

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for pnp.idl:
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


#ifndef __pnp_h__
#define __pnp_h__

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

#ifndef __pnp_INTERFACE_DEFINED__
#define __pnp_INTERFACE_DEFINED__

/* interface pnp */
/* [implicit_handle][strict_context_handle][unique][ms_union][version][uuid] */ 

typedef /* [unique][handle] */ LPWSTR PNP_HANDLE;

typedef /* [context_handle] */ void *PNP_NOTIFICATION_CONTEXT;

typedef PNP_NOTIFICATION_CONTEXT *PPNP_NOTIFICATION_CONTEXT;

CONFIGRET PNP_Connect( 
    /* [unique][string][in] */ PNP_HANDLE UNCServerName);

CONFIGRET PNP_Disconnect( 
    /* [unique][string][in] */ PNP_HANDLE UNCServerName);

CONFIGRET PNP_GetVersion( 
    /* [in] */ handle_t hBinding,
    /* [out] */ WORD *pVersion);

CONFIGRET PNP_GetGlobalState( 
    /* [in] */ handle_t hBinding,
    /* [out] */ PULONG pulState,
    /* [in] */ ULONG ulFlags);

CONFIGRET PNP_InitDetection( 
    /* [in] */ handle_t hBinding);

CONFIGRET PNP_ReportLogOn( 
    /* [in] */ handle_t hBinding,
    /* [in] */ BOOL bAdmin,
    /* [in] */ DWORD ProcessID);

CONFIGRET PNP_ValidateDeviceInstance( 
    /* [in] */ handle_t hBinding,
    /* [ref][string][in] */ LPWSTR pDeviceID,
    /* [in] */ ULONG ulFlags);

CONFIGRET PNP_GetRootDeviceInstance( 
    /* [in] */ handle_t hBinding,
    /* [size_is][string][out] */ LPWSTR pDeviceID,
    /* [in] */ ULONG ulLength);

CONFIGRET PNP_GetRelatedDeviceInstance( 
    /* [in] */ handle_t hBinding,
    /* [in] */ ULONG ulRelationship,
    /* [ref][string][in] */ LPWSTR pDeviceID,
    /* [size_is][string][out] */ LPWSTR pRelatedDeviceID,
    /* [out][in] */ PULONG pulLength,
    /* [in] */ ULONG ulFlags);

CONFIGRET PNP_EnumerateSubKeys( 
    /* [in] */ handle_t hBinding,
    /* [in] */ ULONG ulBranch,
    /* [in] */ ULONG ulIndex,
    /* [size_is][string][out] */ PWSTR Buffer,
    /* [in] */ ULONG ulLength,
    /* [out] */ PULONG pulRequiredLen,
    /* [in] */ ULONG ulFlags);

CONFIGRET PNP_GetDeviceList( 
    /* [in] */ handle_t hBinding,
    /* [unique][string][in] */ LPCWSTR pszFilter,
    /* [length_is][size_is][out] */ LPWSTR Buffer,
    /* [out][in] */ PULONG pulLength,
    /* [in] */ ULONG ulFlags);

CONFIGRET PNP_GetDeviceListSize( 
    /* [in] */ handle_t hBinding,
    /* [unique][string][in] */ LPCWSTR pszFilter,
    /* [out] */ PULONG pulLen,
    /* [in] */ ULONG ulFlags);

CONFIGRET PNP_GetDepth( 
    /* [in] */ handle_t hBinding,
    /* [ref][string][in] */ LPCWSTR pszDeviceID,
    /* [out] */ PULONG pulDepth,
    /* [in] */ ULONG ulFlags);

CONFIGRET PNP_GetDeviceRegProp( 
    /* [in] */ handle_t hBinding,
    /* [ref][string][in] */ LPCWSTR pDeviceID,
    /* [in] */ ULONG ulProperty,
    /* [out][in] */ PULONG pulRegDataType,
    /* [length_is][size_is][out] */ LPBYTE Buffer,
    /* [out][in] */ PULONG pulTransferLen,
    /* [out][in] */ PULONG pulLength,
    /* [in] */ ULONG ulFlags);

CONFIGRET PNP_SetDeviceRegProp( 
    /* [in] */ handle_t hBinding,
    /* [ref][string][in] */ LPCWSTR pDeviceID,
    /* [in] */ ULONG ulProperty,
    /* [in] */ ULONG ulDataType,
    /* [size_is][in] */ LPBYTE Buffer,
    /* [in] */ ULONG ulLength,
    /* [in] */ ULONG ulFlags);

