//+-------------------------------------------------------------------------
//
//  Microsoft Windows
//  Copyright (C) Microsoft Corporation, 1992 - 1993.
//
//  File:      messages.mc
//
//  Contents:  Main message file
//
//  History:   dd-mmm-yy Author    Comment
//             23-Apr-96 BruceFo	Added to dfs setup
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
//////////////////////////////////////////////////////////////////////////
//
// Messages. Note that we use "severity=success" for everything, since no
// error codes are actually getting returned to anyone. We're only using
// the message file for FormatMessage().
//
//////////////////////////////////////////////////////////////////////////
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
// MessageId: MSG_BROWSE
//
// MessageText:
//
//  Select the folder you wish to share.
//
#define MSG_BROWSE                       ((HRESULT)0x00000100L)

//
// MessageId: MSG_NONTSHRUI
//
// MessageText:
//
//  Couldn't load ntshrui.dll.
//
#define MSG_NONTSHRUI                    ((HRESULT)0x00000101L)

//
// MessageId: MSG_NOSERVER
//
// MessageText:
//
//  Unable to enumerate shares. Check to make sure the server is running.
//
#define MSG_NOSERVER                     ((HRESULT)0x00000102L)

//
// MessageId: MSG_NODIRECTORY
//
// MessageText:
//
//  The directory specified, %1!s!, doesn't exist. Do you want to create it?
//
#define MSG_NODIRECTORY                  ((HRESULT)0x00000103L)

//
// MessageId: MSG_ILLEGAL_DIRECTORY
//
// MessageText:
//
//  The directory specified, %1!s!, is either not a local directory or can't otherwise be shared. Please enter a local, shareable, fully-qualified directory.
//
#define MSG_ILLEGAL_DIRECTORY            ((HRESULT)0x00000104L)

//
// MessageId: MSG_NOT_A_DIRECTORY
//
// MessageText:
//
//  The path specified, %1!s!, exists but is not a directory. Please enter a new path.
//
#define MSG_NOT_A_DIRECTORY              ((HRESULT)0x00000105L)

//
// MessageId: MSG_FILEATTRIBSFAIL
//
// MessageText:
//
//  Error examining directory %1!s!.
//
#define MSG_FILEATTRIBSFAIL              ((HRESULT)0x00000106L)

//
// MessageId: MSG_COULDNT_CREATE_DIRECTORY
//
// MessageText:
//
//  Could not create directory %1.
//
#define MSG_COULDNT_CREATE_DIRECTORY     ((HRESULT)0x00000107L)

//
// MessageId: MSG_DFS_DESCRIPTION
//
// MessageText:
//
//  Integrates disparate file shares into a single, logical namespace and manages these logical volumes distributed across a local or wide area network. If this service is stopped, users will be unable to access file shares. If this service is disabled, any services that explicitly depend on it will fail to start.
//
#define MSG_DFS_DESCRIPTION              ((HRESULT)0x00000108L)

//
// MessageId: MSG_DFS_COMPONENT_NAME
//
// MessageText:
//
//  Distributed File System
//
#define MSG_DFS_COMPONENT_NAME           ((HRESULT)0x00000109L)

#endif // __MESSAGES_H__
