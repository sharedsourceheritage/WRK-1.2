/*++

Copyright (c) 1991  Microsoft Corporation

Module Name:

    msg.h

Abstract:

    This file contains the message definitions for the user-mode
    part of text setup.

Author:

    Ted Miller (tedm) 11-Aug-1993

Revision History:

Notes:

    This file is generated from msg.mc

    Durint text setup the screen is laid out with a header and status line;
    counting blank lines to separate them from the main message
    area, this results in a maximum screen message length of 26 lines.
    (There are a minimum of 32 lines total on the screen).

--*/

#ifndef _USETUP_MSG_
#define _USETUP_MSG_


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
// MessageId: SP_MSG_FIRST
//
// MessageText:
//
//  SP_MSG_FIRST
//
#define SP_MSG_FIRST                     0x00002328L

//
// MessageId: SP_SCRN_WELCOME
//
// MessageText:
//
//  %%IWelcome to Setup.
//  
//  This portion of the Setup program prepares Microsoft(R)
//  Windows(R) to run on your computer.
//  
//  
//       To set up Windows now, press ENTER.
//  
//       To repair or recover a Windows installation, press R.
//  
//       To quit Setup without installing Windows, press F3.
//  
//  
//  
//  
//
#define SP_SCRN_WELCOME                  0x00002329L

//
// MessageId: SP_SCRN_PARTITION_CMDCONS
//
// MessageText:
//
//  The following list shows the existing partitions and
//  unpartitioned space on this computer.
//  
//  Use the UP and DOWN ARROW keys to select an item in the list.
//  
//       To create a partition in the unpartitioned space, press C.
//  
//       To delete the selected partition, press D.
//  
//  
//
#define SP_SCRN_PARTITION_CMDCONS        0x0000232AL

//
// MessageId: SP_SCRN_PARTITION
//
// MessageText:
//
//  The following list shows the existing partitions and
//  unpartitioned space on this computer.
//  
//  Use the UP and DOWN ARROW keys to select an item in the list.
//  
//       To set up Windows on the selected item, press ENTER.
//  
//       To create a partition in the unpartitioned space, press C.
//  
//       To delete the selected partition, press D.
//  
//  
//  
//  
//  
//
#define SP_SCRN_PARTITION                0x0000232BL

//
// MessageId: SP_SCRN_CONFIRM_REMOVE_PARTITION
//
// MessageText:
//
//  You asked Setup to delete the partition
//  
//     %1
//  
//  on %2.
//  
//  
//       To delete this partition, press L.
//        CAUTION: All data on this partition will be lost.
//  
//       To return to the previous screen without
//        deleting the partition, press ESC.
//  
//  
//  
//  
//  
//
#define SP_SCRN_CONFIRM_REMOVE_PARTITION 0x0000232CL

//
// MessageId: SP_SCRN_CONFIRM_CREATE_PARTITION
//
// MessageText:
//
//  You asked Setup to create a new partition on
//  %1.
//  
//  
//       To create the new partition, enter a size below and
//        press ENTER.
//  
//       To go back to the previous screen without creating
//        the partition, press ESC.
//  
//  
//  The minimum size for the new partition is %2!5u! megabytes (MB).
//  The maximum size for the new partition is %3!5u! megabytes (MB).
//  
//  
//  
//  
//  
//
#define SP_SCRN_CONFIRM_CREATE_PARTITION 0x0000232DL

//
// MessageId: SP_SCRN_INVALID_MBR_0
//
// MessageText:
//
//  Setup has determined that your computer's startup hard disk is new
//  or has been erased, or that your computer is running an operating
//  system that is incompatible with Windows.
//  
//  If the hard disk is new or has been erased, or if you want to discard
//  its current contents, you can choose to continue Setup.
//  
//  If your computer is running an operating system that is incompatible
//  with Windows, continuing Setup may damage or destroy the existing
//  operating system.
//  
//    To continue Setup, press C.
//     CAUTION: Any data currently on your computer's startup hard disk
//     will be lost.
//  
//    To quit Setup, press F3.
//  
//  
//  
//  
//  
//
#define SP_SCRN_INVALID_MBR_0            0x0000232EL

//
// MessageId: SP_SCRN_TEXTSETUP_SUCCESS
//
// MessageText:
//
//  This portion of Setup has completed successfully.
//  
//
#define SP_SCRN_TEXTSETUP_SUCCESS        0x0000232FL

//
// MessageId: SP_SCRN_TEXTSETUP_FAILURE
//
// MessageText:
//
//  Windows has not been installed on this computer.
//  
//
#define SP_SCRN_TEXTSETUP_FAILURE        0x00002330L

//
// MessageId: SP_SCRN_FATAL_SIF_ERROR_LINE
//
// MessageText:
//
//  The following value in the .SIF file used by Setup is
//  corrupted or missing:
//  
//  Value %1!u! on line %2!u! in section [%3]
//  
//  Setup cannot continue. To quit Setup, press F3.
//  
//  
//  
//
#define SP_SCRN_FATAL_SIF_ERROR_LINE     0x00002331L

//
// MessageId: SP_SCRN_FATAL_SIF_ERROR_KEY
//
// MessageText:
//
//  The following value in the .SIF file used by Setup is
//  corrupted or missing:
//  
//  Value %1!u! on the line in section [%2]
//  with key "%3."
//  
//  Setup cannot continue. To quit Setup, press F3.
//  
//  
//  
//
#define SP_SCRN_FATAL_SIF_ERROR_KEY      0x00002332L

//
// MessageId: SP_SCRN_EXIT_CONFIRMATION
//
// MessageText:
//
//  +====================================================+
//  |  Windows is not completely set up on your          |
//  |  computer.  If you quit Setup now, you will need   |
//  |  to run Setup again to set up Windows.             |
//  |                                                    |
//  |      To continue Setup, press ENTER.              |
//  |      To quit Setup, press F3.                     |
//  *----------------------------------------------------*
//  |  F3=Quit  ENTER=Continue                           |
//  +====================================================+
//  
//  
//  
//  
//
#define SP_SCRN_EXIT_CONFIRMATION        0x00002333L

//
// MessageId: SP_SCRN_REGION_TOO_SMALL
//
// MessageText:
//
//  The partition or the unpartitioned space you selected is too small
//  for Windows. Select a partition or unpartitioned space of
//  at least %1!u! megabytes (MB).
//  
//  
//
#define SP_SCRN_REGION_TOO_SMALL         0x00002334L

//
// MessageId: SP_SCRN_FOREIGN_PARTITION
//
// MessageText:
//
//  Windows cannot recognize the partition you selected.
//  
//  Setup cannot install Windows on this partition. However,
//  you can go back to the previous screen, delete the partition,
//  and then select the resulting unpartitioned space.
//  Setup will then create a new partition on which you can install
//  Windows.
//  
//  
//  
//
#define SP_SCRN_FOREIGN_PARTITION        0x00002335L

//
// MessageId: SP_SCRN_UNKNOWN_FREESPACE
//
// MessageText:
//
//  Windows recognizes the partition you selected, but the
//  partition is unformatted or damaged. To install Windows
//  on this partition, Setup must reformat it.
//  
//  
//        To continue Setup using the selected partition, press C.
//         Setup will ask you again before reformatting the partition.
//  
//        To select a different partition, press ESC.
//  
//  
//  
//  
//
#define SP_SCRN_UNKNOWN_FREESPACE        0x00002336L

//
// MessageId: SP_SCRN_INSUFFICIENT_FREESPACE
//
// MessageText:
//
//  The partition you selected does not have enough free space for
//  the installation of Windows. Windows requires at least
//  %1!u! megabytes (MB) of free disk space.
//  
//  To install Windows on this partition, Setup must reformat it.
//  
//        To continue Setup using the selected partition, press C.
//         Setup will ask you again before reformatting the partition.
//  
//        To select a different partition, press ESC.
//  
//  
//  
//  
//  
//
#define SP_SCRN_INSUFFICIENT_FREESPACE   0x00002337L

//
// MessageId: SP_SCRN_PART_TABLE_FULL
//
// MessageText:
//
//  Setup cannot create a new partition in the space you
//  selected because the maximum number of partitions already
//  exists on the disk.
//  
//  To continue, press ENTER.
//  
//  
//
#define SP_SCRN_PART_TABLE_FULL          0x00002338L

//
// MessageId: SP_SCRN_INF_LINE_CORRUPT
//
// MessageText:
//
//  Line %1!u! of %2 is corrupted. Setup cannot continue.
//  
//  To quit Setup, press F3.
//  
//  
//
#define SP_SCRN_INF_LINE_CORRUPT         0x00002339L

//
// MessageId: SP_SCRN_NO_VALID_C_COLON
//
// MessageText:
//
//  To install Windows on the partition you selected,
//  Setup must write some startup files to the following disk:
//  
//      %1
//  
//  However, this disk does not contain a Windows-compatible
//  partition.
//  
//  To continue installing Windows, return to the partition selection
//  screen and create a Windows-compatible partition on the disk
//  above. If there is no free space on the disk, delete an existing
//  partition, and then create a new one.
//  
//  To return to the partition selection screen, press ENTER.
//  
//  
//  
//
#define SP_SCRN_NO_VALID_C_COLON         0x0000233AL

//
// MessageId: SP_SCRN_BOOT_MANAGER
//
// MessageText:
//
//  Setup has found Boot Manager software on your computer and must
//  temporarily disable the software to set up Windows.
//  
//  After Setup is complete, you can enable the Boot Manager by
//  using the Disk Management tool in Windows to mark the
//  Boot Manager partition as active.  Refer to your Windows
//  documentation for more information about Disk Management.
//  
//  
//  
//  
//
#define SP_SCRN_BOOT_MANAGER             0x0000233BL

//
// MessageId: SP_SCRN_OTHER_OS_ACTIVE
//
// MessageText:
//
//  The active partition on your computer contains another operating
//  system.
//  
//  To successfully complete the installation of Windows, Setup
//  must mark this partition inactive.
//  
//  If the other operating system does not support dual-booting
//  with Windows, you can use Disk Management (part of Computer
//  Management, in the Administrative Tools folder) to mark its
//  partition active when Setup is complete. However, doing this may
//  affect your ability to start Windows.
//  
//  
//  
//  
//  
//
#define SP_SCRN_OTHER_OS_ACTIVE          0x0000233CL

//
// MessageId: SP_SCRN_C_UNKNOWN
//
// MessageText:
//
//  Drive %1 is unformatted, damaged, or formatted with a file system
//  that is incompatible with Windows. To continue installing
//  Windows, Setup needs to format this drive.
//  
//        To format the drive and continue Setup, press F.
//         CAUTION: All data currently on the drive will be lost.
//  
//        To return to the previous screen without formatting
//         the drive, press ESC.
//  
//  
//  
//  
//
#define SP_SCRN_C_UNKNOWN                0x0000233DL

//
// MessageId: SP_SCRN_C_FULL
//
// MessageText:
//
//  Drive %2 does not have enough free disk space to contain
//  Windows startup files.
//  
//  You must have at least %1!u! kilobytes (KB) of free disk space on this
//  drive to install Windows.
//  
//  To continue installing Windows, Setup must format the drive.
//  
//        To format the drive and continue Setup, press F.
//         CAUTION: All data currently on the drive will be lost.
//  
//        To return to the previous screen without formatting the drive,
//         press ESC.
//  
//  
//  
//  
//  
//
#define SP_SCRN_C_FULL                   0x0000233EL

//
// MessageId: SP_SCRN_FORMAT_NEW_PART
//
// MessageText:
//
//  A new partition for Windows has been created on
//  
//  %1.
//  
//  This partition must now be formatted.
//  
//  From the list below, select a file system for the new partition.
//  Use the UP and DOWN ARROW keys to select the file system you want,
//  and then press ENTER.
//  
//  If you want to select a different partition for Windows,
//  press ESC.
//  
//  
//  
//  
//
#define SP_SCRN_FORMAT_NEW_PART          0x0000233FL

//
// MessageId: SP_SCRN_FORMAT_BAD_PART
//
// MessageText:
//
//  The partition is either too full, damaged, not formatted, or
//  formatted with an incompatible file system. To continue installing
//  Windows, Setup must format this partition.
//  
//  %1
//  on %2.
//  
//  CAUTION: Formatting will delete any files on the partition.
//  
//  Use the UP and DOWN ARROW keys to select the file system you want,
//  and then press ENTER to continue.  If you want to select a different
//  partition for Windows, press ESC to go back.
//  
//  
//  
//  
//  
//
#define SP_SCRN_FORMAT_BAD_PART          0x00002340L

//
// MessageId: SP_SCRN_FORMAT_NEW_PART2
//
// MessageText:
//
//  The partition you selected is not formatted. Setup will now
//  format the partition.
//  
//  Use the UP and DOWN ARROW keys to select the file system
//  you want, and then press ENTER.
//  
//  If you want to select a different partition for Windows,
//  press ESC.
//  
//  
//  
//  
//  
//
#define SP_SCRN_FORMAT_NEW_PART2         0x00002341L

//
// MessageId: SP_SCRN_FS_OPTIONS
//
// MessageText:
//
//  Setup will install Windows on partition
//  
//  %1
//  
//  on %2.
//  
//  Use the UP and DOWN ARROW keys to select the file system
//  you want, and then press ENTER. If you want to select a
//  different partition for Windows, press ESC.
//  
//  
//
#define SP_SCRN_FS_OPTIONS               0x00002342L

//
// MessageId: SP_SCRN_CONFIRM_CONVERT
//
// MessageText:
//
//  CAUTION: Windows can use FAT or NTFS, but converting this drive to
//  NTFS will make this drive unusable by other operating systems
//  installed on this computer.
//  
//  Do not convert the drive to NTFS if you require access to the drive
//  when using other operating systems such as MS-DOS, Windows, OS/2, or
//  earlier versions of Windows NT.
//  
//  Confirm that you want to convert:
//  
//  %1
//  
//  on %2.
//  
//        To convert the drive to NTFS, press C.
//  
//        To select a different partition for Windows,
//         press ESC.
//  
//  
//  
//  
//  
//
#define SP_SCRN_CONFIRM_CONVERT          0x00002343L

//
// MessageId: SP_SCRN_CONFIRM_FORMAT
//
// MessageText:
//
//  CAUTION: Formatting this drive will delete all files on it.
//  Confirm that you want to format:
//  
//  %1
//  
//  on %2.
//  
//        To format the drive, press F.
//  
//        To select a different partition for Windows,
//         press ESC.
//  
//  
//  
//
#define SP_SCRN_CONFIRM_FORMAT           0x00002344L

//
// MessageId: SP_SCRN_SETUP_IS_FORMATTING
//
// MessageText:
//
//  Please wait while Setup formats the partition
//  
//  %1
//  
//  on %2.
//  
//  
//
#define SP_SCRN_SETUP_IS_FORMATTING      0x00002345L

//
// MessageId: SP_SCRN_FORMAT_ERROR
//
// MessageText:
//
//  Setup was unable to format the partition. The disk may be damaged.
//  
//  Make sure the drive is switched on and properly connected
//  to your computer. If the disk is a SCSI disk, make sure your SCSI
//  devices are properly terminated. Consult your computer manual or
//  SCSI adapter documentation for more information.
//  
//  You must select a different partition for Windows.
//  To continue, press ENTER.
//  
//  
//  
//  
//
#define SP_SCRN_FORMAT_ERROR             0x00002346L

//
// MessageId: SP_SCRN_ABOUT_TO_FORMAT_C
//
// MessageText:
//
//  Setup will now format drive %1.
//  
//  To continue, press ENTER.
//  
//  
//
#define SP_SCRN_ABOUT_TO_FORMAT_C        0x00002347L

//
// MessageId: SP_SCRN_REMOVE_EXISTING_NT
//
// MessageText:
//
//  You asked Setup to delete Windows system files from the
//  following folder. Confirm that you want to delete:
//  
//  %1
//  
//  CAUTION: After deleting system files from a Windows installation
//  you can no longer start that installation of Windows.
//  
//    To delete Windows system files from the above folder, press R.
//  
//    To go back to the previous screen without deleting any files,
//     press ESC.
//  
//  
//  
//  
//  
//  
//
#define SP_SCRN_REMOVE_EXISTING_NT       0x00002348L

//
// MessageId: SP_SCRN_DONE_REMOVING_EXISTING_NT
//
// MessageText:
//
//  Setup has finished deleting files.
//  
//  %1!u! bytes of disk space were freed.
//  
//  
//
#define SP_SCRN_DONE_REMOVING_EXISTING_NT 0x00002349L

//
// MessageId: SP_SCRN_WAIT_REMOVING_NT_FILES
//
// MessageText:
//
//  Please wait while Setup removes the Windows system files.
//  
//
#define SP_SCRN_WAIT_REMOVING_NT_FILES   0x0000234AL

//
// MessageId: SP_SCRN_CANT_LOAD_SETUP_LOG
//
// MessageText:
//
//  Setup cannot open the following log file:
//  
//  %1
//  
//  Setup cannot delete the Windows system files from the
//  selected installation. To continue, press ENTER.
//  
//  
//  
//
#define SP_SCRN_CANT_LOAD_SETUP_LOG      0x0000234BL

//
// MessageId: SP_SCRN_REMOVE_NT_FILES
//
// MessageText:
//
//  The partition you selected does not have enough free space for the
//  installation of Windows.  Setup has found existing Windows
//  installations in the following folders. Deleting one of them may free
//  enough disk space for Setup to install Windows on the partition
//  you selected.
//  
//  CAUTION: ALL files in a folder will be lost when the folder is
//  deleted.
//  
//    To select the Windows installation you want to delete,
//     use the UP and DOWN ARROW keys, and then press ENTER.
//  
//    If you want to format the partition you selected or you want to
//     install Windows on a different partition, press ESC.
//  
//  
//  
//  
//  
//  
//  
//  
//
#define SP_SCRN_REMOVE_NT_FILES          0x0000234CL

//
// MessageId: SP_SCRN_FATAL_FDISK_WRITE_ERROR
//
// MessageText:
//
//  An error occurred while Setup was updating partition information on:
//  
//  %1.
//  
//  Setup cannot continue. To quit Setup, press F3.
//  
//  
//
#define SP_SCRN_FATAL_FDISK_WRITE_ERROR  0x0000234DL

//
// MessageId: SP_SCRN_REMOVE_NT_FILES_WIN31
//
// MessageText:
//
//  The drive containing the earlier version of Windows is too full to
//  hold Windows. Setup has found existing Windows installations in
//  the following folders. Deleting one of these installations may free
//  enough disk space for Setup to continue.
//  
//  CAUTION: ALL files in a folder will be lost when the folder
//           is deleted.
//  
//    Use the UP and DOWN ARROW keys to select the Windows
//     installation you want to remove, and then press ENTER.
//  
//    If you want to install Windows on a different drive, press ESC
//     or move the highlight to "Do not remove any files" and press ENTER.
//  
//  
//  
//  
//  
//  
//  
//
#define SP_SCRN_REMOVE_NT_FILES_WIN31    0x0000234EL

//
// MessageId: SP_SCRN_WIN31_DRIVE_FULL
//
// MessageText:
//
//  Setup found Microsoft Windows 3.0 or 3.1 or Windows for
//  Workgroups 3.11 in the following folder:
//  
//      %1!c!:%2
//  
//  Setup cannot install Windows because the drive is too full.
//  Windows requires %3!u! megabytes (MB) of free disk space.
//  
//        To install Windows on this drive, press F3
//         to quit Setup. Delete any unneeded files from the drive,
//         and then run Setup again.
//  
//        To install to a different drive, press ENTER.
//  
//  
//  
//  
//  
//
#define SP_SCRN_WIN31_DRIVE_FULL         0x0000234FL

