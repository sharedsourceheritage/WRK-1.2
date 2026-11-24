/*

Copyright (c) 1998  Microsoft Corporation

Module Name:

    msg.mc

Abstract:

    This file contains the message definitions for the command console.

Author:

    Wesley Witt (wesw) 21-Oct-1998

Revision History:

Notes:

--*/
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
// MessageId: MSG_SIGNON
//
// MessageText:
//
//  Microsoft Windows(R) Recovery Console.
//  
//  The Recovery Console provides system repair and recovery functionality.
//  
//  Type EXIT to quit the Recovery Console and restart the computer.
//  
//
#define MSG_SIGNON                       0x00000001L

//
// MessageId: MSG_UNKNOWN_COMMAND
//
// MessageText:
//
//  The command is not recognized  Type HELP for a list of supported commands.
//
#define MSG_UNKNOWN_COMMAND              0x00000002L

//
// MessageId: MSG_SYNTAX_ERROR
//
// MessageText:
//
//  The parameter is not valid. Try /? for help.
//
#define MSG_SYNTAX_ERROR                 0x00000003L

//
// MessageId: MSG_INVALID_DRIVE
//
// MessageText:
//
//  The specified drive is not valid, or there is no disk in the drive.
//
#define MSG_INVALID_DRIVE                0x00000004L

//
// MessageId: MSG_INVALID_PATH
//
// MessageText:
//
//  The path or file specified is not valid.
//
#define MSG_INVALID_PATH                 0x00000005L

//
// MessageId: MSG_CANT_OPEN_FILE
//
// MessageText:
//
//  The file cannot be opened.
//
#define MSG_CANT_OPEN_FILE               0x00000006L

//
// MessageId: MSG_CANT_READ_FILE
//
// MessageText:
//
//  An error occurred during the file read operation.
//
#define MSG_CANT_READ_FILE               0x00000007L

//
// MessageId: MSG_ACCESS_DENIED
//
// MessageText:
//
//  Access is denied.
//
#define MSG_ACCESS_DENIED                0x00000008L

//
// MessageId: MSG_MORE_PROMPT
//
// MessageText:
//
//  More:  ENTER=Scroll (Line)   SPACE=Scroll (Page)   ESC=Stop
//
#define MSG_MORE_PROMPT                  0x00000009L

//
// MessageId: MSG_FILE_ENUM_ERROR
//
// MessageText:
//
//  An error occurred during directory enumeration.
//
#define MSG_FILE_ENUM_ERROR              0x0000000AL

//
// MessageId: MSG_DATE_TIME_FORMAT
//
// MessageText:
//
//  m/d/y  h:na*ap
//  NOTE TO LOCALIZERS:
//  m=month, d=day, y=year, h=hour (12-hour), H=hour (24-hour), n=minutes, a=am/pm, *=end.
//  Following * are abbreviation chars for AM and PM.
//
#define MSG_DATE_TIME_FORMAT             0x0000000BL

//
// MessageId: MSG_NO_FILES
//
// MessageText:
//
//  No matching files were found.
//
#define MSG_NO_FILES                     0x0000000CL

//
// MessageId: MSG_NO_MEDIA_IN_DEVICE
//
// MessageText:
//
//  There is no floppy disk or CD in the drive.
//
#define MSG_NO_MEDIA_IN_DEVICE           0x0000000DL

//
// MessageId: MSG_RENAME_ERROR
//
// MessageText:
//
//  The rename operation failed.
//
#define MSG_RENAME_ERROR                 0x0000000EL

//
// MessageId: MSG_CONFIRM_DELETE
//
// MessageText:
//
//  %1, Are you sure? (Y/N) %0
//
#define MSG_CONFIRM_DELETE               0x0000000FL

//
// MessageId: MSG_YESNO
//
// MessageText:
//
//  yYnN
//
#define MSG_YESNO                        0x00000010L

//
// MessageId: MSG_DELETE_ERROR
//
// MessageText:
//
//  The delete operation failed.
//
#define MSG_DELETE_ERROR                 0x00000012L

//
// MessageId: MSG_CREATE_DIR_FAILED
//
// MessageText:
//
//  The directory could not be created.
//
#define MSG_CREATE_DIR_FAILED            0x00000013L

//
// MessageId: MSG_ALREADY_EXISTS
//
// MessageText:
//
//  A directory or file with the name %1 already exists.
//
#define MSG_ALREADY_EXISTS               0x00000014L

//
// MessageId: MSG_INVALID_NAME
//
// MessageText:
//
//  The file name, directory name, or volume label syntax is incorrect.
//
#define MSG_INVALID_NAME                 0x00000015L

//
// MessageId: MSG_FILE_NOT_FOUND
//
// MessageText:
//
//  The system cannot find the file or directory specified.
//
#define MSG_FILE_NOT_FOUND               0x00000016L

//
// MessageId: MSG_RMDIR_ERROR
//
// MessageText:
//
//  The directory could not be removed.
//
#define MSG_RMDIR_ERROR                  0x00000017L

//
// MessageId: MSG_DIR_NOT_EMPTY
//
// MessageText:
//
//  The directory is not empty.
//
#define MSG_DIR_NOT_EMPTY                0x00000018L

//
// MessageId: MSG_NOT_DIRECTORY
//
// MessageText:
//
//  The name specified is not a directory.
//
#define MSG_NOT_DIRECTORY                0x00000019L

//
// MessageId: MSG_DIR_BANNER1a
//
// MessageText:
//
//   The volume in drive %1!c! is %2
//
#define MSG_DIR_BANNER1a                 0x0000001AL

//
// MessageId: MSG_DIR_BANNER1b
//
// MessageText:
//
//   The volume in drive %1!c! has no label
//
#define MSG_DIR_BANNER1b                 0x0000001BL

//
// MessageId: MSG_DIR_BANNER2
//
// MessageText:
//
//   The volume Serial Number is %1!04x!-%2!04x!
//  
//
#define MSG_DIR_BANNER2                  0x0000001CL

//
// MessageId: MSG_DIR_BANNER3
//
// MessageText:
//
//   Directory of %1
//  
//
#define MSG_DIR_BANNER3                  0x0000001DL

//
// MessageId: MSG_DIR_BANNER4
//
// MessageText:
//
//         %1!u! file(s)   %2 bytes
//
#define MSG_DIR_BANNER4                  0x0000001EL

//
// MessageId: MSG_DIR_BANNER5
//
// MessageText:
//
//         %1 bytes free
//
#define MSG_DIR_BANNER5                  0x0000001FL

//
// MessageId: MSG_VOLUME_NOT_CHECKED
//
// MessageText:
//
//  The drive could not be checked.
//
#define MSG_VOLUME_NOT_CHECKED           0x00000020L

//
// MessageId: MSG_VOLUME_CLEAN
//
// MessageText:
//
//  
//  The volume appears to be in good condition and was not checked.
//  Use /p if you want to check the volume anyway.
//  
//
#define MSG_VOLUME_CLEAN                 0x00000021L

//
// MessageId: MSG_VOLUME_CHECKED_BUT_HOSED
//
// MessageText:
//
//  The volume appears to contain one or more unrecoverable problems.
//
#define MSG_VOLUME_CHECKED_BUT_HOSED     0x00000022L

