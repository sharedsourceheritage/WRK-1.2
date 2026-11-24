using System;
using Microsoft.VisualStudio.Shell.Interop;
using Microsoft.VisualStudio.Shell;
using Microsoft.VisualStudio.Package;
using System.Runtime.InteropServices;
using System.ComponentModel;
using System.Diagnostics;
using System.IO;

namespace Microsoft.VisualStudio.VSIP.Samples.Project
{
    [AttributeUsage(AttributeTargets.Class | AttributeTargets.Property | AttributeTargets.Field, Inherited = false, AllowMultiple = false)]
    internal sealed class LocDisplayNameAttribute : DisplayNameAttribute
    {
        private string name;

        public LocDisplayNameAttribute(string name)
        {
            this.name = name;
        }

        public override string DisplayName
        {
            get
            {
                string result = SR.GetString(this.name);

                if (result == null)
                {
                    Debug.Assert(false, "String resource '" + this.name + "' is missing");
                    result = this.name;
                }

                return result;
            }
        }
    }

    /// <include file='doc\PropertyPages.uex' path='docs/doc[@for="GeneralPropertyPage"]/*' />
    [ComVisible(true), Guid("3c693da2-5bca-49b3-bd95-ffe0a39dd723")]
    public class GeneralPropertyPage : SettingsPage
    {
        private string assemblyName;
        private OutputType outputType;
        private string defaultNamespace;
        private string startupObject;
        private string applicationIcon;
        private PlatformType targetPlatform = PlatformType.v2;
        private string targetPlatformLocation;

        /// <include file='doc\PropertyPages.uex' path='docs/doc[@for="GeneralPropertyPage.GeneralPropertyPage"]/*' />
        public GeneralPropertyPage()
        {
            this.strName = SR.GetString(SR.GeneralCaption);
        }

        /// <include file='doc\PropertyPages.uex' path='docs/doc[@for="GeneralPropertyPage.GetClassName"]/*' />
        public override string GetClassName()
        {
            return this.GetType().FullName;
        }

        /// <include file='doc\PropertyPages.uex' path='docs/doc[@for="GeneralPropertyPage.BindProperties"]/*' />
        public override void BindProperties()
        {
            if (this.ProjectMgr == null)
            {
                Debug.Assert(false);
                return;
            }

            this.assemblyName = this.ProjectMgr.GetProjectProperty("AssemblyName", true);

            string outputType = this.ProjectMgr.GetProjectProperty("OutputType", false);

            if (outputType != null && outputType.Length > 0)
                try { this.outputType = (OutputType)Enum.Parse(typeof(OutputType), outputType); } catch { } //Should only fail if project file is corrupt

            this.defaultNamespace = this.ProjectMgr.GetProjectProperty("RootNamespace", false);
            this.startupObject = this.ProjectMgr.GetProjectProperty("StartupObject", false);
            this.applicationIcon = this.ProjectMgr.GetProjectProperty("ApplicationIcon", false);

            string targetPlatform = this.ProjectMgr.GetProjectProperty("TargetPlatform", false);

            if (targetPlatform != null && targetPlatform.Length > 0)
                try { this.targetPlatform = (PlatformType)Enum.Parse(typeof(PlatformType), targetPlatform); } catch { }

            this.targetPlatformLocation = this.ProjectMgr.GetProjectProperty("TargetPlatformLocation", false);
        }

        /// <include file='doc\PropertyPages.uex' path='docs/doc[@for="GeneralPropertyPage.ApplyChanges"]/*' />
        public override void ApplyChanges()
        {
            if (this.ProjectMgr == null)
            {
                Debug.Assert(false);
                return;
            }

            this.ProjectMgr.SetProjectProperty("AssemblyName", this.assemblyName);
            this.ProjectMgr.SetProjectProperty("OutputType", this.outputType.ToString());
            this.ProjectMgr.SetProjectProperty("RootNamespace", this.defaultNamespace);
            this.ProjectMgr.SetProjectProperty("StartupObject", this.startupObject);
            this.ProjectMgr.SetProjectProperty("ApplicationIcon", this.applicationIcon);
            this.ProjectMgr.SetProjectProperty("TargetPlatform", this.targetPlatform.ToString());
            this.ProjectMgr.SetProjectProperty("TargetPlatformLocation", this.targetPlatformLocation);
            this.IsDirty = false;
        }