//
// MessageId: SP_SCRN_WIN31_UPGRADE
//
// MessageText:
//
//  Setup found Microsoft Windows 3.0 or 3.1 or Windows for
//  Workgroups 3.11 in the following folder:
//  
//      %1!c!:%2
//  
//  Setup can install Windows into this folder. If you install, you
//  will have to specify new settings and reinstall your applications.
//  
//        To install in this directory, press ENTER.
//         CAUTION: Do not select this option if you still use
//         the earlier version of Windows.
//  
//        To select a different folder for installation, press N.
//  
//  
//  
//  
//  
//  
//
#define SP_SCRN_WIN31_UPGRADE            0x00002350L

//
// MessageId: SP_SCRN_GETPATH_1
//
// MessageText:
//
//  Setup needs to copy Windows files onto your hard disk.
//  Select the folder in which the files should be copied:
//  
//  
//
#define SP_SCRN_GETPATH_1                0x00002351L

//
// MessageId: SP_SCRN_GETPATH_2
//
// MessageText:
//
//  To change the suggested location, press the BACKSPACE key
//  to delete characters, and then type the name of the folder
//  where you want to install Windows.
//  
//  
//
#define SP_SCRN_GETPATH_2                0x00002352L

//
// MessageId: SP_SCRN_INVALID_NTPATH
//
// MessageText:
//
//  The folder name you typed is not valid. Make sure the folder name
//  is not the root folder and does not contain any consecutive
//  backslash characters.
//  
//  Also make sure the folder name follows the standard MS-DOS
//  filename rules.
//  
//  To continue, press ENTER. Setup will prompt you to enter
//  a different folder name.
//  
//  
//  
//  
//  
//
#define SP_SCRN_INVALID_NTPATH           0x00002353L

//
// MessageId: SP_SCRN_NTPATH_EXISTS
//
// MessageText:
//
//  CAUTION: A %1 folder already exists that may contain a Windows
//  installation.  If you continue, the existing Windows installation
//  will be overwritten.
//  
//  All files, subfolders, user accounts, applications, security and
//  desktop settings for that Windows installation will be deleted.
//  The "My Documents" folder may also be deleted.
//  
//      To use the folder and delete the existing
//       Windows installation in it, press L.
//  
//      To use a different folder, press ESC.
//  
//      To quit Setup, press F3.
//  
//  
//  
//  
//  
//
#define SP_SCRN_NTPATH_EXISTS            0x00002355L

//
// MessageId: SP_SCRN_OUT_OF_MEMORY
//
// MessageText:
//
//  Setup is out of memory and cannot continue.
//  
//  To quit Setup, press F3.
//  
//  
//
#define SP_SCRN_OUT_OF_MEMORY            0x00002356L

//
// MessageId: SP_SCRN_HW_CONFIRM_1
//
// MessageText:
//
//  Setup has determined that your computer contains the following
//  hardware and software components.
//  
//  
//
#define SP_SCRN_HW_CONFIRM_1             0x00002357L

//
// MessageId: SP_SCRN_HW_CONFIRM_2
//
// MessageText:
//
//            Computer:
//             Display:
//            Keyboard:
//     Keyboard Layout:
//     Pointing Device:
//  
//          No Changes:
//  
//  
//  If you want to change any item in the list, press the UP or DOWN ARROW
//  key to move the highlight to the item you want to change. Then press
//  ENTER to see alternatives for that item.
//  
//  When all the items in the list are correct, move the highlight to
//  "The above list matches my computer" and press ENTER.
//  
//  
//  
//  
//  
//
#define SP_SCRN_HW_CONFIRM_2             0x00002358L

//
// MessageId: SP_SCRN_REGION_RESERVED
//
// MessageText:
//
//  The unpartitioned space you selected is reserved for Windows
//  partitioning information.
//  To create a new partition, go back to the previous screen, and
//  then select a different unpartitioned space.
//  
//  
//
#define SP_SCRN_REGION_RESERVED          0x00002359L

//
// MessageId: SP_SCRN_SELECT_COMPUTER
//
// MessageText:
//
//  You have asked to change the type of computer to be installed.
//  
//    To select a computer from the following list,
//     use the UP or DOWN ARROW key to move the highlight to
//     the computer type you want, and then press ENTER.
//  
//    To return to the previous screen without changing your
//     computer type, press ESC.
//  
//  
//  
//
#define SP_SCRN_SELECT_COMPUTER          0x0000235AL

//
// MessageId: SP_SCRN_SELECT_DISPLAY
//
// MessageText:
//
//  You have asked to change the type of display to be installed.
//  WARNING: The list below is extremely limited and may not contain
//  an item exactly corresponding to your display type. This is normal.
//  Setup will allow further configuration of your display type later.
//  
//  Changing your display type now is neither recommended nor necessary
//  unless you have a driver disk provided by a display adapter
//  manufacturer.
//  
//    To select a display from the following list, use the UP or DOWN ARROW
//     key to move the highlight to the type you want, and then press ENTER.
//  
//    To return to the previous screen without changing your display type,
//     press ESC.
//  
//  
//  
//  
//  
//  
//  
//
#define SP_SCRN_SELECT_DISPLAY           0x0000235BL

//
// MessageId: SP_SCRN_SELECT_KEYBOARD
//
// MessageText:
//
//  You have asked to change the type of keyboard to be installed.
//  
//    To select a keyboard from the following list,
//     use the UP or DOWN ARROW key to move the highlight to
//     the keyboard type you want, and then press ENTER.
//  
//    To return to the previous screen without changing your
//     keyboard type, press ESC.
//  
//  
//  
//
#define SP_SCRN_SELECT_KEYBOARD          0x0000235CL

//
// MessageId: SP_SCRN_SELECT_LAYOUT
//
// MessageText:
//
//  You have asked to change the type of keyboard layout to be installed.
//  
//    To select a keyboard layout from the following list,
//     use the UP or DOWN ARROW key to move the highlight to
//     the keyboard layout type you want, and then press ENTER.
//  
//    To return to the previous screen without changing your
//     keyboard layout type, press ESC.
//  
//  
//  
//
#define SP_SCRN_SELECT_LAYOUT            0x0000235DL

//
// MessageId: SP_SCRN_SELECT_MOUSE
//
// MessageText:
//
//  You have asked to change the type of pointing device to be installed.
//  
//    To select a pointing device from the following list,
//     use the UP or DOWN ARROW key to move the highlight to
//     the pointing device type you want, and then press ENTER.
//  
//    To return to the previous screen without changing your
//     pointing device type, press ESC.
//  
//  
//  
//
#define SP_SCRN_SELECT_MOUSE             0x0000235EL

//
// MessageId: SP_SCRN_SELECT_OEM_COMPUTER
//
// MessageText:
//
//  You have chosen to change your computer type to one supported
//  by a disk provided by a hardware manufacturer.
//  
//    To select a computer from the following list,
//     use the UP or DOWN ARROW key to move the highlight to
//     the computer type you want, and then press ENTER.
//  
//    To return to the previous screen without changing your
//     computer type, press ESC.
//  
//  
//  
//
#define SP_SCRN_SELECT_OEM_COMPUTER      0x0000235FL

//
// MessageId: SP_SCRN_SELECT_OEM_DISPLAY
//
// MessageText:
//
//  You have chosen to install a display provided by a hardware
//  manufacturer.
//  
//    To select a display from the following list,
//     use the UP or DOWN ARROW key to move the highlight to
//     the display type you want, and then press ENTER.
//  
//    To return to the previous screen without changing your display type,
//     press ESC.
//  
//  
//  
//
#define SP_SCRN_SELECT_OEM_DISPLAY       0x00002360L

//
// MessageId: SP_SCRN_SELECT_OEM_KEYBOARD
//
// MessageText:
//
//  You have chosen to install a keyboard provided by a hardware
//  manufacturer.
//  
//    To select a keyboard from the following list,
//     use the UP or DOWN ARROW key to move the highlight to
//     the keyboard type you want, and then press ENTER.
//  
//    To return to the previous screen without changing your
//     keyboard type, press ESC.
//  
//  
//  
//
#define SP_SCRN_SELECT_OEM_KEYBOARD      0x00002361L

//
// MessageId: SP_SCRN_SELECT_OEM_LAYOUT
//
// MessageText:
//
//  You have chosen to install a keyboard layout provided by a hardware
//  manufacturer.
//  
//    To select a keyboard layout from the following list,
//     use the UP or DOWN ARROW key to move the highlight to
//     the keyboard layout type you want, and then press ENTER.
//  
//    To return to the previous screen without changing your
//     keyboard layout type, press ESC.
//  
//  
//  
//
#define SP_SCRN_SELECT_OEM_LAYOUT        0x00002362L

//
// MessageId: SP_SCRN_SELECT_OEM_MOUSE
//
// MessageText:
//
//  You have chosen to install a pointing device provided by a hardware
//  manufacturer.
//  
//    To select a pointing device from the following list,
//     use the UP or DOWN ARROW key to move the highlight to
//     the pointing device type you want, and then press ENTER.
//  
//    To return to the previous screen without changing your
//     pointing device type, press ESC.
//  
//  
//  
//
#define SP_SCRN_SELECT_OEM_MOUSE         0x00002363L

//
// MessageId: SP_SCRN_FLOPPY_PROMPT
//
// MessageText:
//
//  Insert the disk labeled:
//  
//  %%I%1
//  
//  into drive %2!c!:
//  
//  
//  
//   Press ENTER when ready.
//  
//  
//
#define SP_SCRN_FLOPPY_PROMPT            0x00002364L

//
// MessageId: SP_SCRN_CDROM_PROMPT
//
// MessageText:
//
//  Insert the CD labeled:
//  
//  %%I%1
//  
//  into your CD-ROM drive.
//  
//  
//  
//   Press ENTER when ready.
//  
//  
//
#define SP_SCRN_CDROM_PROMPT             0x00002365L

//
// MessageId: SP_SCRN_REMOVE_FLOPPY
//
// MessageText:
//
//  If there is a floppy disk in drive A:, remove it.
//  
//
#define SP_SCRN_REMOVE_FLOPPY            0x00002366L

//
// MessageId: SP_SCRN_DISK_DAMAGED
//
// MessageText:
//
//  The disk or CD you inserted may be damaged.
//  
//  Press ENTER to try again. Make sure you are using
//  the correct disk or CD. If you continue to see this
//  message, try using a different copy of the disk or CD.
//  
//  
//  
//
#define SP_SCRN_DISK_DAMAGED             0x00002367L

//
// MessageId: SP_SCRN_NO_FLOPPY_FOR_OEM_DISK
//
// MessageText:
//
//  Setup cannot install hardware components provided by a hardware
//  manufacturer because there are no floppy disk drives in your computer.
//  
//  
//
#define SP_SCRN_NO_FLOPPY_FOR_OEM_DISK   0x00002368L

//
// MessageId: SP_SCRN_OEM_INF_ERROR
//
// MessageText:
//
//  A problem exists with the .SIF file on the manufacturer-
//  supplied disk:
//  
//  %1
//  
//  
//  Setup cannot use the disk or select an option. Contact the
//  hardware manufacturer.
//  
//  To continue, press ENTER.
//  
//  
//  
//
#define SP_SCRN_OEM_INF_ERROR            0x00002369L

//
// MessageId: SP_SCRN_UNKNOWN_COMPUTER
//
// MessageText:
//
//  Setup cannot continue until it knows the type of your computer.
//  
//
#define SP_SCRN_UNKNOWN_COMPUTER         0x0000236AL

//
// MessageId: SP_SCRN_UNKNOWN_DISPLAY
//
// MessageText:
//
//  Setup cannot continue until it knows the type of your display.
//  
//
#define SP_SCRN_UNKNOWN_DISPLAY          0x0000236BL

//
// MessageId: SP_SCRN_UNKNOWN_KEYBOARD
//
// MessageText:
//
//  Setup cannot continue until it knows the type of your keyboard.
//  
//
#define SP_SCRN_UNKNOWN_KEYBOARD         0x0000236CL

//
// MessageId: SP_SCRN_UNKNOWN_LAYOUT
//
// MessageText:
//
//  Setup cannot continue until it knows your keyboard layout type.
//  
//
#define SP_SCRN_UNKNOWN_LAYOUT           0x0000236DL

//
// MessageId: SP_SCRN_UNKNOWN_MOUSE
//
// MessageText:
//
//  Setup cannot continue until it knows the type of your pointing device.
//  
//
#define SP_SCRN_UNKNOWN_MOUSE            0x0000236EL

//
// MessageId: SP_SCRN_NO_HARD_DRIVES
//
// MessageText:
//
//  Setup did not find any hard disk drives installed in your computer.
//  
//  Make sure any hard disk drives are powered on and properly connected
//  to your computer, and that any disk-related hardware configuration is
//  correct. This may involve running a manufacturer-supplied diagnostic
//  or setup program.
//  
//  Setup cannot continue. To quit Setup, press F3.
//  
//  
//  
//
#define SP_SCRN_NO_HARD_DRIVES           0x0000236FL

//
// MessageId: SP_SCRN_CONFIRM_SCSI_DETECT
//
// MessageText:
//
//  Setup automatically detects floppy disk controllers and standard
//  ESDI/IDE hard disks without user intervention. However on some
//  computers detection of certain other mass storage devices, such as
//  SCSI adapters and CD-ROM drives, can cause the computer to become
//  unresponsive or to malfunction temporarily.
//  
//  For this reason, you can bypass Setup's mass storage device detection
//  and manually select SCSI adapters, CD-ROM drives, and special disk
//  controllers (such as drive arrays) for installation.
//  
//  
//       To continue, press ENTER.
//        Setup will attempt to detect mass storage devices in your computer.
//  
//       To skip mass storage device detection, press S.
//        Setup will allow you to manually select SCSI adapters,
//        CD-ROM drives, and special disk controllers for installation.
//  
//  
//  
//  
//  
//  
//  
//  
//
#define SP_SCRN_CONFIRM_SCSI_DETECT      0x00002370L

//
// MessageId: SP_SCRN_SCSI_LIST_1
//
// MessageText:
//
//  Setup has recognized the following mass storage devices in your computer:
//
#define SP_SCRN_SCSI_LIST_1              0x00002371L

//
// MessageId: SP_SCRN_SCSI_LIST_2
//
// MessageText:
//
//     To specify additional SCSI adapters, CD-ROM drives, or special
//      disk controllers for use with Windows, including those for which
//      you have a device support disk from a mass storage device
//      manufacturer, press S.
//  
//     If you do not have any device support disks from a mass storage
//      device manufacturer, or do not want to specify additional
//      mass storage devices for use with Windows, press ENTER.
//  
//  
//  
//  
//
#define SP_SCRN_SCSI_LIST_2              0x00002372L

//
// MessageId: SP_SCRN_SELECT_SCSI
//
// MessageText:
//
//  You have asked to specify an additional SCSI adapter, CD-ROM drive,
//  or special disk controller for use with Windows.
//  
//    To select a mass storage device from the following list,
//     use the UP or DOWN ARROW key to move the highlight to
//     the mass storage device you want, and then press ENTER.
//  
//    To return to the previous screen without specifying an additional
//     mass storage device for use with Windows, press ESC.
//  
//  
//  
//  
//
#define SP_SCRN_SELECT_SCSI              0x00002373L

//
// MessageId: SP_SCRN_SELECT_OEM_SCSI
//
// MessageText:
//
//  You have chosen to install a SCSI adapter, CD-ROM drive, or
//  special disk controller provided by a hardware manufacturer.
//  
//    To select a mass storage device from the following list,
//     use the UP or DOWN ARROW key to move the highlight to
//     the mass storage device you want, and then press ENTER.
//  
//    To return to the previous screen without specifying a mass storage
//     device for use with Windows, press ESC.
//  
//  
//  
//  
//  
//
#define SP_SCRN_SELECT_OEM_SCSI          0x00002374L

//
// MessageId: SP_SCRN_SCSI_DIDNT_LOAD
//
// MessageText:
//
//  The SCSI adapter, CD-ROM drive, or special disk controller you
//  specified is not installed in your computer.
//  
//  
//
#define SP_SCRN_SCSI_DIDNT_LOAD          0x00002375L

//
// MessageId: SP_SCRN_DIR_CREATE_ERR
//
// MessageText:
//
//  Setup cannot create the folder:
//  
//    %1
//  
//  
//  Setup cannot continue until the folder is created.
//  
//  
//       To retry, press ENTER.
//  
//       To quit Setup, press F3.
//  
//  
//  
//  
//  
//
#define SP_SCRN_DIR_CREATE_ERR           0x00002376L

//
// MessageId: SP_SCRN_COPY_FAILED
//
// MessageText:
//
//  Setup cannot copy the file: %1
//  
//     To retry, press ENTER.
//  
//      If you are installing from a CD, make sure the
//      Windows CD is in the CD-ROM drive.
//  
//     To skip this file, press ESC.
//  
//      CAUTION: If you skip this file, Setup may not complete
//      and Windows may not work properly.
//  
//     To quit Setup, press F3.
//  
//  
//  
//  
//  
//  
//  
//  
//
#define SP_SCRN_COPY_FAILED              0x00002377L

//
// MessageId: SP_SCRN_IMAGE_VERIFY_FAILED
//
// MessageText:
//
//  The file %1 was not copied correctly.
//  
//  The file Setup placed on your hard drive is not a valid Windows
//  system image. If you are installing from a CD, there may be a problem
//  with the Windows CD.
//  
//     To retry, press ENTER.
//  
//      If you continue to receive this message, contact your
//      Windows supplier or system administrator.
//  
//     To skip this file, press ESC.
//  
//      CAUTION: If you skip this file, Setup may not complete
//      and Windows may not work properly.
//  
//     To quit Setup, press F3.
//  
//  
//  
//  
//  
//
#define SP_SCRN_IMAGE_VERIFY_FAILED      0x00002378L

//
// MessageId: SP_SCRN_SETUP_IS_COPYING
//
// MessageText:
//
//  Please wait while Setup copies files
//  to the Windows installation folders.
//  This might take several minutes to complete.
//  
//
#define SP_SCRN_SETUP_IS_COPYING         0x00002379L

//
// MessageId: SP_SCRN_REGISTRY_CONFIG_FAILED
//
// MessageText:
//
//  Setup cannot set the required Windows configuration information.
//  This indicates an internal Setup error.
//  
//  Contact your system administrator.
//  
//  
//
#define SP_SCRN_REGISTRY_CONFIG_FAILED   0x0000237AL

//
// MessageId: SP_SCRN_DOING_REG_CONFIG
//
// MessageText:
//
//  Please wait while Setup initializes your Windows configuration.
//  
//
#define SP_SCRN_DOING_REG_CONFIG         0x0000237BL

//
// MessageId: SP_SCRN_CANT_INIT_FLEXBOOT
//
// MessageText:
//
//  Setup cannot configure your computer to start Windows.
//  
//  There may be a problem with the hard disk containing drive %1,
//  or %2: may be corrupted.
//  
//  Setup cannot continue. To quit Setup, press F3.
//  
//  
//  
//  
//
#define SP_SCRN_CANT_INIT_FLEXBOOT       0x0000237CL

//
// MessageId: SP_SCRN_CANT_UPDATE_BOOTVARS
//
// MessageText:
//
//  Setup cannot add a new entry to your computer's list of
//  available operating systems because your computer's configuration
//  memory may be full.
//  
//  Setup will continue, but you should run the system configuration
//  program supplied by your computer manufacturer to update the
//  startup configuration. You'll need the following information:
//  
//  
//  LOADIDENTIFIER = %1
//  OSLOADER = %2
//  OSLOADPARTITION = %3
//  OSLOADFILENAME = %4
//  OSLOADOPTIONS = %5
//  SYSTEMPARTITION = %6
//  
//  
//  
//  
//  
//  
//  
//
#define SP_SCRN_CANT_UPDATE_BOOTVARS     0x0000237DL