//
// MessageId: MSG_VOLUME_CHECKED_AND_FIXED
//
// MessageText:
//
//  CHKDSK found and fixed one or more errors on the volume.
//
#define MSG_VOLUME_CHECKED_AND_FIXED     0x00000023L

//
// MessageId: MSG_CHKDSK_CHECKING_1
//
// MessageText:
//
//  CHKDSK is checking the volume...
//
#define MSG_CHKDSK_CHECKING_1            0x00000024L

//
// MessageId: MSG_CHKDSK_CHECKING_2
//
// MessageText:
//
//  CHKDSK is performing additional checking or recovery...
//
#define MSG_CHKDSK_CHECKING_2            0x00000025L

//
// MessageId: MSG_VOLUME_PERCENT_COMPLETE
//
// MessageText:
//
//  %1!u!%% completed.%0
//
#define MSG_VOLUME_PERCENT_COMPLETE      0x00000026L

//
// MessageId: MSG_CHKDSK_UNSUPPORTED_VOLUME
//
// MessageText:
//
//  There is no disk in drive or the file system is not supported.
//
#define MSG_CHKDSK_UNSUPPORTED_VOLUME    0x00000027L

//
// MessageId: MSG_CHKDSK_REPORT_1a
//
// MessageText:
//
//  Volume %2 created %1
//
#define MSG_CHKDSK_REPORT_1a             0x00000028L

//
// MessageId: MSG_CHKDSK_REPORT_1b
//
// MessageText:
//
//  Volume created %1
//
#define MSG_CHKDSK_REPORT_1b             0x00000029L

//
// MessageId: MSG_CHKDSK_REPORT_2
//
// MessageText:
//
//  The volume Serial Number is %1!04x!-%2!04x!
//
#define MSG_CHKDSK_REPORT_2              0x0000002AL

//
// MessageId: MSG_CHKDSK_REPORT_3
//
// MessageText:
//
//  %1!9.9s! kilobytes total disk space.
//  %2!9.9s! kilobytes are available.
//  
//  %3!9.9s! bytes in each allocation unit.
//  %4!9.9s! total allocation units on disk.
//  %5!9.9s! allocation units available on disk.
//
#define MSG_CHKDSK_REPORT_3              0x0000002BL

//
// MessageId: MSG_CHKDSK_COMPLETE
//
// MessageText:
//
//  CHKDSK has finished checking the volume.
//
#define MSG_CHKDSK_COMPLETE              0x0000002CL

//
// MessageId: MSG_SHARING_VIOLATION
//
// MessageText:
//
//  The file or directory is being used by another process.
//
#define MSG_SHARING_VIOLATION            0x0000002DL

//
// MessageId: MSG_DRIVEMAP_HEADER
//
// MessageText:
//
//  Drive Mapping
//  
//
#define MSG_DRIVEMAP_HEADER              0x0000002EL

//
// MessageId: MSG_COPY_OVERWRITE
//
// MessageText:
//
//  Overwrite %1? (Yes/No/All): %0
//
#define MSG_COPY_OVERWRITE               0x0000002FL

//
// MessageId: MSG_YESNOALL
//
// MessageText:
//
//  nNyYaA
//
#define MSG_YESNOALL                     0x00000030L

//
// MessageId: MSG_CANT_COPY_FILE
//
// MessageText:
//
//  The file could not be copied.
//
#define MSG_CANT_COPY_FILE               0x00000031L

//
// MessageId: MSG_COPY_COUNT
//
// MessageText:
//
//          %1!u! file(s) copied.
//
#define MSG_COPY_COUNT                   0x00000032L

//
// MessageId: MSG_MAP_ENTRY
//
// MessageText:
//
//  %1!c!%2!c! %3!s!  %4!8u!MB    %5!s!
//
#define MSG_MAP_ENTRY                    0x00000033L

//
// MessageId: MSG_MAP_ENTRY2
//
// MessageText:
//
//  %1!c!:                      %2!s!
//
#define MSG_MAP_ENTRY2                   0x00000034L

//
// MessageId: MSG_INSTALL_SELECT
//
// MessageText:
//
//  Which Windows installation would you like to log onto
//  (To cancel, press ENTER)? %0
//
#define MSG_INSTALL_SELECT               0x00000035L

//
// MessageId: MSG_LOGON_PROMPT_PASSWORD
//
// MessageText:
//
//  Type the Administrator password: %0
//
#define MSG_LOGON_PROMPT_PASSWORD        0x00000036L

//
// MessageId: MSG_LOGON_FAILURE
//
// MessageText:
//
//  The password is not valid.  Please retype the password.
//
#define MSG_LOGON_FAILURE                0x00000037L

//
// MessageId: MSG_LOGON_FAILUE_BAD
//
// MessageText:
//
//  An invalid password has been entered 3 times.
//
#define MSG_LOGON_FAILUE_BAD             0x00000038L

//
// MessageId: MSG_SERVICE_CURRENT_STATE
//
// MessageText:
//
//  The service currently has start_type %1.
//  Please record this value.
//  
//
#define MSG_SERVICE_CURRENT_STATE        0x00000039L

//
// MessageId: MSG_SERVICE_CHANGE_STATE
//
// MessageText:
//
//  The new start_type for the service has been set to %1.
//  
//  The computer must be restarted for the changes to take effect.
//  Type EXIT if you want to restart the computer now.
//
#define MSG_SERVICE_CHANGE_STATE         0x0000003AL

//
// MessageId: MSG_SERVICE_NOT_FOUND
//
// MessageText:
//
//  The registry entry for the %1 service cannot be located.
//  Check that the name of the service is specified correctly.
//
#define MSG_SERVICE_NOT_FOUND            0x0000003CL

//
// MessageId: MSG_SERVICE_FOUND
//
// MessageText:
//
//  The registry entry for the %1 service was found.
//
#define MSG_SERVICE_FOUND                0x0000003DL

//
// MessageId: MSG_SERVICE_ENABLE_HELP
//
// MessageText:
//
//  Using the ENABLE command, you can enable a Windows system service
//  or driver.
//  
//  ENABLE servicename [start_type]
//  
//    servicename   The name of the service or driver to be enabled.
//    start_type    Valid start_type values are:
//  
//                  SERVICE_BOOT_START
//                  SERVICE_SYSTEM_START
//                  SERVICE_AUTO_START
//                  SERVICE_DEMAND_START
//  
//  ENABLE prints the old start_type of the service before resetting it to
//  the new value.  You should make a note of the old value, in case it is
//  necessary to restore the start_type of the service.
//  
//  If you do not specify a new start_type, ENABLE prints the old
//  start_type for you.
//  
//  The start_type values that the DISABLE command displays are:
//  
//                  SERVICE_DISABLED
//                  SERVICE_BOOT_START
//                  SERVICE_SYSTEM_START
//                  SERVICE_AUTO_START
//                  SERVICE_DEMAND_START
//
#define MSG_SERVICE_ENABLE_HELP          0x0000003EL

