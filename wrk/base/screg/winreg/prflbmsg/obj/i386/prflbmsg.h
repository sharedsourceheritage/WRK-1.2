/*++ BUILD Version: 0001    // Increment this if a change has global effects

Copyright (c) 1992-1994  Microsoft Corporation

Module Name:

    perflib.h
       (generated from perflib.mc)

Abstract:

   Event message definitions used by routines in Perflib

Created:

    31-Oct-95 Bob Watson

Revision History:

--*/
#ifndef _PRFLBMSG_H_
#define _PRFLBMSG_H_

//
//     Perflib ERRORS
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
// MessageId: PERFLIB_ACCESS_DENIED
//
// MessageText:
//
//  Access to performance data was denied to %1!s! as attempted from
//  %2!s!
//
#define PERFLIB_ACCESS_DENIED            ((DWORD)0xC00003E8L)

//
// MessageId: PERFLIB_BUFFER_OVERFLOW
//
// MessageText:
//
//  The buffer size returned by a collect procedure in Extensible Counter
//  DLL "%1!s!" for the "%2!s!" service was larger than the space
//  available. Performance data returned by counter DLL will be not be
//  returned in Perf Data Block. The returned buffer size is the first
//  DWORD in the attached data.
//
#define PERFLIB_BUFFER_OVERFLOW          ((DWORD)0xC00003E9L)

//
// MessageId: PERFLIB_GUARD_PAGE_VIOLATION
//
// MessageText:
//
//  A Guard Page was modified by a collect procedure in Extensible
//  Counter DLL "%1!s!" for the "%2!s!" service. Performance data
//  returned by counter DLL will be not be returned in Perf Data Block.
//
#define PERFLIB_GUARD_PAGE_VIOLATION     ((DWORD)0xC00003EAL)

//
// MessageId: PERFLIB_INCORRECT_OBJECT_LENGTH
//
// MessageText:
//
//  The object length of an object returned by Extensible Counter DLL
//  "%1!s!" for the "%2!s!" service was not correct. The sum of the
//  object lengths returned did not match the size of the buffer
//  returned.  Performance data returned by counter DLL will be not be
//  returned in Perf Data Block. The count of objects returned is the
//  first DWORD in the attached data.
//
#define PERFLIB_INCORRECT_OBJECT_LENGTH  ((DWORD)0xC00003EBL)

//
// MessageId: PERFLIB_INCORRECT_INSTANCE_LENGTH
//
// MessageText:
//
//  The instance length of an object returned by Extensible Counter
//  DLL "%1!s!" for the "%2!s!" service was incorrect. The sum of the
//  instance lengths plus the object definition structures did not match
//  the size of the object. Performance data returned by counter DLL will
//  be not be returned in Perf Data Block. The object title index of the
//  bad object is the first DWORD in the attached data.
//
#define PERFLIB_INCORRECT_INSTANCE_LENGTH ((DWORD)0xC00003ECL)

//
// MessageId: PERFLIB_OPEN_PROC_NOT_FOUND
//
// MessageText:
//
//  Unable to locate the open procedure "%1!s!" in DLL "%2!s!" for
//  the "%3!s!" service. Performance data for this service will not be
//  available. The Error Status is the first DWORD in the attached
//  data.
//
#define PERFLIB_OPEN_PROC_NOT_FOUND      ((DWORD)0xC00003EDL)

//
// MessageId: PERFLIB_COLLECT_PROC_NOT_FOUND
//
// MessageText:
//
//  Unable to locate the collect procedure "%1!s!" in DLL "%2!s!" for the
//  "%3!s!" service. Performance data for this service will not be
//  available. The Error Status is the first DWORD in the attached
//  data.
//
#define PERFLIB_COLLECT_PROC_NOT_FOUND   ((DWORD)0xC00003EEL)

//
// MessageId: PERFLIB_CLOSE_PROC_NOT_FOUND
//
// MessageText:
//
//  Unable to locate the close procedure "%1!s!" in DLL "%2!s!" for the
//  "%3!s!" service. Performance data for this service will not be
//  available. The Error Status is the first DWORD in the attached
//  data.
//
#define PERFLIB_CLOSE_PROC_NOT_FOUND     ((DWORD)0xC00003EFL)