//
// MessageId: SP_SCRN_CANT_FIND_UPGRADE
//
// MessageText:
//
//  Setup cannot locate the Windows installation you want to upgrade.
//  
//  Contact your system administrator.
//  
//  
//
#define SP_SCRN_CANT_FIND_UPGRADE        0x0000237EL

//
// MessageId: SP_SCRN_FOUND_UNDELETE
//
// MessageText:
//
//  An Undelete program is in use on your computer. This program
//  uses a portion of your hard disk to keep track of deleted files.
//  
//  Disk space used to keep track of deleted files is not recognized as
//  free disk space by Windows. For this reason, the amount of free
//  disk space reported by Setup and Windows may differ from the
//  amount reported by MS-DOS.
//  
//  
//  
//  
//
#define SP_SCRN_FOUND_UNDELETE           0x0000237FL

//
// MessageId: SP_SCRN_COULDNT_INIT_ARCNAMES
//
// MessageText:
//
//  Setup cannot initialize the device name database, possibly because
//  of an internal Setup error or a system problem.
//  
//  Setup cannot continue. To quit Setup, press F3.
//  
//  
//
#define SP_SCRN_COULDNT_INIT_ARCNAMES    0x00002380L

//
// MessageId: SP_SCRN_CONFIRM_REMOVE_SYSPART
//
// MessageText:
//
//  The partition you tried to delete is a system partition.
//  
//  System partitions may contain diagnostic or hardware configuration
//  programs, programs to start operating systems (such as Windows),
//  or other manufacturer-supplied programs.
//  
//  Delete a system partition only if you are sure that it contains
//  no such programs or if you are willing to lose them. Deleting a
//  system partition may prevent your computer from starting from
//  the hard disk until you complete installation of Windows.
//  
//     To delete this partition, press ENTER.
//      Setup will prompt you for confirmation before
//      deleting the partition.
//  
//     To go back to the previous screen without
//      deleting the partition, press ESC.
//  
//  
//  
//  
//  
//  
//  
//  
//
#define SP_SCRN_CONFIRM_REMOVE_SYSPART   0x00002381L

//
// MessageId: SP_SCRN_INSTALL_ON_SYSPART
//
// MessageText:
//
//  You chose to install Windows on the system partition.
//  
//  A system partition is a special area of the hard disk that your
//  computer uses to store operating system startup files and diagnostic,
//  configuration, or other manufacturer-supplied programs.
//  
//  Your computer requires that system partitions be formatted with the
//  FAT file system. You cannot convert or format the system partition
//  NTFS. As a result, you won't be able to use the full security
//  features of Windows.
//  
//       To select a different partition for Windows, press ESC.
//  
//       To install Windows on the system partition, press ENTER.
//  
//  
//  
//  
//  
//  
//  
//  
//
#define SP_SCRN_INSTALL_ON_SYSPART       0x00002382L

//
// MessageId: SP_SCRN_NO_SYSPARTS
//
// MessageText:
//
//  Either no valid system partitions are defined on this computer, or
//  all system partitions are full. Windows requires %1!u!
//  kilobytes (KB) of free disk space on a valid system partition.
//  
//  A system partition is an area of a hard disk that your computer
//  uses to store operating system startup files and diagnostic,
//  configuration, or other manufacturer-supplied programs.
//  
//  System partitions are created and managed by a manufacturer
//  supplied configuration program.
//  
//  How you start this program depends on your computer type.
//  Usually, you select the "Run a program" option from your
//  computer's startup menu.
//  
//  Setup cannot continue. To quit Setup, press F3.
//  
//  
//  
//  
//  
//  
//  
//  
//
#define SP_SCRN_NO_SYSPARTS              0x00002383L

//
// MessageId: SP_SCRN_SIF_PROCESS_ERROR
//
// MessageText:
//
//  There is a syntax error in the .SIF file that Setup uses
//  at line: %1!u!.
//  
//  
//  Setup cannot continue. Shut down or restart your computer.
//  
//  
//  
//
#define SP_SCRN_SIF_PROCESS_ERROR        0x00002384L

//
// MessageId: SP_SCRN_ALSO_REMOVE_CD
//
// MessageText:
//
//  Remove any CDs from your CD-ROM drive.
//  
//
#define SP_SCRN_ALSO_REMOVE_CD           0x00002385L

//
// MessageId: SP_SCRN_CANT_FIND_LOCAL_SOURCE
//
// MessageText:
//
//  Setup cannot find the temporary installation files.
//  
//  The hard drive on which Setup placed temporary files is not
//  currently available to Windows. You may need a
//  manufacturer-supplied device driver, or you may need to run Setup
//  again and select a drive that is compatible with Windows
//  for the temporary installation files. See your Windows
//  documentation for more information.
//  
//  On x86-based computers, floppy disks generated by Setup for use
//  with non-CD installations are not suitable for installing from CD.
//  
//  Setup cannot continue. To quit, press F3.
//  
//  
//  
//  
//  
//  
//  
//  
//
#define SP_SCRN_CANT_FIND_LOCAL_SOURCE   0x00002386L

//
// MessageId: SP_SCRN_WIN31_REMOVE
//
// MessageText:
//
//  CAUTION: If you continue this upgrade, your current
//  Windows installation will be deleted.
//  
//        To continue this upgrade, press U.
//  
//        To quit Setup, press F3.
//  
//  
//  
//  
//  
//
#define SP_SCRN_WIN31_REMOVE             0x00002387L

//
// MessageId: SP_SCRN_INSUFFICIENT_MEMORY
//
// MessageText:
//
//  This computer does not have enough memory to run Windows.
//  
//  This version requires %1!u!.%2!02u! megabytes (MB)
//  of memory (RAM).
//  
//  Setup cannot continue. To quit Setup, press F3.
//  
//  
//  
//  
//
#define SP_SCRN_INSUFFICIENT_MEMORY      0x0000238AL

//
// MessageId: SP_SCRN_DISK_NOT_INSTALLABLE
//
// MessageText:
//
//  Your computer's startup program cannot gain access to the disk
//  containing the partition or free space you chose. Setup cannot
//  install Windows on this hard disk.
//  
//  This lack of access does not necessarily indicate an error condition.
//  For example, disks attached to a SCSI adapter that wasn't installed
//  by your computer manufacturer or to a secondary hard disk controller,
//  are typically not visible to the startup program unless special
//  software is used. Contact your computer or hard disk controller
//  manufacturer for more information.
//  
//  On x86-based computers, this message may indicate a problem with the
//  CMOS drive type settings. See your disk controller documentation
//  for more information.
//  
//  Press ENTER to continue.
//  
//  
//  
//  
//  
//  
//
#define SP_SCRN_DISK_NOT_INSTALLABLE     0x0000238BL

//
// MessageId: SP_SCRN_CANT_INSTALL_ON_PCMCIA
//
// MessageText:
//
//  Windows cannot be installed on a disk connected to a PC card.
//  Select a different disk.
//  
//  Press ENTER to continue.
//  
//  
//  
//
#define SP_SCRN_CANT_INSTALL_ON_PCMCIA   0x0000238CL

//
// MessageId: SP_SCRN_REPAIR_INF_ERROR
//
// MessageText:
//
//  The Emergency Repair information on the disk you provided
//  or the Windows installation you specified is not valid:
//  
//  %1
//  
//  Setup cannot use the information to repair the selected
//  Windows installation.
//  
//      To provide a different Emergency Repair disk or to specify
//       a different Windows installation, press ENTER.
//  
//      To quit Setup, press F3.
//  
//  
//  
//  
//  
//  
//
#define SP_SCRN_REPAIR_INF_ERROR         0x0000238DL

//
// MessageId: SP_SCRN_REPAIR_INF_ERROR_0
//
// MessageText:
//
//  The Emergency Repair information on the disk you provided
//  or the Windows installation you specified is not valid:
//  
//  %1
//  
//  Setup cannot repair the file.
//  
//     To skip this file, press ENTER. The file will not be repaired.
//  
//     To quit Setup, press F3.
//  
//  
//  
//  
//  
//
#define SP_SCRN_REPAIR_INF_ERROR_0       0x0000238EL

//
// MessageId: SP_SCRN_REPAIR_FILE_MISMATCH
//
// MessageText:
//
//     %1
//  
//  
//     To skip this file, press ESC. The file will not be repaired.
//  
//     To repair this file, press ENTER.
//  
//     To repair this file and all other files not originally
//      installed with Windows, press A.
//  
//     To quit Setup, press F3.
//  
//  
//  
//  
//
#define SP_SCRN_REPAIR_FILE_MISMATCH     0x0000238FL

//
// MessageId: SP_SCRN_SETUP_IS_EXAMINING
//
// MessageText:
//
//  Please wait while Setup examines files on your hard disk.
//  
//
#define SP_SCRN_SETUP_IS_EXAMINING       0x00002390L

//
// MessageId: SP_SCRN_REPAIR_SUCCESS
//
// MessageText:
//
//  Setup has completed repairs.
//  
//
#define SP_SCRN_REPAIR_SUCCESS           0x00002391L

//
// MessageId: SP_SCRN_REPAIR_FAILURE
//
// MessageText:
//
//  Windows has not been repaired.
//  
//
#define SP_SCRN_REPAIR_FAILURE           0x00002392L

//
// MessageId: SP_SCRN_ENTER_TO_RESTART
//
// MessageText:
//
//  To restart your computer, press ENTER.
//  
//
#define SP_SCRN_ENTER_TO_RESTART         0x00002393L

//
// MessageId: SP_SCRN_RESTART_EXPLAIN
//
// MessageText:
//
//  When your computer restarts, Setup will continue.
//  
//
#define SP_SCRN_RESTART_EXPLAIN          0x00002394L

//
// MessageId: SP_SCRN_REPAIR_ASK_REPAIR_DISK
//
// MessageText:
//
//  You need an Emergency Repair disk for the Windows
//  installation you want to repair.
//  
//  
//      If you have the Emergency Repair disk, press ENTER.
//  
//      If you do not have the Emergency Repair disk, press L.
//       Setup will attempt to locate Windows for you.
//  
//  
//  
//  
//  
//
#define SP_SCRN_REPAIR_ASK_REPAIR_DISK   0x00002396L

//
// MessageId: SP_SCRN_NO_VALID_SOURCE
//
// MessageText:
//
//  Setup cannot find a CD-ROM drive.
//  
//  Make sure your CD-ROM drive is on and properly connected
//  to your computer. If it is a SCSI CD-ROM drive, make sure your
//  SCSI devices are properly terminated. See your computer or
//  SCSI adapter documentation for more information.
//  
//  Setup cannot continue. To quit Setup, press F3.
//  
//  
//  
//  
//  
//
#define SP_SCRN_NO_VALID_SOURCE          0x00002397L

//
// MessageId: SP_SCRN_REPAIR_NT_NOT_FOUND
//
// MessageText:
//
//  Setup cannot find a Windows installation to repair. Unless you
//  provide the Emergency Repair disk for the installation you want to
//  repair, Setup cannot make the repairs.
//  
//  
//      If you have the Emergency Repair Disk, or if you want Setup to
//       search for existing Windows installations again, press ENTER.
//  
//      If you want to quit Setup, press F3.
//  
//  
//  
//  
//  
//
#define SP_SCRN_REPAIR_NT_NOT_FOUND      0x00002398L

//
// MessageId: SP_SCRN_DISK_NOT_INSTALLABLE_LUN_NOT_SUPPORTED
//
// MessageText:
//
//  The hard disk containing the partition or free space you chose has a
//  Logical Unit Number (LUN) greater than 0. Therefore, your computer's
//  startup program cannot gain access to the disk. Setup cannot install
//  Windows on this disk.
//  
//  Contact your computer or hard disk controller manufacturer for more
//  information.
//  
//  Press ENTER to continue.
//  
//  
//  
//  
//  
//  
//  
//
#define SP_SCRN_DISK_NOT_INSTALLABLE_LUN_NOT_SUPPORTED 0x00002399L

//
// MessageId: SP_SCRN_FATAL_SETUP_ERROR
//
// MessageText:
//
//  Setup has encountered an error and cannot continue.
//  
//  Contact technical support for assistance.  The following
//  status codes will assist them in diagnosing the problem:
//  
//  (%1!#lx!, %2!#lx!, %3!#lx!, %4!#lx!)
//  
//  
//  
//
#define SP_SCRN_FATAL_SETUP_ERROR        0x0000239AL

//
// MessageId: SP_SCRN_OUT_OF_MEMORY_RAW
//
// MessageText:
//
//  Setup is out of memory and cannot continue.
//  
//  Shut down or restart your computer.
//  
//  
//
#define SP_SCRN_OUT_OF_MEMORY_RAW        0x0000239BL

//
// MessageId: SP_SCRN_VIDEO_ERROR_RAW
//
// MessageText:
//
//  Setup encountered an error while initializing your computer's video.
//  
//  Contact technical support for assistance.  The following
//  status codes will assist them in diagnosing the problem:
//  
//  (%1!#lx!, %2!#lx!)
//  
//  Setup cannot continue. Shut down or restart your computer.
//  
//  
//  
//  
//
#define SP_SCRN_VIDEO_ERROR_RAW          0x0000239CL

//
// MessageId: SP_SCRN_POWER_DOWN
//
// MessageText:
//
//  Setup cannot continue. Shut down or restart your computer.
//  
//
#define SP_SCRN_POWER_DOWN               0x0000239DL

//
// MessageId: SP_SCRN_F3_TO_REBOOT
//
// MessageText:
//
//  Setup cannot continue. To quit Setup, press F3.
//  
//
#define SP_SCRN_F3_TO_REBOOT             0x0000239EL

//
// MessageId: SP_SCRN_NONFATAL_SIF_ERROR_LINE
//
// MessageText:
//
//  The following value in the .SIF file that Setup uses is
//  corrupted or missing:
//  
//  Value %1!u! on line %2!u! in section [%3]
//  
//  Setup was unable to copy the file %4.
//  
//     To skip this file, press ESC.
//  
//      CAUTION: If you skip this file, Setup may not complete
//      and Windows may not work properly.
//  
//     To quit Setup, press F3.
//  
//  
//  
//  
//  
//  
//  
//
#define SP_SCRN_NONFATAL_SIF_ERROR_LINE  0x0000239FL

//
// MessageId: SP_SCRN_NONFATAL_SIF_ERROR_KEY
//
// MessageText:
//
//  The following value in the .SIF file that Setup uses is
//  corrupted or missing:
//  
//  Value %1!u! on the line in section [%2]
//  with key "%3."
//  
//  Setup was unable to copy the file %4.
//  
//     To skip this file, press ESC.
//  
//      CAUTION: If you skip this file, Setup may not complete
//      and Windows may not work properly.
//  
//     To quit Setup, press F3.
//  
//  
//  
//  
//  
//  
//  
//  
//
#define SP_SCRN_NONFATAL_SIF_ERROR_KEY   0x000023A0L

//
// MessageId: SP_SCRN_INSUFFICIENT_FREESPACE_NO_FMT
//
// MessageText:
//
//  The partition you have chosen is too full to contain the selected version
//  of Windows, which requires a drive with at least %1!u! megabytes (MB) of
//  free disk space.
//  
//  Go back to the previous screen and select a different partition
//  on which to install.
//  
//  
//        To go back to the previous screen, press ENTER.
//  
//  
//  
//  
//
#define SP_SCRN_INSUFFICIENT_FREESPACE_NO_FMT 0x000023A2L

//
// MessageId: SP_SCRN_C_FULL_NO_FMT
//
// MessageText:
//
//  Drive %2 does not have enough space for the Windows startup files.
//  
//  You must have at least %1!u! kilobytes (KB) of free disk space
//  on this drive to install the selected version of Windows.
//  
//  Quit Setup and free some space on this drive.
//  
//  
//       To quit Setup, press F3.
//  
//  
//  
//  
//
#define SP_SCRN_C_FULL_NO_FMT            0x000023A3L

//
// MessageId: SP_SCRN_SYSPART_FORMAT_ERROR
//
// MessageText:
//
//  Setup was unable to format drive %1. The hard disk may be damaged.
//  Make sure the disk is on and properly connected
//  to your computer. If the disk is a SCSI disk, make sure your SCSI
//  devices are properly terminated. See your computer or SCSI
//  adapter documentation for more information.
//  
//  Setup cannot continue. To quit Setup, press F3.
//  
//  
//  
//  
//
#define SP_SCRN_SYSPART_FORMAT_ERROR     0x000023A4L

//
// MessageId: SP_SCRN_OSPART_LARGE
//
// MessageText:
//
//  Because this partition is larger than 2048 megabytes (MB), Setup
//  will format it with the FAT32 file system.
//  
//  Files stored on this partition will not be available when you are
//  using other operating systems, such as MS-DOS or some versions of
//  Windows.
//  
//    To continue and format the partition, press ENTER.
//  
//    To go back to the previous screen without having Setup
//     formatting this partition, press ESC.
//  
//    To quit Setup, press F3.
//  
//  
//  
//  
//  
//  
//
#define SP_SCRN_OSPART_LARGE             0x000023A5L

//
// MessageId: SP_SCRN_C_LARGE
//
// MessageText:
//
//  Because drive %1 is larger than 2048 megabytes (MB), Setup will
//  format the drive with the FAT32 file system.
//  
//  Files stored on the drive will not be available when using other
//  operating systems, such as MS-DOS or some versions of Microsoft Windows.
//  
//    To continue and format the drive, press ENTER.
//  
//    To go back to the previous screen without having Setup
//     formatting this partition, press ESC.
//  
//    To quit Setup, press F3.
//  
//  
//  
//  
//  
//  
//
#define SP_SCRN_C_LARGE                  0x000023A6L

//
// MessageId: SP_SCRN_WIN95_MIGRATION
//
// MessageText:
//
//  <unused>
//
#define SP_SCRN_WIN95_MIGRATION          0x000023AAL

//
// MessageId: SP_SCRN_OEM_PREINSTALL_INF_ERROR
//
// MessageText:
//
//  The manufacturer provided file that Setup is trying
//  to use is corrupted or invalid:
//  
//  %1
//  
//  Setup cannot continue. To quit Setup, press F3.
//  
//  
//  
//
#define SP_SCRN_OEM_PREINSTALL_INF_ERROR 0x000023ACL

//
// MessageId: SP_SCRN_OEM_PREINSTALL_VALUE_NOT_FOUND
//
// MessageText:
//
//  The following value specified in the Setup answer file is
//  not defined in the .SIF file, section [%2]:
//  
//    %1
//  
//  
//  Setup cannot continue. To quit Setup, press F3.
//  
//  
//  
//
#define SP_SCRN_OEM_PREINSTALL_VALUE_NOT_FOUND 0x000023ADL

//
// MessageId: SP_SCRN_REMOVABLE_ALREADY_PARTITIONED
//
// MessageText:
//
//  The disk you selected is a removable drive that is already
//  partitioned. Windows does not support creation of multiple
//  partitions on a removable drive.
//  
//  You can select another disk, or you can delete the partitions that
//  already exist and then create a new partition.
//  
//  To go back to the partition selection screen, press ENTER.
//  
//  
//
#define SP_SCRN_REMOVABLE_ALREADY_PARTITIONED 0x000023AEL

