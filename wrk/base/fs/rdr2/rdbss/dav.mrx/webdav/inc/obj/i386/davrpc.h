

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for davrpc.idl, davrpc.acf:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, oldnames, robust
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


#ifndef __davrpc_h__
#define __davrpc_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

/* header files for imported files */
#include "wtypes.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

#ifndef __davclntrpc_INTERFACE_DEFINED__
#define __davclntrpc_INTERFACE_DEFINED__

/* interface davclntrpc */
/* [explicit_handle][unique][version][uuid] */ 

DWORD DavrCreateConnection( 
    /* [in] */ handle_t IDL_handle,
    /* [unique][string][in] */ wchar_t *LocalName,
    /* [string][in] */ wchar_t *RemoteName,
    /* [in] */ DWORD Type,
    /* [unique][string][in] */ wchar_t *Password,
    /* [unique][string][in] */ wchar_t *UserName);

DWORD DavrDoesServerDoDav( 
    /* [in] */ handle_t IDL_handle,
    /* [ref][string][in] */ wchar_t *ServerName,
    /* [ref][out][in] */ boolean *DoesDav);

DWORD DavrIsValidShare( 
    /* [in] */ handle_t IDL_handle,
    /* [ref][string][in] */ wchar_t *ServerName,
    /* [ref][string][in] */ wchar_t *ShareName,
    /* [ref][out][in] */ boolean *ValidShare);

DWORD DavrEnumNetUses( 
    /* [in] */ handle_t IDL_handle,
    /* [ref][out][in] */ DWORD *Index,
    /* [string][out] */ LPWSTR *LocalName,
    /* [string][out] */ LPWSTR *RemoteName,
    /* [ref][out][in] */ boolean *Done);

DWORD DavrEnumShares( 
    /* [in] */ handle_t IDL_handle,
    /* [ref][out][in] */ DWORD *Index,
    /* [ref][string][in] */ wchar_t *ServerName,
    /* [string][out] */ LPWSTR *RemoteName,
    /* [ref][out][in] */ boolean *Done);

DWORD DavrEnumServers( 
    /* [in] */ handle_t IDL_handle,
    /* [ref][out][in] */ DWORD *Index,
    /* [string][out] */ LPWSTR *RemoteName,
    /* [ref][out][in] */ boolean *Done);

DWORD DavrGetConnection( 
    /* [in] */ handle_t IDL_handle,
    /* [ref][string][in] */ wchar_t *LocalName,
    /* [string][out] */ LPWSTR *RemoteName,
    /* [ref][out][in] */ boolean *Connected);

DWORD DavrDeleteConnection( 
    /* [in] */ handle_t IDL_handle,
    /* [ref][string][in] */ wchar_t *ConnectionName,
    /* [in] */ DWORD UseForce);

DWORD DavrGetUser( 
    /* [in] */ handle_t IDL_handle,
    /* [ref][string][in] */ wchar_t *ConnectionName,
    /* [string][out] */ LPWSTR *UserName);

DWORD DavrConnectionExist( 
    /* [in] */ handle_t IDL_handle,
    /* [ref][string][in] */ wchar_t *ConnectionName);

DWORD DavrWinlogonLogonEvent( 
    /* [in] */ handle_t IDL_handle);

DWORD DavrWinlogonLogoffEvent( 
    /* [in] */ handle_t IDL_handle);

DWORD DavrGetDiskSpaceUsage( 
    /* [in] */ handle_t IDL_handle,
    /* [ref][length_is][size_is][out] */ wchar_t *lptzLocation,
    /* [range][in] */ long Size,
    /* [ref][out] */ long *pLength,
    /* [ref][out][in] */ ULARGE_INTEGER *lpMaxSpace,
    /* [ref][out][in] */ ULARGE_INTEGER *lpUsedSpace);

DWORD DavrFreeUsedDiskSpace( 
    /* [in] */ handle_t IDL_handle,
    /* [in] */ DWORD dwPercent);

DWORD DavrGetTheLockOwnerOfTheFile( 
    /* [in] */ handle_t IDL_handle,
    /* [ref][string][in] */ wchar_t *FileName,
    /* [string][out] */ LPWSTR *LockOwnerName);



extern RPC_IF_HANDLE davclntrpc_ClientIfHandle;
extern RPC_IF_HANDLE davclntrpc_ServerIfHandle;
#endif /* __davclntrpc_INTERFACE_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


