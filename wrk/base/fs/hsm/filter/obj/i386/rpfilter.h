
// Copyright (C) Microsoft Corporation, 1996 - 1999

//File Name: Rpfilter.mc
//
//  Note: comments in the .mc file must use both ";" and "//".
//
//  Status values are 32 bit values layed out as follows:
//
//   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
//   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
//  +---+-+-------------------------+-------------------------------+
//  |Sev|C|       Facility          |               Code            |
//  +---+-+-------------------------+-------------------------------+
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
//      Facility - is the facility code
//
//      Code - is the facility's status code
//


//
// %1 is reserved by the IO Manager. If IoAllocateErrorLogEntry is
// called with a device, the name of the device will be inserted into
// the message at %1. Otherwise, the place of %1 will be left empty.
// In either case, the insertion strings from the driver's error log
// entry starts at %2. In other words, the first insertion string goes
// to %2, the second to %3 and so on.
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
#define STATUS_SEVERITY_WARNING          0x2
#define STATUS_SEVERITY_SUCCESS          0x0
#define STATUS_SEVERITY_INFORMATIONAL    0x1
#define STATUS_SEVERITY_ERROR            0x3


//
// MessageId: AV_MSG_MEMORY
//
// MessageText:
//
//  Error allocating memory.
//
#define AV_MSG_MEMORY                    ((NTSTATUS)0x80000001L)

//
// MessageId: AV_MSG_CODE_HIT
//
// MessageText:
//
//  This is to indicate a code path hit (%2).
//
#define AV_MSG_CODE_HIT                  ((NTSTATUS)0x40000002L)

//
// MessageId: AV_MSG_STARTUP
//
// MessageText:
//
//  Failed to initialize.
//
#define AV_MSG_STARTUP                   ((NTSTATUS)0xC0000003L)

//
// MessageId: AV_MSG_MOUNT_ERROR
//
// MessageText:
//
//  Failed to create a device during a file system mount.
//
#define AV_MSG_MOUNT_ERROR               ((NTSTATUS)0xC0000004L)

//
// MessageId: AV_MSG_REGISTER_ERROR
//
// MessageText:
//
//  Failed to create a device during a file system registration.
//
#define AV_MSG_REGISTER_ERROR            ((NTSTATUS)0xC0000005L)

//
// MessageId: AV_MSG_ATTACH_ERROR
//
// MessageText:
//
//  Failed to attach a device during a file system registration.
//
#define AV_MSG_ATTACH_ERROR              ((NTSTATUS)0xC0000006L)

//
// MessageId: AV_MSG_SYMBOLIC_LINK
//
// MessageText:
//
//  Failed to create a symbolic link.
//
#define AV_MSG_SYMBOLIC_LINK             ((NTSTATUS)0x80000007L)

//
// MessageId: AV_MSG_EXCEPTION
//
// MessageText:
//
//  Encountered an exception in %2.
//
#define AV_MSG_EXCEPTION                 ((NTSTATUS)0x80000008L)

//
// MessageId: AV_MSG_USER_ERROR
//
// MessageText:
//
//  Failed to get information for user notification.
//
#define AV_MSG_USER_ERROR                ((NTSTATUS)0x80000009L)

//
// MessageId: AV_MSG_FSA_ERROR
//
// MessageText:
//
//  The Remote Storage Server service is not running or cannot be contacted.
//
#define AV_MSG_FSA_ERROR                 ((NTSTATUS)0xC000000AL)

//
// MessageId: AV_MSG_PATH_ERROR
//
// MessageText:
//
//  Could not obtain the path of a migrated file.
//
#define AV_MSG_PATH_ERROR                ((NTSTATUS)0xC000000BL)

//
// MessageId: AV_MSG_DATA_ERROR
//
// MessageText:
//
//  Found a file in an inconsistent state.  Run a Remote Storage validation job to correct the problem. 
//
#define AV_MSG_DATA_ERROR                ((NTSTATUS)0xC000000CL)

//
// MessageId: AV_MSG_ATTACH_INIT_ERROR
//
// MessageText:
//
//  Failed to attach a device during a file system registration because the device is still initializing.
//
#define AV_MSG_ATTACH_INIT_ERROR         ((NTSTATUS)0xC000000DL)

//
// MessageId: AV_MSG_FSA_CLOSE_WARNING
//
// MessageText:
//
//  The Remote Storage Server service is not running or cannot be contacted.  Unable to log a migrated file event.
//
#define AV_MSG_FSA_CLOSE_WARNING         ((NTSTATUS)0x8000000EL)

