

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for joblib.idl:
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


#ifndef __joblib_h__
#define __joblib_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __CHsmActionCopy_FWD_DEFINED__
#define __CHsmActionCopy_FWD_DEFINED__

#ifdef __cplusplus
typedef class CHsmActionCopy CHsmActionCopy;
#else
typedef struct CHsmActionCopy CHsmActionCopy;
#endif /* __cplusplus */

#endif 	/* __CHsmActionCopy_FWD_DEFINED__ */


#ifndef __CHsmActionDelete_FWD_DEFINED__
#define __CHsmActionDelete_FWD_DEFINED__

#ifdef __cplusplus
typedef class CHsmActionDelete CHsmActionDelete;
#else
typedef struct CHsmActionDelete CHsmActionDelete;
#endif /* __cplusplus */

#endif 	/* __CHsmActionDelete_FWD_DEFINED__ */


#ifndef __CHsmActionManage_FWD_DEFINED__
#define __CHsmActionManage_FWD_DEFINED__

#ifdef __cplusplus
typedef class CHsmActionManage CHsmActionManage;
#else
typedef struct CHsmActionManage CHsmActionManage;
#endif /* __cplusplus */

#endif 	/* __CHsmActionManage_FWD_DEFINED__ */


#ifndef __CHsmActionMigrate_FWD_DEFINED__
#define __CHsmActionMigrate_FWD_DEFINED__

#ifdef __cplusplus
typedef class CHsmActionMigrate CHsmActionMigrate;
#else
typedef struct CHsmActionMigrate CHsmActionMigrate;
#endif /* __cplusplus */

#endif 	/* __CHsmActionMigrate_FWD_DEFINED__ */


#ifndef __CHsmActionMove_FWD_DEFINED__
#define __CHsmActionMove_FWD_DEFINED__

#ifdef __cplusplus
typedef class CHsmActionMove CHsmActionMove;
#else
typedef struct CHsmActionMove CHsmActionMove;
#endif /* __cplusplus */

#endif 	/* __CHsmActionMove_FWD_DEFINED__ */


#ifndef __CHsmActionOnResourcePostValidate_FWD_DEFINED__
#define __CHsmActionOnResourcePostValidate_FWD_DEFINED__

#ifdef __cplusplus
typedef class CHsmActionOnResourcePostValidate CHsmActionOnResourcePostValidate;
#else
typedef struct CHsmActionOnResourcePostValidate CHsmActionOnResourcePostValidate;
#endif /* __cplusplus */

#endif 	/* __CHsmActionOnResourcePostValidate_FWD_DEFINED__ */


#ifndef __CHsmActionOnResourcePreValidate_FWD_DEFINED__
#define __CHsmActionOnResourcePreValidate_FWD_DEFINED__

#ifdef __cplusplus
typedef class CHsmActionOnResourcePreValidate CHsmActionOnResourcePreValidate;
#else
typedef struct CHsmActionOnResourcePreValidate CHsmActionOnResourcePreValidate;
#endif /* __cplusplus */

#endif 	/* __CHsmActionOnResourcePreValidate_FWD_DEFINED__ */


#ifndef __CHsmActionRecall_FWD_DEFINED__
#define __CHsmActionRecall_FWD_DEFINED__

#ifdef __cplusplus
typedef class CHsmActionRecall CHsmActionRecall;
#else
typedef struct CHsmActionRecall CHsmActionRecall;
#endif /* __cplusplus */

#endif 	/* __CHsmActionRecall_FWD_DEFINED__ */


#ifndef __CHsmActionRecycle_FWD_DEFINED__
#define __CHsmActionRecycle_FWD_DEFINED__

#ifdef __cplusplus
typedef class CHsmActionRecycle CHsmActionRecycle;
#else
typedef struct CHsmActionRecycle CHsmActionRecycle;
#endif /* __cplusplus */

#endif 	/* __CHsmActionRecycle_FWD_DEFINED__ */


#ifndef __CHsmActionTruncate_FWD_DEFINED__
#define __CHsmActionTruncate_FWD_DEFINED__

#ifdef __cplusplus
typedef class CHsmActionTruncate CHsmActionTruncate;
#else
typedef struct CHsmActionTruncate CHsmActionTruncate;
#endif /* __cplusplus */

#endif 	/* __CHsmActionTruncate_FWD_DEFINED__ */


#ifndef __CHsmActionUnmanage_FWD_DEFINED__
#define __CHsmActionUnmanage_FWD_DEFINED__

