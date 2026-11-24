

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for jobprv.idl:
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

#ifndef __jobprv_h__
#define __jobprv_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IHsmJobPriv_FWD_DEFINED__
#define __IHsmJobPriv_FWD_DEFINED__
typedef interface IHsmJobPriv IHsmJobPriv;
#endif 	/* __IHsmJobPriv_FWD_DEFINED__ */


#ifndef __IHsmJobWorkItemPriv_FWD_DEFINED__
#define __IHsmJobWorkItemPriv_FWD_DEFINED__
typedef interface IHsmJobWorkItemPriv IHsmJobWorkItemPriv;
#endif 	/* __IHsmJobWorkItemPriv_FWD_DEFINED__ */


#ifndef __IHsmPhasePriv_FWD_DEFINED__
#define __IHsmPhasePriv_FWD_DEFINED__
typedef interface IHsmPhasePriv IHsmPhasePriv;
#endif 	/* __IHsmPhasePriv_FWD_DEFINED__ */


#ifndef __IHsmSessionTotalsPriv_FWD_DEFINED__
#define __IHsmSessionTotalsPriv_FWD_DEFINED__
typedef interface IHsmSessionTotalsPriv IHsmSessionTotalsPriv;
#endif 	/* __IHsmSessionTotalsPriv_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "jobdef.h"
#include "fsaint.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

/* interface __MIDL_itf_jobprv_0000 */
/* [local] */ 







extern RPC_IF_HANDLE __MIDL_itf_jobprv_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_jobprv_0000_v0_0_s_ifspec;

#ifndef __IHsmJobPriv_INTERFACE_DEFINED__
#define __IHsmJobPriv_INTERFACE_DEFINED__

