

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for jobint.idl:
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

#ifndef __jobint_h__
#define __jobint_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IHsmAction_FWD_DEFINED__
#define __IHsmAction_FWD_DEFINED__
typedef interface IHsmAction IHsmAction;
#endif 	/* __IHsmAction_FWD_DEFINED__ */


#ifndef __IHsmActionOnResource_FWD_DEFINED__
#define __IHsmActionOnResource_FWD_DEFINED__
typedef interface IHsmActionOnResource IHsmActionOnResource;
#endif 	/* __IHsmActionOnResource_FWD_DEFINED__ */


#ifndef __IHsmActionOnResourcePost_FWD_DEFINED__
#define __IHsmActionOnResourcePost_FWD_DEFINED__
typedef interface IHsmActionOnResourcePost IHsmActionOnResourcePost;
#endif 	/* __IHsmActionOnResourcePost_FWD_DEFINED__ */


#ifndef __IHsmActionOnResourcePre_FWD_DEFINED__
#define __IHsmActionOnResourcePre_FWD_DEFINED__
typedef interface IHsmActionOnResourcePre IHsmActionOnResourcePre;
#endif 	/* __IHsmActionOnResourcePre_FWD_DEFINED__ */


#ifndef __IHsmActionOnResourcePreScan_FWD_DEFINED__
#define __IHsmActionOnResourcePreScan_FWD_DEFINED__
typedef interface IHsmActionOnResourcePreScan IHsmActionOnResourcePreScan;
#endif 	/* __IHsmActionOnResourcePreScan_FWD_DEFINED__ */


#ifndef __IHsmCriteria_FWD_DEFINED__
#define __IHsmCriteria_FWD_DEFINED__
typedef interface IHsmCriteria IHsmCriteria;
#endif 	/* __IHsmCriteria_FWD_DEFINED__ */


#ifndef __IHsmRelativeCriteria_FWD_DEFINED__
#define __IHsmRelativeCriteria_FWD_DEFINED__
typedef interface IHsmRelativeCriteria IHsmRelativeCriteria;
#endif 	/* __IHsmRelativeCriteria_FWD_DEFINED__ */


#ifndef __IHsmDirectedAction_FWD_DEFINED__
#define __IHsmDirectedAction_FWD_DEFINED__
typedef interface IHsmDirectedAction IHsmDirectedAction;
#endif 	/* __IHsmDirectedAction_FWD_DEFINED__ */


#ifndef __IHsmJob_FWD_DEFINED__
#define __IHsmJob_FWD_DEFINED__
typedef interface IHsmJob IHsmJob;
#endif 	/* __IHsmJob_FWD_DEFINED__ */


#ifndef __IHsmJobContext_FWD_DEFINED__
#define __IHsmJobContext_FWD_DEFINED__
typedef interface IHsmJobContext IHsmJobContext;
#endif 	/* __IHsmJobContext_FWD_DEFINED__ */


#ifndef __IHsmJobDef_FWD_DEFINED__
#define __IHsmJobDef_FWD_DEFINED__
typedef interface IHsmJobDef IHsmJobDef;
#endif 	/* __IHsmJobDef_FWD_DEFINED__ */


#ifndef __IHsmJobSinkEverySession_FWD_DEFINED__
#define __IHsmJobSinkEverySession_FWD_DEFINED__
typedef interface IHsmJobSinkEverySession IHsmJobSinkEverySession;
#endif 	/* __IHsmJobSinkEverySession_FWD_DEFINED__ */


#ifndef __IHsmJobWorkItem_FWD_DEFINED__
#define __IHsmJobWorkItem_FWD_DEFINED__
typedef interface IHsmJobWorkItem IHsmJobWorkItem;
#endif 	/* __IHsmJobWorkItem_FWD_DEFINED__ */


#ifndef __IHsmPhase_FWD_DEFINED__
#define __IHsmPhase_FWD_DEFINED__
typedef interface IHsmPhase IHsmPhase;
#endif 	/* __IHsmPhase_FWD_DEFINED__ */


#ifndef __IHsmPolicy_FWD_DEFINED__
#define __IHsmPolicy_FWD_DEFINED__
typedef interface IHsmPolicy IHsmPolicy;
#endif 	/* __IHsmPolicy_FWD_DEFINED__ */


#ifndef __IHsmRelocateAction_FWD_DEFINED__
#define __IHsmRelocateAction_FWD_DEFINED__
typedef interface IHsmRelocateAction IHsmRelocateAction;
#endif 	/* __IHsmRelocateAction_FWD_DEFINED__ */


#ifndef __IHsmRule_FWD_DEFINED__
#define __IHsmRule_FWD_DEFINED__
typedef interface IHsmRule IHsmRule;
#endif 	/* __IHsmRule_FWD_DEFINED__ */


#ifndef __IHsmRuleStack_FWD_DEFINED__
#define __IHsmRuleStack_FWD_DEFINED__
typedef interface IHsmRuleStack IHsmRuleStack;
#endif 	/* __IHsmRuleStack_FWD_DEFINED__ */


#ifndef __IHsmScanner_FWD_DEFINED__
#define __IHsmScanner_FWD_DEFINED__
typedef interface IHsmScanner IHsmScanner;
#endif 	/* __IHsmScanner_FWD_DEFINED__ */


#ifndef __IHsmSession_FWD_DEFINED__
#define __IHsmSession_FWD_DEFINED__
typedef interface IHsmSession IHsmSession;
#endif 	/* __IHsmSession_FWD_DEFINED__ */


#ifndef __IHsmSessionSinkEveryEvent_FWD_DEFINED__
#define __IHsmSessionSinkEveryEvent_FWD_DEFINED__
typedef interface IHsmSessionSinkEveryEvent IHsmSessionSinkEveryEvent;
#endif 	/* __IHsmSessionSinkEveryEvent_FWD_DEFINED__ */


#ifndef __IHsmSessionSinkEveryItem_FWD_DEFINED__
#define __IHsmSessionSinkEveryItem_FWD_DEFINED__
typedef interface IHsmSessionSinkEveryItem IHsmSessionSinkEveryItem;
#endif 	/* __IHsmSessionSinkEveryItem_FWD_DEFINED__ */


#ifndef __IHsmSessionSinkEveryMediaState_FWD_DEFINED__
#define __IHsmSessionSinkEveryMediaState_FWD_DEFINED__
typedef interface IHsmSessionSinkEveryMediaState IHsmSessionSinkEveryMediaState;
#endif 	/* __IHsmSessionSinkEveryMediaState_FWD_DEFINED__ */


#ifndef __IHsmSessionSinkEveryPriority_FWD_DEFINED__
#define __IHsmSessionSinkEveryPriority_FWD_DEFINED__
typedef interface IHsmSessionSinkEveryPriority IHsmSessionSinkEveryPriority;
#endif 	/* __IHsmSessionSinkEveryPriority_FWD_DEFINED__ */


#ifndef __IHsmSessionSinkEveryState_FWD_DEFINED__
#define __IHsmSessionSinkEveryState_FWD_DEFINED__
typedef interface IHsmSessionSinkEveryState IHsmSessionSinkEveryState;
#endif 	/* __IHsmSessionSinkEveryState_FWD_DEFINED__ */


#ifndef __IHsmSessionSinkSomeItems_FWD_DEFINED__
#define __IHsmSessionSinkSomeItems_FWD_DEFINED__
typedef interface IHsmSessionSinkSomeItems IHsmSessionSinkSomeItems;
#endif 	/* __IHsmSessionSinkSomeItems_FWD_DEFINED__ */


#ifndef __IHsmSessionTotals_FWD_DEFINED__
#define __IHsmSessionTotals_FWD_DEFINED__
typedef interface IHsmSessionTotals IHsmSessionTotals;
#endif 	/* __IHsmSessionTotals_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "wsbint.h"
#include "fsadef.h"
#include "jobdef.h"
#include "fsaint.h"
#include "hsmeng.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

/* interface __MIDL_itf_jobint_0000 */
/* [local] */ 



























extern RPC_IF_HANDLE __MIDL_itf_jobint_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_jobint_0000_v0_0_s_ifspec;

#ifndef __IHsmAction_INTERFACE_DEFINED__
#define __IHsmAction_INTERFACE_DEFINED__