//
// MessageId: SP_SCRN_MARK_SYSPART
//
// MessageText:
//
//  Either no valid system partitions are defined on this computer, or
//  all system partitions are full. Windows requires %1!u! kilobytes
//  (KB) of free disk space on a valid system partition.
//  
//  A system partition is an area of a hard disk that your computer uses
//  to store operating system startup files and diagnostic,
//  configuration, or other manufacturer-supplied programs.
//  
//  System partitions are generally created and managed by a
//  manufacturer-supplied configuration program.
//  
//  Setup needs a system partition to continue.
//  
//  Partitioning menu allows a partition to be marked as system partition.
//  To go back to the previous partitioning menu, press ESC.
//  
//  To quit Setup, press F3.
//
#define SP_SCRN_MARK_SYSPART             0x000023AFL

//
// MessageId: SP_SCRN_WINNT_DRIVE_FULL
//
// MessageText:
//
//  There is not enough disk space to repair the Windows installation
//  you selected.
//  
//      Drive       Space Required(KB)     Free Space Available(KB)
//      --------    ------------------     ------------------------
//      %4          %5                     %6
//      %7          %8                     %9
//  
//  
//        If you want to upgrade, press F3 to quit Setup.
//         Delete any unneeded files to create the required free
//         space and then start Setup again.
//  
//        To go back to the previous screen, press ENTER.
//  
//  
//  
//  
//
#define SP_SCRN_WINNT_DRIVE_FULL         0x000023BEL

//
// MessageId: SP_SCRN_WINNT_DRIVE_FULL_FATAL
//
// MessageText:
//
//  There is not enough disk space to upgrade the following Windows
//  installation:
//  
//      %1:%2 %3
//  
//      Drive       Space Required(KB)     Free Space Available(KB)
//      --------    ------------------     ------------------------
//      %4          %5                     %6
//      %7          %8                     %9
//  
//  
//  Setup cannot continue.
//  
//        Press F3 to quit Setup. Delete any unneeded files to create
//         the required free space and then start Setup again.
//  
//  
//  
//  
//  
//
#define SP_SCRN_WINNT_DRIVE_FULL_FATAL   0x000023BFL

//
// MessageId: SP_SCRN_WINNT_FAILED_UPGRADE
//
// MessageText:
//
//  Setup has already attempted to upgrade the following Windows
//  installation.
//  
//      %1:%2 %3
//  
//  Setup will try to complete the upgrade again.
//  
//        To retry upgrading, press ENTER.
//  
//        To quit Setup, press F3.
//  
//  
//  
//  
//  
//  
//
#define SP_SCRN_WINNT_FAILED_UPGRADE     0x000023C0L

//
// MessageId: SP_SCRN_WINNT_FAILED_UPGRADE_ESC
//
// MessageText:
//
//  Setup has already attempted to upgrade the following Windows
//  installation.
//  
//      %1:%2 %3
//  
//  Setup will try to complete the upgrade again.
//  
//        To retry upgrading, press ENTER.
//  
//        To continue installing a fresh copy of Windows
//         without repairing, press ESC.
//  
//        To quit Setup, press F3.
//  
//  
//  
//  
//
#define SP_SCRN_WINNT_FAILED_UPGRADE_ESC 0x000023C1L

//
// MessageId: SP_SCRN_WINNT_REPAIR_BY_UPGRADE
//
// MessageText:
//
//  If one of the following Windows installations is damaged,
//  Setup can try to repair it.
//  
//  Use the UP and DOWN ARROW keys to select an installation.
//  
//        To repair the selected Windows installation,
//         press R.
//  
//        To continue installing a fresh copy of Windows
//         without repairing, press ESC.
//  
//  
//  
//  
//  
//
#define SP_SCRN_WINNT_REPAIR_BY_UPGRADE  0x000023C3L

//
// MessageId: SP_SCRN_DELETE_FAILED
//
// MessageText:
//
//  Setup cannot delete the file: %1.
//  
//  This error will not prevent Setup from completing successfully.
//  
//  
//     To skip deleting this file, press ESC (recommended).
//  
//     To retry deleting this file, press ENTER.
//  
//     To quit Setup, press F3.
//  
//  
//  
//  
//  
//
#define SP_SCRN_DELETE_FAILED            0x000023C4L

//
// MessageId: SP_SCRN_BACKUP_FAILED
//
// MessageText:
//
//  Setup cannot back up the file %1 to %2.
//  
//  This error will not prevent Setup from completing successfully.
//  
//  
//     To skip backing up this file, press ESC (recommended).
//  
//     To retry backing up this file, press ENTER.
//  
//     To quit Setup, press F3.
//  
//  
//  
//  
//  
//
#define SP_SCRN_BACKUP_FAILED            0x000023C5L

//
// MessageId: SP_SCRN_WINNT_REPAIR
//
// MessageText:
//
//  Setup has found Windows in the following folder:
//  
//  
//      %1 %2
//  
//  
//  
//        To repair this Windows installation, press ENTER.
//  
//        To go back to the previous screen, press ESC.
//  
//        To quit Setup, press F3.
//  
//  
//  
//  
//
#define SP_SCRN_WINNT_REPAIR             0x000023C9L

//
// MessageId: SP_SCRN_WINNT_REPAIR_LIST
//
// MessageText:
//
//  The following list shows the Windows installations on your
//  computer that may be repaired.
//  
//  Use the UP and DOWN ARROW keys to select an item in the list.
//  
//        To repair the selected Windows installation, press ENTER.
//  
//        To go back to the previous screen, press ESC.
//  
//        To quit Setup, press F3.
//  
//  
//  
//  
//
#define SP_SCRN_WINNT_REPAIR_LIST        0x000023CAL

//
// MessageId: SP_SCRN_REPAIR_MENU
//
// MessageText:
//
//  As part of the repair process, Setup will perform each optional task
//  selected below.
//  
//  To have Setup perform the selected tasks, press ENTER.
//  To change the selections, use the UP or DOWN ARROW keys to
//  select an item, and then press ENTER.
//  
//  
//  
//  
//
#define SP_SCRN_REPAIR_MENU              0x000023CBL

//
// MessageId: SP_SCRN_REPAIR_CHECK_HIVES
//
// MessageText:
//
//  Please wait while Setup inspects your Windows configuration.
//  
//
#define SP_SCRN_REPAIR_CHECK_HIVES       0x000023CCL

//
// MessageId: SP_SCRN_REPAIR_HIVE_MENU
//
// MessageText:
//
//  Setup will restore each registry file selected below.
//  
//  To have Setup restore the selected files, press ENTER.
//  To change a selection, use the UP or DOWN ARROW key to
//  select the item, and then press ENTER.
//  
//  CAUTION: Restoring a registry file may delete the existing
//  configuration.
//  
//  
//  
//  
//
#define SP_SCRN_REPAIR_HIVE_MENU         0x000023CDL

//
// MessageId: SP_SCRN_REPAIR_HIVE_FAIL
//
// MessageText:
//
//  Setup cannot restore the registry.  The Emergency Repair disk
//  or the hard disk containing Windows may be damaged.
//  
//       Press ENTER to continue the repair process.
//  
//       To quit, press F3.
//  
//  
//
#define SP_SCRN_REPAIR_HIVE_FAIL         0x000023CEL

//
// MessageId: SP_SCRN_KBD_OPEN_FAILED
//
// MessageText:
//
//  Setup did not find a keyboard connected to your computer.
//  Setup cannot continue.
//  
//  Shut down your computer and check to make sure that the keyboard
//  cable is properly connected. If the problem persists, your keyboard
//  or computer may need repair.
//  
//  
//  
//  
//  
//
#define SP_SCRN_KBD_OPEN_FAILED          0x000023D1L

//
// MessageId: SP_SCRN_KBD_LAYOUT_FAILED
//
// MessageText:
//
//  Setup cannot load the keyboard layout file %1.
//  
//  Setup cannot continue. Shut down or restart your computer.
//  
//  
//
#define SP_SCRN_KBD_LAYOUT_FAILED        0x000023D2L

//
// MessageId: SP_SCRN_RUNNING_AUTOCHK
//
// MessageText:
//
//  Please wait while Setup examines your disks. This may take
//  several minutes depending on the size of the disks.
//  
//
#define SP_SCRN_RUNNING_AUTOCHK          0x000023D3L

//
// MessageId: SP_SCRN_FATAL_ERROR_AUTOCHK_FAILED
//
// MessageText:
//
//  Setup has determined that drive %1 is corrupted and cannot
//  be repaired.
//  
//  Setup cannot continue. To quit Setup, press F3.
//  
//
#define SP_SCRN_FATAL_ERROR_AUTOCHK_FAILED 0x000023D4L

//
// MessageId: SP_SCRN_CANT_RUN_AUTOCHK
//
// MessageText:
//
//  Setup was unable to verify drive %1.
//  
//  Your computer may not have enough memory to examine the drives,
//  or your Windows CD may contain some corrupted files.
//  
//  To continue, press ENTER.
//  
//  
//  
//  
//
#define SP_SCRN_CANT_RUN_AUTOCHK         0x000023D6L

//
// MessageId: SP_SCRN_AUTOCHK_OPTION
//
// MessageText:
//
//  Setup will now examine your computer's drives.
//  
//  Setup needs the original installation files. If you do not have
//  them, you may skip the drive examination.
//  
//  
//        To have Setup examine the drives, press ENTER.
//  
//        To skip the drive examination, press ESC.
//  
//  
//  
//  
//
#define SP_SCRN_AUTOCHK_OPTION           0x000023D7L

//
// MessageId: SP_SCRN_AUTOCHK_REQUIRES_REBOOT
//
// MessageText:
//
//  Setup has performed maintenance on your hard disk. You must
//  restart your computer to continue with Setup.
//  
//
#define SP_SCRN_AUTOCHK_REQUIRES_REBOOT  0x000023D8L

//
// MessageId: SP_SCRN_STEP_UP_NO_QUALIFY
//
// MessageText:
//
//  Setup cannot find a previous version of Windows installed on
//  your computer. To continue, Setup needs to verify that you
//  qualify to use this upgrade product.
//  
//
#define SP_SCRN_STEP_UP_NO_QUALIFY       0x000023D9L

//
// MessageId: SP_SCRN_STEP_UP_PROMPT_WKS
//
// MessageText:
//
//  Please insert your Windows NT 3.51 Workstation, Windows NT 4.0
//  Workstation, Windows 2000 Professional, Windows 95, Windows 98, or
//  Windows Me CD into your CD-ROM drive.
//  
//  
//
#define SP_SCRN_STEP_UP_PROMPT_WKS       0x000023DAL

//
// MessageId: SP_SCRN_STEP_UP_PROMPT_SRV
//
// MessageText:
//
//  Please insert your Windows NT 3.51, Windows NT 4.0 or
//  Windows 2000 Server CD into your CD-ROM drive.
//  
//  
//
#define SP_SCRN_STEP_UP_PROMPT_SRV       0x000023DBL

//
// MessageId: SP_SCRN_STEP_UP_INSTRUCTIONS
//
// MessageText:
//
//        When the CD is in the drive, press ENTER.
//  
//        To quit Setup, press F3.
//  
//  
//
#define SP_SCRN_STEP_UP_INSTRUCTIONS     0x000023DCL

//
// MessageId: SP_SCRN_STEP_UP_BAD_CD
//
// MessageText:
//
//  Setup could not read the CD you inserted, or the CD
//  is not a valid Windows CD.
//  
//
#define SP_SCRN_STEP_UP_BAD_CD           0x000023DDL

//
// MessageId: SP_SCRN_STEP_UP_FATAL
//
// MessageText:
//
//  No previous version of Windows NT can be found on your computer.
//  Setup cannot verify that you qualify to install this upgrade
//  product.
//  
//  To quit Setup, press F3.
//  
//  
//
#define SP_SCRN_STEP_UP_FATAL            0x000023DEL

//
// MessageId: SP_SCRN_STEP_UP_PROMPT_ENT
//
// MessageText:
//
//  Please insert your Windows NT 4.0 Server, Window NT 4.0 Enterprise Edition,
//  Windows 2000 Server, or Windows 2000 Advanced Server CD
//  into your CD-ROM drive.
//  
//
#define SP_SCRN_STEP_UP_PROMPT_ENT       0x000023DFL

//
// MessageId: SP_SCRN_FATAL_ERROR_AUTOFMT_FAILED
//
// MessageText:
//
//  Setup cannot format your drive %1.
//  
//  Setup cannot continue. To quit Setup, press F3.
//  
//
#define SP_SCRN_FATAL_ERROR_AUTOFMT_FAILED 0x000023E0L

//
// MessageId: SP_SCRN_CANT_RUN_AUTOFMT
//
// MessageText:
//
//  Setup cannot format the partition.
//  
//  Your computer may not have enough memory to perform this operation,
//  or your Windows CD-ROM may contain some corrupted files.
//  
//  Setup cannot continue. To quit Setup, press F3.
//  
//  
//  
//  
//
#define SP_SCRN_CANT_RUN_AUTOFMT         0x000023E1L

//
// MessageId: SP_SCRN_OVERWRITE_OEM_FILE
//
// MessageText:
//
//  Setup has determined that the following file did not come
//  from Microsoft:
//  
//      %1
//  
//  This file may have been provided by your hardware manufacturer.
//  
//  Setup can replace this file with the latest Microsoft version,
//  or it can continue the installation without replacing this file.
//  
//  
//        To allow Setup to replace the file, press ENTER.
//  
//        To keep the original file, press ESC.
//  
//  
//  
//  
//
#define SP_SCRN_OVERWRITE_OEM_FILE       0x000023E2L

//
// MessageId: SP_SCRN_PARTITION_DELETE_FAILED
//
// MessageText:
//
//  The partition you selected cannot be deleted.
//  
//  
//  
//  
//  
//  
//  
//  
//  
//  
//  
//  
//  
//  
//  
//  
//  
//  
//  
//  
//  
//  
//  
//  
//
#define SP_SCRN_PARTITION_DELETE_FAILED  0x000023E3L

//
// MessageId: SP_SCRN_PIDINIT_FATAL
//
// MessageText:
//
//  Setup cannot read licensing data.
//  
//  Setup cannot continue.
//  
//  To quit Setup, press F3.
//  
//  
//
#define SP_SCRN_PIDINIT_FATAL            0x000023E4L

//
// MessageId: SP_SCRN_DRIVERCACHE_FATAL
//
// MessageText:
//
//  Setup cannot access the CD containing the Windows installation
//  files.
//  
//  To retry, press ENTER. If you are not successful after several
//  tries, quit Setup. Then, to restart Setup, copy the Windows
//  installation files to your hard disk.
//  
//  To quit Setup, press F3.
//  
//  
//
#define SP_SCRN_DRIVERCACHE_FATAL        0x000023E5L

//
// MessageId: SP_SCRN_FATAL_ERROR_EULA_NOT_FOUND
//
// MessageText:
//
//  Setup cannot find the End User Licensing Agreement (EULA).
//  
//  
//  Setup cannot continue. To quit, press F3.
//  
//
#define SP_SCRN_FATAL_ERROR_EULA_NOT_FOUND 0x000023E7L

//
// MessageId: SP_SCRN_CLEARING_CSC
//
// MessageText:
//
//  Setup is deleting old cached files.
//  
//
#define SP_SCRN_CLEARING_CSC             0x000023E8L

//
// MessageId: SP_SCRN_FSWARN
//
// MessageText:
//
//  Setup has detected one or more older versions of Windows NT
//  on this computer.
//  
//  These versions will not start unless they are upgraded to
//  Windows NT 4.0 with Service Pack 5 or greater before you
//  install Windows.
//  
//  
//  To continue, press C. To quit Setup, press F3.
//  
//  
//  
//  
//  
//  
//  
//  
//  
//  
//  
//
#define SP_SCRN_FSWARN                   0x000023E9L

//
// MessageId: SP_SCRN_WAIT_REMOVING_TEMP_FILES
//
// MessageText:
//
//  Please wait while Setup deletes temporary files.
//  
//
#define SP_SCRN_WAIT_REMOVING_TEMP_FILES 0x000023EAL

//
// MessageId: SP_SCRN_CLEARING_OLD_WINNT
//
// MessageText:
//
//  Setup is deleting the existing Windows installation.
//  
//
#define SP_SCRN_CLEARING_OLD_WINNT       0x000023EBL

//
// MessageId: SP_SCRN_INIT_DISK_NEC98
//
// MessageText:
//
//  
//      %1
//  
//  The disk may be damaged or not properly initialized.
//  To continue installing Windows, Setup must initialize the disk.
//  
//        To initialize the disk, press I.
//         CAUTION: All data on the disk will be lost.
//  
//        To go back to the previous screen without
//         initializing the disk, press ESC.
//  
//  
//
#define SP_SCRN_INIT_DISK_NEC98          0x000023ECL

//
// MessageId: SP_SCRN_INIT_REQUIRES_REBOOT_NEC98
//
// MessageText:
//
//  Setup has completed disk initialization. To continue with Setup,
//  you must shut down your computer and restart Setup.  Make sure that
//  the Windows Setup Boot Disk is in drive A before you restart.
//  
//        To restart, press F3.
//  
//  
//  
//  
//
#define SP_SCRN_INIT_REQUIRES_REBOOT_NEC98 0x000023EDL

//
// MessageId: SP_SCRN_BAD_BIOS
//
// MessageText:
//
//  Setup has determined that the BIOS on your computer must be updated
//  before you can install Windows.
//  Contact your computer manufacturer for more information.
//  
//        To quit Setup, press F3.
//  
//  
//
#define SP_SCRN_BAD_BIOS                 0x000023EEL

//
// MessageId: SP_SCRN_CONFIRM_REMOVE_DYNVOL
//
// MessageText:
//
//  The partition you attempted to delete is on a dynamic disk.
//  Deletion of this partition will make all other partitions
//  on this disk unusable.
//  
//  Do not delete this partition if you need to keep any of
//  the data on any of the partitions on this disk.
//  
//  
//     To delete this partition, press ENTER.
//      Setup will prompt you for confirmation before
//      deleting the partition.
//  
//     To go back to the previous screen without
//      deleting the partition, press ESC.
//  
//  
//
#define SP_SCRN_CONFIRM_REMOVE_DYNVOL    0x000023EFL

//
// MessageId: SP_SCRN_CONFIRM_INABILITY
//
// MessageText:
//
//  Setup is unable to perform the requested operation on
//  the selected partition.  This partition contains temporary
//  Setup files that are required to complete the installation.
//  
//  
//       To continue, press ENTER.
//  
//
#define SP_SCRN_CONFIRM_INABILITY        0x000023F0L

//
// MessageId: SP_SCRN_CUSTOM_EXPRESS
//
// MessageText:
//
//  Windows Setup can automatically configure most aspects of your
//  installation, requiring little or no input from you.  If you are
//  configuring a computer with no local monitor or keyboard, you
//  must use this feature or setup will not complete.
//  
//  
//  If you would like to use this feature, please press ENTER now.
//  
//  
//  If you would like to proceed with a manual installation, please
//  press the C key now.
//
#define SP_SCRN_CUSTOM_EXPRESS           0x000023F1L

//
// MessageId: SP_SCRN_WELCOME_1
//
// MessageText:
//
//  %%IWelcome to Setup.
//  
//  This portion of the Setup program prepares Microsoft(R)
//  Windows(R) to run on your computer.
//  
//  
//       To set up Windows now, press ENTER.
//  
//       To repair a Windows installation using
//        Recovery Console, press R.
//  
//       To quit Setup without installing Windows, press F3.
//  
//  
//  
//  
//
#define SP_SCRN_WELCOME_1                0x000023F2L

//
// MessageId: SP_SCRN_CONFIRM_REMOVE_MSRPART
//
// MessageText:
//
//  The partition you tried to delete is a Microsoft reserved
//  partition.
//  
//  This partition is reserved for converting the disk to
//  dynamic disk. If you delete this partition you may not be
//  able to convert this disk to dynamic disk.
//  
//  
//     To delete this partition, press ENTER.
//      Setup will prompt you for confirmation before
//      deleting the partition.
//  
//     To go back to the previous screen without
//      deleting the partition, press ESC.
//  
//  
//
#define SP_SCRN_CONFIRM_REMOVE_MSRPART   0x000023F3L

