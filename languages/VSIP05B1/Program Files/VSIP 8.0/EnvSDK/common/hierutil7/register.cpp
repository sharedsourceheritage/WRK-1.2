//---------------------------------------------------------------------------
// Microsoft Visual Studio
//
// register.cpp
//
//  Copyright (C) 1997 - 2001 Microsoft Corporation.  
//  All rights reserved.
//
// Description:
//
// Registration helper for packages
//---------------------------------------------------------------------------
#include "hu_pch.h"
#include "register.h"
#include "oleref.h"
#include "VSRegKeyNames.h"

// package keys
static LPCTSTR g_szInprocServer32    = _T("InprocServer32");
static LPCTSTR g_szAutomationKey    = _T("Automation");

// Install keys
static LPCTSTR g_szInstProdsKey        = _T("InstalledProducts");
static LPCTSTR g_szInstPackageKey    = _T("Package");
static LPCTSTR g_szInstResIdKey        = _T("ResourceID");
static LPCTSTR g_szInstResTypeKey    = _T("ResourceType");
static LPCTSTR g_szInstProdDetailsKey = _T("ProductDetails");
static LPCTSTR g_szInstUseInterfaceKey    = _T("UseInterface");

// service keys
static LPCTSTR g_szServicesKey = _T("Services");
static LPCTSTR g_szServiceNameKey = _T("Name");

// menu(command table) keys
static LPCTSTR g_szMenusKey = _T("Menus");

// languages (language manager) keys
static LPCTSTR g_szLangManKey = _T("Languages");
static LPCTSTR g_szFileExt = _T("File Extensions");
static LPCTSTR g_szLangSrvcs = _T("Language Services");
static LPCTSTR g_szCompletion = _T("ShowCompletion");
static LPCTSTR g_szSmartIndent = _T("ShowSmartIndent");
static LPCTSTR g_szUseStockColors = _T("UseStockColors");
static LPCTSTR g_szReqStockColors = _T("RequestStockColors");
static LPCTSTR g_szAutoPropKey = _T("AutomationProperties");
static LPCTSTR g_szTextEditor = _T("TextEditor");
static LPCTSTR g_szPackage = _T("Package");
static LPCTSTR g_szName = _T("Name");

// ToolWindows keys
static LPCTSTR g_szToolWindowsKey = _T("ToolWindows");

// Project File Filter
static LPCTSTR g_szProjectSettingsKey = _T("ProjectSettings");
static LPCTSTR g_szProjectFileFilterKey = _T("FileFilter");

static LPCTSTR g_szMultiFileKey = _T("MultiFileAssociation");

//---------------------------------------------------------------------------
// create key under HKEY_LOCAL_MACHINE
// if pszAltKey != NULL, use instead of REGKEY_VISUALSTUDIOROOT
//---------------------------------------------------------------------------
static LONG CreateBaseKey(LPCTSTR pszAltKey, CRegKey *pKey)
{
    LONG lr = ERROR_SUCCESS;
    if (NULL != pszAltKey)
        lr = pKey->Create(HKEY_LOCAL_MACHINE, pszAltKey);
    else
        lr = pKey->Create(HKEY_LOCAL_MACHINE, _T(REGKEY_VISUALSTUDIOROOT));
    ASSERT(ERROR_SUCCESS == lr);
    return lr;
}

//---------------------------------------------------------------------------
//key:    g_szBaseKey/Packages
//key:        /{clsidPackage}        = clsid
//val:            /(Default)        = pszPackageName
//val:            /InprocServer32 = ModuleFilename
//---------------------------------------------------------------------------
BOOL RegisterPackage(REFIID clsid,
                     LPCTSTR pszPackageName, 
                     LPCTSTR pszAltKey,
                     DWORD dwAutoCount,
                     LPCTSTR szAutomationNames[],
                     LPCTSTR pszSatDir,
                     LPCTSTR pszSatFile)
{
    CRegKey key;
    USES_CONVERSION;
    COleMalloc<OLECHAR>    smpszGUIDPkg;
    TCHAR szModuleFileName[_MAX_PATH + 1];

    if ((CreateBaseKey(pszAltKey, &key) != ERROR_SUCCESS)
        || (key.Create(key, _T(REGKEY_PACKAGES)) != ERROR_SUCCESS)
        || (StringFromCLSID(clsid, &smpszGUIDPkg) != S_OK)
        || (key.Create(key, OLE2T(smpszGUIDPkg)) != ERROR_SUCCESS)
        || !(::GetModuleFileName(_AtlBaseModule.GetModuleInstance(), szModuleFileName, _MAX_PATH)))
    {
        return FALSE;
    }
    key.SetStringValue(NULL, pszPackageName);
    key.SetStringValue(g_szInprocServer32, szModuleFileName);

    if (dwAutoCount)
    {
        CRegKey autokey;
        ASSERT(NULL != szAutomationNames);
        if (ERROR_SUCCESS == autokey.Create(key, g_szAutomationKey))
        {
            do {
                --dwAutoCount;
                ASSERT(NULL != szAutomationNames[dwAutoCount]);
                autokey.SetStringValue(szAutomationNames[dwAutoCount], _T(""));
            } while (dwAutoCount);
        }
        else return FALSE;
    }
    if (NULL != pszSatDir && NULL != pszSatFile)
    {
        CRegKey satkey;
        if (ERROR_SUCCESS == satkey.Create(key, _T(REGKEY_SATELLITEDLL)))
        {
            satkey.SetStringValue(_T(REGVALUE_SATELLITEDLLPATH), pszSatDir);
            satkey.SetStringValue(_T(REGVALUE_SATELLITEDLLNAME), pszSatFile);
        }
        else return FALSE;
    }
    return TRUE;
}

