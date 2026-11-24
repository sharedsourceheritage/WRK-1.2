//
// WSB Messages
//
//
// !!!!! NOTE !!!!! - See WsbGen.h for facility number assignments.
//
#ifndef _WSBERROR_
#define _WSBERROR_
//-----------------------------  MESSAGE CODES ---------------------------------
//
//  901- 999       Generic event codes for debug use.
// 1000-1099       Service error codes. These are similarly defined for all
//                 Remote Storage services. (See specific service below for detail)
// 1100-1999       Wsb (Platform) event codes.
// 2000-2999       HSM event codes. (Note: add all new HSM events to this range)
// 3000-3999       FSA event codes. (Note: add all new FSA events to this range)
// 4000-4999       RMS event codes. (Note: add all new RMS events to this range)
// 5000-5999       MVR event codes. (Note: add all new MOVER events to this range)
// 6000-6999       JOB event codes. (Note: add all new JOB events to this range)
//
// ------------------------------ EVENT CATEGORIES ------------------------------
//
//
//  Values are 32 bit values layed out as follows:
//
//   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
//   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
//  +---+-+-+-----------------------+-------------------------------+
//  |Sev|C|R|     Facility          |               Code            |
//  +---+-+-+-----------------------+-------------------------------+
//
//  where
//
//      Sev - is the severity code
//
//          00 - Success
//          01 - Informational
//          10 - Warning
//          11 - Error
//
//      C - is the Customer code flag
//
//      R - is a reserved bit
//
//      Facility - is the facility code
//
//      Code - is the facility's status code
//
//
// Define the facility codes
//


//
// Define the severity codes
//


//
// MessageId: WSB_CATEGORY_PLATFORM
//
// MessageText:
//
//  Platform
//
#define WSB_CATEGORY_PLATFORM            ((WORD)0x00000001L)

//
// MessageId: WSB_CATEGORY_RMS
//
// MessageText:
//
//  Subsystem
//
#define WSB_CATEGORY_RMS                 ((WORD)0x00000002L)

//
// MessageId: WSB_CATEGORY_HSMENG
//
// MessageText:
//
//  Engine
//
#define WSB_CATEGORY_HSMENG              ((WORD)0x00000003L)

//
// MessageId: WSB_CATEGORY_JOB
//
// MessageText:
//
//  Job
//
#define WSB_CATEGORY_JOB                 ((WORD)0x00000004L)

//
// MessageId: WSB_CATEGORY_HSMTSKMGR
//
// MessageText:
//
//  Task
//
#define WSB_CATEGORY_HSMTSKMGR           ((WORD)0x00000005L)

//
// MessageId: WSB_CATEGORY_FSA
//
// MessageText:
//
//  Agent
//
#define WSB_CATEGORY_FSA                 ((WORD)0x00000006L)

//
// MessageId: WSB_CATEGORY_GUI
//
// MessageText:
//
//  Admin
//
#define WSB_CATEGORY_GUI                 ((WORD)0x00000007L)

//
// MessageId: WSB_CATEGORY_MOVER
//
// MessageText:
//
//  Mover
//
#define WSB_CATEGORY_MOVER               ((WORD)0x00000008L)

//
// MessageId: WSB_CATEGORY_LAUNCH
//
// MessageText:
//
//  Launch
//
#define WSB_CATEGORY_LAUNCH              ((WORD)0x00000009L)

//
// MessageId: WSB_CATEGORY_TEST
//
// MessageText:
//
//  Test
//
#define WSB_CATEGORY_TEST                ((WORD)0x0000000AL)

//
// MessageId: WSB_CATEGORY_USERLINK
//
// MessageText:
//
//  UserLink
//
#define WSB_CATEGORY_USERLINK            ((WORD)0x0000000BL)

//
// ---------------------------  WSB ERROR CODES  ------------------------------
//
//
// MessageId: WSB_E_FIRST
//
// MessageText:
//
//  Define for first Wsb Error.
//
#define WSB_E_FIRST                      ((HRESULT)0x81000000L)

//
// MessageId: WSB_E_NOTFOUND
//
// MessageText:
//
//  Search of a collection or search for an object failed.
//
#define WSB_E_NOTFOUND                   ((HRESULT)0x81000001L)

//
// MessageId: WSB_E_TOOLARGE
//
// MessageText:
//
//  The collection has reached its maximum size.
//
#define WSB_E_TOOLARGE                   ((HRESULT)0x81000002L)

//
// MessageId: WSB_E_OUTOFBOUNDS
//
// MessageText:
//
//  Invalid index was passed to a collection method.
//
#define WSB_E_OUTOFBOUNDS                ((HRESULT)0x81000003L)

//
// MessageId: WSB_E_NOT_INITIALIZED
//
// MessageText:
//
//  Data or object is not properly initialized.
//
#define WSB_E_NOT_INITIALIZED            ((HRESULT)0x81000004L)

//
// MessageId: WSB_E_INVALID_DATA
//
// MessageText:
//
//  Some internal data is wrong or inconsistent.
//
#define WSB_E_INVALID_DATA               ((HRESULT)0x81000005L)

//
// MessageId: WSB_E_RESOURCE_UNAVAILABLE
//
// MessageText:
//
//  Resource which is necessary is not available.
//
#define WSB_E_RESOURCE_UNAVAILABLE       ((HRESULT)0x81000006L)

//
// MessageId: WSB_E_STREAM_ERROR
//
// MessageText:
//
//  Stream error has occurred.
//
#define WSB_E_STREAM_ERROR               ((HRESULT)0x81000007L)

//
// MessageId: WSB_E_IDB_IMP_ERROR
//
// MessageText:
//
//  IDB implementation code has an error.
//
#define WSB_E_IDB_IMP_ERROR              ((HRESULT)0x81000008L)

//
// MessageId: WSB_E_IDB_WRONG_VERSION
//
// MessageText:
//
//  ISAM database is the wrong version.
//
#define WSB_E_IDB_WRONG_VERSION          ((HRESULT)0x81000009L)

//
// MessageId: WSB_E_IDB_PRIMARY_KEY_CHANGED
//
// MessageText:
//
//  Primary record key has changed.
//
#define WSB_E_IDB_PRIMARY_KEY_CHANGED    ((HRESULT)0x8100000AL)

//
// MessageId: WSB_E_IDB_PRIMARY_UNIQUE
//
// MessageText:
//
//  Primary key must be unique.
//
#define WSB_E_IDB_PRIMARY_UNIQUE         ((HRESULT)0x8100000BL)

//
// MessageId: WSB_E_IDB_DISK_FULL
//
// MessageText:
//
//  Database disk is full.
//
#define WSB_E_IDB_DISK_FULL              ((HRESULT)0x8100000CL)

//
// MessageId: WSB_E_IDB_FILE_NOT_FOUND
//
// MessageText:
//
//  Database file cannot be found.
//
#define WSB_E_IDB_FILE_NOT_FOUND         ((HRESULT)0x8100000DL)

//
// MessageId: WSB_E_STRING_CONVERSION
//
// MessageText:
//
//  Error converting a string from one form to another.
//
#define WSB_E_STRING_CONVERSION          ((HRESULT)0x8100000EL)

//
// MessageId: WSB_E_IDB_EXCEPTION
//
// MessageText:
//
//  Database code threw an exception.
//
#define WSB_E_IDB_EXCEPTION              ((HRESULT)0x8100000FL)

//
// MessageId: WSB_E_IDB_TOO_MANY_DB
//
// MessageText:
//
//  Database file cannot be opened because the maximum allowed database files are already open.
//
#define WSB_E_IDB_TOO_MANY_DB            ((HRESULT)0x81000010L)

//
// MessageId: WSB_E_SERVICE_MISSING_DATABASES
//
// MessageText:
//
//  Persistent storage file(s) for the service cannot be found.
//
#define WSB_E_SERVICE_MISSING_DATABASES  ((HRESULT)0x81000011L)

//
// MessageId: WSB_E_SERVICE_INSTANCE_MISMATCH
//
// MessageText:
//
//  Registry identifier for the service does not match the instance identifier saved in the persistent storage files. 
//  This could happen if the Remote Storage persistence files from another installation were restored on this system. 
//  If they need to be restored, you should:
//   1.) Uninstall Remote Storage 
//   2.) Restore persistence files/databases if needed 
//   3.) Re-install Remote Storage.
//
#define WSB_E_SERVICE_INSTANCE_MISMATCH  ((HRESULT)0x81000012L)

//
// MessageId: WSB_E_DATABASE_ALREADY_EXISTS
//
// MessageText:
//
//  A request was made to create persistent storage files which already exist.
//
#define WSB_E_DATABASE_ALREADY_EXISTS    ((HRESULT)0x81000013L)

//
// MessageId: WSB_E_DOMAIN_NOT_IN_DS
//
// MessageText:
//
//  Domain name of this service or process was not found in Directory Services. Make sure the service is running under the proper account.
//
#define WSB_E_DOMAIN_NOT_IN_DS           ((HRESULT)0x81000014L)

//
// MessageId: WSB_E_PERSISTENCE_FILE_CORRUPT
//
// MessageText:
//
//  Persistence file is corrupted.
//
#define WSB_E_PERSISTENCE_FILE_CORRUPT   ((HRESULT)0x81000015L)

//
// MessageId: WSB_E_USNJ_CREATE
//
// MessageText:
//
//  USN Journal cannot be created.
//
#define WSB_E_USNJ_CREATE                ((HRESULT)0x81000016L)

//
// MessageId: WSB_E_USNJ_CREATE_DISK_FULL
//
// MessageText:
//
//  USN Journal cannot be created because the disk is full.
//
#define WSB_E_USNJ_CREATE_DISK_FULL      ((HRESULT)0x81000017L)

//
// MessageId: WSB_E_SYSTEM_DISK_FULL
//
// MessageText:
//
//  The requested operation cannot be completed because the system volume is too full.
//
#define WSB_E_SYSTEM_DISK_FULL           ((HRESULT)0x81000018L)

//
// MessageId: WSB_E_IDB_DATABASE_CORRUPT
//
// MessageText:
//
//  Remote Storage database file is corrupt.  Restore the most recent Remote Storage databases from system backup or most recent media. 
//
#define WSB_E_IDB_DATABASE_CORRUPT       ((HRESULT)0x81000019L)

//
// MessageId: WSB_E_IDB_DELETABLE_DATABASE_CORRUPT
//
// MessageText:
//
//  Remote Storage database file is corrupt.  Delete the database file specified in the ESENT error message in the event log and Remote Storage will recreate it the next time the service starts if necessary.
//
#define WSB_E_IDB_DELETABLE_DATABASE_CORRUPT ((HRESULT)0x8100001AL)

//
// MessageId: WSB_E_IDB_UPDATE_CONFLICT
//
// MessageText:
//
//  Record update conflict occurred.
//
#define WSB_E_IDB_UPDATE_CONFLICT        ((HRESULT)0x8100001BL)

//
// MessageId: WSB_E_IDB_WRONG_BACKUP_SETTINGS
//
// MessageText:
//
//  Database system was initialized with no backup support. Therefore, database backup cannot be done.
//
#define WSB_E_IDB_WRONG_BACKUP_SETTINGS  ((HRESULT)0x8100001CL)

//
// MessageId: WSB_E_INCOMPATIBLE_FILE_SYSTEM
//
// MessageText:
//
//  Cannot format the drive or media: the file system is incompatible
//
#define WSB_E_INCOMPATIBLE_FILE_SYSTEM   ((HRESULT)0x8100001DL)

//
// MessageId: WSB_E_BAD_MEDIA
//
// MessageText:
//
//  Format failed: Media or drive is bad
//
#define WSB_E_BAD_MEDIA                  ((HRESULT)0x8100001EL)

//
// MessageId: WSB_E_WRITE_PROTECTED
//
// MessageText:
//
//  Format failed: Media or drive is write protected
//
#define WSB_E_WRITE_PROTECTED            ((HRESULT)0x8100001FL)

//
// MessageId: WSB_E_CANT_LOCK
//
// MessageText:
//
//  Cannot format the drive or media: failed to lock the file system
//
#define WSB_E_CANT_LOCK                  ((HRESULT)0x81000020L)

//
// MessageId: WSB_E_BAD_LABEL
//
// MessageText:
//
//  Format failed: The volume label supplied for the media to be labeled is invalid
//
#define WSB_E_BAD_LABEL                  ((HRESULT)0x81000021L)

//
// MessageId: WSB_E_CANT_QUICK_FORMAT
//
// MessageText:
//
//  Format failed: Cannot quick format the media to the required file system. Please use a full format instead
//
#define WSB_E_CANT_QUICK_FORMAT          ((HRESULT)0x81000022L)

//
// MessageId: WSB_E_IO_ERROR
//
// MessageText:
//
//  Format failed: An undetermined i/o error occurred while accessing the media. Please replace the media.
//
#define WSB_E_IO_ERROR                   ((HRESULT)0x81000023L)

//
// MessageId: WSB_E_VOLUME_TOO_SMALL
//
// MessageText:
//
//  Format failed: The volume is too small to be formatted to the specified filesystem. Please use a different
//  filesystem or volume.
//
#define WSB_E_VOLUME_TOO_SMALL           ((HRESULT)0x81000024L)

//
// MessageId: WSB_E_VOLUME_TOO_BIG
//
// MessageText:
//
//  Format failed: The volume is too big to be formatted to the specified filesystem. Please use a different
//  filesystem or volume.
//
#define WSB_E_VOLUME_TOO_BIG             ((HRESULT)0x81000025L)

//
// MessageId: WSB_E_FORMAT_FAILED
//
// MessageText:
//
//  Format of drive or media failed.
//
#define WSB_E_FORMAT_FAILED              ((HRESULT)0x81000026L)

//
// MessageId: WSB_E_LAST
//
// MessageText:
//
//  Define for last Wsb Error.
//
#define WSB_E_LAST                       ((HRESULT)0x81000027L)

//
// ------------------------------ WSB DEBUG EVENTS ------------------------------
//
//
// MessageId: WSB_MESSAGE_GENERIC_ERROR
//
// MessageText:
//
//  Error: <%1>
//
#define WSB_MESSAGE_GENERIC_ERROR        ((HRESULT)0xC1000385L)

//
// MessageId: WSB_MESSAGE_GENERIC_WARNING
//
// MessageText:
//
//  Warning: <%1>
//
#define WSB_MESSAGE_GENERIC_WARNING      ((HRESULT)0x81000386L)

//
// MessageId: WSB_MESSAGE_GENERIC_INFORMATION
//
// MessageText:
//
//  Information: <%1>
//
#define WSB_MESSAGE_GENERIC_INFORMATION  ((HRESULT)0x41000387L)

//
// MessageId: WSB_MESSAGE_GENERIC_TEXT
//
// MessageText:
//
//  Text: <%1>
//
#define WSB_MESSAGE_GENERIC_TEXT         ((HRESULT)0x01000388L)

//
// MessageId: WSB_MESSAGE_PROGRAM_ASSERT
//
// MessageText:
//
//  Program Assert: <%1>
//
#define WSB_MESSAGE_PROGRAM_ASSERT       ((HRESULT)0xC1000389L)

//
// -------------------------------  WSB EVENTS  ------------------------------
//
//
// MessageId: WSB_MESSAGE_FIRST
//
// MessageText:
//
//  Define for first Wsb event.
//
#define WSB_MESSAGE_FIRST                ((HRESULT)0x0100044CL)

//
// MessageId: WSB_MESSAGE_IDB_ERROR
//
// MessageText:
//
//  Database system encountered an error. %1
//
#define WSB_MESSAGE_IDB_ERROR            ((HRESULT)0x0100044DL)

