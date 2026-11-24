

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for blkdrv.idl:
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

#ifndef __blkdrv_h__
#define __blkdrv_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IBlockedDrivers_FWD_DEFINED__
#define __IBlockedDrivers_FWD_DEFINED__
typedef interface IBlockedDrivers IBlockedDrivers;
#endif 	/* __IBlockedDrivers_FWD_DEFINED__ */


#ifndef __IDrivers_FWD_DEFINED__
#define __IDrivers_FWD_DEFINED__
typedef interface IDrivers IDrivers;
#endif 	/* __IDrivers_FWD_DEFINED__ */


#ifndef __IDriver_FWD_DEFINED__
#define __IDriver_FWD_DEFINED__
typedef interface IDriver IDriver;
#endif 	/* __IDriver_FWD_DEFINED__ */


#ifndef __IDriversEnum_FWD_DEFINED__
#define __IDriversEnum_FWD_DEFINED__
typedef interface IDriversEnum IDriversEnum;
#endif 	/* __IDriversEnum_FWD_DEFINED__ */


#ifndef __BlockedDrivers_FWD_DEFINED__
#define __BlockedDrivers_FWD_DEFINED__

#ifdef __cplusplus
typedef class BlockedDrivers BlockedDrivers;
#else
typedef struct BlockedDrivers BlockedDrivers;
#endif /* __cplusplus */

#endif 	/* __BlockedDrivers_FWD_DEFINED__ */


#ifndef __Drivers_FWD_DEFINED__
#define __Drivers_FWD_DEFINED__

#ifdef __cplusplus
typedef class Drivers Drivers;
#else
typedef struct Drivers Drivers;
#endif /* __cplusplus */

#endif 	/* __Drivers_FWD_DEFINED__ */


#ifndef __Driver_FWD_DEFINED__
#define __Driver_FWD_DEFINED__

#ifdef __cplusplus
typedef class Driver Driver;
#else
typedef struct Driver Driver;
#endif /* __cplusplus */

#endif 	/* __Driver_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

#ifndef __IBlockedDrivers_INTERFACE_DEFINED__
#define __IBlockedDrivers_INTERFACE_DEFINED__