//---------------------------------------------------------------------------
// Unregisters the package information
//---------------------------------------------------------------------------
BOOL UnregisterPackage(REFIID clsid, LPCTSTR pszAltKey)
{
    CRegKey key;
    USES_CONVERSION;
    COleMalloc<OLECHAR>    smpszGUID;

    if ((CreateBaseKey(pszAltKey, &key) != ERROR_SUCCESS)
        || (key.Open(key, _T(REGKEY_PACKAGES)) != ERROR_SUCCESS)
        || (StringFromCLSID(clsid, &smpszGUID) != S_OK)
        || (key.RecurseDeleteKey(OLE2T(smpszGUID)) != ERROR_SUCCESS))
    {
        return FALSE;
    }
    // Remove project templates
    if ((CreateBaseKey(pszAltKey, &key) != ERROR_SUCCESS)
        || (key.Open(key, _T(REGKEY_NEWPROJTEMPLATES)) != ERROR_SUCCESS)
        || (key.Open(key, _T(REGKEY_TEMPLATEDIRS)) != ERROR_SUCCESS)
        || (key.RecurseDeleteKey(OLE2T(smpszGUID)) != ERROR_SUCCESS))
    {
        return FALSE;
    }

    return TRUE;
}

//---------------------------------------------------------------------------
//    g_szBaseKey/Projects
//        /{guidProjectType}                    = clsidProject
//            /(Default)                        = pszProjectName
//            /Package                        = clsidPackage
//            /DisplayProjectFileExtensions    = pszDispFileExt
//            /PossibleProjectExtensions        = pszPossProjExt
//            /ProjectTemplatesDir            = pszTmplDir
//            /ItemTemplatesDir                = pszItmTmplDir
//            /DesignerTemplatesDir            = psrDesignerTmplDir
//            /DefaultProjectExtension        = pszDefProjExt
//            /DevStudioPackageID                = dwPkgID
//---------------------------------------------------------------------------
BOOL RegisterProject(REFIID clsidPackage, REFIID clsidProject,
                     LPCTSTR pszProjectKey,
                     LPCTSTR pszProjectItemKey,
                     LPCTSTR pszProjectName,
                     LPCTSTR pszProjectItemName,
                     DWORD     dwProjectPriority,
                     DWORD     dwItemPriority,
                     LPCTSTR pszDispFileExt,
                     LPCTSTR pszPossProjExt,
                     LPCTSTR pszTmplDir,
                     LPCTSTR pszItmTmplDir,
                     LPCTSTR pszDesignerTmplDir,
                     LPCTSTR pszAltKey,
                     LPCTSTR pszDefProjExt,
                     REFGUID rguidPseudoFolder,
                     DWORD     dwPkgID)
{
    CRegKey key;
    USES_CONVERSION;
    COleMalloc<OLECHAR>    smpszGUIDPkg, smpszGUIDProject;

    if ((CreateBaseKey(pszAltKey, &key) != ERROR_SUCCESS)
        || (key.Create(key, _T(REGKEY_PROJECTS)) != ERROR_SUCCESS)
        || (StringFromCLSID(clsidProject, &smpszGUIDProject) != S_OK)
        || (StringFromCLSID(clsidPackage, &smpszGUIDPkg) != S_OK)
        || (key.Create(key, OLE2T(smpszGUIDProject)) != ERROR_SUCCESS))
    {
        return FALSE;
    }
    key.SetStringValue(NULL, pszProjectName);
    key.SetStringValue(_T(REGVALUE_CLSIDPACKAGE), OLE2T(smpszGUIDPkg));
    key.SetStringValue(_T(REGVALUE_PROJFILTER), pszDispFileExt);
    key.SetStringValue(_T(REGVALUE_PROJECTEXT), pszPossProjExt);
    key.SetStringValue(_T(REGVALUE_PROJTEMPLATES), pszTmplDir);
    key.SetStringValue(_T(REGVALUE_ITEMTEMPLATES), pszItmTmplDir);
    if (pszDesignerTmplDir != NULL)
    {
        key.SetStringValue(_T("DesignerTemplatesDir"), pszDesignerTmplDir);
    }
    key.SetStringValue(_T(REGVALUE_PROJECTDEFEXT), pszDefProjExt);
    // Only set the devstudio pkg id if non zero
    if(dwPkgID)
        key.SetDWORDValue(_T(REGVALUE_DEVSTUDIOPKGID), dwPkgID);

    if ((key.Create(key, _T(REGKEY_ADDITEMTEMPLATES)) != ERROR_SUCCESS)
        || (key.Create(key, _T(REGKEY_TEMPLATEDIRS)) != ERROR_SUCCESS)
        || (key.Create(key, OLE2T(smpszGUIDPkg)) != ERROR_SUCCESS)
        || (key.Create(key, pszProjectItemKey) != ERROR_SUCCESS))
    {
        return FALSE;
    }
    key.SetStringValue(NULL, pszProjectItemName);
    key.SetDWORDValue(_T(REGVALUE_SORTPRIORITY), dwItemPriority);
    key.SetStringValue(_T(REGVALUE_TEMPLATESDIR), pszItmTmplDir);

    if ((CreateBaseKey(pszAltKey, &key) != ERROR_SUCCESS)
        || (key.Create(key, _T(REGKEY_NEWPROJTEMPLATES)) != ERROR_SUCCESS)
        || (key.Create(key, _T(REGKEY_TEMPLATEDIRS)) != ERROR_SUCCESS)
        || (key.Create(key, OLE2T(smpszGUIDPkg)) != ERROR_SUCCESS)
        || (key.Create(key, pszProjectKey) != ERROR_SUCCESS))
    {
        return FALSE;
    }
    key.SetStringValue(NULL, pszProjectName);
    key.SetDWORDValue(_T(REGVALUE_SORTPRIORITY), dwProjectPriority);
    key.SetStringValue(_T(REGVALUE_TEMPLATESDIR), pszTmplDir);
    // Only set the pseudo folder GUID if non-null
    if (rguidPseudoFolder != GUID_NULL)
    {
        COleMalloc<OLECHAR> smpszGUIDFolder;
        StringFromCLSID(rguidPseudoFolder, &smpszGUIDFolder);
        key.SetStringValue(_T(REGVALUE_FOLDERGUID), OLE2T(smpszGUIDFolder));

        if ((CreateBaseKey(pszAltKey, &key) == ERROR_SUCCESS)
            && (key.Create(key, _T(REGKEY_NEWPROJTEMPLATES)) == ERROR_SUCCESS)
            && (key.Create(key, _T(REGKEY_PSEUDOFOLDERS)) == ERROR_SUCCESS)
            && (key.Create(key, OLE2T(smpszGUIDFolder)) == ERROR_SUCCESS))
        {
            COleMalloc<OLECHAR> smpszGUIDShellPackage;
            StringFromCLSID(CLSID_VsEnvironmentPackage, &smpszGUIDShellPackage);
            TCHAR szDisplayName[_MAX_PATH];
            DWORD dwSortPriority = Priority_VsNewProjectPseudoFolder;
            key.SetStringValue(_T(REGVALUE_CLSIDPACKAGE), OLE2T(smpszGUIDShellPackage));
            wsprintf(szDisplayName, _T("#%d"), RESID_VsNewProjectPseudoFolderName);
            key.SetStringValue(_T(REGVALUE_DISPLAYNAME), szDisplayName);
            key.SetDWORDValue(_T(REGVALUE_SORTPRIORITY), dwSortPriority);
        }
    }

    return TRUE;
}