/* interface IHsmAction */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IHsmAction;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AD402351-00FC-11D0-819C-00A0C91180F2")
    IHsmAction : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetName( 
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Do( 
            /* [in] */ IFsaScanItem *pScanItem) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHsmActionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHsmAction * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHsmAction * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHsmAction * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetName )( 
            IHsmAction * This,
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *Do )( 
            IHsmAction * This,
            /* [in] */ IFsaScanItem *pScanItem);
        
        END_INTERFACE
    } IHsmActionVtbl;

    interface IHsmAction
    {
        CONST_VTBL struct IHsmActionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHsmAction_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHsmAction_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHsmAction_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHsmAction_GetName(This,pName,bufferSize)	\
    (This)->lpVtbl -> GetName(This,pName,bufferSize)

#define IHsmAction_Do(This,pScanItem)	\
    (This)->lpVtbl -> Do(This,pScanItem)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IHsmAction_GetName_Proxy( 
    IHsmAction * This,
    /* [string][out][in] */ OLECHAR **pName,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IHsmAction_GetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmAction_Do_Proxy( 
    IHsmAction * This,
    /* [in] */ IFsaScanItem *pScanItem);


void __RPC_STUB IHsmAction_Do_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IHsmAction_INTERFACE_DEFINED__ */


#ifndef __IHsmActionOnResource_INTERFACE_DEFINED__
#define __IHsmActionOnResource_INTERFACE_DEFINED__

/* interface IHsmActionOnResource */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IHsmActionOnResource;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D9E04213-14D7-11d1-9938-0060976A546D")
    IHsmActionOnResource : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetName( 
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHsmActionOnResourceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHsmActionOnResource * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHsmActionOnResource * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHsmActionOnResource * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetName )( 
            IHsmActionOnResource * This,
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize);
        
        END_INTERFACE
    } IHsmActionOnResourceVtbl;

    interface IHsmActionOnResource
    {
        CONST_VTBL struct IHsmActionOnResourceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHsmActionOnResource_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHsmActionOnResource_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHsmActionOnResource_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHsmActionOnResource_GetName(This,pName,bufferSize)	\
    (This)->lpVtbl -> GetName(This,pName,bufferSize)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IHsmActionOnResource_GetName_Proxy( 
    IHsmActionOnResource * This,
    /* [string][out][in] */ OLECHAR **pName,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IHsmActionOnResource_GetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IHsmActionOnResource_INTERFACE_DEFINED__ */


#ifndef __IHsmActionOnResourcePost_INTERFACE_DEFINED__
#define __IHsmActionOnResourcePost_INTERFACE_DEFINED__

/* interface IHsmActionOnResourcePost */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IHsmActionOnResourcePost;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0AD613D1-18BE-11d1-9939-0060976A546D")
    IHsmActionOnResourcePost : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Do( 
            /* [in] */ IHsmJobWorkItem *pWorkItem,
            /* [in] */ HSM_JOB_STATE state) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHsmActionOnResourcePostVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHsmActionOnResourcePost * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHsmActionOnResourcePost * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHsmActionOnResourcePost * This);
        
        HRESULT ( STDMETHODCALLTYPE *Do )( 
            IHsmActionOnResourcePost * This,
            /* [in] */ IHsmJobWorkItem *pWorkItem,
            /* [in] */ HSM_JOB_STATE state);
        
        END_INTERFACE
    } IHsmActionOnResourcePostVtbl;

    interface IHsmActionOnResourcePost
    {
        CONST_VTBL struct IHsmActionOnResourcePostVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHsmActionOnResourcePost_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHsmActionOnResourcePost_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHsmActionOnResourcePost_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHsmActionOnResourcePost_Do(This,pWorkItem,state)	\
    (This)->lpVtbl -> Do(This,pWorkItem,state)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IHsmActionOnResourcePost_Do_Proxy( 
    IHsmActionOnResourcePost * This,
    /* [in] */ IHsmJobWorkItem *pWorkItem,
    /* [in] */ HSM_JOB_STATE state);


void __RPC_STUB IHsmActionOnResourcePost_Do_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IHsmActionOnResourcePost_INTERFACE_DEFINED__ */


#ifndef __IHsmActionOnResourcePre_INTERFACE_DEFINED__
#define __IHsmActionOnResourcePre_INTERFACE_DEFINED__

/* interface IHsmActionOnResourcePre */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IHsmActionOnResourcePre;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FD8D709C-47DD-4D68-BBD5-817EDD934E4B")
    IHsmActionOnResourcePre : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Do( 
            /* [in] */ IHsmJobWorkItem *pWorkItem,
            /* [in] */ IHsmJobDef *pJobDef) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHsmActionOnResourcePreVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHsmActionOnResourcePre * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHsmActionOnResourcePre * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHsmActionOnResourcePre * This);
        
        HRESULT ( STDMETHODCALLTYPE *Do )( 
            IHsmActionOnResourcePre * This,
            /* [in] */ IHsmJobWorkItem *pWorkItem,
            /* [in] */ IHsmJobDef *pJobDef);
        
        END_INTERFACE
    } IHsmActionOnResourcePreVtbl;

    interface IHsmActionOnResourcePre
    {
        CONST_VTBL struct IHsmActionOnResourcePreVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHsmActionOnResourcePre_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHsmActionOnResourcePre_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHsmActionOnResourcePre_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHsmActionOnResourcePre_Do(This,pWorkItem,pJobDef)	\
    (This)->lpVtbl -> Do(This,pWorkItem,pJobDef)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IHsmActionOnResourcePre_Do_Proxy( 
    IHsmActionOnResourcePre * This,
    /* [in] */ IHsmJobWorkItem *pWorkItem,
    /* [in] */ IHsmJobDef *pJobDef);


void __RPC_STUB IHsmActionOnResourcePre_Do_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IHsmActionOnResourcePre_INTERFACE_DEFINED__ */


#ifndef __IHsmActionOnResourcePreScan_INTERFACE_DEFINED__
#define __IHsmActionOnResourcePreScan_INTERFACE_DEFINED__

/* interface IHsmActionOnResourcePreScan */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IHsmActionOnResourcePreScan;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D7619DB3-265E-4796-A98C-F6F28C2A618C")
    IHsmActionOnResourcePreScan : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Do( 
            /* [in] */ IFsaResource *pResource,
            /* [in] */ IHsmSession *pSession) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHsmActionOnResourcePreScanVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHsmActionOnResourcePreScan * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHsmActionOnResourcePreScan * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHsmActionOnResourcePreScan * This);
        
        HRESULT ( STDMETHODCALLTYPE *Do )( 
            IHsmActionOnResourcePreScan * This,
            /* [in] */ IFsaResource *pResource,
            /* [in] */ IHsmSession *pSession);
        
        END_INTERFACE
    } IHsmActionOnResourcePreScanVtbl;

    interface IHsmActionOnResourcePreScan
    {
        CONST_VTBL struct IHsmActionOnResourcePreScanVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHsmActionOnResourcePreScan_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHsmActionOnResourcePreScan_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHsmActionOnResourcePreScan_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHsmActionOnResourcePreScan_Do(This,pResource,pSession)	\
    (This)->lpVtbl -> Do(This,pResource,pSession)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IHsmActionOnResourcePreScan_Do_Proxy( 
    IHsmActionOnResourcePreScan * This,
    /* [in] */ IFsaResource *pResource,
    /* [in] */ IHsmSession *pSession);


void __RPC_STUB IHsmActionOnResourcePreScan_Do_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IHsmActionOnResourcePreScan_INTERFACE_DEFINED__ */


#ifndef __IHsmCriteria_INTERFACE_DEFINED__
#define __IHsmCriteria_INTERFACE_DEFINED__

/* interface IHsmCriteria */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IHsmCriteria;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AD40235B-00FC-11D0-819C-00A0C91180F2")
    IHsmCriteria : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetName( 
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsIgnored( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsNegated( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetIsIgnored( 
            /* [in] */ BOOL isIgnored) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetIsNegated( 
            /* [in] */ BOOL isNegated) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ShouldDo( 
            /* [in] */ IFsaScanItem *pScanItem,
            /* [in] */ USHORT scale) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Value( 
            /* [in] */ IFsaScanItem *pScanItem,
            /* [string][out] */ OLECHAR **value,
            /* [in] */ ULONG bufferSize) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHsmCriteriaVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHsmCriteria * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHsmCriteria * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHsmCriteria * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetName )( 
            IHsmCriteria * This,
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *IsIgnored )( 
            IHsmCriteria * This);
        
        HRESULT ( STDMETHODCALLTYPE *IsNegated )( 
            IHsmCriteria * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetIsIgnored )( 
            IHsmCriteria * This,
            /* [in] */ BOOL isIgnored);
        
        HRESULT ( STDMETHODCALLTYPE *SetIsNegated )( 
            IHsmCriteria * This,
            /* [in] */ BOOL isNegated);
        
        HRESULT ( STDMETHODCALLTYPE *ShouldDo )( 
            IHsmCriteria * This,
            /* [in] */ IFsaScanItem *pScanItem,
            /* [in] */ USHORT scale);
        
        HRESULT ( STDMETHODCALLTYPE *Value )( 
            IHsmCriteria * This,
            /* [in] */ IFsaScanItem *pScanItem,
            /* [string][out] */ OLECHAR **value,
            /* [in] */ ULONG bufferSize);
        
        END_INTERFACE
    } IHsmCriteriaVtbl;

    interface IHsmCriteria
    {
        CONST_VTBL struct IHsmCriteriaVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHsmCriteria_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHsmCriteria_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHsmCriteria_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHsmCriteria_GetName(This,pName,bufferSize)	\
    (This)->lpVtbl -> GetName(This,pName,bufferSize)

#define IHsmCriteria_IsIgnored(This)	\
    (This)->lpVtbl -> IsIgnored(This)

#define IHsmCriteria_IsNegated(This)	\
    (This)->lpVtbl -> IsNegated(This)

#define IHsmCriteria_SetIsIgnored(This,isIgnored)	\
    (This)->lpVtbl -> SetIsIgnored(This,isIgnored)

#define IHsmCriteria_SetIsNegated(This,isNegated)	\
    (This)->lpVtbl -> SetIsNegated(This,isNegated)

#define IHsmCriteria_ShouldDo(This,pScanItem,scale)	\
    (This)->lpVtbl -> ShouldDo(This,pScanItem,scale)

#define IHsmCriteria_Value(This,pScanItem,value,bufferSize)	\
    (This)->lpVtbl -> Value(This,pScanItem,value,bufferSize)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IHsmCriteria_GetName_Proxy( 
    IHsmCriteria * This,
    /* [string][out][in] */ OLECHAR **pName,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IHsmCriteria_GetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmCriteria_IsIgnored_Proxy( 
    IHsmCriteria * This);


void __RPC_STUB IHsmCriteria_IsIgnored_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmCriteria_IsNegated_Proxy( 
    IHsmCriteria * This);


void __RPC_STUB IHsmCriteria_IsNegated_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmCriteria_SetIsIgnored_Proxy( 
    IHsmCriteria * This,
    /* [in] */ BOOL isIgnored);


void __RPC_STUB IHsmCriteria_SetIsIgnored_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmCriteria_SetIsNegated_Proxy( 
    IHsmCriteria * This,
    /* [in] */ BOOL isNegated);


void __RPC_STUB IHsmCriteria_SetIsNegated_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmCriteria_ShouldDo_Proxy( 
    IHsmCriteria * This,
    /* [in] */ IFsaScanItem *pScanItem,
    /* [in] */ USHORT scale);


void __RPC_STUB IHsmCriteria_ShouldDo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmCriteria_Value_Proxy( 
    IHsmCriteria * This,
    /* [in] */ IFsaScanItem *pScanItem,
    /* [string][out] */ OLECHAR **value,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IHsmCriteria_Value_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IHsmCriteria_INTERFACE_DEFINED__ */


#ifndef __IHsmRelativeCriteria_INTERFACE_DEFINED__
#define __IHsmRelativeCriteria_INTERFACE_DEFINED__

/* interface IHsmRelativeCriteria */
/* [unique][helpstring][uuid][object] */ 

typedef /* [v1_enum] */ 
enum _HSM_CRITERIACOMPARATOR
    {	HSM_CRITERIACOMPARATOR_NOTSET	= 0,
	HSM_CRITERIACOMPARATOR_LT	= 1,
	HSM_CRITERIACOMPARATOR_LTE	= 2,
	HSM_CRITERIACOMPARATOR_EQL	= 3,
	HSM_CRITERIACOMPARATOR_NEQL	= 4,
	HSM_CRITERIACOMPARATOR_GTE	= 5,
	HSM_CRITERIACOMPARATOR_GT	= 6,
	HSM_CRITERIACOMPARATOR_BETWEEN	= 7,
	HSM_CRITERIACOMPARATOR_OUTSIDE	= 8,
	HSM_CRITERIACOMPARATOR_MEMBEROF	= 9
    } 	HSM_CRITERIACOMPARATOR;


EXTERN_C const IID IID_IHsmRelativeCriteria;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2B382EA1-16EA-11D0-81AE-00A0C91180F2")
    IHsmRelativeCriteria : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ComparatorAsString( 
            /* [string][out][in] */ OLECHAR **pCompString,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ComparatorIsBinary( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetArg1( 
            /* [string][out][in] */ OLECHAR **pArg,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetArg2( 
            /* [string][out][in] */ OLECHAR **pArg,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetComparator( 
            /* [out] */ HSM_CRITERIACOMPARATOR *pComparator) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetArg1( 
            /* [string][in] */ OLECHAR *arg) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetArg2( 
            /* [string][in] */ OLECHAR *arg) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetComparator( 
            /* [in] */ HSM_CRITERIACOMPARATOR comparator) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHsmRelativeCriteriaVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHsmRelativeCriteria * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHsmRelativeCriteria * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHsmRelativeCriteria * This);
        
        HRESULT ( STDMETHODCALLTYPE *ComparatorAsString )( 
            IHsmRelativeCriteria * This,
            /* [string][out][in] */ OLECHAR **pCompString,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *ComparatorIsBinary )( 
            IHsmRelativeCriteria * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetArg1 )( 
            IHsmRelativeCriteria * This,
            /* [string][out][in] */ OLECHAR **pArg,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetArg2 )( 
            IHsmRelativeCriteria * This,
            /* [string][out][in] */ OLECHAR **pArg,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetComparator )( 
            IHsmRelativeCriteria * This,
            /* [out] */ HSM_CRITERIACOMPARATOR *pComparator);
        
        HRESULT ( STDMETHODCALLTYPE *SetArg1 )( 
            IHsmRelativeCriteria * This,
            /* [string][in] */ OLECHAR *arg);
        
        HRESULT ( STDMETHODCALLTYPE *SetArg2 )( 
            IHsmRelativeCriteria * This,
            /* [string][in] */ OLECHAR *arg);
        
        HRESULT ( STDMETHODCALLTYPE *SetComparator )( 
            IHsmRelativeCriteria * This,
            /* [in] */ HSM_CRITERIACOMPARATOR comparator);
        
        END_INTERFACE
    } IHsmRelativeCriteriaVtbl;

    interface IHsmRelativeCriteria
    {
        CONST_VTBL struct IHsmRelativeCriteriaVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHsmRelativeCriteria_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHsmRelativeCriteria_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHsmRelativeCriteria_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHsmRelativeCriteria_ComparatorAsString(This,pCompString,bufferSize)	\
    (This)->lpVtbl -> ComparatorAsString(This,pCompString,bufferSize)

#define IHsmRelativeCriteria_ComparatorIsBinary(This)	\
    (This)->lpVtbl -> ComparatorIsBinary(This)

#define IHsmRelativeCriteria_GetArg1(This,pArg,bufferSize)	\
    (This)->lpVtbl -> GetArg1(This,pArg,bufferSize)

#define IHsmRelativeCriteria_GetArg2(This,pArg,bufferSize)	\
    (This)->lpVtbl -> GetArg2(This,pArg,bufferSize)

#define IHsmRelativeCriteria_GetComparator(This,pComparator)	\
    (This)->lpVtbl -> GetComparator(This,pComparator)

#define IHsmRelativeCriteria_SetArg1(This,arg)	\
    (This)->lpVtbl -> SetArg1(This,arg)

#define IHsmRelativeCriteria_SetArg2(This,arg)	\
    (This)->lpVtbl -> SetArg2(This,arg)

#define IHsmRelativeCriteria_SetComparator(This,comparator)	\
    (This)->lpVtbl -> SetComparator(This,comparator)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IHsmRelativeCriteria_ComparatorAsString_Proxy( 
    IHsmRelativeCriteria * This,
    /* [string][out][in] */ OLECHAR **pCompString,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IHsmRelativeCriteria_ComparatorAsString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRelativeCriteria_ComparatorIsBinary_Proxy( 
    IHsmRelativeCriteria * This);


void __RPC_STUB IHsmRelativeCriteria_ComparatorIsBinary_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRelativeCriteria_GetArg1_Proxy( 
    IHsmRelativeCriteria * This,
    /* [string][out][in] */ OLECHAR **pArg,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IHsmRelativeCriteria_GetArg1_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRelativeCriteria_GetArg2_Proxy( 
    IHsmRelativeCriteria * This,
    /* [string][out][in] */ OLECHAR **pArg,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IHsmRelativeCriteria_GetArg2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRelativeCriteria_GetComparator_Proxy( 
    IHsmRelativeCriteria * This,
    /* [out] */ HSM_CRITERIACOMPARATOR *pComparator);


void __RPC_STUB IHsmRelativeCriteria_GetComparator_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRelativeCriteria_SetArg1_Proxy( 
    IHsmRelativeCriteria * This,
    /* [string][in] */ OLECHAR *arg);


void __RPC_STUB IHsmRelativeCriteria_SetArg1_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRelativeCriteria_SetArg2_Proxy( 
    IHsmRelativeCriteria * This,
    /* [string][in] */ OLECHAR *arg);


void __RPC_STUB IHsmRelativeCriteria_SetArg2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRelativeCriteria_SetComparator_Proxy( 
    IHsmRelativeCriteria * This,
    /* [in] */ HSM_CRITERIACOMPARATOR comparator);


void __RPC_STUB IHsmRelativeCriteria_SetComparator_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IHsmRelativeCriteria_INTERFACE_DEFINED__ */


#ifndef __IHsmDirectedAction_INTERFACE_DEFINED__
#define __IHsmDirectedAction_INTERFACE_DEFINED__

/* interface IHsmDirectedAction */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IHsmDirectedAction;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C7A01572-187A-11D0-81B0-00A0C91180F2")
    IHsmDirectedAction : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetStoragePoolId( 
            /* [out] */ GUID *pId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetStoragePoolId( 
            /* [in] */ GUID id) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHsmDirectedActionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHsmDirectedAction * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHsmDirectedAction * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHsmDirectedAction * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetStoragePoolId )( 
            IHsmDirectedAction * This,
            /* [out] */ GUID *pId);
        
        HRESULT ( STDMETHODCALLTYPE *SetStoragePoolId )( 
            IHsmDirectedAction * This,
            /* [in] */ GUID id);
        
        END_INTERFACE
    } IHsmDirectedActionVtbl;

    interface IHsmDirectedAction
    {
        CONST_VTBL struct IHsmDirectedActionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHsmDirectedAction_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHsmDirectedAction_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHsmDirectedAction_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHsmDirectedAction_GetStoragePoolId(This,pId)	\
    (This)->lpVtbl -> GetStoragePoolId(This,pId)

#define IHsmDirectedAction_SetStoragePoolId(This,id)	\
    (This)->lpVtbl -> SetStoragePoolId(This,id)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IHsmDirectedAction_GetStoragePoolId_Proxy( 
    IHsmDirectedAction * This,
    /* [out] */ GUID *pId);


void __RPC_STUB IHsmDirectedAction_GetStoragePoolId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmDirectedAction_SetStoragePoolId_Proxy( 
    IHsmDirectedAction * This,
    /* [in] */ GUID id);


void __RPC_STUB IHsmDirectedAction_SetStoragePoolId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IHsmDirectedAction_INTERFACE_DEFINED__ */


#ifndef __IHsmJob_INTERFACE_DEFINED__
#define __IHsmJob_INTERFACE_DEFINED__

/* interface IHsmJob */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IHsmJob;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2A87C7E2-DB24-11d2-AFA2-00104B9A3758")
    IHsmJob : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Cancel( 
            /* [in] */ HSM_JOB_PHASE phase) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DidFinish( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DidFinishOk( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumWorkItems( 
            /* [out] */ IWsbEnum **ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FindWorkItem( 
            /* [in] */ IHsmSession *pSession,
            /* [out] */ IHsmJobWorkItem **ppWorkItem) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetContext( 
            /* [out] */ IHsmJobContext **ppContext) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDef( 
            /* [out] */ IHsmJobDef **ppDef) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetHsmId( 
            /* [out] */ GUID *pId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIdentifier( 
            /* [out] */ GUID *pId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMaxActiveSessions( 
            /* [out] */ ULONG *pMaxActiveSessions) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetName( 
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRunId( 
            /* [out] */ ULONG *pId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetState( 
            /* [out] */ HSM_JOB_STATE *pState) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InitAs( 
            /* [string][in] */ OLECHAR *name,
            /* [in] */ IHsmJobDef *pDef,
            /* [in] */ HSM_JOB_DEF_TYPE type,
            /* [in] */ GUID storagePool,
            /* [in] */ IHsmServer *pServer,
            /* [in] */ BOOL isUserDefined,
            /* [in] */ IFsaResource *pResource) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsActive( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsUserDefined( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Pause( 
            /* [in] */ HSM_JOB_PHASE phase) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Restart( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Resume( 
            /* [in] */ HSM_JOB_PHASE phase) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetContext( 
            /* [in] */ IHsmJobContext *pContext) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDef( 
            /* [in] */ IHsmJobDef *pDef) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetHsmId( 
            /* [in] */ GUID id) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetIsUserDefined( 
            /* [in] */ BOOL isUserDefined) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetName( 
            /* [string][in] */ OLECHAR *name) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Start( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Suspend( 
            /* [in] */ HSM_JOB_PHASE phase) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WaitUntilDone( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHsmJobVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHsmJob * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHsmJob * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHsmJob * This);
        
        HRESULT ( STDMETHODCALLTYPE *Cancel )( 
            IHsmJob * This,
            /* [in] */ HSM_JOB_PHASE phase);
        
        HRESULT ( STDMETHODCALLTYPE *DidFinish )( 
            IHsmJob * This);
        
        HRESULT ( STDMETHODCALLTYPE *DidFinishOk )( 
            IHsmJob * This);
        
        HRESULT ( STDMETHODCALLTYPE *EnumWorkItems )( 
            IHsmJob * This,
            /* [out] */ IWsbEnum **ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE *FindWorkItem )( 
            IHsmJob * This,
            /* [in] */ IHsmSession *pSession,
            /* [out] */ IHsmJobWorkItem **ppWorkItem);
        
        HRESULT ( STDMETHODCALLTYPE *GetContext )( 
            IHsmJob * This,
            /* [out] */ IHsmJobContext **ppContext);
        
        HRESULT ( STDMETHODCALLTYPE *GetDef )( 
            IHsmJob * This,
            /* [out] */ IHsmJobDef **ppDef);
        
        HRESULT ( STDMETHODCALLTYPE *GetHsmId )( 
            IHsmJob * This,
            /* [out] */ GUID *pId);
        
        HRESULT ( STDMETHODCALLTYPE *GetIdentifier )( 
            IHsmJob * This,
            /* [out] */ GUID *pId);
        
        HRESULT ( STDMETHODCALLTYPE *GetMaxActiveSessions )( 
            IHsmJob * This,
            /* [out] */ ULONG *pMaxActiveSessions);
        
        HRESULT ( STDMETHODCALLTYPE *GetName )( 
            IHsmJob * This,
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetRunId )( 
            IHsmJob * This,
            /* [out] */ ULONG *pId);
        
        HRESULT ( STDMETHODCALLTYPE *GetState )( 
            IHsmJob * This,
            /* [out] */ HSM_JOB_STATE *pState);
        
        HRESULT ( STDMETHODCALLTYPE *InitAs )( 
            IHsmJob * This,
            /* [string][in] */ OLECHAR *name,
            /* [in] */ IHsmJobDef *pDef,
            /* [in] */ HSM_JOB_DEF_TYPE type,
            /* [in] */ GUID storagePool,
            /* [in] */ IHsmServer *pServer,
            /* [in] */ BOOL isUserDefined,
            /* [in] */ IFsaResource *pResource);
        
        HRESULT ( STDMETHODCALLTYPE *IsActive )( 
            IHsmJob * This);
        
        HRESULT ( STDMETHODCALLTYPE *IsUserDefined )( 
            IHsmJob * This);
        
        HRESULT ( STDMETHODCALLTYPE *Pause )( 
            IHsmJob * This,
            /* [in] */ HSM_JOB_PHASE phase);
        
        HRESULT ( STDMETHODCALLTYPE *Restart )( 
            IHsmJob * This);
        
        HRESULT ( STDMETHODCALLTYPE *Resume )( 
            IHsmJob * This,
            /* [in] */ HSM_JOB_PHASE phase);
        
        HRESULT ( STDMETHODCALLTYPE *SetContext )( 
            IHsmJob * This,
            /* [in] */ IHsmJobContext *pContext);
        
        HRESULT ( STDMETHODCALLTYPE *SetDef )( 
            IHsmJob * This,
            /* [in] */ IHsmJobDef *pDef);
        
        HRESULT ( STDMETHODCALLTYPE *SetHsmId )( 
            IHsmJob * This,
            /* [in] */ GUID id);
        
        HRESULT ( STDMETHODCALLTYPE *SetIsUserDefined )( 
            IHsmJob * This,
            /* [in] */ BOOL isUserDefined);
        
        HRESULT ( STDMETHODCALLTYPE *SetName )( 
            IHsmJob * This,
            /* [string][in] */ OLECHAR *name);
        
        HRESULT ( STDMETHODCALLTYPE *Start )( 
            IHsmJob * This);
        
        HRESULT ( STDMETHODCALLTYPE *Suspend )( 
            IHsmJob * This,
            /* [in] */ HSM_JOB_PHASE phase);
        
        HRESULT ( STDMETHODCALLTYPE *WaitUntilDone )( 
            IHsmJob * This);
        
        END_INTERFACE
    } IHsmJobVtbl;

    interface IHsmJob
    {
        CONST_VTBL struct IHsmJobVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHsmJob_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHsmJob_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHsmJob_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHsmJob_Cancel(This,phase)	\
    (This)->lpVtbl -> Cancel(This,phase)

#define IHsmJob_DidFinish(This)	\
    (This)->lpVtbl -> DidFinish(This)

#define IHsmJob_DidFinishOk(This)	\
    (This)->lpVtbl -> DidFinishOk(This)

#define IHsmJob_EnumWorkItems(This,ppEnum)	\
    (This)->lpVtbl -> EnumWorkItems(This,ppEnum)

#define IHsmJob_FindWorkItem(This,pSession,ppWorkItem)	\
    (This)->lpVtbl -> FindWorkItem(This,pSession,ppWorkItem)

#define IHsmJob_GetContext(This,ppContext)	\
    (This)->lpVtbl -> GetContext(This,ppContext)

#define IHsmJob_GetDef(This,ppDef)	\
    (This)->lpVtbl -> GetDef(This,ppDef)

#define IHsmJob_GetHsmId(This,pId)	\
    (This)->lpVtbl -> GetHsmId(This,pId)

#define IHsmJob_GetIdentifier(This,pId)	\
    (This)->lpVtbl -> GetIdentifier(This,pId)

#define IHsmJob_GetMaxActiveSessions(This,pMaxActiveSessions)	\
    (This)->lpVtbl -> GetMaxActiveSessions(This,pMaxActiveSessions)

#define IHsmJob_GetName(This,pName,bufferSize)	\
    (This)->lpVtbl -> GetName(This,pName,bufferSize)

#define IHsmJob_GetRunId(This,pId)	\
    (This)->lpVtbl -> GetRunId(This,pId)

#define IHsmJob_GetState(This,pState)	\
    (This)->lpVtbl -> GetState(This,pState)

#define IHsmJob_InitAs(This,name,pDef,type,storagePool,pServer,isUserDefined,pResource)	\
    (This)->lpVtbl -> InitAs(This,name,pDef,type,storagePool,pServer,isUserDefined,pResource)

#define IHsmJob_IsActive(This)	\
    (This)->lpVtbl -> IsActive(This)

#define IHsmJob_IsUserDefined(This)	\
    (This)->lpVtbl -> IsUserDefined(This)

#define IHsmJob_Pause(This,phase)	\
    (This)->lpVtbl -> Pause(This,phase)

#define IHsmJob_Restart(This)	\
    (This)->lpVtbl -> Restart(This)

#define IHsmJob_Resume(This,phase)	\
    (This)->lpVtbl -> Resume(This,phase)

#define IHsmJob_SetContext(This,pContext)	\
    (This)->lpVtbl -> SetContext(This,pContext)

#define IHsmJob_SetDef(This,pDef)	\
    (This)->lpVtbl -> SetDef(This,pDef)

#define IHsmJob_SetHsmId(This,id)	\
    (This)->lpVtbl -> SetHsmId(This,id)

#define IHsmJob_SetIsUserDefined(This,isUserDefined)	\
    (This)->lpVtbl -> SetIsUserDefined(This,isUserDefined)

#define IHsmJob_SetName(This,name)	\
    (This)->lpVtbl -> SetName(This,name)

#define IHsmJob_Start(This)	\
    (This)->lpVtbl -> Start(This)

#define IHsmJob_Suspend(This,phase)	\
    (This)->lpVtbl -> Suspend(This,phase)

#define IHsmJob_WaitUntilDone(This)	\
    (This)->lpVtbl -> WaitUntilDone(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IHsmJob_Cancel_Proxy( 
    IHsmJob * This,
    /* [in] */ HSM_JOB_PHASE phase);


void __RPC_STUB IHsmJob_Cancel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJob_DidFinish_Proxy( 
    IHsmJob * This);


void __RPC_STUB IHsmJob_DidFinish_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJob_DidFinishOk_Proxy( 
    IHsmJob * This);


void __RPC_STUB IHsmJob_DidFinishOk_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJob_EnumWorkItems_Proxy( 
    IHsmJob * This,
    /* [out] */ IWsbEnum **ppEnum);


void __RPC_STUB IHsmJob_EnumWorkItems_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJob_FindWorkItem_Proxy( 
    IHsmJob * This,
    /* [in] */ IHsmSession *pSession,
    /* [out] */ IHsmJobWorkItem **ppWorkItem);


void __RPC_STUB IHsmJob_FindWorkItem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJob_GetContext_Proxy( 
    IHsmJob * This,
    /* [out] */ IHsmJobContext **ppContext);


void __RPC_STUB IHsmJob_GetContext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJob_GetDef_Proxy( 
    IHsmJob * This,
    /* [out] */ IHsmJobDef **ppDef);


void __RPC_STUB IHsmJob_GetDef_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJob_GetHsmId_Proxy( 
    IHsmJob * This,
    /* [out] */ GUID *pId);


void __RPC_STUB IHsmJob_GetHsmId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJob_GetIdentifier_Proxy( 
    IHsmJob * This,
    /* [out] */ GUID *pId);


void __RPC_STUB IHsmJob_GetIdentifier_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJob_GetMaxActiveSessions_Proxy( 
    IHsmJob * This,
    /* [out] */ ULONG *pMaxActiveSessions);


void __RPC_STUB IHsmJob_GetMaxActiveSessions_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJob_GetName_Proxy( 
    IHsmJob * This,
    /* [string][out][in] */ OLECHAR **pName,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IHsmJob_GetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJob_GetRunId_Proxy( 
    IHsmJob * This,
    /* [out] */ ULONG *pId);


void __RPC_STUB IHsmJob_GetRunId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJob_GetState_Proxy( 
    IHsmJob * This,
    /* [out] */ HSM_JOB_STATE *pState);


void __RPC_STUB IHsmJob_GetState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJob_InitAs_Proxy( 
    IHsmJob * This,
    /* [string][in] */ OLECHAR *name,
    /* [in] */ IHsmJobDef *pDef,
    /* [in] */ HSM_JOB_DEF_TYPE type,
    /* [in] */ GUID storagePool,
    /* [in] */ IHsmServer *pServer,
    /* [in] */ BOOL isUserDefined,
    /* [in] */ IFsaResource *pResource);


void __RPC_STUB IHsmJob_InitAs_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJob_IsActive_Proxy( 
    IHsmJob * This);


void __RPC_STUB IHsmJob_IsActive_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJob_IsUserDefined_Proxy( 
    IHsmJob * This);


void __RPC_STUB IHsmJob_IsUserDefined_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJob_Pause_Proxy( 
    IHsmJob * This,
    /* [in] */ HSM_JOB_PHASE phase);


void __RPC_STUB IHsmJob_Pause_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJob_Restart_Proxy( 
    IHsmJob * This);


void __RPC_STUB IHsmJob_Restart_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJob_Resume_Proxy( 
    IHsmJob * This,
    /* [in] */ HSM_JOB_PHASE phase);


void __RPC_STUB IHsmJob_Resume_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJob_SetContext_Proxy( 
    IHsmJob * This,
    /* [in] */ IHsmJobContext *pContext);


void __RPC_STUB IHsmJob_SetContext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJob_SetDef_Proxy( 
    IHsmJob * This,
    /* [in] */ IHsmJobDef *pDef);


void __RPC_STUB IHsmJob_SetDef_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJob_SetHsmId_Proxy( 
    IHsmJob * This,
    /* [in] */ GUID id);


void __RPC_STUB IHsmJob_SetHsmId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJob_SetIsUserDefined_Proxy( 
    IHsmJob * This,
    /* [in] */ BOOL isUserDefined);


void __RPC_STUB IHsmJob_SetIsUserDefined_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJob_SetName_Proxy( 
    IHsmJob * This,
    /* [string][in] */ OLECHAR *name);


void __RPC_STUB IHsmJob_SetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJob_Start_Proxy( 
    IHsmJob * This);


void __RPC_STUB IHsmJob_Start_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJob_Suspend_Proxy( 
    IHsmJob * This,
    /* [in] */ HSM_JOB_PHASE phase);


void __RPC_STUB IHsmJob_Suspend_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJob_WaitUntilDone_Proxy( 
    IHsmJob * This);


void __RPC_STUB IHsmJob_WaitUntilDone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IHsmJob_INTERFACE_DEFINED__ */


#ifndef __IHsmJobContext_INTERFACE_DEFINED__
#define __IHsmJobContext_INTERFACE_DEFINED__

/* interface IHsmJobContext */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IHsmJobContext;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AD402360-00FC-11D0-819C-00A0C91180F2")
    IHsmJobContext : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE EnumResources( 
            /* [out] */ IWsbEnum **ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Resources( 
            /* [out] */ IWsbCollection **ppResources) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetUsesAllManaged( 
            /* [in] */ BOOL usesAllManaged) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UsesAllManaged( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHsmJobContextVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHsmJobContext * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHsmJobContext * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHsmJobContext * This);
        
        HRESULT ( STDMETHODCALLTYPE *EnumResources )( 
            IHsmJobContext * This,
            /* [out] */ IWsbEnum **ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE *Resources )( 
            IHsmJobContext * This,
            /* [out] */ IWsbCollection **ppResources);
        
        HRESULT ( STDMETHODCALLTYPE *SetUsesAllManaged )( 
            IHsmJobContext * This,
            /* [in] */ BOOL usesAllManaged);
        
        HRESULT ( STDMETHODCALLTYPE *UsesAllManaged )( 
            IHsmJobContext * This);
        
        END_INTERFACE
    } IHsmJobContextVtbl;

    interface IHsmJobContext
    {
        CONST_VTBL struct IHsmJobContextVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHsmJobContext_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHsmJobContext_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHsmJobContext_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHsmJobContext_EnumResources(This,ppEnum)	\
    (This)->lpVtbl -> EnumResources(This,ppEnum)

#define IHsmJobContext_Resources(This,ppResources)	\
    (This)->lpVtbl -> Resources(This,ppResources)

#define IHsmJobContext_SetUsesAllManaged(This,usesAllManaged)	\
    (This)->lpVtbl -> SetUsesAllManaged(This,usesAllManaged)

#define IHsmJobContext_UsesAllManaged(This)	\
    (This)->lpVtbl -> UsesAllManaged(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IHsmJobContext_EnumResources_Proxy( 
    IHsmJobContext * This,
    /* [out] */ IWsbEnum **ppEnum);


void __RPC_STUB IHsmJobContext_EnumResources_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobContext_Resources_Proxy( 
    IHsmJobContext * This,
    /* [out] */ IWsbCollection **ppResources);


void __RPC_STUB IHsmJobContext_Resources_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobContext_SetUsesAllManaged_Proxy( 
    IHsmJobContext * This,
    /* [in] */ BOOL usesAllManaged);


void __RPC_STUB IHsmJobContext_SetUsesAllManaged_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobContext_UsesAllManaged_Proxy( 
    IHsmJobContext * This);


void __RPC_STUB IHsmJobContext_UsesAllManaged_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IHsmJobContext_INTERFACE_DEFINED__ */


#ifndef __IHsmJobDef_INTERFACE_DEFINED__
#define __IHsmJobDef_INTERFACE_DEFINED__

/* interface IHsmJobDef */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IHsmJobDef;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2FA5166A-D28B-49D4-B5F8-B12B3201C1C4")
    IHsmJobDef : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE EnumPolicies( 
            /* [out] */ IWsbEnum **ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIdentifier( 
            /* [out] */ GUID *pId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetName( 
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPostActionOnResource( 
            /* [out] */ IHsmActionOnResourcePost **ppAction) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPreActionOnResource( 
            /* [out] */ IHsmActionOnResourcePre **ppAction) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPreScanActionOnResource( 
            /* [out] */ IHsmActionOnResourcePreScan **ppAction) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InitAs( 
            /* [string][in] */ OLECHAR *name,
            /* [in] */ HSM_JOB_DEF_TYPE type,
            /* [in] */ GUID storagePool,
            /* [in] */ IHsmServer *pServer,
            /* [in] */ BOOL isUserDefined) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Policies( 
            /* [out] */ IWsbCollection **ppPolicies) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetName( 
            /* [string][in] */ OLECHAR *name) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPostActionOnResource( 
            /* [in] */ IHsmActionOnResourcePost *pAction) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPreActionOnResource( 
            /* [in] */ IHsmActionOnResourcePre *pAction) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPreScanActionOnResource( 
            /* [in] */ IHsmActionOnResourcePreScan *pAction) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSkipHiddenItems( 
            /* [in] */ BOOL shouldSkip) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSkipSystemItems( 
            /* [in] */ BOOL shouldSkip) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetUseRPIndex( 
            /* [in] */ BOOL useIndex) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetUseDbIndex( 
            /* [in] */ BOOL useIndex) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SkipHiddenItems( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SkipSystemItems( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UseRPIndex( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UseDbIndex( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHsmJobDefVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHsmJobDef * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHsmJobDef * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHsmJobDef * This);
        
        HRESULT ( STDMETHODCALLTYPE *EnumPolicies )( 
            IHsmJobDef * This,
            /* [out] */ IWsbEnum **ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE *GetIdentifier )( 
            IHsmJobDef * This,
            /* [out] */ GUID *pId);
        
        HRESULT ( STDMETHODCALLTYPE *GetName )( 
            IHsmJobDef * This,
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetPostActionOnResource )( 
            IHsmJobDef * This,
            /* [out] */ IHsmActionOnResourcePost **ppAction);
        
        HRESULT ( STDMETHODCALLTYPE *GetPreActionOnResource )( 
            IHsmJobDef * This,
            /* [out] */ IHsmActionOnResourcePre **ppAction);
        
        HRESULT ( STDMETHODCALLTYPE *GetPreScanActionOnResource )( 
            IHsmJobDef * This,
            /* [out] */ IHsmActionOnResourcePreScan **ppAction);
        
        HRESULT ( STDMETHODCALLTYPE *InitAs )( 
            IHsmJobDef * This,
            /* [string][in] */ OLECHAR *name,
            /* [in] */ HSM_JOB_DEF_TYPE type,
            /* [in] */ GUID storagePool,
            /* [in] */ IHsmServer *pServer,
            /* [in] */ BOOL isUserDefined);
        
        HRESULT ( STDMETHODCALLTYPE *Policies )( 
            IHsmJobDef * This,
            /* [out] */ IWsbCollection **ppPolicies);
        
        HRESULT ( STDMETHODCALLTYPE *SetName )( 
            IHsmJobDef * This,
            /* [string][in] */ OLECHAR *name);
        
        HRESULT ( STDMETHODCALLTYPE *SetPostActionOnResource )( 
            IHsmJobDef * This,
            /* [in] */ IHsmActionOnResourcePost *pAction);
        
        HRESULT ( STDMETHODCALLTYPE *SetPreActionOnResource )( 
            IHsmJobDef * This,
            /* [in] */ IHsmActionOnResourcePre *pAction);
        
        HRESULT ( STDMETHODCALLTYPE *SetPreScanActionOnResource )( 
            IHsmJobDef * This,
            /* [in] */ IHsmActionOnResourcePreScan *pAction);
        
        HRESULT ( STDMETHODCALLTYPE *SetSkipHiddenItems )( 
            IHsmJobDef * This,
            /* [in] */ BOOL shouldSkip);
        
        HRESULT ( STDMETHODCALLTYPE *SetSkipSystemItems )( 
            IHsmJobDef * This,
            /* [in] */ BOOL shouldSkip);
        
        HRESULT ( STDMETHODCALLTYPE *SetUseRPIndex )( 
            IHsmJobDef * This,
            /* [in] */ BOOL useIndex);
        
        HRESULT ( STDMETHODCALLTYPE *SetUseDbIndex )( 
            IHsmJobDef * This,
            /* [in] */ BOOL useIndex);
        
        HRESULT ( STDMETHODCALLTYPE *SkipHiddenItems )( 
            IHsmJobDef * This);
        
        HRESULT ( STDMETHODCALLTYPE *SkipSystemItems )( 
            IHsmJobDef * This);
        
        HRESULT ( STDMETHODCALLTYPE *UseRPIndex )( 
            IHsmJobDef * This);
        
        HRESULT ( STDMETHODCALLTYPE *UseDbIndex )( 
            IHsmJobDef * This);
        
        END_INTERFACE
    } IHsmJobDefVtbl;

    interface IHsmJobDef
    {
        CONST_VTBL struct IHsmJobDefVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHsmJobDef_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHsmJobDef_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHsmJobDef_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHsmJobDef_EnumPolicies(This,ppEnum)	\
    (This)->lpVtbl -> EnumPolicies(This,ppEnum)

#define IHsmJobDef_GetIdentifier(This,pId)	\
    (This)->lpVtbl -> GetIdentifier(This,pId)

#define IHsmJobDef_GetName(This,pName,bufferSize)	\
    (This)->lpVtbl -> GetName(This,pName,bufferSize)

#define IHsmJobDef_GetPostActionOnResource(This,ppAction)	\
    (This)->lpVtbl -> GetPostActionOnResource(This,ppAction)

#define IHsmJobDef_GetPreActionOnResource(This,ppAction)	\
    (This)->lpVtbl -> GetPreActionOnResource(This,ppAction)

#define IHsmJobDef_GetPreScanActionOnResource(This,ppAction)	\
    (This)->lpVtbl -> GetPreScanActionOnResource(This,ppAction)

#define IHsmJobDef_InitAs(This,name,type,storagePool,pServer,isUserDefined)	\
    (This)->lpVtbl -> InitAs(This,name,type,storagePool,pServer,isUserDefined)

#define IHsmJobDef_Policies(This,ppPolicies)	\
    (This)->lpVtbl -> Policies(This,ppPolicies)

#define IHsmJobDef_SetName(This,name)	\
    (This)->lpVtbl -> SetName(This,name)

#define IHsmJobDef_SetPostActionOnResource(This,pAction)	\
    (This)->lpVtbl -> SetPostActionOnResource(This,pAction)

#define IHsmJobDef_SetPreActionOnResource(This,pAction)	\
    (This)->lpVtbl -> SetPreActionOnResource(This,pAction)

#define IHsmJobDef_SetPreScanActionOnResource(This,pAction)	\
    (This)->lpVtbl -> SetPreScanActionOnResource(This,pAction)

#define IHsmJobDef_SetSkipHiddenItems(This,shouldSkip)	\
    (This)->lpVtbl -> SetSkipHiddenItems(This,shouldSkip)

#define IHsmJobDef_SetSkipSystemItems(This,shouldSkip)	\
    (This)->lpVtbl -> SetSkipSystemItems(This,shouldSkip)

#define IHsmJobDef_SetUseRPIndex(This,useIndex)	\
    (This)->lpVtbl -> SetUseRPIndex(This,useIndex)

#define IHsmJobDef_SetUseDbIndex(This,useIndex)	\
    (This)->lpVtbl -> SetUseDbIndex(This,useIndex)

#define IHsmJobDef_SkipHiddenItems(This)	\
    (This)->lpVtbl -> SkipHiddenItems(This)

#define IHsmJobDef_SkipSystemItems(This)	\
    (This)->lpVtbl -> SkipSystemItems(This)

#define IHsmJobDef_UseRPIndex(This)	\
    (This)->lpVtbl -> UseRPIndex(This)

#define IHsmJobDef_UseDbIndex(This)	\
    (This)->lpVtbl -> UseDbIndex(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IHsmJobDef_EnumPolicies_Proxy( 
    IHsmJobDef * This,
    /* [out] */ IWsbEnum **ppEnum);


void __RPC_STUB IHsmJobDef_EnumPolicies_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobDef_GetIdentifier_Proxy( 
    IHsmJobDef * This,
    /* [out] */ GUID *pId);


void __RPC_STUB IHsmJobDef_GetIdentifier_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobDef_GetName_Proxy( 
    IHsmJobDef * This,
    /* [string][out][in] */ OLECHAR **pName,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IHsmJobDef_GetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobDef_GetPostActionOnResource_Proxy( 
    IHsmJobDef * This,
    /* [out] */ IHsmActionOnResourcePost **ppAction);


void __RPC_STUB IHsmJobDef_GetPostActionOnResource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobDef_GetPreActionOnResource_Proxy( 
    IHsmJobDef * This,
    /* [out] */ IHsmActionOnResourcePre **ppAction);


void __RPC_STUB IHsmJobDef_GetPreActionOnResource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobDef_GetPreScanActionOnResource_Proxy( 
    IHsmJobDef * This,
    /* [out] */ IHsmActionOnResourcePreScan **ppAction);


void __RPC_STUB IHsmJobDef_GetPreScanActionOnResource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobDef_InitAs_Proxy( 
    IHsmJobDef * This,
    /* [string][in] */ OLECHAR *name,
    /* [in] */ HSM_JOB_DEF_TYPE type,
    /* [in] */ GUID storagePool,
    /* [in] */ IHsmServer *pServer,
    /* [in] */ BOOL isUserDefined);


void __RPC_STUB IHsmJobDef_InitAs_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobDef_Policies_Proxy( 
    IHsmJobDef * This,
    /* [out] */ IWsbCollection **ppPolicies);


void __RPC_STUB IHsmJobDef_Policies_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobDef_SetName_Proxy( 
    IHsmJobDef * This,
    /* [string][in] */ OLECHAR *name);


void __RPC_STUB IHsmJobDef_SetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobDef_SetPostActionOnResource_Proxy( 
    IHsmJobDef * This,
    /* [in] */ IHsmActionOnResourcePost *pAction);


void __RPC_STUB IHsmJobDef_SetPostActionOnResource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobDef_SetPreActionOnResource_Proxy( 
    IHsmJobDef * This,
    /* [in] */ IHsmActionOnResourcePre *pAction);


void __RPC_STUB IHsmJobDef_SetPreActionOnResource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobDef_SetPreScanActionOnResource_Proxy( 
    IHsmJobDef * This,
    /* [in] */ IHsmActionOnResourcePreScan *pAction);


void __RPC_STUB IHsmJobDef_SetPreScanActionOnResource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobDef_SetSkipHiddenItems_Proxy( 
    IHsmJobDef * This,
    /* [in] */ BOOL shouldSkip);


void __RPC_STUB IHsmJobDef_SetSkipHiddenItems_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobDef_SetSkipSystemItems_Proxy( 
    IHsmJobDef * This,
    /* [in] */ BOOL shouldSkip);


void __RPC_STUB IHsmJobDef_SetSkipSystemItems_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobDef_SetUseRPIndex_Proxy( 
    IHsmJobDef * This,
    /* [in] */ BOOL useIndex);


void __RPC_STUB IHsmJobDef_SetUseRPIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobDef_SetUseDbIndex_Proxy( 
    IHsmJobDef * This,
    /* [in] */ BOOL useIndex);


void __RPC_STUB IHsmJobDef_SetUseDbIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobDef_SkipHiddenItems_Proxy( 
    IHsmJobDef * This);


void __RPC_STUB IHsmJobDef_SkipHiddenItems_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobDef_SkipSystemItems_Proxy( 
    IHsmJobDef * This);


void __RPC_STUB IHsmJobDef_SkipSystemItems_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobDef_UseRPIndex_Proxy( 
    IHsmJobDef * This);


void __RPC_STUB IHsmJobDef_UseRPIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobDef_UseDbIndex_Proxy( 
    IHsmJobDef * This);


void __RPC_STUB IHsmJobDef_UseDbIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IHsmJobDef_INTERFACE_DEFINED__ */


#ifndef __IHsmJobSinkEverySession_INTERFACE_DEFINED__
#define __IHsmJobSinkEverySession_INTERFACE_DEFINED__

/* interface IHsmJobSinkEverySession */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IHsmJobSinkEverySession;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4250BAA0-811D-11d0-81E4-00A0C91180F2")
    IHsmJobSinkEverySession : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ProcessJobSession( 
            /* [in] */ IHsmSession *pSession,
            /* [in] */ IHsmPhase *pPhase,
            /* [string][in] */ OLECHAR *currentPath) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHsmJobSinkEverySessionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHsmJobSinkEverySession * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHsmJobSinkEverySession * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHsmJobSinkEverySession * This);
        
        HRESULT ( STDMETHODCALLTYPE *ProcessJobSession )( 
            IHsmJobSinkEverySession * This,
            /* [in] */ IHsmSession *pSession,
            /* [in] */ IHsmPhase *pPhase,
            /* [string][in] */ OLECHAR *currentPath);
        
        END_INTERFACE
    } IHsmJobSinkEverySessionVtbl;

    interface IHsmJobSinkEverySession
    {
        CONST_VTBL struct IHsmJobSinkEverySessionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHsmJobSinkEverySession_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHsmJobSinkEverySession_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHsmJobSinkEverySession_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHsmJobSinkEverySession_ProcessJobSession(This,pSession,pPhase,currentPath)	\
    (This)->lpVtbl -> ProcessJobSession(This,pSession,pPhase,currentPath)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IHsmJobSinkEverySession_ProcessJobSession_Proxy( 
    IHsmJobSinkEverySession * This,
    /* [in] */ IHsmSession *pSession,
    /* [in] */ IHsmPhase *pPhase,
    /* [string][in] */ OLECHAR *currentPath);


void __RPC_STUB IHsmJobSinkEverySession_ProcessJobSession_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IHsmJobSinkEverySession_INTERFACE_DEFINED__ */


#ifndef __IHsmJobWorkItem_INTERFACE_DEFINED__
#define __IHsmJobWorkItem_INTERFACE_DEFINED__

/* interface IHsmJobWorkItem */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IHsmJobWorkItem;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B8E1CD20-81D3-11d0-81E4-00A0C91180F2")
    IHsmJobWorkItem : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CompareToResourceId( 
            /* [in] */ GUID id,
            /* [out] */ SHORT *pResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CompareToIWorkItem( 
            /* [in] */ IHsmJobWorkItem *pWorkItem,
            /* [out] */ SHORT *pResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DoPostScan( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DoPreScan( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumPhases( 
            /* [out] */ IWsbEnum **ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumTotals( 
            /* [out] */ IWsbEnum **ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCurrentPath( 
            /* [string][out][in] */ OLECHAR **pString,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFinishTime( 
            /* [out] */ FILETIME *pTime) = 0;
        
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
        
    };
    
#else 	/* C style interface */

    typedef struct IHsmJobWorkItemVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHsmJobWorkItem * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHsmJobWorkItem * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHsmJobWorkItem * This);
        
        HRESULT ( STDMETHODCALLTYPE *CompareToResourceId )( 
            IHsmJobWorkItem * This,
            /* [in] */ GUID id,
            /* [out] */ SHORT *pResult);
        
        HRESULT ( STDMETHODCALLTYPE *CompareToIWorkItem )( 
            IHsmJobWorkItem * This,
            /* [in] */ IHsmJobWorkItem *pWorkItem,
            /* [out] */ SHORT *pResult);
        
        HRESULT ( STDMETHODCALLTYPE *DoPostScan )( 
            IHsmJobWorkItem * This);
        
        HRESULT ( STDMETHODCALLTYPE *DoPreScan )( 
            IHsmJobWorkItem * This);
        
        HRESULT ( STDMETHODCALLTYPE *EnumPhases )( 
            IHsmJobWorkItem * This,
            /* [out] */ IWsbEnum **ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE *EnumTotals )( 
            IHsmJobWorkItem * This,
            /* [out] */ IWsbEnum **ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE *GetCurrentPath )( 
            IHsmJobWorkItem * This,
            /* [string][out][in] */ OLECHAR **pString,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetFinishTime )( 
            IHsmJobWorkItem * This,
            /* [out] */ FILETIME *pTime);
        
        HRESULT ( STDMETHODCALLTYPE *GetResourceId )( 
            IHsmJobWorkItem * This,
            /* [out] */ GUID *pId);
        
        HRESULT ( STDMETHODCALLTYPE *GetSession )( 
            IHsmJobWorkItem * This,
            /* [out] */ IHsmSession **ppSession);
        
        HRESULT ( STDMETHODCALLTYPE *GetStartingPath )( 
            IHsmJobWorkItem * This,
            /* [string][out][in] */ OLECHAR **pString,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetStartTime )( 
            IHsmJobWorkItem * This,
            /* [out] */ FILETIME *pTime);
        
        HRESULT ( STDMETHODCALLTYPE *GetState )( 
            IHsmJobWorkItem * This,
            /* [out] */ HSM_JOB_STATE *pState);
        
        HRESULT ( STDMETHODCALLTYPE *GetStateAsString )( 
            IHsmJobWorkItem * This,
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetSubRunId )( 
            IHsmJobWorkItem * This,
            /* [out] */ ULONG *pId);
        
        END_INTERFACE
    } IHsmJobWorkItemVtbl;

    interface IHsmJobWorkItem
    {
        CONST_VTBL struct IHsmJobWorkItemVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHsmJobWorkItem_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHsmJobWorkItem_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHsmJobWorkItem_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHsmJobWorkItem_CompareToResourceId(This,id,pResult)	\
    (This)->lpVtbl -> CompareToResourceId(This,id,pResult)

#define IHsmJobWorkItem_CompareToIWorkItem(This,pWorkItem,pResult)	\
    (This)->lpVtbl -> CompareToIWorkItem(This,pWorkItem,pResult)

#define IHsmJobWorkItem_DoPostScan(This)	\
    (This)->lpVtbl -> DoPostScan(This)

#define IHsmJobWorkItem_DoPreScan(This)	\
    (This)->lpVtbl -> DoPreScan(This)

#define IHsmJobWorkItem_EnumPhases(This,ppEnum)	\
    (This)->lpVtbl -> EnumPhases(This,ppEnum)

#define IHsmJobWorkItem_EnumTotals(This,ppEnum)	\
    (This)->lpVtbl -> EnumTotals(This,ppEnum)

#define IHsmJobWorkItem_GetCurrentPath(This,pString,bufferSize)	\
    (This)->lpVtbl -> GetCurrentPath(This,pString,bufferSize)

#define IHsmJobWorkItem_GetFinishTime(This,pTime)	\
    (This)->lpVtbl -> GetFinishTime(This,pTime)

#define IHsmJobWorkItem_GetResourceId(This,pId)	\
    (This)->lpVtbl -> GetResourceId(This,pId)

#define IHsmJobWorkItem_GetSession(This,ppSession)	\
    (This)->lpVtbl -> GetSession(This,ppSession)

#define IHsmJobWorkItem_GetStartingPath(This,pString,bufferSize)	\
    (This)->lpVtbl -> GetStartingPath(This,pString,bufferSize)

#define IHsmJobWorkItem_GetStartTime(This,pTime)	\
    (This)->lpVtbl -> GetStartTime(This,pTime)

#define IHsmJobWorkItem_GetState(This,pState)	\
    (This)->lpVtbl -> GetState(This,pState)

#define IHsmJobWorkItem_GetStateAsString(This,pName,bufferSize)	\
    (This)->lpVtbl -> GetStateAsString(This,pName,bufferSize)

#define IHsmJobWorkItem_GetSubRunId(This,pId)	\
    (This)->lpVtbl -> GetSubRunId(This,pId)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IHsmJobWorkItem_CompareToResourceId_Proxy( 
    IHsmJobWorkItem * This,
    /* [in] */ GUID id,
    /* [out] */ SHORT *pResult);


void __RPC_STUB IHsmJobWorkItem_CompareToResourceId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobWorkItem_CompareToIWorkItem_Proxy( 
    IHsmJobWorkItem * This,
    /* [in] */ IHsmJobWorkItem *pWorkItem,
    /* [out] */ SHORT *pResult);


void __RPC_STUB IHsmJobWorkItem_CompareToIWorkItem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobWorkItem_DoPostScan_Proxy( 
    IHsmJobWorkItem * This);


void __RPC_STUB IHsmJobWorkItem_DoPostScan_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobWorkItem_DoPreScan_Proxy( 
    IHsmJobWorkItem * This);


void __RPC_STUB IHsmJobWorkItem_DoPreScan_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobWorkItem_EnumPhases_Proxy( 
    IHsmJobWorkItem * This,
    /* [out] */ IWsbEnum **ppEnum);


void __RPC_STUB IHsmJobWorkItem_EnumPhases_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobWorkItem_EnumTotals_Proxy( 
    IHsmJobWorkItem * This,
    /* [out] */ IWsbEnum **ppEnum);


void __RPC_STUB IHsmJobWorkItem_EnumTotals_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobWorkItem_GetCurrentPath_Proxy( 
    IHsmJobWorkItem * This,
    /* [string][out][in] */ OLECHAR **pString,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IHsmJobWorkItem_GetCurrentPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobWorkItem_GetFinishTime_Proxy( 
    IHsmJobWorkItem * This,
    /* [out] */ FILETIME *pTime);


void __RPC_STUB IHsmJobWorkItem_GetFinishTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobWorkItem_GetResourceId_Proxy( 
    IHsmJobWorkItem * This,
    /* [out] */ GUID *pId);


void __RPC_STUB IHsmJobWorkItem_GetResourceId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobWorkItem_GetSession_Proxy( 
    IHsmJobWorkItem * This,
    /* [out] */ IHsmSession **ppSession);


void __RPC_STUB IHsmJobWorkItem_GetSession_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobWorkItem_GetStartingPath_Proxy( 
    IHsmJobWorkItem * This,
    /* [string][out][in] */ OLECHAR **pString,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IHsmJobWorkItem_GetStartingPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobWorkItem_GetStartTime_Proxy( 
    IHsmJobWorkItem * This,
    /* [out] */ FILETIME *pTime);


void __RPC_STUB IHsmJobWorkItem_GetStartTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobWorkItem_GetState_Proxy( 
    IHsmJobWorkItem * This,
    /* [out] */ HSM_JOB_STATE *pState);


void __RPC_STUB IHsmJobWorkItem_GetState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobWorkItem_GetStateAsString_Proxy( 
    IHsmJobWorkItem * This,
    /* [string][out][in] */ OLECHAR **pName,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IHsmJobWorkItem_GetStateAsString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmJobWorkItem_GetSubRunId_Proxy( 
    IHsmJobWorkItem * This,
    /* [out] */ ULONG *pId);


void __RPC_STUB IHsmJobWorkItem_GetSubRunId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IHsmJobWorkItem_INTERFACE_DEFINED__ */


#ifndef __IHsmPhase_INTERFACE_DEFINED__
#define __IHsmPhase_INTERFACE_DEFINED__

/* interface IHsmPhase */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IHsmPhase;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("35035914-0D1C-11d2-9B0C-00104B9A2869")
    IHsmPhase : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IHsmPhase **ppPhase) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CopyTo( 
            /* [in] */ IHsmPhase *pPhase) = 0;
        
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
            /* [out] */ HSM_JOB_PHASE *pPhase) = 0;
        
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
        
    };
    
#else 	/* C style interface */

    typedef struct IHsmPhaseVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHsmPhase * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHsmPhase * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHsmPhase * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IHsmPhase * This,
            /* [out] */ IHsmPhase **ppPhase);
        
        HRESULT ( STDMETHODCALLTYPE *CopyTo )( 
            IHsmPhase * This,
            /* [in] */ IHsmPhase *pPhase);
        
        HRESULT ( STDMETHODCALLTYPE *GetElapsedTime )( 
            IHsmPhase * This,
            /* [out] */ ULONG *pDays,
            /* [out] */ USHORT *pHours,
            /* [out] */ USHORT *pMinutes,
            /* [out] */ USHORT *pSeconds);
        
        HRESULT ( STDMETHODCALLTYPE *GetMediaState )( 
            IHsmPhase * This,
            /* [out] */ HSM_JOB_MEDIA_STATE *pState);
        
        HRESULT ( STDMETHODCALLTYPE *GetMediaStateAsString )( 
            IHsmPhase * This,
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetName )( 
            IHsmPhase * This,
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetPhase )( 
            IHsmPhase * This,
            /* [out] */ HSM_JOB_PHASE *pPhase);
        
        HRESULT ( STDMETHODCALLTYPE *GetPriority )( 
            IHsmPhase * This,
            /* [out] */ HSM_JOB_PRIORITY *pPriority);
        
        HRESULT ( STDMETHODCALLTYPE *GetPriorityAsString )( 
            IHsmPhase * This,
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetState )( 
            IHsmPhase * This,
            /* [out] */ HSM_JOB_STATE *pState);
        
        HRESULT ( STDMETHODCALLTYPE *GetStateAsString )( 
            IHsmPhase * This,
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetStats )( 
            IHsmPhase * This,
            /* [out] */ LONGLONG *items,
            /* [out] */ LONGLONG *size,
            /* [out] */ LONGLONG *skippedItems,
            /* [out] */ LONGLONG *skippedSize,
            /* [out] */ LONGLONG *errorItems,
            /* [out] */ LONGLONG *errorSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetStartTime )( 
            IHsmPhase * This,
            /* [out] */ FILETIME *pTime);
        
        HRESULT ( STDMETHODCALLTYPE *GetStopTime )( 
            IHsmPhase * This,
            /* [out] */ FILETIME *pTime);
        
        END_INTERFACE
    } IHsmPhaseVtbl;

    interface IHsmPhase
    {
        CONST_VTBL struct IHsmPhaseVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHsmPhase_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHsmPhase_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHsmPhase_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHsmPhase_Clone(This,ppPhase)	\
    (This)->lpVtbl -> Clone(This,ppPhase)

#define IHsmPhase_CopyTo(This,pPhase)	\
    (This)->lpVtbl -> CopyTo(This,pPhase)

#define IHsmPhase_GetElapsedTime(This,pDays,pHours,pMinutes,pSeconds)	\
    (This)->lpVtbl -> GetElapsedTime(This,pDays,pHours,pMinutes,pSeconds)

#define IHsmPhase_GetMediaState(This,pState)	\
    (This)->lpVtbl -> GetMediaState(This,pState)

#define IHsmPhase_GetMediaStateAsString(This,pName,bufferSize)	\
    (This)->lpVtbl -> GetMediaStateAsString(This,pName,bufferSize)

#define IHsmPhase_GetName(This,pName,bufferSize)	\
    (This)->lpVtbl -> GetName(This,pName,bufferSize)

#define IHsmPhase_GetPhase(This,pPhase)	\
    (This)->lpVtbl -> GetPhase(This,pPhase)

#define IHsmPhase_GetPriority(This,pPriority)	\
    (This)->lpVtbl -> GetPriority(This,pPriority)

#define IHsmPhase_GetPriorityAsString(This,pName,bufferSize)	\
    (This)->lpVtbl -> GetPriorityAsString(This,pName,bufferSize)

#define IHsmPhase_GetState(This,pState)	\
    (This)->lpVtbl -> GetState(This,pState)

#define IHsmPhase_GetStateAsString(This,pName,bufferSize)	\
    (This)->lpVtbl -> GetStateAsString(This,pName,bufferSize)

#define IHsmPhase_GetStats(This,items,size,skippedItems,skippedSize,errorItems,errorSize)	\
    (This)->lpVtbl -> GetStats(This,items,size,skippedItems,skippedSize,errorItems,errorSize)

#define IHsmPhase_GetStartTime(This,pTime)	\
    (This)->lpVtbl -> GetStartTime(This,pTime)

#define IHsmPhase_GetStopTime(This,pTime)	\
    (This)->lpVtbl -> GetStopTime(This,pTime)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IHsmPhase_Clone_Proxy( 
    IHsmPhase * This,
    /* [out] */ IHsmPhase **ppPhase);


void __RPC_STUB IHsmPhase_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmPhase_CopyTo_Proxy( 
    IHsmPhase * This,
    /* [in] */ IHsmPhase *pPhase);


void __RPC_STUB IHsmPhase_CopyTo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmPhase_GetElapsedTime_Proxy( 
    IHsmPhase * This,
    /* [out] */ ULONG *pDays,
    /* [out] */ USHORT *pHours,
    /* [out] */ USHORT *pMinutes,
    /* [out] */ USHORT *pSeconds);


void __RPC_STUB IHsmPhase_GetElapsedTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmPhase_GetMediaState_Proxy( 
    IHsmPhase * This,
    /* [out] */ HSM_JOB_MEDIA_STATE *pState);


void __RPC_STUB IHsmPhase_GetMediaState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmPhase_GetMediaStateAsString_Proxy( 
    IHsmPhase * This,
    /* [string][out][in] */ OLECHAR **pName,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IHsmPhase_GetMediaStateAsString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmPhase_GetName_Proxy( 
    IHsmPhase * This,
    /* [string][out][in] */ OLECHAR **pName,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IHsmPhase_GetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmPhase_GetPhase_Proxy( 
    IHsmPhase * This,
    /* [out] */ HSM_JOB_PHASE *pPhase);


void __RPC_STUB IHsmPhase_GetPhase_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmPhase_GetPriority_Proxy( 
    IHsmPhase * This,
    /* [out] */ HSM_JOB_PRIORITY *pPriority);


void __RPC_STUB IHsmPhase_GetPriority_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmPhase_GetPriorityAsString_Proxy( 
    IHsmPhase * This,
    /* [string][out][in] */ OLECHAR **pName,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IHsmPhase_GetPriorityAsString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmPhase_GetState_Proxy( 
    IHsmPhase * This,
    /* [out] */ HSM_JOB_STATE *pState);


void __RPC_STUB IHsmPhase_GetState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmPhase_GetStateAsString_Proxy( 
    IHsmPhase * This,
    /* [string][out][in] */ OLECHAR **pName,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IHsmPhase_GetStateAsString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmPhase_GetStats_Proxy( 
    IHsmPhase * This,
    /* [out] */ LONGLONG *items,
    /* [out] */ LONGLONG *size,
    /* [out] */ LONGLONG *skippedItems,
    /* [out] */ LONGLONG *skippedSize,
    /* [out] */ LONGLONG *errorItems,
    /* [out] */ LONGLONG *errorSize);


void __RPC_STUB IHsmPhase_GetStats_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmPhase_GetStartTime_Proxy( 
    IHsmPhase * This,
    /* [out] */ FILETIME *pTime);


void __RPC_STUB IHsmPhase_GetStartTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmPhase_GetStopTime_Proxy( 
    IHsmPhase * This,
    /* [out] */ FILETIME *pTime);


void __RPC_STUB IHsmPhase_GetStopTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IHsmPhase_INTERFACE_DEFINED__ */


#ifndef __IHsmPolicy_INTERFACE_DEFINED__
#define __IHsmPolicy_INTERFACE_DEFINED__

/* interface IHsmPolicy */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IHsmPolicy;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AD40234C-00FC-11D0-819C-00A0C91180F2")
    IHsmPolicy : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE EnumRules( 
            /* [out] */ IWsbEnum **ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAction( 
            /* [out] */ IHsmAction **ppAction) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIdentifier( 
            /* [out] */ GUID *pId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetName( 
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetScale( 
            /* [out] */ USHORT *pScale) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Rules( 
            /* [out] */ IWsbCollection **ppWsbCollection) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAction( 
            /* [in] */ IHsmAction *pAction) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetName( 
            /* [string][in] */ OLECHAR *name) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetScale( 
            /* [in] */ USHORT scale) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetUsesDefaultRules( 
            /* [in] */ BOOL usesDefaults) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UsesDefaultRules( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHsmPolicyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHsmPolicy * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHsmPolicy * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHsmPolicy * This);
        
        HRESULT ( STDMETHODCALLTYPE *EnumRules )( 
            IHsmPolicy * This,
            /* [out] */ IWsbEnum **ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE *GetAction )( 
            IHsmPolicy * This,
            /* [out] */ IHsmAction **ppAction);
        
        HRESULT ( STDMETHODCALLTYPE *GetIdentifier )( 
            IHsmPolicy * This,
            /* [out] */ GUID *pId);
        
        HRESULT ( STDMETHODCALLTYPE *GetName )( 
            IHsmPolicy * This,
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetScale )( 
            IHsmPolicy * This,
            /* [out] */ USHORT *pScale);
        
        HRESULT ( STDMETHODCALLTYPE *Rules )( 
            IHsmPolicy * This,
            /* [out] */ IWsbCollection **ppWsbCollection);
        
        HRESULT ( STDMETHODCALLTYPE *SetAction )( 
            IHsmPolicy * This,
            /* [in] */ IHsmAction *pAction);
        
        HRESULT ( STDMETHODCALLTYPE *SetName )( 
            IHsmPolicy * This,
            /* [string][in] */ OLECHAR *name);
        
        HRESULT ( STDMETHODCALLTYPE *SetScale )( 
            IHsmPolicy * This,
            /* [in] */ USHORT scale);
        
        HRESULT ( STDMETHODCALLTYPE *SetUsesDefaultRules )( 
            IHsmPolicy * This,
            /* [in] */ BOOL usesDefaults);
        
        HRESULT ( STDMETHODCALLTYPE *UsesDefaultRules )( 
            IHsmPolicy * This);
        
        END_INTERFACE
    } IHsmPolicyVtbl;

    interface IHsmPolicy
    {
        CONST_VTBL struct IHsmPolicyVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHsmPolicy_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHsmPolicy_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHsmPolicy_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHsmPolicy_EnumRules(This,ppEnum)	\
    (This)->lpVtbl -> EnumRules(This,ppEnum)

#define IHsmPolicy_GetAction(This,ppAction)	\
    (This)->lpVtbl -> GetAction(This,ppAction)

#define IHsmPolicy_GetIdentifier(This,pId)	\
    (This)->lpVtbl -> GetIdentifier(This,pId)

#define IHsmPolicy_GetName(This,pName,bufferSize)	\
    (This)->lpVtbl -> GetName(This,pName,bufferSize)

#define IHsmPolicy_GetScale(This,pScale)	\
    (This)->lpVtbl -> GetScale(This,pScale)

#define IHsmPolicy_Rules(This,ppWsbCollection)	\
    (This)->lpVtbl -> Rules(This,ppWsbCollection)

#define IHsmPolicy_SetAction(This,pAction)	\
    (This)->lpVtbl -> SetAction(This,pAction)

#define IHsmPolicy_SetName(This,name)	\
    (This)->lpVtbl -> SetName(This,name)

#define IHsmPolicy_SetScale(This,scale)	\
    (This)->lpVtbl -> SetScale(This,scale)

#define IHsmPolicy_SetUsesDefaultRules(This,usesDefaults)	\
    (This)->lpVtbl -> SetUsesDefaultRules(This,usesDefaults)

#define IHsmPolicy_UsesDefaultRules(This)	\
    (This)->lpVtbl -> UsesDefaultRules(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IHsmPolicy_EnumRules_Proxy( 
    IHsmPolicy * This,
    /* [out] */ IWsbEnum **ppEnum);


void __RPC_STUB IHsmPolicy_EnumRules_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmPolicy_GetAction_Proxy( 
    IHsmPolicy * This,
    /* [out] */ IHsmAction **ppAction);


void __RPC_STUB IHsmPolicy_GetAction_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmPolicy_GetIdentifier_Proxy( 
    IHsmPolicy * This,
    /* [out] */ GUID *pId);


void __RPC_STUB IHsmPolicy_GetIdentifier_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmPolicy_GetName_Proxy( 
    IHsmPolicy * This,
    /* [string][out][in] */ OLECHAR **pName,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IHsmPolicy_GetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmPolicy_GetScale_Proxy( 
    IHsmPolicy * This,
    /* [out] */ USHORT *pScale);


void __RPC_STUB IHsmPolicy_GetScale_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmPolicy_Rules_Proxy( 
    IHsmPolicy * This,
    /* [out] */ IWsbCollection **ppWsbCollection);


void __RPC_STUB IHsmPolicy_Rules_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmPolicy_SetAction_Proxy( 
    IHsmPolicy * This,
    /* [in] */ IHsmAction *pAction);


void __RPC_STUB IHsmPolicy_SetAction_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmPolicy_SetName_Proxy( 
    IHsmPolicy * This,
    /* [string][in] */ OLECHAR *name);


void __RPC_STUB IHsmPolicy_SetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmPolicy_SetScale_Proxy( 
    IHsmPolicy * This,
    /* [in] */ USHORT scale);


void __RPC_STUB IHsmPolicy_SetScale_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmPolicy_SetUsesDefaultRules_Proxy( 
    IHsmPolicy * This,
    /* [in] */ BOOL usesDefaults);


void __RPC_STUB IHsmPolicy_SetUsesDefaultRules_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmPolicy_UsesDefaultRules_Proxy( 
    IHsmPolicy * This);


void __RPC_STUB IHsmPolicy_UsesDefaultRules_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IHsmPolicy_INTERFACE_DEFINED__ */


#ifndef __IHsmRelocateAction_INTERFACE_DEFINED__
#define __IHsmRelocateAction_INTERFACE_DEFINED__

/* interface IHsmRelocateAction */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IHsmRelocateAction;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C7A01571-187A-11D0-81B0-00A0C91180F2")
    IHsmRelocateAction : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetDestination( 
            /* [string][out][in] */ OLECHAR **pDest,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ExpandPlaceholders( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RetainHierarchy( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDestination( 
            /* [string][in] */ OLECHAR *dest) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetExpandPlaceholders( 
            /* [in] */ BOOL expandPlaceholders) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRetainHierarchy( 
            /* [in] */ BOOL retainHierarchy) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHsmRelocateActionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHsmRelocateAction * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHsmRelocateAction * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHsmRelocateAction * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetDestination )( 
            IHsmRelocateAction * This,
            /* [string][out][in] */ OLECHAR **pDest,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *ExpandPlaceholders )( 
            IHsmRelocateAction * This);
        
        HRESULT ( STDMETHODCALLTYPE *RetainHierarchy )( 
            IHsmRelocateAction * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetDestination )( 
            IHsmRelocateAction * This,
            /* [string][in] */ OLECHAR *dest);
        
        HRESULT ( STDMETHODCALLTYPE *SetExpandPlaceholders )( 
            IHsmRelocateAction * This,
            /* [in] */ BOOL expandPlaceholders);
        
        HRESULT ( STDMETHODCALLTYPE *SetRetainHierarchy )( 
            IHsmRelocateAction * This,
            /* [in] */ BOOL retainHierarchy);
        
        END_INTERFACE
    } IHsmRelocateActionVtbl;

    interface IHsmRelocateAction
    {
        CONST_VTBL struct IHsmRelocateActionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHsmRelocateAction_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHsmRelocateAction_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHsmRelocateAction_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHsmRelocateAction_GetDestination(This,pDest,bufferSize)	\
    (This)->lpVtbl -> GetDestination(This,pDest,bufferSize)

#define IHsmRelocateAction_ExpandPlaceholders(This)	\
    (This)->lpVtbl -> ExpandPlaceholders(This)

#define IHsmRelocateAction_RetainHierarchy(This)	\
    (This)->lpVtbl -> RetainHierarchy(This)

#define IHsmRelocateAction_SetDestination(This,dest)	\
    (This)->lpVtbl -> SetDestination(This,dest)

#define IHsmRelocateAction_SetExpandPlaceholders(This,expandPlaceholders)	\
    (This)->lpVtbl -> SetExpandPlaceholders(This,expandPlaceholders)

#define IHsmRelocateAction_SetRetainHierarchy(This,retainHierarchy)	\
    (This)->lpVtbl -> SetRetainHierarchy(This,retainHierarchy)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IHsmRelocateAction_GetDestination_Proxy( 
    IHsmRelocateAction * This,
    /* [string][out][in] */ OLECHAR **pDest,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IHsmRelocateAction_GetDestination_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRelocateAction_ExpandPlaceholders_Proxy( 
    IHsmRelocateAction * This);


void __RPC_STUB IHsmRelocateAction_ExpandPlaceholders_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRelocateAction_RetainHierarchy_Proxy( 
    IHsmRelocateAction * This);


void __RPC_STUB IHsmRelocateAction_RetainHierarchy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRelocateAction_SetDestination_Proxy( 
    IHsmRelocateAction * This,
    /* [string][in] */ OLECHAR *dest);


void __RPC_STUB IHsmRelocateAction_SetDestination_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRelocateAction_SetExpandPlaceholders_Proxy( 
    IHsmRelocateAction * This,
    /* [in] */ BOOL expandPlaceholders);


void __RPC_STUB IHsmRelocateAction_SetExpandPlaceholders_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRelocateAction_SetRetainHierarchy_Proxy( 
    IHsmRelocateAction * This,
    /* [in] */ BOOL retainHierarchy);


void __RPC_STUB IHsmRelocateAction_SetRetainHierarchy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IHsmRelocateAction_INTERFACE_DEFINED__ */


#ifndef __IHsmRule_INTERFACE_DEFINED__
#define __IHsmRule_INTERFACE_DEFINED__

/* interface IHsmRule */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IHsmRule;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AD402356-00FC-11D0-819C-00A0C91180F2")
    IHsmRule : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CompareToIRule( 
            /* [in] */ IHsmRule *pRule,
            /* [out] */ SHORT *pResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CompareToPathAndName( 
            /* [string][in] */ OLECHAR *path,
            /* [string][in] */ OLECHAR *name,
            /* [out] */ SHORT *pResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Criteria( 
            /* [out] */ IWsbCollection **ppWsbCollection) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumCriteria( 
            /* [out] */ IWsbEnum **ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetName( 
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSearchName( 
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPath( 
            /* [string][out][in] */ OLECHAR **pPath,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsInclude( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsUserDefined( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsUsedInSubDirs( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MatchesName( 
            /* [string][in] */ OLECHAR *name) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetIsInclude( 
            /* [in] */ BOOL isInclude) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetIsUserDefined( 
            /* [in] */ BOOL isUserDefined) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetIsUsedInSubDirs( 
            /* [in] */ BOOL isUsed) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetName( 
            /* [string][in] */ OLECHAR *name) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPath( 
            /* [string][in] */ OLECHAR *path) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHsmRuleVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHsmRule * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHsmRule * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHsmRule * This);
        
        HRESULT ( STDMETHODCALLTYPE *CompareToIRule )( 
            IHsmRule * This,
            /* [in] */ IHsmRule *pRule,
            /* [out] */ SHORT *pResult);
        
        HRESULT ( STDMETHODCALLTYPE *CompareToPathAndName )( 
            IHsmRule * This,
            /* [string][in] */ OLECHAR *path,
            /* [string][in] */ OLECHAR *name,
            /* [out] */ SHORT *pResult);
        
        HRESULT ( STDMETHODCALLTYPE *Criteria )( 
            IHsmRule * This,
            /* [out] */ IWsbCollection **ppWsbCollection);
        
        HRESULT ( STDMETHODCALLTYPE *EnumCriteria )( 
            IHsmRule * This,
            /* [out] */ IWsbEnum **ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE *GetName )( 
            IHsmRule * This,
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetSearchName )( 
            IHsmRule * This,
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetPath )( 
            IHsmRule * This,
            /* [string][out][in] */ OLECHAR **pPath,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *IsInclude )( 
            IHsmRule * This);
        
        HRESULT ( STDMETHODCALLTYPE *IsUserDefined )( 
            IHsmRule * This);
        
        HRESULT ( STDMETHODCALLTYPE *IsUsedInSubDirs )( 
            IHsmRule * This);
        
        HRESULT ( STDMETHODCALLTYPE *MatchesName )( 
            IHsmRule * This,
            /* [string][in] */ OLECHAR *name);
        
        HRESULT ( STDMETHODCALLTYPE *SetIsInclude )( 
            IHsmRule * This,
            /* [in] */ BOOL isInclude);
        
        HRESULT ( STDMETHODCALLTYPE *SetIsUserDefined )( 
            IHsmRule * This,
            /* [in] */ BOOL isUserDefined);
        
        HRESULT ( STDMETHODCALLTYPE *SetIsUsedInSubDirs )( 
            IHsmRule * This,
            /* [in] */ BOOL isUsed);
        
        HRESULT ( STDMETHODCALLTYPE *SetName )( 
            IHsmRule * This,
            /* [string][in] */ OLECHAR *name);
        
        HRESULT ( STDMETHODCALLTYPE *SetPath )( 
            IHsmRule * This,
            /* [string][in] */ OLECHAR *path);
        
        END_INTERFACE
    } IHsmRuleVtbl;

    interface IHsmRule
    {
        CONST_VTBL struct IHsmRuleVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHsmRule_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHsmRule_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHsmRule_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHsmRule_CompareToIRule(This,pRule,pResult)	\
    (This)->lpVtbl -> CompareToIRule(This,pRule,pResult)

#define IHsmRule_CompareToPathAndName(This,path,name,pResult)	\
    (This)->lpVtbl -> CompareToPathAndName(This,path,name,pResult)

#define IHsmRule_Criteria(This,ppWsbCollection)	\
    (This)->lpVtbl -> Criteria(This,ppWsbCollection)

#define IHsmRule_EnumCriteria(This,ppEnum)	\
    (This)->lpVtbl -> EnumCriteria(This,ppEnum)

#define IHsmRule_GetName(This,pName,bufferSize)	\
    (This)->lpVtbl -> GetName(This,pName,bufferSize)

#define IHsmRule_GetSearchName(This,pName,bufferSize)	\
    (This)->lpVtbl -> GetSearchName(This,pName,bufferSize)

#define IHsmRule_GetPath(This,pPath,bufferSize)	\
    (This)->lpVtbl -> GetPath(This,pPath,bufferSize)

#define IHsmRule_IsInclude(This)	\
    (This)->lpVtbl -> IsInclude(This)

#define IHsmRule_IsUserDefined(This)	\
    (This)->lpVtbl -> IsUserDefined(This)

#define IHsmRule_IsUsedInSubDirs(This)	\
    (This)->lpVtbl -> IsUsedInSubDirs(This)

#define IHsmRule_MatchesName(This,name)	\
    (This)->lpVtbl -> MatchesName(This,name)

#define IHsmRule_SetIsInclude(This,isInclude)	\
    (This)->lpVtbl -> SetIsInclude(This,isInclude)

#define IHsmRule_SetIsUserDefined(This,isUserDefined)	\
    (This)->lpVtbl -> SetIsUserDefined(This,isUserDefined)

#define IHsmRule_SetIsUsedInSubDirs(This,isUsed)	\
    (This)->lpVtbl -> SetIsUsedInSubDirs(This,isUsed)

#define IHsmRule_SetName(This,name)	\
    (This)->lpVtbl -> SetName(This,name)

#define IHsmRule_SetPath(This,path)	\
    (This)->lpVtbl -> SetPath(This,path)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IHsmRule_CompareToIRule_Proxy( 
    IHsmRule * This,
    /* [in] */ IHsmRule *pRule,
    /* [out] */ SHORT *pResult);


void __RPC_STUB IHsmRule_CompareToIRule_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRule_CompareToPathAndName_Proxy( 
    IHsmRule * This,
    /* [string][in] */ OLECHAR *path,
    /* [string][in] */ OLECHAR *name,
    /* [out] */ SHORT *pResult);


void __RPC_STUB IHsmRule_CompareToPathAndName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRule_Criteria_Proxy( 
    IHsmRule * This,
    /* [out] */ IWsbCollection **ppWsbCollection);


void __RPC_STUB IHsmRule_Criteria_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRule_EnumCriteria_Proxy( 
    IHsmRule * This,
    /* [out] */ IWsbEnum **ppEnum);


void __RPC_STUB IHsmRule_EnumCriteria_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRule_GetName_Proxy( 
    IHsmRule * This,
    /* [string][out][in] */ OLECHAR **pName,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IHsmRule_GetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRule_GetSearchName_Proxy( 
    IHsmRule * This,
    /* [string][out][in] */ OLECHAR **pName,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IHsmRule_GetSearchName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRule_GetPath_Proxy( 
    IHsmRule * This,
    /* [string][out][in] */ OLECHAR **pPath,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IHsmRule_GetPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRule_IsInclude_Proxy( 
    IHsmRule * This);


void __RPC_STUB IHsmRule_IsInclude_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRule_IsUserDefined_Proxy( 
    IHsmRule * This);


void __RPC_STUB IHsmRule_IsUserDefined_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRule_IsUsedInSubDirs_Proxy( 
    IHsmRule * This);


void __RPC_STUB IHsmRule_IsUsedInSubDirs_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRule_MatchesName_Proxy( 
    IHsmRule * This,
    /* [string][in] */ OLECHAR *name);


void __RPC_STUB IHsmRule_MatchesName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRule_SetIsInclude_Proxy( 
    IHsmRule * This,
    /* [in] */ BOOL isInclude);


void __RPC_STUB IHsmRule_SetIsInclude_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRule_SetIsUserDefined_Proxy( 
    IHsmRule * This,
    /* [in] */ BOOL isUserDefined);


void __RPC_STUB IHsmRule_SetIsUserDefined_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRule_SetIsUsedInSubDirs_Proxy( 
    IHsmRule * This,
    /* [in] */ BOOL isUsed);


void __RPC_STUB IHsmRule_SetIsUsedInSubDirs_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRule_SetName_Proxy( 
    IHsmRule * This,
    /* [string][in] */ OLECHAR *name);


void __RPC_STUB IHsmRule_SetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRule_SetPath_Proxy( 
    IHsmRule * This,
    /* [string][in] */ OLECHAR *path);


void __RPC_STUB IHsmRule_SetPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IHsmRule_INTERFACE_DEFINED__ */


#ifndef __IHsmRuleStack_INTERFACE_DEFINED__
#define __IHsmRuleStack_INTERFACE_DEFINED__

/* interface IHsmRuleStack */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IHsmRuleStack;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7B22FF21-1AD6-11D0-81B1-00A0C91180F2")
    IHsmRuleStack : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Do( 
            /* [in] */ IFsaScanItem *pScanItem) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DoesMatch( 
            /* [in] */ IFsaScanItem *pScanItem,
            BOOL *pShouldDo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Init( 
            /* [in] */ IHsmPolicy *pPolicy,
            /* [in] */ IFsaResource *pResource) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Pop( 
            /* [string][in] */ OLECHAR *path) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Push( 
            /* [string][in] */ OLECHAR *path) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHsmRuleStackVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHsmRuleStack * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHsmRuleStack * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHsmRuleStack * This);
        
        HRESULT ( STDMETHODCALLTYPE *Do )( 
            IHsmRuleStack * This,
            /* [in] */ IFsaScanItem *pScanItem);
        
        HRESULT ( STDMETHODCALLTYPE *DoesMatch )( 
            IHsmRuleStack * This,
            /* [in] */ IFsaScanItem *pScanItem,
            BOOL *pShouldDo);
        
        HRESULT ( STDMETHODCALLTYPE *Init )( 
            IHsmRuleStack * This,
            /* [in] */ IHsmPolicy *pPolicy,
            /* [in] */ IFsaResource *pResource);
        
        HRESULT ( STDMETHODCALLTYPE *Pop )( 
            IHsmRuleStack * This,
            /* [string][in] */ OLECHAR *path);
        
        HRESULT ( STDMETHODCALLTYPE *Push )( 
            IHsmRuleStack * This,
            /* [string][in] */ OLECHAR *path);
        
        END_INTERFACE
    } IHsmRuleStackVtbl;

    interface IHsmRuleStack
    {
        CONST_VTBL struct IHsmRuleStackVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHsmRuleStack_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHsmRuleStack_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHsmRuleStack_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHsmRuleStack_Do(This,pScanItem)	\
    (This)->lpVtbl -> Do(This,pScanItem)

#define IHsmRuleStack_DoesMatch(This,pScanItem,pShouldDo)	\
    (This)->lpVtbl -> DoesMatch(This,pScanItem,pShouldDo)

#define IHsmRuleStack_Init(This,pPolicy,pResource)	\
    (This)->lpVtbl -> Init(This,pPolicy,pResource)

#define IHsmRuleStack_Pop(This,path)	\
    (This)->lpVtbl -> Pop(This,path)

#define IHsmRuleStack_Push(This,path)	\
    (This)->lpVtbl -> Push(This,path)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IHsmRuleStack_Do_Proxy( 
    IHsmRuleStack * This,
    /* [in] */ IFsaScanItem *pScanItem);


void __RPC_STUB IHsmRuleStack_Do_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRuleStack_DoesMatch_Proxy( 
    IHsmRuleStack * This,
    /* [in] */ IFsaScanItem *pScanItem,
    BOOL *pShouldDo);


void __RPC_STUB IHsmRuleStack_DoesMatch_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRuleStack_Init_Proxy( 
    IHsmRuleStack * This,
    /* [in] */ IHsmPolicy *pPolicy,
    /* [in] */ IFsaResource *pResource);


void __RPC_STUB IHsmRuleStack_Init_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRuleStack_Pop_Proxy( 
    IHsmRuleStack * This,
    /* [string][in] */ OLECHAR *path);


void __RPC_STUB IHsmRuleStack_Pop_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmRuleStack_Push_Proxy( 
    IHsmRuleStack * This,
    /* [string][in] */ OLECHAR *path);


void __RPC_STUB IHsmRuleStack_Push_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IHsmRuleStack_INTERFACE_DEFINED__ */


#ifndef __IHsmScanner_INTERFACE_DEFINED__
#define __IHsmScanner_INTERFACE_DEFINED__

/* interface IHsmScanner */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IHsmScanner;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BEA60F83-7EBA-11d0-81E4-00A0C91180F2")
    IHsmScanner : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Start( 
            /* [in] */ IHsmSession *pSession,
            /* [string][in] */ OLECHAR *path) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHsmScannerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHsmScanner * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHsmScanner * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHsmScanner * This);
        
        HRESULT ( STDMETHODCALLTYPE *Start )( 
            IHsmScanner * This,
            /* [in] */ IHsmSession *pSession,
            /* [string][in] */ OLECHAR *path);
        
        END_INTERFACE
    } IHsmScannerVtbl;

    interface IHsmScanner
    {
        CONST_VTBL struct IHsmScannerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHsmScanner_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHsmScanner_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHsmScanner_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHsmScanner_Start(This,pSession,path)	\
    (This)->lpVtbl -> Start(This,pSession,path)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IHsmScanner_Start_Proxy( 
    IHsmScanner * This,
    /* [in] */ IHsmSession *pSession,
    /* [string][in] */ OLECHAR *path);


void __RPC_STUB IHsmScanner_Start_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IHsmScanner_INTERFACE_DEFINED__ */


#ifndef __IHsmSession_INTERFACE_DEFINED__
#define __IHsmSession_INTERFACE_DEFINED__

/* interface IHsmSession */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IHsmSession;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6E7196DC-7F9C-460D-9E97-845490B81D60")
    IHsmSession : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Cancel( 
            /* [in] */ HSM_JOB_PHASE phase) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumPhases( 
            /* [out] */ IWsbEnum **ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumTotals( 
            /* [out] */ IWsbEnum **ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAdviseInterval( 
            /* [out] */ LONGLONG *pFiletimeTicks) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetHsmId( 
            /* [out] */ GUID *pId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIdentifier( 
            /* [out] */ GUID *pId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetJob( 
            /* [out] */ IHsmJob **ppJob) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetName( 
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetResource( 
            /* [out] */ IFsaResource **ppResource) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRunId( 
            /* [out] */ ULONG *pId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSubRunId( 
            /* [out] */ ULONG *pId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsCanceling( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Pause( 
            /* [in] */ HSM_JOB_PHASE phase) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ProcessEvent( 
            /* [in] */ HSM_JOB_PHASE phase,
            /* [in] */ HSM_JOB_EVENT event) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ProcessHr( 
            /* [in] */ HSM_JOB_PHASE phase,
            /* [string][in] */ CHAR *file,
            /* [in] */ ULONG line,
            /* [in] */ HRESULT hr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ProcessItem( 
            /* [in] */ HSM_JOB_PHASE phase,
            /* [in] */ HSM_JOB_ACTION action,
            /* [in] */ IFsaScanItem *pScanItem,
            /* [in] */ HRESULT hrItem) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ProcessMediaState( 
            /* [in] */ HSM_JOB_PHASE phase,
            /* [in] */ HSM_JOB_MEDIA_STATE state,
            /* [string][in] */ OLECHAR *mediaName,
            /* [in] */ HSM_JOB_MEDIA_TYPE mediaType,
            /* [in] */ ULONG time) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ProcessPriority( 
            /* [in] */ HSM_JOB_PHASE phase,
            /* [in] */ HSM_JOB_PRIORITY priority) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ProcessState( 
            /* [in] */ HSM_JOB_PHASE phase,
            /* [in] */ HSM_JOB_STATE state,
            /* [string][in] */ OLECHAR *currentPath,
            /* [in] */ BOOL bLog) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ProcessString( 
            /* [in] */ HSM_JOB_PHASE phase,
            /* [string][in] */ OLECHAR *string) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Resume( 
            /* [in] */ HSM_JOB_PHASE phase) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAdviseInterval( 
            /* [in] */ LONGLONG filetimeTicks) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Start( 
            /* [string][in] */ OLECHAR *name,
            /* [in] */ ULONG logControl,
            /* [in] */ GUID hsmId,
            /* [in] */ IHsmJob *pJob,
            /* [in] */ IFsaResource *pResource,
            /* [in] */ ULONG runId,
            /* [in] */ ULONG subRunId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Suspend( 
            /* [in] */ HSM_JOB_PHASE phase) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHsmSessionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHsmSession * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHsmSession * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHsmSession * This);
        
        HRESULT ( STDMETHODCALLTYPE *Cancel )( 
            IHsmSession * This,
            /* [in] */ HSM_JOB_PHASE phase);
        
        HRESULT ( STDMETHODCALLTYPE *EnumPhases )( 
            IHsmSession * This,
            /* [out] */ IWsbEnum **ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE *EnumTotals )( 
            IHsmSession * This,
            /* [out] */ IWsbEnum **ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE *GetAdviseInterval )( 
            IHsmSession * This,
            /* [out] */ LONGLONG *pFiletimeTicks);
        
        HRESULT ( STDMETHODCALLTYPE *GetHsmId )( 
            IHsmSession * This,
            /* [out] */ GUID *pId);
        
        HRESULT ( STDMETHODCALLTYPE *GetIdentifier )( 
            IHsmSession * This,
            /* [out] */ GUID *pId);
        
        HRESULT ( STDMETHODCALLTYPE *GetJob )( 
            IHsmSession * This,
            /* [out] */ IHsmJob **ppJob);
        
        HRESULT ( STDMETHODCALLTYPE *GetName )( 
            IHsmSession * This,
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetResource )( 
            IHsmSession * This,
            /* [out] */ IFsaResource **ppResource);
        
        HRESULT ( STDMETHODCALLTYPE *GetRunId )( 
            IHsmSession * This,
            /* [out] */ ULONG *pId);
        
        HRESULT ( STDMETHODCALLTYPE *GetSubRunId )( 
            IHsmSession * This,
            /* [out] */ ULONG *pId);
        
        HRESULT ( STDMETHODCALLTYPE *IsCanceling )( 
            IHsmSession * This);
        
        HRESULT ( STDMETHODCALLTYPE *Pause )( 
            IHsmSession * This,
            /* [in] */ HSM_JOB_PHASE phase);
        
        HRESULT ( STDMETHODCALLTYPE *ProcessEvent )( 
            IHsmSession * This,
            /* [in] */ HSM_JOB_PHASE phase,
            /* [in] */ HSM_JOB_EVENT event);
        
        HRESULT ( STDMETHODCALLTYPE *ProcessHr )( 
            IHsmSession * This,
            /* [in] */ HSM_JOB_PHASE phase,
            /* [string][in] */ CHAR *file,
            /* [in] */ ULONG line,
            /* [in] */ HRESULT hr);
        
        HRESULT ( STDMETHODCALLTYPE *ProcessItem )( 
            IHsmSession * This,
            /* [in] */ HSM_JOB_PHASE phase,
            /* [in] */ HSM_JOB_ACTION action,
            /* [in] */ IFsaScanItem *pScanItem,
            /* [in] */ HRESULT hrItem);
        
        HRESULT ( STDMETHODCALLTYPE *ProcessMediaState )( 
            IHsmSession * This,
            /* [in] */ HSM_JOB_PHASE phase,
            /* [in] */ HSM_JOB_MEDIA_STATE state,
            /* [string][in] */ OLECHAR *mediaName,
            /* [in] */ HSM_JOB_MEDIA_TYPE mediaType,
            /* [in] */ ULONG time);
        
        HRESULT ( STDMETHODCALLTYPE *ProcessPriority )( 
            IHsmSession * This,
            /* [in] */ HSM_JOB_PHASE phase,
            /* [in] */ HSM_JOB_PRIORITY priority);
        
        HRESULT ( STDMETHODCALLTYPE *ProcessState )( 
            IHsmSession * This,
            /* [in] */ HSM_JOB_PHASE phase,
            /* [in] */ HSM_JOB_STATE state,
            /* [string][in] */ OLECHAR *currentPath,
            /* [in] */ BOOL bLog);
        
        HRESULT ( STDMETHODCALLTYPE *ProcessString )( 
            IHsmSession * This,
            /* [in] */ HSM_JOB_PHASE phase,
            /* [string][in] */ OLECHAR *string);
        
        HRESULT ( STDMETHODCALLTYPE *Resume )( 
            IHsmSession * This,
            /* [in] */ HSM_JOB_PHASE phase);
        
        HRESULT ( STDMETHODCALLTYPE *SetAdviseInterval )( 
            IHsmSession * This,
            /* [in] */ LONGLONG filetimeTicks);
        
        HRESULT ( STDMETHODCALLTYPE *Start )( 
            IHsmSession * This,
            /* [string][in] */ OLECHAR *name,
            /* [in] */ ULONG logControl,
            /* [in] */ GUID hsmId,
            /* [in] */ IHsmJob *pJob,
            /* [in] */ IFsaResource *pResource,
            /* [in] */ ULONG runId,
            /* [in] */ ULONG subRunId);
        
        HRESULT ( STDMETHODCALLTYPE *Suspend )( 
            IHsmSession * This,
            /* [in] */ HSM_JOB_PHASE phase);
        
        END_INTERFACE
    } IHsmSessionVtbl;

    interface IHsmSession
    {
        CONST_VTBL struct IHsmSessionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHsmSession_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHsmSession_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHsmSession_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHsmSession_Cancel(This,phase)	\
    (This)->lpVtbl -> Cancel(This,phase)

#define IHsmSession_EnumPhases(This,ppEnum)	\
    (This)->lpVtbl -> EnumPhases(This,ppEnum)

#define IHsmSession_EnumTotals(This,ppEnum)	\
    (This)->lpVtbl -> EnumTotals(This,ppEnum)

#define IHsmSession_GetAdviseInterval(This,pFiletimeTicks)	\
    (This)->lpVtbl -> GetAdviseInterval(This,pFiletimeTicks)

#define IHsmSession_GetHsmId(This,pId)	\
    (This)->lpVtbl -> GetHsmId(This,pId)

#define IHsmSession_GetIdentifier(This,pId)	\
    (This)->lpVtbl -> GetIdentifier(This,pId)

#define IHsmSession_GetJob(This,ppJob)	\
    (This)->lpVtbl -> GetJob(This,ppJob)

#define IHsmSession_GetName(This,pName,bufferSize)	\
    (This)->lpVtbl -> GetName(This,pName,bufferSize)

#define IHsmSession_GetResource(This,ppResource)	\
    (This)->lpVtbl -> GetResource(This,ppResource)

#define IHsmSession_GetRunId(This,pId)	\
    (This)->lpVtbl -> GetRunId(This,pId)

#define IHsmSession_GetSubRunId(This,pId)	\
    (This)->lpVtbl -> GetSubRunId(This,pId)

#define IHsmSession_IsCanceling(This)	\
    (This)->lpVtbl -> IsCanceling(This)

#define IHsmSession_Pause(This,phase)	\
    (This)->lpVtbl -> Pause(This,phase)

#define IHsmSession_ProcessEvent(This,phase,event)	\
    (This)->lpVtbl -> ProcessEvent(This,phase,event)

#define IHsmSession_ProcessHr(This,phase,file,line,hr)	\
    (This)->lpVtbl -> ProcessHr(This,phase,file,line,hr)

#define IHsmSession_ProcessItem(This,phase,action,pScanItem,hrItem)	\
    (This)->lpVtbl -> ProcessItem(This,phase,action,pScanItem,hrItem)

#define IHsmSession_ProcessMediaState(This,phase,state,mediaName,mediaType,time)	\
    (This)->lpVtbl -> ProcessMediaState(This,phase,state,mediaName,mediaType,time)

#define IHsmSession_ProcessPriority(This,phase,priority)	\
    (This)->lpVtbl -> ProcessPriority(This,phase,priority)

#define IHsmSession_ProcessState(This,phase,state,currentPath,bLog)	\
    (This)->lpVtbl -> ProcessState(This,phase,state,currentPath,bLog)

#define IHsmSession_ProcessString(This,phase,string)	\
    (This)->lpVtbl -> ProcessString(This,phase,string)

#define IHsmSession_Resume(This,phase)	\
    (This)->lpVtbl -> Resume(This,phase)

#define IHsmSession_SetAdviseInterval(This,filetimeTicks)	\
    (This)->lpVtbl -> SetAdviseInterval(This,filetimeTicks)

#define IHsmSession_Start(This,name,logControl,hsmId,pJob,pResource,runId,subRunId)	\
    (This)->lpVtbl -> Start(This,name,logControl,hsmId,pJob,pResource,runId,subRunId)

#define IHsmSession_Suspend(This,phase)	\
    (This)->lpVtbl -> Suspend(This,phase)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IHsmSession_Cancel_Proxy( 
    IHsmSession * This,
    /* [in] */ HSM_JOB_PHASE phase);


void __RPC_STUB IHsmSession_Cancel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmSession_EnumPhases_Proxy( 
    IHsmSession * This,
    /* [out] */ IWsbEnum **ppEnum);


void __RPC_STUB IHsmSession_EnumPhases_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmSession_EnumTotals_Proxy( 
    IHsmSession * This,
    /* [out] */ IWsbEnum **ppEnum);


void __RPC_STUB IHsmSession_EnumTotals_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmSession_GetAdviseInterval_Proxy( 
    IHsmSession * This,
    /* [out] */ LONGLONG *pFiletimeTicks);


void __RPC_STUB IHsmSession_GetAdviseInterval_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmSession_GetHsmId_Proxy( 
    IHsmSession * This,
    /* [out] */ GUID *pId);


void __RPC_STUB IHsmSession_GetHsmId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmSession_GetIdentifier_Proxy( 
    IHsmSession * This,
    /* [out] */ GUID *pId);


void __RPC_STUB IHsmSession_GetIdentifier_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmSession_GetJob_Proxy( 
    IHsmSession * This,
    /* [out] */ IHsmJob **ppJob);


void __RPC_STUB IHsmSession_GetJob_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmSession_GetName_Proxy( 
    IHsmSession * This,
    /* [string][out][in] */ OLECHAR **pName,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IHsmSession_GetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmSession_GetResource_Proxy( 
    IHsmSession * This,
    /* [out] */ IFsaResource **ppResource);


void __RPC_STUB IHsmSession_GetResource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmSession_GetRunId_Proxy( 
    IHsmSession * This,
    /* [out] */ ULONG *pId);


void __RPC_STUB IHsmSession_GetRunId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmSession_GetSubRunId_Proxy( 
    IHsmSession * This,
    /* [out] */ ULONG *pId);


void __RPC_STUB IHsmSession_GetSubRunId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmSession_IsCanceling_Proxy( 
    IHsmSession * This);


void __RPC_STUB IHsmSession_IsCanceling_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmSession_Pause_Proxy( 
    IHsmSession * This,
    /* [in] */ HSM_JOB_PHASE phase);


void __RPC_STUB IHsmSession_Pause_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmSession_ProcessEvent_Proxy( 
    IHsmSession * This,
    /* [in] */ HSM_JOB_PHASE phase,
    /* [in] */ HSM_JOB_EVENT event);


void __RPC_STUB IHsmSession_ProcessEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmSession_ProcessHr_Proxy( 
    IHsmSession * This,
    /* [in] */ HSM_JOB_PHASE phase,
    /* [string][in] */ CHAR *file,
    /* [in] */ ULONG line,
    /* [in] */ HRESULT hr);


void __RPC_STUB IHsmSession_ProcessHr_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmSession_ProcessItem_Proxy( 
    IHsmSession * This,
    /* [in] */ HSM_JOB_PHASE phase,
    /* [in] */ HSM_JOB_ACTION action,
    /* [in] */ IFsaScanItem *pScanItem,
    /* [in] */ HRESULT hrItem);


void __RPC_STUB IHsmSession_ProcessItem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmSession_ProcessMediaState_Proxy( 
    IHsmSession * This,
    /* [in] */ HSM_JOB_PHASE phase,
    /* [in] */ HSM_JOB_MEDIA_STATE state,
    /* [string][in] */ OLECHAR *mediaName,
    /* [in] */ HSM_JOB_MEDIA_TYPE mediaType,
    /* [in] */ ULONG time);


void __RPC_STUB IHsmSession_ProcessMediaState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmSession_ProcessPriority_Proxy( 
    IHsmSession * This,
    /* [in] */ HSM_JOB_PHASE phase,
    /* [in] */ HSM_JOB_PRIORITY priority);


void __RPC_STUB IHsmSession_ProcessPriority_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmSession_ProcessState_Proxy( 
    IHsmSession * This,
    /* [in] */ HSM_JOB_PHASE phase,
    /* [in] */ HSM_JOB_STATE state,
    /* [string][in] */ OLECHAR *currentPath,
    /* [in] */ BOOL bLog);


void __RPC_STUB IHsmSession_ProcessState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmSession_ProcessString_Proxy( 
    IHsmSession * This,
    /* [in] */ HSM_JOB_PHASE phase,
    /* [string][in] */ OLECHAR *string);


void __RPC_STUB IHsmSession_ProcessString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmSession_Resume_Proxy( 
    IHsmSession * This,
    /* [in] */ HSM_JOB_PHASE phase);


void __RPC_STUB IHsmSession_Resume_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmSession_SetAdviseInterval_Proxy( 
    IHsmSession * This,
    /* [in] */ LONGLONG filetimeTicks);


void __RPC_STUB IHsmSession_SetAdviseInterval_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmSession_Start_Proxy( 
    IHsmSession * This,
    /* [string][in] */ OLECHAR *name,
    /* [in] */ ULONG logControl,
    /* [in] */ GUID hsmId,
    /* [in] */ IHsmJob *pJob,
    /* [in] */ IFsaResource *pResource,
    /* [in] */ ULONG runId,
    /* [in] */ ULONG subRunId);


void __RPC_STUB IHsmSession_Start_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmSession_Suspend_Proxy( 
    IHsmSession * This,
    /* [in] */ HSM_JOB_PHASE phase);


void __RPC_STUB IHsmSession_Suspend_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IHsmSession_INTERFACE_DEFINED__ */


#ifndef __IHsmSessionSinkEveryEvent_INTERFACE_DEFINED__
#define __IHsmSessionSinkEveryEvent_INTERFACE_DEFINED__

/* interface IHsmSessionSinkEveryEvent */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IHsmSessionSinkEveryEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F1AAA4E0-8385-11d0-81E4-00A0C91180F2")
    IHsmSessionSinkEveryEvent : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ProcessSessionEvent( 
            /* [in] */ IHsmSession *pSession,
            /* [in] */ HSM_JOB_PHASE phase,
            /* [in] */ HSM_JOB_EVENT event) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHsmSessionSinkEveryEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHsmSessionSinkEveryEvent * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHsmSessionSinkEveryEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHsmSessionSinkEveryEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *ProcessSessionEvent )( 
            IHsmSessionSinkEveryEvent * This,
            /* [in] */ IHsmSession *pSession,
            /* [in] */ HSM_JOB_PHASE phase,
            /* [in] */ HSM_JOB_EVENT event);
        
        END_INTERFACE
    } IHsmSessionSinkEveryEventVtbl;

    interface IHsmSessionSinkEveryEvent
    {
        CONST_VTBL struct IHsmSessionSinkEveryEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHsmSessionSinkEveryEvent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHsmSessionSinkEveryEvent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHsmSessionSinkEveryEvent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHsmSessionSinkEveryEvent_ProcessSessionEvent(This,pSession,phase,event)	\
    (This)->lpVtbl -> ProcessSessionEvent(This,pSession,phase,event)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IHsmSessionSinkEveryEvent_ProcessSessionEvent_Proxy( 
    IHsmSessionSinkEveryEvent * This,
    /* [in] */ IHsmSession *pSession,
    /* [in] */ HSM_JOB_PHASE phase,
    /* [in] */ HSM_JOB_EVENT event);


void __RPC_STUB IHsmSessionSinkEveryEvent_ProcessSessionEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IHsmSessionSinkEveryEvent_INTERFACE_DEFINED__ */


#ifndef __IHsmSessionSinkEveryItem_INTERFACE_DEFINED__
#define __IHsmSessionSinkEveryItem_INTERFACE_DEFINED__

/* interface IHsmSessionSinkEveryItem */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IHsmSessionSinkEveryItem;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BEA60F85-7EBA-11d0-81E4-00A0C91180F2")
    IHsmSessionSinkEveryItem : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ProcessSessionItem( 
            /* [in] */ IHsmSession *pSession,
            /* [in] */ IHsmPhase *pPhase,
            /* [in] */ IFsaScanItem *pScanItem,
            /* [in] */ HRESULT hrItem,
            /* [in] */ IHsmSessionTotals *pSessionTotals) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHsmSessionSinkEveryItemVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHsmSessionSinkEveryItem * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHsmSessionSinkEveryItem * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHsmSessionSinkEveryItem * This);
        
        HRESULT ( STDMETHODCALLTYPE *ProcessSessionItem )( 
            IHsmSessionSinkEveryItem * This,
            /* [in] */ IHsmSession *pSession,
            /* [in] */ IHsmPhase *pPhase,
            /* [in] */ IFsaScanItem *pScanItem,
            /* [in] */ HRESULT hrItem,
            /* [in] */ IHsmSessionTotals *pSessionTotals);
        
        END_INTERFACE
    } IHsmSessionSinkEveryItemVtbl;

    interface IHsmSessionSinkEveryItem
    {
        CONST_VTBL struct IHsmSessionSinkEveryItemVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHsmSessionSinkEveryItem_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHsmSessionSinkEveryItem_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHsmSessionSinkEveryItem_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHsmSessionSinkEveryItem_ProcessSessionItem(This,pSession,pPhase,pScanItem,hrItem,pSessionTotals)	\
    (This)->lpVtbl -> ProcessSessionItem(This,pSession,pPhase,pScanItem,hrItem,pSessionTotals)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IHsmSessionSinkEveryItem_ProcessSessionItem_Proxy( 
    IHsmSessionSinkEveryItem * This,
    /* [in] */ IHsmSession *pSession,
    /* [in] */ IHsmPhase *pPhase,
    /* [in] */ IFsaScanItem *pScanItem,
    /* [in] */ HRESULT hrItem,
    /* [in] */ IHsmSessionTotals *pSessionTotals);


void __RPC_STUB IHsmSessionSinkEveryItem_ProcessSessionItem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IHsmSessionSinkEveryItem_INTERFACE_DEFINED__ */


#ifndef __IHsmSessionSinkEveryMediaState_INTERFACE_DEFINED__
#define __IHsmSessionSinkEveryMediaState_INTERFACE_DEFINED__

/* interface IHsmSessionSinkEveryMediaState */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IHsmSessionSinkEveryMediaState;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D5450542-A6C2-11d0-81E7-00A0C91180F2")
    IHsmSessionSinkEveryMediaState : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ProcessSessionMediaState( 
            /* [in] */ IHsmSession *pSession,
            /* [in] */ IHsmPhase *pPhase,
            /* [in] */ HSM_JOB_MEDIA_STATE state,
            /* [string][in] */ OLECHAR *mediaName,
            /* [in] */ HSM_JOB_MEDIA_TYPE mediaType,
            /* [in] */ ULONG time) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHsmSessionSinkEveryMediaStateVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHsmSessionSinkEveryMediaState * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHsmSessionSinkEveryMediaState * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHsmSessionSinkEveryMediaState * This);
        
        HRESULT ( STDMETHODCALLTYPE *ProcessSessionMediaState )( 
            IHsmSessionSinkEveryMediaState * This,
            /* [in] */ IHsmSession *pSession,
            /* [in] */ IHsmPhase *pPhase,
            /* [in] */ HSM_JOB_MEDIA_STATE state,
            /* [string][in] */ OLECHAR *mediaName,
            /* [in] */ HSM_JOB_MEDIA_TYPE mediaType,
            /* [in] */ ULONG time);
        
        END_INTERFACE
    } IHsmSessionSinkEveryMediaStateVtbl;

    interface IHsmSessionSinkEveryMediaState
    {
        CONST_VTBL struct IHsmSessionSinkEveryMediaStateVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHsmSessionSinkEveryMediaState_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHsmSessionSinkEveryMediaState_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHsmSessionSinkEveryMediaState_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHsmSessionSinkEveryMediaState_ProcessSessionMediaState(This,pSession,pPhase,state,mediaName,mediaType,time)	\
    (This)->lpVtbl -> ProcessSessionMediaState(This,pSession,pPhase,state,mediaName,mediaType,time)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IHsmSessionSinkEveryMediaState_ProcessSessionMediaState_Proxy( 
    IHsmSessionSinkEveryMediaState * This,
    /* [in] */ IHsmSession *pSession,
    /* [in] */ IHsmPhase *pPhase,
    /* [in] */ HSM_JOB_MEDIA_STATE state,
    /* [string][in] */ OLECHAR *mediaName,
    /* [in] */ HSM_JOB_MEDIA_TYPE mediaType,
    /* [in] */ ULONG time);


void __RPC_STUB IHsmSessionSinkEveryMediaState_ProcessSessionMediaState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IHsmSessionSinkEveryMediaState_INTERFACE_DEFINED__ */


#ifndef __IHsmSessionSinkEveryPriority_INTERFACE_DEFINED__
#define __IHsmSessionSinkEveryPriority_INTERFACE_DEFINED__

/* interface IHsmSessionSinkEveryPriority */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IHsmSessionSinkEveryPriority;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D5450543-A6C2-11d0-81E7-00A0C91180F2")
    IHsmSessionSinkEveryPriority : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ProcessSessionPriority( 
            /* [in] */ IHsmSession *pSession,
            /* [in] */ IHsmPhase *pPhase) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHsmSessionSinkEveryPriorityVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHsmSessionSinkEveryPriority * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHsmSessionSinkEveryPriority * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHsmSessionSinkEveryPriority * This);
        
        HRESULT ( STDMETHODCALLTYPE *ProcessSessionPriority )( 
            IHsmSessionSinkEveryPriority * This,
            /* [in] */ IHsmSession *pSession,
            /* [in] */ IHsmPhase *pPhase);
        
        END_INTERFACE
    } IHsmSessionSinkEveryPriorityVtbl;

    interface IHsmSessionSinkEveryPriority
    {
        CONST_VTBL struct IHsmSessionSinkEveryPriorityVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHsmSessionSinkEveryPriority_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHsmSessionSinkEveryPriority_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHsmSessionSinkEveryPriority_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHsmSessionSinkEveryPriority_ProcessSessionPriority(This,pSession,pPhase)	\
    (This)->lpVtbl -> ProcessSessionPriority(This,pSession,pPhase)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IHsmSessionSinkEveryPriority_ProcessSessionPriority_Proxy( 
    IHsmSessionSinkEveryPriority * This,
    /* [in] */ IHsmSession *pSession,
    /* [in] */ IHsmPhase *pPhase);


void __RPC_STUB IHsmSessionSinkEveryPriority_ProcessSessionPriority_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IHsmSessionSinkEveryPriority_INTERFACE_DEFINED__ */


#ifndef __IHsmSessionSinkEveryState_INTERFACE_DEFINED__
#define __IHsmSessionSinkEveryState_INTERFACE_DEFINED__

/* interface IHsmSessionSinkEveryState */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IHsmSessionSinkEveryState;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BEA60F87-7EBA-11d0-81E4-00A0C91180F2")
    IHsmSessionSinkEveryState : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ProcessSessionState( 
            /* [in] */ IHsmSession *pSession,
            /* [in] */ IHsmPhase *pPhase,
            /* [string][in] */ OLECHAR *currentPath) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHsmSessionSinkEveryStateVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHsmSessionSinkEveryState * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHsmSessionSinkEveryState * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHsmSessionSinkEveryState * This);
        
        HRESULT ( STDMETHODCALLTYPE *ProcessSessionState )( 
            IHsmSessionSinkEveryState * This,
            /* [in] */ IHsmSession *pSession,
            /* [in] */ IHsmPhase *pPhase,
            /* [string][in] */ OLECHAR *currentPath);
        
        END_INTERFACE
    } IHsmSessionSinkEveryStateVtbl;

    interface IHsmSessionSinkEveryState
    {
        CONST_VTBL struct IHsmSessionSinkEveryStateVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHsmSessionSinkEveryState_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHsmSessionSinkEveryState_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHsmSessionSinkEveryState_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHsmSessionSinkEveryState_ProcessSessionState(This,pSession,pPhase,currentPath)	\
    (This)->lpVtbl -> ProcessSessionState(This,pSession,pPhase,currentPath)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IHsmSessionSinkEveryState_ProcessSessionState_Proxy( 
    IHsmSessionSinkEveryState * This,
    /* [in] */ IHsmSession *pSession,
    /* [in] */ IHsmPhase *pPhase,
    /* [string][in] */ OLECHAR *currentPath);


void __RPC_STUB IHsmSessionSinkEveryState_ProcessSessionState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IHsmSessionSinkEveryState_INTERFACE_DEFINED__ */


#ifndef __IHsmSessionSinkSomeItems_INTERFACE_DEFINED__
#define __IHsmSessionSinkSomeItems_INTERFACE_DEFINED__

/* interface IHsmSessionSinkSomeItems */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IHsmSessionSinkSomeItems;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BEA60F88-7EBA-11d0-81E4-00A0C91180F2")
    IHsmSessionSinkSomeItems : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ProcessSessionItem( 
            /* [in] */ IHsmSession *pSession,
            /* [in] */ IHsmPhase *pPhase,
            /* [in] */ IFsaScanItem *pScanItem,
            /* [in] */ HRESULT hrItem,
            /* [in] */ IHsmSessionTotals *pSessionTotals) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHsmSessionSinkSomeItemsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHsmSessionSinkSomeItems * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHsmSessionSinkSomeItems * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHsmSessionSinkSomeItems * This);
        
        HRESULT ( STDMETHODCALLTYPE *ProcessSessionItem )( 
            IHsmSessionSinkSomeItems * This,
            /* [in] */ IHsmSession *pSession,
            /* [in] */ IHsmPhase *pPhase,
            /* [in] */ IFsaScanItem *pScanItem,
            /* [in] */ HRESULT hrItem,
            /* [in] */ IHsmSessionTotals *pSessionTotals);
        
        END_INTERFACE
    } IHsmSessionSinkSomeItemsVtbl;

    interface IHsmSessionSinkSomeItems
    {
        CONST_VTBL struct IHsmSessionSinkSomeItemsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHsmSessionSinkSomeItems_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHsmSessionSinkSomeItems_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHsmSessionSinkSomeItems_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHsmSessionSinkSomeItems_ProcessSessionItem(This,pSession,pPhase,pScanItem,hrItem,pSessionTotals)	\
    (This)->lpVtbl -> ProcessSessionItem(This,pSession,pPhase,pScanItem,hrItem,pSessionTotals)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IHsmSessionSinkSomeItems_ProcessSessionItem_Proxy( 
    IHsmSessionSinkSomeItems * This,
    /* [in] */ IHsmSession *pSession,
    /* [in] */ IHsmPhase *pPhase,
    /* [in] */ IFsaScanItem *pScanItem,
    /* [in] */ HRESULT hrItem,
    /* [in] */ IHsmSessionTotals *pSessionTotals);


void __RPC_STUB IHsmSessionSinkSomeItems_ProcessSessionItem_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IHsmSessionSinkSomeItems_INTERFACE_DEFINED__ */


#ifndef __IHsmSessionTotals_INTERFACE_DEFINED__
#define __IHsmSessionTotals_INTERFACE_DEFINED__

/* interface IHsmSessionTotals */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IHsmSessionTotals;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("35035913-0D1C-11d2-9B0C-00104B9A2869")
    IHsmSessionTotals : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IHsmSessionTotals **ppSessionTotals) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CopyTo( 
            /* [in] */ IHsmSessionTotals *pSessionTotals) = 0;
        
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
        
    };
    
#else 	/* C style interface */

    typedef struct IHsmSessionTotalsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHsmSessionTotals * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHsmSessionTotals * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHsmSessionTotals * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IHsmSessionTotals * This,
            /* [out] */ IHsmSessionTotals **ppSessionTotals);
        
        HRESULT ( STDMETHODCALLTYPE *CopyTo )( 
            IHsmSessionTotals * This,
            /* [in] */ IHsmSessionTotals *pSessionTotals);
        
        HRESULT ( STDMETHODCALLTYPE *CompareToAction )( 
            IHsmSessionTotals * This,
            /* [in] */ HSM_JOB_ACTION action,
            /* [out] */ SHORT *pResult);
        
        HRESULT ( STDMETHODCALLTYPE *CompareToISessionTotals )( 
            IHsmSessionTotals * This,
            /* [in] */ IHsmSessionTotals *pTotals,
            /* [out] */ SHORT *pResult);
        
        HRESULT ( STDMETHODCALLTYPE *GetAction )( 
            IHsmSessionTotals * This,
            /* [out] */ HSM_JOB_ACTION *pAction);
        
        HRESULT ( STDMETHODCALLTYPE *GetName )( 
            IHsmSessionTotals * This,
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetStats )( 
            IHsmSessionTotals * This,
            /* [out] */ LONGLONG *items,
            /* [out] */ LONGLONG *size,
            /* [out] */ LONGLONG *skippedItems,
            /* [out] */ LONGLONG *skippedSize,
            /* [out] */ LONGLONG *errorItems,
            /* [out] */ LONGLONG *errorSize);
        
        END_INTERFACE
    } IHsmSessionTotalsVtbl;

    interface IHsmSessionTotals
    {
        CONST_VTBL struct IHsmSessionTotalsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHsmSessionTotals_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHsmSessionTotals_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHsmSessionTotals_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHsmSessionTotals_Clone(This,ppSessionTotals)	\
    (This)->lpVtbl -> Clone(This,ppSessionTotals)

#define IHsmSessionTotals_CopyTo(This,pSessionTotals)	\
    (This)->lpVtbl -> CopyTo(This,pSessionTotals)

#define IHsmSessionTotals_CompareToAction(This,action,pResult)	\
    (This)->lpVtbl -> CompareToAction(This,action,pResult)

#define IHsmSessionTotals_CompareToISessionTotals(This,pTotals,pResult)	\
    (This)->lpVtbl -> CompareToISessionTotals(This,pTotals,pResult)

#define IHsmSessionTotals_GetAction(This,pAction)	\
    (This)->lpVtbl -> GetAction(This,pAction)

#define IHsmSessionTotals_GetName(This,pName,bufferSize)	\
    (This)->lpVtbl -> GetName(This,pName,bufferSize)

#define IHsmSessionTotals_GetStats(This,items,size,skippedItems,skippedSize,errorItems,errorSize)	\
    (This)->lpVtbl -> GetStats(This,items,size,skippedItems,skippedSize,errorItems,errorSize)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IHsmSessionTotals_Clone_Proxy( 
    IHsmSessionTotals * This,
    /* [out] */ IHsmSessionTotals **ppSessionTotals);


void __RPC_STUB IHsmSessionTotals_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmSessionTotals_CopyTo_Proxy( 
    IHsmSessionTotals * This,
    /* [in] */ IHsmSessionTotals *pSessionTotals);


void __RPC_STUB IHsmSessionTotals_CopyTo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmSessionTotals_CompareToAction_Proxy( 
    IHsmSessionTotals * This,
    /* [in] */ HSM_JOB_ACTION action,
    /* [out] */ SHORT *pResult);


void __RPC_STUB IHsmSessionTotals_CompareToAction_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmSessionTotals_CompareToISessionTotals_Proxy( 
    IHsmSessionTotals * This,
    /* [in] */ IHsmSessionTotals *pTotals,
    /* [out] */ SHORT *pResult);


void __RPC_STUB IHsmSessionTotals_CompareToISessionTotals_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmSessionTotals_GetAction_Proxy( 
    IHsmSessionTotals * This,
    /* [out] */ HSM_JOB_ACTION *pAction);


void __RPC_STUB IHsmSessionTotals_GetAction_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmSessionTotals_GetName_Proxy( 
    IHsmSessionTotals * This,
    /* [string][out][in] */ OLECHAR **pName,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IHsmSessionTotals_GetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmSessionTotals_GetStats_Proxy( 
    IHsmSessionTotals * This,
    /* [out] */ LONGLONG *items,
    /* [out] */ LONGLONG *size,
    /* [out] */ LONGLONG *skippedItems,
    /* [out] */ LONGLONG *skippedSize,
    /* [out] */ LONGLONG *errorItems,
    /* [out] */ LONGLONG *errorSize);


void __RPC_STUB IHsmSessionTotals_GetStats_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IHsmSessionTotals_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


