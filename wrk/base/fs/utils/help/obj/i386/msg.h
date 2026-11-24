/*++ BUILD Version: 0e001    // Increment this if a change has global effects

Copyright (c) 2001  Microsoft Corporation

Module Name:

    helpmsg.mc

Abstract:

    This file contains the message definitions for the Win32 HELP.EXE
    program.

Author:

    Mark Zbikowski 5-18-2001

Revision History:

Notes:

    There are two sets of messages.  The first, header messages are
    used to display generic one-line help messages.  The second,
    one-line help messages are also used to cue HELP to spawn 
    the specific commands for more detail.  Thus, the command name
    must come first in the line and be terminated with a SPACE.

    The message numbers and #defines must be:

    HELP_USAGE_MESSAGE
    ... other abnormal messages
    HELP_FIRST_HELP_MESSAGE
    ... other header messages
    HELP_FIRST_COMMAND_HELP_MESSAGE
    ... other one-line help messages
    HELP_LAST_HELP_MESSAGE
   

--*/
#ifndef _HELPMSG_
#define _HELPMSG_
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
// MessageId: HELP_USAGE_MESSAGE
//
// MessageText:
//
//  Provides help information for Windows commands.
//  
//  HELP [command]
//  
//      command - displays help information on that command.
//
#define HELP_USAGE_MESSAGE               0x00005A4DL

//
// MessageId: HELP_NOT_FOUND_MESSAGE
//
// MessageText:
//
//  This command is not supported by the help utility.  Try "%1 /?".
//
#define HELP_NOT_FOUND_MESSAGE           0x00005A4EL

#define HELP_FIRST_HELP_MESSAGE HELP_HEADER_MESSAGE
//
// MessageId: HELP_HEADER_MESSAGE
//
// MessageText:
//
//  For more information on a specific command, type HELP command-name
//
#define HELP_HEADER_MESSAGE              0x00005A4FL

#define HELP_FIRST_COMMAND_HELP_MESSAGE HELP_ASSOC_HELP_MESSAGE
//
// MessageId: HELP_ASSOC_HELP_MESSAGE
//
// MessageText:
//
//  ASSOC          Displays or modifies file extension associations.
//
#define HELP_ASSOC_HELP_MESSAGE          0x00005A50L

//
// MessageId: HELP_ATTRIB_HELP_MESSAGE
//
// MessageText:
//
//  ATTRIB         Displays or changes file attributes.
//
#define HELP_ATTRIB_HELP_MESSAGE         0x00005A51L

//
// MessageId: HELP_BREAK_HELP_MESSAGE
//
// MessageText:
//
//  BREAK          Sets or clears extended CTRL+C checking.
//
#define HELP_BREAK_HELP_MESSAGE          0x00005A52L

//
// MessageId: HELP_BOOTCFG_HELP_MESSAGE
//
// MessageText:
//
//  BOOTCFG        Sets properties in boot.ini file to control boot loading.
//
#define HELP_BOOTCFG_HELP_MESSAGE        0x00005A53L

//
// MessageId: HELP_CACLS_HELP_MESSAGE
//
// MessageText:
//
//  CACLS          Displays or modifies access control lists (ACLs) of files.
//
#define HELP_CACLS_HELP_MESSAGE          0x00005A54L

//
// MessageId: HELP_CALL_HELP_MESSAGE
//
// MessageText:
//
//  CALL           Calls one batch program from another.
//
#define HELP_CALL_HELP_MESSAGE           0x00005A55L

//
// MessageId: HELP_CD_HELP_MESSAGE
//
// MessageText:
//
//  CD             Displays the name of or changes the current directory.
//
#define HELP_CD_HELP_MESSAGE             0x00005A56L

//
// MessageId: HELP_CHCP_HELP_MESSAGE
//
// MessageText:
//
//  CHCP           Displays or sets the active code page number.
//
#define HELP_CHCP_HELP_MESSAGE           0x00005A57L

//
// MessageId: HELP_CHDIR_HELP_MESSAGE
//
// MessageText:
//
//  CHDIR          Displays the name of or changes the current directory.
//
#define HELP_CHDIR_HELP_MESSAGE          0x00005A58L

//
// MessageId: HELP_CHKDSK_HELP_MESSAGE
//
// MessageText:
//
//  CHKDSK         Checks a disk and displays a status report.
//
#define HELP_CHKDSK_HELP_MESSAGE         0x00005A59L

//
// MessageId: HELP_CHKNTFS_HELP_MESSAGE
//
// MessageText:
//
//  CHKNTFS        Displays or modifies the checking of disk at boot time.
//
#define HELP_CHKNTFS_HELP_MESSAGE        0x00005A5AL