//
// MessageId: PERFLIB_OPEN_PROC_FAILURE
//
// MessageText:
//
//  The Open Procedure for service "%1!s!" in DLL "%2!s!" failed.
//  Performance data for this service will not be available. The Status code
//  returned is the first DWORD in the attached data.
//
#define PERFLIB_OPEN_PROC_FAILURE        ((DWORD)0xC00003F0L)

//
// MessageId: PERFLIB_OPEN_PROC_EXCEPTION
//
// MessageText:
//
//  The Open Procedure for service "%1!s!" in DLL "%2!s!" generated an
//  exception. Performance data for this service will not be available.
//  The Exception code returned is the first DWORD in the attached data.
//
#define PERFLIB_OPEN_PROC_EXCEPTION      ((DWORD)0xC00003F1L)

//
// MessageId: PERFLIB_COLLECT_PROC_EXCEPTION
//
// MessageText:
//
//  The Collect Procedure for the "%1!s!" service in DLL "%2!s!" generated an
//  exception or returned an invalid status. Performance data returned by
//  counter DLL will be not be returned in Perf Data Block. The exception or
//  status code returned is the first DWORD in the attached data.
//
#define PERFLIB_COLLECT_PROC_EXCEPTION   ((DWORD)0xC00003F2L)

//
// MessageId: PERFLIB_HEAP_ERROR
//
// MessageText:
//
//  The collect procedure in Extensible Counter DLL "%1!s!" for the "%2!s!"
//  service returned a buffer that was larger than the space allocated and
//  may have corrupted the application's heap. This DLL should be disabled
//  or removed from the system until the problem has been corrected to
//  prevent further corruption. The application accessing this performance
//  data should be restarted.  The Performance data returned by counter
//  DLL will be not be returned in Perf Data Block. The Overflow size is
//  the first DWORD in the attached data.
//
#define PERFLIB_HEAP_ERROR               ((DWORD)0xC00003F5L)

//
// MessageId: PERFLIB_COLLECTION_HUNG
//
// MessageText:
//
//  The timeout waiting for the performance data collection function "%1!s!"
//  in the "%2!s!" Library to finish has expired. There may be a problem with
//  this extensible counter or the service it is collecting data from or the
//  system may have been very busy when this call was attempted.
//
#define PERFLIB_COLLECTION_HUNG          ((DWORD)0xC00003F7L)

//
// MessageId: PERFLIB_BUFFER_ALIGNMENT_ERROR
//
// MessageText:
//
//  The data buffer created for the "%1!s!" service in the "%2!s!" library is not
//  aligned on an 8-byte boundary. This may cause problems for applications that are
//  trying to read the performance data buffer. Contact the manufacturer of this
//  library or service to have this problem corrected or to get a newer version
//  of this library.
//
#define PERFLIB_BUFFER_ALIGNMENT_ERROR   ((DWORD)0x800003F8L)

//
// MessageId: PERFLIB_LIBRARY_DISABLED
//
// MessageText:
//
//  Performance counter data collection from the "%1!s!" service has been disabled
//  due to one or more errors generated by the performance counter library for that
//  service. The error(s) that forced this action have been written to the application
//  event log. The error(s) should be corrected before the performance counters
//  for this service are enabled again.
//
#define PERFLIB_LIBRARY_DISABLED         ((DWORD)0xC00003F9L)

//
// MessageId: PERFLIB_LIBRARY_TEMP_DISABLED
//
// MessageText:
//
//  Performance counter data collection from the "%1!s!" service has been disabled
//  for this session due to one or more errors generated by the performance counter
//  library for that service. The error(s) that forced this action have been written
//  to the application event log.
//
#define PERFLIB_LIBRARY_TEMP_DISABLED    ((DWORD)0xC00003FAL)

//
// MessageId: PERFLIB_INVALID_DEFINITION_BLOCK
//
// MessageText:
//
//  A definition field in an object returned by Extensible Counter
//  DLL "%1!s!" for the "%2!s!" service was incorrect. The sum of the
//  definitions block lengths in the object definition structures did not
//  match the size specified in the object definition header. Performance data
//  returned by this counter DLL will be not be returned in Perf Data Block.
//  The object title index of the bad object is the first DWORD in the attached
//  data.
//
#define PERFLIB_INVALID_DEFINITION_BLOCK ((DWORD)0xC00003FBL)

//
// MessageId: PERFLIB_INVALID_SIZE_RETURNED
//
// MessageText:
//
//  The size of the buffer used is greater than that passed to the collect
//  function of the "%1!s!" Extensible Counter DLL for the "%2!s!" service.
//  The size of the buffer passed in is the first DWORD and the size returned
//  is the second DWORD in the attached data.
//
#define PERFLIB_INVALID_SIZE_RETURNED    ((DWORD)0xC00003FCL)