//
// MessageId: MSG_SERVICE_DISABLE_HELP
//
// MessageText:
//
//  Using the DISABLE command, you can disable a Windows system service
//  or driver.
//  
//  DISABLE servicename
//  
//    servicename   The name of the service or driver to be disabled.
//  
//  DISABLE prints the old start_type of the service before resetting it to
//  SERVICE_DISABLED .  You should make a note of the old start_type, in case
//  you need to enable the service again.
//  
//  The start_type values that the DISABLE command displays are:
//  
//                  SERVICE_DISABLED
//                  SERVICE_BOOT_START
//                  SERVICE_SYSTEM_START
//                  SERVICE_AUTO_START
//                  SERVICE_DEMAND_START
//
#define MSG_SERVICE_DISABLE_HELP         0x0000003FL

//
// MessageId: MSG_SERVICE_ALREADY_DISABLED
//
// MessageText:
//
//  The %1 service is already disabled.
//
#define MSG_SERVICE_ALREADY_DISABLED     0x00000040L

//
// MessageId: MSG_SERVICE_MISSING_START_KEY
//
// MessageText:
//
//  The service is missing the Start value key.
//  The system registry may be damaged.
//  
//  If your system is currently not starting correctly, you can try restarting
//  it with the Last Known Good configuration or you can try repairing the
//  Windows installation using the setup program's repair and recovery
//  options.
//
#define MSG_SERVICE_MISSING_START_KEY    0x00000041L

//
// MessageId: MSG_SYSTEM_MISSING_CURRENT_CONTROLS
//
// MessageText:
//
//  The system registry does not appear to have an active ControlSet key.
//  The system registry may be damaged.
//  
//  If your system is currently not starting correctly, you can try restarting
//  it with the Last Known Good configuration or you can try repairing the
//  installation of Windows using the setup program's repair and recovery
//  options.
//
#define MSG_SYSTEM_MISSING_CURRENT_CONTROLS 0x00000042L

//
// MessageId: MSG_SERVICE_SAME_STATE
//
// MessageText:
//
//  The service is already set to %1.
//
#define MSG_SERVICE_SAME_STATE           0x00000043L

//
// MessageId: MSG_SERVICE_ENABLE_SYNTAX_ERROR
//
// MessageText:
//
//  The start_type specified is not valid.
//  
//  Valid start types are:
//  
//                  SERVICE_BOOT_START
//                  SERVICE_SYSTEM_START
//                  SERVICE_AUTO_START
//                  SERVICE_DEMAND_START
//
#define MSG_SERVICE_ENABLE_SYNTAX_ERROR  0x00000044L

//
// MessageId: MSG_COULDNT_FIND_BINARY
//
// MessageText:
//
//  %1 could not be located in either the startup directory
//  or the CDROM drive.
//  
//  Type the full path (including drive letter) for the
//  location of %1: %0
//
#define MSG_COULDNT_FIND_BINARY          0x00000045L

//
// MessageId: MSG_LOOKING_FOR_BINARY
//
// MessageText:
//
//  %1 could not be located in the startup directory.
//  Checking drives for installation source or CD...
//
#define MSG_LOOKING_FOR_BINARY           0x00000046L

//
// MessageId: MSG_FAILED_COULDNT_FIND_BINARY_ANYWHERE
//
// MessageText:
//
//  %1 cannot be found in the specified location.
//
#define MSG_FAILED_COULDNT_FIND_BINARY_ANYWHERE 0x00000047L

//
// MessageId: MSG_CHKDSK_HELP
//
// MessageText:
//
//  Checks a disk and displays a status report
//  
//  CHKDSK [drive:] [/P] [/R]
//  
//    [drive:]      Specifies the drive to check
//    /P            Check even if the drive is not flagged dirty
//    /R            Locates bad sectors and recovers readable information
//                  (implies /P)
//  
//  CHKDSK may be used without any parameters, in which case the
//  current drive is checked with no switches.  You can specify the listed
//  switches.
//  
//  CHKDSK requires the AUTOCHK.EXE file. CHKDSK automatically locates
//  AUTOCHK.EXE in the startup (boot) directory. If it cannot be found in
//  the startup directory, CHKDSK will attempt to locate the Windows
//  installation CD. If the installation CD cannot be found, CHKDSK prompts
//  for the location of AUTOCHK.EXE.
//
#define MSG_CHKDSK_HELP                  0x00000048L

//
// MessageId: MSG_COPY_HELP
//
// MessageText:
//
//  Copies a single file to another location.
//  
//  COPY source [destination]
//  
//    source       Specifies the file to be copied
//  
//    destination  Specifies the directory and/or file name for the new file
//  
//  The source may be removable media, any directory within the system
//  directories of the current Windows installation, the root of any drive,
//  the local installation sources, or the Cmdcons directory.
//  
//  The destination may be any directory within the system directories
//  of the current Windows installation, the root of any drive, the local
//  installation sources, or the cmdcons directory.
//  
//  The destination cannot be removable media.
//  
//  If a destination is not specified, it defaults to the current directory.
//  
//  COPY does not support replaceable parameters (wildcards).
//  
//  COPY prompts if the destination file already exists.
//  
//  A compressed file from the Windows installation CD is automatically
//  decompressed as it is copied.
//
#define MSG_COPY_HELP                    0x00000049L

//
// MessageId: MSG_CHDIR_HELP
//
// MessageText:
//
//  Displays the name of the current directory, or switches to a new directory.
//  
//  CHDIR [path]
//  CHDIR [..]
//  CHDIR [drive:]
//  CD    [path]
//  CD    [..]
//  CD    [drive:]
//  
//  CD ..  Specifies that you want to change to the parent directory.
//  
//  Type CD drive: to display the current directory in the specified drive.
//  Type CD without parameters to display the current drive and directory.
//  
//  The CHDIR command treat spaces as delimiters. Use quotation marks around
//  a directory name containing spaces. For example:
//  
//      cd "\windows\profiles\username\programs\start menu"
//  
//  CHDIR only operates within the system directories of the current
//  Windows installation, removable media, the root directory of any hard
//  disk partition, or the local installation sources.
//  
//
#define MSG_CHDIR_HELP                   0x0000004AL

//
// MessageId: MSG_CLS_HELP
//
// MessageText:
//
//  Clears the screen.
//  
//  CLS
//  
//
#define MSG_CLS_HELP                     0x0000004BL

//
// MessageId: MSG_DELETE_HELP
//
// MessageText:
//
//  Deletes one file.
//  
//  DEL    [drive:][path]filename
//  DELETE [drive:][path]filename
//  
//    [drive:][path]filename
//                  Specifies the file to delete.
//  
//  DELETE only operates within the system directories of the current
//  Windows installation, removable media, the root directory of any hard
//  disk partition, or the local installation sources.
//  
//
#define MSG_DELETE_HELP                  0x0000004CL

//
// MessageId: MSG_START_TYPE_NOT_SPECIFIED
//
// MessageText:
//
//  The start_type of the service was not changed.
//  
//  To change the start_type, specify a start_type.
//  
//  Valid start types are:
//  
//                  SERVICE_BOOT_START
//                  SERVICE_SYSTEM_START
//                  SERVICE_AUTO_START
//                  SERVICE_DEMAND_START
//
#define MSG_START_TYPE_NOT_SPECIFIED     0x0000004DL

