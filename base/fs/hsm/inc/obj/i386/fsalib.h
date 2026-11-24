

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for fsalib.idl:
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


#ifndef __fsalib_h__
#define __fsalib_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __CFsaFilterNTFS_FWD_DEFINED__
#define __CFsaFilterNTFS_FWD_DEFINED__

#ifdef __cplusplus
typedef class CFsaFilterNTFS CFsaFilterNTFS;
#else
typedef struct CFsaFilterNTFS CFsaFilterNTFS;
#endif /* __cplusplus */

#endif 	/* __CFsaFilterNTFS_FWD_DEFINED__ */


#ifndef __CFsaFilterClientNTFS_FWD_DEFINED__
#define __CFsaFilterClientNTFS_FWD_DEFINED__

#ifdef __cplusplus
typedef class CFsaFilterClientNTFS CFsaFilterClientNTFS;
#else
typedef struct CFsaFilterClientNTFS CFsaFilterClientNTFS;
#endif /* __cplusplus */

#endif 	/* __CFsaFilterClientNTFS_FWD_DEFINED__ */


#ifndef __CFsaFilterRecallNTFS_FWD_DEFINED__
#define __CFsaFilterRecallNTFS_FWD_DEFINED__

#ifdef __cplusplus
typedef class CFsaFilterRecallNTFS CFsaFilterRecallNTFS;
#else
typedef struct CFsaFilterRecallNTFS CFsaFilterRecallNTFS;
#endif /* __cplusplus */

#endif 	/* __CFsaFilterRecallNTFS_FWD_DEFINED__ */


#ifndef __CFsaResourceNTFS_FWD_DEFINED__
#define __CFsaResourceNTFS_FWD_DEFINED__

#ifdef __cplusplus
typedef class CFsaResourceNTFS CFsaResourceNTFS;
#else
typedef struct CFsaResourceNTFS CFsaResourceNTFS;
#endif /* __cplusplus */

#endif 	/* __CFsaResourceNTFS_FWD_DEFINED__ */


#ifndef __CFsaScanItemNTFS_FWD_DEFINED__
#define __CFsaScanItemNTFS_FWD_DEFINED__

#ifdef __cplusplus
typedef class CFsaScanItemNTFS CFsaScanItemNTFS;
#else
typedef struct CFsaScanItemNTFS CFsaScanItemNTFS;
#endif /* __cplusplus */

#endif 	/* __CFsaScanItemNTFS_FWD_DEFINED__ */


#ifndef __CFsaServerNTFS_FWD_DEFINED__
#define __CFsaServerNTFS_FWD_DEFINED__

#ifdef __cplusplus
typedef class CFsaServerNTFS CFsaServerNTFS;
#else
typedef struct CFsaServerNTFS CFsaServerNTFS;
#endif /* __cplusplus */

#endif 	/* __CFsaServerNTFS_FWD_DEFINED__ */


#ifndef __CFsaTruncatorNTFS_FWD_DEFINED__
#define __CFsaTruncatorNTFS_FWD_DEFINED__

#ifdef __cplusplus
typedef class CFsaTruncatorNTFS CFsaTruncatorNTFS;
#else
typedef struct CFsaTruncatorNTFS CFsaTruncatorNTFS;
#endif /* __cplusplus */

#endif 	/* __CFsaTruncatorNTFS_FWD_DEFINED__ */


#ifndef __CFsaPremigratedDb_FWD_DEFINED__
#define __CFsaPremigratedDb_FWD_DEFINED__

#ifdef __cplusplus
typedef class CFsaPremigratedDb CFsaPremigratedDb;
#else
typedef struct CFsaPremigratedDb CFsaPremigratedDb;
#endif /* __cplusplus */

#endif 	/* __CFsaPremigratedDb_FWD_DEFINED__ */


#ifndef __CFsaPremigratedRec_FWD_DEFINED__
#define __CFsaPremigratedRec_FWD_DEFINED__

#ifdef __cplusplus
typedef class CFsaPremigratedRec CFsaPremigratedRec;
#else
typedef struct CFsaPremigratedRec CFsaPremigratedRec;
#endif /* __cplusplus */

#endif 	/* __CFsaPremigratedRec_FWD_DEFINED__ */


#ifndef __CFsaUnmanageDb_FWD_DEFINED__
#define __CFsaUnmanageDb_FWD_DEFINED__

#ifdef __cplusplus
typedef class CFsaUnmanageDb CFsaUnmanageDb;
#else
typedef struct CFsaUnmanageDb CFsaUnmanageDb;
#endif /* __cplusplus */

#endif 	/* __CFsaUnmanageDb_FWD_DEFINED__ */


#ifndef __CFsaUnmanageRec_FWD_DEFINED__
#define __CFsaUnmanageRec_FWD_DEFINED__

#ifdef __cplusplus
typedef class CFsaUnmanageRec CFsaUnmanageRec;
#else
typedef struct CFsaUnmanageRec CFsaUnmanageRec;
#endif /* __cplusplus */

#endif 	/* __CFsaUnmanageRec_FWD_DEFINED__ */


#ifndef __CFsaPostIt_FWD_DEFINED__
#define __CFsaPostIt_FWD_DEFINED__

#ifdef __cplusplus
typedef class CFsaPostIt CFsaPostIt;
#else
typedef struct CFsaPostIt CFsaPostIt;
#endif /* __cplusplus */

#endif 	/* __CFsaPostIt_FWD_DEFINED__ */


