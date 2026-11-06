using System;
using System.Diagnostics;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using Unity.Services.CloudCode.Authoring.Editor.Core.Logging;

namespace Unity.Services.CloudCode.Authoring.Editor.Projects
{
    interface IProcessRunner
    {
        Task<ProcessOutput> RunAsync(
            ProcessStartInfo startInfo,
            string stdIn = default,
            CancellationToken cancellationToken = default,
            TimeSpan timeout = default);

        Process RunAsyncFireAndForget(ProcessStartInfo startInfo, Action<string> onStandardError = null);
        bool Start(ProcessStartInfo startInfo);
        void Stop(int processId);
    }

    struct ProcessOutput
    {
        public string StdOut { get; set; }
        public string StdErr { get; set; }
        public int ExitCode { get; set; }
    }

    class ProcessRunner : IProcessRunner
    {
        public async Task<ProcessOutput> RunAsync(
            ProcessStartInfo startInfo,
            string stdIn = default,
            CancellationToken cancellationToken = default,
            TimeSpan timeout = default)
        {
            startInfo.RedirectStandardInput = true;
            startInfo.RedirectStandardOutput = true;
            startInfo.RedirectStandardError = true;

            using var process = new Process();
            var exitTask = WrapProcessInTask(process, cancellationToken);

            process.StartInfo = startInfo;
            process.EnableRaisingEvents = true;
            var stdOut = new StringBuilder();
            process.OutputDataReceived += (sender, args) =>
            {
                stdOut.AppendLine(args.Data);
            };
            var stdErr = new StringBuilder();
            process.ErrorDataReceived += (sender, args) =>
            {
                stdErr.AppendLine(args.Data);
            };

            process.Start();
            process.BeginOutputReadLine();
            process.BeginErrorReadLine();

            if (!string.IsNullOrEmpty(stdIn))
            {
                await process.StandardInput.WriteAsync(stdIn);
                process.StandardInput.Close();
            }
            await HandleExit(process, exitTask, timeout);

            return new ProcessOutput
            {
                ExitCode = process.ExitCode,
                StdOut = stdOut.ToString(),
                StdErr = stdErr.ToString(),
            };
        }

        public Process RunAsyncFireAndForget(ProcessStartInfo startInfo, Action<string> onStandardError = null)
        {
            // stdout is left inherited; stderr is only redirected when a handler is supplied, so a
            // caller can surface early/fatal launch output during startup without keeping a pipe
            // open for the process lifetime.
            if (onStandardError != null)
                startInfo.RedirectStandardError = true;

            var process = new Process();
            process.StartInfo = startInfo;
            process.EnableRaisingEvents = true;

            if (onStandardError != null)
            {
                process.ErrorDataReceived += (sender, args) =>
                {
                    if (!string.IsNullOrEmpty(args.Data))
                        onStandardError(args.Data);
                };
            }

            process.Start();

            if (onStandardError != null)
                process.BeginErrorReadLine();

            return process;
        }

        static async Task HandleExit(
            Process process,
            Task exitTask,
            TimeSpan timeout)
        {
            exitTask.Start();
            var timeoutTask = Task.Delay(timeout == default ? TimeSpan.FromMinutes(5) : timeout);
            var completed = await Task.WhenAny(exitTask, timeoutTask);
            if (completed == timeoutTask)
            {
                process.Kill();
            }
        }

        public bool Start(ProcessStartInfo startInfo)
        {
            using var process = new Process();
            process.StartInfo = startInfo;
            return process.Start();
        }

        static Task WrapProcessInTask(Process process, CancellationToken cancellationToken = default)
        {
            return new Task(process.WaitForExit, cancellationToken);
        }

        public void Stop(int processID)
        {
            try
            {
                using var process = Process.GetProcessById(processID);
                if (process.HasExited)
                    return;

                process.Kill();
            }
            catch (Exception e)
            {
                throw new Exception(e.Message);
            }
        }
    }
}
