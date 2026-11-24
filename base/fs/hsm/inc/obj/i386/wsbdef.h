

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for wsbdef.idl:
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


#ifndef __wsbdef_h__
#define __wsbdef_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

/* header files for imported files */
#include "oaidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

/* interface __MIDL_itf_wsbdef_0000 */
/* [local] */ 

typedef struct _COM_IDB_KEY_INFO
    {
    ULONG Type;
    ULONG Size;
    ULONG Flags;
    } 	COM_IDB_KEY_INFO;

typedef struct _COM_IDB_REC_INFO
    {
    ULONG Type;
    CLSID EntityClassId;
    ULONG Flags;
    ULONG MinSize;
    ULONG MaxSize;
    USHORT nKeys;
    } 	COM_IDB_REC_INFO;

typedef /* [v1_enum] */ 
enum _WSB_ACCESS_TYPE
    {	WSB_ACCESS_TYPE_ALL	= 0,
	WSB_ACCESS_TYPE_USER	= 1,
	WSB_ACCESS_TYPE_OPERATOR	= 2,
	WSB_ACCESS_TYPE_ADMINISTRATOR	= 4
    } 	WSB_ACCESS_TYPE;

typedef struct _HSM_SYSTEM_STATE
    {
    ULONG State;
    } 	HSM_SYSTEM_STATE;



extern RPC_IF_HANDLE __MIDL_itf_wsbdef_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_wsbdef_0000_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


