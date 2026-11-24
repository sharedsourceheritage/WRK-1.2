/*++

Copyright (c) 1993  Microsoft Corporation

Module Name:

    msg.mc

Abstract:

    This file contains the message definitions for event logging.

Author:

    Wesley Witt (wesw) 15-Feb-1999

Revision History:

Notes:

--*/

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
// MessageId: MSG_USAGE
//
// MessageText:
//
//  
//  Microsoft (R) Windows (R) File Checker Version 5.2
//  Copyright (c) Microsoft Corporation. All rights reserved.
//  
//  Scans all protected system files and replaces incorrect versions with correct Microsoft versions.
//  
//  SFC [/SCANNOW] [/SCANONCE] [/SCANBOOT] [/REVERT] [/PURGECACHE] [/CACHESIZE=x]
//  
//  
//  /SCANNOW        Scans all protected system files immediately.
//  /SCANONCE       Scans all protected system files once at the next boot.
//  /SCANBOOT       Scans all protected system files at every boot.
//  /REVERT         Return scan to default setting.
//  /PURGECACHE     Purges the file cache.
//  /CACHESIZE=x    Sets the file cache size.
//
#define MSG_USAGE                        0x40001001L

//
// MessageId: MSG_REBOOT
//
// MessageText:
//
//  
//  The changes to Windows File Protection settings do not take effect until the next restart.
//
#define MSG_REBOOT                       0x40001002L

//
// MessageId: MSG_SCAN_FAIL
//
// MessageText:
//
//  Windows File Protection could not initiate a scan of protected system files.
//  
//  The specific error code is %1!s!.
//
#define MSG_SCAN_FAIL                    0x40001003L

//
// MessageId: MSG_ADMIN
//
// MessageText:
//
//  You must be an administrator running a console session in order to use the Windows File Checker utility.
//
#define MSG_ADMIN                        0x40001004L

//
// MessageId: MSG_DELETE_FAIL
//
// MessageText:
//
//  Failed to delete %2!s!.  The specific error code is %1!s!.
//
#define MSG_DELETE_FAIL                  0x40001005L

//
// MessageId: MSG_PURGE_FAIL
//
// MessageText:
//
//  Windows File Protection could not purge the file cache.  
//  
//  The specific error code is %1!s!.
//
#define MSG_PURGE_FAIL                   0x40001006L

//
// MessageId: MSG_SET_FAIL
//
// MessageText:
//
//  Windows File Protection could not make the requested change.  
//  
//  The specific error code is %1!s!.
//
#define MSG_SET_FAIL                     0x40001007L

//
// MessageId: MSG_SUCCESS
//
// MessageText:
//
//  
//  Windows File Protection successfully made the requested change.
//
#define MSG_SUCCESS                      0x40001008L

