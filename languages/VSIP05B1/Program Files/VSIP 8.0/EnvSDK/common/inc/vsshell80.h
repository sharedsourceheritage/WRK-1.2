

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for vsshell80.idl:
    Oicf, W0, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __vsshell80_h__
#define __vsshell80_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IVsProjectDebugTargetProvider_FWD_DEFINED__
#define __IVsProjectDebugTargetProvider_FWD_DEFINED__
typedef interface IVsProjectDebugTargetProvider IVsProjectDebugTargetProvider;
#endif 	/* __IVsProjectDebugTargetProvider_FWD_DEFINED__ */


#ifndef __IVsRegisterProjectDebugTargetProvider_FWD_DEFINED__
#define __IVsRegisterProjectDebugTargetProvider_FWD_DEFINED__
typedef interface IVsRegisterProjectDebugTargetProvider IVsRegisterProjectDebugTargetProvider;
#endif 	/* __IVsRegisterProjectDebugTargetProvider_FWD_DEFINED__ */


#ifndef __IVsBrowseObject_FWD_DEFINED__
#define __IVsBrowseObject_FWD_DEFINED__
typedef interface IVsBrowseObject IVsBrowseObject;
#endif 	/* __IVsBrowseObject_FWD_DEFINED__ */


#ifndef __IVsCfgBrowseObject_FWD_DEFINED__
#define __IVsCfgBrowseObject_FWD_DEFINED__
typedef interface IVsCfgBrowseObject IVsCfgBrowseObject;
#endif 	/* __IVsCfgBrowseObject_FWD_DEFINED__ */


#ifndef __IVsSolutionEvents4_FWD_DEFINED__
#define __IVsSolutionEvents4_FWD_DEFINED__
typedef interface IVsSolutionEvents4 IVsSolutionEvents4;
#endif 	/* __IVsSolutionEvents4_FWD_DEFINED__ */


#ifndef __IVsFireSolutionEvents2_FWD_DEFINED__
#define __IVsFireSolutionEvents2_FWD_DEFINED__
typedef interface IVsFireSolutionEvents2 IVsFireSolutionEvents2;
#endif 	/* __IVsFireSolutionEvents2_FWD_DEFINED__ */


#ifndef __IVsEnhancedDataTip_FWD_DEFINED__
#define __IVsEnhancedDataTip_FWD_DEFINED__
typedef interface IVsEnhancedDataTip IVsEnhancedDataTip;
#endif 	/* __IVsEnhancedDataTip_FWD_DEFINED__ */


#ifndef __IVsDebugger2_FWD_DEFINED__
#define __IVsDebugger2_FWD_DEFINED__
typedef interface IVsDebugger2 IVsDebugger2;
#endif 	/* __IVsDebugger2_FWD_DEFINED__ */


#ifndef __IVsQueryDebuggableProjectCfg_FWD_DEFINED__
#define __IVsQueryDebuggableProjectCfg_FWD_DEFINED__
typedef interface IVsQueryDebuggableProjectCfg IVsQueryDebuggableProjectCfg;
#endif 	/* __IVsQueryDebuggableProjectCfg_FWD_DEFINED__ */


#ifndef __IVsCommandWindow2_FWD_DEFINED__
#define __IVsCommandWindow2_FWD_DEFINED__
typedef interface IVsCommandWindow2 IVsCommandWindow2;
#endif 	/* __IVsCommandWindow2_FWD_DEFINED__ */


#ifndef __IVsDeferredDocView_FWD_DEFINED__
#define __IVsDeferredDocView_FWD_DEFINED__
typedef interface IVsDeferredDocView IVsDeferredDocView;
#endif 	/* __IVsDeferredDocView_FWD_DEFINED__ */


#ifndef __IVsBuildableProjectCfg2_FWD_DEFINED__
#define __IVsBuildableProjectCfg2_FWD_DEFINED__
typedef interface IVsBuildableProjectCfg2 IVsBuildableProjectCfg2;
#endif 	/* __IVsBuildableProjectCfg2_FWD_DEFINED__ */


#ifndef __IVsPublishableProjectStatusCallback_FWD_DEFINED__
#define __IVsPublishableProjectStatusCallback_FWD_DEFINED__
typedef interface IVsPublishableProjectStatusCallback IVsPublishableProjectStatusCallback;
#endif 	/* __IVsPublishableProjectStatusCallback_FWD_DEFINED__ */


#ifndef __IVsPublishableProjectCfg_FWD_DEFINED__
#define __IVsPublishableProjectCfg_FWD_DEFINED__
typedef interface IVsPublishableProjectCfg IVsPublishableProjectCfg;
#endif 	/* __IVsPublishableProjectCfg_FWD_DEFINED__ */


#ifndef __IVsParseCommandLine2_FWD_DEFINED__
#define __IVsParseCommandLine2_FWD_DEFINED__
typedef interface IVsParseCommandLine2 IVsParseCommandLine2;
#endif 	/* __IVsParseCommandLine2_FWD_DEFINED__ */


#ifndef __IVsCommandWindowsCollection_FWD_DEFINED__
#define __IVsCommandWindowsCollection_FWD_DEFINED__
typedef interface IVsCommandWindowsCollection IVsCommandWindowsCollection;
#endif 	/* __IVsCommandWindowsCollection_FWD_DEFINED__ */


#ifndef __IVsThreadPool_FWD_DEFINED__
#define __IVsThreadPool_FWD_DEFINED__
typedef interface IVsThreadPool IVsThreadPool;
#endif 	/* __IVsThreadPool_FWD_DEFINED__ */


#ifndef __IVsACAdapter_FWD_DEFINED__
#define __IVsACAdapter_FWD_DEFINED__
typedef interface IVsACAdapter IVsACAdapter;
#endif 	/* __IVsACAdapter_FWD_DEFINED__ */


#ifndef __IVsAutoCompletion_FWD_DEFINED__
#define __IVsAutoCompletion_FWD_DEFINED__
typedef interface IVsAutoCompletion IVsAutoCompletion;
#endif 	/* __IVsAutoCompletion_FWD_DEFINED__ */


#ifndef __IVsAutoCompletionUI_FWD_DEFINED__
#define __IVsAutoCompletionUI_FWD_DEFINED__
typedef interface IVsAutoCompletionUI IVsAutoCompletionUI;
#endif 	/* __IVsAutoCompletionUI_FWD_DEFINED__ */


#ifndef __IVsShell2_FWD_DEFINED__
#define __IVsShell2_FWD_DEFINED__
typedef interface IVsShell2 IVsShell2;
#endif 	/* __IVsShell2_FWD_DEFINED__ */


#ifndef __IVsGradient_FWD_DEFINED__
#define __IVsGradient_FWD_DEFINED__
typedef interface IVsGradient IVsGradient;
#endif 	/* __IVsGradient_FWD_DEFINED__ */


#ifndef __IVsUIShell2_FWD_DEFINED__
#define __IVsUIShell2_FWD_DEFINED__
typedef interface IVsUIShell2 IVsUIShell2;
#endif 	/* __IVsUIShell2_FWD_DEFINED__ */


#ifndef __IVsSupportItemHandoff2_FWD_DEFINED__
#define __IVsSupportItemHandoff2_FWD_DEFINED__
typedef interface IVsSupportItemHandoff2 IVsSupportItemHandoff2;
#endif 	/* __IVsSupportItemHandoff2_FWD_DEFINED__ */


#ifndef __IVsLaunchPadOutputParser_FWD_DEFINED__
#define __IVsLaunchPadOutputParser_FWD_DEFINED__
typedef interface IVsLaunchPadOutputParser IVsLaunchPadOutputParser;
#endif 	/* __IVsLaunchPadOutputParser_FWD_DEFINED__ */


#ifndef __IVsLaunchPad2_FWD_DEFINED__
#define __IVsLaunchPad2_FWD_DEFINED__
typedef interface IVsLaunchPad2 IVsLaunchPad2;
#endif 	/* __IVsLaunchPad2_FWD_DEFINED__ */


#ifndef __IVsOpenProjectOrSolutionDlg_FWD_DEFINED__
#define __IVsOpenProjectOrSolutionDlg_FWD_DEFINED__
typedef interface IVsOpenProjectOrSolutionDlg IVsOpenProjectOrSolutionDlg;
#endif 	/* __IVsOpenProjectOrSolutionDlg_FWD_DEFINED__ */


#ifndef __IVsCreateAggregateProject_FWD_DEFINED__
#define __IVsCreateAggregateProject_FWD_DEFINED__
typedef interface IVsCreateAggregateProject IVsCreateAggregateProject;
#endif 	/* __IVsCreateAggregateProject_FWD_DEFINED__ */


#ifndef __IVsAggregatableProject_FWD_DEFINED__
#define __IVsAggregatableProject_FWD_DEFINED__
typedef interface IVsAggregatableProject IVsAggregatableProject;
#endif 	/* __IVsAggregatableProject_FWD_DEFINED__ */


#ifndef __IVsAggregatableProjectFactory_FWD_DEFINED__
#define __IVsAggregatableProjectFactory_FWD_DEFINED__
typedef interface IVsAggregatableProjectFactory IVsAggregatableProjectFactory;
#endif 	/* __IVsAggregatableProjectFactory_FWD_DEFINED__ */


#ifndef __IVsParentProject2_FWD_DEFINED__
#define __IVsParentProject2_FWD_DEFINED__
typedef interface IVsParentProject2 IVsParentProject2;
#endif 	/* __IVsParentProject2_FWD_DEFINED__ */


#ifndef __IVsBuildPropertyStorage_FWD_DEFINED__
#define __IVsBuildPropertyStorage_FWD_DEFINED__
typedef interface IVsBuildPropertyStorage IVsBuildPropertyStorage;
#endif 	/* __IVsBuildPropertyStorage_FWD_DEFINED__ */


#ifndef __IVsProjectBuildSystem_FWD_DEFINED__
#define __IVsProjectBuildSystem_FWD_DEFINED__
typedef interface IVsProjectBuildSystem IVsProjectBuildSystem;
#endif 	/* __IVsProjectBuildSystem_FWD_DEFINED__ */


#ifndef __IPersistXMLFragment_FWD_DEFINED__
#define __IPersistXMLFragment_FWD_DEFINED__
typedef interface IPersistXMLFragment IPersistXMLFragment;
#endif 	/* __IPersistXMLFragment_FWD_DEFINED__ */


#ifndef __IVsProjectFlavorCfg_FWD_DEFINED__
#define __IVsProjectFlavorCfg_FWD_DEFINED__
typedef interface IVsProjectFlavorCfg IVsProjectFlavorCfg;
#endif 	/* __IVsProjectFlavorCfg_FWD_DEFINED__ */


#ifndef __IVsProjectFlavorCfgOutputGroups_FWD_DEFINED__
#define __IVsProjectFlavorCfgOutputGroups_FWD_DEFINED__
typedef interface IVsProjectFlavorCfgOutputGroups IVsProjectFlavorCfgOutputGroups;
#endif 	/* __IVsProjectFlavorCfgOutputGroups_FWD_DEFINED__ */


#ifndef __IVsProjectFlavorCfgProvider_FWD_DEFINED__
#define __IVsProjectFlavorCfgProvider_FWD_DEFINED__
typedef interface IVsProjectFlavorCfgProvider IVsProjectFlavorCfgProvider;
#endif 	/* __IVsProjectFlavorCfgProvider_FWD_DEFINED__ */


#ifndef __IVsFlavoredProjectReferences_FWD_DEFINED__
#define __IVsFlavoredProjectReferences_FWD_DEFINED__
typedef interface IVsFlavoredProjectReferences IVsFlavoredProjectReferences;
#endif 	/* __IVsFlavoredProjectReferences_FWD_DEFINED__ */


#ifndef __IVsFilterKeys2_FWD_DEFINED__
#define __IVsFilterKeys2_FWD_DEFINED__
typedef interface IVsFilterKeys2 IVsFilterKeys2;
#endif 	/* __IVsFilterKeys2_FWD_DEFINED__ */


#ifndef __IVsSettingsReader_FWD_DEFINED__
#define __IVsSettingsReader_FWD_DEFINED__
typedef interface IVsSettingsReader IVsSettingsReader;
#endif 	/* __IVsSettingsReader_FWD_DEFINED__ */


#ifndef __IVsSettingsWriter_FWD_DEFINED__
#define __IVsSettingsWriter_FWD_DEFINED__
typedef interface IVsSettingsWriter IVsSettingsWriter;
#endif 	/* __IVsSettingsWriter_FWD_DEFINED__ */


#ifndef __IVsUserSettings_FWD_DEFINED__
#define __IVsUserSettings_FWD_DEFINED__
typedef interface IVsUserSettings IVsUserSettings;
#endif 	/* __IVsUserSettings_FWD_DEFINED__ */


#ifndef __IVsUserSettingsQuery_FWD_DEFINED__
#define __IVsUserSettingsQuery_FWD_DEFINED__
typedef interface IVsUserSettingsQuery IVsUserSettingsQuery;
#endif 	/* __IVsUserSettingsQuery_FWD_DEFINED__ */


#ifndef __IVsProfileSettingsFileInfo_FWD_DEFINED__
#define __IVsProfileSettingsFileInfo_FWD_DEFINED__
typedef interface IVsProfileSettingsFileInfo IVsProfileSettingsFileInfo;
#endif 	/* __IVsProfileSettingsFileInfo_FWD_DEFINED__ */


#ifndef __IVsProfileSettingsFileCollection_FWD_DEFINED__
#define __IVsProfileSettingsFileCollection_FWD_DEFINED__
typedef interface IVsProfileSettingsFileCollection IVsProfileSettingsFileCollection;
#endif 	/* __IVsProfileSettingsFileCollection_FWD_DEFINED__ */


#ifndef __IVsProfileSettingsTree_FWD_DEFINED__
#define __IVsProfileSettingsTree_FWD_DEFINED__
typedef interface IVsProfileSettingsTree IVsProfileSettingsTree;
#endif 	/* __IVsProfileSettingsTree_FWD_DEFINED__ */


#ifndef __IVsProfileDataManager_FWD_DEFINED__
#define __IVsProfileDataManager_FWD_DEFINED__
typedef interface IVsProfileDataManager IVsProfileDataManager;
#endif 	/* __IVsProfileDataManager_FWD_DEFINED__ */


#ifndef __IVsProfileDelayedActionManager_FWD_DEFINED__
#define __IVsProfileDelayedActionManager_FWD_DEFINED__
typedef interface IVsProfileDelayedActionManager IVsProfileDelayedActionManager;
#endif 	/* __IVsProfileDelayedActionManager_FWD_DEFINED__ */


#ifndef __IVsDeferredSaveProject_FWD_DEFINED__
#define __IVsDeferredSaveProject_FWD_DEFINED__
typedef interface IVsDeferredSaveProject IVsDeferredSaveProject;
#endif 	/* __IVsDeferredSaveProject_FWD_DEFINED__ */


#ifndef __IVsBrowseProjectLocation_FWD_DEFINED__
#define __IVsBrowseProjectLocation_FWD_DEFINED__
typedef interface IVsBrowseProjectLocation IVsBrowseProjectLocation;
#endif 	/* __IVsBrowseProjectLocation_FWD_DEFINED__ */


#ifndef __IVsSolution3_FWD_DEFINED__
#define __IVsSolution3_FWD_DEFINED__
typedef interface IVsSolution3 IVsSolution3;
#endif 	/* __IVsSolution3_FWD_DEFINED__ */


#ifndef __IVsConfigurationManagerDlg_FWD_DEFINED__
#define __IVsConfigurationManagerDlg_FWD_DEFINED__
typedef interface IVsConfigurationManagerDlg IVsConfigurationManagerDlg;
#endif 	/* __IVsConfigurationManagerDlg_FWD_DEFINED__ */


#ifndef __IVsUpdateSolutionEvents3_FWD_DEFINED__
#define __IVsUpdateSolutionEvents3_FWD_DEFINED__
typedef interface IVsUpdateSolutionEvents3 IVsUpdateSolutionEvents3;
#endif 	/* __IVsUpdateSolutionEvents3_FWD_DEFINED__ */


#ifndef __IVsSolutionBuildManager3_FWD_DEFINED__
#define __IVsSolutionBuildManager3_FWD_DEFINED__
typedef interface IVsSolutionBuildManager3 IVsSolutionBuildManager3;
#endif 	/* __IVsSolutionBuildManager3_FWD_DEFINED__ */


#ifndef __IVsSingleFileGeneratorFactory_FWD_DEFINED__
#define __IVsSingleFileGeneratorFactory_FWD_DEFINED__
typedef interface IVsSingleFileGeneratorFactory IVsSingleFileGeneratorFactory;
#endif 	/* __IVsSingleFileGeneratorFactory_FWD_DEFINED__ */


#ifndef __IVsCommunitySearch_FWD_DEFINED__
#define __IVsCommunitySearch_FWD_DEFINED__
typedef interface IVsCommunitySearch IVsCommunitySearch;
#endif 	/* __IVsCommunitySearch_FWD_DEFINED__ */


#ifndef __IVsCommunityProviderInfo_FWD_DEFINED__
#define __IVsCommunityProviderInfo_FWD_DEFINED__
typedef interface IVsCommunityProviderInfo IVsCommunityProviderInfo;
#endif 	/* __IVsCommunityProviderInfo_FWD_DEFINED__ */


#ifndef __IVsCommunityProviders_FWD_DEFINED__
#define __IVsCommunityProviders_FWD_DEFINED__
typedef interface IVsCommunityProviders IVsCommunityProviders;
#endif 	/* __IVsCommunityProviders_FWD_DEFINED__ */


#ifndef __IVsMenuEditorTransactionEvents_FWD_DEFINED__
#define __IVsMenuEditorTransactionEvents_FWD_DEFINED__
typedef interface IVsMenuEditorTransactionEvents IVsMenuEditorTransactionEvents;
#endif 	/* __IVsMenuEditorTransactionEvents_FWD_DEFINED__ */


#ifndef __IVsThreadedWaitDialog_FWD_DEFINED__
#define __IVsThreadedWaitDialog_FWD_DEFINED__
typedef interface IVsThreadedWaitDialog IVsThreadedWaitDialog;
#endif 	/* __IVsThreadedWaitDialog_FWD_DEFINED__ */


#ifndef __IVsProfilesManagerUI_FWD_DEFINED__
#define __IVsProfilesManagerUI_FWD_DEFINED__
typedef interface IVsProfilesManagerUI IVsProfilesManagerUI;
#endif 	/* __IVsProfilesManagerUI_FWD_DEFINED__ */


#ifndef __IVsXMLMemberData3_FWD_DEFINED__
#define __IVsXMLMemberData3_FWD_DEFINED__
typedef interface IVsXMLMemberData3 IVsXMLMemberData3;
#endif 	/* __IVsXMLMemberData3_FWD_DEFINED__ */


#ifndef __IVsNavInfoNode_FWD_DEFINED__
#define __IVsNavInfoNode_FWD_DEFINED__
typedef interface IVsNavInfoNode IVsNavInfoNode;
#endif 	/* __IVsNavInfoNode_FWD_DEFINED__ */


#ifndef __IVsEnumNavInfoNodes_FWD_DEFINED__
#define __IVsEnumNavInfoNodes_FWD_DEFINED__
typedef interface IVsEnumNavInfoNodes IVsEnumNavInfoNodes;
#endif 	/* __IVsEnumNavInfoNodes_FWD_DEFINED__ */


#ifndef __IVsNavInfo_FWD_DEFINED__
#define __IVsNavInfo_FWD_DEFINED__
typedef interface IVsNavInfo IVsNavInfo;
#endif 	/* __IVsNavInfo_FWD_DEFINED__ */


#ifndef __IVsObjectBrowserDescription3_FWD_DEFINED__
#define __IVsObjectBrowserDescription3_FWD_DEFINED__
typedef interface IVsObjectBrowserDescription3 IVsObjectBrowserDescription3;
#endif 	/* __IVsObjectBrowserDescription3_FWD_DEFINED__ */


#ifndef __IVsObjectList2_FWD_DEFINED__
#define __IVsObjectList2_FWD_DEFINED__
typedef interface IVsObjectList2 IVsObjectList2;
#endif 	/* __IVsObjectList2_FWD_DEFINED__ */


#ifndef __IVsBrowseContainersList_FWD_DEFINED__
#define __IVsBrowseContainersList_FWD_DEFINED__
typedef interface IVsBrowseContainersList IVsBrowseContainersList;
#endif 	/* __IVsBrowseContainersList_FWD_DEFINED__ */


#ifndef __IVsLibrary2_FWD_DEFINED__
#define __IVsLibrary2_FWD_DEFINED__
typedef interface IVsLibrary2 IVsLibrary2;
#endif 	/* __IVsLibrary2_FWD_DEFINED__ */


#ifndef __IVsLibrary2Ex_FWD_DEFINED__
#define __IVsLibrary2Ex_FWD_DEFINED__
typedef interface IVsLibrary2Ex IVsLibrary2Ex;
#endif 	/* __IVsLibrary2Ex_FWD_DEFINED__ */


#ifndef __IVsEnumLibraries2_FWD_DEFINED__
#define __IVsEnumLibraries2_FWD_DEFINED__
typedef interface IVsEnumLibraries2 IVsEnumLibraries2;
#endif 	/* __IVsEnumLibraries2_FWD_DEFINED__ */


#ifndef __IVsObjectManager2_FWD_DEFINED__
#define __IVsObjectManager2_FWD_DEFINED__
typedef interface IVsObjectManager2 IVsObjectManager2;
#endif 	/* __IVsObjectManager2_FWD_DEFINED__ */


#ifndef __IVsSelectedSymbol_FWD_DEFINED__
#define __IVsSelectedSymbol_FWD_DEFINED__
typedef interface IVsSelectedSymbol IVsSelectedSymbol;
#endif 	/* __IVsSelectedSymbol_FWD_DEFINED__ */


#ifndef __IVsEnumSelectedSymbols_FWD_DEFINED__
#define __IVsEnumSelectedSymbols_FWD_DEFINED__
typedef interface IVsEnumSelectedSymbols IVsEnumSelectedSymbols;
#endif 	/* __IVsEnumSelectedSymbols_FWD_DEFINED__ */


#ifndef __IVsSelectedSymbols_FWD_DEFINED__
#define __IVsSelectedSymbols_FWD_DEFINED__
typedef interface IVsSelectedSymbols IVsSelectedSymbols;
#endif 	/* __IVsSelectedSymbols_FWD_DEFINED__ */


#ifndef __IVsNavigationTool_FWD_DEFINED__
#define __IVsNavigationTool_FWD_DEFINED__
typedef interface IVsNavigationTool IVsNavigationTool;
#endif 	/* __IVsNavigationTool_FWD_DEFINED__ */


#ifndef __IVsFindSymbol_FWD_DEFINED__
#define __IVsFindSymbol_FWD_DEFINED__
typedef interface IVsFindSymbol IVsFindSymbol;
#endif 	/* __IVsFindSymbol_FWD_DEFINED__ */


#ifndef __IVsFindSymbolEvents_FWD_DEFINED__
#define __IVsFindSymbolEvents_FWD_DEFINED__
typedef interface IVsFindSymbolEvents IVsFindSymbolEvents;
#endif 	/* __IVsFindSymbolEvents_FWD_DEFINED__ */


#ifndef __IVsCallBrowser_FWD_DEFINED__
#define __IVsCallBrowser_FWD_DEFINED__
typedef interface IVsCallBrowser IVsCallBrowser;
#endif 	/* __IVsCallBrowser_FWD_DEFINED__ */


#ifndef __IVsComponentSelectorDlg2_FWD_DEFINED__
#define __IVsComponentSelectorDlg2_FWD_DEFINED__
typedef interface IVsComponentSelectorDlg2 IVsComponentSelectorDlg2;
#endif 	/* __IVsComponentSelectorDlg2_FWD_DEFINED__ */


#ifndef __IVsBuildMacroInfo_FWD_DEFINED__
#define __IVsBuildMacroInfo_FWD_DEFINED__
typedef interface IVsBuildMacroInfo IVsBuildMacroInfo;
#endif 	/* __IVsBuildMacroInfo_FWD_DEFINED__ */


#ifndef __IVsPreviewChangesList_FWD_DEFINED__
#define __IVsPreviewChangesList_FWD_DEFINED__
typedef interface IVsPreviewChangesList IVsPreviewChangesList;
#endif 	/* __IVsPreviewChangesList_FWD_DEFINED__ */


#ifndef __IVsPreviewChangesEngine_FWD_DEFINED__
#define __IVsPreviewChangesEngine_FWD_DEFINED__
typedef interface IVsPreviewChangesEngine IVsPreviewChangesEngine;
#endif 	/* __IVsPreviewChangesEngine_FWD_DEFINED__ */


#ifndef __IVsPreviewChangesService_FWD_DEFINED__
#define __IVsPreviewChangesService_FWD_DEFINED__
typedef interface IVsPreviewChangesService IVsPreviewChangesService;
#endif 	/* __IVsPreviewChangesService_FWD_DEFINED__ */


#ifndef __IVsRefactoringEngine_FWD_DEFINED__
#define __IVsRefactoringEngine_FWD_DEFINED__
typedef interface IVsRefactoringEngine IVsRefactoringEngine;
#endif 	/* __IVsRefactoringEngine_FWD_DEFINED__ */


#ifndef __IVsPreviewChangesPane_FWD_DEFINED__
#define __IVsPreviewChangesPane_FWD_DEFINED__
typedef interface IVsPreviewChangesPane IVsPreviewChangesPane;
#endif 	/* __IVsPreviewChangesPane_FWD_DEFINED__ */


#ifndef __IVsCodeDefViewContext_FWD_DEFINED__
#define __IVsCodeDefViewContext_FWD_DEFINED__
typedef interface IVsCodeDefViewContext IVsCodeDefViewContext;
#endif 	/* __IVsCodeDefViewContext_FWD_DEFINED__ */


#ifndef __IVsCodeDefView_FWD_DEFINED__
#define __IVsCodeDefView_FWD_DEFINED__
typedef interface IVsCodeDefView IVsCodeDefView;
#endif 	/* __IVsCodeDefView_FWD_DEFINED__ */


#ifndef __IVsRunningDocTableEvents4_FWD_DEFINED__
#define __IVsRunningDocTableEvents4_FWD_DEFINED__
typedef interface IVsRunningDocTableEvents4 IVsRunningDocTableEvents4;
#endif 	/* __IVsRunningDocTableEvents4_FWD_DEFINED__ */


#ifndef __IVsToolboxDataProviderRegistry_FWD_DEFINED__
#define __IVsToolboxDataProviderRegistry_FWD_DEFINED__
typedef interface IVsToolboxDataProviderRegistry IVsToolboxDataProviderRegistry;
#endif 	/* __IVsToolboxDataProviderRegistry_FWD_DEFINED__ */


#ifndef __IVsFontAndColorCacheManager_FWD_DEFINED__
#define __IVsFontAndColorCacheManager_FWD_DEFINED__
typedef interface IVsFontAndColorCacheManager IVsFontAndColorCacheManager;
#endif 	/* __IVsFontAndColorCacheManager_FWD_DEFINED__ */


#ifndef __IVsUpgradeLogger_FWD_DEFINED__
#define __IVsUpgradeLogger_FWD_DEFINED__
typedef interface IVsUpgradeLogger IVsUpgradeLogger;
#endif 	/* __IVsUpgradeLogger_FWD_DEFINED__ */


#ifndef __IVsFileUpgrade_FWD_DEFINED__
#define __IVsFileUpgrade_FWD_DEFINED__
typedef interface IVsFileUpgrade IVsFileUpgrade;
#endif 	/* __IVsFileUpgrade_FWD_DEFINED__ */


#ifndef __IVsProjectUpgradeViaFactory_FWD_DEFINED__
#define __IVsProjectUpgradeViaFactory_FWD_DEFINED__
typedef interface IVsProjectUpgradeViaFactory IVsProjectUpgradeViaFactory;
#endif 	/* __IVsProjectUpgradeViaFactory_FWD_DEFINED__ */


#ifndef __IVsActivityLog_FWD_DEFINED__
#define __IVsActivityLog_FWD_DEFINED__
typedef interface IVsActivityLog IVsActivityLog;
#endif 	/* __IVsActivityLog_FWD_DEFINED__ */


#ifndef __IVsPersistDocData3_FWD_DEFINED__
#define __IVsPersistDocData3_FWD_DEFINED__
typedef interface IVsPersistDocData3 IVsPersistDocData3;
#endif 	/* __IVsPersistDocData3_FWD_DEFINED__ */


#ifndef __IVsWindowFrame2_FWD_DEFINED__
#define __IVsWindowFrame2_FWD_DEFINED__
typedef interface IVsWindowFrame2 IVsWindowFrame2;
#endif 	/* __IVsWindowFrame2_FWD_DEFINED__ */


#ifndef __IVsPropertyPage2_FWD_DEFINED__
#define __IVsPropertyPage2_FWD_DEFINED__
typedef interface IVsPropertyPage2 IVsPropertyPage2;
#endif 	/* __IVsPropertyPage2_FWD_DEFINED__ */


#ifndef __IVsWindowFrameNotify3_FWD_DEFINED__
#define __IVsWindowFrameNotify3_FWD_DEFINED__
typedef interface IVsWindowFrameNotify3 IVsWindowFrameNotify3;
#endif 	/* __IVsWindowFrameNotify3_FWD_DEFINED__ */


#ifndef __IVsContextualIntellisenseFilter_FWD_DEFINED__
#define __IVsContextualIntellisenseFilter_FWD_DEFINED__
typedef interface IVsContextualIntellisenseFilter IVsContextualIntellisenseFilter;
#endif 	/* __IVsContextualIntellisenseFilter_FWD_DEFINED__ */


#ifndef __IVsContextualIntellisenseFilterProvider_FWD_DEFINED__
#define __IVsContextualIntellisenseFilterProvider_FWD_DEFINED__
typedef interface IVsContextualIntellisenseFilterProvider IVsContextualIntellisenseFilterProvider;
#endif 	/* __IVsContextualIntellisenseFilterProvider_FWD_DEFINED__ */


#ifndef __IVsToolboxActiveUserHook_FWD_DEFINED__
#define __IVsToolboxActiveUserHook_FWD_DEFINED__
typedef interface IVsToolboxActiveUserHook IVsToolboxActiveUserHook;
#endif 	/* __IVsToolboxActiveUserHook_FWD_DEFINED__ */


#ifndef __IVsPathVariableResolver_FWD_DEFINED__
#define __IVsPathVariableResolver_FWD_DEFINED__
typedef interface IVsPathVariableResolver IVsPathVariableResolver;
#endif 	/* __IVsPathVariableResolver_FWD_DEFINED__ */


#ifndef __IVsProjectFactory2_FWD_DEFINED__
#define __IVsProjectFactory2_FWD_DEFINED__
typedef interface IVsProjectFactory2 IVsProjectFactory2;
#endif 	/* __IVsProjectFactory2_FWD_DEFINED__ */


#ifndef __IVsAsynchOpenFromSccProjectEvents_FWD_DEFINED__
#define __IVsAsynchOpenFromSccProjectEvents_FWD_DEFINED__
typedef interface IVsAsynchOpenFromSccProjectEvents IVsAsynchOpenFromSccProjectEvents;
#endif 	/* __IVsAsynchOpenFromSccProjectEvents_FWD_DEFINED__ */


#ifndef __IVsAsynchOpenFromScc_FWD_DEFINED__
#define __IVsAsynchOpenFromScc_FWD_DEFINED__
typedef interface IVsAsynchOpenFromScc IVsAsynchOpenFromScc;
#endif 	/* __IVsAsynchOpenFromScc_FWD_DEFINED__ */


#ifndef __IVsHierarchyDeleteHandler2_FWD_DEFINED__
#define __IVsHierarchyDeleteHandler2_FWD_DEFINED__
typedef interface IVsHierarchyDeleteHandler2 IVsHierarchyDeleteHandler2;
#endif 	/* __IVsHierarchyDeleteHandler2_FWD_DEFINED__ */


#ifndef __IVsToolbox3_FWD_DEFINED__
#define __IVsToolbox3_FWD_DEFINED__
typedef interface IVsToolbox3 IVsToolbox3;
#endif 	/* __IVsToolbox3_FWD_DEFINED__ */


#ifndef __IVsToolboxDataProvider2_FWD_DEFINED__
#define __IVsToolboxDataProvider2_FWD_DEFINED__
typedef interface IVsToolboxDataProvider2 IVsToolboxDataProvider2;
#endif 	/* __IVsToolboxDataProvider2_FWD_DEFINED__ */


#ifndef __IVsResourceManager_FWD_DEFINED__
#define __IVsResourceManager_FWD_DEFINED__
typedef interface IVsResourceManager IVsResourceManager;
#endif 	/* __IVsResourceManager_FWD_DEFINED__ */


#ifndef __IVsAddNewWebProjectItemDlg_FWD_DEFINED__
#define __IVsAddNewWebProjectItemDlg_FWD_DEFINED__
typedef interface IVsAddNewWebProjectItemDlg IVsAddNewWebProjectItemDlg;
#endif 	/* __IVsAddNewWebProjectItemDlg_FWD_DEFINED__ */


#ifndef __IVsWebProject_FWD_DEFINED__
#define __IVsWebProject_FWD_DEFINED__
typedef interface IVsWebProject IVsWebProject;
#endif 	/* __IVsWebProject_FWD_DEFINED__ */


#ifndef __IVsUIHierarchyWindow2_FWD_DEFINED__
#define __IVsUIHierarchyWindow2_FWD_DEFINED__
typedef interface IVsUIHierarchyWindow2 IVsUIHierarchyWindow2;
#endif 	/* __IVsUIHierarchyWindow2_FWD_DEFINED__ */


#ifndef __IVsSupportYukonDebugging_FWD_DEFINED__
#define __IVsSupportYukonDebugging_FWD_DEFINED__
typedef interface IVsSupportYukonDebugging IVsSupportYukonDebugging;
#endif 	/* __IVsSupportYukonDebugging_FWD_DEFINED__ */


#ifndef __IVsTaskList2_FWD_DEFINED__
#define __IVsTaskList2_FWD_DEFINED__
typedef interface IVsTaskList2 IVsTaskList2;
#endif 	/* __IVsTaskList2_FWD_DEFINED__ */


#ifndef __IVsTaskProvider3_FWD_DEFINED__
#define __IVsTaskProvider3_FWD_DEFINED__
typedef interface IVsTaskProvider3 IVsTaskProvider3;
#endif 	/* __IVsTaskProvider3_FWD_DEFINED__ */


#ifndef __IVsTaskItem3_FWD_DEFINED__
#define __IVsTaskItem3_FWD_DEFINED__
typedef interface IVsTaskItem3 IVsTaskItem3;
#endif 	/* __IVsTaskItem3_FWD_DEFINED__ */


#ifndef __IVsErrorList_FWD_DEFINED__
#define __IVsErrorList_FWD_DEFINED__
typedef interface IVsErrorList IVsErrorList;
#endif 	/* __IVsErrorList_FWD_DEFINED__ */


#ifndef __IVsErrorItem_FWD_DEFINED__
#define __IVsErrorItem_FWD_DEFINED__
typedef interface IVsErrorItem IVsErrorItem;
#endif 	/* __IVsErrorItem_FWD_DEFINED__ */


#ifndef __IVsWindowPaneCommitFilter_FWD_DEFINED__
#define __IVsWindowPaneCommitFilter_FWD_DEFINED__
typedef interface IVsWindowPaneCommitFilter IVsWindowPaneCommitFilter;
#endif 	/* __IVsWindowPaneCommitFilter_FWD_DEFINED__ */


#ifndef __IPreferPropertyPagesWithTreeControl_FWD_DEFINED__
#define __IPreferPropertyPagesWithTreeControl_FWD_DEFINED__
typedef interface IPreferPropertyPagesWithTreeControl IPreferPropertyPagesWithTreeControl;
#endif 	/* __IPreferPropertyPagesWithTreeControl_FWD_DEFINED__ */


#ifndef __IVsDeployDependency2_FWD_DEFINED__
#define __IVsDeployDependency2_FWD_DEFINED__
typedef interface IVsDeployDependency2 IVsDeployDependency2;
#endif 	/* __IVsDeployDependency2_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "vsshell.h"
#include "vsshell2.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

/* interface __MIDL_itf_vsshell80_0000 */
/* [local] */ 

#pragma once


extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0000_v0_0_s_ifspec;

#ifndef __IVsProjectDebugTargetProvider_INTERFACE_DEFINED__
#define __IVsProjectDebugTargetProvider_INTERFACE_DEFINED__

/* interface IVsProjectDebugTargetProvider */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsProjectDebugTargetProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4C5F0CEB-5AC9-4ea4-85E2-72E088EA75A8")
    IVsProjectDebugTargetProvider : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SupplyDebugTarget( 
            /* [out] */ BSTR *pbstrTarget,
            /* [out] */ BSTR *pbstrCommandLine) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsProjectDebugTargetProviderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsProjectDebugTargetProvider * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsProjectDebugTargetProvider * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsProjectDebugTargetProvider * This);
        
        HRESULT ( STDMETHODCALLTYPE *SupplyDebugTarget )( 
            IVsProjectDebugTargetProvider * This,
            /* [out] */ BSTR *pbstrTarget,
            /* [out] */ BSTR *pbstrCommandLine);
        
        END_INTERFACE
    } IVsProjectDebugTargetProviderVtbl;

    interface IVsProjectDebugTargetProvider
    {
        CONST_VTBL struct IVsProjectDebugTargetProviderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsProjectDebugTargetProvider_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsProjectDebugTargetProvider_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsProjectDebugTargetProvider_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsProjectDebugTargetProvider_SupplyDebugTarget(This,pbstrTarget,pbstrCommandLine)	\
    (This)->lpVtbl -> SupplyDebugTarget(This,pbstrTarget,pbstrCommandLine)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsProjectDebugTargetProvider_SupplyDebugTarget_Proxy( 
    IVsProjectDebugTargetProvider * This,
    /* [out] */ BSTR *pbstrTarget,
    /* [out] */ BSTR *pbstrCommandLine);


void __RPC_STUB IVsProjectDebugTargetProvider_SupplyDebugTarget_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsProjectDebugTargetProvider_INTERFACE_DEFINED__ */


#ifndef __IVsRegisterProjectDebugTargetProvider_INTERFACE_DEFINED__
#define __IVsRegisterProjectDebugTargetProvider_INTERFACE_DEFINED__

/* interface IVsRegisterProjectDebugTargetProvider */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsRegisterProjectDebugTargetProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4C5F0CEA-5AC9-4ea4-85E2-72E088EA75A8")
    IVsRegisterProjectDebugTargetProvider : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AddDebugTargetProvider( 
            /* [in] */ IVsProjectDebugTargetProvider *pNewDbgTrgtProvider,
            /* [out] */ IVsProjectDebugTargetProvider **ppNextDbgTrgtProvider) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveDebugTargetProvider( 
            /* [in] */ IVsProjectDebugTargetProvider *pDbgTrgtProvider) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsRegisterProjectDebugTargetProviderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsRegisterProjectDebugTargetProvider * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsRegisterProjectDebugTargetProvider * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsRegisterProjectDebugTargetProvider * This);
        
        HRESULT ( STDMETHODCALLTYPE *AddDebugTargetProvider )( 
            IVsRegisterProjectDebugTargetProvider * This,
            /* [in] */ IVsProjectDebugTargetProvider *pNewDbgTrgtProvider,
            /* [out] */ IVsProjectDebugTargetProvider **ppNextDbgTrgtProvider);
        
        HRESULT ( STDMETHODCALLTYPE *RemoveDebugTargetProvider )( 
            IVsRegisterProjectDebugTargetProvider * This,
            /* [in] */ IVsProjectDebugTargetProvider *pDbgTrgtProvider);
        
        END_INTERFACE
    } IVsRegisterProjectDebugTargetProviderVtbl;

    interface IVsRegisterProjectDebugTargetProvider
    {
        CONST_VTBL struct IVsRegisterProjectDebugTargetProviderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsRegisterProjectDebugTargetProvider_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsRegisterProjectDebugTargetProvider_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsRegisterProjectDebugTargetProvider_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsRegisterProjectDebugTargetProvider_AddDebugTargetProvider(This,pNewDbgTrgtProvider,ppNextDbgTrgtProvider)	\
    (This)->lpVtbl -> AddDebugTargetProvider(This,pNewDbgTrgtProvider,ppNextDbgTrgtProvider)

#define IVsRegisterProjectDebugTargetProvider_RemoveDebugTargetProvider(This,pDbgTrgtProvider)	\
    (This)->lpVtbl -> RemoveDebugTargetProvider(This,pDbgTrgtProvider)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsRegisterProjectDebugTargetProvider_AddDebugTargetProvider_Proxy( 
    IVsRegisterProjectDebugTargetProvider * This,
    /* [in] */ IVsProjectDebugTargetProvider *pNewDbgTrgtProvider,
    /* [out] */ IVsProjectDebugTargetProvider **ppNextDbgTrgtProvider);


void __RPC_STUB IVsRegisterProjectDebugTargetProvider_AddDebugTargetProvider_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsRegisterProjectDebugTargetProvider_RemoveDebugTargetProvider_Proxy( 
    IVsRegisterProjectDebugTargetProvider * This,
    /* [in] */ IVsProjectDebugTargetProvider *pDbgTrgtProvider);


void __RPC_STUB IVsRegisterProjectDebugTargetProvider_RemoveDebugTargetProvider_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsRegisterProjectDebugTargetProvider_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshell80_0666 */
/* [local] */ 

#define SID_SVsRegisterDebugTargetProvider IID_IVsRegisterProjectDebugTargetProvider
extern const __declspec(selectany) GUID GUID_BookmarkWindow =     { 0xa0c5197d, 0xac7, 0x4b63, { 0x97, 0xcd, 0x88, 0x72, 0xa7, 0x89, 0xd2, 0x33 } };


extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0666_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0666_v0_0_s_ifspec;

#ifndef __IVsBrowseObject_INTERFACE_DEFINED__
#define __IVsBrowseObject_INTERFACE_DEFINED__

/* interface IVsBrowseObject */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsBrowseObject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("bc5b644e-7fd7-4a75-98cc-0c2c98aa96f6")
    IVsBrowseObject : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetProjectItem( 
            /* [out] */ IVsHierarchy **pHier,
            /* [out] */ VSITEMID *pItemid) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsBrowseObjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsBrowseObject * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsBrowseObject * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsBrowseObject * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetProjectItem )( 
            IVsBrowseObject * This,
            /* [out] */ IVsHierarchy **pHier,
            /* [out] */ VSITEMID *pItemid);
        
        END_INTERFACE
    } IVsBrowseObjectVtbl;

    interface IVsBrowseObject
    {
        CONST_VTBL struct IVsBrowseObjectVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsBrowseObject_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsBrowseObject_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsBrowseObject_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsBrowseObject_GetProjectItem(This,pHier,pItemid)	\
    (This)->lpVtbl -> GetProjectItem(This,pHier,pItemid)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsBrowseObject_GetProjectItem_Proxy( 
    IVsBrowseObject * This,
    /* [out] */ IVsHierarchy **pHier,
    /* [out] */ VSITEMID *pItemid);


void __RPC_STUB IVsBrowseObject_GetProjectItem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsBrowseObject_INTERFACE_DEFINED__ */


#ifndef __IVsCfgBrowseObject_INTERFACE_DEFINED__
#define __IVsCfgBrowseObject_INTERFACE_DEFINED__

/* interface IVsCfgBrowseObject */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsCfgBrowseObject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a630cff5-eb22-40b7-9464-5f8d4b98b1cb")
    IVsCfgBrowseObject : public IVsBrowseObject
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetCfg( 
            /* [out] */ IVsCfg **ppCfg) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsCfgBrowseObjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsCfgBrowseObject * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsCfgBrowseObject * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsCfgBrowseObject * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetProjectItem )( 
            IVsCfgBrowseObject * This,
            /* [out] */ IVsHierarchy **pHier,
            /* [out] */ VSITEMID *pItemid);
        
        HRESULT ( STDMETHODCALLTYPE *GetCfg )( 
            IVsCfgBrowseObject * This,
            /* [out] */ IVsCfg **ppCfg);
        
        END_INTERFACE
    } IVsCfgBrowseObjectVtbl;

    interface IVsCfgBrowseObject
    {
        CONST_VTBL struct IVsCfgBrowseObjectVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsCfgBrowseObject_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsCfgBrowseObject_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsCfgBrowseObject_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsCfgBrowseObject_GetProjectItem(This,pHier,pItemid)	\
    (This)->lpVtbl -> GetProjectItem(This,pHier,pItemid)


#define IVsCfgBrowseObject_GetCfg(This,ppCfg)	\
    (This)->lpVtbl -> GetCfg(This,ppCfg)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsCfgBrowseObject_GetCfg_Proxy( 
    IVsCfgBrowseObject * This,
    /* [out] */ IVsCfg **ppCfg);


void __RPC_STUB IVsCfgBrowseObject_GetCfg_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsCfgBrowseObject_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshell80_0668 */
/* [local] */ 

extern const __declspec(selectany) CLSID CLSID_SolutionFolderProject = { 0x2150e333, 0x8fdc, 0x42a3, { 0x94, 0x74, 0x1a, 0x39, 0x56, 0xd4, 0x6d, 0xe8 } };

enum __VSHPROPID2
    {	VSHPROPID_PropertyPagesCLSIDList	= -2065,
	VSHPROPID_CfgPropertyPagesCLSIDList	= -2066,
	VSHPROID_ExtObjectCATID	= -2067,
	VSHPROPID_BrowseObjectCATID	= -2068,
	VSHPROPID_CfgBrowseObjectCATID	= -2069,
	VSHPROPID_AddItemTemplatesGuid	= -2070,
	VSHPROPID_ChildrenEnumerated	= -2071,
	VSHPROPID_StatusBarClientText	= -2072,
	VSHPROPID_DebuggeeProcessId	= -2073,
	VSHPROPID_IsLinkFile	= -2074,
	VSHPROPID_KeepAliveDocument	= -2075,
	VSHPROPID_SupportsAppDesigner	= -2076,
	VSHPROPID_IntellisenseUnknown	= -2077,
	VSHPROPID_IsUpgradeRequired	= -2078,
	VSHPROPID_DesignerHiddenCodeGeneration	= -2079,
	VSHPROPID_SuppressOutOfDateMessageOnBuild	= -2080,
	VSHPROPID_Container	= -2081,
	VSHPROPID_UseInnerHierarchyIconList	= -2082,
	VSHPROPID_FIRST2	= -2082
    } ;
typedef /* [public] */ DWORD VSHPROPID2;


enum __VSDESIGNER_HIDDENCODEGENERATION
    {	VSDHCG_Declarations	= 1,
	VSDHCG_InitMethods	= 2,
	VSDHCG_EventMethods	= 4
    } ;

enum __VSPROPID2
    {	VSPROPID_IsSolutionNodeHidden	= -8017,
	VSPROPID_DeferredSaveSolution	= -8018,
	VSPROPID_SimplifiedConfigurations	= -8019,
	VSPROPID_FIRST2	= -8018
    } ;
typedef /* [public] */ DWORD VSPROPID2;


enum __VSCFGPROPID2
    {	VSCFGPROPID_HideConfigurations	= -16009,
	VSCFGPROPID_FIRST2	= -16009
    } ;
typedef LONG VSCFGPROPID2;


enum __VSCREATEPROJFLAGS2
    {	CPF_DEFERREDSAVE	= 0x80,
	CPF_OPEN_ASYNCHRONOUSLY	= 0x100,
	CPF_OPEN_STANDALONE	= 0x200
    } ;
typedef DWORD VSCREATEPROJFLAGS2;


enum __VSCREATESOLUTIONFLAGS2
    {	CSF_HIDESOLUTIONNODEALWAYS	= 0x10,
	CSF_DEFERREDSAVESOLUTION	= 0x20
    } ;
typedef /* [public] */ DWORD VSCREATESOLUTIONFLAGS2;


enum __VSSLNOPENOPTIONS2
    {	SLNOPENOPT_LoadingAsync	= 0x8
    } ;
typedef DWORD VSSLNOPENOPTIONS2;


enum __VSADDITEMFLAGS2
    {	VSADDITEM_NoUserTemplateFeatures	= 0x1000,
	VSADDITEM_ShowOpenButtonDropDown	= 0x40000
    } ;
typedef DWORD VSADDITEMFLAGS2;


enum __VSCREATEEDITORFLAGS2
    {	CEF_OPENSPECIFIC	= 0x10
    } ;
typedef DWORD VSCREATEEDITORFLAGS2;



extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0668_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0668_v0_0_s_ifspec;

#ifndef __IVsSolutionEvents4_INTERFACE_DEFINED__
#define __IVsSolutionEvents4_INTERFACE_DEFINED__

/* interface IVsSolutionEvents4 */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsSolutionEvents4;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("23EC4D20-54A9-4365-82C8-ABDFBA686ECF")
    IVsSolutionEvents4 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnAfterRenameProject( 
            /* [in] */ IVsHierarchy *pHierarchy) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnAfterChangeProjectParent( 
            /* [in] */ IVsHierarchy *pHierarchy) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnAfterAsynchOpenProject( 
            /* [in] */ IVsHierarchy *pHierarchy,
            /* [in] */ BOOL fAdded) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsSolutionEvents4Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsSolutionEvents4 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsSolutionEvents4 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsSolutionEvents4 * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnAfterRenameProject )( 
            IVsSolutionEvents4 * This,
            /* [in] */ IVsHierarchy *pHierarchy);
        
        HRESULT ( STDMETHODCALLTYPE *OnAfterChangeProjectParent )( 
            IVsSolutionEvents4 * This,
            /* [in] */ IVsHierarchy *pHierarchy);
        
        HRESULT ( STDMETHODCALLTYPE *OnAfterAsynchOpenProject )( 
            IVsSolutionEvents4 * This,
            /* [in] */ IVsHierarchy *pHierarchy,
            /* [in] */ BOOL fAdded);
        
        END_INTERFACE
    } IVsSolutionEvents4Vtbl;

    interface IVsSolutionEvents4
    {
        CONST_VTBL struct IVsSolutionEvents4Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsSolutionEvents4_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsSolutionEvents4_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsSolutionEvents4_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsSolutionEvents4_OnAfterRenameProject(This,pHierarchy)	\
    (This)->lpVtbl -> OnAfterRenameProject(This,pHierarchy)

#define IVsSolutionEvents4_OnAfterChangeProjectParent(This,pHierarchy)	\
    (This)->lpVtbl -> OnAfterChangeProjectParent(This,pHierarchy)

#define IVsSolutionEvents4_OnAfterAsynchOpenProject(This,pHierarchy,fAdded)	\
    (This)->lpVtbl -> OnAfterAsynchOpenProject(This,pHierarchy,fAdded)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsSolutionEvents4_OnAfterRenameProject_Proxy( 
    IVsSolutionEvents4 * This,
    /* [in] */ IVsHierarchy *pHierarchy);


void __RPC_STUB IVsSolutionEvents4_OnAfterRenameProject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSolutionEvents4_OnAfterChangeProjectParent_Proxy( 
    IVsSolutionEvents4 * This,
    /* [in] */ IVsHierarchy *pHierarchy);


void __RPC_STUB IVsSolutionEvents4_OnAfterChangeProjectParent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSolutionEvents4_OnAfterAsynchOpenProject_Proxy( 
    IVsSolutionEvents4 * This,
    /* [in] */ IVsHierarchy *pHierarchy,
    /* [in] */ BOOL fAdded);


void __RPC_STUB IVsSolutionEvents4_OnAfterAsynchOpenProject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsSolutionEvents4_INTERFACE_DEFINED__ */


#ifndef __IVsFireSolutionEvents2_INTERFACE_DEFINED__
#define __IVsFireSolutionEvents2_INTERFACE_DEFINED__

/* interface IVsFireSolutionEvents2 */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsFireSolutionEvents2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ED6AAB26-108F-4b4f-A57B-14D20982713D")
    IVsFireSolutionEvents2 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE FireOnAfterRenameProject( 
            /* [in] */ IVsHierarchy *pHierarchy) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FireOnAfterChangeProjectParent( 
            /* [in] */ IVsHierarchy *pHierarchy) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FireOnAfterAsynchOpenProject( 
            /* [in] */ IVsHierarchy *pHierarchy,
            BOOL fAdded) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsFireSolutionEvents2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsFireSolutionEvents2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsFireSolutionEvents2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsFireSolutionEvents2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *FireOnAfterRenameProject )( 
            IVsFireSolutionEvents2 * This,
            /* [in] */ IVsHierarchy *pHierarchy);
        
        HRESULT ( STDMETHODCALLTYPE *FireOnAfterChangeProjectParent )( 
            IVsFireSolutionEvents2 * This,
            /* [in] */ IVsHierarchy *pHierarchy);
        
        HRESULT ( STDMETHODCALLTYPE *FireOnAfterAsynchOpenProject )( 
            IVsFireSolutionEvents2 * This,
            /* [in] */ IVsHierarchy *pHierarchy,
            BOOL fAdded);
        
        END_INTERFACE
    } IVsFireSolutionEvents2Vtbl;

    interface IVsFireSolutionEvents2
    {
        CONST_VTBL struct IVsFireSolutionEvents2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsFireSolutionEvents2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsFireSolutionEvents2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsFireSolutionEvents2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsFireSolutionEvents2_FireOnAfterRenameProject(This,pHierarchy)	\
    (This)->lpVtbl -> FireOnAfterRenameProject(This,pHierarchy)

#define IVsFireSolutionEvents2_FireOnAfterChangeProjectParent(This,pHierarchy)	\
    (This)->lpVtbl -> FireOnAfterChangeProjectParent(This,pHierarchy)

#define IVsFireSolutionEvents2_FireOnAfterAsynchOpenProject(This,pHierarchy,fAdded)	\
    (This)->lpVtbl -> FireOnAfterAsynchOpenProject(This,pHierarchy,fAdded)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsFireSolutionEvents2_FireOnAfterRenameProject_Proxy( 
    IVsFireSolutionEvents2 * This,
    /* [in] */ IVsHierarchy *pHierarchy);


void __RPC_STUB IVsFireSolutionEvents2_FireOnAfterRenameProject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsFireSolutionEvents2_FireOnAfterChangeProjectParent_Proxy( 
    IVsFireSolutionEvents2 * This,
    /* [in] */ IVsHierarchy *pHierarchy);


void __RPC_STUB IVsFireSolutionEvents2_FireOnAfterChangeProjectParent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsFireSolutionEvents2_FireOnAfterAsynchOpenProject_Proxy( 
    IVsFireSolutionEvents2 * This,
    /* [in] */ IVsHierarchy *pHierarchy,
    BOOL fAdded);


void __RPC_STUB IVsFireSolutionEvents2_FireOnAfterAsynchOpenProject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsFireSolutionEvents2_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshell80_0670 */
/* [local] */ 


enum __VSDIRFLAGS2
    {	VSDIRFLAG_RequiresNewFolder	= 0x10,
	VSDIRFLAG_SolutionTemplate	= 0x40,
	VSDIRFLAG_DeferredSaveProject	= 0x80,
	VSDIRFLAG_DontShowNameLocInfo	= 0x100,
	VSDIRFLAG_EnableMasterPage	= 0x200,
	VSDIRFLAG_EnableCodeSeparation	= 0x400,
	VSDIRFLAG_EnableLangDropdown	= 0x800
    } ;
typedef DWORD VSDIRFLAGS2;

typedef 
enum __VSFRAMEMODE2
    {	VSFM_AutoHide	= 4
    } 	VSFRAMEMODE2;


enum __VSFPROPID2
    {	VSFPROPID_OverrideDirtyState	= -4014,
	VSFPROPID_OLEDocObjectDocument	= -4015,
	VSFPROPID_ParentHwnd	= -4016,
	VSFPROPID_ParentFrame	= -4017
    } ;
typedef LONG VSFPROPID2;

extern const __declspec(selectany) GUID GUID_CommunityWindow = { 0x96db1f3b, 0xe7a, 0x4406, { 0xb7, 0x3e, 0xc6, 0xf0, 0xa2, 0xc6, 0x7b, 0x97 } };
extern const __declspec(selectany) GUID GUID_CommunityWindow_BuddyList = { 0xe631cc3f, 0x84f2, 0x446e, { 0xa5, 0xd5, 0x5f, 0x36, 0xe6, 0x42, 0x90, 0x3a } };
extern const __declspec(selectany) GUID GUID_ImmediateWindow =   { 0xecb7191a, 0x597b, 0x41f5, { 0x98, 0x43, 0x03, 0xa4, 0xcf, 0x27, 0x5d, 0xde } };

enum __VSSPROPID2
    {	VSSPROPID_SccProviderChanged	= -9032,
	VSHPROPID_MainWindowSize	= -9033,
	VSHPROPID_MainWindowPos	= -9034,
	VSSPROPID_IsAcademic	= -9035,
	VSSPROPID_IsAppThemed	= -9036,
	VSSPROPID_VisualStudioDir	= -9037,
	VSSPROPID_VsTemplateUserZipProjectFolder	= -9038,
	VSSPROPID_VsTemplateUserZipItemFolder	= -9039,
	VSSPROPID_VisualStudioDirVersioned	= -9040,
	VSSPROPID_InstallRootDir	= -9041,
	VSHPROPID_SolutionExplorerSortingEnabled	= -9042,
	VSSPROPID_FIRST2	= -9042
    } ;
typedef LONG VSSPROPID2;


enum __VSDBGLAUNCHFLAGS2
    {	DBGLAUNCH_MergeEnv	= 0x80,
	DBGLAUNCH_DesignTimeExprEval	= 0x100,
	DBGLAUNCH_StopAtEntryPoint	= 0x200,
	DBGLAUNCH_CannotDebugAlone	= 0x400
    } ;
typedef DWORD VSDBGLAUNCHFLAGS2;


enum _DEBUG_LAUNCH_OPERATION2
    {	DLO_AttachToHostingProcess	= 4,
	DLO_StartDebuggingHostingProcess	= 5
    } ;
typedef DWORD DEBUG_LAUNCH_OPERATION2;


enum __PSFFILEID2
    {	PSFFILEID_WebSettings	= -1002,
	PSFFILEID_AppManifest	= -1003,
	PSFFILEID_AppDesigner	= -1004,
	PSFFILEID_AppSettings	= -1005,
	PSFFILEID_AssemblyResource	= -1006,
	PSFFILEID_AssemblyInfo	= -1007,
	PSFFILEID_FIRST2	= -1007
    } ;
typedef LONG PSFFILEID2;


enum __PSFFLAGS2
    {	PSFF_CheckoutIfExists	= 0x4
    } ;
typedef DWORD PSFFLAGS2;


enum __VSEDT_STYLE
    {	VSEDT_Reserved1	= 0x1
    } ;
typedef DWORD VSEDT_STYLE;



extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0670_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0670_v0_0_s_ifspec;

#ifndef __IVsEnhancedDataTip_INTERFACE_DEFINED__
#define __IVsEnhancedDataTip_INTERFACE_DEFINED__

/* interface IVsEnhancedDataTip */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsEnhancedDataTip;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B8092238-A091-42f1-A945-080B381FBCFC")
    IVsEnhancedDataTip : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Show( 
            /* [in] */ HWND hwndOwner,
            /* [in] */ POINT *pptTopLeft,
            /* [in] */ RECT *pHotRect) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetExpression( 
            /* [in] */ BSTR bstrExpression) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBaseWindowHandle( 
            /* [out] */ HWND *phwnd) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsErrorTip( 
            /* [out] */ BOOL *pbIsError) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsOpen( 
            /* [out] */ BOOL *pbIsOpen) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsEnhancedDataTipVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsEnhancedDataTip * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsEnhancedDataTip * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsEnhancedDataTip * This);
        
        HRESULT ( STDMETHODCALLTYPE *Show )( 
            IVsEnhancedDataTip * This,
            /* [in] */ HWND hwndOwner,
            /* [in] */ POINT *pptTopLeft,
            /* [in] */ RECT *pHotRect);
        
        HRESULT ( STDMETHODCALLTYPE *SetExpression )( 
            IVsEnhancedDataTip * This,
            /* [in] */ BSTR bstrExpression);
        
        HRESULT ( STDMETHODCALLTYPE *GetBaseWindowHandle )( 
            IVsEnhancedDataTip * This,
            /* [out] */ HWND *phwnd);
        
        HRESULT ( STDMETHODCALLTYPE *IsErrorTip )( 
            IVsEnhancedDataTip * This,
            /* [out] */ BOOL *pbIsError);
        
        HRESULT ( STDMETHODCALLTYPE *IsOpen )( 
            IVsEnhancedDataTip * This,
            /* [out] */ BOOL *pbIsOpen);
        
        END_INTERFACE
    } IVsEnhancedDataTipVtbl;

    interface IVsEnhancedDataTip
    {
        CONST_VTBL struct IVsEnhancedDataTipVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsEnhancedDataTip_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsEnhancedDataTip_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsEnhancedDataTip_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsEnhancedDataTip_Show(This,hwndOwner,pptTopLeft,pHotRect)	\
    (This)->lpVtbl -> Show(This,hwndOwner,pptTopLeft,pHotRect)

#define IVsEnhancedDataTip_SetExpression(This,bstrExpression)	\
    (This)->lpVtbl -> SetExpression(This,bstrExpression)

#define IVsEnhancedDataTip_GetBaseWindowHandle(This,phwnd)	\
    (This)->lpVtbl -> GetBaseWindowHandle(This,phwnd)

#define IVsEnhancedDataTip_IsErrorTip(This,pbIsError)	\
    (This)->lpVtbl -> IsErrorTip(This,pbIsError)

#define IVsEnhancedDataTip_IsOpen(This,pbIsOpen)	\
    (This)->lpVtbl -> IsOpen(This,pbIsOpen)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsEnhancedDataTip_Show_Proxy( 
    IVsEnhancedDataTip * This,
    /* [in] */ HWND hwndOwner,
    /* [in] */ POINT *pptTopLeft,
    /* [in] */ RECT *pHotRect);


void __RPC_STUB IVsEnhancedDataTip_Show_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsEnhancedDataTip_SetExpression_Proxy( 
    IVsEnhancedDataTip * This,
    /* [in] */ BSTR bstrExpression);


void __RPC_STUB IVsEnhancedDataTip_SetExpression_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsEnhancedDataTip_GetBaseWindowHandle_Proxy( 
    IVsEnhancedDataTip * This,
    /* [out] */ HWND *phwnd);


void __RPC_STUB IVsEnhancedDataTip_GetBaseWindowHandle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsEnhancedDataTip_IsErrorTip_Proxy( 
    IVsEnhancedDataTip * This,
    /* [out] */ BOOL *pbIsError);


void __RPC_STUB IVsEnhancedDataTip_IsErrorTip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsEnhancedDataTip_IsOpen_Proxy( 
    IVsEnhancedDataTip * This,
    /* [out] */ BOOL *pbIsOpen);


void __RPC_STUB IVsEnhancedDataTip_IsOpen_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsEnhancedDataTip_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshell80_0671 */
/* [local] */ 

typedef struct _VsDebugTargetInfo2
    {
    DWORD cbSize;
    DEBUG_LAUNCH_OPERATION2 dlo;
    VSDBGLAUNCHFLAGS2 LaunchFlags;
    BSTR bstrRemoteMachine;
    BSTR bstrExe;
    BSTR bstrArg;
    BSTR bstrCurDir;
    BSTR bstrEnv;
    GUID guidLaunchDebugEngine;
    DWORD dwDebugEngineCount;
    /* [size_is] */ GUID *pDebugEngines;
    GUID guidPortSupplier;
    BSTR bstrPortName;
    BSTR bstrOptions;
    DWORD_PTR hStdInput;
    DWORD_PTR hStdOutput;
    DWORD_PTR hStdError;
    BOOL fSendToOutputWindow;
    DWORD dwProcessId;
    IUnknown *pUnknown;
    GUID guidProcessLanguage;
    DWORD dwReserved;
    } 	VsDebugTargetInfo2;



extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0671_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0671_v0_0_s_ifspec;

#ifndef __IVsDebugger2_INTERFACE_DEFINED__
#define __IVsDebugger2_INTERFACE_DEFINED__

/* interface IVsDebugger2 */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsDebugger2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B33300FB-FEFE-4E00-A74A-17A5EED1B1ED")
    IVsDebugger2 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE LaunchDebugTargets2( 
            /* [in] */ ULONG DebugTargetCount,
            /* [size_is][out][in] */ VsDebugTargetInfo2 *pDebugTargets) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ConfirmStopDebugging( 
            /* [in] */ LPCOLESTR pszMessage) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumDebugEngines( 
            /* [out] */ IVsEnumGUID **ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEngineName( 
            /* [in] */ REFGUID guidEngine,
            /* [out] */ BSTR *pbstrName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsEngineCompatible( 
            /* [in] */ REFGUID guidEngine,
            /* [in] */ ULONG EngineCount,
            /* [size_is][in] */ GUID *pEngineGUIDs) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetConsoleHandlesForProcess( 
            /* [in] */ DWORD dwPid,
            /* [out] */ ULONG64 *pdwStdInput,
            /* [out] */ ULONG64 *pdwStdOutput,
            /* [out] */ ULONG64 *pdwStdError) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ShowSource( 
            /* [in] */ IUnknown *pUnkDebugDocContext,
            /* [in] */ BOOL fMakeActive,
            /* [in] */ BOOL fAlwaysMoveCaret,
            /* [in] */ BOOL fPromptToFindSource,
            /* [in] */ BOOL fIgnoreIfNotFound,
            /* [out] */ IVsTextView **ppTextView) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateDataTip( 
            /* [in] */ BSTR bstrExpression,
            /* [in] */ VSEDT_STYLE dwStyle,
            /* [out] */ IVsEnhancedDataTip **ppDataTip) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsDebugger2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsDebugger2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsDebugger2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsDebugger2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *LaunchDebugTargets2 )( 
            IVsDebugger2 * This,
            /* [in] */ ULONG DebugTargetCount,
            /* [size_is][out][in] */ VsDebugTargetInfo2 *pDebugTargets);
        
        HRESULT ( STDMETHODCALLTYPE *ConfirmStopDebugging )( 
            IVsDebugger2 * This,
            /* [in] */ LPCOLESTR pszMessage);
        
        HRESULT ( STDMETHODCALLTYPE *EnumDebugEngines )( 
            IVsDebugger2 * This,
            /* [out] */ IVsEnumGUID **ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE *GetEngineName )( 
            IVsDebugger2 * This,
            /* [in] */ REFGUID guidEngine,
            /* [out] */ BSTR *pbstrName);
        
        HRESULT ( STDMETHODCALLTYPE *IsEngineCompatible )( 
            IVsDebugger2 * This,
            /* [in] */ REFGUID guidEngine,
            /* [in] */ ULONG EngineCount,
            /* [size_is][in] */ GUID *pEngineGUIDs);
        
        HRESULT ( STDMETHODCALLTYPE *GetConsoleHandlesForProcess )( 
            IVsDebugger2 * This,
            /* [in] */ DWORD dwPid,
            /* [out] */ ULONG64 *pdwStdInput,
            /* [out] */ ULONG64 *pdwStdOutput,
            /* [out] */ ULONG64 *pdwStdError);
        
        HRESULT ( STDMETHODCALLTYPE *ShowSource )( 
            IVsDebugger2 * This,
            /* [in] */ IUnknown *pUnkDebugDocContext,
            /* [in] */ BOOL fMakeActive,
            /* [in] */ BOOL fAlwaysMoveCaret,
            /* [in] */ BOOL fPromptToFindSource,
            /* [in] */ BOOL fIgnoreIfNotFound,
            /* [out] */ IVsTextView **ppTextView);
        
        HRESULT ( STDMETHODCALLTYPE *CreateDataTip )( 
            IVsDebugger2 * This,
            /* [in] */ BSTR bstrExpression,
            /* [in] */ VSEDT_STYLE dwStyle,
            /* [out] */ IVsEnhancedDataTip **ppDataTip);
        
        END_INTERFACE
    } IVsDebugger2Vtbl;

    interface IVsDebugger2
    {
        CONST_VTBL struct IVsDebugger2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsDebugger2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsDebugger2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsDebugger2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsDebugger2_LaunchDebugTargets2(This,DebugTargetCount,pDebugTargets)	\
    (This)->lpVtbl -> LaunchDebugTargets2(This,DebugTargetCount,pDebugTargets)

#define IVsDebugger2_ConfirmStopDebugging(This,pszMessage)	\
    (This)->lpVtbl -> ConfirmStopDebugging(This,pszMessage)

#define IVsDebugger2_EnumDebugEngines(This,ppEnum)	\
    (This)->lpVtbl -> EnumDebugEngines(This,ppEnum)

#define IVsDebugger2_GetEngineName(This,guidEngine,pbstrName)	\
    (This)->lpVtbl -> GetEngineName(This,guidEngine,pbstrName)

#define IVsDebugger2_IsEngineCompatible(This,guidEngine,EngineCount,pEngineGUIDs)	\
    (This)->lpVtbl -> IsEngineCompatible(This,guidEngine,EngineCount,pEngineGUIDs)

#define IVsDebugger2_GetConsoleHandlesForProcess(This,dwPid,pdwStdInput,pdwStdOutput,pdwStdError)	\
    (This)->lpVtbl -> GetConsoleHandlesForProcess(This,dwPid,pdwStdInput,pdwStdOutput,pdwStdError)

#define IVsDebugger2_ShowSource(This,pUnkDebugDocContext,fMakeActive,fAlwaysMoveCaret,fPromptToFindSource,fIgnoreIfNotFound,ppTextView)	\
    (This)->lpVtbl -> ShowSource(This,pUnkDebugDocContext,fMakeActive,fAlwaysMoveCaret,fPromptToFindSource,fIgnoreIfNotFound,ppTextView)

#define IVsDebugger2_CreateDataTip(This,bstrExpression,dwStyle,ppDataTip)	\
    (This)->lpVtbl -> CreateDataTip(This,bstrExpression,dwStyle,ppDataTip)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsDebugger2_LaunchDebugTargets2_Proxy( 
    IVsDebugger2 * This,
    /* [in] */ ULONG DebugTargetCount,
    /* [size_is][out][in] */ VsDebugTargetInfo2 *pDebugTargets);


void __RPC_STUB IVsDebugger2_LaunchDebugTargets2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsDebugger2_ConfirmStopDebugging_Proxy( 
    IVsDebugger2 * This,
    /* [in] */ LPCOLESTR pszMessage);


void __RPC_STUB IVsDebugger2_ConfirmStopDebugging_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsDebugger2_EnumDebugEngines_Proxy( 
    IVsDebugger2 * This,
    /* [out] */ IVsEnumGUID **ppEnum);


void __RPC_STUB IVsDebugger2_EnumDebugEngines_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsDebugger2_GetEngineName_Proxy( 
    IVsDebugger2 * This,
    /* [in] */ REFGUID guidEngine,
    /* [out] */ BSTR *pbstrName);


void __RPC_STUB IVsDebugger2_GetEngineName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsDebugger2_IsEngineCompatible_Proxy( 
    IVsDebugger2 * This,
    /* [in] */ REFGUID guidEngine,
    /* [in] */ ULONG EngineCount,
    /* [size_is][in] */ GUID *pEngineGUIDs);


void __RPC_STUB IVsDebugger2_IsEngineCompatible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsDebugger2_GetConsoleHandlesForProcess_Proxy( 
    IVsDebugger2 * This,
    /* [in] */ DWORD dwPid,
    /* [out] */ ULONG64 *pdwStdInput,
    /* [out] */ ULONG64 *pdwStdOutput,
    /* [out] */ ULONG64 *pdwStdError);


void __RPC_STUB IVsDebugger2_GetConsoleHandlesForProcess_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsDebugger2_ShowSource_Proxy( 
    IVsDebugger2 * This,
    /* [in] */ IUnknown *pUnkDebugDocContext,
    /* [in] */ BOOL fMakeActive,
    /* [in] */ BOOL fAlwaysMoveCaret,
    /* [in] */ BOOL fPromptToFindSource,
    /* [in] */ BOOL fIgnoreIfNotFound,
    /* [out] */ IVsTextView **ppTextView);


void __RPC_STUB IVsDebugger2_ShowSource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsDebugger2_CreateDataTip_Proxy( 
    IVsDebugger2 * This,
    /* [in] */ BSTR bstrExpression,
    /* [in] */ VSEDT_STYLE dwStyle,
    /* [out] */ IVsEnhancedDataTip **ppDataTip);


void __RPC_STUB IVsDebugger2_CreateDataTip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsDebugger2_INTERFACE_DEFINED__ */


#ifndef __IVsQueryDebuggableProjectCfg_INTERFACE_DEFINED__
#define __IVsQueryDebuggableProjectCfg_INTERFACE_DEFINED__

/* interface IVsQueryDebuggableProjectCfg */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsQueryDebuggableProjectCfg;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CE25FCEE-9E4D-4ec8-856E-38E2BDB2E13B")
    IVsQueryDebuggableProjectCfg : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE QueryDebugTargets( 
            /* [in] */ VSDBGLAUNCHFLAGS grfLaunch,
            /* [in] */ ULONG cTargets,
            /* [size_is][out][in] */ VsDebugTargetInfo2 rgDebugTargetInfo[  ],
            /* [optional][out] */ ULONG *pcActual) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsQueryDebuggableProjectCfgVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsQueryDebuggableProjectCfg * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsQueryDebuggableProjectCfg * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsQueryDebuggableProjectCfg * This);
        
        HRESULT ( STDMETHODCALLTYPE *QueryDebugTargets )( 
            IVsQueryDebuggableProjectCfg * This,
            /* [in] */ VSDBGLAUNCHFLAGS grfLaunch,
            /* [in] */ ULONG cTargets,
            /* [size_is][out][in] */ VsDebugTargetInfo2 rgDebugTargetInfo[  ],
            /* [optional][out] */ ULONG *pcActual);
        
        END_INTERFACE
    } IVsQueryDebuggableProjectCfgVtbl;

    interface IVsQueryDebuggableProjectCfg
    {
        CONST_VTBL struct IVsQueryDebuggableProjectCfgVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsQueryDebuggableProjectCfg_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsQueryDebuggableProjectCfg_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsQueryDebuggableProjectCfg_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsQueryDebuggableProjectCfg_QueryDebugTargets(This,grfLaunch,cTargets,rgDebugTargetInfo,pcActual)	\
    (This)->lpVtbl -> QueryDebugTargets(This,grfLaunch,cTargets,rgDebugTargetInfo,pcActual)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsQueryDebuggableProjectCfg_QueryDebugTargets_Proxy( 
    IVsQueryDebuggableProjectCfg * This,
    /* [in] */ VSDBGLAUNCHFLAGS grfLaunch,
    /* [in] */ ULONG cTargets,
    /* [size_is][out][in] */ VsDebugTargetInfo2 rgDebugTargetInfo[  ],
    /* [optional][out] */ ULONG *pcActual);


void __RPC_STUB IVsQueryDebuggableProjectCfg_QueryDebugTargets_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsQueryDebuggableProjectCfg_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshell80_0673 */
/* [local] */ 

#define VS_E_MIGRATIONREQUIRESRELOAD MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x1FE6)
#define VS_E_SYNCHRONOUSOPENREQUIRED MAKE_HRESULT(SEVERITY_ERROR, FACILITY_ITF, 0x1FE7)

enum __VSOVERLAYICON2
    {	OVERLAYICON_EXCLUDED	= 5,
	OVERLAYICON_NOTONDISK	= 6,
	OVERLAYICON_MAXINDEX2	= 6
    } ;
typedef DWORD VSOVERLAYICON2;


enum __VSMEPROPID2
    {	VSMEPROPID_ICON	= -1012,
	VSMEPROPID_LAST2	= -1012
    } ;
typedef LONG VSMEPROPID2;


enum __COMMANDWINDOWMODE2
    {	CWM_DEFAULT	= -1
    } ;
typedef DWORD COMMANDWINDOWMODE2;



extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0673_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0673_v0_0_s_ifspec;

#ifndef __IVsCommandWindow2_INTERFACE_DEFINED__
#define __IVsCommandWindow2_INTERFACE_DEFINED__

/* interface IVsCommandWindow2 */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsCommandWindow2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E22363B8-E7D3-49b5-B094-7395BB35CE13")
    IVsCommandWindow2 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetMode( 
            /* [in] */ COMMANDWINDOWMODE2 mode) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsCommandWindow2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsCommandWindow2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsCommandWindow2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsCommandWindow2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetMode )( 
            IVsCommandWindow2 * This,
            /* [in] */ COMMANDWINDOWMODE2 mode);
        
        END_INTERFACE
    } IVsCommandWindow2Vtbl;

    interface IVsCommandWindow2
    {
        CONST_VTBL struct IVsCommandWindow2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsCommandWindow2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsCommandWindow2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsCommandWindow2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsCommandWindow2_SetMode(This,mode)	\
    (This)->lpVtbl -> SetMode(This,mode)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsCommandWindow2_SetMode_Proxy( 
    IVsCommandWindow2 * This,
    /* [in] */ COMMANDWINDOWMODE2 mode);


void __RPC_STUB IVsCommandWindow2_SetMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsCommandWindow2_INTERFACE_DEFINED__ */


#ifndef __IVsDeferredDocView_INTERFACE_DEFINED__
#define __IVsDeferredDocView_INTERFACE_DEFINED__

/* interface IVsDeferredDocView */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsDeferredDocView;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F22A0AD5-8F51-4f66-A644-EA64770CF8B7")
    IVsDeferredDocView : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE get_DocView( 
            /* [out] */ IUnknown **ppUnkDocView) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_CmdUIGuid( 
            /* [out] */ GUID *pGuidCmdId) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsDeferredDocViewVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsDeferredDocView * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsDeferredDocView * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsDeferredDocView * This);
        
        HRESULT ( STDMETHODCALLTYPE *get_DocView )( 
            IVsDeferredDocView * This,
            /* [out] */ IUnknown **ppUnkDocView);
        
        HRESULT ( STDMETHODCALLTYPE *get_CmdUIGuid )( 
            IVsDeferredDocView * This,
            /* [out] */ GUID *pGuidCmdId);
        
        END_INTERFACE
    } IVsDeferredDocViewVtbl;

    interface IVsDeferredDocView
    {
        CONST_VTBL struct IVsDeferredDocViewVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsDeferredDocView_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsDeferredDocView_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsDeferredDocView_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsDeferredDocView_get_DocView(This,ppUnkDocView)	\
    (This)->lpVtbl -> get_DocView(This,ppUnkDocView)

#define IVsDeferredDocView_get_CmdUIGuid(This,pGuidCmdId)	\
    (This)->lpVtbl -> get_CmdUIGuid(This,pGuidCmdId)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsDeferredDocView_get_DocView_Proxy( 
    IVsDeferredDocView * This,
    /* [out] */ IUnknown **ppUnkDocView);


void __RPC_STUB IVsDeferredDocView_get_DocView_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsDeferredDocView_get_CmdUIGuid_Proxy( 
    IVsDeferredDocView * This,
    /* [out] */ GUID *pGuidCmdId);


void __RPC_STUB IVsDeferredDocView_get_CmdUIGuid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsDeferredDocView_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshell80_0675 */
/* [local] */ 


enum __VSBLDCFGPROPID
    {	VSBLDCFGPROPID_LAST	= -16000,
	VSBLDCFGPROPID_SupportsMTBuild	= -16000,
	VSBLDCFGPROPID_FIRST	= -16000
    } ;
typedef LONG VSBLDCFGPROPID;



extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0675_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0675_v0_0_s_ifspec;

#ifndef __IVsBuildableProjectCfg2_INTERFACE_DEFINED__
#define __IVsBuildableProjectCfg2_INTERFACE_DEFINED__

/* interface IVsBuildableProjectCfg2 */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsBuildableProjectCfg2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("09857e8e-74cc-43a7-993d-3ec774dca298")
    IVsBuildableProjectCfg2 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetBuildCfgProperty( 
            /* [in] */ VSBLDCFGPROPID propid,
            /* [out] */ VARIANT *pvar) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StartBuildEx( 
            /* [in] */ DWORD dwBuildId,
            /* [in] */ IVsOutputWindowPane *pIVsOutputWindowPane,
            /* [in] */ DWORD dwOptions) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsBuildableProjectCfg2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsBuildableProjectCfg2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsBuildableProjectCfg2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsBuildableProjectCfg2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetBuildCfgProperty )( 
            IVsBuildableProjectCfg2 * This,
            /* [in] */ VSBLDCFGPROPID propid,
            /* [out] */ VARIANT *pvar);
        
        HRESULT ( STDMETHODCALLTYPE *StartBuildEx )( 
            IVsBuildableProjectCfg2 * This,
            /* [in] */ DWORD dwBuildId,
            /* [in] */ IVsOutputWindowPane *pIVsOutputWindowPane,
            /* [in] */ DWORD dwOptions);
        
        END_INTERFACE
    } IVsBuildableProjectCfg2Vtbl;

    interface IVsBuildableProjectCfg2
    {
        CONST_VTBL struct IVsBuildableProjectCfg2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsBuildableProjectCfg2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsBuildableProjectCfg2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsBuildableProjectCfg2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsBuildableProjectCfg2_GetBuildCfgProperty(This,propid,pvar)	\
    (This)->lpVtbl -> GetBuildCfgProperty(This,propid,pvar)

#define IVsBuildableProjectCfg2_StartBuildEx(This,dwBuildId,pIVsOutputWindowPane,dwOptions)	\
    (This)->lpVtbl -> StartBuildEx(This,dwBuildId,pIVsOutputWindowPane,dwOptions)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsBuildableProjectCfg2_GetBuildCfgProperty_Proxy( 
    IVsBuildableProjectCfg2 * This,
    /* [in] */ VSBLDCFGPROPID propid,
    /* [out] */ VARIANT *pvar);


void __RPC_STUB IVsBuildableProjectCfg2_GetBuildCfgProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsBuildableProjectCfg2_StartBuildEx_Proxy( 
    IVsBuildableProjectCfg2 * This,
    /* [in] */ DWORD dwBuildId,
    /* [in] */ IVsOutputWindowPane *pIVsOutputWindowPane,
    /* [in] */ DWORD dwOptions);


void __RPC_STUB IVsBuildableProjectCfg2_StartBuildEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsBuildableProjectCfg2_INTERFACE_DEFINED__ */


#ifndef __IVsPublishableProjectStatusCallback_INTERFACE_DEFINED__
#define __IVsPublishableProjectStatusCallback_INTERFACE_DEFINED__

/* interface IVsPublishableProjectStatusCallback */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsPublishableProjectStatusCallback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("279398E7-6FC1-40a2-9FB3-C321DB469E9B")
    IVsPublishableProjectStatusCallback : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE PublishBegin( 
            /* [out][in] */ BOOL *pfContinue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PublishEnd( 
            /* [in] */ BOOL fSuccess) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Tick( 
            /* [out][in] */ BOOL *pfContinue) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsPublishableProjectStatusCallbackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsPublishableProjectStatusCallback * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsPublishableProjectStatusCallback * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsPublishableProjectStatusCallback * This);
        
        HRESULT ( STDMETHODCALLTYPE *PublishBegin )( 
            IVsPublishableProjectStatusCallback * This,
            /* [out][in] */ BOOL *pfContinue);
        
        HRESULT ( STDMETHODCALLTYPE *PublishEnd )( 
            IVsPublishableProjectStatusCallback * This,
            /* [in] */ BOOL fSuccess);
        
        HRESULT ( STDMETHODCALLTYPE *Tick )( 
            IVsPublishableProjectStatusCallback * This,
            /* [out][in] */ BOOL *pfContinue);
        
        END_INTERFACE
    } IVsPublishableProjectStatusCallbackVtbl;

    interface IVsPublishableProjectStatusCallback
    {
        CONST_VTBL struct IVsPublishableProjectStatusCallbackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsPublishableProjectStatusCallback_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsPublishableProjectStatusCallback_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsPublishableProjectStatusCallback_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsPublishableProjectStatusCallback_PublishBegin(This,pfContinue)	\
    (This)->lpVtbl -> PublishBegin(This,pfContinue)

#define IVsPublishableProjectStatusCallback_PublishEnd(This,fSuccess)	\
    (This)->lpVtbl -> PublishEnd(This,fSuccess)

#define IVsPublishableProjectStatusCallback_Tick(This,pfContinue)	\
    (This)->lpVtbl -> Tick(This,pfContinue)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsPublishableProjectStatusCallback_PublishBegin_Proxy( 
    IVsPublishableProjectStatusCallback * This,
    /* [out][in] */ BOOL *pfContinue);


void __RPC_STUB IVsPublishableProjectStatusCallback_PublishBegin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPublishableProjectStatusCallback_PublishEnd_Proxy( 
    IVsPublishableProjectStatusCallback * This,
    /* [in] */ BOOL fSuccess);


void __RPC_STUB IVsPublishableProjectStatusCallback_PublishEnd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPublishableProjectStatusCallback_Tick_Proxy( 
    IVsPublishableProjectStatusCallback * This,
    /* [out][in] */ BOOL *pfContinue);


void __RPC_STUB IVsPublishableProjectStatusCallback_Tick_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsPublishableProjectStatusCallback_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshell80_0677 */
/* [local] */ 


enum __VSPUBLISHOPTS
    {	PUBOPT_PUBLISHCONTEXT	= 0x1
    } ;
typedef DWORD VSPUBLISHOPTS;



extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0677_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0677_v0_0_s_ifspec;

#ifndef __IVsPublishableProjectCfg_INTERFACE_DEFINED__
#define __IVsPublishableProjectCfg_INTERFACE_DEFINED__

/* interface IVsPublishableProjectCfg */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsPublishableProjectCfg;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("816B2FBE-5C62-439e-8F67-8F0D5D82BC67")
    IVsPublishableProjectCfg : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AdvisePublishStatusCallback( 
            /* [in] */ IVsPublishableProjectStatusCallback *pIVsPublishStatusCallback,
            /* [out] */ VSCOOKIE *pdwCookie) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnadvisePublishStatusCallback( 
            /* [in] */ VSCOOKIE dwCookie) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StartPublish( 
            /* [in] */ IVsOutputWindowPane *pIVsOutputWindowPane,
            /* [in] */ DWORD dwOptions) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryStatusPublish( 
            /* [out] */ BOOL *pfPublishDone) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StopPublish( 
            /* [in] */ BOOL fSync) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ShowPublishPrompt( 
            /* [out] */ BOOL *pfContinue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryStartPublish( 
            /* [in] */ DWORD dwOptions,
            /* [optional][out] */ BOOL *pfSupported,
            /* [optional][out] */ BOOL *pfReady) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPublishProperty( 
            /* [in] */ VSPUBLISHOPTS propid,
            /* [out] */ VARIANT *pvar) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsPublishableProjectCfgVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsPublishableProjectCfg * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsPublishableProjectCfg * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsPublishableProjectCfg * This);
        
        HRESULT ( STDMETHODCALLTYPE *AdvisePublishStatusCallback )( 
            IVsPublishableProjectCfg * This,
            /* [in] */ IVsPublishableProjectStatusCallback *pIVsPublishStatusCallback,
            /* [out] */ VSCOOKIE *pdwCookie);
        
        HRESULT ( STDMETHODCALLTYPE *UnadvisePublishStatusCallback )( 
            IVsPublishableProjectCfg * This,
            /* [in] */ VSCOOKIE dwCookie);
        
        HRESULT ( STDMETHODCALLTYPE *StartPublish )( 
            IVsPublishableProjectCfg * This,
            /* [in] */ IVsOutputWindowPane *pIVsOutputWindowPane,
            /* [in] */ DWORD dwOptions);
        
        HRESULT ( STDMETHODCALLTYPE *QueryStatusPublish )( 
            IVsPublishableProjectCfg * This,
            /* [out] */ BOOL *pfPublishDone);
        
        HRESULT ( STDMETHODCALLTYPE *StopPublish )( 
            IVsPublishableProjectCfg * This,
            /* [in] */ BOOL fSync);
        
        HRESULT ( STDMETHODCALLTYPE *ShowPublishPrompt )( 
            IVsPublishableProjectCfg * This,
            /* [out] */ BOOL *pfContinue);
        
        HRESULT ( STDMETHODCALLTYPE *QueryStartPublish )( 
            IVsPublishableProjectCfg * This,
            /* [in] */ DWORD dwOptions,
            /* [optional][out] */ BOOL *pfSupported,
            /* [optional][out] */ BOOL *pfReady);
        
        HRESULT ( STDMETHODCALLTYPE *GetPublishProperty )( 
            IVsPublishableProjectCfg * This,
            /* [in] */ VSPUBLISHOPTS propid,
            /* [out] */ VARIANT *pvar);
        
        END_INTERFACE
    } IVsPublishableProjectCfgVtbl;

    interface IVsPublishableProjectCfg
    {
        CONST_VTBL struct IVsPublishableProjectCfgVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsPublishableProjectCfg_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsPublishableProjectCfg_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsPublishableProjectCfg_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsPublishableProjectCfg_AdvisePublishStatusCallback(This,pIVsPublishStatusCallback,pdwCookie)	\
    (This)->lpVtbl -> AdvisePublishStatusCallback(This,pIVsPublishStatusCallback,pdwCookie)

#define IVsPublishableProjectCfg_UnadvisePublishStatusCallback(This,dwCookie)	\
    (This)->lpVtbl -> UnadvisePublishStatusCallback(This,dwCookie)

#define IVsPublishableProjectCfg_StartPublish(This,pIVsOutputWindowPane,dwOptions)	\
    (This)->lpVtbl -> StartPublish(This,pIVsOutputWindowPane,dwOptions)

#define IVsPublishableProjectCfg_QueryStatusPublish(This,pfPublishDone)	\
    (This)->lpVtbl -> QueryStatusPublish(This,pfPublishDone)

#define IVsPublishableProjectCfg_StopPublish(This,fSync)	\
    (This)->lpVtbl -> StopPublish(This,fSync)

#define IVsPublishableProjectCfg_ShowPublishPrompt(This,pfContinue)	\
    (This)->lpVtbl -> ShowPublishPrompt(This,pfContinue)

#define IVsPublishableProjectCfg_QueryStartPublish(This,dwOptions,pfSupported,pfReady)	\
    (This)->lpVtbl -> QueryStartPublish(This,dwOptions,pfSupported,pfReady)

#define IVsPublishableProjectCfg_GetPublishProperty(This,propid,pvar)	\
    (This)->lpVtbl -> GetPublishProperty(This,propid,pvar)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsPublishableProjectCfg_AdvisePublishStatusCallback_Proxy( 
    IVsPublishableProjectCfg * This,
    /* [in] */ IVsPublishableProjectStatusCallback *pIVsPublishStatusCallback,
    /* [out] */ VSCOOKIE *pdwCookie);


void __RPC_STUB IVsPublishableProjectCfg_AdvisePublishStatusCallback_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPublishableProjectCfg_UnadvisePublishStatusCallback_Proxy( 
    IVsPublishableProjectCfg * This,
    /* [in] */ VSCOOKIE dwCookie);


void __RPC_STUB IVsPublishableProjectCfg_UnadvisePublishStatusCallback_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPublishableProjectCfg_StartPublish_Proxy( 
    IVsPublishableProjectCfg * This,
    /* [in] */ IVsOutputWindowPane *pIVsOutputWindowPane,
    /* [in] */ DWORD dwOptions);


void __RPC_STUB IVsPublishableProjectCfg_StartPublish_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPublishableProjectCfg_QueryStatusPublish_Proxy( 
    IVsPublishableProjectCfg * This,
    /* [out] */ BOOL *pfPublishDone);


void __RPC_STUB IVsPublishableProjectCfg_QueryStatusPublish_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPublishableProjectCfg_StopPublish_Proxy( 
    IVsPublishableProjectCfg * This,
    /* [in] */ BOOL fSync);


void __RPC_STUB IVsPublishableProjectCfg_StopPublish_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPublishableProjectCfg_ShowPublishPrompt_Proxy( 
    IVsPublishableProjectCfg * This,
    /* [out] */ BOOL *pfContinue);


void __RPC_STUB IVsPublishableProjectCfg_ShowPublishPrompt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPublishableProjectCfg_QueryStartPublish_Proxy( 
    IVsPublishableProjectCfg * This,
    /* [in] */ DWORD dwOptions,
    /* [optional][out] */ BOOL *pfSupported,
    /* [optional][out] */ BOOL *pfReady);


void __RPC_STUB IVsPublishableProjectCfg_QueryStartPublish_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPublishableProjectCfg_GetPublishProperty_Proxy( 
    IVsPublishableProjectCfg * This,
    /* [in] */ VSPUBLISHOPTS propid,
    /* [out] */ VARIANT *pvar);


void __RPC_STUB IVsPublishableProjectCfg_GetPublishProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsPublishableProjectCfg_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshell80_0678 */
/* [local] */ 

typedef 
enum __VSSOLNBUILDUPDATEFLAGS2
    {	SBF_OPERATION_PUBLISHUI	= 0x800000,
	SBF_OPERATION_PUBLISH	= 0x1000000
    } 	VSSOLNBUILDUPDATEFLAGS2;

#define PCL_AUTO_SWITCHES       -2
#define PCL_AUTO_SWITCHVALUES   -3


extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0678_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0678_v0_0_s_ifspec;

#ifndef __IVsParseCommandLine2_INTERFACE_DEFINED__
#define __IVsParseCommandLine2_INTERFACE_DEFINED__

/* interface IVsParseCommandLine2 */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsParseCommandLine2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7837DF15-0604-4ea1-8515-CD5A30972482")
    IVsParseCommandLine2 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetACParamOrSwitch( 
            /* [out] */ int *piACIndex,
            /* [out] */ int *piACStart,
            /* [out] */ int *pcchACLength,
            /* [out] */ BSTR *pbstrCurSwitch,
            /* [retval][out] */ BSTR *pbstrACParam) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsParseCommandLine2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsParseCommandLine2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsParseCommandLine2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsParseCommandLine2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetACParamOrSwitch )( 
            IVsParseCommandLine2 * This,
            /* [out] */ int *piACIndex,
            /* [out] */ int *piACStart,
            /* [out] */ int *pcchACLength,
            /* [out] */ BSTR *pbstrCurSwitch,
            /* [retval][out] */ BSTR *pbstrACParam);
        
        END_INTERFACE
    } IVsParseCommandLine2Vtbl;

    interface IVsParseCommandLine2
    {
        CONST_VTBL struct IVsParseCommandLine2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsParseCommandLine2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsParseCommandLine2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsParseCommandLine2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsParseCommandLine2_GetACParamOrSwitch(This,piACIndex,piACStart,pcchACLength,pbstrCurSwitch,pbstrACParam)	\
    (This)->lpVtbl -> GetACParamOrSwitch(This,piACIndex,piACStart,pcchACLength,pbstrCurSwitch,pbstrACParam)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsParseCommandLine2_GetACParamOrSwitch_Proxy( 
    IVsParseCommandLine2 * This,
    /* [out] */ int *piACIndex,
    /* [out] */ int *piACStart,
    /* [out] */ int *pcchACLength,
    /* [out] */ BSTR *pbstrCurSwitch,
    /* [retval][out] */ BSTR *pbstrACParam);


void __RPC_STUB IVsParseCommandLine2_GetACParamOrSwitch_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsParseCommandLine2_INTERFACE_DEFINED__ */


#ifndef __IVsCommandWindowsCollection_INTERFACE_DEFINED__
#define __IVsCommandWindowsCollection_INTERFACE_DEFINED__

/* interface IVsCommandWindowsCollection */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsCommandWindowsCollection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("615FF029-FEFA-492c-8CD2-C3F66644C3F9")
    IVsCommandWindowsCollection : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Create( 
            /* [in] */ COMMANDWINDOWMODE2 mode,
            /* [in] */ DWORD dwToolWindowId,
            /* [out] */ UINT *puCookie) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OpenExistingOrCreateNewCommandWindow( 
            /* [in] */ COMMANDWINDOWMODE2 mode,
            /* [out] */ UINT *puCookie) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCommandWindowFromCookie( 
            /* [in] */ UINT uCookie,
            /* [out] */ IUnknown **ppunkCmdWindow) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCommandWindowFromMode( 
            /* [in] */ COMMANDWINDOWMODE2 mode,
            /* [out] */ IUnknown **ppunkCmdWindow) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRunningCommandWindowCommand( 
            /* [in] */ UINT uCookie,
            /* [in] */ BOOL fCmdWin) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsOutputWaiting( 
            /* [in] */ UINT uCookie) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Close( 
            /* [in] */ UINT uCookie) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CloseAllCommandWindows( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsCommandWindowsCollectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsCommandWindowsCollection * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsCommandWindowsCollection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsCommandWindowsCollection * This);
        
        HRESULT ( STDMETHODCALLTYPE *Create )( 
            IVsCommandWindowsCollection * This,
            /* [in] */ COMMANDWINDOWMODE2 mode,
            /* [in] */ DWORD dwToolWindowId,
            /* [out] */ UINT *puCookie);
        
        HRESULT ( STDMETHODCALLTYPE *OpenExistingOrCreateNewCommandWindow )( 
            IVsCommandWindowsCollection * This,
            /* [in] */ COMMANDWINDOWMODE2 mode,
            /* [out] */ UINT *puCookie);
        
        HRESULT ( STDMETHODCALLTYPE *GetCommandWindowFromCookie )( 
            IVsCommandWindowsCollection * This,
            /* [in] */ UINT uCookie,
            /* [out] */ IUnknown **ppunkCmdWindow);
        
        HRESULT ( STDMETHODCALLTYPE *GetCommandWindowFromMode )( 
            IVsCommandWindowsCollection * This,
            /* [in] */ COMMANDWINDOWMODE2 mode,
            /* [out] */ IUnknown **ppunkCmdWindow);
        
        HRESULT ( STDMETHODCALLTYPE *SetRunningCommandWindowCommand )( 
            IVsCommandWindowsCollection * This,
            /* [in] */ UINT uCookie,
            /* [in] */ BOOL fCmdWin);
        
        HRESULT ( STDMETHODCALLTYPE *IsOutputWaiting )( 
            IVsCommandWindowsCollection * This,
            /* [in] */ UINT uCookie);
        
        HRESULT ( STDMETHODCALLTYPE *Close )( 
            IVsCommandWindowsCollection * This,
            /* [in] */ UINT uCookie);
        
        HRESULT ( STDMETHODCALLTYPE *CloseAllCommandWindows )( 
            IVsCommandWindowsCollection * This);
        
        END_INTERFACE
    } IVsCommandWindowsCollectionVtbl;

    interface IVsCommandWindowsCollection
    {
        CONST_VTBL struct IVsCommandWindowsCollectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsCommandWindowsCollection_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsCommandWindowsCollection_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsCommandWindowsCollection_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsCommandWindowsCollection_Create(This,mode,dwToolWindowId,puCookie)	\
    (This)->lpVtbl -> Create(This,mode,dwToolWindowId,puCookie)

#define IVsCommandWindowsCollection_OpenExistingOrCreateNewCommandWindow(This,mode,puCookie)	\
    (This)->lpVtbl -> OpenExistingOrCreateNewCommandWindow(This,mode,puCookie)

#define IVsCommandWindowsCollection_GetCommandWindowFromCookie(This,uCookie,ppunkCmdWindow)	\
    (This)->lpVtbl -> GetCommandWindowFromCookie(This,uCookie,ppunkCmdWindow)

#define IVsCommandWindowsCollection_GetCommandWindowFromMode(This,mode,ppunkCmdWindow)	\
    (This)->lpVtbl -> GetCommandWindowFromMode(This,mode,ppunkCmdWindow)

#define IVsCommandWindowsCollection_SetRunningCommandWindowCommand(This,uCookie,fCmdWin)	\
    (This)->lpVtbl -> SetRunningCommandWindowCommand(This,uCookie,fCmdWin)

#define IVsCommandWindowsCollection_IsOutputWaiting(This,uCookie)	\
    (This)->lpVtbl -> IsOutputWaiting(This,uCookie)

#define IVsCommandWindowsCollection_Close(This,uCookie)	\
    (This)->lpVtbl -> Close(This,uCookie)

#define IVsCommandWindowsCollection_CloseAllCommandWindows(This)	\
    (This)->lpVtbl -> CloseAllCommandWindows(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsCommandWindowsCollection_Create_Proxy( 
    IVsCommandWindowsCollection * This,
    /* [in] */ COMMANDWINDOWMODE2 mode,
    /* [in] */ DWORD dwToolWindowId,
    /* [out] */ UINT *puCookie);


void __RPC_STUB IVsCommandWindowsCollection_Create_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsCommandWindowsCollection_OpenExistingOrCreateNewCommandWindow_Proxy( 
    IVsCommandWindowsCollection * This,
    /* [in] */ COMMANDWINDOWMODE2 mode,
    /* [out] */ UINT *puCookie);


void __RPC_STUB IVsCommandWindowsCollection_OpenExistingOrCreateNewCommandWindow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsCommandWindowsCollection_GetCommandWindowFromCookie_Proxy( 
    IVsCommandWindowsCollection * This,
    /* [in] */ UINT uCookie,
    /* [out] */ IUnknown **ppunkCmdWindow);


void __RPC_STUB IVsCommandWindowsCollection_GetCommandWindowFromCookie_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsCommandWindowsCollection_GetCommandWindowFromMode_Proxy( 
    IVsCommandWindowsCollection * This,
    /* [in] */ COMMANDWINDOWMODE2 mode,
    /* [out] */ IUnknown **ppunkCmdWindow);


void __RPC_STUB IVsCommandWindowsCollection_GetCommandWindowFromMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsCommandWindowsCollection_SetRunningCommandWindowCommand_Proxy( 
    IVsCommandWindowsCollection * This,
    /* [in] */ UINT uCookie,
    /* [in] */ BOOL fCmdWin);


void __RPC_STUB IVsCommandWindowsCollection_SetRunningCommandWindowCommand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsCommandWindowsCollection_IsOutputWaiting_Proxy( 
    IVsCommandWindowsCollection * This,
    /* [in] */ UINT uCookie);


void __RPC_STUB IVsCommandWindowsCollection_IsOutputWaiting_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsCommandWindowsCollection_Close_Proxy( 
    IVsCommandWindowsCollection * This,
    /* [in] */ UINT uCookie);


void __RPC_STUB IVsCommandWindowsCollection_Close_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsCommandWindowsCollection_CloseAllCommandWindows_Proxy( 
    IVsCommandWindowsCollection * This);


void __RPC_STUB IVsCommandWindowsCollection_CloseAllCommandWindows_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsCommandWindowsCollection_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshell80_0680 */
/* [local] */ 

#define SID_SVsCommandWindowsCollection IID_IVsCommandWindowsCollection
typedef void (__cdecl * PVsBackgroundTask_Proc)(DWORD_PTR pvParam);
typedef PVsBackgroundTask_Proc PVsBackgroundTask_Function_Pointer;

enum __VSBACKGROUNDTASKPRIORITY
    {	VSBACKGROUNDTASKPRIORITY_STANDARD	= 0,
	VSBACKGROUNDTASKPRIORITY_IMMEDIATE	= 1,
	VSBACKGROUNDTASKPRIORITY_OTHER	= 2
    } ;
typedef DWORD VSBACKGROUNDTASKPRIORITY;



extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0680_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0680_v0_0_s_ifspec;

#ifndef __IVsThreadPool_INTERFACE_DEFINED__
#define __IVsThreadPool_INTERFACE_DEFINED__

/* interface IVsThreadPool */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsThreadPool;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("615FF0FB-A19B-4bc8-B9AF-372EA191BA46")
    IVsThreadPool : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ScheduleTask( 
            /* [in] */ DWORD_PTR pTaskProc,
            /* [in] */ DWORD_PTR pvParam,
            /* [in] */ VSBACKGROUNDTASKPRIORITY priority) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ScheduleWaitableTask( 
            /* [in] */ DWORD_PTR hWait,
            /* [in] */ DWORD_PTR pTaskProc,
            /* [in] */ DWORD_PTR pvParam) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnscheduleWaitableTask( 
            /* [in] */ DWORD_PTR hWait) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsThreadPoolVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsThreadPool * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsThreadPool * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsThreadPool * This);
        
        HRESULT ( STDMETHODCALLTYPE *ScheduleTask )( 
            IVsThreadPool * This,
            /* [in] */ DWORD_PTR pTaskProc,
            /* [in] */ DWORD_PTR pvParam,
            /* [in] */ VSBACKGROUNDTASKPRIORITY priority);
        
        HRESULT ( STDMETHODCALLTYPE *ScheduleWaitableTask )( 
            IVsThreadPool * This,
            /* [in] */ DWORD_PTR hWait,
            /* [in] */ DWORD_PTR pTaskProc,
            /* [in] */ DWORD_PTR pvParam);
        
        HRESULT ( STDMETHODCALLTYPE *UnscheduleWaitableTask )( 
            IVsThreadPool * This,
            /* [in] */ DWORD_PTR hWait);
        
        END_INTERFACE
    } IVsThreadPoolVtbl;

    interface IVsThreadPool
    {
        CONST_VTBL struct IVsThreadPoolVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsThreadPool_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsThreadPool_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsThreadPool_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsThreadPool_ScheduleTask(This,pTaskProc,pvParam,priority)	\
    (This)->lpVtbl -> ScheduleTask(This,pTaskProc,pvParam,priority)

#define IVsThreadPool_ScheduleWaitableTask(This,hWait,pTaskProc,pvParam)	\
    (This)->lpVtbl -> ScheduleWaitableTask(This,hWait,pTaskProc,pvParam)

#define IVsThreadPool_UnscheduleWaitableTask(This,hWait)	\
    (This)->lpVtbl -> UnscheduleWaitableTask(This,hWait)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsThreadPool_ScheduleTask_Proxy( 
    IVsThreadPool * This,
    /* [in] */ DWORD_PTR pTaskProc,
    /* [in] */ DWORD_PTR pvParam,
    /* [in] */ VSBACKGROUNDTASKPRIORITY priority);


void __RPC_STUB IVsThreadPool_ScheduleTask_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsThreadPool_ScheduleWaitableTask_Proxy( 
    IVsThreadPool * This,
    /* [in] */ DWORD_PTR hWait,
    /* [in] */ DWORD_PTR pTaskProc,
    /* [in] */ DWORD_PTR pvParam);


void __RPC_STUB IVsThreadPool_ScheduleWaitableTask_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsThreadPool_UnscheduleWaitableTask_Proxy( 
    IVsThreadPool * This,
    /* [in] */ DWORD_PTR hWait);


void __RPC_STUB IVsThreadPool_UnscheduleWaitableTask_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsThreadPool_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshell80_0681 */
/* [local] */ 

#define SID_SVsThreadPool IID_IVsThreadPool


extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0681_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0681_v0_0_s_ifspec;

#ifndef __IVsACAdapter_INTERFACE_DEFINED__
#define __IVsACAdapter_INTERFACE_DEFINED__

/* interface IVsACAdapter */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsACAdapter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3270B176-8679-42e3-B37D-D260A6B5CB6C")
    IVsACAdapter : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE FAutoCompletionMode( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnStartAutocompletion( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTargetText( 
            /* [out] */ BSTR *pbstrTargetText) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCursorPos( 
            /* [out] */ int *piCursorPos) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetACRect( 
            /* [in] */ int cchOffset,
            /* [in] */ int cchLength,
            /* [out] */ RECT *pRect) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UpdateTargetTextFromACPick( 
            /* [in] */ BSTR bstrPickText,
            /* [in] */ int iSelectionStart,
            /* [in] */ int iSelectionEnd) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ExtractACSubstring( 
            /* [in] */ const WCHAR *szText,
            /* [in] */ int iCursorPos,
            /* [out] */ BSTR *pbstrSubstring,
            /* [out] */ int *piACOffset,
            /* [out] */ int *piACLength) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FormatACText( 
            /* [out][in] */ WCHAR *szACText) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsACAdapterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsACAdapter * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsACAdapter * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsACAdapter * This);
        
        HRESULT ( STDMETHODCALLTYPE *FAutoCompletionMode )( 
            IVsACAdapter * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnStartAutocompletion )( 
            IVsACAdapter * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTargetText )( 
            IVsACAdapter * This,
            /* [out] */ BSTR *pbstrTargetText);
        
        HRESULT ( STDMETHODCALLTYPE *GetCursorPos )( 
            IVsACAdapter * This,
            /* [out] */ int *piCursorPos);
        
        HRESULT ( STDMETHODCALLTYPE *GetACRect )( 
            IVsACAdapter * This,
            /* [in] */ int cchOffset,
            /* [in] */ int cchLength,
            /* [out] */ RECT *pRect);
        
        HRESULT ( STDMETHODCALLTYPE *UpdateTargetTextFromACPick )( 
            IVsACAdapter * This,
            /* [in] */ BSTR bstrPickText,
            /* [in] */ int iSelectionStart,
            /* [in] */ int iSelectionEnd);
        
        HRESULT ( STDMETHODCALLTYPE *ExtractACSubstring )( 
            IVsACAdapter * This,
            /* [in] */ const WCHAR *szText,
            /* [in] */ int iCursorPos,
            /* [out] */ BSTR *pbstrSubstring,
            /* [out] */ int *piACOffset,
            /* [out] */ int *piACLength);
        
        HRESULT ( STDMETHODCALLTYPE *FormatACText )( 
            IVsACAdapter * This,
            /* [out][in] */ WCHAR *szACText);
        
        END_INTERFACE
    } IVsACAdapterVtbl;

    interface IVsACAdapter
    {
        CONST_VTBL struct IVsACAdapterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsACAdapter_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsACAdapter_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsACAdapter_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsACAdapter_FAutoCompletionMode(This)	\
    (This)->lpVtbl -> FAutoCompletionMode(This)

#define IVsACAdapter_OnStartAutocompletion(This)	\
    (This)->lpVtbl -> OnStartAutocompletion(This)

#define IVsACAdapter_GetTargetText(This,pbstrTargetText)	\
    (This)->lpVtbl -> GetTargetText(This,pbstrTargetText)

#define IVsACAdapter_GetCursorPos(This,piCursorPos)	\
    (This)->lpVtbl -> GetCursorPos(This,piCursorPos)

#define IVsACAdapter_GetACRect(This,cchOffset,cchLength,pRect)	\
    (This)->lpVtbl -> GetACRect(This,cchOffset,cchLength,pRect)

#define IVsACAdapter_UpdateTargetTextFromACPick(This,bstrPickText,iSelectionStart,iSelectionEnd)	\
    (This)->lpVtbl -> UpdateTargetTextFromACPick(This,bstrPickText,iSelectionStart,iSelectionEnd)

#define IVsACAdapter_ExtractACSubstring(This,szText,iCursorPos,pbstrSubstring,piACOffset,piACLength)	\
    (This)->lpVtbl -> ExtractACSubstring(This,szText,iCursorPos,pbstrSubstring,piACOffset,piACLength)

#define IVsACAdapter_FormatACText(This,szACText)	\
    (This)->lpVtbl -> FormatACText(This,szACText)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsACAdapter_FAutoCompletionMode_Proxy( 
    IVsACAdapter * This);


void __RPC_STUB IVsACAdapter_FAutoCompletionMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsACAdapter_OnStartAutocompletion_Proxy( 
    IVsACAdapter * This);


void __RPC_STUB IVsACAdapter_OnStartAutocompletion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsACAdapter_GetTargetText_Proxy( 
    IVsACAdapter * This,
    /* [out] */ BSTR *pbstrTargetText);


void __RPC_STUB IVsACAdapter_GetTargetText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsACAdapter_GetCursorPos_Proxy( 
    IVsACAdapter * This,
    /* [out] */ int *piCursorPos);


void __RPC_STUB IVsACAdapter_GetCursorPos_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsACAdapter_GetACRect_Proxy( 
    IVsACAdapter * This,
    /* [in] */ int cchOffset,
    /* [in] */ int cchLength,
    /* [out] */ RECT *pRect);


void __RPC_STUB IVsACAdapter_GetACRect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsACAdapter_UpdateTargetTextFromACPick_Proxy( 
    IVsACAdapter * This,
    /* [in] */ BSTR bstrPickText,
    /* [in] */ int iSelectionStart,
    /* [in] */ int iSelectionEnd);


void __RPC_STUB IVsACAdapter_UpdateTargetTextFromACPick_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsACAdapter_ExtractACSubstring_Proxy( 
    IVsACAdapter * This,
    /* [in] */ const WCHAR *szText,
    /* [in] */ int iCursorPos,
    /* [out] */ BSTR *pbstrSubstring,
    /* [out] */ int *piACOffset,
    /* [out] */ int *piACLength);


void __RPC_STUB IVsACAdapter_ExtractACSubstring_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsACAdapter_FormatACText_Proxy( 
    IVsACAdapter * This,
    /* [out][in] */ WCHAR *szACText);


void __RPC_STUB IVsACAdapter_FormatACText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsACAdapter_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshell80_0682 */
/* [local] */ 

typedef 
enum __tagACOPTION
    {	ACO_INLINE	= 0,
	ACO_POPUP	= 1
    } 	__ACOPTION;

typedef int ACOPTIONS;

typedef 
enum __tagACLISTINDEX
    {	ACLI_INVALID	= -2,
	ACLI_NONE	= -1,
	ACLI_MIN	= 0,
	ACLI_ASYNCH_MIN	= 0,
	ACLI_COMMANDS	= ACLI_ASYNCH_MIN,
	ACLI_ALIASES	= ACLI_COMMANDS + 1,
	ACLI_SOLUTIONFILES	= ACLI_ALIASES + 1,
	ACLI_PROJECTTEMPLATES	= ACLI_SOLUTIONFILES + 1,
	ACLI_FILETEMPLATES	= ACLI_PROJECTTEMPLATES + 1,
	ACLI_ASYNCH_MAX	= ACLI_FILETEMPLATES,
	ACLI_SYNCH_MIN	= 16,
	ACLI_URL	= ACLI_SYNCH_MIN,
	ACLI_DISKFILES	= ACLI_URL + 1,
	ACLI_DIRECTORIES	= ACLI_DISKFILES + 1,
	ACLI_USERPROVIDED	= ACLI_DIRECTORIES + 1,
	ACLI_SYNCH_MAX	= ACLI_USERPROVIDED,
	ACLI_MAX	= 32
    } 	__ACLISTINDEX;

typedef 
enum __tagACSOURCE
    {	ACS_COMMANDS	= 1 << ACLI_COMMANDS,
	ACS_ALIASES	= 1 << ACLI_ALIASES,
	ACS_SOLUTIONFILES	= 1 << ACLI_SOLUTIONFILES,
	ACS_PROJECTTEMPLATES	= 1 << ACLI_PROJECTTEMPLATES,
	ACS_FILETEMPLATES	= 1 << ACLI_FILETEMPLATES,
	ACS_URL	= 1 << ACLI_URL,
	ACS_DISKFILES	= 1 << ACLI_DISKFILES,
	ACS_DIRECTORIES	= 1 << ACLI_DIRECTORIES,
	ACS_USERPROVIDED	= 1 << ACLI_USERPROVIDED
    } 	__ACSOURCE;

typedef DWORD ACSOURCES;

typedef 
enum __tagACLISTOPTION
    {	ACLISTO_NONE	= 0,
	ACLISTO_CURRENTDIR	= 1,
	ACLISTO_MYCOMPUTER	= 2,
	ACLISTO_DESKTOP	= 4,
	ACLISTO_FAVORITES	= 8,
	ACLISTO_FILESYSONLY	= 16,
	ACLISTO_FILESYSDIRS	= 32
    } 	__ACLISTOPTION;

typedef int ACLISTOPTIONS;



extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0682_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0682_v0_0_s_ifspec;

#ifndef __IVsAutoCompletion_INTERFACE_DEFINED__
#define __IVsAutoCompletion_INTERFACE_DEFINED__

/* interface IVsAutoCompletion */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsAutoCompletion;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("39AA086B-2744-44e2-830E-D4A9AF2391EB")
    IVsAutoCompletion : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Init( 
            /* [in] */ HWND hwndEdit,
            /* [in] */ const WCHAR *pszDelim) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetStartDir( 
            /* [ref][in] */ const WCHAR *pszStartDir) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSources( 
            /* [in] */ ACSOURCES grfSources) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetUserProvidedEnum( 
            /* [in] */ IEnumString *pesUserProvidedEnum,
            /* [in] */ BOOL fCopy) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetACListOptions( 
            /* [in] */ ACLISTOPTIONS grfACListOptions) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetACOptions( 
            /* [in] */ ACOPTIONS grfOptions) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStartDir( 
            /* [retval][out] */ BSTR *pbstrStartDir) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSources( 
            /* [retval][out] */ ACSOURCES *pgrfSources) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetACOptions( 
            /* [retval][out] */ ACOPTIONS *pgrfOptions) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetACListOptions( 
            /* [retval][out] */ ACLISTOPTIONS *pgrfACListOptions) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUserProvidedEnum( 
            /* [retval][out] */ IEnumString **pesUserProvidedEnum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsAutoCompletionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsAutoCompletion * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsAutoCompletion * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsAutoCompletion * This);
        
        HRESULT ( STDMETHODCALLTYPE *Init )( 
            IVsAutoCompletion * This,
            /* [in] */ HWND hwndEdit,
            /* [in] */ const WCHAR *pszDelim);
        
        HRESULT ( STDMETHODCALLTYPE *SetStartDir )( 
            IVsAutoCompletion * This,
            /* [ref][in] */ const WCHAR *pszStartDir);
        
        HRESULT ( STDMETHODCALLTYPE *SetSources )( 
            IVsAutoCompletion * This,
            /* [in] */ ACSOURCES grfSources);
        
        HRESULT ( STDMETHODCALLTYPE *SetUserProvidedEnum )( 
            IVsAutoCompletion * This,
            /* [in] */ IEnumString *pesUserProvidedEnum,
            /* [in] */ BOOL fCopy);
        
        HRESULT ( STDMETHODCALLTYPE *SetACListOptions )( 
            IVsAutoCompletion * This,
            /* [in] */ ACLISTOPTIONS grfACListOptions);
        
        HRESULT ( STDMETHODCALLTYPE *SetACOptions )( 
            IVsAutoCompletion * This,
            /* [in] */ ACOPTIONS grfOptions);
        
        HRESULT ( STDMETHODCALLTYPE *GetStartDir )( 
            IVsAutoCompletion * This,
            /* [retval][out] */ BSTR *pbstrStartDir);
        
        HRESULT ( STDMETHODCALLTYPE *GetSources )( 
            IVsAutoCompletion * This,
            /* [retval][out] */ ACSOURCES *pgrfSources);
        
        HRESULT ( STDMETHODCALLTYPE *GetACOptions )( 
            IVsAutoCompletion * This,
            /* [retval][out] */ ACOPTIONS *pgrfOptions);
        
        HRESULT ( STDMETHODCALLTYPE *GetACListOptions )( 
            IVsAutoCompletion * This,
            /* [retval][out] */ ACLISTOPTIONS *pgrfACListOptions);
        
        HRESULT ( STDMETHODCALLTYPE *GetUserProvidedEnum )( 
            IVsAutoCompletion * This,
            /* [retval][out] */ IEnumString **pesUserProvidedEnum);
        
        END_INTERFACE
    } IVsAutoCompletionVtbl;

    interface IVsAutoCompletion
    {
        CONST_VTBL struct IVsAutoCompletionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsAutoCompletion_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsAutoCompletion_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsAutoCompletion_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsAutoCompletion_Init(This,hwndEdit,pszDelim)	\
    (This)->lpVtbl -> Init(This,hwndEdit,pszDelim)

#define IVsAutoCompletion_SetStartDir(This,pszStartDir)	\
    (This)->lpVtbl -> SetStartDir(This,pszStartDir)

#define IVsAutoCompletion_SetSources(This,grfSources)	\
    (This)->lpVtbl -> SetSources(This,grfSources)

#define IVsAutoCompletion_SetUserProvidedEnum(This,pesUserProvidedEnum,fCopy)	\
    (This)->lpVtbl -> SetUserProvidedEnum(This,pesUserProvidedEnum,fCopy)

#define IVsAutoCompletion_SetACListOptions(This,grfACListOptions)	\
    (This)->lpVtbl -> SetACListOptions(This,grfACListOptions)

#define IVsAutoCompletion_SetACOptions(This,grfOptions)	\
    (This)->lpVtbl -> SetACOptions(This,grfOptions)

#define IVsAutoCompletion_GetStartDir(This,pbstrStartDir)	\
    (This)->lpVtbl -> GetStartDir(This,pbstrStartDir)

#define IVsAutoCompletion_GetSources(This,pgrfSources)	\
    (This)->lpVtbl -> GetSources(This,pgrfSources)

#define IVsAutoCompletion_GetACOptions(This,pgrfOptions)	\
    (This)->lpVtbl -> GetACOptions(This,pgrfOptions)

#define IVsAutoCompletion_GetACListOptions(This,pgrfACListOptions)	\
    (This)->lpVtbl -> GetACListOptions(This,pgrfACListOptions)

#define IVsAutoCompletion_GetUserProvidedEnum(This,pesUserProvidedEnum)	\
    (This)->lpVtbl -> GetUserProvidedEnum(This,pesUserProvidedEnum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsAutoCompletion_Init_Proxy( 
    IVsAutoCompletion * This,
    /* [in] */ HWND hwndEdit,
    /* [in] */ const WCHAR *pszDelim);


void __RPC_STUB IVsAutoCompletion_Init_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsAutoCompletion_SetStartDir_Proxy( 
    IVsAutoCompletion * This,
    /* [ref][in] */ const WCHAR *pszStartDir);


void __RPC_STUB IVsAutoCompletion_SetStartDir_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsAutoCompletion_SetSources_Proxy( 
    IVsAutoCompletion * This,
    /* [in] */ ACSOURCES grfSources);


void __RPC_STUB IVsAutoCompletion_SetSources_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsAutoCompletion_SetUserProvidedEnum_Proxy( 
    IVsAutoCompletion * This,
    /* [in] */ IEnumString *pesUserProvidedEnum,
    /* [in] */ BOOL fCopy);


void __RPC_STUB IVsAutoCompletion_SetUserProvidedEnum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsAutoCompletion_SetACListOptions_Proxy( 
    IVsAutoCompletion * This,
    /* [in] */ ACLISTOPTIONS grfACListOptions);


void __RPC_STUB IVsAutoCompletion_SetACListOptions_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsAutoCompletion_SetACOptions_Proxy( 
    IVsAutoCompletion * This,
    /* [in] */ ACOPTIONS grfOptions);


void __RPC_STUB IVsAutoCompletion_SetACOptions_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsAutoCompletion_GetStartDir_Proxy( 
    IVsAutoCompletion * This,
    /* [retval][out] */ BSTR *pbstrStartDir);


void __RPC_STUB IVsAutoCompletion_GetStartDir_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsAutoCompletion_GetSources_Proxy( 
    IVsAutoCompletion * This,
    /* [retval][out] */ ACSOURCES *pgrfSources);


void __RPC_STUB IVsAutoCompletion_GetSources_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsAutoCompletion_GetACOptions_Proxy( 
    IVsAutoCompletion * This,
    /* [retval][out] */ ACOPTIONS *pgrfOptions);


void __RPC_STUB IVsAutoCompletion_GetACOptions_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsAutoCompletion_GetACListOptions_Proxy( 
    IVsAutoCompletion * This,
    /* [retval][out] */ ACLISTOPTIONS *pgrfACListOptions);


void __RPC_STUB IVsAutoCompletion_GetACListOptions_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsAutoCompletion_GetUserProvidedEnum_Proxy( 
    IVsAutoCompletion * This,
    /* [retval][out] */ IEnumString **pesUserProvidedEnum);


void __RPC_STUB IVsAutoCompletion_GetUserProvidedEnum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsAutoCompletion_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshell80_0683 */
/* [local] */ 

#define SID_SVsAutoCompletion IID_IVsAutoCompletion


extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0683_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0683_v0_0_s_ifspec;

#ifndef __IVsAutoCompletionUI_INTERFACE_DEFINED__
#define __IVsAutoCompletionUI_INTERFACE_DEFINED__

/* interface IVsAutoCompletionUI */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsAutoCompletionUI;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("80FA261A-CC4C-4a96-9E3B-6388BA98E6D2")
    IVsAutoCompletionUI : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE InitUI( 
            /* [in] */ IVsACAdapter *iacAdapter) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnTargetTextChanged( 
            /* [in] */ BOOL fForceIfEmpty) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnKey( 
            /* [in] */ UINT uMsg,
            /* [in] */ WPARAM wParam,
            /* [in] */ LPARAM lParam) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnChar( 
            /* [in] */ WPARAM wParam,
            /* [in] */ LPARAM lParam) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnKillFocus( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnSetFocus( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Complete( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Cancel( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ForceRequery( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsACDroppedDown( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetACListSelection( 
            /* [out] */ BSTR *pbstrSel) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetACWindow( 
            /* [out] */ HWND *hwndACWindow) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsAutoCompletionUIVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsAutoCompletionUI * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsAutoCompletionUI * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsAutoCompletionUI * This);
        
        HRESULT ( STDMETHODCALLTYPE *InitUI )( 
            IVsAutoCompletionUI * This,
            /* [in] */ IVsACAdapter *iacAdapter);
        
        HRESULT ( STDMETHODCALLTYPE *OnTargetTextChanged )( 
            IVsAutoCompletionUI * This,
            /* [in] */ BOOL fForceIfEmpty);
        
        HRESULT ( STDMETHODCALLTYPE *OnKey )( 
            IVsAutoCompletionUI * This,
            /* [in] */ UINT uMsg,
            /* [in] */ WPARAM wParam,
            /* [in] */ LPARAM lParam);
        
        HRESULT ( STDMETHODCALLTYPE *OnChar )( 
            IVsAutoCompletionUI * This,
            /* [in] */ WPARAM wParam,
            /* [in] */ LPARAM lParam);
        
        HRESULT ( STDMETHODCALLTYPE *OnKillFocus )( 
            IVsAutoCompletionUI * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnSetFocus )( 
            IVsAutoCompletionUI * This);
        
        HRESULT ( STDMETHODCALLTYPE *Complete )( 
            IVsAutoCompletionUI * This);
        
        HRESULT ( STDMETHODCALLTYPE *Cancel )( 
            IVsAutoCompletionUI * This);
        
        HRESULT ( STDMETHODCALLTYPE *ForceRequery )( 
            IVsAutoCompletionUI * This);
        
        HRESULT ( STDMETHODCALLTYPE *IsACDroppedDown )( 
            IVsAutoCompletionUI * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetACListSelection )( 
            IVsAutoCompletionUI * This,
            /* [out] */ BSTR *pbstrSel);
        
        HRESULT ( STDMETHODCALLTYPE *GetACWindow )( 
            IVsAutoCompletionUI * This,
            /* [out] */ HWND *hwndACWindow);
        
        END_INTERFACE
    } IVsAutoCompletionUIVtbl;

    interface IVsAutoCompletionUI
    {
        CONST_VTBL struct IVsAutoCompletionUIVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsAutoCompletionUI_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsAutoCompletionUI_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsAutoCompletionUI_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsAutoCompletionUI_InitUI(This,iacAdapter)	\
    (This)->lpVtbl -> InitUI(This,iacAdapter)

#define IVsAutoCompletionUI_OnTargetTextChanged(This,fForceIfEmpty)	\
    (This)->lpVtbl -> OnTargetTextChanged(This,fForceIfEmpty)

#define IVsAutoCompletionUI_OnKey(This,uMsg,wParam,lParam)	\
    (This)->lpVtbl -> OnKey(This,uMsg,wParam,lParam)

#define IVsAutoCompletionUI_OnChar(This,wParam,lParam)	\
    (This)->lpVtbl -> OnChar(This,wParam,lParam)

#define IVsAutoCompletionUI_OnKillFocus(This)	\
    (This)->lpVtbl -> OnKillFocus(This)

#define IVsAutoCompletionUI_OnSetFocus(This)	\
    (This)->lpVtbl -> OnSetFocus(This)

#define IVsAutoCompletionUI_Complete(This)	\
    (This)->lpVtbl -> Complete(This)

#define IVsAutoCompletionUI_Cancel(This)	\
    (This)->lpVtbl -> Cancel(This)

#define IVsAutoCompletionUI_ForceRequery(This)	\
    (This)->lpVtbl -> ForceRequery(This)

#define IVsAutoCompletionUI_IsACDroppedDown(This)	\
    (This)->lpVtbl -> IsACDroppedDown(This)

#define IVsAutoCompletionUI_GetACListSelection(This,pbstrSel)	\
    (This)->lpVtbl -> GetACListSelection(This,pbstrSel)

#define IVsAutoCompletionUI_GetACWindow(This,hwndACWindow)	\
    (This)->lpVtbl -> GetACWindow(This,hwndACWindow)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsAutoCompletionUI_InitUI_Proxy( 
    IVsAutoCompletionUI * This,
    /* [in] */ IVsACAdapter *iacAdapter);


void __RPC_STUB IVsAutoCompletionUI_InitUI_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsAutoCompletionUI_OnTargetTextChanged_Proxy( 
    IVsAutoCompletionUI * This,
    /* [in] */ BOOL fForceIfEmpty);


void __RPC_STUB IVsAutoCompletionUI_OnTargetTextChanged_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsAutoCompletionUI_OnKey_Proxy( 
    IVsAutoCompletionUI * This,
    /* [in] */ UINT uMsg,
    /* [in] */ WPARAM wParam,
    /* [in] */ LPARAM lParam);


void __RPC_STUB IVsAutoCompletionUI_OnKey_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsAutoCompletionUI_OnChar_Proxy( 
    IVsAutoCompletionUI * This,
    /* [in] */ WPARAM wParam,
    /* [in] */ LPARAM lParam);


void __RPC_STUB IVsAutoCompletionUI_OnChar_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsAutoCompletionUI_OnKillFocus_Proxy( 
    IVsAutoCompletionUI * This);


void __RPC_STUB IVsAutoCompletionUI_OnKillFocus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsAutoCompletionUI_OnSetFocus_Proxy( 
    IVsAutoCompletionUI * This);


void __RPC_STUB IVsAutoCompletionUI_OnSetFocus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsAutoCompletionUI_Complete_Proxy( 
    IVsAutoCompletionUI * This);


void __RPC_STUB IVsAutoCompletionUI_Complete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsAutoCompletionUI_Cancel_Proxy( 
    IVsAutoCompletionUI * This);


void __RPC_STUB IVsAutoCompletionUI_Cancel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsAutoCompletionUI_ForceRequery_Proxy( 
    IVsAutoCompletionUI * This);


void __RPC_STUB IVsAutoCompletionUI_ForceRequery_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsAutoCompletionUI_IsACDroppedDown_Proxy( 
    IVsAutoCompletionUI * This);


void __RPC_STUB IVsAutoCompletionUI_IsACDroppedDown_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsAutoCompletionUI_GetACListSelection_Proxy( 
    IVsAutoCompletionUI * This,
    /* [out] */ BSTR *pbstrSel);


void __RPC_STUB IVsAutoCompletionUI_GetACListSelection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsAutoCompletionUI_GetACWindow_Proxy( 
    IVsAutoCompletionUI * This,
    /* [out] */ HWND *hwndACWindow);


void __RPC_STUB IVsAutoCompletionUI_GetACWindow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsAutoCompletionUI_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshell80_0684 */
/* [local] */ 

typedef struct _VSNSEBROWSEINFOW
    {
    DWORD lStructSize;
    LPCOLESTR pszNamespaceGUID;
    LPCOLESTR pszTrayDisplayName;
    LPCOLESTR pszProtocolPrefix;
    BOOL fOnlyShowNSEInTray;
    } 	VSNSEBROWSEINFOW;

typedef struct _VSSAVETREEITEM
    {
    VSRDTSAVEOPTIONS grfSave;
    VSCOOKIE docCookie;
    IVsHierarchy *pHier;
    VSITEMID itemid;
    } 	VSSAVETREEITEM;



extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0684_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0684_v0_0_s_ifspec;

#ifndef __IVsShell2_INTERFACE_DEFINED__
#define __IVsShell2_INTERFACE_DEFINED__

/* interface IVsShell2 */
/* [object][version][uuid] */ 


EXTERN_C const IID IID_IVsShell2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F3519E2D-D5D2-4455-B9F4-5F61F993BD66")
    IVsShell2 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE LoadPackageStringWithLCID( 
            /* [in] */ REFGUID guidPackage,
            /* [in] */ ULONG resid,
            /* [in] */ LCID lcid,
            /* [retval][out] */ BSTR *pbstrOut) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsShell2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsShell2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsShell2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsShell2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *LoadPackageStringWithLCID )( 
            IVsShell2 * This,
            /* [in] */ REFGUID guidPackage,
            /* [in] */ ULONG resid,
            /* [in] */ LCID lcid,
            /* [retval][out] */ BSTR *pbstrOut);
        
        END_INTERFACE
    } IVsShell2Vtbl;

    interface IVsShell2
    {
        CONST_VTBL struct IVsShell2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsShell2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsShell2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsShell2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsShell2_LoadPackageStringWithLCID(This,guidPackage,resid,lcid,pbstrOut)	\
    (This)->lpVtbl -> LoadPackageStringWithLCID(This,guidPackage,resid,lcid,pbstrOut)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsShell2_LoadPackageStringWithLCID_Proxy( 
    IVsShell2 * This,
    /* [in] */ REFGUID guidPackage,
    /* [in] */ ULONG resid,
    /* [in] */ LCID lcid,
    /* [retval][out] */ BSTR *pbstrOut);


void __RPC_STUB IVsShell2_LoadPackageStringWithLCID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsShell2_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshell80_0685 */
/* [local] */ 

typedef 
enum __VSSYSCOLOREX
    {	VSCOLOR_ACCENT_BORDER	= -5,
	VSCOLOR_ACCENT_DARK	= -6,
	VSCOLOR_ACCENT_LIGHT	= -7,
	VSCOLOR_ACCENT_MEDIUM	= -8,
	VSCOLOR_ACCENT_PALE	= -9,
	VSCOLOR_COMMANDBAR_BORDER	= -10,
	VSCOLOR_COMMANDBAR_DRAGHANDLE	= -11,
	VSCOLOR_COMMANDBAR_DRAGHANDLE_SHADOW	= -12,
	VSCOLOR_COMMANDBAR_GRADIENT_BEGIN	= -13,
	VSCOLOR_COMMANDBAR_GRADIENT_END	= -14,
	VSCOLOR_COMMANDBAR_GRADIENT_MIDDLE	= -15,
	VSCOLOR_COMMANDBAR_HOVER	= -16,
	VSCOLOR_COMMANDBAR_HOVEROVERSELECTED	= -17,
	VSCOLOR_COMMANDBAR_SELECTED	= -18,
	VSCOLOR_COMMANDBAR_SHADOW	= -19,
	VSCOLOR_COMMANDBAR_TEXT_ACTIVE	= -20,
	VSCOLOR_COMMANDBAR_TEXT_INACTIVE	= -21,
	VSCOLOR_CONTROL_EDIT_HINTTEXT	= -22,
	VSCOLOR_CONTROL_EDIT_REQUIRED_BACKGROUND	= -23,
	VSCOLOR_CONTROL_EDIT_REQUIRED_HINTTEXT	= -24,
	VSCOLOR_CONTROL_LINK_TEXT	= -25,
	VSCOLOR_CONTROL_LINK_TEXT_HOVER	= -26,
	VSCOLOR_CONTROL_LINK_TEXT_PRESSED	= -27,
	VSCOLOR_CONTROL_OUTLINE	= -28,
	VSCOLOR_DEBUGGER_DATATIP_ACTIVE_BACKGROUND	= -29,
	VSCOLOR_DEBUGGER_DATATIP_ACTIVE_BORDER	= -30,
	VSCOLOR_DEBUGGER_DATATIP_ACTIVE_TEXT	= -31,
	VSCOLOR_DEBUGGER_DATATIP_INACTIVE_BACKGROUND	= -32,
	VSCOLOR_DEBUGGER_DATATIP_INACTIVE_BORDER	= -33,
	VSCOLOR_DEBUGGER_DATATIP_INACTIVE_TEXT	= -34,
	VSCOLOR_DESIGNER_BACKGROUND	= -35,
	VSCOLOR_DESIGNER_TRAY	= -36,
	VSCOLOR_DESIGNER_WATERMARK	= -37,
	VSCOLOR_FILETAB_BORDER	= -38,
	VSCOLOR_FILETAB_CHANNELBACKGROUND	= -39,
	VSCOLOR_FILETAB_GRADIENTDARK	= -40,
	VSCOLOR_FILETAB_GRADIENTLIGHT	= -41,
	VSCOLOR_FILETAB_SELECTEDBACKGROUND	= -42,
	VSCOLOR_FILETAB_SELECTEDBORDER	= -43,
	VSCOLOR_FILETAB_SELECTEDTEXT	= -44,
	VSCOLOR_FILETAB_TEXT	= -45,
	VSCOLOR_FORMSMARTTAG_ACTIONTAG_BORDER	= -46,
	VSCOLOR_FORMSMARTTAG_ACTIONTAG_FILL	= -47,
	VSCOLOR_FORMSMARTTAG_OBJECTTAG_BORDER	= -48,
	VSCOLOR_FORMSMARTTAG_OBJECTTAG_FILL	= -49,
	VSCOLOR_PANEL_BORDER	= -50,
	VSCOLOR_PANEL_GRADIENTDARK	= -51,
	VSCOLOR_PANEL_GRADIENTLIGHT	= -52,
	VSCOLOR_PANEL_HOVEROVERCLOSE_BORDER	= -53,
	VSCOLOR_PANEL_HOVEROVERCLOSE_FILL	= -54,
	VSCOLOR_PANEL_HYPERLINK	= -55,
	VSCOLOR_PANEL_HYPERLINK_HOVER	= -56,
	VSCOLOR_PANEL_HYPERLINK_PRESSED	= -57,
	VSCOLOR_PANEL_SEPARATOR	= -58,
	VSCOLOR_PANEL_SUBGROUPSEPARATOR	= -59,
	VSCOLOR_PANEL_TEXT	= -60,
	VSCOLOR_PANEL_TITLEBAR	= -61,
	VSCOLOR_PANEL_TITLEBAR_TEXT	= -62,
	VSCOLOR_PANEL_TITLEBAR_UNSELECTED	= -63,
	VSCOLOR_SCREENTIP_BORDER	= -64,
	VSCOLOR_SCREENTIP_BACKGROUND	= -65,
	VSCOLOR_SCREENTIP_TEXT	= -66,
	VSCOLOR_ENVIRONMENT_BACKGROUND	= -67,
	VSCOLOR_ENVIRONMENT_BACKGROUND_GRADIENTBEGIN	= -68,
	VSCOLOR_ENVIRONMENT_BACKGROUND_GRADIENTEND	= -69,
	VSCOLOR_SIDEBAR_BACKGROUND	= -70,
	VSCOLOR_SIDEBAR_GRADIENTDARK	= -71,
	VSCOLOR_SIDEBAR_GRADIENTLIGHT	= -72,
	VSCOLOR_SIDEBAR_TEXT	= -73,
	VSCOLOR_SMARTTAG_BORDER	= -74,
	VSCOLOR_SMARTTAG_FILL	= -75,
	VSCOLOR_SMARTTAG_HOVER_BORDER	= -76,
	VSCOLOR_SMARTTAG_HOVER_FILL	= -77,
	VSCOLOR_SMARTTAG_HOVER_TEXT	= -78,
	VSCOLOR_SMARTTAG_TEXT	= -79,
	VSCOLOR_SNAPLINES	= -80,
	VSCOLOR_SNAPLINES_TEXTBASELINE	= -81,
	VSCOLOR_TASKLIST_GRIDLINES	= -82,
	VSCOLOR_TITLEBAR_ACTIVE	= -83,
	VSCOLOR_TITLEBAR_ACTIVE_GRADIENTBEGIN	= -84,
	VSCOLOR_TITLEBAR_ACTIVE_GRADIENTEND	= -85,
	VSCOLOR_TITLEBAR_ACTIVE_TEXT	= -86,
	VSCOLOR_TITLEBAR_INACTIVE	= -87,
	VSCOLOR_TITLEBAR_INACTIVE_GRADIENTBEGIN	= -88,
	VSCOLOR_TITLEBAR_INACTIVE_GRADIENTEND	= -89,
	VSCOLOR_TITLEBAR_INACTIVE_TEXT	= -90,
	VSCOLOR_TOOLBOX_BACKGROUND	= -91,
	VSCOLOR_TOOLBOX_DIVIDER	= -92,
	VSCOLOR_TOOLBOX_GRADIENTDARK	= -93,
	VSCOLOR_TOOLBOX_GRADIENTLIGHT	= -94,
	VSCOLOR_TOOLBOX_HEADINGACCENT	= -95,
	VSCOLOR_TOOLBOX_HEADINGBEGIN	= -96,
	VSCOLOR_TOOLBOX_HEADINGEND	= -97,
	VSCOLOR_TOOLBOX_CAPTION_ACTIVE	= -98,
	VSCOLOR_TOOLBOX_CAPTION_INACTIVE	= -99,
	VSCOLOR_TOOLBOX_ICON_HIGHLIGHT	= -100,
	VSCOLOR_TOOLBOX_ICON_SHADOW	= -101,
	VSCOLOR_TOOLWINDOW_TAB_SELECTEDTAB	= -102,
	VSCOLOR_TOOLWINDOW_TAB_BORDER	= -103,
	VSCOLOR_TOOLWINDOW_TAB_GRADIENTBEGIN	= -104,
	VSCOLOR_TOOLWINDOW_TAB_GRADIENTEND	= -105,
	VSCOLOR_TOOLWINDOW_TAB_TEXT	= -106,
	VSCOLOR_TOOLWINDOW_TAB_SELECTEDTEXT	= -107,
	VSCOLOR_HELP_HOWDOI_PANE_BACKGROUND	= -108,
	VSCOLOR_HELP_HOWDOI_PANE_BORDER	= -109,
	VSCOLOR_HELP_HOWDOI_PANE_LINK	= -110,
	VSCOLOR_HELP_HOWDOI_PANE_TEXT	= -111,
	VSCOLOR_HELP_HOWDOI_TASK_BACKGROUND	= -112,
	VSCOLOR_HELP_HOWDOI_TASK_LINK	= -113,
	VSCOLOR_HELP_HOWDOI_TASK_TEXT	= -114,
	VSCOLOR_HELP_SEARCH_BACKGROUND	= -115,
	VSCOLOR_HELP_SEARCH_BORDER	= -116,
	VSCOLOR_HELP_SEARCH_FITLER_BACKGROUND	= -117,
	VSCOLOR_HELP_SEARCH_FITLER_BORDER	= -118,
	VSCOLOR_HELP_SEARCH_GRADIENT_BEGIN	= -119,
	VSCOLOR_HELP_SEARCH_GRADIENT_END	= -120,
	VSCOLOR_HELP_SEARCH_NAVIGATION_DISABLED	= -121,
	VSCOLOR_HELP_SEARCH_NAVIGATION_ENABLED	= -122,
	VSCOLOR_HELP_SEARCH_PANEL_RULES	= -123,
	VSCOLOR_HELP_SEARCH_PROVIDER_BACKGROUND	= -124,
	VSCOLOR_HELP_SEARCH_PROVIDER_ICON	= -125,
	VSCOLOR_HELP_SEARCH_PROVIDER_TEXT	= -126,
	VSCOLOR_HELP_SEARCH_RESULT_LINK_SELECTED	= -127,
	VSCOLOR_HELP_SEARCH_RESULT_LINK_UNSELECTED	= -128,
	VSCOLOR_HELP_SEARCH_RESULT_SELECTED_BACKGROUND	= -129,
	VSCOLOR_HELP_SEARCH_RESULT_SELECTED_TEXT	= -130,
	VSCOLOR_HELP_SEARCH_TEXT	= -131,
	VSCOLOR_WIZARD_ORIENTATIONPANEL_BACKGROUND	= -132,
	VSCOLOR_WIZARD_ORIENTATIONPANEL_TEXT	= -133,
	VSCOLOR_COMMANDBAR_HOVEROVERSELECTEDICON	= -134,
	VSCOLOR_LASTEX	= -134
    } 	VSSYSCOLOREX;

typedef 
enum __tagGRADIENTTYPE
    {	VSGRADIENT_SHELLBACKGROUND	= 1,
	VSGRADIENT_TOOLWIN_ACTIVE_TITLE_BAR	= 2,
	VSGRADIENT_TOOLWIN_INACTIVE_TITLE_BAR	= 3,
	VSGRADIENT_TOOLWIN_BACKGROUND	= 4,
	VSGRADIENT_FILETAB	= 5,
	VSGRADIENT_TOOLTAB	= 6,
	VSGRADIENT_TOOLBOX_HEADING	= 7,
	VSGRADIENT_HELP_SEARCH_BACKGROUND	= 8
    } 	GRADIENTTYPE;



extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0685_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0685_v0_0_s_ifspec;

#ifndef __IVsGradient_INTERFACE_DEFINED__
#define __IVsGradient_INTERFACE_DEFINED__

/* interface IVsGradient */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsGradient;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("fd3f680a-d5c1-437a-8a21-8084310bf037")
    IVsGradient : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE DrawGradient( 
            /* [in] */ HWND hwnd,
            /* [in] */ HDC hdc,
            /* [in] */ RECT *gradientRect,
            /* [in] */ RECT *sliceRect) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetGradientVector( 
            /* [in] */ int cVector,
            /* [size_is][out][in] */ COLORREF *rgVector) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsGradientVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsGradient * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsGradient * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsGradient * This);
        
        HRESULT ( STDMETHODCALLTYPE *DrawGradient )( 
            IVsGradient * This,
            /* [in] */ HWND hwnd,
            /* [in] */ HDC hdc,
            /* [in] */ RECT *gradientRect,
            /* [in] */ RECT *sliceRect);
        
        HRESULT ( STDMETHODCALLTYPE *GetGradientVector )( 
            IVsGradient * This,
            /* [in] */ int cVector,
            /* [size_is][out][in] */ COLORREF *rgVector);
        
        END_INTERFACE
    } IVsGradientVtbl;

    interface IVsGradient
    {
        CONST_VTBL struct IVsGradientVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsGradient_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsGradient_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsGradient_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsGradient_DrawGradient(This,hwnd,hdc,gradientRect,sliceRect)	\
    (This)->lpVtbl -> DrawGradient(This,hwnd,hdc,gradientRect,sliceRect)

#define IVsGradient_GetGradientVector(This,cVector,rgVector)	\
    (This)->lpVtbl -> GetGradientVector(This,cVector,rgVector)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsGradient_DrawGradient_Proxy( 
    IVsGradient * This,
    /* [in] */ HWND hwnd,
    /* [in] */ HDC hdc,
    /* [in] */ RECT *gradientRect,
    /* [in] */ RECT *sliceRect);


void __RPC_STUB IVsGradient_DrawGradient_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsGradient_GetGradientVector_Proxy( 
    IVsGradient * This,
    /* [in] */ int cVector,
    /* [size_is][out][in] */ COLORREF *rgVector);


void __RPC_STUB IVsGradient_GetGradientVector_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsGradient_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshell80_0686 */
/* [local] */ 


enum _VSCURSORTYPE
    {	VSCURSOR_POINTER	= 1,
	VSCURSOR_UPARROW	= 2,
	VSCURSOR_SPLITNS	= 3,
	VSCURSOR_SPLITEW	= 4,
	VSCURSOR_IBEAM	= 5,
	VSCURSOR_WAIT	= 6,
	VSCURSOR_CROSS	= 7,
	VSCURSOR_GRIP	= 8,
	VSCURSOR_DRAGSCRAP_MOVE	= 9,
	VSCURSOR_DRAGSCRAP_COPY	= 10,
	VSCURSOR_DRAGDOCUMENT_MOVE	= 11,
	VSCURSOR_DRAGDOCUMENT_COPY	= 12,
	VSCURSOR_DRAGNOEFFECT	= 13,
	VSCURSOR_SIZENS	= 14,
	VSCURSOR_SIZEEW	= 15,
	VSCURSOR_SIZENWSE	= 16,
	VSCURSOR_SIZENESW	= 17,
	VSCURSOR_SIZEALL	= 18
    } ;
typedef DWORD VSCURSORTYPE;



extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0686_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0686_v0_0_s_ifspec;

#ifndef __IVsUIShell2_INTERFACE_DEFINED__
#define __IVsUIShell2_INTERFACE_DEFINED__

/* interface IVsUIShell2 */
/* [object][version][uuid] */ 


EXTERN_C const IID IID_IVsUIShell2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4E6B6EF9-8E3D-4756-99E9-1192BAAD5496")
    IVsUIShell2 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetOpenFileNameViaDlgEx( 
            /* [out][in] */ VSOPENFILENAMEW *pOpenFileName,
            /* [in] */ LPCOLESTR pszHelpTopic) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSaveFileNameViaDlgEx( 
            /* [out][in] */ VSSAVEFILENAMEW *pSaveFileName,
            /* [in] */ LPCOLESTR pszHelpTopic) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDirectoryViaBrowseDlgEx( 
            /* [out][in] */ VSBROWSEINFOW *pBrowse,
            /* [in] */ LPCOLESTR pszHelpTopic,
            /* [in] */ LPCOLESTR pszOpenButtonLabel,
            /* [in] */ LPCOLESTR pszCeilingDir,
            /* [in] */ VSNSEBROWSEINFOW *pNSEBrowseInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SaveItemsViaDlg( 
            /* [in] */ UINT cItems,
            /* [size_is][in] */ VSSAVETREEITEM rgSaveItems[  ]) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVSSysColorEx( 
            /* [in] */ VSSYSCOLOREX dwSysColIndex,
            /* [out] */ DWORD *pdwRGBval) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateGradient( 
            /* [in] */ GRADIENTTYPE gradientType,
            /* [out] */ IVsGradient **pGradient) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVSCursor( 
            /* [in] */ VSCURSORTYPE cursor,
            /* [out] */ HCURSOR *phIcon) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsUIShell2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsUIShell2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsUIShell2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsUIShell2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetOpenFileNameViaDlgEx )( 
            IVsUIShell2 * This,
            /* [out][in] */ VSOPENFILENAMEW *pOpenFileName,
            /* [in] */ LPCOLESTR pszHelpTopic);
        
        HRESULT ( STDMETHODCALLTYPE *GetSaveFileNameViaDlgEx )( 
            IVsUIShell2 * This,
            /* [out][in] */ VSSAVEFILENAMEW *pSaveFileName,
            /* [in] */ LPCOLESTR pszHelpTopic);
        
        HRESULT ( STDMETHODCALLTYPE *GetDirectoryViaBrowseDlgEx )( 
            IVsUIShell2 * This,
            /* [out][in] */ VSBROWSEINFOW *pBrowse,
            /* [in] */ LPCOLESTR pszHelpTopic,
            /* [in] */ LPCOLESTR pszOpenButtonLabel,
            /* [in] */ LPCOLESTR pszCeilingDir,
            /* [in] */ VSNSEBROWSEINFOW *pNSEBrowseInfo);
        
        HRESULT ( STDMETHODCALLTYPE *SaveItemsViaDlg )( 
            IVsUIShell2 * This,
            /* [in] */ UINT cItems,
            /* [size_is][in] */ VSSAVETREEITEM rgSaveItems[  ]);
        
        HRESULT ( STDMETHODCALLTYPE *GetVSSysColorEx )( 
            IVsUIShell2 * This,
            /* [in] */ VSSYSCOLOREX dwSysColIndex,
            /* [out] */ DWORD *pdwRGBval);
        
        HRESULT ( STDMETHODCALLTYPE *CreateGradient )( 
            IVsUIShell2 * This,
            /* [in] */ GRADIENTTYPE gradientType,
            /* [out] */ IVsGradient **pGradient);
        
        HRESULT ( STDMETHODCALLTYPE *GetVSCursor )( 
            IVsUIShell2 * This,
            /* [in] */ VSCURSORTYPE cursor,
            /* [out] */ HCURSOR *phIcon);
        
        END_INTERFACE
    } IVsUIShell2Vtbl;

    interface IVsUIShell2
    {
        CONST_VTBL struct IVsUIShell2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsUIShell2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsUIShell2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsUIShell2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsUIShell2_GetOpenFileNameViaDlgEx(This,pOpenFileName,pszHelpTopic)	\
    (This)->lpVtbl -> GetOpenFileNameViaDlgEx(This,pOpenFileName,pszHelpTopic)

#define IVsUIShell2_GetSaveFileNameViaDlgEx(This,pSaveFileName,pszHelpTopic)	\
    (This)->lpVtbl -> GetSaveFileNameViaDlgEx(This,pSaveFileName,pszHelpTopic)

#define IVsUIShell2_GetDirectoryViaBrowseDlgEx(This,pBrowse,pszHelpTopic,pszOpenButtonLabel,pszCeilingDir,pNSEBrowseInfo)	\
    (This)->lpVtbl -> GetDirectoryViaBrowseDlgEx(This,pBrowse,pszHelpTopic,pszOpenButtonLabel,pszCeilingDir,pNSEBrowseInfo)

#define IVsUIShell2_SaveItemsViaDlg(This,cItems,rgSaveItems)	\
    (This)->lpVtbl -> SaveItemsViaDlg(This,cItems,rgSaveItems)

#define IVsUIShell2_GetVSSysColorEx(This,dwSysColIndex,pdwRGBval)	\
    (This)->lpVtbl -> GetVSSysColorEx(This,dwSysColIndex,pdwRGBval)

#define IVsUIShell2_CreateGradient(This,gradientType,pGradient)	\
    (This)->lpVtbl -> CreateGradient(This,gradientType,pGradient)

#define IVsUIShell2_GetVSCursor(This,cursor,phIcon)	\
    (This)->lpVtbl -> GetVSCursor(This,cursor,phIcon)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsUIShell2_GetOpenFileNameViaDlgEx_Proxy( 
    IVsUIShell2 * This,
    /* [out][in] */ VSOPENFILENAMEW *pOpenFileName,
    /* [in] */ LPCOLESTR pszHelpTopic);


void __RPC_STUB IVsUIShell2_GetOpenFileNameViaDlgEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsUIShell2_GetSaveFileNameViaDlgEx_Proxy( 
    IVsUIShell2 * This,
    /* [out][in] */ VSSAVEFILENAMEW *pSaveFileName,
    /* [in] */ LPCOLESTR pszHelpTopic);


void __RPC_STUB IVsUIShell2_GetSaveFileNameViaDlgEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsUIShell2_GetDirectoryViaBrowseDlgEx_Proxy( 
    IVsUIShell2 * This,
    /* [out][in] */ VSBROWSEINFOW *pBrowse,
    /* [in] */ LPCOLESTR pszHelpTopic,
    /* [in] */ LPCOLESTR pszOpenButtonLabel,
    /* [in] */ LPCOLESTR pszCeilingDir,
    /* [in] */ VSNSEBROWSEINFOW *pNSEBrowseInfo);


void __RPC_STUB IVsUIShell2_GetDirectoryViaBrowseDlgEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsUIShell2_SaveItemsViaDlg_Proxy( 
    IVsUIShell2 * This,
    /* [in] */ UINT cItems,
    /* [size_is][in] */ VSSAVETREEITEM rgSaveItems[  ]);


void __RPC_STUB IVsUIShell2_SaveItemsViaDlg_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsUIShell2_GetVSSysColorEx_Proxy( 
    IVsUIShell2 * This,
    /* [in] */ VSSYSCOLOREX dwSysColIndex,
    /* [out] */ DWORD *pdwRGBval);


void __RPC_STUB IVsUIShell2_GetVSSysColorEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsUIShell2_CreateGradient_Proxy( 
    IVsUIShell2 * This,
    /* [in] */ GRADIENTTYPE gradientType,
    /* [out] */ IVsGradient **pGradient);


void __RPC_STUB IVsUIShell2_CreateGradient_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsUIShell2_GetVSCursor_Proxy( 
    IVsUIShell2 * This,
    /* [in] */ VSCURSORTYPE cursor,
    /* [out] */ HCURSOR *phIcon);


void __RPC_STUB IVsUIShell2_GetVSCursor_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsUIShell2_INTERFACE_DEFINED__ */


#ifndef __IVsSupportItemHandoff2_INTERFACE_DEFINED__
#define __IVsSupportItemHandoff2_INTERFACE_DEFINED__

/* interface IVsSupportItemHandoff2 */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsSupportItemHandoff2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2AFA4F74-7A1A-4dee-8F99-46E74E5A3C0F")
    IVsSupportItemHandoff2 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnBeforeHandoffItem( 
            /* [in] */ VSITEMID itemid,
            /* [in] */ IVsProject3 *pProjDest) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsSupportItemHandoff2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsSupportItemHandoff2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsSupportItemHandoff2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsSupportItemHandoff2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnBeforeHandoffItem )( 
            IVsSupportItemHandoff2 * This,
            /* [in] */ VSITEMID itemid,
            /* [in] */ IVsProject3 *pProjDest);
        
        END_INTERFACE
    } IVsSupportItemHandoff2Vtbl;

    interface IVsSupportItemHandoff2
    {
        CONST_VTBL struct IVsSupportItemHandoff2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsSupportItemHandoff2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsSupportItemHandoff2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsSupportItemHandoff2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsSupportItemHandoff2_OnBeforeHandoffItem(This,itemid,pProjDest)	\
    (This)->lpVtbl -> OnBeforeHandoffItem(This,itemid,pProjDest)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsSupportItemHandoff2_OnBeforeHandoffItem_Proxy( 
    IVsSupportItemHandoff2 * This,
    /* [in] */ VSITEMID itemid,
    /* [in] */ IVsProject3 *pProjDest);


void __RPC_STUB IVsSupportItemHandoff2_OnBeforeHandoffItem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsSupportItemHandoff2_INTERFACE_DEFINED__ */


#ifndef __IVsLaunchPadOutputParser_INTERFACE_DEFINED__
#define __IVsLaunchPadOutputParser_INTERFACE_DEFINED__

/* interface IVsLaunchPadOutputParser */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsLaunchPadOutputParser;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A9832932-5F3B-487d-A80D-95115EADDAC3")
    IVsLaunchPadOutputParser : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ParseOutputStringForInfo( 
            /* [in] */ LPCOLESTR pszOutputString,
            /* [out] */ BSTR *pbstrFilename,
            /* [out] */ ULONG *pnLineNum,
            /* [out] */ ULONG *pnPriority,
            /* [out] */ BSTR *pbstrTaskItemText,
            /* [out] */ BSTR *pbstrHelpKeyword) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsLaunchPadOutputParserVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsLaunchPadOutputParser * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsLaunchPadOutputParser * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsLaunchPadOutputParser * This);
        
        HRESULT ( STDMETHODCALLTYPE *ParseOutputStringForInfo )( 
            IVsLaunchPadOutputParser * This,
            /* [in] */ LPCOLESTR pszOutputString,
            /* [out] */ BSTR *pbstrFilename,
            /* [out] */ ULONG *pnLineNum,
            /* [out] */ ULONG *pnPriority,
            /* [out] */ BSTR *pbstrTaskItemText,
            /* [out] */ BSTR *pbstrHelpKeyword);
        
        END_INTERFACE
    } IVsLaunchPadOutputParserVtbl;

    interface IVsLaunchPadOutputParser
    {
        CONST_VTBL struct IVsLaunchPadOutputParserVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsLaunchPadOutputParser_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsLaunchPadOutputParser_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsLaunchPadOutputParser_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsLaunchPadOutputParser_ParseOutputStringForInfo(This,pszOutputString,pbstrFilename,pnLineNum,pnPriority,pbstrTaskItemText,pbstrHelpKeyword)	\
    (This)->lpVtbl -> ParseOutputStringForInfo(This,pszOutputString,pbstrFilename,pnLineNum,pnPriority,pbstrTaskItemText,pbstrHelpKeyword)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsLaunchPadOutputParser_ParseOutputStringForInfo_Proxy( 
    IVsLaunchPadOutputParser * This,
    /* [in] */ LPCOLESTR pszOutputString,
    /* [out] */ BSTR *pbstrFilename,
    /* [out] */ ULONG *pnLineNum,
    /* [out] */ ULONG *pnPriority,
    /* [out] */ BSTR *pbstrTaskItemText,
    /* [out] */ BSTR *pbstrHelpKeyword);


void __RPC_STUB IVsLaunchPadOutputParser_ParseOutputStringForInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsLaunchPadOutputParser_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshell80_0689 */
/* [local] */ 

typedef /* [public] */ 
enum __MIDL___MIDL_itf_vsshell80_0689_0001
    {	LPF_TreatOutputAsUnicode	= 0x10
    } 	_LAUNCHPAD_FLAGS2;

typedef DWORD LAUNCHPAD_FLAGS2;



extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0689_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0689_v0_0_s_ifspec;

#ifndef __IVsLaunchPad2_INTERFACE_DEFINED__
#define __IVsLaunchPad2_INTERFACE_DEFINED__

/* interface IVsLaunchPad2 */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsLaunchPad2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0DBD685A-0A10-4e25-B88E-02E58E60785E")
    IVsLaunchPad2 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ExecCommandEx( 
            /* [in] */ LPCOLESTR pszApplicationName,
            /* [in] */ LPCOLESTR pszCommandLine,
            /* [in] */ LPCOLESTR pszWorkingDir,
            /* [in] */ LAUNCHPAD_FLAGS2 lpf,
            /* [in] */ IVsOutputWindowPane *pOutputWindowPane,
            /* [in] */ ULONG nTaskItemCategory,
            /* [in] */ ULONG nTaskItemBitmap,
            /* [in] */ LPCOLESTR pszTaskListSubcategory,
            /* [in] */ IVsLaunchPadEvents *pVsLaunchPadEvents,
            /* [in] */ IVsLaunchPadOutputParser *pOutputParser,
            /* [out] */ DWORD *pdwProcessExitCode,
            /* [out] */ BSTR *pbstrOutput) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsLaunchPad2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsLaunchPad2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsLaunchPad2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsLaunchPad2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *ExecCommandEx )( 
            IVsLaunchPad2 * This,
            /* [in] */ LPCOLESTR pszApplicationName,
            /* [in] */ LPCOLESTR pszCommandLine,
            /* [in] */ LPCOLESTR pszWorkingDir,
            /* [in] */ LAUNCHPAD_FLAGS2 lpf,
            /* [in] */ IVsOutputWindowPane *pOutputWindowPane,
            /* [in] */ ULONG nTaskItemCategory,
            /* [in] */ ULONG nTaskItemBitmap,
            /* [in] */ LPCOLESTR pszTaskListSubcategory,
            /* [in] */ IVsLaunchPadEvents *pVsLaunchPadEvents,
            /* [in] */ IVsLaunchPadOutputParser *pOutputParser,
            /* [out] */ DWORD *pdwProcessExitCode,
            /* [out] */ BSTR *pbstrOutput);
        
        END_INTERFACE
    } IVsLaunchPad2Vtbl;

    interface IVsLaunchPad2
    {
        CONST_VTBL struct IVsLaunchPad2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsLaunchPad2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsLaunchPad2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsLaunchPad2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsLaunchPad2_ExecCommandEx(This,pszApplicationName,pszCommandLine,pszWorkingDir,lpf,pOutputWindowPane,nTaskItemCategory,nTaskItemBitmap,pszTaskListSubcategory,pVsLaunchPadEvents,pOutputParser,pdwProcessExitCode,pbstrOutput)	\
    (This)->lpVtbl -> ExecCommandEx(This,pszApplicationName,pszCommandLine,pszWorkingDir,lpf,pOutputWindowPane,nTaskItemCategory,nTaskItemBitmap,pszTaskListSubcategory,pVsLaunchPadEvents,pOutputParser,pdwProcessExitCode,pbstrOutput)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsLaunchPad2_ExecCommandEx_Proxy( 
    IVsLaunchPad2 * This,
    /* [in] */ LPCOLESTR pszApplicationName,
    /* [in] */ LPCOLESTR pszCommandLine,
    /* [in] */ LPCOLESTR pszWorkingDir,
    /* [in] */ LAUNCHPAD_FLAGS2 lpf,
    /* [in] */ IVsOutputWindowPane *pOutputWindowPane,
    /* [in] */ ULONG nTaskItemCategory,
    /* [in] */ ULONG nTaskItemBitmap,
    /* [in] */ LPCOLESTR pszTaskListSubcategory,
    /* [in] */ IVsLaunchPadEvents *pVsLaunchPadEvents,
    /* [in] */ IVsLaunchPadOutputParser *pOutputParser,
    /* [out] */ DWORD *pdwProcessExitCode,
    /* [out] */ BSTR *pbstrOutput);


void __RPC_STUB IVsLaunchPad2_ExecCommandEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsLaunchPad2_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshell80_0690 */
/* [local] */ 


enum __VSPROJSLNDLGFLAGS
    {	PSDF_OpenSolutionDialog	= 0x1,
	PSDF_OpenProjectDialog	= 0x2,
	PSDF_AddExistingProjectDialog	= 0x4,
	PSDF_DefaultToAllProjectsFilter	= 0x8,
	PSDF_DirectoryPicker	= 0x10
    } ;
typedef DWORD VSPROJSLNDLGFLAGS;



extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0690_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0690_v0_0_s_ifspec;

#ifndef __IVsOpenProjectOrSolutionDlg_INTERFACE_DEFINED__
#define __IVsOpenProjectOrSolutionDlg_INTERFACE_DEFINED__

/* interface IVsOpenProjectOrSolutionDlg */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsOpenProjectOrSolutionDlg;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("09b17094-f50c-40e0-8ab5-57c22a786596")
    IVsOpenProjectOrSolutionDlg : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OpenProjectOrSolutionViaDlg( 
            /* [in] */ VSPROJSLNDLGFLAGS grfProjSlnDlgFlags,
            /* [in] */ LPCOLESTR pwzStartDirectory,
            /* [in] */ LPCOLESTR pwzDialogTitle,
            /* [in] */ REFGUID rguidProjectType) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsOpenProjectOrSolutionDlgVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsOpenProjectOrSolutionDlg * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsOpenProjectOrSolutionDlg * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsOpenProjectOrSolutionDlg * This);
        
        HRESULT ( STDMETHODCALLTYPE *OpenProjectOrSolutionViaDlg )( 
            IVsOpenProjectOrSolutionDlg * This,
            /* [in] */ VSPROJSLNDLGFLAGS grfProjSlnDlgFlags,
            /* [in] */ LPCOLESTR pwzStartDirectory,
            /* [in] */ LPCOLESTR pwzDialogTitle,
            /* [in] */ REFGUID rguidProjectType);
        
        END_INTERFACE
    } IVsOpenProjectOrSolutionDlgVtbl;

    interface IVsOpenProjectOrSolutionDlg
    {
        CONST_VTBL struct IVsOpenProjectOrSolutionDlgVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsOpenProjectOrSolutionDlg_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsOpenProjectOrSolutionDlg_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsOpenProjectOrSolutionDlg_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsOpenProjectOrSolutionDlg_OpenProjectOrSolutionViaDlg(This,grfProjSlnDlgFlags,pwzStartDirectory,pwzDialogTitle,rguidProjectType)	\
    (This)->lpVtbl -> OpenProjectOrSolutionViaDlg(This,grfProjSlnDlgFlags,pwzStartDirectory,pwzDialogTitle,rguidProjectType)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsOpenProjectOrSolutionDlg_OpenProjectOrSolutionViaDlg_Proxy( 
    IVsOpenProjectOrSolutionDlg * This,
    /* [in] */ VSPROJSLNDLGFLAGS grfProjSlnDlgFlags,
    /* [in] */ LPCOLESTR pwzStartDirectory,
    /* [in] */ LPCOLESTR pwzDialogTitle,
    /* [in] */ REFGUID rguidProjectType);


void __RPC_STUB IVsOpenProjectOrSolutionDlg_OpenProjectOrSolutionViaDlg_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsOpenProjectOrSolutionDlg_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshell80_0691 */
/* [local] */ 

#define SID_SVsOpenProjectOrSolutionDlg IID_IVsOpenProjectOrSolutionDlg


extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0691_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0691_v0_0_s_ifspec;

#ifndef __IVsCreateAggregateProject_INTERFACE_DEFINED__
#define __IVsCreateAggregateProject_INTERFACE_DEFINED__

/* interface IVsCreateAggregateProject */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsCreateAggregateProject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("84f41718-d169-4567-a0cd-b3cbcf58ff71")
    IVsCreateAggregateProject : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CreateAggregateProject( 
            /* [in] */ LPCOLESTR pszProjectTypeGuids,
            /* [in] */ LPCOLESTR pszFilename,
            /* [in] */ LPCOLESTR pszLocation,
            /* [in] */ LPCOLESTR pszName,
            /* [in] */ VSCREATEPROJFLAGS grfCreateFlags,
            /* [in] */ REFIID iidProject,
            /* [iid_is][out] */ void **ppvProject) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsCreateAggregateProjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsCreateAggregateProject * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsCreateAggregateProject * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsCreateAggregateProject * This);
        
        HRESULT ( STDMETHODCALLTYPE *CreateAggregateProject )( 
            IVsCreateAggregateProject * This,
            /* [in] */ LPCOLESTR pszProjectTypeGuids,
            /* [in] */ LPCOLESTR pszFilename,
            /* [in] */ LPCOLESTR pszLocation,
            /* [in] */ LPCOLESTR pszName,
            /* [in] */ VSCREATEPROJFLAGS grfCreateFlags,
            /* [in] */ REFIID iidProject,
            /* [iid_is][out] */ void **ppvProject);
        
        END_INTERFACE
    } IVsCreateAggregateProjectVtbl;

    interface IVsCreateAggregateProject
    {
        CONST_VTBL struct IVsCreateAggregateProjectVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsCreateAggregateProject_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsCreateAggregateProject_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsCreateAggregateProject_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsCreateAggregateProject_CreateAggregateProject(This,pszProjectTypeGuids,pszFilename,pszLocation,pszName,grfCreateFlags,iidProject,ppvProject)	\
    (This)->lpVtbl -> CreateAggregateProject(This,pszProjectTypeGuids,pszFilename,pszLocation,pszName,grfCreateFlags,iidProject,ppvProject)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsCreateAggregateProject_CreateAggregateProject_Proxy( 
    IVsCreateAggregateProject * This,
    /* [in] */ LPCOLESTR pszProjectTypeGuids,
    /* [in] */ LPCOLESTR pszFilename,
    /* [in] */ LPCOLESTR pszLocation,
    /* [in] */ LPCOLESTR pszName,
    /* [in] */ VSCREATEPROJFLAGS grfCreateFlags,
    /* [in] */ REFIID iidProject,
    /* [iid_is][out] */ void **ppvProject);


void __RPC_STUB IVsCreateAggregateProject_CreateAggregateProject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsCreateAggregateProject_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshell80_0692 */
/* [local] */ 

#define SID_SVsCreateAggregateProject IID_IVsCreateAggregateProject


extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0692_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0692_v0_0_s_ifspec;

#ifndef __IVsAggregatableProject_INTERFACE_DEFINED__
#define __IVsAggregatableProject_INTERFACE_DEFINED__

/* interface IVsAggregatableProject */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsAggregatableProject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ffb2e715-7312-4b93-83d7-d37bcc561c90")
    IVsAggregatableProject : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetInnerProject( 
            /* [in] */ IUnknown *punkInner) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InitializeForOuter( 
            /* [in] */ LPCOLESTR pszFilename,
            /* [in] */ LPCOLESTR pszLocation,
            /* [in] */ LPCOLESTR pszName,
            /* [in] */ VSCREATEPROJFLAGS grfCreateFlags,
            /* [in] */ REFIID iidProject,
            /* [iid_is][out] */ void **ppvProject,
            /* [out] */ BOOL *pfCanceled) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAggregateProjectTypeGuids( 
            /* [out] */ BSTR *pbstrProjTypeGuids) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAggregateProjectTypeGuids( 
            /* [in] */ LPCOLESTR lpstrProjTypeGuids) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsAggregatableProjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsAggregatableProject * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsAggregatableProject * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsAggregatableProject * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetInnerProject )( 
            IVsAggregatableProject * This,
            /* [in] */ IUnknown *punkInner);
        
        HRESULT ( STDMETHODCALLTYPE *InitializeForOuter )( 
            IVsAggregatableProject * This,
            /* [in] */ LPCOLESTR pszFilename,
            /* [in] */ LPCOLESTR pszLocation,
            /* [in] */ LPCOLESTR pszName,
            /* [in] */ VSCREATEPROJFLAGS grfCreateFlags,
            /* [in] */ REFIID iidProject,
            /* [iid_is][out] */ void **ppvProject,
            /* [out] */ BOOL *pfCanceled);
        
        HRESULT ( STDMETHODCALLTYPE *GetAggregateProjectTypeGuids )( 
            IVsAggregatableProject * This,
            /* [out] */ BSTR *pbstrProjTypeGuids);
        
        HRESULT ( STDMETHODCALLTYPE *SetAggregateProjectTypeGuids )( 
            IVsAggregatableProject * This,
            /* [in] */ LPCOLESTR lpstrProjTypeGuids);
        
        END_INTERFACE
    } IVsAggregatableProjectVtbl;

    interface IVsAggregatableProject
    {
        CONST_VTBL struct IVsAggregatableProjectVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsAggregatableProject_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsAggregatableProject_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsAggregatableProject_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsAggregatableProject_SetInnerProject(This,punkInner)	\
    (This)->lpVtbl -> SetInnerProject(This,punkInner)

#define IVsAggregatableProject_InitializeForOuter(This,pszFilename,pszLocation,pszName,grfCreateFlags,iidProject,ppvProject,pfCanceled)	\
    (This)->lpVtbl -> InitializeForOuter(This,pszFilename,pszLocation,pszName,grfCreateFlags,iidProject,ppvProject,pfCanceled)

#define IVsAggregatableProject_GetAggregateProjectTypeGuids(This,pbstrProjTypeGuids)	\
    (This)->lpVtbl -> GetAggregateProjectTypeGuids(This,pbstrProjTypeGuids)

#define IVsAggregatableProject_SetAggregateProjectTypeGuids(This,lpstrProjTypeGuids)	\
    (This)->lpVtbl -> SetAggregateProjectTypeGuids(This,lpstrProjTypeGuids)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsAggregatableProject_SetInnerProject_Proxy( 
    IVsAggregatableProject * This,
    /* [in] */ IUnknown *punkInner);


void __RPC_STUB IVsAggregatableProject_SetInnerProject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsAggregatableProject_InitializeForOuter_Proxy( 
    IVsAggregatableProject * This,
    /* [in] */ LPCOLESTR pszFilename,
    /* [in] */ LPCOLESTR pszLocation,
    /* [in] */ LPCOLESTR pszName,
    /* [in] */ VSCREATEPROJFLAGS grfCreateFlags,
    /* [in] */ REFIID iidProject,
    /* [iid_is][out] */ void **ppvProject,
    /* [out] */ BOOL *pfCanceled);


void __RPC_STUB IVsAggregatableProject_InitializeForOuter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsAggregatableProject_GetAggregateProjectTypeGuids_Proxy( 
    IVsAggregatableProject * This,
    /* [out] */ BSTR *pbstrProjTypeGuids);


void __RPC_STUB IVsAggregatableProject_GetAggregateProjectTypeGuids_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsAggregatableProject_SetAggregateProjectTypeGuids_Proxy( 
    IVsAggregatableProject * This,
    /* [in] */ LPCOLESTR lpstrProjTypeGuids);


void __RPC_STUB IVsAggregatableProject_SetAggregateProjectTypeGuids_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsAggregatableProject_INTERFACE_DEFINED__ */


#ifndef __IVsAggregatableProjectFactory_INTERFACE_DEFINED__
#define __IVsAggregatableProjectFactory_INTERFACE_DEFINED__

/* interface IVsAggregatableProjectFactory */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsAggregatableProjectFactory;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("44569501-2ad0-4966-9bac-12b799a1ced6")
    IVsAggregatableProjectFactory : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetAggregateProjectType( 
            /* [in] */ LPCOLESTR pszFilename,
            /* [out] */ BSTR *pbstrProjTypeGuid) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PreCreateForOuter( 
            /* [in] */ IUnknown *punkOuter,
            /* [out] */ IUnknown **ppunkProject) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsAggregatableProjectFactoryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsAggregatableProjectFactory * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsAggregatableProjectFactory * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsAggregatableProjectFactory * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetAggregateProjectType )( 
            IVsAggregatableProjectFactory * This,
            /* [in] */ LPCOLESTR pszFilename,
            /* [out] */ BSTR *pbstrProjTypeGuid);
        
        HRESULT ( STDMETHODCALLTYPE *PreCreateForOuter )( 
            IVsAggregatableProjectFactory * This,
            /* [in] */ IUnknown *punkOuter,
            /* [out] */ IUnknown **ppunkProject);
        
        END_INTERFACE
    } IVsAggregatableProjectFactoryVtbl;

    interface IVsAggregatableProjectFactory
    {
        CONST_VTBL struct IVsAggregatableProjectFactoryVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsAggregatableProjectFactory_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsAggregatableProjectFactory_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsAggregatableProjectFactory_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsAggregatableProjectFactory_GetAggregateProjectType(This,pszFilename,pbstrProjTypeGuid)	\
    (This)->lpVtbl -> GetAggregateProjectType(This,pszFilename,pbstrProjTypeGuid)

#define IVsAggregatableProjectFactory_PreCreateForOuter(This,punkOuter,ppunkProject)	\
    (This)->lpVtbl -> PreCreateForOuter(This,punkOuter,ppunkProject)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsAggregatableProjectFactory_GetAggregateProjectType_Proxy( 
    IVsAggregatableProjectFactory * This,
    /* [in] */ LPCOLESTR pszFilename,
    /* [out] */ BSTR *pbstrProjTypeGuid);


void __RPC_STUB IVsAggregatableProjectFactory_GetAggregateProjectType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsAggregatableProjectFactory_PreCreateForOuter_Proxy( 
    IVsAggregatableProjectFactory * This,
    /* [in] */ IUnknown *punkOuter,
    /* [out] */ IUnknown **ppunkProject);


void __RPC_STUB IVsAggregatableProjectFactory_PreCreateForOuter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsAggregatableProjectFactory_INTERFACE_DEFINED__ */


#ifndef __IVsParentProject2_INTERFACE_DEFINED__
#define __IVsParentProject2_INTERFACE_DEFINED__

/* interface IVsParentProject2 */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsParentProject2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D63BB7D7-D7A0-4c02-AA85-7E9233797CDB")
    IVsParentProject2 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CreateNestedProject( 
            /* [in] */ VSITEMID itemidLoc,
            /* [in] */ REFGUID rguidProjectType,
            /* [in] */ LPCOLESTR lpszMoniker,
            /* [in] */ LPCOLESTR lpszLocation,
            /* [in] */ LPCOLESTR lpszName,
            /* [in] */ VSCREATEPROJFLAGS grfCreateFlags,
            /* [in] */ REFIID iidProject,
            /* [iid_is][out] */ void **ppProject) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddNestedSolution( 
            /* [in] */ VSITEMID itemidLoc,
            /* [in] */ VSSLNOPENOPTIONS grfOpenOpts,
            /* [in] */ LPCOLESTR pszFilename) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsParentProject2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsParentProject2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsParentProject2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsParentProject2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *CreateNestedProject )( 
            IVsParentProject2 * This,
            /* [in] */ VSITEMID itemidLoc,
            /* [in] */ REFGUID rguidProjectType,
            /* [in] */ LPCOLESTR lpszMoniker,
            /* [in] */ LPCOLESTR lpszLocation,
            /* [in] */ LPCOLESTR lpszName,
            /* [in] */ VSCREATEPROJFLAGS grfCreateFlags,
            /* [in] */ REFIID iidProject,
            /* [iid_is][out] */ void **ppProject);
        
        HRESULT ( STDMETHODCALLTYPE *AddNestedSolution )( 
            IVsParentProject2 * This,
            /* [in] */ VSITEMID itemidLoc,
            /* [in] */ VSSLNOPENOPTIONS grfOpenOpts,
            /* [in] */ LPCOLESTR pszFilename);
        
        END_INTERFACE
    } IVsParentProject2Vtbl;

    interface IVsParentProject2
    {
        CONST_VTBL struct IVsParentProject2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsParentProject2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsParentProject2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsParentProject2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsParentProject2_CreateNestedProject(This,itemidLoc,rguidProjectType,lpszMoniker,lpszLocation,lpszName,grfCreateFlags,iidProject,ppProject)	\
    (This)->lpVtbl -> CreateNestedProject(This,itemidLoc,rguidProjectType,lpszMoniker,lpszLocation,lpszName,grfCreateFlags,iidProject,ppProject)

#define IVsParentProject2_AddNestedSolution(This,itemidLoc,grfOpenOpts,pszFilename)	\
    (This)->lpVtbl -> AddNestedSolution(This,itemidLoc,grfOpenOpts,pszFilename)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsParentProject2_CreateNestedProject_Proxy( 
    IVsParentProject2 * This,
    /* [in] */ VSITEMID itemidLoc,
    /* [in] */ REFGUID rguidProjectType,
    /* [in] */ LPCOLESTR lpszMoniker,
    /* [in] */ LPCOLESTR lpszLocation,
    /* [in] */ LPCOLESTR lpszName,
    /* [in] */ VSCREATEPROJFLAGS grfCreateFlags,
    /* [in] */ REFIID iidProject,
    /* [iid_is][out] */ void **ppProject);


void __RPC_STUB IVsParentProject2_CreateNestedProject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsParentProject2_AddNestedSolution_Proxy( 
    IVsParentProject2 * This,
    /* [in] */ VSITEMID itemidLoc,
    /* [in] */ VSSLNOPENOPTIONS grfOpenOpts,
    /* [in] */ LPCOLESTR pszFilename);


void __RPC_STUB IVsParentProject2_AddNestedSolution_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsParentProject2_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshell80_0695 */
/* [local] */ 


enum _PersistStorageType
    {	PST_PROJECT_FILE	= 1,
	PST_USER_FILE	= 2
    } ;
typedef DWORD PersistStorageType;



extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0695_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0695_v0_0_s_ifspec;

#ifndef __IVsBuildPropertyStorage_INTERFACE_DEFINED__
#define __IVsBuildPropertyStorage_INTERFACE_DEFINED__

/* interface IVsBuildPropertyStorage */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsBuildPropertyStorage;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E7355FDF-A118-48f5-9655-7EFD9D2DC352")
    IVsBuildPropertyStorage : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetPropertyValue( 
            /* [in] */ LPCOLESTR pszPropName,
            /* [in] */ LPCOLESTR pszConfigName,
            /* [in] */ PersistStorageType storage,
            /* [retval][out] */ BSTR *pbstrPropValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPropertyValue( 
            /* [in] */ LPCOLESTR pszPropName,
            /* [in] */ LPCOLESTR pszConfigName,
            /* [in] */ PersistStorageType storage,
            /* [in] */ LPCOLESTR pszPropValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveProperty( 
            /* [in] */ LPCOLESTR pszPropName,
            /* [in] */ LPCOLESTR pszConfigName,
            /* [in] */ PersistStorageType storage) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsBuildPropertyStorageVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsBuildPropertyStorage * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsBuildPropertyStorage * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsBuildPropertyStorage * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetPropertyValue )( 
            IVsBuildPropertyStorage * This,
            /* [in] */ LPCOLESTR pszPropName,
            /* [in] */ LPCOLESTR pszConfigName,
            /* [in] */ PersistStorageType storage,
            /* [retval][out] */ BSTR *pbstrPropValue);
        
        HRESULT ( STDMETHODCALLTYPE *SetPropertyValue )( 
            IVsBuildPropertyStorage * This,
            /* [in] */ LPCOLESTR pszPropName,
            /* [in] */ LPCOLESTR pszConfigName,
            /* [in] */ PersistStorageType storage,
            /* [in] */ LPCOLESTR pszPropValue);
        
        HRESULT ( STDMETHODCALLTYPE *RemoveProperty )( 
            IVsBuildPropertyStorage * This,
            /* [in] */ LPCOLESTR pszPropName,
            /* [in] */ LPCOLESTR pszConfigName,
            /* [in] */ PersistStorageType storage);
        
        END_INTERFACE
    } IVsBuildPropertyStorageVtbl;

    interface IVsBuildPropertyStorage
    {
        CONST_VTBL struct IVsBuildPropertyStorageVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsBuildPropertyStorage_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsBuildPropertyStorage_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsBuildPropertyStorage_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsBuildPropertyStorage_GetPropertyValue(This,pszPropName,pszConfigName,storage,pbstrPropValue)	\
    (This)->lpVtbl -> GetPropertyValue(This,pszPropName,pszConfigName,storage,pbstrPropValue)

#define IVsBuildPropertyStorage_SetPropertyValue(This,pszPropName,pszConfigName,storage,pszPropValue)	\
    (This)->lpVtbl -> SetPropertyValue(This,pszPropName,pszConfigName,storage,pszPropValue)

#define IVsBuildPropertyStorage_RemoveProperty(This,pszPropName,pszConfigName,storage)	\
    (This)->lpVtbl -> RemoveProperty(This,pszPropName,pszConfigName,storage)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsBuildPropertyStorage_GetPropertyValue_Proxy( 
    IVsBuildPropertyStorage * This,
    /* [in] */ LPCOLESTR pszPropName,
    /* [in] */ LPCOLESTR pszConfigName,
    /* [in] */ PersistStorageType storage,
    /* [retval][out] */ BSTR *pbstrPropValue);


void __RPC_STUB IVsBuildPropertyStorage_GetPropertyValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsBuildPropertyStorage_SetPropertyValue_Proxy( 
    IVsBuildPropertyStorage * This,
    /* [in] */ LPCOLESTR pszPropName,
    /* [in] */ LPCOLESTR pszConfigName,
    /* [in] */ PersistStorageType storage,
    /* [in] */ LPCOLESTR pszPropValue);


void __RPC_STUB IVsBuildPropertyStorage_SetPropertyValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsBuildPropertyStorage_RemoveProperty_Proxy( 
    IVsBuildPropertyStorage * This,
    /* [in] */ LPCOLESTR pszPropName,
    /* [in] */ LPCOLESTR pszConfigName,
    /* [in] */ PersistStorageType storage);


void __RPC_STUB IVsBuildPropertyStorage_RemoveProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsBuildPropertyStorage_INTERFACE_DEFINED__ */


#ifndef __IVsProjectBuildSystem_INTERFACE_DEFINED__
#define __IVsProjectBuildSystem_INTERFACE_DEFINED__

/* interface IVsProjectBuildSystem */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsProjectBuildSystem;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("eb0718c0-e050-4657-872b-e845cd4f617b")
    IVsProjectBuildSystem : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetHostObject( 
            /* [in] */ LPCOLESTR pszTargetName,
            /* [in] */ LPCOLESTR pszTaskName,
            /* [in] */ IUnknown *punkHostObject) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StartBatchEdit( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EndBatchEdit( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CancelBatchEdit( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsProjectBuildSystemVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsProjectBuildSystem * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsProjectBuildSystem * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsProjectBuildSystem * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetHostObject )( 
            IVsProjectBuildSystem * This,
            /* [in] */ LPCOLESTR pszTargetName,
            /* [in] */ LPCOLESTR pszTaskName,
            /* [in] */ IUnknown *punkHostObject);
        
        HRESULT ( STDMETHODCALLTYPE *StartBatchEdit )( 
            IVsProjectBuildSystem * This);
        
        HRESULT ( STDMETHODCALLTYPE *EndBatchEdit )( 
            IVsProjectBuildSystem * This);
        
        HRESULT ( STDMETHODCALLTYPE *CancelBatchEdit )( 
            IVsProjectBuildSystem * This);
        
        END_INTERFACE
    } IVsProjectBuildSystemVtbl;

    interface IVsProjectBuildSystem
    {
        CONST_VTBL struct IVsProjectBuildSystemVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsProjectBuildSystem_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsProjectBuildSystem_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsProjectBuildSystem_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsProjectBuildSystem_SetHostObject(This,pszTargetName,pszTaskName,punkHostObject)	\
    (This)->lpVtbl -> SetHostObject(This,pszTargetName,pszTaskName,punkHostObject)

#define IVsProjectBuildSystem_StartBatchEdit(This)	\
    (This)->lpVtbl -> StartBatchEdit(This)

#define IVsProjectBuildSystem_EndBatchEdit(This)	\
    (This)->lpVtbl -> EndBatchEdit(This)

#define IVsProjectBuildSystem_CancelBatchEdit(This)	\
    (This)->lpVtbl -> CancelBatchEdit(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsProjectBuildSystem_SetHostObject_Proxy( 
    IVsProjectBuildSystem * This,
    /* [in] */ LPCOLESTR pszTargetName,
    /* [in] */ LPCOLESTR pszTaskName,
    /* [in] */ IUnknown *punkHostObject);


void __RPC_STUB IVsProjectBuildSystem_SetHostObject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsProjectBuildSystem_StartBatchEdit_Proxy( 
    IVsProjectBuildSystem * This);


void __RPC_STUB IVsProjectBuildSystem_StartBatchEdit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsProjectBuildSystem_EndBatchEdit_Proxy( 
    IVsProjectBuildSystem * This);


void __RPC_STUB IVsProjectBuildSystem_EndBatchEdit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsProjectBuildSystem_CancelBatchEdit_Proxy( 
    IVsProjectBuildSystem * This);


void __RPC_STUB IVsProjectBuildSystem_CancelBatchEdit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsProjectBuildSystem_INTERFACE_DEFINED__ */


#ifndef __IPersistXMLFragment_INTERFACE_DEFINED__
#define __IPersistXMLFragment_INTERFACE_DEFINED__

/* interface IPersistXMLFragment */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IPersistXMLFragment;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6B0C8632-6F01-4e54-9645-FFE82A2F4FE9")
    IPersistXMLFragment : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE InitNew( 
            /* [in] */ REFGUID guidFlavor,
            /* [in] */ PersistStorageType storage) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsFragmentDirty( 
            /* [in] */ PersistStorageType storage,
            /* [out] */ BOOL *pfDirty) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Load( 
            /* [in] */ REFGUID guidFlavor,
            /* [in] */ PersistStorageType storage,
            /* [in] */ LPCOLESTR pszXMLFragment) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Save( 
            /* [in] */ REFGUID guidFlavor,
            /* [in] */ PersistStorageType storage,
            /* [out] */ BSTR *pbstrXMLFragment,
            /* [in] */ BOOL fClearDirty) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IPersistXMLFragmentVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPersistXMLFragment * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPersistXMLFragment * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPersistXMLFragment * This);
        
        HRESULT ( STDMETHODCALLTYPE *InitNew )( 
            IPersistXMLFragment * This,
            /* [in] */ REFGUID guidFlavor,
            /* [in] */ PersistStorageType storage);
        
        HRESULT ( STDMETHODCALLTYPE *IsFragmentDirty )( 
            IPersistXMLFragment * This,
            /* [in] */ PersistStorageType storage,
            /* [out] */ BOOL *pfDirty);
        
        HRESULT ( STDMETHODCALLTYPE *Load )( 
            IPersistXMLFragment * This,
            /* [in] */ REFGUID guidFlavor,
            /* [in] */ PersistStorageType storage,
            /* [in] */ LPCOLESTR pszXMLFragment);
        
        HRESULT ( STDMETHODCALLTYPE *Save )( 
            IPersistXMLFragment * This,
            /* [in] */ REFGUID guidFlavor,
            /* [in] */ PersistStorageType storage,
            /* [out] */ BSTR *pbstrXMLFragment,
            /* [in] */ BOOL fClearDirty);
        
        END_INTERFACE
    } IPersistXMLFragmentVtbl;

    interface IPersistXMLFragment
    {
        CONST_VTBL struct IPersistXMLFragmentVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPersistXMLFragment_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPersistXMLFragment_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPersistXMLFragment_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IPersistXMLFragment_InitNew(This,guidFlavor,storage)	\
    (This)->lpVtbl -> InitNew(This,guidFlavor,storage)

#define IPersistXMLFragment_IsFragmentDirty(This,storage,pfDirty)	\
    (This)->lpVtbl -> IsFragmentDirty(This,storage,pfDirty)

#define IPersistXMLFragment_Load(This,guidFlavor,storage,pszXMLFragment)	\
    (This)->lpVtbl -> Load(This,guidFlavor,storage,pszXMLFragment)

#define IPersistXMLFragment_Save(This,guidFlavor,storage,pbstrXMLFragment,fClearDirty)	\
    (This)->lpVtbl -> Save(This,guidFlavor,storage,pbstrXMLFragment,fClearDirty)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IPersistXMLFragment_InitNew_Proxy( 
    IPersistXMLFragment * This,
    /* [in] */ REFGUID guidFlavor,
    /* [in] */ PersistStorageType storage);


void __RPC_STUB IPersistXMLFragment_InitNew_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPersistXMLFragment_IsFragmentDirty_Proxy( 
    IPersistXMLFragment * This,
    /* [in] */ PersistStorageType storage,
    /* [out] */ BOOL *pfDirty);


void __RPC_STUB IPersistXMLFragment_IsFragmentDirty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPersistXMLFragment_Load_Proxy( 
    IPersistXMLFragment * This,
    /* [in] */ REFGUID guidFlavor,
    /* [in] */ PersistStorageType storage,
    /* [in] */ LPCOLESTR pszXMLFragment);


void __RPC_STUB IPersistXMLFragment_Load_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IPersistXMLFragment_Save_Proxy( 
    IPersistXMLFragment * This,
    /* [in] */ REFGUID guidFlavor,
    /* [in] */ PersistStorageType storage,
    /* [out] */ BSTR *pbstrXMLFragment,
    /* [in] */ BOOL fClearDirty);


void __RPC_STUB IPersistXMLFragment_Save_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IPersistXMLFragment_INTERFACE_DEFINED__ */


#ifndef __IVsProjectFlavorCfg_INTERFACE_DEFINED__
#define __IVsProjectFlavorCfg_INTERFACE_DEFINED__

/* interface IVsProjectFlavorCfg */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsProjectFlavorCfg;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3bffc423-6c82-46c0-af2a-79a3ed3eda93")
    IVsProjectFlavorCfg : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE get_CfgType( 
            /* [in] */ REFIID iidCfg,
            /* [iid_is][out] */ void **ppCfg) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsProjectFlavorCfgVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsProjectFlavorCfg * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsProjectFlavorCfg * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsProjectFlavorCfg * This);
        
        HRESULT ( STDMETHODCALLTYPE *get_CfgType )( 
            IVsProjectFlavorCfg * This,
            /* [in] */ REFIID iidCfg,
            /* [iid_is][out] */ void **ppCfg);
        
        HRESULT ( STDMETHODCALLTYPE *Close )( 
            IVsProjectFlavorCfg * This);
        
        END_INTERFACE
    } IVsProjectFlavorCfgVtbl;

    interface IVsProjectFlavorCfg
    {
        CONST_VTBL struct IVsProjectFlavorCfgVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsProjectFlavorCfg_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsProjectFlavorCfg_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsProjectFlavorCfg_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsProjectFlavorCfg_get_CfgType(This,iidCfg,ppCfg)	\
    (This)->lpVtbl -> get_CfgType(This,iidCfg,ppCfg)

#define IVsProjectFlavorCfg_Close(This)	\
    (This)->lpVtbl -> Close(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsProjectFlavorCfg_get_CfgType_Proxy( 
    IVsProjectFlavorCfg * This,
    /* [in] */ REFIID iidCfg,
    /* [iid_is][out] */ void **ppCfg);


void __RPC_STUB IVsProjectFlavorCfg_get_CfgType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsProjectFlavorCfg_Close_Proxy( 
    IVsProjectFlavorCfg * This);


void __RPC_STUB IVsProjectFlavorCfg_Close_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsProjectFlavorCfg_INTERFACE_DEFINED__ */


#ifndef __IVsProjectFlavorCfgOutputGroups_INTERFACE_DEFINED__
#define __IVsProjectFlavorCfgOutputGroups_INTERFACE_DEFINED__

/* interface IVsProjectFlavorCfgOutputGroups */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsProjectFlavorCfgOutputGroups;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("52F50FAC-B245-4a81-9A02-DBF8F115389B")
    IVsProjectFlavorCfgOutputGroups : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CustomizeOutputGroup( 
            /* [in] */ IVsOutputGroup *pIn,
            /* [out] */ IVsOutputGroup **pOut) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsProjectFlavorCfgOutputGroupsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsProjectFlavorCfgOutputGroups * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsProjectFlavorCfgOutputGroups * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsProjectFlavorCfgOutputGroups * This);
        
        HRESULT ( STDMETHODCALLTYPE *CustomizeOutputGroup )( 
            IVsProjectFlavorCfgOutputGroups * This,
            /* [in] */ IVsOutputGroup *pIn,
            /* [out] */ IVsOutputGroup **pOut);
        
        END_INTERFACE
    } IVsProjectFlavorCfgOutputGroupsVtbl;

    interface IVsProjectFlavorCfgOutputGroups
    {
        CONST_VTBL struct IVsProjectFlavorCfgOutputGroupsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsProjectFlavorCfgOutputGroups_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsProjectFlavorCfgOutputGroups_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsProjectFlavorCfgOutputGroups_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsProjectFlavorCfgOutputGroups_CustomizeOutputGroup(This,pIn,pOut)	\
    (This)->lpVtbl -> CustomizeOutputGroup(This,pIn,pOut)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsProjectFlavorCfgOutputGroups_CustomizeOutputGroup_Proxy( 
    IVsProjectFlavorCfgOutputGroups * This,
    /* [in] */ IVsOutputGroup *pIn,
    /* [out] */ IVsOutputGroup **pOut);


void __RPC_STUB IVsProjectFlavorCfgOutputGroups_CustomizeOutputGroup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsProjectFlavorCfgOutputGroups_INTERFACE_DEFINED__ */


#ifndef __IVsProjectFlavorCfgProvider_INTERFACE_DEFINED__
#define __IVsProjectFlavorCfgProvider_INTERFACE_DEFINED__

/* interface IVsProjectFlavorCfgProvider */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsProjectFlavorCfgProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2b81d5f8-f8bd-4a65-8f51-f3bfcd51a924")
    IVsProjectFlavorCfgProvider : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CreateProjectFlavorCfg( 
            /* [in] */ IVsCfg *pBaseProjectCfg,
            /* [out] */ IVsProjectFlavorCfg **ppFlavorCfg) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsProjectFlavorCfgProviderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsProjectFlavorCfgProvider * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsProjectFlavorCfgProvider * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsProjectFlavorCfgProvider * This);
        
        HRESULT ( STDMETHODCALLTYPE *CreateProjectFlavorCfg )( 
            IVsProjectFlavorCfgProvider * This,
            /* [in] */ IVsCfg *pBaseProjectCfg,
            /* [out] */ IVsProjectFlavorCfg **ppFlavorCfg);
        
        END_INTERFACE
    } IVsProjectFlavorCfgProviderVtbl;

    interface IVsProjectFlavorCfgProvider
    {
        CONST_VTBL struct IVsProjectFlavorCfgProviderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsProjectFlavorCfgProvider_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsProjectFlavorCfgProvider_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsProjectFlavorCfgProvider_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsProjectFlavorCfgProvider_CreateProjectFlavorCfg(This,pBaseProjectCfg,ppFlavorCfg)	\
    (This)->lpVtbl -> CreateProjectFlavorCfg(This,pBaseProjectCfg,ppFlavorCfg)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsProjectFlavorCfgProvider_CreateProjectFlavorCfg_Proxy( 
    IVsProjectFlavorCfgProvider * This,
    /* [in] */ IVsCfg *pBaseProjectCfg,
    /* [out] */ IVsProjectFlavorCfg **ppFlavorCfg);


void __RPC_STUB IVsProjectFlavorCfgProvider_CreateProjectFlavorCfg_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsProjectFlavorCfgProvider_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshell80_0701 */
/* [local] */ 


enum __UPDATE_REFERENCE_REASON
    {	URR_PROJECT_OPEN	= 0,
	URR_BUILD	= URR_PROJECT_OPEN + 1,
	URR_START_DEBUG	= URR_BUILD + 1,
	URR_REFERENCEPATH_CHANGED	= URR_START_DEBUG + 1,
	URR_REFERENCE_ADDED	= URR_REFERENCEPATH_CHANGED + 1,
	URR_REFERENCE_REMOVED	= URR_REFERENCE_ADDED + 1,
	URR_EXPLICIT_USER_ACTION	= URR_REFERENCE_REMOVED + 1
    } ;
typedef DWORD UPDATE_REFERENCE_REASON;



extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0701_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0701_v0_0_s_ifspec;

#ifndef __IVsFlavoredProjectReferences_INTERFACE_DEFINED__
#define __IVsFlavoredProjectReferences_INTERFACE_DEFINED__

/* interface IVsFlavoredProjectReferences */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsFlavoredProjectReferences;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("66DB9803-1019-48ca-99F2-DAD69E49532C")
    IVsFlavoredProjectReferences : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE QueryAddProjectReference( 
            /* [in] */ IUnknown *pReferencedProject,
            /* [retval][out] */ BOOL *pbCanAdd) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryCanBeReferenced( 
            /* [in] */ IUnknown *pReferencingProject,
            /* [retval][out] */ BOOL *pbAllowReferenced) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryRefreshReferences( 
            /* [in] */ UPDATE_REFERENCE_REASON reason,
            /* [retval][out] */ BOOL *pbUpdate) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsFlavoredProjectReferencesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsFlavoredProjectReferences * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsFlavoredProjectReferences * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsFlavoredProjectReferences * This);
        
        HRESULT ( STDMETHODCALLTYPE *QueryAddProjectReference )( 
            IVsFlavoredProjectReferences * This,
            /* [in] */ IUnknown *pReferencedProject,
            /* [retval][out] */ BOOL *pbCanAdd);
        
        HRESULT ( STDMETHODCALLTYPE *QueryCanBeReferenced )( 
            IVsFlavoredProjectReferences * This,
            /* [in] */ IUnknown *pReferencingProject,
            /* [retval][out] */ BOOL *pbAllowReferenced);
        
        HRESULT ( STDMETHODCALLTYPE *QueryRefreshReferences )( 
            IVsFlavoredProjectReferences * This,
            /* [in] */ UPDATE_REFERENCE_REASON reason,
            /* [retval][out] */ BOOL *pbUpdate);
        
        END_INTERFACE
    } IVsFlavoredProjectReferencesVtbl;

    interface IVsFlavoredProjectReferences
    {
        CONST_VTBL struct IVsFlavoredProjectReferencesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsFlavoredProjectReferences_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsFlavoredProjectReferences_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsFlavoredProjectReferences_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsFlavoredProjectReferences_QueryAddProjectReference(This,pReferencedProject,pbCanAdd)	\
    (This)->lpVtbl -> QueryAddProjectReference(This,pReferencedProject,pbCanAdd)

#define IVsFlavoredProjectReferences_QueryCanBeReferenced(This,pReferencingProject,pbAllowReferenced)	\
    (This)->lpVtbl -> QueryCanBeReferenced(This,pReferencingProject,pbAllowReferenced)

#define IVsFlavoredProjectReferences_QueryRefreshReferences(This,reason,pbUpdate)	\
    (This)->lpVtbl -> QueryRefreshReferences(This,reason,pbUpdate)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsFlavoredProjectReferences_QueryAddProjectReference_Proxy( 
    IVsFlavoredProjectReferences * This,
    /* [in] */ IUnknown *pReferencedProject,
    /* [retval][out] */ BOOL *pbCanAdd);


void __RPC_STUB IVsFlavoredProjectReferences_QueryAddProjectReference_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsFlavoredProjectReferences_QueryCanBeReferenced_Proxy( 
    IVsFlavoredProjectReferences * This,
    /* [in] */ IUnknown *pReferencingProject,
    /* [retval][out] */ BOOL *pbAllowReferenced);


void __RPC_STUB IVsFlavoredProjectReferences_QueryCanBeReferenced_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsFlavoredProjectReferences_QueryRefreshReferences_Proxy( 
    IVsFlavoredProjectReferences * This,
    /* [in] */ UPDATE_REFERENCE_REASON reason,
    /* [retval][out] */ BOOL *pbUpdate);


void __RPC_STUB IVsFlavoredProjectReferences_QueryRefreshReferences_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsFlavoredProjectReferences_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshell80_0702 */
/* [local] */ 


enum __VSTRANSACCELEXFLAGS
    {	VSTAEXF_Default	= 0,
	VSTAEXF_NoFireCommand	= 0x1,
	VSTAEXF_IgnoreActiveKBScopes	= 0x2,
	VSTAEXF_UseTextEditorKBScope	= 0x4,
	VSTAEXF_UseGlobalKBScope	= 0x8,
	VSTAEXF_AllowModalState	= 0x10
    } ;
typedef DWORD VSTRANSACCELEXFLAGS;



extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0702_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0702_v0_0_s_ifspec;

#ifndef __IVsFilterKeys2_INTERFACE_DEFINED__
#define __IVsFilterKeys2_INTERFACE_DEFINED__

/* interface IVsFilterKeys2 */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsFilterKeys2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A1FF0D7C-1F51-4a95-B107-EC6FFE2C5794")
    IVsFilterKeys2 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE TranslateAcceleratorEx( 
            /* [in] */ LPMSG pMsg,
            /* [in] */ VSTRANSACCELEXFLAGS dwFlags,
            /* [in] */ DWORD cKeyBindingScopes,
            /* [size_is][in] */ const GUID rgguidKeyBindingScopes[  ],
            /* [out] */ GUID *pguidCmd,
            /* [out] */ DWORD *pdwCmd,
            /* [retval][out] */ BOOL *fCmdTranslated) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsFilterKeys2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsFilterKeys2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsFilterKeys2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsFilterKeys2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *TranslateAcceleratorEx )( 
            IVsFilterKeys2 * This,
            /* [in] */ LPMSG pMsg,
            /* [in] */ VSTRANSACCELEXFLAGS dwFlags,
            /* [in] */ DWORD cKeyBindingScopes,
            /* [size_is][in] */ const GUID rgguidKeyBindingScopes[  ],
            /* [out] */ GUID *pguidCmd,
            /* [out] */ DWORD *pdwCmd,
            /* [retval][out] */ BOOL *fCmdTranslated);
        
        END_INTERFACE
    } IVsFilterKeys2Vtbl;

    interface IVsFilterKeys2
    {
        CONST_VTBL struct IVsFilterKeys2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsFilterKeys2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsFilterKeys2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsFilterKeys2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsFilterKeys2_TranslateAcceleratorEx(This,pMsg,dwFlags,cKeyBindingScopes,rgguidKeyBindingScopes,pguidCmd,pdwCmd,fCmdTranslated)	\
    (This)->lpVtbl -> TranslateAcceleratorEx(This,pMsg,dwFlags,cKeyBindingScopes,rgguidKeyBindingScopes,pguidCmd,pdwCmd,fCmdTranslated)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsFilterKeys2_TranslateAcceleratorEx_Proxy( 
    IVsFilterKeys2 * This,
    /* [in] */ LPMSG pMsg,
    /* [in] */ VSTRANSACCELEXFLAGS dwFlags,
    /* [in] */ DWORD cKeyBindingScopes,
    /* [size_is][in] */ const GUID rgguidKeyBindingScopes[  ],
    /* [out] */ GUID *pguidCmd,
    /* [out] */ DWORD *pdwCmd,
    /* [retval][out] */ BOOL *fCmdTranslated);


void __RPC_STUB IVsFilterKeys2_TranslateAcceleratorEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsFilterKeys2_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshell80_0703 */
/* [local] */ 


enum __UserSettingsFlags
    {	USF_None	= 0,
	USF_ResetOnImport	= 1
    } ;
typedef DWORD UserSettingsFlags;



extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0703_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0703_v0_0_s_ifspec;

#ifndef __IVsSettingsReader_INTERFACE_DEFINED__
#define __IVsSettingsReader_INTERFACE_DEFINED__

/* interface IVsSettingsReader */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsSettingsReader;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("38C38501-1428-4abb-8B27-2F0E1E6DD757")
    IVsSettingsReader : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ReadSettingString( 
            /* [in] */ LPCOLESTR pszSettingName,
            /* [retval][out] */ BSTR *pbstrSettingValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReadSettingLong( 
            /* [in] */ LPCOLESTR pszSettingName,
            /* [retval][out] */ long *plSettingValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReadSettingBoolean( 
            /* [in] */ LPCOLESTR pszSettingName,
            /* [retval][out] */ BOOL *pfSettingValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReadSettingBytes( 
            /* [in] */ LPCOLESTR pszSettingName,
            /* [out][in] */ BYTE *pSettingValue,
            /* [out] */ long *plDataLength,
            /* [in] */ long lDataMax) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReadSettingAttribute( 
            /* [in] */ LPCOLESTR pszSettingName,
            /* [in] */ LPCOLESTR pszAttributeName,
            /* [retval][out] */ BSTR *pbstrSettingValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReadVersion( 
            /* [out] */ int *pnMajor,
            /* [out] */ int *pnMinor,
            /* [out] */ int *pnBuild) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReportError( 
            /* [in] */ LPCOLESTR pszError) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsSettingsReaderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsSettingsReader * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsSettingsReader * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsSettingsReader * This);
        
        HRESULT ( STDMETHODCALLTYPE *ReadSettingString )( 
            IVsSettingsReader * This,
            /* [in] */ LPCOLESTR pszSettingName,
            /* [retval][out] */ BSTR *pbstrSettingValue);
        
        HRESULT ( STDMETHODCALLTYPE *ReadSettingLong )( 
            IVsSettingsReader * This,
            /* [in] */ LPCOLESTR pszSettingName,
            /* [retval][out] */ long *plSettingValue);
        
        HRESULT ( STDMETHODCALLTYPE *ReadSettingBoolean )( 
            IVsSettingsReader * This,
            /* [in] */ LPCOLESTR pszSettingName,
            /* [retval][out] */ BOOL *pfSettingValue);
        
        HRESULT ( STDMETHODCALLTYPE *ReadSettingBytes )( 
            IVsSettingsReader * This,
            /* [in] */ LPCOLESTR pszSettingName,
            /* [out][in] */ BYTE *pSettingValue,
            /* [out] */ long *plDataLength,
            /* [in] */ long lDataMax);
        
        HRESULT ( STDMETHODCALLTYPE *ReadSettingAttribute )( 
            IVsSettingsReader * This,
            /* [in] */ LPCOLESTR pszSettingName,
            /* [in] */ LPCOLESTR pszAttributeName,
            /* [retval][out] */ BSTR *pbstrSettingValue);
        
        HRESULT ( STDMETHODCALLTYPE *ReadVersion )( 
            IVsSettingsReader * This,
            /* [out] */ int *pnMajor,
            /* [out] */ int *pnMinor,
            /* [out] */ int *pnBuild);
        
        HRESULT ( STDMETHODCALLTYPE *ReportError )( 
            IVsSettingsReader * This,
            /* [in] */ LPCOLESTR pszError);
        
        END_INTERFACE
    } IVsSettingsReaderVtbl;

    interface IVsSettingsReader
    {
        CONST_VTBL struct IVsSettingsReaderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsSettingsReader_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsSettingsReader_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsSettingsReader_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsSettingsReader_ReadSettingString(This,pszSettingName,pbstrSettingValue)	\
    (This)->lpVtbl -> ReadSettingString(This,pszSettingName,pbstrSettingValue)

#define IVsSettingsReader_ReadSettingLong(This,pszSettingName,plSettingValue)	\
    (This)->lpVtbl -> ReadSettingLong(This,pszSettingName,plSettingValue)

#define IVsSettingsReader_ReadSettingBoolean(This,pszSettingName,pfSettingValue)	\
    (This)->lpVtbl -> ReadSettingBoolean(This,pszSettingName,pfSettingValue)

#define IVsSettingsReader_ReadSettingBytes(This,pszSettingName,pSettingValue,plDataLength,lDataMax)	\
    (This)->lpVtbl -> ReadSettingBytes(This,pszSettingName,pSettingValue,plDataLength,lDataMax)

#define IVsSettingsReader_ReadSettingAttribute(This,pszSettingName,pszAttributeName,pbstrSettingValue)	\
    (This)->lpVtbl -> ReadSettingAttribute(This,pszSettingName,pszAttributeName,pbstrSettingValue)

#define IVsSettingsReader_ReadVersion(This,pnMajor,pnMinor,pnBuild)	\
    (This)->lpVtbl -> ReadVersion(This,pnMajor,pnMinor,pnBuild)

#define IVsSettingsReader_ReportError(This,pszError)	\
    (This)->lpVtbl -> ReportError(This,pszError)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsSettingsReader_ReadSettingString_Proxy( 
    IVsSettingsReader * This,
    /* [in] */ LPCOLESTR pszSettingName,
    /* [retval][out] */ BSTR *pbstrSettingValue);


void __RPC_STUB IVsSettingsReader_ReadSettingString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSettingsReader_ReadSettingLong_Proxy( 
    IVsSettingsReader * This,
    /* [in] */ LPCOLESTR pszSettingName,
    /* [retval][out] */ long *plSettingValue);


void __RPC_STUB IVsSettingsReader_ReadSettingLong_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSettingsReader_ReadSettingBoolean_Proxy( 
    IVsSettingsReader * This,
    /* [in] */ LPCOLESTR pszSettingName,
    /* [retval][out] */ BOOL *pfSettingValue);


void __RPC_STUB IVsSettingsReader_ReadSettingBoolean_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSettingsReader_ReadSettingBytes_Proxy( 
    IVsSettingsReader * This,
    /* [in] */ LPCOLESTR pszSettingName,
    /* [out][in] */ BYTE *pSettingValue,
    /* [out] */ long *plDataLength,
    /* [in] */ long lDataMax);


void __RPC_STUB IVsSettingsReader_ReadSettingBytes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSettingsReader_ReadSettingAttribute_Proxy( 
    IVsSettingsReader * This,
    /* [in] */ LPCOLESTR pszSettingName,
    /* [in] */ LPCOLESTR pszAttributeName,
    /* [retval][out] */ BSTR *pbstrSettingValue);


void __RPC_STUB IVsSettingsReader_ReadSettingAttribute_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSettingsReader_ReadVersion_Proxy( 
    IVsSettingsReader * This,
    /* [out] */ int *pnMajor,
    /* [out] */ int *pnMinor,
    /* [out] */ int *pnBuild);


void __RPC_STUB IVsSettingsReader_ReadVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSettingsReader_ReportError_Proxy( 
    IVsSettingsReader * This,
    /* [in] */ LPCOLESTR pszError);


void __RPC_STUB IVsSettingsReader_ReportError_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsSettingsReader_INTERFACE_DEFINED__ */


#ifndef __IVsSettingsWriter_INTERFACE_DEFINED__
#define __IVsSettingsWriter_INTERFACE_DEFINED__

/* interface IVsSettingsWriter */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsSettingsWriter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0F1CF980-AFC6-406e-958D-7F24287E3916")
    IVsSettingsWriter : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE WriteSettingString( 
            LPCOLESTR pszSettingName,
            LPCOLESTR pszSettingValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WriteSettingLong( 
            LPCOLESTR pszSettingName,
            long lSettingValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WriteSettingBoolean( 
            LPCOLESTR pszSettingName,
            BOOL fSettingValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WriteSettingBytes( 
            LPCOLESTR pszSettingName,
            BYTE *pSettingValue,
            long lDataLength) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WriteSettingAttribute( 
            LPCOLESTR pszSettingName,
            LPCOLESTR pszAttributeName,
            LPCOLESTR pszSettingValue) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsSettingsWriterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsSettingsWriter * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsSettingsWriter * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsSettingsWriter * This);
        
        HRESULT ( STDMETHODCALLTYPE *WriteSettingString )( 
            IVsSettingsWriter * This,
            LPCOLESTR pszSettingName,
            LPCOLESTR pszSettingValue);
        
        HRESULT ( STDMETHODCALLTYPE *WriteSettingLong )( 
            IVsSettingsWriter * This,
            LPCOLESTR pszSettingName,
            long lSettingValue);
        
        HRESULT ( STDMETHODCALLTYPE *WriteSettingBoolean )( 
            IVsSettingsWriter * This,
            LPCOLESTR pszSettingName,
            BOOL fSettingValue);
        
        HRESULT ( STDMETHODCALLTYPE *WriteSettingBytes )( 
            IVsSettingsWriter * This,
            LPCOLESTR pszSettingName,
            BYTE *pSettingValue,
            long lDataLength);
        
        HRESULT ( STDMETHODCALLTYPE *WriteSettingAttribute )( 
            IVsSettingsWriter * This,
            LPCOLESTR pszSettingName,
            LPCOLESTR pszAttributeName,
            LPCOLESTR pszSettingValue);
        
        END_INTERFACE
    } IVsSettingsWriterVtbl;

    interface IVsSettingsWriter
    {
        CONST_VTBL struct IVsSettingsWriterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsSettingsWriter_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsSettingsWriter_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsSettingsWriter_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsSettingsWriter_WriteSettingString(This,pszSettingName,pszSettingValue)	\
    (This)->lpVtbl -> WriteSettingString(This,pszSettingName,pszSettingValue)

#define IVsSettingsWriter_WriteSettingLong(This,pszSettingName,lSettingValue)	\
    (This)->lpVtbl -> WriteSettingLong(This,pszSettingName,lSettingValue)

#define IVsSettingsWriter_WriteSettingBoolean(This,pszSettingName,fSettingValue)	\
    (This)->lpVtbl -> WriteSettingBoolean(This,pszSettingName,fSettingValue)

#define IVsSettingsWriter_WriteSettingBytes(This,pszSettingName,pSettingValue,lDataLength)	\
    (This)->lpVtbl -> WriteSettingBytes(This,pszSettingName,pSettingValue,lDataLength)

#define IVsSettingsWriter_WriteSettingAttribute(This,pszSettingName,pszAttributeName,pszSettingValue)	\
    (This)->lpVtbl -> WriteSettingAttribute(This,pszSettingName,pszAttributeName,pszSettingValue)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsSettingsWriter_WriteSettingString_Proxy( 
    IVsSettingsWriter * This,
    LPCOLESTR pszSettingName,
    LPCOLESTR pszSettingValue);


void __RPC_STUB IVsSettingsWriter_WriteSettingString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSettingsWriter_WriteSettingLong_Proxy( 
    IVsSettingsWriter * This,
    LPCOLESTR pszSettingName,
    long lSettingValue);


void __RPC_STUB IVsSettingsWriter_WriteSettingLong_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSettingsWriter_WriteSettingBoolean_Proxy( 
    IVsSettingsWriter * This,
    LPCOLESTR pszSettingName,
    BOOL fSettingValue);


void __RPC_STUB IVsSettingsWriter_WriteSettingBoolean_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSettingsWriter_WriteSettingBytes_Proxy( 
    IVsSettingsWriter * This,
    LPCOLESTR pszSettingName,
    BYTE *pSettingValue,
    long lDataLength);


void __RPC_STUB IVsSettingsWriter_WriteSettingBytes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSettingsWriter_WriteSettingAttribute_Proxy( 
    IVsSettingsWriter * This,
    LPCOLESTR pszSettingName,
    LPCOLESTR pszAttributeName,
    LPCOLESTR pszSettingValue);


void __RPC_STUB IVsSettingsWriter_WriteSettingAttribute_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsSettingsWriter_INTERFACE_DEFINED__ */


#ifndef __IVsUserSettings_INTERFACE_DEFINED__
#define __IVsUserSettings_INTERFACE_DEFINED__

/* interface IVsUserSettings */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsUserSettings;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("770E285D-3B7D-4342-B3C4-42BD9F53A300")
    IVsUserSettings : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ExportSettings( 
            LPOLESTR pszCategoryGUID,
            IVsSettingsWriter *pSettings) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ImportSettings( 
            LPOLESTR pszCategoryGUID,
            IVsSettingsReader *pSettings,
            UserSettingsFlags flags,
            BOOL *pfRestartRequired) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsUserSettingsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsUserSettings * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsUserSettings * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsUserSettings * This);
        
        HRESULT ( STDMETHODCALLTYPE *ExportSettings )( 
            IVsUserSettings * This,
            LPOLESTR pszCategoryGUID,
            IVsSettingsWriter *pSettings);
        
        HRESULT ( STDMETHODCALLTYPE *ImportSettings )( 
            IVsUserSettings * This,
            LPOLESTR pszCategoryGUID,
            IVsSettingsReader *pSettings,
            UserSettingsFlags flags,
            BOOL *pfRestartRequired);
        
        END_INTERFACE
    } IVsUserSettingsVtbl;

    interface IVsUserSettings
    {
        CONST_VTBL struct IVsUserSettingsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsUserSettings_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsUserSettings_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsUserSettings_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsUserSettings_ExportSettings(This,pszCategoryGUID,pSettings)	\
    (This)->lpVtbl -> ExportSettings(This,pszCategoryGUID,pSettings)

#define IVsUserSettings_ImportSettings(This,pszCategoryGUID,pSettings,flags,pfRestartRequired)	\
    (This)->lpVtbl -> ImportSettings(This,pszCategoryGUID,pSettings,flags,pfRestartRequired)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsUserSettings_ExportSettings_Proxy( 
    IVsUserSettings * This,
    LPOLESTR pszCategoryGUID,
    IVsSettingsWriter *pSettings);


void __RPC_STUB IVsUserSettings_ExportSettings_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsUserSettings_ImportSettings_Proxy( 
    IVsUserSettings * This,
    LPOLESTR pszCategoryGUID,
    IVsSettingsReader *pSettings,
    UserSettingsFlags flags,
    BOOL *pfRestartRequired);


void __RPC_STUB IVsUserSettings_ImportSettings_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsUserSettings_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshell80_0706 */
/* [local] */ 

#define SID_SVsSettingsReader IID_IVsSettingsReader


extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0706_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0706_v0_0_s_ifspec;

#ifndef __IVsUserSettingsQuery_INTERFACE_DEFINED__
#define __IVsUserSettingsQuery_INTERFACE_DEFINED__

/* interface IVsUserSettingsQuery */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsUserSettingsQuery;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("334E1F15-7D97-4231-81B0-998E4A960E69")
    IVsUserSettingsQuery : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE NeedExport( 
            /* [in] */ LPOLESTR szCategoryGUID,
            /* [out] */ BOOL *pfNeedExport) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsUserSettingsQueryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsUserSettingsQuery * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsUserSettingsQuery * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsUserSettingsQuery * This);
        
        HRESULT ( STDMETHODCALLTYPE *NeedExport )( 
            IVsUserSettingsQuery * This,
            /* [in] */ LPOLESTR szCategoryGUID,
            /* [out] */ BOOL *pfNeedExport);
        
        END_INTERFACE
    } IVsUserSettingsQueryVtbl;

    interface IVsUserSettingsQuery
    {
        CONST_VTBL struct IVsUserSettingsQueryVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsUserSettingsQuery_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsUserSettingsQuery_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsUserSettingsQuery_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsUserSettingsQuery_NeedExport(This,szCategoryGUID,pfNeedExport)	\
    (This)->lpVtbl -> NeedExport(This,szCategoryGUID,pfNeedExport)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsUserSettingsQuery_NeedExport_Proxy( 
    IVsUserSettingsQuery * This,
    /* [in] */ LPOLESTR szCategoryGUID,
    /* [out] */ BOOL *pfNeedExport);


void __RPC_STUB IVsUserSettingsQuery_NeedExport_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsUserSettingsQuery_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshell80_0707 */
/* [local] */ 







enum __VSPROFILELOCATIONS
    {	PFL_LocationNone	= 0,
	PFL_InstallDir	= 0x1,
	PFL_SettingsDir	= 0x20,
	PFL_Other	= 0x400,
	PFL_All	= 0xffffffff
    } ;
typedef DWORD VSPROFILELOCATIONS;


enum __VSPROFILEIMPORTEXPORTRESULTS
    {	PIER_NOERROR	= 0,
	PIER_RESTARTREQUIRED	= 0x1,
	PIER_FOUNDERRORS	= 0x2,
	PIER_CHECKLOG	= 0x4,
	PIER_FATALERROR	= 0x8
    } ;
typedef DWORD VSPROFILEIMPORTEXPORTRESULTS;


enum __VSPROFILETEAMSETTINGSFLAGS
    {	PTSF_CHECKFORUPDATE	= 0,
	PTSF_UPDATEALWAYS	= 0x1
    } ;
typedef DWORD VSPROFILETEAMSETTINGSFLAGS;


enum __VSPROFILETEAMSETTINGSCHANGEDFLAGS
    {	PTSCF_TEAMFILE_NOCHANGE	= 0,
	PTSCF_TEAMFILE_CHANGED	= 0x1,
	PTSCF_TEAMFILE_SAME	= 0x2
    } ;
typedef DWORD VSPROFILETEAMSETTINGSCHANGEDFLAGS;


enum __VSPROFILEUIDISPLAYFLAGS
    {	PUID_NONE	= 0,
	PUID_DONTPROMPTTOSAVE	= 0x1,
	PUID_DONTPROMPTSECURITY	= 0x2
    } ;
typedef DWORD VSPROFILEUIDISPLAYFLAGS;


enum __VSPROFILECATEGORYSECURITY
    {	PCSEC_SAFE	= 0,
	PCSEC_THREAT_VS	= 0x1,
	PCSEC_THREAT_MACHINE	= 0x2
    } ;
typedef DWORD VSPROFILECATEGORYSECURITY;


enum __VSPROFILECATEGORYSENSITIVITY
    {	PCSEN_SAFE	= 0,
	PCSEN_PRIVACY	= 0x1
    } ;
typedef DWORD VSPROFILECATEGORYSENSITIVITY;



extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0707_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0707_v0_0_s_ifspec;

#ifndef __IVsProfileSettingsFileInfo_INTERFACE_DEFINED__
#define __IVsProfileSettingsFileInfo_INTERFACE_DEFINED__

/* interface IVsProfileSettingsFileInfo */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsProfileSettingsFileInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8E8E55A9-4111-4808-A0D0-7F067FB3A62F")
    IVsProfileSettingsFileInfo : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetFilePath( 
            /* [out] */ BSTR *pbstrFilePath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFileLocation( 
            /* [out] */ VSPROFILELOCATIONS *pfileLocation) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFriendlyName( 
            /* [out] */ BSTR *pbstrFriendlyName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDescription( 
            /* [out] */ BSTR *pbstrDescription) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSettingsForImport( 
            /* [out] */ IVsProfileSettingsTree **ppSettingsTree) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsProfileSettingsFileInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsProfileSettingsFileInfo * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsProfileSettingsFileInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsProfileSettingsFileInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetFilePath )( 
            IVsProfileSettingsFileInfo * This,
            /* [out] */ BSTR *pbstrFilePath);
        
        HRESULT ( STDMETHODCALLTYPE *GetFileLocation )( 
            IVsProfileSettingsFileInfo * This,
            /* [out] */ VSPROFILELOCATIONS *pfileLocation);
        
        HRESULT ( STDMETHODCALLTYPE *GetFriendlyName )( 
            IVsProfileSettingsFileInfo * This,
            /* [out] */ BSTR *pbstrFriendlyName);
        
        HRESULT ( STDMETHODCALLTYPE *GetDescription )( 
            IVsProfileSettingsFileInfo * This,
            /* [out] */ BSTR *pbstrDescription);
        
        HRESULT ( STDMETHODCALLTYPE *GetSettingsForImport )( 
            IVsProfileSettingsFileInfo * This,
            /* [out] */ IVsProfileSettingsTree **ppSettingsTree);
        
        END_INTERFACE
    } IVsProfileSettingsFileInfoVtbl;

    interface IVsProfileSettingsFileInfo
    {
        CONST_VTBL struct IVsProfileSettingsFileInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsProfileSettingsFileInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsProfileSettingsFileInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsProfileSettingsFileInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsProfileSettingsFileInfo_GetFilePath(This,pbstrFilePath)	\
    (This)->lpVtbl -> GetFilePath(This,pbstrFilePath)

#define IVsProfileSettingsFileInfo_GetFileLocation(This,pfileLocation)	\
    (This)->lpVtbl -> GetFileLocation(This,pfileLocation)

#define IVsProfileSettingsFileInfo_GetFriendlyName(This,pbstrFriendlyName)	\
    (This)->lpVtbl -> GetFriendlyName(This,pbstrFriendlyName)

#define IVsProfileSettingsFileInfo_GetDescription(This,pbstrDescription)	\
    (This)->lpVtbl -> GetDescription(This,pbstrDescription)

#define IVsProfileSettingsFileInfo_GetSettingsForImport(This,ppSettingsTree)	\
    (This)->lpVtbl -> GetSettingsForImport(This,ppSettingsTree)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsProfileSettingsFileInfo_GetFilePath_Proxy( 
    IVsProfileSettingsFileInfo * This,
    /* [out] */ BSTR *pbstrFilePath);


void __RPC_STUB IVsProfileSettingsFileInfo_GetFilePath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsProfileSettingsFileInfo_GetFileLocation_Proxy( 
    IVsProfileSettingsFileInfo * This,
    /* [out] */ VSPROFILELOCATIONS *pfileLocation);


void __RPC_STUB IVsProfileSettingsFileInfo_GetFileLocation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsProfileSettingsFileInfo_GetFriendlyName_Proxy( 
    IVsProfileSettingsFileInfo * This,
    /* [out] */ BSTR *pbstrFriendlyName);


void __RPC_STUB IVsProfileSettingsFileInfo_GetFriendlyName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsProfileSettingsFileInfo_GetDescription_Proxy( 
    IVsProfileSettingsFileInfo * This,
    /* [out] */ BSTR *pbstrDescription);


void __RPC_STUB IVsProfileSettingsFileInfo_GetDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsProfileSettingsFileInfo_GetSettingsForImport_Proxy( 
    IVsProfileSettingsFileInfo * This,
    /* [out] */ IVsProfileSettingsTree **ppSettingsTree);


void __RPC_STUB IVsProfileSettingsFileInfo_GetSettingsForImport_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsProfileSettingsFileInfo_INTERFACE_DEFINED__ */


#ifndef __IVsProfileSettingsFileCollection_INTERFACE_DEFINED__
#define __IVsProfileSettingsFileCollection_INTERFACE_DEFINED__

/* interface IVsProfileSettingsFileCollection */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsProfileSettingsFileCollection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0FAF274A-3898-445a-822F-7D42927EFEF9")
    IVsProfileSettingsFileCollection : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetCount( 
            /* [out] */ int *pCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSettingsFile( 
            /* [in] */ int index,
            /* [out] */ IVsProfileSettingsFileInfo **ppFileInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddBrowseFile( 
            /* [in] */ BSTR bstrFilePath,
            /* [out] */ IVsProfileSettingsFileInfo **ppFileInfo) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsProfileSettingsFileCollectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsProfileSettingsFileCollection * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsProfileSettingsFileCollection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsProfileSettingsFileCollection * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetCount )( 
            IVsProfileSettingsFileCollection * This,
            /* [out] */ int *pCount);
        
        HRESULT ( STDMETHODCALLTYPE *GetSettingsFile )( 
            IVsProfileSettingsFileCollection * This,
            /* [in] */ int index,
            /* [out] */ IVsProfileSettingsFileInfo **ppFileInfo);
        
        HRESULT ( STDMETHODCALLTYPE *AddBrowseFile )( 
            IVsProfileSettingsFileCollection * This,
            /* [in] */ BSTR bstrFilePath,
            /* [out] */ IVsProfileSettingsFileInfo **ppFileInfo);
        
        END_INTERFACE
    } IVsProfileSettingsFileCollectionVtbl;

    interface IVsProfileSettingsFileCollection
    {
        CONST_VTBL struct IVsProfileSettingsFileCollectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsProfileSettingsFileCollection_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsProfileSettingsFileCollection_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsProfileSettingsFileCollection_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsProfileSettingsFileCollection_GetCount(This,pCount)	\
    (This)->lpVtbl -> GetCount(This,pCount)

#define IVsProfileSettingsFileCollection_GetSettingsFile(This,index,ppFileInfo)	\
    (This)->lpVtbl -> GetSettingsFile(This,index,ppFileInfo)

#define IVsProfileSettingsFileCollection_AddBrowseFile(This,bstrFilePath,ppFileInfo)	\
    (This)->lpVtbl -> AddBrowseFile(This,bstrFilePath,ppFileInfo)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsProfileSettingsFileCollection_GetCount_Proxy( 
    IVsProfileSettingsFileCollection * This,
    /* [out] */ int *pCount);


void __RPC_STUB IVsProfileSettingsFileCollection_GetCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsProfileSettingsFileCollection_GetSettingsFile_Proxy( 
    IVsProfileSettingsFileCollection * This,
    /* [in] */ int index,
    /* [out] */ IVsProfileSettingsFileInfo **ppFileInfo);


void __RPC_STUB IVsProfileSettingsFileCollection_GetSettingsFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsProfileSettingsFileCollection_AddBrowseFile_Proxy( 
    IVsProfileSettingsFileCollection * This,
    /* [in] */ BSTR bstrFilePath,
    /* [out] */ IVsProfileSettingsFileInfo **ppFileInfo);


void __RPC_STUB IVsProfileSettingsFileCollection_AddBrowseFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsProfileSettingsFileCollection_INTERFACE_DEFINED__ */


#ifndef __IVsProfileSettingsTree_INTERFACE_DEFINED__
#define __IVsProfileSettingsTree_INTERFACE_DEFINED__

/* interface IVsProfileSettingsTree */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsProfileSettingsTree;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("23B6FED1-C3CB-4006-BAD0-64A7EB61DF39")
    IVsProfileSettingsTree : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetChildCount( 
            /* [out] */ int *pCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetChild( 
            /* [in] */ int index,
            /* [out] */ IVsProfileSettingsTree **ppChildTree) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDisplayName( 
            /* [out] */ BSTR *pbstrName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCategory( 
            /* [out] */ BSTR *pbstrCategory) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRegisteredName( 
            /* [out] */ BSTR *pbstrRegisteredName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNameForID( 
            /* [out] */ BSTR *pbstrNameForID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPackage( 
            /* [out] */ BSTR *pbstrPackage) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIsAutomationPropBased( 
            /* [out] */ BOOL *pfAutoProp) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEnabled( 
            /* [out] */ BOOL *pfEnabled) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetEnabled( 
            /* [in] */ BOOL fEnabled,
            /* [in] */ BOOL fIncludeChildren) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVisible( 
            /* [out] */ BOOL *pfVisible) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAlternatePath( 
            /* [out] */ BSTR *pbstrAlternatePath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIsPlaceholder( 
            /* [out] */ BOOL *pfPlaceholder) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRepresentedNode( 
            /* [out] */ IVsProfileSettingsTree **ppRepresentedNode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSecurityLevel( 
            /* [out] */ VSPROFILECATEGORYSECURITY *pSecurityLevel) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSensitivityLevel( 
            /* [out] */ VSPROFILECATEGORYSENSITIVITY *pSensitivityLevel) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FindChildTree( 
            /* [in] */ BSTR bstrNameSearch,
            /* [in] */ BOOL fSearchChildTrees,
            /* [out] */ IVsProfileSettingsTree **ppChildTree,
            /* [out] */ BSTR *pbstrRelativePath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddChildTree( 
            /* [in] */ IVsProfileSettingsTree *pChildTree) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RevisePlacements( 
            /* [in] */ IVsProfileSettingsTree *pTreeRoot,
            /* [in] */ IVsProfileSettingsTree *pTreeRootBasis,
            /* [in] */ BSTR bstrCurrentParent) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsProfileSettingsTreeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsProfileSettingsTree * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsProfileSettingsTree * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsProfileSettingsTree * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetChildCount )( 
            IVsProfileSettingsTree * This,
            /* [out] */ int *pCount);
        
        HRESULT ( STDMETHODCALLTYPE *GetChild )( 
            IVsProfileSettingsTree * This,
            /* [in] */ int index,
            /* [out] */ IVsProfileSettingsTree **ppChildTree);
        
        HRESULT ( STDMETHODCALLTYPE *GetDisplayName )( 
            IVsProfileSettingsTree * This,
            /* [out] */ BSTR *pbstrName);
        
        HRESULT ( STDMETHODCALLTYPE *GetCategory )( 
            IVsProfileSettingsTree * This,
            /* [out] */ BSTR *pbstrCategory);
        
        HRESULT ( STDMETHODCALLTYPE *GetRegisteredName )( 
            IVsProfileSettingsTree * This,
            /* [out] */ BSTR *pbstrRegisteredName);
        
        HRESULT ( STDMETHODCALLTYPE *GetNameForID )( 
            IVsProfileSettingsTree * This,
            /* [out] */ BSTR *pbstrNameForID);
        
        HRESULT ( STDMETHODCALLTYPE *GetPackage )( 
            IVsProfileSettingsTree * This,
            /* [out] */ BSTR *pbstrPackage);
        
        HRESULT ( STDMETHODCALLTYPE *GetIsAutomationPropBased )( 
            IVsProfileSettingsTree * This,
            /* [out] */ BOOL *pfAutoProp);
        
        HRESULT ( STDMETHODCALLTYPE *GetEnabled )( 
            IVsProfileSettingsTree * This,
            /* [out] */ BOOL *pfEnabled);
        
        HRESULT ( STDMETHODCALLTYPE *SetEnabled )( 
            IVsProfileSettingsTree * This,
            /* [in] */ BOOL fEnabled,
            /* [in] */ BOOL fIncludeChildren);
        
        HRESULT ( STDMETHODCALLTYPE *GetVisible )( 
            IVsProfileSettingsTree * This,
            /* [out] */ BOOL *pfVisible);
        
        HRESULT ( STDMETHODCALLTYPE *GetAlternatePath )( 
            IVsProfileSettingsTree * This,
            /* [out] */ BSTR *pbstrAlternatePath);
        
        HRESULT ( STDMETHODCALLTYPE *GetIsPlaceholder )( 
            IVsProfileSettingsTree * This,
            /* [out] */ BOOL *pfPlaceholder);
        
        HRESULT ( STDMETHODCALLTYPE *GetRepresentedNode )( 
            IVsProfileSettingsTree * This,
            /* [out] */ IVsProfileSettingsTree **ppRepresentedNode);
        
        HRESULT ( STDMETHODCALLTYPE *GetSecurityLevel )( 
            IVsProfileSettingsTree * This,
            /* [out] */ VSPROFILECATEGORYSECURITY *pSecurityLevel);
        
        HRESULT ( STDMETHODCALLTYPE *GetSensitivityLevel )( 
            IVsProfileSettingsTree * This,
            /* [out] */ VSPROFILECATEGORYSENSITIVITY *pSensitivityLevel);
        
        HRESULT ( STDMETHODCALLTYPE *FindChildTree )( 
            IVsProfileSettingsTree * This,
            /* [in] */ BSTR bstrNameSearch,
            /* [in] */ BOOL fSearchChildTrees,
            /* [out] */ IVsProfileSettingsTree **ppChildTree,
            /* [out] */ BSTR *pbstrRelativePath);
        
        HRESULT ( STDMETHODCALLTYPE *AddChildTree )( 
            IVsProfileSettingsTree * This,
            /* [in] */ IVsProfileSettingsTree *pChildTree);
        
        HRESULT ( STDMETHODCALLTYPE *RevisePlacements )( 
            IVsProfileSettingsTree * This,
            /* [in] */ IVsProfileSettingsTree *pTreeRoot,
            /* [in] */ IVsProfileSettingsTree *pTreeRootBasis,
            /* [in] */ BSTR bstrCurrentParent);
        
        END_INTERFACE
    } IVsProfileSettingsTreeVtbl;

    interface IVsProfileSettingsTree
    {
        CONST_VTBL struct IVsProfileSettingsTreeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsProfileSettingsTree_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsProfileSettingsTree_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsProfileSettingsTree_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsProfileSettingsTree_GetChildCount(This,pCount)	\
    (This)->lpVtbl -> GetChildCount(This,pCount)

#define IVsProfileSettingsTree_GetChild(This,index,ppChildTree)	\
    (This)->lpVtbl -> GetChild(This,index,ppChildTree)

#define IVsProfileSettingsTree_GetDisplayName(This,pbstrName)	\
    (This)->lpVtbl -> GetDisplayName(This,pbstrName)

#define IVsProfileSettingsTree_GetCategory(This,pbstrCategory)	\
    (This)->lpVtbl -> GetCategory(This,pbstrCategory)

#define IVsProfileSettingsTree_GetRegisteredName(This,pbstrRegisteredName)	\
    (This)->lpVtbl -> GetRegisteredName(This,pbstrRegisteredName)

#define IVsProfileSettingsTree_GetNameForID(This,pbstrNameForID)	\
    (This)->lpVtbl -> GetNameForID(This,pbstrNameForID)

#define IVsProfileSettingsTree_GetPackage(This,pbstrPackage)	\
    (This)->lpVtbl -> GetPackage(This,pbstrPackage)

#define IVsProfileSettingsTree_GetIsAutomationPropBased(This,pfAutoProp)	\
    (This)->lpVtbl -> GetIsAutomationPropBased(This,pfAutoProp)

#define IVsProfileSettingsTree_GetEnabled(This,pfEnabled)	\
    (This)->lpVtbl -> GetEnabled(This,pfEnabled)

#define IVsProfileSettingsTree_SetEnabled(This,fEnabled,fIncludeChildren)	\
    (This)->lpVtbl -> SetEnabled(This,fEnabled,fIncludeChildren)

#define IVsProfileSettingsTree_GetVisible(This,pfVisible)	\
    (This)->lpVtbl -> GetVisible(This,pfVisible)

#define IVsProfileSettingsTree_GetAlternatePath(This,pbstrAlternatePath)	\
    (This)->lpVtbl -> GetAlternatePath(This,pbstrAlternatePath)

#define IVsProfileSettingsTree_GetIsPlaceholder(This,pfPlaceholder)	\
    (This)->lpVtbl -> GetIsPlaceholder(This,pfPlaceholder)

#define IVsProfileSettingsTree_GetRepresentedNode(This,ppRepresentedNode)	\
    (This)->lpVtbl -> GetRepresentedNode(This,ppRepresentedNode)

#define IVsProfileSettingsTree_GetSecurityLevel(This,pSecurityLevel)	\
    (This)->lpVtbl -> GetSecurityLevel(This,pSecurityLevel)

#define IVsProfileSettingsTree_GetSensitivityLevel(This,pSensitivityLevel)	\
    (This)->lpVtbl -> GetSensitivityLevel(This,pSensitivityLevel)

#define IVsProfileSettingsTree_FindChildTree(This,bstrNameSearch,fSearchChildTrees,ppChildTree,pbstrRelativePath)	\
    (This)->lpVtbl -> FindChildTree(This,bstrNameSearch,fSearchChildTrees,ppChildTree,pbstrRelativePath)

#define IVsProfileSettingsTree_AddChildTree(This,pChildTree)	\
    (This)->lpVtbl -> AddChildTree(This,pChildTree)

#define IVsProfileSettingsTree_RevisePlacements(This,pTreeRoot,pTreeRootBasis,bstrCurrentParent)	\
    (This)->lpVtbl -> RevisePlacements(This,pTreeRoot,pTreeRootBasis,bstrCurrentParent)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsProfileSettingsTree_GetChildCount_Proxy( 
    IVsProfileSettingsTree * This,
    /* [out] */ int *pCount);


void __RPC_STUB IVsProfileSettingsTree_GetChildCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsProfileSettingsTree_GetChild_Proxy( 
    IVsProfileSettingsTree * This,
    /* [in] */ int index,
    /* [out] */ IVsProfileSettingsTree **ppChildTree);


void __RPC_STUB IVsProfileSettingsTree_GetChild_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsProfileSettingsTree_GetDisplayName_Proxy( 
    IVsProfileSettingsTree * This,
    /* [out] */ BSTR *pbstrName);


void __RPC_STUB IVsProfileSettingsTree_GetDisplayName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsProfileSettingsTree_GetCategory_Proxy( 
    IVsProfileSettingsTree * This,
    /* [out] */ BSTR *pbstrCategory);


void __RPC_STUB IVsProfileSettingsTree_GetCategory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsProfileSettingsTree_GetRegisteredName_Proxy( 
    IVsProfileSettingsTree * This,
    /* [out] */ BSTR *pbstrRegisteredName);


void __RPC_STUB IVsProfileSettingsTree_GetRegisteredName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsProfileSettingsTree_GetNameForID_Proxy( 
    IVsProfileSettingsTree * This,
    /* [out] */ BSTR *pbstrNameForID);


void __RPC_STUB IVsProfileSettingsTree_GetNameForID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsProfileSettingsTree_GetPackage_Proxy( 
    IVsProfileSettingsTree * This,
    /* [out] */ BSTR *pbstrPackage);


void __RPC_STUB IVsProfileSettingsTree_GetPackage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsProfileSettingsTree_GetIsAutomationPropBased_Proxy( 
    IVsProfileSettingsTree * This,
    /* [out] */ BOOL *pfAutoProp);


void __RPC_STUB IVsProfileSettingsTree_GetIsAutomationPropBased_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsProfileSettingsTree_GetEnabled_Proxy( 
    IVsProfileSettingsTree * This,
    /* [out] */ BOOL *pfEnabled);


void __RPC_STUB IVsProfileSettingsTree_GetEnabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsProfileSettingsTree_SetEnabled_Proxy( 
    IVsProfileSettingsTree * This,
    /* [in] */ BOOL fEnabled,
    /* [in] */ BOOL fIncludeChildren);


void __RPC_STUB IVsProfileSettingsTree_SetEnabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsProfileSettingsTree_GetVisible_Proxy( 
    IVsProfileSettingsTree * This,
    /* [out] */ BOOL *pfVisible);


void __RPC_STUB IVsProfileSettingsTree_GetVisible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsProfileSettingsTree_GetAlternatePath_Proxy( 
    IVsProfileSettingsTree * This,
    /* [out] */ BSTR *pbstrAlternatePath);


void __RPC_STUB IVsProfileSettingsTree_GetAlternatePath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsProfileSettingsTree_GetIsPlaceholder_Proxy( 
    IVsProfileSettingsTree * This,
    /* [out] */ BOOL *pfPlaceholder);


void __RPC_STUB IVsProfileSettingsTree_GetIsPlaceholder_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsProfileSettingsTree_GetRepresentedNode_Proxy( 
    IVsProfileSettingsTree * This,
    /* [out] */ IVsProfileSettingsTree **ppRepresentedNode);


void __RPC_STUB IVsProfileSettingsTree_GetRepresentedNode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsProfileSettingsTree_GetSecurityLevel_Proxy( 
    IVsProfileSettingsTree * This,
    /* [out] */ VSPROFILECATEGORYSECURITY *pSecurityLevel);


void __RPC_STUB IVsProfileSettingsTree_GetSecurityLevel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsProfileSettingsTree_GetSensitivityLevel_Proxy( 
    IVsProfileSettingsTree * This,
    /* [out] */ VSPROFILECATEGORYSENSITIVITY *pSensitivityLevel);


void __RPC_STUB IVsProfileSettingsTree_GetSensitivityLevel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsProfileSettingsTree_FindChildTree_Proxy( 
    IVsProfileSettingsTree * This,
    /* [in] */ BSTR bstrNameSearch,
    /* [in] */ BOOL fSearchChildTrees,
    /* [out] */ IVsProfileSettingsTree **ppChildTree,
    /* [out] */ BSTR *pbstrRelativePath);


void __RPC_STUB IVsProfileSettingsTree_FindChildTree_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsProfileSettingsTree_AddChildTree_Proxy( 
    IVsProfileSettingsTree * This,
    /* [in] */ IVsProfileSettingsTree *pChildTree);


void __RPC_STUB IVsProfileSettingsTree_AddChildTree_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsProfileSettingsTree_RevisePlacements_Proxy( 
    IVsProfileSettingsTree * This,
    /* [in] */ IVsProfileSettingsTree *pTreeRoot,
    /* [in] */ IVsProfileSettingsTree *pTreeRootBasis,
    /* [in] */ BSTR bstrCurrentParent);


void __RPC_STUB IVsProfileSettingsTree_RevisePlacements_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsProfileSettingsTree_INTERFACE_DEFINED__ */


#ifndef __IVsProfileDataManager_INTERFACE_DEFINED__
#define __IVsProfileDataManager_INTERFACE_DEFINED__

/* interface IVsProfileDataManager */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsProfileDataManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("466EFAF6-F832-4079-83CD-4BBB02719C1D")
    IVsProfileDataManager : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE LastResetPoint( 
            /* [out] */ BSTR *pbstrResetFilename) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSettingsFiles( 
            /* [in] */ VSPROFILELOCATIONS fileLocations,
            /* [out] */ IVsProfileSettingsFileCollection **ppCollection) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDefaultSettingsLocation( 
            /* [out] */ BSTR *pbstrSettingsLocation) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUniqueExportFileName( 
            /* [out] */ BSTR *pbstrExportFile) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSettingsFileExtension( 
            /* [out] */ BSTR *pbstrSettingsFileExtension) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSettingsForExport( 
            /* [out] */ IVsProfileSettingsTree **ppSettingsTree) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ExportSettings( 
            /* [in] */ BSTR bstrFilePath,
            /* [in] */ IVsProfileSettingsTree *pSettingsTree,
            /* [out] */ VSPROFILEIMPORTEXPORTRESULTS *pdwResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ImportSettings( 
            /* [in] */ IVsProfileSettingsTree *pSettingsTree,
            /* [out] */ VSPROFILEIMPORTEXPORTRESULTS *pdwResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ResetSettings( 
            /* [in] */ IVsProfileSettingsFileInfo *pFileInfo,
            /* [out] */ VSPROFILEIMPORTEXPORTRESULTS *pdwResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ExportAllSettings( 
            /* [in] */ BSTR bstrFilePath,
            /* [out] */ VSPROFILEIMPORTEXPORTRESULTS *pdwResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AutoSaveAllSettings( 
            /* [out] */ VSPROFILEIMPORTEXPORTRESULTS *pdwResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CheckUpdateTeamSettings( 
            /* [in] */ VSPROFILETEAMSETTINGSFLAGS dwFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReportTeamSettingsChanged( 
            /* [in] */ VSPROFILETEAMSETTINGSCHANGEDFLAGS dwFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ShowProfilesUI( 
            /* [in] */ BSTR bstrActivePane) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUIFlags( 
            /* [out] */ VSPROFILEUIDISPLAYFLAGS *pdwUIFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetUIFlags( 
            /* [in] */ VSPROFILEUIDISPLAYFLAGS dwUIFlags) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsProfileDataManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsProfileDataManager * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsProfileDataManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsProfileDataManager * This);
        
        HRESULT ( STDMETHODCALLTYPE *LastResetPoint )( 
            IVsProfileDataManager * This,
            /* [out] */ BSTR *pbstrResetFilename);
        
        HRESULT ( STDMETHODCALLTYPE *GetSettingsFiles )( 
            IVsProfileDataManager * This,
            /* [in] */ VSPROFILELOCATIONS fileLocations,
            /* [out] */ IVsProfileSettingsFileCollection **ppCollection);
        
        HRESULT ( STDMETHODCALLTYPE *GetDefaultSettingsLocation )( 
            IVsProfileDataManager * This,
            /* [out] */ BSTR *pbstrSettingsLocation);
        
        HRESULT ( STDMETHODCALLTYPE *GetUniqueExportFileName )( 
            IVsProfileDataManager * This,
            /* [out] */ BSTR *pbstrExportFile);
        
        HRESULT ( STDMETHODCALLTYPE *GetSettingsFileExtension )( 
            IVsProfileDataManager * This,
            /* [out] */ BSTR *pbstrSettingsFileExtension);
        
        HRESULT ( STDMETHODCALLTYPE *GetSettingsForExport )( 
            IVsProfileDataManager * This,
            /* [out] */ IVsProfileSettingsTree **ppSettingsTree);
        
        HRESULT ( STDMETHODCALLTYPE *ExportSettings )( 
            IVsProfileDataManager * This,
            /* [in] */ BSTR bstrFilePath,
            /* [in] */ IVsProfileSettingsTree *pSettingsTree,
            /* [out] */ VSPROFILEIMPORTEXPORTRESULTS *pdwResult);
        
        HRESULT ( STDMETHODCALLTYPE *ImportSettings )( 
            IVsProfileDataManager * This,
            /* [in] */ IVsProfileSettingsTree *pSettingsTree,
            /* [out] */ VSPROFILEIMPORTEXPORTRESULTS *pdwResult);
        
        HRESULT ( STDMETHODCALLTYPE *ResetSettings )( 
            IVsProfileDataManager * This,
            /* [in] */ IVsProfileSettingsFileInfo *pFileInfo,
            /* [out] */ VSPROFILEIMPORTEXPORTRESULTS *pdwResult);
        
        HRESULT ( STDMETHODCALLTYPE *ExportAllSettings )( 
            IVsProfileDataManager * This,
            /* [in] */ BSTR bstrFilePath,
            /* [out] */ VSPROFILEIMPORTEXPORTRESULTS *pdwResult);
        
        HRESULT ( STDMETHODCALLTYPE *AutoSaveAllSettings )( 
            IVsProfileDataManager * This,
            /* [out] */ VSPROFILEIMPORTEXPORTRESULTS *pdwResult);
        
        HRESULT ( STDMETHODCALLTYPE *CheckUpdateTeamSettings )( 
            IVsProfileDataManager * This,
            /* [in] */ VSPROFILETEAMSETTINGSFLAGS dwFlags);
        
        HRESULT ( STDMETHODCALLTYPE *ReportTeamSettingsChanged )( 
            IVsProfileDataManager * This,
            /* [in] */ VSPROFILETEAMSETTINGSCHANGEDFLAGS dwFlags);
        
        HRESULT ( STDMETHODCALLTYPE *ShowProfilesUI )( 
            IVsProfileDataManager * This,
            /* [in] */ BSTR bstrActivePane);
        
        HRESULT ( STDMETHODCALLTYPE *GetUIFlags )( 
            IVsProfileDataManager * This,
            /* [out] */ VSPROFILEUIDISPLAYFLAGS *pdwUIFlags);
        
        HRESULT ( STDMETHODCALLTYPE *SetUIFlags )( 
            IVsProfileDataManager * This,
            /* [in] */ VSPROFILEUIDISPLAYFLAGS dwUIFlags);
        
        END_INTERFACE
    } IVsProfileDataManagerVtbl;

    interface IVsProfileDataManager
    {
        CONST_VTBL struct IVsProfileDataManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsProfileDataManager_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsProfileDataManager_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsProfileDataManager_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsProfileDataManager_LastResetPoint(This,pbstrResetFilename)	\
    (This)->lpVtbl -> LastResetPoint(This,pbstrResetFilename)

#define IVsProfileDataManager_GetSettingsFiles(This,fileLocations,ppCollection)	\
    (This)->lpVtbl -> GetSettingsFiles(This,fileLocations,ppCollection)

#define IVsProfileDataManager_GetDefaultSettingsLocation(This,pbstrSettingsLocation)	\
    (This)->lpVtbl -> GetDefaultSettingsLocation(This,pbstrSettingsLocation)

#define IVsProfileDataManager_GetUniqueExportFileName(This,pbstrExportFile)	\
    (This)->lpVtbl -> GetUniqueExportFileName(This,pbstrExportFile)

#define IVsProfileDataManager_GetSettingsFileExtension(This,pbstrSettingsFileExtension)	\
    (This)->lpVtbl -> GetSettingsFileExtension(This,pbstrSettingsFileExtension)

#define IVsProfileDataManager_GetSettingsForExport(This,ppSettingsTree)	\
    (This)->lpVtbl -> GetSettingsForExport(This,ppSettingsTree)

#define IVsProfileDataManager_ExportSettings(This,bstrFilePath,pSettingsTree,pdwResult)	\
    (This)->lpVtbl -> ExportSettings(This,bstrFilePath,pSettingsTree,pdwResult)

#define IVsProfileDataManager_ImportSettings(This,pSettingsTree,pdwResult)	\
    (This)->lpVtbl -> ImportSettings(This,pSettingsTree,pdwResult)

#define IVsProfileDataManager_ResetSettings(This,pFileInfo,pdwResult)	\
    (This)->lpVtbl -> ResetSettings(This,pFileInfo,pdwResult)

#define IVsProfileDataManager_ExportAllSettings(This,bstrFilePath,pdwResult)	\
    (This)->lpVtbl -> ExportAllSettings(This,bstrFilePath,pdwResult)

#define IVsProfileDataManager_AutoSaveAllSettings(This,pdwResult)	\
    (This)->lpVtbl -> AutoSaveAllSettings(This,pdwResult)

#define IVsProfileDataManager_CheckUpdateTeamSettings(This,dwFlags)	\
    (This)->lpVtbl -> CheckUpdateTeamSettings(This,dwFlags)

#define IVsProfileDataManager_ReportTeamSettingsChanged(This,dwFlags)	\
    (This)->lpVtbl -> ReportTeamSettingsChanged(This,dwFlags)

#define IVsProfileDataManager_ShowProfilesUI(This,bstrActivePane)	\
    (This)->lpVtbl -> ShowProfilesUI(This,bstrActivePane)

#define IVsProfileDataManager_GetUIFlags(This,pdwUIFlags)	\
    (This)->lpVtbl -> GetUIFlags(This,pdwUIFlags)

#define IVsProfileDataManager_SetUIFlags(This,dwUIFlags)	\
    (This)->lpVtbl -> SetUIFlags(This,dwUIFlags)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsProfileDataManager_LastResetPoint_Proxy( 
    IVsProfileDataManager * This,
    /* [out] */ BSTR *pbstrResetFilename);


void __RPC_STUB IVsProfileDataManager_LastResetPoint_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsProfileDataManager_GetSettingsFiles_Proxy( 
    IVsProfileDataManager * This,
    /* [in] */ VSPROFILELOCATIONS fileLocations,
    /* [out] */ IVsProfileSettingsFileCollection **ppCollection);


void __RPC_STUB IVsProfileDataManager_GetSettingsFiles_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsProfileDataManager_GetDefaultSettingsLocation_Proxy( 
    IVsProfileDataManager * This,
    /* [out] */ BSTR *pbstrSettingsLocation);


void __RPC_STUB IVsProfileDataManager_GetDefaultSettingsLocation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsProfileDataManager_GetUniqueExportFileName_Proxy( 
    IVsProfileDataManager * This,
    /* [out] */ BSTR *pbstrExportFile);


void __RPC_STUB IVsProfileDataManager_GetUniqueExportFileName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsProfileDataManager_GetSettingsFileExtension_Proxy( 
    IVsProfileDataManager * This,
    /* [out] */ BSTR *pbstrSettingsFileExtension);


void __RPC_STUB IVsProfileDataManager_GetSettingsFileExtension_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsProfileDataManager_GetSettingsForExport_Proxy( 
    IVsProfileDataManager * This,
    /* [out] */ IVsProfileSettingsTree **ppSettingsTree);


void __RPC_STUB IVsProfileDataManager_GetSettingsForExport_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsProfileDataManager_ExportSettings_Proxy( 
    IVsProfileDataManager * This,
    /* [in] */ BSTR bstrFilePath,
    /* [in] */ IVsProfileSettingsTree *pSettingsTree,
    /* [out] */ VSPROFILEIMPORTEXPORTRESULTS *pdwResult);


void __RPC_STUB IVsProfileDataManager_ExportSettings_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsProfileDataManager_ImportSettings_Proxy( 
    IVsProfileDataManager * This,
    /* [in] */ IVsProfileSettingsTree *pSettingsTree,
    /* [out] */ VSPROFILEIMPORTEXPORTRESULTS *pdwResult);


void __RPC_STUB IVsProfileDataManager_ImportSettings_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsProfileDataManager_ResetSettings_Proxy( 
    IVsProfileDataManager * This,
    /* [in] */ IVsProfileSettingsFileInfo *pFileInfo,
    /* [out] */ VSPROFILEIMPORTEXPORTRESULTS *pdwResult);


void __RPC_STUB IVsProfileDataManager_ResetSettings_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsProfileDataManager_ExportAllSettings_Proxy( 
    IVsProfileDataManager * This,
    /* [in] */ BSTR bstrFilePath,
    /* [out] */ VSPROFILEIMPORTEXPORTRESULTS *pdwResult);


void __RPC_STUB IVsProfileDataManager_ExportAllSettings_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsProfileDataManager_AutoSaveAllSettings_Proxy( 
    IVsProfileDataManager * This,
    /* [out] */ VSPROFILEIMPORTEXPORTRESULTS *pdwResult);


void __RPC_STUB IVsProfileDataManager_AutoSaveAllSettings_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsProfileDataManager_CheckUpdateTeamSettings_Proxy( 
    IVsProfileDataManager * This,
    /* [in] */ VSPROFILETEAMSETTINGSFLAGS dwFlags);


void __RPC_STUB IVsProfileDataManager_CheckUpdateTeamSettings_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsProfileDataManager_ReportTeamSettingsChanged_Proxy( 
    IVsProfileDataManager * This,
    /* [in] */ VSPROFILETEAMSETTINGSCHANGEDFLAGS dwFlags);


void __RPC_STUB IVsProfileDataManager_ReportTeamSettingsChanged_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsProfileDataManager_ShowProfilesUI_Proxy( 
    IVsProfileDataManager * This,
    /* [in] */ BSTR bstrActivePane);


void __RPC_STUB IVsProfileDataManager_ShowProfilesUI_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsProfileDataManager_GetUIFlags_Proxy( 
    IVsProfileDataManager * This,
    /* [out] */ VSPROFILEUIDISPLAYFLAGS *pdwUIFlags);


void __RPC_STUB IVsProfileDataManager_GetUIFlags_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsProfileDataManager_SetUIFlags_Proxy( 
    IVsProfileDataManager * This,
    /* [in] */ VSPROFILEUIDISPLAYFLAGS dwUIFlags);


void __RPC_STUB IVsProfileDataManager_SetUIFlags_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsProfileDataManager_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshell80_0711 */
/* [local] */ 

#define SID_SVsProfileDataManager IID_IVsProfileDataManager


extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0711_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0711_v0_0_s_ifspec;

#ifndef __IVsProfileDelayedActionManager_INTERFACE_DEFINED__
#define __IVsProfileDelayedActionManager_INTERFACE_DEFINED__

/* interface IVsProfileDelayedActionManager */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsProfileDelayedActionManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("10D6BECF-9AB8-4b47-8830-909881B1CFDD")
    IVsProfileDelayedActionManager : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE DelayedExportSettings( 
            BSTR bstrFilePath,
            IVsProfileSettingsTree *pSettingsTree) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DelayedImportSettings( 
            IVsProfileSettingsTree *pSettingsTree,
            BOOL fSaveCurrentSettings,
            BSTR bstrSaveFile) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DelayedResetSettings( 
            IVsProfileSettingsFileInfo *pFileInfo,
            BOOL fSaveCurrentSettings,
            BSTR bstrSaveFile) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsProfileDelayedActionManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsProfileDelayedActionManager * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsProfileDelayedActionManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsProfileDelayedActionManager * This);
        
        HRESULT ( STDMETHODCALLTYPE *DelayedExportSettings )( 
            IVsProfileDelayedActionManager * This,
            BSTR bstrFilePath,
            IVsProfileSettingsTree *pSettingsTree);
        
        HRESULT ( STDMETHODCALLTYPE *DelayedImportSettings )( 
            IVsProfileDelayedActionManager * This,
            IVsProfileSettingsTree *pSettingsTree,
            BOOL fSaveCurrentSettings,
            BSTR bstrSaveFile);
        
        HRESULT ( STDMETHODCALLTYPE *DelayedResetSettings )( 
            IVsProfileDelayedActionManager * This,
            IVsProfileSettingsFileInfo *pFileInfo,
            BOOL fSaveCurrentSettings,
            BSTR bstrSaveFile);
        
        END_INTERFACE
    } IVsProfileDelayedActionManagerVtbl;

    interface IVsProfileDelayedActionManager
    {
        CONST_VTBL struct IVsProfileDelayedActionManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsProfileDelayedActionManager_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsProfileDelayedActionManager_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsProfileDelayedActionManager_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsProfileDelayedActionManager_DelayedExportSettings(This,bstrFilePath,pSettingsTree)	\
    (This)->lpVtbl -> DelayedExportSettings(This,bstrFilePath,pSettingsTree)

#define IVsProfileDelayedActionManager_DelayedImportSettings(This,pSettingsTree,fSaveCurrentSettings,bstrSaveFile)	\
    (This)->lpVtbl -> DelayedImportSettings(This,pSettingsTree,fSaveCurrentSettings,bstrSaveFile)

#define IVsProfileDelayedActionManager_DelayedResetSettings(This,pFileInfo,fSaveCurrentSettings,bstrSaveFile)	\
    (This)->lpVtbl -> DelayedResetSettings(This,pFileInfo,fSaveCurrentSettings,bstrSaveFile)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsProfileDelayedActionManager_DelayedExportSettings_Proxy( 
    IVsProfileDelayedActionManager * This,
    BSTR bstrFilePath,
    IVsProfileSettingsTree *pSettingsTree);


void __RPC_STUB IVsProfileDelayedActionManager_DelayedExportSettings_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsProfileDelayedActionManager_DelayedImportSettings_Proxy( 
    IVsProfileDelayedActionManager * This,
    IVsProfileSettingsTree *pSettingsTree,
    BOOL fSaveCurrentSettings,
    BSTR bstrSaveFile);


void __RPC_STUB IVsProfileDelayedActionManager_DelayedImportSettings_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsProfileDelayedActionManager_DelayedResetSettings_Proxy( 
    IVsProfileDelayedActionManager * This,
    IVsProfileSettingsFileInfo *pFileInfo,
    BOOL fSaveCurrentSettings,
    BSTR bstrSaveFile);


void __RPC_STUB IVsProfileDelayedActionManager_DelayedResetSettings_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsProfileDelayedActionManager_INTERFACE_DEFINED__ */


#ifndef __IVsDeferredSaveProject_INTERFACE_DEFINED__
#define __IVsDeferredSaveProject_INTERFACE_DEFINED__

/* interface IVsDeferredSaveProject */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsDeferredSaveProject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("83B2961F-AC2B-409b-89BD-DCF698E3C402")
    IVsDeferredSaveProject : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SaveProjectToLocation( 
            /* [in] */ LPCOLESTR pszProjectFilename) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsDeferredSaveProjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsDeferredSaveProject * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsDeferredSaveProject * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsDeferredSaveProject * This);
        
        HRESULT ( STDMETHODCALLTYPE *SaveProjectToLocation )( 
            IVsDeferredSaveProject * This,
            /* [in] */ LPCOLESTR pszProjectFilename);
        
        END_INTERFACE
    } IVsDeferredSaveProjectVtbl;

    interface IVsDeferredSaveProject
    {
        CONST_VTBL struct IVsDeferredSaveProjectVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsDeferredSaveProject_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsDeferredSaveProject_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsDeferredSaveProject_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsDeferredSaveProject_SaveProjectToLocation(This,pszProjectFilename)	\
    (This)->lpVtbl -> SaveProjectToLocation(This,pszProjectFilename)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsDeferredSaveProject_SaveProjectToLocation_Proxy( 
    IVsDeferredSaveProject * This,
    /* [in] */ LPCOLESTR pszProjectFilename);


void __RPC_STUB IVsDeferredSaveProject_SaveProjectToLocation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsDeferredSaveProject_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshell80_0713 */
/* [local] */ 


enum __VSCREATENEWPROJVIADLGEXFLAGS
    {	VNPVDE_ALWAYSNEWSOLUTION	= 0x1,
	VNPVDE_OVERRIDEBROWSEBUTTON	= 0x2,
	VNPVDE_ALWAYSADDTOSOLUTION	= 0x4,
	VNPVDE_ADDNESTEDTOSELECTION	= 0x4
    } ;
typedef DWORD VSCREATENEWPROJVIADLGEXFLAGS;



extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0713_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0713_v0_0_s_ifspec;

#ifndef __IVsBrowseProjectLocation_INTERFACE_DEFINED__
#define __IVsBrowseProjectLocation_INTERFACE_DEFINED__

/* interface IVsBrowseProjectLocation */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsBrowseProjectLocation;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("368FC032-AE91-44a2-BE6B-093A8A9E63CC")
    IVsBrowseProjectLocation : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE BrowseProjectLocation( 
            /* [in] */ LPCOLESTR pszStartDirectory,
            /* [out] */ BSTR *pbstrProjectLocation) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsBrowseProjectLocationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsBrowseProjectLocation * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsBrowseProjectLocation * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsBrowseProjectLocation * This);
        
        HRESULT ( STDMETHODCALLTYPE *BrowseProjectLocation )( 
            IVsBrowseProjectLocation * This,
            /* [in] */ LPCOLESTR pszStartDirectory,
            /* [out] */ BSTR *pbstrProjectLocation);
        
        END_INTERFACE
    } IVsBrowseProjectLocationVtbl;

    interface IVsBrowseProjectLocation
    {
        CONST_VTBL struct IVsBrowseProjectLocationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsBrowseProjectLocation_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsBrowseProjectLocation_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsBrowseProjectLocation_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsBrowseProjectLocation_BrowseProjectLocation(This,pszStartDirectory,pbstrProjectLocation)	\
    (This)->lpVtbl -> BrowseProjectLocation(This,pszStartDirectory,pbstrProjectLocation)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsBrowseProjectLocation_BrowseProjectLocation_Proxy( 
    IVsBrowseProjectLocation * This,
    /* [in] */ LPCOLESTR pszStartDirectory,
    /* [out] */ BSTR *pbstrProjectLocation);


void __RPC_STUB IVsBrowseProjectLocation_BrowseProjectLocation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsBrowseProjectLocation_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshell80_0714 */
/* [local] */ 


enum __VSSAVEDEFERREDSAVEFLAGS
    {	VSDSF_HIDEADDTOSOURCECONTROL	= 0x1
    } ;
typedef DWORD VSSAVEDEFERREDSAVEFLAGS;



extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0714_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0714_v0_0_s_ifspec;

#ifndef __IVsSolution3_INTERFACE_DEFINED__
#define __IVsSolution3_INTERFACE_DEFINED__

/* interface IVsSolution3 */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsSolution3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("58DCF7BF-F14E-43ec-A7B2-9F78EDD06418")
    IVsSolution3 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CreateNewProjectViaDlgEx( 
            /* [in] */ LPCOLESTR pszDlgTitle,
            /* [in] */ LPCOLESTR pszTemplateDir,
            /* [in] */ LPCOLESTR pszExpand,
            /* [in] */ LPCOLESTR pszSelect,
            /* [in] */ LPCOLESTR pszHelpTopic,
            /* [in] */ VSCREATENEWPROJVIADLGEXFLAGS cnpvdeFlags,
            /* [in] */ IVsBrowseProjectLocation *pBrowse) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUniqueUINameOfProject( 
            /* [in] */ IVsHierarchy *pHierarchy,
            /* [out] */ BSTR *pbstrUniqueName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CheckForAndSaveDeferredSaveSolution( 
            /* [in] */ BOOL fCloseSolution,
            /* [in] */ LPCOLESTR pszMessage,
            /* [in] */ LPCOLESTR pszTitle,
            /* [in] */ VSSAVEDEFERREDSAVEFLAGS grfFlags) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsSolution3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsSolution3 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsSolution3 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsSolution3 * This);
        
        HRESULT ( STDMETHODCALLTYPE *CreateNewProjectViaDlgEx )( 
            IVsSolution3 * This,
            /* [in] */ LPCOLESTR pszDlgTitle,
            /* [in] */ LPCOLESTR pszTemplateDir,
            /* [in] */ LPCOLESTR pszExpand,
            /* [in] */ LPCOLESTR pszSelect,
            /* [in] */ LPCOLESTR pszHelpTopic,
            /* [in] */ VSCREATENEWPROJVIADLGEXFLAGS cnpvdeFlags,
            /* [in] */ IVsBrowseProjectLocation *pBrowse);
        
        HRESULT ( STDMETHODCALLTYPE *GetUniqueUINameOfProject )( 
            IVsSolution3 * This,
            /* [in] */ IVsHierarchy *pHierarchy,
            /* [out] */ BSTR *pbstrUniqueName);
        
        HRESULT ( STDMETHODCALLTYPE *CheckForAndSaveDeferredSaveSolution )( 
            IVsSolution3 * This,
            /* [in] */ BOOL fCloseSolution,
            /* [in] */ LPCOLESTR pszMessage,
            /* [in] */ LPCOLESTR pszTitle,
            /* [in] */ VSSAVEDEFERREDSAVEFLAGS grfFlags);
        
        END_INTERFACE
    } IVsSolution3Vtbl;

    interface IVsSolution3
    {
        CONST_VTBL struct IVsSolution3Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsSolution3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsSolution3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsSolution3_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsSolution3_CreateNewProjectViaDlgEx(This,pszDlgTitle,pszTemplateDir,pszExpand,pszSelect,pszHelpTopic,cnpvdeFlags,pBrowse)	\
    (This)->lpVtbl -> CreateNewProjectViaDlgEx(This,pszDlgTitle,pszTemplateDir,pszExpand,pszSelect,pszHelpTopic,cnpvdeFlags,pBrowse)

#define IVsSolution3_GetUniqueUINameOfProject(This,pHierarchy,pbstrUniqueName)	\
    (This)->lpVtbl -> GetUniqueUINameOfProject(This,pHierarchy,pbstrUniqueName)

#define IVsSolution3_CheckForAndSaveDeferredSaveSolution(This,fCloseSolution,pszMessage,pszTitle,grfFlags)	\
    (This)->lpVtbl -> CheckForAndSaveDeferredSaveSolution(This,fCloseSolution,pszMessage,pszTitle,grfFlags)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsSolution3_CreateNewProjectViaDlgEx_Proxy( 
    IVsSolution3 * This,
    /* [in] */ LPCOLESTR pszDlgTitle,
    /* [in] */ LPCOLESTR pszTemplateDir,
    /* [in] */ LPCOLESTR pszExpand,
    /* [in] */ LPCOLESTR pszSelect,
    /* [in] */ LPCOLESTR pszHelpTopic,
    /* [in] */ VSCREATENEWPROJVIADLGEXFLAGS cnpvdeFlags,
    /* [in] */ IVsBrowseProjectLocation *pBrowse);


void __RPC_STUB IVsSolution3_CreateNewProjectViaDlgEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSolution3_GetUniqueUINameOfProject_Proxy( 
    IVsSolution3 * This,
    /* [in] */ IVsHierarchy *pHierarchy,
    /* [out] */ BSTR *pbstrUniqueName);


void __RPC_STUB IVsSolution3_GetUniqueUINameOfProject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSolution3_CheckForAndSaveDeferredSaveSolution_Proxy( 
    IVsSolution3 * This,
    /* [in] */ BOOL fCloseSolution,
    /* [in] */ LPCOLESTR pszMessage,
    /* [in] */ LPCOLESTR pszTitle,
    /* [in] */ VSSAVEDEFERREDSAVEFLAGS grfFlags);


void __RPC_STUB IVsSolution3_CheckForAndSaveDeferredSaveSolution_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsSolution3_INTERFACE_DEFINED__ */


#ifndef __IVsConfigurationManagerDlg_INTERFACE_DEFINED__
#define __IVsConfigurationManagerDlg_INTERFACE_DEFINED__

/* interface IVsConfigurationManagerDlg */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsConfigurationManagerDlg;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("57F5E77F-75C9-42A3-8DAF-579C3556A0DD")
    IVsConfigurationManagerDlg : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ShowConfigurationManagerDlg( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsConfigurationManagerDlgVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsConfigurationManagerDlg * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsConfigurationManagerDlg * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsConfigurationManagerDlg * This);
        
        HRESULT ( STDMETHODCALLTYPE *ShowConfigurationManagerDlg )( 
            IVsConfigurationManagerDlg * This);
        
        END_INTERFACE
    } IVsConfigurationManagerDlgVtbl;

    interface IVsConfigurationManagerDlg
    {
        CONST_VTBL struct IVsConfigurationManagerDlgVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsConfigurationManagerDlg_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsConfigurationManagerDlg_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsConfigurationManagerDlg_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsConfigurationManagerDlg_ShowConfigurationManagerDlg(This)	\
    (This)->lpVtbl -> ShowConfigurationManagerDlg(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsConfigurationManagerDlg_ShowConfigurationManagerDlg_Proxy( 
    IVsConfigurationManagerDlg * This);


void __RPC_STUB IVsConfigurationManagerDlg_ShowConfigurationManagerDlg_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsConfigurationManagerDlg_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshell80_0716 */
/* [local] */ 

#define SID_SVsConfigurationManagerDlg IID_IVsConfigurationManagerDlg


extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0716_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0716_v0_0_s_ifspec;

#ifndef __IVsUpdateSolutionEvents3_INTERFACE_DEFINED__
#define __IVsUpdateSolutionEvents3_INTERFACE_DEFINED__

/* interface IVsUpdateSolutionEvents3 */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsUpdateSolutionEvents3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("40025C28-3303-42CA-BED8-0F3BD856BD6D")
    IVsUpdateSolutionEvents3 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnBeforeActiveSolutionCfgChange( 
            /* [in] */ IVsCfg *pOldActiveSlnCfg,
            /* [in] */ IVsCfg *pNewActiveSlnCfg) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnAfterActiveSolutionCfgChange( 
            /* [in] */ IVsCfg *pOldActiveSlnCfg,
            /* [in] */ IVsCfg *pNewActiveSlnCfg) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsUpdateSolutionEvents3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsUpdateSolutionEvents3 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsUpdateSolutionEvents3 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsUpdateSolutionEvents3 * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnBeforeActiveSolutionCfgChange )( 
            IVsUpdateSolutionEvents3 * This,
            /* [in] */ IVsCfg *pOldActiveSlnCfg,
            /* [in] */ IVsCfg *pNewActiveSlnCfg);
        
        HRESULT ( STDMETHODCALLTYPE *OnAfterActiveSolutionCfgChange )( 
            IVsUpdateSolutionEvents3 * This,
            /* [in] */ IVsCfg *pOldActiveSlnCfg,
            /* [in] */ IVsCfg *pNewActiveSlnCfg);
        
        END_INTERFACE
    } IVsUpdateSolutionEvents3Vtbl;

    interface IVsUpdateSolutionEvents3
    {
        CONST_VTBL struct IVsUpdateSolutionEvents3Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsUpdateSolutionEvents3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsUpdateSolutionEvents3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsUpdateSolutionEvents3_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsUpdateSolutionEvents3_OnBeforeActiveSolutionCfgChange(This,pOldActiveSlnCfg,pNewActiveSlnCfg)	\
    (This)->lpVtbl -> OnBeforeActiveSolutionCfgChange(This,pOldActiveSlnCfg,pNewActiveSlnCfg)

#define IVsUpdateSolutionEvents3_OnAfterActiveSolutionCfgChange(This,pOldActiveSlnCfg,pNewActiveSlnCfg)	\
    (This)->lpVtbl -> OnAfterActiveSolutionCfgChange(This,pOldActiveSlnCfg,pNewActiveSlnCfg)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsUpdateSolutionEvents3_OnBeforeActiveSolutionCfgChange_Proxy( 
    IVsUpdateSolutionEvents3 * This,
    /* [in] */ IVsCfg *pOldActiveSlnCfg,
    /* [in] */ IVsCfg *pNewActiveSlnCfg);


void __RPC_STUB IVsUpdateSolutionEvents3_OnBeforeActiveSolutionCfgChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsUpdateSolutionEvents3_OnAfterActiveSolutionCfgChange_Proxy( 
    IVsUpdateSolutionEvents3 * This,
    /* [in] */ IVsCfg *pOldActiveSlnCfg,
    /* [in] */ IVsCfg *pNewActiveSlnCfg);


void __RPC_STUB IVsUpdateSolutionEvents3_OnAfterActiveSolutionCfgChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsUpdateSolutionEvents3_INTERFACE_DEFINED__ */


#ifndef __IVsSolutionBuildManager3_INTERFACE_DEFINED__
#define __IVsSolutionBuildManager3_INTERFACE_DEFINED__

/* interface IVsSolutionBuildManager3 */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsSolutionBuildManager3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B6EA87ED-C498-4484-81AC-0BED187E28E6")
    IVsSolutionBuildManager3 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AdviseUpdateSolutionEvents3( 
            /* [in] */ IVsUpdateSolutionEvents3 *pIVsUpdateSolutionEvents3,
            /* [out] */ VSCOOKIE *pdwCookie) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnadviseUpdateSolutionEvents3( 
            /* [in] */ VSCOOKIE dwCookie) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AreProjectsUpToDate( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryBuildManagerBusyEx( 
            /* [out] */ DWORD *pdwBuildManagerOperation) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsSolutionBuildManager3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsSolutionBuildManager3 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsSolutionBuildManager3 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsSolutionBuildManager3 * This);
        
        HRESULT ( STDMETHODCALLTYPE *AdviseUpdateSolutionEvents3 )( 
            IVsSolutionBuildManager3 * This,
            /* [in] */ IVsUpdateSolutionEvents3 *pIVsUpdateSolutionEvents3,
            /* [out] */ VSCOOKIE *pdwCookie);
        
        HRESULT ( STDMETHODCALLTYPE *UnadviseUpdateSolutionEvents3 )( 
            IVsSolutionBuildManager3 * This,
            /* [in] */ VSCOOKIE dwCookie);
        
        HRESULT ( STDMETHODCALLTYPE *AreProjectsUpToDate )( 
            IVsSolutionBuildManager3 * This);
        
        HRESULT ( STDMETHODCALLTYPE *QueryBuildManagerBusyEx )( 
            IVsSolutionBuildManager3 * This,
            /* [out] */ DWORD *pdwBuildManagerOperation);
        
        END_INTERFACE
    } IVsSolutionBuildManager3Vtbl;

    interface IVsSolutionBuildManager3
    {
        CONST_VTBL struct IVsSolutionBuildManager3Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsSolutionBuildManager3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsSolutionBuildManager3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsSolutionBuildManager3_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsSolutionBuildManager3_AdviseUpdateSolutionEvents3(This,pIVsUpdateSolutionEvents3,pdwCookie)	\
    (This)->lpVtbl -> AdviseUpdateSolutionEvents3(This,pIVsUpdateSolutionEvents3,pdwCookie)

#define IVsSolutionBuildManager3_UnadviseUpdateSolutionEvents3(This,dwCookie)	\
    (This)->lpVtbl -> UnadviseUpdateSolutionEvents3(This,dwCookie)

#define IVsSolutionBuildManager3_AreProjectsUpToDate(This)	\
    (This)->lpVtbl -> AreProjectsUpToDate(This)

#define IVsSolutionBuildManager3_QueryBuildManagerBusyEx(This,pdwBuildManagerOperation)	\
    (This)->lpVtbl -> QueryBuildManagerBusyEx(This,pdwBuildManagerOperation)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsSolutionBuildManager3_AdviseUpdateSolutionEvents3_Proxy( 
    IVsSolutionBuildManager3 * This,
    /* [in] */ IVsUpdateSolutionEvents3 *pIVsUpdateSolutionEvents3,
    /* [out] */ VSCOOKIE *pdwCookie);


void __RPC_STUB IVsSolutionBuildManager3_AdviseUpdateSolutionEvents3_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSolutionBuildManager3_UnadviseUpdateSolutionEvents3_Proxy( 
    IVsSolutionBuildManager3 * This,
    /* [in] */ VSCOOKIE dwCookie);


void __RPC_STUB IVsSolutionBuildManager3_UnadviseUpdateSolutionEvents3_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSolutionBuildManager3_AreProjectsUpToDate_Proxy( 
    IVsSolutionBuildManager3 * This);


void __RPC_STUB IVsSolutionBuildManager3_AreProjectsUpToDate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSolutionBuildManager3_QueryBuildManagerBusyEx_Proxy( 
    IVsSolutionBuildManager3 * This,
    /* [out] */ DWORD *pdwBuildManagerOperation);


void __RPC_STUB IVsSolutionBuildManager3_QueryBuildManagerBusyEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsSolutionBuildManager3_INTERFACE_DEFINED__ */


#ifndef __IVsSingleFileGeneratorFactory_INTERFACE_DEFINED__
#define __IVsSingleFileGeneratorFactory_INTERFACE_DEFINED__

/* interface IVsSingleFileGeneratorFactory */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsSingleFileGeneratorFactory;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3ADA7A5D-591E-4c9e-8B87-5E33F8E64AA8")
    IVsSingleFileGeneratorFactory : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetDefaultGenerator( 
            /* [in] */ LPCOLESTR wszFilename,
            /* [retval][out] */ BSTR *pbstrGenProgID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateGeneratorInstance( 
            /* [in] */ LPCOLESTR wszProgId,
            /* [out] */ BOOL *pbGeneratesDesignTimeSource,
            /* [out] */ BOOL *pbUseTempPEFlag,
            /* [out] */ IVsSingleFileGenerator **ppGenerate) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetGeneratorInformation( 
            /* [in] */ LPCWSTR wszProgID,
            /* [out] */ BOOL *pbGeneratesDesignTimeSource,
            /* [out] */ BOOL *pbUseTempPEFlag,
            /* [out] */ GUID *pguidGenerator) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsSingleFileGeneratorFactoryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsSingleFileGeneratorFactory * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsSingleFileGeneratorFactory * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsSingleFileGeneratorFactory * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetDefaultGenerator )( 
            IVsSingleFileGeneratorFactory * This,
            /* [in] */ LPCOLESTR wszFilename,
            /* [retval][out] */ BSTR *pbstrGenProgID);
        
        HRESULT ( STDMETHODCALLTYPE *CreateGeneratorInstance )( 
            IVsSingleFileGeneratorFactory * This,
            /* [in] */ LPCOLESTR wszProgId,
            /* [out] */ BOOL *pbGeneratesDesignTimeSource,
            /* [out] */ BOOL *pbUseTempPEFlag,
            /* [out] */ IVsSingleFileGenerator **ppGenerate);
        
        HRESULT ( STDMETHODCALLTYPE *GetGeneratorInformation )( 
            IVsSingleFileGeneratorFactory * This,
            /* [in] */ LPCWSTR wszProgID,
            /* [out] */ BOOL *pbGeneratesDesignTimeSource,
            /* [out] */ BOOL *pbUseTempPEFlag,
            /* [out] */ GUID *pguidGenerator);
        
        END_INTERFACE
    } IVsSingleFileGeneratorFactoryVtbl;

    interface IVsSingleFileGeneratorFactory
    {
        CONST_VTBL struct IVsSingleFileGeneratorFactoryVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsSingleFileGeneratorFactory_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsSingleFileGeneratorFactory_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsSingleFileGeneratorFactory_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsSingleFileGeneratorFactory_GetDefaultGenerator(This,wszFilename,pbstrGenProgID)	\
    (This)->lpVtbl -> GetDefaultGenerator(This,wszFilename,pbstrGenProgID)

#define IVsSingleFileGeneratorFactory_CreateGeneratorInstance(This,wszProgId,pbGeneratesDesignTimeSource,pbUseTempPEFlag,ppGenerate)	\
    (This)->lpVtbl -> CreateGeneratorInstance(This,wszProgId,pbGeneratesDesignTimeSource,pbUseTempPEFlag,ppGenerate)

#define IVsSingleFileGeneratorFactory_GetGeneratorInformation(This,wszProgID,pbGeneratesDesignTimeSource,pbUseTempPEFlag,pguidGenerator)	\
    (This)->lpVtbl -> GetGeneratorInformation(This,wszProgID,pbGeneratesDesignTimeSource,pbUseTempPEFlag,pguidGenerator)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsSingleFileGeneratorFactory_GetDefaultGenerator_Proxy( 
    IVsSingleFileGeneratorFactory * This,
    /* [in] */ LPCOLESTR wszFilename,
    /* [retval][out] */ BSTR *pbstrGenProgID);


void __RPC_STUB IVsSingleFileGeneratorFactory_GetDefaultGenerator_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSingleFileGeneratorFactory_CreateGeneratorInstance_Proxy( 
    IVsSingleFileGeneratorFactory * This,
    /* [in] */ LPCOLESTR wszProgId,
    /* [out] */ BOOL *pbGeneratesDesignTimeSource,
    /* [out] */ BOOL *pbUseTempPEFlag,
    /* [out] */ IVsSingleFileGenerator **ppGenerate);


void __RPC_STUB IVsSingleFileGeneratorFactory_CreateGeneratorInstance_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSingleFileGeneratorFactory_GetGeneratorInformation_Proxy( 
    IVsSingleFileGeneratorFactory * This,
    /* [in] */ LPCWSTR wszProgID,
    /* [out] */ BOOL *pbGeneratesDesignTimeSource,
    /* [out] */ BOOL *pbUseTempPEFlag,
    /* [out] */ GUID *pguidGenerator);


void __RPC_STUB IVsSingleFileGeneratorFactory_GetGeneratorInformation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsSingleFileGeneratorFactory_INTERFACE_DEFINED__ */


#ifndef __IVsCommunitySearch_INTERFACE_DEFINED__
#define __IVsCommunitySearch_INTERFACE_DEFINED__

/* interface IVsCommunitySearch */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsCommunitySearch;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7A30D0C5-C357-425A-8693-241D47EA16C6")
    IVsCommunitySearch : public IUnknown
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IVsCommunitySearchVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsCommunitySearch * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsCommunitySearch * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsCommunitySearch * This);
        
        END_INTERFACE
    } IVsCommunitySearchVtbl;

    interface IVsCommunitySearch
    {
        CONST_VTBL struct IVsCommunitySearchVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsCommunitySearch_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsCommunitySearch_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsCommunitySearch_Release(This)	\
    (This)->lpVtbl -> Release(This)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVsCommunitySearch_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshell80_0720 */
/* [local] */ 

#define SID_SVsCommunitySearch IID_IVsCommunitySearch


extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0720_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0720_v0_0_s_ifspec;

#ifndef __IVsCommunityProviderInfo_INTERFACE_DEFINED__
#define __IVsCommunityProviderInfo_INTERFACE_DEFINED__

/* interface IVsCommunityProviderInfo */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsCommunityProviderInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CD99184E-6142-4652-B10A-16AB2A58EBCE")
    IVsCommunityProviderInfo : public IUnknown
    {
    public:
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pRetVal) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Description( 
            /* [retval][out] */ BSTR *pRetVal) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Url( 
            /* [retval][out] */ BSTR *pRetVal) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_LogoUrl( 
            /* [retval][out] */ BSTR *pRetVal) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_SearchUrl( 
            /* [retval][out] */ BSTR *pRetVal) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_PostUrl( 
            /* [retval][out] */ BSTR *pRetVal) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_SupportPostSnippet( 
            /* [retval][out] */ VARIANT_BOOL *pRetVal) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_SupportPostTemplate( 
            /* [retval][out] */ VARIANT_BOOL *pRetVal) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_CountryRegion( 
            /* [retval][out] */ BSTR *pRetVal) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Language( 
            /* [retval][out] */ BSTR *pRetVal) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_Enabled( 
            /* [retval][out] */ VARIANT_BOOL *pRetVal) = 0;
        
        virtual /* [propget] */ HRESULT STDMETHODCALLTYPE get_IsCustom( 
            /* [retval][out] */ VARIANT_BOOL *pRetVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsCommunityProviderInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsCommunityProviderInfo * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsCommunityProviderInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsCommunityProviderInfo * This);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IVsCommunityProviderInfo * This,
            /* [retval][out] */ BSTR *pRetVal);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Description )( 
            IVsCommunityProviderInfo * This,
            /* [retval][out] */ BSTR *pRetVal);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Url )( 
            IVsCommunityProviderInfo * This,
            /* [retval][out] */ BSTR *pRetVal);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_LogoUrl )( 
            IVsCommunityProviderInfo * This,
            /* [retval][out] */ BSTR *pRetVal);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_SearchUrl )( 
            IVsCommunityProviderInfo * This,
            /* [retval][out] */ BSTR *pRetVal);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_PostUrl )( 
            IVsCommunityProviderInfo * This,
            /* [retval][out] */ BSTR *pRetVal);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_SupportPostSnippet )( 
            IVsCommunityProviderInfo * This,
            /* [retval][out] */ VARIANT_BOOL *pRetVal);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_SupportPostTemplate )( 
            IVsCommunityProviderInfo * This,
            /* [retval][out] */ VARIANT_BOOL *pRetVal);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_CountryRegion )( 
            IVsCommunityProviderInfo * This,
            /* [retval][out] */ BSTR *pRetVal);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Language )( 
            IVsCommunityProviderInfo * This,
            /* [retval][out] */ BSTR *pRetVal);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_Enabled )( 
            IVsCommunityProviderInfo * This,
            /* [retval][out] */ VARIANT_BOOL *pRetVal);
        
        /* [propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsCustom )( 
            IVsCommunityProviderInfo * This,
            /* [retval][out] */ VARIANT_BOOL *pRetVal);
        
        END_INTERFACE
    } IVsCommunityProviderInfoVtbl;

    interface IVsCommunityProviderInfo
    {
        CONST_VTBL struct IVsCommunityProviderInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsCommunityProviderInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsCommunityProviderInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsCommunityProviderInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsCommunityProviderInfo_get_Name(This,pRetVal)	\
    (This)->lpVtbl -> get_Name(This,pRetVal)

#define IVsCommunityProviderInfo_get_Description(This,pRetVal)	\
    (This)->lpVtbl -> get_Description(This,pRetVal)

#define IVsCommunityProviderInfo_get_Url(This,pRetVal)	\
    (This)->lpVtbl -> get_Url(This,pRetVal)

#define IVsCommunityProviderInfo_get_LogoUrl(This,pRetVal)	\
    (This)->lpVtbl -> get_LogoUrl(This,pRetVal)

#define IVsCommunityProviderInfo_get_SearchUrl(This,pRetVal)	\
    (This)->lpVtbl -> get_SearchUrl(This,pRetVal)

#define IVsCommunityProviderInfo_get_PostUrl(This,pRetVal)	\
    (This)->lpVtbl -> get_PostUrl(This,pRetVal)

#define IVsCommunityProviderInfo_get_SupportPostSnippet(This,pRetVal)	\
    (This)->lpVtbl -> get_SupportPostSnippet(This,pRetVal)

#define IVsCommunityProviderInfo_get_SupportPostTemplate(This,pRetVal)	\
    (This)->lpVtbl -> get_SupportPostTemplate(This,pRetVal)

#define IVsCommunityProviderInfo_get_CountryRegion(This,pRetVal)	\
    (This)->lpVtbl -> get_CountryRegion(This,pRetVal)

#define IVsCommunityProviderInfo_get_Language(This,pRetVal)	\
    (This)->lpVtbl -> get_Language(This,pRetVal)

#define IVsCommunityProviderInfo_get_Enabled(This,pRetVal)	\
    (This)->lpVtbl -> get_Enabled(This,pRetVal)

#define IVsCommunityProviderInfo_get_IsCustom(This,pRetVal)	\
    (This)->lpVtbl -> get_IsCustom(This,pRetVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget] */ HRESULT STDMETHODCALLTYPE IVsCommunityProviderInfo_get_Name_Proxy( 
    IVsCommunityProviderInfo * This,
    /* [retval][out] */ BSTR *pRetVal);


void __RPC_STUB IVsCommunityProviderInfo_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IVsCommunityProviderInfo_get_Description_Proxy( 
    IVsCommunityProviderInfo * This,
    /* [retval][out] */ BSTR *pRetVal);


void __RPC_STUB IVsCommunityProviderInfo_get_Description_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IVsCommunityProviderInfo_get_Url_Proxy( 
    IVsCommunityProviderInfo * This,
    /* [retval][out] */ BSTR *pRetVal);


void __RPC_STUB IVsCommunityProviderInfo_get_Url_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IVsCommunityProviderInfo_get_LogoUrl_Proxy( 
    IVsCommunityProviderInfo * This,
    /* [retval][out] */ BSTR *pRetVal);


void __RPC_STUB IVsCommunityProviderInfo_get_LogoUrl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IVsCommunityProviderInfo_get_SearchUrl_Proxy( 
    IVsCommunityProviderInfo * This,
    /* [retval][out] */ BSTR *pRetVal);


void __RPC_STUB IVsCommunityProviderInfo_get_SearchUrl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IVsCommunityProviderInfo_get_PostUrl_Proxy( 
    IVsCommunityProviderInfo * This,
    /* [retval][out] */ BSTR *pRetVal);


void __RPC_STUB IVsCommunityProviderInfo_get_PostUrl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IVsCommunityProviderInfo_get_SupportPostSnippet_Proxy( 
    IVsCommunityProviderInfo * This,
    /* [retval][out] */ VARIANT_BOOL *pRetVal);


void __RPC_STUB IVsCommunityProviderInfo_get_SupportPostSnippet_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IVsCommunityProviderInfo_get_SupportPostTemplate_Proxy( 
    IVsCommunityProviderInfo * This,
    /* [retval][out] */ VARIANT_BOOL *pRetVal);


void __RPC_STUB IVsCommunityProviderInfo_get_SupportPostTemplate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IVsCommunityProviderInfo_get_CountryRegion_Proxy( 
    IVsCommunityProviderInfo * This,
    /* [retval][out] */ BSTR *pRetVal);


void __RPC_STUB IVsCommunityProviderInfo_get_CountryRegion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IVsCommunityProviderInfo_get_Language_Proxy( 
    IVsCommunityProviderInfo * This,
    /* [retval][out] */ BSTR *pRetVal);


void __RPC_STUB IVsCommunityProviderInfo_get_Language_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IVsCommunityProviderInfo_get_Enabled_Proxy( 
    IVsCommunityProviderInfo * This,
    /* [retval][out] */ VARIANT_BOOL *pRetVal);


void __RPC_STUB IVsCommunityProviderInfo_get_Enabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget] */ HRESULT STDMETHODCALLTYPE IVsCommunityProviderInfo_get_IsCustom_Proxy( 
    IVsCommunityProviderInfo * This,
    /* [retval][out] */ VARIANT_BOOL *pRetVal);


void __RPC_STUB IVsCommunityProviderInfo_get_IsCustom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsCommunityProviderInfo_INTERFACE_DEFINED__ */


#ifndef __IVsCommunityProviders_INTERFACE_DEFINED__
#define __IVsCommunityProviders_INTERFACE_DEFINED__

/* interface IVsCommunityProviders */
/* [object][unique][version][uuid][local] */ 


EXTERN_C const IID IID_IVsCommunityProviders;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F3050DE0-EF94-404F-906F-99346777FFAB")
    IVsCommunityProviders : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetAllProviderInfo( 
            /* [retval][out] */ SAFEARRAY * *pRetVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetProviderInfo( 
            /* [in] */ BSTR providerName,
            /* [retval][out] */ IVsCommunityProviderInfo **pRetVal) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnableProvider( 
            /* [in] */ BSTR providerName,
            /* [in] */ VARIANT_BOOL enable) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnableUnknownProviders( 
            /* [in] */ VARIANT_BOOL enable) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsCommunityProvidersVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsCommunityProviders * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsCommunityProviders * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsCommunityProviders * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetAllProviderInfo )( 
            IVsCommunityProviders * This,
            /* [retval][out] */ SAFEARRAY * *pRetVal);
        
        HRESULT ( STDMETHODCALLTYPE *GetProviderInfo )( 
            IVsCommunityProviders * This,
            /* [in] */ BSTR providerName,
            /* [retval][out] */ IVsCommunityProviderInfo **pRetVal);
        
        HRESULT ( STDMETHODCALLTYPE *EnableProvider )( 
            IVsCommunityProviders * This,
            /* [in] */ BSTR providerName,
            /* [in] */ VARIANT_BOOL enable);
        
        HRESULT ( STDMETHODCALLTYPE *EnableUnknownProviders )( 
            IVsCommunityProviders * This,
            /* [in] */ VARIANT_BOOL enable);
        
        END_INTERFACE
    } IVsCommunityProvidersVtbl;

    interface IVsCommunityProviders
    {
        CONST_VTBL struct IVsCommunityProvidersVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsCommunityProviders_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsCommunityProviders_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsCommunityProviders_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsCommunityProviders_GetAllProviderInfo(This,pRetVal)	\
    (This)->lpVtbl -> GetAllProviderInfo(This,pRetVal)

#define IVsCommunityProviders_GetProviderInfo(This,providerName,pRetVal)	\
    (This)->lpVtbl -> GetProviderInfo(This,providerName,pRetVal)

#define IVsCommunityProviders_EnableProvider(This,providerName,enable)	\
    (This)->lpVtbl -> EnableProvider(This,providerName,enable)

#define IVsCommunityProviders_EnableUnknownProviders(This,enable)	\
    (This)->lpVtbl -> EnableUnknownProviders(This,enable)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsCommunityProviders_GetAllProviderInfo_Proxy( 
    IVsCommunityProviders * This,
    /* [retval][out] */ SAFEARRAY * *pRetVal);


void __RPC_STUB IVsCommunityProviders_GetAllProviderInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsCommunityProviders_GetProviderInfo_Proxy( 
    IVsCommunityProviders * This,
    /* [in] */ BSTR providerName,
    /* [retval][out] */ IVsCommunityProviderInfo **pRetVal);


void __RPC_STUB IVsCommunityProviders_GetProviderInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsCommunityProviders_EnableProvider_Proxy( 
    IVsCommunityProviders * This,
    /* [in] */ BSTR providerName,
    /* [in] */ VARIANT_BOOL enable);


void __RPC_STUB IVsCommunityProviders_EnableProvider_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsCommunityProviders_EnableUnknownProviders_Proxy( 
    IVsCommunityProviders * This,
    /* [in] */ VARIANT_BOOL enable);


void __RPC_STUB IVsCommunityProviders_EnableUnknownProviders_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsCommunityProviders_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshell80_0722 */
/* [local] */ 


enum __VSMEINIT2
    {	MD_ITEMICONSUPPORT	= 0x10000
    } ;
typedef DWORD VSMEINIT2;


enum __MENUEDITOR_TRANSACTION
    {	MENUEDITOR_TRANSACTION_DISCARD	= -1,
	MENUEDITOR_TRANSACTION_ALL	= MENUEDITOR_TRANSACTION_DISCARD + 1,
	MENUEDITOR_TRANSACTION_CUT	= MENUEDITOR_TRANSACTION_ALL + 1,
	MENUEDITOR_TRANSACTION_PASTE	= MENUEDITOR_TRANSACTION_CUT + 1,
	MENUEDITOR_TRANSACTION_COPY	= MENUEDITOR_TRANSACTION_PASTE + 1,
	MENUEDITOR_TRANSACTION_DELETE	= MENUEDITOR_TRANSACTION_COPY + 1
    } ;
typedef DWORD MENUEDITOR_TRANSACTION;



extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0722_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0722_v0_0_s_ifspec;

#ifndef __IVsMenuEditorTransactionEvents_INTERFACE_DEFINED__
#define __IVsMenuEditorTransactionEvents_INTERFACE_DEFINED__

/* interface IVsMenuEditorTransactionEvents */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsMenuEditorTransactionEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A0E39F2D-1333-4e71-B3AC-FC7BBFD92D9E")
    IVsMenuEditorTransactionEvents : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE BeginTransaction( 
            /* [in] */ MENUEDITOR_TRANSACTION __MIDL_0011) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EndTransaction( 
            /* [in] */ MENUEDITOR_TRANSACTION __MIDL_0012) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsMenuEditorTransactionEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsMenuEditorTransactionEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsMenuEditorTransactionEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsMenuEditorTransactionEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *BeginTransaction )( 
            IVsMenuEditorTransactionEvents * This,
            /* [in] */ MENUEDITOR_TRANSACTION __MIDL_0011);
        
        HRESULT ( STDMETHODCALLTYPE *EndTransaction )( 
            IVsMenuEditorTransactionEvents * This,
            /* [in] */ MENUEDITOR_TRANSACTION __MIDL_0012);
        
        END_INTERFACE
    } IVsMenuEditorTransactionEventsVtbl;

    interface IVsMenuEditorTransactionEvents
    {
        CONST_VTBL struct IVsMenuEditorTransactionEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsMenuEditorTransactionEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsMenuEditorTransactionEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsMenuEditorTransactionEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsMenuEditorTransactionEvents_BeginTransaction(This,__MIDL_0011)	\
    (This)->lpVtbl -> BeginTransaction(This,__MIDL_0011)

#define IVsMenuEditorTransactionEvents_EndTransaction(This,__MIDL_0012)	\
    (This)->lpVtbl -> EndTransaction(This,__MIDL_0012)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsMenuEditorTransactionEvents_BeginTransaction_Proxy( 
    IVsMenuEditorTransactionEvents * This,
    /* [in] */ MENUEDITOR_TRANSACTION __MIDL_0011);


void __RPC_STUB IVsMenuEditorTransactionEvents_BeginTransaction_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsMenuEditorTransactionEvents_EndTransaction_Proxy( 
    IVsMenuEditorTransactionEvents * This,
    /* [in] */ MENUEDITOR_TRANSACTION __MIDL_0012);


void __RPC_STUB IVsMenuEditorTransactionEvents_EndTransaction_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsMenuEditorTransactionEvents_INTERFACE_DEFINED__ */


#ifndef __IVsThreadedWaitDialog_INTERFACE_DEFINED__
#define __IVsThreadedWaitDialog_INTERFACE_DEFINED__

/* interface IVsThreadedWaitDialog */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsThreadedWaitDialog;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E051C7B7-7648-473c-8A7D-2B9554A31F9D")
    IVsThreadedWaitDialog : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE StartWaitDialog( 
            /* [in] */ BSTR bstrWaitCaption,
            /* [in] */ BSTR bstrWaitMessage,
            /* [in] */ BSTR bstrIfTruncateAppend,
            /* [in] */ BOOL fCancellable,
            /* [in] */ VARIANT varStatusBmpAnim,
            /* [in] */ BSTR bstrStatusBarText) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EndWaitDialog( 
            BOOL *pfCancelled) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GiveTimeSlice( 
            /* [in] */ BSTR bstrUpdatedWaitMessage,
            /* [in] */ BSTR bstrIfTruncateAppend,
            /* [in] */ BOOL fDisableCancel,
            /* [out] */ BOOL *pfCancelled) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsThreadedWaitDialogVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsThreadedWaitDialog * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsThreadedWaitDialog * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsThreadedWaitDialog * This);
        
        HRESULT ( STDMETHODCALLTYPE *StartWaitDialog )( 
            IVsThreadedWaitDialog * This,
            /* [in] */ BSTR bstrWaitCaption,
            /* [in] */ BSTR bstrWaitMessage,
            /* [in] */ BSTR bstrIfTruncateAppend,
            /* [in] */ BOOL fCancellable,
            /* [in] */ VARIANT varStatusBmpAnim,
            /* [in] */ BSTR bstrStatusBarText);
        
        HRESULT ( STDMETHODCALLTYPE *EndWaitDialog )( 
            IVsThreadedWaitDialog * This,
            BOOL *pfCancelled);
        
        HRESULT ( STDMETHODCALLTYPE *GiveTimeSlice )( 
            IVsThreadedWaitDialog * This,
            /* [in] */ BSTR bstrUpdatedWaitMessage,
            /* [in] */ BSTR bstrIfTruncateAppend,
            /* [in] */ BOOL fDisableCancel,
            /* [out] */ BOOL *pfCancelled);
        
        END_INTERFACE
    } IVsThreadedWaitDialogVtbl;

    interface IVsThreadedWaitDialog
    {
        CONST_VTBL struct IVsThreadedWaitDialogVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsThreadedWaitDialog_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsThreadedWaitDialog_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsThreadedWaitDialog_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsThreadedWaitDialog_StartWaitDialog(This,bstrWaitCaption,bstrWaitMessage,bstrIfTruncateAppend,fCancellable,varStatusBmpAnim,bstrStatusBarText)	\
    (This)->lpVtbl -> StartWaitDialog(This,bstrWaitCaption,bstrWaitMessage,bstrIfTruncateAppend,fCancellable,varStatusBmpAnim,bstrStatusBarText)

#define IVsThreadedWaitDialog_EndWaitDialog(This,pfCancelled)	\
    (This)->lpVtbl -> EndWaitDialog(This,pfCancelled)

#define IVsThreadedWaitDialog_GiveTimeSlice(This,bstrUpdatedWaitMessage,bstrIfTruncateAppend,fDisableCancel,pfCancelled)	\
    (This)->lpVtbl -> GiveTimeSlice(This,bstrUpdatedWaitMessage,bstrIfTruncateAppend,fDisableCancel,pfCancelled)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsThreadedWaitDialog_StartWaitDialog_Proxy( 
    IVsThreadedWaitDialog * This,
    /* [in] */ BSTR bstrWaitCaption,
    /* [in] */ BSTR bstrWaitMessage,
    /* [in] */ BSTR bstrIfTruncateAppend,
    /* [in] */ BOOL fCancellable,
    /* [in] */ VARIANT varStatusBmpAnim,
    /* [in] */ BSTR bstrStatusBarText);


void __RPC_STUB IVsThreadedWaitDialog_StartWaitDialog_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsThreadedWaitDialog_EndWaitDialog_Proxy( 
    IVsThreadedWaitDialog * This,
    BOOL *pfCancelled);


void __RPC_STUB IVsThreadedWaitDialog_EndWaitDialog_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsThreadedWaitDialog_GiveTimeSlice_Proxy( 
    IVsThreadedWaitDialog * This,
    /* [in] */ BSTR bstrUpdatedWaitMessage,
    /* [in] */ BSTR bstrIfTruncateAppend,
    /* [in] */ BOOL fDisableCancel,
    /* [out] */ BOOL *pfCancelled);


void __RPC_STUB IVsThreadedWaitDialog_GiveTimeSlice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsThreadedWaitDialog_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshell80_0724 */
/* [local] */ 

#define SID_SVsThreadedWaitDialog IID_IVsThreadedWaitDialog


extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0724_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0724_v0_0_s_ifspec;

#ifndef __IVsProfilesManagerUI_INTERFACE_DEFINED__
#define __IVsProfilesManagerUI_INTERFACE_DEFINED__

/* interface IVsProfilesManagerUI */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsProfilesManagerUI;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D06B7887-893C-439c-A231-8BF3E5335E30")
    IVsProfilesManagerUI : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ShowProfilesUI( 
            IVsProfileDelayedActionManager *pDoDelayedAction,
            BSTR bstrActivePane) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsProfilesManagerUIVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsProfilesManagerUI * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsProfilesManagerUI * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsProfilesManagerUI * This);
        
        HRESULT ( STDMETHODCALLTYPE *ShowProfilesUI )( 
            IVsProfilesManagerUI * This,
            IVsProfileDelayedActionManager *pDoDelayedAction,
            BSTR bstrActivePane);
        
        END_INTERFACE
    } IVsProfilesManagerUIVtbl;

    interface IVsProfilesManagerUI
    {
        CONST_VTBL struct IVsProfilesManagerUIVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsProfilesManagerUI_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsProfilesManagerUI_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsProfilesManagerUI_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsProfilesManagerUI_ShowProfilesUI(This,pDoDelayedAction,bstrActivePane)	\
    (This)->lpVtbl -> ShowProfilesUI(This,pDoDelayedAction,bstrActivePane)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsProfilesManagerUI_ShowProfilesUI_Proxy( 
    IVsProfilesManagerUI * This,
    IVsProfileDelayedActionManager *pDoDelayedAction,
    BSTR bstrActivePane);


void __RPC_STUB IVsProfilesManagerUI_ShowProfilesUI_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsProfilesManagerUI_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshell80_0725 */
/* [local] */ 

#define SID_SVsProfilesManagerUI IID_IVsProfilesManagerUI


extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0725_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0725_v0_0_s_ifspec;

#ifndef __IVsXMLMemberData3_INTERFACE_DEFINED__
#define __IVsXMLMemberData3_INTERFACE_DEFINED__

/* interface IVsXMLMemberData3 */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsXMLMemberData3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C04165C2-3CAC-4508-B651-DD24906DBD4D")
    IVsXMLMemberData3 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetSummaryText( 
            /* [out] */ BSTR *pbstrSummary) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetParamCount( 
            /* [out] */ long *piParams) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetParamTextAt( 
            /* [in] */ long iParam,
            /* [out] */ BSTR *pbstrName,
            /* [out] */ BSTR *pbstrText) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetReturnsText( 
            /* [out] */ BSTR *pbstrReturns) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRemarksText( 
            /* [out] */ BSTR *pbstrRemarks) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetExceptionCount( 
            /* [out] */ long *piExceptions) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetExceptionTextAt( 
            /* [in] */ long iException,
            /* [out] */ BSTR *pbstrType,
            /* [out] */ BSTR *pbstrText) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFilterPriority( 
            /* [out] */ long *piFilterPriority) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCompletionListText( 
            /* [out] */ BSTR *pbstrCompletionList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCompletionListTextAt( 
            /* [in] */ long iParam,
            /* [out] */ BSTR *pbstrCompletionList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPermissionSet( 
            /* [out] */ BSTR *pbstrPermissionSetXML) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTypeParamCount( 
            /* [out] */ long *piTypeParams) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTypeParamTextAt( 
            /* [in] */ long iTypeParam,
            /* [out] */ BSTR *pbstrName,
            /* [out] */ BSTR *pbstrText) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsXMLMemberData3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsXMLMemberData3 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsXMLMemberData3 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsXMLMemberData3 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetSummaryText )( 
            IVsXMLMemberData3 * This,
            /* [out] */ BSTR *pbstrSummary);
        
        HRESULT ( STDMETHODCALLTYPE *GetParamCount )( 
            IVsXMLMemberData3 * This,
            /* [out] */ long *piParams);
        
        HRESULT ( STDMETHODCALLTYPE *GetParamTextAt )( 
            IVsXMLMemberData3 * This,
            /* [in] */ long iParam,
            /* [out] */ BSTR *pbstrName,
            /* [out] */ BSTR *pbstrText);
        
        HRESULT ( STDMETHODCALLTYPE *GetReturnsText )( 
            IVsXMLMemberData3 * This,
            /* [out] */ BSTR *pbstrReturns);
        
        HRESULT ( STDMETHODCALLTYPE *GetRemarksText )( 
            IVsXMLMemberData3 * This,
            /* [out] */ BSTR *pbstrRemarks);
        
        HRESULT ( STDMETHODCALLTYPE *GetExceptionCount )( 
            IVsXMLMemberData3 * This,
            /* [out] */ long *piExceptions);
        
        HRESULT ( STDMETHODCALLTYPE *GetExceptionTextAt )( 
            IVsXMLMemberData3 * This,
            /* [in] */ long iException,
            /* [out] */ BSTR *pbstrType,
            /* [out] */ BSTR *pbstrText);
        
        HRESULT ( STDMETHODCALLTYPE *GetFilterPriority )( 
            IVsXMLMemberData3 * This,
            /* [out] */ long *piFilterPriority);
        
        HRESULT ( STDMETHODCALLTYPE *GetCompletionListText )( 
            IVsXMLMemberData3 * This,
            /* [out] */ BSTR *pbstrCompletionList);
        
        HRESULT ( STDMETHODCALLTYPE *GetCompletionListTextAt )( 
            IVsXMLMemberData3 * This,
            /* [in] */ long iParam,
            /* [out] */ BSTR *pbstrCompletionList);
        
        HRESULT ( STDMETHODCALLTYPE *GetPermissionSet )( 
            IVsXMLMemberData3 * This,
            /* [out] */ BSTR *pbstrPermissionSetXML);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeParamCount )( 
            IVsXMLMemberData3 * This,
            /* [out] */ long *piTypeParams);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeParamTextAt )( 
            IVsXMLMemberData3 * This,
            /* [in] */ long iTypeParam,
            /* [out] */ BSTR *pbstrName,
            /* [out] */ BSTR *pbstrText);
        
        END_INTERFACE
    } IVsXMLMemberData3Vtbl;

    interface IVsXMLMemberData3
    {
        CONST_VTBL struct IVsXMLMemberData3Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsXMLMemberData3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsXMLMemberData3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsXMLMemberData3_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsXMLMemberData3_GetSummaryText(This,pbstrSummary)	\
    (This)->lpVtbl -> GetSummaryText(This,pbstrSummary)

#define IVsXMLMemberData3_GetParamCount(This,piParams)	\
    (This)->lpVtbl -> GetParamCount(This,piParams)

#define IVsXMLMemberData3_GetParamTextAt(This,iParam,pbstrName,pbstrText)	\
    (This)->lpVtbl -> GetParamTextAt(This,iParam,pbstrName,pbstrText)

#define IVsXMLMemberData3_GetReturnsText(This,pbstrReturns)	\
    (This)->lpVtbl -> GetReturnsText(This,pbstrReturns)

#define IVsXMLMemberData3_GetRemarksText(This,pbstrRemarks)	\
    (This)->lpVtbl -> GetRemarksText(This,pbstrRemarks)

#define IVsXMLMemberData3_GetExceptionCount(This,piExceptions)	\
    (This)->lpVtbl -> GetExceptionCount(This,piExceptions)

#define IVsXMLMemberData3_GetExceptionTextAt(This,iException,pbstrType,pbstrText)	\
    (This)->lpVtbl -> GetExceptionTextAt(This,iException,pbstrType,pbstrText)

#define IVsXMLMemberData3_GetFilterPriority(This,piFilterPriority)	\
    (This)->lpVtbl -> GetFilterPriority(This,piFilterPriority)

#define IVsXMLMemberData3_GetCompletionListText(This,pbstrCompletionList)	\
    (This)->lpVtbl -> GetCompletionListText(This,pbstrCompletionList)

#define IVsXMLMemberData3_GetCompletionListTextAt(This,iParam,pbstrCompletionList)	\
    (This)->lpVtbl -> GetCompletionListTextAt(This,iParam,pbstrCompletionList)

#define IVsXMLMemberData3_GetPermissionSet(This,pbstrPermissionSetXML)	\
    (This)->lpVtbl -> GetPermissionSet(This,pbstrPermissionSetXML)

#define IVsXMLMemberData3_GetTypeParamCount(This,piTypeParams)	\
    (This)->lpVtbl -> GetTypeParamCount(This,piTypeParams)

#define IVsXMLMemberData3_GetTypeParamTextAt(This,iTypeParam,pbstrName,pbstrText)	\
    (This)->lpVtbl -> GetTypeParamTextAt(This,iTypeParam,pbstrName,pbstrText)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsXMLMemberData3_GetSummaryText_Proxy( 
    IVsXMLMemberData3 * This,
    /* [out] */ BSTR *pbstrSummary);


void __RPC_STUB IVsXMLMemberData3_GetSummaryText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsXMLMemberData3_GetParamCount_Proxy( 
    IVsXMLMemberData3 * This,
    /* [out] */ long *piParams);


void __RPC_STUB IVsXMLMemberData3_GetParamCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsXMLMemberData3_GetParamTextAt_Proxy( 
    IVsXMLMemberData3 * This,
    /* [in] */ long iParam,
    /* [out] */ BSTR *pbstrName,
    /* [out] */ BSTR *pbstrText);


void __RPC_STUB IVsXMLMemberData3_GetParamTextAt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsXMLMemberData3_GetReturnsText_Proxy( 
    IVsXMLMemberData3 * This,
    /* [out] */ BSTR *pbstrReturns);


void __RPC_STUB IVsXMLMemberData3_GetReturnsText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsXMLMemberData3_GetRemarksText_Proxy( 
    IVsXMLMemberData3 * This,
    /* [out] */ BSTR *pbstrRemarks);


void __RPC_STUB IVsXMLMemberData3_GetRemarksText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsXMLMemberData3_GetExceptionCount_Proxy( 
    IVsXMLMemberData3 * This,
    /* [out] */ long *piExceptions);


void __RPC_STUB IVsXMLMemberData3_GetExceptionCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsXMLMemberData3_GetExceptionTextAt_Proxy( 
    IVsXMLMemberData3 * This,
    /* [in] */ long iException,
    /* [out] */ BSTR *pbstrType,
    /* [out] */ BSTR *pbstrText);


void __RPC_STUB IVsXMLMemberData3_GetExceptionTextAt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsXMLMemberData3_GetFilterPriority_Proxy( 
    IVsXMLMemberData3 * This,
    /* [out] */ long *piFilterPriority);


void __RPC_STUB IVsXMLMemberData3_GetFilterPriority_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsXMLMemberData3_GetCompletionListText_Proxy( 
    IVsXMLMemberData3 * This,
    /* [out] */ BSTR *pbstrCompletionList);


void __RPC_STUB IVsXMLMemberData3_GetCompletionListText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsXMLMemberData3_GetCompletionListTextAt_Proxy( 
    IVsXMLMemberData3 * This,
    /* [in] */ long iParam,
    /* [out] */ BSTR *pbstrCompletionList);


void __RPC_STUB IVsXMLMemberData3_GetCompletionListTextAt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsXMLMemberData3_GetPermissionSet_Proxy( 
    IVsXMLMemberData3 * This,
    /* [out] */ BSTR *pbstrPermissionSetXML);


void __RPC_STUB IVsXMLMemberData3_GetPermissionSet_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsXMLMemberData3_GetTypeParamCount_Proxy( 
    IVsXMLMemberData3 * This,
    /* [out] */ long *piTypeParams);


void __RPC_STUB IVsXMLMemberData3_GetTypeParamCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsXMLMemberData3_GetTypeParamTextAt_Proxy( 
    IVsXMLMemberData3 * This,
    /* [in] */ long iTypeParam,
    /* [out] */ BSTR *pbstrName,
    /* [out] */ BSTR *pbstrText);


void __RPC_STUB IVsXMLMemberData3_GetTypeParamTextAt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsXMLMemberData3_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshell80_0726 */
/* [local] */ 


enum _LIB_LISTTYPE2
    {	LLT_NIL	= 0,
	LLT_MEMBERHIERARCHY	= 0x20
    } ;
typedef DWORD LIB_LISTTYPE2;

typedef LIB_LISTTYPE2 LIBCAT_LISTTYPE2;

#define COUNT_LIBCAT_LISTTYPE 6

enum _LIB_FLAGS2
    {	LF_SUPPORTSWHEREUSED	= 0x10,
	LF_SUPPORTSFILTERING	= 0x20,
	LF_SUPPORTSFILTERINGWITHEXPANSION	= 0x40,
	LF_SUPPORTSCALLBROWSER	= 0x80,
	LF_SUPPORTSLISTREFERENCES	= 0x100,
	LF_SUPPORTSCUSTOMSEARCHRESULTS	= 0x200,
	LF_SUPPORTSALWAYSUPDATE	= 0x400
    } ;
typedef DWORD LIB_FLAGS2;


enum _LIB_LISTCAPABILITIES2
    {	LLC_ALLOWELEMENTSEARCH	= 0x100
    } ;
typedef DWORD LIB_LISTCAPABILITIES2;


enum _VSOBSEARCHOPTIONS2
    {	VSOBSO_INCLUDEWHEREDEFINITION	= 0x4,
	VSOBSO_INCLUDEWHEREDECLARATION	= 0x8,
	VSOBSO_INCLUDEWHERERETURNTYPE	= 0x10,
	VSOBSO_INCLUDEWHEREPARAMETERTYPE	= 0x20,
	VSOBSO_INCLUDEWHEREDERIVEDTYPE	= 0x40,
	VSOBSO_INCLUDEWHERECODEUSAGE	= 0x80,
	VSOBSO_FILTERING	= 0x100,
	VSOBSO_EXPANDCHILDREN	= 0x200,
	VSOBSO_CALLSTO	= 0x400,
	VSOBSO_CALLSFROM	= 0x800,
	VSOBSO_LISTREFERENCES	= 0x1000
    } ;
typedef DWORD VSOBSEARCHOPTIONS2;


typedef struct _VSOBSEARCHCRITERIA2
    {
    LPCOLESTR szName;
    VSOBSEARCHTYPE eSrchType;
    VSOBSEARCHOPTIONS2 grfOptions;
    DWORD dwCustom;
    IVsNavInfo *pIVsNavInfo;
    } 	VSOBSEARCHCRITERIA2;

typedef struct _VSOBNAVNAMEINFONODE2
    {
    WCHAR *pszName;
    LIB_LISTTYPE2 lltName;
    struct _VSOBNAVNAMEINFONODE2 *pNext;
    } 	VSOBNAVNAMEINFONODE2;

typedef struct _VSOBNAVIGATIONINFO3
    {
    GUID *pguidLib;
    WCHAR *pszLibName;
    VSOBNAVNAMEINFONODE2 *pName;
    DWORD dwCustom;
    } 	VSOBNAVIGATIONINFO3;


enum _LIB_CATEGORY2
    {	LC_NIL	= 0,
	LC_PHYSICALCONTAINERTYPE	= 10,
	LC_HIERARCHYTYPE	= 11,
	LC_MEMBERINHERITANCE	= 12,
	LC_Last2	= LC_MEMBERINHERITANCE
    } ;
typedef LONG LIB_CATEGORY2;

#define COUNT_LIB_CATEGORY2 12

enum _LIBCAT_CLASSTYPE2
    {	LCCT_TEMPLATE	= 0x4000,
	LCCT_GENERIC	= 0x8000,
	LCCT_ITERATOR	= 0x10000
    } ;
typedef DWORD LIBCAT_CLASSTYPE2;

#define COUNT_LIBCAT_CLASSTYPE2 17

enum _LIBCAT_MEMBERTYPE2
    {	LCMT_TEMPLATE	= 0x4000,
	LCMT_GENERIC	= 0x8000
    } ;
typedef DWORD LIBCAT_MEMBERTYPE2;

#define COUNT_LIBCAT_MEMBERTYPE2 16

enum _LIBCAT_PHYSICALCONTAINERTYPE
    {	LCPT_GLOBAL	= 0x1,
	LCPT_PROJECTREFERENCE	= 0x2,
	LCPT_PROJECT	= 0x4
    } ;
typedef DWORD LIBCAT_PHYSICALCONTAINERTYPE;

#define COUNT_LIBCAT_PHYSICALCONTAINERTYPE 3

enum _LIBCAT_HIERARCHYTYPE
    {	LCHT_UNKNOWN	= 0x1,
	LCHT_FOLDER	= 0x2,
	LCHT_BASESANDINTERFACES	= 0x4,
	LCHT_INHERITEDMEMBERS	= 0x8,
	LCHT_PROJECTREFERENCES	= 0x10,
	LCHT_DERIVEDTYPES	= 0x20
    } ;
typedef DWORD LIBCAT_HIERARCHYTYPE;

#define COUNT_LIBCAT_HIERARCHYTYPE 6

enum _LIBCAT_MEMBERINHERITANCE
    {	LCMI_IMMEDIATE	= 0x1,
	LCMI_OVERRIDABLE	= 0x2,
	LCMI_OVERRIDEREQUIRED	= 0x4,
	LCMI_OVERRIDDEN	= 0x8,
	LCMI_NOTOVERRIDABLE	= 0x10
    } ;
typedef DWORD LIBCAT_MEMBERINHERITANCE;

#define COUNT_LIBCAT_MEMBERINHERITANCE 5

enum _VSOBJLISTELEMPROPID
    {	VSOBJLISTELEMPROPID_FIRST	= 1,
	VSOBJLISTELEMPROPID_HELPKEYWORD	= 1,
	VSOBJLISTELEMPROPID_COMPONENTPATH	= 2,
	VSOBJLISTELEMPROPID_CODEDEFVIEWCONTEXT	= 3,
	VSOBJLISTELEMPROPID_SUPPORTSCALLSTO	= 4,
	VSOBJLISTELEMPROPID_SUPPORTSCALLSFROM	= 5,
	VSOBJLISTELEMPROPID_FULLNAME	= 6,
	VSOBJLISTELEMPROPID_LEAFNAME	= 7,
	VSOBJLISTELEMPROPID_NAME_FOR_RENAME	= 8,
	VSOBJLISTELEMPROPID_LAST	= 8
    } ;
typedef LONG VSOBJLISTELEMPROPID;



extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0726_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0726_v0_0_s_ifspec;

#ifndef __IVsNavInfoNode_INTERFACE_DEFINED__
#define __IVsNavInfoNode_INTERFACE_DEFINED__

/* interface IVsNavInfoNode */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsNavInfoNode;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1BD1DD01-1246-4694-9DA7-8ADCD9CA3275")
    IVsNavInfoNode : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE get_Type( 
            /* [out] */ DWORD *pllt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_Name( 
            /* [out] */ BSTR *pbstrName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsNavInfoNodeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsNavInfoNode * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsNavInfoNode * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsNavInfoNode * This);
        
        HRESULT ( STDMETHODCALLTYPE *get_Type )( 
            IVsNavInfoNode * This,
            /* [out] */ DWORD *pllt);
        
        HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IVsNavInfoNode * This,
            /* [out] */ BSTR *pbstrName);
        
        END_INTERFACE
    } IVsNavInfoNodeVtbl;

    interface IVsNavInfoNode
    {
        CONST_VTBL struct IVsNavInfoNodeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsNavInfoNode_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsNavInfoNode_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsNavInfoNode_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsNavInfoNode_get_Type(This,pllt)	\
    (This)->lpVtbl -> get_Type(This,pllt)

#define IVsNavInfoNode_get_Name(This,pbstrName)	\
    (This)->lpVtbl -> get_Name(This,pbstrName)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsNavInfoNode_get_Type_Proxy( 
    IVsNavInfoNode * This,
    /* [out] */ DWORD *pllt);


void __RPC_STUB IVsNavInfoNode_get_Type_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsNavInfoNode_get_Name_Proxy( 
    IVsNavInfoNode * This,
    /* [out] */ BSTR *pbstrName);


void __RPC_STUB IVsNavInfoNode_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsNavInfoNode_INTERFACE_DEFINED__ */


#ifndef __IVsEnumNavInfoNodes_INTERFACE_DEFINED__
#define __IVsEnumNavInfoNodes_INTERFACE_DEFINED__

/* interface IVsEnumNavInfoNodes */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsEnumNavInfoNodes;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D2042A65-5E86-4cfa-AD68-F2D6886628D7")
    IVsEnumNavInfoNodes : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ IVsNavInfoNode **rgelt,
            /* [out] */ ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IVsEnumNavInfoNodes **ppenum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsEnumNavInfoNodesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsEnumNavInfoNodes * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsEnumNavInfoNodes * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsEnumNavInfoNodes * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IVsEnumNavInfoNodes * This,
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ IVsNavInfoNode **rgelt,
            /* [out] */ ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IVsEnumNavInfoNodes * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IVsEnumNavInfoNodes * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IVsEnumNavInfoNodes * This,
            /* [out] */ IVsEnumNavInfoNodes **ppenum);
        
        END_INTERFACE
    } IVsEnumNavInfoNodesVtbl;

    interface IVsEnumNavInfoNodes
    {
        CONST_VTBL struct IVsEnumNavInfoNodesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsEnumNavInfoNodes_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsEnumNavInfoNodes_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsEnumNavInfoNodes_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsEnumNavInfoNodes_Next(This,celt,rgelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched)

#define IVsEnumNavInfoNodes_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IVsEnumNavInfoNodes_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IVsEnumNavInfoNodes_Clone(This,ppenum)	\
    (This)->lpVtbl -> Clone(This,ppenum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsEnumNavInfoNodes_Next_Proxy( 
    IVsEnumNavInfoNodes * This,
    /* [in] */ ULONG celt,
    /* [length_is][size_is][out] */ IVsNavInfoNode **rgelt,
    /* [out] */ ULONG *pceltFetched);


void __RPC_STUB IVsEnumNavInfoNodes_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsEnumNavInfoNodes_Skip_Proxy( 
    IVsEnumNavInfoNodes * This,
    /* [in] */ ULONG celt);


void __RPC_STUB IVsEnumNavInfoNodes_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsEnumNavInfoNodes_Reset_Proxy( 
    IVsEnumNavInfoNodes * This);


void __RPC_STUB IVsEnumNavInfoNodes_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsEnumNavInfoNodes_Clone_Proxy( 
    IVsEnumNavInfoNodes * This,
    /* [out] */ IVsEnumNavInfoNodes **ppenum);


void __RPC_STUB IVsEnumNavInfoNodes_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsEnumNavInfoNodes_INTERFACE_DEFINED__ */


#ifndef __IVsNavInfo_INTERFACE_DEFINED__
#define __IVsNavInfo_INTERFACE_DEFINED__

/* interface IVsNavInfo */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsNavInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("61772DB8-2D5B-49cb-9CE8-891459921F7F")
    IVsNavInfo : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetLibGuid( 
            /* [out] */ GUID *pGuid) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSymbolType( 
            /* [out] */ DWORD *pdwType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumPresentationNodes( 
            /* [in] */ DWORD dwFlags,
            /* [out] */ IVsEnumNavInfoNodes **ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumCanonicalNodes( 
            /* [out] */ IVsEnumNavInfoNodes **ppEnum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsNavInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsNavInfo * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsNavInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsNavInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetLibGuid )( 
            IVsNavInfo * This,
            /* [out] */ GUID *pGuid);
        
        HRESULT ( STDMETHODCALLTYPE *GetSymbolType )( 
            IVsNavInfo * This,
            /* [out] */ DWORD *pdwType);
        
        HRESULT ( STDMETHODCALLTYPE *EnumPresentationNodes )( 
            IVsNavInfo * This,
            /* [in] */ DWORD dwFlags,
            /* [out] */ IVsEnumNavInfoNodes **ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE *EnumCanonicalNodes )( 
            IVsNavInfo * This,
            /* [out] */ IVsEnumNavInfoNodes **ppEnum);
        
        END_INTERFACE
    } IVsNavInfoVtbl;

    interface IVsNavInfo
    {
        CONST_VTBL struct IVsNavInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsNavInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsNavInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsNavInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsNavInfo_GetLibGuid(This,pGuid)	\
    (This)->lpVtbl -> GetLibGuid(This,pGuid)

#define IVsNavInfo_GetSymbolType(This,pdwType)	\
    (This)->lpVtbl -> GetSymbolType(This,pdwType)

#define IVsNavInfo_EnumPresentationNodes(This,dwFlags,ppEnum)	\
    (This)->lpVtbl -> EnumPresentationNodes(This,dwFlags,ppEnum)

#define IVsNavInfo_EnumCanonicalNodes(This,ppEnum)	\
    (This)->lpVtbl -> EnumCanonicalNodes(This,ppEnum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsNavInfo_GetLibGuid_Proxy( 
    IVsNavInfo * This,
    /* [out] */ GUID *pGuid);


void __RPC_STUB IVsNavInfo_GetLibGuid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsNavInfo_GetSymbolType_Proxy( 
    IVsNavInfo * This,
    /* [out] */ DWORD *pdwType);


void __RPC_STUB IVsNavInfo_GetSymbolType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsNavInfo_EnumPresentationNodes_Proxy( 
    IVsNavInfo * This,
    /* [in] */ DWORD dwFlags,
    /* [out] */ IVsEnumNavInfoNodes **ppEnum);


void __RPC_STUB IVsNavInfo_EnumPresentationNodes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsNavInfo_EnumCanonicalNodes_Proxy( 
    IVsNavInfo * This,
    /* [out] */ IVsEnumNavInfoNodes **ppEnum);


void __RPC_STUB IVsNavInfo_EnumCanonicalNodes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsNavInfo_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshell80_0729 */
/* [local] */ 

typedef struct tagSymbolDescriptionNode
    {
    DWORD dwType;
    LPCOLESTR pszName;
    } 	SYMBOL_DESCRIPTION_NODE;



extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0729_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0729_v0_0_s_ifspec;

#ifndef __IVsObjectBrowserDescription3_INTERFACE_DEFINED__
#define __IVsObjectBrowserDescription3_INTERFACE_DEFINED__

/* interface IVsObjectBrowserDescription3 */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsObjectBrowserDescription3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2BCD7A6A-D251-4286-9A61-BDEDDE91114F")
    IVsObjectBrowserDescription3 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AddDescriptionText3( 
            /* [in] */ LPCWSTR pText,
            /* [in] */ VSOBDESCRIPTIONSECTION obdSect,
            /* [in] */ IVsNavInfo *pHyperJump) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ClearDescriptionText( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsObjectBrowserDescription3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsObjectBrowserDescription3 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsObjectBrowserDescription3 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsObjectBrowserDescription3 * This);
        
        HRESULT ( STDMETHODCALLTYPE *AddDescriptionText3 )( 
            IVsObjectBrowserDescription3 * This,
            /* [in] */ LPCWSTR pText,
            /* [in] */ VSOBDESCRIPTIONSECTION obdSect,
            /* [in] */ IVsNavInfo *pHyperJump);
        
        HRESULT ( STDMETHODCALLTYPE *ClearDescriptionText )( 
            IVsObjectBrowserDescription3 * This);
        
        END_INTERFACE
    } IVsObjectBrowserDescription3Vtbl;

    interface IVsObjectBrowserDescription3
    {
        CONST_VTBL struct IVsObjectBrowserDescription3Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsObjectBrowserDescription3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsObjectBrowserDescription3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsObjectBrowserDescription3_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsObjectBrowserDescription3_AddDescriptionText3(This,pText,obdSect,pHyperJump)	\
    (This)->lpVtbl -> AddDescriptionText3(This,pText,obdSect,pHyperJump)

#define IVsObjectBrowserDescription3_ClearDescriptionText(This)	\
    (This)->lpVtbl -> ClearDescriptionText(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsObjectBrowserDescription3_AddDescriptionText3_Proxy( 
    IVsObjectBrowserDescription3 * This,
    /* [in] */ LPCWSTR pText,
    /* [in] */ VSOBDESCRIPTIONSECTION obdSect,
    /* [in] */ IVsNavInfo *pHyperJump);


void __RPC_STUB IVsObjectBrowserDescription3_AddDescriptionText3_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsObjectBrowserDescription3_ClearDescriptionText_Proxy( 
    IVsObjectBrowserDescription3 * This);


void __RPC_STUB IVsObjectBrowserDescription3_ClearDescriptionText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsObjectBrowserDescription3_INTERFACE_DEFINED__ */


#ifndef __IVsObjectList2_INTERFACE_DEFINED__
#define __IVsObjectList2_INTERFACE_DEFINED__

/* interface IVsObjectList2 */
/* [object][local][version][uuid] */ 


EXTERN_C const IID IID_IVsObjectList2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E37F46C4-C627-4d88-A091-2992EE33B51D")
    IVsObjectList2 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetFlags( 
            /* [out] */ VSTREEFLAGS *pFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetItemCount( 
            /* [out] */ ULONG *pCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetExpandedList( 
            /* [in] */ ULONG Index,
            /* [out] */ BOOL *pfCanRecurse,
            /* [out] */ IVsLiteTreeList **pptlNode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LocateExpandedList( 
            /* [in] */ IVsLiteTreeList *ExpandedList,
            /* [out] */ ULONG *iIndex) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnClose( 
            /* [out] */ VSTREECLOSEACTIONS *ptca) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetText( 
            /* [in] */ ULONG Index,
            /* [in] */ VSTREETEXTOPTIONS tto,
            /* [out] */ const WCHAR **ppszText) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTipText( 
            /* [in] */ ULONG Index,
            /* [in] */ VSTREETOOLTIPTYPE eTipType,
            /* [out] */ const WCHAR **ppszText) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetExpandable( 
            /* [in] */ ULONG Index,
            /* [out] */ BOOL *pfExpandable) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetDisplayData( 
            /* [in] */ ULONG Index,
            /* [out] */ VSTREEDISPLAYDATA *pData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UpdateCounter( 
            /* [out] */ ULONG *pCurUpdate,
            /* [out] */ VSTREEITEMCHANGESMASK *pgrfChanges) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetListChanges( 
            /* [out][in] */ ULONG *pcChanges,
            /* [size_is][in] */ VSTREELISTITEMCHANGE *prgListChanges) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ToggleState( 
            /* [in] */ ULONG Index,
            /* [out] */ VSTREESTATECHANGEREFRESH *ptscr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCapabilities2( 
            /* [out] */ LIB_LISTCAPABILITIES2 *pgrfCapabilities) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetList2( 
            /* [in] */ ULONG Index,
            /* [in] */ LIB_LISTTYPE2 ListType,
            /* [in] */ LIB_LISTFLAGS Flags,
            /* [in] */ VSOBSEARCHCRITERIA2 *pobSrch,
            /* [retval][out] */ IVsObjectList2 **ppIVsObjectList2) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCategoryField2( 
            /* [in] */ ULONG Index,
            /* [in] */ LIB_CATEGORY2 Category,
            /* [retval][out] */ DWORD *pfCatField) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetExpandable3( 
            /* [in] */ ULONG Index,
            /* [in] */ LIB_LISTTYPE2 ListTypeExcluded,
            /* [out] */ BOOL *pfExpandable) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNavigationInfo2( 
            /* [in] */ ULONG Index,
            /* [out][in] */ VSOBNAVIGATIONINFO3 *pobNav) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LocateNavigationInfo2( 
            /* [in] */ VSOBNAVIGATIONINFO3 *pobNav,
            /* [in] */ VSOBNAVNAMEINFONODE2 *pobName,
            /* [in] */ BOOL fDontUpdate,
            /* [out] */ BOOL *pfMatchedName,
            /* [out] */ ULONG *pIndex) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBrowseObject( 
            /* [in] */ ULONG Index,
            /* [out] */ IDispatch **ppdispBrowseObj) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUserContext( 
            /* [in] */ ULONG Index,
            /* [out] */ IUnknown **ppunkUserCtx) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ShowHelp( 
            /* [in] */ ULONG Index) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSourceContext( 
            /* [in] */ ULONG Index,
            /* [out] */ const WCHAR **pszFileName,
            /* [out] */ ULONG *pulLineNum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CountSourceItems( 
            /* [in] */ ULONG Index,
            /* [out] */ IVsHierarchy **ppHier,
            /* [out] */ VSITEMID *pitemid,
            /* [retval][out] */ ULONG *pcItems) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMultipleSourceItems( 
            /* [in] */ ULONG Index,
            /* [in] */ VSGSIFLAGS grfGSI,
            /* [in] */ ULONG cItems,
            /* [size_is][out] */ VSITEMSELECTION rgItemSel[  ]) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CanGoToSource( 
            /* [in] */ ULONG Index,
            /* [in] */ VSOBJGOTOSRCTYPE SrcType,
            /* [out] */ BOOL *pfOK) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GoToSource( 
            /* [in] */ ULONG Index,
            /* [in] */ VSOBJGOTOSRCTYPE SrcType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetContextMenu( 
            /* [in] */ ULONG Index,
            /* [out] */ CLSID *pclsidActive,
            /* [out] */ LONG *pnMenuId,
            /* [out] */ IOleCommandTarget **ppCmdTrgtActive) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryDragDrop( 
            /* [in] */ ULONG Index,
            /* [in] */ IDataObject *pDataObject,
            /* [in] */ DWORD grfKeyState,
            /* [out][in] */ DWORD *pdwEffect) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DoDragDrop( 
            /* [in] */ ULONG Index,
            /* [in] */ IDataObject *pDataObject,
            /* [in] */ DWORD grfKeyState,
            /* [out][in] */ DWORD *pdwEffect) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CanRename( 
            /* [in] */ ULONG Index,
            /* [in] */ LPCOLESTR pszNewName,
            /* [out] */ BOOL *pfOK) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DoRename( 
            /* [in] */ ULONG Index,
            /* [in] */ LPCOLESTR pszNewName,
            /* [in] */ VSOBJOPFLAGS grfFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CanDelete( 
            /* [in] */ ULONG Index,
            /* [out] */ BOOL *pfOK) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DoDelete( 
            /* [in] */ ULONG Index,
            /* [in] */ VSOBJOPFLAGS grfFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FillDescription( 
            /* [in] */ ULONG Index,
            /* [in] */ VSOBJDESCOPTIONS grfOptions,
            /* [in] */ IVsObjectBrowserDescription2 *pobDesc) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FillDescription2( 
            /* [in] */ ULONG Index,
            /* [in] */ VSOBJDESCOPTIONS grfOptions,
            /* [in] */ IVsObjectBrowserDescription3 *pobDesc) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumClipboardFormats( 
            /* [in] */ ULONG Index,
            /* [in] */ VSOBJCFFLAGS grfFlags,
            /* [in] */ ULONG celt,
            /* [size_is][out][in] */ VSOBJCLIPFORMAT rgcfFormats[  ],
            /* [optional][out] */ ULONG *pcActual) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetClipboardFormat( 
            /* [in] */ ULONG Index,
            /* [in] */ VSOBJCFFLAGS grfFlags,
            /* [in] */ FORMATETC *pFormatetc,
            /* [in] */ STGMEDIUM *pMedium) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetExtendedClipboardVariant( 
            /* [in] */ ULONG Index,
            /* [in] */ VSOBJCFFLAGS grfFlags,
            /* [in] */ const VSOBJCLIPFORMAT *pcfFormat,
            /* [out] */ VARIANT *pvarFormat) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetProperty( 
            /* [in] */ ULONG Index,
            /* [in] */ VSOBJLISTELEMPROPID propid,
            /* [out] */ VARIANT *pvar) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNavInfo( 
            /* [in] */ ULONG Index,
            /* [out] */ IVsNavInfo **ppNavInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNavInfoNode( 
            /* [in] */ ULONG Index,
            /* [out] */ IVsNavInfoNode **ppNavInfoNode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LocateNavInfoNode( 
            /* [in] */ IVsNavInfoNode *pNavInfoNode,
            /* [out] */ ULONG *pulIndex) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsObjectList2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsObjectList2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsObjectList2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsObjectList2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetFlags )( 
            IVsObjectList2 * This,
            /* [out] */ VSTREEFLAGS *pFlags);
        
        HRESULT ( STDMETHODCALLTYPE *GetItemCount )( 
            IVsObjectList2 * This,
            /* [out] */ ULONG *pCount);
        
        HRESULT ( STDMETHODCALLTYPE *GetExpandedList )( 
            IVsObjectList2 * This,
            /* [in] */ ULONG Index,
            /* [out] */ BOOL *pfCanRecurse,
            /* [out] */ IVsLiteTreeList **pptlNode);
        
        HRESULT ( STDMETHODCALLTYPE *LocateExpandedList )( 
            IVsObjectList2 * This,
            /* [in] */ IVsLiteTreeList *ExpandedList,
            /* [out] */ ULONG *iIndex);
        
        HRESULT ( STDMETHODCALLTYPE *OnClose )( 
            IVsObjectList2 * This,
            /* [out] */ VSTREECLOSEACTIONS *ptca);
        
        HRESULT ( STDMETHODCALLTYPE *GetText )( 
            IVsObjectList2 * This,
            /* [in] */ ULONG Index,
            /* [in] */ VSTREETEXTOPTIONS tto,
            /* [out] */ const WCHAR **ppszText);
        
        HRESULT ( STDMETHODCALLTYPE *GetTipText )( 
            IVsObjectList2 * This,
            /* [in] */ ULONG Index,
            /* [in] */ VSTREETOOLTIPTYPE eTipType,
            /* [out] */ const WCHAR **ppszText);
        
        HRESULT ( STDMETHODCALLTYPE *GetExpandable )( 
            IVsObjectList2 * This,
            /* [in] */ ULONG Index,
            /* [out] */ BOOL *pfExpandable);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *GetDisplayData )( 
            IVsObjectList2 * This,
            /* [in] */ ULONG Index,
            /* [out] */ VSTREEDISPLAYDATA *pData);
        
        HRESULT ( STDMETHODCALLTYPE *UpdateCounter )( 
            IVsObjectList2 * This,
            /* [out] */ ULONG *pCurUpdate,
            /* [out] */ VSTREEITEMCHANGESMASK *pgrfChanges);
        
        HRESULT ( STDMETHODCALLTYPE *GetListChanges )( 
            IVsObjectList2 * This,
            /* [out][in] */ ULONG *pcChanges,
            /* [size_is][in] */ VSTREELISTITEMCHANGE *prgListChanges);
        
        HRESULT ( STDMETHODCALLTYPE *ToggleState )( 
            IVsObjectList2 * This,
            /* [in] */ ULONG Index,
            /* [out] */ VSTREESTATECHANGEREFRESH *ptscr);
        
        HRESULT ( STDMETHODCALLTYPE *GetCapabilities2 )( 
            IVsObjectList2 * This,
            /* [out] */ LIB_LISTCAPABILITIES2 *pgrfCapabilities);
        
        HRESULT ( STDMETHODCALLTYPE *GetList2 )( 
            IVsObjectList2 * This,
            /* [in] */ ULONG Index,
            /* [in] */ LIB_LISTTYPE2 ListType,
            /* [in] */ LIB_LISTFLAGS Flags,
            /* [in] */ VSOBSEARCHCRITERIA2 *pobSrch,
            /* [retval][out] */ IVsObjectList2 **ppIVsObjectList2);
        
        HRESULT ( STDMETHODCALLTYPE *GetCategoryField2 )( 
            IVsObjectList2 * This,
            /* [in] */ ULONG Index,
            /* [in] */ LIB_CATEGORY2 Category,
            /* [retval][out] */ DWORD *pfCatField);
        
        HRESULT ( STDMETHODCALLTYPE *GetExpandable3 )( 
            IVsObjectList2 * This,
            /* [in] */ ULONG Index,
            /* [in] */ LIB_LISTTYPE2 ListTypeExcluded,
            /* [out] */ BOOL *pfExpandable);
        
        HRESULT ( STDMETHODCALLTYPE *GetNavigationInfo2 )( 
            IVsObjectList2 * This,
            /* [in] */ ULONG Index,
            /* [out][in] */ VSOBNAVIGATIONINFO3 *pobNav);
        
        HRESULT ( STDMETHODCALLTYPE *LocateNavigationInfo2 )( 
            IVsObjectList2 * This,
            /* [in] */ VSOBNAVIGATIONINFO3 *pobNav,
            /* [in] */ VSOBNAVNAMEINFONODE2 *pobName,
            /* [in] */ BOOL fDontUpdate,
            /* [out] */ BOOL *pfMatchedName,
            /* [out] */ ULONG *pIndex);
        
        HRESULT ( STDMETHODCALLTYPE *GetBrowseObject )( 
            IVsObjectList2 * This,
            /* [in] */ ULONG Index,
            /* [out] */ IDispatch **ppdispBrowseObj);
        
        HRESULT ( STDMETHODCALLTYPE *GetUserContext )( 
            IVsObjectList2 * This,
            /* [in] */ ULONG Index,
            /* [out] */ IUnknown **ppunkUserCtx);
        
        HRESULT ( STDMETHODCALLTYPE *ShowHelp )( 
            IVsObjectList2 * This,
            /* [in] */ ULONG Index);
        
        HRESULT ( STDMETHODCALLTYPE *GetSourceContext )( 
            IVsObjectList2 * This,
            /* [in] */ ULONG Index,
            /* [out] */ const WCHAR **pszFileName,
            /* [out] */ ULONG *pulLineNum);
        
        HRESULT ( STDMETHODCALLTYPE *CountSourceItems )( 
            IVsObjectList2 * This,
            /* [in] */ ULONG Index,
            /* [out] */ IVsHierarchy **ppHier,
            /* [out] */ VSITEMID *pitemid,
            /* [retval][out] */ ULONG *pcItems);
        
        HRESULT ( STDMETHODCALLTYPE *GetMultipleSourceItems )( 
            IVsObjectList2 * This,
            /* [in] */ ULONG Index,
            /* [in] */ VSGSIFLAGS grfGSI,
            /* [in] */ ULONG cItems,
            /* [size_is][out] */ VSITEMSELECTION rgItemSel[  ]);
        
        HRESULT ( STDMETHODCALLTYPE *CanGoToSource )( 
            IVsObjectList2 * This,
            /* [in] */ ULONG Index,
            /* [in] */ VSOBJGOTOSRCTYPE SrcType,
            /* [out] */ BOOL *pfOK);
        
        HRESULT ( STDMETHODCALLTYPE *GoToSource )( 
            IVsObjectList2 * This,
            /* [in] */ ULONG Index,
            /* [in] */ VSOBJGOTOSRCTYPE SrcType);
        
        HRESULT ( STDMETHODCALLTYPE *GetContextMenu )( 
            IVsObjectList2 * This,
            /* [in] */ ULONG Index,
            /* [out] */ CLSID *pclsidActive,
            /* [out] */ LONG *pnMenuId,
            /* [out] */ IOleCommandTarget **ppCmdTrgtActive);
        
        HRESULT ( STDMETHODCALLTYPE *QueryDragDrop )( 
            IVsObjectList2 * This,
            /* [in] */ ULONG Index,
            /* [in] */ IDataObject *pDataObject,
            /* [in] */ DWORD grfKeyState,
            /* [out][in] */ DWORD *pdwEffect);
        
        HRESULT ( STDMETHODCALLTYPE *DoDragDrop )( 
            IVsObjectList2 * This,
            /* [in] */ ULONG Index,
            /* [in] */ IDataObject *pDataObject,
            /* [in] */ DWORD grfKeyState,
            /* [out][in] */ DWORD *pdwEffect);
        
        HRESULT ( STDMETHODCALLTYPE *CanRename )( 
            IVsObjectList2 * This,
            /* [in] */ ULONG Index,
            /* [in] */ LPCOLESTR pszNewName,
            /* [out] */ BOOL *pfOK);
        
        HRESULT ( STDMETHODCALLTYPE *DoRename )( 
            IVsObjectList2 * This,
            /* [in] */ ULONG Index,
            /* [in] */ LPCOLESTR pszNewName,
            /* [in] */ VSOBJOPFLAGS grfFlags);
        
        HRESULT ( STDMETHODCALLTYPE *CanDelete )( 
            IVsObjectList2 * This,
            /* [in] */ ULONG Index,
            /* [out] */ BOOL *pfOK);
        
        HRESULT ( STDMETHODCALLTYPE *DoDelete )( 
            IVsObjectList2 * This,
            /* [in] */ ULONG Index,
            /* [in] */ VSOBJOPFLAGS grfFlags);
        
        HRESULT ( STDMETHODCALLTYPE *FillDescription )( 
            IVsObjectList2 * This,
            /* [in] */ ULONG Index,
            /* [in] */ VSOBJDESCOPTIONS grfOptions,
            /* [in] */ IVsObjectBrowserDescription2 *pobDesc);
        
        HRESULT ( STDMETHODCALLTYPE *FillDescription2 )( 
            IVsObjectList2 * This,
            /* [in] */ ULONG Index,
            /* [in] */ VSOBJDESCOPTIONS grfOptions,
            /* [in] */ IVsObjectBrowserDescription3 *pobDesc);
        
        HRESULT ( STDMETHODCALLTYPE *EnumClipboardFormats )( 
            IVsObjectList2 * This,
            /* [in] */ ULONG Index,
            /* [in] */ VSOBJCFFLAGS grfFlags,
            /* [in] */ ULONG celt,
            /* [size_is][out][in] */ VSOBJCLIPFORMAT rgcfFormats[  ],
            /* [optional][out] */ ULONG *pcActual);
        
        HRESULT ( STDMETHODCALLTYPE *GetClipboardFormat )( 
            IVsObjectList2 * This,
            /* [in] */ ULONG Index,
            /* [in] */ VSOBJCFFLAGS grfFlags,
            /* [in] */ FORMATETC *pFormatetc,
            /* [in] */ STGMEDIUM *pMedium);
        
        HRESULT ( STDMETHODCALLTYPE *GetExtendedClipboardVariant )( 
            IVsObjectList2 * This,
            /* [in] */ ULONG Index,
            /* [in] */ VSOBJCFFLAGS grfFlags,
            /* [in] */ const VSOBJCLIPFORMAT *pcfFormat,
            /* [out] */ VARIANT *pvarFormat);
        
        HRESULT ( STDMETHODCALLTYPE *GetProperty )( 
            IVsObjectList2 * This,
            /* [in] */ ULONG Index,
            /* [in] */ VSOBJLISTELEMPROPID propid,
            /* [out] */ VARIANT *pvar);
        
        HRESULT ( STDMETHODCALLTYPE *GetNavInfo )( 
            IVsObjectList2 * This,
            /* [in] */ ULONG Index,
            /* [out] */ IVsNavInfo **ppNavInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetNavInfoNode )( 
            IVsObjectList2 * This,
            /* [in] */ ULONG Index,
            /* [out] */ IVsNavInfoNode **ppNavInfoNode);
        
        HRESULT ( STDMETHODCALLTYPE *LocateNavInfoNode )( 
            IVsObjectList2 * This,
            /* [in] */ IVsNavInfoNode *pNavInfoNode,
            /* [out] */ ULONG *pulIndex);
        
        END_INTERFACE
    } IVsObjectList2Vtbl;

    interface IVsObjectList2
    {
        CONST_VTBL struct IVsObjectList2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsObjectList2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsObjectList2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsObjectList2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsObjectList2_GetFlags(This,pFlags)	\
    (This)->lpVtbl -> GetFlags(This,pFlags)

#define IVsObjectList2_GetItemCount(This,pCount)	\
    (This)->lpVtbl -> GetItemCount(This,pCount)

#define IVsObjectList2_GetExpandedList(This,Index,pfCanRecurse,pptlNode)	\
    (This)->lpVtbl -> GetExpandedList(This,Index,pfCanRecurse,pptlNode)

#define IVsObjectList2_LocateExpandedList(This,ExpandedList,iIndex)	\
    (This)->lpVtbl -> LocateExpandedList(This,ExpandedList,iIndex)

#define IVsObjectList2_OnClose(This,ptca)	\
    (This)->lpVtbl -> OnClose(This,ptca)

#define IVsObjectList2_GetText(This,Index,tto,ppszText)	\
    (This)->lpVtbl -> GetText(This,Index,tto,ppszText)

#define IVsObjectList2_GetTipText(This,Index,eTipType,ppszText)	\
    (This)->lpVtbl -> GetTipText(This,Index,eTipType,ppszText)

#define IVsObjectList2_GetExpandable(This,Index,pfExpandable)	\
    (This)->lpVtbl -> GetExpandable(This,Index,pfExpandable)

#define IVsObjectList2_GetDisplayData(This,Index,pData)	\
    (This)->lpVtbl -> GetDisplayData(This,Index,pData)

#define IVsObjectList2_UpdateCounter(This,pCurUpdate,pgrfChanges)	\
    (This)->lpVtbl -> UpdateCounter(This,pCurUpdate,pgrfChanges)

#define IVsObjectList2_GetListChanges(This,pcChanges,prgListChanges)	\
    (This)->lpVtbl -> GetListChanges(This,pcChanges,prgListChanges)

#define IVsObjectList2_ToggleState(This,Index,ptscr)	\
    (This)->lpVtbl -> ToggleState(This,Index,ptscr)

#define IVsObjectList2_GetCapabilities2(This,pgrfCapabilities)	\
    (This)->lpVtbl -> GetCapabilities2(This,pgrfCapabilities)

#define IVsObjectList2_GetList2(This,Index,ListType,Flags,pobSrch,ppIVsObjectList2)	\
    (This)->lpVtbl -> GetList2(This,Index,ListType,Flags,pobSrch,ppIVsObjectList2)

#define IVsObjectList2_GetCategoryField2(This,Index,Category,pfCatField)	\
    (This)->lpVtbl -> GetCategoryField2(This,Index,Category,pfCatField)

#define IVsObjectList2_GetExpandable3(This,Index,ListTypeExcluded,pfExpandable)	\
    (This)->lpVtbl -> GetExpandable3(This,Index,ListTypeExcluded,pfExpandable)

#define IVsObjectList2_GetNavigationInfo2(This,Index,pobNav)	\
    (This)->lpVtbl -> GetNavigationInfo2(This,Index,pobNav)

#define IVsObjectList2_LocateNavigationInfo2(This,pobNav,pobName,fDontUpdate,pfMatchedName,pIndex)	\
    (This)->lpVtbl -> LocateNavigationInfo2(This,pobNav,pobName,fDontUpdate,pfMatchedName,pIndex)

#define IVsObjectList2_GetBrowseObject(This,Index,ppdispBrowseObj)	\
    (This)->lpVtbl -> GetBrowseObject(This,Index,ppdispBrowseObj)

#define IVsObjectList2_GetUserContext(This,Index,ppunkUserCtx)	\
    (This)->lpVtbl -> GetUserContext(This,Index,ppunkUserCtx)

#define IVsObjectList2_ShowHelp(This,Index)	\
    (This)->lpVtbl -> ShowHelp(This,Index)

#define IVsObjectList2_GetSourceContext(This,Index,pszFileName,pulLineNum)	\
    (This)->lpVtbl -> GetSourceContext(This,Index,pszFileName,pulLineNum)

#define IVsObjectList2_CountSourceItems(This,Index,ppHier,pitemid,pcItems)	\
    (This)->lpVtbl -> CountSourceItems(This,Index,ppHier,pitemid,pcItems)

#define IVsObjectList2_GetMultipleSourceItems(This,Index,grfGSI,cItems,rgItemSel)	\
    (This)->lpVtbl -> GetMultipleSourceItems(This,Index,grfGSI,cItems,rgItemSel)

#define IVsObjectList2_CanGoToSource(This,Index,SrcType,pfOK)	\
    (This)->lpVtbl -> CanGoToSource(This,Index,SrcType,pfOK)

#define IVsObjectList2_GoToSource(This,Index,SrcType)	\
    (This)->lpVtbl -> GoToSource(This,Index,SrcType)

#define IVsObjectList2_GetContextMenu(This,Index,pclsidActive,pnMenuId,ppCmdTrgtActive)	\
    (This)->lpVtbl -> GetContextMenu(This,Index,pclsidActive,pnMenuId,ppCmdTrgtActive)

#define IVsObjectList2_QueryDragDrop(This,Index,pDataObject,grfKeyState,pdwEffect)	\
    (This)->lpVtbl -> QueryDragDrop(This,Index,pDataObject,grfKeyState,pdwEffect)

#define IVsObjectList2_DoDragDrop(This,Index,pDataObject,grfKeyState,pdwEffect)	\
    (This)->lpVtbl -> DoDragDrop(This,Index,pDataObject,grfKeyState,pdwEffect)

#define IVsObjectList2_CanRename(This,Index,pszNewName,pfOK)	\
    (This)->lpVtbl -> CanRename(This,Index,pszNewName,pfOK)

#define IVsObjectList2_DoRename(This,Index,pszNewName,grfFlags)	\
    (This)->lpVtbl -> DoRename(This,Index,pszNewName,grfFlags)

#define IVsObjectList2_CanDelete(This,Index,pfOK)	\
    (This)->lpVtbl -> CanDelete(This,Index,pfOK)

#define IVsObjectList2_DoDelete(This,Index,grfFlags)	\
    (This)->lpVtbl -> DoDelete(This,Index,grfFlags)

#define IVsObjectList2_FillDescription(This,Index,grfOptions,pobDesc)	\
    (This)->lpVtbl -> FillDescription(This,Index,grfOptions,pobDesc)

#define IVsObjectList2_FillDescription2(This,Index,grfOptions,pobDesc)	\
    (This)->lpVtbl -> FillDescription2(This,Index,grfOptions,pobDesc)

#define IVsObjectList2_EnumClipboardFormats(This,Index,grfFlags,celt,rgcfFormats,pcActual)	\
    (This)->lpVtbl -> EnumClipboardFormats(This,Index,grfFlags,celt,rgcfFormats,pcActual)

#define IVsObjectList2_GetClipboardFormat(This,Index,grfFlags,pFormatetc,pMedium)	\
    (This)->lpVtbl -> GetClipboardFormat(This,Index,grfFlags,pFormatetc,pMedium)

#define IVsObjectList2_GetExtendedClipboardVariant(This,Index,grfFlags,pcfFormat,pvarFormat)	\
    (This)->lpVtbl -> GetExtendedClipboardVariant(This,Index,grfFlags,pcfFormat,pvarFormat)

#define IVsObjectList2_GetProperty(This,Index,propid,pvar)	\
    (This)->lpVtbl -> GetProperty(This,Index,propid,pvar)

#define IVsObjectList2_GetNavInfo(This,Index,ppNavInfo)	\
    (This)->lpVtbl -> GetNavInfo(This,Index,ppNavInfo)

#define IVsObjectList2_GetNavInfoNode(This,Index,ppNavInfoNode)	\
    (This)->lpVtbl -> GetNavInfoNode(This,Index,ppNavInfoNode)

#define IVsObjectList2_LocateNavInfoNode(This,pNavInfoNode,pulIndex)	\
    (This)->lpVtbl -> LocateNavInfoNode(This,pNavInfoNode,pulIndex)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsObjectList2_GetFlags_Proxy( 
    IVsObjectList2 * This,
    /* [out] */ VSTREEFLAGS *pFlags);


void __RPC_STUB IVsObjectList2_GetFlags_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsObjectList2_GetItemCount_Proxy( 
    IVsObjectList2 * This,
    /* [out] */ ULONG *pCount);


void __RPC_STUB IVsObjectList2_GetItemCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsObjectList2_GetExpandedList_Proxy( 
    IVsObjectList2 * This,
    /* [in] */ ULONG Index,
    /* [out] */ BOOL *pfCanRecurse,
    /* [out] */ IVsLiteTreeList **pptlNode);


void __RPC_STUB IVsObjectList2_GetExpandedList_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsObjectList2_LocateExpandedList_Proxy( 
    IVsObjectList2 * This,
    /* [in] */ IVsLiteTreeList *ExpandedList,
    /* [out] */ ULONG *iIndex);


void __RPC_STUB IVsObjectList2_LocateExpandedList_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsObjectList2_OnClose_Proxy( 
    IVsObjectList2 * This,
    /* [out] */ VSTREECLOSEACTIONS *ptca);


void __RPC_STUB IVsObjectList2_OnClose_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsObjectList2_GetText_Proxy( 
    IVsObjectList2 * This,
    /* [in] */ ULONG Index,
    /* [in] */ VSTREETEXTOPTIONS tto,
    /* [out] */ const WCHAR **ppszText);


void __RPC_STUB IVsObjectList2_GetText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsObjectList2_GetTipText_Proxy( 
    IVsObjectList2 * This,
    /* [in] */ ULONG Index,
    /* [in] */ VSTREETOOLTIPTYPE eTipType,
    /* [out] */ const WCHAR **ppszText);


void __RPC_STUB IVsObjectList2_GetTipText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsObjectList2_GetExpandable_Proxy( 
    IVsObjectList2 * This,
    /* [in] */ ULONG Index,
    /* [out] */ BOOL *pfExpandable);


void __RPC_STUB IVsObjectList2_GetExpandable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [local] */ HRESULT STDMETHODCALLTYPE IVsObjectList2_GetDisplayData_Proxy( 
    IVsObjectList2 * This,
    /* [in] */ ULONG Index,
    /* [out] */ VSTREEDISPLAYDATA *pData);


void __RPC_STUB IVsObjectList2_GetDisplayData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsObjectList2_UpdateCounter_Proxy( 
    IVsObjectList2 * This,
    /* [out] */ ULONG *pCurUpdate,
    /* [out] */ VSTREEITEMCHANGESMASK *pgrfChanges);


void __RPC_STUB IVsObjectList2_UpdateCounter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsObjectList2_GetListChanges_Proxy( 
    IVsObjectList2 * This,
    /* [out][in] */ ULONG *pcChanges,
    /* [size_is][in] */ VSTREELISTITEMCHANGE *prgListChanges);


void __RPC_STUB IVsObjectList2_GetListChanges_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsObjectList2_ToggleState_Proxy( 
    IVsObjectList2 * This,
    /* [in] */ ULONG Index,
    /* [out] */ VSTREESTATECHANGEREFRESH *ptscr);


void __RPC_STUB IVsObjectList2_ToggleState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsObjectList2_GetCapabilities2_Proxy( 
    IVsObjectList2 * This,
    /* [out] */ LIB_LISTCAPABILITIES2 *pgrfCapabilities);


void __RPC_STUB IVsObjectList2_GetCapabilities2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsObjectList2_GetList2_Proxy( 
    IVsObjectList2 * This,
    /* [in] */ ULONG Index,
    /* [in] */ LIB_LISTTYPE2 ListType,
    /* [in] */ LIB_LISTFLAGS Flags,
    /* [in] */ VSOBSEARCHCRITERIA2 *pobSrch,
    /* [retval][out] */ IVsObjectList2 **ppIVsObjectList2);


void __RPC_STUB IVsObjectList2_GetList2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsObjectList2_GetCategoryField2_Proxy( 
    IVsObjectList2 * This,
    /* [in] */ ULONG Index,
    /* [in] */ LIB_CATEGORY2 Category,
    /* [retval][out] */ DWORD *pfCatField);


void __RPC_STUB IVsObjectList2_GetCategoryField2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsObjectList2_GetExpandable3_Proxy( 
    IVsObjectList2 * This,
    /* [in] */ ULONG Index,
    /* [in] */ LIB_LISTTYPE2 ListTypeExcluded,
    /* [out] */ BOOL *pfExpandable);


void __RPC_STUB IVsObjectList2_GetExpandable3_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsObjectList2_GetNavigationInfo2_Proxy( 
    IVsObjectList2 * This,
    /* [in] */ ULONG Index,
    /* [out][in] */ VSOBNAVIGATIONINFO3 *pobNav);


void __RPC_STUB IVsObjectList2_GetNavigationInfo2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsObjectList2_LocateNavigationInfo2_Proxy( 
    IVsObjectList2 * This,
    /* [in] */ VSOBNAVIGATIONINFO3 *pobNav,
    /* [in] */ VSOBNAVNAMEINFONODE2 *pobName,
    /* [in] */ BOOL fDontUpdate,
    /* [out] */ BOOL *pfMatchedName,
    /* [out] */ ULONG *pIndex);


void __RPC_STUB IVsObjectList2_LocateNavigationInfo2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsObjectList2_GetBrowseObject_Proxy( 
    IVsObjectList2 * This,
    /* [in] */ ULONG Index,
    /* [out] */ IDispatch **ppdispBrowseObj);


void __RPC_STUB IVsObjectList2_GetBrowseObject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsObjectList2_GetUserContext_Proxy( 
    IVsObjectList2 * This,
    /* [in] */ ULONG Index,
    /* [out] */ IUnknown **ppunkUserCtx);


void __RPC_STUB IVsObjectList2_GetUserContext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsObjectList2_ShowHelp_Proxy( 
    IVsObjectList2 * This,
    /* [in] */ ULONG Index);


void __RPC_STUB IVsObjectList2_ShowHelp_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsObjectList2_GetSourceContext_Proxy( 
    IVsObjectList2 * This,
    /* [in] */ ULONG Index,
    /* [out] */ const WCHAR **pszFileName,
    /* [out] */ ULONG *pulLineNum);


void __RPC_STUB IVsObjectList2_GetSourceContext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsObjectList2_CountSourceItems_Proxy( 
    IVsObjectList2 * This,
    /* [in] */ ULONG Index,
    /* [out] */ IVsHierarchy **ppHier,
    /* [out] */ VSITEMID *pitemid,
    /* [retval][out] */ ULONG *pcItems);


void __RPC_STUB IVsObjectList2_CountSourceItems_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsObjectList2_GetMultipleSourceItems_Proxy( 
    IVsObjectList2 * This,
    /* [in] */ ULONG Index,
    /* [in] */ VSGSIFLAGS grfGSI,
    /* [in] */ ULONG cItems,
    /* [size_is][out] */ VSITEMSELECTION rgItemSel[  ]);


void __RPC_STUB IVsObjectList2_GetMultipleSourceItems_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsObjectList2_CanGoToSource_Proxy( 
    IVsObjectList2 * This,
    /* [in] */ ULONG Index,
    /* [in] */ VSOBJGOTOSRCTYPE SrcType,
    /* [out] */ BOOL *pfOK);


void __RPC_STUB IVsObjectList2_CanGoToSource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsObjectList2_GoToSource_Proxy( 
    IVsObjectList2 * This,
    /* [in] */ ULONG Index,
    /* [in] */ VSOBJGOTOSRCTYPE SrcType);


void __RPC_STUB IVsObjectList2_GoToSource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsObjectList2_GetContextMenu_Proxy( 
    IVsObjectList2 * This,
    /* [in] */ ULONG Index,
    /* [out] */ CLSID *pclsidActive,
    /* [out] */ LONG *pnMenuId,
    /* [out] */ IOleCommandTarget **ppCmdTrgtActive);


void __RPC_STUB IVsObjectList2_GetContextMenu_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsObjectList2_QueryDragDrop_Proxy( 
    IVsObjectList2 * This,
    /* [in] */ ULONG Index,
    /* [in] */ IDataObject *pDataObject,
    /* [in] */ DWORD grfKeyState,
    /* [out][in] */ DWORD *pdwEffect);


void __RPC_STUB IVsObjectList2_QueryDragDrop_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsObjectList2_DoDragDrop_Proxy( 
    IVsObjectList2 * This,
    /* [in] */ ULONG Index,
    /* [in] */ IDataObject *pDataObject,
    /* [in] */ DWORD grfKeyState,
    /* [out][in] */ DWORD *pdwEffect);


void __RPC_STUB IVsObjectList2_DoDragDrop_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsObjectList2_CanRename_Proxy( 
    IVsObjectList2 * This,
    /* [in] */ ULONG Index,
    /* [in] */ LPCOLESTR pszNewName,
    /* [out] */ BOOL *pfOK);


void __RPC_STUB IVsObjectList2_CanRename_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsObjectList2_DoRename_Proxy( 
    IVsObjectList2 * This,
    /* [in] */ ULONG Index,
    /* [in] */ LPCOLESTR pszNewName,
    /* [in] */ VSOBJOPFLAGS grfFlags);


void __RPC_STUB IVsObjectList2_DoRename_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsObjectList2_CanDelete_Proxy( 
    IVsObjectList2 * This,
    /* [in] */ ULONG Index,
    /* [out] */ BOOL *pfOK);


void __RPC_STUB IVsObjectList2_CanDelete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsObjectList2_DoDelete_Proxy( 
    IVsObjectList2 * This,
    /* [in] */ ULONG Index,
    /* [in] */ VSOBJOPFLAGS grfFlags);


void __RPC_STUB IVsObjectList2_DoDelete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsObjectList2_FillDescription_Proxy( 
    IVsObjectList2 * This,
    /* [in] */ ULONG Index,
    /* [in] */ VSOBJDESCOPTIONS grfOptions,
    /* [in] */ IVsObjectBrowserDescription2 *pobDesc);


void __RPC_STUB IVsObjectList2_FillDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsObjectList2_FillDescription2_Proxy( 
    IVsObjectList2 * This,
    /* [in] */ ULONG Index,
    /* [in] */ VSOBJDESCOPTIONS grfOptions,
    /* [in] */ IVsObjectBrowserDescription3 *pobDesc);


void __RPC_STUB IVsObjectList2_FillDescription2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsObjectList2_EnumClipboardFormats_Proxy( 
    IVsObjectList2 * This,
    /* [in] */ ULONG Index,
    /* [in] */ VSOBJCFFLAGS grfFlags,
    /* [in] */ ULONG celt,
    /* [size_is][out][in] */ VSOBJCLIPFORMAT rgcfFormats[  ],
    /* [optional][out] */ ULONG *pcActual);


void __RPC_STUB IVsObjectList2_EnumClipboardFormats_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsObjectList2_GetClipboardFormat_Proxy( 
    IVsObjectList2 * This,
    /* [in] */ ULONG Index,
    /* [in] */ VSOBJCFFLAGS grfFlags,
    /* [in] */ FORMATETC *pFormatetc,
    /* [in] */ STGMEDIUM *pMedium);


void __RPC_STUB IVsObjectList2_GetClipboardFormat_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsObjectList2_GetExtendedClipboardVariant_Proxy( 
    IVsObjectList2 * This,
    /* [in] */ ULONG Index,
    /* [in] */ VSOBJCFFLAGS grfFlags,
    /* [in] */ const VSOBJCLIPFORMAT *pcfFormat,
    /* [out] */ VARIANT *pvarFormat);


void __RPC_STUB IVsObjectList2_GetExtendedClipboardVariant_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsObjectList2_GetProperty_Proxy( 
    IVsObjectList2 * This,
    /* [in] */ ULONG Index,
    /* [in] */ VSOBJLISTELEMPROPID propid,
    /* [out] */ VARIANT *pvar);


void __RPC_STUB IVsObjectList2_GetProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsObjectList2_GetNavInfo_Proxy( 
    IVsObjectList2 * This,
    /* [in] */ ULONG Index,
    /* [out] */ IVsNavInfo **ppNavInfo);


void __RPC_STUB IVsObjectList2_GetNavInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsObjectList2_GetNavInfoNode_Proxy( 
    IVsObjectList2 * This,
    /* [in] */ ULONG Index,
    /* [out] */ IVsNavInfoNode **ppNavInfoNode);


void __RPC_STUB IVsObjectList2_GetNavInfoNode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsObjectList2_LocateNavInfoNode_Proxy( 
    IVsObjectList2 * This,
    /* [in] */ IVsNavInfoNode *pNavInfoNode,
    /* [out] */ ULONG *pulIndex);


void __RPC_STUB IVsObjectList2_LocateNavInfoNode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsObjectList2_INTERFACE_DEFINED__ */


#ifndef __IVsBrowseContainersList_INTERFACE_DEFINED__
#define __IVsBrowseContainersList_INTERFACE_DEFINED__

/* interface IVsBrowseContainersList */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsBrowseContainersList;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("288F2A0C-B2E5-4799-9B9C-24E6EFCEFBF4")
    IVsBrowseContainersList : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetContainerData( 
            /* [in] */ ULONG ulIndex,
            /* [out] */ VSCOMPONENTSELECTORDATA *pData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FindContainer( 
            /* [in] */ VSCOMPONENTSELECTORDATA *pData,
            /* [out] */ ULONG *pulIndex) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsBrowseContainersListVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsBrowseContainersList * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsBrowseContainersList * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsBrowseContainersList * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetContainerData )( 
            IVsBrowseContainersList * This,
            /* [in] */ ULONG ulIndex,
            /* [out] */ VSCOMPONENTSELECTORDATA *pData);
        
        HRESULT ( STDMETHODCALLTYPE *FindContainer )( 
            IVsBrowseContainersList * This,
            /* [in] */ VSCOMPONENTSELECTORDATA *pData,
            /* [out] */ ULONG *pulIndex);
        
        END_INTERFACE
    } IVsBrowseContainersListVtbl;

    interface IVsBrowseContainersList
    {
        CONST_VTBL struct IVsBrowseContainersListVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsBrowseContainersList_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsBrowseContainersList_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsBrowseContainersList_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsBrowseContainersList_GetContainerData(This,ulIndex,pData)	\
    (This)->lpVtbl -> GetContainerData(This,ulIndex,pData)

#define IVsBrowseContainersList_FindContainer(This,pData,pulIndex)	\
    (This)->lpVtbl -> FindContainer(This,pData,pulIndex)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsBrowseContainersList_GetContainerData_Proxy( 
    IVsBrowseContainersList * This,
    /* [in] */ ULONG ulIndex,
    /* [out] */ VSCOMPONENTSELECTORDATA *pData);


void __RPC_STUB IVsBrowseContainersList_GetContainerData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsBrowseContainersList_FindContainer_Proxy( 
    IVsBrowseContainersList * This,
    /* [in] */ VSCOMPONENTSELECTORDATA *pData,
    /* [out] */ ULONG *pulIndex);


void __RPC_STUB IVsBrowseContainersList_FindContainer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsBrowseContainersList_INTERFACE_DEFINED__ */


#ifndef __IVsLibrary2_INTERFACE_DEFINED__
#define __IVsLibrary2_INTERFACE_DEFINED__

/* interface IVsLibrary2 */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsLibrary2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EDD9F8A9-3FFE-4c4c-94F8-610B88E19160")
    IVsLibrary2 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetSupportedCategoryFields2( 
            /* [in] */ LIB_CATEGORY2 Category,
            /* [retval][out] */ DWORD *pgrfCatField) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetList2( 
            /* [in] */ LIB_LISTTYPE2 ListType,
            /* [in] */ LIB_LISTFLAGS Flags,
            /* [in] */ VSOBSEARCHCRITERIA2 *pobSrch,
            /* [retval][out] */ IVsObjectList2 **ppIVsObjectList2) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLibList( 
            /* [in] */ LIB_PERSISTTYPE lptType,
            /* [retval][out] */ IVsLiteTreeList **ppList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLibFlags2( 
            /* [retval][out] */ LIB_FLAGS2 *pgrfFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UpdateCounter( 
            /* [out] */ ULONG *pCurUpdate) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetGuid( 
            const GUID **ppguidLib) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSeparatorString( 
            LPCWSTR *pszSeparator) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadState( 
            /* [in] */ IStream *pIStream,
            /* [in] */ LIB_PERSISTTYPE lptType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SaveState( 
            /* [in] */ IStream *pIStream,
            /* [in] */ LIB_PERSISTTYPE lptType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBrowseContainersForHierarchy( 
            /* [in] */ IVsHierarchy *pHierarchy,
            /* [in] */ ULONG celt,
            /* [size_is][out][in] */ VSBROWSECONTAINER rgBrowseContainers[  ],
            /* [optional][out] */ ULONG *pcActual) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddBrowseContainer( 
            /* [in] */ PVSCOMPONENTSELECTORDATA pcdComponent,
            /* [out][in] */ LIB_ADDREMOVEOPTIONS *pgrfOptions,
            /* [out] */ BSTR *pbstrComponentAdded) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveBrowseContainer( 
            /* [in] */ DWORD dwReserved,
            /* [in] */ LPCWSTR pszLibName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateNavInfo( 
            /* [size_is][in] */ SYMBOL_DESCRIPTION_NODE rgSymbolNodes[  ],
            /* [in] */ ULONG ulcNodes,
            /* [out] */ IVsNavInfo **ppNavInfo) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsLibrary2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsLibrary2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsLibrary2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsLibrary2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetSupportedCategoryFields2 )( 
            IVsLibrary2 * This,
            /* [in] */ LIB_CATEGORY2 Category,
            /* [retval][out] */ DWORD *pgrfCatField);
        
        HRESULT ( STDMETHODCALLTYPE *GetList2 )( 
            IVsLibrary2 * This,
            /* [in] */ LIB_LISTTYPE2 ListType,
            /* [in] */ LIB_LISTFLAGS Flags,
            /* [in] */ VSOBSEARCHCRITERIA2 *pobSrch,
            /* [retval][out] */ IVsObjectList2 **ppIVsObjectList2);
        
        HRESULT ( STDMETHODCALLTYPE *GetLibList )( 
            IVsLibrary2 * This,
            /* [in] */ LIB_PERSISTTYPE lptType,
            /* [retval][out] */ IVsLiteTreeList **ppList);
        
        HRESULT ( STDMETHODCALLTYPE *GetLibFlags2 )( 
            IVsLibrary2 * This,
            /* [retval][out] */ LIB_FLAGS2 *pgrfFlags);
        
        HRESULT ( STDMETHODCALLTYPE *UpdateCounter )( 
            IVsLibrary2 * This,
            /* [out] */ ULONG *pCurUpdate);
        
        HRESULT ( STDMETHODCALLTYPE *GetGuid )( 
            IVsLibrary2 * This,
            const GUID **ppguidLib);
        
        HRESULT ( STDMETHODCALLTYPE *GetSeparatorString )( 
            IVsLibrary2 * This,
            LPCWSTR *pszSeparator);
        
        HRESULT ( STDMETHODCALLTYPE *LoadState )( 
            IVsLibrary2 * This,
            /* [in] */ IStream *pIStream,
            /* [in] */ LIB_PERSISTTYPE lptType);
        
        HRESULT ( STDMETHODCALLTYPE *SaveState )( 
            IVsLibrary2 * This,
            /* [in] */ IStream *pIStream,
            /* [in] */ LIB_PERSISTTYPE lptType);
        
        HRESULT ( STDMETHODCALLTYPE *GetBrowseContainersForHierarchy )( 
            IVsLibrary2 * This,
            /* [in] */ IVsHierarchy *pHierarchy,
            /* [in] */ ULONG celt,
            /* [size_is][out][in] */ VSBROWSECONTAINER rgBrowseContainers[  ],
            /* [optional][out] */ ULONG *pcActual);
        
        HRESULT ( STDMETHODCALLTYPE *AddBrowseContainer )( 
            IVsLibrary2 * This,
            /* [in] */ PVSCOMPONENTSELECTORDATA pcdComponent,
            /* [out][in] */ LIB_ADDREMOVEOPTIONS *pgrfOptions,
            /* [out] */ BSTR *pbstrComponentAdded);
        
        HRESULT ( STDMETHODCALLTYPE *RemoveBrowseContainer )( 
            IVsLibrary2 * This,
            /* [in] */ DWORD dwReserved,
            /* [in] */ LPCWSTR pszLibName);
        
        HRESULT ( STDMETHODCALLTYPE *CreateNavInfo )( 
            IVsLibrary2 * This,
            /* [size_is][in] */ SYMBOL_DESCRIPTION_NODE rgSymbolNodes[  ],
            /* [in] */ ULONG ulcNodes,
            /* [out] */ IVsNavInfo **ppNavInfo);
        
        END_INTERFACE
    } IVsLibrary2Vtbl;

    interface IVsLibrary2
    {
        CONST_VTBL struct IVsLibrary2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsLibrary2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsLibrary2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsLibrary2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsLibrary2_GetSupportedCategoryFields2(This,Category,pgrfCatField)	\
    (This)->lpVtbl -> GetSupportedCategoryFields2(This,Category,pgrfCatField)

#define IVsLibrary2_GetList2(This,ListType,Flags,pobSrch,ppIVsObjectList2)	\
    (This)->lpVtbl -> GetList2(This,ListType,Flags,pobSrch,ppIVsObjectList2)

#define IVsLibrary2_GetLibList(This,lptType,ppList)	\
    (This)->lpVtbl -> GetLibList(This,lptType,ppList)

#define IVsLibrary2_GetLibFlags2(This,pgrfFlags)	\
    (This)->lpVtbl -> GetLibFlags2(This,pgrfFlags)

#define IVsLibrary2_UpdateCounter(This,pCurUpdate)	\
    (This)->lpVtbl -> UpdateCounter(This,pCurUpdate)

#define IVsLibrary2_GetGuid(This,ppguidLib)	\
    (This)->lpVtbl -> GetGuid(This,ppguidLib)

#define IVsLibrary2_GetSeparatorString(This,pszSeparator)	\
    (This)->lpVtbl -> GetSeparatorString(This,pszSeparator)

#define IVsLibrary2_LoadState(This,pIStream,lptType)	\
    (This)->lpVtbl -> LoadState(This,pIStream,lptType)

#define IVsLibrary2_SaveState(This,pIStream,lptType)	\
    (This)->lpVtbl -> SaveState(This,pIStream,lptType)

#define IVsLibrary2_GetBrowseContainersForHierarchy(This,pHierarchy,celt,rgBrowseContainers,pcActual)	\
    (This)->lpVtbl -> GetBrowseContainersForHierarchy(This,pHierarchy,celt,rgBrowseContainers,pcActual)

#define IVsLibrary2_AddBrowseContainer(This,pcdComponent,pgrfOptions,pbstrComponentAdded)	\
    (This)->lpVtbl -> AddBrowseContainer(This,pcdComponent,pgrfOptions,pbstrComponentAdded)

#define IVsLibrary2_RemoveBrowseContainer(This,dwReserved,pszLibName)	\
    (This)->lpVtbl -> RemoveBrowseContainer(This,dwReserved,pszLibName)

#define IVsLibrary2_CreateNavInfo(This,rgSymbolNodes,ulcNodes,ppNavInfo)	\
    (This)->lpVtbl -> CreateNavInfo(This,rgSymbolNodes,ulcNodes,ppNavInfo)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsLibrary2_GetSupportedCategoryFields2_Proxy( 
    IVsLibrary2 * This,
    /* [in] */ LIB_CATEGORY2 Category,
    /* [retval][out] */ DWORD *pgrfCatField);


void __RPC_STUB IVsLibrary2_GetSupportedCategoryFields2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsLibrary2_GetList2_Proxy( 
    IVsLibrary2 * This,
    /* [in] */ LIB_LISTTYPE2 ListType,
    /* [in] */ LIB_LISTFLAGS Flags,
    /* [in] */ VSOBSEARCHCRITERIA2 *pobSrch,
    /* [retval][out] */ IVsObjectList2 **ppIVsObjectList2);


void __RPC_STUB IVsLibrary2_GetList2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsLibrary2_GetLibList_Proxy( 
    IVsLibrary2 * This,
    /* [in] */ LIB_PERSISTTYPE lptType,
    /* [retval][out] */ IVsLiteTreeList **ppList);


void __RPC_STUB IVsLibrary2_GetLibList_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsLibrary2_GetLibFlags2_Proxy( 
    IVsLibrary2 * This,
    /* [retval][out] */ LIB_FLAGS2 *pgrfFlags);


void __RPC_STUB IVsLibrary2_GetLibFlags2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsLibrary2_UpdateCounter_Proxy( 
    IVsLibrary2 * This,
    /* [out] */ ULONG *pCurUpdate);


void __RPC_STUB IVsLibrary2_UpdateCounter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsLibrary2_GetGuid_Proxy( 
    IVsLibrary2 * This,
    const GUID **ppguidLib);


void __RPC_STUB IVsLibrary2_GetGuid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsLibrary2_GetSeparatorString_Proxy( 
    IVsLibrary2 * This,
    LPCWSTR *pszSeparator);


void __RPC_STUB IVsLibrary2_GetSeparatorString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsLibrary2_LoadState_Proxy( 
    IVsLibrary2 * This,
    /* [in] */ IStream *pIStream,
    /* [in] */ LIB_PERSISTTYPE lptType);


void __RPC_STUB IVsLibrary2_LoadState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsLibrary2_SaveState_Proxy( 
    IVsLibrary2 * This,
    /* [in] */ IStream *pIStream,
    /* [in] */ LIB_PERSISTTYPE lptType);


void __RPC_STUB IVsLibrary2_SaveState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsLibrary2_GetBrowseContainersForHierarchy_Proxy( 
    IVsLibrary2 * This,
    /* [in] */ IVsHierarchy *pHierarchy,
    /* [in] */ ULONG celt,
    /* [size_is][out][in] */ VSBROWSECONTAINER rgBrowseContainers[  ],
    /* [optional][out] */ ULONG *pcActual);


void __RPC_STUB IVsLibrary2_GetBrowseContainersForHierarchy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsLibrary2_AddBrowseContainer_Proxy( 
    IVsLibrary2 * This,
    /* [in] */ PVSCOMPONENTSELECTORDATA pcdComponent,
    /* [out][in] */ LIB_ADDREMOVEOPTIONS *pgrfOptions,
    /* [out] */ BSTR *pbstrComponentAdded);


void __RPC_STUB IVsLibrary2_AddBrowseContainer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsLibrary2_RemoveBrowseContainer_Proxy( 
    IVsLibrary2 * This,
    /* [in] */ DWORD dwReserved,
    /* [in] */ LPCWSTR pszLibName);


void __RPC_STUB IVsLibrary2_RemoveBrowseContainer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsLibrary2_CreateNavInfo_Proxy( 
    IVsLibrary2 * This,
    /* [size_is][in] */ SYMBOL_DESCRIPTION_NODE rgSymbolNodes[  ],
    /* [in] */ ULONG ulcNodes,
    /* [out] */ IVsNavInfo **ppNavInfo);


void __RPC_STUB IVsLibrary2_CreateNavInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsLibrary2_INTERFACE_DEFINED__ */


#ifndef __IVsLibrary2Ex_INTERFACE_DEFINED__
#define __IVsLibrary2Ex_INTERFACE_DEFINED__

/* interface IVsLibrary2Ex */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsLibrary2Ex;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D9C7D24D-7ED2-4a9d-93D1-450426CB27DF")
    IVsLibrary2Ex : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetNavInfoContainerData( 
            /* [in] */ IVsNavInfo *pNavInfo,
            /* [out] */ VSCOMPONENTSELECTORDATA *pcsdComponent) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsLibrary2ExVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsLibrary2Ex * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsLibrary2Ex * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsLibrary2Ex * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetNavInfoContainerData )( 
            IVsLibrary2Ex * This,
            /* [in] */ IVsNavInfo *pNavInfo,
            /* [out] */ VSCOMPONENTSELECTORDATA *pcsdComponent);
        
        END_INTERFACE
    } IVsLibrary2ExVtbl;

    interface IVsLibrary2Ex
    {
        CONST_VTBL struct IVsLibrary2ExVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsLibrary2Ex_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsLibrary2Ex_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsLibrary2Ex_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsLibrary2Ex_GetNavInfoContainerData(This,pNavInfo,pcsdComponent)	\
    (This)->lpVtbl -> GetNavInfoContainerData(This,pNavInfo,pcsdComponent)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsLibrary2Ex_GetNavInfoContainerData_Proxy( 
    IVsLibrary2Ex * This,
    /* [in] */ IVsNavInfo *pNavInfo,
    /* [out] */ VSCOMPONENTSELECTORDATA *pcsdComponent);


void __RPC_STUB IVsLibrary2Ex_GetNavInfoContainerData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsLibrary2Ex_INTERFACE_DEFINED__ */


#ifndef __IVsEnumLibraries2_INTERFACE_DEFINED__
#define __IVsEnumLibraries2_INTERFACE_DEFINED__

/* interface IVsEnumLibraries2 */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsEnumLibraries2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FE2BB01D-6EBA-4796-ADF9-59EC7D100AC2")
    IVsEnumLibraries2 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ IVsLibrary2 **rgelt,
            /* [out] */ ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IVsEnumLibraries2 **ppenum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsEnumLibraries2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsEnumLibraries2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsEnumLibraries2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsEnumLibraries2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IVsEnumLibraries2 * This,
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ IVsLibrary2 **rgelt,
            /* [out] */ ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IVsEnumLibraries2 * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IVsEnumLibraries2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IVsEnumLibraries2 * This,
            /* [out] */ IVsEnumLibraries2 **ppenum);
        
        END_INTERFACE
    } IVsEnumLibraries2Vtbl;

    interface IVsEnumLibraries2
    {
        CONST_VTBL struct IVsEnumLibraries2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsEnumLibraries2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsEnumLibraries2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsEnumLibraries2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsEnumLibraries2_Next(This,celt,rgelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched)

#define IVsEnumLibraries2_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IVsEnumLibraries2_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IVsEnumLibraries2_Clone(This,ppenum)	\
    (This)->lpVtbl -> Clone(This,ppenum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsEnumLibraries2_Next_Proxy( 
    IVsEnumLibraries2 * This,
    /* [in] */ ULONG celt,
    /* [length_is][size_is][out] */ IVsLibrary2 **rgelt,
    /* [out] */ ULONG *pceltFetched);


void __RPC_STUB IVsEnumLibraries2_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsEnumLibraries2_Skip_Proxy( 
    IVsEnumLibraries2 * This,
    /* [in] */ ULONG celt);


void __RPC_STUB IVsEnumLibraries2_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsEnumLibraries2_Reset_Proxy( 
    IVsEnumLibraries2 * This);


void __RPC_STUB IVsEnumLibraries2_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsEnumLibraries2_Clone_Proxy( 
    IVsEnumLibraries2 * This,
    /* [out] */ IVsEnumLibraries2 **ppenum);


void __RPC_STUB IVsEnumLibraries2_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsEnumLibraries2_INTERFACE_DEFINED__ */


#ifndef __IVsObjectManager2_INTERFACE_DEFINED__
#define __IVsObjectManager2_INTERFACE_DEFINED__

/* interface IVsObjectManager2 */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsObjectManager2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6A0392E4-68E8-4fbc-AFCF-85155533E48E")
    IVsObjectManager2 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE RegisterLibrary( 
            /* [in] */ IVsLibrary2 *pLib,
            /* [out] */ VSCOOKIE *pdwCookie) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnregisterLibrary( 
            /* [in] */ VSCOOKIE dwCookie) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumLibraries( 
            /* [out] */ IVsEnumLibraries2 **ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FindLibrary( 
            /* [in] */ REFGUID guidLibrary,
            /* [out] */ IVsLibrary2 **ppLib) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsObjectManager2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsObjectManager2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsObjectManager2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsObjectManager2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *RegisterLibrary )( 
            IVsObjectManager2 * This,
            /* [in] */ IVsLibrary2 *pLib,
            /* [out] */ VSCOOKIE *pdwCookie);
        
        HRESULT ( STDMETHODCALLTYPE *UnregisterLibrary )( 
            IVsObjectManager2 * This,
            /* [in] */ VSCOOKIE dwCookie);
        
        HRESULT ( STDMETHODCALLTYPE *EnumLibraries )( 
            IVsObjectManager2 * This,
            /* [out] */ IVsEnumLibraries2 **ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE *FindLibrary )( 
            IVsObjectManager2 * This,
            /* [in] */ REFGUID guidLibrary,
            /* [out] */ IVsLibrary2 **ppLib);
        
        END_INTERFACE
    } IVsObjectManager2Vtbl;

    interface IVsObjectManager2
    {
        CONST_VTBL struct IVsObjectManager2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsObjectManager2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsObjectManager2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsObjectManager2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsObjectManager2_RegisterLibrary(This,pLib,pdwCookie)	\
    (This)->lpVtbl -> RegisterLibrary(This,pLib,pdwCookie)

#define IVsObjectManager2_UnregisterLibrary(This,dwCookie)	\
    (This)->lpVtbl -> UnregisterLibrary(This,dwCookie)

#define IVsObjectManager2_EnumLibraries(This,ppEnum)	\
    (This)->lpVtbl -> EnumLibraries(This,ppEnum)

#define IVsObjectManager2_FindLibrary(This,guidLibrary,ppLib)	\
    (This)->lpVtbl -> FindLibrary(This,guidLibrary,ppLib)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsObjectManager2_RegisterLibrary_Proxy( 
    IVsObjectManager2 * This,
    /* [in] */ IVsLibrary2 *pLib,
    /* [out] */ VSCOOKIE *pdwCookie);


void __RPC_STUB IVsObjectManager2_RegisterLibrary_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsObjectManager2_UnregisterLibrary_Proxy( 
    IVsObjectManager2 * This,
    /* [in] */ VSCOOKIE dwCookie);


void __RPC_STUB IVsObjectManager2_UnregisterLibrary_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsObjectManager2_EnumLibraries_Proxy( 
    IVsObjectManager2 * This,
    /* [out] */ IVsEnumLibraries2 **ppEnum);


void __RPC_STUB IVsObjectManager2_EnumLibraries_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsObjectManager2_FindLibrary_Proxy( 
    IVsObjectManager2 * This,
    /* [in] */ REFGUID guidLibrary,
    /* [out] */ IVsLibrary2 **ppLib);


void __RPC_STUB IVsObjectManager2_FindLibrary_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsObjectManager2_INTERFACE_DEFINED__ */


#ifndef __IVsSelectedSymbol_INTERFACE_DEFINED__
#define __IVsSelectedSymbol_INTERFACE_DEFINED__

/* interface IVsSelectedSymbol */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsSelectedSymbol;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9D86535E-5FE7-4aaf-8846-F1FB5556109A")
    IVsSelectedSymbol : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetNavInfo( 
            /* [out] */ IVsNavInfo **ppNavInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetName( 
            /* [out] */ BSTR *pbstrName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsSelectedSymbolVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsSelectedSymbol * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsSelectedSymbol * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsSelectedSymbol * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetNavInfo )( 
            IVsSelectedSymbol * This,
            /* [out] */ IVsNavInfo **ppNavInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetName )( 
            IVsSelectedSymbol * This,
            /* [out] */ BSTR *pbstrName);
        
        END_INTERFACE
    } IVsSelectedSymbolVtbl;

    interface IVsSelectedSymbol
    {
        CONST_VTBL struct IVsSelectedSymbolVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsSelectedSymbol_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsSelectedSymbol_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsSelectedSymbol_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsSelectedSymbol_GetNavInfo(This,ppNavInfo)	\
    (This)->lpVtbl -> GetNavInfo(This,ppNavInfo)

#define IVsSelectedSymbol_GetName(This,pbstrName)	\
    (This)->lpVtbl -> GetName(This,pbstrName)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsSelectedSymbol_GetNavInfo_Proxy( 
    IVsSelectedSymbol * This,
    /* [out] */ IVsNavInfo **ppNavInfo);


void __RPC_STUB IVsSelectedSymbol_GetNavInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSelectedSymbol_GetName_Proxy( 
    IVsSelectedSymbol * This,
    /* [out] */ BSTR *pbstrName);


void __RPC_STUB IVsSelectedSymbol_GetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsSelectedSymbol_INTERFACE_DEFINED__ */


#ifndef __IVsEnumSelectedSymbols_INTERFACE_DEFINED__
#define __IVsEnumSelectedSymbols_INTERFACE_DEFINED__

/* interface IVsEnumSelectedSymbols */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsEnumSelectedSymbols;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CAC67C59-301A-415d-B269-790F7D4731BC")
    IVsEnumSelectedSymbols : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ IVsSelectedSymbol **rgpIVsSelectedSymbol,
            /* [out] */ ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IVsEnumSelectedSymbols **ppIVsEnumSelectedSymbols) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsEnumSelectedSymbolsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsEnumSelectedSymbols * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsEnumSelectedSymbols * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsEnumSelectedSymbols * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IVsEnumSelectedSymbols * This,
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ IVsSelectedSymbol **rgpIVsSelectedSymbol,
            /* [out] */ ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IVsEnumSelectedSymbols * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IVsEnumSelectedSymbols * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IVsEnumSelectedSymbols * This,
            /* [out] */ IVsEnumSelectedSymbols **ppIVsEnumSelectedSymbols);
        
        END_INTERFACE
    } IVsEnumSelectedSymbolsVtbl;

    interface IVsEnumSelectedSymbols
    {
        CONST_VTBL struct IVsEnumSelectedSymbolsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsEnumSelectedSymbols_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsEnumSelectedSymbols_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsEnumSelectedSymbols_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsEnumSelectedSymbols_Next(This,celt,rgpIVsSelectedSymbol,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgpIVsSelectedSymbol,pceltFetched)

#define IVsEnumSelectedSymbols_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IVsEnumSelectedSymbols_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IVsEnumSelectedSymbols_Clone(This,ppIVsEnumSelectedSymbols)	\
    (This)->lpVtbl -> Clone(This,ppIVsEnumSelectedSymbols)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsEnumSelectedSymbols_Next_Proxy( 
    IVsEnumSelectedSymbols * This,
    /* [in] */ ULONG celt,
    /* [length_is][size_is][out] */ IVsSelectedSymbol **rgpIVsSelectedSymbol,
    /* [out] */ ULONG *pceltFetched);


void __RPC_STUB IVsEnumSelectedSymbols_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsEnumSelectedSymbols_Skip_Proxy( 
    IVsEnumSelectedSymbols * This,
    /* [in] */ ULONG celt);


void __RPC_STUB IVsEnumSelectedSymbols_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsEnumSelectedSymbols_Reset_Proxy( 
    IVsEnumSelectedSymbols * This);


void __RPC_STUB IVsEnumSelectedSymbols_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsEnumSelectedSymbols_Clone_Proxy( 
    IVsEnumSelectedSymbols * This,
    /* [out] */ IVsEnumSelectedSymbols **ppIVsEnumSelectedSymbols);


void __RPC_STUB IVsEnumSelectedSymbols_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsEnumSelectedSymbols_INTERFACE_DEFINED__ */


#ifndef __IVsSelectedSymbols_INTERFACE_DEFINED__
#define __IVsSelectedSymbols_INTERFACE_DEFINED__

/* interface IVsSelectedSymbols */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsSelectedSymbols;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8A8921BE-42C7-4984-82E9-C68B12C2B22E")
    IVsSelectedSymbols : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetCount( 
            /* [out] */ ULONG *pcItems) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetItem( 
            /* [in] */ ULONG iItem,
            /* [out] */ IVsSelectedSymbol **ppIVsSelectedSymbol) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumSelectedSymbols( 
            /* [out] */ IVsEnumSelectedSymbols **ppIVsEnumSelectedSymbols) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetItemTypes( 
            /* [out] */ DWORD *pgrfTypes) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsSelectedSymbolsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsSelectedSymbols * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsSelectedSymbols * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsSelectedSymbols * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetCount )( 
            IVsSelectedSymbols * This,
            /* [out] */ ULONG *pcItems);
        
        HRESULT ( STDMETHODCALLTYPE *GetItem )( 
            IVsSelectedSymbols * This,
            /* [in] */ ULONG iItem,
            /* [out] */ IVsSelectedSymbol **ppIVsSelectedSymbol);
        
        HRESULT ( STDMETHODCALLTYPE *EnumSelectedSymbols )( 
            IVsSelectedSymbols * This,
            /* [out] */ IVsEnumSelectedSymbols **ppIVsEnumSelectedSymbols);
        
        HRESULT ( STDMETHODCALLTYPE *GetItemTypes )( 
            IVsSelectedSymbols * This,
            /* [out] */ DWORD *pgrfTypes);
        
        END_INTERFACE
    } IVsSelectedSymbolsVtbl;

    interface IVsSelectedSymbols
    {
        CONST_VTBL struct IVsSelectedSymbolsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsSelectedSymbols_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsSelectedSymbols_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsSelectedSymbols_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsSelectedSymbols_GetCount(This,pcItems)	\
    (This)->lpVtbl -> GetCount(This,pcItems)

#define IVsSelectedSymbols_GetItem(This,iItem,ppIVsSelectedSymbol)	\
    (This)->lpVtbl -> GetItem(This,iItem,ppIVsSelectedSymbol)

#define IVsSelectedSymbols_EnumSelectedSymbols(This,ppIVsEnumSelectedSymbols)	\
    (This)->lpVtbl -> EnumSelectedSymbols(This,ppIVsEnumSelectedSymbols)

#define IVsSelectedSymbols_GetItemTypes(This,pgrfTypes)	\
    (This)->lpVtbl -> GetItemTypes(This,pgrfTypes)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsSelectedSymbols_GetCount_Proxy( 
    IVsSelectedSymbols * This,
    /* [out] */ ULONG *pcItems);


void __RPC_STUB IVsSelectedSymbols_GetCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSelectedSymbols_GetItem_Proxy( 
    IVsSelectedSymbols * This,
    /* [in] */ ULONG iItem,
    /* [out] */ IVsSelectedSymbol **ppIVsSelectedSymbol);


void __RPC_STUB IVsSelectedSymbols_GetItem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSelectedSymbols_EnumSelectedSymbols_Proxy( 
    IVsSelectedSymbols * This,
    /* [out] */ IVsEnumSelectedSymbols **ppIVsEnumSelectedSymbols);


void __RPC_STUB IVsSelectedSymbols_EnumSelectedSymbols_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSelectedSymbols_GetItemTypes_Proxy( 
    IVsSelectedSymbols * This,
    /* [out] */ DWORD *pgrfTypes);


void __RPC_STUB IVsSelectedSymbols_GetItemTypes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsSelectedSymbols_INTERFACE_DEFINED__ */


#ifndef __IVsNavigationTool_INTERFACE_DEFINED__
#define __IVsNavigationTool_INTERFACE_DEFINED__

/* interface IVsNavigationTool */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsNavigationTool;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FDAEB434-F941-4370-9B89-325249EFEC48")
    IVsNavigationTool : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE NavigateToSymbol( 
            /* [in] */ REFGUID guidLib,
            /* [size_is][in] */ SYMBOL_DESCRIPTION_NODE rgSymbolNodes[  ],
            /* [in] */ ULONG ulcNodes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE NavigateToNavInfo( 
            /* [in] */ IVsNavInfo *pNavInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSelectedSymbols( 
            /* [out] */ IVsSelectedSymbols **ppIVsSelectedSymbols) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsNavigationToolVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsNavigationTool * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsNavigationTool * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsNavigationTool * This);
        
        HRESULT ( STDMETHODCALLTYPE *NavigateToSymbol )( 
            IVsNavigationTool * This,
            /* [in] */ REFGUID guidLib,
            /* [size_is][in] */ SYMBOL_DESCRIPTION_NODE rgSymbolNodes[  ],
            /* [in] */ ULONG ulcNodes);
        
        HRESULT ( STDMETHODCALLTYPE *NavigateToNavInfo )( 
            IVsNavigationTool * This,
            /* [in] */ IVsNavInfo *pNavInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetSelectedSymbols )( 
            IVsNavigationTool * This,
            /* [out] */ IVsSelectedSymbols **ppIVsSelectedSymbols);
        
        END_INTERFACE
    } IVsNavigationToolVtbl;

    interface IVsNavigationTool
    {
        CONST_VTBL struct IVsNavigationToolVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsNavigationTool_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsNavigationTool_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsNavigationTool_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsNavigationTool_NavigateToSymbol(This,guidLib,rgSymbolNodes,ulcNodes)	\
    (This)->lpVtbl -> NavigateToSymbol(This,guidLib,rgSymbolNodes,ulcNodes)

#define IVsNavigationTool_NavigateToNavInfo(This,pNavInfo)	\
    (This)->lpVtbl -> NavigateToNavInfo(This,pNavInfo)

#define IVsNavigationTool_GetSelectedSymbols(This,ppIVsSelectedSymbols)	\
    (This)->lpVtbl -> GetSelectedSymbols(This,ppIVsSelectedSymbols)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsNavigationTool_NavigateToSymbol_Proxy( 
    IVsNavigationTool * This,
    /* [in] */ REFGUID guidLib,
    /* [size_is][in] */ SYMBOL_DESCRIPTION_NODE rgSymbolNodes[  ],
    /* [in] */ ULONG ulcNodes);


void __RPC_STUB IVsNavigationTool_NavigateToSymbol_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsNavigationTool_NavigateToNavInfo_Proxy( 
    IVsNavigationTool * This,
    /* [in] */ IVsNavInfo *pNavInfo);


void __RPC_STUB IVsNavigationTool_NavigateToNavInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsNavigationTool_GetSelectedSymbols_Proxy( 
    IVsNavigationTool * This,
    /* [out] */ IVsSelectedSymbols **ppIVsSelectedSymbols);


void __RPC_STUB IVsNavigationTool_GetSelectedSymbols_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsNavigationTool_INTERFACE_DEFINED__ */


#ifndef __IVsFindSymbol_INTERFACE_DEFINED__
#define __IVsFindSymbol_INTERFACE_DEFINED__

/* interface IVsFindSymbol */
/* [object][unique][version][local][uuid] */ 


EXTERN_C const IID IID_IVsFindSymbol;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7FF85070-4667-4532-B149-63A7B205060B")
    IVsFindSymbol : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetUserOptions( 
            /* [out] */ GUID *pguidScope,
            /* [out] */ VSOBSEARCHCRITERIA2 *pobSrch) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetUserOptions( 
            /* [in] */ REFGUID guidScope,
            /* [in] */ const VSOBSEARCHCRITERIA2 *pobSrch) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DoSearch( 
            /* [in] */ REFGUID guidSymbolScope,
            /* [in] */ const VSOBSEARCHCRITERIA2 *pobSrch) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsFindSymbolVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsFindSymbol * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsFindSymbol * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsFindSymbol * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetUserOptions )( 
            IVsFindSymbol * This,
            /* [out] */ GUID *pguidScope,
            /* [out] */ VSOBSEARCHCRITERIA2 *pobSrch);
        
        HRESULT ( STDMETHODCALLTYPE *SetUserOptions )( 
            IVsFindSymbol * This,
            /* [in] */ REFGUID guidScope,
            /* [in] */ const VSOBSEARCHCRITERIA2 *pobSrch);
        
        HRESULT ( STDMETHODCALLTYPE *DoSearch )( 
            IVsFindSymbol * This,
            /* [in] */ REFGUID guidSymbolScope,
            /* [in] */ const VSOBSEARCHCRITERIA2 *pobSrch);
        
        END_INTERFACE
    } IVsFindSymbolVtbl;

    interface IVsFindSymbol
    {
        CONST_VTBL struct IVsFindSymbolVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsFindSymbol_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsFindSymbol_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsFindSymbol_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsFindSymbol_GetUserOptions(This,pguidScope,pobSrch)	\
    (This)->lpVtbl -> GetUserOptions(This,pguidScope,pobSrch)

#define IVsFindSymbol_SetUserOptions(This,guidScope,pobSrch)	\
    (This)->lpVtbl -> SetUserOptions(This,guidScope,pobSrch)

#define IVsFindSymbol_DoSearch(This,guidSymbolScope,pobSrch)	\
    (This)->lpVtbl -> DoSearch(This,guidSymbolScope,pobSrch)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsFindSymbol_GetUserOptions_Proxy( 
    IVsFindSymbol * This,
    /* [out] */ GUID *pguidScope,
    /* [out] */ VSOBSEARCHCRITERIA2 *pobSrch);


void __RPC_STUB IVsFindSymbol_GetUserOptions_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsFindSymbol_SetUserOptions_Proxy( 
    IVsFindSymbol * This,
    /* [in] */ REFGUID guidScope,
    /* [in] */ const VSOBSEARCHCRITERIA2 *pobSrch);


void __RPC_STUB IVsFindSymbol_SetUserOptions_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsFindSymbol_DoSearch_Proxy( 
    IVsFindSymbol * This,
    /* [in] */ REFGUID guidSymbolScope,
    /* [in] */ const VSOBSEARCHCRITERIA2 *pobSrch);


void __RPC_STUB IVsFindSymbol_DoSearch_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsFindSymbol_INTERFACE_DEFINED__ */


#ifndef __IVsFindSymbolEvents_INTERFACE_DEFINED__
#define __IVsFindSymbolEvents_INTERFACE_DEFINED__

/* interface IVsFindSymbolEvents */
/* [object][version][uuid] */ 


EXTERN_C const IID IID_IVsFindSymbolEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("18220DBE-1AEB-44ea-A924-F3571D202EF4")
    IVsFindSymbolEvents : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnUserOptionsChanged( 
            /* [in] */ REFGUID guidSymbolScope,
            /* [in] */ const VSOBSEARCHCRITERIA2 *pobSrch) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsFindSymbolEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsFindSymbolEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsFindSymbolEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsFindSymbolEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnUserOptionsChanged )( 
            IVsFindSymbolEvents * This,
            /* [in] */ REFGUID guidSymbolScope,
            /* [in] */ const VSOBSEARCHCRITERIA2 *pobSrch);
        
        END_INTERFACE
    } IVsFindSymbolEventsVtbl;

    interface IVsFindSymbolEvents
    {
        CONST_VTBL struct IVsFindSymbolEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsFindSymbolEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsFindSymbolEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsFindSymbolEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsFindSymbolEvents_OnUserOptionsChanged(This,guidSymbolScope,pobSrch)	\
    (This)->lpVtbl -> OnUserOptionsChanged(This,guidSymbolScope,pobSrch)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsFindSymbolEvents_OnUserOptionsChanged_Proxy( 
    IVsFindSymbolEvents * This,
    /* [in] */ REFGUID guidSymbolScope,
    /* [in] */ const VSOBSEARCHCRITERIA2 *pobSrch);


void __RPC_STUB IVsFindSymbolEvents_OnUserOptionsChanged_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsFindSymbolEvents_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshell80_0742 */
/* [local] */ 

DEFINE_GUID(GUID_VsSymbolScope_All, 0xa5a527ea, 0xcf0a, 0x4abf, 0xb5, 0x1, 0xea, 0xfe, 0x6b, 0x3b, 0xa5, 0xc6);
DEFINE_GUID(GUID_VsSymbolScope_OBSelectedComponents, 0x41fd0b24, 0x8d2b, 0x48c1, 0xb1, 0xda, 0xaa, 0xcf, 0x13, 0xa5, 0x57, 0xf);
DEFINE_GUID(GUID_VsSymbolScope_FSSelectedComponents, 0xc2146638, 0xc2fe, 0x4c1e, 0xa4, 0x9d, 0x64, 0xae, 0x97, 0x1e, 0xef, 0x39);
DEFINE_GUID(GUID_VsSymbolScope_Frameworks, 0x3168518c, 0xb7c9, 0x4e0c, 0xbd, 0x51, 0xe3, 0x32, 0x1c, 0xa7, 0xb4, 0xd8);
DEFINE_GUID(GUID_VsSymbolScope_Solution, 0xb1ba9461, 0xfc54, 0x45b3, 0xa4, 0x84, 0xcb, 0x6d, 0xd0, 0xb9, 0x5c, 0x94);

enum __VSCALLBROWSERMODE
    {	CBM_CALLSTO	= 0,
	CBM_CALLSTO_NEWWINDOW	= 1,
	CBM_CALLSFROM	= 2,
	CBM_CALLSFROM_NEWWINDOW	= 3
    } ;
typedef LONG CALLBROWSERMODE;



extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0742_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0742_v0_0_s_ifspec;

#ifndef __IVsCallBrowser_INTERFACE_DEFINED__
#define __IVsCallBrowser_INTERFACE_DEFINED__

/* interface IVsCallBrowser */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsCallBrowser;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6ED4E844-A0AF-4d6f-B108-8E655785BC88")
    IVsCallBrowser : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetRootAtSymbol( 
            /* [in] */ CALLBROWSERMODE cbMode,
            /* [in] */ REFGUID guidLib,
            /* [size_is][in] */ SYMBOL_DESCRIPTION_NODE rgSymbolNodes[  ],
            /* [in] */ ULONG ulcNodes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRootAtNavInfo( 
            /* [in] */ CALLBROWSERMODE cbMode,
            /* [in] */ IVsNavInfo *pNavInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CanCreateNewInstance( 
            /* [out] */ BOOL *pfOK) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsCallBrowserVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsCallBrowser * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsCallBrowser * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsCallBrowser * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetRootAtSymbol )( 
            IVsCallBrowser * This,
            /* [in] */ CALLBROWSERMODE cbMode,
            /* [in] */ REFGUID guidLib,
            /* [size_is][in] */ SYMBOL_DESCRIPTION_NODE rgSymbolNodes[  ],
            /* [in] */ ULONG ulcNodes);
        
        HRESULT ( STDMETHODCALLTYPE *SetRootAtNavInfo )( 
            IVsCallBrowser * This,
            /* [in] */ CALLBROWSERMODE cbMode,
            /* [in] */ IVsNavInfo *pNavInfo);
        
        HRESULT ( STDMETHODCALLTYPE *CanCreateNewInstance )( 
            IVsCallBrowser * This,
            /* [out] */ BOOL *pfOK);
        
        END_INTERFACE
    } IVsCallBrowserVtbl;

    interface IVsCallBrowser
    {
        CONST_VTBL struct IVsCallBrowserVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsCallBrowser_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsCallBrowser_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsCallBrowser_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsCallBrowser_SetRootAtSymbol(This,cbMode,guidLib,rgSymbolNodes,ulcNodes)	\
    (This)->lpVtbl -> SetRootAtSymbol(This,cbMode,guidLib,rgSymbolNodes,ulcNodes)

#define IVsCallBrowser_SetRootAtNavInfo(This,cbMode,pNavInfo)	\
    (This)->lpVtbl -> SetRootAtNavInfo(This,cbMode,pNavInfo)

#define IVsCallBrowser_CanCreateNewInstance(This,pfOK)	\
    (This)->lpVtbl -> CanCreateNewInstance(This,pfOK)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsCallBrowser_SetRootAtSymbol_Proxy( 
    IVsCallBrowser * This,
    /* [in] */ CALLBROWSERMODE cbMode,
    /* [in] */ REFGUID guidLib,
    /* [size_is][in] */ SYMBOL_DESCRIPTION_NODE rgSymbolNodes[  ],
    /* [in] */ ULONG ulcNodes);


void __RPC_STUB IVsCallBrowser_SetRootAtSymbol_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsCallBrowser_SetRootAtNavInfo_Proxy( 
    IVsCallBrowser * This,
    /* [in] */ CALLBROWSERMODE cbMode,
    /* [in] */ IVsNavInfo *pNavInfo);


void __RPC_STUB IVsCallBrowser_SetRootAtNavInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsCallBrowser_CanCreateNewInstance_Proxy( 
    IVsCallBrowser * This,
    /* [out] */ BOOL *pfOK);


void __RPC_STUB IVsCallBrowser_CanCreateNewInstance_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsCallBrowser_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshell80_0743 */
/* [local] */ 

#define SID_SVsCallBrowser IID_IVsCallBrowser
extern const __declspec(selectany) GUID GUID_CallBrowser = { 0x5415ea3a, 0xd813, 0x4948, { 0xb5, 0x1e, 0x56, 0x20, 0x82, 0xce, 0x8, 0x87 } };

enum __VSCOMPSELFLAGS2
    {	VSCOMSEL2_MultiSelectMode	= 0x1,
	VSCOMSEL2_ShowSelectedList	= 0x80
    } ;
typedef DWORD VSCOMPSELFLAGS2;



extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0743_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0743_v0_0_s_ifspec;

#ifndef __IVsComponentSelectorDlg2_INTERFACE_DEFINED__
#define __IVsComponentSelectorDlg2_INTERFACE_DEFINED__

/* interface IVsComponentSelectorDlg2 */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsComponentSelectorDlg2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2D7CDC3D-FA79-4df3-9CD2-AACF65A2846E")
    IVsComponentSelectorDlg2 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ComponentSelectorDlg2( 
            /* [in] */ VSCOMPSELFLAGS2 grfFlags,
            /* [in] */ IVsComponentUser *pUser,
            /* [in] */ ULONG cComponents,
            /* [size_is][in] */ PVSCOMPONENTSELECTORDATA rgpcsdComponents[  ],
            /* [in] */ LPCOLESTR lpszDlgTitle,
            /* [in] */ LPCOLESTR lpszHelpTopic,
            /* [out][in] */ ULONG *pxDlgSize,
            /* [out][in] */ ULONG *pyDlgSize,
            /* [in] */ ULONG cTabInitializers,
            /* [size_is][in] */ VSCOMPONENTSELECTORTABINIT rgcstiTabInitializers[  ],
            /* [out][in] */ GUID *pguidStartOnThisTab,
            /* [in] */ LPCOLESTR pszBrowseFilters,
            /* [out][in] */ BSTR *pbstrBrowseLocation) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsComponentSelectorDlg2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsComponentSelectorDlg2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsComponentSelectorDlg2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsComponentSelectorDlg2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *ComponentSelectorDlg2 )( 
            IVsComponentSelectorDlg2 * This,
            /* [in] */ VSCOMPSELFLAGS2 grfFlags,
            /* [in] */ IVsComponentUser *pUser,
            /* [in] */ ULONG cComponents,
            /* [size_is][in] */ PVSCOMPONENTSELECTORDATA rgpcsdComponents[  ],
            /* [in] */ LPCOLESTR lpszDlgTitle,
            /* [in] */ LPCOLESTR lpszHelpTopic,
            /* [out][in] */ ULONG *pxDlgSize,
            /* [out][in] */ ULONG *pyDlgSize,
            /* [in] */ ULONG cTabInitializers,
            /* [size_is][in] */ VSCOMPONENTSELECTORTABINIT rgcstiTabInitializers[  ],
            /* [out][in] */ GUID *pguidStartOnThisTab,
            /* [in] */ LPCOLESTR pszBrowseFilters,
            /* [out][in] */ BSTR *pbstrBrowseLocation);
        
        END_INTERFACE
    } IVsComponentSelectorDlg2Vtbl;

    interface IVsComponentSelectorDlg2
    {
        CONST_VTBL struct IVsComponentSelectorDlg2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsComponentSelectorDlg2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsComponentSelectorDlg2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsComponentSelectorDlg2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsComponentSelectorDlg2_ComponentSelectorDlg2(This,grfFlags,pUser,cComponents,rgpcsdComponents,lpszDlgTitle,lpszHelpTopic,pxDlgSize,pyDlgSize,cTabInitializers,rgcstiTabInitializers,pguidStartOnThisTab,pszBrowseFilters,pbstrBrowseLocation)	\
    (This)->lpVtbl -> ComponentSelectorDlg2(This,grfFlags,pUser,cComponents,rgpcsdComponents,lpszDlgTitle,lpszHelpTopic,pxDlgSize,pyDlgSize,cTabInitializers,rgcstiTabInitializers,pguidStartOnThisTab,pszBrowseFilters,pbstrBrowseLocation)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsComponentSelectorDlg2_ComponentSelectorDlg2_Proxy( 
    IVsComponentSelectorDlg2 * This,
    /* [in] */ VSCOMPSELFLAGS2 grfFlags,
    /* [in] */ IVsComponentUser *pUser,
    /* [in] */ ULONG cComponents,
    /* [size_is][in] */ PVSCOMPONENTSELECTORDATA rgpcsdComponents[  ],
    /* [in] */ LPCOLESTR lpszDlgTitle,
    /* [in] */ LPCOLESTR lpszHelpTopic,
    /* [out][in] */ ULONG *pxDlgSize,
    /* [out][in] */ ULONG *pyDlgSize,
    /* [in] */ ULONG cTabInitializers,
    /* [size_is][in] */ VSCOMPONENTSELECTORTABINIT rgcstiTabInitializers[  ],
    /* [out][in] */ GUID *pguidStartOnThisTab,
    /* [in] */ LPCOLESTR pszBrowseFilters,
    /* [out][in] */ BSTR *pbstrBrowseLocation);


void __RPC_STUB IVsComponentSelectorDlg2_ComponentSelectorDlg2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsComponentSelectorDlg2_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshell80_0744 */
/* [local] */ 

#define SID_SVsComponentSelectorDlg2 IID_IVsComponentSelectorDlg2
DEFINE_GUID(GUID_BrowseFilesPage, 0x2483f435, 0x673d, 0x4fa3, 0x8a, 0xdd, 0xb5, 0x14, 0x42, 0xf6, 0x53, 0x49);
DEFINE_GUID(GUID_MRUPage, 0x19b97f03, 0x9594, 0x4c1c, 0xbe, 0x28, 0x25, 0xff, 0x3, 0x1, 0x13, 0xb3);


extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0744_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0744_v0_0_s_ifspec;

#ifndef __IVsBuildMacroInfo_INTERFACE_DEFINED__
#define __IVsBuildMacroInfo_INTERFACE_DEFINED__

/* interface IVsBuildMacroInfo */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsBuildMacroInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9015B3AB-9FE2-430d-B79F-E0E581BD5B8B")
    IVsBuildMacroInfo : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetBuildMacroValue( 
            /* [in] */ BSTR bstrBuildMacroName,
            /* [out] */ BSTR *pbstrBuildMacroValue) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsBuildMacroInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsBuildMacroInfo * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsBuildMacroInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsBuildMacroInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetBuildMacroValue )( 
            IVsBuildMacroInfo * This,
            /* [in] */ BSTR bstrBuildMacroName,
            /* [out] */ BSTR *pbstrBuildMacroValue);
        
        END_INTERFACE
    } IVsBuildMacroInfoVtbl;

    interface IVsBuildMacroInfo
    {
        CONST_VTBL struct IVsBuildMacroInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsBuildMacroInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsBuildMacroInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsBuildMacroInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsBuildMacroInfo_GetBuildMacroValue(This,bstrBuildMacroName,pbstrBuildMacroValue)	\
    (This)->lpVtbl -> GetBuildMacroValue(This,bstrBuildMacroName,pbstrBuildMacroValue)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsBuildMacroInfo_GetBuildMacroValue_Proxy( 
    IVsBuildMacroInfo * This,
    /* [in] */ BSTR bstrBuildMacroName,
    /* [out] */ BSTR *pbstrBuildMacroValue);


void __RPC_STUB IVsBuildMacroInfo_GetBuildMacroValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsBuildMacroInfo_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshell80_0745 */
/* [local] */ 


enum __PREVIEWCHANGESITEMCHECKSTATE
    {	PCCS_None	= 0,
	PCCS_Unchecked	= 1,
	PCCS_PartiallyChecked	= 2,
	PCCS_Checked	= 3
    } ;
typedef LONG PREVIEWCHANGESITEMCHECKSTATE;


enum __PREVIEWCHANGESITEMDISPLAYSTATE
    {	PCDS_Normal	= 0,
	PCDS_Completed	= PCDS_Normal + 1,
	PCDS_Error	= PCDS_Completed + 1
    } ;
typedef LONG PREVIEWCHANGESITEMDISPLAYSTATE;



extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0745_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0745_v0_0_s_ifspec;

#ifndef __IVsPreviewChangesList_INTERFACE_DEFINED__
#define __IVsPreviewChangesList_INTERFACE_DEFINED__

/* interface IVsPreviewChangesList */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsPreviewChangesList;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B334F714-993B-4902-89E0-792213B538DB")
    IVsPreviewChangesList : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetFlags( 
            /* [out] */ VSTREEFLAGS *pFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetItemCount( 
            /* [out] */ ULONG *pCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetExpandedList( 
            /* [in] */ ULONG Index,
            /* [out] */ BOOL *pfCanRecurse,
            /* [out] */ IVsLiteTreeList **pptlNode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LocateExpandedList( 
            /* [in] */ IVsLiteTreeList *ExpandedList,
            /* [out] */ ULONG *iIndex) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnClose( 
            /* [out] */ VSTREECLOSEACTIONS *ptca) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetText( 
            /* [in] */ ULONG Index,
            /* [in] */ VSTREETEXTOPTIONS tto,
            /* [out] */ const WCHAR **ppszText) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTipText( 
            /* [in] */ ULONG Index,
            /* [in] */ VSTREETOOLTIPTYPE eTipType,
            /* [out] */ const WCHAR **ppszText) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetExpandable( 
            /* [in] */ ULONG Index,
            /* [out] */ BOOL *pfExpandable) = 0;
        
        virtual /* [local] */ HRESULT STDMETHODCALLTYPE GetDisplayData( 
            /* [in] */ ULONG Index,
            /* [out] */ VSTREEDISPLAYDATA *pData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UpdateCounter( 
            /* [out] */ ULONG *pCurUpdate,
            /* [out] */ VSTREEITEMCHANGESMASK *pgrfChanges) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetListChanges( 
            /* [out][in] */ ULONG *pcChanges,
            /* [size_is][in] */ VSTREELISTITEMCHANGE *prgListChanges) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ToggleState( 
            /* [in] */ ULONG Index,
            /* [out] */ VSTREESTATECHANGEREFRESH *ptscr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnRequestSource( 
            /* [in] */ ULONG Index,
            /* [in] */ IUnknown *pIUnknownTextView) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsPreviewChangesListVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsPreviewChangesList * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsPreviewChangesList * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsPreviewChangesList * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetFlags )( 
            IVsPreviewChangesList * This,
            /* [out] */ VSTREEFLAGS *pFlags);
        
        HRESULT ( STDMETHODCALLTYPE *GetItemCount )( 
            IVsPreviewChangesList * This,
            /* [out] */ ULONG *pCount);
        
        HRESULT ( STDMETHODCALLTYPE *GetExpandedList )( 
            IVsPreviewChangesList * This,
            /* [in] */ ULONG Index,
            /* [out] */ BOOL *pfCanRecurse,
            /* [out] */ IVsLiteTreeList **pptlNode);
        
        HRESULT ( STDMETHODCALLTYPE *LocateExpandedList )( 
            IVsPreviewChangesList * This,
            /* [in] */ IVsLiteTreeList *ExpandedList,
            /* [out] */ ULONG *iIndex);
        
        HRESULT ( STDMETHODCALLTYPE *OnClose )( 
            IVsPreviewChangesList * This,
            /* [out] */ VSTREECLOSEACTIONS *ptca);
        
        HRESULT ( STDMETHODCALLTYPE *GetText )( 
            IVsPreviewChangesList * This,
            /* [in] */ ULONG Index,
            /* [in] */ VSTREETEXTOPTIONS tto,
            /* [out] */ const WCHAR **ppszText);
        
        HRESULT ( STDMETHODCALLTYPE *GetTipText )( 
            IVsPreviewChangesList * This,
            /* [in] */ ULONG Index,
            /* [in] */ VSTREETOOLTIPTYPE eTipType,
            /* [out] */ const WCHAR **ppszText);
        
        HRESULT ( STDMETHODCALLTYPE *GetExpandable )( 
            IVsPreviewChangesList * This,
            /* [in] */ ULONG Index,
            /* [out] */ BOOL *pfExpandable);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *GetDisplayData )( 
            IVsPreviewChangesList * This,
            /* [in] */ ULONG Index,
            /* [out] */ VSTREEDISPLAYDATA *pData);
        
        HRESULT ( STDMETHODCALLTYPE *UpdateCounter )( 
            IVsPreviewChangesList * This,
            /* [out] */ ULONG *pCurUpdate,
            /* [out] */ VSTREEITEMCHANGESMASK *pgrfChanges);
        
        HRESULT ( STDMETHODCALLTYPE *GetListChanges )( 
            IVsPreviewChangesList * This,
            /* [out][in] */ ULONG *pcChanges,
            /* [size_is][in] */ VSTREELISTITEMCHANGE *prgListChanges);
        
        HRESULT ( STDMETHODCALLTYPE *ToggleState )( 
            IVsPreviewChangesList * This,
            /* [in] */ ULONG Index,
            /* [out] */ VSTREESTATECHANGEREFRESH *ptscr);
        
        HRESULT ( STDMETHODCALLTYPE *OnRequestSource )( 
            IVsPreviewChangesList * This,
            /* [in] */ ULONG Index,
            /* [in] */ IUnknown *pIUnknownTextView);
        
        END_INTERFACE
    } IVsPreviewChangesListVtbl;

    interface IVsPreviewChangesList
    {
        CONST_VTBL struct IVsPreviewChangesListVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsPreviewChangesList_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsPreviewChangesList_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsPreviewChangesList_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsPreviewChangesList_GetFlags(This,pFlags)	\
    (This)->lpVtbl -> GetFlags(This,pFlags)

#define IVsPreviewChangesList_GetItemCount(This,pCount)	\
    (This)->lpVtbl -> GetItemCount(This,pCount)

#define IVsPreviewChangesList_GetExpandedList(This,Index,pfCanRecurse,pptlNode)	\
    (This)->lpVtbl -> GetExpandedList(This,Index,pfCanRecurse,pptlNode)

#define IVsPreviewChangesList_LocateExpandedList(This,ExpandedList,iIndex)	\
    (This)->lpVtbl -> LocateExpandedList(This,ExpandedList,iIndex)

#define IVsPreviewChangesList_OnClose(This,ptca)	\
    (This)->lpVtbl -> OnClose(This,ptca)

#define IVsPreviewChangesList_GetText(This,Index,tto,ppszText)	\
    (This)->lpVtbl -> GetText(This,Index,tto,ppszText)

#define IVsPreviewChangesList_GetTipText(This,Index,eTipType,ppszText)	\
    (This)->lpVtbl -> GetTipText(This,Index,eTipType,ppszText)

#define IVsPreviewChangesList_GetExpandable(This,Index,pfExpandable)	\
    (This)->lpVtbl -> GetExpandable(This,Index,pfExpandable)

#define IVsPreviewChangesList_GetDisplayData(This,Index,pData)	\
    (This)->lpVtbl -> GetDisplayData(This,Index,pData)

#define IVsPreviewChangesList_UpdateCounter(This,pCurUpdate,pgrfChanges)	\
    (This)->lpVtbl -> UpdateCounter(This,pCurUpdate,pgrfChanges)

#define IVsPreviewChangesList_GetListChanges(This,pcChanges,prgListChanges)	\
    (This)->lpVtbl -> GetListChanges(This,pcChanges,prgListChanges)

#define IVsPreviewChangesList_ToggleState(This,Index,ptscr)	\
    (This)->lpVtbl -> ToggleState(This,Index,ptscr)

#define IVsPreviewChangesList_OnRequestSource(This,Index,pIUnknownTextView)	\
    (This)->lpVtbl -> OnRequestSource(This,Index,pIUnknownTextView)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsPreviewChangesList_GetFlags_Proxy( 
    IVsPreviewChangesList * This,
    /* [out] */ VSTREEFLAGS *pFlags);


void __RPC_STUB IVsPreviewChangesList_GetFlags_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPreviewChangesList_GetItemCount_Proxy( 
    IVsPreviewChangesList * This,
    /* [out] */ ULONG *pCount);


void __RPC_STUB IVsPreviewChangesList_GetItemCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPreviewChangesList_GetExpandedList_Proxy( 
    IVsPreviewChangesList * This,
    /* [in] */ ULONG Index,
    /* [out] */ BOOL *pfCanRecurse,
    /* [out] */ IVsLiteTreeList **pptlNode);


void __RPC_STUB IVsPreviewChangesList_GetExpandedList_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPreviewChangesList_LocateExpandedList_Proxy( 
    IVsPreviewChangesList * This,
    /* [in] */ IVsLiteTreeList *ExpandedList,
    /* [out] */ ULONG *iIndex);


void __RPC_STUB IVsPreviewChangesList_LocateExpandedList_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPreviewChangesList_OnClose_Proxy( 
    IVsPreviewChangesList * This,
    /* [out] */ VSTREECLOSEACTIONS *ptca);


void __RPC_STUB IVsPreviewChangesList_OnClose_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPreviewChangesList_GetText_Proxy( 
    IVsPreviewChangesList * This,
    /* [in] */ ULONG Index,
    /* [in] */ VSTREETEXTOPTIONS tto,
    /* [out] */ const WCHAR **ppszText);


void __RPC_STUB IVsPreviewChangesList_GetText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPreviewChangesList_GetTipText_Proxy( 
    IVsPreviewChangesList * This,
    /* [in] */ ULONG Index,
    /* [in] */ VSTREETOOLTIPTYPE eTipType,
    /* [out] */ const WCHAR **ppszText);


void __RPC_STUB IVsPreviewChangesList_GetTipText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPreviewChangesList_GetExpandable_Proxy( 
    IVsPreviewChangesList * This,
    /* [in] */ ULONG Index,
    /* [out] */ BOOL *pfExpandable);


void __RPC_STUB IVsPreviewChangesList_GetExpandable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [local] */ HRESULT STDMETHODCALLTYPE IVsPreviewChangesList_GetDisplayData_Proxy( 
    IVsPreviewChangesList * This,
    /* [in] */ ULONG Index,
    /* [out] */ VSTREEDISPLAYDATA *pData);


void __RPC_STUB IVsPreviewChangesList_GetDisplayData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPreviewChangesList_UpdateCounter_Proxy( 
    IVsPreviewChangesList * This,
    /* [out] */ ULONG *pCurUpdate,
    /* [out] */ VSTREEITEMCHANGESMASK *pgrfChanges);


void __RPC_STUB IVsPreviewChangesList_UpdateCounter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPreviewChangesList_GetListChanges_Proxy( 
    IVsPreviewChangesList * This,
    /* [out][in] */ ULONG *pcChanges,
    /* [size_is][in] */ VSTREELISTITEMCHANGE *prgListChanges);


void __RPC_STUB IVsPreviewChangesList_GetListChanges_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPreviewChangesList_ToggleState_Proxy( 
    IVsPreviewChangesList * This,
    /* [in] */ ULONG Index,
    /* [out] */ VSTREESTATECHANGEREFRESH *ptscr);


void __RPC_STUB IVsPreviewChangesList_ToggleState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPreviewChangesList_OnRequestSource_Proxy( 
    IVsPreviewChangesList * This,
    /* [in] */ ULONG Index,
    /* [in] */ IUnknown *pIUnknownTextView);


void __RPC_STUB IVsPreviewChangesList_OnRequestSource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsPreviewChangesList_INTERFACE_DEFINED__ */


#ifndef __IVsPreviewChangesEngine_INTERFACE_DEFINED__
#define __IVsPreviewChangesEngine_INTERFACE_DEFINED__

/* interface IVsPreviewChangesEngine */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsPreviewChangesEngine;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6DE3E607-1E2C-4f56-B4A6-BCAF63A0BB9F")
    IVsPreviewChangesEngine : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetTitle( 
            /* [out] */ BSTR *pbstrTitle) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDescription( 
            /* [out] */ BSTR *pbstrDescription) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetConfirmation( 
            /* [out] */ BSTR *pbstrConfirmation) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRootChangesList( 
            /* [out] */ IVsPreviewChangesList **ppIVsPreviewChangesList) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ApplyChanges( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsPreviewChangesEngineVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsPreviewChangesEngine * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsPreviewChangesEngine * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsPreviewChangesEngine * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTitle )( 
            IVsPreviewChangesEngine * This,
            /* [out] */ BSTR *pbstrTitle);
        
        HRESULT ( STDMETHODCALLTYPE *GetDescription )( 
            IVsPreviewChangesEngine * This,
            /* [out] */ BSTR *pbstrDescription);
        
        HRESULT ( STDMETHODCALLTYPE *GetConfirmation )( 
            IVsPreviewChangesEngine * This,
            /* [out] */ BSTR *pbstrConfirmation);
        
        HRESULT ( STDMETHODCALLTYPE *GetRootChangesList )( 
            IVsPreviewChangesEngine * This,
            /* [out] */ IVsPreviewChangesList **ppIVsPreviewChangesList);
        
        HRESULT ( STDMETHODCALLTYPE *ApplyChanges )( 
            IVsPreviewChangesEngine * This);
        
        END_INTERFACE
    } IVsPreviewChangesEngineVtbl;

    interface IVsPreviewChangesEngine
    {
        CONST_VTBL struct IVsPreviewChangesEngineVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsPreviewChangesEngine_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsPreviewChangesEngine_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsPreviewChangesEngine_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsPreviewChangesEngine_GetTitle(This,pbstrTitle)	\
    (This)->lpVtbl -> GetTitle(This,pbstrTitle)

#define IVsPreviewChangesEngine_GetDescription(This,pbstrDescription)	\
    (This)->lpVtbl -> GetDescription(This,pbstrDescription)

#define IVsPreviewChangesEngine_GetConfirmation(This,pbstrConfirmation)	\
    (This)->lpVtbl -> GetConfirmation(This,pbstrConfirmation)

#define IVsPreviewChangesEngine_GetRootChangesList(This,ppIVsPreviewChangesList)	\
    (This)->lpVtbl -> GetRootChangesList(This,ppIVsPreviewChangesList)

#define IVsPreviewChangesEngine_ApplyChanges(This)	\
    (This)->lpVtbl -> ApplyChanges(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsPreviewChangesEngine_GetTitle_Proxy( 
    IVsPreviewChangesEngine * This,
    /* [out] */ BSTR *pbstrTitle);


void __RPC_STUB IVsPreviewChangesEngine_GetTitle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPreviewChangesEngine_GetDescription_Proxy( 
    IVsPreviewChangesEngine * This,
    /* [out] */ BSTR *pbstrDescription);


void __RPC_STUB IVsPreviewChangesEngine_GetDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPreviewChangesEngine_GetConfirmation_Proxy( 
    IVsPreviewChangesEngine * This,
    /* [out] */ BSTR *pbstrConfirmation);


void __RPC_STUB IVsPreviewChangesEngine_GetConfirmation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPreviewChangesEngine_GetRootChangesList_Proxy( 
    IVsPreviewChangesEngine * This,
    /* [out] */ IVsPreviewChangesList **ppIVsPreviewChangesList);


void __RPC_STUB IVsPreviewChangesEngine_GetRootChangesList_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPreviewChangesEngine_ApplyChanges_Proxy( 
    IVsPreviewChangesEngine * This);


void __RPC_STUB IVsPreviewChangesEngine_ApplyChanges_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsPreviewChangesEngine_INTERFACE_DEFINED__ */


#ifndef __IVsPreviewChangesService_INTERFACE_DEFINED__
#define __IVsPreviewChangesService_INTERFACE_DEFINED__

/* interface IVsPreviewChangesService */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsPreviewChangesService;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AF142B19-FB37-40c0-9C28-6617ADBFFAC7")
    IVsPreviewChangesService : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE PreviewChanges( 
            /* [in] */ IVsPreviewChangesEngine *pIVsPreviewChangesEngine) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsPreviewChangesServiceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsPreviewChangesService * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsPreviewChangesService * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsPreviewChangesService * This);
        
        HRESULT ( STDMETHODCALLTYPE *PreviewChanges )( 
            IVsPreviewChangesService * This,
            /* [in] */ IVsPreviewChangesEngine *pIVsPreviewChangesEngine);
        
        END_INTERFACE
    } IVsPreviewChangesServiceVtbl;

    interface IVsPreviewChangesService
    {
        CONST_VTBL struct IVsPreviewChangesServiceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsPreviewChangesService_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsPreviewChangesService_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsPreviewChangesService_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsPreviewChangesService_PreviewChanges(This,pIVsPreviewChangesEngine)	\
    (This)->lpVtbl -> PreviewChanges(This,pIVsPreviewChangesEngine)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsPreviewChangesService_PreviewChanges_Proxy( 
    IVsPreviewChangesService * This,
    /* [in] */ IVsPreviewChangesEngine *pIVsPreviewChangesEngine);


void __RPC_STUB IVsPreviewChangesService_PreviewChanges_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsPreviewChangesService_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshell80_0748 */
/* [local] */ 

#define SID_SVsPreviewChangesService IID_IVsPreviewChangesService

enum __PREVIEWCHANGESPANESTATE
    {	PCPS_Ready	= 0,
	PCPS_NeedsRefresh	= PCPS_Ready + 1,
	PCPS_InProgress	= PCPS_NeedsRefresh + 1,
	PCPS_Failed	= PCPS_InProgress + 1,
	PCPS_Completed	= PCPS_Failed + 1
    } ;
typedef LONG PREVIEWCHANGESPANESTATE;


enum __PREVIEWCHANGESLISTOPTIONS
    {	PCLO_IncludeSymbols	= 0x1,
	PCLO_IncludeStrings	= 0x2,
	PCLO_IncludeComments	= 0x4
    } ;
typedef DWORD PREVIEWCHANGESLISTOPTIONS;

typedef struct __PREVIEWCHANGESPANESTATEINFO
    {
    PREVIEWCHANGESPANESTATE state;
    BSTR bstrMessage;
    } 	PREVIEWCHANGESPANESTATEINFO;



extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0748_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0748_v0_0_s_ifspec;

#ifndef __IVsRefactoringEngine_INTERFACE_DEFINED__
#define __IVsRefactoringEngine_INTERFACE_DEFINED__

/* interface IVsRefactoringEngine */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsRefactoringEngine;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A0393713-61B3-45d6-B411-8F65D1FE32F2")
    IVsRefactoringEngine : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE StartRefactoring( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StopRefactoring( 
            /* [out] */ PREVIEWCHANGESPANESTATEINFO *pStateInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RefreshChangesList( 
            /* [in] */ PREVIEWCHANGESLISTOPTIONS options,
            /* [out] */ IVsPreviewChangesList **ppList,
            /* [out] */ PREVIEWCHANGESPANESTATEINFO *pStateInfo) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsRefactoringEngineVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsRefactoringEngine * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsRefactoringEngine * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsRefactoringEngine * This);
        
        HRESULT ( STDMETHODCALLTYPE *StartRefactoring )( 
            IVsRefactoringEngine * This);
        
        HRESULT ( STDMETHODCALLTYPE *StopRefactoring )( 
            IVsRefactoringEngine * This,
            /* [out] */ PREVIEWCHANGESPANESTATEINFO *pStateInfo);
        
        HRESULT ( STDMETHODCALLTYPE *RefreshChangesList )( 
            IVsRefactoringEngine * This,
            /* [in] */ PREVIEWCHANGESLISTOPTIONS options,
            /* [out] */ IVsPreviewChangesList **ppList,
            /* [out] */ PREVIEWCHANGESPANESTATEINFO *pStateInfo);
        
        END_INTERFACE
    } IVsRefactoringEngineVtbl;

    interface IVsRefactoringEngine
    {
        CONST_VTBL struct IVsRefactoringEngineVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsRefactoringEngine_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsRefactoringEngine_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsRefactoringEngine_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsRefactoringEngine_StartRefactoring(This)	\
    (This)->lpVtbl -> StartRefactoring(This)

#define IVsRefactoringEngine_StopRefactoring(This,pStateInfo)	\
    (This)->lpVtbl -> StopRefactoring(This,pStateInfo)

#define IVsRefactoringEngine_RefreshChangesList(This,options,ppList,pStateInfo)	\
    (This)->lpVtbl -> RefreshChangesList(This,options,ppList,pStateInfo)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsRefactoringEngine_StartRefactoring_Proxy( 
    IVsRefactoringEngine * This);


void __RPC_STUB IVsRefactoringEngine_StartRefactoring_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsRefactoringEngine_StopRefactoring_Proxy( 
    IVsRefactoringEngine * This,
    /* [out] */ PREVIEWCHANGESPANESTATEINFO *pStateInfo);


void __RPC_STUB IVsRefactoringEngine_StopRefactoring_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsRefactoringEngine_RefreshChangesList_Proxy( 
    IVsRefactoringEngine * This,
    /* [in] */ PREVIEWCHANGESLISTOPTIONS options,
    /* [out] */ IVsPreviewChangesList **ppList,
    /* [out] */ PREVIEWCHANGESPANESTATEINFO *pStateInfo);


void __RPC_STUB IVsRefactoringEngine_RefreshChangesList_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsRefactoringEngine_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshell80_0749 */
/* [local] */ 


enum __PREVIEWCHANGESOPTIONSFLAGS
    {	PCOF_StartButton	= 0x1,
	PCOF_StopButton	= 0x2,
	PCOF_RefreshButton	= 0x4,
	PCOF_SearchCommentsButton	= 0x8,
	PCOF_SearchStringsButton	= 0x10,
	PCOF_ProgressBar	= 0x20,
	PCOF_DisableExcluding	= 0x40
    } ;
typedef DWORD PREVIEWCHANGESOPTIONSFLAGS;

typedef struct __PREVIEWCHANGESPANEOPTIONS
    {
    LPCWSTR lpszTitle;
    PREVIEWCHANGESOPTIONSFLAGS flags;
    } 	PREVIEWCHANGESPANEOPTIONS;



extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0749_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0749_v0_0_s_ifspec;

#ifndef __IVsPreviewChangesPane_INTERFACE_DEFINED__
#define __IVsPreviewChangesPane_INTERFACE_DEFINED__

/* interface IVsPreviewChangesPane */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsPreviewChangesPane;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3EB4EDFE-58D2-40b3-A704-1D29C6568252")
    IVsPreviewChangesPane : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetOptions( 
            /* [in] */ PREVIEWCHANGESPANEOPTIONS options) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Initialize( 
            /* [in] */ IVsRefactoringEngine *pRefactoringEngine) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetState( 
            /* [in] */ PREVIEWCHANGESPANESTATEINFO StateInfo) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsPreviewChangesPaneVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsPreviewChangesPane * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsPreviewChangesPane * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsPreviewChangesPane * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetOptions )( 
            IVsPreviewChangesPane * This,
            /* [in] */ PREVIEWCHANGESPANEOPTIONS options);
        
        HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IVsPreviewChangesPane * This,
            /* [in] */ IVsRefactoringEngine *pRefactoringEngine);
        
        HRESULT ( STDMETHODCALLTYPE *SetState )( 
            IVsPreviewChangesPane * This,
            /* [in] */ PREVIEWCHANGESPANESTATEINFO StateInfo);
        
        END_INTERFACE
    } IVsPreviewChangesPaneVtbl;

    interface IVsPreviewChangesPane
    {
        CONST_VTBL struct IVsPreviewChangesPaneVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsPreviewChangesPane_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsPreviewChangesPane_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsPreviewChangesPane_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsPreviewChangesPane_SetOptions(This,options)	\
    (This)->lpVtbl -> SetOptions(This,options)

#define IVsPreviewChangesPane_Initialize(This,pRefactoringEngine)	\
    (This)->lpVtbl -> Initialize(This,pRefactoringEngine)

#define IVsPreviewChangesPane_SetState(This,StateInfo)	\
    (This)->lpVtbl -> SetState(This,StateInfo)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsPreviewChangesPane_SetOptions_Proxy( 
    IVsPreviewChangesPane * This,
    /* [in] */ PREVIEWCHANGESPANEOPTIONS options);


void __RPC_STUB IVsPreviewChangesPane_SetOptions_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPreviewChangesPane_Initialize_Proxy( 
    IVsPreviewChangesPane * This,
    /* [in] */ IVsRefactoringEngine *pRefactoringEngine);


void __RPC_STUB IVsPreviewChangesPane_Initialize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPreviewChangesPane_SetState_Proxy( 
    IVsPreviewChangesPane * This,
    /* [in] */ PREVIEWCHANGESPANESTATEINFO StateInfo);


void __RPC_STUB IVsPreviewChangesPane_SetState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsPreviewChangesPane_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshell80_0750 */
/* [local] */ 

#define SID_SVsPreviewChangesPane IID_IVsPreviewChangesService


extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0750_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0750_v0_0_s_ifspec;

#ifndef __IVsCodeDefViewContext_INTERFACE_DEFINED__
#define __IVsCodeDefViewContext_INTERFACE_DEFINED__

/* interface IVsCodeDefViewContext */
/* [object][local][version][uuid] */ 


EXTERN_C const IID IID_IVsCodeDefViewContext;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E7070F9A-502F-4454-B4A2-FE261C568C37")
    IVsCodeDefViewContext : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetCount( 
            ULONG *pcItems) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSymbolName( 
            ULONG iItem,
            BSTR *pbstrSymbolName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFileName( 
            ULONG iItem,
            BSTR *pbstrFileName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLine( 
            ULONG iItem,
            ULONG *piLine) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCol( 
            ULONG iItem,
            ULONG *piCol) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsCodeDefViewContextVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsCodeDefViewContext * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsCodeDefViewContext * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsCodeDefViewContext * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetCount )( 
            IVsCodeDefViewContext * This,
            ULONG *pcItems);
        
        HRESULT ( STDMETHODCALLTYPE *GetSymbolName )( 
            IVsCodeDefViewContext * This,
            ULONG iItem,
            BSTR *pbstrSymbolName);
        
        HRESULT ( STDMETHODCALLTYPE *GetFileName )( 
            IVsCodeDefViewContext * This,
            ULONG iItem,
            BSTR *pbstrFileName);
        
        HRESULT ( STDMETHODCALLTYPE *GetLine )( 
            IVsCodeDefViewContext * This,
            ULONG iItem,
            ULONG *piLine);
        
        HRESULT ( STDMETHODCALLTYPE *GetCol )( 
            IVsCodeDefViewContext * This,
            ULONG iItem,
            ULONG *piCol);
        
        END_INTERFACE
    } IVsCodeDefViewContextVtbl;

    interface IVsCodeDefViewContext
    {
        CONST_VTBL struct IVsCodeDefViewContextVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsCodeDefViewContext_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsCodeDefViewContext_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsCodeDefViewContext_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsCodeDefViewContext_GetCount(This,pcItems)	\
    (This)->lpVtbl -> GetCount(This,pcItems)

#define IVsCodeDefViewContext_GetSymbolName(This,iItem,pbstrSymbolName)	\
    (This)->lpVtbl -> GetSymbolName(This,iItem,pbstrSymbolName)

#define IVsCodeDefViewContext_GetFileName(This,iItem,pbstrFileName)	\
    (This)->lpVtbl -> GetFileName(This,iItem,pbstrFileName)

#define IVsCodeDefViewContext_GetLine(This,iItem,piLine)	\
    (This)->lpVtbl -> GetLine(This,iItem,piLine)

#define IVsCodeDefViewContext_GetCol(This,iItem,piCol)	\
    (This)->lpVtbl -> GetCol(This,iItem,piCol)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsCodeDefViewContext_GetCount_Proxy( 
    IVsCodeDefViewContext * This,
    ULONG *pcItems);


void __RPC_STUB IVsCodeDefViewContext_GetCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsCodeDefViewContext_GetSymbolName_Proxy( 
    IVsCodeDefViewContext * This,
    ULONG iItem,
    BSTR *pbstrSymbolName);


void __RPC_STUB IVsCodeDefViewContext_GetSymbolName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsCodeDefViewContext_GetFileName_Proxy( 
    IVsCodeDefViewContext * This,
    ULONG iItem,
    BSTR *pbstrFileName);


void __RPC_STUB IVsCodeDefViewContext_GetFileName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsCodeDefViewContext_GetLine_Proxy( 
    IVsCodeDefViewContext * This,
    ULONG iItem,
    ULONG *piLine);


void __RPC_STUB IVsCodeDefViewContext_GetLine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsCodeDefViewContext_GetCol_Proxy( 
    IVsCodeDefViewContext * This,
    ULONG iItem,
    ULONG *piCol);


void __RPC_STUB IVsCodeDefViewContext_GetCol_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsCodeDefViewContext_INTERFACE_DEFINED__ */


#ifndef __IVsCodeDefView_INTERFACE_DEFINED__
#define __IVsCodeDefView_INTERFACE_DEFINED__

/* interface IVsCodeDefView */
/* [object][local][version][uuid] */ 


EXTERN_C const IID IID_IVsCodeDefView;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("588470CC-84F8-4a57-9AC4-86BCA0625FF4")
    IVsCodeDefView : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ShowWindow( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE HideWindow( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsVisible( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetContext( 
            /* [in] */ IVsCodeDefViewContext *pIVsCodeDefViewContext) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRefreshDelay( 
            /* [out] */ ULONG *pcMilliseconds) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ForceIdleProcessing( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsCodeDefViewVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsCodeDefView * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsCodeDefView * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsCodeDefView * This);
        
        HRESULT ( STDMETHODCALLTYPE *ShowWindow )( 
            IVsCodeDefView * This);
        
        HRESULT ( STDMETHODCALLTYPE *HideWindow )( 
            IVsCodeDefView * This);
        
        HRESULT ( STDMETHODCALLTYPE *IsVisible )( 
            IVsCodeDefView * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetContext )( 
            IVsCodeDefView * This,
            /* [in] */ IVsCodeDefViewContext *pIVsCodeDefViewContext);
        
        HRESULT ( STDMETHODCALLTYPE *GetRefreshDelay )( 
            IVsCodeDefView * This,
            /* [out] */ ULONG *pcMilliseconds);
        
        HRESULT ( STDMETHODCALLTYPE *ForceIdleProcessing )( 
            IVsCodeDefView * This);
        
        END_INTERFACE
    } IVsCodeDefViewVtbl;

    interface IVsCodeDefView
    {
        CONST_VTBL struct IVsCodeDefViewVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsCodeDefView_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsCodeDefView_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsCodeDefView_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsCodeDefView_ShowWindow(This)	\
    (This)->lpVtbl -> ShowWindow(This)

#define IVsCodeDefView_HideWindow(This)	\
    (This)->lpVtbl -> HideWindow(This)

#define IVsCodeDefView_IsVisible(This)	\
    (This)->lpVtbl -> IsVisible(This)

#define IVsCodeDefView_SetContext(This,pIVsCodeDefViewContext)	\
    (This)->lpVtbl -> SetContext(This,pIVsCodeDefViewContext)

#define IVsCodeDefView_GetRefreshDelay(This,pcMilliseconds)	\
    (This)->lpVtbl -> GetRefreshDelay(This,pcMilliseconds)

#define IVsCodeDefView_ForceIdleProcessing(This)	\
    (This)->lpVtbl -> ForceIdleProcessing(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsCodeDefView_ShowWindow_Proxy( 
    IVsCodeDefView * This);


void __RPC_STUB IVsCodeDefView_ShowWindow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsCodeDefView_HideWindow_Proxy( 
    IVsCodeDefView * This);


void __RPC_STUB IVsCodeDefView_HideWindow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsCodeDefView_IsVisible_Proxy( 
    IVsCodeDefView * This);


void __RPC_STUB IVsCodeDefView_IsVisible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsCodeDefView_SetContext_Proxy( 
    IVsCodeDefView * This,
    /* [in] */ IVsCodeDefViewContext *pIVsCodeDefViewContext);


void __RPC_STUB IVsCodeDefView_SetContext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsCodeDefView_GetRefreshDelay_Proxy( 
    IVsCodeDefView * This,
    /* [out] */ ULONG *pcMilliseconds);


void __RPC_STUB IVsCodeDefView_GetRefreshDelay_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsCodeDefView_ForceIdleProcessing_Proxy( 
    IVsCodeDefView * This);


void __RPC_STUB IVsCodeDefView_ForceIdleProcessing_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsCodeDefView_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshell80_0752 */
/* [local] */ 

#define SID_SVsCodeDefView IID_IVsCodeDefView

enum __VSRDTSAVEOPTIONS2
    {	RDTSAVEOPT_SkipNewUnsaved	= 0x20,
	RDTSAVEOPT_FSaveAs	= 0x20000000
    } ;
typedef DWORD VSRDTSAVEOPTIONS2;



extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0752_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0752_v0_0_s_ifspec;

#ifndef __IVsRunningDocTableEvents4_INTERFACE_DEFINED__
#define __IVsRunningDocTableEvents4_INTERFACE_DEFINED__

/* interface IVsRunningDocTableEvents4 */
/* [object][version][uuid] */ 


EXTERN_C const IID IID_IVsRunningDocTableEvents4;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("79A342F3-D637-4d54-83DC-DDD511743A49")
    IVsRunningDocTableEvents4 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnBeforeFirstDocumentLock( 
            /* [in] */ IVsHierarchy *pHier,
            /* [in] */ VSITEMID itemid,
            /* [in] */ LPCOLESTR pszMkDocument) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsRunningDocTableEvents4Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsRunningDocTableEvents4 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsRunningDocTableEvents4 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsRunningDocTableEvents4 * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnBeforeFirstDocumentLock )( 
            IVsRunningDocTableEvents4 * This,
            /* [in] */ IVsHierarchy *pHier,
            /* [in] */ VSITEMID itemid,
            /* [in] */ LPCOLESTR pszMkDocument);
        
        END_INTERFACE
    } IVsRunningDocTableEvents4Vtbl;

    interface IVsRunningDocTableEvents4
    {
        CONST_VTBL struct IVsRunningDocTableEvents4Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsRunningDocTableEvents4_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsRunningDocTableEvents4_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsRunningDocTableEvents4_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsRunningDocTableEvents4_OnBeforeFirstDocumentLock(This,pHier,itemid,pszMkDocument)	\
    (This)->lpVtbl -> OnBeforeFirstDocumentLock(This,pHier,itemid,pszMkDocument)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsRunningDocTableEvents4_OnBeforeFirstDocumentLock_Proxy( 
    IVsRunningDocTableEvents4 * This,
    /* [in] */ IVsHierarchy *pHier,
    /* [in] */ VSITEMID itemid,
    /* [in] */ LPCOLESTR pszMkDocument);


void __RPC_STUB IVsRunningDocTableEvents4_OnBeforeFirstDocumentLock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsRunningDocTableEvents4_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshell80_0753 */
/* [local] */ 

extern const __declspec(selectany) GUID UICONTEXT_NotBuildingAndNotDebugging = { 0x48ea4a80, 0xf14e, 0x4107, { 0x88, 0xfa, 0x8d, 0x0, 0x16, 0xf3, 0xb, 0x9c } };
extern const __declspec(selectany) GUID UICONTEXT_SolutionOrProjectUpgrading = { 0xef4f870b, 0x7b85, 0x4f29, { 0x9d, 0x15, 0xce, 0x1a, 0xbf, 0xbe, 0x73, 0x3b } };


extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0753_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0753_v0_0_s_ifspec;

#ifndef __IVsToolboxDataProviderRegistry_INTERFACE_DEFINED__
#define __IVsToolboxDataProviderRegistry_INTERFACE_DEFINED__

/* interface IVsToolboxDataProviderRegistry */
/* [object][version][uuid] */ 


EXTERN_C const IID IID_IVsToolboxDataProviderRegistry;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("653BE2DA-BA98-41b7-8ABC-7A38B0E1C01A")
    IVsToolboxDataProviderRegistry : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE RegisterDataProvider( 
            /* [in] */ IVsToolboxDataProvider *pDP,
            /* [retval][out] */ VSCOOKIE *pdwProvider) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnregisterDataProvider( 
            /* [in] */ VSCOOKIE dwProvider) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsToolboxDataProviderRegistryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsToolboxDataProviderRegistry * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsToolboxDataProviderRegistry * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsToolboxDataProviderRegistry * This);
        
        HRESULT ( STDMETHODCALLTYPE *RegisterDataProvider )( 
            IVsToolboxDataProviderRegistry * This,
            /* [in] */ IVsToolboxDataProvider *pDP,
            /* [retval][out] */ VSCOOKIE *pdwProvider);
        
        HRESULT ( STDMETHODCALLTYPE *UnregisterDataProvider )( 
            IVsToolboxDataProviderRegistry * This,
            /* [in] */ VSCOOKIE dwProvider);
        
        END_INTERFACE
    } IVsToolboxDataProviderRegistryVtbl;

    interface IVsToolboxDataProviderRegistry
    {
        CONST_VTBL struct IVsToolboxDataProviderRegistryVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsToolboxDataProviderRegistry_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsToolboxDataProviderRegistry_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsToolboxDataProviderRegistry_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsToolboxDataProviderRegistry_RegisterDataProvider(This,pDP,pdwProvider)	\
    (This)->lpVtbl -> RegisterDataProvider(This,pDP,pdwProvider)

#define IVsToolboxDataProviderRegistry_UnregisterDataProvider(This,dwProvider)	\
    (This)->lpVtbl -> UnregisterDataProvider(This,dwProvider)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsToolboxDataProviderRegistry_RegisterDataProvider_Proxy( 
    IVsToolboxDataProviderRegistry * This,
    /* [in] */ IVsToolboxDataProvider *pDP,
    /* [retval][out] */ VSCOOKIE *pdwProvider);


void __RPC_STUB IVsToolboxDataProviderRegistry_RegisterDataProvider_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsToolboxDataProviderRegistry_UnregisterDataProvider_Proxy( 
    IVsToolboxDataProviderRegistry * This,
    /* [in] */ VSCOOKIE dwProvider);


void __RPC_STUB IVsToolboxDataProviderRegistry_UnregisterDataProvider_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsToolboxDataProviderRegistry_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshell80_0754 */
/* [local] */ 

#define SID_SVsToolboxDataProviderRegistry IID_IVsToolboxDataProviderRegistry


extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0754_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0754_v0_0_s_ifspec;

#ifndef __IVsFontAndColorCacheManager_INTERFACE_DEFINED__
#define __IVsFontAndColorCacheManager_INTERFACE_DEFINED__

/* interface IVsFontAndColorCacheManager */
/* [object][version][uuid] */ 


EXTERN_C const IID IID_IVsFontAndColorCacheManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("55D3D8C8-F08C-4b31-B70D-FCC52468A5B2")
    IVsFontAndColorCacheManager : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CheckCache( 
            /* [in] */ REFGUID rguidCategory,
            /* [out] */ BOOL *pfHasData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ClearCache( 
            /* [in] */ REFGUID rguidCategory) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RefreshCache( 
            /* [in] */ REFGUID rguidCategory) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CheckCacheable( 
            /* [in] */ REFGUID rguidCategory,
            /* [out] */ BOOL *pfCacheable) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ClearAllCaches( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsFontAndColorCacheManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsFontAndColorCacheManager * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsFontAndColorCacheManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsFontAndColorCacheManager * This);
        
        HRESULT ( STDMETHODCALLTYPE *CheckCache )( 
            IVsFontAndColorCacheManager * This,
            /* [in] */ REFGUID rguidCategory,
            /* [out] */ BOOL *pfHasData);
        
        HRESULT ( STDMETHODCALLTYPE *ClearCache )( 
            IVsFontAndColorCacheManager * This,
            /* [in] */ REFGUID rguidCategory);
        
        HRESULT ( STDMETHODCALLTYPE *RefreshCache )( 
            IVsFontAndColorCacheManager * This,
            /* [in] */ REFGUID rguidCategory);
        
        HRESULT ( STDMETHODCALLTYPE *CheckCacheable )( 
            IVsFontAndColorCacheManager * This,
            /* [in] */ REFGUID rguidCategory,
            /* [out] */ BOOL *pfCacheable);
        
        HRESULT ( STDMETHODCALLTYPE *ClearAllCaches )( 
            IVsFontAndColorCacheManager * This);
        
        END_INTERFACE
    } IVsFontAndColorCacheManagerVtbl;

    interface IVsFontAndColorCacheManager
    {
        CONST_VTBL struct IVsFontAndColorCacheManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsFontAndColorCacheManager_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsFontAndColorCacheManager_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsFontAndColorCacheManager_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsFontAndColorCacheManager_CheckCache(This,rguidCategory,pfHasData)	\
    (This)->lpVtbl -> CheckCache(This,rguidCategory,pfHasData)

#define IVsFontAndColorCacheManager_ClearCache(This,rguidCategory)	\
    (This)->lpVtbl -> ClearCache(This,rguidCategory)

#define IVsFontAndColorCacheManager_RefreshCache(This,rguidCategory)	\
    (This)->lpVtbl -> RefreshCache(This,rguidCategory)

#define IVsFontAndColorCacheManager_CheckCacheable(This,rguidCategory,pfCacheable)	\
    (This)->lpVtbl -> CheckCacheable(This,rguidCategory,pfCacheable)

#define IVsFontAndColorCacheManager_ClearAllCaches(This)	\
    (This)->lpVtbl -> ClearAllCaches(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsFontAndColorCacheManager_CheckCache_Proxy( 
    IVsFontAndColorCacheManager * This,
    /* [in] */ REFGUID rguidCategory,
    /* [out] */ BOOL *pfHasData);


void __RPC_STUB IVsFontAndColorCacheManager_CheckCache_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsFontAndColorCacheManager_ClearCache_Proxy( 
    IVsFontAndColorCacheManager * This,
    /* [in] */ REFGUID rguidCategory);


void __RPC_STUB IVsFontAndColorCacheManager_ClearCache_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsFontAndColorCacheManager_RefreshCache_Proxy( 
    IVsFontAndColorCacheManager * This,
    /* [in] */ REFGUID rguidCategory);


void __RPC_STUB IVsFontAndColorCacheManager_RefreshCache_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsFontAndColorCacheManager_CheckCacheable_Proxy( 
    IVsFontAndColorCacheManager * This,
    /* [in] */ REFGUID rguidCategory,
    /* [out] */ BOOL *pfCacheable);


void __RPC_STUB IVsFontAndColorCacheManager_CheckCacheable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsFontAndColorCacheManager_ClearAllCaches_Proxy( 
    IVsFontAndColorCacheManager * This);


void __RPC_STUB IVsFontAndColorCacheManager_ClearAllCaches_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsFontAndColorCacheManager_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshell80_0755 */
/* [local] */ 

#define SID_SVsFontAndColorCacheManager IID_IVsFontAndColorCacheManager

enum __VSUL_ERRORLEVEL
    {	VSUL_INFORMATIONAL	= 0,
	VSUL_WARNING	= 0x1,
	VSUL_ERROR	= 0x2,
	VSUL_STATUSMSG	= 0x3
    } ;
typedef DWORD VSUL_ERRORLEVEL;



extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0755_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0755_v0_0_s_ifspec;

#ifndef __IVsUpgradeLogger_INTERFACE_DEFINED__
#define __IVsUpgradeLogger_INTERFACE_DEFINED__

/* interface IVsUpgradeLogger */
/* [object][local][version][uuid] */ 


EXTERN_C const IID IID_IVsUpgradeLogger;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AE88C42E-B3D6-4fec-9C63-C9F1B28233EA")
    IVsUpgradeLogger : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE LogMessage( 
            /* [in] */ VSUL_ERRORLEVEL ErrorLevel,
            /* [in] */ BSTR bstrProject,
            /* [in] */ BSTR bstrSource,
            /* [in] */ BSTR bstrDescription) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Flush( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsUpgradeLoggerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsUpgradeLogger * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsUpgradeLogger * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsUpgradeLogger * This);
        
        HRESULT ( STDMETHODCALLTYPE *LogMessage )( 
            IVsUpgradeLogger * This,
            /* [in] */ VSUL_ERRORLEVEL ErrorLevel,
            /* [in] */ BSTR bstrProject,
            /* [in] */ BSTR bstrSource,
            /* [in] */ BSTR bstrDescription);
        
        HRESULT ( STDMETHODCALLTYPE *Flush )( 
            IVsUpgradeLogger * This);
        
        END_INTERFACE
    } IVsUpgradeLoggerVtbl;

    interface IVsUpgradeLogger
    {
        CONST_VTBL struct IVsUpgradeLoggerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsUpgradeLogger_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsUpgradeLogger_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsUpgradeLogger_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsUpgradeLogger_LogMessage(This,ErrorLevel,bstrProject,bstrSource,bstrDescription)	\
    (This)->lpVtbl -> LogMessage(This,ErrorLevel,bstrProject,bstrSource,bstrDescription)

#define IVsUpgradeLogger_Flush(This)	\
    (This)->lpVtbl -> Flush(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsUpgradeLogger_LogMessage_Proxy( 
    IVsUpgradeLogger * This,
    /* [in] */ VSUL_ERRORLEVEL ErrorLevel,
    /* [in] */ BSTR bstrProject,
    /* [in] */ BSTR bstrSource,
    /* [in] */ BSTR bstrDescription);


void __RPC_STUB IVsUpgradeLogger_LogMessage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsUpgradeLogger_Flush_Proxy( 
    IVsUpgradeLogger * This);


void __RPC_STUB IVsUpgradeLogger_Flush_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsUpgradeLogger_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshell80_0756 */
/* [local] */ 

#define SID_IVsUpgradeLogger IID_IVsUpgradeLogger


extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0756_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0756_v0_0_s_ifspec;

#ifndef __IVsFileUpgrade_INTERFACE_DEFINED__
#define __IVsFileUpgrade_INTERFACE_DEFINED__

/* interface IVsFileUpgrade */
/* [object][local][version][uuid] */ 


EXTERN_C const IID IID_IVsFileUpgrade;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5D2D55F2-E545-4301-9C22-52BC694CA76C")
    IVsFileUpgrade : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE UpgradeFile( 
            /* [in] */ BSTR bstrProjectName,
            /* [in] */ BSTR bstrFileName,
            /* [in] */ BOOL bNoBackup,
            /* [in] */ IVsUpgradeLogger *pLogger,
            /* [out] */ BOOL *pUpgradeRequired) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UpgradeFile_CheckOnly( 
            /* [in] */ BSTR bstrProjectName,
            /* [in] */ BSTR bstrFileName,
            /* [in] */ BOOL bNoBackup,
            /* [in] */ IVsUpgradeLogger *pLogger,
            /* [out] */ BOOL *pUpgradeRequired) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsFileUpgradeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsFileUpgrade * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsFileUpgrade * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsFileUpgrade * This);
        
        HRESULT ( STDMETHODCALLTYPE *UpgradeFile )( 
            IVsFileUpgrade * This,
            /* [in] */ BSTR bstrProjectName,
            /* [in] */ BSTR bstrFileName,
            /* [in] */ BOOL bNoBackup,
            /* [in] */ IVsUpgradeLogger *pLogger,
            /* [out] */ BOOL *pUpgradeRequired);
        
        HRESULT ( STDMETHODCALLTYPE *UpgradeFile_CheckOnly )( 
            IVsFileUpgrade * This,
            /* [in] */ BSTR bstrProjectName,
            /* [in] */ BSTR bstrFileName,
            /* [in] */ BOOL bNoBackup,
            /* [in] */ IVsUpgradeLogger *pLogger,
            /* [out] */ BOOL *pUpgradeRequired);
        
        END_INTERFACE
    } IVsFileUpgradeVtbl;

    interface IVsFileUpgrade
    {
        CONST_VTBL struct IVsFileUpgradeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsFileUpgrade_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsFileUpgrade_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsFileUpgrade_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsFileUpgrade_UpgradeFile(This,bstrProjectName,bstrFileName,bNoBackup,pLogger,pUpgradeRequired)	\
    (This)->lpVtbl -> UpgradeFile(This,bstrProjectName,bstrFileName,bNoBackup,pLogger,pUpgradeRequired)

#define IVsFileUpgrade_UpgradeFile_CheckOnly(This,bstrProjectName,bstrFileName,bNoBackup,pLogger,pUpgradeRequired)	\
    (This)->lpVtbl -> UpgradeFile_CheckOnly(This,bstrProjectName,bstrFileName,bNoBackup,pLogger,pUpgradeRequired)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsFileUpgrade_UpgradeFile_Proxy( 
    IVsFileUpgrade * This,
    /* [in] */ BSTR bstrProjectName,
    /* [in] */ BSTR bstrFileName,
    /* [in] */ BOOL bNoBackup,
    /* [in] */ IVsUpgradeLogger *pLogger,
    /* [out] */ BOOL *pUpgradeRequired);


void __RPC_STUB IVsFileUpgrade_UpgradeFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsFileUpgrade_UpgradeFile_CheckOnly_Proxy( 
    IVsFileUpgrade * This,
    /* [in] */ BSTR bstrProjectName,
    /* [in] */ BSTR bstrFileName,
    /* [in] */ BOOL bNoBackup,
    /* [in] */ IVsUpgradeLogger *pLogger,
    /* [out] */ BOOL *pUpgradeRequired);


void __RPC_STUB IVsFileUpgrade_UpgradeFile_CheckOnly_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsFileUpgrade_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshell80_0757 */
/* [local] */ 


enum __VSPPROJECTUPGRADEVIAFACTORYFLAGS
    {	PUVFF_COPYUPGRADE	= 0x10,
	PUVFF_SXSBACKUP	= 0x20,
	PUVFF_COPYBACKUP	= 0x40
    } ;
typedef DWORD VSPUVF_FLAGS;



extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0757_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0757_v0_0_s_ifspec;

#ifndef __IVsProjectUpgradeViaFactory_INTERFACE_DEFINED__
#define __IVsProjectUpgradeViaFactory_INTERFACE_DEFINED__

/* interface IVsProjectUpgradeViaFactory */
/* [object][local][version][uuid] */ 


EXTERN_C const IID IID_IVsProjectUpgradeViaFactory;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0DBA1379-5D67-4a6c-8C06-A5795AF7364B")
    IVsProjectUpgradeViaFactory : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE QueryCapabilities( 
            /* [out] */ VSPUVF_FLAGS *pUpgradeProjectFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UpgradeProject( 
            /* [in] */ BSTR bstrFileName,
            /* [in] */ VSPUVF_FLAGS fUpgradeFlag,
            /* [in] */ BSTR bstrCopyLocation,
            /* [out] */ BSTR *pbstrUpgradedFullyQualifiedFileName,
            /* [in] */ IVsUpgradeLogger *pLogger,
            /* [out] */ BOOL *pUpgradeRequired,
            /* [out] */ GUID *pguidNewProjectFactory) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UpgradeProject_CheckOnly( 
            /* [in] */ BSTR bstrFileName,
            /* [in] */ IVsUpgradeLogger *pLogger,
            /* [out] */ BOOL *pUpgradeRequired) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSccInfo( 
            /* [in] */ BSTR bstrProjectFileName,
            /* [out] */ BSTR *pbstrSccProjectName,
            /* [out] */ BSTR *pbstrSccAuxPath,
            /* [out] */ BSTR *pbstrSccLocalPath,
            /* [out] */ BSTR *pbstrProvider) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsProjectUpgradeViaFactoryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsProjectUpgradeViaFactory * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsProjectUpgradeViaFactory * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsProjectUpgradeViaFactory * This);
        
        HRESULT ( STDMETHODCALLTYPE *QueryCapabilities )( 
            IVsProjectUpgradeViaFactory * This,
            /* [out] */ VSPUVF_FLAGS *pUpgradeProjectFlags);
        
        HRESULT ( STDMETHODCALLTYPE *UpgradeProject )( 
            IVsProjectUpgradeViaFactory * This,
            /* [in] */ BSTR bstrFileName,
            /* [in] */ VSPUVF_FLAGS fUpgradeFlag,
            /* [in] */ BSTR bstrCopyLocation,
            /* [out] */ BSTR *pbstrUpgradedFullyQualifiedFileName,
            /* [in] */ IVsUpgradeLogger *pLogger,
            /* [out] */ BOOL *pUpgradeRequired,
            /* [out] */ GUID *pguidNewProjectFactory);
        
        HRESULT ( STDMETHODCALLTYPE *UpgradeProject_CheckOnly )( 
            IVsProjectUpgradeViaFactory * This,
            /* [in] */ BSTR bstrFileName,
            /* [in] */ IVsUpgradeLogger *pLogger,
            /* [out] */ BOOL *pUpgradeRequired);
        
        HRESULT ( STDMETHODCALLTYPE *GetSccInfo )( 
            IVsProjectUpgradeViaFactory * This,
            /* [in] */ BSTR bstrProjectFileName,
            /* [out] */ BSTR *pbstrSccProjectName,
            /* [out] */ BSTR *pbstrSccAuxPath,
            /* [out] */ BSTR *pbstrSccLocalPath,
            /* [out] */ BSTR *pbstrProvider);
        
        END_INTERFACE
    } IVsProjectUpgradeViaFactoryVtbl;

    interface IVsProjectUpgradeViaFactory
    {
        CONST_VTBL struct IVsProjectUpgradeViaFactoryVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsProjectUpgradeViaFactory_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsProjectUpgradeViaFactory_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsProjectUpgradeViaFactory_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsProjectUpgradeViaFactory_QueryCapabilities(This,pUpgradeProjectFlags)	\
    (This)->lpVtbl -> QueryCapabilities(This,pUpgradeProjectFlags)

#define IVsProjectUpgradeViaFactory_UpgradeProject(This,bstrFileName,fUpgradeFlag,bstrCopyLocation,pbstrUpgradedFullyQualifiedFileName,pLogger,pUpgradeRequired,pguidNewProjectFactory)	\
    (This)->lpVtbl -> UpgradeProject(This,bstrFileName,fUpgradeFlag,bstrCopyLocation,pbstrUpgradedFullyQualifiedFileName,pLogger,pUpgradeRequired,pguidNewProjectFactory)

#define IVsProjectUpgradeViaFactory_UpgradeProject_CheckOnly(This,bstrFileName,pLogger,pUpgradeRequired)	\
    (This)->lpVtbl -> UpgradeProject_CheckOnly(This,bstrFileName,pLogger,pUpgradeRequired)

#define IVsProjectUpgradeViaFactory_GetSccInfo(This,bstrProjectFileName,pbstrSccProjectName,pbstrSccAuxPath,pbstrSccLocalPath,pbstrProvider)	\
    (This)->lpVtbl -> GetSccInfo(This,bstrProjectFileName,pbstrSccProjectName,pbstrSccAuxPath,pbstrSccLocalPath,pbstrProvider)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsProjectUpgradeViaFactory_QueryCapabilities_Proxy( 
    IVsProjectUpgradeViaFactory * This,
    /* [out] */ VSPUVF_FLAGS *pUpgradeProjectFlags);


void __RPC_STUB IVsProjectUpgradeViaFactory_QueryCapabilities_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsProjectUpgradeViaFactory_UpgradeProject_Proxy( 
    IVsProjectUpgradeViaFactory * This,
    /* [in] */ BSTR bstrFileName,
    /* [in] */ VSPUVF_FLAGS fUpgradeFlag,
    /* [in] */ BSTR bstrCopyLocation,
    /* [out] */ BSTR *pbstrUpgradedFullyQualifiedFileName,
    /* [in] */ IVsUpgradeLogger *pLogger,
    /* [out] */ BOOL *pUpgradeRequired,
    /* [out] */ GUID *pguidNewProjectFactory);


void __RPC_STUB IVsProjectUpgradeViaFactory_UpgradeProject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsProjectUpgradeViaFactory_UpgradeProject_CheckOnly_Proxy( 
    IVsProjectUpgradeViaFactory * This,
    /* [in] */ BSTR bstrFileName,
    /* [in] */ IVsUpgradeLogger *pLogger,
    /* [out] */ BOOL *pUpgradeRequired);


void __RPC_STUB IVsProjectUpgradeViaFactory_UpgradeProject_CheckOnly_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsProjectUpgradeViaFactory_GetSccInfo_Proxy( 
    IVsProjectUpgradeViaFactory * This,
    /* [in] */ BSTR bstrProjectFileName,
    /* [out] */ BSTR *pbstrSccProjectName,
    /* [out] */ BSTR *pbstrSccAuxPath,
    /* [out] */ BSTR *pbstrSccLocalPath,
    /* [out] */ BSTR *pbstrProvider);


void __RPC_STUB IVsProjectUpgradeViaFactory_GetSccInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsProjectUpgradeViaFactory_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshell80_0758 */
/* [local] */ 

typedef 
enum __tagACTIVITYLOG_ENTRYTYPE
    {	ALE_ERROR	= 1,
	ALE_WARNING	= 2,
	ALE_INFORMATION	= 3
    } 	ACTIVITYLOG_ENTRYTYPE;



extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0758_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0758_v0_0_s_ifspec;

#ifndef __IVsActivityLog_INTERFACE_DEFINED__
#define __IVsActivityLog_INTERFACE_DEFINED__

/* interface IVsActivityLog */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsActivityLog;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("76AF73F9-A322-42b0-A515-D4D7553508FE")
    IVsActivityLog : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE LogEntry( 
            /* [in] */ ACTIVITYLOG_ENTRYTYPE actType,
            /* [in] */ LPCOLESTR pszSource,
            /* [in] */ LPCOLESTR pszDescription) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LogEntryGuid( 
            /* [in] */ ACTIVITYLOG_ENTRYTYPE actType,
            /* [in] */ LPCOLESTR pszSource,
            /* [in] */ LPCOLESTR pszDescription,
            /* [in] */ GUID guid) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LogEntryHr( 
            /* [in] */ ACTIVITYLOG_ENTRYTYPE actType,
            /* [in] */ LPCOLESTR pszSource,
            /* [in] */ LPCOLESTR pszDescription,
            /* [in] */ HRESULT hr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LogEntryGuidHr( 
            /* [in] */ ACTIVITYLOG_ENTRYTYPE actType,
            /* [in] */ LPCOLESTR pszSource,
            /* [in] */ LPCOLESTR pszDescription,
            /* [in] */ GUID guid,
            /* [in] */ HRESULT hr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LogEntryPath( 
            /* [in] */ ACTIVITYLOG_ENTRYTYPE actType,
            /* [in] */ LPCOLESTR pszSource,
            /* [in] */ LPCOLESTR pszDescription,
            /* [in] */ LPCOLESTR pszPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LogEntryGuidPath( 
            /* [in] */ ACTIVITYLOG_ENTRYTYPE actType,
            /* [in] */ LPCOLESTR pszSource,
            /* [in] */ LPCOLESTR pszDescription,
            /* [in] */ GUID guid,
            /* [in] */ LPCOLESTR pszPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LogEntryHrPath( 
            /* [in] */ ACTIVITYLOG_ENTRYTYPE actType,
            /* [in] */ LPCOLESTR pszSource,
            /* [in] */ LPCOLESTR pszDescription,
            /* [in] */ HRESULT hr,
            /* [in] */ LPCOLESTR pszPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LogEntryGuidHrPath( 
            /* [in] */ ACTIVITYLOG_ENTRYTYPE actType,
            /* [in] */ LPCOLESTR pszSource,
            /* [in] */ LPCOLESTR pszDescription,
            /* [in] */ GUID guid,
            /* [in] */ HRESULT hr,
            /* [in] */ LPCOLESTR pszPath) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsActivityLogVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsActivityLog * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsActivityLog * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsActivityLog * This);
        
        HRESULT ( STDMETHODCALLTYPE *LogEntry )( 
            IVsActivityLog * This,
            /* [in] */ ACTIVITYLOG_ENTRYTYPE actType,
            /* [in] */ LPCOLESTR pszSource,
            /* [in] */ LPCOLESTR pszDescription);
        
        HRESULT ( STDMETHODCALLTYPE *LogEntryGuid )( 
            IVsActivityLog * This,
            /* [in] */ ACTIVITYLOG_ENTRYTYPE actType,
            /* [in] */ LPCOLESTR pszSource,
            /* [in] */ LPCOLESTR pszDescription,
            /* [in] */ GUID guid);
        
        HRESULT ( STDMETHODCALLTYPE *LogEntryHr )( 
            IVsActivityLog * This,
            /* [in] */ ACTIVITYLOG_ENTRYTYPE actType,
            /* [in] */ LPCOLESTR pszSource,
            /* [in] */ LPCOLESTR pszDescription,
            /* [in] */ HRESULT hr);
        
        HRESULT ( STDMETHODCALLTYPE *LogEntryGuidHr )( 
            IVsActivityLog * This,
            /* [in] */ ACTIVITYLOG_ENTRYTYPE actType,
            /* [in] */ LPCOLESTR pszSource,
            /* [in] */ LPCOLESTR pszDescription,
            /* [in] */ GUID guid,
            /* [in] */ HRESULT hr);
        
        HRESULT ( STDMETHODCALLTYPE *LogEntryPath )( 
            IVsActivityLog * This,
            /* [in] */ ACTIVITYLOG_ENTRYTYPE actType,
            /* [in] */ LPCOLESTR pszSource,
            /* [in] */ LPCOLESTR pszDescription,
            /* [in] */ LPCOLESTR pszPath);
        
        HRESULT ( STDMETHODCALLTYPE *LogEntryGuidPath )( 
            IVsActivityLog * This,
            /* [in] */ ACTIVITYLOG_ENTRYTYPE actType,
            /* [in] */ LPCOLESTR pszSource,
            /* [in] */ LPCOLESTR pszDescription,
            /* [in] */ GUID guid,
            /* [in] */ LPCOLESTR pszPath);
        
        HRESULT ( STDMETHODCALLTYPE *LogEntryHrPath )( 
            IVsActivityLog * This,
            /* [in] */ ACTIVITYLOG_ENTRYTYPE actType,
            /* [in] */ LPCOLESTR pszSource,
            /* [in] */ LPCOLESTR pszDescription,
            /* [in] */ HRESULT hr,
            /* [in] */ LPCOLESTR pszPath);
        
        HRESULT ( STDMETHODCALLTYPE *LogEntryGuidHrPath )( 
            IVsActivityLog * This,
            /* [in] */ ACTIVITYLOG_ENTRYTYPE actType,
            /* [in] */ LPCOLESTR pszSource,
            /* [in] */ LPCOLESTR pszDescription,
            /* [in] */ GUID guid,
            /* [in] */ HRESULT hr,
            /* [in] */ LPCOLESTR pszPath);
        
        END_INTERFACE
    } IVsActivityLogVtbl;

    interface IVsActivityLog
    {
        CONST_VTBL struct IVsActivityLogVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsActivityLog_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsActivityLog_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsActivityLog_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsActivityLog_LogEntry(This,actType,pszSource,pszDescription)	\
    (This)->lpVtbl -> LogEntry(This,actType,pszSource,pszDescription)

#define IVsActivityLog_LogEntryGuid(This,actType,pszSource,pszDescription,guid)	\
    (This)->lpVtbl -> LogEntryGuid(This,actType,pszSource,pszDescription,guid)

#define IVsActivityLog_LogEntryHr(This,actType,pszSource,pszDescription,hr)	\
    (This)->lpVtbl -> LogEntryHr(This,actType,pszSource,pszDescription,hr)

#define IVsActivityLog_LogEntryGuidHr(This,actType,pszSource,pszDescription,guid,hr)	\
    (This)->lpVtbl -> LogEntryGuidHr(This,actType,pszSource,pszDescription,guid,hr)

#define IVsActivityLog_LogEntryPath(This,actType,pszSource,pszDescription,pszPath)	\
    (This)->lpVtbl -> LogEntryPath(This,actType,pszSource,pszDescription,pszPath)

#define IVsActivityLog_LogEntryGuidPath(This,actType,pszSource,pszDescription,guid,pszPath)	\
    (This)->lpVtbl -> LogEntryGuidPath(This,actType,pszSource,pszDescription,guid,pszPath)

#define IVsActivityLog_LogEntryHrPath(This,actType,pszSource,pszDescription,hr,pszPath)	\
    (This)->lpVtbl -> LogEntryHrPath(This,actType,pszSource,pszDescription,hr,pszPath)

#define IVsActivityLog_LogEntryGuidHrPath(This,actType,pszSource,pszDescription,guid,hr,pszPath)	\
    (This)->lpVtbl -> LogEntryGuidHrPath(This,actType,pszSource,pszDescription,guid,hr,pszPath)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsActivityLog_LogEntry_Proxy( 
    IVsActivityLog * This,
    /* [in] */ ACTIVITYLOG_ENTRYTYPE actType,
    /* [in] */ LPCOLESTR pszSource,
    /* [in] */ LPCOLESTR pszDescription);


void __RPC_STUB IVsActivityLog_LogEntry_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsActivityLog_LogEntryGuid_Proxy( 
    IVsActivityLog * This,
    /* [in] */ ACTIVITYLOG_ENTRYTYPE actType,
    /* [in] */ LPCOLESTR pszSource,
    /* [in] */ LPCOLESTR pszDescription,
    /* [in] */ GUID guid);


void __RPC_STUB IVsActivityLog_LogEntryGuid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsActivityLog_LogEntryHr_Proxy( 
    IVsActivityLog * This,
    /* [in] */ ACTIVITYLOG_ENTRYTYPE actType,
    /* [in] */ LPCOLESTR pszSource,
    /* [in] */ LPCOLESTR pszDescription,
    /* [in] */ HRESULT hr);


void __RPC_STUB IVsActivityLog_LogEntryHr_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsActivityLog_LogEntryGuidHr_Proxy( 
    IVsActivityLog * This,
    /* [in] */ ACTIVITYLOG_ENTRYTYPE actType,
    /* [in] */ LPCOLESTR pszSource,
    /* [in] */ LPCOLESTR pszDescription,
    /* [in] */ GUID guid,
    /* [in] */ HRESULT hr);


void __RPC_STUB IVsActivityLog_LogEntryGuidHr_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsActivityLog_LogEntryPath_Proxy( 
    IVsActivityLog * This,
    /* [in] */ ACTIVITYLOG_ENTRYTYPE actType,
    /* [in] */ LPCOLESTR pszSource,
    /* [in] */ LPCOLESTR pszDescription,
    /* [in] */ LPCOLESTR pszPath);


void __RPC_STUB IVsActivityLog_LogEntryPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsActivityLog_LogEntryGuidPath_Proxy( 
    IVsActivityLog * This,
    /* [in] */ ACTIVITYLOG_ENTRYTYPE actType,
    /* [in] */ LPCOLESTR pszSource,
    /* [in] */ LPCOLESTR pszDescription,
    /* [in] */ GUID guid,
    /* [in] */ LPCOLESTR pszPath);


void __RPC_STUB IVsActivityLog_LogEntryGuidPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsActivityLog_LogEntryHrPath_Proxy( 
    IVsActivityLog * This,
    /* [in] */ ACTIVITYLOG_ENTRYTYPE actType,
    /* [in] */ LPCOLESTR pszSource,
    /* [in] */ LPCOLESTR pszDescription,
    /* [in] */ HRESULT hr,
    /* [in] */ LPCOLESTR pszPath);


void __RPC_STUB IVsActivityLog_LogEntryHrPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsActivityLog_LogEntryGuidHrPath_Proxy( 
    IVsActivityLog * This,
    /* [in] */ ACTIVITYLOG_ENTRYTYPE actType,
    /* [in] */ LPCOLESTR pszSource,
    /* [in] */ LPCOLESTR pszDescription,
    /* [in] */ GUID guid,
    /* [in] */ HRESULT hr,
    /* [in] */ LPCOLESTR pszPath);


void __RPC_STUB IVsActivityLog_LogEntryGuidHrPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsActivityLog_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshell80_0759 */
/* [local] */ 

#define SID_SVsActivityLog IID_IVsActivityLog


extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0759_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0759_v0_0_s_ifspec;

#ifndef __IVsPersistDocData3_INTERFACE_DEFINED__
#define __IVsPersistDocData3_INTERFACE_DEFINED__

/* interface IVsPersistDocData3 */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsPersistDocData3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DEC057F4-46D1-4BD3-9D63-21E5E3F19368")
    IVsPersistDocData3 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE HandsOffDocDataStorage( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE HandsOnDocDataStorage( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsPersistDocData3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsPersistDocData3 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsPersistDocData3 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsPersistDocData3 * This);
        
        HRESULT ( STDMETHODCALLTYPE *HandsOffDocDataStorage )( 
            IVsPersistDocData3 * This);
        
        HRESULT ( STDMETHODCALLTYPE *HandsOnDocDataStorage )( 
            IVsPersistDocData3 * This);
        
        END_INTERFACE
    } IVsPersistDocData3Vtbl;

    interface IVsPersistDocData3
    {
        CONST_VTBL struct IVsPersistDocData3Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsPersistDocData3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsPersistDocData3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsPersistDocData3_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsPersistDocData3_HandsOffDocDataStorage(This)	\
    (This)->lpVtbl -> HandsOffDocDataStorage(This)

#define IVsPersistDocData3_HandsOnDocDataStorage(This)	\
    (This)->lpVtbl -> HandsOnDocDataStorage(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsPersistDocData3_HandsOffDocDataStorage_Proxy( 
    IVsPersistDocData3 * This);


void __RPC_STUB IVsPersistDocData3_HandsOffDocDataStorage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPersistDocData3_HandsOnDocDataStorage_Proxy( 
    IVsPersistDocData3 * This);


void __RPC_STUB IVsPersistDocData3_HandsOnDocDataStorage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsPersistDocData3_INTERFACE_DEFINED__ */


#ifndef __IVsWindowFrame2_INTERFACE_DEFINED__
#define __IVsWindowFrame2_INTERFACE_DEFINED__

/* interface IVsWindowFrame2 */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsWindowFrame2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("801885A0-9DC6-4e34-B064-1C3228F66794")
    IVsWindowFrame2 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Advise( 
            /* [in] */ IVsWindowFrameNotify *pNotify,
            /* [out] */ VSCOOKIE *pdwCookie) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Unadvise( 
            /* [in] */ VSCOOKIE dwCookie) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsWindowFrame2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsWindowFrame2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsWindowFrame2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsWindowFrame2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *Advise )( 
            IVsWindowFrame2 * This,
            /* [in] */ IVsWindowFrameNotify *pNotify,
            /* [out] */ VSCOOKIE *pdwCookie);
        
        HRESULT ( STDMETHODCALLTYPE *Unadvise )( 
            IVsWindowFrame2 * This,
            /* [in] */ VSCOOKIE dwCookie);
        
        END_INTERFACE
    } IVsWindowFrame2Vtbl;

    interface IVsWindowFrame2
    {
        CONST_VTBL struct IVsWindowFrame2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsWindowFrame2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsWindowFrame2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsWindowFrame2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsWindowFrame2_Advise(This,pNotify,pdwCookie)	\
    (This)->lpVtbl -> Advise(This,pNotify,pdwCookie)

#define IVsWindowFrame2_Unadvise(This,dwCookie)	\
    (This)->lpVtbl -> Unadvise(This,dwCookie)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsWindowFrame2_Advise_Proxy( 
    IVsWindowFrame2 * This,
    /* [in] */ IVsWindowFrameNotify *pNotify,
    /* [out] */ VSCOOKIE *pdwCookie);


void __RPC_STUB IVsWindowFrame2_Advise_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsWindowFrame2_Unadvise_Proxy( 
    IVsWindowFrame2 * This,
    /* [in] */ VSCOOKIE dwCookie);


void __RPC_STUB IVsWindowFrame2_Unadvise_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsWindowFrame2_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshell80_0761 */
/* [local] */ 


enum __VSPPPID
    {	VSPPPID_FIRST	= 1,
	VSPPPID_PAGENAME	= 1,
	VSPPPID_LAST	= 1
    } ;
typedef DWORD VSPPPID;



extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0761_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0761_v0_0_s_ifspec;

#ifndef __IVsPropertyPage2_INTERFACE_DEFINED__
#define __IVsPropertyPage2_INTERFACE_DEFINED__

/* interface IVsPropertyPage2 */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsPropertyPage2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6FC6A958-B2E7-441b-823C-10EA30B24EEC")
    IVsPropertyPage2 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetProperty( 
            /* [in] */ VSPPPID propid,
            /* [out] */ VARIANT *pvar) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetProperty( 
            /* [in] */ VSPPPID propid,
            /* [in] */ VARIANT var) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsPropertyPage2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsPropertyPage2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsPropertyPage2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsPropertyPage2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetProperty )( 
            IVsPropertyPage2 * This,
            /* [in] */ VSPPPID propid,
            /* [out] */ VARIANT *pvar);
        
        HRESULT ( STDMETHODCALLTYPE *SetProperty )( 
            IVsPropertyPage2 * This,
            /* [in] */ VSPPPID propid,
            /* [in] */ VARIANT var);
        
        END_INTERFACE
    } IVsPropertyPage2Vtbl;

    interface IVsPropertyPage2
    {
        CONST_VTBL struct IVsPropertyPage2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsPropertyPage2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsPropertyPage2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsPropertyPage2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsPropertyPage2_GetProperty(This,propid,pvar)	\
    (This)->lpVtbl -> GetProperty(This,propid,pvar)

#define IVsPropertyPage2_SetProperty(This,propid,var)	\
    (This)->lpVtbl -> SetProperty(This,propid,var)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsPropertyPage2_GetProperty_Proxy( 
    IVsPropertyPage2 * This,
    /* [in] */ VSPPPID propid,
    /* [out] */ VARIANT *pvar);


void __RPC_STUB IVsPropertyPage2_GetProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPropertyPage2_SetProperty_Proxy( 
    IVsPropertyPage2 * This,
    /* [in] */ VSPPPID propid,
    /* [in] */ VARIANT var);


void __RPC_STUB IVsPropertyPage2_SetProperty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsPropertyPage2_INTERFACE_DEFINED__ */


#ifndef __IVsWindowFrameNotify3_INTERFACE_DEFINED__
#define __IVsWindowFrameNotify3_INTERFACE_DEFINED__

/* interface IVsWindowFrameNotify3 */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsWindowFrameNotify3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8C213AC2-FF13-4361-9FC5-39D368D26CD3")
    IVsWindowFrameNotify3 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnShow( 
            /* [in] */ FRAMESHOW fShow) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnMove( 
            /* [in] */ int x,
            /* [in] */ int y,
            /* [in] */ int w,
            /* [in] */ int h) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnSize( 
            /* [in] */ int x,
            /* [in] */ int y,
            /* [in] */ int w,
            /* [in] */ int h) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnDockableChange( 
            /* [in] */ BOOL fDockable,
            /* [in] */ int x,
            /* [in] */ int y,
            /* [in] */ int w,
            /* [in] */ int h) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnClose( 
            /* [out][in] */ FRAMECLOSE *pgrfSaveOptions) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsWindowFrameNotify3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsWindowFrameNotify3 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsWindowFrameNotify3 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsWindowFrameNotify3 * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnShow )( 
            IVsWindowFrameNotify3 * This,
            /* [in] */ FRAMESHOW fShow);
        
        HRESULT ( STDMETHODCALLTYPE *OnMove )( 
            IVsWindowFrameNotify3 * This,
            /* [in] */ int x,
            /* [in] */ int y,
            /* [in] */ int w,
            /* [in] */ int h);
        
        HRESULT ( STDMETHODCALLTYPE *OnSize )( 
            IVsWindowFrameNotify3 * This,
            /* [in] */ int x,
            /* [in] */ int y,
            /* [in] */ int w,
            /* [in] */ int h);
        
        HRESULT ( STDMETHODCALLTYPE *OnDockableChange )( 
            IVsWindowFrameNotify3 * This,
            /* [in] */ BOOL fDockable,
            /* [in] */ int x,
            /* [in] */ int y,
            /* [in] */ int w,
            /* [in] */ int h);
        
        HRESULT ( STDMETHODCALLTYPE *OnClose )( 
            IVsWindowFrameNotify3 * This,
            /* [out][in] */ FRAMECLOSE *pgrfSaveOptions);
        
        END_INTERFACE
    } IVsWindowFrameNotify3Vtbl;

    interface IVsWindowFrameNotify3
    {
        CONST_VTBL struct IVsWindowFrameNotify3Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsWindowFrameNotify3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsWindowFrameNotify3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsWindowFrameNotify3_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsWindowFrameNotify3_OnShow(This,fShow)	\
    (This)->lpVtbl -> OnShow(This,fShow)

#define IVsWindowFrameNotify3_OnMove(This,x,y,w,h)	\
    (This)->lpVtbl -> OnMove(This,x,y,w,h)

#define IVsWindowFrameNotify3_OnSize(This,x,y,w,h)	\
    (This)->lpVtbl -> OnSize(This,x,y,w,h)

#define IVsWindowFrameNotify3_OnDockableChange(This,fDockable,x,y,w,h)	\
    (This)->lpVtbl -> OnDockableChange(This,fDockable,x,y,w,h)

#define IVsWindowFrameNotify3_OnClose(This,pgrfSaveOptions)	\
    (This)->lpVtbl -> OnClose(This,pgrfSaveOptions)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsWindowFrameNotify3_OnShow_Proxy( 
    IVsWindowFrameNotify3 * This,
    /* [in] */ FRAMESHOW fShow);


void __RPC_STUB IVsWindowFrameNotify3_OnShow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsWindowFrameNotify3_OnMove_Proxy( 
    IVsWindowFrameNotify3 * This,
    /* [in] */ int x,
    /* [in] */ int y,
    /* [in] */ int w,
    /* [in] */ int h);


void __RPC_STUB IVsWindowFrameNotify3_OnMove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsWindowFrameNotify3_OnSize_Proxy( 
    IVsWindowFrameNotify3 * This,
    /* [in] */ int x,
    /* [in] */ int y,
    /* [in] */ int w,
    /* [in] */ int h);


void __RPC_STUB IVsWindowFrameNotify3_OnSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsWindowFrameNotify3_OnDockableChange_Proxy( 
    IVsWindowFrameNotify3 * This,
    /* [in] */ BOOL fDockable,
    /* [in] */ int x,
    /* [in] */ int y,
    /* [in] */ int w,
    /* [in] */ int h);


void __RPC_STUB IVsWindowFrameNotify3_OnDockableChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsWindowFrameNotify3_OnClose_Proxy( 
    IVsWindowFrameNotify3 * This,
    /* [out][in] */ FRAMECLOSE *pgrfSaveOptions);


void __RPC_STUB IVsWindowFrameNotify3_OnClose_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsWindowFrameNotify3_INTERFACE_DEFINED__ */


#ifndef __IVsContextualIntellisenseFilter_INTERFACE_DEFINED__
#define __IVsContextualIntellisenseFilter_INTERFACE_DEFINED__

/* interface IVsContextualIntellisenseFilter */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsContextualIntellisenseFilter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C0C5974A-288D-4719-AB48-9CB812B5E895")
    IVsContextualIntellisenseFilter : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Initialize( 
            /* [in] */ IVsHierarchy *pHierarchy) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsTypeVisible( 
            /* [in] */ LPCOLESTR szTypeName,
            /* [out] */ BOOL *pfVisible) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsMemberVisible( 
            /* [in] */ LPCOLESTR szMemberSignature,
            /* [out] */ BOOL *pfVisible) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsContextualIntellisenseFilterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsContextualIntellisenseFilter * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsContextualIntellisenseFilter * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsContextualIntellisenseFilter * This);
        
        HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IVsContextualIntellisenseFilter * This,
            /* [in] */ IVsHierarchy *pHierarchy);
        
        HRESULT ( STDMETHODCALLTYPE *IsTypeVisible )( 
            IVsContextualIntellisenseFilter * This,
            /* [in] */ LPCOLESTR szTypeName,
            /* [out] */ BOOL *pfVisible);
        
        HRESULT ( STDMETHODCALLTYPE *IsMemberVisible )( 
            IVsContextualIntellisenseFilter * This,
            /* [in] */ LPCOLESTR szMemberSignature,
            /* [out] */ BOOL *pfVisible);
        
        HRESULT ( STDMETHODCALLTYPE *Close )( 
            IVsContextualIntellisenseFilter * This);
        
        END_INTERFACE
    } IVsContextualIntellisenseFilterVtbl;

    interface IVsContextualIntellisenseFilter
    {
        CONST_VTBL struct IVsContextualIntellisenseFilterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsContextualIntellisenseFilter_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsContextualIntellisenseFilter_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsContextualIntellisenseFilter_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsContextualIntellisenseFilter_Initialize(This,pHierarchy)	\
    (This)->lpVtbl -> Initialize(This,pHierarchy)

#define IVsContextualIntellisenseFilter_IsTypeVisible(This,szTypeName,pfVisible)	\
    (This)->lpVtbl -> IsTypeVisible(This,szTypeName,pfVisible)

#define IVsContextualIntellisenseFilter_IsMemberVisible(This,szMemberSignature,pfVisible)	\
    (This)->lpVtbl -> IsMemberVisible(This,szMemberSignature,pfVisible)

#define IVsContextualIntellisenseFilter_Close(This)	\
    (This)->lpVtbl -> Close(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsContextualIntellisenseFilter_Initialize_Proxy( 
    IVsContextualIntellisenseFilter * This,
    /* [in] */ IVsHierarchy *pHierarchy);


void __RPC_STUB IVsContextualIntellisenseFilter_Initialize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsContextualIntellisenseFilter_IsTypeVisible_Proxy( 
    IVsContextualIntellisenseFilter * This,
    /* [in] */ LPCOLESTR szTypeName,
    /* [out] */ BOOL *pfVisible);


void __RPC_STUB IVsContextualIntellisenseFilter_IsTypeVisible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsContextualIntellisenseFilter_IsMemberVisible_Proxy( 
    IVsContextualIntellisenseFilter * This,
    /* [in] */ LPCOLESTR szMemberSignature,
    /* [out] */ BOOL *pfVisible);


void __RPC_STUB IVsContextualIntellisenseFilter_IsMemberVisible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsContextualIntellisenseFilter_Close_Proxy( 
    IVsContextualIntellisenseFilter * This);


void __RPC_STUB IVsContextualIntellisenseFilter_Close_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsContextualIntellisenseFilter_INTERFACE_DEFINED__ */


#ifndef __IVsContextualIntellisenseFilterProvider_INTERFACE_DEFINED__
#define __IVsContextualIntellisenseFilterProvider_INTERFACE_DEFINED__

/* interface IVsContextualIntellisenseFilterProvider */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsContextualIntellisenseFilterProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F7827DCE-0B39-474d-8D48-FE8100C9044C")
    IVsContextualIntellisenseFilterProvider : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetFilter( 
            /* [in] */ IVsHierarchy *pHierarchy,
            /* [out] */ IVsContextualIntellisenseFilter **ppFilter) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsContextualIntellisenseFilterProviderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsContextualIntellisenseFilterProvider * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsContextualIntellisenseFilterProvider * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsContextualIntellisenseFilterProvider * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetFilter )( 
            IVsContextualIntellisenseFilterProvider * This,
            /* [in] */ IVsHierarchy *pHierarchy,
            /* [out] */ IVsContextualIntellisenseFilter **ppFilter);
        
        END_INTERFACE
    } IVsContextualIntellisenseFilterProviderVtbl;

    interface IVsContextualIntellisenseFilterProvider
    {
        CONST_VTBL struct IVsContextualIntellisenseFilterProviderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsContextualIntellisenseFilterProvider_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsContextualIntellisenseFilterProvider_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsContextualIntellisenseFilterProvider_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsContextualIntellisenseFilterProvider_GetFilter(This,pHierarchy,ppFilter)	\
    (This)->lpVtbl -> GetFilter(This,pHierarchy,ppFilter)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsContextualIntellisenseFilterProvider_GetFilter_Proxy( 
    IVsContextualIntellisenseFilterProvider * This,
    /* [in] */ IVsHierarchy *pHierarchy,
    /* [out] */ IVsContextualIntellisenseFilter **ppFilter);


void __RPC_STUB IVsContextualIntellisenseFilterProvider_GetFilter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsContextualIntellisenseFilterProvider_INTERFACE_DEFINED__ */


#ifndef __IVsToolboxActiveUserHook_INTERFACE_DEFINED__
#define __IVsToolboxActiveUserHook_INTERFACE_DEFINED__

/* interface IVsToolboxActiveUserHook */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsToolboxActiveUserHook;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A00C298A-6520-4822-ABD8-C5CD03846599")
    IVsToolboxActiveUserHook : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE InterceptDataObject( 
            /* [in] */ IDataObject *pIn,
            /* [out] */ IDataObject **ppOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ToolboxSelectionChanged( 
            /* [in] */ IDataObject *pSelected) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsToolboxActiveUserHookVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsToolboxActiveUserHook * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsToolboxActiveUserHook * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsToolboxActiveUserHook * This);
        
        HRESULT ( STDMETHODCALLTYPE *InterceptDataObject )( 
            IVsToolboxActiveUserHook * This,
            /* [in] */ IDataObject *pIn,
            /* [out] */ IDataObject **ppOut);
        
        HRESULT ( STDMETHODCALLTYPE *ToolboxSelectionChanged )( 
            IVsToolboxActiveUserHook * This,
            /* [in] */ IDataObject *pSelected);
        
        END_INTERFACE
    } IVsToolboxActiveUserHookVtbl;

    interface IVsToolboxActiveUserHook
    {
        CONST_VTBL struct IVsToolboxActiveUserHookVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsToolboxActiveUserHook_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsToolboxActiveUserHook_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsToolboxActiveUserHook_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsToolboxActiveUserHook_InterceptDataObject(This,pIn,ppOut)	\
    (This)->lpVtbl -> InterceptDataObject(This,pIn,ppOut)

#define IVsToolboxActiveUserHook_ToolboxSelectionChanged(This,pSelected)	\
    (This)->lpVtbl -> ToolboxSelectionChanged(This,pSelected)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsToolboxActiveUserHook_InterceptDataObject_Proxy( 
    IVsToolboxActiveUserHook * This,
    /* [in] */ IDataObject *pIn,
    /* [out] */ IDataObject **ppOut);


void __RPC_STUB IVsToolboxActiveUserHook_InterceptDataObject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsToolboxActiveUserHook_ToolboxSelectionChanged_Proxy( 
    IVsToolboxActiveUserHook * This,
    /* [in] */ IDataObject *pSelected);


void __RPC_STUB IVsToolboxActiveUserHook_ToolboxSelectionChanged_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsToolboxActiveUserHook_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshell80_0766 */
/* [local] */ 


enum __VSPROFILEPATHRESOLVERFLAGS
    {	VSPPR_None	= 0,
	VSPPR_OnlyForProfiles	= 0x1
    } ;
typedef DWORD VSPROFILEPATHRESOLVERFLAGS;



extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0766_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0766_v0_0_s_ifspec;

#ifndef __IVsPathVariableResolver_INTERFACE_DEFINED__
#define __IVsPathVariableResolver_INTERFACE_DEFINED__

/* interface IVsPathVariableResolver */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsPathVariableResolver;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("17A4EF87-4472-47f6-B066-FE96036678D0")
    IVsPathVariableResolver : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ResolvePath( 
            /* [in] */ LPCOLESTR strEncodedPath,
            /* [in] */ VSPROFILEPATHRESOLVERFLAGS dwFlags,
            /* [out] */ BSTR *pbstrPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EncodePath( 
            /* [in] */ LPCOLESTR strPath,
            /* [in] */ VSPROFILEPATHRESOLVERFLAGS dwFlags,
            /* [out] */ BSTR *pbstrEncodedPath) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsPathVariableResolverVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsPathVariableResolver * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsPathVariableResolver * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsPathVariableResolver * This);
        
        HRESULT ( STDMETHODCALLTYPE *ResolvePath )( 
            IVsPathVariableResolver * This,
            /* [in] */ LPCOLESTR strEncodedPath,
            /* [in] */ VSPROFILEPATHRESOLVERFLAGS dwFlags,
            /* [out] */ BSTR *pbstrPath);
        
        HRESULT ( STDMETHODCALLTYPE *EncodePath )( 
            IVsPathVariableResolver * This,
            /* [in] */ LPCOLESTR strPath,
            /* [in] */ VSPROFILEPATHRESOLVERFLAGS dwFlags,
            /* [out] */ BSTR *pbstrEncodedPath);
        
        END_INTERFACE
    } IVsPathVariableResolverVtbl;

    interface IVsPathVariableResolver
    {
        CONST_VTBL struct IVsPathVariableResolverVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsPathVariableResolver_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsPathVariableResolver_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsPathVariableResolver_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsPathVariableResolver_ResolvePath(This,strEncodedPath,dwFlags,pbstrPath)	\
    (This)->lpVtbl -> ResolvePath(This,strEncodedPath,dwFlags,pbstrPath)

#define IVsPathVariableResolver_EncodePath(This,strPath,dwFlags,pbstrEncodedPath)	\
    (This)->lpVtbl -> EncodePath(This,strPath,dwFlags,pbstrEncodedPath)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsPathVariableResolver_ResolvePath_Proxy( 
    IVsPathVariableResolver * This,
    /* [in] */ LPCOLESTR strEncodedPath,
    /* [in] */ VSPROFILEPATHRESOLVERFLAGS dwFlags,
    /* [out] */ BSTR *pbstrPath);


void __RPC_STUB IVsPathVariableResolver_ResolvePath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPathVariableResolver_EncodePath_Proxy( 
    IVsPathVariableResolver * This,
    /* [in] */ LPCOLESTR strPath,
    /* [in] */ VSPROFILEPATHRESOLVERFLAGS dwFlags,
    /* [out] */ BSTR *pbstrEncodedPath);


void __RPC_STUB IVsPathVariableResolver_EncodePath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsPathVariableResolver_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshell80_0767 */
/* [local] */ 

#define SID_SVsPathVariableResolver IID_IVsPathVariableResolver

enum __VSASYNCHOPENPROJECTTYPE
    {	AOPT_SYNCHRONOUS	= 0,
	AOPT_ASYNCHRONOUS	= 0x1
    } ;
typedef DWORD VSASYNCHOPENPROJECTTYPE;



extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0767_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0767_v0_0_s_ifspec;

#ifndef __IVsProjectFactory2_INTERFACE_DEFINED__
#define __IVsProjectFactory2_INTERFACE_DEFINED__

/* interface IVsProjectFactory2 */
/* [object][version][uuid] */ 


EXTERN_C const IID IID_IVsProjectFactory2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("55E1A1E1-ECAC-46e0-BDE3-1E35BC68C31C")
    IVsProjectFactory2 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetAsynchOpenProjectType( 
            /* [retval][out] */ VSASYNCHOPENPROJECTTYPE *pType) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsProjectFactory2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsProjectFactory2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsProjectFactory2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsProjectFactory2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetAsynchOpenProjectType )( 
            IVsProjectFactory2 * This,
            /* [retval][out] */ VSASYNCHOPENPROJECTTYPE *pType);
        
        END_INTERFACE
    } IVsProjectFactory2Vtbl;

    interface IVsProjectFactory2
    {
        CONST_VTBL struct IVsProjectFactory2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsProjectFactory2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsProjectFactory2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsProjectFactory2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsProjectFactory2_GetAsynchOpenProjectType(This,pType)	\
    (This)->lpVtbl -> GetAsynchOpenProjectType(This,pType)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsProjectFactory2_GetAsynchOpenProjectType_Proxy( 
    IVsProjectFactory2 * This,
    /* [retval][out] */ VSASYNCHOPENPROJECTTYPE *pType);


void __RPC_STUB IVsProjectFactory2_GetAsynchOpenProjectType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsProjectFactory2_INTERFACE_DEFINED__ */


#ifndef __IVsAsynchOpenFromSccProjectEvents_INTERFACE_DEFINED__
#define __IVsAsynchOpenFromSccProjectEvents_INTERFACE_DEFINED__

/* interface IVsAsynchOpenFromSccProjectEvents */
/* [object][version][uuid] */ 


EXTERN_C const IID IID_IVsAsynchOpenFromSccProjectEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C31C30EF-3B22-4f02-93BB-BCDA5FA192AA")
    IVsAsynchOpenFromSccProjectEvents : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnFilesDownloaded( 
            /* [in] */ int cFiles,
            /* [size_is][in] */ const LPCOLESTR rgpszFullPaths[  ]) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnLoadComplete( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsAsynchOpenFromSccProjectEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsAsynchOpenFromSccProjectEvents * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsAsynchOpenFromSccProjectEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsAsynchOpenFromSccProjectEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnFilesDownloaded )( 
            IVsAsynchOpenFromSccProjectEvents * This,
            /* [in] */ int cFiles,
            /* [size_is][in] */ const LPCOLESTR rgpszFullPaths[  ]);
        
        HRESULT ( STDMETHODCALLTYPE *OnLoadComplete )( 
            IVsAsynchOpenFromSccProjectEvents * This);
        
        END_INTERFACE
    } IVsAsynchOpenFromSccProjectEventsVtbl;

    interface IVsAsynchOpenFromSccProjectEvents
    {
        CONST_VTBL struct IVsAsynchOpenFromSccProjectEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsAsynchOpenFromSccProjectEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsAsynchOpenFromSccProjectEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsAsynchOpenFromSccProjectEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsAsynchOpenFromSccProjectEvents_OnFilesDownloaded(This,cFiles,rgpszFullPaths)	\
    (This)->lpVtbl -> OnFilesDownloaded(This,cFiles,rgpszFullPaths)

#define IVsAsynchOpenFromSccProjectEvents_OnLoadComplete(This)	\
    (This)->lpVtbl -> OnLoadComplete(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsAsynchOpenFromSccProjectEvents_OnFilesDownloaded_Proxy( 
    IVsAsynchOpenFromSccProjectEvents * This,
    /* [in] */ int cFiles,
    /* [size_is][in] */ const LPCOLESTR rgpszFullPaths[  ]);


void __RPC_STUB IVsAsynchOpenFromSccProjectEvents_OnFilesDownloaded_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsAsynchOpenFromSccProjectEvents_OnLoadComplete_Proxy( 
    IVsAsynchOpenFromSccProjectEvents * This);


void __RPC_STUB IVsAsynchOpenFromSccProjectEvents_OnLoadComplete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsAsynchOpenFromSccProjectEvents_INTERFACE_DEFINED__ */


#ifndef __IVsAsynchOpenFromScc_INTERFACE_DEFINED__
#define __IVsAsynchOpenFromScc_INTERFACE_DEFINED__

/* interface IVsAsynchOpenFromScc */
/* [object][version][uuid] */ 


EXTERN_C const IID IID_IVsAsynchOpenFromScc;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("99871A31-DB02-4da9-98FB-89D8EDC700CE")
    IVsAsynchOpenFromScc : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE LoadProjectAsynchronously( 
            /* [in] */ LPCOLESTR lpszProjectPath,
            /* [out] */ BOOL *pReturnValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadProject( 
            /* [in] */ LPCOLESTR lpszProjectPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsLoadingContent( 
            /* [in] */ IVsHierarchy *pHierarchy,
            /* [out] */ BOOL *pfIsLoading) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsAsynchOpenFromSccVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsAsynchOpenFromScc * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsAsynchOpenFromScc * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsAsynchOpenFromScc * This);
        
        HRESULT ( STDMETHODCALLTYPE *LoadProjectAsynchronously )( 
            IVsAsynchOpenFromScc * This,
            /* [in] */ LPCOLESTR lpszProjectPath,
            /* [out] */ BOOL *pReturnValue);
        
        HRESULT ( STDMETHODCALLTYPE *LoadProject )( 
            IVsAsynchOpenFromScc * This,
            /* [in] */ LPCOLESTR lpszProjectPath);
        
        HRESULT ( STDMETHODCALLTYPE *IsLoadingContent )( 
            IVsAsynchOpenFromScc * This,
            /* [in] */ IVsHierarchy *pHierarchy,
            /* [out] */ BOOL *pfIsLoading);
        
        END_INTERFACE
    } IVsAsynchOpenFromSccVtbl;

    interface IVsAsynchOpenFromScc
    {
        CONST_VTBL struct IVsAsynchOpenFromSccVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsAsynchOpenFromScc_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsAsynchOpenFromScc_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsAsynchOpenFromScc_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsAsynchOpenFromScc_LoadProjectAsynchronously(This,lpszProjectPath,pReturnValue)	\
    (This)->lpVtbl -> LoadProjectAsynchronously(This,lpszProjectPath,pReturnValue)

#define IVsAsynchOpenFromScc_LoadProject(This,lpszProjectPath)	\
    (This)->lpVtbl -> LoadProject(This,lpszProjectPath)

#define IVsAsynchOpenFromScc_IsLoadingContent(This,pHierarchy,pfIsLoading)	\
    (This)->lpVtbl -> IsLoadingContent(This,pHierarchy,pfIsLoading)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsAsynchOpenFromScc_LoadProjectAsynchronously_Proxy( 
    IVsAsynchOpenFromScc * This,
    /* [in] */ LPCOLESTR lpszProjectPath,
    /* [out] */ BOOL *pReturnValue);


void __RPC_STUB IVsAsynchOpenFromScc_LoadProjectAsynchronously_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsAsynchOpenFromScc_LoadProject_Proxy( 
    IVsAsynchOpenFromScc * This,
    /* [in] */ LPCOLESTR lpszProjectPath);


void __RPC_STUB IVsAsynchOpenFromScc_LoadProject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsAsynchOpenFromScc_IsLoadingContent_Proxy( 
    IVsAsynchOpenFromScc * This,
    /* [in] */ IVsHierarchy *pHierarchy,
    /* [out] */ BOOL *pfIsLoading);


void __RPC_STUB IVsAsynchOpenFromScc_IsLoadingContent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsAsynchOpenFromScc_INTERFACE_DEFINED__ */


#ifndef __IVsHierarchyDeleteHandler2_INTERFACE_DEFINED__
#define __IVsHierarchyDeleteHandler2_INTERFACE_DEFINED__

/* interface IVsHierarchyDeleteHandler2 */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsHierarchyDeleteHandler2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("78FD1CBD-387B-4262-BD7B-65C34F86356E")
    IVsHierarchyDeleteHandler2 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ShowSpecificDeleteRemoveMessage( 
            /* [in] */ DWORD dwDelItemOps,
            /* [in] */ ULONG cDelItems,
            /* [size_is][in] */ VSITEMID rgDelItems[  ],
            /* [out] */ BOOL *pfShowStandardMessage,
            /* [out] */ VSDELETEITEMOPERATION *pdwDelItemOp) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ShowMultiSelDeleteOrRemoveMessage( 
            /* [in] */ VSDELETEITEMOPERATION dwDelItemOp,
            /* [in] */ ULONG cDelItems,
            /* [size_is][in] */ VSITEMID rgDelItems[  ],
            /* [out] */ BOOL *pfCancelOperation) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsHierarchyDeleteHandler2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsHierarchyDeleteHandler2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsHierarchyDeleteHandler2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsHierarchyDeleteHandler2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *ShowSpecificDeleteRemoveMessage )( 
            IVsHierarchyDeleteHandler2 * This,
            /* [in] */ DWORD dwDelItemOps,
            /* [in] */ ULONG cDelItems,
            /* [size_is][in] */ VSITEMID rgDelItems[  ],
            /* [out] */ BOOL *pfShowStandardMessage,
            /* [out] */ VSDELETEITEMOPERATION *pdwDelItemOp);
        
        HRESULT ( STDMETHODCALLTYPE *ShowMultiSelDeleteOrRemoveMessage )( 
            IVsHierarchyDeleteHandler2 * This,
            /* [in] */ VSDELETEITEMOPERATION dwDelItemOp,
            /* [in] */ ULONG cDelItems,
            /* [size_is][in] */ VSITEMID rgDelItems[  ],
            /* [out] */ BOOL *pfCancelOperation);
        
        END_INTERFACE
    } IVsHierarchyDeleteHandler2Vtbl;

    interface IVsHierarchyDeleteHandler2
    {
        CONST_VTBL struct IVsHierarchyDeleteHandler2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsHierarchyDeleteHandler2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsHierarchyDeleteHandler2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsHierarchyDeleteHandler2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsHierarchyDeleteHandler2_ShowSpecificDeleteRemoveMessage(This,dwDelItemOps,cDelItems,rgDelItems,pfShowStandardMessage,pdwDelItemOp)	\
    (This)->lpVtbl -> ShowSpecificDeleteRemoveMessage(This,dwDelItemOps,cDelItems,rgDelItems,pfShowStandardMessage,pdwDelItemOp)

#define IVsHierarchyDeleteHandler2_ShowMultiSelDeleteOrRemoveMessage(This,dwDelItemOp,cDelItems,rgDelItems,pfCancelOperation)	\
    (This)->lpVtbl -> ShowMultiSelDeleteOrRemoveMessage(This,dwDelItemOp,cDelItems,rgDelItems,pfCancelOperation)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsHierarchyDeleteHandler2_ShowSpecificDeleteRemoveMessage_Proxy( 
    IVsHierarchyDeleteHandler2 * This,
    /* [in] */ DWORD dwDelItemOps,
    /* [in] */ ULONG cDelItems,
    /* [size_is][in] */ VSITEMID rgDelItems[  ],
    /* [out] */ BOOL *pfShowStandardMessage,
    /* [out] */ VSDELETEITEMOPERATION *pdwDelItemOp);


void __RPC_STUB IVsHierarchyDeleteHandler2_ShowSpecificDeleteRemoveMessage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsHierarchyDeleteHandler2_ShowMultiSelDeleteOrRemoveMessage_Proxy( 
    IVsHierarchyDeleteHandler2 * This,
    /* [in] */ VSDELETEITEMOPERATION dwDelItemOp,
    /* [in] */ ULONG cDelItems,
    /* [size_is][in] */ VSITEMID rgDelItems[  ],
    /* [out] */ BOOL *pfCancelOperation);


void __RPC_STUB IVsHierarchyDeleteHandler2_ShowMultiSelDeleteOrRemoveMessage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsHierarchyDeleteHandler2_INTERFACE_DEFINED__ */


#ifndef __IVsToolbox3_INTERFACE_DEFINED__
#define __IVsToolbox3_INTERFACE_DEFINED__

/* interface IVsToolbox3 */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsToolbox3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5C67B771-43AD-4bcf-9342-E82CF8E4CBFD")
    IVsToolbox3 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetIDOfTab( 
            /* [in] */ LPCOLESTR lpszTabName,
            /* [in] */ LPCOLESTR lpszTabID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIDOfTab( 
            /* [in] */ LPCOLESTR lpszTabName,
            /* [out] */ BSTR *pbstrTabID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTabOfID( 
            /* [in] */ LPCOLESTR lpszTabID,
            /* [out] */ BSTR *pbstrTabName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLastModifiedTime( 
            /* [out] */ SYSTEMTIME *pst) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsToolbox3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsToolbox3 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsToolbox3 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsToolbox3 * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetIDOfTab )( 
            IVsToolbox3 * This,
            /* [in] */ LPCOLESTR lpszTabName,
            /* [in] */ LPCOLESTR lpszTabID);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDOfTab )( 
            IVsToolbox3 * This,
            /* [in] */ LPCOLESTR lpszTabName,
            /* [out] */ BSTR *pbstrTabID);
        
        HRESULT ( STDMETHODCALLTYPE *GetTabOfID )( 
            IVsToolbox3 * This,
            /* [in] */ LPCOLESTR lpszTabID,
            /* [out] */ BSTR *pbstrTabName);
        
        HRESULT ( STDMETHODCALLTYPE *GetLastModifiedTime )( 
            IVsToolbox3 * This,
            /* [out] */ SYSTEMTIME *pst);
        
        END_INTERFACE
    } IVsToolbox3Vtbl;

    interface IVsToolbox3
    {
        CONST_VTBL struct IVsToolbox3Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsToolbox3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsToolbox3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsToolbox3_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsToolbox3_SetIDOfTab(This,lpszTabName,lpszTabID)	\
    (This)->lpVtbl -> SetIDOfTab(This,lpszTabName,lpszTabID)

#define IVsToolbox3_GetIDOfTab(This,lpszTabName,pbstrTabID)	\
    (This)->lpVtbl -> GetIDOfTab(This,lpszTabName,pbstrTabID)

#define IVsToolbox3_GetTabOfID(This,lpszTabID,pbstrTabName)	\
    (This)->lpVtbl -> GetTabOfID(This,lpszTabID,pbstrTabName)

#define IVsToolbox3_GetLastModifiedTime(This,pst)	\
    (This)->lpVtbl -> GetLastModifiedTime(This,pst)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsToolbox3_SetIDOfTab_Proxy( 
    IVsToolbox3 * This,
    /* [in] */ LPCOLESTR lpszTabName,
    /* [in] */ LPCOLESTR lpszTabID);


void __RPC_STUB IVsToolbox3_SetIDOfTab_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsToolbox3_GetIDOfTab_Proxy( 
    IVsToolbox3 * This,
    /* [in] */ LPCOLESTR lpszTabName,
    /* [out] */ BSTR *pbstrTabID);


void __RPC_STUB IVsToolbox3_GetIDOfTab_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsToolbox3_GetTabOfID_Proxy( 
    IVsToolbox3 * This,
    /* [in] */ LPCOLESTR lpszTabID,
    /* [out] */ BSTR *pbstrTabName);


void __RPC_STUB IVsToolbox3_GetTabOfID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsToolbox3_GetLastModifiedTime_Proxy( 
    IVsToolbox3 * This,
    /* [out] */ SYSTEMTIME *pst);


void __RPC_STUB IVsToolbox3_GetLastModifiedTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsToolbox3_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshell80_0772 */
/* [local] */ 

#define	lpszToolboxTipFieldName	( L"Name" )

#define	lpszToolboxTipFieldVersion	( L"Version" )

#define	lpszToolboxTipFieldCompany	( L"Company" )

#define	lpszToolboxTipFieldComponentType	( L"ComponentType" )

#define	lpszToolboxTipFieldDescription	( L"Description" )



extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0772_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0772_v0_0_s_ifspec;

#ifndef __IVsToolboxDataProvider2_INTERFACE_DEFINED__
#define __IVsToolboxDataProvider2_INTERFACE_DEFINED__

/* interface IVsToolboxDataProvider2 */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsToolboxDataProvider2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1CD73232-A3C7-48fa-8B0A-2E35804097BF")
    IVsToolboxDataProvider2 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetPackageGUID( 
            /* [out] */ GUID *pguidPkg) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUniqueID( 
            /* [out] */ GUID *pguidID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDisplayName( 
            /* [out] */ BSTR *pbstrName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetItemTipInfo( 
            /* [in] */ IDataObject *pDO,
            /* [in] */ LPCOLESTR lpszCurrentName,
            /* [in] */ IPropertyBag *pStrings) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetProfileData( 
            /* [in] */ IDataObject *pDO,
            /* [out] */ BSTR *pbstrData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetItemID( 
            /* [in] */ IDataObject *pDO,
            /* [out] */ BSTR *pbstrID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReconstituteItem( 
            /* [in] */ LPCOLESTR lpszCurrentName,
            /* [in] */ LPCOLESTR lpszID,
            /* [in] */ LPCOLESTR lpszData,
            /* [out] */ IDataObject **ppDO,
            /* [out] */ TBXITEMINFO *ptif) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsToolboxDataProvider2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsToolboxDataProvider2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsToolboxDataProvider2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsToolboxDataProvider2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetPackageGUID )( 
            IVsToolboxDataProvider2 * This,
            /* [out] */ GUID *pguidPkg);
        
        HRESULT ( STDMETHODCALLTYPE *GetUniqueID )( 
            IVsToolboxDataProvider2 * This,
            /* [out] */ GUID *pguidID);
        
        HRESULT ( STDMETHODCALLTYPE *GetDisplayName )( 
            IVsToolboxDataProvider2 * This,
            /* [out] */ BSTR *pbstrName);
        
        HRESULT ( STDMETHODCALLTYPE *GetItemTipInfo )( 
            IVsToolboxDataProvider2 * This,
            /* [in] */ IDataObject *pDO,
            /* [in] */ LPCOLESTR lpszCurrentName,
            /* [in] */ IPropertyBag *pStrings);
        
        HRESULT ( STDMETHODCALLTYPE *GetProfileData )( 
            IVsToolboxDataProvider2 * This,
            /* [in] */ IDataObject *pDO,
            /* [out] */ BSTR *pbstrData);
        
        HRESULT ( STDMETHODCALLTYPE *GetItemID )( 
            IVsToolboxDataProvider2 * This,
            /* [in] */ IDataObject *pDO,
            /* [out] */ BSTR *pbstrID);
        
        HRESULT ( STDMETHODCALLTYPE *ReconstituteItem )( 
            IVsToolboxDataProvider2 * This,
            /* [in] */ LPCOLESTR lpszCurrentName,
            /* [in] */ LPCOLESTR lpszID,
            /* [in] */ LPCOLESTR lpszData,
            /* [out] */ IDataObject **ppDO,
            /* [out] */ TBXITEMINFO *ptif);
        
        END_INTERFACE
    } IVsToolboxDataProvider2Vtbl;

    interface IVsToolboxDataProvider2
    {
        CONST_VTBL struct IVsToolboxDataProvider2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsToolboxDataProvider2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsToolboxDataProvider2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsToolboxDataProvider2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsToolboxDataProvider2_GetPackageGUID(This,pguidPkg)	\
    (This)->lpVtbl -> GetPackageGUID(This,pguidPkg)

#define IVsToolboxDataProvider2_GetUniqueID(This,pguidID)	\
    (This)->lpVtbl -> GetUniqueID(This,pguidID)

#define IVsToolboxDataProvider2_GetDisplayName(This,pbstrName)	\
    (This)->lpVtbl -> GetDisplayName(This,pbstrName)

#define IVsToolboxDataProvider2_GetItemTipInfo(This,pDO,lpszCurrentName,pStrings)	\
    (This)->lpVtbl -> GetItemTipInfo(This,pDO,lpszCurrentName,pStrings)

#define IVsToolboxDataProvider2_GetProfileData(This,pDO,pbstrData)	\
    (This)->lpVtbl -> GetProfileData(This,pDO,pbstrData)

#define IVsToolboxDataProvider2_GetItemID(This,pDO,pbstrID)	\
    (This)->lpVtbl -> GetItemID(This,pDO,pbstrID)

#define IVsToolboxDataProvider2_ReconstituteItem(This,lpszCurrentName,lpszID,lpszData,ppDO,ptif)	\
    (This)->lpVtbl -> ReconstituteItem(This,lpszCurrentName,lpszID,lpszData,ppDO,ptif)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsToolboxDataProvider2_GetPackageGUID_Proxy( 
    IVsToolboxDataProvider2 * This,
    /* [out] */ GUID *pguidPkg);


void __RPC_STUB IVsToolboxDataProvider2_GetPackageGUID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsToolboxDataProvider2_GetUniqueID_Proxy( 
    IVsToolboxDataProvider2 * This,
    /* [out] */ GUID *pguidID);


void __RPC_STUB IVsToolboxDataProvider2_GetUniqueID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsToolboxDataProvider2_GetDisplayName_Proxy( 
    IVsToolboxDataProvider2 * This,
    /* [out] */ BSTR *pbstrName);


void __RPC_STUB IVsToolboxDataProvider2_GetDisplayName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsToolboxDataProvider2_GetItemTipInfo_Proxy( 
    IVsToolboxDataProvider2 * This,
    /* [in] */ IDataObject *pDO,
    /* [in] */ LPCOLESTR lpszCurrentName,
    /* [in] */ IPropertyBag *pStrings);


void __RPC_STUB IVsToolboxDataProvider2_GetItemTipInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsToolboxDataProvider2_GetProfileData_Proxy( 
    IVsToolboxDataProvider2 * This,
    /* [in] */ IDataObject *pDO,
    /* [out] */ BSTR *pbstrData);


void __RPC_STUB IVsToolboxDataProvider2_GetProfileData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsToolboxDataProvider2_GetItemID_Proxy( 
    IVsToolboxDataProvider2 * This,
    /* [in] */ IDataObject *pDO,
    /* [out] */ BSTR *pbstrID);


void __RPC_STUB IVsToolboxDataProvider2_GetItemID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsToolboxDataProvider2_ReconstituteItem_Proxy( 
    IVsToolboxDataProvider2 * This,
    /* [in] */ LPCOLESTR lpszCurrentName,
    /* [in] */ LPCOLESTR lpszID,
    /* [in] */ LPCOLESTR lpszData,
    /* [out] */ IDataObject **ppDO,
    /* [out] */ TBXITEMINFO *ptif);


void __RPC_STUB IVsToolboxDataProvider2_ReconstituteItem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsToolboxDataProvider2_INTERFACE_DEFINED__ */


#ifndef __IVsResourceManager_INTERFACE_DEFINED__
#define __IVsResourceManager_INTERFACE_DEFINED__

/* interface IVsResourceManager */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsResourceManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F0D7A6F0-C722-4AB6-A5D9-C7FF13027410")
    IVsResourceManager : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE LoadResourceString( 
            /* [in] */ REFGUID guidPackage,
            /* [in] */ const WCHAR *pszResourceName,
            /* [retval][out] */ BSTR *pbstrValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadResourceBitmap( 
            /* [in] */ REFGUID guidPackage,
            /* [in] */ const WCHAR *pszResourceName,
            /* [retval][out] */ HBITMAP *hbmpValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadResourceIcon( 
            /* [in] */ REFGUID guidPackage,
            /* [in] */ const WCHAR *pszResourceName,
            /* [retval][out] */ HICON *hicoValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadResourceBlob( 
            /* [in] */ REFGUID guidPackage,
            /* [in] */ const WCHAR *pszResourceName,
            /* [out] */ BYTE **pBytes,
            /* [out] */ long *lAllocated) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadResourceString2( 
            /* [in] */ const WCHAR *pszAssemblyPath,
            /* [in] */ const WCHAR *pszResourceName,
            /* [retval][out] */ BSTR *pbstrValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadResourceBitmap2( 
            /* [in] */ const WCHAR *pszAssemblyPath,
            /* [in] */ const WCHAR *szResourceName,
            /* [retval][out] */ HBITMAP *hbmpValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadResourceIcon2( 
            /* [in] */ const WCHAR *pszAssemblyPath,
            /* [in] */ const WCHAR *pszResourceName,
            /* [retval][out] */ HICON *hicoValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadResourceBlob2( 
            /* [in] */ const WCHAR *pszAssemblyPath,
            /* [in] */ const WCHAR *pszResourceName,
            /* [out] */ BYTE **pBytes,
            /* [out] */ long *lAllocated) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsResourceManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsResourceManager * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsResourceManager * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsResourceManager * This);
        
        HRESULT ( STDMETHODCALLTYPE *LoadResourceString )( 
            IVsResourceManager * This,
            /* [in] */ REFGUID guidPackage,
            /* [in] */ const WCHAR *pszResourceName,
            /* [retval][out] */ BSTR *pbstrValue);
        
        HRESULT ( STDMETHODCALLTYPE *LoadResourceBitmap )( 
            IVsResourceManager * This,
            /* [in] */ REFGUID guidPackage,
            /* [in] */ const WCHAR *pszResourceName,
            /* [retval][out] */ HBITMAP *hbmpValue);
        
        HRESULT ( STDMETHODCALLTYPE *LoadResourceIcon )( 
            IVsResourceManager * This,
            /* [in] */ REFGUID guidPackage,
            /* [in] */ const WCHAR *pszResourceName,
            /* [retval][out] */ HICON *hicoValue);
        
        HRESULT ( STDMETHODCALLTYPE *LoadResourceBlob )( 
            IVsResourceManager * This,
            /* [in] */ REFGUID guidPackage,
            /* [in] */ const WCHAR *pszResourceName,
            /* [out] */ BYTE **pBytes,
            /* [out] */ long *lAllocated);
        
        HRESULT ( STDMETHODCALLTYPE *LoadResourceString2 )( 
            IVsResourceManager * This,
            /* [in] */ const WCHAR *pszAssemblyPath,
            /* [in] */ const WCHAR *pszResourceName,
            /* [retval][out] */ BSTR *pbstrValue);
        
        HRESULT ( STDMETHODCALLTYPE *LoadResourceBitmap2 )( 
            IVsResourceManager * This,
            /* [in] */ const WCHAR *pszAssemblyPath,
            /* [in] */ const WCHAR *szResourceName,
            /* [retval][out] */ HBITMAP *hbmpValue);
        
        HRESULT ( STDMETHODCALLTYPE *LoadResourceIcon2 )( 
            IVsResourceManager * This,
            /* [in] */ const WCHAR *pszAssemblyPath,
            /* [in] */ const WCHAR *pszResourceName,
            /* [retval][out] */ HICON *hicoValue);
        
        HRESULT ( STDMETHODCALLTYPE *LoadResourceBlob2 )( 
            IVsResourceManager * This,
            /* [in] */ const WCHAR *pszAssemblyPath,
            /* [in] */ const WCHAR *pszResourceName,
            /* [out] */ BYTE **pBytes,
            /* [out] */ long *lAllocated);
        
        END_INTERFACE
    } IVsResourceManagerVtbl;

    interface IVsResourceManager
    {
        CONST_VTBL struct IVsResourceManagerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsResourceManager_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsResourceManager_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsResourceManager_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsResourceManager_LoadResourceString(This,guidPackage,pszResourceName,pbstrValue)	\
    (This)->lpVtbl -> LoadResourceString(This,guidPackage,pszResourceName,pbstrValue)

#define IVsResourceManager_LoadResourceBitmap(This,guidPackage,pszResourceName,hbmpValue)	\
    (This)->lpVtbl -> LoadResourceBitmap(This,guidPackage,pszResourceName,hbmpValue)

#define IVsResourceManager_LoadResourceIcon(This,guidPackage,pszResourceName,hicoValue)	\
    (This)->lpVtbl -> LoadResourceIcon(This,guidPackage,pszResourceName,hicoValue)

#define IVsResourceManager_LoadResourceBlob(This,guidPackage,pszResourceName,pBytes,lAllocated)	\
    (This)->lpVtbl -> LoadResourceBlob(This,guidPackage,pszResourceName,pBytes,lAllocated)

#define IVsResourceManager_LoadResourceString2(This,pszAssemblyPath,pszResourceName,pbstrValue)	\
    (This)->lpVtbl -> LoadResourceString2(This,pszAssemblyPath,pszResourceName,pbstrValue)

#define IVsResourceManager_LoadResourceBitmap2(This,pszAssemblyPath,szResourceName,hbmpValue)	\
    (This)->lpVtbl -> LoadResourceBitmap2(This,pszAssemblyPath,szResourceName,hbmpValue)

#define IVsResourceManager_LoadResourceIcon2(This,pszAssemblyPath,pszResourceName,hicoValue)	\
    (This)->lpVtbl -> LoadResourceIcon2(This,pszAssemblyPath,pszResourceName,hicoValue)

#define IVsResourceManager_LoadResourceBlob2(This,pszAssemblyPath,pszResourceName,pBytes,lAllocated)	\
    (This)->lpVtbl -> LoadResourceBlob2(This,pszAssemblyPath,pszResourceName,pBytes,lAllocated)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsResourceManager_LoadResourceString_Proxy( 
    IVsResourceManager * This,
    /* [in] */ REFGUID guidPackage,
    /* [in] */ const WCHAR *pszResourceName,
    /* [retval][out] */ BSTR *pbstrValue);


void __RPC_STUB IVsResourceManager_LoadResourceString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsResourceManager_LoadResourceBitmap_Proxy( 
    IVsResourceManager * This,
    /* [in] */ REFGUID guidPackage,
    /* [in] */ const WCHAR *pszResourceName,
    /* [retval][out] */ HBITMAP *hbmpValue);


void __RPC_STUB IVsResourceManager_LoadResourceBitmap_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsResourceManager_LoadResourceIcon_Proxy( 
    IVsResourceManager * This,
    /* [in] */ REFGUID guidPackage,
    /* [in] */ const WCHAR *pszResourceName,
    /* [retval][out] */ HICON *hicoValue);


void __RPC_STUB IVsResourceManager_LoadResourceIcon_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsResourceManager_LoadResourceBlob_Proxy( 
    IVsResourceManager * This,
    /* [in] */ REFGUID guidPackage,
    /* [in] */ const WCHAR *pszResourceName,
    /* [out] */ BYTE **pBytes,
    /* [out] */ long *lAllocated);


void __RPC_STUB IVsResourceManager_LoadResourceBlob_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsResourceManager_LoadResourceString2_Proxy( 
    IVsResourceManager * This,
    /* [in] */ const WCHAR *pszAssemblyPath,
    /* [in] */ const WCHAR *pszResourceName,
    /* [retval][out] */ BSTR *pbstrValue);


void __RPC_STUB IVsResourceManager_LoadResourceString2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsResourceManager_LoadResourceBitmap2_Proxy( 
    IVsResourceManager * This,
    /* [in] */ const WCHAR *pszAssemblyPath,
    /* [in] */ const WCHAR *szResourceName,
    /* [retval][out] */ HBITMAP *hbmpValue);


void __RPC_STUB IVsResourceManager_LoadResourceBitmap2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsResourceManager_LoadResourceIcon2_Proxy( 
    IVsResourceManager * This,
    /* [in] */ const WCHAR *pszAssemblyPath,
    /* [in] */ const WCHAR *pszResourceName,
    /* [retval][out] */ HICON *hicoValue);


void __RPC_STUB IVsResourceManager_LoadResourceIcon2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsResourceManager_LoadResourceBlob2_Proxy( 
    IVsResourceManager * This,
    /* [in] */ const WCHAR *pszAssemblyPath,
    /* [in] */ const WCHAR *pszResourceName,
    /* [out] */ BYTE **pBytes,
    /* [out] */ long *lAllocated);


void __RPC_STUB IVsResourceManager_LoadResourceBlob2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsResourceManager_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshell80_0774 */
/* [local] */ 

#define SID_SVsResourceManager IID_IVsResourceManager

enum __VSADDNEWWEBITEMOPTIONS
    {	VSADDWEBITEM_SelectMaster	= 0x1,
	VSADDWEBITEM_SeparateCodeFile	= 0x2
    } ;
typedef DWORD VSADDNEWWEBITEMOPTIONS;



extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0774_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0774_v0_0_s_ifspec;

#ifndef __IVsAddNewWebProjectItemDlg_INTERFACE_DEFINED__
#define __IVsAddNewWebProjectItemDlg_INTERFACE_DEFINED__

/* interface IVsAddNewWebProjectItemDlg */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsAddNewWebProjectItemDlg;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("41F92AB8-98B0-4cf4-907B-C5CE4403A570")
    IVsAddNewWebProjectItemDlg : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AddNewWebProjectItemDlg( 
            /* [in] */ VSITEMID itemidLoc,
            /* [in] */ REFGUID rguidProject,
            /* [in] */ IVsProject *pProject,
            /* [in] */ LPCOLESTR pszDlgTitle,
            /* [in] */ LPCOLESTR lpszHelpTopic,
            /* [in] */ LPCOLESTR lpszLanguage,
            /* [in] */ LPCOLESTR lpszSelect,
            /* [in] */ VSADDNEWWEBITEMOPTIONS options) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsAddNewWebProjectItemDlgVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsAddNewWebProjectItemDlg * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsAddNewWebProjectItemDlg * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsAddNewWebProjectItemDlg * This);
        
        HRESULT ( STDMETHODCALLTYPE *AddNewWebProjectItemDlg )( 
            IVsAddNewWebProjectItemDlg * This,
            /* [in] */ VSITEMID itemidLoc,
            /* [in] */ REFGUID rguidProject,
            /* [in] */ IVsProject *pProject,
            /* [in] */ LPCOLESTR pszDlgTitle,
            /* [in] */ LPCOLESTR lpszHelpTopic,
            /* [in] */ LPCOLESTR lpszLanguage,
            /* [in] */ LPCOLESTR lpszSelect,
            /* [in] */ VSADDNEWWEBITEMOPTIONS options);
        
        END_INTERFACE
    } IVsAddNewWebProjectItemDlgVtbl;

    interface IVsAddNewWebProjectItemDlg
    {
        CONST_VTBL struct IVsAddNewWebProjectItemDlgVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsAddNewWebProjectItemDlg_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsAddNewWebProjectItemDlg_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsAddNewWebProjectItemDlg_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsAddNewWebProjectItemDlg_AddNewWebProjectItemDlg(This,itemidLoc,rguidProject,pProject,pszDlgTitle,lpszHelpTopic,lpszLanguage,lpszSelect,options)	\
    (This)->lpVtbl -> AddNewWebProjectItemDlg(This,itemidLoc,rguidProject,pProject,pszDlgTitle,lpszHelpTopic,lpszLanguage,lpszSelect,options)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsAddNewWebProjectItemDlg_AddNewWebProjectItemDlg_Proxy( 
    IVsAddNewWebProjectItemDlg * This,
    /* [in] */ VSITEMID itemidLoc,
    /* [in] */ REFGUID rguidProject,
    /* [in] */ IVsProject *pProject,
    /* [in] */ LPCOLESTR pszDlgTitle,
    /* [in] */ LPCOLESTR lpszHelpTopic,
    /* [in] */ LPCOLESTR lpszLanguage,
    /* [in] */ LPCOLESTR lpszSelect,
    /* [in] */ VSADDNEWWEBITEMOPTIONS options);


void __RPC_STUB IVsAddNewWebProjectItemDlg_AddNewWebProjectItemDlg_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsAddNewWebProjectItemDlg_INTERFACE_DEFINED__ */


#ifndef __IVsWebProject_INTERFACE_DEFINED__
#define __IVsWebProject_INTERFACE_DEFINED__

/* interface IVsWebProject */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsWebProject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0BD8000A-F537-4889-9FBC-C5F63B313956")
    IVsWebProject : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AddNewWebItem( 
            /* [in] */ VSITEMID itemidLoc,
            /* [in] */ VSADDITEMOPERATION dwAddItemOperation,
            /* [in] */ LPCOLESTR pszItemName,
            /* [in] */ LPCOLESTR pszFileTemplate,
            /* [in] */ VSADDNEWWEBITEMOPTIONS options,
            /* [in] */ LPCOLESTR pszSelectedLanguage,
            /* [in] */ HWND hwndDlgOwner,
            /* [retval][out] */ VSADDRESULT *pResult) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsWebProjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsWebProject * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsWebProject * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsWebProject * This);
        
        HRESULT ( STDMETHODCALLTYPE *AddNewWebItem )( 
            IVsWebProject * This,
            /* [in] */ VSITEMID itemidLoc,
            /* [in] */ VSADDITEMOPERATION dwAddItemOperation,
            /* [in] */ LPCOLESTR pszItemName,
            /* [in] */ LPCOLESTR pszFileTemplate,
            /* [in] */ VSADDNEWWEBITEMOPTIONS options,
            /* [in] */ LPCOLESTR pszSelectedLanguage,
            /* [in] */ HWND hwndDlgOwner,
            /* [retval][out] */ VSADDRESULT *pResult);
        
        END_INTERFACE
    } IVsWebProjectVtbl;

    interface IVsWebProject
    {
        CONST_VTBL struct IVsWebProjectVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsWebProject_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsWebProject_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsWebProject_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsWebProject_AddNewWebItem(This,itemidLoc,dwAddItemOperation,pszItemName,pszFileTemplate,options,pszSelectedLanguage,hwndDlgOwner,pResult)	\
    (This)->lpVtbl -> AddNewWebItem(This,itemidLoc,dwAddItemOperation,pszItemName,pszFileTemplate,options,pszSelectedLanguage,hwndDlgOwner,pResult)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsWebProject_AddNewWebItem_Proxy( 
    IVsWebProject * This,
    /* [in] */ VSITEMID itemidLoc,
    /* [in] */ VSADDITEMOPERATION dwAddItemOperation,
    /* [in] */ LPCOLESTR pszItemName,
    /* [in] */ LPCOLESTR pszFileTemplate,
    /* [in] */ VSADDNEWWEBITEMOPTIONS options,
    /* [in] */ LPCOLESTR pszSelectedLanguage,
    /* [in] */ HWND hwndDlgOwner,
    /* [retval][out] */ VSADDRESULT *pResult);


void __RPC_STUB IVsWebProject_AddNewWebItem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsWebProject_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshell80_0776 */
/* [local] */ 


enum __VSHIERITEMATTRIBUTE
    {	VSHIERITEMATTRIBUTE_Bold	= 1
    } ;
typedef DWORD VSHIERITEMATTRIBUTE;



extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0776_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0776_v0_0_s_ifspec;

#ifndef __IVsUIHierarchyWindow2_INTERFACE_DEFINED__
#define __IVsUIHierarchyWindow2_INTERFACE_DEFINED__

/* interface IVsUIHierarchyWindow2 */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsUIHierarchyWindow2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5B8C06A0-4379-4218-A046-B1DC466E5818")
    IVsUIHierarchyWindow2 : public IVsUIHierarchyWindow
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetItemAttribute( 
            /* [in] */ IVsUIHierarchy *pUIH,
            /* [in] */ VSITEMID itemid,
            /* [in] */ VSHIERITEMATTRIBUTE attribute,
            /* [in] */ VARIANT value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsUIHierarchyWindow2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsUIHierarchyWindow2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsUIHierarchyWindow2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsUIHierarchyWindow2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *Init )( 
            IVsUIHierarchyWindow2 * This,
            /* [in] */ IVsUIHierarchy *pUIH,
            /* [in] */ UIHWINFLAGS grfUIHWF,
            /* [out] */ IUnknown **ppunkOut);
        
        HRESULT ( STDMETHODCALLTYPE *ExpandItem )( 
            IVsUIHierarchyWindow2 * This,
            /* [in] */ IVsUIHierarchy *pUIH,
            /* [in] */ VSITEMID itemid,
            /* [in] */ EXPANDFLAGS expf);
        
        HRESULT ( STDMETHODCALLTYPE *AddUIHierarchy )( 
            IVsUIHierarchyWindow2 * This,
            /* [in] */ IVsUIHierarchy *pUIH,
            /* [in] */ VSADDHIEROPTIONS grfAddOptions);
        
        HRESULT ( STDMETHODCALLTYPE *RemoveUIHierarchy )( 
            IVsUIHierarchyWindow2 * This,
            /* [in] */ IVsUIHierarchy *pUIH);
        
        HRESULT ( STDMETHODCALLTYPE *SetWindowHelpTopic )( 
            IVsUIHierarchyWindow2 * This,
            /* [in] */ LPCOLESTR lpszHelpFile,
            /* [in] */ DWORD dwContext);
        
        HRESULT ( STDMETHODCALLTYPE *GetItemState )( 
            IVsUIHierarchyWindow2 * This,
            /* [in] */ IVsUIHierarchy *pHier,
            /* [in] */ VSITEMID itemid,
            /* [in] */ VSHIERARCHYITEMSTATE dwStateMask,
            /* [retval][out] */ VSHIERARCHYITEMSTATE *pdwState);
        
        HRESULT ( STDMETHODCALLTYPE *FindCommonSelectedHierarchy )( 
            IVsUIHierarchyWindow2 * This,
            /* [in] */ VSCOMHIEROPTIONS grfOpt,
            /* [retval][out] */ IVsUIHierarchy **lppCommonUIH);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *SetCursor )( 
            IVsUIHierarchyWindow2 * This,
            /* [in] */ HCURSOR hNewCursor,
            /* [retval][out] */ HCURSOR *phOldCursor);
        
        HRESULT ( STDMETHODCALLTYPE *GetCurrentSelection )( 
            IVsUIHierarchyWindow2 * This,
            /* [out] */ IVsHierarchy **ppHier,
            /* [out] */ VSITEMID *pitemid,
            /* [out] */ IVsMultiItemSelect **ppMIS);
        
        HRESULT ( STDMETHODCALLTYPE *SetItemAttribute )( 
            IVsUIHierarchyWindow2 * This,
            /* [in] */ IVsUIHierarchy *pUIH,
            /* [in] */ VSITEMID itemid,
            /* [in] */ VSHIERITEMATTRIBUTE attribute,
            /* [in] */ VARIANT value);
        
        END_INTERFACE
    } IVsUIHierarchyWindow2Vtbl;

    interface IVsUIHierarchyWindow2
    {
        CONST_VTBL struct IVsUIHierarchyWindow2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsUIHierarchyWindow2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsUIHierarchyWindow2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsUIHierarchyWindow2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsUIHierarchyWindow2_Init(This,pUIH,grfUIHWF,ppunkOut)	\
    (This)->lpVtbl -> Init(This,pUIH,grfUIHWF,ppunkOut)

#define IVsUIHierarchyWindow2_ExpandItem(This,pUIH,itemid,expf)	\
    (This)->lpVtbl -> ExpandItem(This,pUIH,itemid,expf)

#define IVsUIHierarchyWindow2_AddUIHierarchy(This,pUIH,grfAddOptions)	\
    (This)->lpVtbl -> AddUIHierarchy(This,pUIH,grfAddOptions)

#define IVsUIHierarchyWindow2_RemoveUIHierarchy(This,pUIH)	\
    (This)->lpVtbl -> RemoveUIHierarchy(This,pUIH)

#define IVsUIHierarchyWindow2_SetWindowHelpTopic(This,lpszHelpFile,dwContext)	\
    (This)->lpVtbl -> SetWindowHelpTopic(This,lpszHelpFile,dwContext)

#define IVsUIHierarchyWindow2_GetItemState(This,pHier,itemid,dwStateMask,pdwState)	\
    (This)->lpVtbl -> GetItemState(This,pHier,itemid,dwStateMask,pdwState)

#define IVsUIHierarchyWindow2_FindCommonSelectedHierarchy(This,grfOpt,lppCommonUIH)	\
    (This)->lpVtbl -> FindCommonSelectedHierarchy(This,grfOpt,lppCommonUIH)

#define IVsUIHierarchyWindow2_SetCursor(This,hNewCursor,phOldCursor)	\
    (This)->lpVtbl -> SetCursor(This,hNewCursor,phOldCursor)

#define IVsUIHierarchyWindow2_GetCurrentSelection(This,ppHier,pitemid,ppMIS)	\
    (This)->lpVtbl -> GetCurrentSelection(This,ppHier,pitemid,ppMIS)


#define IVsUIHierarchyWindow2_SetItemAttribute(This,pUIH,itemid,attribute,value)	\
    (This)->lpVtbl -> SetItemAttribute(This,pUIH,itemid,attribute,value)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsUIHierarchyWindow2_SetItemAttribute_Proxy( 
    IVsUIHierarchyWindow2 * This,
    /* [in] */ IVsUIHierarchy *pUIH,
    /* [in] */ VSITEMID itemid,
    /* [in] */ VSHIERITEMATTRIBUTE attribute,
    /* [in] */ VARIANT value);


void __RPC_STUB IVsUIHierarchyWindow2_SetItemAttribute_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsUIHierarchyWindow2_INTERFACE_DEFINED__ */


#ifndef __IVsSupportYukonDebugging_INTERFACE_DEFINED__
#define __IVsSupportYukonDebugging_INTERFACE_DEFINED__

/* interface IVsSupportYukonDebugging */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsSupportYukonDebugging;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8E40D748-F682-4951-B465-16D0C252A69D")
    IVsSupportYukonDebugging : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetProjectSqlConection( 
            /* [out] */ IUnknown **pConnection) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsSupportYukonDebuggingVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsSupportYukonDebugging * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsSupportYukonDebugging * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsSupportYukonDebugging * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetProjectSqlConection )( 
            IVsSupportYukonDebugging * This,
            /* [out] */ IUnknown **pConnection);
        
        END_INTERFACE
    } IVsSupportYukonDebuggingVtbl;

    interface IVsSupportYukonDebugging
    {
        CONST_VTBL struct IVsSupportYukonDebuggingVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsSupportYukonDebugging_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsSupportYukonDebugging_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsSupportYukonDebugging_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsSupportYukonDebugging_GetProjectSqlConection(This,pConnection)	\
    (This)->lpVtbl -> GetProjectSqlConection(This,pConnection)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsSupportYukonDebugging_GetProjectSqlConection_Proxy( 
    IVsSupportYukonDebugging * This,
    /* [out] */ IUnknown **pConnection);


void __RPC_STUB IVsSupportYukonDebugging_GetProjectSqlConection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsSupportYukonDebugging_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshell80_0778 */
/* [local] */ 



typedef 
enum __tagVSTASKLISTSELECTIONSCROLLPOS
    {	TSSP_NOSCROLL	= 0,
	TSSP_CENTERCARET	= 1,
	TSSP_CARETATTOP	= 2,
	TSSP_CARETATBOTTOM	= 3,
	TSSP_MINSCROLL	= 4,
	TSSP_SHOWALL	= 5
    } 	VSTASKLISTSELECTIONSCROLLPOS;

typedef 
enum __tagVSTASKLISTSELECTIONTYPE
    {	TST_REPLACESEL	= 0,
	TST_EXTENDSEL	= 1,
	TST_ADDTOSEL	= 2
    } 	VSTASKLISTSELECTIONTYPE;



extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0778_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0778_v0_0_s_ifspec;

#ifndef __IVsTaskList2_INTERFACE_DEFINED__
#define __IVsTaskList2_INTERFACE_DEFINED__

/* interface IVsTaskList2 */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsTaskList2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("62357211-57FD-4425-A9E5-9A6E0D3B731C")
    IVsTaskList2 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetSelectionCount( 
            /* [out] */ int *pnItems) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCaretPos( 
            /* [out] */ IVsTaskItem **ppItem) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumSelectedItems( 
            /* [out] */ IVsEnumTaskItems **ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SelectItems( 
            /* [in] */ int nItems,
            /* [size_is][in] */ IVsTaskItem *pItems[  ],
            /* [in] */ VSTASKLISTSELECTIONTYPE tsfSelType,
            /* [in] */ VSTASKLISTSELECTIONSCROLLPOS tsspScrollPos) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BeginTaskEdit( 
            /* [in] */ IVsTaskItem *pItem,
            /* [in] */ int iFocusField) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetActiveProvider( 
            /* [out] */ IVsTaskProvider **ppProvider) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetActiveProvider( 
            /* [in] */ REFGUID rguidProvider) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RefreshOrAddTasks( 
            /* [in] */ VSCOOKIE vsProviderCookie,
            /* [in] */ int nTasks,
            /* [size_is][in] */ IVsTaskItem *prgTasks[  ]) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveTasks( 
            /* [in] */ VSCOOKIE vsProviderCookie,
            /* [in] */ int nTasks,
            /* [size_is][in] */ IVsTaskItem *prgTasks[  ]) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsTaskList2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsTaskList2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsTaskList2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsTaskList2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetSelectionCount )( 
            IVsTaskList2 * This,
            /* [out] */ int *pnItems);
        
        HRESULT ( STDMETHODCALLTYPE *GetCaretPos )( 
            IVsTaskList2 * This,
            /* [out] */ IVsTaskItem **ppItem);
        
        HRESULT ( STDMETHODCALLTYPE *EnumSelectedItems )( 
            IVsTaskList2 * This,
            /* [out] */ IVsEnumTaskItems **ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE *SelectItems )( 
            IVsTaskList2 * This,
            /* [in] */ int nItems,
            /* [size_is][in] */ IVsTaskItem *pItems[  ],
            /* [in] */ VSTASKLISTSELECTIONTYPE tsfSelType,
            /* [in] */ VSTASKLISTSELECTIONSCROLLPOS tsspScrollPos);
        
        HRESULT ( STDMETHODCALLTYPE *BeginTaskEdit )( 
            IVsTaskList2 * This,
            /* [in] */ IVsTaskItem *pItem,
            /* [in] */ int iFocusField);
        
        HRESULT ( STDMETHODCALLTYPE *GetActiveProvider )( 
            IVsTaskList2 * This,
            /* [out] */ IVsTaskProvider **ppProvider);
        
        HRESULT ( STDMETHODCALLTYPE *SetActiveProvider )( 
            IVsTaskList2 * This,
            /* [in] */ REFGUID rguidProvider);
        
        HRESULT ( STDMETHODCALLTYPE *RefreshOrAddTasks )( 
            IVsTaskList2 * This,
            /* [in] */ VSCOOKIE vsProviderCookie,
            /* [in] */ int nTasks,
            /* [size_is][in] */ IVsTaskItem *prgTasks[  ]);
        
        HRESULT ( STDMETHODCALLTYPE *RemoveTasks )( 
            IVsTaskList2 * This,
            /* [in] */ VSCOOKIE vsProviderCookie,
            /* [in] */ int nTasks,
            /* [size_is][in] */ IVsTaskItem *prgTasks[  ]);
        
        END_INTERFACE
    } IVsTaskList2Vtbl;

    interface IVsTaskList2
    {
        CONST_VTBL struct IVsTaskList2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsTaskList2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsTaskList2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsTaskList2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsTaskList2_GetSelectionCount(This,pnItems)	\
    (This)->lpVtbl -> GetSelectionCount(This,pnItems)

#define IVsTaskList2_GetCaretPos(This,ppItem)	\
    (This)->lpVtbl -> GetCaretPos(This,ppItem)

#define IVsTaskList2_EnumSelectedItems(This,ppEnum)	\
    (This)->lpVtbl -> EnumSelectedItems(This,ppEnum)

#define IVsTaskList2_SelectItems(This,nItems,pItems,tsfSelType,tsspScrollPos)	\
    (This)->lpVtbl -> SelectItems(This,nItems,pItems,tsfSelType,tsspScrollPos)

#define IVsTaskList2_BeginTaskEdit(This,pItem,iFocusField)	\
    (This)->lpVtbl -> BeginTaskEdit(This,pItem,iFocusField)

#define IVsTaskList2_GetActiveProvider(This,ppProvider)	\
    (This)->lpVtbl -> GetActiveProvider(This,ppProvider)

#define IVsTaskList2_SetActiveProvider(This,rguidProvider)	\
    (This)->lpVtbl -> SetActiveProvider(This,rguidProvider)

#define IVsTaskList2_RefreshOrAddTasks(This,vsProviderCookie,nTasks,prgTasks)	\
    (This)->lpVtbl -> RefreshOrAddTasks(This,vsProviderCookie,nTasks,prgTasks)

#define IVsTaskList2_RemoveTasks(This,vsProviderCookie,nTasks,prgTasks)	\
    (This)->lpVtbl -> RemoveTasks(This,vsProviderCookie,nTasks,prgTasks)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsTaskList2_GetSelectionCount_Proxy( 
    IVsTaskList2 * This,
    /* [out] */ int *pnItems);


void __RPC_STUB IVsTaskList2_GetSelectionCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTaskList2_GetCaretPos_Proxy( 
    IVsTaskList2 * This,
    /* [out] */ IVsTaskItem **ppItem);


void __RPC_STUB IVsTaskList2_GetCaretPos_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTaskList2_EnumSelectedItems_Proxy( 
    IVsTaskList2 * This,
    /* [out] */ IVsEnumTaskItems **ppEnum);


void __RPC_STUB IVsTaskList2_EnumSelectedItems_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTaskList2_SelectItems_Proxy( 
    IVsTaskList2 * This,
    /* [in] */ int nItems,
    /* [size_is][in] */ IVsTaskItem *pItems[  ],
    /* [in] */ VSTASKLISTSELECTIONTYPE tsfSelType,
    /* [in] */ VSTASKLISTSELECTIONSCROLLPOS tsspScrollPos);


void __RPC_STUB IVsTaskList2_SelectItems_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTaskList2_BeginTaskEdit_Proxy( 
    IVsTaskList2 * This,
    /* [in] */ IVsTaskItem *pItem,
    /* [in] */ int iFocusField);


void __RPC_STUB IVsTaskList2_BeginTaskEdit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTaskList2_GetActiveProvider_Proxy( 
    IVsTaskList2 * This,
    /* [out] */ IVsTaskProvider **ppProvider);


void __RPC_STUB IVsTaskList2_GetActiveProvider_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTaskList2_SetActiveProvider_Proxy( 
    IVsTaskList2 * This,
    /* [in] */ REFGUID rguidProvider);


void __RPC_STUB IVsTaskList2_SetActiveProvider_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTaskList2_RefreshOrAddTasks_Proxy( 
    IVsTaskList2 * This,
    /* [in] */ VSCOOKIE vsProviderCookie,
    /* [in] */ int nTasks,
    /* [size_is][in] */ IVsTaskItem *prgTasks[  ]);


void __RPC_STUB IVsTaskList2_RefreshOrAddTasks_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTaskList2_RemoveTasks_Proxy( 
    IVsTaskList2 * This,
    /* [in] */ VSCOOKIE vsProviderCookie,
    /* [in] */ int nTasks,
    /* [size_is][in] */ IVsTaskItem *prgTasks[  ]);


void __RPC_STUB IVsTaskList2_RemoveTasks_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsTaskList2_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshell80_0779 */
/* [local] */ 

typedef struct _VSTASKCOLUMN
    {
    int iField;
    BSTR bstrHeading;
    int iImage;
    BOOL fShowSortArrow;
    BOOL fAllowUserSort;
    BOOL fVisibleByDefault;
    BOOL fAllowHide;
    BOOL fSizeable;
    BOOL fMoveable;
    int iDefaultSortPriority;
    BOOL fDescendingSort;
    int cxMinWidth;
    int cxDefaultWidth;
    BOOL fDynamicSize;
    BSTR bstrCanonicalName;
    BSTR bstrLocalizedName;
    BSTR bstrTip;
    BOOL fFitContent;
    } 	VSTASKCOLUMN;


enum __VSTASKPROVIDERFLAGS
    {	TPF_ALWAYSVISIBLE	= 0x1,
	TPF_NOAUTOROUTING	= 0x2
    } ;
typedef DWORD VSTASKPROVIDERFLAGS;



extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0779_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0779_v0_0_s_ifspec;

#ifndef __IVsTaskProvider3_INTERFACE_DEFINED__
#define __IVsTaskProvider3_INTERFACE_DEFINED__

/* interface IVsTaskProvider3 */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsTaskProvider3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AFA6B21D-D599-43f9-A3AB-0840359F11C3")
    IVsTaskProvider3 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetProviderFlags( 
            /* [out] */ VSTASKPROVIDERFLAGS *tpfFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetProviderName( 
            /* [out] */ BSTR *pbstrName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetProviderGuid( 
            /* [out] */ GUID *pguidProvider) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSurrogateProviderGuid( 
            /* [out] */ GUID *pguidProvider) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetProviderToolbar( 
            /* [out] */ GUID *pguidGroup,
            /* [out] */ DWORD *pdwID) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetColumnCount( 
            /* [out] */ int *pnColumns) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetColumn( 
            /* [in] */ int iColumn,
            /* [out] */ VSTASKCOLUMN *pColumn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnBeginTaskEdit( 
            /* [in] */ IVsTaskItem *pItem) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnEndTaskEdit( 
            /* [in] */ IVsTaskItem *pItem,
            /* [in] */ BOOL fCommitChanges,
            /* [out] */ BOOL *pfAllowChanges) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsTaskProvider3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsTaskProvider3 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsTaskProvider3 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsTaskProvider3 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetProviderFlags )( 
            IVsTaskProvider3 * This,
            /* [out] */ VSTASKPROVIDERFLAGS *tpfFlags);
        
        HRESULT ( STDMETHODCALLTYPE *GetProviderName )( 
            IVsTaskProvider3 * This,
            /* [out] */ BSTR *pbstrName);
        
        HRESULT ( STDMETHODCALLTYPE *GetProviderGuid )( 
            IVsTaskProvider3 * This,
            /* [out] */ GUID *pguidProvider);
        
        HRESULT ( STDMETHODCALLTYPE *GetSurrogateProviderGuid )( 
            IVsTaskProvider3 * This,
            /* [out] */ GUID *pguidProvider);
        
        HRESULT ( STDMETHODCALLTYPE *GetProviderToolbar )( 
            IVsTaskProvider3 * This,
            /* [out] */ GUID *pguidGroup,
            /* [out] */ DWORD *pdwID);
        
        HRESULT ( STDMETHODCALLTYPE *GetColumnCount )( 
            IVsTaskProvider3 * This,
            /* [out] */ int *pnColumns);
        
        HRESULT ( STDMETHODCALLTYPE *GetColumn )( 
            IVsTaskProvider3 * This,
            /* [in] */ int iColumn,
            /* [out] */ VSTASKCOLUMN *pColumn);
        
        HRESULT ( STDMETHODCALLTYPE *OnBeginTaskEdit )( 
            IVsTaskProvider3 * This,
            /* [in] */ IVsTaskItem *pItem);
        
        HRESULT ( STDMETHODCALLTYPE *OnEndTaskEdit )( 
            IVsTaskProvider3 * This,
            /* [in] */ IVsTaskItem *pItem,
            /* [in] */ BOOL fCommitChanges,
            /* [out] */ BOOL *pfAllowChanges);
        
        END_INTERFACE
    } IVsTaskProvider3Vtbl;

    interface IVsTaskProvider3
    {
        CONST_VTBL struct IVsTaskProvider3Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsTaskProvider3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsTaskProvider3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsTaskProvider3_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsTaskProvider3_GetProviderFlags(This,tpfFlags)	\
    (This)->lpVtbl -> GetProviderFlags(This,tpfFlags)

#define IVsTaskProvider3_GetProviderName(This,pbstrName)	\
    (This)->lpVtbl -> GetProviderName(This,pbstrName)

#define IVsTaskProvider3_GetProviderGuid(This,pguidProvider)	\
    (This)->lpVtbl -> GetProviderGuid(This,pguidProvider)

#define IVsTaskProvider3_GetSurrogateProviderGuid(This,pguidProvider)	\
    (This)->lpVtbl -> GetSurrogateProviderGuid(This,pguidProvider)

#define IVsTaskProvider3_GetProviderToolbar(This,pguidGroup,pdwID)	\
    (This)->lpVtbl -> GetProviderToolbar(This,pguidGroup,pdwID)

#define IVsTaskProvider3_GetColumnCount(This,pnColumns)	\
    (This)->lpVtbl -> GetColumnCount(This,pnColumns)

#define IVsTaskProvider3_GetColumn(This,iColumn,pColumn)	\
    (This)->lpVtbl -> GetColumn(This,iColumn,pColumn)

#define IVsTaskProvider3_OnBeginTaskEdit(This,pItem)	\
    (This)->lpVtbl -> OnBeginTaskEdit(This,pItem)

#define IVsTaskProvider3_OnEndTaskEdit(This,pItem,fCommitChanges,pfAllowChanges)	\
    (This)->lpVtbl -> OnEndTaskEdit(This,pItem,fCommitChanges,pfAllowChanges)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsTaskProvider3_GetProviderFlags_Proxy( 
    IVsTaskProvider3 * This,
    /* [out] */ VSTASKPROVIDERFLAGS *tpfFlags);


void __RPC_STUB IVsTaskProvider3_GetProviderFlags_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTaskProvider3_GetProviderName_Proxy( 
    IVsTaskProvider3 * This,
    /* [out] */ BSTR *pbstrName);


void __RPC_STUB IVsTaskProvider3_GetProviderName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTaskProvider3_GetProviderGuid_Proxy( 
    IVsTaskProvider3 * This,
    /* [out] */ GUID *pguidProvider);


void __RPC_STUB IVsTaskProvider3_GetProviderGuid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTaskProvider3_GetSurrogateProviderGuid_Proxy( 
    IVsTaskProvider3 * This,
    /* [out] */ GUID *pguidProvider);


void __RPC_STUB IVsTaskProvider3_GetSurrogateProviderGuid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTaskProvider3_GetProviderToolbar_Proxy( 
    IVsTaskProvider3 * This,
    /* [out] */ GUID *pguidGroup,
    /* [out] */ DWORD *pdwID);


void __RPC_STUB IVsTaskProvider3_GetProviderToolbar_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTaskProvider3_GetColumnCount_Proxy( 
    IVsTaskProvider3 * This,
    /* [out] */ int *pnColumns);


void __RPC_STUB IVsTaskProvider3_GetColumnCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTaskProvider3_GetColumn_Proxy( 
    IVsTaskProvider3 * This,
    /* [in] */ int iColumn,
    /* [out] */ VSTASKCOLUMN *pColumn);


void __RPC_STUB IVsTaskProvider3_GetColumn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTaskProvider3_OnBeginTaskEdit_Proxy( 
    IVsTaskProvider3 * This,
    /* [in] */ IVsTaskItem *pItem);


void __RPC_STUB IVsTaskProvider3_OnBeginTaskEdit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTaskProvider3_OnEndTaskEdit_Proxy( 
    IVsTaskProvider3 * This,
    /* [in] */ IVsTaskItem *pItem,
    /* [in] */ BOOL fCommitChanges,
    /* [out] */ BOOL *pfAllowChanges);


void __RPC_STUB IVsTaskProvider3_OnEndTaskEdit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsTaskProvider3_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshell80_0780 */
/* [local] */ 

typedef 
enum __tagVSTASKVALUETYPE
    {	TVT_NULL	= 0,
	TVT_TEXT	= 1,
	TVT_LINKTEXT	= 2,
	TVT_BASE10	= 3,
	TVT_IMAGE	= 4
    } 	VSTASKVALUETYPE;


enum __VSTASKVALUEFLAGS
    {	TVF_EDITABLE	= 0x1,
	TVF_ENUM	= 0x2,
	TVF_BINARY_STATE	= 0x4,
	TVF_HORZ_RIGHT	= 0x8,
	TVF_HORZ_CENTER	= 0x10,
	TVF_STRIKETHROUGH	= 0x20,
	TVF_FILENAME	= 0x40
    } ;
typedef DWORD VSTASKVALUEFLAGS;



extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0780_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0780_v0_0_s_ifspec;

#ifndef __IVsTaskItem3_INTERFACE_DEFINED__
#define __IVsTaskItem3_INTERFACE_DEFINED__

/* interface IVsTaskItem3 */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsTaskItem3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F353950E-C381-4ba6-BCAA-6BA64E53D252")
    IVsTaskItem3 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetTaskProvider( 
            /* [out] */ IVsTaskProvider3 **ppProvider) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTaskName( 
            /* [out] */ BSTR *pbstrName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetColumnValue( 
            /* [in] */ int iField,
            /* [out] */ VSTASKVALUETYPE *ptvtType,
            /* [out] */ VSTASKVALUEFLAGS *ptvfFlags,
            /* [out] */ VARIANT *pvarValue,
            /* [out] */ BSTR *pbstrAccessibilityName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTipText( 
            /* [in] */ int iField,
            /* [out] */ BSTR *pbstrTipText) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetColumnValue( 
            /* [in] */ int iField,
            /* [in] */ VARIANT *pvarValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsDirty( 
            /* [out] */ BOOL *pfDirty) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEnumCount( 
            /* [in] */ int iField,
            /* [out] */ int *pnValues) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEnumValue( 
            /* [in] */ int iField,
            /* [in] */ int iValue,
            /* [out] */ VARIANT *pvarValue,
            /* [out] */ BSTR *pbstrAccessibilityName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnLinkClicked( 
            /* [in] */ int iField,
            /* [in] */ int iLinkIndex) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNavigationStatusText( 
            /* [out] */ BSTR *pbstrText) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDefaultEditField( 
            /* [out] */ int *piField) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSurrogateProviderGuid( 
            /* [out] */ GUID *pguidProvider) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsTaskItem3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsTaskItem3 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsTaskItem3 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsTaskItem3 * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTaskProvider )( 
            IVsTaskItem3 * This,
            /* [out] */ IVsTaskProvider3 **ppProvider);
        
        HRESULT ( STDMETHODCALLTYPE *GetTaskName )( 
            IVsTaskItem3 * This,
            /* [out] */ BSTR *pbstrName);
        
        HRESULT ( STDMETHODCALLTYPE *GetColumnValue )( 
            IVsTaskItem3 * This,
            /* [in] */ int iField,
            /* [out] */ VSTASKVALUETYPE *ptvtType,
            /* [out] */ VSTASKVALUEFLAGS *ptvfFlags,
            /* [out] */ VARIANT *pvarValue,
            /* [out] */ BSTR *pbstrAccessibilityName);
        
        HRESULT ( STDMETHODCALLTYPE *GetTipText )( 
            IVsTaskItem3 * This,
            /* [in] */ int iField,
            /* [out] */ BSTR *pbstrTipText);
        
        HRESULT ( STDMETHODCALLTYPE *SetColumnValue )( 
            IVsTaskItem3 * This,
            /* [in] */ int iField,
            /* [in] */ VARIANT *pvarValue);
        
        HRESULT ( STDMETHODCALLTYPE *IsDirty )( 
            IVsTaskItem3 * This,
            /* [out] */ BOOL *pfDirty);
        
        HRESULT ( STDMETHODCALLTYPE *GetEnumCount )( 
            IVsTaskItem3 * This,
            /* [in] */ int iField,
            /* [out] */ int *pnValues);
        
        HRESULT ( STDMETHODCALLTYPE *GetEnumValue )( 
            IVsTaskItem3 * This,
            /* [in] */ int iField,
            /* [in] */ int iValue,
            /* [out] */ VARIANT *pvarValue,
            /* [out] */ BSTR *pbstrAccessibilityName);
        
        HRESULT ( STDMETHODCALLTYPE *OnLinkClicked )( 
            IVsTaskItem3 * This,
            /* [in] */ int iField,
            /* [in] */ int iLinkIndex);
        
        HRESULT ( STDMETHODCALLTYPE *GetNavigationStatusText )( 
            IVsTaskItem3 * This,
            /* [out] */ BSTR *pbstrText);
        
        HRESULT ( STDMETHODCALLTYPE *GetDefaultEditField )( 
            IVsTaskItem3 * This,
            /* [out] */ int *piField);
        
        HRESULT ( STDMETHODCALLTYPE *GetSurrogateProviderGuid )( 
            IVsTaskItem3 * This,
            /* [out] */ GUID *pguidProvider);
        
        END_INTERFACE
    } IVsTaskItem3Vtbl;

    interface IVsTaskItem3
    {
        CONST_VTBL struct IVsTaskItem3Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsTaskItem3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsTaskItem3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsTaskItem3_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsTaskItem3_GetTaskProvider(This,ppProvider)	\
    (This)->lpVtbl -> GetTaskProvider(This,ppProvider)

#define IVsTaskItem3_GetTaskName(This,pbstrName)	\
    (This)->lpVtbl -> GetTaskName(This,pbstrName)

#define IVsTaskItem3_GetColumnValue(This,iField,ptvtType,ptvfFlags,pvarValue,pbstrAccessibilityName)	\
    (This)->lpVtbl -> GetColumnValue(This,iField,ptvtType,ptvfFlags,pvarValue,pbstrAccessibilityName)

#define IVsTaskItem3_GetTipText(This,iField,pbstrTipText)	\
    (This)->lpVtbl -> GetTipText(This,iField,pbstrTipText)

#define IVsTaskItem3_SetColumnValue(This,iField,pvarValue)	\
    (This)->lpVtbl -> SetColumnValue(This,iField,pvarValue)

#define IVsTaskItem3_IsDirty(This,pfDirty)	\
    (This)->lpVtbl -> IsDirty(This,pfDirty)

#define IVsTaskItem3_GetEnumCount(This,iField,pnValues)	\
    (This)->lpVtbl -> GetEnumCount(This,iField,pnValues)

#define IVsTaskItem3_GetEnumValue(This,iField,iValue,pvarValue,pbstrAccessibilityName)	\
    (This)->lpVtbl -> GetEnumValue(This,iField,iValue,pvarValue,pbstrAccessibilityName)

#define IVsTaskItem3_OnLinkClicked(This,iField,iLinkIndex)	\
    (This)->lpVtbl -> OnLinkClicked(This,iField,iLinkIndex)

#define IVsTaskItem3_GetNavigationStatusText(This,pbstrText)	\
    (This)->lpVtbl -> GetNavigationStatusText(This,pbstrText)

#define IVsTaskItem3_GetDefaultEditField(This,piField)	\
    (This)->lpVtbl -> GetDefaultEditField(This,piField)

#define IVsTaskItem3_GetSurrogateProviderGuid(This,pguidProvider)	\
    (This)->lpVtbl -> GetSurrogateProviderGuid(This,pguidProvider)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsTaskItem3_GetTaskProvider_Proxy( 
    IVsTaskItem3 * This,
    /* [out] */ IVsTaskProvider3 **ppProvider);


void __RPC_STUB IVsTaskItem3_GetTaskProvider_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTaskItem3_GetTaskName_Proxy( 
    IVsTaskItem3 * This,
    /* [out] */ BSTR *pbstrName);


void __RPC_STUB IVsTaskItem3_GetTaskName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTaskItem3_GetColumnValue_Proxy( 
    IVsTaskItem3 * This,
    /* [in] */ int iField,
    /* [out] */ VSTASKVALUETYPE *ptvtType,
    /* [out] */ VSTASKVALUEFLAGS *ptvfFlags,
    /* [out] */ VARIANT *pvarValue,
    /* [out] */ BSTR *pbstrAccessibilityName);


void __RPC_STUB IVsTaskItem3_GetColumnValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTaskItem3_GetTipText_Proxy( 
    IVsTaskItem3 * This,
    /* [in] */ int iField,
    /* [out] */ BSTR *pbstrTipText);


void __RPC_STUB IVsTaskItem3_GetTipText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTaskItem3_SetColumnValue_Proxy( 
    IVsTaskItem3 * This,
    /* [in] */ int iField,
    /* [in] */ VARIANT *pvarValue);


void __RPC_STUB IVsTaskItem3_SetColumnValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTaskItem3_IsDirty_Proxy( 
    IVsTaskItem3 * This,
    /* [out] */ BOOL *pfDirty);


void __RPC_STUB IVsTaskItem3_IsDirty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTaskItem3_GetEnumCount_Proxy( 
    IVsTaskItem3 * This,
    /* [in] */ int iField,
    /* [out] */ int *pnValues);


void __RPC_STUB IVsTaskItem3_GetEnumCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTaskItem3_GetEnumValue_Proxy( 
    IVsTaskItem3 * This,
    /* [in] */ int iField,
    /* [in] */ int iValue,
    /* [out] */ VARIANT *pvarValue,
    /* [out] */ BSTR *pbstrAccessibilityName);


void __RPC_STUB IVsTaskItem3_GetEnumValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTaskItem3_OnLinkClicked_Proxy( 
    IVsTaskItem3 * This,
    /* [in] */ int iField,
    /* [in] */ int iLinkIndex);


void __RPC_STUB IVsTaskItem3_OnLinkClicked_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTaskItem3_GetNavigationStatusText_Proxy( 
    IVsTaskItem3 * This,
    /* [out] */ BSTR *pbstrText);


void __RPC_STUB IVsTaskItem3_GetNavigationStatusText_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTaskItem3_GetDefaultEditField_Proxy( 
    IVsTaskItem3 * This,
    /* [out] */ int *piField);


void __RPC_STUB IVsTaskItem3_GetDefaultEditField_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsTaskItem3_GetSurrogateProviderGuid_Proxy( 
    IVsTaskItem3 * This,
    /* [out] */ GUID *pguidProvider);


void __RPC_STUB IVsTaskItem3_GetSurrogateProviderGuid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsTaskItem3_INTERFACE_DEFINED__ */


#ifndef __IVsErrorList_INTERFACE_DEFINED__
#define __IVsErrorList_INTERFACE_DEFINED__

/* interface IVsErrorList */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsErrorList;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D824A797-62D2-4f60-98F8-4423624BC1BF")
    IVsErrorList : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE BringToFront( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ForceShowErrors( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsErrorListVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsErrorList * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsErrorList * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsErrorList * This);
        
        HRESULT ( STDMETHODCALLTYPE *BringToFront )( 
            IVsErrorList * This);
        
        HRESULT ( STDMETHODCALLTYPE *ForceShowErrors )( 
            IVsErrorList * This);
        
        END_INTERFACE
    } IVsErrorListVtbl;

    interface IVsErrorList
    {
        CONST_VTBL struct IVsErrorListVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsErrorList_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsErrorList_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsErrorList_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsErrorList_BringToFront(This)	\
    (This)->lpVtbl -> BringToFront(This)

#define IVsErrorList_ForceShowErrors(This)	\
    (This)->lpVtbl -> ForceShowErrors(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsErrorList_BringToFront_Proxy( 
    IVsErrorList * This);


void __RPC_STUB IVsErrorList_BringToFront_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsErrorList_ForceShowErrors_Proxy( 
    IVsErrorList * This);


void __RPC_STUB IVsErrorList_ForceShowErrors_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsErrorList_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vsshell80_0782 */
/* [local] */ 

extern const __declspec(selectany) GUID SID_SVsErrorList = { 0x599bcd9e, 0xcafa, 0x43df, { 0xaa, 0x3, 0x12, 0x9c, 0x0, 0x4, 0xc2, 0xbd } };
extern const __declspec(selectany) GUID GUID_ErrorList = { 0xd78612c7, 0x9962, 0x4b83, { 0x95, 0xd9, 0x26, 0x80, 0x46, 0xda, 0xd2, 0x3a } };
extern const __declspec(selectany) GUID GUID_PropertySheetManager = { 0x6B8E94B5, 0x0949, 0x4d9c, { 0xA8, 0x1F, 0xC1, 0xB9, 0xB7, 0x44, 0x18, 0x5C} };
typedef 
enum __tagVSERRORCATEGORY
    {	EC_ERROR	= 0,
	EC_WARNING	= 1,
	EC_MESSAGE	= 2
    } 	VSERRORCATEGORY;



extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0782_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vsshell80_0782_v0_0_s_ifspec;

#ifndef __IVsErrorItem_INTERFACE_DEFINED__
#define __IVsErrorItem_INTERFACE_DEFINED__

/* interface IVsErrorItem */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsErrorItem;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CE3DF110-7630-4d6c-81D5-5CFA12ADDAE6")
    IVsErrorItem : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetHierarchy( 
            /* [out] */ IVsHierarchy **ppProject) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCategory( 
            /* [out] */ VSERRORCATEGORY *pCategory) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsErrorItemVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsErrorItem * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsErrorItem * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsErrorItem * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetHierarchy )( 
            IVsErrorItem * This,
            /* [out] */ IVsHierarchy **ppProject);
        
        HRESULT ( STDMETHODCALLTYPE *GetCategory )( 
            IVsErrorItem * This,
            /* [out] */ VSERRORCATEGORY *pCategory);
        
        END_INTERFACE
    } IVsErrorItemVtbl;

    interface IVsErrorItem
    {
        CONST_VTBL struct IVsErrorItemVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsErrorItem_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsErrorItem_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsErrorItem_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsErrorItem_GetHierarchy(This,ppProject)	\
    (This)->lpVtbl -> GetHierarchy(This,ppProject)

#define IVsErrorItem_GetCategory(This,pCategory)	\
    (This)->lpVtbl -> GetCategory(This,pCategory)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsErrorItem_GetHierarchy_Proxy( 
    IVsErrorItem * This,
    /* [out] */ IVsHierarchy **ppProject);


void __RPC_STUB IVsErrorItem_GetHierarchy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsErrorItem_GetCategory_Proxy( 
    IVsErrorItem * This,
    /* [out] */ VSERRORCATEGORY *pCategory);


void __RPC_STUB IVsErrorItem_GetCategory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsErrorItem_INTERFACE_DEFINED__ */


#ifndef __IVsWindowPaneCommitFilter_INTERFACE_DEFINED__
#define __IVsWindowPaneCommitFilter_INTERFACE_DEFINED__

/* interface IVsWindowPaneCommitFilter */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsWindowPaneCommitFilter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("072B9701-2F81-4468-8EB6-074206504B62")
    IVsWindowPaneCommitFilter : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE IsCommitCommand( 
            /* [in] */ REFGUID pguidCmdGroup,
            /* [in] */ DWORD dwCmdID,
            /* [out] */ BOOL *pfCommitCommand) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsWindowPaneCommitFilterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsWindowPaneCommitFilter * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsWindowPaneCommitFilter * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsWindowPaneCommitFilter * This);
        
        HRESULT ( STDMETHODCALLTYPE *IsCommitCommand )( 
            IVsWindowPaneCommitFilter * This,
            /* [in] */ REFGUID pguidCmdGroup,
            /* [in] */ DWORD dwCmdID,
            /* [out] */ BOOL *pfCommitCommand);
        
        END_INTERFACE
    } IVsWindowPaneCommitFilterVtbl;

    interface IVsWindowPaneCommitFilter
    {
        CONST_VTBL struct IVsWindowPaneCommitFilterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsWindowPaneCommitFilter_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsWindowPaneCommitFilter_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsWindowPaneCommitFilter_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsWindowPaneCommitFilter_IsCommitCommand(This,pguidCmdGroup,dwCmdID,pfCommitCommand)	\
    (This)->lpVtbl -> IsCommitCommand(This,pguidCmdGroup,dwCmdID,pfCommitCommand)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsWindowPaneCommitFilter_IsCommitCommand_Proxy( 
    IVsWindowPaneCommitFilter * This,
    /* [in] */ REFGUID pguidCmdGroup,
    /* [in] */ DWORD dwCmdID,
    /* [out] */ BOOL *pfCommitCommand);


void __RPC_STUB IVsWindowPaneCommitFilter_IsCommitCommand_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsWindowPaneCommitFilter_INTERFACE_DEFINED__ */


#ifndef __IPreferPropertyPagesWithTreeControl_INTERFACE_DEFINED__
#define __IPreferPropertyPagesWithTreeControl_INTERFACE_DEFINED__

/* interface IPreferPropertyPagesWithTreeControl */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IPreferPropertyPagesWithTreeControl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("03AEFCEA-62A9-4606-8E17-7CB0FC13D5E0")
    IPreferPropertyPagesWithTreeControl : public IUnknown
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IPreferPropertyPagesWithTreeControlVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IPreferPropertyPagesWithTreeControl * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IPreferPropertyPagesWithTreeControl * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IPreferPropertyPagesWithTreeControl * This);
        
        END_INTERFACE
    } IPreferPropertyPagesWithTreeControlVtbl;

    interface IPreferPropertyPagesWithTreeControl
    {
        CONST_VTBL struct IPreferPropertyPagesWithTreeControlVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IPreferPropertyPagesWithTreeControl_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IPreferPropertyPagesWithTreeControl_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IPreferPropertyPagesWithTreeControl_Release(This)	\
    (This)->lpVtbl -> Release(This)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IPreferPropertyPagesWithTreeControl_INTERFACE_DEFINED__ */


#ifndef __IVsDeployDependency2_INTERFACE_DEFINED__
#define __IVsDeployDependency2_INTERFACE_DEFINED__

/* interface IVsDeployDependency2 */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsDeployDependency2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("77F54647-95E6-4033-91A8-51CCD014D945")
    IVsDeployDependency2 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE get_Property( 
            /* [in] */ LPCOLESTR szProperty,
            /* [out] */ VARIANT *pvar) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsDeployDependency2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsDeployDependency2 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsDeployDependency2 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsDeployDependency2 * This);
        
        HRESULT ( STDMETHODCALLTYPE *get_Property )( 
            IVsDeployDependency2 * This,
            /* [in] */ LPCOLESTR szProperty,
            /* [out] */ VARIANT *pvar);
        
        END_INTERFACE
    } IVsDeployDependency2Vtbl;

    interface IVsDeployDependency2
    {
        CONST_VTBL struct IVsDeployDependency2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsDeployDependency2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsDeployDependency2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsDeployDependency2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsDeployDependency2_get_Property(This,szProperty,pvar)	\
    (This)->lpVtbl -> get_Property(This,szProperty,pvar)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsDeployDependency2_get_Property_Proxy( 
    IVsDeployDependency2 * This,
    /* [in] */ LPCOLESTR szProperty,
    /* [out] */ VARIANT *pvar);


void __RPC_STUB IVsDeployDependency2_get_Property_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsDeployDependency2_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

unsigned long             __RPC_USER  HBITMAP_UserSize(     unsigned long *, unsigned long            , HBITMAP * ); 
unsigned char * __RPC_USER  HBITMAP_UserMarshal(  unsigned long *, unsigned char *, HBITMAP * ); 
unsigned char * __RPC_USER  HBITMAP_UserUnmarshal(unsigned long *, unsigned char *, HBITMAP * ); 
void                      __RPC_USER  HBITMAP_UserFree(     unsigned long *, HBITMAP * ); 

unsigned long             __RPC_USER  HDC_UserSize(     unsigned long *, unsigned long            , HDC * ); 
unsigned char * __RPC_USER  HDC_UserMarshal(  unsigned long *, unsigned char *, HDC * ); 
unsigned char * __RPC_USER  HDC_UserUnmarshal(unsigned long *, unsigned char *, HDC * ); 
void                      __RPC_USER  HDC_UserFree(     unsigned long *, HDC * ); 

unsigned long             __RPC_USER  HICON_UserSize(     unsigned long *, unsigned long            , HICON * ); 
unsigned char * __RPC_USER  HICON_UserMarshal(  unsigned long *, unsigned char *, HICON * ); 
unsigned char * __RPC_USER  HICON_UserUnmarshal(unsigned long *, unsigned char *, HICON * ); 
void                      __RPC_USER  HICON_UserFree(     unsigned long *, HICON * ); 

unsigned long             __RPC_USER  HWND_UserSize(     unsigned long *, unsigned long            , HWND * ); 
unsigned char * __RPC_USER  HWND_UserMarshal(  unsigned long *, unsigned char *, HWND * ); 
unsigned char * __RPC_USER  HWND_UserUnmarshal(unsigned long *, unsigned char *, HWND * ); 
void                      __RPC_USER  HWND_UserFree(     unsigned long *, HWND * ); 

unsigned long             __RPC_USER  VARIANT_UserSize(     unsigned long *, unsigned long            , VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserMarshal(  unsigned long *, unsigned char *, VARIANT * ); 
unsigned char * __RPC_USER  VARIANT_UserUnmarshal(unsigned long *, unsigned char *, VARIANT * ); 
void                      __RPC_USER  VARIANT_UserFree(     unsigned long *, VARIANT * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


