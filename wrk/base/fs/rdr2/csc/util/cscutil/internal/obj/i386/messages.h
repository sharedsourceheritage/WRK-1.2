//+-------------------------------------------------------------------------
//
//  Microsoft Windows
//  Copyright (C) Microsoft Corporation, 1992 - 2000.
//
//  File:      messages.mc
//
//  Contents:  Main message file
//
//  History:   dd-mmm-yy Author    Comment
//             12-Jan-94 WilliamW  Created for Dfs Administrator project
//
//  Notes:
// A .mc file is compiled by the MC tool to generate a .h file and
// a .rc (resource compiler script) file.
//
// Comments in .mc files start with a ";".
// Comment lines are generated directly in the .h file, without
// the leading ";"
//
// See mc.hlp for more help on .mc files and the MC tool.
//
//--------------------------------------------------------------------------
#ifndef __MESSAGES_H__
#define __MESSAGES_H__
#ifdef FACILITY_NULL
#undef FACILITY_NULL
#endif
#ifdef FACILITY_RPC
#undef FACILITY_RPC
#endif
#ifdef FACILITY_DISPATCH
#undef FACILITY_DISPATCH
#endif
#ifdef FACILITY_STORAGE
#undef FACILITY_STORAGE
#endif
#ifdef FACILITY_ITF
#undef FACILITY_ITF
#endif
#ifdef FACILITY_WIN32
#undef FACILITY_WIN32
#endif
#ifdef FACILITY_WINDOWS
#undef FACILITY_WINDOWS
#endif
//
// Start message values at 0x100
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
#define FACILITY_WINDOWS                 0x8
#define FACILITY_WIN32                   0x7
#define FACILITY_STORAGE                 0x3
#define FACILITY_RPC                     0x1
#define FACILITY_NULL                    0x0
#define FACILITY_ITF                     0x4
#define FACILITY_DISPATCH                0x2


//
// Define the severity codes
//
#define STATUS_SEVERITY_SUCCESS          0x0
#define STATUS_SEVERITY_COERROR          0x2


//
// MessageId: MSG_FIRST_MESSAGE
//
// MessageText:
//
//  MSG_FIRST_MESSAGE
//
#define MSG_FIRST_MESSAGE                ((HRESULT)0x00000100L)

//
// MessageId: MSG_USAGE
//
// MessageText:
//
//  
//  Microsoft(R) Windows(TM) CSC Utility Version Beta 0.31
//  Copyright (C) Microsoft Corporation 1991-2001. All Rights Reserved.
//  
//  Usage: cscutil [/OPTIONS]
//  
//      /INFO
//      /FCBLIST
//      /DBSTATUS
//      /ENABLE
//      /DISABLE
//      /RESID
//      /SWITCHES
//  
//      /CHECK:<\\server\share>
//      /ENUM[:<\\server\share>] [/RECURSE] [/FULL] [/TOUCH]
//      /FILL:<\\server\share> [/FULL] [/ASK /SKIP]
//      /ENUMFORSTATS:<\\server\share>
//  
//      /PIN:<\\server\share\filename> [/USER | /SYSTEM] [/INHERIT]
//      /UNPIN:<\\server\share> [/USER | /SYSTEM] [/INHERIT] [/RECURSE]
//  
//      /DELETE:<\\server\share\path> [/RECURSE]
//  
//      /QUERYFILE:<\\server\share>  [/FULL]
//      /QUERYFILEEX:<\\server\share> [/FULL]
//      /QUERYSHARE:<\\server\share[\path]> [/FULL]
//  
//      /MERGE:<\\server\share> [/ASK /SKIP]
//      /MOVE:<\\server\share\file>
//  
//      /MOVESHARE: <\\server\share> <\\server\share>
//      
//      /RANDW:\\server\share\file [/OFFSET:X,Y,Z]
//  
//      /DISCONNECT:<\\server\share>
//      /RECONNECT:<\\server\share>
//  
//      /ISSERVEROFFLINE:<\\server\share>
//  
//      /GETSPACE
//      /SETSPACE:<bytes to set>
//  
//      /ENCRYPT
//      /DECRYPT
//  
//      /EXCLUSIONLIST:<exclusionlist>
//      /BWCONSERVATIONLIST:<exclusionlist>
//      /FLAGS
//  
//      /SHAREID:<HSHARE>
//      /PQENUM
//  
//      /DB:[<CSC DB DIRECTORY>]
//  
//
#define MSG_USAGE                        ((HRESULT)0x00000101L)