//
// MessageId: WSB_MESSAGE_IDB_INIT_FAILED
//
// MessageText:
//
//  Database system in directory <%1> cannot be initialized.
//
#define WSB_MESSAGE_IDB_INIT_FAILED      ((HRESULT)0xC100044EL)

//
// MessageId: WSB_MESSAGE_IDB_OPEN_FAILED
//
// MessageText:
//
//  Database %1 cannot be opened.
//
#define WSB_MESSAGE_IDB_OPEN_FAILED      ((HRESULT)0xC100044FL)

//
// MessageId: WSB_MESSAGE_IDB_CREATE_FAILED
//
// MessageText:
//
//  Database %1 cannot be created.
//
#define WSB_MESSAGE_IDB_CREATE_FAILED    ((HRESULT)0xC1000450L)

//
// MessageId: WSB_MESSAGE_IDB_BACKUP_FAILED
//
// MessageText:
//
//  Database cannot be backed up to %1.
//
#define WSB_MESSAGE_IDB_BACKUP_FAILED    ((HRESULT)0xC1000451L)

//
// MessageId: WSB_MESSAGE_IDB_BACKUP_FULL
//
// MessageText:
//
//  Full backup of database to %1.
//
#define WSB_MESSAGE_IDB_BACKUP_FULL      ((HRESULT)0x01000452L)

//
// MessageId: WSB_MESSAGE_IDB_BACKUP_INCREMENTAL
//
// MessageText:
//
//  Incremental backup of database to %1.
//
#define WSB_MESSAGE_IDB_BACKUP_INCREMENTAL ((HRESULT)0x01000453L)

//
// MessageId: WSB_MESSAGE_IDB_EXCEPTION
//
// MessageText:
//
//  Low-level database code has thrown an exception.
//
#define WSB_MESSAGE_IDB_EXCEPTION        ((HRESULT)0xC1000454L)

//
// MessageId: WSB_MESSAGE_SERVICE_ID_NOT_REGISTERED
//
// MessageText:
//
//  Storage ID for service %1 was not found in the registry.
//
#define WSB_MESSAGE_SERVICE_ID_NOT_REGISTERED ((HRESULT)0x01000455L)

//
// MessageId: WSB_MESSAGE_IDB_INCREMENTAL_BACKUP_FAILED
//
// MessageText:
//
//  Incremental backup of the database to %1 failed due to %2 in the database system.
//
#define WSB_MESSAGE_IDB_INCREMENTAL_BACKUP_FAILED ((HRESULT)0x81000456L)

//
// MessageId: WSB_MESSAGE_IDB_MISSING_FULL_BACKUP
//
// MessageText:
//
//  Incremental backup of the database to %1 failed due to a missing full backup. Full backup will be performed instead.
//
#define WSB_MESSAGE_IDB_MISSING_FULL_BACKUP ((HRESULT)0x01000457L)

//
// MessageId: WSB_MESSAGE_DATABASES_NOT_FOUND
//
// MessageText:
//
//  Persistent storage files for service %1 were not found.
//
#define WSB_MESSAGE_DATABASES_NOT_FOUND  ((HRESULT)0x01000458L)

//
// MessageId: WSB_MESSAGE_SERVICE_INSTANCE_MISMATCH
//
// MessageText:
//
//  Service ID in the persistent storage files for service %1 does not match the ID in the registry. The service initialization has failed.
//
#define WSB_MESSAGE_SERVICE_INSTANCE_MISMATCH ((HRESULT)0xC1000459L)

//
// MessageId: WSB_MESSAGE_SERVICE_ID_REGISTERED
//
// MessageText:
//
//  Service %1 automatically registered its ID to match that found in the persistent storage files.
//
#define WSB_MESSAGE_SERVICE_ID_REGISTERED ((HRESULT)0x0100045AL)

//
// MessageId: WSB_MESSAGE_SERVICE_MISSING_DATABASES
//
// MessageText:
//
//  A database for service %1 cannot be located. 
//  If you can find a copy of these files (RsEng.col , RsFsa.col) in a piece of Remote Storage media or system backup, you should:%n
//   1) Stop Remote Storage service.%n
//   2) Delete the files with .col and .bak extensions from the directory %SystemRoot%\System32\RemoteStorage%n
//   3) Restore RsEng.col and RsFsa.col from your backup storage to %SystemRoot%\System32\RemoteStorage directory.%n
//   4) Restart Remote Storage service.%n
//  If these files cannot be restored, then you may have to manually re-manage all your volumes and restore all desired settings.
//  Recalls of files already migrated, however, would not be affected.
//
#define WSB_MESSAGE_SERVICE_MISSING_DATABASES ((HRESULT)0xC100045BL)

//
// MessageId: WSB_MESSAGE_SERVICE_NEW_INSTALLATION
//
// MessageText:
//
//  New persistent storage for service %1 created.
//
#define WSB_MESSAGE_SERVICE_NEW_INSTALLATION ((HRESULT)0x0100045CL)

//
// MessageId: WSB_MESSAGE_PUBLISH_IN_DS
//
// MessageText:
//
//  Service %1 was published in Directory Services.
//
#define WSB_MESSAGE_PUBLISH_IN_DS        ((HRESULT)0x0100045DL)

//
// MessageId: WSB_MESSAGE_PUBLISH_FAILED
//
// MessageText:
//
//  Service %1 could not be published in Directory Services.
//
#define WSB_MESSAGE_PUBLISH_FAILED       ((HRESULT)0x8100045EL)

//
// MessageId: WSB_MESSAGE_FILE_RENAMED
//
// MessageText:
//
//  File <%1> has been renamed to <%2>.
//
#define WSB_MESSAGE_FILE_RENAMED         ((HRESULT)0x8100045FL)

//
// MessageId: WSB_MESSAGE_FILE_RENAME_FAILED
//
// MessageText:
//
//  Attempted rename of file <%1> to <%2> failed. %3
//
#define WSB_MESSAGE_FILE_RENAME_FAILED   ((HRESULT)0x81000460L)

//
// MessageId: WSB_MESSAGE_SAFELOAD_USING_BACKUP
//
// MessageText:
//
//  Persistent storage file <%1> cannot be loaded. Will attempt using backup file.
//
#define WSB_MESSAGE_SAFELOAD_USING_BACKUP ((HRESULT)0x41000461L)

//
// MessageId: WSB_MESSAGE_SAFELOAD_RECOVERY_FAILED
//
// MessageText:
//
//  Recovery for persistent storage file <%1> failed, because the file and its backup do not exist or both are corrupted. You can use a backup/restore program to restore the file from any tapes allocated to Remote Storage on this system (refer to the Remote Storage documentation to recover files from Remote Storage media using a backup/restore program). After restoring the file <%1>, please stop and restart Remote Storage service or reboot the system.
//
#define WSB_MESSAGE_SAFELOAD_RECOVERY_FAILED ((HRESULT)0xC1000462L)

//
// MessageId: WSB_MESSAGE_SAFESAVE_RECOVERY_CANT_ACCESS
//
// MessageText:
//
//  Persistent storage file <%1> cannot be accessed to prepare for persistent storage saving. The save has failed.
//
#define WSB_MESSAGE_SAFESAVE_RECOVERY_CANT_ACCESS ((HRESULT)0xC1000463L)

//
// MessageId: WSB_MESSAGE_SAFESAVE_RECOVERY_CANT_SAVE
//
// MessageText:
//
//  The persistent storage file <%1> cannot be saved.  <%2>  Make sure that this file (located in %SystemRoot%\System32\RemoteStorage directory) has write privileges for Administrators and System Account. You will have to stop and restart Remote Storage service or reboot the system after changing privileges.
//
#define WSB_MESSAGE_SAFESAVE_RECOVERY_CANT_SAVE ((HRESULT)0xC1000464L)

//
// MessageId: WSB_MESSAGE_SAFECREATE_SAVE_FAILED
//
// MessageText:
//
//  The persistent storage file <%1> cannot be saved. The create has failed.
//
#define WSB_MESSAGE_SAFECREATE_SAVE_FAILED ((HRESULT)0xC1000465L)

//
// MessageId: WSB_E_IDB_DATABASE_DELETED
//
// MessageText:
//
//  The Remote Storage database file <%1> has been deleted because it was corrupted.
//
#define WSB_E_IDB_DATABASE_DELETED       ((HRESULT)0x81000466L)

//
// MessageId: WSB_E_IDB_DATABASE_DELETED_NO_ERROR
//
// MessageText:
//
//  The Remote Storage database file <%1> has been deleted.
//
#define WSB_E_IDB_DATABASE_DELETED_NO_ERROR ((HRESULT)0x01000467L)

//
// MessageId: WSB_MESSAGE_LAST
//
// MessageText:
//
//  Define for last Wsb event.
//
#define WSB_MESSAGE_LAST                 ((HRESULT)0x01000468L)

//
// ---------------------------  HSM ERROR CODES  ------------------------------
//
//
// MessageId: HSM_E_FIRST
//
// MessageText:
//
//  Define for first HSM Error.
//
#define HSM_E_FIRST                      ((HRESULT)0x81030000L)

//
// MessageId: HSM_E_STG_PL_NOT_CFGD
//
// MessageText:
//
//  Remote Storage is not configured to use a specific media pool.  Use the Remote Storage Setup Wizard to configure Remote Storage.
//
#define HSM_E_STG_PL_NOT_CFGD            ((HRESULT)0x81030001L)

//
// MessageId: HSM_E_STG_PL_INVALID
//
// MessageText:
//
//  Media pool that was configured for Remote Storage is no longer valid.  Removable Storage Management (RSM) device configuration, or database, has changed from what it was when Remote Storage was initially configured.
//
#define HSM_E_STG_PL_INVALID             ((HRESULT)0x81030002L)

//
// MessageId: HSM_E_BUSY
//
// MessageText:
//
//  Data movement request is denied because Remote Storage is busy.
//
#define HSM_E_BUSY                       ((HRESULT)0x81030003L)

//
// MessageId: HSM_E_NO_MORE_MEDIA
//
// MessageText:
//
//  Data movement request is delayed because there is no available media.
//
#define HSM_E_NO_MORE_MEDIA              ((HRESULT)0x81030004L)

//
// MessageId: HSM_E_NO_MORE_MEDIA_FINAL
//
// MessageText:
//
//  Data movement request is denied because there is no available media.
//
#define HSM_E_NO_MORE_MEDIA_FINAL        ((HRESULT)0x81030005L)

//
// MessageId: HSM_E_MEDIA_NOT_AVAILABLE
//
// MessageText:
//
//  Data movement request is denied because the media is not available to the media management subsystem.
//
#define HSM_E_MEDIA_NOT_AVAILABLE        ((HRESULT)0x81030006L)

//
// MessageId: HSM_E_MEDIA_BUSY
//
// MessageText:
//
//  Data movement request is denied because the media or media access device is being used for another request.
//
#define HSM_E_MEDIA_BUSY                 ((HRESULT)0x81030007L)

//
// MessageId: HSM_E_STG_PL_NOT_FOUND
//
// MessageText:
//
//  Storage pool identified by the job is not configured for this Remote Storage installation.
//
#define HSM_E_STG_PL_NOT_FOUND           ((HRESULT)0x81030008L)

//
// MessageId: HSM_E_FILE_CHANGED
//
// MessageText:
//
//  Data movement request was skipped because the file was modified after the premigration request was made.
//
#define HSM_E_FILE_CHANGED               ((HRESULT)0x81030009L)

//
// MessageId: HSM_E_FILE_ALREADY_MANAGED
//
// MessageText:
//
//  Data movement request was skipped because the file is already managed.
//
#define HSM_E_FILE_ALREADY_MANAGED       ((HRESULT)0x8103000AL)

//
// MessageId: HSM_E_FILE_NOT_TRUNCATED
//
// MessageText:
//
//  Data movement request was skipped because the file is no longer truncated.
//
#define HSM_E_FILE_NOT_TRUNCATED         ((HRESULT)0x8103000BL)

//
// MessageId: HSM_E_SEGMENT_INFO_NOT_FOUND
//
// MessageText:
//
//  Data movement request has failed because the data cannot be located in the Remote Storage databases.
//
#define HSM_E_SEGMENT_INFO_NOT_FOUND     ((HRESULT)0x8103000CL)

//
// MessageId: HSM_E_MEDIA_INFO_NOT_FOUND
//
// MessageText:
//
//  Data movement request has failed because the data cannot be located in the Remote Storage databases (media information).
//
#define HSM_E_MEDIA_INFO_NOT_FOUND       ((HRESULT)0x8103000DL)

//
// MessageId: HSM_E_BAG_INFO_NOT_FOUND
//
// MessageText:
//
//  Data movement request has failed because the data cannot be located in the Remote Storage databases (bag information).
//
#define HSM_E_BAG_INFO_NOT_FOUND         ((HRESULT)0x8103000EL)

//
// MessageId: HSM_E_WORK_SKIPPED_CANCELLED
//
// MessageText:
//
//  Data movement request was skipped because the job was cancelled.
//
#define HSM_E_WORK_SKIPPED_CANCELLED     ((HRESULT)0x8103000FL)

//
// MessageId: HSM_E_WORK_SKIPPED_DATABASE_ACCESS
//
// MessageText:
//
//  Data movement request was skipped because the Remote Storage engine cannot access its database.
//
#define HSM_E_WORK_SKIPPED_DATABASE_ACCESS ((HRESULT)0x81030010L)

//
// MessageId: HSM_E_WORK_SKIPPED_TSK_MGR_NOT_TOLD
//
// MessageText:
//
//  Work queue cannot process the request(s) and the task manager cannot be notified.
//
#define HSM_E_WORK_SKIPPED_TSK_MGR_NOT_TOLD ((HRESULT)0x81030011L)

//
// MessageId: HSM_E_WORK_SKIPPED_FILE_TOO_BIG
//
// MessageText:
//
//  Data movement request was skipped because the file is larger than all available remote storage media.
//
#define HSM_E_WORK_SKIPPED_FILE_TOO_BIG  ((HRESULT)0x81030012L)

//
// MessageId: HSM_E_WORK_SKIPPED_FILE_BIGGER_MEDIA
//
// MessageText:
//
//  Data movement request was skipped because the file is larger than the allocated remote storage media.
//
#define HSM_E_WORK_SKIPPED_FILE_BIGGER_MEDIA ((HRESULT)0x81030013L)

//
// MessageId: HSM_E_WORK_SKIPPED_COMMIT_FAILED
//
// MessageText:
//
//  Data failed to be committed to remote storage media. All files queued for commit will be skipped.
//
#define HSM_E_WORK_SKIPPED_COMMIT_FAILED ((HRESULT)0x81030014L)

//
// MessageId: HSM_E_RECREATE_FLAG_WRONGVALUE
//
// MessageText:
//
//  Media identified to be recreated was not configured to be recreated. The recreation request is denied.
//
#define HSM_E_RECREATE_FLAG_WRONGVALUE   ((HRESULT)0x81030015L)

//
// MessageId: HSM_E_NO_COPIES_CONFIGURED
//
// MessageText:
//
//  Remote Storage received a request to use a media copy to recreate a master, but the Remote Storage is not configured to generate copies.
//
#define HSM_E_NO_COPIES_CONFIGURED       ((HRESULT)0x81030016L)

//
// MessageId: HSM_E_NO_COPIES_EXIST
//
// MessageText:
//
//  Remote Storage received a request to use a media copy to recreate a master, but either the Remote Storage has not yet created any copies of the master, or the System Administrator deleted or disabled all pre-existing copies.
//
#define HSM_E_NO_COPIES_EXIST            ((HRESULT)0x81030017L)

