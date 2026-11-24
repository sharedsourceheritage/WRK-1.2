
/*--

Copyright (c) 2000  Microsoft Corporation

Module Name:

    msg.mc

Abstract:

    This file contains the message definitions

Author:

    Wesley Witt (wesw) 11-February-2000

Revision History:

Notes:

--*/


#define MSG_FIRST_MESSAGE_ID   MSG_USAGE
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
// MessageId: MSG_USAGE
//
// MessageText:
//
//  ---- Commands Supported ----
//  
//  behavior        Control file system behavior
//  dirty           Manage volume dirty bit
//  file            File specific commands
//  fsinfo          File system information
//  hardlink        Hardlink management
//  objectid        Object ID management
//  quota           Quota management
//  reparsepoint    Reparse point management
//  sparse          Sparse file control
//  usn             USN management
//  volume          Volume management
//
#define MSG_USAGE                        0x40002710L

//
// MessageId: MSG_ERROR
//
// MessageText:
//
//  Error: %0
//
#define MSG_ERROR                        0x40002711L

//
// MessageId: MSG_DRIVES
//
// MessageText:
//
//  Drives: %0
//
#define MSG_DRIVES                       0x40002712L

//
// MessageId: MSG_USAGE_DRIVETYPE
//
// MessageText:
//
//  Usage : fsutil fsinfo drivetype <volume pathname>
//     Eg : fsutil fsinfo drivetype C:
//
#define MSG_USAGE_DRIVETYPE              0x40002713L

//
// MessageId: MSG_DRIVE_UNKNOWN
//
// MessageText:
//
//  %1 - Unknown Drive
//
#define MSG_DRIVE_UNKNOWN                0x40002714L

//
// MessageId: MSG_DRIVE_NO_ROOT_DIR
//
// MessageText:
//
//  %1 - No such Root Directory
//
#define MSG_DRIVE_NO_ROOT_DIR            0x40002715L

//
// MessageId: MSG_DRIVE_REMOVABLE
//
// MessageText:
//
//  %1 - Removable Drive
//
#define MSG_DRIVE_REMOVABLE              0x40002716L

//
// MessageId: MSG_DRIVE_FIXED
//
// MessageText:
//
//  %1 - Fixed Drive
//
#define MSG_DRIVE_FIXED                  0x40002717L

//
// MessageId: MSG_DRIVE_REMOTE
//
// MessageText:
//
//  %1 - Remote/Network Drive
//
#define MSG_DRIVE_REMOTE                 0x40002718L

//
// MessageId: MSG_DRIVE_CDROM
//
// MessageText:
//
//  %1 - CD-ROM Drive
//
#define MSG_DRIVE_CDROM                  0x40002719L

//
// MessageId: MSG_DRIVE_RAMDISK
//
// MessageText:
//
//  %1 - Ram Disk
//
#define MSG_DRIVE_RAMDISK                0x4000271AL

//
// MessageId: MSG_USAGE_INFOV
//
// MessageText:
//
//  Usage : fsutil fsinfo volumeinfo <volume pathname>
//     Eg : fsutil fsinfo volumeinfo C:\
//
#define MSG_USAGE_INFOV                  0x4000271BL

//
// MessageId: MSG_FILE_CASE_SENSITIVE_SEARCH
//
// MessageText:
//
//  Supports Case-sensitive filenames
//
#define MSG_FILE_CASE_SENSITIVE_SEARCH   0x4000271CL

//
// MessageId: MSG_FILE_CASE_PRESERVED_NAMES
//
// MessageText:
//
//  Preserves Case of filenames
//
#define MSG_FILE_CASE_PRESERVED_NAMES    0x4000271DL

//
// MessageId: MSG_FILE_UNICODE_ON_DISK
//
// MessageText:
//
//  Supports Unicode in filenames
//
#define MSG_FILE_UNICODE_ON_DISK         0x4000271EL

//
// MessageId: MSG_FILE_PERSISTENT_ACLS
//
// MessageText:
//
//  Preserves & Enforces ACL's
//
#define MSG_FILE_PERSISTENT_ACLS         0x4000271FL

//
// MessageId: MSG_FILE_FILE_COMPRESSION
//
// MessageText:
//
//  Supports file-based Compression
//
#define MSG_FILE_FILE_COMPRESSION        0x40002720L

//
// MessageId: MSG_FILE_VOLUME_QUOTAS
//
// MessageText:
//
//  Supports Disk Quotas
//
#define MSG_FILE_VOLUME_QUOTAS           0x40002721L

//
// MessageId: MSG_FILE_SUPPORTS_SPARSE_FILES
//
// MessageText:
//
//  Supports Sparse files
//
#define MSG_FILE_SUPPORTS_SPARSE_FILES   0x40002722L

//
// MessageId: MSG_FILE_SUPPORTS_REPARSE_POINTS
//
// MessageText:
//
//  Supports Reparse Points
//
#define MSG_FILE_SUPPORTS_REPARSE_POINTS 0x40002723L

//
// MessageId: MSG_FILE_SUPPORTS_REMOTE_STORAGE
//
// MessageText:
//
//  Supports Remote Storage
//
#define MSG_FILE_SUPPORTS_REMOTE_STORAGE 0x40002724L

//
// MessageId: MSG_FILE_VOLUME_IS_COMPRESSED
//
// MessageText:
//
//  Compressed volume
//
#define MSG_FILE_VOLUME_IS_COMPRESSED    0x40002725L

//
// MessageId: MSG_FILE_SUPPORTS_OBJECT_IDS
//
// MessageText:
//
//  Supports Object Identifiers
//
#define MSG_FILE_SUPPORTS_OBJECT_IDS     0x40002726L

//
// MessageId: MSG_FILE_SUPPORTS_ENCRYPTION
//
// MessageText:
//
//  Supports Encrypted File System
//
#define MSG_FILE_SUPPORTS_ENCRYPTION     0x40002727L

