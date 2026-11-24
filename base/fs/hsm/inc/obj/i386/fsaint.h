

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for fsaint.idl:
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

#ifndef __fsaint_h__
#define __fsaint_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IFsaFilter_FWD_DEFINED__
#define __IFsaFilter_FWD_DEFINED__
typedef interface IFsaFilter IFsaFilter;
#endif 	/* __IFsaFilter_FWD_DEFINED__ */


#ifndef __IFsaFilterClient_FWD_DEFINED__
#define __IFsaFilterClient_FWD_DEFINED__
typedef interface IFsaFilterClient IFsaFilterClient;
#endif 	/* __IFsaFilterClient_FWD_DEFINED__ */


#ifndef __IFsaFilterRecall_FWD_DEFINED__
#define __IFsaFilterRecall_FWD_DEFINED__
typedef interface IFsaFilterRecall IFsaFilterRecall;
#endif 	/* __IFsaFilterRecall_FWD_DEFINED__ */


#ifndef __IFsaResource_FWD_DEFINED__
#define __IFsaResource_FWD_DEFINED__
typedef interface IFsaResource IFsaResource;
#endif 	/* __IFsaResource_FWD_DEFINED__ */


#ifndef __IFsaScanItem_FWD_DEFINED__
#define __IFsaScanItem_FWD_DEFINED__
typedef interface IFsaScanItem IFsaScanItem;
#endif 	/* __IFsaScanItem_FWD_DEFINED__ */


#ifndef __IFsaServer_FWD_DEFINED__
#define __IFsaServer_FWD_DEFINED__
typedef interface IFsaServer IFsaServer;
#endif 	/* __IFsaServer_FWD_DEFINED__ */


#ifndef __IFsaTruncator_FWD_DEFINED__
#define __IFsaTruncator_FWD_DEFINED__
typedef interface IFsaTruncator IFsaTruncator;
#endif 	/* __IFsaTruncator_FWD_DEFINED__ */


#ifndef __IFsaPostIt_FWD_DEFINED__
#define __IFsaPostIt_FWD_DEFINED__
typedef interface IFsaPostIt IFsaPostIt;
#endif 	/* __IFsaPostIt_FWD_DEFINED__ */


#ifndef __IFsaRecallNotifyClient_FWD_DEFINED__
#define __IFsaRecallNotifyClient_FWD_DEFINED__
typedef interface IFsaRecallNotifyClient IFsaRecallNotifyClient;
#endif 	/* __IFsaRecallNotifyClient_FWD_DEFINED__ */


#ifndef __IFsaRecallNotifyServer_FWD_DEFINED__
#define __IFsaRecallNotifyServer_FWD_DEFINED__
typedef interface IFsaRecallNotifyServer IFsaRecallNotifyServer;
#endif 	/* __IFsaRecallNotifyServer_FWD_DEFINED__ */


#ifndef __IFsaRecallNotifySend_FWD_DEFINED__
#define __IFsaRecallNotifySend_FWD_DEFINED__
typedef interface IFsaRecallNotifySend IFsaRecallNotifySend;
#endif 	/* __IFsaRecallNotifySend_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "wsbint.h"
#include "fsadef.h"
#include "jobdef.h"
#include "tskint.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

/* interface __MIDL_itf_fsaint_0000 */
/* [local] */ 













extern RPC_IF_HANDLE __MIDL_itf_fsaint_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_fsaint_0000_v0_0_s_ifspec;

#ifndef __IFsaFilter_INTERFACE_DEFINED__
#define __IFsaFilter_INTERFACE_DEFINED__