#ifdef __cplusplus
typedef class CHsmActionUnmanage CHsmActionUnmanage;
#else
typedef struct CHsmActionUnmanage CHsmActionUnmanage;
#endif /* __cplusplus */

#endif 	/* __CHsmActionUnmanage_FWD_DEFINED__ */


#ifndef __CHsmActionOnResourcePreUnmanage_FWD_DEFINED__
#define __CHsmActionOnResourcePreUnmanage_FWD_DEFINED__

#ifdef __cplusplus
typedef class CHsmActionOnResourcePreUnmanage CHsmActionOnResourcePreUnmanage;
#else
typedef struct CHsmActionOnResourcePreUnmanage CHsmActionOnResourcePreUnmanage;
#endif /* __cplusplus */

#endif 	/* __CHsmActionOnResourcePreUnmanage_FWD_DEFINED__ */


#ifndef __CHsmActionOnResourcePostUnmanage_FWD_DEFINED__
#define __CHsmActionOnResourcePostUnmanage_FWD_DEFINED__

#ifdef __cplusplus
typedef class CHsmActionOnResourcePostUnmanage CHsmActionOnResourcePostUnmanage;
#else
typedef struct CHsmActionOnResourcePostUnmanage CHsmActionOnResourcePostUnmanage;
#endif /* __cplusplus */

#endif 	/* __CHsmActionOnResourcePostUnmanage_FWD_DEFINED__ */


#ifndef __CHsmActionOnResourcePreScanUnmanage_FWD_DEFINED__
#define __CHsmActionOnResourcePreScanUnmanage_FWD_DEFINED__

#ifdef __cplusplus
typedef class CHsmActionOnResourcePreScanUnmanage CHsmActionOnResourcePreScanUnmanage;
#else
typedef struct CHsmActionOnResourcePreScanUnmanage CHsmActionOnResourcePreScanUnmanage;
#endif /* __cplusplus */

#endif 	/* __CHsmActionOnResourcePreScanUnmanage_FWD_DEFINED__ */


#ifndef __CHsmActionValidate_FWD_DEFINED__
#define __CHsmActionValidate_FWD_DEFINED__

#ifdef __cplusplus
typedef class CHsmActionValidate CHsmActionValidate;
#else
typedef struct CHsmActionValidate CHsmActionValidate;
#endif /* __cplusplus */

#endif 	/* __CHsmActionValidate_FWD_DEFINED__ */


#ifndef __CHsmCritAccessTime_FWD_DEFINED__
#define __CHsmCritAccessTime_FWD_DEFINED__

#ifdef __cplusplus
typedef class CHsmCritAccessTime CHsmCritAccessTime;
#else
typedef struct CHsmCritAccessTime CHsmCritAccessTime;
#endif /* __cplusplus */

#endif 	/* __CHsmCritAccessTime_FWD_DEFINED__ */


#ifndef __CHsmCritAlways_FWD_DEFINED__
#define __CHsmCritAlways_FWD_DEFINED__

#ifdef __cplusplus
typedef class CHsmCritAlways CHsmCritAlways;
#else
typedef struct CHsmCritAlways CHsmCritAlways;
#endif /* __cplusplus */

#endif 	/* __CHsmCritAlways_FWD_DEFINED__ */


#ifndef __CHsmCritCompressed_FWD_DEFINED__
#define __CHsmCritCompressed_FWD_DEFINED__

#ifdef __cplusplus
typedef class CHsmCritCompressed CHsmCritCompressed;
#else
typedef struct CHsmCritCompressed CHsmCritCompressed;
#endif /* __cplusplus */

#endif 	/* __CHsmCritCompressed_FWD_DEFINED__ */


#ifndef __CHsmCritGroup_FWD_DEFINED__
#define __CHsmCritGroup_FWD_DEFINED__

#ifdef __cplusplus
typedef class CHsmCritGroup CHsmCritGroup;
#else
typedef struct CHsmCritGroup CHsmCritGroup;
#endif /* __cplusplus */

#endif 	/* __CHsmCritGroup_FWD_DEFINED__ */


#ifndef __CHsmCritLinked_FWD_DEFINED__
#define __CHsmCritLinked_FWD_DEFINED__

#ifdef __cplusplus
typedef class CHsmCritLinked CHsmCritLinked;
#else
typedef struct CHsmCritLinked CHsmCritLinked;
#endif /* __cplusplus */

