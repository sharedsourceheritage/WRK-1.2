using System;
using System.IO;
using System.Runtime.InteropServices;
using Microsoft.VisualStudio.Shell.Interop;
using Microsoft.VisualStudio.Shell;
using Microsoft.VisualStudio.Package;
using Microsoft.Win32;
using EnvDTE;
using IOleServiceProvider = Microsoft.VisualStudio.OLE.Interop.IServiceProvider;

namespace Microsoft.VisualStudio.VSIP.Samples.Project
{
    [DefaultRegistryRoot("Software\\Microsoft\\VisualStudio\\8.0")]
    [ProvideProjectFactory(typeof(MyProjectFactory), "MyProject", "#201", "myproj", "myproj", "..\\..\\Templates\\Projects")]
    [RegisterProjectItem(typeof(MyProjectFactory), "My Items", "..\\..\\Templates\\ProjectItems", 500)]
    [ProvideObject(typeof(GeneralPropertyPage))]
    [Guid("e815d8ad-49bf-427d-99c8-009db3e56ab9")]
    public class MyPackage : Microsoft.VisualStudio.Shell.Package
    {
        protected override void Initialize()
        {
            base.Initialize();
            this.RegisterProjectFactory(new MyProjectFactory(this));
        }
    }

    [GuidAttribute("952a0f31-c8d1-4365-9936-107f60fa614d")]
    public class MyProjectFactory : Microsoft.VisualStudio.Package.ProjectFactory
    {
        public MyProjectFactory(MyPackage package) : base()
        {
            this.SetPackage(package);
        }

        protected override Microsoft.VisualStudio.Package.Project CreateProject()
        {
            MyProject project = new MyProject(this.package as MyPackage);
            project.SetSite((IOleServiceProvider)((IServiceProvider)this.package).GetService(typeof(IOleServiceProvider)));
            return project;
        }
    }

    [Guid("919fc76c-2c18-4df3-818a-e2a4da45d915")]
    public class MyProject : Microsoft.VisualStudio.Package.Project
    {
        private MyPackage package;

        public MyProject(MyPackage pkg)
        {
            this.package = pkg;
        }
        public override Guid GetProjectGuid()
        {
            return typeof(MyProjectFactory).GUID;
        }
        public override string GetProjectType()
        {
            return "MyProject";
        }

        /// <summary>
        /// Overriding to provide project general property page
        /// </summary>
        /// <returns></returns>
        public override Guid[] GetPropertyPageGuids()
        {
            Guid[] result = new Guid[1];
            result[0] = typeof(GeneralPropertyPage).GUID;
            return result;
        }

        /// <summary>
        /// Overriding, but current implementation does nothing
        /// To provide configuration specific page project property page, this should return an array bigger then 0
        /// (you can make it do the same as GetPropertyPageGuids() to see its impact)
        /// </summary>
        /// <param name="config"></param>
        /// <returns></returns>
        public override Guid[] GetConfigPropertyPageGuids(string config)
        {
            Guid[] result = new Guid[0];
            return result;
        }

        /// <summary>
        /// Overriding to provide customization of files on add files.
        /// This will replace tokens in the file with actual value (namespace, class name,...)
        /// </summary>
        /// <param name="source">Full path to template file</param>
        /// <param name="target">Full path to destination file</param>
        public override void AddFileFromTemplate(string source, string target)
        {
			if (!System.IO.File.Exists(source))
				throw new FileNotFoundException(String.Format("Template file not found: {0}", source));

			TokenProcessor tokenReplacer = new TokenProcessor();
            tokenReplacer.TheDTE = (DTE)((IServiceProvider)this.package).GetService(typeof(_DTE));

            string className = Path.GetFileNameWithoutExtension(target);
            string namespce = this.GetProjectProperty("RootNamespace");
            if (namespce == null || namespce.Length == 0)
                namespce = className;
            tokenReplacer.AddReplace("%className%", className, TokenReplaceType.ReplaceString);
            tokenReplacer.AddReplace("%namespace%", namespce, TokenReplaceType.ReplaceString);
			try
			{
				tokenReplacer.UntokenMiscFile(source, target);
			}
			catch (Exception e)
			{
				throw new FileLoadException("Failed to add template file to project", target, e);
			}
		}

    }
}