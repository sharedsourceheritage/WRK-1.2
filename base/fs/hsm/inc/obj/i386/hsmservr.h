

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for hsmservr.idl:
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

#ifndef __hsmservr_h__
#define __hsmservr_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IHsmConnPoint_FWD_DEFINED__
#define __IHsmConnPoint_FWD_DEFINED__
typedef interface IHsmConnPoint IHsmConnPoint;
#endif 	/* __IHsmConnPoint_FWD_DEFINED__ */


#ifndef __HsmConnPoint_FWD_DEFINED__
#define __HsmConnPoint_FWD_DEFINED__

#ifdef __cplusplus
typedef class HsmConnPoint HsmConnPoint;
#else
typedef struct HsmConnPoint HsmConnPoint;
#endif /* __cplusplus */

#endif 	/* __HsmConnPoint_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "hsmeng.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

#ifndef __IHsmConnPoint_INTERFACE_DEFINED__
#define __IHsmConnPoint_INTERFACE_DEFINED__

/* interface IHsmConnPoint */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IHsmConnPoint;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ADCAF721-1D59-4134-B0D9-854C314C058F")
    IHsmConnPoint : public IUnknown
    {
    public:
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetEngineServer( 
            /* [out] */ IHsmServer **ppHsmServer) = 0;
        
        virtual /* [helpstring] */ HRESULT STDMETHODCALLTYPE GetFsaServer( 
            /* [out] */ IFsaServer **ppFsaServer) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHsmConnPointVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHsmConnPoint * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHsmConnPoint * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHsmConnPoint * This);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetEngineServer )( 
            IHsmConnPoint * This,
            /* [out] */ IHsmServer **ppHsmServer);
        
        /* [helpstring] */ HRESULT ( STDMETHODCALLTYPE *GetFsaServer )( 
            IHsmConnPoint * This,
            /* [out] */ IFsaServer **ppFsaServer);
        
        END_INTERFACE
    } IHsmConnPointVtbl;

    interface IHsmConnPoint
    {
        CONST_VTBL struct IHsmConnPointVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHsmConnPoint_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHsmConnPoint_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHsmConnPoint_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHsmConnPoint_GetEngineServer(This,ppHsmServer)	\
    (This)->lpVtbl -> GetEngineServer(This,ppHsmServer)

#define IHsmConnPoint_GetFsaServer(This,ppFsaServer)	\
    (This)->lpVtbl -> GetFsaServer(This,ppFsaServer)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring] */ HRESULT STDMETHODCALLTYPE IHsmConnPoint_GetEngineServer_Proxy( 
    IHsmConnPoint * This,
    /* [out] */ IHsmServer **ppHsmServer);


void __RPC_STUB IHsmConnPoint_GetEngineServer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring] */ HRESULT STDMETHODCALLTYPE IHsmConnPoint_GetFsaServer_Proxy( 
    IHsmConnPoint * This,
    /* [out] */ IFsaServer **ppFsaServer);


void __RPC_STUB IHsmConnPoint_GetFsaServer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IHsmConnPoint_INTERFACE_DEFINED__ */



#ifndef __HSMSERVRLib_LIBRARY_DEFINED__
#define __HSMSERVRLib_LIBRARY_DEFINED__

/* library HSMSERVRLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_HSMSERVRLib;

EXTERN_C const CLSID CLSID_HsmConnPoint;

#ifdef __cplusplus

class DECLSPEC_UUID("F9F79FB4-10B7-47BB-A6C5-03FD6736D82F")
HsmConnPoint;
#endif
#endif /* __HSMSERVRLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