CONFIGRET PNP_GetClassInstance( 
    /* [in] */ handle_t hBinding,
    /* [ref][string][in] */ LPCWSTR pDeviceID,
    /* [size_is][string][out] */ LPWSTR pszClassInstance,
    /* [in] */ ULONG ulLength);

CONFIGRET PNP_CreateKey( 
    /* [in] */ handle_t hBinding,
    /* [ref][string][in] */ LPCWSTR pszSubKey,
    /* [in] */ REGSAM samDesired,
    /* [in] */ ULONG ulFlags);

CONFIGRET PNP_DeleteRegistryKey( 
    /* [in] */ handle_t hBinding,
    /* [ref][string][in] */ LPCWSTR pszDeviceID,
    /* [ref][string][in] */ LPCWSTR pszParentKey,
    /* [ref][string][in] */ LPCWSTR pszChildKey,
    /* [in] */ ULONG ulFlags);

CONFIGRET PNP_GetClassCount( 
    /* [in] */ handle_t hBinding,
    /* [out] */ PULONG pulClassCount,
    /* [in] */ ULONG ulFlags);

CONFIGRET PNP_GetClassName( 
    /* [in] */ handle_t hBinding,
    /* [ref][string][in] */ PCWSTR pszClassGuid,
    /* [size_is][string][out] */ PWSTR Buffer,
    /* [out][in] */ PULONG pulLength,
    /* [in] */ ULONG ulFlags);

CONFIGRET PNP_DeleteClassKey( 
    /* [in] */ handle_t hBinding,
    /* [ref][string][in] */ PCWSTR pszClassGuid,
    /* [in] */ ULONG ulFlags);

CONFIGRET PNP_GetInterfaceDeviceAlias( 
    /* [in] */ handle_t hBinding,
    /* [ref][string][in] */ PCWSTR pszInterfaceDevice,
    /* [in] */ LPGUID AliasInterfaceGuid,
    /* [size_is][string][out] */ PWSTR pszAliasInterfaceDevice,
    /* [out][in] */ PULONG pulLength,
    /* [out][in] */ PULONG pulTransferLen,
    /* [in] */ ULONG ulFlags);

CONFIGRET PNP_GetInterfaceDeviceList( 
    /* [in] */ handle_t hBinding,
    /* [in] */ LPGUID InterfaceGuid,
    /* [unique][string][in] */ LPCWSTR pszDeviceID,
    /* [length_is][size_is][out] */ LPWSTR Buffer,
    /* [out][in] */ PULONG pulLength,
    /* [in] */ ULONG ulFlags);

CONFIGRET PNP_GetInterfaceDeviceListSize( 
    /* [in] */ handle_t hBinding,
    /* [out] */ PULONG pulLen,
    /* [in] */ LPGUID InterfaceGuid,
    /* [unique][string][in] */ LPCWSTR pszDeviceID,
    /* [in] */ ULONG ulFlags);

CONFIGRET PNP_RegisterDeviceClassAssociation( 
    /* [in] */ handle_t hBinding,
    /* [unique][string][in] */ LPCWSTR pszDeviceID,
    /* [in] */ LPGUID InterfaceGuid,
    /* [unique][string][in] */ LPCWSTR pszReference,
    /* [size_is][string][out] */ PWSTR pszSymLink,
    /* [out][in] */ PULONG pulLength,
    /* [out][in] */ PULONG pulTransferLen,
    /* [in] */ ULONG ulFlags);

CONFIGRET PNP_UnregisterDeviceClassAssociation( 
    /* [in] */ handle_t hBinding,
    /* [unique][string][in] */ LPCWSTR pszInterfaceDevice,
    /* [in] */ ULONG ulFlags);

CONFIGRET PNP_GetClassRegProp( 
    /* [in] */ handle_t hBinding,
    /* [ref][string][in] */ LPCWSTR pszClassGuid,
    /* [in] */ ULONG ulProperty,
    /* [out][in] */ PULONG pulRegDataType,
    /* [length_is][size_is][out] */ LPBYTE Buffer,
    /* [out][in] */ PULONG pulTransferLen,
    /* [out][in] */ PULONG pulLength,
    /* [in] */ ULONG ulFlags);

CONFIGRET PNP_SetClassRegProp( 
    /* [in] */ handle_t hBinding,
    /* [ref][string][in] */ LPCWSTR pszClassGuid,
    /* [in] */ ULONG ulProperty,
    /* [in] */ ULONG ulDataType,
    /* [size_is][in] */ LPBYTE Buffer,
    /* [in] */ ULONG ulLength,
    /* [in] */ ULONG ulFlags);

