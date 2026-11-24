

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for tskint.idl:
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

#ifndef __tskint_h__
#define __tskint_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IHsmFsaTskMgr_FWD_DEFINED__
#define __IHsmFsaTskMgr_FWD_DEFINED__
typedef interface IHsmFsaTskMgr IHsmFsaTskMgr;
#endif 	/* __IHsmFsaTskMgr_FWD_DEFINED__ */


#ifndef __IHsmWorkQueue_FWD_DEFINED__
#define __IHsmWorkQueue_FWD_DEFINED__
typedef interface IHsmWorkQueue IHsmWorkQueue;
#endif 	/* __IHsmWorkQueue_FWD_DEFINED__ */


#ifndef __IHsmWorkItem_FWD_DEFINED__
#define __IHsmWorkItem_FWD_DEFINED__
typedef interface IHsmWorkItem IHsmWorkItem;
#endif 	/* __IHsmWorkItem_FWD_DEFINED__ */


#ifndef __IHsmRecallQueue_FWD_DEFINED__
#define __IHsmRecallQueue_FWD_DEFINED__
typedef interface IHsmRecallQueue IHsmRecallQueue;
#endif 	/* __IHsmRecallQueue_FWD_DEFINED__ */


#ifndef __IHsmRecallItem_FWD_DEFINED__
#define __IHsmRecallItem_FWD_DEFINED__
typedef interface IHsmRecallItem IHsmRecallItem;
#endif 	/* __IHsmRecallItem_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "wsbint.h"
#include "jobdef.h"
#include "jobint.h"
#include "tskdef.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

/* interface __MIDL_itf_tskint_0000 */
/* [local] */ 







extern RPC_IF_HANDLE __MIDL_itf_tskint_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_tskint_0000_v0_0_s_ifspec;

#ifndef __IHsmFsaTskMgr_INTERFACE_DEFINED__
#define __IHsmFsaTskMgr_INTERFACE_DEFINED__

