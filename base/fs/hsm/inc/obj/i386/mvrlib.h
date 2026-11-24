

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for mvrlib.idl:
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


#ifndef __mvrlib_h__
#define __mvrlib_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __CMemIo_FWD_DEFINED__
#define __CMemIo_FWD_DEFINED__

#ifdef __cplusplus
typedef class CMemIo CMemIo;
#else
typedef struct CMemIo CMemIo;
#endif /* __cplusplus */

#endif 	/* __CMemIo_FWD_DEFINED__ */


#ifndef __CNtTapeIo_FWD_DEFINED__
#define __CNtTapeIo_FWD_DEFINED__

#ifdef __cplusplus
typedef class CNtTapeIo CNtTapeIo;
#else
typedef struct CNtTapeIo CNtTapeIo;
#endif /* __cplusplus */

#endif 	/* __CNtTapeIo_FWD_DEFINED__ */


#ifndef __CNtFileIo_FWD_DEFINED__
#define __CNtFileIo_FWD_DEFINED__

#ifdef __cplusplus
typedef class CNtFileIo CNtFileIo;
#else
typedef struct CNtFileIo CNtFileIo;
#endif /* __cplusplus */

#endif 	/* __CNtFileIo_FWD_DEFINED__ */


#ifndef __CLocalStore_FWD_DEFINED__
#define __CLocalStore_FWD_DEFINED__

#ifdef __cplusplus
typedef class CLocalStore CLocalStore;
#else
typedef struct CLocalStore CLocalStore;
#endif /* __cplusplus */

#endif 	/* __CLocalStore_FWD_DEFINED__ */


#ifndef __CFilterIo_FWD_DEFINED__
#define __CFilterIo_FWD_DEFINED__

#ifdef __cplusplus
typedef class CFilterIo CFilterIo;
#else
typedef struct CFilterIo CFilterIo;
#endif /* __cplusplus */

#endif 	/* __CFilterIo_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "MvrInt.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 


#ifndef __MOVERLib_LIBRARY_DEFINED__
#define __MOVERLib_LIBRARY_DEFINED__

/* library MOVERLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_MOVERLib;

EXTERN_C const CLSID CLSID_CMemIo;

#ifdef __cplusplus

class DECLSPEC_UUID("BD030C00-000B-11D0-D0DD-00A0C9190459")
CMemIo;
#endif

EXTERN_C const CLSID CLSID_CNtTapeIo;

#ifdef __cplusplus

class DECLSPEC_UUID("BD040C00-000B-11D0-D0DD-00A0C9190459")
CNtTapeIo;
#endif

EXTERN_C const CLSID CLSID_CNtFileIo;

#ifdef __cplusplus

class DECLSPEC_UUID("BD050C00-000B-11D0-D0DD-00A0C9190459")
CNtFileIo;
#endif

EXTERN_C const CLSID CLSID_CLocalStore;

#ifdef __cplusplus

class DECLSPEC_UUID("BD080C00-000B-11D0-D0DD-00A0C9190459")
CLocalStore;
#endif

EXTERN_C const CLSID CLSID_CFilterIo;

#ifdef __cplusplus

class DECLSPEC_UUID("BD090C00-000B-11D0-D0DD-00A0C9190459")
CFilterIo;
#endif
#endif /* __MOVERLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