/* interface IBlockedDrivers */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IBlockedDrivers;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("13F176D6-9B1D-477D-BD33-6FE75E960578")
    IBlockedDrivers : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE BlockedDrivers( 
            /* [retval][out] */ LPDISPATCH *pCollection) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBlockedDriversVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IBlockedDrivers * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IBlockedDrivers * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IBlockedDrivers * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IBlockedDrivers * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IBlockedDrivers * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IBlockedDrivers * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IBlockedDrivers * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *BlockedDrivers )( 
            IBlockedDrivers * This,
            /* [retval][out] */ LPDISPATCH *pCollection);
        
        END_INTERFACE
    } IBlockedDriversVtbl;

    interface IBlockedDrivers
    {
        CONST_VTBL struct IBlockedDriversVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBlockedDrivers_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IBlockedDrivers_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IBlockedDrivers_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IBlockedDrivers_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IBlockedDrivers_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IBlockedDrivers_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IBlockedDrivers_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IBlockedDrivers_BlockedDrivers(This,pCollection)	\
    (This)->lpVtbl -> BlockedDrivers(This,pCollection)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IBlockedDrivers_BlockedDrivers_Proxy( 
    IBlockedDrivers * This,
    /* [retval][out] */ LPDISPATCH *pCollection);


void __RPC_STUB IBlockedDrivers_BlockedDrivers_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IBlockedDrivers_INTERFACE_DEFINED__ */


#ifndef __IDrivers_INTERFACE_DEFINED__
#define __IDrivers_INTERFACE_DEFINED__

/* interface IDrivers */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IDrivers;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5FD0C0B2-0C30-43B2-A95B-2D7894ACD1C1")
    IDrivers : public IDispatch
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get__NewEnum( 
            /* [retval][out] */ IUnknown **ppUnk) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Item( 
            /* [in] */ long Index,
            /* [retval][out] */ LPDISPATCH *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDriversVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDrivers * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDrivers * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDrivers * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDrivers * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDrivers * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDrivers * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDrivers * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get__NewEnum )( 
            IDrivers * This,
            /* [retval][out] */ IUnknown **ppUnk);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Item )( 
            IDrivers * This,
            /* [in] */ long Index,
            /* [retval][out] */ LPDISPATCH *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Count )( 
            IDrivers * This,
            /* [retval][out] */ long *pVal);
        
        END_INTERFACE
    } IDriversVtbl;

    interface IDrivers
    {
        CONST_VTBL struct IDriversVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDrivers_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDrivers_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDrivers_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDrivers_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IDrivers_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IDrivers_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IDrivers_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IDrivers_get__NewEnum(This,ppUnk)	\
    (This)->lpVtbl -> get__NewEnum(This,ppUnk)

#define IDrivers_Item(This,Index,pVal)	\
    (This)->lpVtbl -> Item(This,Index,pVal)

#define IDrivers_get_Count(This,pVal)	\
    (This)->lpVtbl -> get_Count(This,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id][propget] */ HRESULT STDMETHODCALLTYPE IDrivers_get__NewEnum_Proxy( 
    IDrivers * This,
    /* [retval][out] */ IUnknown **ppUnk);


void __RPC_STUB IDrivers_get__NewEnum_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDrivers_Item_Proxy( 
    IDrivers * This,
    /* [in] */ long Index,
    /* [retval][out] */ LPDISPATCH *pVal);


void __RPC_STUB IDrivers_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDrivers_get_Count_Proxy( 
    IDrivers * This,
    /* [retval][out] */ long *pVal);


void __RPC_STUB IDrivers_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDrivers_INTERFACE_DEFINED__ */


#ifndef __IDriver_INTERFACE_DEFINED__
#define __IDriver_INTERFACE_DEFINED__

/* interface IDriver */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IDriver;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("08B6A002-8A41-4282-AE6C-7BE38158640C")
    IDriver : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Description( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Manufacturer( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_HelpFile( 
            /* [retval][out] */ BSTR *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDriverVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDriver * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDriver * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDriver * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDriver * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDriver * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDriver * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDriver * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            IDriver * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Description )( 
            IDriver * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Manufacturer )( 
            IDriver * This,
            /* [retval][out] */ BSTR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_HelpFile )( 
            IDriver * This,
            /* [retval][out] */ BSTR *pVal);
        
        END_INTERFACE
    } IDriverVtbl;

    interface IDriver
    {
        CONST_VTBL struct IDriverVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDriver_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDriver_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDriver_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDriver_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IDriver_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IDriver_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IDriver_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IDriver_get_Name(This,pVal)	\
    (This)->lpVtbl -> get_Name(This,pVal)

#define IDriver_get_Description(This,pVal)	\
    (This)->lpVtbl -> get_Description(This,pVal)

#define IDriver_get_Manufacturer(This,pVal)	\
    (This)->lpVtbl -> get_Manufacturer(This,pVal)

#define IDriver_get_HelpFile(This,pVal)	\
    (This)->lpVtbl -> get_HelpFile(This,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDriver_get_Name_Proxy( 
    IDriver * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IDriver_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDriver_get_Description_Proxy( 
    IDriver * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IDriver_get_Description_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDriver_get_Manufacturer_Proxy( 
    IDriver * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IDriver_get_Manufacturer_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDriver_get_HelpFile_Proxy( 
    IDriver * This,
    /* [retval][out] */ BSTR *pVal);


void __RPC_STUB IDriver_get_HelpFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDriver_INTERFACE_DEFINED__ */


#ifndef __IDriversEnum_INTERFACE_DEFINED__
#define __IDriversEnum_INTERFACE_DEFINED__

/* interface IDriversEnum */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IDriversEnum;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("16D32DAD-FBDA-44A4-A2C2-B196B4D9FB59")
    IDriversEnum : public IEnumVARIANT
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct IDriversEnumVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDriversEnum * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDriversEnum * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDriversEnum * This);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Next )( 
            IDriversEnum * This,
            /* [in] */ ULONG celt,
            /* [length_is][size_is][out] */ VARIANT *rgVar,
            /* [out] */ ULONG *pCeltFetched);
        
        HRESULT ( STDMETHODCALLTYPE *Skip )( 
            IDriversEnum * This,
            /* [in] */ ULONG celt);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IDriversEnum * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IDriversEnum * This,
            /* [out] */ IEnumVARIANT **ppEnum);
        
        END_INTERFACE
    } IDriversEnumVtbl;

    interface IDriversEnum
    {
        CONST_VTBL struct IDriversEnumVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDriversEnum_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDriversEnum_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDriversEnum_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDriversEnum_Next(This,celt,rgVar,pCeltFetched)	\
    (This)->lpVtbl -> Next(This,celt,rgVar,pCeltFetched)

#define IDriversEnum_Skip(This,celt)	\
    (This)->lpVtbl -> Skip(This,celt)

#define IDriversEnum_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IDriversEnum_Clone(This,ppEnum)	\
    (This)->lpVtbl -> Clone(This,ppEnum)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* __IDriversEnum_INTERFACE_DEFINED__ */



#ifndef __BLOCKDRIVERLib_LIBRARY_DEFINED__
#define __BLOCKDRIVERLib_LIBRARY_DEFINED__

/* library BLOCKDRIVERLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_BLOCKDRIVERLib;

EXTERN_C const CLSID CLSID_BlockedDrivers;

#ifdef __cplusplus

class DECLSPEC_UUID("783C030F-E948-487D-B35D-94FCF0F0C172")
BlockedDrivers;
#endif

EXTERN_C const CLSID CLSID_Drivers;

#ifdef __cplusplus

class DECLSPEC_UUID("D1AE835C-9D92-492F-80B4-43356F75038C")
Drivers;
#endif

EXTERN_C const CLSID CLSID_Driver;

#ifdef __cplusplus

class DECLSPEC_UUID("B62314FC-1215-4AEC-BCCD-AE51609BA291")
Driver;
#endif
#endif /* __BLOCKDRIVERLib_LIBRARY_DEFINED__ */

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


