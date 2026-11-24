/*++ BUILD Version: 0001    // Increment this if a change has global effects

Copyright (c) 2001  Microsoft Corporation

Module Name:

    errlog.mc

Abstract:

    Constant definitions for the I/O error code log values.

Revision History:

--*/

#ifndef _ACPIECLOG_
#define _ACPIECLOG_

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
#define FACILITY_RPC_STUBS               0x3
#define FACILITY_RPC_RUNTIME             0x2
#define FACILITY_IO_ERROR_CODE           0x4
#define FACILITY_ACPIEC_ERROR_LOG_CODE   0x5


//
// Define the severity codes
//
#define STATUS_SEVERITY_WARNING          0x2
#define STATUS_SEVERITY_SUCCESS          0x0
#define STATUS_SEVERITY_INFORMATIONAL    0x1
#define STATUS_SEVERITY_ERROR            0x3


//
// MessageId: ACPIEC_ERR_WATCHDOG
//
// MessageText:
//
//  %1: The embedded controller (EC) hardware didn't respond within the timeout period.  This may indicate an error in the EC hardware or firmware, or possibly a poorly designed BIOS which accesses the EC in an unsafe manner.  The EC driver will retry the failed transaction if possible.
//
#define ACPIEC_ERR_WATCHDOG              ((NTSTATUS)0xC0050001L)

//
// MessageId: ACPIEC_ERR_EC_LOCKED
//
// MessageText:
//
//  %1: The embedded controller (EC) hardware appears to have quit functioning.  Repeated retries have resulted in no forward progress processing requests.  All requests to the EC will fail until reboot.
//
#define ACPIEC_ERR_EC_LOCKED             ((NTSTATUS)0xC0050002L)

//
// MessageId: ACPIEC_ERR_SPURIOUS_DATA
//
// MessageText:
//
//  %1: The embedded controller (EC) hardware returned data when none was requested.  This may indicate that the BIOS is incorectly trying to access the EC without syncronizing with the OS.  The data is being ignored.
//
#define ACPIEC_ERR_SPURIOUS_DATA         ((NTSTATUS)0x80050003L)

#endif /* _ACPIECLOG_ */
