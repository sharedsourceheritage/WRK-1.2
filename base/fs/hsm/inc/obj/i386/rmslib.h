

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for rmslib.idl:
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


#ifndef __rmslib_h__
#define __rmslib_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __CRmsServer_FWD_DEFINED__
#define __CRmsServer_FWD_DEFINED__

#ifdef __cplusplus
typedef class CRmsServer CRmsServer;
#else
typedef struct CRmsServer CRmsServer;
#endif /* __cplusplus */

#endif 	/* __CRmsServer_FWD_DEFINED__ */


#ifndef __CRmsLibrary_FWD_DEFINED__
#define __CRmsLibrary_FWD_DEFINED__

#ifdef __cplusplus
typedef class CRmsLibrary CRmsLibrary;
#else
typedef struct CRmsLibrary CRmsLibrary;
#endif /* __cplusplus */

#endif 	/* __CRmsLibrary_FWD_DEFINED__ */


#ifndef __CRmsDriveClass_FWD_DEFINED__
#define __CRmsDriveClass_FWD_DEFINED__

#ifdef __cplusplus
typedef class CRmsDriveClass CRmsDriveClass;
#else
typedef struct CRmsDriveClass CRmsDriveClass;
#endif /* __cplusplus */

#endif 	/* __CRmsDriveClass_FWD_DEFINED__ */


#ifndef __CRmsCartridge_FWD_DEFINED__
#define __CRmsCartridge_FWD_DEFINED__

#ifdef __cplusplus
typedef class CRmsCartridge CRmsCartridge;
#else
typedef struct CRmsCartridge CRmsCartridge;
#endif /* __cplusplus */

#endif 	/* __CRmsCartridge_FWD_DEFINED__ */


#ifndef __CRmsDrive_FWD_DEFINED__
#define __CRmsDrive_FWD_DEFINED__

#ifdef __cplusplus
typedef class CRmsDrive CRmsDrive;
#else
typedef struct CRmsDrive CRmsDrive;
#endif /* __cplusplus */

#endif 	/* __CRmsDrive_FWD_DEFINED__ */


#ifndef __CRmsStorageSlot_FWD_DEFINED__
#define __CRmsStorageSlot_FWD_DEFINED__

#ifdef __cplusplus
typedef class CRmsStorageSlot CRmsStorageSlot;
#else
typedef struct CRmsStorageSlot CRmsStorageSlot;
#endif /* __cplusplus */

#endif 	/* __CRmsStorageSlot_FWD_DEFINED__ */


#ifndef __CRmsMediumChanger_FWD_DEFINED__
#define __CRmsMediumChanger_FWD_DEFINED__

#ifdef __cplusplus
typedef class CRmsMediumChanger CRmsMediumChanger;
#else
typedef struct CRmsMediumChanger CRmsMediumChanger;
#endif /* __cplusplus */

#endif 	/* __CRmsMediumChanger_FWD_DEFINED__ */


#ifndef __CRmsIEPort_FWD_DEFINED__
#define __CRmsIEPort_FWD_DEFINED__

#ifdef __cplusplus
typedef class CRmsIEPort CRmsIEPort;
#else
typedef struct CRmsIEPort CRmsIEPort;
#endif /* __cplusplus */

#endif 	/* __CRmsIEPort_FWD_DEFINED__ */


#ifndef __CRmsMediaSet_FWD_DEFINED__
#define __CRmsMediaSet_FWD_DEFINED__

#ifdef __cplusplus
typedef class CRmsMediaSet CRmsMediaSet;
#else
typedef struct CRmsMediaSet CRmsMediaSet;
#endif /* __cplusplus */

#endif 	/* __CRmsMediaSet_FWD_DEFINED__ */


#ifndef __CRmsRequest_FWD_DEFINED__
#define __CRmsRequest_FWD_DEFINED__

#ifdef __cplusplus
typedef class CRmsRequest CRmsRequest;
#else
typedef struct CRmsRequest CRmsRequest;
#endif /* __cplusplus */

#endif 	/* __CRmsRequest_FWD_DEFINED__ */


#ifndef __CRmsPartition_FWD_DEFINED__
#define __CRmsPartition_FWD_DEFINED__

