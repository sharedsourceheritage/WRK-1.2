
#pragma warning( disable: 4049 )  /* more than 64k source lines */
#pragma warning( disable: 4100 ) /* unreferenced arguments in x86 call */
#pragma warning( disable: 4211 )  /* redefine extent to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0359 */
/* Compiler settings for vspkg.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
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

#ifndef __vspkg_h__
#define __vspkg_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IVsEnumBSTRs_FWD_DEFINED__
#define __IVsEnumBSTRs_FWD_DEFINED__
typedef interface IVsEnumBSTRs IVsEnumBSTRs;
#endif 	/* __IVsEnumBSTRs_FWD_DEFINED__ */


#ifndef __IVsPackageDescription_FWD_DEFINED__
#define __IVsPackageDescription_FWD_DEFINED__
typedef interface IVsPackageDescription IVsPackageDescription;
#endif 	/* __IVsPackageDescription_FWD_DEFINED__ */


#ifndef __IVsJARPackageDescription_FWD_DEFINED__
#define __IVsJARPackageDescription_FWD_DEFINED__
typedef interface IVsJARPackageDescription IVsJARPackageDescription;
#endif 	/* __IVsJARPackageDescription_FWD_DEFINED__ */


#ifndef __IVsCABPackageDescription_FWD_DEFINED__
#define __IVsCABPackageDescription_FWD_DEFINED__
typedef interface IVsCABPackageDescription IVsCABPackageDescription;
#endif 	/* __IVsCABPackageDescription_FWD_DEFINED__ */


#ifndef __IVsDeploymentCABPackageDescription_FWD_DEFINED__
#define __IVsDeploymentCABPackageDescription_FWD_DEFINED__
typedef interface IVsDeploymentCABPackageDescription IVsDeploymentCABPackageDescription;
#endif 	/* __IVsDeploymentCABPackageDescription_FWD_DEFINED__ */


#ifndef __IVsEnumPackageItems_FWD_DEFINED__
#define __IVsEnumPackageItems_FWD_DEFINED__
typedef interface IVsEnumPackageItems IVsEnumPackageItems;
#endif 	/* __IVsEnumPackageItems_FWD_DEFINED__ */


#ifndef __IVsPackageItem_FWD_DEFINED__
#define __IVsPackageItem_FWD_DEFINED__
typedef interface IVsPackageItem IVsPackageItem;
#endif 	/* __IVsPackageItem_FWD_DEFINED__ */


#ifndef __IVsJARPackageItem_FWD_DEFINED__
#define __IVsJARPackageItem_FWD_DEFINED__
typedef interface IVsJARPackageItem IVsJARPackageItem;
#endif 	/* __IVsJARPackageItem_FWD_DEFINED__ */


#ifndef __IVsCABPackageItem_FWD_DEFINED__
#define __IVsCABPackageItem_FWD_DEFINED__
typedef interface IVsCABPackageItem IVsCABPackageItem;
#endif 	/* __IVsCABPackageItem_FWD_DEFINED__ */


#ifndef __IVsPackagingEngineStatusCallback_FWD_DEFINED__
#define __IVsPackagingEngineStatusCallback_FWD_DEFINED__
typedef interface IVsPackagingEngineStatusCallback IVsPackagingEngineStatusCallback;
#endif 	/* __IVsPackagingEngineStatusCallback_FWD_DEFINED__ */


#ifndef __IVsCABPackagingEngineStatusCallback_FWD_DEFINED__
#define __IVsCABPackagingEngineStatusCallback_FWD_DEFINED__
typedef interface IVsCABPackagingEngineStatusCallback IVsCABPackagingEngineStatusCallback;
#endif 	/* __IVsCABPackagingEngineStatusCallback_FWD_DEFINED__ */


#ifndef __IVsPackagingEngine_FWD_DEFINED__
#define __IVsPackagingEngine_FWD_DEFINED__
typedef interface IVsPackagingEngine IVsPackagingEngine;
#endif 	/* __IVsPackagingEngine_FWD_DEFINED__ */


#ifndef __IVsCABPackagingEngine_FWD_DEFINED__
#define __IVsCABPackagingEngine_FWD_DEFINED__
typedef interface IVsCABPackagingEngine IVsCABPackagingEngine;
#endif 	/* __IVsCABPackagingEngine_FWD_DEFINED__ */


#ifndef __IVsPackageExplorerStatusCallback_FWD_DEFINED__
#define __IVsPackageExplorerStatusCallback_FWD_DEFINED__
typedef interface IVsPackageExplorerStatusCallback IVsPackageExplorerStatusCallback;
#endif 	/* __IVsPackageExplorerStatusCallback_FWD_DEFINED__ */


#ifndef __IVsPackageExplorer_FWD_DEFINED__
#define __IVsPackageExplorer_FWD_DEFINED__
typedef interface IVsPackageExplorer IVsPackageExplorer;
#endif 	/* __IVsPackageExplorer_FWD_DEFINED__ */


#ifndef __IVsPackagingHelper_FWD_DEFINED__
#define __IVsPackagingHelper_FWD_DEFINED__
typedef interface IVsPackagingHelper IVsPackagingHelper;
#endif 	/* __IVsPackagingHelper_FWD_DEFINED__ */


#ifndef __IVsPackagingWrapperProjectCfg_FWD_DEFINED__
#define __IVsPackagingWrapperProjectCfg_FWD_DEFINED__
typedef interface IVsPackagingWrapperProjectCfg IVsPackagingWrapperProjectCfg;
#endif 	/* __IVsPackagingWrapperProjectCfg_FWD_DEFINED__ */


#ifndef __IVsPackagingEngineFilter_FWD_DEFINED__
#define __IVsPackagingEngineFilter_FWD_DEFINED__
typedef interface IVsPackagingEngineFilter IVsPackagingEngineFilter;
#endif 	/* __IVsPackagingEngineFilter_FWD_DEFINED__ */


#ifndef __IVsPackagingGeneralPPageController_FWD_DEFINED__
#define __IVsPackagingGeneralPPageController_FWD_DEFINED__
typedef interface IVsPackagingGeneralPPageController IVsPackagingGeneralPPageController;
#endif 	/* __IVsPackagingGeneralPPageController_FWD_DEFINED__ */


#ifndef __IVsPackagingGeneralPPageSettings_FWD_DEFINED__
#define __IVsPackagingGeneralPPageSettings_FWD_DEFINED__
typedef interface IVsPackagingGeneralPPageSettings IVsPackagingGeneralPPageSettings;
#endif 	/* __IVsPackagingGeneralPPageSettings_FWD_DEFINED__ */


#ifndef __IVsPackagingGeneralProperties_FWD_DEFINED__
#define __IVsPackagingGeneralProperties_FWD_DEFINED__
typedef interface IVsPackagingGeneralProperties IVsPackagingGeneralProperties;
#endif 	/* __IVsPackagingGeneralProperties_FWD_DEFINED__ */


#ifndef __IVsPackagingOutputsProperties_FWD_DEFINED__
#define __IVsPackagingOutputsProperties_FWD_DEFINED__
typedef interface IVsPackagingOutputsProperties IVsPackagingOutputsProperties;
#endif 	/* __IVsPackagingOutputsProperties_FWD_DEFINED__ */


#ifndef __IVsPackagingPropertyObject_FWD_DEFINED__
#define __IVsPackagingPropertyObject_FWD_DEFINED__
typedef interface IVsPackagingPropertyObject IVsPackagingPropertyObject;
#endif 	/* __IVsPackagingPropertyObject_FWD_DEFINED__ */


#ifndef __IVsCABPPageController_FWD_DEFINED__
#define __IVsCABPPageController_FWD_DEFINED__
typedef interface IVsCABPPageController IVsCABPPageController;
#endif 	/* __IVsCABPPageController_FWD_DEFINED__ */


#ifndef __IVsCABPPageSettings_FWD_DEFINED__
#define __IVsCABPPageSettings_FWD_DEFINED__
typedef interface IVsCABPPageSettings IVsCABPPageSettings;
#endif 	/* __IVsCABPPageSettings_FWD_DEFINED__ */


#ifndef __IVsCABProperties_FWD_DEFINED__
#define __IVsCABProperties_FWD_DEFINED__
typedef interface IVsCABProperties IVsCABProperties;
#endif 	/* __IVsCABProperties_FWD_DEFINED__ */


#ifndef __IVsSigningProperties_FWD_DEFINED__
#define __IVsSigningProperties_FWD_DEFINED__
typedef interface IVsSigningProperties IVsSigningProperties;
#endif 	/* __IVsSigningProperties_FWD_DEFINED__ */


#ifndef __IVsSigningJavaPermissionProperties_FWD_DEFINED__
#define __IVsSigningJavaPermissionProperties_FWD_DEFINED__
typedef interface IVsSigningJavaPermissionProperties IVsSigningJavaPermissionProperties;
#endif 	/* __IVsSigningJavaPermissionProperties_FWD_DEFINED__ */


#ifndef __IVsOSDProperties_FWD_DEFINED__
#define __IVsOSDProperties_FWD_DEFINED__
typedef interface IVsOSDProperties IVsOSDProperties;
#endif 	/* __IVsOSDProperties_FWD_DEFINED__ */


#ifndef __IVsSetupPPageController_FWD_DEFINED__
#define __IVsSetupPPageController_FWD_DEFINED__
typedef interface IVsSetupPPageController IVsSetupPPageController;
#endif 	/* __IVsSetupPPageController_FWD_DEFINED__ */


#ifndef __IVsSetupPPageSettings_FWD_DEFINED__
#define __IVsSetupPPageSettings_FWD_DEFINED__
typedef interface IVsSetupPPageSettings IVsSetupPPageSettings;
#endif 	/* __IVsSetupPPageSettings_FWD_DEFINED__ */


#ifndef __IVsSetupProperties_FWD_DEFINED__
#define __IVsSetupProperties_FWD_DEFINED__
typedef interface IVsSetupProperties IVsSetupProperties;
#endif 	/* __IVsSetupProperties_FWD_DEFINED__ */


#ifndef __IVsEnumVSSETUPFILEPROP_FWD_DEFINED__
#define __IVsEnumVSSETUPFILEPROP_FWD_DEFINED__
typedef interface IVsEnumVSSETUPFILEPROP IVsEnumVSSETUPFILEPROP;
#endif 	/* __IVsEnumVSSETUPFILEPROP_FWD_DEFINED__ */


#ifndef __IVsSetupFilePlacementProperties_FWD_DEFINED__
#define __IVsSetupFilePlacementProperties_FWD_DEFINED__
typedef interface IVsSetupFilePlacementProperties IVsSetupFilePlacementProperties;
#endif 	/* __IVsSetupFilePlacementProperties_FWD_DEFINED__ */


#ifndef __IVsSetupPackageDescription_FWD_DEFINED__
#define __IVsSetupPackageDescription_FWD_DEFINED__
typedef interface IVsSetupPackageDescription IVsSetupPackageDescription;
#endif 	/* __IVsSetupPackageDescription_FWD_DEFINED__ */


#ifndef __IVsSetupPackageItem_FWD_DEFINED__
#define __IVsSetupPackageItem_FWD_DEFINED__
typedef interface IVsSetupPackageItem IVsSetupPackageItem;
#endif 	/* __IVsSetupPackageItem_FWD_DEFINED__ */


#ifndef __IVsSetupPackagingEngineStatusCallback_FWD_DEFINED__
#define __IVsSetupPackagingEngineStatusCallback_FWD_DEFINED__
typedef interface IVsSetupPackagingEngineStatusCallback IVsSetupPackagingEngineStatusCallback;
#endif 	/* __IVsSetupPackagingEngineStatusCallback_FWD_DEFINED__ */


#ifndef __IVsSetupPackagingEngine_FWD_DEFINED__
#define __IVsSetupPackagingEngine_FWD_DEFINED__
typedef interface IVsSetupPackagingEngine IVsSetupPackagingEngine;
#endif 	/* __IVsSetupPackagingEngine_FWD_DEFINED__ */


#ifndef __IVsINFBasicGeneration_FWD_DEFINED__
#define __IVsINFBasicGeneration_FWD_DEFINED__
typedef interface IVsINFBasicGeneration IVsINFBasicGeneration;
#endif 	/* __IVsINFBasicGeneration_FWD_DEFINED__ */


#ifndef __IVsPackagingEnginePropertyInterfaceBroker_FWD_DEFINED__
#define __IVsPackagingEnginePropertyInterfaceBroker_FWD_DEFINED__
typedef interface IVsPackagingEnginePropertyInterfaceBroker IVsPackagingEnginePropertyInterfaceBroker;
#endif 	/* __IVsPackagingEnginePropertyInterfaceBroker_FWD_DEFINED__ */


#ifndef __IVsJARProperties_FWD_DEFINED__
#define __IVsJARProperties_FWD_DEFINED__
typedef interface IVsJARProperties IVsJARProperties;
#endif 	/* __IVsJARProperties_FWD_DEFINED__ */


#ifndef __IVsJARPPageController_FWD_DEFINED__
#define __IVsJARPPageController_FWD_DEFINED__
typedef interface IVsJARPPageController IVsJARPPageController;
#endif 	/* __IVsJARPPageController_FWD_DEFINED__ */


#ifndef __IVsJARPPageSettings_FWD_DEFINED__
#define __IVsJARPPageSettings_FWD_DEFINED__
typedef interface IVsJARPPageSettings IVsJARPPageSettings;
#endif 	/* __IVsJARPPageSettings_FWD_DEFINED__ */


#ifndef __IVsOpenSoftwareDistributionInfo_FWD_DEFINED__
#define __IVsOpenSoftwareDistributionInfo_FWD_DEFINED__
typedef interface IVsOpenSoftwareDistributionInfo IVsOpenSoftwareDistributionInfo;
#endif 	/* __IVsOpenSoftwareDistributionInfo_FWD_DEFINED__ */


#ifndef __IVsCABPermissionsPageSettings_FWD_DEFINED__
#define __IVsCABPermissionsPageSettings_FWD_DEFINED__
typedef interface IVsCABPermissionsPageSettings IVsCABPermissionsPageSettings;
#endif 	/* __IVsCABPermissionsPageSettings_FWD_DEFINED__ */


#ifndef __IVsVMPermission_FWD_DEFINED__
#define __IVsVMPermission_FWD_DEFINED__
typedef interface IVsVMPermission IVsVMPermission;
#endif 	/* __IVsVMPermission_FWD_DEFINED__ */


#ifndef __IVsVMPermissionProvider_FWD_DEFINED__
#define __IVsVMPermissionProvider_FWD_DEFINED__
typedef interface IVsVMPermissionProvider IVsVMPermissionProvider;
#endif 	/* __IVsVMPermissionProvider_FWD_DEFINED__ */


#ifndef __IVsEnumVMPermissions_FWD_DEFINED__
#define __IVsEnumVMPermissions_FWD_DEFINED__
typedef interface IVsEnumVMPermissions IVsEnumVMPermissions;
#endif 	/* __IVsEnumVMPermissions_FWD_DEFINED__ */


#ifndef __IVsVMPermissionCollection_FWD_DEFINED__
#define __IVsVMPermissionCollection_FWD_DEFINED__
typedef interface IVsVMPermissionCollection IVsVMPermissionCollection;
#endif 	/* __IVsVMPermissionCollection_FWD_DEFINED__ */


#ifndef __IVsVMPermissionProperty_FWD_DEFINED__
#define __IVsVMPermissionProperty_FWD_DEFINED__
typedef interface IVsVMPermissionProperty IVsVMPermissionProperty;
#endif 	/* __IVsVMPermissionProperty_FWD_DEFINED__ */


#ifndef __IVsEnumVMPermissionProperties_FWD_DEFINED__
#define __IVsEnumVMPermissionProperties_FWD_DEFINED__
typedef interface IVsEnumVMPermissionProperties IVsEnumVMPermissionProperties;
#endif 	/* __IVsEnumVMPermissionProperties_FWD_DEFINED__ */


#ifndef __IVsCABExternalDependenciesPageSettings_FWD_DEFINED__
#define __IVsCABExternalDependenciesPageSettings_FWD_DEFINED__
typedef interface IVsCABExternalDependenciesPageSettings IVsCABExternalDependenciesPageSettings;
#endif 	/* __IVsCABExternalDependenciesPageSettings_FWD_DEFINED__ */


#ifndef __IVsPNPAdditionalFilesPageSettings_FWD_DEFINED__
#define __IVsPNPAdditionalFilesPageSettings_FWD_DEFINED__
typedef interface IVsPNPAdditionalFilesPageSettings IVsPNPAdditionalFilesPageSettings;
#endif 	/* __IVsPNPAdditionalFilesPageSettings_FWD_DEFINED__ */


#ifndef __IVsWebLibrary_FWD_DEFINED__
#define __IVsWebLibrary_FWD_DEFINED__
typedef interface IVsWebLibrary IVsWebLibrary;
#endif 	/* __IVsWebLibrary_FWD_DEFINED__ */


#ifndef __IVsWebLibraryProvider_FWD_DEFINED__
#define __IVsWebLibraryProvider_FWD_DEFINED__
typedef interface IVsWebLibraryProvider IVsWebLibraryProvider;
#endif 	/* __IVsWebLibraryProvider_FWD_DEFINED__ */


#ifndef __IVsEnumWebLibraries_FWD_DEFINED__
#define __IVsEnumWebLibraries_FWD_DEFINED__
typedef interface IVsEnumWebLibraries IVsEnumWebLibraries;
#endif 	/* __IVsEnumWebLibraries_FWD_DEFINED__ */


#ifndef __IVsWebLibraryCollection_FWD_DEFINED__
#define __IVsWebLibraryCollection_FWD_DEFINED__
typedef interface IVsWebLibraryCollection IVsWebLibraryCollection;
#endif 	/* __IVsWebLibraryCollection_FWD_DEFINED__ */


#ifndef __IVsAdditionalItemProvider_FWD_DEFINED__
#define __IVsAdditionalItemProvider_FWD_DEFINED__
typedef interface IVsAdditionalItemProvider IVsAdditionalItemProvider;
#endif 	/* __IVsAdditionalItemProvider_FWD_DEFINED__ */


#ifndef __IVsAdditionalItemCollection_FWD_DEFINED__
#define __IVsAdditionalItemCollection_FWD_DEFINED__
typedef interface IVsAdditionalItemCollection IVsAdditionalItemCollection;
#endif 	/* __IVsAdditionalItemCollection_FWD_DEFINED__ */


#ifndef __IVsSubProcess_FWD_DEFINED__
#define __IVsSubProcess_FWD_DEFINED__
typedef interface IVsSubProcess IVsSubProcess;
#endif 	/* __IVsSubProcess_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "vsshell.h"
#include "vssolutn.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

/* interface __MIDL_itf_vspkg_0000 */
/* [local] */ 








































extern RPC_IF_HANDLE __MIDL_itf_vspkg_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vspkg_0000_v0_0_s_ifspec;

#ifndef __IVsEnumBSTRs_INTERFACE_DEFINED__
#define __IVsEnumBSTRs_INTERFACE_DEFINED__

/* interface IVsEnumBSTRs */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsEnumBSTRs;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("52383877-c56b-11d0-8a49-00a0c91e2acd")
    IVsEnumBSTRs : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [size_is][out][in] */ BSTR rgbstr[  ],
            /* [out] */ ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IVsEnumBSTRs **ppIVsEnumBSTRs) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsEnumBSTRsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsEnumBSTRs * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsEnumBSTRs * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsEnumBSTRs * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IVsEnumBSTRs * This,
            /* [in] */ ULONG celt,
            /* [size_is][out][in] */ BSTR rgbstr[  ],
            /* [out] */ ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IVsEnumBSTRs * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IVsEnumBSTRs * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IVsEnumBSTRs * This,
            /* [out] */ IVsEnumBSTRs **ppIVsEnumBSTRs);
        
        END_INTERFACE
    } IVsEnumBSTRsVtbl;

    interface IVsEnumBSTRs
    {
        CONST_VTBL struct IVsEnumBSTRsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsEnumBSTRs_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsEnumBSTRs_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsEnumBSTRs_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsEnumBSTRs_Next(This,celt,rgbstr,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgbstr,pceltFetched)

#define IVsEnumBSTRs_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IVsEnumBSTRs_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IVsEnumBSTRs_Clone(This,ppIVsEnumBSTRs)	\
    (This)->lpVtbl -> Clone(This,ppIVsEnumBSTRs)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsEnumBSTRs_Next_Proxy( 
    IVsEnumBSTRs * This,
    /* [in] */ ULONG celt,
    /* [size_is][out][in] */ BSTR rgbstr[  ],
    /* [out] */ ULONG *pceltFetched);


void __RPC_STUB IVsEnumBSTRs_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsEnumBSTRs_Skip_Proxy( 
    IVsEnumBSTRs * This,
    /* [in] */ ULONG celt);


void __RPC_STUB IVsEnumBSTRs_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsEnumBSTRs_Reset_Proxy( 
    IVsEnumBSTRs * This);


void __RPC_STUB IVsEnumBSTRs_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsEnumBSTRs_Clone_Proxy( 
    IVsEnumBSTRs * This,
    /* [out] */ IVsEnumBSTRs **ppIVsEnumBSTRs);


void __RPC_STUB IVsEnumBSTRs_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsEnumBSTRs_INTERFACE_DEFINED__ */


#ifndef __IVsPackageDescription_INTERFACE_DEFINED__
#define __IVsPackageDescription_INTERFACE_DEFINED__

/* interface IVsPackageDescription */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsPackageDescription;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("52383865-c56b-11d0-8a49-00a0c91e2acd")
    IVsPackageDescription : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE EnumItems( 
            /* [out] */ IVsEnumPackageItems **ppIVsEnumPackageItems) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_OSDFilename( 
            /* [full][string][in] */ LPCOLESTR szFilename) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_OSDFilename( 
            /* [out] */ BSTR *pbstrFileName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsPackageDescriptionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsPackageDescription * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsPackageDescription * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsPackageDescription * This);
        
        HRESULT ( STDMETHODCALLTYPE *EnumItems )( 
            IVsPackageDescription * This,
            /* [out] */ IVsEnumPackageItems **ppIVsEnumPackageItems);
        
        HRESULT ( STDMETHODCALLTYPE *put_OSDFilename )( 
            IVsPackageDescription * This,
            /* [full][string][in] */ LPCOLESTR szFilename);
        
        HRESULT ( STDMETHODCALLTYPE *get_OSDFilename )( 
            IVsPackageDescription * This,
            /* [out] */ BSTR *pbstrFileName);
        
        END_INTERFACE
    } IVsPackageDescriptionVtbl;

    interface IVsPackageDescription
    {
        CONST_VTBL struct IVsPackageDescriptionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsPackageDescription_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsPackageDescription_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsPackageDescription_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsPackageDescription_EnumItems(This,ppIVsEnumPackageItems)	\
    (This)->lpVtbl -> EnumItems(This,ppIVsEnumPackageItems)

#define IVsPackageDescription_put_OSDFilename(This,szFilename)	\
    (This)->lpVtbl -> put_OSDFilename(This,szFilename)

#define IVsPackageDescription_get_OSDFilename(This,pbstrFileName)	\
    (This)->lpVtbl -> get_OSDFilename(This,pbstrFileName)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsPackageDescription_EnumItems_Proxy( 
    IVsPackageDescription * This,
    /* [out] */ IVsEnumPackageItems **ppIVsEnumPackageItems);


void __RPC_STUB IVsPackageDescription_EnumItems_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackageDescription_put_OSDFilename_Proxy( 
    IVsPackageDescription * This,
    /* [full][string][in] */ LPCOLESTR szFilename);


void __RPC_STUB IVsPackageDescription_put_OSDFilename_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackageDescription_get_OSDFilename_Proxy( 
    IVsPackageDescription * This,
    /* [out] */ BSTR *pbstrFileName);


void __RPC_STUB IVsPackageDescription_get_OSDFilename_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsPackageDescription_INTERFACE_DEFINED__ */


#ifndef __IVsJARPackageDescription_INTERFACE_DEFINED__
#define __IVsJARPackageDescription_INTERFACE_DEFINED__

/* interface IVsJARPackageDescription */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsJARPackageDescription;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("52383866-c56b-11d0-8a49-00a0c91e2acd")
    IVsJARPackageDescription : public IVsPackageDescription
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE put_PackageComment( 
            /* [full][string][in] */ LPCOLESTR szFilename) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_PackageComment( 
            /* [in] */ ULONG cch,
            /* [size_is][out][in] */ OLECHAR rgchBuffer[  ],
            /* [out] */ ULONG *pcchActual) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsJARPackageDescriptionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsJARPackageDescription * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsJARPackageDescription * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsJARPackageDescription * This);
        
        HRESULT ( STDMETHODCALLTYPE *EnumItems )( 
            IVsJARPackageDescription * This,
            /* [out] */ IVsEnumPackageItems **ppIVsEnumPackageItems);
        
        HRESULT ( STDMETHODCALLTYPE *put_OSDFilename )( 
            IVsJARPackageDescription * This,
            /* [full][string][in] */ LPCOLESTR szFilename);
        
        HRESULT ( STDMETHODCALLTYPE *get_OSDFilename )( 
            IVsJARPackageDescription * This,
            /* [out] */ BSTR *pbstrFileName);
        
        HRESULT ( STDMETHODCALLTYPE *put_PackageComment )( 
            IVsJARPackageDescription * This,
            /* [full][string][in] */ LPCOLESTR szFilename);
        
        HRESULT ( STDMETHODCALLTYPE *get_PackageComment )( 
            IVsJARPackageDescription * This,
            /* [in] */ ULONG cch,
            /* [size_is][out][in] */ OLECHAR rgchBuffer[  ],
            /* [out] */ ULONG *pcchActual);
        
        END_INTERFACE
    } IVsJARPackageDescriptionVtbl;

    interface IVsJARPackageDescription
    {
        CONST_VTBL struct IVsJARPackageDescriptionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsJARPackageDescription_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsJARPackageDescription_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsJARPackageDescription_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsJARPackageDescription_EnumItems(This,ppIVsEnumPackageItems)	\
    (This)->lpVtbl -> EnumItems(This,ppIVsEnumPackageItems)

#define IVsJARPackageDescription_put_OSDFilename(This,szFilename)	\
    (This)->lpVtbl -> put_OSDFilename(This,szFilename)

#define IVsJARPackageDescription_get_OSDFilename(This,pbstrFileName)	\
    (This)->lpVtbl -> get_OSDFilename(This,pbstrFileName)


#define IVsJARPackageDescription_put_PackageComment(This,szFilename)	\
    (This)->lpVtbl -> put_PackageComment(This,szFilename)

#define IVsJARPackageDescription_get_PackageComment(This,cch,rgchBuffer,pcchActual)	\
    (This)->lpVtbl -> get_PackageComment(This,cch,rgchBuffer,pcchActual)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsJARPackageDescription_put_PackageComment_Proxy( 
    IVsJARPackageDescription * This,
    /* [full][string][in] */ LPCOLESTR szFilename);


void __RPC_STUB IVsJARPackageDescription_put_PackageComment_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsJARPackageDescription_get_PackageComment_Proxy( 
    IVsJARPackageDescription * This,
    /* [in] */ ULONG cch,
    /* [size_is][out][in] */ OLECHAR rgchBuffer[  ],
    /* [out] */ ULONG *pcchActual);


void __RPC_STUB IVsJARPackageDescription_get_PackageComment_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsJARPackageDescription_INTERFACE_DEFINED__ */


#ifndef __IVsCABPackageDescription_INTERFACE_DEFINED__
#define __IVsCABPackageDescription_INTERFACE_DEFINED__

/* interface IVsCABPackageDescription */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsCABPackageDescription;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("52383867-c56b-11d0-8a49-00a0c91e2acd")
    IVsCABPackageDescription : public IVsPackageDescription
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE get_ReservedSpace( 
            /* [out] */ UINT *plReservedSpace) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_CompressionType( 
            /* [out] */ unsigned short *tcomp) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_CompressionType( 
            /* [in] */ unsigned short tcomp) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsCABPackageDescriptionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsCABPackageDescription * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsCABPackageDescription * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsCABPackageDescription * This);
        
        HRESULT ( STDMETHODCALLTYPE *EnumItems )( 
            IVsCABPackageDescription * This,
            /* [out] */ IVsEnumPackageItems **ppIVsEnumPackageItems);
        
        HRESULT ( STDMETHODCALLTYPE *put_OSDFilename )( 
            IVsCABPackageDescription * This,
            /* [full][string][in] */ LPCOLESTR szFilename);
        
        HRESULT ( STDMETHODCALLTYPE *get_OSDFilename )( 
            IVsCABPackageDescription * This,
            /* [out] */ BSTR *pbstrFileName);
        
        HRESULT ( STDMETHODCALLTYPE *get_ReservedSpace )( 
            IVsCABPackageDescription * This,
            /* [out] */ UINT *plReservedSpace);
        
        HRESULT ( STDMETHODCALLTYPE *get_CompressionType )( 
            IVsCABPackageDescription * This,
            /* [out] */ unsigned short *tcomp);
        
        HRESULT ( STDMETHODCALLTYPE *put_CompressionType )( 
            IVsCABPackageDescription * This,
            /* [in] */ unsigned short tcomp);
        
        END_INTERFACE
    } IVsCABPackageDescriptionVtbl;

    interface IVsCABPackageDescription
    {
        CONST_VTBL struct IVsCABPackageDescriptionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsCABPackageDescription_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsCABPackageDescription_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsCABPackageDescription_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsCABPackageDescription_EnumItems(This,ppIVsEnumPackageItems)	\
    (This)->lpVtbl -> EnumItems(This,ppIVsEnumPackageItems)

#define IVsCABPackageDescription_put_OSDFilename(This,szFilename)	\
    (This)->lpVtbl -> put_OSDFilename(This,szFilename)

#define IVsCABPackageDescription_get_OSDFilename(This,pbstrFileName)	\
    (This)->lpVtbl -> get_OSDFilename(This,pbstrFileName)


#define IVsCABPackageDescription_get_ReservedSpace(This,plReservedSpace)	\
    (This)->lpVtbl -> get_ReservedSpace(This,plReservedSpace)

#define IVsCABPackageDescription_get_CompressionType(This,tcomp)	\
    (This)->lpVtbl -> get_CompressionType(This,tcomp)

#define IVsCABPackageDescription_put_CompressionType(This,tcomp)	\
    (This)->lpVtbl -> put_CompressionType(This,tcomp)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsCABPackageDescription_get_ReservedSpace_Proxy( 
    IVsCABPackageDescription * This,
    /* [out] */ UINT *plReservedSpace);


void __RPC_STUB IVsCABPackageDescription_get_ReservedSpace_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsCABPackageDescription_get_CompressionType_Proxy( 
    IVsCABPackageDescription * This,
    /* [out] */ unsigned short *tcomp);


void __RPC_STUB IVsCABPackageDescription_get_CompressionType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsCABPackageDescription_put_CompressionType_Proxy( 
    IVsCABPackageDescription * This,
    /* [in] */ unsigned short tcomp);


void __RPC_STUB IVsCABPackageDescription_put_CompressionType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsCABPackageDescription_INTERFACE_DEFINED__ */


#ifndef __IVsDeploymentCABPackageDescription_INTERFACE_DEFINED__
#define __IVsDeploymentCABPackageDescription_INTERFACE_DEFINED__

/* interface IVsDeploymentCABPackageDescription */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsDeploymentCABPackageDescription;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3C0B95F0-8B92-11d1-A218-0000F8026F55")
    IVsDeploymentCABPackageDescription : public IVsCABPackageDescription
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE get_IVsOutputWindowPane( 
            /* [out] */ IVsOutputWindowPane **ppIVsOutputWindowPane) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_StoredFilenameCodePage( 
            /* [out] */ UINT *puiCodePage) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsDeploymentCABPackageDescriptionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsDeploymentCABPackageDescription * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsDeploymentCABPackageDescription * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsDeploymentCABPackageDescription * This);
        
        HRESULT ( STDMETHODCALLTYPE *EnumItems )( 
            IVsDeploymentCABPackageDescription * This,
            /* [out] */ IVsEnumPackageItems **ppIVsEnumPackageItems);
        
        HRESULT ( STDMETHODCALLTYPE *put_OSDFilename )( 
            IVsDeploymentCABPackageDescription * This,
            /* [full][string][in] */ LPCOLESTR szFilename);
        
        HRESULT ( STDMETHODCALLTYPE *get_OSDFilename )( 
            IVsDeploymentCABPackageDescription * This,
            /* [out] */ BSTR *pbstrFileName);
        
        HRESULT ( STDMETHODCALLTYPE *get_ReservedSpace )( 
            IVsDeploymentCABPackageDescription * This,
            /* [out] */ UINT *plReservedSpace);
        
        HRESULT ( STDMETHODCALLTYPE *get_CompressionType )( 
            IVsDeploymentCABPackageDescription * This,
            /* [out] */ unsigned short *tcomp);
        
        HRESULT ( STDMETHODCALLTYPE *put_CompressionType )( 
            IVsDeploymentCABPackageDescription * This,
            /* [in] */ unsigned short tcomp);
        
        HRESULT ( STDMETHODCALLTYPE *get_IVsOutputWindowPane )( 
            IVsDeploymentCABPackageDescription * This,
            /* [out] */ IVsOutputWindowPane **ppIVsOutputWindowPane);
        
        HRESULT ( STDMETHODCALLTYPE *get_StoredFilenameCodePage )( 
            IVsDeploymentCABPackageDescription * This,
            /* [out] */ UINT *puiCodePage);
        
        END_INTERFACE
    } IVsDeploymentCABPackageDescriptionVtbl;

    interface IVsDeploymentCABPackageDescription
    {
        CONST_VTBL struct IVsDeploymentCABPackageDescriptionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsDeploymentCABPackageDescription_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsDeploymentCABPackageDescription_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsDeploymentCABPackageDescription_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsDeploymentCABPackageDescription_EnumItems(This,ppIVsEnumPackageItems)	\
    (This)->lpVtbl -> EnumItems(This,ppIVsEnumPackageItems)

#define IVsDeploymentCABPackageDescription_put_OSDFilename(This,szFilename)	\
    (This)->lpVtbl -> put_OSDFilename(This,szFilename)

#define IVsDeploymentCABPackageDescription_get_OSDFilename(This,pbstrFileName)	\
    (This)->lpVtbl -> get_OSDFilename(This,pbstrFileName)


#define IVsDeploymentCABPackageDescription_get_ReservedSpace(This,plReservedSpace)	\
    (This)->lpVtbl -> get_ReservedSpace(This,plReservedSpace)

#define IVsDeploymentCABPackageDescription_get_CompressionType(This,tcomp)	\
    (This)->lpVtbl -> get_CompressionType(This,tcomp)

#define IVsDeploymentCABPackageDescription_put_CompressionType(This,tcomp)	\
    (This)->lpVtbl -> put_CompressionType(This,tcomp)


#define IVsDeploymentCABPackageDescription_get_IVsOutputWindowPane(This,ppIVsOutputWindowPane)	\
    (This)->lpVtbl -> get_IVsOutputWindowPane(This,ppIVsOutputWindowPane)

#define IVsDeploymentCABPackageDescription_get_StoredFilenameCodePage(This,puiCodePage)	\
    (This)->lpVtbl -> get_StoredFilenameCodePage(This,puiCodePage)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsDeploymentCABPackageDescription_get_IVsOutputWindowPane_Proxy( 
    IVsDeploymentCABPackageDescription * This,
    /* [out] */ IVsOutputWindowPane **ppIVsOutputWindowPane);


void __RPC_STUB IVsDeploymentCABPackageDescription_get_IVsOutputWindowPane_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsDeploymentCABPackageDescription_get_StoredFilenameCodePage_Proxy( 
    IVsDeploymentCABPackageDescription * This,
    /* [out] */ UINT *puiCodePage);


void __RPC_STUB IVsDeploymentCABPackageDescription_get_StoredFilenameCodePage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsDeploymentCABPackageDescription_INTERFACE_DEFINED__ */


#ifndef __IVsEnumPackageItems_INTERFACE_DEFINED__
#define __IVsEnumPackageItems_INTERFACE_DEFINED__

/* interface IVsEnumPackageItems */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsEnumPackageItems;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("52383868-c56b-11d0-8a49-00a0c91e2acd")
    IVsEnumPackageItems : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ IVsPackageItem **prgpelt,
            /* [out] */ ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IVsEnumPackageItems **ppIVsEnumPackageItems) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsEnumPackageItemsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsEnumPackageItems * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsEnumPackageItems * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsEnumPackageItems * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IVsEnumPackageItems * This,
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ IVsPackageItem **prgpelt,
            /* [out] */ ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IVsEnumPackageItems * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IVsEnumPackageItems * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IVsEnumPackageItems * This,
            /* [out] */ IVsEnumPackageItems **ppIVsEnumPackageItems);
        
        END_INTERFACE
    } IVsEnumPackageItemsVtbl;

    interface IVsEnumPackageItems
    {
        CONST_VTBL struct IVsEnumPackageItemsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsEnumPackageItems_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsEnumPackageItems_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsEnumPackageItems_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsEnumPackageItems_Next(This,celt,prgpelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,prgpelt,pceltFetched)

#define IVsEnumPackageItems_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IVsEnumPackageItems_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IVsEnumPackageItems_Clone(This,ppIVsEnumPackageItems)	\
    (This)->lpVtbl -> Clone(This,ppIVsEnumPackageItems)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsEnumPackageItems_Next_Proxy( 
    IVsEnumPackageItems * This,
    /* [in] */ ULONG celt,
    /* [length_is][size_is][out] */ IVsPackageItem **prgpelt,
    /* [out] */ ULONG *pceltFetched);


void __RPC_STUB IVsEnumPackageItems_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsEnumPackageItems_Skip_Proxy( 
    IVsEnumPackageItems * This,
    /* [in] */ ULONG celt);


void __RPC_STUB IVsEnumPackageItems_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsEnumPackageItems_Reset_Proxy( 
    IVsEnumPackageItems * This);


void __RPC_STUB IVsEnumPackageItems_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsEnumPackageItems_Clone_Proxy( 
    IVsEnumPackageItems * This,
    /* [out] */ IVsEnumPackageItems **ppIVsEnumPackageItems);


void __RPC_STUB IVsEnumPackageItems_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsEnumPackageItems_INTERFACE_DEFINED__ */


#ifndef __IVsPackageItem_INTERFACE_DEFINED__
#define __IVsPackageItem_INTERFACE_DEFINED__

/* interface IVsPackageItem */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsPackageItem;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("52383869-c56b-11d0-8a49-00a0c91e2acd")
    IVsPackageItem : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE get_Filename( 
            /* [in] */ ULONG cch,
            /* [unique][size_is][out][in] */ OLECHAR rgchBuffer[  ],
            /* [out] */ ULONG *pcchActual) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_ProjectRelativeFilename( 
            /* [in] */ ULONG cch,
            /* [unique][size_is][out][in] */ OLECHAR rgchBuffer[  ],
            /* [out] */ ULONG *pcchActual) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_ItemSource( 
            /* [in] */ ULONG cch,
            /* [unique][size_is][out][in] */ OLECHAR rgchBuffer[  ],
            /* [out] */ ULONG *pcchActual) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsPackageItemVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsPackageItem * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsPackageItem * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsPackageItem * This);
        
        HRESULT ( STDMETHODCALLTYPE *get_Filename )( 
            IVsPackageItem * This,
            /* [in] */ ULONG cch,
            /* [unique][size_is][out][in] */ OLECHAR rgchBuffer[  ],
            /* [out] */ ULONG *pcchActual);
        
        HRESULT ( STDMETHODCALLTYPE *get_ProjectRelativeFilename )( 
            IVsPackageItem * This,
            /* [in] */ ULONG cch,
            /* [unique][size_is][out][in] */ OLECHAR rgchBuffer[  ],
            /* [out] */ ULONG *pcchActual);
        
        HRESULT ( STDMETHODCALLTYPE *get_ItemSource )( 
            IVsPackageItem * This,
            /* [in] */ ULONG cch,
            /* [unique][size_is][out][in] */ OLECHAR rgchBuffer[  ],
            /* [out] */ ULONG *pcchActual);
        
        END_INTERFACE
    } IVsPackageItemVtbl;

    interface IVsPackageItem
    {
        CONST_VTBL struct IVsPackageItemVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsPackageItem_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsPackageItem_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsPackageItem_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsPackageItem_get_Filename(This,cch,rgchBuffer,pcchActual)	\
    (This)->lpVtbl -> get_Filename(This,cch,rgchBuffer,pcchActual)

#define IVsPackageItem_get_ProjectRelativeFilename(This,cch,rgchBuffer,pcchActual)	\
    (This)->lpVtbl -> get_ProjectRelativeFilename(This,cch,rgchBuffer,pcchActual)

#define IVsPackageItem_get_ItemSource(This,cch,rgchBuffer,pcchActual)	\
    (This)->lpVtbl -> get_ItemSource(This,cch,rgchBuffer,pcchActual)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsPackageItem_get_Filename_Proxy( 
    IVsPackageItem * This,
    /* [in] */ ULONG cch,
    /* [unique][size_is][out][in] */ OLECHAR rgchBuffer[  ],
    /* [out] */ ULONG *pcchActual);


void __RPC_STUB IVsPackageItem_get_Filename_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackageItem_get_ProjectRelativeFilename_Proxy( 
    IVsPackageItem * This,
    /* [in] */ ULONG cch,
    /* [unique][size_is][out][in] */ OLECHAR rgchBuffer[  ],
    /* [out] */ ULONG *pcchActual);


void __RPC_STUB IVsPackageItem_get_ProjectRelativeFilename_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackageItem_get_ItemSource_Proxy( 
    IVsPackageItem * This,
    /* [in] */ ULONG cch,
    /* [unique][size_is][out][in] */ OLECHAR rgchBuffer[  ],
    /* [out] */ ULONG *pcchActual);


void __RPC_STUB IVsPackageItem_get_ItemSource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsPackageItem_INTERFACE_DEFINED__ */


#ifndef __IVsJARPackageItem_INTERFACE_DEFINED__
#define __IVsJARPackageItem_INTERFACE_DEFINED__

/* interface IVsJARPackageItem */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsJARPackageItem;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5238386a-c56b-11d0-8a49-00a0c91e2acd")
    IVsJARPackageItem : public IVsPackageItem
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE put_ItemComment( 
            /* [full][string][in] */ LPCOLESTR szFilename) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_ItemComment( 
            /* [in] */ ULONG cch,
            /* [size_is][out][in] */ OLECHAR rgchBuffer[  ],
            /* [out] */ ULONG *pcchActual) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsJARPackageItemVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsJARPackageItem * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsJARPackageItem * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsJARPackageItem * This);
        
        HRESULT ( STDMETHODCALLTYPE *get_Filename )( 
            IVsJARPackageItem * This,
            /* [in] */ ULONG cch,
            /* [unique][size_is][out][in] */ OLECHAR rgchBuffer[  ],
            /* [out] */ ULONG *pcchActual);
        
        HRESULT ( STDMETHODCALLTYPE *get_ProjectRelativeFilename )( 
            IVsJARPackageItem * This,
            /* [in] */ ULONG cch,
            /* [unique][size_is][out][in] */ OLECHAR rgchBuffer[  ],
            /* [out] */ ULONG *pcchActual);
        
        HRESULT ( STDMETHODCALLTYPE *get_ItemSource )( 
            IVsJARPackageItem * This,
            /* [in] */ ULONG cch,
            /* [unique][size_is][out][in] */ OLECHAR rgchBuffer[  ],
            /* [out] */ ULONG *pcchActual);
        
        HRESULT ( STDMETHODCALLTYPE *put_ItemComment )( 
            IVsJARPackageItem * This,
            /* [full][string][in] */ LPCOLESTR szFilename);
        
        HRESULT ( STDMETHODCALLTYPE *get_ItemComment )( 
            IVsJARPackageItem * This,
            /* [in] */ ULONG cch,
            /* [size_is][out][in] */ OLECHAR rgchBuffer[  ],
            /* [out] */ ULONG *pcchActual);
        
        END_INTERFACE
    } IVsJARPackageItemVtbl;

    interface IVsJARPackageItem
    {
        CONST_VTBL struct IVsJARPackageItemVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsJARPackageItem_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsJARPackageItem_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsJARPackageItem_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsJARPackageItem_get_Filename(This,cch,rgchBuffer,pcchActual)	\
    (This)->lpVtbl -> get_Filename(This,cch,rgchBuffer,pcchActual)

#define IVsJARPackageItem_get_ProjectRelativeFilename(This,cch,rgchBuffer,pcchActual)	\
    (This)->lpVtbl -> get_ProjectRelativeFilename(This,cch,rgchBuffer,pcchActual)

#define IVsJARPackageItem_get_ItemSource(This,cch,rgchBuffer,pcchActual)	\
    (This)->lpVtbl -> get_ItemSource(This,cch,rgchBuffer,pcchActual)


#define IVsJARPackageItem_put_ItemComment(This,szFilename)	\
    (This)->lpVtbl -> put_ItemComment(This,szFilename)

#define IVsJARPackageItem_get_ItemComment(This,cch,rgchBuffer,pcchActual)	\
    (This)->lpVtbl -> get_ItemComment(This,cch,rgchBuffer,pcchActual)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsJARPackageItem_put_ItemComment_Proxy( 
    IVsJARPackageItem * This,
    /* [full][string][in] */ LPCOLESTR szFilename);


void __RPC_STUB IVsJARPackageItem_put_ItemComment_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsJARPackageItem_get_ItemComment_Proxy( 
    IVsJARPackageItem * This,
    /* [in] */ ULONG cch,
    /* [size_is][out][in] */ OLECHAR rgchBuffer[  ],
    /* [out] */ ULONG *pcchActual);


void __RPC_STUB IVsJARPackageItem_get_ItemComment_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsJARPackageItem_INTERFACE_DEFINED__ */


#ifndef __IVsCABPackageItem_INTERFACE_DEFINED__
#define __IVsCABPackageItem_INTERFACE_DEFINED__

/* interface IVsCABPackageItem */
/* [object][version][uuid] */ 


EXTERN_C const IID IID_IVsCABPackageItem;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5238386b-c56b-11d0-8a49-00a0c91e2acd")
    IVsCABPackageItem : public IVsPackageItem
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE get_StoredFilename( 
            /* [in] */ ULONG cch,
            /* [size_is][out][in] */ OLECHAR rgchBuffer[  ],
            /* [out] */ ULONG *pcchActual) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_CompressionType( 
            /* [out] */ USHORT *pusCompressionType) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsCABPackageItemVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsCABPackageItem * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsCABPackageItem * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsCABPackageItem * This);
        
        HRESULT ( STDMETHODCALLTYPE *get_Filename )( 
            IVsCABPackageItem * This,
            /* [in] */ ULONG cch,
            /* [unique][size_is][out][in] */ OLECHAR rgchBuffer[  ],
            /* [out] */ ULONG *pcchActual);
        
        HRESULT ( STDMETHODCALLTYPE *get_ProjectRelativeFilename )( 
            IVsCABPackageItem * This,
            /* [in] */ ULONG cch,
            /* [unique][size_is][out][in] */ OLECHAR rgchBuffer[  ],
            /* [out] */ ULONG *pcchActual);
        
        HRESULT ( STDMETHODCALLTYPE *get_ItemSource )( 
            IVsCABPackageItem * This,
            /* [in] */ ULONG cch,
            /* [unique][size_is][out][in] */ OLECHAR rgchBuffer[  ],
            /* [out] */ ULONG *pcchActual);
        
        HRESULT ( STDMETHODCALLTYPE *get_StoredFilename )( 
            IVsCABPackageItem * This,
            /* [in] */ ULONG cch,
            /* [size_is][out][in] */ OLECHAR rgchBuffer[  ],
            /* [out] */ ULONG *pcchActual);
        
        HRESULT ( STDMETHODCALLTYPE *get_CompressionType )( 
            IVsCABPackageItem * This,
            /* [out] */ USHORT *pusCompressionType);
        
        END_INTERFACE
    } IVsCABPackageItemVtbl;

    interface IVsCABPackageItem
    {
        CONST_VTBL struct IVsCABPackageItemVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsCABPackageItem_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsCABPackageItem_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsCABPackageItem_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsCABPackageItem_get_Filename(This,cch,rgchBuffer,pcchActual)	\
    (This)->lpVtbl -> get_Filename(This,cch,rgchBuffer,pcchActual)

#define IVsCABPackageItem_get_ProjectRelativeFilename(This,cch,rgchBuffer,pcchActual)	\
    (This)->lpVtbl -> get_ProjectRelativeFilename(This,cch,rgchBuffer,pcchActual)

#define IVsCABPackageItem_get_ItemSource(This,cch,rgchBuffer,pcchActual)	\
    (This)->lpVtbl -> get_ItemSource(This,cch,rgchBuffer,pcchActual)


#define IVsCABPackageItem_get_StoredFilename(This,cch,rgchBuffer,pcchActual)	\
    (This)->lpVtbl -> get_StoredFilename(This,cch,rgchBuffer,pcchActual)

#define IVsCABPackageItem_get_CompressionType(This,pusCompressionType)	\
    (This)->lpVtbl -> get_CompressionType(This,pusCompressionType)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsCABPackageItem_get_StoredFilename_Proxy( 
    IVsCABPackageItem * This,
    /* [in] */ ULONG cch,
    /* [size_is][out][in] */ OLECHAR rgchBuffer[  ],
    /* [out] */ ULONG *pcchActual);


void __RPC_STUB IVsCABPackageItem_get_StoredFilename_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsCABPackageItem_get_CompressionType_Proxy( 
    IVsCABPackageItem * This,
    /* [out] */ USHORT *pusCompressionType);


void __RPC_STUB IVsCABPackageItem_get_CompressionType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsCABPackageItem_INTERFACE_DEFINED__ */


#ifndef __IVsPackagingEngineStatusCallback_INTERFACE_DEFINED__
#define __IVsPackagingEngineStatusCallback_INTERFACE_DEFINED__

/* interface IVsPackagingEngineStatusCallback */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsPackagingEngineStatusCallback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FB61C8EA-A6E4-11d0-8A43-00A0C91E2ACD")
    IVsPackagingEngineStatusCallback : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Tick( 
            /* [unique][out][in] */ BOOL *pfContinue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnPackagingStart( 
            /* [in] */ IVsPackageDescription *pIVsPackageDescription) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnPackagingEnd( 
            /* [in] */ IVsPackageDescription *pIVsPackageDescription,
            /* [in] */ BOOL fSuccessful) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnFileInsertionStart( 
            /* [in] */ IVsPackageItem *pIVsPackageItem,
            /* [out][in] */ BOOL *pfContinue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnFileInsertionProgress( 
            /* [in] */ IVsPackageItem *pIVsPackageItem,
            /* [in] */ ULONG ulProgressMax,
            /* [in] */ ULONG ulProgressCurrent,
            /* [out][in] */ BOOL *pfContinue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnFileInsertionEnd( 
            /* [in] */ IVsPackageItem *pIVsPackageItem,
            /* [out][in] */ BOOL *pfContinue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReportError( 
            /* [unique][in] */ IVsPackageDescription *pIVsPackageDescription,
            /* [unique][in] */ IVsPackageItem *pIVsPackageItem,
            /* [in] */ HRESULT hr,
            /* [in] */ IErrorInfo *pIErrorInfo,
            /* [out][in] */ BOOL *pfContinue) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsPackagingEngineStatusCallbackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsPackagingEngineStatusCallback * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsPackagingEngineStatusCallback * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsPackagingEngineStatusCallback * This);
        
        HRESULT ( STDMETHODCALLTYPE *Tick )( 
            IVsPackagingEngineStatusCallback * This,
            /* [unique][out][in] */ BOOL *pfContinue);
        
        HRESULT ( STDMETHODCALLTYPE *OnPackagingStart )( 
            IVsPackagingEngineStatusCallback * This,
            /* [in] */ IVsPackageDescription *pIVsPackageDescription);
        
        HRESULT ( STDMETHODCALLTYPE *OnPackagingEnd )( 
            IVsPackagingEngineStatusCallback * This,
            /* [in] */ IVsPackageDescription *pIVsPackageDescription,
            /* [in] */ BOOL fSuccessful);
        
        HRESULT ( STDMETHODCALLTYPE *OnFileInsertionStart )( 
            IVsPackagingEngineStatusCallback * This,
            /* [in] */ IVsPackageItem *pIVsPackageItem,
            /* [out][in] */ BOOL *pfContinue);
        
        HRESULT ( STDMETHODCALLTYPE *OnFileInsertionProgress )( 
            IVsPackagingEngineStatusCallback * This,
            /* [in] */ IVsPackageItem *pIVsPackageItem,
            /* [in] */ ULONG ulProgressMax,
            /* [in] */ ULONG ulProgressCurrent,
            /* [out][in] */ BOOL *pfContinue);
        
        HRESULT ( STDMETHODCALLTYPE *OnFileInsertionEnd )( 
            IVsPackagingEngineStatusCallback * This,
            /* [in] */ IVsPackageItem *pIVsPackageItem,
            /* [out][in] */ BOOL *pfContinue);
        
        HRESULT ( STDMETHODCALLTYPE *ReportError )( 
            IVsPackagingEngineStatusCallback * This,
            /* [unique][in] */ IVsPackageDescription *pIVsPackageDescription,
            /* [unique][in] */ IVsPackageItem *pIVsPackageItem,
            /* [in] */ HRESULT hr,
            /* [in] */ IErrorInfo *pIErrorInfo,
            /* [out][in] */ BOOL *pfContinue);
        
        END_INTERFACE
    } IVsPackagingEngineStatusCallbackVtbl;

    interface IVsPackagingEngineStatusCallback
    {
        CONST_VTBL struct IVsPackagingEngineStatusCallbackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsPackagingEngineStatusCallback_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsPackagingEngineStatusCallback_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsPackagingEngineStatusCallback_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsPackagingEngineStatusCallback_Tick(This,pfContinue)	\
    (This)->lpVtbl -> Tick(This,pfContinue)

#define IVsPackagingEngineStatusCallback_OnPackagingStart(This,pIVsPackageDescription)	\
    (This)->lpVtbl -> OnPackagingStart(This,pIVsPackageDescription)

#define IVsPackagingEngineStatusCallback_OnPackagingEnd(This,pIVsPackageDescription,fSuccessful)	\
    (This)->lpVtbl -> OnPackagingEnd(This,pIVsPackageDescription,fSuccessful)

#define IVsPackagingEngineStatusCallback_OnFileInsertionStart(This,pIVsPackageItem,pfContinue)	\
    (This)->lpVtbl -> OnFileInsertionStart(This,pIVsPackageItem,pfContinue)

#define IVsPackagingEngineStatusCallback_OnFileInsertionProgress(This,pIVsPackageItem,ulProgressMax,ulProgressCurrent,pfContinue)	\
    (This)->lpVtbl -> OnFileInsertionProgress(This,pIVsPackageItem,ulProgressMax,ulProgressCurrent,pfContinue)

#define IVsPackagingEngineStatusCallback_OnFileInsertionEnd(This,pIVsPackageItem,pfContinue)	\
    (This)->lpVtbl -> OnFileInsertionEnd(This,pIVsPackageItem,pfContinue)

#define IVsPackagingEngineStatusCallback_ReportError(This,pIVsPackageDescription,pIVsPackageItem,hr,pIErrorInfo,pfContinue)	\
    (This)->lpVtbl -> ReportError(This,pIVsPackageDescription,pIVsPackageItem,hr,pIErrorInfo,pfContinue)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsPackagingEngineStatusCallback_Tick_Proxy( 
    IVsPackagingEngineStatusCallback * This,
    /* [unique][out][in] */ BOOL *pfContinue);


void __RPC_STUB IVsPackagingEngineStatusCallback_Tick_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingEngineStatusCallback_OnPackagingStart_Proxy( 
    IVsPackagingEngineStatusCallback * This,
    /* [in] */ IVsPackageDescription *pIVsPackageDescription);


void __RPC_STUB IVsPackagingEngineStatusCallback_OnPackagingStart_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingEngineStatusCallback_OnPackagingEnd_Proxy( 
    IVsPackagingEngineStatusCallback * This,
    /* [in] */ IVsPackageDescription *pIVsPackageDescription,
    /* [in] */ BOOL fSuccessful);


void __RPC_STUB IVsPackagingEngineStatusCallback_OnPackagingEnd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingEngineStatusCallback_OnFileInsertionStart_Proxy( 
    IVsPackagingEngineStatusCallback * This,
    /* [in] */ IVsPackageItem *pIVsPackageItem,
    /* [out][in] */ BOOL *pfContinue);


void __RPC_STUB IVsPackagingEngineStatusCallback_OnFileInsertionStart_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingEngineStatusCallback_OnFileInsertionProgress_Proxy( 
    IVsPackagingEngineStatusCallback * This,
    /* [in] */ IVsPackageItem *pIVsPackageItem,
    /* [in] */ ULONG ulProgressMax,
    /* [in] */ ULONG ulProgressCurrent,
    /* [out][in] */ BOOL *pfContinue);


void __RPC_STUB IVsPackagingEngineStatusCallback_OnFileInsertionProgress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingEngineStatusCallback_OnFileInsertionEnd_Proxy( 
    IVsPackagingEngineStatusCallback * This,
    /* [in] */ IVsPackageItem *pIVsPackageItem,
    /* [out][in] */ BOOL *pfContinue);


void __RPC_STUB IVsPackagingEngineStatusCallback_OnFileInsertionEnd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingEngineStatusCallback_ReportError_Proxy( 
    IVsPackagingEngineStatusCallback * This,
    /* [unique][in] */ IVsPackageDescription *pIVsPackageDescription,
    /* [unique][in] */ IVsPackageItem *pIVsPackageItem,
    /* [in] */ HRESULT hr,
    /* [in] */ IErrorInfo *pIErrorInfo,
    /* [out][in] */ BOOL *pfContinue);


void __RPC_STUB IVsPackagingEngineStatusCallback_ReportError_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsPackagingEngineStatusCallback_INTERFACE_DEFINED__ */


#ifndef __IVsCABPackagingEngineStatusCallback_INTERFACE_DEFINED__
#define __IVsCABPackagingEngineStatusCallback_INTERFACE_DEFINED__

/* interface IVsCABPackagingEngineStatusCallback */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsCABPackagingEngineStatusCallback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("52383875-c56b-11d0-8a49-00a0c91e2acd")
    IVsCABPackagingEngineStatusCallback : public IVsPackagingEngineStatusCallback
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnFileInsertionStatus( 
            /* [in] */ IVsPackageItem *pIVsPackageItem,
            /* [in] */ ULONG ulCompressedBlockSize,
            /* [in] */ ULONG ulUncompressedBlockSize,
            /* [out][in] */ BOOL *pfContinue) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsCABPackagingEngineStatusCallbackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsCABPackagingEngineStatusCallback * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsCABPackagingEngineStatusCallback * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsCABPackagingEngineStatusCallback * This);
        
        HRESULT ( STDMETHODCALLTYPE *Tick )( 
            IVsCABPackagingEngineStatusCallback * This,
            /* [unique][out][in] */ BOOL *pfContinue);
        
        HRESULT ( STDMETHODCALLTYPE *OnPackagingStart )( 
            IVsCABPackagingEngineStatusCallback * This,
            /* [in] */ IVsPackageDescription *pIVsPackageDescription);
        
        HRESULT ( STDMETHODCALLTYPE *OnPackagingEnd )( 
            IVsCABPackagingEngineStatusCallback * This,
            /* [in] */ IVsPackageDescription *pIVsPackageDescription,
            /* [in] */ BOOL fSuccessful);
        
        HRESULT ( STDMETHODCALLTYPE *OnFileInsertionStart )( 
            IVsCABPackagingEngineStatusCallback * This,
            /* [in] */ IVsPackageItem *pIVsPackageItem,
            /* [out][in] */ BOOL *pfContinue);
        
        HRESULT ( STDMETHODCALLTYPE *OnFileInsertionProgress )( 
            IVsCABPackagingEngineStatusCallback * This,
            /* [in] */ IVsPackageItem *pIVsPackageItem,
            /* [in] */ ULONG ulProgressMax,
            /* [in] */ ULONG ulProgressCurrent,
            /* [out][in] */ BOOL *pfContinue);
        
        HRESULT ( STDMETHODCALLTYPE *OnFileInsertionEnd )( 
            IVsCABPackagingEngineStatusCallback * This,
            /* [in] */ IVsPackageItem *pIVsPackageItem,
            /* [out][in] */ BOOL *pfContinue);
        
        HRESULT ( STDMETHODCALLTYPE *ReportError )( 
            IVsCABPackagingEngineStatusCallback * This,
            /* [unique][in] */ IVsPackageDescription *pIVsPackageDescription,
            /* [unique][in] */ IVsPackageItem *pIVsPackageItem,
            /* [in] */ HRESULT hr,
            /* [in] */ IErrorInfo *pIErrorInfo,
            /* [out][in] */ BOOL *pfContinue);
        
        HRESULT ( STDMETHODCALLTYPE *OnFileInsertionStatus )( 
            IVsCABPackagingEngineStatusCallback * This,
            /* [in] */ IVsPackageItem *pIVsPackageItem,
            /* [in] */ ULONG ulCompressedBlockSize,
            /* [in] */ ULONG ulUncompressedBlockSize,
            /* [out][in] */ BOOL *pfContinue);
        
        END_INTERFACE
    } IVsCABPackagingEngineStatusCallbackVtbl;

    interface IVsCABPackagingEngineStatusCallback
    {
        CONST_VTBL struct IVsCABPackagingEngineStatusCallbackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsCABPackagingEngineStatusCallback_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsCABPackagingEngineStatusCallback_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsCABPackagingEngineStatusCallback_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsCABPackagingEngineStatusCallback_Tick(This,pfContinue)	\
    (This)->lpVtbl -> Tick(This,pfContinue)

#define IVsCABPackagingEngineStatusCallback_OnPackagingStart(This,pIVsPackageDescription)	\
    (This)->lpVtbl -> OnPackagingStart(This,pIVsPackageDescription)

#define IVsCABPackagingEngineStatusCallback_OnPackagingEnd(This,pIVsPackageDescription,fSuccessful)	\
    (This)->lpVtbl -> OnPackagingEnd(This,pIVsPackageDescription,fSuccessful)

#define IVsCABPackagingEngineStatusCallback_OnFileInsertionStart(This,pIVsPackageItem,pfContinue)	\
    (This)->lpVtbl -> OnFileInsertionStart(This,pIVsPackageItem,pfContinue)

#define IVsCABPackagingEngineStatusCallback_OnFileInsertionProgress(This,pIVsPackageItem,ulProgressMax,ulProgressCurrent,pfContinue)	\
    (This)->lpVtbl -> OnFileInsertionProgress(This,pIVsPackageItem,ulProgressMax,ulProgressCurrent,pfContinue)

#define IVsCABPackagingEngineStatusCallback_OnFileInsertionEnd(This,pIVsPackageItem,pfContinue)	\
    (This)->lpVtbl -> OnFileInsertionEnd(This,pIVsPackageItem,pfContinue)

#define IVsCABPackagingEngineStatusCallback_ReportError(This,pIVsPackageDescription,pIVsPackageItem,hr,pIErrorInfo,pfContinue)	\
    (This)->lpVtbl -> ReportError(This,pIVsPackageDescription,pIVsPackageItem,hr,pIErrorInfo,pfContinue)


#define IVsCABPackagingEngineStatusCallback_OnFileInsertionStatus(This,pIVsPackageItem,ulCompressedBlockSize,ulUncompressedBlockSize,pfContinue)	\
    (This)->lpVtbl -> OnFileInsertionStatus(This,pIVsPackageItem,ulCompressedBlockSize,ulUncompressedBlockSize,pfContinue)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsCABPackagingEngineStatusCallback_OnFileInsertionStatus_Proxy( 
    IVsCABPackagingEngineStatusCallback * This,
    /* [in] */ IVsPackageItem *pIVsPackageItem,
    /* [in] */ ULONG ulCompressedBlockSize,
    /* [in] */ ULONG ulUncompressedBlockSize,
    /* [out][in] */ BOOL *pfContinue);


void __RPC_STUB IVsCABPackagingEngineStatusCallback_OnFileInsertionStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsCABPackagingEngineStatusCallback_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vspkg_0688 */
/* [local] */ 

extern const __declspec(selectany) GUID CATID_VS_PACKAGING_ENGINE  = { /* 707d11b3-91ca-11d2-8a3e-00a0c91e2acd */
	   0x707d11b3,
	   0x91ca,
	   0x11d2,
	   {0x8a, 0x3e, 0x00, 0xa0, 0xc9, 0x1e, 0x2a, 0xcd}
	 };


extern RPC_IF_HANDLE __MIDL_itf_vspkg_0688_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vspkg_0688_v0_0_s_ifspec;

#ifndef __IVsPackagingEngine_INTERFACE_DEFINED__
#define __IVsPackagingEngine_INTERFACE_DEFINED__

/* interface IVsPackagingEngine */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsPackagingEngine;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FB61C8E9-A6E4-11d0-8A43-00A0C91E2ACD")
    IVsPackagingEngine : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE put_PackageDescription( 
            /* [in] */ IVsPackageDescription *pIVsPackageDescription) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_PackageDescription( 
            /* [out] */ IVsPackageDescription **ppIVsPackageDescription) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_OutputFilename( 
            /* [full][string][in] */ LPCOLESTR szFilename) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_OutputFilename( 
            /* [in] */ ULONG cch,
            /* [size_is][out][in] */ OLECHAR rgchBuffer[  ],
            /* [out] */ ULONG *pcchActual) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AdvisePackagingEngineStatusCallback( 
            /* [in] */ IVsPackagingEngineStatusCallback *pIVsPackagingEngineStatusCallback,
            /* [out] */ VSCOOKIE *pdwCookie) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnadvisePackagingEngineStatusCallback( 
            /* [in] */ VSCOOKIE dwCookie) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Start( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryStatus( 
            /* [out] */ BOOL *pfDone) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Stop( 
            /* [in] */ BOOL fSync) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Wait( 
            /* [in] */ DWORD dwMilliseconds,
            /* [in] */ BOOL fTickOnMessages) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsPackagingEngineVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsPackagingEngine * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsPackagingEngine * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsPackagingEngine * This);
        
        HRESULT ( STDMETHODCALLTYPE *put_PackageDescription )( 
            IVsPackagingEngine * This,
            /* [in] */ IVsPackageDescription *pIVsPackageDescription);
        
        HRESULT ( STDMETHODCALLTYPE *get_PackageDescription )( 
            IVsPackagingEngine * This,
            /* [out] */ IVsPackageDescription **ppIVsPackageDescription);
        
        HRESULT ( STDMETHODCALLTYPE *put_OutputFilename )( 
            IVsPackagingEngine * This,
            /* [full][string][in] */ LPCOLESTR szFilename);
        
        HRESULT ( STDMETHODCALLTYPE *get_OutputFilename )( 
            IVsPackagingEngine * This,
            /* [in] */ ULONG cch,
            /* [size_is][out][in] */ OLECHAR rgchBuffer[  ],
            /* [out] */ ULONG *pcchActual);
        
        HRESULT ( STDMETHODCALLTYPE *AdvisePackagingEngineStatusCallback )( 
            IVsPackagingEngine * This,
            /* [in] */ IVsPackagingEngineStatusCallback *pIVsPackagingEngineStatusCallback,
            /* [out] */ VSCOOKIE *pdwCookie);
        
        HRESULT ( STDMETHODCALLTYPE *UnadvisePackagingEngineStatusCallback )( 
            IVsPackagingEngine * This,
            /* [in] */ VSCOOKIE dwCookie);
        
        HRESULT ( STDMETHODCALLTYPE *Start )( 
            IVsPackagingEngine * This);
        
        HRESULT ( STDMETHODCALLTYPE *QueryStatus )( 
            IVsPackagingEngine * This,
            /* [out] */ BOOL *pfDone);
        
        HRESULT ( STDMETHODCALLTYPE *Stop )( 
            IVsPackagingEngine * This,
            /* [in] */ BOOL fSync);
        
        HRESULT ( STDMETHODCALLTYPE *Wait )( 
            IVsPackagingEngine * This,
            /* [in] */ DWORD dwMilliseconds,
            /* [in] */ BOOL fTickOnMessages);
        
        END_INTERFACE
    } IVsPackagingEngineVtbl;

    interface IVsPackagingEngine
    {
        CONST_VTBL struct IVsPackagingEngineVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsPackagingEngine_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsPackagingEngine_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsPackagingEngine_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsPackagingEngine_put_PackageDescription(This,pIVsPackageDescription)	\
    (This)->lpVtbl -> put_PackageDescription(This,pIVsPackageDescription)

#define IVsPackagingEngine_get_PackageDescription(This,ppIVsPackageDescription)	\
    (This)->lpVtbl -> get_PackageDescription(This,ppIVsPackageDescription)

#define IVsPackagingEngine_put_OutputFilename(This,szFilename)	\
    (This)->lpVtbl -> put_OutputFilename(This,szFilename)

#define IVsPackagingEngine_get_OutputFilename(This,cch,rgchBuffer,pcchActual)	\
    (This)->lpVtbl -> get_OutputFilename(This,cch,rgchBuffer,pcchActual)

#define IVsPackagingEngine_AdvisePackagingEngineStatusCallback(This,pIVsPackagingEngineStatusCallback,pdwCookie)	\
    (This)->lpVtbl -> AdvisePackagingEngineStatusCallback(This,pIVsPackagingEngineStatusCallback,pdwCookie)

#define IVsPackagingEngine_UnadvisePackagingEngineStatusCallback(This,dwCookie)	\
    (This)->lpVtbl -> UnadvisePackagingEngineStatusCallback(This,dwCookie)

#define IVsPackagingEngine_Start(This)	\
    (This)->lpVtbl -> Start(This)

#define IVsPackagingEngine_QueryStatus(This,pfDone)	\
    (This)->lpVtbl -> QueryStatus(This,pfDone)

#define IVsPackagingEngine_Stop(This,fSync)	\
    (This)->lpVtbl -> Stop(This,fSync)

#define IVsPackagingEngine_Wait(This,dwMilliseconds,fTickOnMessages)	\
    (This)->lpVtbl -> Wait(This,dwMilliseconds,fTickOnMessages)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsPackagingEngine_put_PackageDescription_Proxy( 
    IVsPackagingEngine * This,
    /* [in] */ IVsPackageDescription *pIVsPackageDescription);


void __RPC_STUB IVsPackagingEngine_put_PackageDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingEngine_get_PackageDescription_Proxy( 
    IVsPackagingEngine * This,
    /* [out] */ IVsPackageDescription **ppIVsPackageDescription);


void __RPC_STUB IVsPackagingEngine_get_PackageDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingEngine_put_OutputFilename_Proxy( 
    IVsPackagingEngine * This,
    /* [full][string][in] */ LPCOLESTR szFilename);


void __RPC_STUB IVsPackagingEngine_put_OutputFilename_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingEngine_get_OutputFilename_Proxy( 
    IVsPackagingEngine * This,
    /* [in] */ ULONG cch,
    /* [size_is][out][in] */ OLECHAR rgchBuffer[  ],
    /* [out] */ ULONG *pcchActual);


void __RPC_STUB IVsPackagingEngine_get_OutputFilename_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingEngine_AdvisePackagingEngineStatusCallback_Proxy( 
    IVsPackagingEngine * This,
    /* [in] */ IVsPackagingEngineStatusCallback *pIVsPackagingEngineStatusCallback,
    /* [out] */ VSCOOKIE *pdwCookie);


void __RPC_STUB IVsPackagingEngine_AdvisePackagingEngineStatusCallback_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingEngine_UnadvisePackagingEngineStatusCallback_Proxy( 
    IVsPackagingEngine * This,
    /* [in] */ VSCOOKIE dwCookie);


void __RPC_STUB IVsPackagingEngine_UnadvisePackagingEngineStatusCallback_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingEngine_Start_Proxy( 
    IVsPackagingEngine * This);


void __RPC_STUB IVsPackagingEngine_Start_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingEngine_QueryStatus_Proxy( 
    IVsPackagingEngine * This,
    /* [out] */ BOOL *pfDone);


void __RPC_STUB IVsPackagingEngine_QueryStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingEngine_Stop_Proxy( 
    IVsPackagingEngine * This,
    /* [in] */ BOOL fSync);


void __RPC_STUB IVsPackagingEngine_Stop_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingEngine_Wait_Proxy( 
    IVsPackagingEngine * This,
    /* [in] */ DWORD dwMilliseconds,
    /* [in] */ BOOL fTickOnMessages);


void __RPC_STUB IVsPackagingEngine_Wait_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsPackagingEngine_INTERFACE_DEFINED__ */


#ifndef __IVsCABPackagingEngine_INTERFACE_DEFINED__
#define __IVsCABPackagingEngine_INTERFACE_DEFINED__

/* interface IVsCABPackagingEngine */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsCABPackagingEngine;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("52383876-c56b-11d0-8a49-00a0c91e2acd")
    IVsCABPackagingEngine : public IVsPackagingEngine
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AdviseCABPackagingEngineStatusCallback( 
            /* [in] */ IVsCABPackagingEngineStatusCallback *pIVsCABPackagingEngineStatusCallback,
            /* [out] */ VSCOOKIE *pdwCookie) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnadviseCABPackagingEngineStatusCallback( 
            /* [in] */ VSCOOKIE dwCookie) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsCABPackagingEngineVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsCABPackagingEngine * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsCABPackagingEngine * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsCABPackagingEngine * This);
        
        HRESULT ( STDMETHODCALLTYPE *put_PackageDescription )( 
            IVsCABPackagingEngine * This,
            /* [in] */ IVsPackageDescription *pIVsPackageDescription);
        
        HRESULT ( STDMETHODCALLTYPE *get_PackageDescription )( 
            IVsCABPackagingEngine * This,
            /* [out] */ IVsPackageDescription **ppIVsPackageDescription);
        
        HRESULT ( STDMETHODCALLTYPE *put_OutputFilename )( 
            IVsCABPackagingEngine * This,
            /* [full][string][in] */ LPCOLESTR szFilename);
        
        HRESULT ( STDMETHODCALLTYPE *get_OutputFilename )( 
            IVsCABPackagingEngine * This,
            /* [in] */ ULONG cch,
            /* [size_is][out][in] */ OLECHAR rgchBuffer[  ],
            /* [out] */ ULONG *pcchActual);
        
        HRESULT ( STDMETHODCALLTYPE *AdvisePackagingEngineStatusCallback )( 
            IVsCABPackagingEngine * This,
            /* [in] */ IVsPackagingEngineStatusCallback *pIVsPackagingEngineStatusCallback,
            /* [out] */ VSCOOKIE *pdwCookie);
        
        HRESULT ( STDMETHODCALLTYPE *UnadvisePackagingEngineStatusCallback )( 
            IVsCABPackagingEngine * This,
            /* [in] */ VSCOOKIE dwCookie);
        
        HRESULT ( STDMETHODCALLTYPE *Start )( 
            IVsCABPackagingEngine * This);
        
        HRESULT ( STDMETHODCALLTYPE *QueryStatus )( 
            IVsCABPackagingEngine * This,
            /* [out] */ BOOL *pfDone);
        
        HRESULT ( STDMETHODCALLTYPE *Stop )( 
            IVsCABPackagingEngine * This,
            /* [in] */ BOOL fSync);
        
        HRESULT ( STDMETHODCALLTYPE *Wait )( 
            IVsCABPackagingEngine * This,
            /* [in] */ DWORD dwMilliseconds,
            /* [in] */ BOOL fTickOnMessages);
        
        HRESULT ( STDMETHODCALLTYPE *AdviseCABPackagingEngineStatusCallback )( 
            IVsCABPackagingEngine * This,
            /* [in] */ IVsCABPackagingEngineStatusCallback *pIVsCABPackagingEngineStatusCallback,
            /* [out] */ VSCOOKIE *pdwCookie);
        
        HRESULT ( STDMETHODCALLTYPE *UnadviseCABPackagingEngineStatusCallback )( 
            IVsCABPackagingEngine * This,
            /* [in] */ VSCOOKIE dwCookie);
        
        END_INTERFACE
    } IVsCABPackagingEngineVtbl;

    interface IVsCABPackagingEngine
    {
        CONST_VTBL struct IVsCABPackagingEngineVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsCABPackagingEngine_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsCABPackagingEngine_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsCABPackagingEngine_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsCABPackagingEngine_put_PackageDescription(This,pIVsPackageDescription)	\
    (This)->lpVtbl -> put_PackageDescription(This,pIVsPackageDescription)

#define IVsCABPackagingEngine_get_PackageDescription(This,ppIVsPackageDescription)	\
    (This)->lpVtbl -> get_PackageDescription(This,ppIVsPackageDescription)

#define IVsCABPackagingEngine_put_OutputFilename(This,szFilename)	\
    (This)->lpVtbl -> put_OutputFilename(This,szFilename)

#define IVsCABPackagingEngine_get_OutputFilename(This,cch,rgchBuffer,pcchActual)	\
    (This)->lpVtbl -> get_OutputFilename(This,cch,rgchBuffer,pcchActual)

#define IVsCABPackagingEngine_AdvisePackagingEngineStatusCallback(This,pIVsPackagingEngineStatusCallback,pdwCookie)	\
    (This)->lpVtbl -> AdvisePackagingEngineStatusCallback(This,pIVsPackagingEngineStatusCallback,pdwCookie)

#define IVsCABPackagingEngine_UnadvisePackagingEngineStatusCallback(This,dwCookie)	\
    (This)->lpVtbl -> UnadvisePackagingEngineStatusCallback(This,dwCookie)

#define IVsCABPackagingEngine_Start(This)	\
    (This)->lpVtbl -> Start(This)

#define IVsCABPackagingEngine_QueryStatus(This,pfDone)	\
    (This)->lpVtbl -> QueryStatus(This,pfDone)

#define IVsCABPackagingEngine_Stop(This,fSync)	\
    (This)->lpVtbl -> Stop(This,fSync)

#define IVsCABPackagingEngine_Wait(This,dwMilliseconds,fTickOnMessages)	\
    (This)->lpVtbl -> Wait(This,dwMilliseconds,fTickOnMessages)


#define IVsCABPackagingEngine_AdviseCABPackagingEngineStatusCallback(This,pIVsCABPackagingEngineStatusCallback,pdwCookie)	\
    (This)->lpVtbl -> AdviseCABPackagingEngineStatusCallback(This,pIVsCABPackagingEngineStatusCallback,pdwCookie)

#define IVsCABPackagingEngine_UnadviseCABPackagingEngineStatusCallback(This,dwCookie)	\
    (This)->lpVtbl -> UnadviseCABPackagingEngineStatusCallback(This,dwCookie)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsCABPackagingEngine_AdviseCABPackagingEngineStatusCallback_Proxy( 
    IVsCABPackagingEngine * This,
    /* [in] */ IVsCABPackagingEngineStatusCallback *pIVsCABPackagingEngineStatusCallback,
    /* [out] */ VSCOOKIE *pdwCookie);


void __RPC_STUB IVsCABPackagingEngine_AdviseCABPackagingEngineStatusCallback_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsCABPackagingEngine_UnadviseCABPackagingEngineStatusCallback_Proxy( 
    IVsCABPackagingEngine * This,
    /* [in] */ VSCOOKIE dwCookie);


void __RPC_STUB IVsCABPackagingEngine_UnadviseCABPackagingEngineStatusCallback_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsCABPackagingEngine_INTERFACE_DEFINED__ */


#ifndef __IVsPackageExplorerStatusCallback_INTERFACE_DEFINED__
#define __IVsPackageExplorerStatusCallback_INTERFACE_DEFINED__

/* interface IVsPackageExplorerStatusCallback */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsPackageExplorerStatusCallback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("52383862-c56b-11d0-8a49-00a0c91e2acd")
    IVsPackageExplorerStatusCallback : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Tick( 
            /* [out][in] */ BOOL *pfContinue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnOpenedPackage( 
            /* [in] */ LPCOLESTR szFile,
            /* [out][in] */ BOOL *pfContinue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnClosedPackage( 
            /* [in] */ LPCOLESTR szFile,
            /* [in] */ BOOL fSuccess) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnNextPackageItem( 
            /* [in] */ LPCOLESTR szItemName,
            /* [out][in] */ BOOL *pfExtract,
            /* [out][in] */ BOOL *pfContinue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PackageItemProgress( 
            /* [in] */ LPCOLESTR szItemName,
            /* [in] */ ULONG ulProgressCurrent,
            /* [in] */ ULONG ulProgressMaximum,
            /* [out][in] */ BOOL *pfContinue) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsPackageExplorerStatusCallbackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsPackageExplorerStatusCallback * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsPackageExplorerStatusCallback * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsPackageExplorerStatusCallback * This);
        
        HRESULT ( STDMETHODCALLTYPE *Tick )( 
            IVsPackageExplorerStatusCallback * This,
            /* [out][in] */ BOOL *pfContinue);
        
        HRESULT ( STDMETHODCALLTYPE *OnOpenedPackage )( 
            IVsPackageExplorerStatusCallback * This,
            /* [in] */ LPCOLESTR szFile,
            /* [out][in] */ BOOL *pfContinue);
        
        HRESULT ( STDMETHODCALLTYPE *OnClosedPackage )( 
            IVsPackageExplorerStatusCallback * This,
            /* [in] */ LPCOLESTR szFile,
            /* [in] */ BOOL fSuccess);
        
        HRESULT ( STDMETHODCALLTYPE *OnNextPackageItem )( 
            IVsPackageExplorerStatusCallback * This,
            /* [in] */ LPCOLESTR szItemName,
            /* [out][in] */ BOOL *pfExtract,
            /* [out][in] */ BOOL *pfContinue);
        
        HRESULT ( STDMETHODCALLTYPE *PackageItemProgress )( 
            IVsPackageExplorerStatusCallback * This,
            /* [in] */ LPCOLESTR szItemName,
            /* [in] */ ULONG ulProgressCurrent,
            /* [in] */ ULONG ulProgressMaximum,
            /* [out][in] */ BOOL *pfContinue);
        
        END_INTERFACE
    } IVsPackageExplorerStatusCallbackVtbl;

    interface IVsPackageExplorerStatusCallback
    {
        CONST_VTBL struct IVsPackageExplorerStatusCallbackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsPackageExplorerStatusCallback_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsPackageExplorerStatusCallback_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsPackageExplorerStatusCallback_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsPackageExplorerStatusCallback_Tick(This,pfContinue)	\
    (This)->lpVtbl -> Tick(This,pfContinue)

#define IVsPackageExplorerStatusCallback_OnOpenedPackage(This,szFile,pfContinue)	\
    (This)->lpVtbl -> OnOpenedPackage(This,szFile,pfContinue)

#define IVsPackageExplorerStatusCallback_OnClosedPackage(This,szFile,fSuccess)	\
    (This)->lpVtbl -> OnClosedPackage(This,szFile,fSuccess)

#define IVsPackageExplorerStatusCallback_OnNextPackageItem(This,szItemName,pfExtract,pfContinue)	\
    (This)->lpVtbl -> OnNextPackageItem(This,szItemName,pfExtract,pfContinue)

#define IVsPackageExplorerStatusCallback_PackageItemProgress(This,szItemName,ulProgressCurrent,ulProgressMaximum,pfContinue)	\
    (This)->lpVtbl -> PackageItemProgress(This,szItemName,ulProgressCurrent,ulProgressMaximum,pfContinue)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsPackageExplorerStatusCallback_Tick_Proxy( 
    IVsPackageExplorerStatusCallback * This,
    /* [out][in] */ BOOL *pfContinue);


void __RPC_STUB IVsPackageExplorerStatusCallback_Tick_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackageExplorerStatusCallback_OnOpenedPackage_Proxy( 
    IVsPackageExplorerStatusCallback * This,
    /* [in] */ LPCOLESTR szFile,
    /* [out][in] */ BOOL *pfContinue);


void __RPC_STUB IVsPackageExplorerStatusCallback_OnOpenedPackage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackageExplorerStatusCallback_OnClosedPackage_Proxy( 
    IVsPackageExplorerStatusCallback * This,
    /* [in] */ LPCOLESTR szFile,
    /* [in] */ BOOL fSuccess);


void __RPC_STUB IVsPackageExplorerStatusCallback_OnClosedPackage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackageExplorerStatusCallback_OnNextPackageItem_Proxy( 
    IVsPackageExplorerStatusCallback * This,
    /* [in] */ LPCOLESTR szItemName,
    /* [out][in] */ BOOL *pfExtract,
    /* [out][in] */ BOOL *pfContinue);


void __RPC_STUB IVsPackageExplorerStatusCallback_OnNextPackageItem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackageExplorerStatusCallback_PackageItemProgress_Proxy( 
    IVsPackageExplorerStatusCallback * This,
    /* [in] */ LPCOLESTR szItemName,
    /* [in] */ ULONG ulProgressCurrent,
    /* [in] */ ULONG ulProgressMaximum,
    /* [out][in] */ BOOL *pfContinue);


void __RPC_STUB IVsPackageExplorerStatusCallback_PackageItemProgress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsPackageExplorerStatusCallback_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vspkg_0691 */
/* [local] */ 

extern const __declspec(selectany) GUID CATID_VS_PACKAGE_EXPLORER  = { /* 707d11b2-91ca-11d0-8a3e-00a0c91e2acd */
	   0x707d11b2,
	   0x91ca,
	   0x11d0,
	   {0x8a, 0x3e, 0x00, 0xa0, 0xc9, 0x1e, 0x2a, 0xcd}
	 };


extern RPC_IF_HANDLE __MIDL_itf_vspkg_0691_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vspkg_0691_v0_0_s_ifspec;

#ifndef __IVsPackageExplorer_INTERFACE_DEFINED__
#define __IVsPackageExplorer_INTERFACE_DEFINED__

/* interface IVsPackageExplorer */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsPackageExplorer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("52383863-c56b-11d0-8a49-00a0c91e2acd")
    IVsPackageExplorer : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE put_InputFile( 
            /* [in] */ LPCOLESTR szFileName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_InputFile( 
            /* [in] */ ULONG cch,
            /* [size_is][out][in] */ OLECHAR rgchBuffer[  ],
            /* [out] */ ULONG *pcchActual) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_OutputRoot( 
            /* [in] */ LPCOLESTR szOutputRoot) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_OutputRoot( 
            /* [in] */ ULONG cch,
            /* [size_is][out][in] */ OLECHAR rgchBuffer[  ],
            /* [out] */ ULONG *pcchActual) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AdvisePackageExplorerStatusCallback( 
            /* [in] */ IVsPackageExplorerStatusCallback *pIVsPackageExplorerStatusCallback,
            /* [out] */ VSCOOKIE *pdwCookie) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnadvisePackageExplorerStatusCallback( 
            /* [in] */ VSCOOKIE dwCookie) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Start( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryStatus( 
            /* [out] */ BOOL *pfDone) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Stop( 
            /* [in] */ BOOL fSync) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Wait( 
            /* [in] */ DWORD dwMilliseconds,
            BOOL fTickOnMessage) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsPackageExplorerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsPackageExplorer * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsPackageExplorer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsPackageExplorer * This);
        
        HRESULT ( STDMETHODCALLTYPE *put_InputFile )( 
            IVsPackageExplorer * This,
            /* [in] */ LPCOLESTR szFileName);
        
        HRESULT ( STDMETHODCALLTYPE *get_InputFile )( 
            IVsPackageExplorer * This,
            /* [in] */ ULONG cch,
            /* [size_is][out][in] */ OLECHAR rgchBuffer[  ],
            /* [out] */ ULONG *pcchActual);
        
        HRESULT ( STDMETHODCALLTYPE *put_OutputRoot )( 
            IVsPackageExplorer * This,
            /* [in] */ LPCOLESTR szOutputRoot);
        
        HRESULT ( STDMETHODCALLTYPE *get_OutputRoot )( 
            IVsPackageExplorer * This,
            /* [in] */ ULONG cch,
            /* [size_is][out][in] */ OLECHAR rgchBuffer[  ],
            /* [out] */ ULONG *pcchActual);
        
        HRESULT ( STDMETHODCALLTYPE *AdvisePackageExplorerStatusCallback )( 
            IVsPackageExplorer * This,
            /* [in] */ IVsPackageExplorerStatusCallback *pIVsPackageExplorerStatusCallback,
            /* [out] */ VSCOOKIE *pdwCookie);
        
        HRESULT ( STDMETHODCALLTYPE *UnadvisePackageExplorerStatusCallback )( 
            IVsPackageExplorer * This,
            /* [in] */ VSCOOKIE dwCookie);
        
        HRESULT ( STDMETHODCALLTYPE *Start )( 
            IVsPackageExplorer * This);
        
        HRESULT ( STDMETHODCALLTYPE *QueryStatus )( 
            IVsPackageExplorer * This,
            /* [out] */ BOOL *pfDone);
        
        HRESULT ( STDMETHODCALLTYPE *Stop )( 
            IVsPackageExplorer * This,
            /* [in] */ BOOL fSync);
        
        HRESULT ( STDMETHODCALLTYPE *Wait )( 
            IVsPackageExplorer * This,
            /* [in] */ DWORD dwMilliseconds,
            BOOL fTickOnMessage);
        
        END_INTERFACE
    } IVsPackageExplorerVtbl;

    interface IVsPackageExplorer
    {
        CONST_VTBL struct IVsPackageExplorerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsPackageExplorer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsPackageExplorer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsPackageExplorer_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsPackageExplorer_put_InputFile(This,szFileName)	\
    (This)->lpVtbl -> put_InputFile(This,szFileName)

#define IVsPackageExplorer_get_InputFile(This,cch,rgchBuffer,pcchActual)	\
    (This)->lpVtbl -> get_InputFile(This,cch,rgchBuffer,pcchActual)

#define IVsPackageExplorer_put_OutputRoot(This,szOutputRoot)	\
    (This)->lpVtbl -> put_OutputRoot(This,szOutputRoot)

#define IVsPackageExplorer_get_OutputRoot(This,cch,rgchBuffer,pcchActual)	\
    (This)->lpVtbl -> get_OutputRoot(This,cch,rgchBuffer,pcchActual)

#define IVsPackageExplorer_AdvisePackageExplorerStatusCallback(This,pIVsPackageExplorerStatusCallback,pdwCookie)	\
    (This)->lpVtbl -> AdvisePackageExplorerStatusCallback(This,pIVsPackageExplorerStatusCallback,pdwCookie)

#define IVsPackageExplorer_UnadvisePackageExplorerStatusCallback(This,dwCookie)	\
    (This)->lpVtbl -> UnadvisePackageExplorerStatusCallback(This,dwCookie)

#define IVsPackageExplorer_Start(This)	\
    (This)->lpVtbl -> Start(This)

#define IVsPackageExplorer_QueryStatus(This,pfDone)	\
    (This)->lpVtbl -> QueryStatus(This,pfDone)

#define IVsPackageExplorer_Stop(This,fSync)	\
    (This)->lpVtbl -> Stop(This,fSync)

#define IVsPackageExplorer_Wait(This,dwMilliseconds,fTickOnMessage)	\
    (This)->lpVtbl -> Wait(This,dwMilliseconds,fTickOnMessage)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsPackageExplorer_put_InputFile_Proxy( 
    IVsPackageExplorer * This,
    /* [in] */ LPCOLESTR szFileName);


void __RPC_STUB IVsPackageExplorer_put_InputFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackageExplorer_get_InputFile_Proxy( 
    IVsPackageExplorer * This,
    /* [in] */ ULONG cch,
    /* [size_is][out][in] */ OLECHAR rgchBuffer[  ],
    /* [out] */ ULONG *pcchActual);


void __RPC_STUB IVsPackageExplorer_get_InputFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackageExplorer_put_OutputRoot_Proxy( 
    IVsPackageExplorer * This,
    /* [in] */ LPCOLESTR szOutputRoot);


void __RPC_STUB IVsPackageExplorer_put_OutputRoot_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackageExplorer_get_OutputRoot_Proxy( 
    IVsPackageExplorer * This,
    /* [in] */ ULONG cch,
    /* [size_is][out][in] */ OLECHAR rgchBuffer[  ],
    /* [out] */ ULONG *pcchActual);


void __RPC_STUB IVsPackageExplorer_get_OutputRoot_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackageExplorer_AdvisePackageExplorerStatusCallback_Proxy( 
    IVsPackageExplorer * This,
    /* [in] */ IVsPackageExplorerStatusCallback *pIVsPackageExplorerStatusCallback,
    /* [out] */ VSCOOKIE *pdwCookie);


void __RPC_STUB IVsPackageExplorer_AdvisePackageExplorerStatusCallback_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackageExplorer_UnadvisePackageExplorerStatusCallback_Proxy( 
    IVsPackageExplorer * This,
    /* [in] */ VSCOOKIE dwCookie);


void __RPC_STUB IVsPackageExplorer_UnadvisePackageExplorerStatusCallback_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackageExplorer_Start_Proxy( 
    IVsPackageExplorer * This);


void __RPC_STUB IVsPackageExplorer_Start_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackageExplorer_QueryStatus_Proxy( 
    IVsPackageExplorer * This,
    /* [out] */ BOOL *pfDone);


void __RPC_STUB IVsPackageExplorer_QueryStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackageExplorer_Stop_Proxy( 
    IVsPackageExplorer * This,
    /* [in] */ BOOL fSync);


void __RPC_STUB IVsPackageExplorer_Stop_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackageExplorer_Wait_Proxy( 
    IVsPackageExplorer * This,
    /* [in] */ DWORD dwMilliseconds,
    BOOL fTickOnMessage);


void __RPC_STUB IVsPackageExplorer_Wait_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsPackageExplorer_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vspkg_0692 */
/* [local] */ 

typedef 
enum tagVSPKGCWPF
    {	VSPKGCWPF_OWNS_PROJECT_CFG	= 1
    } 	VSPKGCWPF;



extern RPC_IF_HANDLE __MIDL_itf_vspkg_0692_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vspkg_0692_v0_0_s_ifspec;

#ifndef __IVsPackagingHelper_INTERFACE_DEFINED__
#define __IVsPackagingHelper_INTERFACE_DEFINED__

/* interface IVsPackagingHelper */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsPackagingHelper;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5238386c-c56b-11d0-8a49-00a0c91e2acd")
    IVsPackagingHelper : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CreateWrapperProjectCfg( 
            /* [in] */ IVsProjectCfgProvider *pIVsProjectCfgProvider,
            /* [in] */ IVsProjectCfg *pIVsProjectCfg,
            /* [in] */ LPCOLESTR szCanonicalName,
            /* [in] */ LPCOLESTR szDisplayName,
            /* [in] */ LPCOLESTR szCfgRootDirectory,
            /* [in] */ LPCOLESTR szProjectBaseName,
            /* [in] */ IVsPackagingEngineFilter *pIVsPackagingEngineFilter,
            /* [in] */ DWORD dwOptions,
            /* [out] */ IVsProjectCfg **ppIVsProjectCfg) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsPackagingHelperVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsPackagingHelper * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsPackagingHelper * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsPackagingHelper * This);
        
        HRESULT ( STDMETHODCALLTYPE *CreateWrapperProjectCfg )( 
            IVsPackagingHelper * This,
            /* [in] */ IVsProjectCfgProvider *pIVsProjectCfgProvider,
            /* [in] */ IVsProjectCfg *pIVsProjectCfg,
            /* [in] */ LPCOLESTR szCanonicalName,
            /* [in] */ LPCOLESTR szDisplayName,
            /* [in] */ LPCOLESTR szCfgRootDirectory,
            /* [in] */ LPCOLESTR szProjectBaseName,
            /* [in] */ IVsPackagingEngineFilter *pIVsPackagingEngineFilter,
            /* [in] */ DWORD dwOptions,
            /* [out] */ IVsProjectCfg **ppIVsProjectCfg);
        
        END_INTERFACE
    } IVsPackagingHelperVtbl;

    interface IVsPackagingHelper
    {
        CONST_VTBL struct IVsPackagingHelperVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsPackagingHelper_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsPackagingHelper_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsPackagingHelper_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsPackagingHelper_CreateWrapperProjectCfg(This,pIVsProjectCfgProvider,pIVsProjectCfg,szCanonicalName,szDisplayName,szCfgRootDirectory,szProjectBaseName,pIVsPackagingEngineFilter,dwOptions,ppIVsProjectCfg)	\
    (This)->lpVtbl -> CreateWrapperProjectCfg(This,pIVsProjectCfgProvider,pIVsProjectCfg,szCanonicalName,szDisplayName,szCfgRootDirectory,szProjectBaseName,pIVsPackagingEngineFilter,dwOptions,ppIVsProjectCfg)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsPackagingHelper_CreateWrapperProjectCfg_Proxy( 
    IVsPackagingHelper * This,
    /* [in] */ IVsProjectCfgProvider *pIVsProjectCfgProvider,
    /* [in] */ IVsProjectCfg *pIVsProjectCfg,
    /* [in] */ LPCOLESTR szCanonicalName,
    /* [in] */ LPCOLESTR szDisplayName,
    /* [in] */ LPCOLESTR szCfgRootDirectory,
    /* [in] */ LPCOLESTR szProjectBaseName,
    /* [in] */ IVsPackagingEngineFilter *pIVsPackagingEngineFilter,
    /* [in] */ DWORD dwOptions,
    /* [out] */ IVsProjectCfg **ppIVsProjectCfg);


void __RPC_STUB IVsPackagingHelper_CreateWrapperProjectCfg_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsPackagingHelper_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vspkg_0693 */
/* [local] */ 

#define SID_SVsPackagingHelper IID_IVsPackagingHelper


extern RPC_IF_HANDLE __MIDL_itf_vspkg_0693_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vspkg_0693_v0_0_s_ifspec;

#ifndef __IVsPackagingWrapperProjectCfg_INTERFACE_DEFINED__
#define __IVsPackagingWrapperProjectCfg_INTERFACE_DEFINED__

/* interface IVsPackagingWrapperProjectCfg */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsPackagingWrapperProjectCfg;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("52383874-c56b-11d0-8a49-00a0c91e2acd")
    IVsPackagingWrapperProjectCfg : public IVsProjectCfg
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE get_WrappedProjectCfg( 
            /* [out] */ IVsProjectCfg **ppIVsProjectCfg) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsDirty( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsPackagingWrapperProjectCfgVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsPackagingWrapperProjectCfg * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsPackagingWrapperProjectCfg * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsPackagingWrapperProjectCfg * This);
        
        HRESULT ( STDMETHODCALLTYPE *get_DisplayName )( 
            IVsPackagingWrapperProjectCfg * This,
            /* [out] */ BSTR *pbstrDisplayName);
        
        HRESULT ( STDMETHODCALLTYPE *get_IsDebugOnly )( 
            IVsPackagingWrapperProjectCfg * This,
            /* [out] */ BOOL *pfIsDebugOnly);
        
        HRESULT ( STDMETHODCALLTYPE *get_IsReleaseOnly )( 
            IVsPackagingWrapperProjectCfg * This,
            /* [out] */ BOOL *pfIsReleaseOnly);
        
        HRESULT ( STDMETHODCALLTYPE *EnumOutputs )( 
            IVsPackagingWrapperProjectCfg * This,
            /* [out] */ IVsEnumOutputs **ppIVsEnumOutputs);
        
        HRESULT ( STDMETHODCALLTYPE *OpenOutput )( 
            IVsPackagingWrapperProjectCfg * This,
            /* [in] */ LPCOLESTR szOutputCanonicalName,
            /* [out] */ IVsOutput **ppIVsOutput);
        
        HRESULT ( STDMETHODCALLTYPE *get_ProjectCfgProvider )( 
            IVsPackagingWrapperProjectCfg * This,
            /* [out] */ IVsProjectCfgProvider **ppIVsProjectCfgProvider);
        
        HRESULT ( STDMETHODCALLTYPE *get_BuildableProjectCfg )( 
            IVsPackagingWrapperProjectCfg * This,
            /* [out] */ IVsBuildableProjectCfg **ppIVsBuildableProjectCfg);
        
        HRESULT ( STDMETHODCALLTYPE *get_CanonicalName )( 
            IVsPackagingWrapperProjectCfg * This,
            /* [out] */ BSTR *pbstrCanonicalName);
        
        HRESULT ( STDMETHODCALLTYPE *get_Platform )( 
            IVsPackagingWrapperProjectCfg * This,
            /* [out] */ GUID *pguidPlatform);
        
        HRESULT ( STDMETHODCALLTYPE *get_IsPackaged )( 
            IVsPackagingWrapperProjectCfg * This,
            /* [out] */ BOOL *pfIsPackaged);
        
        HRESULT ( STDMETHODCALLTYPE *get_IsSpecifyingOutputSupported )( 
            IVsPackagingWrapperProjectCfg * This,
            /* [out] */ BOOL *pfIsSpecifyingOutputSupported);
        
        HRESULT ( STDMETHODCALLTYPE *get_TargetCodePage )( 
            IVsPackagingWrapperProjectCfg * This,
            /* [out] */ UINT *puiTargetCodePage);
        
        HRESULT ( STDMETHODCALLTYPE *get_UpdateSequenceNumber )( 
            IVsPackagingWrapperProjectCfg * This,
            /* [out] */ ULARGE_INTEGER *puliUSN);
        
        HRESULT ( STDMETHODCALLTYPE *get_RootURL )( 
            IVsPackagingWrapperProjectCfg * This,
            /* [out] */ BSTR *pbstrRootURL);
        
        HRESULT ( STDMETHODCALLTYPE *get_WrappedProjectCfg )( 
            IVsPackagingWrapperProjectCfg * This,
            /* [out] */ IVsProjectCfg **ppIVsProjectCfg);
        
        HRESULT ( STDMETHODCALLTYPE *IsDirty )( 
            IVsPackagingWrapperProjectCfg * This);
        
        HRESULT ( STDMETHODCALLTYPE *Close )( 
            IVsPackagingWrapperProjectCfg * This);
        
        END_INTERFACE
    } IVsPackagingWrapperProjectCfgVtbl;

    interface IVsPackagingWrapperProjectCfg
    {
        CONST_VTBL struct IVsPackagingWrapperProjectCfgVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsPackagingWrapperProjectCfg_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsPackagingWrapperProjectCfg_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsPackagingWrapperProjectCfg_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsPackagingWrapperProjectCfg_get_DisplayName(This,pbstrDisplayName)	\
    (This)->lpVtbl -> get_DisplayName(This,pbstrDisplayName)

#define IVsPackagingWrapperProjectCfg_get_IsDebugOnly(This,pfIsDebugOnly)	\
    (This)->lpVtbl -> get_IsDebugOnly(This,pfIsDebugOnly)

#define IVsPackagingWrapperProjectCfg_get_IsReleaseOnly(This,pfIsReleaseOnly)	\
    (This)->lpVtbl -> get_IsReleaseOnly(This,pfIsReleaseOnly)


#define IVsPackagingWrapperProjectCfg_EnumOutputs(This,ppIVsEnumOutputs)	\
    (This)->lpVtbl -> EnumOutputs(This,ppIVsEnumOutputs)

#define IVsPackagingWrapperProjectCfg_OpenOutput(This,szOutputCanonicalName,ppIVsOutput)	\
    (This)->lpVtbl -> OpenOutput(This,szOutputCanonicalName,ppIVsOutput)

#define IVsPackagingWrapperProjectCfg_get_ProjectCfgProvider(This,ppIVsProjectCfgProvider)	\
    (This)->lpVtbl -> get_ProjectCfgProvider(This,ppIVsProjectCfgProvider)

#define IVsPackagingWrapperProjectCfg_get_BuildableProjectCfg(This,ppIVsBuildableProjectCfg)	\
    (This)->lpVtbl -> get_BuildableProjectCfg(This,ppIVsBuildableProjectCfg)

#define IVsPackagingWrapperProjectCfg_get_CanonicalName(This,pbstrCanonicalName)	\
    (This)->lpVtbl -> get_CanonicalName(This,pbstrCanonicalName)

#define IVsPackagingWrapperProjectCfg_get_Platform(This,pguidPlatform)	\
    (This)->lpVtbl -> get_Platform(This,pguidPlatform)

#define IVsPackagingWrapperProjectCfg_get_IsPackaged(This,pfIsPackaged)	\
    (This)->lpVtbl -> get_IsPackaged(This,pfIsPackaged)

#define IVsPackagingWrapperProjectCfg_get_IsSpecifyingOutputSupported(This,pfIsSpecifyingOutputSupported)	\
    (This)->lpVtbl -> get_IsSpecifyingOutputSupported(This,pfIsSpecifyingOutputSupported)

#define IVsPackagingWrapperProjectCfg_get_TargetCodePage(This,puiTargetCodePage)	\
    (This)->lpVtbl -> get_TargetCodePage(This,puiTargetCodePage)

#define IVsPackagingWrapperProjectCfg_get_UpdateSequenceNumber(This,puliUSN)	\
    (This)->lpVtbl -> get_UpdateSequenceNumber(This,puliUSN)

#define IVsPackagingWrapperProjectCfg_get_RootURL(This,pbstrRootURL)	\
    (This)->lpVtbl -> get_RootURL(This,pbstrRootURL)


#define IVsPackagingWrapperProjectCfg_get_WrappedProjectCfg(This,ppIVsProjectCfg)	\
    (This)->lpVtbl -> get_WrappedProjectCfg(This,ppIVsProjectCfg)

#define IVsPackagingWrapperProjectCfg_IsDirty(This)	\
    (This)->lpVtbl -> IsDirty(This)

#define IVsPackagingWrapperProjectCfg_Close(This)	\
    (This)->lpVtbl -> Close(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsPackagingWrapperProjectCfg_get_WrappedProjectCfg_Proxy( 
    IVsPackagingWrapperProjectCfg * This,
    /* [out] */ IVsProjectCfg **ppIVsProjectCfg);


void __RPC_STUB IVsPackagingWrapperProjectCfg_get_WrappedProjectCfg_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingWrapperProjectCfg_IsDirty_Proxy( 
    IVsPackagingWrapperProjectCfg * This);


void __RPC_STUB IVsPackagingWrapperProjectCfg_IsDirty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingWrapperProjectCfg_Close_Proxy( 
    IVsPackagingWrapperProjectCfg * This);


void __RPC_STUB IVsPackagingWrapperProjectCfg_Close_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsPackagingWrapperProjectCfg_INTERFACE_DEFINED__ */


#ifndef __IVsPackagingEngineFilter_INTERFACE_DEFINED__
#define __IVsPackagingEngineFilter_INTERFACE_DEFINED__

/* interface IVsPackagingEngineFilter */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsPackagingEngineFilter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5238386d-c56b-11d0-8a49-00a0c91e2acd")
    IVsPackagingEngineFilter : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE DoFilter( 
            /* [in] */ ULONG cclsid,
            /* [size_is][in] */ CLSID rgclsid[  ],
            /* [size_is][out][in] */ BOOL rgfEnable[  ]) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsPackagingEngineFilterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsPackagingEngineFilter * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsPackagingEngineFilter * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsPackagingEngineFilter * This);
        
        HRESULT ( STDMETHODCALLTYPE *DoFilter )( 
            IVsPackagingEngineFilter * This,
            /* [in] */ ULONG cclsid,
            /* [size_is][in] */ CLSID rgclsid[  ],
            /* [size_is][out][in] */ BOOL rgfEnable[  ]);
        
        END_INTERFACE
    } IVsPackagingEngineFilterVtbl;

    interface IVsPackagingEngineFilter
    {
        CONST_VTBL struct IVsPackagingEngineFilterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsPackagingEngineFilter_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsPackagingEngineFilter_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsPackagingEngineFilter_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsPackagingEngineFilter_DoFilter(This,cclsid,rgclsid,rgfEnable)	\
    (This)->lpVtbl -> DoFilter(This,cclsid,rgclsid,rgfEnable)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsPackagingEngineFilter_DoFilter_Proxy( 
    IVsPackagingEngineFilter * This,
    /* [in] */ ULONG cclsid,
    /* [size_is][in] */ CLSID rgclsid[  ],
    /* [size_is][out][in] */ BOOL rgfEnable[  ]);


void __RPC_STUB IVsPackagingEngineFilter_DoFilter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsPackagingEngineFilter_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vspkg_0695 */
/* [local] */ 

#if !defined(__bundle_h__)
EXTERN_C const __declspec(selectany) GUID CLSID_VS_PACKAGING_GENERAL_PROPERTY_PAGE = {0xa57e3d70, 0xd2d3, 0x11d2, {0x8a, 0x50, 0x00, 0xa0, 0xc9, 0x1e, 0x2a, 0xcd}};
EXTERN_C const __declspec(selectany) GUID CLSID_VS_CAB_PROPERTY_PAGE = {0xa57e3d71, 0xd2d3, 0x11d2, {0x8a, 0x50, 0x00, 0xa0, 0xc9, 0x1e, 0x2a, 0xcd}};
EXTERN_C const __declspec(selectany) GUID CLSID_VS_CAB_PERMISSIONS_PAGE = {0xa57e3d76, 0xd2d3, 0x11d0, {0x8a, 0x50, 0x00, 0xa0, 0xc9, 0x1e, 0x2a, 0xcd}};
EXTERN_C const __declspec(selectany) GUID CLSID_VS_JAR_PROPERTY_PAGE = {0xa57e3d73, 0xd2d3, 0x11d2, {0x8a, 0x50, 0x00, 0xa0, 0xc9, 0x1e, 0x2a, 0xcd}};
EXTERN_C const __declspec(selectany) GUID CLSID_VS_SETUP_PROPERTIES_TARGET_PAGE = {0x4c2b25c3, 0x02f7, 0x11d2, {0xa4, 0xbe, 0x00, 0x60, 0x97, 0xc9, 0x93, 0x3c}};
EXTERN_C const __declspec(selectany) GUID CLSID_VS_SETUP_PROPERTIES_DEPENDENCIES_PAGE = {0x4c2b25c4, 0x02f7, 0x11d2, {0xa4, 0xbe, 0x00, 0x60, 0x97, 0xc9, 0x93, 0x3c}};
EXTERN_C const __declspec(selectany) GUID CLSID_VS_CAB_PACKAGING_ENGINE = {0xFB61C8EE,0xA6E4,0x11d2, {0x8A,0x43,0x00,0xA0,0xC9,0x1E,0x2A,0xCD}};
EXTERN_C const __declspec(selectany) GUID CLSID_VS_PACKAGING_OUTPUTS_PROPERTY_PAGE = { 0xa57e3dae, 0xd2d3, 0x11d2, {0x8a, 0x50, 0x00, 0xa0, 0xc9, 0x1e, 0x2a, 0xcd}};
#endif


extern RPC_IF_HANDLE __MIDL_itf_vspkg_0695_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vspkg_0695_v0_0_s_ifspec;

#ifndef __IVsPackagingGeneralPPageController_INTERFACE_DEFINED__
#define __IVsPackagingGeneralPPageController_INTERFACE_DEFINED__

/* interface IVsPackagingGeneralPPageController */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsPackagingGeneralPPageController;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5238386e-c56b-11d0-8a49-00a0c91e2acd")
    IVsPackagingGeneralPPageController : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnSetObject( 
            /* [in] */ IVsPackagingGeneralPPageSettings *pIVsPackagingGeneralPPageSettings) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsPackagingGeneralPPageControllerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsPackagingGeneralPPageController * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsPackagingGeneralPPageController * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsPackagingGeneralPPageController * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnSetObject )( 
            IVsPackagingGeneralPPageController * This,
            /* [in] */ IVsPackagingGeneralPPageSettings *pIVsPackagingGeneralPPageSettings);
        
        END_INTERFACE
    } IVsPackagingGeneralPPageControllerVtbl;

    interface IVsPackagingGeneralPPageController
    {
        CONST_VTBL struct IVsPackagingGeneralPPageControllerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsPackagingGeneralPPageController_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsPackagingGeneralPPageController_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsPackagingGeneralPPageController_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsPackagingGeneralPPageController_OnSetObject(This,pIVsPackagingGeneralPPageSettings)	\
    (This)->lpVtbl -> OnSetObject(This,pIVsPackagingGeneralPPageSettings)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsPackagingGeneralPPageController_OnSetObject_Proxy( 
    IVsPackagingGeneralPPageController * This,
    /* [in] */ IVsPackagingGeneralPPageSettings *pIVsPackagingGeneralPPageSettings);


void __RPC_STUB IVsPackagingGeneralPPageController_OnSetObject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsPackagingGeneralPPageController_INTERFACE_DEFINED__ */


#ifndef __IVsPackagingGeneralPPageSettings_INTERFACE_DEFINED__
#define __IVsPackagingGeneralPPageSettings_INTERFACE_DEFINED__

/* interface IVsPackagingGeneralPPageSettings */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsPackagingGeneralPPageSettings;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5238386f-c56b-11d0-8a49-00a0c91e2acd")
    IVsPackagingGeneralPPageSettings : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE get_PackagingEngineFilter( 
            /* [out] */ IVsPackagingEngineFilter **ppIVsPackagingEngineFilter) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_PackagingEngineFilter( 
            /* [in] */ IVsPackagingEngineFilter *pIVsPackagingEngineFilter) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_IsFileListEnabled( 
            /* [out] */ BOOL *pfEnabled) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_IsFileListEnabled( 
            /* [in] */ BOOL fEnable) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_IsEngineTypeListEnabled( 
            /* [out] */ BOOL *pfEnabled) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_IsEngineTypeListEnabled( 
            /* [in] */ BOOL fEnable) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsPackagingGeneralPPageSettingsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsPackagingGeneralPPageSettings * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsPackagingGeneralPPageSettings * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsPackagingGeneralPPageSettings * This);
        
        HRESULT ( STDMETHODCALLTYPE *get_PackagingEngineFilter )( 
            IVsPackagingGeneralPPageSettings * This,
            /* [out] */ IVsPackagingEngineFilter **ppIVsPackagingEngineFilter);
        
        HRESULT ( STDMETHODCALLTYPE *put_PackagingEngineFilter )( 
            IVsPackagingGeneralPPageSettings * This,
            /* [in] */ IVsPackagingEngineFilter *pIVsPackagingEngineFilter);
        
        HRESULT ( STDMETHODCALLTYPE *get_IsFileListEnabled )( 
            IVsPackagingGeneralPPageSettings * This,
            /* [out] */ BOOL *pfEnabled);
        
        HRESULT ( STDMETHODCALLTYPE *put_IsFileListEnabled )( 
            IVsPackagingGeneralPPageSettings * This,
            /* [in] */ BOOL fEnable);
        
        HRESULT ( STDMETHODCALLTYPE *get_IsEngineTypeListEnabled )( 
            IVsPackagingGeneralPPageSettings * This,
            /* [out] */ BOOL *pfEnabled);
        
        HRESULT ( STDMETHODCALLTYPE *put_IsEngineTypeListEnabled )( 
            IVsPackagingGeneralPPageSettings * This,
            /* [in] */ BOOL fEnable);
        
        END_INTERFACE
    } IVsPackagingGeneralPPageSettingsVtbl;

    interface IVsPackagingGeneralPPageSettings
    {
        CONST_VTBL struct IVsPackagingGeneralPPageSettingsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsPackagingGeneralPPageSettings_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsPackagingGeneralPPageSettings_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsPackagingGeneralPPageSettings_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsPackagingGeneralPPageSettings_get_PackagingEngineFilter(This,ppIVsPackagingEngineFilter)	\
    (This)->lpVtbl -> get_PackagingEngineFilter(This,ppIVsPackagingEngineFilter)

#define IVsPackagingGeneralPPageSettings_put_PackagingEngineFilter(This,pIVsPackagingEngineFilter)	\
    (This)->lpVtbl -> put_PackagingEngineFilter(This,pIVsPackagingEngineFilter)

#define IVsPackagingGeneralPPageSettings_get_IsFileListEnabled(This,pfEnabled)	\
    (This)->lpVtbl -> get_IsFileListEnabled(This,pfEnabled)

#define IVsPackagingGeneralPPageSettings_put_IsFileListEnabled(This,fEnable)	\
    (This)->lpVtbl -> put_IsFileListEnabled(This,fEnable)

#define IVsPackagingGeneralPPageSettings_get_IsEngineTypeListEnabled(This,pfEnabled)	\
    (This)->lpVtbl -> get_IsEngineTypeListEnabled(This,pfEnabled)

#define IVsPackagingGeneralPPageSettings_put_IsEngineTypeListEnabled(This,fEnable)	\
    (This)->lpVtbl -> put_IsEngineTypeListEnabled(This,fEnable)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsPackagingGeneralPPageSettings_get_PackagingEngineFilter_Proxy( 
    IVsPackagingGeneralPPageSettings * This,
    /* [out] */ IVsPackagingEngineFilter **ppIVsPackagingEngineFilter);


void __RPC_STUB IVsPackagingGeneralPPageSettings_get_PackagingEngineFilter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingGeneralPPageSettings_put_PackagingEngineFilter_Proxy( 
    IVsPackagingGeneralPPageSettings * This,
    /* [in] */ IVsPackagingEngineFilter *pIVsPackagingEngineFilter);


void __RPC_STUB IVsPackagingGeneralPPageSettings_put_PackagingEngineFilter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingGeneralPPageSettings_get_IsFileListEnabled_Proxy( 
    IVsPackagingGeneralPPageSettings * This,
    /* [out] */ BOOL *pfEnabled);


void __RPC_STUB IVsPackagingGeneralPPageSettings_get_IsFileListEnabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingGeneralPPageSettings_put_IsFileListEnabled_Proxy( 
    IVsPackagingGeneralPPageSettings * This,
    /* [in] */ BOOL fEnable);


void __RPC_STUB IVsPackagingGeneralPPageSettings_put_IsFileListEnabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingGeneralPPageSettings_get_IsEngineTypeListEnabled_Proxy( 
    IVsPackagingGeneralPPageSettings * This,
    /* [out] */ BOOL *pfEnabled);


void __RPC_STUB IVsPackagingGeneralPPageSettings_get_IsEngineTypeListEnabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingGeneralPPageSettings_put_IsEngineTypeListEnabled_Proxy( 
    IVsPackagingGeneralPPageSettings * This,
    /* [in] */ BOOL fEnable);


void __RPC_STUB IVsPackagingGeneralPPageSettings_put_IsEngineTypeListEnabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsPackagingGeneralPPageSettings_INTERFACE_DEFINED__ */


#ifndef __IVsPackagingGeneralProperties_INTERFACE_DEFINED__
#define __IVsPackagingGeneralProperties_INTERFACE_DEFINED__

/* interface IVsPackagingGeneralProperties */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsPackagingGeneralProperties;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("52383870-c56b-11d0-8a49-00a0c91e2acd")
    IVsPackagingGeneralProperties : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE get_PackagingEngine( 
            /* [out] */ CLSID *pclsidPackagingEngine) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_PackagingEngine( 
            /* [in] */ REFCLSID rclsidPackagingEngine) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_OutputFilename( 
            /* [in] */ ULONG cchBuffer,
            /* [size_is][out][in] */ OLECHAR rgchBuffer[  ],
            /* [out] */ ULONG *pcchActual) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_OutputFilename( 
            /* [in] */ LPCOLESTR szOutputFilename) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumPackagingCandidates( 
            /* [out] */ IVsEnumOutputs **ppIVsEnumOutputs,
            /* [in] */ unsigned short uFilter) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_OutputsToPackage( 
            /* [in] */ ULONG cbstr,
            /* [size_is][out][in] */ BSTR rgbstrCanonicalNames[  ],
            /* [out] */ ULONG *pcbstrActual) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_OutputsToPackage( 
            /* [in] */ ULONG cbstr,
            /* [size_is][in] */ LPCOLESTR rgszCanonicalNames[  ]) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_OutputsToPackageAreFilters( 
            /* [out] */ BOOL *pfOutputsAreFilter) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_OutputsToPackageAreFilters( 
            /* [in] */ BOOL fOutputsAreFilter) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_PackageAllOutputs( 
            /* [out] */ BOOL *pfPackageAllOutputs) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_PackageAllOutputs( 
            /* [in] */ BOOL fPackageAllOutputs) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_PackagingEnginePropertyInterfaceBroker( 
            /* [out] */ IVsPackagingEnginePropertyInterfaceBroker **ppIVsPackagingEnginePropertyInterfaceBroker) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_RootDirectory( 
            /* [in] */ ULONG cchBuffer,
            /* [size_is][out][in] */ OLECHAR rgchBuffer[  ],
            /* [out] */ ULONG *pcchActual) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_AdditionalFileCollection( 
            /* [out] */ IVsAdditionalItemCollection **ppIVsAdditionalFileCollection) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_AdditionalFileCollection( 
            /* [in] */ IVsAdditionalItemCollection *pIVsAdditionalFileCollection) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsPackagingGeneralPropertiesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsPackagingGeneralProperties * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsPackagingGeneralProperties * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsPackagingGeneralProperties * This);
        
        HRESULT ( STDMETHODCALLTYPE *get_PackagingEngine )( 
            IVsPackagingGeneralProperties * This,
            /* [out] */ CLSID *pclsidPackagingEngine);
        
        HRESULT ( STDMETHODCALLTYPE *put_PackagingEngine )( 
            IVsPackagingGeneralProperties * This,
            /* [in] */ REFCLSID rclsidPackagingEngine);
        
        HRESULT ( STDMETHODCALLTYPE *get_OutputFilename )( 
            IVsPackagingGeneralProperties * This,
            /* [in] */ ULONG cchBuffer,
            /* [size_is][out][in] */ OLECHAR rgchBuffer[  ],
            /* [out] */ ULONG *pcchActual);
        
        HRESULT ( STDMETHODCALLTYPE *put_OutputFilename )( 
            IVsPackagingGeneralProperties * This,
            /* [in] */ LPCOLESTR szOutputFilename);
        
        HRESULT ( STDMETHODCALLTYPE *EnumPackagingCandidates )( 
            IVsPackagingGeneralProperties * This,
            /* [out] */ IVsEnumOutputs **ppIVsEnumOutputs,
            /* [in] */ unsigned short uFilter);
        
        HRESULT ( STDMETHODCALLTYPE *get_OutputsToPackage )( 
            IVsPackagingGeneralProperties * This,
            /* [in] */ ULONG cbstr,
            /* [size_is][out][in] */ BSTR rgbstrCanonicalNames[  ],
            /* [out] */ ULONG *pcbstrActual);
        
        HRESULT ( STDMETHODCALLTYPE *put_OutputsToPackage )( 
            IVsPackagingGeneralProperties * This,
            /* [in] */ ULONG cbstr,
            /* [size_is][in] */ LPCOLESTR rgszCanonicalNames[  ]);
        
        HRESULT ( STDMETHODCALLTYPE *get_OutputsToPackageAreFilters )( 
            IVsPackagingGeneralProperties * This,
            /* [out] */ BOOL *pfOutputsAreFilter);
        
        HRESULT ( STDMETHODCALLTYPE *put_OutputsToPackageAreFilters )( 
            IVsPackagingGeneralProperties * This,
            /* [in] */ BOOL fOutputsAreFilter);
        
        HRESULT ( STDMETHODCALLTYPE *get_PackageAllOutputs )( 
            IVsPackagingGeneralProperties * This,
            /* [out] */ BOOL *pfPackageAllOutputs);
        
        HRESULT ( STDMETHODCALLTYPE *put_PackageAllOutputs )( 
            IVsPackagingGeneralProperties * This,
            /* [in] */ BOOL fPackageAllOutputs);
        
        HRESULT ( STDMETHODCALLTYPE *get_PackagingEnginePropertyInterfaceBroker )( 
            IVsPackagingGeneralProperties * This,
            /* [out] */ IVsPackagingEnginePropertyInterfaceBroker **ppIVsPackagingEnginePropertyInterfaceBroker);
        
        HRESULT ( STDMETHODCALLTYPE *get_RootDirectory )( 
            IVsPackagingGeneralProperties * This,
            /* [in] */ ULONG cchBuffer,
            /* [size_is][out][in] */ OLECHAR rgchBuffer[  ],
            /* [out] */ ULONG *pcchActual);
        
        HRESULT ( STDMETHODCALLTYPE *get_AdditionalFileCollection )( 
            IVsPackagingGeneralProperties * This,
            /* [out] */ IVsAdditionalItemCollection **ppIVsAdditionalFileCollection);
        
        HRESULT ( STDMETHODCALLTYPE *put_AdditionalFileCollection )( 
            IVsPackagingGeneralProperties * This,
            /* [in] */ IVsAdditionalItemCollection *pIVsAdditionalFileCollection);
        
        END_INTERFACE
    } IVsPackagingGeneralPropertiesVtbl;

    interface IVsPackagingGeneralProperties
    {
        CONST_VTBL struct IVsPackagingGeneralPropertiesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsPackagingGeneralProperties_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsPackagingGeneralProperties_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsPackagingGeneralProperties_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsPackagingGeneralProperties_get_PackagingEngine(This,pclsidPackagingEngine)	\
    (This)->lpVtbl -> get_PackagingEngine(This,pclsidPackagingEngine)

#define IVsPackagingGeneralProperties_put_PackagingEngine(This,rclsidPackagingEngine)	\
    (This)->lpVtbl -> put_PackagingEngine(This,rclsidPackagingEngine)

#define IVsPackagingGeneralProperties_get_OutputFilename(This,cchBuffer,rgchBuffer,pcchActual)	\
    (This)->lpVtbl -> get_OutputFilename(This,cchBuffer,rgchBuffer,pcchActual)

#define IVsPackagingGeneralProperties_put_OutputFilename(This,szOutputFilename)	\
    (This)->lpVtbl -> put_OutputFilename(This,szOutputFilename)

#define IVsPackagingGeneralProperties_EnumPackagingCandidates(This,ppIVsEnumOutputs,uFilter)	\
    (This)->lpVtbl -> EnumPackagingCandidates(This,ppIVsEnumOutputs,uFilter)

#define IVsPackagingGeneralProperties_get_OutputsToPackage(This,cbstr,rgbstrCanonicalNames,pcbstrActual)	\
    (This)->lpVtbl -> get_OutputsToPackage(This,cbstr,rgbstrCanonicalNames,pcbstrActual)

#define IVsPackagingGeneralProperties_put_OutputsToPackage(This,cbstr,rgszCanonicalNames)	\
    (This)->lpVtbl -> put_OutputsToPackage(This,cbstr,rgszCanonicalNames)

#define IVsPackagingGeneralProperties_get_OutputsToPackageAreFilters(This,pfOutputsAreFilter)	\
    (This)->lpVtbl -> get_OutputsToPackageAreFilters(This,pfOutputsAreFilter)

#define IVsPackagingGeneralProperties_put_OutputsToPackageAreFilters(This,fOutputsAreFilter)	\
    (This)->lpVtbl -> put_OutputsToPackageAreFilters(This,fOutputsAreFilter)

#define IVsPackagingGeneralProperties_get_PackageAllOutputs(This,pfPackageAllOutputs)	\
    (This)->lpVtbl -> get_PackageAllOutputs(This,pfPackageAllOutputs)

#define IVsPackagingGeneralProperties_put_PackageAllOutputs(This,fPackageAllOutputs)	\
    (This)->lpVtbl -> put_PackageAllOutputs(This,fPackageAllOutputs)

#define IVsPackagingGeneralProperties_get_PackagingEnginePropertyInterfaceBroker(This,ppIVsPackagingEnginePropertyInterfaceBroker)	\
    (This)->lpVtbl -> get_PackagingEnginePropertyInterfaceBroker(This,ppIVsPackagingEnginePropertyInterfaceBroker)

#define IVsPackagingGeneralProperties_get_RootDirectory(This,cchBuffer,rgchBuffer,pcchActual)	\
    (This)->lpVtbl -> get_RootDirectory(This,cchBuffer,rgchBuffer,pcchActual)

#define IVsPackagingGeneralProperties_get_AdditionalFileCollection(This,ppIVsAdditionalFileCollection)	\
    (This)->lpVtbl -> get_AdditionalFileCollection(This,ppIVsAdditionalFileCollection)

#define IVsPackagingGeneralProperties_put_AdditionalFileCollection(This,pIVsAdditionalFileCollection)	\
    (This)->lpVtbl -> put_AdditionalFileCollection(This,pIVsAdditionalFileCollection)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsPackagingGeneralProperties_get_PackagingEngine_Proxy( 
    IVsPackagingGeneralProperties * This,
    /* [out] */ CLSID *pclsidPackagingEngine);


void __RPC_STUB IVsPackagingGeneralProperties_get_PackagingEngine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingGeneralProperties_put_PackagingEngine_Proxy( 
    IVsPackagingGeneralProperties * This,
    /* [in] */ REFCLSID rclsidPackagingEngine);


void __RPC_STUB IVsPackagingGeneralProperties_put_PackagingEngine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingGeneralProperties_get_OutputFilename_Proxy( 
    IVsPackagingGeneralProperties * This,
    /* [in] */ ULONG cchBuffer,
    /* [size_is][out][in] */ OLECHAR rgchBuffer[  ],
    /* [out] */ ULONG *pcchActual);


void __RPC_STUB IVsPackagingGeneralProperties_get_OutputFilename_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingGeneralProperties_put_OutputFilename_Proxy( 
    IVsPackagingGeneralProperties * This,
    /* [in] */ LPCOLESTR szOutputFilename);


void __RPC_STUB IVsPackagingGeneralProperties_put_OutputFilename_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingGeneralProperties_EnumPackagingCandidates_Proxy( 
    IVsPackagingGeneralProperties * This,
    /* [out] */ IVsEnumOutputs **ppIVsEnumOutputs,
    /* [in] */ unsigned short uFilter);


void __RPC_STUB IVsPackagingGeneralProperties_EnumPackagingCandidates_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingGeneralProperties_get_OutputsToPackage_Proxy( 
    IVsPackagingGeneralProperties * This,
    /* [in] */ ULONG cbstr,
    /* [size_is][out][in] */ BSTR rgbstrCanonicalNames[  ],
    /* [out] */ ULONG *pcbstrActual);


void __RPC_STUB IVsPackagingGeneralProperties_get_OutputsToPackage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingGeneralProperties_put_OutputsToPackage_Proxy( 
    IVsPackagingGeneralProperties * This,
    /* [in] */ ULONG cbstr,
    /* [size_is][in] */ LPCOLESTR rgszCanonicalNames[  ]);


void __RPC_STUB IVsPackagingGeneralProperties_put_OutputsToPackage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingGeneralProperties_get_OutputsToPackageAreFilters_Proxy( 
    IVsPackagingGeneralProperties * This,
    /* [out] */ BOOL *pfOutputsAreFilter);


void __RPC_STUB IVsPackagingGeneralProperties_get_OutputsToPackageAreFilters_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingGeneralProperties_put_OutputsToPackageAreFilters_Proxy( 
    IVsPackagingGeneralProperties * This,
    /* [in] */ BOOL fOutputsAreFilter);


void __RPC_STUB IVsPackagingGeneralProperties_put_OutputsToPackageAreFilters_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingGeneralProperties_get_PackageAllOutputs_Proxy( 
    IVsPackagingGeneralProperties * This,
    /* [out] */ BOOL *pfPackageAllOutputs);


void __RPC_STUB IVsPackagingGeneralProperties_get_PackageAllOutputs_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingGeneralProperties_put_PackageAllOutputs_Proxy( 
    IVsPackagingGeneralProperties * This,
    /* [in] */ BOOL fPackageAllOutputs);


void __RPC_STUB IVsPackagingGeneralProperties_put_PackageAllOutputs_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingGeneralProperties_get_PackagingEnginePropertyInterfaceBroker_Proxy( 
    IVsPackagingGeneralProperties * This,
    /* [out] */ IVsPackagingEnginePropertyInterfaceBroker **ppIVsPackagingEnginePropertyInterfaceBroker);


void __RPC_STUB IVsPackagingGeneralProperties_get_PackagingEnginePropertyInterfaceBroker_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingGeneralProperties_get_RootDirectory_Proxy( 
    IVsPackagingGeneralProperties * This,
    /* [in] */ ULONG cchBuffer,
    /* [size_is][out][in] */ OLECHAR rgchBuffer[  ],
    /* [out] */ ULONG *pcchActual);


void __RPC_STUB IVsPackagingGeneralProperties_get_RootDirectory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingGeneralProperties_get_AdditionalFileCollection_Proxy( 
    IVsPackagingGeneralProperties * This,
    /* [out] */ IVsAdditionalItemCollection **ppIVsAdditionalFileCollection);


void __RPC_STUB IVsPackagingGeneralProperties_get_AdditionalFileCollection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingGeneralProperties_put_AdditionalFileCollection_Proxy( 
    IVsPackagingGeneralProperties * This,
    /* [in] */ IVsAdditionalItemCollection *pIVsAdditionalFileCollection);


void __RPC_STUB IVsPackagingGeneralProperties_put_AdditionalFileCollection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsPackagingGeneralProperties_INTERFACE_DEFINED__ */


#ifndef __IVsPackagingOutputsProperties_INTERFACE_DEFINED__
#define __IVsPackagingOutputsProperties_INTERFACE_DEFINED__

/* interface IVsPackagingOutputsProperties */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsPackagingOutputsProperties;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a57e3daf-d2d3-11d0-8a50-00a0c91e2acd")
    IVsPackagingOutputsProperties : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE EnumPossibleOutputs( 
            /* [out] */ IVsEnumOutputs **ppIVsEnumOutputs) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_OutputsToOutput( 
            /* [in] */ ULONG cbstr,
            /* [size_is][out][in] */ BSTR rgbstrCanonicalNames[  ],
            /* [out] */ ULONG *pcbstrActual) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_OutputsToOutput( 
            /* [in] */ ULONG cbstr,
            /* [size_is][in] */ LPCOLESTR rgszCanonicalNames[  ]) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_OutputsToOutputAreFilters( 
            /* [out] */ BOOL *pfOutputsAreFilter) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_OutputsToOutputAreFilters( 
            /* [in] */ BOOL fOutputsAreFilter) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_OutputAllOutputs( 
            /* [out] */ BOOL *pfPackageAllOutputs) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_OutputAllOutputs( 
            /* [in] */ BOOL fPackageAllOutputs) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_OutputPackage( 
            /* [out] */ BOOL *pfOutputPackage) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_OutputPackage( 
            /* [in] */ BOOL fOutputPackage) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_OmitPackagedFiles( 
            /* [out] */ BOOL *pfOmitPackagedFiles) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_OmitPackagedFiles( 
            /* [in] */ BOOL fOmitPackagedFiles) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsPackagingOutputsPropertiesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsPackagingOutputsProperties * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsPackagingOutputsProperties * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsPackagingOutputsProperties * This);
        
        HRESULT ( STDMETHODCALLTYPE *EnumPossibleOutputs )( 
            IVsPackagingOutputsProperties * This,
            /* [out] */ IVsEnumOutputs **ppIVsEnumOutputs);
        
        HRESULT ( STDMETHODCALLTYPE *get_OutputsToOutput )( 
            IVsPackagingOutputsProperties * This,
            /* [in] */ ULONG cbstr,
            /* [size_is][out][in] */ BSTR rgbstrCanonicalNames[  ],
            /* [out] */ ULONG *pcbstrActual);
        
        HRESULT ( STDMETHODCALLTYPE *put_OutputsToOutput )( 
            IVsPackagingOutputsProperties * This,
            /* [in] */ ULONG cbstr,
            /* [size_is][in] */ LPCOLESTR rgszCanonicalNames[  ]);
        
        HRESULT ( STDMETHODCALLTYPE *get_OutputsToOutputAreFilters )( 
            IVsPackagingOutputsProperties * This,
            /* [out] */ BOOL *pfOutputsAreFilter);
        
        HRESULT ( STDMETHODCALLTYPE *put_OutputsToOutputAreFilters )( 
            IVsPackagingOutputsProperties * This,
            /* [in] */ BOOL fOutputsAreFilter);
        
        HRESULT ( STDMETHODCALLTYPE *get_OutputAllOutputs )( 
            IVsPackagingOutputsProperties * This,
            /* [out] */ BOOL *pfPackageAllOutputs);
        
        HRESULT ( STDMETHODCALLTYPE *put_OutputAllOutputs )( 
            IVsPackagingOutputsProperties * This,
            /* [in] */ BOOL fPackageAllOutputs);
        
        HRESULT ( STDMETHODCALLTYPE *get_OutputPackage )( 
            IVsPackagingOutputsProperties * This,
            /* [out] */ BOOL *pfOutputPackage);
        
        HRESULT ( STDMETHODCALLTYPE *put_OutputPackage )( 
            IVsPackagingOutputsProperties * This,
            /* [in] */ BOOL fOutputPackage);
        
        HRESULT ( STDMETHODCALLTYPE *get_OmitPackagedFiles )( 
            IVsPackagingOutputsProperties * This,
            /* [out] */ BOOL *pfOmitPackagedFiles);
        
        HRESULT ( STDMETHODCALLTYPE *put_OmitPackagedFiles )( 
            IVsPackagingOutputsProperties * This,
            /* [in] */ BOOL fOmitPackagedFiles);
        
        END_INTERFACE
    } IVsPackagingOutputsPropertiesVtbl;

    interface IVsPackagingOutputsProperties
    {
        CONST_VTBL struct IVsPackagingOutputsPropertiesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsPackagingOutputsProperties_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsPackagingOutputsProperties_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsPackagingOutputsProperties_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsPackagingOutputsProperties_EnumPossibleOutputs(This,ppIVsEnumOutputs)	\
    (This)->lpVtbl -> EnumPossibleOutputs(This,ppIVsEnumOutputs)

#define IVsPackagingOutputsProperties_get_OutputsToOutput(This,cbstr,rgbstrCanonicalNames,pcbstrActual)	\
    (This)->lpVtbl -> get_OutputsToOutput(This,cbstr,rgbstrCanonicalNames,pcbstrActual)

#define IVsPackagingOutputsProperties_put_OutputsToOutput(This,cbstr,rgszCanonicalNames)	\
    (This)->lpVtbl -> put_OutputsToOutput(This,cbstr,rgszCanonicalNames)

#define IVsPackagingOutputsProperties_get_OutputsToOutputAreFilters(This,pfOutputsAreFilter)	\
    (This)->lpVtbl -> get_OutputsToOutputAreFilters(This,pfOutputsAreFilter)

#define IVsPackagingOutputsProperties_put_OutputsToOutputAreFilters(This,fOutputsAreFilter)	\
    (This)->lpVtbl -> put_OutputsToOutputAreFilters(This,fOutputsAreFilter)

#define IVsPackagingOutputsProperties_get_OutputAllOutputs(This,pfPackageAllOutputs)	\
    (This)->lpVtbl -> get_OutputAllOutputs(This,pfPackageAllOutputs)

#define IVsPackagingOutputsProperties_put_OutputAllOutputs(This,fPackageAllOutputs)	\
    (This)->lpVtbl -> put_OutputAllOutputs(This,fPackageAllOutputs)

#define IVsPackagingOutputsProperties_get_OutputPackage(This,pfOutputPackage)	\
    (This)->lpVtbl -> get_OutputPackage(This,pfOutputPackage)

#define IVsPackagingOutputsProperties_put_OutputPackage(This,fOutputPackage)	\
    (This)->lpVtbl -> put_OutputPackage(This,fOutputPackage)

#define IVsPackagingOutputsProperties_get_OmitPackagedFiles(This,pfOmitPackagedFiles)	\
    (This)->lpVtbl -> get_OmitPackagedFiles(This,pfOmitPackagedFiles)

#define IVsPackagingOutputsProperties_put_OmitPackagedFiles(This,fOmitPackagedFiles)	\
    (This)->lpVtbl -> put_OmitPackagedFiles(This,fOmitPackagedFiles)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsPackagingOutputsProperties_EnumPossibleOutputs_Proxy( 
    IVsPackagingOutputsProperties * This,
    /* [out] */ IVsEnumOutputs **ppIVsEnumOutputs);


void __RPC_STUB IVsPackagingOutputsProperties_EnumPossibleOutputs_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingOutputsProperties_get_OutputsToOutput_Proxy( 
    IVsPackagingOutputsProperties * This,
    /* [in] */ ULONG cbstr,
    /* [size_is][out][in] */ BSTR rgbstrCanonicalNames[  ],
    /* [out] */ ULONG *pcbstrActual);


void __RPC_STUB IVsPackagingOutputsProperties_get_OutputsToOutput_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingOutputsProperties_put_OutputsToOutput_Proxy( 
    IVsPackagingOutputsProperties * This,
    /* [in] */ ULONG cbstr,
    /* [size_is][in] */ LPCOLESTR rgszCanonicalNames[  ]);


void __RPC_STUB IVsPackagingOutputsProperties_put_OutputsToOutput_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingOutputsProperties_get_OutputsToOutputAreFilters_Proxy( 
    IVsPackagingOutputsProperties * This,
    /* [out] */ BOOL *pfOutputsAreFilter);


void __RPC_STUB IVsPackagingOutputsProperties_get_OutputsToOutputAreFilters_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingOutputsProperties_put_OutputsToOutputAreFilters_Proxy( 
    IVsPackagingOutputsProperties * This,
    /* [in] */ BOOL fOutputsAreFilter);


void __RPC_STUB IVsPackagingOutputsProperties_put_OutputsToOutputAreFilters_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingOutputsProperties_get_OutputAllOutputs_Proxy( 
    IVsPackagingOutputsProperties * This,
    /* [out] */ BOOL *pfPackageAllOutputs);


void __RPC_STUB IVsPackagingOutputsProperties_get_OutputAllOutputs_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingOutputsProperties_put_OutputAllOutputs_Proxy( 
    IVsPackagingOutputsProperties * This,
    /* [in] */ BOOL fPackageAllOutputs);


void __RPC_STUB IVsPackagingOutputsProperties_put_OutputAllOutputs_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingOutputsProperties_get_OutputPackage_Proxy( 
    IVsPackagingOutputsProperties * This,
    /* [out] */ BOOL *pfOutputPackage);


void __RPC_STUB IVsPackagingOutputsProperties_get_OutputPackage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingOutputsProperties_put_OutputPackage_Proxy( 
    IVsPackagingOutputsProperties * This,
    /* [in] */ BOOL fOutputPackage);


void __RPC_STUB IVsPackagingOutputsProperties_put_OutputPackage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingOutputsProperties_get_OmitPackagedFiles_Proxy( 
    IVsPackagingOutputsProperties * This,
    /* [out] */ BOOL *pfOmitPackagedFiles);


void __RPC_STUB IVsPackagingOutputsProperties_get_OmitPackagedFiles_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingOutputsProperties_put_OmitPackagedFiles_Proxy( 
    IVsPackagingOutputsProperties * This,
    /* [in] */ BOOL fOmitPackagedFiles);


void __RPC_STUB IVsPackagingOutputsProperties_put_OmitPackagedFiles_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsPackagingOutputsProperties_INTERFACE_DEFINED__ */


#ifndef __IVsPackagingPropertyObject_INTERFACE_DEFINED__
#define __IVsPackagingPropertyObject_INTERFACE_DEFINED__

/* interface IVsPackagingPropertyObject */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsPackagingPropertyObject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5238387a-c56b-11d0-8a49-00a0c91e2acd")
    IVsPackagingPropertyObject : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE get_PackagingEnginePropertyInterfaceBroker( 
            /* [out] */ IVsPackagingEnginePropertyInterfaceBroker **ppIVsPackagingEnginePropertyInterfaceBroker) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_PackagingEnginePropertyInterfaceBroker( 
            /* [in] */ IVsPackagingEnginePropertyInterfaceBroker *pIVsPackagingEnginePropertyInterfaceBroker) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IVsPackagingPropertyObject **ppIVsPackagingPropertyObject) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Merge( 
            /* [in] */ IVsPackagingPropertyObject *pIVsPackagingPropertyObject) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_OutputFilename( 
            /* [in] */ ULONG cchBuffer,
            /* [size_is][out][in] */ OLECHAR rgochBuffer[  ],
            /* [out] */ ULONG *pcchActual) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_OutputFilename( 
            /* [in] */ LPCOLESTR szFilename) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_BaseDirectory( 
            /* [in] */ ULONG cchBuffer,
            /* [size_is][out][in] */ OLECHAR rgochBuffer[  ],
            /* [out] */ ULONG *pcchActual) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_BaseDirectory( 
            /* [in] */ LPCOLESTR szBaseDirectory) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsPackagingPropertyObjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsPackagingPropertyObject * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsPackagingPropertyObject * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsPackagingPropertyObject * This);
        
        HRESULT ( STDMETHODCALLTYPE *get_PackagingEnginePropertyInterfaceBroker )( 
            IVsPackagingPropertyObject * This,
            /* [out] */ IVsPackagingEnginePropertyInterfaceBroker **ppIVsPackagingEnginePropertyInterfaceBroker);
        
        HRESULT ( STDMETHODCALLTYPE *put_PackagingEnginePropertyInterfaceBroker )( 
            IVsPackagingPropertyObject * This,
            /* [in] */ IVsPackagingEnginePropertyInterfaceBroker *pIVsPackagingEnginePropertyInterfaceBroker);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IVsPackagingPropertyObject * This,
            /* [out] */ IVsPackagingPropertyObject **ppIVsPackagingPropertyObject);
        
        HRESULT ( STDMETHODCALLTYPE *Merge )( 
            IVsPackagingPropertyObject * This,
            /* [in] */ IVsPackagingPropertyObject *pIVsPackagingPropertyObject);
        
        HRESULT ( STDMETHODCALLTYPE *Close )( 
            IVsPackagingPropertyObject * This);
        
        HRESULT ( STDMETHODCALLTYPE *get_OutputFilename )( 
            IVsPackagingPropertyObject * This,
            /* [in] */ ULONG cchBuffer,
            /* [size_is][out][in] */ OLECHAR rgochBuffer[  ],
            /* [out] */ ULONG *pcchActual);
        
        HRESULT ( STDMETHODCALLTYPE *put_OutputFilename )( 
            IVsPackagingPropertyObject * This,
            /* [in] */ LPCOLESTR szFilename);
        
        HRESULT ( STDMETHODCALLTYPE *get_BaseDirectory )( 
            IVsPackagingPropertyObject * This,
            /* [in] */ ULONG cchBuffer,
            /* [size_is][out][in] */ OLECHAR rgochBuffer[  ],
            /* [out] */ ULONG *pcchActual);
        
        HRESULT ( STDMETHODCALLTYPE *put_BaseDirectory )( 
            IVsPackagingPropertyObject * This,
            /* [in] */ LPCOLESTR szBaseDirectory);
        
        END_INTERFACE
    } IVsPackagingPropertyObjectVtbl;

    interface IVsPackagingPropertyObject
    {
        CONST_VTBL struct IVsPackagingPropertyObjectVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsPackagingPropertyObject_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsPackagingPropertyObject_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsPackagingPropertyObject_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsPackagingPropertyObject_get_PackagingEnginePropertyInterfaceBroker(This,ppIVsPackagingEnginePropertyInterfaceBroker)	\
    (This)->lpVtbl -> get_PackagingEnginePropertyInterfaceBroker(This,ppIVsPackagingEnginePropertyInterfaceBroker)

#define IVsPackagingPropertyObject_put_PackagingEnginePropertyInterfaceBroker(This,pIVsPackagingEnginePropertyInterfaceBroker)	\
    (This)->lpVtbl -> put_PackagingEnginePropertyInterfaceBroker(This,pIVsPackagingEnginePropertyInterfaceBroker)

#define IVsPackagingPropertyObject_Clone(This,ppIVsPackagingPropertyObject)	\
    (This)->lpVtbl -> Clone(This,ppIVsPackagingPropertyObject)

#define IVsPackagingPropertyObject_Merge(This,pIVsPackagingPropertyObject)	\
    (This)->lpVtbl -> Merge(This,pIVsPackagingPropertyObject)

#define IVsPackagingPropertyObject_Close(This)	\
    (This)->lpVtbl -> Close(This)

#define IVsPackagingPropertyObject_get_OutputFilename(This,cchBuffer,rgochBuffer,pcchActual)	\
    (This)->lpVtbl -> get_OutputFilename(This,cchBuffer,rgochBuffer,pcchActual)

#define IVsPackagingPropertyObject_put_OutputFilename(This,szFilename)	\
    (This)->lpVtbl -> put_OutputFilename(This,szFilename)

#define IVsPackagingPropertyObject_get_BaseDirectory(This,cchBuffer,rgochBuffer,pcchActual)	\
    (This)->lpVtbl -> get_BaseDirectory(This,cchBuffer,rgochBuffer,pcchActual)

#define IVsPackagingPropertyObject_put_BaseDirectory(This,szBaseDirectory)	\
    (This)->lpVtbl -> put_BaseDirectory(This,szBaseDirectory)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsPackagingPropertyObject_get_PackagingEnginePropertyInterfaceBroker_Proxy( 
    IVsPackagingPropertyObject * This,
    /* [out] */ IVsPackagingEnginePropertyInterfaceBroker **ppIVsPackagingEnginePropertyInterfaceBroker);


void __RPC_STUB IVsPackagingPropertyObject_get_PackagingEnginePropertyInterfaceBroker_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingPropertyObject_put_PackagingEnginePropertyInterfaceBroker_Proxy( 
    IVsPackagingPropertyObject * This,
    /* [in] */ IVsPackagingEnginePropertyInterfaceBroker *pIVsPackagingEnginePropertyInterfaceBroker);


void __RPC_STUB IVsPackagingPropertyObject_put_PackagingEnginePropertyInterfaceBroker_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingPropertyObject_Clone_Proxy( 
    IVsPackagingPropertyObject * This,
    /* [out] */ IVsPackagingPropertyObject **ppIVsPackagingPropertyObject);


void __RPC_STUB IVsPackagingPropertyObject_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingPropertyObject_Merge_Proxy( 
    IVsPackagingPropertyObject * This,
    /* [in] */ IVsPackagingPropertyObject *pIVsPackagingPropertyObject);


void __RPC_STUB IVsPackagingPropertyObject_Merge_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingPropertyObject_Close_Proxy( 
    IVsPackagingPropertyObject * This);


void __RPC_STUB IVsPackagingPropertyObject_Close_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingPropertyObject_get_OutputFilename_Proxy( 
    IVsPackagingPropertyObject * This,
    /* [in] */ ULONG cchBuffer,
    /* [size_is][out][in] */ OLECHAR rgochBuffer[  ],
    /* [out] */ ULONG *pcchActual);


void __RPC_STUB IVsPackagingPropertyObject_get_OutputFilename_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingPropertyObject_put_OutputFilename_Proxy( 
    IVsPackagingPropertyObject * This,
    /* [in] */ LPCOLESTR szFilename);


void __RPC_STUB IVsPackagingPropertyObject_put_OutputFilename_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingPropertyObject_get_BaseDirectory_Proxy( 
    IVsPackagingPropertyObject * This,
    /* [in] */ ULONG cchBuffer,
    /* [size_is][out][in] */ OLECHAR rgochBuffer[  ],
    /* [out] */ ULONG *pcchActual);


void __RPC_STUB IVsPackagingPropertyObject_get_BaseDirectory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingPropertyObject_put_BaseDirectory_Proxy( 
    IVsPackagingPropertyObject * This,
    /* [in] */ LPCOLESTR szBaseDirectory);


void __RPC_STUB IVsPackagingPropertyObject_put_BaseDirectory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsPackagingPropertyObject_INTERFACE_DEFINED__ */


#ifndef __IVsCABPPageController_INTERFACE_DEFINED__
#define __IVsCABPPageController_INTERFACE_DEFINED__

/* interface IVsCABPPageController */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsCABPPageController;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("52383871-c56b-11d0-8a49-00a0c91e2acd")
    IVsCABPPageController : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnSetObject( 
            /* [in] */ IVsCABPPageSettings *pIVsCABPPageSettings) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsCABPPageControllerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsCABPPageController * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsCABPPageController * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsCABPPageController * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnSetObject )( 
            IVsCABPPageController * This,
            /* [in] */ IVsCABPPageSettings *pIVsCABPPageSettings);
        
        END_INTERFACE
    } IVsCABPPageControllerVtbl;

    interface IVsCABPPageController
    {
        CONST_VTBL struct IVsCABPPageControllerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsCABPPageController_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsCABPPageController_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsCABPPageController_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsCABPPageController_OnSetObject(This,pIVsCABPPageSettings)	\
    (This)->lpVtbl -> OnSetObject(This,pIVsCABPPageSettings)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsCABPPageController_OnSetObject_Proxy( 
    IVsCABPPageController * This,
    /* [in] */ IVsCABPPageSettings *pIVsCABPPageSettings);


void __RPC_STUB IVsCABPPageController_OnSetObject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsCABPPageController_INTERFACE_DEFINED__ */


#ifndef __IVsCABPPageSettings_INTERFACE_DEFINED__
#define __IVsCABPPageSettings_INTERFACE_DEFINED__

/* interface IVsCABPPageSettings */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsCABPPageSettings;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("52383872-c56b-11d0-8a49-00a0c91e2acd")
    IVsCABPPageSettings : public IUnknown
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IVsCABPPageSettingsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsCABPPageSettings * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsCABPPageSettings * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsCABPPageSettings * This);
        
        END_INTERFACE
    } IVsCABPPageSettingsVtbl;

    interface IVsCABPPageSettings
    {
        CONST_VTBL struct IVsCABPPageSettingsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsCABPPageSettings_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsCABPPageSettings_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsCABPPageSettings_Release(This)	\
    (This)->lpVtbl -> Release(This)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVsCABPPageSettings_INTERFACE_DEFINED__ */


#ifndef __IVsCABProperties_INTERFACE_DEFINED__
#define __IVsCABProperties_INTERFACE_DEFINED__

/* interface IVsCABProperties */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsCABProperties;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("52383873-c56b-11d0-8a49-00a0c91e2acd")
    IVsCABProperties : public IVsPackagingPropertyObject
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE get_CompressionType( 
            /* [in] */ ULONG cchBuffer,
            /* [size_is][out][in] */ OLECHAR szBuffer[  ],
            /* [out] */ ULONG *pcchActual) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_CompressionType( 
            /* [in] */ LPCOLESTR sz) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumCompressionTypes( 
            /* [out] */ IVsEnumBSTRs **ppIVsEnumBSTRs) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_FilenameCodePage( 
            /* [out] */ UINT *puiCodePage) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_FilenameCodePage( 
            /* [in] */ UINT uiCodePage) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_StoreUTF8( 
            /* [out] */ BOOL *fStoreUTF8) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_StoreUTF8( 
            /* [in] */ BOOL fStoreUTF8) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsCABPropertiesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsCABProperties * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsCABProperties * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsCABProperties * This);
        
        HRESULT ( STDMETHODCALLTYPE *get_PackagingEnginePropertyInterfaceBroker )( 
            IVsCABProperties * This,
            /* [out] */ IVsPackagingEnginePropertyInterfaceBroker **ppIVsPackagingEnginePropertyInterfaceBroker);
        
        HRESULT ( STDMETHODCALLTYPE *put_PackagingEnginePropertyInterfaceBroker )( 
            IVsCABProperties * This,
            /* [in] */ IVsPackagingEnginePropertyInterfaceBroker *pIVsPackagingEnginePropertyInterfaceBroker);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IVsCABProperties * This,
            /* [out] */ IVsPackagingPropertyObject **ppIVsPackagingPropertyObject);
        
        HRESULT ( STDMETHODCALLTYPE *Merge )( 
            IVsCABProperties * This,
            /* [in] */ IVsPackagingPropertyObject *pIVsPackagingPropertyObject);
        
        HRESULT ( STDMETHODCALLTYPE *Close )( 
            IVsCABProperties * This);
        
        HRESULT ( STDMETHODCALLTYPE *get_OutputFilename )( 
            IVsCABProperties * This,
            /* [in] */ ULONG cchBuffer,
            /* [size_is][out][in] */ OLECHAR rgochBuffer[  ],
            /* [out] */ ULONG *pcchActual);
        
        HRESULT ( STDMETHODCALLTYPE *put_OutputFilename )( 
            IVsCABProperties * This,
            /* [in] */ LPCOLESTR szFilename);
        
        HRESULT ( STDMETHODCALLTYPE *get_BaseDirectory )( 
            IVsCABProperties * This,
            /* [in] */ ULONG cchBuffer,
            /* [size_is][out][in] */ OLECHAR rgochBuffer[  ],
            /* [out] */ ULONG *pcchActual);
        
        HRESULT ( STDMETHODCALLTYPE *put_BaseDirectory )( 
            IVsCABProperties * This,
            /* [in] */ LPCOLESTR szBaseDirectory);
        
        HRESULT ( STDMETHODCALLTYPE *get_CompressionType )( 
            IVsCABProperties * This,
            /* [in] */ ULONG cchBuffer,
            /* [size_is][out][in] */ OLECHAR szBuffer[  ],
            /* [out] */ ULONG *pcchActual);
        
        HRESULT ( STDMETHODCALLTYPE *put_CompressionType )( 
            IVsCABProperties * This,
            /* [in] */ LPCOLESTR sz);
        
        HRESULT ( STDMETHODCALLTYPE *EnumCompressionTypes )( 
            IVsCABProperties * This,
            /* [out] */ IVsEnumBSTRs **ppIVsEnumBSTRs);
        
        HRESULT ( STDMETHODCALLTYPE *get_FilenameCodePage )( 
            IVsCABProperties * This,
            /* [out] */ UINT *puiCodePage);
        
        HRESULT ( STDMETHODCALLTYPE *put_FilenameCodePage )( 
            IVsCABProperties * This,
            /* [in] */ UINT uiCodePage);
        
        HRESULT ( STDMETHODCALLTYPE *get_StoreUTF8 )( 
            IVsCABProperties * This,
            /* [out] */ BOOL *fStoreUTF8);
        
        HRESULT ( STDMETHODCALLTYPE *put_StoreUTF8 )( 
            IVsCABProperties * This,
            /* [in] */ BOOL fStoreUTF8);
        
        END_INTERFACE
    } IVsCABPropertiesVtbl;

    interface IVsCABProperties
    {
        CONST_VTBL struct IVsCABPropertiesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsCABProperties_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsCABProperties_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsCABProperties_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsCABProperties_get_PackagingEnginePropertyInterfaceBroker(This,ppIVsPackagingEnginePropertyInterfaceBroker)	\
    (This)->lpVtbl -> get_PackagingEnginePropertyInterfaceBroker(This,ppIVsPackagingEnginePropertyInterfaceBroker)

#define IVsCABProperties_put_PackagingEnginePropertyInterfaceBroker(This,pIVsPackagingEnginePropertyInterfaceBroker)	\
    (This)->lpVtbl -> put_PackagingEnginePropertyInterfaceBroker(This,pIVsPackagingEnginePropertyInterfaceBroker)

#define IVsCABProperties_Clone(This,ppIVsPackagingPropertyObject)	\
    (This)->lpVtbl -> Clone(This,ppIVsPackagingPropertyObject)

#define IVsCABProperties_Merge(This,pIVsPackagingPropertyObject)	\
    (This)->lpVtbl -> Merge(This,pIVsPackagingPropertyObject)

#define IVsCABProperties_Close(This)	\
    (This)->lpVtbl -> Close(This)

#define IVsCABProperties_get_OutputFilename(This,cchBuffer,rgochBuffer,pcchActual)	\
    (This)->lpVtbl -> get_OutputFilename(This,cchBuffer,rgochBuffer,pcchActual)

#define IVsCABProperties_put_OutputFilename(This,szFilename)	\
    (This)->lpVtbl -> put_OutputFilename(This,szFilename)

#define IVsCABProperties_get_BaseDirectory(This,cchBuffer,rgochBuffer,pcchActual)	\
    (This)->lpVtbl -> get_BaseDirectory(This,cchBuffer,rgochBuffer,pcchActual)

#define IVsCABProperties_put_BaseDirectory(This,szBaseDirectory)	\
    (This)->lpVtbl -> put_BaseDirectory(This,szBaseDirectory)


#define IVsCABProperties_get_CompressionType(This,cchBuffer,szBuffer,pcchActual)	\
    (This)->lpVtbl -> get_CompressionType(This,cchBuffer,szBuffer,pcchActual)

#define IVsCABProperties_put_CompressionType(This,sz)	\
    (This)->lpVtbl -> put_CompressionType(This,sz)

#define IVsCABProperties_EnumCompressionTypes(This,ppIVsEnumBSTRs)	\
    (This)->lpVtbl -> EnumCompressionTypes(This,ppIVsEnumBSTRs)

#define IVsCABProperties_get_FilenameCodePage(This,puiCodePage)	\
    (This)->lpVtbl -> get_FilenameCodePage(This,puiCodePage)

#define IVsCABProperties_put_FilenameCodePage(This,uiCodePage)	\
    (This)->lpVtbl -> put_FilenameCodePage(This,uiCodePage)

#define IVsCABProperties_get_StoreUTF8(This,fStoreUTF8)	\
    (This)->lpVtbl -> get_StoreUTF8(This,fStoreUTF8)

#define IVsCABProperties_put_StoreUTF8(This,fStoreUTF8)	\
    (This)->lpVtbl -> put_StoreUTF8(This,fStoreUTF8)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsCABProperties_get_CompressionType_Proxy( 
    IVsCABProperties * This,
    /* [in] */ ULONG cchBuffer,
    /* [size_is][out][in] */ OLECHAR szBuffer[  ],
    /* [out] */ ULONG *pcchActual);


void __RPC_STUB IVsCABProperties_get_CompressionType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsCABProperties_put_CompressionType_Proxy( 
    IVsCABProperties * This,
    /* [in] */ LPCOLESTR sz);


void __RPC_STUB IVsCABProperties_put_CompressionType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsCABProperties_EnumCompressionTypes_Proxy( 
    IVsCABProperties * This,
    /* [out] */ IVsEnumBSTRs **ppIVsEnumBSTRs);


void __RPC_STUB IVsCABProperties_EnumCompressionTypes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsCABProperties_get_FilenameCodePage_Proxy( 
    IVsCABProperties * This,
    /* [out] */ UINT *puiCodePage);


void __RPC_STUB IVsCABProperties_get_FilenameCodePage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsCABProperties_put_FilenameCodePage_Proxy( 
    IVsCABProperties * This,
    /* [in] */ UINT uiCodePage);


void __RPC_STUB IVsCABProperties_put_FilenameCodePage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsCABProperties_get_StoreUTF8_Proxy( 
    IVsCABProperties * This,
    /* [out] */ BOOL *fStoreUTF8);


void __RPC_STUB IVsCABProperties_get_StoreUTF8_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsCABProperties_put_StoreUTF8_Proxy( 
    IVsCABProperties * This,
    /* [in] */ BOOL fStoreUTF8);


void __RPC_STUB IVsCABProperties_put_StoreUTF8_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsCABProperties_INTERFACE_DEFINED__ */


#ifndef __IVsSigningProperties_INTERFACE_DEFINED__
#define __IVsSigningProperties_INTERFACE_DEFINED__

/* interface IVsSigningProperties */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsSigningProperties;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a57e3d86-d2d3-11d0-8a50-00a0c91e2acd")
    IVsSigningProperties : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE get_SigningEnabled( 
            /* [out] */ BOOL *fSigningEnabled) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_SigningEnabled( 
            /* [in] */ BOOL fSigningEnabled) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_SPCFilename( 
            /* [in] */ ULONG cchBuffer,
            /* [size_is][out][in] */ OLECHAR szBuffer[  ],
            /* [out] */ ULONG *pcchActual) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_SPCFilename( 
            /* [in] */ LPCOLESTR szFilename) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_KeyName( 
            /* [in] */ ULONG cchBuffer,
            /* [size_is][out][in] */ OLECHAR szBuffer[  ],
            /* [out] */ ULONG *pcchActual) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_KeyName( 
            /* [in] */ LPCOLESTR szFilename) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_SelectCertificate( 
            /* [out] */ BOOL *fActiveXControls) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_SelectCertificate( 
            /* [in] */ BOOL fActiveXControls) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_TimeserverURL( 
            /* [in] */ ULONG cchBuffer,
            /* [size_is][out][in] */ OLECHAR szBuffer[  ],
            /* [out] */ ULONG *pcchActual) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_TimeserverURL( 
            /* [in] */ LPCOLESTR szTimeserverURL) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsSigningPropertiesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsSigningProperties * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsSigningProperties * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsSigningProperties * This);
        
        HRESULT ( STDMETHODCALLTYPE *get_SigningEnabled )( 
            IVsSigningProperties * This,
            /* [out] */ BOOL *fSigningEnabled);
        
        HRESULT ( STDMETHODCALLTYPE *put_SigningEnabled )( 
            IVsSigningProperties * This,
            /* [in] */ BOOL fSigningEnabled);
        
        HRESULT ( STDMETHODCALLTYPE *get_SPCFilename )( 
            IVsSigningProperties * This,
            /* [in] */ ULONG cchBuffer,
            /* [size_is][out][in] */ OLECHAR szBuffer[  ],
            /* [out] */ ULONG *pcchActual);
        
        HRESULT ( STDMETHODCALLTYPE *put_SPCFilename )( 
            IVsSigningProperties * This,
            /* [in] */ LPCOLESTR szFilename);
        
        HRESULT ( STDMETHODCALLTYPE *get_KeyName )( 
            IVsSigningProperties * This,
            /* [in] */ ULONG cchBuffer,
            /* [size_is][out][in] */ OLECHAR szBuffer[  ],
            /* [out] */ ULONG *pcchActual);
        
        HRESULT ( STDMETHODCALLTYPE *put_KeyName )( 
            IVsSigningProperties * This,
            /* [in] */ LPCOLESTR szFilename);
        
        HRESULT ( STDMETHODCALLTYPE *get_SelectCertificate )( 
            IVsSigningProperties * This,
            /* [out] */ BOOL *fActiveXControls);
        
        HRESULT ( STDMETHODCALLTYPE *put_SelectCertificate )( 
            IVsSigningProperties * This,
            /* [in] */ BOOL fActiveXControls);
        
        HRESULT ( STDMETHODCALLTYPE *get_TimeserverURL )( 
            IVsSigningProperties * This,
            /* [in] */ ULONG cchBuffer,
            /* [size_is][out][in] */ OLECHAR szBuffer[  ],
            /* [out] */ ULONG *pcchActual);
        
        HRESULT ( STDMETHODCALLTYPE *put_TimeserverURL )( 
            IVsSigningProperties * This,
            /* [in] */ LPCOLESTR szTimeserverURL);
        
        END_INTERFACE
    } IVsSigningPropertiesVtbl;

    interface IVsSigningProperties
    {
        CONST_VTBL struct IVsSigningPropertiesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsSigningProperties_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsSigningProperties_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsSigningProperties_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsSigningProperties_get_SigningEnabled(This,fSigningEnabled)	\
    (This)->lpVtbl -> get_SigningEnabled(This,fSigningEnabled)

#define IVsSigningProperties_put_SigningEnabled(This,fSigningEnabled)	\
    (This)->lpVtbl -> put_SigningEnabled(This,fSigningEnabled)

#define IVsSigningProperties_get_SPCFilename(This,cchBuffer,szBuffer,pcchActual)	\
    (This)->lpVtbl -> get_SPCFilename(This,cchBuffer,szBuffer,pcchActual)

#define IVsSigningProperties_put_SPCFilename(This,szFilename)	\
    (This)->lpVtbl -> put_SPCFilename(This,szFilename)

#define IVsSigningProperties_get_KeyName(This,cchBuffer,szBuffer,pcchActual)	\
    (This)->lpVtbl -> get_KeyName(This,cchBuffer,szBuffer,pcchActual)

#define IVsSigningProperties_put_KeyName(This,szFilename)	\
    (This)->lpVtbl -> put_KeyName(This,szFilename)

#define IVsSigningProperties_get_SelectCertificate(This,fActiveXControls)	\
    (This)->lpVtbl -> get_SelectCertificate(This,fActiveXControls)

#define IVsSigningProperties_put_SelectCertificate(This,fActiveXControls)	\
    (This)->lpVtbl -> put_SelectCertificate(This,fActiveXControls)

#define IVsSigningProperties_get_TimeserverURL(This,cchBuffer,szBuffer,pcchActual)	\
    (This)->lpVtbl -> get_TimeserverURL(This,cchBuffer,szBuffer,pcchActual)

#define IVsSigningProperties_put_TimeserverURL(This,szTimeserverURL)	\
    (This)->lpVtbl -> put_TimeserverURL(This,szTimeserverURL)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsSigningProperties_get_SigningEnabled_Proxy( 
    IVsSigningProperties * This,
    /* [out] */ BOOL *fSigningEnabled);


void __RPC_STUB IVsSigningProperties_get_SigningEnabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSigningProperties_put_SigningEnabled_Proxy( 
    IVsSigningProperties * This,
    /* [in] */ BOOL fSigningEnabled);


void __RPC_STUB IVsSigningProperties_put_SigningEnabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSigningProperties_get_SPCFilename_Proxy( 
    IVsSigningProperties * This,
    /* [in] */ ULONG cchBuffer,
    /* [size_is][out][in] */ OLECHAR szBuffer[  ],
    /* [out] */ ULONG *pcchActual);


void __RPC_STUB IVsSigningProperties_get_SPCFilename_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSigningProperties_put_SPCFilename_Proxy( 
    IVsSigningProperties * This,
    /* [in] */ LPCOLESTR szFilename);


void __RPC_STUB IVsSigningProperties_put_SPCFilename_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSigningProperties_get_KeyName_Proxy( 
    IVsSigningProperties * This,
    /* [in] */ ULONG cchBuffer,
    /* [size_is][out][in] */ OLECHAR szBuffer[  ],
    /* [out] */ ULONG *pcchActual);


void __RPC_STUB IVsSigningProperties_get_KeyName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSigningProperties_put_KeyName_Proxy( 
    IVsSigningProperties * This,
    /* [in] */ LPCOLESTR szFilename);


void __RPC_STUB IVsSigningProperties_put_KeyName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSigningProperties_get_SelectCertificate_Proxy( 
    IVsSigningProperties * This,
    /* [out] */ BOOL *fActiveXControls);


void __RPC_STUB IVsSigningProperties_get_SelectCertificate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSigningProperties_put_SelectCertificate_Proxy( 
    IVsSigningProperties * This,
    /* [in] */ BOOL fActiveXControls);


void __RPC_STUB IVsSigningProperties_put_SelectCertificate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSigningProperties_get_TimeserverURL_Proxy( 
    IVsSigningProperties * This,
    /* [in] */ ULONG cchBuffer,
    /* [size_is][out][in] */ OLECHAR szBuffer[  ],
    /* [out] */ ULONG *pcchActual);


void __RPC_STUB IVsSigningProperties_get_TimeserverURL_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSigningProperties_put_TimeserverURL_Proxy( 
    IVsSigningProperties * This,
    /* [in] */ LPCOLESTR szTimeserverURL);


void __RPC_STUB IVsSigningProperties_put_TimeserverURL_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsSigningProperties_INTERFACE_DEFINED__ */


#ifndef __IVsSigningJavaPermissionProperties_INTERFACE_DEFINED__
#define __IVsSigningJavaPermissionProperties_INTERFACE_DEFINED__

/* interface IVsSigningJavaPermissionProperties */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsSigningJavaPermissionProperties;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a57e3d87-d2d3-11d0-8a50-00a0c91e2acd")
    IVsSigningJavaPermissionProperties : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE get_JavaPermissionsEnabled( 
            /* [out] */ BOOL *fJavaPermissionsEnabled) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_JavaPermissionsEnabled( 
            /* [in] */ BOOL fJavaPermissionsEnabled) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_ActiveXControls( 
            /* [out] */ BOOL *fActiveXControls) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_ActiveXControls( 
            /* [in] */ BOOL fActiveXControls) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_PermissionLevel( 
            /* [in] */ ULONG cchBuffer,
            /* [size_is][out][in] */ OLECHAR szBuffer[  ],
            /* [out] */ ULONG *pcchActual) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_PermissionLevel( 
            /* [in] */ LPCOLESTR szFilename) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_CustomPermissionCollection( 
            /* [out] */ IVsVMPermissionCollection **ppIVsVMPermissionCollection) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_CustomPermissionCollection( 
            /* [in] */ IVsVMPermissionCollection *pIVsVMPermissionCollection) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsSigningJavaPermissionPropertiesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsSigningJavaPermissionProperties * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsSigningJavaPermissionProperties * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsSigningJavaPermissionProperties * This);
        
        HRESULT ( STDMETHODCALLTYPE *get_JavaPermissionsEnabled )( 
            IVsSigningJavaPermissionProperties * This,
            /* [out] */ BOOL *fJavaPermissionsEnabled);
        
        HRESULT ( STDMETHODCALLTYPE *put_JavaPermissionsEnabled )( 
            IVsSigningJavaPermissionProperties * This,
            /* [in] */ BOOL fJavaPermissionsEnabled);
        
        HRESULT ( STDMETHODCALLTYPE *get_ActiveXControls )( 
            IVsSigningJavaPermissionProperties * This,
            /* [out] */ BOOL *fActiveXControls);
        
        HRESULT ( STDMETHODCALLTYPE *put_ActiveXControls )( 
            IVsSigningJavaPermissionProperties * This,
            /* [in] */ BOOL fActiveXControls);
        
        HRESULT ( STDMETHODCALLTYPE *get_PermissionLevel )( 
            IVsSigningJavaPermissionProperties * This,
            /* [in] */ ULONG cchBuffer,
            /* [size_is][out][in] */ OLECHAR szBuffer[  ],
            /* [out] */ ULONG *pcchActual);
        
        HRESULT ( STDMETHODCALLTYPE *put_PermissionLevel )( 
            IVsSigningJavaPermissionProperties * This,
            /* [in] */ LPCOLESTR szFilename);
        
        HRESULT ( STDMETHODCALLTYPE *get_CustomPermissionCollection )( 
            IVsSigningJavaPermissionProperties * This,
            /* [out] */ IVsVMPermissionCollection **ppIVsVMPermissionCollection);
        
        HRESULT ( STDMETHODCALLTYPE *put_CustomPermissionCollection )( 
            IVsSigningJavaPermissionProperties * This,
            /* [in] */ IVsVMPermissionCollection *pIVsVMPermissionCollection);
        
        END_INTERFACE
    } IVsSigningJavaPermissionPropertiesVtbl;

    interface IVsSigningJavaPermissionProperties
    {
        CONST_VTBL struct IVsSigningJavaPermissionPropertiesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsSigningJavaPermissionProperties_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsSigningJavaPermissionProperties_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsSigningJavaPermissionProperties_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsSigningJavaPermissionProperties_get_JavaPermissionsEnabled(This,fJavaPermissionsEnabled)	\
    (This)->lpVtbl -> get_JavaPermissionsEnabled(This,fJavaPermissionsEnabled)

#define IVsSigningJavaPermissionProperties_put_JavaPermissionsEnabled(This,fJavaPermissionsEnabled)	\
    (This)->lpVtbl -> put_JavaPermissionsEnabled(This,fJavaPermissionsEnabled)

#define IVsSigningJavaPermissionProperties_get_ActiveXControls(This,fActiveXControls)	\
    (This)->lpVtbl -> get_ActiveXControls(This,fActiveXControls)

#define IVsSigningJavaPermissionProperties_put_ActiveXControls(This,fActiveXControls)	\
    (This)->lpVtbl -> put_ActiveXControls(This,fActiveXControls)

#define IVsSigningJavaPermissionProperties_get_PermissionLevel(This,cchBuffer,szBuffer,pcchActual)	\
    (This)->lpVtbl -> get_PermissionLevel(This,cchBuffer,szBuffer,pcchActual)

#define IVsSigningJavaPermissionProperties_put_PermissionLevel(This,szFilename)	\
    (This)->lpVtbl -> put_PermissionLevel(This,szFilename)

#define IVsSigningJavaPermissionProperties_get_CustomPermissionCollection(This,ppIVsVMPermissionCollection)	\
    (This)->lpVtbl -> get_CustomPermissionCollection(This,ppIVsVMPermissionCollection)

#define IVsSigningJavaPermissionProperties_put_CustomPermissionCollection(This,pIVsVMPermissionCollection)	\
    (This)->lpVtbl -> put_CustomPermissionCollection(This,pIVsVMPermissionCollection)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsSigningJavaPermissionProperties_get_JavaPermissionsEnabled_Proxy( 
    IVsSigningJavaPermissionProperties * This,
    /* [out] */ BOOL *fJavaPermissionsEnabled);


void __RPC_STUB IVsSigningJavaPermissionProperties_get_JavaPermissionsEnabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSigningJavaPermissionProperties_put_JavaPermissionsEnabled_Proxy( 
    IVsSigningJavaPermissionProperties * This,
    /* [in] */ BOOL fJavaPermissionsEnabled);


void __RPC_STUB IVsSigningJavaPermissionProperties_put_JavaPermissionsEnabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSigningJavaPermissionProperties_get_ActiveXControls_Proxy( 
    IVsSigningJavaPermissionProperties * This,
    /* [out] */ BOOL *fActiveXControls);


void __RPC_STUB IVsSigningJavaPermissionProperties_get_ActiveXControls_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSigningJavaPermissionProperties_put_ActiveXControls_Proxy( 
    IVsSigningJavaPermissionProperties * This,
    /* [in] */ BOOL fActiveXControls);


void __RPC_STUB IVsSigningJavaPermissionProperties_put_ActiveXControls_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSigningJavaPermissionProperties_get_PermissionLevel_Proxy( 
    IVsSigningJavaPermissionProperties * This,
    /* [in] */ ULONG cchBuffer,
    /* [size_is][out][in] */ OLECHAR szBuffer[  ],
    /* [out] */ ULONG *pcchActual);


void __RPC_STUB IVsSigningJavaPermissionProperties_get_PermissionLevel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSigningJavaPermissionProperties_put_PermissionLevel_Proxy( 
    IVsSigningJavaPermissionProperties * This,
    /* [in] */ LPCOLESTR szFilename);


void __RPC_STUB IVsSigningJavaPermissionProperties_put_PermissionLevel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSigningJavaPermissionProperties_get_CustomPermissionCollection_Proxy( 
    IVsSigningJavaPermissionProperties * This,
    /* [out] */ IVsVMPermissionCollection **ppIVsVMPermissionCollection);


void __RPC_STUB IVsSigningJavaPermissionProperties_get_CustomPermissionCollection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSigningJavaPermissionProperties_put_CustomPermissionCollection_Proxy( 
    IVsSigningJavaPermissionProperties * This,
    /* [in] */ IVsVMPermissionCollection *pIVsVMPermissionCollection);


void __RPC_STUB IVsSigningJavaPermissionProperties_put_CustomPermissionCollection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsSigningJavaPermissionProperties_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vspkg_0705 */
/* [local] */ 

#define VS_OSD_CONTAINS_UNPACKAGED_CLASSES	0x01
#define VS_OSD_CONTAINS_PACKAGES				0x02
#define VS_OSD_CONTAINS_NATIVECODE			0x04
#define VS_OSD_CONTAINS_JAVA_CLASSES			0x08


extern RPC_IF_HANDLE __MIDL_itf_vspkg_0705_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vspkg_0705_v0_0_s_ifspec;

#ifndef __IVsOSDProperties_INTERFACE_DEFINED__
#define __IVsOSDProperties_INTERFACE_DEFINED__

/* interface IVsOSDProperties */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsOSDProperties;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a57e3d88-d2d3-11d0-8a50-00a0c91e2acd")
    IVsOSDProperties : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE get_WebLibraryCollection( 
            /* [out] */ IVsWebLibraryCollection **ppIVsWebLibraryCollection) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_WebLibraryCollection( 
            /* [in] */ IVsWebLibraryCollection *pIVsWebLibaryCollection) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_ExternalDependencyCollection( 
            /* [out] */ IVsAdditionalItemCollection **ppIVsAdditionalItemCollection) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_ExternalDependencyCollection( 
            /* [in] */ IVsAdditionalItemCollection *pIVsAdditionalItemCollection) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_FriendlyName( 
            /* [in] */ ULONG cchBuffer,
            /* [size_is][out][in] */ OLECHAR szBuffer[  ],
            /* [out] */ ULONG *pcchActual) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_FriendlyName( 
            /* [in] */ LPCOLESTR szFriendlyName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_VersionString( 
            /* [in] */ ULONG cchBuffer,
            /* [size_is][out][in] */ OLECHAR szBuffer[  ],
            /* [out] */ ULONG *pcchActual) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_VersionString( 
            /* [in] */ LPCOLESTR szVersionString) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_Namespace( 
            /* [in] */ ULONG cchBuffer,
            /* [size_is][out][in] */ OLECHAR szBuffer[  ],
            /* [out] */ ULONG *pcchActual) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_Namespace( 
            /* [in] */ LPCOLESTR szNamespaceString) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_IsSystem( 
            /* [out] */ BOOL *pfIsSystem) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_IsSystem( 
            /* [in] */ BOOL fIsSystem) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_NeedsTrustedSource( 
            /* [out] */ BOOL *pfNeedsTrustedSource) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_NeedsTrustedSource( 
            /* [in] */ BOOL fNeedsTrustedSource) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsOSDPropertiesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsOSDProperties * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsOSDProperties * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsOSDProperties * This);
        
        HRESULT ( STDMETHODCALLTYPE *get_WebLibraryCollection )( 
            IVsOSDProperties * This,
            /* [out] */ IVsWebLibraryCollection **ppIVsWebLibraryCollection);
        
        HRESULT ( STDMETHODCALLTYPE *put_WebLibraryCollection )( 
            IVsOSDProperties * This,
            /* [in] */ IVsWebLibraryCollection *pIVsWebLibaryCollection);
        
        HRESULT ( STDMETHODCALLTYPE *get_ExternalDependencyCollection )( 
            IVsOSDProperties * This,
            /* [out] */ IVsAdditionalItemCollection **ppIVsAdditionalItemCollection);
        
        HRESULT ( STDMETHODCALLTYPE *put_ExternalDependencyCollection )( 
            IVsOSDProperties * This,
            /* [in] */ IVsAdditionalItemCollection *pIVsAdditionalItemCollection);
        
        HRESULT ( STDMETHODCALLTYPE *get_FriendlyName )( 
            IVsOSDProperties * This,
            /* [in] */ ULONG cchBuffer,
            /* [size_is][out][in] */ OLECHAR szBuffer[  ],
            /* [out] */ ULONG *pcchActual);
        
        HRESULT ( STDMETHODCALLTYPE *put_FriendlyName )( 
            IVsOSDProperties * This,
            /* [in] */ LPCOLESTR szFriendlyName);
        
        HRESULT ( STDMETHODCALLTYPE *get_VersionString )( 
            IVsOSDProperties * This,
            /* [in] */ ULONG cchBuffer,
            /* [size_is][out][in] */ OLECHAR szBuffer[  ],
            /* [out] */ ULONG *pcchActual);
        
        HRESULT ( STDMETHODCALLTYPE *put_VersionString )( 
            IVsOSDProperties * This,
            /* [in] */ LPCOLESTR szVersionString);
        
        HRESULT ( STDMETHODCALLTYPE *get_Namespace )( 
            IVsOSDProperties * This,
            /* [in] */ ULONG cchBuffer,
            /* [size_is][out][in] */ OLECHAR szBuffer[  ],
            /* [out] */ ULONG *pcchActual);
        
        HRESULT ( STDMETHODCALLTYPE *put_Namespace )( 
            IVsOSDProperties * This,
            /* [in] */ LPCOLESTR szNamespaceString);
        
        HRESULT ( STDMETHODCALLTYPE *get_IsSystem )( 
            IVsOSDProperties * This,
            /* [out] */ BOOL *pfIsSystem);
        
        HRESULT ( STDMETHODCALLTYPE *put_IsSystem )( 
            IVsOSDProperties * This,
            /* [in] */ BOOL fIsSystem);
        
        HRESULT ( STDMETHODCALLTYPE *get_NeedsTrustedSource )( 
            IVsOSDProperties * This,
            /* [out] */ BOOL *pfNeedsTrustedSource);
        
        HRESULT ( STDMETHODCALLTYPE *put_NeedsTrustedSource )( 
            IVsOSDProperties * This,
            /* [in] */ BOOL fNeedsTrustedSource);
        
        END_INTERFACE
    } IVsOSDPropertiesVtbl;

    interface IVsOSDProperties
    {
        CONST_VTBL struct IVsOSDPropertiesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsOSDProperties_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsOSDProperties_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsOSDProperties_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsOSDProperties_get_WebLibraryCollection(This,ppIVsWebLibraryCollection)	\
    (This)->lpVtbl -> get_WebLibraryCollection(This,ppIVsWebLibraryCollection)

#define IVsOSDProperties_put_WebLibraryCollection(This,pIVsWebLibaryCollection)	\
    (This)->lpVtbl -> put_WebLibraryCollection(This,pIVsWebLibaryCollection)

#define IVsOSDProperties_get_ExternalDependencyCollection(This,ppIVsAdditionalItemCollection)	\
    (This)->lpVtbl -> get_ExternalDependencyCollection(This,ppIVsAdditionalItemCollection)

#define IVsOSDProperties_put_ExternalDependencyCollection(This,pIVsAdditionalItemCollection)	\
    (This)->lpVtbl -> put_ExternalDependencyCollection(This,pIVsAdditionalItemCollection)

#define IVsOSDProperties_get_FriendlyName(This,cchBuffer,szBuffer,pcchActual)	\
    (This)->lpVtbl -> get_FriendlyName(This,cchBuffer,szBuffer,pcchActual)

#define IVsOSDProperties_put_FriendlyName(This,szFriendlyName)	\
    (This)->lpVtbl -> put_FriendlyName(This,szFriendlyName)

#define IVsOSDProperties_get_VersionString(This,cchBuffer,szBuffer,pcchActual)	\
    (This)->lpVtbl -> get_VersionString(This,cchBuffer,szBuffer,pcchActual)

#define IVsOSDProperties_put_VersionString(This,szVersionString)	\
    (This)->lpVtbl -> put_VersionString(This,szVersionString)

#define IVsOSDProperties_get_Namespace(This,cchBuffer,szBuffer,pcchActual)	\
    (This)->lpVtbl -> get_Namespace(This,cchBuffer,szBuffer,pcchActual)

#define IVsOSDProperties_put_Namespace(This,szNamespaceString)	\
    (This)->lpVtbl -> put_Namespace(This,szNamespaceString)

#define IVsOSDProperties_get_IsSystem(This,pfIsSystem)	\
    (This)->lpVtbl -> get_IsSystem(This,pfIsSystem)

#define IVsOSDProperties_put_IsSystem(This,fIsSystem)	\
    (This)->lpVtbl -> put_IsSystem(This,fIsSystem)

#define IVsOSDProperties_get_NeedsTrustedSource(This,pfNeedsTrustedSource)	\
    (This)->lpVtbl -> get_NeedsTrustedSource(This,pfNeedsTrustedSource)

#define IVsOSDProperties_put_NeedsTrustedSource(This,fNeedsTrustedSource)	\
    (This)->lpVtbl -> put_NeedsTrustedSource(This,fNeedsTrustedSource)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsOSDProperties_get_WebLibraryCollection_Proxy( 
    IVsOSDProperties * This,
    /* [out] */ IVsWebLibraryCollection **ppIVsWebLibraryCollection);


void __RPC_STUB IVsOSDProperties_get_WebLibraryCollection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsOSDProperties_put_WebLibraryCollection_Proxy( 
    IVsOSDProperties * This,
    /* [in] */ IVsWebLibraryCollection *pIVsWebLibaryCollection);


void __RPC_STUB IVsOSDProperties_put_WebLibraryCollection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsOSDProperties_get_ExternalDependencyCollection_Proxy( 
    IVsOSDProperties * This,
    /* [out] */ IVsAdditionalItemCollection **ppIVsAdditionalItemCollection);


void __RPC_STUB IVsOSDProperties_get_ExternalDependencyCollection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsOSDProperties_put_ExternalDependencyCollection_Proxy( 
    IVsOSDProperties * This,
    /* [in] */ IVsAdditionalItemCollection *pIVsAdditionalItemCollection);


void __RPC_STUB IVsOSDProperties_put_ExternalDependencyCollection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsOSDProperties_get_FriendlyName_Proxy( 
    IVsOSDProperties * This,
    /* [in] */ ULONG cchBuffer,
    /* [size_is][out][in] */ OLECHAR szBuffer[  ],
    /* [out] */ ULONG *pcchActual);


void __RPC_STUB IVsOSDProperties_get_FriendlyName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsOSDProperties_put_FriendlyName_Proxy( 
    IVsOSDProperties * This,
    /* [in] */ LPCOLESTR szFriendlyName);


void __RPC_STUB IVsOSDProperties_put_FriendlyName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsOSDProperties_get_VersionString_Proxy( 
    IVsOSDProperties * This,
    /* [in] */ ULONG cchBuffer,
    /* [size_is][out][in] */ OLECHAR szBuffer[  ],
    /* [out] */ ULONG *pcchActual);


void __RPC_STUB IVsOSDProperties_get_VersionString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsOSDProperties_put_VersionString_Proxy( 
    IVsOSDProperties * This,
    /* [in] */ LPCOLESTR szVersionString);


void __RPC_STUB IVsOSDProperties_put_VersionString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsOSDProperties_get_Namespace_Proxy( 
    IVsOSDProperties * This,
    /* [in] */ ULONG cchBuffer,
    /* [size_is][out][in] */ OLECHAR szBuffer[  ],
    /* [out] */ ULONG *pcchActual);


void __RPC_STUB IVsOSDProperties_get_Namespace_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsOSDProperties_put_Namespace_Proxy( 
    IVsOSDProperties * This,
    /* [in] */ LPCOLESTR szNamespaceString);


void __RPC_STUB IVsOSDProperties_put_Namespace_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsOSDProperties_get_IsSystem_Proxy( 
    IVsOSDProperties * This,
    /* [out] */ BOOL *pfIsSystem);


void __RPC_STUB IVsOSDProperties_get_IsSystem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsOSDProperties_put_IsSystem_Proxy( 
    IVsOSDProperties * This,
    /* [in] */ BOOL fIsSystem);


void __RPC_STUB IVsOSDProperties_put_IsSystem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsOSDProperties_get_NeedsTrustedSource_Proxy( 
    IVsOSDProperties * This,
    /* [out] */ BOOL *pfNeedsTrustedSource);


void __RPC_STUB IVsOSDProperties_get_NeedsTrustedSource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsOSDProperties_put_NeedsTrustedSource_Proxy( 
    IVsOSDProperties * This,
    /* [in] */ BOOL fNeedsTrustedSource);


void __RPC_STUB IVsOSDProperties_put_NeedsTrustedSource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsOSDProperties_INTERFACE_DEFINED__ */


#ifndef __IVsSetupPPageController_INTERFACE_DEFINED__
#define __IVsSetupPPageController_INTERFACE_DEFINED__

/* interface IVsSetupPPageController */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsSetupPPageController;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4C2B25CE-02F7-11d1-A4BE-006097C9933C")
    IVsSetupPPageController : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnSetObject( 
            /* [in] */ IVsSetupPPageSettings *pIVsSetupPPageSettings) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsSetupPPageControllerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsSetupPPageController * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsSetupPPageController * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsSetupPPageController * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnSetObject )( 
            IVsSetupPPageController * This,
            /* [in] */ IVsSetupPPageSettings *pIVsSetupPPageSettings);
        
        END_INTERFACE
    } IVsSetupPPageControllerVtbl;

    interface IVsSetupPPageController
    {
        CONST_VTBL struct IVsSetupPPageControllerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsSetupPPageController_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsSetupPPageController_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsSetupPPageController_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsSetupPPageController_OnSetObject(This,pIVsSetupPPageSettings)	\
    (This)->lpVtbl -> OnSetObject(This,pIVsSetupPPageSettings)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsSetupPPageController_OnSetObject_Proxy( 
    IVsSetupPPageController * This,
    /* [in] */ IVsSetupPPageSettings *pIVsSetupPPageSettings);


void __RPC_STUB IVsSetupPPageController_OnSetObject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsSetupPPageController_INTERFACE_DEFINED__ */


#ifndef __IVsSetupPPageSettings_INTERFACE_DEFINED__
#define __IVsSetupPPageSettings_INTERFACE_DEFINED__

/* interface IVsSetupPPageSettings */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsSetupPPageSettings;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4C2B25C9-02F7-11d1-A4BE-006097C9933C")
    IVsSetupPPageSettings : public IUnknown
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IVsSetupPPageSettingsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsSetupPPageSettings * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsSetupPPageSettings * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsSetupPPageSettings * This);
        
        END_INTERFACE
    } IVsSetupPPageSettingsVtbl;

    interface IVsSetupPPageSettings
    {
        CONST_VTBL struct IVsSetupPPageSettingsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsSetupPPageSettings_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsSetupPPageSettings_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsSetupPPageSettings_Release(This)	\
    (This)->lpVtbl -> Release(This)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVsSetupPPageSettings_INTERFACE_DEFINED__ */


#ifndef __IVsSetupProperties_INTERFACE_DEFINED__
#define __IVsSetupProperties_INTERFACE_DEFINED__

/* interface IVsSetupProperties */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsSetupProperties;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4C2B25C8-02F7-11d1-A4BE-006097C9933C")
    IVsSetupProperties : public IVsPackagingPropertyObject
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE get_AppName( 
            /* [out] */ BSTR *bstrInput) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_AppName( 
            /* [in] */ LPCOLESTR szFilename) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_InstallDirName( 
            /* [out] */ BSTR *bstrInput) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_InstallDirName( 
            /* [in] */ LPCOLESTR szFilename) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_StartName( 
            /* [out] */ BSTR *bstrInput) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_StartName( 
            /* [in] */ LPCOLESTR szFilename) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_StartInvokeEXE( 
            /* [out] */ BSTR *bstrInput) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_StartInvokeEXE( 
            /* [in] */ LPCOLESTR szFilename) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_StartInvokeArgument( 
            /* [out] */ BSTR *bstrInput) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_StartInvokeArgument( 
            /* [in] */ LPCOLESTR szFilename) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_IncludeAll( 
            /* [out] */ BOOL *pfvalue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_IncludeAll( 
            /* [in] */ BOOL fvalue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_CreateInProgramFiles( 
            /* [out] */ BOOL *pfvalue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_CreateInProgramFiles( 
            /* [in] */ BOOL fvalue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_CreateInStartMenu( 
            /* [out] */ BOOL *pfvalue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_CreateInStartMenu( 
            /* [in] */ BOOL fvalue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_EXEsToRun( 
            /* [in] */ ULONG cbstr,
            /* [unique][size_is][out][in] */ BSTR *rgbstrCanonicalNames,
            /* [out] */ ULONG *pcbstrActual) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_EXEsToRun( 
            /* [in] */ ULONG cbstr,
            /* [size_is][in] */ LPCOLESTR *prgszCanonicalNames) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_RemoteComponents( 
            /* [in] */ ULONG cbstr,
            /* [unique][size_is][out][in] */ BSTR *prgbstrCanonicalNames,
            /* [out] */ ULONG *pcbstrActual) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_RemoteComponents( 
            /* [in] */ ULONG cbstr,
            /* [size_is][in] */ LPCOLESTR *prgszCanonicalNames) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_RemoteServer( 
            /* [out] */ BSTR *bstrBuffer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_RemoteServer( 
            /* [in] */ LPCOLESTR szFilename) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_PromptAlways( 
            /* [out] */ BOOL *pfvalue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_PromptAlways( 
            /* [in] */ BOOL fvalue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_WebLibraryCollection( 
            /* [out] */ IVsWebLibraryCollection **ppIVsWebLibraryCollection) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_WebLibraryCollection( 
            /* [in] */ IVsWebLibraryCollection *pIVsWebLibaryCollection) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_ProjectName( 
            /* [in] */ ULONG cchBuffer,
            /* [size_is][out][in] */ OLECHAR rgochBuffer[  ],
            /* [out] */ ULONG *pcchActual) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_ProjectName( 
            /* [in] */ LPCOLESTR szProjectName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumEngineInputs( 
            /* [out] */ IVsEnumOutputs **ppIVsEnumOutputs) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumPossibleExposedObjects( 
            /* [out] */ IVsEnumExposedObjects **ppIVsEnumExposedObjects) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSolutionName( 
            /* [out] */ BSTR *bstrSol) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOutputDestination( 
            /* [in] */ LPCOLESTR szOutputCanonicalName,
            /* [out] */ BSTR *pbstrOutputDestination,
            /* [out] */ BOOL *pfReferenceCount,
            /* [out] */ BOOL *pfPromptForUninstallDelete) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsSetupPropertiesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsSetupProperties * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsSetupProperties * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsSetupProperties * This);
        
        HRESULT ( STDMETHODCALLTYPE *get_PackagingEnginePropertyInterfaceBroker )( 
            IVsSetupProperties * This,
            /* [out] */ IVsPackagingEnginePropertyInterfaceBroker **ppIVsPackagingEnginePropertyInterfaceBroker);
        
        HRESULT ( STDMETHODCALLTYPE *put_PackagingEnginePropertyInterfaceBroker )( 
            IVsSetupProperties * This,
            /* [in] */ IVsPackagingEnginePropertyInterfaceBroker *pIVsPackagingEnginePropertyInterfaceBroker);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IVsSetupProperties * This,
            /* [out] */ IVsPackagingPropertyObject **ppIVsPackagingPropertyObject);
        
        HRESULT ( STDMETHODCALLTYPE *Merge )( 
            IVsSetupProperties * This,
            /* [in] */ IVsPackagingPropertyObject *pIVsPackagingPropertyObject);
        
        HRESULT ( STDMETHODCALLTYPE *Close )( 
            IVsSetupProperties * This);
        
        HRESULT ( STDMETHODCALLTYPE *get_OutputFilename )( 
            IVsSetupProperties * This,
            /* [in] */ ULONG cchBuffer,
            /* [size_is][out][in] */ OLECHAR rgochBuffer[  ],
            /* [out] */ ULONG *pcchActual);
        
        HRESULT ( STDMETHODCALLTYPE *put_OutputFilename )( 
            IVsSetupProperties * This,
            /* [in] */ LPCOLESTR szFilename);
        
        HRESULT ( STDMETHODCALLTYPE *get_BaseDirectory )( 
            IVsSetupProperties * This,
            /* [in] */ ULONG cchBuffer,
            /* [size_is][out][in] */ OLECHAR rgochBuffer[  ],
            /* [out] */ ULONG *pcchActual);
        
        HRESULT ( STDMETHODCALLTYPE *put_BaseDirectory )( 
            IVsSetupProperties * This,
            /* [in] */ LPCOLESTR szBaseDirectory);
        
        HRESULT ( STDMETHODCALLTYPE *get_AppName )( 
            IVsSetupProperties * This,
            /* [out] */ BSTR *bstrInput);
        
        HRESULT ( STDMETHODCALLTYPE *put_AppName )( 
            IVsSetupProperties * This,
            /* [in] */ LPCOLESTR szFilename);
        
        HRESULT ( STDMETHODCALLTYPE *get_InstallDirName )( 
            IVsSetupProperties * This,
            /* [out] */ BSTR *bstrInput);
        
        HRESULT ( STDMETHODCALLTYPE *put_InstallDirName )( 
            IVsSetupProperties * This,
            /* [in] */ LPCOLESTR szFilename);
        
        HRESULT ( STDMETHODCALLTYPE *get_StartName )( 
            IVsSetupProperties * This,
            /* [out] */ BSTR *bstrInput);
        
        HRESULT ( STDMETHODCALLTYPE *put_StartName )( 
            IVsSetupProperties * This,
            /* [in] */ LPCOLESTR szFilename);
        
        HRESULT ( STDMETHODCALLTYPE *get_StartInvokeEXE )( 
            IVsSetupProperties * This,
            /* [out] */ BSTR *bstrInput);
        
        HRESULT ( STDMETHODCALLTYPE *put_StartInvokeEXE )( 
            IVsSetupProperties * This,
            /* [in] */ LPCOLESTR szFilename);
        
        HRESULT ( STDMETHODCALLTYPE *get_StartInvokeArgument )( 
            IVsSetupProperties * This,
            /* [out] */ BSTR *bstrInput);
        
        HRESULT ( STDMETHODCALLTYPE *put_StartInvokeArgument )( 
            IVsSetupProperties * This,
            /* [in] */ LPCOLESTR szFilename);
        
        HRESULT ( STDMETHODCALLTYPE *get_IncludeAll )( 
            IVsSetupProperties * This,
            /* [out] */ BOOL *pfvalue);
        
        HRESULT ( STDMETHODCALLTYPE *put_IncludeAll )( 
            IVsSetupProperties * This,
            /* [in] */ BOOL fvalue);
        
        HRESULT ( STDMETHODCALLTYPE *get_CreateInProgramFiles )( 
            IVsSetupProperties * This,
            /* [out] */ BOOL *pfvalue);
        
        HRESULT ( STDMETHODCALLTYPE *put_CreateInProgramFiles )( 
            IVsSetupProperties * This,
            /* [in] */ BOOL fvalue);
        
        HRESULT ( STDMETHODCALLTYPE *get_CreateInStartMenu )( 
            IVsSetupProperties * This,
            /* [out] */ BOOL *pfvalue);
        
        HRESULT ( STDMETHODCALLTYPE *put_CreateInStartMenu )( 
            IVsSetupProperties * This,
            /* [in] */ BOOL fvalue);
        
        HRESULT ( STDMETHODCALLTYPE *get_EXEsToRun )( 
            IVsSetupProperties * This,
            /* [in] */ ULONG cbstr,
            /* [unique][size_is][out][in] */ BSTR *rgbstrCanonicalNames,
            /* [out] */ ULONG *pcbstrActual);
        
        HRESULT ( STDMETHODCALLTYPE *put_EXEsToRun )( 
            IVsSetupProperties * This,
            /* [in] */ ULONG cbstr,
            /* [size_is][in] */ LPCOLESTR *prgszCanonicalNames);
        
        HRESULT ( STDMETHODCALLTYPE *get_RemoteComponents )( 
            IVsSetupProperties * This,
            /* [in] */ ULONG cbstr,
            /* [unique][size_is][out][in] */ BSTR *prgbstrCanonicalNames,
            /* [out] */ ULONG *pcbstrActual);
        
        HRESULT ( STDMETHODCALLTYPE *put_RemoteComponents )( 
            IVsSetupProperties * This,
            /* [in] */ ULONG cbstr,
            /* [size_is][in] */ LPCOLESTR *prgszCanonicalNames);
        
        HRESULT ( STDMETHODCALLTYPE *get_RemoteServer )( 
            IVsSetupProperties * This,
            /* [out] */ BSTR *bstrBuffer);
        
        HRESULT ( STDMETHODCALLTYPE *put_RemoteServer )( 
            IVsSetupProperties * This,
            /* [in] */ LPCOLESTR szFilename);
        
        HRESULT ( STDMETHODCALLTYPE *get_PromptAlways )( 
            IVsSetupProperties * This,
            /* [out] */ BOOL *pfvalue);
        
        HRESULT ( STDMETHODCALLTYPE *put_PromptAlways )( 
            IVsSetupProperties * This,
            /* [in] */ BOOL fvalue);
        
        HRESULT ( STDMETHODCALLTYPE *get_WebLibraryCollection )( 
            IVsSetupProperties * This,
            /* [out] */ IVsWebLibraryCollection **ppIVsWebLibraryCollection);
        
        HRESULT ( STDMETHODCALLTYPE *put_WebLibraryCollection )( 
            IVsSetupProperties * This,
            /* [in] */ IVsWebLibraryCollection *pIVsWebLibaryCollection);
        
        HRESULT ( STDMETHODCALLTYPE *get_ProjectName )( 
            IVsSetupProperties * This,
            /* [in] */ ULONG cchBuffer,
            /* [size_is][out][in] */ OLECHAR rgochBuffer[  ],
            /* [out] */ ULONG *pcchActual);
        
        HRESULT ( STDMETHODCALLTYPE *put_ProjectName )( 
            IVsSetupProperties * This,
            /* [in] */ LPCOLESTR szProjectName);
        
        HRESULT ( STDMETHODCALLTYPE *EnumEngineInputs )( 
            IVsSetupProperties * This,
            /* [out] */ IVsEnumOutputs **ppIVsEnumOutputs);
        
        HRESULT ( STDMETHODCALLTYPE *EnumPossibleExposedObjects )( 
            IVsSetupProperties * This,
            /* [out] */ IVsEnumExposedObjects **ppIVsEnumExposedObjects);
        
        HRESULT ( STDMETHODCALLTYPE *GetSolutionName )( 
            IVsSetupProperties * This,
            /* [out] */ BSTR *bstrSol);
        
        HRESULT ( STDMETHODCALLTYPE *GetOutputDestination )( 
            IVsSetupProperties * This,
            /* [in] */ LPCOLESTR szOutputCanonicalName,
            /* [out] */ BSTR *pbstrOutputDestination,
            /* [out] */ BOOL *pfReferenceCount,
            /* [out] */ BOOL *pfPromptForUninstallDelete);
        
        END_INTERFACE
    } IVsSetupPropertiesVtbl;

    interface IVsSetupProperties
    {
        CONST_VTBL struct IVsSetupPropertiesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsSetupProperties_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsSetupProperties_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsSetupProperties_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsSetupProperties_get_PackagingEnginePropertyInterfaceBroker(This,ppIVsPackagingEnginePropertyInterfaceBroker)	\
    (This)->lpVtbl -> get_PackagingEnginePropertyInterfaceBroker(This,ppIVsPackagingEnginePropertyInterfaceBroker)

#define IVsSetupProperties_put_PackagingEnginePropertyInterfaceBroker(This,pIVsPackagingEnginePropertyInterfaceBroker)	\
    (This)->lpVtbl -> put_PackagingEnginePropertyInterfaceBroker(This,pIVsPackagingEnginePropertyInterfaceBroker)

#define IVsSetupProperties_Clone(This,ppIVsPackagingPropertyObject)	\
    (This)->lpVtbl -> Clone(This,ppIVsPackagingPropertyObject)

#define IVsSetupProperties_Merge(This,pIVsPackagingPropertyObject)	\
    (This)->lpVtbl -> Merge(This,pIVsPackagingPropertyObject)

#define IVsSetupProperties_Close(This)	\
    (This)->lpVtbl -> Close(This)

#define IVsSetupProperties_get_OutputFilename(This,cchBuffer,rgochBuffer,pcchActual)	\
    (This)->lpVtbl -> get_OutputFilename(This,cchBuffer,rgochBuffer,pcchActual)

#define IVsSetupProperties_put_OutputFilename(This,szFilename)	\
    (This)->lpVtbl -> put_OutputFilename(This,szFilename)

#define IVsSetupProperties_get_BaseDirectory(This,cchBuffer,rgochBuffer,pcchActual)	\
    (This)->lpVtbl -> get_BaseDirectory(This,cchBuffer,rgochBuffer,pcchActual)

#define IVsSetupProperties_put_BaseDirectory(This,szBaseDirectory)	\
    (This)->lpVtbl -> put_BaseDirectory(This,szBaseDirectory)


#define IVsSetupProperties_get_AppName(This,bstrInput)	\
    (This)->lpVtbl -> get_AppName(This,bstrInput)

#define IVsSetupProperties_put_AppName(This,szFilename)	\
    (This)->lpVtbl -> put_AppName(This,szFilename)

#define IVsSetupProperties_get_InstallDirName(This,bstrInput)	\
    (This)->lpVtbl -> get_InstallDirName(This,bstrInput)

#define IVsSetupProperties_put_InstallDirName(This,szFilename)	\
    (This)->lpVtbl -> put_InstallDirName(This,szFilename)

#define IVsSetupProperties_get_StartName(This,bstrInput)	\
    (This)->lpVtbl -> get_StartName(This,bstrInput)

#define IVsSetupProperties_put_StartName(This,szFilename)	\
    (This)->lpVtbl -> put_StartName(This,szFilename)

#define IVsSetupProperties_get_StartInvokeEXE(This,bstrInput)	\
    (This)->lpVtbl -> get_StartInvokeEXE(This,bstrInput)

#define IVsSetupProperties_put_StartInvokeEXE(This,szFilename)	\
    (This)->lpVtbl -> put_StartInvokeEXE(This,szFilename)

#define IVsSetupProperties_get_StartInvokeArgument(This,bstrInput)	\
    (This)->lpVtbl -> get_StartInvokeArgument(This,bstrInput)

#define IVsSetupProperties_put_StartInvokeArgument(This,szFilename)	\
    (This)->lpVtbl -> put_StartInvokeArgument(This,szFilename)

#define IVsSetupProperties_get_IncludeAll(This,pfvalue)	\
    (This)->lpVtbl -> get_IncludeAll(This,pfvalue)

#define IVsSetupProperties_put_IncludeAll(This,fvalue)	\
    (This)->lpVtbl -> put_IncludeAll(This,fvalue)

#define IVsSetupProperties_get_CreateInProgramFiles(This,pfvalue)	\
    (This)->lpVtbl -> get_CreateInProgramFiles(This,pfvalue)

#define IVsSetupProperties_put_CreateInProgramFiles(This,fvalue)	\
    (This)->lpVtbl -> put_CreateInProgramFiles(This,fvalue)

#define IVsSetupProperties_get_CreateInStartMenu(This,pfvalue)	\
    (This)->lpVtbl -> get_CreateInStartMenu(This,pfvalue)

#define IVsSetupProperties_put_CreateInStartMenu(This,fvalue)	\
    (This)->lpVtbl -> put_CreateInStartMenu(This,fvalue)

#define IVsSetupProperties_get_EXEsToRun(This,cbstr,rgbstrCanonicalNames,pcbstrActual)	\
    (This)->lpVtbl -> get_EXEsToRun(This,cbstr,rgbstrCanonicalNames,pcbstrActual)

#define IVsSetupProperties_put_EXEsToRun(This,cbstr,prgszCanonicalNames)	\
    (This)->lpVtbl -> put_EXEsToRun(This,cbstr,prgszCanonicalNames)

#define IVsSetupProperties_get_RemoteComponents(This,cbstr,prgbstrCanonicalNames,pcbstrActual)	\
    (This)->lpVtbl -> get_RemoteComponents(This,cbstr,prgbstrCanonicalNames,pcbstrActual)

#define IVsSetupProperties_put_RemoteComponents(This,cbstr,prgszCanonicalNames)	\
    (This)->lpVtbl -> put_RemoteComponents(This,cbstr,prgszCanonicalNames)

#define IVsSetupProperties_get_RemoteServer(This,bstrBuffer)	\
    (This)->lpVtbl -> get_RemoteServer(This,bstrBuffer)

#define IVsSetupProperties_put_RemoteServer(This,szFilename)	\
    (This)->lpVtbl -> put_RemoteServer(This,szFilename)

#define IVsSetupProperties_get_PromptAlways(This,pfvalue)	\
    (This)->lpVtbl -> get_PromptAlways(This,pfvalue)

#define IVsSetupProperties_put_PromptAlways(This,fvalue)	\
    (This)->lpVtbl -> put_PromptAlways(This,fvalue)

#define IVsSetupProperties_get_WebLibraryCollection(This,ppIVsWebLibraryCollection)	\
    (This)->lpVtbl -> get_WebLibraryCollection(This,ppIVsWebLibraryCollection)

#define IVsSetupProperties_put_WebLibraryCollection(This,pIVsWebLibaryCollection)	\
    (This)->lpVtbl -> put_WebLibraryCollection(This,pIVsWebLibaryCollection)

#define IVsSetupProperties_get_ProjectName(This,cchBuffer,rgochBuffer,pcchActual)	\
    (This)->lpVtbl -> get_ProjectName(This,cchBuffer,rgochBuffer,pcchActual)

#define IVsSetupProperties_put_ProjectName(This,szProjectName)	\
    (This)->lpVtbl -> put_ProjectName(This,szProjectName)

#define IVsSetupProperties_EnumEngineInputs(This,ppIVsEnumOutputs)	\
    (This)->lpVtbl -> EnumEngineInputs(This,ppIVsEnumOutputs)

#define IVsSetupProperties_EnumPossibleExposedObjects(This,ppIVsEnumExposedObjects)	\
    (This)->lpVtbl -> EnumPossibleExposedObjects(This,ppIVsEnumExposedObjects)

#define IVsSetupProperties_GetSolutionName(This,bstrSol)	\
    (This)->lpVtbl -> GetSolutionName(This,bstrSol)

#define IVsSetupProperties_GetOutputDestination(This,szOutputCanonicalName,pbstrOutputDestination,pfReferenceCount,pfPromptForUninstallDelete)	\
    (This)->lpVtbl -> GetOutputDestination(This,szOutputCanonicalName,pbstrOutputDestination,pfReferenceCount,pfPromptForUninstallDelete)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsSetupProperties_get_AppName_Proxy( 
    IVsSetupProperties * This,
    /* [out] */ BSTR *bstrInput);


void __RPC_STUB IVsSetupProperties_get_AppName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSetupProperties_put_AppName_Proxy( 
    IVsSetupProperties * This,
    /* [in] */ LPCOLESTR szFilename);


void __RPC_STUB IVsSetupProperties_put_AppName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSetupProperties_get_InstallDirName_Proxy( 
    IVsSetupProperties * This,
    /* [out] */ BSTR *bstrInput);


void __RPC_STUB IVsSetupProperties_get_InstallDirName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSetupProperties_put_InstallDirName_Proxy( 
    IVsSetupProperties * This,
    /* [in] */ LPCOLESTR szFilename);


void __RPC_STUB IVsSetupProperties_put_InstallDirName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSetupProperties_get_StartName_Proxy( 
    IVsSetupProperties * This,
    /* [out] */ BSTR *bstrInput);


void __RPC_STUB IVsSetupProperties_get_StartName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSetupProperties_put_StartName_Proxy( 
    IVsSetupProperties * This,
    /* [in] */ LPCOLESTR szFilename);


void __RPC_STUB IVsSetupProperties_put_StartName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSetupProperties_get_StartInvokeEXE_Proxy( 
    IVsSetupProperties * This,
    /* [out] */ BSTR *bstrInput);


void __RPC_STUB IVsSetupProperties_get_StartInvokeEXE_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSetupProperties_put_StartInvokeEXE_Proxy( 
    IVsSetupProperties * This,
    /* [in] */ LPCOLESTR szFilename);


void __RPC_STUB IVsSetupProperties_put_StartInvokeEXE_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSetupProperties_get_StartInvokeArgument_Proxy( 
    IVsSetupProperties * This,
    /* [out] */ BSTR *bstrInput);


void __RPC_STUB IVsSetupProperties_get_StartInvokeArgument_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSetupProperties_put_StartInvokeArgument_Proxy( 
    IVsSetupProperties * This,
    /* [in] */ LPCOLESTR szFilename);


void __RPC_STUB IVsSetupProperties_put_StartInvokeArgument_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSetupProperties_get_IncludeAll_Proxy( 
    IVsSetupProperties * This,
    /* [out] */ BOOL *pfvalue);


void __RPC_STUB IVsSetupProperties_get_IncludeAll_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSetupProperties_put_IncludeAll_Proxy( 
    IVsSetupProperties * This,
    /* [in] */ BOOL fvalue);


void __RPC_STUB IVsSetupProperties_put_IncludeAll_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSetupProperties_get_CreateInProgramFiles_Proxy( 
    IVsSetupProperties * This,
    /* [out] */ BOOL *pfvalue);


void __RPC_STUB IVsSetupProperties_get_CreateInProgramFiles_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSetupProperties_put_CreateInProgramFiles_Proxy( 
    IVsSetupProperties * This,
    /* [in] */ BOOL fvalue);


void __RPC_STUB IVsSetupProperties_put_CreateInProgramFiles_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSetupProperties_get_CreateInStartMenu_Proxy( 
    IVsSetupProperties * This,
    /* [out] */ BOOL *pfvalue);


void __RPC_STUB IVsSetupProperties_get_CreateInStartMenu_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSetupProperties_put_CreateInStartMenu_Proxy( 
    IVsSetupProperties * This,
    /* [in] */ BOOL fvalue);


void __RPC_STUB IVsSetupProperties_put_CreateInStartMenu_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSetupProperties_get_EXEsToRun_Proxy( 
    IVsSetupProperties * This,
    /* [in] */ ULONG cbstr,
    /* [unique][size_is][out][in] */ BSTR *rgbstrCanonicalNames,
    /* [out] */ ULONG *pcbstrActual);


void __RPC_STUB IVsSetupProperties_get_EXEsToRun_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSetupProperties_put_EXEsToRun_Proxy( 
    IVsSetupProperties * This,
    /* [in] */ ULONG cbstr,
    /* [size_is][in] */ LPCOLESTR *prgszCanonicalNames);


void __RPC_STUB IVsSetupProperties_put_EXEsToRun_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSetupProperties_get_RemoteComponents_Proxy( 
    IVsSetupProperties * This,
    /* [in] */ ULONG cbstr,
    /* [unique][size_is][out][in] */ BSTR *prgbstrCanonicalNames,
    /* [out] */ ULONG *pcbstrActual);


void __RPC_STUB IVsSetupProperties_get_RemoteComponents_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSetupProperties_put_RemoteComponents_Proxy( 
    IVsSetupProperties * This,
    /* [in] */ ULONG cbstr,
    /* [size_is][in] */ LPCOLESTR *prgszCanonicalNames);


void __RPC_STUB IVsSetupProperties_put_RemoteComponents_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSetupProperties_get_RemoteServer_Proxy( 
    IVsSetupProperties * This,
    /* [out] */ BSTR *bstrBuffer);


void __RPC_STUB IVsSetupProperties_get_RemoteServer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSetupProperties_put_RemoteServer_Proxy( 
    IVsSetupProperties * This,
    /* [in] */ LPCOLESTR szFilename);


void __RPC_STUB IVsSetupProperties_put_RemoteServer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSetupProperties_get_PromptAlways_Proxy( 
    IVsSetupProperties * This,
    /* [out] */ BOOL *pfvalue);


void __RPC_STUB IVsSetupProperties_get_PromptAlways_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSetupProperties_put_PromptAlways_Proxy( 
    IVsSetupProperties * This,
    /* [in] */ BOOL fvalue);


void __RPC_STUB IVsSetupProperties_put_PromptAlways_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSetupProperties_get_WebLibraryCollection_Proxy( 
    IVsSetupProperties * This,
    /* [out] */ IVsWebLibraryCollection **ppIVsWebLibraryCollection);


void __RPC_STUB IVsSetupProperties_get_WebLibraryCollection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSetupProperties_put_WebLibraryCollection_Proxy( 
    IVsSetupProperties * This,
    /* [in] */ IVsWebLibraryCollection *pIVsWebLibaryCollection);


void __RPC_STUB IVsSetupProperties_put_WebLibraryCollection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSetupProperties_get_ProjectName_Proxy( 
    IVsSetupProperties * This,
    /* [in] */ ULONG cchBuffer,
    /* [size_is][out][in] */ OLECHAR rgochBuffer[  ],
    /* [out] */ ULONG *pcchActual);


void __RPC_STUB IVsSetupProperties_get_ProjectName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSetupProperties_put_ProjectName_Proxy( 
    IVsSetupProperties * This,
    /* [in] */ LPCOLESTR szProjectName);


void __RPC_STUB IVsSetupProperties_put_ProjectName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSetupProperties_EnumEngineInputs_Proxy( 
    IVsSetupProperties * This,
    /* [out] */ IVsEnumOutputs **ppIVsEnumOutputs);


void __RPC_STUB IVsSetupProperties_EnumEngineInputs_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSetupProperties_EnumPossibleExposedObjects_Proxy( 
    IVsSetupProperties * This,
    /* [out] */ IVsEnumExposedObjects **ppIVsEnumExposedObjects);


void __RPC_STUB IVsSetupProperties_EnumPossibleExposedObjects_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSetupProperties_GetSolutionName_Proxy( 
    IVsSetupProperties * This,
    /* [out] */ BSTR *bstrSol);


void __RPC_STUB IVsSetupProperties_GetSolutionName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSetupProperties_GetOutputDestination_Proxy( 
    IVsSetupProperties * This,
    /* [in] */ LPCOLESTR szOutputCanonicalName,
    /* [out] */ BSTR *pbstrOutputDestination,
    /* [out] */ BOOL *pfReferenceCount,
    /* [out] */ BOOL *pfPromptForUninstallDelete);


void __RPC_STUB IVsSetupProperties_GetOutputDestination_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsSetupProperties_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vspkg_0709 */
/* [local] */ 

typedef struct tagVSSETUPFILEPROP
    {
    BSTR m_bstrCanonicalName;
    BSTR m_bstrOutputDestination;
    BOOL m_fReferenceCount;
    BOOL m_fPromptForDelete;
    } 	VSSETUPFILEPROP;



extern RPC_IF_HANDLE __MIDL_itf_vspkg_0709_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vspkg_0709_v0_0_s_ifspec;

#ifndef __IVsEnumVSSETUPFILEPROP_INTERFACE_DEFINED__
#define __IVsEnumVSSETUPFILEPROP_INTERFACE_DEFINED__

/* interface IVsEnumVSSETUPFILEPROP */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsEnumVSSETUPFILEPROP;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1eecc150-93a6-11d1-929f-00a0c91e2acd")
    IVsEnumVSSETUPFILEPROP : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [size_is][out][in] */ VSSETUPFILEPROP *prgvssfp,
            /* [out] */ ULONG *pcActual) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IVsEnumVSSETUPFILEPROP **ppIVsEnumVSSETUPFILEPROP) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsEnumVSSETUPFILEPROPVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsEnumVSSETUPFILEPROP * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsEnumVSSETUPFILEPROP * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsEnumVSSETUPFILEPROP * This);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IVsEnumVSSETUPFILEPROP * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IVsEnumVSSETUPFILEPROP * This,
            /* [in] */ ULONG celt,
            /* [size_is][out][in] */ VSSETUPFILEPROP *prgvssfp,
            /* [out] */ ULONG *pcActual);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IVsEnumVSSETUPFILEPROP * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IVsEnumVSSETUPFILEPROP * This,
            /* [out] */ IVsEnumVSSETUPFILEPROP **ppIVsEnumVSSETUPFILEPROP);
        
        END_INTERFACE
    } IVsEnumVSSETUPFILEPROPVtbl;

    interface IVsEnumVSSETUPFILEPROP
    {
        CONST_VTBL struct IVsEnumVSSETUPFILEPROPVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsEnumVSSETUPFILEPROP_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsEnumVSSETUPFILEPROP_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsEnumVSSETUPFILEPROP_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsEnumVSSETUPFILEPROP_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IVsEnumVSSETUPFILEPROP_Next(This,celt,prgvssfp,pcActual)	\
    (This)->lpVtbl -> Next(This,celt,prgvssfp,pcActual)

#define IVsEnumVSSETUPFILEPROP_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IVsEnumVSSETUPFILEPROP_Clone(This,ppIVsEnumVSSETUPFILEPROP)	\
    (This)->lpVtbl -> Clone(This,ppIVsEnumVSSETUPFILEPROP)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsEnumVSSETUPFILEPROP_Reset_Proxy( 
    IVsEnumVSSETUPFILEPROP * This);


void __RPC_STUB IVsEnumVSSETUPFILEPROP_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsEnumVSSETUPFILEPROP_Next_Proxy( 
    IVsEnumVSSETUPFILEPROP * This,
    /* [in] */ ULONG celt,
    /* [size_is][out][in] */ VSSETUPFILEPROP *prgvssfp,
    /* [out] */ ULONG *pcActual);


void __RPC_STUB IVsEnumVSSETUPFILEPROP_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsEnumVSSETUPFILEPROP_Skip_Proxy( 
    IVsEnumVSSETUPFILEPROP * This,
    /* [in] */ ULONG celt);


void __RPC_STUB IVsEnumVSSETUPFILEPROP_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsEnumVSSETUPFILEPROP_Clone_Proxy( 
    IVsEnumVSSETUPFILEPROP * This,
    /* [out] */ IVsEnumVSSETUPFILEPROP **ppIVsEnumVSSETUPFILEPROP);


void __RPC_STUB IVsEnumVSSETUPFILEPROP_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsEnumVSSETUPFILEPROP_INTERFACE_DEFINED__ */


#ifndef __IVsSetupFilePlacementProperties_INTERFACE_DEFINED__
#define __IVsSetupFilePlacementProperties_INTERFACE_DEFINED__

/* interface IVsSetupFilePlacementProperties */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsSetupFilePlacementProperties;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5238387d-c56b-11d0-8a49-00a0c91e2acd")
    IVsSetupFilePlacementProperties : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE EnumPlacedFiles( 
            /* [out] */ IVsEnumVSSETUPFILEPROP **ppIVsEnumVSSETUPFILEPROP) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_PlacedFiles( 
            /* [in] */ ULONG celt,
            /* [size_is][unique][in] */ VSSETUPFILEPROP *prgvssfp) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOutputDestination( 
            /* [in] */ LPCOLESTR szOutputCanonicalName,
            /* [out] */ BSTR *pbstrOutputDestination,
            /* [out] */ BOOL *pfReferenceCount,
            /* [out] */ BOOL *pfPromptForDelete) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumEngineInputs( 
            /* [out] */ IVsEnumOutputs **ppIVsEnumOutputs) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsSetupFilePlacementPropertiesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsSetupFilePlacementProperties * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsSetupFilePlacementProperties * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsSetupFilePlacementProperties * This);
        
        HRESULT ( STDMETHODCALLTYPE *EnumPlacedFiles )( 
            IVsSetupFilePlacementProperties * This,
            /* [out] */ IVsEnumVSSETUPFILEPROP **ppIVsEnumVSSETUPFILEPROP);
        
        HRESULT ( STDMETHODCALLTYPE *put_PlacedFiles )( 
            IVsSetupFilePlacementProperties * This,
            /* [in] */ ULONG celt,
            /* [size_is][unique][in] */ VSSETUPFILEPROP *prgvssfp);
        
        HRESULT ( STDMETHODCALLTYPE *GetOutputDestination )( 
            IVsSetupFilePlacementProperties * This,
            /* [in] */ LPCOLESTR szOutputCanonicalName,
            /* [out] */ BSTR *pbstrOutputDestination,
            /* [out] */ BOOL *pfReferenceCount,
            /* [out] */ BOOL *pfPromptForDelete);
        
        HRESULT ( STDMETHODCALLTYPE *EnumEngineInputs )( 
            IVsSetupFilePlacementProperties * This,
            /* [out] */ IVsEnumOutputs **ppIVsEnumOutputs);
        
        END_INTERFACE
    } IVsSetupFilePlacementPropertiesVtbl;

    interface IVsSetupFilePlacementProperties
    {
        CONST_VTBL struct IVsSetupFilePlacementPropertiesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsSetupFilePlacementProperties_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsSetupFilePlacementProperties_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsSetupFilePlacementProperties_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsSetupFilePlacementProperties_EnumPlacedFiles(This,ppIVsEnumVSSETUPFILEPROP)	\
    (This)->lpVtbl -> EnumPlacedFiles(This,ppIVsEnumVSSETUPFILEPROP)

#define IVsSetupFilePlacementProperties_put_PlacedFiles(This,celt,prgvssfp)	\
    (This)->lpVtbl -> put_PlacedFiles(This,celt,prgvssfp)

#define IVsSetupFilePlacementProperties_GetOutputDestination(This,szOutputCanonicalName,pbstrOutputDestination,pfReferenceCount,pfPromptForDelete)	\
    (This)->lpVtbl -> GetOutputDestination(This,szOutputCanonicalName,pbstrOutputDestination,pfReferenceCount,pfPromptForDelete)

#define IVsSetupFilePlacementProperties_EnumEngineInputs(This,ppIVsEnumOutputs)	\
    (This)->lpVtbl -> EnumEngineInputs(This,ppIVsEnumOutputs)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsSetupFilePlacementProperties_EnumPlacedFiles_Proxy( 
    IVsSetupFilePlacementProperties * This,
    /* [out] */ IVsEnumVSSETUPFILEPROP **ppIVsEnumVSSETUPFILEPROP);


void __RPC_STUB IVsSetupFilePlacementProperties_EnumPlacedFiles_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSetupFilePlacementProperties_put_PlacedFiles_Proxy( 
    IVsSetupFilePlacementProperties * This,
    /* [in] */ ULONG celt,
    /* [size_is][unique][in] */ VSSETUPFILEPROP *prgvssfp);


void __RPC_STUB IVsSetupFilePlacementProperties_put_PlacedFiles_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSetupFilePlacementProperties_GetOutputDestination_Proxy( 
    IVsSetupFilePlacementProperties * This,
    /* [in] */ LPCOLESTR szOutputCanonicalName,
    /* [out] */ BSTR *pbstrOutputDestination,
    /* [out] */ BOOL *pfReferenceCount,
    /* [out] */ BOOL *pfPromptForDelete);


void __RPC_STUB IVsSetupFilePlacementProperties_GetOutputDestination_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSetupFilePlacementProperties_EnumEngineInputs_Proxy( 
    IVsSetupFilePlacementProperties * This,
    /* [out] */ IVsEnumOutputs **ppIVsEnumOutputs);


void __RPC_STUB IVsSetupFilePlacementProperties_EnumEngineInputs_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsSetupFilePlacementProperties_INTERFACE_DEFINED__ */


#ifndef __IVsSetupPackageDescription_INTERFACE_DEFINED__
#define __IVsSetupPackageDescription_INTERFACE_DEFINED__

/* interface IVsSetupPackageDescription */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsSetupPackageDescription;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4C2B25CA-02F7-11d1-A4BE-006097C9933C")
    IVsSetupPackageDescription : public IVsPackageDescription
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE get_ReservedSpace( 
            /* [out] */ UINT *plReservedSpace) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsSetupPackageDescriptionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsSetupPackageDescription * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsSetupPackageDescription * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsSetupPackageDescription * This);
        
        HRESULT ( STDMETHODCALLTYPE *EnumItems )( 
            IVsSetupPackageDescription * This,
            /* [out] */ IVsEnumPackageItems **ppIVsEnumPackageItems);
        
        HRESULT ( STDMETHODCALLTYPE *put_OSDFilename )( 
            IVsSetupPackageDescription * This,
            /* [full][string][in] */ LPCOLESTR szFilename);
        
        HRESULT ( STDMETHODCALLTYPE *get_OSDFilename )( 
            IVsSetupPackageDescription * This,
            /* [out] */ BSTR *pbstrFileName);
        
        HRESULT ( STDMETHODCALLTYPE *get_ReservedSpace )( 
            IVsSetupPackageDescription * This,
            /* [out] */ UINT *plReservedSpace);
        
        END_INTERFACE
    } IVsSetupPackageDescriptionVtbl;

    interface IVsSetupPackageDescription
    {
        CONST_VTBL struct IVsSetupPackageDescriptionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsSetupPackageDescription_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsSetupPackageDescription_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsSetupPackageDescription_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsSetupPackageDescription_EnumItems(This,ppIVsEnumPackageItems)	\
    (This)->lpVtbl -> EnumItems(This,ppIVsEnumPackageItems)

#define IVsSetupPackageDescription_put_OSDFilename(This,szFilename)	\
    (This)->lpVtbl -> put_OSDFilename(This,szFilename)

#define IVsSetupPackageDescription_get_OSDFilename(This,pbstrFileName)	\
    (This)->lpVtbl -> get_OSDFilename(This,pbstrFileName)


#define IVsSetupPackageDescription_get_ReservedSpace(This,plReservedSpace)	\
    (This)->lpVtbl -> get_ReservedSpace(This,plReservedSpace)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsSetupPackageDescription_get_ReservedSpace_Proxy( 
    IVsSetupPackageDescription * This,
    /* [out] */ UINT *plReservedSpace);


void __RPC_STUB IVsSetupPackageDescription_get_ReservedSpace_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsSetupPackageDescription_INTERFACE_DEFINED__ */


#ifndef __IVsSetupPackageItem_INTERFACE_DEFINED__
#define __IVsSetupPackageItem_INTERFACE_DEFINED__

/* interface IVsSetupPackageItem */
/* [object][version][uuid] */ 


EXTERN_C const IID IID_IVsSetupPackageItem;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4C2B25CB-02F7-11d1-A4BE-006097C9933C")
    IVsSetupPackageItem : public IVsPackageItem
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE get_StoredFilename( 
            /* [in] */ ULONG cch,
            /* [size_is][out][in] */ OLECHAR rgchBuffer[  ],
            /* [out] */ ULONG *pcchActual) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_OutputDestination( 
            /* [out] */ BSTR *pbstrDestination,
            /* [out] */ BOOL *pfReferenceCount,
            /* [out] */ BOOL *pfPromptForDelete) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsSetupPackageItemVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsSetupPackageItem * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsSetupPackageItem * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsSetupPackageItem * This);
        
        HRESULT ( STDMETHODCALLTYPE *get_Filename )( 
            IVsSetupPackageItem * This,
            /* [in] */ ULONG cch,
            /* [unique][size_is][out][in] */ OLECHAR rgchBuffer[  ],
            /* [out] */ ULONG *pcchActual);
        
        HRESULT ( STDMETHODCALLTYPE *get_ProjectRelativeFilename )( 
            IVsSetupPackageItem * This,
            /* [in] */ ULONG cch,
            /* [unique][size_is][out][in] */ OLECHAR rgchBuffer[  ],
            /* [out] */ ULONG *pcchActual);
        
        HRESULT ( STDMETHODCALLTYPE *get_ItemSource )( 
            IVsSetupPackageItem * This,
            /* [in] */ ULONG cch,
            /* [unique][size_is][out][in] */ OLECHAR rgchBuffer[  ],
            /* [out] */ ULONG *pcchActual);
        
        HRESULT ( STDMETHODCALLTYPE *get_StoredFilename )( 
            IVsSetupPackageItem * This,
            /* [in] */ ULONG cch,
            /* [size_is][out][in] */ OLECHAR rgchBuffer[  ],
            /* [out] */ ULONG *pcchActual);
        
        HRESULT ( STDMETHODCALLTYPE *get_OutputDestination )( 
            IVsSetupPackageItem * This,
            /* [out] */ BSTR *pbstrDestination,
            /* [out] */ BOOL *pfReferenceCount,
            /* [out] */ BOOL *pfPromptForDelete);
        
        END_INTERFACE
    } IVsSetupPackageItemVtbl;

    interface IVsSetupPackageItem
    {
        CONST_VTBL struct IVsSetupPackageItemVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsSetupPackageItem_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsSetupPackageItem_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsSetupPackageItem_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsSetupPackageItem_get_Filename(This,cch,rgchBuffer,pcchActual)	\
    (This)->lpVtbl -> get_Filename(This,cch,rgchBuffer,pcchActual)

#define IVsSetupPackageItem_get_ProjectRelativeFilename(This,cch,rgchBuffer,pcchActual)	\
    (This)->lpVtbl -> get_ProjectRelativeFilename(This,cch,rgchBuffer,pcchActual)

#define IVsSetupPackageItem_get_ItemSource(This,cch,rgchBuffer,pcchActual)	\
    (This)->lpVtbl -> get_ItemSource(This,cch,rgchBuffer,pcchActual)


#define IVsSetupPackageItem_get_StoredFilename(This,cch,rgchBuffer,pcchActual)	\
    (This)->lpVtbl -> get_StoredFilename(This,cch,rgchBuffer,pcchActual)

#define IVsSetupPackageItem_get_OutputDestination(This,pbstrDestination,pfReferenceCount,pfPromptForDelete)	\
    (This)->lpVtbl -> get_OutputDestination(This,pbstrDestination,pfReferenceCount,pfPromptForDelete)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsSetupPackageItem_get_StoredFilename_Proxy( 
    IVsSetupPackageItem * This,
    /* [in] */ ULONG cch,
    /* [size_is][out][in] */ OLECHAR rgchBuffer[  ],
    /* [out] */ ULONG *pcchActual);


void __RPC_STUB IVsSetupPackageItem_get_StoredFilename_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSetupPackageItem_get_OutputDestination_Proxy( 
    IVsSetupPackageItem * This,
    /* [out] */ BSTR *pbstrDestination,
    /* [out] */ BOOL *pfReferenceCount,
    /* [out] */ BOOL *pfPromptForDelete);


void __RPC_STUB IVsSetupPackageItem_get_OutputDestination_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsSetupPackageItem_INTERFACE_DEFINED__ */


#ifndef __IVsSetupPackagingEngineStatusCallback_INTERFACE_DEFINED__
#define __IVsSetupPackagingEngineStatusCallback_INTERFACE_DEFINED__

/* interface IVsSetupPackagingEngineStatusCallback */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsSetupPackagingEngineStatusCallback;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4C2B25CC-02F7-11d1-A4BE-006097C9933C")
    IVsSetupPackagingEngineStatusCallback : public IVsPackagingEngineStatusCallback
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnFileInsertionStatus( 
            /* [in] */ IVsPackageItem *pIVsPackageItem,
            /* [in] */ ULONG ulCompressedBlockSize,
            /* [in] */ ULONG ulUncompressedBlockSize,
            /* [out][in] */ BOOL *pfContinue) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsSetupPackagingEngineStatusCallbackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsSetupPackagingEngineStatusCallback * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsSetupPackagingEngineStatusCallback * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsSetupPackagingEngineStatusCallback * This);
        
        HRESULT ( STDMETHODCALLTYPE *Tick )( 
            IVsSetupPackagingEngineStatusCallback * This,
            /* [unique][out][in] */ BOOL *pfContinue);
        
        HRESULT ( STDMETHODCALLTYPE *OnPackagingStart )( 
            IVsSetupPackagingEngineStatusCallback * This,
            /* [in] */ IVsPackageDescription *pIVsPackageDescription);
        
        HRESULT ( STDMETHODCALLTYPE *OnPackagingEnd )( 
            IVsSetupPackagingEngineStatusCallback * This,
            /* [in] */ IVsPackageDescription *pIVsPackageDescription,
            /* [in] */ BOOL fSuccessful);
        
        HRESULT ( STDMETHODCALLTYPE *OnFileInsertionStart )( 
            IVsSetupPackagingEngineStatusCallback * This,
            /* [in] */ IVsPackageItem *pIVsPackageItem,
            /* [out][in] */ BOOL *pfContinue);
        
        HRESULT ( STDMETHODCALLTYPE *OnFileInsertionProgress )( 
            IVsSetupPackagingEngineStatusCallback * This,
            /* [in] */ IVsPackageItem *pIVsPackageItem,
            /* [in] */ ULONG ulProgressMax,
            /* [in] */ ULONG ulProgressCurrent,
            /* [out][in] */ BOOL *pfContinue);
        
        HRESULT ( STDMETHODCALLTYPE *OnFileInsertionEnd )( 
            IVsSetupPackagingEngineStatusCallback * This,
            /* [in] */ IVsPackageItem *pIVsPackageItem,
            /* [out][in] */ BOOL *pfContinue);
        
        HRESULT ( STDMETHODCALLTYPE *ReportError )( 
            IVsSetupPackagingEngineStatusCallback * This,
            /* [unique][in] */ IVsPackageDescription *pIVsPackageDescription,
            /* [unique][in] */ IVsPackageItem *pIVsPackageItem,
            /* [in] */ HRESULT hr,
            /* [in] */ IErrorInfo *pIErrorInfo,
            /* [out][in] */ BOOL *pfContinue);
        
        HRESULT ( STDMETHODCALLTYPE *OnFileInsertionStatus )( 
            IVsSetupPackagingEngineStatusCallback * This,
            /* [in] */ IVsPackageItem *pIVsPackageItem,
            /* [in] */ ULONG ulCompressedBlockSize,
            /* [in] */ ULONG ulUncompressedBlockSize,
            /* [out][in] */ BOOL *pfContinue);
        
        END_INTERFACE
    } IVsSetupPackagingEngineStatusCallbackVtbl;

    interface IVsSetupPackagingEngineStatusCallback
    {
        CONST_VTBL struct IVsSetupPackagingEngineStatusCallbackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsSetupPackagingEngineStatusCallback_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsSetupPackagingEngineStatusCallback_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsSetupPackagingEngineStatusCallback_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsSetupPackagingEngineStatusCallback_Tick(This,pfContinue)	\
    (This)->lpVtbl -> Tick(This,pfContinue)

#define IVsSetupPackagingEngineStatusCallback_OnPackagingStart(This,pIVsPackageDescription)	\
    (This)->lpVtbl -> OnPackagingStart(This,pIVsPackageDescription)

#define IVsSetupPackagingEngineStatusCallback_OnPackagingEnd(This,pIVsPackageDescription,fSuccessful)	\
    (This)->lpVtbl -> OnPackagingEnd(This,pIVsPackageDescription,fSuccessful)

#define IVsSetupPackagingEngineStatusCallback_OnFileInsertionStart(This,pIVsPackageItem,pfContinue)	\
    (This)->lpVtbl -> OnFileInsertionStart(This,pIVsPackageItem,pfContinue)

#define IVsSetupPackagingEngineStatusCallback_OnFileInsertionProgress(This,pIVsPackageItem,ulProgressMax,ulProgressCurrent,pfContinue)	\
    (This)->lpVtbl -> OnFileInsertionProgress(This,pIVsPackageItem,ulProgressMax,ulProgressCurrent,pfContinue)

#define IVsSetupPackagingEngineStatusCallback_OnFileInsertionEnd(This,pIVsPackageItem,pfContinue)	\
    (This)->lpVtbl -> OnFileInsertionEnd(This,pIVsPackageItem,pfContinue)

#define IVsSetupPackagingEngineStatusCallback_ReportError(This,pIVsPackageDescription,pIVsPackageItem,hr,pIErrorInfo,pfContinue)	\
    (This)->lpVtbl -> ReportError(This,pIVsPackageDescription,pIVsPackageItem,hr,pIErrorInfo,pfContinue)


#define IVsSetupPackagingEngineStatusCallback_OnFileInsertionStatus(This,pIVsPackageItem,ulCompressedBlockSize,ulUncompressedBlockSize,pfContinue)	\
    (This)->lpVtbl -> OnFileInsertionStatus(This,pIVsPackageItem,ulCompressedBlockSize,ulUncompressedBlockSize,pfContinue)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsSetupPackagingEngineStatusCallback_OnFileInsertionStatus_Proxy( 
    IVsSetupPackagingEngineStatusCallback * This,
    /* [in] */ IVsPackageItem *pIVsPackageItem,
    /* [in] */ ULONG ulCompressedBlockSize,
    /* [in] */ ULONG ulUncompressedBlockSize,
    /* [out][in] */ BOOL *pfContinue);


void __RPC_STUB IVsSetupPackagingEngineStatusCallback_OnFileInsertionStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsSetupPackagingEngineStatusCallback_INTERFACE_DEFINED__ */


#ifndef __IVsSetupPackagingEngine_INTERFACE_DEFINED__
#define __IVsSetupPackagingEngine_INTERFACE_DEFINED__

/* interface IVsSetupPackagingEngine */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsSetupPackagingEngine;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A54695A1-038A-11d1-A4BF-006097C9933C")
    IVsSetupPackagingEngine : public IVsPackagingEngine
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AdviseSetupPackagingEngineStatusCallback( 
            /* [in] */ IVsSetupPackagingEngineStatusCallback *pIVsSetupPackagingEngineStatusCallback,
            /* [out] */ VSCOOKIE *pdwCookie) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnadviseSetupPackagingEngineStatusCallback( 
            /* [in] */ VSCOOKIE dwCookie) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsSetupPackagingEngineVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsSetupPackagingEngine * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsSetupPackagingEngine * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsSetupPackagingEngine * This);
        
        HRESULT ( STDMETHODCALLTYPE *put_PackageDescription )( 
            IVsSetupPackagingEngine * This,
            /* [in] */ IVsPackageDescription *pIVsPackageDescription);
        
        HRESULT ( STDMETHODCALLTYPE *get_PackageDescription )( 
            IVsSetupPackagingEngine * This,
            /* [out] */ IVsPackageDescription **ppIVsPackageDescription);
        
        HRESULT ( STDMETHODCALLTYPE *put_OutputFilename )( 
            IVsSetupPackagingEngine * This,
            /* [full][string][in] */ LPCOLESTR szFilename);
        
        HRESULT ( STDMETHODCALLTYPE *get_OutputFilename )( 
            IVsSetupPackagingEngine * This,
            /* [in] */ ULONG cch,
            /* [size_is][out][in] */ OLECHAR rgchBuffer[  ],
            /* [out] */ ULONG *pcchActual);
        
        HRESULT ( STDMETHODCALLTYPE *AdvisePackagingEngineStatusCallback )( 
            IVsSetupPackagingEngine * This,
            /* [in] */ IVsPackagingEngineStatusCallback *pIVsPackagingEngineStatusCallback,
            /* [out] */ VSCOOKIE *pdwCookie);
        
        HRESULT ( STDMETHODCALLTYPE *UnadvisePackagingEngineStatusCallback )( 
            IVsSetupPackagingEngine * This,
            /* [in] */ VSCOOKIE dwCookie);
        
        HRESULT ( STDMETHODCALLTYPE *Start )( 
            IVsSetupPackagingEngine * This);
        
        HRESULT ( STDMETHODCALLTYPE *QueryStatus )( 
            IVsSetupPackagingEngine * This,
            /* [out] */ BOOL *pfDone);
        
        HRESULT ( STDMETHODCALLTYPE *Stop )( 
            IVsSetupPackagingEngine * This,
            /* [in] */ BOOL fSync);
        
        HRESULT ( STDMETHODCALLTYPE *Wait )( 
            IVsSetupPackagingEngine * This,
            /* [in] */ DWORD dwMilliseconds,
            /* [in] */ BOOL fTickOnMessages);
        
        HRESULT ( STDMETHODCALLTYPE *AdviseSetupPackagingEngineStatusCallback )( 
            IVsSetupPackagingEngine * This,
            /* [in] */ IVsSetupPackagingEngineStatusCallback *pIVsSetupPackagingEngineStatusCallback,
            /* [out] */ VSCOOKIE *pdwCookie);
        
        HRESULT ( STDMETHODCALLTYPE *UnadviseSetupPackagingEngineStatusCallback )( 
            IVsSetupPackagingEngine * This,
            /* [in] */ VSCOOKIE dwCookie);
        
        END_INTERFACE
    } IVsSetupPackagingEngineVtbl;

    interface IVsSetupPackagingEngine
    {
        CONST_VTBL struct IVsSetupPackagingEngineVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsSetupPackagingEngine_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsSetupPackagingEngine_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsSetupPackagingEngine_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsSetupPackagingEngine_put_PackageDescription(This,pIVsPackageDescription)	\
    (This)->lpVtbl -> put_PackageDescription(This,pIVsPackageDescription)

#define IVsSetupPackagingEngine_get_PackageDescription(This,ppIVsPackageDescription)	\
    (This)->lpVtbl -> get_PackageDescription(This,ppIVsPackageDescription)

#define IVsSetupPackagingEngine_put_OutputFilename(This,szFilename)	\
    (This)->lpVtbl -> put_OutputFilename(This,szFilename)

#define IVsSetupPackagingEngine_get_OutputFilename(This,cch,rgchBuffer,pcchActual)	\
    (This)->lpVtbl -> get_OutputFilename(This,cch,rgchBuffer,pcchActual)

#define IVsSetupPackagingEngine_AdvisePackagingEngineStatusCallback(This,pIVsPackagingEngineStatusCallback,pdwCookie)	\
    (This)->lpVtbl -> AdvisePackagingEngineStatusCallback(This,pIVsPackagingEngineStatusCallback,pdwCookie)

#define IVsSetupPackagingEngine_UnadvisePackagingEngineStatusCallback(This,dwCookie)	\
    (This)->lpVtbl -> UnadvisePackagingEngineStatusCallback(This,dwCookie)

#define IVsSetupPackagingEngine_Start(This)	\
    (This)->lpVtbl -> Start(This)

#define IVsSetupPackagingEngine_QueryStatus(This,pfDone)	\
    (This)->lpVtbl -> QueryStatus(This,pfDone)

#define IVsSetupPackagingEngine_Stop(This,fSync)	\
    (This)->lpVtbl -> Stop(This,fSync)

#define IVsSetupPackagingEngine_Wait(This,dwMilliseconds,fTickOnMessages)	\
    (This)->lpVtbl -> Wait(This,dwMilliseconds,fTickOnMessages)


#define IVsSetupPackagingEngine_AdviseSetupPackagingEngineStatusCallback(This,pIVsSetupPackagingEngineStatusCallback,pdwCookie)	\
    (This)->lpVtbl -> AdviseSetupPackagingEngineStatusCallback(This,pIVsSetupPackagingEngineStatusCallback,pdwCookie)

#define IVsSetupPackagingEngine_UnadviseSetupPackagingEngineStatusCallback(This,dwCookie)	\
    (This)->lpVtbl -> UnadviseSetupPackagingEngineStatusCallback(This,dwCookie)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsSetupPackagingEngine_AdviseSetupPackagingEngineStatusCallback_Proxy( 
    IVsSetupPackagingEngine * This,
    /* [in] */ IVsSetupPackagingEngineStatusCallback *pIVsSetupPackagingEngineStatusCallback,
    /* [out] */ VSCOOKIE *pdwCookie);


void __RPC_STUB IVsSetupPackagingEngine_AdviseSetupPackagingEngineStatusCallback_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSetupPackagingEngine_UnadviseSetupPackagingEngineStatusCallback_Proxy( 
    IVsSetupPackagingEngine * This,
    /* [in] */ VSCOOKIE dwCookie);


void __RPC_STUB IVsSetupPackagingEngine_UnadviseSetupPackagingEngineStatusCallback_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsSetupPackagingEngine_INTERFACE_DEFINED__ */


#ifndef __IVsINFBasicGeneration_INTERFACE_DEFINED__
#define __IVsINFBasicGeneration_INTERFACE_DEFINED__

/* interface IVsINFBasicGeneration */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsINFBasicGeneration;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("52DCF8A2-0A94-11d1-A53E-006097B7186F")
    IVsINFBasicGeneration : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE put_PackageDescription( 
            /* [in] */ IVsPackageDescription *pIVsPackageDescription) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_PackageDescription( 
            /* [out] */ IVsPackageDescription **ppIVsPackageDescription) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_OutputFilename( 
            /* [in] */ LPCOLESTR szFilename) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_OutputFilename( 
            /* [out] */ BSTR *bstrInput) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_InstallDirName( 
            /* [in] */ LPCOLESTR szInstallDirName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_InstallDirName( 
            /* [out] */ BSTR *bstrInput) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_FileToInstall( 
            /* [in] */ LPCOLESTR szFileToInstall) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_SystemFileToInstall( 
            /* [in] */ LPCOLESTR szSystemFileToInstall,
            /* [in] */ BOOL toRegister) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_RegistryKeyRequired( 
            /* [in] */ LPCOLESTR bstrRegKey,
            /* [in] */ LPCOLESTR bstrRegPath,
            /* [in] */ LPCOLESTR bstrRegSubKey) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_AppName( 
            /* [out] */ BSTR *bstrInput) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_AppName( 
            /* [in] */ LPCOLESTR szFilename) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_StartName( 
            /* [out] */ BSTR *bstrInput) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_StartName( 
            /* [in] */ LPCOLESTR szFilename) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_StartInvokeEXE( 
            /* [out] */ BSTR *bstrInput) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_StartInvokeEXE( 
            /* [in] */ LPCOLESTR szFilename) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_StartInvokeArgument( 
            /* [out] */ BSTR *bstrInput) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_StartInvokeArgument( 
            /* [in] */ LPCOLESTR szFilename) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_WorkingDir( 
            /* [in] */ LPCOLESTR szWorkingDir) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_BaseDirectory( 
            /* [in] */ LPCOLESTR szBaseDirectory) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_CreateInProgramFiles( 
            /* [in] */ BOOL fCreateInProgramFiles) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MakeINF( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsINFBasicGenerationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsINFBasicGeneration * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsINFBasicGeneration * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsINFBasicGeneration * This);
        
        HRESULT ( STDMETHODCALLTYPE *put_PackageDescription )( 
            IVsINFBasicGeneration * This,
            /* [in] */ IVsPackageDescription *pIVsPackageDescription);
        
        HRESULT ( STDMETHODCALLTYPE *get_PackageDescription )( 
            IVsINFBasicGeneration * This,
            /* [out] */ IVsPackageDescription **ppIVsPackageDescription);
        
        HRESULT ( STDMETHODCALLTYPE *put_OutputFilename )( 
            IVsINFBasicGeneration * This,
            /* [in] */ LPCOLESTR szFilename);
        
        HRESULT ( STDMETHODCALLTYPE *get_OutputFilename )( 
            IVsINFBasicGeneration * This,
            /* [out] */ BSTR *bstrInput);
        
        HRESULT ( STDMETHODCALLTYPE *put_InstallDirName )( 
            IVsINFBasicGeneration * This,
            /* [in] */ LPCOLESTR szInstallDirName);
        
        HRESULT ( STDMETHODCALLTYPE *get_InstallDirName )( 
            IVsINFBasicGeneration * This,
            /* [out] */ BSTR *bstrInput);
        
        HRESULT ( STDMETHODCALLTYPE *put_FileToInstall )( 
            IVsINFBasicGeneration * This,
            /* [in] */ LPCOLESTR szFileToInstall);
        
        HRESULT ( STDMETHODCALLTYPE *put_SystemFileToInstall )( 
            IVsINFBasicGeneration * This,
            /* [in] */ LPCOLESTR szSystemFileToInstall,
            /* [in] */ BOOL toRegister);
        
        HRESULT ( STDMETHODCALLTYPE *put_RegistryKeyRequired )( 
            IVsINFBasicGeneration * This,
            /* [in] */ LPCOLESTR bstrRegKey,
            /* [in] */ LPCOLESTR bstrRegPath,
            /* [in] */ LPCOLESTR bstrRegSubKey);
        
        HRESULT ( STDMETHODCALLTYPE *get_AppName )( 
            IVsINFBasicGeneration * This,
            /* [out] */ BSTR *bstrInput);
        
        HRESULT ( STDMETHODCALLTYPE *put_AppName )( 
            IVsINFBasicGeneration * This,
            /* [in] */ LPCOLESTR szFilename);
        
        HRESULT ( STDMETHODCALLTYPE *get_StartName )( 
            IVsINFBasicGeneration * This,
            /* [out] */ BSTR *bstrInput);
        
        HRESULT ( STDMETHODCALLTYPE *put_StartName )( 
            IVsINFBasicGeneration * This,
            /* [in] */ LPCOLESTR szFilename);
        
        HRESULT ( STDMETHODCALLTYPE *get_StartInvokeEXE )( 
            IVsINFBasicGeneration * This,
            /* [out] */ BSTR *bstrInput);
        
        HRESULT ( STDMETHODCALLTYPE *put_StartInvokeEXE )( 
            IVsINFBasicGeneration * This,
            /* [in] */ LPCOLESTR szFilename);
        
        HRESULT ( STDMETHODCALLTYPE *get_StartInvokeArgument )( 
            IVsINFBasicGeneration * This,
            /* [out] */ BSTR *bstrInput);
        
        HRESULT ( STDMETHODCALLTYPE *put_StartInvokeArgument )( 
            IVsINFBasicGeneration * This,
            /* [in] */ LPCOLESTR szFilename);
        
        HRESULT ( STDMETHODCALLTYPE *put_WorkingDir )( 
            IVsINFBasicGeneration * This,
            /* [in] */ LPCOLESTR szWorkingDir);
        
        HRESULT ( STDMETHODCALLTYPE *put_BaseDirectory )( 
            IVsINFBasicGeneration * This,
            /* [in] */ LPCOLESTR szBaseDirectory);
        
        HRESULT ( STDMETHODCALLTYPE *put_CreateInProgramFiles )( 
            IVsINFBasicGeneration * This,
            /* [in] */ BOOL fCreateInProgramFiles);
        
        HRESULT ( STDMETHODCALLTYPE *MakeINF )( 
            IVsINFBasicGeneration * This);
        
        END_INTERFACE
    } IVsINFBasicGenerationVtbl;

    interface IVsINFBasicGeneration
    {
        CONST_VTBL struct IVsINFBasicGenerationVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsINFBasicGeneration_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsINFBasicGeneration_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsINFBasicGeneration_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsINFBasicGeneration_put_PackageDescription(This,pIVsPackageDescription)	\
    (This)->lpVtbl -> put_PackageDescription(This,pIVsPackageDescription)

#define IVsINFBasicGeneration_get_PackageDescription(This,ppIVsPackageDescription)	\
    (This)->lpVtbl -> get_PackageDescription(This,ppIVsPackageDescription)

#define IVsINFBasicGeneration_put_OutputFilename(This,szFilename)	\
    (This)->lpVtbl -> put_OutputFilename(This,szFilename)

#define IVsINFBasicGeneration_get_OutputFilename(This,bstrInput)	\
    (This)->lpVtbl -> get_OutputFilename(This,bstrInput)

#define IVsINFBasicGeneration_put_InstallDirName(This,szInstallDirName)	\
    (This)->lpVtbl -> put_InstallDirName(This,szInstallDirName)

#define IVsINFBasicGeneration_get_InstallDirName(This,bstrInput)	\
    (This)->lpVtbl -> get_InstallDirName(This,bstrInput)

#define IVsINFBasicGeneration_put_FileToInstall(This,szFileToInstall)	\
    (This)->lpVtbl -> put_FileToInstall(This,szFileToInstall)

#define IVsINFBasicGeneration_put_SystemFileToInstall(This,szSystemFileToInstall,toRegister)	\
    (This)->lpVtbl -> put_SystemFileToInstall(This,szSystemFileToInstall,toRegister)

#define IVsINFBasicGeneration_put_RegistryKeyRequired(This,bstrRegKey,bstrRegPath,bstrRegSubKey)	\
    (This)->lpVtbl -> put_RegistryKeyRequired(This,bstrRegKey,bstrRegPath,bstrRegSubKey)

#define IVsINFBasicGeneration_get_AppName(This,bstrInput)	\
    (This)->lpVtbl -> get_AppName(This,bstrInput)

#define IVsINFBasicGeneration_put_AppName(This,szFilename)	\
    (This)->lpVtbl -> put_AppName(This,szFilename)

#define IVsINFBasicGeneration_get_StartName(This,bstrInput)	\
    (This)->lpVtbl -> get_StartName(This,bstrInput)

#define IVsINFBasicGeneration_put_StartName(This,szFilename)	\
    (This)->lpVtbl -> put_StartName(This,szFilename)

#define IVsINFBasicGeneration_get_StartInvokeEXE(This,bstrInput)	\
    (This)->lpVtbl -> get_StartInvokeEXE(This,bstrInput)

#define IVsINFBasicGeneration_put_StartInvokeEXE(This,szFilename)	\
    (This)->lpVtbl -> put_StartInvokeEXE(This,szFilename)

#define IVsINFBasicGeneration_get_StartInvokeArgument(This,bstrInput)	\
    (This)->lpVtbl -> get_StartInvokeArgument(This,bstrInput)

#define IVsINFBasicGeneration_put_StartInvokeArgument(This,szFilename)	\
    (This)->lpVtbl -> put_StartInvokeArgument(This,szFilename)

#define IVsINFBasicGeneration_put_WorkingDir(This,szWorkingDir)	\
    (This)->lpVtbl -> put_WorkingDir(This,szWorkingDir)

#define IVsINFBasicGeneration_put_BaseDirectory(This,szBaseDirectory)	\
    (This)->lpVtbl -> put_BaseDirectory(This,szBaseDirectory)

#define IVsINFBasicGeneration_put_CreateInProgramFiles(This,fCreateInProgramFiles)	\
    (This)->lpVtbl -> put_CreateInProgramFiles(This,fCreateInProgramFiles)

#define IVsINFBasicGeneration_MakeINF(This)	\
    (This)->lpVtbl -> MakeINF(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsINFBasicGeneration_put_PackageDescription_Proxy( 
    IVsINFBasicGeneration * This,
    /* [in] */ IVsPackageDescription *pIVsPackageDescription);


void __RPC_STUB IVsINFBasicGeneration_put_PackageDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsINFBasicGeneration_get_PackageDescription_Proxy( 
    IVsINFBasicGeneration * This,
    /* [out] */ IVsPackageDescription **ppIVsPackageDescription);


void __RPC_STUB IVsINFBasicGeneration_get_PackageDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsINFBasicGeneration_put_OutputFilename_Proxy( 
    IVsINFBasicGeneration * This,
    /* [in] */ LPCOLESTR szFilename);


void __RPC_STUB IVsINFBasicGeneration_put_OutputFilename_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsINFBasicGeneration_get_OutputFilename_Proxy( 
    IVsINFBasicGeneration * This,
    /* [out] */ BSTR *bstrInput);


void __RPC_STUB IVsINFBasicGeneration_get_OutputFilename_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsINFBasicGeneration_put_InstallDirName_Proxy( 
    IVsINFBasicGeneration * This,
    /* [in] */ LPCOLESTR szInstallDirName);


void __RPC_STUB IVsINFBasicGeneration_put_InstallDirName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsINFBasicGeneration_get_InstallDirName_Proxy( 
    IVsINFBasicGeneration * This,
    /* [out] */ BSTR *bstrInput);


void __RPC_STUB IVsINFBasicGeneration_get_InstallDirName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsINFBasicGeneration_put_FileToInstall_Proxy( 
    IVsINFBasicGeneration * This,
    /* [in] */ LPCOLESTR szFileToInstall);


void __RPC_STUB IVsINFBasicGeneration_put_FileToInstall_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsINFBasicGeneration_put_SystemFileToInstall_Proxy( 
    IVsINFBasicGeneration * This,
    /* [in] */ LPCOLESTR szSystemFileToInstall,
    /* [in] */ BOOL toRegister);


void __RPC_STUB IVsINFBasicGeneration_put_SystemFileToInstall_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsINFBasicGeneration_put_RegistryKeyRequired_Proxy( 
    IVsINFBasicGeneration * This,
    /* [in] */ LPCOLESTR bstrRegKey,
    /* [in] */ LPCOLESTR bstrRegPath,
    /* [in] */ LPCOLESTR bstrRegSubKey);


void __RPC_STUB IVsINFBasicGeneration_put_RegistryKeyRequired_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsINFBasicGeneration_get_AppName_Proxy( 
    IVsINFBasicGeneration * This,
    /* [out] */ BSTR *bstrInput);


void __RPC_STUB IVsINFBasicGeneration_get_AppName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsINFBasicGeneration_put_AppName_Proxy( 
    IVsINFBasicGeneration * This,
    /* [in] */ LPCOLESTR szFilename);


void __RPC_STUB IVsINFBasicGeneration_put_AppName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsINFBasicGeneration_get_StartName_Proxy( 
    IVsINFBasicGeneration * This,
    /* [out] */ BSTR *bstrInput);


void __RPC_STUB IVsINFBasicGeneration_get_StartName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsINFBasicGeneration_put_StartName_Proxy( 
    IVsINFBasicGeneration * This,
    /* [in] */ LPCOLESTR szFilename);


void __RPC_STUB IVsINFBasicGeneration_put_StartName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsINFBasicGeneration_get_StartInvokeEXE_Proxy( 
    IVsINFBasicGeneration * This,
    /* [out] */ BSTR *bstrInput);


void __RPC_STUB IVsINFBasicGeneration_get_StartInvokeEXE_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsINFBasicGeneration_put_StartInvokeEXE_Proxy( 
    IVsINFBasicGeneration * This,
    /* [in] */ LPCOLESTR szFilename);


void __RPC_STUB IVsINFBasicGeneration_put_StartInvokeEXE_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsINFBasicGeneration_get_StartInvokeArgument_Proxy( 
    IVsINFBasicGeneration * This,
    /* [out] */ BSTR *bstrInput);


void __RPC_STUB IVsINFBasicGeneration_get_StartInvokeArgument_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsINFBasicGeneration_put_StartInvokeArgument_Proxy( 
    IVsINFBasicGeneration * This,
    /* [in] */ LPCOLESTR szFilename);


void __RPC_STUB IVsINFBasicGeneration_put_StartInvokeArgument_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsINFBasicGeneration_put_WorkingDir_Proxy( 
    IVsINFBasicGeneration * This,
    /* [in] */ LPCOLESTR szWorkingDir);


void __RPC_STUB IVsINFBasicGeneration_put_WorkingDir_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsINFBasicGeneration_put_BaseDirectory_Proxy( 
    IVsINFBasicGeneration * This,
    /* [in] */ LPCOLESTR szBaseDirectory);


void __RPC_STUB IVsINFBasicGeneration_put_BaseDirectory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsINFBasicGeneration_put_CreateInProgramFiles_Proxy( 
    IVsINFBasicGeneration * This,
    /* [in] */ BOOL fCreateInProgramFiles);


void __RPC_STUB IVsINFBasicGeneration_put_CreateInProgramFiles_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsINFBasicGeneration_MakeINF_Proxy( 
    IVsINFBasicGeneration * This);


void __RPC_STUB IVsINFBasicGeneration_MakeINF_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsINFBasicGeneration_INTERFACE_DEFINED__ */


#ifndef __IVsPackagingEnginePropertyInterfaceBroker_INTERFACE_DEFINED__
#define __IVsPackagingEnginePropertyInterfaceBroker_INTERFACE_DEFINED__

/* interface IVsPackagingEnginePropertyInterfaceBroker */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsPackagingEnginePropertyInterfaceBroker;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("52383878-c56b-11d0-8a49-00a0c91e2acd")
    IVsPackagingEnginePropertyInterfaceBroker : public IVsPropertyInterfaceBroker
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SwitchPackagingEngine( 
            /* [in] */ REFCLSID rclsidPackagingEngine,
            /* [in] */ BOOL fRetainOldSettings) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_PackagingEngine( 
            /* [out] */ CLSID *pclsid) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_PropertyObject( 
            /* [out] */ IVsPackagingPropertyObject **ppIVsPackagingPropertyObject) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IVsPackagingEnginePropertyInterfaceBroker **ppIVsPackagingEnginePropertyInterfaceBroker) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Merge( 
            /* [in] */ IVsPackagingEnginePropertyInterfaceBroker *pIVsPackagingEnginePropertyInterfaceBroker) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumPossibleDependencies( 
            /* [out] */ IVsEnumDependencies **ppIVsEnumDependencies) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumPossibleExposedObjects( 
            /* [out] */ IVsEnumExposedObjects **ppIVsEnumExposedObjects) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_IVsOutputWindowPane( 
            /* [out] */ IVsOutputWindowPane **ppIVsOutputWindowPane) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_IVsOutputWindowPane( 
            /* [in] */ IVsOutputWindowPane *pIVsOutputWindowPane) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Close( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDirty( 
            BOOL fDirty) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsPackagingEnginePropertyInterfaceBrokerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsPackagingEnginePropertyInterfaceBroker * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsPackagingEnginePropertyInterfaceBroker * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsPackagingEnginePropertyInterfaceBroker * This);
        
        HRESULT ( STDMETHODCALLTYPE *QueryPropertyInterface )( 
            IVsPackagingEnginePropertyInterfaceBroker * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        HRESULT ( STDMETHODCALLTYPE *SwitchPackagingEngine )( 
            IVsPackagingEnginePropertyInterfaceBroker * This,
            /* [in] */ REFCLSID rclsidPackagingEngine,
            /* [in] */ BOOL fRetainOldSettings);
        
        HRESULT ( STDMETHODCALLTYPE *get_PackagingEngine )( 
            IVsPackagingEnginePropertyInterfaceBroker * This,
            /* [out] */ CLSID *pclsid);
        
        HRESULT ( STDMETHODCALLTYPE *get_PropertyObject )( 
            IVsPackagingEnginePropertyInterfaceBroker * This,
            /* [out] */ IVsPackagingPropertyObject **ppIVsPackagingPropertyObject);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IVsPackagingEnginePropertyInterfaceBroker * This,
            /* [out] */ IVsPackagingEnginePropertyInterfaceBroker **ppIVsPackagingEnginePropertyInterfaceBroker);
        
        HRESULT ( STDMETHODCALLTYPE *Merge )( 
            IVsPackagingEnginePropertyInterfaceBroker * This,
            /* [in] */ IVsPackagingEnginePropertyInterfaceBroker *pIVsPackagingEnginePropertyInterfaceBroker);
        
        HRESULT ( STDMETHODCALLTYPE *EnumPossibleDependencies )( 
            IVsPackagingEnginePropertyInterfaceBroker * This,
            /* [out] */ IVsEnumDependencies **ppIVsEnumDependencies);
        
        HRESULT ( STDMETHODCALLTYPE *EnumPossibleExposedObjects )( 
            IVsPackagingEnginePropertyInterfaceBroker * This,
            /* [out] */ IVsEnumExposedObjects **ppIVsEnumExposedObjects);
        
        HRESULT ( STDMETHODCALLTYPE *get_IVsOutputWindowPane )( 
            IVsPackagingEnginePropertyInterfaceBroker * This,
            /* [out] */ IVsOutputWindowPane **ppIVsOutputWindowPane);
        
        HRESULT ( STDMETHODCALLTYPE *put_IVsOutputWindowPane )( 
            IVsPackagingEnginePropertyInterfaceBroker * This,
            /* [in] */ IVsOutputWindowPane *pIVsOutputWindowPane);
        
        HRESULT ( STDMETHODCALLTYPE *Close )( 
            IVsPackagingEnginePropertyInterfaceBroker * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetDirty )( 
            IVsPackagingEnginePropertyInterfaceBroker * This,
            BOOL fDirty);
        
        END_INTERFACE
    } IVsPackagingEnginePropertyInterfaceBrokerVtbl;

    interface IVsPackagingEnginePropertyInterfaceBroker
    {
        CONST_VTBL struct IVsPackagingEnginePropertyInterfaceBrokerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsPackagingEnginePropertyInterfaceBroker_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsPackagingEnginePropertyInterfaceBroker_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsPackagingEnginePropertyInterfaceBroker_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsPackagingEnginePropertyInterfaceBroker_QueryPropertyInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryPropertyInterface(This,riid,ppvObject)


#define IVsPackagingEnginePropertyInterfaceBroker_SwitchPackagingEngine(This,rclsidPackagingEngine,fRetainOldSettings)	\
    (This)->lpVtbl -> SwitchPackagingEngine(This,rclsidPackagingEngine,fRetainOldSettings)

#define IVsPackagingEnginePropertyInterfaceBroker_get_PackagingEngine(This,pclsid)	\
    (This)->lpVtbl -> get_PackagingEngine(This,pclsid)

#define IVsPackagingEnginePropertyInterfaceBroker_get_PropertyObject(This,ppIVsPackagingPropertyObject)	\
    (This)->lpVtbl -> get_PropertyObject(This,ppIVsPackagingPropertyObject)

#define IVsPackagingEnginePropertyInterfaceBroker_Clone(This,ppIVsPackagingEnginePropertyInterfaceBroker)	\
    (This)->lpVtbl -> Clone(This,ppIVsPackagingEnginePropertyInterfaceBroker)

#define IVsPackagingEnginePropertyInterfaceBroker_Merge(This,pIVsPackagingEnginePropertyInterfaceBroker)	\
    (This)->lpVtbl -> Merge(This,pIVsPackagingEnginePropertyInterfaceBroker)

#define IVsPackagingEnginePropertyInterfaceBroker_EnumPossibleDependencies(This,ppIVsEnumDependencies)	\
    (This)->lpVtbl -> EnumPossibleDependencies(This,ppIVsEnumDependencies)

#define IVsPackagingEnginePropertyInterfaceBroker_EnumPossibleExposedObjects(This,ppIVsEnumExposedObjects)	\
    (This)->lpVtbl -> EnumPossibleExposedObjects(This,ppIVsEnumExposedObjects)

#define IVsPackagingEnginePropertyInterfaceBroker_get_IVsOutputWindowPane(This,ppIVsOutputWindowPane)	\
    (This)->lpVtbl -> get_IVsOutputWindowPane(This,ppIVsOutputWindowPane)

#define IVsPackagingEnginePropertyInterfaceBroker_put_IVsOutputWindowPane(This,pIVsOutputWindowPane)	\
    (This)->lpVtbl -> put_IVsOutputWindowPane(This,pIVsOutputWindowPane)

#define IVsPackagingEnginePropertyInterfaceBroker_Close(This)	\
    (This)->lpVtbl -> Close(This)

#define IVsPackagingEnginePropertyInterfaceBroker_SetDirty(This,fDirty)	\
    (This)->lpVtbl -> SetDirty(This,fDirty)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsPackagingEnginePropertyInterfaceBroker_SwitchPackagingEngine_Proxy( 
    IVsPackagingEnginePropertyInterfaceBroker * This,
    /* [in] */ REFCLSID rclsidPackagingEngine,
    /* [in] */ BOOL fRetainOldSettings);


void __RPC_STUB IVsPackagingEnginePropertyInterfaceBroker_SwitchPackagingEngine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingEnginePropertyInterfaceBroker_get_PackagingEngine_Proxy( 
    IVsPackagingEnginePropertyInterfaceBroker * This,
    /* [out] */ CLSID *pclsid);


void __RPC_STUB IVsPackagingEnginePropertyInterfaceBroker_get_PackagingEngine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingEnginePropertyInterfaceBroker_get_PropertyObject_Proxy( 
    IVsPackagingEnginePropertyInterfaceBroker * This,
    /* [out] */ IVsPackagingPropertyObject **ppIVsPackagingPropertyObject);


void __RPC_STUB IVsPackagingEnginePropertyInterfaceBroker_get_PropertyObject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingEnginePropertyInterfaceBroker_Clone_Proxy( 
    IVsPackagingEnginePropertyInterfaceBroker * This,
    /* [out] */ IVsPackagingEnginePropertyInterfaceBroker **ppIVsPackagingEnginePropertyInterfaceBroker);


void __RPC_STUB IVsPackagingEnginePropertyInterfaceBroker_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingEnginePropertyInterfaceBroker_Merge_Proxy( 
    IVsPackagingEnginePropertyInterfaceBroker * This,
    /* [in] */ IVsPackagingEnginePropertyInterfaceBroker *pIVsPackagingEnginePropertyInterfaceBroker);


void __RPC_STUB IVsPackagingEnginePropertyInterfaceBroker_Merge_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingEnginePropertyInterfaceBroker_EnumPossibleDependencies_Proxy( 
    IVsPackagingEnginePropertyInterfaceBroker * This,
    /* [out] */ IVsEnumDependencies **ppIVsEnumDependencies);


void __RPC_STUB IVsPackagingEnginePropertyInterfaceBroker_EnumPossibleDependencies_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingEnginePropertyInterfaceBroker_EnumPossibleExposedObjects_Proxy( 
    IVsPackagingEnginePropertyInterfaceBroker * This,
    /* [out] */ IVsEnumExposedObjects **ppIVsEnumExposedObjects);


void __RPC_STUB IVsPackagingEnginePropertyInterfaceBroker_EnumPossibleExposedObjects_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingEnginePropertyInterfaceBroker_get_IVsOutputWindowPane_Proxy( 
    IVsPackagingEnginePropertyInterfaceBroker * This,
    /* [out] */ IVsOutputWindowPane **ppIVsOutputWindowPane);


void __RPC_STUB IVsPackagingEnginePropertyInterfaceBroker_get_IVsOutputWindowPane_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingEnginePropertyInterfaceBroker_put_IVsOutputWindowPane_Proxy( 
    IVsPackagingEnginePropertyInterfaceBroker * This,
    /* [in] */ IVsOutputWindowPane *pIVsOutputWindowPane);


void __RPC_STUB IVsPackagingEnginePropertyInterfaceBroker_put_IVsOutputWindowPane_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingEnginePropertyInterfaceBroker_Close_Proxy( 
    IVsPackagingEnginePropertyInterfaceBroker * This);


void __RPC_STUB IVsPackagingEnginePropertyInterfaceBroker_Close_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsPackagingEnginePropertyInterfaceBroker_SetDirty_Proxy( 
    IVsPackagingEnginePropertyInterfaceBroker * This,
    BOOL fDirty);


void __RPC_STUB IVsPackagingEnginePropertyInterfaceBroker_SetDirty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsPackagingEnginePropertyInterfaceBroker_INTERFACE_DEFINED__ */


#ifndef __IVsJARProperties_INTERFACE_DEFINED__
#define __IVsJARProperties_INTERFACE_DEFINED__

/* interface IVsJARProperties */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsJARProperties;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("52383879-c56b-11d0-8a49-00a0c91e2acd")
    IVsJARProperties : public IVsPackagingPropertyObject
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IVsJARPropertiesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsJARProperties * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsJARProperties * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsJARProperties * This);
        
        HRESULT ( STDMETHODCALLTYPE *get_PackagingEnginePropertyInterfaceBroker )( 
            IVsJARProperties * This,
            /* [out] */ IVsPackagingEnginePropertyInterfaceBroker **ppIVsPackagingEnginePropertyInterfaceBroker);
        
        HRESULT ( STDMETHODCALLTYPE *put_PackagingEnginePropertyInterfaceBroker )( 
            IVsJARProperties * This,
            /* [in] */ IVsPackagingEnginePropertyInterfaceBroker *pIVsPackagingEnginePropertyInterfaceBroker);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IVsJARProperties * This,
            /* [out] */ IVsPackagingPropertyObject **ppIVsPackagingPropertyObject);
        
        HRESULT ( STDMETHODCALLTYPE *Merge )( 
            IVsJARProperties * This,
            /* [in] */ IVsPackagingPropertyObject *pIVsPackagingPropertyObject);
        
        HRESULT ( STDMETHODCALLTYPE *Close )( 
            IVsJARProperties * This);
        
        HRESULT ( STDMETHODCALLTYPE *get_OutputFilename )( 
            IVsJARProperties * This,
            /* [in] */ ULONG cchBuffer,
            /* [size_is][out][in] */ OLECHAR rgochBuffer[  ],
            /* [out] */ ULONG *pcchActual);
        
        HRESULT ( STDMETHODCALLTYPE *put_OutputFilename )( 
            IVsJARProperties * This,
            /* [in] */ LPCOLESTR szFilename);
        
        HRESULT ( STDMETHODCALLTYPE *get_BaseDirectory )( 
            IVsJARProperties * This,
            /* [in] */ ULONG cchBuffer,
            /* [size_is][out][in] */ OLECHAR rgochBuffer[  ],
            /* [out] */ ULONG *pcchActual);
        
        HRESULT ( STDMETHODCALLTYPE *put_BaseDirectory )( 
            IVsJARProperties * This,
            /* [in] */ LPCOLESTR szBaseDirectory);
        
        END_INTERFACE
    } IVsJARPropertiesVtbl;

    interface IVsJARProperties
    {
        CONST_VTBL struct IVsJARPropertiesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsJARProperties_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsJARProperties_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsJARProperties_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsJARProperties_get_PackagingEnginePropertyInterfaceBroker(This,ppIVsPackagingEnginePropertyInterfaceBroker)	\
    (This)->lpVtbl -> get_PackagingEnginePropertyInterfaceBroker(This,ppIVsPackagingEnginePropertyInterfaceBroker)

#define IVsJARProperties_put_PackagingEnginePropertyInterfaceBroker(This,pIVsPackagingEnginePropertyInterfaceBroker)	\
    (This)->lpVtbl -> put_PackagingEnginePropertyInterfaceBroker(This,pIVsPackagingEnginePropertyInterfaceBroker)

#define IVsJARProperties_Clone(This,ppIVsPackagingPropertyObject)	\
    (This)->lpVtbl -> Clone(This,ppIVsPackagingPropertyObject)

#define IVsJARProperties_Merge(This,pIVsPackagingPropertyObject)	\
    (This)->lpVtbl -> Merge(This,pIVsPackagingPropertyObject)

#define IVsJARProperties_Close(This)	\
    (This)->lpVtbl -> Close(This)

#define IVsJARProperties_get_OutputFilename(This,cchBuffer,rgochBuffer,pcchActual)	\
    (This)->lpVtbl -> get_OutputFilename(This,cchBuffer,rgochBuffer,pcchActual)

#define IVsJARProperties_put_OutputFilename(This,szFilename)	\
    (This)->lpVtbl -> put_OutputFilename(This,szFilename)

#define IVsJARProperties_get_BaseDirectory(This,cchBuffer,rgochBuffer,pcchActual)	\
    (This)->lpVtbl -> get_BaseDirectory(This,cchBuffer,rgochBuffer,pcchActual)

#define IVsJARProperties_put_BaseDirectory(This,szBaseDirectory)	\
    (This)->lpVtbl -> put_BaseDirectory(This,szBaseDirectory)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVsJARProperties_INTERFACE_DEFINED__ */


#ifndef __IVsJARPPageController_INTERFACE_DEFINED__
#define __IVsJARPPageController_INTERFACE_DEFINED__

/* interface IVsJARPPageController */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsJARPPageController;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5238387b-c56b-11d0-8a49-00a0c91e2acd")
    IVsJARPPageController : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnSetObject( 
            /* [in] */ IVsJARPPageSettings *pIVsJARPPageSettings) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsJARPPageControllerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsJARPPageController * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsJARPPageController * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsJARPPageController * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnSetObject )( 
            IVsJARPPageController * This,
            /* [in] */ IVsJARPPageSettings *pIVsJARPPageSettings);
        
        END_INTERFACE
    } IVsJARPPageControllerVtbl;

    interface IVsJARPPageController
    {
        CONST_VTBL struct IVsJARPPageControllerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsJARPPageController_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsJARPPageController_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsJARPPageController_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsJARPPageController_OnSetObject(This,pIVsJARPPageSettings)	\
    (This)->lpVtbl -> OnSetObject(This,pIVsJARPPageSettings)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsJARPPageController_OnSetObject_Proxy( 
    IVsJARPPageController * This,
    /* [in] */ IVsJARPPageSettings *pIVsJARPPageSettings);


void __RPC_STUB IVsJARPPageController_OnSetObject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsJARPPageController_INTERFACE_DEFINED__ */


#ifndef __IVsJARPPageSettings_INTERFACE_DEFINED__
#define __IVsJARPPageSettings_INTERFACE_DEFINED__

/* interface IVsJARPPageSettings */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsJARPPageSettings;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5238387c-c56b-11d0-8a49-00a0c91e2acd")
    IVsJARPPageSettings : public IUnknown
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IVsJARPPageSettingsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsJARPPageSettings * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsJARPPageSettings * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsJARPPageSettings * This);
        
        END_INTERFACE
    } IVsJARPPageSettingsVtbl;

    interface IVsJARPPageSettings
    {
        CONST_VTBL struct IVsJARPPageSettingsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsJARPPageSettings_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsJARPPageSettings_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsJARPPageSettings_Release(This)	\
    (This)->lpVtbl -> Release(This)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVsJARPPageSettings_INTERFACE_DEFINED__ */


#ifndef __IVsOpenSoftwareDistributionInfo_INTERFACE_DEFINED__
#define __IVsOpenSoftwareDistributionInfo_INTERFACE_DEFINED__

/* interface IVsOpenSoftwareDistributionInfo */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsOpenSoftwareDistributionInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a57e3d75-d2d3-11d0-8a50-00a0c91e2acd")
    IVsOpenSoftwareDistributionInfo : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE get_OSDTitle( 
            /* [out] */ BSTR *pbstrTitle) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_OSDName( 
            /* [out] */ BSTR *pbstrName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_OSDAbstract( 
            /* [out] */ BSTR *pbstrAbstract) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_OSDVersion( 
            /* [out] */ BSTR *pbstrVersion) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsOpenSoftwareDistributionInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsOpenSoftwareDistributionInfo * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsOpenSoftwareDistributionInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsOpenSoftwareDistributionInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *get_OSDTitle )( 
            IVsOpenSoftwareDistributionInfo * This,
            /* [out] */ BSTR *pbstrTitle);
        
        HRESULT ( STDMETHODCALLTYPE *get_OSDName )( 
            IVsOpenSoftwareDistributionInfo * This,
            /* [out] */ BSTR *pbstrName);
        
        HRESULT ( STDMETHODCALLTYPE *get_OSDAbstract )( 
            IVsOpenSoftwareDistributionInfo * This,
            /* [out] */ BSTR *pbstrAbstract);
        
        HRESULT ( STDMETHODCALLTYPE *get_OSDVersion )( 
            IVsOpenSoftwareDistributionInfo * This,
            /* [out] */ BSTR *pbstrVersion);
        
        END_INTERFACE
    } IVsOpenSoftwareDistributionInfoVtbl;

    interface IVsOpenSoftwareDistributionInfo
    {
        CONST_VTBL struct IVsOpenSoftwareDistributionInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsOpenSoftwareDistributionInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsOpenSoftwareDistributionInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsOpenSoftwareDistributionInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsOpenSoftwareDistributionInfo_get_OSDTitle(This,pbstrTitle)	\
    (This)->lpVtbl -> get_OSDTitle(This,pbstrTitle)

#define IVsOpenSoftwareDistributionInfo_get_OSDName(This,pbstrName)	\
    (This)->lpVtbl -> get_OSDName(This,pbstrName)

#define IVsOpenSoftwareDistributionInfo_get_OSDAbstract(This,pbstrAbstract)	\
    (This)->lpVtbl -> get_OSDAbstract(This,pbstrAbstract)

#define IVsOpenSoftwareDistributionInfo_get_OSDVersion(This,pbstrVersion)	\
    (This)->lpVtbl -> get_OSDVersion(This,pbstrVersion)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsOpenSoftwareDistributionInfo_get_OSDTitle_Proxy( 
    IVsOpenSoftwareDistributionInfo * This,
    /* [out] */ BSTR *pbstrTitle);


void __RPC_STUB IVsOpenSoftwareDistributionInfo_get_OSDTitle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsOpenSoftwareDistributionInfo_get_OSDName_Proxy( 
    IVsOpenSoftwareDistributionInfo * This,
    /* [out] */ BSTR *pbstrName);


void __RPC_STUB IVsOpenSoftwareDistributionInfo_get_OSDName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsOpenSoftwareDistributionInfo_get_OSDAbstract_Proxy( 
    IVsOpenSoftwareDistributionInfo * This,
    /* [out] */ BSTR *pbstrAbstract);


void __RPC_STUB IVsOpenSoftwareDistributionInfo_get_OSDAbstract_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsOpenSoftwareDistributionInfo_get_OSDVersion_Proxy( 
    IVsOpenSoftwareDistributionInfo * This,
    /* [out] */ BSTR *pbstrVersion);


void __RPC_STUB IVsOpenSoftwareDistributionInfo_get_OSDVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsOpenSoftwareDistributionInfo_INTERFACE_DEFINED__ */


#ifndef __IVsCABPermissionsPageSettings_INTERFACE_DEFINED__
#define __IVsCABPermissionsPageSettings_INTERFACE_DEFINED__

/* interface IVsCABPermissionsPageSettings */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsCABPermissionsPageSettings;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a57e3d77-d2d3-11d0-8a50-00a0c91e2acd")
    IVsCABPermissionsPageSettings : public IUnknown
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IVsCABPermissionsPageSettingsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsCABPermissionsPageSettings * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsCABPermissionsPageSettings * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsCABPermissionsPageSettings * This);
        
        END_INTERFACE
    } IVsCABPermissionsPageSettingsVtbl;

    interface IVsCABPermissionsPageSettings
    {
        CONST_VTBL struct IVsCABPermissionsPageSettingsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsCABPermissionsPageSettings_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsCABPermissionsPageSettings_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsCABPermissionsPageSettings_Release(This)	\
    (This)->lpVtbl -> Release(This)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVsCABPermissionsPageSettings_INTERFACE_DEFINED__ */


#ifndef __IVsVMPermission_INTERFACE_DEFINED__
#define __IVsVMPermission_INTERFACE_DEFINED__

/* interface IVsVMPermission */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsVMPermission;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a57e3d79-d2d3-11d0-8a50-00a0c91e2acd")
    IVsVMPermission : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE get_FriendlyName( 
            /* [out] */ BSTR *pbstrFriendlyName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_Description( 
            /* [out] */ BSTR *pbstrDescription) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_PermissionId( 
            /* [out] */ BSTR *pbstrPermissionId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_Setting( 
            /* [in] */ BOOL fState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_Setting( 
            /* [out] */ BOOL *pfState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Copy( 
            /* [out] */ IVsVMPermission **ppIVsVMPermission) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsVMPermissionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsVMPermission * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsVMPermission * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsVMPermission * This);
        
        HRESULT ( STDMETHODCALLTYPE *get_FriendlyName )( 
            IVsVMPermission * This,
            /* [out] */ BSTR *pbstrFriendlyName);
        
        HRESULT ( STDMETHODCALLTYPE *get_Description )( 
            IVsVMPermission * This,
            /* [out] */ BSTR *pbstrDescription);
        
        HRESULT ( STDMETHODCALLTYPE *get_PermissionId )( 
            IVsVMPermission * This,
            /* [out] */ BSTR *pbstrPermissionId);
        
        HRESULT ( STDMETHODCALLTYPE *put_Setting )( 
            IVsVMPermission * This,
            /* [in] */ BOOL fState);
        
        HRESULT ( STDMETHODCALLTYPE *get_Setting )( 
            IVsVMPermission * This,
            /* [out] */ BOOL *pfState);
        
        HRESULT ( STDMETHODCALLTYPE *Copy )( 
            IVsVMPermission * This,
            /* [out] */ IVsVMPermission **ppIVsVMPermission);
        
        END_INTERFACE
    } IVsVMPermissionVtbl;

    interface IVsVMPermission
    {
        CONST_VTBL struct IVsVMPermissionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsVMPermission_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsVMPermission_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsVMPermission_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsVMPermission_get_FriendlyName(This,pbstrFriendlyName)	\
    (This)->lpVtbl -> get_FriendlyName(This,pbstrFriendlyName)

#define IVsVMPermission_get_Description(This,pbstrDescription)	\
    (This)->lpVtbl -> get_Description(This,pbstrDescription)

#define IVsVMPermission_get_PermissionId(This,pbstrPermissionId)	\
    (This)->lpVtbl -> get_PermissionId(This,pbstrPermissionId)

#define IVsVMPermission_put_Setting(This,fState)	\
    (This)->lpVtbl -> put_Setting(This,fState)

#define IVsVMPermission_get_Setting(This,pfState)	\
    (This)->lpVtbl -> get_Setting(This,pfState)

#define IVsVMPermission_Copy(This,ppIVsVMPermission)	\
    (This)->lpVtbl -> Copy(This,ppIVsVMPermission)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsVMPermission_get_FriendlyName_Proxy( 
    IVsVMPermission * This,
    /* [out] */ BSTR *pbstrFriendlyName);


void __RPC_STUB IVsVMPermission_get_FriendlyName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsVMPermission_get_Description_Proxy( 
    IVsVMPermission * This,
    /* [out] */ BSTR *pbstrDescription);


void __RPC_STUB IVsVMPermission_get_Description_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsVMPermission_get_PermissionId_Proxy( 
    IVsVMPermission * This,
    /* [out] */ BSTR *pbstrPermissionId);


void __RPC_STUB IVsVMPermission_get_PermissionId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsVMPermission_put_Setting_Proxy( 
    IVsVMPermission * This,
    /* [in] */ BOOL fState);


void __RPC_STUB IVsVMPermission_put_Setting_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsVMPermission_get_Setting_Proxy( 
    IVsVMPermission * This,
    /* [out] */ BOOL *pfState);


void __RPC_STUB IVsVMPermission_get_Setting_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsVMPermission_Copy_Proxy( 
    IVsVMPermission * This,
    /* [out] */ IVsVMPermission **ppIVsVMPermission);


void __RPC_STUB IVsVMPermission_Copy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsVMPermission_INTERFACE_DEFINED__ */


#ifndef __IVsVMPermissionProvider_INTERFACE_DEFINED__
#define __IVsVMPermissionProvider_INTERFACE_DEFINED__

/* interface IVsVMPermissionProvider */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsVMPermissionProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a57e3d78-d2d3-11d0-8a50-00a0c91e2acd")
    IVsVMPermissionProvider : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE LoadPermission( 
            /* [in] */ IPropertyBag *pIPropertyBag,
            /* [out] */ IVsVMPermission **ppIVsVMPermission) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ConstructVMPermissionCollection( 
            /* [in] */ int iCollectionType,
            /* [out] */ IVsVMPermissionCollection **ppIVsVMPermissionCollection) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsVMPermissionProviderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsVMPermissionProvider * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsVMPermissionProvider * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsVMPermissionProvider * This);
        
        HRESULT ( STDMETHODCALLTYPE *LoadPermission )( 
            IVsVMPermissionProvider * This,
            /* [in] */ IPropertyBag *pIPropertyBag,
            /* [out] */ IVsVMPermission **ppIVsVMPermission);
        
        HRESULT ( STDMETHODCALLTYPE *ConstructVMPermissionCollection )( 
            IVsVMPermissionProvider * This,
            /* [in] */ int iCollectionType,
            /* [out] */ IVsVMPermissionCollection **ppIVsVMPermissionCollection);
        
        END_INTERFACE
    } IVsVMPermissionProviderVtbl;

    interface IVsVMPermissionProvider
    {
        CONST_VTBL struct IVsVMPermissionProviderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsVMPermissionProvider_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsVMPermissionProvider_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsVMPermissionProvider_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsVMPermissionProvider_LoadPermission(This,pIPropertyBag,ppIVsVMPermission)	\
    (This)->lpVtbl -> LoadPermission(This,pIPropertyBag,ppIVsVMPermission)

#define IVsVMPermissionProvider_ConstructVMPermissionCollection(This,iCollectionType,ppIVsVMPermissionCollection)	\
    (This)->lpVtbl -> ConstructVMPermissionCollection(This,iCollectionType,ppIVsVMPermissionCollection)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsVMPermissionProvider_LoadPermission_Proxy( 
    IVsVMPermissionProvider * This,
    /* [in] */ IPropertyBag *pIPropertyBag,
    /* [out] */ IVsVMPermission **ppIVsVMPermission);


void __RPC_STUB IVsVMPermissionProvider_LoadPermission_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsVMPermissionProvider_ConstructVMPermissionCollection_Proxy( 
    IVsVMPermissionProvider * This,
    /* [in] */ int iCollectionType,
    /* [out] */ IVsVMPermissionCollection **ppIVsVMPermissionCollection);


void __RPC_STUB IVsVMPermissionProvider_ConstructVMPermissionCollection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsVMPermissionProvider_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vspkg_0724 */
/* [local] */ 

#define SID_SVsVMSystemPermissionProvider IID_IVsVMPermissionProvider


extern RPC_IF_HANDLE __MIDL_itf_vspkg_0724_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vspkg_0724_v0_0_s_ifspec;

#ifndef __IVsEnumVMPermissions_INTERFACE_DEFINED__
#define __IVsEnumVMPermissions_INTERFACE_DEFINED__

/* interface IVsEnumVMPermissions */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsEnumVMPermissions;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a57e3d7a-d2d3-11d0-8a50-00a0c91e2acd")
    IVsEnumVMPermissions : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [size_is][out][in] */ IVsVMPermission *rgelt[  ],
            /* [out] */ ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IVsEnumVMPermissions **ppIVsEnumVMPermissions) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsEnumVMPermissionsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsEnumVMPermissions * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsEnumVMPermissions * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsEnumVMPermissions * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IVsEnumVMPermissions * This,
            /* [in] */ ULONG celt,
            /* [size_is][out][in] */ IVsVMPermission *rgelt[  ],
            /* [out] */ ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IVsEnumVMPermissions * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IVsEnumVMPermissions * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IVsEnumVMPermissions * This,
            /* [out] */ IVsEnumVMPermissions **ppIVsEnumVMPermissions);
        
        END_INTERFACE
    } IVsEnumVMPermissionsVtbl;

    interface IVsEnumVMPermissions
    {
        CONST_VTBL struct IVsEnumVMPermissionsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsEnumVMPermissions_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsEnumVMPermissions_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsEnumVMPermissions_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsEnumVMPermissions_Next(This,celt,rgelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched)

#define IVsEnumVMPermissions_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IVsEnumVMPermissions_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IVsEnumVMPermissions_Clone(This,ppIVsEnumVMPermissions)	\
    (This)->lpVtbl -> Clone(This,ppIVsEnumVMPermissions)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsEnumVMPermissions_Next_Proxy( 
    IVsEnumVMPermissions * This,
    /* [in] */ ULONG celt,
    /* [size_is][out][in] */ IVsVMPermission *rgelt[  ],
    /* [out] */ ULONG *pceltFetched);


void __RPC_STUB IVsEnumVMPermissions_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsEnumVMPermissions_Skip_Proxy( 
    IVsEnumVMPermissions * This,
    /* [in] */ ULONG celt);


void __RPC_STUB IVsEnumVMPermissions_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsEnumVMPermissions_Reset_Proxy( 
    IVsEnumVMPermissions * This);


void __RPC_STUB IVsEnumVMPermissions_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsEnumVMPermissions_Clone_Proxy( 
    IVsEnumVMPermissions * This,
    /* [out] */ IVsEnumVMPermissions **ppIVsEnumVMPermissions);


void __RPC_STUB IVsEnumVMPermissions_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsEnumVMPermissions_INTERFACE_DEFINED__ */


#ifndef __IVsVMPermissionCollection_INTERFACE_DEFINED__
#define __IVsVMPermissionCollection_INTERFACE_DEFINED__

/* interface IVsVMPermissionCollection */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsVMPermissionCollection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a57e3d7b-d2d3-11d0-8a50-00a0c91e2acd")
    IVsVMPermissionCollection : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE EnumCollectionVMPermissions( 
            /* [out] */ IVsEnumVMPermissions **ppIVsEnumVMPermissions) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WriteCollectionAsIni( 
            /* [full][string][in] */ LPCOLESTR szIniFilename,
            /* [in] */ BOOL fActiveX) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Copy( 
            /* [out] */ IVsVMPermissionCollection **ppIVsVMPermissionCollection) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsVMPermissionCollectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsVMPermissionCollection * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsVMPermissionCollection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsVMPermissionCollection * This);
        
        HRESULT ( STDMETHODCALLTYPE *EnumCollectionVMPermissions )( 
            IVsVMPermissionCollection * This,
            /* [out] */ IVsEnumVMPermissions **ppIVsEnumVMPermissions);
        
        HRESULT ( STDMETHODCALLTYPE *WriteCollectionAsIni )( 
            IVsVMPermissionCollection * This,
            /* [full][string][in] */ LPCOLESTR szIniFilename,
            /* [in] */ BOOL fActiveX);
        
        HRESULT ( STDMETHODCALLTYPE *Copy )( 
            IVsVMPermissionCollection * This,
            /* [out] */ IVsVMPermissionCollection **ppIVsVMPermissionCollection);
        
        END_INTERFACE
    } IVsVMPermissionCollectionVtbl;

    interface IVsVMPermissionCollection
    {
        CONST_VTBL struct IVsVMPermissionCollectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsVMPermissionCollection_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsVMPermissionCollection_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsVMPermissionCollection_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsVMPermissionCollection_EnumCollectionVMPermissions(This,ppIVsEnumVMPermissions)	\
    (This)->lpVtbl -> EnumCollectionVMPermissions(This,ppIVsEnumVMPermissions)

#define IVsVMPermissionCollection_WriteCollectionAsIni(This,szIniFilename,fActiveX)	\
    (This)->lpVtbl -> WriteCollectionAsIni(This,szIniFilename,fActiveX)

#define IVsVMPermissionCollection_Copy(This,ppIVsVMPermissionCollection)	\
    (This)->lpVtbl -> Copy(This,ppIVsVMPermissionCollection)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsVMPermissionCollection_EnumCollectionVMPermissions_Proxy( 
    IVsVMPermissionCollection * This,
    /* [out] */ IVsEnumVMPermissions **ppIVsEnumVMPermissions);


void __RPC_STUB IVsVMPermissionCollection_EnumCollectionVMPermissions_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsVMPermissionCollection_WriteCollectionAsIni_Proxy( 
    IVsVMPermissionCollection * This,
    /* [full][string][in] */ LPCOLESTR szIniFilename,
    /* [in] */ BOOL fActiveX);


void __RPC_STUB IVsVMPermissionCollection_WriteCollectionAsIni_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsVMPermissionCollection_Copy_Proxy( 
    IVsVMPermissionCollection * This,
    /* [out] */ IVsVMPermissionCollection **ppIVsVMPermissionCollection);


void __RPC_STUB IVsVMPermissionCollection_Copy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsVMPermissionCollection_INTERFACE_DEFINED__ */


#ifndef __IVsVMPermissionProperty_INTERFACE_DEFINED__
#define __IVsVMPermissionProperty_INTERFACE_DEFINED__

/* interface IVsVMPermissionProperty */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsVMPermissionProperty;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a57e3d7c-d2d3-11d0-8a50-00a0c91e2acd")
    IVsVMPermissionProperty : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE get_PropertyName( 
            /* [out] */ BSTR *pbstrPropertyName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_PropertyType( 
            /* [out] */ UINT *puiPropertyType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_PropertyValue( 
            /* [in] */ LPCOLESTR pszPropertyValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_PropertyValue( 
            /* [out] */ BSTR *pbstrPropertyValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Copy( 
            /* [out] */ IVsVMPermissionProperty **ppIVsVMPermissionProperty) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsVMPermissionPropertyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsVMPermissionProperty * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsVMPermissionProperty * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsVMPermissionProperty * This);
        
        HRESULT ( STDMETHODCALLTYPE *get_PropertyName )( 
            IVsVMPermissionProperty * This,
            /* [out] */ BSTR *pbstrPropertyName);
        
        HRESULT ( STDMETHODCALLTYPE *get_PropertyType )( 
            IVsVMPermissionProperty * This,
            /* [out] */ UINT *puiPropertyType);
        
        HRESULT ( STDMETHODCALLTYPE *put_PropertyValue )( 
            IVsVMPermissionProperty * This,
            /* [in] */ LPCOLESTR pszPropertyValue);
        
        HRESULT ( STDMETHODCALLTYPE *get_PropertyValue )( 
            IVsVMPermissionProperty * This,
            /* [out] */ BSTR *pbstrPropertyValue);
        
        HRESULT ( STDMETHODCALLTYPE *Copy )( 
            IVsVMPermissionProperty * This,
            /* [out] */ IVsVMPermissionProperty **ppIVsVMPermissionProperty);
        
        END_INTERFACE
    } IVsVMPermissionPropertyVtbl;

    interface IVsVMPermissionProperty
    {
        CONST_VTBL struct IVsVMPermissionPropertyVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsVMPermissionProperty_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsVMPermissionProperty_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsVMPermissionProperty_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsVMPermissionProperty_get_PropertyName(This,pbstrPropertyName)	\
    (This)->lpVtbl -> get_PropertyName(This,pbstrPropertyName)

#define IVsVMPermissionProperty_get_PropertyType(This,puiPropertyType)	\
    (This)->lpVtbl -> get_PropertyType(This,puiPropertyType)

#define IVsVMPermissionProperty_put_PropertyValue(This,pszPropertyValue)	\
    (This)->lpVtbl -> put_PropertyValue(This,pszPropertyValue)

#define IVsVMPermissionProperty_get_PropertyValue(This,pbstrPropertyValue)	\
    (This)->lpVtbl -> get_PropertyValue(This,pbstrPropertyValue)

#define IVsVMPermissionProperty_Copy(This,ppIVsVMPermissionProperty)	\
    (This)->lpVtbl -> Copy(This,ppIVsVMPermissionProperty)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsVMPermissionProperty_get_PropertyName_Proxy( 
    IVsVMPermissionProperty * This,
    /* [out] */ BSTR *pbstrPropertyName);


void __RPC_STUB IVsVMPermissionProperty_get_PropertyName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsVMPermissionProperty_get_PropertyType_Proxy( 
    IVsVMPermissionProperty * This,
    /* [out] */ UINT *puiPropertyType);


void __RPC_STUB IVsVMPermissionProperty_get_PropertyType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsVMPermissionProperty_put_PropertyValue_Proxy( 
    IVsVMPermissionProperty * This,
    /* [in] */ LPCOLESTR pszPropertyValue);


void __RPC_STUB IVsVMPermissionProperty_put_PropertyValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsVMPermissionProperty_get_PropertyValue_Proxy( 
    IVsVMPermissionProperty * This,
    /* [out] */ BSTR *pbstrPropertyValue);


void __RPC_STUB IVsVMPermissionProperty_get_PropertyValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsVMPermissionProperty_Copy_Proxy( 
    IVsVMPermissionProperty * This,
    /* [out] */ IVsVMPermissionProperty **ppIVsVMPermissionProperty);


void __RPC_STUB IVsVMPermissionProperty_Copy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsVMPermissionProperty_INTERFACE_DEFINED__ */


#ifndef __IVsEnumVMPermissionProperties_INTERFACE_DEFINED__
#define __IVsEnumVMPermissionProperties_INTERFACE_DEFINED__

/* interface IVsEnumVMPermissionProperties */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsEnumVMPermissionProperties;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a57e3d7d-d2d3-11d0-8a50-00a0c91e2acd")
    IVsEnumVMPermissionProperties : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [size_is][out][in] */ IVsVMPermissionProperty *rgelt[  ],
            /* [out] */ ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IVsEnumVMPermissionProperties **ppIVsEnumVMPermissionProperties) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsEnumVMPermissionPropertiesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsEnumVMPermissionProperties * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsEnumVMPermissionProperties * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsEnumVMPermissionProperties * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IVsEnumVMPermissionProperties * This,
            /* [in] */ ULONG celt,
            /* [size_is][out][in] */ IVsVMPermissionProperty *rgelt[  ],
            /* [out] */ ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IVsEnumVMPermissionProperties * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IVsEnumVMPermissionProperties * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IVsEnumVMPermissionProperties * This,
            /* [out] */ IVsEnumVMPermissionProperties **ppIVsEnumVMPermissionProperties);
        
        END_INTERFACE
    } IVsEnumVMPermissionPropertiesVtbl;

    interface IVsEnumVMPermissionProperties
    {
        CONST_VTBL struct IVsEnumVMPermissionPropertiesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsEnumVMPermissionProperties_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsEnumVMPermissionProperties_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsEnumVMPermissionProperties_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsEnumVMPermissionProperties_Next(This,celt,rgelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgelt,pceltFetched)

#define IVsEnumVMPermissionProperties_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IVsEnumVMPermissionProperties_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IVsEnumVMPermissionProperties_Clone(This,ppIVsEnumVMPermissionProperties)	\
    (This)->lpVtbl -> Clone(This,ppIVsEnumVMPermissionProperties)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsEnumVMPermissionProperties_Next_Proxy( 
    IVsEnumVMPermissionProperties * This,
    /* [in] */ ULONG celt,
    /* [size_is][out][in] */ IVsVMPermissionProperty *rgelt[  ],
    /* [out] */ ULONG *pceltFetched);


void __RPC_STUB IVsEnumVMPermissionProperties_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsEnumVMPermissionProperties_Skip_Proxy( 
    IVsEnumVMPermissionProperties * This,
    /* [in] */ ULONG celt);


void __RPC_STUB IVsEnumVMPermissionProperties_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsEnumVMPermissionProperties_Reset_Proxy( 
    IVsEnumVMPermissionProperties * This);


void __RPC_STUB IVsEnumVMPermissionProperties_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsEnumVMPermissionProperties_Clone_Proxy( 
    IVsEnumVMPermissionProperties * This,
    /* [out] */ IVsEnumVMPermissionProperties **ppIVsEnumVMPermissionProperties);


void __RPC_STUB IVsEnumVMPermissionProperties_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsEnumVMPermissionProperties_INTERFACE_DEFINED__ */


#ifndef __IVsCABExternalDependenciesPageSettings_INTERFACE_DEFINED__
#define __IVsCABExternalDependenciesPageSettings_INTERFACE_DEFINED__

/* interface IVsCABExternalDependenciesPageSettings */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsCABExternalDependenciesPageSettings;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a57e3d7e-d2d3-11d0-8a50-00a0c91e2acd")
    IVsCABExternalDependenciesPageSettings : public IUnknown
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IVsCABExternalDependenciesPageSettingsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsCABExternalDependenciesPageSettings * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsCABExternalDependenciesPageSettings * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsCABExternalDependenciesPageSettings * This);
        
        END_INTERFACE
    } IVsCABExternalDependenciesPageSettingsVtbl;

    interface IVsCABExternalDependenciesPageSettings
    {
        CONST_VTBL struct IVsCABExternalDependenciesPageSettingsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsCABExternalDependenciesPageSettings_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsCABExternalDependenciesPageSettings_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsCABExternalDependenciesPageSettings_Release(This)	\
    (This)->lpVtbl -> Release(This)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVsCABExternalDependenciesPageSettings_INTERFACE_DEFINED__ */


#ifndef __IVsPNPAdditionalFilesPageSettings_INTERFACE_DEFINED__
#define __IVsPNPAdditionalFilesPageSettings_INTERFACE_DEFINED__

/* interface IVsPNPAdditionalFilesPageSettings */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsPNPAdditionalFilesPageSettings;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a57e3d7f-d2d3-11d0-8a50-00a0c91e2acd")
    IVsPNPAdditionalFilesPageSettings : public IUnknown
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IVsPNPAdditionalFilesPageSettingsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsPNPAdditionalFilesPageSettings * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsPNPAdditionalFilesPageSettings * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsPNPAdditionalFilesPageSettings * This);
        
        END_INTERFACE
    } IVsPNPAdditionalFilesPageSettingsVtbl;

    interface IVsPNPAdditionalFilesPageSettings
    {
        CONST_VTBL struct IVsPNPAdditionalFilesPageSettingsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsPNPAdditionalFilesPageSettings_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsPNPAdditionalFilesPageSettings_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsPNPAdditionalFilesPageSettings_Release(This)	\
    (This)->lpVtbl -> Release(This)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IVsPNPAdditionalFilesPageSettings_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vspkg_0730 */
/* [local] */ 

#ifndef __ENUMVSPACKAGEWEBLIBENUMS
#define __ENUMVSPACKAGEWEBLIBENUMS

enum __VSPKGWEBLIBUSES
    {	VSPKGWEBLIBEXTERNALDEPENDENCY	= 0x1,
	VSPKGWEBLIBSETUPLIBRARY	= 0x2
    } ;
#endif


extern RPC_IF_HANDLE __MIDL_itf_vspkg_0730_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vspkg_0730_v0_0_s_ifspec;

#ifndef __IVsWebLibrary_INTERFACE_DEFINED__
#define __IVsWebLibrary_INTERFACE_DEFINED__

/* interface IVsWebLibrary */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsWebLibrary;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a57e3d82-d2d3-11d0-8a50-00a0c91e2acd")
    IVsWebLibrary : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE get_INFSectionByName( 
            /* [in] */ LPCOLESTR pszSectionName,
            /* [out] */ DWORD *pdwPriority,
            /* [in] */ ULONG cch,
            /* [size_is][out][in] */ OLECHAR rgchBuffer[  ],
            /* [out] */ ULONG *pcchActual) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_SLIBSectionByName( 
            /* [in] */ LPCOLESTR pszSectionName,
            /* [out] */ BSTR *pbstrOut) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_SectionName( 
            /* [out] */ BSTR *pbstrSectionName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_Flags( 
            /* [out] */ DWORD *pdwFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE put_Setting( 
            /* [in] */ BOOL fState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE get_Setting( 
            /* [out] */ BOOL *pfState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Copy( 
            /* [out] */ IVsWebLibrary **ppIVsWebLibrary) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsWebLibraryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsWebLibrary * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsWebLibrary * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsWebLibrary * This);
        
        HRESULT ( STDMETHODCALLTYPE *get_INFSectionByName )( 
            IVsWebLibrary * This,
            /* [in] */ LPCOLESTR pszSectionName,
            /* [out] */ DWORD *pdwPriority,
            /* [in] */ ULONG cch,
            /* [size_is][out][in] */ OLECHAR rgchBuffer[  ],
            /* [out] */ ULONG *pcchActual);
        
        HRESULT ( STDMETHODCALLTYPE *get_SLIBSectionByName )( 
            IVsWebLibrary * This,
            /* [in] */ LPCOLESTR pszSectionName,
            /* [out] */ BSTR *pbstrOut);
        
        HRESULT ( STDMETHODCALLTYPE *get_SectionName )( 
            IVsWebLibrary * This,
            /* [out] */ BSTR *pbstrSectionName);
        
        HRESULT ( STDMETHODCALLTYPE *get_Flags )( 
            IVsWebLibrary * This,
            /* [out] */ DWORD *pdwFlags);
        
        HRESULT ( STDMETHODCALLTYPE *put_Setting )( 
            IVsWebLibrary * This,
            /* [in] */ BOOL fState);
        
        HRESULT ( STDMETHODCALLTYPE *get_Setting )( 
            IVsWebLibrary * This,
            /* [out] */ BOOL *pfState);
        
        HRESULT ( STDMETHODCALLTYPE *Copy )( 
            IVsWebLibrary * This,
            /* [out] */ IVsWebLibrary **ppIVsWebLibrary);
        
        END_INTERFACE
    } IVsWebLibraryVtbl;

    interface IVsWebLibrary
    {
        CONST_VTBL struct IVsWebLibraryVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsWebLibrary_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsWebLibrary_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsWebLibrary_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsWebLibrary_get_INFSectionByName(This,pszSectionName,pdwPriority,cch,rgchBuffer,pcchActual)	\
    (This)->lpVtbl -> get_INFSectionByName(This,pszSectionName,pdwPriority,cch,rgchBuffer,pcchActual)

#define IVsWebLibrary_get_SLIBSectionByName(This,pszSectionName,pbstrOut)	\
    (This)->lpVtbl -> get_SLIBSectionByName(This,pszSectionName,pbstrOut)

#define IVsWebLibrary_get_SectionName(This,pbstrSectionName)	\
    (This)->lpVtbl -> get_SectionName(This,pbstrSectionName)

#define IVsWebLibrary_get_Flags(This,pdwFlags)	\
    (This)->lpVtbl -> get_Flags(This,pdwFlags)

#define IVsWebLibrary_put_Setting(This,fState)	\
    (This)->lpVtbl -> put_Setting(This,fState)

#define IVsWebLibrary_get_Setting(This,pfState)	\
    (This)->lpVtbl -> get_Setting(This,pfState)

#define IVsWebLibrary_Copy(This,ppIVsWebLibrary)	\
    (This)->lpVtbl -> Copy(This,ppIVsWebLibrary)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsWebLibrary_get_INFSectionByName_Proxy( 
    IVsWebLibrary * This,
    /* [in] */ LPCOLESTR pszSectionName,
    /* [out] */ DWORD *pdwPriority,
    /* [in] */ ULONG cch,
    /* [size_is][out][in] */ OLECHAR rgchBuffer[  ],
    /* [out] */ ULONG *pcchActual);


void __RPC_STUB IVsWebLibrary_get_INFSectionByName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsWebLibrary_get_SLIBSectionByName_Proxy( 
    IVsWebLibrary * This,
    /* [in] */ LPCOLESTR pszSectionName,
    /* [out] */ BSTR *pbstrOut);


void __RPC_STUB IVsWebLibrary_get_SLIBSectionByName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsWebLibrary_get_SectionName_Proxy( 
    IVsWebLibrary * This,
    /* [out] */ BSTR *pbstrSectionName);


void __RPC_STUB IVsWebLibrary_get_SectionName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsWebLibrary_get_Flags_Proxy( 
    IVsWebLibrary * This,
    /* [out] */ DWORD *pdwFlags);


void __RPC_STUB IVsWebLibrary_get_Flags_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsWebLibrary_put_Setting_Proxy( 
    IVsWebLibrary * This,
    /* [in] */ BOOL fState);


void __RPC_STUB IVsWebLibrary_put_Setting_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsWebLibrary_get_Setting_Proxy( 
    IVsWebLibrary * This,
    /* [out] */ BOOL *pfState);


void __RPC_STUB IVsWebLibrary_get_Setting_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsWebLibrary_Copy_Proxy( 
    IVsWebLibrary * This,
    /* [out] */ IVsWebLibrary **ppIVsWebLibrary);


void __RPC_STUB IVsWebLibrary_Copy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsWebLibrary_INTERFACE_DEFINED__ */


#ifndef __IVsWebLibraryProvider_INTERFACE_DEFINED__
#define __IVsWebLibraryProvider_INTERFACE_DEFINED__

/* interface IVsWebLibraryProvider */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsWebLibraryProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a57e3d83-d2d3-11d0-8a50-00a0c91e2acd")
    IVsWebLibraryProvider : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE LoadPermission( 
            /* [in] */ IPropertyBag *pIPropertyBag,
            /* [out] */ IVsWebLibrary **ppIVsWebLibrary) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ConstructWebLibraryCollection( 
            /* [in] */ int iCollectionType,
            /* [out] */ IVsWebLibraryCollection **ppIVsWebLibraryCollection) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsWebLibraryProviderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsWebLibraryProvider * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsWebLibraryProvider * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsWebLibraryProvider * This);
        
        HRESULT ( STDMETHODCALLTYPE *LoadPermission )( 
            IVsWebLibraryProvider * This,
            /* [in] */ IPropertyBag *pIPropertyBag,
            /* [out] */ IVsWebLibrary **ppIVsWebLibrary);
        
        HRESULT ( STDMETHODCALLTYPE *ConstructWebLibraryCollection )( 
            IVsWebLibraryProvider * This,
            /* [in] */ int iCollectionType,
            /* [out] */ IVsWebLibraryCollection **ppIVsWebLibraryCollection);
        
        END_INTERFACE
    } IVsWebLibraryProviderVtbl;

    interface IVsWebLibraryProvider
    {
        CONST_VTBL struct IVsWebLibraryProviderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsWebLibraryProvider_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsWebLibraryProvider_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsWebLibraryProvider_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsWebLibraryProvider_LoadPermission(This,pIPropertyBag,ppIVsWebLibrary)	\
    (This)->lpVtbl -> LoadPermission(This,pIPropertyBag,ppIVsWebLibrary)

#define IVsWebLibraryProvider_ConstructWebLibraryCollection(This,iCollectionType,ppIVsWebLibraryCollection)	\
    (This)->lpVtbl -> ConstructWebLibraryCollection(This,iCollectionType,ppIVsWebLibraryCollection)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsWebLibraryProvider_LoadPermission_Proxy( 
    IVsWebLibraryProvider * This,
    /* [in] */ IPropertyBag *pIPropertyBag,
    /* [out] */ IVsWebLibrary **ppIVsWebLibrary);


void __RPC_STUB IVsWebLibraryProvider_LoadPermission_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsWebLibraryProvider_ConstructWebLibraryCollection_Proxy( 
    IVsWebLibraryProvider * This,
    /* [in] */ int iCollectionType,
    /* [out] */ IVsWebLibraryCollection **ppIVsWebLibraryCollection);


void __RPC_STUB IVsWebLibraryProvider_ConstructWebLibraryCollection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsWebLibraryProvider_INTERFACE_DEFINED__ */


/* interface __MIDL_itf_vspkg_0732 */
/* [local] */ 

typedef /* [unique] */ IVsWebLibrary *PIVsWebLibrary;



extern RPC_IF_HANDLE __MIDL_itf_vspkg_0732_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vspkg_0732_v0_0_s_ifspec;

#ifndef __IVsEnumWebLibraries_INTERFACE_DEFINED__
#define __IVsEnumWebLibraries_INTERFACE_DEFINED__

/* interface IVsEnumWebLibraries */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsEnumWebLibraries;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a57e3d80-d2d3-11d0-8a50-00a0c91e2acd")
    IVsEnumWebLibraries : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG celt,
            /* [size_is][out] */ PIVsWebLibrary *prgelt,
            /* [out] */ ULONG *pceltFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Skip( 
            /* [in] */ ULONG celt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IVsEnumWebLibraries **ppIVsEnumWebLibraries) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsEnumWebLibrariesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsEnumWebLibraries * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsEnumWebLibraries * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsEnumWebLibraries * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IVsEnumWebLibraries * This,
            /* [in] */ ULONG celt,
            /* [size_is][out] */ PIVsWebLibrary *prgelt,
            /* [out] */ ULONG *pceltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IVsEnumWebLibraries * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IVsEnumWebLibraries * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IVsEnumWebLibraries * This,
            /* [out] */ IVsEnumWebLibraries **ppIVsEnumWebLibraries);
        
        END_INTERFACE
    } IVsEnumWebLibrariesVtbl;

    interface IVsEnumWebLibraries
    {
        CONST_VTBL struct IVsEnumWebLibrariesVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsEnumWebLibraries_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsEnumWebLibraries_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsEnumWebLibraries_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsEnumWebLibraries_Next(This,celt,prgelt,pceltFetched)	\
    (This)->lpVtbl -> Next(This,celt,prgelt,pceltFetched)

#define IVsEnumWebLibraries_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IVsEnumWebLibraries_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IVsEnumWebLibraries_Clone(This,ppIVsEnumWebLibraries)	\
    (This)->lpVtbl -> Clone(This,ppIVsEnumWebLibraries)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsEnumWebLibraries_Next_Proxy( 
    IVsEnumWebLibraries * This,
    /* [in] */ ULONG celt,
    /* [size_is][out] */ PIVsWebLibrary *prgelt,
    /* [out] */ ULONG *pceltFetched);


void __RPC_STUB IVsEnumWebLibraries_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsEnumWebLibraries_Skip_Proxy( 
    IVsEnumWebLibraries * This,
    /* [in] */ ULONG celt);


void __RPC_STUB IVsEnumWebLibraries_Skip_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsEnumWebLibraries_Reset_Proxy( 
    IVsEnumWebLibraries * This);


void __RPC_STUB IVsEnumWebLibraries_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsEnumWebLibraries_Clone_Proxy( 
    IVsEnumWebLibraries * This,
    /* [out] */ IVsEnumWebLibraries **ppIVsEnumWebLibraries);


void __RPC_STUB IVsEnumWebLibraries_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsEnumWebLibraries_INTERFACE_DEFINED__ */


#ifndef __IVsWebLibraryCollection_INTERFACE_DEFINED__
#define __IVsWebLibraryCollection_INTERFACE_DEFINED__

/* interface IVsWebLibraryCollection */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsWebLibraryCollection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a57e3d81-d2d3-11d0-8a50-00a0c91e2acd")
    IVsWebLibraryCollection : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE EnumCollectionWebLibraries( 
            /* [out] */ IVsEnumWebLibraries **ppIVsEnumWebLibraries) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Copy( 
            /* [out] */ IVsWebLibraryCollection **ppIVsWebLibraryCollection) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsWebLibraryCollectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsWebLibraryCollection * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsWebLibraryCollection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsWebLibraryCollection * This);
        
        HRESULT ( STDMETHODCALLTYPE *EnumCollectionWebLibraries )( 
            IVsWebLibraryCollection * This,
            /* [out] */ IVsEnumWebLibraries **ppIVsEnumWebLibraries);
        
        HRESULT ( STDMETHODCALLTYPE *Copy )( 
            IVsWebLibraryCollection * This,
            /* [out] */ IVsWebLibraryCollection **ppIVsWebLibraryCollection);
        
        END_INTERFACE
    } IVsWebLibraryCollectionVtbl;

    interface IVsWebLibraryCollection
    {
        CONST_VTBL struct IVsWebLibraryCollectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsWebLibraryCollection_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsWebLibraryCollection_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsWebLibraryCollection_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsWebLibraryCollection_EnumCollectionWebLibraries(This,ppIVsEnumWebLibraries)	\
    (This)->lpVtbl -> EnumCollectionWebLibraries(This,ppIVsEnumWebLibraries)

#define IVsWebLibraryCollection_Copy(This,ppIVsWebLibraryCollection)	\
    (This)->lpVtbl -> Copy(This,ppIVsWebLibraryCollection)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsWebLibraryCollection_EnumCollectionWebLibraries_Proxy( 
    IVsWebLibraryCollection * This,
    /* [out] */ IVsEnumWebLibraries **ppIVsEnumWebLibraries);


void __RPC_STUB IVsWebLibraryCollection_EnumCollectionWebLibraries_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsWebLibraryCollection_Copy_Proxy( 
    IVsWebLibraryCollection * This,
    /* [out] */ IVsWebLibraryCollection **ppIVsWebLibraryCollection);


void __RPC_STUB IVsWebLibraryCollection_Copy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsWebLibraryCollection_INTERFACE_DEFINED__ */


#ifndef __IVsAdditionalItemProvider_INTERFACE_DEFINED__
#define __IVsAdditionalItemProvider_INTERFACE_DEFINED__

/* interface IVsAdditionalItemProvider */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsAdditionalItemProvider;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a57e3d84-d2d3-11d0-8a50-00a0c91e2acd")
    IVsAdditionalItemProvider : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE LoadPermission( 
            /* [in] */ IPropertyBag *pIPropertyBag) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ConstructAdditionalItemCollection( 
            /* [in] */ int iCollectionType,
            /* [out] */ IVsAdditionalItemCollection **ppIVsAdditionalItemCollection) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsAdditionalItemProviderVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsAdditionalItemProvider * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsAdditionalItemProvider * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsAdditionalItemProvider * This);
        
        HRESULT ( STDMETHODCALLTYPE *LoadPermission )( 
            IVsAdditionalItemProvider * This,
            /* [in] */ IPropertyBag *pIPropertyBag);
        
        HRESULT ( STDMETHODCALLTYPE *ConstructAdditionalItemCollection )( 
            IVsAdditionalItemProvider * This,
            /* [in] */ int iCollectionType,
            /* [out] */ IVsAdditionalItemCollection **ppIVsAdditionalItemCollection);
        
        END_INTERFACE
    } IVsAdditionalItemProviderVtbl;

    interface IVsAdditionalItemProvider
    {
        CONST_VTBL struct IVsAdditionalItemProviderVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsAdditionalItemProvider_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsAdditionalItemProvider_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsAdditionalItemProvider_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsAdditionalItemProvider_LoadPermission(This,pIPropertyBag)	\
    (This)->lpVtbl -> LoadPermission(This,pIPropertyBag)

#define IVsAdditionalItemProvider_ConstructAdditionalItemCollection(This,iCollectionType,ppIVsAdditionalItemCollection)	\
    (This)->lpVtbl -> ConstructAdditionalItemCollection(This,iCollectionType,ppIVsAdditionalItemCollection)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsAdditionalItemProvider_LoadPermission_Proxy( 
    IVsAdditionalItemProvider * This,
    /* [in] */ IPropertyBag *pIPropertyBag);


void __RPC_STUB IVsAdditionalItemProvider_LoadPermission_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsAdditionalItemProvider_ConstructAdditionalItemCollection_Proxy( 
    IVsAdditionalItemProvider * This,
    /* [in] */ int iCollectionType,
    /* [out] */ IVsAdditionalItemCollection **ppIVsAdditionalItemCollection);


void __RPC_STUB IVsAdditionalItemProvider_ConstructAdditionalItemCollection_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsAdditionalItemProvider_INTERFACE_DEFINED__ */


#ifndef __IVsAdditionalItemCollection_INTERFACE_DEFINED__
#define __IVsAdditionalItemCollection_INTERFACE_DEFINED__

/* interface IVsAdditionalItemCollection */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsAdditionalItemCollection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("a57e3d85-d2d3-11d0-8a50-00a0c91e2acd")
    IVsAdditionalItemCollection : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE EnumCollectionAdditionalItems( 
            /* [out] */ IVsEnumBSTRs **ppIVsEnumBSTRs) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ LPCOLESTR pszAdditionalItem) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveByIndex( 
            /* [in] */ ULONG ulIndex) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAt( 
            /* [in] */ ULONG ulIndex,
            /* [in] */ LPCOLESTR pszModifiedItem) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Empty( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Copy( 
            /* [out] */ IVsAdditionalItemCollection **ppIVsAdditionalItemCollection) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsAdditionalItemCollectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsAdditionalItemCollection * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsAdditionalItemCollection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsAdditionalItemCollection * This);
        
        HRESULT ( STDMETHODCALLTYPE *EnumCollectionAdditionalItems )( 
            IVsAdditionalItemCollection * This,
            /* [out] */ IVsEnumBSTRs **ppIVsEnumBSTRs);
        
        HRESULT ( STDMETHODCALLTYPE *Add )( 
            IVsAdditionalItemCollection * This,
            /* [in] */ LPCOLESTR pszAdditionalItem);
        
        HRESULT ( STDMETHODCALLTYPE *RemoveByIndex )( 
            IVsAdditionalItemCollection * This,
            /* [in] */ ULONG ulIndex);
        
        HRESULT ( STDMETHODCALLTYPE *SetAt )( 
            IVsAdditionalItemCollection * This,
            /* [in] */ ULONG ulIndex,
            /* [in] */ LPCOLESTR pszModifiedItem);
        
        HRESULT ( STDMETHODCALLTYPE *Empty )( 
            IVsAdditionalItemCollection * This);
        
        HRESULT ( STDMETHODCALLTYPE *Copy )( 
            IVsAdditionalItemCollection * This,
            /* [out] */ IVsAdditionalItemCollection **ppIVsAdditionalItemCollection);
        
        END_INTERFACE
    } IVsAdditionalItemCollectionVtbl;

    interface IVsAdditionalItemCollection
    {
        CONST_VTBL struct IVsAdditionalItemCollectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsAdditionalItemCollection_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsAdditionalItemCollection_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsAdditionalItemCollection_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsAdditionalItemCollection_EnumCollectionAdditionalItems(This,ppIVsEnumBSTRs)	\
    (This)->lpVtbl -> EnumCollectionAdditionalItems(This,ppIVsEnumBSTRs)

#define IVsAdditionalItemCollection_Add(This,pszAdditionalItem)	\
    (This)->lpVtbl -> Add(This,pszAdditionalItem)

#define IVsAdditionalItemCollection_RemoveByIndex(This,ulIndex)	\
    (This)->lpVtbl -> RemoveByIndex(This,ulIndex)

#define IVsAdditionalItemCollection_SetAt(This,ulIndex,pszModifiedItem)	\
    (This)->lpVtbl -> SetAt(This,ulIndex,pszModifiedItem)

#define IVsAdditionalItemCollection_Empty(This)	\
    (This)->lpVtbl -> Empty(This)

#define IVsAdditionalItemCollection_Copy(This,ppIVsAdditionalItemCollection)	\
    (This)->lpVtbl -> Copy(This,ppIVsAdditionalItemCollection)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsAdditionalItemCollection_EnumCollectionAdditionalItems_Proxy( 
    IVsAdditionalItemCollection * This,
    /* [out] */ IVsEnumBSTRs **ppIVsEnumBSTRs);


void __RPC_STUB IVsAdditionalItemCollection_EnumCollectionAdditionalItems_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsAdditionalItemCollection_Add_Proxy( 
    IVsAdditionalItemCollection * This,
    /* [in] */ LPCOLESTR pszAdditionalItem);


void __RPC_STUB IVsAdditionalItemCollection_Add_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsAdditionalItemCollection_RemoveByIndex_Proxy( 
    IVsAdditionalItemCollection * This,
    /* [in] */ ULONG ulIndex);


void __RPC_STUB IVsAdditionalItemCollection_RemoveByIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsAdditionalItemCollection_SetAt_Proxy( 
    IVsAdditionalItemCollection * This,
    /* [in] */ ULONG ulIndex,
    /* [in] */ LPCOLESTR pszModifiedItem);


void __RPC_STUB IVsAdditionalItemCollection_SetAt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsAdditionalItemCollection_Empty_Proxy( 
    IVsAdditionalItemCollection * This);


void __RPC_STUB IVsAdditionalItemCollection_Empty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsAdditionalItemCollection_Copy_Proxy( 
    IVsAdditionalItemCollection * This,
    /* [out] */ IVsAdditionalItemCollection **ppIVsAdditionalItemCollection);


void __RPC_STUB IVsAdditionalItemCollection_Copy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsAdditionalItemCollection_INTERFACE_DEFINED__ */


#ifndef __IVsSubProcess_INTERFACE_DEFINED__
#define __IVsSubProcess_INTERFACE_DEFINED__

/* interface IVsSubProcess */
/* [object][unique][version][uuid] */ 


EXTERN_C const IID IID_IVsSubProcess;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4bfaa76b-cde4-11d0-a95b-00aa004786a8")
    IVsSubProcess : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Start( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryStatus( 
            BOOL *pfBuildDone) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Stop( 
            BOOL fSync) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Wait( 
            DWORD dwMilliseconds,
            BOOL fTickWhenMessageQNotEmpty) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsSubProcessVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsSubProcess * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsSubProcess * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsSubProcess * This);
        
        HRESULT ( STDMETHODCALLTYPE *Start )( 
            IVsSubProcess * This);
        
        HRESULT ( STDMETHODCALLTYPE *QueryStatus )( 
            IVsSubProcess * This,
            BOOL *pfBuildDone);
        
        HRESULT ( STDMETHODCALLTYPE *Stop )( 
            IVsSubProcess * This,
            BOOL fSync);
        
        HRESULT ( STDMETHODCALLTYPE *Wait )( 
            IVsSubProcess * This,
            DWORD dwMilliseconds,
            BOOL fTickWhenMessageQNotEmpty);
        
        END_INTERFACE
    } IVsSubProcessVtbl;

    interface IVsSubProcess
    {
        CONST_VTBL struct IVsSubProcessVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsSubProcess_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsSubProcess_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsSubProcess_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsSubProcess_Start(This)	\
    (This)->lpVtbl -> Start(This)

#define IVsSubProcess_QueryStatus(This,pfBuildDone)	\
    (This)->lpVtbl -> QueryStatus(This,pfBuildDone)

#define IVsSubProcess_Stop(This,fSync)	\
    (This)->lpVtbl -> Stop(This,fSync)

#define IVsSubProcess_Wait(This,dwMilliseconds,fTickWhenMessageQNotEmpty)	\
    (This)->lpVtbl -> Wait(This,dwMilliseconds,fTickWhenMessageQNotEmpty)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsSubProcess_Start_Proxy( 
    IVsSubProcess * This);


void __RPC_STUB IVsSubProcess_Start_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSubProcess_QueryStatus_Proxy( 
    IVsSubProcess * This,
    BOOL *pfBuildDone);


void __RPC_STUB IVsSubProcess_QueryStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSubProcess_Stop_Proxy( 
    IVsSubProcess * This,
    BOOL fSync);


void __RPC_STUB IVsSubProcess_Stop_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSubProcess_Wait_Proxy( 
    IVsSubProcess * This,
    DWORD dwMilliseconds,
    BOOL fTickWhenMessageQNotEmpty);


void __RPC_STUB IVsSubProcess_Wait_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsSubProcess_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


