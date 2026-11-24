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
#ifdef MOVERENAME
// /move \\dfsname\dfsshare\path1 \\dfsname\dfsshare\path2
//         Move a Dfs junction point.
// /rename \\dfsname\dfsshare\path1 \\dfsname\dfsshare\path2
//         Rename a folder that is in the Dfs.
#endif
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
//  The syntax of this command is:
//  
//  DFSCMD [options]
//  
//  DFSCMD configures a Dfs tree.
//  
//  [options] can be:
//  
//  /help
//          Display this message.
//  /map \\dfsname\dfsshare\path \\server\share\path [comment] [/restore]
//          Create a Dfs volume; map a Dfs path to a server path. With /restore,
//          do no checks of destination server.
//  /unmap \\dfsname\dfsshare\path
//          Delete a Dfs volume; remove all its replicas.
//  /add \\dfsname\dfsshare\path \\server\share\path [/restore]
//          Add a replica to a Dfs volume.  With /restore, do no checks of
//          destination server.
//  /remove \\dfsname\dfsshare\path \\server\share\path
//          Remove a replica from a Dfs volume.
//  /view \\dfsname\dfsshare [/partial | /full | /batch || /batchrestore]
//          View all the volumes in the Dfs. Without arguments, view just
//          the volume names. With /partial, view comment also.  With /full,
//          display a list of all the servers for a volume. With /batch,
//          output a batch file to recreate the dfs.  With /batchrestore,
//          output a batch file to recreate the dfs using the /restore switch.
//  
//  Note that paths or comments with spaces should be enclosed in quotes.
//
#define MSG_USAGE                        ((HRESULT)0x00000101L)

//
// MessageId: MSG_OUTOFMEMORY
//
// MessageText:
//
//  Out of memory.
//
#define MSG_OUTOFMEMORY                  ((HRESULT)0x00000102L)

//
// MessageId: MSG_SUCCESSFUL
//
// MessageText:
//
//  The command completed successfully.
//
#define MSG_SUCCESSFUL                   ((HRESULT)0x00000103L)

//
// MessageId: MSG_ERROR
//
// MessageText:
//
//  System error %1!d! has occurred.
//  
//
#define MSG_ERROR                        ((HRESULT)0x00000104L)

//
// MessageId: MSG_ERROR_UNKNOWN
//
// MessageText:
//
//  Unknown error.
//
#define MSG_ERROR_UNKNOWN                ((HRESULT)0x00000105L)

//
// MessageId: MSG_NO_MESSAGES
//
// MessageText:
//
//  Couldn't find message file %1!s!.
//
#define MSG_NO_MESSAGES                  ((HRESULT)0x00000106L)

//
// MessageId: MSG_BAD_PATH
//
// MessageText:
//
//  Error analyzing input path.
//
#define MSG_BAD_PATH                     ((HRESULT)0x00000107L)

//
// MessageId: MSG_BAD_PATH2
//
// MessageText:
//
//  Path %1!s! does not refer to a directory.
//
#define MSG_BAD_PATH2                    ((HRESULT)0x00000108L)

//
// MessageId: MSG_ERROR_CREATING_DIR
//
// MessageText:
//
//  Error creating directory %1!s!.
//
#define MSG_ERROR_CREATING_DIR           ((HRESULT)0x00000109L)

#endif // __MESSAGES_H__
