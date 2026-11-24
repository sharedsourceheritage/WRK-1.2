

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for ivssccmanager3.idl:
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

#ifndef __ivssccmanager3_h__
#define __ivssccmanager3_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IVsSccManager3_FWD_DEFINED__
#define __IVsSccManager3_FWD_DEFINED__
typedef interface IVsSccManager3 IVsSccManager3;
#endif 	/* __IVsSccManager3_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "IVsSccProject2.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

/* interface __MIDL_itf_ivssccmanager3_0000 */
/* [local] */ 

#pragma once
#pragma once


extern RPC_IF_HANDLE __MIDL_itf_ivssccmanager3_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ivssccmanager3_0000_v0_0_s_ifspec;

#ifndef __IVsSccManager3_INTERFACE_DEFINED__
#define __IVsSccManager3_INTERFACE_DEFINED__

/* interface IVsSccManager3 */
/* [object][uuid] */ 


EXTERN_C const IID IID_IVsSccManager3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("53544C4D-A152-4757-868A-2A7D0F2E5580")
    IVsSccManager3 : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE TakeProjectOffline( 
            /* [in] */ IVsSccProject2 *pscp2Project,
            /* [in] */ LPCOLESTR pszOnlineProjectFilePath) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RegisterOfflineSccProject( 
            /* [in] */ IVsSccProject2 *pscp2Project,
            /* [in] */ LPCOLESTR pszOnlineProjectFilePath,
            /* [in] */ LPCOLESTR pszSccProjectName,
            /* [in] */ LPCOLESTR pszSccAuxPath,
            /* [in] */ LPCOLESTR pszSccLocalPath,
            /* [in] */ LPCOLESTR pszProvider) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BringProjectOnline( 
            /* [in] */ IVsSccProject2 *pscp2Project) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVsSccManager3Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVsSccManager3 * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVsSccManager3 * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVsSccManager3 * This);
        
        HRESULT ( STDMETHODCALLTYPE *TakeProjectOffline )( 
            IVsSccManager3 * This,
            /* [in] */ IVsSccProject2 *pscp2Project,
            /* [in] */ LPCOLESTR pszOnlineProjectFilePath);
        
        HRESULT ( STDMETHODCALLTYPE *RegisterOfflineSccProject )( 
            IVsSccManager3 * This,
            /* [in] */ IVsSccProject2 *pscp2Project,
            /* [in] */ LPCOLESTR pszOnlineProjectFilePath,
            /* [in] */ LPCOLESTR pszSccProjectName,
            /* [in] */ LPCOLESTR pszSccAuxPath,
            /* [in] */ LPCOLESTR pszSccLocalPath,
            /* [in] */ LPCOLESTR pszProvider);
        
        HRESULT ( STDMETHODCALLTYPE *BringProjectOnline )( 
            IVsSccManager3 * This,
            /* [in] */ IVsSccProject2 *pscp2Project);
        
        END_INTERFACE
    } IVsSccManager3Vtbl;

    interface IVsSccManager3
    {
        CONST_VTBL struct IVsSccManager3Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVsSccManager3_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVsSccManager3_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVsSccManager3_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVsSccManager3_TakeProjectOffline(This,pscp2Project,pszOnlineProjectFilePath)	\
    (This)->lpVtbl -> TakeProjectOffline(This,pscp2Project,pszOnlineProjectFilePath)

#define IVsSccManager3_RegisterOfflineSccProject(This,pscp2Project,pszOnlineProjectFilePath,pszSccProjectName,pszSccAuxPath,pszSccLocalPath,pszProvider)	\
    (This)->lpVtbl -> RegisterOfflineSccProject(This,pscp2Project,pszOnlineProjectFilePath,pszSccProjectName,pszSccAuxPath,pszSccLocalPath,pszProvider)

#define IVsSccManager3_BringProjectOnline(This,pscp2Project)	\
    (This)->lpVtbl -> BringProjectOnline(This,pscp2Project)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVsSccManager3_TakeProjectOffline_Proxy( 
    IVsSccManager3 * This,
    /* [in] */ IVsSccProject2 *pscp2Project,
    /* [in] */ LPCOLESTR pszOnlineProjectFilePath);


void __RPC_STUB IVsSccManager3_TakeProjectOffline_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSccManager3_RegisterOfflineSccProject_Proxy( 
    IVsSccManager3 * This,
    /* [in] */ IVsSccProject2 *pscp2Project,
    /* [in] */ LPCOLESTR pszOnlineProjectFilePath,
    /* [in] */ LPCOLESTR pszSccProjectName,
    /* [in] */ LPCOLESTR pszSccAuxPath,
    /* [in] */ LPCOLESTR pszSccLocalPath,
    /* [in] */ LPCOLESTR pszProvider);


void __RPC_STUB IVsSccManager3_RegisterOfflineSccProject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVsSccManager3_BringProjectOnline_Proxy( 
    IVsSccManager3 * This,
    /* [in] */ IVsSccProject2 *pscp2Project);


void __RPC_STUB IVsSccManager3_BringProjectOnline_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVsSccManager3_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


