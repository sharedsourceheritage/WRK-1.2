/*++

Copyright (c) 1991-2002  Microsoft Corporation

Module Name:

    vssevents.h

Abstract:

    This file contains the message definitions for the VSS Task resource

Author:

    Charlie Wickham (charlwi) 15-Aug-2002

Revision History:

Notes:

    This file is generated from vssevents.mc

--*/

#ifndef _VSSEVENTS_INCLUDED
#define _VSSEVENTS_INCLUDED


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
// MessageId: RES_VSSTASK_OPEN_FAILED
//
// MessageText:
//
//  The resource '%1' failed to be created.
//  %n%nThe associated error code is stored in the data section.%n
//
#define RES_VSSTASK_OPEN_FAILED          1001L

//
// MessageId: RES_VSSTASK_TERMINATE_TASK_FAILED
//
// MessageText:
//
//  The task associated with resource '%1' couldn't be stopped. You will need
//  to stop it manually.
//  %n%nThe associated error code is stored in the data section.%n
//
#define RES_VSSTASK_TERMINATE_TASK_FAILED 1002L

//
// MessageId: RES_VSSTASK_DELETE_TASK_FAILED
//
// MessageText:
//
//  The task associated with resource '%1' couldn't be deleted. You will need
//  to delete it manually by removing it from the Scheduled Tasks folder.
//  %n%nThe associated error code is stored in the data section.%n
//
#define RES_VSSTASK_DELETE_TASK_FAILED   1003L

//
// MessageId: RES_VSSTASK_ONLINE_FAILED
//
// MessageText:
//
//  The task associated with Cluster resource '%1' could not be added to
//  the Scheduled Tasks folder.
//  %n%nThe associated error code is stored in the data section.%n
//
#define RES_VSSTASK_ONLINE_FAILED        1004L

#endif // _VSSEVENTS_INCLUDED
