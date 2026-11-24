

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for sfcapi.idl:
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


#ifndef __sfcapi_h__
#define __sfcapi_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

/* header files for imported files */
#include "imports.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

#ifndef __sfcapi_INTERFACE_DEFINED__
#define __sfcapi_INTERFACE_DEFINED__

/* interface sfcapi */
/* [auto_handle][unique][ms_union][version][uuid] */ 

/* client prototype */
/* [fault_status][comm_status] */ error_status_t SfcCli_GetNextProtectedFile( 
    /* [in] */ handle_t hBinding,
    /* [in] */ DWORD FileNumber,
    /* [size_is][size_is][unique][out][in] */ LPBYTE *FileName,
    /* [out][in] */ LPDWORD FileNameSize);
/* server prototype */
/* [fault_status][comm_status] */ error_status_t SfcSrv_GetNextProtectedFile( 
    /* [in] */ handle_t hBinding,
    /* [in] */ DWORD FileNumber,
    /* [size_is][size_is][unique][out][in] */ LPBYTE *FileName,
    /* [out][in] */ LPDWORD FileNameSize);
/* switch prototype */
/* [fault_status][comm_status] */ error_status_t GetNextProtectedFile( 
    /* [in] */ handle_t hBinding,
    /* [in] */ DWORD FileNumber,
    /* [size_is][size_is][unique][out][in] */ LPBYTE *FileName,
    /* [out][in] */ LPDWORD FileNameSize);

/* client prototype */
/* [fault_status][comm_status] */ error_status_t SfcCli_IsFileProtected( 
    /* [in] */ handle_t hBinding,
    /* [unique][string][in] */ PCWSTR ProtFileName);
/* server prototype */
/* [fault_status][comm_status] */ error_status_t SfcSrv_IsFileProtected( 
    /* [in] */ handle_t hBinding,
    /* [unique][string][in] */ PCWSTR ProtFileName);
/* switch prototype */
/* [fault_status][comm_status] */ error_status_t IsFileProtected( 
    /* [in] */ handle_t hBinding,
    /* [unique][string][in] */ PCWSTR ProtFileName);

/* client prototype */
/* [fault_status][comm_status] */ error_status_t SfcCli_FileException( 
    /* [in] */ handle_t hBinding,
    /* [unique][string][in] */ PCWSTR FileName,
    /* [in] */ DWORD ExpectedChangeType);
/* server prototype */
/* [fault_status][comm_status] */ error_status_t SfcSrv_FileException( 
    /* [in] */ handle_t hBinding,
    /* [unique][string][in] */ PCWSTR FileName,
    /* [in] */ DWORD ExpectedChangeType);
/* switch prototype */
/* [fault_status][comm_status] */ error_status_t FileException( 
    /* [in] */ handle_t hBinding,
    /* [unique][string][in] */ PCWSTR FileName,
    /* [in] */ DWORD ExpectedChangeType);

/* client prototype */
/* [fault_status][comm_status] */ error_status_t SfcCli_InitiateScan( 
    /* [in] */ handle_t hBinding,
    /* [in] */ DWORD ScanWhen);
/* server prototype */
/* [fault_status][comm_status] */ error_status_t SfcSrv_InitiateScan( 
    /* [in] */ handle_t hBinding,
    /* [in] */ DWORD ScanWhen);
/* switch prototype */
/* [fault_status][comm_status] */ error_status_t InitiateScan( 
    /* [in] */ handle_t hBinding,
    /* [in] */ DWORD ScanWhen);

/* client prototype */
/* [fault_status][comm_status] */ error_status_t SfcCli_PurgeCache( 
    /* [in] */ handle_t hBinding);
/* server prototype */
/* [fault_status][comm_status] */ error_status_t SfcSrv_PurgeCache( 
    /* [in] */ handle_t hBinding);
/* switch prototype */
/* [fault_status][comm_status] */ error_status_t PurgeCache( 
    /* [in] */ handle_t hBinding);

/* client prototype */
/* [fault_status][comm_status] */ error_status_t SfcCli_SetCacheSize( 
    /* [in] */ handle_t hBinding,
    /* [in] */ DWORD NewSize);
/* server prototype */
/* [fault_status][comm_status] */ error_status_t SfcSrv_SetCacheSize( 
    /* [in] */ handle_t hBinding,
    /* [in] */ DWORD NewSize);
/* switch prototype */
/* [fault_status][comm_status] */ error_status_t SetCacheSize( 
    /* [in] */ handle_t hBinding,
    /* [in] */ DWORD NewSize);

/* client prototype */
/* [fault_status][comm_status] */ error_status_t SfcCli_SetDisable( 
    /* [in] */ handle_t hBinding,
    /* [in] */ DWORD NewValue);
/* server prototype */
/* [fault_status][comm_status] */ error_status_t SfcSrv_SetDisable( 
    /* [in] */ handle_t hBinding,
    /* [in] */ DWORD NewValue);
/* switch prototype */
/* [fault_status][comm_status] */ error_status_t SetDisable( 
    /* [in] */ handle_t hBinding,
    /* [in] */ DWORD NewValue);

/* client prototype */
/* [fault_status][comm_status] */ error_status_t SfcCli_InstallProtectedFiles( 
    /* [in] */ handle_t hBinding,
    /* [size_is][unique][in] */ const LPBYTE FileNames,
    /* [in] */ DWORD FileNamesSize,
    /* [size_is][size_is][unique][out][in] */ LPBYTE *InstallStatus,
    /* [out][in] */ LPDWORD BufferSize,
    /* [out] */ LPDWORD Count,
    /* [in] */ BOOL AllowUI,
    /* [unique][string][in] */ PCWSTR ClassName,
    /* [unique][string][in] */ PCWSTR WindowName);
/* server prototype */
/* [fault_status][comm_status] */ error_status_t SfcSrv_InstallProtectedFiles( 
    /* [in] */ handle_t hBinding,
    /* [size_is][unique][in] */ const LPBYTE FileNames,
    /* [in] */ DWORD FileNamesSize,
    /* [size_is][size_is][unique][out][in] */ LPBYTE *InstallStatus,
    /* [out][in] */ LPDWORD BufferSize,
    /* [out] */ LPDWORD Count,
    /* [in] */ BOOL AllowUI,
    /* [unique][string][in] */ PCWSTR ClassName,
    /* [unique][string][in] */ PCWSTR WindowName);
/* switch prototype */
/* [fault_status][comm_status] */ error_status_t InstallProtectedFiles( 
    /* [in] */ handle_t hBinding,
    /* [size_is][unique][in] */ const LPBYTE FileNames,
    /* [in] */ DWORD FileNamesSize,
    /* [size_is][size_is][unique][out][in] */ LPBYTE *InstallStatus,
    /* [out][in] */ LPDWORD BufferSize,
    /* [out] */ LPDWORD Count,
    /* [in] */ BOOL AllowUI,
    /* [unique][string][in] */ PCWSTR ClassName,
    /* [unique][string][in] */ PCWSTR WindowName);



extern RPC_IF_HANDLE SfcCli_sfcapi_ClientIfHandle;
extern RPC_IF_HANDLE sfcapi_ClientIfHandle;
extern RPC_IF_HANDLE SfcSrv_sfcapi_ServerIfHandle;
#endif /* __sfcapi_INTERFACE_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