//
// MessageId: HSM_E_NO_COPY_EXISTS
//
// MessageText:
//
//  Remote Storage received a request to use a media copy to recreate a master, but either the Remote Storage has not yet created the specified copy of the master, or the System Administrator deleted or disabled the specified copy.
//
#define HSM_E_NO_COPY_EXISTS             ((HRESULT)0x81030018L)

//
// MessageId: HSM_E_DATABASE_VERSION_MISMATCH
//
// MessageText:
//
//  Database version expected by the server does not match that saved in the databases. The server will stop.
//
#define HSM_E_DATABASE_VERSION_MISMATCH  ((HRESULT)0x81030019L)

//
// MessageId: HSM_E_FILE_MANAGED_BY_DIFFERENT_HSM
//
// MessageText:
//
//  The instance of Remote Storage that managed the file is not the current instance. 
//  This could happen if you have restored the Remote Storage databases from another installation for disaster recovery.
//  To be able to recall files managed by the previous installation, you should:
//   1.) Uninstall Remote Storage on this system 
//   2.) Restore the Remote Storage databases and persistence files from the 
//       Remote Storage media for the previous installation. 
//       Refer to Remote Storage documentation for information on how to do the restore. 
//   3.) Re-install Remote Storage. 
//
#define HSM_E_FILE_MANAGED_BY_DIFFERENT_HSM ((HRESULT)0x8103001AL)

//
// MessageId: HSM_E_BAD_SEGMENT_INFORMATION
//
// MessageText:
//
//  Remote Storage Segment database retrieved invalid data. The file cannot be recalled.
//
#define HSM_E_BAD_SEGMENT_INFORMATION    ((HRESULT)0x8103001BL)

//
// MessageId: HSM_E_VALIDATE_BAG_NOT_FOUND
//
// MessageText:
//
//  BAG information for the file cannot be found in the Remote Storage Engine databases.
//
#define HSM_E_VALIDATE_BAG_NOT_FOUND     ((HRESULT)0x8103001CL)

//
// MessageId: HSM_E_VALIDATE_SEGMENT_NOT_FOUND
//
// MessageText:
//
//  Remote Storage Engine databases cannot find segment information for the file.
//
#define HSM_E_VALIDATE_SEGMENT_NOT_FOUND ((HRESULT)0x8103001DL)

//
// MessageId: HSM_E_VALIDATE_MEDIA_NOT_FOUND
//
// MessageText:
//
//  Remote Storage Engine databases cannot find media information for the file.
//
#define HSM_E_VALIDATE_MEDIA_NOT_FOUND   ((HRESULT)0x8103001EL)

//
// MessageId: HSM_E_VALIDATE_DATA_NOT_ON_MEDIA
//
// MessageText:
//
//  Remote Storage cannot find data for the file. This can be caused by the recreation of a remote storage media master from an incomplete (out of date) copy.
//
#define HSM_E_VALIDATE_DATA_NOT_ON_MEDIA ((HRESULT)0x8103001FL)

//
// MessageId: HSM_E_MEDIA_COPY_FAILED
//
// MessageText:
//
//  Creating or updating a remote storage media copy encountered an error while attempting to synchronize a copy set.
//
#define HSM_E_MEDIA_COPY_FAILED          ((HRESULT)0x81030020L)

//
// MessageId: HSM_E_NOT_READY
//
// MessageText:
//
//  Remote Storage Engine is not running or not initialized yet.
//
#define HSM_E_NOT_READY                  ((HRESULT)0x81030021L)

//
// MessageId: HSM_E_DISABLE_RUNNING_JOBS
//
// MessageText:
//
//  Remote Storage cannot disable jobs while jobs are running. Disabling all jobs is allowed only while no job is running.
//
#define HSM_E_DISABLE_RUNNING_JOBS       ((HRESULT)0x81030022L)

//
// MessageId: HSM_E_NO_TWO_DRIVES
//
// MessageText:
//
//  Remote Storage needs at least two enabled drives to complete the operation.
//
#define HSM_E_NO_TWO_DRIVES              ((HRESULT)0x81030023L)

//
// MessageId: HSM_E_FILE_LOCK_VIOLATION
//
// MessageText:
//
//  Remote Storage cannot access the file because another process has locked a portion of the file.
//  If this error repeated itself the job may be running when another application like backup is accessing many files.
//  Consider scheduling the Remote Storage job to a different time such that it does not run concurrently with this application.
//
#define HSM_E_FILE_LOCK_VIOLATION        ((HRESULT)0x81030024L)

//
// MessageId: HSM_E_FILE_SHARING_VIOLATION
//
// MessageText:
//
//  Remote Storage cannot access the file because it is being used by another process.
//  If this error repeated itself the job may be running when another application like backup is touching many files.
//  Consider scheduling the Remote Storage job to a different time such that it does not run concurrently with this application.
//
#define HSM_E_FILE_SHARING_VIOLATION     ((HRESULT)0x81030025L)

//
// MessageId: HSM_E_LAST
//
// MessageText:
//
//  Define for last Hsm Error.
//
#define HSM_E_LAST                       ((HRESULT)0x81030026L)

//
// ------------------------------ HSM SERVICE EVENTS ------------------------------
//
//
// MessageId: HSM_MESSAGE_SERVICE_STARTED
//
// MessageText:
//
//  Service started.
//
#define HSM_MESSAGE_SERVICE_STARTED      ((HRESULT)0x410303E8L)

//
// MessageId: HSM_MESSAGE_SERVICE_EXITING
//
// MessageText:
//
//  Service exiting.
//
#define HSM_MESSAGE_SERVICE_EXITING      ((HRESULT)0x410303E9L)

//
// MessageId: HSM_MESSAGE_SERVICE_STOPPED
//
// MessageText:
//
//  Service stopped.
//
#define HSM_MESSAGE_SERVICE_STOPPED      ((HRESULT)0x010303EAL)

//
// MessageId: HSM_MESSAGE_SERVICE_HANDLER_NOT_INSTALLED
//
// MessageText:
//
//  Handler not installed.
//
#define HSM_MESSAGE_SERVICE_HANDLER_NOT_INSTALLED ((HRESULT)0xC10303EBL)

//
// MessageId: HSM_MESSAGE_SERVICE_RECEIVED_BAD_REQUEST
//
// MessageText:
//
//  Bad service request %1.
//
#define HSM_MESSAGE_SERVICE_RECEIVED_BAD_REQUEST ((HRESULT)0xC10303ECL)

//
// MessageId: HSM_MESSAGE_SERVICE_INITIALIZATION_FAILED
//
// MessageText:
//
//  Service initialization failed. %1
//
#define HSM_MESSAGE_SERVICE_INITIALIZATION_FAILED ((HRESULT)0xC10303EDL)

//
// MessageId: HSM_MESSAGE_SERVICE_CREATE_FAILED
//
// MessageText:
//
//  Service instantiation failed. %1
//
#define HSM_MESSAGE_SERVICE_CREATE_FAILED ((HRESULT)0xC10303EEL)

//
// MessageId: HSM_MESSAGE_SERVICE_FAILED_TO_SHUTDOWN
//
// MessageText:
//
//  A failure occurred during service shutdown. %1
//
#define HSM_MESSAGE_SERVICE_FAILED_TO_SHUTDOWN ((HRESULT)0xC10303EFL)

//
// MessageId: HSM_MESSAGE_SERVICE_UNABLE_TO_SET_BACKUP_PRIVILEGE
//
// MessageText:
//
//  Unable to set backup privilege. %1
//
#define HSM_MESSAGE_SERVICE_UNABLE_TO_SET_BACKUP_PRIVILEGE ((HRESULT)0xC10303F0L)

//
// MessageId: HSM_MESSAGE_SERVICE_UNABLE_TO_SET_RESTORE_PRIVILEGE
//
// MessageText:
//
//  Unable to set restore privilege. %1
//
#define HSM_MESSAGE_SERVICE_UNABLE_TO_SET_RESTORE_PRIVILEGE ((HRESULT)0xC10303F1L)

//
// MessageId: HSM_MESSAGE_SERVICE_FAILED_COM_INIT
//
// MessageText:
//
//  Failed to initialize COM %1. %2
//
#define HSM_MESSAGE_SERVICE_FAILED_COM_INIT ((HRESULT)0xC10303F2L)

//
// -------------------------------  HSM EVENTS  ------------------------------
//
//
// MessageId: HSM_MESSAGE_FIRST
//
// MessageText:
//
//  Define for first Hsm event.
//
#define HSM_MESSAGE_FIRST                ((HRESULT)0x010307D0L)

//
// MessageId: HSM_MESSAGE_SYNCHRONIZE_MEDIA_START
//
// MessageText:
//
//  Remote Storage is beginning to synchronize a copy set.
//
#define HSM_MESSAGE_SYNCHRONIZE_MEDIA_START ((HRESULT)0x410307D1L)

//
// MessageId: HSM_MESSAGE_SYNCHRONIZE_MEDIA_END
//
// MessageText:
//
//  Remote Storage has completed its synchronize a copy set task. %1
//
#define HSM_MESSAGE_SYNCHRONIZE_MEDIA_END ((HRESULT)0x410307D2L)

//
// MessageId: HSM_MESSAGE_SYNCHRONIZE_MEDIA_ERROR
//
// MessageText:
//
//  An error occured while Remote Storage was attempting to update copy set %1 for media %2. %3
//
#define HSM_MESSAGE_SYNCHRONIZE_MEDIA_ERROR ((HRESULT)0xC10307D3L)

//
// MessageId: HSM_MESSAGE_SEARCH_STGPOOL_BY_HSMID_ERROR
//
// MessageText:
//
//  Remote Storage could not locate storage pool.  %1  Ensure the most recent databases have been restored.
//
#define HSM_MESSAGE_SEARCH_STGPOOL_BY_HSMID_ERROR ((HRESULT)0xC10307D4L)

//
// MessageId: HSM_MESSAGE_WORK_SKIPPED_COMMIT_FAILED
//
// MessageText:
//
//  Data failed to be committed to remote storage media. The file <%1> queued for commit has not been migrated.
//
#define HSM_MESSAGE_WORK_SKIPPED_COMMIT_FAILED ((HRESULT)0x010307D5L)

//
// MessageId: HSM_MESSAGE_RECREATE_MASTER_START
//
// MessageText:
//
//  Remote Storage is beginning to re-create a master media.
//
#define HSM_MESSAGE_RECREATE_MASTER_START ((HRESULT)0x410307D6L)

//
// MessageId: HSM_MESSAGE_RECREATE_MASTER_INVALID_FLAG_VALUE
//
// MessageText:
//
//  Remote Storage cancelled the master media re-creation because the media was not marked for re-creation.
//
#define HSM_MESSAGE_RECREATE_MASTER_INVALID_FLAG_VALUE ((HRESULT)0xC10307D7L)

//
// MessageId: HSM_MESSAGE_RECREATE_MASTER_COPY_OLD
//
// MessageText:
//
//  Remote Storage is re-creating a master from a copy that is not current with the original master. Data may be lost. Once the master has been re-created run the 'Validate Now' job located on the managed volume's "Tools" property page tab.
//
#define HSM_MESSAGE_RECREATE_MASTER_COPY_OLD ((HRESULT)0x810307D8L)

//
// MessageId: HSM_MESSAGE_RECREATE_MASTER_END
//
// MessageText:
//
//  Remote Storage has completed its re-create master media task. %1
//
#define HSM_MESSAGE_RECREATE_MASTER_END  ((HRESULT)0x410307D9L)

//
// MessageId: HSM_MESSAGE_RECREATE_MASTER_ERROR_END
//
// MessageText:
//
//  Remote Storage has completed its re-create master media task with the following error: %1
//
#define HSM_MESSAGE_RECREATE_MASTER_ERROR_END ((HRESULT)0xC10307DAL)

//
// MessageId: HSM_MESSAGE_DATABASE_VERSION_MISMATCH
//
// MessageText:
//
//  Remote Storage Engine expected version %1 of the databases but the databases are version %2. The service will stop.
//
#define HSM_MESSAGE_DATABASE_VERSION_MISMATCH ((HRESULT)0xC10307DBL)

//
// MessageId: HSM_MESSAGE_DATABASE_VERSION_UPGRADE
//
// MessageText:
//
//  Remote Storage Engine will upgrade version %2 of the databases to version %1.
//
#define HSM_MESSAGE_DATABASE_VERSION_UPGRADE ((HRESULT)0x010307DCL)

//
// MessageId: HSM_MESSAGE_FILE_MANAGED_BY_DIFFERENT_HSM
//
// MessageText:
//
//  Remote Storage installation that originally managed the file <%1> no longer exists, probably because Remote Storage was reinstalled. The data for this file is no longer automatically available. If the original removable media is still available, you may be able to restore the data manually with NtBackup.
//
#define HSM_MESSAGE_FILE_MANAGED_BY_DIFFERENT_HSM ((HRESULT)0x810307DDL)

//
// MessageId: HSM_MESSAGE_MANAGE_FAILED_DISK_FULL
//
// MessageText:
//
//  Remote Storage Service failed to manage the file <%1> because that disk volume is full.
//  The manage job is being cancelled.
//
#define HSM_MESSAGE_MANAGE_FAILED_DISK_FULL ((HRESULT)0xC10307DEL)

//
// MessageId: HSM_MESSAGE_DATABASE_FILE_NOT_COPIED
//
// MessageText:
//
//  A backup copy of Remote Storage database file(s) <%1> cannot be made.  %2  The problem should be corrected to insure a complete backup of all Remote Storage database files are stored on Remote Storage media.
//
#define HSM_MESSAGE_DATABASE_FILE_NOT_COPIED ((HRESULT)0x010307DFL)

//
// MessageId: HSM_MESSAGE_DATABASE_FILE_COPY_RETRY
//
// MessageText:
//
//  The previous attempt to make a backup copy of one or more Remote Storage database files did not succeed.  The operation is being retried.  An Error level event will follow if the retry does not succeed.
//
#define HSM_MESSAGE_DATABASE_FILE_COPY_RETRY ((HRESULT)0x010307E0L)

//
// MessageId: HSM_MESSAGE_TOO_MANY_CONSECUTIVE_JOB_ERRORS
//
// MessageText:
//
//  The Remote Storage job is being canceled because %1 consecutive errors were encountered.
//
#define HSM_MESSAGE_TOO_MANY_CONSECUTIVE_JOB_ERRORS ((HRESULT)0xC10307E1L)

//
// MessageId: HSM_MESSAGE_TOO_MANY_TOTAL_JOB_ERRORS
//
// MessageText:
//
//  The Remote Storage job is being canceled because %1 errors were encountered.
//
#define HSM_MESSAGE_TOO_MANY_TOTAL_JOB_ERRORS ((HRESULT)0xC10307E2L)

//
// MessageId: HSM_MESSAGE_GENERAL_DATABASE_FILE_NOT_COPIED
//
// MessageText:
//
//  A backup copy of one or more Remote Storage database file(s) cannot be made.  %1  The problem should be corrected to insure a complete backup of all Remote Storage database files are stored on Remote Storage media.
//
#define HSM_MESSAGE_GENERAL_DATABASE_FILE_NOT_COPIED ((HRESULT)0xC10307E3L)

//
// MessageId: HSM_MESSAGE_MEDIA_DISABLED
//
// MessageText:
//
//  Media <%1> required for this operation has been disabled. 
//
#define HSM_MESSAGE_MEDIA_DISABLED       ((HRESULT)0x810307E4L)

//
// MessageId: HSM_MESSAGE_PROCESS_WORK_ITEM_ERROR
//
// MessageText:
//
//  While processing the file %1, Remote Storage encountered the error: %2
//
#define HSM_MESSAGE_PROCESS_WORK_ITEM_ERROR ((HRESULT)0xC10307E5L)