//
// MessageId: MSG_FILE_NAMED_STREAMS
//
// MessageText:
//
//  Supports Named Streams
//
#define MSG_FILE_NAMED_STREAMS           0x40002728L

//
// MessageId: MSG_VOLNAME
//
// MessageText:
//
//  Volume Name : %1
//
#define MSG_VOLNAME                      0x40002729L

//
// MessageId: MSG_SERIALNO
//
// MessageText:
//
//  Volume Serial Number : 0x%1!x!
//
#define MSG_SERIALNO                     0x4000272AL

//
// MessageId: MSG_MAX_COMP_LEN
//
// MessageText:
//
//  Max Component Length : %1!d!
//
#define MSG_MAX_COMP_LEN                 0x4000272BL

//
// MessageId: MSG_FS_NAME
//
// MessageText:
//
//  File System Name : %1
//
#define MSG_FS_NAME                      0x4000272CL

//
// MessageId: MSG_USAGE_DF
//
// MessageText:
//
//  Usage : fsutil volume diskfree <volume pathname>
//     Eg : fsutil volume diskfree C:
//
#define MSG_USAGE_DF                     0x4000272DL

//
// MessageId: MSG_DISKFREE
//
// MessageText:
//
//  Total # of free bytes        : %1
//  Total # of bytes             : %2
//  Total # of avail free bytes  : %3
//
#define MSG_DISKFREE                     0x4000272EL

//
// MessageId: MSG_COULD_NOT_OPEN_EVENTLOG
//
// MessageText:
//
//  Error opening handle for eventlog
//
#define MSG_COULD_NOT_OPEN_EVENTLOG      0x4000272FL

//
// MessageId: MSG_SEARCHING_EVENTLOG
//
// MessageText:
//
//  Searching in %1 Event Log...
//
#define MSG_SEARCHING_EVENTLOG           0x40002730L

//
// MessageId: MSG_QUOTA_THREASHOLD
//
// MessageText:
//
//  **** A user hit their quota threshold ! ****
//
#define MSG_QUOTA_THREASHOLD             0x40002731L

//
// MessageId: MSG_QUOTA_LIMIT
//
// MessageText:
//
//  **** A user hit their quota limit ! ****
//
#define MSG_QUOTA_LIMIT                  0x40002732L

//
// MessageId: MSG_EVENT_ID
//
// MessageText:
//
//      Event ID  : 0x%1!x!
//
#define MSG_EVENT_ID                     0x40002733L

//
// MessageId: MSG_EVENT_TYPE_ERROR
//
// MessageText:
//
//      EventType : Error
//
#define MSG_EVENT_TYPE_ERROR             0x40002734L

//
// MessageId: MSG_EVENT_TYPE_WARNING
//
// MessageText:
//
//      EventType : Warning
//
#define MSG_EVENT_TYPE_WARNING           0x40002735L

//
// MessageId: MSG_EVENT_TYPE_INFORMATION
//
// MessageText:
//
//      EventType : Information
//
#define MSG_EVENT_TYPE_INFORMATION       0x40002736L

//
// MessageId: MSG_EVENT_TYPE_AUDIT_SUCCESS
//
// MessageText:
//
//      EventType : Audit success
//
#define MSG_EVENT_TYPE_AUDIT_SUCCESS     0x40002737L

//
// MessageId: MSG_EVENT_TYPE_AUDIT_FAILURE
//
// MessageText:
//
//      EventType : Audit failure
//
#define MSG_EVENT_TYPE_AUDIT_FAILURE     0x40002738L

//
// MessageId: MSG_EVENT_CATEGORY
//
// MessageText:
//
//      Event Category : %1!d!
//
#define MSG_EVENT_CATEGORY               0x40002739L

//
// MessageId: MSG_EVENT_SOURCE
//
// MessageText:
//
//      Source : %1
//
#define MSG_EVENT_SOURCE                 0x4000273AL

//
// MessageId: MSG_EVENT_DATA
//
// MessageText:
//
//      Data: %1
//
#define MSG_EVENT_DATA                   0x4000273BL

//
// MessageId: MSG_GOOD_QUOTA
//
// MessageText:
//
//  No quota violations detected
//
#define MSG_GOOD_QUOTA                   0x4000273CL

//
// MessageId: MSG_USERNAME
//
// MessageText:
//
//      User: %1\%2
//
#define MSG_USERNAME                     0x4000273DL

//
// MessageId: MSG_USAGE_RQUERYVK
//
// MessageText:
//
//  Usage : fsutil behavior query <option>
//  
//  <option>
//  
//  disable8dot3
//  allowextchar
//  disablelastaccess
//  quotanotify
//  mftzone
//  memoryusage
//
#define MSG_USAGE_RQUERYVK               0x4000273EL

//
// MessageId: MSG_USAGE_RSETVK
//
// MessageText:
//
//  Usage : fsutil behavior set <option> <value>
//  
//  <option>               <values>
//  
//  disable8dot3           1 | 0
//  allowextchar           1 | 0
//  disablelastaccess      1 | 0
//  quotanotify            1 through 4294967295 seconds
//  mftzone                1 through 4
//  memoryusage            1 through 2
//
#define MSG_USAGE_RSETVK                 0x4000273FL

//
// MessageId: MSG_USAGE_DISMOUNTV
//
// MessageText:
//
//  Usage : fsutil volume dismount <volume pathname>
//     Eg : fsutil volume dismount C:
//
#define MSG_USAGE_DISMOUNTV              0x40002740L

//
// MessageId: MSG_USAGE_MARKV
//
// MessageText:
//
//  Usage : fsutil dirty set <volume pathname>
//     Eg : fsutil dirty set C:
//
#define MSG_USAGE_MARKV                  0x40002741L