//
// MessageId: MSG_DIR_HELP
//
// MessageText:
//
//  
//  Displays a list of files and subdirectories in a directory.
//  
//  DIR [drive:][path][filename]
//  
//    [drive:][path][filename]
//                Specifies drive, directory, and/or files to list.
//  
//  DIR lists all files, including hidden and system files.
//  
//  Files may have the following attributes:
//  
//   D  Directory                  R  Read-only
//   H  Hidden file                A  Files ready for archiving
//   S  System file                C  Compressed
//   E  Encrypted                  P  Reparse Point
//  
//  DIR only operates within the system directories of the current
//  Windows installation, removable media, the root directory of any hard
//  disk partition, or the local installation sources.
//  
//
#define MSG_DIR_HELP                     0x0000004EL

//
// MessageId: MSG_LOGON_HELP
//
// MessageText:
//
//  
//  Logs on to a Windows installation.
//  
//  LOGON
//  
//  LOGON lists the detected installations of Windows, and requests the
//  local administrator password for those installations.
//  
//
#define MSG_LOGON_HELP                   0x0000004FL

//
// MessageId: MSG_REBOOT_NOW
//
// MessageText:
//
//  To restart your computer, press ENTER.
//  
//
#define MSG_REBOOT_NOW                   0x00000050L

//
// MessageId: MSG_MAP_HELP
//
// MessageText:
//
//  Displays the drive letter mappings.
//  
//  MAP [arc]
//  
//  MAP lists the drive letter to physical device mappings that are currently
//  active.
//  
//  The arc parameter tells MAP to use ARC paths instead of Windows
//  device paths.
//  
//
#define MSG_MAP_HELP                     0x00000051L

//
// MessageId: MSG_TYPE_HELP
//
// MessageText:
//
//  Displays a text file to the screen.
//  
//  MORE filename or TYPE filename
//  
//  MORE or TYPE displays a text file.
//  
//
#define MSG_TYPE_HELP                    0x00000052L

//
// MessageId: MSG_RENAME_HELP
//
// MessageText:
//
//  Renames a single file.
//  
//  RENAME [drive:][path]filename1 filename2.
//  REN [drive:][path]filename1 filename2.
//  
//  You cannot specify a new drive or path for your destination file.
//  
//  RENAME will only operate within the system directories of the current
//  Windows installation, removable media, the root directory of any hard
//  disk partition, or the local installation sources.
//  
//
#define MSG_RENAME_HELP                  0x00000053L

//
// MessageId: MSG_MAKEDIR_HELP
//
// MessageText:
//
//  Creates a directory.
//  
//  MKDIR [drive:]path
//  MD [drive:]path
//  
//  MKDIR only operates within the system directories of the current
//  Windows installation, removable media, the root directory of any hard
//  disk partition, or the local installation sources.
//  
//
#define MSG_MAKEDIR_HELP                 0x00000054L

//
// MessageId: MSG_REMOVEDIR_HELP
//
// MessageText:
//
//  Removes (deletes) a directory.
//  
//  RMDIR [drive:]path
//  RD [drive:]path
//  
//  RMDIR only operates within the system directories of the current
//  Windows installation, removable media, the root directory of any hard
//  disk partition, or the local installation sources.
//  
//
#define MSG_REMOVEDIR_HELP               0x00000055L

//
// MessageId: MSG_HELPCOMMAND_HELP
//
// MessageText:
//
//  
//  For more information on a specific command, type
//  command-name /? or HELP command-name.
//  
//
#define MSG_HELPCOMMAND_HELP             0x00000056L

//
// MessageId: MSG_FIXMBR_HELP
//
// MessageText:
//
//  Repairs the master boot record of the boot partition.
//  
//  FIXMBR [device-name]
//  
//    device-name     Optional name that specifies the device
//                    that will be updated with a new MBR.
//                    If this is left blank then the boot device is used.
//  
//  FIXMBR is only supported on x86-based computers.
//  
//
#define MSG_FIXMBR_HELP                  0x00000057L

//
// MessageId: MSG_ONLY_ON_X86
//
// MessageText:
//
//  This is only supported on x86-based computers.
//  
//
#define MSG_ONLY_ON_X86                  0x00000058L

//
// MessageId: MSG_FIXMBR_DOING_IT
//
// MessageText:
//
//  Writing new master boot record on physical drive
//  %1.
//
#define MSG_FIXMBR_DOING_IT              0x00000059L

//
// MessageId: MSG_FIXMBR_INT13_HOOKER
//
// MessageText:
//
//  An Interrupt 13 hook was detected.
//
#define MSG_FIXMBR_INT13_HOOKER          0x0000005AL

//
// MessageId: MSG_FIXMBR_NO_VALID_SIGNATURE
//
// MessageText:
//
//  FIXMBR could not detect a master boot record signature.
//
#define MSG_FIXMBR_NO_VALID_SIGNATURE    0x0000005BL

//
// MessageId: MSG_FIXMBR_WARNING_BEFORE_PROCEED
//
// MessageText:
//
//  
//  ** CAUTION **
//  
//  FIXMBR may damage your partition tables if you
//  proceed.
//  
//  This could cause all the partitions on the current hard disk
//  to become inaccessible.
//  
//  If you are not having problems accessing your drive,
//  do not continue.
//  
//
#define MSG_FIXMBR_WARNING_BEFORE_PROCEED 0x0000005CL

//
// MessageId: MSG_FIXMBR_DONE
//
// MessageText:
//
//  
//  The new master boot record has been successfully written.
//  
//
#define MSG_FIXMBR_DONE                  0x0000005DL

//
// MessageId: MSG_FIXMBR_FAILED
//
// MessageText:
//
//  
//  The new master boot record could not be written.
//  
//  The disk may be damaged.
//  
//
#define MSG_FIXMBR_FAILED                0x0000005EL

//
// MessageId: MSG_FIXMBR_ABORT
//
// MessageText:
//
//  
//  Canceled writing the new master boot record write operation.
//  
//
#define MSG_FIXMBR_ABORT                 0x0000005FL

//
// MessageId: MSG_FIXMBR_READ_ERROR
//
// MessageText:
//
//  
//  The old master boot record cannot be read.
//  
//
#define MSG_FIXMBR_READ_ERROR            0x00000060L

//
// MessageId: MSG_FIXMBR_IS_PC98
//
// MessageText:
//
//  
//  This is a NEC PC98.
//
#define MSG_FIXMBR_IS_PC98               0x00000061L

//
// MessageId: MSG_FIXMBR_ARE_YOU_SURE
//
// MessageText:
//
//  Are you sure you want to write a new MBR? %0
//
#define MSG_FIXMBR_ARE_YOU_SURE          0x00000062L

//
// MessageId: MSG_FIXBOOT_HELP
//
// MessageText:
//
//  Writes a new bootsector onto the system partition.
//  
//  FIXBOOT [drive:]
//  
//          [drive:]
//                  Specifies the drive to which a boot sector
//                  will be written, overriding the default
//                  choice of the system boot partition.
//  
//  FIXBOOT is only supported on x86-based computers.
//
#define MSG_FIXBOOT_HELP                 0x00000063L