#endif 	/* __CHsmCritLinked_FWD_DEFINED__ */


#ifndef __CHsmCritLogicalSize_FWD_DEFINED__
#define __CHsmCritLogicalSize_FWD_DEFINED__

#ifdef __cplusplus
typedef class CHsmCritLogicalSize CHsmCritLogicalSize;
#else
typedef struct CHsmCritLogicalSize CHsmCritLogicalSize;
#endif /* __cplusplus */

#endif 	/* __CHsmCritLogicalSize_FWD_DEFINED__ */


#ifndef __CHsmCritMbit_FWD_DEFINED__
#define __CHsmCritMbit_FWD_DEFINED__

#ifdef __cplusplus
typedef class CHsmCritMbit CHsmCritMbit;
#else
typedef struct CHsmCritMbit CHsmCritMbit;
#endif /* __cplusplus */

#endif 	/* __CHsmCritMbit_FWD_DEFINED__ */


#ifndef __CHsmCritManageable_FWD_DEFINED__
#define __CHsmCritManageable_FWD_DEFINED__

#ifdef __cplusplus
typedef class CHsmCritManageable CHsmCritManageable;
#else
typedef struct CHsmCritManageable CHsmCritManageable;
#endif /* __cplusplus */

#endif 	/* __CHsmCritManageable_FWD_DEFINED__ */


#ifndef __CHsmCritMigrated_FWD_DEFINED__
#define __CHsmCritMigrated_FWD_DEFINED__

#ifdef __cplusplus
typedef class CHsmCritMigrated CHsmCritMigrated;
#else
typedef struct CHsmCritMigrated CHsmCritMigrated;
#endif /* __cplusplus */

#endif 	/* __CHsmCritMigrated_FWD_DEFINED__ */


#ifndef __CHsmCritModifyTime_FWD_DEFINED__
#define __CHsmCritModifyTime_FWD_DEFINED__

#ifdef __cplusplus
typedef class CHsmCritModifyTime CHsmCritModifyTime;
#else
typedef struct CHsmCritModifyTime CHsmCritModifyTime;
#endif /* __cplusplus */

#endif 	/* __CHsmCritModifyTime_FWD_DEFINED__ */


#ifndef __CHsmCritOwner_FWD_DEFINED__
#define __CHsmCritOwner_FWD_DEFINED__

#ifdef __cplusplus
typedef class CHsmCritOwner CHsmCritOwner;
#else
typedef struct CHsmCritOwner CHsmCritOwner;
#endif /* __cplusplus */

#endif 	/* __CHsmCritOwner_FWD_DEFINED__ */


#ifndef __CHsmCritPhysicalSize_FWD_DEFINED__
#define __CHsmCritPhysicalSize_FWD_DEFINED__

#ifdef __cplusplus
typedef class CHsmCritPhysicalSize CHsmCritPhysicalSize;
#else
typedef struct CHsmCritPhysicalSize CHsmCritPhysicalSize;
#endif /* __cplusplus */

#endif 	/* __CHsmCritPhysicalSize_FWD_DEFINED__ */


#ifndef __CHsmCritPremigrated_FWD_DEFINED__
#define __CHsmCritPremigrated_FWD_DEFINED__

#ifdef __cplusplus
typedef class CHsmCritPremigrated CHsmCritPremigrated;
#else
typedef struct CHsmCritPremigrated CHsmCritPremigrated;
#endif /* __cplusplus */

#endif 	/* __CHsmCritPremigrated_FWD_DEFINED__ */


#ifndef __CHsmJob_FWD_DEFINED__
#define __CHsmJob_FWD_DEFINED__

#ifdef __cplusplus
typedef class CHsmJob CHsmJob;
#else
typedef struct CHsmJob CHsmJob;
#endif /* __cplusplus */

#endif 	/* __CHsmJob_FWD_DEFINED__ */


#ifndef __CHsmJobContext_FWD_DEFINED__
#define __CHsmJobContext_FWD_DEFINED__

#ifdef __cplusplus
typedef class CHsmJobContext CHsmJobContext;
#else
typedef struct CHsmJobContext CHsmJobContext;
#endif /* __cplusplus */

#endif 	/* __CHsmJobContext_FWD_DEFINED__ */


#ifndef __CHsmJobDef_FWD_DEFINED__
#define __CHsmJobDef_FWD_DEFINED__