//
// MessageId: HSM_MESSAGE_ABORTING_RECALL_QUEUE
//
// MessageText:
//
//  Remote Storage is terminating all outstanding recalls due to severe failures while trying to recall a file.
//
#define HSM_MESSAGE_ABORTING_RECALL_QUEUE ((HRESULT)0x810307E6L)

//
// MessageId: HSM_MESSAGE_SYNCHRONIZE_MEDIA_ABORT
//
// MessageText:
//
//  Remote Storage aborted synchronizing copy set %1. %2
//
#define HSM_MESSAGE_SYNCHRONIZE_MEDIA_ABORT ((HRESULT)0xC10307E7L)

//
// MessageId: HSM_MESSAGE_NEW_MEDIA_LIMIT
//
// MessageText:
//
//  Remote Storage updated the maximum file size to manage to %1 MB. The maximum media capacity determines this limit.
//
#define HSM_MESSAGE_NEW_MEDIA_LIMIT      ((HRESULT)0x410307E8L)

//
// MessageId: HSM_MESSAGE_LAST
//
// MessageText:
//
//  Define for last Hsm event.
//
#define HSM_MESSAGE_LAST                 ((HRESULT)0x010307E9L)

//
// MessageId: HSM_MESSAGE_MANAGE_FAILED_USER_QUOTA
//
// MessageText:
//
//  Remote Storage Service failed to manage the file <%1> because the file owner has passed the quota limit.
//  The manage job will skip every file whose owner is above the quota limit. Please delete files or enlarge the quota limit to avoid such errors in the future.
//
#define HSM_MESSAGE_MANAGE_FAILED_USER_QUOTA ((HRESULT)0xC10307EAL)

//
// ----------------------------- FSA ERROR CODES  -------------------------------
//
//
// MessageId: FSA_E_FIRST
//
// MessageText:
//
//  Define for first Fsa Error.
//
#define FSA_E_FIRST                      ((HRESULT)0x81060000L)

//
// MessageId: FSA_E_NOMEDIALOADED
//
// MessageText:
//
//  No media is loaded in the drive.
//
#define FSA_E_NOMEDIALOADED              ((HRESULT)0x81060001L)

//
// MessageId: FSA_E_UNMANAGABLE
//
// MessageText:
//
//  Resource has properties (e.g. file system type) which prevent it from being able to be managed.
//
#define FSA_E_UNMANAGABLE                ((HRESULT)0x81060002L)

//
// MessageId: FSA_E_ITEMCHANGED
//
// MessageText:
//
//  File has changed since it was premigrated, so the information in secondary storage does not match the placeholder.
//
#define FSA_E_ITEMCHANGED                ((HRESULT)0x01060003L)

//
// MessageId: FSA_E_ITEMINUSE
//
// MessageText:
//
//  File is in use (memory mapped) by another process.
//
#define FSA_E_ITEMINUSE                  ((HRESULT)0x01060004L)

//
// MessageId: FSA_E_NOTMANAGED
//
// MessageText:
//
//  File is not managed (i.e. does not contain a placeholder).
//
#define FSA_E_NOTMANAGED                 ((HRESULT)0x81060005L)

//
// MessageId: FSA_E_IOCTLTHREADFAILED
//
// MessageText:
//
//  Remote Storage encountered an error communicating with the file system driver. Recalls will not be functional until this problem is resolved.
//
#define FSA_E_IOCTLTHREADFAILED          ((HRESULT)0x81060006L)

//
// MessageId: FSA_E_PIPETHREADFAILED
//
// MessageText:
//
//  Remote Storage encountered an error communicating with the recall clients. Automatic recall notification will not be functional until this problem is resolved.
//
#define FSA_E_PIPETHREADFAILED           ((HRESULT)0x81060007L)

//
// MessageId: FSA_E_SKIPPED
//
// MessageText:
//
//  File was skipped.
//
#define FSA_E_SKIPPED                    ((HRESULT)0x81060008L)

//
// MessageId: FSA_E_RSCALREADYMANAGED
//
// MessageText:
//
//  Resource is managed by a different Remote Storage installation.
//
#define FSA_E_RSCALREADYMANAGED          ((HRESULT)0x81060009L)

//
// MessageId: FSA_E_AUTOVALIDATE_SCHEDULE_FAILED
//
// MessageText:
//
//  Remote Storage cannot schedule an automatic validate job for the volume. Run a manual validate job on this volume to correct any inconsistencies.
//
#define FSA_E_AUTOVALIDATE_SCHEDULE_FAILED ((HRESULT)0x8106000AL)

//
// MessageId: FSA_E_REPARSE_NOT_WRITTEN_FILE_CHANGED
//
// MessageText:
//
//  Reparse information for the file was not written because the file has been modified.
//
#define FSA_E_REPARSE_NOT_WRITTEN_FILE_CHANGED ((HRESULT)0x0106000BL)

//
// MessageId: FSA_E_RECALL_FAILED
//
// MessageText:
//
//  Remote Storage failed to recall the file.
//
#define FSA_E_RECALL_FAILED              ((HRESULT)0x8106000CL)

//
// MessageId: FSA_E_DATABASE_VERSION_MISMATCH
//
// MessageText:
//
//  Database version expected by the server does not match the one saved in the databases. The server will stop.
//
#define FSA_E_DATABASE_VERSION_MISMATCH  ((HRESULT)0x8106000DL)

//
// MessageId: FSA_E_FILE_IS_TOTALLY_SPARSE
//
// MessageText:
//
//  File is a totally sparse file.
//
#define FSA_E_FILE_IS_TOTALLY_SPARSE     ((HRESULT)0x0106000EL)

//
// MessageId: FSA_E_FILE_IS_PARTIALLY_SPARSE
//
// MessageText:
//
//  File is partially a sparse file.
//
#define FSA_E_FILE_IS_PARTIALLY_SPARSE   ((HRESULT)0x0106000FL)

//
// MessageId: FSA_E_FILE_IS_NOT_SPARSE
//
// MessageText:
//
//  File is completely resident.
//
#define FSA_E_FILE_IS_NOT_SPARSE         ((HRESULT)0x01060010L)

//
// MessageId: FSA_E_FILE_CHANGED
//
// MessageText:
//
//  Scanned file version and migrated file version do not match.
//
#define FSA_E_FILE_CHANGED               ((HRESULT)0x81060011L)

//
// MessageId: FSA_E_FILE_ALREADY_MANAGED
//
// MessageText:
//
//  File is already managed.
//
#define FSA_E_FILE_ALREADY_MANAGED       ((HRESULT)0x81060012L)

//
// MessageId: FSA_E_FILE_NOT_TRUNCATED
//
// MessageText:
//
//  File is not truncated.
//
#define FSA_E_FILE_NOT_TRUNCATED         ((HRESULT)0x81060013L)

//NOT USED
//
// MessageId: FSA_E_BAD_VOLUME
//
// MessageText:
//
//  Failed to identify the volume.
//
#define FSA_E_BAD_VOLUME                 ((HRESULT)0x81060014L)

//
// MessageId: FSA_E_HIT_RECALL_LIMIT
//
// MessageText:
//
//  User has hit the runaway recall limit.
//
#define FSA_E_HIT_RECALL_LIMIT           ((HRESULT)0x81060015L)

//
// MessageId: FSA_E_REPARSE_NOT_CREATED_DISK_FULL
//
// MessageText:
//
//  Reparse information for the file was not written because the disk is full.
//
#define FSA_E_REPARSE_NOT_CREATED_DISK_FULL ((HRESULT)0x81060016L)

//
// MessageId: FSA_E_ACCESS_ERROR
//
// MessageText:
//
//  Unable to truncate file <%1> because it could not be accessed <%2>.
//
#define FSA_E_ACCESS_ERROR               ((HRESULT)0x81060017L)

//
// MessageId: FSA_E_NOT_READY
//
// MessageText:
//
//  Remote Storage is not running or not initialized yet.
//
#define FSA_E_NOT_READY                  ((HRESULT)0x81060018L)

//
// MessageId: FSA_E_REPARSE_OWNER_PASS_QUOTA
//
// MessageText:
//
//  Reparse information for the file was not written because the file owner has passed the quota limit
//
#define FSA_E_REPARSE_OWNER_PASS_QUOTA   ((HRESULT)0x81060019L)

//
// MessageId: FSA_E_LAST
//
// MessageText:
//
//  Define for last Fsa Error.
//
#define FSA_E_LAST                       ((HRESULT)0x8106001AL)

//
// ------------------------------ FSA SERVICE EVENTS ------------------------------
//
//
// MessageId: FSA_MESSAGE_SERVICE_STARTED
//
// MessageText:
//
//  Service started.
//
#define FSA_MESSAGE_SERVICE_STARTED      ((HRESULT)0x410603E8L)

//
// MessageId: FSA_MESSAGE_SERVICE_EXITING
//
// MessageText:
//
//  Service exiting.
//
#define FSA_MESSAGE_SERVICE_EXITING      ((HRESULT)0x410603E9L)

//
// MessageId: FSA_MESSAGE_SERVICE_STOPPED
//
// MessageText:
//
//  Service stopped.
//
#define FSA_MESSAGE_SERVICE_STOPPED      ((HRESULT)0x010603EAL)

//
// MessageId: FSA_MESSAGE_SERVICE_HANDLER_NOT_INSTALLED
//
// MessageText:
//
//  Handler not installed.
//
#define FSA_MESSAGE_SERVICE_HANDLER_NOT_INSTALLED ((HRESULT)0xC10603EBL)

//
// MessageId: FSA_MESSAGE_SERVICE_RECEIVED_BAD_REQUEST
//
// MessageText:
//
//  Bad service request %1
//
#define FSA_MESSAGE_SERVICE_RECEIVED_BAD_REQUEST ((HRESULT)0xC10603ECL)

//
// MessageId: FSA_MESSAGE_SERVICE_INITIALIZATION_FAILED
//
// MessageText:
//
//  Service initialization failed. %1
//
#define FSA_MESSAGE_SERVICE_INITIALIZATION_FAILED ((HRESULT)0xC10603EDL)

//
// MessageId: FSA_MESSAGE_SERVICE_CREATE_FAILED
//
// MessageText:
//
//  Service instantiation failed. %1
//
#define FSA_MESSAGE_SERVICE_CREATE_FAILED ((HRESULT)0xC10603EEL)

//
// MessageId: FSA_MESSAGE_SERVICE_FAILED_TO_SAVE_DATABASE
//
// MessageText:
//
//  Failed to save database. %1
//
#define FSA_MESSAGE_SERVICE_FAILED_TO_SAVE_DATABASE ((HRESULT)0xC10603EFL)

//
// MessageId: FSA_MESSAGE_SERVICE_UNABLE_TO_SET_BACKUP_PRIVILEGE
//
// MessageText:
//
//  Unable to set backup privilege. %1
//
#define FSA_MESSAGE_SERVICE_UNABLE_TO_SET_BACKUP_PRIVILEGE ((HRESULT)0xC10603F0L)

//
// MessageId: FSA_MESSAGE_SERVICE_UNABLE_TO_SET_RESTORE_PRIVILEGE
//
// MessageText:
//
//  Unable to set restore privilege. %1
//
#define FSA_MESSAGE_SERVICE_UNABLE_TO_SET_RESTORE_PRIVILEGE ((HRESULT)0xC10603F1L)

//
// MessageId: FSA_MESSAGE_SERVICE_FAILED_TO_SHUTDOWN
//
// MessageText:
//
//  A failure occurred during service shutdown. %1
//
#define FSA_MESSAGE_SERVICE_FAILED_TO_SHUTDOWN ((HRESULT)0xC10603F2L)

//
// -------------------------------  FSA EVENTS  ------------------------------
//
//
// MessageId: FSA_MESSAGE_FIRST
//
// MessageText:
//
//  Define for first Fsa event.
//
#define FSA_MESSAGE_FIRST                ((HRESULT)0x01060BB8L)

//
// MessageId: FSA_MESSAGE_RESCANFAILED
//
// MessageText:
//
//  Rescan attempted to learn about device configuration changes, because an indication was received that device configuration has changed, but the scan failed. %1
//
#define FSA_MESSAGE_RESCANFAILED         ((HRESULT)0x81060BB9L)

//
// MessageId: FSA_MESSAGE_FILESKIPPED_ISMANAGED
//
// MessageText:
//
//  File <%2> for job <%1> was not managed because it is already managed.
//
#define FSA_MESSAGE_FILESKIPPED_ISMANAGED ((HRESULT)0x01060BBAL)

//
// MessageId: FSA_MESSAGE_FILESKIPPED_ISTOOSMALL
//
// MessageText:
//
//  File <%2> for job <%1> was not managed because it is too small to be managed.
//
#define FSA_MESSAGE_FILESKIPPED_ISTOOSMALL ((HRESULT)0x01060BBBL)

//
// MessageId: FSA_MESSAGE_FILESKIPPED_ISSPARSE
//
// MessageText:
//
//  File <%2> for job <%1> was not managed because it is a sparse file;
//
#define FSA_MESSAGE_FILESKIPPED_ISSPARSE ((HRESULT)0x01060BBCL)

//
// MessageId: FSA_MESSAGE_FILESKIPPED_ISENCRYPTED
//
// MessageText:
//
//  File <%2> for job <%1> was not managed because it is an encrypted file.
//
#define FSA_MESSAGE_FILESKIPPED_ISENCRYPTED ((HRESULT)0x01060BBDL)

//
// MessageId: FSA_MESSAGE_FILESKIPPED_ISALINK
//
// MessageText:
//
//  File <%2> for job <%1> was not managed because it is a link.
//
#define FSA_MESSAGE_FILESKIPPED_ISALINK  ((HRESULT)0x01060BBEL)

//
// MessageId: FSA_MESSAGE_FILESKIPPED_ISACCESSED
//
// MessageText:
//
//  File <%2> for job <%1> was not managed because it has been accessed too recently.
//
#define FSA_MESSAGE_FILESKIPPED_ISACCESSED ((HRESULT)0x01060BBFL)

//
// MessageId: FSA_MESSAGE_FILESKIPPED_ISTOOLARGE
//
// MessageText:
//
//  File <%2> for job <%1> was not managed because it is too large to be managed (larger than media size).
//
#define FSA_MESSAGE_FILESKIPPED_ISTOOLARGE ((HRESULT)0x01060BC0L)

//
// MessageId: FSA_MESSAGE_TRUNCSKIPPED_ISNOTMANAGED
//
// MessageText:
//
//  File <%2> for job <%1> was not truncated because it is not currently premigrated.
//
#define FSA_MESSAGE_TRUNCSKIPPED_ISNOTMANAGED ((HRESULT)0x01060BC1L)

//
// MessageId: FSA_MESSAGE_TRUNCSKIPPED_ISCHANGED
//
// MessageText:
//
//  File <%2> for job <%1> was not truncated because it has changed since it was premigrated.
//
#define FSA_MESSAGE_TRUNCSKIPPED_ISCHANGED ((HRESULT)0x01060BC2L)

//
// MessageId: FSA_MESSAGE_TRUNCSKIPPED_ISMAPPED
//
// MessageText:
//
//  File <%2> for job <%1> was not truncated because another process has it memory mapped.
//
#define FSA_MESSAGE_TRUNCSKIPPED_ISMAPPED ((HRESULT)0x01060BC3L)

//
// MessageId: FSA_MESSAGE_RECALL_RECOVERY_FAIL
//
// MessageText:
//
//  Recovery from aborted recall of file <%1> failed.
//
#define FSA_MESSAGE_RECALL_RECOVERY_FAIL ((HRESULT)0x81060BC4L)