//
// MessageId: MSG_FIXBOOT_READ_ERROR
//
// MessageText:
//
//  
//  The old boot sector information cannot be read.
//  
//
#define MSG_FIXBOOT_READ_ERROR           0x00000064L

//
// MessageId: MSG_FIXBOOT_FIX_ERROR
//
// MessageText:
//
//  
//  The boot sector cannot be fixed.
//  
//
#define MSG_FIXBOOT_FIX_ERROR            0x00000065L

//
// MessageId: MSG_FIXBOOT_DONE
//
// MessageText:
//
//  
//  The new bootsector was successfully written.
//  
//
#define MSG_FIXBOOT_DONE                 0x00000066L

//
// MessageId: MSG_FIXBOOT_NO_VALID_FS
//
// MessageText:
//
//  The file system on the startup partition is unknown.
//  FIXBOOT is attempting to detect the file system type.
//
#define MSG_FIXBOOT_NO_VALID_FS          0x00000067L

//
// MessageId: MSG_FIXBOOT_FS
//
// MessageText:
//
//  The file system on the startup partition is %1.
//
#define MSG_FIXBOOT_FS                   0x00000068L

//
// MessageId: MSG_FIXBOOT_INFO1
//
// MessageText:
//
//  
//  The target partition is %1!c!:.
//
#define MSG_FIXBOOT_INFO1                0x00000069L

//
// MessageId: MSG_FIXBOOT_FAILED1
//
// MessageText:
//
//  
//  FIXBOOT cannot open the partition.
//  
//
#define MSG_FIXBOOT_FAILED1              0x0000006AL

//
// MessageId: MSG_FIXBOOT_DETERMINE
//
// MessageText:
//
//  
//  The bootsector is corrupt.
//  FIXBOOT is checking the filesystem type...
//
#define MSG_FIXBOOT_DETERMINE            0x0000006BL

//
// MessageId: MSG_FIXBOOT_FOUND_NTFS
//
// MessageText:
//
//  The partition is using the NTFS file system.
//
#define MSG_FIXBOOT_FOUND_NTFS           0x0000006CL

//
// MessageId: MSG_FIXBOOT_FOUND_FAT
//
// MessageText:
//
//  The partition is using the FAT file system.
//
#define MSG_FIXBOOT_FOUND_FAT            0x0000006DL

//
// MessageId: MSG_FIXBOOT_CHECKING_OS
//
// MessageText:
//
//  
//  FIXBOOT is checking for an operating system.
//
#define MSG_FIXBOOT_CHECKING_OS          0x0000006EL

//
// MessageId: MSG_FIXBOOT_WRITING
//
// MessageText:
//
//  
//  FIXBOOT is writing a new boot sector.
//
#define MSG_FIXBOOT_WRITING              0x0000006FL

//
// MessageId: MSG_FIXBOOT_INVALID
//
// MessageText:
//
//  
//  FIXBOOT cannot find the system drive, or the drive
//  specified is not valid.
//
#define MSG_FIXBOOT_INVALID              0x00000070L

//
// MessageId: MSG_FILE_NOT_FOUND2
//
// MessageText:
//
//  The system cannot find the file specified.
//
#define MSG_FILE_NOT_FOUND2              0x00000071L

//
// MessageId: MSG_DIR_WILDCARD_NOT_SUPPORTED
//
// MessageText:
//
//  COPY does not support wildcards or directory copies.
//
#define MSG_DIR_WILDCARD_NOT_SUPPORTED   0x00000072L

//
// MessageId: MSG_SYSTEMROOT_HELP
//
// MessageText:
//
//  Sets the current directory to systemroot.
//  
//  SYSTEMROOT
//  
//
#define MSG_SYSTEMROOT_HELP              0x00000073L

//
// MessageId: MSG_REPAIR_HELP
//
// MessageText:
//
//  You can use the REPAIR command to repair your system.
//  
//  REPAIR PathtoERFiles PathtoNTSourceFiles  /NoConfirm /RepairStartup /Registry
//  
//      PathtoERFiles:  Path to the Emergency Repair Disk Files
//                      (Setup.log, autoexec.nt, config.nt).  If this parameter
//                      is not specified, REPAIR prompts the user with 2 choices:
//                      Use a floppy disk, or use the repair info stored in
//                      %windir%\repair.
//  
//      PathtoNTSourceFiles: Path to the Windows Installation CD files.
//                           This is the CD-ROM drive if not specified.
//  
//      NoConfirm: Replace all files listed in setup.log without prompting the
//                 user. By default, the user is prompted to confirm the
//                 replacement of each file.
//  
//      Registry: Replace all the registry files in %windir%\system32\config
//                with the original copy of the registry saved after setup and
//                located in %windir%\repair.
//  
//      RepairStartup: Repair the startup environment, boot files, and boot
//                     sector.
//
#define MSG_REPAIR_HELP                  0x00000074L

//
// MessageId: MSG_NYI
//
// MessageText:
//
//  Not yet implemented.
//
#define MSG_NYI                          0x00000075L

//
// MessageId: MSG_BATCH_HELP
//
// MessageText:
//
//  Executes commands specified in a text file
//  
//  BATCH Inputfile [Outputfile]
//  
//    InputFile     Specifies the text file that contains the list of
//                  commands to be executed.
//  
//    OutputFile    If specified, contains the output of the specified
//                  commands.  If not specified, the output is displayed
//                  on the screen.
//  
//
#define MSG_BATCH_HELP                   0x00000076L

//
// MessageId: MSG_FORMAT_HELP
//
// MessageText:
//
//  Formats a disk for use with Windows.
//  
//  FORMAT [drive:] [/Q] [/FS:file-system]
//  
//    [drive:]          Specifies the drive to format.
//    /Q                Performs a quick format.
//    /FS:file-system   Specifies the file system to use (FAT, FAT32, or NTFS)
//  
//
#define MSG_FORMAT_HELP                  0x00000077L

//
// MessageId: MSG_VOLUME_NOT_FORMATTED
//
// MessageText:
//
//  The drive cannot be formatted.
//
#define MSG_VOLUME_NOT_FORMATTED         0x00000078L

//
// MessageId: MSG_FORMAT_FORMATTING_1
//
// MessageText:
//
//  FORMAT is formatting the volume...
//
#define MSG_FORMAT_FORMATTING_1          0x00000079L

//
// MessageId: MSG_FORMAT_HEADER
//
// MessageText:
//
//  CAUTION: All data on non-removable disk
//  drive %1 will be lost!
//  Proceed with Format (Y/N)?%0
//
#define MSG_FORMAT_HEADER                0x0000007AL