CONFIGRET PNP_CreateDevInst( 
    /* [in] */ handle_t hBinding,
    /* [size_is][string][out][in] */ LPWSTR pszDeviceID,
    /* [ref][string][in] */ LPWSTR pszParentDeviceID,
    /* [in] */ ULONG ulLength,
    /* [in] */ ULONG ulFlags);

CONFIGRET PNP_DeviceInstanceAction( 
    /* [in] */ handle_t hBinding,
    /* [in] */ ULONG ulMajorAction,
    /* [in] */ ULONG ulMinorAction,
    /* [unique][string][in] */ PCWSTR pszDeviceInstance1,
    /* [unique][string][in] */ PCWSTR pszDeviceInstance2);

CONFIGRET PNP_GetDeviceStatus( 
    /* [in] */ handle_t hBinding,
    /* [unique][string][in] */ LPCWSTR pDeviceID,
    /* [out] */ PULONG pulStatus,
    /* [out] */ PULONG pulProblem,
    /* [in] */ ULONG ulFlags);

CONFIGRET PNP_SetDeviceProblem( 
    /* [in] */ handle_t hBinding,
    /* [unique][string][in] */ LPCWSTR pDeviceID,
    /* [in] */ ULONG ulProblem,
    /* [in] */ ULONG ulFlags);

CONFIGRET PNP_DisableDevInst( 
    /* [in] */ handle_t hBinding,
    /* [unique][string][in] */ LPCWSTR pDeviceID,
    /* [unique][out][in] */ PPNP_VETO_TYPE pVetoType,
    /* [unique][max_is][string][out][in] */ LPWSTR pszVetoName,
    /* [in] */ ULONG ulNameLength,
    /* [in] */ ULONG ulFlags);

CONFIGRET PNP_UninstallDevInst( 
    /* [in] */ handle_t hBinding,
    /* [unique][string][in] */ LPCWSTR pDeviceID,
    /* [in] */ ULONG ulFlags);

CONFIGRET PNP_AddID( 
    /* [in] */ handle_t hBinding,
    /* [unique][string][in] */ LPCWSTR pszDeviceID,
    /* [ref][string][in] */ LPCWSTR pszID,
    /* [in] */ ULONG ulFlags);

CONFIGRET PNP_RegisterDriver( 
    /* [in] */ handle_t hBinding,
    /* [ref][string][in] */ LPCWSTR pszDeviceID,
    /* [in] */ ULONG ulFlags);

CONFIGRET PNP_QueryRemove( 
    /* [in] */ handle_t hBinding,
    /* [ref][string][in] */ LPCWSTR pszDeviceID,
    /* [unique][out][in] */ PPNP_VETO_TYPE pVetoType,
    /* [unique][max_is][string][out][in] */ LPWSTR pszVetoName,
    /* [in] */ ULONG ulNameLength,
    /* [in] */ ULONG ulFlags);

CONFIGRET PNP_RequestDeviceEject( 
    /* [in] */ handle_t hBinding,
    /* [ref][string][in] */ LPCWSTR pszDeviceID,
    /* [unique][out][in] */ PPNP_VETO_TYPE pVetoType,
    /* [unique][max_is][string][out][in] */ LPWSTR pszVetoName,
    /* [in] */ ULONG ulNameLength,
    /* [in] */ ULONG ulFlags);

CONFIGRET PNP_IsDockStationPresent( 
    /* [in] */ handle_t hBinding,
    /* [unique][out][in] */ PBOOL Present);

CONFIGRET PNP_RequestEjectPC( 
    /* [in] */ handle_t hBinding);

CONFIGRET PNP_HwProfFlags( 
    /* [in] */ handle_t hBinding,
    /* [in] */ ULONG ulAction,
    /* [ref][string][in] */ LPCWSTR pDeviceID,
    /* [in] */ ULONG ulConfig,
    /* [out][in] */ PULONG pulValue,
    /* [unique][out][in] */ PPNP_VETO_TYPE pVetoType,
    /* [unique][max_is][string][out][in] */ LPWSTR pszVetoName,
    /* [in] */ ULONG ulNameLength,
    /* [in] */ ULONG ulFlags);

CONFIGRET PNP_GetHwProfInfo( 
    /* [in] */ handle_t hBinding,
    /* [in] */ ULONG ulIndex,
    /* [ref][out][in] */ HWPROFILEINFO *pHWProfileInfo,
    /* [in] */ ULONG ulProfileInfoSize,
    /* [in] */ ULONG ulFlags);

CONFIGRET PNP_AddEmptyLogConf( 
    /* [in] */ handle_t hBinding,
    /* [ref][string][in] */ LPWSTR pDeviceID,
    /* [in] */ ULONG ulPriority,
    /* [out] */ PULONG pulLogConfTag,
    /* [in] */ ULONG ulFlags);

