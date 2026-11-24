/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// DynamicExtender.cs : Implementation of a dynamically registered extender

using System;
using System.Diagnostics;
using System.Reflection;
using System.Runtime.InteropServices;

namespace Microsoft.VisualStudio.VSIP.Samples.AutoExtender
{    
    public class DynamicExtenderProvider : Object, EnvDTE.IExtenderProvider
    {
        private static string dynamicExtenderName = "CSharpProjectBrowseObjectExtender";

        public DynamicExtenderProvider()
        {
            string methodName = 
                MethodBase.GetCurrentMethod().DeclaringType.FullName + "::" + 
                MethodBase.GetCurrentMethod().Name ;
            Trace.WriteLine("Entering " + methodName);
            Trace.WriteLine("Leaving " + methodName);
        }

        public static string DynamicExtenderName
        {
            get { return dynamicExtenderName; }
        }

        //////////////////////////////////////////////////////////////////
        // IExtenderProvider Implementation
        #region IExtenderProvider Members

        public bool CanExtend(string ExtenderCATID, 
                              string ExtenderName,
                              object ExtendeeObject)
        {
            string methodName = 
                MethodBase.GetCurrentMethod().DeclaringType.FullName + "::" + 
                MethodBase.GetCurrentMethod().Name ;
            Trace.Write("Entering " + methodName);
            Trace.Write(" ExtenderCATID " + ExtenderCATID);
            Trace.WriteLine(" ExtenderName " + ExtenderName);
            bool IfCanExtend = false;

            // check if provider can create extender for the given
            // ExtenderCATID, ExtenderName, and Extendee instance
            System.ComponentModel.PropertyDescriptor extendeeCATIDProp = 
                System.ComponentModel.TypeDescriptor.GetProperties(ExtendeeObject)["ExtenderCATID"];
            if (true == ExtenderName.Equals(DynamicExtenderProvider.DynamicExtenderName)
                && true == ExtenderCATID.ToUpper().Equals(VSLangProj.PrjBrowseObjectCATID.prjCATIDCSharpProjectBrowseObject.ToUpper())
                && null != extendeeCATIDProp
                && true == extendeeCATIDProp.GetValue(ExtendeeObject).ToString().ToUpper().Equals(VSLangProj.PrjBrowseObjectCATID.prjCATIDCSharpProjectBrowseObject.ToUpper())) 
            {
                IfCanExtend = true;
            }
            else
            {
                IfCanExtend = false;
            }

            Trace.WriteLine("Leaving " + methodName + " " + IfCanExtend);
            return IfCanExtend;
        }

        public object GetExtender(string ExtenderCATID,
                                  string ExtenderName, 
                                  object ExtendeeObject,
                                  EnvDTE.IExtenderSite ExtenderSite,
                                  int Cookie)
        {
            string methodName = 
                MethodBase.GetCurrentMethod().DeclaringType.FullName + "::" + 
                MethodBase.GetCurrentMethod().Name ;
            Trace.WriteLine("Entering " + methodName);
            DynamicExtender dynamicExtender = null;

            if (true == CanExtend(ExtenderCATID, ExtenderName, ExtendeeObject))
            {
                EnvDTE.DTE dte = (EnvDTE.DTE) ExtenderSite.GetObject("");
                if (null == dte)
                {
                    throw new NullReferenceException("GetObject failed");
                }

                // find project object for the given project browse object
                EnvDTE.Project csharpProj = null;
                System.ComponentModel.PropertyDescriptor browseObjFileNameProp =
                    System.ComponentModel.TypeDescriptor.GetProperties(ExtendeeObject)["FileName"];
                if (null == browseObjFileNameProp)
                {
                    throw new NullReferenceException("GetProperties failed");
                }
                String strProjFileName = browseObjFileNameProp.GetValue(ExtendeeObject) as String;
                if (null == strProjFileName)
                {
                    throw new NullReferenceException("System.ComponentModel.PropertyDescriptor.GetValue failed");
                }
                foreach(EnvDTE.Project prj in dte.Solution.Projects)
                {
                    if (true == prj.FileName.ToUpper().EndsWith(strProjFileName.ToUpper()))
                    {
                        csharpProj = prj;
                        break;
                    }
                }
                if (null == csharpProj)
                {
                    throw new NullReferenceException();
                }

                // create extender
                dynamicExtender = new DynamicExtender(); 
                dynamicExtender.Init(csharpProj, Cookie, ExtenderSite);
            }

            Trace.WriteLine("Leaving " + methodName);
            return dynamicExtender;
        }

