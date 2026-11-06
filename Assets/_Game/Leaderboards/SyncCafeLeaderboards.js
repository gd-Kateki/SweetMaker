// Publish this script in both development and production before enabling the write policy.
const { DataApi } = require("@unity-services/cloud-save-1.0");
const { LeaderboardsApi } = require("@unity-services/leaderboards-2.0");

module.exports = async ({ params, context }) => {
  if (!context.playerId || !context.serviceToken) throw Error("PLAYER_AUTHENTICATION_REQUIRED");
  const mode = { development: "DEVELOPMENT-ISOLATED", production: "RELEASE" }[context.environmentName];
  if (!mode) throw Error("UNSUPPORTED_ENVIRONMENT");
  if (!/^[A-Za-z0-9+/]{43}=$/.test(params.checksum || "")) throw Error("INVALID_CHECKSUM");
  const key = "dmc_backup_v1_" + mode;
  const saves = new DataApi({ accessToken: context.serviceToken });
  const response = await saves.getItems(context.projectId, context.playerId, [key]);
  const item = response.data.results.find(value => value.key === key);
  if (!item || typeof item.value !== "string" || item.value.length > 500000)
    throw Error("CLOUD_BACKUP_REQUIRED");
  const backup = JSON.parse(item.value);
  if (backup.version !== 1 || backup.playerId !== context.playerId || backup.environment !== mode)
    throw Error("BACKUP_OWNER_MISMATCH");
  if (backup.checksum !== params.checksum) throw Error("BACKUP_CHANGED_RETRY");
  if (typeof backup.cafeName !== "string" || !backup.cafeName.trim() ||
      backup.cafeName !== backup.cafeName.trim() || backup.cafeName.length > 20 ||
      /[\u0000-\u001f\u007f]/.test(backup.cafeName)) throw Error("INVALID_CAFE_NAME");
  if (!Number.isInteger(backup.tutorialStage) || backup.tutorialStage < 0 || backup.tutorialStage > 4 ||
      typeof backup.saveJson !== "string" || backup.saveJson.length > 350000)
    throw Error("INVALID_BACKUP");

  // JsonUtility writes Int64 totals as integer tokens. Quote those tokens before
  // parsing so JavaScript doesn't round them before storing display metadata.
  const save = JSON.parse(backup.saveJson.replace(
    /(?<!\\)("(?:totalMoneyEarned|totalOrdersCompleted)"\s*:\s*)(-?\d+)(?=\s*[,}])/g, '$1"$2"'));
  if (!save || save.saveVersion !== 2 || !save.economy || !Number.isInteger(save.completedRebirthCount) ||
      save.completedRebirthCount < 0 || save.completedRebirthCount > 2147483647)
    throw Error("INVALID_PROGRESS");
  const normalizeTotal = raw => {
    if (typeof raw !== "string" || !/^(0|[1-9]\d{0,18})$/.test(raw) ||
        (raw.length === 19 && raw > "9223372036854775807")) throw Error("INVALID_TOTAL");
    return raw;
  };
  const money = normalizeTotal(save.economy.totalMoneyEarned);
  const orders = normalizeTotal(save.economy.totalOrdersCompleted);
  const leaderboards = new LeaderboardsApi({ accessToken: context.serviceToken });
  const publish = (id, total) => leaderboards.addLeaderboardPlayerScore(
    context.projectId, id, context.playerId, {
      score: Number(total),
      metadata: { cafeName: backup.cafeName, rebirth: save.completedRebirthCount, total }
    });
  // Latest Score makes a retry safe if the first category succeeded and the second failed.
  await publish("total_money_earned", money);
  await publish("total_orders_completed", orders);
  return { uploaded: true, checksum: backup.checksum };
};

module.exports.params = { checksum: { type: "String", required: true } };