//
// MessageId: SP_SCRN_C_UNKNOWN_1
//
// MessageText:
//
//  Drive %1 is unformatted, damaged, or formatted with a file system
//  that is incompatible with Windows. To continue installing
//  Windows, Setup needs to format this drive.
//  
//        To format the drive and continue Setup, press F.
//         CAUTION: All data currently on the drive will be lost.
//  
//        To quit setup, press F3.
//  
//  
//  
//  
//
#define SP_SCRN_C_UNKNOWN_1              0x000023F4L

//
// MessageId: SP_SCRN_FORMAT_NEW_PART3
//
// MessageText:
//
//  The system partition is not formatted. Setup will now format the
//  system partition.
//  
//  System partitions may contain diagnostic or hardware configuration
//  programs, programs to start operating systems (such as Windows),
//  or other manufacturer-supplied programs.
//  
//  Use the UP and DOWN ARROW keys to select the file system
//  you want, and then press ENTER.
//  
//  
//  
//
#define SP_SCRN_FORMAT_NEW_PART3         0x000023F5L

//
// MessageId: SP_SCRN_INVALID_INSTALLPART
//
// MessageText:
//
//  Setup cannot install to the selected partition.
//  
//  You can only install to GPT disks on IA-64 machines and
//  MBR disks on X-86 machines.
//  
//  You can only upgrade installations on GPT disk on IA-64
//  machines and MBR disks on X-86 machines.
//  
//     To go back to the previous screen press ENTER.
//  
//
#define SP_SCRN_INVALID_INSTALLPART      0x000023F6L

//
// MessageId: SP_SCRN_CANT_INIT_FLEXBOOT_EFI
//
// MessageText:
//
//  Setup cannot add a new entry to your computer's list of
//  available operating systems because your computer's configuration
//  memory may be full.
//  
//  Setup cannot continue. To quit Setup, press F3.
//  
//  
//  
//  
//
#define SP_SCRN_CANT_INIT_FLEXBOOT_EFI   0x000023F7L

//
// MessageId: SP_SCRN_CANT_RUN_AUTOCHK_UNINSTALL
//
// MessageText:
//
//  Setup was unable to verify drive %1.
//  
//  Possible reasons:
//  
//     You might need to quit Uninstall, insert the Windows CD, and
//      restart your computer
//  
//     Setup is having trouble reading your CD or hard disk
//  
//     Your computer might not have enough memory to examine the drives
//  
//  To continue without drive verification, press ENTER.
//  
//  To quit Uninstall, press F3.
//  
//
#define SP_SCRN_CANT_RUN_AUTOCHK_UNINSTALL 0x000023F8L

//
// Screens added to support Double Space
// (9500 =< id < 10000 )
//
//
// MessageId: SP_SCRN_CONFIRM_REMOVE_PARTITION_COMPRESSED
//
// MessageText:
//
//  You asked Setup to delete the partition:
//  
//     %1
//  
//  on %2.
//  
//  CAUTION: This partition contains %3!u! compressed drive(s).
//  
//  Deleting this partition will also delete its compressed drive(s).
//  
//       To delete this partition, press L.
//        CAUTION: ALL data on the partition will be lost.
//  
//       To go back to the previous screen without
//        deleting the partition, press ESC.
//  
//  
//  
//  
//  
//  
//  
//
#define SP_SCRN_CONFIRM_REMOVE_PARTITION_COMPRESSED 0x0000251CL

//
// MessageId: SP_SCRN_CONFIRM_FORMAT_COMPRESSED
//
// MessageText:
//
//  CAUTION: This partition contains %3!u! compressed drive(s).
//  Formatting this drive will erase all data currently stored on it,
//  including its compressed drive(s).
//  Confirm that you want to format
//  
//  %1
//  
//  on %2.
//  
//        To format the drive, press F.
//  
//        To select a different partition for Windows, press ESC.
//  
//  
//  
//  
//  
//  
//  
//
#define SP_SCRN_CONFIRM_FORMAT_COMPRESSED 0x0000251DL

//
// MessageId: SP_SCRN_CONFIRM_CONVERT_COMPRESSED
//
// MessageText:
//
//  CAUTION: This partition contains %3!u! compressed drive(s).
//  
//  Converting this partition to NTFS will make the partition and
//  its compressed drive(s) inaccessable to to some operating systems
//  including Windows 98 and Windows ME.
//  
//  If you need access to the drive when using other operating systems,
//  such as MS-DOS, Windows, or OS/2, do not convert the drive to NTFS.
//  
//  Confirm that you want to convert:
//  
//  %1
//  
//  on %2.
//  
//        To convert the partition to NTFS, press C.
//  
//        To select a different partition,
//         press ESC.
//  
//  
//  
//  
//  
//  
//  
//
#define SP_SCRN_CONFIRM_CONVERT_COMPRESSED 0x0000251EL

//
// MessageId: SP_SCRN_SYSPREP_PATCH_MISSING_OS
//
// MessageText:
//
//  CAUTION: The selected operating system image cannot be modified to
//  match your computer's hardware because a matching version of
//  Windows could not be found.
//  
//  The image may work if your hardware is similar to the hardware
//  in use when the image was created.
//  
//        To continue installing, press C.
//  
//        To quit Setup, press F3.
//
#define SP_SCRN_SYSPREP_PATCH_MISSING_OS 0x0000251FL

//
// MessageId: SP_SCRN_SYSPREP_PATCH_FAILURE
//
// MessageText:
//
//  CAUTION: The selected operating system image cannot be
//  modified to match your computer's hardware because of a
//  missing driver or lack of resources.
//  
//  The image may work if your hardware is similar to the hardware
//  in use when the image was created.
//  
//        To continue installing, press C.
//  
//        To quit Setup, press F3.
//
#define SP_SCRN_SYSPREP_PATCH_FAILURE    0x00002520L

//
// MessageId: SP_SCRN_SYSPREP_COPY_FAILURE
//
// MessageText:
//
//  Setup encountered error %1!#lx! while copying %2 from the
//  operating system image.
//  
//  The image may work if the file or directory is not critical.
//  
//        To continue installing, press C.
//  
//        To quit Setup, press F3.
//
#define SP_SCRN_SYSPREP_COPY_FAILURE     0x00002521L

//
// MessageId: SP_SCRN_SYSPREP_FATAL_FAILURE
//
// MessageText:
//
//  Setup cannot copy the operating system image you selected.
//  
//  %1
//  
//  Contact your system administrator.
//  
//  
//
#define SP_SCRN_SYSPREP_FATAL_FAILURE    0x00002522L

//
// MessageId: SP_SCRN_SYSPREP_SETACL_FAILED
//
// MessageText:
//
//  Setup cannot set permissions for %1.
//  
//     To skip this file, press ESC.
//  
//      CAUTION: If you choose to skip this file, Setup may not
//      complete or Windows may not function properly.
//  
//     To quit Setup, press F3.
//  
//  
//  
//  
//  
//  
//  
//  
//
#define SP_SCRN_SYSPREP_SETACL_FAILED    0x00002523L

//
// MessageId: SP_SCRN_OTHEROS_ON_PARTITION
//
// MessageText:
//
//  You chose to install Windows on a partition that contains another
//  operating system. Installing Windows on this partition might cause
//  the other operating system to function improperly.
//  
//  CAUTION: Installing multiple operating systems on a single partition
//           is not recommended. To learn more about installing multiple
//           operating systems on a single computer, see
//  
//           http://www.microsoft.com/windows/multiboot.asp
//  
//           using Internet Explorer.
//  
//  
//       To continue Setup using this partition, press C.
//  
//       To select a different partition, press ESC.
//  
//  
//  
//  
//
#define SP_SCRN_OTHEROS_ON_PARTITION     0x00002524L

//
// MessageId: SP_SELECT_KBDLAYOUT
//
// MessageText:
//
//  Please select the keyboard layout which you would like
//  to use
//
#define SP_SELECT_KBDLAYOUT              0x00002525L

//
// MessageId: SP_AUTOCREATE_ESP
//
// MessageText:
//
//  Setup could not locate an existing system partition.
//  
//  System partitions contains diagnostic or hardware configuration
//  programs, programs to start operating systems (such as Windows),
//  or other manufacturer-supplied programs.
//  
//  Setup will try to create a system partition for you automatically.
//  
//        To allow  Setup to create  a system partition, press ENTER.
//  
//        If you want to create a system partition on your own, press ESC.
//  
//
#define SP_AUTOCREATE_ESP                0x00002526L

//
// MessageId: SP_AUTOCREATE_ESP_FAILED
//
// MessageText:
//
//  Setup could not create a system partition automatically.
//  
//  System partitions contains diagnostic or hardware configuration
//  programs, programs to start operating systems (such as Windows),
//  or other manufacturer-supplied programs.
//  
//  You need to create a partition manually and mark it as a system
//  partition.
//  
//  If all the disks are MBR disks then convert one of disks where
//  you want the system partition to reside to GPT disk.
//  
//  To convert a disk to GPT delete all the partitions on the disk,
//  and select "S=Change Disk Style" option. When setup prompts for
//  auto creation of system partition, press ENTER.
//  
//        To continue, press ENTER.
//  
//
#define SP_AUTOCREATE_ESP_FAILED         0x00002527L

//
// MessageId: SP_ESP_INSTALL_PARTITION_SAME
//
// MessageText:
//
//  Setup cannot install to the partition selected. The partition you
//  select to install to should be different from the system partition or
//  Microsoft reserved partition.
//  
//  System partitions contains diagnostic or hardware configuration
//  programs, programs to start operating systems (such as Windows),
//  or other manufacturer-supplied programs.
//  
//  Microsoft reserved partition is needed for converting the disk to
//  dynamic disk.
//  
//  
//        To go back to partitioning menu, press ENTER.
//  
//
#define SP_ESP_INSTALL_PARTITION_SAME    0x00002528L


//
// Note a single space character at the starting of the
// message
//

//
// MessageId: SP_TEXT_FORMAT_QUICK
//
// MessageText:
//
//   (Quick)%0
//
#define SP_TEXT_FORMAT_QUICK             0x00002529L

//
// MessageId: SP_NON_GPT_SYSTEM_PARTITION
//
// MessageText:
//
//  
//  Currently no valid system partitions are defined on this computer.
//  
//  A system partition is an area of a hard disk that your computer uses
//  to store operating system startup files and diagnostic,
//  configuration, or other manufacturer-supplied programs.
//  
//  System partitions are generally created and managed by a manufacturer
//  supplied configuration program.
//  
//  To install Windows you need to have a valid system partition on a
//  GPT or EFI format disk
//  
//  For new system partition, create a partition on the starting free
//  space of a GPT or EFI format disk and then convert it into system
//  partition by selecting "M=Make System Partition" partition option in
//  the partitioning screen.
//  
//  To go back to the partitioning screen, press ENTER
//
#define SP_NON_GPT_SYSTEM_PARTITION      0x0000252AL

//
// MessageId: SP_NO_DYNAMIC_DISK_INSTALL
//
// MessageText:
//
//  
//  Windows XP Home Edition cannot be installed on a dynamic disk since
//  dynamic disks are not supported by Windows XP Home Edition.
//  
//  Select another partition on a hard disk which is not a dynamic disk.
//  
//  To install  Windows XP Home Edition on a dynamic disk delete
//  all the partitions on the disk, create a new partition and then
//  install to the new partition.
//  
//        To go back to partitioning screen, press ENTER.
//  
//
#define SP_NO_DYNAMIC_DISK_INSTALL       0x0000252BL

//
// MessageId: SP_ENABLE_ESP_DISK_IN_FIRMWARE
//
// MessageText:
//
//  Setup could not continue with the installation.
//  
//  One or more of your disk drives is not enabled in the firmware of the system.
//  To prevent against creating redundant EFI System Partitions (ESP) on your
//  system you must enable all disks in the firmware.
//  
//  
//        To go back to partitioning menu, press ESC.
//  
//        To reboot, press F3.
//
#define SP_ENABLE_ESP_DISK_IN_FIRMWARE   0x0000252CL

//
// MessageId: SP_MSR_NOT_PRESENT
//
// MessageText:
//
//  Setup could not continue with the installation.
//  
//  Currently there is no MSR (Microsoft Reserved Partition) on your
//  system drive.
//  
//  An MSR is required on every disk.
//  
//  Please delete one or more partitions or resize the ESP to free
//  space for the MSR after the ESP(EFI System Partition).
//  
//        To go back to the partitioning menu, press ENTER.
//
#define SP_MSR_NOT_PRESENT               0x0000252DL

//
// Text that represents options that are displayed in the status line
// go here (id >= 10000).
//
// MessageID=10000 SymbolicName=SP_STAT_F1_EQUALS_HELP
// Language=English
// F1=Help%0
// .
//
// MessageId: SP_STAT_F3_EQUALS_EXIT
//
// MessageText:
//
//  F3=Quit%0
//
#define SP_STAT_F3_EQUALS_EXIT           0x00002711L

//
// MessageId: SP_STAT_ENTER_EQUALS_CONTINUE
//
// MessageText:
//
//  ENTER=Continue%0
//
#define SP_STAT_ENTER_EQUALS_CONTINUE    0x00002712L

//
// MessageId: SP_STAT_ESC_EQUALS_AUX
//
// MessageText:
//
//  ESC=More Options%0
//
#define SP_STAT_ESC_EQUALS_AUX           0x00002713L

//
// MessageId: SP_STAT_ENTER_EQUALS_EXPRESS
//
// MessageText:
//
//  ENTER=Express Setup%0
//
#define SP_STAT_ENTER_EQUALS_EXPRESS     0x00002714L

//
// MessageId: SP_STAT_C_EQUALS_CUSTOM
//
// MessageText:
//
//  C=Custom Setup%0
//
#define SP_STAT_C_EQUALS_CUSTOM          0x00002715L

//
// MessageId: SP_STAT_C_EQUALS_CREATE_PARTITION
//
// MessageText:
//
//  C=Create Partition%0
//
#define SP_STAT_C_EQUALS_CREATE_PARTITION 0x00002716L

//
// MessageId: SP_STAT_D_EQUALS_DELETE_PARTITION
//
// MessageText:
//
//  D=Delete Partition%0
//
#define SP_STAT_D_EQUALS_DELETE_PARTITION 0x00002717L

//
// MessageId: SP_STAT_ENTER_EQUALS_INSTALL
//
// MessageText:
//
//  ENTER=Install%0
//
#define SP_STAT_ENTER_EQUALS_INSTALL     0x00002718L

//
// MessageId: SP_STAT_L_EQUALS_DELETE
//
// MessageText:
//
//  L=Delete%0
//
#define SP_STAT_L_EQUALS_DELETE          0x00002719L

//
// MessageId: SP_STAT_F3_EQUALS_REBOOT
//
// MessageText:
//
//  F3=Restart%0
//
#define SP_STAT_F3_EQUALS_REBOOT         0x0000271AL

//
// MessageId: SP_STAT_ESC_EQUALS_CANCEL
//
// MessageText:
//
//  ESC=Cancel%0
//
#define SP_STAT_ESC_EQUALS_CANCEL        0x0000271BL

//
// MessageId: SP_STAT_ENTER_EQUALS_CREATE
//
// MessageText:
//
//  ENTER=Create%0
//
#define SP_STAT_ENTER_EQUALS_CREATE      0x0000271CL

//
// MessageId: SP_STAT_C_EQUALS_CONTINUE_SETUP
//
// MessageText:
//
//  C=Continue Setup%0
//
#define SP_STAT_C_EQUALS_CONTINUE_SETUP  0x0000271DL

//
// MessageId: SP_STAT_ENTER_EQUALS_RESTART
//
// MessageText:
//
//  ENTER=Restart Computer%0
//
#define SP_STAT_ENTER_EQUALS_RESTART     0x0000271EL

//
// MessageId: SP_STAT_F_EQUALS_FORMAT
//
// MessageText:
//
//  F=Format%0
//
#define SP_STAT_F_EQUALS_FORMAT          0x0000271FL

//
// MessageId: SP_STAT_C_EQUALS_CONVERT
//
// MessageText:
//
//  C=Convert%0
//
#define SP_STAT_C_EQUALS_CONVERT         0x00002720L

//
// MessageId: SP_STAT_EXAMINING_DISK_CONFIG
//
// MessageText:
//
//  Examining disk configuration...%0
//
#define SP_STAT_EXAMINING_DISK_CONFIG    0x00002721L

//
// MessageId: SP_STAT_ENTER_EQUALS_SELECT
//
// MessageText:
//
//  ENTER=Select%0
//
#define SP_STAT_ENTER_EQUALS_SELECT      0x00002722L

//
// MessageId: SP_STAT_R_EQUALS_REMOVE_FILES
//
// MessageText:
//
//  R=Remove Files%0
//
#define SP_STAT_R_EQUALS_REMOVE_FILES    0x00002723L

//
// MessageId: SP_STAT_REMOVING
//
// MessageText:
//
//  Removing:%0
//
#define SP_STAT_REMOVING                 0x00002724L

//
// MessageId: SP_STAT_UPDATING_DISK
//
// MessageText:
//
//  Updating %1...%0
//
#define SP_STAT_UPDATING_DISK            0x00002725L

//
// MessageId: SP_STAT_LOOKING_FOR_WIN31
//
// MessageText:
//
//  Searching for versions of Microsoft Windows...%0
//
#define SP_STAT_LOOKING_FOR_WIN31        0x00002726L

//
// MessageId: SP_STAT_N_EQUALS_NEW_PATH
//
// MessageText:
//
//  N=Different Folder%0
//
#define SP_STAT_N_EQUALS_NEW_PATH        0x00002727L

//
// MessageId: SP_STAT_EXAMINING_DISK_N
//
// MessageText:
//
//  Examining %1...%0
//
#define SP_STAT_EXAMINING_DISK_N         0x00002728L

//
// MessageId: SP_STAT_ESC_EQUALS_NEW_PATH
//
// MessageText:
//
//  ESC=Different Folder%0
//
#define SP_STAT_ESC_EQUALS_NEW_PATH      0x00002729L

//
// MessageId: SP_STAT_PLEASE_WAIT
//
// MessageText:
//
//  Please wait...%0
//
#define SP_STAT_PLEASE_WAIT              0x0000272AL

//
// MessageId: SP_STAT_S_EQUALS_SKIP_DETECTION
//
// MessageText:
//
//  S=Skip Detection%0
//
#define SP_STAT_S_EQUALS_SKIP_DETECTION  0x0000272BL

//
// MessageId: SP_STAT_LOADING_DRIVER
//
// MessageText:
//
//  Loading device driver (%1)...%0
//
#define SP_STAT_LOADING_DRIVER           0x0000272CL

//
// MessageId: SP_STAT_S_EQUALS_SCSI_ADAPTER
//
// MessageText:
//
//  S=Specify Additional Device%0
//
#define SP_STAT_S_EQUALS_SCSI_ADAPTER    0x0000272DL

//
// MessageId: SP_STAT_CREATING_DIRS
//
// MessageText:
//
//  Creating folder %1...%0
//
#define SP_STAT_CREATING_DIRS            0x0000272EL

//
// MessageId: SP_STAT_ENTER_EQUALS_RETRY
//
// MessageText:
//
//  ENTER=Retry%0
//
#define SP_STAT_ENTER_EQUALS_RETRY       0x0000272FL

//
// MessageId: SP_STAT_ESC_EQUALS_SKIP_FILE
//
// MessageText:
//
//  ESC=Skip File%0
//
#define SP_STAT_ESC_EQUALS_SKIP_FILE     0x00002730L