//---------------------------------------------------------------------------
// Call to register each filter.
//---------------------------------------------------------------------------
BOOL RegisterProjectFilter(REFIID clsidProject, DWORD grfFilterOptions,
                     LPCTSTR pszFilter,    DWORD dwRanking, LPCTSTR pszAltKey /*=NULL*/)
{
    CRegKey key;
    USES_CONVERSION;
    COleMalloc<OLECHAR>    smpszGUIDProject;

    if ((CreateBaseKey(pszAltKey, &key) != ERROR_SUCCESS)
        || (key.Create(key, _T(REGKEY_PROJECTS)) != ERROR_SUCCESS)
        || (StringFromCLSID(clsidProject, &smpszGUIDProject) != S_OK)
        || (key.Create(key, OLE2T(smpszGUIDProject)) != ERROR_SUCCESS))
    {
        return FALSE;
    }
    // Create Filters\/1, Filters\/2, etc.
    WCHAR temp[20];
    temp[0] = 0;
    _itow(dwRanking, temp, 10);
    CString strFilterKey = _T(REGKEY_ITEMFILTERS);
    strFilterKey += _T("\\/");
    strFilterKey += temp;
    
    if(key.Create(key, strFilterKey) != ERROR_SUCCESS)
        return FALSE;

    // Filter string is the default value.
    key.SetStringValue(NULL, pszFilter);

    // Now write the options. Default values are all 0, so only write ones that are
    // set.
    if(grfFilterOptions & FILTER_COMMONOPEN)
        key.SetDWORDValue(_T(REGVALUE_COMMONOPENFILTER), 1);
    if(grfFilterOptions & FILTER_COMMONFIND)
        key.SetDWORDValue(_T(REGVALUE_COMMONFINDFILTER), 1);
    if(grfFilterOptions & FILTER_FINDINFILES)
        key.SetDWORDValue(_T(REGVALUE_FINDINFILESFILTER), 1);
    if(grfFilterOptions & FILTER_NOTOPENFILE)
        key.SetDWORDValue(_T(REGVALUE_NOTOPENFILEFILTER), 1);
    if(grfFilterOptions & FILTER_NOTADDEXISTING)
        key.SetDWORDValue(_T(REGVALUE_NOTADDEXISTFILTER), 1);

    return TRUE;
}
//---------------------------------------------------------------------------
// Call to register each project specific editor. 
//    g_szBaseKey/Projects
//        /{clsidProject}                
//            \Editors
//                .ext = {iidEditorFactory}
//                .ext1 = {iidEditorFactory1}, et.c
//---------------------------------------------------------------------------
BOOL RegisterProjectSpecificEditor(REFIID clsidProject, 
                     LPCTSTR pszExtension,    REFIID iidEditorFactory,
                     LPCTSTR pszAltKey)
{
    CRegKey key;
    USES_CONVERSION;
    COleMalloc<OLECHAR>    smpszGUIDProject;
    COleMalloc<OLECHAR>    smpszGUIDEditorFactory;
    
    // Create clsidProject\Editors
    if ((CreateBaseKey(pszAltKey, &key) == ERROR_SUCCESS)
        && (key.Create(key, _T(REGKEY_PROJECTS)) == ERROR_SUCCESS)
        && (StringFromCLSID(clsidProject, &smpszGUIDProject) == S_OK)
        && (key.Create(key, OLE2T(smpszGUIDProject)) == ERROR_SUCCESS)
        && (key.Create(key, _T(REGKEY_EDITORS)) == ERROR_SUCCESS))
    {
        // Now add the extension - editor factory value
        if(StringFromCLSID(iidEditorFactory, &smpszGUIDEditorFactory) == S_OK)
        {    // Set the value
            key.SetStringValue(pszExtension, OLE2T(smpszGUIDEditorFactory));
            return TRUE;
        }
    }
    return FALSE;
}

