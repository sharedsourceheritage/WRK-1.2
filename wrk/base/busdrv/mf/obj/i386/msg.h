/*++ BUILD Version: 0001    // Increment this if a change has global effects

Copyright (c) 1997-2000  Microsoft Corporation

Module Name:

    mf.mc

Abstract:

    Internationalizable messages for user viewable text.

Author:

    Andy Thornton (andrewth) 20-Oct-97

Revision History:

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


//
// MessageId: MF_MSG_TEXT_DESCRIPTION
//
// MessageText:
//
//  Multifunction Device
//
#define MF_MSG_TEXT_DESCRIPTION          ((MF_MSG_ID)0x00000000L)

