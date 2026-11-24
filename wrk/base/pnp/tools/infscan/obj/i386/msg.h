//
// Copyright (c) Microsoft Corporation.  All rights reserved.
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


//
// Define the severity codes
//


//
// MessageId: MSG_NULL
//
// MessageText:
//
//  MSG_NULL
//
#define MSG_NULL                         0x0000EA60L

//
// MessageId: MSG_INF_STYLE_WIN4
//
// MessageText:
//
//  Cannot open as INF_STYLE_WIN4.
//
#define MSG_INF_STYLE_WIN4               0x0000EA61L

//
// MessageId: MSG_NO_CLASS_GUID
//
// MessageText:
//
//  No Class GUID (but Class specified).
//
#define MSG_NO_CLASS_GUID                0x0000EA62L

//
// MessageId: MSG_INVALID_CLASS_GUID
//
// MessageText:
//
//  Setup Class GUID is invalid.
//
#define MSG_INVALID_CLASS_GUID           0x0000EA63L

//
// MessageId: MSG_INCORRECT_CLASS_GUID
//
// MessageText:
//
//  Setup Class GUID different to expected %1.
//
#define MSG_INCORRECT_CLASS_GUID         0x0000EA64L

//
// MessageId: MSG_UNKNOWN_CLASS_GUID
//
// MessageText:
//
//  Setup Class GUID not listed in filter.
//
#define MSG_UNKNOWN_CLASS_GUID           0x0000EA65L

//
// MessageId: MSG_NO_LISTED_MODEL
//
// MessageText:
//
//  Listed model section [%1] does not exist.
//
#define MSG_NO_LISTED_MODEL              0x0000EA66L

//
// MessageId: MSG_NO_MANUFACTURER
//
// MessageText:
//
//  No/Empty [Manufacturer] section.
//
#define MSG_NO_MANUFACTURER              0x0000EA67L

//
// MessageId: MSG_SECTION_NAME_TOO_BIG
//
// MessageText:
//
//  Section name listed in [%1] too big (use ChkInf for more).
//
#define MSG_SECTION_NAME_TOO_BIG         0x0000EA68L

//
// MessageId: MSG_EXPECTED_MODEL_SECTION
//
// MessageText:
//
//  A model section is not listed in [Manufacturer] section (use ChkInf for more).
//
#define MSG_EXPECTED_MODEL_SECTION       0x0000EA69L

//
// MessageId: MSG_DECORATED_MODEL
//
// MessageText:
//
//  One or more decorated models for section [%1] (incompatible with Win2k).
//
#define MSG_DECORATED_MODEL              0x0000EA6AL

//
// MessageId: MSG_NO_CLASS
//
// MessageText:
//
//  No Class GUID or Class specified.
//
#define MSG_NO_CLASS                     0x0000EA6BL

//
// MessageId: MSG_EXPECTED_DESCRIPTION
//
// MessageText:
//
//  Device description expected in models section [%1].
//
#define MSG_EXPECTED_DESCRIPTION         0x0000EA6CL

//
// MessageId: MSG_EXPECTED_INSTALL_SECTION
//
// MessageText:
//
//  Install section expected in models section [%1] for description "%2".
//
#define MSG_EXPECTED_INSTALL_SECTION     0x0000EA6DL

//
// MessageId: MSG_NO_ACTUAL_INSTALL_SECTION
//
// MessageText:
//
//  No install section [%1] or decorated variant found.
//
#define MSG_NO_ACTUAL_INSTALL_SECTION    0x0000EA6EL

//
// MessageId: MSG_LOCAL_DUPLICATE_DESC
//
// MessageText:
//
//  Device description "%3" is used for both install sections [%1] and [%2] in same INF.
//
#define MSG_LOCAL_DUPLICATE_DESC         0x0000EA6FL

//
// MessageId: MSG_GLOBAL_DUPLICATE_DESC
//
// MessageText:
//
//  Device description "%3" in section [%1] is also used in INF(s) %2.
//
#define MSG_GLOBAL_DUPLICATE_DESC        0x0000EA70L

//
// MessageId: MSG_MULTIPLE_INCLUDE
//
// MessageText:
//
//  Multiple INCLUDE directives in [%1] (2nd+ ignored).
//
#define MSG_MULTIPLE_INCLUDE             0x0000EA71L

//
// MessageId: MSG_MULTIPLE_NEEDS
//
// MessageText:
//
//  Multiple NEEDS directives in [%1] (2nd+ ignored).
//
#define MSG_MULTIPLE_NEEDS               0x0000EA72L

//
// MessageId: MSG_OPENAPPENDINF
//
// MessageText:
//
//  Failed to open INF "%1" that should be located at "%2".
//
#define MSG_OPENAPPENDINF                0x0000EA73L

