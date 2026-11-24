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
// MessageId: MSG_FIRST
//
// MessageText:
//
//  MSG_FIRST
//
#define MSG_FIRST                        0x0000EA60L

//
// MessageId: MSG_ERROR_WITH_SYSTEM_ERROR
//
// MessageText:
//
//  %1
//  
//  %2%0
//
#define MSG_ERROR_WITH_SYSTEM_ERROR      0x0000EA61L

//
// MessageId: MSG_USAGE
//
// MessageText:
//
//  Usage: riprep [/quiet] [/pnp]
//  Options:
//  /quiet%tDo not show confirmation dialog boxes.
//  /pnp%tImage will force full Plug-and-Play detection of devices on installation.
//
#define MSG_USAGE                        0x0000EA62L

