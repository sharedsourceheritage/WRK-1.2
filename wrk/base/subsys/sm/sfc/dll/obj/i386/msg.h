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



/* dll replacement messages */


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
// MessageId: MSG_DLL_CHANGE
//
// MessageText:
//
//  File replacement was attempted on the protected system file %1!s!.
//  This file was restored to the original version to maintain system stability.
//  The file version of the bad file is %2!s!.
//
#define MSG_DLL_CHANGE                   0x4000FA00L

//
// MessageId: MSG_DLL_CHANGE2
//
// MessageText:
//
//  File replacement was attempted on the protected system file %1!s!.
//  This file was restored to the original version to maintain system stability.
//  The file version of the bad file is %2!s!, the version of the system file is %3!s!.
//
#define MSG_DLL_CHANGE2                  0x4000FA01L

//
// MessageId: MSG_DLL_CHANGE3
//
// MessageText:
//
//  File replacement was attempted on the protected system file %1!s!.
//  This file was restored to the original version to maintain system stability.
//  The file version of the system file is %2!s!.
//
#define MSG_DLL_CHANGE3                  0x4000FA02L

//
// MessageId: MSG_DLL_CHANGE_NOVERSION
//
// MessageText:
//
//  File replacement was attempted on the protected system file %1!s!.
//  This file was restored to the original version to maintain system stability.
//  The file version of the bad file is unknown.
//
#define MSG_DLL_CHANGE_NOVERSION         0x4000FA03L

//
// MessageId: MSG_RESTORE_FAILURE
//
// MessageText:
//
//  The protected system file %1!s! could not be restored to its original, valid version.
//  The file version of the bad file is %2!s!
//  
//  The specific error code is %3!s!.
//
#define MSG_RESTORE_FAILURE              0x4000FA04L

//
// MessageId: MSG_COPY_CANCEL
//
// MessageText:
//
//  The protected system file %1!s! was not restored to its original, valid version
//  because the Windows File Protection restoration process was cancelled
//  by user interaction, user name is %2!s!.
//  
//  The file version of the bad file is %3!s!.
//
#define MSG_COPY_CANCEL                  0x4000FA05L

//
// MessageId: MSG_COPY_CANCEL_NOUI
//
// MessageText:
//
//  The protected system file %1!s! was not restored to its original, valid version
//  because the Windows File Protection restoration process was configured
//  to not bring up windows.  The currently logged on user was %2!s!.
//  
//  The file version of the bad file is %3!s!.
//
#define MSG_COPY_CANCEL_NOUI             0x4000FA06L

//
// MessageId: MSG_RESTORE_FAILURE_MAX_RETRIES
//
// MessageText:
//
//  The protected system file %1!s! could not be verified as valid because the file
//  was in use.
//  Use the SFC utility to verify the integrity of the file at a later time.
//
#define MSG_RESTORE_FAILURE_MAX_RETRIES  0x4000FA07L

//
// MessageId: MSG_DLL_NOVALIDATION_TERMINATION
//
// MessageText:
//
//  The protected system file %1!s! could not be verified as valid because Windows
//  File Protection is terminating.
//  Use the SFC utility to verify the integrity of the file at a later time.
//
#define MSG_DLL_NOVALIDATION_TERMINATION 0x4000FA08L



/* file scanning messages */


//
// MessageId: MSG_SCAN_STARTED
//
// MessageText:
//
//  Windows File Protection file scan was started.
//
#define MSG_SCAN_STARTED                 0x4000FA10L

//
// MessageId: MSG_SCAN_COMPLETED
//
// MessageText:
//
//  Windows File Protection file scan completed successfully.
//
#define MSG_SCAN_COMPLETED               0x4000FA11L

//
// MessageId: MSG_SCAN_CANCELLED
//
// MessageText:
//
//  Windows File Protection file scan was cancelled by user interaction, user name is %1!s!.
//
#define MSG_SCAN_CANCELLED               0x4000FA12L

//
// MessageId: MSG_SCAN_FOUND_BAD_FILE_NOVERSION
//
// MessageText:
//
//  Windows File Protection scan found that the system file %1!s! has a bad
//  signature. This file was restored to the original version to maintain system
//  stability.
//
#define MSG_SCAN_FOUND_BAD_FILE_NOVERSION 0x4000FA13L

//
// MessageId: MSG_SCAN_FOUND_BAD_FILE
//
// MessageText:
//
//  Windows File Protection scan found that the system file %1!s! has a bad
//  signature. This file was restored to the original version to maintain system
//  stability.  The file version of the system file is %2!s!.
//
#define MSG_SCAN_FOUND_BAD_FILE          0x4000FA14L

//
// MessageId: MSG_CACHE_COPY_ERROR
//
// MessageText:
//
//  The system file %1!s! could not be copied into the
//  DLL cache.  The specific error code is %2!s!.
//  
//  This file is necessary to maintain system stability.
//
#define MSG_CACHE_COPY_ERROR             0x4000FA15L



/* general WFP messages */


//
// MessageId: MSG_DISABLE
//
// MessageText:
//
//  Windows File Protection is not active on this system.
//
#define MSG_DISABLE                      0x4000FA20L

//
// MessageId: MSG_INITIALIZATION_FAILED
//
// MessageText:
//
//  Windows File Protection could not be initialized.
//  
//  The specific error code is %1!s!.
//
#define MSG_INITIALIZATION_FAILED        0x4000FA21L

//
// MessageId: MSG_DLLCACHE_INVALID
//
// MessageText:
//
//  Windows File Protection could not access the specified DLL cache directory.
//  
//  Windows File Protection has disabled DLL cache functionality.
//
#define MSG_DLLCACHE_INVALID             0x4000FA22L

//
// MessageId: MSG_CATALOG_RESTORE_FAILURE
//
// MessageText:
//
//  Windows File Protection could not restore the system catalog file %1!s!.  
//  This file is necessary to maintain system stability.
//  
//  The specific error code is %2!s!.
//
#define MSG_CATALOG_RESTORE_FAILURE      0x4000FA23L

//
// MessageId: MSG_SXS_INITIALIZATION_FAILED
//
// MessageText:
//
//  Windows File Protection was unable to start up SxS assembly protection.
//  
//  Assembly protection is now disabled.  The error code is %1!s!
//
#define MSG_SXS_INITIALIZATION_FAILED    0x4000FA24L