//
// MessageId: MSG_FDISK_HELP
//
// MessageText:
//
//  Use the DISKPART command to manage the partitions on your hard
//  disk volumes.
//  
//  DISKPART [/add|/delete] [device-name|drive-name|partition-name] [size]
//  
//    /ADD            Create a new partition
//    /DELETE         Delete an existing partition
//  
//    device-name     Device name for creating a new partition.  The name
//                    can be obtained from the output of the MAP command.
//                    An example of a good device name is
//                    \Device\HardDisk0.
//  
//    drive-name      This is a drive letter-based name for deleting an
//                    existing partition.  An example of a good drive
//                    name is D:.
//  
//    partition-name  This is a partition-based name for deleting an
//                    exisiting partition and can be used in place of the
//                    drive-name argument.  An example of a good
//                    partition name is \Device\HardDisk0\Partition1.
//  
//    Note:  If you use the DISKPART command with no arguments, a user
//    interface for managing your partitions appears.
//  
//
#define MSG_FDISK_HELP                   0x0000007BL

//
// MessageId: MSG_REPAIR_ERFILES_LOCATION
//
// MessageText:
//
//  Specify the location of the emergency repair files? %0
//
#define MSG_REPAIR_ERFILES_LOCATION      0x0000007CL

//
// MessageId: MSG_DEL_WILDCARD_NOT_SUPPORTED
//
// MessageText:
//
//  DELETE does not support wildcards.
//
#define MSG_DEL_WILDCARD_NOT_SUPPORTED   0x0000007DL

//
// MessageId: MSG_SET_ALLOW_WILDCARDS
//
// MessageText:
//
//  AllowWildCards = %1
//
#define MSG_SET_ALLOW_WILDCARDS          0x0000007EL

//
// MessageId: MSG_SET_ALLOW_ALLPATHS
//
// MessageText:
//
//  AllowAllPaths = %1
//
#define MSG_SET_ALLOW_ALLPATHS           0x0000007FL

//
// MessageId: MSG_SET_ALLOW_REMOVABLE_MEDIA
//
// MessageText:
//
//  AllowRemovableMedia = %1
//
#define MSG_SET_ALLOW_REMOVABLE_MEDIA    0x00000080L

//
// MessageId: MSG_SET_NO_COPY_PROMPT
//
// MessageText:
//
//  NoCopyPrompt = %1
//
#define MSG_SET_NO_COPY_PROMPT           0x00000081L

//
// MessageId: MSG_CANNOT_FORMAT_REMOVABLE
//
// MessageText:
//
//  You cannot format removable media.
//
#define MSG_CANNOT_FORMAT_REMOVABLE      0x00000082L

//
// MessageId: MSG_VOLUME_CHECKED_AND_FOUND
//
// MessageText:
//
//  CHKDSK found one or more errors on the volume.
//
#define MSG_VOLUME_CHECKED_AND_FOUND     0x00000083L

//
// MessageId: MSG_LOGON_PROMPT_USERNAME
//
// MessageText:
//
//  Please enter your user name: %0
//
#define MSG_LOGON_PROMPT_USERNAME        0x00000084L

//
// MessageId: MSG_NET_USE_HELP
//
// MessageText:
//
//  Use NET USE to Map a network share point to a drive letter.
//  
//  NET USE [\\server-name\share-name /USER:domain-name\user-name [password] | drive-letter: /d]
//  
//  server-name             The server that you wish to connect to.
//  
//  share-name              The share that you wish to connect to.
//  
//  domain-name             The domain to use when validating the credentials
//                          for user-name.
//  
//  user-name               The user within domain-name to use for connecting
//                          to \\server-name\share-name.
//  
//  password                You may, optionally, enter the password on the command line.
//  
//  Note:                   NET USE will prompt for the password if it is not on the
//                          command line and will automatically assign a drive letter
//                          to the connection if it successfully connects.
//  
//  drive-letter            The drive letter that NET USE as assigned to a
//                          server connection.
//  
//  /d                      Indicates that this connection is to be disconnected.
//  
//
#define MSG_NET_USE_HELP                 0x00000085L

//
// MessageId: MSG_NET_USE_PROMPT_PASSWORD
//
// MessageText:
//
//  Please enter your password: %0
//
#define MSG_NET_USE_PROMPT_PASSWORD      0x00000086L

//
// MessageId: MSG_NET_USE_ERROR
//
// MessageText:
//
//  NET USE failed.
//
#define MSG_NET_USE_ERROR                0x00000087L

//
// MessageId: MSG_NET_USE_DRIVE_LETTER
//
// MessageText:
//
//  %1 has been mapped to drive letter %2.
//
#define MSG_NET_USE_DRIVE_LETTER         0x00000088L

//
// MessageId: MSG_CONNECTION_IN_USE
//
// MessageText:
//
//  There are open files and/or incomplete directory
//  searches pending on the connection.
//
#define MSG_CONNECTION_IN_USE            0x00000089L

//
// MessageId: MSG_INSTALL_SELECT_ERROR
//
// MessageText:
//
//  
//  Invalid selection.  Please select a valid installation number.
//
#define MSG_INSTALL_SELECT_ERROR         0x0000008AL

//
// MessageId: MSG_ATTRIB_HELP
//
// MessageText:
//
//  Changes attributes on one file or directory.
//  
//  ATTRIB -R|+R|-S|+S|-H|+H|-C|+C filename
//  
//    +   Sets an attribute.
//    -   Clears an attribute.
//    R   Read-only file attribute.
//    S   System file attribute.
//    H   Hidden file attribute.
//    C   Compressed file attribute.
//  
//  To view attributes, use the DIR command.
//
#define MSG_ATTRIB_HELP                  0x0000008BL

//
// MessageId: MSG_EXIT_HELP
//
// MessageText:
//
//  Use the EXIT command to quit the Recovery Console and restart the computer.
//  
//
#define MSG_EXIT_HELP                    0x0000008CL

//
// MessageId: MSG_LISTSVC_HELP
//
// MessageText:
//
//  The LISTSVC command lists all available services and drivers on the
//  computer.
//
#define MSG_LISTSVC_HELP                 0x0000008EL

//
// MessageId: MSG_LOGON_PROMPT_SYSKEY_PASSWORD
//
// MessageText:
//
//  Type the startup password: %0
//
#define MSG_LOGON_PROMPT_SYSKEY_PASSWORD 0x0000008FL

//
// MessageId: MSG_LOGON_PROMPT_SYSKEY_FLOPPY
//
// MessageText:
//
//  Startup Key Disk
//
#define MSG_LOGON_PROMPT_SYSKEY_FLOPPY   0x00000090L

//
// MessageId: MSG_EXPAND_HELP
//
// MessageText:
//
//  Expands a compressed file.
//  
//  EXPAND source [/F:filespec] [destination] [/Y]
//  EXPAND source [/F:filespec] /D
//  
//    source       Specifies the file to be expanded.  May not include
//                 wildcards.
//  
//    destination  Specifies the directory for the new file.  Default is the
//                 current directory.
//  
//    /Y           Do not prompt before overwriting an existing file.
//  
//    /F:filespec  If the source contains more than one file, this parameter
//                 is required to identify the specific file(s) to be expanded.
//                 May include wildcards.
//  
//    /D           Do not expand; only display a directory of the files which
//                 are contained in the source.
//  
//  The destination may be any directory within the system directories
//  of the current Windows installation, the root of any drive, the local
//  installation sources, or the cmdcons directory.
//  
//  The destination cannot be removable media.
//  
//  The destination file cannot be read-only.  Use the ATTRIB command to remove
//  the read-only attribute.
//  
//  EXPAND prompts if the destination file already exists unless /Y is used.
//
#define MSG_EXPAND_HELP                  0x00000091L

