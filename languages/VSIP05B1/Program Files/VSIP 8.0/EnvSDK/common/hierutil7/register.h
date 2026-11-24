//---------------------------------------------------------------------------
// Microsoft Visual Studio
//
// register.h
//
//  Copyright (C) 1997 - 2001 Microsoft Corporation.  
//  All rights reserved.
//
// Description:
//
// Registration helper for packages
//---------------------------------------------------------------------------
#if (_MSC_VER > 1000) && !defined(NO_PRAGMA_ONCE)
#pragma once
#endif


#ifndef __REGISTER_H__
#define __REGISTER_H__

BOOL RegisterPackage(REFIID clsid, LPCTSTR szPackageName, 
					 LPCTSTR szAltKey,
					 DWORD dwAutoCount = 0, LPCTSTR szAutomationNames[] = NULL,
					 LPCTSTR pszSatDir = NULL, LPCTSTR pszSatFile = NULL);

BOOL UnregisterPackage(REFIID clsid, LPCTSTR szAltKey);

BOOL RegisterProject(REFIID clsidPackage, REFIID clsidProject,
					 LPCTSTR pszProjectKey,
					 LPCTSTR pszProjectItemKey,
					 LPCTSTR pszProjectName,
					 LPCTSTR pszProjectItemName,
					 DWORD	 dwProjectPriority,
					 DWORD	 dwItemPriority,
					 LPCTSTR pszDispFileExt,
					 LPCTSTR pszPossProjExt,
					 LPCTSTR pszTmplDir,
					 LPCTSTR pszItmTmplDir,
					 LPCTSTR pszDesignerTmplDir,
					 LPCTSTR pszAltKey,
					 LPCTSTR pszDefProjExt,
					 REFGUID rguidPseudoFolder,
					 DWORD	 dwPkgID = 0);

// Call to register each Open (bFind = FALSE) or Find filter.
BOOL RegisterProjectFilter(REFIID clsidProject, DWORD grfFilterOptions,
					 LPCTSTR pszFilter,	DWORD dwRanking, 
					 LPCTSTR pszAltKey = NULL);

// Call to register each project specific editor.
BOOL RegisterProjectSpecificEditor(REFIID clsidProject, 
					 LPCTSTR pszExtension,	REFIID iidEditorFactory, 
					 LPCTSTR pszAltKey = NULL);

BOOL RegisterNewFileTemplateDir(REFIID clsidPackage, LPCTSTR pszDefValue, LPCTSTR pszItmTmplDir,
					 DWORD dwItemPriority, LPCTSTR pszAltKey = NULL);
BOOL UnregisterNewFileTemplateDir(REFIID clsidPackage, LPCTSTR pszAltKey = NULL);

BOOL RegisterAboutInfo(REFIID clsid, LPCTSTR pszUniqueInstallKey, LPCTSTR pszProductName, 
					   LPCTSTR pszProductDetails, DWORD dwPIDResId, DWORD dwPIDResType, LPCTSTR szAltKey = NULL);

// Use this version if you support IVsInstalledProduct/IVsMicrosoftInstalledProduct
BOOL RegisterAboutInfo(REFIID clsidPkg, LPCTSTR pszUniqueInstallKey, LPCTSTR pszAltKey);

BOOL UnregisterAboutInfo(LPCTSTR pszUniqueInstallKey, LPCTSTR szAltKey = NULL);

BOOL RegisterOutputWindow(REFIID clsidOutputWindow,REFIID clsidPkg, LPCTSTR pszOutputName, BOOL bInitiallyInvisible, LPCTSTR szAltKey = NULL);
BOOL UnregisterOutputWindow(REFIID clsidOutputWindow,LPCTSTR szAltKey = NULL);

enum // grfFilterOptions
{
	FILTER_COMMONOPEN	=	1,	
	FILTER_COMMONFIND	=	2,	
	FILTER_FINDINFILES	=	4,
	FILTER_NOTOPENFILE	=	8,
	FILTER_NOTADDEXISTING =	16
};

BOOL UnregisterProject(REFIID clsid, LPCTSTR szAltKey);

BOOL RegisterService(REFIID clsidService, REFIID clsidPackage, 
					 LPCTSTR szServiceName, LPCTSTR szAltKey);

BOOL UnregisterService(REFIID clsidService, LPCTSTR szAltKey);

BOOL RegisterCommandTable(REFIID clsid, LPCTSTR szCommandTableFilename,
					LPCTSTR szAltKey =NULL);

BOOL RegisterCommandTable(REFIID clsid, UINT nIDCommandTable, UINT nVersion,
					LPCTSTR pszFilename = NULL,	LPCTSTR szAltKey =NULL);

BOOL UnregisterCommandTable(REFIID clsid, LPCTSTR szAltKey =NULL);

BOOL RegisterOutputWindowPane(
		REFIID clsidOutputWindowPane,
		LPCTSTR pszName,
		BOOL fInitiallyInvisible,
		LPCTSTR szAltKey =NULL);

BOOL RegisterLanguageExtension(
	LPCTSTR szExt,
	REFIID sidLangMan,
	LPCTSTR pszAltKey = NULL);

BOOL RegisterLanguageService(
		REFIID clsidPackage,
		REFIID sidLangMan,
		REFIID sidTextEditor,
		LPCTSTR szLangName,
		BOOL fCompletion,
		BOOL fSmartIndent,
		BOOL fStockColors,
		LPCTSTR pszAltKey = NULL);

BOOL UnregisterLanguageService(
		REFIID clsidPackage,
		LPCTSTR szLangName,
		LPCTSTR pszAltKey = NULL);

BOOL UnregisterLanguageExtension(
	LPCTSTR szExt,
	LPCTSTR pszAltKey = NULL);

BOOL RegisterToolWindow(
	REFIID clsidToolWindow,
	REFIID clsidPackage,
	LPCTSTR pszAltKey =NULL);

BOOL UnregisterToolWindow(
	REFIID clsidToolWindow,
	LPCTSTR pszAltKey =NULL);

BOOL RegisterProjectFileFilter(
	REFIID clsidProject, 
	LPCTSTR pszAltKey,
	LPCTSTR pszDefaultFileFilter);

BOOL RegisterMultiFileItem(
	REFIID clsidProject, 
	LPCTSTR pszAltKey,
	LPCTSTR pszMultiFileKey,
	LPCTSTR pszMultiFileEntry);

#endif // __REGISTER_H__
