

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for wsbint.idl:
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

#ifndef __wsbint_h__
#define __wsbint_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IWsbCollectable_FWD_DEFINED__
#define __IWsbCollectable_FWD_DEFINED__
typedef interface IWsbCollectable IWsbCollectable;
#endif 	/* __IWsbCollectable_FWD_DEFINED__ */


#ifndef __IWsbCollection_FWD_DEFINED__
#define __IWsbCollection_FWD_DEFINED__
typedef interface IWsbCollection IWsbCollection;
#endif 	/* __IWsbCollection_FWD_DEFINED__ */


#ifndef __IWsbEnum_FWD_DEFINED__
#define __IWsbEnum_FWD_DEFINED__
typedef interface IWsbEnum IWsbEnum;
#endif 	/* __IWsbEnum_FWD_DEFINED__ */


#ifndef __IWsbEnumEx_FWD_DEFINED__
#define __IWsbEnumEx_FWD_DEFINED__
typedef interface IWsbEnumEx IWsbEnumEx;
#endif 	/* __IWsbEnumEx_FWD_DEFINED__ */


#ifndef __IWsbGuid_FWD_DEFINED__
#define __IWsbGuid_FWD_DEFINED__
typedef interface IWsbGuid IWsbGuid;
#endif 	/* __IWsbGuid_FWD_DEFINED__ */


#ifndef __IWsbIndexedCollection_FWD_DEFINED__
#define __IWsbIndexedCollection_FWD_DEFINED__
typedef interface IWsbIndexedCollection IWsbIndexedCollection;
#endif 	/* __IWsbIndexedCollection_FWD_DEFINED__ */


#ifndef __IWsbPersistStream_FWD_DEFINED__
#define __IWsbPersistStream_FWD_DEFINED__
typedef interface IWsbPersistStream IWsbPersistStream;
#endif 	/* __IWsbPersistStream_FWD_DEFINED__ */


#ifndef __IWsbPersistable_FWD_DEFINED__
#define __IWsbPersistable_FWD_DEFINED__
typedef interface IWsbPersistable IWsbPersistable;
#endif 	/* __IWsbPersistable_FWD_DEFINED__ */


#ifndef __IWsbString_FWD_DEFINED__
#define __IWsbString_FWD_DEFINED__
typedef interface IWsbString IWsbString;
#endif 	/* __IWsbString_FWD_DEFINED__ */


#ifndef __IWsbTestable_FWD_DEFINED__
#define __IWsbTestable_FWD_DEFINED__
typedef interface IWsbTestable IWsbTestable;
#endif 	/* __IWsbTestable_FWD_DEFINED__ */


#ifndef __IWsbDbSys_FWD_DEFINED__
#define __IWsbDbSys_FWD_DEFINED__
typedef interface IWsbDbSys IWsbDbSys;
#endif 	/* __IWsbDbSys_FWD_DEFINED__ */


#ifndef __IWsbDb_FWD_DEFINED__
#define __IWsbDb_FWD_DEFINED__
typedef interface IWsbDb IWsbDb;
#endif 	/* __IWsbDb_FWD_DEFINED__ */


#ifndef __IWsbDbSession_FWD_DEFINED__
#define __IWsbDbSession_FWD_DEFINED__
typedef interface IWsbDbSession IWsbDbSession;
#endif 	/* __IWsbDbSession_FWD_DEFINED__ */


#ifndef __IWsbDbKey_FWD_DEFINED__
#define __IWsbDbKey_FWD_DEFINED__
typedef interface IWsbDbKey IWsbDbKey;
#endif 	/* __IWsbDbKey_FWD_DEFINED__ */


#ifndef __IWsbDbEntity_FWD_DEFINED__
#define __IWsbDbEntity_FWD_DEFINED__
typedef interface IWsbDbEntity IWsbDbEntity;
#endif 	/* __IWsbDbEntity_FWD_DEFINED__ */


#ifndef __IWsbCreateLocalObject_FWD_DEFINED__
#define __IWsbCreateLocalObject_FWD_DEFINED__
typedef interface IWsbCreateLocalObject IWsbCreateLocalObject;
#endif 	/* __IWsbCreateLocalObject_FWD_DEFINED__ */


#ifndef __IWsbTrace_FWD_DEFINED__
#define __IWsbTrace_FWD_DEFINED__
typedef interface IWsbTrace IWsbTrace;
#endif 	/* __IWsbTrace_FWD_DEFINED__ */


#ifndef __IWsbDbSysPriv_FWD_DEFINED__
#define __IWsbDbSysPriv_FWD_DEFINED__
typedef interface IWsbDbSysPriv IWsbDbSysPriv;
#endif 	/* __IWsbDbSysPriv_FWD_DEFINED__ */


#ifndef __IWsbDbPriv_FWD_DEFINED__
#define __IWsbDbPriv_FWD_DEFINED__
typedef interface IWsbDbPriv IWsbDbPriv;
#endif 	/* __IWsbDbPriv_FWD_DEFINED__ */


#ifndef __IWsbDbSessionPriv_FWD_DEFINED__
#define __IWsbDbSessionPriv_FWD_DEFINED__
typedef interface IWsbDbSessionPriv IWsbDbSessionPriv;
#endif 	/* __IWsbDbSessionPriv_FWD_DEFINED__ */


#ifndef __IWsbDbKeyPriv_FWD_DEFINED__
#define __IWsbDbKeyPriv_FWD_DEFINED__
typedef interface IWsbDbKeyPriv IWsbDbKeyPriv;
#endif 	/* __IWsbDbKeyPriv_FWD_DEFINED__ */


#ifndef __IWsbDbEntityPriv_FWD_DEFINED__
#define __IWsbDbEntityPriv_FWD_DEFINED__
typedef interface IWsbDbEntityPriv IWsbDbEntityPriv;
#endif 	/* __IWsbDbEntityPriv_FWD_DEFINED__ */


#ifndef __IWsbServer_FWD_DEFINED__
#define __IWsbServer_FWD_DEFINED__
typedef interface IWsbServer IWsbServer;
#endif 	/* __IWsbServer_FWD_DEFINED__ */


#ifndef __IHsmSystemState_FWD_DEFINED__
#define __IHsmSystemState_FWD_DEFINED__
typedef interface IHsmSystemState IHsmSystemState;
#endif 	/* __IHsmSystemState_FWD_DEFINED__ */


#ifndef __IHsmEvent_FWD_DEFINED__
#define __IHsmEvent_FWD_DEFINED__
typedef interface IHsmEvent IHsmEvent;
#endif 	/* __IHsmEvent_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "wsbdef.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

/* interface __MIDL_itf_wsbint_0000 */
/* [local] */ 







extern RPC_IF_HANDLE __MIDL_itf_wsbint_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_wsbint_0000_v0_0_s_ifspec;

#ifndef __IWsbCollectable_INTERFACE_DEFINED__
#define __IWsbCollectable_INTERFACE_DEFINED__

