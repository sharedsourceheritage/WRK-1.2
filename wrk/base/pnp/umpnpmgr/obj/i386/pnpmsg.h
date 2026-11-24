/*++ BUILD Version: 0001    // Increment this if a change has global effects

Copyright (c) Microsoft Corporation.  All rights reserved.

Module Name:

    pnpmsg.mc

Abstract:

    Events which are logged by the PlugPlay Manager.

Author:

    Robert Nelson (robertn) 10-Jan-1999

Revision History:

--*/

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
// MessageId: ERR_CREATING_LOGON_EVENT
//
// MessageText:
//
//  Error creating logon event
//
#define ERR_CREATING_LOGON_EVENT         ((DWORD)0xC0000000L)

//
// MessageId: ERR_CREATING_INSTALL_EVENT
//
// MessageText:
//
//  Error creating install event
//
#define ERR_CREATING_INSTALL_EVENT       ((DWORD)0xC0000001L)

//
// MessageId: ERR_CREATING_PENDING_INSTALL_EVENT
//
// MessageText:
//
//  Error creating pending install event
//
#define ERR_CREATING_PENDING_INSTALL_EVENT ((DWORD)0xC0000002L)

//
// MessageId: ERR_CREATING_SETUP_PIPE
//
// MessageText:
//
//  Error creating setup pipe
//
#define ERR_CREATING_SETUP_PIPE          ((DWORD)0xC0000003L)

//
// MessageId: ERR_WRITING_SETUP_PIPE
//
// MessageText:
//
//  Error writing to setup pipe
//
#define ERR_WRITING_SETUP_PIPE           ((DWORD)0xC0000004L)

//
// MessageId: ERR_ALLOCATING_EVENT_BLOCK
//
// MessageText:
//
//  Error allocating event block
//
#define ERR_ALLOCATING_EVENT_BLOCK       ((DWORD)0xC0000005L)

//
// MessageId: ERR_ALLOCATING_NOTIFICATION_STRUCTURE
//
// MessageText:
//
//  Error allocating notification structure
//
#define ERR_ALLOCATING_NOTIFICATION_STRUCTURE ((DWORD)0xC0000006L)

//
// MessageId: ERR_ALLOCATING_BROADCAST_HANDLE
//
// MessageText:
//
//  Error allocating broadcast handle
//
#define ERR_ALLOCATING_BROADCAST_HANDLE  ((DWORD)0xC0000007L)

//
// MessageId: ERR_ALLOCATING_BROADCAST_INTERFACE
//
// MessageText:
//
//  Error allocating broadcast device interface
//
#define ERR_ALLOCATING_BROADCAST_INTERFACE ((DWORD)0xC0000008L)

//
// MessageId: ERR_WRITING_SURPRISE_REMOVE_PIPE
//
// MessageText:
//
//  Error writing to surprise removal pipe
//
#define ERR_WRITING_SURPRISE_REMOVE_PIPE ((DWORD)0xC0000009L)

//
// MessageId: ERR_WRITING_SERVER_INSTALL_PIPE
//
// MessageText:
//
//  Error writing to server side install pipe
//
#define ERR_WRITING_SERVER_INSTALL_PIPE  ((DWORD)0xC000000AL)

//
// MessageId: ERR_SURPRISE_REMOVAL_1
//
// MessageText:
//
//  The device %1 disappeared from the system without first being prepared for removal.
//
#define ERR_SURPRISE_REMOVAL_1           ((DWORD)0xC000000BL)

//
// MessageId: ERR_SURPRISE_REMOVAL_2
//
// MessageText:
//
//  The device '%1' (%2) disappeared from the system without first being prepared for removal.
//
#define ERR_SURPRISE_REMOVAL_2           ((DWORD)0xC000000CL)

//
// MessageId: ERR_PROCESSING_RUNONCE
//
// MessageText:
//
//  Error processing one or more RunOnce entries during server-side device installation.
//
#define ERR_PROCESSING_RUNONCE           ((DWORD)0xC000000DL)

//
// MessageId: WRN_INTERFACE_CHANGE_TIMED_OUT
//
// MessageText:
//
//  Timed out sending notification of device interface change to window of "%1"
//
#define WRN_INTERFACE_CHANGE_TIMED_OUT   ((DWORD)0x80000100L)

