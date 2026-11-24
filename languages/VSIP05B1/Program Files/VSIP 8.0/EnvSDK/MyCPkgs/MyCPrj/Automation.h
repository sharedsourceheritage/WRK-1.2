
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// Automation.h : Project automation declarations

#pragma once

// Note: You must replace the strings with the projects and events you expose
extern const WCHAR ENVSDK_DECLSPEC_SELECT_ANY g_wszAutomationProjects[] = L"MycProjects";
extern const WCHAR ENVSDK_DECLSPEC_SELECT_ANY g_wszAutomationProjectsEvents[] = L"MycProjectsEvents";
extern const WCHAR ENVSDK_DECLSPEC_SELECT_ANY g_wszAutomationProjectItemsEvents[] = L"MycProjectItemsEvents";

#define szguidCATIDProjectItem      prjCATIDMycPrjProjectItem
#define szguidCATIDProject          prjCATIDMycPrjProject
#define szProjectKind               prjKindMycPrjProject
#define szProjectsKind              prjKindMycPrjProjects
#define szProjectItemsKind          prjKindMycPrjProjectItems

#ifndef DTE_LIB_VERSION_MAJ
    #define DTE_LIB_VERSION_MAJ 7
#endif
#ifndef DTE_LIB_VERSION_MIN
    #define DTE_LIB_VERSION_MIN 0
#endif

//-------------------------------------------------------------------------
// The following smartptr type class is used to ensure we balance every 
// EnterAutomationFunction with a corresponding ExitAutomationFunction.
//-------------------------------------------------------------------------
class CEnterAutomationFunction
{
public :
    CEnterAutomationFunction() : m_hr(E_FAIL)
    {
        IVsExtensibility* pExt = _VxModule.GetIVsExtensibility();
        if (pExt)
            m_hr = pExt->EnterAutomationFunction();
        ASSERT(SUCCEEDED(m_hr));
    }
    ~CEnterAutomationFunction()
    {
        if(SUCCEEDED(m_hr))
        {
            IVsExtensibility* pExt = _VxModule.GetIVsExtensibility();
            if (pExt)
                pExt->ExitAutomationFunction();
        }
    }
protected:
    HRESULT m_hr;
};