//
// MessageId: MSG_USAGE_GETFSS
//
// MessageText:
//
//  Usage : fsutil fsinfo statistics <volume pathname>
//     Eg : fsutil fsinfo statistics C:
//
#define MSG_USAGE_GETFSS                 0x40002742L

//
// MessageId: MSG_GENERAL_FSSTAT
//
// MessageText:
//
//  
//  UserFileReads :        %1
//  UserFileReadBytes :    %2
//  UserDiskReads :        %3
//  UserFileWrites :       %4
//  UserFileWriteBytes :   %5
//  UserDiskWrites :       %6
//  MetaDataReads :        %7
//  MetaDataReadBytes :    %8
//  MetaDataDiskReads :    %9
//  MetaDataWrites :       %10
//  MetaDataWriteBytes :   %11
//  MetaDataDiskWrites :   %12
//  
//
#define MSG_GENERAL_FSSTAT               0x40002743L

//
// MessageId: MSG_FAT_FSSTA
//
// MessageText:
//
//  CreateHits :           %1
//  SuccesfulCreates :     %2
//  FailedCreates :        %3
//  NonCachedReads :       %4
//  NonCachedRead Bytes :  %5
//  NonCachedWrites :      %6
//  NonCachedWrite Bytes : %7
//  NonCachedDiskReads :   %8
//  NonCachedDiskWrites :  %9
//
#define MSG_FAT_FSSTA                    0x40002744L

//
// MessageId: MSG_NTFS_FSSTA
//
// MessageText:
//
//  MftReads :             %1
//  MftReadBytes :         %2
//  MftWrites :            %3
//  MftWriteBytes :        %4
//  Mft2Writes :           %5
//  Mft2WriteBytes :       %6
//  RootIndexReads :       %7
//  RootIndexReadBytes :   %8
//  RootIndexWrites :      %9
//  RootIndexWriteBytes :  %10
//  BitmapReads :          %11
//  BitmapReadBytes :      %12
//  BitmapWrites :         %13
//  BitmapWriteBytes :     %14
//  MftBitmapReads :       %15
//  MftBitmapReadBytes :   %16
//  MftBitmapWrites :      %17
//  MftBitmapWriteBytes :  %18
//  UserIndexReads :       %19
//  UserIndexReadBytes :   %20
//  UserIndexWrites :      %21
//  UserIndexWriteBytes :  %22
//  LogFileReads :         %23
//  LogFileReadBytes :     %24
//  LogFileWrites :        %25
//  LogFileWriteBytes :    %26
//
#define MSG_NTFS_FSSTA                   0x40002745L

//
// MessageId: MSG_FSTYPE_FAT
//
// MessageText:
//
//  File System Type :     FAT
//
#define MSG_FSTYPE_FAT                   0x40002746L

//
// MessageId: MSG_FSTYPE_NTFS
//
// MessageText:
//
//  File System Type :     NTFS
//
#define MSG_FSTYPE_NTFS                  0x40002747L

//
// MessageId: MSG_USAGE_VALID_DATA
//
// MessageText:
//
//  Usage : fsutil file setvaliddata <filename> <datalength>
//     Eg : fsutil file setvaliddata C:\testfile.txt 4096
//
#define MSG_USAGE_VALID_DATA             0x40002748L

//
// MessageId: MSG_USAGE_SHORTNAME
//
// MessageText:
//
//  Usage : fsutil file setshortname <filename> <shortname>
//     Eg : fsutil file setshortname C:\testfile.txt testfile
//
#define MSG_USAGE_SHORTNAME              0x40002749L

//
// MessageId: MSG_NTFS_REQUIRED
//
// MessageText:
//
//  The FSUTIL utility requires a local NTFS volume.
//
#define MSG_NTFS_REQUIRED                0x4000274AL

//
// MessageId: MSG_ALLOCRANGE_USAGE
//
// MessageText:
//
//  Usage : fsutil file queryallocranges offset=<val> length=<val> <filename>
//      offset : File Offset, the start of the range to query
//      length : Size, in bytes, of the range
//      Eg : fsutil file queryallocranges offset=1024 length=64 C:\Temp\sample.txt
//
#define MSG_ALLOCRANGE_USAGE             0x4000274BL

//
// MessageId: MSG_ALLOCRANGE_RANGES
//
// MessageText:
//
//  ** Range : %1!d! **
//  Starting Offset : 0x%2
//  Length in bytes : 0x%3
//
#define MSG_ALLOCRANGE_RANGES            0x4000274CL

//
// MessageId: MSG_SETZERO_USAGE
//
// MessageText:
//
//  Usage : fsutil file setzerodata offset=<val> length=<val> <filename>
//      offset : File offset, the start of the range to set to zeroes
//      length : Byte length of the zeroed range
//          Eg : fsutil file setzerodata offset=100 length=150 C:\Temp\sample.txt
//
#define MSG_SETZERO_USAGE                0x4000274DL

//
// MessageId: MSG_SETSPARSE_USAGE
//
// MessageText:
//
//  Usage : fsutil sparse setflag <filename>
//     Eg : fsutil sparse setflag C:\Temp\sample.txt
//
#define MSG_SETSPARSE_USAGE              0x4000274EL

//
// MessageId: MSG_USAGE_NTFSINFO
//
// MessageText:
//
//  Usage : fsutil fsinfo ntfsinfo <volume pathname>
//     Eg : fsutil fsinfo ntfsinfo C:
//
#define MSG_USAGE_NTFSINFO               0x4000274FL