CONFIGRET PNP_FreeLogConf( 
    /* [in] */ handle_t hBinding,
    /* [ref][string][in] */ LPWSTR pDeviceID,
    /* [in] */ ULONG ulLogConfType,
    /* [in] */ ULONG ulLogConfTag,
    /* [in] */ ULONG ulFlags);

CONFIGRET PNP_GetFirstLogConf( 
    /* [in] */ handle_t hBinding,
    /* [ref][string][in] */ LPWSTR pDeviceID,
    /* [in] */ ULONG ulLogConfType,
    /* [out] */ PULONG pulLogConfTag,
    /* [in] */ ULONG ulFlags);

CONFIGRET PNP_GetNextLogConf( 
    /* [in] */ handle_t hBinding,
    /* [ref][string][in] */ LPWSTR pDeviceID,
    /* [in] */ ULONG ulLogConfType,
    /* [in] */ ULONG ulCurrentTag,
    /* [out] */ PULONG pulNextTag,
    /* [in] */ ULONG ulFlags);

CONFIGRET PNP_GetLogConfPriority( 
    /* [in] */ handle_t hBinding,
    /* [ref][string][in] */ LPWSTR pDeviceID,
    /* [in] */ ULONG ulType,
    /* [in] */ ULONG ulTag,
    /* [out] */ PULONG pPriority,
    /* [in] */ ULONG ulFlags);

CONFIGRET PNP_AddResDes( 
    /* [in] */ handle_t hBinding,
    /* [ref][string][in] */ LPWSTR pDeviceID,
    /* [in] */ ULONG ulLogConfTag,
    /* [in] */ ULONG ulLogConfType,
    /* [in] */ RESOURCEID ResourceID,
    /* [out] */ PULONG pulResourceTag,
    /* [size_is][in] */ LPBYTE ResourceData,
    /* [in] */ ULONG ResourceLen,
    /* [in] */ ULONG ulFlags);

CONFIGRET PNP_FreeResDes( 
    /* [in] */ handle_t hBinding,
    /* [ref][string][in] */ LPWSTR pDeviceID,
    /* [in] */ ULONG ulLogConfTag,
    /* [in] */ ULONG ulLogConfType,
    /* [in] */ RESOURCEID ResourceID,
    /* [in] */ ULONG ulResourceTag,
    /* [out] */ PULONG pulPreviousResType,
    /* [out] */ PULONG pulPreviousResTag,
    /* [in] */ ULONG ulFlags);

CONFIGRET PNP_GetNextResDes( 
    /* [in] */ handle_t hBinding,
    /* [ref][string][in] */ LPWSTR pDeviceID,
    /* [in] */ ULONG ulLogConfTag,
    /* [in] */ ULONG ulLogConfType,
    /* [in] */ RESOURCEID ResourceID,
    /* [in] */ ULONG ulResourceTag,
    /* [out] */ PULONG pulNextResDesTag,
    /* [out] */ PULONG pulNextResDesType,
    /* [in] */ ULONG ulFlags);

CONFIGRET PNP_GetResDesData( 
    /* [in] */ handle_t hBinding,
    /* [ref][string][in] */ LPWSTR pDeviceID,
    /* [in] */ ULONG ulLogConfTag,
    /* [in] */ ULONG ulLogConfType,
    /* [in] */ RESOURCEID ResourceID,
    /* [in] */ ULONG ulResourceTag,
    /* [size_is][out] */ LPBYTE Buffer,
    /* [in] */ ULONG BufferLen,
    /* [in] */ ULONG ulFlags);

CONFIGRET PNP_GetResDesDataSize( 
    /* [in] */ handle_t hBinding,
    /* [ref][string][in] */ LPWSTR pDeviceID,
    /* [in] */ ULONG ulLogConfTag,
    /* [in] */ ULONG ulLogConfType,
    /* [in] */ RESOURCEID ResourceID,
    /* [in] */ ULONG ulResourceTag,
    /* [out] */ PULONG pulSize,
    /* [in] */ ULONG ulFlags);

CONFIGRET PNP_ModifyResDes( 
    /* [in] */ handle_t hBinding,
    /* [ref][string][in] */ LPWSTR pDeviceID,
    /* [in] */ ULONG ulLogConfTag,
    /* [in] */ ULONG ulLogConfType,
    /* [in] */ RESOURCEID CurrentResourceID,
    /* [in] */ RESOURCEID NewResourceID,
    /* [in] */ ULONG ulResourceTag,
    /* [size_is][in] */ LPBYTE ResourceData,
    /* [in] */ ULONG ResourceLen,
    /* [in] */ ULONG ulFlags);