//
// MessageId: HELP_CLS_HELP_MESSAGE
//
// MessageText:
//
//  CLS            Clears the screen.
//
#define HELP_CLS_HELP_MESSAGE            0x00005A5BL

//
// MessageId: HELP_CMD_HELP_MESSAGE
//
// MessageText:
//
//  CMD            Starts a new instance of the Windows command interpreter.
//
#define HELP_CMD_HELP_MESSAGE            0x00005A5CL

//
// MessageId: HELP_COLOR_HELP_MESSAGE
//
// MessageText:
//
//  COLOR          Sets the default console foreground and background colors.
//
#define HELP_COLOR_HELP_MESSAGE          0x00005A5DL

//
// MessageId: HELP_COMP_HELP_MESSAGE
//
// MessageText:
//
//  COMP           Compares the contents of two files or sets of files.
//
#define HELP_COMP_HELP_MESSAGE           0x00005A5EL

//
// MessageId: HELP_COMPACT_HELP_MESSAGE
//
// MessageText:
//
//  COMPACT        Displays or alters the compression of files on NTFS partitions.
//
#define HELP_COMPACT_HELP_MESSAGE        0x00005A5FL

//
// MessageId: HELP_CONVERT_HELP_MESSAGE
//
// MessageText:
//
//  CONVERT        Converts FAT volumes to NTFS.  You cannot convert the
//                 current drive.
//
#define HELP_CONVERT_HELP_MESSAGE        0x00005A60L

//
// MessageId: HELP_COPY_HELP_MESSAGE
//
// MessageText:
//
//  COPY           Copies one or more files to another location.
//
#define HELP_COPY_HELP_MESSAGE           0x00005A61L

//
// MessageId: HELP_DATE_HELP_MESSAGE
//
// MessageText:
//
//  DATE           Displays or sets the date.
//
#define HELP_DATE_HELP_MESSAGE           0x00005A62L

//
// MessageId: HELP_DEL_HELP_MESSAGE
//
// MessageText:
//
//  DEL            Deletes one or more files.
//
#define HELP_DEL_HELP_MESSAGE            0x00005A63L

//
// MessageId: HELP_DIR_HELP_MESSAGE
//
// MessageText:
//
//  DIR            Displays a list of files and subdirectories in a directory.
//
#define HELP_DIR_HELP_MESSAGE            0x00005A64L

//
// MessageId: HELP_DISKCOMP_HELP_MESSAGE
//
// MessageText:
//
//  DISKCOMP       Compares the contents of two floppy disks.
//
#define HELP_DISKCOMP_HELP_MESSAGE       0x00005A65L

//
// MessageId: HELP_DISKCOPY_HELP_MESSAGE
//
// MessageText:
//
//  DISKCOPY       Copies the contents of one floppy disk to another.
//
#define HELP_DISKCOPY_HELP_MESSAGE       0x00005A66L

//
// MessageId: HELP_DISKPART_HELP_MESSAGE
//
// MessageText:
//
//  DISKPART       Displays or configures Disk Partition properties.
//
#define HELP_DISKPART_HELP_MESSAGE       0x00005A67L

//
// MessageId: HELP_DOSKEY_HELP_MESSAGE
//
// MessageText:
//
//  DOSKEY         Edits command lines, recalls Windows commands, and 
//                 creates macros.
//
#define HELP_DOSKEY_HELP_MESSAGE         0x00005A68L

//
// MessageId: HELP_DRIVERQUERY_HELP_MESSAGE
//
// MessageText:
//
//  DRIVERQUERY    Displays current device driver status and properties.
//
#define HELP_DRIVERQUERY_HELP_MESSAGE    0x00005A69L

//
// MessageId: HELP_ECHO_HELP_MESSAGE
//
// MessageText:
//
//  ECHO           Displays messages, or turns command echoing on or off.
//
#define HELP_ECHO_HELP_MESSAGE           0x00005A6AL

//
// MessageId: HELP_ENDLOCAL_HELP_MESSAGE
//
// MessageText:
//
//  ENDLOCAL       Ends localization of environment changes in a batch file.
//
#define HELP_ENDLOCAL_HELP_MESSAGE       0x00005A6BL

//
// MessageId: HELP_ERASE_HELP_MESSAGE
//
// MessageText:
//
//  ERASE          Deletes one or more files.
//
#define HELP_ERASE_HELP_MESSAGE          0x00005A6CL