//
// MessageId: MSG_NTFSINFO_STATS
//
// MessageText:
//
//  NTFS Volume Serial Number :       0x%1
//  Version :                         %2!d!.%3!d!
//  Number Sectors :                  0x%4
//  Total Clusters :                  0x%5
//  Free Clusters  :                  0x%6
//  Total Reserved :                  0x%7
//  Bytes Per Sector  :               %8!d!
//  Bytes Per Cluster :               %9!d!
//  Bytes Per FileRecord Segment    : %10!d!
//  Clusters Per FileRecord Segment : %11!d!
//  Mft Valid Data Length :           0x%12
//  Mft Start Lcn  :                  0x%13
//  Mft2 Start Lcn :                  0x%14
//  Mft Zone Start :                  0x%15
//  Mft Zone End   :                  0x%16
//
#define MSG_NTFSINFO_STATS               0x40002750L

//
// MessageId: MSG_USAGE_ISVDIRTY
//
// MessageText:
//
//  Usage : fsutil dirty query <volume pathname>
//     Eg : fsutil dirty query  C:
//
#define MSG_USAGE_ISVDIRTY               0x40002751L

//
// MessageId: MSG_ISVDIRTY_YES
//
// MessageText:
//
//  Volume - %1!s! is Dirty
//
#define MSG_ISVDIRTY_YES                 0x40002752L

//
// MessageId: MSG_ISVDIRTY_NO
//
// MessageText:
//
//  Volume - %1!s! is NOT Dirty
//
#define MSG_ISVDIRTY_NO                  0x40002753L

//
// MessageId: MSG_USAGE_GETREPARSE
//
// MessageText:
//
//  Usage : fsutil reparsepoint query <filename>
//     Eg : fsutil reparsepoint query C:\Server
//
#define MSG_USAGE_GETREPARSE             0x40002754L

//
// MessageId: MSG_GETREPARSE_TAGVAL
//
// MessageText:
//
//  Reparse Tag Value : 0x%1!08x!
//
#define MSG_GETREPARSE_TAGVAL            0x40002755L

//
// MessageId: MSG_TAG_MICROSOFT
//
// MessageText:
//
//  Tag value: Microsoft
//
#define MSG_TAG_MICROSOFT                0x40002756L

//
// MessageId: MSG_TAG_NAME_SURROGATE
//
// MessageText:
//
//  Tag value: Name Surrogate
//
#define MSG_TAG_NAME_SURROGATE           0x40002757L

//
// MessageId: MSG_TAG_SYMBOLIC_LINK
//
// MessageText:
//
//  Tag value: Symbolic Link
//
#define MSG_TAG_SYMBOLIC_LINK            0x40002758L

//
// MessageId: MSG_TAG_MOUNT_POINT
//
// MessageText:
//
//  Tag value: Mount Point
//
#define MSG_TAG_MOUNT_POINT              0x40002759L

//
// MessageId: MSG_TAG_HSM
//
// MessageText:
//
//  Tag value: HSM
//
#define MSG_TAG_HSM                      0x4000275AL

//
// MessageId: MSG_TAG_SIS
//
// MessageText:
//
//  Tag value: SIS
//
#define MSG_TAG_SIS                      0x4000275BL

//
// MessageId: MSG_TAG_FILTER_MANAGER
//
// MessageText:
//
//  Tag value: Filter Manager
//
#define MSG_TAG_FILTER_MANAGER           0x4000275CL

//
// MessageId: MSG_TAG_DFS
//
// MessageText:
//
//  Tag value: DFS
//
#define MSG_TAG_DFS                      0x4000275DL

//
// MessageId: MSG_GETREPARSE_GUID
//
// MessageText:
//
//  GUID : %1!s!
//
#define MSG_GETREPARSE_GUID              0x4000275EL

//
// MessageId: MSG_GETREPARSE_DATA
//
// MessageText:
//
//  Reparse Data:
//
#define MSG_GETREPARSE_DATA              0x4000275FL

//
// MessageId: MSG_DELETE_REPARSE
//
// MessageText:
//
//  Usage : fsutil reparsepoint delete <filename>
//     Eg : fsutil reparsepoint delete C:\Server
//
#define MSG_DELETE_REPARSE               0x40002760L

//
// MessageId: MSG_USAGE_SETOBJECTID
//
// MessageText:
//
//  Usage : fsutil objectid set <ObjectId> <BirthVolumeId> <BirthObjectId> <DomainId> <filename>
//   ObjectId      : 32-digit hexadecimal data
//   BirthVolumeId : 32-digit hexadecimal data
//   BirthObjectId : 32-digit hexadecimal data
//   DomainId      : 32-digit hexadecimal data
//   All values must be in Hex of the form 40dff02fc9b4d4118f120090273fa9fc
//     Eg : fsutil objectid set 40dff02fc9b4d4118f120090273fa9fc
//                              f86ad6865fe8d21183910008c709d19e
//                              40dff02fc9b4d4118f120090273fa9fc
//                              00000000000000000000000000000000 C:\Temp\sample.txt
//
#define MSG_USAGE_SETOBJECTID            0x40002761L

//
// MessageId: MSG_USAGE_GETOBJECTID
//
// MessageText:
//
//  Usage : fsutil objectid query <filename>
//     Eg : fsutil objectid query C:\Temp\sample.txt
//
#define MSG_USAGE_GETOBJECTID            0x40002762L

//
// MessageId: MSG_USAGE_CREATEOBJECTID
//
// MessageText:
//
//  Usage : fsutil objectid create <filename>
//     Eg : fsutil objectid create C:\Temp\sample.txt
//
#define MSG_USAGE_CREATEOBJECTID         0x40002763L

//
// MessageId: MSG_USAGE_DELETEOBJECTID
//
// MessageText:
//
//  Usage : fsutil objectid delete <filename>
//     Eg : fsutil objectid delete C:\Temp\sample.txt
//
#define MSG_USAGE_DELETEOBJECTID         0x40002764L

//
// MessageId: MSG_OBJECTID_TEXT
//
// MessageText:
//
//  Object ID :        %0
//
#define MSG_OBJECTID_TEXT                0x40002765L