//
// MessageId: SP_STAT_BUILDING_COPYLIST
//
// MessageText:
//
//  Creating list of files to be copied...%0
//
#define SP_STAT_BUILDING_COPYLIST        0x00002731L

//
// MessageId: SP_STAT_COPYING
//
// MessageText:
//
//  Copying:%0
//
#define SP_STAT_COPYING                  0x00002732L

//
// MessageId: SP_STAT_LOADING_SIF
//
// MessageText:
//
//  Loading information file %1...%0
//
#define SP_STAT_LOADING_SIF              0x00002733L

//
// MessageId: SP_STAT_REG_LOADING_HIVES
//
// MessageText:
//
//  Loading default configuration...%0
//
#define SP_STAT_REG_LOADING_HIVES        0x00002734L

//
// MessageId: SP_STAT_REG_SAVING_HIVES
//
// MessageText:
//
//  Saving configuration...%0
//
#define SP_STAT_REG_SAVING_HIVES         0x00002735L

//
// MessageId: SP_STAT_REG_DOING_HIVES
//
// MessageText:
//
//  Initializing configuration...%0
//
#define SP_STAT_REG_DOING_HIVES          0x00002736L

//
// MessageId: SP_STAT_INITING_FLEXBOOT
//
// MessageText:
//
//  Setting startup configuration...%0
//
#define SP_STAT_INITING_FLEXBOOT         0x00002737L

//
// MessageId: SP_STAT_UPDATING_NVRAM
//
// MessageText:
//
//  Updating startup environment...%0
//
#define SP_STAT_UPDATING_NVRAM           0x00002738L

//
// MessageId: SP_STAT_SHUTTING_DOWN
//
// MessageText:
//
//  Restarting computer...%0
//
#define SP_STAT_SHUTTING_DOWN            0x00002739L

//
// MessageId: SP_STAT_PROCESSING_SIF
//
// MessageText:
//
//  Processing information file...%0
//
#define SP_STAT_PROCESSING_SIF           0x0000273AL

//
// MessageId: SP_STAT_DOING_NTBOOTDD
//
// MessageText:
//
//  Initializing SCSI startup configuration...%0
//
#define SP_STAT_DOING_NTBOOTDD           0x0000273BL

//
// MessageId: SP_STAT_FONT_UPGRADE
//
// MessageText:
//
//  Preparing to upgrade font file %1...%0
//
#define SP_STAT_FONT_UPGRADE             0x0000273CL

//
// MessageId: SP_STAT_EXAMINING_CONFIG
//
// MessageText:
//
//  Examining configuration...%0
//
#define SP_STAT_EXAMINING_CONFIG         0x0000273DL

// MessageId=10046 SymbolicName=SP_STAT_HELP_UPGRADE
// Language=English
// Preparing to upgrade help file %1...%0
// .
//
// MessageId: SP_STAT_I_EQUALS_INIT_NEC98
//
// MessageText:
//
//  I=Initialize Disk%0
//
#define SP_STAT_I_EQUALS_INIT_NEC98      0x0000273FL

//
// MessageId: SP_STAT_S_EQUALS_CHANGE_DISK_STYLE
//
// MessageText:
//
//  S=Change Disk Style%0
//
#define SP_STAT_S_EQUALS_CHANGE_DISK_STYLE 0x00002740L

//
// MessageId: SP_STAT_M_EQUALS_MAKE_SYSPART
//
// MessageText:
//
//  M=Make System Partition%0
//
#define SP_STAT_M_EQUALS_MAKE_SYSPART    0x00002741L

//
// MessageId: SP_STAT_LOOKING_FOR_WINNT
//
// MessageText:
//
//  Searching for previous versions of Microsoft Windows...%0
//
#define SP_STAT_LOOKING_FOR_WINNT        0x0000274CL

//
// MessageId: SP_STAT_EXAMINING_FLEXBOOT
//
// MessageText:
//
//  Examining startup environment...%0
//
#define SP_STAT_EXAMINING_FLEXBOOT       0x0000274DL

//
// MessageId: SP_STAT_DELETING_FILE
//
// MessageText:
//
//  Deleting file %1...%0
//
#define SP_STAT_DELETING_FILE            0x0000274EL

//
// MessageId: SP_STAT_CLEANING_FLEXBOOT
//
// MessageText:
//
//  Updating startup configuration...%0
//
#define SP_STAT_CLEANING_FLEXBOOT        0x0000274FL

//
// MessageId: SP_STAT_ENTER_EQUALS_UPGRADE
//
// MessageText:
//
//  ENTER=Upgrade%0
//
#define SP_STAT_ENTER_EQUALS_UPGRADE     0x00002750L

//
// MessageId: SP_STAT_O_EQUALS_OVERWRITE
//
// MessageText:
//
//  O=Overwrite%0
//
#define SP_STAT_O_EQUALS_OVERWRITE       0x00002751L

//
// MessageId: SP_STAT_BACKING_UP_FILE
//
// MessageText:
//
//  Backing up file %1 to %2...%0
//
#define SP_STAT_BACKING_UP_FILE          0x00002752L

//
// MessageId: SP_STAT_ESC_EQUALS_SKIP_OPERATION
//
// MessageText:
//
//  ESC=Skip Operation%0
//
#define SP_STAT_ESC_EQUALS_SKIP_OPERATION 0x00002753L

//
// MessageId: SP_STAT_ESC_EQUALS_NO_REPAIR
//
// MessageText:
//
//  ESC=Don't Repair%0
//
#define SP_STAT_ESC_EQUALS_NO_REPAIR     0x00002754L

//
// MessageId: SP_STAT_ENTER_EQUALS_CONTINUE_HELP
//
// MessageText:
//
//  ENTER=Next Page%0
//
#define SP_STAT_ENTER_EQUALS_CONTINUE_HELP 0x00002755L

//
// MessageId: SP_STAT_BACKSP_EQUALS_PREV_HELP
//
// MessageText:
//
//  BACKSPACE=Previous Page%0
//
#define SP_STAT_BACKSP_EQUALS_PREV_HELP  0x00002756L

//
// MessageId: SP_STAT_ESC_EQUALS_CANCEL_HELP
//
// MessageText:
//
//  ESC=Cancel Help%0
//
#define SP_STAT_ESC_EQUALS_CANCEL_HELP   0x00002757L

//
// MessageId: SP_STAT_LOADING_KBD_LAYOUT
//
// MessageText:
//
//  Loading Keyboard Layout library %1...%0
//
#define SP_STAT_LOADING_KBD_LAYOUT       0x00002758L

//
// MessageId: SP_STAT_R_EQUALS_REPAIR
//
// MessageText:
//
//  R=Repair%0
//
#define SP_STAT_R_EQUALS_REPAIR          0x00002759L

//
// MessageId: SP_STAT_ENTER_EQUALS_REPAIR
//
// MessageText:
//
//  ENTER=Repair%0
//
#define SP_STAT_ENTER_EQUALS_REPAIR      0x0000275AL

//
// MessageId: SP_STAT_EXAMINING_WINNT
//
// MessageText:
//
//  Examining %1...%0
//
#define SP_STAT_EXAMINING_WINNT          0x0000275BL

//
// MessageId: SP_STAT_REPAIR_WINNT
//
// MessageText:
//
//  Repairing %1 ...%0
//
#define SP_STAT_REPAIR_WINNT             0x0000275CL

//
// MessageId: SP_STAT_A_EQUALS_REPAIR_ALL
//
// MessageText:
//
//  A=Repair All%0
//
#define SP_STAT_A_EQUALS_REPAIR_ALL      0x0000275DL

//
// MessageId: SP_STAT_ENTER_EQUALS_CHANGE
//
// MessageText:
//
//  ENTER=Select/Deselect%0
//
#define SP_STAT_ENTER_EQUALS_CHANGE      0x0000275EL

//
// MessageId: SP_STAT_ESC_EQUALS_CLEAN_INSTALL
//
// MessageText:
//
//  ESC=Clean Install%0
//
#define SP_STAT_ESC_EQUALS_CLEAN_INSTALL 0x0000275FL

//
// MessageId: SP_STAT_M_EQUALS_REPAIR_MANUAL
//
// MessageText:
//
//  M=Manual Repair%0
//
#define SP_STAT_M_EQUALS_REPAIR_MANUAL   0x00002761L

//
// MessageId: SP_STAT_F_EQUALS_REPAIR_FAST
//
// MessageText:
//
//  F=Fast Repair%0
//
#define SP_STAT_F_EQUALS_REPAIR_FAST     0x00002762L

//
// MessageId: SP_STAT_KBD_HARD_REBOOT
//
// MessageText:
//
//  Shut Down Computer%0
//
#define SP_STAT_KBD_HARD_REBOOT          0x00002763L

//
// MessageId: SP_STAT_CHECKING_DRIVE
//
// MessageText:
//
//  Checking drive %1...%0
//
#define SP_STAT_CHECKING_DRIVE           0x00002764L

//
// MessageId: SP_STAT_SETUP_IS_EXAMINING_DIRS
//
// MessageText:
//
//  Setup is examining folders...%0
//
#define SP_STAT_SETUP_IS_EXAMINING_DIRS  0x00002765L

//
// MessageId: SP_STAT_ENTER_EQUALS_REPLACE_FILE
//
// MessageText:
//
//  ENTER=Replace File%0
//
#define SP_STAT_ENTER_EQUALS_REPLACE_FILE 0x00002766L

//
// MessageId: SP_STAT_U_EQUALS_UPGRADE
//
// MessageText:
//
//  U=Upgrade%0
//
#define SP_STAT_U_EQUALS_UPGRADE         0x00002767L

//
// MessageId: SP_STAT_X_EQUALS_ACCEPT_LICENSE
//
// MessageText:
//
//  F8=I agree%0
//
#define SP_STAT_X_EQUALS_ACCEPT_LICENSE  0x00002769L

//
// MessageId: SP_STAT_X_EQUALS_REJECT_LICENSE
//
// MessageText:
//
//  ESC=I do not agree%0
//
#define SP_STAT_X_EQUALS_REJECT_LICENSE  0x0000276AL

//
// MessageId: SP_STAT_PAGEDOWN_EQUALS_NEXT_LIC
//
// MessageText:
//
//  PAGE DOWN=Next Page%0
//
#define SP_STAT_PAGEDOWN_EQUALS_NEXT_LIC 0x0000276BL

//
// MessageId: SP_STAT_PAGEUP_EQUALS_PREV_LIC
//
// MessageText:
//
//  PAGE UP=Previous Page%0
//
#define SP_STAT_PAGEUP_EQUALS_PREV_LIC   0x0000276CL

//
// MessageId: SP_STAT_LOOKING_FOR_WIN95
//
// MessageText:
//
//  Searching for previous versions of Microsoft Windows...%0
//
#define SP_STAT_LOOKING_FOR_WIN95        0x0000276DL

//
// MessageId: SP_SCRN_EVALUATION_NOTIFY
//
// MessageText:
//
//  %%ISetup Notification:
//  
//  You are about to install an evaluation version of Microsoft(R)
//  Windows(R) operating system which contains a time limited expiration
//  for evaluation purposes only.
//  
//       To continue, press ENTER.
//  
//       To quit Setup without installing Windows, press F3.
//  
//
#define SP_SCRN_EVALUATION_NOTIFY        0x0000276EL

//
// MessageId: SP_STAT_L_EQUALS_LOCATE
//
// MessageText:
//
//  L=Locate%0
//
#define SP_STAT_L_EQUALS_LOCATE          0x0000276FL

//
// MessageId: SP_STAT_C_EQUALS_CMDCONS
//
// MessageText:
//
//  C=Console%0
//
#define SP_STAT_C_EQUALS_CMDCONS         0x00002770L

//
// MessageId: SP_SCRN_SYSTEMPARTITION_INVALID
//
// MessageText:
//
//  %%ISetup Notification:
//  
//  Setup has detected that your system partition is invalid.  You may
//  reconfigure your disk partitions now or exit Setup.
//  
//       To return to the disk partitioning menu, press ENTER.
//  
//       To quit Setup without installing Windows, press F3.
//  
//
#define SP_SCRN_SYSTEMPARTITION_INVALID  0x00002771L

//
// MessageId: SP_KBDLAYOUT_PROMPT
//
// MessageText:
//
//  To select non-default keyboard layout press ENTER now (%1!1u!)%0
//
#define SP_KBDLAYOUT_PROMPT              0x00002772L

//
// MessageId: SP_EMPTY_OPTION
//
// MessageText:
//
//  %0
//
#define SP_EMPTY_OPTION                  0x00002773L

//
// Header text goes here (id >= 11000).
//
//
// MessageId: SP_HEAD_PRO_SETUP
//
// MessageText:
//
//  Windows XP Professional Setup%0
//
#define SP_HEAD_PRO_SETUP                0x00002AF8L

//
// MessageId: SP_HEAD_SRV_SETUP
//
// MessageText:
//
//  Windows Server 2003, Standard Edition Setup%0
//
#define SP_HEAD_SRV_SETUP                0x00002AF9L

//
// MessageId: SP_HEAD_HELP
//
// MessageText:
//
//  Setup Help%0
//
#define SP_HEAD_HELP                     0x00002AFAL

//
// MessageId: SP_HEAD_LICENSE
//
// MessageText:
//
//  Windows Licensing Agreement%0
//
#define SP_HEAD_LICENSE                  0x00002AFBL

//
// MessageId: SP_HEAD_PER_SETUP
//
// MessageText:
//
//  Windows XP Home Edition Setup%0
//
#define SP_HEAD_PER_SETUP                0x00002AFCL

//
// MessageId: SP_HEAD_ADS_SETUP
//
// MessageText:
//
//  Windows Server 2003, Enterprise Edition Setup%0
//
#define SP_HEAD_ADS_SETUP                0x00002AFDL

//
// MessageId: SP_HEAD_DTC_SETUP
//
// MessageText:
//
//  Windows Server 2003, Datacenter Edition Setup%0
//
#define SP_HEAD_DTC_SETUP                0x00002AFEL

//
// MessageId: SP_HEAD_BLA_SETUP
//
// MessageText:
//
//  Windows Server 2003, Web Edition Setup%0
//
#define SP_HEAD_BLA_SETUP                0x00002AFFL

//
// MessageId: SP_HEAD_SBS_SETUP
//
// MessageText:
//
//  Windows Server 2003 for Small Business Server Setup%0
//
#define SP_HEAD_SBS_SETUP                0x00002B00L

//
// Miscellaneous text goes here (id >= 12000).
//
//
// MessageId: SP_TEXT_UNKNOWN_DISK_0
//
// MessageText:
//
//  Unknown Disk%0
//
#define SP_TEXT_UNKNOWN_DISK_0           0x00002EE0L

//
// MessageId: SP_TEXT_UNKNOWN_DISK_1
//
// MessageText:
//
//  %1!u! MB Disk on unknown adapter%0
//
#define SP_TEXT_UNKNOWN_DISK_1           0x00002EE1L

//
// MessageId: SP_TEXT_DISK_OFF_LINE
//
// MessageText:
//
//  (Setup cannot access this disk.)%0
//
#define SP_TEXT_DISK_OFF_LINE            0x00002EE2L

//
// MessageId: SP_TEXT_REGION_DESCR_1
//
// MessageText:
//
//  %1  %2!-35.35s!%3!5u! MB ( %4!5u! MB free)%0
//
#define SP_TEXT_REGION_DESCR_1           0x00002EE3L

//
// MessageId: SP_TEXT_REGION_DESCR_1a
//
// MessageText:
//
//  %1  %2!-35.35s!%3!5u! MB ( %4!5u! KB free)%0
//
#define SP_TEXT_REGION_DESCR_1a          0x00002EE4L

//
// MessageId: SP_TEXT_REGION_DESCR_2
//
// MessageText:
//
//  %1  %2!-35.35s!%3!5u! MB%0
//
#define SP_TEXT_REGION_DESCR_2           0x00002EE5L

//
// MessageId: SP_TEXT_REGION_DESCR_3
//
// MessageText:
//
//      Unpartitioned space                %1!5u! MB%0
//
#define SP_TEXT_REGION_DESCR_3           0x00002EE6L

//
// MessageId: SP_TEXT_SIZE_PROMPT
//
// MessageText:
//
//  Create partition of size (in MB):%0
//
#define SP_TEXT_SIZE_PROMPT              0x00002EE7L

//
// MessageId: SP_TEXT_SETUP_IS_FORMATTING
//
// MessageText:
//
//  Setup is formatting...%0
//
#define SP_TEXT_SETUP_IS_FORMATTING      0x00002EE8L

//
// MessageId: SP_TEXT_SETUP_IS_REMOVING_FILES
//
// MessageText:
//
//  Setup is deleting files...%0
//
#define SP_TEXT_SETUP_IS_REMOVING_FILES  0x00002EE9L

//
// MessageId: SP_TEXT_HARD_DISK_NO_MEDIA
//
// MessageText:
//
//  (There is no disk in this drive.)%0
//
#define SP_TEXT_HARD_DISK_NO_MEDIA       0x00002EEAL

//
// MessageId: SP_TEXT_FAT_FORMAT
//
// MessageText:
//
//  Format the partition using the FAT file system%0
//
#define SP_TEXT_FAT_FORMAT               0x00002EEBL

//
// MessageId: SP_TEXT_NTFS_FORMAT
//
// MessageText:
//
//  Format the partition using the NTFS file system%0
//
#define SP_TEXT_NTFS_FORMAT              0x00002EECL

//
// MessageId: SP_TEXT_NTFS_CONVERT
//
// MessageText:
//
//  Convert the partition to NTFS%0
//
#define SP_TEXT_NTFS_CONVERT             0x00002EEDL

//
// MessageId: SP_TEXT_DO_NOTHING
//
// MessageText:
//
//  Leave the current file system intact (no changes)%0
//
#define SP_TEXT_DO_NOTHING               0x00002EEEL

//
// MessageId: SP_TEXT_REMOVE_NO_FILES
//
// MessageText:
//
//  Do not delete any files%0
//
#define SP_TEXT_REMOVE_NO_FILES          0x00002EEFL

//
// MessageId: SP_TEXT_ANGLED_NONE
//
// MessageText:
//
//  <none>
//
#define SP_TEXT_ANGLED_NONE              0x00002EF0L

//
// MessageId: SP_TEXT_DBLSPACE_FORMAT
//
// MessageText:
//
//  %0
//
#define SP_TEXT_DBLSPACE_FORMAT          0x00002EF1L

//
// MessageId: SP_SYSPREP_INVALID_VERSION
//
// MessageText:
//
//  The operating system image is imcompatible with this version of
//  Windows.
//
#define SP_SYSPREP_INVALID_VERSION       0x00002EF2L

//
// MessageId: SP_SYSPREP_INVALID_PARTITION
//
// MessageText:
//
//  This computer does not have enough disk partitions for the selected
//  image.
//
#define SP_SYSPREP_INVALID_PARTITION     0x00002EF3L

//
// MessageId: SP_SYSPREP_NOT_ENOUGH_PARTITIONS
//
// MessageText:
//
//  This computer does not have enough disk partitions for the selected
//  image.
//
#define SP_SYSPREP_NOT_ENOUGH_PARTITIONS 0x00002EF4L

//
// MessageId: SP_SYSPREP_NOT_ENOUGH_DISK_SPACE
//
// MessageText:
//
//  This computer does not have enough disk space on the selected partition.
//
#define SP_SYSPREP_NOT_ENOUGH_DISK_SPACE 0x00002EF5L

//
// MessageId: SP_SYSPREP_ACL_FAILURE
//
// MessageText:
//
//  Cannot set permissions on %1.
//
#define SP_SYSPREP_ACL_FAILURE           0x00002EF6L