//
// MessageId: AV_MSG_SERIAL
//
// MessageText:
//
//  Device object did not contain a volume parameter block - recall cannot complete.
//
#define AV_MSG_SERIAL                    ((NTSTATUS)0x8000000FL)

//
// MessageId: AV_MSG_REGISTER_WARNING
//
// MessageText:
//
//  Found another device attached to the NTFS file system.  Remote storage recalls may not work correctly in all cases.
//
#define AV_MSG_REGISTER_WARNING          ((NTSTATUS)0x80000010L)

//
// MessageId: AV_MSG_VALIDATE_WARNING
//
// MessageText:
//
//  Unable to inform the Remote Storage Server service to initiate an automatic validation job.  Run a Remote Storage validation job for each volume manually.
//
#define AV_MSG_VALIDATE_WARNING          ((NTSTATUS)0x80000011L)

//
// MessageId: AV_MSG_NO_BUFFER_LOCK
//
// MessageText:
//
//  Unable to lock the user buffer during a read operation.
//
#define AV_MSG_NO_BUFFER_LOCK            ((NTSTATUS)0xC0000012L)

//
// MessageId: AV_MSG_PRESERVE_DATE_FAILED
//
// MessageText:
//
//  Unable to preserve the last modified date when recalling a file.
//
#define AV_MSG_PRESERVE_DATE_FAILED      ((NTSTATUS)0xC0000013L)

//
// MessageId: AV_MSG_MARK_USN_FAILED
//
// MessageText:
//
//  Unable to mark the USN record when recalling a file.
//
#define AV_MSG_MARK_USN_FAILED           ((NTSTATUS)0xC0000014L)

//
// MessageId: AV_MSG_WRITE_REPARSE_FAILED
//
// MessageText:
//
//  Unable to write the reparse point on a recalled file.
//
#define AV_MSG_WRITE_REPARSE_FAILED      ((NTSTATUS)0xC0000015L)

//
// MessageId: AV_MSG_WRITE_FAILED
//
// MessageText:
//
//  Unable to write to a file being recalled.
//
#define AV_MSG_WRITE_FAILED              ((NTSTATUS)0xC0000016L)

//
// MessageId: AV_MSG_SET_SIZE_FAILED
//
// MessageText:
//
//  Unable to set the file size of a file being recalled.
//
#define AV_MSG_SET_SIZE_FAILED           ((NTSTATUS)0xC0000017L)

//
// MessageId: AV_MSG_UNEXPECTED_ERROR
//
// MessageText:
//
//  Encountered an unexpected error.
//
#define AV_MSG_UNEXPECTED_ERROR          ((NTSTATUS)0xC0000018L)

//
// MessageId: AV_MSG_DELETE_REPARSE_POINT_FAILED
//
// MessageText:
//
//  Could not delete the reparse point when file was modified
//
#define AV_MSG_DELETE_REPARSE_POINT_FAILED ((NTSTATUS)0x80000019L)

//
// MessageId: AV_MSG_RESET_FILE_ATTRIBUTE_OFFLINE_FAILED
//
// MessageText:
//
//  Could not reset FILE_ATTRIBUTE_OFFLINE after recalling the file %2. You have to manually reset this attribute on the file.  Till then, the file will be shown with a high latency overlay icon in Explorer (and with the size in parentheses when you do a 'dir' on it). Otherwise the file is still premigrated, and can be accessed normally. 
//
#define AV_MSG_RESET_FILE_ATTRIBUTE_OFFLINE_FAILED ((NTSTATUS)0xC000001AL)

//
// MessageId: AV_MSG_OUT_OF_FSA_REQUESTS
//
// MessageText:
//
//  Due to large number of simultaneous recalls, Remote Storage has run out of resources to communicate with user-mode recall engine. As a result, some of the accesses to files that are migrated by Remote Storage will fail until the number of recalls reduce.
//
#define AV_MSG_OUT_OF_FSA_REQUESTS       ((NTSTATUS)0x8000001BL)

//
// MessageId: AV_MSG_SET_PREMIGRATED_STATE_FAILED
//
// MessageText:
//
//  Could not set as premigrated (cached on disk) after recalling the file %2. Hence the file will be re-truncated and further i/o on the file will cause another recall.
//
#define AV_MSG_SET_PREMIGRATED_STATE_FAILED ((NTSTATUS)0xC000001CL)

//
// MessageId: AV_MSG_MULTIPLE_COMPLETION_ATTEMPTS
//
// MessageText:
//
//  Second or subsequent attempt to initiate recall completion processing on file %2 was ignored.
//
#define AV_MSG_MULTIPLE_COMPLETION_ATTEMPTS ((NTSTATUS)0x8000001DL)

