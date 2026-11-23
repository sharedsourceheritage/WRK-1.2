

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0363 */
/* at Wed Feb 25 07:13:11 2004
 */
/* Compiler settings for F:\Depot\SQLVault\mdac28sdk\Samples\oledb\omniprov\source\SDK\obj\i386\TheProvider.idl:
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


#ifndef __TheProvider_h__
#define __TheProvider_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __MSOmniProv_FWD_DEFINED__
#define __MSOmniProv_FWD_DEFINED__

#ifdef __cplusplus
typedef class MSOmniProv MSOmniProv;
#else
typedef struct MSOmniProv MSOmniProv;
#endif /* __cplusplus */

#endif 	/* __MSOmniProv_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 


#ifndef __THEPROVIDERLib_LIBRARY_DEFINED__
#define __THEPROVIDERLib_LIBRARY_DEFINED__

/* library THEPROVIDERLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_THEPROVIDERLib;

EXTERN_C const CLSID CLSID_MSOmniProv;

#ifdef __cplusplus

class DECLSPEC_UUID("B14C8EB2-3632-11D3-AC81-00C04F8DB3D5")
MSOmniProv;
#endif
#endif /* __THEPROVIDERLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