//
// MessageId: HELP_EVENTQUERY_HELP_MESSAGE
//
// MessageText:
//
//  EVENTQUERY     Displays event log entries for specified criteria.
//
#define HELP_EVENTQUERY_HELP_MESSAGE     0x00005A6DL

//
// MessageId: HELP_EXIT_HELP_MESSAGE
//
// MessageText:
//
//  EXIT           Quits the CMD.EXE program (command interpreter).
//
#define HELP_EXIT_HELP_MESSAGE           0x00005A6EL

//
// MessageId: HELP_FC_HELP_MESSAGE
//
// MessageText:
//
//  FC             Compares two files or sets of files, and displays the 
//                 differences between them.
//
#define HELP_FC_HELP_MESSAGE             0x00005A6FL

//
// MessageId: HELP_FIND_HELP_MESSAGE
//
// MessageText:
//
//  FIND           Searches for a text string in a file or files.
//
#define HELP_FIND_HELP_MESSAGE           0x00005A70L

//
// MessageId: HELP_FINDSTR_HELP_MESSAGE
//
// MessageText:
//
//  FINDSTR        Searches for strings in files.
//
#define HELP_FINDSTR_HELP_MESSAGE        0x00005A71L

//
// MessageId: HELP_FOR_HELP_MESSAGE
//
// MessageText:
//
//  FOR            Runs a specified command for each file in a set of files.
//
#define HELP_FOR_HELP_MESSAGE            0x00005A72L

//
// MessageId: HELP_FORMAT_HELP_MESSAGE
//
// MessageText:
//
//  FORMAT         Formats a disk for use with Windows.
//
#define HELP_FORMAT_HELP_MESSAGE         0x00005A73L

//
// MessageId: HELP_FSUTIL_HELP_MESSAGE
//
// MessageText:
//
//  FSUTIL         Displays or configures the file system properties.
//
#define HELP_FSUTIL_HELP_MESSAGE         0x00005A74L

//
// MessageId: HELP_FTYPE_HELP_MESSAGE
//
// MessageText:
//
//  FTYPE          Displays or modifies file types used in file extension 
//                 associations.
//
#define HELP_FTYPE_HELP_MESSAGE          0x00005A75L

//
// MessageId: HELP_GOTO_HELP_MESSAGE
//
// MessageText:
//
//  GOTO           Directs the Windows command interpreter to a labeled line in 
//                 a batch program.
//
#define HELP_GOTO_HELP_MESSAGE           0x00005A76L

//
// MessageId: HELP_GPRESULT_HELP_MESSAGE
//
// MessageText:
//
//  GPRESULT       Displays Group Policy information for machine or user.
//
#define HELP_GPRESULT_HELP_MESSAGE       0x00005A77L

//
// MessageId: HELP_GRAFTABL_HELP_MESSAGE
//
// MessageText:
//
//  GRAFTABL       Enables Windows to display an extended character set in 
//                 graphics mode.
//
#define HELP_GRAFTABL_HELP_MESSAGE       0x00005A78L

//
// MessageId: HELP_HELP_HELP_MESSAGE
//
// MessageText:
//
//  HELP           Provides Help information for Windows commands.
//
#define HELP_HELP_HELP_MESSAGE           0x00005A79L

//
// MessageId: HELP_IF_HELP_MESSAGE
//
// MessageText:
//
//  IF             Performs conditional processing in batch programs.
//
#define HELP_IF_HELP_MESSAGE             0x00005A7AL

//
// MessageId: HELP_LABEL_HELP_MESSAGE
//
// MessageText:
//
//  LABEL          Creates, changes, or deletes the volume label of a disk.
//
#define HELP_LABEL_HELP_MESSAGE          0x00005A7BL

//
// MessageId: HELP_MD_HELP_MESSAGE
//
// MessageText:
//
//  MD             Creates a directory.
//
#define HELP_MD_HELP_MESSAGE             0x00005A7CL

//
// MessageId: HELP_MKDIR_HELP_MESSAGE
//
// MessageText:
//
//  MKDIR          Creates a directory.
//
#define HELP_MKDIR_HELP_MESSAGE          0x00005A7DL

//
// MessageId: HELP_MODE_HELP_MESSAGE
//
// MessageText:
//
//  MODE           Configures a system device.
//
#define HELP_MODE_HELP_MESSAGE           0x00005A7EL

//
// MessageId: HELP_MORE_HELP_MESSAGE
//
// MessageText:
//
//  MORE           Displays output one screen at a time.
//
#define HELP_MORE_HELP_MESSAGE           0x00005A7FL

