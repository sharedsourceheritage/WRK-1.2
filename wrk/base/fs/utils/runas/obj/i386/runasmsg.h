 /*++ BUILD Version: 0001    // Increment this if a change has global effects
Copyright (c) 1997-2001  Microsoft Corporation

Module Name:

    RunasMsg.mc

Abstract:

    This file contains the message definitions for the Win32 runas
    utility.

Author:

    Duncan Bryce          [DuncanB]         19-Feb-2001

Revision History:

--*/

 /**++

 %1 represents the application created by runas
 %2 represents the user who's context the process has been created in
 %3 represents the privilege level of the user

 For example:

 cmd.exe (running as ntdev\duncanb with untrusted privileges)

 --**/

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
// MessageId: RUNASP_STRING_TITLE_WITH_RESTRICTED
//
// MessageText:
//
//  %1 (running as %2 with %3 privileges)%0
//
#define RUNASP_STRING_TITLE_WITH_RESTRICTED 0x00001F41L

 /**++

 %1 represents the application created by runas
 %2 represents the user who's context the process has been created in

 For example:

 cmd.exe (running as ntdev\duncanb)

 --**/

//
// MessageId: RUNASP_STRING_TITLE
//
// MessageText:
//
//  %1 (running as %2)%0
//
#define RUNASP_STRING_TITLE              0x00001F42L

//
// MessageId: RUNASP_STRING_ERROR_INTERNAL
//
// MessageText:
//
//  RUNAS ERROR: An internal error occured: %1!d!
//
#define RUNASP_STRING_ERROR_INTERNAL     0x00001F43L

//
// MessageId: RUNASP_STRING_WAIT
//
// MessageText:
//
//  Attempting to start %1 as user "%2" ...
//
#define RUNASP_STRING_WAIT               0x00001F44L

 /**++

 %1 represents the application that runas couldn't start
 %2 represents the numeric error code
 %3 represents the formatted error text 

 For example:
 
 RUNAS ERROR: Unable to run - cmd.exe 
 1326: Logon Failure: unknown username or bad password. 

 --**/

//
// MessageId: RUNASP_STRING_ERROR_OCCURED
//
// MessageText:
//
//  RUNAS ERROR: Unable to run - %1
//  %2!d!: %3 %0
//
#define RUNASP_STRING_ERROR_OCCURED      0x00001F45L

//
// MessageId: RUNASP_STRING_ERROR_ARG_TOO_LONG
//
// MessageText:
//
//  RUNAS ERROR: The following argument was too long: %1
//
#define RUNASP_STRING_ERROR_ARG_TOO_LONG 0x00001F46L