//
// MessageId: MSG_BIRTHVOLID_TEXT
//
// MessageText:
//
//  BirthVolume ID :   %0
//
#define MSG_BIRTHVOLID_TEXT              0x40002766L

//
// MessageId: MSG_BIRTHOBJECTID_TEXT
//
// MessageText:
//
//  BirthObjectId ID : %0
//
#define MSG_BIRTHOBJECTID_TEXT           0x40002767L

//
// MessageId: MSG_DOMAINID_TEXT
//
// MessageText:
//
//  Domain ID :        %0
//
#define MSG_DOMAINID_TEXT                0x40002768L

//
// MessageId: MSG_USAGE_CREATEUSN
//
// MessageText:
//
//  Usage : fsutil usn createjournal m=<max-value> a=<alloc-delta> <volume pathname>
//     Eg : fsutil usn createjournal m=1000 a=100 C:
//
#define MSG_USAGE_CREATEUSN              0x40002769L

//
// MessageId: MSG_USNRECORD
//
// MessageText:
//
//  
//  Major Version    : 0x%1!x!
//  Minor Version    : 0x%2!x!
//  FileRef#         : 0x%3
//  Parent FileRef#  : 0x%4
//  Usn              : 0x%5
//  Time Stamp       : 0x%6 %7 %8
//  Reason           : 0x%9!lx!
//  Source Info      : 0x%10!lx!
//  Security Id      : 0x%11!lx!
//  File Attributes  : 0x%12!lx!
//  File Name Length : 0x%13!x!
//  File Name Offset : 0x%14!x!
//  FileName         : %15!.*ws!
//
#define MSG_USNRECORD                    0x4000276AL

//
// MessageId: MSG_USAGE_QUERYUSN
//
// MessageText:
//
//  Usage : fsutil usn queryjournal <volume pathname>
//     Eg : fsutil usn queryjournal C:
//
#define MSG_USAGE_QUERYUSN               0x4000276BL

//
// MessageId: MSG_QUERYUSN
//
// MessageText:
//
//  Usn Journal ID   : 0x%1
//  First Usn        : 0x%2
//  Next Usn         : 0x%3
//  Lowest Valid Usn : 0x%4
//  Max Usn          : 0x%5
//  Maximum Size     : 0x%6
//  Allocation Delta : 0x%7
//
#define MSG_QUERYUSN                     0x4000276CL

//
// MessageId: MSG_USAGE_DELETEUSN
//
// MessageText:
//
//  Usage : fsutil usn deletejournal <flags> <volume pathname>
//  <Flags>
//    /D : Delete
//    /N : Notify
//    Eg : usn deletejournal /D C:
//
#define MSG_USAGE_DELETEUSN              0x4000276DL

//
// MessageId: MSG_USAGE_ENUMDATA
//
// MessageText:
//
//  Usage : fsutil usn enumdata <file ref#> <lowUsn> <highUsn> <volume pathname>
//     Eg : fsutil usn enumdata 1 0 1 C:\
//
#define MSG_USAGE_ENUMDATA               0x4000276EL

//
// MessageId: MSG_ENUMDATA
//
// MessageText:
//
//  File Ref#       : 0x%1
//  ParentFile Ref# : 0x%2
//  Usn             : 0x%3
//  SecurityId      : 0x%4!08x!
//  Reason          : 0x%5!08x!
//  Name (%6!03d!)      : %7!.*ws!
//  
//
#define MSG_ENUMDATA                     0x4000276FL

//
// MessageId: MSG_USAGE_READDATA
//
// MessageText:
//
//  Usage : fsutil usn readdata <filename>
//     Eg : fsutil usn readdata C:\Temp\sample.txt
//
#define MSG_USAGE_READDATA               0x40002770L

//
// MessageId: MSG_USAGE_FINDBYSID
//
// MessageText:
//
//  Usage : fsutil file findbysid <user> <directory>
//     Eg : fsutil file findbysid scottb C:\users
//
#define MSG_USAGE_FINDBYSID              0x40002771L

//
// MessageId: MSG_USAGE_BEHAVIOR
//
// MessageText:
//
//  ---- BEHAVIOR Commands Supported ----
//  
//  query           Query the file system behavior parameters
//  set             Change the file system behavior parameters
//
#define MSG_USAGE_BEHAVIOR               0x40002772L

//
// MessageId: MSG_BEHAVIOR_OUTPUT
//
// MessageText:
//
//  %1 = %2!u!
//
#define MSG_BEHAVIOR_OUTPUT              0x40002773L

//
// MessageId: MSG_BEHAVIOR_OUTPUT_NOT_SET
//
// MessageText:
//
//  %1 is not currently set
//
#define MSG_BEHAVIOR_OUTPUT_NOT_SET      0x40002774L

//
// MessageId: MSG_USAGE_DIRTY
//
// MessageText:
//
//  ---- DIRTY Commands Supported ----
//  
//  query           Query the dirty bit
//  set             Set the dirty bit
//
#define MSG_USAGE_DIRTY                  0x40002775L

//
// MessageId: MSG_USAGE_FILE
//
// MessageText:
//
//  ---- FILE Commands Supported ----
//  
//  findbysid               Find a file by security identifier
//  queryallocranges        Query the allocated ranges for a file
//  setshortname            Set the short name for a file
//  setvaliddata            Set the valid data length for a file
//  setzerodata             Set the zero data for a file
//  createnew               Creates a new file of a specified size
//
#define MSG_USAGE_FILE                   0x40002776L

//
// MessageId: MSG_USAGE_FSINFO
//
// MessageText:
//
//  ---- FSINFO Commands Supported ----
//  
//  drives          List all drives
//  drivetype       Query drive type for a drive
//  volumeinfo      Query volume information
//  ntfsinfo        Query NTFS specific volume information
//  statistics      Query file system statistics
//
#define MSG_USAGE_FSINFO                 0x40002777L

