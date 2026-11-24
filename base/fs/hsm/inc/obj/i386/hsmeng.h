

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for hsmeng.idl:
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

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __hsmeng_h__
#define __hsmeng_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IHsmServer_FWD_DEFINED__
#define __IHsmServer_FWD_DEFINED__
typedef interface IHsmServer IHsmServer;
#endif 	/* __IHsmServer_FWD_DEFINED__ */


#ifndef __IHsmUpgradeRmsDb_FWD_DEFINED__
#define __IHsmUpgradeRmsDb_FWD_DEFINED__
typedef interface IHsmUpgradeRmsDb IHsmUpgradeRmsDb;
#endif 	/* __IHsmUpgradeRmsDb_FWD_DEFINED__ */


#ifndef __IHsmManagedResource_FWD_DEFINED__
#define __IHsmManagedResource_FWD_DEFINED__
typedef interface IHsmManagedResource IHsmManagedResource;
#endif 	/* __IHsmManagedResource_FWD_DEFINED__ */


#ifndef __IHsmManagedResourceCollection_FWD_DEFINED__
#define __IHsmManagedResourceCollection_FWD_DEFINED__
typedef interface IHsmManagedResourceCollection IHsmManagedResourceCollection;
#endif 	/* __IHsmManagedResourceCollection_FWD_DEFINED__ */


#ifndef __IHsmStoragePool_FWD_DEFINED__
#define __IHsmStoragePool_FWD_DEFINED__
typedef interface IHsmStoragePool IHsmStoragePool;
#endif 	/* __IHsmStoragePool_FWD_DEFINED__ */


#ifndef __IMountingMedia_FWD_DEFINED__
#define __IMountingMedia_FWD_DEFINED__
typedef interface IMountingMedia IMountingMedia;
#endif 	/* __IMountingMedia_FWD_DEFINED__ */


#ifndef __HsmServer_FWD_DEFINED__
#define __HsmServer_FWD_DEFINED__

#ifdef __cplusplus
typedef class HsmServer HsmServer;
#else
typedef struct HsmServer HsmServer;
#endif /* __cplusplus */

#endif 	/* __HsmServer_FWD_DEFINED__ */


#ifndef __CHsmUpgradeRmsDb_FWD_DEFINED__
#define __CHsmUpgradeRmsDb_FWD_DEFINED__

#ifdef __cplusplus
typedef class CHsmUpgradeRmsDb CHsmUpgradeRmsDb;
#else
typedef struct CHsmUpgradeRmsDb CHsmUpgradeRmsDb;
#endif /* __cplusplus */

#endif 	/* __CHsmUpgradeRmsDb_FWD_DEFINED__ */


#ifndef __CHsmManagedResource_FWD_DEFINED__
#define __CHsmManagedResource_FWD_DEFINED__

#ifdef __cplusplus
typedef class CHsmManagedResource CHsmManagedResource;
#else
typedef struct CHsmManagedResource CHsmManagedResource;
#endif /* __cplusplus */

#endif 	/* __CHsmManagedResource_FWD_DEFINED__ */


#ifndef __CHsmManagedResourceCollection_FWD_DEFINED__
#define __CHsmManagedResourceCollection_FWD_DEFINED__

#ifdef __cplusplus
typedef class CHsmManagedResourceCollection CHsmManagedResourceCollection;
#else
typedef struct CHsmManagedResourceCollection CHsmManagedResourceCollection;
#endif /* __cplusplus */

#endif 	/* __CHsmManagedResourceCollection_FWD_DEFINED__ */


#ifndef __CHsmStoragePool_FWD_DEFINED__
#define __CHsmStoragePool_FWD_DEFINED__

#ifdef __cplusplus
typedef class CHsmStoragePool CHsmStoragePool;
#else
typedef struct CHsmStoragePool CHsmStoragePool;
#endif /* __cplusplus */

#endif 	/* __CHsmStoragePool_FWD_DEFINED__ */


#ifndef __CMountingMedia_FWD_DEFINED__
#define __CMountingMedia_FWD_DEFINED__

#ifdef __cplusplus
typedef class CMountingMedia CMountingMedia;
#else
typedef struct CMountingMedia CMountingMedia;
#endif /* __cplusplus */

#endif 	/* __CMountingMedia_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "mstask.h"
#include "metaint.h"
#include "RmsInt.h"
#include "tskint.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

/* interface __MIDL_itf_hsmeng_0000 */
/* [local] */ 






typedef /* [v1_enum] */ 
enum _HSM_RSLTS_LVL
    {	HSM_FILE_LVL_RSLTS	= 0,
	HSM_RES_LVL_RSLTS	= HSM_FILE_LVL_RSLTS + 1
    } 	HSM_RSLTS_LVL;

typedef /* [v1_enum] */ 
enum _HSM_SYS_STS
    {	HSM_SYS_STS_STARTING	= 0,
	HSM_SYS_STS_ONLINE	= HSM_SYS_STS_STARTING + 1,
	HSM_SYS_STS_OFF_PEND	= HSM_SYS_STS_ONLINE + 1,
	HSM_SYS_STS_OFFLINE	= HSM_SYS_STS_OFF_PEND + 1,
	HSM_SYS_STS_MAINT	= HSM_SYS_STS_OFFLINE + 1,
	HSM_SYS_STS_DISABLED	= HSM_SYS_STS_MAINT + 1,
	HSM_SYS_STS_SHUT_PEND	= HSM_SYS_STS_DISABLED + 1,
	HSM_SYS_STS_SHUTDOWN	= HSM_SYS_STS_SHUT_PEND + 1
    } 	HSM_SYS_STS;

typedef /* [v1_enum] */ 
enum _HSM_FULL_ACT
    {	HSM_FULL_NO_MIGRATES	= 0,
	HSM_FULL_OVERFLOW	= HSM_FULL_NO_MIGRATES + 1
    } 	HSM_FULL_ACT;

typedef GUID HSMID;

#if 0
typedef GUID *REFGUID;

#endif // 0
#if defined(__cplusplus)
#define REFHSMID             const HSMID &
#else // !__cplusplus
#define REFHSMID             const HSMID * const
#endif // !__cplusplus


extern RPC_IF_HANDLE __MIDL_itf_hsmeng_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_hsmeng_0000_v0_0_s_ifspec;

#ifndef __IHsmServer_INTERFACE_DEFINED__
#define __IHsmServer_INTERFACE_DEFINED__

