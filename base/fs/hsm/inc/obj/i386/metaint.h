

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for metaint.idl:
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

#ifndef __metaint_h__
#define __metaint_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ISegRec_FWD_DEFINED__
#define __ISegRec_FWD_DEFINED__
typedef interface ISegRec ISegRec;
#endif 	/* __ISegRec_FWD_DEFINED__ */


#ifndef __IBagHole_FWD_DEFINED__
#define __IBagHole_FWD_DEFINED__
typedef interface IBagHole IBagHole;
#endif 	/* __IBagHole_FWD_DEFINED__ */


#ifndef __IBagInfo_FWD_DEFINED__
#define __IBagInfo_FWD_DEFINED__
typedef interface IBagInfo IBagInfo;
#endif 	/* __IBagInfo_FWD_DEFINED__ */


#ifndef __IMediaInfo_FWD_DEFINED__
#define __IMediaInfo_FWD_DEFINED__
typedef interface IMediaInfo IMediaInfo;
#endif 	/* __IMediaInfo_FWD_DEFINED__ */


#ifndef __IVolAssign_FWD_DEFINED__
#define __IVolAssign_FWD_DEFINED__
typedef interface IVolAssign IVolAssign;
#endif 	/* __IVolAssign_FWD_DEFINED__ */


#ifndef __ISegDb_FWD_DEFINED__
#define __ISegDb_FWD_DEFINED__
typedef interface ISegDb ISegDb;
#endif 	/* __ISegDb_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "wsbint.h"
#include "metadef.h"
#include "jobdef.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

#ifndef __ISegRec_INTERFACE_DEFINED__
#define __ISegRec_INTERFACE_DEFINED__