//---------------------------------------------------------------------------
// Registers path to templates for the misc files project (new files)
//    g_szBaseKey/Projects
//        /{guidMiscFilesProject}                = Misc files project
//            \AddItemTemplates
//            \TemplateDirs
//            \{clsidPackage}            
//            \/1                                = pszDefValue
//            /SortPriority                    = dwItemPriority
//            /TemplatesDir                    = pszItmTmplDir
//---------------------------------------------------------------------------
BOOL RegisterNewFileTemplateDir(REFIID clsidPackage, LPCTSTR pszDefValue,
                LPCTSTR pszItmTmplDir, DWORD dwItemPriority, LPCTSTR pszAltKey)
{
    CRegKey key;
    USES_CONVERSION;
    COleMalloc<OLECHAR> smpszGUIDPkg, smpszGUIDProject;

    if ((CreateBaseKey(pszAltKey, &key) != ERROR_SUCCESS)
        || (key.Create(key, _T(REGKEY_PROJECTS)) != ERROR_SUCCESS)
        || (StringFromCLSID(CLSID_MiscellaneousFilesProject, &smpszGUIDProject) != S_OK)
        || (StringFromCLSID(clsidPackage, &smpszGUIDPkg) != S_OK)
        || (key.Create(key, OLE2T(smpszGUIDProject)) != ERROR_SUCCESS)
        || (key.Create(key, _T(REGKEY_ADDITEMTEMPLATES)) != ERROR_SUCCESS)
        || (key.Create(key, _T(REGKEY_TEMPLATEDIRS)) != ERROR_SUCCESS)
        || (key.Create(key, OLE2T(smpszGUIDPkg)) != ERROR_SUCCESS)
        || (key.Create(key, _T("/1")) != ERROR_SUCCESS))
    {
        return FALSE;
    }
    key.SetStringValue(NULL, pszDefValue);
    key.SetStringValue(_T(REGVALUE_TEMPLATESDIR), pszItmTmplDir);
    key.SetDWORDValue(_T(REGVALUE_SORTPRIORITY), dwItemPriority);
    return TRUE;
}

//---------------------------------------------------------------------------
// Unregisters path to templates for the misc files project (new files)
//---------------------------------------------------------------------------
BOOL UnregisterNewFileTemplateDir(REFIID clsidPackage, LPCTSTR pszAltKey)
{
    CRegKey key;
    USES_CONVERSION;
    COleMalloc<OLECHAR> smpszGUIDPkg, smpszGUIDProject;

    if ((CreateBaseKey(pszAltKey, &key) != ERROR_SUCCESS)
        || (key.Open(key, _T(REGKEY_PROJECTS)) != ERROR_SUCCESS)
        || (StringFromCLSID(CLSID_MiscellaneousFilesProject, &smpszGUIDProject) != S_OK)
        || (StringFromCLSID(clsidPackage, &smpszGUIDPkg) != S_OK)
        || (key.Open(key, OLE2T(smpszGUIDProject)) != ERROR_SUCCESS)
        || (key.Open(key, _T(REGKEY_ADDITEMTEMPLATES)) != ERROR_SUCCESS)
        || (key.Open(key, _T(REGKEY_TEMPLATEDIRS)) != ERROR_SUCCESS)
        || (key.RecurseDeleteKey(OLE2T(smpszGUIDPkg)) != ERROR_SUCCESS))
    {
        return FALSE;
    }
    return TRUE;
}

//---------------------------------------------------------------------------
// Register About Box information
//    
// g_szBaseKey/Installed Products
//        /    Visual Interdev                    = pszProductName,
//            Package                            = clsidPackage
//            ResourceID                        = dwPIDResId
//            ResourceType                    = dwPIDResType
//            ProductDetails                    = pszProductDetails
//
// Note that pszProductDetails, pszProductName can contain "#ResID" to load
// strings from resource dll rather than hardcoding.
//---------------------------------------------------------------------------
BOOL RegisterAboutInfo(REFIID clsidPkg, LPCTSTR pszUniqueInstallKey, LPCTSTR pszProductName, 
                       LPCTSTR pszProductDetails, DWORD dwPIDResId, DWORD dwPIDResType, LPCTSTR pszAltKey)
{
    CRegKey key;
    USES_CONVERSION;
    COleMalloc<OLECHAR>    smpszGUIDPkg;
    // Create \VisualStudio\v6\InstalledProducts\pszUniqueInstallKey
    if ((CreateBaseKey(pszAltKey, &key) != ERROR_SUCCESS)
        || (key.Create(key, g_szInstProdsKey) != ERROR_SUCCESS)
        || (key.Create(key, pszUniqueInstallKey) != ERROR_SUCCESS))
    {
        return FALSE;
    }

    ::StringFromCLSID(clsidPkg, &smpszGUIDPkg);
    key.SetStringValue(NULL, pszProductName);
    key.SetStringValue(g_szInstPackageKey, OLE2T(smpszGUIDPkg));
    key.SetDWORDValue(g_szInstResIdKey, dwPIDResId);
    key.SetDWORDValue(g_szInstResTypeKey, dwPIDResType);
    key.SetStringValue(g_szInstProdDetailsKey, pszProductDetails);
    return TRUE;
}