//
// MessageId: HELP_MOVE_HELP_MESSAGE
//
// MessageText:
//
//  MOVE           Moves one or more files from one directory to another 
//                 directory.
//
#define HELP_MOVE_HELP_MESSAGE           0x00005A80L

//
// MessageId: HELP_OPENFILES_HELP_MESSAGE
//
// MessageText:
//
//  OPENFILES      Displays files opened by remote users for a file share.
//
#define HELP_OPENFILES_HELP_MESSAGE      0x00005A81L

//
// MessageId: HELP_PAGEFILECONFIG_HELP_MESSAGE
//
// MessageText:
//
//  PAGEFILECONFIG Displays or configures Pagefile properties.
//
#define HELP_PAGEFILECONFIG_HELP_MESSAGE 0x00005A82L

//
// MessageId: HELP_PATH_HELP_MESSAGE
//
// MessageText:
//
//  PATH           Displays or sets a search path for executable files.
//
#define HELP_PATH_HELP_MESSAGE           0x00005A83L

//
// MessageId: HELP_PAUSE_HELP_MESSAGE
//
// MessageText:
//
//  PAUSE          Suspends processing of a batch file and displays a message.
//
#define HELP_PAUSE_HELP_MESSAGE          0x00005A84L

//
// MessageId: HELP_POPD_HELP_MESSAGE
//
// MessageText:
//
//  POPD           Restores the previous value of the current directory saved by 
//                 PUSHD.
//
#define HELP_POPD_HELP_MESSAGE           0x00005A85L

//
// MessageId: HELP_PRINT_HELP_MESSAGE
//
// MessageText:
//
//  PRINT          Prints a text file.
//
#define HELP_PRINT_HELP_MESSAGE          0x00005A86L

//
// MessageId: HELP_PROMPT_HELP_MESSAGE
//
// MessageText:
//
//  PROMPT         Changes the Windows command prompt.
//
#define HELP_PROMPT_HELP_MESSAGE         0x00005A87L

//
// MessageId: HELP_PUSHD_HELP_MESSAGE
//
// MessageText:
//
//  PUSHD          Saves the current directory then changes it.
//
#define HELP_PUSHD_HELP_MESSAGE          0x00005A88L

//
// MessageId: HELP_RD_HELP_MESSAGE
//
// MessageText:
//
//  RD             Removes a directory.
//
#define HELP_RD_HELP_MESSAGE             0x00005A89L

//
// MessageId: HELP_RECOVER_HELP_MESSAGE
//
// MessageText:
//
//  RECOVER        Recovers readable information from a bad or defective disk.
//
#define HELP_RECOVER_HELP_MESSAGE        0x00005A8AL

//
// MessageId: HELP_REM_HELP_MESSAGE
//
// MessageText:
//
//  REM            Records comments (remarks) in batch files or CONFIG.SYS.
//
#define HELP_REM_HELP_MESSAGE            0x00005A8BL

//
// MessageId: HELP_REN_HELP_MESSAGE
//
// MessageText:
//
//  REN            Renames a file or files.
//
#define HELP_REN_HELP_MESSAGE            0x00005A8CL

//
// MessageId: HELP_RENAME_HELP_MESSAGE
//
// MessageText:
//
//  RENAME         Renames a file or files.
//
#define HELP_RENAME_HELP_MESSAGE         0x00005A8DL

//
// MessageId: HELP_REPLACE_HELP_MESSAGE
//
// MessageText:
//
//  REPLACE        Replaces files.
//
#define HELP_REPLACE_HELP_MESSAGE        0x00005A8EL

//
// MessageId: HELP_RMDIR_HELP_MESSAGE
//
// MessageText:
//
//  RMDIR          Removes a directory.
//
#define HELP_RMDIR_HELP_MESSAGE          0x00005A8FL

//
// MessageId: HELP_SET_HELP_MESSAGE
//
// MessageText:
//
//  SET            Displays, sets, or removes Windows environment variables.
//
#define HELP_SET_HELP_MESSAGE            0x00005A90L

//
// MessageId: HELP_SETLOCAL_HELP_MESSAGE
//
// MessageText:
//
//  SETLOCAL       Begins localization of environment changes in a batch file.
//
#define HELP_SETLOCAL_HELP_MESSAGE       0x00005A91L

//
// MessageId: HELP_SC_HELP_MESSAGE
//
// MessageText:
//
//  SC             Displays or configures services (background processes).
//
#define HELP_SC_HELP_MESSAGE             0x00005A92L

//
// MessageId: HELP_SCHTASKS_HELP_MESSAGE
//
// MessageText:
//
//  SCHTASKS       Schedules commands and programs to run on a computer.
//
#define HELP_SCHTASKS_HELP_MESSAGE       0x00005A93L