//
// MessageId: SP_SYSPREP_NO_MIRROR_FILE
//
// MessageText:
//
//  Cannot read image configuration file from %1
//
#define SP_SYSPREP_NO_MIRROR_FILE        0x00002EF7L

//
// MessageId: SP_SYSPREP_WRONG_PROCESSOR_COUNT_MULTI
//
// MessageText:
//
//  This computer is multiprocessor-enabled but the image is from
//  a uniprocessor-enabled computer.
//
#define SP_SYSPREP_WRONG_PROCESSOR_COUNT_MULTI 0x00002EF8L

//
// MessageId: SP_SYSPREP_WRONG_PROCESSOR_COUNT_UNI
//
// MessageText:
//
//  This computer is uniprocessor-enabled but the image is from
//  a multiprocessor-enabled computer.
//
#define SP_SYSPREP_WRONG_PROCESSOR_COUNT_UNI 0x00002EF9L

//
// MessageId: SP_SYSPREP_WRONG_HAL
//
// MessageText:
//
//  This computer uses a different HAL than the computer from which
//  the image was created.
//  
//  The signature of the original HAL is:
//  %1
//  
//  The signature of this computer's HAL is:
//  %2
//
#define SP_SYSPREP_WRONG_HAL             0x00002EFAL

//
// MessageId: SP_BOOTMSG_FAT_NTLDR_MISSING
//
// MessageText:
//
//  NTLDR is missing%0
//
#define SP_BOOTMSG_FAT_NTLDR_MISSING     0x00002F12L

//
// MessageId: SP_BOOTMSG_FAT_DISK_ERROR
//
// MessageText:
//
//  Disk error%0
//
#define SP_BOOTMSG_FAT_DISK_ERROR        0x00002F13L

//
// MessageId: SP_BOOTMSG_FAT_PRESS_KEY
//
// MessageText:
//
//  Press any key to restart%0
//
#define SP_BOOTMSG_FAT_PRESS_KEY         0x00002F14L

//
// MessageId: SP_BOOTMSG_NTFS_NTLDR_MISSING
//
// MessageText:
//
//  NTLDR is missing%0
//
#define SP_BOOTMSG_NTFS_NTLDR_MISSING    0x00002F15L

//
// MessageId: SP_BOOTMSG_NTFS_NTLDR_COMPRESSED
//
// MessageText:
//
//  NTLDR is compressed%0
//
#define SP_BOOTMSG_NTFS_NTLDR_COMPRESSED 0x00002F16L

//
// MessageId: SP_BOOTMSG_NTFS_DISK_ERROR
//
// MessageText:
//
//  A disk read error occurred%0
//
#define SP_BOOTMSG_NTFS_DISK_ERROR       0x00002F17L

//
// MessageId: SP_BOOTMSG_NTFS_PRESS_KEY
//
// MessageText:
//
//  Press Ctrl+Alt+Del to restart%0
//
#define SP_BOOTMSG_NTFS_PRESS_KEY        0x00002F18L

//
// MessageId: SP_BOOTMSG_MBR_INVALID_TABLE
//
// MessageText:
//
//  Invalid partition table%0
//
#define SP_BOOTMSG_MBR_INVALID_TABLE     0x00002F19L

//
// MessageId: SP_BOOTMSG_MBR_IO_ERROR
//
// MessageText:
//
//  Error loading operating system%0
//
#define SP_BOOTMSG_MBR_IO_ERROR          0x00002F1AL

//
// MessageId: SP_BOOTMSG_MBR_MISSING_OS
//
// MessageText:
//
//  Missing operating system%0
//
#define SP_BOOTMSG_MBR_MISSING_OS        0x00002F1BL

//
// MessageId: SP_TEXT_PARTITION_NAME_BASE
//
// MessageText:
//
//  XENIX%0
//
#define SP_TEXT_PARTITION_NAME_BASE      0x00002F44L

#define SP_TEXT_PARTITION_NAME_XENIX SP_TEXT_PARTITION_NAME_BASE
//
// MessageId: SP_TEXT_PARTITION_NAME_BOOTMANAGER
//
// MessageText:
//
//  OS/2 Boot Manager%0
//
#define SP_TEXT_PARTITION_NAME_BOOTMANAGER 0x00002F45L

//
// MessageId: SP_TEXT_PARTITION_NAME_EISA
//
// MessageText:
//
//  EISA Utilities%0
//
#define SP_TEXT_PARTITION_NAME_EISA      0x00002F46L

//
// MessageId: SP_TEXT_PARTITION_NAME_UNIX
//
// MessageText:
//
//  Unix%0
//
#define SP_TEXT_PARTITION_NAME_UNIX      0x00002F47L

//
// MessageId: SP_TEXT_PARTITION_NAME_NTFT
//
// MessageText:
//
//  Windows Fault Tolerance%0
//
#define SP_TEXT_PARTITION_NAME_NTFT      0x00002F48L

//
// MessageId: SP_TEXT_PARTITION_NAME_XENIXTABLE
//
// MessageText:
//
//  XENIX Table%0
//
#define SP_TEXT_PARTITION_NAME_XENIXTABLE 0x00002F49L

//
// MessageId: SP_TEXT_PARTITION_NAME_PPCBOOT
//
// MessageText:
//
//  System Reserved%0
//
#define SP_TEXT_PARTITION_NAME_PPCBOOT   0x00002F4AL

//
// MessageId: SP_TEXT_PARTITION_NAME_EZDRIVE
//
// MessageText:
//
//  EZDrive%0
//
#define SP_TEXT_PARTITION_NAME_EZDRIVE   0x00002F4BL

//
// MessageId: SP_TEXT_PARTITION_NAME_UNK
//
// MessageText:
//
//  Unknown%0
//
#define SP_TEXT_PARTITION_NAME_UNK       0x00002F4CL

//
// MessageId: SP_TEXT_PARTITION_NAME_PWRQST
//
// MessageText:
//
//  PowerQuest%0
//
#define SP_TEXT_PARTITION_NAME_PWRQST    0x00002F4EL

//
// MessageId: SP_TEXT_PARTITION_NAME_BMHIDE
//
// MessageText:
//
//  Inactive (OS/2 Boot Manager)%0
//
#define SP_TEXT_PARTITION_NAME_BMHIDE    0x00002F4FL

//
// MessageId: SP_TEXT_PARTITION_NAME_ONTRACK
//
// MessageText:
//
//  OnTrack Disk Manager%0
//
#define SP_TEXT_PARTITION_NAME_ONTRACK   0x00002F50L

//
// MessageId: SP_TEXT_PARTITION_NAME_VERIT
//
// MessageText:
//
//  Windows%0
//
#define SP_TEXT_PARTITION_NAME_VERIT     0x00002F51L

//
// MessageId: SP_TEXT_MIGRATED_DRIVER
//
// MessageText:
//
//  Unknown device (migrated driver: %1)%0
//
#define SP_TEXT_MIGRATED_DRIVER          0x00002F52L

//
// MessageId: SP_TEXT_UNKNOWN_DISK_2
//
// MessageText:
//
//  %1!u! MB Disk on %2%0
//
#define SP_TEXT_UNKNOWN_DISK_2           0x00002F53L

//
// MessageId: SP_TEXT_PARTNAME_DESCR_1
//
// MessageText:
//
//  Partition%1!u! (%2!-0.11s!) [%3]%0
//
#define SP_TEXT_PARTNAME_DESCR_1         0x00002F54L

//
// MessageId: SP_TEXT_PARTNAME_DESCR_2
//
// MessageText:
//
//  Partition%1!u! [%2]%0
//
#define SP_TEXT_PARTNAME_DESCR_2         0x00002F55L

//
// MessageId: SP_TEXT_PARTNAME_DESCR_3
//
// MessageText:
//
//  Partition%1!u! (%2!-0.30s!)%0
//
#define SP_TEXT_PARTNAME_DESCR_3         0x00002F56L

//
// MessageId: SP_TEXT_PARTNAME_RESERVED
//
// MessageText:
//
//  Reserved%0
//
#define SP_TEXT_PARTNAME_RESERVED        0x00002F57L

//
// Allow for expansion of the partition type name database above!
// (Note the gap between the message numbers of
// SP_TEXT_PARTITION_NAME_UNK and SP_TEXT_FS_NAME_BASE.)
//
//
// Do not change the order of SP_TEXT_FS_NAME_xxx without
// also changing the FilesystemType enum!
//
//
// MessageId: SP_TEXT_FS_NAME_BASE
//
// MessageText:
//
//  Unformatted or Damaged%0
//
#define SP_TEXT_FS_NAME_BASE             0x00002FA8L

//
// MessageId: SP_TEXT_FS_NAME_1
//
// MessageText:
//
//  New (Raw)%0
//
#define SP_TEXT_FS_NAME_1                0x00002FA9L

//
// MessageId: SP_TEXT_FS_NAME_2
//
// MessageText:
//
//  FAT%0
//
#define SP_TEXT_FS_NAME_2                0x00002FAAL

//
// MessageId: SP_TEXT_FS_NAME_3
//
// MessageText:
//
//  NTFS%0
//
#define SP_TEXT_FS_NAME_3                0x00002FABL

//
// MessageId: SP_TEXT_FS_NAME_4
//
// MessageText:
//
//  FAT32%0
//
#define SP_TEXT_FS_NAME_4                0x00002FACL

//
// MessageId: SP_TEXT_FS_NAME_5
//
// MessageText:
//
//  NTFS%0
//
#define SP_TEXT_FS_NAME_5                0x00002FADL

//
// MessageId: SP_TEXT_UNKNOWN
//
// MessageText:
//
//  Unknown%0
//
#define SP_TEXT_UNKNOWN                  0x00002FAFL

//
// MessageId: SP_TEXT_LIST_MATCHES
//
// MessageText:
//
//  The above list matches my computer.%0
//
#define SP_TEXT_LIST_MATCHES             0x00002FB0L

//
// MessageId: SP_TEXT_OTHER_HARDWARE
//
// MessageText:
//
//  Other (Requires disk provided by a hardware manufacturer)%0
//
#define SP_TEXT_OTHER_HARDWARE           0x00002FB1L

//
// MessageId: SP_TEXT_OEM_DISK_NAME
//
// MessageText:
//
//  Manufacturer-supplied hardware support disk%0
//
#define SP_TEXT_OEM_DISK_NAME            0x00002FB2L

//
// MessageId: SP_TEXT_OEM_INF_ERROR_0
//
// MessageText:
//
//  Setup cannot load the file.
//  
//
#define SP_TEXT_OEM_INF_ERROR_0          0x00002FB3L

//
// MessageId: SP_TEXT_OEM_INF_ERROR_1
//
// MessageText:
//
//  The disk contains no support files for the component you are
//  attempting to change.
//  
//  
//  
//
#define SP_TEXT_OEM_INF_ERROR_1          0x00002FB4L

//
// MessageId: SP_TEXT_OEM_INF_ERROR_2
//
// MessageText:
//
//  Syntax error on line %2!u! in section
//  %1
//  
//
#define SP_TEXT_OEM_INF_ERROR_2          0x00002FB5L

//
// MessageId: SP_TEXT_OEM_INF_ERROR_3
//
// MessageText:
//
//  Section %1
//  missing or empty.
//  
//
#define SP_TEXT_OEM_INF_ERROR_3          0x00002FB6L

//
// MessageId: SP_TEXT_OEM_INF_ERROR_4
//
// MessageText:
//
//  Unknown file type specified on line %2!u! in section
//  %1.
//  
//  
//
#define SP_TEXT_OEM_INF_ERROR_4          0x00002FB7L

//
// MessageId: SP_TEXT_OEM_INF_ERROR_5
//
// MessageText:
//
//  Bad source disk specified on line %2!u! in section
//  %1.
//  
//  
//
#define SP_TEXT_OEM_INF_ERROR_5          0x00002FB8L

//
// MessageId: SP_TEXT_OEM_INF_ERROR_6
//
// MessageText:
//
//  Unknown registry value type specified on line %2!u! in section
//  %1.
//  
//  
//
#define SP_TEXT_OEM_INF_ERROR_6          0x00002FB9L

//
// MessageId: SP_TEXT_OEM_INF_ERROR_7
//
// MessageText:
//
//  Badly formed registry data on line %2!u! in section
//  %1.
//  
//  
//
#define SP_TEXT_OEM_INF_ERROR_7          0x00002FBAL

//
// MessageId: SP_TEXT_OEM_INF_ERROR_8
//
// MessageText:
//
//  Missing <configname> (field 3) on line %2!u! in section
//  %1.
//  
//  
//
#define SP_TEXT_OEM_INF_ERROR_8          0x00002FBBL

//
// MessageId: SP_TEXT_OEM_INF_ERROR_9
//
// MessageText:
//
//  Illegal or missing file types specified in section
//  %1.
//  
//  
//
#define SP_TEXT_OEM_INF_ERROR_9          0x00002FBCL

//
// MessageId: SP_TEXT_OEM_INF_ERROR_A
//
// MessageText:
//
//  Line %2!u! contains a syntax error.
//  
//
#define SP_TEXT_OEM_INF_ERROR_A          0x00002FBDL

//
// MessageId: SP_TEXT_MORE_UP
//
// MessageText:
//
//  (More )%0
//
#define SP_TEXT_MORE_UP                  0x00002FBEL

//
// MessageId: SP_TEXT_MORE_DOWN
//
// MessageText:
//
//  (More )%0
//
#define SP_TEXT_MORE_DOWN                0x00002FBFL

//
// MessageId: SP_TEXT_FOUND_ADAPTER
//
// MessageText:
//
//  Found: %1%0
//
#define SP_TEXT_FOUND_ADAPTER            0x00002FC0L

//
// MessageId: SP_TEXT_SETUP_IS_COPYING
//
// MessageText:
//
//  Setup is copying files...%0
//
#define SP_TEXT_SETUP_IS_COPYING         0x00002FC1L

//
// MessageId: SP_TEXT_PREVIOUS_OS
//
// MessageText:
//
//  Unidentified operating system on drive %1.%0
//
#define SP_TEXT_PREVIOUS_OS              0x00002FC2L

//
// MessageId: SP_TEXT_REPAIR_DISK_NAME
//
// MessageText:
//
//  Windows Emergency Repair Disk%0
//
#define SP_TEXT_REPAIR_DISK_NAME         0x00002FC4L

//
// MessageId: SP_TEXT_REPAIR_INF_ERROR_0
//
// MessageText:
//
//  Setup cannot find or load the file.
//
#define SP_TEXT_REPAIR_INF_ERROR_0       0x00002FC5L

//
// MessageId: SP_TEXT_REPAIR_INF_ERROR_1
//
// MessageText:
//
//  Line %2!u! contains a syntax error.
//
#define SP_TEXT_REPAIR_INF_ERROR_1       0x00002FC6L

//
// MessageId: SP_TEXT_REPAIR_INF_ERROR_2
//
// MessageText:
//
//  Incorrect or missing signature in the Repair Information File.
//
#define SP_TEXT_REPAIR_INF_ERROR_2       0x00002FC7L

//
// MessageId: SP_TEXT_REPAIR_INF_ERROR_3
//
// MessageText:
//
//  Setup cannot load the source file %1 or the source
//  file is not the original one Setup copied to the
//  Windows installation.
//
#define SP_TEXT_REPAIR_INF_ERROR_3       0x00002FC8L

//
// MessageId: SP_TEXT_REPAIR_INF_ERROR_4
//
// MessageText:
//
//  Setup has determined that the file:
//  
//      %1
//  
//  is not the original file that Setup copied to the
//  Windows installation.
//
#define SP_TEXT_REPAIR_INF_ERROR_4       0x00002FC9L

//
// MessageId: SP_TEXT_REPAIR_INF_ERROR_5
//
// MessageText:
//
//  The file is not the Windows version.
//
#define SP_TEXT_REPAIR_INF_ERROR_5       0x00002FCAL

//
// MessageId: SP_TEXT_SETUP_IS_EXAMINING
//
// MessageText:
//
//  Setup is examining files...%0
//
#define SP_TEXT_SETUP_IS_EXAMINING       0x00002FCBL

//
// MessageId: SP_TEXT_REPAIR_CDROM_OPTION
//
// MessageText:
//
//  Repair Windows from CD%0
//
#define SP_TEXT_REPAIR_CDROM_OPTION      0x00002FCCL

//
// MessageId: SP_TEXT_REPAIR_OR_DR_DISK_NAME
//
// MessageText:
//
//  Windows Emergency Repair Disk or Automated System Recovery Disk%0
//
#define SP_TEXT_REPAIR_OR_DR_DISK_NAME   0x00002FCDL

//
// MessageId: SP_REPAIR_MENU_ITEM_1
//
// MessageText:
//
//  [X] Inspect startup environment%0
//
#define SP_REPAIR_MENU_ITEM_1            0x00002FCFL

//
// MessageId: SP_REPAIR_MENU_ITEM_2
//
// MessageText:
//
//  [X] Verify Windows system files%0
//
#define SP_REPAIR_MENU_ITEM_2            0x00002FD0L

//
// MessageId: SP_REPAIR_MENU_ITEM_3
//
// MessageText:
//
//  [X] Inspect boot sector%0
//
#define SP_REPAIR_MENU_ITEM_3            0x00002FD1L

//
// MessageId: SP_REPAIR_MENU_ITEM_CONTINUE
//
// MessageText:
//
//      Continue (perform selected tasks)%0
//
#define SP_REPAIR_MENU_ITEM_CONTINUE     0x00002FD3L

//
// MessageId: SP_REPAIR_HIVE_ITEM_1
//
// MessageText:
//
//  [ ] SYSTEM (System Configuration)%0
//
#define SP_REPAIR_HIVE_ITEM_1            0x00002FD4L

//
// MessageId: SP_REPAIR_HIVE_ITEM_2
//
// MessageText:
//
//  [ ] SOFTWARE (Software Information)%0
//
#define SP_REPAIR_HIVE_ITEM_2            0x00002FD5L

//
// MessageId: SP_REPAIR_HIVE_ITEM_3
//
// MessageText:
//
//  [ ] DEFAULT (Default User Profile)%0
//
#define SP_REPAIR_HIVE_ITEM_3            0x00002FD6L

//
// MessageId: SP_REPAIR_HIVE_ITEM_4
//
// MessageText:
//
//  [ ] NTUSER.DAT (New User Profile)%0
//
#define SP_REPAIR_HIVE_ITEM_4            0x00002FD7L

//
// MessageId: SP_REPAIR_HIVE_ITEM_5
//
// MessageText:
//
//  [ ] SECURITY (Security Policy) and%0
//
#define SP_REPAIR_HIVE_ITEM_5            0x00002FD8L

//
// MessageId: SP_REPAIR_HIVE_ITEM_6
//
// MessageText:
//
//      SAM (User Accounts Database)%0
//
#define SP_REPAIR_HIVE_ITEM_6            0x00002FD9L

//
// MessageId: SP_UPG_MIRROR_DRIVELETTER
//
// MessageText:
//
//  (Mirror)%0
//
#define SP_UPG_MIRROR_DRIVELETTER        0x00002FDAL

//
// MessageId: SP_TEXT_OEM_INF_ERROR_B
//
// MessageText:
//
//  Section [%1] does not contain the description
//  %3
//  
//
#define SP_TEXT_OEM_INF_ERROR_B          0x00002FDBL

//
// ASR
//
//
// MessageId: SP_TEXT_DR_DISK_NAME
//
// MessageText:
//
//  Windows Automated System Recovery Disk%0
//
#define SP_TEXT_DR_DISK_NAME             0x00002FDCL