/* interface IHsmServer */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IHsmServer;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E372F85B-D72B-4A7D-B0F6-2BCF8FED88B9")
    IHsmServer : public IHsmSystemState
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Init( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetID( 
            /* [out] */ GUID *phid) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDbPath( 
            /* [string][out][in] */ OLECHAR **pPath,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetIDbPath( 
            /* [string][out][in] */ OLECHAR **pPath,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetDbPathAndName( 
            /* [string][out][in] */ OLECHAR **pPath,
            /* [in] */ ULONG bufferSize) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetName( 
            /* [out][string] */ OLECHAR **ppName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetHsmExtVerHi( 
            /* [out] */ SHORT *pExtVerHi) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetHsmExtVerLo( 
            /* [out] */ SHORT *pExtVerLo) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetHsmExtRev( 
            /* [out] */ SHORT *pExtRev) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetAutosave( 
            /* [out] */ ULONG *pMilliseconds) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetAutosave( 
            /* [in] */ ULONG milliseconds) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCopyFilesLimit( 
            /* [out] */ ULONG *pLimit) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCopyFilesUserLimit( 
            /* [out] */ ULONG *pLimit) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetCopyFilesUserLimit( 
            /* [in] */ ULONG limit) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetManagedResources( 
            /* [out] */ IWsbIndexedCollection **ppCollection) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FindHsmStoragePoolById( 
            /* [in] */ GUID StoragePoolId,
            /* [out] */ IHsmStoragePool **ppStoragePool) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FindHsmStoragePoolByMediaSetId( 
            /* [in] */ GUID RmsMediaSetId,
            /* [out] */ IHsmStoragePool **ppStoragePool) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FindMediaIdByDescription( 
            /* [string][in] */ OLECHAR *description,
            /* [out] */ GUID *pMediaId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FindStoragePoolByName( 
            /* [string][in] */ OLECHAR *name,
            /* [out] */ IHsmStoragePool **ppStoragePool) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetStoragePools( 
            /* [out] */ IWsbIndexedCollection **ppCollection) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetOnlineInformation( 
            /* [out] */ IWsbIndexedCollection **ppCollection) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMessages( 
            /* [out] */ IWsbIndexedCollection **ppCollection) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetUsrToNotify( 
            /* [out] */ IWsbIndexedCollection **ppCollection) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE FindJobByName( 
            /* [string][in] */ OLECHAR *name,
            /* [out] */ IHsmJob **ppJob) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetJobs( 
            /* [out] */ IWsbIndexedCollection **ppCollection) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetJobDefs( 
            /* [out] */ IWsbIndexedCollection **ppCollection) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetPolicies( 
            /* [out] */ IWsbIndexedCollection **ppCollection) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetActions( 
            /* [out] */ IWsbIndexedCollection **ppCollection) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetCriteria( 
            /* [out] */ IWsbIndexedCollection **ppCollection) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMediaRecs( 
            /* [out] */ IWsbIndexedCollection **ppCollection) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMountingMedias( 
            /* [out] */ IWsbIndexedCollection **ppCollection) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE LockMountingMedias( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UnlockMountingMedias( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNextMedia( 
            /* [out] */ LONG *pNextMedia) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSegmentDb( 
            /* [out] */ IWsbDb **ppDb) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE BackupSegmentDb( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetHsmFsaTskMgr( 
            /* [out] */ IHsmFsaTskMgr **ppHsmTskMgr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SaveMetaData( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SavePersistData( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CloseOutDb( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CancelAllJobs( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE AreJobsEnabled( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE EnableAllJobs( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE DisableAllJobs( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RestartSuspendedJobs( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateTask( 
            /* [string][in] */ const OLECHAR *jobName,
            /* [string][in] */ const OLECHAR *jobParameters,
            /* [string][in] */ const OLECHAR *jobComments,
            /* [in] */ const TASK_TRIGGER_TYPE jobTriggerType,
            /* [in] */ const WORD jobStartHour,
            /* [in] */ const WORD jobStartMinute,
            /* [in] */ const BOOL scheduledJob) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CreateTaskEx( 
            /* [string][in] */ const OLECHAR *jobName,
            /* [string][in] */ const OLECHAR *jobParameters,
            /* [string][in] */ const OLECHAR *jobComments,
            /* [in] */ const TASK_TRIGGER_TYPE jobTriggerType,
            /* [in] */ const SYSTEMTIME runTime,
            /* [in] */ const DWORD runOccurrence,
            /* [in] */ const BOOL scheduledJob) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CancelCopyMedia( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MarkMediaForRecreation( 
            /* [in] */ REFGUID masterMediaId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE RecreateMaster( 
            /* [in] */ REFGUID masterMediaId,
            /* [in] */ USHORT copySet) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SynchronizeMedia( 
            /* [in] */ GUID poolId,
            /* [in] */ USHORT copySet) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetHsmMediaMgr( 
            /* [out] */ IRmsServer **ppHsmMediaMgr) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ResetSegmentValidMark( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE ResetMediaValidBytes( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetSegmentPosition( 
            /* [in] */ REFGUID bagId,
            /* [in] */ LONGLONG fileStart,
            /* [in] */ LONGLONG fileSize,
            /* [out] */ GUID *pPosMedia,
            /* [out] */ LONGLONG *pPosOfffset) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE UpdateMediaSizeLimit( 
            /* [out] */ DWORD *pNewLimit) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHsmServerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHsmServer * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHsmServer * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHsmServer * This);
        
        HRESULT ( STDMETHODCALLTYPE *ChangeSysState )( 
            IHsmServer * This,
            /* [out][in] */ HSM_SYSTEM_STATE *pSysState);
        
        HRESULT ( STDMETHODCALLTYPE *Init )( 
            IHsmServer * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetID )( 
            IHsmServer * This,
            /* [out] */ GUID *phid);
        
        HRESULT ( STDMETHODCALLTYPE *GetDbPath )( 
            IHsmServer * This,
            /* [string][out][in] */ OLECHAR **pPath,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDbPath )( 
            IHsmServer * This,
            /* [string][out][in] */ OLECHAR **pPath,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetDbPathAndName )( 
            IHsmServer * This,
            /* [string][out][in] */ OLECHAR **pPath,
            /* [in] */ ULONG bufferSize);
        
        HRESULT ( STDMETHODCALLTYPE *GetName )( 
            IHsmServer * This,
            /* [out][string] */ OLECHAR **ppName);
        
        HRESULT ( STDMETHODCALLTYPE *GetHsmExtVerHi )( 
            IHsmServer * This,
            /* [out] */ SHORT *pExtVerHi);
        
        HRESULT ( STDMETHODCALLTYPE *GetHsmExtVerLo )( 
            IHsmServer * This,
            /* [out] */ SHORT *pExtVerLo);
        
        HRESULT ( STDMETHODCALLTYPE *GetHsmExtRev )( 
            IHsmServer * This,
            /* [out] */ SHORT *pExtRev);
        
        HRESULT ( STDMETHODCALLTYPE *GetAutosave )( 
            IHsmServer * This,
            /* [out] */ ULONG *pMilliseconds);
        
        HRESULT ( STDMETHODCALLTYPE *SetAutosave )( 
            IHsmServer * This,
            /* [in] */ ULONG milliseconds);
        
        HRESULT ( STDMETHODCALLTYPE *GetCopyFilesLimit )( 
            IHsmServer * This,
            /* [out] */ ULONG *pLimit);
        
        HRESULT ( STDMETHODCALLTYPE *GetCopyFilesUserLimit )( 
            IHsmServer * This,
            /* [out] */ ULONG *pLimit);
        
        HRESULT ( STDMETHODCALLTYPE *SetCopyFilesUserLimit )( 
            IHsmServer * This,
            /* [in] */ ULONG limit);
        
        HRESULT ( STDMETHODCALLTYPE *GetManagedResources )( 
            IHsmServer * This,
            /* [out] */ IWsbIndexedCollection **ppCollection);
        
        HRESULT ( STDMETHODCALLTYPE *FindHsmStoragePoolById )( 
            IHsmServer * This,
            /* [in] */ GUID StoragePoolId,
            /* [out] */ IHsmStoragePool **ppStoragePool);
        
        HRESULT ( STDMETHODCALLTYPE *FindHsmStoragePoolByMediaSetId )( 
            IHsmServer * This,
            /* [in] */ GUID RmsMediaSetId,
            /* [out] */ IHsmStoragePool **ppStoragePool);
        
        HRESULT ( STDMETHODCALLTYPE *FindMediaIdByDescription )( 
            IHsmServer * This,
            /* [string][in] */ OLECHAR *description,
            /* [out] */ GUID *pMediaId);
        
        HRESULT ( STDMETHODCALLTYPE *FindStoragePoolByName )( 
            IHsmServer * This,
            /* [string][in] */ OLECHAR *name,
            /* [out] */ IHsmStoragePool **ppStoragePool);
        
        HRESULT ( STDMETHODCALLTYPE *GetStoragePools )( 
            IHsmServer * This,
            /* [out] */ IWsbIndexedCollection **ppCollection);
        
        HRESULT ( STDMETHODCALLTYPE *GetOnlineInformation )( 
            IHsmServer * This,
            /* [out] */ IWsbIndexedCollection **ppCollection);
        
        HRESULT ( STDMETHODCALLTYPE *GetMessages )( 
            IHsmServer * This,
            /* [out] */ IWsbIndexedCollection **ppCollection);
        
        HRESULT ( STDMETHODCALLTYPE *GetUsrToNotify )( 
            IHsmServer * This,
            /* [out] */ IWsbIndexedCollection **ppCollection);
        
        HRESULT ( STDMETHODCALLTYPE *FindJobByName )( 
            IHsmServer * This,
            /* [string][in] */ OLECHAR *name,
            /* [out] */ IHsmJob **ppJob);
        
        HRESULT ( STDMETHODCALLTYPE *GetJobs )( 
            IHsmServer * This,
            /* [out] */ IWsbIndexedCollection **ppCollection);
        
        HRESULT ( STDMETHODCALLTYPE *GetJobDefs )( 
            IHsmServer * This,
            /* [out] */ IWsbIndexedCollection **ppCollection);
        
        HRESULT ( STDMETHODCALLTYPE *GetPolicies )( 
            IHsmServer * This,
            /* [out] */ IWsbIndexedCollection **ppCollection);
        
        HRESULT ( STDMETHODCALLTYPE *GetActions )( 
            IHsmServer * This,
            /* [out] */ IWsbIndexedCollection **ppCollection);
        
        HRESULT ( STDMETHODCALLTYPE *GetCriteria )( 
            IHsmServer * This,
            /* [out] */ IWsbIndexedCollection **ppCollection);
        
        HRESULT ( STDMETHODCALLTYPE *GetMediaRecs )( 
            IHsmServer * This,
            /* [out] */ IWsbIndexedCollection **ppCollection);
        
        HRESULT ( STDMETHODCALLTYPE *GetMountingMedias )( 
            IHsmServer * This,
            /* [out] */ IWsbIndexedCollection **ppCollection);
        
        HRESULT ( STDMETHODCALLTYPE *LockMountingMedias )( 
            IHsmServer * This);
        
        HRESULT ( STDMETHODCALLTYPE *UnlockMountingMedias )( 
            IHsmServer * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetNextMedia )( 
            IHsmServer * This,
            /* [out] */ LONG *pNextMedia);
        
        HRESULT ( STDMETHODCALLTYPE *GetSegmentDb )( 
            IHsmServer * This,
            /* [out] */ IWsbDb **ppDb);
        
        HRESULT ( STDMETHODCALLTYPE *BackupSegmentDb )( 
            IHsmServer * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetHsmFsaTskMgr )( 
            IHsmServer * This,
            /* [out] */ IHsmFsaTskMgr **ppHsmTskMgr);
        
        HRESULT ( STDMETHODCALLTYPE *SaveMetaData )( 
            IHsmServer * This);
        
        HRESULT ( STDMETHODCALLTYPE *SavePersistData )( 
            IHsmServer * This);
        
        HRESULT ( STDMETHODCALLTYPE *CloseOutDb )( 
            IHsmServer * This);
        
        HRESULT ( STDMETHODCALLTYPE *CancelAllJobs )( 
            IHsmServer * This);
        
        HRESULT ( STDMETHODCALLTYPE *AreJobsEnabled )( 
            IHsmServer * This);
        
        HRESULT ( STDMETHODCALLTYPE *EnableAllJobs )( 
            IHsmServer * This);
        
        HRESULT ( STDMETHODCALLTYPE *DisableAllJobs )( 
            IHsmServer * This);
        
        HRESULT ( STDMETHODCALLTYPE *RestartSuspendedJobs )( 
            IHsmServer * This);
        
        HRESULT ( STDMETHODCALLTYPE *CreateTask )( 
            IHsmServer * This,
            /* [string][in] */ const OLECHAR *jobName,
            /* [string][in] */ const OLECHAR *jobParameters,
            /* [string][in] */ const OLECHAR *jobComments,
            /* [in] */ const TASK_TRIGGER_TYPE jobTriggerType,
            /* [in] */ const WORD jobStartHour,
            /* [in] */ const WORD jobStartMinute,
            /* [in] */ const BOOL scheduledJob);
        
        HRESULT ( STDMETHODCALLTYPE *CreateTaskEx )( 
            IHsmServer * This,
            /* [string][in] */ const OLECHAR *jobName,
            /* [string][in] */ const OLECHAR *jobParameters,
            /* [string][in] */ const OLECHAR *jobComments,
            /* [in] */ const TASK_TRIGGER_TYPE jobTriggerType,
            /* [in] */ const SYSTEMTIME runTime,
            /* [in] */ const DWORD runOccurrence,
            /* [in] */ const BOOL scheduledJob);
        
        HRESULT ( STDMETHODCALLTYPE *CancelCopyMedia )( 
            IHsmServer * This);
        
        HRESULT ( STDMETHODCALLTYPE *MarkMediaForRecreation )( 
            IHsmServer * This,
            /* [in] */ REFGUID masterMediaId);
        
        HRESULT ( STDMETHODCALLTYPE *RecreateMaster )( 
            IHsmServer * This,
            /* [in] */ REFGUID masterMediaId,
            /* [in] */ USHORT copySet);
        
        HRESULT ( STDMETHODCALLTYPE *SynchronizeMedia )( 
            IHsmServer * This,
            /* [in] */ GUID poolId,
            /* [in] */ USHORT copySet);
        
        HRESULT ( STDMETHODCALLTYPE *GetHsmMediaMgr )( 
            IHsmServer * This,
            /* [out] */ IRmsServer **ppHsmMediaMgr);
        
        HRESULT ( STDMETHODCALLTYPE *ResetSegmentValidMark )( 
            IHsmServer * This);
        
        HRESULT ( STDMETHODCALLTYPE *ResetMediaValidBytes )( 
            IHsmServer * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetSegmentPosition )( 
            IHsmServer * This,
            /* [in] */ REFGUID bagId,
            /* [in] */ LONGLONG fileStart,
            /* [in] */ LONGLONG fileSize,
            /* [out] */ GUID *pPosMedia,
            /* [out] */ LONGLONG *pPosOfffset);
        
        HRESULT ( STDMETHODCALLTYPE *UpdateMediaSizeLimit )( 
            IHsmServer * This,
            /* [out] */ DWORD *pNewLimit);
        
        END_INTERFACE
    } IHsmServerVtbl;

    interface IHsmServer
    {
        CONST_VTBL struct IHsmServerVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHsmServer_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHsmServer_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHsmServer_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHsmServer_ChangeSysState(This,pSysState)	\
    (This)->lpVtbl -> ChangeSysState(This,pSysState)


#define IHsmServer_Init(This)	\
    (This)->lpVtbl -> Init(This)

#define IHsmServer_GetID(This,phid)	\
    (This)->lpVtbl -> GetID(This,phid)

#define IHsmServer_GetDbPath(This,pPath,bufferSize)	\
    (This)->lpVtbl -> GetDbPath(This,pPath,bufferSize)

#define IHsmServer_GetIDbPath(This,pPath,bufferSize)	\
    (This)->lpVtbl -> GetIDbPath(This,pPath,bufferSize)

#define IHsmServer_GetDbPathAndName(This,pPath,bufferSize)	\
    (This)->lpVtbl -> GetDbPathAndName(This,pPath,bufferSize)

#define IHsmServer_GetName(This,ppName)	\
    (This)->lpVtbl -> GetName(This,ppName)

#define IHsmServer_GetHsmExtVerHi(This,pExtVerHi)	\
    (This)->lpVtbl -> GetHsmExtVerHi(This,pExtVerHi)

#define IHsmServer_GetHsmExtVerLo(This,pExtVerLo)	\
    (This)->lpVtbl -> GetHsmExtVerLo(This,pExtVerLo)

#define IHsmServer_GetHsmExtRev(This,pExtRev)	\
    (This)->lpVtbl -> GetHsmExtRev(This,pExtRev)

#define IHsmServer_GetAutosave(This,pMilliseconds)	\
    (This)->lpVtbl -> GetAutosave(This,pMilliseconds)

#define IHsmServer_SetAutosave(This,milliseconds)	\
    (This)->lpVtbl -> SetAutosave(This,milliseconds)

#define IHsmServer_GetCopyFilesLimit(This,pLimit)	\
    (This)->lpVtbl -> GetCopyFilesLimit(This,pLimit)

#define IHsmServer_GetCopyFilesUserLimit(This,pLimit)	\
    (This)->lpVtbl -> GetCopyFilesUserLimit(This,pLimit)

#define IHsmServer_SetCopyFilesUserLimit(This,limit)	\
    (This)->lpVtbl -> SetCopyFilesUserLimit(This,limit)

#define IHsmServer_GetManagedResources(This,ppCollection)	\
    (This)->lpVtbl -> GetManagedResources(This,ppCollection)

#define IHsmServer_FindHsmStoragePoolById(This,StoragePoolId,ppStoragePool)	\
    (This)->lpVtbl -> FindHsmStoragePoolById(This,StoragePoolId,ppStoragePool)

#define IHsmServer_FindHsmStoragePoolByMediaSetId(This,RmsMediaSetId,ppStoragePool)	\
    (This)->lpVtbl -> FindHsmStoragePoolByMediaSetId(This,RmsMediaSetId,ppStoragePool)

#define IHsmServer_FindMediaIdByDescription(This,description,pMediaId)	\
    (This)->lpVtbl -> FindMediaIdByDescription(This,description,pMediaId)

#define IHsmServer_FindStoragePoolByName(This,name,ppStoragePool)	\
    (This)->lpVtbl -> FindStoragePoolByName(This,name,ppStoragePool)

#define IHsmServer_GetStoragePools(This,ppCollection)	\
    (This)->lpVtbl -> GetStoragePools(This,ppCollection)

#define IHsmServer_GetOnlineInformation(This,ppCollection)	\
    (This)->lpVtbl -> GetOnlineInformation(This,ppCollection)

#define IHsmServer_GetMessages(This,ppCollection)	\
    (This)->lpVtbl -> GetMessages(This,ppCollection)

#define IHsmServer_GetUsrToNotify(This,ppCollection)	\
    (This)->lpVtbl -> GetUsrToNotify(This,ppCollection)

#define IHsmServer_FindJobByName(This,name,ppJob)	\
    (This)->lpVtbl -> FindJobByName(This,name,ppJob)

#define IHsmServer_GetJobs(This,ppCollection)	\
    (This)->lpVtbl -> GetJobs(This,ppCollection)

#define IHsmServer_GetJobDefs(This,ppCollection)	\
    (This)->lpVtbl -> GetJobDefs(This,ppCollection)

#define IHsmServer_GetPolicies(This,ppCollection)	\
    (This)->lpVtbl -> GetPolicies(This,ppCollection)

#define IHsmServer_GetActions(This,ppCollection)	\
    (This)->lpVtbl -> GetActions(This,ppCollection)

#define IHsmServer_GetCriteria(This,ppCollection)	\
    (This)->lpVtbl -> GetCriteria(This,ppCollection)

#define IHsmServer_GetMediaRecs(This,ppCollection)	\
    (This)->lpVtbl -> GetMediaRecs(This,ppCollection)

#define IHsmServer_GetMountingMedias(This,ppCollection)	\
    (This)->lpVtbl -> GetMountingMedias(This,ppCollection)

#define IHsmServer_LockMountingMedias(This)	\
    (This)->lpVtbl -> LockMountingMedias(This)

#define IHsmServer_UnlockMountingMedias(This)	\
    (This)->lpVtbl -> UnlockMountingMedias(This)

#define IHsmServer_GetNextMedia(This,pNextMedia)	\
    (This)->lpVtbl -> GetNextMedia(This,pNextMedia)

#define IHsmServer_GetSegmentDb(This,ppDb)	\
    (This)->lpVtbl -> GetSegmentDb(This,ppDb)

#define IHsmServer_BackupSegmentDb(This)	\
    (This)->lpVtbl -> BackupSegmentDb(This)

#define IHsmServer_GetHsmFsaTskMgr(This,ppHsmTskMgr)	\
    (This)->lpVtbl -> GetHsmFsaTskMgr(This,ppHsmTskMgr)

#define IHsmServer_SaveMetaData(This)	\
    (This)->lpVtbl -> SaveMetaData(This)

#define IHsmServer_SavePersistData(This)	\
    (This)->lpVtbl -> SavePersistData(This)

#define IHsmServer_CloseOutDb(This)	\
    (This)->lpVtbl -> CloseOutDb(This)

#define IHsmServer_CancelAllJobs(This)	\
    (This)->lpVtbl -> CancelAllJobs(This)

#define IHsmServer_AreJobsEnabled(This)	\
    (This)->lpVtbl -> AreJobsEnabled(This)

#define IHsmServer_EnableAllJobs(This)	\
    (This)->lpVtbl -> EnableAllJobs(This)

#define IHsmServer_DisableAllJobs(This)	\
    (This)->lpVtbl -> DisableAllJobs(This)

#define IHsmServer_RestartSuspendedJobs(This)	\
    (This)->lpVtbl -> RestartSuspendedJobs(This)

#define IHsmServer_CreateTask(This,jobName,jobParameters,jobComments,jobTriggerType,jobStartHour,jobStartMinute,scheduledJob)	\
    (This)->lpVtbl -> CreateTask(This,jobName,jobParameters,jobComments,jobTriggerType,jobStartHour,jobStartMinute,scheduledJob)

#define IHsmServer_CreateTaskEx(This,jobName,jobParameters,jobComments,jobTriggerType,runTime,runOccurrence,scheduledJob)	\
    (This)->lpVtbl -> CreateTaskEx(This,jobName,jobParameters,jobComments,jobTriggerType,runTime,runOccurrence,scheduledJob)

#define IHsmServer_CancelCopyMedia(This)	\
    (This)->lpVtbl -> CancelCopyMedia(This)

#define IHsmServer_MarkMediaForRecreation(This,masterMediaId)	\
    (This)->lpVtbl -> MarkMediaForRecreation(This,masterMediaId)

#define IHsmServer_RecreateMaster(This,masterMediaId,copySet)	\
    (This)->lpVtbl -> RecreateMaster(This,masterMediaId,copySet)

#define IHsmServer_SynchronizeMedia(This,poolId,copySet)	\
    (This)->lpVtbl -> SynchronizeMedia(This,poolId,copySet)

#define IHsmServer_GetHsmMediaMgr(This,ppHsmMediaMgr)	\
    (This)->lpVtbl -> GetHsmMediaMgr(This,ppHsmMediaMgr)

#define IHsmServer_ResetSegmentValidMark(This)	\
    (This)->lpVtbl -> ResetSegmentValidMark(This)

#define IHsmServer_ResetMediaValidBytes(This)	\
    (This)->lpVtbl -> ResetMediaValidBytes(This)

#define IHsmServer_GetSegmentPosition(This,bagId,fileStart,fileSize,pPosMedia,pPosOfffset)	\
    (This)->lpVtbl -> GetSegmentPosition(This,bagId,fileStart,fileSize,pPosMedia,pPosOfffset)

#define IHsmServer_UpdateMediaSizeLimit(This,pNewLimit)	\
    (This)->lpVtbl -> UpdateMediaSizeLimit(This,pNewLimit)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IHsmServer_Init_Proxy( 
    IHsmServer * This);


void __RPC_STUB IHsmServer_Init_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmServer_GetID_Proxy( 
    IHsmServer * This,
    /* [out] */ GUID *phid);


void __RPC_STUB IHsmServer_GetID_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmServer_GetDbPath_Proxy( 
    IHsmServer * This,
    /* [string][out][in] */ OLECHAR **pPath,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IHsmServer_GetDbPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmServer_GetIDbPath_Proxy( 
    IHsmServer * This,
    /* [string][out][in] */ OLECHAR **pPath,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IHsmServer_GetIDbPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmServer_GetDbPathAndName_Proxy( 
    IHsmServer * This,
    /* [string][out][in] */ OLECHAR **pPath,
    /* [in] */ ULONG bufferSize);


void __RPC_STUB IHsmServer_GetDbPathAndName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmServer_GetName_Proxy( 
    IHsmServer * This,
    /* [out][string] */ OLECHAR **ppName);


void __RPC_STUB IHsmServer_GetName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmServer_GetHsmExtVerHi_Proxy( 
    IHsmServer * This,
    /* [out] */ SHORT *pExtVerHi);


void __RPC_STUB IHsmServer_GetHsmExtVerHi_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmServer_GetHsmExtVerLo_Proxy( 
    IHsmServer * This,
    /* [out] */ SHORT *pExtVerLo);


void __RPC_STUB IHsmServer_GetHsmExtVerLo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmServer_GetHsmExtRev_Proxy( 
    IHsmServer * This,
    /* [out] */ SHORT *pExtRev);


void __RPC_STUB IHsmServer_GetHsmExtRev_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmServer_GetAutosave_Proxy( 
    IHsmServer * This,
    /* [out] */ ULONG *pMilliseconds);


void __RPC_STUB IHsmServer_GetAutosave_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmServer_SetAutosave_Proxy( 
    IHsmServer * This,
    /* [in] */ ULONG milliseconds);


void __RPC_STUB IHsmServer_SetAutosave_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmServer_GetCopyFilesLimit_Proxy( 
    IHsmServer * This,
    /* [out] */ ULONG *pLimit);


void __RPC_STUB IHsmServer_GetCopyFilesLimit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmServer_GetCopyFilesUserLimit_Proxy( 
    IHsmServer * This,
    /* [out] */ ULONG *pLimit);


void __RPC_STUB IHsmServer_GetCopyFilesUserLimit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmServer_SetCopyFilesUserLimit_Proxy( 
    IHsmServer * This,
    /* [in] */ ULONG limit);


void __RPC_STUB IHsmServer_SetCopyFilesUserLimit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmServer_GetManagedResources_Proxy( 
    IHsmServer * This,
    /* [out] */ IWsbIndexedCollection **ppCollection);


void __RPC_STUB IHsmServer_GetManagedResources_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmServer_FindHsmStoragePoolById_Proxy( 
    IHsmServer * This,
    /* [in] */ GUID StoragePoolId,
    /* [out] */ IHsmStoragePool **ppStoragePool);


void __RPC_STUB IHsmServer_FindHsmStoragePoolById_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmServer_FindHsmStoragePoolByMediaSetId_Proxy( 
    IHsmServer * This,
    /* [in] */ GUID RmsMediaSetId,
    /* [out] */ IHsmStoragePool **ppStoragePool);


void __RPC_STUB IHsmServer_FindHsmStoragePoolByMediaSetId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmServer_FindMediaIdByDescription_Proxy( 
    IHsmServer * This,
    /* [string][in] */ OLECHAR *description,
    /* [out] */ GUID *pMediaId);


void __RPC_STUB IHsmServer_FindMediaIdByDescription_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmServer_FindStoragePoolByName_Proxy( 
    IHsmServer * This,
    /* [string][in] */ OLECHAR *name,
    /* [out] */ IHsmStoragePool **ppStoragePool);


void __RPC_STUB IHsmServer_FindStoragePoolByName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmServer_GetStoragePools_Proxy( 
    IHsmServer * This,
    /* [out] */ IWsbIndexedCollection **ppCollection);


void __RPC_STUB IHsmServer_GetStoragePools_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmServer_GetOnlineInformation_Proxy( 
    IHsmServer * This,
    /* [out] */ IWsbIndexedCollection **ppCollection);


void __RPC_STUB IHsmServer_GetOnlineInformation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmServer_GetMessages_Proxy( 
    IHsmServer * This,
    /* [out] */ IWsbIndexedCollection **ppCollection);


void __RPC_STUB IHsmServer_GetMessages_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmServer_GetUsrToNotify_Proxy( 
    IHsmServer * This,
    /* [out] */ IWsbIndexedCollection **ppCollection);


void __RPC_STUB IHsmServer_GetUsrToNotify_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmServer_FindJobByName_Proxy( 
    IHsmServer * This,
    /* [string][in] */ OLECHAR *name,
    /* [out] */ IHsmJob **ppJob);


void __RPC_STUB IHsmServer_FindJobByName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmServer_GetJobs_Proxy( 
    IHsmServer * This,
    /* [out] */ IWsbIndexedCollection **ppCollection);


void __RPC_STUB IHsmServer_GetJobs_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmServer_GetJobDefs_Proxy( 
    IHsmServer * This,
    /* [out] */ IWsbIndexedCollection **ppCollection);


void __RPC_STUB IHsmServer_GetJobDefs_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmServer_GetPolicies_Proxy( 
    IHsmServer * This,
    /* [out] */ IWsbIndexedCollection **ppCollection);


void __RPC_STUB IHsmServer_GetPolicies_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmServer_GetActions_Proxy( 
    IHsmServer * This,
    /* [out] */ IWsbIndexedCollection **ppCollection);


void __RPC_STUB IHsmServer_GetActions_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmServer_GetCriteria_Proxy( 
    IHsmServer * This,
    /* [out] */ IWsbIndexedCollection **ppCollection);


void __RPC_STUB IHsmServer_GetCriteria_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmServer_GetMediaRecs_Proxy( 
    IHsmServer * This,
    /* [out] */ IWsbIndexedCollection **ppCollection);


void __RPC_STUB IHsmServer_GetMediaRecs_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmServer_GetMountingMedias_Proxy( 
    IHsmServer * This,
    /* [out] */ IWsbIndexedCollection **ppCollection);


void __RPC_STUB IHsmServer_GetMountingMedias_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmServer_LockMountingMedias_Proxy( 
    IHsmServer * This);


void __RPC_STUB IHsmServer_LockMountingMedias_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmServer_UnlockMountingMedias_Proxy( 
    IHsmServer * This);


void __RPC_STUB IHsmServer_UnlockMountingMedias_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmServer_GetNextMedia_Proxy( 
    IHsmServer * This,
    /* [out] */ LONG *pNextMedia);


void __RPC_STUB IHsmServer_GetNextMedia_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmServer_GetSegmentDb_Proxy( 
    IHsmServer * This,
    /* [out] */ IWsbDb **ppDb);


void __RPC_STUB IHsmServer_GetSegmentDb_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmServer_BackupSegmentDb_Proxy( 
    IHsmServer * This);


void __RPC_STUB IHsmServer_BackupSegmentDb_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmServer_GetHsmFsaTskMgr_Proxy( 
    IHsmServer * This,
    /* [out] */ IHsmFsaTskMgr **ppHsmTskMgr);


void __RPC_STUB IHsmServer_GetHsmFsaTskMgr_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmServer_SaveMetaData_Proxy( 
    IHsmServer * This);


void __RPC_STUB IHsmServer_SaveMetaData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmServer_SavePersistData_Proxy( 
    IHsmServer * This);


void __RPC_STUB IHsmServer_SavePersistData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmServer_CloseOutDb_Proxy( 
    IHsmServer * This);


void __RPC_STUB IHsmServer_CloseOutDb_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmServer_CancelAllJobs_Proxy( 
    IHsmServer * This);


void __RPC_STUB IHsmServer_CancelAllJobs_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmServer_AreJobsEnabled_Proxy( 
    IHsmServer * This);


void __RPC_STUB IHsmServer_AreJobsEnabled_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmServer_EnableAllJobs_Proxy( 
    IHsmServer * This);


void __RPC_STUB IHsmServer_EnableAllJobs_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmServer_DisableAllJobs_Proxy( 
    IHsmServer * This);


void __RPC_STUB IHsmServer_DisableAllJobs_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmServer_RestartSuspendedJobs_Proxy( 
    IHsmServer * This);


void __RPC_STUB IHsmServer_RestartSuspendedJobs_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmServer_CreateTask_Proxy( 
    IHsmServer * This,
    /* [string][in] */ const OLECHAR *jobName,
    /* [string][in] */ const OLECHAR *jobParameters,
    /* [string][in] */ const OLECHAR *jobComments,
    /* [in] */ const TASK_TRIGGER_TYPE jobTriggerType,
    /* [in] */ const WORD jobStartHour,
    /* [in] */ const WORD jobStartMinute,
    /* [in] */ const BOOL scheduledJob);


void __RPC_STUB IHsmServer_CreateTask_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmServer_CreateTaskEx_Proxy( 
    IHsmServer * This,
    /* [string][in] */ const OLECHAR *jobName,
    /* [string][in] */ const OLECHAR *jobParameters,
    /* [string][in] */ const OLECHAR *jobComments,
    /* [in] */ const TASK_TRIGGER_TYPE jobTriggerType,
    /* [in] */ const SYSTEMTIME runTime,
    /* [in] */ const DWORD runOccurrence,
    /* [in] */ const BOOL scheduledJob);


void __RPC_STUB IHsmServer_CreateTaskEx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmServer_CancelCopyMedia_Proxy( 
    IHsmServer * This);


void __RPC_STUB IHsmServer_CancelCopyMedia_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmServer_MarkMediaForRecreation_Proxy( 
    IHsmServer * This,
    /* [in] */ REFGUID masterMediaId);


void __RPC_STUB IHsmServer_MarkMediaForRecreation_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmServer_RecreateMaster_Proxy( 
    IHsmServer * This,
    /* [in] */ REFGUID masterMediaId,
    /* [in] */ USHORT copySet);


void __RPC_STUB IHsmServer_RecreateMaster_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmServer_SynchronizeMedia_Proxy( 
    IHsmServer * This,
    /* [in] */ GUID poolId,
    /* [in] */ USHORT copySet);


void __RPC_STUB IHsmServer_SynchronizeMedia_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmServer_GetHsmMediaMgr_Proxy( 
    IHsmServer * This,
    /* [out] */ IRmsServer **ppHsmMediaMgr);


void __RPC_STUB IHsmServer_GetHsmMediaMgr_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmServer_ResetSegmentValidMark_Proxy( 
    IHsmServer * This);


void __RPC_STUB IHsmServer_ResetSegmentValidMark_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmServer_ResetMediaValidBytes_Proxy( 
    IHsmServer * This);


void __RPC_STUB IHsmServer_ResetMediaValidBytes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmServer_GetSegmentPosition_Proxy( 
    IHsmServer * This,
    /* [in] */ REFGUID bagId,
    /* [in] */ LONGLONG fileStart,
    /* [in] */ LONGLONG fileSize,
    /* [out] */ GUID *pPosMedia,
    /* [out] */ LONGLONG *pPosOfffset);


void __RPC_STUB IHsmServer_GetSegmentPosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmServer_UpdateMediaSizeLimit_Proxy( 
    IHsmServer * This,
    /* [out] */ DWORD *pNewLimit);


void __RPC_STUB IHsmServer_UpdateMediaSizeLimit_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IHsmServer_INTERFACE_DEFINED__ */


#ifndef __IHsmUpgradeRmsDb_INTERFACE_DEFINED__
#define __IHsmUpgradeRmsDb_INTERFACE_DEFINED__

/* interface IHsmUpgradeRmsDb */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IHsmUpgradeRmsDb;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B04E802A-8D06-46BE-8930-2AA2DA4C0DF2")
    IHsmUpgradeRmsDb : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Init( 
            /* [in] */ IRmsServer *ppHsmMediaMgr) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHsmUpgradeRmsDbVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHsmUpgradeRmsDb * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHsmUpgradeRmsDb * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHsmUpgradeRmsDb * This);
        
        HRESULT ( STDMETHODCALLTYPE *Init )( 
            IHsmUpgradeRmsDb * This,
            /* [in] */ IRmsServer *ppHsmMediaMgr);
        
        END_INTERFACE
    } IHsmUpgradeRmsDbVtbl;

    interface IHsmUpgradeRmsDb
    {
        CONST_VTBL struct IHsmUpgradeRmsDbVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHsmUpgradeRmsDb_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHsmUpgradeRmsDb_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHsmUpgradeRmsDb_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHsmUpgradeRmsDb_Init(This,ppHsmMediaMgr)	\
    (This)->lpVtbl -> Init(This,ppHsmMediaMgr)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IHsmUpgradeRmsDb_Init_Proxy( 
    IHsmUpgradeRmsDb * This,
    /* [in] */ IRmsServer *ppHsmMediaMgr);


void __RPC_STUB IHsmUpgradeRmsDb_Init_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IHsmUpgradeRmsDb_INTERFACE_DEFINED__ */


#ifndef __IHsmManagedResource_INTERFACE_DEFINED__
#define __IHsmManagedResource_INTERFACE_DEFINED__

/* interface IHsmManagedResource */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IHsmManagedResource;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BA365110-6D66-11d0-9E2E-00A0C916F120")
    IHsmManagedResource : public IWsbCollectable
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetResourceId( 
            /* [out] */ GUID *pResourceId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetResourceId( 
            /* [in] */ GUID resourceId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InitFromFsaResource( 
            /* [in] */ IUnknown *pFsa) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetFsaResource( 
            /* [out] */ IUnknown **ppFsa) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CompareToIHsmManagedResource( 
            /* [in] */ IHsmManagedResource *pHsmManagedResource,
            /* [out] */ short *psResult) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHsmManagedResourceVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHsmManagedResource * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHsmManagedResource * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHsmManagedResource * This);
        
        HRESULT ( STDMETHODCALLTYPE *CompareTo )( 
            IHsmManagedResource * This,
            /* [in] */ IUnknown *pCollectable,
            /* [out] */ SHORT *pResult);
        
        HRESULT ( STDMETHODCALLTYPE *IsEqual )( 
            IHsmManagedResource * This,
            /* [in] */ IUnknown *pCollectable);
        
        HRESULT ( STDMETHODCALLTYPE *GetResourceId )( 
            IHsmManagedResource * This,
            /* [out] */ GUID *pResourceId);
        
        HRESULT ( STDMETHODCALLTYPE *SetResourceId )( 
            IHsmManagedResource * This,
            /* [in] */ GUID resourceId);
        
        HRESULT ( STDMETHODCALLTYPE *InitFromFsaResource )( 
            IHsmManagedResource * This,
            /* [in] */ IUnknown *pFsa);
        
        HRESULT ( STDMETHODCALLTYPE *GetFsaResource )( 
            IHsmManagedResource * This,
            /* [out] */ IUnknown **ppFsa);
        
        HRESULT ( STDMETHODCALLTYPE *CompareToIHsmManagedResource )( 
            IHsmManagedResource * This,
            /* [in] */ IHsmManagedResource *pHsmManagedResource,
            /* [out] */ short *psResult);
        
        END_INTERFACE
    } IHsmManagedResourceVtbl;

    interface IHsmManagedResource
    {
        CONST_VTBL struct IHsmManagedResourceVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHsmManagedResource_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHsmManagedResource_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHsmManagedResource_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHsmManagedResource_CompareTo(This,pCollectable,pResult)	\
    (This)->lpVtbl -> CompareTo(This,pCollectable,pResult)

#define IHsmManagedResource_IsEqual(This,pCollectable)	\
    (This)->lpVtbl -> IsEqual(This,pCollectable)


#define IHsmManagedResource_GetResourceId(This,pResourceId)	\
    (This)->lpVtbl -> GetResourceId(This,pResourceId)

#define IHsmManagedResource_SetResourceId(This,resourceId)	\
    (This)->lpVtbl -> SetResourceId(This,resourceId)

#define IHsmManagedResource_InitFromFsaResource(This,pFsa)	\
    (This)->lpVtbl -> InitFromFsaResource(This,pFsa)

#define IHsmManagedResource_GetFsaResource(This,ppFsa)	\
    (This)->lpVtbl -> GetFsaResource(This,ppFsa)

#define IHsmManagedResource_CompareToIHsmManagedResource(This,pHsmManagedResource,psResult)	\
    (This)->lpVtbl -> CompareToIHsmManagedResource(This,pHsmManagedResource,psResult)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IHsmManagedResource_GetResourceId_Proxy( 
    IHsmManagedResource * This,
    /* [out] */ GUID *pResourceId);


void __RPC_STUB IHsmManagedResource_GetResourceId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmManagedResource_SetResourceId_Proxy( 
    IHsmManagedResource * This,
    /* [in] */ GUID resourceId);


void __RPC_STUB IHsmManagedResource_SetResourceId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmManagedResource_InitFromFsaResource_Proxy( 
    IHsmManagedResource * This,
    /* [in] */ IUnknown *pFsa);


void __RPC_STUB IHsmManagedResource_InitFromFsaResource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmManagedResource_GetFsaResource_Proxy( 
    IHsmManagedResource * This,
    /* [out] */ IUnknown **ppFsa);


void __RPC_STUB IHsmManagedResource_GetFsaResource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmManagedResource_CompareToIHsmManagedResource_Proxy( 
    IHsmManagedResource * This,
    /* [in] */ IHsmManagedResource *pHsmManagedResource,
    /* [out] */ short *psResult);


void __RPC_STUB IHsmManagedResource_CompareToIHsmManagedResource_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IHsmManagedResource_INTERFACE_DEFINED__ */


#ifndef __IHsmManagedResourceCollection_INTERFACE_DEFINED__
#define __IHsmManagedResourceCollection_INTERFACE_DEFINED__

/* interface IHsmManagedResourceCollection */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IHsmManagedResourceCollection;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AAA2ABF1-E5CF-11d1-9974-0060976A546D")
    IHsmManagedResourceCollection : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE DeleteAllAndRelease( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHsmManagedResourceCollectionVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHsmManagedResourceCollection * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHsmManagedResourceCollection * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHsmManagedResourceCollection * This);
        
        HRESULT ( STDMETHODCALLTYPE *DeleteAllAndRelease )( 
            IHsmManagedResourceCollection * This);
        
        END_INTERFACE
    } IHsmManagedResourceCollectionVtbl;

    interface IHsmManagedResourceCollection
    {
        CONST_VTBL struct IHsmManagedResourceCollectionVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHsmManagedResourceCollection_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHsmManagedResourceCollection_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHsmManagedResourceCollection_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHsmManagedResourceCollection_DeleteAllAndRelease(This)	\
    (This)->lpVtbl -> DeleteAllAndRelease(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IHsmManagedResourceCollection_DeleteAllAndRelease_Proxy( 
    IHsmManagedResourceCollection * This);


void __RPC_STUB IHsmManagedResourceCollection_DeleteAllAndRelease_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IHsmManagedResourceCollection_INTERFACE_DEFINED__ */


#ifndef __IHsmStoragePool_INTERFACE_DEFINED__
#define __IHsmStoragePool_INTERFACE_DEFINED__

/* interface IHsmStoragePool */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IHsmStoragePool;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DD529292-3892-47A4-B016-C752A50CFC29")
    IHsmStoragePool : public IWsbCollectable
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE GetId( 
            /* [out] */ GUID *pId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetId( 
            /* [in] */ GUID Id) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMediaSet( 
            /* [out] */ GUID *pMediaSetId,
            /* [string][out] */ BSTR *pMediaSetName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMediaSet( 
            /* [in] */ GUID mediaSetId,
            /* [string][in] */ BSTR mediaSetName) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNumOnlineMedia( 
            /* [out] */ ULONG *pNumOnlineMedia) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetNumOnlineMedia( 
            /* [in] */ ULONG numOnlineMedia) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetNumMediaCopies( 
            /* [out] */ USHORT *pNumMediaCopies) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetNumMediaCopies( 
            /* [in] */ USHORT numMediaCopies) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetManagementPolicy( 
            /* [out] */ GUID *pManagementPolicyId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetManagementPolicy( 
            /* [in] */ GUID managementPolicyId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE InitFromRmsMediaSet( 
            /* [in] */ IUnknown *pRmsMediaSet) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetRmsMediaSet( 
            /* [out] */ IUnknown **ppRmsMediaSet) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE CompareToIHsmStoragePool( 
            /* [in] */ IHsmStoragePool *pHsmStoragePool,
            /* [out] */ short *psResult) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMediaSetType( 
            /* [out] */ USHORT *pMediaType) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IHsmStoragePoolVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IHsmStoragePool * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IHsmStoragePool * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IHsmStoragePool * This);
        
        HRESULT ( STDMETHODCALLTYPE *CompareTo )( 
            IHsmStoragePool * This,
            /* [in] */ IUnknown *pCollectable,
            /* [out] */ SHORT *pResult);
        
        HRESULT ( STDMETHODCALLTYPE *IsEqual )( 
            IHsmStoragePool * This,
            /* [in] */ IUnknown *pCollectable);
        
        HRESULT ( STDMETHODCALLTYPE *GetId )( 
            IHsmStoragePool * This,
            /* [out] */ GUID *pId);
        
        HRESULT ( STDMETHODCALLTYPE *SetId )( 
            IHsmStoragePool * This,
            /* [in] */ GUID Id);
        
        HRESULT ( STDMETHODCALLTYPE *GetMediaSet )( 
            IHsmStoragePool * This,
            /* [out] */ GUID *pMediaSetId,
            /* [string][out] */ BSTR *pMediaSetName);
        
        HRESULT ( STDMETHODCALLTYPE *SetMediaSet )( 
            IHsmStoragePool * This,
            /* [in] */ GUID mediaSetId,
            /* [string][in] */ BSTR mediaSetName);
        
        HRESULT ( STDMETHODCALLTYPE *GetNumOnlineMedia )( 
            IHsmStoragePool * This,
            /* [out] */ ULONG *pNumOnlineMedia);
        
        HRESULT ( STDMETHODCALLTYPE *SetNumOnlineMedia )( 
            IHsmStoragePool * This,
            /* [in] */ ULONG numOnlineMedia);
        
        HRESULT ( STDMETHODCALLTYPE *GetNumMediaCopies )( 
            IHsmStoragePool * This,
            /* [out] */ USHORT *pNumMediaCopies);
        
        HRESULT ( STDMETHODCALLTYPE *SetNumMediaCopies )( 
            IHsmStoragePool * This,
            /* [in] */ USHORT numMediaCopies);
        
        HRESULT ( STDMETHODCALLTYPE *GetManagementPolicy )( 
            IHsmStoragePool * This,
            /* [out] */ GUID *pManagementPolicyId);
        
        HRESULT ( STDMETHODCALLTYPE *SetManagementPolicy )( 
            IHsmStoragePool * This,
            /* [in] */ GUID managementPolicyId);
        
        HRESULT ( STDMETHODCALLTYPE *InitFromRmsMediaSet )( 
            IHsmStoragePool * This,
            /* [in] */ IUnknown *pRmsMediaSet);
        
        HRESULT ( STDMETHODCALLTYPE *GetRmsMediaSet )( 
            IHsmStoragePool * This,
            /* [out] */ IUnknown **ppRmsMediaSet);
        
        HRESULT ( STDMETHODCALLTYPE *CompareToIHsmStoragePool )( 
            IHsmStoragePool * This,
            /* [in] */ IHsmStoragePool *pHsmStoragePool,
            /* [out] */ short *psResult);
        
        HRESULT ( STDMETHODCALLTYPE *GetMediaSetType )( 
            IHsmStoragePool * This,
            /* [out] */ USHORT *pMediaType);
        
        END_INTERFACE
    } IHsmStoragePoolVtbl;

    interface IHsmStoragePool
    {
        CONST_VTBL struct IHsmStoragePoolVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IHsmStoragePool_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IHsmStoragePool_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IHsmStoragePool_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IHsmStoragePool_CompareTo(This,pCollectable,pResult)	\
    (This)->lpVtbl -> CompareTo(This,pCollectable,pResult)

#define IHsmStoragePool_IsEqual(This,pCollectable)	\
    (This)->lpVtbl -> IsEqual(This,pCollectable)


#define IHsmStoragePool_GetId(This,pId)	\
    (This)->lpVtbl -> GetId(This,pId)

#define IHsmStoragePool_SetId(This,Id)	\
    (This)->lpVtbl -> SetId(This,Id)

#define IHsmStoragePool_GetMediaSet(This,pMediaSetId,pMediaSetName)	\
    (This)->lpVtbl -> GetMediaSet(This,pMediaSetId,pMediaSetName)

#define IHsmStoragePool_SetMediaSet(This,mediaSetId,mediaSetName)	\
    (This)->lpVtbl -> SetMediaSet(This,mediaSetId,mediaSetName)

#define IHsmStoragePool_GetNumOnlineMedia(This,pNumOnlineMedia)	\
    (This)->lpVtbl -> GetNumOnlineMedia(This,pNumOnlineMedia)

#define IHsmStoragePool_SetNumOnlineMedia(This,numOnlineMedia)	\
    (This)->lpVtbl -> SetNumOnlineMedia(This,numOnlineMedia)

#define IHsmStoragePool_GetNumMediaCopies(This,pNumMediaCopies)	\
    (This)->lpVtbl -> GetNumMediaCopies(This,pNumMediaCopies)

#define IHsmStoragePool_SetNumMediaCopies(This,numMediaCopies)	\
    (This)->lpVtbl -> SetNumMediaCopies(This,numMediaCopies)

#define IHsmStoragePool_GetManagementPolicy(This,pManagementPolicyId)	\
    (This)->lpVtbl -> GetManagementPolicy(This,pManagementPolicyId)

#define IHsmStoragePool_SetManagementPolicy(This,managementPolicyId)	\
    (This)->lpVtbl -> SetManagementPolicy(This,managementPolicyId)

#define IHsmStoragePool_InitFromRmsMediaSet(This,pRmsMediaSet)	\
    (This)->lpVtbl -> InitFromRmsMediaSet(This,pRmsMediaSet)

#define IHsmStoragePool_GetRmsMediaSet(This,ppRmsMediaSet)	\
    (This)->lpVtbl -> GetRmsMediaSet(This,ppRmsMediaSet)

#define IHsmStoragePool_CompareToIHsmStoragePool(This,pHsmStoragePool,psResult)	\
    (This)->lpVtbl -> CompareToIHsmStoragePool(This,pHsmStoragePool,psResult)

#define IHsmStoragePool_GetMediaSetType(This,pMediaType)	\
    (This)->lpVtbl -> GetMediaSetType(This,pMediaType)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IHsmStoragePool_GetId_Proxy( 
    IHsmStoragePool * This,
    /* [out] */ GUID *pId);


void __RPC_STUB IHsmStoragePool_GetId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmStoragePool_SetId_Proxy( 
    IHsmStoragePool * This,
    /* [in] */ GUID Id);


void __RPC_STUB IHsmStoragePool_SetId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmStoragePool_GetMediaSet_Proxy( 
    IHsmStoragePool * This,
    /* [out] */ GUID *pMediaSetId,
    /* [string][out] */ BSTR *pMediaSetName);


void __RPC_STUB IHsmStoragePool_GetMediaSet_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmStoragePool_SetMediaSet_Proxy( 
    IHsmStoragePool * This,
    /* [in] */ GUID mediaSetId,
    /* [string][in] */ BSTR mediaSetName);


void __RPC_STUB IHsmStoragePool_SetMediaSet_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmStoragePool_GetNumOnlineMedia_Proxy( 
    IHsmStoragePool * This,
    /* [out] */ ULONG *pNumOnlineMedia);


void __RPC_STUB IHsmStoragePool_GetNumOnlineMedia_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmStoragePool_SetNumOnlineMedia_Proxy( 
    IHsmStoragePool * This,
    /* [in] */ ULONG numOnlineMedia);


void __RPC_STUB IHsmStoragePool_SetNumOnlineMedia_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmStoragePool_GetNumMediaCopies_Proxy( 
    IHsmStoragePool * This,
    /* [out] */ USHORT *pNumMediaCopies);


void __RPC_STUB IHsmStoragePool_GetNumMediaCopies_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmStoragePool_SetNumMediaCopies_Proxy( 
    IHsmStoragePool * This,
    /* [in] */ USHORT numMediaCopies);


void __RPC_STUB IHsmStoragePool_SetNumMediaCopies_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmStoragePool_GetManagementPolicy_Proxy( 
    IHsmStoragePool * This,
    /* [out] */ GUID *pManagementPolicyId);


void __RPC_STUB IHsmStoragePool_GetManagementPolicy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmStoragePool_SetManagementPolicy_Proxy( 
    IHsmStoragePool * This,
    /* [in] */ GUID managementPolicyId);


void __RPC_STUB IHsmStoragePool_SetManagementPolicy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmStoragePool_InitFromRmsMediaSet_Proxy( 
    IHsmStoragePool * This,
    /* [in] */ IUnknown *pRmsMediaSet);


void __RPC_STUB IHsmStoragePool_InitFromRmsMediaSet_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmStoragePool_GetRmsMediaSet_Proxy( 
    IHsmStoragePool * This,
    /* [out] */ IUnknown **ppRmsMediaSet);


void __RPC_STUB IHsmStoragePool_GetRmsMediaSet_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmStoragePool_CompareToIHsmStoragePool_Proxy( 
    IHsmStoragePool * This,
    /* [in] */ IHsmStoragePool *pHsmStoragePool,
    /* [out] */ short *psResult);


void __RPC_STUB IHsmStoragePool_CompareToIHsmStoragePool_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IHsmStoragePool_GetMediaSetType_Proxy( 
    IHsmStoragePool * This,
    /* [out] */ USHORT *pMediaType);


void __RPC_STUB IHsmStoragePool_GetMediaSetType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IHsmStoragePool_INTERFACE_DEFINED__ */


#ifndef __IMountingMedia_INTERFACE_DEFINED__
#define __IMountingMedia_INTERFACE_DEFINED__

/* interface IMountingMedia */
/* [unique][helpstring][uuid][object] */ 


EXTERN_C const IID IID_IMountingMedia;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("38E504D8-CBC5-4701-BAC5-D4F85B45FC79")
    IMountingMedia : public IUnknown
    {
    public:
        virtual HRESULT STDMETHODCALLTYPE Init( 
            /* [in] */ REFGUID mediaId,
            /* [in] */ BOOL readOnly) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE GetMediaId( 
            /* [out] */ GUID *pMediaId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetMediaId( 
            /* [in] */ REFGUID mediaId) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE WaitForMount( 
            /* [in] */ DWORD timeout) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE MountDone( void) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE SetIsReadOnly( 
            /* [in] */ BOOL readOnly) = 0;
        
        virtual HRESULT STDMETHODCALLTYPE IsReadOnly( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IMountingMediaVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IMountingMedia * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IMountingMedia * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IMountingMedia * This);
        
        HRESULT ( STDMETHODCALLTYPE *Init )( 
            IMountingMedia * This,
            /* [in] */ REFGUID mediaId,
            /* [in] */ BOOL readOnly);
        
        HRESULT ( STDMETHODCALLTYPE *GetMediaId )( 
            IMountingMedia * This,
            /* [out] */ GUID *pMediaId);
        
        HRESULT ( STDMETHODCALLTYPE *SetMediaId )( 
            IMountingMedia * This,
            /* [in] */ REFGUID mediaId);
        
        HRESULT ( STDMETHODCALLTYPE *WaitForMount )( 
            IMountingMedia * This,
            /* [in] */ DWORD timeout);
        
        HRESULT ( STDMETHODCALLTYPE *MountDone )( 
            IMountingMedia * This);
        
        HRESULT ( STDMETHODCALLTYPE *SetIsReadOnly )( 
            IMountingMedia * This,
            /* [in] */ BOOL readOnly);
        
        HRESULT ( STDMETHODCALLTYPE *IsReadOnly )( 
            IMountingMedia * This);
        
        END_INTERFACE
    } IMountingMediaVtbl;

    interface IMountingMedia
    {
        CONST_VTBL struct IMountingMediaVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IMountingMedia_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IMountingMedia_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IMountingMedia_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IMountingMedia_Init(This,mediaId,readOnly)	\
    (This)->lpVtbl -> Init(This,mediaId,readOnly)

#define IMountingMedia_GetMediaId(This,pMediaId)	\
    (This)->lpVtbl -> GetMediaId(This,pMediaId)

#define IMountingMedia_SetMediaId(This,mediaId)	\
    (This)->lpVtbl -> SetMediaId(This,mediaId)

#define IMountingMedia_WaitForMount(This,timeout)	\
    (This)->lpVtbl -> WaitForMount(This,timeout)

#define IMountingMedia_MountDone(This)	\
    (This)->lpVtbl -> MountDone(This)

#define IMountingMedia_SetIsReadOnly(This,readOnly)	\
    (This)->lpVtbl -> SetIsReadOnly(This,readOnly)

#define IMountingMedia_IsReadOnly(This)	\
    (This)->lpVtbl -> IsReadOnly(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



HRESULT STDMETHODCALLTYPE IMountingMedia_Init_Proxy( 
    IMountingMedia * This,
    /* [in] */ REFGUID mediaId,
    /* [in] */ BOOL readOnly);


void __RPC_STUB IMountingMedia_Init_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMountingMedia_GetMediaId_Proxy( 
    IMountingMedia * This,
    /* [out] */ GUID *pMediaId);


void __RPC_STUB IMountingMedia_GetMediaId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMountingMedia_SetMediaId_Proxy( 
    IMountingMedia * This,
    /* [in] */ REFGUID mediaId);


void __RPC_STUB IMountingMedia_SetMediaId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMountingMedia_WaitForMount_Proxy( 
    IMountingMedia * This,
    /* [in] */ DWORD timeout);


void __RPC_STUB IMountingMedia_WaitForMount_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMountingMedia_MountDone_Proxy( 
    IMountingMedia * This);


void __RPC_STUB IMountingMedia_MountDone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMountingMedia_SetIsReadOnly_Proxy( 
    IMountingMedia * This,
    /* [in] */ BOOL readOnly);


void __RPC_STUB IMountingMedia_SetIsReadOnly_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


HRESULT STDMETHODCALLTYPE IMountingMedia_IsReadOnly_Proxy( 
    IMountingMedia * This);


void __RPC_STUB IMountingMedia_IsReadOnly_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IMountingMedia_INTERFACE_DEFINED__ */



#ifndef __HsmEngLib_LIBRARY_DEFINED__
#define __HsmEngLib_LIBRARY_DEFINED__

/* library HsmEngLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_HsmEngLib;

EXTERN_C const CLSID CLSID_HsmServer;

#ifdef __cplusplus

class DECLSPEC_UUID("2D1E3156-25DE-11D0-8073-00A0C905F098")
HsmServer;
#endif

EXTERN_C const CLSID CLSID_CHsmUpgradeRmsDb;

#ifdef __cplusplus

class DECLSPEC_UUID("FA94233C-F4E2-4B96-A4FA-BC63AFB69F7D")
CHsmUpgradeRmsDb;
#endif

EXTERN_C const CLSID CLSID_CHsmManagedResource;

#ifdef __cplusplus

class DECLSPEC_UUID("AB939AD0-6D67-11d0-9E2E-00A0C916F120")
CHsmManagedResource;
#endif

EXTERN_C const CLSID CLSID_CHsmManagedResourceCollection;

#ifdef __cplusplus

class DECLSPEC_UUID("8448DD80-7614-11d0-9E33-00A0C916F120")
CHsmManagedResourceCollection;
#endif

EXTERN_C const CLSID CLSID_CHsmStoragePool;

#ifdef __cplusplus

class DECLSPEC_UUID("61F0B790-82D9-11d0-9E35-00A0C916F120")
CHsmStoragePool;
#endif

EXTERN_C const CLSID CLSID_CMountingMedia;

#ifdef __cplusplus

class DECLSPEC_UUID("842B10E9-FAAD-4A8C-87FE-4FF9EBF45ABC")
CMountingMedia;
#endif
#endif /* __HsmEngLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long *, unsigned long            , BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserMarshal(  unsigned long *, unsigned char *, BSTR * ); 
unsigned char * __RPC_USER  BSTR_UserUnmarshal(unsigned long *, unsigned char *, BSTR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long *, BSTR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