//
// MessageId: WRN_TARGET_DEVICE_CHANGE_TIMED_OUT
//
// MessageText:
//
//  Timed out sending notification of target device change to window of "%1"
//
#define WRN_TARGET_DEVICE_CHANGE_TIMED_OUT ((DWORD)0x80000101L)

//
// MessageId: WRN_PRIVATE_TARGET_DEVICE_CHANGE_TIMED_OUT
//
// MessageText:
//
//  Timed out sending private notification of target device change to window of "%1"
//
#define WRN_PRIVATE_TARGET_DEVICE_CHANGE_TIMED_OUT ((DWORD)0x80000102L)

//
// MessageId: WRN_CANCEL_NOTIFICATION_TIMED_OUT
//
// MessageText:
//
//  Timed out sending notification of target device change cancel to window of "%1"
//
#define WRN_CANCEL_NOTIFICATION_TIMED_OUT ((DWORD)0x80000103L)

//
// MessageId: WRN_TARGET_DEVICE_CHANGE_SERVICE_VETO
//
// MessageText:
//
//  The service "%1" vetoed a target device change request.
//
#define WRN_TARGET_DEVICE_CHANGE_SERVICE_VETO ((DWORD)0x80000104L)

//
// MessageId: WRN_HWPROFILE_CHANGE_SERVICE_VETO
//
// MessageText:
//
//  The service "%1" vetoed a hardware profile change request.
//
#define WRN_HWPROFILE_CHANGE_SERVICE_VETO ((DWORD)0x80000105L)

//
// MessageId: WRN_POWER_EVENT_SERVICE_VETO
//
// MessageText:
//
//  The service "%1" vetoed a power event request.
//
#define WRN_POWER_EVENT_SERVICE_VETO     ((DWORD)0x80000106L)

//
// MessageId: WRN_STOPPED_SERVICE_REGISTERED
//
// MessageText:
//
//  The service "%1" may not have unregistered for device event notifications before it was stopped.
//
#define WRN_STOPPED_SERVICE_REGISTERED   ((DWORD)0x80000107L)

//
// MessageId: WRN_NEWDEV_NOT_PRESENT
//
// MessageText:
//
//  Client side device installation was not performed because the file "%1" was not found.
//
#define WRN_NEWDEV_NOT_PRESENT           ((DWORD)0x80000108L)

//
// MessageId: WRN_HOTPLUG_NOT_PRESENT
//
// MessageText:
//
//  HotPlug notification was not performed because the file "%1" was not found.
//
#define WRN_HOTPLUG_NOT_PRESENT          ((DWORD)0x80000109L)

//
// MessageId: WRN_EMBEDDEDNT_UI_SUPPRESSED
//
// MessageText:
//
//  Plug and Play user-interface dialogs have been suppressed on EmbeddedNT.
//
#define WRN_EMBEDDEDNT_UI_SUPPRESSED     ((DWORD)0x8000010AL)

//
// MessageId: WRN_NEWDEV_UI_SUPPRESSED
//
// MessageText:
//
//  Client side device installation was not performed for "%1" because all user-interface dialogs have been suppressed.
//
#define WRN_NEWDEV_UI_SUPPRESSED         ((DWORD)0x8000010BL)

//
// MessageId: WRN_HOTPLUG_UI_SUPPRESSED
//
// MessageText:
//
//  HotPlug notification was not performed for "%1" because all user-interface dialogs have been suppressed.
//
#define WRN_HOTPLUG_UI_SUPPRESSED        ((DWORD)0x8000010CL)

//
// MessageId: WRN_REBOOT_UI_SUPPRESSED
//
// MessageText:
//
//  Did not prompt a user for reboot because all user-interface dialogs have been suppressed.
//
#define WRN_REBOOT_UI_SUPPRESSED         ((DWORD)0x8000010DL)

//
// MessageId: WRN_FACTORY_UI_SUPPRESSED
//
// MessageText:
//
//  Plug and Play user-interface dialogs have been suppressed in Factory Mode.
//
#define WRN_FACTORY_UI_SUPPRESSED        ((DWORD)0x8000010EL)