#ifdef __cplusplus
typedef class CHsmJobDef CHsmJobDef;
#else
typedef struct CHsmJobDef CHsmJobDef;
#endif /* __cplusplus */

#endif 	/* __CHsmJobDef_FWD_DEFINED__ */


#ifndef __CHsmJobWorkItem_FWD_DEFINED__
#define __CHsmJobWorkItem_FWD_DEFINED__

#ifdef __cplusplus
typedef class CHsmJobWorkItem CHsmJobWorkItem;
#else
typedef struct CHsmJobWorkItem CHsmJobWorkItem;
#endif /* __cplusplus */

#endif 	/* __CHsmJobWorkItem_FWD_DEFINED__ */


#ifndef __CHsmPhase_FWD_DEFINED__
#define __CHsmPhase_FWD_DEFINED__

#ifdef __cplusplus
typedef class CHsmPhase CHsmPhase;
#else
typedef struct CHsmPhase CHsmPhase;
#endif /* __cplusplus */

#endif 	/* __CHsmPhase_FWD_DEFINED__ */


#ifndef __CHsmPolicy_FWD_DEFINED__
#define __CHsmPolicy_FWD_DEFINED__

#ifdef __cplusplus
typedef class CHsmPolicy CHsmPolicy;
#else
typedef struct CHsmPolicy CHsmPolicy;
#endif /* __cplusplus */

#endif 	/* __CHsmPolicy_FWD_DEFINED__ */


#ifndef __CHsmRule_FWD_DEFINED__
#define __CHsmRule_FWD_DEFINED__

#ifdef __cplusplus
typedef class CHsmRule CHsmRule;
#else
typedef struct CHsmRule CHsmRule;
#endif /* __cplusplus */

#endif 	/* __CHsmRule_FWD_DEFINED__ */


#ifndef __CHsmRuleStack_FWD_DEFINED__
#define __CHsmRuleStack_FWD_DEFINED__

#ifdef __cplusplus
typedef class CHsmRuleStack CHsmRuleStack;
#else
typedef struct CHsmRuleStack CHsmRuleStack;
#endif /* __cplusplus */

#endif 	/* __CHsmRuleStack_FWD_DEFINED__ */


#ifndef __CHsmScanner_FWD_DEFINED__
#define __CHsmScanner_FWD_DEFINED__

#ifdef __cplusplus
typedef class CHsmScanner CHsmScanner;
#else
typedef struct CHsmScanner CHsmScanner;
#endif /* __cplusplus */

#endif 	/* __CHsmScanner_FWD_DEFINED__ */


#ifndef __CHsmSession_FWD_DEFINED__
#define __CHsmSession_FWD_DEFINED__

#ifdef __cplusplus
typedef class CHsmSession CHsmSession;
#else
typedef struct CHsmSession CHsmSession;
#endif /* __cplusplus */

#endif 	/* __CHsmSession_FWD_DEFINED__ */


#ifndef __CHsmSessionTotals_FWD_DEFINED__
#define __CHsmSessionTotals_FWD_DEFINED__

#ifdef __cplusplus
typedef class CHsmSessionTotals CHsmSessionTotals;
#else
typedef struct CHsmSessionTotals CHsmSessionTotals;
#endif /* __cplusplus */

#endif 	/* __CHsmSessionTotals_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "jobdef.h"
#include "jobint.h"
#include "jobprv.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 


#ifndef __JOBSLib_LIBRARY_DEFINED__
#define __JOBSLib_LIBRARY_DEFINED__

