

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for mvrint.idl:
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

#ifndef __mvrint_h__
#define __mvrint_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IDataMover_FWD_DEFINED__
#define __IDataMover_FWD_DEFINED__
typedef interface IDataMover IDataMover;
#endif 	/* __IDataMover_FWD_DEFINED__ */


#ifndef __IRemoteStorageHint_FWD_DEFINED__
#define __IRemoteStorageHint_FWD_DEFINED__
typedef interface IRemoteStorageHint IRemoteStorageHint;
#endif 	/* __IRemoteStorageHint_FWD_DEFINED__ */


#ifndef __IRemoteStorage_FWD_DEFINED__
#define __IRemoteStorage_FWD_DEFINED__
typedef interface IRemoteStorage IRemoteStorage;
#endif 	/* __IRemoteStorage_FWD_DEFINED__ */


#ifndef __ILocalStorage_FWD_DEFINED__
#define __ILocalStorage_FWD_DEFINED__
typedef interface ILocalStorage ILocalStorage;
#endif 	/* __ILocalStorage_FWD_DEFINED__ */


#ifndef __IRemoteStream_FWD_DEFINED__
#define __IRemoteStream_FWD_DEFINED__
typedef interface IRemoteStream IRemoteStream;
#endif 	/* __IRemoteStream_FWD_DEFINED__ */


#ifndef __ILocalStream_FWD_DEFINED__
#define __ILocalStream_FWD_DEFINED__
typedef interface ILocalStream ILocalStream;
#endif 	/* __ILocalStream_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "RmsInt.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

/* interface __MIDL_itf_mvrint_0000 */
/* [local] */ 




extern RPC_IF_HANDLE __MIDL_itf_mvrint_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_mvrint_0000_v0_0_s_ifspec;

#ifndef __IDataMover_INTERFACE_DEFINED__
#define __IDataMover_INTERFACE_DEFINED__

