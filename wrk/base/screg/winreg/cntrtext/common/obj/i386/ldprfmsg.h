/*++ BUILD Version: 0001    // Increment this if a change has global effects

Copyright (c) 1998 Microsoft Corporation

Module Name:

    ldprfmsg.h
       (generated from ldprfmsg.mc)

Abstract:

   Event message definititions used by routines in LoadPerf.DLL

Created:

    8-Mar-99 Bob Watson

Revision History:

--*/
#ifndef _LDPRFMSG_H_
#define _LDPRFMSG_H_

//
//     LoadPerf ERRORS
//
// 
// informational messages
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
#define STATUS_SEVERITY_WARNING          0x2
#define STATUS_SEVERITY_SUCCESS          0x0
#define STATUS_SEVERITY_INFORMATIONAL    0x1
#define STATUS_SEVERITY_ERROR            0x3


//
// MessageId: LDPRFMSG_LOAD_SUCCESS
//
// MessageText:
//
//  Performance counters for the %1!s! (%2!s!) service were loaded successfully.
//  The Record Data contains the new index values assigned
//  to this service.
//
#define LDPRFMSG_LOAD_SUCCESS            ((DWORD)0x400003E8L)

//
// MessageId: LDPRFMSG_UNLOAD_SUCCESS
//
// MessageText:
//
//  Performance counters for the %1!s! (%2!s!) service were removed successfully.
//  The Record Data contains the new values of the system Last Counter and
//  Last Help registry entries.
//
#define LDPRFMSG_UNLOAD_SUCCESS          ((DWORD)0x400003E9L)

//
// MessageId: LDPRFMSG_ALREADY_EXIST
//
// MessageText:
//
//  Performance counters for the %1!s! (%2!s!) service are already in Performance
//  Registry, no need to re-install again.
//
#define LDPRFMSG_ALREADY_EXIST           ((DWORD)0x400003EAL)

// 
// warning messages
// 
//
// MessageId: LDPRFMSG_NO_MOF_FILE_CREATED
//
// MessageText:
//
//  No MOF file %2!s! was created for the %1!s! service. Before the performance
//  counters of this service can be collected by WMI a MOF file will need
//  to be created and loaded manually. Contact the vendor of this service
//  for additional information.
//
#define LDPRFMSG_NO_MOF_FILE_CREATED     ((DWORD)0x800007D1L)

//
// MessageId: LDPRFMSG_NO_MOF_FILE_LOADED
//
// MessageText:
//
//  The MOF file created for the %1!s! service could not be loaded. The
//  error code returned by the MOF Compiler is contained in the Record Data.
//  Before the performance counters of this service can be collected by WMI
//  the MOF file will need to be loaded manually. Contact the vendor of this
//  service for additional information.
//
#define LDPRFMSG_NO_MOF_FILE_LOADED      ((DWORD)0x800007D2L)

//
// MessageId: LDPRFMSG_CANT_DELETE_MOF
//
// MessageText:
//
//  The MOF file created for the %1!s! service cannot be deleted as requested.
//  The MOF file is required for the autorecover function.
//
#define LDPRFMSG_CANT_DELETE_MOF         ((DWORD)0x800007D3L)

//
// MessageId: LDPRFMSG_REGISTRY_CORRUPT_MULTI_SZ
//
// MessageText:
//
//  The Performance registry value %1!s! string is corrupted. Skip string \"%2!s!\".
//
#define LDPRFMSG_REGISTRY_CORRUPT_MULTI_SZ ((DWORD)0x800007D4L)

//
// MessageId: LDPRFMSG_CORRUPT_INCLUDE_FILE
//
// MessageText:
//
//  No COUNTER/HELP definition for Language %1!s!.
//
#define LDPRFMSG_CORRUPT_INCLUDE_FILE    ((DWORD)0x800007D5L)