//
// MessageId: MSG_CANT_EXPAND_FILE
//
// MessageText:
//
//  The file could not be expanded.
//
#define MSG_CANT_EXPAND_FILE             0x00000092L

//
// MessageId: MSG_EXPAND_COUNT
//
// MessageText:
//
//          %1!u! file(s) expanded.
//
#define MSG_EXPAND_COUNT                 0x00000093L

//
// MessageId: MSG_EXPAND_SHOWN
//
// MessageText:
//
//          %1!u! file(s).
//
#define MSG_EXPAND_SHOWN                 0x00000094L

//
// MessageId: MSG_EXPAND_NO_MATCH
//
// MessageText:
//
//  No files matching '%1' in %2.
//
#define MSG_EXPAND_NO_MATCH              0x00000095L

//
// MessageId: MSG_COPY_OVERWRITE_QUIT
//
// MessageText:
//
//  Overwrite %1? (Yes/No/All/Quit): %0
//
#define MSG_COPY_OVERWRITE_QUIT          0x00000096L

//
// MessageId: MSG_YESNOALLQUIT
//
// MessageText:
//
//  nNyYaAqQ
//
#define MSG_YESNOALLQUIT                 0x00000097L

//
// MessageId: MSG_FILESPEC_REQUIRED
//
// MessageText:
//
//  The source file contains multiple files.  The -F:filespec option is
//  required to specify which file(s) are to be expanded.  -F:* may be
//  used to expand all files.
//
#define MSG_FILESPEC_REQUIRED            0x00000098L

//
// MessageId: MSG_BREAK
//
// MessageText:
//
//  ^C
//
#define MSG_BREAK                        0x00000099L

//
// MessageId: MSG_EXPANDED
//
// MessageText:
//
//  %1
//
#define MSG_EXPANDED                     0x0000009AL

//
// MessageId: MSG_EXPAND_FAILED
//
// MessageText:
//
//  Unable to create file %1.
//
#define MSG_EXPAND_FAILED                0x0000009BL

//
// MessageId: MSG_SETCMD_HELP
//
// MessageText:
//
//  Displays and sets Recovery Console environment variables
//  
//  SET [variable = parameter]
//  
//  SET AllowWildCards = TRUE
//  
//  To display a list of Recovery Console environment variables, type SET without 
//  parameters.
//  
//  The Recovery Console supports the following environment variables:
//  
//  AllowWildCards       Enable wildcard support for some commands (such as the
//                       DEL command).
//  
//  AllowAllPaths        Allow access to all files and folders on the computer.
//  
//  AllowRemovableMedia  Allow files to be copied to removable media, such as a 
//                       floppy disk.
//  
//  NoCopyPrompt         Do not prompt when overwriting an existing file.
//  
//  The SET command is an optional Recovery Console command that can only be 
//  enabled by using the Group Policy snap-in. 
//
#define MSG_SETCMD_HELP                  0x0000009CL

//
// MessageId: MSG_SETCMD_DISABLED
//
// MessageText:
//
//  The SET command is currently disabled. The SET command is an optional
//  Recovery Console command that can only be enabled by using the the 
//  Security Configuration and Analysis snap-in. 
//
#define MSG_SETCMD_DISABLED              0x0000009DL

//
// MessageId: MSG_FIXBOOT_ARE_YOU_SURE
//
// MessageText:
//
//  Are you sure you want to write a new bootsector to the partition %1 ? %0
//
#define MSG_FIXBOOT_ARE_YOU_SURE         0x0000009EL

//
// MessageId: MSG_FDISK_INVALID_PARTITION_SIZE
//
// MessageText:
//
//  Cannot create a new partition of size %1 MB on disk %2.
//
#define MSG_FDISK_INVALID_PARTITION_SIZE 0x0000009FL

//
// MessageId: MSG_ATTRIB_CANNOT_CHANGE_COMPRESSION
//
// MessageText:
//
//  Cannot change the compression attribute for the specified file or directory.
//
#define MSG_ATTRIB_CANNOT_CHANGE_COMPRESSION 0x000000A0L

//
// MessageId: MSG_BATCH_BATCH
//
// MessageText:
//
//  Batch file cannot contain BATCH command.
//
#define MSG_BATCH_BATCH                  0x000000A1L

//
// MessageId: MSG_SVCTYPE_BOOT
//
// MessageText:
//
//  Boot
//
#define MSG_SVCTYPE_BOOT                 0x000000A2L

//
// MessageId: MSG_SVCTYPE_SYSTEM
//
// MessageText:
//
//  System
//
#define MSG_SVCTYPE_SYSTEM               0x000000A3L

//
// MessageId: MSG_SVCTYPE_AUTO
//
// MessageText:
//
//  Auto
//
#define MSG_SVCTYPE_AUTO                 0x000000A4L

//
// MessageId: MSG_SVCTYPE_MANUAL
//
// MessageText:
//
//  Manual
//
#define MSG_SVCTYPE_MANUAL               0x000000A5L

//
// MessageId: MSG_SVCTYPE_DISABLED
//
// MessageText:
//
//  Disabled
//
#define MSG_SVCTYPE_DISABLED             0x000000A6L

//
// MessageId: MSG_VERIFIER_HELP
//
// MessageText:
//
//  verifier [ /flags FLAGS [ /iolevel IOLEVEL ] ] /all
//  verifier [ /flags FLAGS [ /iolevel IOLEVEL ] ] /driver NAME [NAME ...]
//  verifier /reset
//  verifier /query
//  
//  FLAGS is a decimal combination of bits:
//  
//      bit 0 - special pool checking
//      bit 1 - force irql checking
//      bit 2 - low resources simulation
//      bit 3 - pool tracking
//      bit 4 - I/O verification
//  
//  IOLEVEL can have one the following values:
//  
//      1 - I/O verification level 1
//      2 - I/O verification level 2 (more strict than level 1)
//  
//      The default I/O verification level is 1.
//      The value is ignored if the I/O verification bit is not set in FLAGS.
//  
//  Multiple driver names should be separated by space. You can use wildcards 
//  for multiple names e.g. *.sys for all the driver names ending with ".sys".
//
#define MSG_VERIFIER_HELP                0x000000A7L

//
// MessageId: MSG_BOOTCFG_HELP
//
// MessageText:
//
//  Use the BOOTCFG command for boot configuration and recovery
//  
//  BOOTCFG /ADD 
//  BOOTCFG /REBUILD 
//  BOOTCFG /SCAN
//  BOOTCFG /LIST
//  BOOTCFG /DISABLEEMS
//  BOOTCFG /EMS [PORT BAUDRATE] | [useBiosSettings]
//  
//    /SCAN           Scan all disks for Windows installations and display 
//                    the results
//    
//    /ADD            Add a Windows installation to the boot list 
//  
//    /REBUILD        Iterate through all Windows installations and allow
//                    the user to choose which to add
//      
//    /DEFAULT        Set the default boot entry
//  
//    /LIST           List the entries already in the boot list
//  
//    /DISABLEEMS     Disable redirection in the boot loader
//  
//    /EMS            Enable redirection in the boot loader with the specified 
//                    configuration
//                    
//                    example: bootcfg /ems com1 115200
//                             bootcfg /ems useBiosSettings
//    
//
#define MSG_BOOTCFG_HELP                 0x000000A8L