//
// MessageId: MSG_RECURSIVE_INCLUDE
//
// MessageText:
//
//  NEEDS in [%1] has recursive INCLUDE in [%2].
//
#define MSG_RECURSIVE_INCLUDE            0x0000EA74L

//
// MessageId: MSG_RECURSIVE_NEEDS
//
// MessageText:
//
//  NEEDS in [%1] has recursive NEEDS in [%2].
//
#define MSG_RECURSIVE_NEEDS              0x0000EA75L

//
// MessageId: MSG_INCLUDE
//
// MessageText:
//
//  INCLUDE in [%1].
//
#define MSG_INCLUDE                      0x0000EA76L

//
// MessageId: MSG_NEEDS
//
// MessageText:
//
//  NEEDS in [%1].
//
#define MSG_NEEDS                        0x0000EA77L

//
// MessageId: MSG_NEEDS_NOSECT
//
// MessageText:
//
//  NEEDS in [%1] references non existant section [%2].
//
#define MSG_NEEDS_NOSECT                 0x0000EA78L

//
// MessageId: MSG_NO_GENERIC_INSTALL_SECTION
//
// MessageText:
//
//  Decorated versions of install section [%1] found only for subset of platforms.
//
#define MSG_NO_GENERIC_INSTALL_SECTION   0x0000EA79L

//
// MessageId: MSG_MODEL_DECORATION_BAD
//
// MessageText:
//
//  Decorated Model section [%1.%2] of [%1] not allowed.
//
#define MSG_MODEL_DECORATION_BAD         0x0000EA7AL

//
// MessageId: MSG_MISSING_COPY_SECTION
//
// MessageText:
//
//  Missing CopyFiles section [%1] referenced from [%2].
//
#define MSG_MISSING_COPY_SECTION         0x0000EA7BL

//
// MessageId: MSG_BAD_FILENAME_ENTRY
//
// MessageText:
//
//  Bad/missing keyword in [%1].
//
#define MSG_BAD_FILENAME_ENTRY           0x0000EA7CL

//
// MessageId: MSG_BAD_FILENAME_DISK
//
// MessageText:
//
//  Missing Disk ID in [%1] for "%2".
//
#define MSG_BAD_FILENAME_DISK            0x0000EA7DL

//
// MessageId: MSG_SOURCE_CONFLICT
//
// MessageText:
//
//  Source information about file "%2" in [%1] differs from same file entry in other SourceDisksFiles (check).
//
#define MSG_SOURCE_CONFLICT              0x0000EA7EL

//
// MessageId: MSG_SOURCE_NOT_LISTED
//
// MessageText:
//
//  No source information for file "%2" copied via [%1].
//
#define MSG_SOURCE_NOT_LISTED            0x0000EA7FL

//
// MessageId: MSG_SOURCE_NOT_LISTED_PLATFORM
//
// MessageText:
//
//  No source information for file "%2" for specific platform copied via [%1].
//
#define MSG_SOURCE_NOT_LISTED_PLATFORM   0x0000EA80L

//
// MessageId: MSG_WINNT_DIRECTORY_CONFLICT
//
// MessageText:
//
//  [WinntDirectories] listing for "%1" has same index as listing for "%2".
//
#define MSG_WINNT_DIRECTORY_CONFLICT     0x0000EA81L

//
// MessageId: MSG_TEXTMODE_DISPOSITION_MISSING_DIR
//
// MessageText:
//
//  Textmode/Upgrade disposition for "%2" in [%1] indicates potential copy but no destination directory given.
//
#define MSG_TEXTMODE_DISPOSITION_MISSING_DIR 0x0000EA82L

//
// MessageId: MSG_DIRID_NOT_SPECIFIED
//
// MessageText:
//
//  Section "%1" in [DestinationDirs] needs to specify directory ID.
//
#define MSG_DIRID_NOT_SPECIFIED          0x0000EA83L

//
// MessageId: MSG_TEXTMODE_TARGET_MISMATCH
//
// MessageText:
//
//  Textmode/Upgrade target for "%2" mismatches copy target in [%1].
//
#define MSG_TEXTMODE_TARGET_MISMATCH     0x0000EA84L

//
// MessageId: MSG_TEXTMODE_TARGET_UNKNOWN
//
// MessageText:
//
//  Textmode/Upgrade directory for "%2" is not listed.
//
#define MSG_TEXTMODE_TARGET_UNKNOWN      0x0000EA85L

//
// MessageId: MSG_GLOBAL_DUPLICATE_HWID
//
// MessageText:
//
//  Hardware ID "%3" in section [%1] is also used in INF(s) %2.
//
#define MSG_GLOBAL_DUPLICATE_HWID        0x0000EA86L

