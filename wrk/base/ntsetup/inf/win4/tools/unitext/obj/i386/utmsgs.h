/*++

Copyright (c) 1991  Microsoft Corporation

Module Name:

    utmsgs.h

Abstract:

    This file contains the message definitions for unitext.exe.

Author:

    Ted Miller (tedm) 16-June-1993

Revision History:

Notes:

    This file is generated from utmsgs.mc

--*/

#ifndef _UNITEXTMSG_
#define _UNITEXTMSG_


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
// MessageId: MSG_FIRST_UNITEXT_MSG
//
// MessageText:
//
//  MSG_FIRST_UNITEXT_MSG
//
#define MSG_FIRST_UNITEXT_MSG            0x000061A8L

//
// MessageId: MSG_BAD_MSG
//
// MessageText:
//
//  Internal error: can't find message %1!u!.
//
#define MSG_BAD_MSG                      0x000061A9L

//
// MessageId: MSG_INSUFFICIENT_MEMORY
//
// MessageText:
//
//  Insufficient memory.
//
#define MSG_INSUFFICIENT_MEMORY          0x000061AAL

//
// MessageId: MSG_USAGE
//
// MessageText:
//
//  
//  Usage: unitext [-m|-u] [-o|-a|-<nnn>] [-z] <src_file> <dst_file>
//  
//      -m     multibyte->unicode translation.
//      -u     unicode->multibyte translation.
//  
//      -o     multibyte text file uses current OEM codepage [default].
//      -a     multibyte text file uses current ANSI codepage.
//      -<nnn> multibyte character set uses given codepage.
//      -z     Doesn't convert MB->UC if file is already Unicode (or)
//  	   Doesn't convert UC->MB if file is not Unicode
//  
//  
//  Examples:
//  
//      unitext -m -o c:\src.txt c:\dst.uni
//  
//          Converts OEM text file c:\src.txt to Unicode text file c:\dst.uni.
//  
//      unitext -u -a c:\src.uni c:\dst.txt
//  
//          Converts Unicode text file c:\src.uni to ANSI text file c:\dst.txt
//  
//      unitext -m -437 c:\src.txt c:\dst.uni
//  
//          Converts OEM text file in codepage 437 to Unicode text file.
//
#define MSG_USAGE                        0x000061ABL

//
// MessageId: MSG_CANT_OPEN_SOURCE
//
// MessageText:
//
//  Unable to open source file %1 (error = %2!u!).
//
#define MSG_CANT_OPEN_SOURCE             0x000061ACL

//
// MessageId: MSG_CANT_OPEN_TARGET
//
// MessageText:
//
//  Unable to create target file %1 (error = %2!u!).
//
#define MSG_CANT_OPEN_TARGET             0x000061ADL

//
// MessageId: MSG_CANT_GET_SIZE
//
// MessageText:
//
//  Unable to to determine size of source file %1 (error = %2!u!).
//
#define MSG_CANT_GET_SIZE                0x000061AEL

//
// MessageId: MSG_ZERO_LENGTH
//
// MessageText:
//
//  Source file %1 is empty.
//
#define MSG_ZERO_LENGTH                  0x000061AFL

//
// MessageId: MSG_READ_ERROR
//
// MessageText:
//
//  Unable to read file %1 (error = %2!u!).
//
#define MSG_READ_ERROR                   0x000061B0L

//
// MessageId: MSG_WARN_SRC_IS_MB
//
// MessageText:
//
//  Warning: source file %1 is probably not unicode!
//
#define MSG_WARN_SRC_IS_MB               0x000061B1L

//
// MessageId: MSG_WARN_SRC_IS_UNICODE
//
// MessageText:
//
//  Warning: source file %1 is probably unicode!
//
#define MSG_WARN_SRC_IS_UNICODE          0x000061B2L

//
// MessageId: MSG_SEEK_ERROR
//
// MessageText:
//
//  Unable to seek in file %1 (error = %2!u!).
//
#define MSG_SEEK_ERROR                   0x000061B3L

//
// MessageId: MSG_BAD_CODEPAGE
//
// MessageText:
//
//  Codepage %1!u! is invalid.
//
#define MSG_BAD_CODEPAGE                 0x000061B4L

//
// MessageId: MSG_CONV_MB_TO_UNICODE
//
// MessageText:
//
//  Converting multibyte file %1 to unicode file %2 using codepage %3!u!...
//
#define MSG_CONV_MB_TO_UNICODE           0x000061B5L

//
// MessageId: MSG_CANT_MAP_FILE
//
// MessageText:
//
//  Unable to map file %1 (error = %2!u!).
//
#define MSG_CANT_MAP_FILE                0x000061B6L

//
// MessageId: MSG_CONVERT_FAILED
//
// MessageText:
//
//  Conversion failed (error = %1!u!).
//
#define MSG_CONVERT_FAILED               0x000061B7L

//
// MessageId: MSG_ERROR_SET_EOF
//
// MessageText:
//
//  Unable to set end-of-file for file %1 (error = %2!u!).
//
#define MSG_ERROR_SET_EOF                0x000061B8L

//
// MessageId: MSG_CONVERT_OK
//
// MessageText:
//
//  Conversion completed.
//
#define MSG_CONVERT_OK                   0x000061B9L

//
// MessageId: MSG_CONV_UNICODE_TO_MB
//
// MessageText:
//
//  Converting unicode file %1 to multibyte file %2 using codepage %3!u!...
//
#define MSG_CONV_UNICODE_TO_MB           0x000061BAL

//
// MessageId: MSG_ERROR_BYTES_SWAPPED
//
// MessageText:
//
//  Byte-reversed unicode files are not supported.
//
#define MSG_ERROR_BYTES_SWAPPED          0x000061BBL

//
// MessageId: MSG_USED_DEFAULT_CHAR
//
// MessageText:
//
//  One or more characters replaced in target by default character.
//
#define MSG_USED_DEFAULT_CHAR            0x000061BCL

//
// MessageId: MSG_ERR_SRC_IS_MB
//
// MessageText:
//
//  Warning: source file %1 is probably not unicode! Stopping conversion.
//
#define MSG_ERR_SRC_IS_MB                0x000061BDL

//
// MessageId: MSG_ERR_SRC_IS_UNICODE
//
// MessageText:
//
//  Warning: source file %1 is probably unicode! Stopping conversion.
//
#define MSG_ERR_SRC_IS_UNICODE           0x000061BEL

#endif // _UNITEXTMSG_