//
// MessageId: FSA_MESSAGE_TRUNCATE_RECOVERY_FAIL
//
// MessageText:
//
//  Recovery from aborted truncate of file <%1> failed. %2
//
#define FSA_MESSAGE_TRUNCATE_RECOVERY_FAIL ((HRESULT)0x81060BC5L)

//
// MessageId: FSA_MESSAGE_RECALL_RECOVERY_OK
//
// MessageText:
//
//  Recovery from aborted recall of file <%1> succeeded.
//
#define FSA_MESSAGE_RECALL_RECOVERY_OK   ((HRESULT)0x01060BC6L)

//
// MessageId: FSA_MESSAGE_TRUNCATE_RECOVERY_OK
//
// MessageText:
//
//  Recovery from aborted truncate of file <%1> succeeded.
//
#define FSA_MESSAGE_TRUNCATE_RECOVERY_OK ((HRESULT)0x01060BC7L)

//
// MessageId: FSA_MESSAGE_RSCFAILEDINIT
//
// MessageText:
//
//  Scan for manageable drives encountered an error on drive <%2>. %1  The drive will be skipped. If you wish to manage this drive, then fix the problem with the drive and try again.
//
#define FSA_MESSAGE_RSCFAILEDINIT        ((HRESULT)0x01060BC8L)

//
// MessageId: FSA_MESSAGE_REPARSE_NOT_WRITTEN_FILE_CHANGED
//
// MessageText:
//
//  Reparse information for the file <%1> was not written because the file has been modified.
//
#define FSA_MESSAGE_REPARSE_NOT_WRITTEN_FILE_CHANGED ((HRESULT)0x01060BC9L)

//
// MessageId: FSA_MESSAGE_FILE_NOT_IN_PREMIG_LIST
//
// MessageText:
//
//  File <%1> could not be added to the premigration list. %2
//
#define FSA_MESSAGE_FILE_NOT_IN_PREMIG_LIST ((HRESULT)0x41060BCAL)

//
// MessageId: FSA_MESSAGE_DATABASE_VERSION_MISMATCH
//
// MessageText:
//
//  Remote Storage File expected version %1 of the databases but the databases are version %2. The service will stop.
//
#define FSA_MESSAGE_DATABASE_VERSION_MISMATCH ((HRESULT)0xC1060BCBL)

//
// MessageId: FSA_MESSAGE_FILESKIPPED_HASEA
//
// MessageText:
//
//  File <%2> for job <%1> was not managed because it has extended attributes.
//
#define FSA_MESSAGE_FILESKIPPED_HASEA    ((HRESULT)0x01060BCCL)

//
// MessageId: FSA_MESSAGE_PREMIGRATION_LIST_MISSING
//
// MessageText:
//
//  Remote Storage File did not find a premigration list for volume <%1>. An empty list has been created and a validate job will be scheduled to construct the premigration list.
//
#define FSA_MESSAGE_PREMIGRATION_LIST_MISSING ((HRESULT)0x41060BCDL)

//
// MessageId: FSA_MESSAGE_AUTO_VALIDATE
//
// MessageText:
//
//  Validate job has been scheduled for volume <%1> to rebuild the premigration list.
//
#define FSA_MESSAGE_AUTO_VALIDATE        ((HRESULT)0x41060BCEL)

//
// MessageId: FSA_MESSAGE_VALIDATE_TRUNCATED_FILE
//
// MessageText:
//
//  File <%1> was truncated by the validate job.
//
#define FSA_MESSAGE_VALIDATE_TRUNCATED_FILE ((HRESULT)0x01060BCFL)

//
// MessageId: FSA_MESSAGE_VALIDATE_RESET_PH_MODIFY_TIME
//
// MessageText:
//
//  Reparse information modify time for file <%1> was updated by the validate job.
//
#define FSA_MESSAGE_VALIDATE_RESET_PH_MODIFY_TIME ((HRESULT)0x01060BD0L)

//
// MessageId: FSA_MESSAGE_VALIDATE_UNMANAGED_FILE
//
// MessageText:
//
//  File <%1> was unmanaged by the validate job because the modify time in the reparse point information did not match the modify date of the file.
//
#define FSA_MESSAGE_VALIDATE_UNMANAGED_FILE ((HRESULT)0x01060BD1L)

//
// MessageId: FSA_MESSAGE_VALIDATE_UNMANAGED_FILE_ENGINE
//
// MessageText:
//
//  Managed file <%1> on <%2> was unmanaged by the validate job because the Remote Storage Engine reported the exception <%3> when validating the reparse point information.
//
#define FSA_MESSAGE_VALIDATE_UNMANAGED_FILE_ENGINE ((HRESULT)0x01060BD2L)

//
// MessageId: FSA_MESSAGE_VALIDATE_DELETED_FILE_ENGINE
//
// MessageText:
//
//  Truncated file <%1> on <%2> reported exception <%3> when validating the reparse point information. This file will not be accessible until this problem is resolved.
//
#define FSA_MESSAGE_VALIDATE_DELETED_FILE_ENGINE ((HRESULT)0x41060BD3L)

//
// MessageId: FSA_MESSAGE_CANNOT_CREATE_USNJ
//
// MessageText:
//
//  USN journal for volume %1 cannot be created. This volume cannot be managed by Remote Storage.
//
#define FSA_MESSAGE_CANNOT_CREATE_USNJ   ((HRESULT)0xC1060BD4L)

//
// MessageId: FSA_MESSAGE_CANNOT_CREATE_USNJ_DISK_FULL
//
// MessageText:
//
//  USN journal for volume %1 cannot be created because the disk is too full. This volume cannot be managed by Remote Storage.
//
#define FSA_MESSAGE_CANNOT_CREATE_USNJ_DISK_FULL ((HRESULT)0xC1060BD5L)

//
// MessageId: FSA_MESSAGE_CANNOT_ACCESS_USNJ
//
// MessageText:
//
//  Remote Storage cannot access the USN Journal for volume %2. %1  This volume cannot be managed by Remote Storage.
//
#define FSA_MESSAGE_CANNOT_ACCESS_USNJ   ((HRESULT)0xC1060BD6L)

//
// MessageId: FSA_MESSAGE_RECALL_TIMING_MINUTES
//
// MessageText:
//
//  Recall of <%1> took %2 minutes to complete. %3
//
#define FSA_MESSAGE_RECALL_TIMING_MINUTES ((HRESULT)0x01060BD7L)

//
// MessageId: FSA_MESSAGE_RECALL_TIMING_SECONDS
//
// MessageText:
//
//  Recall of <%1> took %2 seconds to complete. %3
//
#define FSA_MESSAGE_RECALL_TIMING_SECONDS ((HRESULT)0x01060BD8L)

//
// MessageId: FSA_MESSAGE_NOT_UPDATING_ACCESS_DATES
//
// MessageText:
//
//  This server has been configured to run without updating last access times. Remote Storage relies on being able to use last access times to determine which files are not being used and should be moved to Remote Storage. For best operation, please change the NTFS configuration in the registry to allow updating of access times and reboot the server.
//
#define FSA_MESSAGE_NOT_UPDATING_ACCESS_DATES ((HRESULT)0x81060BD9L)

//
// MessageId: FSA_MESSAGE_USN_CHECK_FAILED
//
// MessageText:
//
//  Pretruncation USN Journal check for file <%1> cannot be performed by Remote Storage. %2  The CRC check will be performed instead.
//
#define FSA_MESSAGE_USN_CHECK_FAILED     ((HRESULT)0x01060BDAL)

//
// MessageId: FSA_MESSAGE_IOCTLTHREADFAILED
//
// MessageText:
//
//  Remote Storage encountered an error communicating with the file system driver. %1  Recalls will not be functional until this problem is resolved.
//
#define FSA_MESSAGE_IOCTLTHREADFAILED    ((HRESULT)0x81060BDBL)

//
// MessageId: FSA_MESSAGE_PIPETHREADFAILED
//
// MessageText:
//
//  Remote Storage encountered an error communicating with the recall clients. %1  Automatic recall notification will not be functional until this problem is resolved.
//
#define FSA_MESSAGE_PIPETHREADFAILED     ((HRESULT)0x81060BDCL)

//
// MessageId: FSA_MESSAGE_AUTOVALIDATE_SCHEDULE_FAILED
//
// MessageText:
//
//  Automatic validate job for volume <%1> cannot be scheduled by Remote Storage. Run a manual validate job on this volume to correct any inconsistencies.
//
#define FSA_MESSAGE_AUTOVALIDATE_SCHEDULE_FAILED ((HRESULT)0x81060BDDL)

//
// MessageId: FSA_MESSAGE_RECALL_FAILED
//
// MessageText:
//
//  Remote Storage failed to recall file <%1>. %2
//
#define FSA_MESSAGE_RECALL_FAILED        ((HRESULT)0x81060BDEL)

//
// MessageId: FSA_MESSAGE_BAD_VOLUME
//
// MessageText:
//
//  Remote Storage failed to identify volume <%1>. %2
//
#define FSA_MESSAGE_BAD_VOLUME           ((HRESULT)0x81060BDFL)

//
// MessageId: FSA_MESSAGE_HIT_RECALL_LIMIT_ACCESSDENIED
//
// MessageText:
//
//  User %1 has hit the runaway recall limit. File recalls by this user will be denied.
//
#define FSA_MESSAGE_HIT_RECALL_LIMIT_ACCESSDENIED ((HRESULT)0x81060BE0L)

//
// MessageId: FSA_MESSAGE_HIT_RECALL_LIMIT_TRUNCATEONCLOSE
//
// MessageText:
//
//  User %1 has hit the runaway recall limit. Files recalled by this user will not remain on primary storage after the user closes them.
//
#define FSA_MESSAGE_HIT_RECALL_LIMIT_TRUNCATEONCLOSE ((HRESULT)0x81060BE1L)

//
// MessageId: FSA_MESSAGE_REPARSE_NOT_CREATED
//
// MessageText:
//
//  Reparse information for the file <%1> was not created for the following reason: %2
//
#define FSA_MESSAGE_REPARSE_NOT_CREATED  ((HRESULT)0x01060BE2L)

//
// MessageId: FSA_MESSAGE_RECALL_FAILED_NOT_READY
//
// MessageText:
//
//  Remote Storage failed to recall file <%1>. %2
//
#define FSA_MESSAGE_RECALL_FAILED_NOT_READY ((HRESULT)0x01060BE3L)

//
// MessageId: FSA_MESSAGE_LAST
//
// MessageText:
//
//  Define for last Fsa event.
//
#define FSA_MESSAGE_LAST                 ((HRESULT)0x01060BE4L)

//
// ------------------------------ RMS ERROR CODES  -----------------------------
//
//
// MessageId: RMS_E_FIRST
//
// MessageText:
//
//  Define for first Rms Error.
//
#define RMS_E_FIRST                      ((HRESULT)0x81010000L)

//
// MessageId: RMS_E_NOT_FOUND
//
// MessageText:
//
//  Item was not found.
//
#define RMS_E_NOT_FOUND                  ((HRESULT)0x81010001L)

//
// MessageId: RMS_E_NOT_SUPPORTED
//
// MessageText:
//
//  Operation is not supported.
//
#define RMS_E_NOT_SUPPORTED              ((HRESULT)0x81010002L)

//
// MessageId: RMS_E_RESOURCE_BUSY
//
// MessageText:
//
//  Resource required to complete the operation is busy.
//
#define RMS_E_RESOURCE_BUSY              ((HRESULT)0x81010003L)

//
// MessageId: RMS_E_CARTRIDGE_BUSY
//
// MessageText:
//
//  Media is in use.
//
#define RMS_E_CARTRIDGE_BUSY             ((HRESULT)0x81010004L)

//
// MessageId: RMS_E_DRIVE_BUSY
//
// MessageText:
//
//  Drive resource required to complete the operation is busy.
//
#define RMS_E_DRIVE_BUSY                 ((HRESULT)0x81010005L)

//
// MessageId: RMS_E_RESOURCE_UNAVAILABLE
//
// MessageText:
//
//  Resource required to complete the operation is not available.
//
#define RMS_E_RESOURCE_UNAVAILABLE       ((HRESULT)0x81010006L)

//
// MessageId: RMS_E_CARTRIDGE_UNAVAILABLE
//
// MessageText:
//
//  Media is not available for normal operations.
//
#define RMS_E_CARTRIDGE_UNAVAILABLE      ((HRESULT)0x81010007L)

//
// MessageId: RMS_E_DRIVE_UNAVAILABLE
//
// MessageText:
//
//  Drive resource required to complete the operation is not available.
//
#define RMS_E_DRIVE_UNAVAILABLE          ((HRESULT)0x81010008L)

//
// MessageId: RMS_E_LIBRARY_UNAVAILABLE
//
// MessageText:
//
//  Library resource required to complete the operation is not available.
//
#define RMS_E_LIBRARY_UNAVAILABLE        ((HRESULT)0x81010009L)

//
// MessageId: RMS_E_ACCESS_DENIED
//
// MessageText:
//
//  Access to the object is denied.
//
#define RMS_E_ACCESS_DENIED              ((HRESULT)0x8101000AL)

//
// MessageId: RMS_E_INVALIDARG
//
// MessageText:
//
//  One or more parameters are incorrect.
//
#define RMS_E_INVALIDARG                 ((HRESULT)0x8101000BL)

//
// MessageId: RMS_E_CANCELLED
//
// MessageText:
//
//  User cancelled the operation.
//
#define RMS_E_CANCELLED                  ((HRESULT)0x8101000CL)

//
// MessageId: RMS_E_REQUEST_REFUSED
//
// MessageText:
//
//  Request is refused.
//
#define RMS_E_REQUEST_REFUSED            ((HRESULT)0x8101000DL)

//
// MessageId: RMS_E_WRITE_PROTECT
//
// MessageText:
//
//  Media is write protected.
//
#define RMS_E_WRITE_PROTECT              ((HRESULT)0x8101000EL)

//
// MessageId: RMS_E_MEDIA_OFFLINE
//
// MessageText:
//
//  Media is offline.
//
#define RMS_E_MEDIA_OFFLINE              ((HRESULT)0x8101000FL)

//
// MessageId: RMS_E_TIMEOUT
//
// MessageText:
//
//  Timeout period expired while waiting for media.
//
#define RMS_E_TIMEOUT                    ((HRESULT)0x81010010L)

//
// MessageId: RMS_E_SCRATCH_NOT_FOUND
//
// MessageText:
//
//  Free media is not available. Add more free media.
//
#define RMS_E_SCRATCH_NOT_FOUND          ((HRESULT)0x81010011L)

//
// MessageId: RMS_E_SCRATCH_NOT_FOUND_FINAL
//
// MessageText:
//
//  Free media is not available. Configure your system with more free medias.
//
#define RMS_E_SCRATCH_NOT_FOUND_FINAL    ((HRESULT)0x81010012L)

//
// MessageId: RMS_E_SCRATCH_NOT_FOUND_TOO_SMALL
//
// MessageText:
//
//  Free media with the requested capacity is not available.
//
#define RMS_E_SCRATCH_NOT_FOUND_TOO_SMALL ((HRESULT)0x81010013L)

//
// MessageId: RMS_E_CARTRIDGE_NOT_FOUND
//
// MessageText:
//
//  Media cannot be found.  It may have been deallocated.
//
#define RMS_E_CARTRIDGE_NOT_FOUND        ((HRESULT)0x81010014L)

//
// MessageId: RMS_E_CARTRIDGE_DISABLED
//
// MessageText:
//
//  Media required for this operation is disabled.
//
#define RMS_E_CARTRIDGE_DISABLED         ((HRESULT)0x81010015L)

//
// MessageId: RMS_E_CARTRIDGE_NOT_MOUNTED
//
// MessageText:
//
//  Media is not mounted. Cannot dismount.
//
#define RMS_E_CARTRIDGE_NOT_MOUNTED      ((HRESULT)0x81010016L)

