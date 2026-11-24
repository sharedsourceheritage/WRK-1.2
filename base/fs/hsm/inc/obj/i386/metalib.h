

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for metalib.idl:
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


#ifndef __metalib_h__
#define __metalib_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __CSegRec_FWD_DEFINED__
#define __CSegRec_FWD_DEFINED__

#ifdef __cplusplus
typedef class CSegRec CSegRec;
#else
typedef struct CSegRec CSegRec;
#endif /* __cplusplus */

#endif 	/* __CSegRec_FWD_DEFINED__ */


#ifndef __CBagHole_FWD_DEFINED__
#define __CBagHole_FWD_DEFINED__

#ifdef __cplusplus
typedef class CBagHole CBagHole;
#else
typedef struct CBagHole CBagHole;
#endif /* __cplusplus */

#endif 	/* __CBagHole_FWD_DEFINED__ */


#ifndef __CBagInfo_FWD_DEFINED__
#define __CBagInfo_FWD_DEFINED__

#ifdef __cplusplus
typedef class CBagInfo CBagInfo;
#else
typedef struct CBagInfo CBagInfo;
#endif /* __cplusplus */

#endif 	/* __CBagInfo_FWD_DEFINED__ */


#ifndef __CMediaInfo_FWD_DEFINED__
#define __CMediaInfo_FWD_DEFINED__

#ifdef __cplusplus
typedef class CMediaInfo CMediaInfo;
#else
typedef struct CMediaInfo CMediaInfo;
#endif /* __cplusplus */

#endif 	/* __CMediaInfo_FWD_DEFINED__ */


#ifndef __CVolAssign_FWD_DEFINED__
#define __CVolAssign_FWD_DEFINED__

#ifdef __cplusplus
typedef class CVolAssign CVolAssign;
#else
typedef struct CVolAssign CVolAssign;
#endif /* __cplusplus */

#endif 	/* __CVolAssign_FWD_DEFINED__ */


#ifndef __CSegDb_FWD_DEFINED__
#define __CSegDb_FWD_DEFINED__

#ifdef __cplusplus
typedef class CSegDb CSegDb;
#else
typedef struct CSegDb CSegDb;
#endif /* __cplusplus */

#endif 	/* __CSegDb_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "metaint.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 


#ifndef __MetaLib_LIBRARY_DEFINED__
#define __MetaLib_LIBRARY_DEFINED__

/* library MetaLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_MetaLib;

EXTERN_C const CLSID CLSID_CSegRec;

#ifdef __cplusplus

class DECLSPEC_UUID("37F704E6-3EF9-11D0-9E17-00A0C916F120")
CSegRec;
#endif

EXTERN_C const CLSID CLSID_CBagHole;

#ifdef __cplusplus

class DECLSPEC_UUID("450024A3-47D0-11D0-9E1E-00A0C916F120")
CBagHole;
#endif

EXTERN_C const CLSID CLSID_CBagInfo;

#ifdef __cplusplus

class DECLSPEC_UUID("B13FA473-4E1B-11D0-9E22-00A0C916F120")
CBagInfo;
#endif

EXTERN_C const CLSID CLSID_CMediaInfo;

#ifdef __cplusplus

class DECLSPEC_UUID("F0D7AFE0-9026-11d0-9E3B-00A0C916F120")
CMediaInfo;
#endif

EXTERN_C const CLSID CLSID_CVolAssign;

#ifdef __cplusplus

class DECLSPEC_UUID("4A009E81-DC42-11d0-9925-00A0C9058BF6")
CVolAssign;
#endif

EXTERN_C const CLSID CLSID_CSegDb;

#ifdef __cplusplus

class DECLSPEC_UUID("768AD5A4-40C8-11D0-9E17-00A0C916F120")
CSegDb;
#endif
#endif /* __MetaLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