//
// MessageId: LDPRFMSG_CORRUPT_PERFLIB_INDEX
//
// MessageText:
//
//  LastCounter and LastHelp values of performance registry is corrupted and
//  needs to be updated. The first and second DWORDs in Data Section are the
//  original values while the third and forth DWORDs in Data Section are the
//  updated new values.
//
#define LDPRFMSG_CORRUPT_PERFLIB_INDEX   ((DWORD)0x800007D6L)

//
// MessageId: LDPRFMSG_REPAIR_SERVICE_FAIL
//
// MessageText:
//
//  Cannot repair performance counters for %1!s! service. Please re-install
//  manually using LODCTR tool.
//
#define LDPRFMSG_REPAIR_SERVICE_FAIL     ((DWORD)0x800007D7L)

// 
// error messages
// 

//
// MessageId: LDPRFMSG_REGISTRY_INDEX_CORRUPT
//
// MessageText:
//
//  The performance strings in the registry do not match the index values
//  stored in Performance registry key. The last index value from performance
//  registry key in the first DWORD in Data section, and the index of the
//  last string used in the second DWORD in Data section.
//
#define LDPRFMSG_REGISTRY_INDEX_CORRUPT  ((DWORD)0xC0000BB8L)

//
// MessageId: LDPRFMSG_REGISTRY_COUNTER_STRINGS_CORRUPT
//
// MessageText:
//
//  The performance counter name string value in the registry is incorrectly
//  formatted. The bogus string is %1!s!, the bogus index value is the first
//  DWORD in Data section while the last valid index values are the second and
//  third DWORD in Data section.
//
#define LDPRFMSG_REGISTRY_COUNTER_STRINGS_CORRUPT ((DWORD)0xC0000BB9L)

//
// MessageId: LDPRFMSG_REGISTRY_HELP_STRINGS_CORRUPT
//
// MessageText:
//
//  The performance counter explain text string value in the registry is
//  incorrectly formatted. The bogus string is %1!s!, the bogus index value
//  is the first DWORD in Data section while the last valid index values are
//  the second and third DWORD in Data section.
//
#define LDPRFMSG_REGISTRY_HELP_STRINGS_CORRUPT ((DWORD)0xC0000BBAL)

//
// MessageId: LDPRFMSG_UNABLE_OPEN_KEY
//
// MessageText:
//
//  The %1!s! key could not be opened or accessed in order to install counter
//  strings.The Win32 status returned by the call is the first DWORD in Data
//  section.
//
#define LDPRFMSG_UNABLE_OPEN_KEY         ((DWORD)0xC0000BBBL)

//
// MessageId: LDPRFMSG_UNABLE_READ_VALUE
//
// MessageText:
//
//  The %1!s! registry value could not be read or was the incorrect data type.
//  The Win32 status returned by the call is the first DWORD in Data section.
//
#define LDPRFMSG_UNABLE_READ_VALUE       ((DWORD)0xC0000BBCL)

//
// MessageId: LDPRFMSG_UNABLE_ACCESS_STRINGS
//
// MessageText:
//
//  Unable to open the registry key for the performance counter strings of
//  the %1!s! language ID.
//  The Win32 status returned by the call is the first DWORD in Data section.
//
#define LDPRFMSG_UNABLE_ACCESS_STRINGS   ((DWORD)0xC0000BBDL)

//
// MessageId: LDPRFMSG_UNABLE_READ_COUNTER_STRINGS
//
// MessageText:
//
//  Unable to read the performance counter strings of the %1!s! language ID.
//  The Win32 status returned by the call is the first DWORD in Data section.
//
#define LDPRFMSG_UNABLE_READ_COUNTER_STRINGS ((DWORD)0xC0000BBEL)

//
// MessageId: LDPRFMSG_UNABLE_READ_HELP_STRINGS
//
// MessageText:
//
//  Unable to read the performance counter explain text strings of the
//  %1!s! language ID.
//  The Win32 status returned by the call is the first DWORD in Data section.
//
#define LDPRFMSG_UNABLE_READ_HELP_STRINGS ((DWORD)0xC0000BBFL)