//
// MessageId: MSG_USAGE_HARDLINK
//
// MessageText:
//
//  ---- HARDLINK Commands Supported ----
//  
//  create          Create a hardlink
//
#define MSG_USAGE_HARDLINK               0x40002778L

//
// MessageId: MSG_USAGE_OBJECTID
//
// MessageText:
//
//  ---- OBJECTID Commands Supported ----
//  
//  query           Query the object identifier
//  set             Change the object identifier
//  delete          Delete the object identifier
//  create          Create the object identifier
//
#define MSG_USAGE_OBJECTID               0x40002779L

//
// MessageId: MSG_USAGE_QUOTA
//
// MessageText:
//
//  ---- QUOTA Commands Supported ----
//  
//  disable         Disable quota tracking and enforcement
//  track           Enable quota tracking
//  enforce         Enable quota enforcement
//  violations      Display quota violations
//  modify          Sets disk quota for a user
//  query           Query disk quotas
//
#define MSG_USAGE_QUOTA                  0x4000277AL

//
// MessageId: MSG_USAGE_REPARSEPOINT
//
// MessageText:
//
//  ---- REPARSEPOINT Commands Supported ----
//  
//  query           Query a reparse point
//  delete          Delete a reparse point
//
#define MSG_USAGE_REPARSEPOINT           0x4000277BL

//
// MessageId: MSG_USAGE_SPARSE
//
// MessageText:
//
//  ---- SPARSE Commands Supported ----
//  
//  setflag         Set sparse
//  queryflag       Query sparse
//  queryrange      Query range
//  setrange        Set sparse range
//
#define MSG_USAGE_SPARSE                 0x4000277CL

//
// MessageId: MSG_USAGE_USN
//
// MessageText:
//
//  ---- USN Commands Supported ----
//  
//  createjournal   Create a USN journal
//  deletejournal   Delete a USN journal
//  enumdata        Enumerate USN data
//  queryjournal    Query the USN data for a volume
//  readdata        Read the USN data for a file
//
#define MSG_USAGE_USN                    0x4000277DL

//
// MessageId: MSG_USAGE_VOLUME
//
// MessageText:
//
//  ---- VOLUME Commands Supported ----
//  
//  dismount        Dismount a volume
//  diskfree        Query the free space of a volume
//
#define MSG_USAGE_VOLUME                 0x4000277EL

//
// MessageId: MSG_USAGE_CREATEFILE
//
// MessageText:
//
//  Usage : fsutil file createnew <filename> <length>
//     Eg : fsutil file createnew C:\testfile.txt 1000
//
#define MSG_USAGE_CREATEFILE             0x4000277FL

//
// MessageId: MSG_ADMIN_REQUIRED
//
// MessageText:
//
//  The FSUTIL utility requires that you have administrative privileges.
//
#define MSG_ADMIN_REQUIRED               0x40002780L

//
// MessageId: MSG_USAGE_HARDLINK_CREATE
//
// MessageText:
//
//  Usage : fsutil hardlink create <new filename> <existing filename>
//     Eg : fsutil hardlink create c:\foo.txt c:\bar.txt
//
#define MSG_USAGE_HARDLINK_CREATE        0x40002781L

//
// MessageId: MSG_HARDLINK_CREATED
//
// MessageText:
//
//  Hardlink created for %1!s! <<===>> %2!s!
//
#define MSG_HARDLINK_CREATED             0x40002782L

//
// MessageId: MSG_CREATEFILE_SUCCEEDED
//
// MessageText:
//
//  File %1!s! is created
//
#define MSG_CREATEFILE_SUCCEEDED         0x40002783L

//
// MessageId: MSG_QUOTA_DUMP_DEFAULT
//
// MessageText:
//
//  Default quota values
//
#define MSG_QUOTA_DUMP_DEFAULT           0x40002784L

//
// MessageId: MSG_QUOTA_SID_USER
//
// MessageText:
//
//  SID Name        = %1!s!\%2!s! (User)
//
#define MSG_QUOTA_SID_USER               0x40002785L

//
// MessageId: MSG_QUOTA_SID_GROUP
//
// MessageText:
//
//  SID Name        = %1!s!\%2!s! (Group)
//
#define MSG_QUOTA_SID_GROUP              0x40002786L

//
// MessageId: MSG_QUOTA_SID_DOMAIN
//
// MessageText:
//
//  SID Name        = %1!s!\%2!s! (Domain)
//
#define MSG_QUOTA_SID_DOMAIN             0x40002787L

//
// MessageId: MSG_QUOTA_SID_ALIAS
//
// MessageText:
//
//  SID Name        = %1!s!\%2!s! (Alias)
//
#define MSG_QUOTA_SID_ALIAS              0x40002788L

//
// MessageId: MSG_QUOTA_SID_WELLKNOWNGROUP
//
// MessageText:
//
//  SID Name        = %1!s!\%2!s! (WellKnownGroup)
//
#define MSG_QUOTA_SID_WELLKNOWNGROUP     0x40002789L

//
// MessageId: MSG_QUOTA_SID_DELETEDACCOUNT
//
// MessageText:
//
//  SID Name        = %1!s!\%2!s! (DeletedAccount)
//
#define MSG_QUOTA_SID_DELETEDACCOUNT     0x4000278AL

//
// MessageId: MSG_QUOTA_SID_INVALID
//
// MessageText:
//
//  SID Name        = %1!s!\%2!s! (Invalid)
//
#define MSG_QUOTA_SID_INVALID            0x4000278BL

//
// MessageId: MSG_QUOTA_SID_UNKNOWN
//
// MessageText:
//
//  SID Name        = %1!s!\%2!s! (Unknown)
//
#define MSG_QUOTA_SID_UNKNOWN            0x4000278CL

