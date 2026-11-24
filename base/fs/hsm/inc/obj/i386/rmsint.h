

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for rmsint.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


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

#ifndef __rmsint_h__
#define __rmsint_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IRmsServer_FWD_DEFINED__
#define __IRmsServer_FWD_DEFINED__
typedef interface IRmsServer IRmsServer;
#endif 	/* __IRmsServer_FWD_DEFINED__ */


#ifndef __IRmsLibrary_FWD_DEFINED__
#define __IRmsLibrary_FWD_DEFINED__
typedef interface IRmsLibrary IRmsLibrary;
#endif 	/* __IRmsLibrary_FWD_DEFINED__ */


#ifndef __IRmsDriveClass_FWD_DEFINED__
#define __IRmsDriveClass_FWD_DEFINED__
typedef interface IRmsDriveClass IRmsDriveClass;
#endif 	/* __IRmsDriveClass_FWD_DEFINED__ */


#ifndef __IRmsCartridge_FWD_DEFINED__
#define __IRmsCartridge_FWD_DEFINED__
typedef interface IRmsCartridge IRmsCartridge;
#endif 	/* __IRmsCartridge_FWD_DEFINED__ */


#ifndef __IRmsDrive_FWD_DEFINED__
#define __IRmsDrive_FWD_DEFINED__
typedef interface IRmsDrive IRmsDrive;
#endif 	/* __IRmsDrive_FWD_DEFINED__ */


#ifndef __IRmsStorageSlot_FWD_DEFINED__
#define __IRmsStorageSlot_FWD_DEFINED__
typedef interface IRmsStorageSlot IRmsStorageSlot;
#endif 	/* __IRmsStorageSlot_FWD_DEFINED__ */


#ifndef __IRmsMediumChanger_FWD_DEFINED__
#define __IRmsMediumChanger_FWD_DEFINED__
typedef interface IRmsMediumChanger IRmsMediumChanger;
#endif 	/* __IRmsMediumChanger_FWD_DEFINED__ */


#ifndef __IRmsMoveMedia_FWD_DEFINED__
#define __IRmsMoveMedia_FWD_DEFINED__
typedef interface IRmsMoveMedia IRmsMoveMedia;
#endif 	/* __IRmsMoveMedia_FWD_DEFINED__ */


#ifndef __IRmsIEPort_FWD_DEFINED__
#define __IRmsIEPort_FWD_DEFINED__
typedef interface IRmsIEPort IRmsIEPort;
#endif 	/* __IRmsIEPort_FWD_DEFINED__ */


#ifndef __IRmsMediaSet_FWD_DEFINED__
#define __IRmsMediaSet_FWD_DEFINED__
typedef interface IRmsMediaSet IRmsMediaSet;
#endif 	/* __IRmsMediaSet_FWD_DEFINED__ */


#ifndef __IRmsRequest_FWD_DEFINED__
#define __IRmsRequest_FWD_DEFINED__
typedef interface IRmsRequest IRmsRequest;
#endif 	/* __IRmsRequest_FWD_DEFINED__ */


#ifndef __IRmsPartition_FWD_DEFINED__
#define __IRmsPartition_FWD_DEFINED__
typedef interface IRmsPartition IRmsPartition;
#endif 	/* __IRmsPartition_FWD_DEFINED__ */


#ifndef __IRmsComObject_FWD_DEFINED__
#define __IRmsComObject_FWD_DEFINED__
typedef interface IRmsComObject IRmsComObject;
#endif 	/* __IRmsComObject_FWD_DEFINED__ */


#ifndef __IRmsChangerElement_FWD_DEFINED__
#define __IRmsChangerElement_FWD_DEFINED__
typedef interface IRmsChangerElement IRmsChangerElement;
#endif 	/* __IRmsChangerElement_FWD_DEFINED__ */


#ifndef __IRmsDevice_FWD_DEFINED__
#define __IRmsDevice_FWD_DEFINED__
typedef interface IRmsDevice IRmsDevice;
#endif 	/* __IRmsDevice_FWD_DEFINED__ */


#ifndef __IRmsStorageInfo_FWD_DEFINED__
#define __IRmsStorageInfo_FWD_DEFINED__
typedef interface IRmsStorageInfo IRmsStorageInfo;
#endif 	/* __IRmsStorageInfo_FWD_DEFINED__ */


#ifndef __IRmsClient_FWD_DEFINED__
#define __IRmsClient_FWD_DEFINED__
typedef interface IRmsClient IRmsClient;
#endif 	/* __IRmsClient_FWD_DEFINED__ */


#ifndef __IRmsNTMS_FWD_DEFINED__
#define __IRmsNTMS_FWD_DEFINED__
typedef interface IRmsNTMS IRmsNTMS;
#endif 	/* __IRmsNTMS_FWD_DEFINED__ */


#ifndef __IRmsSinkEveryEvent_FWD_DEFINED__
#define __IRmsSinkEveryEvent_FWD_DEFINED__
typedef interface IRmsSinkEveryEvent IRmsSinkEveryEvent;
#endif 	/* __IRmsSinkEveryEvent_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "WsbInt.h"
#include "MvrInt.h"
#include "winioctl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

/* interface __MIDL_itf_rmsint_0000 */
/* [local] */ 







typedef struct _RMS_CHANGER_PARAMETERS
    {
    USHORT x;
    BOOL HasScanner	: 1;
    BOOL CanInitWithRange	: 1;
    BOOL CanCloseIEPort	: 1;
    BOOL CanOpenIEPort	: 1;
    BOOL HasNVROM	: 1;
    BOOL CanExchange	: 1;
    BOOL HasCleanerSlot	: 1;
    BOOL CanLockUnlock	: 1;
    BOOL HasMagazine	: 1;
    BOOL CanFlip	: 1;
    BOOL CanPositionToElement	: 1;
    BOOL DriveIsStorage	: 1;
    BOOL IEPortIsStorage	: 1;
    BOOL SlotIsStorage	: 1;
    BOOL TransportIsStorage	: 1;
    BOOL RequiresHomeUnit	: 1;
    BOOL RequiresCleaning	: 1;
    BOOL RequiresCartridgeEject	: 1;
    BOOL RequiresCleanerEject	: 1;
    BOOL SupportsVolumeId	: 1;
    BOOL SupportsVolumeSequence	: 1;
    BOOL SupportsVolumeSearch	: 1;
    BOOL SupportsVolumeAssert	: 1;
    BOOL SupportsVolumeReplace	: 1;
    BOOL SupportsVolumeUndefine	: 1;
    BOOL CanEnableDisableKeypad	: 1;
    } 	RmsChangerParameters;



extern RPC_IF_HANDLE __MIDL_itf_rmsint_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_rmsint_0000_v0_0_s_ifspec;

#ifndef __IRmsServer_INTERFACE_DEFINED__
#define __IRmsServer_INTERFACE_DEFINED__