/* interface ISegRec */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISegRec;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("952B2BC7-FAF6-4B14-84CD-2FA4F0156BC7")
    ISegRec : public IWsbDbEntity
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetSegmentRecord( 
            /* [out] */ GUID *pBagId,
            /* [out] */ LONGLONG *pSegStartLoc,
            /* [out] */ LONGLONG *pSegLen,
            /* [out] */ USHORT *pSegFlags,
            /* [out] */ GUID *pPrimPos,
            /* [out] */ LONGLONG *pSecPos) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSegmentRecord( 
            /* [in] */ GUID bagId,
            /* [in] */ LONGLONG segStartLoc,
            /* [in] */ LONGLONG segLen,
            /* [in] */ USHORT segFlags,
            /* [in] */ GUID primPos,
            /* [in] */ LONGLONG secPos) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSegmentFlags( 
            /* [out] */ USHORT *pSegFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSegmentFlags( 
            /* [in] */ USHORT segFlags) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPrimPos( 
            /* [out] */ GUID *pPrimPos) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetPrimPos( 
            /* [in] */ GUID PrimPos) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSecPos( 
            /* [out] */ LONGLONG *pSecPos) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetSecPos( 
            /* [in] */ LONGLONG secPos) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISegRecVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISegRec * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISegRec * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISegRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            ISegRec * This,
            /* [in] */ REFIID riid,
            /* [iid_is][retval][out] */ void **ppEntity);
        
        HRESULT ( STDMETHODCALLTYPE *Disconnect )( 
            ISegRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *FindEQ )( 
            ISegRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *FindGT )( 
            ISegRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *FindGTE )( 
            ISegRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *FindLT )( 
            ISegRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *FindLTE )( 
            ISegRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *First )( 
            ISegRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *Last )( 
            ISegRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *MarkAsNew )( 
            ISegRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            ISegRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *Previous )( 
            ISegRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *Print )( 
            ISegRec * This,
            /* [in] */ IStream *pStream);
        
        HRESULT ( STDMETHODCALLTYPE *Remove )( 
            ISegRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *UpdateKey )( 
            ISegRec * This,
            /* [in] */ IWsbDbKey *pKey);
        
        HRESULT ( STDMETHODCALLTYPE *UseKey )( 
            ISegRec * This,
            /* [in] */ ULONG type);
        
        HRESULT ( STDMETHODCALLTYPE *Write )( 
            ISegRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetSequentialScan )( 
            ISegRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *ResetSequentialScan )( 
            ISegRec * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetSegmentRecord )( 
            ISegRec * This,
            /* [out] */ GUID *pBagId,
            /* [out] */ LONGLONG *pSegStartLoc,
            /* [out] */ LONGLONG *pSegLen,
            /* [out] */ USHORT *pSegFlags,
            /* [out] */ GUID *pPrimPos,
            /* [out] */ LONGLONG *pSecPos);
        
        HRESULT ( STDMETHODCALLTYPE *SetSegmentRecord )( 
            ISegRec * This,
            /* [in] */ GUID bagId,
            /* [in] */ LONGLONG segStartLoc,
            /* [in] */ LONGLONG segLen,
            /* [in] */ USHORT segFlags,
            /* [in] */ GUID primPos,
            /* [in] */ LONGLONG secPos);
        
        HRESULT ( STDMETHODCALLTYPE *GetSegmentFlags )( 
            ISegRec * This,
            /* [out] */ USHORT *pSegFlags);
        
        HRESULT ( STDMETHODCALLTYPE *SetSegmentFlags )( 
            ISegRec * This,
            /* [in] */ USHORT segFlags);
        
        HRESULT ( STDMETHODCALLTYPE *GetPrimPos )( 
            ISegRec * This,
            /* [out] */ GUID *pPrimPos);
        
        HRESULT ( STDMETHODCALLTYPE *SetPrimPos )( 
            ISegRec * This,
            /* [in] */ GUID PrimPos);
        
        HRESULT ( STDMETHODCALLTYPE *GetSecPos )( 
            ISegRec * This,
            /* [out] */ LONGLONG *pSecPos);
        
        HRESULT ( STDMETHODCALLTYPE *SetSecPos )( 
            ISegRec * This,
            /* [in] */ LONGLONG secPos);
        
        END_INTERFACE
    } ISegRecVtbl;

    interface ISegRec
    {
        CONST_VTBL struct ISegRecVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISegRec_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISegRec_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISegRec_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISegRec_Clone(This,riid,ppEntity)	\
    (This)->lpVtbl -> Clone(This,riid,ppEntity)

#define ISegRec_Disconnect(This)	\
    (This)->lpVtbl -> Disconnect(This)

#define ISegRec_FindEQ(This)	\
    (This)->lpVtbl -> FindEQ(This)

#define ISegRec_FindGT(This)	\
    (This)->lpVtbl -> FindGT(This)

#define ISegRec_FindGTE(This)	\
    (This)->lpVtbl -> FindGTE(This)

#define ISegRec_FindLT(This)	\
    (This)->lpVtbl -> FindLT(This)

#define ISegRec_FindLTE(This)	\
    (This)->lpVtbl -> FindLTE(This)

#define ISegRec_First(This)	\
    (This)->lpVtbl -> First(This)

#define ISegRec_Last(This)	\
    (This)->lpVtbl -> Last(This)

#define ISegRec_MarkAsNew(This)	\
    (This)->lpVtbl -> MarkAsNew(This)

#define ISegRec_Next(This)	\
    (This)->lpVtbl -> Next(This)

#define ISegRec_Previous(This)	\
    (This)->lpVtbl -> Previous(This)

#define ISegRec_Print(This,pStream)	\
    (This)->lpVtbl -> Print(This,pStream)

#define ISegRec_Remove(This)	\
    (This)->lpVtbl -> Remove(This)

#define ISegRec_UpdateKey(This,pKey)	\
    (This)->lpVtbl -> UpdateKey(This,pKey)

#define ISegRec_UseKey(This,type)	\
    (This)->lpVtbl -> UseKey(This,type)

#define ISegRec_Write(This)	\
    (This)->lpVtbl -> Write(This)

#define ISegRec_SetSequentialScan(This)	\
    (This)->lpVtbl -> SetSequentialScan(This)

#define ISegRec_ResetSequentialScan(This)	\
    (This)->lpVtbl -> ResetSequentialScan(This)


#define ISegRec_GetSegmentRecord(This,pBagId,pSegStartLoc,pSegLen,pSegFlags,pPrimPos,pSecPos)	\
    (This)->lpVtbl -> GetSegmentRecord(This,pBagId,pSegStartLoc,pSegLen,pSegFlags,pPrimPos,pSecPos)

#define ISegRec_SetSegmentRecord(This,bagId,segStartLoc,segLen,segFlags,primPos,secPos)	\
    (This)->lpVtbl -> SetSegmentRecord(This,bagId,segStartLoc,segLen,segFlags,primPos,secPos)

#define ISegRec_GetSegmentFlags(This,pSegFlags)	\
    (This)->lpVtbl -> GetSegmentFlags(This,pSegFlags)

#define ISegRec_SetSegmentFlags(This,segFlags)	\
    (This)->lpVtbl -> SetSegmentFlags(This,segFlags)

#define ISegRec_GetPrimPos(This,pPrimPos)	\
    (This)->lpVtbl -> GetPrimPos(This,pPrimPos)

#define ISegRec_SetPrimPos(This,PrimPos)	\
    (This)->lpVtbl -> SetPrimPos(This,PrimPos)

#define ISegRec_GetSecPos(This,pSecPos)	\
    (This)->lpVtbl -> GetSecPos(This,pSecPos)

#define ISegRec_SetSecPos(This,secPos)	\
    (This)->lpVtbl -> SetSecPos(This,secPos)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ISegRec_GetSegmentRecord_Proxy( 
    ISegRec * This,
    /* [out] */ GUID *pBagId,
    /* [out] */ LONGLONG *pSegStartLoc,
    /* [out] */ LONGLONG *pSegLen,
    /* [out] */ USHORT *pSegFlags,
    /* [out] */ GUID *pPrimPos,
    /* [out] */ LONGLONG *pSecPos);


void __RPC_STUB ISegRec_GetSegmentRecord_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ISegRec_SetSegmentRecord_Proxy( 
    ISegRec * This,
    /* [in] */ GUID bagId,
    /* [in] */ LONGLONG segStartLoc,
    /* [in] */ LONGLONG segLen,
    /* [in] */ USHORT segFlags,
    /* [in] */ GUID primPos,
    /* [in] */ LONGLONG secPos);


void __RPC_STUB ISegRec_SetSegmentRecord_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ISegRec_GetSegmentFlags_Proxy( 
    ISegRec * This,
    /* [out] */ USHORT *pSegFlags);


void __RPC_STUB ISegRec_GetSegmentFlags_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ISegRec_SetSegmentFlags_Proxy( 
    ISegRec * This,
    /* [in] */ USHORT segFlags);


void __RPC_STUB ISegRec_SetSegmentFlags_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ISegRec_GetPrimPos_Proxy( 
    ISegRec * This,
    /* [out] */ GUID *pPrimPos);


void __RPC_STUB ISegRec_GetPrimPos_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ISegRec_SetPrimPos_Proxy( 
    ISegRec * This,
    /* [in] */ GUID PrimPos);


void __RPC_STUB ISegRec_SetPrimPos_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ISegRec_GetSecPos_Proxy( 
    ISegRec * This,
    /* [out] */ LONGLONG *pSecPos);


void __RPC_STUB ISegRec_GetSecPos_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ISegRec_SetSecPos_Proxy( 
    ISegRec * This,
    /* [in] */ LONGLONG secPos);


void __RPC_STUB ISegRec_SetSecPos_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISegRec_INTERFACE_DEFINED__ */


#ifndef __IBagHole_INTERFACE_DEFINED__
#define __IBagHole_INTERFACE_DEFINED__

/* interface IBagHole */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IBagHole;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("450024A0-47D0-11D0-9E1E-00A0C916F120")
    IBagHole : public IWsbDbEntity
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetBagHole( 
            /* [out] */ GUID *pBagId,
            /* [out] */ LONGLONG *pSegStartLoc,
            /* [out] */ LONGLONG *pSegLen) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetBagHole( 
            /* [in] */ GUID BagId,
            /* [in] */ LONGLONG segStartLoc,
            /* [in] */ LONGLONG segLen) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBagHoleVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IBagHole * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IBagHole * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IBagHole * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IBagHole * This,
            /* [in] */ REFIID riid,
            /* [iid_is][retval][out] */ void **ppEntity);
        
        HRESULT ( STDMETHODCALLTYPE *Disconnect )( 
            IBagHole * This);
        
        HRESULT ( STDMETHODCALLTYPE *FindEQ )( 
            IBagHole * This);
        
        HRESULT ( STDMETHODCALLTYPE *FindGT )( 
            IBagHole * This);
        
        HRESULT ( STDMETHODCALLTYPE *FindGTE )( 
            IBagHole * This);
        
        HRESULT ( STDMETHODCALLTYPE *FindLT )( 
            IBagHole * This);
        
        HRESULT ( STDMETHODCALLTYPE *FindLTE )( 
            IBagHole * This);
        
        HRESULT ( STDMETHODCALLTYPE *First )( 
            IBagHole * This);
        
        HRESULT ( STDMETHODCALLTYPE *Last )( 
            IBagHole * This);
        
        HRESULT ( STDMETHODCALLTYPE *MarkAsNew )( 
            IBagHole * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IBagHole * This);
        
        HRESULT ( STDMETHODCALLTYPE *Previous )( 
            IBagHole * This);
        
        HRESULT ( STDMETHODCALLTYPE *Print )( 
            IBagHole * This,
            /* [in] */ IStream *pStream);
        
        HRESULT ( STDMETHODCALLTYPE *Remove )( 
            IBagHole * This);
        
        HRESULT ( STDMETHODCALLTYPE *UpdateKey )( 
            IBagHole * This,
            /* [in] */ IWsbDbKey *pKey);
        
        HRESULT ( STDMETHODCALLTYPE *UseKey )( 
            IBagHole * This,
            /* [in] */ ULONG type);
        
        HRESULT ( STDMETHODCALLTYPE *Write )( 
            IBagHole * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetSequentialScan )( 
            IBagHole * This);
        
        HRESULT ( STDMETHODCALLTYPE *ResetSequentialScan )( 
            IBagHole * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetBagHole )( 
            IBagHole * This,
            /* [out] */ GUID *pBagId,
            /* [out] */ LONGLONG *pSegStartLoc,
            /* [out] */ LONGLONG *pSegLen);
        
        HRESULT ( STDMETHODCALLTYPE *SetBagHole )( 
            IBagHole * This,
            /* [in] */ GUID BagId,
            /* [in] */ LONGLONG segStartLoc,
            /* [in] */ LONGLONG segLen);
        
        END_INTERFACE
    } IBagHoleVtbl;

    interface IBagHole
    {
        CONST_VTBL struct IBagHoleVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBagHole_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IBagHole_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IBagHole_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IBagHole_Clone(This,riid,ppEntity)	\
    (This)->lpVtbl -> Clone(This,riid,ppEntity)

#define IBagHole_Disconnect(This)	\
    (This)->lpVtbl -> Disconnect(This)

#define IBagHole_FindEQ(This)	\
    (This)->lpVtbl -> FindEQ(This)

#define IBagHole_FindGT(This)	\
    (This)->lpVtbl -> FindGT(This)

#define IBagHole_FindGTE(This)	\
    (This)->lpVtbl -> FindGTE(This)

#define IBagHole_FindLT(This)	\
    (This)->lpVtbl -> FindLT(This)

#define IBagHole_FindLTE(This)	\
    (This)->lpVtbl -> FindLTE(This)

#define IBagHole_First(This)	\
    (This)->lpVtbl -> First(This)

#define IBagHole_Last(This)	\
    (This)->lpVtbl -> Last(This)

#define IBagHole_MarkAsNew(This)	\
    (This)->lpVtbl -> MarkAsNew(This)

#define IBagHole_Next(This)	\
    (This)->lpVtbl -> Next(This)

#define IBagHole_Previous(This)	\
    (This)->lpVtbl -> Previous(This)

#define IBagHole_Print(This,pStream)	\
    (This)->lpVtbl -> Print(This,pStream)

#define IBagHole_Remove(This)	\
    (This)->lpVtbl -> Remove(This)

#define IBagHole_UpdateKey(This,pKey)	\
    (This)->lpVtbl -> UpdateKey(This,pKey)

#define IBagHole_UseKey(This,type)	\
    (This)->lpVtbl -> UseKey(This,type)

#define IBagHole_Write(This)	\
    (This)->lpVtbl -> Write(This)

#define IBagHole_SetSequentialScan(This)	\
    (This)->lpVtbl -> SetSequentialScan(This)

#define IBagHole_ResetSequentialScan(This)	\
    (This)->lpVtbl -> ResetSequentialScan(This)


#define IBagHole_GetBagHole(This,pBagId,pSegStartLoc,pSegLen)	\
    (This)->lpVtbl -> GetBagHole(This,pBagId,pSegStartLoc,pSegLen)

#define IBagHole_SetBagHole(This,BagId,segStartLoc,segLen)	\
    (This)->lpVtbl -> SetBagHole(This,BagId,segStartLoc,segLen)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IBagHole_GetBagHole_Proxy( 
    IBagHole * This,
    /* [out] */ GUID *pBagId,
    /* [out] */ LONGLONG *pSegStartLoc,
    /* [out] */ LONGLONG *pSegLen);


void __RPC_STUB IBagHole_GetBagHole_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IBagHole_SetBagHole_Proxy( 
    IBagHole * This,
    /* [in] */ GUID BagId,
    /* [in] */ LONGLONG segStartLoc,
    /* [in] */ LONGLONG segLen);


void __RPC_STUB IBagHole_SetBagHole_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IBagHole_INTERFACE_DEFINED__ */


#ifndef __IBagInfo_INTERFACE_DEFINED__
#define __IBagInfo_INTERFACE_DEFINED__

/* interface IBagInfo */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IBagInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B13FA471-4E1B-11D0-9E22-00A0C916F120")
    IBagInfo : public IWsbDbEntity
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetBagInfo( 
            /* [out] */ HSM_BAG_STATUS *pStatus,
            /* [out] */ GUID *pBagId,
            /* [out] */ FILETIME *pBirthDate,
            /* [out] */ LONGLONG *pLen,
            /* [out] */ USHORT *pType,
            /* [out] */ GUID *pVolId,
            /* [out] */ LONGLONG *pDeletedBagAmount,
            /* [out] */ SHORT *pRemoteDataSet) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetBagInfo( 
            /* [in] */ HSM_BAG_STATUS status,
            /* [in] */ GUID bagId,
            /* [in] */ FILETIME birthDate,
            /* [in] */ LONGLONG len,
            /* [in] */ USHORT type,
            /* [in] */ GUID volId,
            /* [in] */ LONGLONG deletedBagAmount,
            /* [in] */ SHORT remoteDataSet) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IBagInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IBagInfo * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IBagInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IBagInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IBagInfo * This,
            /* [in] */ REFIID riid,
            /* [iid_is][retval][out] */ void **ppEntity);
        
        HRESULT ( STDMETHODCALLTYPE *Disconnect )( 
            IBagInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *FindEQ )( 
            IBagInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *FindGT )( 
            IBagInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *FindGTE )( 
            IBagInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *FindLT )( 
            IBagInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *FindLTE )( 
            IBagInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *First )( 
            IBagInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Last )( 
            IBagInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *MarkAsNew )( 
            IBagInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IBagInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Previous )( 
            IBagInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Print )( 
            IBagInfo * This,
            /* [in] */ IStream *pStream);
        
        HRESULT ( STDMETHODCALLTYPE *Remove )( 
            IBagInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *UpdateKey )( 
            IBagInfo * This,
            /* [in] */ IWsbDbKey *pKey);
        
        HRESULT ( STDMETHODCALLTYPE *UseKey )( 
            IBagInfo * This,
            /* [in] */ ULONG type);
        
        HRESULT ( STDMETHODCALLTYPE *Write )( 
            IBagInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetSequentialScan )( 
            IBagInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *ResetSequentialScan )( 
            IBagInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetBagInfo )( 
            IBagInfo * This,
            /* [out] */ HSM_BAG_STATUS *pStatus,
            /* [out] */ GUID *pBagId,
            /* [out] */ FILETIME *pBirthDate,
            /* [out] */ LONGLONG *pLen,
            /* [out] */ USHORT *pType,
            /* [out] */ GUID *pVolId,
            /* [out] */ LONGLONG *pDeletedBagAmount,
            /* [out] */ SHORT *pRemoteDataSet);
        
        HRESULT ( STDMETHODCALLTYPE *SetBagInfo )( 
            IBagInfo * This,
            /* [in] */ HSM_BAG_STATUS status,
            /* [in] */ GUID bagId,
            /* [in] */ FILETIME birthDate,
            /* [in] */ LONGLONG len,
            /* [in] */ USHORT type,
            /* [in] */ GUID volId,
            /* [in] */ LONGLONG deletedBagAmount,
            /* [in] */ SHORT remoteDataSet);
        
        END_INTERFACE
    } IBagInfoVtbl;

    interface IBagInfo
    {
        CONST_VTBL struct IBagInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IBagInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IBagInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IBagInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IBagInfo_Clone(This,riid,ppEntity)	\
    (This)->lpVtbl -> Clone(This,riid,ppEntity)

#define IBagInfo_Disconnect(This)	\
    (This)->lpVtbl -> Disconnect(This)

#define IBagInfo_FindEQ(This)	\
    (This)->lpVtbl -> FindEQ(This)

#define IBagInfo_FindGT(This)	\
    (This)->lpVtbl -> FindGT(This)

#define IBagInfo_FindGTE(This)	\
    (This)->lpVtbl -> FindGTE(This)

#define IBagInfo_FindLT(This)	\
    (This)->lpVtbl -> FindLT(This)

#define IBagInfo_FindLTE(This)	\
    (This)->lpVtbl -> FindLTE(This)

#define IBagInfo_First(This)	\
    (This)->lpVtbl -> First(This)

#define IBagInfo_Last(This)	\
    (This)->lpVtbl -> Last(This)

#define IBagInfo_MarkAsNew(This)	\
    (This)->lpVtbl -> MarkAsNew(This)

#define IBagInfo_Next(This)	\
    (This)->lpVtbl -> Next(This)

#define IBagInfo_Previous(This)	\
    (This)->lpVtbl -> Previous(This)

#define IBagInfo_Print(This,pStream)	\
    (This)->lpVtbl -> Print(This,pStream)

#define IBagInfo_Remove(This)	\
    (This)->lpVtbl -> Remove(This)

#define IBagInfo_UpdateKey(This,pKey)	\
    (This)->lpVtbl -> UpdateKey(This,pKey)

#define IBagInfo_UseKey(This,type)	\
    (This)->lpVtbl -> UseKey(This,type)

#define IBagInfo_Write(This)	\
    (This)->lpVtbl -> Write(This)

#define IBagInfo_SetSequentialScan(This)	\
    (This)->lpVtbl -> SetSequentialScan(This)

#define IBagInfo_ResetSequentialScan(This)	\
    (This)->lpVtbl -> ResetSequentialScan(This)


#define IBagInfo_GetBagInfo(This,pStatus,pBagId,pBirthDate,pLen,pType,pVolId,pDeletedBagAmount,pRemoteDataSet)	\
    (This)->lpVtbl -> GetBagInfo(This,pStatus,pBagId,pBirthDate,pLen,pType,pVolId,pDeletedBagAmount,pRemoteDataSet)

#define IBagInfo_SetBagInfo(This,status,bagId,birthDate,len,type,volId,deletedBagAmount,remoteDataSet)	\
    (This)->lpVtbl -> SetBagInfo(This,status,bagId,birthDate,len,type,volId,deletedBagAmount,remoteDataSet)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IBagInfo_GetBagInfo_Proxy( 
    IBagInfo * This,
    /* [out] */ HSM_BAG_STATUS *pStatus,
    /* [out] */ GUID *pBagId,
    /* [out] */ FILETIME *pBirthDate,
    /* [out] */ LONGLONG *pLen,
    /* [out] */ USHORT *pType,
    /* [out] */ GUID *pVolId,
    /* [out] */ LONGLONG *pDeletedBagAmount,
    /* [out] */ SHORT *pRemoteDataSet);


void __RPC_STUB IBagInfo_GetBagInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IBagInfo_SetBagInfo_Proxy( 
    IBagInfo * This,
    /* [in] */ HSM_BAG_STATUS status,
    /* [in] */ GUID bagId,
    /* [in] */ FILETIME birthDate,
    /* [in] */ LONGLONG len,
    /* [in] */ USHORT type,
    /* [in] */ GUID volId,
    /* [in] */ LONGLONG deletedBagAmount,
    /* [in] */ SHORT remoteDataSet);


void __RPC_STUB IBagInfo_SetBagInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IBagInfo_INTERFACE_DEFINED__ */


#ifndef __IMediaInfo_INTERFACE_DEFINED__
#define __IMediaInfo_INTERFACE_DEFINED__

/* interface IMediaInfo */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IMediaInfo;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("072E876C-B1CD-4344-A038-4668E931DDAD")
    IMediaInfo : public IWsbDbEntity
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetCapacity( 
            /* [out] */ LONGLONG *pCapacity) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCopyDescription( 
            /* [in] */ USHORT copyNumber,
            /* [string][out] */ OLECHAR **pDescription,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCopyInfo( 
            /* [in] */ USHORT copyNumber,
            /* [out] */ GUID *pMediaSubsystemId,
            /* [string][out] */ OLECHAR **pDescription,
            /* [in] */ ULONG descriptionBufferSize,
            /* [string][out] */ OLECHAR **pName,
            /* [in] */ ULONG nameBufferSize,
            /* [out] */ FILETIME *pUpdate,
            /* [out] */ HRESULT *pLastError,
            /* [out] */ SHORT *pNextRemoteDataSet) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCopyLastError( 
            /* [in] */ USHORT copyNumber,
            /* [out] */ HRESULT *pLastError) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCopyMediaSubsystemId( 
            /* [in] */ USHORT copyNumber,
            /* [out] */ GUID *pMediaSubsystemId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCopyName( 
            /* [in] */ USHORT copyNumber,
            /* [string][out] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCopyNextRemoteDataSet( 
            /* [in] */ USHORT copyNumber,
            /* [out] */ SHORT *pNextRemoteDataSet) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCopyUpdate( 
            /* [in] */ USHORT copyNumber,
            /* [out] */ FILETIME *pUpdate) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDescription( 
            /* [string][out] */ OLECHAR **pDescription,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFreeBytes( 
            /* [out] */ LONGLONG *pFreeBytes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetId( 
            /* [out] */ GUID *pId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLastError( 
            /* [out] */ HRESULT *pLastError) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLastKnownGoodMasterInfo( 
            /* [out] */ GUID *pMediaId,
            /* [out] */ GUID *pMediaSubsystemId,
            /* [out] */ GUID *pStoragePoolId,
            /* [out] */ LONGLONG *pFreeBytes,
            /* [out] */ LONGLONG *pCapacity,
            /* [out] */ HRESULT *pLastError,
            /* [string][out] */ OLECHAR **pDescription,
            /* [in] */ ULONG descriptionBufferSize,
            /* [out] */ HSM_JOB_MEDIA_TYPE *pType,
            /* [string][out] */ OLECHAR **pName,
            /* [in] */ ULONG nameBufferSize,
            /* [out] */ BOOL *pReadOnly,
            /* [out] */ FILETIME *pUpdate,
            /* [out] */ SHORT *pNextRemoteDataSet) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLKGMasterNextRemoteDataSet( 
            /* [out] */ short *pNextRemoteDataSet) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetLogicalValidBytes( 
            /* [out] */ LONGLONG *pLogicalValidBytes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMediaInfo( 
            /* [out] */ GUID *pMediaId,
            /* [out] */ GUID *pMediaSubsystemId,
            /* [out] */ GUID *pStoragePoolId,
            /* [out] */ LONGLONG *pFreeBytes,
            /* [out] */ LONGLONG *pCapacity,
            /* [out] */ HRESULT *pLastError,
            /* [out] */ short *pNextRemoteDataSet,
            /* [string][out] */ OLECHAR **pDescription,
            /* [in] */ ULONG descriptionBufferSize,
            /* [out] */ HSM_JOB_MEDIA_TYPE *pType,
            /* [string][out] */ OLECHAR **pName,
            /* [in] */ ULONG nameBufferSize,
            /* [out] */ BOOL *pReadOnly,
            /* [out] */ FILETIME *pUpdate,
            /* [out] */ LONGLONG *pLogicalValidBytes,
            /* [out] */ BOOL *pRecreate) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMediaSubsystemId( 
            /* [out] */ GUID *pRmsMediaId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetName( 
            /* [string][out] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNextRemoteDataSet( 
            /* [out] */ short *pNextRemoteDataSet) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecallOnlyStatus( 
            /* [out] */ BOOL *pRecallOnlyStatus) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRecreate( 
            /* [out] */ BOOL *pRecreate) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStoragePoolId( 
            /* [out] */ GUID *pStoragePoolId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetType( 
            /* [out] */ HSM_JOB_MEDIA_TYPE *pType) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUpdate( 
            /* [out] */ FILETIME *pUpdate) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetName( 
            /* [string][in] */ OLECHAR *name) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCapacity( 
            /* [in] */ LONGLONG capacity) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCopyName( 
            /* [in] */ USHORT copyNumber,
            /* [string][in] */ OLECHAR *name) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCopyNextRemoteDataSet( 
            /* [in] */ USHORT copyNumber,
            /* [in] */ SHORT nextRemoteDataSet) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCopyDescription( 
            /* [in] */ USHORT copyNumber,
            /* [string][in] */ OLECHAR *description) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCopyInfo( 
            /* [in] */ USHORT copyNumber,
            /* [in] */ GUID mediaSybsystemMediaId,
            /* [string][in] */ OLECHAR *description,
            /* [string][in] */ OLECHAR *name,
            /* [in] */ FILETIME update,
            /* [in] */ HRESULT lastError,
            /* [in] */ SHORT nextRemoteDataSet) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCopyLastError( 
            /* [in] */ USHORT copyNumber,
            /* [in] */ HRESULT lastError) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCopyMediaSubsystemId( 
            /* [in] */ USHORT copyNumber,
            /* [in] */ GUID mediaSybsystemMediaId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCopyUpdate( 
            /* [in] */ USHORT copyNumber,
            /* [in] */ FILETIME update) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetDescription( 
            /* [string][in] */ OLECHAR *description) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetId( 
            /* [in] */ GUID id) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetFreeBytes( 
            /* [in] */ LONGLONG FreeBytes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetLastError( 
            /* [in] */ HRESULT lastError) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetLastKnownGoodMasterInfo( 
            /* [in] */ GUID mediaId,
            /* [in] */ GUID mediaSubsystemMediaId,
            /* [in] */ GUID storagePoolId,
            /* [in] */ LONGLONG FreeBytes,
            /* [in] */ LONGLONG Capacity,
            /* [in] */ HRESULT lastError,
            /* [string][in] */ OLECHAR *description,
            /* [in] */ HSM_JOB_MEDIA_TYPE type,
            /* [string][in] */ OLECHAR *name,
            /* [in] */ BOOL readOnly,
            /* [in] */ FILETIME update,
            /* [in] */ SHORT nextRemoteDataSet) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetLogicalValidBytes( 
            /* [in] */ LONGLONG logicalValidBytes) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMediaInfo( 
            /* [in] */ GUID mediaId,
            /* [in] */ GUID mediaSubsystemMediaId,
            /* [in] */ GUID storagePoolId,
            /* [in] */ LONGLONG FreeBytes,
            /* [in] */ LONGLONG Capacity,
            /* [in] */ HRESULT lastError,
            /* [in] */ short nextRemoteDataSet,
            /* [string][in] */ OLECHAR *description,
            /* [in] */ HSM_JOB_MEDIA_TYPE type,
            /* [string][in] */ OLECHAR *name,
            /* [in] */ BOOL readOnly,
            /* [in] */ FILETIME update,
            /* [in] */ LONGLONG logicalValidBytes,
            /* [in] */ BOOL recreate) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMediaSubsystemId( 
            /* [in] */ GUID rmsMediaId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetNextRemoteDataSet( 
            /* [in] */ short nextRemoteDataSet) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRecallOnlyStatus( 
            /* [in] */ BOOL readOnlyStatus) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetRecreate( 
            /* [in] */ BOOL recreate) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetStoragePoolId( 
            /* [in] */ GUID storagePoolId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetType( 
            /* [in] */ HSM_JOB_MEDIA_TYPE type) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetUpdate( 
            /* [in] */ FILETIME update) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DeleteCopy( 
            /* [in] */ USHORT copyNumber) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RecreateMaster( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UpdateLastKnownGoodMaster( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMediaInfoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMediaInfo * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMediaInfo * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMediaInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IMediaInfo * This,
            /* [in] */ REFIID riid,
            /* [iid_is][retval][out] */ void **ppEntity);
        
        HRESULT ( STDMETHODCALLTYPE *Disconnect )( 
            IMediaInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *FindEQ )( 
            IMediaInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *FindGT )( 
            IMediaInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *FindGTE )( 
            IMediaInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *FindLT )( 
            IMediaInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *FindLTE )( 
            IMediaInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *First )( 
            IMediaInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Last )( 
            IMediaInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *MarkAsNew )( 
            IMediaInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IMediaInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Previous )( 
            IMediaInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *Print )( 
            IMediaInfo * This,
            /* [in] */ IStream *pStream);
        
        HRESULT ( STDMETHODCALLTYPE *Remove )( 
            IMediaInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *UpdateKey )( 
            IMediaInfo * This,
            /* [in] */ IWsbDbKey *pKey);
        
        HRESULT ( STDMETHODCALLTYPE *UseKey )( 
            IMediaInfo * This,
            /* [in] */ ULONG type);
        
        HRESULT ( STDMETHODCALLTYPE *Write )( 
            IMediaInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetSequentialScan )( 
            IMediaInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *ResetSequentialScan )( 
            IMediaInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetCapacity )( 
            IMediaInfo * This,
            /* [out] */ LONGLONG *pCapacity);
        
        HRESULT ( STDMETHODCALLTYPE *GetCopyDescription )( 
            IMediaInfo * This,
            /* [in] */ USHORT copyNumber,
            /* [string][out] */ OLECHAR **pDescription,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetCopyInfo )( 
            IMediaInfo * This,
            /* [in] */ USHORT copyNumber,
            /* [out] */ GUID *pMediaSubsystemId,
            /* [string][out] */ OLECHAR **pDescription,
            /* [in] */ ULONG descriptionBufferSize,
            /* [string][out] */ OLECHAR **pName,
            /* [in] */ ULONG nameBufferSize,
            /* [out] */ FILETIME *pUpdate,
            /* [out] */ HRESULT *pLastError,
            /* [out] */ SHORT *pNextRemoteDataSet);
        
        HRESULT ( STDMETHODCALLTYPE *GetCopyLastError )( 
            IMediaInfo * This,
            /* [in] */ USHORT copyNumber,
            /* [out] */ HRESULT *pLastError);
        
        HRESULT ( STDMETHODCALLTYPE *GetCopyMediaSubsystemId )( 
            IMediaInfo * This,
            /* [in] */ USHORT copyNumber,
            /* [out] */ GUID *pMediaSubsystemId);
        
        HRESULT ( STDMETHODCALLTYPE *GetCopyName )( 
            IMediaInfo * This,
            /* [in] */ USHORT copyNumber,
            /* [string][out] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetCopyNextRemoteDataSet )( 
            IMediaInfo * This,
            /* [in] */ USHORT copyNumber,
            /* [out] */ SHORT *pNextRemoteDataSet);
        
        HRESULT ( STDMETHODCALLTYPE *GetCopyUpdate )( 
            IMediaInfo * This,
            /* [in] */ USHORT copyNumber,
            /* [out] */ FILETIME *pUpdate);
        
        HRESULT ( STDMETHODCALLTYPE *GetDescription )( 
            IMediaInfo * This,
            /* [string][out] */ OLECHAR **pDescription,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetFreeBytes )( 
            IMediaInfo * This,
            /* [out] */ LONGLONG *pFreeBytes);
        
        HRESULT ( STDMETHODCALLTYPE *GetId )( 
            IMediaInfo * This,
            /* [out] */ GUID *pId);
        
        HRESULT ( STDMETHODCALLTYPE *GetLastError )( 
            IMediaInfo * This,
            /* [out] */ HRESULT *pLastError);
        
        HRESULT ( STDMETHODCALLTYPE *GetLastKnownGoodMasterInfo )( 
            IMediaInfo * This,
            /* [out] */ GUID *pMediaId,
            /* [out] */ GUID *pMediaSubsystemId,
            /* [out] */ GUID *pStoragePoolId,
            /* [out] */ LONGLONG *pFreeBytes,
            /* [out] */ LONGLONG *pCapacity,
            /* [out] */ HRESULT *pLastError,
            /* [string][out] */ OLECHAR **pDescription,
            /* [in] */ ULONG descriptionBufferSize,
            /* [out] */ HSM_JOB_MEDIA_TYPE *pType,
            /* [string][out] */ OLECHAR **pName,
            /* [in] */ ULONG nameBufferSize,
            /* [out] */ BOOL *pReadOnly,
            /* [out] */ FILETIME *pUpdate,
            /* [out] */ SHORT *pNextRemoteDataSet);
        
        HRESULT ( STDMETHODCALLTYPE *GetLKGMasterNextRemoteDataSet )( 
            IMediaInfo * This,
            /* [out] */ short *pNextRemoteDataSet);
        
        HRESULT ( STDMETHODCALLTYPE *GetLogicalValidBytes )( 
            IMediaInfo * This,
            /* [out] */ LONGLONG *pLogicalValidBytes);
        
        HRESULT ( STDMETHODCALLTYPE *GetMediaInfo )( 
            IMediaInfo * This,
            /* [out] */ GUID *pMediaId,
            /* [out] */ GUID *pMediaSubsystemId,
            /* [out] */ GUID *pStoragePoolId,
            /* [out] */ LONGLONG *pFreeBytes,
            /* [out] */ LONGLONG *pCapacity,
            /* [out] */ HRESULT *pLastError,
            /* [out] */ short *pNextRemoteDataSet,
            /* [string][out] */ OLECHAR **pDescription,
            /* [in] */ ULONG descriptionBufferSize,
            /* [out] */ HSM_JOB_MEDIA_TYPE *pType,
            /* [string][out] */ OLECHAR **pName,
            /* [in] */ ULONG nameBufferSize,
            /* [out] */ BOOL *pReadOnly,
            /* [out] */ FILETIME *pUpdate,
            /* [out] */ LONGLONG *pLogicalValidBytes,
            /* [out] */ BOOL *pRecreate);
        
        HRESULT ( STDMETHODCALLTYPE *GetMediaSubsystemId )( 
            IMediaInfo * This,
            /* [out] */ GUID *pRmsMediaId);
        
        HRESULT ( STDMETHODCALLTYPE *GetName )( 
            IMediaInfo * This,
            /* [string][out] */ OLECHAR **pName,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetNextRemoteDataSet )( 
            IMediaInfo * This,
            /* [out] */ short *pNextRemoteDataSet);
        
        HRESULT ( STDMETHODCALLTYPE *GetRecallOnlyStatus )( 
            IMediaInfo * This,
            /* [out] */ BOOL *pRecallOnlyStatus);
        
        HRESULT ( STDMETHODCALLTYPE *GetRecreate )( 
            IMediaInfo * This,
            /* [out] */ BOOL *pRecreate);
        
        HRESULT ( STDMETHODCALLTYPE *GetStoragePoolId )( 
            IMediaInfo * This,
            /* [out] */ GUID *pStoragePoolId);
        
        HRESULT ( STDMETHODCALLTYPE *GetType )( 
            IMediaInfo * This,
            /* [out] */ HSM_JOB_MEDIA_TYPE *pType);
        
        HRESULT ( STDMETHODCALLTYPE *GetUpdate )( 
            IMediaInfo * This,
            /* [out] */ FILETIME *pUpdate);
        
        HRESULT ( STDMETHODCALLTYPE *SetName )( 
            IMediaInfo * This,
            /* [string][in] */ OLECHAR *name);
        
        HRESULT ( STDMETHODCALLTYPE *SetCapacity )( 
            IMediaInfo * This,
            /* [in] */ LONGLONG capacity);
        
        HRESULT ( STDMETHODCALLTYPE *SetCopyName )( 
            IMediaInfo * This,
            /* [in] */ USHORT copyNumber,
            /* [string][in] */ OLECHAR *name);
        
        HRESULT ( STDMETHODCALLTYPE *SetCopyNextRemoteDataSet )( 
            IMediaInfo * This,
            /* [in] */ USHORT copyNumber,
            /* [in] */ SHORT nextRemoteDataSet);
        
        HRESULT ( STDMETHODCALLTYPE *SetCopyDescription )( 
            IMediaInfo * This,
            /* [in] */ USHORT copyNumber,
            /* [string][in] */ OLECHAR *description);
        
        HRESULT ( STDMETHODCALLTYPE *SetCopyInfo )( 
            IMediaInfo * This,
            /* [in] */ USHORT copyNumber,
            /* [in] */ GUID mediaSybsystemMediaId,
            /* [string][in] */ OLECHAR *description,
            /* [string][in] */ OLECHAR *name,
            /* [in] */ FILETIME update,
            /* [in] */ HRESULT lastError,
            /* [in] */ SHORT nextRemoteDataSet);
        
        HRESULT ( STDMETHODCALLTYPE *SetCopyLastError )( 
            IMediaInfo * This,
            /* [in] */ USHORT copyNumber,
            /* [in] */ HRESULT lastError);
        
        HRESULT ( STDMETHODCALLTYPE *SetCopyMediaSubsystemId )( 
            IMediaInfo * This,
            /* [in] */ USHORT copyNumber,
            /* [in] */ GUID mediaSybsystemMediaId);
        
        HRESULT ( STDMETHODCALLTYPE *SetCopyUpdate )( 
            IMediaInfo * This,
            /* [in] */ USHORT copyNumber,
            /* [in] */ FILETIME update);
        
        HRESULT ( STDMETHODCALLTYPE *SetDescription )( 
            IMediaInfo * This,
            /* [string][in] */ OLECHAR *description);
        
        HRESULT ( STDMETHODCALLTYPE *SetId )( 
            IMediaInfo * This,
            /* [in] */ GUID id);
        
        HRESULT ( STDMETHODCALLTYPE *SetFreeBytes )( 
            IMediaInfo * This,
            /* [in] */ LONGLONG FreeBytes);
        
        HRESULT ( STDMETHODCALLTYPE *SetLastError )( 
            IMediaInfo * This,
            /* [in] */ HRESULT lastError);
        
        HRESULT ( STDMETHODCALLTYPE *SetLastKnownGoodMasterInfo )( 
            IMediaInfo * This,
            /* [in] */ GUID mediaId,
            /* [in] */ GUID mediaSubsystemMediaId,
            /* [in] */ GUID storagePoolId,
            /* [in] */ LONGLONG FreeBytes,
            /* [in] */ LONGLONG Capacity,
            /* [in] */ HRESULT lastError,
            /* [string][in] */ OLECHAR *description,
            /* [in] */ HSM_JOB_MEDIA_TYPE type,
            /* [string][in] */ OLECHAR *name,
            /* [in] */ BOOL readOnly,
            /* [in] */ FILETIME update,
            /* [in] */ SHORT nextRemoteDataSet);
        
        HRESULT ( STDMETHODCALLTYPE *SetLogicalValidBytes )( 
            IMediaInfo * This,
            /* [in] */ LONGLONG logicalValidBytes);
        
        HRESULT ( STDMETHODCALLTYPE *SetMediaInfo )( 
            IMediaInfo * This,
            /* [in] */ GUID mediaId,
            /* [in] */ GUID mediaSubsystemMediaId,
            /* [in] */ GUID storagePoolId,
            /* [in] */ LONGLONG FreeBytes,
            /* [in] */ LONGLONG Capacity,
            /* [in] */ HRESULT lastError,
            /* [in] */ short nextRemoteDataSet,
            /* [string][in] */ OLECHAR *description,
            /* [in] */ HSM_JOB_MEDIA_TYPE type,
            /* [string][in] */ OLECHAR *name,
            /* [in] */ BOOL readOnly,
            /* [in] */ FILETIME update,
            /* [in] */ LONGLONG logicalValidBytes,
            /* [in] */ BOOL recreate);
        
        HRESULT ( STDMETHODCALLTYPE *SetMediaSubsystemId )( 
            IMediaInfo * This,
            /* [in] */ GUID rmsMediaId);
        
        HRESULT ( STDMETHODCALLTYPE *SetNextRemoteDataSet )( 
            IMediaInfo * This,
            /* [in] */ short nextRemoteDataSet);
        
        HRESULT ( STDMETHODCALLTYPE *SetRecallOnlyStatus )( 
            IMediaInfo * This,
            /* [in] */ BOOL readOnlyStatus);
        
        HRESULT ( STDMETHODCALLTYPE *SetRecreate )( 
            IMediaInfo * This,
            /* [in] */ BOOL recreate);
        
        HRESULT ( STDMETHODCALLTYPE *SetStoragePoolId )( 
            IMediaInfo * This,
            /* [in] */ GUID storagePoolId);
        
        HRESULT ( STDMETHODCALLTYPE *SetType )( 
            IMediaInfo * This,
            /* [in] */ HSM_JOB_MEDIA_TYPE type);
        
        HRESULT ( STDMETHODCALLTYPE *SetUpdate )( 
            IMediaInfo * This,
            /* [in] */ FILETIME update);
        
        HRESULT ( STDMETHODCALLTYPE *DeleteCopy )( 
            IMediaInfo * This,
            /* [in] */ USHORT copyNumber);
        
        HRESULT ( STDMETHODCALLTYPE *RecreateMaster )( 
            IMediaInfo * This);
        
        HRESULT ( STDMETHODCALLTYPE *UpdateLastKnownGoodMaster )( 
            IMediaInfo * This);
        
        END_INTERFACE
    } IMediaInfoVtbl;

    interface IMediaInfo
    {
        CONST_VTBL struct IMediaInfoVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMediaInfo_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IMediaInfo_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IMediaInfo_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IMediaInfo_Clone(This,riid,ppEntity)	\
    (This)->lpVtbl -> Clone(This,riid,ppEntity)

#define IMediaInfo_Disconnect(This)	\
    (This)->lpVtbl -> Disconnect(This)

#define IMediaInfo_FindEQ(This)	\
    (This)->lpVtbl -> FindEQ(This)

#define IMediaInfo_FindGT(This)	\
    (This)->lpVtbl -> FindGT(This)

#define IMediaInfo_FindGTE(This)	\
    (This)->lpVtbl -> FindGTE(This)

#define IMediaInfo_FindLT(This)	\
    (This)->lpVtbl -> FindLT(This)

#define IMediaInfo_FindLTE(This)	\
    (This)->lpVtbl -> FindLTE(This)

#define IMediaInfo_First(This)	\
    (This)->lpVtbl -> First(This)

#define IMediaInfo_Last(This)	\
    (This)->lpVtbl -> Last(This)

#define IMediaInfo_MarkAsNew(This)	\
    (This)->lpVtbl -> MarkAsNew(This)

#define IMediaInfo_Next(This)	\
    (This)->lpVtbl -> Next(This)

#define IMediaInfo_Previous(This)	\
    (This)->lpVtbl -> Previous(This)

#define IMediaInfo_Print(This,pStream)	\
    (This)->lpVtbl -> Print(This,pStream)

#define IMediaInfo_Remove(This)	\
    (This)->lpVtbl -> Remove(This)

#define IMediaInfo_UpdateKey(This,pKey)	\
    (This)->lpVtbl -> UpdateKey(This,pKey)

#define IMediaInfo_UseKey(This,type)	\
    (This)->lpVtbl -> UseKey(This,type)

#define IMediaInfo_Write(This)	\
    (This)->lpVtbl -> Write(This)

#define IMediaInfo_SetSequentialScan(This)	\
    (This)->lpVtbl -> SetSequentialScan(This)

#define IMediaInfo_ResetSequentialScan(This)	\
    (This)->lpVtbl -> ResetSequentialScan(This)


#define IMediaInfo_GetCapacity(This,pCapacity)	\
    (This)->lpVtbl -> GetCapacity(This,pCapacity)

#define IMediaInfo_GetCopyDescription(This,copyNumber,pDescription,bufferSize)	\
    (This)->lpVtbl -> GetCopyDescription(This,copyNumber,pDescription,bufferSize)

#define IMediaInfo_GetCopyInfo(This,copyNumber,pMediaSubsystemId,pDescription,descriptionBufferSize,pName,nameBufferSize,pUpdate,pLastError,pNextRemoteDataSet)	\
    (This)->lpVtbl -> GetCopyInfo(This,copyNumber,pMediaSubsystemId,pDescription,descriptionBufferSize,pName,nameBufferSize,pUpdate,pLastError,pNextRemoteDataSet)

#define IMediaInfo_GetCopyLastError(This,copyNumber,pLastError)	\
    (This)->lpVtbl -> GetCopyLastError(This,copyNumber,pLastError)

#define IMediaInfo_GetCopyMediaSubsystemId(This,copyNumber,pMediaSubsystemId)	\
    (This)->lpVtbl -> GetCopyMediaSubsystemId(This,copyNumber,pMediaSubsystemId)

#define IMediaInfo_GetCopyName(This,copyNumber,pName,bufferSize)	\
    (This)->lpVtbl -> GetCopyName(This,copyNumber,pName,bufferSize)

#define IMediaInfo_GetCopyNextRemoteDataSet(This,copyNumber,pNextRemoteDataSet)	\
    (This)->lpVtbl -> GetCopyNextRemoteDataSet(This,copyNumber,pNextRemoteDataSet)

#define IMediaInfo_GetCopyUpdate(This,copyNumber,pUpdate)	\
    (This)->lpVtbl -> GetCopyUpdate(This,copyNumber,pUpdate)

#define IMediaInfo_GetDescription(This,pDescription,bufferSize)	\
    (This)->lpVtbl -> GetDescription(This,pDescription,bufferSize)

#define IMediaInfo_GetFreeBytes(This,pFreeBytes)	\
    (This)->lpVtbl -> GetFreeBytes(This,pFreeBytes)

#define IMediaInfo_GetId(This,pId)	\
    (This)->lpVtbl -> GetId(This,pId)

#define IMediaInfo_GetLastError(This,pLastError)	\
    (This)->lpVtbl -> GetLastError(This,pLastError)

#define IMediaInfo_GetLastKnownGoodMasterInfo(This,pMediaId,pMediaSubsystemId,pStoragePoolId,pFreeBytes,pCapacity,pLastError,pDescription,descriptionBufferSize,pType,pName,nameBufferSize,pReadOnly,pUpdate,pNextRemoteDataSet)	\
    (This)->lpVtbl -> GetLastKnownGoodMasterInfo(This,pMediaId,pMediaSubsystemId,pStoragePoolId,pFreeBytes,pCapacity,pLastError,pDescription,descriptionBufferSize,pType,pName,nameBufferSize,pReadOnly,pUpdate,pNextRemoteDataSet)

#define IMediaInfo_GetLKGMasterNextRemoteDataSet(This,pNextRemoteDataSet)	\
    (This)->lpVtbl -> GetLKGMasterNextRemoteDataSet(This,pNextRemoteDataSet)

#define IMediaInfo_GetLogicalValidBytes(This,pLogicalValidBytes)	\
    (This)->lpVtbl -> GetLogicalValidBytes(This,pLogicalValidBytes)

#define IMediaInfo_GetMediaInfo(This,pMediaId,pMediaSubsystemId,pStoragePoolId,pFreeBytes,pCapacity,pLastError,pNextRemoteDataSet,pDescription,descriptionBufferSize,pType,pName,nameBufferSize,pReadOnly,pUpdate,pLogicalValidBytes,pRecreate)	\
    (This)->lpVtbl -> GetMediaInfo(This,pMediaId,pMediaSubsystemId,pStoragePoolId,pFreeBytes,pCapacity,pLastError,pNextRemoteDataSet,pDescription,descriptionBufferSize,pType,pName,nameBufferSize,pReadOnly,pUpdate,pLogicalValidBytes,pRecreate)

#define IMediaInfo_GetMediaSubsystemId(This,pRmsMediaId)	\
    (This)->lpVtbl -> GetMediaSubsystemId(This,pRmsMediaId)

#define IMediaInfo_GetName(This,pName,bufferSize)	\
    (This)->lpVtbl -> GetName(This,pName,bufferSize)

#define IMediaInfo_GetNextRemoteDataSet(This,pNextRemoteDataSet)	\
    (This)->lpVtbl -> GetNextRemoteDataSet(This,pNextRemoteDataSet)

#define IMediaInfo_GetRecallOnlyStatus(This,pRecallOnlyStatus)	\
    (This)->lpVtbl -> GetRecallOnlyStatus(This,pRecallOnlyStatus)

#define IMediaInfo_GetRecreate(This,pRecreate)	\
    (This)->lpVtbl -> GetRecreate(This,pRecreate)

#define IMediaInfo_GetStoragePoolId(This,pStoragePoolId)	\
    (This)->lpVtbl -> GetStoragePoolId(This,pStoragePoolId)

#define IMediaInfo_GetType(This,pType)	\
    (This)->lpVtbl -> GetType(This,pType)

#define IMediaInfo_GetUpdate(This,pUpdate)	\
    (This)->lpVtbl -> GetUpdate(This,pUpdate)

#define IMediaInfo_SetName(This,name)	\
    (This)->lpVtbl -> SetName(This,name)

#define IMediaInfo_SetCapacity(This,capacity)	\
    (This)->lpVtbl -> SetCapacity(This,capacity)

#define IMediaInfo_SetCopyName(This,copyNumber,name)	\
    (This)->lpVtbl -> SetCopyName(This,copyNumber,name)

#define IMediaInfo_SetCopyNextRemoteDataSet(This,copyNumber,nextRemoteDataSet)	\
    (This)->lpVtbl -> SetCopyNextRemoteDataSet(This,copyNumber,nextRemoteDataSet)

#define IMediaInfo_SetCopyDescription(This,copyNumber,description)	\
    (This)->lpVtbl -> SetCopyDescription(This,copyNumber,description)

#define IMediaInfo_SetCopyInfo(This,copyNumber,mediaSybsystemMediaId,description,name,update,lastError,nextRemoteDataSet)	\
    (This)->lpVtbl -> SetCopyInfo(This,copyNumber,mediaSybsystemMediaId,description,name,update,lastError,nextRemoteDataSet)

#define IMediaInfo_SetCopyLastError(This,copyNumber,lastError)	\
    (This)->lpVtbl -> SetCopyLastError(This,copyNumber,lastError)

#define IMediaInfo_SetCopyMediaSubsystemId(This,copyNumber,mediaSybsystemMediaId)	\
    (This)->lpVtbl -> SetCopyMediaSubsystemId(This,copyNumber,mediaSybsystemMediaId)

#define IMediaInfo_SetCopyUpdate(This,copyNumber,update)	\
    (This)->lpVtbl -> SetCopyUpdate(This,copyNumber,update)

#define IMediaInfo_SetDescription(This,description)	\
    (This)->lpVtbl -> SetDescription(This,description)

#define IMediaInfo_SetId(This,id)	\
    (This)->lpVtbl -> SetId(This,id)

#define IMediaInfo_SetFreeBytes(This,FreeBytes)	\
    (This)->lpVtbl -> SetFreeBytes(This,FreeBytes)

#define IMediaInfo_SetLastError(This,lastError)	\
    (This)->lpVtbl -> SetLastError(This,lastError)

#define IMediaInfo_SetLastKnownGoodMasterInfo(This,mediaId,mediaSubsystemMediaId,storagePoolId,FreeBytes,Capacity,lastError,description,type,name,readOnly,update,nextRemoteDataSet)	\
    (This)->lpVtbl -> SetLastKnownGoodMasterInfo(This,mediaId,mediaSubsystemMediaId,storagePoolId,FreeBytes,Capacity,lastError,description,type,name,readOnly,update,nextRemoteDataSet)

#define IMediaInfo_SetLogicalValidBytes(This,logicalValidBytes)	\
    (This)->lpVtbl -> SetLogicalValidBytes(This,logicalValidBytes)

#define IMediaInfo_SetMediaInfo(This,mediaId,mediaSubsystemMediaId,storagePoolId,FreeBytes,Capacity,lastError,nextRemoteDataSet,description,type,name,readOnly,update,logicalValidBytes,recreate)	\
    (This)->lpVtbl -> SetMediaInfo(This,mediaId,mediaSubsystemMediaId,storagePoolId,FreeBytes,Capacity,lastError,nextRemoteDataSet,description,type,name,readOnly,update,logicalValidBytes,recreate)

#define IMediaInfo_SetMediaSubsystemId(This,rmsMediaId)	\
    (This)->lpVtbl -> SetMediaSubsystemId(This,rmsMediaId)

#define IMediaInfo_SetNextRemoteDataSet(This,nextRemoteDataSet)	\
    (This)->lpVtbl -> SetNextRemoteDataSet(This,nextRemoteDataSet)

#define IMediaInfo_SetRecallOnlyStatus(This,readOnlyStatus)	\
    (This)->lpVtbl -> SetRecallOnlyStatus(This,readOnlyStatus)

#define IMediaInfo_SetRecreate(This,recreate)	\
    (This)->lpVtbl -> SetRecreate(This,recreate)

#define IMediaInfo_SetStoragePoolId(This,storagePoolId)	\
    (This)->lpVtbl -> SetStoragePoolId(This,storagePoolId)

#define IMediaInfo_SetType(This,type)	\
    (This)->lpVtbl -> SetType(This,type)

#define IMediaInfo_SetUpdate(This,update)	\
    (This)->lpVtbl -> SetUpdate(This,update)

#define IMediaInfo_DeleteCopy(This,copyNumber)	\
    (This)->lpVtbl -> DeleteCopy(This,copyNumber)

#define IMediaInfo_RecreateMaster(This)	\
    (This)->lpVtbl -> RecreateMaster(This)

#define IMediaInfo_UpdateLastKnownGoodMaster(This)	\
    (This)->lpVtbl -> UpdateLastKnownGoodMaster(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IMediaInfo_GetCapacity_Proxy( 
    IMediaInfo * This,
    /* [out] */ LONGLONG *pCapacity);


void __RPC_STUB IMediaInfo_GetCapacity_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaInfo_GetCopyDescription_Proxy( 
    IMediaInfo * This,
    /* [in] */ USHORT copyNumber,
    /* [string][out] */ OLECHAR **pDescription,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IMediaInfo_GetCopyDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaInfo_GetCopyInfo_Proxy( 
    IMediaInfo * This,
    /* [in] */ USHORT copyNumber,
    /* [out] */ GUID *pMediaSubsystemId,
    /* [string][out] */ OLECHAR **pDescription,
    /* [in] */ ULONG descriptionBufferSize,
    /* [string][out] */ OLECHAR **pName,
    /* [in] */ ULONG nameBufferSize,
    /* [out] */ FILETIME *pUpdate,
    /* [out] */ HRESULT *pLastError,
    /* [out] */ SHORT *pNextRemoteDataSet);


void __RPC_STUB IMediaInfo_GetCopyInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaInfo_GetCopyLastError_Proxy( 
    IMediaInfo * This,
    /* [in] */ USHORT copyNumber,
    /* [out] */ HRESULT *pLastError);


void __RPC_STUB IMediaInfo_GetCopyLastError_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaInfo_GetCopyMediaSubsystemId_Proxy( 
    IMediaInfo * This,
    /* [in] */ USHORT copyNumber,
    /* [out] */ GUID *pMediaSubsystemId);


void __RPC_STUB IMediaInfo_GetCopyMediaSubsystemId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaInfo_GetCopyName_Proxy( 
    IMediaInfo * This,
    /* [in] */ USHORT copyNumber,
    /* [string][out] */ OLECHAR **pName,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IMediaInfo_GetCopyName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaInfo_GetCopyNextRemoteDataSet_Proxy( 
    IMediaInfo * This,
    /* [in] */ USHORT copyNumber,
    /* [out] */ SHORT *pNextRemoteDataSet);


void __RPC_STUB IMediaInfo_GetCopyNextRemoteDataSet_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaInfo_GetCopyUpdate_Proxy( 
    IMediaInfo * This,
    /* [in] */ USHORT copyNumber,
    /* [out] */ FILETIME *pUpdate);


void __RPC_STUB IMediaInfo_GetCopyUpdate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaInfo_GetDescription_Proxy( 
    IMediaInfo * This,
    /* [string][out] */ OLECHAR **pDescription,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IMediaInfo_GetDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaInfo_GetFreeBytes_Proxy( 
    IMediaInfo * This,
    /* [out] */ LONGLONG *pFreeBytes);


void __RPC_STUB IMediaInfo_GetFreeBytes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaInfo_GetId_Proxy( 
    IMediaInfo * This,
    /* [out] */ GUID *pId);


void __RPC_STUB IMediaInfo_GetId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaInfo_GetLastError_Proxy( 
    IMediaInfo * This,
    /* [out] */ HRESULT *pLastError);


void __RPC_STUB IMediaInfo_GetLastError_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaInfo_GetLastKnownGoodMasterInfo_Proxy( 
    IMediaInfo * This,
    /* [out] */ GUID *pMediaId,
    /* [out] */ GUID *pMediaSubsystemId,
    /* [out] */ GUID *pStoragePoolId,
    /* [out] */ LONGLONG *pFreeBytes,
    /* [out] */ LONGLONG *pCapacity,
    /* [out] */ HRESULT *pLastError,
    /* [string][out] */ OLECHAR **pDescription,
    /* [in] */ ULONG descriptionBufferSize,
    /* [out] */ HSM_JOB_MEDIA_TYPE *pType,
    /* [string][out] */ OLECHAR **pName,
    /* [in] */ ULONG nameBufferSize,
    /* [out] */ BOOL *pReadOnly,
    /* [out] */ FILETIME *pUpdate,
    /* [out] */ SHORT *pNextRemoteDataSet);


void __RPC_STUB IMediaInfo_GetLastKnownGoodMasterInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaInfo_GetLKGMasterNextRemoteDataSet_Proxy( 
    IMediaInfo * This,
    /* [out] */ short *pNextRemoteDataSet);


void __RPC_STUB IMediaInfo_GetLKGMasterNextRemoteDataSet_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaInfo_GetLogicalValidBytes_Proxy( 
    IMediaInfo * This,
    /* [out] */ LONGLONG *pLogicalValidBytes);


void __RPC_STUB IMediaInfo_GetLogicalValidBytes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaInfo_GetMediaInfo_Proxy( 
    IMediaInfo * This,
    /* [out] */ GUID *pMediaId,
    /* [out] */ GUID *pMediaSubsystemId,
    /* [out] */ GUID *pStoragePoolId,
    /* [out] */ LONGLONG *pFreeBytes,
    /* [out] */ LONGLONG *pCapacity,
    /* [out] */ HRESULT *pLastError,
    /* [out] */ short *pNextRemoteDataSet,
    /* [string][out] */ OLECHAR **pDescription,
    /* [in] */ ULONG descriptionBufferSize,
    /* [out] */ HSM_JOB_MEDIA_TYPE *pType,
    /* [string][out] */ OLECHAR **pName,
    /* [in] */ ULONG nameBufferSize,
    /* [out] */ BOOL *pReadOnly,
    /* [out] */ FILETIME *pUpdate,
    /* [out] */ LONGLONG *pLogicalValidBytes,
    /* [out] */ BOOL *pRecreate);


void __RPC_STUB IMediaInfo_GetMediaInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaInfo_GetMediaSubsystemId_Proxy( 
    IMediaInfo * This,
    /* [out] */ GUID *pRmsMediaId);


void __RPC_STUB IMediaInfo_GetMediaSubsystemId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaInfo_GetName_Proxy( 
    IMediaInfo * This,
    /* [string][out] */ OLECHAR **pName,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IMediaInfo_GetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaInfo_GetNextRemoteDataSet_Proxy( 
    IMediaInfo * This,
    /* [out] */ short *pNextRemoteDataSet);


void __RPC_STUB IMediaInfo_GetNextRemoteDataSet_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaInfo_GetRecallOnlyStatus_Proxy( 
    IMediaInfo * This,
    /* [out] */ BOOL *pRecallOnlyStatus);


void __RPC_STUB IMediaInfo_GetRecallOnlyStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaInfo_GetRecreate_Proxy( 
    IMediaInfo * This,
    /* [out] */ BOOL *pRecreate);


void __RPC_STUB IMediaInfo_GetRecreate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaInfo_GetStoragePoolId_Proxy( 
    IMediaInfo * This,
    /* [out] */ GUID *pStoragePoolId);


void __RPC_STUB IMediaInfo_GetStoragePoolId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaInfo_GetType_Proxy( 
    IMediaInfo * This,
    /* [out] */ HSM_JOB_MEDIA_TYPE *pType);


void __RPC_STUB IMediaInfo_GetType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaInfo_GetUpdate_Proxy( 
    IMediaInfo * This,
    /* [out] */ FILETIME *pUpdate);


void __RPC_STUB IMediaInfo_GetUpdate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaInfo_SetName_Proxy( 
    IMediaInfo * This,
    /* [string][in] */ OLECHAR *name);


void __RPC_STUB IMediaInfo_SetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaInfo_SetCapacity_Proxy( 
    IMediaInfo * This,
    /* [in] */ LONGLONG capacity);


void __RPC_STUB IMediaInfo_SetCapacity_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaInfo_SetCopyName_Proxy( 
    IMediaInfo * This,
    /* [in] */ USHORT copyNumber,
    /* [string][in] */ OLECHAR *name);


void __RPC_STUB IMediaInfo_SetCopyName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaInfo_SetCopyNextRemoteDataSet_Proxy( 
    IMediaInfo * This,
    /* [in] */ USHORT copyNumber,
    /* [in] */ SHORT nextRemoteDataSet);


void __RPC_STUB IMediaInfo_SetCopyNextRemoteDataSet_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaInfo_SetCopyDescription_Proxy( 
    IMediaInfo * This,
    /* [in] */ USHORT copyNumber,
    /* [string][in] */ OLECHAR *description);


void __RPC_STUB IMediaInfo_SetCopyDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaInfo_SetCopyInfo_Proxy( 
    IMediaInfo * This,
    /* [in] */ USHORT copyNumber,
    /* [in] */ GUID mediaSybsystemMediaId,
    /* [string][in] */ OLECHAR *description,
    /* [string][in] */ OLECHAR *name,
    /* [in] */ FILETIME update,
    /* [in] */ HRESULT lastError,
    /* [in] */ SHORT nextRemoteDataSet);


void __RPC_STUB IMediaInfo_SetCopyInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaInfo_SetCopyLastError_Proxy( 
    IMediaInfo * This,
    /* [in] */ USHORT copyNumber,
    /* [in] */ HRESULT lastError);


void __RPC_STUB IMediaInfo_SetCopyLastError_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaInfo_SetCopyMediaSubsystemId_Proxy( 
    IMediaInfo * This,
    /* [in] */ USHORT copyNumber,
    /* [in] */ GUID mediaSybsystemMediaId);


void __RPC_STUB IMediaInfo_SetCopyMediaSubsystemId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaInfo_SetCopyUpdate_Proxy( 
    IMediaInfo * This,
    /* [in] */ USHORT copyNumber,
    /* [in] */ FILETIME update);


void __RPC_STUB IMediaInfo_SetCopyUpdate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaInfo_SetDescription_Proxy( 
    IMediaInfo * This,
    /* [string][in] */ OLECHAR *description);


void __RPC_STUB IMediaInfo_SetDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaInfo_SetId_Proxy( 
    IMediaInfo * This,
    /* [in] */ GUID id);


void __RPC_STUB IMediaInfo_SetId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaInfo_SetFreeBytes_Proxy( 
    IMediaInfo * This,
    /* [in] */ LONGLONG FreeBytes);


void __RPC_STUB IMediaInfo_SetFreeBytes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaInfo_SetLastError_Proxy( 
    IMediaInfo * This,
    /* [in] */ HRESULT lastError);


void __RPC_STUB IMediaInfo_SetLastError_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaInfo_SetLastKnownGoodMasterInfo_Proxy( 
    IMediaInfo * This,
    /* [in] */ GUID mediaId,
    /* [in] */ GUID mediaSubsystemMediaId,
    /* [in] */ GUID storagePoolId,
    /* [in] */ LONGLONG FreeBytes,
    /* [in] */ LONGLONG Capacity,
    /* [in] */ HRESULT lastError,
    /* [string][in] */ OLECHAR *description,
    /* [in] */ HSM_JOB_MEDIA_TYPE type,
    /* [string][in] */ OLECHAR *name,
    /* [in] */ BOOL readOnly,
    /* [in] */ FILETIME update,
    /* [in] */ SHORT nextRemoteDataSet);


void __RPC_STUB IMediaInfo_SetLastKnownGoodMasterInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaInfo_SetLogicalValidBytes_Proxy( 
    IMediaInfo * This,
    /* [in] */ LONGLONG logicalValidBytes);


void __RPC_STUB IMediaInfo_SetLogicalValidBytes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaInfo_SetMediaInfo_Proxy( 
    IMediaInfo * This,
    /* [in] */ GUID mediaId,
    /* [in] */ GUID mediaSubsystemMediaId,
    /* [in] */ GUID storagePoolId,
    /* [in] */ LONGLONG FreeBytes,
    /* [in] */ LONGLONG Capacity,
    /* [in] */ HRESULT lastError,
    /* [in] */ short nextRemoteDataSet,
    /* [string][in] */ OLECHAR *description,
    /* [in] */ HSM_JOB_MEDIA_TYPE type,
    /* [string][in] */ OLECHAR *name,
    /* [in] */ BOOL readOnly,
    /* [in] */ FILETIME update,
    /* [in] */ LONGLONG logicalValidBytes,
    /* [in] */ BOOL recreate);


void __RPC_STUB IMediaInfo_SetMediaInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaInfo_SetMediaSubsystemId_Proxy( 
    IMediaInfo * This,
    /* [in] */ GUID rmsMediaId);


void __RPC_STUB IMediaInfo_SetMediaSubsystemId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaInfo_SetNextRemoteDataSet_Proxy( 
    IMediaInfo * This,
    /* [in] */ short nextRemoteDataSet);


void __RPC_STUB IMediaInfo_SetNextRemoteDataSet_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaInfo_SetRecallOnlyStatus_Proxy( 
    IMediaInfo * This,
    /* [in] */ BOOL readOnlyStatus);


void __RPC_STUB IMediaInfo_SetRecallOnlyStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaInfo_SetRecreate_Proxy( 
    IMediaInfo * This,
    /* [in] */ BOOL recreate);


void __RPC_STUB IMediaInfo_SetRecreate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaInfo_SetStoragePoolId_Proxy( 
    IMediaInfo * This,
    /* [in] */ GUID storagePoolId);


void __RPC_STUB IMediaInfo_SetStoragePoolId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaInfo_SetType_Proxy( 
    IMediaInfo * This,
    /* [in] */ HSM_JOB_MEDIA_TYPE type);


void __RPC_STUB IMediaInfo_SetType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaInfo_SetUpdate_Proxy( 
    IMediaInfo * This,
    /* [in] */ FILETIME update);


void __RPC_STUB IMediaInfo_SetUpdate_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaInfo_DeleteCopy_Proxy( 
    IMediaInfo * This,
    /* [in] */ USHORT copyNumber);


void __RPC_STUB IMediaInfo_DeleteCopy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaInfo_RecreateMaster_Proxy( 
    IMediaInfo * This);


void __RPC_STUB IMediaInfo_RecreateMaster_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMediaInfo_UpdateLastKnownGoodMaster_Proxy( 
    IMediaInfo * This);


void __RPC_STUB IMediaInfo_UpdateLastKnownGoodMaster_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IMediaInfo_INTERFACE_DEFINED__ */


#ifndef __IVolAssign_INTERFACE_DEFINED__
#define __IVolAssign_INTERFACE_DEFINED__

/* interface IVolAssign */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IVolAssign;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4A009E82-DC42-11d0-9925-00A0C9058BF6")
    IVolAssign : public IWsbDbEntity
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetVolAssign( 
            /* [out] */ GUID *pBagId,
            /* [out] */ LONGLONG *pSegStartLoc,
            /* [out] */ LONGLONG *pSegLen,
            /* [out] */ GUID *pVolId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetVolAssign( 
            /* [in] */ GUID BagId,
            /* [in] */ LONGLONG segStartLoc,
            /* [in] */ LONGLONG segLen,
            /* [in] */ GUID VolId) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IVolAssignVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IVolAssign * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IVolAssign * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IVolAssign * This);
        
        HRESULT ( STDMETHODCALLTYPE *Clone )( 
            IVolAssign * This,
            /* [in] */ REFIID riid,
            /* [iid_is][retval][out] */ void **ppEntity);
        
        HRESULT ( STDMETHODCALLTYPE *Disconnect )( 
            IVolAssign * This);
        
        HRESULT ( STDMETHODCALLTYPE *FindEQ )( 
            IVolAssign * This);
        
        HRESULT ( STDMETHODCALLTYPE *FindGT )( 
            IVolAssign * This);
        
        HRESULT ( STDMETHODCALLTYPE *FindGTE )( 
            IVolAssign * This);
        
        HRESULT ( STDMETHODCALLTYPE *FindLT )( 
            IVolAssign * This);
        
        HRESULT ( STDMETHODCALLTYPE *FindLTE )( 
            IVolAssign * This);
        
        HRESULT ( STDMETHODCALLTYPE *First )( 
            IVolAssign * This);
        
        HRESULT ( STDMETHODCALLTYPE *Last )( 
            IVolAssign * This);
        
        HRESULT ( STDMETHODCALLTYPE *MarkAsNew )( 
            IVolAssign * This);
        
        HRESULT ( STDMETHODCALLTYPE *Next )( 
            IVolAssign * This);
        
        HRESULT ( STDMETHODCALLTYPE *Previous )( 
            IVolAssign * This);
        
        HRESULT ( STDMETHODCALLTYPE *Print )( 
            IVolAssign * This,
            /* [in] */ IStream *pStream);
        
        HRESULT ( STDMETHODCALLTYPE *Remove )( 
            IVolAssign * This);
        
        HRESULT ( STDMETHODCALLTYPE *UpdateKey )( 
            IVolAssign * This,
            /* [in] */ IWsbDbKey *pKey);
        
        HRESULT ( STDMETHODCALLTYPE *UseKey )( 
            IVolAssign * This,
            /* [in] */ ULONG type);
        
        HRESULT ( STDMETHODCALLTYPE *Write )( 
            IVolAssign * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetSequentialScan )( 
            IVolAssign * This);
        
        HRESULT ( STDMETHODCALLTYPE *ResetSequentialScan )( 
            IVolAssign * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetVolAssign )( 
            IVolAssign * This,
            /* [out] */ GUID *pBagId,
            /* [out] */ LONGLONG *pSegStartLoc,
            /* [out] */ LONGLONG *pSegLen,
            /* [out] */ GUID *pVolId);
        
        HRESULT ( STDMETHODCALLTYPE *SetVolAssign )( 
            IVolAssign * This,
            /* [in] */ GUID BagId,
            /* [in] */ LONGLONG segStartLoc,
            /* [in] */ LONGLONG segLen,
            /* [in] */ GUID VolId);
        
        END_INTERFACE
    } IVolAssignVtbl;

    interface IVolAssign
    {
        CONST_VTBL struct IVolAssignVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IVolAssign_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IVolAssign_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IVolAssign_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IVolAssign_Clone(This,riid,ppEntity)	\
    (This)->lpVtbl -> Clone(This,riid,ppEntity)

#define IVolAssign_Disconnect(This)	\
    (This)->lpVtbl -> Disconnect(This)

#define IVolAssign_FindEQ(This)	\
    (This)->lpVtbl -> FindEQ(This)

#define IVolAssign_FindGT(This)	\
    (This)->lpVtbl -> FindGT(This)

#define IVolAssign_FindGTE(This)	\
    (This)->lpVtbl -> FindGTE(This)

#define IVolAssign_FindLT(This)	\
    (This)->lpVtbl -> FindLT(This)

#define IVolAssign_FindLTE(This)	\
    (This)->lpVtbl -> FindLTE(This)

#define IVolAssign_First(This)	\
    (This)->lpVtbl -> First(This)

#define IVolAssign_Last(This)	\
    (This)->lpVtbl -> Last(This)

#define IVolAssign_MarkAsNew(This)	\
    (This)->lpVtbl -> MarkAsNew(This)

#define IVolAssign_Next(This)	\
    (This)->lpVtbl -> Next(This)

#define IVolAssign_Previous(This)	\
    (This)->lpVtbl -> Previous(This)

#define IVolAssign_Print(This,pStream)	\
    (This)->lpVtbl -> Print(This,pStream)

#define IVolAssign_Remove(This)	\
    (This)->lpVtbl -> Remove(This)

#define IVolAssign_UpdateKey(This,pKey)	\
    (This)->lpVtbl -> UpdateKey(This,pKey)

#define IVolAssign_UseKey(This,type)	\
    (This)->lpVtbl -> UseKey(This,type)

#define IVolAssign_Write(This)	\
    (This)->lpVtbl -> Write(This)

#define IVolAssign_SetSequentialScan(This)	\
    (This)->lpVtbl -> SetSequentialScan(This)

#define IVolAssign_ResetSequentialScan(This)	\
    (This)->lpVtbl -> ResetSequentialScan(This)


#define IVolAssign_GetVolAssign(This,pBagId,pSegStartLoc,pSegLen,pVolId)	\
    (This)->lpVtbl -> GetVolAssign(This,pBagId,pSegStartLoc,pSegLen,pVolId)

#define IVolAssign_SetVolAssign(This,BagId,segStartLoc,segLen,VolId)	\
    (This)->lpVtbl -> SetVolAssign(This,BagId,segStartLoc,segLen,VolId)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IVolAssign_GetVolAssign_Proxy( 
    IVolAssign * This,
    /* [out] */ GUID *pBagId,
    /* [out] */ LONGLONG *pSegStartLoc,
    /* [out] */ LONGLONG *pSegLen,
    /* [out] */ GUID *pVolId);


void __RPC_STUB IVolAssign_GetVolAssign_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IVolAssign_SetVolAssign_Proxy( 
    IVolAssign * This,
    /* [in] */ GUID BagId,
    /* [in] */ LONGLONG segStartLoc,
    /* [in] */ LONGLONG segLen,
    /* [in] */ GUID VolId);


void __RPC_STUB IVolAssign_SetVolAssign_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IVolAssign_INTERFACE_DEFINED__ */


#ifndef __ISegDb_INTERFACE_DEFINED__
#define __ISegDb_INTERFACE_DEFINED__

/* interface ISegDb */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_ISegDb;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("36A90590-3921-4C67-BAD2-CAD166E08B6D")
    ISegDb : public IWsbDb
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Erase( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE Initialize( 
            /* [string][in] */ OLECHAR *root,
            /* [in] */ IWsbDbSys *pDbSys,
            /* [out][in] */ BOOL *pCreateFlag) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BagHoleAdd( 
            /* [in] */ IWsbDbSession *pDbSession,
            /* [in] */ GUID bagId,
            /* [in] */ LONGLONG segStartLoc,
            /* [in] */ LONGLONG segLen) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BagHoleFind( 
            /* [in] */ IWsbDbSession *pDbSession,
            /* [in] */ GUID bagId,
            /* [in] */ LONGLONG segStartLoc,
            /* [in] */ LONGLONG segLen,
            /* [out] */ IBagHole **ppIBagHole) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BagHoleSubtract( 
            /* [in] */ IWsbDbSession *pDbSession,
            /* [in] */ GUID bagId,
            /* [in] */ LONGLONG segStartLoc,
            /* [in] */ LONGLONG segLen) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SegAdd( 
            /* [in] */ IWsbDbSession *pDbSession,
            /* [in] */ GUID bagId,
            /* [in] */ LONGLONG segStartLoc,
            /* [in] */ LONGLONG segLen,
            /* [in] */ GUID MediaId,
            /* [in] */ LONGLONG mediaStart,
            /* [defaultvalue][in] */ BOOL indirectRecord = FALSE) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SegFind( 
            /* [in] */ IWsbDbSession *pDbSession,
            /* [in] */ GUID bagId,
            /* [in] */ LONGLONG segStartLoc,
            /* [in] */ LONGLONG segLen,
            /* [out] */ ISegRec **ppISegRec) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SegSubtract( 
            /* [in] */ IWsbDbSession *pDbSession,
            /* [in] */ GUID bagId,
            /* [in] */ LONGLONG segStartLoc,
            /* [in] */ LONGLONG segLen) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE VolAssignAdd( 
            /* [in] */ IWsbDbSession *pDbSession,
            /* [in] */ GUID bagId,
            /* [in] */ LONGLONG segStartLoc,
            /* [in] */ LONGLONG segLen,
            /* [in] */ GUID VolId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE VolAssignFind( 
            /* [in] */ IWsbDbSession *pDbSession,
            /* [in] */ GUID bagId,
            /* [in] */ LONGLONG segStartLoc,
            /* [in] */ LONGLONG segLen,
            /* [out] */ IVolAssign **ppIVolAssign) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE VolAssignSubtract( 
            /* [in] */ IWsbDbSession *pDbSession,
            /* [in] */ GUID bagId,
            /* [in] */ LONGLONG segStartLoc,
            /* [in] */ LONGLONG segLen) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ISegDbVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ISegDb * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            ISegDb * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            ISegDb * This);
        
        HRESULT ( STDMETHODCALLTYPE *Close )( 
            ISegDb * This,
            /* [in] */ IWsbDbSession *pSession);
        
        HRESULT ( STDMETHODCALLTYPE *Create )( 
            ISegDb * This,
            /* [string][in] */ OLECHAR *path,
            /* [defaultvalue][in] */ ULONG flags);
        
        HRESULT ( STDMETHODCALLTYPE *Delete )( 
            ISegDb * This,
            /* [string][in] */ OLECHAR *path,
            /* [defaultvalue][in] */ ULONG flags);
        
        HRESULT ( STDMETHODCALLTYPE *Dump )( 
            ISegDb * This,
            /* [string][in] */ OLECHAR *Filename,
            /* [in] */ ULONG Flags,
            /* [in] */ ULONG Data);
        
        HRESULT ( STDMETHODCALLTYPE *GetEntity )( 
            ISegDb * This,
            /* [in] */ IWsbDbSession *pSession,
            /* [in] */ ULONG RecId,
            /* [in] */ REFIID riid,
            /* [iid_is][retval][out] */ void **ppEntity);
        
        HRESULT ( STDMETHODCALLTYPE *GetName )( 
            ISegDb * This,
            /* [string][out] */ OLECHAR **pName);
        
        HRESULT ( STDMETHODCALLTYPE *GetPath )( 
            ISegDb * This,
            /* [string][out] */ OLECHAR **pPath);
        
        HRESULT ( STDMETHODCALLTYPE *GetVersion )( 
            ISegDb * This,
            /* [out] */ ULONG *pVer);
        
        HRESULT ( STDMETHODCALLTYPE *Locate )( 
            ISegDb * This,
            /* [string][in] */ OLECHAR *path);
        
        HRESULT ( STDMETHODCALLTYPE *Open )( 
            ISegDb * This,
            /* [out][in] */ IWsbDbSession **ppSession);
        
        HRESULT ( STDMETHODCALLTYPE *Erase )( 
            ISegDb * This);
        
        HRESULT ( STDMETHODCALLTYPE *Initialize )( 
            ISegDb * This,
            /* [string][in] */ OLECHAR *root,
            /* [in] */ IWsbDbSys *pDbSys,
            /* [out][in] */ BOOL *pCreateFlag);
        
        HRESULT ( STDMETHODCALLTYPE *BagHoleAdd )( 
            ISegDb * This,
            /* [in] */ IWsbDbSession *pDbSession,
            /* [in] */ GUID bagId,
            /* [in] */ LONGLONG segStartLoc,
            /* [in] */ LONGLONG segLen);
        
        HRESULT ( STDMETHODCALLTYPE *BagHoleFind )( 
            ISegDb * This,
            /* [in] */ IWsbDbSession *pDbSession,
            /* [in] */ GUID bagId,
            /* [in] */ LONGLONG segStartLoc,
            /* [in] */ LONGLONG segLen,
            /* [out] */ IBagHole **ppIBagHole);
        
        HRESULT ( STDMETHODCALLTYPE *BagHoleSubtract )( 
            ISegDb * This,
            /* [in] */ IWsbDbSession *pDbSession,
            /* [in] */ GUID bagId,
            /* [in] */ LONGLONG segStartLoc,
            /* [in] */ LONGLONG segLen);
        
        HRESULT ( STDMETHODCALLTYPE *SegAdd )( 
            ISegDb * This,
            /* [in] */ IWsbDbSession *pDbSession,
            /* [in] */ GUID bagId,
            /* [in] */ LONGLONG segStartLoc,
            /* [in] */ LONGLONG segLen,
            /* [in] */ GUID MediaId,
            /* [in] */ LONGLONG mediaStart,
            /* [defaultvalue][in] */ BOOL indirectRecord);
        
        HRESULT ( STDMETHODCALLTYPE *SegFind )( 
            ISegDb * This,
            /* [in] */ IWsbDbSession *pDbSession,
            /* [in] */ GUID bagId,
            /* [in] */ LONGLONG segStartLoc,
            /* [in] */ LONGLONG segLen,
            /* [out] */ ISegRec **ppISegRec);
        
        HRESULT ( STDMETHODCALLTYPE *SegSubtract )( 
            ISegDb * This,
            /* [in] */ IWsbDbSession *pDbSession,
            /* [in] */ GUID bagId,
            /* [in] */ LONGLONG segStartLoc,
            /* [in] */ LONGLONG segLen);
        
        HRESULT ( STDMETHODCALLTYPE *VolAssignAdd )( 
            ISegDb * This,
            /* [in] */ IWsbDbSession *pDbSession,
            /* [in] */ GUID bagId,
            /* [in] */ LONGLONG segStartLoc,
            /* [in] */ LONGLONG segLen,
            /* [in] */ GUID VolId);
        
        HRESULT ( STDMETHODCALLTYPE *VolAssignFind )( 
            ISegDb * This,
            /* [in] */ IWsbDbSession *pDbSession,
            /* [in] */ GUID bagId,
            /* [in] */ LONGLONG segStartLoc,
            /* [in] */ LONGLONG segLen,
            /* [out] */ IVolAssign **ppIVolAssign);
        
        HRESULT ( STDMETHODCALLTYPE *VolAssignSubtract )( 
            ISegDb * This,
            /* [in] */ IWsbDbSession *pDbSession,
            /* [in] */ GUID bagId,
            /* [in] */ LONGLONG segStartLoc,
            /* [in] */ LONGLONG segLen);
        
        END_INTERFACE
    } ISegDbVtbl;

    interface ISegDb
    {
        CONST_VTBL struct ISegDbVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ISegDb_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ISegDb_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ISegDb_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ISegDb_Close(This,pSession)	\
    (This)->lpVtbl -> Close(This,pSession)

#define ISegDb_Create(This,path,flags)	\
    (This)->lpVtbl -> Create(This,path,flags)

#define ISegDb_Delete(This,path,flags)	\
    (This)->lpVtbl -> Delete(This,path,flags)

#define ISegDb_Dump(This,Filename,Flags,Data)	\
    (This)->lpVtbl -> Dump(This,Filename,Flags,Data)

#define ISegDb_GetEntity(This,pSession,RecId,riid,ppEntity)	\
    (This)->lpVtbl -> GetEntity(This,pSession,RecId,riid,ppEntity)

#define ISegDb_GetName(This,pName)	\
    (This)->lpVtbl -> GetName(This,pName)

#define ISegDb_GetPath(This,pPath)	\
    (This)->lpVtbl -> GetPath(This,pPath)

#define ISegDb_GetVersion(This,pVer)	\
    (This)->lpVtbl -> GetVersion(This,pVer)

#define ISegDb_Locate(This,path)	\
    (This)->lpVtbl -> Locate(This,path)

#define ISegDb_Open(This,ppSession)	\
    (This)->lpVtbl -> Open(This,ppSession)


#define ISegDb_Erase(This)	\
    (This)->lpVtbl -> Erase(This)

#define ISegDb_Initialize(This,root,pDbSys,pCreateFlag)	\
    (This)->lpVtbl -> Initialize(This,root,pDbSys,pCreateFlag)

#define ISegDb_BagHoleAdd(This,pDbSession,bagId,segStartLoc,segLen)	\
    (This)->lpVtbl -> BagHoleAdd(This,pDbSession,bagId,segStartLoc,segLen)

#define ISegDb_BagHoleFind(This,pDbSession,bagId,segStartLoc,segLen,ppIBagHole)	\
    (This)->lpVtbl -> BagHoleFind(This,pDbSession,bagId,segStartLoc,segLen,ppIBagHole)

#define ISegDb_BagHoleSubtract(This,pDbSession,bagId,segStartLoc,segLen)	\
    (This)->lpVtbl -> BagHoleSubtract(This,pDbSession,bagId,segStartLoc,segLen)

#define ISegDb_SegAdd(This,pDbSession,bagId,segStartLoc,segLen,MediaId,mediaStart,indirectRecord)	\
    (This)->lpVtbl -> SegAdd(This,pDbSession,bagId,segStartLoc,segLen,MediaId,mediaStart,indirectRecord)

#define ISegDb_SegFind(This,pDbSession,bagId,segStartLoc,segLen,ppISegRec)	\
    (This)->lpVtbl -> SegFind(This,pDbSession,bagId,segStartLoc,segLen,ppISegRec)

#define ISegDb_SegSubtract(This,pDbSession,bagId,segStartLoc,segLen)	\
    (This)->lpVtbl -> SegSubtract(This,pDbSession,bagId,segStartLoc,segLen)

#define ISegDb_VolAssignAdd(This,pDbSession,bagId,segStartLoc,segLen,VolId)	\
    (This)->lpVtbl -> VolAssignAdd(This,pDbSession,bagId,segStartLoc,segLen,VolId)

#define ISegDb_VolAssignFind(This,pDbSession,bagId,segStartLoc,segLen,ppIVolAssign)	\
    (This)->lpVtbl -> VolAssignFind(This,pDbSession,bagId,segStartLoc,segLen,ppIVolAssign)

#define ISegDb_VolAssignSubtract(This,pDbSession,bagId,segStartLoc,segLen)	\
    (This)->lpVtbl -> VolAssignSubtract(This,pDbSession,bagId,segStartLoc,segLen)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE ISegDb_Erase_Proxy( 
    ISegDb * This);


void __RPC_STUB ISegDb_Erase_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ISegDb_Initialize_Proxy( 
    ISegDb * This,
    /* [string][in] */ OLECHAR *root,
    /* [in] */ IWsbDbSys *pDbSys,
    /* [out][in] */ BOOL *pCreateFlag);


void __RPC_STUB ISegDb_Initialize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ISegDb_BagHoleAdd_Proxy( 
    ISegDb * This,
    /* [in] */ IWsbDbSession *pDbSession,
    /* [in] */ GUID bagId,
    /* [in] */ LONGLONG segStartLoc,
    /* [in] */ LONGLONG segLen);


void __RPC_STUB ISegDb_BagHoleAdd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ISegDb_BagHoleFind_Proxy( 
    ISegDb * This,
    /* [in] */ IWsbDbSession *pDbSession,
    /* [in] */ GUID bagId,
    /* [in] */ LONGLONG segStartLoc,
    /* [in] */ LONGLONG segLen,
    /* [out] */ IBagHole **ppIBagHole);


void __RPC_STUB ISegDb_BagHoleFind_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ISegDb_BagHoleSubtract_Proxy( 
    ISegDb * This,
    /* [in] */ IWsbDbSession *pDbSession,
    /* [in] */ GUID bagId,
    /* [in] */ LONGLONG segStartLoc,
    /* [in] */ LONGLONG segLen);


void __RPC_STUB ISegDb_BagHoleSubtract_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ISegDb_SegAdd_Proxy( 
    ISegDb * This,
    /* [in] */ IWsbDbSession *pDbSession,
    /* [in] */ GUID bagId,
    /* [in] */ LONGLONG segStartLoc,
    /* [in] */ LONGLONG segLen,
    /* [in] */ GUID MediaId,
    /* [in] */ LONGLONG mediaStart,
    /* [defaultvalue][in] */ BOOL indirectRecord);


void __RPC_STUB ISegDb_SegAdd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ISegDb_SegFind_Proxy( 
    ISegDb * This,
    /* [in] */ IWsbDbSession *pDbSession,
    /* [in] */ GUID bagId,
    /* [in] */ LONGLONG segStartLoc,
    /* [in] */ LONGLONG segLen,
    /* [out] */ ISegRec **ppISegRec);


void __RPC_STUB ISegDb_SegFind_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ISegDb_SegSubtract_Proxy( 
    ISegDb * This,
    /* [in] */ IWsbDbSession *pDbSession,
    /* [in] */ GUID bagId,
    /* [in] */ LONGLONG segStartLoc,
    /* [in] */ LONGLONG segLen);


void __RPC_STUB ISegDb_SegSubtract_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ISegDb_VolAssignAdd_Proxy( 
    ISegDb * This,
    /* [in] */ IWsbDbSession *pDbSession,
    /* [in] */ GUID bagId,
    /* [in] */ LONGLONG segStartLoc,
    /* [in] */ LONGLONG segLen,
    /* [in] */ GUID VolId);


void __RPC_STUB ISegDb_VolAssignAdd_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ISegDb_VolAssignFind_Proxy( 
    ISegDb * This,
    /* [in] */ IWsbDbSession *pDbSession,
    /* [in] */ GUID bagId,
    /* [in] */ LONGLONG segStartLoc,
    /* [in] */ LONGLONG segLen,
    /* [out] */ IVolAssign **ppIVolAssign);


void __RPC_STUB ISegDb_VolAssignFind_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE ISegDb_VolAssignSubtract_Proxy( 
    ISegDb * This,
    /* [in] */ IWsbDbSession *pDbSession,
    /* [in] */ GUID bagId,
    /* [in] */ LONGLONG segStartLoc,
    /* [in] */ LONGLONG segLen);


void __RPC_STUB ISegDb_VolAssignSubtract_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ISegDb_INTERFACE_DEFINED__ */


/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