//
// MessageId: MSG_QUOTA_DUMP_INFO
//
// MessageText:
//
//  Change time     = %1!s!
//  Quota Used      = %2
//  Quota Threshold = %3
//  Quota Limit     = %4
//  
//
#define MSG_QUOTA_DUMP_INFO              0x4000278DL

//
// MessageId: MSG_USAGE_QUOTA_QUERY
//
// MessageText:
//
//  Usage : fsutil quota query <volume pathname>
//     Eg : fsutil quota query C:
//
#define MSG_USAGE_QUOTA_QUERY            0x4000278EL

//
// MessageId: MSG_USAGE_QUOTA_MODIFY
//
// MessageText:
//
//  Usage : fsutil quota modify <volume pathname> <threshold> <limit> <user>
//     Eg : fsutil quota modify c: 3000 5000 domain\user
//
#define MSG_USAGE_QUOTA_MODIFY           0x4000278FL

//
// MessageId: MSG_USAGE_QUOTA_VIOLATIONS
//
// MessageText:
//
//  Usage : fsutil quota violations
//     Eg : fsutil quota violations
//
#define MSG_USAGE_QUOTA_VIOLATIONS       0x40002790L

//
// MessageId: MSG_USAGE_QUOTA_VOLUME_INFO
//
// MessageText:
//
//  FileSystemControlFlags = 0x%1!08x!
//
#define MSG_USAGE_QUOTA_VOLUME_INFO      0x40002791L

//
// MessageId: MSG_QUOTA_STATUS_DISABLED
//
// MessageText:
//
//      Quotas are disabled on this volume
//
#define MSG_QUOTA_STATUS_DISABLED        0x40002792L

//
// MessageId: MSG_QUOTA_STATUS_ENFORCE
//
// MessageText:
//
//      Quotas are tracked and enforced on this volume
//
#define MSG_QUOTA_STATUS_ENFORCE         0x40002793L

//
// MessageId: MSG_QUOTA_STATUS_TRACKING
//
// MessageText:
//
//      Quotas are tracked on this volume
//
#define MSG_QUOTA_STATUS_TRACKING        0x40002794L

//
// MessageId: MSG_QUOTA_LOGGING_LIMITS
//
// MessageText:
//
//      Logging enable for quota limits
//
#define MSG_QUOTA_LOGGING_LIMITS         0x40002795L

//
// MessageId: MSG_QUOTA_LOGGING_THRESH
//
// MessageText:
//
//      Logging enable for quota thresholds
//
#define MSG_QUOTA_LOGGING_THRESH         0x40002796L

//
// MessageId: MSG_QUOTA_LOGGING_BOTH
//
// MessageText:
//
//      Logging enable for quota limits and threshold
//
#define MSG_QUOTA_LOGGING_BOTH           0x40002797L

//
// MessageId: MSG_QUOTA_LOGGING_EVENTS
//
// MessageText:
//
//      Logging for quota events is not enabled
//
#define MSG_QUOTA_LOGGING_EVENTS         0x40002798L

//
// MessageId: MSG_QUOTA_VALUES_INCOMPLETE
//
// MessageText:
//
//      The quota values are incomplete
//
#define MSG_QUOTA_VALUES_INCOMPLETE      0x40002799L

//
// MessageId: MSG_QUOTA_VALUES_GOOD
//
// MessageText:
//
//      The quota values are up to date
//
#define MSG_QUOTA_VALUES_GOOD            0x4000279AL

//
// MessageId: MSG_USAGE_QUOTA_LIMITS
//
// MessageText:
//
//  
//  Default Quota Threshold = 0x%1
//  Default Quota Limit     = 0x%2
//  
//
#define MSG_USAGE_QUOTA_LIMITS           0x4000279BL

//
// MessageId: MSG_USAGE_QUOTA_REQUIRED
//
// MessageText:
//
//  Quotas are not enabled on volume %1!s!
//
#define MSG_USAGE_QUOTA_REQUIRED         0x4000279CL

//
// MessageId: MSG_DIRTY_SET
//
// MessageText:
//
//  Volume - %1!s! is now marked dirty
//
#define MSG_DIRTY_SET                    0x4000279DL

//
// MessageId: MSG_SET_VDL
//
// MessageText:
//
//  Valid data length is changed
//
#define MSG_SET_VDL                      0x4000279EL

//
// MessageId: MSG_SET_ZERODATA
//
// MessageText:
//
//  Zero data is changed
//
#define MSG_SET_ZERODATA                 0x4000279FL

//
// MessageId: MSG_FINDFILESBYSID_NONE
//
// MessageText:
//
//  No files were found
//
#define MSG_FINDFILESBYSID_NONE          0x400027A0L

//
// MessageId: MSG_SPARSE_IS_SET
//
// MessageText:
//
//  This file is set as sparse
//
#define MSG_SPARSE_IS_SET                0x400027A1L

//
// MessageId: MSG_SPARSE_ISNOT_SET
//
// MessageText:
//
//  This file is NOT set as sparse
//
#define MSG_SPARSE_ISNOT_SET             0x400027A2L

//
// MessageId: MSG_QUERYSPARSE_USAGE
//
// MessageText:
//
//  Usage : fsutil sparse queryflag <filename>
//     Eg : fsutil sparse queryflag C:\Temp\sample.txt
//
#define MSG_QUERYSPARSE_USAGE            0x400027A3L

//
// MessageId: MSG_SETSPARSE_RANGE_USAGE
//
// MessageText:
//
//  Usage : fsutil sparse setrange <filename> <beginning offset> <length>
//     Eg : fsutil sparse setrange C:\Temp\sample.txt 65536 131072
//
#define MSG_SETSPARSE_RANGE_USAGE        0x400027A4L

