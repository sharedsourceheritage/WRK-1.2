

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for tsklib.idl:
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


#ifndef __tsklib_h__
#define __tsklib_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __CHsmTskMgr_FWD_DEFINED__
#define __CHsmTskMgr_FWD_DEFINED__

#ifdef __cplusplus
typedef class CHsmTskMgr CHsmTskMgr;
#else
typedef struct CHsmTskMgr CHsmTskMgr;
#endif /* __cplusplus */

#endif 	/* __CHsmTskMgr_FWD_DEFINED__ */


#ifndef __CHsmWorkQueue_FWD_DEFINED__
#define __CHsmWorkQueue_FWD_DEFINED__

#ifdef __cplusplus
typedef class CHsmWorkQueue CHsmWorkQueue;
#else
typedef struct CHsmWorkQueue CHsmWorkQueue;
#endif /* __cplusplus */

#endif 	/* __CHsmWorkQueue_FWD_DEFINED__ */


#ifndef __CHsmWorkItem_FWD_DEFINED__
#define __CHsmWorkItem_FWD_DEFINED__

#ifdef __cplusplus
typedef class CHsmWorkItem CHsmWorkItem;
#else
typedef struct CHsmWorkItem CHsmWorkItem;
#endif /* __cplusplus */

#endif 	/* __CHsmWorkItem_FWD_DEFINED__ */


#ifndef __CHsmRecallQueue_FWD_DEFINED__
#define __CHsmRecallQueue_FWD_DEFINED__

#ifdef __cplusplus
typedef class CHsmRecallQueue CHsmRecallQueue;
#else
typedef struct CHsmRecallQueue CHsmRecallQueue;
#endif /* __cplusplus */

#endif 	/* __CHsmRecallQueue_FWD_DEFINED__ */


#ifndef __CHsmRecallItem_FWD_DEFINED__
#define __CHsmRecallItem_FWD_DEFINED__

#ifdef __cplusplus
typedef class CHsmRecallItem CHsmRecallItem;
#else
typedef struct CHsmRecallItem CHsmRecallItem;
#endif /* __cplusplus */

#endif 	/* __CHsmRecallItem_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "jobdef.h"
#include "tskint.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 


#ifndef __TASKLib_LIBRARY_DEFINED__
#define __TASKLib_LIBRARY_DEFINED__

/* library TASKLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_TASKLib;

EXTERN_C const CLSID CLSID_CHsmTskMgr;

#ifdef __cplusplus

class DECLSPEC_UUID("7DDE1826-4F86-11D0-9E22-00A0C916F120")
CHsmTskMgr;
#endif

EXTERN_C const CLSID CLSID_CHsmWorkQueue;

#ifdef __cplusplus

class DECLSPEC_UUID("247DF540-C558-11d0-B16F-00A0C916F120")
CHsmWorkQueue;
#endif

EXTERN_C const CLSID CLSID_CHsmWorkItem;

#ifdef __cplusplus

class DECLSPEC_UUID("23E45B60-C598-11d0-B16F-00A0C916F120")
CHsmWorkItem;
#endif

EXTERN_C const CLSID CLSID_CHsmRecallQueue;

#ifdef __cplusplus

class DECLSPEC_UUID("9b832d5c-c5e0-4ac8-a573-feb8bb6597ac")
CHsmRecallQueue;
#endif

EXTERN_C const CLSID CLSID_CHsmRecallItem;

#ifdef __cplusplus

class DECLSPEC_UUID("a915d0f3-5fbe-400f-bf44-157c052884a7")
CHsmRecallItem;
#endif
#endif /* __TASKLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