/* interface IDataMover */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IDataMover;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("54B6C009-C05A-4F16-AB55-716A1A1BE447")
    IDataMover : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetObjectId( 
            /* [out] */ GUID *pObjectId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BeginSession( 
            /* [string][in] */ BSTR remoteSessionName,
            /* [string][in] */ BSTR remoteSessionDescription,
            /* [in] */ SHORT remoteDataSet,
            /* [in] */ DWORD options) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EndSession( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE StoreData( 
            /* [string][in] */ BSTR localName,
            /* [in] */ ULARGE_INTEGER localDataStart,
            /* [in] */ ULARGE_INTEGER localDataSize,
            /* [in] */ DWORD flags,
            /* [out] */ ULARGE_INTEGER *pRemoteDataSetStart,
            /* [out] */ ULARGE_INTEGER *pRemoteFileStart,
            /* [out] */ ULARGE_INTEGER *pRemoteFileSize,
            /* [out] */ ULARGE_INTEGER *pRemoteDataStart,
            /* [out] */ ULARGE_INTEGER *pRemoteDataSize,
            /* [out] */ DWORD *pRemoteVerificationType,
            /* [out] */ ULARGE_INTEGER *pRemoteVerificationData,
            /* [out] */ DWORD *pDatastreamCRCType,
            /* [out] */ ULARGE_INTEGER *pDatastreamCRC,
            /* [out] */ ULARGE_INTEGER *pUsn) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RecallData( 
            /* [string][in] */ BSTR localName,
            /* [in] */ ULARGE_INTEGER localDataStart,
            /* [in] */ ULARGE_INTEGER localDataSize,
            /* [in] */ DWORD flags,
            /* [string][in] */ BSTR migratedSessionName,
            /* [in] */ ULARGE_INTEGER remoteDataSetStart,
            /* [in] */ ULARGE_INTEGER remoteFileStart,
            /* [in] */ ULARGE_INTEGER remoteFileSize,
            /* [in] */ ULARGE_INTEGER remoteDataStart,
            /* [in] */ ULARGE_INTEGER remoteDataSize,
            /* [in] */ DWORD remoteVerificationType,
            /* [in] */ ULARGE_INTEGER remoteVerificationData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FormatLabel( 
            /* [string][in] */ BSTR displayName,
            /* [string][out][in] */ BSTR *pLabel) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WriteLabel( 
            /* [string][in] */ BSTR label) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReadLabel( 
            /* [string][out][in] */ BSTR *pLabel) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE VerifyLabel( 
            /* [string][in] */ BSTR label) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDeviceName( 
            /* [string][out][in] */ BSTR *pName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDeviceName( 
            /* [string][in] */ BSTR name,
            /* [string][defaultvalue][in] */ BSTR volName = 0) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLargestFreeSpace( 
            /* [out] */ LONGLONG *freeSpace,
            /* [out] */ LONGLONG *capacity,
            /* [defaultvalue][in] */ ULONG defaultFreeSpaceLow = 0xffffffff,
            /* [defaultvalue][in] */ LONG defaultFreeSpaceHigh = 0xffffffff) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetInitialOffset( 
            /* [in] */ ULARGE_INTEGER initialOffset) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCartridge( 
            /* [out] */ IRmsCartridge **ptr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCartridge( 
            /* [in] */ IRmsCartridge *ptr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Cancel( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateLocalStream( 
            /* [string][in] */ BSTR name,
            /* [in] */ DWORD mode,
            /* [out] */ IStream **ppStream) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateRemoteStream( 
            /* [string][in] */ BSTR name,
            /* [in] */ DWORD mode,
            /* [string][in] */ BSTR remoteSessionName,
            /* [string][in] */ BSTR remoteSessionDescription,
            /* [in] */ ULARGE_INTEGER remoteDataSetStart,
            /* [in] */ ULARGE_INTEGER remoteFileStart,
            /* [in] */ ULARGE_INTEGER remoteFileSize,
            /* [in] */ ULARGE_INTEGER remoteDataStart,
            /* [in] */ ULARGE_INTEGER remoteDataSize,
            /* [in] */ DWORD remoteVerificationType,
            /* [in] */ ULARGE_INTEGER remoteVerificationData,
            /* [out] */ IStream **ppStream) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CloseStream( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Duplicate( 
            /* [in] */ IDataMover *pDestination,
            /* [in] */ DWORD options,
            /* [out] */ ULARGE_INTEGER *pBytesCopied,
            /* [out] */ ULARGE_INTEGER *pBytesReclaimed) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FlushBuffers( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Recover( 
            /* [out] */ BOOL *pDeleteFile) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDataMoverVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDataMover * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDataMover * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDataMover * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDataMover * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDataMover * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDataMover * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDataMover * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *GetObjectId )( 
            IDataMover * This,
            /* [out] */ GUID *pObjectId);
        
        HRESULT ( STDMETHODCALLTYPE *BeginSession )( 
            IDataMover * This,
            /* [string][in] */ BSTR remoteSessionName,
            /* [string][in] */ BSTR remoteSessionDescription,
            /* [in] */ SHORT remoteDataSet,
            /* [in] */ DWORD options);
        
        HRESULT ( STDMETHODCALLTYPE *EndSession )( 
            IDataMover * This);
        
        HRESULT ( STDMETHODCALLTYPE *StoreData )( 
            IDataMover * This,
            /* [string][in] */ BSTR localName,
            /* [in] */ ULARGE_INTEGER localDataStart,
            /* [in] */ ULARGE_INTEGER localDataSize,
            /* [in] */ DWORD flags,
            /* [out] */ ULARGE_INTEGER *pRemoteDataSetStart,
            /* [out] */ ULARGE_INTEGER *pRemoteFileStart,
            /* [out] */ ULARGE_INTEGER *pRemoteFileSize,
            /* [out] */ ULARGE_INTEGER *pRemoteDataStart,
            /* [out] */ ULARGE_INTEGER *pRemoteDataSize,
            /* [out] */ DWORD *pRemoteVerificationType,
            /* [out] */ ULARGE_INTEGER *pRemoteVerificationData,
            /* [out] */ DWORD *pDatastreamCRCType,
            /* [out] */ ULARGE_INTEGER *pDatastreamCRC,
            /* [out] */ ULARGE_INTEGER *pUsn);
        
        HRESULT ( STDMETHODCALLTYPE *RecallData )( 
            IDataMover * This,
            /* [string][in] */ BSTR localName,
            /* [in] */ ULARGE_INTEGER localDataStart,
            /* [in] */ ULARGE_INTEGER localDataSize,
            /* [in] */ DWORD flags,
            /* [string][in] */ BSTR migratedSessionName,
            /* [in] */ ULARGE_INTEGER remoteDataSetStart,
            /* [in] */ ULARGE_INTEGER remoteFileStart,
            /* [in] */ ULARGE_INTEGER remoteFileSize,
            /* [in] */ ULARGE_INTEGER remoteDataStart,
            /* [in] */ ULARGE_INTEGER remoteDataSize,
            /* [in] */ DWORD remoteVerificationType,
            /* [in] */ ULARGE_INTEGER remoteVerificationData);
        
        HRESULT ( STDMETHODCALLTYPE *FormatLabel )( 
            IDataMover * This,
            /* [string][in] */ BSTR displayName,
            /* [string][out][in] */ BSTR *pLabel);
        
        HRESULT ( STDMETHODCALLTYPE *WriteLabel )( 
            IDataMover * This,
            /* [string][in] */ BSTR label);
        
        HRESULT ( STDMETHODCALLTYPE *ReadLabel )( 
            IDataMover * This,
            /* [string][out][in] */ BSTR *pLabel);
        
        HRESULT ( STDMETHODCALLTYPE *VerifyLabel )( 
            IDataMover * This,
            /* [string][in] */ BSTR label);
        
        HRESULT ( STDMETHODCALLTYPE *GetDeviceName )( 
            IDataMover * This,
            /* [string][out][in] */ BSTR *pName);
        
        HRESULT ( STDMETHODCALLTYPE *SetDeviceName )( 
            IDataMover * This,
            /* [string][in] */ BSTR name,
            /* [string][defaultvalue][in] */ BSTR volName);
        
        HRESULT ( STDMETHODCALLTYPE *GetLargestFreeSpace )( 
            IDataMover * This,
            /* [out] */ LONGLONG *freeSpace,
            /* [out] */ LONGLONG *capacity,
            /* [defaultvalue][in] */ ULONG defaultFreeSpaceLow,
            /* [defaultvalue][in] */ LONG defaultFreeSpaceHigh);
        
        HRESULT ( STDMETHODCALLTYPE *SetInitialOffset )( 
            IDataMover * This,
            /* [in] */ ULARGE_INTEGER initialOffset);
        
        HRESULT ( STDMETHODCALLTYPE *GetCartridge )( 
            IDataMover * This,
            /* [out] */ IRmsCartridge **ptr);
        
        HRESULT ( STDMETHODCALLTYPE *SetCartridge )( 
            IDataMover * This,
            /* [in] */ IRmsCartridge *ptr);
        
        HRESULT ( STDMETHODCALLTYPE *Cancel )( 
            IDataMover * This);
        
        HRESULT ( STDMETHODCALLTYPE *CreateLocalStream )( 
            IDataMover * This,
            /* [string][in] */ BSTR name,
            /* [in] */ DWORD mode,
            /* [out] */ IStream **ppStream);
        
        HRESULT ( STDMETHODCALLTYPE *CreateRemoteStream )( 
            IDataMover * This,
            /* [string][in] */ BSTR name,
            /* [in] */ DWORD mode,
            /* [string][in] */ BSTR remoteSessionName,
            /* [string][in] */ BSTR remoteSessionDescription,
            /* [in] */ ULARGE_INTEGER remoteDataSetStart,
            /* [in] */ ULARGE_INTEGER remoteFileStart,
            /* [in] */ ULARGE_INTEGER remoteFileSize,
            /* [in] */ ULARGE_INTEGER remoteDataStart,
            /* [in] */ ULARGE_INTEGER remoteDataSize,
            /* [in] */ DWORD remoteVerificationType,
            /* [in] */ ULARGE_INTEGER remoteVerificationData,
            /* [out] */ IStream **ppStream);
        
        HRESULT ( STDMETHODCALLTYPE *CloseStream )( 
            IDataMover * This);
        
        HRESULT ( STDMETHODCALLTYPE *Duplicate )( 
            IDataMover * This,
            /* [in] */ IDataMover *pDestination,
            /* [in] */ DWORD options,
            /* [out] */ ULARGE_INTEGER *pBytesCopied,
            /* [out] */ ULARGE_INTEGER *pBytesReclaimed);
        
        HRESULT ( STDMETHODCALLTYPE *FlushBuffers )( 
            IDataMover * This);
        
        HRESULT ( STDMETHODCALLTYPE *Recover )( 
            IDataMover * This,
            /* [out] */ BOOL *pDeleteFile);
        
        END_INTERFACE
    } IDataMoverVtbl;

    interface IDataMover
    {
        CONST_VTBL struct IDataMoverVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDataMover_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDataMover_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDataMover_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDataMover_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IDataMover_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IDataMover_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IDataMover_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IDataMover_GetObjectId(This,pObjectId)	\
    (This)->lpVtbl -> GetObjectId(This,pObjectId)

#define IDataMover_BeginSession(This,remoteSessionName,remoteSessionDescription,remoteDataSet,options)	\
    (This)->lpVtbl -> BeginSession(This,remoteSessionName,remoteSessionDescription,remoteDataSet,options)

#define IDataMover_EndSession(This)	\
    (This)->lpVtbl -> EndSession(This)

#define IDataMover_StoreData(This,localName,localDataStart,localDataSize,flags,pRemoteDataSetStart,pRemoteFileStart,pRemoteFileSize,pRemoteDataStart,pRemoteDataSize,pRemoteVerificationType,pRemoteVerificationData,pDatastreamCRCType,pDatastreamCRC,pUsn)	\
    (This)->lpVtbl -> StoreData(This,localName,localDataStart,localDataSize,flags,pRemoteDataSetStart,pRemoteFileStart,pRemoteFileSize,pRemoteDataStart,pRemoteDataSize,pRemoteVerificationType,pRemoteVerificationData,pDatastreamCRCType,pDatastreamCRC,pUsn)

#define IDataMover_RecallData(This,localName,localDataStart,localDataSize,flags,migratedSessionName,remoteDataSetStart,remoteFileStart,remoteFileSize,remoteDataStart,remoteDataSize,remoteVerificationType,remoteVerificationData)	\
    (This)->lpVtbl -> RecallData(This,localName,localDataStart,localDataSize,flags,migratedSessionName,remoteDataSetStart,remoteFileStart,remoteFileSize,remoteDataStart,remoteDataSize,remoteVerificationType,remoteVerificationData)

#define IDataMover_FormatLabel(This,displayName,pLabel)	\
    (This)->lpVtbl -> FormatLabel(This,displayName,pLabel)

#define IDataMover_WriteLabel(This,label)	\
    (This)->lpVtbl -> WriteLabel(This,label)

#define IDataMover_ReadLabel(This,pLabel)	\
    (This)->lpVtbl -> ReadLabel(This,pLabel)

#define IDataMover_VerifyLabel(This,label)	\
    (This)->lpVtbl -> VerifyLabel(This,label)

#define IDataMover_GetDeviceName(This,pName)	\
    (This)->lpVtbl -> GetDeviceName(This,pName)

#define IDataMover_SetDeviceName(This,name,volName)	\
    (This)->lpVtbl -> SetDeviceName(This,name,volName)

#define IDataMover_GetLargestFreeSpace(This,freeSpace,capacity,defaultFreeSpaceLow,defaultFreeSpaceHigh)	\
    (This)->lpVtbl -> GetLargestFreeSpace(This,freeSpace,capacity,defaultFreeSpaceLow,defaultFreeSpaceHigh)

#define IDataMover_SetInitialOffset(This,initialOffset)	\
    (This)->lpVtbl -> SetInitialOffset(This,initialOffset)

#define IDataMover_GetCartridge(This,ptr)	\
    (This)->lpVtbl -> GetCartridge(This,ptr)

#define IDataMover_SetCartridge(This,ptr)	\
    (This)->lpVtbl -> SetCartridge(This,ptr)

#define IDataMover_Cancel(This)	\
    (This)->lpVtbl -> Cancel(This)

#define IDataMover_CreateLocalStream(This,name,mode,ppStream)	\
    (This)->lpVtbl -> CreateLocalStream(This,name,mode,ppStream)

#define IDataMover_CreateRemoteStream(This,name,mode,remoteSessionName,remoteSessionDescription,remoteDataSetStart,remoteFileStart,remoteFileSize,remoteDataStart,remoteDataSize,remoteVerificationType,remoteVerificationData,ppStream)	\
    (This)->lpVtbl -> CreateRemoteStream(This,name,mode,remoteSessionName,remoteSessionDescription,remoteDataSetStart,remoteFileStart,remoteFileSize,remoteDataStart,remoteDataSize,remoteVerificationType,remoteVerificationData,ppStream)

#define IDataMover_CloseStream(This)	\
    (This)->lpVtbl -> CloseStream(This)

#define IDataMover_Duplicate(This,pDestination,options,pBytesCopied,pBytesReclaimed)	\
    (This)->lpVtbl -> Duplicate(This,pDestination,options,pBytesCopied,pBytesReclaimed)

#define IDataMover_FlushBuffers(This)	\
    (This)->lpVtbl -> FlushBuffers(This)

#define IDataMover_Recover(This,pDeleteFile)	\
    (This)->lpVtbl -> Recover(This,pDeleteFile)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IDataMover_GetObjectId_Proxy( 
    IDataMover * This,
    /* [out] */ GUID *pObjectId);


void __RPC_STUB IDataMover_GetObjectId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDataMover_BeginSession_Proxy( 
    IDataMover * This,
    /* [string][in] */ BSTR remoteSessionName,
    /* [string][in] */ BSTR remoteSessionDescription,
    /* [in] */ SHORT remoteDataSet,
    /* [in] */ DWORD options);


void __RPC_STUB IDataMover_BeginSession_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDataMover_EndSession_Proxy( 
    IDataMover * This);


void __RPC_STUB IDataMover_EndSession_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDataMover_StoreData_Proxy( 
    IDataMover * This,
    /* [string][in] */ BSTR localName,
    /* [in] */ ULARGE_INTEGER localDataStart,
    /* [in] */ ULARGE_INTEGER localDataSize,
    /* [in] */ DWORD flags,
    /* [out] */ ULARGE_INTEGER *pRemoteDataSetStart,
    /* [out] */ ULARGE_INTEGER *pRemoteFileStart,
    /* [out] */ ULARGE_INTEGER *pRemoteFileSize,
    /* [out] */ ULARGE_INTEGER *pRemoteDataStart,
    /* [out] */ ULARGE_INTEGER *pRemoteDataSize,
    /* [out] */ DWORD *pRemoteVerificationType,
    /* [out] */ ULARGE_INTEGER *pRemoteVerificationData,
    /* [out] */ DWORD *pDatastreamCRCType,
    /* [out] */ ULARGE_INTEGER *pDatastreamCRC,
    /* [out] */ ULARGE_INTEGER *pUsn);


void __RPC_STUB IDataMover_StoreData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDataMover_RecallData_Proxy( 
    IDataMover * This,
    /* [string][in] */ BSTR localName,
    /* [in] */ ULARGE_INTEGER localDataStart,
    /* [in] */ ULARGE_INTEGER localDataSize,
    /* [in] */ DWORD flags,
    /* [string][in] */ BSTR migratedSessionName,
    /* [in] */ ULARGE_INTEGER remoteDataSetStart,
    /* [in] */ ULARGE_INTEGER remoteFileStart,
    /* [in] */ ULARGE_INTEGER remoteFileSize,
    /* [in] */ ULARGE_INTEGER remoteDataStart,
    /* [in] */ ULARGE_INTEGER remoteDataSize,
    /* [in] */ DWORD remoteVerificationType,
    /* [in] */ ULARGE_INTEGER remoteVerificationData);


void __RPC_STUB IDataMover_RecallData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDataMover_FormatLabel_Proxy( 
    IDataMover * This,
    /* [string][in] */ BSTR displayName,
    /* [string][out][in] */ BSTR *pLabel);


void __RPC_STUB IDataMover_FormatLabel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDataMover_WriteLabel_Proxy( 
    IDataMover * This,
    /* [string][in] */ BSTR label);


void __RPC_STUB IDataMover_WriteLabel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDataMover_ReadLabel_Proxy( 
    IDataMover * This,
    /* [string][out][in] */ BSTR *pLabel);


void __RPC_STUB IDataMover_ReadLabel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDataMover_VerifyLabel_Proxy( 
    IDataMover * This,
    /* [string][in] */ BSTR label);


void __RPC_STUB IDataMover_VerifyLabel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDataMover_GetDeviceName_Proxy( 
    IDataMover * This,
    /* [string][out][in] */ BSTR *pName);


void __RPC_STUB IDataMover_GetDeviceName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDataMover_SetDeviceName_Proxy( 
    IDataMover * This,
    /* [string][in] */ BSTR name,
    /* [string][defaultvalue][in] */ BSTR volName);


void __RPC_STUB IDataMover_SetDeviceName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDataMover_GetLargestFreeSpace_Proxy( 
    IDataMover * This,
    /* [out] */ LONGLONG *freeSpace,
    /* [out] */ LONGLONG *capacity,
    /* [defaultvalue][in] */ ULONG defaultFreeSpaceLow,
    /* [defaultvalue][in] */ LONG defaultFreeSpaceHigh);


void __RPC_STUB IDataMover_GetLargestFreeSpace_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDataMover_SetInitialOffset_Proxy( 
    IDataMover * This,
    /* [in] */ ULARGE_INTEGER initialOffset);


void __RPC_STUB IDataMover_SetInitialOffset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDataMover_GetCartridge_Proxy( 
    IDataMover * This,
    /* [out] */ IRmsCartridge **ptr);


void __RPC_STUB IDataMover_GetCartridge_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDataMover_SetCartridge_Proxy( 
    IDataMover * This,
    /* [in] */ IRmsCartridge *ptr);


void __RPC_STUB IDataMover_SetCartridge_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDataMover_Cancel_Proxy( 
    IDataMover * This);


void __RPC_STUB IDataMover_Cancel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDataMover_CreateLocalStream_Proxy( 
    IDataMover * This,
    /* [string][in] */ BSTR name,
    /* [in] */ DWORD mode,
    /* [out] */ IStream **ppStream);


void __RPC_STUB IDataMover_CreateLocalStream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDataMover_CreateRemoteStream_Proxy( 
    IDataMover * This,
    /* [string][in] */ BSTR name,
    /* [in] */ DWORD mode,
    /* [string][in] */ BSTR remoteSessionName,
    /* [string][in] */ BSTR remoteSessionDescription,
    /* [in] */ ULARGE_INTEGER remoteDataSetStart,
    /* [in] */ ULARGE_INTEGER remoteFileStart,
    /* [in] */ ULARGE_INTEGER remoteFileSize,
    /* [in] */ ULARGE_INTEGER remoteDataStart,
    /* [in] */ ULARGE_INTEGER remoteDataSize,
    /* [in] */ DWORD remoteVerificationType,
    /* [in] */ ULARGE_INTEGER remoteVerificationData,
    /* [out] */ IStream **ppStream);


void __RPC_STUB IDataMover_CreateRemoteStream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDataMover_CloseStream_Proxy( 
    IDataMover * This);


void __RPC_STUB IDataMover_CloseStream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDataMover_Duplicate_Proxy( 
    IDataMover * This,
    /* [in] */ IDataMover *pDestination,
    /* [in] */ DWORD options,
    /* [out] */ ULARGE_INTEGER *pBytesCopied,
    /* [out] */ ULARGE_INTEGER *pBytesReclaimed);


void __RPC_STUB IDataMover_Duplicate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDataMover_FlushBuffers_Proxy( 
    IDataMover * This);


void __RPC_STUB IDataMover_FlushBuffers_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IDataMover_Recover_Proxy( 
    IDataMover * This,
    /* [out] */ BOOL *pDeleteFile);


void __RPC_STUB IDataMover_Recover_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDataMover_INTERFACE_DEFINED__ */


#ifndef __IRemoteStorageHint_INTERFACE_DEFINED__
#define __IRemoteStorageHint_INTERFACE_DEFINED__

/* interface IRemoteStorageHint */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRemoteStorageHint;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BD010A01-000B-11D0-D0DD-00A0C9190459")
    IRemoteStorageHint : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Reset( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDataSetStart( 
            /* [in] */ ULARGE_INTEGER dataSetStart) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFileStart( 
            /* [in] */ ULARGE_INTEGER fileStart) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFileSize( 
            /* [in] */ ULARGE_INTEGER fileSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDataStart( 
            /* [in] */ ULARGE_INTEGER dataStart) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDataSize( 
            /* [in] */ ULARGE_INTEGER dataSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetVerificationData( 
            /* [in] */ DWORD verificationType,
            /* [in] */ ULARGE_INTEGER verificationData) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDatastreamCRC( 
            /* [in] */ DWORD dataStreamCRCType,
            /* [in] */ ULARGE_INTEGER dataStreamCRC) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFileUSN( 
            /* [in] */ ULARGE_INTEGER fileUSN) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetElementInformation( 
            /* [out] */ ULARGE_INTEGER *pDataSetStart,
            /* [out] */ ULARGE_INTEGER *pFileStart,
            /* [out] */ ULARGE_INTEGER *pFileSize,
            /* [out] */ ULARGE_INTEGER *pDataStart,
            /* [out] */ ULARGE_INTEGER *pDataSize,
            /* [out] */ DWORD *pVerificationType,
            /* [out] */ ULARGE_INTEGER *pVerificationData,
            /* [out] */ DWORD *pDataStreamCRCType,
            /* [out] */ ULARGE_INTEGER *pDataStreamCRC,
            /* [out] */ ULARGE_INTEGER *pFileUSN) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRemoteStorageHintVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRemoteStorageHint * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRemoteStorageHint * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRemoteStorageHint * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IRemoteStorageHint * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IRemoteStorageHint * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IRemoteStorageHint * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRemoteStorageHint * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *Reset )( 
            IRemoteStorageHint * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetDataSetStart )( 
            IRemoteStorageHint * This,
            /* [in] */ ULARGE_INTEGER dataSetStart);
        
        HRESULT ( STDMETHODCALLTYPE *SetFileStart )( 
            IRemoteStorageHint * This,
            /* [in] */ ULARGE_INTEGER fileStart);
        
        HRESULT ( STDMETHODCALLTYPE *SetFileSize )( 
            IRemoteStorageHint * This,
            /* [in] */ ULARGE_INTEGER fileSize);
        
        HRESULT ( STDMETHODCALLTYPE *SetDataStart )( 
            IRemoteStorageHint * This,
            /* [in] */ ULARGE_INTEGER dataStart);
        
        HRESULT ( STDMETHODCALLTYPE *SetDataSize )( 
            IRemoteStorageHint * This,
            /* [in] */ ULARGE_INTEGER dataSize);
        
        HRESULT ( STDMETHODCALLTYPE *SetVerificationData )( 
            IRemoteStorageHint * This,
            /* [in] */ DWORD verificationType,
            /* [in] */ ULARGE_INTEGER verificationData);
        
        HRESULT ( STDMETHODCALLTYPE *SetDatastreamCRC )( 
            IRemoteStorageHint * This,
            /* [in] */ DWORD dataStreamCRCType,
            /* [in] */ ULARGE_INTEGER dataStreamCRC);
        
        HRESULT ( STDMETHODCALLTYPE *SetFileUSN )( 
            IRemoteStorageHint * This,
            /* [in] */ ULARGE_INTEGER fileUSN);
        
        HRESULT ( STDMETHODCALLTYPE *GetElementInformation )( 
            IRemoteStorageHint * This,
            /* [out] */ ULARGE_INTEGER *pDataSetStart,
            /* [out] */ ULARGE_INTEGER *pFileStart,
            /* [out] */ ULARGE_INTEGER *pFileSize,
            /* [out] */ ULARGE_INTEGER *pDataStart,
            /* [out] */ ULARGE_INTEGER *pDataSize,
            /* [out] */ DWORD *pVerificationType,
            /* [out] */ ULARGE_INTEGER *pVerificationData,
            /* [out] */ DWORD *pDataStreamCRCType,
            /* [out] */ ULARGE_INTEGER *pDataStreamCRC,
            /* [out] */ ULARGE_INTEGER *pFileUSN);
        
        END_INTERFACE
    } IRemoteStorageHintVtbl;

    interface IRemoteStorageHint
    {
        CONST_VTBL struct IRemoteStorageHintVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRemoteStorageHint_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRemoteStorageHint_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRemoteStorageHint_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRemoteStorageHint_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRemoteStorageHint_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRemoteStorageHint_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRemoteStorageHint_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRemoteStorageHint_Reset(This)	\
    (This)->lpVtbl -> Reset(This)

#define IRemoteStorageHint_SetDataSetStart(This,dataSetStart)	\
    (This)->lpVtbl -> SetDataSetStart(This,dataSetStart)

#define IRemoteStorageHint_SetFileStart(This,fileStart)	\
    (This)->lpVtbl -> SetFileStart(This,fileStart)

#define IRemoteStorageHint_SetFileSize(This,fileSize)	\
    (This)->lpVtbl -> SetFileSize(This,fileSize)

#define IRemoteStorageHint_SetDataStart(This,dataStart)	\
    (This)->lpVtbl -> SetDataStart(This,dataStart)

#define IRemoteStorageHint_SetDataSize(This,dataSize)	\
    (This)->lpVtbl -> SetDataSize(This,dataSize)

#define IRemoteStorageHint_SetVerificationData(This,verificationType,verificationData)	\
    (This)->lpVtbl -> SetVerificationData(This,verificationType,verificationData)

#define IRemoteStorageHint_SetDatastreamCRC(This,dataStreamCRCType,dataStreamCRC)	\
    (This)->lpVtbl -> SetDatastreamCRC(This,dataStreamCRCType,dataStreamCRC)

#define IRemoteStorageHint_SetFileUSN(This,fileUSN)	\
    (This)->lpVtbl -> SetFileUSN(This,fileUSN)

#define IRemoteStorageHint_GetElementInformation(This,pDataSetStart,pFileStart,pFileSize,pDataStart,pDataSize,pVerificationType,pVerificationData,pDataStreamCRCType,pDataStreamCRC,pFileUSN)	\
    (This)->lpVtbl -> GetElementInformation(This,pDataSetStart,pFileStart,pFileSize,pDataStart,pDataSize,pVerificationType,pVerificationData,pDataStreamCRCType,pDataStreamCRC,pFileUSN)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRemoteStorageHint_Reset_Proxy( 
    IRemoteStorageHint * This);


void __RPC_STUB IRemoteStorageHint_Reset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRemoteStorageHint_SetDataSetStart_Proxy( 
    IRemoteStorageHint * This,
    /* [in] */ ULARGE_INTEGER dataSetStart);


void __RPC_STUB IRemoteStorageHint_SetDataSetStart_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRemoteStorageHint_SetFileStart_Proxy( 
    IRemoteStorageHint * This,
    /* [in] */ ULARGE_INTEGER fileStart);


void __RPC_STUB IRemoteStorageHint_SetFileStart_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRemoteStorageHint_SetFileSize_Proxy( 
    IRemoteStorageHint * This,
    /* [in] */ ULARGE_INTEGER fileSize);


void __RPC_STUB IRemoteStorageHint_SetFileSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRemoteStorageHint_SetDataStart_Proxy( 
    IRemoteStorageHint * This,
    /* [in] */ ULARGE_INTEGER dataStart);


void __RPC_STUB IRemoteStorageHint_SetDataStart_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRemoteStorageHint_SetDataSize_Proxy( 
    IRemoteStorageHint * This,
    /* [in] */ ULARGE_INTEGER dataSize);


void __RPC_STUB IRemoteStorageHint_SetDataSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRemoteStorageHint_SetVerificationData_Proxy( 
    IRemoteStorageHint * This,
    /* [in] */ DWORD verificationType,
    /* [in] */ ULARGE_INTEGER verificationData);


void __RPC_STUB IRemoteStorageHint_SetVerificationData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRemoteStorageHint_SetDatastreamCRC_Proxy( 
    IRemoteStorageHint * This,
    /* [in] */ DWORD dataStreamCRCType,
    /* [in] */ ULARGE_INTEGER dataStreamCRC);


void __RPC_STUB IRemoteStorageHint_SetDatastreamCRC_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRemoteStorageHint_SetFileUSN_Proxy( 
    IRemoteStorageHint * This,
    /* [in] */ ULARGE_INTEGER fileUSN);


void __RPC_STUB IRemoteStorageHint_SetFileUSN_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRemoteStorageHint_GetElementInformation_Proxy( 
    IRemoteStorageHint * This,
    /* [out] */ ULARGE_INTEGER *pDataSetStart,
    /* [out] */ ULARGE_INTEGER *pFileStart,
    /* [out] */ ULARGE_INTEGER *pFileSize,
    /* [out] */ ULARGE_INTEGER *pDataStart,
    /* [out] */ ULARGE_INTEGER *pDataSize,
    /* [out] */ DWORD *pVerificationType,
    /* [out] */ ULARGE_INTEGER *pVerificationData,
    /* [out] */ DWORD *pDataStreamCRCType,
    /* [out] */ ULARGE_INTEGER *pDataStreamCRC,
    /* [out] */ ULARGE_INTEGER *pFileUSN);


void __RPC_STUB IRemoteStorageHint_GetElementInformation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRemoteStorageHint_INTERFACE_DEFINED__ */


#ifndef __IRemoteStorage_INTERFACE_DEFINED__
#define __IRemoteStorage_INTERFACE_DEFINED__

/* interface IRemoteStorage */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRemoteStorage;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C48AD3C9-00D4-11D3-8FD1-0040339FD97B")
    IRemoteStorage : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE FormatLabel( 
            /* [string][in] */ BSTR displayName,
            /* [string][out][in] */ BSTR *pLabel) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WriteLabel( 
            /* [string][in] */ BSTR label) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ReadLabel( 
            /* [string][out][in] */ BSTR *pLabel) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE VerifyLabel( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDeviceName( 
            /* [string][out][in] */ BSTR *pName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDeviceName( 
            /* [string][in] */ BSTR name,
            /* [string][defaultvalue][in] */ BSTR volName = 0) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLargestFreeSpace( 
            /* [out] */ LONGLONG *freeSpace,
            /* [out] */ LONGLONG *capacity) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCartridge( 
            /* [out] */ IRmsCartridge **ptr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCartridge( 
            /* [in] */ IRmsCartridge *ptr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateRemoteStream( 
            /* [string][in] */ BSTR name,
            /* [string][in] */ BSTR description,
            /* [in] */ SHORT index,
            /* [in] */ DWORD options,
            /* [in] */ IRemoteStorageHint *pHint,
            /* [out] */ IStream **ppStream) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CloseStream( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRemoteStorageVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRemoteStorage * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRemoteStorage * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRemoteStorage * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IRemoteStorage * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IRemoteStorage * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IRemoteStorage * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRemoteStorage * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *FormatLabel )( 
            IRemoteStorage * This,
            /* [string][in] */ BSTR displayName,
            /* [string][out][in] */ BSTR *pLabel);
        
        HRESULT ( STDMETHODCALLTYPE *WriteLabel )( 
            IRemoteStorage * This,
            /* [string][in] */ BSTR label);
        
        HRESULT ( STDMETHODCALLTYPE *ReadLabel )( 
            IRemoteStorage * This,
            /* [string][out][in] */ BSTR *pLabel);
        
        HRESULT ( STDMETHODCALLTYPE *VerifyLabel )( 
            IRemoteStorage * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetDeviceName )( 
            IRemoteStorage * This,
            /* [string][out][in] */ BSTR *pName);
        
        HRESULT ( STDMETHODCALLTYPE *SetDeviceName )( 
            IRemoteStorage * This,
            /* [string][in] */ BSTR name,
            /* [string][defaultvalue][in] */ BSTR volName);
        
        HRESULT ( STDMETHODCALLTYPE *GetLargestFreeSpace )( 
            IRemoteStorage * This,
            /* [out] */ LONGLONG *freeSpace,
            /* [out] */ LONGLONG *capacity);
        
        HRESULT ( STDMETHODCALLTYPE *GetCartridge )( 
            IRemoteStorage * This,
            /* [out] */ IRmsCartridge **ptr);
        
        HRESULT ( STDMETHODCALLTYPE *SetCartridge )( 
            IRemoteStorage * This,
            /* [in] */ IRmsCartridge *ptr);
        
        HRESULT ( STDMETHODCALLTYPE *CreateRemoteStream )( 
            IRemoteStorage * This,
            /* [string][in] */ BSTR name,
            /* [string][in] */ BSTR description,
            /* [in] */ SHORT index,
            /* [in] */ DWORD options,
            /* [in] */ IRemoteStorageHint *pHint,
            /* [out] */ IStream **ppStream);
        
        HRESULT ( STDMETHODCALLTYPE *CloseStream )( 
            IRemoteStorage * This);
        
        END_INTERFACE
    } IRemoteStorageVtbl;

    interface IRemoteStorage
    {
        CONST_VTBL struct IRemoteStorageVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRemoteStorage_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRemoteStorage_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRemoteStorage_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRemoteStorage_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRemoteStorage_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRemoteStorage_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRemoteStorage_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRemoteStorage_FormatLabel(This,displayName,pLabel)	\
    (This)->lpVtbl -> FormatLabel(This,displayName,pLabel)

#define IRemoteStorage_WriteLabel(This,label)	\
    (This)->lpVtbl -> WriteLabel(This,label)

#define IRemoteStorage_ReadLabel(This,pLabel)	\
    (This)->lpVtbl -> ReadLabel(This,pLabel)

#define IRemoteStorage_VerifyLabel(This)	\
    (This)->lpVtbl -> VerifyLabel(This)

#define IRemoteStorage_GetDeviceName(This,pName)	\
    (This)->lpVtbl -> GetDeviceName(This,pName)

#define IRemoteStorage_SetDeviceName(This,name,volName)	\
    (This)->lpVtbl -> SetDeviceName(This,name,volName)

#define IRemoteStorage_GetLargestFreeSpace(This,freeSpace,capacity)	\
    (This)->lpVtbl -> GetLargestFreeSpace(This,freeSpace,capacity)

#define IRemoteStorage_GetCartridge(This,ptr)	\
    (This)->lpVtbl -> GetCartridge(This,ptr)

#define IRemoteStorage_SetCartridge(This,ptr)	\
    (This)->lpVtbl -> SetCartridge(This,ptr)

#define IRemoteStorage_CreateRemoteStream(This,name,description,index,options,pHint,ppStream)	\
    (This)->lpVtbl -> CreateRemoteStream(This,name,description,index,options,pHint,ppStream)

#define IRemoteStorage_CloseStream(This)	\
    (This)->lpVtbl -> CloseStream(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRemoteStorage_FormatLabel_Proxy( 
    IRemoteStorage * This,
    /* [string][in] */ BSTR displayName,
    /* [string][out][in] */ BSTR *pLabel);


void __RPC_STUB IRemoteStorage_FormatLabel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRemoteStorage_WriteLabel_Proxy( 
    IRemoteStorage * This,
    /* [string][in] */ BSTR label);


void __RPC_STUB IRemoteStorage_WriteLabel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRemoteStorage_ReadLabel_Proxy( 
    IRemoteStorage * This,
    /* [string][out][in] */ BSTR *pLabel);


void __RPC_STUB IRemoteStorage_ReadLabel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRemoteStorage_VerifyLabel_Proxy( 
    IRemoteStorage * This);


void __RPC_STUB IRemoteStorage_VerifyLabel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRemoteStorage_GetDeviceName_Proxy( 
    IRemoteStorage * This,
    /* [string][out][in] */ BSTR *pName);


void __RPC_STUB IRemoteStorage_GetDeviceName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRemoteStorage_SetDeviceName_Proxy( 
    IRemoteStorage * This,
    /* [string][in] */ BSTR name,
    /* [string][defaultvalue][in] */ BSTR volName);


void __RPC_STUB IRemoteStorage_SetDeviceName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRemoteStorage_GetLargestFreeSpace_Proxy( 
    IRemoteStorage * This,
    /* [out] */ LONGLONG *freeSpace,
    /* [out] */ LONGLONG *capacity);


void __RPC_STUB IRemoteStorage_GetLargestFreeSpace_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRemoteStorage_GetCartridge_Proxy( 
    IRemoteStorage * This,
    /* [out] */ IRmsCartridge **ptr);


void __RPC_STUB IRemoteStorage_GetCartridge_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRemoteStorage_SetCartridge_Proxy( 
    IRemoteStorage * This,
    /* [in] */ IRmsCartridge *ptr);


void __RPC_STUB IRemoteStorage_SetCartridge_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRemoteStorage_CreateRemoteStream_Proxy( 
    IRemoteStorage * This,
    /* [string][in] */ BSTR name,
    /* [string][in] */ BSTR description,
    /* [in] */ SHORT index,
    /* [in] */ DWORD options,
    /* [in] */ IRemoteStorageHint *pHint,
    /* [out] */ IStream **ppStream);


void __RPC_STUB IRemoteStorage_CreateRemoteStream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRemoteStorage_CloseStream_Proxy( 
    IRemoteStorage * This);


void __RPC_STUB IRemoteStorage_CloseStream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRemoteStorage_INTERFACE_DEFINED__ */


#ifndef __ILocalStorage_INTERFACE_DEFINED__
#define __ILocalStorage_INTERFACE_DEFINED__

/* interface ILocalStorage */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ILocalStorage;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BD010A03-000B-11D0-D0DD-00A0C9190459")
    ILocalStorage : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CreateLocalStream( 
            /* [string][in] */ BSTR name,
            /* [in] */ DWORD mode,
            /* [out] */ IStream **ppStream) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CloseStream( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILocalStorageVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILocalStorage * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILocalStorage * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILocalStorage * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILocalStorage * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILocalStorage * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILocalStorage * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILocalStorage * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *CreateLocalStream )( 
            ILocalStorage * This,
            /* [string][in] */ BSTR name,
            /* [in] */ DWORD mode,
            /* [out] */ IStream **ppStream);
        
        HRESULT ( STDMETHODCALLTYPE *CloseStream )( 
            ILocalStorage * This);
        
        END_INTERFACE
    } ILocalStorageVtbl;

    interface ILocalStorage
    {
        CONST_VTBL struct ILocalStorageVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILocalStorage_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ILocalStorage_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ILocalStorage_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ILocalStorage_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ILocalStorage_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ILocalStorage_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ILocalStorage_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ILocalStorage_CreateLocalStream(This,name,mode,ppStream)	\
    (This)->lpVtbl -> CreateLocalStream(This,name,mode,ppStream)

#define ILocalStorage_CloseStream(This)	\
    (This)->lpVtbl -> CloseStream(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ILocalStorage_CreateLocalStream_Proxy( 
    ILocalStorage * This,
    /* [string][in] */ BSTR name,
    /* [in] */ DWORD mode,
    /* [out] */ IStream **ppStream);


void __RPC_STUB ILocalStorage_CreateLocalStream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ILocalStorage_CloseStream_Proxy( 
    ILocalStorage * This);


void __RPC_STUB ILocalStorage_CloseStream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ILocalStorage_INTERFACE_DEFINED__ */


#ifndef __IRemoteStream_INTERFACE_DEFINED__
#define __IRemoteStream_INTERFACE_DEFINED__

/* interface IRemoteStream */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IRemoteStream;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BD010A04-000B-11D0-D0DD-00A0C9190459")
    IRemoteStream : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CreateRemoteStream( 
            /* [string][in] */ BSTR name,
            /* [in] */ DWORD mode,
            /* [out] */ IStream **ppStream) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CloseStream( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRemoteStreamVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IRemoteStream * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IRemoteStream * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IRemoteStream * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IRemoteStream * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IRemoteStream * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IRemoteStream * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IRemoteStream * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *CreateRemoteStream )( 
            IRemoteStream * This,
            /* [string][in] */ BSTR name,
            /* [in] */ DWORD mode,
            /* [out] */ IStream **ppStream);
        
        HRESULT ( STDMETHODCALLTYPE *CloseStream )( 
            IRemoteStream * This);
        
        END_INTERFACE
    } IRemoteStreamVtbl;

    interface IRemoteStream
    {
        CONST_VTBL struct IRemoteStreamVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRemoteStream_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRemoteStream_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRemoteStream_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRemoteStream_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRemoteStream_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRemoteStream_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRemoteStream_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRemoteStream_CreateRemoteStream(This,name,mode,ppStream)	\
    (This)->lpVtbl -> CreateRemoteStream(This,name,mode,ppStream)

#define IRemoteStream_CloseStream(This)	\
    (This)->lpVtbl -> CloseStream(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IRemoteStream_CreateRemoteStream_Proxy( 
    IRemoteStream * This,
    /* [string][in] */ BSTR name,
    /* [in] */ DWORD mode,
    /* [out] */ IStream **ppStream);


void __RPC_STUB IRemoteStream_CreateRemoteStream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IRemoteStream_CloseStream_Proxy( 
    IRemoteStream * This);


void __RPC_STUB IRemoteStream_CloseStream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRemoteStream_INTERFACE_DEFINED__ */


#ifndef __ILocalStream_INTERFACE_DEFINED__
#define __ILocalStream_INTERFACE_DEFINED__

/* interface ILocalStream */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ILocalStream;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BD010A05-000B-11D0-D0DD-00A0C9190459")
    ILocalStream : public IDispatch
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE CreateLocalStream( 
            /* [string][in] */ BSTR name,
            /* [in] */ DWORD mode,
            /* [out] */ IStream **ppStream) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CloseStream( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ILocalStreamVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ILocalStream * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ILocalStream * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ILocalStream * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ILocalStream * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ILocalStream * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ILocalStream * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ILocalStream * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        HRESULT ( STDMETHODCALLTYPE *CreateLocalStream )( 
            ILocalStream * This,
            /* [string][in] */ BSTR name,
            /* [in] */ DWORD mode,
            /* [out] */ IStream **ppStream);
        
        HRESULT ( STDMETHODCALLTYPE *CloseStream )( 
            ILocalStream * This);
        
        END_INTERFACE
    } ILocalStreamVtbl;

    interface ILocalStream
    {
        CONST_VTBL struct ILocalStreamVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ILocalStream_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ILocalStream_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ILocalStream_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ILocalStream_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ILocalStream_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ILocalStream_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ILocalStream_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ILocalStream_CreateLocalStream(This,name,mode,ppStream)	\
    (This)->lpVtbl -> CreateLocalStream(This,name,mode,ppStream)

#define ILocalStream_CloseStream(This)	\
    (This)->lpVtbl -> CloseStream(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ILocalStream_CreateLocalStream_Proxy( 
    ILocalStream * This,
    /* [string][in] */ BSTR name,
    /* [in] */ DWORD mode,
    /* [out] */ IStream **ppStream);


void __RPC_STUB ILocalStream_CreateLocalStream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ILocalStream_CloseStream_Proxy( 
    ILocalStream * This);


void __RPC_STUB ILocalStream_CloseStream_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ILocalStream_INTERFACE_DEFINED__ */


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