/* interface IHsmJobPriv */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IHsmJobPriv;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("31B6B5CB-0DB0-4286-84EA-8A0F3D25AE00")
    IHsmJobPriv : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AdviseOfSessionState( 
            /* [in] */ IHsmSession *pSession,
            /* [in] */ IHsmPhase *pPhase,
            /* [string][in] */ OLECHAR *currentPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DoNext( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHsmJobPrivVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHsmJobPriv * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHsmJobPriv * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHsmJobPriv * This);
        
        HRESULT ( STDMETHODCALLTYPE *AdviseOfSessionState )( 
            IHsmJobPriv * This,
            /* [in] */ IHsmSession *pSession,
            /* [in] */ IHsmPhase *pPhase,
            /* [string][in] */ OLECHAR *currentPath);
        
        HRESULT ( STDMETHODCALLTYPE *DoNext )( 
            IHsmJobPriv * This);
        
        END_INTERFACE
    } IHsmJobPrivVtbl;

    interface IHsmJobPriv
    {
        CONST_VTBL struct IHsmJobPrivVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHsmJobPriv_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHsmJobPriv_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHsmJobPriv_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHsmJobPriv_AdviseOfSessionState(This,pSession,pPhase,currentPath)	\
    (This)->lpVtbl -> AdviseOfSessionState(This,pSession,pPhase,currentPath)

#define IHsmJobPriv_DoNext(This)	\
    (This)->lpVtbl -> DoNext(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IHsmJobPriv_AdviseOfSessionState_Proxy( 
    IHsmJobPriv * This,
    /* [in] */ IHsmSession *pSession,
    /* [in] */ IHsmPhase *pPhase,
    /* [string][in] */ OLECHAR *currentPath);


void __RPC_STUB IHsmJobPriv_AdviseOfSessionState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobPriv_DoNext_Proxy( 
    IHsmJobPriv * This);


void __RPC_STUB IHsmJobPriv_DoNext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IHsmJobPriv_INTERFACE_DEFINED__ */


#ifndef __IHsmJobWorkItemPriv_INTERFACE_DEFINED__
#define __IHsmJobWorkItemPriv_INTERFACE_DEFINED__

/* interface IHsmJobWorkItemPriv */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IHsmJobWorkItemPriv;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("29312E77-7056-4E2F-83CC-FB1489FAD7F6")
    IHsmJobWorkItemPriv : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CompareToResourceId( 
            /* [in] */ GUID id,
            /* [out] */ SHORT *pResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CompareToIWorkItem( 
            /* [in] */ IHsmJobWorkItem *pWorkItem,
            /* [out] */ SHORT *pResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumPhases( 
            /* [out] */ IWsbEnum **ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumTotals( 
            /* [out] */ IWsbEnum **ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCookie( 
            /* [out] */ DWORD *pCookie) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCurrentPath( 
            /* [string][out][in] */ OLECHAR **pString,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFinishTime( 
            /* [out] */ FILETIME *pTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPhases( 
            /* [out] */ IWsbCollection **pPhases) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetResourceId( 
            /* [out] */ GUID *pId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSession( 
            /* [out] */ IHsmSession **ppSession) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStartingPath( 
            /* [string][out][in] */ OLECHAR **pString,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStartTime( 
            /* [out] */ FILETIME *pTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetState( 
            /* [out] */ HSM_JOB_STATE *pState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStateAsString( 
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSubRunId( 
            /* [out] */ ULONG *pId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTotals( 
            /* [out] */ IWsbCollection **pTotals) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Init( 
            /* [in] */ IHsmJob *pJob) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCookie( 
            /* [in] */ DWORD cookie) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCurrentPath( 
            /* [string][in] */ OLECHAR *string) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFinishTime( 
            /* [in] */ FILETIME time) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetResourceId( 
            /* [in] */ GUID id) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSession( 
            /* [in] */ IHsmSession *pSession) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetStartingPath( 
            /* [string][in] */ OLECHAR *string) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetStartTime( 
            /* [in] */ FILETIME time) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetState( 
            /* [in] */ HSM_JOB_STATE state) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSubRunId( 
            /* [in] */ ULONG id) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsActiveItem( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetActiveItem( 
            /* [in] */ BOOL bActive) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHsmJobWorkItemPrivVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHsmJobWorkItemPriv * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHsmJobWorkItemPriv * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHsmJobWorkItemPriv * This);
        
        HRESULT ( STDMETHODCALLTYPE *CompareToResourceId )( 
            IHsmJobWorkItemPriv * This,
            /* [in] */ GUID id,
            /* [out] */ SHORT *pResult);
        
        HRESULT ( STDMETHODCALLTYPE *CompareToIWorkItem )( 
            IHsmJobWorkItemPriv * This,
            /* [in] */ IHsmJobWorkItem *pWorkItem,
            /* [out] */ SHORT *pResult);
        
        HRESULT ( STDMETHODCALLTYPE *EnumPhases )( 
            IHsmJobWorkItemPriv * This,
            /* [out] */ IWsbEnum **ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE *EnumTotals )( 
            IHsmJobWorkItemPriv * This,
            /* [out] */ IWsbEnum **ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE *GetCookie )( 
            IHsmJobWorkItemPriv * This,
            /* [out] */ DWORD *pCookie);
        
        HRESULT ( STDMETHODCALLTYPE *GetCurrentPath )( 
            IHsmJobWorkItemPriv * This,
            /* [string][out][in] */ OLECHAR **pString,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetFinishTime )( 
            IHsmJobWorkItemPriv * This,
            /* [out] */ FILETIME *pTime);
        
        HRESULT ( STDMETHODCALLTYPE *GetPhases )( 
            IHsmJobWorkItemPriv * This,
            /* [out] */ IWsbCollection **pPhases);
        
        HRESULT ( STDMETHODCALLTYPE *GetResourceId )( 
            IHsmJobWorkItemPriv * This,
            /* [out] */ GUID *pId);
        
        HRESULT ( STDMETHODCALLTYPE *GetSession )( 
            IHsmJobWorkItemPriv * This,
            /* [out] */ IHsmSession **ppSession);
        
        HRESULT ( STDMETHODCALLTYPE *GetStartingPath )( 
            IHsmJobWorkItemPriv * This,
            /* [string][out][in] */ OLECHAR **pString,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetStartTime )( 
            IHsmJobWorkItemPriv * This,
            /* [out] */ FILETIME *pTime);
        
        HRESULT ( STDMETHODCALLTYPE *GetState )( 
            IHsmJobWorkItemPriv * This,
            /* [out] */ HSM_JOB_STATE *pState);
        
        HRESULT ( STDMETHODCALLTYPE *GetStateAsString )( 
            IHsmJobWorkItemPriv * This,
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetSubRunId )( 
            IHsmJobWorkItemPriv * This,
            /* [out] */ ULONG *pId);
        
        HRESULT ( STDMETHODCALLTYPE *GetTotals )( 
            IHsmJobWorkItemPriv * This,
            /* [out] */ IWsbCollection **pTotals);
        
        HRESULT ( STDMETHODCALLTYPE *Init )( 
            IHsmJobWorkItemPriv * This,
            /* [in] */ IHsmJob *pJob);
        
        HRESULT ( STDMETHODCALLTYPE *SetCookie )( 
            IHsmJobWorkItemPriv * This,
            /* [in] */ DWORD cookie);
        
        HRESULT ( STDMETHODCALLTYPE *SetCurrentPath )( 
            IHsmJobWorkItemPriv * This,
            /* [string][in] */ OLECHAR *string);
        
        HRESULT ( STDMETHODCALLTYPE *SetFinishTime )( 
            IHsmJobWorkItemPriv * This,
            /* [in] */ FILETIME time);
        
        HRESULT ( STDMETHODCALLTYPE *SetResourceId )( 
            IHsmJobWorkItemPriv * This,
            /* [in] */ GUID id);
        
        HRESULT ( STDMETHODCALLTYPE *SetSession )( 
            IHsmJobWorkItemPriv * This,
            /* [in] */ IHsmSession *pSession);
        
        HRESULT ( STDMETHODCALLTYPE *SetStartingPath )( 
            IHsmJobWorkItemPriv * This,
            /* [string][in] */ OLECHAR *string);
        
        HRESULT ( STDMETHODCALLTYPE *SetStartTime )( 
            IHsmJobWorkItemPriv * This,
            /* [in] */ FILETIME time);
        
        HRESULT ( STDMETHODCALLTYPE *SetState )( 
            IHsmJobWorkItemPriv * This,
            /* [in] */ HSM_JOB_STATE state);
        
        HRESULT ( STDMETHODCALLTYPE *SetSubRunId )( 
            IHsmJobWorkItemPriv * This,
            /* [in] */ ULONG id);
        
        HRESULT ( STDMETHODCALLTYPE *IsActiveItem )( 
            IHsmJobWorkItemPriv * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetActiveItem )( 
            IHsmJobWorkItemPriv * This,
            /* [in] */ BOOL bActive);
        
        END_INTERFACE
    } IHsmJobWorkItemPrivVtbl;

    interface IHsmJobWorkItemPriv
    {
        CONST_VTBL struct IHsmJobWorkItemPrivVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHsmJobWorkItemPriv_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHsmJobWorkItemPriv_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHsmJobWorkItemPriv_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHsmJobWorkItemPriv_CompareToResourceId(This,id,pResult)	\
    (This)->lpVtbl -> CompareToResourceId(This,id,pResult)

#define IHsmJobWorkItemPriv_CompareToIWorkItem(This,pWorkItem,pResult)	\
    (This)->lpVtbl -> CompareToIWorkItem(This,pWorkItem,pResult)

#define IHsmJobWorkItemPriv_EnumPhases(This,ppEnum)	\
    (This)->lpVtbl -> EnumPhases(This,ppEnum)

#define IHsmJobWorkItemPriv_EnumTotals(This,ppEnum)	\
    (This)->lpVtbl -> EnumTotals(This,ppEnum)

#define IHsmJobWorkItemPriv_GetCookie(This,pCookie)	\
    (This)->lpVtbl -> GetCookie(This,pCookie)

#define IHsmJobWorkItemPriv_GetCurrentPath(This,pString,bufferSize)	\
    (This)->lpVtbl -> GetCurrentPath(This,pString,bufferSize)

#define IHsmJobWorkItemPriv_GetFinishTime(This,pTime)	\
    (This)->lpVtbl -> GetFinishTime(This,pTime)

#define IHsmJobWorkItemPriv_GetPhases(This,pPhases)	\
    (This)->lpVtbl -> GetPhases(This,pPhases)

#define IHsmJobWorkItemPriv_GetResourceId(This,pId)	\
    (This)->lpVtbl -> GetResourceId(This,pId)

#define IHsmJobWorkItemPriv_GetSession(This,ppSession)	\
    (This)->lpVtbl -> GetSession(This,ppSession)

#define IHsmJobWorkItemPriv_GetStartingPath(This,pString,bufferSize)	\
    (This)->lpVtbl -> GetStartingPath(This,pString,bufferSize)

#define IHsmJobWorkItemPriv_GetStartTime(This,pTime)	\
    (This)->lpVtbl -> GetStartTime(This,pTime)

#define IHsmJobWorkItemPriv_GetState(This,pState)	\
    (This)->lpVtbl -> GetState(This,pState)

#define IHsmJobWorkItemPriv_GetStateAsString(This,pName,bufferSize)	\
    (This)->lpVtbl -> GetStateAsString(This,pName,bufferSize)

#define IHsmJobWorkItemPriv_GetSubRunId(This,pId)	\
    (This)->lpVtbl -> GetSubRunId(This,pId)

#define IHsmJobWorkItemPriv_GetTotals(This,pTotals)	\
    (This)->lpVtbl -> GetTotals(This,pTotals)

#define IHsmJobWorkItemPriv_Init(This,pJob)	\
    (This)->lpVtbl -> Init(This,pJob)

#define IHsmJobWorkItemPriv_SetCookie(This,cookie)	\
    (This)->lpVtbl -> SetCookie(This,cookie)

#define IHsmJobWorkItemPriv_SetCurrentPath(This,string)	\
    (This)->lpVtbl -> SetCurrentPath(This,string)

#define IHsmJobWorkItemPriv_SetFinishTime(This,time)	\
    (This)->lpVtbl -> SetFinishTime(This,time)

#define IHsmJobWorkItemPriv_SetResourceId(This,id)	\
    (This)->lpVtbl -> SetResourceId(This,id)

#define IHsmJobWorkItemPriv_SetSession(This,pSession)	\
    (This)->lpVtbl -> SetSession(This,pSession)

#define IHsmJobWorkItemPriv_SetStartingPath(This,string)	\
    (This)->lpVtbl -> SetStartingPath(This,string)

#define IHsmJobWorkItemPriv_SetStartTime(This,time)	\
    (This)->lpVtbl -> SetStartTime(This,time)

#define IHsmJobWorkItemPriv_SetState(This,state)	\
    (This)->lpVtbl -> SetState(This,state)

#define IHsmJobWorkItemPriv_SetSubRunId(This,id)	\
    (This)->lpVtbl -> SetSubRunId(This,id)

#define IHsmJobWorkItemPriv_IsActiveItem(This)	\
    (This)->lpVtbl -> IsActiveItem(This)

#define IHsmJobWorkItemPriv_SetActiveItem(This,bActive)	\
    (This)->lpVtbl -> SetActiveItem(This,bActive)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IHsmJobWorkItemPriv_CompareToResourceId_Proxy( 
    IHsmJobWorkItemPriv * This,
    /* [in] */ GUID id,
    /* [out] */ SHORT *pResult);


void __RPC_STUB IHsmJobWorkItemPriv_CompareToResourceId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobWorkItemPriv_CompareToIWorkItem_Proxy( 
    IHsmJobWorkItemPriv * This,
    /* [in] */ IHsmJobWorkItem *pWorkItem,
    /* [out] */ SHORT *pResult);


void __RPC_STUB IHsmJobWorkItemPriv_CompareToIWorkItem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobWorkItemPriv_EnumPhases_Proxy( 
    IHsmJobWorkItemPriv * This,
    /* [out] */ IWsbEnum **ppEnum);


void __RPC_STUB IHsmJobWorkItemPriv_EnumPhases_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobWorkItemPriv_EnumTotals_Proxy( 
    IHsmJobWorkItemPriv * This,
    /* [out] */ IWsbEnum **ppEnum);


void __RPC_STUB IHsmJobWorkItemPriv_EnumTotals_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobWorkItemPriv_GetCookie_Proxy( 
    IHsmJobWorkItemPriv * This,
    /* [out] */ DWORD *pCookie);


void __RPC_STUB IHsmJobWorkItemPriv_GetCookie_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobWorkItemPriv_GetCurrentPath_Proxy( 
    IHsmJobWorkItemPriv * This,
    /* [string][out][in] */ OLECHAR **pString,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IHsmJobWorkItemPriv_GetCurrentPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobWorkItemPriv_GetFinishTime_Proxy( 
    IHsmJobWorkItemPriv * This,
    /* [out] */ FILETIME *pTime);


void __RPC_STUB IHsmJobWorkItemPriv_GetFinishTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobWorkItemPriv_GetPhases_Proxy( 
    IHsmJobWorkItemPriv * This,
    /* [out] */ IWsbCollection **pPhases);


void __RPC_STUB IHsmJobWorkItemPriv_GetPhases_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobWorkItemPriv_GetResourceId_Proxy( 
    IHsmJobWorkItemPriv * This,
    /* [out] */ GUID *pId);


void __RPC_STUB IHsmJobWorkItemPriv_GetResourceId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobWorkItemPriv_GetSession_Proxy( 
    IHsmJobWorkItemPriv * This,
    /* [out] */ IHsmSession **ppSession);


void __RPC_STUB IHsmJobWorkItemPriv_GetSession_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobWorkItemPriv_GetStartingPath_Proxy( 
    IHsmJobWorkItemPriv * This,
    /* [string][out][in] */ OLECHAR **pString,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IHsmJobWorkItemPriv_GetStartingPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobWorkItemPriv_GetStartTime_Proxy( 
    IHsmJobWorkItemPriv * This,
    /* [out] */ FILETIME *pTime);


void __RPC_STUB IHsmJobWorkItemPriv_GetStartTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobWorkItemPriv_GetState_Proxy( 
    IHsmJobWorkItemPriv * This,
    /* [out] */ HSM_JOB_STATE *pState);


void __RPC_STUB IHsmJobWorkItemPriv_GetState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobWorkItemPriv_GetStateAsString_Proxy( 
    IHsmJobWorkItemPriv * This,
    /* [string][out][in] */ OLECHAR **pName,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IHsmJobWorkItemPriv_GetStateAsString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobWorkItemPriv_GetSubRunId_Proxy( 
    IHsmJobWorkItemPriv * This,
    /* [out] */ ULONG *pId);


void __RPC_STUB IHsmJobWorkItemPriv_GetSubRunId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobWorkItemPriv_GetTotals_Proxy( 
    IHsmJobWorkItemPriv * This,
    /* [out] */ IWsbCollection **pTotals);


void __RPC_STUB IHsmJobWorkItemPriv_GetTotals_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobWorkItemPriv_Init_Proxy( 
    IHsmJobWorkItemPriv * This,
    /* [in] */ IHsmJob *pJob);


void __RPC_STUB IHsmJobWorkItemPriv_Init_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobWorkItemPriv_SetCookie_Proxy( 
    IHsmJobWorkItemPriv * This,
    /* [in] */ DWORD cookie);


void __RPC_STUB IHsmJobWorkItemPriv_SetCookie_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobWorkItemPriv_SetCurrentPath_Proxy( 
    IHsmJobWorkItemPriv * This,
    /* [string][in] */ OLECHAR *string);


void __RPC_STUB IHsmJobWorkItemPriv_SetCurrentPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobWorkItemPriv_SetFinishTime_Proxy( 
    IHsmJobWorkItemPriv * This,
    /* [in] */ FILETIME time);


void __RPC_STUB IHsmJobWorkItemPriv_SetFinishTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobWorkItemPriv_SetResourceId_Proxy( 
    IHsmJobWorkItemPriv * This,
    /* [in] */ GUID id);


void __RPC_STUB IHsmJobWorkItemPriv_SetResourceId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobWorkItemPriv_SetSession_Proxy( 
    IHsmJobWorkItemPriv * This,
    /* [in] */ IHsmSession *pSession);


void __RPC_STUB IHsmJobWorkItemPriv_SetSession_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobWorkItemPriv_SetStartingPath_Proxy( 
    IHsmJobWorkItemPriv * This,
    /* [string][in] */ OLECHAR *string);


void __RPC_STUB IHsmJobWorkItemPriv_SetStartingPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobWorkItemPriv_SetStartTime_Proxy( 
    IHsmJobWorkItemPriv * This,
    /* [in] */ FILETIME time);


void __RPC_STUB IHsmJobWorkItemPriv_SetStartTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobWorkItemPriv_SetState_Proxy( 
    IHsmJobWorkItemPriv * This,
    /* [in] */ HSM_JOB_STATE state);


void __RPC_STUB IHsmJobWorkItemPriv_SetState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobWorkItemPriv_SetSubRunId_Proxy( 
    IHsmJobWorkItemPriv * This,
    /* [in] */ ULONG id);


void __RPC_STUB IHsmJobWorkItemPriv_SetSubRunId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobWorkItemPriv_IsActiveItem_Proxy( 
    IHsmJobWorkItemPriv * This);


void __RPC_STUB IHsmJobWorkItemPriv_IsActiveItem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobWorkItemPriv_SetActiveItem_Proxy( 
    IHsmJobWorkItemPriv * This,
    /* [in] */ BOOL bActive);


void __RPC_STUB IHsmJobWorkItemPriv_SetActiveItem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IHsmJobWorkItemPriv_INTERFACE_DEFINED__ */


#ifndef __IHsmPhasePriv_INTERFACE_DEFINED__
#define __IHsmPhasePriv_INTERFACE_DEFINED__

/* interface IHsmPhasePriv */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IHsmPhasePriv;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("35035911-0D1C-11d2-9B0C-00104B9A2869")
    IHsmPhasePriv : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AddItem( 
            /* [in] */ IFsaScanItem *pItem,
            /* [in] */ HRESULT itemHr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IHsmPhasePriv **ppPhasePriv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CopyTo( 
            /* [in] */ IHsmPhasePriv *pPhasePriv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetElapsedTime( 
            /* [out] */ ULONG *pDays,
            /* [out] */ USHORT *pHours,
            /* [out] */ USHORT *pMinutes,
            /* [out] */ USHORT *pSeconds) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMediaState( 
            /* [out] */ HSM_JOB_MEDIA_STATE *pState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMediaStateAsString( 
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetName( 
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPhase( 
            HSM_JOB_PHASE *pPhase) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPriority( 
            /* [out] */ HSM_JOB_PRIORITY *pPriority) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPriorityAsString( 
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetState( 
            /* [out] */ HSM_JOB_STATE *pState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStateAsString( 
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStats( 
            /* [out] */ LONGLONG *items,
            /* [out] */ LONGLONG *size,
            /* [out] */ LONGLONG *skippedItems,
            /* [out] */ LONGLONG *skippedSize,
            /* [out] */ LONGLONG *errorItems,
            /* [out] */ LONGLONG *errorSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStartTime( 
            /* [out] */ FILETIME *pTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStopTime( 
            /* [out] */ FILETIME *pTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetInternalStuff( 
            /* [in] */ ULONG mountCount,
            /* [in] */ ULONG transferCount,
            /* [in] */ LONGLONG elapsedTime,
            /* [in] */ FILETIME startTime,
            /* [in] */ FILETIME restartTime,
            /* [in] */ FILETIME stopTime) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMediaState( 
            /* [in] */ HSM_JOB_MEDIA_STATE state) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPhase( 
            /* [in] */ HSM_JOB_PHASE phase) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPriority( 
            /* [in] */ HSM_JOB_PRIORITY priority) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetState( 
            /* [in] */ HSM_JOB_STATE state) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetStats( 
            /* [in] */ LONGLONG items,
            /* [in] */ LONGLONG size,
            /* [in] */ LONGLONG skippedItems,
            /* [in] */ LONGLONG skippedSize,
            /* [in] */ LONGLONG errorItems,
            /* [in] */ LONGLONG errorSize) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHsmPhasePrivVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHsmPhasePriv * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHsmPhasePriv * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHsmPhasePriv * This);
        
        HRESULT ( STDMETHODCALLTYPE *AddItem )( 
            IHsmPhasePriv * This,
            /* [in] */ IFsaScanItem *pItem,
            /* [in] */ HRESULT itemHr);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IHsmPhasePriv * This,
            /* [out] */ IHsmPhasePriv **ppPhasePriv);
        
        HRESULT ( STDMETHODCALLTYPE *CopyTo )( 
            IHsmPhasePriv * This,
            /* [in] */ IHsmPhasePriv *pPhasePriv);
        
        HRESULT ( STDMETHODCALLTYPE *GetElapsedTime )( 
            IHsmPhasePriv * This,
            /* [out] */ ULONG *pDays,
            /* [out] */ USHORT *pHours,
            /* [out] */ USHORT *pMinutes,
            /* [out] */ USHORT *pSeconds);
        
        HRESULT ( STDMETHODCALLTYPE *GetMediaState )( 
            IHsmPhasePriv * This,
            /* [out] */ HSM_JOB_MEDIA_STATE *pState);
        
        HRESULT ( STDMETHODCALLTYPE *GetMediaStateAsString )( 
            IHsmPhasePriv * This,
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetName )( 
            IHsmPhasePriv * This,
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetPhase )( 
            IHsmPhasePriv * This,
            HSM_JOB_PHASE *pPhase);
        
        HRESULT ( STDMETHODCALLTYPE *GetPriority )( 
            IHsmPhasePriv * This,
            /* [out] */ HSM_JOB_PRIORITY *pPriority);
        
        HRESULT ( STDMETHODCALLTYPE *GetPriorityAsString )( 
            IHsmPhasePriv * This,
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetState )( 
            IHsmPhasePriv * This,
            /* [out] */ HSM_JOB_STATE *pState);
        
        HRESULT ( STDMETHODCALLTYPE *GetStateAsString )( 
            IHsmPhasePriv * This,
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetStats )( 
            IHsmPhasePriv * This,
            /* [out] */ LONGLONG *items,
            /* [out] */ LONGLONG *size,
            /* [out] */ LONGLONG *skippedItems,
            /* [out] */ LONGLONG *skippedSize,
            /* [out] */ LONGLONG *errorItems,
            /* [out] */ LONGLONG *errorSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetStartTime )( 
            IHsmPhasePriv * This,
            /* [out] */ FILETIME *pTime);
        
        HRESULT ( STDMETHODCALLTYPE *GetStopTime )( 
            IHsmPhasePriv * This,
            /* [out] */ FILETIME *pTime);
        
        HRESULT ( STDMETHODCALLTYPE *SetInternalStuff )( 
            IHsmPhasePriv * This,
            /* [in] */ ULONG mountCount,
            /* [in] */ ULONG transferCount,
            /* [in] */ LONGLONG elapsedTime,
            /* [in] */ FILETIME startTime,
            /* [in] */ FILETIME restartTime,
            /* [in] */ FILETIME stopTime);
        
        HRESULT ( STDMETHODCALLTYPE *SetMediaState )( 
            IHsmPhasePriv * This,
            /* [in] */ HSM_JOB_MEDIA_STATE state);
        
        HRESULT ( STDMETHODCALLTYPE *SetPhase )( 
            IHsmPhasePriv * This,
            /* [in] */ HSM_JOB_PHASE phase);
        
        HRESULT ( STDMETHODCALLTYPE *SetPriority )( 
            IHsmPhasePriv * This,
            /* [in] */ HSM_JOB_PRIORITY priority);
        
        HRESULT ( STDMETHODCALLTYPE *SetState )( 
            IHsmPhasePriv * This,
            /* [in] */ HSM_JOB_STATE state);
        
        HRESULT ( STDMETHODCALLTYPE *SetStats )( 
            IHsmPhasePriv * This,
            /* [in] */ LONGLONG items,
            /* [in] */ LONGLONG size,
            /* [in] */ LONGLONG skippedItems,
            /* [in] */ LONGLONG skippedSize,
            /* [in] */ LONGLONG errorItems,
            /* [in] */ LONGLONG errorSize);
        
        END_INTERFACE
    } IHsmPhasePrivVtbl;

    interface IHsmPhasePriv
    {
        CONST_VTBL struct IHsmPhasePrivVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHsmPhasePriv_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHsmPhasePriv_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHsmPhasePriv_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHsmPhasePriv_AddItem(This,pItem,itemHr)	\
    (This)->lpVtbl -> AddItem(This,pItem,itemHr)

#define IHsmPhasePriv_Clone(This,ppPhasePriv)	\
    (This)->lpVtbl -> Clone(This,ppPhasePriv)

#define IHsmPhasePriv_CopyTo(This,pPhasePriv)	\
    (This)->lpVtbl -> CopyTo(This,pPhasePriv)

#define IHsmPhasePriv_GetElapsedTime(This,pDays,pHours,pMinutes,pSeconds)	\
    (This)->lpVtbl -> GetElapsedTime(This,pDays,pHours,pMinutes,pSeconds)

#define IHsmPhasePriv_GetMediaState(This,pState)	\
    (This)->lpVtbl -> GetMediaState(This,pState)

#define IHsmPhasePriv_GetMediaStateAsString(This,pName,bufferSize)	\
    (This)->lpVtbl -> GetMediaStateAsString(This,pName,bufferSize)

#define IHsmPhasePriv_GetName(This,pName,bufferSize)	\
    (This)->lpVtbl -> GetName(This,pName,bufferSize)

#define IHsmPhasePriv_GetPhase(This,pPhase)	\
    (This)->lpVtbl -> GetPhase(This,pPhase)

#define IHsmPhasePriv_GetPriority(This,pPriority)	\
    (This)->lpVtbl -> GetPriority(This,pPriority)

#define IHsmPhasePriv_GetPriorityAsString(This,pName,bufferSize)	\
    (This)->lpVtbl -> GetPriorityAsString(This,pName,bufferSize)

#define IHsmPhasePriv_GetState(This,pState)	\
    (This)->lpVtbl -> GetState(This,pState)

#define IHsmPhasePriv_GetStateAsString(This,pName,bufferSize)	\
    (This)->lpVtbl -> GetStateAsString(This,pName,bufferSize)

#define IHsmPhasePriv_GetStats(This,items,size,skippedItems,skippedSize,errorItems,errorSize)	\
    (This)->lpVtbl -> GetStats(This,items,size,skippedItems,skippedSize,errorItems,errorSize)

#define IHsmPhasePriv_GetStartTime(This,pTime)	\
    (This)->lpVtbl -> GetStartTime(This,pTime)

#define IHsmPhasePriv_GetStopTime(This,pTime)	\
    (This)->lpVtbl -> GetStopTime(This,pTime)

#define IHsmPhasePriv_SetInternalStuff(This,mountCount,transferCount,elapsedTime,startTime,restartTime,stopTime)	\
    (This)->lpVtbl -> SetInternalStuff(This,mountCount,transferCount,elapsedTime,startTime,restartTime,stopTime)

#define IHsmPhasePriv_SetMediaState(This,state)	\
    (This)->lpVtbl -> SetMediaState(This,state)

#define IHsmPhasePriv_SetPhase(This,phase)	\
    (This)->lpVtbl -> SetPhase(This,phase)

#define IHsmPhasePriv_SetPriority(This,priority)	\
    (This)->lpVtbl -> SetPriority(This,priority)

#define IHsmPhasePriv_SetState(This,state)	\
    (This)->lpVtbl -> SetState(This,state)

#define IHsmPhasePriv_SetStats(This,items,size,skippedItems,skippedSize,errorItems,errorSize)	\
    (This)->lpVtbl -> SetStats(This,items,size,skippedItems,skippedSize,errorItems,errorSize)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IHsmPhasePriv_AddItem_Proxy( 
    IHsmPhasePriv * This,
    /* [in] */ IFsaScanItem *pItem,
    /* [in] */ HRESULT itemHr);


void __RPC_STUB IHsmPhasePriv_AddItem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmPhasePriv_Clone_Proxy( 
    IHsmPhasePriv * This,
    /* [out] */ IHsmPhasePriv **ppPhasePriv);


void __RPC_STUB IHsmPhasePriv_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmPhasePriv_CopyTo_Proxy( 
    IHsmPhasePriv * This,
    /* [in] */ IHsmPhasePriv *pPhasePriv);


void __RPC_STUB IHsmPhasePriv_CopyTo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmPhasePriv_GetElapsedTime_Proxy( 
    IHsmPhasePriv * This,
    /* [out] */ ULONG *pDays,
    /* [out] */ USHORT *pHours,
    /* [out] */ USHORT *pMinutes,
    /* [out] */ USHORT *pSeconds);


void __RPC_STUB IHsmPhasePriv_GetElapsedTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmPhasePriv_GetMediaState_Proxy( 
    IHsmPhasePriv * This,
    /* [out] */ HSM_JOB_MEDIA_STATE *pState);


void __RPC_STUB IHsmPhasePriv_GetMediaState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmPhasePriv_GetMediaStateAsString_Proxy( 
    IHsmPhasePriv * This,
    /* [string][out][in] */ OLECHAR **pName,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IHsmPhasePriv_GetMediaStateAsString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmPhasePriv_GetName_Proxy( 
    IHsmPhasePriv * This,
    /* [string][out][in] */ OLECHAR **pName,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IHsmPhasePriv_GetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmPhasePriv_GetPhase_Proxy( 
    IHsmPhasePriv * This,
    HSM_JOB_PHASE *pPhase);


void __RPC_STUB IHsmPhasePriv_GetPhase_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmPhasePriv_GetPriority_Proxy( 
    IHsmPhasePriv * This,
    /* [out] */ HSM_JOB_PRIORITY *pPriority);


void __RPC_STUB IHsmPhasePriv_GetPriority_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmPhasePriv_GetPriorityAsString_Proxy( 
    IHsmPhasePriv * This,
    /* [string][out][in] */ OLECHAR **pName,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IHsmPhasePriv_GetPriorityAsString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmPhasePriv_GetState_Proxy( 
    IHsmPhasePriv * This,
    /* [out] */ HSM_JOB_STATE *pState);


void __RPC_STUB IHsmPhasePriv_GetState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmPhasePriv_GetStateAsString_Proxy( 
    IHsmPhasePriv * This,
    /* [string][out][in] */ OLECHAR **pName,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IHsmPhasePriv_GetStateAsString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmPhasePriv_GetStats_Proxy( 
    IHsmPhasePriv * This,
    /* [out] */ LONGLONG *items,
    /* [out] */ LONGLONG *size,
    /* [out] */ LONGLONG *skippedItems,
    /* [out] */ LONGLONG *skippedSize,
    /* [out] */ LONGLONG *errorItems,
    /* [out] */ LONGLONG *errorSize);


void __RPC_STUB IHsmPhasePriv_GetStats_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmPhasePriv_GetStartTime_Proxy( 
    IHsmPhasePriv * This,
    /* [out] */ FILETIME *pTime);


void __RPC_STUB IHsmPhasePriv_GetStartTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmPhasePriv_GetStopTime_Proxy( 
    IHsmPhasePriv * This,
    /* [out] */ FILETIME *pTime);


void __RPC_STUB IHsmPhasePriv_GetStopTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmPhasePriv_SetInternalStuff_Proxy( 
    IHsmPhasePriv * This,
    /* [in] */ ULONG mountCount,
    /* [in] */ ULONG transferCount,
    /* [in] */ LONGLONG elapsedTime,
    /* [in] */ FILETIME startTime,
    /* [in] */ FILETIME restartTime,
    /* [in] */ FILETIME stopTime);


void __RPC_STUB IHsmPhasePriv_SetInternalStuff_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmPhasePriv_SetMediaState_Proxy( 
    IHsmPhasePriv * This,
    /* [in] */ HSM_JOB_MEDIA_STATE state);


void __RPC_STUB IHsmPhasePriv_SetMediaState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmPhasePriv_SetPhase_Proxy( 
    IHsmPhasePriv * This,
    /* [in] */ HSM_JOB_PHASE phase);


void __RPC_STUB IHsmPhasePriv_SetPhase_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmPhasePriv_SetPriority_Proxy( 
    IHsmPhasePriv * This,
    /* [in] */ HSM_JOB_PRIORITY priority);


void __RPC_STUB IHsmPhasePriv_SetPriority_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmPhasePriv_SetState_Proxy( 
    IHsmPhasePriv * This,
    /* [in] */ HSM_JOB_STATE state);


void __RPC_STUB IHsmPhasePriv_SetState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmPhasePriv_SetStats_Proxy( 
    IHsmPhasePriv * This,
    /* [in] */ LONGLONG items,
    /* [in] */ LONGLONG size,
    /* [in] */ LONGLONG skippedItems,
    /* [in] */ LONGLONG skippedSize,
    /* [in] */ LONGLONG errorItems,
    /* [in] */ LONGLONG errorSize);


void __RPC_STUB IHsmPhasePriv_SetStats_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IHsmPhasePriv_INTERFACE_DEFINED__ */


#ifndef __IHsmSessionTotalsPriv_INTERFACE_DEFINED__
#define __IHsmSessionTotalsPriv_INTERFACE_DEFINED__

/* interface IHsmSessionTotalsPriv */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IHsmSessionTotalsPriv;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("35035912-0D1C-11d2-9B0C-00104B9A2869")
    IHsmSessionTotalsPriv : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AddItem( 
            /* [in] */ IFsaScanItem *pItem,
            /* [in] */ HRESULT itemHr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IHsmSessionTotalsPriv **ppSessionTotalsPriv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CopyTo( 
            /* [in] */ IHsmSessionTotalsPriv *pSessionTotalsPriv) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CompareToAction( 
            /* [in] */ HSM_JOB_ACTION action,
            /* [out] */ SHORT *pResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CompareToISessionTotals( 
            /* [in] */ IHsmSessionTotals *pTotals,
            /* [out] */ SHORT *pResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAction( 
            /* [out] */ HSM_JOB_ACTION *pAction) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetName( 
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStats( 
            /* [out] */ LONGLONG *items,
            /* [out] */ LONGLONG *size,
            /* [out] */ LONGLONG *skippedItems,
            /* [out] */ LONGLONG *skippedSize,
            /* [out] */ LONGLONG *errorItems,
            /* [out] */ LONGLONG *errorSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAction( 
            /* [in] */ HSM_JOB_ACTION action) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetStats( 
            /* [in] */ LONGLONG items,
            /* [in] */ LONGLONG size,
            /* [in] */ LONGLONG skippedItems,
            /* [in] */ LONGLONG skippedSize,
            /* [in] */ LONGLONG errorItems,
            /* [in] */ LONGLONG errorSize) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHsmSessionTotalsPrivVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHsmSessionTotalsPriv * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHsmSessionTotalsPriv * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHsmSessionTotalsPriv * This);
        
        HRESULT ( STDMETHODCALLTYPE *AddItem )( 
            IHsmSessionTotalsPriv * This,
            /* [in] */ IFsaScanItem *pItem,
            /* [in] */ HRESULT itemHr);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IHsmSessionTotalsPriv * This,
            /* [out] */ IHsmSessionTotalsPriv **ppSessionTotalsPriv);
        
        HRESULT ( STDMETHODCALLTYPE *CopyTo )( 
            IHsmSessionTotalsPriv * This,
            /* [in] */ IHsmSessionTotalsPriv *pSessionTotalsPriv);
        
        HRESULT ( STDMETHODCALLTYPE *CompareToAction )( 
            IHsmSessionTotalsPriv * This,
            /* [in] */ HSM_JOB_ACTION action,
            /* [out] */ SHORT *pResult);
        
        HRESULT ( STDMETHODCALLTYPE *CompareToISessionTotals )( 
            IHsmSessionTotalsPriv * This,
            /* [in] */ IHsmSessionTotals *pTotals,
            /* [out] */ SHORT *pResult);
        
        HRESULT ( STDMETHODCALLTYPE *GetAction )( 
            IHsmSessionTotalsPriv * This,
            /* [out] */ HSM_JOB_ACTION *pAction);
        
        HRESULT ( STDMETHODCALLTYPE *GetName )( 
            IHsmSessionTotalsPriv * This,
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetStats )( 
            IHsmSessionTotalsPriv * This,
            /* [out] */ LONGLONG *items,
            /* [out] */ LONGLONG *size,
            /* [out] */ LONGLONG *skippedItems,
            /* [out] */ LONGLONG *skippedSize,
            /* [out] */ LONGLONG *errorItems,
            /* [out] */ LONGLONG *errorSize);
        
        HRESULT ( STDMETHODCALLTYPE *SetAction )( 
            IHsmSessionTotalsPriv * This,
            /* [in] */ HSM_JOB_ACTION action);
        
        HRESULT ( STDMETHODCALLTYPE *SetStats )( 
            IHsmSessionTotalsPriv * This,
            /* [in] */ LONGLONG items,
            /* [in] */ LONGLONG size,
            /* [in] */ LONGLONG skippedItems,
            /* [in] */ LONGLONG skippedSize,
            /* [in] */ LONGLONG errorItems,
            /* [in] */ LONGLONG errorSize);
        
        END_INTERFACE
    } IHsmSessionTotalsPrivVtbl;

    interface IHsmSessionTotalsPriv
    {
        CONST_VTBL struct IHsmSessionTotalsPrivVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHsmSessionTotalsPriv_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHsmSessionTotalsPriv_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHsmSessionTotalsPriv_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHsmSessionTotalsPriv_AddItem(This,pItem,itemHr)	\
    (This)->lpVtbl -> AddItem(This,pItem,itemHr)

#define IHsmSessionTotalsPriv_Clone(This,ppSessionTotalsPriv)	\
    (This)->lpVtbl -> Clone(This,ppSessionTotalsPriv)

#define IHsmSessionTotalsPriv_CopyTo(This,pSessionTotalsPriv)	\
    (This)->lpVtbl -> CopyTo(This,pSessionTotalsPriv)

#define IHsmSessionTotalsPriv_CompareToAction(This,action,pResult)	\
    (This)->lpVtbl -> CompareToAction(This,action,pResult)

#define IHsmSessionTotalsPriv_CompareToISessionTotals(This,pTotals,pResult)	\
    (This)->lpVtbl -> CompareToISessionTotals(This,pTotals,pResult)

#define IHsmSessionTotalsPriv_GetAction(This,pAction)	\
    (This)->lpVtbl -> GetAction(This,pAction)

#define IHsmSessionTotalsPriv_GetName(This,pName,bufferSize)	\
    (This)->lpVtbl -> GetName(This,pName,bufferSize)

#define IHsmSessionTotalsPriv_GetStats(This,items,size,skippedItems,skippedSize,errorItems,errorSize)	\
    (This)->lpVtbl -> GetStats(This,items,size,skippedItems,skippedSize,errorItems,errorSize)

#define IHsmSessionTotalsPriv_SetAction(This,action)	\
    (This)->lpVtbl -> SetAction(This,action)

#define IHsmSessionTotalsPriv_SetStats(This,items,size,skippedItems,skippedSize,errorItems,errorSize)	\
    (This)->lpVtbl -> SetStats(This,items,size,skippedItems,skippedSize,errorItems,errorSize)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IHsmSessionTotalsPriv_AddItem_Proxy( 
    IHsmSessionTotalsPriv * This,
    /* [in] */ IFsaScanItem *pItem,
    /* [in] */ HRESULT itemHr);


void __RPC_STUB IHsmSessionTotalsPriv_AddItem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmSessionTotalsPriv_Clone_Proxy( 
    IHsmSessionTotalsPriv * This,
    /* [out] */ IHsmSessionTotalsPriv **ppSessionTotalsPriv);


void __RPC_STUB IHsmSessionTotalsPriv_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmSessionTotalsPriv_CopyTo_Proxy( 
    IHsmSessionTotalsPriv * This,
    /* [in] */ IHsmSessionTotalsPriv *pSessionTotalsPriv);


void __RPC_STUB IHsmSessionTotalsPriv_CopyTo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmSessionTotalsPriv_CompareToAction_Proxy( 
    IHsmSessionTotalsPriv * This,
    /* [in] */ HSM_JOB_ACTION action,
    /* [out] */ SHORT *pResult);


void __RPC_STUB IHsmSessionTotalsPriv_CompareToAction_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmSessionTotalsPriv_CompareToISessionTotals_Proxy( 
    IHsmSessionTotalsPriv * This,
    /* [in] */ IHsmSessionTotals *pTotals,
    /* [out] */ SHORT *pResult);


void __RPC_STUB IHsmSessionTotalsPriv_CompareToISessionTotals_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmSessionTotalsPriv_GetAction_Proxy( 
    IHsmSessionTotalsPriv * This,
    /* [out] */ HSM_JOB_ACTION *pAction);


void __RPC_STUB IHsmSessionTotalsPriv_GetAction_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmSessionTotalsPriv_GetName_Proxy( 
    IHsmSessionTotalsPriv * This,
    /* [string][out][in] */ OLECHAR **pName,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IHsmSessionTotalsPriv_GetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmSessionTotalsPriv_GetStats_Proxy( 
    IHsmSessionTotalsPriv * This,
    /* [out] */ LONGLONG *items,
    /* [out] */ LONGLONG *size,
    /* [out] */ LONGLONG *skippedItems,
    /* [out] */ LONGLONG *skippedSize,
    /* [out] */ LONGLONG *errorItems,
    /* [out] */ LONGLONG *errorSize);


void __RPC_STUB IHsmSessionTotalsPriv_GetStats_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmSessionTotalsPriv_SetAction_Proxy( 
    IHsmSessionTotalsPriv * This,
    /* [in] */ HSM_JOB_ACTION action);


void __RPC_STUB IHsmSessionTotalsPriv_SetAction_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmSessionTotalsPriv_SetStats_Proxy( 
    IHsmSessionTotalsPriv * This,
    /* [in] */ LONGLONG items,
    /* [in] */ LONGLONG size,
    /* [in] */ LONGLONG skippedItems,
    /* [in] */ LONGLONG skippedSize,
    /* [in] */ LONGLONG errorItems,
    /* [in] */ LONGLONG errorSize);


void __RPC_STUB IHsmSessionTotalsPriv_SetStats_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IHsmSessionTotalsPriv_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