//
// MessageId: MSG_USAGE_EX
//
// MessageText:
//
//  
//      -------------------------------------------------------------
//      /DEBUG
//      /SETSHARESTATUS:<SHARE>:<FLAGS>  /SET /CLEAR
//      /PURGE[:timeout]
//      /DETECTOR
//      /GETSHADOW:<HDIR>:<NAME>
//      /GETSHADOWINFO:<HDIR>:<HSHADOW>
//      /DELETESHADOW:<HDIR>:<HSHADOW>
//
#define MSG_USAGE_EX                     ((HRESULT)0x00000102L)

//
// MessageId: MSG_USAGE2
//
// MessageText:
//
//  
//  Microsoft(R) Windows(TM) CSC Utility Version Beta 0.31
//  Copyright (C) Microsoft Corporation 1991-2001. All Rights Reserved.
//  
//  Usage: csccmd [/OPTIONS]
//  
//      /RESID
//      /ENUM[:<\\server\share>] [/RECURSE]
//      /DISCONNECT:<\\server\share>
//      /MOVESHARE: <\\server\share> <\\server\share>
//  
//
#define MSG_USAGE2                       ((HRESULT)0x00000103L)

//
// MessageId: MSG_USAGE_EX2
//
// MessageText:
//
//  
//      -------------------------------------------------------------
//      /DEBUG
//  
//
#define MSG_USAGE_EX2                    ((HRESULT)0x00000104L)

//
// MessageId: MSG_FLAGS
//
// MessageText:
//
//  
//  Share status flags -------------------
//  
//  0x00000000  Manual Caching
//  0x00000001  Modified offline
//  0x00000040  Auto Caching
//  0x00000080  Virtually Disconnected Ops
//  0x000000C0  No Caching
//  0x00000200  Finds in progress
//  0x00000400  Open files
//  0x00000800  Connected
//  0x00004000  Merging
//  0x00008000  Disconnected Op
//  
//  File status flags ------------------------
//  
//  0x00000001  Data locally modified
//  0x00000002  Attrib locally modified
//  0x00000004  Time locally modified
//  0x00000008  Stale
//  0x00000010  Locally deleted
//  0x00000020  Sparse
//  0x00000080  Shadow reused
//  0x00000100  Orphan
//  0x00000200  Suspect
//  0x00000400  Locally created
//  0x00010000  User has READ access
//  0x00020000  User has WRITE access
//  0x00040000  Guest has READ access
//  0x00080000  Guest has WRITE access
//  0x00100000  Other has READ access
//  0x00200000  Other has WRITE access
//  0x80000000  Entry is a file
//  0x40000000  File in use
//  
//  File hint flags -------------------
//  
//  0x00000001  Pin User
//  0x00000002  Pin Inherit User
//  0x00000004  Pin Inherit System
//  0x00000008  Conserve Bandwidth
//  0x00000010  Pin System
//  
//
#define MSG_FLAGS                        ((HRESULT)0x00000105L)

//
// MessageId: MSG_SUCCESSFUL
//
// MessageText:
//
//  The command completed successfully.
//
#define MSG_SUCCESSFUL                   ((HRESULT)0x00000106L)

//
// MessageId: MSG_NOTHING_TO_DO
//
// MessageText:
//
//  Nothing to do.
//
#define MSG_NOTHING_TO_DO                ((HRESULT)0x00000107L)

//
// MessageId: MSG_ERROR
//
// MessageText:
//
//  System error %1!d! has occurred.
//
#define MSG_ERROR                        ((HRESULT)0x00000108L)

//
// MessageId: MSG_UNRECOGNIZED_OPTION
//
// MessageText:
//
//  Unrecognized option "%1!s!"
//
#define MSG_UNRECOGNIZED_OPTION          ((HRESULT)0x00000109L)

//
// MessageId: MSG_CSC_DISABLED
//
// MessageText:
//
//  ERROR:: CSC is not enabled on this machine.
//
#define MSG_CSC_DISABLED                 ((HRESULT)0x0000010AL)

//
// MessageId: MSG_TO_LOCAL
//
// MessageText:
//
//  ERROR:: MoveShare cannot move cached remote share to local path.
//
#define MSG_TO_LOCAL                     ((HRESULT)0x0000010BL)

//
// MessageId: MSG_NO_CSC
//
// MessageText:
//
//  ERROR:: CSC was not enabled on one of the specified shares.
//
#define MSG_NO_CSC                       ((HRESULT)0x0000010CL)

//
// MessageId: MSG_NOT_ONLINE
//
// MessageText:
//
//  ERROR:: MoveShare will only move to a currently online share.
//
#define MSG_NOT_ONLINE                   ((HRESULT)0x0000010DL)

#endif // __MESSAGES_H__