//
// MessageId: HELP_SHIFT_HELP_MESSAGE
//
// MessageText:
//
//  SHIFT          Shifts the position of replaceable parameters in batch files.
//
#define HELP_SHIFT_HELP_MESSAGE          0x00005A94L

//
// MessageId: HELP_SHUTDOWN_HELP_MESSAGE
//
// MessageText:
//
//  SHUTDOWN       Allows proper local or remote shutdown of machine.
//
#define HELP_SHUTDOWN_HELP_MESSAGE       0x00005A95L

//
// MessageId: HELP_SORT_HELP_MESSAGE
//
// MessageText:
//
//  SORT           Sorts input.
//
#define HELP_SORT_HELP_MESSAGE           0x00005A96L

//
// MessageId: HELP_START_HELP_MESSAGE
//
// MessageText:
//
//  START          Starts a separate window to run a specified program or command.
//
#define HELP_START_HELP_MESSAGE          0x00005A97L

//
// MessageId: HELP_SUBST_HELP_MESSAGE
//
// MessageText:
//
//  SUBST          Associates a path with a drive letter.
//
#define HELP_SUBST_HELP_MESSAGE          0x00005A98L

//
// MessageId: HELP_SYSTEMINFO_HELP_MESSAGE
//
// MessageText:
//
//  SYSTEMINFO     Displays machine specific properties and configuration.
//
#define HELP_SYSTEMINFO_HELP_MESSAGE     0x00005A99L

//
// MessageId: HELP_TASKLIST_HELP_MESSAGE
//
// MessageText:
//
//  TASKLIST       Displays all currently running tasks including services.
//
#define HELP_TASKLIST_HELP_MESSAGE       0x00005A9AL

//
// MessageId: HELP_TASKKILL_HELP_MESSAGE
//
// MessageText:
//
//  TASKKILL       Kill or stop a running process or application.
//
#define HELP_TASKKILL_HELP_MESSAGE       0x00005A9BL

//
// MessageId: HELP_TIME_HELP_MESSAGE
//
// MessageText:
//
//  TIME           Displays or sets the system time.
//
#define HELP_TIME_HELP_MESSAGE           0x00005A9CL

//
// MessageId: HELP_TITLE_HELP_MESSAGE
//
// MessageText:
//
//  TITLE          Sets the window title for a CMD.EXE session.
//
#define HELP_TITLE_HELP_MESSAGE          0x00005A9DL

//
// MessageId: HELP_TREE_HELP_MESSAGE
//
// MessageText:
//
//  TREE           Graphically displays the directory structure of a drive or 
//                 path.
//
#define HELP_TREE_HELP_MESSAGE           0x00005A9EL

//
// MessageId: HELP_TYPE_HELP_MESSAGE
//
// MessageText:
//
//  TYPE           Displays the contents of a text file.
//
#define HELP_TYPE_HELP_MESSAGE           0x00005A9FL

//
// MessageId: HELP_VER_HELP_MESSAGE
//
// MessageText:
//
//  VER            Displays the Windows version.
//
#define HELP_VER_HELP_MESSAGE            0x00005AA0L

//
// MessageId: HELP_VERIFY_HELP_MESSAGE
//
// MessageText:
//
//  VERIFY         Tells Windows whether to verify that your files are written
//                 correctly to a disk.
//
#define HELP_VERIFY_HELP_MESSAGE         0x00005AA1L

//
// MessageId: HELP_VOL_HELP_MESSAGE
//
// MessageText:
//
//  VOL            Displays a disk volume label and serial number.
//
#define HELP_VOL_HELP_MESSAGE            0x00005AA2L

//
// MessageId: HELP_XCOPY_HELP_MESSAGE
//
// MessageText:
//
//  XCOPY          Copies files and directory trees.
//
#define HELP_XCOPY_HELP_MESSAGE          0x00005AA3L

//
// MessageId: HELP_WMIC_HELP_MESSAGE
//
// MessageText:
//
//  WMIC           Displays WMI information inside interactive command shell.
//
#define HELP_WMIC_HELP_MESSAGE           0x00005AA4L

//
// MessageId: HELP_FOOTER_MESSAGE
//
// MessageText:
//
//  
//  For more information on tools see the command-line reference in the online help.
//
#define HELP_FOOTER_MESSAGE              0x00005AA5L

#define HELP_LAST_HELP_MESSAGE HELP_FOOTER_MESSAGE
#endif  // _HELPMSG_