/* interface IHsmFsaTskMgr */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IHsmFsaTskMgr;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("14F73FCB-517D-4503-B15D-2D40B3E9CD21")
    IHsmFsaTskMgr : public IHsmSystemState
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ContactOk( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DoFsaWork( 
            /* [in] */ IFsaPostIt *fsaWorkItem) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Init( 
            /* [in] */ IUnknown *pServer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WorkQueueDone( 
            /* [in] */ IHsmSession *pSession,
            HSM_WORK_QUEUE_TYPE type,
            GUID *mediaId) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHsmFsaTskMgrVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHsmFsaTskMgr * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHsmFsaTskMgr * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHsmFsaTskMgr * This);
        
        HRESULT ( STDMETHODCALLTYPE *ChangeSysState )( 
            IHsmFsaTskMgr * This,
            /* [out][in] */ HSM_SYSTEM_STATE *pSysState);
        
        HRESULT ( STDMETHODCALLTYPE *ContactOk )( 
            IHsmFsaTskMgr * This);
        
        HRESULT ( STDMETHODCALLTYPE *DoFsaWork )( 
            IHsmFsaTskMgr * This,
            /* [in] */ IFsaPostIt *fsaWorkItem);
        
        HRESULT ( STDMETHODCALLTYPE *Init )( 
            IHsmFsaTskMgr * This,
            /* [in] */ IUnknown *pServer);
        
        HRESULT ( STDMETHODCALLTYPE *WorkQueueDone )( 
            IHsmFsaTskMgr * This,
            /* [in] */ IHsmSession *pSession,
            HSM_WORK_QUEUE_TYPE type,
            GUID *mediaId);
        
        END_INTERFACE
    } IHsmFsaTskMgrVtbl;

    interface IHsmFsaTskMgr
    {
        CONST_VTBL struct IHsmFsaTskMgrVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHsmFsaTskMgr_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHsmFsaTskMgr_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHsmFsaTskMgr_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHsmFsaTskMgr_ChangeSysState(This,pSysState)	\
    (This)->lpVtbl -> ChangeSysState(This,pSysState)


#define IHsmFsaTskMgr_ContactOk(This)	\
    (This)->lpVtbl -> ContactOk(This)

#define IHsmFsaTskMgr_DoFsaWork(This,fsaWorkItem)	\
    (This)->lpVtbl -> DoFsaWork(This,fsaWorkItem)

#define IHsmFsaTskMgr_Init(This,pServer)	\
    (This)->lpVtbl -> Init(This,pServer)

#define IHsmFsaTskMgr_WorkQueueDone(This,pSession,type,mediaId)	\
    (This)->lpVtbl -> WorkQueueDone(This,pSession,type,mediaId)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IHsmFsaTskMgr_ContactOk_Proxy( 
    IHsmFsaTskMgr * This);


void __RPC_STUB IHsmFsaTskMgr_ContactOk_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmFsaTskMgr_DoFsaWork_Proxy( 
    IHsmFsaTskMgr * This,
    /* [in] */ IFsaPostIt *fsaWorkItem);


void __RPC_STUB IHsmFsaTskMgr_DoFsaWork_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmFsaTskMgr_Init_Proxy( 
    IHsmFsaTskMgr * This,
    /* [in] */ IUnknown *pServer);


void __RPC_STUB IHsmFsaTskMgr_Init_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmFsaTskMgr_WorkQueueDone_Proxy( 
    IHsmFsaTskMgr * This,
    /* [in] */ IHsmSession *pSession,
    HSM_WORK_QUEUE_TYPE type,
    GUID *mediaId);


void __RPC_STUB IHsmFsaTskMgr_WorkQueueDone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IHsmFsaTskMgr_INTERFACE_DEFINED__ */


#ifndef __IHsmWorkQueue_INTERFACE_DEFINED__
#define __IHsmWorkQueue_INTERFACE_DEFINED__

/* interface IHsmWorkQueue */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IHsmWorkQueue;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("39A35CB0-C56B-11d0-B16F-00A0C916F120")
    IHsmWorkQueue : public IHsmSystemState
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ IFsaPostIt *pFsaWorkItem) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Init( 
            /* [in] */ IUnknown *pServer,
            /* [in] */ IHsmSession *pSession,
            /* [in] */ IHsmFsaTskMgr *pTskMgr,
            /* [in] */ HSM_WORK_QUEUE_TYPE type) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Start( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Stop( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ContactOk( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCurrentSessionId( 
            /* [out] */ GUID *pSessionId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNumWorkItems( 
            /* [out] */ ULONG *pNumWorkItems) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHsmWorkQueueVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHsmWorkQueue * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHsmWorkQueue * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHsmWorkQueue * This);
        
        HRESULT ( STDMETHODCALLTYPE *ChangeSysState )( 
            IHsmWorkQueue * This,
            /* [out][in] */ HSM_SYSTEM_STATE *pSysState);
        
        HRESULT ( STDMETHODCALLTYPE *Add )( 
            IHsmWorkQueue * This,
            /* [in] */ IFsaPostIt *pFsaWorkItem);
        
        HRESULT ( STDMETHODCALLTYPE *Init )( 
            IHsmWorkQueue * This,
            /* [in] */ IUnknown *pServer,
            /* [in] */ IHsmSession *pSession,
            /* [in] */ IHsmFsaTskMgr *pTskMgr,
            /* [in] */ HSM_WORK_QUEUE_TYPE type);
        
        HRESULT ( STDMETHODCALLTYPE *Start )( 
            IHsmWorkQueue * This);
        
        HRESULT ( STDMETHODCALLTYPE *Stop )( 
            IHsmWorkQueue * This);
        
        HRESULT ( STDMETHODCALLTYPE *ContactOk )( 
            IHsmWorkQueue * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetCurrentSessionId )( 
            IHsmWorkQueue * This,
            /* [out] */ GUID *pSessionId);
        
        HRESULT ( STDMETHODCALLTYPE *GetNumWorkItems )( 
            IHsmWorkQueue * This,
            /* [out] */ ULONG *pNumWorkItems);
        
        END_INTERFACE
    } IHsmWorkQueueVtbl;

    interface IHsmWorkQueue
    {
        CONST_VTBL struct IHsmWorkQueueVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHsmWorkQueue_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHsmWorkQueue_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHsmWorkQueue_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHsmWorkQueue_ChangeSysState(This,pSysState)	\
    (This)->lpVtbl -> ChangeSysState(This,pSysState)


#define IHsmWorkQueue_Add(This,pFsaWorkItem)	\
    (This)->lpVtbl -> Add(This,pFsaWorkItem)

#define IHsmWorkQueue_Init(This,pServer,pSession,pTskMgr,type)	\
    (This)->lpVtbl -> Init(This,pServer,pSession,pTskMgr,type)

#define IHsmWorkQueue_Start(This)	\
    (This)->lpVtbl -> Start(This)

#define IHsmWorkQueue_Stop(This)	\
    (This)->lpVtbl -> Stop(This)

#define IHsmWorkQueue_ContactOk(This)	\
    (This)->lpVtbl -> ContactOk(This)

#define IHsmWorkQueue_GetCurrentSessionId(This,pSessionId)	\
    (This)->lpVtbl -> GetCurrentSessionId(This,pSessionId)

#define IHsmWorkQueue_GetNumWorkItems(This,pNumWorkItems)	\
    (This)->lpVtbl -> GetNumWorkItems(This,pNumWorkItems)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IHsmWorkQueue_Add_Proxy( 
    IHsmWorkQueue * This,
    /* [in] */ IFsaPostIt *pFsaWorkItem);


void __RPC_STUB IHsmWorkQueue_Add_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmWorkQueue_Init_Proxy( 
    IHsmWorkQueue * This,
    /* [in] */ IUnknown *pServer,
    /* [in] */ IHsmSession *pSession,
    /* [in] */ IHsmFsaTskMgr *pTskMgr,
    /* [in] */ HSM_WORK_QUEUE_TYPE type);


void __RPC_STUB IHsmWorkQueue_Init_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmWorkQueue_Start_Proxy( 
    IHsmWorkQueue * This);


void __RPC_STUB IHsmWorkQueue_Start_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmWorkQueue_Stop_Proxy( 
    IHsmWorkQueue * This);


void __RPC_STUB IHsmWorkQueue_Stop_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmWorkQueue_ContactOk_Proxy( 
    IHsmWorkQueue * This);


void __RPC_STUB IHsmWorkQueue_ContactOk_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmWorkQueue_GetCurrentSessionId_Proxy( 
    IHsmWorkQueue * This,
    /* [out] */ GUID *pSessionId);


void __RPC_STUB IHsmWorkQueue_GetCurrentSessionId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmWorkQueue_GetNumWorkItems_Proxy( 
    IHsmWorkQueue * This,
    /* [out] */ ULONG *pNumWorkItems);


void __RPC_STUB IHsmWorkQueue_GetNumWorkItems_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IHsmWorkQueue_INTERFACE_DEFINED__ */


#ifndef __IHsmWorkItem_INTERFACE_DEFINED__
#define __IHsmWorkItem_INTERFACE_DEFINED__

/* interface IHsmWorkItem */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IHsmWorkItem;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BF8BBCD0-C596-11d0-B16F-00A0C916F120")
    IHsmWorkItem : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CompareToIHsmWorkItem( 
            /* [in] */ IHsmWorkItem *pWorkItem,
            /* [out] */ SHORT *pResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFsaPostIt( 
            /* [out] */ IFsaPostIt **ppFsaPostIt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFsaResource( 
            /* [out] */ IFsaResource **ppFsaResource) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetId( 
            /* [out] */ GUID *pId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMediaInfo( 
            /* [out] */ GUID *pMediaId,
            /* [out] */ FILETIME *pMediaLastUpdate,
            /* [out] */ HRESULT *pMediaLastError,
            /* [out] */ BOOL *pMediaRecallOnly,
            /* [out] */ LONGLONG *pMediaFreeBytes,
            /* [out] */ short *pMediaRemoteDataSet) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetResult( 
            /* [out] */ HRESULT *pHr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetWorkType( 
            /* [out] */ HSM_WORK_ITEM_TYPE *pWorkType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFsaPostIt( 
            /* [in] */ IFsaPostIt *pFsaPostIt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFsaResource( 
            /* [in] */ IFsaResource *pFsaResource) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMediaInfo( 
            /* [in] */ GUID mediaId,
            /* [in] */ FILETIME mediaLastUpdate,
            /* [in] */ HRESULT mediaLastError,
            /* [in] */ BOOL mediaRecallOnly,
            /* [in] */ LONGLONG mediaFreeBytes,
            /* [in] */ short mediaRemoteDataSet) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetResult( 
            /* [in] */ HRESULT hr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetWorkType( 
            /* [in] */ HSM_WORK_ITEM_TYPE workType) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHsmWorkItemVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHsmWorkItem * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHsmWorkItem * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHsmWorkItem * This);
        
        HRESULT ( STDMETHODCALLTYPE *CompareToIHsmWorkItem )( 
            IHsmWorkItem * This,
            /* [in] */ IHsmWorkItem *pWorkItem,
            /* [out] */ SHORT *pResult);
        
        HRESULT ( STDMETHODCALLTYPE *GetFsaPostIt )( 
            IHsmWorkItem * This,
            /* [out] */ IFsaPostIt **ppFsaPostIt);
        
        HRESULT ( STDMETHODCALLTYPE *GetFsaResource )( 
            IHsmWorkItem * This,
            /* [out] */ IFsaResource **ppFsaResource);
        
        HRESULT ( STDMETHODCALLTYPE *GetId )( 
            IHsmWorkItem * This,
            /* [out] */ GUID *pId);
        
        HRESULT ( STDMETHODCALLTYPE *GetMediaInfo )( 
            IHsmWorkItem * This,
            /* [out] */ GUID *pMediaId,
            /* [out] */ FILETIME *pMediaLastUpdate,
            /* [out] */ HRESULT *pMediaLastError,
            /* [out] */ BOOL *pMediaRecallOnly,
            /* [out] */ LONGLONG *pMediaFreeBytes,
            /* [out] */ short *pMediaRemoteDataSet);
        
        HRESULT ( STDMETHODCALLTYPE *GetResult )( 
            IHsmWorkItem * This,
            /* [out] */ HRESULT *pHr);
        
        HRESULT ( STDMETHODCALLTYPE *GetWorkType )( 
            IHsmWorkItem * This,
            /* [out] */ HSM_WORK_ITEM_TYPE *pWorkType);
        
        HRESULT ( STDMETHODCALLTYPE *SetFsaPostIt )( 
            IHsmWorkItem * This,
            /* [in] */ IFsaPostIt *pFsaPostIt);
        
        HRESULT ( STDMETHODCALLTYPE *SetFsaResource )( 
            IHsmWorkItem * This,
            /* [in] */ IFsaResource *pFsaResource);
        
        HRESULT ( STDMETHODCALLTYPE *SetMediaInfo )( 
            IHsmWorkItem * This,
            /* [in] */ GUID mediaId,
            /* [in] */ FILETIME mediaLastUpdate,
            /* [in] */ HRESULT mediaLastError,
            /* [in] */ BOOL mediaRecallOnly,
            /* [in] */ LONGLONG mediaFreeBytes,
            /* [in] */ short mediaRemoteDataSet);
        
        HRESULT ( STDMETHODCALLTYPE *SetResult )( 
            IHsmWorkItem * This,
            /* [in] */ HRESULT hr);
        
        HRESULT ( STDMETHODCALLTYPE *SetWorkType )( 
            IHsmWorkItem * This,
            /* [in] */ HSM_WORK_ITEM_TYPE workType);
        
        END_INTERFACE
    } IHsmWorkItemVtbl;

    interface IHsmWorkItem
    {
        CONST_VTBL struct IHsmWorkItemVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHsmWorkItem_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHsmWorkItem_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHsmWorkItem_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHsmWorkItem_CompareToIHsmWorkItem(This,pWorkItem,pResult)	\
    (This)->lpVtbl -> CompareToIHsmWorkItem(This,pWorkItem,pResult)

#define IHsmWorkItem_GetFsaPostIt(This,ppFsaPostIt)	\
    (This)->lpVtbl -> GetFsaPostIt(This,ppFsaPostIt)

#define IHsmWorkItem_GetFsaResource(This,ppFsaResource)	\
    (This)->lpVtbl -> GetFsaResource(This,ppFsaResource)

#define IHsmWorkItem_GetId(This,pId)	\
    (This)->lpVtbl -> GetId(This,pId)

#define IHsmWorkItem_GetMediaInfo(This,pMediaId,pMediaLastUpdate,pMediaLastError,pMediaRecallOnly,pMediaFreeBytes,pMediaRemoteDataSet)	\
    (This)->lpVtbl -> GetMediaInfo(This,pMediaId,pMediaLastUpdate,pMediaLastError,pMediaRecallOnly,pMediaFreeBytes,pMediaRemoteDataSet)

#define IHsmWorkItem_GetResult(This,pHr)	\
    (This)->lpVtbl -> GetResult(This,pHr)

#define IHsmWorkItem_GetWorkType(This,pWorkType)	\
    (This)->lpVtbl -> GetWorkType(This,pWorkType)

#define IHsmWorkItem_SetFsaPostIt(This,pFsaPostIt)	\
    (This)->lpVtbl -> SetFsaPostIt(This,pFsaPostIt)

#define IHsmWorkItem_SetFsaResource(This,pFsaResource)	\
    (This)->lpVtbl -> SetFsaResource(This,pFsaResource)

#define IHsmWorkItem_SetMediaInfo(This,mediaId,mediaLastUpdate,mediaLastError,mediaRecallOnly,mediaFreeBytes,mediaRemoteDataSet)	\
    (This)->lpVtbl -> SetMediaInfo(This,mediaId,mediaLastUpdate,mediaLastError,mediaRecallOnly,mediaFreeBytes,mediaRemoteDataSet)

#define IHsmWorkItem_SetResult(This,hr)	\
    (This)->lpVtbl -> SetResult(This,hr)

#define IHsmWorkItem_SetWorkType(This,workType)	\
    (This)->lpVtbl -> SetWorkType(This,workType)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IHsmWorkItem_CompareToIHsmWorkItem_Proxy( 
    IHsmWorkItem * This,
    /* [in] */ IHsmWorkItem *pWorkItem,
    /* [out] */ SHORT *pResult);


void __RPC_STUB IHsmWorkItem_CompareToIHsmWorkItem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmWorkItem_GetFsaPostIt_Proxy( 
    IHsmWorkItem * This,
    /* [out] */ IFsaPostIt **ppFsaPostIt);


void __RPC_STUB IHsmWorkItem_GetFsaPostIt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmWorkItem_GetFsaResource_Proxy( 
    IHsmWorkItem * This,
    /* [out] */ IFsaResource **ppFsaResource);


void __RPC_STUB IHsmWorkItem_GetFsaResource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmWorkItem_GetId_Proxy( 
    IHsmWorkItem * This,
    /* [out] */ GUID *pId);


void __RPC_STUB IHsmWorkItem_GetId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmWorkItem_GetMediaInfo_Proxy( 
    IHsmWorkItem * This,
    /* [out] */ GUID *pMediaId,
    /* [out] */ FILETIME *pMediaLastUpdate,
    /* [out] */ HRESULT *pMediaLastError,
    /* [out] */ BOOL *pMediaRecallOnly,
    /* [out] */ LONGLONG *pMediaFreeBytes,
    /* [out] */ short *pMediaRemoteDataSet);


void __RPC_STUB IHsmWorkItem_GetMediaInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmWorkItem_GetResult_Proxy( 
    IHsmWorkItem * This,
    /* [out] */ HRESULT *pHr);


void __RPC_STUB IHsmWorkItem_GetResult_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmWorkItem_GetWorkType_Proxy( 
    IHsmWorkItem * This,
    /* [out] */ HSM_WORK_ITEM_TYPE *pWorkType);


void __RPC_STUB IHsmWorkItem_GetWorkType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmWorkItem_SetFsaPostIt_Proxy( 
    IHsmWorkItem * This,
    /* [in] */ IFsaPostIt *pFsaPostIt);


void __RPC_STUB IHsmWorkItem_SetFsaPostIt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmWorkItem_SetFsaResource_Proxy( 
    IHsmWorkItem * This,
    /* [in] */ IFsaResource *pFsaResource);


void __RPC_STUB IHsmWorkItem_SetFsaResource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmWorkItem_SetMediaInfo_Proxy( 
    IHsmWorkItem * This,
    /* [in] */ GUID mediaId,
    /* [in] */ FILETIME mediaLastUpdate,
    /* [in] */ HRESULT mediaLastError,
    /* [in] */ BOOL mediaRecallOnly,
    /* [in] */ LONGLONG mediaFreeBytes,
    /* [in] */ short mediaRemoteDataSet);


void __RPC_STUB IHsmWorkItem_SetMediaInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmWorkItem_SetResult_Proxy( 
    IHsmWorkItem * This,
    /* [in] */ HRESULT hr);


void __RPC_STUB IHsmWorkItem_SetResult_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmWorkItem_SetWorkType_Proxy( 
    IHsmWorkItem * This,
    /* [in] */ HSM_WORK_ITEM_TYPE workType);


void __RPC_STUB IHsmWorkItem_SetWorkType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IHsmWorkItem_INTERFACE_DEFINED__ */


#ifndef __IHsmRecallQueue_INTERFACE_DEFINED__
#define __IHsmRecallQueue_INTERFACE_DEFINED__

/* interface IHsmRecallQueue */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IHsmRecallQueue;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E3A35E06-4263-4505-B77B-196B22ACC94b")
    IHsmRecallQueue : public IHsmSystemState
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ IFsaPostIt *pFsaWorkItem,
            /* [in] */ GUID *pBagId,
            /* [in] */ LONGLONG dataSetStart) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Init( 
            /* [in] */ IUnknown *pServer,
            /* [in] */ IHsmFsaTskMgr *pTskMgr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Start( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Stop( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ContactOk( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMediaId( 
            /* [out] */ GUID *mediaId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMediaId( 
            /* [in] */ GUID *mediaId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsEmpty( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHsmRecallQueueVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHsmRecallQueue * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHsmRecallQueue * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHsmRecallQueue * This);
        
        HRESULT ( STDMETHODCALLTYPE *ChangeSysState )( 
            IHsmRecallQueue * This,
            /* [out][in] */ HSM_SYSTEM_STATE *pSysState);
        
        HRESULT ( STDMETHODCALLTYPE *Add )( 
            IHsmRecallQueue * This,
            /* [in] */ IFsaPostIt *pFsaWorkItem,
            /* [in] */ GUID *pBagId,
            /* [in] */ LONGLONG dataSetStart);
        
        HRESULT ( STDMETHODCALLTYPE *Init )( 
            IHsmRecallQueue * This,
            /* [in] */ IUnknown *pServer,
            /* [in] */ IHsmFsaTskMgr *pTskMgr);
        
        HRESULT ( STDMETHODCALLTYPE *Start )( 
            IHsmRecallQueue * This);
        
        HRESULT ( STDMETHODCALLTYPE *Stop )( 
            IHsmRecallQueue * This);
        
        HRESULT ( STDMETHODCALLTYPE *ContactOk )( 
            IHsmRecallQueue * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetMediaId )( 
            IHsmRecallQueue * This,
            /* [out] */ GUID *mediaId);
        
        HRESULT ( STDMETHODCALLTYPE *SetMediaId )( 
            IHsmRecallQueue * This,
            /* [in] */ GUID *mediaId);
        
        HRESULT ( STDMETHODCALLTYPE *IsEmpty )( 
            IHsmRecallQueue * This);
        
        END_INTERFACE
    } IHsmRecallQueueVtbl;

    interface IHsmRecallQueue
    {
        CONST_VTBL struct IHsmRecallQueueVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHsmRecallQueue_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHsmRecallQueue_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHsmRecallQueue_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHsmRecallQueue_ChangeSysState(This,pSysState)	\
    (This)->lpVtbl -> ChangeSysState(This,pSysState)


#define IHsmRecallQueue_Add(This,pFsaWorkItem,pBagId,dataSetStart)	\
    (This)->lpVtbl -> Add(This,pFsaWorkItem,pBagId,dataSetStart)

#define IHsmRecallQueue_Init(This,pServer,pTskMgr)	\
    (This)->lpVtbl -> Init(This,pServer,pTskMgr)

#define IHsmRecallQueue_Start(This)	\
    (This)->lpVtbl -> Start(This)

#define IHsmRecallQueue_Stop(This)	\
    (This)->lpVtbl -> Stop(This)

#define IHsmRecallQueue_ContactOk(This)	\
    (This)->lpVtbl -> ContactOk(This)

#define IHsmRecallQueue_GetMediaId(This,mediaId)	\
    (This)->lpVtbl -> GetMediaId(This,mediaId)

#define IHsmRecallQueue_SetMediaId(This,mediaId)	\
    (This)->lpVtbl -> SetMediaId(This,mediaId)

#define IHsmRecallQueue_IsEmpty(This)	\
    (This)->lpVtbl -> IsEmpty(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IHsmRecallQueue_Add_Proxy( 
    IHsmRecallQueue * This,
    /* [in] */ IFsaPostIt *pFsaWorkItem,
    /* [in] */ GUID *pBagId,
    /* [in] */ LONGLONG dataSetStart);


void __RPC_STUB IHsmRecallQueue_Add_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRecallQueue_Init_Proxy( 
    IHsmRecallQueue * This,
    /* [in] */ IUnknown *pServer,
    /* [in] */ IHsmFsaTskMgr *pTskMgr);


void __RPC_STUB IHsmRecallQueue_Init_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRecallQueue_Start_Proxy( 
    IHsmRecallQueue * This);


void __RPC_STUB IHsmRecallQueue_Start_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRecallQueue_Stop_Proxy( 
    IHsmRecallQueue * This);


void __RPC_STUB IHsmRecallQueue_Stop_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRecallQueue_ContactOk_Proxy( 
    IHsmRecallQueue * This);


void __RPC_STUB IHsmRecallQueue_ContactOk_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRecallQueue_GetMediaId_Proxy( 
    IHsmRecallQueue * This,
    /* [out] */ GUID *mediaId);


void __RPC_STUB IHsmRecallQueue_GetMediaId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRecallQueue_SetMediaId_Proxy( 
    IHsmRecallQueue * This,
    /* [in] */ GUID *mediaId);


void __RPC_STUB IHsmRecallQueue_SetMediaId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRecallQueue_IsEmpty_Proxy( 
    IHsmRecallQueue * This);


void __RPC_STUB IHsmRecallQueue_IsEmpty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IHsmRecallQueue_INTERFACE_DEFINED__ */


#ifndef __IHsmRecallItem_INTERFACE_DEFINED__
#define __IHsmRecallItem_INTERFACE_DEFINED__

/* interface IHsmRecallItem */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IHsmRecallItem;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B287C709-f4AD-467C-811D-1D56021D68AD")
    IHsmRecallItem : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CompareToIHsmRecallItem( 
            /* [in] */ IHsmRecallItem *pWorkItem,
            /* [out] */ SHORT *pResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFsaPostIt( 
            /* [out] */ IFsaPostIt **ppFsaPostIt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFsaResource( 
            /* [out] */ IFsaResource **ppFsaResource) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetId( 
            /* [out] */ GUID *pId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMediaInfo( 
            /* [out] */ GUID *pMediaId,
            /* [out] */ FILETIME *pMediaLastUpdate,
            /* [out] */ HRESULT *pMediaLastError,
            /* [out] */ BOOL *pMediaRecallOnly,
            /* [out] */ LONGLONG *pMediaFreeBytes,
            /* [out] */ short *pMediaRemoteDataSet) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetResult( 
            /* [out] */ HRESULT *pHr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetWorkType( 
            /* [out] */ HSM_WORK_ITEM_TYPE *pWorkType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEventCookie( 
            /* [out] */ DWORD *pEventCookie) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStateCookie( 
            /* [out] */ DWORD *pStateCookie) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetJobState( 
            /* [out] */ HSM_JOB_STATE *pJobState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetJobPhase( 
            /* [out] */ HSM_JOB_PHASE *pJobPhase) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSeekOffset( 
            /* [out] */ LONGLONG *pJobPhase) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBagId( 
            /* [out] */ GUID *pBagId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDataSetStart( 
            /* [out] */ LONGLONG *pDataSetStart) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFsaPostIt( 
            /* [in] */ IFsaPostIt *pFsaPostIt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFsaResource( 
            /* [in] */ IFsaResource *pFsaResource) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMediaInfo( 
            /* [in] */ GUID mediaId,
            /* [in] */ FILETIME mediaLastUpdate,
            /* [in] */ HRESULT mediaLastError,
            /* [in] */ BOOL mediaRecallOnly,
            /* [in] */ LONGLONG mediaFreeBytes,
            /* [in] */ short mediaRemoteDataSet) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetResult( 
            /* [in] */ HRESULT hr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetWorkType( 
            /* [in] */ HSM_WORK_ITEM_TYPE workType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetEventCookie( 
            /* [in] */ DWORD eventCookie) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetStateCookie( 
            /* [in] */ DWORD stateCookie) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetJobState( 
            /* [in] */ HSM_JOB_STATE jobState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetJobPhase( 
            /* [in] */ HSM_JOB_PHASE jobPhase) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSeekOffset( 
            /* [in] */ LONGLONG seekOffset) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetBagId( 
            /* [in] */ GUID *bagId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDataSetStart( 
            /* [in] */ LONGLONG dataSetStart) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHsmRecallItemVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHsmRecallItem * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHsmRecallItem * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHsmRecallItem * This);
        
        HRESULT ( STDMETHODCALLTYPE *CompareToIHsmRecallItem )( 
            IHsmRecallItem * This,
            /* [in] */ IHsmRecallItem *pWorkItem,
            /* [out] */ SHORT *pResult);
        
        HRESULT ( STDMETHODCALLTYPE *GetFsaPostIt )( 
            IHsmRecallItem * This,
            /* [out] */ IFsaPostIt **ppFsaPostIt);
        
        HRESULT ( STDMETHODCALLTYPE *GetFsaResource )( 
            IHsmRecallItem * This,
            /* [out] */ IFsaResource **ppFsaResource);
        
        HRESULT ( STDMETHODCALLTYPE *GetId )( 
            IHsmRecallItem * This,
            /* [out] */ GUID *pId);
        
        HRESULT ( STDMETHODCALLTYPE *GetMediaInfo )( 
            IHsmRecallItem * This,
            /* [out] */ GUID *pMediaId,
            /* [out] */ FILETIME *pMediaLastUpdate,
            /* [out] */ HRESULT *pMediaLastError,
            /* [out] */ BOOL *pMediaRecallOnly,
            /* [out] */ LONGLONG *pMediaFreeBytes,
            /* [out] */ short *pMediaRemoteDataSet);
        
        HRESULT ( STDMETHODCALLTYPE *GetResult )( 
            IHsmRecallItem * This,
            /* [out] */ HRESULT *pHr);
        
        HRESULT ( STDMETHODCALLTYPE *GetWorkType )( 
            IHsmRecallItem * This,
            /* [out] */ HSM_WORK_ITEM_TYPE *pWorkType);
        
        HRESULT ( STDMETHODCALLTYPE *GetEventCookie )( 
            IHsmRecallItem * This,
            /* [out] */ DWORD *pEventCookie);
        
        HRESULT ( STDMETHODCALLTYPE *GetStateCookie )( 
            IHsmRecallItem * This,
            /* [out] */ DWORD *pStateCookie);
        
        HRESULT ( STDMETHODCALLTYPE *GetJobState )( 
            IHsmRecallItem * This,
            /* [out] */ HSM_JOB_STATE *pJobState);
        
        HRESULT ( STDMETHODCALLTYPE *GetJobPhase )( 
            IHsmRecallItem * This,
            /* [out] */ HSM_JOB_PHASE *pJobPhase);
        
        HRESULT ( STDMETHODCALLTYPE *GetSeekOffset )( 
            IHsmRecallItem * This,
            /* [out] */ LONGLONG *pJobPhase);
        
        HRESULT ( STDMETHODCALLTYPE *GetBagId )( 
            IHsmRecallItem * This,
            /* [out] */ GUID *pBagId);
        
        HRESULT ( STDMETHODCALLTYPE *GetDataSetStart )( 
            IHsmRecallItem * This,
            /* [out] */ LONGLONG *pDataSetStart);
        
        HRESULT ( STDMETHODCALLTYPE *SetFsaPostIt )( 
            IHsmRecallItem * This,
            /* [in] */ IFsaPostIt *pFsaPostIt);
        
        HRESULT ( STDMETHODCALLTYPE *SetFsaResource )( 
            IHsmRecallItem * This,
            /* [in] */ IFsaResource *pFsaResource);
        
        HRESULT ( STDMETHODCALLTYPE *SetMediaInfo )( 
            IHsmRecallItem * This,
            /* [in] */ GUID mediaId,
            /* [in] */ FILETIME mediaLastUpdate,
            /* [in] */ HRESULT mediaLastError,
            /* [in] */ BOOL mediaRecallOnly,
            /* [in] */ LONGLONG mediaFreeBytes,
            /* [in] */ short mediaRemoteDataSet);
        
        HRESULT ( STDMETHODCALLTYPE *SetResult )( 
            IHsmRecallItem * This,
            /* [in] */ HRESULT hr);
        
        HRESULT ( STDMETHODCALLTYPE *SetWorkType )( 
            IHsmRecallItem * This,
            /* [in] */ HSM_WORK_ITEM_TYPE workType);
        
        HRESULT ( STDMETHODCALLTYPE *SetEventCookie )( 
            IHsmRecallItem * This,
            /* [in] */ DWORD eventCookie);
        
        HRESULT ( STDMETHODCALLTYPE *SetStateCookie )( 
            IHsmRecallItem * This,
            /* [in] */ DWORD stateCookie);
        
        HRESULT ( STDMETHODCALLTYPE *SetJobState )( 
            IHsmRecallItem * This,
            /* [in] */ HSM_JOB_STATE jobState);
        
        HRESULT ( STDMETHODCALLTYPE *SetJobPhase )( 
            IHsmRecallItem * This,
            /* [in] */ HSM_JOB_PHASE jobPhase);
        
        HRESULT ( STDMETHODCALLTYPE *SetSeekOffset )( 
            IHsmRecallItem * This,
            /* [in] */ LONGLONG seekOffset);
        
        HRESULT ( STDMETHODCALLTYPE *SetBagId )( 
            IHsmRecallItem * This,
            /* [in] */ GUID *bagId);
        
        HRESULT ( STDMETHODCALLTYPE *SetDataSetStart )( 
            IHsmRecallItem * This,
            /* [in] */ LONGLONG dataSetStart);
        
        END_INTERFACE
    } IHsmRecallItemVtbl;

    interface IHsmRecallItem
    {
        CONST_VTBL struct IHsmRecallItemVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHsmRecallItem_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHsmRecallItem_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHsmRecallItem_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHsmRecallItem_CompareToIHsmRecallItem(This,pWorkItem,pResult)	\
    (This)->lpVtbl -> CompareToIHsmRecallItem(This,pWorkItem,pResult)

#define IHsmRecallItem_GetFsaPostIt(This,ppFsaPostIt)	\
    (This)->lpVtbl -> GetFsaPostIt(This,ppFsaPostIt)

#define IHsmRecallItem_GetFsaResource(This,ppFsaResource)	\
    (This)->lpVtbl -> GetFsaResource(This,ppFsaResource)

#define IHsmRecallItem_GetId(This,pId)	\
    (This)->lpVtbl -> GetId(This,pId)

#define IHsmRecallItem_GetMediaInfo(This,pMediaId,pMediaLastUpdate,pMediaLastError,pMediaRecallOnly,pMediaFreeBytes,pMediaRemoteDataSet)	\
    (This)->lpVtbl -> GetMediaInfo(This,pMediaId,pMediaLastUpdate,pMediaLastError,pMediaRecallOnly,pMediaFreeBytes,pMediaRemoteDataSet)

#define IHsmRecallItem_GetResult(This,pHr)	\
    (This)->lpVtbl -> GetResult(This,pHr)

#define IHsmRecallItem_GetWorkType(This,pWorkType)	\
    (This)->lpVtbl -> GetWorkType(This,pWorkType)

#define IHsmRecallItem_GetEventCookie(This,pEventCookie)	\
    (This)->lpVtbl -> GetEventCookie(This,pEventCookie)

#define IHsmRecallItem_GetStateCookie(This,pStateCookie)	\
    (This)->lpVtbl -> GetStateCookie(This,pStateCookie)

#define IHsmRecallItem_GetJobState(This,pJobState)	\
    (This)->lpVtbl -> GetJobState(This,pJobState)

#define IHsmRecallItem_GetJobPhase(This,pJobPhase)	\
    (This)->lpVtbl -> GetJobPhase(This,pJobPhase)

#define IHsmRecallItem_GetSeekOffset(This,pJobPhase)	\
    (This)->lpVtbl -> GetSeekOffset(This,pJobPhase)

#define IHsmRecallItem_GetBagId(This,pBagId)	\
    (This)->lpVtbl -> GetBagId(This,pBagId)

#define IHsmRecallItem_GetDataSetStart(This,pDataSetStart)	\
    (This)->lpVtbl -> GetDataSetStart(This,pDataSetStart)

#define IHsmRecallItem_SetFsaPostIt(This,pFsaPostIt)	\
    (This)->lpVtbl -> SetFsaPostIt(This,pFsaPostIt)

#define IHsmRecallItem_SetFsaResource(This,pFsaResource)	\
    (This)->lpVtbl -> SetFsaResource(This,pFsaResource)

#define IHsmRecallItem_SetMediaInfo(This,mediaId,mediaLastUpdate,mediaLastError,mediaRecallOnly,mediaFreeBytes,mediaRemoteDataSet)	\
    (This)->lpVtbl -> SetMediaInfo(This,mediaId,mediaLastUpdate,mediaLastError,mediaRecallOnly,mediaFreeBytes,mediaRemoteDataSet)

#define IHsmRecallItem_SetResult(This,hr)	\
    (This)->lpVtbl -> SetResult(This,hr)

#define IHsmRecallItem_SetWorkType(This,workType)	\
    (This)->lpVtbl -> SetWorkType(This,workType)

#define IHsmRecallItem_SetEventCookie(This,eventCookie)	\
    (This)->lpVtbl -> SetEventCookie(This,eventCookie)

#define IHsmRecallItem_SetStateCookie(This,stateCookie)	\
    (This)->lpVtbl -> SetStateCookie(This,stateCookie)

#define IHsmRecallItem_SetJobState(This,jobState)	\
    (This)->lpVtbl -> SetJobState(This,jobState)

#define IHsmRecallItem_SetJobPhase(This,jobPhase)	\
    (This)->lpVtbl -> SetJobPhase(This,jobPhase)

#define IHsmRecallItem_SetSeekOffset(This,seekOffset)	\
    (This)->lpVtbl -> SetSeekOffset(This,seekOffset)

#define IHsmRecallItem_SetBagId(This,bagId)	\
    (This)->lpVtbl -> SetBagId(This,bagId)

#define IHsmRecallItem_SetDataSetStart(This,dataSetStart)	\
    (This)->lpVtbl -> SetDataSetStart(This,dataSetStart)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IHsmRecallItem_CompareToIHsmRecallItem_Proxy( 
    IHsmRecallItem * This,
    /* [in] */ IHsmRecallItem *pWorkItem,
    /* [out] */ SHORT *pResult);


void __RPC_STUB IHsmRecallItem_CompareToIHsmRecallItem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRecallItem_GetFsaPostIt_Proxy( 
    IHsmRecallItem * This,
    /* [out] */ IFsaPostIt **ppFsaPostIt);


void __RPC_STUB IHsmRecallItem_GetFsaPostIt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRecallItem_GetFsaResource_Proxy( 
    IHsmRecallItem * This,
    /* [out] */ IFsaResource **ppFsaResource);


void __RPC_STUB IHsmRecallItem_GetFsaResource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRecallItem_GetId_Proxy( 
    IHsmRecallItem * This,
    /* [out] */ GUID *pId);


void __RPC_STUB IHsmRecallItem_GetId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRecallItem_GetMediaInfo_Proxy( 
    IHsmRecallItem * This,
    /* [out] */ GUID *pMediaId,
    /* [out] */ FILETIME *pMediaLastUpdate,
    /* [out] */ HRESULT *pMediaLastError,
    /* [out] */ BOOL *pMediaRecallOnly,
    /* [out] */ LONGLONG *pMediaFreeBytes,
    /* [out] */ short *pMediaRemoteDataSet);


void __RPC_STUB IHsmRecallItem_GetMediaInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRecallItem_GetResult_Proxy( 
    IHsmRecallItem * This,
    /* [out] */ HRESULT *pHr);


void __RPC_STUB IHsmRecallItem_GetResult_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRecallItem_GetWorkType_Proxy( 
    IHsmRecallItem * This,
    /* [out] */ HSM_WORK_ITEM_TYPE *pWorkType);


void __RPC_STUB IHsmRecallItem_GetWorkType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRecallItem_GetEventCookie_Proxy( 
    IHsmRecallItem * This,
    /* [out] */ DWORD *pEventCookie);


void __RPC_STUB IHsmRecallItem_GetEventCookie_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRecallItem_GetStateCookie_Proxy( 
    IHsmRecallItem * This,
    /* [out] */ DWORD *pStateCookie);


void __RPC_STUB IHsmRecallItem_GetStateCookie_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRecallItem_GetJobState_Proxy( 
    IHsmRecallItem * This,
    /* [out] */ HSM_JOB_STATE *pJobState);


void __RPC_STUB IHsmRecallItem_GetJobState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRecallItem_GetJobPhase_Proxy( 
    IHsmRecallItem * This,
    /* [out] */ HSM_JOB_PHASE *pJobPhase);


void __RPC_STUB IHsmRecallItem_GetJobPhase_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRecallItem_GetSeekOffset_Proxy( 
    IHsmRecallItem * This,
    /* [out] */ LONGLONG *pJobPhase);


void __RPC_STUB IHsmRecallItem_GetSeekOffset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRecallItem_GetBagId_Proxy( 
    IHsmRecallItem * This,
    /* [out] */ GUID *pBagId);


void __RPC_STUB IHsmRecallItem_GetBagId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRecallItem_GetDataSetStart_Proxy( 
    IHsmRecallItem * This,
    /* [out] */ LONGLONG *pDataSetStart);


void __RPC_STUB IHsmRecallItem_GetDataSetStart_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRecallItem_SetFsaPostIt_Proxy( 
    IHsmRecallItem * This,
    /* [in] */ IFsaPostIt *pFsaPostIt);


void __RPC_STUB IHsmRecallItem_SetFsaPostIt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRecallItem_SetFsaResource_Proxy( 
    IHsmRecallItem * This,
    /* [in] */ IFsaResource *pFsaResource);


void __RPC_STUB IHsmRecallItem_SetFsaResource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRecallItem_SetMediaInfo_Proxy( 
    IHsmRecallItem * This,
    /* [in] */ GUID mediaId,
    /* [in] */ FILETIME mediaLastUpdate,
    /* [in] */ HRESULT mediaLastError,
    /* [in] */ BOOL mediaRecallOnly,
    /* [in] */ LONGLONG mediaFreeBytes,
    /* [in] */ short mediaRemoteDataSet);


void __RPC_STUB IHsmRecallItem_SetMediaInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRecallItem_SetResult_Proxy( 
    IHsmRecallItem * This,
    /* [in] */ HRESULT hr);


void __RPC_STUB IHsmRecallItem_SetResult_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRecallItem_SetWorkType_Proxy( 
    IHsmRecallItem * This,
    /* [in] */ HSM_WORK_ITEM_TYPE workType);


void __RPC_STUB IHsmRecallItem_SetWorkType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRecallItem_SetEventCookie_Proxy( 
    IHsmRecallItem * This,
    /* [in] */ DWORD eventCookie);


void __RPC_STUB IHsmRecallItem_SetEventCookie_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRecallItem_SetStateCookie_Proxy( 
    IHsmRecallItem * This,
    /* [in] */ DWORD stateCookie);


void __RPC_STUB IHsmRecallItem_SetStateCookie_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRecallItem_SetJobState_Proxy( 
    IHsmRecallItem * This,
    /* [in] */ HSM_JOB_STATE jobState);


void __RPC_STUB IHsmRecallItem_SetJobState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRecallItem_SetJobPhase_Proxy( 
    IHsmRecallItem * This,
    /* [in] */ HSM_JOB_PHASE jobPhase);


void __RPC_STUB IHsmRecallItem_SetJobPhase_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRecallItem_SetSeekOffset_Proxy( 
    IHsmRecallItem * This,
    /* [in] */ LONGLONG seekOffset);


void __RPC_STUB IHsmRecallItem_SetSeekOffset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRecallItem_SetBagId_Proxy( 
    IHsmRecallItem * This,
    /* [in] */ GUID *bagId);


void __RPC_STUB IHsmRecallItem_SetBagId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRecallItem_SetDataSetStart_Proxy( 
    IHsmRecallItem * This,
    /* [in] */ LONGLONG dataSetStart);


void __RPC_STUB IHsmRecallItem_SetDataSetStart_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IHsmRecallItem_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


