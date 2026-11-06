using System;
using Unity.Services.CloudCode.Authoring.Editor.Core.Model;
using Unity.Services.CloudCode.Authoring.Editor.Modules;
using Unity.Services.DeploymentApi.Editor;

namespace Unity.Services.CloudCode.Authoring.Editor.Deployment.Modules
{
    class Module : Script
    {
        readonly IModuleItem m_Parent;

        public Module(string path, IModuleItem parent) : base(path)
        {
            m_Parent = parent;
        }

        public override float Progress
        {
            get => base.Progress;
            set
            {
                base.Progress = value;
                if (value <= 0f)
                {
                    m_Parent.Progress = 0f;
                    return;
                }
                m_Parent.Progress = (float)Math.Round(66.6f + value / 3f, 0, MidpointRounding.AwayFromZero);
            }
        }

        public override DeploymentStatus Status
        {
            get => base.Status;
            set
            {
                base.Status = value;
                m_Parent.UpdateLogStatus(value);
            }
        }
    }
}
