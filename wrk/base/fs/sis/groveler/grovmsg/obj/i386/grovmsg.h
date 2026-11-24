/*++

Copyright (c) 1998  Microsoft Corporation

Module Name:

    grovmsg.h

Abstract:

	SIS Groveler message definitions

Authors:

	John Douceur, 1998

Environment:

	User Mode


Revision History:


--*/

#ifndef _INC_GROVMSG

#define _INC_GROVMSG


#define MESSAGE_SEVERITY(hr)  (((hr) >> 30) & 0x3)

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
#define MESSAGE_SEVERITY_WARNING         0x2
#define MESSAGE_SEVERITY_SUCCESS         0x0
#define MESSAGE_SEVERITY_INFORMATIONAL   0x1
#define MESSAGE_SEVERITY_ERROR           0x3


//
// MessageId: GROVMSG_SERVICE_STARTED
//
// MessageText:
//
//  The groveler service has started.
//
#define GROVMSG_SERVICE_STARTED          0x46661000L

//
// MessageId: GROVMSG_GROVELER_STARTED
//
// MessageText:
//
//  The groveler on partition %1 has started successfully.
//
#define GROVMSG_GROVELER_STARTED         0x46661001L

//
// MessageId: GROVMSG_SET_USN_LOG_SIZE
//
// MessageText:
//
//  Setting USN log size on partition %1 to %2 bytes.
//
#define GROVMSG_SET_USN_LOG_SIZE         0x46661002L

//
// MessageId: GROVMSG_GROVELER_DISABLED
//
// MessageText:
//
//  The groveler on partition %1 is disabled.
//
#define GROVMSG_GROVELER_DISABLED        0x46661003L

//
// MessageId: GROVMSG_SERVICE_STOPPED
//
// MessageText:
//
//  The groveler service has stopped.
//
#define GROVMSG_SERVICE_STOPPED          0x46661004L

//
// MessageId: GROVMSG_SERVICE_PAUSED
//
// MessageText:
//
//  The groveler service has paused.
//
#define GROVMSG_SERVICE_PAUSED           0x46661005L

//
// MessageId: GROVMSG_SERVICE_CONTINUED
//
// MessageText:
//
//  The groveler service has continued.
//
#define GROVMSG_SERVICE_CONTINUED        0x46661006L

//
// MessageId: GROVMSG_INIT_USN_LOG
//
// MessageText:
//
//  Initializing USN log size on partition %1 to %2 bytes.
//
#define GROVMSG_INIT_USN_LOG             0x46661007L

//MessageId = 0x1008
//Severity = Informational
//Facility = GROVELER
//SymbolicName = GROVMSG_USN_LOG_RETRY
//Language = English
//Attempting to reinitialize the USN log on partition %1.
//.
//
// MessageId: GROVMSG_GROVELER_RETRY
//
// MessageText:
//
//  Attempting to restart the groveler on partition %1.
//
#define GROVMSG_GROVELER_RETRY           0x46661009L

//
// MessageId: GROVMSG_ALL_GROVELERS_DISABLED
//
// MessageText:
//
//  Groveler disabled on all partitions.
//
#define GROVMSG_ALL_GROVELERS_DISABLED   0x86662000L

//
// MessageId: GROVMSG_ALL_GROVELERS_DEAD
//
// MessageText:
//
//  Grovelers on all partitions have failed.
//
#define GROVMSG_ALL_GROVELERS_DEAD       0x86662001L

//
// MessageId: GROVMSG_USN_LOG_OVERRUN
//
// MessageText:
//
//  USN log overrun on partition %1.
//
#define GROVMSG_USN_LOG_OVERRUN          0x46662002L

//
// MessageId: GROVMSG_SET_STATUS_FAILURE
//
// MessageText:
//
//  Unable to set service status, status=%1.
//
#define GROVMSG_SET_STATUS_FAILURE       0x86662003L

//
// MessageId: GROVMSG_NO_PARTITIONS
//
// MessageText:
//
//  No local partitions have SIS installed.
//
#define GROVMSG_NO_PARTITIONS            0x86662004L

//
// MessageId: GROVMSG_UNKNOWN_EXCEPTION
//
// MessageText:
//
//  An unknown exception occurred, exception=%1.
//
#define GROVMSG_UNKNOWN_EXCEPTION        0xC6663000L

//
// MessageId: GROVMSG_SERVICE_NOSTART
//
// MessageText:
//
//  The groveler service has failed to start, status=%1.
//
#define GROVMSG_SERVICE_NOSTART          0xC6663001L

//
// MessageId: GROVMSG_GROVELER_NOSTART
//
// MessageText:
//
//  The groveler on partition %1 has failed to start.
//
#define GROVMSG_GROVELER_NOSTART         0xC6663002L

//
// MessageId: GROVMSG_LOG_EXTRACTOR_DEAD
//
// MessageText:
//
//  USN log read failure on partition %1, status=%2.
//
#define GROVMSG_LOG_EXTRACTOR_DEAD       0xC6663003L

//
// MessageId: GROVMSG_GROVELER_DEAD
//
// MessageText:
//
//  The groveler on partition %1 has failed due to a database error. 
//  See ESENT event log entries for details.
//
#define GROVMSG_GROVELER_DEAD            0xC6663004L

//
// MessageId: GROVMSG_MEMALLOC_FAILURE
//
// MessageText:
//
//  The groveler service failed to allocate memory.
//
#define GROVMSG_MEMALLOC_FAILURE         0xC6663005L

//
// MessageId: GROVMSG_CREATE_EVENT_FAILURE
//
// MessageText:
//
//  The groveler service failed to create a Windows event, status=%1.
//
#define GROVMSG_CREATE_EVENT_FAILURE     0xC6663006L

//MessageId = 0x3007
//Severity = Error
//Facility = GROVELER
//SymbolicName = GROVMSG_DATABASE_ERROR
//Language = English
//The groveler database on partition %1 has failed. %0
//Database will be reinitialized.%0
//.

#endif /* _INC_GROVMSG */
