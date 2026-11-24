/*++ BUILD Version: 0001    // Increment this if a change has global effects

Copyright (c) 1994-1995  Microsoft Corporation

Module Name:

    msg.h

Abstract:

    This file contains the message definitions for the Win32 MOUNTVOL
    utility.

Author:

    Norbert Kusters        [norbertk]        11-Sep-1997

Revision History:

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
// MessageId: MOUNTVOL_USAGE1
//
// MessageText:
//
//  Creates, deletes, or lists a volume mount point.
//  
//  MOUNTVOL [drive:]path VolumeName
//  MOUNTVOL [drive:]path /D
//  MOUNTVOL [drive:]path /L
//  MOUNTVOL [drive:]path /P
//  MOUNTVOL /R
//  MOUNTVOL /N
//  MOUNTVOL /E
//
#define MOUNTVOL_USAGE1                  0x00000001L

//
// MessageId: MOUNTVOL_USAGE1_IA64
//
// MessageText:
//
//  MOUNTVOL drive: /S
//
#define MOUNTVOL_USAGE1_IA64             0x00000002L

//
// MessageId: MOUNTVOL_USAGE2
//
// MessageText:
//
//  
//      path        Specifies the existing NTFS directory where the mount
//                  point will reside.
//      VolumeName  Specifies the volume name that is the target of the mount
//                  point.
//      /D          Removes the volume mount point from the specified directory.
//      /L          Lists the mounted volume name for the specified directory.
//      /P          Removes the volume mount point from the specified directory,
//                  dismounts the volume, and makes the volume not mountable.
//                  You can make the volume mountable again by creating a volume
//                  mount point.
//      /R          Removes volume mount point directories and registry settings
//                  for volumes that are no longer in the system.
//      /N          Disables automatic mounting of new volumes.
//      /E          Re-enables automatic mounting of new volumes.
//
#define MOUNTVOL_USAGE2                  0x00000003L

//
// MessageId: MOUNTVOL_USAGE2_IA64
//
// MessageText:
//
//      /S          Mount the EFI System Partition on the given drive.
//
#define MOUNTVOL_USAGE2_IA64             0x00000004L

//
// MessageId: MOUNTVOL_START_OF_LIST
//
// MessageText:
//
//  
//  Possible values for VolumeName along with current mount points are:
//  
//
#define MOUNTVOL_START_OF_LIST           0x00000005L

//
// MessageId: MOUNTVOL_MOUNT_POINT
//
// MessageText:
//
//          %1
//
#define MOUNTVOL_MOUNT_POINT             0x00000006L

//
// MessageId: MOUNTVOL_VOLUME_NAME
//
// MessageText:
//
//      %1
//
#define MOUNTVOL_VOLUME_NAME             0x00000007L

//
// MessageId: MOUNTVOL_NEWLINE
//
// MessageText:
//
//  
//
#define MOUNTVOL_NEWLINE                 0x00000008L

//
// MessageId: MOUNTVOL_NO_MOUNT_POINTS
//
// MessageText:
//
//          *** NO MOUNT POINTS ***
//  
//
#define MOUNTVOL_NO_MOUNT_POINTS         0x00000009L

//
// MessageId: MOUNTVOL_EFI
//
// MessageText:
//
//      The EFI System Partition is mounted at %1
//  
//
#define MOUNTVOL_EFI                     0x0000000AL

//
// MessageId: MOUNTVOL_VOLUME_IN_USE
//
// MessageText:
//
//  The volume is still in use.  A force dismount was issued and current handles
//  to the volume have been invalidated.
//
#define MOUNTVOL_VOLUME_IN_USE           0x0000000BL

//
// MessageId: MOUNTVOL_NOT_MOUNTED
//
// MessageText:
//
//          *** NOT MOUNTABLE UNTIL A VOLUME MOUNT POINT IS CREATED ***
//  
//
#define MOUNTVOL_NOT_MOUNTED             0x0000000CL

//
// MessageId: MOUNTVOL_NO_AUTO_MOUNT
//
// MessageText:
//
//  New volumes are not mounted automatically when added to the system.  To mount a
//  volume, you must create a volume mount point.
//  
//
#define MOUNTVOL_NO_AUTO_MOUNT           0x0000000DL

//
// MessageId: MOUNTVOL_OTHER_VOLUME_MOUNT_POINTS
//
// MessageText:
//
//  The /P option can only be used when the given mount point is the only mount
//  point for the volume.  Use /D instead.
//
#define MOUNTVOL_OTHER_VOLUME_MOUNT_POINTS 0x0000000EL

//
// MessageId: MOUNTVOL_NOT_SUPPORTED
//
// MessageText:
//
//  This volume does not support this operation.  Dynamic volumes and removable
//  volumes do not support this operation.
//
#define MOUNTVOL_NOT_SUPPORTED           0x0000000FL