#ifndef __CFsaRecallNotifyClient_FWD_DEFINED__
#define __CFsaRecallNotifyClient_FWD_DEFINED__

#ifdef __cplusplus
typedef class CFsaRecallNotifyClient CFsaRecallNotifyClient;
#else
typedef struct CFsaRecallNotifyClient CFsaRecallNotifyClient;
#endif /* __cplusplus */

#endif 	/* __CFsaRecallNotifyClient_FWD_DEFINED__ */


#ifndef __CFsaRecoveryRec_FWD_DEFINED__
#define __CFsaRecoveryRec_FWD_DEFINED__

#ifdef __cplusplus
typedef class CFsaRecoveryRec CFsaRecoveryRec;
#else
typedef struct CFsaRecoveryRec CFsaRecoveryRec;
#endif /* __cplusplus */

#endif 	/* __CFsaRecoveryRec_FWD_DEFINED__ */


#ifndef __CFsaRecallNotifyServer_FWD_DEFINED__
#define __CFsaRecallNotifyServer_FWD_DEFINED__

#ifdef __cplusplus
typedef class CFsaRecallNotifyServer CFsaRecallNotifyServer;
#else
typedef struct CFsaRecallNotifyServer CFsaRecallNotifyServer;
#endif /* __cplusplus */

#endif 	/* __CFsaRecallNotifyServer_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "fsaint.h"
#include "fsaprv.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 


#ifndef __FSALib_LIBRARY_DEFINED__
#define __FSALib_LIBRARY_DEFINED__

/* library FSALib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_FSALib;

EXTERN_C const CLSID CLSID_CFsaFilterNTFS;

#ifdef __cplusplus

class DECLSPEC_UUID("FCDC8671-7329-11d0-81DF-00A0C91180F2")
CFsaFilterNTFS;
#endif

EXTERN_C const CLSID CLSID_CFsaFilterClientNTFS;

#ifdef __cplusplus

class DECLSPEC_UUID("B2AD2931-84FD-11d0-81E4-00A0C91180F2")
CFsaFilterClientNTFS;
#endif

EXTERN_C const CLSID CLSID_CFsaFilterRecallNTFS;

#ifdef __cplusplus

class DECLSPEC_UUID("B2AD2932-84FD-11d0-81E4-00A0C91180F2")
CFsaFilterRecallNTFS;
#endif

EXTERN_C const CLSID CLSID_CFsaResourceNTFS;

#ifdef __cplusplus

class DECLSPEC_UUID("112981B3-1BA5-11D0-81B2-00A0C91180F2")
CFsaResourceNTFS;
#endif

EXTERN_C const CLSID CLSID_CFsaScanItemNTFS;

#ifdef __cplusplus

class DECLSPEC_UUID("112981B2-1BA5-11D0-81B2-00A0C91180F2")
CFsaScanItemNTFS;
#endif

EXTERN_C const CLSID CLSID_CFsaServerNTFS;

#ifdef __cplusplus

class DECLSPEC_UUID("E707D9B2-4F89-11D0-81CC-00A0C91180F2")
CFsaServerNTFS;
#endif

EXTERN_C const CLSID CLSID_CFsaTruncatorNTFS;

#ifdef __cplusplus

class DECLSPEC_UUID("14005FF1-8B4F-11d0-81E6-00A0C91180F2")
CFsaTruncatorNTFS;
#endif

EXTERN_C const CLSID CLSID_CFsaPremigratedDb;

#ifdef __cplusplus

class DECLSPEC_UUID("0B8B6F12-8B3A-11D0-990C-00A0C9058BF6")
CFsaPremigratedDb;
#endif

EXTERN_C const CLSID CLSID_CFsaPremigratedRec;

#ifdef __cplusplus

class DECLSPEC_UUID("7CA819F2-8AAB-11D0-990C-00A0C9058BF6")
CFsaPremigratedRec;
#endif

EXTERN_C const CLSID CLSID_CFsaUnmanageDb;

#ifdef __cplusplus

class DECLSPEC_UUID("58DD2BB0-1A57-4CD3-B11E-D505E4332BC0")
CFsaUnmanageDb;
#endif

EXTERN_C const CLSID CLSID_CFsaUnmanageRec;

#ifdef __cplusplus

class DECLSPEC_UUID("85D81D44-31D5-43B0-9466-1E4F66EEC03A")
CFsaUnmanageRec;
#endif

EXTERN_C const CLSID CLSID_CFsaPostIt;

#ifdef __cplusplus

class DECLSPEC_UUID("F7860350-AA27-11d0-B16D-00A0C916F120")
CFsaPostIt;
#endif

EXTERN_C const CLSID CLSID_CFsaRecallNotifyClient;

#ifdef __cplusplus

class DECLSPEC_UUID("D68BD5B0-D6AA-11d0-9EDA-00A02488FCDE")
CFsaRecallNotifyClient;
#endif

EXTERN_C const CLSID CLSID_CFsaRecoveryRec;

#ifdef __cplusplus

class DECLSPEC_UUID("CECCB131-286D-11d1-993E-0060976A546D")
CFsaRecoveryRec;
#endif

EXTERN_C const CLSID CLSID_CFsaRecallNotifyServer;

#ifdef __cplusplus

class DECLSPEC_UUID("D68BD5B3-D6AA-11d0-9EDA-00A02488FCDE")
CFsaRecallNotifyServer;
#endif
#endif /* __FSALib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