//
// MessageId: MSG_QUERYSPARSE_RANGE_USAGE
//
// MessageText:
//
//  Usage : fsutil sparse queryrange <filename>
//     Eg : fsutil sparse queryrange C:\Temp\sample.txt
//
#define MSG_QUERYSPARSE_RANGE_USAGE      0x400027A5L

//
// MessageId: MSG_FILE_IS_NOT_SPARSE
//
// MessageText:
//
//  The specified file is NOT sparse
//
#define MSG_FILE_IS_NOT_SPARSE           0x400027A6L

//
// MessageId: MSG_SPARSE_RANGE
//
// MessageText:
//
//  sparse range: %1
//
#define MSG_SPARSE_RANGE                 0x400027A7L

//
// MessageId: MSG_NO_OBJECT_ID
//
// MessageText:
//
//  The specified file has no object id
//
#define MSG_NO_OBJECT_ID                 0x400027A8L

//
// MessageId: MSG_NOT_SAME_DEVICE
//
// MessageText:
//
//  The new link and the existing file must be on the same volume.
//
#define MSG_NOT_SAME_DEVICE              0x400027A9L

//
// MessageId: MSG_USAGE_QUOTA_DISABLE
//
// MessageText:
//
//  Usage : fsutil quota disable <volume pathname>
//     Eg : fsutil quota disable C:
//
#define MSG_USAGE_QUOTA_DISABLE          0x400027AAL

//
// MessageId: MSG_USAGE_QUOTA_TRACK
//
// MessageText:
//
//  Usage : fsutil quota track <volume pathname>
//     Eg : fsutil quota track C:
//
#define MSG_USAGE_QUOTA_TRACK            0x400027ABL

//
// MessageId: MSG_USAGE_QUOTA_ENFORCE
//
// MessageText:
//
//  Usage : fsutil quota enforce <volume pathname>
//     Eg : fsutil quota enforce C:
//
#define MSG_USAGE_QUOTA_ENFORCE          0x400027ACL

//
// MessageId: MSG_INVALID_PARAMETER
//
// MessageText:
//
//  %1 is an invalid parameter.
//
#define MSG_INVALID_PARAMETER            0x400027ADL

//
// MessageId: MSG_LISTDRIVES_USAGE
//
// MessageText:
//
//  Usage : fsutil fsinfo drives
//
#define MSG_LISTDRIVES_USAGE             0x400027AEL

//
// MessageId: MSG_NEED_LOCAL_VOLUME
//
// MessageText:
//
//  The FSUTIL utility requires a local volume.
//
#define MSG_NEED_LOCAL_VOLUME            0x400027AFL

//
// MessageId: MSG_DRIVE_TOO_LONG
//
// MessageText:
//
//  The specified drive is too long.
//
#define MSG_DRIVE_TOO_LONG               0x400027B0L

//
// MessageId: MSG_FILENAME_TOO_LONG
//
// MessageText:
//
//  The specified file name is too long.
//
#define MSG_FILENAME_TOO_LONG            0x400027B1L

//
// MessageId: MSG_SIS_REPARSE_INFO
//
// MessageText:
//
//  Format version: %1!d!
//  CSid:           %2!s!
//  LinkIndex:      0x%3!08x!.%4!08x!
//  LinkFileNtfsID: 0x%5!08x!.%6!08x!
//  CSFileNtfsID:   0x%7!08x!.%8!08x!
//  CSChecksum:     0x%9!08x!.%10!08x!
//  Checksum:       0x%11!08x!.%12!08x!
//
#define MSG_SIS_REPARSE_INFO             0x400027B2L

//
// MessageId: MSG_MOUNT_POINT_INFO
//
// MessageText:
//
//  Substitue Name offset: %1!d!
//  Substitue Name length: %2!d!
//  Print Name offset:     %3!d!
//  Print Name Length:     %4!d!
//
#define MSG_MOUNT_POINT_INFO             0x400027B3L

//
// MessageId: MSG_MOUNT_POINT_SUBSTITUE_NAME
//
// MessageText:
//
//  Substitute Name:       %1!.*s!
//
#define MSG_MOUNT_POINT_SUBSTITUE_NAME   0x400027B4L

//
// MessageId: MSG_MOUNT_POINT_PRINT_NAME
//
// MessageText:
//
//  Print Name:            %1!.*s!
//
#define MSG_MOUNT_POINT_PRINT_NAME       0x400027B5L

//
// MessageId: MSG_REPARSE_DATA_LENGTH
//
// MessageText:
//
//  Reparse Data Length: 0x%1!08x!
//
#define MSG_REPARSE_DATA_LENGTH          0x400027B6L

//
// MessageId: MSG_RIS_REPARSE_INFO
//
// MessageText:
//
//  Vendor ID:            %1!s!
//  Qualifier:            0x%2!08x!
//  Version:              0x%3!08x!
//  Global Flags:         0x%4!08x!
//  Num Data Entries:     %5!d!
//  File ID:              %6!s!
//  Data:
//  Flags:                0x%7!08x!
//  Migration Time:       %8!s!
//  HSM ID:               %9!s!
//  Bag ID:               %10!s!
//  File Start:           0x%11!08x!.%12!08x!
//  File Size:            0x%13!08x!.%14!08x!
//  Data Start:           0x%15!08x!.%16!08x!
//  Data Size:            0x%17!08x!.%18!08x!
//  File Version:         0x%19!08x!.%20!08x!
//  Verification Data:    0x%21!08x!.%22!08x!
//  Verification Type:    %23!u!
//  Recall Count:         %24!u!
//  Recall Time:          %25!s!
//  Data Stream Start:    0x%26!08x!.%27!08x!
//  Data Stream Size:     0x%28!08x!.%29!08x!
//  Data Stream:          %30!u!
//  Data Stream CRC Type: %31!u!
//  Data Stream CRC:      0x%32!08x!.%3!08x!
//
#define MSG_RIS_REPARSE_INFO             0x400027B7L