/* interface IFsaFilter */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IFsaFilter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5FFF1640-D487-11d1-A9F5-00A0248903EA")
    IFsaFilter : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Cancel( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CancelRecall( 
            /* [in] */ IFsaFilterRecall *pRecall) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CompareToIdentifier( 
            /* [in] */ GUID id,
            /* [out] */ SHORT *pResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CompareToIFilter( 
            /* [in] */ IFsaFilter *pFilter,
            /* [out] */ SHORT *pResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeleteRecall( 
            /* [in] */ IFsaFilterRecall *pRecall) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumRecalls( 
            /* [out] */ IWsbEnum **ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIdentifier( 
            /* [out] */ GUID *pId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLogicalName( 
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMaxRecallBuffers( 
            /* [out] */ ULONG *pMaxBuffers) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMaxRecalls( 
            /* [out] */ ULONG *pMaxRecalls) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMinRecallInterval( 
            /* [out] */ ULONG *pMinIterval) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetState( 
            /* [out] */ HSM_JOB_STATE *pState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsEnabled( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Pause( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Resume( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAdminExemption( 
            /* [out] */ BOOL *isExempt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetIsEnabled( 
            /* [in] */ BOOL isEnabled) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMaxRecalls( 
            /* [in] */ ULONG maxRecalls) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMinRecallInterval( 
            /* [in] */ ULONG minIterval) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMaxRecallBuffers( 
            /* [in] */ ULONG maxBuffers) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Start( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StopIoctlThread( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FindRecall( 
            /* [in] */ GUID recallId,
            /* [out] */ IFsaFilterRecall **pRecall) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAdminExemption( 
            /* [in] */ BOOL isExempt) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFsaFilterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFsaFilter * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFsaFilter * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFsaFilter * This);
        
        HRESULT ( STDMETHODCALLTYPE *Cancel )( 
            IFsaFilter * This);
        
        HRESULT ( STDMETHODCALLTYPE *CancelRecall )( 
            IFsaFilter * This,
            /* [in] */ IFsaFilterRecall *pRecall);
        
        HRESULT ( STDMETHODCALLTYPE *CompareToIdentifier )( 
            IFsaFilter * This,
            /* [in] */ GUID id,
            /* [out] */ SHORT *pResult);
        
        HRESULT ( STDMETHODCALLTYPE *CompareToIFilter )( 
            IFsaFilter * This,
            /* [in] */ IFsaFilter *pFilter,
            /* [out] */ SHORT *pResult);
        
        HRESULT ( STDMETHODCALLTYPE *DeleteRecall )( 
            IFsaFilter * This,
            /* [in] */ IFsaFilterRecall *pRecall);
        
        HRESULT ( STDMETHODCALLTYPE *EnumRecalls )( 
            IFsaFilter * This,
            /* [out] */ IWsbEnum **ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE *GetIdentifier )( 
            IFsaFilter * This,
            /* [out] */ GUID *pId);
        
        HRESULT ( STDMETHODCALLTYPE *GetLogicalName )( 
            IFsaFilter * This,
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetMaxRecallBuffers )( 
            IFsaFilter * This,
            /* [out] */ ULONG *pMaxBuffers);
        
        HRESULT ( STDMETHODCALLTYPE *GetMaxRecalls )( 
            IFsaFilter * This,
            /* [out] */ ULONG *pMaxRecalls);
        
        HRESULT ( STDMETHODCALLTYPE *GetMinRecallInterval )( 
            IFsaFilter * This,
            /* [out] */ ULONG *pMinIterval);
        
        HRESULT ( STDMETHODCALLTYPE *GetState )( 
            IFsaFilter * This,
            /* [out] */ HSM_JOB_STATE *pState);
        
        HRESULT ( STDMETHODCALLTYPE *IsEnabled )( 
            IFsaFilter * This);
        
        HRESULT ( STDMETHODCALLTYPE *Pause )( 
            IFsaFilter * This);
        
        HRESULT ( STDMETHODCALLTYPE *Resume )( 
            IFsaFilter * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetAdminExemption )( 
            IFsaFilter * This,
            /* [out] */ BOOL *isExempt);
        
        HRESULT ( STDMETHODCALLTYPE *SetIsEnabled )( 
            IFsaFilter * This,
            /* [in] */ BOOL isEnabled);
        
        HRESULT ( STDMETHODCALLTYPE *SetMaxRecalls )( 
            IFsaFilter * This,
            /* [in] */ ULONG maxRecalls);
        
        HRESULT ( STDMETHODCALLTYPE *SetMinRecallInterval )( 
            IFsaFilter * This,
            /* [in] */ ULONG minIterval);
        
        HRESULT ( STDMETHODCALLTYPE *SetMaxRecallBuffers )( 
            IFsaFilter * This,
            /* [in] */ ULONG maxBuffers);
        
        HRESULT ( STDMETHODCALLTYPE *Start )( 
            IFsaFilter * This);
        
        HRESULT ( STDMETHODCALLTYPE *StopIoctlThread )( 
            IFsaFilter * This);
        
        HRESULT ( STDMETHODCALLTYPE *FindRecall )( 
            IFsaFilter * This,
            /* [in] */ GUID recallId,
            /* [out] */ IFsaFilterRecall **pRecall);
        
        HRESULT ( STDMETHODCALLTYPE *SetAdminExemption )( 
            IFsaFilter * This,
            /* [in] */ BOOL isExempt);
        
        END_INTERFACE
    } IFsaFilterVtbl;

    interface IFsaFilter
    {
        CONST_VTBL struct IFsaFilterVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFsaFilter_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFsaFilter_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFsaFilter_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFsaFilter_Cancel(This)	\
    (This)->lpVtbl -> Cancel(This)

#define IFsaFilter_CancelRecall(This,pRecall)	\
    (This)->lpVtbl -> CancelRecall(This,pRecall)

#define IFsaFilter_CompareToIdentifier(This,id,pResult)	\
    (This)->lpVtbl -> CompareToIdentifier(This,id,pResult)

#define IFsaFilter_CompareToIFilter(This,pFilter,pResult)	\
    (This)->lpVtbl -> CompareToIFilter(This,pFilter,pResult)

#define IFsaFilter_DeleteRecall(This,pRecall)	\
    (This)->lpVtbl -> DeleteRecall(This,pRecall)

#define IFsaFilter_EnumRecalls(This,ppEnum)	\
    (This)->lpVtbl -> EnumRecalls(This,ppEnum)

#define IFsaFilter_GetIdentifier(This,pId)	\
    (This)->lpVtbl -> GetIdentifier(This,pId)

#define IFsaFilter_GetLogicalName(This,pName,bufferSize)	\
    (This)->lpVtbl -> GetLogicalName(This,pName,bufferSize)

#define IFsaFilter_GetMaxRecallBuffers(This,pMaxBuffers)	\
    (This)->lpVtbl -> GetMaxRecallBuffers(This,pMaxBuffers)

#define IFsaFilter_GetMaxRecalls(This,pMaxRecalls)	\
    (This)->lpVtbl -> GetMaxRecalls(This,pMaxRecalls)

#define IFsaFilter_GetMinRecallInterval(This,pMinIterval)	\
    (This)->lpVtbl -> GetMinRecallInterval(This,pMinIterval)

#define IFsaFilter_GetState(This,pState)	\
    (This)->lpVtbl -> GetState(This,pState)

#define IFsaFilter_IsEnabled(This)	\
    (This)->lpVtbl -> IsEnabled(This)

#define IFsaFilter_Pause(This)	\
    (This)->lpVtbl -> Pause(This)

#define IFsaFilter_Resume(This)	\
    (This)->lpVtbl -> Resume(This)

#define IFsaFilter_GetAdminExemption(This,isExempt)	\
    (This)->lpVtbl -> GetAdminExemption(This,isExempt)

#define IFsaFilter_SetIsEnabled(This,isEnabled)	\
    (This)->lpVtbl -> SetIsEnabled(This,isEnabled)

#define IFsaFilter_SetMaxRecalls(This,maxRecalls)	\
    (This)->lpVtbl -> SetMaxRecalls(This,maxRecalls)

#define IFsaFilter_SetMinRecallInterval(This,minIterval)	\
    (This)->lpVtbl -> SetMinRecallInterval(This,minIterval)

#define IFsaFilter_SetMaxRecallBuffers(This,maxBuffers)	\
    (This)->lpVtbl -> SetMaxRecallBuffers(This,maxBuffers)

#define IFsaFilter_Start(This)	\
    (This)->lpVtbl -> Start(This)

#define IFsaFilter_StopIoctlThread(This)	\
    (This)->lpVtbl -> StopIoctlThread(This)

#define IFsaFilter_FindRecall(This,recallId,pRecall)	\
    (This)->lpVtbl -> FindRecall(This,recallId,pRecall)

#define IFsaFilter_SetAdminExemption(This,isExempt)	\
    (This)->lpVtbl -> SetAdminExemption(This,isExempt)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IFsaFilter_Cancel_Proxy( 
    IFsaFilter * This);


void __RPC_STUB IFsaFilter_Cancel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilter_CancelRecall_Proxy( 
    IFsaFilter * This,
    /* [in] */ IFsaFilterRecall *pRecall);


void __RPC_STUB IFsaFilter_CancelRecall_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilter_CompareToIdentifier_Proxy( 
    IFsaFilter * This,
    /* [in] */ GUID id,
    /* [out] */ SHORT *pResult);


void __RPC_STUB IFsaFilter_CompareToIdentifier_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilter_CompareToIFilter_Proxy( 
    IFsaFilter * This,
    /* [in] */ IFsaFilter *pFilter,
    /* [out] */ SHORT *pResult);


void __RPC_STUB IFsaFilter_CompareToIFilter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilter_DeleteRecall_Proxy( 
    IFsaFilter * This,
    /* [in] */ IFsaFilterRecall *pRecall);


void __RPC_STUB IFsaFilter_DeleteRecall_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilter_EnumRecalls_Proxy( 
    IFsaFilter * This,
    /* [out] */ IWsbEnum **ppEnum);


void __RPC_STUB IFsaFilter_EnumRecalls_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilter_GetIdentifier_Proxy( 
    IFsaFilter * This,
    /* [out] */ GUID *pId);


void __RPC_STUB IFsaFilter_GetIdentifier_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilter_GetLogicalName_Proxy( 
    IFsaFilter * This,
    /* [string][out][in] */ OLECHAR **pName,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IFsaFilter_GetLogicalName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilter_GetMaxRecallBuffers_Proxy( 
    IFsaFilter * This,
    /* [out] */ ULONG *pMaxBuffers);


void __RPC_STUB IFsaFilter_GetMaxRecallBuffers_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilter_GetMaxRecalls_Proxy( 
    IFsaFilter * This,
    /* [out] */ ULONG *pMaxRecalls);


void __RPC_STUB IFsaFilter_GetMaxRecalls_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilter_GetMinRecallInterval_Proxy( 
    IFsaFilter * This,
    /* [out] */ ULONG *pMinIterval);


void __RPC_STUB IFsaFilter_GetMinRecallInterval_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilter_GetState_Proxy( 
    IFsaFilter * This,
    /* [out] */ HSM_JOB_STATE *pState);


void __RPC_STUB IFsaFilter_GetState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilter_IsEnabled_Proxy( 
    IFsaFilter * This);


void __RPC_STUB IFsaFilter_IsEnabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilter_Pause_Proxy( 
    IFsaFilter * This);


void __RPC_STUB IFsaFilter_Pause_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilter_Resume_Proxy( 
    IFsaFilter * This);


void __RPC_STUB IFsaFilter_Resume_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilter_GetAdminExemption_Proxy( 
    IFsaFilter * This,
    /* [out] */ BOOL *isExempt);


void __RPC_STUB IFsaFilter_GetAdminExemption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilter_SetIsEnabled_Proxy( 
    IFsaFilter * This,
    /* [in] */ BOOL isEnabled);


void __RPC_STUB IFsaFilter_SetIsEnabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilter_SetMaxRecalls_Proxy( 
    IFsaFilter * This,
    /* [in] */ ULONG maxRecalls);


void __RPC_STUB IFsaFilter_SetMaxRecalls_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilter_SetMinRecallInterval_Proxy( 
    IFsaFilter * This,
    /* [in] */ ULONG minIterval);


void __RPC_STUB IFsaFilter_SetMinRecallInterval_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilter_SetMaxRecallBuffers_Proxy( 
    IFsaFilter * This,
    /* [in] */ ULONG maxBuffers);


void __RPC_STUB IFsaFilter_SetMaxRecallBuffers_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilter_Start_Proxy( 
    IFsaFilter * This);


void __RPC_STUB IFsaFilter_Start_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilter_StopIoctlThread_Proxy( 
    IFsaFilter * This);


void __RPC_STUB IFsaFilter_StopIoctlThread_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilter_FindRecall_Proxy( 
    IFsaFilter * This,
    /* [in] */ GUID recallId,
    /* [out] */ IFsaFilterRecall **pRecall);


void __RPC_STUB IFsaFilter_FindRecall_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilter_SetAdminExemption_Proxy( 
    IFsaFilter * This,
    /* [in] */ BOOL isExempt);


void __RPC_STUB IFsaFilter_SetAdminExemption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IFsaFilter_INTERFACE_DEFINED__ */


#ifndef __IFsaFilterClient_INTERFACE_DEFINED__
#define __IFsaFilterClient_INTERFACE_DEFINED__

/* interface IFsaFilterClient */
/* [unique][helpstring][uuid][object] */ 

typedef 
enum _FSA_FILTERCLIENT_COMPARE
    {	FSA_FILTERCLIENT_COMPARE_ID	= 0,
	FSA_FILTERCLIENT_COMPARE_MACHINE	= 1
    } 	FSA_FILTERCLIENT_COMPARE;


EXTERN_C const IID IID_IFsaFilterClient;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("560E5A02-DEDE-11d1-A9F5-00A0248903EA")
    IFsaFilterClient : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CompareBy( 
            /* [in] */ FSA_FILTERCLIENT_COMPARE by) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CompareToAuthenticationId( 
            /* [in] */ LONG luidHigh,
            /* [in] */ ULONG luidLow,
            /* [out] */ SHORT *pResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CompareToIClient( 
            /* [in] */ IFsaFilterClient *pClient,
            /* [out] */ SHORT *pResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CompareToMachineName( 
            /* [string][in] */ OLECHAR *name,
            /* [out] */ SHORT *pResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAuthenticationId( 
            /* [out] */ LONG *pLuidHigh,
            /* [out] */ ULONG *pluidLow) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDomainName( 
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLastRecallTime( 
            /* [out] */ FILETIME *pTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMachineName( 
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecallCount( 
            /* [out] */ ULONG *pCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUserName( 
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE HasRecallDisabled( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE HitRecallLimit( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAuthenticationId( 
            /* [in] */ LONG luidHigh,
            /* [in] */ ULONG luidLow) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDomainName( 
            /* [string][in] */ OLECHAR *pName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetHasRecallDisabled( 
            /* [in] */ BOOL isDisabled) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetHitRecallLimit( 
            /* [in] */ BOOL hitLimit) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetLastRecallTime( 
            /* [in] */ FILETIME time) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMachineName( 
            /* [string][in] */ OLECHAR *pName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRecallCount( 
            /* [in] */ ULONG count) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetUserName( 
            /* [string][in] */ OLECHAR *pName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StartIdentify( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetTokenSource( 
            /* [in] */ CHAR *source) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SendRecallInfo( 
            /* [in] */ IFsaFilterRecall *pRecall,
            /* [in] */ BOOL starting,
            /* [in] */ HRESULT rHr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IdentifyThread( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetIsAdmin( 
            /* [in] */ BOOLEAN isAdmin) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIsAdmin( 
            /* [out] */ BOOLEAN *isAdmin) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CheckRecallLimit( 
            /* [in] */ DWORD minRecallInterval,
            /* [in] */ DWORD maxRecalls,
            /* [in] */ BOOLEAN exemptAdmin) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFsaFilterClientVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFsaFilterClient * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFsaFilterClient * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFsaFilterClient * This);
        
        HRESULT ( STDMETHODCALLTYPE *CompareBy )( 
            IFsaFilterClient * This,
            /* [in] */ FSA_FILTERCLIENT_COMPARE by);
        
        HRESULT ( STDMETHODCALLTYPE *CompareToAuthenticationId )( 
            IFsaFilterClient * This,
            /* [in] */ LONG luidHigh,
            /* [in] */ ULONG luidLow,
            /* [out] */ SHORT *pResult);
        
        HRESULT ( STDMETHODCALLTYPE *CompareToIClient )( 
            IFsaFilterClient * This,
            /* [in] */ IFsaFilterClient *pClient,
            /* [out] */ SHORT *pResult);
        
        HRESULT ( STDMETHODCALLTYPE *CompareToMachineName )( 
            IFsaFilterClient * This,
            /* [string][in] */ OLECHAR *name,
            /* [out] */ SHORT *pResult);
        
        HRESULT ( STDMETHODCALLTYPE *GetAuthenticationId )( 
            IFsaFilterClient * This,
            /* [out] */ LONG *pLuidHigh,
            /* [out] */ ULONG *pluidLow);
        
        HRESULT ( STDMETHODCALLTYPE *GetDomainName )( 
            IFsaFilterClient * This,
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetLastRecallTime )( 
            IFsaFilterClient * This,
            /* [out] */ FILETIME *pTime);
        
        HRESULT ( STDMETHODCALLTYPE *GetMachineName )( 
            IFsaFilterClient * This,
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetRecallCount )( 
            IFsaFilterClient * This,
            /* [out] */ ULONG *pCount);
        
        HRESULT ( STDMETHODCALLTYPE *GetUserName )( 
            IFsaFilterClient * This,
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *HasRecallDisabled )( 
            IFsaFilterClient * This);
        
        HRESULT ( STDMETHODCALLTYPE *HitRecallLimit )( 
            IFsaFilterClient * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetAuthenticationId )( 
            IFsaFilterClient * This,
            /* [in] */ LONG luidHigh,
            /* [in] */ ULONG luidLow);
        
        HRESULT ( STDMETHODCALLTYPE *SetDomainName )( 
            IFsaFilterClient * This,
            /* [string][in] */ OLECHAR *pName);
        
        HRESULT ( STDMETHODCALLTYPE *SetHasRecallDisabled )( 
            IFsaFilterClient * This,
            /* [in] */ BOOL isDisabled);
        
        HRESULT ( STDMETHODCALLTYPE *SetHitRecallLimit )( 
            IFsaFilterClient * This,
            /* [in] */ BOOL hitLimit);
        
        HRESULT ( STDMETHODCALLTYPE *SetLastRecallTime )( 
            IFsaFilterClient * This,
            /* [in] */ FILETIME time);
        
        HRESULT ( STDMETHODCALLTYPE *SetMachineName )( 
            IFsaFilterClient * This,
            /* [string][in] */ OLECHAR *pName);
        
        HRESULT ( STDMETHODCALLTYPE *SetRecallCount )( 
            IFsaFilterClient * This,
            /* [in] */ ULONG count);
        
        HRESULT ( STDMETHODCALLTYPE *SetUserName )( 
            IFsaFilterClient * This,
            /* [string][in] */ OLECHAR *pName);
        
        HRESULT ( STDMETHODCALLTYPE *StartIdentify )( 
            IFsaFilterClient * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetTokenSource )( 
            IFsaFilterClient * This,
            /* [in] */ CHAR *source);
        
        HRESULT ( STDMETHODCALLTYPE *SendRecallInfo )( 
            IFsaFilterClient * This,
            /* [in] */ IFsaFilterRecall *pRecall,
            /* [in] */ BOOL starting,
            /* [in] */ HRESULT rHr);
        
        HRESULT ( STDMETHODCALLTYPE *IdentifyThread )( 
            IFsaFilterClient * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetIsAdmin )( 
            IFsaFilterClient * This,
            /* [in] */ BOOLEAN isAdmin);
        
        HRESULT ( STDMETHODCALLTYPE *GetIsAdmin )( 
            IFsaFilterClient * This,
            /* [out] */ BOOLEAN *isAdmin);
        
        HRESULT ( STDMETHODCALLTYPE *CheckRecallLimit )( 
            IFsaFilterClient * This,
            /* [in] */ DWORD minRecallInterval,
            /* [in] */ DWORD maxRecalls,
            /* [in] */ BOOLEAN exemptAdmin);
        
        END_INTERFACE
    } IFsaFilterClientVtbl;

    interface IFsaFilterClient
    {
        CONST_VTBL struct IFsaFilterClientVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFsaFilterClient_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFsaFilterClient_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFsaFilterClient_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFsaFilterClient_CompareBy(This,by)	\
    (This)->lpVtbl -> CompareBy(This,by)

#define IFsaFilterClient_CompareToAuthenticationId(This,luidHigh,luidLow,pResult)	\
    (This)->lpVtbl -> CompareToAuthenticationId(This,luidHigh,luidLow,pResult)

#define IFsaFilterClient_CompareToIClient(This,pClient,pResult)	\
    (This)->lpVtbl -> CompareToIClient(This,pClient,pResult)

#define IFsaFilterClient_CompareToMachineName(This,name,pResult)	\
    (This)->lpVtbl -> CompareToMachineName(This,name,pResult)

#define IFsaFilterClient_GetAuthenticationId(This,pLuidHigh,pluidLow)	\
    (This)->lpVtbl -> GetAuthenticationId(This,pLuidHigh,pluidLow)

#define IFsaFilterClient_GetDomainName(This,pName,bufferSize)	\
    (This)->lpVtbl -> GetDomainName(This,pName,bufferSize)

#define IFsaFilterClient_GetLastRecallTime(This,pTime)	\
    (This)->lpVtbl -> GetLastRecallTime(This,pTime)

#define IFsaFilterClient_GetMachineName(This,pName,bufferSize)	\
    (This)->lpVtbl -> GetMachineName(This,pName,bufferSize)

#define IFsaFilterClient_GetRecallCount(This,pCount)	\
    (This)->lpVtbl -> GetRecallCount(This,pCount)

#define IFsaFilterClient_GetUserName(This,pName,bufferSize)	\
    (This)->lpVtbl -> GetUserName(This,pName,bufferSize)

#define IFsaFilterClient_HasRecallDisabled(This)	\
    (This)->lpVtbl -> HasRecallDisabled(This)

#define IFsaFilterClient_HitRecallLimit(This)	\
    (This)->lpVtbl -> HitRecallLimit(This)

#define IFsaFilterClient_SetAuthenticationId(This,luidHigh,luidLow)	\
    (This)->lpVtbl -> SetAuthenticationId(This,luidHigh,luidLow)

#define IFsaFilterClient_SetDomainName(This,pName)	\
    (This)->lpVtbl -> SetDomainName(This,pName)

#define IFsaFilterClient_SetHasRecallDisabled(This,isDisabled)	\
    (This)->lpVtbl -> SetHasRecallDisabled(This,isDisabled)

#define IFsaFilterClient_SetHitRecallLimit(This,hitLimit)	\
    (This)->lpVtbl -> SetHitRecallLimit(This,hitLimit)

#define IFsaFilterClient_SetLastRecallTime(This,time)	\
    (This)->lpVtbl -> SetLastRecallTime(This,time)

#define IFsaFilterClient_SetMachineName(This,pName)	\
    (This)->lpVtbl -> SetMachineName(This,pName)

#define IFsaFilterClient_SetRecallCount(This,count)	\
    (This)->lpVtbl -> SetRecallCount(This,count)

#define IFsaFilterClient_SetUserName(This,pName)	\
    (This)->lpVtbl -> SetUserName(This,pName)

#define IFsaFilterClient_StartIdentify(This)	\
    (This)->lpVtbl -> StartIdentify(This)

#define IFsaFilterClient_SetTokenSource(This,source)	\
    (This)->lpVtbl -> SetTokenSource(This,source)

#define IFsaFilterClient_SendRecallInfo(This,pRecall,starting,rHr)	\
    (This)->lpVtbl -> SendRecallInfo(This,pRecall,starting,rHr)

#define IFsaFilterClient_IdentifyThread(This)	\
    (This)->lpVtbl -> IdentifyThread(This)

#define IFsaFilterClient_SetIsAdmin(This,isAdmin)	\
    (This)->lpVtbl -> SetIsAdmin(This,isAdmin)

#define IFsaFilterClient_GetIsAdmin(This,isAdmin)	\
    (This)->lpVtbl -> GetIsAdmin(This,isAdmin)

#define IFsaFilterClient_CheckRecallLimit(This,minRecallInterval,maxRecalls,exemptAdmin)	\
    (This)->lpVtbl -> CheckRecallLimit(This,minRecallInterval,maxRecalls,exemptAdmin)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IFsaFilterClient_CompareBy_Proxy( 
    IFsaFilterClient * This,
    /* [in] */ FSA_FILTERCLIENT_COMPARE by);


void __RPC_STUB IFsaFilterClient_CompareBy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterClient_CompareToAuthenticationId_Proxy( 
    IFsaFilterClient * This,
    /* [in] */ LONG luidHigh,
    /* [in] */ ULONG luidLow,
    /* [out] */ SHORT *pResult);


void __RPC_STUB IFsaFilterClient_CompareToAuthenticationId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterClient_CompareToIClient_Proxy( 
    IFsaFilterClient * This,
    /* [in] */ IFsaFilterClient *pClient,
    /* [out] */ SHORT *pResult);


void __RPC_STUB IFsaFilterClient_CompareToIClient_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterClient_CompareToMachineName_Proxy( 
    IFsaFilterClient * This,
    /* [string][in] */ OLECHAR *name,
    /* [out] */ SHORT *pResult);


void __RPC_STUB IFsaFilterClient_CompareToMachineName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterClient_GetAuthenticationId_Proxy( 
    IFsaFilterClient * This,
    /* [out] */ LONG *pLuidHigh,
    /* [out] */ ULONG *pluidLow);


void __RPC_STUB IFsaFilterClient_GetAuthenticationId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterClient_GetDomainName_Proxy( 
    IFsaFilterClient * This,
    /* [string][out][in] */ OLECHAR **pName,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IFsaFilterClient_GetDomainName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterClient_GetLastRecallTime_Proxy( 
    IFsaFilterClient * This,
    /* [out] */ FILETIME *pTime);


void __RPC_STUB IFsaFilterClient_GetLastRecallTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterClient_GetMachineName_Proxy( 
    IFsaFilterClient * This,
    /* [string][out][in] */ OLECHAR **pName,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IFsaFilterClient_GetMachineName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterClient_GetRecallCount_Proxy( 
    IFsaFilterClient * This,
    /* [out] */ ULONG *pCount);


void __RPC_STUB IFsaFilterClient_GetRecallCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterClient_GetUserName_Proxy( 
    IFsaFilterClient * This,
    /* [string][out][in] */ OLECHAR **pName,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IFsaFilterClient_GetUserName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterClient_HasRecallDisabled_Proxy( 
    IFsaFilterClient * This);


void __RPC_STUB IFsaFilterClient_HasRecallDisabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterClient_HitRecallLimit_Proxy( 
    IFsaFilterClient * This);


void __RPC_STUB IFsaFilterClient_HitRecallLimit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterClient_SetAuthenticationId_Proxy( 
    IFsaFilterClient * This,
    /* [in] */ LONG luidHigh,
    /* [in] */ ULONG luidLow);


void __RPC_STUB IFsaFilterClient_SetAuthenticationId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterClient_SetDomainName_Proxy( 
    IFsaFilterClient * This,
    /* [string][in] */ OLECHAR *pName);


void __RPC_STUB IFsaFilterClient_SetDomainName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterClient_SetHasRecallDisabled_Proxy( 
    IFsaFilterClient * This,
    /* [in] */ BOOL isDisabled);


void __RPC_STUB IFsaFilterClient_SetHasRecallDisabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterClient_SetHitRecallLimit_Proxy( 
    IFsaFilterClient * This,
    /* [in] */ BOOL hitLimit);


void __RPC_STUB IFsaFilterClient_SetHitRecallLimit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterClient_SetLastRecallTime_Proxy( 
    IFsaFilterClient * This,
    /* [in] */ FILETIME time);


void __RPC_STUB IFsaFilterClient_SetLastRecallTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterClient_SetMachineName_Proxy( 
    IFsaFilterClient * This,
    /* [string][in] */ OLECHAR *pName);


void __RPC_STUB IFsaFilterClient_SetMachineName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterClient_SetRecallCount_Proxy( 
    IFsaFilterClient * This,
    /* [in] */ ULONG count);


void __RPC_STUB IFsaFilterClient_SetRecallCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterClient_SetUserName_Proxy( 
    IFsaFilterClient * This,
    /* [string][in] */ OLECHAR *pName);


void __RPC_STUB IFsaFilterClient_SetUserName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterClient_StartIdentify_Proxy( 
    IFsaFilterClient * This);


void __RPC_STUB IFsaFilterClient_StartIdentify_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterClient_SetTokenSource_Proxy( 
    IFsaFilterClient * This,
    /* [in] */ CHAR *source);


void __RPC_STUB IFsaFilterClient_SetTokenSource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterClient_SendRecallInfo_Proxy( 
    IFsaFilterClient * This,
    /* [in] */ IFsaFilterRecall *pRecall,
    /* [in] */ BOOL starting,
    /* [in] */ HRESULT rHr);


void __RPC_STUB IFsaFilterClient_SendRecallInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterClient_IdentifyThread_Proxy( 
    IFsaFilterClient * This);


void __RPC_STUB IFsaFilterClient_IdentifyThread_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterClient_SetIsAdmin_Proxy( 
    IFsaFilterClient * This,
    /* [in] */ BOOLEAN isAdmin);


void __RPC_STUB IFsaFilterClient_SetIsAdmin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterClient_GetIsAdmin_Proxy( 
    IFsaFilterClient * This,
    /* [out] */ BOOLEAN *isAdmin);


void __RPC_STUB IFsaFilterClient_GetIsAdmin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterClient_CheckRecallLimit_Proxy( 
    IFsaFilterClient * This,
    /* [in] */ DWORD minRecallInterval,
    /* [in] */ DWORD maxRecalls,
    /* [in] */ BOOLEAN exemptAdmin);


void __RPC_STUB IFsaFilterClient_CheckRecallLimit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IFsaFilterClient_INTERFACE_DEFINED__ */


#ifndef __IFsaFilterRecall_INTERFACE_DEFINED__
#define __IFsaFilterRecall_INTERFACE_DEFINED__

/* interface IFsaFilterRecall */
/* [unique][helpstring][uuid][object] */ 

typedef 
enum _FSA_RECALL_COMPARE
    {	FSA_RECALL_COMPARE_ID	= 0,
	FSA_RECALL_COMPARE_IRECALL	= 1,
	FSA_RECALL_COMPARE_CONTEXT_ID	= 2
    } 	FSA_RECALL_COMPARE;


EXTERN_C const IID IID_IFsaFilterRecall;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5E176F27-6F53-4C84-B935-9259297669B0")
    IFsaFilterRecall : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CompareToIdentifier( 
            /* [in] */ GUID id,
            /* [out] */ SHORT *pResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CompareToIRecall( 
            /* [in] */ IFsaFilterRecall *pRecall,
            /* [out] */ SHORT *pResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CompareToDriversRecallId( 
            /* [in] */ ULONGLONG id,
            /* [out] */ SHORT *pResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CompareToDriversContextId( 
            /* [in] */ ULONGLONG id,
            /* [out] */ SHORT *pResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CompareBy( 
            /* [in] */ FSA_RECALL_COMPARE by) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIdentifier( 
            /* [out] */ GUID *pId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMode( 
            /* [out] */ ULONG *pMode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOffset( 
            /* [out] */ LONGLONG *pOffset) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPath( 
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetResource( 
            /* [out] */ IFsaResource **ppResource) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecallFlags( 
            /* [out] */ ULONG *recallFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSession( 
            /* [out] */ IHsmSession **ppSession) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSize( 
            /* [out] */ LONGLONG *pSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetState( 
            /* [out] */ HSM_JOB_STATE *pState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUserName( 
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE HasCompleted( 
            /* [in] */ HRESULT resultHr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WasCancelled( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateLocalStream( 
            /* [out] */ IStream **ppStream) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CheckRecallLimit( 
            /* [in] */ DWORD minRecallInterval,
            /* [in] */ DWORD maxRecalls,
            /* [in] */ BOOLEAN exemptAdmin) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddClient( 
            /* [in] */ IFsaFilterClient *pWaitingClient) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFsaFilterRecallVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFsaFilterRecall * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFsaFilterRecall * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFsaFilterRecall * This);
        
        HRESULT ( STDMETHODCALLTYPE *CompareToIdentifier )( 
            IFsaFilterRecall * This,
            /* [in] */ GUID id,
            /* [out] */ SHORT *pResult);
        
        HRESULT ( STDMETHODCALLTYPE *CompareToIRecall )( 
            IFsaFilterRecall * This,
            /* [in] */ IFsaFilterRecall *pRecall,
            /* [out] */ SHORT *pResult);
        
        HRESULT ( STDMETHODCALLTYPE *CompareToDriversRecallId )( 
            IFsaFilterRecall * This,
            /* [in] */ ULONGLONG id,
            /* [out] */ SHORT *pResult);
        
        HRESULT ( STDMETHODCALLTYPE *CompareToDriversContextId )( 
            IFsaFilterRecall * This,
            /* [in] */ ULONGLONG id,
            /* [out] */ SHORT *pResult);
        
        HRESULT ( STDMETHODCALLTYPE *CompareBy )( 
            IFsaFilterRecall * This,
            /* [in] */ FSA_RECALL_COMPARE by);
        
        HRESULT ( STDMETHODCALLTYPE *GetIdentifier )( 
            IFsaFilterRecall * This,
            /* [out] */ GUID *pId);
        
        HRESULT ( STDMETHODCALLTYPE *GetMode )( 
            IFsaFilterRecall * This,
            /* [out] */ ULONG *pMode);
        
        HRESULT ( STDMETHODCALLTYPE *GetOffset )( 
            IFsaFilterRecall * This,
            /* [out] */ LONGLONG *pOffset);
        
        HRESULT ( STDMETHODCALLTYPE *GetPath )( 
            IFsaFilterRecall * This,
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetResource )( 
            IFsaFilterRecall * This,
            /* [out] */ IFsaResource **ppResource);
        
        HRESULT ( STDMETHODCALLTYPE *GetRecallFlags )( 
            IFsaFilterRecall * This,
            /* [out] */ ULONG *recallFlags);
        
        HRESULT ( STDMETHODCALLTYPE *GetSession )( 
            IFsaFilterRecall * This,
            /* [out] */ IHsmSession **ppSession);
        
        HRESULT ( STDMETHODCALLTYPE *GetSize )( 
            IFsaFilterRecall * This,
            /* [out] */ LONGLONG *pSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetState )( 
            IFsaFilterRecall * This,
            /* [out] */ HSM_JOB_STATE *pState);
        
        HRESULT ( STDMETHODCALLTYPE *GetUserName )( 
            IFsaFilterRecall * This,
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *HasCompleted )( 
            IFsaFilterRecall * This,
            /* [in] */ HRESULT resultHr);
        
        HRESULT ( STDMETHODCALLTYPE *WasCancelled )( 
            IFsaFilterRecall * This);
        
        HRESULT ( STDMETHODCALLTYPE *CreateLocalStream )( 
            IFsaFilterRecall * This,
            /* [out] */ IStream **ppStream);
        
        HRESULT ( STDMETHODCALLTYPE *CheckRecallLimit )( 
            IFsaFilterRecall * This,
            /* [in] */ DWORD minRecallInterval,
            /* [in] */ DWORD maxRecalls,
            /* [in] */ BOOLEAN exemptAdmin);
        
        HRESULT ( STDMETHODCALLTYPE *AddClient )( 
            IFsaFilterRecall * This,
            /* [in] */ IFsaFilterClient *pWaitingClient);
        
        END_INTERFACE
    } IFsaFilterRecallVtbl;

    interface IFsaFilterRecall
    {
        CONST_VTBL struct IFsaFilterRecallVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFsaFilterRecall_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFsaFilterRecall_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFsaFilterRecall_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFsaFilterRecall_CompareToIdentifier(This,id,pResult)	\
    (This)->lpVtbl -> CompareToIdentifier(This,id,pResult)

#define IFsaFilterRecall_CompareToIRecall(This,pRecall,pResult)	\
    (This)->lpVtbl -> CompareToIRecall(This,pRecall,pResult)

#define IFsaFilterRecall_CompareToDriversRecallId(This,id,pResult)	\
    (This)->lpVtbl -> CompareToDriversRecallId(This,id,pResult)

#define IFsaFilterRecall_CompareToDriversContextId(This,id,pResult)	\
    (This)->lpVtbl -> CompareToDriversContextId(This,id,pResult)

#define IFsaFilterRecall_CompareBy(This,by)	\
    (This)->lpVtbl -> CompareBy(This,by)

#define IFsaFilterRecall_GetIdentifier(This,pId)	\
    (This)->lpVtbl -> GetIdentifier(This,pId)

#define IFsaFilterRecall_GetMode(This,pMode)	\
    (This)->lpVtbl -> GetMode(This,pMode)

#define IFsaFilterRecall_GetOffset(This,pOffset)	\
    (This)->lpVtbl -> GetOffset(This,pOffset)

#define IFsaFilterRecall_GetPath(This,pName,bufferSize)	\
    (This)->lpVtbl -> GetPath(This,pName,bufferSize)

#define IFsaFilterRecall_GetResource(This,ppResource)	\
    (This)->lpVtbl -> GetResource(This,ppResource)

#define IFsaFilterRecall_GetRecallFlags(This,recallFlags)	\
    (This)->lpVtbl -> GetRecallFlags(This,recallFlags)

#define IFsaFilterRecall_GetSession(This,ppSession)	\
    (This)->lpVtbl -> GetSession(This,ppSession)

#define IFsaFilterRecall_GetSize(This,pSize)	\
    (This)->lpVtbl -> GetSize(This,pSize)

#define IFsaFilterRecall_GetState(This,pState)	\
    (This)->lpVtbl -> GetState(This,pState)

#define IFsaFilterRecall_GetUserName(This,pName,bufferSize)	\
    (This)->lpVtbl -> GetUserName(This,pName,bufferSize)

#define IFsaFilterRecall_HasCompleted(This,resultHr)	\
    (This)->lpVtbl -> HasCompleted(This,resultHr)

#define IFsaFilterRecall_WasCancelled(This)	\
    (This)->lpVtbl -> WasCancelled(This)

#define IFsaFilterRecall_CreateLocalStream(This,ppStream)	\
    (This)->lpVtbl -> CreateLocalStream(This,ppStream)

#define IFsaFilterRecall_CheckRecallLimit(This,minRecallInterval,maxRecalls,exemptAdmin)	\
    (This)->lpVtbl -> CheckRecallLimit(This,minRecallInterval,maxRecalls,exemptAdmin)

#define IFsaFilterRecall_AddClient(This,pWaitingClient)	\
    (This)->lpVtbl -> AddClient(This,pWaitingClient)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IFsaFilterRecall_CompareToIdentifier_Proxy( 
    IFsaFilterRecall * This,
    /* [in] */ GUID id,
    /* [out] */ SHORT *pResult);


void __RPC_STUB IFsaFilterRecall_CompareToIdentifier_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterRecall_CompareToIRecall_Proxy( 
    IFsaFilterRecall * This,
    /* [in] */ IFsaFilterRecall *pRecall,
    /* [out] */ SHORT *pResult);


void __RPC_STUB IFsaFilterRecall_CompareToIRecall_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterRecall_CompareToDriversRecallId_Proxy( 
    IFsaFilterRecall * This,
    /* [in] */ ULONGLONG id,
    /* [out] */ SHORT *pResult);


void __RPC_STUB IFsaFilterRecall_CompareToDriversRecallId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterRecall_CompareToDriversContextId_Proxy( 
    IFsaFilterRecall * This,
    /* [in] */ ULONGLONG id,
    /* [out] */ SHORT *pResult);


void __RPC_STUB IFsaFilterRecall_CompareToDriversContextId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterRecall_CompareBy_Proxy( 
    IFsaFilterRecall * This,
    /* [in] */ FSA_RECALL_COMPARE by);


void __RPC_STUB IFsaFilterRecall_CompareBy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterRecall_GetIdentifier_Proxy( 
    IFsaFilterRecall * This,
    /* [out] */ GUID *pId);


void __RPC_STUB IFsaFilterRecall_GetIdentifier_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterRecall_GetMode_Proxy( 
    IFsaFilterRecall * This,
    /* [out] */ ULONG *pMode);


void __RPC_STUB IFsaFilterRecall_GetMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterRecall_GetOffset_Proxy( 
    IFsaFilterRecall * This,
    /* [out] */ LONGLONG *pOffset);


void __RPC_STUB IFsaFilterRecall_GetOffset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterRecall_GetPath_Proxy( 
    IFsaFilterRecall * This,
    /* [string][out][in] */ OLECHAR **pName,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IFsaFilterRecall_GetPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterRecall_GetResource_Proxy( 
    IFsaFilterRecall * This,
    /* [out] */ IFsaResource **ppResource);


void __RPC_STUB IFsaFilterRecall_GetResource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterRecall_GetRecallFlags_Proxy( 
    IFsaFilterRecall * This,
    /* [out] */ ULONG *recallFlags);


void __RPC_STUB IFsaFilterRecall_GetRecallFlags_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterRecall_GetSession_Proxy( 
    IFsaFilterRecall * This,
    /* [out] */ IHsmSession **ppSession);


void __RPC_STUB IFsaFilterRecall_GetSession_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterRecall_GetSize_Proxy( 
    IFsaFilterRecall * This,
    /* [out] */ LONGLONG *pSize);


void __RPC_STUB IFsaFilterRecall_GetSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterRecall_GetState_Proxy( 
    IFsaFilterRecall * This,
    /* [out] */ HSM_JOB_STATE *pState);


void __RPC_STUB IFsaFilterRecall_GetState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterRecall_GetUserName_Proxy( 
    IFsaFilterRecall * This,
    /* [string][out][in] */ OLECHAR **pName,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IFsaFilterRecall_GetUserName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterRecall_HasCompleted_Proxy( 
    IFsaFilterRecall * This,
    /* [in] */ HRESULT resultHr);


void __RPC_STUB IFsaFilterRecall_HasCompleted_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterRecall_WasCancelled_Proxy( 
    IFsaFilterRecall * This);


void __RPC_STUB IFsaFilterRecall_WasCancelled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterRecall_CreateLocalStream_Proxy( 
    IFsaFilterRecall * This,
    /* [out] */ IStream **ppStream);


void __RPC_STUB IFsaFilterRecall_CreateLocalStream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterRecall_CheckRecallLimit_Proxy( 
    IFsaFilterRecall * This,
    /* [in] */ DWORD minRecallInterval,
    /* [in] */ DWORD maxRecalls,
    /* [in] */ BOOLEAN exemptAdmin);


void __RPC_STUB IFsaFilterRecall_CheckRecallLimit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterRecall_AddClient_Proxy( 
    IFsaFilterRecall * This,
    /* [in] */ IFsaFilterClient *pWaitingClient);


void __RPC_STUB IFsaFilterRecall_AddClient_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IFsaFilterRecall_INTERFACE_DEFINED__ */


#ifndef __IFsaResource_INTERFACE_DEFINED__
#define __IFsaResource_INTERFACE_DEFINED__

/* interface IFsaResource */
/* [unique][helpstring][uuid][object] */ 

typedef 
enum _FSA_RESOURCE_COMPARE
    {	FSA_RESOURCE_COMPARE_ID	= 0,
	FSA_RESOURCE_COMPARE_NAME	= 1,
	FSA_RESOURCE_COMPARE_PATH	= 2,
	FSA_RESOURCE_COMPARE_ALTERNATEPATH	= 3,
	FSA_RESOURCE_COMPARE_SERIAL	= 4,
	FSA_RESOURCE_COMPARE_USER_NAME	= 5,
	FSA_RESOURCE_COMPARE_STICKY_NAME	= 6
    } 	FSA_RESOURCE_COMPARE;


EXTERN_C const IID IID_IFsaResource;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("172F71CD-A452-4005-8E3E-7BCEAE124D53")
    IFsaResource : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AddPremigrated( 
            /* [in] */ IFsaScanItem *pScanItem,
            /* [in] */ LONGLONG offset,
            /* [in] */ LONGLONG size,
            /* [in] */ BOOL isWaitingForClose,
            /* [in] */ LONGLONG usn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddTruncated( 
            /* [in] */ IFsaScanItem *pScanItem,
            /* [in] */ LONGLONG offset,
            /* [in] */ LONGLONG size) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BeginSession( 
            /* [string][in] */ OLECHAR *name,
            /* [in] */ ULONG logControl,
            /* [in] */ ULONG runId,
            /* [in] */ ULONG subRunId,
            /* [out] */ IHsmSession **ppSession) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BeginValidate( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CheckForValidate( 
            /* [in] */ BOOL bForceValidate) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CompareBy( 
            /* [in] */ FSA_RESOURCE_COMPARE by) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CompareToAlternatePath( 
            /* [string][in] */ OLECHAR *path,
            /* [out] */ SHORT *pResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CompareToIdentifier( 
            /* [in] */ GUID id,
            /* [out] */ SHORT *pResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CompareToIResource( 
            /* [in] */ IFsaResource *pResource,
            /* [out] */ SHORT *pResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CompareToName( 
            /* [string][in] */ OLECHAR *name,
            /* [out] */ SHORT *pResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CompareToUserName( 
            /* [string][in] */ OLECHAR *userName,
            /* [out] */ SHORT *pResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CompareToPath( 
            /* [string][in] */ OLECHAR *path,
            /* [out] */ SHORT *pResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CompareToSerial( 
            /* [in] */ ULONG serial,
            /* [out] */ SHORT *pResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CompareToStickyName( 
            /* [string][in] */ OLECHAR *name,
            /* [out] */ SHORT *pResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateDefaultRules( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EndSession( 
            /* [in] */ IHsmSession *pSession) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EndValidate( 
            /* [in] */ HSM_JOB_STATE state) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumDefaultRules( 
            /* [out] */ IWsbEnum **ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FindFirst( 
            /* [string][in] */ OLECHAR *path,
            /* [in] */ IHsmSession *pSession,
            /* [out] */ IFsaScanItem **ppScanItem) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FindFirstInRPIndex( 
            /* [in] */ IHsmSession *pSession,
            /* [out] */ IFsaScanItem **ppScanItem) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FindFirstInDbIndex( 
            /* [in] */ IHsmSession *pSession,
            /* [out] */ IFsaScanItem **ppScanItem) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FindNext( 
            /* [in] */ IFsaScanItem *pScanItem) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FindNextInRPIndex( 
            /* [in] */ IFsaScanItem *pScanItem) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FindNextInDbIndex( 
            /* [in] */ IFsaScanItem *pScanItem) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FindFileId( 
            /* [in] */ LONGLONG fileId,
            /* [in] */ IHsmSession *pSession,
            /* [out] */ IFsaScanItem **ppScanItem) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FindObjectId( 
            /* [in] */ LONGLONG objIdHi,
            /* [in] */ LONGLONG objIdLo,
            /* [in] */ IHsmSession *pSession,
            /* [out] */ IFsaScanItem **ppScanItem) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAlternatePath( 
            /* [string][out][in] */ OLECHAR **pPath,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDefaultRules( 
            /* [out] */ IWsbCollection **ppCollection) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDbPath( 
            /* [string][out][in] */ OLECHAR **pPath,
            ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUnmanageDbPath( 
            /* [string][out][in] */ OLECHAR **pPath,
            ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFreeLevel( 
            /* [out] */ ULONG *pLevel) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFsName( 
            /* [string][out][in] */ OLECHAR **pName,
            ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetHsmEngine( 
            /* [out] */ IHsmFsaTskMgr **ppEngine) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetHsmLevel( 
            /* [out] */ ULONG *pLevel) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIdentifier( 
            /* [out] */ GUID *pId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLogicalName( 
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetManageableItemLogicalSize( 
            /* [out] */ LONGLONG *pSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetManageableItemAccessTime( 
            /* [out] */ BOOL *isRelative,
            /* [out] */ FILETIME *pTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetManagingHsm( 
            /* [out] */ GUID *pId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetName( 
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOldPath( 
            /* [string][out][in] */ OLECHAR **pPath,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPath( 
            /* [string][out][in] */ OLECHAR **pPath,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSerial( 
            /* [out] */ ULONG *serial) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSizes( 
            /* [out] */ LONGLONG *pTotal,
            /* [out] */ LONGLONG *pFree,
            /* [out] */ LONGLONG *pPremigrated,
            /* [out] */ LONGLONG *pTruncated) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTruncator( 
            /* [out] */ IFsaTruncator **ppTruncator) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUncPath( 
            /* [string][out][in] */ OLECHAR **pPath,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUserFriendlyName( 
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStickyName( 
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsActive( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsAvailable( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsDeletePending( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsManaged( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Manage( 
            /* [in] */ IFsaScanItem *pScanItem,
            /* [in] */ LONGLONG offset,
            /* [in] */ LONGLONG size,
            /* [in] */ GUID storagePoolId,
            /* [in] */ BOOL truncate) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ManagedBy( 
            /* [in] */ GUID hsmId,
            /* [in] */ ULONG hsmLevel,
            /* [in] */ BOOL release) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE NeedsRepair( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ProcessResult( 
            /* [in] */ IFsaPostIt *pResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Recall( 
            /* [in] */ IFsaScanItem *pScanItem,
            /* [in] */ LONGLONG offset,
            /* [in] */ LONGLONG size,
            /* [in] */ BOOL deletePlaceholder) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemovePremigrated( 
            /* [in] */ IFsaScanItem *pScanItem,
            /* [in] */ LONGLONG offset,
            /* [in] */ LONGLONG size) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveTruncated( 
            /* [in] */ IFsaScanItem *pScanItem,
            /* [in] */ LONGLONG offset,
            /* [in] */ LONGLONG size) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetHsmLevel( 
            /* [in] */ ULONG level) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetIsActive( 
            /* [in] */ BOOL isActive) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetIsAvailable( 
            /* [in] */ BOOL isActive) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetIsDeletePending( 
            /* [in] */ BOOL isDeletePending) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetManageableItemLogicalSize( 
            /* [in] */ LONGLONG pSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetManageableItemAccessTime( 
            /* [in] */ BOOL isRelative,
            /* [in] */ FILETIME pTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSerial( 
            /* [in] */ ULONG serial) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StartJob( 
            /* [string][in] */ OLECHAR *startingPath,
            /* [in] */ IHsmSession *pSession) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StartJobSession( 
            /* [in] */ IHsmJob *pJob,
            /* [in] */ ULONG subRunId,
            /* [out] */ IHsmSession **ppSession) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Validate( 
            /* [in] */ IFsaScanItem *pScanItem,
            /* [in] */ LONGLONG offset,
            /* [in] */ LONGLONG size,
            /* [in] */ LONGLONG usn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetupValidateJob( 
            /* [in] */ SYSTEMTIME runtime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUsnId( 
            /* [out] */ ULONGLONG *usnId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ValidateForTruncate( 
            /* [in] */ IFsaScanItem *pScanItem,
            /* [in] */ LONGLONG offset,
            /* [in] */ LONGLONG size,
            /* [in] */ LONGLONG usn) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFsaResourceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFsaResource * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFsaResource * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFsaResource * This);
        
        HRESULT ( STDMETHODCALLTYPE *AddPremigrated )( 
            IFsaResource * This,
            /* [in] */ IFsaScanItem *pScanItem,
            /* [in] */ LONGLONG offset,
            /* [in] */ LONGLONG size,
            /* [in] */ BOOL isWaitingForClose,
            /* [in] */ LONGLONG usn);
        
        HRESULT ( STDMETHODCALLTYPE *AddTruncated )( 
            IFsaResource * This,
            /* [in] */ IFsaScanItem *pScanItem,
            /* [in] */ LONGLONG offset,
            /* [in] */ LONGLONG size);
        
        HRESULT ( STDMETHODCALLTYPE *BeginSession )( 
            IFsaResource * This,
            /* [string][in] */ OLECHAR *name,
            /* [in] */ ULONG logControl,
            /* [in] */ ULONG runId,
            /* [in] */ ULONG subRunId,
            /* [out] */ IHsmSession **ppSession);
        
        HRESULT ( STDMETHODCALLTYPE *BeginValidate )( 
            IFsaResource * This);
        
        HRESULT ( STDMETHODCALLTYPE *CheckForValidate )( 
            IFsaResource * This,
            /* [in] */ BOOL bForceValidate);
        
        HRESULT ( STDMETHODCALLTYPE *CompareBy )( 
            IFsaResource * This,
            /* [in] */ FSA_RESOURCE_COMPARE by);
        
        HRESULT ( STDMETHODCALLTYPE *CompareToAlternatePath )( 
            IFsaResource * This,
            /* [string][in] */ OLECHAR *path,
            /* [out] */ SHORT *pResult);
        
        HRESULT ( STDMETHODCALLTYPE *CompareToIdentifier )( 
            IFsaResource * This,
            /* [in] */ GUID id,
            /* [out] */ SHORT *pResult);
        
        HRESULT ( STDMETHODCALLTYPE *CompareToIResource )( 
            IFsaResource * This,
            /* [in] */ IFsaResource *pResource,
            /* [out] */ SHORT *pResult);
        
        HRESULT ( STDMETHODCALLTYPE *CompareToName )( 
            IFsaResource * This,
            /* [string][in] */ OLECHAR *name,
            /* [out] */ SHORT *pResult);
        
        HRESULT ( STDMETHODCALLTYPE *CompareToUserName )( 
            IFsaResource * This,
            /* [string][in] */ OLECHAR *userName,
            /* [out] */ SHORT *pResult);
        
        HRESULT ( STDMETHODCALLTYPE *CompareToPath )( 
            IFsaResource * This,
            /* [string][in] */ OLECHAR *path,
            /* [out] */ SHORT *pResult);
        
        HRESULT ( STDMETHODCALLTYPE *CompareToSerial )( 
            IFsaResource * This,
            /* [in] */ ULONG serial,
            /* [out] */ SHORT *pResult);
        
        HRESULT ( STDMETHODCALLTYPE *CompareToStickyName )( 
            IFsaResource * This,
            /* [string][in] */ OLECHAR *name,
            /* [out] */ SHORT *pResult);
        
        HRESULT ( STDMETHODCALLTYPE *CreateDefaultRules )( 
            IFsaResource * This);
        
        HRESULT ( STDMETHODCALLTYPE *EndSession )( 
            IFsaResource * This,
            /* [in] */ IHsmSession *pSession);
        
        HRESULT ( STDMETHODCALLTYPE *EndValidate )( 
            IFsaResource * This,
            /* [in] */ HSM_JOB_STATE state);
        
        HRESULT ( STDMETHODCALLTYPE *EnumDefaultRules )( 
            IFsaResource * This,
            /* [out] */ IWsbEnum **ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE *FindFirst )( 
            IFsaResource * This,
            /* [string][in] */ OLECHAR *path,
            /* [in] */ IHsmSession *pSession,
            /* [out] */ IFsaScanItem **ppScanItem);
        
        HRESULT ( STDMETHODCALLTYPE *FindFirstInRPIndex )( 
            IFsaResource * This,
            /* [in] */ IHsmSession *pSession,
            /* [out] */ IFsaScanItem **ppScanItem);
        
        HRESULT ( STDMETHODCALLTYPE *FindFirstInDbIndex )( 
            IFsaResource * This,
            /* [in] */ IHsmSession *pSession,
            /* [out] */ IFsaScanItem **ppScanItem);
        
        HRESULT ( STDMETHODCALLTYPE *FindNext )( 
            IFsaResource * This,
            /* [in] */ IFsaScanItem *pScanItem);
        
        HRESULT ( STDMETHODCALLTYPE *FindNextInRPIndex )( 
            IFsaResource * This,
            /* [in] */ IFsaScanItem *pScanItem);
        
        HRESULT ( STDMETHODCALLTYPE *FindNextInDbIndex )( 
            IFsaResource * This,
            /* [in] */ IFsaScanItem *pScanItem);
        
        HRESULT ( STDMETHODCALLTYPE *FindFileId )( 
            IFsaResource * This,
            /* [in] */ LONGLONG fileId,
            /* [in] */ IHsmSession *pSession,
            /* [out] */ IFsaScanItem **ppScanItem);
        
        HRESULT ( STDMETHODCALLTYPE *FindObjectId )( 
            IFsaResource * This,
            /* [in] */ LONGLONG objIdHi,
            /* [in] */ LONGLONG objIdLo,
            /* [in] */ IHsmSession *pSession,
            /* [out] */ IFsaScanItem **ppScanItem);
        
        HRESULT ( STDMETHODCALLTYPE *GetAlternatePath )( 
            IFsaResource * This,
            /* [string][out][in] */ OLECHAR **pPath,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetDefaultRules )( 
            IFsaResource * This,
            /* [out] */ IWsbCollection **ppCollection);
        
        HRESULT ( STDMETHODCALLTYPE *GetDbPath )( 
            IFsaResource * This,
            /* [string][out][in] */ OLECHAR **pPath,
            ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetUnmanageDbPath )( 
            IFsaResource * This,
            /* [string][out][in] */ OLECHAR **pPath,
            ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetFreeLevel )( 
            IFsaResource * This,
            /* [out] */ ULONG *pLevel);
        
        HRESULT ( STDMETHODCALLTYPE *GetFsName )( 
            IFsaResource * This,
            /* [string][out][in] */ OLECHAR **pName,
            ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetHsmEngine )( 
            IFsaResource * This,
            /* [out] */ IHsmFsaTskMgr **ppEngine);
        
        HRESULT ( STDMETHODCALLTYPE *GetHsmLevel )( 
            IFsaResource * This,
            /* [out] */ ULONG *pLevel);
        
        HRESULT ( STDMETHODCALLTYPE *GetIdentifier )( 
            IFsaResource * This,
            /* [out] */ GUID *pId);
        
        HRESULT ( STDMETHODCALLTYPE *GetLogicalName )( 
            IFsaResource * This,
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetManageableItemLogicalSize )( 
            IFsaResource * This,
            /* [out] */ LONGLONG *pSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetManageableItemAccessTime )( 
            IFsaResource * This,
            /* [out] */ BOOL *isRelative,
            /* [out] */ FILETIME *pTime);
        
        HRESULT ( STDMETHODCALLTYPE *GetManagingHsm )( 
            IFsaResource * This,
            /* [out] */ GUID *pId);
        
        HRESULT ( STDMETHODCALLTYPE *GetName )( 
            IFsaResource * This,
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetOldPath )( 
            IFsaResource * This,
            /* [string][out][in] */ OLECHAR **pPath,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetPath )( 
            IFsaResource * This,
            /* [string][out][in] */ OLECHAR **pPath,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetSerial )( 
            IFsaResource * This,
            /* [out] */ ULONG *serial);
        
        HRESULT ( STDMETHODCALLTYPE *GetSizes )( 
            IFsaResource * This,
            /* [out] */ LONGLONG *pTotal,
            /* [out] */ LONGLONG *pFree,
            /* [out] */ LONGLONG *pPremigrated,
            /* [out] */ LONGLONG *pTruncated);
        
        HRESULT ( STDMETHODCALLTYPE *GetTruncator )( 
            IFsaResource * This,
            /* [out] */ IFsaTruncator **ppTruncator);
        
        HRESULT ( STDMETHODCALLTYPE *GetUncPath )( 
            IFsaResource * This,
            /* [string][out][in] */ OLECHAR **pPath,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetUserFriendlyName )( 
            IFsaResource * This,
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetStickyName )( 
            IFsaResource * This,
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *IsActive )( 
            IFsaResource * This);
        
        HRESULT ( STDMETHODCALLTYPE *IsAvailable )( 
            IFsaResource * This);
        
        HRESULT ( STDMETHODCALLTYPE *IsDeletePending )( 
            IFsaResource * This);
        
        HRESULT ( STDMETHODCALLTYPE *IsManaged )( 
            IFsaResource * This);
        
        HRESULT ( STDMETHODCALLTYPE *Manage )( 
            IFsaResource * This,
            /* [in] */ IFsaScanItem *pScanItem,
            /* [in] */ LONGLONG offset,
            /* [in] */ LONGLONG size,
            /* [in] */ GUID storagePoolId,
            /* [in] */ BOOL truncate);
        
        HRESULT ( STDMETHODCALLTYPE *ManagedBy )( 
            IFsaResource * This,
            /* [in] */ GUID hsmId,
            /* [in] */ ULONG hsmLevel,
            /* [in] */ BOOL release);
        
        HRESULT ( STDMETHODCALLTYPE *NeedsRepair )( 
            IFsaResource * This);
        
        HRESULT ( STDMETHODCALLTYPE *ProcessResult )( 
            IFsaResource * This,
            /* [in] */ IFsaPostIt *pResult);
        
        HRESULT ( STDMETHODCALLTYPE *Recall )( 
            IFsaResource * This,
            /* [in] */ IFsaScanItem *pScanItem,
            /* [in] */ LONGLONG offset,
            /* [in] */ LONGLONG size,
            /* [in] */ BOOL deletePlaceholder);
        
        HRESULT ( STDMETHODCALLTYPE *RemovePremigrated )( 
            IFsaResource * This,
            /* [in] */ IFsaScanItem *pScanItem,
            /* [in] */ LONGLONG offset,
            /* [in] */ LONGLONG size);
        
        HRESULT ( STDMETHODCALLTYPE *RemoveTruncated )( 
            IFsaResource * This,
            /* [in] */ IFsaScanItem *pScanItem,
            /* [in] */ LONGLONG offset,
            /* [in] */ LONGLONG size);
        
        HRESULT ( STDMETHODCALLTYPE *SetHsmLevel )( 
            IFsaResource * This,
            /* [in] */ ULONG level);
        
        HRESULT ( STDMETHODCALLTYPE *SetIsActive )( 
            IFsaResource * This,
            /* [in] */ BOOL isActive);
        
        HRESULT ( STDMETHODCALLTYPE *SetIsAvailable )( 
            IFsaResource * This,
            /* [in] */ BOOL isActive);
        
        HRESULT ( STDMETHODCALLTYPE *SetIsDeletePending )( 
            IFsaResource * This,
            /* [in] */ BOOL isDeletePending);
        
        HRESULT ( STDMETHODCALLTYPE *SetManageableItemLogicalSize )( 
            IFsaResource * This,
            /* [in] */ LONGLONG pSize);
        
        HRESULT ( STDMETHODCALLTYPE *SetManageableItemAccessTime )( 
            IFsaResource * This,
            /* [in] */ BOOL isRelative,
            /* [in] */ FILETIME pTime);
        
        HRESULT ( STDMETHODCALLTYPE *SetSerial )( 
            IFsaResource * This,
            /* [in] */ ULONG serial);
        
        HRESULT ( STDMETHODCALLTYPE *StartJob )( 
            IFsaResource * This,
            /* [string][in] */ OLECHAR *startingPath,
            /* [in] */ IHsmSession *pSession);
        
        HRESULT ( STDMETHODCALLTYPE *StartJobSession )( 
            IFsaResource * This,
            /* [in] */ IHsmJob *pJob,
            /* [in] */ ULONG subRunId,
            /* [out] */ IHsmSession **ppSession);
        
        HRESULT ( STDMETHODCALLTYPE *Validate )( 
            IFsaResource * This,
            /* [in] */ IFsaScanItem *pScanItem,
            /* [in] */ LONGLONG offset,
            /* [in] */ LONGLONG size,
            /* [in] */ LONGLONG usn);
        
        HRESULT ( STDMETHODCALLTYPE *SetupValidateJob )( 
            IFsaResource * This,
            /* [in] */ SYSTEMTIME runtime);
        
        HRESULT ( STDMETHODCALLTYPE *GetUsnId )( 
            IFsaResource * This,
            /* [out] */ ULONGLONG *usnId);
        
        HRESULT ( STDMETHODCALLTYPE *ValidateForTruncate )( 
            IFsaResource * This,
            /* [in] */ IFsaScanItem *pScanItem,
            /* [in] */ LONGLONG offset,
            /* [in] */ LONGLONG size,
            /* [in] */ LONGLONG usn);
        
        END_INTERFACE
    } IFsaResourceVtbl;

    interface IFsaResource
    {
        CONST_VTBL struct IFsaResourceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFsaResource_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFsaResource_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFsaResource_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFsaResource_AddPremigrated(This,pScanItem,offset,size,isWaitingForClose,usn)	\
    (This)->lpVtbl -> AddPremigrated(This,pScanItem,offset,size,isWaitingForClose,usn)

#define IFsaResource_AddTruncated(This,pScanItem,offset,size)	\
    (This)->lpVtbl -> AddTruncated(This,pScanItem,offset,size)

#define IFsaResource_BeginSession(This,name,logControl,runId,subRunId,ppSession)	\
    (This)->lpVtbl -> BeginSession(This,name,logControl,runId,subRunId,ppSession)

#define IFsaResource_BeginValidate(This)	\
    (This)->lpVtbl -> BeginValidate(This)

#define IFsaResource_CheckForValidate(This,bForceValidate)	\
    (This)->lpVtbl -> CheckForValidate(This,bForceValidate)

#define IFsaResource_CompareBy(This,by)	\
    (This)->lpVtbl -> CompareBy(This,by)

#define IFsaResource_CompareToAlternatePath(This,path,pResult)	\
    (This)->lpVtbl -> CompareToAlternatePath(This,path,pResult)

#define IFsaResource_CompareToIdentifier(This,id,pResult)	\
    (This)->lpVtbl -> CompareToIdentifier(This,id,pResult)

#define IFsaResource_CompareToIResource(This,pResource,pResult)	\
    (This)->lpVtbl -> CompareToIResource(This,pResource,pResult)

#define IFsaResource_CompareToName(This,name,pResult)	\
    (This)->lpVtbl -> CompareToName(This,name,pResult)

#define IFsaResource_CompareToUserName(This,userName,pResult)	\
    (This)->lpVtbl -> CompareToUserName(This,userName,pResult)

#define IFsaResource_CompareToPath(This,path,pResult)	\
    (This)->lpVtbl -> CompareToPath(This,path,pResult)

#define IFsaResource_CompareToSerial(This,serial,pResult)	\
    (This)->lpVtbl -> CompareToSerial(This,serial,pResult)

#define IFsaResource_CompareToStickyName(This,name,pResult)	\
    (This)->lpVtbl -> CompareToStickyName(This,name,pResult)

#define IFsaResource_CreateDefaultRules(This)	\
    (This)->lpVtbl -> CreateDefaultRules(This)

#define IFsaResource_EndSession(This,pSession)	\
    (This)->lpVtbl -> EndSession(This,pSession)

#define IFsaResource_EndValidate(This,state)	\
    (This)->lpVtbl -> EndValidate(This,state)

#define IFsaResource_EnumDefaultRules(This,ppEnum)	\
    (This)->lpVtbl -> EnumDefaultRules(This,ppEnum)

#define IFsaResource_FindFirst(This,path,pSession,ppScanItem)	\
    (This)->lpVtbl -> FindFirst(This,path,pSession,ppScanItem)

#define IFsaResource_FindFirstInRPIndex(This,pSession,ppScanItem)	\
    (This)->lpVtbl -> FindFirstInRPIndex(This,pSession,ppScanItem)

#define IFsaResource_FindFirstInDbIndex(This,pSession,ppScanItem)	\
    (This)->lpVtbl -> FindFirstInDbIndex(This,pSession,ppScanItem)

#define IFsaResource_FindNext(This,pScanItem)	\
    (This)->lpVtbl -> FindNext(This,pScanItem)

#define IFsaResource_FindNextInRPIndex(This,pScanItem)	\
    (This)->lpVtbl -> FindNextInRPIndex(This,pScanItem)

#define IFsaResource_FindNextInDbIndex(This,pScanItem)	\
    (This)->lpVtbl -> FindNextInDbIndex(This,pScanItem)

#define IFsaResource_FindFileId(This,fileId,pSession,ppScanItem)	\
    (This)->lpVtbl -> FindFileId(This,fileId,pSession,ppScanItem)

#define IFsaResource_FindObjectId(This,objIdHi,objIdLo,pSession,ppScanItem)	\
    (This)->lpVtbl -> FindObjectId(This,objIdHi,objIdLo,pSession,ppScanItem)

#define IFsaResource_GetAlternatePath(This,pPath,bufferSize)	\
    (This)->lpVtbl -> GetAlternatePath(This,pPath,bufferSize)

#define IFsaResource_GetDefaultRules(This,ppCollection)	\
    (This)->lpVtbl -> GetDefaultRules(This,ppCollection)

#define IFsaResource_GetDbPath(This,pPath,bufferSize)	\
    (This)->lpVtbl -> GetDbPath(This,pPath,bufferSize)

#define IFsaResource_GetUnmanageDbPath(This,pPath,bufferSize)	\
    (This)->lpVtbl -> GetUnmanageDbPath(This,pPath,bufferSize)

#define IFsaResource_GetFreeLevel(This,pLevel)	\
    (This)->lpVtbl -> GetFreeLevel(This,pLevel)

#define IFsaResource_GetFsName(This,pName,bufferSize)	\
    (This)->lpVtbl -> GetFsName(This,pName,bufferSize)

#define IFsaResource_GetHsmEngine(This,ppEngine)	\
    (This)->lpVtbl -> GetHsmEngine(This,ppEngine)

#define IFsaResource_GetHsmLevel(This,pLevel)	\
    (This)->lpVtbl -> GetHsmLevel(This,pLevel)

#define IFsaResource_GetIdentifier(This,pId)	\
    (This)->lpVtbl -> GetIdentifier(This,pId)

#define IFsaResource_GetLogicalName(This,pName,bufferSize)	\
    (This)->lpVtbl -> GetLogicalName(This,pName,bufferSize)

#define IFsaResource_GetManageableItemLogicalSize(This,pSize)	\
    (This)->lpVtbl -> GetManageableItemLogicalSize(This,pSize)

#define IFsaResource_GetManageableItemAccessTime(This,isRelative,pTime)	\
    (This)->lpVtbl -> GetManageableItemAccessTime(This,isRelative,pTime)

#define IFsaResource_GetManagingHsm(This,pId)	\
    (This)->lpVtbl -> GetManagingHsm(This,pId)

#define IFsaResource_GetName(This,pName,bufferSize)	\
    (This)->lpVtbl -> GetName(This,pName,bufferSize)

#define IFsaResource_GetOldPath(This,pPath,bufferSize)	\
    (This)->lpVtbl -> GetOldPath(This,pPath,bufferSize)

#define IFsaResource_GetPath(This,pPath,bufferSize)	\
    (This)->lpVtbl -> GetPath(This,pPath,bufferSize)

#define IFsaResource_GetSerial(This,serial)	\
    (This)->lpVtbl -> GetSerial(This,serial)

#define IFsaResource_GetSizes(This,pTotal,pFree,pPremigrated,pTruncated)	\
    (This)->lpVtbl -> GetSizes(This,pTotal,pFree,pPremigrated,pTruncated)

#define IFsaResource_GetTruncator(This,ppTruncator)	\
    (This)->lpVtbl -> GetTruncator(This,ppTruncator)

#define IFsaResource_GetUncPath(This,pPath,bufferSize)	\
    (This)->lpVtbl -> GetUncPath(This,pPath,bufferSize)

#define IFsaResource_GetUserFriendlyName(This,pName,bufferSize)	\
    (This)->lpVtbl -> GetUserFriendlyName(This,pName,bufferSize)

#define IFsaResource_GetStickyName(This,pName,bufferSize)	\
    (This)->lpVtbl -> GetStickyName(This,pName,bufferSize)

#define IFsaResource_IsActive(This)	\
    (This)->lpVtbl -> IsActive(This)

#define IFsaResource_IsAvailable(This)	\
    (This)->lpVtbl -> IsAvailable(This)

#define IFsaResource_IsDeletePending(This)	\
    (This)->lpVtbl -> IsDeletePending(This)

#define IFsaResource_IsManaged(This)	\
    (This)->lpVtbl -> IsManaged(This)

#define IFsaResource_Manage(This,pScanItem,offset,size,storagePoolId,truncate)	\
    (This)->lpVtbl -> Manage(This,pScanItem,offset,size,storagePoolId,truncate)

#define IFsaResource_ManagedBy(This,hsmId,hsmLevel,release)	\
    (This)->lpVtbl -> ManagedBy(This,hsmId,hsmLevel,release)

#define IFsaResource_NeedsRepair(This)	\
    (This)->lpVtbl -> NeedsRepair(This)

#define IFsaResource_ProcessResult(This,pResult)	\
    (This)->lpVtbl -> ProcessResult(This,pResult)

#define IFsaResource_Recall(This,pScanItem,offset,size,deletePlaceholder)	\
    (This)->lpVtbl -> Recall(This,pScanItem,offset,size,deletePlaceholder)

#define IFsaResource_RemovePremigrated(This,pScanItem,offset,size)	\
    (This)->lpVtbl -> RemovePremigrated(This,pScanItem,offset,size)

#define IFsaResource_RemoveTruncated(This,pScanItem,offset,size)	\
    (This)->lpVtbl -> RemoveTruncated(This,pScanItem,offset,size)

#define IFsaResource_SetHsmLevel(This,level)	\
    (This)->lpVtbl -> SetHsmLevel(This,level)

#define IFsaResource_SetIsActive(This,isActive)	\
    (This)->lpVtbl -> SetIsActive(This,isActive)

#define IFsaResource_SetIsAvailable(This,isActive)	\
    (This)->lpVtbl -> SetIsAvailable(This,isActive)

#define IFsaResource_SetIsDeletePending(This,isDeletePending)	\
    (This)->lpVtbl -> SetIsDeletePending(This,isDeletePending)

#define IFsaResource_SetManageableItemLogicalSize(This,pSize)	\
    (This)->lpVtbl -> SetManageableItemLogicalSize(This,pSize)

#define IFsaResource_SetManageableItemAccessTime(This,isRelative,pTime)	\
    (This)->lpVtbl -> SetManageableItemAccessTime(This,isRelative,pTime)

#define IFsaResource_SetSerial(This,serial)	\
    (This)->lpVtbl -> SetSerial(This,serial)

#define IFsaResource_StartJob(This,startingPath,pSession)	\
    (This)->lpVtbl -> StartJob(This,startingPath,pSession)

#define IFsaResource_StartJobSession(This,pJob,subRunId,ppSession)	\
    (This)->lpVtbl -> StartJobSession(This,pJob,subRunId,ppSession)

#define IFsaResource_Validate(This,pScanItem,offset,size,usn)	\
    (This)->lpVtbl -> Validate(This,pScanItem,offset,size,usn)

#define IFsaResource_SetupValidateJob(This,runtime)	\
    (This)->lpVtbl -> SetupValidateJob(This,runtime)

#define IFsaResource_GetUsnId(This,usnId)	\
    (This)->lpVtbl -> GetUsnId(This,usnId)

#define IFsaResource_ValidateForTruncate(This,pScanItem,offset,size,usn)	\
    (This)->lpVtbl -> ValidateForTruncate(This,pScanItem,offset,size,usn)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IFsaResource_AddPremigrated_Proxy( 
    IFsaResource * This,
    /* [in] */ IFsaScanItem *pScanItem,
    /* [in] */ LONGLONG offset,
    /* [in] */ LONGLONG size,
    /* [in] */ BOOL isWaitingForClose,
    /* [in] */ LONGLONG usn);


void __RPC_STUB IFsaResource_AddPremigrated_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_AddTruncated_Proxy( 
    IFsaResource * This,
    /* [in] */ IFsaScanItem *pScanItem,
    /* [in] */ LONGLONG offset,
    /* [in] */ LONGLONG size);


void __RPC_STUB IFsaResource_AddTruncated_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_BeginSession_Proxy( 
    IFsaResource * This,
    /* [string][in] */ OLECHAR *name,
    /* [in] */ ULONG logControl,
    /* [in] */ ULONG runId,
    /* [in] */ ULONG subRunId,
    /* [out] */ IHsmSession **ppSession);


void __RPC_STUB IFsaResource_BeginSession_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_BeginValidate_Proxy( 
    IFsaResource * This);


void __RPC_STUB IFsaResource_BeginValidate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_CheckForValidate_Proxy( 
    IFsaResource * This,
    /* [in] */ BOOL bForceValidate);


void __RPC_STUB IFsaResource_CheckForValidate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_CompareBy_Proxy( 
    IFsaResource * This,
    /* [in] */ FSA_RESOURCE_COMPARE by);


void __RPC_STUB IFsaResource_CompareBy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_CompareToAlternatePath_Proxy( 
    IFsaResource * This,
    /* [string][in] */ OLECHAR *path,
    /* [out] */ SHORT *pResult);


void __RPC_STUB IFsaResource_CompareToAlternatePath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_CompareToIdentifier_Proxy( 
    IFsaResource * This,
    /* [in] */ GUID id,
    /* [out] */ SHORT *pResult);


void __RPC_STUB IFsaResource_CompareToIdentifier_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_CompareToIResource_Proxy( 
    IFsaResource * This,
    /* [in] */ IFsaResource *pResource,
    /* [out] */ SHORT *pResult);


void __RPC_STUB IFsaResource_CompareToIResource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_CompareToName_Proxy( 
    IFsaResource * This,
    /* [string][in] */ OLECHAR *name,
    /* [out] */ SHORT *pResult);


void __RPC_STUB IFsaResource_CompareToName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_CompareToUserName_Proxy( 
    IFsaResource * This,
    /* [string][in] */ OLECHAR *userName,
    /* [out] */ SHORT *pResult);


void __RPC_STUB IFsaResource_CompareToUserName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_CompareToPath_Proxy( 
    IFsaResource * This,
    /* [string][in] */ OLECHAR *path,
    /* [out] */ SHORT *pResult);


void __RPC_STUB IFsaResource_CompareToPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_CompareToSerial_Proxy( 
    IFsaResource * This,
    /* [in] */ ULONG serial,
    /* [out] */ SHORT *pResult);


void __RPC_STUB IFsaResource_CompareToSerial_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_CompareToStickyName_Proxy( 
    IFsaResource * This,
    /* [string][in] */ OLECHAR *name,
    /* [out] */ SHORT *pResult);


void __RPC_STUB IFsaResource_CompareToStickyName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_CreateDefaultRules_Proxy( 
    IFsaResource * This);


void __RPC_STUB IFsaResource_CreateDefaultRules_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_EndSession_Proxy( 
    IFsaResource * This,
    /* [in] */ IHsmSession *pSession);


void __RPC_STUB IFsaResource_EndSession_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_EndValidate_Proxy( 
    IFsaResource * This,
    /* [in] */ HSM_JOB_STATE state);


void __RPC_STUB IFsaResource_EndValidate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_EnumDefaultRules_Proxy( 
    IFsaResource * This,
    /* [out] */ IWsbEnum **ppEnum);


void __RPC_STUB IFsaResource_EnumDefaultRules_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_FindFirst_Proxy( 
    IFsaResource * This,
    /* [string][in] */ OLECHAR *path,
    /* [in] */ IHsmSession *pSession,
    /* [out] */ IFsaScanItem **ppScanItem);


void __RPC_STUB IFsaResource_FindFirst_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_FindFirstInRPIndex_Proxy( 
    IFsaResource * This,
    /* [in] */ IHsmSession *pSession,
    /* [out] */ IFsaScanItem **ppScanItem);


void __RPC_STUB IFsaResource_FindFirstInRPIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_FindFirstInDbIndex_Proxy( 
    IFsaResource * This,
    /* [in] */ IHsmSession *pSession,
    /* [out] */ IFsaScanItem **ppScanItem);


void __RPC_STUB IFsaResource_FindFirstInDbIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_FindNext_Proxy( 
    IFsaResource * This,
    /* [in] */ IFsaScanItem *pScanItem);


void __RPC_STUB IFsaResource_FindNext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_FindNextInRPIndex_Proxy( 
    IFsaResource * This,
    /* [in] */ IFsaScanItem *pScanItem);


void __RPC_STUB IFsaResource_FindNextInRPIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_FindNextInDbIndex_Proxy( 
    IFsaResource * This,
    /* [in] */ IFsaScanItem *pScanItem);


void __RPC_STUB IFsaResource_FindNextInDbIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_FindFileId_Proxy( 
    IFsaResource * This,
    /* [in] */ LONGLONG fileId,
    /* [in] */ IHsmSession *pSession,
    /* [out] */ IFsaScanItem **ppScanItem);


void __RPC_STUB IFsaResource_FindFileId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_FindObjectId_Proxy( 
    IFsaResource * This,
    /* [in] */ LONGLONG objIdHi,
    /* [in] */ LONGLONG objIdLo,
    /* [in] */ IHsmSession *pSession,
    /* [out] */ IFsaScanItem **ppScanItem);


void __RPC_STUB IFsaResource_FindObjectId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_GetAlternatePath_Proxy( 
    IFsaResource * This,
    /* [string][out][in] */ OLECHAR **pPath,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IFsaResource_GetAlternatePath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_GetDefaultRules_Proxy( 
    IFsaResource * This,
    /* [out] */ IWsbCollection **ppCollection);


void __RPC_STUB IFsaResource_GetDefaultRules_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_GetDbPath_Proxy( 
    IFsaResource * This,
    /* [string][out][in] */ OLECHAR **pPath,
    ULONG bufferSize);


void __RPC_STUB IFsaResource_GetDbPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_GetUnmanageDbPath_Proxy( 
    IFsaResource * This,
    /* [string][out][in] */ OLECHAR **pPath,
    ULONG bufferSize);


void __RPC_STUB IFsaResource_GetUnmanageDbPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_GetFreeLevel_Proxy( 
    IFsaResource * This,
    /* [out] */ ULONG *pLevel);


void __RPC_STUB IFsaResource_GetFreeLevel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_GetFsName_Proxy( 
    IFsaResource * This,
    /* [string][out][in] */ OLECHAR **pName,
    ULONG bufferSize);


void __RPC_STUB IFsaResource_GetFsName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_GetHsmEngine_Proxy( 
    IFsaResource * This,
    /* [out] */ IHsmFsaTskMgr **ppEngine);


void __RPC_STUB IFsaResource_GetHsmEngine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_GetHsmLevel_Proxy( 
    IFsaResource * This,
    /* [out] */ ULONG *pLevel);


void __RPC_STUB IFsaResource_GetHsmLevel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_GetIdentifier_Proxy( 
    IFsaResource * This,
    /* [out] */ GUID *pId);


void __RPC_STUB IFsaResource_GetIdentifier_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_GetLogicalName_Proxy( 
    IFsaResource * This,
    /* [string][out][in] */ OLECHAR **pName,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IFsaResource_GetLogicalName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_GetManageableItemLogicalSize_Proxy( 
    IFsaResource * This,
    /* [out] */ LONGLONG *pSize);


void __RPC_STUB IFsaResource_GetManageableItemLogicalSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_GetManageableItemAccessTime_Proxy( 
    IFsaResource * This,
    /* [out] */ BOOL *isRelative,
    /* [out] */ FILETIME *pTime);


void __RPC_STUB IFsaResource_GetManageableItemAccessTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_GetManagingHsm_Proxy( 
    IFsaResource * This,
    /* [out] */ GUID *pId);


void __RPC_STUB IFsaResource_GetManagingHsm_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_GetName_Proxy( 
    IFsaResource * This,
    /* [string][out][in] */ OLECHAR **pName,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IFsaResource_GetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_GetOldPath_Proxy( 
    IFsaResource * This,
    /* [string][out][in] */ OLECHAR **pPath,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IFsaResource_GetOldPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_GetPath_Proxy( 
    IFsaResource * This,
    /* [string][out][in] */ OLECHAR **pPath,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IFsaResource_GetPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_GetSerial_Proxy( 
    IFsaResource * This,
    /* [out] */ ULONG *serial);


void __RPC_STUB IFsaResource_GetSerial_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_GetSizes_Proxy( 
    IFsaResource * This,
    /* [out] */ LONGLONG *pTotal,
    /* [out] */ LONGLONG *pFree,
    /* [out] */ LONGLONG *pPremigrated,
    /* [out] */ LONGLONG *pTruncated);


void __RPC_STUB IFsaResource_GetSizes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_GetTruncator_Proxy( 
    IFsaResource * This,
    /* [out] */ IFsaTruncator **ppTruncator);


void __RPC_STUB IFsaResource_GetTruncator_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_GetUncPath_Proxy( 
    IFsaResource * This,
    /* [string][out][in] */ OLECHAR **pPath,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IFsaResource_GetUncPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_GetUserFriendlyName_Proxy( 
    IFsaResource * This,
    /* [string][out][in] */ OLECHAR **pName,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IFsaResource_GetUserFriendlyName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_GetStickyName_Proxy( 
    IFsaResource * This,
    /* [string][out][in] */ OLECHAR **pName,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IFsaResource_GetStickyName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_IsActive_Proxy( 
    IFsaResource * This);


void __RPC_STUB IFsaResource_IsActive_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_IsAvailable_Proxy( 
    IFsaResource * This);


void __RPC_STUB IFsaResource_IsAvailable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_IsDeletePending_Proxy( 
    IFsaResource * This);


void __RPC_STUB IFsaResource_IsDeletePending_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_IsManaged_Proxy( 
    IFsaResource * This);


void __RPC_STUB IFsaResource_IsManaged_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_Manage_Proxy( 
    IFsaResource * This,
    /* [in] */ IFsaScanItem *pScanItem,
    /* [in] */ LONGLONG offset,
    /* [in] */ LONGLONG size,
    /* [in] */ GUID storagePoolId,
    /* [in] */ BOOL truncate);


void __RPC_STUB IFsaResource_Manage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_ManagedBy_Proxy( 
    IFsaResource * This,
    /* [in] */ GUID hsmId,
    /* [in] */ ULONG hsmLevel,
    /* [in] */ BOOL release);


void __RPC_STUB IFsaResource_ManagedBy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_NeedsRepair_Proxy( 
    IFsaResource * This);


void __RPC_STUB IFsaResource_NeedsRepair_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_ProcessResult_Proxy( 
    IFsaResource * This,
    /* [in] */ IFsaPostIt *pResult);


void __RPC_STUB IFsaResource_ProcessResult_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_Recall_Proxy( 
    IFsaResource * This,
    /* [in] */ IFsaScanItem *pScanItem,
    /* [in] */ LONGLONG offset,
    /* [in] */ LONGLONG size,
    /* [in] */ BOOL deletePlaceholder);


void __RPC_STUB IFsaResource_Recall_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_RemovePremigrated_Proxy( 
    IFsaResource * This,
    /* [in] */ IFsaScanItem *pScanItem,
    /* [in] */ LONGLONG offset,
    /* [in] */ LONGLONG size);


void __RPC_STUB IFsaResource_RemovePremigrated_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_RemoveTruncated_Proxy( 
    IFsaResource * This,
    /* [in] */ IFsaScanItem *pScanItem,
    /* [in] */ LONGLONG offset,
    /* [in] */ LONGLONG size);


void __RPC_STUB IFsaResource_RemoveTruncated_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_SetHsmLevel_Proxy( 
    IFsaResource * This,
    /* [in] */ ULONG level);


void __RPC_STUB IFsaResource_SetHsmLevel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_SetIsActive_Proxy( 
    IFsaResource * This,
    /* [in] */ BOOL isActive);


void __RPC_STUB IFsaResource_SetIsActive_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_SetIsAvailable_Proxy( 
    IFsaResource * This,
    /* [in] */ BOOL isActive);


void __RPC_STUB IFsaResource_SetIsAvailable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_SetIsDeletePending_Proxy( 
    IFsaResource * This,
    /* [in] */ BOOL isDeletePending);


void __RPC_STUB IFsaResource_SetIsDeletePending_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_SetManageableItemLogicalSize_Proxy( 
    IFsaResource * This,
    /* [in] */ LONGLONG pSize);


void __RPC_STUB IFsaResource_SetManageableItemLogicalSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_SetManageableItemAccessTime_Proxy( 
    IFsaResource * This,
    /* [in] */ BOOL isRelative,
    /* [in] */ FILETIME pTime);


void __RPC_STUB IFsaResource_SetManageableItemAccessTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_SetSerial_Proxy( 
    IFsaResource * This,
    /* [in] */ ULONG serial);


void __RPC_STUB IFsaResource_SetSerial_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_StartJob_Proxy( 
    IFsaResource * This,
    /* [string][in] */ OLECHAR *startingPath,
    /* [in] */ IHsmSession *pSession);


void __RPC_STUB IFsaResource_StartJob_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_StartJobSession_Proxy( 
    IFsaResource * This,
    /* [in] */ IHsmJob *pJob,
    /* [in] */ ULONG subRunId,
    /* [out] */ IHsmSession **ppSession);


void __RPC_STUB IFsaResource_StartJobSession_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_Validate_Proxy( 
    IFsaResource * This,
    /* [in] */ IFsaScanItem *pScanItem,
    /* [in] */ LONGLONG offset,
    /* [in] */ LONGLONG size,
    /* [in] */ LONGLONG usn);


void __RPC_STUB IFsaResource_Validate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_SetupValidateJob_Proxy( 
    IFsaResource * This,
    /* [in] */ SYSTEMTIME runtime);


void __RPC_STUB IFsaResource_SetupValidateJob_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_GetUsnId_Proxy( 
    IFsaResource * This,
    /* [out] */ ULONGLONG *usnId);


void __RPC_STUB IFsaResource_GetUsnId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResource_ValidateForTruncate_Proxy( 
    IFsaResource * This,
    /* [in] */ IFsaScanItem *pScanItem,
    /* [in] */ LONGLONG offset,
    /* [in] */ LONGLONG size,
    /* [in] */ LONGLONG usn);


void __RPC_STUB IFsaResource_ValidateForTruncate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IFsaResource_INTERFACE_DEFINED__ */


#ifndef __IFsaScanItem_INTERFACE_DEFINED__
#define __IFsaScanItem_INTERFACE_DEFINED__

/* interface IFsaScanItem */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IFsaScanItem;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("087e7ed0-727a-11d2-9cd3-00a0c9118102")
    IFsaScanItem : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CheckIfSparse( 
            /* [in] */ LONGLONG offset,
            /* [in] */ LONGLONG size) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CompareToIScanItem( 
            /* [in] */ IFsaScanItem *pScanItem,
            /* [out] */ SHORT *pResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CompareToPathAndName( 
            /* [string][in] */ OLECHAR *path,
            /* [string][in] */ OLECHAR *name,
            /* [out] */ SHORT *pResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Copy( 
            /* [string][in] */ OLECHAR *dest,
            /* [in] */ BOOL retainHierarcy,
            /* [in] */ BOOL expandPlaceholders,
            /* [in] */ BOOL overwriteExisting) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateLocalStream( 
            /* [out] */ IStream **ppStream) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreatePlaceholder( 
            /* [in] */ LONGLONG offset,
            /* [in] */ LONGLONG size,
            /* [in] */ FSA_PLACEHOLDER pPlaceholder,
            /* [in] */ BOOL checkUsn,
            /* [in] */ LONGLONG usn,
            /* [out] */ LONGLONG *pUsn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeletePlaceholder( 
            /* [in] */ LONGLONG offset,
            /* [in] */ LONGLONG size) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FindFirstPlaceholder( 
            /* [out] */ LONGLONG *pOffset,
            /* [out] */ LONGLONG *pSize,
            /* [out] */ FSA_PLACEHOLDER *pPlaceholder) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FindNextPlaceholder( 
            /* [out][in] */ LONGLONG *pOffset,
            /* [out][in] */ LONGLONG *pSize,
            /* [out][in] */ FSA_PLACEHOLDER *pPlaceholder) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAccessTime( 
            /* [out] */ FILETIME *pTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFileId( 
            /* [out] */ LONGLONG *pFileId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFileUsn( 
            /* [out] */ LONGLONG *pFileUsn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFullPathAndName( 
            /* [string][in] */ OLECHAR *prependix,
            /* [string][in] */ OLECHAR *appendix,
            /* [string][out][in] */ OLECHAR **pPath,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetGroup( 
            /* [string][out][in] */ OLECHAR **pOwner,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLogicalSize( 
            /* [out] */ LONGLONG *pSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetModifyTime( 
            /* [out] */ FILETIME *pTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetName( 
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOwner( 
            /* [string][out][in] */ OLECHAR **pOwner,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPathForFind( 
            /* [string][in] */ OLECHAR *searchName,
            /* [string][out][in] */ OLECHAR **pPath,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPath( 
            /* [string][out][in] */ OLECHAR **pPath,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPathAndName( 
            /* [string][in] */ OLECHAR *appendix,
            /* [string][out][in] */ OLECHAR **pPath,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPhysicalSize( 
            /* [out] */ LONGLONG *pSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPlaceholder( 
            /* [in] */ LONGLONG offset,
            /* [in] */ LONGLONG size,
            /* [out] */ FSA_PLACEHOLDER *pPlaceholder) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSession( 
            /* [out] */ IHsmSession **ppSession) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUncPathAndName( 
            /* [string][in] */ OLECHAR *prependix,
            /* [string][in] */ OLECHAR *appendix,
            /* [string][out][in] */ OLECHAR **pPath,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVersionId( 
            /* [out] */ LONGLONG *pId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE HasExtendedAttributes( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsALink( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsAParent( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsARelativeParent( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsCompressed( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsDeleteOK( 
            /* [in] */ IFsaPostIt *pPostIt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsEncrypted( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsGroupMemberOf( 
            /* [string][in] */ OLECHAR *group) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsHidden( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsManageable( 
            /* [in] */ LONGLONG offset,
            /* [in] */ LONGLONG size) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsManaged( 
            /* [in] */ LONGLONG offset,
            /* [in] */ LONGLONG size) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsMbit( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsMigrateOK( 
            /* [in] */ IFsaPostIt *pPostIt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsOffline( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsOwnerMemberOf( 
            /* [string][in] */ OLECHAR *group) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsPremigrated( 
            /* [in] */ LONGLONG offset,
            /* [in] */ LONGLONG size) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsReadOnly( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsRecallOK( 
            /* [in] */ IFsaPostIt *pPostIt) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsSparse( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsSystem( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsTotallySparse( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsTruncated( 
            /* [in] */ LONGLONG offset,
            /* [in] */ LONGLONG size) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Manage( 
            /* [in] */ LONGLONG offset,
            /* [in] */ LONGLONG size,
            /* [in] */ GUID storagePoolId,
            /* [in] */ BOOL truncate) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Move( 
            /* [string][in] */ OLECHAR *dest,
            /* [in] */ BOOL retainHierarcy,
            /* [in] */ BOOL expandPlaceholders,
            /* [in] */ BOOL overwriteExisting) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Recall( 
            /* [in] */ LONGLONG offset,
            /* [in] */ LONGLONG size,
            /* [in] */ BOOL deletePlaceholder) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Recycle( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Truncate( 
            /* [in] */ LONGLONG offset,
            /* [in] */ LONGLONG size) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Unmanage( 
            /* [in] */ LONGLONG offset,
            /* [in] */ LONGLONG size) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Validate( 
            /* [in] */ LONGLONG offset,
            /* [in] */ LONGLONG size) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PrepareForManage( 
            /* [in] */ LONGLONG offset,
            /* [in] */ LONGLONG size) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Verify( 
            /* [in] */ LONGLONG offset,
            /* [in] */ LONGLONG size) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE TruncateValidated( 
            /* [in] */ LONGLONG offset,
            /* [in] */ LONGLONG size) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFsaScanItemVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFsaScanItem * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFsaScanItem * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFsaScanItem * This);
        
        HRESULT ( STDMETHODCALLTYPE *CheckIfSparse )( 
            IFsaScanItem * This,
            /* [in] */ LONGLONG offset,
            /* [in] */ LONGLONG size);
        
        HRESULT ( STDMETHODCALLTYPE *CompareToIScanItem )( 
            IFsaScanItem * This,
            /* [in] */ IFsaScanItem *pScanItem,
            /* [out] */ SHORT *pResult);
        
        HRESULT ( STDMETHODCALLTYPE *CompareToPathAndName )( 
            IFsaScanItem * This,
            /* [string][in] */ OLECHAR *path,
            /* [string][in] */ OLECHAR *name,
            /* [out] */ SHORT *pResult);
        
        HRESULT ( STDMETHODCALLTYPE *Copy )( 
            IFsaScanItem * This,
            /* [string][in] */ OLECHAR *dest,
            /* [in] */ BOOL retainHierarcy,
            /* [in] */ BOOL expandPlaceholders,
            /* [in] */ BOOL overwriteExisting);
        
        HRESULT ( STDMETHODCALLTYPE *CreateLocalStream )( 
            IFsaScanItem * This,
            /* [out] */ IStream **ppStream);
        
        HRESULT ( STDMETHODCALLTYPE *CreatePlaceholder )( 
            IFsaScanItem * This,
            /* [in] */ LONGLONG offset,
            /* [in] */ LONGLONG size,
            /* [in] */ FSA_PLACEHOLDER pPlaceholder,
            /* [in] */ BOOL checkUsn,
            /* [in] */ LONGLONG usn,
            /* [out] */ LONGLONG *pUsn);
        
        HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IFsaScanItem * This);
        
        HRESULT ( STDMETHODCALLTYPE *DeletePlaceholder )( 
            IFsaScanItem * This,
            /* [in] */ LONGLONG offset,
            /* [in] */ LONGLONG size);
        
        HRESULT ( STDMETHODCALLTYPE *FindFirstPlaceholder )( 
            IFsaScanItem * This,
            /* [out] */ LONGLONG *pOffset,
            /* [out] */ LONGLONG *pSize,
            /* [out] */ FSA_PLACEHOLDER *pPlaceholder);
        
        HRESULT ( STDMETHODCALLTYPE *FindNextPlaceholder )( 
            IFsaScanItem * This,
            /* [out][in] */ LONGLONG *pOffset,
            /* [out][in] */ LONGLONG *pSize,
            /* [out][in] */ FSA_PLACEHOLDER *pPlaceholder);
        
        HRESULT ( STDMETHODCALLTYPE *GetAccessTime )( 
            IFsaScanItem * This,
            /* [out] */ FILETIME *pTime);
        
        HRESULT ( STDMETHODCALLTYPE *GetFileId )( 
            IFsaScanItem * This,
            /* [out] */ LONGLONG *pFileId);
        
        HRESULT ( STDMETHODCALLTYPE *GetFileUsn )( 
            IFsaScanItem * This,
            /* [out] */ LONGLONG *pFileUsn);
        
        HRESULT ( STDMETHODCALLTYPE *GetFullPathAndName )( 
            IFsaScanItem * This,
            /* [string][in] */ OLECHAR *prependix,
            /* [string][in] */ OLECHAR *appendix,
            /* [string][out][in] */ OLECHAR **pPath,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetGroup )( 
            IFsaScanItem * This,
            /* [string][out][in] */ OLECHAR **pOwner,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetLogicalSize )( 
            IFsaScanItem * This,
            /* [out] */ LONGLONG *pSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetModifyTime )( 
            IFsaScanItem * This,
            /* [out] */ FILETIME *pTime);
        
        HRESULT ( STDMETHODCALLTYPE *GetName )( 
            IFsaScanItem * This,
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetOwner )( 
            IFsaScanItem * This,
            /* [string][out][in] */ OLECHAR **pOwner,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetPathForFind )( 
            IFsaScanItem * This,
            /* [string][in] */ OLECHAR *searchName,
            /* [string][out][in] */ OLECHAR **pPath,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetPath )( 
            IFsaScanItem * This,
            /* [string][out][in] */ OLECHAR **pPath,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetPathAndName )( 
            IFsaScanItem * This,
            /* [string][in] */ OLECHAR *appendix,
            /* [string][out][in] */ OLECHAR **pPath,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetPhysicalSize )( 
            IFsaScanItem * This,
            /* [out] */ LONGLONG *pSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetPlaceholder )( 
            IFsaScanItem * This,
            /* [in] */ LONGLONG offset,
            /* [in] */ LONGLONG size,
            /* [out] */ FSA_PLACEHOLDER *pPlaceholder);
        
        HRESULT ( STDMETHODCALLTYPE *GetSession )( 
            IFsaScanItem * This,
            /* [out] */ IHsmSession **ppSession);
        
        HRESULT ( STDMETHODCALLTYPE *GetUncPathAndName )( 
            IFsaScanItem * This,
            /* [string][in] */ OLECHAR *prependix,
            /* [string][in] */ OLECHAR *appendix,
            /* [string][out][in] */ OLECHAR **pPath,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetVersionId )( 
            IFsaScanItem * This,
            /* [out] */ LONGLONG *pId);
        
        HRESULT ( STDMETHODCALLTYPE *HasExtendedAttributes )( 
            IFsaScanItem * This);
        
        HRESULT ( STDMETHODCALLTYPE *IsALink )( 
            IFsaScanItem * This);
        
        HRESULT ( STDMETHODCALLTYPE *IsAParent )( 
            IFsaScanItem * This);
        
        HRESULT ( STDMETHODCALLTYPE *IsARelativeParent )( 
            IFsaScanItem * This);
        
        HRESULT ( STDMETHODCALLTYPE *IsCompressed )( 
            IFsaScanItem * This);
        
        HRESULT ( STDMETHODCALLTYPE *IsDeleteOK )( 
            IFsaScanItem * This,
            /* [in] */ IFsaPostIt *pPostIt);
        
        HRESULT ( STDMETHODCALLTYPE *IsEncrypted )( 
            IFsaScanItem * This);
        
        HRESULT ( STDMETHODCALLTYPE *IsGroupMemberOf )( 
            IFsaScanItem * This,
            /* [string][in] */ OLECHAR *group);
        
        HRESULT ( STDMETHODCALLTYPE *IsHidden )( 
            IFsaScanItem * This);
        
        HRESULT ( STDMETHODCALLTYPE *IsManageable )( 
            IFsaScanItem * This,
            /* [in] */ LONGLONG offset,
            /* [in] */ LONGLONG size);
        
        HRESULT ( STDMETHODCALLTYPE *IsManaged )( 
            IFsaScanItem * This,
            /* [in] */ LONGLONG offset,
            /* [in] */ LONGLONG size);
        
        HRESULT ( STDMETHODCALLTYPE *IsMbit )( 
            IFsaScanItem * This);
        
        HRESULT ( STDMETHODCALLTYPE *IsMigrateOK )( 
            IFsaScanItem * This,
            /* [in] */ IFsaPostIt *pPostIt);
        
        HRESULT ( STDMETHODCALLTYPE *IsOffline )( 
            IFsaScanItem * This);
        
        HRESULT ( STDMETHODCALLTYPE *IsOwnerMemberOf )( 
            IFsaScanItem * This,
            /* [string][in] */ OLECHAR *group);
        
        HRESULT ( STDMETHODCALLTYPE *IsPremigrated )( 
            IFsaScanItem * This,
            /* [in] */ LONGLONG offset,
            /* [in] */ LONGLONG size);
        
        HRESULT ( STDMETHODCALLTYPE *IsReadOnly )( 
            IFsaScanItem * This);
        
        HRESULT ( STDMETHODCALLTYPE *IsRecallOK )( 
            IFsaScanItem * This,
            /* [in] */ IFsaPostIt *pPostIt);
        
        HRESULT ( STDMETHODCALLTYPE *IsSparse )( 
            IFsaScanItem * This);
        
        HRESULT ( STDMETHODCALLTYPE *IsSystem )( 
            IFsaScanItem * This);
        
        HRESULT ( STDMETHODCALLTYPE *IsTotallySparse )( 
            IFsaScanItem * This);
        
        HRESULT ( STDMETHODCALLTYPE *IsTruncated )( 
            IFsaScanItem * This,
            /* [in] */ LONGLONG offset,
            /* [in] */ LONGLONG size);
        
        HRESULT ( STDMETHODCALLTYPE *Manage )( 
            IFsaScanItem * This,
            /* [in] */ LONGLONG offset,
            /* [in] */ LONGLONG size,
            /* [in] */ GUID storagePoolId,
            /* [in] */ BOOL truncate);
        
        HRESULT ( STDMETHODCALLTYPE *Move )( 
            IFsaScanItem * This,
            /* [string][in] */ OLECHAR *dest,
            /* [in] */ BOOL retainHierarcy,
            /* [in] */ BOOL expandPlaceholders,
            /* [in] */ BOOL overwriteExisting);
        
        HRESULT ( STDMETHODCALLTYPE *Recall )( 
            IFsaScanItem * This,
            /* [in] */ LONGLONG offset,
            /* [in] */ LONGLONG size,
            /* [in] */ BOOL deletePlaceholder);
        
        HRESULT ( STDMETHODCALLTYPE *Recycle )( 
            IFsaScanItem * This);
        
        HRESULT ( STDMETHODCALLTYPE *Truncate )( 
            IFsaScanItem * This,
            /* [in] */ LONGLONG offset,
            /* [in] */ LONGLONG size);
        
        HRESULT ( STDMETHODCALLTYPE *Unmanage )( 
            IFsaScanItem * This,
            /* [in] */ LONGLONG offset,
            /* [in] */ LONGLONG size);
        
        HRESULT ( STDMETHODCALLTYPE *Validate )( 
            IFsaScanItem * This,
            /* [in] */ LONGLONG offset,
            /* [in] */ LONGLONG size);
        
        HRESULT ( STDMETHODCALLTYPE *PrepareForManage )( 
            IFsaScanItem * This,
            /* [in] */ LONGLONG offset,
            /* [in] */ LONGLONG size);
        
        HRESULT ( STDMETHODCALLTYPE *Verify )( 
            IFsaScanItem * This,
            /* [in] */ LONGLONG offset,
            /* [in] */ LONGLONG size);
        
        HRESULT ( STDMETHODCALLTYPE *TruncateValidated )( 
            IFsaScanItem * This,
            /* [in] */ LONGLONG offset,
            /* [in] */ LONGLONG size);
        
        END_INTERFACE
    } IFsaScanItemVtbl;

    interface IFsaScanItem
    {
        CONST_VTBL struct IFsaScanItemVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFsaScanItem_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFsaScanItem_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFsaScanItem_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFsaScanItem_CheckIfSparse(This,offset,size)	\
    (This)->lpVtbl -> CheckIfSparse(This,offset,size)

#define IFsaScanItem_CompareToIScanItem(This,pScanItem,pResult)	\
    (This)->lpVtbl -> CompareToIScanItem(This,pScanItem,pResult)

#define IFsaScanItem_CompareToPathAndName(This,path,name,pResult)	\
    (This)->lpVtbl -> CompareToPathAndName(This,path,name,pResult)

#define IFsaScanItem_Copy(This,dest,retainHierarcy,expandPlaceholders,overwriteExisting)	\
    (This)->lpVtbl -> Copy(This,dest,retainHierarcy,expandPlaceholders,overwriteExisting)

#define IFsaScanItem_CreateLocalStream(This,ppStream)	\
    (This)->lpVtbl -> CreateLocalStream(This,ppStream)

#define IFsaScanItem_CreatePlaceholder(This,offset,size,pPlaceholder,checkUsn,usn,pUsn)	\
    (This)->lpVtbl -> CreatePlaceholder(This,offset,size,pPlaceholder,checkUsn,usn,pUsn)

#define IFsaScanItem_Delete(This)	\
    (This)->lpVtbl -> Delete(This)

#define IFsaScanItem_DeletePlaceholder(This,offset,size)	\
    (This)->lpVtbl -> DeletePlaceholder(This,offset,size)

#define IFsaScanItem_FindFirstPlaceholder(This,pOffset,pSize,pPlaceholder)	\
    (This)->lpVtbl -> FindFirstPlaceholder(This,pOffset,pSize,pPlaceholder)

#define IFsaScanItem_FindNextPlaceholder(This,pOffset,pSize,pPlaceholder)	\
    (This)->lpVtbl -> FindNextPlaceholder(This,pOffset,pSize,pPlaceholder)

#define IFsaScanItem_GetAccessTime(This,pTime)	\
    (This)->lpVtbl -> GetAccessTime(This,pTime)

#define IFsaScanItem_GetFileId(This,pFileId)	\
    (This)->lpVtbl -> GetFileId(This,pFileId)

#define IFsaScanItem_GetFileUsn(This,pFileUsn)	\
    (This)->lpVtbl -> GetFileUsn(This,pFileUsn)

#define IFsaScanItem_GetFullPathAndName(This,prependix,appendix,pPath,bufferSize)	\
    (This)->lpVtbl -> GetFullPathAndName(This,prependix,appendix,pPath,bufferSize)

#define IFsaScanItem_GetGroup(This,pOwner,bufferSize)	\
    (This)->lpVtbl -> GetGroup(This,pOwner,bufferSize)

#define IFsaScanItem_GetLogicalSize(This,pSize)	\
    (This)->lpVtbl -> GetLogicalSize(This,pSize)

#define IFsaScanItem_GetModifyTime(This,pTime)	\
    (This)->lpVtbl -> GetModifyTime(This,pTime)

#define IFsaScanItem_GetName(This,pName,bufferSize)	\
    (This)->lpVtbl -> GetName(This,pName,bufferSize)

#define IFsaScanItem_GetOwner(This,pOwner,bufferSize)	\
    (This)->lpVtbl -> GetOwner(This,pOwner,bufferSize)

#define IFsaScanItem_GetPathForFind(This,searchName,pPath,bufferSize)	\
    (This)->lpVtbl -> GetPathForFind(This,searchName,pPath,bufferSize)

#define IFsaScanItem_GetPath(This,pPath,bufferSize)	\
    (This)->lpVtbl -> GetPath(This,pPath,bufferSize)

#define IFsaScanItem_GetPathAndName(This,appendix,pPath,bufferSize)	\
    (This)->lpVtbl -> GetPathAndName(This,appendix,pPath,bufferSize)

#define IFsaScanItem_GetPhysicalSize(This,pSize)	\
    (This)->lpVtbl -> GetPhysicalSize(This,pSize)

#define IFsaScanItem_GetPlaceholder(This,offset,size,pPlaceholder)	\
    (This)->lpVtbl -> GetPlaceholder(This,offset,size,pPlaceholder)

#define IFsaScanItem_GetSession(This,ppSession)	\
    (This)->lpVtbl -> GetSession(This,ppSession)

#define IFsaScanItem_GetUncPathAndName(This,prependix,appendix,pPath,bufferSize)	\
    (This)->lpVtbl -> GetUncPathAndName(This,prependix,appendix,pPath,bufferSize)

#define IFsaScanItem_GetVersionId(This,pId)	\
    (This)->lpVtbl -> GetVersionId(This,pId)

#define IFsaScanItem_HasExtendedAttributes(This)	\
    (This)->lpVtbl -> HasExtendedAttributes(This)

#define IFsaScanItem_IsALink(This)	\
    (This)->lpVtbl -> IsALink(This)

#define IFsaScanItem_IsAParent(This)	\
    (This)->lpVtbl -> IsAParent(This)

#define IFsaScanItem_IsARelativeParent(This)	\
    (This)->lpVtbl -> IsARelativeParent(This)

#define IFsaScanItem_IsCompressed(This)	\
    (This)->lpVtbl -> IsCompressed(This)

#define IFsaScanItem_IsDeleteOK(This,pPostIt)	\
    (This)->lpVtbl -> IsDeleteOK(This,pPostIt)

#define IFsaScanItem_IsEncrypted(This)	\
    (This)->lpVtbl -> IsEncrypted(This)

#define IFsaScanItem_IsGroupMemberOf(This,group)	\
    (This)->lpVtbl -> IsGroupMemberOf(This,group)

#define IFsaScanItem_IsHidden(This)	\
    (This)->lpVtbl -> IsHidden(This)

#define IFsaScanItem_IsManageable(This,offset,size)	\
    (This)->lpVtbl -> IsManageable(This,offset,size)

#define IFsaScanItem_IsManaged(This,offset,size)	\
    (This)->lpVtbl -> IsManaged(This,offset,size)

#define IFsaScanItem_IsMbit(This)	\
    (This)->lpVtbl -> IsMbit(This)

#define IFsaScanItem_IsMigrateOK(This,pPostIt)	\
    (This)->lpVtbl -> IsMigrateOK(This,pPostIt)

#define IFsaScanItem_IsOffline(This)	\
    (This)->lpVtbl -> IsOffline(This)

#define IFsaScanItem_IsOwnerMemberOf(This,group)	\
    (This)->lpVtbl -> IsOwnerMemberOf(This,group)

#define IFsaScanItem_IsPremigrated(This,offset,size)	\
    (This)->lpVtbl -> IsPremigrated(This,offset,size)

#define IFsaScanItem_IsReadOnly(This)	\
    (This)->lpVtbl -> IsReadOnly(This)

#define IFsaScanItem_IsRecallOK(This,pPostIt)	\
    (This)->lpVtbl -> IsRecallOK(This,pPostIt)

#define IFsaScanItem_IsSparse(This)	\
    (This)->lpVtbl -> IsSparse(This)

#define IFsaScanItem_IsSystem(This)	\
    (This)->lpVtbl -> IsSystem(This)

#define IFsaScanItem_IsTotallySparse(This)	\
    (This)->lpVtbl -> IsTotallySparse(This)

#define IFsaScanItem_IsTruncated(This,offset,size)	\
    (This)->lpVtbl -> IsTruncated(This,offset,size)

#define IFsaScanItem_Manage(This,offset,size,storagePoolId,truncate)	\
    (This)->lpVtbl -> Manage(This,offset,size,storagePoolId,truncate)

#define IFsaScanItem_Move(This,dest,retainHierarcy,expandPlaceholders,overwriteExisting)	\
    (This)->lpVtbl -> Move(This,dest,retainHierarcy,expandPlaceholders,overwriteExisting)

#define IFsaScanItem_Recall(This,offset,size,deletePlaceholder)	\
    (This)->lpVtbl -> Recall(This,offset,size,deletePlaceholder)

#define IFsaScanItem_Recycle(This)	\
    (This)->lpVtbl -> Recycle(This)

#define IFsaScanItem_Truncate(This,offset,size)	\
    (This)->lpVtbl -> Truncate(This,offset,size)

#define IFsaScanItem_Unmanage(This,offset,size)	\
    (This)->lpVtbl -> Unmanage(This,offset,size)

#define IFsaScanItem_Validate(This,offset,size)	\
    (This)->lpVtbl -> Validate(This,offset,size)

#define IFsaScanItem_PrepareForManage(This,offset,size)	\
    (This)->lpVtbl -> PrepareForManage(This,offset,size)

#define IFsaScanItem_Verify(This,offset,size)	\
    (This)->lpVtbl -> Verify(This,offset,size)

#define IFsaScanItem_TruncateValidated(This,offset,size)	\
    (This)->lpVtbl -> TruncateValidated(This,offset,size)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IFsaScanItem_CheckIfSparse_Proxy( 
    IFsaScanItem * This,
    /* [in] */ LONGLONG offset,
    /* [in] */ LONGLONG size);


void __RPC_STUB IFsaScanItem_CheckIfSparse_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItem_CompareToIScanItem_Proxy( 
    IFsaScanItem * This,
    /* [in] */ IFsaScanItem *pScanItem,
    /* [out] */ SHORT *pResult);


void __RPC_STUB IFsaScanItem_CompareToIScanItem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItem_CompareToPathAndName_Proxy( 
    IFsaScanItem * This,
    /* [string][in] */ OLECHAR *path,
    /* [string][in] */ OLECHAR *name,
    /* [out] */ SHORT *pResult);


void __RPC_STUB IFsaScanItem_CompareToPathAndName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItem_Copy_Proxy( 
    IFsaScanItem * This,
    /* [string][in] */ OLECHAR *dest,
    /* [in] */ BOOL retainHierarcy,
    /* [in] */ BOOL expandPlaceholders,
    /* [in] */ BOOL overwriteExisting);


void __RPC_STUB IFsaScanItem_Copy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItem_CreateLocalStream_Proxy( 
    IFsaScanItem * This,
    /* [out] */ IStream **ppStream);


void __RPC_STUB IFsaScanItem_CreateLocalStream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItem_CreatePlaceholder_Proxy( 
    IFsaScanItem * This,
    /* [in] */ LONGLONG offset,
    /* [in] */ LONGLONG size,
    /* [in] */ FSA_PLACEHOLDER pPlaceholder,
    /* [in] */ BOOL checkUsn,
    /* [in] */ LONGLONG usn,
    /* [out] */ LONGLONG *pUsn);


void __RPC_STUB IFsaScanItem_CreatePlaceholder_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItem_Delete_Proxy( 
    IFsaScanItem * This);


void __RPC_STUB IFsaScanItem_Delete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItem_DeletePlaceholder_Proxy( 
    IFsaScanItem * This,
    /* [in] */ LONGLONG offset,
    /* [in] */ LONGLONG size);


void __RPC_STUB IFsaScanItem_DeletePlaceholder_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItem_FindFirstPlaceholder_Proxy( 
    IFsaScanItem * This,
    /* [out] */ LONGLONG *pOffset,
    /* [out] */ LONGLONG *pSize,
    /* [out] */ FSA_PLACEHOLDER *pPlaceholder);


void __RPC_STUB IFsaScanItem_FindFirstPlaceholder_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItem_FindNextPlaceholder_Proxy( 
    IFsaScanItem * This,
    /* [out][in] */ LONGLONG *pOffset,
    /* [out][in] */ LONGLONG *pSize,
    /* [out][in] */ FSA_PLACEHOLDER *pPlaceholder);


void __RPC_STUB IFsaScanItem_FindNextPlaceholder_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItem_GetAccessTime_Proxy( 
    IFsaScanItem * This,
    /* [out] */ FILETIME *pTime);


void __RPC_STUB IFsaScanItem_GetAccessTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItem_GetFileId_Proxy( 
    IFsaScanItem * This,
    /* [out] */ LONGLONG *pFileId);


void __RPC_STUB IFsaScanItem_GetFileId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItem_GetFileUsn_Proxy( 
    IFsaScanItem * This,
    /* [out] */ LONGLONG *pFileUsn);


void __RPC_STUB IFsaScanItem_GetFileUsn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItem_GetFullPathAndName_Proxy( 
    IFsaScanItem * This,
    /* [string][in] */ OLECHAR *prependix,
    /* [string][in] */ OLECHAR *appendix,
    /* [string][out][in] */ OLECHAR **pPath,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IFsaScanItem_GetFullPathAndName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItem_GetGroup_Proxy( 
    IFsaScanItem * This,
    /* [string][out][in] */ OLECHAR **pOwner,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IFsaScanItem_GetGroup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItem_GetLogicalSize_Proxy( 
    IFsaScanItem * This,
    /* [out] */ LONGLONG *pSize);


void __RPC_STUB IFsaScanItem_GetLogicalSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItem_GetModifyTime_Proxy( 
    IFsaScanItem * This,
    /* [out] */ FILETIME *pTime);


void __RPC_STUB IFsaScanItem_GetModifyTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItem_GetName_Proxy( 
    IFsaScanItem * This,
    /* [string][out][in] */ OLECHAR **pName,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IFsaScanItem_GetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItem_GetOwner_Proxy( 
    IFsaScanItem * This,
    /* [string][out][in] */ OLECHAR **pOwner,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IFsaScanItem_GetOwner_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItem_GetPathForFind_Proxy( 
    IFsaScanItem * This,
    /* [string][in] */ OLECHAR *searchName,
    /* [string][out][in] */ OLECHAR **pPath,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IFsaScanItem_GetPathForFind_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItem_GetPath_Proxy( 
    IFsaScanItem * This,
    /* [string][out][in] */ OLECHAR **pPath,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IFsaScanItem_GetPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItem_GetPathAndName_Proxy( 
    IFsaScanItem * This,
    /* [string][in] */ OLECHAR *appendix,
    /* [string][out][in] */ OLECHAR **pPath,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IFsaScanItem_GetPathAndName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItem_GetPhysicalSize_Proxy( 
    IFsaScanItem * This,
    /* [out] */ LONGLONG *pSize);


void __RPC_STUB IFsaScanItem_GetPhysicalSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItem_GetPlaceholder_Proxy( 
    IFsaScanItem * This,
    /* [in] */ LONGLONG offset,
    /* [in] */ LONGLONG size,
    /* [out] */ FSA_PLACEHOLDER *pPlaceholder);


void __RPC_STUB IFsaScanItem_GetPlaceholder_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItem_GetSession_Proxy( 
    IFsaScanItem * This,
    /* [out] */ IHsmSession **ppSession);


void __RPC_STUB IFsaScanItem_GetSession_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItem_GetUncPathAndName_Proxy( 
    IFsaScanItem * This,
    /* [string][in] */ OLECHAR *prependix,
    /* [string][in] */ OLECHAR *appendix,
    /* [string][out][in] */ OLECHAR **pPath,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IFsaScanItem_GetUncPathAndName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItem_GetVersionId_Proxy( 
    IFsaScanItem * This,
    /* [out] */ LONGLONG *pId);


void __RPC_STUB IFsaScanItem_GetVersionId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItem_HasExtendedAttributes_Proxy( 
    IFsaScanItem * This);


void __RPC_STUB IFsaScanItem_HasExtendedAttributes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItem_IsALink_Proxy( 
    IFsaScanItem * This);


void __RPC_STUB IFsaScanItem_IsALink_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItem_IsAParent_Proxy( 
    IFsaScanItem * This);


void __RPC_STUB IFsaScanItem_IsAParent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItem_IsARelativeParent_Proxy( 
    IFsaScanItem * This);


void __RPC_STUB IFsaScanItem_IsARelativeParent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItem_IsCompressed_Proxy( 
    IFsaScanItem * This);


void __RPC_STUB IFsaScanItem_IsCompressed_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItem_IsDeleteOK_Proxy( 
    IFsaScanItem * This,
    /* [in] */ IFsaPostIt *pPostIt);


void __RPC_STUB IFsaScanItem_IsDeleteOK_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItem_IsEncrypted_Proxy( 
    IFsaScanItem * This);


void __RPC_STUB IFsaScanItem_IsEncrypted_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItem_IsGroupMemberOf_Proxy( 
    IFsaScanItem * This,
    /* [string][in] */ OLECHAR *group);


void __RPC_STUB IFsaScanItem_IsGroupMemberOf_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItem_IsHidden_Proxy( 
    IFsaScanItem * This);


void __RPC_STUB IFsaScanItem_IsHidden_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItem_IsManageable_Proxy( 
    IFsaScanItem * This,
    /* [in] */ LONGLONG offset,
    /* [in] */ LONGLONG size);


void __RPC_STUB IFsaScanItem_IsManageable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItem_IsManaged_Proxy( 
    IFsaScanItem * This,
    /* [in] */ LONGLONG offset,
    /* [in] */ LONGLONG size);


void __RPC_STUB IFsaScanItem_IsManaged_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItem_IsMbit_Proxy( 
    IFsaScanItem * This);


void __RPC_STUB IFsaScanItem_IsMbit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItem_IsMigrateOK_Proxy( 
    IFsaScanItem * This,
    /* [in] */ IFsaPostIt *pPostIt);


void __RPC_STUB IFsaScanItem_IsMigrateOK_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItem_IsOffline_Proxy( 
    IFsaScanItem * This);


void __RPC_STUB IFsaScanItem_IsOffline_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItem_IsOwnerMemberOf_Proxy( 
    IFsaScanItem * This,
    /* [string][in] */ OLECHAR *group);


void __RPC_STUB IFsaScanItem_IsOwnerMemberOf_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItem_IsPremigrated_Proxy( 
    IFsaScanItem * This,
    /* [in] */ LONGLONG offset,
    /* [in] */ LONGLONG size);


void __RPC_STUB IFsaScanItem_IsPremigrated_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItem_IsReadOnly_Proxy( 
    IFsaScanItem * This);


void __RPC_STUB IFsaScanItem_IsReadOnly_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItem_IsRecallOK_Proxy( 
    IFsaScanItem * This,
    /* [in] */ IFsaPostIt *pPostIt);


void __RPC_STUB IFsaScanItem_IsRecallOK_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItem_IsSparse_Proxy( 
    IFsaScanItem * This);


void __RPC_STUB IFsaScanItem_IsSparse_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItem_IsSystem_Proxy( 
    IFsaScanItem * This);


void __RPC_STUB IFsaScanItem_IsSystem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItem_IsTotallySparse_Proxy( 
    IFsaScanItem * This);


void __RPC_STUB IFsaScanItem_IsTotallySparse_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItem_IsTruncated_Proxy( 
    IFsaScanItem * This,
    /* [in] */ LONGLONG offset,
    /* [in] */ LONGLONG size);


void __RPC_STUB IFsaScanItem_IsTruncated_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItem_Manage_Proxy( 
    IFsaScanItem * This,
    /* [in] */ LONGLONG offset,
    /* [in] */ LONGLONG size,
    /* [in] */ GUID storagePoolId,
    /* [in] */ BOOL truncate);


void __RPC_STUB IFsaScanItem_Manage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItem_Move_Proxy( 
    IFsaScanItem * This,
    /* [string][in] */ OLECHAR *dest,
    /* [in] */ BOOL retainHierarcy,
    /* [in] */ BOOL expandPlaceholders,
    /* [in] */ BOOL overwriteExisting);


void __RPC_STUB IFsaScanItem_Move_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItem_Recall_Proxy( 
    IFsaScanItem * This,
    /* [in] */ LONGLONG offset,
    /* [in] */ LONGLONG size,
    /* [in] */ BOOL deletePlaceholder);


void __RPC_STUB IFsaScanItem_Recall_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItem_Recycle_Proxy( 
    IFsaScanItem * This);


void __RPC_STUB IFsaScanItem_Recycle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItem_Truncate_Proxy( 
    IFsaScanItem * This,
    /* [in] */ LONGLONG offset,
    /* [in] */ LONGLONG size);


void __RPC_STUB IFsaScanItem_Truncate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItem_Unmanage_Proxy( 
    IFsaScanItem * This,
    /* [in] */ LONGLONG offset,
    /* [in] */ LONGLONG size);


void __RPC_STUB IFsaScanItem_Unmanage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItem_Validate_Proxy( 
    IFsaScanItem * This,
    /* [in] */ LONGLONG offset,
    /* [in] */ LONGLONG size);


void __RPC_STUB IFsaScanItem_Validate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItem_PrepareForManage_Proxy( 
    IFsaScanItem * This,
    /* [in] */ LONGLONG offset,
    /* [in] */ LONGLONG size);


void __RPC_STUB IFsaScanItem_PrepareForManage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItem_Verify_Proxy( 
    IFsaScanItem * This,
    /* [in] */ LONGLONG offset,
    /* [in] */ LONGLONG size);


void __RPC_STUB IFsaScanItem_Verify_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItem_TruncateValidated_Proxy( 
    IFsaScanItem * This,
    /* [in] */ LONGLONG offset,
    /* [in] */ LONGLONG size);


void __RPC_STUB IFsaScanItem_TruncateValidated_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IFsaScanItem_INTERFACE_DEFINED__ */


#ifndef __IFsaServer_INTERFACE_DEFINED__
#define __IFsaServer_INTERFACE_DEFINED__

/* interface IFsaServer */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IFsaServer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C49D553D-CA2B-4482-A404-CD4B6B44EAE4")
    IFsaServer : public IHsmSystemState
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE EnumResources( 
            /* [out] */ IWsbEnum **ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FindResourceByAlternatePath( 
            /* [string][in] */ OLECHAR *path,
            /* [out] */ IFsaResource **ppResource) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FindResourceById( 
            /* [in] */ GUID id,
            /* [out] */ IFsaResource **ppResource) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FindResourceByName( 
            /* [string][in] */ OLECHAR *name,
            /* [out] */ IFsaResource **ppResource) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FindResourceByPath( 
            /* [string][in] */ OLECHAR *path,
            /* [out] */ IFsaResource **ppResource) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FindResourceBySerial( 
            /* [in] */ ULONG serial,
            /* [out] */ IFsaResource **ppResource) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FindResourceByStickyName( 
            /* [string][in] */ OLECHAR *name,
            /* [out] */ IFsaResource **ppResource) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAutosave( 
            /* [out] */ ULONG *pMilliseconds) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDbPath( 
            /* [string][out][in] */ OLECHAR **pPath,
            ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDbPathAndName( 
            /* [string][out][in] */ OLECHAR **pPath,
            ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIDbSys( 
            /* [out] */ IWsbDbSys **ppDbSys) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUnmanageIDbSys( 
            /* [out] */ IWsbDbSys **ppDbSys) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFilter( 
            /* [out] */ IFsaFilter **ppFilter) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIDbPath( 
            /* [string][out][in] */ OLECHAR **pPath,
            ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUnmanageIDbPath( 
            /* [string][out][in] */ OLECHAR **pPath,
            ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIdentifier( 
            /* [out] */ GUID *pId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLogicalName( 
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetName( 
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Init( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ScanForResources( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAutosave( 
            /* [in] */ ULONG milliseconds) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFsaServerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFsaServer * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFsaServer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFsaServer * This);
        
        HRESULT ( STDMETHODCALLTYPE *ChangeSysState )( 
            IFsaServer * This,
            /* [out][in] */ HSM_SYSTEM_STATE *pSysState);
        
        HRESULT ( STDMETHODCALLTYPE *EnumResources )( 
            IFsaServer * This,
            /* [out] */ IWsbEnum **ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE *FindResourceByAlternatePath )( 
            IFsaServer * This,
            /* [string][in] */ OLECHAR *path,
            /* [out] */ IFsaResource **ppResource);
        
        HRESULT ( STDMETHODCALLTYPE *FindResourceById )( 
            IFsaServer * This,
            /* [in] */ GUID id,
            /* [out] */ IFsaResource **ppResource);
        
        HRESULT ( STDMETHODCALLTYPE *FindResourceByName )( 
            IFsaServer * This,
            /* [string][in] */ OLECHAR *name,
            /* [out] */ IFsaResource **ppResource);
        
        HRESULT ( STDMETHODCALLTYPE *FindResourceByPath )( 
            IFsaServer * This,
            /* [string][in] */ OLECHAR *path,
            /* [out] */ IFsaResource **ppResource);
        
        HRESULT ( STDMETHODCALLTYPE *FindResourceBySerial )( 
            IFsaServer * This,
            /* [in] */ ULONG serial,
            /* [out] */ IFsaResource **ppResource);
        
        HRESULT ( STDMETHODCALLTYPE *FindResourceByStickyName )( 
            IFsaServer * This,
            /* [string][in] */ OLECHAR *name,
            /* [out] */ IFsaResource **ppResource);
        
        HRESULT ( STDMETHODCALLTYPE *GetAutosave )( 
            IFsaServer * This,
            /* [out] */ ULONG *pMilliseconds);
        
        HRESULT ( STDMETHODCALLTYPE *GetDbPath )( 
            IFsaServer * This,
            /* [string][out][in] */ OLECHAR **pPath,
            ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetDbPathAndName )( 
            IFsaServer * This,
            /* [string][out][in] */ OLECHAR **pPath,
            ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDbSys )( 
            IFsaServer * This,
            /* [out] */ IWsbDbSys **ppDbSys);
        
        HRESULT ( STDMETHODCALLTYPE *GetUnmanageIDbSys )( 
            IFsaServer * This,
            /* [out] */ IWsbDbSys **ppDbSys);
        
        HRESULT ( STDMETHODCALLTYPE *GetFilter )( 
            IFsaServer * This,
            /* [out] */ IFsaFilter **ppFilter);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDbPath )( 
            IFsaServer * This,
            /* [string][out][in] */ OLECHAR **pPath,
            ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetUnmanageIDbPath )( 
            IFsaServer * This,
            /* [string][out][in] */ OLECHAR **pPath,
            ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetIdentifier )( 
            IFsaServer * This,
            /* [out] */ GUID *pId);
        
        HRESULT ( STDMETHODCALLTYPE *GetLogicalName )( 
            IFsaServer * This,
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetName )( 
            IFsaServer * This,
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *Init )( 
            IFsaServer * This);
        
        HRESULT ( STDMETHODCALLTYPE *ScanForResources )( 
            IFsaServer * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetAutosave )( 
            IFsaServer * This,
            /* [in] */ ULONG milliseconds);
        
        END_INTERFACE
    } IFsaServerVtbl;

    interface IFsaServer
    {
        CONST_VTBL struct IFsaServerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFsaServer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFsaServer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFsaServer_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFsaServer_ChangeSysState(This,pSysState)	\
    (This)->lpVtbl -> ChangeSysState(This,pSysState)


#define IFsaServer_EnumResources(This,ppEnum)	\
    (This)->lpVtbl -> EnumResources(This,ppEnum)

#define IFsaServer_FindResourceByAlternatePath(This,path,ppResource)	\
    (This)->lpVtbl -> FindResourceByAlternatePath(This,path,ppResource)

#define IFsaServer_FindResourceById(This,id,ppResource)	\
    (This)->lpVtbl -> FindResourceById(This,id,ppResource)

#define IFsaServer_FindResourceByName(This,name,ppResource)	\
    (This)->lpVtbl -> FindResourceByName(This,name,ppResource)

#define IFsaServer_FindResourceByPath(This,path,ppResource)	\
    (This)->lpVtbl -> FindResourceByPath(This,path,ppResource)

#define IFsaServer_FindResourceBySerial(This,serial,ppResource)	\
    (This)->lpVtbl -> FindResourceBySerial(This,serial,ppResource)

#define IFsaServer_FindResourceByStickyName(This,name,ppResource)	\
    (This)->lpVtbl -> FindResourceByStickyName(This,name,ppResource)

#define IFsaServer_GetAutosave(This,pMilliseconds)	\
    (This)->lpVtbl -> GetAutosave(This,pMilliseconds)

#define IFsaServer_GetDbPath(This,pPath,bufferSize)	\
    (This)->lpVtbl -> GetDbPath(This,pPath,bufferSize)

#define IFsaServer_GetDbPathAndName(This,pPath,bufferSize)	\
    (This)->lpVtbl -> GetDbPathAndName(This,pPath,bufferSize)

#define IFsaServer_GetIDbSys(This,ppDbSys)	\
    (This)->lpVtbl -> GetIDbSys(This,ppDbSys)

#define IFsaServer_GetUnmanageIDbSys(This,ppDbSys)	\
    (This)->lpVtbl -> GetUnmanageIDbSys(This,ppDbSys)

#define IFsaServer_GetFilter(This,ppFilter)	\
    (This)->lpVtbl -> GetFilter(This,ppFilter)

#define IFsaServer_GetIDbPath(This,pPath,bufferSize)	\
    (This)->lpVtbl -> GetIDbPath(This,pPath,bufferSize)

#define IFsaServer_GetUnmanageIDbPath(This,pPath,bufferSize)	\
    (This)->lpVtbl -> GetUnmanageIDbPath(This,pPath,bufferSize)

#define IFsaServer_GetIdentifier(This,pId)	\
    (This)->lpVtbl -> GetIdentifier(This,pId)

#define IFsaServer_GetLogicalName(This,pName,bufferSize)	\
    (This)->lpVtbl -> GetLogicalName(This,pName,bufferSize)

#define IFsaServer_GetName(This,pName,bufferSize)	\
    (This)->lpVtbl -> GetName(This,pName,bufferSize)

#define IFsaServer_Init(This)	\
    (This)->lpVtbl -> Init(This)

#define IFsaServer_ScanForResources(This)	\
    (This)->lpVtbl -> ScanForResources(This)

#define IFsaServer_SetAutosave(This,milliseconds)	\
    (This)->lpVtbl -> SetAutosave(This,milliseconds)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IFsaServer_EnumResources_Proxy( 
    IFsaServer * This,
    /* [out] */ IWsbEnum **ppEnum);


void __RPC_STUB IFsaServer_EnumResources_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaServer_FindResourceByAlternatePath_Proxy( 
    IFsaServer * This,
    /* [string][in] */ OLECHAR *path,
    /* [out] */ IFsaResource **ppResource);


void __RPC_STUB IFsaServer_FindResourceByAlternatePath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaServer_FindResourceById_Proxy( 
    IFsaServer * This,
    /* [in] */ GUID id,
    /* [out] */ IFsaResource **ppResource);


void __RPC_STUB IFsaServer_FindResourceById_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaServer_FindResourceByName_Proxy( 
    IFsaServer * This,
    /* [string][in] */ OLECHAR *name,
    /* [out] */ IFsaResource **ppResource);


void __RPC_STUB IFsaServer_FindResourceByName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaServer_FindResourceByPath_Proxy( 
    IFsaServer * This,
    /* [string][in] */ OLECHAR *path,
    /* [out] */ IFsaResource **ppResource);


void __RPC_STUB IFsaServer_FindResourceByPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaServer_FindResourceBySerial_Proxy( 
    IFsaServer * This,
    /* [in] */ ULONG serial,
    /* [out] */ IFsaResource **ppResource);


void __RPC_STUB IFsaServer_FindResourceBySerial_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaServer_FindResourceByStickyName_Proxy( 
    IFsaServer * This,
    /* [string][in] */ OLECHAR *name,
    /* [out] */ IFsaResource **ppResource);


void __RPC_STUB IFsaServer_FindResourceByStickyName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaServer_GetAutosave_Proxy( 
    IFsaServer * This,
    /* [out] */ ULONG *pMilliseconds);


void __RPC_STUB IFsaServer_GetAutosave_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaServer_GetDbPath_Proxy( 
    IFsaServer * This,
    /* [string][out][in] */ OLECHAR **pPath,
    ULONG bufferSize);


void __RPC_STUB IFsaServer_GetDbPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaServer_GetDbPathAndName_Proxy( 
    IFsaServer * This,
    /* [string][out][in] */ OLECHAR **pPath,
    ULONG bufferSize);


void __RPC_STUB IFsaServer_GetDbPathAndName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaServer_GetIDbSys_Proxy( 
    IFsaServer * This,
    /* [out] */ IWsbDbSys **ppDbSys);


void __RPC_STUB IFsaServer_GetIDbSys_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaServer_GetUnmanageIDbSys_Proxy( 
    IFsaServer * This,
    /* [out] */ IWsbDbSys **ppDbSys);


void __RPC_STUB IFsaServer_GetUnmanageIDbSys_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaServer_GetFilter_Proxy( 
    IFsaServer * This,
    /* [out] */ IFsaFilter **ppFilter);


void __RPC_STUB IFsaServer_GetFilter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaServer_GetIDbPath_Proxy( 
    IFsaServer * This,
    /* [string][out][in] */ OLECHAR **pPath,
    ULONG bufferSize);


void __RPC_STUB IFsaServer_GetIDbPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaServer_GetUnmanageIDbPath_Proxy( 
    IFsaServer * This,
    /* [string][out][in] */ OLECHAR **pPath,
    ULONG bufferSize);


void __RPC_STUB IFsaServer_GetUnmanageIDbPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaServer_GetIdentifier_Proxy( 
    IFsaServer * This,
    /* [out] */ GUID *pId);


void __RPC_STUB IFsaServer_GetIdentifier_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaServer_GetLogicalName_Proxy( 
    IFsaServer * This,
    /* [string][out][in] */ OLECHAR **pName,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IFsaServer_GetLogicalName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaServer_GetName_Proxy( 
    IFsaServer * This,
    /* [string][out][in] */ OLECHAR **pName,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IFsaServer_GetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaServer_Init_Proxy( 
    IFsaServer * This);


void __RPC_STUB IFsaServer_Init_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaServer_ScanForResources_Proxy( 
    IFsaServer * This);


void __RPC_STUB IFsaServer_ScanForResources_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaServer_SetAutosave_Proxy( 
    IFsaServer * This,
    /* [in] */ ULONG milliseconds);


void __RPC_STUB IFsaServer_SetAutosave_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IFsaServer_INTERFACE_DEFINED__ */


#ifndef __IFsaTruncator_INTERFACE_DEFINED__
#define __IFsaTruncator_INTERFACE_DEFINED__

/* interface IFsaTruncator */
/* [unique][helpstring][uuid][object] */ 

typedef 
enum _FSA_PREMIGRATED_SORT_ORDER
    {	FSA_SORT_PL_BY_ACCESS_TIME	= 0,
	FSA_SORT_PL_BY_SIZE	= 1,
	FSA_SORT_PL_BY_PATH_NAME	= 2,
	FSA_SORT_PL_BY_SIZE_AND_TIME	= 3
    } 	FSA_PREMIGRATED_SORT_ORDER;


EXTERN_C const IID IID_IFsaTruncator;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9CABC042-8AA4-11d0-81E6-00A0C91180F2")
    IFsaTruncator : public IHsmSystemState
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetSession( 
            /* [out] */ IHsmSession **ppSession) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetKeepRecallTime( 
            /* [out] */ FILETIME *pTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMaxFilesPerRun( 
            /* [out] */ LONGLONG *pMaxFiles) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPremigratedSortOrder( 
            /* [out] */ FSA_PREMIGRATED_SORT_ORDER *pSortOrder) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRunInterval( 
            /* [out] */ ULONG *pMilliseconds) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMaxFilesPerRun( 
            /* [in] */ LONGLONG maxFiles) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPremigratedSortOrder( 
            /* [in] */ FSA_PREMIGRATED_SORT_ORDER SortOrder) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRunInterval( 
            /* [in] */ ULONG milliseconds) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetKeepRecallTime( 
            /* [in] */ FILETIME time) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Start( 
            /* [in] */ IFsaResource *pResource) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE KickStart( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFsaTruncatorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFsaTruncator * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFsaTruncator * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFsaTruncator * This);
        
        HRESULT ( STDMETHODCALLTYPE *ChangeSysState )( 
            IFsaTruncator * This,
            /* [out][in] */ HSM_SYSTEM_STATE *pSysState);
        
        HRESULT ( STDMETHODCALLTYPE *GetSession )( 
            IFsaTruncator * This,
            /* [out] */ IHsmSession **ppSession);
        
        HRESULT ( STDMETHODCALLTYPE *GetKeepRecallTime )( 
            IFsaTruncator * This,
            /* [out] */ FILETIME *pTime);
        
        HRESULT ( STDMETHODCALLTYPE *GetMaxFilesPerRun )( 
            IFsaTruncator * This,
            /* [out] */ LONGLONG *pMaxFiles);
        
        HRESULT ( STDMETHODCALLTYPE *GetPremigratedSortOrder )( 
            IFsaTruncator * This,
            /* [out] */ FSA_PREMIGRATED_SORT_ORDER *pSortOrder);
        
        HRESULT ( STDMETHODCALLTYPE *GetRunInterval )( 
            IFsaTruncator * This,
            /* [out] */ ULONG *pMilliseconds);
        
        HRESULT ( STDMETHODCALLTYPE *SetMaxFilesPerRun )( 
            IFsaTruncator * This,
            /* [in] */ LONGLONG maxFiles);
        
        HRESULT ( STDMETHODCALLTYPE *SetPremigratedSortOrder )( 
            IFsaTruncator * This,
            /* [in] */ FSA_PREMIGRATED_SORT_ORDER SortOrder);
        
        HRESULT ( STDMETHODCALLTYPE *SetRunInterval )( 
            IFsaTruncator * This,
            /* [in] */ ULONG milliseconds);
        
        HRESULT ( STDMETHODCALLTYPE *SetKeepRecallTime )( 
            IFsaTruncator * This,
            /* [in] */ FILETIME time);
        
        HRESULT ( STDMETHODCALLTYPE *Start )( 
            IFsaTruncator * This,
            /* [in] */ IFsaResource *pResource);
        
        HRESULT ( STDMETHODCALLTYPE *KickStart )( 
            IFsaTruncator * This);
        
        END_INTERFACE
    } IFsaTruncatorVtbl;

    interface IFsaTruncator
    {
        CONST_VTBL struct IFsaTruncatorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFsaTruncator_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFsaTruncator_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFsaTruncator_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFsaTruncator_ChangeSysState(This,pSysState)	\
    (This)->lpVtbl -> ChangeSysState(This,pSysState)


#define IFsaTruncator_GetSession(This,ppSession)	\
    (This)->lpVtbl -> GetSession(This,ppSession)

#define IFsaTruncator_GetKeepRecallTime(This,pTime)	\
    (This)->lpVtbl -> GetKeepRecallTime(This,pTime)

#define IFsaTruncator_GetMaxFilesPerRun(This,pMaxFiles)	\
    (This)->lpVtbl -> GetMaxFilesPerRun(This,pMaxFiles)

#define IFsaTruncator_GetPremigratedSortOrder(This,pSortOrder)	\
    (This)->lpVtbl -> GetPremigratedSortOrder(This,pSortOrder)

#define IFsaTruncator_GetRunInterval(This,pMilliseconds)	\
    (This)->lpVtbl -> GetRunInterval(This,pMilliseconds)

#define IFsaTruncator_SetMaxFilesPerRun(This,maxFiles)	\
    (This)->lpVtbl -> SetMaxFilesPerRun(This,maxFiles)

#define IFsaTruncator_SetPremigratedSortOrder(This,SortOrder)	\
    (This)->lpVtbl -> SetPremigratedSortOrder(This,SortOrder)

#define IFsaTruncator_SetRunInterval(This,milliseconds)	\
    (This)->lpVtbl -> SetRunInterval(This,milliseconds)

#define IFsaTruncator_SetKeepRecallTime(This,time)	\
    (This)->lpVtbl -> SetKeepRecallTime(This,time)

#define IFsaTruncator_Start(This,pResource)	\
    (This)->lpVtbl -> Start(This,pResource)

#define IFsaTruncator_KickStart(This)	\
    (This)->lpVtbl -> KickStart(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IFsaTruncator_GetSession_Proxy( 
    IFsaTruncator * This,
    /* [out] */ IHsmSession **ppSession);


void __RPC_STUB IFsaTruncator_GetSession_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaTruncator_GetKeepRecallTime_Proxy( 
    IFsaTruncator * This,
    /* [out] */ FILETIME *pTime);


void __RPC_STUB IFsaTruncator_GetKeepRecallTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaTruncator_GetMaxFilesPerRun_Proxy( 
    IFsaTruncator * This,
    /* [out] */ LONGLONG *pMaxFiles);


void __RPC_STUB IFsaTruncator_GetMaxFilesPerRun_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaTruncator_GetPremigratedSortOrder_Proxy( 
    IFsaTruncator * This,
    /* [out] */ FSA_PREMIGRATED_SORT_ORDER *pSortOrder);


void __RPC_STUB IFsaTruncator_GetPremigratedSortOrder_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaTruncator_GetRunInterval_Proxy( 
    IFsaTruncator * This,
    /* [out] */ ULONG *pMilliseconds);


void __RPC_STUB IFsaTruncator_GetRunInterval_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaTruncator_SetMaxFilesPerRun_Proxy( 
    IFsaTruncator * This,
    /* [in] */ LONGLONG maxFiles);


void __RPC_STUB IFsaTruncator_SetMaxFilesPerRun_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaTruncator_SetPremigratedSortOrder_Proxy( 
    IFsaTruncator * This,
    /* [in] */ FSA_PREMIGRATED_SORT_ORDER SortOrder);


void __RPC_STUB IFsaTruncator_SetPremigratedSortOrder_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaTruncator_SetRunInterval_Proxy( 
    IFsaTruncator * This,
    /* [in] */ ULONG milliseconds);


void __RPC_STUB IFsaTruncator_SetRunInterval_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaTruncator_SetKeepRecallTime_Proxy( 
    IFsaTruncator * This,
    /* [in] */ FILETIME time);


void __RPC_STUB IFsaTruncator_SetKeepRecallTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaTruncator_Start_Proxy( 
    IFsaTruncator * This,
    /* [in] */ IFsaResource *pResource);


void __RPC_STUB IFsaTruncator_Start_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaTruncator_KickStart_Proxy( 
    IFsaTruncator * This);


void __RPC_STUB IFsaTruncator_KickStart_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IFsaTruncator_INTERFACE_DEFINED__ */


#ifndef __IFsaPostIt_INTERFACE_DEFINED__
#define __IFsaPostIt_INTERFACE_DEFINED__

/* interface IFsaPostIt */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IFsaPostIt;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B5A1ED6A-CED4-4D16-9A76-8CD4473A2CE9")
    IFsaPostIt : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetFileVersionId( 
            /* [out] */ LONGLONG *pFileVersionId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFilterRecall( 
            /* [out] */ IFsaFilterRecall **ppRecall) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMode( 
            /* [out] */ ULONG *pMode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPath( 
            /* [string][out][in] */ OLECHAR **pPath,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPlaceholder( 
            /* [out] */ FSA_PLACEHOLDER *pPlaceholder) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRequestAction( 
            /* [out] */ FSA_REQUEST_ACTION *pRequestAction) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRequestOffset( 
            /* [out] */ LONGLONG *pRequestOffset) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRequestSize( 
            /* [out] */ LONGLONG *pRequestSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetResult( 
            /* [out] */ HRESULT *pHr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetResultAction( 
            /* [out] */ FSA_RESULT_ACTION *pResultAction) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSession( 
            /* [out] */ IHsmSession **ppSession) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStoragePoolId( 
            /* [out] */ GUID *pStoragePoolId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUSN( 
            /* [out] */ LONGLONG *pUsn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetThreadId( 
            /* [out] */ DWORD *pThreadId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFileVersionId( 
            /* [in] */ LONGLONG fileVersionId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFilterRecall( 
            /* [in] */ IFsaFilterRecall *pRecall) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMode( 
            /* [in] */ ULONG mode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPath( 
            /* [string][in] */ OLECHAR *path) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPlaceholder( 
            /* [in] */ FSA_PLACEHOLDER *pPlaceholder) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRequestAction( 
            /* [in] */ FSA_REQUEST_ACTION requestAction) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRequestOffset( 
            /* [in] */ LONGLONG requestOffset) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRequestSize( 
            /* [in] */ LONGLONG requestSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetResult( 
            /* [in] */ HRESULT hr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetResultAction( 
            /* [in] */ FSA_RESULT_ACTION pResultAction) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSession( 
            /* [in] */ IHsmSession *pSession) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetStoragePoolId( 
            /* [in] */ GUID storagePoolId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetUSN( 
            /* [in] */ LONGLONG usn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetThreadId( 
            /* [in] */ DWORD threadId) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFsaPostItVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFsaPostIt * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFsaPostIt * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFsaPostIt * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetFileVersionId )( 
            IFsaPostIt * This,
            /* [out] */ LONGLONG *pFileVersionId);
        
        HRESULT ( STDMETHODCALLTYPE *GetFilterRecall )( 
            IFsaPostIt * This,
            /* [out] */ IFsaFilterRecall **ppRecall);
        
        HRESULT ( STDMETHODCALLTYPE *GetMode )( 
            IFsaPostIt * This,
            /* [out] */ ULONG *pMode);
        
        HRESULT ( STDMETHODCALLTYPE *GetPath )( 
            IFsaPostIt * This,
            /* [string][out][in] */ OLECHAR **pPath,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetPlaceholder )( 
            IFsaPostIt * This,
            /* [out] */ FSA_PLACEHOLDER *pPlaceholder);
        
        HRESULT ( STDMETHODCALLTYPE *GetRequestAction )( 
            IFsaPostIt * This,
            /* [out] */ FSA_REQUEST_ACTION *pRequestAction);
        
        HRESULT ( STDMETHODCALLTYPE *GetRequestOffset )( 
            IFsaPostIt * This,
            /* [out] */ LONGLONG *pRequestOffset);
        
        HRESULT ( STDMETHODCALLTYPE *GetRequestSize )( 
            IFsaPostIt * This,
            /* [out] */ LONGLONG *pRequestSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetResult )( 
            IFsaPostIt * This,
            /* [out] */ HRESULT *pHr);
        
        HRESULT ( STDMETHODCALLTYPE *GetResultAction )( 
            IFsaPostIt * This,
            /* [out] */ FSA_RESULT_ACTION *pResultAction);
        
        HRESULT ( STDMETHODCALLTYPE *GetSession )( 
            IFsaPostIt * This,
            /* [out] */ IHsmSession **ppSession);
        
        HRESULT ( STDMETHODCALLTYPE *GetStoragePoolId )( 
            IFsaPostIt * This,
            /* [out] */ GUID *pStoragePoolId);
        
        HRESULT ( STDMETHODCALLTYPE *GetUSN )( 
            IFsaPostIt * This,
            /* [out] */ LONGLONG *pUsn);
        
        HRESULT ( STDMETHODCALLTYPE *GetThreadId )( 
            IFsaPostIt * This,
            /* [out] */ DWORD *pThreadId);
        
        HRESULT ( STDMETHODCALLTYPE *SetFileVersionId )( 
            IFsaPostIt * This,
            /* [in] */ LONGLONG fileVersionId);
        
        HRESULT ( STDMETHODCALLTYPE *SetFilterRecall )( 
            IFsaPostIt * This,
            /* [in] */ IFsaFilterRecall *pRecall);
        
        HRESULT ( STDMETHODCALLTYPE *SetMode )( 
            IFsaPostIt * This,
            /* [in] */ ULONG mode);
        
        HRESULT ( STDMETHODCALLTYPE *SetPath )( 
            IFsaPostIt * This,
            /* [string][in] */ OLECHAR *path);
        
        HRESULT ( STDMETHODCALLTYPE *SetPlaceholder )( 
            IFsaPostIt * This,
            /* [in] */ FSA_PLACEHOLDER *pPlaceholder);
        
        HRESULT ( STDMETHODCALLTYPE *SetRequestAction )( 
            IFsaPostIt * This,
            /* [in] */ FSA_REQUEST_ACTION requestAction);
        
        HRESULT ( STDMETHODCALLTYPE *SetRequestOffset )( 
            IFsaPostIt * This,
            /* [in] */ LONGLONG requestOffset);
        
        HRESULT ( STDMETHODCALLTYPE *SetRequestSize )( 
            IFsaPostIt * This,
            /* [in] */ LONGLONG requestSize);
        
        HRESULT ( STDMETHODCALLTYPE *SetResult )( 
            IFsaPostIt * This,
            /* [in] */ HRESULT hr);
        
        HRESULT ( STDMETHODCALLTYPE *SetResultAction )( 
            IFsaPostIt * This,
            /* [in] */ FSA_RESULT_ACTION pResultAction);
        
        HRESULT ( STDMETHODCALLTYPE *SetSession )( 
            IFsaPostIt * This,
            /* [in] */ IHsmSession *pSession);
        
        HRESULT ( STDMETHODCALLTYPE *SetStoragePoolId )( 
            IFsaPostIt * This,
            /* [in] */ GUID storagePoolId);
        
        HRESULT ( STDMETHODCALLTYPE *SetUSN )( 
            IFsaPostIt * This,
            /* [in] */ LONGLONG usn);
        
        HRESULT ( STDMETHODCALLTYPE *SetThreadId )( 
            IFsaPostIt * This,
            /* [in] */ DWORD threadId);
        
        END_INTERFACE
    } IFsaPostItVtbl;

    interface IFsaPostIt
    {
        CONST_VTBL struct IFsaPostItVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFsaPostIt_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFsaPostIt_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFsaPostIt_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFsaPostIt_GetFileVersionId(This,pFileVersionId)	\
    (This)->lpVtbl -> GetFileVersionId(This,pFileVersionId)

#define IFsaPostIt_GetFilterRecall(This,ppRecall)	\
    (This)->lpVtbl -> GetFilterRecall(This,ppRecall)

#define IFsaPostIt_GetMode(This,pMode)	\
    (This)->lpVtbl -> GetMode(This,pMode)

#define IFsaPostIt_GetPath(This,pPath,bufferSize)	\
    (This)->lpVtbl -> GetPath(This,pPath,bufferSize)

#define IFsaPostIt_GetPlaceholder(This,pPlaceholder)	\
    (This)->lpVtbl -> GetPlaceholder(This,pPlaceholder)

#define IFsaPostIt_GetRequestAction(This,pRequestAction)	\
    (This)->lpVtbl -> GetRequestAction(This,pRequestAction)

#define IFsaPostIt_GetRequestOffset(This,pRequestOffset)	\
    (This)->lpVtbl -> GetRequestOffset(This,pRequestOffset)

#define IFsaPostIt_GetRequestSize(This,pRequestSize)	\
    (This)->lpVtbl -> GetRequestSize(This,pRequestSize)

#define IFsaPostIt_GetResult(This,pHr)	\
    (This)->lpVtbl -> GetResult(This,pHr)

#define IFsaPostIt_GetResultAction(This,pResultAction)	\
    (This)->lpVtbl -> GetResultAction(This,pResultAction)

#define IFsaPostIt_GetSession(This,ppSession)	\
    (This)->lpVtbl -> GetSession(This,ppSession)

#define IFsaPostIt_GetStoragePoolId(This,pStoragePoolId)	\
    (This)->lpVtbl -> GetStoragePoolId(This,pStoragePoolId)

#define IFsaPostIt_GetUSN(This,pUsn)	\
    (This)->lpVtbl -> GetUSN(This,pUsn)

#define IFsaPostIt_GetThreadId(This,pThreadId)	\
    (This)->lpVtbl -> GetThreadId(This,pThreadId)

#define IFsaPostIt_SetFileVersionId(This,fileVersionId)	\
    (This)->lpVtbl -> SetFileVersionId(This,fileVersionId)

#define IFsaPostIt_SetFilterRecall(This,pRecall)	\
    (This)->lpVtbl -> SetFilterRecall(This,pRecall)

#define IFsaPostIt_SetMode(This,mode)	\
    (This)->lpVtbl -> SetMode(This,mode)

#define IFsaPostIt_SetPath(This,path)	\
    (This)->lpVtbl -> SetPath(This,path)

#define IFsaPostIt_SetPlaceholder(This,pPlaceholder)	\
    (This)->lpVtbl -> SetPlaceholder(This,pPlaceholder)

#define IFsaPostIt_SetRequestAction(This,requestAction)	\
    (This)->lpVtbl -> SetRequestAction(This,requestAction)

#define IFsaPostIt_SetRequestOffset(This,requestOffset)	\
    (This)->lpVtbl -> SetRequestOffset(This,requestOffset)

#define IFsaPostIt_SetRequestSize(This,requestSize)	\
    (This)->lpVtbl -> SetRequestSize(This,requestSize)

#define IFsaPostIt_SetResult(This,hr)	\
    (This)->lpVtbl -> SetResult(This,hr)

#define IFsaPostIt_SetResultAction(This,pResultAction)	\
    (This)->lpVtbl -> SetResultAction(This,pResultAction)

#define IFsaPostIt_SetSession(This,pSession)	\
    (This)->lpVtbl -> SetSession(This,pSession)

#define IFsaPostIt_SetStoragePoolId(This,storagePoolId)	\
    (This)->lpVtbl -> SetStoragePoolId(This,storagePoolId)

#define IFsaPostIt_SetUSN(This,usn)	\
    (This)->lpVtbl -> SetUSN(This,usn)

#define IFsaPostIt_SetThreadId(This,threadId)	\
    (This)->lpVtbl -> SetThreadId(This,threadId)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IFsaPostIt_GetFileVersionId_Proxy( 
    IFsaPostIt * This,
    /* [out] */ LONGLONG *pFileVersionId);


void __RPC_STUB IFsaPostIt_GetFileVersionId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaPostIt_GetFilterRecall_Proxy( 
    IFsaPostIt * This,
    /* [out] */ IFsaFilterRecall **ppRecall);


void __RPC_STUB IFsaPostIt_GetFilterRecall_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaPostIt_GetMode_Proxy( 
    IFsaPostIt * This,
    /* [out] */ ULONG *pMode);


void __RPC_STUB IFsaPostIt_GetMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaPostIt_GetPath_Proxy( 
    IFsaPostIt * This,
    /* [string][out][in] */ OLECHAR **pPath,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IFsaPostIt_GetPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaPostIt_GetPlaceholder_Proxy( 
    IFsaPostIt * This,
    /* [out] */ FSA_PLACEHOLDER *pPlaceholder);


void __RPC_STUB IFsaPostIt_GetPlaceholder_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaPostIt_GetRequestAction_Proxy( 
    IFsaPostIt * This,
    /* [out] */ FSA_REQUEST_ACTION *pRequestAction);


void __RPC_STUB IFsaPostIt_GetRequestAction_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaPostIt_GetRequestOffset_Proxy( 
    IFsaPostIt * This,
    /* [out] */ LONGLONG *pRequestOffset);


void __RPC_STUB IFsaPostIt_GetRequestOffset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaPostIt_GetRequestSize_Proxy( 
    IFsaPostIt * This,
    /* [out] */ LONGLONG *pRequestSize);


void __RPC_STUB IFsaPostIt_GetRequestSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaPostIt_GetResult_Proxy( 
    IFsaPostIt * This,
    /* [out] */ HRESULT *pHr);


void __RPC_STUB IFsaPostIt_GetResult_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaPostIt_GetResultAction_Proxy( 
    IFsaPostIt * This,
    /* [out] */ FSA_RESULT_ACTION *pResultAction);


void __RPC_STUB IFsaPostIt_GetResultAction_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaPostIt_GetSession_Proxy( 
    IFsaPostIt * This,
    /* [out] */ IHsmSession **ppSession);


void __RPC_STUB IFsaPostIt_GetSession_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaPostIt_GetStoragePoolId_Proxy( 
    IFsaPostIt * This,
    /* [out] */ GUID *pStoragePoolId);


void __RPC_STUB IFsaPostIt_GetStoragePoolId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaPostIt_GetUSN_Proxy( 
    IFsaPostIt * This,
    /* [out] */ LONGLONG *pUsn);


void __RPC_STUB IFsaPostIt_GetUSN_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaPostIt_GetThreadId_Proxy( 
    IFsaPostIt * This,
    /* [out] */ DWORD *pThreadId);


void __RPC_STUB IFsaPostIt_GetThreadId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaPostIt_SetFileVersionId_Proxy( 
    IFsaPostIt * This,
    /* [in] */ LONGLONG fileVersionId);


void __RPC_STUB IFsaPostIt_SetFileVersionId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaPostIt_SetFilterRecall_Proxy( 
    IFsaPostIt * This,
    /* [in] */ IFsaFilterRecall *pRecall);


void __RPC_STUB IFsaPostIt_SetFilterRecall_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaPostIt_SetMode_Proxy( 
    IFsaPostIt * This,
    /* [in] */ ULONG mode);


void __RPC_STUB IFsaPostIt_SetMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaPostIt_SetPath_Proxy( 
    IFsaPostIt * This,
    /* [string][in] */ OLECHAR *path);


void __RPC_STUB IFsaPostIt_SetPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaPostIt_SetPlaceholder_Proxy( 
    IFsaPostIt * This,
    /* [in] */ FSA_PLACEHOLDER *pPlaceholder);


void __RPC_STUB IFsaPostIt_SetPlaceholder_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaPostIt_SetRequestAction_Proxy( 
    IFsaPostIt * This,
    /* [in] */ FSA_REQUEST_ACTION requestAction);


void __RPC_STUB IFsaPostIt_SetRequestAction_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaPostIt_SetRequestOffset_Proxy( 
    IFsaPostIt * This,
    /* [in] */ LONGLONG requestOffset);


void __RPC_STUB IFsaPostIt_SetRequestOffset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaPostIt_SetRequestSize_Proxy( 
    IFsaPostIt * This,
    /* [in] */ LONGLONG requestSize);


void __RPC_STUB IFsaPostIt_SetRequestSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaPostIt_SetResult_Proxy( 
    IFsaPostIt * This,
    /* [in] */ HRESULT hr);


void __RPC_STUB IFsaPostIt_SetResult_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaPostIt_SetResultAction_Proxy( 
    IFsaPostIt * This,
    /* [in] */ FSA_RESULT_ACTION pResultAction);


void __RPC_STUB IFsaPostIt_SetResultAction_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaPostIt_SetSession_Proxy( 
    IFsaPostIt * This,
    /* [in] */ IHsmSession *pSession);


void __RPC_STUB IFsaPostIt_SetSession_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaPostIt_SetStoragePoolId_Proxy( 
    IFsaPostIt * This,
    /* [in] */ GUID storagePoolId);


void __RPC_STUB IFsaPostIt_SetStoragePoolId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaPostIt_SetUSN_Proxy( 
    IFsaPostIt * This,
    /* [in] */ LONGLONG usn);


void __RPC_STUB IFsaPostIt_SetUSN_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaPostIt_SetThreadId_Proxy( 
    IFsaPostIt * This,
    /* [in] */ DWORD threadId);


void __RPC_STUB IFsaPostIt_SetThreadId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IFsaPostIt_INTERFACE_DEFINED__ */


#ifndef __IFsaRecallNotifyClient_INTERFACE_DEFINED__
#define __IFsaRecallNotifyClient_INTERFACE_DEFINED__

/* interface IFsaRecallNotifyClient */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IFsaRecallNotifyClient;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D68BD5B1-D6AA-11d0-9EDA-00A02488FCDE")
    IFsaRecallNotifyClient : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE IdentifyWithServer( 
            /* [string][in] */ OLECHAR *szServerName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnRecallStarted( 
            /* [in] */ IFsaRecallNotifyServer *pRecall) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OnRecallFinished( 
            /* [in] */ IFsaRecallNotifyServer *pRecall,
            /* [in] */ HRESULT hr) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFsaRecallNotifyClientVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFsaRecallNotifyClient * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFsaRecallNotifyClient * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFsaRecallNotifyClient * This);
        
        HRESULT ( STDMETHODCALLTYPE *IdentifyWithServer )( 
            IFsaRecallNotifyClient * This,
            /* [string][in] */ OLECHAR *szServerName);
        
        HRESULT ( STDMETHODCALLTYPE *OnRecallStarted )( 
            IFsaRecallNotifyClient * This,
            /* [in] */ IFsaRecallNotifyServer *pRecall);
        
        HRESULT ( STDMETHODCALLTYPE *OnRecallFinished )( 
            IFsaRecallNotifyClient * This,
            /* [in] */ IFsaRecallNotifyServer *pRecall,
            /* [in] */ HRESULT hr);
        
        END_INTERFACE
    } IFsaRecallNotifyClientVtbl;

    interface IFsaRecallNotifyClient
    {
        CONST_VTBL struct IFsaRecallNotifyClientVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFsaRecallNotifyClient_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFsaRecallNotifyClient_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFsaRecallNotifyClient_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFsaRecallNotifyClient_IdentifyWithServer(This,szServerName)	\
    (This)->lpVtbl -> IdentifyWithServer(This,szServerName)

#define IFsaRecallNotifyClient_OnRecallStarted(This,pRecall)	\
    (This)->lpVtbl -> OnRecallStarted(This,pRecall)

#define IFsaRecallNotifyClient_OnRecallFinished(This,pRecall,hr)	\
    (This)->lpVtbl -> OnRecallFinished(This,pRecall,hr)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IFsaRecallNotifyClient_IdentifyWithServer_Proxy( 
    IFsaRecallNotifyClient * This,
    /* [string][in] */ OLECHAR *szServerName);


void __RPC_STUB IFsaRecallNotifyClient_IdentifyWithServer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaRecallNotifyClient_OnRecallStarted_Proxy( 
    IFsaRecallNotifyClient * This,
    /* [in] */ IFsaRecallNotifyServer *pRecall);


void __RPC_STUB IFsaRecallNotifyClient_OnRecallStarted_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaRecallNotifyClient_OnRecallFinished_Proxy( 
    IFsaRecallNotifyClient * This,
    /* [in] */ IFsaRecallNotifyServer *pRecall,
    /* [in] */ HRESULT hr);


void __RPC_STUB IFsaRecallNotifyClient_OnRecallFinished_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IFsaRecallNotifyClient_INTERFACE_DEFINED__ */


#ifndef __IFsaRecallNotifyServer_INTERFACE_DEFINED__
#define __IFsaRecallNotifyServer_INTERFACE_DEFINED__

/* interface IFsaRecallNotifyServer */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IFsaRecallNotifyServer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D68BD5B2-D6AA-11d0-9EDA-00A02488FCDE")
    IFsaRecallNotifyServer : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Init( 
            /* [in] */ IFsaFilterRecall *pRecall) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Cancel( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIdentifier( 
            /* [out] */ GUID *pId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMode( 
            /* [out] */ ULONG *pMode) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOffset( 
            /* [out] */ LONGLONG *pOffset) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPath( 
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecallFlags( 
            /* [out] */ ULONG *recallFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSize( 
            /* [out] */ LONGLONG *pSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetState( 
            /* [out] */ HSM_JOB_STATE *pState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUserName( 
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WasCancelled( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFsaRecallNotifyServerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFsaRecallNotifyServer * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFsaRecallNotifyServer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFsaRecallNotifyServer * This);
        
        HRESULT ( STDMETHODCALLTYPE *Init )( 
            IFsaRecallNotifyServer * This,
            /* [in] */ IFsaFilterRecall *pRecall);
        
        HRESULT ( STDMETHODCALLTYPE *Cancel )( 
            IFsaRecallNotifyServer * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetIdentifier )( 
            IFsaRecallNotifyServer * This,
            /* [out] */ GUID *pId);
        
        HRESULT ( STDMETHODCALLTYPE *GetMode )( 
            IFsaRecallNotifyServer * This,
            /* [out] */ ULONG *pMode);
        
        HRESULT ( STDMETHODCALLTYPE *GetOffset )( 
            IFsaRecallNotifyServer * This,
            /* [out] */ LONGLONG *pOffset);
        
        HRESULT ( STDMETHODCALLTYPE *GetPath )( 
            IFsaRecallNotifyServer * This,
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetRecallFlags )( 
            IFsaRecallNotifyServer * This,
            /* [out] */ ULONG *recallFlags);
        
        HRESULT ( STDMETHODCALLTYPE *GetSize )( 
            IFsaRecallNotifyServer * This,
            /* [out] */ LONGLONG *pSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetState )( 
            IFsaRecallNotifyServer * This,
            /* [out] */ HSM_JOB_STATE *pState);
        
        HRESULT ( STDMETHODCALLTYPE *GetUserName )( 
            IFsaRecallNotifyServer * This,
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *WasCancelled )( 
            IFsaRecallNotifyServer * This);
        
        END_INTERFACE
    } IFsaRecallNotifyServerVtbl;

    interface IFsaRecallNotifyServer
    {
        CONST_VTBL struct IFsaRecallNotifyServerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFsaRecallNotifyServer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFsaRecallNotifyServer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFsaRecallNotifyServer_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFsaRecallNotifyServer_Init(This,pRecall)	\
    (This)->lpVtbl -> Init(This,pRecall)

#define IFsaRecallNotifyServer_Cancel(This)	\
    (This)->lpVtbl -> Cancel(This)

#define IFsaRecallNotifyServer_GetIdentifier(This,pId)	\
    (This)->lpVtbl -> GetIdentifier(This,pId)

#define IFsaRecallNotifyServer_GetMode(This,pMode)	\
    (This)->lpVtbl -> GetMode(This,pMode)

#define IFsaRecallNotifyServer_GetOffset(This,pOffset)	\
    (This)->lpVtbl -> GetOffset(This,pOffset)

#define IFsaRecallNotifyServer_GetPath(This,pName,bufferSize)	\
    (This)->lpVtbl -> GetPath(This,pName,bufferSize)

#define IFsaRecallNotifyServer_GetRecallFlags(This,recallFlags)	\
    (This)->lpVtbl -> GetRecallFlags(This,recallFlags)

#define IFsaRecallNotifyServer_GetSize(This,pSize)	\
    (This)->lpVtbl -> GetSize(This,pSize)

#define IFsaRecallNotifyServer_GetState(This,pState)	\
    (This)->lpVtbl -> GetState(This,pState)

#define IFsaRecallNotifyServer_GetUserName(This,pName,bufferSize)	\
    (This)->lpVtbl -> GetUserName(This,pName,bufferSize)

#define IFsaRecallNotifyServer_WasCancelled(This)	\
    (This)->lpVtbl -> WasCancelled(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IFsaRecallNotifyServer_Init_Proxy( 
    IFsaRecallNotifyServer * This,
    /* [in] */ IFsaFilterRecall *pRecall);


void __RPC_STUB IFsaRecallNotifyServer_Init_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaRecallNotifyServer_Cancel_Proxy( 
    IFsaRecallNotifyServer * This);


void __RPC_STUB IFsaRecallNotifyServer_Cancel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaRecallNotifyServer_GetIdentifier_Proxy( 
    IFsaRecallNotifyServer * This,
    /* [out] */ GUID *pId);


void __RPC_STUB IFsaRecallNotifyServer_GetIdentifier_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaRecallNotifyServer_GetMode_Proxy( 
    IFsaRecallNotifyServer * This,
    /* [out] */ ULONG *pMode);


void __RPC_STUB IFsaRecallNotifyServer_GetMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaRecallNotifyServer_GetOffset_Proxy( 
    IFsaRecallNotifyServer * This,
    /* [out] */ LONGLONG *pOffset);


void __RPC_STUB IFsaRecallNotifyServer_GetOffset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaRecallNotifyServer_GetPath_Proxy( 
    IFsaRecallNotifyServer * This,
    /* [string][out][in] */ OLECHAR **pName,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IFsaRecallNotifyServer_GetPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaRecallNotifyServer_GetRecallFlags_Proxy( 
    IFsaRecallNotifyServer * This,
    /* [out] */ ULONG *recallFlags);


void __RPC_STUB IFsaRecallNotifyServer_GetRecallFlags_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaRecallNotifyServer_GetSize_Proxy( 
    IFsaRecallNotifyServer * This,
    /* [out] */ LONGLONG *pSize);


void __RPC_STUB IFsaRecallNotifyServer_GetSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaRecallNotifyServer_GetState_Proxy( 
    IFsaRecallNotifyServer * This,
    /* [out] */ HSM_JOB_STATE *pState);


void __RPC_STUB IFsaRecallNotifyServer_GetState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaRecallNotifyServer_GetUserName_Proxy( 
    IFsaRecallNotifyServer * This,
    /* [string][out][in] */ OLECHAR **pName,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IFsaRecallNotifyServer_GetUserName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaRecallNotifyServer_WasCancelled_Proxy( 
    IFsaRecallNotifyServer * This);


void __RPC_STUB IFsaRecallNotifyServer_WasCancelled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IFsaRecallNotifyServer_INTERFACE_DEFINED__ */


#ifndef __IFsaRecallNotifySend_INTERFACE_DEFINED__
#define __IFsaRecallNotifySend_INTERFACE_DEFINED__

/* interface IFsaRecallNotifySend */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IFsaRecallNotifySend;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("931AC085-F98C-4595-92C0-706ED3DFA6D7")
    IFsaRecallNotifySend : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SendNotification( 
            /* [unique][string][in] */ OLECHAR *machineName,
            /* [in] */ BOOL started,
            /* [in] */ HRESULT rHr) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFsaRecallNotifySendVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFsaRecallNotifySend * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFsaRecallNotifySend * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFsaRecallNotifySend * This);
        
        HRESULT ( STDMETHODCALLTYPE *SendNotification )( 
            IFsaRecallNotifySend * This,
            /* [unique][string][in] */ OLECHAR *machineName,
            /* [in] */ BOOL started,
            /* [in] */ HRESULT rHr);
        
        END_INTERFACE
    } IFsaRecallNotifySendVtbl;

    interface IFsaRecallNotifySend
    {
        CONST_VTBL struct IFsaRecallNotifySendVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFsaRecallNotifySend_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFsaRecallNotifySend_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFsaRecallNotifySend_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFsaRecallNotifySend_SendNotification(This,machineName,started,rHr)	\
    (This)->lpVtbl -> SendNotification(This,machineName,started,rHr)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IFsaRecallNotifySend_SendNotification_Proxy( 
    IFsaRecallNotifySend * This,
    /* [unique][string][in] */ OLECHAR *machineName,
    /* [in] */ BOOL started,
    /* [in] */ HRESULT rHr);


void __RPC_STUB IFsaRecallNotifySend_SendNotification_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IFsaRecallNotifySend_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


