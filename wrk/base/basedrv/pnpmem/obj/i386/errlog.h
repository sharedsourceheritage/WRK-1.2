/*++ BUILD Version: 0001    // Increment this if a change has global effects

Copyright (C) Microsoft Corporation, 2001

Module Name:

    pnpmem.mc

Abstract:

    Constant definitions for the I/O error code log values.

--*/

#ifndef _PNPMEMLOG_
#define _PNPMEMLOG_


//
// Warning Error Messages
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
#define FACILITY_RPC_STUBS               0x3
#define FACILITY_RPC_RUNTIME             0x2
#define FACILITY_PNPMEM_ERROR_CODE       0xF
#define FACILITY_IO_ERROR_CODE           0x4


//
// Define the severity codes
//
#define STATUS_SEVERITY_WARNING          0x2
#define STATUS_SEVERITY_SUCCESS          0x0
#define STATUS_SEVERITY_INFORMATIONAL    0x1
#define STATUS_SEVERITY_ERROR            0x3


//
// MessageId: PNPMEM_ERR_FAILED_TO_ADD_MEMORY
//
// MessageText:
//
//  Failed to add memory range starting at 0x%2 for 0x%3 bytes.  This
//  operation exceeded the maximum memory capacity of the operating system
//  or the server is not configured to support dynamic memory operations.
//
#define PNPMEM_ERR_FAILED_TO_ADD_MEMORY  ((NTSTATUS)0x800F0000L)

#endif /* _PNPMEMLOG_ */
