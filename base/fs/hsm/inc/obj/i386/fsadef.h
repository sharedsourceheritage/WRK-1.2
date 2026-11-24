

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for fsadef.idl:
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


#ifndef __fsadef_h__
#define __fsadef_h__

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

/* interface __MIDL_itf_fsadef_0000 */
/* [local] */ 

typedef /* [v1_enum] */ 
enum _FSA_REQUEST_ACTION
    {	FSA_REQUEST_ACTION_NONE	= 0,
	FSA_REQUEST_ACTION_DELETE	= 1,
	FSA_REQUEST_ACTION_FILTER_RECALL	= 2,
	FSA_REQUEST_ACTION_PREMIGRATE	= 3,
	FSA_REQUEST_ACTION_RECALL	= 4,
	FSA_REQUEST_ACTION_VALIDATE	= 5,
	FSA_REQUEST_ACTION_FILTER_READ	= 6,
	FSA_REQUEST_ACTION_VALIDATE_FOR_TRUNCATE	= 7
    } 	FSA_REQUEST_ACTION;

typedef /* [v1_enum] */ 
enum _FSA_RESULT_ACTION
    {	FSA_RESULT_ACTION_NONE	= 0,
	FSA_RESULT_ACTION_DELETE	= 1,
	FSA_RESULT_ACTION_DELETEPLACEHOLDER	= 2,
	FSA_RESULT_ACTION_LIST	= 3,
	FSA_RESULT_ACTION_OPEN	= 4,
	FSA_RESULT_ACTION_PEEK	= 5,
	FSA_RESULT_ACTION_REPARSE	= 6,
	FSA_RESULT_ACTION_TRUNCATE	= 7,
	FSA_RESULT_ACTION_REWRITEPLACEHOLDER	= 8,
	FSA_RESULT_ACTION_RECALLEDDATA	= 9,
	FSA_RESULT_ACTION_NORECALL	= 10,
	FSA_RESULT_ACTION_FAIL	= 11,
	FSA_RESULT_ACTION_VALIDATE_OK	= 12,
	FSA_RESULT_ACTION_VALIDATE_BAD	= 13,
	FSA_RESULT_ACTION_VALIDATE_FOR_TRUNCATE_OK	= 14,
	FSA_RESULT_ACTION_VALIDATE_FOR_TRUNCATE_BAD	= 15
    } 	FSA_RESULT_ACTION;

typedef struct _FSA_PLACEHOLDER
    {
    BOOL isTruncated;
    BOOL truncateOnClose;
    BOOL premigrateOnClose;
    FILETIME migrationTime;
    GUID hsmId;
    GUID bagId;
    LONGLONG fileStart;
    LONGLONG fileSize;
    LONGLONG dataStart;
    LONGLONG dataSize;
    LONGLONG fileVersionId;
    LONGLONG verificationData;
    ULONG verificationType;
    ULONG recallCount;
    FILETIME recallTime;
    LONGLONG dataStreamStart;
    LONGLONG dataStreamSize;
    LONG dataStream;
    ULONG dataStreamCRCType;
    LONGLONG dataStreamCRC;
    } 	FSA_PLACEHOLDER;

typedef struct _FSA_PLACEHOLDER *PFSA_PLACEHOLDER;



extern RPC_IF_HANDLE __MIDL_itf_fsadef_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_fsadef_0000_v0_0_s_ifspec;

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