        #endregion
    }

    [InterfaceType(ComInterfaceType.InterfaceIsDual)]
    public interface IDynamicExtender
    {    
        System.DateTime ProjectCreated
        {
            get;
        }
        string ProjectDescription
        {
            get;
            set;
        }
    }

    [ClassInterface(ClassInterfaceType.None)]
    public class DynamicExtender : IDynamicExtender
    {
        // names to be used when store property values in EnvDTE.Project.Global
        const string prjDescPropName = "ProjDescription";

        //////////////////////////////////////////////////////////////////
        // DynamicExtender Fields
        // extension manager site
        private EnvDTE.IExtenderSite extenderSite; 
        // cookie that identify this extender at extension manager site
        private int siteCookie; 
        // csharp project object. use it for two purposes
        // 1. get project file name in order to get file creation time 
        //    for ProjectCreated property
        // 2. use EnvDTE.Project.Global to persist extender property values
        private EnvDTE.Project csharpProject; 

        public DynamicExtender()
        {
            string methodName = 
                MethodBase.GetCurrentMethod().DeclaringType.FullName + "::" + 
                MethodBase.GetCurrentMethod().Name ;
            Trace.WriteLine("Entering " + methodName);
            extenderSite = null;
            siteCookie = 0;
            csharpProject = null;
            Trace.WriteLine("Leaving " + methodName);
        }

        public void Init(EnvDTE.Project CSharpProject, int ExtenderCookie,
            EnvDTE.IExtenderSite ExtenderSite)
        {
            string methodName = 
                MethodBase.GetCurrentMethod().DeclaringType.FullName + "::" + 
                MethodBase.GetCurrentMethod().Name ;
            Trace.WriteLine("Entering " + methodName + 
                String.Format(" cookie 0x{0:X}", ExtenderCookie));
            extenderSite = ExtenderSite;
            siteCookie = ExtenderCookie;
            csharpProject = CSharpProject;
            Trace.WriteLine("Leaving " + methodName);
        }

        ~DynamicExtender()
        {
            string methodName = 
                MethodBase.GetCurrentMethod().DeclaringType.FullName + "::" + 
                MethodBase.GetCurrentMethod().Name ;
            Trace.WriteLine("Entering " + methodName);
            // Wrap this call in a try-catch to avoid any failure code the
            // Site may return. For instance, since this object is GC'ed,
            // the Site may have already let go of its Cookie.
            try
            {
                if (null != extenderSite && 0 != siteCookie) 
                {
                    extenderSite.NotifyDelete(siteCookie);
                    Trace.WriteLine(String.Format("Extender cookie deleted 0x{0:X}", siteCookie));
                }
            }
            catch 
            {
            }
            Trace.WriteLine("Leaving " + methodName);
        }

        /////////////////////////////////////////////////////////////////////////////
        // IDynamicExtender Implementation
        #region IDynamicExtender Members

        public System.DateTime ProjectCreated
        {
            get
            {
                return System.IO.File.GetCreationTime(csharpProject.FileName);
            }
        }

        public String ProjectDescription
        {
            get
            {
                EnvDTE.Globals projGlobals = csharpProject.Globals;
                if (false == projGlobals.get_VariableExists(prjDescPropName))
                {
                    projGlobals[prjDescPropName] = string.Empty;
                    projGlobals.set_VariablePersists(prjDescPropName, true);
                }
                return projGlobals[prjDescPropName].ToString();
            }
            set
            {
                EnvDTE.Globals projGlobals = csharpProject.Globals;
                projGlobals[prjDescPropName] = value;
                projGlobals.set_VariablePersists(prjDescPropName, true);
            }
        }

        #endregion
    }
}