//
// MessageId: MSG_BOOTCFG_SCAN_RESULTS_TITLE
//
// MessageText:
//
//  
//  The Windows installation scan was successful.
//   
//  Note: These results are stored statically for this session.
//        If the disk configuration changes during this session,
//        in order to get an updated scan, you must first reboot
//        the machine and then rescan the disks.
//  
//  Total identified Windows installs: %1!u!
//  
//
#define MSG_BOOTCFG_SCAN_RESULTS_TITLE   0x000000A9L

//
// MessageId: MSG_BOOTCFG_SCAN_RESULTS_ENTRY
//
// MessageText:
//
//  [%1!u!]: %2!c!:%3
//
#define MSG_BOOTCFG_SCAN_RESULTS_ENTRY   0x000000AAL

//
// MessageId: MSG_BOOTCFG_SCAN_FAILURE
//
// MessageText:
//
//  
//  Error: Failed to succcessfully scan disks for Windows installations.
//         This error may be caused by a corrupt file system, which would
//         prevent Bootcfg from successfully scanning.  Use chkdsk to
//             detect any disk errors.
//  
//  Note: This operation must complete successfully in order for the 
//        /add or /rebuild commands to be utilized.
//  
//
#define MSG_BOOTCFG_SCAN_FAILURE         0x000000ABL

//
// MessageId: MSG_BOOTCFG_INSTALL_DISCOVERY_QUERY
//
// MessageText:
//
//  Add installation to boot list? (Yes/No/All): %0 
//
#define MSG_BOOTCFG_INSTALL_DISCOVERY_QUERY 0x000000ACL

//
// MessageId: MSG_BOOTCFG_INSTALL_LOADIDENTIFIER_QUERY
//
// MessageText:
//
//  Enter Load Identifier: %0
//
#define MSG_BOOTCFG_INSTALL_LOADIDENTIFIER_QUERY 0x000000ADL

//
// MessageId: MSG_BOOTCFG_INSTALL_OSLOADOPTIONS_QUERY
//
// MessageText:
//
//  Enter OS Load Options: %0
//
#define MSG_BOOTCFG_INSTALL_OSLOADOPTIONS_QUERY 0x000000AEL

//
// MessageId: MSG_BOOTCFG_SCAN_NOTIFICATION
//
// MessageText:
//
//  
//  Scanning all disks for Windows installations.  
//  
//  Please wait, since this may take a while...
//
#define MSG_BOOTCFG_SCAN_NOTIFICATION    0x000000AFL

//
// MessageId: MSG_BOOTCFG_LIST_NO_ENTRIES
//
// MessageText:
//
//  
//  There are currently no boot entries available to display.
//  
//
#define MSG_BOOTCFG_LIST_NO_ENTRIES      0x000000B0L

//
// MessageId: MSG_BOOTCFG_EXPORT_HEADER
//
// MessageText:
//
//  
//  Total entries in boot list: %1!u!
//
#define MSG_BOOTCFG_EXPORT_HEADER        0x000000B1L

//
// MessageId: MSG_BOOTCFG_EXPORT_ENTRY
//
// MessageText:
//
//  
//  [%1!u!] %2
//  OS Load Options: %3
//  OS Location: %4!c!:%5
//
#define MSG_BOOTCFG_EXPORT_ENTRY         0x000000B2L

//
// MessageId: MSG_BOOTCFG_BATCH_LOADID
//
// MessageText:
//
//  Windows Installation %0
//
#define MSG_BOOTCFG_BATCH_LOADID         0x000000B3L

//
// MessageId: MSG_BOOTCFG_ADD_QUERY
//
// MessageText:
//
//  
//  Select installation to add: %0
//
#define MSG_BOOTCFG_ADD_QUERY            0x000000B4L

//
// MessageId: MSG_BOOTCFG_INVALID_SELECTION
//
// MessageText:
//
//  
//  Invalid selection: %1
//  
//
#define MSG_BOOTCFG_INVALID_SELECTION    0x000000B5L

//
// MessageId: MSG_BOOTCFG_REDIRECT_FAILURE_UPDATING
//
// MessageText:
//
//  
//  Error: Failed to update headless redirection configuration.
//  
//
#define MSG_BOOTCFG_REDIRECT_FAILURE_UPDATING 0x000000B6L

//
// MessageId: MSG_BOOTCFG_ENABLE_REDIRECT_SUCCESS
//
// MessageText:
//
//  
//  Headless redirection has been enabled using:
//  
//      Port: %1
//  Baudrate: %2
//  
//
#define MSG_BOOTCFG_ENABLE_REDIRECT_SUCCESS 0x000000B7L

//
// MessageId: MSG_BOOTCFG_ENABLE_REDIRECT_PORT_SUCCESS
//
// MessageText:
//
//  
//  Headless redirection has been enabled using:
//  
//      Port: %1
//  Baudrate: [default]
//  
//
#define MSG_BOOTCFG_ENABLE_REDIRECT_PORT_SUCCESS 0x000000B8L

//
// MessageId: MSG_BOOTCFG_DISABLEREDIRECT_SUCCESS
//
// MessageText:
//
//  
//  Headless redirection has been disabled.
//  
//
#define MSG_BOOTCFG_DISABLEREDIRECT_SUCCESS 0x000000B9L

//
// MessageId: MSG_BOOTCFG_DEFAULT_SUCCESS
//
// MessageText:
//
//  
//  The selected boot entry is now the default.
//  
//
#define MSG_BOOTCFG_DEFAULT_SUCCESS      0x000000BAL

//
// MessageId: MSG_BOOTCFG_DEFAULT_FAILURE
//
// MessageText:
//
//  
//  Error: Failed to set default boot entry.
//  
//
#define MSG_BOOTCFG_DEFAULT_FAILURE      0x000000BBL

//
// MessageId: MSG_BOOTCFG_ADD_NOT_FOUND
//
// MessageText:
//
//  
//  Error: Could not add installation %1 since this entry could
//         not be found in the available installations list.
//  
//
#define MSG_BOOTCFG_ADD_NOT_FOUND        0x000000BCL

//
// MessageId: MSG_BOOTCFG_BOOTLIST_ADD_FAILURE
//
// MessageText:
//
//  
//  Error: Failed to add the selected boot entry to the boot list. 
//  
//
#define MSG_BOOTCFG_BOOTLIST_ADD_FAILURE 0x000000BDL

//
// MessageId: MSG_BOOTCFG_DEFAULT_NO_ENTRIES
//
// MessageText:
//
//  
//  There are currently no boot entries, therefore the default 
//  boot entry cannot be set.  You must first use /add or 
//  /rebuild to add a Windows installation to the boot list.
//  
//
#define MSG_BOOTCFG_DEFAULT_NO_ENTRIES   0x000000BEL