//---------------------------------------------------------------------------
// Register About Box information
//    
// Use this if you support IVsInstalledProduct/IVsMicrosoftInstalledProduct
// g_szBaseKey/Installed Products
//        /    VisualBasic    (pszUniqueInstallKey) = non-set
//            Package                              = clsidPackage
//            UseInterface                      = 1
//
//---------------------------------------------------------------------------
BOOL RegisterAboutInfo(REFIID clsidPkg, LPCTSTR pszUniqueInstallKey, LPCTSTR pszAltKey)
{
    CRegKey key;
    USES_CONVERSION;
    COleMalloc<OLECHAR>    smpszGUIDPkg;
    // Create \VisualStudio\v6\InstalledProducts\pszUniqueInstallKey
    if ((CreateBaseKey(pszAltKey, &key) != ERROR_SUCCESS)
        || (key.Create(key, g_szInstProdsKey) != ERROR_SUCCESS)
        || (key.Create(key, pszUniqueInstallKey) != ERROR_SUCCESS))
    {
        return FALSE;
    }

    ::StringFromCLSID(clsidPkg, &smpszGUIDPkg);
    key.SetStringValue(g_szInstPackageKey, OLE2T(smpszGUIDPkg));
    key.SetDWORDValue(g_szInstUseInterfaceKey, 1);
    return TRUE;
}

//---------------------------------------------------------------------------
//UnRegister About information
//---------------------------------------------------------------------------
BOOL UnregisterAboutInfo(LPCTSTR pszUniqueInstallKey, LPCTSTR pszAltKey)
{
    CRegKey key;
    // Nuke \VisualStudio\v6\InstalledProducts\pszUniqueInstallKey
    if ((CreateBaseKey(pszAltKey, &key) != ERROR_SUCCESS)
        || (key.Open(key, g_szInstProdsKey) != ERROR_SUCCESS)
        || (key.RecurseDeleteKey(pszUniqueInstallKey) != ERROR_SUCCESS))
    {
        return FALSE;
    }
    return TRUE;
}

//---------------------------------------------------------------------------
// Registers an output window
//    
// g_szBaseKey/OutputWindow
//        /    {clsidOutputWindow}                = output window guid,
//                default value                = pszOutputWindowName
//            Package                            = clsidPackage (owner)
//
// Note that pszOutputWindowName can contain "#ResID" to load
// strings from resource dll rather than hardcoding.
//---------------------------------------------------------------------------
BOOL RegisterOutputWindow(REFIID clsidOutputWindow, REFIID clsidPkg, LPCTSTR pszOutputWindowName, 
                          BOOL bInitiallyInvisible, LPCTSTR pszAltKey)
{
    CRegKey key;
    USES_CONVERSION;
    COleMalloc<OLECHAR>    smpszGUIDPkg, smpszGUIDOutputWindow;
    // Create \VisualStudio\v6\OutputWindow\{clsidOutputWindow}
    if ((CreateBaseKey(pszAltKey, &key) != ERROR_SUCCESS)
        || (key.Create(key, _T(REGKEY_OUTPUTWINDOW)) != ERROR_SUCCESS)
        || (StringFromCLSID(clsidOutputWindow, &smpszGUIDOutputWindow) != S_OK)
        || (key.Create(key, OLE2T(smpszGUIDOutputWindow)) != ERROR_SUCCESS))
    {
        return FALSE;
    }

    key.SetStringValue(NULL, pszOutputWindowName);
    StringFromCLSID(clsidPkg, &smpszGUIDPkg);
    key.SetStringValue(g_szInstPackageKey, OLE2T(smpszGUIDPkg));
    key.SetDWORDValue(_T(REGVALUE_PANEINITINVISIBLE), (bInitiallyInvisible) ? 1 : 0);
    return TRUE;
}

//---------------------------------------------------------------------------
// UnRegister output Window
//---------------------------------------------------------------------------
BOOL UnregisterOutputWindow(REFIID clsidOutputWindow, LPCTSTR pszAltKey)
{
    CRegKey key;
    USES_CONVERSION;
    // Nuke \VisualStudio\v6\OutputWindow\{clsidOutputWindow}
    COleMalloc<OLECHAR>    smpszGUIDPkg, smpszGUIDOutputWindow;
    if ((CreateBaseKey(pszAltKey, &key) != ERROR_SUCCESS)
        || (key.Open(key, _T(REGKEY_OUTPUTWINDOW)) != ERROR_SUCCESS)
        || (StringFromCLSID(clsidOutputWindow, &smpszGUIDOutputWindow) != S_OK)
        || (key.RecurseDeleteKey(OLE2T(smpszGUIDOutputWindow)) != ERROR_SUCCESS))
    {
        return FALSE;
    }
    return TRUE;
}

//---------------------------------------------------------------------------
// Unregisters the project keys
//---------------------------------------------------------------------------
BOOL UnregisterProject(REFIID clsid, LPCTSTR pszAltKey)
{
    CRegKey key;
    USES_CONVERSION;
    COleMalloc<OLECHAR>    smpszGUID;

    if ((CreateBaseKey(pszAltKey, &key) != ERROR_SUCCESS)
        || (key.Open(key, _T(REGKEY_PROJECTS)) != ERROR_SUCCESS)
        || (StringFromCLSID(clsid, &smpszGUID)!= S_OK)
        || (key.RecurseDeleteKey(OLE2T(smpszGUID)) != ERROR_SUCCESS))
    {
        return FALSE;
    }

    return TRUE;
}

//---------------------------------------------------------------------------
//key:    g_szBaseKey/Projects
//key:        /Services
//key:            /{guidOfServiceProffered}    = clsidService
//val:                /(Default)                = clsidPackage
//val:                /Name                    = pszServiceName
//---------------------------------------------------------------------------
BOOL RegisterService(REFIID clsidPackage, REFIID clsidService,
                     LPCTSTR pszServiceName, LPCTSTR pszAltKey)
{
    CRegKey key;
    USES_CONVERSION;
    COleMalloc<OLECHAR>    smpszGUIDService, smpszGUIDPkg;

    if ((CreateBaseKey(pszAltKey, &key) != ERROR_SUCCESS)
        || (key.Create(key, g_szServicesKey) != ERROR_SUCCESS)
        || (StringFromCLSID(clsidService, &smpszGUIDService)!= S_OK)
        || (key.Create(key, OLE2T(smpszGUIDService)) != ERROR_SUCCESS)
        || (StringFromCLSID(clsidPackage, &smpszGUIDPkg)!= S_OK))
    {
        return FALSE;
    }
    key.SetStringValue(NULL, OLE2T(smpszGUIDPkg));
    key.SetStringValue(g_szServiceNameKey, pszServiceName);
    return TRUE;
}

