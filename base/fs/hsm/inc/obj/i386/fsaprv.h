

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for fsaprv.idl:
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

#ifndef __fsaprv_h__
#define __fsaprv_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IFsaFilterPriv_FWD_DEFINED__
#define __IFsaFilterPriv_FWD_DEFINED__
typedef interface IFsaFilterPriv IFsaFilterPriv;
#endif 	/* __IFsaFilterPriv_FWD_DEFINED__ */


#ifndef __IFsaFilterRecallPriv_FWD_DEFINED__
#define __IFsaFilterRecallPriv_FWD_DEFINED__
typedef interface IFsaFilterRecallPriv IFsaFilterRecallPriv;
#endif 	/* __IFsaFilterRecallPriv_FWD_DEFINED__ */


#ifndef __IFsaResourcePriv_FWD_DEFINED__
#define __IFsaResourcePriv_FWD_DEFINED__
typedef interface IFsaResourcePriv IFsaResourcePriv;
#endif 	/* __IFsaResourcePriv_FWD_DEFINED__ */


#ifndef __IFsaScanItemPriv_FWD_DEFINED__
#define __IFsaScanItemPriv_FWD_DEFINED__
typedef interface IFsaScanItemPriv IFsaScanItemPriv;
#endif 	/* __IFsaScanItemPriv_FWD_DEFINED__ */


#ifndef __IFsaPremigratedDb_FWD_DEFINED__
#define __IFsaPremigratedDb_FWD_DEFINED__
typedef interface IFsaPremigratedDb IFsaPremigratedDb;
#endif 	/* __IFsaPremigratedDb_FWD_DEFINED__ */


#ifndef __IFsaPremigratedRec_FWD_DEFINED__
#define __IFsaPremigratedRec_FWD_DEFINED__
typedef interface IFsaPremigratedRec IFsaPremigratedRec;
#endif 	/* __IFsaPremigratedRec_FWD_DEFINED__ */


#ifndef __IFsaRecoveryRec_FWD_DEFINED__
#define __IFsaRecoveryRec_FWD_DEFINED__
typedef interface IFsaRecoveryRec IFsaRecoveryRec;
#endif 	/* __IFsaRecoveryRec_FWD_DEFINED__ */


#ifndef __IFsaUnmanageDb_FWD_DEFINED__
#define __IFsaUnmanageDb_FWD_DEFINED__
typedef interface IFsaUnmanageDb IFsaUnmanageDb;
#endif 	/* __IFsaUnmanageDb_FWD_DEFINED__ */


#ifndef __IFsaUnmanageRec_FWD_DEFINED__
#define __IFsaUnmanageRec_FWD_DEFINED__
typedef interface IFsaUnmanageRec IFsaUnmanageRec;
#endif 	/* __IFsaUnmanageRec_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "fsaint.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

/* interface __MIDL_itf_fsaprv_0000 */
/* [local] */ 







extern RPC_IF_HANDLE __MIDL_itf_fsaprv_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_fsaprv_0000_v0_0_s_ifspec;

#ifndef __IFsaFilterPriv_INTERFACE_DEFINED__
#define __IFsaFilterPriv_INTERFACE_DEFINED__