/* interface IWsbCollectable */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWsbCollectable;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9C7D6F0A-1562-11D0-81AC-00A0C91180F2")
    IWsbCollectable : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CompareTo( 
            /* [in] */ IUnknown *pCollectable,
            /* [out] */ SHORT *pResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsEqual( 
            /* [in] */ IUnknown *pCollectable) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWsbCollectableVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWsbCollectable * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWsbCollectable * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWsbCollectable * This);
        
        HRESULT ( STDMETHODCALLTYPE *CompareTo )( 
            IWsbCollectable * This,
            /* [in] */ IUnknown *pCollectable,
            /* [out] */ SHORT *pResult);
        
        HRESULT ( STDMETHODCALLTYPE *IsEqual )( 
            IWsbCollectable * This,
            /* [in] */ IUnknown *pCollectable);
        
        END_INTERFACE
    } IWsbCollectableVtbl;

    interface IWsbCollectable
    {
        CONST_VTBL struct IWsbCollectableVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWsbCollectable_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWsbCollectable_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWsbCollectable_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWsbCollectable_CompareTo(This,pCollectable,pResult)	\
    (This)->lpVtbl -> CompareTo(This,pCollectable,pResult)

#define IWsbCollectable_IsEqual(This,pCollectable)	\
    (This)->lpVtbl -> IsEqual(This,pCollectable)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IWsbCollectable_CompareTo_Proxy( 
    IWsbCollectable * This,
    /* [in] */ IUnknown *pCollectable,
    /* [out] */ SHORT *pResult);


void __RPC_STUB IWsbCollectable_CompareTo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbCollectable_IsEqual_Proxy( 
    IWsbCollectable * This,
    /* [in] */ IUnknown *pCollectable);


void __RPC_STUB IWsbCollectable_IsEqual_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IWsbCollectable_INTERFACE_DEFINED__ */


#ifndef __IWsbCollection_INTERFACE_DEFINED__
#define __IWsbCollection_INTERFACE_DEFINED__

/* interface IWsbCollection */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWsbCollection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9C7D6F0F-1562-11D0-81AC-00A0C91180F2")
    IWsbCollection : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Add( 
            /* [in] */ IUnknown *pCollectable) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Contains( 
            /* [in] */ IUnknown *pCollectable) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEntries( 
            /* [out] */ ULONG *pEntries) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Find( 
            /* [in] */ IUnknown *pCollectable,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppElement) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsEmpty( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsLocked( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Lock( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE OccurencesOf( 
            /* [in] */ IUnknown *pCollectable,
            /* [out] */ ULONG *occurences) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Remove( 
            /* [in] */ IUnknown *pCollectable,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppElement) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveAndRelease( 
            /* [in] */ IUnknown *pCollectable) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveAllAndRelease( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Unlock( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Enum( 
            /* [retval][out] */ IWsbEnum **ppEnum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnumUnknown( 
            /* [retval][out] */ IEnumUnknown **ppEnum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWsbCollectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWsbCollection * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWsbCollection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWsbCollection * This);
        
        HRESULT ( STDMETHODCALLTYPE *Add )( 
            IWsbCollection * This,
            /* [in] */ IUnknown *pCollectable);
        
        HRESULT ( STDMETHODCALLTYPE *Contains )( 
            IWsbCollection * This,
            /* [in] */ IUnknown *pCollectable);
        
        HRESULT ( STDMETHODCALLTYPE *GetEntries )( 
            IWsbCollection * This,
            /* [out] */ ULONG *pEntries);
        
        HRESULT ( STDMETHODCALLTYPE *Find )( 
            IWsbCollection * This,
            /* [in] */ IUnknown *pCollectable,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppElement);
        
        HRESULT ( STDMETHODCALLTYPE *IsEmpty )( 
            IWsbCollection * This);
        
        HRESULT ( STDMETHODCALLTYPE *IsLocked )( 
            IWsbCollection * This);
        
        HRESULT ( STDMETHODCALLTYPE *Lock )( 
            IWsbCollection * This);
        
        HRESULT ( STDMETHODCALLTYPE *OccurencesOf )( 
            IWsbCollection * This,
            /* [in] */ IUnknown *pCollectable,
            /* [out] */ ULONG *occurences);
        
        HRESULT ( STDMETHODCALLTYPE *Remove )( 
            IWsbCollection * This,
            /* [in] */ IUnknown *pCollectable,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppElement);
        
        HRESULT ( STDMETHODCALLTYPE *RemoveAndRelease )( 
            IWsbCollection * This,
            /* [in] */ IUnknown *pCollectable);
        
        HRESULT ( STDMETHODCALLTYPE *RemoveAllAndRelease )( 
            IWsbCollection * This);
        
        HRESULT ( STDMETHODCALLTYPE *Unlock )( 
            IWsbCollection * This);
        
        HRESULT ( STDMETHODCALLTYPE *Enum )( 
            IWsbCollection * This,
            /* [retval][out] */ IWsbEnum **ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE *EnumUnknown )( 
            IWsbCollection * This,
            /* [retval][out] */ IEnumUnknown **ppEnum);
        
        END_INTERFACE
    } IWsbCollectionVtbl;

    interface IWsbCollection
    {
        CONST_VTBL struct IWsbCollectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWsbCollection_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWsbCollection_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWsbCollection_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWsbCollection_Add(This,pCollectable)	\
    (This)->lpVtbl -> Add(This,pCollectable)

#define IWsbCollection_Contains(This,pCollectable)	\
    (This)->lpVtbl -> Contains(This,pCollectable)

#define IWsbCollection_GetEntries(This,pEntries)	\
    (This)->lpVtbl -> GetEntries(This,pEntries)

#define IWsbCollection_Find(This,pCollectable,riid,ppElement)	\
    (This)->lpVtbl -> Find(This,pCollectable,riid,ppElement)

#define IWsbCollection_IsEmpty(This)	\
    (This)->lpVtbl -> IsEmpty(This)

#define IWsbCollection_IsLocked(This)	\
    (This)->lpVtbl -> IsLocked(This)

#define IWsbCollection_Lock(This)	\
    (This)->lpVtbl -> Lock(This)

#define IWsbCollection_OccurencesOf(This,pCollectable,occurences)	\
    (This)->lpVtbl -> OccurencesOf(This,pCollectable,occurences)

#define IWsbCollection_Remove(This,pCollectable,riid,ppElement)	\
    (This)->lpVtbl -> Remove(This,pCollectable,riid,ppElement)

#define IWsbCollection_RemoveAndRelease(This,pCollectable)	\
    (This)->lpVtbl -> RemoveAndRelease(This,pCollectable)

#define IWsbCollection_RemoveAllAndRelease(This)	\
    (This)->lpVtbl -> RemoveAllAndRelease(This)

#define IWsbCollection_Unlock(This)	\
    (This)->lpVtbl -> Unlock(This)

#define IWsbCollection_Enum(This,ppEnum)	\
    (This)->lpVtbl -> Enum(This,ppEnum)

#define IWsbCollection_EnumUnknown(This,ppEnum)	\
    (This)->lpVtbl -> EnumUnknown(This,ppEnum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IWsbCollection_Add_Proxy( 
    IWsbCollection * This,
    /* [in] */ IUnknown *pCollectable);


void __RPC_STUB IWsbCollection_Add_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbCollection_Contains_Proxy( 
    IWsbCollection * This,
    /* [in] */ IUnknown *pCollectable);


void __RPC_STUB IWsbCollection_Contains_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbCollection_GetEntries_Proxy( 
    IWsbCollection * This,
    /* [out] */ ULONG *pEntries);


void __RPC_STUB IWsbCollection_GetEntries_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbCollection_Find_Proxy( 
    IWsbCollection * This,
    /* [in] */ IUnknown *pCollectable,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ void **ppElement);


void __RPC_STUB IWsbCollection_Find_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbCollection_IsEmpty_Proxy( 
    IWsbCollection * This);


void __RPC_STUB IWsbCollection_IsEmpty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbCollection_IsLocked_Proxy( 
    IWsbCollection * This);


void __RPC_STUB IWsbCollection_IsLocked_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbCollection_Lock_Proxy( 
    IWsbCollection * This);


void __RPC_STUB IWsbCollection_Lock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbCollection_OccurencesOf_Proxy( 
    IWsbCollection * This,
    /* [in] */ IUnknown *pCollectable,
    /* [out] */ ULONG *occurences);


void __RPC_STUB IWsbCollection_OccurencesOf_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbCollection_Remove_Proxy( 
    IWsbCollection * This,
    /* [in] */ IUnknown *pCollectable,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ void **ppElement);


void __RPC_STUB IWsbCollection_Remove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbCollection_RemoveAndRelease_Proxy( 
    IWsbCollection * This,
    /* [in] */ IUnknown *pCollectable);


void __RPC_STUB IWsbCollection_RemoveAndRelease_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbCollection_RemoveAllAndRelease_Proxy( 
    IWsbCollection * This);


void __RPC_STUB IWsbCollection_RemoveAllAndRelease_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbCollection_Unlock_Proxy( 
    IWsbCollection * This);


void __RPC_STUB IWsbCollection_Unlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbCollection_Enum_Proxy( 
    IWsbCollection * This,
    /* [retval][out] */ IWsbEnum **ppEnum);


void __RPC_STUB IWsbCollection_Enum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbCollection_EnumUnknown_Proxy( 
    IWsbCollection * This,
    /* [retval][out] */ IEnumUnknown **ppEnum);


void __RPC_STUB IWsbCollection_EnumUnknown_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IWsbCollection_INTERFACE_DEFINED__ */


#ifndef __IWsbEnum_INTERFACE_DEFINED__
#define __IWsbEnum_INTERFACE_DEFINED__

/* interface IWsbEnum */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWsbEnum;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9C7D6F14-1562-11D0-81AC-00A0C91180F2")
    IWsbEnum : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE First( 
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppElement) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppElement) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE This( 
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppElement) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Previous( 
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppElement) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Last( 
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppElement) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FindNext( 
            /* [in] */ IUnknown *pCollectable,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppElement) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Find( 
            /* [in] */ IUnknown *pCollectable,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppElement) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FindPrevious( 
            /* [in] */ IUnknown *pCollectable,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppElement) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SkipToFirst( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SkipNext( 
            /* [in] */ ULONG element) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SkipTo( 
            /* [in] */ ULONG index) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SkipPrevious( 
            /* [in] */ ULONG element) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SkipToLast( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Init( 
            /* [in] */ IWsbCollection *pCollection) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IWsbEnum **ppEnum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWsbEnumVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWsbEnum * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWsbEnum * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWsbEnum * This);
        
        HRESULT ( STDMETHODCALLTYPE *First )( 
            IWsbEnum * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppElement);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IWsbEnum * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppElement);
        
        HRESULT ( STDMETHODCALLTYPE *This )( 
            IWsbEnum * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppElement);
        
        HRESULT ( STDMETHODCALLTYPE *Previous )( 
            IWsbEnum * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppElement);
        
        HRESULT ( STDMETHODCALLTYPE *Last )( 
            IWsbEnum * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppElement);
        
        HRESULT ( STDMETHODCALLTYPE *FindNext )( 
            IWsbEnum * This,
            /* [in] */ IUnknown *pCollectable,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppElement);
        
        HRESULT ( STDMETHODCALLTYPE *Find )( 
            IWsbEnum * This,
            /* [in] */ IUnknown *pCollectable,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppElement);
        
        HRESULT ( STDMETHODCALLTYPE *FindPrevious )( 
            IWsbEnum * This,
            /* [in] */ IUnknown *pCollectable,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppElement);
        
        HRESULT ( STDMETHODCALLTYPE *SkipToFirst )( 
            IWsbEnum * This);
        
        HRESULT ( STDMETHODCALLTYPE *SkipNext )( 
            IWsbEnum * This,
            /* [in] */ ULONG element);
        
        HRESULT ( STDMETHODCALLTYPE *SkipTo )( 
            IWsbEnum * This,
            /* [in] */ ULONG index);
        
        HRESULT ( STDMETHODCALLTYPE *SkipPrevious )( 
            IWsbEnum * This,
            /* [in] */ ULONG element);
        
        HRESULT ( STDMETHODCALLTYPE *SkipToLast )( 
            IWsbEnum * This);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IWsbEnum * This);
        
        HRESULT ( STDMETHODCALLTYPE *Init )( 
            IWsbEnum * This,
            /* [in] */ IWsbCollection *pCollection);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IWsbEnum * This,
            /* [out] */ IWsbEnum **ppEnum);
        
        END_INTERFACE
    } IWsbEnumVtbl;

    interface IWsbEnum
    {
        CONST_VTBL struct IWsbEnumVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWsbEnum_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWsbEnum_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWsbEnum_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWsbEnum_First(This,riid,ppElement)	\
    (This)->lpVtbl -> First(This,riid,ppElement)

#define IWsbEnum_Next(This,riid,ppElement)	\
    (This)->lpVtbl -> Next(This,riid,ppElement)

#define IWsbEnum_This(This,riid,ppElement)	\
    (This)->lpVtbl -> This(This,riid,ppElement)

#define IWsbEnum_Previous(This,riid,ppElement)	\
    (This)->lpVtbl -> Previous(This,riid,ppElement)

#define IWsbEnum_Last(This,riid,ppElement)	\
    (This)->lpVtbl -> Last(This,riid,ppElement)

#define IWsbEnum_FindNext(This,pCollectable,riid,ppElement)	\
    (This)->lpVtbl -> FindNext(This,pCollectable,riid,ppElement)

#define IWsbEnum_Find(This,pCollectable,riid,ppElement)	\
    (This)->lpVtbl -> Find(This,pCollectable,riid,ppElement)

#define IWsbEnum_FindPrevious(This,pCollectable,riid,ppElement)	\
    (This)->lpVtbl -> FindPrevious(This,pCollectable,riid,ppElement)

#define IWsbEnum_SkipToFirst(This)	\
    (This)->lpVtbl -> SkipToFirst(This)

#define IWsbEnum_SkipNext(This,element)	\
    (This)->lpVtbl -> SkipNext(This,element)

#define IWsbEnum_SkipTo(This,index)	\
    (This)->lpVtbl -> SkipTo(This,index)

#define IWsbEnum_SkipPrevious(This,element)	\
    (This)->lpVtbl -> SkipPrevious(This,element)

#define IWsbEnum_SkipToLast(This)	\
    (This)->lpVtbl -> SkipToLast(This)

#define IWsbEnum_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IWsbEnum_Init(This,pCollection)	\
    (This)->lpVtbl -> Init(This,pCollection)

#define IWsbEnum_Clone(This,ppEnum)	\
    (This)->lpVtbl -> Clone(This,ppEnum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IWsbEnum_First_Proxy( 
    IWsbEnum * This,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ void **ppElement);


void __RPC_STUB IWsbEnum_First_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbEnum_Next_Proxy( 
    IWsbEnum * This,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ void **ppElement);


void __RPC_STUB IWsbEnum_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbEnum_This_Proxy( 
    IWsbEnum * This,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ void **ppElement);


void __RPC_STUB IWsbEnum_This_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbEnum_Previous_Proxy( 
    IWsbEnum * This,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ void **ppElement);


void __RPC_STUB IWsbEnum_Previous_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbEnum_Last_Proxy( 
    IWsbEnum * This,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ void **ppElement);


void __RPC_STUB IWsbEnum_Last_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbEnum_FindNext_Proxy( 
    IWsbEnum * This,
    /* [in] */ IUnknown *pCollectable,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ void **ppElement);


void __RPC_STUB IWsbEnum_FindNext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbEnum_Find_Proxy( 
    IWsbEnum * This,
    /* [in] */ IUnknown *pCollectable,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ void **ppElement);


void __RPC_STUB IWsbEnum_Find_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbEnum_FindPrevious_Proxy( 
    IWsbEnum * This,
    /* [in] */ IUnknown *pCollectable,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ void **ppElement);


void __RPC_STUB IWsbEnum_FindPrevious_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbEnum_SkipToFirst_Proxy( 
    IWsbEnum * This);


void __RPC_STUB IWsbEnum_SkipToFirst_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbEnum_SkipNext_Proxy( 
    IWsbEnum * This,
    /* [in] */ ULONG element);


void __RPC_STUB IWsbEnum_SkipNext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbEnum_SkipTo_Proxy( 
    IWsbEnum * This,
    /* [in] */ ULONG index);


void __RPC_STUB IWsbEnum_SkipTo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbEnum_SkipPrevious_Proxy( 
    IWsbEnum * This,
    /* [in] */ ULONG element);


void __RPC_STUB IWsbEnum_SkipPrevious_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbEnum_SkipToLast_Proxy( 
    IWsbEnum * This);


void __RPC_STUB IWsbEnum_SkipToLast_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbEnum_Reset_Proxy( 
    IWsbEnum * This);


void __RPC_STUB IWsbEnum_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbEnum_Init_Proxy( 
    IWsbEnum * This,
    /* [in] */ IWsbCollection *pCollection);


void __RPC_STUB IWsbEnum_Init_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbEnum_Clone_Proxy( 
    IWsbEnum * This,
    /* [out] */ IWsbEnum **ppEnum);


void __RPC_STUB IWsbEnum_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IWsbEnum_INTERFACE_DEFINED__ */


#ifndef __IWsbEnumEx_INTERFACE_DEFINED__
#define __IWsbEnumEx_INTERFACE_DEFINED__

/* interface IWsbEnumEx */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWsbEnumEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F5A3AC60-9993-11d0-81E7-00A0C91180F2")
    IWsbEnumEx : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE First( 
            /* [in] */ ULONG element,
            /* [in] */ REFIID riid,
            /* [length_is][size_is][size_is][iid_is][out] */ void **elements,
            /* [out] */ ULONG *pElementsFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Next( 
            /* [in] */ ULONG element,
            /* [in] */ REFIID riid,
            /* [length_is][size_is][size_is][iid_is][out] */ void **elements,
            /* [out] */ ULONG *pElementsFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE This( 
            /* [in] */ ULONG element,
            /* [in] */ REFIID riid,
            /* [length_is][size_is][size_is][iid_is][out] */ void **elements,
            /* [out] */ ULONG *pElementsFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Previous( 
            /* [in] */ ULONG element,
            /* [in] */ REFIID riid,
            /* [length_is][size_is][size_is][iid_is][out] */ void **elements,
            /* [out] */ ULONG *pElementsFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Last( 
            /* [in] */ ULONG element,
            /* [in] */ REFIID riid,
            /* [length_is][size_is][size_is][iid_is][out] */ void **elements,
            /* [out] */ ULONG *pElementsFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FindNext( 
            /* [in] */ IUnknown *pCollectable,
            /* [in] */ ULONG element,
            /* [in] */ REFIID riid,
            /* [length_is][size_is][size_is][iid_is][out] */ void **elements,
            /* [out] */ ULONG *pElementsFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Find( 
            /* [in] */ IUnknown *pCollectable,
            /* [in] */ ULONG element,
            /* [in] */ REFIID riid,
            /* [length_is][size_is][size_is][iid_is][out] */ void **elements,
            /* [out] */ ULONG *pElementsFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FindPrevious( 
            /* [in] */ IUnknown *pCollectable,
            /* [in] */ ULONG element,
            /* [in] */ REFIID riid,
            /* [length_is][size_is][size_is][iid_is][out] */ void **elements,
            /* [out] */ ULONG *pElementsFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SkipToFirst( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SkipNext( 
            /* [in] */ ULONG element) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SkipTo( 
            /* [in] */ ULONG index) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SkipPrevious( 
            /* [in] */ ULONG element) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SkipToLast( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Init( 
            /* [in] */ IWsbCollection *pCollection) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [out] */ IWsbEnum **ppEnum) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWsbEnumExVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWsbEnumEx * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWsbEnumEx * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWsbEnumEx * This);
        
        HRESULT ( STDMETHODCALLTYPE *First )( 
            IWsbEnumEx * This,
            /* [in] */ ULONG element,
            /* [in] */ REFIID riid,
            /* [length_is][size_is][size_is][iid_is][out] */ void **elements,
            /* [out] */ ULONG *pElementsFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IWsbEnumEx * This,
            /* [in] */ ULONG element,
            /* [in] */ REFIID riid,
            /* [length_is][size_is][size_is][iid_is][out] */ void **elements,
            /* [out] */ ULONG *pElementsFetched);
        
        HRESULT ( STDMETHODCALLTYPE *This )( 
            IWsbEnumEx * This,
            /* [in] */ ULONG element,
            /* [in] */ REFIID riid,
            /* [length_is][size_is][size_is][iid_is][out] */ void **elements,
            /* [out] */ ULONG *pElementsFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Previous )( 
            IWsbEnumEx * This,
            /* [in] */ ULONG element,
            /* [in] */ REFIID riid,
            /* [length_is][size_is][size_is][iid_is][out] */ void **elements,
            /* [out] */ ULONG *pElementsFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Last )( 
            IWsbEnumEx * This,
            /* [in] */ ULONG element,
            /* [in] */ REFIID riid,
            /* [length_is][size_is][size_is][iid_is][out] */ void **elements,
            /* [out] */ ULONG *pElementsFetched);
        
        HRESULT ( STDMETHODCALLTYPE *FindNext )( 
            IWsbEnumEx * This,
            /* [in] */ IUnknown *pCollectable,
            /* [in] */ ULONG element,
            /* [in] */ REFIID riid,
            /* [length_is][size_is][size_is][iid_is][out] */ void **elements,
            /* [out] */ ULONG *pElementsFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Find )( 
            IWsbEnumEx * This,
            /* [in] */ IUnknown *pCollectable,
            /* [in] */ ULONG element,
            /* [in] */ REFIID riid,
            /* [length_is][size_is][size_is][iid_is][out] */ void **elements,
            /* [out] */ ULONG *pElementsFetched);
        
        HRESULT ( STDMETHODCALLTYPE *FindPrevious )( 
            IWsbEnumEx * This,
            /* [in] */ IUnknown *pCollectable,
            /* [in] */ ULONG element,
            /* [in] */ REFIID riid,
            /* [length_is][size_is][size_is][iid_is][out] */ void **elements,
            /* [out] */ ULONG *pElementsFetched);
        
        HRESULT ( STDMETHODCALLTYPE *SkipToFirst )( 
            IWsbEnumEx * This);
        
        HRESULT ( STDMETHODCALLTYPE *SkipNext )( 
            IWsbEnumEx * This,
            /* [in] */ ULONG element);
        
        HRESULT ( STDMETHODCALLTYPE *SkipTo )( 
            IWsbEnumEx * This,
            /* [in] */ ULONG index);
        
        HRESULT ( STDMETHODCALLTYPE *SkipPrevious )( 
            IWsbEnumEx * This,
            /* [in] */ ULONG element);
        
        HRESULT ( STDMETHODCALLTYPE *SkipToLast )( 
            IWsbEnumEx * This);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IWsbEnumEx * This);
        
        HRESULT ( STDMETHODCALLTYPE *Init )( 
            IWsbEnumEx * This,
            /* [in] */ IWsbCollection *pCollection);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IWsbEnumEx * This,
            /* [out] */ IWsbEnum **ppEnum);
        
        END_INTERFACE
    } IWsbEnumExVtbl;

    interface IWsbEnumEx
    {
        CONST_VTBL struct IWsbEnumExVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWsbEnumEx_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWsbEnumEx_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWsbEnumEx_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWsbEnumEx_First(This,element,riid,elements,pElementsFetched)	\
    (This)->lpVtbl -> First(This,element,riid,elements,pElementsFetched)

#define IWsbEnumEx_Next(This,element,riid,elements,pElementsFetched)	\
    (This)->lpVtbl -> Next(This,element,riid,elements,pElementsFetched)

#define IWsbEnumEx_This(This,element,riid,elements,pElementsFetched)	\
    (This)->lpVtbl -> This(This,element,riid,elements,pElementsFetched)

#define IWsbEnumEx_Previous(This,element,riid,elements,pElementsFetched)	\
    (This)->lpVtbl -> Previous(This,element,riid,elements,pElementsFetched)

#define IWsbEnumEx_Last(This,element,riid,elements,pElementsFetched)	\
    (This)->lpVtbl -> Last(This,element,riid,elements,pElementsFetched)

#define IWsbEnumEx_FindNext(This,pCollectable,element,riid,elements,pElementsFetched)	\
    (This)->lpVtbl -> FindNext(This,pCollectable,element,riid,elements,pElementsFetched)

#define IWsbEnumEx_Find(This,pCollectable,element,riid,elements,pElementsFetched)	\
    (This)->lpVtbl -> Find(This,pCollectable,element,riid,elements,pElementsFetched)

#define IWsbEnumEx_FindPrevious(This,pCollectable,element,riid,elements,pElementsFetched)	\
    (This)->lpVtbl -> FindPrevious(This,pCollectable,element,riid,elements,pElementsFetched)

#define IWsbEnumEx_SkipToFirst(This)	\
    (This)->lpVtbl -> SkipToFirst(This)

#define IWsbEnumEx_SkipNext(This,element)	\
    (This)->lpVtbl -> SkipNext(This,element)

#define IWsbEnumEx_SkipTo(This,index)	\
    (This)->lpVtbl -> SkipTo(This,index)

#define IWsbEnumEx_SkipPrevious(This,element)	\
    (This)->lpVtbl -> SkipPrevious(This,element)

#define IWsbEnumEx_SkipToLast(This)	\
    (This)->lpVtbl -> SkipToLast(This)

#define IWsbEnumEx_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IWsbEnumEx_Init(This,pCollection)	\
    (This)->lpVtbl -> Init(This,pCollection)

#define IWsbEnumEx_Clone(This,ppEnum)	\
    (This)->lpVtbl -> Clone(This,ppEnum)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IWsbEnumEx_First_Proxy( 
    IWsbEnumEx * This,
    /* [in] */ ULONG element,
    /* [in] */ REFIID riid,
    /* [length_is][size_is][size_is][iid_is][out] */ void **elements,
    /* [out] */ ULONG *pElementsFetched);


void __RPC_STUB IWsbEnumEx_First_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbEnumEx_Next_Proxy( 
    IWsbEnumEx * This,
    /* [in] */ ULONG element,
    /* [in] */ REFIID riid,
    /* [length_is][size_is][size_is][iid_is][out] */ void **elements,
    /* [out] */ ULONG *pElementsFetched);


void __RPC_STUB IWsbEnumEx_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbEnumEx_This_Proxy( 
    IWsbEnumEx * This,
    /* [in] */ ULONG element,
    /* [in] */ REFIID riid,
    /* [length_is][size_is][size_is][iid_is][out] */ void **elements,
    /* [out] */ ULONG *pElementsFetched);


void __RPC_STUB IWsbEnumEx_This_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbEnumEx_Previous_Proxy( 
    IWsbEnumEx * This,
    /* [in] */ ULONG element,
    /* [in] */ REFIID riid,
    /* [length_is][size_is][size_is][iid_is][out] */ void **elements,
    /* [out] */ ULONG *pElementsFetched);


void __RPC_STUB IWsbEnumEx_Previous_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbEnumEx_Last_Proxy( 
    IWsbEnumEx * This,
    /* [in] */ ULONG element,
    /* [in] */ REFIID riid,
    /* [length_is][size_is][size_is][iid_is][out] */ void **elements,
    /* [out] */ ULONG *pElementsFetched);


void __RPC_STUB IWsbEnumEx_Last_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbEnumEx_FindNext_Proxy( 
    IWsbEnumEx * This,
    /* [in] */ IUnknown *pCollectable,
    /* [in] */ ULONG element,
    /* [in] */ REFIID riid,
    /* [length_is][size_is][size_is][iid_is][out] */ void **elements,
    /* [out] */ ULONG *pElementsFetched);


void __RPC_STUB IWsbEnumEx_FindNext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbEnumEx_Find_Proxy( 
    IWsbEnumEx * This,
    /* [in] */ IUnknown *pCollectable,
    /* [in] */ ULONG element,
    /* [in] */ REFIID riid,
    /* [length_is][size_is][size_is][iid_is][out] */ void **elements,
    /* [out] */ ULONG *pElementsFetched);


void __RPC_STUB IWsbEnumEx_Find_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbEnumEx_FindPrevious_Proxy( 
    IWsbEnumEx * This,
    /* [in] */ IUnknown *pCollectable,
    /* [in] */ ULONG element,
    /* [in] */ REFIID riid,
    /* [length_is][size_is][size_is][iid_is][out] */ void **elements,
    /* [out] */ ULONG *pElementsFetched);


void __RPC_STUB IWsbEnumEx_FindPrevious_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbEnumEx_SkipToFirst_Proxy( 
    IWsbEnumEx * This);


void __RPC_STUB IWsbEnumEx_SkipToFirst_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbEnumEx_SkipNext_Proxy( 
    IWsbEnumEx * This,
    /* [in] */ ULONG element);


void __RPC_STUB IWsbEnumEx_SkipNext_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbEnumEx_SkipTo_Proxy( 
    IWsbEnumEx * This,
    /* [in] */ ULONG index);


void __RPC_STUB IWsbEnumEx_SkipTo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbEnumEx_SkipPrevious_Proxy( 
    IWsbEnumEx * This,
    /* [in] */ ULONG element);


void __RPC_STUB IWsbEnumEx_SkipPrevious_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbEnumEx_SkipToLast_Proxy( 
    IWsbEnumEx * This);


void __RPC_STUB IWsbEnumEx_SkipToLast_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbEnumEx_Reset_Proxy( 
    IWsbEnumEx * This);


void __RPC_STUB IWsbEnumEx_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbEnumEx_Init_Proxy( 
    IWsbEnumEx * This,
    /* [in] */ IWsbCollection *pCollection);


void __RPC_STUB IWsbEnumEx_Init_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbEnumEx_Clone_Proxy( 
    IWsbEnumEx * This,
    /* [out] */ IWsbEnum **ppEnum);


void __RPC_STUB IWsbEnumEx_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IWsbEnumEx_INTERFACE_DEFINED__ */


#ifndef __IWsbGuid_INTERFACE_DEFINED__
#define __IWsbGuid_INTERFACE_DEFINED__

/* interface IWsbGuid */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWsbGuid;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A0FF1F41-237A-11D0-81BA-00A0C91180F2")
    IWsbGuid : public IWsbCollectable
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CompareToGuid( 
            /* [in] */ GUID value,
            /* [out] */ SHORT *pResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CompareToIGuid( 
            /* [in] */ IWsbGuid *pGuid,
            /* [out] */ SHORT *pResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetGuid( 
            /* [out] */ GUID *pValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetGuid( 
            /* [in] */ GUID value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWsbGuidVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWsbGuid * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWsbGuid * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWsbGuid * This);
        
        HRESULT ( STDMETHODCALLTYPE *CompareTo )( 
            IWsbGuid * This,
            /* [in] */ IUnknown *pCollectable,
            /* [out] */ SHORT *pResult);
        
        HRESULT ( STDMETHODCALLTYPE *IsEqual )( 
            IWsbGuid * This,
            /* [in] */ IUnknown *pCollectable);
        
        HRESULT ( STDMETHODCALLTYPE *CompareToGuid )( 
            IWsbGuid * This,
            /* [in] */ GUID value,
            /* [out] */ SHORT *pResult);
        
        HRESULT ( STDMETHODCALLTYPE *CompareToIGuid )( 
            IWsbGuid * This,
            /* [in] */ IWsbGuid *pGuid,
            /* [out] */ SHORT *pResult);
        
        HRESULT ( STDMETHODCALLTYPE *GetGuid )( 
            IWsbGuid * This,
            /* [out] */ GUID *pValue);
        
        HRESULT ( STDMETHODCALLTYPE *SetGuid )( 
            IWsbGuid * This,
            /* [in] */ GUID value);
        
        END_INTERFACE
    } IWsbGuidVtbl;

    interface IWsbGuid
    {
        CONST_VTBL struct IWsbGuidVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWsbGuid_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWsbGuid_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWsbGuid_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWsbGuid_CompareTo(This,pCollectable,pResult)	\
    (This)->lpVtbl -> CompareTo(This,pCollectable,pResult)

#define IWsbGuid_IsEqual(This,pCollectable)	\
    (This)->lpVtbl -> IsEqual(This,pCollectable)


#define IWsbGuid_CompareToGuid(This,value,pResult)	\
    (This)->lpVtbl -> CompareToGuid(This,value,pResult)

#define IWsbGuid_CompareToIGuid(This,pGuid,pResult)	\
    (This)->lpVtbl -> CompareToIGuid(This,pGuid,pResult)

#define IWsbGuid_GetGuid(This,pValue)	\
    (This)->lpVtbl -> GetGuid(This,pValue)

#define IWsbGuid_SetGuid(This,value)	\
    (This)->lpVtbl -> SetGuid(This,value)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IWsbGuid_CompareToGuid_Proxy( 
    IWsbGuid * This,
    /* [in] */ GUID value,
    /* [out] */ SHORT *pResult);


void __RPC_STUB IWsbGuid_CompareToGuid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbGuid_CompareToIGuid_Proxy( 
    IWsbGuid * This,
    /* [in] */ IWsbGuid *pGuid,
    /* [out] */ SHORT *pResult);


void __RPC_STUB IWsbGuid_CompareToIGuid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbGuid_GetGuid_Proxy( 
    IWsbGuid * This,
    /* [out] */ GUID *pValue);


void __RPC_STUB IWsbGuid_GetGuid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbGuid_SetGuid_Proxy( 
    IWsbGuid * This,
    /* [in] */ GUID value);


void __RPC_STUB IWsbGuid_SetGuid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IWsbGuid_INTERFACE_DEFINED__ */


#ifndef __IWsbIndexedCollection_INTERFACE_DEFINED__
#define __IWsbIndexedCollection_INTERFACE_DEFINED__

/* interface IWsbIndexedCollection */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWsbIndexedCollection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A5B69200-214B-11D0-81B7-00A0C91180F2")
    IWsbIndexedCollection : public IWsbCollection
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AddAt( 
            /* [in] */ IUnknown *pCollectable,
            /* [in] */ ULONG index) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Append( 
            /* [in] */ IUnknown *pCollectable) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Prepend( 
            /* [in] */ IUnknown *pCollectable) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RemoveAt( 
            /* [in] */ ULONG index,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppElement) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE First( 
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppElement) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE At( 
            /* [in] */ ULONG index,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppElement) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Last( 
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppElement) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Index( 
            /* [in] */ IUnknown *pCollectable,
            /* [in] */ ULONG *pIndex) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Copy( 
            /* [in] */ ULONG start,
            /* [in] */ ULONG stop,
            /* [in] */ REFIID riid,
            /* [length_is][size_is][size_is][iid_is][out] */ void **elements,
            /* [out] */ ULONG *pElementsFetched) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CopyIfMatches( 
            /* [in] */ ULONG start,
            /* [in] */ ULONG stop,
            /* [in] */ IUnknown *pCollectable,
            /* [in] */ ULONG element,
            /* [in] */ REFIID riid,
            /* [length_is][size_is][size_is][iid_is][out] */ void **elements,
            /* [out] */ ULONG *pElementsFetched,
            /* [out] */ ULONG *pStoppedAt) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWsbIndexedCollectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWsbIndexedCollection * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWsbIndexedCollection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWsbIndexedCollection * This);
        
        HRESULT ( STDMETHODCALLTYPE *Add )( 
            IWsbIndexedCollection * This,
            /* [in] */ IUnknown *pCollectable);
        
        HRESULT ( STDMETHODCALLTYPE *Contains )( 
            IWsbIndexedCollection * This,
            /* [in] */ IUnknown *pCollectable);
        
        HRESULT ( STDMETHODCALLTYPE *GetEntries )( 
            IWsbIndexedCollection * This,
            /* [out] */ ULONG *pEntries);
        
        HRESULT ( STDMETHODCALLTYPE *Find )( 
            IWsbIndexedCollection * This,
            /* [in] */ IUnknown *pCollectable,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppElement);
        
        HRESULT ( STDMETHODCALLTYPE *IsEmpty )( 
            IWsbIndexedCollection * This);
        
        HRESULT ( STDMETHODCALLTYPE *IsLocked )( 
            IWsbIndexedCollection * This);
        
        HRESULT ( STDMETHODCALLTYPE *Lock )( 
            IWsbIndexedCollection * This);
        
        HRESULT ( STDMETHODCALLTYPE *OccurencesOf )( 
            IWsbIndexedCollection * This,
            /* [in] */ IUnknown *pCollectable,
            /* [out] */ ULONG *occurences);
        
        HRESULT ( STDMETHODCALLTYPE *Remove )( 
            IWsbIndexedCollection * This,
            /* [in] */ IUnknown *pCollectable,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppElement);
        
        HRESULT ( STDMETHODCALLTYPE *RemoveAndRelease )( 
            IWsbIndexedCollection * This,
            /* [in] */ IUnknown *pCollectable);
        
        HRESULT ( STDMETHODCALLTYPE *RemoveAllAndRelease )( 
            IWsbIndexedCollection * This);
        
        HRESULT ( STDMETHODCALLTYPE *Unlock )( 
            IWsbIndexedCollection * This);
        
        HRESULT ( STDMETHODCALLTYPE *Enum )( 
            IWsbIndexedCollection * This,
            /* [retval][out] */ IWsbEnum **ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE *EnumUnknown )( 
            IWsbIndexedCollection * This,
            /* [retval][out] */ IEnumUnknown **ppEnum);
        
        HRESULT ( STDMETHODCALLTYPE *AddAt )( 
            IWsbIndexedCollection * This,
            /* [in] */ IUnknown *pCollectable,
            /* [in] */ ULONG index);
        
        HRESULT ( STDMETHODCALLTYPE *Append )( 
            IWsbIndexedCollection * This,
            /* [in] */ IUnknown *pCollectable);
        
        HRESULT ( STDMETHODCALLTYPE *Prepend )( 
            IWsbIndexedCollection * This,
            /* [in] */ IUnknown *pCollectable);
        
        HRESULT ( STDMETHODCALLTYPE *RemoveAt )( 
            IWsbIndexedCollection * This,
            /* [in] */ ULONG index,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppElement);
        
        HRESULT ( STDMETHODCALLTYPE *First )( 
            IWsbIndexedCollection * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppElement);
        
        HRESULT ( STDMETHODCALLTYPE *At )( 
            IWsbIndexedCollection * This,
            /* [in] */ ULONG index,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppElement);
        
        HRESULT ( STDMETHODCALLTYPE *Last )( 
            IWsbIndexedCollection * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppElement);
        
        HRESULT ( STDMETHODCALLTYPE *Index )( 
            IWsbIndexedCollection * This,
            /* [in] */ IUnknown *pCollectable,
            /* [in] */ ULONG *pIndex);
        
        HRESULT ( STDMETHODCALLTYPE *Copy )( 
            IWsbIndexedCollection * This,
            /* [in] */ ULONG start,
            /* [in] */ ULONG stop,
            /* [in] */ REFIID riid,
            /* [length_is][size_is][size_is][iid_is][out] */ void **elements,
            /* [out] */ ULONG *pElementsFetched);
        
        HRESULT ( STDMETHODCALLTYPE *CopyIfMatches )( 
            IWsbIndexedCollection * This,
            /* [in] */ ULONG start,
            /* [in] */ ULONG stop,
            /* [in] */ IUnknown *pCollectable,
            /* [in] */ ULONG element,
            /* [in] */ REFIID riid,
            /* [length_is][size_is][size_is][iid_is][out] */ void **elements,
            /* [out] */ ULONG *pElementsFetched,
            /* [out] */ ULONG *pStoppedAt);
        
        END_INTERFACE
    } IWsbIndexedCollectionVtbl;

    interface IWsbIndexedCollection
    {
        CONST_VTBL struct IWsbIndexedCollectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWsbIndexedCollection_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWsbIndexedCollection_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWsbIndexedCollection_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWsbIndexedCollection_Add(This,pCollectable)	\
    (This)->lpVtbl -> Add(This,pCollectable)

#define IWsbIndexedCollection_Contains(This,pCollectable)	\
    (This)->lpVtbl -> Contains(This,pCollectable)

#define IWsbIndexedCollection_GetEntries(This,pEntries)	\
    (This)->lpVtbl -> GetEntries(This,pEntries)

#define IWsbIndexedCollection_Find(This,pCollectable,riid,ppElement)	\
    (This)->lpVtbl -> Find(This,pCollectable,riid,ppElement)

#define IWsbIndexedCollection_IsEmpty(This)	\
    (This)->lpVtbl -> IsEmpty(This)

#define IWsbIndexedCollection_IsLocked(This)	\
    (This)->lpVtbl -> IsLocked(This)

#define IWsbIndexedCollection_Lock(This)	\
    (This)->lpVtbl -> Lock(This)

#define IWsbIndexedCollection_OccurencesOf(This,pCollectable,occurences)	\
    (This)->lpVtbl -> OccurencesOf(This,pCollectable,occurences)

#define IWsbIndexedCollection_Remove(This,pCollectable,riid,ppElement)	\
    (This)->lpVtbl -> Remove(This,pCollectable,riid,ppElement)

#define IWsbIndexedCollection_RemoveAndRelease(This,pCollectable)	\
    (This)->lpVtbl -> RemoveAndRelease(This,pCollectable)

#define IWsbIndexedCollection_RemoveAllAndRelease(This)	\
    (This)->lpVtbl -> RemoveAllAndRelease(This)

#define IWsbIndexedCollection_Unlock(This)	\
    (This)->lpVtbl -> Unlock(This)

#define IWsbIndexedCollection_Enum(This,ppEnum)	\
    (This)->lpVtbl -> Enum(This,ppEnum)

#define IWsbIndexedCollection_EnumUnknown(This,ppEnum)	\
    (This)->lpVtbl -> EnumUnknown(This,ppEnum)


#define IWsbIndexedCollection_AddAt(This,pCollectable,index)	\
    (This)->lpVtbl -> AddAt(This,pCollectable,index)

#define IWsbIndexedCollection_Append(This,pCollectable)	\
    (This)->lpVtbl -> Append(This,pCollectable)

#define IWsbIndexedCollection_Prepend(This,pCollectable)	\
    (This)->lpVtbl -> Prepend(This,pCollectable)

#define IWsbIndexedCollection_RemoveAt(This,index,riid,ppElement)	\
    (This)->lpVtbl -> RemoveAt(This,index,riid,ppElement)

#define IWsbIndexedCollection_First(This,riid,ppElement)	\
    (This)->lpVtbl -> First(This,riid,ppElement)

#define IWsbIndexedCollection_At(This,index,riid,ppElement)	\
    (This)->lpVtbl -> At(This,index,riid,ppElement)

#define IWsbIndexedCollection_Last(This,riid,ppElement)	\
    (This)->lpVtbl -> Last(This,riid,ppElement)

#define IWsbIndexedCollection_Index(This,pCollectable,pIndex)	\
    (This)->lpVtbl -> Index(This,pCollectable,pIndex)

#define IWsbIndexedCollection_Copy(This,start,stop,riid,elements,pElementsFetched)	\
    (This)->lpVtbl -> Copy(This,start,stop,riid,elements,pElementsFetched)

#define IWsbIndexedCollection_CopyIfMatches(This,start,stop,pCollectable,element,riid,elements,pElementsFetched,pStoppedAt)	\
    (This)->lpVtbl -> CopyIfMatches(This,start,stop,pCollectable,element,riid,elements,pElementsFetched,pStoppedAt)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IWsbIndexedCollection_AddAt_Proxy( 
    IWsbIndexedCollection * This,
    /* [in] */ IUnknown *pCollectable,
    /* [in] */ ULONG index);


void __RPC_STUB IWsbIndexedCollection_AddAt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbIndexedCollection_Append_Proxy( 
    IWsbIndexedCollection * This,
    /* [in] */ IUnknown *pCollectable);


void __RPC_STUB IWsbIndexedCollection_Append_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbIndexedCollection_Prepend_Proxy( 
    IWsbIndexedCollection * This,
    /* [in] */ IUnknown *pCollectable);


void __RPC_STUB IWsbIndexedCollection_Prepend_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbIndexedCollection_RemoveAt_Proxy( 
    IWsbIndexedCollection * This,
    /* [in] */ ULONG index,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ void **ppElement);


void __RPC_STUB IWsbIndexedCollection_RemoveAt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbIndexedCollection_First_Proxy( 
    IWsbIndexedCollection * This,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ void **ppElement);


void __RPC_STUB IWsbIndexedCollection_First_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbIndexedCollection_At_Proxy( 
    IWsbIndexedCollection * This,
    /* [in] */ ULONG index,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ void **ppElement);


void __RPC_STUB IWsbIndexedCollection_At_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbIndexedCollection_Last_Proxy( 
    IWsbIndexedCollection * This,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ void **ppElement);


void __RPC_STUB IWsbIndexedCollection_Last_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbIndexedCollection_Index_Proxy( 
    IWsbIndexedCollection * This,
    /* [in] */ IUnknown *pCollectable,
    /* [in] */ ULONG *pIndex);


void __RPC_STUB IWsbIndexedCollection_Index_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbIndexedCollection_Copy_Proxy( 
    IWsbIndexedCollection * This,
    /* [in] */ ULONG start,
    /* [in] */ ULONG stop,
    /* [in] */ REFIID riid,
    /* [length_is][size_is][size_is][iid_is][out] */ void **elements,
    /* [out] */ ULONG *pElementsFetched);


void __RPC_STUB IWsbIndexedCollection_Copy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbIndexedCollection_CopyIfMatches_Proxy( 
    IWsbIndexedCollection * This,
    /* [in] */ ULONG start,
    /* [in] */ ULONG stop,
    /* [in] */ IUnknown *pCollectable,
    /* [in] */ ULONG element,
    /* [in] */ REFIID riid,
    /* [length_is][size_is][size_is][iid_is][out] */ void **elements,
    /* [out] */ ULONG *pElementsFetched,
    /* [out] */ ULONG *pStoppedAt);


void __RPC_STUB IWsbIndexedCollection_CopyIfMatches_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IWsbIndexedCollection_INTERFACE_DEFINED__ */


#ifndef __IWsbPersistStream_INTERFACE_DEFINED__
#define __IWsbPersistStream_INTERFACE_DEFINED__

/* interface IWsbPersistStream */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWsbPersistStream;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C4D14AA2-79EE-11D0-9909-00A0C9058BF6")
    IWsbPersistStream : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE SetIsDirty( 
            /* [in] */ BOOL isDirty) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWsbPersistStreamVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWsbPersistStream * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWsbPersistStream * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWsbPersistStream * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetIsDirty )( 
            IWsbPersistStream * This,
            /* [in] */ BOOL isDirty);
        
        END_INTERFACE
    } IWsbPersistStreamVtbl;

    interface IWsbPersistStream
    {
        CONST_VTBL struct IWsbPersistStreamVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWsbPersistStream_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWsbPersistStream_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWsbPersistStream_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWsbPersistStream_SetIsDirty(This,isDirty)	\
    (This)->lpVtbl -> SetIsDirty(This,isDirty)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IWsbPersistStream_SetIsDirty_Proxy( 
    IWsbPersistStream * This,
    /* [in] */ BOOL isDirty);


void __RPC_STUB IWsbPersistStream_SetIsDirty_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IWsbPersistStream_INTERFACE_DEFINED__ */


#ifndef __IWsbPersistable_INTERFACE_DEFINED__
#define __IWsbPersistable_INTERFACE_DEFINED__

/* interface IWsbPersistable */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWsbPersistable;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5BF46531-282D-11D0-81BE-00A0C91180F2")
    IWsbPersistable : public IWsbPersistStream
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetDefaultFileName( 
            /* [size_is][string][out][in] */ OLECHAR **pFilename,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReleaseFile( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDefaultFileName( 
            /* [string][in] */ OLECHAR *fileName) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWsbPersistableVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWsbPersistable * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWsbPersistable * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWsbPersistable * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetIsDirty )( 
            IWsbPersistable * This,
            /* [in] */ BOOL isDirty);
        
        HRESULT ( STDMETHODCALLTYPE *GetDefaultFileName )( 
            IWsbPersistable * This,
            /* [size_is][string][out][in] */ OLECHAR **pFilename,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *ReleaseFile )( 
            IWsbPersistable * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetDefaultFileName )( 
            IWsbPersistable * This,
            /* [string][in] */ OLECHAR *fileName);
        
        END_INTERFACE
    } IWsbPersistableVtbl;

    interface IWsbPersistable
    {
        CONST_VTBL struct IWsbPersistableVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWsbPersistable_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWsbPersistable_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWsbPersistable_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWsbPersistable_SetIsDirty(This,isDirty)	\
    (This)->lpVtbl -> SetIsDirty(This,isDirty)


#define IWsbPersistable_GetDefaultFileName(This,pFilename,bufferSize)	\
    (This)->lpVtbl -> GetDefaultFileName(This,pFilename,bufferSize)

#define IWsbPersistable_ReleaseFile(This)	\
    (This)->lpVtbl -> ReleaseFile(This)

#define IWsbPersistable_SetDefaultFileName(This,fileName)	\
    (This)->lpVtbl -> SetDefaultFileName(This,fileName)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IWsbPersistable_GetDefaultFileName_Proxy( 
    IWsbPersistable * This,
    /* [size_is][string][out][in] */ OLECHAR **pFilename,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IWsbPersistable_GetDefaultFileName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbPersistable_ReleaseFile_Proxy( 
    IWsbPersistable * This);


void __RPC_STUB IWsbPersistable_ReleaseFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbPersistable_SetDefaultFileName_Proxy( 
    IWsbPersistable * This,
    /* [string][in] */ OLECHAR *fileName);


void __RPC_STUB IWsbPersistable_SetDefaultFileName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IWsbPersistable_INTERFACE_DEFINED__ */


#ifndef __IWsbString_INTERFACE_DEFINED__
#define __IWsbString_INTERFACE_DEFINED__

/* interface IWsbString */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWsbString;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DB35D731-21E9-11D0-81B8-00A0C91180F2")
    IWsbString : public IWsbCollectable
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CompareToString( 
            /* [string][in] */ OLECHAR *value,
            /* [out] */ SHORT *pResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CompareToIString( 
            /* [in] */ IWsbString *pString,
            /* [out] */ SHORT *pResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetString( 
            /* [string][out][in] */ OLECHAR **pValue,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStringAndCase( 
            /* [string][out][in] */ OLECHAR **pValue,
            /* [out] */ BOOL *pIsCaseDependent,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsCaseDependent( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetIsCaseDependent( 
            /* [in] */ BOOL isCaseDependent) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetString( 
            /* [string][in] */ OLECHAR *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetStringAndCase( 
            /* [string][in] */ OLECHAR *value,
            /* [in] */ BOOL isCaseDependent) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWsbStringVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWsbString * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWsbString * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWsbString * This);
        
        HRESULT ( STDMETHODCALLTYPE *CompareTo )( 
            IWsbString * This,
            /* [in] */ IUnknown *pCollectable,
            /* [out] */ SHORT *pResult);
        
        HRESULT ( STDMETHODCALLTYPE *IsEqual )( 
            IWsbString * This,
            /* [in] */ IUnknown *pCollectable);
        
        HRESULT ( STDMETHODCALLTYPE *CompareToString )( 
            IWsbString * This,
            /* [string][in] */ OLECHAR *value,
            /* [out] */ SHORT *pResult);
        
        HRESULT ( STDMETHODCALLTYPE *CompareToIString )( 
            IWsbString * This,
            /* [in] */ IWsbString *pString,
            /* [out] */ SHORT *pResult);
        
        HRESULT ( STDMETHODCALLTYPE *GetString )( 
            IWsbString * This,
            /* [string][out][in] */ OLECHAR **pValue,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetStringAndCase )( 
            IWsbString * This,
            /* [string][out][in] */ OLECHAR **pValue,
            /* [out] */ BOOL *pIsCaseDependent,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *IsCaseDependent )( 
            IWsbString * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetIsCaseDependent )( 
            IWsbString * This,
            /* [in] */ BOOL isCaseDependent);
        
        HRESULT ( STDMETHODCALLTYPE *SetString )( 
            IWsbString * This,
            /* [string][in] */ OLECHAR *value);
        
        HRESULT ( STDMETHODCALLTYPE *SetStringAndCase )( 
            IWsbString * This,
            /* [string][in] */ OLECHAR *value,
            /* [in] */ BOOL isCaseDependent);
        
        END_INTERFACE
    } IWsbStringVtbl;

    interface IWsbString
    {
        CONST_VTBL struct IWsbStringVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWsbString_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWsbString_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWsbString_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWsbString_CompareTo(This,pCollectable,pResult)	\
    (This)->lpVtbl -> CompareTo(This,pCollectable,pResult)

#define IWsbString_IsEqual(This,pCollectable)	\
    (This)->lpVtbl -> IsEqual(This,pCollectable)


#define IWsbString_CompareToString(This,value,pResult)	\
    (This)->lpVtbl -> CompareToString(This,value,pResult)

#define IWsbString_CompareToIString(This,pString,pResult)	\
    (This)->lpVtbl -> CompareToIString(This,pString,pResult)

#define IWsbString_GetString(This,pValue,bufferSize)	\
    (This)->lpVtbl -> GetString(This,pValue,bufferSize)

#define IWsbString_GetStringAndCase(This,pValue,pIsCaseDependent,bufferSize)	\
    (This)->lpVtbl -> GetStringAndCase(This,pValue,pIsCaseDependent,bufferSize)

#define IWsbString_IsCaseDependent(This)	\
    (This)->lpVtbl -> IsCaseDependent(This)

#define IWsbString_SetIsCaseDependent(This,isCaseDependent)	\
    (This)->lpVtbl -> SetIsCaseDependent(This,isCaseDependent)

#define IWsbString_SetString(This,value)	\
    (This)->lpVtbl -> SetString(This,value)

#define IWsbString_SetStringAndCase(This,value,isCaseDependent)	\
    (This)->lpVtbl -> SetStringAndCase(This,value,isCaseDependent)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IWsbString_CompareToString_Proxy( 
    IWsbString * This,
    /* [string][in] */ OLECHAR *value,
    /* [out] */ SHORT *pResult);


void __RPC_STUB IWsbString_CompareToString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbString_CompareToIString_Proxy( 
    IWsbString * This,
    /* [in] */ IWsbString *pString,
    /* [out] */ SHORT *pResult);


void __RPC_STUB IWsbString_CompareToIString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbString_GetString_Proxy( 
    IWsbString * This,
    /* [string][out][in] */ OLECHAR **pValue,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IWsbString_GetString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbString_GetStringAndCase_Proxy( 
    IWsbString * This,
    /* [string][out][in] */ OLECHAR **pValue,
    /* [out] */ BOOL *pIsCaseDependent,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IWsbString_GetStringAndCase_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbString_IsCaseDependent_Proxy( 
    IWsbString * This);


void __RPC_STUB IWsbString_IsCaseDependent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbString_SetIsCaseDependent_Proxy( 
    IWsbString * This,
    /* [in] */ BOOL isCaseDependent);


void __RPC_STUB IWsbString_SetIsCaseDependent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbString_SetString_Proxy( 
    IWsbString * This,
    /* [string][in] */ OLECHAR *value);


void __RPC_STUB IWsbString_SetString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbString_SetStringAndCase_Proxy( 
    IWsbString * This,
    /* [string][in] */ OLECHAR *value,
    /* [in] */ BOOL isCaseDependent);


void __RPC_STUB IWsbString_SetStringAndCase_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IWsbString_INTERFACE_DEFINED__ */


#ifndef __IWsbTestable_INTERFACE_DEFINED__
#define __IWsbTestable_INTERFACE_DEFINED__

/* interface IWsbTestable */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWsbTestable;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("05342021-25D8-11D0-81BB-00A0C91180F2")
    IWsbTestable : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Test( 
            /* [out] */ USHORT *passed,
            /* [out] */ USHORT *failed) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWsbTestableVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWsbTestable * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWsbTestable * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWsbTestable * This);
        
        HRESULT ( STDMETHODCALLTYPE *Test )( 
            IWsbTestable * This,
            /* [out] */ USHORT *passed,
            /* [out] */ USHORT *failed);
        
        END_INTERFACE
    } IWsbTestableVtbl;

    interface IWsbTestable
    {
        CONST_VTBL struct IWsbTestableVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWsbTestable_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWsbTestable_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWsbTestable_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWsbTestable_Test(This,passed,failed)	\
    (This)->lpVtbl -> Test(This,passed,failed)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IWsbTestable_Test_Proxy( 
    IWsbTestable * This,
    /* [out] */ USHORT *passed,
    /* [out] */ USHORT *failed);


void __RPC_STUB IWsbTestable_Test_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IWsbTestable_INTERFACE_DEFINED__ */


#ifndef __IWsbDbSys_INTERFACE_DEFINED__
#define __IWsbDbSys_INTERFACE_DEFINED__

/* interface IWsbDbSys */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWsbDbSys;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F2608980-0A45-47B4-B110-37EA59F67C47")
    IWsbDbSys : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Backup( 
            /* [string][in] */ OLECHAR *path,
            /* [in] */ ULONG flags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Init( 
            /* [string][in] */ OLECHAR *path,
            /* [in] */ ULONG flags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Terminate( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE NewSession( 
            /* [out] */ IWsbDbSession **ppSession) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetGlobalSession( 
            /* [out] */ IWsbDbSession **ppSession) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Restore( 
            /* [string][in] */ OLECHAR *fromPath,
            /* [string][in] */ OLECHAR *toPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IncrementChangeCount( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWsbDbSysVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWsbDbSys * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWsbDbSys * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWsbDbSys * This);
        
        HRESULT ( STDMETHODCALLTYPE *Backup )( 
            IWsbDbSys * This,
            /* [string][in] */ OLECHAR *path,
            /* [in] */ ULONG flags);
        
        HRESULT ( STDMETHODCALLTYPE *Init )( 
            IWsbDbSys * This,
            /* [string][in] */ OLECHAR *path,
            /* [in] */ ULONG flags);
        
        HRESULT ( STDMETHODCALLTYPE *Terminate )( 
            IWsbDbSys * This);
        
        HRESULT ( STDMETHODCALLTYPE *NewSession )( 
            IWsbDbSys * This,
            /* [out] */ IWsbDbSession **ppSession);
        
        HRESULT ( STDMETHODCALLTYPE *GetGlobalSession )( 
            IWsbDbSys * This,
            /* [out] */ IWsbDbSession **ppSession);
        
        HRESULT ( STDMETHODCALLTYPE *Restore )( 
            IWsbDbSys * This,
            /* [string][in] */ OLECHAR *fromPath,
            /* [string][in] */ OLECHAR *toPath);
        
        HRESULT ( STDMETHODCALLTYPE *IncrementChangeCount )( 
            IWsbDbSys * This);
        
        END_INTERFACE
    } IWsbDbSysVtbl;

    interface IWsbDbSys
    {
        CONST_VTBL struct IWsbDbSysVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWsbDbSys_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWsbDbSys_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWsbDbSys_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWsbDbSys_Backup(This,path,flags)	\
    (This)->lpVtbl -> Backup(This,path,flags)

#define IWsbDbSys_Init(This,path,flags)	\
    (This)->lpVtbl -> Init(This,path,flags)

#define IWsbDbSys_Terminate(This)	\
    (This)->lpVtbl -> Terminate(This)

#define IWsbDbSys_NewSession(This,ppSession)	\
    (This)->lpVtbl -> NewSession(This,ppSession)

#define IWsbDbSys_GetGlobalSession(This,ppSession)	\
    (This)->lpVtbl -> GetGlobalSession(This,ppSession)

#define IWsbDbSys_Restore(This,fromPath,toPath)	\
    (This)->lpVtbl -> Restore(This,fromPath,toPath)

#define IWsbDbSys_IncrementChangeCount(This)	\
    (This)->lpVtbl -> IncrementChangeCount(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IWsbDbSys_Backup_Proxy( 
    IWsbDbSys * This,
    /* [string][in] */ OLECHAR *path,
    /* [in] */ ULONG flags);


void __RPC_STUB IWsbDbSys_Backup_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDbSys_Init_Proxy( 
    IWsbDbSys * This,
    /* [string][in] */ OLECHAR *path,
    /* [in] */ ULONG flags);


void __RPC_STUB IWsbDbSys_Init_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDbSys_Terminate_Proxy( 
    IWsbDbSys * This);


void __RPC_STUB IWsbDbSys_Terminate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDbSys_NewSession_Proxy( 
    IWsbDbSys * This,
    /* [out] */ IWsbDbSession **ppSession);


void __RPC_STUB IWsbDbSys_NewSession_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDbSys_GetGlobalSession_Proxy( 
    IWsbDbSys * This,
    /* [out] */ IWsbDbSession **ppSession);


void __RPC_STUB IWsbDbSys_GetGlobalSession_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDbSys_Restore_Proxy( 
    IWsbDbSys * This,
    /* [string][in] */ OLECHAR *fromPath,
    /* [string][in] */ OLECHAR *toPath);


void __RPC_STUB IWsbDbSys_Restore_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDbSys_IncrementChangeCount_Proxy( 
    IWsbDbSys * This);


void __RPC_STUB IWsbDbSys_IncrementChangeCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IWsbDbSys_INTERFACE_DEFINED__ */


#ifndef __IWsbDb_INTERFACE_DEFINED__
#define __IWsbDb_INTERFACE_DEFINED__

/* interface IWsbDb */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWsbDb;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("D7A42F4A-117C-47A3-9C30-92D63A4919E4")
    IWsbDb : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Close( 
            /* [in] */ IWsbDbSession *pSession) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Create( 
            /* [string][in] */ OLECHAR *path,
            /* [defaultvalue][in] */ ULONG flags = 0) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Delete( 
            /* [string][in] */ OLECHAR *path,
            /* [defaultvalue][in] */ ULONG flags = 0) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Dump( 
            /* [string][in] */ OLECHAR *Filename,
            /* [in] */ ULONG Flags,
            /* [in] */ ULONG Data) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetEntity( 
            /* [in] */ IWsbDbSession *pSession,
            /* [in] */ ULONG RecId,
            /* [in] */ REFIID riid,
            /* [iid_is][retval][out] */ void **ppEntity) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetName( 
            /* [string][out] */ OLECHAR **pName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPath( 
            /* [string][out] */ OLECHAR **pPath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetVersion( 
            /* [out] */ ULONG *pVer) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Locate( 
            /* [string][in] */ OLECHAR *path) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Open( 
            /* [out][in] */ IWsbDbSession **ppSession) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWsbDbVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWsbDb * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWsbDb * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWsbDb * This);
        
        HRESULT ( STDMETHODCALLTYPE *Close )( 
            IWsbDb * This,
            /* [in] */ IWsbDbSession *pSession);
        
        HRESULT ( STDMETHODCALLTYPE *Create )( 
            IWsbDb * This,
            /* [string][in] */ OLECHAR *path,
            /* [defaultvalue][in] */ ULONG flags);
        
        HRESULT ( STDMETHODCALLTYPE *Delete )( 
            IWsbDb * This,
            /* [string][in] */ OLECHAR *path,
            /* [defaultvalue][in] */ ULONG flags);
        
        HRESULT ( STDMETHODCALLTYPE *Dump )( 
            IWsbDb * This,
            /* [string][in] */ OLECHAR *Filename,
            /* [in] */ ULONG Flags,
            /* [in] */ ULONG Data);
        
        HRESULT ( STDMETHODCALLTYPE *GetEntity )( 
            IWsbDb * This,
            /* [in] */ IWsbDbSession *pSession,
            /* [in] */ ULONG RecId,
            /* [in] */ REFIID riid,
            /* [iid_is][retval][out] */ void **ppEntity);
        
        HRESULT ( STDMETHODCALLTYPE *GetName )( 
            IWsbDb * This,
            /* [string][out] */ OLECHAR **pName);
        
        HRESULT ( STDMETHODCALLTYPE *GetPath )( 
            IWsbDb * This,
            /* [string][out] */ OLECHAR **pPath);
        
        HRESULT ( STDMETHODCALLTYPE *GetVersion )( 
            IWsbDb * This,
            /* [out] */ ULONG *pVer);
        
        HRESULT ( STDMETHODCALLTYPE *Locate )( 
            IWsbDb * This,
            /* [string][in] */ OLECHAR *path);
        
        HRESULT ( STDMETHODCALLTYPE *Open )( 
            IWsbDb * This,
            /* [out][in] */ IWsbDbSession **ppSession);
        
        END_INTERFACE
    } IWsbDbVtbl;

    interface IWsbDb
    {
        CONST_VTBL struct IWsbDbVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWsbDb_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWsbDb_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWsbDb_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWsbDb_Close(This,pSession)	\
    (This)->lpVtbl -> Close(This,pSession)

#define IWsbDb_Create(This,path,flags)	\
    (This)->lpVtbl -> Create(This,path,flags)

#define IWsbDb_Delete(This,path,flags)	\
    (This)->lpVtbl -> Delete(This,path,flags)

#define IWsbDb_Dump(This,Filename,Flags,Data)	\
    (This)->lpVtbl -> Dump(This,Filename,Flags,Data)

#define IWsbDb_GetEntity(This,pSession,RecId,riid,ppEntity)	\
    (This)->lpVtbl -> GetEntity(This,pSession,RecId,riid,ppEntity)

#define IWsbDb_GetName(This,pName)	\
    (This)->lpVtbl -> GetName(This,pName)

#define IWsbDb_GetPath(This,pPath)	\
    (This)->lpVtbl -> GetPath(This,pPath)

#define IWsbDb_GetVersion(This,pVer)	\
    (This)->lpVtbl -> GetVersion(This,pVer)

#define IWsbDb_Locate(This,path)	\
    (This)->lpVtbl -> Locate(This,path)

#define IWsbDb_Open(This,ppSession)	\
    (This)->lpVtbl -> Open(This,ppSession)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IWsbDb_Close_Proxy( 
    IWsbDb * This,
    /* [in] */ IWsbDbSession *pSession);


void __RPC_STUB IWsbDb_Close_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDb_Create_Proxy( 
    IWsbDb * This,
    /* [string][in] */ OLECHAR *path,
    /* [defaultvalue][in] */ ULONG flags);


void __RPC_STUB IWsbDb_Create_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDb_Delete_Proxy( 
    IWsbDb * This,
    /* [string][in] */ OLECHAR *path,
    /* [defaultvalue][in] */ ULONG flags);


void __RPC_STUB IWsbDb_Delete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDb_Dump_Proxy( 
    IWsbDb * This,
    /* [string][in] */ OLECHAR *Filename,
    /* [in] */ ULONG Flags,
    /* [in] */ ULONG Data);


void __RPC_STUB IWsbDb_Dump_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDb_GetEntity_Proxy( 
    IWsbDb * This,
    /* [in] */ IWsbDbSession *pSession,
    /* [in] */ ULONG RecId,
    /* [in] */ REFIID riid,
    /* [iid_is][retval][out] */ void **ppEntity);


void __RPC_STUB IWsbDb_GetEntity_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDb_GetName_Proxy( 
    IWsbDb * This,
    /* [string][out] */ OLECHAR **pName);


void __RPC_STUB IWsbDb_GetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDb_GetPath_Proxy( 
    IWsbDb * This,
    /* [string][out] */ OLECHAR **pPath);


void __RPC_STUB IWsbDb_GetPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDb_GetVersion_Proxy( 
    IWsbDb * This,
    /* [out] */ ULONG *pVer);


void __RPC_STUB IWsbDb_GetVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDb_Locate_Proxy( 
    IWsbDb * This,
    /* [string][in] */ OLECHAR *path);


void __RPC_STUB IWsbDb_Locate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDb_Open_Proxy( 
    IWsbDb * This,
    /* [out][in] */ IWsbDbSession **ppSession);


void __RPC_STUB IWsbDb_Open_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IWsbDb_INTERFACE_DEFINED__ */


#ifndef __IWsbDbSession_INTERFACE_DEFINED__
#define __IWsbDbSession_INTERFACE_DEFINED__

/* interface IWsbDbSession */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWsbDbSession;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("01973831-E996-11d0-9928-00A0C9058BF6")
    IWsbDbSession : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE TransactionBegin( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE TransactionCancel( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE TransactionEnd( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWsbDbSessionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWsbDbSession * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWsbDbSession * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWsbDbSession * This);
        
        HRESULT ( STDMETHODCALLTYPE *TransactionBegin )( 
            IWsbDbSession * This);
        
        HRESULT ( STDMETHODCALLTYPE *TransactionCancel )( 
            IWsbDbSession * This);
        
        HRESULT ( STDMETHODCALLTYPE *TransactionEnd )( 
            IWsbDbSession * This);
        
        END_INTERFACE
    } IWsbDbSessionVtbl;

    interface IWsbDbSession
    {
        CONST_VTBL struct IWsbDbSessionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWsbDbSession_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWsbDbSession_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWsbDbSession_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWsbDbSession_TransactionBegin(This)	\
    (This)->lpVtbl -> TransactionBegin(This)

#define IWsbDbSession_TransactionCancel(This)	\
    (This)->lpVtbl -> TransactionCancel(This)

#define IWsbDbSession_TransactionEnd(This)	\
    (This)->lpVtbl -> TransactionEnd(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IWsbDbSession_TransactionBegin_Proxy( 
    IWsbDbSession * This);


void __RPC_STUB IWsbDbSession_TransactionBegin_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDbSession_TransactionCancel_Proxy( 
    IWsbDbSession * This);


void __RPC_STUB IWsbDbSession_TransactionCancel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDbSession_TransactionEnd_Proxy( 
    IWsbDbSession * This);


void __RPC_STUB IWsbDbSession_TransactionEnd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IWsbDbSession_INTERFACE_DEFINED__ */


#ifndef __IWsbDbKey_INTERFACE_DEFINED__
#define __IWsbDbKey_INTERFACE_DEFINED__

/* interface IWsbDbKey */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWsbDbKey;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("46CE9EDA-447C-11D0-98FC-00A0C9058BF6")
    IWsbDbKey : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE AppendBool( 
            /* [in] */ BOOL value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AppendBytes( 
            /* [size_is][in] */ UCHAR *bytes,
            /* [in] */ ULONG size) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AppendFiletime( 
            /* [in] */ FILETIME value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AppendGuid( 
            /* [in] */ GUID value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AppendLonglong( 
            /* [in] */ LONGLONG value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AppendString( 
            /* [string][in] */ OLECHAR *value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetType( 
            /* [out] */ ULONG *pType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetToBool( 
            /* [in] */ BOOL value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetToBytes( 
            /* [size_is][in] */ UCHAR *bytes,
            /* [in] */ ULONG size) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetToFiletime( 
            /* [in] */ FILETIME value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetToGuid( 
            /* [in] */ GUID value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetToLonglong( 
            /* [in] */ LONGLONG value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetToUlong( 
            /* [in] */ ULONG value) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetToString( 
            /* [string][in] */ OLECHAR *value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWsbDbKeyVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWsbDbKey * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWsbDbKey * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWsbDbKey * This);
        
        HRESULT ( STDMETHODCALLTYPE *AppendBool )( 
            IWsbDbKey * This,
            /* [in] */ BOOL value);
        
        HRESULT ( STDMETHODCALLTYPE *AppendBytes )( 
            IWsbDbKey * This,
            /* [size_is][in] */ UCHAR *bytes,
            /* [in] */ ULONG size);
        
        HRESULT ( STDMETHODCALLTYPE *AppendFiletime )( 
            IWsbDbKey * This,
            /* [in] */ FILETIME value);
        
        HRESULT ( STDMETHODCALLTYPE *AppendGuid )( 
            IWsbDbKey * This,
            /* [in] */ GUID value);
        
        HRESULT ( STDMETHODCALLTYPE *AppendLonglong )( 
            IWsbDbKey * This,
            /* [in] */ LONGLONG value);
        
        HRESULT ( STDMETHODCALLTYPE *AppendString )( 
            IWsbDbKey * This,
            /* [string][in] */ OLECHAR *value);
        
        HRESULT ( STDMETHODCALLTYPE *GetType )( 
            IWsbDbKey * This,
            /* [out] */ ULONG *pType);
        
        HRESULT ( STDMETHODCALLTYPE *SetToBool )( 
            IWsbDbKey * This,
            /* [in] */ BOOL value);
        
        HRESULT ( STDMETHODCALLTYPE *SetToBytes )( 
            IWsbDbKey * This,
            /* [size_is][in] */ UCHAR *bytes,
            /* [in] */ ULONG size);
        
        HRESULT ( STDMETHODCALLTYPE *SetToFiletime )( 
            IWsbDbKey * This,
            /* [in] */ FILETIME value);
        
        HRESULT ( STDMETHODCALLTYPE *SetToGuid )( 
            IWsbDbKey * This,
            /* [in] */ GUID value);
        
        HRESULT ( STDMETHODCALLTYPE *SetToLonglong )( 
            IWsbDbKey * This,
            /* [in] */ LONGLONG value);
        
        HRESULT ( STDMETHODCALLTYPE *SetToUlong )( 
            IWsbDbKey * This,
            /* [in] */ ULONG value);
        
        HRESULT ( STDMETHODCALLTYPE *SetToString )( 
            IWsbDbKey * This,
            /* [string][in] */ OLECHAR *value);
        
        END_INTERFACE
    } IWsbDbKeyVtbl;

    interface IWsbDbKey
    {
        CONST_VTBL struct IWsbDbKeyVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWsbDbKey_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWsbDbKey_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWsbDbKey_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWsbDbKey_AppendBool(This,value)	\
    (This)->lpVtbl -> AppendBool(This,value)

#define IWsbDbKey_AppendBytes(This,bytes,size)	\
    (This)->lpVtbl -> AppendBytes(This,bytes,size)

#define IWsbDbKey_AppendFiletime(This,value)	\
    (This)->lpVtbl -> AppendFiletime(This,value)

#define IWsbDbKey_AppendGuid(This,value)	\
    (This)->lpVtbl -> AppendGuid(This,value)

#define IWsbDbKey_AppendLonglong(This,value)	\
    (This)->lpVtbl -> AppendLonglong(This,value)

#define IWsbDbKey_AppendString(This,value)	\
    (This)->lpVtbl -> AppendString(This,value)

#define IWsbDbKey_GetType(This,pType)	\
    (This)->lpVtbl -> GetType(This,pType)

#define IWsbDbKey_SetToBool(This,value)	\
    (This)->lpVtbl -> SetToBool(This,value)

#define IWsbDbKey_SetToBytes(This,bytes,size)	\
    (This)->lpVtbl -> SetToBytes(This,bytes,size)

#define IWsbDbKey_SetToFiletime(This,value)	\
    (This)->lpVtbl -> SetToFiletime(This,value)

#define IWsbDbKey_SetToGuid(This,value)	\
    (This)->lpVtbl -> SetToGuid(This,value)

#define IWsbDbKey_SetToLonglong(This,value)	\
    (This)->lpVtbl -> SetToLonglong(This,value)

#define IWsbDbKey_SetToUlong(This,value)	\
    (This)->lpVtbl -> SetToUlong(This,value)

#define IWsbDbKey_SetToString(This,value)	\
    (This)->lpVtbl -> SetToString(This,value)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IWsbDbKey_AppendBool_Proxy( 
    IWsbDbKey * This,
    /* [in] */ BOOL value);


void __RPC_STUB IWsbDbKey_AppendBool_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDbKey_AppendBytes_Proxy( 
    IWsbDbKey * This,
    /* [size_is][in] */ UCHAR *bytes,
    /* [in] */ ULONG size);


void __RPC_STUB IWsbDbKey_AppendBytes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDbKey_AppendFiletime_Proxy( 
    IWsbDbKey * This,
    /* [in] */ FILETIME value);


void __RPC_STUB IWsbDbKey_AppendFiletime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDbKey_AppendGuid_Proxy( 
    IWsbDbKey * This,
    /* [in] */ GUID value);


void __RPC_STUB IWsbDbKey_AppendGuid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDbKey_AppendLonglong_Proxy( 
    IWsbDbKey * This,
    /* [in] */ LONGLONG value);


void __RPC_STUB IWsbDbKey_AppendLonglong_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDbKey_AppendString_Proxy( 
    IWsbDbKey * This,
    /* [string][in] */ OLECHAR *value);


void __RPC_STUB IWsbDbKey_AppendString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDbKey_GetType_Proxy( 
    IWsbDbKey * This,
    /* [out] */ ULONG *pType);


void __RPC_STUB IWsbDbKey_GetType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDbKey_SetToBool_Proxy( 
    IWsbDbKey * This,
    /* [in] */ BOOL value);


void __RPC_STUB IWsbDbKey_SetToBool_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDbKey_SetToBytes_Proxy( 
    IWsbDbKey * This,
    /* [size_is][in] */ UCHAR *bytes,
    /* [in] */ ULONG size);


void __RPC_STUB IWsbDbKey_SetToBytes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDbKey_SetToFiletime_Proxy( 
    IWsbDbKey * This,
    /* [in] */ FILETIME value);


void __RPC_STUB IWsbDbKey_SetToFiletime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDbKey_SetToGuid_Proxy( 
    IWsbDbKey * This,
    /* [in] */ GUID value);


void __RPC_STUB IWsbDbKey_SetToGuid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDbKey_SetToLonglong_Proxy( 
    IWsbDbKey * This,
    /* [in] */ LONGLONG value);


void __RPC_STUB IWsbDbKey_SetToLonglong_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDbKey_SetToUlong_Proxy( 
    IWsbDbKey * This,
    /* [in] */ ULONG value);


void __RPC_STUB IWsbDbKey_SetToUlong_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDbKey_SetToString_Proxy( 
    IWsbDbKey * This,
    /* [string][in] */ OLECHAR *value);


void __RPC_STUB IWsbDbKey_SetToString_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IWsbDbKey_INTERFACE_DEFINED__ */


#ifndef __IWsbDbEntity_INTERFACE_DEFINED__
#define __IWsbDbEntity_INTERFACE_DEFINED__

/* interface IWsbDbEntity */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWsbDbEntity;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FC7FB18F-F497-47A6-A28F-7CC4BFECAA5E")
    IWsbDbEntity : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Clone( 
            /* [in] */ REFIID riid,
            /* [iid_is][retval][out] */ void **ppEntity) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Disconnect( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FindEQ( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FindGT( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FindGTE( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FindLT( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FindLTE( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE First( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Last( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MarkAsNew( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Next( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Previous( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Print( 
            /* [in] */ IStream *pStream) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Remove( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UpdateKey( 
            /* [in] */ IWsbDbKey *pKey) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UseKey( 
            /* [in] */ ULONG type) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Write( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSequentialScan( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ResetSequentialScan( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWsbDbEntityVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWsbDbEntity * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWsbDbEntity * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWsbDbEntity * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IWsbDbEntity * This,
            /* [in] */ REFIID riid,
            /* [iid_is][retval][out] */ void **ppEntity);
        
        HRESULT ( STDMETHODCALLTYPE *Disconnect )( 
            IWsbDbEntity * This);
        
        HRESULT ( STDMETHODCALLTYPE *FindEQ )( 
            IWsbDbEntity * This);
        
        HRESULT ( STDMETHODCALLTYPE *FindGT )( 
            IWsbDbEntity * This);
        
        HRESULT ( STDMETHODCALLTYPE *FindGTE )( 
            IWsbDbEntity * This);
        
        HRESULT ( STDMETHODCALLTYPE *FindLT )( 
            IWsbDbEntity * This);
        
        HRESULT ( STDMETHODCALLTYPE *FindLTE )( 
            IWsbDbEntity * This);
        
        HRESULT ( STDMETHODCALLTYPE *First )( 
            IWsbDbEntity * This);
        
        HRESULT ( STDMETHODCALLTYPE *Last )( 
            IWsbDbEntity * This);
        
        HRESULT ( STDMETHODCALLTYPE *MarkAsNew )( 
            IWsbDbEntity * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IWsbDbEntity * This);
        
        HRESULT ( STDMETHODCALLTYPE *Previous )( 
            IWsbDbEntity * This);
        
        HRESULT ( STDMETHODCALLTYPE *Print )( 
            IWsbDbEntity * This,
            /* [in] */ IStream *pStream);
        
        HRESULT ( STDMETHODCALLTYPE *Remove )( 
            IWsbDbEntity * This);
        
        HRESULT ( STDMETHODCALLTYPE *UpdateKey )( 
            IWsbDbEntity * This,
            /* [in] */ IWsbDbKey *pKey);
        
        HRESULT ( STDMETHODCALLTYPE *UseKey )( 
            IWsbDbEntity * This,
            /* [in] */ ULONG type);
        
        HRESULT ( STDMETHODCALLTYPE *Write )( 
            IWsbDbEntity * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetSequentialScan )( 
            IWsbDbEntity * This);
        
        HRESULT ( STDMETHODCALLTYPE *ResetSequentialScan )( 
            IWsbDbEntity * This);
        
        END_INTERFACE
    } IWsbDbEntityVtbl;

    interface IWsbDbEntity
    {
        CONST_VTBL struct IWsbDbEntityVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWsbDbEntity_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWsbDbEntity_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWsbDbEntity_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWsbDbEntity_Clone(This,riid,ppEntity)	\
    (This)->lpVtbl -> Clone(This,riid,ppEntity)

#define IWsbDbEntity_Disconnect(This)	\
    (This)->lpVtbl -> Disconnect(This)

#define IWsbDbEntity_FindEQ(This)	\
    (This)->lpVtbl -> FindEQ(This)

#define IWsbDbEntity_FindGT(This)	\
    (This)->lpVtbl -> FindGT(This)

#define IWsbDbEntity_FindGTE(This)	\
    (This)->lpVtbl -> FindGTE(This)

#define IWsbDbEntity_FindLT(This)	\
    (This)->lpVtbl -> FindLT(This)

#define IWsbDbEntity_FindLTE(This)	\
    (This)->lpVtbl -> FindLTE(This)

#define IWsbDbEntity_First(This)	\
    (This)->lpVtbl -> First(This)

#define IWsbDbEntity_Last(This)	\
    (This)->lpVtbl -> Last(This)

#define IWsbDbEntity_MarkAsNew(This)	\
    (This)->lpVtbl -> MarkAsNew(This)

#define IWsbDbEntity_Next(This)	\
    (This)->lpVtbl -> Next(This)

#define IWsbDbEntity_Previous(This)	\
    (This)->lpVtbl -> Previous(This)

#define IWsbDbEntity_Print(This,pStream)	\
    (This)->lpVtbl -> Print(This,pStream)

#define IWsbDbEntity_Remove(This)	\
    (This)->lpVtbl -> Remove(This)

#define IWsbDbEntity_UpdateKey(This,pKey)	\
    (This)->lpVtbl -> UpdateKey(This,pKey)

#define IWsbDbEntity_UseKey(This,type)	\
    (This)->lpVtbl -> UseKey(This,type)

#define IWsbDbEntity_Write(This)	\
    (This)->lpVtbl -> Write(This)

#define IWsbDbEntity_SetSequentialScan(This)	\
    (This)->lpVtbl -> SetSequentialScan(This)

#define IWsbDbEntity_ResetSequentialScan(This)	\
    (This)->lpVtbl -> ResetSequentialScan(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IWsbDbEntity_Clone_Proxy( 
    IWsbDbEntity * This,
    /* [in] */ REFIID riid,
    /* [iid_is][retval][out] */ void **ppEntity);


void __RPC_STUB IWsbDbEntity_Clone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDbEntity_Disconnect_Proxy( 
    IWsbDbEntity * This);


void __RPC_STUB IWsbDbEntity_Disconnect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDbEntity_FindEQ_Proxy( 
    IWsbDbEntity * This);


void __RPC_STUB IWsbDbEntity_FindEQ_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDbEntity_FindGT_Proxy( 
    IWsbDbEntity * This);


void __RPC_STUB IWsbDbEntity_FindGT_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDbEntity_FindGTE_Proxy( 
    IWsbDbEntity * This);


void __RPC_STUB IWsbDbEntity_FindGTE_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDbEntity_FindLT_Proxy( 
    IWsbDbEntity * This);


void __RPC_STUB IWsbDbEntity_FindLT_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDbEntity_FindLTE_Proxy( 
    IWsbDbEntity * This);


void __RPC_STUB IWsbDbEntity_FindLTE_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDbEntity_First_Proxy( 
    IWsbDbEntity * This);


void __RPC_STUB IWsbDbEntity_First_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDbEntity_Last_Proxy( 
    IWsbDbEntity * This);


void __RPC_STUB IWsbDbEntity_Last_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDbEntity_MarkAsNew_Proxy( 
    IWsbDbEntity * This);


void __RPC_STUB IWsbDbEntity_MarkAsNew_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDbEntity_Next_Proxy( 
    IWsbDbEntity * This);


void __RPC_STUB IWsbDbEntity_Next_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDbEntity_Previous_Proxy( 
    IWsbDbEntity * This);


void __RPC_STUB IWsbDbEntity_Previous_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDbEntity_Print_Proxy( 
    IWsbDbEntity * This,
    /* [in] */ IStream *pStream);


void __RPC_STUB IWsbDbEntity_Print_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDbEntity_Remove_Proxy( 
    IWsbDbEntity * This);


void __RPC_STUB IWsbDbEntity_Remove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDbEntity_UpdateKey_Proxy( 
    IWsbDbEntity * This,
    /* [in] */ IWsbDbKey *pKey);


void __RPC_STUB IWsbDbEntity_UpdateKey_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDbEntity_UseKey_Proxy( 
    IWsbDbEntity * This,
    /* [in] */ ULONG type);


void __RPC_STUB IWsbDbEntity_UseKey_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDbEntity_Write_Proxy( 
    IWsbDbEntity * This);


void __RPC_STUB IWsbDbEntity_Write_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDbEntity_SetSequentialScan_Proxy( 
    IWsbDbEntity * This);


void __RPC_STUB IWsbDbEntity_SetSequentialScan_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDbEntity_ResetSequentialScan_Proxy( 
    IWsbDbEntity * This);


void __RPC_STUB IWsbDbEntity_ResetSequentialScan_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IWsbDbEntity_INTERFACE_DEFINED__ */


#ifndef __IWsbCreateLocalObject_INTERFACE_DEFINED__
#define __IWsbCreateLocalObject_INTERFACE_DEFINED__

/* interface IWsbCreateLocalObject */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWsbCreateLocalObject;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EF5207D0-8C0B-11d0-9E39-00A0C916F120")
    IWsbCreateLocalObject : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CreateInstance( 
            /* [in] */ REFCLSID rclsid,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppv) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWsbCreateLocalObjectVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWsbCreateLocalObject * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWsbCreateLocalObject * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWsbCreateLocalObject * This);
        
        HRESULT ( STDMETHODCALLTYPE *CreateInstance )( 
            IWsbCreateLocalObject * This,
            /* [in] */ REFCLSID rclsid,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppv);
        
        END_INTERFACE
    } IWsbCreateLocalObjectVtbl;

    interface IWsbCreateLocalObject
    {
        CONST_VTBL struct IWsbCreateLocalObjectVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWsbCreateLocalObject_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWsbCreateLocalObject_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWsbCreateLocalObject_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWsbCreateLocalObject_CreateInstance(This,rclsid,riid,ppv)	\
    (This)->lpVtbl -> CreateInstance(This,rclsid,riid,ppv)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IWsbCreateLocalObject_CreateInstance_Proxy( 
    IWsbCreateLocalObject * This,
    /* [in] */ REFCLSID rclsid,
    /* [in] */ REFIID riid,
    /* [iid_is][out] */ void **ppv);


void __RPC_STUB IWsbCreateLocalObject_CreateInstance_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IWsbCreateLocalObject_INTERFACE_DEFINED__ */


#ifndef __IWsbTrace_INTERFACE_DEFINED__
#define __IWsbTrace_INTERFACE_DEFINED__

/* interface IWsbTrace */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWsbTrace;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0AF2DA10-7DD7-11d0-9E33-00A0C916F120")
    IWsbTrace : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE StartTrace( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StopTrace( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetTraceOn( 
            /* [in] */ LONGLONG traceElement) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetTraceOff( 
            /* [in] */ LONGLONG traceElement) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTraceSettings( 
            /* [out] */ LONGLONG *pTraceElements) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTraceSetting( 
            /* [in] */ LONGLONG traceElement,
            /* [out] */ BOOL *pOn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DirectOutput( 
            /* [in] */ ULONG output) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetOutputFormat( 
            /* [in] */ BOOL timeStamp,
            /* [in] */ BOOL traceCount,
            /* [in] */ BOOL traceThreadId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOutputFormat( 
            /* [out] */ BOOL *pTimeStamp,
            /* [out] */ BOOL *pTraceCount,
            /* [out] */ BOOL *pTraceThreadId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetTraceFileControls( 
            /* [string][in] */ OLECHAR *traceFileName,
            /* [in] */ BOOL commitEachEntry,
            /* [in] */ LONGLONG maxTraceFileSize,
            /* [string][in] */ OLECHAR *traceFileCopyName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTraceFileControls( 
            /* [string][out] */ OLECHAR **traceFileName,
            /* [out] */ BOOL *pCommitEachEntry,
            /* [out] */ LONGLONG *pMaxTraceFileSize,
            /* [string][out] */ OLECHAR **traceFileCopyName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetTraceEntryExit( 
            /* [in] */ BOOL traceEntryExit) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTraceEntryExit( 
            /* [out] */ BOOL *pTraceEntryExit) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetLogLevel( 
            /* [in] */ WORD traceError) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLogLevel( 
            /* [out] */ WORD *pTraceError) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Print( 
            /* [string][in] */ OLECHAR *traceString) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRegistryEntry( 
            /* [string][out] */ OLECHAR **pRegistryEntry) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRegistryEntry( 
            /* [string][in] */ OLECHAR *pRegistryEntry) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LoadFromRegistry( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetTraceSettings( 
            /* [in] */ LONGLONG traceElements) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLogSnapShot( 
            /* [out] */ BOOL *pOn,
            /* [out] */ WORD *pLevel,
            /* [string][out] */ OLECHAR **pSnapShotPath,
            /* [out] */ BOOL *pResetTrace) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetLogSnapShot( 
            /* [in] */ BOOL on,
            /* [in] */ WORD level,
            /* [string][in] */ OLECHAR *snapShotPath,
            /* [in] */ BOOL resetTrace) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWsbTraceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWsbTrace * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWsbTrace * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWsbTrace * This);
        
        HRESULT ( STDMETHODCALLTYPE *StartTrace )( 
            IWsbTrace * This);
        
        HRESULT ( STDMETHODCALLTYPE *StopTrace )( 
            IWsbTrace * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetTraceOn )( 
            IWsbTrace * This,
            /* [in] */ LONGLONG traceElement);
        
        HRESULT ( STDMETHODCALLTYPE *SetTraceOff )( 
            IWsbTrace * This,
            /* [in] */ LONGLONG traceElement);
        
        HRESULT ( STDMETHODCALLTYPE *GetTraceSettings )( 
            IWsbTrace * This,
            /* [out] */ LONGLONG *pTraceElements);
        
        HRESULT ( STDMETHODCALLTYPE *GetTraceSetting )( 
            IWsbTrace * This,
            /* [in] */ LONGLONG traceElement,
            /* [out] */ BOOL *pOn);
        
        HRESULT ( STDMETHODCALLTYPE *DirectOutput )( 
            IWsbTrace * This,
            /* [in] */ ULONG output);
        
        HRESULT ( STDMETHODCALLTYPE *SetOutputFormat )( 
            IWsbTrace * This,
            /* [in] */ BOOL timeStamp,
            /* [in] */ BOOL traceCount,
            /* [in] */ BOOL traceThreadId);
        
        HRESULT ( STDMETHODCALLTYPE *GetOutputFormat )( 
            IWsbTrace * This,
            /* [out] */ BOOL *pTimeStamp,
            /* [out] */ BOOL *pTraceCount,
            /* [out] */ BOOL *pTraceThreadId);
        
        HRESULT ( STDMETHODCALLTYPE *SetTraceFileControls )( 
            IWsbTrace * This,
            /* [string][in] */ OLECHAR *traceFileName,
            /* [in] */ BOOL commitEachEntry,
            /* [in] */ LONGLONG maxTraceFileSize,
            /* [string][in] */ OLECHAR *traceFileCopyName);
        
        HRESULT ( STDMETHODCALLTYPE *GetTraceFileControls )( 
            IWsbTrace * This,
            /* [string][out] */ OLECHAR **traceFileName,
            /* [out] */ BOOL *pCommitEachEntry,
            /* [out] */ LONGLONG *pMaxTraceFileSize,
            /* [string][out] */ OLECHAR **traceFileCopyName);
        
        HRESULT ( STDMETHODCALLTYPE *SetTraceEntryExit )( 
            IWsbTrace * This,
            /* [in] */ BOOL traceEntryExit);
        
        HRESULT ( STDMETHODCALLTYPE *GetTraceEntryExit )( 
            IWsbTrace * This,
            /* [out] */ BOOL *pTraceEntryExit);
        
        HRESULT ( STDMETHODCALLTYPE *SetLogLevel )( 
            IWsbTrace * This,
            /* [in] */ WORD traceError);
        
        HRESULT ( STDMETHODCALLTYPE *GetLogLevel )( 
            IWsbTrace * This,
            /* [out] */ WORD *pTraceError);
        
        HRESULT ( STDMETHODCALLTYPE *Print )( 
            IWsbTrace * This,
            /* [string][in] */ OLECHAR *traceString);
        
        HRESULT ( STDMETHODCALLTYPE *GetRegistryEntry )( 
            IWsbTrace * This,
            /* [string][out] */ OLECHAR **pRegistryEntry);
        
        HRESULT ( STDMETHODCALLTYPE *SetRegistryEntry )( 
            IWsbTrace * This,
            /* [string][in] */ OLECHAR *pRegistryEntry);
        
        HRESULT ( STDMETHODCALLTYPE *LoadFromRegistry )( 
            IWsbTrace * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetTraceSettings )( 
            IWsbTrace * This,
            /* [in] */ LONGLONG traceElements);
        
        HRESULT ( STDMETHODCALLTYPE *GetLogSnapShot )( 
            IWsbTrace * This,
            /* [out] */ BOOL *pOn,
            /* [out] */ WORD *pLevel,
            /* [string][out] */ OLECHAR **pSnapShotPath,
            /* [out] */ BOOL *pResetTrace);
        
        HRESULT ( STDMETHODCALLTYPE *SetLogSnapShot )( 
            IWsbTrace * This,
            /* [in] */ BOOL on,
            /* [in] */ WORD level,
            /* [string][in] */ OLECHAR *snapShotPath,
            /* [in] */ BOOL resetTrace);
        
        END_INTERFACE
    } IWsbTraceVtbl;

    interface IWsbTrace
    {
        CONST_VTBL struct IWsbTraceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWsbTrace_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWsbTrace_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWsbTrace_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWsbTrace_StartTrace(This)	\
    (This)->lpVtbl -> StartTrace(This)

#define IWsbTrace_StopTrace(This)	\
    (This)->lpVtbl -> StopTrace(This)

#define IWsbTrace_SetTraceOn(This,traceElement)	\
    (This)->lpVtbl -> SetTraceOn(This,traceElement)

#define IWsbTrace_SetTraceOff(This,traceElement)	\
    (This)->lpVtbl -> SetTraceOff(This,traceElement)

#define IWsbTrace_GetTraceSettings(This,pTraceElements)	\
    (This)->lpVtbl -> GetTraceSettings(This,pTraceElements)

#define IWsbTrace_GetTraceSetting(This,traceElement,pOn)	\
    (This)->lpVtbl -> GetTraceSetting(This,traceElement,pOn)

#define IWsbTrace_DirectOutput(This,output)	\
    (This)->lpVtbl -> DirectOutput(This,output)

#define IWsbTrace_SetOutputFormat(This,timeStamp,traceCount,traceThreadId)	\
    (This)->lpVtbl -> SetOutputFormat(This,timeStamp,traceCount,traceThreadId)

#define IWsbTrace_GetOutputFormat(This,pTimeStamp,pTraceCount,pTraceThreadId)	\
    (This)->lpVtbl -> GetOutputFormat(This,pTimeStamp,pTraceCount,pTraceThreadId)

#define IWsbTrace_SetTraceFileControls(This,traceFileName,commitEachEntry,maxTraceFileSize,traceFileCopyName)	\
    (This)->lpVtbl -> SetTraceFileControls(This,traceFileName,commitEachEntry,maxTraceFileSize,traceFileCopyName)

#define IWsbTrace_GetTraceFileControls(This,traceFileName,pCommitEachEntry,pMaxTraceFileSize,traceFileCopyName)	\
    (This)->lpVtbl -> GetTraceFileControls(This,traceFileName,pCommitEachEntry,pMaxTraceFileSize,traceFileCopyName)

#define IWsbTrace_SetTraceEntryExit(This,traceEntryExit)	\
    (This)->lpVtbl -> SetTraceEntryExit(This,traceEntryExit)

#define IWsbTrace_GetTraceEntryExit(This,pTraceEntryExit)	\
    (This)->lpVtbl -> GetTraceEntryExit(This,pTraceEntryExit)

#define IWsbTrace_SetLogLevel(This,traceError)	\
    (This)->lpVtbl -> SetLogLevel(This,traceError)

#define IWsbTrace_GetLogLevel(This,pTraceError)	\
    (This)->lpVtbl -> GetLogLevel(This,pTraceError)

#define IWsbTrace_Print(This,traceString)	\
    (This)->lpVtbl -> Print(This,traceString)

#define IWsbTrace_GetRegistryEntry(This,pRegistryEntry)	\
    (This)->lpVtbl -> GetRegistryEntry(This,pRegistryEntry)

#define IWsbTrace_SetRegistryEntry(This,pRegistryEntry)	\
    (This)->lpVtbl -> SetRegistryEntry(This,pRegistryEntry)

#define IWsbTrace_LoadFromRegistry(This)	\
    (This)->lpVtbl -> LoadFromRegistry(This)

#define IWsbTrace_SetTraceSettings(This,traceElements)	\
    (This)->lpVtbl -> SetTraceSettings(This,traceElements)

#define IWsbTrace_GetLogSnapShot(This,pOn,pLevel,pSnapShotPath,pResetTrace)	\
    (This)->lpVtbl -> GetLogSnapShot(This,pOn,pLevel,pSnapShotPath,pResetTrace)

#define IWsbTrace_SetLogSnapShot(This,on,level,snapShotPath,resetTrace)	\
    (This)->lpVtbl -> SetLogSnapShot(This,on,level,snapShotPath,resetTrace)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IWsbTrace_StartTrace_Proxy( 
    IWsbTrace * This);


void __RPC_STUB IWsbTrace_StartTrace_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbTrace_StopTrace_Proxy( 
    IWsbTrace * This);


void __RPC_STUB IWsbTrace_StopTrace_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbTrace_SetTraceOn_Proxy( 
    IWsbTrace * This,
    /* [in] */ LONGLONG traceElement);


void __RPC_STUB IWsbTrace_SetTraceOn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbTrace_SetTraceOff_Proxy( 
    IWsbTrace * This,
    /* [in] */ LONGLONG traceElement);


void __RPC_STUB IWsbTrace_SetTraceOff_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbTrace_GetTraceSettings_Proxy( 
    IWsbTrace * This,
    /* [out] */ LONGLONG *pTraceElements);


void __RPC_STUB IWsbTrace_GetTraceSettings_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbTrace_GetTraceSetting_Proxy( 
    IWsbTrace * This,
    /* [in] */ LONGLONG traceElement,
    /* [out] */ BOOL *pOn);


void __RPC_STUB IWsbTrace_GetTraceSetting_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbTrace_DirectOutput_Proxy( 
    IWsbTrace * This,
    /* [in] */ ULONG output);


void __RPC_STUB IWsbTrace_DirectOutput_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbTrace_SetOutputFormat_Proxy( 
    IWsbTrace * This,
    /* [in] */ BOOL timeStamp,
    /* [in] */ BOOL traceCount,
    /* [in] */ BOOL traceThreadId);


void __RPC_STUB IWsbTrace_SetOutputFormat_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbTrace_GetOutputFormat_Proxy( 
    IWsbTrace * This,
    /* [out] */ BOOL *pTimeStamp,
    /* [out] */ BOOL *pTraceCount,
    /* [out] */ BOOL *pTraceThreadId);


void __RPC_STUB IWsbTrace_GetOutputFormat_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbTrace_SetTraceFileControls_Proxy( 
    IWsbTrace * This,
    /* [string][in] */ OLECHAR *traceFileName,
    /* [in] */ BOOL commitEachEntry,
    /* [in] */ LONGLONG maxTraceFileSize,
    /* [string][in] */ OLECHAR *traceFileCopyName);


void __RPC_STUB IWsbTrace_SetTraceFileControls_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbTrace_GetTraceFileControls_Proxy( 
    IWsbTrace * This,
    /* [string][out] */ OLECHAR **traceFileName,
    /* [out] */ BOOL *pCommitEachEntry,
    /* [out] */ LONGLONG *pMaxTraceFileSize,
    /* [string][out] */ OLECHAR **traceFileCopyName);


void __RPC_STUB IWsbTrace_GetTraceFileControls_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbTrace_SetTraceEntryExit_Proxy( 
    IWsbTrace * This,
    /* [in] */ BOOL traceEntryExit);


void __RPC_STUB IWsbTrace_SetTraceEntryExit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbTrace_GetTraceEntryExit_Proxy( 
    IWsbTrace * This,
    /* [out] */ BOOL *pTraceEntryExit);


void __RPC_STUB IWsbTrace_GetTraceEntryExit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbTrace_SetLogLevel_Proxy( 
    IWsbTrace * This,
    /* [in] */ WORD traceError);


void __RPC_STUB IWsbTrace_SetLogLevel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbTrace_GetLogLevel_Proxy( 
    IWsbTrace * This,
    /* [out] */ WORD *pTraceError);


void __RPC_STUB IWsbTrace_GetLogLevel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbTrace_Print_Proxy( 
    IWsbTrace * This,
    /* [string][in] */ OLECHAR *traceString);


void __RPC_STUB IWsbTrace_Print_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbTrace_GetRegistryEntry_Proxy( 
    IWsbTrace * This,
    /* [string][out] */ OLECHAR **pRegistryEntry);


void __RPC_STUB IWsbTrace_GetRegistryEntry_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbTrace_SetRegistryEntry_Proxy( 
    IWsbTrace * This,
    /* [string][in] */ OLECHAR *pRegistryEntry);


void __RPC_STUB IWsbTrace_SetRegistryEntry_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbTrace_LoadFromRegistry_Proxy( 
    IWsbTrace * This);


void __RPC_STUB IWsbTrace_LoadFromRegistry_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbTrace_SetTraceSettings_Proxy( 
    IWsbTrace * This,
    /* [in] */ LONGLONG traceElements);


void __RPC_STUB IWsbTrace_SetTraceSettings_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbTrace_GetLogSnapShot_Proxy( 
    IWsbTrace * This,
    /* [out] */ BOOL *pOn,
    /* [out] */ WORD *pLevel,
    /* [string][out] */ OLECHAR **pSnapShotPath,
    /* [out] */ BOOL *pResetTrace);


void __RPC_STUB IWsbTrace_GetLogSnapShot_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbTrace_SetLogSnapShot_Proxy( 
    IWsbTrace * This,
    /* [in] */ BOOL on,
    /* [in] */ WORD level,
    /* [string][in] */ OLECHAR *snapShotPath,
    /* [in] */ BOOL resetTrace);


void __RPC_STUB IWsbTrace_SetLogSnapShot_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IWsbTrace_INTERFACE_DEFINED__ */


#ifndef __IWsbDbSysPriv_INTERFACE_DEFINED__
#define __IWsbDbSysPriv_INTERFACE_DEFINED__

/* interface IWsbDbSysPriv */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_IWsbDbSysPriv;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8A2612A9-2466-470E-AD46-059318CE8C4E")
    IWsbDbSysPriv : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE IncrementChangeCount( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DbAttachedAdd( 
            /* [string][in] */ OLECHAR *name,
            /* [in] */ BOOL attach) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DbAttachedEmptySlot( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DbAttachedInit( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DbAttachedRemove( 
            /* [string][in] */ OLECHAR *name) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWsbDbSysPrivVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWsbDbSysPriv * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWsbDbSysPriv * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWsbDbSysPriv * This);
        
        HRESULT ( STDMETHODCALLTYPE *IncrementChangeCount )( 
            IWsbDbSysPriv * This);
        
        HRESULT ( STDMETHODCALLTYPE *DbAttachedAdd )( 
            IWsbDbSysPriv * This,
            /* [string][in] */ OLECHAR *name,
            /* [in] */ BOOL attach);
        
        HRESULT ( STDMETHODCALLTYPE *DbAttachedEmptySlot )( 
            IWsbDbSysPriv * This);
        
        HRESULT ( STDMETHODCALLTYPE *DbAttachedInit )( 
            IWsbDbSysPriv * This);
        
        HRESULT ( STDMETHODCALLTYPE *DbAttachedRemove )( 
            IWsbDbSysPriv * This,
            /* [string][in] */ OLECHAR *name);
        
        END_INTERFACE
    } IWsbDbSysPrivVtbl;

    interface IWsbDbSysPriv
    {
        CONST_VTBL struct IWsbDbSysPrivVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWsbDbSysPriv_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWsbDbSysPriv_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWsbDbSysPriv_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWsbDbSysPriv_IncrementChangeCount(This)	\
    (This)->lpVtbl -> IncrementChangeCount(This)

#define IWsbDbSysPriv_DbAttachedAdd(This,name,attach)	\
    (This)->lpVtbl -> DbAttachedAdd(This,name,attach)

#define IWsbDbSysPriv_DbAttachedEmptySlot(This)	\
    (This)->lpVtbl -> DbAttachedEmptySlot(This)

#define IWsbDbSysPriv_DbAttachedInit(This)	\
    (This)->lpVtbl -> DbAttachedInit(This)

#define IWsbDbSysPriv_DbAttachedRemove(This,name)	\
    (This)->lpVtbl -> DbAttachedRemove(This,name)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IWsbDbSysPriv_IncrementChangeCount_Proxy( 
    IWsbDbSysPriv * This);


void __RPC_STUB IWsbDbSysPriv_IncrementChangeCount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDbSysPriv_DbAttachedAdd_Proxy( 
    IWsbDbSysPriv * This,
    /* [string][in] */ OLECHAR *name,
    /* [in] */ BOOL attach);


void __RPC_STUB IWsbDbSysPriv_DbAttachedAdd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDbSysPriv_DbAttachedEmptySlot_Proxy( 
    IWsbDbSysPriv * This);


void __RPC_STUB IWsbDbSysPriv_DbAttachedEmptySlot_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDbSysPriv_DbAttachedInit_Proxy( 
    IWsbDbSysPriv * This);


void __RPC_STUB IWsbDbSysPriv_DbAttachedInit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDbSysPriv_DbAttachedRemove_Proxy( 
    IWsbDbSysPriv * This,
    /* [string][in] */ OLECHAR *name);


void __RPC_STUB IWsbDbSysPriv_DbAttachedRemove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IWsbDbSysPriv_INTERFACE_DEFINED__ */


#ifndef __IWsbDbPriv_INTERFACE_DEFINED__
#define __IWsbDbPriv_INTERFACE_DEFINED__

/* interface IWsbDbPriv */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_IWsbDbPriv;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5FD6B1D1-6A43-11D0-9905-00A0C9058BF6")
    IWsbDbPriv : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetJetIds( 
            /* [in] */ ULONG_PTR SessionID,
            /* [in] */ ULONG RecType,
            /* [out] */ ULONG_PTR *pTableId,
            /* [out] */ ULONG *pDataColId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetJetIndexInfo( 
            /* [in] */ ULONG_PTR SessionId,
            /* [in] */ ULONG RecType,
            /* [in] */ ULONG KeyType,
            /* [out] */ ULONG *pColId,
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNewSQN( 
            /* [in] */ ULONG RecType,
            /* [out] */ ULONG *pSeqNum) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetKeyInfo( 
            /* [in] */ ULONG RecType,
            /* [in] */ USHORT nKeys,
            /* [size_is][out] */ COM_IDB_KEY_INFO *pKeyInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecInfo( 
            /* [in] */ ULONG RecType,
            /* [out] */ COM_IDB_REC_INFO *pRecInfo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Lock( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Unlock( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWsbDbPrivVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWsbDbPriv * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWsbDbPriv * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWsbDbPriv * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetJetIds )( 
            IWsbDbPriv * This,
            /* [in] */ ULONG_PTR SessionID,
            /* [in] */ ULONG RecType,
            /* [out] */ ULONG_PTR *pTableId,
            /* [out] */ ULONG *pDataColId);
        
        HRESULT ( STDMETHODCALLTYPE *GetJetIndexInfo )( 
            IWsbDbPriv * This,
            /* [in] */ ULONG_PTR SessionId,
            /* [in] */ ULONG RecType,
            /* [in] */ ULONG KeyType,
            /* [out] */ ULONG *pColId,
            /* [string][out][in] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetNewSQN )( 
            IWsbDbPriv * This,
            /* [in] */ ULONG RecType,
            /* [out] */ ULONG *pSeqNum);
        
        HRESULT ( STDMETHODCALLTYPE *GetKeyInfo )( 
            IWsbDbPriv * This,
            /* [in] */ ULONG RecType,
            /* [in] */ USHORT nKeys,
            /* [size_is][out] */ COM_IDB_KEY_INFO *pKeyInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetRecInfo )( 
            IWsbDbPriv * This,
            /* [in] */ ULONG RecType,
            /* [out] */ COM_IDB_REC_INFO *pRecInfo);
        
        HRESULT ( STDMETHODCALLTYPE *Lock )( 
            IWsbDbPriv * This);
        
        HRESULT ( STDMETHODCALLTYPE *Unlock )( 
            IWsbDbPriv * This);
        
        END_INTERFACE
    } IWsbDbPrivVtbl;

    interface IWsbDbPriv
    {
        CONST_VTBL struct IWsbDbPrivVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWsbDbPriv_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWsbDbPriv_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWsbDbPriv_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWsbDbPriv_GetJetIds(This,SessionID,RecType,pTableId,pDataColId)	\
    (This)->lpVtbl -> GetJetIds(This,SessionID,RecType,pTableId,pDataColId)

#define IWsbDbPriv_GetJetIndexInfo(This,SessionId,RecType,KeyType,pColId,pName,bufferSize)	\
    (This)->lpVtbl -> GetJetIndexInfo(This,SessionId,RecType,KeyType,pColId,pName,bufferSize)

#define IWsbDbPriv_GetNewSQN(This,RecType,pSeqNum)	\
    (This)->lpVtbl -> GetNewSQN(This,RecType,pSeqNum)

#define IWsbDbPriv_GetKeyInfo(This,RecType,nKeys,pKeyInfo)	\
    (This)->lpVtbl -> GetKeyInfo(This,RecType,nKeys,pKeyInfo)

#define IWsbDbPriv_GetRecInfo(This,RecType,pRecInfo)	\
    (This)->lpVtbl -> GetRecInfo(This,RecType,pRecInfo)

#define IWsbDbPriv_Lock(This)	\
    (This)->lpVtbl -> Lock(This)

#define IWsbDbPriv_Unlock(This)	\
    (This)->lpVtbl -> Unlock(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IWsbDbPriv_GetJetIds_Proxy( 
    IWsbDbPriv * This,
    /* [in] */ ULONG_PTR SessionID,
    /* [in] */ ULONG RecType,
    /* [out] */ ULONG_PTR *pTableId,
    /* [out] */ ULONG *pDataColId);


void __RPC_STUB IWsbDbPriv_GetJetIds_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDbPriv_GetJetIndexInfo_Proxy( 
    IWsbDbPriv * This,
    /* [in] */ ULONG_PTR SessionId,
    /* [in] */ ULONG RecType,
    /* [in] */ ULONG KeyType,
    /* [out] */ ULONG *pColId,
    /* [string][out][in] */ OLECHAR **pName,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IWsbDbPriv_GetJetIndexInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDbPriv_GetNewSQN_Proxy( 
    IWsbDbPriv * This,
    /* [in] */ ULONG RecType,
    /* [out] */ ULONG *pSeqNum);


void __RPC_STUB IWsbDbPriv_GetNewSQN_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDbPriv_GetKeyInfo_Proxy( 
    IWsbDbPriv * This,
    /* [in] */ ULONG RecType,
    /* [in] */ USHORT nKeys,
    /* [size_is][out] */ COM_IDB_KEY_INFO *pKeyInfo);


void __RPC_STUB IWsbDbPriv_GetKeyInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDbPriv_GetRecInfo_Proxy( 
    IWsbDbPriv * This,
    /* [in] */ ULONG RecType,
    /* [out] */ COM_IDB_REC_INFO *pRecInfo);


void __RPC_STUB IWsbDbPriv_GetRecInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDbPriv_Lock_Proxy( 
    IWsbDbPriv * This);


void __RPC_STUB IWsbDbPriv_Lock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDbPriv_Unlock_Proxy( 
    IWsbDbPriv * This);


void __RPC_STUB IWsbDbPriv_Unlock_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IWsbDbPriv_INTERFACE_DEFINED__ */


#ifndef __IWsbDbSessionPriv_INTERFACE_DEFINED__
#define __IWsbDbSessionPriv_INTERFACE_DEFINED__

/* interface IWsbDbSessionPriv */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_IWsbDbSessionPriv;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C8DA1798-A48C-458C-B597-F497AB046A38")
    IWsbDbSessionPriv : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Init( 
            /* [in] */ ULONG_PTR *pInstance) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetJetId( 
            /* [out] */ ULONG_PTR *pSessionId) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWsbDbSessionPrivVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWsbDbSessionPriv * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWsbDbSessionPriv * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWsbDbSessionPriv * This);
        
        HRESULT ( STDMETHODCALLTYPE *Init )( 
            IWsbDbSessionPriv * This,
            /* [in] */ ULONG_PTR *pInstance);
        
        HRESULT ( STDMETHODCALLTYPE *GetJetId )( 
            IWsbDbSessionPriv * This,
            /* [out] */ ULONG_PTR *pSessionId);
        
        END_INTERFACE
    } IWsbDbSessionPrivVtbl;

    interface IWsbDbSessionPriv
    {
        CONST_VTBL struct IWsbDbSessionPrivVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWsbDbSessionPriv_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWsbDbSessionPriv_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWsbDbSessionPriv_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWsbDbSessionPriv_Init(This,pInstance)	\
    (This)->lpVtbl -> Init(This,pInstance)

#define IWsbDbSessionPriv_GetJetId(This,pSessionId)	\
    (This)->lpVtbl -> GetJetId(This,pSessionId)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IWsbDbSessionPriv_Init_Proxy( 
    IWsbDbSessionPriv * This,
    /* [in] */ ULONG_PTR *pInstance);


void __RPC_STUB IWsbDbSessionPriv_Init_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDbSessionPriv_GetJetId_Proxy( 
    IWsbDbSessionPriv * This,
    /* [out] */ ULONG_PTR *pSessionId);


void __RPC_STUB IWsbDbSessionPriv_GetJetId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IWsbDbSessionPriv_INTERFACE_DEFINED__ */


#ifndef __IWsbDbKeyPriv_INTERFACE_DEFINED__
#define __IWsbDbKeyPriv_INTERFACE_DEFINED__

/* interface IWsbDbKeyPriv */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_IWsbDbKeyPriv;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5FD6B1D4-6A43-11D0-9905-00A0C9058BF6")
    IWsbDbKeyPriv : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetBytes( 
            /* [out] */ UCHAR **ppBytes,
            /* [out] */ ULONG *pSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetType( 
            /* [in] */ ULONG type) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWsbDbKeyPrivVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWsbDbKeyPriv * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWsbDbKeyPriv * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWsbDbKeyPriv * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetBytes )( 
            IWsbDbKeyPriv * This,
            /* [out] */ UCHAR **ppBytes,
            /* [out] */ ULONG *pSize);
        
        HRESULT ( STDMETHODCALLTYPE *SetType )( 
            IWsbDbKeyPriv * This,
            /* [in] */ ULONG type);
        
        END_INTERFACE
    } IWsbDbKeyPrivVtbl;

    interface IWsbDbKeyPriv
    {
        CONST_VTBL struct IWsbDbKeyPrivVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWsbDbKeyPriv_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWsbDbKeyPriv_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWsbDbKeyPriv_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWsbDbKeyPriv_GetBytes(This,ppBytes,pSize)	\
    (This)->lpVtbl -> GetBytes(This,ppBytes,pSize)

#define IWsbDbKeyPriv_SetType(This,type)	\
    (This)->lpVtbl -> SetType(This,type)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IWsbDbKeyPriv_GetBytes_Proxy( 
    IWsbDbKeyPriv * This,
    /* [out] */ UCHAR **ppBytes,
    /* [out] */ ULONG *pSize);


void __RPC_STUB IWsbDbKeyPriv_GetBytes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDbKeyPriv_SetType_Proxy( 
    IWsbDbKeyPriv * This,
    /* [in] */ ULONG type);


void __RPC_STUB IWsbDbKeyPriv_SetType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IWsbDbKeyPriv_INTERFACE_DEFINED__ */


#ifndef __IWsbDbEntityPriv_INTERFACE_DEFINED__
#define __IWsbDbEntityPriv_INTERFACE_DEFINED__

/* interface IWsbDbEntityPriv */
/* [unique][helpstring][uuid][local][object] */ 


EXTERN_C const IID IID_IWsbDbEntityPriv;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F16476FD-BF20-442A-84EB-5CEA9462E81D")
    IWsbDbEntityPriv : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Copy( 
            /* [in] */ IWsbDbEntity *pEntity) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CopyValues( 
            /* [in] */ ULONG flags,
            /* [in] */ IWsbDbEntity *pEntity) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCurKey( 
            /* [out] */ IWsbDbKey **ppKey) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetKey( 
            /* [in] */ ULONG KeyType,
            /* [out] */ IWsbDbKey **ppKey) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetValue( 
            /* [in] */ ULONG flag,
            /* [out] */ ULONG *pValue) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Init( 
            /* [in] */ IWsbDb *pDb,
            /* [in] */ IWsbDbSys *pDbSys,
            /* [in] */ ULONG RecType,
            /* [in] */ ULONG_PTR SessionId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetValue( 
            /* [in] */ ULONG flag,
            /* [in] */ ULONG value) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWsbDbEntityPrivVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWsbDbEntityPriv * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWsbDbEntityPriv * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWsbDbEntityPriv * This);
        
        HRESULT ( STDMETHODCALLTYPE *Copy )( 
            IWsbDbEntityPriv * This,
            /* [in] */ IWsbDbEntity *pEntity);
        
        HRESULT ( STDMETHODCALLTYPE *CopyValues )( 
            IWsbDbEntityPriv * This,
            /* [in] */ ULONG flags,
            /* [in] */ IWsbDbEntity *pEntity);
        
        HRESULT ( STDMETHODCALLTYPE *GetCurKey )( 
            IWsbDbEntityPriv * This,
            /* [out] */ IWsbDbKey **ppKey);
        
        HRESULT ( STDMETHODCALLTYPE *GetKey )( 
            IWsbDbEntityPriv * This,
            /* [in] */ ULONG KeyType,
            /* [out] */ IWsbDbKey **ppKey);
        
        HRESULT ( STDMETHODCALLTYPE *GetValue )( 
            IWsbDbEntityPriv * This,
            /* [in] */ ULONG flag,
            /* [out] */ ULONG *pValue);
        
        HRESULT ( STDMETHODCALLTYPE *Init )( 
            IWsbDbEntityPriv * This,
            /* [in] */ IWsbDb *pDb,
            /* [in] */ IWsbDbSys *pDbSys,
            /* [in] */ ULONG RecType,
            /* [in] */ ULONG_PTR SessionId);
        
        HRESULT ( STDMETHODCALLTYPE *SetValue )( 
            IWsbDbEntityPriv * This,
            /* [in] */ ULONG flag,
            /* [in] */ ULONG value);
        
        END_INTERFACE
    } IWsbDbEntityPrivVtbl;

    interface IWsbDbEntityPriv
    {
        CONST_VTBL struct IWsbDbEntityPrivVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWsbDbEntityPriv_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWsbDbEntityPriv_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWsbDbEntityPriv_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWsbDbEntityPriv_Copy(This,pEntity)	\
    (This)->lpVtbl -> Copy(This,pEntity)

#define IWsbDbEntityPriv_CopyValues(This,flags,pEntity)	\
    (This)->lpVtbl -> CopyValues(This,flags,pEntity)

#define IWsbDbEntityPriv_GetCurKey(This,ppKey)	\
    (This)->lpVtbl -> GetCurKey(This,ppKey)

#define IWsbDbEntityPriv_GetKey(This,KeyType,ppKey)	\
    (This)->lpVtbl -> GetKey(This,KeyType,ppKey)

#define IWsbDbEntityPriv_GetValue(This,flag,pValue)	\
    (This)->lpVtbl -> GetValue(This,flag,pValue)

#define IWsbDbEntityPriv_Init(This,pDb,pDbSys,RecType,SessionId)	\
    (This)->lpVtbl -> Init(This,pDb,pDbSys,RecType,SessionId)

#define IWsbDbEntityPriv_SetValue(This,flag,value)	\
    (This)->lpVtbl -> SetValue(This,flag,value)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IWsbDbEntityPriv_Copy_Proxy( 
    IWsbDbEntityPriv * This,
    /* [in] */ IWsbDbEntity *pEntity);


void __RPC_STUB IWsbDbEntityPriv_Copy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDbEntityPriv_CopyValues_Proxy( 
    IWsbDbEntityPriv * This,
    /* [in] */ ULONG flags,
    /* [in] */ IWsbDbEntity *pEntity);


void __RPC_STUB IWsbDbEntityPriv_CopyValues_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDbEntityPriv_GetCurKey_Proxy( 
    IWsbDbEntityPriv * This,
    /* [out] */ IWsbDbKey **ppKey);


void __RPC_STUB IWsbDbEntityPriv_GetCurKey_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDbEntityPriv_GetKey_Proxy( 
    IWsbDbEntityPriv * This,
    /* [in] */ ULONG KeyType,
    /* [out] */ IWsbDbKey **ppKey);


void __RPC_STUB IWsbDbEntityPriv_GetKey_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDbEntityPriv_GetValue_Proxy( 
    IWsbDbEntityPriv * This,
    /* [in] */ ULONG flag,
    /* [out] */ ULONG *pValue);


void __RPC_STUB IWsbDbEntityPriv_GetValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDbEntityPriv_Init_Proxy( 
    IWsbDbEntityPriv * This,
    /* [in] */ IWsbDb *pDb,
    /* [in] */ IWsbDbSys *pDbSys,
    /* [in] */ ULONG RecType,
    /* [in] */ ULONG_PTR SessionId);


void __RPC_STUB IWsbDbEntityPriv_Init_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbDbEntityPriv_SetValue_Proxy( 
    IWsbDbEntityPriv * This,
    /* [in] */ ULONG flag,
    /* [in] */ ULONG value);


void __RPC_STUB IWsbDbEntityPriv_SetValue_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IWsbDbEntityPriv_INTERFACE_DEFINED__ */


#ifndef __IWsbServer_INTERFACE_DEFINED__
#define __IWsbServer_INTERFACE_DEFINED__

/* interface IWsbServer */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IWsbServer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("58A4F966-55BE-4D62-892E-43A9978BF4C2")
    IWsbServer : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetDbPathAndName( 
            /* [string][out] */ OLECHAR **pDbPathAndName,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetId( 
            /* [out] */ GUID *pId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRegistryName( 
            /* [string][out] */ OLECHAR **pRegistryName,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetBuildVersion( 
            /* [out] */ ULONG *pBuildVersion) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNtProductVersion( 
            /* [string][out] */ OLECHAR **pNtProductVersion,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNtProductBuild( 
            /* [out] */ ULONG *pNtProductBuild) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDatabaseVersion( 
            /* [out] */ ULONG *pDatabaseVersion) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SaveAll( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetId( 
            /* [in] */ GUID id) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DestroyObject( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Unload( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CheckAccess( 
            /* [in] */ WSB_ACCESS_TYPE AccessType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetTrace( 
            /* [out] */ IWsbTrace **ppTrace) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetTrace( 
            /* [in] */ IWsbTrace *pTrace) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IWsbServerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IWsbServer * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IWsbServer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IWsbServer * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetDbPathAndName )( 
            IWsbServer * This,
            /* [string][out] */ OLECHAR **pDbPathAndName,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetId )( 
            IWsbServer * This,
            /* [out] */ GUID *pId);
        
        HRESULT ( STDMETHODCALLTYPE *GetRegistryName )( 
            IWsbServer * This,
            /* [string][out] */ OLECHAR **pRegistryName,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetBuildVersion )( 
            IWsbServer * This,
            /* [out] */ ULONG *pBuildVersion);
        
        HRESULT ( STDMETHODCALLTYPE *GetNtProductVersion )( 
            IWsbServer * This,
            /* [string][out] */ OLECHAR **pNtProductVersion,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetNtProductBuild )( 
            IWsbServer * This,
            /* [out] */ ULONG *pNtProductBuild);
        
        HRESULT ( STDMETHODCALLTYPE *GetDatabaseVersion )( 
            IWsbServer * This,
            /* [out] */ ULONG *pDatabaseVersion);
        
        HRESULT ( STDMETHODCALLTYPE *SaveAll )( 
            IWsbServer * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetId )( 
            IWsbServer * This,
            /* [in] */ GUID id);
        
        HRESULT ( STDMETHODCALLTYPE *DestroyObject )( 
            IWsbServer * This);
        
        HRESULT ( STDMETHODCALLTYPE *Unload )( 
            IWsbServer * This);
        
        HRESULT ( STDMETHODCALLTYPE *CheckAccess )( 
            IWsbServer * This,
            /* [in] */ WSB_ACCESS_TYPE AccessType);
        
        HRESULT ( STDMETHODCALLTYPE *GetTrace )( 
            IWsbServer * This,
            /* [out] */ IWsbTrace **ppTrace);
        
        HRESULT ( STDMETHODCALLTYPE *SetTrace )( 
            IWsbServer * This,
            /* [in] */ IWsbTrace *pTrace);
        
        END_INTERFACE
    } IWsbServerVtbl;

    interface IWsbServer
    {
        CONST_VTBL struct IWsbServerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IWsbServer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IWsbServer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IWsbServer_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IWsbServer_GetDbPathAndName(This,pDbPathAndName,bufferSize)	\
    (This)->lpVtbl -> GetDbPathAndName(This,pDbPathAndName,bufferSize)

#define IWsbServer_GetId(This,pId)	\
    (This)->lpVtbl -> GetId(This,pId)

#define IWsbServer_GetRegistryName(This,pRegistryName,bufferSize)	\
    (This)->lpVtbl -> GetRegistryName(This,pRegistryName,bufferSize)

#define IWsbServer_GetBuildVersion(This,pBuildVersion)	\
    (This)->lpVtbl -> GetBuildVersion(This,pBuildVersion)

#define IWsbServer_GetNtProductVersion(This,pNtProductVersion,bufferSize)	\
    (This)->lpVtbl -> GetNtProductVersion(This,pNtProductVersion,bufferSize)

#define IWsbServer_GetNtProductBuild(This,pNtProductBuild)	\
    (This)->lpVtbl -> GetNtProductBuild(This,pNtProductBuild)

#define IWsbServer_GetDatabaseVersion(This,pDatabaseVersion)	\
    (This)->lpVtbl -> GetDatabaseVersion(This,pDatabaseVersion)

#define IWsbServer_SaveAll(This)	\
    (This)->lpVtbl -> SaveAll(This)

#define IWsbServer_SetId(This,id)	\
    (This)->lpVtbl -> SetId(This,id)

#define IWsbServer_DestroyObject(This)	\
    (This)->lpVtbl -> DestroyObject(This)

#define IWsbServer_Unload(This)	\
    (This)->lpVtbl -> Unload(This)

#define IWsbServer_CheckAccess(This,AccessType)	\
    (This)->lpVtbl -> CheckAccess(This,AccessType)

#define IWsbServer_GetTrace(This,ppTrace)	\
    (This)->lpVtbl -> GetTrace(This,ppTrace)

#define IWsbServer_SetTrace(This,pTrace)	\
    (This)->lpVtbl -> SetTrace(This,pTrace)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IWsbServer_GetDbPathAndName_Proxy( 
    IWsbServer * This,
    /* [string][out] */ OLECHAR **pDbPathAndName,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IWsbServer_GetDbPathAndName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbServer_GetId_Proxy( 
    IWsbServer * This,
    /* [out] */ GUID *pId);


void __RPC_STUB IWsbServer_GetId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbServer_GetRegistryName_Proxy( 
    IWsbServer * This,
    /* [string][out] */ OLECHAR **pRegistryName,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IWsbServer_GetRegistryName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbServer_GetBuildVersion_Proxy( 
    IWsbServer * This,
    /* [out] */ ULONG *pBuildVersion);


void __RPC_STUB IWsbServer_GetBuildVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbServer_GetNtProductVersion_Proxy( 
    IWsbServer * This,
    /* [string][out] */ OLECHAR **pNtProductVersion,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IWsbServer_GetNtProductVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbServer_GetNtProductBuild_Proxy( 
    IWsbServer * This,
    /* [out] */ ULONG *pNtProductBuild);


void __RPC_STUB IWsbServer_GetNtProductBuild_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbServer_GetDatabaseVersion_Proxy( 
    IWsbServer * This,
    /* [out] */ ULONG *pDatabaseVersion);


void __RPC_STUB IWsbServer_GetDatabaseVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbServer_SaveAll_Proxy( 
    IWsbServer * This);


void __RPC_STUB IWsbServer_SaveAll_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbServer_SetId_Proxy( 
    IWsbServer * This,
    /* [in] */ GUID id);


void __RPC_STUB IWsbServer_SetId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbServer_DestroyObject_Proxy( 
    IWsbServer * This);


void __RPC_STUB IWsbServer_DestroyObject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbServer_Unload_Proxy( 
    IWsbServer * This);


void __RPC_STUB IWsbServer_Unload_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbServer_CheckAccess_Proxy( 
    IWsbServer * This,
    /* [in] */ WSB_ACCESS_TYPE AccessType);


void __RPC_STUB IWsbServer_CheckAccess_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbServer_GetTrace_Proxy( 
    IWsbServer * This,
    /* [out] */ IWsbTrace **ppTrace);


void __RPC_STUB IWsbServer_GetTrace_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IWsbServer_SetTrace_Proxy( 
    IWsbServer * This,
    /* [in] */ IWsbTrace *pTrace);


void __RPC_STUB IWsbServer_SetTrace_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IWsbServer_INTERFACE_DEFINED__ */


#ifndef __IHsmSystemState_INTERFACE_DEFINED__
#define __IHsmSystemState_INTERFACE_DEFINED__

/* interface IHsmSystemState */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IHsmSystemState;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3F0DA041-69F1-11d2-AF82-00104B9A3758")
    IHsmSystemState : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE ChangeSysState( 
            /* [out][in] */ HSM_SYSTEM_STATE *pSysState) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHsmSystemStateVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHsmSystemState * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHsmSystemState * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHsmSystemState * This);
        
        HRESULT ( STDMETHODCALLTYPE *ChangeSysState )( 
            IHsmSystemState * This,
            /* [out][in] */ HSM_SYSTEM_STATE *pSysState);
        
        END_INTERFACE
    } IHsmSystemStateVtbl;

    interface IHsmSystemState
    {
        CONST_VTBL struct IHsmSystemStateVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHsmSystemState_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHsmSystemState_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHsmSystemState_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHsmSystemState_ChangeSysState(This,pSysState)	\
    (This)->lpVtbl -> ChangeSysState(This,pSysState)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IHsmSystemState_ChangeSysState_Proxy( 
    IHsmSystemState * This,
    /* [out][in] */ HSM_SYSTEM_STATE *pSysState);


void __RPC_STUB IHsmSystemState_ChangeSysState_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IHsmSystemState_INTERFACE_DEFINED__ */


#ifndef __IHsmEvent_INTERFACE_DEFINED__
#define __IHsmEvent_INTERFACE_DEFINED__

/* interface IHsmEvent */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IHsmEvent;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("621EFF31-B2E2-11d1-B9A6-00A0C9190447")
    IHsmEvent : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE OnStateChange( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHsmEventVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHsmEvent * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHsmEvent * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHsmEvent * This);
        
        HRESULT ( STDMETHODCALLTYPE *OnStateChange )( 
            IHsmEvent * This);
        
        END_INTERFACE
    } IHsmEventVtbl;

    interface IHsmEvent
    {
        CONST_VTBL struct IHsmEventVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHsmEvent_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHsmEvent_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHsmEvent_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHsmEvent_OnStateChange(This)	\
    (This)->lpVtbl -> OnStateChange(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IHsmEvent_OnStateChange_Proxy( 
    IHsmEvent * This);


void __RPC_STUB IHsmEvent_OnStateChange_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IHsmEvent_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