//
// MessageId: RMS_E_LIBRARY_NOT_FOUND
//
// MessageText:
//
//  Specified library was not found.
//
#define RMS_E_LIBRARY_NOT_FOUND          ((HRESULT)0x81010017L)

//
// MessageId: RMS_E_MEDIASET_NOT_FOUND
//
// MessageText:
//
//  The media pool identifier does not represent a valid media pool.  The Removable Storage Management (RSM) device configuration or database has changed from what it was when Remote Storage was initially configured.
//
#define RMS_E_MEDIASET_NOT_FOUND         ((HRESULT)0x81010018L)

//
// MessageId: RMS_E_ALREADY_EXISTS
//
// MessageText:
//
//  Attempt to create an object failed because the object already exists, and the create disposition was new.
//
#define RMS_E_ALREADY_EXISTS             ((HRESULT)0x81010019L)

//
// MessageId: RMS_E_NTMS_OBJECT_NOT_FOUND
//
// MessageText:
//
//  Specified Removable Storage Management (RSM) object could not be found.
//
#define RMS_E_NTMS_OBJECT_NOT_FOUND      ((HRESULT)0x8101001AL)

//
// MessageId: RMS_E_NTMS_NOT_CONNECTED
//
// MessageText:
//
//  Remote Storage cannot establish a connection to Removable Storage Management (RSM). Check that Removable Storage Management (RSM) is properly installed, configured, and is running. Then restart Remote Storage.
//
#define RMS_E_NTMS_NOT_CONNECTED         ((HRESULT)0x8101001BL)

//
// MessageId: RMS_E_NOT_CONFIGURED_FOR_NTMS
//
// MessageText:
//
//  Remote Storage Media is not currently configured to run with Removable Storage Management (RSM).
//
#define RMS_E_NOT_CONFIGURED_FOR_NTMS    ((HRESULT)0x8101001CL)

//
// MessageId: RMS_E_NTMS_NOT_REGISTERED
//
// MessageText:
//
//  Removable Storage Management (RSM) is not registered. Check that Removable Storage Management (RSM) is properly installed, configured, and is running. Then restart Remote Storage.
//
#define RMS_E_NTMS_NOT_REGISTERED        ((HRESULT)0x8101001DL)

//
// MessageId: RMS_E_NOT_READY_SERVER_STARTING
//
// MessageText:
//
//  Remote Storage Media is starting.
//
#define RMS_E_NOT_READY_SERVER_STARTING  ((HRESULT)0x8101001EL)

//
// MessageId: RMS_E_NOT_READY_SERVER_STARTED
//
// MessageText:
//
//  Remote Storage Media has not initialized.
//
#define RMS_E_NOT_READY_SERVER_STARTED   ((HRESULT)0x8101001FL)

//
// MessageId: RMS_E_NOT_READY_SERVER_INITIALIZING
//
// MessageText:
//
//  Remote Storage Media is initializing.
//
#define RMS_E_NOT_READY_SERVER_INITIALIZING ((HRESULT)0x81010020L)

//
// MessageId: RMS_E_NOT_READY_SERVER_STOPPING
//
// MessageText:
//
//  Remote Storage Media is in the process of stopping.
//
#define RMS_E_NOT_READY_SERVER_STOPPING  ((HRESULT)0x81010021L)

//
// MessageId: RMS_E_NOT_READY_SERVER_STOPPED
//
// MessageText:
//
//  Remote Storage Media has stopped.
//
#define RMS_E_NOT_READY_SERVER_STOPPED   ((HRESULT)0x81010022L)

//
// MessageId: RMS_E_NOT_READY_SERVER_SUSPENDING
//
// MessageText:
//
//  Remote Storage Media is suspending operation.
//
#define RMS_E_NOT_READY_SERVER_SUSPENDING ((HRESULT)0x81010023L)

//
// MessageId: RMS_E_NOT_READY_SERVER_SUSPENDED
//
// MessageText:
//
//  Remote Storage Media has suspended operation.
//
#define RMS_E_NOT_READY_SERVER_SUSPENDED ((HRESULT)0x81010024L)

//
// MessageId: RMS_E_NOT_READY_SERVER_RESUMING
//
// MessageText:
//
//  Remote Storage Media is resuming operation.
//
#define RMS_E_NOT_READY_SERVER_RESUMING  ((HRESULT)0x81010025L)

//
// MessageId: RMS_E_NOT_READY_SERVER_DISABLED
//
// MessageText:
//
//  Remote Storage Media has been disabled. Check for a previous event that describes the reason.
//
#define RMS_E_NOT_READY_SERVER_DISABLED  ((HRESULT)0x81010026L)

//
// MessageId: RMS_E_NOT_READY_SERVER_LOCKED
//
// MessageText:
//
//  Remote Storage Media is performing a synchronized operation and cannot be accessed.
//
#define RMS_E_NOT_READY_SERVER_LOCKED    ((HRESULT)0x81010027L)

//
// MessageId: RMS_E_DATABASE_MISMATCH
//
// MessageText:
//
//  Previous Remote Storage Media database does not match with the one expected.
//
#define RMS_E_DATABASE_MISMATCH          ((HRESULT)0x81010028L)

//
// MessageId: RMS_E_DATABASE_VERSION_MISMATCH
//
// MessageText:
//
//  Database version expected by the server does not match that saved in the databases. The server will stop.
//
#define RMS_E_DATABASE_VERSION_MISMATCH  ((HRESULT)0x81010029L)

//
// MessageId: RMS_E_POWER_EVENT
//
// MessageText:
//
//  Suspended by external power event.
//
#define RMS_E_POWER_EVENT                ((HRESULT)0x8101002AL)

//
// MessageId: RMS_E_LAST
//
// MessageText:
//
//  Define for last Rms Error.
//
#define RMS_E_LAST                       ((HRESULT)0x8101002BL)

//
// ----------------------------- RMS SEVICE EVENTS ------------------------------
//
//
// MessageId: RMS_MESSAGE_SERVICE_UNABLE_TO_SET_BACKUP_PRIVILEGE
//
// MessageText:
//
//  Unable to set backup privilege. %1
//
#define RMS_MESSAGE_SERVICE_UNABLE_TO_SET_BACKUP_PRIVILEGE ((HRESULT)0xC10103E8L)

//
// MessageId: RMS_MESSAGE_SERVICE_UNABLE_TO_SET_RESTORE_PRIVILEGE
//
// MessageText:
//
//  Unable to set restore privilege. %1
//
#define RMS_MESSAGE_SERVICE_UNABLE_TO_SET_RESTORE_PRIVILEGE ((HRESULT)0xC10103E9L)

//
// -------------------------------  RMS EVENTS  ------------------------------
//
//
// MessageId: RMS_MESSAGE_FIRST
//
// MessageText:
//
//  Define for first Rms event.
//
#define RMS_MESSAGE_FIRST                ((HRESULT)0x01010FA0L)

//
// MessageId: RMS_MESSAGE_CARTRIDGE_MOUNTED
//
// MessageText:
//
//  Media <%1/%2> was successfully mounted.
//
#define RMS_MESSAGE_CARTRIDGE_MOUNTED    ((HRESULT)0x01010FA1L)

//
// MessageId: RMS_MESSAGE_MOUNT_FAILED
//
// MessageText:
//
//  Media <%1/%2> cannot be mounted into a drive. %3
//
#define RMS_MESSAGE_MOUNT_FAILED         ((HRESULT)0x81010FA2L)

//
// MessageId: RMS_MESSAGE_SCRATCH_MOUNT_FAILED
//
// MessageText:
//
//  Scratch mount operation for <%1> cannot complete. %2
//
#define RMS_MESSAGE_SCRATCH_MOUNT_FAILED ((HRESULT)0x81010FA3L)

//
// MessageId: RMS_MESSAGE_CARTRIDGE_DISMOUNTED
//
// MessageText:
//
//  Media <%1/%2> was successfully dismounted.
//
#define RMS_MESSAGE_CARTRIDGE_DISMOUNTED ((HRESULT)0x01010FA4L)

//
// MessageId: RMS_MESSAGE_DISMOUNT_FAILED
//
// MessageText:
//
//  Media <%1/%2> cannot be dismounted. %3
//
#define RMS_MESSAGE_DISMOUNT_FAILED      ((HRESULT)0x81010FA5L)

//
// MessageId: RMS_MESSAGE_CARTRIDGE_RECYCLED
//
// MessageText:
//
//  Media <%1/%2> was successfully recycled.
//
#define RMS_MESSAGE_CARTRIDGE_RECYCLED   ((HRESULT)0x01010FA6L)

//
// MessageId: RMS_MESSAGE_CARTRIDGE_RECYCLE_FAILED
//
// MessageText:
//
//  Media <%1/%2> cannot be recycled. %3
//
#define RMS_MESSAGE_CARTRIDGE_RECYCLE_FAILED ((HRESULT)0x81010FA7L)

//
// MessageId: RMS_MESSAGE_SEQUENTIAL_ACCESS_MEDIA_IN_USE
//
// MessageText:
//
//  Mount operation cannot complete because the specified sequential access media is already in use by another process. Try again later.
//
#define RMS_MESSAGE_SEQUENTIAL_ACCESS_MEDIA_IN_USE ((HRESULT)0x81010FA8L)

//
// MessageId: RMS_MESSAGE_CARTRIDGE_NOT_FOUND
//
// MessageText:
//
//  Media <%1> cannot be found. %2
//
#define RMS_MESSAGE_CARTRIDGE_NOT_FOUND  ((HRESULT)0x01010FA9L)

//
// MessageId: RMS_MESSAGE_NTMS_CONNECTION_NOT_ESABLISHED
//
// MessageText:
//
//  Connection to Removable Storage Management (RSM) cannot be established. %1  Correct the problem then restart the Remote Storage service.
//
#define RMS_MESSAGE_NTMS_CONNECTION_NOT_ESABLISHED ((HRESULT)0xC1010FAAL)

//
// MessageId: RMS_MESSAGE_NTMS_INITIALIZATION_FAILED
//
// MessageText:
//
//  Remote Storage initialization with Removable Storage Management (RSM) cannot complete. %1  Correct the problem then restart the Remote Storage service.
//
#define RMS_MESSAGE_NTMS_INITIALIZATION_FAILED ((HRESULT)0xC1010FABL)

//
// MessageId: RMS_MESSAGE_OBJECT_DISABLED
//
// MessageText:
//
//  <%1> disabled. %2
//
#define RMS_MESSAGE_OBJECT_DISABLED      ((HRESULT)0x01010FACL)

//
// MessageId: RMS_MESSAGE_OBJECT_ENABLED
//
// MessageText:
//
//  <%1> enabled.
//
#define RMS_MESSAGE_OBJECT_ENABLED       ((HRESULT)0x01010FADL)

//
// MessageId: RMS_MESSAGE_DATABASE_VERSION_MISMATCH
//
// MessageText:
//
//  Remote Storage Media expected version %1 of the databases but the databases are version %2. The service will stop.
//
#define RMS_MESSAGE_DATABASE_VERSION_MISMATCH ((HRESULT)0xC1010FAEL)

//
// MessageId: RMS_MESSAGE_SCRATCH_MEDIA_REQUEST
//
// MessageText:
//
//  Remote Storage cannot find a unit of free media of sufficient capacity. Please add a unit of %1 media with a nominal (uncompressed) capacity of at least %2.
//
#define RMS_MESSAGE_SCRATCH_MEDIA_REQUEST ((HRESULT)0x81010FAFL)

//
// MessageId: RMS_MESSAGE_SCRATCH_MEDIA_NO_SIZE_REQUEST
//
// MessageText:
//
//  Remote Storage cannot find a unit of free media. Please add a unit of %1 media to the library.
//
#define RMS_MESSAGE_SCRATCH_MEDIA_NO_SIZE_REQUEST ((HRESULT)0x81010FB0L)

//
// MessageId: RMS_MESSAGE_NTMS_FAILURE
//
// MessageText:
//
//  Unexpected Removable Storage Management (RSM) return value. Function: %1, returned: %2  Item Skipped.
//
#define RMS_MESSAGE_NTMS_FAILURE         ((HRESULT)0x81010FB1L)

//
// MessageId: RMS_MESSAGE_NTMS_FAULT
//
// MessageText:
//
//  Removable Storage Management (RSM) cannot complete operation: <%1>. %2%3
//
#define RMS_MESSAGE_NTMS_FAULT           ((HRESULT)0x81010FB2L)

//
// MessageId: RMS_MESSAGE_NTMS_UNKNOWN_FAULT
//
// MessageText:
//
//  Removable Storage Management (RSM) cannot complete operation: <%1>. Unexpected result: %2
//
#define RMS_MESSAGE_NTMS_UNKNOWN_FAULT   ((HRESULT)0x81010FB3L)

//
// MessageId: RMS_MESSAGE_DRIVE_NOT_AVAILABLE
//
// MessageText:
//
//  Media <%1/%2> cannot be mounted into a drive. This might indicate that one of the drives needs cleaning.
//
#define RMS_MESSAGE_DRIVE_NOT_AVAILABLE  ((HRESULT)0x81010FB4L)

//
// MessageId: RMS_MESSAGE_OFFLINE_MEDIA_REQUEST
//
// MessageText:
//
//  Media <%1/%2> is offline.  Please inject the offline media into the library or drive and then repeat the operation.
//
#define RMS_MESSAGE_OFFLINE_MEDIA_REQUEST ((HRESULT)0x81010FB5L)

//
// MessageId: RMS_MESSAGE_SCRATCH_MOUNT_RETRY
//
// MessageText:
//
//  Scratch mount operation for <%1> cannot complete. %2  Remote Storage will attempt this operation on a different cartridge.
//
#define RMS_MESSAGE_SCRATCH_MOUNT_RETRY  ((HRESULT)0x81010FB6L)

//
// MessageId: RMS_MESSAGE_EXPECTED_MOUNT_FAILED
//
// MessageText:
//
//  Media <%1/%2> cannot be mounted into a drive. %3
//
#define RMS_MESSAGE_EXPECTED_MOUNT_FAILED ((HRESULT)0x01010FB7L)

//
// MessageId: RMS_MESSAGE_EXPECTED_SCRATCH_MOUNT_FAILED
//
// MessageText:
//
//  Scratch mount operation for <%1> cannot complete. %2
//
#define RMS_MESSAGE_EXPECTED_SCRATCH_MOUNT_FAILED ((HRESULT)0x01010FB8L)

//
// MessageId: RMS_MESSAGE_EJECT_BAD_MEDIA_REQUEST
//
// MessageText:
//
//  Media <%1> in slot <%2> failed to format. The media may be damaged. Please eject the media out of the library. 
//  If the problem continues with another media, the drive or the library may be damaged.
//
#define RMS_MESSAGE_EJECT_BAD_MEDIA_REQUEST ((HRESULT)0x81010FB9L)

//
// MessageId: RMS_MESSAGE_FORMAT_BAD_MEDIA
//
// MessageText:
//
//  Media <%1> failed to format. The media may be damaged. RSS has disabled the media and posted a request to eject the media out of the library. 
//  If the problem continues with another media, the drive or the library may be damaged. The system log may contain more information on such a device error.
//
#define RMS_MESSAGE_FORMAT_BAD_MEDIA     ((HRESULT)0x81010FBAL)

//
// MessageId: RMS_MESSAGE_FORMAT_BAD_SECOND_SIDE_MEDIA
//
// MessageText:
//
//  The second side of media <%1> failed to format. If the problem continues, The target media may be damaged.
//  If the target is a master media, you may need to recreate the master from a media copy, or eject the media and set the write protect tab to avoid writing more data to the media. 
//  If the target is a media copy, you can delete the copy using Remote Storage media property page, then eject and dispose the media.
//
#define RMS_MESSAGE_FORMAT_BAD_SECOND_SIDE_MEDIA ((HRESULT)0x81010FBBL)