//---------------------------------------------------------------------------
// Unregisters the given service
//---------------------------------------------------------------------------
BOOL UnregisterService(REFIID clsidService, LPCTSTR pszAltKey)
{
    CRegKey key;
    USES_CONVERSION;
    COleMalloc<OLECHAR>    smpszGUID;

    if ((CreateBaseKey(pszAltKey, &key) != ERROR_SUCCESS)
        || (key.Open(key, g_szServicesKey) != ERROR_SUCCESS)
        || (StringFromCLSID(clsidService, &smpszGUID)!= S_OK)
        || (key.RecurseDeleteKey(OLE2T(smpszGUID)) != ERROR_SUCCESS))
    {
        return FALSE;
    }
    return TRUE;
}

//---------------------------------------------------------------------------
//key:    g_szBaseKey/Projects
//key:        /Menus
//val:            /{clsidPackage} = pszCommandTableFilename
//---------------------------------------------------------------------------
BOOL RegisterCommandTable(REFIID clsidPackage,
                          LPCTSTR pszCommandTableFilename, LPCTSTR pszAltKey)
{
    CRegKey key;
    USES_CONVERSION;
    COleMalloc<OLECHAR>    smpszGUID;

    if ((CreateBaseKey(pszAltKey, &key) != ERROR_SUCCESS)
        || (key.Create(key, g_szMenusKey) != ERROR_SUCCESS)
        || (StringFromCLSID(clsidPackage, &smpszGUID) != S_OK))
    {
        return FALSE;
    }    

    // Allocate ample memory.  We allocate for the worst case scenario:  each character
    // in the filename takes 3 TCHAR character slots to represent.  
    TCHAR* szKeyValue = new TCHAR[3 * (_MAX_PATH + _tcslen(pszCommandTableFilename) + 1)];
    if (!szKeyValue)
        return FALSE;
    
    ::GetModuleFileName(_AtlBaseModule.GetModuleInstance(), szKeyValue, _MAX_PATH);

    TCHAR *pch =_tcsrchr(szKeyValue, _T('\\'));
    pch = (pch == NULL) ? szKeyValue : _tcsinc(pch);
    _tcscpy(pch, pszCommandTableFilename);

    // Compute the return value
    BOOL bRetVal = (key.SetStringValue(OLE2T(smpszGUID), szKeyValue) == ERROR_SUCCESS);
    
    delete[] szKeyValue;
    return bRetVal;
}

