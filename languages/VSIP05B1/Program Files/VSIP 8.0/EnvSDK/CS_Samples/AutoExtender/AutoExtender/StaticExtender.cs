/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// StaticExtender.cs : Implementation of a statically registered extender
#define TRACE

using System;
using System.Diagnostics;
using System.Reflection;
using System.Runtime.InteropServices;

namespace Microsoft.VisualStudio.VSIP.Samples.AutoExtender
{    
    [Guid("7C7E655A-0FBD-43c8-BC2E-C83BB68BFFA2")]
    public class StaticExtenderProvider : Object, EnvDTE.IExtenderProvider
    {
        private static string staticExtenderName = 
            "StaticSolutionBrowserObjExtender";

        public StaticExtenderProvider()
        {
            string methodName = 
                MethodBase.GetCurrentMethod().DeclaringType.FullName + "::" + 
                MethodBase.GetCurrentMethod().Name ;
            Trace.WriteLine("Entering " + methodName);
            Trace.WriteLine("Leaving " + methodName);
        }

        public static string StaticExtenderName
        {
            get { return staticExtenderName; }
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
            bool IfCanExtend = false;
            Trace.WriteLine("Entering " + methodName);
            Trace.WriteLine("ExtenderCATID " + ExtenderCATID);
            Trace.WriteLine("ExtenderName " + ExtenderName);

            // check if provider can create extender for the given
            // ExtenderCATID, ExtenderName, and Extendee instance
            System.ComponentModel.PropertyDescriptor extendeeCATIDProp = 
                System.ComponentModel.TypeDescriptor.GetProperties(ExtendeeObject)["ExtenderCATID"];
            if (true == ExtenderName.Equals(StaticExtenderProvider.StaticExtenderName)
                && true == ExtenderCATID.ToUpper().Equals(EnvDTE.Constants.vsCATIDSolutionBrowseObject.ToUpper())
                && null != extendeeCATIDProp
                && true == extendeeCATIDProp.GetValue(ExtendeeObject).ToString().ToUpper().Equals(EnvDTE.Constants.vsCATIDSolutionBrowseObject.ToUpper())
                ) 
            {
                //ExtendeeObject is EnvDTE.Solution)
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
            StaticExtender staticExtender = null;

            if (true == CanExtend(ExtenderCATID, ExtenderName, ExtendeeObject))
            {
                EnvDTE.Solution solution = ((EnvDTE.DTE) ExtenderSite.GetObject("")).Solution;
                if (null == solution)
                {
                    throw new NullReferenceException("((EnvDTE.DTE) " + "ExtenderSite.GetObject(\"\")).Solution failed");
                }

                staticExtender = new StaticExtender();
                staticExtender.Init(solution, Cookie, ExtenderSite);
            }
            Trace.WriteLine("Leaving " + methodName);
            return staticExtender;
        }

        #endregion
    }

    [InterfaceType(ComInterfaceType.InterfaceIsDual)]
    public interface IStaticExtender
    {    
        string SolutionDescription
        {
            get;
            set;
        }
    }

    [ClassInterface(ClassInterfaceType.None)]
    public class StaticExtender
        :
        IStaticExtender, 
        EnvDTE.IFilterProperties
    {
        const string slnDescPropName = "SolutionDescription";
        //////////////////////////////////////////////////////////////////
        // StaticExtender Fields
        private int siteCookie; 
        private EnvDTE.IExtenderSite extenderSite; 
        private EnvDTE.Solution solution; 

        public StaticExtender()
        {
            string methodName = 
                MethodBase.GetCurrentMethod().DeclaringType.FullName + "::" + 
                MethodBase.GetCurrentMethod().Name ;
            Trace.WriteLine("Entering " + methodName);
            Trace.WriteLine("Leaving " + methodName);
        }

        public void Init(EnvDTE.Solution DTESolution, 
                         int ExtenderCookie,
                         EnvDTE.IExtenderSite ExtenderSite)
        {
            string methodName = 
                MethodBase.GetCurrentMethod().DeclaringType.FullName + "::" + 
                MethodBase.GetCurrentMethod().Name ;
            Trace.WriteLine("Entering " + methodName);
            extenderSite = ExtenderSite;
            siteCookie = ExtenderCookie;
            solution = DTESolution;
            Trace.WriteLine("Leaving " + methodName);
        }

        ~StaticExtender()
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
                if (extenderSite != null)
                {
                    extenderSite.NotifyDelete(siteCookie);
                    Trace.WriteLine("Cookie deleted from site " +
                        String.Format("0x{0:X}", siteCookie) );
                }
            }
            catch 
            {
            }
            Trace.WriteLine("Leaving " + methodName);
        }

        /////////////////////////////////////////////////////////////////////////////
        // IStaticExtender Implementation
        #region IStaticExtender Members

        public string SolutionDescription
        {
            get
            {
                EnvDTE.Globals solutionGlobals = solution.Globals;
                if (!solutionGlobals.get_VariableExists(slnDescPropName))
                {
                    solutionGlobals[slnDescPropName] = string.Empty;
                    solutionGlobals.set_VariablePersists(slnDescPropName, true);
                }
                return solutionGlobals[slnDescPropName].ToString();
            }
            set
            {
                EnvDTE.Globals solutionGlobals = solution.Globals;
                solutionGlobals[slnDescPropName] = value;
                solutionGlobals.set_VariablePersists(slnDescPropName, true);
            }
        }

        #endregion

        //////////////////////////////////////////////////////////////////
        // IFilterProperties Implementation
        // public EnvDTE.vsFilterProperties IsPropertyHidden(string PropertyName)
        // Microsoft.VisualStudio.PropertyBrowser.AutoExtMgr_IFilterProperties 
        #region IFilterProperties Members

        public EnvDTE.vsFilterProperties IsPropertyHidden(string PropertyName) 
        {
            EnvDTE.vsFilterProperties propertyHidden;

            string methodName = 
                MethodBase.GetCurrentMethod().DeclaringType.FullName + "::" + 
                MethodBase.GetCurrentMethod().Name ;
            Trace.WriteLine("Entering " + methodName + " " + PropertyName);

            if ( true == PropertyName.Equals("Description") )
            {
                propertyHidden = EnvDTE.vsFilterProperties.vsFilterPropertiesAll;
            }
            else
            {
                propertyHidden = EnvDTE.vsFilterProperties.vsFilterPropertiesNone; 
            }

            Trace.WriteLine("Leaving " + methodName + " " + propertyHidden);
            return propertyHidden;
        }

        #endregion
    }
}