/* interface IFsaFilterPriv */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IFsaFilterPriv;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3DEFB163-BAEC-11d2-9EE9-00104B226B3E")
    IFsaFilterPriv : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Init( 
            /* [in] */ IFsaServer *pServer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetIdentifier( 
            /* [in] */ GUID id) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IoctlThread( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE PipeThread( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SendCancel( 
            /* [in] */ IFsaFilterRecallPriv *pRecallPriv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SendComplete( 
            /* [in] */ IFsaFilterRecallPriv *recall,
            /* [in] */ HRESULT result) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFsaFilterPrivVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFsaFilterPriv * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFsaFilterPriv * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFsaFilterPriv * This);
        
        HRESULT ( STDMETHODCALLTYPE *Init )( 
            IFsaFilterPriv * This,
            /* [in] */ IFsaServer *pServer);
        
        HRESULT ( STDMETHODCALLTYPE *SetIdentifier )( 
            IFsaFilterPriv * This,
            /* [in] */ GUID id);
        
        HRESULT ( STDMETHODCALLTYPE *IoctlThread )( 
            IFsaFilterPriv * This);
        
        HRESULT ( STDMETHODCALLTYPE *PipeThread )( 
            IFsaFilterPriv * This);
        
        HRESULT ( STDMETHODCALLTYPE *SendCancel )( 
            IFsaFilterPriv * This,
            /* [in] */ IFsaFilterRecallPriv *pRecallPriv);
        
        HRESULT ( STDMETHODCALLTYPE *SendComplete )( 
            IFsaFilterPriv * This,
            /* [in] */ IFsaFilterRecallPriv *recall,
            /* [in] */ HRESULT result);
        
        END_INTERFACE
    } IFsaFilterPrivVtbl;

    interface IFsaFilterPriv
    {
        CONST_VTBL struct IFsaFilterPrivVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFsaFilterPriv_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFsaFilterPriv_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFsaFilterPriv_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFsaFilterPriv_Init(This,pServer)	\
    (This)->lpVtbl -> Init(This,pServer)

#define IFsaFilterPriv_SetIdentifier(This,id)	\
    (This)->lpVtbl -> SetIdentifier(This,id)

#define IFsaFilterPriv_IoctlThread(This)	\
    (This)->lpVtbl -> IoctlThread(This)

#define IFsaFilterPriv_PipeThread(This)	\
    (This)->lpVtbl -> PipeThread(This)

#define IFsaFilterPriv_SendCancel(This,pRecallPriv)	\
    (This)->lpVtbl -> SendCancel(This,pRecallPriv)

#define IFsaFilterPriv_SendComplete(This,recall,result)	\
    (This)->lpVtbl -> SendComplete(This,recall,result)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IFsaFilterPriv_Init_Proxy( 
    IFsaFilterPriv * This,
    /* [in] */ IFsaServer *pServer);


void __RPC_STUB IFsaFilterPriv_Init_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterPriv_SetIdentifier_Proxy( 
    IFsaFilterPriv * This,
    /* [in] */ GUID id);


void __RPC_STUB IFsaFilterPriv_SetIdentifier_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterPriv_IoctlThread_Proxy( 
    IFsaFilterPriv * This);


void __RPC_STUB IFsaFilterPriv_IoctlThread_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterPriv_PipeThread_Proxy( 
    IFsaFilterPriv * This);


void __RPC_STUB IFsaFilterPriv_PipeThread_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterPriv_SendCancel_Proxy( 
    IFsaFilterPriv * This,
    /* [in] */ IFsaFilterRecallPriv *pRecallPriv);


void __RPC_STUB IFsaFilterPriv_SendCancel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterPriv_SendComplete_Proxy( 
    IFsaFilterPriv * This,
    /* [in] */ IFsaFilterRecallPriv *recall,
    /* [in] */ HRESULT result);


void __RPC_STUB IFsaFilterPriv_SendComplete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IFsaFilterPriv_INTERFACE_DEFINED__ */


#ifndef __IFsaFilterRecallPriv_INTERFACE_DEFINED__
#define __IFsaFilterRecallPriv_INTERFACE_DEFINED__

/* interface IFsaFilterRecallPriv */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IFsaFilterRecallPriv;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("23A05997-DA21-4998-A354-8797303FB91E")
    IFsaFilterRecallPriv : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Cancel( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CancelByDriver( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Delete( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetClient( 
            /* [out] */ IFsaFilterClient **ppClient) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDriversRecallId( 
            /* [out] */ ULONGLONG *pId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDriversRecallId( 
            /* [in] */ ULONGLONG pId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetThreadId( 
            /* [in] */ DWORD pId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPlaceholder( 
            /* [out] */ FSA_PLACEHOLDER *pPlaceholder) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Init( 
            /* [in] */ IFsaFilterClient *pClient,
            /* [in] */ ULONGLONG pDriversRecallId,
            /* [in] */ IFsaResource *pResource,
            /* [string][in] */ OLECHAR *path,
            /* [in] */ LONGLONG fileId,
            /* [in] */ LONGLONG offset,
            /* [in] */ LONGLONG size,
            /* [in] */ ULONG mode,
            /* [in] */ FSA_PLACEHOLDER *pPlaceholder,
            /* [in] */ IFsaFilterPriv *pFilterPriv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetIdentifier( 
            /* [in] */ GUID id) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StartRecall( 
            /* [in] */ ULONGLONG offset,
            /* [in] */ ULONGLONG size) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStream( 
            /* [out] */ IStream **ppStream) = 0;
        
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
        
        virtual HRESULT STDMETHODCALLTYPE GetSession( 
            /* [out] */ IHsmSession **ppSession) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSize( 
            /* [out] */ LONGLONG *pSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetState( 
            /* [out] */ HSM_JOB_STATE *pState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUserName( 
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WasCancelled( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LogComplete( 
            /* [in] */ HRESULT hr) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFsaFilterRecallPrivVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFsaFilterRecallPriv * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFsaFilterRecallPriv * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFsaFilterRecallPriv * This);
        
        HRESULT ( STDMETHODCALLTYPE *Cancel )( 
            IFsaFilterRecallPriv * This);
        
        HRESULT ( STDMETHODCALLTYPE *CancelByDriver )( 
            IFsaFilterRecallPriv * This);
        
        HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IFsaFilterRecallPriv * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetClient )( 
            IFsaFilterRecallPriv * This,
            /* [out] */ IFsaFilterClient **ppClient);
        
        HRESULT ( STDMETHODCALLTYPE *GetDriversRecallId )( 
            IFsaFilterRecallPriv * This,
            /* [out] */ ULONGLONG *pId);
        
        HRESULT ( STDMETHODCALLTYPE *SetDriversRecallId )( 
            IFsaFilterRecallPriv * This,
            /* [in] */ ULONGLONG pId);
        
        HRESULT ( STDMETHODCALLTYPE *SetThreadId )( 
            IFsaFilterRecallPriv * This,
            /* [in] */ DWORD pId);
        
        HRESULT ( STDMETHODCALLTYPE *GetPlaceholder )( 
            IFsaFilterRecallPriv * This,
            /* [out] */ FSA_PLACEHOLDER *pPlaceholder);
        
        HRESULT ( STDMETHODCALLTYPE *Init )( 
            IFsaFilterRecallPriv * This,
            /* [in] */ IFsaFilterClient *pClient,
            /* [in] */ ULONGLONG pDriversRecallId,
            /* [in] */ IFsaResource *pResource,
            /* [string][in] */ OLECHAR *path,
            /* [in] */ LONGLONG fileId,
            /* [in] */ LONGLONG offset,
            /* [in] */ LONGLONG size,
            /* [in] */ ULONG mode,
            /* [in] */ FSA_PLACEHOLDER *pPlaceholder,
            /* [in] */ IFsaFilterPriv *pFilterPriv);
        
        HRESULT ( STDMETHODCALLTYPE *SetIdentifier )( 
            IFsaFilterRecallPriv * This,
            /* [in] */ GUID id);
        
        HRESULT ( STDMETHODCALLTYPE *StartRecall )( 
            IFsaFilterRecallPriv * This,
            /* [in] */ ULONGLONG offset,
            /* [in] */ ULONGLONG size);
        
        HRESULT ( STDMETHODCALLTYPE *GetStream )( 
            IFsaFilterRecallPriv * This,
            /* [out] */ IStream **ppStream);
        
        HRESULT ( STDMETHODCALLTYPE *CompareToIdentifier )( 
            IFsaFilterRecallPriv * This,
            /* [in] */ GUID id,
            /* [out] */ SHORT *pResult);
        
        HRESULT ( STDMETHODCALLTYPE *CompareToIRecall )( 
            IFsaFilterRecallPriv * This,
            /* [in] */ IFsaFilterRecall *pRecall,
            /* [out] */ SHORT *pResult);
        
        HRESULT ( STDMETHODCALLTYPE *CompareToDriversRecallId )( 
            IFsaFilterRecallPriv * This,
            /* [in] */ ULONGLONG id,
            /* [out] */ SHORT *pResult);
        
        HRESULT ( STDMETHODCALLTYPE *CompareToDriversContextId )( 
            IFsaFilterRecallPriv * This,
            /* [in] */ ULONGLONG id,
            /* [out] */ SHORT *pResult);
        
        HRESULT ( STDMETHODCALLTYPE *CompareBy )( 
            IFsaFilterRecallPriv * This,
            /* [in] */ FSA_RECALL_COMPARE by);
        
        HRESULT ( STDMETHODCALLTYPE *GetIdentifier )( 
            IFsaFilterRecallPriv * This,
            /* [out] */ GUID *pId);
        
        HRESULT ( STDMETHODCALLTYPE *GetMode )( 
            IFsaFilterRecallPriv * This,
            /* [out] */ ULONG *pMode);
        
        HRESULT ( STDMETHODCALLTYPE *GetOffset )( 
            IFsaFilterRecallPriv * This,
            /* [out] */ LONGLONG *pOffset);
        
        HRESULT ( STDMETHODCALLTYPE *GetPath )( 
            IFsaFilterRecallPriv * This,
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetResource )( 
            IFsaFilterRecallPriv * This,
            /* [out] */ IFsaResource **ppResource);
        
        HRESULT ( STDMETHODCALLTYPE *GetSession )( 
            IFsaFilterRecallPriv * This,
            /* [out] */ IHsmSession **ppSession);
        
        HRESULT ( STDMETHODCALLTYPE *GetSize )( 
            IFsaFilterRecallPriv * This,
            /* [out] */ LONGLONG *pSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetState )( 
            IFsaFilterRecallPriv * This,
            /* [out] */ HSM_JOB_STATE *pState);
        
        HRESULT ( STDMETHODCALLTYPE *GetUserName )( 
            IFsaFilterRecallPriv * This,
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *WasCancelled )( 
            IFsaFilterRecallPriv * This);
        
        HRESULT ( STDMETHODCALLTYPE *LogComplete )( 
            IFsaFilterRecallPriv * This,
            /* [in] */ HRESULT hr);
        
        END_INTERFACE
    } IFsaFilterRecallPrivVtbl;

    interface IFsaFilterRecallPriv
    {
        CONST_VTBL struct IFsaFilterRecallPrivVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFsaFilterRecallPriv_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFsaFilterRecallPriv_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFsaFilterRecallPriv_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFsaFilterRecallPriv_Cancel(This)	\
    (This)->lpVtbl -> Cancel(This)

#define IFsaFilterRecallPriv_CancelByDriver(This)	\
    (This)->lpVtbl -> CancelByDriver(This)

#define IFsaFilterRecallPriv_Delete(This)	\
    (This)->lpVtbl -> Delete(This)

#define IFsaFilterRecallPriv_GetClient(This,ppClient)	\
    (This)->lpVtbl -> GetClient(This,ppClient)

#define IFsaFilterRecallPriv_GetDriversRecallId(This,pId)	\
    (This)->lpVtbl -> GetDriversRecallId(This,pId)

#define IFsaFilterRecallPriv_SetDriversRecallId(This,pId)	\
    (This)->lpVtbl -> SetDriversRecallId(This,pId)

#define IFsaFilterRecallPriv_SetThreadId(This,pId)	\
    (This)->lpVtbl -> SetThreadId(This,pId)

#define IFsaFilterRecallPriv_GetPlaceholder(This,pPlaceholder)	\
    (This)->lpVtbl -> GetPlaceholder(This,pPlaceholder)

#define IFsaFilterRecallPriv_Init(This,pClient,pDriversRecallId,pResource,path,fileId,offset,size,mode,pPlaceholder,pFilterPriv)	\
    (This)->lpVtbl -> Init(This,pClient,pDriversRecallId,pResource,path,fileId,offset,size,mode,pPlaceholder,pFilterPriv)

#define IFsaFilterRecallPriv_SetIdentifier(This,id)	\
    (This)->lpVtbl -> SetIdentifier(This,id)

#define IFsaFilterRecallPriv_StartRecall(This,offset,size)	\
    (This)->lpVtbl -> StartRecall(This,offset,size)

#define IFsaFilterRecallPriv_GetStream(This,ppStream)	\
    (This)->lpVtbl -> GetStream(This,ppStream)

#define IFsaFilterRecallPriv_CompareToIdentifier(This,id,pResult)	\
    (This)->lpVtbl -> CompareToIdentifier(This,id,pResult)

#define IFsaFilterRecallPriv_CompareToIRecall(This,pRecall,pResult)	\
    (This)->lpVtbl -> CompareToIRecall(This,pRecall,pResult)

#define IFsaFilterRecallPriv_CompareToDriversRecallId(This,id,pResult)	\
    (This)->lpVtbl -> CompareToDriversRecallId(This,id,pResult)

#define IFsaFilterRecallPriv_CompareToDriversContextId(This,id,pResult)	\
    (This)->lpVtbl -> CompareToDriversContextId(This,id,pResult)

#define IFsaFilterRecallPriv_CompareBy(This,by)	\
    (This)->lpVtbl -> CompareBy(This,by)

#define IFsaFilterRecallPriv_GetIdentifier(This,pId)	\
    (This)->lpVtbl -> GetIdentifier(This,pId)

#define IFsaFilterRecallPriv_GetMode(This,pMode)	\
    (This)->lpVtbl -> GetMode(This,pMode)

#define IFsaFilterRecallPriv_GetOffset(This,pOffset)	\
    (This)->lpVtbl -> GetOffset(This,pOffset)

#define IFsaFilterRecallPriv_GetPath(This,pName,bufferSize)	\
    (This)->lpVtbl -> GetPath(This,pName,bufferSize)

#define IFsaFilterRecallPriv_GetResource(This,ppResource)	\
    (This)->lpVtbl -> GetResource(This,ppResource)

#define IFsaFilterRecallPriv_GetSession(This,ppSession)	\
    (This)->lpVtbl -> GetSession(This,ppSession)

#define IFsaFilterRecallPriv_GetSize(This,pSize)	\
    (This)->lpVtbl -> GetSize(This,pSize)

#define IFsaFilterRecallPriv_GetState(This,pState)	\
    (This)->lpVtbl -> GetState(This,pState)

#define IFsaFilterRecallPriv_GetUserName(This,pName,bufferSize)	\
    (This)->lpVtbl -> GetUserName(This,pName,bufferSize)

#define IFsaFilterRecallPriv_WasCancelled(This)	\
    (This)->lpVtbl -> WasCancelled(This)

#define IFsaFilterRecallPriv_LogComplete(This,hr)	\
    (This)->lpVtbl -> LogComplete(This,hr)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IFsaFilterRecallPriv_Cancel_Proxy( 
    IFsaFilterRecallPriv * This);


void __RPC_STUB IFsaFilterRecallPriv_Cancel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterRecallPriv_CancelByDriver_Proxy( 
    IFsaFilterRecallPriv * This);


void __RPC_STUB IFsaFilterRecallPriv_CancelByDriver_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterRecallPriv_Delete_Proxy( 
    IFsaFilterRecallPriv * This);


void __RPC_STUB IFsaFilterRecallPriv_Delete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterRecallPriv_GetClient_Proxy( 
    IFsaFilterRecallPriv * This,
    /* [out] */ IFsaFilterClient **ppClient);


void __RPC_STUB IFsaFilterRecallPriv_GetClient_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterRecallPriv_GetDriversRecallId_Proxy( 
    IFsaFilterRecallPriv * This,
    /* [out] */ ULONGLONG *pId);


void __RPC_STUB IFsaFilterRecallPriv_GetDriversRecallId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterRecallPriv_SetDriversRecallId_Proxy( 
    IFsaFilterRecallPriv * This,
    /* [in] */ ULONGLONG pId);


void __RPC_STUB IFsaFilterRecallPriv_SetDriversRecallId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterRecallPriv_SetThreadId_Proxy( 
    IFsaFilterRecallPriv * This,
    /* [in] */ DWORD pId);


void __RPC_STUB IFsaFilterRecallPriv_SetThreadId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterRecallPriv_GetPlaceholder_Proxy( 
    IFsaFilterRecallPriv * This,
    /* [out] */ FSA_PLACEHOLDER *pPlaceholder);


void __RPC_STUB IFsaFilterRecallPriv_GetPlaceholder_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterRecallPriv_Init_Proxy( 
    IFsaFilterRecallPriv * This,
    /* [in] */ IFsaFilterClient *pClient,
    /* [in] */ ULONGLONG pDriversRecallId,
    /* [in] */ IFsaResource *pResource,
    /* [string][in] */ OLECHAR *path,
    /* [in] */ LONGLONG fileId,
    /* [in] */ LONGLONG offset,
    /* [in] */ LONGLONG size,
    /* [in] */ ULONG mode,
    /* [in] */ FSA_PLACEHOLDER *pPlaceholder,
    /* [in] */ IFsaFilterPriv *pFilterPriv);


void __RPC_STUB IFsaFilterRecallPriv_Init_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterRecallPriv_SetIdentifier_Proxy( 
    IFsaFilterRecallPriv * This,
    /* [in] */ GUID id);


void __RPC_STUB IFsaFilterRecallPriv_SetIdentifier_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterRecallPriv_StartRecall_Proxy( 
    IFsaFilterRecallPriv * This,
    /* [in] */ ULONGLONG offset,
    /* [in] */ ULONGLONG size);


void __RPC_STUB IFsaFilterRecallPriv_StartRecall_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterRecallPriv_GetStream_Proxy( 
    IFsaFilterRecallPriv * This,
    /* [out] */ IStream **ppStream);


void __RPC_STUB IFsaFilterRecallPriv_GetStream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterRecallPriv_CompareToIdentifier_Proxy( 
    IFsaFilterRecallPriv * This,
    /* [in] */ GUID id,
    /* [out] */ SHORT *pResult);


void __RPC_STUB IFsaFilterRecallPriv_CompareToIdentifier_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterRecallPriv_CompareToIRecall_Proxy( 
    IFsaFilterRecallPriv * This,
    /* [in] */ IFsaFilterRecall *pRecall,
    /* [out] */ SHORT *pResult);


void __RPC_STUB IFsaFilterRecallPriv_CompareToIRecall_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterRecallPriv_CompareToDriversRecallId_Proxy( 
    IFsaFilterRecallPriv * This,
    /* [in] */ ULONGLONG id,
    /* [out] */ SHORT *pResult);


void __RPC_STUB IFsaFilterRecallPriv_CompareToDriversRecallId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterRecallPriv_CompareToDriversContextId_Proxy( 
    IFsaFilterRecallPriv * This,
    /* [in] */ ULONGLONG id,
    /* [out] */ SHORT *pResult);


void __RPC_STUB IFsaFilterRecallPriv_CompareToDriversContextId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterRecallPriv_CompareBy_Proxy( 
    IFsaFilterRecallPriv * This,
    /* [in] */ FSA_RECALL_COMPARE by);


void __RPC_STUB IFsaFilterRecallPriv_CompareBy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterRecallPriv_GetIdentifier_Proxy( 
    IFsaFilterRecallPriv * This,
    /* [out] */ GUID *pId);


void __RPC_STUB IFsaFilterRecallPriv_GetIdentifier_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterRecallPriv_GetMode_Proxy( 
    IFsaFilterRecallPriv * This,
    /* [out] */ ULONG *pMode);


void __RPC_STUB IFsaFilterRecallPriv_GetMode_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterRecallPriv_GetOffset_Proxy( 
    IFsaFilterRecallPriv * This,
    /* [out] */ LONGLONG *pOffset);


void __RPC_STUB IFsaFilterRecallPriv_GetOffset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterRecallPriv_GetPath_Proxy( 
    IFsaFilterRecallPriv * This,
    /* [string][out][in] */ OLECHAR **pName,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IFsaFilterRecallPriv_GetPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterRecallPriv_GetResource_Proxy( 
    IFsaFilterRecallPriv * This,
    /* [out] */ IFsaResource **ppResource);


void __RPC_STUB IFsaFilterRecallPriv_GetResource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterRecallPriv_GetSession_Proxy( 
    IFsaFilterRecallPriv * This,
    /* [out] */ IHsmSession **ppSession);


void __RPC_STUB IFsaFilterRecallPriv_GetSession_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterRecallPriv_GetSize_Proxy( 
    IFsaFilterRecallPriv * This,
    /* [out] */ LONGLONG *pSize);


void __RPC_STUB IFsaFilterRecallPriv_GetSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterRecallPriv_GetState_Proxy( 
    IFsaFilterRecallPriv * This,
    /* [out] */ HSM_JOB_STATE *pState);


void __RPC_STUB IFsaFilterRecallPriv_GetState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterRecallPriv_GetUserName_Proxy( 
    IFsaFilterRecallPriv * This,
    /* [string][out][in] */ OLECHAR **pName,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IFsaFilterRecallPriv_GetUserName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterRecallPriv_WasCancelled_Proxy( 
    IFsaFilterRecallPriv * This);


void __RPC_STUB IFsaFilterRecallPriv_WasCancelled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaFilterRecallPriv_LogComplete_Proxy( 
    IFsaFilterRecallPriv * This,
    /* [in] */ HRESULT hr);


void __RPC_STUB IFsaFilterRecallPriv_LogComplete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IFsaFilterRecallPriv_INTERFACE_DEFINED__ */


#ifndef __IFsaResourcePriv_INTERFACE_DEFINED__
#define __IFsaResourcePriv_INTERFACE_DEFINED__

/* interface IFsaResourcePriv */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IFsaResourcePriv;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BFAB9D53-4D27-4B22-BCEA-B83C29E7D509")
    IFsaResourcePriv : public IHsmSystemState
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AddPremigratedSize( 
            /* [in] */ LONGLONG size) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AddTruncatedSize( 
            /* [in] */ LONGLONG size) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DoRecovery( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FilterSawOpen( 
            /* [in] */ IHsmSession *pSession,
            /* [in] */ IFsaFilterRecall *pRecall,
            /* [string][in] */ OLECHAR *path,
            /* [in] */ LONGLONG fileId,
            /* [in] */ LONGLONG requestOffset,
            /* [in] */ LONGLONG requestSize,
            /* [in] */ FSA_PLACEHOLDER *pPlaceholder,
            /* [in] */ ULONG mode,
            /* [in] */ FSA_RESULT_ACTION resultAction,
            /* [in] */ DWORD threadId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FilterSawDelete( 
            /* [in] */ GUID filterId,
            /* [string][in] */ OLECHAR *path,
            /* [in] */ LONGLONG size,
            /* [in] */ FSA_PLACEHOLDER *pPlaceholder) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPremigrated( 
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppDb) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUnmanageDb( 
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppDb) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InitializeUnmanageDb( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE TerminateUnmanageDb( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Init( 
            /* [in] */ IFsaServer *pServer,
            /* [string][in] */ OLECHAR *path,
            /* [string][in] */ OLECHAR *dosname) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemovePremigratedSize( 
            /* [in] */ LONGLONG size) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveTruncatedSize( 
            /* [in] */ LONGLONG size) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAlternatePath( 
            /* [string][in] */ OLECHAR *path) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetIdentifier( 
            /* [in] */ GUID id) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetName( 
            /* [string][in] */ OLECHAR *name) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetOldPath( 
            /* [string][in] */ OLECHAR *oldPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPath( 
            /* [string][in] */ OLECHAR *path) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetUserFriendlyName( 
            /* [string][in] */ OLECHAR *path) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetStickyName( 
            /* [string][in] */ OLECHAR *path) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSerial( 
            /* [in] */ ULONG serial) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UpdateFrom( 
            /* [in] */ IFsaServer *pServer,
            /* [in] */ IFsaResource *pResource) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMaxFileLogicalSize( 
            /* [out] */ LONGLONG *pSize) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFsaResourcePrivVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFsaResourcePriv * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFsaResourcePriv * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFsaResourcePriv * This);
        
        HRESULT ( STDMETHODCALLTYPE *ChangeSysState )( 
            IFsaResourcePriv * This,
            /* [out][in] */ HSM_SYSTEM_STATE *pSysState);
        
        HRESULT ( STDMETHODCALLTYPE *AddPremigratedSize )( 
            IFsaResourcePriv * This,
            /* [in] */ LONGLONG size);
        
        HRESULT ( STDMETHODCALLTYPE *AddTruncatedSize )( 
            IFsaResourcePriv * This,
            /* [in] */ LONGLONG size);
        
        HRESULT ( STDMETHODCALLTYPE *DoRecovery )( 
            IFsaResourcePriv * This);
        
        HRESULT ( STDMETHODCALLTYPE *FilterSawOpen )( 
            IFsaResourcePriv * This,
            /* [in] */ IHsmSession *pSession,
            /* [in] */ IFsaFilterRecall *pRecall,
            /* [string][in] */ OLECHAR *path,
            /* [in] */ LONGLONG fileId,
            /* [in] */ LONGLONG requestOffset,
            /* [in] */ LONGLONG requestSize,
            /* [in] */ FSA_PLACEHOLDER *pPlaceholder,
            /* [in] */ ULONG mode,
            /* [in] */ FSA_RESULT_ACTION resultAction,
            /* [in] */ DWORD threadId);
        
        HRESULT ( STDMETHODCALLTYPE *FilterSawDelete )( 
            IFsaResourcePriv * This,
            /* [in] */ GUID filterId,
            /* [string][in] */ OLECHAR *path,
            /* [in] */ LONGLONG size,
            /* [in] */ FSA_PLACEHOLDER *pPlaceholder);
        
        HRESULT ( STDMETHODCALLTYPE *GetPremigrated )( 
            IFsaResourcePriv * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppDb);
        
        HRESULT ( STDMETHODCALLTYPE *GetUnmanageDb )( 
            IFsaResourcePriv * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppDb);
        
        HRESULT ( STDMETHODCALLTYPE *InitializeUnmanageDb )( 
            IFsaResourcePriv * This);
        
        HRESULT ( STDMETHODCALLTYPE *TerminateUnmanageDb )( 
            IFsaResourcePriv * This);
        
        HRESULT ( STDMETHODCALLTYPE *Init )( 
            IFsaResourcePriv * This,
            /* [in] */ IFsaServer *pServer,
            /* [string][in] */ OLECHAR *path,
            /* [string][in] */ OLECHAR *dosname);
        
        HRESULT ( STDMETHODCALLTYPE *RemovePremigratedSize )( 
            IFsaResourcePriv * This,
            /* [in] */ LONGLONG size);
        
        HRESULT ( STDMETHODCALLTYPE *RemoveTruncatedSize )( 
            IFsaResourcePriv * This,
            /* [in] */ LONGLONG size);
        
        HRESULT ( STDMETHODCALLTYPE *SetAlternatePath )( 
            IFsaResourcePriv * This,
            /* [string][in] */ OLECHAR *path);
        
        HRESULT ( STDMETHODCALLTYPE *SetIdentifier )( 
            IFsaResourcePriv * This,
            /* [in] */ GUID id);
        
        HRESULT ( STDMETHODCALLTYPE *SetName )( 
            IFsaResourcePriv * This,
            /* [string][in] */ OLECHAR *name);
        
        HRESULT ( STDMETHODCALLTYPE *SetOldPath )( 
            IFsaResourcePriv * This,
            /* [string][in] */ OLECHAR *oldPath);
        
        HRESULT ( STDMETHODCALLTYPE *SetPath )( 
            IFsaResourcePriv * This,
            /* [string][in] */ OLECHAR *path);
        
        HRESULT ( STDMETHODCALLTYPE *SetUserFriendlyName )( 
            IFsaResourcePriv * This,
            /* [string][in] */ OLECHAR *path);
        
        HRESULT ( STDMETHODCALLTYPE *SetStickyName )( 
            IFsaResourcePriv * This,
            /* [string][in] */ OLECHAR *path);
        
        HRESULT ( STDMETHODCALLTYPE *SetSerial )( 
            IFsaResourcePriv * This,
            /* [in] */ ULONG serial);
        
        HRESULT ( STDMETHODCALLTYPE *UpdateFrom )( 
            IFsaResourcePriv * This,
            /* [in] */ IFsaServer *pServer,
            /* [in] */ IFsaResource *pResource);
        
        HRESULT ( STDMETHODCALLTYPE *GetMaxFileLogicalSize )( 
            IFsaResourcePriv * This,
            /* [out] */ LONGLONG *pSize);
        
        END_INTERFACE
    } IFsaResourcePrivVtbl;

    interface IFsaResourcePriv
    {
        CONST_VTBL struct IFsaResourcePrivVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFsaResourcePriv_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFsaResourcePriv_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFsaResourcePriv_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFsaResourcePriv_ChangeSysState(This,pSysState)	\
    (This)->lpVtbl -> ChangeSysState(This,pSysState)


#define IFsaResourcePriv_AddPremigratedSize(This,size)	\
    (This)->lpVtbl -> AddPremigratedSize(This,size)

#define IFsaResourcePriv_AddTruncatedSize(This,size)	\
    (This)->lpVtbl -> AddTruncatedSize(This,size)

#define IFsaResourcePriv_DoRecovery(This)	\
    (This)->lpVtbl -> DoRecovery(This)

#define IFsaResourcePriv_FilterSawOpen(This,pSession,pRecall,path,fileId,requestOffset,requestSize,pPlaceholder,mode,resultAction,threadId)	\
    (This)->lpVtbl -> FilterSawOpen(This,pSession,pRecall,path,fileId,requestOffset,requestSize,pPlaceholder,mode,resultAction,threadId)

#define IFsaResourcePriv_FilterSawDelete(This,filterId,path,size,pPlaceholder)	\
    (This)->lpVtbl -> FilterSawDelete(This,filterId,path,size,pPlaceholder)

#define IFsaResourcePriv_GetPremigrated(This,riid,ppDb)	\
    (This)->lpVtbl -> GetPremigrated(This,riid,ppDb)

#define IFsaResourcePriv_GetUnmanageDb(This,riid,ppDb)	\
    (This)->lpVtbl -> GetUnmanageDb(This,riid,ppDb)

#define IFsaResourcePriv_InitializeUnmanageDb(This)	\
    (This)->lpVtbl -> InitializeUnmanageDb(This)

#define IFsaResourcePriv_TerminateUnmanageDb(This)	\
    (This)->lpVtbl -> TerminateUnmanageDb(This)

#define IFsaResourcePriv_Init(This,pServer,path,dosname)	\
    (This)->lpVtbl -> Init(This,pServer,path,dosname)

#define IFsaResourcePriv_RemovePremigratedSize(This,size)	\
    (This)->lpVtbl -> RemovePremigratedSize(This,size)

#define IFsaResourcePriv_RemoveTruncatedSize(This,size)	\
    (This)->lpVtbl -> RemoveTruncatedSize(This,size)

#define IFsaResourcePriv_SetAlternatePath(This,path)	\
    (This)->lpVtbl -> SetAlternatePath(This,path)

#define IFsaResourcePriv_SetIdentifier(This,id)	\
    (This)->lpVtbl -> SetIdentifier(This,id)

#define IFsaResourcePriv_SetName(This,name)	\
    (This)->lpVtbl -> SetName(This,name)

#define IFsaResourcePriv_SetOldPath(This,oldPath)	\
    (This)->lpVtbl -> SetOldPath(This,oldPath)

#define IFsaResourcePriv_SetPath(This,path)	\
    (This)->lpVtbl -> SetPath(This,path)

#define IFsaResourcePriv_SetUserFriendlyName(This,path)	\
    (This)->lpVtbl -> SetUserFriendlyName(This,path)

#define IFsaResourcePriv_SetStickyName(This,path)	\
    (This)->lpVtbl -> SetStickyName(This,path)

#define IFsaResourcePriv_SetSerial(This,serial)	\
    (This)->lpVtbl -> SetSerial(This,serial)

#define IFsaResourcePriv_UpdateFrom(This,pServer,pResource)	\
    (This)->lpVtbl -> UpdateFrom(This,pServer,pResource)

#define IFsaResourcePriv_GetMaxFileLogicalSize(This,pSize)	\
    (This)->lpVtbl -> GetMaxFileLogicalSize(This,pSize)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IFsaResourcePriv_AddPremigratedSize_Proxy( 
    IFsaResourcePriv * This,
    /* [in] */ LONGLONG size);


void __RPC_STUB IFsaResourcePriv_AddPremigratedSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResourcePriv_AddTruncatedSize_Proxy( 
    IFsaResourcePriv * This,
    /* [in] */ LONGLONG size);


void __RPC_STUB IFsaResourcePriv_AddTruncatedSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResourcePriv_DoRecovery_Proxy( 
    IFsaResourcePriv * This);


void __RPC_STUB IFsaResourcePriv_DoRecovery_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResourcePriv_FilterSawOpen_Proxy( 
    IFsaResourcePriv * This,
    /* [in] */ IHsmSession *pSession,
    /* [in] */ IFsaFilterRecall *pRecall,
    /* [string][in] */ OLECHAR *path,
    /* [in] */ LONGLONG fileId,
    /* [in] */ LONGLONG requestOffset,
    /* [in] */ LONGLONG requestSize,
    /* [in] */ FSA_PLACEHOLDER *pPlaceholder,
    /* [in] */ ULONG mode,
    /* [in] */ FSA_RESULT_ACTION resultAction,
    /* [in] */ DWORD threadId);


void __RPC_STUB IFsaResourcePriv_FilterSawOpen_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResourcePriv_FilterSawDelete_Proxy( 
    IFsaResourcePriv * This,
    /* [in] */ GUID filterId,
    /* [string][in] */ OLECHAR *path,
    /* [in] */ LONGLONG size,
    /* [in] */ FSA_PLACEHOLDER *pPlaceholder);


void __RPC_STUB IFsaResourcePriv_FilterSawDelete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResourcePriv_GetPremigrated_Proxy( 
    IFsaResourcePriv * This,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ void **ppDb);


void __RPC_STUB IFsaResourcePriv_GetPremigrated_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResourcePriv_GetUnmanageDb_Proxy( 
    IFsaResourcePriv * This,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ void **ppDb);


void __RPC_STUB IFsaResourcePriv_GetUnmanageDb_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResourcePriv_InitializeUnmanageDb_Proxy( 
    IFsaResourcePriv * This);


void __RPC_STUB IFsaResourcePriv_InitializeUnmanageDb_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResourcePriv_TerminateUnmanageDb_Proxy( 
    IFsaResourcePriv * This);


void __RPC_STUB IFsaResourcePriv_TerminateUnmanageDb_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResourcePriv_Init_Proxy( 
    IFsaResourcePriv * This,
    /* [in] */ IFsaServer *pServer,
    /* [string][in] */ OLECHAR *path,
    /* [string][in] */ OLECHAR *dosname);


void __RPC_STUB IFsaResourcePriv_Init_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResourcePriv_RemovePremigratedSize_Proxy( 
    IFsaResourcePriv * This,
    /* [in] */ LONGLONG size);


void __RPC_STUB IFsaResourcePriv_RemovePremigratedSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResourcePriv_RemoveTruncatedSize_Proxy( 
    IFsaResourcePriv * This,
    /* [in] */ LONGLONG size);


void __RPC_STUB IFsaResourcePriv_RemoveTruncatedSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResourcePriv_SetAlternatePath_Proxy( 
    IFsaResourcePriv * This,
    /* [string][in] */ OLECHAR *path);


void __RPC_STUB IFsaResourcePriv_SetAlternatePath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResourcePriv_SetIdentifier_Proxy( 
    IFsaResourcePriv * This,
    /* [in] */ GUID id);


void __RPC_STUB IFsaResourcePriv_SetIdentifier_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResourcePriv_SetName_Proxy( 
    IFsaResourcePriv * This,
    /* [string][in] */ OLECHAR *name);


void __RPC_STUB IFsaResourcePriv_SetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResourcePriv_SetOldPath_Proxy( 
    IFsaResourcePriv * This,
    /* [string][in] */ OLECHAR *oldPath);


void __RPC_STUB IFsaResourcePriv_SetOldPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResourcePriv_SetPath_Proxy( 
    IFsaResourcePriv * This,
    /* [string][in] */ OLECHAR *path);


void __RPC_STUB IFsaResourcePriv_SetPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResourcePriv_SetUserFriendlyName_Proxy( 
    IFsaResourcePriv * This,
    /* [string][in] */ OLECHAR *path);


void __RPC_STUB IFsaResourcePriv_SetUserFriendlyName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResourcePriv_SetStickyName_Proxy( 
    IFsaResourcePriv * This,
    /* [string][in] */ OLECHAR *path);


void __RPC_STUB IFsaResourcePriv_SetStickyName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResourcePriv_SetSerial_Proxy( 
    IFsaResourcePriv * This,
    /* [in] */ ULONG serial);


void __RPC_STUB IFsaResourcePriv_SetSerial_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResourcePriv_UpdateFrom_Proxy( 
    IFsaResourcePriv * This,
    /* [in] */ IFsaServer *pServer,
    /* [in] */ IFsaResource *pResource);


void __RPC_STUB IFsaResourcePriv_UpdateFrom_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaResourcePriv_GetMaxFileLogicalSize_Proxy( 
    IFsaResourcePriv * This,
    /* [out] */ LONGLONG *pSize);


void __RPC_STUB IFsaResourcePriv_GetMaxFileLogicalSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IFsaResourcePriv_INTERFACE_DEFINED__ */


#ifndef __IFsaScanItemPriv_INTERFACE_DEFINED__
#define __IFsaScanItemPriv_INTERFACE_DEFINED__

/* interface IFsaScanItemPriv */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IFsaScanItemPriv;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("03150C1E-9580-4A1F-91B3-BE2367E4F400")
    IFsaScanItemPriv : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE FindFirst( 
            /* [in] */ IFsaResource *pResource,
            /* [string][in] */ OLECHAR *path,
            /* [in] */ IHsmSession *pSession) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FindFirstInRPIndex( 
            /* [in] */ IFsaResource *pResource,
            /* [in] */ IHsmSession *pSession) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FindFirstInDbIndex( 
            /* [in] */ IFsaResource *pResource,
            /* [in] */ IHsmSession *pSession) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FindNext( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FindNextInRPIndex( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FindNextInDbIndex( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE TruncateInternal( 
            /* [in] */ LONGLONG offset,
            /* [in] */ LONGLONG size) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE VerifyInternal( 
            /* [in] */ LONGLONG offset,
            /* [in] */ LONGLONG size,
            /* [in] */ LONGLONG usn1,
            /* [in] */ LONGLONG usn2) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFsaScanItemPrivVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFsaScanItemPriv * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFsaScanItemPriv * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFsaScanItemPriv * This);
        
        HRESULT ( STDMETHODCALLTYPE *FindFirst )( 
            IFsaScanItemPriv * This,
            /* [in] */ IFsaResource *pResource,
            /* [string][in] */ OLECHAR *path,
            /* [in] */ IHsmSession *pSession);
        
        HRESULT ( STDMETHODCALLTYPE *FindFirstInRPIndex )( 
            IFsaScanItemPriv * This,
            /* [in] */ IFsaResource *pResource,
            /* [in] */ IHsmSession *pSession);
        
        HRESULT ( STDMETHODCALLTYPE *FindFirstInDbIndex )( 
            IFsaScanItemPriv * This,
            /* [in] */ IFsaResource *pResource,
            /* [in] */ IHsmSession *pSession);
        
        HRESULT ( STDMETHODCALLTYPE *FindNext )( 
            IFsaScanItemPriv * This);
        
        HRESULT ( STDMETHODCALLTYPE *FindNextInRPIndex )( 
            IFsaScanItemPriv * This);
        
        HRESULT ( STDMETHODCALLTYPE *FindNextInDbIndex )( 
            IFsaScanItemPriv * This);
        
        HRESULT ( STDMETHODCALLTYPE *TruncateInternal )( 
            IFsaScanItemPriv * This,
            /* [in] */ LONGLONG offset,
            /* [in] */ LONGLONG size);
        
        HRESULT ( STDMETHODCALLTYPE *VerifyInternal )( 
            IFsaScanItemPriv * This,
            /* [in] */ LONGLONG offset,
            /* [in] */ LONGLONG size,
            /* [in] */ LONGLONG usn1,
            /* [in] */ LONGLONG usn2);
        
        END_INTERFACE
    } IFsaScanItemPrivVtbl;

    interface IFsaScanItemPriv
    {
        CONST_VTBL struct IFsaScanItemPrivVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFsaScanItemPriv_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFsaScanItemPriv_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFsaScanItemPriv_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFsaScanItemPriv_FindFirst(This,pResource,path,pSession)	\
    (This)->lpVtbl -> FindFirst(This,pResource,path,pSession)

#define IFsaScanItemPriv_FindFirstInRPIndex(This,pResource,pSession)	\
    (This)->lpVtbl -> FindFirstInRPIndex(This,pResource,pSession)

#define IFsaScanItemPriv_FindFirstInDbIndex(This,pResource,pSession)	\
    (This)->lpVtbl -> FindFirstInDbIndex(This,pResource,pSession)

#define IFsaScanItemPriv_FindNext(This)	\
    (This)->lpVtbl -> FindNext(This)

#define IFsaScanItemPriv_FindNextInRPIndex(This)	\
    (This)->lpVtbl -> FindNextInRPIndex(This)

#define IFsaScanItemPriv_FindNextInDbIndex(This)	\
    (This)->lpVtbl -> FindNextInDbIndex(This)

#define IFsaScanItemPriv_TruncateInternal(This,offset,size)	\
    (This)->lpVtbl -> TruncateInternal(This,offset,size)

#define IFsaScanItemPriv_VerifyInternal(This,offset,size,usn1,usn2)	\
    (This)->lpVtbl -> VerifyInternal(This,offset,size,usn1,usn2)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IFsaScanItemPriv_FindFirst_Proxy( 
    IFsaScanItemPriv * This,
    /* [in] */ IFsaResource *pResource,
    /* [string][in] */ OLECHAR *path,
    /* [in] */ IHsmSession *pSession);


void __RPC_STUB IFsaScanItemPriv_FindFirst_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItemPriv_FindFirstInRPIndex_Proxy( 
    IFsaScanItemPriv * This,
    /* [in] */ IFsaResource *pResource,
    /* [in] */ IHsmSession *pSession);


void __RPC_STUB IFsaScanItemPriv_FindFirstInRPIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItemPriv_FindFirstInDbIndex_Proxy( 
    IFsaScanItemPriv * This,
    /* [in] */ IFsaResource *pResource,
    /* [in] */ IHsmSession *pSession);


void __RPC_STUB IFsaScanItemPriv_FindFirstInDbIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItemPriv_FindNext_Proxy( 
    IFsaScanItemPriv * This);


void __RPC_STUB IFsaScanItemPriv_FindNext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItemPriv_FindNextInRPIndex_Proxy( 
    IFsaScanItemPriv * This);


void __RPC_STUB IFsaScanItemPriv_FindNextInRPIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItemPriv_FindNextInDbIndex_Proxy( 
    IFsaScanItemPriv * This);


void __RPC_STUB IFsaScanItemPriv_FindNextInDbIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItemPriv_TruncateInternal_Proxy( 
    IFsaScanItemPriv * This,
    /* [in] */ LONGLONG offset,
    /* [in] */ LONGLONG size);


void __RPC_STUB IFsaScanItemPriv_TruncateInternal_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaScanItemPriv_VerifyInternal_Proxy( 
    IFsaScanItemPriv * This,
    /* [in] */ LONGLONG offset,
    /* [in] */ LONGLONG size,
    /* [in] */ LONGLONG usn1,
    /* [in] */ LONGLONG usn2);


void __RPC_STUB IFsaScanItemPriv_VerifyInternal_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IFsaScanItemPriv_INTERFACE_DEFINED__ */


#ifndef __IFsaPremigratedDb_INTERFACE_DEFINED__
#define __IFsaPremigratedDb_INTERFACE_DEFINED__

/* interface IFsaPremigratedDb */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IFsaPremigratedDb;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E4D900C9-DFD0-4F8D-8F44-1555C2E3E15F")
    IFsaPremigratedDb : public IWsbDb
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Init( 
            /* [string][in] */ OLECHAR *name,
            /* [in] */ IWsbDbSys *pDbSys,
            /* [out] */ BOOL *pCreated) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFsaPremigratedDbVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFsaPremigratedDb * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFsaPremigratedDb * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFsaPremigratedDb * This);
        
        HRESULT ( STDMETHODCALLTYPE *Close )( 
            IFsaPremigratedDb * This,
            /* [in] */ IWsbDbSession *pSession);
        
        HRESULT ( STDMETHODCALLTYPE *Create )( 
            IFsaPremigratedDb * This,
            /* [string][in] */ OLECHAR *path,
            /* [defaultvalue][in] */ ULONG flags);
        
        HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IFsaPremigratedDb * This,
            /* [string][in] */ OLECHAR *path,
            /* [defaultvalue][in] */ ULONG flags);
        
        HRESULT ( STDMETHODCALLTYPE *Dump )( 
            IFsaPremigratedDb * This,
            /* [string][in] */ OLECHAR *Filename,
            /* [in] */ ULONG Flags,
            /* [in] */ ULONG Data);
        
        HRESULT ( STDMETHODCALLTYPE *GetEntity )( 
            IFsaPremigratedDb * This,
            /* [in] */ IWsbDbSession *pSession,
            /* [in] */ ULONG RecId,
            /* [in] */ REFIID riid,
            /* [iid_is][retval][out] */ void **ppEntity);
        
        HRESULT ( STDMETHODCALLTYPE *GetName )( 
            IFsaPremigratedDb * This,
            /* [string][out] */ OLECHAR **pName);
        
        HRESULT ( STDMETHODCALLTYPE *GetPath )( 
            IFsaPremigratedDb * This,
            /* [string][out] */ OLECHAR **pPath);
        
        HRESULT ( STDMETHODCALLTYPE *GetVersion )( 
            IFsaPremigratedDb * This,
            /* [out] */ ULONG *pVer);
        
        HRESULT ( STDMETHODCALLTYPE *Locate )( 
            IFsaPremigratedDb * This,
            /* [string][in] */ OLECHAR *path);
        
        HRESULT ( STDMETHODCALLTYPE *Open )( 
            IFsaPremigratedDb * This,
            /* [out][in] */ IWsbDbSession **ppSession);
        
        HRESULT ( STDMETHODCALLTYPE *Init )( 
            IFsaPremigratedDb * This,
            /* [string][in] */ OLECHAR *name,
            /* [in] */ IWsbDbSys *pDbSys,
            /* [out] */ BOOL *pCreated);
        
        END_INTERFACE
    } IFsaPremigratedDbVtbl;

    interface IFsaPremigratedDb
    {
        CONST_VTBL struct IFsaPremigratedDbVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFsaPremigratedDb_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFsaPremigratedDb_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFsaPremigratedDb_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFsaPremigratedDb_Close(This,pSession)	\
    (This)->lpVtbl -> Close(This,pSession)

#define IFsaPremigratedDb_Create(This,path,flags)	\
    (This)->lpVtbl -> Create(This,path,flags)

#define IFsaPremigratedDb_Delete(This,path,flags)	\
    (This)->lpVtbl -> Delete(This,path,flags)

#define IFsaPremigratedDb_Dump(This,Filename,Flags,Data)	\
    (This)->lpVtbl -> Dump(This,Filename,Flags,Data)

#define IFsaPremigratedDb_GetEntity(This,pSession,RecId,riid,ppEntity)	\
    (This)->lpVtbl -> GetEntity(This,pSession,RecId,riid,ppEntity)

#define IFsaPremigratedDb_GetName(This,pName)	\
    (This)->lpVtbl -> GetName(This,pName)

#define IFsaPremigratedDb_GetPath(This,pPath)	\
    (This)->lpVtbl -> GetPath(This,pPath)

#define IFsaPremigratedDb_GetVersion(This,pVer)	\
    (This)->lpVtbl -> GetVersion(This,pVer)

#define IFsaPremigratedDb_Locate(This,path)	\
    (This)->lpVtbl -> Locate(This,path)

#define IFsaPremigratedDb_Open(This,ppSession)	\
    (This)->lpVtbl -> Open(This,ppSession)


#define IFsaPremigratedDb_Init(This,name,pDbSys,pCreated)	\
    (This)->lpVtbl -> Init(This,name,pDbSys,pCreated)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IFsaPremigratedDb_Init_Proxy( 
    IFsaPremigratedDb * This,
    /* [string][in] */ OLECHAR *name,
    /* [in] */ IWsbDbSys *pDbSys,
    /* [out] */ BOOL *pCreated);


void __RPC_STUB IFsaPremigratedDb_Init_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IFsaPremigratedDb_INTERFACE_DEFINED__ */


#ifndef __IFsaPremigratedRec_INTERFACE_DEFINED__
#define __IFsaPremigratedRec_INTERFACE_DEFINED__

/* interface IFsaPremigratedRec */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IFsaPremigratedRec;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5E2526D3-400D-11d1-A3D5-00609704F787")
    IFsaPremigratedRec : public IWsbDbEntity
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetAccessTime( 
            /* [out] */ FILETIME *pAccessTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBagId( 
            /* [out] */ GUID *pId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBagOffset( 
            /* [out] */ LONGLONG *pOffset) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFileId( 
            /* [out] */ LONGLONG *pFileId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFileUSN( 
            /* [out] */ LONGLONG *pFileUSN) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOffset( 
            /* [out] */ LONGLONG *pOffset) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPath( 
            /* [string][out] */ OLECHAR **ppPath,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecallTime( 
            /* [out] */ FILETIME *pTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSize( 
            /* [out] */ LONGLONG *pSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsWaitingForClose( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAccessTime( 
            /* [in] */ FILETIME pAccessTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFromScanItem( 
            /* [in] */ IFsaScanItem *pScanItem,
            /* [in] */ LONGLONG offset,
            /* [in] */ LONGLONG size,
            /* [in] */ BOOL isWaitingForClose) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetBagId( 
            /* [in] */ GUID pId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetBagOffset( 
            /* [in] */ LONGLONG pOffset) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFileId( 
            /* [in] */ LONGLONG pFileId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFileUSN( 
            /* [in] */ LONGLONG pFileUSN) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetIsWaitingForClose( 
            /* [in] */ BOOL isWaiting) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetOffset( 
            /* [in] */ LONGLONG pOffset) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPath( 
            /* [string][in] */ OLECHAR *pPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRecallTime( 
            /* [in] */ FILETIME time) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSize( 
            /* [in] */ LONGLONG pSize) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFsaPremigratedRecVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFsaPremigratedRec * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFsaPremigratedRec * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFsaPremigratedRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IFsaPremigratedRec * This,
            /* [in] */ REFIID riid,
            /* [iid_is][retval][out] */ void **ppEntity);
        
        HRESULT ( STDMETHODCALLTYPE *Disconnect )( 
            IFsaPremigratedRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *FindEQ )( 
            IFsaPremigratedRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *FindGT )( 
            IFsaPremigratedRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *FindGTE )( 
            IFsaPremigratedRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *FindLT )( 
            IFsaPremigratedRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *FindLTE )( 
            IFsaPremigratedRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *First )( 
            IFsaPremigratedRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *Last )( 
            IFsaPremigratedRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *MarkAsNew )( 
            IFsaPremigratedRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IFsaPremigratedRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *Previous )( 
            IFsaPremigratedRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *Print )( 
            IFsaPremigratedRec * This,
            /* [in] */ IStream *pStream);
        
        HRESULT ( STDMETHODCALLTYPE *Remove )( 
            IFsaPremigratedRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *UpdateKey )( 
            IFsaPremigratedRec * This,
            /* [in] */ IWsbDbKey *pKey);
        
        HRESULT ( STDMETHODCALLTYPE *UseKey )( 
            IFsaPremigratedRec * This,
            /* [in] */ ULONG type);
        
        HRESULT ( STDMETHODCALLTYPE *Write )( 
            IFsaPremigratedRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetSequentialScan )( 
            IFsaPremigratedRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *ResetSequentialScan )( 
            IFsaPremigratedRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetAccessTime )( 
            IFsaPremigratedRec * This,
            /* [out] */ FILETIME *pAccessTime);
        
        HRESULT ( STDMETHODCALLTYPE *GetBagId )( 
            IFsaPremigratedRec * This,
            /* [out] */ GUID *pId);
        
        HRESULT ( STDMETHODCALLTYPE *GetBagOffset )( 
            IFsaPremigratedRec * This,
            /* [out] */ LONGLONG *pOffset);
        
        HRESULT ( STDMETHODCALLTYPE *GetFileId )( 
            IFsaPremigratedRec * This,
            /* [out] */ LONGLONG *pFileId);
        
        HRESULT ( STDMETHODCALLTYPE *GetFileUSN )( 
            IFsaPremigratedRec * This,
            /* [out] */ LONGLONG *pFileUSN);
        
        HRESULT ( STDMETHODCALLTYPE *GetOffset )( 
            IFsaPremigratedRec * This,
            /* [out] */ LONGLONG *pOffset);
        
        HRESULT ( STDMETHODCALLTYPE *GetPath )( 
            IFsaPremigratedRec * This,
            /* [string][out] */ OLECHAR **ppPath,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetRecallTime )( 
            IFsaPremigratedRec * This,
            /* [out] */ FILETIME *pTime);
        
        HRESULT ( STDMETHODCALLTYPE *GetSize )( 
            IFsaPremigratedRec * This,
            /* [out] */ LONGLONG *pSize);
        
        HRESULT ( STDMETHODCALLTYPE *IsWaitingForClose )( 
            IFsaPremigratedRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetAccessTime )( 
            IFsaPremigratedRec * This,
            /* [in] */ FILETIME pAccessTime);
        
        HRESULT ( STDMETHODCALLTYPE *SetFromScanItem )( 
            IFsaPremigratedRec * This,
            /* [in] */ IFsaScanItem *pScanItem,
            /* [in] */ LONGLONG offset,
            /* [in] */ LONGLONG size,
            /* [in] */ BOOL isWaitingForClose);
        
        HRESULT ( STDMETHODCALLTYPE *SetBagId )( 
            IFsaPremigratedRec * This,
            /* [in] */ GUID pId);
        
        HRESULT ( STDMETHODCALLTYPE *SetBagOffset )( 
            IFsaPremigratedRec * This,
            /* [in] */ LONGLONG pOffset);
        
        HRESULT ( STDMETHODCALLTYPE *SetFileId )( 
            IFsaPremigratedRec * This,
            /* [in] */ LONGLONG pFileId);
        
        HRESULT ( STDMETHODCALLTYPE *SetFileUSN )( 
            IFsaPremigratedRec * This,
            /* [in] */ LONGLONG pFileUSN);
        
        HRESULT ( STDMETHODCALLTYPE *SetIsWaitingForClose )( 
            IFsaPremigratedRec * This,
            /* [in] */ BOOL isWaiting);
        
        HRESULT ( STDMETHODCALLTYPE *SetOffset )( 
            IFsaPremigratedRec * This,
            /* [in] */ LONGLONG pOffset);
        
        HRESULT ( STDMETHODCALLTYPE *SetPath )( 
            IFsaPremigratedRec * This,
            /* [string][in] */ OLECHAR *pPath);
        
        HRESULT ( STDMETHODCALLTYPE *SetRecallTime )( 
            IFsaPremigratedRec * This,
            /* [in] */ FILETIME time);
        
        HRESULT ( STDMETHODCALLTYPE *SetSize )( 
            IFsaPremigratedRec * This,
            /* [in] */ LONGLONG pSize);
        
        END_INTERFACE
    } IFsaPremigratedRecVtbl;

    interface IFsaPremigratedRec
    {
        CONST_VTBL struct IFsaPremigratedRecVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFsaPremigratedRec_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFsaPremigratedRec_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFsaPremigratedRec_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFsaPremigratedRec_Clone(This,riid,ppEntity)	\
    (This)->lpVtbl -> Clone(This,riid,ppEntity)

#define IFsaPremigratedRec_Disconnect(This)	\
    (This)->lpVtbl -> Disconnect(This)

#define IFsaPremigratedRec_FindEQ(This)	\
    (This)->lpVtbl -> FindEQ(This)

#define IFsaPremigratedRec_FindGT(This)	\
    (This)->lpVtbl -> FindGT(This)

#define IFsaPremigratedRec_FindGTE(This)	\
    (This)->lpVtbl -> FindGTE(This)

#define IFsaPremigratedRec_FindLT(This)	\
    (This)->lpVtbl -> FindLT(This)

#define IFsaPremigratedRec_FindLTE(This)	\
    (This)->lpVtbl -> FindLTE(This)

#define IFsaPremigratedRec_First(This)	\
    (This)->lpVtbl -> First(This)

#define IFsaPremigratedRec_Last(This)	\
    (This)->lpVtbl -> Last(This)

#define IFsaPremigratedRec_MarkAsNew(This)	\
    (This)->lpVtbl -> MarkAsNew(This)

#define IFsaPremigratedRec_Next(This)	\
    (This)->lpVtbl -> Next(This)

#define IFsaPremigratedRec_Previous(This)	\
    (This)->lpVtbl -> Previous(This)

#define IFsaPremigratedRec_Print(This,pStream)	\
    (This)->lpVtbl -> Print(This,pStream)

#define IFsaPremigratedRec_Remove(This)	\
    (This)->lpVtbl -> Remove(This)

#define IFsaPremigratedRec_UpdateKey(This,pKey)	\
    (This)->lpVtbl -> UpdateKey(This,pKey)

#define IFsaPremigratedRec_UseKey(This,type)	\
    (This)->lpVtbl -> UseKey(This,type)

#define IFsaPremigratedRec_Write(This)	\
    (This)->lpVtbl -> Write(This)

#define IFsaPremigratedRec_SetSequentialScan(This)	\
    (This)->lpVtbl -> SetSequentialScan(This)

#define IFsaPremigratedRec_ResetSequentialScan(This)	\
    (This)->lpVtbl -> ResetSequentialScan(This)


#define IFsaPremigratedRec_GetAccessTime(This,pAccessTime)	\
    (This)->lpVtbl -> GetAccessTime(This,pAccessTime)

#define IFsaPremigratedRec_GetBagId(This,pId)	\
    (This)->lpVtbl -> GetBagId(This,pId)

#define IFsaPremigratedRec_GetBagOffset(This,pOffset)	\
    (This)->lpVtbl -> GetBagOffset(This,pOffset)

#define IFsaPremigratedRec_GetFileId(This,pFileId)	\
    (This)->lpVtbl -> GetFileId(This,pFileId)

#define IFsaPremigratedRec_GetFileUSN(This,pFileUSN)	\
    (This)->lpVtbl -> GetFileUSN(This,pFileUSN)

#define IFsaPremigratedRec_GetOffset(This,pOffset)	\
    (This)->lpVtbl -> GetOffset(This,pOffset)

#define IFsaPremigratedRec_GetPath(This,ppPath,bufferSize)	\
    (This)->lpVtbl -> GetPath(This,ppPath,bufferSize)

#define IFsaPremigratedRec_GetRecallTime(This,pTime)	\
    (This)->lpVtbl -> GetRecallTime(This,pTime)

#define IFsaPremigratedRec_GetSize(This,pSize)	\
    (This)->lpVtbl -> GetSize(This,pSize)

#define IFsaPremigratedRec_IsWaitingForClose(This)	\
    (This)->lpVtbl -> IsWaitingForClose(This)

#define IFsaPremigratedRec_SetAccessTime(This,pAccessTime)	\
    (This)->lpVtbl -> SetAccessTime(This,pAccessTime)

#define IFsaPremigratedRec_SetFromScanItem(This,pScanItem,offset,size,isWaitingForClose)	\
    (This)->lpVtbl -> SetFromScanItem(This,pScanItem,offset,size,isWaitingForClose)

#define IFsaPremigratedRec_SetBagId(This,pId)	\
    (This)->lpVtbl -> SetBagId(This,pId)

#define IFsaPremigratedRec_SetBagOffset(This,pOffset)	\
    (This)->lpVtbl -> SetBagOffset(This,pOffset)

#define IFsaPremigratedRec_SetFileId(This,pFileId)	\
    (This)->lpVtbl -> SetFileId(This,pFileId)

#define IFsaPremigratedRec_SetFileUSN(This,pFileUSN)	\
    (This)->lpVtbl -> SetFileUSN(This,pFileUSN)

#define IFsaPremigratedRec_SetIsWaitingForClose(This,isWaiting)	\
    (This)->lpVtbl -> SetIsWaitingForClose(This,isWaiting)

#define IFsaPremigratedRec_SetOffset(This,pOffset)	\
    (This)->lpVtbl -> SetOffset(This,pOffset)

#define IFsaPremigratedRec_SetPath(This,pPath)	\
    (This)->lpVtbl -> SetPath(This,pPath)

#define IFsaPremigratedRec_SetRecallTime(This,time)	\
    (This)->lpVtbl -> SetRecallTime(This,time)

#define IFsaPremigratedRec_SetSize(This,pSize)	\
    (This)->lpVtbl -> SetSize(This,pSize)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IFsaPremigratedRec_GetAccessTime_Proxy( 
    IFsaPremigratedRec * This,
    /* [out] */ FILETIME *pAccessTime);


void __RPC_STUB IFsaPremigratedRec_GetAccessTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaPremigratedRec_GetBagId_Proxy( 
    IFsaPremigratedRec * This,
    /* [out] */ GUID *pId);


void __RPC_STUB IFsaPremigratedRec_GetBagId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaPremigratedRec_GetBagOffset_Proxy( 
    IFsaPremigratedRec * This,
    /* [out] */ LONGLONG *pOffset);


void __RPC_STUB IFsaPremigratedRec_GetBagOffset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaPremigratedRec_GetFileId_Proxy( 
    IFsaPremigratedRec * This,
    /* [out] */ LONGLONG *pFileId);


void __RPC_STUB IFsaPremigratedRec_GetFileId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaPremigratedRec_GetFileUSN_Proxy( 
    IFsaPremigratedRec * This,
    /* [out] */ LONGLONG *pFileUSN);


void __RPC_STUB IFsaPremigratedRec_GetFileUSN_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaPremigratedRec_GetOffset_Proxy( 
    IFsaPremigratedRec * This,
    /* [out] */ LONGLONG *pOffset);


void __RPC_STUB IFsaPremigratedRec_GetOffset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaPremigratedRec_GetPath_Proxy( 
    IFsaPremigratedRec * This,
    /* [string][out] */ OLECHAR **ppPath,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IFsaPremigratedRec_GetPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaPremigratedRec_GetRecallTime_Proxy( 
    IFsaPremigratedRec * This,
    /* [out] */ FILETIME *pTime);


void __RPC_STUB IFsaPremigratedRec_GetRecallTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaPremigratedRec_GetSize_Proxy( 
    IFsaPremigratedRec * This,
    /* [out] */ LONGLONG *pSize);


void __RPC_STUB IFsaPremigratedRec_GetSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaPremigratedRec_IsWaitingForClose_Proxy( 
    IFsaPremigratedRec * This);


void __RPC_STUB IFsaPremigratedRec_IsWaitingForClose_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaPremigratedRec_SetAccessTime_Proxy( 
    IFsaPremigratedRec * This,
    /* [in] */ FILETIME pAccessTime);


void __RPC_STUB IFsaPremigratedRec_SetAccessTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaPremigratedRec_SetFromScanItem_Proxy( 
    IFsaPremigratedRec * This,
    /* [in] */ IFsaScanItem *pScanItem,
    /* [in] */ LONGLONG offset,
    /* [in] */ LONGLONG size,
    /* [in] */ BOOL isWaitingForClose);


void __RPC_STUB IFsaPremigratedRec_SetFromScanItem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaPremigratedRec_SetBagId_Proxy( 
    IFsaPremigratedRec * This,
    /* [in] */ GUID pId);


void __RPC_STUB IFsaPremigratedRec_SetBagId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaPremigratedRec_SetBagOffset_Proxy( 
    IFsaPremigratedRec * This,
    /* [in] */ LONGLONG pOffset);


void __RPC_STUB IFsaPremigratedRec_SetBagOffset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaPremigratedRec_SetFileId_Proxy( 
    IFsaPremigratedRec * This,
    /* [in] */ LONGLONG pFileId);


void __RPC_STUB IFsaPremigratedRec_SetFileId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaPremigratedRec_SetFileUSN_Proxy( 
    IFsaPremigratedRec * This,
    /* [in] */ LONGLONG pFileUSN);


void __RPC_STUB IFsaPremigratedRec_SetFileUSN_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaPremigratedRec_SetIsWaitingForClose_Proxy( 
    IFsaPremigratedRec * This,
    /* [in] */ BOOL isWaiting);


void __RPC_STUB IFsaPremigratedRec_SetIsWaitingForClose_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaPremigratedRec_SetOffset_Proxy( 
    IFsaPremigratedRec * This,
    /* [in] */ LONGLONG pOffset);


void __RPC_STUB IFsaPremigratedRec_SetOffset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaPremigratedRec_SetPath_Proxy( 
    IFsaPremigratedRec * This,
    /* [string][in] */ OLECHAR *pPath);


void __RPC_STUB IFsaPremigratedRec_SetPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaPremigratedRec_SetRecallTime_Proxy( 
    IFsaPremigratedRec * This,
    /* [in] */ FILETIME time);


void __RPC_STUB IFsaPremigratedRec_SetRecallTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaPremigratedRec_SetSize_Proxy( 
    IFsaPremigratedRec * This,
    /* [in] */ LONGLONG pSize);


void __RPC_STUB IFsaPremigratedRec_SetSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IFsaPremigratedRec_INTERFACE_DEFINED__ */


#ifndef __IFsaRecoveryRec_INTERFACE_DEFINED__
#define __IFsaRecoveryRec_INTERFACE_DEFINED__

/* interface IFsaRecoveryRec */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IFsaRecoveryRec;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("74D85681-44D8-11d1-A3D7-00609704F787")
    IFsaRecoveryRec : public IWsbDbEntity
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetBagId( 
            /* [out] */ GUID *pId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBagOffset( 
            /* [out] */ LONGLONG *pOffset) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFileId( 
            /* [out] */ LONGLONG *pFileId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOffsetSize( 
            /* [out] */ LONGLONG *pOffset,
            /* [out] */ LONGLONG *pSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPath( 
            /* [string][out] */ OLECHAR **ppPath,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecoveryCount( 
            /* [out] */ LONG *pCount) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStatus( 
            /* [out] */ ULONG *pStatus) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetBagId( 
            /* [in] */ GUID pId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetBagOffset( 
            /* [in] */ LONGLONG pOffset) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFileId( 
            /* [in] */ LONGLONG pFileId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetOffsetSize( 
            /* [in] */ LONGLONG Offset,
            /* [in] */ LONGLONG Size) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPath( 
            /* [string][in] */ OLECHAR *pPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRecoveryCount( 
            /* [in] */ LONG Count) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetStatus( 
            /* [in] */ ULONG Status) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFsaRecoveryRecVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFsaRecoveryRec * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFsaRecoveryRec * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFsaRecoveryRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IFsaRecoveryRec * This,
            /* [in] */ REFIID riid,
            /* [iid_is][retval][out] */ void **ppEntity);
        
        HRESULT ( STDMETHODCALLTYPE *Disconnect )( 
            IFsaRecoveryRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *FindEQ )( 
            IFsaRecoveryRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *FindGT )( 
            IFsaRecoveryRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *FindGTE )( 
            IFsaRecoveryRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *FindLT )( 
            IFsaRecoveryRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *FindLTE )( 
            IFsaRecoveryRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *First )( 
            IFsaRecoveryRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *Last )( 
            IFsaRecoveryRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *MarkAsNew )( 
            IFsaRecoveryRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IFsaRecoveryRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *Previous )( 
            IFsaRecoveryRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *Print )( 
            IFsaRecoveryRec * This,
            /* [in] */ IStream *pStream);
        
        HRESULT ( STDMETHODCALLTYPE *Remove )( 
            IFsaRecoveryRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *UpdateKey )( 
            IFsaRecoveryRec * This,
            /* [in] */ IWsbDbKey *pKey);
        
        HRESULT ( STDMETHODCALLTYPE *UseKey )( 
            IFsaRecoveryRec * This,
            /* [in] */ ULONG type);
        
        HRESULT ( STDMETHODCALLTYPE *Write )( 
            IFsaRecoveryRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetSequentialScan )( 
            IFsaRecoveryRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *ResetSequentialScan )( 
            IFsaRecoveryRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetBagId )( 
            IFsaRecoveryRec * This,
            /* [out] */ GUID *pId);
        
        HRESULT ( STDMETHODCALLTYPE *GetBagOffset )( 
            IFsaRecoveryRec * This,
            /* [out] */ LONGLONG *pOffset);
        
        HRESULT ( STDMETHODCALLTYPE *GetFileId )( 
            IFsaRecoveryRec * This,
            /* [out] */ LONGLONG *pFileId);
        
        HRESULT ( STDMETHODCALLTYPE *GetOffsetSize )( 
            IFsaRecoveryRec * This,
            /* [out] */ LONGLONG *pOffset,
            /* [out] */ LONGLONG *pSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetPath )( 
            IFsaRecoveryRec * This,
            /* [string][out] */ OLECHAR **ppPath,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetRecoveryCount )( 
            IFsaRecoveryRec * This,
            /* [out] */ LONG *pCount);
        
        HRESULT ( STDMETHODCALLTYPE *GetStatus )( 
            IFsaRecoveryRec * This,
            /* [out] */ ULONG *pStatus);
        
        HRESULT ( STDMETHODCALLTYPE *SetBagId )( 
            IFsaRecoveryRec * This,
            /* [in] */ GUID pId);
        
        HRESULT ( STDMETHODCALLTYPE *SetBagOffset )( 
            IFsaRecoveryRec * This,
            /* [in] */ LONGLONG pOffset);
        
        HRESULT ( STDMETHODCALLTYPE *SetFileId )( 
            IFsaRecoveryRec * This,
            /* [in] */ LONGLONG pFileId);
        
        HRESULT ( STDMETHODCALLTYPE *SetOffsetSize )( 
            IFsaRecoveryRec * This,
            /* [in] */ LONGLONG Offset,
            /* [in] */ LONGLONG Size);
        
        HRESULT ( STDMETHODCALLTYPE *SetPath )( 
            IFsaRecoveryRec * This,
            /* [string][in] */ OLECHAR *pPath);
        
        HRESULT ( STDMETHODCALLTYPE *SetRecoveryCount )( 
            IFsaRecoveryRec * This,
            /* [in] */ LONG Count);
        
        HRESULT ( STDMETHODCALLTYPE *SetStatus )( 
            IFsaRecoveryRec * This,
            /* [in] */ ULONG Status);
        
        END_INTERFACE
    } IFsaRecoveryRecVtbl;

    interface IFsaRecoveryRec
    {
        CONST_VTBL struct IFsaRecoveryRecVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFsaRecoveryRec_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFsaRecoveryRec_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFsaRecoveryRec_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFsaRecoveryRec_Clone(This,riid,ppEntity)	\
    (This)->lpVtbl -> Clone(This,riid,ppEntity)

#define IFsaRecoveryRec_Disconnect(This)	\
    (This)->lpVtbl -> Disconnect(This)

#define IFsaRecoveryRec_FindEQ(This)	\
    (This)->lpVtbl -> FindEQ(This)

#define IFsaRecoveryRec_FindGT(This)	\
    (This)->lpVtbl -> FindGT(This)

#define IFsaRecoveryRec_FindGTE(This)	\
    (This)->lpVtbl -> FindGTE(This)

#define IFsaRecoveryRec_FindLT(This)	\
    (This)->lpVtbl -> FindLT(This)

#define IFsaRecoveryRec_FindLTE(This)	\
    (This)->lpVtbl -> FindLTE(This)

#define IFsaRecoveryRec_First(This)	\
    (This)->lpVtbl -> First(This)

#define IFsaRecoveryRec_Last(This)	\
    (This)->lpVtbl -> Last(This)

#define IFsaRecoveryRec_MarkAsNew(This)	\
    (This)->lpVtbl -> MarkAsNew(This)

#define IFsaRecoveryRec_Next(This)	\
    (This)->lpVtbl -> Next(This)

#define IFsaRecoveryRec_Previous(This)	\
    (This)->lpVtbl -> Previous(This)

#define IFsaRecoveryRec_Print(This,pStream)	\
    (This)->lpVtbl -> Print(This,pStream)

#define IFsaRecoveryRec_Remove(This)	\
    (This)->lpVtbl -> Remove(This)

#define IFsaRecoveryRec_UpdateKey(This,pKey)	\
    (This)->lpVtbl -> UpdateKey(This,pKey)

#define IFsaRecoveryRec_UseKey(This,type)	\
    (This)->lpVtbl -> UseKey(This,type)

#define IFsaRecoveryRec_Write(This)	\
    (This)->lpVtbl -> Write(This)

#define IFsaRecoveryRec_SetSequentialScan(This)	\
    (This)->lpVtbl -> SetSequentialScan(This)

#define IFsaRecoveryRec_ResetSequentialScan(This)	\
    (This)->lpVtbl -> ResetSequentialScan(This)


#define IFsaRecoveryRec_GetBagId(This,pId)	\
    (This)->lpVtbl -> GetBagId(This,pId)

#define IFsaRecoveryRec_GetBagOffset(This,pOffset)	\
    (This)->lpVtbl -> GetBagOffset(This,pOffset)

#define IFsaRecoveryRec_GetFileId(This,pFileId)	\
    (This)->lpVtbl -> GetFileId(This,pFileId)

#define IFsaRecoveryRec_GetOffsetSize(This,pOffset,pSize)	\
    (This)->lpVtbl -> GetOffsetSize(This,pOffset,pSize)

#define IFsaRecoveryRec_GetPath(This,ppPath,bufferSize)	\
    (This)->lpVtbl -> GetPath(This,ppPath,bufferSize)

#define IFsaRecoveryRec_GetRecoveryCount(This,pCount)	\
    (This)->lpVtbl -> GetRecoveryCount(This,pCount)

#define IFsaRecoveryRec_GetStatus(This,pStatus)	\
    (This)->lpVtbl -> GetStatus(This,pStatus)

#define IFsaRecoveryRec_SetBagId(This,pId)	\
    (This)->lpVtbl -> SetBagId(This,pId)

#define IFsaRecoveryRec_SetBagOffset(This,pOffset)	\
    (This)->lpVtbl -> SetBagOffset(This,pOffset)

#define IFsaRecoveryRec_SetFileId(This,pFileId)	\
    (This)->lpVtbl -> SetFileId(This,pFileId)

#define IFsaRecoveryRec_SetOffsetSize(This,Offset,Size)	\
    (This)->lpVtbl -> SetOffsetSize(This,Offset,Size)

#define IFsaRecoveryRec_SetPath(This,pPath)	\
    (This)->lpVtbl -> SetPath(This,pPath)

#define IFsaRecoveryRec_SetRecoveryCount(This,Count)	\
    (This)->lpVtbl -> SetRecoveryCount(This,Count)

#define IFsaRecoveryRec_SetStatus(This,Status)	\
    (This)->lpVtbl -> SetStatus(This,Status)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IFsaRecoveryRec_GetBagId_Proxy( 
    IFsaRecoveryRec * This,
    /* [out] */ GUID *pId);


void __RPC_STUB IFsaRecoveryRec_GetBagId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaRecoveryRec_GetBagOffset_Proxy( 
    IFsaRecoveryRec * This,
    /* [out] */ LONGLONG *pOffset);


void __RPC_STUB IFsaRecoveryRec_GetBagOffset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaRecoveryRec_GetFileId_Proxy( 
    IFsaRecoveryRec * This,
    /* [out] */ LONGLONG *pFileId);


void __RPC_STUB IFsaRecoveryRec_GetFileId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaRecoveryRec_GetOffsetSize_Proxy( 
    IFsaRecoveryRec * This,
    /* [out] */ LONGLONG *pOffset,
    /* [out] */ LONGLONG *pSize);


void __RPC_STUB IFsaRecoveryRec_GetOffsetSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaRecoveryRec_GetPath_Proxy( 
    IFsaRecoveryRec * This,
    /* [string][out] */ OLECHAR **ppPath,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IFsaRecoveryRec_GetPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaRecoveryRec_GetRecoveryCount_Proxy( 
    IFsaRecoveryRec * This,
    /* [out] */ LONG *pCount);


void __RPC_STUB IFsaRecoveryRec_GetRecoveryCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaRecoveryRec_GetStatus_Proxy( 
    IFsaRecoveryRec * This,
    /* [out] */ ULONG *pStatus);


void __RPC_STUB IFsaRecoveryRec_GetStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaRecoveryRec_SetBagId_Proxy( 
    IFsaRecoveryRec * This,
    /* [in] */ GUID pId);


void __RPC_STUB IFsaRecoveryRec_SetBagId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaRecoveryRec_SetBagOffset_Proxy( 
    IFsaRecoveryRec * This,
    /* [in] */ LONGLONG pOffset);


void __RPC_STUB IFsaRecoveryRec_SetBagOffset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaRecoveryRec_SetFileId_Proxy( 
    IFsaRecoveryRec * This,
    /* [in] */ LONGLONG pFileId);


void __RPC_STUB IFsaRecoveryRec_SetFileId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaRecoveryRec_SetOffsetSize_Proxy( 
    IFsaRecoveryRec * This,
    /* [in] */ LONGLONG Offset,
    /* [in] */ LONGLONG Size);


void __RPC_STUB IFsaRecoveryRec_SetOffsetSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaRecoveryRec_SetPath_Proxy( 
    IFsaRecoveryRec * This,
    /* [string][in] */ OLECHAR *pPath);


void __RPC_STUB IFsaRecoveryRec_SetPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaRecoveryRec_SetRecoveryCount_Proxy( 
    IFsaRecoveryRec * This,
    /* [in] */ LONG Count);


void __RPC_STUB IFsaRecoveryRec_SetRecoveryCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaRecoveryRec_SetStatus_Proxy( 
    IFsaRecoveryRec * This,
    /* [in] */ ULONG Status);


void __RPC_STUB IFsaRecoveryRec_SetStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IFsaRecoveryRec_INTERFACE_DEFINED__ */


#ifndef __IFsaUnmanageDb_INTERFACE_DEFINED__
#define __IFsaUnmanageDb_INTERFACE_DEFINED__

/* interface IFsaUnmanageDb */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IFsaUnmanageDb;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3F676047-90B6-48D6-B479-28E57AD4B746")
    IFsaUnmanageDb : public IWsbDb
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Init( 
            /* [string][in] */ OLECHAR *name,
            /* [in] */ IWsbDbSys *pDbSys,
            /* [out] */ BOOL *pCreated) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFsaUnmanageDbVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFsaUnmanageDb * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFsaUnmanageDb * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFsaUnmanageDb * This);
        
        HRESULT ( STDMETHODCALLTYPE *Close )( 
            IFsaUnmanageDb * This,
            /* [in] */ IWsbDbSession *pSession);
        
        HRESULT ( STDMETHODCALLTYPE *Create )( 
            IFsaUnmanageDb * This,
            /* [string][in] */ OLECHAR *path,
            /* [defaultvalue][in] */ ULONG flags);
        
        HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IFsaUnmanageDb * This,
            /* [string][in] */ OLECHAR *path,
            /* [defaultvalue][in] */ ULONG flags);
        
        HRESULT ( STDMETHODCALLTYPE *Dump )( 
            IFsaUnmanageDb * This,
            /* [string][in] */ OLECHAR *Filename,
            /* [in] */ ULONG Flags,
            /* [in] */ ULONG Data);
        
        HRESULT ( STDMETHODCALLTYPE *GetEntity )( 
            IFsaUnmanageDb * This,
            /* [in] */ IWsbDbSession *pSession,
            /* [in] */ ULONG RecId,
            /* [in] */ REFIID riid,
            /* [iid_is][retval][out] */ void **ppEntity);
        
        HRESULT ( STDMETHODCALLTYPE *GetName )( 
            IFsaUnmanageDb * This,
            /* [string][out] */ OLECHAR **pName);
        
        HRESULT ( STDMETHODCALLTYPE *GetPath )( 
            IFsaUnmanageDb * This,
            /* [string][out] */ OLECHAR **pPath);
        
        HRESULT ( STDMETHODCALLTYPE *GetVersion )( 
            IFsaUnmanageDb * This,
            /* [out] */ ULONG *pVer);
        
        HRESULT ( STDMETHODCALLTYPE *Locate )( 
            IFsaUnmanageDb * This,
            /* [string][in] */ OLECHAR *path);
        
        HRESULT ( STDMETHODCALLTYPE *Open )( 
            IFsaUnmanageDb * This,
            /* [out][in] */ IWsbDbSession **ppSession);
        
        HRESULT ( STDMETHODCALLTYPE *Init )( 
            IFsaUnmanageDb * This,
            /* [string][in] */ OLECHAR *name,
            /* [in] */ IWsbDbSys *pDbSys,
            /* [out] */ BOOL *pCreated);
        
        END_INTERFACE
    } IFsaUnmanageDbVtbl;

    interface IFsaUnmanageDb
    {
        CONST_VTBL struct IFsaUnmanageDbVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFsaUnmanageDb_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFsaUnmanageDb_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFsaUnmanageDb_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFsaUnmanageDb_Close(This,pSession)	\
    (This)->lpVtbl -> Close(This,pSession)

#define IFsaUnmanageDb_Create(This,path,flags)	\
    (This)->lpVtbl -> Create(This,path,flags)

#define IFsaUnmanageDb_Delete(This,path,flags)	\
    (This)->lpVtbl -> Delete(This,path,flags)

#define IFsaUnmanageDb_Dump(This,Filename,Flags,Data)	\
    (This)->lpVtbl -> Dump(This,Filename,Flags,Data)

#define IFsaUnmanageDb_GetEntity(This,pSession,RecId,riid,ppEntity)	\
    (This)->lpVtbl -> GetEntity(This,pSession,RecId,riid,ppEntity)

#define IFsaUnmanageDb_GetName(This,pName)	\
    (This)->lpVtbl -> GetName(This,pName)

#define IFsaUnmanageDb_GetPath(This,pPath)	\
    (This)->lpVtbl -> GetPath(This,pPath)

#define IFsaUnmanageDb_GetVersion(This,pVer)	\
    (This)->lpVtbl -> GetVersion(This,pVer)

#define IFsaUnmanageDb_Locate(This,path)	\
    (This)->lpVtbl -> Locate(This,path)

#define IFsaUnmanageDb_Open(This,ppSession)	\
    (This)->lpVtbl -> Open(This,ppSession)


#define IFsaUnmanageDb_Init(This,name,pDbSys,pCreated)	\
    (This)->lpVtbl -> Init(This,name,pDbSys,pCreated)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IFsaUnmanageDb_Init_Proxy( 
    IFsaUnmanageDb * This,
    /* [string][in] */ OLECHAR *name,
    /* [in] */ IWsbDbSys *pDbSys,
    /* [out] */ BOOL *pCreated);


void __RPC_STUB IFsaUnmanageDb_Init_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IFsaUnmanageDb_INTERFACE_DEFINED__ */


#ifndef __IFsaUnmanageRec_INTERFACE_DEFINED__
#define __IFsaUnmanageRec_INTERFACE_DEFINED__

/* interface IFsaUnmanageRec */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IFsaUnmanageRec;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("90D54B53-EDB6-401D-81C5-47D7B4842EC0")
    IFsaUnmanageRec : public IWsbDbEntity
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetMediaId( 
            /* [out] */ GUID *pId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFileOffset( 
            /* [out] */ LONGLONG *pOffset) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFileId( 
            /* [out] */ LONGLONG *pFileId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMediaId( 
            /* [in] */ GUID pId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFileOffset( 
            /* [in] */ LONGLONG pOffset) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFileId( 
            /* [in] */ LONGLONG pFileId) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IFsaUnmanageRecVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IFsaUnmanageRec * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IFsaUnmanageRec * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IFsaUnmanageRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IFsaUnmanageRec * This,
            /* [in] */ REFIID riid,
            /* [iid_is][retval][out] */ void **ppEntity);
        
        HRESULT ( STDMETHODCALLTYPE *Disconnect )( 
            IFsaUnmanageRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *FindEQ )( 
            IFsaUnmanageRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *FindGT )( 
            IFsaUnmanageRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *FindGTE )( 
            IFsaUnmanageRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *FindLT )( 
            IFsaUnmanageRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *FindLTE )( 
            IFsaUnmanageRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *First )( 
            IFsaUnmanageRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *Last )( 
            IFsaUnmanageRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *MarkAsNew )( 
            IFsaUnmanageRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IFsaUnmanageRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *Previous )( 
            IFsaUnmanageRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *Print )( 
            IFsaUnmanageRec * This,
            /* [in] */ IStream *pStream);
        
        HRESULT ( STDMETHODCALLTYPE *Remove )( 
            IFsaUnmanageRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *UpdateKey )( 
            IFsaUnmanageRec * This,
            /* [in] */ IWsbDbKey *pKey);
        
        HRESULT ( STDMETHODCALLTYPE *UseKey )( 
            IFsaUnmanageRec * This,
            /* [in] */ ULONG type);
        
        HRESULT ( STDMETHODCALLTYPE *Write )( 
            IFsaUnmanageRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetSequentialScan )( 
            IFsaUnmanageRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *ResetSequentialScan )( 
            IFsaUnmanageRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetMediaId )( 
            IFsaUnmanageRec * This,
            /* [out] */ GUID *pId);
        
        HRESULT ( STDMETHODCALLTYPE *GetFileOffset )( 
            IFsaUnmanageRec * This,
            /* [out] */ LONGLONG *pOffset);
        
        HRESULT ( STDMETHODCALLTYPE *GetFileId )( 
            IFsaUnmanageRec * This,
            /* [out] */ LONGLONG *pFileId);
        
        HRESULT ( STDMETHODCALLTYPE *SetMediaId )( 
            IFsaUnmanageRec * This,
            /* [in] */ GUID pId);
        
        HRESULT ( STDMETHODCALLTYPE *SetFileOffset )( 
            IFsaUnmanageRec * This,
            /* [in] */ LONGLONG pOffset);
        
        HRESULT ( STDMETHODCALLTYPE *SetFileId )( 
            IFsaUnmanageRec * This,
            /* [in] */ LONGLONG pFileId);
        
        END_INTERFACE
    } IFsaUnmanageRecVtbl;

    interface IFsaUnmanageRec
    {
        CONST_VTBL struct IFsaUnmanageRecVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IFsaUnmanageRec_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IFsaUnmanageRec_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IFsaUnmanageRec_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IFsaUnmanageRec_Clone(This,riid,ppEntity)	\
    (This)->lpVtbl -> Clone(This,riid,ppEntity)

#define IFsaUnmanageRec_Disconnect(This)	\
    (This)->lpVtbl -> Disconnect(This)

#define IFsaUnmanageRec_FindEQ(This)	\
    (This)->lpVtbl -> FindEQ(This)

#define IFsaUnmanageRec_FindGT(This)	\
    (This)->lpVtbl -> FindGT(This)

#define IFsaUnmanageRec_FindGTE(This)	\
    (This)->lpVtbl -> FindGTE(This)

#define IFsaUnmanageRec_FindLT(This)	\
    (This)->lpVtbl -> FindLT(This)

#define IFsaUnmanageRec_FindLTE(This)	\
    (This)->lpVtbl -> FindLTE(This)

#define IFsaUnmanageRec_First(This)	\
    (This)->lpVtbl -> First(This)

#define IFsaUnmanageRec_Last(This)	\
    (This)->lpVtbl -> Last(This)

#define IFsaUnmanageRec_MarkAsNew(This)	\
    (This)->lpVtbl -> MarkAsNew(This)

#define IFsaUnmanageRec_Next(This)	\
    (This)->lpVtbl -> Next(This)

#define IFsaUnmanageRec_Previous(This)	\
    (This)->lpVtbl -> Previous(This)

#define IFsaUnmanageRec_Print(This,pStream)	\
    (This)->lpVtbl -> Print(This,pStream)

#define IFsaUnmanageRec_Remove(This)	\
    (This)->lpVtbl -> Remove(This)

#define IFsaUnmanageRec_UpdateKey(This,pKey)	\
    (This)->lpVtbl -> UpdateKey(This,pKey)

#define IFsaUnmanageRec_UseKey(This,type)	\
    (This)->lpVtbl -> UseKey(This,type)

#define IFsaUnmanageRec_Write(This)	\
    (This)->lpVtbl -> Write(This)

#define IFsaUnmanageRec_SetSequentialScan(This)	\
    (This)->lpVtbl -> SetSequentialScan(This)

#define IFsaUnmanageRec_ResetSequentialScan(This)	\
    (This)->lpVtbl -> ResetSequentialScan(This)


#define IFsaUnmanageRec_GetMediaId(This,pId)	\
    (This)->lpVtbl -> GetMediaId(This,pId)

#define IFsaUnmanageRec_GetFileOffset(This,pOffset)	\
    (This)->lpVtbl -> GetFileOffset(This,pOffset)

#define IFsaUnmanageRec_GetFileId(This,pFileId)	\
    (This)->lpVtbl -> GetFileId(This,pFileId)

#define IFsaUnmanageRec_SetMediaId(This,pId)	\
    (This)->lpVtbl -> SetMediaId(This,pId)

#define IFsaUnmanageRec_SetFileOffset(This,pOffset)	\
    (This)->lpVtbl -> SetFileOffset(This,pOffset)

#define IFsaUnmanageRec_SetFileId(This,pFileId)	\
    (This)->lpVtbl -> SetFileId(This,pFileId)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IFsaUnmanageRec_GetMediaId_Proxy( 
    IFsaUnmanageRec * This,
    /* [out] */ GUID *pId);


void __RPC_STUB IFsaUnmanageRec_GetMediaId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaUnmanageRec_GetFileOffset_Proxy( 
    IFsaUnmanageRec * This,
    /* [out] */ LONGLONG *pOffset);


void __RPC_STUB IFsaUnmanageRec_GetFileOffset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaUnmanageRec_GetFileId_Proxy( 
    IFsaUnmanageRec * This,
    /* [out] */ LONGLONG *pFileId);


void __RPC_STUB IFsaUnmanageRec_GetFileId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaUnmanageRec_SetMediaId_Proxy( 
    IFsaUnmanageRec * This,
    /* [in] */ GUID pId);


void __RPC_STUB IFsaUnmanageRec_SetMediaId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaUnmanageRec_SetFileOffset_Proxy( 
    IFsaUnmanageRec * This,
    /* [in] */ LONGLONG pOffset);


void __RPC_STUB IFsaUnmanageRec_SetFileOffset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IFsaUnmanageRec_SetFileId_Proxy( 
    IFsaUnmanageRec * This,
    /* [in] */ LONGLONG pFileId);


void __RPC_STUB IFsaUnmanageRec_SetFileId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IFsaUnmanageRec_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