#ifdef __cplusplus
typedef class CRmsPartition CRmsPartition;
#else
typedef struct CRmsPartition CRmsPartition;
#endif /* __cplusplus */

#endif 	/* __CRmsPartition_FWD_DEFINED__ */


#ifndef __CRmsClient_FWD_DEFINED__
#define __CRmsClient_FWD_DEFINED__

#ifdef __cplusplus
typedef class CRmsClient CRmsClient;
#else
typedef struct CRmsClient CRmsClient;
#endif /* __cplusplus */

#endif 	/* __CRmsClient_FWD_DEFINED__ */


#ifndef __CRmsNTMS_FWD_DEFINED__
#define __CRmsNTMS_FWD_DEFINED__

#ifdef __cplusplus
typedef class CRmsNTMS CRmsNTMS;
#else
typedef struct CRmsNTMS CRmsNTMS;
#endif /* __cplusplus */

#endif 	/* __CRmsNTMS_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "RmsInt.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 


#ifndef __RMSLib_LIBRARY_DEFINED__
#define __RMSLib_LIBRARY_DEFINED__

/* library RMSLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_RMSLib;

EXTERN_C const CLSID CLSID_CRmsServer;

#ifdef __cplusplus

class DECLSPEC_UUID("FE37FA01-3729-11D0-8CF4-00A0C9190459")
CRmsServer;
#endif

EXTERN_C const CLSID CLSID_CRmsLibrary;

#ifdef __cplusplus

class DECLSPEC_UUID("FE37FA02-3729-11D0-8CF4-00A0C9190459")
CRmsLibrary;
#endif

EXTERN_C const CLSID CLSID_CRmsDriveClass;

#ifdef __cplusplus

class DECLSPEC_UUID("FE37FA03-3729-11D0-8CF4-00A0C9190459")
CRmsDriveClass;
#endif

EXTERN_C const CLSID CLSID_CRmsCartridge;

#ifdef __cplusplus

class DECLSPEC_UUID("FE37FA04-3729-11D0-8CF4-00A0C9190459")
CRmsCartridge;
#endif

EXTERN_C const CLSID CLSID_CRmsDrive;

#ifdef __cplusplus

class DECLSPEC_UUID("FE37FA05-3729-11D0-8CF4-00A0C9190459")
CRmsDrive;
#endif

EXTERN_C const CLSID CLSID_CRmsStorageSlot;

#ifdef __cplusplus

class DECLSPEC_UUID("FE37FA06-3729-11D0-8CF4-00A0C9190459")
CRmsStorageSlot;
#endif

EXTERN_C const CLSID CLSID_CRmsMediumChanger;

#ifdef __cplusplus

class DECLSPEC_UUID("FE37FA07-3729-11D0-8CF4-00A0C9190459")
CRmsMediumChanger;
#endif

EXTERN_C const CLSID CLSID_CRmsIEPort;

#ifdef __cplusplus

class DECLSPEC_UUID("FE37FA08-3729-11D0-8CF4-00A0C9190459")
CRmsIEPort;
#endif

EXTERN_C const CLSID CLSID_CRmsMediaSet;

#ifdef __cplusplus

class DECLSPEC_UUID("FE37FA09-3729-11D0-8CF4-00A0C9190459")
CRmsMediaSet;
#endif

EXTERN_C const CLSID CLSID_CRmsRequest;

#ifdef __cplusplus

class DECLSPEC_UUID("FE37FA10-3729-11D0-8CF4-00A0C9190459")
CRmsRequest;
#endif

EXTERN_C const CLSID CLSID_CRmsPartition;

#ifdef __cplusplus

class DECLSPEC_UUID("FE37FA11-3729-11D0-8CF4-00A0C9190459")
CRmsPartition;
#endif

EXTERN_C const CLSID CLSID_CRmsClient;

#ifdef __cplusplus

class DECLSPEC_UUID("FE37FA12-3729-11D0-8CF4-00A0C9190459")
CRmsClient;
#endif

EXTERN_C const CLSID CLSID_CRmsNTMS;

#ifdef __cplusplus

class DECLSPEC_UUID("FE37FA13-3729-11D0-8CF4-00A0C9190459")
CRmsNTMS;
#endif
#endif /* __RMSLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