//
// MessageId: RMS_MESSAGE_LAST
//
// MessageText:
//
//  Define for last Rms event.
//
#define RMS_MESSAGE_LAST                 ((HRESULT)0x01010FBCL)

//
// -----------------------------  MOVER ERROR CODES  ------------------------------
//
//
// MessageId: MVR_E_FIRST
//
// MessageText:
//
//  Define for first MVR Error.
//
#define MVR_E_FIRST                      ((HRESULT)0x810B0000L)

//
// MessageId: MVR_E_NOT_FOUND
//
// MessageText:
//
//  Object not found.
//
#define MVR_E_NOT_FOUND                  ((HRESULT)0x810B0001L)

//
// MessageId: MVR_E_RESOURCE_BUSY
//
// MessageText:
//
//  Resource required to complete the operation is busy.
//
#define MVR_E_RESOURCE_BUSY              ((HRESULT)0x810B0002L)

//
// MessageId: MVR_E_RESOURCE_UNAVAILABLE
//
// MessageText:
//
//  Resource required to complete the operation is not available.
//
#define MVR_E_RESOURCE_UNAVAILABLE       ((HRESULT)0x810B0003L)

//
// MessageId: MVR_E_ACCESS_DENIED
//
// MessageText:
//
//  Access to the object is denied.
//
#define MVR_E_ACCESS_DENIED              ((HRESULT)0x810B0004L)

//
// MessageId: MVR_E_INVALIDARG
//
// MessageText:
//
//  One or more parameters are incorrect.
//
#define MVR_E_INVALIDARG                 ((HRESULT)0x810B0005L)

//
// MessageId: MVR_E_CANCELED
//
// MessageText:
//
//  Operator cancelled the operation.
//
#define MVR_E_CANCELED                   ((HRESULT)0x810B0006L)

//
// MessageId: MVR_E_TIMEOUT
//
// MessageText:
//
//  Operation timed out before completing.
//
#define MVR_E_TIMEOUT                    ((HRESULT)0x810B0007L)

//
// MessageId: MVR_E_LOGIC_ERROR
//
// MessageText:
//
//  Logic error occurred in the Remote Storage data mover code.
//
#define MVR_E_LOGIC_ERROR                ((HRESULT)0x810B0008L)

//
// MessageId: MVR_E_OVERWRITE_NOT_ALLOWED
//
// MessageText:
//
//  Data overwrite is not allowed.
//
#define MVR_E_OVERWRITE_NOT_ALLOWED      ((HRESULT)0x810B0009L)

//
// MessageId: MVR_E_INCONSISTENT_MEDIA_LAYOUT
//
// MessageText:
//
//  Media layout is inconsistent.
//
#define MVR_E_INCONSISTENT_MEDIA_LAYOUT  ((HRESULT)0x810B000AL)

//
// MessageId: MVR_E_DATA_SET_MISSING
//
// MessageText:
//
//  Previous or expected data set is missing.  This is normally a non-fatal error that usually occurs when the previous data set was created, but then the operation was interrupted by a device error, power outage, or bus-rest.  The operation will be retried automatically by Remote Storage.
//
#define MVR_E_DATA_SET_MISSING           ((HRESULT)0x810B000BL)

//
// MessageId: MVR_E_UNKNOWN_MEDIA
//
// MessageText:
//
//  Media is unknown to Remote Storage.
//
#define MVR_E_UNKNOWN_MEDIA              ((HRESULT)0x810B000CL)

//
// MessageId: MVR_E_UNEXPECTED_MEDIA_ID_DETECTED
//
// MessageText:
//
//  On-media Id is different than what is expected. The wrong unit of media may have been placed into the drive.
//
#define MVR_E_UNEXPECTED_MEDIA_ID_DETECTED ((HRESULT)0x810B000DL)

//
// MessageId: MVR_E_CANT_CALC_DATASTREAM_CRC
//
// MessageText:
//
//  Calculation of the CRC for the unnamed datastream encountered an error. Data transfer aborted.
//
#define MVR_E_CANT_CALC_DATASTREAM_CRC   ((HRESULT)0x810B000EL)

//
// MessageId: MVR_E_UNEXPECTED_DATA
//
// MessageText:
//
//  Data read is different than what is expected. Data transfer aborted.
//
#define MVR_E_UNEXPECTED_DATA            ((HRESULT)0x810B000FL)

//
// MessageId: MVR_E_MAX_RETRY_ATTEMPTS_EXCEEDED
//
// MessageText:
//
//  Maximum retry attempts was exceeded.
//
#define MVR_E_MAX_RETRY_ATTEMPTS_EXCEEDED ((HRESULT)0x810B0010L)

//
// ---------------------------- MOVER DEVICE ERRORS  ------------------------------
//
//
// MessageId: MVR_E_BEGINNING_OF_MEDIA
//
// MessageText:
//
//  Beginning of the tape or a partition was encountered.
//
#define MVR_E_BEGINNING_OF_MEDIA         ((HRESULT)0x810B0011L)

//
// MessageId: MVR_E_BUS_RESET
//
// MessageText:
//
//  I/O bus was reset.
//
#define MVR_E_BUS_RESET                  ((HRESULT)0x810B0012L)

//
// MessageId: MVR_E_END_OF_MEDIA
//
// MessageText:
//
//  Physical end of the media has been reached.
//
#define MVR_E_END_OF_MEDIA               ((HRESULT)0x810B0013L)

//
// MessageId: MVR_S_FILEMARK_DETECTED
//
// MessageText:
//
//  Tape access reached a filemark.
//
#define MVR_S_FILEMARK_DETECTED          ((HRESULT)0x010B0014L)

//
// MessageId: MVR_S_SETMARK_DETECTED
//
// MessageText:
//
//  Tape access reached the end of a set of files.
//
#define MVR_S_SETMARK_DETECTED           ((HRESULT)0x010B0015L)

//
// MessageId: MVR_S_NO_DATA_DETECTED
//
// MessageText:
//
//  Unexpected end of data detected.
//
#define MVR_S_NO_DATA_DETECTED           ((HRESULT)0x010B0016L)

//
// MessageId: MVR_E_PARTITION_FAILURE
//
// MessageText:
//
//  Remote Storage is unable to partition the tape.
//
#define MVR_E_PARTITION_FAILURE          ((HRESULT)0x810B0017L)

//
// MessageId: MVR_E_INVALID_BLOCK_LENGTH
//
// MessageText:
//
//  Current blocksize is incorrect.
//
#define MVR_E_INVALID_BLOCK_LENGTH       ((HRESULT)0x810B0018L)

//
// MessageId: MVR_E_DEVICE_NOT_PARTITIONED
//
// MessageText:
//
//  Tape partition information cannot be found when loading a tape.
//
#define MVR_E_DEVICE_NOT_PARTITIONED     ((HRESULT)0x810B0019L)

//
// MessageId: MVR_E_MEDIA_CHANGED
//
// MessageText:
//
//  Media in the drive may have changed.
//
#define MVR_E_MEDIA_CHANGED              ((HRESULT)0x810B001AL)

//
// MessageId: MVR_E_NO_MEDIA_IN_DRIVE
//
// MessageText:
//
//  No media is in the drive.
//
#define MVR_E_NO_MEDIA_IN_DRIVE          ((HRESULT)0x810B001BL)

//
// MessageId: MVR_E_UNABLE_TO_LOCK_MEDIA
//
// MessageText:
//
//  Remote Storage is unable to lock the media eject mechanism.
//
#define MVR_E_UNABLE_TO_LOCK_MEDIA       ((HRESULT)0x810B001CL)

//
// MessageId: MVR_E_UNABLE_TO_UNLOAD_MEDIA
//
// MessageText:
//
//  Remote Storage is unable to unload the media.
//
#define MVR_E_UNABLE_TO_UNLOAD_MEDIA     ((HRESULT)0x810B001DL)

//
// MessageId: MVR_E_WRITE_PROTECT
//
// MessageText:
//
//  The device is reporting that the target media is write protected.  You may need to check the write protect tab on the cartridge, and retry the operation.
//
#define MVR_E_WRITE_PROTECT              ((HRESULT)0x810B001EL)

//
// MessageId: MVR_E_CRC
//
// MessageText:
//
//  Data error (bad CRC). The target drive might need cleaning. The system log may contain more information about the device error. If this problem continues, the target media might be damaged. 
//  If the target is the master media, you may need to recreate the master from a media copy, or eject the media and set the write protect tab to avoid writing more data to the media.
//  If the target is a media copy, you can delete the media using Remote Storage media property page, then eject and dispose the media.
//
#define MVR_E_CRC                        ((HRESULT)0x810B001FL)

//
// MessageId: MVR_E_DEVICE_REQUIRES_CLEANING
//
// MessageText:
//
//  Device has indicated that cleaning is required before further operations are attempted.  If this problem continues, the media might be damaged.  You may need to recreate the master media from a media copy.  You may also set the write protect tab on the physical media to avoid writing more data to the media.
//
#define MVR_E_DEVICE_REQUIRES_CLEANING   ((HRESULT)0x810B0020L)

//
// MessageId: MVR_E_SHARING_VIOLATION
//
// MessageText:
//
//  Process cannot access the file because it is being used by another process.
//
#define MVR_E_SHARING_VIOLATION          ((HRESULT)0x810B0021L)

//
// MessageId: MVR_E_ERROR_IO_DEVICE
//
// MessageText:
//
//  Request cannot be performed because of an I/O device error.  This might indicate that cleaning is required before further operations are attempted.  If this problem continues, the media might be damaged.  You may need to recreate the master media from a media copy.  You may also set the write protect tab on the physical media to avoid writing more data to the media.
//
#define MVR_E_ERROR_IO_DEVICE            ((HRESULT)0x810B0022L)

//
// MessageId: MVR_E_ERROR_DEVICE_NOT_CONNECTED
//
// MessageText:
//
//  Device is not connected.
//
#define MVR_E_ERROR_DEVICE_NOT_CONNECTED ((HRESULT)0x810B0023L)

//
// MessageId: MVR_E_ERROR_NOT_READY
//
// MessageText:
//
//  Device is not ready.
//
#define MVR_E_ERROR_NOT_READY            ((HRESULT)0x810B0024L)

//
// MessageId: MVR_E_DISK_FULL
//
// MessageText:
//
//  Insufficient disk space to complete the operation.
//
#define MVR_E_DISK_FULL                  ((HRESULT)0x810B0025L)

//
// MessageId: MVR_E_UNRECOGNIZED_VOLUME
//
// MessageText:
//
//  The volume does not contain a recognized file system.
//
#define MVR_E_UNRECOGNIZED_VOLUME        ((HRESULT)0x810B0026L)

//
// MessageId: MVR_E_MEDIA_ABORT
//
// MessageText:
//
//  Operation aborted due to a bad media.
//
#define MVR_E_MEDIA_ABORT                ((HRESULT)0x810B0027L)

//
// MessageId: MVR_E_LAST
//
// MessageText:
//
//  Define for last MVR Error.
//
#define MVR_E_LAST                       ((HRESULT)0x810B0028L)

//
// ------------------------------- MOVER EVENTS  ------------------------------
//
//
// MessageId: MVR_MESSAGE_FIRST
//
// MessageText:
//
//  Define for first Mover event.
//
#define MVR_MESSAGE_FIRST                ((HRESULT)0x010B1388L)

//
// MessageId: MVR_MESSAGE_DEVICE_ERROR
//
// MessageText:
//
//  Remote Storage encountered an error while accessing the device for <%1>.  %2  Check the System Log for more information.
//
#define MVR_MESSAGE_DEVICE_ERROR         ((HRESULT)0x010B1389L)

//
// MessageId: MVR_MESSAGE_RECOVERABLE_DEVICE_ERROR_DETECTED
//
// MessageText:
//
//  Remote Storage is attempting to retry the operation.
//
#define MVR_MESSAGE_RECOVERABLE_DEVICE_ERROR_DETECTED ((HRESULT)0x010B138AL)

//
// MessageId: MVR_MESSAGE_RECOVERABLE_DEVICE_ERROR_RECOVERED
//
// MessageText:
//
//  Remote Storage successfully recovered from the device error.
//
#define MVR_MESSAGE_RECOVERABLE_DEVICE_ERROR_RECOVERED ((HRESULT)0x410B138BL)

//
// MessageId: MVR_MESSAGE_UNRECOVERABLE_DEVICE_ERROR
//
// MessageText:
//
//  Remote Storage cannot recover from the device error.  %1
//
#define MVR_MESSAGE_UNRECOVERABLE_DEVICE_ERROR ((HRESULT)0x810B138CL)

//
// MessageId: MVR_MESSAGE_INCOMPLETE_DATA_SET_DETECTED
//
// MessageText:
//
//  Incomplete Remote Storage data set <%1> was detected on media <%2/%3>.  Automatic data set recovery is in progress.
//
#define MVR_MESSAGE_INCOMPLETE_DATA_SET_DETECTED ((HRESULT)0x410B138DL)

//
// MessageId: MVR_MESSAGE_DATA_SET_RECOVERED
//
// MessageText:
//
//  Automatic data set recovery completed successfully.
//
#define MVR_MESSAGE_DATA_SET_RECOVERED   ((HRESULT)0x410B138EL)

//
// MessageId: MVR_MESSAGE_DATA_SET_NOT_RECOVERABLE
//
// MessageText:
//
//  Target data set is not recoverable.  %1
//
#define MVR_MESSAGE_DATA_SET_NOT_RECOVERABLE ((HRESULT)0x810B138FL)

//
// MessageId: MVR_MESSAGE_DATA_SET_NOT_CREATED
//
// MessageText:
//
//  Remote Storage cannot create a new data set.  %1
//
#define MVR_MESSAGE_DATA_SET_NOT_CREATED ((HRESULT)0x810B1390L)

//
// MessageId: MVR_MESSAGE_DATA_TRANSFER_ERROR
//
// MessageText:
//
//  The file <%1> cannot be copied to Remote Storage media.  %2
//
#define MVR_MESSAGE_DATA_TRANSFER_ERROR  ((HRESULT)0x010B1391L)

//
// MessageId: MVR_MESSAGE_UNEXPECTED_DATA
//
// MessageText:
//
//  Unexpected data <%1> read from <%2/%3> at location %4, offset %5, mark %6. Contact product support.
//
#define MVR_MESSAGE_UNEXPECTED_DATA      ((HRESULT)0xC10B1392L)

//
// MessageId: MVR_MESSAGE_ON_MEDIA_ID_VERIFY_FAILED
//
// MessageText:
//
//  On-media label for media <%1/%2> cannot be verified.  %3
//
#define MVR_MESSAGE_ON_MEDIA_ID_VERIFY_FAILED ((HRESULT)0xC10B1393L)

//
// MessageId: MVR_MESSAGE_UNEXPECTED_DATA_SET_LOCATION_DETECTED
//
// MessageText:
//
//  Remote Storage attempted to write information to a data set at location <%1>, but the file was unexpectedly found at location <%2>. Automatic data set recovery is in progress.
//
#define MVR_MESSAGE_UNEXPECTED_DATA_SET_LOCATION_DETECTED ((HRESULT)0x810B1394L)

//
// MessageId: MVR_MESSAGE_MEDIA_NOT_VALID
//
// MessageText:
//
//  The media cannot be verified for %1.  %2
//
#define MVR_MESSAGE_MEDIA_NOT_VALID      ((HRESULT)0x810B1395L)