/* library JOBSLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_JOBSLib;

EXTERN_C const CLSID CLSID_CHsmActionCopy;

#ifdef __cplusplus

class DECLSPEC_UUID("7B22FF2A-1AD6-11D0-81B1-00A0C91180F2")
CHsmActionCopy;
#endif

EXTERN_C const CLSID CLSID_CHsmActionDelete;

#ifdef __cplusplus

class DECLSPEC_UUID("AD402355-00FC-11D0-819C-00A0C91180F2")
CHsmActionDelete;
#endif

EXTERN_C const CLSID CLSID_CHsmActionManage;

#ifdef __cplusplus

class DECLSPEC_UUID("7B22FF29-1AD6-11D0-81B1-00A0C91180F2")
CHsmActionManage;
#endif

EXTERN_C const CLSID CLSID_CHsmActionMigrate;

#ifdef __cplusplus

class DECLSPEC_UUID("7B22FF28-1AD6-11D0-81B1-00A0C91180F2")
CHsmActionMigrate;
#endif

EXTERN_C const CLSID CLSID_CHsmActionMove;

#ifdef __cplusplus

class DECLSPEC_UUID("7B22FF2B-1AD6-11D0-81B1-00A0C91180F2")
CHsmActionMove;
#endif

EXTERN_C const CLSID CLSID_CHsmActionOnResourcePostValidate;

#ifdef __cplusplus

class DECLSPEC_UUID("D9E04211-14D7-11d1-9938-0060976A546D")
CHsmActionOnResourcePostValidate;
#endif

EXTERN_C const CLSID CLSID_CHsmActionOnResourcePreValidate;

#ifdef __cplusplus

class DECLSPEC_UUID("D9E04212-14D7-11d1-9938-0060976A546D")
CHsmActionOnResourcePreValidate;
#endif

EXTERN_C const CLSID CLSID_CHsmActionRecall;

#ifdef __cplusplus

class DECLSPEC_UUID("7B22FF22-1AD6-11D0-81B1-00A0C91180F2")
CHsmActionRecall;
#endif

EXTERN_C const CLSID CLSID_CHsmActionRecycle;

#ifdef __cplusplus

class DECLSPEC_UUID("7B22FF23-1AD6-11D0-81B1-00A0C91180F2")
CHsmActionRecycle;
#endif

EXTERN_C const CLSID CLSID_CHsmActionTruncate;

#ifdef __cplusplus

class DECLSPEC_UUID("7B22FF24-1AD6-11D0-81B1-00A0C91180F2")
CHsmActionTruncate;
#endif

EXTERN_C const CLSID CLSID_CHsmActionUnmanage;

#ifdef __cplusplus

class DECLSPEC_UUID("D3AF5DB1-1DF8-11D0-81B6-00A0C91180F2")
CHsmActionUnmanage;
#endif

EXTERN_C const CLSID CLSID_CHsmActionOnResourcePreUnmanage;

#ifdef __cplusplus

class DECLSPEC_UUID("D2C875C1-AD6E-11d1-9F2F-00A02488FCDE")
CHsmActionOnResourcePreUnmanage;
#endif

EXTERN_C const CLSID CLSID_CHsmActionOnResourcePostUnmanage;

#ifdef __cplusplus

class DECLSPEC_UUID("D9E04214-14D7-11d1-9938-0060976A546D")
CHsmActionOnResourcePostUnmanage;
#endif

EXTERN_C const CLSID CLSID_CHsmActionOnResourcePreScanUnmanage;

#ifdef __cplusplus

class DECLSPEC_UUID("80494942-A1B8-459E-95A8-0D27B17620FB")
CHsmActionOnResourcePreScanUnmanage;
#endif

EXTERN_C const CLSID CLSID_CHsmActionValidate;

#ifdef __cplusplus

class DECLSPEC_UUID("7B22FF26-1AD6-11D0-81B1-00A0C91180F2")
CHsmActionValidate;
#endif

EXTERN_C const CLSID CLSID_CHsmCritAccessTime;

#ifdef __cplusplus

class DECLSPEC_UUID("7B22FF2F-1AD6-11D0-81B1-00A0C91180F2")
CHsmCritAccessTime;
#endif

EXTERN_C const CLSID CLSID_CHsmCritAlways;

#ifdef __cplusplus

class DECLSPEC_UUID("AD40235F-00FC-11D0-819C-00A0C91180F2")
CHsmCritAlways;
#endif

EXTERN_C const CLSID CLSID_CHsmCritCompressed;

#ifdef __cplusplus

class DECLSPEC_UUID("7B22FF2E-1AD6-11D0-81B1-00A0C91180F2")
CHsmCritCompressed;
#endif

EXTERN_C const CLSID CLSID_CHsmCritGroup;

#ifdef __cplusplus

class DECLSPEC_UUID("7B22FF30-1AD6-11D0-81B1-00A0C91180F2")
CHsmCritGroup;
#endif

EXTERN_C const CLSID CLSID_CHsmCritLinked;

#ifdef __cplusplus

class DECLSPEC_UUID("CFB04621-1C9F-11D0-81B4-00A0C91180F2")
CHsmCritLinked;
#endif

EXTERN_C const CLSID CLSID_CHsmCritLogicalSize;

#ifdef __cplusplus

class DECLSPEC_UUID("7B22FF31-1AD6-11D0-81B1-00A0C91180F2")
CHsmCritLogicalSize;
#endif

EXTERN_C const CLSID CLSID_CHsmCritMbit;

#ifdef __cplusplus

class DECLSPEC_UUID("D3AF5DB2-1DF8-11D0-81B6-00A0C91180F2")
CHsmCritMbit;
#endif

EXTERN_C const CLSID CLSID_CHsmCritManageable;

#ifdef __cplusplus

class DECLSPEC_UUID("CFB04622-1C9F-11D0-81B4-00A0C91180F2")
CHsmCritManageable;
#endif

EXTERN_C const CLSID CLSID_CHsmCritMigrated;

#ifdef __cplusplus

class DECLSPEC_UUID("7B22FF2C-1AD6-11D0-81B1-00A0C91180F2")
CHsmCritMigrated;
#endif

EXTERN_C const CLSID CLSID_CHsmCritModifyTime;

#ifdef __cplusplus

class DECLSPEC_UUID("7B22FF32-1AD6-11D0-81B1-00A0C91180F2")
CHsmCritModifyTime;
#endif

EXTERN_C const CLSID CLSID_CHsmCritOwner;

#ifdef __cplusplus

class DECLSPEC_UUID("7B22FF33-1AD6-11D0-81B1-00A0C91180F2")
CHsmCritOwner;
#endif

EXTERN_C const CLSID CLSID_CHsmCritPhysicalSize;

#ifdef __cplusplus

class DECLSPEC_UUID("7B22FF34-1AD6-11D0-81B1-00A0C91180F2")
CHsmCritPhysicalSize;
#endif

EXTERN_C const CLSID CLSID_CHsmCritPremigrated;

#ifdef __cplusplus

class DECLSPEC_UUID("7B22FF2D-1AD6-11D0-81B1-00A0C91180F2")
CHsmCritPremigrated;
#endif

EXTERN_C const CLSID CLSID_CHsmJob;

#ifdef __cplusplus

class DECLSPEC_UUID("AD402346-00FC-11D0-819C-00A0C91180F2")
CHsmJob;
#endif

EXTERN_C const CLSID CLSID_CHsmJobContext;

#ifdef __cplusplus

class DECLSPEC_UUID("AD402364-00FC-11D0-819C-00A0C91180F2")
CHsmJobContext;
#endif

EXTERN_C const CLSID CLSID_CHsmJobDef;

#ifdef __cplusplus

class DECLSPEC_UUID("AD40234B-00FC-11D0-819C-00A0C91180F2")
CHsmJobDef;
#endif

EXTERN_C const CLSID CLSID_CHsmJobWorkItem;

#ifdef __cplusplus

class DECLSPEC_UUID("B8E1CD21-81D3-11d0-81E4-00A0C91180F2")
CHsmJobWorkItem;
#endif

EXTERN_C const CLSID CLSID_CHsmPhase;

#ifdef __cplusplus

class DECLSPEC_UUID("BEA60F8A-7EBA-11d0-81E4-00A0C91180F2")
CHsmPhase;
#endif

EXTERN_C const CLSID CLSID_CHsmPolicy;

#ifdef __cplusplus

class DECLSPEC_UUID("AD402350-00FC-11D0-819C-00A0C91180F2")
CHsmPolicy;
#endif

EXTERN_C const CLSID CLSID_CHsmRule;

#ifdef __cplusplus

class DECLSPEC_UUID("AD40235A-00FC-11D0-819C-00A0C91180F2")
CHsmRule;
#endif

EXTERN_C const CLSID CLSID_CHsmRuleStack;

#ifdef __cplusplus

class DECLSPEC_UUID("C2E29801-B1BA-11d0-81E9-00A0C91180F2")
CHsmRuleStack;
#endif

EXTERN_C const CLSID CLSID_CHsmScanner;

#ifdef __cplusplus

class DECLSPEC_UUID("BEA60F81-7EBA-11d0-81E4-00A0C91180F2")
CHsmScanner;
#endif

EXTERN_C const CLSID CLSID_CHsmSession;

#ifdef __cplusplus

class DECLSPEC_UUID("BEA60F80-7EBA-11d0-81E4-00A0C91180F2")
CHsmSession;
#endif

EXTERN_C const CLSID CLSID_CHsmSessionTotals;

#ifdef __cplusplus

class DECLSPEC_UUID("FF67BB34-8430-11d0-81E4-00A0C91180F2")
CHsmSessionTotals;
#endif
#endif /* __JOBSLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