CONFIGRET PNP_DetectResourceConflict( 
    /* [in] */ handle_t hBinding,
    /* [ref][string][in] */ LPWSTR pDeviceID,
    /* [in] */ RESOURCEID ResourceID,
    /* [size_is][in] */ LPBYTE ResourceData,
    /* [in] */ ULONG ResourceLen,
    /* [out] */ PBOOL pbConflictDetected,
    /* [in] */ ULONG ulFlags);

CONFIGRET PNP_QueryResConfList( 
    /* [in] */ handle_t hBinding,
    /* [ref][string][in] */ LPWSTR pDeviceID,
    /* [in] */ RESOURCEID ResourceID,
    /* [size_is][in] */ LPBYTE ResourceData,
    /* [in] */ ULONG ResourceLen,
    /* [size_is][out] */ LPBYTE Buffer,
    /* [in] */ ULONG BufferLen,
    /* [in] */ ULONG ulFlags);

CONFIGRET PNP_SetHwProf( 
    /* [in] */ handle_t hBinding,
    /* [in] */ ULONG ulHardwareProfile,
    /* [in] */ ULONG ulFlags);

CONFIGRET PNP_QueryArbitratorFreeData( 
    /* [in] */ handle_t hBinding,
    /* [size_is][out] */ LPBYTE pData,
    /* [in] */ ULONG ulDataLen,
    /* [ref][string][in] */ LPCWSTR pszDeviceID,
    /* [in] */ RESOURCEID ResourceID,
    /* [in] */ ULONG ulFlags);

CONFIGRET PNP_QueryArbitratorFreeSize( 
    /* [in] */ handle_t hBinding,
    /* [out] */ PULONG pulSize,
    /* [ref][string][in] */ LPCWSTR pszDeviceID,
    /* [in] */ RESOURCEID ResourceID,
    /* [in] */ ULONG ulFlags);

CONFIGRET PNP_RunDetection( 
    /* [in] */ handle_t hBinding,
    /* [in] */ ULONG ulFlags);

CONFIGRET PNP_RegisterNotification( 
    /* [in] */ handle_t hBinding,
    /* [in] */ ULONG_PTR hRecipient,
    /* [ref][string][in] */ LPWSTR ServiceName,
    /* [size_is][in] */ LPBYTE NotificationFilter,
    /* [in] */ ULONG ulSize,
    /* [in] */ DWORD Flags,
    /* [out] */ PNP_NOTIFICATION_CONTEXT *Context,
    /* [in] */ ULONG hProcess,
    /* [in] */ ULONG64 *ClientContext);

CONFIGRET PNP_UnregisterNotification( 
    /* [in] */ handle_t hBinding,
    /* [out][in] */ PNP_NOTIFICATION_CONTEXT *Context);

CONFIGRET PNP_GetCustomDevProp( 
    /* [in] */ handle_t hBinding,
    /* [ref][string][in] */ LPCWSTR pDeviceID,
    /* [ref][string][in] */ LPCWSTR CustomPropName,
    /* [out] */ PULONG pulRegDataType,
    /* [length_is][size_is][out] */ LPBYTE Buffer,
    /* [out] */ PULONG pulTransferLen,
    /* [out][in] */ PULONG pulLength,
    /* [in] */ ULONG ulFlags);

CONFIGRET PNP_GetVersionInternal( 
    /* [in] */ handle_t hBinding,
    /* [out][in] */ WORD *pwVersion);

CONFIGRET PNP_GetBlockedDriverInfo( 
    /* [in] */ handle_t hBinding,
    /* [length_is][size_is][out] */ LPBYTE Buffer,
    /* [out] */ PULONG pulTransferLen,
    /* [out][in] */ PULONG pulLength,
    /* [in] */ ULONG ulFlags);

CONFIGRET PNP_GetServerSideDeviceInstallFlags( 
    /* [in] */ handle_t hBinding,
    /* [out] */ PULONG pulSSDIFlags,
    /* [in] */ ULONG ulFlags);


extern handle_t pnp_handle;


extern RPC_IF_HANDLE pnp_ClientIfHandle;
extern RPC_IF_HANDLE pnp_ServerIfHandle;
#endif /* __pnp_INTERFACE_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

handle_t __RPC_USER PNP_HANDLE_bind  ( PNP_HANDLE );
void     __RPC_USER PNP_HANDLE_unbind( PNP_HANDLE, handle_t );

void __RPC_USER PNP_NOTIFICATION_CONTEXT_rundown( PNP_NOTIFICATION_CONTEXT );

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