//
// MessageId: PERFLIB_INVALID_WOW32_PERF_DLL
//
// MessageText:
//
//  Windows cannot open the 32-bit extensible counter DLL %1 in a 64-bit environment.
//  Contact the file vendor to obtain a 64-bit version.
//  Alternatively, you can open the 32-bit extensible counter DLL by using the 32-bit version
//  of Performance Monitor. To use this tool, open the Windows folder, open the Syswow64 folder,
//  and then start Perfmon.exe.
//
#define PERFLIB_INVALID_WOW32_PERF_DLL   ((DWORD)0xC00003FDL)

//
// MessageId: PERFLIB_INVALID_IA64_PERF_DLL
//
// MessageText:
//
//  Windows cannot open the 64-bit extensible counter DLL %1 in a 32-bit environment.
//  Contact the file vendor to obtain a 32-bit version.
//  Alternatively if you are running a 64-bit native environment, you can open the 64-bit extensible
//  counter DLL by using the 64-bit version of Performance Monitor.
//  To use this tool, open the Windows folder, open the System32 folder, and then start Perfmon.exe.
//
#define PERFLIB_INVALID_IA64_PERF_DLL    ((DWORD)0xC00003FEL)

//
// MessageId: PERFLIB_BUFFER_POINTER_MISMATCH
//
// MessageText:
//
//  The pointer returned did not match the buffer length returned by the
//  Collect procedure for the "%1!s!" service in Extensible Counter DLL
//  "%2!s!". The Length will be adjusted to match and the performance
//  data will appear in the Perf Data Block. The returned length is the first
//  DWORD, the new length is the second DWORD in the attached data.
//
#define PERFLIB_BUFFER_POINTER_MISMATCH  ((DWORD)0x800007D0L)

//
// MessageId: PERFLIB_NO_PERFORMANCE_SUBKEY
//
// MessageText:
//
//  The "%1!s!" service does not have a Performance subkey or the key
//  could not be opened. No performance counters will be collected for
//  this service. The Win32 error code is returned in the first DWORD in
//  the attached data.
//
#define PERFLIB_NO_PERFORMANCE_SUBKEY    ((DWORD)0x800007D1L)

//
// MessageId: PERFLIB_OPEN_PROC_TIMEOUT
//
// MessageText:
//
//  The open procedure for service "%1!s!" in DLL "%2!s!" has taken longer than
//  the established wait time to complete. There may be a problem with
//  this extensible counter or the service it is collecting data from or the
//  system may have been very busy when this call was attempted.
//
#define PERFLIB_OPEN_PROC_TIMEOUT        ((DWORD)0x800007D2L)

//
// MessageId: PERFLIB_NOT_TRUSTED_FILE
//
// MessageText:
//
//  The configuration information of the performance library "%1!s!" for the
//  "%2!s!" service does not match the trusted performance library information
//  stored in the registry. The functions in this library will not be treated
//  as trusted.
//
#define PERFLIB_NOT_TRUSTED_FILE         ((DWORD)0x800007D3L)

//
// MessageId: PERFLIB_TOO_MANY_OBJECTS
//
// MessageText:
//
//  The number of objects allowed in a performance library has exceed the
//  maximum supported.
//
#define PERFLIB_TOO_MANY_OBJECTS         ((DWORD)0xC0000BBAL)

//
// MessageId: PERFLIB_PROC_NAME_NOT_FOUND
//
// MessageText:
//
//  Unable to find the %1!s! Procedure name in the registry for service "%2!s!".
//  Please check the application event log to make sure there were no problems
//  encountered during installation of the "%2!s!" service and re-install its
//  performance counter DLL.
//
#define PERFLIB_PROC_NAME_NOT_FOUND      ((DWORD)0xC0000BBBL)

//
// MessageId: PERFLIB_REGVALUE_NOT_FOUND
//
// MessageText:
//
//  Unable to find valid registry value "%1!s!" in the registry for service "%2!s!".
//  Please check the application event log to make sure there were no problems
//  encountered during installation of the "%2!s!" service and re-install its
//  performance counter DLL.
//
#define PERFLIB_REGVALUE_NOT_FOUND       ((DWORD)0xC0000BBCL)


#endif //_PRFLBMSG_H_