        /// <include file='doc\PropertyPages.uex' path='docs/doc[@for="GeneralPropertyPage.AssemblyName"]/*' />
        [SRCategoryAttribute(SR.Application)]
        [LocDisplayName(SR.AssemblyName)]
        [SRDescriptionAttribute(SR.AssemblyNameDescription)]
        public string AssemblyName
        {
            get { return this.assemblyName; }
            set { this.assemblyName = value; this.IsDirty = true; }
        }

        /// <include file='doc\PropertyPages.uex' path='docs/doc[@for="GeneralPropertyPage.OutputType"]/*' />
        [SRCategoryAttribute(SR.Application)]
        [LocDisplayName(SR.OutputType)]
        [SRDescriptionAttribute(SR.OutputTypeDescription)]
        public OutputType OutputType
        {
            get { return this.outputType; }
            set { this.outputType = value; this.IsDirty = true; }
        }

        /// <include file='doc\PropertyPages.uex' path='docs/doc[@for="GeneralPropertyPage.DefaultNamespace"]/*' />
        [SRCategoryAttribute(SR.Application)]
        [LocDisplayName(SR.DefaultNamespace)]
        [SRDescriptionAttribute(SR.DefaultNamespaceDescription)]
        public string DefaultNamespace
        {
            get { return this.defaultNamespace; }
            set { this.defaultNamespace = value; this.IsDirty = true; }
        }

        /// <include file='doc\PropertyPages.uex' path='docs/doc[@for="GeneralPropertyPage.StartupObject"]/*' />
        [SRCategoryAttribute(SR.Application)]
        [LocDisplayName(SR.StartupObject)]
        [SRDescriptionAttribute(SR.StartupObjectDescription)]
        public string StartupObject
        {
            get { return this.startupObject; }
            set { this.startupObject = value; this.IsDirty = true; }
        }

        /// <include file='doc\PropertyPages.uex' path='docs/doc[@for="GeneralPropertyPage.ApplicationIcon"]/*' />
        [SRCategoryAttribute(SR.Application)]
        [LocDisplayName(SR.ApplicationIcon)]
        [SRDescriptionAttribute(SR.ApplicationIconDescription)]
        public string ApplicationIcon
        {
            get { return this.applicationIcon; }
            set { this.applicationIcon = value; this.IsDirty = true; }
        }

        /// <include file='doc\PropertyPages.uex' path='docs/doc[@for="GeneralPropertyPage.ProjectFile"]/*' />
        [SRCategoryAttribute(SR.Project)]
        [LocDisplayName(SR.ProjectFile)]
        [SRDescriptionAttribute(SR.ProjectFileDescription)]
        public string ProjectFile
        {
            get { return Path.GetFileName(this.ProjectMgr.ProjectFile); }
        }

        /// <include file='doc\PropertyPages.uex' path='docs/doc[@for="GeneralPropertyPage.ProjectFolder"]/*' />
        [SRCategoryAttribute(SR.Project)]
        [LocDisplayName(SR.ProjectFolder)]
        [SRDescriptionAttribute(SR.ProjectFolderDescription)]
        public string ProjectFolder
        {
            get { return Path.GetDirectoryName(this.ProjectMgr.ProjectFolder); }
        }

        /// <include file='doc\PropertyPages.uex' path='docs/doc[@for="GeneralPropertyPage.OutputFile"]/*' />
        [SRCategoryAttribute(SR.Project)]
        [LocDisplayName(SR.OutputFile)]
        [SRDescriptionAttribute(SR.OutputFileDescription)]
        public string OutputFile
        {
            get
            {
                switch (this.outputType)
                {
                    case OutputType.Exe: return this.assemblyName + ".exe";

                    default: return this.assemblyName + ".dll";
                }
            }
        }

        /// <include file='doc\PropertyPages.uex' path='docs/doc[@for="GeneralPropertyPage.TargetPlatform"]/*' />
        [SRCategoryAttribute(SR.Project)]
        [LocDisplayName(SR.TargetPlatform)]
        [SRDescriptionAttribute(SR.TargetPlatformDescription)]
        public PlatformType TargetPlatform
        {
            get { return this.targetPlatform; }
            set { this.targetPlatform = value; IsDirty = true; }
        }

        /// <include file='doc\PropertyPages.uex' path='docs/doc[@for="GeneralPropertyPage.TargetPlatformLocation"]/*' />
        [SRCategoryAttribute(SR.Project)]
        [LocDisplayName(SR.TargetPlatformLocation)]
        [SRDescriptionAttribute(SR.TargetPlatformLocationDescription)]
        public string TargetPlatformLocation
        {
            get { return this.targetPlatformLocation; }
            set { this.targetPlatformLocation = value; IsDirty = true; }
        }
    }
}