//
// MessageId: MVR_MESSAGE_MEDIA_FORMAT_FAILED
//
// MessageText:
//
//  Failed to format to NTFS the media %3 that was mounted to %1 .  %2
//
#define MVR_MESSAGE_MEDIA_FORMAT_FAILED  ((HRESULT)0xC10B1396L)

//
// MessageId: MVR_MESSAGE_DATA_SET_FILE_ERROR
//
// MessageText:
//
//  Remote Storage encountered an error while trying to create the data set file %1 .  %2
//
#define MVR_MESSAGE_DATA_SET_FILE_ERROR  ((HRESULT)0xC10B1397L)

//
// MessageId: MVR_MESSAGE_FILTER_DATA_SEND_ERROR
//
// MessageText:
//
//  Remote Storage encountered an error while sending data to the file system driver. The recall operation has been aborted.  %1
//
#define MVR_MESSAGE_FILTER_DATA_SEND_ERROR ((HRESULT)0xC10B1398L)

//
// MessageId: MVR_MESSAGE_UNKNOWN_DEVICE_ERROR
//
// MessageText:
//
//  Remote Storage encountered an unknown error while accessing the device for %1.  %2  Check the System Log for more information.
//
#define MVR_MESSAGE_UNKNOWN_DEVICE_ERROR ((HRESULT)0xC10B176FL)

//
// MessageId: MVR_MESSAGE_LAST
//
// MessageText:
//
//  Define for last Mover event.
//
#define MVR_MESSAGE_LAST                 ((HRESULT)0x010B1770L)

//
// ------------------------------ JOB ERROR CODES  ------------------------------
//
//
// MessageId: JOB_E_FIRST
//
// MessageText:
//
//  Define for first Job Error.
//
#define JOB_E_FIRST                      ((HRESULT)0x81040000L)

//
// MessageId: JOB_E_ALREADYACTIVE
//
// MessageText:
//
//  An attempt was made to start or restart a job that is already active.
//
#define JOB_E_ALREADYACTIVE              ((HRESULT)0x81040001L)

//
// MessageId: JOB_E_NOTMANAGINGHSM
//
// MessageText:
//
//  An attempt was made to start or restart a job that is not owned by the Remote Storage that manages the resource.
//
#define JOB_E_NOTMANAGINGHSM             ((HRESULT)0x81040002L)

//
// MessageId: JOB_E_DIREXCLUDED
//
// MessageText:
//
//  Specified directory was not scanned because the rules indicated that it and all of its subdirectories have been excluded.
//
#define JOB_E_DIREXCLUDED                ((HRESULT)0x81040003L)

//
// MessageId: JOB_E_FILEEXCLUDED
//
// MessageText:
//
//  Specified file was not processed because the rules indicate that it has been excluded.
//
#define JOB_E_FILEEXCLUDED               ((HRESULT)0x81040004L)

//
// MessageId: JOB_E_DOESNTMATCH
//
// MessageText:
//
//  File does not match any of the include or exclude rules defined for the job.
//
#define JOB_E_DOESNTMATCH                ((HRESULT)0x81040005L)

//
// MessageId: JOB_E_LAST
//
// MessageText:
//
//  Define for last Job Error.
//
#define JOB_E_LAST                       ((HRESULT)0x81040006L)

//
// -------------------------------  JOB EVENTS  ------------------------------
//
//
// MessageId: JOB_MESSAGE_FIRST
//
// MessageText:
//
//  Define for first Job event.
//
#define JOB_MESSAGE_FIRST                ((HRESULT)0x41041770L)

//
// MessageId: JOB_MESSAGE_JOB_CANCELLING
//
// MessageText:
//
//  Job <%1> is being cancelled.
//
#define JOB_MESSAGE_JOB_CANCELLING       ((HRESULT)0x01041771L)

//
// MessageId: JOB_MESSAGE_JOB_COMPLETED
//
// MessageText:
//
//  Job <%1> has completed.
//
#define JOB_MESSAGE_JOB_COMPLETED        ((HRESULT)0x01041772L)

//
// MessageId: JOB_MESSAGE_JOB_PAUSING
//
// MessageText:
//
//  Job <%1> is being paused.
//
#define JOB_MESSAGE_JOB_PAUSING          ((HRESULT)0x01041773L)

//
// MessageId: JOB_MESSAGE_JOB_RESTARTING
//
// MessageText:
//
//  Job <%1> is being restarted.
//
#define JOB_MESSAGE_JOB_RESTARTING       ((HRESULT)0x01041774L)

//
// MessageId: JOB_MESSAGE_JOB_RESUMING
//
// MessageText:
//
//  Job <%1> is being resumed.
//
#define JOB_MESSAGE_JOB_RESUMING         ((HRESULT)0x01041775L)

//
// MessageId: JOB_MESSAGE_JOB_STARTING
//
// MessageText:
//
//  Job <%1> is being started.
//
#define JOB_MESSAGE_JOB_STARTING         ((HRESULT)0x01041776L)

//
// MessageId: JOB_MESSAGE_JOB_SUSPENDING
//
// MessageText:
//
//  Job <%1> is being suspended because the volume it needs is in use by another job or the number of jobs currently running is the maximum allowed.
//
#define JOB_MESSAGE_JOB_SUSPENDING       ((HRESULT)0x01041777L)

//
// MessageId: JOB_MESSAGE_SESSION_ACTIVE
//
// MessageText:
//
//  %2 for <%1> on %3 is active.
//
#define JOB_MESSAGE_SESSION_ACTIVE       ((HRESULT)0x01041778L)

//
// MessageId: JOB_MESSAGE_SESSION_CANCELLED
//
// MessageText:
//
//  %2 for <%1> on %3 was cancelled: succeeded on %4 files (%5 bytes), skipped %6 files (%7 bytes), and failed on %8 files (%9 bytes) in %10 for a throughput of %11 files/sec (%12 bytes/sec).
//
#define JOB_MESSAGE_SESSION_CANCELLED    ((HRESULT)0x41041779L)

//
// MessageId: JOB_MESSAGE_SESSION_CANCELLING
//
// MessageText:
//
//  %2 for <%1> on %3 is being cancelled.
//
#define JOB_MESSAGE_SESSION_CANCELLING   ((HRESULT)0x0104177AL)

//
// MessageId: JOB_MESSAGE_SESSION_DONE
//
// MessageText:
//
//  %2 for <%1> on %3 is done: succeeded on %4 files (%5 bytes), skipped %6 files (%7 bytes), and failed on %8 files (%9 bytes) in %10 for a throughput of %11 files/sec (%12 bytes/sec).
//
#define JOB_MESSAGE_SESSION_DONE         ((HRESULT)0x4104177BL)

//
// MessageId: JOB_MESSAGE_SESSION_FAILED
//
// MessageText:
//
//  %2 for <%1> on %3 has failed: succeeded on %4 files (%5 bytes), skipped %6 files (%7 bytes), and failed on %8 files (%9 bytes) in %10 for a throughput of %11 files/sec (%12 bytes/sec).
//
#define JOB_MESSAGE_SESSION_FAILED       ((HRESULT)0x8104177CL)

//
// MessageId: JOB_MESSAGE_SESSION_IDLE
//
// MessageText:
//
//  %2 for <%1> on %3 is idle.
//
#define JOB_MESSAGE_SESSION_IDLE         ((HRESULT)0x0104177DL)

//
// MessageId: JOB_MESSAGE_SESSION_PAUSING
//
// MessageText:
//
//  %2 for <%1> on %3 is pausing.
//
#define JOB_MESSAGE_SESSION_PAUSING      ((HRESULT)0x0104177EL)

//
// MessageId: JOB_MESSAGE_SESSION_PAUSED
//
// MessageText:
//
//  %2 for <%1> on %3 was paused: succeeded on %4 files (%5 bytes), skipped %6 files (%7 bytes), and failed on %8 files (%9 bytes) in %10 for a throughput of %11 files/sec (%12 bytes/sec).
//
#define JOB_MESSAGE_SESSION_PAUSED       ((HRESULT)0x0104177FL)

//
// MessageId: JOB_MESSAGE_SESSION_RESUMING
//
// MessageText:
//
//  %2 for <%1> on %3 is resuming.
//
#define JOB_MESSAGE_SESSION_RESUMING     ((HRESULT)0x01041780L)

//
// MessageId: JOB_MESSAGE_SESSION_SKIPPED
//
// MessageText:
//
//  %2 for <%1> on %3 was skipped.
//
#define JOB_MESSAGE_SESSION_SKIPPED      ((HRESULT)0x81041781L)

//
// MessageId: JOB_MESSAGE_SESSION_STARTING
//
// MessageText:
//
//  %2 for <%1> on %3 is starting.
//
#define JOB_MESSAGE_SESSION_STARTING     ((HRESULT)0x01041782L)

//
// MessageId: JOB_MESSAGE_SESSION_SUSPENDED
//
// MessageText:
//
//  %2 for <%1> on %3 was suspended: succeeded on %4 files (%5 bytes), skipped %6 files (%7 bytes), and failed on %8 files (%9 bytes) in %10 for a throughput of %11 files/sec (%12 bytes/sec).
//
#define JOB_MESSAGE_SESSION_SUSPENDED    ((HRESULT)0x01041783L)

//
// MessageId: JOB_MESSAGE_SESSION_SUSPENDING
//
// MessageText:
//
//  %2 for <%1> on %3 is being suspended.
//
#define JOB_MESSAGE_SESSION_SUSPENDING   ((HRESULT)0x01041784L)

//
// MessageId: JOB_MESSAGE_SESSION_ERROR
//
// MessageText:
//
//  An error was detected doing %2 for <%1> on %3. %4
//
#define JOB_MESSAGE_SESSION_ERROR        ((HRESULT)0xC1041785L)

//
// MessageId: JOB_MESSAGE_SESSION_INTERNALERROR
//
// MessageText:
//
//  An error was detected doing %2 for <%1> on %3 in file <%4> line %5. %6
//
#define JOB_MESSAGE_SESSION_INTERNALERROR ((HRESULT)0xC1041786L)

//
// MessageId: JOB_MESSAGE_SESSION_ITEM_SKIPPED
//
// MessageText:
//
//  Error during %2 for <%1> of %4 on %3. %5
//
#define JOB_MESSAGE_SESSION_ITEM_SKIPPED ((HRESULT)0x01041787L)

//
// MessageId: JOB_MESSAGE_SCAN_FILESKIPPED_NORULE
//
// MessageText:
//
//  The file <%2> for job <%1> was not managed because it does not match an inclusion rule.
//
#define JOB_MESSAGE_SCAN_FILESKIPPED_NORULE ((HRESULT)0x01041788L)

//
// MessageId: JOB_MESSAGE_JOB_FAILED_NOTMANAGINGHSM
//
// MessageText:
//
//  The job <%1> has failed because it does not own the resource <%2> that it is trying to manage.
//
#define JOB_MESSAGE_JOB_FAILED_NOTMANAGINGHSM ((HRESULT)0x81041789L)

//
// MessageId: JOB_MESSAGE_JOB_FAILED
//
// MessageText:
//
//  The job <%1> has failed for resource <%2>.
//
#define JOB_MESSAGE_JOB_FAILED           ((HRESULT)0x8104178AL)

//
// MessageId: JOB_MESSAGE_JOB_ALREADYACTIVE
//
// MessageText:
//
//  An attempt was made to start or restart the job <%1> that is already active.
//
#define JOB_MESSAGE_JOB_ALREADYACTIVE    ((HRESULT)0x8104178BL)

//
// MessageId: JOB_MESSAGE_RESOURCE_INACTIVE
//
// MessageText:
//
//  <%1> is being skipped by job <%2> because it is inactive.
//
#define JOB_MESSAGE_RESOURCE_INACTIVE    ((HRESULT)0x0104178CL)

//
// MessageId: JOB_MESSAGE_RESOURCE_UNAVAILABLE
//
// MessageText:
//
//  <%1> is being skipped by job <%2> because it is unavailable.
//
#define JOB_MESSAGE_RESOURCE_UNAVAILABLE ((HRESULT)0x8104178DL)

//
// MessageId: JOB_MESSAGE_RESOURCE_NEEDS_REPAIR
//
// MessageText:
//
//  <%1> is being skipped by job <%2> because it needs to be repaired.
//
#define JOB_MESSAGE_RESOURCE_NEEDS_REPAIR ((HRESULT)0x8104178EL)

//
// MessageId: JOB_MESSAGE_UNMANAGE_PRESCAN_FAILED
//
// MessageText:
//
//  Pre-scan for creating temporary database for Remove Volume job for <%1> failed. %2  Remove Volume job cannot continue.
//
#define JOB_MESSAGE_UNMANAGE_PRESCAN_FAILED ((HRESULT)0x8104178FL)

//
// MessageId: JOB_MESSAGE_LAST
//
// MessageText:
//
//  Define for last Job event.
//
#define JOB_MESSAGE_LAST                 ((HRESULT)0x01041790L)

//
// ------------------------------ LNK SERVICE EVENTS ------------------------------
//
//
// MessageId: LNK_MESSAGE_SERVICE_STARTED
//
// MessageText:
//
//  Service started.
//
#define LNK_MESSAGE_SERVICE_STARTED      ((HRESULT)0x410E03E8L)

//
// MessageId: LNK_MESSAGE_SERVICE_EXITING
//
// MessageText:
//
//  Service exiting.
//
#define LNK_MESSAGE_SERVICE_EXITING      ((HRESULT)0x410E03E9L)

//
// MessageId: LNK_MESSAGE_SERVICE_STOPPED
//
// MessageText:
//
//  Service stopped.
//
#define LNK_MESSAGE_SERVICE_STOPPED      ((HRESULT)0x010E03EAL)

//
// MessageId: LNK_MESSAGE_SERVICE_HANDLER_NOT_INSTALLED
//
// MessageText:
//
//  Handler not installed.
//
#define LNK_MESSAGE_SERVICE_HANDLER_NOT_INSTALLED ((HRESULT)0xC10E03EBL)

//
// MessageId: LNK_MESSAGE_SERVICE_RECEIVED_BAD_REQUEST
//
// MessageText:
//
//  Bad service request %1
//
#define LNK_MESSAGE_SERVICE_RECEIVED_BAD_REQUEST ((HRESULT)0xC10E03ECL)

//
// MessageId: LNK_MESSAGE_SERVICE_INITIALIZATION_FAILED
//
// MessageText:
//
//  Service initialization failed. %1
//
#define LNK_MESSAGE_SERVICE_INITIALIZATION_FAILED ((HRESULT)0xC10E03EDL)

//
// MessageId: LNK_MESSAGE_RECALL_NOTIFY_LIMIT_REACHED
//
// MessageText:
//
//  Remote Storage cannot issue further recall notifications due to an internal threshold being hit. Please restart the %1 service.%n
//  If this error repeats itself, a malicious user may be trying to use all server resources.%n
//  In order to identify the malicious user, open the Shared Folders console. The malicious user will maintain an open session and an open handle to a truncated file on the managed volume.
//
#define LNK_MESSAGE_RECALL_NOTIFY_LIMIT_REACHED ((HRESULT)0xC10E03EEL)

//
// MessageId: LNK_MESSAGE_CONCURRENT_NOTIFY_LIMIT_REACHED
//
// MessageText:
//
//  Remote Storage cannot issue further recall notifications due to an internal threshold being hit. Please restart the %1 service.%n
//  If this error repeats itself, a malicious user may be trying to use all server resources.%n
//  The malicious user process will be running on one or more of these machines: <%2>.
//
#define LNK_MESSAGE_CONCURRENT_NOTIFY_LIMIT_REACHED ((HRESULT)0xC10E03EFL)

#endif // _WSBERROR_
