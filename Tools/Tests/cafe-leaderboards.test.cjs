const test = require('node:test');
const assert = require('node:assert/strict');
const fs = require('node:fs');
const path = require('node:path');
const vm = require('node:vm');
const source = fs.readFileSync(path.resolve(__dirname, '../../Assets/_Game/Leaderboards/SyncCafeLeaderboards.js'), 'utf8');
const checksum = Buffer.alloc(32).toString('base64');

function fixture(environmentName = 'production') {
  const writes = [], reads = [];
  const state = {
    failOrders: false,
    backup: { version: 1, playerId: 'player-a', environment: environmentName === 'production' ? 'RELEASE' : 'DEVELOPMENT-ISOLATED',
      cafeName: 'Café Crème', tutorialStage: 4, checksum,
      saveJson: '{"saveVersion":2,"completedRebirthCount":7,"economy":{"totalMoneyEarned":22345678901234567,"totalOrdersCompleted":42}}' }
  };
  class DataApi {
    constructor(options) { assert.equal(options.accessToken, 'service-token'); }
    async getItems(project, player, keys) {
      reads.push({ project, player, keys });
      return { data: { results: state.backup ? [{ key: keys[0], value: JSON.stringify(state.backup) }] : [] } };
    }
  }
  class LeaderboardsApi {
    constructor(options) { assert.equal(options.accessToken, 'service-token'); }
    async addLeaderboardPlayerScore(project, board, player, value) {
      if (state.failOrders && board === 'total_orders_completed') throw Error('Temporary outage');
      writes.push({ project, board, player, ...value });
    }
  }
  const scope = { module: { exports: {} }, require: id => {
    if (id === '@unity-services/cloud-save-1.0') return { DataApi };
    if (id === '@unity-services/leaderboards-2.0') return { LeaderboardsApi };
    throw Error('Unexpected SDK ' + id);
  } };
  vm.runInNewContext(source, scope);
  const context = { projectId: 'project', playerId: 'player-a', serviceToken: 'service-token', environmentName };
  const run = (params = { checksum }) => scope.module.exports({ params, context });
  return { run, context, state, writes, reads };
}

for (const environment of ['production', 'development']) {
  test('publishes saved totals and metadata in ' + environment, async () => {
    const f = fixture(environment);
    const result = await f.run({ checksum, score: 999999, playerId: 'victim', cafeName: 'Forged', rebirth: 999 });
    assert.equal(result.uploaded, true);
    assert.equal(f.reads[0].player, 'player-a');
    assert.equal(f.reads[0].keys[0], 'dmc_backup_v1_' + f.state.backup.environment);
    assert.equal(f.writes.length, 2);
    assert.equal(f.writes[0].metadata.total, '22345678901234567');
    assert.equal(f.writes[0].metadata.cafeName, 'Café Crème');
    assert.equal(f.writes[0].metadata.rebirth, 7);
    assert.equal(f.writes[0].player, 'player-a');
    assert.equal(f.writes[1].score, 42);
  });
}

for (const [name, change, expected] of [
  ['missing identity', f => f.context.playerId = null, /AUTHENTICATION/],
  ['missing service token', f => f.context.serviceToken = null, /AUTHENTICATION/],
  ['unknown environment', f => f.context.environmentName = 'test', /ENVIRONMENT/],
  ['missing backup', f => f.state.backup = null, /BACKUP_REQUIRED/],
  ['different owner', f => f.state.backup.playerId = 'victim', /OWNER_MISMATCH/],
  ['different environment', f => f.state.backup.environment = 'DEVELOPMENT-ISOLATED', /OWNER_MISMATCH/],
  ['stale backup', f => f.state.backup.checksum = 'changed', /BACKUP_CHANGED/],
  ['control characters in name', f => f.state.backup.cafeName = 'Cafe\nForged', /CAFE_NAME/],
  ['oversized name', f => f.state.backup.cafeName = 'x'.repeat(21), /CAFE_NAME/],
  ['negative total', f => f.state.backup.saveJson = f.state.backup.saveJson.replace(':42', ':-42'), /INVALID_TOTAL/],
  ['overflow total', f => f.state.backup.saveJson = f.state.backup.saveJson.replace(':42', ':9223372036854775808'), /INVALID_TOTAL/],
  ['unsupported save schema', f => f.state.backup.saveJson = f.state.backup.saveJson.replace('"saveVersion":2', '"saveVersion":3'), /INVALID_PROGRESS/]
]) {
  test('rejects ' + name + ' before leaderboard writes', async () => {
    const f = fixture(); change(f);
    await assert.rejects(f.run(), expected);
    assert.equal(f.writes.length, 0);
  });
}

test('invalid checksum does not read player data', async () => {
  const f = fixture();
  await assert.rejects(f.run({ checksum: 'bad' }), /INVALID_CHECKSUM/);
  assert.equal(f.reads.length, 0);
});

test('partial failure can retry absolute totals without double counting', async () => {
  const f = fixture(); f.state.failOrders = true;
  await assert.rejects(f.run(), /outage/);
  f.state.failOrders = false;
  await f.run();
  assert.equal(f.writes.length, 3);
  assert.equal(f.writes[0].score, f.writes[1].score);
  assert.equal(f.writes[2].score, 42);
});