/* interface IRmsServer */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRmsServer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DDA2FBE0-33E4-4221-A2C8-D907110397EA")
    IRmsServer : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE IsReady( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ChangeState( 
            /* [in] */ LONG newState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsNTMSInstalled( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNTMS( 
            /* [out] */ IRmsNTMS **ptr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InitializeInAnotherThread( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Initialize( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SaveAll( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetServerName( 
            /* [string][out][in] */ BSTR *pName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCartridges( 
            /* [out] */ IWsbIndexedCollection **ptr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetActiveCartridges( 
            /* [out] */ IWsbIndexedCollection **ptr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDataMovers( 
            /* [out] */ IWsbIndexedCollection **ptr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetActiveCartridge( 
            /* [in] */ IRmsCartridge *ptr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLibraries( 
            /* [out] */ IWsbIndexedCollection **ptr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMediaSets( 
            /* [out] */ IWsbIndexedCollection **ptr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRequests( 
            /* [out] */ IWsbIndexedCollection **ptr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetClients( 
            /* [out] */ IWsbIndexedCollection **ptr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUnconfiguredDevices( 
            /* [out] */ IWsbIndexedCollection **ptr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ScanForDevices( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ScanForDrives( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MountScratchCartridge( 
            /* [out] */ GUID *pCartId,
            /* [in] */ REFGUID fromMediaSet,
            /* [in] */ REFGUID prevSideId,
            /* [out][in] */ LONGLONG *pFreeSpace,
            /* [in] */ LONG blockingFactor,
            /* [string][in] */ BSTR displayName,
            /* [out][in] */ IRmsDrive **ppDrive,
            /* [out] */ IRmsCartridge **ppCartridge,
            /* [out] */ IDataMover **ppDataMover,
            /* [defaultvalue][in] */ DWORD options = 0) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MountCartridge( 
            /* [in] */ REFGUID cartId,
            /* [out][in] */ IRmsDrive **ppDrive,
            /* [out] */ IRmsCartridge **ppCartridge,
            /* [out] */ IDataMover **ppDataMover,
            /* [defaultvalue][in] */ DWORD options = 0,
            /* [defaultvalue][in] */ DWORD threadId = 0) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DismountCartridge( 
            /* [in] */ REFGUID cartId,
            /* [defaultvalue][in] */ DWORD options = 0) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DuplicateCartridge( 
            /* [in] */ REFGUID cartId,
            /* [in] */ REFGUID firstSideId,
            /* [out][in] */ GUID *pCopyCartId,
            /* [in] */ REFGUID copySet,
            /* [string][in] */ BSTR copyName,
            /* [out] */ LONGLONG *pFreeSpace,
            /* [out] */ LONGLONG *pCapacity,
            /* [in] */ DWORD options) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RecycleCartridge( 
            /* [in] */ REFGUID cartId,
            /* [in] */ DWORD options) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FindLibraryById( 
            /* [in] */ REFGUID libId,
            /* [out] */ IRmsLibrary **ptr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FindCartridgeById( 
            /* [in] */ REFGUID cartId,
            /* [out] */ IRmsCartridge **ptr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateObject( 
            /* [in] */ REFGUID objectId,
            /* [in] */ REFCLSID rclsid,
            /* [in] */ REFIID riid,
            /* [in] */ DWORD dwCreate,
            /* [iid_is][out] */ void **ppvObj) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNofAvailableDrives( 
            /* [in] */ REFGUID fromMediaSet,
            /* [out] */ DWORD *pdwNofDrives) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FindCartridgeStatusById( 
            /* [in] */ REFGUID cartId,
            /* [out] */ DWORD *pdwStatus) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsMultipleSidedMedia( 
            /* [in] */ REFGUID mediaSetId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CheckSecondSide( 
            /* [in] */ REFGUID firstSideId,
            /* [out] */ BOOL *pbValid,
            /* [out] */ GUID *pSecondSideId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMaxMediaCapacity( 
            /* [in] */ REFGUID fromMediaSet,
            /* [out] */ LONGLONG *pMaxCapacity) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRmsServerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRmsServer * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRmsServer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRmsServer * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IRmsServer * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IRmsServer * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IRmsServer * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRmsServer * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *IsReady )( 
            IRmsServer * This);
        
        HRESULT ( STDMETHODCALLTYPE *ChangeState )( 
            IRmsServer * This,
            /* [in] */ LONG newState);
        
        HRESULT ( STDMETHODCALLTYPE *IsNTMSInstalled )( 
            IRmsServer * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetNTMS )( 
            IRmsServer * This,
            /* [out] */ IRmsNTMS **ptr);
        
        HRESULT ( STDMETHODCALLTYPE *InitializeInAnotherThread )( 
            IRmsServer * This);
        
        HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IRmsServer * This);
        
        HRESULT ( STDMETHODCALLTYPE *SaveAll )( 
            IRmsServer * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetServerName )( 
            IRmsServer * This,
            /* [string][out][in] */ BSTR *pName);
        
        HRESULT ( STDMETHODCALLTYPE *GetCartridges )( 
            IRmsServer * This,
            /* [out] */ IWsbIndexedCollection **ptr);
        
        HRESULT ( STDMETHODCALLTYPE *GetActiveCartridges )( 
            IRmsServer * This,
            /* [out] */ IWsbIndexedCollection **ptr);
        
        HRESULT ( STDMETHODCALLTYPE *GetDataMovers )( 
            IRmsServer * This,
            /* [out] */ IWsbIndexedCollection **ptr);
        
        HRESULT ( STDMETHODCALLTYPE *SetActiveCartridge )( 
            IRmsServer * This,
            /* [in] */ IRmsCartridge *ptr);
        
        HRESULT ( STDMETHODCALLTYPE *GetLibraries )( 
            IRmsServer * This,
            /* [out] */ IWsbIndexedCollection **ptr);
        
        HRESULT ( STDMETHODCALLTYPE *GetMediaSets )( 
            IRmsServer * This,
            /* [out] */ IWsbIndexedCollection **ptr);
        
        HRESULT ( STDMETHODCALLTYPE *GetRequests )( 
            IRmsServer * This,
            /* [out] */ IWsbIndexedCollection **ptr);
        
        HRESULT ( STDMETHODCALLTYPE *GetClients )( 
            IRmsServer * This,
            /* [out] */ IWsbIndexedCollection **ptr);
        
        HRESULT ( STDMETHODCALLTYPE *GetUnconfiguredDevices )( 
            IRmsServer * This,
            /* [out] */ IWsbIndexedCollection **ptr);
        
        HRESULT ( STDMETHODCALLTYPE *ScanForDevices )( 
            IRmsServer * This);
        
        HRESULT ( STDMETHODCALLTYPE *ScanForDrives )( 
            IRmsServer * This);
        
        HRESULT ( STDMETHODCALLTYPE *MountScratchCartridge )( 
            IRmsServer * This,
            /* [out] */ GUID *pCartId,
            /* [in] */ REFGUID fromMediaSet,
            /* [in] */ REFGUID prevSideId,
            /* [out][in] */ LONGLONG *pFreeSpace,
            /* [in] */ LONG blockingFactor,
            /* [string][in] */ BSTR displayName,
            /* [out][in] */ IRmsDrive **ppDrive,
            /* [out] */ IRmsCartridge **ppCartridge,
            /* [out] */ IDataMover **ppDataMover,
            /* [defaultvalue][in] */ DWORD options);
        
        HRESULT ( STDMETHODCALLTYPE *MountCartridge )( 
            IRmsServer * This,
            /* [in] */ REFGUID cartId,
            /* [out][in] */ IRmsDrive **ppDrive,
            /* [out] */ IRmsCartridge **ppCartridge,
            /* [out] */ IDataMover **ppDataMover,
            /* [defaultvalue][in] */ DWORD options,
            /* [defaultvalue][in] */ DWORD threadId);
        
        HRESULT ( STDMETHODCALLTYPE *DismountCartridge )( 
            IRmsServer * This,
            /* [in] */ REFGUID cartId,
            /* [defaultvalue][in] */ DWORD options);
        
        HRESULT ( STDMETHODCALLTYPE *DuplicateCartridge )( 
            IRmsServer * This,
            /* [in] */ REFGUID cartId,
            /* [in] */ REFGUID firstSideId,
            /* [out][in] */ GUID *pCopyCartId,
            /* [in] */ REFGUID copySet,
            /* [string][in] */ BSTR copyName,
            /* [out] */ LONGLONG *pFreeSpace,
            /* [out] */ LONGLONG *pCapacity,
            /* [in] */ DWORD options);
        
        HRESULT ( STDMETHODCALLTYPE *RecycleCartridge )( 
            IRmsServer * This,
            /* [in] */ REFGUID cartId,
            /* [in] */ DWORD options);
        
        HRESULT ( STDMETHODCALLTYPE *FindLibraryById )( 
            IRmsServer * This,
            /* [in] */ REFGUID libId,
            /* [out] */ IRmsLibrary **ptr);
        
        HRESULT ( STDMETHODCALLTYPE *FindCartridgeById )( 
            IRmsServer * This,
            /* [in] */ REFGUID cartId,
            /* [out] */ IRmsCartridge **ptr);
        
        HRESULT ( STDMETHODCALLTYPE *CreateObject )( 
            IRmsServer * This,
            /* [in] */ REFGUID objectId,
            /* [in] */ REFCLSID rclsid,
            /* [in] */ REFIID riid,
            /* [in] */ DWORD dwCreate,
            /* [iid_is][out] */ void **ppvObj);
        
        HRESULT ( STDMETHODCALLTYPE *GetNofAvailableDrives )( 
            IRmsServer * This,
            /* [in] */ REFGUID fromMediaSet,
            /* [out] */ DWORD *pdwNofDrives);
        
        HRESULT ( STDMETHODCALLTYPE *FindCartridgeStatusById )( 
            IRmsServer * This,
            /* [in] */ REFGUID cartId,
            /* [out] */ DWORD *pdwStatus);
        
        HRESULT ( STDMETHODCALLTYPE *IsMultipleSidedMedia )( 
            IRmsServer * This,
            /* [in] */ REFGUID mediaSetId);
        
        HRESULT ( STDMETHODCALLTYPE *CheckSecondSide )( 
            IRmsServer * This,
            /* [in] */ REFGUID firstSideId,
            /* [out] */ BOOL *pbValid,
            /* [out] */ GUID *pSecondSideId);
        
        HRESULT ( STDMETHODCALLTYPE *GetMaxMediaCapacity )( 
            IRmsServer * This,
            /* [in] */ REFGUID fromMediaSet,
            /* [out] */ LONGLONG *pMaxCapacity);
        
        END_INTERFACE
    } IRmsServerVtbl;

    interface IRmsServer
    {
        CONST_VTBL struct IRmsServerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRmsServer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRmsServer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRmsServer_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRmsServer_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRmsServer_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRmsServer_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRmsServer_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRmsServer_IsReady(This)	\
    (This)->lpVtbl -> IsReady(This)

#define IRmsServer_ChangeState(This,newState)	\
    (This)->lpVtbl -> ChangeState(This,newState)

#define IRmsServer_IsNTMSInstalled(This)	\
    (This)->lpVtbl -> IsNTMSInstalled(This)

#define IRmsServer_GetNTMS(This,ptr)	\
    (This)->lpVtbl -> GetNTMS(This,ptr)

#define IRmsServer_InitializeInAnotherThread(This)	\
    (This)->lpVtbl -> InitializeInAnotherThread(This)

#define IRmsServer_Initialize(This)	\
    (This)->lpVtbl -> Initialize(This)

#define IRmsServer_SaveAll(This)	\
    (This)->lpVtbl -> SaveAll(This)

#define IRmsServer_GetServerName(This,pName)	\
    (This)->lpVtbl -> GetServerName(This,pName)

#define IRmsServer_GetCartridges(This,ptr)	\
    (This)->lpVtbl -> GetCartridges(This,ptr)

#define IRmsServer_GetActiveCartridges(This,ptr)	\
    (This)->lpVtbl -> GetActiveCartridges(This,ptr)

#define IRmsServer_GetDataMovers(This,ptr)	\
    (This)->lpVtbl -> GetDataMovers(This,ptr)

#define IRmsServer_SetActiveCartridge(This,ptr)	\
    (This)->lpVtbl -> SetActiveCartridge(This,ptr)

#define IRmsServer_GetLibraries(This,ptr)	\
    (This)->lpVtbl -> GetLibraries(This,ptr)

#define IRmsServer_GetMediaSets(This,ptr)	\
    (This)->lpVtbl -> GetMediaSets(This,ptr)

#define IRmsServer_GetRequests(This,ptr)	\
    (This)->lpVtbl -> GetRequests(This,ptr)

#define IRmsServer_GetClients(This,ptr)	\
    (This)->lpVtbl -> GetClients(This,ptr)

#define IRmsServer_GetUnconfiguredDevices(This,ptr)	\
    (This)->lpVtbl -> GetUnconfiguredDevices(This,ptr)

#define IRmsServer_ScanForDevices(This)	\
    (This)->lpVtbl -> ScanForDevices(This)

#define IRmsServer_ScanForDrives(This)	\
    (This)->lpVtbl -> ScanForDrives(This)

#define IRmsServer_MountScratchCartridge(This,pCartId,fromMediaSet,prevSideId,pFreeSpace,blockingFactor,displayName,ppDrive,ppCartridge,ppDataMover,options)	\
    (This)->lpVtbl -> MountScratchCartridge(This,pCartId,fromMediaSet,prevSideId,pFreeSpace,blockingFactor,displayName,ppDrive,ppCartridge,ppDataMover,options)

#define IRmsServer_MountCartridge(This,cartId,ppDrive,ppCartridge,ppDataMover,options,threadId)	\
    (This)->lpVtbl -> MountCartridge(This,cartId,ppDrive,ppCartridge,ppDataMover,options,threadId)

#define IRmsServer_DismountCartridge(This,cartId,options)	\
    (This)->lpVtbl -> DismountCartridge(This,cartId,options)

#define IRmsServer_DuplicateCartridge(This,cartId,firstSideId,pCopyCartId,copySet,copyName,pFreeSpace,pCapacity,options)	\
    (This)->lpVtbl -> DuplicateCartridge(This,cartId,firstSideId,pCopyCartId,copySet,copyName,pFreeSpace,pCapacity,options)

#define IRmsServer_RecycleCartridge(This,cartId,options)	\
    (This)->lpVtbl -> RecycleCartridge(This,cartId,options)

#define IRmsServer_FindLibraryById(This,libId,ptr)	\
    (This)->lpVtbl -> FindLibraryById(This,libId,ptr)

#define IRmsServer_FindCartridgeById(This,cartId,ptr)	\
    (This)->lpVtbl -> FindCartridgeById(This,cartId,ptr)

#define IRmsServer_CreateObject(This,objectId,rclsid,riid,dwCreate,ppvObj)	\
    (This)->lpVtbl -> CreateObject(This,objectId,rclsid,riid,dwCreate,ppvObj)

#define IRmsServer_GetNofAvailableDrives(This,fromMediaSet,pdwNofDrives)	\
    (This)->lpVtbl -> GetNofAvailableDrives(This,fromMediaSet,pdwNofDrives)

#define IRmsServer_FindCartridgeStatusById(This,cartId,pdwStatus)	\
    (This)->lpVtbl -> FindCartridgeStatusById(This,cartId,pdwStatus)

#define IRmsServer_IsMultipleSidedMedia(This,mediaSetId)	\
    (This)->lpVtbl -> IsMultipleSidedMedia(This,mediaSetId)

#define IRmsServer_CheckSecondSide(This,firstSideId,pbValid,pSecondSideId)	\
    (This)->lpVtbl -> CheckSecondSide(This,firstSideId,pbValid,pSecondSideId)

#define IRmsServer_GetMaxMediaCapacity(This,fromMediaSet,pMaxCapacity)	\
    (This)->lpVtbl -> GetMaxMediaCapacity(This,fromMediaSet,pMaxCapacity)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRmsServer_IsReady_Proxy( 
    IRmsServer * This);


void __RPC_STUB IRmsServer_IsReady_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsServer_ChangeState_Proxy( 
    IRmsServer * This,
    /* [in] */ LONG newState);


void __RPC_STUB IRmsServer_ChangeState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsServer_IsNTMSInstalled_Proxy( 
    IRmsServer * This);


void __RPC_STUB IRmsServer_IsNTMSInstalled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsServer_GetNTMS_Proxy( 
    IRmsServer * This,
    /* [out] */ IRmsNTMS **ptr);


void __RPC_STUB IRmsServer_GetNTMS_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsServer_InitializeInAnotherThread_Proxy( 
    IRmsServer * This);


void __RPC_STUB IRmsServer_InitializeInAnotherThread_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsServer_Initialize_Proxy( 
    IRmsServer * This);


void __RPC_STUB IRmsServer_Initialize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsServer_SaveAll_Proxy( 
    IRmsServer * This);


void __RPC_STUB IRmsServer_SaveAll_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsServer_GetServerName_Proxy( 
    IRmsServer * This,
    /* [string][out][in] */ BSTR *pName);


void __RPC_STUB IRmsServer_GetServerName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsServer_GetCartridges_Proxy( 
    IRmsServer * This,
    /* [out] */ IWsbIndexedCollection **ptr);


void __RPC_STUB IRmsServer_GetCartridges_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsServer_GetActiveCartridges_Proxy( 
    IRmsServer * This,
    /* [out] */ IWsbIndexedCollection **ptr);


void __RPC_STUB IRmsServer_GetActiveCartridges_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsServer_GetDataMovers_Proxy( 
    IRmsServer * This,
    /* [out] */ IWsbIndexedCollection **ptr);


void __RPC_STUB IRmsServer_GetDataMovers_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsServer_SetActiveCartridge_Proxy( 
    IRmsServer * This,
    /* [in] */ IRmsCartridge *ptr);


void __RPC_STUB IRmsServer_SetActiveCartridge_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsServer_GetLibraries_Proxy( 
    IRmsServer * This,
    /* [out] */ IWsbIndexedCollection **ptr);


void __RPC_STUB IRmsServer_GetLibraries_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsServer_GetMediaSets_Proxy( 
    IRmsServer * This,
    /* [out] */ IWsbIndexedCollection **ptr);


void __RPC_STUB IRmsServer_GetMediaSets_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsServer_GetRequests_Proxy( 
    IRmsServer * This,
    /* [out] */ IWsbIndexedCollection **ptr);


void __RPC_STUB IRmsServer_GetRequests_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsServer_GetClients_Proxy( 
    IRmsServer * This,
    /* [out] */ IWsbIndexedCollection **ptr);


void __RPC_STUB IRmsServer_GetClients_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsServer_GetUnconfiguredDevices_Proxy( 
    IRmsServer * This,
    /* [out] */ IWsbIndexedCollection **ptr);


void __RPC_STUB IRmsServer_GetUnconfiguredDevices_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsServer_ScanForDevices_Proxy( 
    IRmsServer * This);


void __RPC_STUB IRmsServer_ScanForDevices_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsServer_ScanForDrives_Proxy( 
    IRmsServer * This);


void __RPC_STUB IRmsServer_ScanForDrives_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsServer_MountScratchCartridge_Proxy( 
    IRmsServer * This,
    /* [out] */ GUID *pCartId,
    /* [in] */ REFGUID fromMediaSet,
    /* [in] */ REFGUID prevSideId,
    /* [out][in] */ LONGLONG *pFreeSpace,
    /* [in] */ LONG blockingFactor,
    /* [string][in] */ BSTR displayName,
    /* [out][in] */ IRmsDrive **ppDrive,
    /* [out] */ IRmsCartridge **ppCartridge,
    /* [out] */ IDataMover **ppDataMover,
    /* [defaultvalue][in] */ DWORD options);


void __RPC_STUB IRmsServer_MountScratchCartridge_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsServer_MountCartridge_Proxy( 
    IRmsServer * This,
    /* [in] */ REFGUID cartId,
    /* [out][in] */ IRmsDrive **ppDrive,
    /* [out] */ IRmsCartridge **ppCartridge,
    /* [out] */ IDataMover **ppDataMover,
    /* [defaultvalue][in] */ DWORD options,
    /* [defaultvalue][in] */ DWORD threadId);


void __RPC_STUB IRmsServer_MountCartridge_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsServer_DismountCartridge_Proxy( 
    IRmsServer * This,
    /* [in] */ REFGUID cartId,
    /* [defaultvalue][in] */ DWORD options);


void __RPC_STUB IRmsServer_DismountCartridge_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsServer_DuplicateCartridge_Proxy( 
    IRmsServer * This,
    /* [in] */ REFGUID cartId,
    /* [in] */ REFGUID firstSideId,
    /* [out][in] */ GUID *pCopyCartId,
    /* [in] */ REFGUID copySet,
    /* [string][in] */ BSTR copyName,
    /* [out] */ LONGLONG *pFreeSpace,
    /* [out] */ LONGLONG *pCapacity,
    /* [in] */ DWORD options);


void __RPC_STUB IRmsServer_DuplicateCartridge_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsServer_RecycleCartridge_Proxy( 
    IRmsServer * This,
    /* [in] */ REFGUID cartId,
    /* [in] */ DWORD options);


void __RPC_STUB IRmsServer_RecycleCartridge_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsServer_FindLibraryById_Proxy( 
    IRmsServer * This,
    /* [in] */ REFGUID libId,
    /* [out] */ IRmsLibrary **ptr);


void __RPC_STUB IRmsServer_FindLibraryById_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsServer_FindCartridgeById_Proxy( 
    IRmsServer * This,
    /* [in] */ REFGUID cartId,
    /* [out] */ IRmsCartridge **ptr);


void __RPC_STUB IRmsServer_FindCartridgeById_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsServer_CreateObject_Proxy( 
    IRmsServer * This,
    /* [in] */ REFGUID objectId,
    /* [in] */ REFCLSID rclsid,
    /* [in] */ REFIID riid,
    /* [in] */ DWORD dwCreate,
    /* [iid_is][out] */ void **ppvObj);


void __RPC_STUB IRmsServer_CreateObject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsServer_GetNofAvailableDrives_Proxy( 
    IRmsServer * This,
    /* [in] */ REFGUID fromMediaSet,
    /* [out] */ DWORD *pdwNofDrives);


void __RPC_STUB IRmsServer_GetNofAvailableDrives_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsServer_FindCartridgeStatusById_Proxy( 
    IRmsServer * This,
    /* [in] */ REFGUID cartId,
    /* [out] */ DWORD *pdwStatus);


void __RPC_STUB IRmsServer_FindCartridgeStatusById_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsServer_IsMultipleSidedMedia_Proxy( 
    IRmsServer * This,
    /* [in] */ REFGUID mediaSetId);


void __RPC_STUB IRmsServer_IsMultipleSidedMedia_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsServer_CheckSecondSide_Proxy( 
    IRmsServer * This,
    /* [in] */ REFGUID firstSideId,
    /* [out] */ BOOL *pbValid,
    /* [out] */ GUID *pSecondSideId);


void __RPC_STUB IRmsServer_CheckSecondSide_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsServer_GetMaxMediaCapacity_Proxy( 
    IRmsServer * This,
    /* [in] */ REFGUID fromMediaSet,
    /* [out] */ LONGLONG *pMaxCapacity);


void __RPC_STUB IRmsServer_GetMaxMediaCapacity_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRmsServer_INTERFACE_DEFINED__ */


#ifndef __IRmsLibrary_INTERFACE_DEFINED__
#define __IRmsLibrary_INTERFACE_DEFINED__

/* interface IRmsLibrary */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRmsLibrary;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FE37FB02-3729-11D0-8CF4-00A0C9190459")
    IRmsLibrary : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetLibraryId( 
            /* [out] */ GUID *pLibId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetLibraryId( 
            /* [in] */ GUID libId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetName( 
            /* [string][out][in] */ BSTR *pName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetName( 
            /* [string][in] */ BSTR name) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMediaSupported( 
            /* [out] */ LONG *pType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMediaSupported( 
            /* [in] */ LONG type) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMaxChangers( 
            /* [out] */ LONG *pNum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMaxChangers( 
            /* [in] */ LONG num) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMaxDrives( 
            /* [out] */ LONG *pNum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMaxDrives( 
            /* [in] */ LONG num) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMaxPorts( 
            /* [out] */ LONG *pNum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMaxPorts( 
            /* [in] */ LONG num) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMaxSlots( 
            /* [out] */ LONG *pNum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMaxSlots( 
            /* [in] */ LONG num) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNumUsedSlots( 
            /* [out] */ LONG *pNum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNumStagingSlots( 
            /* [out] */ LONG *pNum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetNumStagingSlots( 
            /* [in] */ LONG num) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNumScratchCarts( 
            /* [out] */ LONG *pNum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetNumScratchCarts( 
            /* [in] */ LONG num) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNumUnknownCarts( 
            /* [out] */ LONG *pNum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetNumUnknownCarts( 
            /* [in] */ LONG num) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsMagazineSupported( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetIsMagazineSupported( 
            /* [in] */ BOOL flag) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMaxCleaningMounts( 
            /* [out] */ LONG *pNum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMaxCleaningMounts( 
            /* [in] */ LONG num) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSlotSelectionPolicy( 
            /* [out] */ LONG *pNum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSlotSelectionPolicy( 
            /* [in] */ LONG num) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetChangers( 
            /* [out] */ IWsbIndexedCollection **ptr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDriveClasses( 
            /* [out] */ IWsbIndexedCollection **ptr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDrives( 
            /* [out] */ IWsbIndexedCollection **ptr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStorageSlots( 
            /* [out] */ IWsbIndexedCollection **ptr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStagingSlots( 
            /* [out] */ IWsbIndexedCollection **ptr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPorts( 
            /* [out] */ IWsbIndexedCollection **ptr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCleaningCartridges( 
            /* [out] */ IWsbIndexedCollection **ptr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetScratchCartridges( 
            /* [out] */ IWsbIndexedCollection **ptr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMediaSets( 
            /* [out] */ IWsbIndexedCollection **ptr) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRmsLibraryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRmsLibrary * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRmsLibrary * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRmsLibrary * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IRmsLibrary * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IRmsLibrary * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IRmsLibrary * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRmsLibrary * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *GetLibraryId )( 
            IRmsLibrary * This,
            /* [out] */ GUID *pLibId);
        
        HRESULT ( STDMETHODCALLTYPE *SetLibraryId )( 
            IRmsLibrary * This,
            /* [in] */ GUID libId);
        
        HRESULT ( STDMETHODCALLTYPE *GetName )( 
            IRmsLibrary * This,
            /* [string][out][in] */ BSTR *pName);
        
        HRESULT ( STDMETHODCALLTYPE *SetName )( 
            IRmsLibrary * This,
            /* [string][in] */ BSTR name);
        
        HRESULT ( STDMETHODCALLTYPE *GetMediaSupported )( 
            IRmsLibrary * This,
            /* [out] */ LONG *pType);
        
        HRESULT ( STDMETHODCALLTYPE *SetMediaSupported )( 
            IRmsLibrary * This,
            /* [in] */ LONG type);
        
        HRESULT ( STDMETHODCALLTYPE *GetMaxChangers )( 
            IRmsLibrary * This,
            /* [out] */ LONG *pNum);
        
        HRESULT ( STDMETHODCALLTYPE *SetMaxChangers )( 
            IRmsLibrary * This,
            /* [in] */ LONG num);
        
        HRESULT ( STDMETHODCALLTYPE *GetMaxDrives )( 
            IRmsLibrary * This,
            /* [out] */ LONG *pNum);
        
        HRESULT ( STDMETHODCALLTYPE *SetMaxDrives )( 
            IRmsLibrary * This,
            /* [in] */ LONG num);
        
        HRESULT ( STDMETHODCALLTYPE *GetMaxPorts )( 
            IRmsLibrary * This,
            /* [out] */ LONG *pNum);
        
        HRESULT ( STDMETHODCALLTYPE *SetMaxPorts )( 
            IRmsLibrary * This,
            /* [in] */ LONG num);
        
        HRESULT ( STDMETHODCALLTYPE *GetMaxSlots )( 
            IRmsLibrary * This,
            /* [out] */ LONG *pNum);
        
        HRESULT ( STDMETHODCALLTYPE *SetMaxSlots )( 
            IRmsLibrary * This,
            /* [in] */ LONG num);
        
        HRESULT ( STDMETHODCALLTYPE *GetNumUsedSlots )( 
            IRmsLibrary * This,
            /* [out] */ LONG *pNum);
        
        HRESULT ( STDMETHODCALLTYPE *GetNumStagingSlots )( 
            IRmsLibrary * This,
            /* [out] */ LONG *pNum);
        
        HRESULT ( STDMETHODCALLTYPE *SetNumStagingSlots )( 
            IRmsLibrary * This,
            /* [in] */ LONG num);
        
        HRESULT ( STDMETHODCALLTYPE *GetNumScratchCarts )( 
            IRmsLibrary * This,
            /* [out] */ LONG *pNum);
        
        HRESULT ( STDMETHODCALLTYPE *SetNumScratchCarts )( 
            IRmsLibrary * This,
            /* [in] */ LONG num);
        
        HRESULT ( STDMETHODCALLTYPE *GetNumUnknownCarts )( 
            IRmsLibrary * This,
            /* [out] */ LONG *pNum);
        
        HRESULT ( STDMETHODCALLTYPE *SetNumUnknownCarts )( 
            IRmsLibrary * This,
            /* [in] */ LONG num);
        
        HRESULT ( STDMETHODCALLTYPE *IsMagazineSupported )( 
            IRmsLibrary * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetIsMagazineSupported )( 
            IRmsLibrary * This,
            /* [in] */ BOOL flag);
        
        HRESULT ( STDMETHODCALLTYPE *GetMaxCleaningMounts )( 
            IRmsLibrary * This,
            /* [out] */ LONG *pNum);
        
        HRESULT ( STDMETHODCALLTYPE *SetMaxCleaningMounts )( 
            IRmsLibrary * This,
            /* [in] */ LONG num);
        
        HRESULT ( STDMETHODCALLTYPE *GetSlotSelectionPolicy )( 
            IRmsLibrary * This,
            /* [out] */ LONG *pNum);
        
        HRESULT ( STDMETHODCALLTYPE *SetSlotSelectionPolicy )( 
            IRmsLibrary * This,
            /* [in] */ LONG num);
        
        HRESULT ( STDMETHODCALLTYPE *GetChangers )( 
            IRmsLibrary * This,
            /* [out] */ IWsbIndexedCollection **ptr);
        
        HRESULT ( STDMETHODCALLTYPE *GetDriveClasses )( 
            IRmsLibrary * This,
            /* [out] */ IWsbIndexedCollection **ptr);
        
        HRESULT ( STDMETHODCALLTYPE *GetDrives )( 
            IRmsLibrary * This,
            /* [out] */ IWsbIndexedCollection **ptr);
        
        HRESULT ( STDMETHODCALLTYPE *GetStorageSlots )( 
            IRmsLibrary * This,
            /* [out] */ IWsbIndexedCollection **ptr);
        
        HRESULT ( STDMETHODCALLTYPE *GetStagingSlots )( 
            IRmsLibrary * This,
            /* [out] */ IWsbIndexedCollection **ptr);
        
        HRESULT ( STDMETHODCALLTYPE *GetPorts )( 
            IRmsLibrary * This,
            /* [out] */ IWsbIndexedCollection **ptr);
        
        HRESULT ( STDMETHODCALLTYPE *GetCleaningCartridges )( 
            IRmsLibrary * This,
            /* [out] */ IWsbIndexedCollection **ptr);
        
        HRESULT ( STDMETHODCALLTYPE *GetScratchCartridges )( 
            IRmsLibrary * This,
            /* [out] */ IWsbIndexedCollection **ptr);
        
        HRESULT ( STDMETHODCALLTYPE *GetMediaSets )( 
            IRmsLibrary * This,
            /* [out] */ IWsbIndexedCollection **ptr);
        
        END_INTERFACE
    } IRmsLibraryVtbl;

    interface IRmsLibrary
    {
        CONST_VTBL struct IRmsLibraryVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRmsLibrary_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRmsLibrary_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRmsLibrary_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRmsLibrary_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRmsLibrary_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRmsLibrary_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRmsLibrary_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRmsLibrary_GetLibraryId(This,pLibId)	\
    (This)->lpVtbl -> GetLibraryId(This,pLibId)

#define IRmsLibrary_SetLibraryId(This,libId)	\
    (This)->lpVtbl -> SetLibraryId(This,libId)

#define IRmsLibrary_GetName(This,pName)	\
    (This)->lpVtbl -> GetName(This,pName)

#define IRmsLibrary_SetName(This,name)	\
    (This)->lpVtbl -> SetName(This,name)

#define IRmsLibrary_GetMediaSupported(This,pType)	\
    (This)->lpVtbl -> GetMediaSupported(This,pType)

#define IRmsLibrary_SetMediaSupported(This,type)	\
    (This)->lpVtbl -> SetMediaSupported(This,type)

#define IRmsLibrary_GetMaxChangers(This,pNum)	\
    (This)->lpVtbl -> GetMaxChangers(This,pNum)

#define IRmsLibrary_SetMaxChangers(This,num)	\
    (This)->lpVtbl -> SetMaxChangers(This,num)

#define IRmsLibrary_GetMaxDrives(This,pNum)	\
    (This)->lpVtbl -> GetMaxDrives(This,pNum)

#define IRmsLibrary_SetMaxDrives(This,num)	\
    (This)->lpVtbl -> SetMaxDrives(This,num)

#define IRmsLibrary_GetMaxPorts(This,pNum)	\
    (This)->lpVtbl -> GetMaxPorts(This,pNum)

#define IRmsLibrary_SetMaxPorts(This,num)	\
    (This)->lpVtbl -> SetMaxPorts(This,num)

#define IRmsLibrary_GetMaxSlots(This,pNum)	\
    (This)->lpVtbl -> GetMaxSlots(This,pNum)

#define IRmsLibrary_SetMaxSlots(This,num)	\
    (This)->lpVtbl -> SetMaxSlots(This,num)

#define IRmsLibrary_GetNumUsedSlots(This,pNum)	\
    (This)->lpVtbl -> GetNumUsedSlots(This,pNum)

#define IRmsLibrary_GetNumStagingSlots(This,pNum)	\
    (This)->lpVtbl -> GetNumStagingSlots(This,pNum)

#define IRmsLibrary_SetNumStagingSlots(This,num)	\
    (This)->lpVtbl -> SetNumStagingSlots(This,num)

#define IRmsLibrary_GetNumScratchCarts(This,pNum)	\
    (This)->lpVtbl -> GetNumScratchCarts(This,pNum)

#define IRmsLibrary_SetNumScratchCarts(This,num)	\
    (This)->lpVtbl -> SetNumScratchCarts(This,num)

#define IRmsLibrary_GetNumUnknownCarts(This,pNum)	\
    (This)->lpVtbl -> GetNumUnknownCarts(This,pNum)

#define IRmsLibrary_SetNumUnknownCarts(This,num)	\
    (This)->lpVtbl -> SetNumUnknownCarts(This,num)

#define IRmsLibrary_IsMagazineSupported(This)	\
    (This)->lpVtbl -> IsMagazineSupported(This)

#define IRmsLibrary_SetIsMagazineSupported(This,flag)	\
    (This)->lpVtbl -> SetIsMagazineSupported(This,flag)

#define IRmsLibrary_GetMaxCleaningMounts(This,pNum)	\
    (This)->lpVtbl -> GetMaxCleaningMounts(This,pNum)

#define IRmsLibrary_SetMaxCleaningMounts(This,num)	\
    (This)->lpVtbl -> SetMaxCleaningMounts(This,num)

#define IRmsLibrary_GetSlotSelectionPolicy(This,pNum)	\
    (This)->lpVtbl -> GetSlotSelectionPolicy(This,pNum)

#define IRmsLibrary_SetSlotSelectionPolicy(This,num)	\
    (This)->lpVtbl -> SetSlotSelectionPolicy(This,num)

#define IRmsLibrary_GetChangers(This,ptr)	\
    (This)->lpVtbl -> GetChangers(This,ptr)

#define IRmsLibrary_GetDriveClasses(This,ptr)	\
    (This)->lpVtbl -> GetDriveClasses(This,ptr)

#define IRmsLibrary_GetDrives(This,ptr)	\
    (This)->lpVtbl -> GetDrives(This,ptr)

#define IRmsLibrary_GetStorageSlots(This,ptr)	\
    (This)->lpVtbl -> GetStorageSlots(This,ptr)

#define IRmsLibrary_GetStagingSlots(This,ptr)	\
    (This)->lpVtbl -> GetStagingSlots(This,ptr)

#define IRmsLibrary_GetPorts(This,ptr)	\
    (This)->lpVtbl -> GetPorts(This,ptr)

#define IRmsLibrary_GetCleaningCartridges(This,ptr)	\
    (This)->lpVtbl -> GetCleaningCartridges(This,ptr)

#define IRmsLibrary_GetScratchCartridges(This,ptr)	\
    (This)->lpVtbl -> GetScratchCartridges(This,ptr)

#define IRmsLibrary_GetMediaSets(This,ptr)	\
    (This)->lpVtbl -> GetMediaSets(This,ptr)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRmsLibrary_GetLibraryId_Proxy( 
    IRmsLibrary * This,
    /* [out] */ GUID *pLibId);


void __RPC_STUB IRmsLibrary_GetLibraryId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsLibrary_SetLibraryId_Proxy( 
    IRmsLibrary * This,
    /* [in] */ GUID libId);


void __RPC_STUB IRmsLibrary_SetLibraryId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsLibrary_GetName_Proxy( 
    IRmsLibrary * This,
    /* [string][out][in] */ BSTR *pName);


void __RPC_STUB IRmsLibrary_GetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsLibrary_SetName_Proxy( 
    IRmsLibrary * This,
    /* [string][in] */ BSTR name);


void __RPC_STUB IRmsLibrary_SetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsLibrary_GetMediaSupported_Proxy( 
    IRmsLibrary * This,
    /* [out] */ LONG *pType);


void __RPC_STUB IRmsLibrary_GetMediaSupported_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsLibrary_SetMediaSupported_Proxy( 
    IRmsLibrary * This,
    /* [in] */ LONG type);


void __RPC_STUB IRmsLibrary_SetMediaSupported_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsLibrary_GetMaxChangers_Proxy( 
    IRmsLibrary * This,
    /* [out] */ LONG *pNum);


void __RPC_STUB IRmsLibrary_GetMaxChangers_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsLibrary_SetMaxChangers_Proxy( 
    IRmsLibrary * This,
    /* [in] */ LONG num);


void __RPC_STUB IRmsLibrary_SetMaxChangers_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsLibrary_GetMaxDrives_Proxy( 
    IRmsLibrary * This,
    /* [out] */ LONG *pNum);


void __RPC_STUB IRmsLibrary_GetMaxDrives_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsLibrary_SetMaxDrives_Proxy( 
    IRmsLibrary * This,
    /* [in] */ LONG num);


void __RPC_STUB IRmsLibrary_SetMaxDrives_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsLibrary_GetMaxPorts_Proxy( 
    IRmsLibrary * This,
    /* [out] */ LONG *pNum);


void __RPC_STUB IRmsLibrary_GetMaxPorts_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsLibrary_SetMaxPorts_Proxy( 
    IRmsLibrary * This,
    /* [in] */ LONG num);


void __RPC_STUB IRmsLibrary_SetMaxPorts_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsLibrary_GetMaxSlots_Proxy( 
    IRmsLibrary * This,
    /* [out] */ LONG *pNum);


void __RPC_STUB IRmsLibrary_GetMaxSlots_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsLibrary_SetMaxSlots_Proxy( 
    IRmsLibrary * This,
    /* [in] */ LONG num);


void __RPC_STUB IRmsLibrary_SetMaxSlots_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsLibrary_GetNumUsedSlots_Proxy( 
    IRmsLibrary * This,
    /* [out] */ LONG *pNum);


void __RPC_STUB IRmsLibrary_GetNumUsedSlots_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsLibrary_GetNumStagingSlots_Proxy( 
    IRmsLibrary * This,
    /* [out] */ LONG *pNum);


void __RPC_STUB IRmsLibrary_GetNumStagingSlots_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsLibrary_SetNumStagingSlots_Proxy( 
    IRmsLibrary * This,
    /* [in] */ LONG num);


void __RPC_STUB IRmsLibrary_SetNumStagingSlots_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsLibrary_GetNumScratchCarts_Proxy( 
    IRmsLibrary * This,
    /* [out] */ LONG *pNum);


void __RPC_STUB IRmsLibrary_GetNumScratchCarts_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsLibrary_SetNumScratchCarts_Proxy( 
    IRmsLibrary * This,
    /* [in] */ LONG num);


void __RPC_STUB IRmsLibrary_SetNumScratchCarts_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsLibrary_GetNumUnknownCarts_Proxy( 
    IRmsLibrary * This,
    /* [out] */ LONG *pNum);


void __RPC_STUB IRmsLibrary_GetNumUnknownCarts_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsLibrary_SetNumUnknownCarts_Proxy( 
    IRmsLibrary * This,
    /* [in] */ LONG num);


void __RPC_STUB IRmsLibrary_SetNumUnknownCarts_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsLibrary_IsMagazineSupported_Proxy( 
    IRmsLibrary * This);


void __RPC_STUB IRmsLibrary_IsMagazineSupported_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsLibrary_SetIsMagazineSupported_Proxy( 
    IRmsLibrary * This,
    /* [in] */ BOOL flag);


void __RPC_STUB IRmsLibrary_SetIsMagazineSupported_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsLibrary_GetMaxCleaningMounts_Proxy( 
    IRmsLibrary * This,
    /* [out] */ LONG *pNum);


void __RPC_STUB IRmsLibrary_GetMaxCleaningMounts_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsLibrary_SetMaxCleaningMounts_Proxy( 
    IRmsLibrary * This,
    /* [in] */ LONG num);


void __RPC_STUB IRmsLibrary_SetMaxCleaningMounts_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsLibrary_GetSlotSelectionPolicy_Proxy( 
    IRmsLibrary * This,
    /* [out] */ LONG *pNum);


void __RPC_STUB IRmsLibrary_GetSlotSelectionPolicy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsLibrary_SetSlotSelectionPolicy_Proxy( 
    IRmsLibrary * This,
    /* [in] */ LONG num);


void __RPC_STUB IRmsLibrary_SetSlotSelectionPolicy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsLibrary_GetChangers_Proxy( 
    IRmsLibrary * This,
    /* [out] */ IWsbIndexedCollection **ptr);


void __RPC_STUB IRmsLibrary_GetChangers_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsLibrary_GetDriveClasses_Proxy( 
    IRmsLibrary * This,
    /* [out] */ IWsbIndexedCollection **ptr);


void __RPC_STUB IRmsLibrary_GetDriveClasses_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsLibrary_GetDrives_Proxy( 
    IRmsLibrary * This,
    /* [out] */ IWsbIndexedCollection **ptr);


void __RPC_STUB IRmsLibrary_GetDrives_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsLibrary_GetStorageSlots_Proxy( 
    IRmsLibrary * This,
    /* [out] */ IWsbIndexedCollection **ptr);


void __RPC_STUB IRmsLibrary_GetStorageSlots_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsLibrary_GetStagingSlots_Proxy( 
    IRmsLibrary * This,
    /* [out] */ IWsbIndexedCollection **ptr);


void __RPC_STUB IRmsLibrary_GetStagingSlots_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsLibrary_GetPorts_Proxy( 
    IRmsLibrary * This,
    /* [out] */ IWsbIndexedCollection **ptr);


void __RPC_STUB IRmsLibrary_GetPorts_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsLibrary_GetCleaningCartridges_Proxy( 
    IRmsLibrary * This,
    /* [out] */ IWsbIndexedCollection **ptr);


void __RPC_STUB IRmsLibrary_GetCleaningCartridges_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsLibrary_GetScratchCartridges_Proxy( 
    IRmsLibrary * This,
    /* [out] */ IWsbIndexedCollection **ptr);


void __RPC_STUB IRmsLibrary_GetScratchCartridges_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsLibrary_GetMediaSets_Proxy( 
    IRmsLibrary * This,
    /* [out] */ IWsbIndexedCollection **ptr);


void __RPC_STUB IRmsLibrary_GetMediaSets_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRmsLibrary_INTERFACE_DEFINED__ */


#ifndef __IRmsDriveClass_INTERFACE_DEFINED__
#define __IRmsDriveClass_INTERFACE_DEFINED__

/* interface IRmsDriveClass */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRmsDriveClass;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FE37FB03-3729-11D0-8CF4-00A0C9190459")
    IRmsDriveClass : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetDriveClassId( 
            /* [out] */ GUID *pDriveClassId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetName( 
            /* [string][out][in] */ BSTR *pName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetName( 
            /* [string][in] */ BSTR name) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetType( 
            /* [out] */ LONG *pType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetType( 
            /* [in] */ LONG type) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCapability( 
            /* [out] */ LONG *pCapablity) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCapability( 
            /* [in] */ LONG capability) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIdleTime( 
            /* [out] */ LONG *pTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetIdleTime( 
            /* [in] */ LONG time) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMountWaitTime( 
            /* [out] */ LONG *pTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMountWaitTime( 
            /* [in] */ LONG time) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMountLimit( 
            /* [out] */ LONG *pLim) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMountLimit( 
            /* [in] */ LONG lim) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetQueuedRequests( 
            /* [out] */ LONG *pReqs) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetQueuedRequests( 
            /* [in] */ LONG reqs) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUnloadPauseTime( 
            /* [out] */ LONG *pTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetUnloadPauseTime( 
            /* [in] */ LONG time) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDriveSelectionPolicy( 
            /* [out] */ LONG *pPolicy) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDriveSelectionPolicy( 
            /* [in] */ LONG policy) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDrives( 
            /* [out] */ IWsbIndexedCollection **ptr) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRmsDriveClassVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRmsDriveClass * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRmsDriveClass * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRmsDriveClass * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IRmsDriveClass * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IRmsDriveClass * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IRmsDriveClass * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRmsDriveClass * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *GetDriveClassId )( 
            IRmsDriveClass * This,
            /* [out] */ GUID *pDriveClassId);
        
        HRESULT ( STDMETHODCALLTYPE *GetName )( 
            IRmsDriveClass * This,
            /* [string][out][in] */ BSTR *pName);
        
        HRESULT ( STDMETHODCALLTYPE *SetName )( 
            IRmsDriveClass * This,
            /* [string][in] */ BSTR name);
        
        HRESULT ( STDMETHODCALLTYPE *GetType )( 
            IRmsDriveClass * This,
            /* [out] */ LONG *pType);
        
        HRESULT ( STDMETHODCALLTYPE *SetType )( 
            IRmsDriveClass * This,
            /* [in] */ LONG type);
        
        HRESULT ( STDMETHODCALLTYPE *GetCapability )( 
            IRmsDriveClass * This,
            /* [out] */ LONG *pCapablity);
        
        HRESULT ( STDMETHODCALLTYPE *SetCapability )( 
            IRmsDriveClass * This,
            /* [in] */ LONG capability);
        
        HRESULT ( STDMETHODCALLTYPE *GetIdleTime )( 
            IRmsDriveClass * This,
            /* [out] */ LONG *pTime);
        
        HRESULT ( STDMETHODCALLTYPE *SetIdleTime )( 
            IRmsDriveClass * This,
            /* [in] */ LONG time);
        
        HRESULT ( STDMETHODCALLTYPE *GetMountWaitTime )( 
            IRmsDriveClass * This,
            /* [out] */ LONG *pTime);
        
        HRESULT ( STDMETHODCALLTYPE *SetMountWaitTime )( 
            IRmsDriveClass * This,
            /* [in] */ LONG time);
        
        HRESULT ( STDMETHODCALLTYPE *GetMountLimit )( 
            IRmsDriveClass * This,
            /* [out] */ LONG *pLim);
        
        HRESULT ( STDMETHODCALLTYPE *SetMountLimit )( 
            IRmsDriveClass * This,
            /* [in] */ LONG lim);
        
        HRESULT ( STDMETHODCALLTYPE *GetQueuedRequests )( 
            IRmsDriveClass * This,
            /* [out] */ LONG *pReqs);
        
        HRESULT ( STDMETHODCALLTYPE *SetQueuedRequests )( 
            IRmsDriveClass * This,
            /* [in] */ LONG reqs);
        
        HRESULT ( STDMETHODCALLTYPE *GetUnloadPauseTime )( 
            IRmsDriveClass * This,
            /* [out] */ LONG *pTime);
        
        HRESULT ( STDMETHODCALLTYPE *SetUnloadPauseTime )( 
            IRmsDriveClass * This,
            /* [in] */ LONG time);
        
        HRESULT ( STDMETHODCALLTYPE *GetDriveSelectionPolicy )( 
            IRmsDriveClass * This,
            /* [out] */ LONG *pPolicy);
        
        HRESULT ( STDMETHODCALLTYPE *SetDriveSelectionPolicy )( 
            IRmsDriveClass * This,
            /* [in] */ LONG policy);
        
        HRESULT ( STDMETHODCALLTYPE *GetDrives )( 
            IRmsDriveClass * This,
            /* [out] */ IWsbIndexedCollection **ptr);
        
        END_INTERFACE
    } IRmsDriveClassVtbl;

    interface IRmsDriveClass
    {
        CONST_VTBL struct IRmsDriveClassVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRmsDriveClass_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRmsDriveClass_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRmsDriveClass_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRmsDriveClass_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRmsDriveClass_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRmsDriveClass_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRmsDriveClass_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRmsDriveClass_GetDriveClassId(This,pDriveClassId)	\
    (This)->lpVtbl -> GetDriveClassId(This,pDriveClassId)

#define IRmsDriveClass_GetName(This,pName)	\
    (This)->lpVtbl -> GetName(This,pName)

#define IRmsDriveClass_SetName(This,name)	\
    (This)->lpVtbl -> SetName(This,name)

#define IRmsDriveClass_GetType(This,pType)	\
    (This)->lpVtbl -> GetType(This,pType)

#define IRmsDriveClass_SetType(This,type)	\
    (This)->lpVtbl -> SetType(This,type)

#define IRmsDriveClass_GetCapability(This,pCapablity)	\
    (This)->lpVtbl -> GetCapability(This,pCapablity)

#define IRmsDriveClass_SetCapability(This,capability)	\
    (This)->lpVtbl -> SetCapability(This,capability)

#define IRmsDriveClass_GetIdleTime(This,pTime)	\
    (This)->lpVtbl -> GetIdleTime(This,pTime)

#define IRmsDriveClass_SetIdleTime(This,time)	\
    (This)->lpVtbl -> SetIdleTime(This,time)

#define IRmsDriveClass_GetMountWaitTime(This,pTime)	\
    (This)->lpVtbl -> GetMountWaitTime(This,pTime)

#define IRmsDriveClass_SetMountWaitTime(This,time)	\
    (This)->lpVtbl -> SetMountWaitTime(This,time)

#define IRmsDriveClass_GetMountLimit(This,pLim)	\
    (This)->lpVtbl -> GetMountLimit(This,pLim)

#define IRmsDriveClass_SetMountLimit(This,lim)	\
    (This)->lpVtbl -> SetMountLimit(This,lim)

#define IRmsDriveClass_GetQueuedRequests(This,pReqs)	\
    (This)->lpVtbl -> GetQueuedRequests(This,pReqs)

#define IRmsDriveClass_SetQueuedRequests(This,reqs)	\
    (This)->lpVtbl -> SetQueuedRequests(This,reqs)

#define IRmsDriveClass_GetUnloadPauseTime(This,pTime)	\
    (This)->lpVtbl -> GetUnloadPauseTime(This,pTime)

#define IRmsDriveClass_SetUnloadPauseTime(This,time)	\
    (This)->lpVtbl -> SetUnloadPauseTime(This,time)

#define IRmsDriveClass_GetDriveSelectionPolicy(This,pPolicy)	\
    (This)->lpVtbl -> GetDriveSelectionPolicy(This,pPolicy)

#define IRmsDriveClass_SetDriveSelectionPolicy(This,policy)	\
    (This)->lpVtbl -> SetDriveSelectionPolicy(This,policy)

#define IRmsDriveClass_GetDrives(This,ptr)	\
    (This)->lpVtbl -> GetDrives(This,ptr)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRmsDriveClass_GetDriveClassId_Proxy( 
    IRmsDriveClass * This,
    /* [out] */ GUID *pDriveClassId);


void __RPC_STUB IRmsDriveClass_GetDriveClassId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsDriveClass_GetName_Proxy( 
    IRmsDriveClass * This,
    /* [string][out][in] */ BSTR *pName);


void __RPC_STUB IRmsDriveClass_GetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsDriveClass_SetName_Proxy( 
    IRmsDriveClass * This,
    /* [string][in] */ BSTR name);


void __RPC_STUB IRmsDriveClass_SetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsDriveClass_GetType_Proxy( 
    IRmsDriveClass * This,
    /* [out] */ LONG *pType);


void __RPC_STUB IRmsDriveClass_GetType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsDriveClass_SetType_Proxy( 
    IRmsDriveClass * This,
    /* [in] */ LONG type);


void __RPC_STUB IRmsDriveClass_SetType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsDriveClass_GetCapability_Proxy( 
    IRmsDriveClass * This,
    /* [out] */ LONG *pCapablity);


void __RPC_STUB IRmsDriveClass_GetCapability_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsDriveClass_SetCapability_Proxy( 
    IRmsDriveClass * This,
    /* [in] */ LONG capability);


void __RPC_STUB IRmsDriveClass_SetCapability_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsDriveClass_GetIdleTime_Proxy( 
    IRmsDriveClass * This,
    /* [out] */ LONG *pTime);


void __RPC_STUB IRmsDriveClass_GetIdleTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsDriveClass_SetIdleTime_Proxy( 
    IRmsDriveClass * This,
    /* [in] */ LONG time);


void __RPC_STUB IRmsDriveClass_SetIdleTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsDriveClass_GetMountWaitTime_Proxy( 
    IRmsDriveClass * This,
    /* [out] */ LONG *pTime);


void __RPC_STUB IRmsDriveClass_GetMountWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsDriveClass_SetMountWaitTime_Proxy( 
    IRmsDriveClass * This,
    /* [in] */ LONG time);


void __RPC_STUB IRmsDriveClass_SetMountWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsDriveClass_GetMountLimit_Proxy( 
    IRmsDriveClass * This,
    /* [out] */ LONG *pLim);


void __RPC_STUB IRmsDriveClass_GetMountLimit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsDriveClass_SetMountLimit_Proxy( 
    IRmsDriveClass * This,
    /* [in] */ LONG lim);


void __RPC_STUB IRmsDriveClass_SetMountLimit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsDriveClass_GetQueuedRequests_Proxy( 
    IRmsDriveClass * This,
    /* [out] */ LONG *pReqs);


void __RPC_STUB IRmsDriveClass_GetQueuedRequests_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsDriveClass_SetQueuedRequests_Proxy( 
    IRmsDriveClass * This,
    /* [in] */ LONG reqs);


void __RPC_STUB IRmsDriveClass_SetQueuedRequests_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsDriveClass_GetUnloadPauseTime_Proxy( 
    IRmsDriveClass * This,
    /* [out] */ LONG *pTime);


void __RPC_STUB IRmsDriveClass_GetUnloadPauseTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsDriveClass_SetUnloadPauseTime_Proxy( 
    IRmsDriveClass * This,
    /* [in] */ LONG time);


void __RPC_STUB IRmsDriveClass_SetUnloadPauseTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsDriveClass_GetDriveSelectionPolicy_Proxy( 
    IRmsDriveClass * This,
    /* [out] */ LONG *pPolicy);


void __RPC_STUB IRmsDriveClass_GetDriveSelectionPolicy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsDriveClass_SetDriveSelectionPolicy_Proxy( 
    IRmsDriveClass * This,
    /* [in] */ LONG policy);


void __RPC_STUB IRmsDriveClass_SetDriveSelectionPolicy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsDriveClass_GetDrives_Proxy( 
    IRmsDriveClass * This,
    /* [out] */ IWsbIndexedCollection **ptr);


void __RPC_STUB IRmsDriveClass_GetDrives_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRmsDriveClass_INTERFACE_DEFINED__ */


#ifndef __IRmsCartridge_INTERFACE_DEFINED__
#define __IRmsCartridge_INTERFACE_DEFINED__

/* interface IRmsCartridge */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRmsCartridge;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("534F26CB-4F8A-4FEE-8D7E-5C35A0A0CC38")
    IRmsCartridge : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetMediaSetId( 
            /* [out] */ GUID *pMediaSetId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMediaSetId( 
            /* [in] */ GUID mediaSetId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCartridgeId( 
            /* [in] */ GUID cartId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCartridgeId( 
            /* [out] */ GUID *pCartId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetName( 
            /* [string][out][in] */ BSTR *pName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetName( 
            /* [string][in] */ BSTR name) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDescription( 
            /* [string][out][in] */ BSTR *pDescription) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDescription( 
            /* [string][in] */ BSTR name) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTagAndNumber( 
            /* [string][out][in] */ BSTR *pTag,
            /* [out] */ LONG *pNumber) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetTagAndNumber( 
            /* [string][in] */ BSTR tag,
            /* [in] */ LONG number) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBarcode( 
            /* [string][out][in] */ BSTR *pBarcode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOnMediaIdentifier( 
            /* [size_is][out][in] */ BYTE *pIdentifier,
            /* [out][in] */ LONG *pSize,
            /* [out] */ LONG *pType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetOnMediaIdentifier( 
            /* [size_is][in] */ BYTE *pIdentifier,
            /* [in] */ LONG size,
            /* [in] */ LONG type) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOnMediaLabel( 
            /* [string][out][in] */ BSTR *pLabel) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetOnMediaLabel( 
            /* [string][in] */ BSTR label) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStatus( 
            /* [out] */ LONG *pStatus) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetStatus( 
            /* [in] */ LONG status) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetType( 
            /* [out] */ LONG *pType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetType( 
            /* [in] */ LONG type) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBlockSize( 
            /* [out] */ LONG *pBlockSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetBlockSize( 
            /* [in] */ LONG blockSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetIsTwoSided( 
            /* [in] */ BOOL flag) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsTwoSided( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetIsMounted( 
            /* [in] */ BOOL flag) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsMounted( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetIsAvailable( 
            /* [in] */ BOOL flag) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsAvailable( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetHome( 
            /* [out] */ LONG *pType,
            /* [out] */ GUID *pLibId,
            /* [out] */ GUID *pMediaSetId,
            /* [out] */ LONG *pPos,
            /* [out] */ LONG *pAlt1,
            /* [out] */ LONG *pAlt2,
            /* [out] */ LONG *pAlt3,
            /* [out] */ BOOL *pInvert) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetHome( 
            /* [in] */ LONG type,
            /* [in] */ GUID libId,
            /* [in] */ GUID mediaSetId,
            /* [in] */ LONG pos,
            /* [in] */ LONG alt1,
            /* [in] */ LONG alt2,
            /* [in] */ LONG alt3,
            /* [in] */ BOOL invert) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLocation( 
            /* [unique][out][in] */ LONG *pType,
            /* [unique][out][in] */ GUID *pLibId,
            /* [unique][out][in] */ GUID *pMediaSetId,
            /* [unique][out][in] */ LONG *pPos,
            /* [unique][out][in] */ LONG *pAlt1,
            /* [unique][out][in] */ LONG *pAlt2,
            /* [unique][out][in] */ LONG *pAlt3,
            /* [unique][out][in] */ BOOL *pInvert) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetLocation( 
            /* [in] */ LONG type,
            /* [in] */ GUID libId,
            /* [in] */ GUID mediaSetId,
            /* [in] */ LONG pos,
            /* [in] */ LONG alt1,
            /* [in] */ LONG alt2,
            /* [in] */ LONG alt3,
            /* [in] */ BOOL invert) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDrive( 
            /* [out] */ IRmsDrive **ptr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDrive( 
            /* [in] */ IRmsDrive *ptr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMailStop( 
            /* [string][out][in] */ BSTR *pMailStop) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMailStop( 
            /* [string][in] */ BSTR mailStop) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetInfo( 
            /* [size_is][out] */ UCHAR *pInfo,
            /* [out] */ SHORT *pSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetInfo( 
            /* [size_is][in] */ UCHAR *pInfo,
            /* [in] */ SHORT size) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOwnerClassId( 
            /* [out] */ CLSID *pClassId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetOwnerClassId( 
            /* [in] */ CLSID classId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPartitions( 
            /* [out] */ IWsbIndexedCollection **ptr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVerifierClass( 
            /* [out] */ CLSID *pClassId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetVerifierClass( 
            /* [in] */ CLSID classId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPortalClass( 
            /* [out] */ CLSID *pClassId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPortalClass( 
            /* [in] */ CLSID classId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Mount( 
            /* [out] */ IRmsDrive **ppDrive,
            /* [defaultvalue][in] */ DWORD options = 0,
            /* [defaultvalue][in] */ DWORD threadId = 0) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Dismount( 
            /* [defaultvalue][in] */ DWORD options = 0) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Home( 
            /* [defaultvalue][in] */ DWORD options = 0) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateDataMover( 
            /* [out] */ IDataMover **ptr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReleaseDataMover( 
            /* [in] */ IDataMover *ptr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadDataCache( 
            /* [size_is][out] */ BYTE *pCache,
            /* [out][in] */ ULONG *pSize,
            /* [out] */ ULONG *pUsed,
            /* [out] */ ULARGE_INTEGER *pStartPBA) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SaveDataCache( 
            /* [size_is][in] */ BYTE *pCache,
            /* [in] */ ULONG size,
            /* [in] */ ULONG used,
            /* [in] */ ULARGE_INTEGER startPBA) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetManagedBy( 
            /* [out] */ LONG *pManagedBy) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetManagedBy( 
            /* [in] */ LONG managedBy) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsFixedBlockSize( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRmsCartridgeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRmsCartridge * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRmsCartridge * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRmsCartridge * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IRmsCartridge * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IRmsCartridge * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IRmsCartridge * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRmsCartridge * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *GetMediaSetId )( 
            IRmsCartridge * This,
            /* [out] */ GUID *pMediaSetId);
        
        HRESULT ( STDMETHODCALLTYPE *SetMediaSetId )( 
            IRmsCartridge * This,
            /* [in] */ GUID mediaSetId);
        
        HRESULT ( STDMETHODCALLTYPE *SetCartridgeId )( 
            IRmsCartridge * This,
            /* [in] */ GUID cartId);
        
        HRESULT ( STDMETHODCALLTYPE *GetCartridgeId )( 
            IRmsCartridge * This,
            /* [out] */ GUID *pCartId);
        
        HRESULT ( STDMETHODCALLTYPE *GetName )( 
            IRmsCartridge * This,
            /* [string][out][in] */ BSTR *pName);
        
        HRESULT ( STDMETHODCALLTYPE *SetName )( 
            IRmsCartridge * This,
            /* [string][in] */ BSTR name);
        
        HRESULT ( STDMETHODCALLTYPE *GetDescription )( 
            IRmsCartridge * This,
            /* [string][out][in] */ BSTR *pDescription);
        
        HRESULT ( STDMETHODCALLTYPE *SetDescription )( 
            IRmsCartridge * This,
            /* [string][in] */ BSTR name);
        
        HRESULT ( STDMETHODCALLTYPE *GetTagAndNumber )( 
            IRmsCartridge * This,
            /* [string][out][in] */ BSTR *pTag,
            /* [out] */ LONG *pNumber);
        
        HRESULT ( STDMETHODCALLTYPE *SetTagAndNumber )( 
            IRmsCartridge * This,
            /* [string][in] */ BSTR tag,
            /* [in] */ LONG number);
        
        HRESULT ( STDMETHODCALLTYPE *GetBarcode )( 
            IRmsCartridge * This,
            /* [string][out][in] */ BSTR *pBarcode);
        
        HRESULT ( STDMETHODCALLTYPE *GetOnMediaIdentifier )( 
            IRmsCartridge * This,
            /* [size_is][out][in] */ BYTE *pIdentifier,
            /* [out][in] */ LONG *pSize,
            /* [out] */ LONG *pType);
        
        HRESULT ( STDMETHODCALLTYPE *SetOnMediaIdentifier )( 
            IRmsCartridge * This,
            /* [size_is][in] */ BYTE *pIdentifier,
            /* [in] */ LONG size,
            /* [in] */ LONG type);
        
        HRESULT ( STDMETHODCALLTYPE *GetOnMediaLabel )( 
            IRmsCartridge * This,
            /* [string][out][in] */ BSTR *pLabel);
        
        HRESULT ( STDMETHODCALLTYPE *SetOnMediaLabel )( 
            IRmsCartridge * This,
            /* [string][in] */ BSTR label);
        
        HRESULT ( STDMETHODCALLTYPE *GetStatus )( 
            IRmsCartridge * This,
            /* [out] */ LONG *pStatus);
        
        HRESULT ( STDMETHODCALLTYPE *SetStatus )( 
            IRmsCartridge * This,
            /* [in] */ LONG status);
        
        HRESULT ( STDMETHODCALLTYPE *GetType )( 
            IRmsCartridge * This,
            /* [out] */ LONG *pType);
        
        HRESULT ( STDMETHODCALLTYPE *SetType )( 
            IRmsCartridge * This,
            /* [in] */ LONG type);
        
        HRESULT ( STDMETHODCALLTYPE *GetBlockSize )( 
            IRmsCartridge * This,
            /* [out] */ LONG *pBlockSize);
        
        HRESULT ( STDMETHODCALLTYPE *SetBlockSize )( 
            IRmsCartridge * This,
            /* [in] */ LONG blockSize);
        
        HRESULT ( STDMETHODCALLTYPE *SetIsTwoSided )( 
            IRmsCartridge * This,
            /* [in] */ BOOL flag);
        
        HRESULT ( STDMETHODCALLTYPE *IsTwoSided )( 
            IRmsCartridge * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetIsMounted )( 
            IRmsCartridge * This,
            /* [in] */ BOOL flag);
        
        HRESULT ( STDMETHODCALLTYPE *IsMounted )( 
            IRmsCartridge * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetIsAvailable )( 
            IRmsCartridge * This,
            /* [in] */ BOOL flag);
        
        HRESULT ( STDMETHODCALLTYPE *IsAvailable )( 
            IRmsCartridge * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetHome )( 
            IRmsCartridge * This,
            /* [out] */ LONG *pType,
            /* [out] */ GUID *pLibId,
            /* [out] */ GUID *pMediaSetId,
            /* [out] */ LONG *pPos,
            /* [out] */ LONG *pAlt1,
            /* [out] */ LONG *pAlt2,
            /* [out] */ LONG *pAlt3,
            /* [out] */ BOOL *pInvert);
        
        HRESULT ( STDMETHODCALLTYPE *SetHome )( 
            IRmsCartridge * This,
            /* [in] */ LONG type,
            /* [in] */ GUID libId,
            /* [in] */ GUID mediaSetId,
            /* [in] */ LONG pos,
            /* [in] */ LONG alt1,
            /* [in] */ LONG alt2,
            /* [in] */ LONG alt3,
            /* [in] */ BOOL invert);
        
        HRESULT ( STDMETHODCALLTYPE *GetLocation )( 
            IRmsCartridge * This,
            /* [unique][out][in] */ LONG *pType,
            /* [unique][out][in] */ GUID *pLibId,
            /* [unique][out][in] */ GUID *pMediaSetId,
            /* [unique][out][in] */ LONG *pPos,
            /* [unique][out][in] */ LONG *pAlt1,
            /* [unique][out][in] */ LONG *pAlt2,
            /* [unique][out][in] */ LONG *pAlt3,
            /* [unique][out][in] */ BOOL *pInvert);
        
        HRESULT ( STDMETHODCALLTYPE *SetLocation )( 
            IRmsCartridge * This,
            /* [in] */ LONG type,
            /* [in] */ GUID libId,
            /* [in] */ GUID mediaSetId,
            /* [in] */ LONG pos,
            /* [in] */ LONG alt1,
            /* [in] */ LONG alt2,
            /* [in] */ LONG alt3,
            /* [in] */ BOOL invert);
        
        HRESULT ( STDMETHODCALLTYPE *GetDrive )( 
            IRmsCartridge * This,
            /* [out] */ IRmsDrive **ptr);
        
        HRESULT ( STDMETHODCALLTYPE *SetDrive )( 
            IRmsCartridge * This,
            /* [in] */ IRmsDrive *ptr);
        
        HRESULT ( STDMETHODCALLTYPE *GetMailStop )( 
            IRmsCartridge * This,
            /* [string][out][in] */ BSTR *pMailStop);
        
        HRESULT ( STDMETHODCALLTYPE *SetMailStop )( 
            IRmsCartridge * This,
            /* [string][in] */ BSTR mailStop);
        
        HRESULT ( STDMETHODCALLTYPE *GetInfo )( 
            IRmsCartridge * This,
            /* [size_is][out] */ UCHAR *pInfo,
            /* [out] */ SHORT *pSize);
        
        HRESULT ( STDMETHODCALLTYPE *SetInfo )( 
            IRmsCartridge * This,
            /* [size_is][in] */ UCHAR *pInfo,
            /* [in] */ SHORT size);
        
        HRESULT ( STDMETHODCALLTYPE *GetOwnerClassId )( 
            IRmsCartridge * This,
            /* [out] */ CLSID *pClassId);
        
        HRESULT ( STDMETHODCALLTYPE *SetOwnerClassId )( 
            IRmsCartridge * This,
            /* [in] */ CLSID classId);
        
        HRESULT ( STDMETHODCALLTYPE *GetPartitions )( 
            IRmsCartridge * This,
            /* [out] */ IWsbIndexedCollection **ptr);
        
        HRESULT ( STDMETHODCALLTYPE *GetVerifierClass )( 
            IRmsCartridge * This,
            /* [out] */ CLSID *pClassId);
        
        HRESULT ( STDMETHODCALLTYPE *SetVerifierClass )( 
            IRmsCartridge * This,
            /* [in] */ CLSID classId);
        
        HRESULT ( STDMETHODCALLTYPE *GetPortalClass )( 
            IRmsCartridge * This,
            /* [out] */ CLSID *pClassId);
        
        HRESULT ( STDMETHODCALLTYPE *SetPortalClass )( 
            IRmsCartridge * This,
            /* [in] */ CLSID classId);
        
        HRESULT ( STDMETHODCALLTYPE *Mount )( 
            IRmsCartridge * This,
            /* [out] */ IRmsDrive **ppDrive,
            /* [defaultvalue][in] */ DWORD options,
            /* [defaultvalue][in] */ DWORD threadId);
        
        HRESULT ( STDMETHODCALLTYPE *Dismount )( 
            IRmsCartridge * This,
            /* [defaultvalue][in] */ DWORD options);
        
        HRESULT ( STDMETHODCALLTYPE *Home )( 
            IRmsCartridge * This,
            /* [defaultvalue][in] */ DWORD options);
        
        HRESULT ( STDMETHODCALLTYPE *CreateDataMover )( 
            IRmsCartridge * This,
            /* [out] */ IDataMover **ptr);
        
        HRESULT ( STDMETHODCALLTYPE *ReleaseDataMover )( 
            IRmsCartridge * This,
            /* [in] */ IDataMover *ptr);
        
        HRESULT ( STDMETHODCALLTYPE *LoadDataCache )( 
            IRmsCartridge * This,
            /* [size_is][out] */ BYTE *pCache,
            /* [out][in] */ ULONG *pSize,
            /* [out] */ ULONG *pUsed,
            /* [out] */ ULARGE_INTEGER *pStartPBA);
        
        HRESULT ( STDMETHODCALLTYPE *SaveDataCache )( 
            IRmsCartridge * This,
            /* [size_is][in] */ BYTE *pCache,
            /* [in] */ ULONG size,
            /* [in] */ ULONG used,
            /* [in] */ ULARGE_INTEGER startPBA);
        
        HRESULT ( STDMETHODCALLTYPE *GetManagedBy )( 
            IRmsCartridge * This,
            /* [out] */ LONG *pManagedBy);
        
        HRESULT ( STDMETHODCALLTYPE *SetManagedBy )( 
            IRmsCartridge * This,
            /* [in] */ LONG managedBy);
        
        HRESULT ( STDMETHODCALLTYPE *IsFixedBlockSize )( 
            IRmsCartridge * This);
        
        END_INTERFACE
    } IRmsCartridgeVtbl;

    interface IRmsCartridge
    {
        CONST_VTBL struct IRmsCartridgeVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRmsCartridge_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRmsCartridge_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRmsCartridge_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRmsCartridge_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRmsCartridge_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRmsCartridge_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRmsCartridge_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRmsCartridge_GetMediaSetId(This,pMediaSetId)	\
    (This)->lpVtbl -> GetMediaSetId(This,pMediaSetId)

#define IRmsCartridge_SetMediaSetId(This,mediaSetId)	\
    (This)->lpVtbl -> SetMediaSetId(This,mediaSetId)

#define IRmsCartridge_SetCartridgeId(This,cartId)	\
    (This)->lpVtbl -> SetCartridgeId(This,cartId)

#define IRmsCartridge_GetCartridgeId(This,pCartId)	\
    (This)->lpVtbl -> GetCartridgeId(This,pCartId)

#define IRmsCartridge_GetName(This,pName)	\
    (This)->lpVtbl -> GetName(This,pName)

#define IRmsCartridge_SetName(This,name)	\
    (This)->lpVtbl -> SetName(This,name)

#define IRmsCartridge_GetDescription(This,pDescription)	\
    (This)->lpVtbl -> GetDescription(This,pDescription)

#define IRmsCartridge_SetDescription(This,name)	\
    (This)->lpVtbl -> SetDescription(This,name)

#define IRmsCartridge_GetTagAndNumber(This,pTag,pNumber)	\
    (This)->lpVtbl -> GetTagAndNumber(This,pTag,pNumber)

#define IRmsCartridge_SetTagAndNumber(This,tag,number)	\
    (This)->lpVtbl -> SetTagAndNumber(This,tag,number)

#define IRmsCartridge_GetBarcode(This,pBarcode)	\
    (This)->lpVtbl -> GetBarcode(This,pBarcode)

#define IRmsCartridge_GetOnMediaIdentifier(This,pIdentifier,pSize,pType)	\
    (This)->lpVtbl -> GetOnMediaIdentifier(This,pIdentifier,pSize,pType)

#define IRmsCartridge_SetOnMediaIdentifier(This,pIdentifier,size,type)	\
    (This)->lpVtbl -> SetOnMediaIdentifier(This,pIdentifier,size,type)

#define IRmsCartridge_GetOnMediaLabel(This,pLabel)	\
    (This)->lpVtbl -> GetOnMediaLabel(This,pLabel)

#define IRmsCartridge_SetOnMediaLabel(This,label)	\
    (This)->lpVtbl -> SetOnMediaLabel(This,label)

#define IRmsCartridge_GetStatus(This,pStatus)	\
    (This)->lpVtbl -> GetStatus(This,pStatus)

#define IRmsCartridge_SetStatus(This,status)	\
    (This)->lpVtbl -> SetStatus(This,status)

#define IRmsCartridge_GetType(This,pType)	\
    (This)->lpVtbl -> GetType(This,pType)

#define IRmsCartridge_SetType(This,type)	\
    (This)->lpVtbl -> SetType(This,type)

#define IRmsCartridge_GetBlockSize(This,pBlockSize)	\
    (This)->lpVtbl -> GetBlockSize(This,pBlockSize)

#define IRmsCartridge_SetBlockSize(This,blockSize)	\
    (This)->lpVtbl -> SetBlockSize(This,blockSize)

#define IRmsCartridge_SetIsTwoSided(This,flag)	\
    (This)->lpVtbl -> SetIsTwoSided(This,flag)

#define IRmsCartridge_IsTwoSided(This)	\
    (This)->lpVtbl -> IsTwoSided(This)

#define IRmsCartridge_SetIsMounted(This,flag)	\
    (This)->lpVtbl -> SetIsMounted(This,flag)

#define IRmsCartridge_IsMounted(This)	\
    (This)->lpVtbl -> IsMounted(This)

#define IRmsCartridge_SetIsAvailable(This,flag)	\
    (This)->lpVtbl -> SetIsAvailable(This,flag)

#define IRmsCartridge_IsAvailable(This)	\
    (This)->lpVtbl -> IsAvailable(This)

#define IRmsCartridge_GetHome(This,pType,pLibId,pMediaSetId,pPos,pAlt1,pAlt2,pAlt3,pInvert)	\
    (This)->lpVtbl -> GetHome(This,pType,pLibId,pMediaSetId,pPos,pAlt1,pAlt2,pAlt3,pInvert)

#define IRmsCartridge_SetHome(This,type,libId,mediaSetId,pos,alt1,alt2,alt3,invert)	\
    (This)->lpVtbl -> SetHome(This,type,libId,mediaSetId,pos,alt1,alt2,alt3,invert)

#define IRmsCartridge_GetLocation(This,pType,pLibId,pMediaSetId,pPos,pAlt1,pAlt2,pAlt3,pInvert)	\
    (This)->lpVtbl -> GetLocation(This,pType,pLibId,pMediaSetId,pPos,pAlt1,pAlt2,pAlt3,pInvert)

#define IRmsCartridge_SetLocation(This,type,libId,mediaSetId,pos,alt1,alt2,alt3,invert)	\
    (This)->lpVtbl -> SetLocation(This,type,libId,mediaSetId,pos,alt1,alt2,alt3,invert)

#define IRmsCartridge_GetDrive(This,ptr)	\
    (This)->lpVtbl -> GetDrive(This,ptr)

#define IRmsCartridge_SetDrive(This,ptr)	\
    (This)->lpVtbl -> SetDrive(This,ptr)

#define IRmsCartridge_GetMailStop(This,pMailStop)	\
    (This)->lpVtbl -> GetMailStop(This,pMailStop)

#define IRmsCartridge_SetMailStop(This,mailStop)	\
    (This)->lpVtbl -> SetMailStop(This,mailStop)

#define IRmsCartridge_GetInfo(This,pInfo,pSize)	\
    (This)->lpVtbl -> GetInfo(This,pInfo,pSize)

#define IRmsCartridge_SetInfo(This,pInfo,size)	\
    (This)->lpVtbl -> SetInfo(This,pInfo,size)

#define IRmsCartridge_GetOwnerClassId(This,pClassId)	\
    (This)->lpVtbl -> GetOwnerClassId(This,pClassId)

#define IRmsCartridge_SetOwnerClassId(This,classId)	\
    (This)->lpVtbl -> SetOwnerClassId(This,classId)

#define IRmsCartridge_GetPartitions(This,ptr)	\
    (This)->lpVtbl -> GetPartitions(This,ptr)

#define IRmsCartridge_GetVerifierClass(This,pClassId)	\
    (This)->lpVtbl -> GetVerifierClass(This,pClassId)

#define IRmsCartridge_SetVerifierClass(This,classId)	\
    (This)->lpVtbl -> SetVerifierClass(This,classId)

#define IRmsCartridge_GetPortalClass(This,pClassId)	\
    (This)->lpVtbl -> GetPortalClass(This,pClassId)

#define IRmsCartridge_SetPortalClass(This,classId)	\
    (This)->lpVtbl -> SetPortalClass(This,classId)

#define IRmsCartridge_Mount(This,ppDrive,options,threadId)	\
    (This)->lpVtbl -> Mount(This,ppDrive,options,threadId)

#define IRmsCartridge_Dismount(This,options)	\
    (This)->lpVtbl -> Dismount(This,options)

#define IRmsCartridge_Home(This,options)	\
    (This)->lpVtbl -> Home(This,options)

#define IRmsCartridge_CreateDataMover(This,ptr)	\
    (This)->lpVtbl -> CreateDataMover(This,ptr)

#define IRmsCartridge_ReleaseDataMover(This,ptr)	\
    (This)->lpVtbl -> ReleaseDataMover(This,ptr)

#define IRmsCartridge_LoadDataCache(This,pCache,pSize,pUsed,pStartPBA)	\
    (This)->lpVtbl -> LoadDataCache(This,pCache,pSize,pUsed,pStartPBA)

#define IRmsCartridge_SaveDataCache(This,pCache,size,used,startPBA)	\
    (This)->lpVtbl -> SaveDataCache(This,pCache,size,used,startPBA)

#define IRmsCartridge_GetManagedBy(This,pManagedBy)	\
    (This)->lpVtbl -> GetManagedBy(This,pManagedBy)

#define IRmsCartridge_SetManagedBy(This,managedBy)	\
    (This)->lpVtbl -> SetManagedBy(This,managedBy)

#define IRmsCartridge_IsFixedBlockSize(This)	\
    (This)->lpVtbl -> IsFixedBlockSize(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRmsCartridge_GetMediaSetId_Proxy( 
    IRmsCartridge * This,
    /* [out] */ GUID *pMediaSetId);


void __RPC_STUB IRmsCartridge_GetMediaSetId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsCartridge_SetMediaSetId_Proxy( 
    IRmsCartridge * This,
    /* [in] */ GUID mediaSetId);


void __RPC_STUB IRmsCartridge_SetMediaSetId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsCartridge_SetCartridgeId_Proxy( 
    IRmsCartridge * This,
    /* [in] */ GUID cartId);


void __RPC_STUB IRmsCartridge_SetCartridgeId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsCartridge_GetCartridgeId_Proxy( 
    IRmsCartridge * This,
    /* [out] */ GUID *pCartId);


void __RPC_STUB IRmsCartridge_GetCartridgeId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsCartridge_GetName_Proxy( 
    IRmsCartridge * This,
    /* [string][out][in] */ BSTR *pName);


void __RPC_STUB IRmsCartridge_GetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsCartridge_SetName_Proxy( 
    IRmsCartridge * This,
    /* [string][in] */ BSTR name);


void __RPC_STUB IRmsCartridge_SetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsCartridge_GetDescription_Proxy( 
    IRmsCartridge * This,
    /* [string][out][in] */ BSTR *pDescription);


void __RPC_STUB IRmsCartridge_GetDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsCartridge_SetDescription_Proxy( 
    IRmsCartridge * This,
    /* [string][in] */ BSTR name);


void __RPC_STUB IRmsCartridge_SetDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsCartridge_GetTagAndNumber_Proxy( 
    IRmsCartridge * This,
    /* [string][out][in] */ BSTR *pTag,
    /* [out] */ LONG *pNumber);


void __RPC_STUB IRmsCartridge_GetTagAndNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsCartridge_SetTagAndNumber_Proxy( 
    IRmsCartridge * This,
    /* [string][in] */ BSTR tag,
    /* [in] */ LONG number);


void __RPC_STUB IRmsCartridge_SetTagAndNumber_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsCartridge_GetBarcode_Proxy( 
    IRmsCartridge * This,
    /* [string][out][in] */ BSTR *pBarcode);


void __RPC_STUB IRmsCartridge_GetBarcode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsCartridge_GetOnMediaIdentifier_Proxy( 
    IRmsCartridge * This,
    /* [size_is][out][in] */ BYTE *pIdentifier,
    /* [out][in] */ LONG *pSize,
    /* [out] */ LONG *pType);


void __RPC_STUB IRmsCartridge_GetOnMediaIdentifier_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsCartridge_SetOnMediaIdentifier_Proxy( 
    IRmsCartridge * This,
    /* [size_is][in] */ BYTE *pIdentifier,
    /* [in] */ LONG size,
    /* [in] */ LONG type);


void __RPC_STUB IRmsCartridge_SetOnMediaIdentifier_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsCartridge_GetOnMediaLabel_Proxy( 
    IRmsCartridge * This,
    /* [string][out][in] */ BSTR *pLabel);


void __RPC_STUB IRmsCartridge_GetOnMediaLabel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsCartridge_SetOnMediaLabel_Proxy( 
    IRmsCartridge * This,
    /* [string][in] */ BSTR label);


void __RPC_STUB IRmsCartridge_SetOnMediaLabel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsCartridge_GetStatus_Proxy( 
    IRmsCartridge * This,
    /* [out] */ LONG *pStatus);


void __RPC_STUB IRmsCartridge_GetStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsCartridge_SetStatus_Proxy( 
    IRmsCartridge * This,
    /* [in] */ LONG status);


void __RPC_STUB IRmsCartridge_SetStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsCartridge_GetType_Proxy( 
    IRmsCartridge * This,
    /* [out] */ LONG *pType);


void __RPC_STUB IRmsCartridge_GetType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsCartridge_SetType_Proxy( 
    IRmsCartridge * This,
    /* [in] */ LONG type);


void __RPC_STUB IRmsCartridge_SetType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsCartridge_GetBlockSize_Proxy( 
    IRmsCartridge * This,
    /* [out] */ LONG *pBlockSize);


void __RPC_STUB IRmsCartridge_GetBlockSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsCartridge_SetBlockSize_Proxy( 
    IRmsCartridge * This,
    /* [in] */ LONG blockSize);


void __RPC_STUB IRmsCartridge_SetBlockSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsCartridge_SetIsTwoSided_Proxy( 
    IRmsCartridge * This,
    /* [in] */ BOOL flag);


void __RPC_STUB IRmsCartridge_SetIsTwoSided_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsCartridge_IsTwoSided_Proxy( 
    IRmsCartridge * This);


void __RPC_STUB IRmsCartridge_IsTwoSided_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsCartridge_SetIsMounted_Proxy( 
    IRmsCartridge * This,
    /* [in] */ BOOL flag);


void __RPC_STUB IRmsCartridge_SetIsMounted_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsCartridge_IsMounted_Proxy( 
    IRmsCartridge * This);


void __RPC_STUB IRmsCartridge_IsMounted_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsCartridge_SetIsAvailable_Proxy( 
    IRmsCartridge * This,
    /* [in] */ BOOL flag);


void __RPC_STUB IRmsCartridge_SetIsAvailable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsCartridge_IsAvailable_Proxy( 
    IRmsCartridge * This);


void __RPC_STUB IRmsCartridge_IsAvailable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsCartridge_GetHome_Proxy( 
    IRmsCartridge * This,
    /* [out] */ LONG *pType,
    /* [out] */ GUID *pLibId,
    /* [out] */ GUID *pMediaSetId,
    /* [out] */ LONG *pPos,
    /* [out] */ LONG *pAlt1,
    /* [out] */ LONG *pAlt2,
    /* [out] */ LONG *pAlt3,
    /* [out] */ BOOL *pInvert);


void __RPC_STUB IRmsCartridge_GetHome_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsCartridge_SetHome_Proxy( 
    IRmsCartridge * This,
    /* [in] */ LONG type,
    /* [in] */ GUID libId,
    /* [in] */ GUID mediaSetId,
    /* [in] */ LONG pos,
    /* [in] */ LONG alt1,
    /* [in] */ LONG alt2,
    /* [in] */ LONG alt3,
    /* [in] */ BOOL invert);


void __RPC_STUB IRmsCartridge_SetHome_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsCartridge_GetLocation_Proxy( 
    IRmsCartridge * This,
    /* [unique][out][in] */ LONG *pType,
    /* [unique][out][in] */ GUID *pLibId,
    /* [unique][out][in] */ GUID *pMediaSetId,
    /* [unique][out][in] */ LONG *pPos,
    /* [unique][out][in] */ LONG *pAlt1,
    /* [unique][out][in] */ LONG *pAlt2,
    /* [unique][out][in] */ LONG *pAlt3,
    /* [unique][out][in] */ BOOL *pInvert);


void __RPC_STUB IRmsCartridge_GetLocation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsCartridge_SetLocation_Proxy( 
    IRmsCartridge * This,
    /* [in] */ LONG type,
    /* [in] */ GUID libId,
    /* [in] */ GUID mediaSetId,
    /* [in] */ LONG pos,
    /* [in] */ LONG alt1,
    /* [in] */ LONG alt2,
    /* [in] */ LONG alt3,
    /* [in] */ BOOL invert);


void __RPC_STUB IRmsCartridge_SetLocation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsCartridge_GetDrive_Proxy( 
    IRmsCartridge * This,
    /* [out] */ IRmsDrive **ptr);


void __RPC_STUB IRmsCartridge_GetDrive_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsCartridge_SetDrive_Proxy( 
    IRmsCartridge * This,
    /* [in] */ IRmsDrive *ptr);


void __RPC_STUB IRmsCartridge_SetDrive_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsCartridge_GetMailStop_Proxy( 
    IRmsCartridge * This,
    /* [string][out][in] */ BSTR *pMailStop);


void __RPC_STUB IRmsCartridge_GetMailStop_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsCartridge_SetMailStop_Proxy( 
    IRmsCartridge * This,
    /* [string][in] */ BSTR mailStop);


void __RPC_STUB IRmsCartridge_SetMailStop_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsCartridge_GetInfo_Proxy( 
    IRmsCartridge * This,
    /* [size_is][out] */ UCHAR *pInfo,
    /* [out] */ SHORT *pSize);


void __RPC_STUB IRmsCartridge_GetInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsCartridge_SetInfo_Proxy( 
    IRmsCartridge * This,
    /* [size_is][in] */ UCHAR *pInfo,
    /* [in] */ SHORT size);


void __RPC_STUB IRmsCartridge_SetInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsCartridge_GetOwnerClassId_Proxy( 
    IRmsCartridge * This,
    /* [out] */ CLSID *pClassId);


void __RPC_STUB IRmsCartridge_GetOwnerClassId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsCartridge_SetOwnerClassId_Proxy( 
    IRmsCartridge * This,
    /* [in] */ CLSID classId);


void __RPC_STUB IRmsCartridge_SetOwnerClassId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsCartridge_GetPartitions_Proxy( 
    IRmsCartridge * This,
    /* [out] */ IWsbIndexedCollection **ptr);


void __RPC_STUB IRmsCartridge_GetPartitions_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsCartridge_GetVerifierClass_Proxy( 
    IRmsCartridge * This,
    /* [out] */ CLSID *pClassId);


void __RPC_STUB IRmsCartridge_GetVerifierClass_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsCartridge_SetVerifierClass_Proxy( 
    IRmsCartridge * This,
    /* [in] */ CLSID classId);


void __RPC_STUB IRmsCartridge_SetVerifierClass_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsCartridge_GetPortalClass_Proxy( 
    IRmsCartridge * This,
    /* [out] */ CLSID *pClassId);


void __RPC_STUB IRmsCartridge_GetPortalClass_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsCartridge_SetPortalClass_Proxy( 
    IRmsCartridge * This,
    /* [in] */ CLSID classId);


void __RPC_STUB IRmsCartridge_SetPortalClass_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsCartridge_Mount_Proxy( 
    IRmsCartridge * This,
    /* [out] */ IRmsDrive **ppDrive,
    /* [defaultvalue][in] */ DWORD options,
    /* [defaultvalue][in] */ DWORD threadId);


void __RPC_STUB IRmsCartridge_Mount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsCartridge_Dismount_Proxy( 
    IRmsCartridge * This,
    /* [defaultvalue][in] */ DWORD options);


void __RPC_STUB IRmsCartridge_Dismount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsCartridge_Home_Proxy( 
    IRmsCartridge * This,
    /* [defaultvalue][in] */ DWORD options);


void __RPC_STUB IRmsCartridge_Home_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsCartridge_CreateDataMover_Proxy( 
    IRmsCartridge * This,
    /* [out] */ IDataMover **ptr);


void __RPC_STUB IRmsCartridge_CreateDataMover_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsCartridge_ReleaseDataMover_Proxy( 
    IRmsCartridge * This,
    /* [in] */ IDataMover *ptr);


void __RPC_STUB IRmsCartridge_ReleaseDataMover_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsCartridge_LoadDataCache_Proxy( 
    IRmsCartridge * This,
    /* [size_is][out] */ BYTE *pCache,
    /* [out][in] */ ULONG *pSize,
    /* [out] */ ULONG *pUsed,
    /* [out] */ ULARGE_INTEGER *pStartPBA);


void __RPC_STUB IRmsCartridge_LoadDataCache_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsCartridge_SaveDataCache_Proxy( 
    IRmsCartridge * This,
    /* [size_is][in] */ BYTE *pCache,
    /* [in] */ ULONG size,
    /* [in] */ ULONG used,
    /* [in] */ ULARGE_INTEGER startPBA);


void __RPC_STUB IRmsCartridge_SaveDataCache_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsCartridge_GetManagedBy_Proxy( 
    IRmsCartridge * This,
    /* [out] */ LONG *pManagedBy);


void __RPC_STUB IRmsCartridge_GetManagedBy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsCartridge_SetManagedBy_Proxy( 
    IRmsCartridge * This,
    /* [in] */ LONG managedBy);


void __RPC_STUB IRmsCartridge_SetManagedBy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsCartridge_IsFixedBlockSize_Proxy( 
    IRmsCartridge * This);


void __RPC_STUB IRmsCartridge_IsFixedBlockSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRmsCartridge_INTERFACE_DEFINED__ */


#ifndef __IRmsDrive_INTERFACE_DEFINED__
#define __IRmsDrive_INTERFACE_DEFINED__

/* interface IRmsDrive */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRmsDrive;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AA46E0CE-F1F8-11D2-A81E-00C04FB960ED")
    IRmsDrive : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetMountReference( 
            /* [out] */ LONG *pRefs) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ResetMountReference( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddMountReference( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReleaseMountReference( 
            /* [defaultvalue][in] */ DWORD options = 0) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SelectForMount( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateDataMover( 
            /* [out] */ IDataMover **ptr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReleaseDataMover( 
            /* [in] */ IDataMover *ptr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Eject( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLargestFreeSpace( 
            /* [out] */ LONGLONG *freeSpace,
            /* [out] */ LONGLONG *capacity) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnloadNow( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRmsDriveVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRmsDrive * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRmsDrive * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRmsDrive * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IRmsDrive * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IRmsDrive * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IRmsDrive * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRmsDrive * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *GetMountReference )( 
            IRmsDrive * This,
            /* [out] */ LONG *pRefs);
        
        HRESULT ( STDMETHODCALLTYPE *ResetMountReference )( 
            IRmsDrive * This);
        
        HRESULT ( STDMETHODCALLTYPE *AddMountReference )( 
            IRmsDrive * This);
        
        HRESULT ( STDMETHODCALLTYPE *ReleaseMountReference )( 
            IRmsDrive * This,
            /* [defaultvalue][in] */ DWORD options);
        
        HRESULT ( STDMETHODCALLTYPE *SelectForMount )( 
            IRmsDrive * This);
        
        HRESULT ( STDMETHODCALLTYPE *CreateDataMover )( 
            IRmsDrive * This,
            /* [out] */ IDataMover **ptr);
        
        HRESULT ( STDMETHODCALLTYPE *ReleaseDataMover )( 
            IRmsDrive * This,
            /* [in] */ IDataMover *ptr);
        
        HRESULT ( STDMETHODCALLTYPE *Eject )( 
            IRmsDrive * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetLargestFreeSpace )( 
            IRmsDrive * This,
            /* [out] */ LONGLONG *freeSpace,
            /* [out] */ LONGLONG *capacity);
        
        HRESULT ( STDMETHODCALLTYPE *UnloadNow )( 
            IRmsDrive * This);
        
        END_INTERFACE
    } IRmsDriveVtbl;

    interface IRmsDrive
    {
        CONST_VTBL struct IRmsDriveVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRmsDrive_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRmsDrive_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRmsDrive_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRmsDrive_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRmsDrive_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRmsDrive_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRmsDrive_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRmsDrive_GetMountReference(This,pRefs)	\
    (This)->lpVtbl -> GetMountReference(This,pRefs)

#define IRmsDrive_ResetMountReference(This)	\
    (This)->lpVtbl -> ResetMountReference(This)

#define IRmsDrive_AddMountReference(This)	\
    (This)->lpVtbl -> AddMountReference(This)

#define IRmsDrive_ReleaseMountReference(This,options)	\
    (This)->lpVtbl -> ReleaseMountReference(This,options)

#define IRmsDrive_SelectForMount(This)	\
    (This)->lpVtbl -> SelectForMount(This)

#define IRmsDrive_CreateDataMover(This,ptr)	\
    (This)->lpVtbl -> CreateDataMover(This,ptr)

#define IRmsDrive_ReleaseDataMover(This,ptr)	\
    (This)->lpVtbl -> ReleaseDataMover(This,ptr)

#define IRmsDrive_Eject(This)	\
    (This)->lpVtbl -> Eject(This)

#define IRmsDrive_GetLargestFreeSpace(This,freeSpace,capacity)	\
    (This)->lpVtbl -> GetLargestFreeSpace(This,freeSpace,capacity)

#define IRmsDrive_UnloadNow(This)	\
    (This)->lpVtbl -> UnloadNow(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRmsDrive_GetMountReference_Proxy( 
    IRmsDrive * This,
    /* [out] */ LONG *pRefs);


void __RPC_STUB IRmsDrive_GetMountReference_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsDrive_ResetMountReference_Proxy( 
    IRmsDrive * This);


void __RPC_STUB IRmsDrive_ResetMountReference_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsDrive_AddMountReference_Proxy( 
    IRmsDrive * This);


void __RPC_STUB IRmsDrive_AddMountReference_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsDrive_ReleaseMountReference_Proxy( 
    IRmsDrive * This,
    /* [defaultvalue][in] */ DWORD options);


void __RPC_STUB IRmsDrive_ReleaseMountReference_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsDrive_SelectForMount_Proxy( 
    IRmsDrive * This);


void __RPC_STUB IRmsDrive_SelectForMount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsDrive_CreateDataMover_Proxy( 
    IRmsDrive * This,
    /* [out] */ IDataMover **ptr);


void __RPC_STUB IRmsDrive_CreateDataMover_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsDrive_ReleaseDataMover_Proxy( 
    IRmsDrive * This,
    /* [in] */ IDataMover *ptr);


void __RPC_STUB IRmsDrive_ReleaseDataMover_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsDrive_Eject_Proxy( 
    IRmsDrive * This);


void __RPC_STUB IRmsDrive_Eject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsDrive_GetLargestFreeSpace_Proxy( 
    IRmsDrive * This,
    /* [out] */ LONGLONG *freeSpace,
    /* [out] */ LONGLONG *capacity);


void __RPC_STUB IRmsDrive_GetLargestFreeSpace_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsDrive_UnloadNow_Proxy( 
    IRmsDrive * This);


void __RPC_STUB IRmsDrive_UnloadNow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRmsDrive_INTERFACE_DEFINED__ */


#ifndef __IRmsStorageSlot_INTERFACE_DEFINED__
#define __IRmsStorageSlot_INTERFACE_DEFINED__

/* interface IRmsStorageSlot */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRmsStorageSlot;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FE37FB06-3729-11D0-8CF4-00A0C9190459")
    IRmsStorageSlot : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetIsInMagazine( 
            /* [in] */ BOOL flag) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsInMagazine( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMagazineAndCell( 
            /* [out] */ LONG *pMag,
            /* [out] */ LONG *pCell) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMagazineAndCell( 
            /* [in] */ LONG mag,
            /* [in] */ LONG cell) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRmsStorageSlotVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRmsStorageSlot * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRmsStorageSlot * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRmsStorageSlot * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IRmsStorageSlot * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IRmsStorageSlot * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IRmsStorageSlot * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRmsStorageSlot * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *SetIsInMagazine )( 
            IRmsStorageSlot * This,
            /* [in] */ BOOL flag);
        
        HRESULT ( STDMETHODCALLTYPE *IsInMagazine )( 
            IRmsStorageSlot * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetMagazineAndCell )( 
            IRmsStorageSlot * This,
            /* [out] */ LONG *pMag,
            /* [out] */ LONG *pCell);
        
        HRESULT ( STDMETHODCALLTYPE *SetMagazineAndCell )( 
            IRmsStorageSlot * This,
            /* [in] */ LONG mag,
            /* [in] */ LONG cell);
        
        END_INTERFACE
    } IRmsStorageSlotVtbl;

    interface IRmsStorageSlot
    {
        CONST_VTBL struct IRmsStorageSlotVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRmsStorageSlot_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRmsStorageSlot_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRmsStorageSlot_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRmsStorageSlot_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRmsStorageSlot_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRmsStorageSlot_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRmsStorageSlot_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRmsStorageSlot_SetIsInMagazine(This,flag)	\
    (This)->lpVtbl -> SetIsInMagazine(This,flag)

#define IRmsStorageSlot_IsInMagazine(This)	\
    (This)->lpVtbl -> IsInMagazine(This)

#define IRmsStorageSlot_GetMagazineAndCell(This,pMag,pCell)	\
    (This)->lpVtbl -> GetMagazineAndCell(This,pMag,pCell)

#define IRmsStorageSlot_SetMagazineAndCell(This,mag,cell)	\
    (This)->lpVtbl -> SetMagazineAndCell(This,mag,cell)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRmsStorageSlot_SetIsInMagazine_Proxy( 
    IRmsStorageSlot * This,
    /* [in] */ BOOL flag);


void __RPC_STUB IRmsStorageSlot_SetIsInMagazine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsStorageSlot_IsInMagazine_Proxy( 
    IRmsStorageSlot * This);


void __RPC_STUB IRmsStorageSlot_IsInMagazine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsStorageSlot_GetMagazineAndCell_Proxy( 
    IRmsStorageSlot * This,
    /* [out] */ LONG *pMag,
    /* [out] */ LONG *pCell);


void __RPC_STUB IRmsStorageSlot_GetMagazineAndCell_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsStorageSlot_SetMagazineAndCell_Proxy( 
    IRmsStorageSlot * This,
    /* [in] */ LONG mag,
    /* [in] */ LONG cell);


void __RPC_STUB IRmsStorageSlot_SetMagazineAndCell_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRmsStorageSlot_INTERFACE_DEFINED__ */


#ifndef __IRmsMediumChanger_INTERFACE_DEFINED__
#define __IRmsMediumChanger_INTERFACE_DEFINED__

/* interface IRmsMediumChanger */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRmsMediumChanger;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FE37FB07-3729-11D0-8CF4-00A0C9190459")
    IRmsMediumChanger : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Initialize( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AcquireDevice( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReleaseDevice( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetHome( 
            /* [out] */ LONG *pType,
            /* [out] */ LONG *pPos,
            /* [out] */ BOOL *pInvert) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetHome( 
            /* [in] */ LONG type,
            /* [in] */ LONG pos,
            /* [in] */ BOOL invert) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAutomatic( 
            /* [in] */ BOOL flag) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsAutomatic( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCanRotate( 
            /* [in] */ BOOL flag) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CanRotate( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOperation( 
            /* [string][out][in] */ BSTR *pOperation) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetOperation( 
            /* [string][in] */ BSTR pOperation) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPercentComplete( 
            /* [out] */ BYTE *pPercent) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPercentComplete( 
            /* [in] */ BYTE percent) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE TestReady( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ImportCartridge( 
            /* [in] */ IRmsCartridge **pCart) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ExportCartridge( 
            /* [in] */ IRmsCartridge **pCart) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MoveCartridge( 
            /* [in] */ IRmsCartridge *pSrcCart,
            IUnknown *pDestElmt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE HomeCartridge( 
            /* [in] */ IRmsCartridge *pCart) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRmsMediumChangerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRmsMediumChanger * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRmsMediumChanger * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRmsMediumChanger * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IRmsMediumChanger * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IRmsMediumChanger * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IRmsMediumChanger * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRmsMediumChanger * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IRmsMediumChanger * This);
        
        HRESULT ( STDMETHODCALLTYPE *AcquireDevice )( 
            IRmsMediumChanger * This);
        
        HRESULT ( STDMETHODCALLTYPE *ReleaseDevice )( 
            IRmsMediumChanger * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetHome )( 
            IRmsMediumChanger * This,
            /* [out] */ LONG *pType,
            /* [out] */ LONG *pPos,
            /* [out] */ BOOL *pInvert);
        
        HRESULT ( STDMETHODCALLTYPE *SetHome )( 
            IRmsMediumChanger * This,
            /* [in] */ LONG type,
            /* [in] */ LONG pos,
            /* [in] */ BOOL invert);
        
        HRESULT ( STDMETHODCALLTYPE *SetAutomatic )( 
            IRmsMediumChanger * This,
            /* [in] */ BOOL flag);
        
        HRESULT ( STDMETHODCALLTYPE *IsAutomatic )( 
            IRmsMediumChanger * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetCanRotate )( 
            IRmsMediumChanger * This,
            /* [in] */ BOOL flag);
        
        HRESULT ( STDMETHODCALLTYPE *CanRotate )( 
            IRmsMediumChanger * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetOperation )( 
            IRmsMediumChanger * This,
            /* [string][out][in] */ BSTR *pOperation);
        
        HRESULT ( STDMETHODCALLTYPE *SetOperation )( 
            IRmsMediumChanger * This,
            /* [string][in] */ BSTR pOperation);
        
        HRESULT ( STDMETHODCALLTYPE *GetPercentComplete )( 
            IRmsMediumChanger * This,
            /* [out] */ BYTE *pPercent);
        
        HRESULT ( STDMETHODCALLTYPE *SetPercentComplete )( 
            IRmsMediumChanger * This,
            /* [in] */ BYTE percent);
        
        HRESULT ( STDMETHODCALLTYPE *TestReady )( 
            IRmsMediumChanger * This);
        
        HRESULT ( STDMETHODCALLTYPE *ImportCartridge )( 
            IRmsMediumChanger * This,
            /* [in] */ IRmsCartridge **pCart);
        
        HRESULT ( STDMETHODCALLTYPE *ExportCartridge )( 
            IRmsMediumChanger * This,
            /* [in] */ IRmsCartridge **pCart);
        
        HRESULT ( STDMETHODCALLTYPE *MoveCartridge )( 
            IRmsMediumChanger * This,
            /* [in] */ IRmsCartridge *pSrcCart,
            IUnknown *pDestElmt);
        
        HRESULT ( STDMETHODCALLTYPE *HomeCartridge )( 
            IRmsMediumChanger * This,
            /* [in] */ IRmsCartridge *pCart);
        
        END_INTERFACE
    } IRmsMediumChangerVtbl;

    interface IRmsMediumChanger
    {
        CONST_VTBL struct IRmsMediumChangerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRmsMediumChanger_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRmsMediumChanger_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRmsMediumChanger_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRmsMediumChanger_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRmsMediumChanger_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRmsMediumChanger_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRmsMediumChanger_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRmsMediumChanger_Initialize(This)	\
    (This)->lpVtbl -> Initialize(This)

#define IRmsMediumChanger_AcquireDevice(This)	\
    (This)->lpVtbl -> AcquireDevice(This)

#define IRmsMediumChanger_ReleaseDevice(This)	\
    (This)->lpVtbl -> ReleaseDevice(This)

#define IRmsMediumChanger_GetHome(This,pType,pPos,pInvert)	\
    (This)->lpVtbl -> GetHome(This,pType,pPos,pInvert)

#define IRmsMediumChanger_SetHome(This,type,pos,invert)	\
    (This)->lpVtbl -> SetHome(This,type,pos,invert)

#define IRmsMediumChanger_SetAutomatic(This,flag)	\
    (This)->lpVtbl -> SetAutomatic(This,flag)

#define IRmsMediumChanger_IsAutomatic(This)	\
    (This)->lpVtbl -> IsAutomatic(This)

#define IRmsMediumChanger_SetCanRotate(This,flag)	\
    (This)->lpVtbl -> SetCanRotate(This,flag)

#define IRmsMediumChanger_CanRotate(This)	\
    (This)->lpVtbl -> CanRotate(This)

#define IRmsMediumChanger_GetOperation(This,pOperation)	\
    (This)->lpVtbl -> GetOperation(This,pOperation)

#define IRmsMediumChanger_SetOperation(This,pOperation)	\
    (This)->lpVtbl -> SetOperation(This,pOperation)

#define IRmsMediumChanger_GetPercentComplete(This,pPercent)	\
    (This)->lpVtbl -> GetPercentComplete(This,pPercent)

#define IRmsMediumChanger_SetPercentComplete(This,percent)	\
    (This)->lpVtbl -> SetPercentComplete(This,percent)

#define IRmsMediumChanger_TestReady(This)	\
    (This)->lpVtbl -> TestReady(This)

#define IRmsMediumChanger_ImportCartridge(This,pCart)	\
    (This)->lpVtbl -> ImportCartridge(This,pCart)

#define IRmsMediumChanger_ExportCartridge(This,pCart)	\
    (This)->lpVtbl -> ExportCartridge(This,pCart)

#define IRmsMediumChanger_MoveCartridge(This,pSrcCart,pDestElmt)	\
    (This)->lpVtbl -> MoveCartridge(This,pSrcCart,pDestElmt)

#define IRmsMediumChanger_HomeCartridge(This,pCart)	\
    (This)->lpVtbl -> HomeCartridge(This,pCart)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRmsMediumChanger_Initialize_Proxy( 
    IRmsMediumChanger * This);


void __RPC_STUB IRmsMediumChanger_Initialize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsMediumChanger_AcquireDevice_Proxy( 
    IRmsMediumChanger * This);


void __RPC_STUB IRmsMediumChanger_AcquireDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsMediumChanger_ReleaseDevice_Proxy( 
    IRmsMediumChanger * This);


void __RPC_STUB IRmsMediumChanger_ReleaseDevice_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsMediumChanger_GetHome_Proxy( 
    IRmsMediumChanger * This,
    /* [out] */ LONG *pType,
    /* [out] */ LONG *pPos,
    /* [out] */ BOOL *pInvert);


void __RPC_STUB IRmsMediumChanger_GetHome_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsMediumChanger_SetHome_Proxy( 
    IRmsMediumChanger * This,
    /* [in] */ LONG type,
    /* [in] */ LONG pos,
    /* [in] */ BOOL invert);


void __RPC_STUB IRmsMediumChanger_SetHome_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsMediumChanger_SetAutomatic_Proxy( 
    IRmsMediumChanger * This,
    /* [in] */ BOOL flag);


void __RPC_STUB IRmsMediumChanger_SetAutomatic_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsMediumChanger_IsAutomatic_Proxy( 
    IRmsMediumChanger * This);


void __RPC_STUB IRmsMediumChanger_IsAutomatic_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsMediumChanger_SetCanRotate_Proxy( 
    IRmsMediumChanger * This,
    /* [in] */ BOOL flag);


void __RPC_STUB IRmsMediumChanger_SetCanRotate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsMediumChanger_CanRotate_Proxy( 
    IRmsMediumChanger * This);


void __RPC_STUB IRmsMediumChanger_CanRotate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsMediumChanger_GetOperation_Proxy( 
    IRmsMediumChanger * This,
    /* [string][out][in] */ BSTR *pOperation);


void __RPC_STUB IRmsMediumChanger_GetOperation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsMediumChanger_SetOperation_Proxy( 
    IRmsMediumChanger * This,
    /* [string][in] */ BSTR pOperation);


void __RPC_STUB IRmsMediumChanger_SetOperation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsMediumChanger_GetPercentComplete_Proxy( 
    IRmsMediumChanger * This,
    /* [out] */ BYTE *pPercent);


void __RPC_STUB IRmsMediumChanger_GetPercentComplete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsMediumChanger_SetPercentComplete_Proxy( 
    IRmsMediumChanger * This,
    /* [in] */ BYTE percent);


void __RPC_STUB IRmsMediumChanger_SetPercentComplete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsMediumChanger_TestReady_Proxy( 
    IRmsMediumChanger * This);


void __RPC_STUB IRmsMediumChanger_TestReady_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsMediumChanger_ImportCartridge_Proxy( 
    IRmsMediumChanger * This,
    /* [in] */ IRmsCartridge **pCart);


void __RPC_STUB IRmsMediumChanger_ImportCartridge_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsMediumChanger_ExportCartridge_Proxy( 
    IRmsMediumChanger * This,
    /* [in] */ IRmsCartridge **pCart);


void __RPC_STUB IRmsMediumChanger_ExportCartridge_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsMediumChanger_MoveCartridge_Proxy( 
    IRmsMediumChanger * This,
    /* [in] */ IRmsCartridge *pSrcCart,
    IUnknown *pDestElmt);


void __RPC_STUB IRmsMediumChanger_MoveCartridge_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsMediumChanger_HomeCartridge_Proxy( 
    IRmsMediumChanger * This,
    /* [in] */ IRmsCartridge *pCart);


void __RPC_STUB IRmsMediumChanger_HomeCartridge_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRmsMediumChanger_INTERFACE_DEFINED__ */


#ifndef __IRmsMoveMedia_INTERFACE_DEFINED__
#define __IRmsMoveMedia_INTERFACE_DEFINED__

/* interface IRmsMoveMedia */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRmsMoveMedia;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FE37FB18-3729-11D0-8CF4-00A0C9190459")
    IRmsMoveMedia : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetParameters( 
            /* [out][in] */ DWORD *pSize,
            /* [size_is][out] */ PGET_CHANGER_PARAMETERS pParms) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetProductData( 
            /* [out][in] */ DWORD *pSize,
            /* [size_is][out] */ PCHANGER_PRODUCT_DATA pData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RezeroUnit( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InitializeElementStatus( 
            /* [in] */ CHANGER_ELEMENT_LIST elementList,
            /* [in] */ BOOL barCodeScan) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Status( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAccess( 
            /* [in] */ CHANGER_ELEMENT element,
            /* [in] */ DWORD control) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetElementStatus( 
            /* [in] */ CHANGER_ELEMENT_LIST elementList,
            /* [in] */ BOOL volumeTagInfo,
            /* [out][in] */ DWORD *pSize,
            /* [size_is][out] */ PREAD_ELEMENT_ADDRESS_INFO pElementInformation) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ExchangeMedium( 
            /* [in] */ CHANGER_ELEMENT source,
            /* [in] */ CHANGER_ELEMENT destination1,
            /* [in] */ CHANGER_ELEMENT destination2,
            /* [in] */ BOOL flip1,
            /* [in] */ BOOL flip2) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MoveMedium( 
            /* [in] */ CHANGER_ELEMENT source,
            /* [in] */ CHANGER_ELEMENT destination,
            /* [in] */ BOOL flip) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Position( 
            /* [in] */ CHANGER_ELEMENT destination,
            /* [in] */ BOOL flip) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE QueryVolumeTag( 
            /* [in] */ CHANGER_ELEMENT startingElement,
            /* [in] */ DWORD actionCode,
            /* [in] */ UCHAR *pVolumeIDTemplate,
            /* [out][in] */ DWORD *pNumberOfElementsReturned,
            /* [size_is][out] */ PREAD_ELEMENT_ADDRESS_INFO pElementInformation) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRmsMoveMediaVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRmsMoveMedia * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRmsMoveMedia * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRmsMoveMedia * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetParameters )( 
            IRmsMoveMedia * This,
            /* [out][in] */ DWORD *pSize,
            /* [size_is][out] */ PGET_CHANGER_PARAMETERS pParms);
        
        HRESULT ( STDMETHODCALLTYPE *GetProductData )( 
            IRmsMoveMedia * This,
            /* [out][in] */ DWORD *pSize,
            /* [size_is][out] */ PCHANGER_PRODUCT_DATA pData);
        
        HRESULT ( STDMETHODCALLTYPE *RezeroUnit )( 
            IRmsMoveMedia * This);
        
        HRESULT ( STDMETHODCALLTYPE *InitializeElementStatus )( 
            IRmsMoveMedia * This,
            /* [in] */ CHANGER_ELEMENT_LIST elementList,
            /* [in] */ BOOL barCodeScan);
        
        HRESULT ( STDMETHODCALLTYPE *Status )( 
            IRmsMoveMedia * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetAccess )( 
            IRmsMoveMedia * This,
            /* [in] */ CHANGER_ELEMENT element,
            /* [in] */ DWORD control);
        
        HRESULT ( STDMETHODCALLTYPE *GetElementStatus )( 
            IRmsMoveMedia * This,
            /* [in] */ CHANGER_ELEMENT_LIST elementList,
            /* [in] */ BOOL volumeTagInfo,
            /* [out][in] */ DWORD *pSize,
            /* [size_is][out] */ PREAD_ELEMENT_ADDRESS_INFO pElementInformation);
        
        HRESULT ( STDMETHODCALLTYPE *ExchangeMedium )( 
            IRmsMoveMedia * This,
            /* [in] */ CHANGER_ELEMENT source,
            /* [in] */ CHANGER_ELEMENT destination1,
            /* [in] */ CHANGER_ELEMENT destination2,
            /* [in] */ BOOL flip1,
            /* [in] */ BOOL flip2);
        
        HRESULT ( STDMETHODCALLTYPE *MoveMedium )( 
            IRmsMoveMedia * This,
            /* [in] */ CHANGER_ELEMENT source,
            /* [in] */ CHANGER_ELEMENT destination,
            /* [in] */ BOOL flip);
        
        HRESULT ( STDMETHODCALLTYPE *Position )( 
            IRmsMoveMedia * This,
            /* [in] */ CHANGER_ELEMENT destination,
            /* [in] */ BOOL flip);
        
        HRESULT ( STDMETHODCALLTYPE *QueryVolumeTag )( 
            IRmsMoveMedia * This,
            /* [in] */ CHANGER_ELEMENT startingElement,
            /* [in] */ DWORD actionCode,
            /* [in] */ UCHAR *pVolumeIDTemplate,
            /* [out][in] */ DWORD *pNumberOfElementsReturned,
            /* [size_is][out] */ PREAD_ELEMENT_ADDRESS_INFO pElementInformation);
        
        END_INTERFACE
    } IRmsMoveMediaVtbl;

    interface IRmsMoveMedia
    {
        CONST_VTBL struct IRmsMoveMediaVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRmsMoveMedia_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRmsMoveMedia_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRmsMoveMedia_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRmsMoveMedia_GetParameters(This,pSize,pParms)	\
    (This)->lpVtbl -> GetParameters(This,pSize,pParms)

#define IRmsMoveMedia_GetProductData(This,pSize,pData)	\
    (This)->lpVtbl -> GetProductData(This,pSize,pData)

#define IRmsMoveMedia_RezeroUnit(This)	\
    (This)->lpVtbl -> RezeroUnit(This)

#define IRmsMoveMedia_InitializeElementStatus(This,elementList,barCodeScan)	\
    (This)->lpVtbl -> InitializeElementStatus(This,elementList,barCodeScan)

#define IRmsMoveMedia_Status(This)	\
    (This)->lpVtbl -> Status(This)

#define IRmsMoveMedia_SetAccess(This,element,control)	\
    (This)->lpVtbl -> SetAccess(This,element,control)

#define IRmsMoveMedia_GetElementStatus(This,elementList,volumeTagInfo,pSize,pElementInformation)	\
    (This)->lpVtbl -> GetElementStatus(This,elementList,volumeTagInfo,pSize,pElementInformation)

#define IRmsMoveMedia_ExchangeMedium(This,source,destination1,destination2,flip1,flip2)	\
    (This)->lpVtbl -> ExchangeMedium(This,source,destination1,destination2,flip1,flip2)

#define IRmsMoveMedia_MoveMedium(This,source,destination,flip)	\
    (This)->lpVtbl -> MoveMedium(This,source,destination,flip)

#define IRmsMoveMedia_Position(This,destination,flip)	\
    (This)->lpVtbl -> Position(This,destination,flip)

#define IRmsMoveMedia_QueryVolumeTag(This,startingElement,actionCode,pVolumeIDTemplate,pNumberOfElementsReturned,pElementInformation)	\
    (This)->lpVtbl -> QueryVolumeTag(This,startingElement,actionCode,pVolumeIDTemplate,pNumberOfElementsReturned,pElementInformation)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRmsMoveMedia_GetParameters_Proxy( 
    IRmsMoveMedia * This,
    /* [out][in] */ DWORD *pSize,
    /* [size_is][out] */ PGET_CHANGER_PARAMETERS pParms);


void __RPC_STUB IRmsMoveMedia_GetParameters_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsMoveMedia_GetProductData_Proxy( 
    IRmsMoveMedia * This,
    /* [out][in] */ DWORD *pSize,
    /* [size_is][out] */ PCHANGER_PRODUCT_DATA pData);


void __RPC_STUB IRmsMoveMedia_GetProductData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsMoveMedia_RezeroUnit_Proxy( 
    IRmsMoveMedia * This);


void __RPC_STUB IRmsMoveMedia_RezeroUnit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsMoveMedia_InitializeElementStatus_Proxy( 
    IRmsMoveMedia * This,
    /* [in] */ CHANGER_ELEMENT_LIST elementList,
    /* [in] */ BOOL barCodeScan);


void __RPC_STUB IRmsMoveMedia_InitializeElementStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsMoveMedia_Status_Proxy( 
    IRmsMoveMedia * This);


void __RPC_STUB IRmsMoveMedia_Status_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsMoveMedia_SetAccess_Proxy( 
    IRmsMoveMedia * This,
    /* [in] */ CHANGER_ELEMENT element,
    /* [in] */ DWORD control);


void __RPC_STUB IRmsMoveMedia_SetAccess_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsMoveMedia_GetElementStatus_Proxy( 
    IRmsMoveMedia * This,
    /* [in] */ CHANGER_ELEMENT_LIST elementList,
    /* [in] */ BOOL volumeTagInfo,
    /* [out][in] */ DWORD *pSize,
    /* [size_is][out] */ PREAD_ELEMENT_ADDRESS_INFO pElementInformation);


void __RPC_STUB IRmsMoveMedia_GetElementStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsMoveMedia_ExchangeMedium_Proxy( 
    IRmsMoveMedia * This,
    /* [in] */ CHANGER_ELEMENT source,
    /* [in] */ CHANGER_ELEMENT destination1,
    /* [in] */ CHANGER_ELEMENT destination2,
    /* [in] */ BOOL flip1,
    /* [in] */ BOOL flip2);


void __RPC_STUB IRmsMoveMedia_ExchangeMedium_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsMoveMedia_MoveMedium_Proxy( 
    IRmsMoveMedia * This,
    /* [in] */ CHANGER_ELEMENT source,
    /* [in] */ CHANGER_ELEMENT destination,
    /* [in] */ BOOL flip);


void __RPC_STUB IRmsMoveMedia_MoveMedium_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsMoveMedia_Position_Proxy( 
    IRmsMoveMedia * This,
    /* [in] */ CHANGER_ELEMENT destination,
    /* [in] */ BOOL flip);


void __RPC_STUB IRmsMoveMedia_Position_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsMoveMedia_QueryVolumeTag_Proxy( 
    IRmsMoveMedia * This,
    /* [in] */ CHANGER_ELEMENT startingElement,
    /* [in] */ DWORD actionCode,
    /* [in] */ UCHAR *pVolumeIDTemplate,
    /* [out][in] */ DWORD *pNumberOfElementsReturned,
    /* [size_is][out] */ PREAD_ELEMENT_ADDRESS_INFO pElementInformation);


void __RPC_STUB IRmsMoveMedia_QueryVolumeTag_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRmsMoveMedia_INTERFACE_DEFINED__ */


#ifndef __IRmsIEPort_INTERFACE_DEFINED__
#define __IRmsIEPort_INTERFACE_DEFINED__

/* interface IRmsIEPort */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRmsIEPort;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FE37FB08-3729-11D0-8CF4-00A0C9190459")
    IRmsIEPort : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetDescription( 
            /* [string][out][in] */ BSTR *pDesc) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDescription( 
            /* [string][in] */ BSTR desc) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetIsImport( 
            /* [in] */ BOOL flag) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsImport( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetIsExport( 
            /* [in] */ BOOL flag) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsExport( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetWaitTime( 
            /* [out] */ LONG *pTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetWaitTime( 
            /* [in] */ LONG time) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRmsIEPortVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRmsIEPort * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRmsIEPort * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRmsIEPort * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IRmsIEPort * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IRmsIEPort * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IRmsIEPort * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRmsIEPort * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *GetDescription )( 
            IRmsIEPort * This,
            /* [string][out][in] */ BSTR *pDesc);
        
        HRESULT ( STDMETHODCALLTYPE *SetDescription )( 
            IRmsIEPort * This,
            /* [string][in] */ BSTR desc);
        
        HRESULT ( STDMETHODCALLTYPE *SetIsImport )( 
            IRmsIEPort * This,
            /* [in] */ BOOL flag);
        
        HRESULT ( STDMETHODCALLTYPE *IsImport )( 
            IRmsIEPort * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetIsExport )( 
            IRmsIEPort * This,
            /* [in] */ BOOL flag);
        
        HRESULT ( STDMETHODCALLTYPE *IsExport )( 
            IRmsIEPort * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetWaitTime )( 
            IRmsIEPort * This,
            /* [out] */ LONG *pTime);
        
        HRESULT ( STDMETHODCALLTYPE *SetWaitTime )( 
            IRmsIEPort * This,
            /* [in] */ LONG time);
        
        END_INTERFACE
    } IRmsIEPortVtbl;

    interface IRmsIEPort
    {
        CONST_VTBL struct IRmsIEPortVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRmsIEPort_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRmsIEPort_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRmsIEPort_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRmsIEPort_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRmsIEPort_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRmsIEPort_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRmsIEPort_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRmsIEPort_GetDescription(This,pDesc)	\
    (This)->lpVtbl -> GetDescription(This,pDesc)

#define IRmsIEPort_SetDescription(This,desc)	\
    (This)->lpVtbl -> SetDescription(This,desc)

#define IRmsIEPort_SetIsImport(This,flag)	\
    (This)->lpVtbl -> SetIsImport(This,flag)

#define IRmsIEPort_IsImport(This)	\
    (This)->lpVtbl -> IsImport(This)

#define IRmsIEPort_SetIsExport(This,flag)	\
    (This)->lpVtbl -> SetIsExport(This,flag)

#define IRmsIEPort_IsExport(This)	\
    (This)->lpVtbl -> IsExport(This)

#define IRmsIEPort_GetWaitTime(This,pTime)	\
    (This)->lpVtbl -> GetWaitTime(This,pTime)

#define IRmsIEPort_SetWaitTime(This,time)	\
    (This)->lpVtbl -> SetWaitTime(This,time)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRmsIEPort_GetDescription_Proxy( 
    IRmsIEPort * This,
    /* [string][out][in] */ BSTR *pDesc);


void __RPC_STUB IRmsIEPort_GetDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsIEPort_SetDescription_Proxy( 
    IRmsIEPort * This,
    /* [string][in] */ BSTR desc);


void __RPC_STUB IRmsIEPort_SetDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsIEPort_SetIsImport_Proxy( 
    IRmsIEPort * This,
    /* [in] */ BOOL flag);


void __RPC_STUB IRmsIEPort_SetIsImport_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsIEPort_IsImport_Proxy( 
    IRmsIEPort * This);


void __RPC_STUB IRmsIEPort_IsImport_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsIEPort_SetIsExport_Proxy( 
    IRmsIEPort * This,
    /* [in] */ BOOL flag);


void __RPC_STUB IRmsIEPort_SetIsExport_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsIEPort_IsExport_Proxy( 
    IRmsIEPort * This);


void __RPC_STUB IRmsIEPort_IsExport_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsIEPort_GetWaitTime_Proxy( 
    IRmsIEPort * This,
    /* [out] */ LONG *pTime);


void __RPC_STUB IRmsIEPort_GetWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsIEPort_SetWaitTime_Proxy( 
    IRmsIEPort * This,
    /* [in] */ LONG time);


void __RPC_STUB IRmsIEPort_SetWaitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRmsIEPort_INTERFACE_DEFINED__ */


#ifndef __IRmsMediaSet_INTERFACE_DEFINED__
#define __IRmsMediaSet_INTERFACE_DEFINED__

/* interface IRmsMediaSet */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRmsMediaSet;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BC9E7125-0976-4773-9E43-72047FED478C")
    IRmsMediaSet : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetMediaSetId( 
            /* [out] */ GUID *pMediaSetId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetName( 
            /* [string][out][in] */ BSTR *pName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetName( 
            /* [string][in] */ BSTR name) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMediaSupported( 
            /* [out] */ LONG *pType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMediaSupported( 
            /* [in] */ LONG type) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetInfo( 
            /* [size_is][out] */ UCHAR *pInfo,
            /* [out] */ SHORT *pSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetInfo( 
            /* [size_is][in] */ UCHAR *pInfo,
            /* [in] */ SHORT size) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOwnerClassId( 
            /* [out] */ CLSID *pClassId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetOwnerClassId( 
            /* [in] */ CLSID classId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMediaSetType( 
            /* [out] */ LONG *pType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMediaSetType( 
            /* [in] */ LONG type) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMaxCartridges( 
            /* [out] */ LONG *pNum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMaxCartridges( 
            /* [in] */ LONG num) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOccupancy( 
            /* [out] */ LONG *pNum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetOccupancy( 
            /* [in] */ LONG num) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsMediaCopySupported( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetIsMediaCopySupported( 
            /* [in] */ BOOL flag) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Allocate( 
            /* [in] */ REFGUID prevSideId,
            /* [out][in] */ LONGLONG *pFreeSpace,
            /* [string][in] */ BSTR displayName,
            /* [in] */ DWORD options,
            /* [out] */ IRmsCartridge **ppCart) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Deallocate( 
            /* [in] */ IRmsCartridge *pCart) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRmsMediaSetVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRmsMediaSet * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRmsMediaSet * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRmsMediaSet * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IRmsMediaSet * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IRmsMediaSet * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IRmsMediaSet * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRmsMediaSet * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *GetMediaSetId )( 
            IRmsMediaSet * This,
            /* [out] */ GUID *pMediaSetId);
        
        HRESULT ( STDMETHODCALLTYPE *GetName )( 
            IRmsMediaSet * This,
            /* [string][out][in] */ BSTR *pName);
        
        HRESULT ( STDMETHODCALLTYPE *SetName )( 
            IRmsMediaSet * This,
            /* [string][in] */ BSTR name);
        
        HRESULT ( STDMETHODCALLTYPE *GetMediaSupported )( 
            IRmsMediaSet * This,
            /* [out] */ LONG *pType);
        
        HRESULT ( STDMETHODCALLTYPE *SetMediaSupported )( 
            IRmsMediaSet * This,
            /* [in] */ LONG type);
        
        HRESULT ( STDMETHODCALLTYPE *GetInfo )( 
            IRmsMediaSet * This,
            /* [size_is][out] */ UCHAR *pInfo,
            /* [out] */ SHORT *pSize);
        
        HRESULT ( STDMETHODCALLTYPE *SetInfo )( 
            IRmsMediaSet * This,
            /* [size_is][in] */ UCHAR *pInfo,
            /* [in] */ SHORT size);
        
        HRESULT ( STDMETHODCALLTYPE *GetOwnerClassId )( 
            IRmsMediaSet * This,
            /* [out] */ CLSID *pClassId);
        
        HRESULT ( STDMETHODCALLTYPE *SetOwnerClassId )( 
            IRmsMediaSet * This,
            /* [in] */ CLSID classId);
        
        HRESULT ( STDMETHODCALLTYPE *GetMediaSetType )( 
            IRmsMediaSet * This,
            /* [out] */ LONG *pType);
        
        HRESULT ( STDMETHODCALLTYPE *SetMediaSetType )( 
            IRmsMediaSet * This,
            /* [in] */ LONG type);
        
        HRESULT ( STDMETHODCALLTYPE *GetMaxCartridges )( 
            IRmsMediaSet * This,
            /* [out] */ LONG *pNum);
        
        HRESULT ( STDMETHODCALLTYPE *SetMaxCartridges )( 
            IRmsMediaSet * This,
            /* [in] */ LONG num);
        
        HRESULT ( STDMETHODCALLTYPE *GetOccupancy )( 
            IRmsMediaSet * This,
            /* [out] */ LONG *pNum);
        
        HRESULT ( STDMETHODCALLTYPE *SetOccupancy )( 
            IRmsMediaSet * This,
            /* [in] */ LONG num);
        
        HRESULT ( STDMETHODCALLTYPE *IsMediaCopySupported )( 
            IRmsMediaSet * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetIsMediaCopySupported )( 
            IRmsMediaSet * This,
            /* [in] */ BOOL flag);
        
        HRESULT ( STDMETHODCALLTYPE *Allocate )( 
            IRmsMediaSet * This,
            /* [in] */ REFGUID prevSideId,
            /* [out][in] */ LONGLONG *pFreeSpace,
            /* [string][in] */ BSTR displayName,
            /* [in] */ DWORD options,
            /* [out] */ IRmsCartridge **ppCart);
        
        HRESULT ( STDMETHODCALLTYPE *Deallocate )( 
            IRmsMediaSet * This,
            /* [in] */ IRmsCartridge *pCart);
        
        END_INTERFACE
    } IRmsMediaSetVtbl;

    interface IRmsMediaSet
    {
        CONST_VTBL struct IRmsMediaSetVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRmsMediaSet_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRmsMediaSet_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRmsMediaSet_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRmsMediaSet_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRmsMediaSet_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRmsMediaSet_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRmsMediaSet_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRmsMediaSet_GetMediaSetId(This,pMediaSetId)	\
    (This)->lpVtbl -> GetMediaSetId(This,pMediaSetId)

#define IRmsMediaSet_GetName(This,pName)	\
    (This)->lpVtbl -> GetName(This,pName)

#define IRmsMediaSet_SetName(This,name)	\
    (This)->lpVtbl -> SetName(This,name)

#define IRmsMediaSet_GetMediaSupported(This,pType)	\
    (This)->lpVtbl -> GetMediaSupported(This,pType)

#define IRmsMediaSet_SetMediaSupported(This,type)	\
    (This)->lpVtbl -> SetMediaSupported(This,type)

#define IRmsMediaSet_GetInfo(This,pInfo,pSize)	\
    (This)->lpVtbl -> GetInfo(This,pInfo,pSize)

#define IRmsMediaSet_SetInfo(This,pInfo,size)	\
    (This)->lpVtbl -> SetInfo(This,pInfo,size)

#define IRmsMediaSet_GetOwnerClassId(This,pClassId)	\
    (This)->lpVtbl -> GetOwnerClassId(This,pClassId)

#define IRmsMediaSet_SetOwnerClassId(This,classId)	\
    (This)->lpVtbl -> SetOwnerClassId(This,classId)

#define IRmsMediaSet_GetMediaSetType(This,pType)	\
    (This)->lpVtbl -> GetMediaSetType(This,pType)

#define IRmsMediaSet_SetMediaSetType(This,type)	\
    (This)->lpVtbl -> SetMediaSetType(This,type)

#define IRmsMediaSet_GetMaxCartridges(This,pNum)	\
    (This)->lpVtbl -> GetMaxCartridges(This,pNum)

#define IRmsMediaSet_SetMaxCartridges(This,num)	\
    (This)->lpVtbl -> SetMaxCartridges(This,num)

#define IRmsMediaSet_GetOccupancy(This,pNum)	\
    (This)->lpVtbl -> GetOccupancy(This,pNum)

#define IRmsMediaSet_SetOccupancy(This,num)	\
    (This)->lpVtbl -> SetOccupancy(This,num)

#define IRmsMediaSet_IsMediaCopySupported(This)	\
    (This)->lpVtbl -> IsMediaCopySupported(This)

#define IRmsMediaSet_SetIsMediaCopySupported(This,flag)	\
    (This)->lpVtbl -> SetIsMediaCopySupported(This,flag)

#define IRmsMediaSet_Allocate(This,prevSideId,pFreeSpace,displayName,options,ppCart)	\
    (This)->lpVtbl -> Allocate(This,prevSideId,pFreeSpace,displayName,options,ppCart)

#define IRmsMediaSet_Deallocate(This,pCart)	\
    (This)->lpVtbl -> Deallocate(This,pCart)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRmsMediaSet_GetMediaSetId_Proxy( 
    IRmsMediaSet * This,
    /* [out] */ GUID *pMediaSetId);


void __RPC_STUB IRmsMediaSet_GetMediaSetId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsMediaSet_GetName_Proxy( 
    IRmsMediaSet * This,
    /* [string][out][in] */ BSTR *pName);


void __RPC_STUB IRmsMediaSet_GetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsMediaSet_SetName_Proxy( 
    IRmsMediaSet * This,
    /* [string][in] */ BSTR name);


void __RPC_STUB IRmsMediaSet_SetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsMediaSet_GetMediaSupported_Proxy( 
    IRmsMediaSet * This,
    /* [out] */ LONG *pType);


void __RPC_STUB IRmsMediaSet_GetMediaSupported_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsMediaSet_SetMediaSupported_Proxy( 
    IRmsMediaSet * This,
    /* [in] */ LONG type);


void __RPC_STUB IRmsMediaSet_SetMediaSupported_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsMediaSet_GetInfo_Proxy( 
    IRmsMediaSet * This,
    /* [size_is][out] */ UCHAR *pInfo,
    /* [out] */ SHORT *pSize);


void __RPC_STUB IRmsMediaSet_GetInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsMediaSet_SetInfo_Proxy( 
    IRmsMediaSet * This,
    /* [size_is][in] */ UCHAR *pInfo,
    /* [in] */ SHORT size);


void __RPC_STUB IRmsMediaSet_SetInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsMediaSet_GetOwnerClassId_Proxy( 
    IRmsMediaSet * This,
    /* [out] */ CLSID *pClassId);


void __RPC_STUB IRmsMediaSet_GetOwnerClassId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsMediaSet_SetOwnerClassId_Proxy( 
    IRmsMediaSet * This,
    /* [in] */ CLSID classId);


void __RPC_STUB IRmsMediaSet_SetOwnerClassId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsMediaSet_GetMediaSetType_Proxy( 
    IRmsMediaSet * This,
    /* [out] */ LONG *pType);


void __RPC_STUB IRmsMediaSet_GetMediaSetType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsMediaSet_SetMediaSetType_Proxy( 
    IRmsMediaSet * This,
    /* [in] */ LONG type);


void __RPC_STUB IRmsMediaSet_SetMediaSetType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsMediaSet_GetMaxCartridges_Proxy( 
    IRmsMediaSet * This,
    /* [out] */ LONG *pNum);


void __RPC_STUB IRmsMediaSet_GetMaxCartridges_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsMediaSet_SetMaxCartridges_Proxy( 
    IRmsMediaSet * This,
    /* [in] */ LONG num);


void __RPC_STUB IRmsMediaSet_SetMaxCartridges_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsMediaSet_GetOccupancy_Proxy( 
    IRmsMediaSet * This,
    /* [out] */ LONG *pNum);


void __RPC_STUB IRmsMediaSet_GetOccupancy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsMediaSet_SetOccupancy_Proxy( 
    IRmsMediaSet * This,
    /* [in] */ LONG num);


void __RPC_STUB IRmsMediaSet_SetOccupancy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsMediaSet_IsMediaCopySupported_Proxy( 
    IRmsMediaSet * This);


void __RPC_STUB IRmsMediaSet_IsMediaCopySupported_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsMediaSet_SetIsMediaCopySupported_Proxy( 
    IRmsMediaSet * This,
    /* [in] */ BOOL flag);


void __RPC_STUB IRmsMediaSet_SetIsMediaCopySupported_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsMediaSet_Allocate_Proxy( 
    IRmsMediaSet * This,
    /* [in] */ REFGUID prevSideId,
    /* [out][in] */ LONGLONG *pFreeSpace,
    /* [string][in] */ BSTR displayName,
    /* [in] */ DWORD options,
    /* [out] */ IRmsCartridge **ppCart);


void __RPC_STUB IRmsMediaSet_Allocate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsMediaSet_Deallocate_Proxy( 
    IRmsMediaSet * This,
    /* [in] */ IRmsCartridge *pCart);


void __RPC_STUB IRmsMediaSet_Deallocate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRmsMediaSet_INTERFACE_DEFINED__ */


#ifndef __IRmsRequest_INTERFACE_DEFINED__
#define __IRmsRequest_INTERFACE_DEFINED__

/* interface IRmsRequest */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRmsRequest;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FE37FB10-3729-11D0-8CF4-00A0C9190459")
    IRmsRequest : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetRequestNo( 
            /* [out] */ LONG *pRequestNo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRequestDescription( 
            /* [string][out][in] */ BSTR *pDesc) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRequestDescription( 
            /* [string][in] */ BSTR desc) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetIsDone( 
            /* [in] */ BOOL flag) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsDone( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOperation( 
            /* [string][out][in] */ BSTR *pOperation) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetOperation( 
            /* [string][in] */ BSTR operation) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPercentComplete( 
            /* [out] */ BYTE *pPercent) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPercentComplete( 
            /* [in] */ BYTE percent) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRmsRequestVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRmsRequest * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRmsRequest * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRmsRequest * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IRmsRequest * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IRmsRequest * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IRmsRequest * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRmsRequest * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *GetRequestNo )( 
            IRmsRequest * This,
            /* [out] */ LONG *pRequestNo);
        
        HRESULT ( STDMETHODCALLTYPE *GetRequestDescription )( 
            IRmsRequest * This,
            /* [string][out][in] */ BSTR *pDesc);
        
        HRESULT ( STDMETHODCALLTYPE *SetRequestDescription )( 
            IRmsRequest * This,
            /* [string][in] */ BSTR desc);
        
        HRESULT ( STDMETHODCALLTYPE *SetIsDone )( 
            IRmsRequest * This,
            /* [in] */ BOOL flag);
        
        HRESULT ( STDMETHODCALLTYPE *IsDone )( 
            IRmsRequest * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetOperation )( 
            IRmsRequest * This,
            /* [string][out][in] */ BSTR *pOperation);
        
        HRESULT ( STDMETHODCALLTYPE *SetOperation )( 
            IRmsRequest * This,
            /* [string][in] */ BSTR operation);
        
        HRESULT ( STDMETHODCALLTYPE *GetPercentComplete )( 
            IRmsRequest * This,
            /* [out] */ BYTE *pPercent);
        
        HRESULT ( STDMETHODCALLTYPE *SetPercentComplete )( 
            IRmsRequest * This,
            /* [in] */ BYTE percent);
        
        END_INTERFACE
    } IRmsRequestVtbl;

    interface IRmsRequest
    {
        CONST_VTBL struct IRmsRequestVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRmsRequest_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRmsRequest_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRmsRequest_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRmsRequest_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRmsRequest_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRmsRequest_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRmsRequest_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRmsRequest_GetRequestNo(This,pRequestNo)	\
    (This)->lpVtbl -> GetRequestNo(This,pRequestNo)

#define IRmsRequest_GetRequestDescription(This,pDesc)	\
    (This)->lpVtbl -> GetRequestDescription(This,pDesc)

#define IRmsRequest_SetRequestDescription(This,desc)	\
    (This)->lpVtbl -> SetRequestDescription(This,desc)

#define IRmsRequest_SetIsDone(This,flag)	\
    (This)->lpVtbl -> SetIsDone(This,flag)

#define IRmsRequest_IsDone(This)	\
    (This)->lpVtbl -> IsDone(This)

#define IRmsRequest_GetOperation(This,pOperation)	\
    (This)->lpVtbl -> GetOperation(This,pOperation)

#define IRmsRequest_SetOperation(This,operation)	\
    (This)->lpVtbl -> SetOperation(This,operation)

#define IRmsRequest_GetPercentComplete(This,pPercent)	\
    (This)->lpVtbl -> GetPercentComplete(This,pPercent)

#define IRmsRequest_SetPercentComplete(This,percent)	\
    (This)->lpVtbl -> SetPercentComplete(This,percent)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRmsRequest_GetRequestNo_Proxy( 
    IRmsRequest * This,
    /* [out] */ LONG *pRequestNo);


void __RPC_STUB IRmsRequest_GetRequestNo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsRequest_GetRequestDescription_Proxy( 
    IRmsRequest * This,
    /* [string][out][in] */ BSTR *pDesc);


void __RPC_STUB IRmsRequest_GetRequestDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsRequest_SetRequestDescription_Proxy( 
    IRmsRequest * This,
    /* [string][in] */ BSTR desc);


void __RPC_STUB IRmsRequest_SetRequestDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsRequest_SetIsDone_Proxy( 
    IRmsRequest * This,
    /* [in] */ BOOL flag);


void __RPC_STUB IRmsRequest_SetIsDone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsRequest_IsDone_Proxy( 
    IRmsRequest * This);


void __RPC_STUB IRmsRequest_IsDone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsRequest_GetOperation_Proxy( 
    IRmsRequest * This,
    /* [string][out][in] */ BSTR *pOperation);


void __RPC_STUB IRmsRequest_GetOperation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsRequest_SetOperation_Proxy( 
    IRmsRequest * This,
    /* [string][in] */ BSTR operation);


void __RPC_STUB IRmsRequest_SetOperation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsRequest_GetPercentComplete_Proxy( 
    IRmsRequest * This,
    /* [out] */ BYTE *pPercent);


void __RPC_STUB IRmsRequest_GetPercentComplete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsRequest_SetPercentComplete_Proxy( 
    IRmsRequest * This,
    /* [in] */ BYTE percent);


void __RPC_STUB IRmsRequest_SetPercentComplete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRmsRequest_INTERFACE_DEFINED__ */


#ifndef __IRmsPartition_INTERFACE_DEFINED__
#define __IRmsPartition_INTERFACE_DEFINED__

/* interface IRmsPartition */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRmsPartition;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FE37FB11-3729-11D0-8CF4-00A0C9190459")
    IRmsPartition : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetPartNo( 
            /* [out] */ LONG *pPartNo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAttributes( 
            /* [out] */ LONG *pAttr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAttributes( 
            /* [in] */ LONG attr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIdentifier( 
            /* [size_is][out] */ UCHAR *pIdent,
            /* [out] */ SHORT *pSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetIdentifier( 
            /* [size_is][in] */ UCHAR *pIdent,
            /* [in] */ SHORT size) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE VerifyIdentifier( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReadOnMediaId( 
            /* [size_is][out] */ UCHAR *pId,
            /* [out] */ LONG *pSize) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRmsPartitionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRmsPartition * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRmsPartition * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRmsPartition * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IRmsPartition * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IRmsPartition * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IRmsPartition * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRmsPartition * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *GetPartNo )( 
            IRmsPartition * This,
            /* [out] */ LONG *pPartNo);
        
        HRESULT ( STDMETHODCALLTYPE *GetAttributes )( 
            IRmsPartition * This,
            /* [out] */ LONG *pAttr);
        
        HRESULT ( STDMETHODCALLTYPE *SetAttributes )( 
            IRmsPartition * This,
            /* [in] */ LONG attr);
        
        HRESULT ( STDMETHODCALLTYPE *GetIdentifier )( 
            IRmsPartition * This,
            /* [size_is][out] */ UCHAR *pIdent,
            /* [out] */ SHORT *pSize);
        
        HRESULT ( STDMETHODCALLTYPE *SetIdentifier )( 
            IRmsPartition * This,
            /* [size_is][in] */ UCHAR *pIdent,
            /* [in] */ SHORT size);
        
        HRESULT ( STDMETHODCALLTYPE *VerifyIdentifier )( 
            IRmsPartition * This);
        
        HRESULT ( STDMETHODCALLTYPE *ReadOnMediaId )( 
            IRmsPartition * This,
            /* [size_is][out] */ UCHAR *pId,
            /* [out] */ LONG *pSize);
        
        END_INTERFACE
    } IRmsPartitionVtbl;

    interface IRmsPartition
    {
        CONST_VTBL struct IRmsPartitionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRmsPartition_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRmsPartition_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRmsPartition_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRmsPartition_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRmsPartition_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRmsPartition_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRmsPartition_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRmsPartition_GetPartNo(This,pPartNo)	\
    (This)->lpVtbl -> GetPartNo(This,pPartNo)

#define IRmsPartition_GetAttributes(This,pAttr)	\
    (This)->lpVtbl -> GetAttributes(This,pAttr)

#define IRmsPartition_SetAttributes(This,attr)	\
    (This)->lpVtbl -> SetAttributes(This,attr)

#define IRmsPartition_GetIdentifier(This,pIdent,pSize)	\
    (This)->lpVtbl -> GetIdentifier(This,pIdent,pSize)

#define IRmsPartition_SetIdentifier(This,pIdent,size)	\
    (This)->lpVtbl -> SetIdentifier(This,pIdent,size)

#define IRmsPartition_VerifyIdentifier(This)	\
    (This)->lpVtbl -> VerifyIdentifier(This)

#define IRmsPartition_ReadOnMediaId(This,pId,pSize)	\
    (This)->lpVtbl -> ReadOnMediaId(This,pId,pSize)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRmsPartition_GetPartNo_Proxy( 
    IRmsPartition * This,
    /* [out] */ LONG *pPartNo);


void __RPC_STUB IRmsPartition_GetPartNo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsPartition_GetAttributes_Proxy( 
    IRmsPartition * This,
    /* [out] */ LONG *pAttr);


void __RPC_STUB IRmsPartition_GetAttributes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsPartition_SetAttributes_Proxy( 
    IRmsPartition * This,
    /* [in] */ LONG attr);


void __RPC_STUB IRmsPartition_SetAttributes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsPartition_GetIdentifier_Proxy( 
    IRmsPartition * This,
    /* [size_is][out] */ UCHAR *pIdent,
    /* [out] */ SHORT *pSize);


void __RPC_STUB IRmsPartition_GetIdentifier_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsPartition_SetIdentifier_Proxy( 
    IRmsPartition * This,
    /* [size_is][in] */ UCHAR *pIdent,
    /* [in] */ SHORT size);


void __RPC_STUB IRmsPartition_SetIdentifier_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsPartition_VerifyIdentifier_Proxy( 
    IRmsPartition * This);


void __RPC_STUB IRmsPartition_VerifyIdentifier_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsPartition_ReadOnMediaId_Proxy( 
    IRmsPartition * This,
    /* [size_is][out] */ UCHAR *pId,
    /* [out] */ LONG *pSize);


void __RPC_STUB IRmsPartition_ReadOnMediaId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRmsPartition_INTERFACE_DEFINED__ */


#ifndef __IRmsComObject_INTERFACE_DEFINED__
#define __IRmsComObject_INTERFACE_DEFINED__

/* interface IRmsComObject */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRmsComObject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FE37FB12-3729-11D0-8CF4-00A0C9190459")
    IRmsComObject : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetObjectId( 
            /* [out] */ GUID *pObjectId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetObjectId( 
            /* [in] */ GUID objectId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetObjectType( 
            /* [out] */ LONG *pType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetObjectType( 
            /* [in] */ LONG type) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsEnabled( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Enable( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Disable( 
            /* [in] */ HRESULT reason) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetState( 
            /* [out] */ LONG *pState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetState( 
            /* [in] */ LONG state) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStatusCode( 
            /* [out] */ HRESULT *pResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetStatusCode( 
            /* [in] */ HRESULT result) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetName( 
            /* [string][out][in] */ BSTR *pName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetName( 
            /* [string][in] */ BSTR name) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDescription( 
            /* [string][out][in] */ BSTR *pDesc) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDescription( 
            /* [string][in] */ BSTR desc) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFindBy( 
            /* [out] */ LONG *pFindBy) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFindBy( 
            /* [in] */ LONG findby) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRmsComObjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRmsComObject * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRmsComObject * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRmsComObject * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IRmsComObject * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IRmsComObject * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IRmsComObject * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRmsComObject * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *GetObjectId )( 
            IRmsComObject * This,
            /* [out] */ GUID *pObjectId);
        
        HRESULT ( STDMETHODCALLTYPE *SetObjectId )( 
            IRmsComObject * This,
            /* [in] */ GUID objectId);
        
        HRESULT ( STDMETHODCALLTYPE *GetObjectType )( 
            IRmsComObject * This,
            /* [out] */ LONG *pType);
        
        HRESULT ( STDMETHODCALLTYPE *SetObjectType )( 
            IRmsComObject * This,
            /* [in] */ LONG type);
        
        HRESULT ( STDMETHODCALLTYPE *IsEnabled )( 
            IRmsComObject * This);
        
        HRESULT ( STDMETHODCALLTYPE *Enable )( 
            IRmsComObject * This);
        
        HRESULT ( STDMETHODCALLTYPE *Disable )( 
            IRmsComObject * This,
            /* [in] */ HRESULT reason);
        
        HRESULT ( STDMETHODCALLTYPE *GetState )( 
            IRmsComObject * This,
            /* [out] */ LONG *pState);
        
        HRESULT ( STDMETHODCALLTYPE *SetState )( 
            IRmsComObject * This,
            /* [in] */ LONG state);
        
        HRESULT ( STDMETHODCALLTYPE *GetStatusCode )( 
            IRmsComObject * This,
            /* [out] */ HRESULT *pResult);
        
        HRESULT ( STDMETHODCALLTYPE *SetStatusCode )( 
            IRmsComObject * This,
            /* [in] */ HRESULT result);
        
        HRESULT ( STDMETHODCALLTYPE *GetName )( 
            IRmsComObject * This,
            /* [string][out][in] */ BSTR *pName);
        
        HRESULT ( STDMETHODCALLTYPE *SetName )( 
            IRmsComObject * This,
            /* [string][in] */ BSTR name);
        
        HRESULT ( STDMETHODCALLTYPE *GetDescription )( 
            IRmsComObject * This,
            /* [string][out][in] */ BSTR *pDesc);
        
        HRESULT ( STDMETHODCALLTYPE *SetDescription )( 
            IRmsComObject * This,
            /* [string][in] */ BSTR desc);
        
        HRESULT ( STDMETHODCALLTYPE *GetFindBy )( 
            IRmsComObject * This,
            /* [out] */ LONG *pFindBy);
        
        HRESULT ( STDMETHODCALLTYPE *SetFindBy )( 
            IRmsComObject * This,
            /* [in] */ LONG findby);
        
        END_INTERFACE
    } IRmsComObjectVtbl;

    interface IRmsComObject
    {
        CONST_VTBL struct IRmsComObjectVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRmsComObject_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRmsComObject_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRmsComObject_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRmsComObject_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRmsComObject_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRmsComObject_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRmsComObject_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRmsComObject_GetObjectId(This,pObjectId)	\
    (This)->lpVtbl -> GetObjectId(This,pObjectId)

#define IRmsComObject_SetObjectId(This,objectId)	\
    (This)->lpVtbl -> SetObjectId(This,objectId)

#define IRmsComObject_GetObjectType(This,pType)	\
    (This)->lpVtbl -> GetObjectType(This,pType)

#define IRmsComObject_SetObjectType(This,type)	\
    (This)->lpVtbl -> SetObjectType(This,type)

#define IRmsComObject_IsEnabled(This)	\
    (This)->lpVtbl -> IsEnabled(This)

#define IRmsComObject_Enable(This)	\
    (This)->lpVtbl -> Enable(This)

#define IRmsComObject_Disable(This,reason)	\
    (This)->lpVtbl -> Disable(This,reason)

#define IRmsComObject_GetState(This,pState)	\
    (This)->lpVtbl -> GetState(This,pState)

#define IRmsComObject_SetState(This,state)	\
    (This)->lpVtbl -> SetState(This,state)

#define IRmsComObject_GetStatusCode(This,pResult)	\
    (This)->lpVtbl -> GetStatusCode(This,pResult)

#define IRmsComObject_SetStatusCode(This,result)	\
    (This)->lpVtbl -> SetStatusCode(This,result)

#define IRmsComObject_GetName(This,pName)	\
    (This)->lpVtbl -> GetName(This,pName)

#define IRmsComObject_SetName(This,name)	\
    (This)->lpVtbl -> SetName(This,name)

#define IRmsComObject_GetDescription(This,pDesc)	\
    (This)->lpVtbl -> GetDescription(This,pDesc)

#define IRmsComObject_SetDescription(This,desc)	\
    (This)->lpVtbl -> SetDescription(This,desc)

#define IRmsComObject_GetFindBy(This,pFindBy)	\
    (This)->lpVtbl -> GetFindBy(This,pFindBy)

#define IRmsComObject_SetFindBy(This,findby)	\
    (This)->lpVtbl -> SetFindBy(This,findby)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRmsComObject_GetObjectId_Proxy( 
    IRmsComObject * This,
    /* [out] */ GUID *pObjectId);


void __RPC_STUB IRmsComObject_GetObjectId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsComObject_SetObjectId_Proxy( 
    IRmsComObject * This,
    /* [in] */ GUID objectId);


void __RPC_STUB IRmsComObject_SetObjectId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsComObject_GetObjectType_Proxy( 
    IRmsComObject * This,
    /* [out] */ LONG *pType);


void __RPC_STUB IRmsComObject_GetObjectType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsComObject_SetObjectType_Proxy( 
    IRmsComObject * This,
    /* [in] */ LONG type);


void __RPC_STUB IRmsComObject_SetObjectType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsComObject_IsEnabled_Proxy( 
    IRmsComObject * This);


void __RPC_STUB IRmsComObject_IsEnabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsComObject_Enable_Proxy( 
    IRmsComObject * This);


void __RPC_STUB IRmsComObject_Enable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsComObject_Disable_Proxy( 
    IRmsComObject * This,
    /* [in] */ HRESULT reason);


void __RPC_STUB IRmsComObject_Disable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsComObject_GetState_Proxy( 
    IRmsComObject * This,
    /* [out] */ LONG *pState);


void __RPC_STUB IRmsComObject_GetState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsComObject_SetState_Proxy( 
    IRmsComObject * This,
    /* [in] */ LONG state);


void __RPC_STUB IRmsComObject_SetState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsComObject_GetStatusCode_Proxy( 
    IRmsComObject * This,
    /* [out] */ HRESULT *pResult);


void __RPC_STUB IRmsComObject_GetStatusCode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsComObject_SetStatusCode_Proxy( 
    IRmsComObject * This,
    /* [in] */ HRESULT result);


void __RPC_STUB IRmsComObject_SetStatusCode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsComObject_GetName_Proxy( 
    IRmsComObject * This,
    /* [string][out][in] */ BSTR *pName);


void __RPC_STUB IRmsComObject_GetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsComObject_SetName_Proxy( 
    IRmsComObject * This,
    /* [string][in] */ BSTR name);


void __RPC_STUB IRmsComObject_SetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsComObject_GetDescription_Proxy( 
    IRmsComObject * This,
    /* [string][out][in] */ BSTR *pDesc);


void __RPC_STUB IRmsComObject_GetDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsComObject_SetDescription_Proxy( 
    IRmsComObject * This,
    /* [string][in] */ BSTR desc);


void __RPC_STUB IRmsComObject_SetDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsComObject_GetFindBy_Proxy( 
    IRmsComObject * This,
    /* [out] */ LONG *pFindBy);


void __RPC_STUB IRmsComObject_GetFindBy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsComObject_SetFindBy_Proxy( 
    IRmsComObject * This,
    /* [in] */ LONG findby);


void __RPC_STUB IRmsComObject_SetFindBy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRmsComObject_INTERFACE_DEFINED__ */


#ifndef __IRmsChangerElement_INTERFACE_DEFINED__
#define __IRmsChangerElement_INTERFACE_DEFINED__

/* interface IRmsChangerElement */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRmsChangerElement;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FE37FB13-3729-11D0-8CF4-00A0C9190459")
    IRmsChangerElement : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetElementNo( 
            /* [out] */ LONG *pElementNo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLocation( 
            /* [unique][out][in] */ LONG *pType,
            /* [unique][out][in] */ GUID *pLibId,
            /* [unique][out][in] */ GUID *pMediaSetId,
            /* [unique][out][in] */ LONG *pPos,
            /* [unique][out][in] */ LONG *pAlt1,
            /* [unique][out][in] */ LONG *pAlt2,
            /* [unique][out][in] */ LONG *pAlt3,
            /* [unique][out][in] */ BOOL *pInvert) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetLocation( 
            /* [in] */ LONG type,
            /* [in] */ GUID libId,
            /* [in] */ GUID mediaSetId,
            /* [in] */ LONG pos,
            /* [in] */ LONG alt1,
            /* [in] */ LONG alt2,
            /* [in] */ LONG alt3,
            /* [in] */ BOOL invert) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMediaSupported( 
            /* [out] */ LONG *pType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMediaSupported( 
            /* [in] */ LONG type) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetIsStorage( 
            /* [in] */ BOOL flag) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsStorage( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetIsOccupied( 
            /* [in] */ BOOL flag) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsOccupied( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCartridge( 
            /* [out] */ IRmsCartridge **ptr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCartridge( 
            /* [in] */ IRmsCartridge *ptr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOwnerClassId( 
            /* [out] */ CLSID *pClassId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetOwnerClassId( 
            /* [in] */ CLSID classId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAccessCounters( 
            /* [out] */ LONG *pGets,
            /* [out] */ LONG *pPuts) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ResetAccessCounters( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCoordinates( 
            /* [out] */ LONG *pX1,
            /* [out] */ LONG *pX2,
            /* [out] */ LONG *pX3) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCoordinates( 
            /* [in] */ LONG x1,
            /* [in] */ LONG x2,
            /* [in] */ LONG x3) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRmsChangerElementVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRmsChangerElement * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRmsChangerElement * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRmsChangerElement * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IRmsChangerElement * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IRmsChangerElement * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IRmsChangerElement * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRmsChangerElement * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *GetElementNo )( 
            IRmsChangerElement * This,
            /* [out] */ LONG *pElementNo);
        
        HRESULT ( STDMETHODCALLTYPE *GetLocation )( 
            IRmsChangerElement * This,
            /* [unique][out][in] */ LONG *pType,
            /* [unique][out][in] */ GUID *pLibId,
            /* [unique][out][in] */ GUID *pMediaSetId,
            /* [unique][out][in] */ LONG *pPos,
            /* [unique][out][in] */ LONG *pAlt1,
            /* [unique][out][in] */ LONG *pAlt2,
            /* [unique][out][in] */ LONG *pAlt3,
            /* [unique][out][in] */ BOOL *pInvert);
        
        HRESULT ( STDMETHODCALLTYPE *SetLocation )( 
            IRmsChangerElement * This,
            /* [in] */ LONG type,
            /* [in] */ GUID libId,
            /* [in] */ GUID mediaSetId,
            /* [in] */ LONG pos,
            /* [in] */ LONG alt1,
            /* [in] */ LONG alt2,
            /* [in] */ LONG alt3,
            /* [in] */ BOOL invert);
        
        HRESULT ( STDMETHODCALLTYPE *GetMediaSupported )( 
            IRmsChangerElement * This,
            /* [out] */ LONG *pType);
        
        HRESULT ( STDMETHODCALLTYPE *SetMediaSupported )( 
            IRmsChangerElement * This,
            /* [in] */ LONG type);
        
        HRESULT ( STDMETHODCALLTYPE *SetIsStorage )( 
            IRmsChangerElement * This,
            /* [in] */ BOOL flag);
        
        HRESULT ( STDMETHODCALLTYPE *IsStorage )( 
            IRmsChangerElement * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetIsOccupied )( 
            IRmsChangerElement * This,
            /* [in] */ BOOL flag);
        
        HRESULT ( STDMETHODCALLTYPE *IsOccupied )( 
            IRmsChangerElement * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetCartridge )( 
            IRmsChangerElement * This,
            /* [out] */ IRmsCartridge **ptr);
        
        HRESULT ( STDMETHODCALLTYPE *SetCartridge )( 
            IRmsChangerElement * This,
            /* [in] */ IRmsCartridge *ptr);
        
        HRESULT ( STDMETHODCALLTYPE *GetOwnerClassId )( 
            IRmsChangerElement * This,
            /* [out] */ CLSID *pClassId);
        
        HRESULT ( STDMETHODCALLTYPE *SetOwnerClassId )( 
            IRmsChangerElement * This,
            /* [in] */ CLSID classId);
        
        HRESULT ( STDMETHODCALLTYPE *GetAccessCounters )( 
            IRmsChangerElement * This,
            /* [out] */ LONG *pGets,
            /* [out] */ LONG *pPuts);
        
        HRESULT ( STDMETHODCALLTYPE *ResetAccessCounters )( 
            IRmsChangerElement * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetCoordinates )( 
            IRmsChangerElement * This,
            /* [out] */ LONG *pX1,
            /* [out] */ LONG *pX2,
            /* [out] */ LONG *pX3);
        
        HRESULT ( STDMETHODCALLTYPE *SetCoordinates )( 
            IRmsChangerElement * This,
            /* [in] */ LONG x1,
            /* [in] */ LONG x2,
            /* [in] */ LONG x3);
        
        END_INTERFACE
    } IRmsChangerElementVtbl;

    interface IRmsChangerElement
    {
        CONST_VTBL struct IRmsChangerElementVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRmsChangerElement_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRmsChangerElement_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRmsChangerElement_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRmsChangerElement_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRmsChangerElement_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRmsChangerElement_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRmsChangerElement_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRmsChangerElement_GetElementNo(This,pElementNo)	\
    (This)->lpVtbl -> GetElementNo(This,pElementNo)

#define IRmsChangerElement_GetLocation(This,pType,pLibId,pMediaSetId,pPos,pAlt1,pAlt2,pAlt3,pInvert)	\
    (This)->lpVtbl -> GetLocation(This,pType,pLibId,pMediaSetId,pPos,pAlt1,pAlt2,pAlt3,pInvert)

#define IRmsChangerElement_SetLocation(This,type,libId,mediaSetId,pos,alt1,alt2,alt3,invert)	\
    (This)->lpVtbl -> SetLocation(This,type,libId,mediaSetId,pos,alt1,alt2,alt3,invert)

#define IRmsChangerElement_GetMediaSupported(This,pType)	\
    (This)->lpVtbl -> GetMediaSupported(This,pType)

#define IRmsChangerElement_SetMediaSupported(This,type)	\
    (This)->lpVtbl -> SetMediaSupported(This,type)

#define IRmsChangerElement_SetIsStorage(This,flag)	\
    (This)->lpVtbl -> SetIsStorage(This,flag)

#define IRmsChangerElement_IsStorage(This)	\
    (This)->lpVtbl -> IsStorage(This)

#define IRmsChangerElement_SetIsOccupied(This,flag)	\
    (This)->lpVtbl -> SetIsOccupied(This,flag)

#define IRmsChangerElement_IsOccupied(This)	\
    (This)->lpVtbl -> IsOccupied(This)

#define IRmsChangerElement_GetCartridge(This,ptr)	\
    (This)->lpVtbl -> GetCartridge(This,ptr)

#define IRmsChangerElement_SetCartridge(This,ptr)	\
    (This)->lpVtbl -> SetCartridge(This,ptr)

#define IRmsChangerElement_GetOwnerClassId(This,pClassId)	\
    (This)->lpVtbl -> GetOwnerClassId(This,pClassId)

#define IRmsChangerElement_SetOwnerClassId(This,classId)	\
    (This)->lpVtbl -> SetOwnerClassId(This,classId)

#define IRmsChangerElement_GetAccessCounters(This,pGets,pPuts)	\
    (This)->lpVtbl -> GetAccessCounters(This,pGets,pPuts)

#define IRmsChangerElement_ResetAccessCounters(This)	\
    (This)->lpVtbl -> ResetAccessCounters(This)

#define IRmsChangerElement_GetCoordinates(This,pX1,pX2,pX3)	\
    (This)->lpVtbl -> GetCoordinates(This,pX1,pX2,pX3)

#define IRmsChangerElement_SetCoordinates(This,x1,x2,x3)	\
    (This)->lpVtbl -> SetCoordinates(This,x1,x2,x3)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRmsChangerElement_GetElementNo_Proxy( 
    IRmsChangerElement * This,
    /* [out] */ LONG *pElementNo);


void __RPC_STUB IRmsChangerElement_GetElementNo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsChangerElement_GetLocation_Proxy( 
    IRmsChangerElement * This,
    /* [unique][out][in] */ LONG *pType,
    /* [unique][out][in] */ GUID *pLibId,
    /* [unique][out][in] */ GUID *pMediaSetId,
    /* [unique][out][in] */ LONG *pPos,
    /* [unique][out][in] */ LONG *pAlt1,
    /* [unique][out][in] */ LONG *pAlt2,
    /* [unique][out][in] */ LONG *pAlt3,
    /* [unique][out][in] */ BOOL *pInvert);


void __RPC_STUB IRmsChangerElement_GetLocation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsChangerElement_SetLocation_Proxy( 
    IRmsChangerElement * This,
    /* [in] */ LONG type,
    /* [in] */ GUID libId,
    /* [in] */ GUID mediaSetId,
    /* [in] */ LONG pos,
    /* [in] */ LONG alt1,
    /* [in] */ LONG alt2,
    /* [in] */ LONG alt3,
    /* [in] */ BOOL invert);


void __RPC_STUB IRmsChangerElement_SetLocation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsChangerElement_GetMediaSupported_Proxy( 
    IRmsChangerElement * This,
    /* [out] */ LONG *pType);


void __RPC_STUB IRmsChangerElement_GetMediaSupported_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsChangerElement_SetMediaSupported_Proxy( 
    IRmsChangerElement * This,
    /* [in] */ LONG type);


void __RPC_STUB IRmsChangerElement_SetMediaSupported_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsChangerElement_SetIsStorage_Proxy( 
    IRmsChangerElement * This,
    /* [in] */ BOOL flag);


void __RPC_STUB IRmsChangerElement_SetIsStorage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsChangerElement_IsStorage_Proxy( 
    IRmsChangerElement * This);


void __RPC_STUB IRmsChangerElement_IsStorage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsChangerElement_SetIsOccupied_Proxy( 
    IRmsChangerElement * This,
    /* [in] */ BOOL flag);


void __RPC_STUB IRmsChangerElement_SetIsOccupied_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsChangerElement_IsOccupied_Proxy( 
    IRmsChangerElement * This);


void __RPC_STUB IRmsChangerElement_IsOccupied_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsChangerElement_GetCartridge_Proxy( 
    IRmsChangerElement * This,
    /* [out] */ IRmsCartridge **ptr);


void __RPC_STUB IRmsChangerElement_GetCartridge_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsChangerElement_SetCartridge_Proxy( 
    IRmsChangerElement * This,
    /* [in] */ IRmsCartridge *ptr);


void __RPC_STUB IRmsChangerElement_SetCartridge_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsChangerElement_GetOwnerClassId_Proxy( 
    IRmsChangerElement * This,
    /* [out] */ CLSID *pClassId);


void __RPC_STUB IRmsChangerElement_GetOwnerClassId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsChangerElement_SetOwnerClassId_Proxy( 
    IRmsChangerElement * This,
    /* [in] */ CLSID classId);


void __RPC_STUB IRmsChangerElement_SetOwnerClassId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsChangerElement_GetAccessCounters_Proxy( 
    IRmsChangerElement * This,
    /* [out] */ LONG *pGets,
    /* [out] */ LONG *pPuts);


void __RPC_STUB IRmsChangerElement_GetAccessCounters_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsChangerElement_ResetAccessCounters_Proxy( 
    IRmsChangerElement * This);


void __RPC_STUB IRmsChangerElement_ResetAccessCounters_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsChangerElement_GetCoordinates_Proxy( 
    IRmsChangerElement * This,
    /* [out] */ LONG *pX1,
    /* [out] */ LONG *pX2,
    /* [out] */ LONG *pX3);


void __RPC_STUB IRmsChangerElement_GetCoordinates_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsChangerElement_SetCoordinates_Proxy( 
    IRmsChangerElement * This,
    /* [in] */ LONG x1,
    /* [in] */ LONG x2,
    /* [in] */ LONG x3);


void __RPC_STUB IRmsChangerElement_SetCoordinates_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRmsChangerElement_INTERFACE_DEFINED__ */


#ifndef __IRmsDevice_INTERFACE_DEFINED__
#define __IRmsDevice_INTERFACE_DEFINED__

/* interface IRmsDevice */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRmsDevice;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FE37FB14-3729-11D0-8CF4-00A0C9190459")
    IRmsDevice : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetDeviceName( 
            /* [string][out][in] */ BSTR *pName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDeviceName( 
            /* [string][in] */ BSTR name) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDeviceType( 
            /* [out] */ LONG *pType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDeviceType( 
            /* [in] */ LONG type) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDeviceInfo( 
            /* [size_is][out] */ UCHAR *pId,
            /* [out] */ SHORT *pSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDeviceInfo( 
            /* [size_is][in] */ UCHAR *pId,
            /* [in] */ SHORT size) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDeviceAddress( 
            /* [out] */ BYTE *pPort,
            /* [out] */ BYTE *pBus,
            /* [out] */ BYTE *pId,
            /* [out] */ BYTE *pLun) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDeviceAddress( 
            /* [in] */ BYTE port,
            /* [in] */ BYTE bus,
            /* [in] */ BYTE id,
            /* [in] */ BYTE lun) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRmsDeviceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRmsDevice * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRmsDevice * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRmsDevice * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IRmsDevice * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IRmsDevice * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IRmsDevice * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRmsDevice * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *GetDeviceName )( 
            IRmsDevice * This,
            /* [string][out][in] */ BSTR *pName);
        
        HRESULT ( STDMETHODCALLTYPE *SetDeviceName )( 
            IRmsDevice * This,
            /* [string][in] */ BSTR name);
        
        HRESULT ( STDMETHODCALLTYPE *GetDeviceType )( 
            IRmsDevice * This,
            /* [out] */ LONG *pType);
        
        HRESULT ( STDMETHODCALLTYPE *SetDeviceType )( 
            IRmsDevice * This,
            /* [in] */ LONG type);
        
        HRESULT ( STDMETHODCALLTYPE *GetDeviceInfo )( 
            IRmsDevice * This,
            /* [size_is][out] */ UCHAR *pId,
            /* [out] */ SHORT *pSize);
        
        HRESULT ( STDMETHODCALLTYPE *SetDeviceInfo )( 
            IRmsDevice * This,
            /* [size_is][in] */ UCHAR *pId,
            /* [in] */ SHORT size);
        
        HRESULT ( STDMETHODCALLTYPE *GetDeviceAddress )( 
            IRmsDevice * This,
            /* [out] */ BYTE *pPort,
            /* [out] */ BYTE *pBus,
            /* [out] */ BYTE *pId,
            /* [out] */ BYTE *pLun);
        
        HRESULT ( STDMETHODCALLTYPE *SetDeviceAddress )( 
            IRmsDevice * This,
            /* [in] */ BYTE port,
            /* [in] */ BYTE bus,
            /* [in] */ BYTE id,
            /* [in] */ BYTE lun);
        
        END_INTERFACE
    } IRmsDeviceVtbl;

    interface IRmsDevice
    {
        CONST_VTBL struct IRmsDeviceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRmsDevice_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRmsDevice_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRmsDevice_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRmsDevice_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRmsDevice_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRmsDevice_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRmsDevice_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRmsDevice_GetDeviceName(This,pName)	\
    (This)->lpVtbl -> GetDeviceName(This,pName)

#define IRmsDevice_SetDeviceName(This,name)	\
    (This)->lpVtbl -> SetDeviceName(This,name)

#define IRmsDevice_GetDeviceType(This,pType)	\
    (This)->lpVtbl -> GetDeviceType(This,pType)

#define IRmsDevice_SetDeviceType(This,type)	\
    (This)->lpVtbl -> SetDeviceType(This,type)

#define IRmsDevice_GetDeviceInfo(This,pId,pSize)	\
    (This)->lpVtbl -> GetDeviceInfo(This,pId,pSize)

#define IRmsDevice_SetDeviceInfo(This,pId,size)	\
    (This)->lpVtbl -> SetDeviceInfo(This,pId,size)

#define IRmsDevice_GetDeviceAddress(This,pPort,pBus,pId,pLun)	\
    (This)->lpVtbl -> GetDeviceAddress(This,pPort,pBus,pId,pLun)

#define IRmsDevice_SetDeviceAddress(This,port,bus,id,lun)	\
    (This)->lpVtbl -> SetDeviceAddress(This,port,bus,id,lun)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRmsDevice_GetDeviceName_Proxy( 
    IRmsDevice * This,
    /* [string][out][in] */ BSTR *pName);


void __RPC_STUB IRmsDevice_GetDeviceName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsDevice_SetDeviceName_Proxy( 
    IRmsDevice * This,
    /* [string][in] */ BSTR name);


void __RPC_STUB IRmsDevice_SetDeviceName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsDevice_GetDeviceType_Proxy( 
    IRmsDevice * This,
    /* [out] */ LONG *pType);


void __RPC_STUB IRmsDevice_GetDeviceType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsDevice_SetDeviceType_Proxy( 
    IRmsDevice * This,
    /* [in] */ LONG type);


void __RPC_STUB IRmsDevice_SetDeviceType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsDevice_GetDeviceInfo_Proxy( 
    IRmsDevice * This,
    /* [size_is][out] */ UCHAR *pId,
    /* [out] */ SHORT *pSize);


void __RPC_STUB IRmsDevice_GetDeviceInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsDevice_SetDeviceInfo_Proxy( 
    IRmsDevice * This,
    /* [size_is][in] */ UCHAR *pId,
    /* [in] */ SHORT size);


void __RPC_STUB IRmsDevice_SetDeviceInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsDevice_GetDeviceAddress_Proxy( 
    IRmsDevice * This,
    /* [out] */ BYTE *pPort,
    /* [out] */ BYTE *pBus,
    /* [out] */ BYTE *pId,
    /* [out] */ BYTE *pLun);


void __RPC_STUB IRmsDevice_GetDeviceAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsDevice_SetDeviceAddress_Proxy( 
    IRmsDevice * This,
    /* [in] */ BYTE port,
    /* [in] */ BYTE bus,
    /* [in] */ BYTE id,
    /* [in] */ BYTE lun);


void __RPC_STUB IRmsDevice_SetDeviceAddress_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRmsDevice_INTERFACE_DEFINED__ */


#ifndef __IRmsStorageInfo_INTERFACE_DEFINED__
#define __IRmsStorageInfo_INTERFACE_DEFINED__

/* interface IRmsStorageInfo */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRmsStorageInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FE37FB15-3729-11D0-8CF4-00A0C9190459")
    IRmsStorageInfo : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetMountCounters( 
            /* [out] */ LONG *pReads,
            /* [out] */ LONG *pWrites) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBytesRead2( 
            /* [out] */ LONG *pReadHi,
            /* [out] */ LONG *pReadLo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBytesRead( 
            /* [out] */ LONGLONG *pRead) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetBytesRead2( 
            /* [in] */ LONG readHi,
            /* [in] */ LONG readLo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetBytesRead( 
            /* [in] */ LONGLONG read) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IncrementBytesRead( 
            /* [in] */ LONG val) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBytesWritten2( 
            /* [out] */ LONG *pWriteHi,
            /* [out] */ LONG *pWriteLo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBytesWritten( 
            /* [out] */ LONGLONG *pWritten) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetBytesWritten2( 
            /* [in] */ LONG writeHi,
            /* [in] */ LONG writeLo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetBytesWritten( 
            /* [in] */ LONGLONG written) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IncrementBytesWritten( 
            /* [in] */ LONG val) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCapacity2( 
            /* [out] */ LONG *pCapHi,
            /* [out] */ LONG *pCapLo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCapacity( 
            /* [out] */ LONGLONG *pCap) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUsedSpace2( 
            /* [out] */ LONG *pUsedHi,
            /* [out] */ LONG *pUsedLo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUsedSpace( 
            /* [out] */ LONGLONG *pUsed) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLargestFreeSpace2( 
            /* [out] */ LONG *pFreeHi,
            /* [out] */ LONG *pFreeLo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLargestFreeSpace( 
            /* [out] */ LONGLONG *pFree) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCapacity( 
            /* [in] */ LONGLONG cap) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetUsedSpace( 
            /* [in] */ LONGLONG used) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFreeSpace( 
            /* [in] */ LONGLONG free) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ResetCounters( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRmsStorageInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRmsStorageInfo * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRmsStorageInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRmsStorageInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IRmsStorageInfo * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IRmsStorageInfo * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IRmsStorageInfo * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRmsStorageInfo * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *GetMountCounters )( 
            IRmsStorageInfo * This,
            /* [out] */ LONG *pReads,
            /* [out] */ LONG *pWrites);
        
        HRESULT ( STDMETHODCALLTYPE *GetBytesRead2 )( 
            IRmsStorageInfo * This,
            /* [out] */ LONG *pReadHi,
            /* [out] */ LONG *pReadLo);
        
        HRESULT ( STDMETHODCALLTYPE *GetBytesRead )( 
            IRmsStorageInfo * This,
            /* [out] */ LONGLONG *pRead);
        
        HRESULT ( STDMETHODCALLTYPE *SetBytesRead2 )( 
            IRmsStorageInfo * This,
            /* [in] */ LONG readHi,
            /* [in] */ LONG readLo);
        
        HRESULT ( STDMETHODCALLTYPE *SetBytesRead )( 
            IRmsStorageInfo * This,
            /* [in] */ LONGLONG read);
        
        HRESULT ( STDMETHODCALLTYPE *IncrementBytesRead )( 
            IRmsStorageInfo * This,
            /* [in] */ LONG val);
        
        HRESULT ( STDMETHODCALLTYPE *GetBytesWritten2 )( 
            IRmsStorageInfo * This,
            /* [out] */ LONG *pWriteHi,
            /* [out] */ LONG *pWriteLo);
        
        HRESULT ( STDMETHODCALLTYPE *GetBytesWritten )( 
            IRmsStorageInfo * This,
            /* [out] */ LONGLONG *pWritten);
        
        HRESULT ( STDMETHODCALLTYPE *SetBytesWritten2 )( 
            IRmsStorageInfo * This,
            /* [in] */ LONG writeHi,
            /* [in] */ LONG writeLo);
        
        HRESULT ( STDMETHODCALLTYPE *SetBytesWritten )( 
            IRmsStorageInfo * This,
            /* [in] */ LONGLONG written);
        
        HRESULT ( STDMETHODCALLTYPE *IncrementBytesWritten )( 
            IRmsStorageInfo * This,
            /* [in] */ LONG val);
        
        HRESULT ( STDMETHODCALLTYPE *GetCapacity2 )( 
            IRmsStorageInfo * This,
            /* [out] */ LONG *pCapHi,
            /* [out] */ LONG *pCapLo);
        
        HRESULT ( STDMETHODCALLTYPE *GetCapacity )( 
            IRmsStorageInfo * This,
            /* [out] */ LONGLONG *pCap);
        
        HRESULT ( STDMETHODCALLTYPE *GetUsedSpace2 )( 
            IRmsStorageInfo * This,
            /* [out] */ LONG *pUsedHi,
            /* [out] */ LONG *pUsedLo);
        
        HRESULT ( STDMETHODCALLTYPE *GetUsedSpace )( 
            IRmsStorageInfo * This,
            /* [out] */ LONGLONG *pUsed);
        
        HRESULT ( STDMETHODCALLTYPE *GetLargestFreeSpace2 )( 
            IRmsStorageInfo * This,
            /* [out] */ LONG *pFreeHi,
            /* [out] */ LONG *pFreeLo);
        
        HRESULT ( STDMETHODCALLTYPE *GetLargestFreeSpace )( 
            IRmsStorageInfo * This,
            /* [out] */ LONGLONG *pFree);
        
        HRESULT ( STDMETHODCALLTYPE *SetCapacity )( 
            IRmsStorageInfo * This,
            /* [in] */ LONGLONG cap);
        
        HRESULT ( STDMETHODCALLTYPE *SetUsedSpace )( 
            IRmsStorageInfo * This,
            /* [in] */ LONGLONG used);
        
        HRESULT ( STDMETHODCALLTYPE *SetFreeSpace )( 
            IRmsStorageInfo * This,
            /* [in] */ LONGLONG free);
        
        HRESULT ( STDMETHODCALLTYPE *ResetCounters )( 
            IRmsStorageInfo * This);
        
        END_INTERFACE
    } IRmsStorageInfoVtbl;

    interface IRmsStorageInfo
    {
        CONST_VTBL struct IRmsStorageInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRmsStorageInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRmsStorageInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRmsStorageInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRmsStorageInfo_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRmsStorageInfo_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRmsStorageInfo_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRmsStorageInfo_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRmsStorageInfo_GetMountCounters(This,pReads,pWrites)	\
    (This)->lpVtbl -> GetMountCounters(This,pReads,pWrites)

#define IRmsStorageInfo_GetBytesRead2(This,pReadHi,pReadLo)	\
    (This)->lpVtbl -> GetBytesRead2(This,pReadHi,pReadLo)

#define IRmsStorageInfo_GetBytesRead(This,pRead)	\
    (This)->lpVtbl -> GetBytesRead(This,pRead)

#define IRmsStorageInfo_SetBytesRead2(This,readHi,readLo)	\
    (This)->lpVtbl -> SetBytesRead2(This,readHi,readLo)

#define IRmsStorageInfo_SetBytesRead(This,read)	\
    (This)->lpVtbl -> SetBytesRead(This,read)

#define IRmsStorageInfo_IncrementBytesRead(This,val)	\
    (This)->lpVtbl -> IncrementBytesRead(This,val)

#define IRmsStorageInfo_GetBytesWritten2(This,pWriteHi,pWriteLo)	\
    (This)->lpVtbl -> GetBytesWritten2(This,pWriteHi,pWriteLo)

#define IRmsStorageInfo_GetBytesWritten(This,pWritten)	\
    (This)->lpVtbl -> GetBytesWritten(This,pWritten)

#define IRmsStorageInfo_SetBytesWritten2(This,writeHi,writeLo)	\
    (This)->lpVtbl -> SetBytesWritten2(This,writeHi,writeLo)

#define IRmsStorageInfo_SetBytesWritten(This,written)	\
    (This)->lpVtbl -> SetBytesWritten(This,written)

#define IRmsStorageInfo_IncrementBytesWritten(This,val)	\
    (This)->lpVtbl -> IncrementBytesWritten(This,val)

#define IRmsStorageInfo_GetCapacity2(This,pCapHi,pCapLo)	\
    (This)->lpVtbl -> GetCapacity2(This,pCapHi,pCapLo)

#define IRmsStorageInfo_GetCapacity(This,pCap)	\
    (This)->lpVtbl -> GetCapacity(This,pCap)

#define IRmsStorageInfo_GetUsedSpace2(This,pUsedHi,pUsedLo)	\
    (This)->lpVtbl -> GetUsedSpace2(This,pUsedHi,pUsedLo)

#define IRmsStorageInfo_GetUsedSpace(This,pUsed)	\
    (This)->lpVtbl -> GetUsedSpace(This,pUsed)

#define IRmsStorageInfo_GetLargestFreeSpace2(This,pFreeHi,pFreeLo)	\
    (This)->lpVtbl -> GetLargestFreeSpace2(This,pFreeHi,pFreeLo)

#define IRmsStorageInfo_GetLargestFreeSpace(This,pFree)	\
    (This)->lpVtbl -> GetLargestFreeSpace(This,pFree)

#define IRmsStorageInfo_SetCapacity(This,cap)	\
    (This)->lpVtbl -> SetCapacity(This,cap)

#define IRmsStorageInfo_SetUsedSpace(This,used)	\
    (This)->lpVtbl -> SetUsedSpace(This,used)

#define IRmsStorageInfo_SetFreeSpace(This,free)	\
    (This)->lpVtbl -> SetFreeSpace(This,free)

#define IRmsStorageInfo_ResetCounters(This)	\
    (This)->lpVtbl -> ResetCounters(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRmsStorageInfo_GetMountCounters_Proxy( 
    IRmsStorageInfo * This,
    /* [out] */ LONG *pReads,
    /* [out] */ LONG *pWrites);


void __RPC_STUB IRmsStorageInfo_GetMountCounters_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsStorageInfo_GetBytesRead2_Proxy( 
    IRmsStorageInfo * This,
    /* [out] */ LONG *pReadHi,
    /* [out] */ LONG *pReadLo);


void __RPC_STUB IRmsStorageInfo_GetBytesRead2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsStorageInfo_GetBytesRead_Proxy( 
    IRmsStorageInfo * This,
    /* [out] */ LONGLONG *pRead);


void __RPC_STUB IRmsStorageInfo_GetBytesRead_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsStorageInfo_SetBytesRead2_Proxy( 
    IRmsStorageInfo * This,
    /* [in] */ LONG readHi,
    /* [in] */ LONG readLo);


void __RPC_STUB IRmsStorageInfo_SetBytesRead2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsStorageInfo_SetBytesRead_Proxy( 
    IRmsStorageInfo * This,
    /* [in] */ LONGLONG read);


void __RPC_STUB IRmsStorageInfo_SetBytesRead_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsStorageInfo_IncrementBytesRead_Proxy( 
    IRmsStorageInfo * This,
    /* [in] */ LONG val);


void __RPC_STUB IRmsStorageInfo_IncrementBytesRead_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsStorageInfo_GetBytesWritten2_Proxy( 
    IRmsStorageInfo * This,
    /* [out] */ LONG *pWriteHi,
    /* [out] */ LONG *pWriteLo);


void __RPC_STUB IRmsStorageInfo_GetBytesWritten2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsStorageInfo_GetBytesWritten_Proxy( 
    IRmsStorageInfo * This,
    /* [out] */ LONGLONG *pWritten);


void __RPC_STUB IRmsStorageInfo_GetBytesWritten_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsStorageInfo_SetBytesWritten2_Proxy( 
    IRmsStorageInfo * This,
    /* [in] */ LONG writeHi,
    /* [in] */ LONG writeLo);


void __RPC_STUB IRmsStorageInfo_SetBytesWritten2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsStorageInfo_SetBytesWritten_Proxy( 
    IRmsStorageInfo * This,
    /* [in] */ LONGLONG written);


void __RPC_STUB IRmsStorageInfo_SetBytesWritten_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsStorageInfo_IncrementBytesWritten_Proxy( 
    IRmsStorageInfo * This,
    /* [in] */ LONG val);


void __RPC_STUB IRmsStorageInfo_IncrementBytesWritten_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsStorageInfo_GetCapacity2_Proxy( 
    IRmsStorageInfo * This,
    /* [out] */ LONG *pCapHi,
    /* [out] */ LONG *pCapLo);


void __RPC_STUB IRmsStorageInfo_GetCapacity2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsStorageInfo_GetCapacity_Proxy( 
    IRmsStorageInfo * This,
    /* [out] */ LONGLONG *pCap);


void __RPC_STUB IRmsStorageInfo_GetCapacity_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsStorageInfo_GetUsedSpace2_Proxy( 
    IRmsStorageInfo * This,
    /* [out] */ LONG *pUsedHi,
    /* [out] */ LONG *pUsedLo);


void __RPC_STUB IRmsStorageInfo_GetUsedSpace2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsStorageInfo_GetUsedSpace_Proxy( 
    IRmsStorageInfo * This,
    /* [out] */ LONGLONG *pUsed);


void __RPC_STUB IRmsStorageInfo_GetUsedSpace_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsStorageInfo_GetLargestFreeSpace2_Proxy( 
    IRmsStorageInfo * This,
    /* [out] */ LONG *pFreeHi,
    /* [out] */ LONG *pFreeLo);


void __RPC_STUB IRmsStorageInfo_GetLargestFreeSpace2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsStorageInfo_GetLargestFreeSpace_Proxy( 
    IRmsStorageInfo * This,
    /* [out] */ LONGLONG *pFree);


void __RPC_STUB IRmsStorageInfo_GetLargestFreeSpace_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsStorageInfo_SetCapacity_Proxy( 
    IRmsStorageInfo * This,
    /* [in] */ LONGLONG cap);


void __RPC_STUB IRmsStorageInfo_SetCapacity_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsStorageInfo_SetUsedSpace_Proxy( 
    IRmsStorageInfo * This,
    /* [in] */ LONGLONG used);


void __RPC_STUB IRmsStorageInfo_SetUsedSpace_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsStorageInfo_SetFreeSpace_Proxy( 
    IRmsStorageInfo * This,
    /* [in] */ LONGLONG free);


void __RPC_STUB IRmsStorageInfo_SetFreeSpace_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsStorageInfo_ResetCounters_Proxy( 
    IRmsStorageInfo * This);


void __RPC_STUB IRmsStorageInfo_ResetCounters_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRmsStorageInfo_INTERFACE_DEFINED__ */


#ifndef __IRmsClient_INTERFACE_DEFINED__
#define __IRmsClient_INTERFACE_DEFINED__

/* interface IRmsClient */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRmsClient;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FE37FB16-3729-11D0-8CF4-00A0C9190459")
    IRmsClient : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetOwnerClassId( 
            /* [out] */ CLSID *pClassId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetOwnerClassId( 
            /* [in] */ CLSID classId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetName( 
            /* [string][out][in] */ BSTR *pName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetName( 
            /* [string][in] */ BSTR name) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPassword( 
            /* [string][out][in] */ BSTR *pName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPassword( 
            /* [string][in] */ BSTR name) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetInfo( 
            /* [size_is][out] */ UCHAR *pInfo,
            /* [out] */ SHORT *pSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetInfo( 
            /* [size_is][in] */ UCHAR *pInfo,
            /* [in] */ SHORT size) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVerifierClass( 
            /* [out] */ CLSID *pClassId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetVerifierClass( 
            /* [in] */ CLSID classId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPortalClass( 
            /* [out] */ CLSID *pClassId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPortalClass( 
            /* [in] */ CLSID classId) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRmsClientVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRmsClient * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRmsClient * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRmsClient * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IRmsClient * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IRmsClient * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IRmsClient * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRmsClient * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *GetOwnerClassId )( 
            IRmsClient * This,
            /* [out] */ CLSID *pClassId);
        
        HRESULT ( STDMETHODCALLTYPE *SetOwnerClassId )( 
            IRmsClient * This,
            /* [in] */ CLSID classId);
        
        HRESULT ( STDMETHODCALLTYPE *GetName )( 
            IRmsClient * This,
            /* [string][out][in] */ BSTR *pName);
        
        HRESULT ( STDMETHODCALLTYPE *SetName )( 
            IRmsClient * This,
            /* [string][in] */ BSTR name);
        
        HRESULT ( STDMETHODCALLTYPE *GetPassword )( 
            IRmsClient * This,
            /* [string][out][in] */ BSTR *pName);
        
        HRESULT ( STDMETHODCALLTYPE *SetPassword )( 
            IRmsClient * This,
            /* [string][in] */ BSTR name);
        
        HRESULT ( STDMETHODCALLTYPE *GetInfo )( 
            IRmsClient * This,
            /* [size_is][out] */ UCHAR *pInfo,
            /* [out] */ SHORT *pSize);
        
        HRESULT ( STDMETHODCALLTYPE *SetInfo )( 
            IRmsClient * This,
            /* [size_is][in] */ UCHAR *pInfo,
            /* [in] */ SHORT size);
        
        HRESULT ( STDMETHODCALLTYPE *GetVerifierClass )( 
            IRmsClient * This,
            /* [out] */ CLSID *pClassId);
        
        HRESULT ( STDMETHODCALLTYPE *SetVerifierClass )( 
            IRmsClient * This,
            /* [in] */ CLSID classId);
        
        HRESULT ( STDMETHODCALLTYPE *GetPortalClass )( 
            IRmsClient * This,
            /* [out] */ CLSID *pClassId);
        
        HRESULT ( STDMETHODCALLTYPE *SetPortalClass )( 
            IRmsClient * This,
            /* [in] */ CLSID classId);
        
        END_INTERFACE
    } IRmsClientVtbl;

    interface IRmsClient
    {
        CONST_VTBL struct IRmsClientVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRmsClient_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRmsClient_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRmsClient_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRmsClient_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRmsClient_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRmsClient_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRmsClient_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRmsClient_GetOwnerClassId(This,pClassId)	\
    (This)->lpVtbl -> GetOwnerClassId(This,pClassId)

#define IRmsClient_SetOwnerClassId(This,classId)	\
    (This)->lpVtbl -> SetOwnerClassId(This,classId)

#define IRmsClient_GetName(This,pName)	\
    (This)->lpVtbl -> GetName(This,pName)

#define IRmsClient_SetName(This,name)	\
    (This)->lpVtbl -> SetName(This,name)

#define IRmsClient_GetPassword(This,pName)	\
    (This)->lpVtbl -> GetPassword(This,pName)

#define IRmsClient_SetPassword(This,name)	\
    (This)->lpVtbl -> SetPassword(This,name)

#define IRmsClient_GetInfo(This,pInfo,pSize)	\
    (This)->lpVtbl -> GetInfo(This,pInfo,pSize)

#define IRmsClient_SetInfo(This,pInfo,size)	\
    (This)->lpVtbl -> SetInfo(This,pInfo,size)

#define IRmsClient_GetVerifierClass(This,pClassId)	\
    (This)->lpVtbl -> GetVerifierClass(This,pClassId)

#define IRmsClient_SetVerifierClass(This,classId)	\
    (This)->lpVtbl -> SetVerifierClass(This,classId)

#define IRmsClient_GetPortalClass(This,pClassId)	\
    (This)->lpVtbl -> GetPortalClass(This,pClassId)

#define IRmsClient_SetPortalClass(This,classId)	\
    (This)->lpVtbl -> SetPortalClass(This,classId)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRmsClient_GetOwnerClassId_Proxy( 
    IRmsClient * This,
    /* [out] */ CLSID *pClassId);


void __RPC_STUB IRmsClient_GetOwnerClassId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsClient_SetOwnerClassId_Proxy( 
    IRmsClient * This,
    /* [in] */ CLSID classId);


void __RPC_STUB IRmsClient_SetOwnerClassId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsClient_GetName_Proxy( 
    IRmsClient * This,
    /* [string][out][in] */ BSTR *pName);


void __RPC_STUB IRmsClient_GetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsClient_SetName_Proxy( 
    IRmsClient * This,
    /* [string][in] */ BSTR name);


void __RPC_STUB IRmsClient_SetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsClient_GetPassword_Proxy( 
    IRmsClient * This,
    /* [string][out][in] */ BSTR *pName);


void __RPC_STUB IRmsClient_GetPassword_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsClient_SetPassword_Proxy( 
    IRmsClient * This,
    /* [string][in] */ BSTR name);


void __RPC_STUB IRmsClient_SetPassword_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsClient_GetInfo_Proxy( 
    IRmsClient * This,
    /* [size_is][out] */ UCHAR *pInfo,
    /* [out] */ SHORT *pSize);


void __RPC_STUB IRmsClient_GetInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsClient_SetInfo_Proxy( 
    IRmsClient * This,
    /* [size_is][in] */ UCHAR *pInfo,
    /* [in] */ SHORT size);


void __RPC_STUB IRmsClient_SetInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsClient_GetVerifierClass_Proxy( 
    IRmsClient * This,
    /* [out] */ CLSID *pClassId);


void __RPC_STUB IRmsClient_GetVerifierClass_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsClient_SetVerifierClass_Proxy( 
    IRmsClient * This,
    /* [in] */ CLSID classId);


void __RPC_STUB IRmsClient_SetVerifierClass_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsClient_GetPortalClass_Proxy( 
    IRmsClient * This,
    /* [out] */ CLSID *pClassId);


void __RPC_STUB IRmsClient_GetPortalClass_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsClient_SetPortalClass_Proxy( 
    IRmsClient * This,
    /* [in] */ CLSID classId);


void __RPC_STUB IRmsClient_SetPortalClass_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRmsClient_INTERFACE_DEFINED__ */


#ifndef __IRmsNTMS_INTERFACE_DEFINED__
#define __IRmsNTMS_INTERFACE_DEFINED__

/* interface IRmsNTMS */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRmsNTMS;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("70674820-67DF-4C2F-9DF4-1AF0AD4227FF")
    IRmsNTMS : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE IsInstalled( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Initialize( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Allocate( 
            /* [in] */ REFGUID fromMediaSet,
            /* [in] */ REFGUID prevSideId,
            /* [out][in] */ LONGLONG *pFreeSpace,
            /* [in] */ BSTR displayName,
            /* [in] */ DWORD options,
            /* [out] */ IRmsCartridge **ppCart) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Mount( 
            /* [in] */ IRmsCartridge *pCart,
            /* [out][in] */ IRmsDrive **ppDrive,
            /* [defaultvalue][in] */ DWORD options = 0,
            /* [defaultvalue][in] */ DWORD threadId = 0) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Dismount( 
            /* [in] */ IRmsCartridge *pCart,
            /* [defaultvalue][in] */ DWORD options = 0) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Deallocate( 
            /* [in] */ IRmsCartridge *pCart) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DismountAll( 
            /* [in] */ REFGUID fromMediaSet,
            /* [defaultvalue][in] */ DWORD options = 0) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DisableAndEject( 
            /* [in] */ IRmsCartridge *pCart,
            /* [defaultvalue][in] */ DWORD options = 0) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UpdateOmidInfo( 
            /* [in] */ REFGUID cartId,
            /* [size_is][in] */ BYTE *pBuffer,
            /* [in] */ LONG size,
            /* [in] */ LONG type) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBlockSize( 
            /* [in] */ REFGUID cartId,
            /* [out] */ LONG *pBlockSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetBlockSize( 
            /* [in] */ REFGUID cartId,
            /* [in] */ LONG blockSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ExportDatabase( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FindCartridge( 
            /* [in] */ REFGUID cartId,
            /* [out] */ IRmsCartridge **ppCartridge) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Suspend( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Resume( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsMediaCopySupported( 
            /* [in] */ REFGUID mediaPoolId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UpdateDrive( 
            /* [in] */ IRmsDrive *pDrive) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNofAvailableDrives( 
            /* [out] */ DWORD *pdwNofDrives) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CheckSecondSide( 
            /* [in] */ REFGUID firstSideId,
            /* [out] */ BOOL *pbValid,
            /* [out] */ GUID *pSecondSideId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMaxMediaCapacity( 
            /* [in] */ REFGUID fromMediaSet,
            /* [out] */ LONGLONG *pMaxCapacity) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRmsNTMSVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRmsNTMS * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRmsNTMS * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRmsNTMS * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IRmsNTMS * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IRmsNTMS * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IRmsNTMS * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRmsNTMS * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *IsInstalled )( 
            IRmsNTMS * This);
        
        HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            IRmsNTMS * This);
        
        HRESULT ( STDMETHODCALLTYPE *Allocate )( 
            IRmsNTMS * This,
            /* [in] */ REFGUID fromMediaSet,
            /* [in] */ REFGUID prevSideId,
            /* [out][in] */ LONGLONG *pFreeSpace,
            /* [in] */ BSTR displayName,
            /* [in] */ DWORD options,
            /* [out] */ IRmsCartridge **ppCart);
        
        HRESULT ( STDMETHODCALLTYPE *Mount )( 
            IRmsNTMS * This,
            /* [in] */ IRmsCartridge *pCart,
            /* [out][in] */ IRmsDrive **ppDrive,
            /* [defaultvalue][in] */ DWORD options,
            /* [defaultvalue][in] */ DWORD threadId);
        
        HRESULT ( STDMETHODCALLTYPE *Dismount )( 
            IRmsNTMS * This,
            /* [in] */ IRmsCartridge *pCart,
            /* [defaultvalue][in] */ DWORD options);
        
        HRESULT ( STDMETHODCALLTYPE *Deallocate )( 
            IRmsNTMS * This,
            /* [in] */ IRmsCartridge *pCart);
        
        HRESULT ( STDMETHODCALLTYPE *DismountAll )( 
            IRmsNTMS * This,
            /* [in] */ REFGUID fromMediaSet,
            /* [defaultvalue][in] */ DWORD options);
        
        HRESULT ( STDMETHODCALLTYPE *DisableAndEject )( 
            IRmsNTMS * This,
            /* [in] */ IRmsCartridge *pCart,
            /* [defaultvalue][in] */ DWORD options);
        
        HRESULT ( STDMETHODCALLTYPE *UpdateOmidInfo )( 
            IRmsNTMS * This,
            /* [in] */ REFGUID cartId,
            /* [size_is][in] */ BYTE *pBuffer,
            /* [in] */ LONG size,
            /* [in] */ LONG type);
        
        HRESULT ( STDMETHODCALLTYPE *GetBlockSize )( 
            IRmsNTMS * This,
            /* [in] */ REFGUID cartId,
            /* [out] */ LONG *pBlockSize);
        
        HRESULT ( STDMETHODCALLTYPE *SetBlockSize )( 
            IRmsNTMS * This,
            /* [in] */ REFGUID cartId,
            /* [in] */ LONG blockSize);
        
        HRESULT ( STDMETHODCALLTYPE *ExportDatabase )( 
            IRmsNTMS * This);
        
        HRESULT ( STDMETHODCALLTYPE *FindCartridge )( 
            IRmsNTMS * This,
            /* [in] */ REFGUID cartId,
            /* [out] */ IRmsCartridge **ppCartridge);
        
        HRESULT ( STDMETHODCALLTYPE *Suspend )( 
            IRmsNTMS * This);
        
        HRESULT ( STDMETHODCALLTYPE *Resume )( 
            IRmsNTMS * This);
        
        HRESULT ( STDMETHODCALLTYPE *IsMediaCopySupported )( 
            IRmsNTMS * This,
            /* [in] */ REFGUID mediaPoolId);
        
        HRESULT ( STDMETHODCALLTYPE *UpdateDrive )( 
            IRmsNTMS * This,
            /* [in] */ IRmsDrive *pDrive);
        
        HRESULT ( STDMETHODCALLTYPE *GetNofAvailableDrives )( 
            IRmsNTMS * This,
            /* [out] */ DWORD *pdwNofDrives);
        
        HRESULT ( STDMETHODCALLTYPE *CheckSecondSide )( 
            IRmsNTMS * This,
            /* [in] */ REFGUID firstSideId,
            /* [out] */ BOOL *pbValid,
            /* [out] */ GUID *pSecondSideId);
        
        HRESULT ( STDMETHODCALLTYPE *GetMaxMediaCapacity )( 
            IRmsNTMS * This,
            /* [in] */ REFGUID fromMediaSet,
            /* [out] */ LONGLONG *pMaxCapacity);
        
        END_INTERFACE
    } IRmsNTMSVtbl;

    interface IRmsNTMS
    {
        CONST_VTBL struct IRmsNTMSVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRmsNTMS_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRmsNTMS_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRmsNTMS_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRmsNTMS_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRmsNTMS_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRmsNTMS_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRmsNTMS_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRmsNTMS_IsInstalled(This)	\
    (This)->lpVtbl -> IsInstalled(This)

#define IRmsNTMS_Initialize(This)	\
    (This)->lpVtbl -> Initialize(This)

#define IRmsNTMS_Allocate(This,fromMediaSet,prevSideId,pFreeSpace,displayName,options,ppCart)	\
    (This)->lpVtbl -> Allocate(This,fromMediaSet,prevSideId,pFreeSpace,displayName,options,ppCart)

#define IRmsNTMS_Mount(This,pCart,ppDrive,options,threadId)	\
    (This)->lpVtbl -> Mount(This,pCart,ppDrive,options,threadId)

#define IRmsNTMS_Dismount(This,pCart,options)	\
    (This)->lpVtbl -> Dismount(This,pCart,options)

#define IRmsNTMS_Deallocate(This,pCart)	\
    (This)->lpVtbl -> Deallocate(This,pCart)

#define IRmsNTMS_DismountAll(This,fromMediaSet,options)	\
    (This)->lpVtbl -> DismountAll(This,fromMediaSet,options)

#define IRmsNTMS_DisableAndEject(This,pCart,options)	\
    (This)->lpVtbl -> DisableAndEject(This,pCart,options)

#define IRmsNTMS_UpdateOmidInfo(This,cartId,pBuffer,size,type)	\
    (This)->lpVtbl -> UpdateOmidInfo(This,cartId,pBuffer,size,type)

#define IRmsNTMS_GetBlockSize(This,cartId,pBlockSize)	\
    (This)->lpVtbl -> GetBlockSize(This,cartId,pBlockSize)

#define IRmsNTMS_SetBlockSize(This,cartId,blockSize)	\
    (This)->lpVtbl -> SetBlockSize(This,cartId,blockSize)

#define IRmsNTMS_ExportDatabase(This)	\
    (This)->lpVtbl -> ExportDatabase(This)

#define IRmsNTMS_FindCartridge(This,cartId,ppCartridge)	\
    (This)->lpVtbl -> FindCartridge(This,cartId,ppCartridge)

#define IRmsNTMS_Suspend(This)	\
    (This)->lpVtbl -> Suspend(This)

#define IRmsNTMS_Resume(This)	\
    (This)->lpVtbl -> Resume(This)

#define IRmsNTMS_IsMediaCopySupported(This,mediaPoolId)	\
    (This)->lpVtbl -> IsMediaCopySupported(This,mediaPoolId)

#define IRmsNTMS_UpdateDrive(This,pDrive)	\
    (This)->lpVtbl -> UpdateDrive(This,pDrive)

#define IRmsNTMS_GetNofAvailableDrives(This,pdwNofDrives)	\
    (This)->lpVtbl -> GetNofAvailableDrives(This,pdwNofDrives)

#define IRmsNTMS_CheckSecondSide(This,firstSideId,pbValid,pSecondSideId)	\
    (This)->lpVtbl -> CheckSecondSide(This,firstSideId,pbValid,pSecondSideId)

#define IRmsNTMS_GetMaxMediaCapacity(This,fromMediaSet,pMaxCapacity)	\
    (This)->lpVtbl -> GetMaxMediaCapacity(This,fromMediaSet,pMaxCapacity)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRmsNTMS_IsInstalled_Proxy( 
    IRmsNTMS * This);


void __RPC_STUB IRmsNTMS_IsInstalled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsNTMS_Initialize_Proxy( 
    IRmsNTMS * This);


void __RPC_STUB IRmsNTMS_Initialize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsNTMS_Allocate_Proxy( 
    IRmsNTMS * This,
    /* [in] */ REFGUID fromMediaSet,
    /* [in] */ REFGUID prevSideId,
    /* [out][in] */ LONGLONG *pFreeSpace,
    /* [in] */ BSTR displayName,
    /* [in] */ DWORD options,
    /* [out] */ IRmsCartridge **ppCart);


void __RPC_STUB IRmsNTMS_Allocate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsNTMS_Mount_Proxy( 
    IRmsNTMS * This,
    /* [in] */ IRmsCartridge *pCart,
    /* [out][in] */ IRmsDrive **ppDrive,
    /* [defaultvalue][in] */ DWORD options,
    /* [defaultvalue][in] */ DWORD threadId);


void __RPC_STUB IRmsNTMS_Mount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsNTMS_Dismount_Proxy( 
    IRmsNTMS * This,
    /* [in] */ IRmsCartridge *pCart,
    /* [defaultvalue][in] */ DWORD options);


void __RPC_STUB IRmsNTMS_Dismount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsNTMS_Deallocate_Proxy( 
    IRmsNTMS * This,
    /* [in] */ IRmsCartridge *pCart);


void __RPC_STUB IRmsNTMS_Deallocate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsNTMS_DismountAll_Proxy( 
    IRmsNTMS * This,
    /* [in] */ REFGUID fromMediaSet,
    /* [defaultvalue][in] */ DWORD options);


void __RPC_STUB IRmsNTMS_DismountAll_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsNTMS_DisableAndEject_Proxy( 
    IRmsNTMS * This,
    /* [in] */ IRmsCartridge *pCart,
    /* [defaultvalue][in] */ DWORD options);


void __RPC_STUB IRmsNTMS_DisableAndEject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsNTMS_UpdateOmidInfo_Proxy( 
    IRmsNTMS * This,
    /* [in] */ REFGUID cartId,
    /* [size_is][in] */ BYTE *pBuffer,
    /* [in] */ LONG size,
    /* [in] */ LONG type);


void __RPC_STUB IRmsNTMS_UpdateOmidInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsNTMS_GetBlockSize_Proxy( 
    IRmsNTMS * This,
    /* [in] */ REFGUID cartId,
    /* [out] */ LONG *pBlockSize);


void __RPC_STUB IRmsNTMS_GetBlockSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsNTMS_SetBlockSize_Proxy( 
    IRmsNTMS * This,
    /* [in] */ REFGUID cartId,
    /* [in] */ LONG blockSize);


void __RPC_STUB IRmsNTMS_SetBlockSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsNTMS_ExportDatabase_Proxy( 
    IRmsNTMS * This);


void __RPC_STUB IRmsNTMS_ExportDatabase_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsNTMS_FindCartridge_Proxy( 
    IRmsNTMS * This,
    /* [in] */ REFGUID cartId,
    /* [out] */ IRmsCartridge **ppCartridge);


void __RPC_STUB IRmsNTMS_FindCartridge_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsNTMS_Suspend_Proxy( 
    IRmsNTMS * This);


void __RPC_STUB IRmsNTMS_Suspend_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsNTMS_Resume_Proxy( 
    IRmsNTMS * This);


void __RPC_STUB IRmsNTMS_Resume_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsNTMS_IsMediaCopySupported_Proxy( 
    IRmsNTMS * This,
    /* [in] */ REFGUID mediaPoolId);


void __RPC_STUB IRmsNTMS_IsMediaCopySupported_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsNTMS_UpdateDrive_Proxy( 
    IRmsNTMS * This,
    /* [in] */ IRmsDrive *pDrive);


void __RPC_STUB IRmsNTMS_UpdateDrive_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsNTMS_GetNofAvailableDrives_Proxy( 
    IRmsNTMS * This,
    /* [out] */ DWORD *pdwNofDrives);


void __RPC_STUB IRmsNTMS_GetNofAvailableDrives_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsNTMS_CheckSecondSide_Proxy( 
    IRmsNTMS * This,
    /* [in] */ REFGUID firstSideId,
    /* [out] */ BOOL *pbValid,
    /* [out] */ GUID *pSecondSideId);


void __RPC_STUB IRmsNTMS_CheckSecondSide_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRmsNTMS_GetMaxMediaCapacity_Proxy( 
    IRmsNTMS * This,
    /* [in] */ REFGUID fromMediaSet,
    /* [out] */ LONGLONG *pMaxCapacity);


void __RPC_STUB IRmsNTMS_GetMaxMediaCapacity_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRmsNTMS_INTERFACE_DEFINED__ */


#ifndef __IRmsSinkEveryEvent_INTERFACE_DEFINED__
#define __IRmsSinkEveryEvent_INTERFACE_DEFINED__

/* interface IRmsSinkEveryEvent */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRmsSinkEveryEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FE37FB20-3729-11D0-8CF4-00A0C9190459")
    IRmsSinkEveryEvent : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ProcessObjectStatusChange( 
            /* [in] */ BOOL isEnabled,
            /* [in] */ LONG state,
            /* [in] */ HRESULT statusCode) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRmsSinkEveryEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRmsSinkEveryEvent * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRmsSinkEveryEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRmsSinkEveryEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *ProcessObjectStatusChange )( 
            IRmsSinkEveryEvent * This,
            /* [in] */ BOOL isEnabled,
            /* [in] */ LONG state,
            /* [in] */ HRESULT statusCode);
        
        END_INTERFACE
    } IRmsSinkEveryEventVtbl;

    interface IRmsSinkEveryEvent
    {
        CONST_VTBL struct IRmsSinkEveryEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRmsSinkEveryEvent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRmsSinkEveryEvent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRmsSinkEveryEvent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRmsSinkEveryEvent_ProcessObjectStatusChange(This,isEnabled,state,statusCode)	\
    (This)->lpVtbl -> ProcessObjectStatusChange(This,isEnabled,state,statusCode)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRmsSinkEveryEvent_ProcessObjectStatusChange_Proxy( 
    IRmsSinkEveryEvent * This,
    /* [in] */ BOOL isEnabled,
    /* [in] */ LONG state,
    /* [in] */ HRESULT statusCode);


void __RPC_STUB IRmsSinkEveryEvent_ProcessObjectStatusChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRmsSinkEveryEvent_INTERFACE_DEFINED__ */


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