//
// MessageId: LDPRFMSG_MEMORY_ALLOCATION_FAILURE
//
// MessageText:
//
//  Unable to allocate a required memory buffer.
//
#define LDPRFMSG_MEMORY_ALLOCATION_FAILURE ((DWORD)0xC0000BC0L)

//
// MessageId: LDPRFMSG_LOAD_FAILURE
//
// MessageText:
//
//  Installing the performance counter strings for service %1!s! (%2!s!) failed. The
//  Error code is the first DWORD in Data section.
//
#define LDPRFMSG_LOAD_FAILURE            ((DWORD)0xC0000BC1L)

//
// MessageId: LDPRFMSG_UNLOAD_FAILURE
//
// MessageText:
//
//  Unloading the performance counter strings for service %1!s! (%2!s!) failed. The
//  Error code is the first DWORD in Data section.
//
#define LDPRFMSG_UNLOAD_FAILURE          ((DWORD)0xC0000BC3L)

//
// MessageId: LDPRFMSG_REGISTRY_BASEINDEX_CORRUPT
//
// MessageText:
//
//  The performance strings in the Performance registry value is corrupted when
//  process %1!s! extension counter provider. BaseIndex value from Performance
//  registry is the first DWORD in Data section, LastCounter value is the second
//  DWORD in Data section, and LastHelp value is the third DWORD in Data section.
//
#define LDPRFMSG_REGISTRY_BASEINDEX_CORRUPT ((DWORD)0xC0000BC4L)

//
// MessageId: LDPRFMSG_UNABLE_UPDATE_COUNTER_STRINGS
//
// MessageText:
//
//  Unable to update the performance counter strings of the %1!s! language ID.
//  The Win32 status returned by the call is the first DWORD in Data section.
//
#define LDPRFMSG_UNABLE_UPDATE_COUNTER_STRINGS ((DWORD)0xC0000BC5L)

//
// MessageId: LDPRFMSG_UNABLE_UPDATE_HELP_STRINGS
//
// MessageText:
//
//  Unable to update the performance counter explain text strings of the
//  %1!s! language ID.
//  The Win32 status returned by the call is the first DWORD in Data section.
//
#define LDPRFMSG_UNABLE_UPDATE_HELP_STRINGS ((DWORD)0xC0000BC6L)

//
// MessageId: LDPRFMSG_CORRUPT_INDEX
//
// MessageText:
//
//  Index for %1!s! is corrupted. The index value is the first DWORD in Data section.
//
#define LDPRFMSG_CORRUPT_INDEX           ((DWORD)0xC0000BC7L)

//
// MessageId: LDPRFMSG_UNABLE_UPDATE_VALUE
//
// MessageText:
//
//  Cannot update %1!s! value of %2!s! key. The error code is the first DWORD in
//  Data section, updated value is the second DWORD in Data section.
//
#define LDPRFMSG_UNABLE_UPDATE_VALUE     ((DWORD)0xC0000BC8L)

//
// MessageId: LDPRFMSG_UNABLE_QUERY_VALUE
//
// MessageText:
//
//  Cannot update %1!s! value of %2!s! key. The error code is the first DWORD in
//  Data section.
//
#define LDPRFMSG_UNABLE_QUERY_VALUE      ((DWORD)0xC0000BC9L)

//
// MessageId: LDPRFMSG_CORRUPT_INDEX_RANGE
//
// MessageText:
//
//  %1!s! index range of service %2!s! is corrupted. The first DWORD in Data
//  section contains the first index used while the second DWORD in Data section
//  contains last index used.
//
#define LDPRFMSG_CORRUPT_INDEX_RANGE     ((DWORD)0xC0000BCAL)

#endif //_LDPRFMSG_H_