//
// MessageId: SP_TEXT_DR_UNKNOWN_NT_FILESYSTEM
//
// MessageText:
//
//  Setup encountered the following unrecoverable error while processing
//  the ASR state file asr.sif:
//  
//      An unrecognized file system is specified for the Windows
//      partition.
//  
//  Please check that the correct floppy is in the drive and that the ASR
//  state file has not been modified since its creation.
//  
//  Setup cannot continue. To quit Setup, press F3.
//
#define SP_TEXT_DR_UNKNOWN_NT_FILESYSTEM 0x00002FE2L

//
// MessageId: SP_TEXT_DR_UNKNOWN_LOADER_FILESYSTEM
//
// MessageText:
//
//  Setup encountered the following unrecoverable error while
//  processing the ASR state file asr.sif:
//  
//      An unrecognized file system is specified for the
//      system partition.
//  
//  Please check that the correct floppy is in the drive and that
//  the ASR state file has not been modified since its creation.
//  
//  Setup cannot continue. To quit Setup, press F3.
//
#define SP_TEXT_DR_UNKNOWN_LOADER_FILESYSTEM 0x00002FE3L

//
// MessageId: SP_TEXT_DR_INSUFFICIENT_CAPACITY
//
// MessageText:
//
//  Setup was unable to restore the configuration of your system
//  because of the following error:
//  
//      The capacity of the replacement hard disk drives is
//      insufficient, and cannot be used to recover the
//      partitions on the original system disk.
//  
//  The replacement hard disk drives must be at least as large
//  as the disks present on the original system.
//  
//  Please make sure that all the hard disk drives are switched
//  on and properly connected to your computer, and that any
//  disk-related hardware configuration is correct. This may
//  involve running a manufacturer-supplied diagnostic or setup
//  program. If the disk is a SCSI disk, make sure your SCSI
//  devices are properly terminated. Consult your computer manual
//  or SCSI adapter documentation for more information.
//  
//  Setup cannot continue. To quit Setup, press F3.
//
#define SP_TEXT_DR_INSUFFICIENT_CAPACITY 0x00002FE4L

//
// MessageId: SP_TEXT_DR_INTERNAL_ERROR
//
// MessageText:
//
//  Setup was unable to restore the configuration of your system
//  because of an internal error (%1).
//  
//  Please check that the correct floppy is in the drive and that
//  the ASR state file has not been modified since its creation.
//  
//  Please make sure that all the hard disk drives are switched
//  on and properly connected to your computer, and that any
//  disk-related hardware configuration is correct. This may
//  involve running a manufacturer-supplied diagnostic or setup
//  program. If the disk is a SCSI disk, make sure your SCSI
//  devices are properly terminated. Consult your computer manual
//  or SCSI adapter documentation for more information.
//  
//  Setup cannot continue. To quit Setup, press F3.
//
#define SP_TEXT_DR_INTERNAL_ERROR        0x00002FE6L

//
// MessageId: SP_SCRN_ASR_IS_EXAMINING
//
// MessageText:
//
//  Please wait while the Setup examines files on
//  your hard disk.
//
#define SP_SCRN_ASR_IS_EXAMINING         0x00002FE7L

//
// MessageId: SP_TEXT_DR_NO_SETUPLOG
//
// MessageText:
//
//  Setup was unable to read the log file from the
//  Emergency Repair disk.  Please ensure that
//  the file setup.log is present and readable.
//  
//  Setup cannot continue. To quit Setup, press F3.
//
#define SP_TEXT_DR_NO_SETUPLOG           0x00002FE8L

//
// MessageId: SP_SCRN_DR_DISK_REFORMAT_WARNING
//
// MessageText:
//
//  To restore the configuration of your system, Setup must delete
//  and recreate all the partitions on the disks listed below.
//  
//  CAUTION:  All data present on these disks will be lost.
//  
//  Do you want to continue recreating the partitions?
//  
//       To continue, press C.  Partitions on all the disks listed
//        below will be deleted.
//  
//       To quit Setup, press F3.  No changes will be made to any
//        of the disks on the system.
//  
//  
//
#define SP_SCRN_DR_DISK_REFORMAT_WARNING 0x00002FE9L

//
// MessageId: SP_SCRN_DR_OR_REPAIR
//
// MessageText:
//
//  Windows Repair Options:
//  
//       To repair a Windows installation by using the recovery
//        console, press C.
//  
//       To repair a Windows installation by using the
//        emergency repair process, press R.
//  
//  
//  If the repair options do not successfully repair your system, run
//  Windows Setup again.
//
#define SP_SCRN_DR_OR_REPAIR             0x00002FEEL

//
// MessageId: SP_SCRN_REPAIR_MANUAL_OR_FAST
//
// MessageText:
//
//  This operation will attempt to repair your Windows system.
//  Depending on the type of damage present, this operation may or
//  may not be successful. If the system is not successfully repaired,
//  restart Setup and choose the option to recover a destroyed system
//  or system disk.
//  
//  Select one of the following repair options.
//  
//       Manual Repair: To choose from a list of repair options, press M.
//  
//       Fast Repair: To perform all repair options, press F.
//
#define SP_SCRN_REPAIR_MANUAL_OR_FAST    0x00002FEFL

//
// MessageId: SP_SCRN_DR_CANNOT_DO_ER
//
// MessageText:
//
//  Emergency Repair cannot continue.
//  
//  
//  The Emergency Repair procedure cannot repair this Windows system,
//  because the Windows partition has been recreated and/or
//  reformatted by the Automated System Recovery procedure, and the files
//  on the partition are no longer intact.
//
#define SP_SCRN_DR_CANNOT_DO_ER          0x00002FF0L

//
//   End of DR/ER messages
//
//
// MessageId: SP_TEXT_SETUP_IS_DELETING
//
// MessageText:
//
//  Setup is deleting files...%0
//
#define SP_TEXT_SETUP_IS_DELETING        0x00002FF1L

//
// MessageId: SP_TEXT_SETUP_REBOOT
//
// MessageText:
//
//  Your computer will reboot in %%d seconds...%0
//
#define SP_TEXT_SETUP_REBOOT             0x0000300CL

//
//   More DR/ER messages
//
//
// MessageId: SP_SCRN_DR_SIF_BAD_RECORD
//
// MessageText:
//
//  Setup encountered the following error while processing
//  the ASR state file asr.sif:
//  
//      Invalid record in section: %1
//  
//  Please check that the correct floppy is in the drive and that
//  the ASR state file has not been modified since its creation.
//  
//  Setup cannot continue. To quit Setup, press F3.
//
#define SP_SCRN_DR_SIF_BAD_RECORD        0x00003074L

//
// MessageId: SP_SCRN_DR_SIF_INSTALL_FILE_NOT_FOUND
//
// MessageText:
//
//  Setup encountered errors while copying the following file
//  to your system.
//  
//      File: %1
//  
//      Source Media Label: %2
//  
//      Vendor: %3
//  
//  This file may be required for the successful completion
//  of Automated System Recovery.
//  
//       To retry, press Enter
//  
//       To quit Setup, press F3
//  
//       To skip this file and continue, press ESC.
//
#define SP_SCRN_DR_SIF_INSTALL_FILE_NOT_FOUND 0x00003076L

//
// MessageId: SP_SCRN_DR_CREATE_ERROR_DISK_PARTITION
//
// MessageText:
//
//  Setup was unable to create the partitions listed in the ASR
//  state file, asr.sif.
//  
//  Please check that the correct floppy is in the drive and that
//  the ASR state file has not been modified since its creation.
//  
//  Please make sure that all the hard disk drives are switched
//  on and properly connected to your computer, and that any
//  disk-related hardware configuration is correct. This may
//  involve running a manufacturer-supplied diagnostic or setup
//  program. If the disk is a SCSI disk, make sure your SCSI
//  devices are properly terminated. Consult your computer manual
//  or SCSI adapter documentation for more information.
//  
//  
//  Setup cannot continue. To quit Setup, press F3.
//
#define SP_SCRN_DR_CREATE_ERROR_DISK_PARTITION 0x0000307CL

//
// MessageId: SP_TEXT_DR_BAD_SETUPLOG
//
// MessageText:
//
//  Setup encountered an error in one or more records of
//  the log file setup.log on the ASR disk.
//  
//  Setup cannot continue. To quit Setup, press F3.
//
#define SP_TEXT_DR_BAD_SETUPLOG          0x0000307DL

//
// MessageId: SP_TEXT_DR_STATEFILE_BAD_LINE
//
// MessageText:
//
//  Setup encountered the following error while processing
//  the ASR state file asr.sif:
//  
//      Invalid file format at line %1!u!
//  
//  Please check that the correct floppy is in the drive and that
//  the ASR state file has not been modified since its creation.
//  
//  Setup cannot continue. To quit Setup, press F3.
//
#define SP_TEXT_DR_STATEFILE_BAD_LINE    0x0000307EL

//
// MessageId: SP_TEXT_DR_STATEFILE_ERROR
//
// MessageText:
//
//  Setup was unable process the ASR state file asr.sif on the
//  floppy disk.
//  
//  Please check that the correct floppy is in the drive and that
//  the ASR state file has not been modified since its creation.
//  
//  Setup cannot continue. To quit Setup, press F3.
//
#define SP_TEXT_DR_STATEFILE_ERROR       0x0000307FL

//
// MessageId: SP_TEXT_DR_NO_FLOPPY_DRIVE
//
// MessageText:
//
//  Setup could not detect a floppy drive on your machine.
//  
//  Setup cannot continue. To quit Setup, press F3.
//
#define SP_TEXT_DR_NO_FLOPPY_DRIVE       0x00003085L

//
// MessageId: SP_TEXT_DR_NO_ASRSIF_RIS
//
// MessageText:
//
//  Setup could not load the ASR state file asr.sif from the
//  network.
//  
//  Setup cannot continue. To quit Setup, press F3.
//
#define SP_TEXT_DR_NO_ASRSIF_RIS         0x00003086L

//
// MessageId: SP_SCRN_DR_OVERWRITE_EXISTING_FILE
//
// MessageText:
//
//  The following file already exists on your system.
//  
//      File: %1
//  
//        To over-write the existing file, press O.
//  
//        To preserve existing file and skip
//         copying this file, press ESC.
//  
//        To quit Setup, press F3.
//
#define SP_SCRN_DR_OVERWRITE_EXISTING_FILE 0x00003089L

//
// MessageId: SP_SCRN_DR_SIF_NOT_FOUND
//
// MessageText:
//
//  Setup could not copy the following file on to your system.
//  
//      File: %1
//  
//      Disk: %2
//  
//  
//  Since this file is required for a successful recovery,
//  Setup cannot proceed.
//  
//        To retry, press Enter
//  
//        To quit Setup, press F3
//
#define SP_SCRN_DR_SIF_NOT_FOUND         0x0000308AL

//
// MessageId: SP_CMDCONS_NOT_FOUND
//
// MessageText:
//
//  
//  
//  SPCMDCON.SYS file needed for Recovery Console is missing.
//  
//  Recovery Console cannot proceed.
//  
//       To exit, press F3
//
#define SP_CMDCONS_NOT_FOUND             0x0000308BL

//
// MessageId: SP_SCRN_DR_SYSTEM_DISK_TOO_SMALL
//
// MessageText:
//
//  Setup was unable to restore the configuration of your system
//  because of the following error:
//  
//      The capacity of the current system disk drive is
//      insufficient, and cannot be used to recover the
//      partitions on the original system disk.
//  
//  The replacement hard disk drives must be at least as large
//  as the disks present on the original system.
//  
//  Please make sure that all the hard disk drives are switched
//  on and properly connected to your computer, and that any
//  disk-related hardware configuration is correct. This may
//  involve running a manufacturer-supplied diagnostic or setup
//  program. If the disk is a SCSI disk, make sure your SCSI
//  devices are properly terminated. Consult your computer manual
//  or SCSI adapter documentation for more information.
//  
//  Setup cannot continue. To quit Setup, press F3.
//
#define SP_SCRN_DR_SYSTEM_DISK_TOO_SMALL 0x0000308CL

//
// MessageId: SP_SCRN_DR_INCOMPATIBLE_MEDIA
//
// MessageText:
//
//  Setup was unable to restore the configuration of your system
//  because of the following error:
//  
//      The Windows installation media you are using for the
//      recovery does not match the original installation media.
//  
//  Please check that the correct floppy is in the drive and that
//  the ASR state file has not been modified since its creation,
//  and restart ASR using the installation media used on the
//  original system.
//  
//  Setup cannot continue. To quit Setup, press F3.
//
#define SP_SCRN_DR_INCOMPATIBLE_MEDIA    0x0000308DL

//
// MessageId: SP_SCRN_BACKUP_SAVE_FAILED
//
// MessageText:
//
//  Setup cannot back up the file
//  
//    %1
//  
//  This error will not prevent Setup from completing successfully,
//  but it might cause the uninstall option to malfunction.
//  
//  
//     To continue without a backup of this file, press ENTER.
//  
//     To stop creation of the backup image, press Esc.
//  
//     To quit Setup, press F3.
//  
//  
//  Error code: %2!#lx!
//
#define SP_SCRN_BACKUP_SAVE_FAILED       0x0000308EL

//
// MessageId: SP_SCRN_BACKUP_IMAGE_FAILED
//
// MessageText:
//
//  Setup cannot create the backup image.
//  
//  This error will not prevent Setup from completing successfully,
//  but it will cause the uninstall option to malfunction.
//  
//  
//     To continue without the ability to uninstall, press ENTER.
//  
//     To quit Setup, press F3.
//
#define SP_SCRN_BACKUP_IMAGE_FAILED      0x0000308FL

//
// MessageId: SP_SCRN_ROLLBACK_FAILED
//
// MessageText:
//
//  Setup was not able to restore all files.
//  
//  This error might indicate that the restored operating system
//  won't work.
//  
//  
//     To quit Setup, press F3.
//
#define SP_SCRN_ROLLBACK_FAILED          0x00003090L

//
// MessageId: SP_SCRN_ROLLBACK_IMAGE_BAD
//
// MessageText:
//
//  Setup was not able to find a valid backup image. Uninstall
//  cannot be completed.
//  
//  
//     To quit Setup, press F3.
//
#define SP_SCRN_ROLLBACK_IMAGE_BAD       0x00003091L

//
// MessageId: SP_STAT_BACKING_UP_WIN9X_FILE
//
// MessageText:
//
//  Backing up %1...%0
//
#define SP_STAT_BACKING_UP_WIN9X_FILE    0x00003092L

//
// MessageId: SP_TEXT_PARTITION_NAME_DYNVOL
//
// MessageText:
//
//  Dynamic Volume%0
//
#define SP_TEXT_PARTITION_NAME_DYNVOL    0x00003093L

 #ifdef HEADLESS_ATTENDEDTEXTMODE_UNATTENDEDGUIMODE
 MessageId=12450 SymbolicName=SP_SCRN_GET_GUI_STUFF
 Language=English
 The following fields are needed to complete setup. Once you have
 filled a field press enter to move between fields.
 .

 MessageId=12451 SymbolicName=SP_SCRN_GET_TIME_ZONE
 Language=English
 Enter the timezone information. Use the arrow keys to move
 between the fields. Enter to select an option.
 .

 MessageId=12452 SymbolicName=SP_TEXT_NAME_PROMPT
 Language=English
 Name %0
 .

 MessageId=12453 SymbolicName=SP_TEXT_COMPUTER_PROMPT
 Language=English
 Computer %0
 .

 MessageId=12454 SymbolicName=SP_TEXT_ORG_PROMPT
 Language=English
 Organization %0
 .

 MessageId=12455 SymbolicName=SP_SCRN_GET_SERVER_TYPE
 Language=English
 Choose the type of server you want installed.USe arrow keys to move
 between the fields. Enter to select an option.
 .
 #endif
//
// MessageId: SP_SCRN_GET_ADMIN_PASSWORD
//
// MessageText:
//
//  Please enter the password that will be used for the Administrator
//  Account on this machine.  This password must not be empty.
//  
//  Administrator Password: %0
//
#define SP_SCRN_GET_ADMIN_PASSWORD       0x00003094L

//
// MessageId: SP_SCRN_GET_ADMIN_PASSWORD_CONFIRM
//
// MessageText:
//
//  Please re-enter the Administrator password.
//  
//  Password Confirmation: %0
//
#define SP_SCRN_GET_ADMIN_PASSWORD_CONFIRM 0x00003095L

//
// MessageId: SP_SCRN_GET_ADMIN_PASSWORD_FAILURE
//
// MessageText:
//
//  The Administrator password did not match the confirmation password.
//  
//  Please press enter to re-enter the Administrator password.
//
#define SP_SCRN_GET_ADMIN_PASSWORD_FAILURE 0x00003096L

//
// The following value is used for the localizable mnemonic keystrokes
// (such as C=Custom Setup, etc).  The first message is the list of
// values.  The second is an informative message for the localizers.
// The order of these values must match the MNEMONIC_KEYS enum (spdsputl.h).
// Note the zeroth item is not used.
//
//
// MessageId: SP_MNEMONICS
//
// MessageText:
//
//  *CCDCFCRNSSLORAUAILFMCSM%0
//
#define SP_MNEMONICS                     0x00003A98L

#endif // _USETUP_MSG_

 //
 // These are placeholders for localization-specific messages.
 // For example in Japan these are used for the special keyboard
 // confirmation messages.
 //
//
// MessageId: SP_SCRN_LOCALE_SPECIFIC_1
//
// MessageText:
//
//  SP_SCRN_LOCALE_SPECIFIC_1
//
#define SP_SCRN_LOCALE_SPECIFIC_1        0x00005208L

//
// MessageId: SP_SCRN_LOCALE_SPECIFIC_2
//
// MessageText:
//
//  SP_SCRN_LOCALE_SPECIFIC_2
//
#define SP_SCRN_LOCALE_SPECIFIC_2        0x00005209L

//
// MessageId: SP_SCRN_LOCALE_SPECIFIC_3
//
// MessageText:
//
//  SP_SCRN_LOCALE_SPECIFIC_3
//
#define SP_SCRN_LOCALE_SPECIFIC_3        0x0000520AL

//
// MessageId: SP_SCRN_LOCALE_SPECIFIC_4
//
// MessageText:
//
//  SP_SCRN_LOCALE_SPECIFIC_4
//
#define SP_SCRN_LOCALE_SPECIFIC_4        0x0000520BL

//
// MessageId: SP_SCRN_LOCALE_SPECIFIC_5
//
// MessageText:
//
//  SP_SCRN_LOCALE_SPECIFIC_5
//
#define SP_SCRN_LOCALE_SPECIFIC_5        0x0000520CL

//
// MessageId: SP_SCRN_LOCALE_SPECIFIC_6
//
// MessageText:
//
//  SP_SCRN_LOCALE_SPECIFIC_6
//
#define SP_SCRN_LOCALE_SPECIFIC_6        0x0000520DL

//
// MessageId: SP_SCRN_LOCALE_SPECIFIC_7
//
// MessageText:
//
//  SP_SCRN_LOCALE_SPECIFIC_7
//
#define SP_SCRN_LOCALE_SPECIFIC_7        0x0000520EL

//
// MessageId: SP_SCRN_LOCALE_SPECIFIC_8
//
// MessageText:
//
//  SP_SCRN_LOCALE_SPECIFIC_8
//
#define SP_SCRN_LOCALE_SPECIFIC_8        0x0000520FL

//
// MessageId: SP_SCRN_LOCALE_SPECIFIC_9
//
// MessageText:
//
//  SP_SCRN_LOCALE_SPECIFIC_9
//
#define SP_SCRN_LOCALE_SPECIFIC_9        0x00005210L

//
// MessageId: SP_SCRN_LOCALE_SPECIFIC_10
//
// MessageText:
//
//  SP_SCRN_LOCALE_SPECIFIC_10
//
#define SP_SCRN_LOCALE_SPECIFIC_10       0x00005211L

