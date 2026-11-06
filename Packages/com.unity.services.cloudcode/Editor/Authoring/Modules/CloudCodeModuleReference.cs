using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.IO;
using System.Runtime.CompilerServices;
using Newtonsoft.Json;
using Newtonsoft.Json.Serialization;
using Unity.Services.CloudCode.Authoring.Editor.Core.Model;
using Unity.Services.CloudCode.Editor.Shared.Assets;
using Unity.Services.CloudCode.Editor.Shared.EditorUtils;
using Unity.Services.DeploymentApi.Editor;
using UnityEngine;
using WebSocketSharp;
using SystemPath = System.IO.Path;

namespace Unity.Services.CloudCode.Authoring.Editor.Modules
{
    [HelpURL("https://docs.unity3d.com/Packages/com.unity.services.cloudcode@2.8/manual/Authoring/cloud_code_modules.html"),
     Icon("Packages/com.unity.services.cloudcode/Editor/Authoring/Modules/UI/Assets/CloudCodeAsset.png")]
    class CloudCodeModuleReference : ScriptableObject, ICopyable<CloudCodeModuleReference>, IPath, ISolutionModuleItem
    {
        static readonly JsonSerializerSettings k_JsonSerializerSettings = new JsonSerializerSettings
        {
            Formatting = Formatting.Indented,
            ContractResolver = new CamelCasePropertyNamesContractResolver()
        };

        const string SolutionExtension = ".sln";

        [SerializeField]
        string m_ModulePath;
        string m_Path;
        string m_AssetName;
        float m_Progress;
        string m_Type = "C# Module";
        DeploymentStatus m_Status;
        SerializableObservableCollection<AssetState> m_States;

        string m_ModuleName;
        public string ModuleName
        {
            get => m_ModuleName;
            set => SetField(ref m_ModuleName, value);
        }
        public string Name
        {
            get
            {
                if (m_AssetName.IsNullOrEmpty())
                {
                    return SystemPath.GetFileName(Path);
                }
                return m_AssetName;
            }
            set => SetField(ref m_AssetName, value);
        }

        public string Type
        {
            get => m_Type;
        }

        public string Path
        {
            get => m_Path;
            set
            {
                SetName(value);
                SetField(ref m_Path, value);
            }
        }

        void SetName(string path)
        {
            Name = string.IsNullOrEmpty(path) ? string.Empty : System.IO.Path.GetFileName(path);
        }

        public string SolutionPath => GetSolutionPath();

        public string CcmPath { get; set; }

        public float Progress
        {
            get { return m_Progress; }
            set { SetField(ref m_Progress, value); }
        }

        public List<(DateTime, DeploymentStatus)> StatusLog { get; } = new List<(DateTime, DeploymentStatus)>();

        public DeploymentStatus Status
        {
            get { return m_Status; }
            set { SetField(ref m_Status, value); }
        }

        // TODO: record and surface the last successful deployment for ccmr (see CloudCodeModule).
        public LastSuccessfulDeploymentInfo LastSuccessfulDeployment { get; set; }

        public ObservableCollection<AssetState> States => m_States;

        public string ModulePath
        {
            get => m_ModulePath;
            set => SetValidPath(value);
        }

        string GetSolutionPath()
        {
            var ccmrDir = System.IO.Path.GetDirectoryName(System.IO.Path.GetFullPath(m_Path));
            var targetPath = System.IO.Path.Combine(ccmrDir, ModulePath);
            return System.IO.Path.GetFullPath(targetPath);
        }

        void SetValidPath(string newModulePath)
        {
            var finalPath = newModulePath;
            if (!System.IO.Path.GetExtension(finalPath).Equals(SolutionExtension))
            {
                finalPath =
                    System.IO.Path.Combine(
                        newModulePath , System.IO.Path.GetFileNameWithoutExtension(Name) + SolutionExtension);
            }
            SetField(ref m_ModulePath, finalPath);
        }

        public CloudCodeModuleReference()
        {
            Progress = 0;
            Status = DeploymentStatus.Empty;
            m_States = new SerializableObservableCollection<AssetState>();
        }

        public string ToJson()
        {
            return JsonConvert.SerializeObject(
                new
                {
                    ModulePath
                },
                k_JsonSerializerSettings);
        }

        public bool FromJson(string json)
        {
            try
            {
                JsonConvert.PopulateObject(json, this, k_JsonSerializerSettings);
                return true;
            }
            catch (JsonException e)
            {
                Debug.LogError($"Failed to parse Cloud Code Module Reference: {e.Message}");
                return false;
            }
        }

        public bool SaveChanges()
        {
            try
            {
                var json = ToJson();
                File.WriteAllText(this.Path, json);
                return true;
            }
            catch (Exception e)
            {
                Debug.LogError($"Failed to save Cloud Code Module Reference: {e.Message}");
                return false;
            }
        }

        public void CopyTo(CloudCodeModuleReference value)
        {
            value.ModulePath = ModulePath;
        }

        protected bool SetField<T>(ref T field, T value, [CallerMemberName] string propertyName = null)
        {
            if (EqualityComparer<T>.Default.Equals(field, value))
                return false;
            field = value;
            OnPropertyChanged(propertyName);
            return true;
        }

        protected virtual void OnPropertyChanged(string propertyName = null)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }

        public event PropertyChangedEventHandler PropertyChanged;

        #region Serialization Wrappers

        // Required as ObservableCollection fails Unity serialization of its items across Domain Reloads
        [Serializable]
        class SerializableObservableCollection<T> : ObservableCollection<T>, ISerializationCallbackReceiver
        {
            [SerializeField]
            List<T> m_PersistedList;

            internal SerializableObservableCollection()
            {
                m_PersistedList = new List<T>();
            }

            public void OnBeforeSerialize()
            {
                m_PersistedList.Clear();
                m_PersistedList.AddRange(Items);
            }

            public void OnAfterDeserialize()
            {
                Items.Clear();
                foreach (var state in m_PersistedList)
                {
                    Items.Add(state);
                }
            }
        }

        #endregion
    }
}
