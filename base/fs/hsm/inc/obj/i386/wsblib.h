

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for wsblib.idl:
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


#ifndef __wsblib_h__
#define __wsblib_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __CWsbGuid_FWD_DEFINED__
#define __CWsbGuid_FWD_DEFINED__

#ifdef __cplusplus
typedef class CWsbGuid CWsbGuid;
#else
typedef struct CWsbGuid CWsbGuid;
#endif /* __cplusplus */

#endif 	/* __CWsbGuid_FWD_DEFINED__ */


#ifndef __CWsbIndexedEnum_FWD_DEFINED__
#define __CWsbIndexedEnum_FWD_DEFINED__

#ifdef __cplusplus
typedef class CWsbIndexedEnum CWsbIndexedEnum;
#else
typedef struct CWsbIndexedEnum CWsbIndexedEnum;
#endif /* __cplusplus */

#endif 	/* __CWsbIndexedEnum_FWD_DEFINED__ */


#ifndef __CWsbOrderedCollection_FWD_DEFINED__
#define __CWsbOrderedCollection_FWD_DEFINED__

#ifdef __cplusplus
typedef class CWsbOrderedCollection CWsbOrderedCollection;
#else
typedef struct CWsbOrderedCollection CWsbOrderedCollection;
#endif /* __cplusplus */

#endif 	/* __CWsbOrderedCollection_FWD_DEFINED__ */


#ifndef __CWsbString_FWD_DEFINED__
#define __CWsbString_FWD_DEFINED__

#ifdef __cplusplus
typedef class CWsbString CWsbString;
#else
typedef struct CWsbString CWsbString;
#endif /* __cplusplus */

#endif 	/* __CWsbString_FWD_DEFINED__ */


#ifndef __CWsbDbSys_FWD_DEFINED__
#define __CWsbDbSys_FWD_DEFINED__

#ifdef __cplusplus
typedef class CWsbDbSys CWsbDbSys;
#else
typedef struct CWsbDbSys CWsbDbSys;
#endif /* __cplusplus */

#endif 	/* __CWsbDbSys_FWD_DEFINED__ */


#ifndef __CWsbDb_FWD_DEFINED__
#define __CWsbDb_FWD_DEFINED__

#ifdef __cplusplus
typedef class CWsbDb CWsbDb;
#else
typedef struct CWsbDb CWsbDb;
#endif /* __cplusplus */

#endif 	/* __CWsbDb_FWD_DEFINED__ */


#ifndef __CWsbDbKey_FWD_DEFINED__
#define __CWsbDbKey_FWD_DEFINED__

#ifdef __cplusplus
typedef class CWsbDbKey CWsbDbKey;
#else
typedef struct CWsbDbKey CWsbDbKey;
#endif /* __cplusplus */

#endif 	/* __CWsbDbKey_FWD_DEFINED__ */


#ifndef __CWsbTrace_FWD_DEFINED__
#define __CWsbTrace_FWD_DEFINED__

#ifdef __cplusplus
typedef class CWsbTrace CWsbTrace;
#else
typedef struct CWsbTrace CWsbTrace;
#endif /* __cplusplus */

#endif 	/* __CWsbTrace_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "wsbint.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 


#ifndef __WSBLib_LIBRARY_DEFINED__
#define __WSBLib_LIBRARY_DEFINED__

/* library WSBLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_WSBLib;

EXTERN_C const CLSID CLSID_CWsbGuid;

#ifdef __cplusplus

class DECLSPEC_UUID("A0FF1F42-237A-11D0-81BA-00A0C91180F2")
CWsbGuid;
#endif

EXTERN_C const CLSID CLSID_CWsbIndexedEnum;

#ifdef __cplusplus

class DECLSPEC_UUID("DB35D732-21E9-11D0-81B8-00A0C91180F2")
CWsbIndexedEnum;
#endif

EXTERN_C const CLSID CLSID_CWsbOrderedCollection;

#ifdef __cplusplus

class DECLSPEC_UUID("9C7D6F13-1562-11D0-81AC-00A0C91180F2")
CWsbOrderedCollection;
#endif

EXTERN_C const CLSID CLSID_CWsbString;

#ifdef __cplusplus

class DECLSPEC_UUID("DB35D733-21E9-11D0-81B8-00A0C91180F2")
CWsbString;
#endif

EXTERN_C const CLSID CLSID_CWsbDbSys;

#ifdef __cplusplus

class DECLSPEC_UUID("5D1A1AD2-C658-11d0-991E-00A0C9058BF6")
CWsbDbSys;
#endif

EXTERN_C const CLSID CLSID_CWsbDb;

#ifdef __cplusplus

class DECLSPEC_UUID("46CE9ED4-447C-11D0-98FC-00A0C9058BF6")
CWsbDb;
#endif

EXTERN_C const CLSID CLSID_CWsbDbKey;

#ifdef __cplusplus

class DECLSPEC_UUID("46CE9EDE-447C-11D0-98FC-00A0C9058BF6")
CWsbDbKey;
#endif

EXTERN_C const CLSID CLSID_CWsbTrace;

#ifdef __cplusplus

class DECLSPEC_UUID("389E18D0-7EE3-11d0-9E35-00A0C916F120")
CWsbTrace;
#endif
#endif /* __WSBLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