//---------------------------------------------------------------------------
//key:    g_szBaseKey/Projects
//key:        /Menus
//val:            /{clsidPackage} = ModuleName, ResourceID, Version
//---------------------------------------------------------------------------
BOOL RegisterCommandTable(
    REFIID clsidPackage,
    UINT nIDCommandTable,
    UINT nVersion,
    LPCTSTR pszFilename /*= NULL*/,
    LPCTSTR pszAltKey /*=NULL*/)
{
    CRegKey key;
    USES_CONVERSION;
    COleMalloc<OLECHAR>    smpszGUID;

    if ((CreateBaseKey(pszAltKey, &key) != ERROR_SUCCESS)
        || (key.Create(key, g_szMenusKey) != ERROR_SUCCESS)
        || (StringFromCLSID(clsidPackage, &smpszGUID) != S_OK))
    {
        return FALSE;
    }

    // MAX_PATH + 40 characters for nIDCommandTable + 40 characters for nVersion + 1 terminating NULL.
    // We multiply by 3 so that we allocate for the worst case scenario (each character actually takes
    // up 3 slots -- in mbcs)
    TCHAR szModuleFileName[3 * _MAX_PATH + 81];
    if (NULL == pszFilename)
    {
        ::GetModuleFileName(_AtlBaseModule.GetModuleInstance(), szModuleFileName, _MAX_PATH);
        pszFilename = szModuleFileName;
    }

    CString strKeyValue;
    strKeyValue.Format(_T("%s, %d, %d"), pszFilename, nIDCommandTable, nVersion);

    return (key.SetStringValue(OLE2T(smpszGUID), strKeyValue) == ERROR_SUCCESS);
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
BOOL UnregisterCommandTable(REFIID clsid, LPCTSTR pszAltKey)
{
    CRegKey key;
    USES_CONVERSION;
    COleMalloc<OLECHAR>    smpszGUID;

    if ((CreateBaseKey(pszAltKey, &key) != ERROR_SUCCESS)
        || (key.Open(key, g_szMenusKey) != ERROR_SUCCESS)
        || (StringFromCLSID(clsid, &smpszGUID)!= S_OK))
    {
        return FALSE;
    }
    return (key.SetStringValue(OLE2T(smpszGUID), _T("")) == ERROR_SUCCESS);
}

//---------------------------------------------------------------------------
//key:    g_szBaseKey
//key:        /OutputWindow
//val:            /{clsidOutputWindowPane} = Name
//---------------------------------------------------------------------------
BOOL RegisterOutputWindowPane(
    REFIID clsidOutputWindowPane,
    LPCTSTR pszName,
    BOOL fInitiallyInvisible,
    LPCTSTR pszAltKey /*=NULL*/)
{
    CRegKey key;
    USES_CONVERSION;
    COleMalloc<OLECHAR>    smpszGUID;

    if ((CreateBaseKey(pszAltKey, &key) != ERROR_SUCCESS)
        || (key.Create(key, _T(REGKEY_OUTPUTWINDOW)) != ERROR_SUCCESS)
        || (StringFromCLSID(clsidOutputWindowPane, &smpszGUID) != S_OK)
        || (key.Create(key, OLE2T(smpszGUID)) != ERROR_SUCCESS))
    {
        return FALSE;
    }    

    if (key.SetStringValue(NULL, pszName) != ERROR_SUCCESS)
        return FALSE;

    return (key.SetDWORDValue(_T(REGVALUE_PANEINITINVISIBLE), (fInitiallyInvisible?1:0)) == ERROR_SUCCESS);
}

//---------------------------------------------------------------------------
// To set up the registry like:
//        basekey (VisualStudio/7.0)
//            langkey (Languages)
//                extkey (File Extenstions)
//                    ext (.sql)
//---------------------------------------------------------------------------
BOOL RegisterLanguageExtension(
    LPCTSTR szExt,
    REFIID sidLangMan,
    LPCTSTR pszAltKey    // = NULL
    )
{
    CRegKey    basekey;
    CRegKey    langkey;
    CRegKey    extkey;
    CRegKey    ext;

    USES_CONVERSION;
    COleMalloc<OLECHAR>    smpszGUID;

    if (CreateBaseKey(pszAltKey, &basekey) != ERROR_SUCCESS)
        return FALSE;

    if (langkey.Create(basekey, g_szLangManKey) != ERROR_SUCCESS)
        return FALSE;

    if (extkey.Create(langkey, g_szFileExt) != ERROR_SUCCESS)
        return FALSE;

    if (ext.Create(extkey, szExt) != ERROR_SUCCESS)
        return FALSE;

    if (StringFromCLSID(sidLangMan, &smpszGUID) != S_OK)
        return FALSE;

    if (ext.SetStringValue(NULL, OLE2T(smpszGUID)) != ERROR_SUCCESS)
        return FALSE;

    return TRUE;
}

//---------------------------------------------------------------------------
// To set up the registry like:
//        basekey (VisualStudio/7.0)
//            langkey (Languages)
//                langsrvcskey (Language Services)
//                    langname (SQL)
//            autoprop (AutomationProperties)
//                editor (TextEditor)
//                    editorname (T-SQL)
//---------------------------------------------------------------------------
BOOL RegisterLanguageService(
        REFIID clsidPackage,
        REFIID sidLangMan,
        REFIID sidTextEditor,
        LPCTSTR szLangName,
        BOOL fCompletion,
        BOOL fSmartIndent,
        BOOL fStockColors,
        LPCTSTR pszAltKey    // = NULL
        )
{
    CRegKey    basekey, langkey, langsrvcskey, langname;
    CRegKey    autoprop, editor, editorname;

    USES_CONVERSION;
    COleMalloc<OLECHAR>    smpszGUIDLangMan;
    COleMalloc<OLECHAR> smpszGUIDTextEd;

    // Language Managers are also services
    if (!RegisterService(clsidPackage, sidLangMan, szLangName, pszAltKey))
        return FALSE;

    if (CreateBaseKey(pszAltKey, &basekey) != ERROR_SUCCESS)
        return FALSE;

    if (langkey.Create(basekey, g_szLangManKey) != ERROR_SUCCESS)
        return FALSE;

    if (langsrvcskey.Create(langkey, g_szLangSrvcs) != ERROR_SUCCESS)
        return FALSE;

    if (langname.Create(langsrvcskey, szLangName) != ERROR_SUCCESS)
        return FALSE;

    if (StringFromCLSID(sidLangMan, &smpszGUIDLangMan) != S_OK)
        return FALSE;

    if (langname.SetStringValue(NULL, OLE2T(smpszGUIDLangMan)) != ERROR_SUCCESS)
        return FALSE;

    if (langname.SetDWORDValue(g_szCompletion, fCompletion ? 1:0) != ERROR_SUCCESS)
        return FALSE;

    if (langname.SetDWORDValue(g_szSmartIndent, fSmartIndent ? 1:0) != ERROR_SUCCESS)
        return FALSE;

    if (langname.SetDWORDValue(g_szReqStockColors, fStockColors ? 1:0) != ERROR_SUCCESS)
        return FALSE;

// Part 2
    if (autoprop.Create(basekey, g_szAutoPropKey) != ERROR_SUCCESS)
        return FALSE;

    if (editor.Create(autoprop, g_szTextEditor) != ERROR_SUCCESS)
        return FALSE;

    if (editorname.Create(editor, szLangName) != ERROR_SUCCESS)
        return FALSE;

    if (StringFromCLSID(sidTextEditor, &smpszGUIDTextEd) != S_OK)
        return FALSE;

    if (editorname.SetStringValue(g_szPackage, OLE2T(smpszGUIDTextEd)) != ERROR_SUCCESS)
        return FALSE;

    if (editorname.SetStringValue(g_szName, szLangName) != ERROR_SUCCESS)
        return FALSE;

    return TRUE;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
BOOL UnregisterLanguageService(
        REFIID sidLangMan,
        LPCTSTR szLangName,
        LPCTSTR pszAltKey    // = NULL
        )
{
    CRegKey    basekey;
    CRegKey    langkey;
    CRegKey    langsrvcskey;
    CRegKey    langname;
    CRegKey    autoprop, editor;

    USES_CONVERSION;
    COleMalloc<OLECHAR>    smpszGUID;

    if (!UnregisterService(sidLangMan, pszAltKey))
        return FALSE;

    if (CreateBaseKey(pszAltKey, &basekey) != ERROR_SUCCESS)
        return FALSE;

    if (langkey.Create(basekey, g_szLangManKey) != ERROR_SUCCESS)
        return FALSE;

    if (langsrvcskey.Create(langkey, g_szLangSrvcs) != ERROR_SUCCESS)
        return FALSE;

    if (langsrvcskey.RecurseDeleteKey(szLangName) != ERROR_SUCCESS)
        return FALSE;

// Part 2
    if (autoprop.Create(basekey, g_szAutoPropKey) != ERROR_SUCCESS)
        return FALSE;

    if (editor.Create(autoprop, g_szTextEditor) != ERROR_SUCCESS)
        return FALSE;

    if (editor.RecurseDeleteKey(szLangName) != ERROR_SUCCESS)
        return FALSE;

    return TRUE;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
BOOL UnregisterLanguageExtension(
        LPCTSTR szExt,
        LPCTSTR pszAltKey    // = NULL
        )
{
    CRegKey    basekey;
    CRegKey    langkey;
    CRegKey    extkey;
    CRegKey    ext;

    if (CreateBaseKey(pszAltKey, &basekey) != ERROR_SUCCESS)
        return FALSE;

    if (langkey.Create(basekey, g_szLangManKey) != ERROR_SUCCESS)
        return FALSE;

    if (extkey.Create(langkey, g_szFileExt) != ERROR_SUCCESS)
        return FALSE;

    if (extkey.RecurseDeleteKey(szExt) != ERROR_SUCCESS)
        return FALSE;

    return TRUE;
}

//---------------------------------------------------------------------------
//key:    g_szBaseKey
//key:        /ToolWindows
//val:            /{clsidToolWindow} = {clsidPackage}
//---------------------------------------------------------------------------
BOOL RegisterToolWindow(
    REFIID clsidToolWindow,
    REFIID clsidPackage,
    LPCTSTR pszAltKey /*=NULL*/)
{
    CRegKey key;
    USES_CONVERSION;
    COleMalloc<OLECHAR>    smpszGUID, smpszGUIDPkg;

    if ((CreateBaseKey(pszAltKey, &key) != ERROR_SUCCESS)
        || (key.Create(key, g_szToolWindowsKey) != ERROR_SUCCESS)
        || (StringFromCLSID(clsidToolWindow, &smpszGUID) != S_OK)
        || (key.Create(key, OLE2T(smpszGUID)) != ERROR_SUCCESS))
    {
        return FALSE;
    }    

    if ((StringFromCLSID(clsidPackage, &smpszGUIDPkg)!= S_OK) ||
        (key.SetStringValue(NULL, OLE2T(smpszGUIDPkg)) != ERROR_SUCCESS))
    {
        return FALSE;
    }

    return TRUE;
}

BOOL UnregisterToolWindow(
    REFIID clsidToolWindow,
    LPCTSTR pszAltKey /*=NULL*/)
{
    CRegKey key;
    USES_CONVERSION;
    COleMalloc<OLECHAR>    smpszGUID;

    if ((CreateBaseKey(pszAltKey, &key) != ERROR_SUCCESS)
        || (key.Open(key, g_szToolWindowsKey) != ERROR_SUCCESS)
        || (StringFromCLSID(clsidToolWindow, &smpszGUID)!= S_OK)
        || (key.RecurseDeleteKey(OLE2T(smpszGUID)) != ERROR_SUCCESS))
    {
        return FALSE;
    }
    return TRUE;
}


//------------------------------------------------------------------------------
// RegisterProjectFileFilter
//------------------------------------------------------------------------------
BOOL RegisterProjectFileFilter(
    REFIID clsidProject, 
    LPCTSTR pszAltKey,
    LPCTSTR pszDefaultFileFilter)
{
    CRegKey key, key2;
    USES_CONVERSION;
    COleMalloc<OLECHAR> smpszGUIDPkg, smpszGUIDProject;

    // Create/open parent keys
    if ((CreateBaseKey(pszAltKey, &key) != ERROR_SUCCESS)
        || (key.Create(key, _T(REGKEY_PROJECTS)) != ERROR_SUCCESS)
        || (StringFromCLSID(clsidProject, &smpszGUIDProject) != S_OK)
        || (key.Create(key, OLE2T(smpszGUIDProject)) != ERROR_SUCCESS))
    {
        return FALSE;
    }

    if ((key2.Create(key, g_szProjectSettingsKey) != ERROR_SUCCESS)
        || (key2.SetStringValue(g_szProjectFileFilterKey, pszDefaultFileFilter) != ERROR_SUCCESS))
    {
        return FALSE;
    }

    return TRUE;
}


//------------------------------------------------------------------------------
// RegisterMultiFileItem
//------------------------------------------------------------------------------
BOOL RegisterMultiFileItem(
    REFIID clsidProject, 
    LPCTSTR pszAltKey,
    LPCTSTR pszMultiFileKey,
    LPCTSTR pszMultiFileEntry)
{
    CRegKey key, key2;
    USES_CONVERSION;
    COleMalloc<OLECHAR> smpszGUIDProject;

    // Create/open parent keys
    if ((CreateBaseKey(pszAltKey, &key) != ERROR_SUCCESS)
        || (key.Create(key, _T(REGKEY_PROJECTS)) != ERROR_SUCCESS)
        || (StringFromCLSID(clsidProject, &smpszGUIDProject) != S_OK)
        || (key.Create(key, OLE2T(smpszGUIDProject)) != ERROR_SUCCESS)
        || (key.Create(key, g_szProjectSettingsKey) != ERROR_SUCCESS)
       )
    {
        return FALSE;
    }

    if ((key2.Create(key, g_szMultiFileKey) != ERROR_SUCCESS)
        || (key2.SetStringValue(pszMultiFileKey, pszMultiFileEntry) != ERROR_SUCCESS))
    {
        return FALSE;
    }

    return TRUE;
}

