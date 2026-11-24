/*++

Copyright (c) 1991-2001  Microsoft Corporation

Module Name:

    clusvmsg.h

Abstract:

    This file contains the message definitions for the Cluster service.

Author:

    Mike Massa (mikemas) 2-Jan-1996

Revision History:

Notes:

    This file is generated from clusvmsg.mc

    How to add a new error log category: By convention, error log categories 
    start at 1 and increase monotonically. Start by adding a category
    identifier to the end of the list. Next, set LOG_CURRENT_MODULE in your
    source code to the symbolic name of the new category, e.g.:

    #define LOG_CURRENT_MODULE LOG_MODULE_XYZ

    The cluster event log macros will substitute your category ID
    appropriately.

    Finally, modify the CategoryCount entry in
    cluster\mgmt\cluscfg\basecluster\clcfgsrv.inf and
    cluster\mgmt\clusocm\clusocm.inf to the new total.

--*/

#ifndef _CLUSVMSG_INCLUDED
#define _CLUSVMSG_INCLUDED


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
// MessageId: LOG_MODULE_API
//
// MessageText:
//
//  API
//
#define LOG_MODULE_API                   1L

//
// MessageId: LOG_MODULE_EP
//
// MessageText:
//
//  Event Processor
//
#define LOG_MODULE_EP                    2L

//
// MessageId: LOG_MODULE_FM
//
// MessageText:
//
//  Failover Mgr
//
#define LOG_MODULE_FM                    3L

//
// MessageId: LOG_MODULE_OM
//
// MessageText:
//
//  Object Mgr
//
#define LOG_MODULE_OM                    4L

//
// MessageId: LOG_MODULE_NM
//
// MessageText:
//
//  Node Mgr
//
#define LOG_MODULE_NM                    5L

//
// MessageId: LOG_MODULE_GUM
//
// MessageText:
//
//  Global Update Mgr
//
#define LOG_MODULE_GUM                   6L

//
// MessageId: LOG_MODULE_CP
//
// MessageText:
//
//  Checkpoint Mgr
//
#define LOG_MODULE_CP                    7L

//
// MessageId: LOG_MODULE_INIT
//
// MessageText:
//
//  Startup/Shutdown
//
#define LOG_MODULE_INIT                  8L

//
// MessageId: LOG_MODULE_DM
//
// MessageText:
//
//  Database Mgr
//
#define LOG_MODULE_DM                    9L

//
// MessageId: LOG_MODULE_MM
//
// MessageText:
//
//  Membership Mgr
//
#define LOG_MODULE_MM                    10L

//
// MessageId: LOG_MODULE_RESMON
//
// MessageText:
//
//  Resource Monitor
//
#define LOG_MODULE_RESMON                11L

//
// MessageId: LOG_MODULE_LM
//
// MessageText:
//
//  Log Mgr
//
#define LOG_MODULE_LM                    12L

//
// MessageId: LOG_MODULE_EVTLOG
//
// MessageText:
//
//  Event Logger
//
#define LOG_MODULE_EVTLOG                13L

//
// MessageId: LOG_MODULE_CLRTL
//
// MessageText:
//
//  RTL
//
#define LOG_MODULE_CLRTL                 14L

//
// MessageId: LOG_MODULE_GENAPP
//
// MessageText:
//
//  Generic App Resource
//
#define LOG_MODULE_GENAPP                15L

//
// MessageId: LOG_MODULE_GENSVC
//
// MessageText:
//
//  Generic Service Resource
//
#define LOG_MODULE_GENSVC                16L

//
// MessageId: LOG_MODULE_FTSET
//
// MessageText:
//
//  FTSETs
//
#define LOG_MODULE_FTSET                 17L

//
// MessageId: LOG_MODULE_DISK
//
// MessageText:
//
//  Physical Disk Resource
//
#define LOG_MODULE_DISK                  18L

//
// MessageId: LOG_MODULE_NETNAME
//
// MessageText:
//
//  Network Name Resource
//
#define LOG_MODULE_NETNAME               19L

//
// MessageId: LOG_MODULE_IPADDR
//
// MessageText:
//
//  IP Address Resource
//
#define LOG_MODULE_IPADDR                20L

//
// MessageId: LOG_MODULE_SMB
//
// MessageText:
//
//  File Share Resource
//
#define LOG_MODULE_SMB                   21L

//
// MessageId: LOG_MODULE_TIME
//
// MessageText:
//
//  Time Service Resource
//
#define LOG_MODULE_TIME                  22L

//
// MessageId: LOG_MODULE_SPOOL
//
// MessageText:
//
//  Print Spooler Resource
//
#define LOG_MODULE_SPOOL                 23L

//
// MessageId: LOG_MODULE_LKQRM
//
// MessageText:
//
//  Local Quorum Resource
//
#define LOG_MODULE_LKQRM                 24L

//
// MessageId: LOG_MODULE_DHCP
//
// MessageText:
//
//  DHCP Resource
//
#define LOG_MODULE_DHCP                  25L

//
// MessageId: LOG_MODULE_MSMQ
//
// MessageText:
//
//  MS Message Queue Resource
//
#define LOG_MODULE_MSMQ                  26L

//
// MessageId: LOG_MODULE_MSDTC
//
// MessageText:
//
//  MS Distributed Trans. Co-ord. Resource
//
#define LOG_MODULE_MSDTC                 27L

//
// MessageId: LOG_MODULE_WINS
//
// MessageText:
//
//  WINS Resource
//
#define LOG_MODULE_WINS                  28L

//
// MessageId: LOG_MODULE_VSSCLUS
//
// MessageText:
//
//  Volume Snapshot Service support
//
#define LOG_MODULE_VSSCLUS               29L

//
// MessageId: LOG_MODULE_GENSCRIPT
//
// MessageText:
//
//  Generic Script Resource
//
#define LOG_MODULE_GENSCRIPT             30L

//
// end of Error Log Categories
//

//
// MessageId: UNEXPECTED_FATAL_ERROR
//
// MessageText:
//
//  Cluster service suffered an unexpected fatal error
//  at line %1 of source module %2. The error code was %3.
//
#define UNEXPECTED_FATAL_ERROR           1000L

//
// MessageId: ASSERTION_FAILURE
//
// MessageText:
//
//  Cluster service failed a validity check on line
//  %1 of source module %2.
//  "%3"
//
#define ASSERTION_FAILURE                1001L

//
// MessageId: LOG_FAILURE
//
// MessageText:
//
//  Cluster service handled an unexpected error
//  at line %1 of source module %2. The error code was %3.
//
#define LOG_FAILURE                      1002L


//
// DON'T USE MSG IDS 1003, 1004, OR 1005. ClRtlMsgPrint didn't log into the
// the cluster log. These msgs were intended for the cluster log and don't
// belong in the system event log. However, they need to be left here in order
// to interpret any old clussvc event entries.
//

//
// MessageId: INVALID_RESOURCETYPE_DLLNAME
//
// MessageText:
//
//  The DllName value for the %1!ws! resource type does not exist.
//  Resources of this type will not be monitored. The error was %2!d!.
//
#define INVALID_RESOURCETYPE_DLLNAME     1003L

//
// MessageId: INVALID_RESOURCETYPE_LOOKSALIVE
//
// MessageText:
//
//  The LooksAlive poll interval for the %1!ws! resource type does not exist.
//  Resources of this type will not be monitored. The error was %2!d!.
//
#define INVALID_RESOURCETYPE_LOOKSALIVE  1004L

//
// MessageId: INVALID_RESOURCETYPE_ISALIVE
//
// MessageText:
//
//  The IsAlive poll interval for the %1!ws! resource type does not exist.
//  Resources of this type will not be monitored. The error was %2!d!.
//
#define INVALID_RESOURCETYPE_ISALIVE     1005L

//
// MessageId: NM_EVENT_MEMBERSHIP_HALT
//
// MessageText:
//
//  Cluster service was halted due to a server cluster membership or
//  communications error. The error code was %1.
//
#define NM_EVENT_MEMBERSHIP_HALT         1006L

//
// MessageId: NM_EVENT_NEW_NODE
//
// MessageText:
//
//  A new node, %1, has been added to the server cluster.
//
#define NM_EVENT_NEW_NODE                1007L

//
// MessageId: RMON_INVALID_COMMAND_LINE
//
// MessageText:
//
//  Cluster Resource Monitor was started with an invalid command line
//  option: %1.
//
#define RMON_INVALID_COMMAND_LINE        1008L

//
// MessageId: SERVICE_FAILED_JOIN_OR_FORM
//
// MessageText:
//
//  Cluster service could not join an existing server cluster and could not
//  form a new server cluster. Cluster service has terminated.
//
#define SERVICE_FAILED_JOIN_OR_FORM      1009L

//
// MessageId: SERVICE_FAILED_NOT_MEMBER
//
// MessageText:
//
//  Cluster service is shutting down because the current node is not a
//  member of any server cluster. Cluster service must be reinstalled to make
//  this node a member of a server cluster.
//
#define SERVICE_FAILED_NOT_MEMBER        1010L

//
// MessageId: NM_NODE_EVICTED
//
// MessageText:
//
//  Cluster node %1 has been evicted from the server cluster.
//
#define NM_NODE_EVICTED                  1011L

//
// MessageId: SERVICE_FAILED_INVALID_OS
//
// MessageText:
//
//  Cluster service did not start because the current version of Windows
//  is not correct. Cluster service runs only on Windows Server 2003
//  Enterprise Edition and Windows Server 2003 Datacenter Edition.
//
#define SERVICE_FAILED_INVALID_OS        1012L

//
// MessageId: DM_CHKPOINT_UPLOADFAILED
//
// MessageText:
//
//  The quorum log checkpoint could not be restored to the server cluster database.
//  There may be open handles to the server cluster database that prevent this operation
//  from succeeding.
//
#define DM_CHKPOINT_UPLOADFAILED         1013L

//
// MessageId: CS_COMMAND_LINE_HELP
//
// MessageText:
//
//  To start Cluster service, in Control Panel, double-click Administrative Tools,
//  then double-click Services. Or, at the command prompt, type:
//  %nnet start clussvc.
//
#define CS_COMMAND_LINE_HELP             1014L

//
// MessageId: LM_LOG_CHKPOINT_NOT_FOUND
//
// MessageText:
//
//  No checkpoint record was found in the log file %1. The checkpoint file is
//  invalid or was deleted.
//
#define LM_LOG_CHKPOINT_NOT_FOUND        1015L

//
// MessageId: LM_CHKPOINT_GETFAILED
//
// MessageText:
//
//  Cluster service failed to obtain a checkpoint from the server cluster
//  database for log file %1.
//
#define LM_CHKPOINT_GETFAILED            1016L

//
// MessageId: LM_LOG_EXCEEDS_MAXSIZE
//
// MessageText:
//
//  The log file %1 exceeds its maximum size. An attempt will be made to reset
//  the log, or you should use the Cluster Administrator utility to adjust the maximum
//  size.
//
#define LM_LOG_EXCEEDS_MAXSIZE           1017L

//
// MessageId: LM_LOG_CORRUPT
//
// MessageText:
//
//  The log file %1 was found to be corrupt.  An attempt will be made to reset
//  it, or you should use the Cluster Administrator utility to adjust the maximum
//  size.
//
#define LM_LOG_CORRUPT                   1019L

//
// MessageId: LM_DISKSPACE_LOW_WATERMARK
//
// MessageText:
//
//  There is insufficient disk space remaining on the quorum device. Please
//  increase the amount of free space on the quorum device. Changes to the server cluster
//  registry will not be made if there is insufficient free space on the disk for
//  the quorum log files.
//
#define LM_DISKSPACE_LOW_WATERMARK       1021L

//
// MessageId: LM_DISKSPACE_HIGH_WATERMARK
//
// MessageText:
//
//  There is insufficient space left on the quorum device. Cluster
//  Service cannot start.
//
#define LM_DISKSPACE_HIGH_WATERMARK      1022L

//
// MessageId: FM_QUORUM_RESOURCE_NOT_FOUND
//
// MessageText:
//
//  The quorum resource was not found. Cluster service has
//  terminated.
//
#define FM_QUORUM_RESOURCE_NOT_FOUND     1023L

//
// MessageId: CP_REG_CKPT_RESTORE_FAILED
//
// MessageText:
//
//  The registry checkpoint for Cluster resource %1 could not be restored to
//  registry key HKEY_LOCAL_MACHINE\%2. The resource may not function correctly.
//  Make sure that no other processes have open handles to registry keys in this
//  registry subtree.
//
#define CP_REG_CKPT_RESTORE_FAILED       1024L

//
// MessageId: RES_FTSET_DISK_ERROR
//
// MessageText:
//
//  Cluster FT set DISK registry information is corrupt.
//
#define RES_FTSET_DISK_ERROR             1025L

//
// MessageId: RES_FTSET_MEMBER_MOUNT_FAILED
//
// MessageText:
//
//  Cluster FT set '%1' could not be mounted.
//
#define RES_FTSET_MEMBER_MOUNT_FAILED    1026L

//
// MessageId: RES_FTSET_MEMBER_MISSING
//
// MessageText:
//
//  Cluster FT set '%1' could not attach to the member with disk signature %2.
//
#define RES_FTSET_MEMBER_MISSING         1027L

//
// MessageId: RES_FTSET_TOO_MANY_MISSING_MEMBERS
//
// MessageText:
//
//  Cluster FT set '%1' has too many missing members to continue operation.
//
#define RES_FTSET_TOO_MANY_MISSING_MEMBERS 1028L

//
// MessageId: RES_FTSET_FILESYSTEM_FAILED
//
// MessageText:
//
//  Cluster FT set '%1' has failed a file system check.
//
#define RES_FTSET_FILESYSTEM_FAILED      1029L

//
// MessageId: RES_FTSET_ALL_MEMBERS_INACCESSIBLE
//
// MessageText:
//
//  No members of cluster FT set '%1' are responding to I/O requests.
//
#define RES_FTSET_ALL_MEMBERS_INACCESSIBLE 1030L

//
// MessageId: RES_FTSET_RESERVATION_LOST
//
// MessageText:
//
//  Reservation of cluster FT set '%1' has been lost.
//
#define RES_FTSET_RESERVATION_LOST       1031L

//
// MessageId: RES_FTSET_MEMBER_REMOVED
//
// MessageText:
//
//  Disk member %2 has been removed from cluster FT set '%1'.
//
#define RES_FTSET_MEMBER_REMOVED         1032L

//
// MessageId: RES_FTSET_MEMBER_ADDED
//
// MessageText:
//
//  Disk member %2 has been added to cluster FT set '%1'.
//
#define RES_FTSET_MEMBER_ADDED           1033L

//
// MessageId: RES_DISK_MISSING
//
// MessageText:
//
//  The disk associated with cluster disk resource '%1' could not be found.
//  The expected signature of the disk was %2. If the disk was removed from
//  the server cluster, the resource should be deleted. If the disk was replaced,
//  the resource must be deleted and created again in order to bring the disk
//  online. If the disk has not been removed or replaced, it may be inaccessible
//  at this time because it is reserved by another server cluster node.
//
#define RES_DISK_MISSING                 1034L

//
// MessageId: RES_DISK_MOUNT_FAILED
//
// MessageText:
//
//  Cluster disk resource '%1' could not be mounted.
//
#define RES_DISK_MOUNT_FAILED            1035L

//
// MessageId: RES_DISK_FAILED_SCSI_CHECK
//
// MessageText:
//
//  Cluster disk resource '%1' did not respond to a SCSI maintenance command.
//
#define RES_DISK_FAILED_SCSI_CHECK       1036L

//
// MessageId: RES_DISK_FILESYSTEM_FAILED
//
// MessageText:
//
//  Cluster disk resource '%1' has failed a file system check. Please check your
//  disk configuration.
//
#define RES_DISK_FILESYSTEM_FAILED       1037L

//
// MessageId: RES_DISK_RESERVATION_LOST
//
// MessageText:
//
//  Reservation of cluster disk '%1' has been lost. Please check your system and
//  disk configuration.
//
#define RES_DISK_RESERVATION_LOST        1038L

//
// MessageId: RES_GENAPP_CREATE_FAILED
//
// MessageText:
//
//  Cluster generic application '%1' could not be created.
//
#define RES_GENAPP_CREATE_FAILED         1039L

//
// MessageId: RES_GENSVC_OPEN_FAILED
//
// MessageText:
//
//  Cluster generic service '%1' could not be found.
//
#define RES_GENSVC_OPEN_FAILED           1040L

//
// MessageId: RES_GENSVC_START_FAILED
//
// MessageText:
//
//  Cluster generic service '%1' could not be started.
//
#define RES_GENSVC_START_FAILED          1041L

//
// MessageId: RES_GENSVC_FAILED_AFTER_START
//
// MessageText:
//
//  Cluster generic service '%1' failed.
//
#define RES_GENSVC_FAILED_AFTER_START    1042L

//
// MessageId: RES_IPADDR_NBT_INTERFACE_FAILED
//
// MessageText:
//
//  The NetBios interface for cluster IP Address resource '%1' has failed.
//
#define RES_IPADDR_NBT_INTERFACE_FAILED  1043L

//
// MessageId: RES_IPADDR_NBT_INTERFACE_CREATE_FAILED
//
// MessageText:
//
//  Cluster IP Address resource '%1' could not create the required NetBios
//  interface.
//
#define RES_IPADDR_NBT_INTERFACE_CREATE_FAILED 1044L

//
// MessageId: RES_IPADDR_NTE_CREATE_FAILED
//
// MessageText:
//
//  Cluster IP Address resource '%1' could not create the required TCP/IP
//  interface.
//
#define RES_IPADDR_NTE_CREATE_FAILED     1045L

//
// MessageId: RES_IPADDR_INVALID_SUBNET
//
// MessageText:
//
//  Cluster IP Address resource '%1' cannot be brought online because the
//  subnet mask parameter is invalid. Please check your network configuration.
//
#define RES_IPADDR_INVALID_SUBNET        1046L

//
// MessageId: RES_IPADDR_INVALID_ADDRESS
//
// MessageText:
//
//  Cluster IP Address resource '%1' cannot be brought online because the
//  Address parameter is invalid. Please check your network configuration.
//
#define RES_IPADDR_INVALID_ADDRESS       1047L

//
// MessageId: RES_IPADDR_INVALID_ADAPTER
//
// MessageText:
//
//  Cluster IP Address resource '%1' cannot be brought online because the
//  adapter name parameter is invalid. Please check your network configuration.
//
#define RES_IPADDR_INVALID_ADAPTER       1048L

//
// MessageId: RES_IPADDR_IN_USE
//
// MessageText:
//
//  Cluster IP Address resource '%1' cannot be brought online because address
//  %2 is already present on the network. Please check your network configuration.
//
#define RES_IPADDR_IN_USE                1049L

//
// MessageId: RES_NETNAME_DUPLICATE
//
// MessageText:
//
//  Cluster Network Name resource '%1' cannot be brought online because the name
//  %2 is already present on the network. Please check your network configuration.
//
#define RES_NETNAME_DUPLICATE            1050L

//
// MessageId: RES_NETNAME_NO_IP_ADDRESS
//
// MessageText:
//
//  Cluster Network Name resource '%1' cannot be brought online because it is
//  either configured to have no associated name service or it could not be
//  registered with NetBIOS and a DNS name server at this time. This prevents the
//  name from being brought online.%n
//  %nOne or more dependent IP address resource(s) must have either the
//  enableNetBIOS property enabled or its network adapter must have at least one
//  DNS server associated with it.
//
#define RES_NETNAME_NO_IP_ADDRESS        1051L

//
// MessageId: RES_NETNAME_CANT_ADD_NAME_STATUS
//
// MessageText:
//
//  Cluster Network Name resource '%1' cannot be brought online because the name
//  could not be added to the system. The associated error code is stored in the
//  data section.
//
#define RES_NETNAME_CANT_ADD_NAME_STATUS 1052L

//
// MessageId: RES_SMB_CANT_CREATE_SHARE
//
// MessageText:
//
//  Cluster File Share '%1' cannot be brought online because the share
//  could not be created.
//
#define RES_SMB_CANT_CREATE_SHARE        1053L

//
// MessageId: RES_SMB_SHARE_NOT_FOUND
//
// MessageText:
//
//  Cluster File Share '%1' could not be found.
//
#define RES_SMB_SHARE_NOT_FOUND          1054L

//
// MessageId: RES_SMB_SHARE_FAILED
//
// MessageText:
//
//  Cluster File Share resource '%1' has failed a status check. The error code
//  is %2.
//
#define RES_SMB_SHARE_FAILED             1055L

//
// MessageId: SERVICE_MUST_JOIN
//
// MessageText:
//
//  the server cluster database on the local node is in an invalid state.
//  Please start another node before starting this node.
//
#define SERVICE_MUST_JOIN                1056L

//
// MessageId: DM_DATABASE_CORRUPT_OR_MISSING
//
// MessageText:
//
//  the server cluster database could not be loaded. The file CLUSDB is either
//  corrupt or missing.
//
#define DM_DATABASE_CORRUPT_OR_MISSING   1057L

//
// MessageId: RMON_CANT_LOAD_RESTYPE
//
// MessageText:
//
//  The Cluster Resource Monitor could not load the DLL %1 for resource type %2.
//
#define RMON_CANT_LOAD_RESTYPE           1058L

//
// MessageId: RMON_CANT_INIT_RESTYPE
//
// MessageText:
//
//  Cluster resource DLL %1 for resource type %2 failed to initialize.
//
#define RMON_CANT_INIT_RESTYPE           1059L

//
// MessageId: RMON_RESTYPE_BAD_TABLE
//
// MessageText:
//
//  Cluster resource DLL %1 for resource type %2 returned an invalid function
//  table.
//
#define RMON_RESTYPE_BAD_TABLE           1060L

//
// MessageId: SERVICE_SUCCESSFUL_FORM
//
// MessageText:
//
//  Cluster service successfully formed the server cluster %1 on this node.
//
#define SERVICE_SUCCESSFUL_FORM          1061L

//
// MessageId: SERVICE_SUCCESSFUL_JOIN
//
// MessageText:
//
//  Cluster service successfully joined the server cluster %1.
//
#define SERVICE_SUCCESSFUL_JOIN          1062L

//
// MessageId: SERVICE_SUCCESSFUL_TERMINATION
//
// MessageText:
//
//  Cluster service was successfully stopped.
//
#define SERVICE_SUCCESSFUL_TERMINATION   1063L

//
// MessageId: DM_TOMBSTONECREATE_FAILED
//
// MessageText:
//
//  The quorum resource was changed. The old quorum resource could
//  not be marked as obsolete. If there is partition in time, you may
//  lose changes to your database since the node that is down will not
//  be able to get to the new quorum resource.
//
#define DM_TOMBSTONECREATE_FAILED        1064L

//
// MessageId: RMON_ONLINE_FAILED
//
// MessageText:
//
//  Cluster resource %1 failed to come online.
//
#define RMON_ONLINE_FAILED               1065L

//
// MessageId: RES_DISK_CORRUPT_DISK
//
// MessageText:
//
//  Cluster disk resource "%1" is corrupt. Run 'ChkDsk /F' to repair problems.
//  The volume name for this resource is "%2".%n
//  If available, ChkDsk output will be in the file "%3".%n
//  ChkDsk may write information to the Application Event Log with Event ID 26180.
//
#define RES_DISK_CORRUPT_DISK            1066L

//
// MessageId: RES_DISK_CORRUPT_FILE
//
// MessageText:
//
//  Cluster disk resource "%1" has corrupt files. Run ChkDsk /F to repair
//  problems.%n
//  The volume name for this resource is "%2".%n
//  If available, ChkDsk output will be in the file "%3".%n
//  ChkDsk may write information to the Application Event Log with Event ID 26180.
//
#define RES_DISK_CORRUPT_FILE            1067L

//
// MessageId: RES_SMB_SHARE_CANT_ADD
//
// MessageText:
//
//  Cluster file share resource %1 failed to start with error %2.
//
#define RES_SMB_SHARE_CANT_ADD           1068L

//
// MessageId: FM_RESOURCE_FAILURE
//
// MessageText:
//
//  Cluster resource '%1' in Resource Group '%2' failed.
//
#define FM_RESOURCE_FAILURE              1069L

//
// MessageId: NM_EVENT_BEGIN_JOIN_FAILED
//
// MessageText:
//
//  The node failed to begin the process of joining the server cluster.
//  The error code was %1.
//
#define NM_EVENT_BEGIN_JOIN_FAILED       1070L

//
// MessageId: NM_EVENT_JOIN_REFUSED
//
// MessageText:
//
//  Cluster node %1 attempted to join but was refused. The error code was %2.
//
#define NM_EVENT_JOIN_REFUSED            1071L

//
// MessageId: NM_INIT_FAILED
//
// MessageText:
//
//  Cluster service node initialization failed with error %1.
//
#define NM_INIT_FAILED                   1072L

//
// MessageId: CS_EVENT_INCONSISTENCY_HALT
//
// MessageText:
//
//  Cluster service was halted to prevent an inconsistency within the
//  server cluster. The error code was %1.
//
#define CS_EVENT_INCONSISTENCY_HALT      1073L

//
// MessageId: NM_EVENT_EVICTION_ERROR
//
// MessageText:
//
//  An unrecoverable error occurred on node %1 while attempting to evict node %2
//  from the server cluster. The error code was %3.
//
#define NM_EVENT_EVICTION_ERROR          1074L

//
// MessageId: NM_EVENT_SET_NETWORK_PRIORITY_FAILED
//
// MessageText:
//
//  Cluster service failed to set the priority for cluster network %1.
//  The error code was %2. Communication between server cluster nodes may not operate as
//  configured.
//
#define NM_EVENT_SET_NETWORK_PRIORITY_FAILED 1075L

//
// MessageId: NM_EVENT_REGISTER_NETINTERFACE_FAILED
//
// MessageText:
//
//  Cluster service failed to register the interface for node '%1'
//  on network '%2' with the server cluster network provider. The error code was %3.
//
#define NM_EVENT_REGISTER_NETINTERFACE_FAILED 1076L

//
// MessageId: RES_IPADDR_NTE_INTERFACE_FAILED
//
// MessageText:
//
//  The TCP/IP interface for Cluster IP Address '%1' has failed.
//
#define RES_IPADDR_NTE_INTERFACE_FAILED  1077L

//
// MessageId: RES_IPADDR_WINS_ADDRESS_FAILED
//
// MessageText:
//
//  Cluster IP Address '%1' failed to register WINS address on interface '%2'.
//
#define RES_IPADDR_WINS_ADDRESS_FAILED   1078L

//
// MessageId: NM_EVENT_NODE_UNREACHABLE
//
// MessageText:
//
//  The node cannot join the server cluster because it cannot communicate with
//  node %1 over any network configured for internal server cluster communication.
//  Check the network configuration of the node and the server cluster.
//
#define NM_EVENT_NODE_UNREACHABLE        1079L

//
// MessageId: CS_DISKWRITE_FAILURE
//
// MessageText:
//
//  Cluster service could not write to a file (%1). The disk may be low
//  on disk space, or some other serious condition exists.
//
#define CS_DISKWRITE_FAILURE             1080L

//
// MessageId: CP_SAVE_REGISTRY_FAILURE
//
// MessageText:
//
//  Cluster service failed to save the registry key %1 when a resource
//  was brought offline.  The error code was %2.  Some changes may be lost.
//
#define CP_SAVE_REGISTRY_FAILURE         1081L

//
// MessageId: CP_RESTORE_REGISTRY_FAILURE
//
// MessageText:
//
//  Cluster service failed to restore a registry key for resource %1 when it
//  was brought online. This error code was %2.  Some changes may be lost.
//
#define CP_RESTORE_REGISTRY_FAILURE      1082L

//
// MessageId: NM_EVENT_WSASTARTUP_FAILED
//
// MessageText:
//
//  Cluster service failed to initialize the Windows Sockets interface.
//  The error code was %1. Please check the network configuration and system
//  installation.
//
#define NM_EVENT_WSASTARTUP_FAILED       1083L

//
// MessageId: CS_EVENT_ALLOCATION_FAILURE
//
// MessageText:
//
//  Cluster service failed to allocate a necessary system resource.
//  The error code was %1.
//
#define CS_EVENT_ALLOCATION_FAILURE      1084L

//
// MessageId: NM_EVENT_GETCOMPUTERNAME_FAILED
//
// MessageText:
//
//  Cluster service failed to determine the local computer name.
//  The error code was %1.
//
#define NM_EVENT_GETCOMPUTERNAME_FAILED  1085L

//
// MessageId: NM_EVENT_CLUSNET_UNAVAILABLE
//
// MessageText:
//
//  Cluster service failed to access the Cluster Network driver.
//  The error code was %1. Please check Cluster service installation.
//
#define NM_EVENT_CLUSNET_UNAVAILABLE     1086L

//
// MessageId: NM_EVENT_CLUSNET_CALL_FAILED
//
// MessageText:
//
//  A required Cluster Network Driver operation failed. The error code was %1.
//
#define NM_EVENT_CLUSNET_CALL_FAILED     1087L

//
// MessageId: CS_EVENT_REG_OPEN_FAILED
//
// MessageText:
//
//  Cluster service failed to open a registry key. The key name was %1.
//  The error code was %2.
//
#define CS_EVENT_REG_OPEN_FAILED         1088L

//
// MessageId: CS_EVENT_REG_QUERY_FAILED
//
// MessageText:
//
//  Cluster service failed to query a registry value. The value name
//  was %1. The error code was %2.
//
#define CS_EVENT_REG_QUERY_FAILED        1089L

//
// MessageId: CS_EVENT_REG_OPERATION_FAILED
//
// MessageText:
//
//  Cluster service failed to perform an operation on the registry.
//  The error code was %1.
//
#define CS_EVENT_REG_OPERATION_FAILED    1090L

//
// MessageId: NM_EVENT_INVALID_CLUSNET_ENDPOINT
//
// MessageText:
//
//  The Cluster Network endpoint value, %1, specified in the registry is not
//  valid. The default value, %2, will be used.
//
#define NM_EVENT_INVALID_CLUSNET_ENDPOINT 1091L

//
// MessageId: NM_EVENT_MM_FORM_FAILED
//
// MessageText:
//
//  Cluster service failed to form the server cluster membership.
//  The error code was %1
//
#define NM_EVENT_MM_FORM_FAILED          1092L

//
// MessageId: NM_EVENT_NODE_NOT_MEMBER
//
// MessageText:
//
//  Node %1 is not a member of server cluster %2. If the name of
//  the node has changed, Cluster service must be reinstalled.
//
#define NM_EVENT_NODE_NOT_MEMBER         1093L

//
// MessageId: NM_EVENT_CONFIG_SYNCH_FAILED
//
// MessageText:
//
//  Cluster service failed to obtain information from the server cluster
//  configuration database. The error code was %1.
//
#define NM_EVENT_CONFIG_SYNCH_FAILED     1094L

//
// MessageId: CLNET_EVENT_QUERY_CONFIG_FAILED
//
// MessageText:
//
//  Cluster service failed to obtain information about the network
//  configuration of the node. The error code was %1. Check that the
//  TCP/IP services are installed.
//
#define CLNET_EVENT_QUERY_CONFIG_FAILED  1095L

//
// MessageId: CLNET_EVENT_INVALID_ADAPTER_ADDRESS
//
// MessageText:
//
//  Cluster service cannot use network adapter %1 because it does
//  not have a valid IP address assigned to it.
//
#define CLNET_EVENT_INVALID_ADAPTER_ADDRESS 1096L

//
// MessageId: CLNET_EVENT_NO_VALID_ADAPTER
//
// MessageText:
//
//  Cluster service did not find any network adapters with valid
//  IP addresses installed in the system. The node will not be able to join
//  a server cluster.
//
#define CLNET_EVENT_NO_VALID_ADAPTER     1097L

//
// MessageId: CLNET_EVENT_DELETE_INTERFACE
//
// MessageText:
//
//  The node is no longer attached to cluster network '%1' by adapter %2.
//  Cluster service will delete network interface '%3' from the
//  server cluster configuration.
//
#define CLNET_EVENT_DELETE_INTERFACE     1098L

//
// MessageId: CLNET_EVENT_DELETE_INTERFACE_FAILED
//
// MessageText:
//
//  Cluster service failed to delete an unused network interface
//  from the server cluster configuration. The error code was %1.
//
#define CLNET_EVENT_DELETE_INTERFACE_FAILED 1099L

//
// MessageId: CLNET_EVENT_CREATE_INTERFACE
//
// MessageText:
//
//  Cluster service discovered that the node is now
//  attached to cluster network '%1' by adapter %2. A new cluster network
//  interface will be added to the server cluster configuration.
//
#define CLNET_EVENT_CREATE_INTERFACE     1100L

//
// MessageId: CLNET_EVENT_CREATE_INTERFACE_FAILED
//
// MessageText:
//
//  Cluster service failed to add a network interface to the
//  server cluster configuration. The error code was %1.
//
#define CLNET_EVENT_CREATE_INTERFACE_FAILED 1101L

//
// MessageId: CLNET_EVENT_CREATE_NETWORK
//
// MessageText:
//
//  Cluster service discovered that the node is attached to a new
//  network by adapter %1. A new network and a network interface will be added
//  to the server cluster configuration.
//
#define CLNET_EVENT_CREATE_NETWORK       1102L

//
// MessageId: CLNET_EVENT_CREATE_NETWORK_FAILED
//
// MessageText:
//
//  Cluster service failed to add a network to the server cluster configuration.
//  The error code was %1.
//
#define CLNET_EVENT_CREATE_NETWORK_FAILED 1103L

//
// MessageId: CLNET_EVENT_UPDATE_INTERFACE_FAILED
//
// MessageText:
//
//  Cluster service failed to update the configuration for one of
//  the node's network interfaces. The error code was %1.
//
#define CLNET_EVENT_UPDATE_INTERFACE_FAILED 1104L

//
// MessageId: CS_EVENT_RPC_INIT_FAILED
//
// MessageText:
//
//  Cluster service failed to initialize the RPC services.
//  The error code was %1.
//
#define CS_EVENT_RPC_INIT_FAILED         1105L

//
// MessageId: NM_EVENT_JOIN_BIND_OUT_FAILED
//
// MessageText:
//
//  The node failed to make a connection to cluster node %1 over network '%2'.
//  The error code was %3.
//
#define NM_EVENT_JOIN_BIND_OUT_FAILED    1106L

//
// MessageId: NM_EVENT_JOIN_BIND_IN_FAILED
//
// MessageText:
//
//  Cluster node %1 failed to make a connection to the node over
//  network '%2'. The error code was %3.
//
#define NM_EVENT_JOIN_BIND_IN_FAILED     1107L

//
// MessageId: NM_EVENT_JOIN_TIMED_OUT
//
// MessageText:
//
//  The join of node %1 to the server cluster timed out and was aborted.
//
#define NM_EVENT_JOIN_TIMED_OUT          1108L

//
// MessageId: NM_EVENT_CREATE_SECURITY_CONTEXT_FAILED
//
// MessageText:
//
//  The node was unable to secure its connection to cluster node %1. The error
//  code was %2. Check that all nodes in the server cluster can communicate with their
//  domain controllers.
//
#define NM_EVENT_CREATE_SECURITY_CONTEXT_FAILED 1109L

//
// MessageId: NM_EVENT_PETITION_FAILED
//
// MessageText:
//
//  The node failed to join the active server cluster membership. The error code
//  was %1.
//
#define NM_EVENT_PETITION_FAILED         1110L

//
// MessageId: NM_EVENT_GENERAL_JOIN_ERROR
//
// MessageText:
//
//  An unrecoverable error occurred while the node was joining the server cluster.
//  The error code was %1.
//
#define NM_EVENT_GENERAL_JOIN_ERROR      1111L

//
// MessageId: NM_EVENT_JOIN_ABORTED
//
// MessageText:
//
//  The node's attempt to join the server cluster was aborted by the sponsor node.
//  Check the event log of an active server cluster node for more information.
//
#define NM_EVENT_JOIN_ABORTED            1112L

//
// MessageId: NM_EVENT_JOIN_ABANDONED
//
// MessageText:
//
//  The node's attempt to join the server cluster was abandoned after too many failures.
//
#define NM_EVENT_JOIN_ABANDONED          1113L

//
// MessageId: NM_EVENT_JOINER_BIND_FAILED
//
// MessageText:
//
//  The node failed to make a connection to joining node %1 over network %2.
//  The error code was %3.
//
#define NM_EVENT_JOINER_BIND_FAILED      1114L

//
// MessageId: NM_EVENT_SPONSOR_JOIN_ABORTED
//
// MessageText:
//
//  An unrecoverable error caused the join of node %1 to the server cluster
//  to be aborted. The error code was %2.
//
#define NM_EVENT_SPONSOR_JOIN_ABORTED    1115L

//
// MessageId: RES_NETNAME_NOT_REGISTERED
//
// MessageText:
//
//  Cluster Network Name '%1' could not be instantiated on its associated cluster
//  network. No DNS servers were available and all of the Network Name's dependent
//  IP Address resources do not have NetBIOS enabled.
//
#define RES_NETNAME_NOT_REGISTERED       1116L

//
// MessageId: RMON_OFFLINE_FAILED
//
// MessageText:
//
//  Cluster resource %1 failed to come offline.
//
#define RMON_OFFLINE_FAILED              1117L

//
// MessageId: CLNET_NODE_POISONED
//
// MessageText:
//
//  Cluster service was terminated as requested by Node %2.
//
#define CLNET_NODE_POISONED              1118L

//
// MessageId: RES_NETNAME_DNS_REGISTRATION_MISSING
//
// MessageText:
//
//  The registration of DNS name %2 for resource '%1' over
//  adapter '%4' failed for the following reason:%n
//  %n%3
//
#define RES_NETNAME_DNS_REGISTRATION_MISSING 1119L

//
// MessageId: RES_DISK_WRITING_TO_CLUSREG
//
// MessageText:
//
//  The DLL associated with cluster disk resource '%1' is attempting to change
//  the drive letter parameters from '%2' to '%3' in the server cluster database. If your
//  restore database operation failed, this could be caused by the replacement
//  of a quorum drive with a different partition layout from the original
//  quorum drive at the time the database backup was made. If this is the case
//  and you would like to use the new disk as the quorum drive, we suggest that
//  you stop the Cluster disk service, change the drive letter(s) of this drive to
//  '%2', start the Cluster disk service and retry the restore database procedure.
//
#define RES_DISK_WRITING_TO_CLUSREG      1120L

//
// MessageId: CP_CRYPTO_CKPT_RESTORE_FAILED
//
// MessageText:
//
//  The crypto checkpoint for cluster resource '%1' could not be restored to
//  the container name '%2'. The resource may not function correctly.
//
#define CP_CRYPTO_CKPT_RESTORE_FAILED    1121L

//
// MessageId: NM_EVENT_NETINTERFACE_UP
//
// MessageText:
//
//  The node (re)established communication with cluster node '%1' on network '%2'.
//
#define NM_EVENT_NETINTERFACE_UP         1122L

//
// MessageId: NM_EVENT_NETINTERFACE_UNREACHABLE
//
// MessageText:
//
//  The node lost communication with cluster node '%1' on network '%2'.
//
#define NM_EVENT_NETINTERFACE_UNREACHABLE 1123L

//
// MessageId: NM_EVENT_NETINTERFACE_FAILED
//
// MessageText:
//
//  The node determined that its interface to network '%1' failed.
//
#define NM_EVENT_NETINTERFACE_FAILED     1124L

//
// MessageId: NM_EVENT_CLUSTER_NETINTERFACE_UP
//
// MessageText:
//
//  The interface for cluster node '%1' on network '%2' is operational (up).
//  The node can communicate with all other available cluster nodes on the
//  network.
//
#define NM_EVENT_CLUSTER_NETINTERFACE_UP 1125L

//
// MessageId: NM_EVENT_CLUSTER_NETINTERFACE_UNREACHABLE
//
// MessageText:
//
//  The interface for cluster node '%1' on network '%2' is unreachable by
//  at least one other cluster node attached to the network. the server cluster was
//  not able to determine the location of the failure. Look for additional
//  entries in the system event log indicating which other nodes
//  have lost communication with node %1. If the condition persists, check
//  the cable connecting the node to the network. Next, check for hardware or
//  software errors in the node's network adapter. Finally, check for failures
//  in any other network components to which the node is connected such as
//  hubs, switches, or bridges.
//
#define NM_EVENT_CLUSTER_NETINTERFACE_UNREACHABLE 1126L

//
// MessageId: NM_EVENT_CLUSTER_NETINTERFACE_FAILED
//
// MessageText:
//
//  The interface for cluster node '%1' on network '%2' failed.
//  If the condition persists, check the cable connecting
//  the node to the network. Next, check for hardware or software errors in
//  node's network adapter. Finally, check for failures in any network
//  components to which the node is connected such as hubs, switches,
//  or bridges.
//
#define NM_EVENT_CLUSTER_NETINTERFACE_FAILED 1127L

//
// MessageId: NM_EVENT_CLUSTER_NETWORK_UP
//
// MessageText:
//
//  Cluster network '%1' is operational (up). All available server cluster nodes
//  attached to the network can communicate using it.
//
#define NM_EVENT_CLUSTER_NETWORK_UP      1128L

//
// MessageId: NM_EVENT_CLUSTER_NETWORK_PARTITIONED
//
// MessageText:
//
//  Cluster network '%1' is partitioned. Some attached server cluster nodes cannot
//  communicate with each other over the network. The server cluster was not able
//  to determine the location of the failure. Look for additional
//  entries in the system event log indicating which nodes have lost
//  communication. If the condition persists, check for failures in any network
//  components to which the nodes are connected such as hubs, switches, or
//  bridges. Also check for hardware or software errors in the adapters that
//  attach the nodes to the network.
//
#define NM_EVENT_CLUSTER_NETWORK_PARTITIONED 1129L

//
// MessageId: NM_EVENT_CLUSTER_NETWORK_DOWN
//
// MessageText:
//
//  Cluster network '%1' is down. None of the available nodes can communicate
//  using this network. If the condition persists, check for failures in any
//  network components to which the nodes are connected such as hubs, switches,
//  or bridges. Next, check the cables connecting the nodes to the network.
//  Finally, check for hardware or software errors in the adapters that attach
//  the nodes to the network.
//
#define NM_EVENT_CLUSTER_NETWORK_DOWN    1130L

//
// MessageId: NM_EVENT_NETINTERFACE_CREATED
//
// MessageText:
//
//  An interface was added for node %1 on network %2.
//
#define NM_EVENT_NETINTERFACE_CREATED    1131L

//
// MessageId: NM_EVENT_NETINTERFACE_DELETED
//
// MessageText:
//
//  The interface for node %1 on network %2 was removed.
//
#define NM_EVENT_NETINTERFACE_DELETED    1132L

//
// MessageId: NM_EVENT_NETWORK_CREATED
//
// MessageText:
//
//  New network %1 was added to the server cluster.
//
#define NM_EVENT_NETWORK_CREATED         1133L

//
// MessageId: NM_EVENT_NETWORK_DELETED
//
// MessageText:
//
//  Network %1 was removed from the server cluster.
//
#define NM_EVENT_NETWORK_DELETED         1134L

//
// MessageId: NM_EVENT_NODE_DOWN
//
// MessageText:
//
//  Cluster node %1 was removed from the active server cluster membership.
//  Cluster service may have been stopped on the node, the node may have
//  failed, or the node may have lost communication with the other active
//  server cluster nodes.
//
#define NM_EVENT_NODE_DOWN               1135L

//
// MessageId: NM_EVENT_NODE_BANISHED
//
// MessageText:
//
//  Cluster node %1 failed a critical operation. It will be removed from the
//  active server cluster membership. Check that the node is functioning
//  properly and that it can communicate with the other active server cluster nodes.
//
#define NM_EVENT_NODE_BANISHED           1136L

//
// MessageId: EVTLOG_DATA_DROPPED
//
// MessageText:
//
//  The EventLog replication queue %1 is full. %2 event(s) was(were) discarded
//  for a total size of %3.
//
#define EVTLOG_DATA_DROPPED              1137L

//
// MessageId: RES_SMB_CANT_CREATE_DFS_ROOT
//
// MessageText:
//
//  Cluster File Share '%1' could not be made a DFS root share because a DFS root
//  could not be created on this node. This could be due to a currently existing
//  DFS root on this node. If you want to make file share '%1' a DFS root share,
//  open the DFS Manager UI in the Administrative Tools folder in the Control
//  Panel, delete any existing DFS root, and then bring the file share '%1'
//  online.
//
#define RES_SMB_CANT_CREATE_DFS_ROOT     1138L

//
// MessageId: RES_DISK_PNP_CHANGING_QUORUM
//
// MessageText:
//
//  Physical Disk resource received a notification that
//  the drive letter on the quorum drive was changed from '%1:' to '%2:'.
//
#define RES_DISK_PNP_CHANGING_QUORUM     1139L

//
// MessageId: RES_NETNAME_DNS_CANNOT_STOP
//
// MessageText:
//
//  A DNS query or update operation started by the Network Name resource did not complete.
//  To avoid further problems, the Network Name resource has stopped the host
//  Resource Monitor process. If this condition recurs, move the resource
//  into a separate Resource Monitor  so it won't affect other resources.
//  Then, consult your network administrator to resolve the DNS problem.
//
#define RES_NETNAME_DNS_CANNOT_STOP      1140L

//
// MessageId: RES_SMB_CANT_INIT_DFS_SVC
//
// MessageText:
//
//  Cluster DFS Root '%1' could not initialize the DFS service on this node. This
//  is preventing the DFS Root resource from coming online. If the 'Distributed
//  File System' is not listed as one of the services that has started on this
//  node when you issue the command 'net start', then you may manually try to
//  start the DFS service by using the command 'net start dfs'. Once the DFS
//  service is running, try to bring the DFS root resource online.
//
#define RES_SMB_CANT_INIT_DFS_SVC        1141L

//
// MessageId: RES_SMB_CANT_ONLINE_DFS_ROOT
//
// MessageText:
//
//  Cluster DFS Root '%1' could not be brought online on this node. The error code is %2.
//
#define RES_SMB_CANT_ONLINE_DFS_ROOT     1142L

//
// MessageId: CS_STOPPING_SVC_ON_REMOTE_NODES
//
// MessageText:
//
//  Cluster service is attempting to stop the active Cluster services on all
//  other server cluster nodes as a part of the restore database operation. After the
//  restoration procedure is successful on this node, you have to manually restart
//  Cluster service on all other server cluster nodes.
//
#define CS_STOPPING_SVC_ON_REMOTE_NODES  1143L

//
// MessageId: NM_EVENT_REGISTER_NETWORK_FAILED
//
// MessageText:
//
//  Cluster service failed to register the network '%1'
//  with the Cluster network provider. The error code was %2.
//
#define NM_EVENT_REGISTER_NETWORK_FAILED 1144L

//
// MessageId: RMON_RESOURCE_TIMEOUT
//
// MessageText:
//
//  Cluster resource %1 timed out. If the pending timeout is too short for this
//  resource, consider increasing the pending timeout value.
//
#define RMON_RESOURCE_TIMEOUT            1145L

//
// MessageId: FM_EVENT_RESMON_DIED
//
// MessageText:
//
//  The cluster resource monitor died unexpectedly, an attempt will be made to restart it.
//
#define FM_EVENT_RESMON_DIED             1146L

//
// MessageId: LM_QUORUM_LOG_NOT_FOUND
//
// MessageText:
//
//  Cluster service encountered a fatal error. The vital quorum log
//  file '%1' could not be found. If you have a backup of the quorum log file, you
//  may try to start Cluster service with logging disabled by entering%n
//  %nnet start clussvc /noquorumlogging%n
//  %nat a command window, copy the backed up quorum log file to the MSCS directory
//  on the quorum drive, stop Cluster service using 'net stop clussvc', and restart 
//  Cluster service with logging re-enabled using the 'net start clussvc' command. 
//  If you do not have a backup of the quorum log file, you may try to start 
//  Cluster service by entering%n
//  %nnet start clussvc /resetquorumlog%n
//  %nat a command window. This will attempt to create a new quorum log file based on 
//  possibly stale information in the server cluster database. You may then stop 
//  Cluster service and restart it with logging re-enabled using the 'net start clussvc' 
//  command.
//
#define LM_QUORUM_LOG_NOT_FOUND          1147L

//
// MessageId: LM_QUORUM_LOG_CORRUPT
//
// MessageText:
//
//  Cluster service encountered a fatal error. The vital quorum log
//  file '%1' is corrupt. If you have a backup of the quorum log file,
//  you may try to start Cluster service with logging disabled by entering%n
//  %nnet start clussvc /noquorumlogging%n
//  %nat a command window, copy the backed up quorum log file to the MSCS directory
//  on the quorum drive, stop Cluster service using 'net stop clussvc', and restart 
//  Cluster service with logging re-enabled using the 'net start clussvc' command. 
//  If you do not have a backup of the quorum log file, you may try to start Cluster 
//  service by entering%n
//  %nnet start clussvc /resetquorumlog%n
//  %nat a command window. This will attempt to create a new quorum log file based on 
//  possibly stale information in the server cluster database. You may then stop 
//  Cluster service and restart it with logging re-enabled using the 'net start clussvc' 
//  command.
//
#define LM_QUORUM_LOG_CORRUPT            1148L

//
// MessageId: RES_NETNAME_CANT_DELETE_DNS_RECORDS
//
// MessageText:
//
//  The DNS Host (A) and Pointer (PTR) records associated with Cluster resource
//  '%1' were not removed from the resource's associated DNS server. If necessary,
//  they can be deleted manually. Contact your DNS administrator to assist with
//  this effort.
//
#define RES_NETNAME_CANT_DELETE_DNS_RECORDS 1149L

//
// MessageId: RES_NETNAME_DNS_PTR_RECORD_DELETE_FAILED
//
// MessageText:
//
//  The removal of the DNS Pointer (PTR) record (%2) for host %3 which is
//  associated with Cluster Network Name resource '%1' failed with error %4.  If
//  necessary, the record can be deleted manually. Contact your DNS administrator
//  to assist you in this effort.
//
#define RES_NETNAME_DNS_PTR_RECORD_DELETE_FAILED 1150L

//
// MessageId: RES_NETNAME_DNS_A_RECORD_DELETE_FAILED
//
// MessageText:
//
//  The removal of the DNS Host (A) record (%2) associated with Cluster Network
//  Name resource '%1' failed with error %3.  If necessary, the record can be
//  deleted manually. Contact your DNS administrator to assist with this effort.
//
#define RES_NETNAME_DNS_A_RECORD_DELETE_FAILED 1151L

//
// MessageId: RES_NETNAME_DNS_SINGLE_A_RECORD_DELETE_FAILED
//
// MessageText:
//
//  The removal of the DNS Host (A) record (host: %2, IP address: %3)
//  associated with Cluster Network Name resource '%1' failed with error %4.  If
//  necessary, the record can be deleted manually. Contact your DNS administrator
//  to assist with this effort.
//
#define RES_NETNAME_DNS_SINGLE_A_RECORD_DELETE_FAILED 1152L

//
// MessageId: FM_EVENT_GROUP_FAILOVER
//
// MessageText:
//
//  Cluster service is attempting to failover the Cluster Resource Group '%1' from node %2 to node %3.
//
#define FM_EVENT_GROUP_FAILOVER          1153L

//
// MessageId: FM_EVENT_GROUP_FAILBACK
//
// MessageText:
//
//  Cluster service is attempting to failback the Cluster Resource Group '%1' from node %2 to node %3.
//
#define FM_EVENT_GROUP_FAILBACK          1154L

//
// MessageId: NM_EVENT_CLUSNET_ENABLE_SHUTDOWN_FAILED
//
// MessageText:
//
//  Cluster service failed to enable automatic shutdown of the Cluster Network
//  Driver. The error code was %1.
//
#define NM_EVENT_CLUSNET_ENABLE_SHUTDOWN_FAILED 1155L

//
// MessageId: NM_EVENT_CLUSNET_INITIALIZE_FAILED
//
// MessageText:
//
//  Initialization of the Cluster Network Driver failed. The error code was %1.
//
#define NM_EVENT_CLUSNET_INITIALIZE_FAILED 1156L

//
// MessageId: NM_EVENT_CLUSNET_RESERVE_ENDPOINT_FAILED
//
// MessageText:
//
//  Reservation of Cluster Control Message Protocol port %1 failed.
//  The error code was %2.
//
#define NM_EVENT_CLUSNET_RESERVE_ENDPOINT_FAILED 1157L

//
// MessageId: NM_EVENT_CLUSNET_ONLINE_COMM_FAILED
//
// MessageText:
//
//  The Cluster Network Driver failed to enable communication for cluster
//  node %1. The error code was %2.
//
#define NM_EVENT_CLUSNET_ONLINE_COMM_FAILED 1158L

//
// MessageId: NM_EVENT_CLUSNET_SET_INTERFACE_PRIO_FAILED
//
// MessageText:
//
//  Cluster service failed to set network interface priorities for node %1.
//  The error code was %2.
//
#define NM_EVENT_CLUSNET_SET_INTERFACE_PRIO_FAILED 1159L

//
// MessageId: NM_EVENT_CLUSNET_REGISTER_NODE_FAILED
//
// MessageText:
//
//  Registration of cluster node %1 with the Cluster Network Driver failed.
//  The error code was %2.
//
#define NM_EVENT_CLUSNET_REGISTER_NODE_FAILED 1160L

//
// MessageId: RES_DISK_INVALID_MP_SIG_UNAVAILABLE
//
// MessageText:
//
//  Cluster disk resource "%1":%n
//  Mount point "%2" for clustered target volume "%3" cannot be verified as
//  acceptable because the target volume signature was unavailable.
//
#define RES_DISK_INVALID_MP_SIG_UNAVAILABLE 1161L

//
// MessageId: RES_DISK_INVALID_MP_SOURCE_EQUAL_TARGET
//
// MessageText:
//
//  Cluster disk resource "%1":%n
//  Mount point "%2" for clustered target volume "%3" is not acceptable
//  as the source and target are the same device.
//
#define RES_DISK_INVALID_MP_SOURCE_EQUAL_TARGET 1162L

//
// MessageId: RES_DISK_INVALID_MP_SIG_ENUMERATION_FAILED
//
// MessageText:
//
//  Cluster disk resource "%1":%n
//  Mount point "%2" for clustered target volume "%3" cannot be verified as
//  acceptable because the cluster disk signature enumeration failed.
//
#define RES_DISK_INVALID_MP_SIG_ENUMERATION_FAILED 1163L

//
// MessageId: RES_DISK_INVALID_MP_QUORUM_SIG_UNAVAILABLE
//
// MessageText:
//
//  Cluster disk resource "%1":%n
//  Mount point "%2" for clustered target volume "%3" cannot be verified as
//  acceptable because the quorum disk signature was unavailable.
//
#define RES_DISK_INVALID_MP_QUORUM_SIG_UNAVAILABLE 1164L

//
// MessageId: RES_DISK_INVALID_MP_TARGET_IS_QUORUM
//
// MessageText:
//
//  Cluster disk resource "%1":%n
//  Mount point "%2" for clustered target volume "%3" is not acceptable
//  because the target volume is the quorum disk.  The quorum disk
//  cannot be dependent on another disk resource.
//
#define RES_DISK_INVALID_MP_TARGET_IS_QUORUM 1165L

//
// MessageId: RES_DISK_INVALID_MP_ENUM_DISK_DEP_FAILED
//
// MessageText:
//
//  Cluster disk resource "%1":%n
//  Mount point "%2" for clustered target volume "%3" cannot be verified as
//  acceptable because the cluster disk dependency enumeration failed.
//
#define RES_DISK_INVALID_MP_ENUM_DISK_DEP_FAILED 1166L

//
// MessageId: RES_DISK_INVALID_MP_INVALID_DEPENDENCIES
//
// MessageText:
//
//  Cluster disk resource "%1":%n
//  Mount point "%2" for clustered target volume "%3" is not acceptable
//  because the cluster dependencies are not correctly set between the
//  source and the target volume.%n
//  %nThe target volume must be dependent on the source volume. Insure that
//  the disk dependencies are set correctly.
//
#define RES_DISK_INVALID_MP_INVALID_DEPENDENCIES 1167L

//
// MessageId: SERVICE_CLUSRTL_BAD_PATH
//
// MessageText:
//
//  Cluster service failed to initialize due to an invalid file specification in
//  the CLUSTERLOG environment variable. Please check that the specified drive
//  letter exists and that the drive is not read-only.
//
#define SERVICE_CLUSRTL_BAD_PATH         1168L

//
// MessageId: SERVICE_CLUSRTL_ERROR
//
// MessageText:
//
//  Cluster service failed to initialize due to the following error:%n
//  %n%1
//
#define SERVICE_CLUSRTL_ERROR            1169L

//
// MessageId: RES_DISK_FULL_DISK_QUORUM
//
// MessageText:
//
//  Cluster disk resource "%1" [quorum] is full or nearly at capacity.
//  The cluster service will attempt to start, but may fail because of the
//  lack of disk space. If Cluster service fails after this message is
//  posted, restart Cluster service (with logging disabled) by starting
//  a command window, and typing%n
//  %nnet start clussvc /noquorumlogging%n
//  %nMove some of the unnecessary files from the quorum disk to another volume
//  after Cluster service is started.%n
//  Do not move files required by Cluster service!%n
//  Once additional space has been made available on the quorum disk, use
//  'net stop clussvc' to stop Cluster service, then run 'net start clussvc' to
//  restart Cluster service with logging re-enabled.%n
//  The volume name for this resource is "%2".
//
#define RES_DISK_FULL_DISK_QUORUM        1170L

//
// MessageId: RES_DISK_FULL_DISK_NOT_QUORUM
//
// MessageText:
//
//  Cluster disk resource "%1" is full or nearly at capacity. Move some of the
//  unnecessary files from this disk to another volume after Cluster service
//  is started.%n
//  The volume name for this resource is "%2".
//
#define RES_DISK_FULL_DISK_NOT_QUORUM    1171L

//
// MessageId: RES_DISK_FULL_DISK_UNKNOWN
//
// MessageText:
//
//  Cluster disk resource "%1" [unknown] is full or nearly at capacity.
//  Cluster service will attempt to start, but may fail because of the lack of disk
//  space. If Cluster service fails after this message is posted, restart
//  Cluster service (with logging disabled) by starting a command window and typing%n
//  %nnet start clussvc /noquorumlogging%n
//  %nIf this is the quorum disk, move some of the unnecessary files from the
//  quorum disk to another volume after Cluster service is started. If this
//  disk is not the quorum disk, move some files to another volume.
//  Do not move files required by Cluster service!%n
//  Once additional space has been made available on the quorum disk, use
//  'net stop clussvc' to stop Cluster service, then run 'net start clussvc' to
//  restart Cluster service with logging re-enabled.%n
//  The volume name for this resource is "%2".
//
#define RES_DISK_FULL_DISK_UNKNOWN       1172L

//
// MessageId: MM_EVENT_RELOAD_FAILED
//
// MessageText:
//
//  Cluster service is shutting down because the membership engine detected a
//  membership event while trying to join the server cluster. Shutting down is the
//  normal response to this type of event. Cluster service will restart per the
//  Service Manager's recovery actions.
//
#define MM_EVENT_RELOAD_FAILED           1173L

//
// MessageId: MM_EVENT_INTERNAL_ERROR
//
// MessageText:
//
//  Cluster service is shutting down because the membership engine suffered an
//  internal error. Cluster service will restart per the Service Manager's
//  recovery actions.
//
#define MM_EVENT_INTERNAL_ERROR          1174L

//
// MessageId: MM_EVENT_PRUNED_OUT
//
// MessageText:
//
//  Cluster service is shutting down because the membership engine detected the
//  loss of connectivity to all other nodes in the cluster. This could be due to a
//  network interface failure on this node. Check the system event log for any
//  network related failures around the time of this event. Also check your
//  physical network infrastructure to ensure that communication
//  between this node and all other nodes in the server cluster is intact. Cluster
//  service will restart per the Service Manager's recovery actions but may not
//  join the server cluster until any network problems has been resolved.
//
#define MM_EVENT_PRUNED_OUT              1175L

//
// MessageId: MM_EVENT_PARIAH
//
// MessageText:
//
//  Cluster service is shutting down as requested by node %1 (%2). Check the system
//  event log on node %1 to determine the reason for the shutdown request. Cluster
//  service will restart per the Service Manager's recovery actions.
//
#define MM_EVENT_PARIAH                  1176L

//
// MessageId: MM_EVENT_ARBITRATION_FAILED
//
// MessageText:
//
//  Cluster service is shutting down because the membership engine failed to
//  arbitrate for the quorum device. This could be due to the loss of network
//  connectivity with the current quorum owner.  Check your physical network
//  infrastructure to ensure that communication between this node and
//  all other nodes in the server cluster is intact.
//
#define MM_EVENT_ARBITRATION_FAILED      1177L

//
// MessageId: MM_EVENT_ARBITRATION_STALLED
//
// MessageText:
//
//  Cluster service is shutting down because the membership engine detected that
//  the arbitration process for the quorum device has stalled. This could be due
//  to problems with your disk hardware and/or the associated drivers.  Check the
//  system event log for any disk related errors.
//
#define MM_EVENT_ARBITRATION_STALLED     1178L

//
// MessageId: MM_EVENT_SHUTDOWN_DURING_RGP
//
// MessageText:
//
//  Cluster service received a membership event while shutting down. Cluster
//  service is shutting down immediately to facilitate server cluster membership
//  for the remaining nodes. This is the normal response to this type of event.
//
#define MM_EVENT_SHUTDOWN_DURING_RGP     1179L

//
// MessageId: NM_EVENT_FORM_WITH_NO_NETWORKS
//
// MessageText:
//
//  While forming a server cluster on this node, Cluster service failed to
//  detect a viable network enabled for cluster use. Other nodes will not be
//  able to join this cluster unless network communication can be established.
//
#define NM_EVENT_FORM_WITH_NO_NETWORKS   1180L

//
// MessageId: NETRES_RESOURCE_START_ERROR
//
// MessageText:
//
//  Cluster %1 resource failed while starting service.
//
#define NETRES_RESOURCE_START_ERROR      1181L

//
// MessageId: NETRES_RESOURCE_STOP_ERROR
//
// MessageText:
//
//  Cluster %1 resource failed while stopping service.
//
#define NETRES_RESOURCE_STOP_ERROR       1182L

//
// MessageId: RES_DISK_INVALID_MP_SOURCE_NOT_CLUSTERED
//
// MessageText:
//
//  Cluster disk resource "%1":%n
//  Mount point "%2" for clustered target volume "%3" is not acceptable
//  because the source volume is not a clustered disk. Both the source
//  and target must be clustered disks.  When the target disk is moved
//  to another node, the mountpoint will become invalid. Also, this
//  mountpoint is available only on the current node.
//
#define RES_DISK_INVALID_MP_SOURCE_NOT_CLUSTERED 1183L

//
// MessageId: RES_DISK_MP_VOLGUID_LIST_EXCESSIVE
//
// MessageText:
//
//  Cluster disk resource "%1":%n
//  The VolGuid list maintained for this disk resource appears to have
//  too many entries. If all the VolGuid entries are valid, than this
//  message can safely be ignored. If the VolGuid list should be
//  recreated, you can do this by setting this disk resource's Parameter
//  key "UseMountPoints=0" and taking the disk offline and online again.
//  For the quorum resource, set "UseMountPoints=0" and then move the
//  quorum disk from one node to another. Note that when mountpoints are
//  disabled ("UseMountPoints=0"), mountpoints on the clustered disks
//  will not work correctly until they are re-enabled ("UseMountPoints=1").
//  
//
#define RES_DISK_MP_VOLGUID_LIST_EXCESSIVE 1184L

//
// MessageId: RES_NETNAME_CANT_DELETE_DEPENDENT_RESOURCE_DNS_RECORDS
//
// MessageText:
//
//  The DNS Host (A) and Pointer (PTR) records for Cluster Network Name resource
//  '%1' and %2 were not removed from the resource's associated DNS server. If
//  necessary, they can be deleted manually. Contact your DNS administrator to
//  assist with this effort.
//
#define RES_NETNAME_CANT_DELETE_DEPENDENT_RESOURCE_DNS_RECORDS 1185L

//
// MessageId: SERVICE_PASSWORD_CHANGE_INITIATED
//
// MessageText:
//
//  The password associated with the Cluster service domain account is being
//  updated on this node.
//
#define SERVICE_PASSWORD_CHANGE_INITIATED 1186L

//
// MessageId: SERVICE_PASSWORD_CHANGE_SUCCESS
//
// MessageText:
//
//  The password associated with the Cluster service domain account was
//  successfully updated on this node.
//
#define SERVICE_PASSWORD_CHANGE_SUCCESS  1187L

//
// MessageId: SERVICE_PASSWORD_CHANGE_FAILED
//
// MessageText:
//
//  The update of the Cluster service domain account password failed on this node.
//  Cluster service on this node will be stopped. If Cluster service cannot be 
//  started due to a logon failure, reset Cluster service's domain account password 
//  through the Services snap-in in the Microsoft Management Console.
//
#define SERVICE_PASSWORD_CHANGE_FAILED   1188L

//
// MessageId: SERVICE_CLUSTER_DATABASE_RESTORE_SUCCESSFUL
//
// MessageText:
//
//  Cluster service has successfully restored the cluster database to the quorum disk.
//  Please verify that the restored configuration of the cluster is as expected. You
//  may use the Cluster Administrator tool to verify the restored configuration.
//  After that, you can start the Cluster service on the remaining cluster nodes by entering
//  'net start clussvc' at a command window on those nodes. This will result in
//  these nodes synchronizing the restored database from this initially restored node.
//
#define SERVICE_CLUSTER_DATABASE_RESTORE_SUCCESSFUL 1189L

//
// MessageId: RES_NETNAME_COMPUTER_ACCOUNT_DELETED
//
// MessageText:
//
//  The computer account for Cluster resource '%1' in domain %2 was deleted.
//
#define RES_NETNAME_COMPUTER_ACCOUNT_DELETED 1190L

//
// MessageId: RES_NETNAME_DELETE_COMPUTER_ACCOUNT_FAILED_STATUS
//
// MessageText:
//
//  The computer account for Cluster resource '%1' in domain %2 could not be
//  deleted. The associated error code is stored in the data section. The domain
//  administrator will need to remove this account manually.%n
//  %nThe presence of a computer account for this name will cause authentication
//  using the Negotiate and Kerberos security packages to fail.
//
#define RES_NETNAME_DELETE_COMPUTER_ACCOUNT_FAILED_STATUS 1191L

//
// MessageId: RES_NETNAME_DELETE_COMPUTER_ACCOUNT_FAILED
//
// MessageText:
//
//  The computer account for Cluster resource '%1' in domain %2 could not be
//  deleted for the following reason:%n
//  %n%3%n
//  %nThe domain administrator will need to remove this account manually.
//  %nThe presence of a computer account for this name will cause authentication
//  using the Negotiate and Kerberos security packages to fail.
//
#define RES_NETNAME_DELETE_COMPUTER_ACCOUNT_FAILED 1192L

//
// MessageId: RES_NETNAME_ADD_COMPUTER_ACCOUNT_FAILED_STATUS
//
// MessageText:
//
//  The computer account for Cluster resource '%1' in domain %2 could not be
//  created for the following reason:%n
//  %n%3.%n
//  %nThe associated error code is stored in the data section.%n
//  %nThe Cluster Service Account may lack the proper access rights to Active
//  Directory. The domain administrator should be contacted to assist with
//  resolving this issue.
//
#define RES_NETNAME_ADD_COMPUTER_ACCOUNT_FAILED_STATUS 1193L

//
// MessageId: RES_NETNAME_ADD_COMPUTER_ACCOUNT_FAILED
//
// MessageText:
//
//  The computer account for Cluster resource '%1' in domain %2 could not be
//  created for the following reason: %3.%n
//  %nThe text for the associated error code is: %4%n
//  %nThe Cluster Service Account may lack the proper access rights to Active
//  Directory. The domain administrator should be contacted to assist with
//  resolving this issue.
//
#define RES_NETNAME_ADD_COMPUTER_ACCOUNT_FAILED 1194L

//
// MessageId: RES_NETNAME_DNS_REGISTRATION_FAILED_STATUS
//
// MessageText:
//
//  The required registration of the DNS name(s) associated with Cluster resource
//  '%1' failed. The associated error code is stored in the data section.
//
#define RES_NETNAME_DNS_REGISTRATION_FAILED_STATUS 1195L

//
// MessageId: RES_NETNAME_DNS_REGISTRATION_FAILED
//
// MessageText:
//
//  The required registration of the DNS name(s) associated with Cluster resource
//  '%1' failed for the following reason:%n
//  %n%2%n
//  %nPlease check with your network adminstrator for the best recovery action.
//
#define RES_NETNAME_DNS_REGISTRATION_FAILED 1196L

//
// MessageId: NM_EVENT_MULTICAST_ADDRESS_CHOICE
//
// MessageText:
//
//  Cluster node %1 selected multicast address %2 for network %3 after failing
//  to contact a MADCAP server.
//
#define NM_EVENT_MULTICAST_ADDRESS_CHOICE 1197L

//
// MessageId: NM_EVENT_OBTAINED_MULTICAST_LEASE
//
// MessageText:
//
//  Cluster node %1 obtained a lease on a new multicast address (%2) for
//  network %3 from MADCAP server %4.
//
#define NM_EVENT_OBTAINED_MULTICAST_LEASE 1198L

//
// MessageId: NM_EVENT_MULTICAST_ADDRESS_FAILURE
//
// MessageText:
//
//  Cluster node %1 was not able to obtain a multicast address from
//  a MADCAP server for network %2 or to select one automatically. The
//  error code was %3. Cluster operations will not be affected, although
//  cluster nodes will not exchange multicast messages on this network.
//
#define NM_EVENT_MULTICAST_ADDRESS_FAILURE 1199L

//
// MessageId: FM_EVENT_GROUP_START_ONLINE
//
// MessageText:
//
//  The Cluster Service is attempting to bring online the Resource Group "%1".
//
#define FM_EVENT_GROUP_START_ONLINE      1200L

//
// MessageId: FM_EVENT_GROUP_COMPLETE_ONLINE
//
// MessageText:
//
//  The Cluster Service brought the Resource Group "%1" online.
//
#define FM_EVENT_GROUP_COMPLETE_ONLINE   1201L

 // If you change the following MessageId, then you must also update this value
 // in nt\public\internal\base\inc\clussprt.h
//
// MessageId: EVT_EVENT_TIME_DELTA_INFORMATION
//
// MessageText:
//
//  The time delta between node %1 and node %2 is %3(in 100 nanosecs). 
//
#define EVT_EVENT_TIME_DELTA_INFORMATION 1202L

//
// MessageId: FM_EVENT_GROUP_START_OFFLINE
//
// MessageText:
//
//  The Cluster Service is attempting to offline the Resource Group "%1".
//
#define FM_EVENT_GROUP_START_OFFLINE     1203L

//
// MessageId: FM_EVENT_GROUP_COMPLETE_OFFLINE
//
// MessageText:
//
//  The Cluster Service brought the Resource Group "%1" offline.
//
#define FM_EVENT_GROUP_COMPLETE_OFFLINE  1204L

//
// MessageId: FM_EVENT_GROUP_FAILED_ONLINE_OFFLINE
//
// MessageText:
//
//  The Cluster Service failed to bring the Resource Group "%1" completely online or offline.
//
#define FM_EVENT_GROUP_FAILED_ONLINE_OFFLINE 1205L

//
// MessageId: RES_NETNAME_UPDATE_COMPUTER_ACCOUNT_FAILED_STATUS
//
// MessageText:
//
//  The computer account for Cluster resource '%1' in domain %2 could not be
//  configured for the following reason:%n
//  %n%3.%n
//  %nThe associated error code is stored in the data section.%n
//  %nThe Cluster Service Account may lack the proper access rights to Active
//  Directory. The domain administrator should be contacted to assist with
//  resolving this issue.
//
#define RES_NETNAME_UPDATE_COMPUTER_ACCOUNT_FAILED_STATUS 1206L

//
// MessageId: RES_NETNAME_UPDATE_COMPUTER_ACCOUNT_FAILED
//
// MessageText:
//
//  The computer account for Cluster resource '%1' in domain %2 could not be
//  configured for the following reason:%n
//  %n%3%n
//  %nThe text for the associated error code is: %4%n
//  %nThe Cluster Service Account may lack the proper access rights to Active
//  Directory. The domain administrator should be contacted to assist with
//  resolving this issue.
//
#define RES_NETNAME_UPDATE_COMPUTER_ACCOUNT_FAILED 1207L

//
// MessageId: RES_DISK_INVALID_MP_TARGET_NOT_CLUSTERED
//
// MessageText:
//
//  Cluster disk resource "%1":%n
//  Mount point "%2" for target volume "%3" is not acceptable
//  because the target volume is not a clustered disk. Both the source
//  and target must be clustered disks.  When the source disk is moved
//  to another node, the mountpoint will become invalid. Also, this
//  mountpoint is available only on the current node.
//
#define RES_DISK_INVALID_MP_TARGET_NOT_CLUSTERED 1208L

//
// MessageId: CLUSDISK_RESET_BUS_REQUESTED
//
// MessageText:
//
//  Cluster service is requesting a bus reset for device %1.
//
#define CLUSDISK_RESET_BUS_REQUESTED     1209L

//
// MessageId: RES_NETNAME_COMPOBJ_IN_DS
//
// MessageText:
//
//  Cluster resource '%1' failed to go online because its associated computer
//  account (%2) exists in Active Directory and the Kerberos authentication is not
//  enabled for the resource. Client applications that are using Kerberos based
//  authentication (either directly or through the Negotiate security package)
//  will fail to authenticate when contacting a service by this network name.%n
//  %nTo bring the resource online, either enable Kerberos authentication or
//  delete the computer account.
//
#define RES_NETNAME_COMPOBJ_IN_DS        1210L

//
// MessageId: RES_NETNAME_NO_WRITEABLE_DC_STATUS
//
// MessageText:
//
//  The computer account for Cluster resource '%1' could not be created in
//  the cluster's domain because a domain controller running Active Directory
//  could not be located. The associated error code is stored in the data section.%n
//  %nCheck this node's connectivity to a domain controller running Active
//  Directory.
//
#define RES_NETNAME_NO_WRITEABLE_DC_STATUS 1211L

//
// MessageId: RES_NETNAME_NO_WRITEABLE_DC
//
// MessageText:
//
//  The computer account for Cluster resource '%1' could not be created in
//  the cluster's domain because a domain controller running Active Directory
//  could not be located for the following reason:%n
//  %n%2
//  %nCheck this node's connectivity to a domain controller running Active
//  Directory.
//
#define RES_NETNAME_NO_WRITEABLE_DC      1212L

//
// MessageId: RES_NETNAME_RENAME_RESTORE_FAILED
//
// MessageText:
//
//  The computer account in Active Directory (%2) for Cluster resource '%1' could
//  not be renamed back to its original name (%3) and is now different from the
//  network name. The associated error code is stored in the data section.%n
//  %nIf the computer account name is not changed back to the orignal name, an
//  attempt to create a new computer account will be made the next time this
//  resource is brought online. This may cause improper operation or the failure
//  of resources that are dependent on this resource due to the loss of
//  configuration information stored with the associated computer account.%n
//  %nTo recover, either set the resource back to its original network name or
//  edit the name of the computer account using the ADSI editor MMC snapin.
//
#define RES_NETNAME_RENAME_RESTORE_FAILED 1213L

//
// MessageId: RES_NETNAME_CANT_ADD_NAME2
//
// MessageText:
//
//  Cluster Network Name resource '%1' cannot be brought online because the name
//  could not be added to the system for the following reason: %2.
//
#define RES_NETNAME_CANT_ADD_NAME2       1214L

//
// MessageId: RES_NETNAME_NOT_REGISTERED_WITH_RDR
//
// MessageText:
//
//  Cluster Network Name %2 is no longer registered with its hosting system. The
//  associated resource name is '%1'.
//
#define RES_NETNAME_NOT_REGISTERED_WITH_RDR 1215L

//
// MessageId: SERVICE_NETNAME_CHANGE_WARNING
//
// MessageText:
//
//  Cluster Network Name was changed even though the core Cluster Network Name resource 
//  could not perform all the related changes.  If you have problems bringing the Cluster 
//  Network Name resource online, please check the eventlog for troubleshooting.
//
#define SERVICE_NETNAME_CHANGE_WARNING   1216L

//
// MessageId: RES_NETNAME_RENAME
//
// MessageText:
//
//  The Network Name for resource '%1' was changed from %2 to %3.
//
#define RES_NETNAME_RENAME               1217L

//
// MessageId: RES_NETNAME_ONLINE_RENAME_RECOVERY_MISSING_ACCOUNT
//
// MessageText:
//
//  The computer account in Active Directory for Cluster resource '%1' could not
//  be found during rename recovery on the Domain Controller where it was created
//  (%2).%n
//  %nThe original name (%3) was being renamed to %4 and neither computer account
//  could be found. The resource cannot go online until the computer account is
//  recreated. This can be accomplished by disabling and re-enabling Kerberos
//  Authentication for this resource.
//
#define RES_NETNAME_ONLINE_RENAME_RECOVERY_MISSING_ACCOUNT 1218L

//
// MessageId: RES_NETNAME_ONLINE_RENAME_DC_NOT_FOUND
//
// MessageText:
//
//  The search in Active Directory to find computer account %2 on DC %3 for
//  resource '%1' failed. The associated error code is stored in the data
//  section.%n
//  %nThe computer account for this resource was in the process of being renamed
//  and did not complete. The Domain Controller where the account was being
//  renamed is either unavailable or is preventing access when searching for the
//  account. This DC must be made available before this resource can go online in
//  order to reconcile the rename operation.%n
//  %nIf this is not possible, disable and re-enable Kerberos Authentication and
//  an attempt will be made to find the computer account on a different DC.
//
#define RES_NETNAME_ONLINE_RENAME_DC_NOT_FOUND 1219L

//
// MessageId: RES_NETNAME_ONLINE_RENAME_RECOVERY_FAILED
//
// MessageText:
//
//  The computer account for resource '%1' failed to be renamed from %2 to %3
//  using Domain Controller %4. The associated error code is stored in the data
//  section.%n
//  %nThe computer account for this resource was in the process of being renamed
//  and did not complete. This was detected during the online process for this
//  resource. In order to recover, the computer account must be renamed to the
//  current value of the Name property, i.e., the name presented on the network.%n
//  %nThe Domain Controller where the renamed was attempted might not be
//  available; if this is the case, wait for the Domain Controller to be available
//  again. The Domain Controller could be denying access to the account; after
//  resolving access, try to bring the name online again.%n
//  %nIf this is not possible, disable and re-enable Kerberos Authentication and
//  an attempt will be made to find the computer account on a different DC. You
//  need to change the Name property to %2 in order to use the existing computer
//  account.
//
#define RES_NETNAME_ONLINE_RENAME_RECOVERY_FAILED 1220L

//
// MessageId: RES_NETNAME_RENAME_OUT_OF_SYNCH_WITH_COMPOBJ
//
// MessageText:
//
//  The Network Name (%2) for resource '%1' does not match the name of the
//  corresponding computer account in AD (%3). This is usually due to the name
//  change of the computer account not replicating to other domain controllers in
//  the domain. A subsequent rename cannot be performed until the name change has
//  replicated to other DCs. If the Network Name has not been changed, then the it
//  is out synch with the name of the computer account. This problem can be fixed
//  by renaming the computer account and letting that change replicate to other
//  DCs. Once that has occurred, the Network Name for this resource can be
//  changed.
//
#define RES_NETNAME_RENAME_OUT_OF_SYNCH_WITH_COMPOBJ 1221L

//
// MessageId: CS_EVENT_CLEANUP_ON_EVICTION
//
// MessageText:
//
//  This node was evicted from the cluster while it was down.  The cluster state has been
//  cleaned up.  The cleanup status was %1. 
//
#define CS_EVENT_CLEANUP_ON_EVICTION     1222L

//
// MessageId: RES_IPADDR_INVALID_NETWORK_ROLE
//
// MessageText:
//
//  Cluster IP Address resource '%1' cannot be brought online because the
//  configured role of cluster network '%2' does not allow client access. Please
//  check your network configuration.
//
#define RES_IPADDR_INVALID_NETWORK_ROLE  1223L

//
// MessageId: RES_IPADDR_PATCHED_NETWORK
//
// MessageText:
//
//  Cluster IP Address resource '%1' has been moved to cluster network '%2'
//  because its IP address and subnet mask match. To reverse this assignment,
//  take resource '%1' offline, restore the '%1' Network property to its former
//  value, set the '%1' OverrideAddressMatch property to 1, and bring resource
//  '%1' back online.
//
#define RES_IPADDR_PATCHED_NETWORK       1224L

//
// MessageId: RES_NETNAME_UPGRADE_TO_KERBEROS_SUPPORT_FAILED
//
// MessageText:
//
//  The Network Name resource '%1' is a provider for an MSMQ resource. Kerberos
//  Authentication support must be enabled for the Network Name resource in order
//  to successfully bring the MSMQ resource online. The attempt to enable this
//  feature failed; the associated error code is stored in the data section.%n
//  %nTo set the RequireKerberos property for this resource, take this resource
//  offline, display this resource's properties in Cluster Administrator and
//  select the Parameters tab. Check the "Enable Kerberos Authentication" box and
//  press OK to save the changes. Bring this resource online.%n
//  %nAlternatively, the property can be set by using the cluster.exe command line
//  tool:%n
//  %ncluster resource "%1" /priv RequireKerberos=1
//
#define RES_NETNAME_UPGRADE_TO_KERBEROS_SUPPORT_FAILED 1225L

//
// MessageId: RES_NETNAME_TCB_NOT_HELD
//
// MessageText:
//
//  The Network Name resource '%1' has Kerberos Authentication support
//  enabled. This feature requires that the Cluster Service Account hold the Trust
//  Computing Base (TCB) or "Act as part of the operating system" privilege. This
//  privilege is locally granted to the Cluster Service Account during cluster
//  setup and is no longer granted to the account. It may have been removed as the
//  result of the application of a Group Policy object to this cluster node.%n
//  %nThe TCB privilege can be granted via the Local Security Policy snap-in
//  (secpol.msc). Q307532 contains information on how to assign user rights. Add
//  the Cluster Service Account to the list of accounts that have this
//  privilege.%n
//  %nIn order for the privilege to be enabled, the Cluster Service must be
//  stopped and restarted. This procedure may have to be applied on each node in
//  the cluster.
//
#define RES_NETNAME_TCB_NOT_HELD         1226L

//
// MessageId: RES_NETNAME_LSA_ERROR
//
// MessageText:
//
//  The Network Name resource '%1' has Kerberos Authentication support enabled and
//  was unable to add the virtual network name credentials to the LSA. The
//  associated error code is stored in the data section.
//
#define RES_NETNAME_LSA_ERROR            1227L

//
// MessageId: CLNET_CLUSSVC_HUNG_TERMINATE
//
// MessageText:
//
//  The Cluster Network Driver has lost contact with Cluster service for %2 seconds. Cluster service will be Terminated.
//
#define CLNET_CLUSSVC_HUNG_TERMINATE     1228L

//
// MessageId: CLNET_CLUSSVC_HUNG
//
// MessageText:
//
//  The Cluster Network Driver has lost contact with Cluster service for %2 seconds.
//
#define CLNET_CLUSSVC_HUNG               1229L

//
// MessageId: RMON_DEADLOCK_DETECTED
//
// MessageText:
//
//  Cluster resource monitor detected a deadlock possibly caused by invoking the '%4' entry point of
//  resource DLL '%1', resource type '%2', resource '%3'. This process is now attempting to terminate. 
//
#define RMON_DEADLOCK_DETECTED           1230L

//
// MessageId: CS_INVALID_START_PARAMETER
//
// MessageText:
//
//  The start parameter '%1' supplied to the Cluster Service is invalid. The service is now stopping.
//  Valid start parameters are %n%n
//  ResetQuorumLog/RQ - Reset the quorum log file at startup.%n
//  FixQuorum/FQ - Start the Cluster Service even in the absence of a functioning quorum resource.%n
//  NoQuorumLogging/NQ - Run the Cluster Service in this node with quorum logging turned off.%n
//  DebugResmon/DR - The Cluster Service waits for a debugger to be attached to all Resource Monitor processes at their start.%n
//  ForceQuorum/FO <N1,N2,...> - Force a majority node set with the node list N1, N2, etc. (Applicable only for Majority Node Set quorum)%n
//  NoGroupInfoEvtLogging/NG - Do not log events to the event log related to group online and offline.
//
#define CS_INVALID_START_PARAMETER       1231L

//
// MessageId: RES_GENSCRIPT_TIMEOUT
//
// MessageText:
//
//  Cluster generic script resource %1 timed out. %2 script entry point did not complete execution
//  in a timely manner. This could be due to an infinite loop or a hang in this entry point, or the
//  pending timeout may be too short for this resource. Please review the %2 script entry point to make
//  sure there's no infinite loop or a hang in the script code, and then consider increasing the pending
//  timeout value if necessary. In a command shell, run "cluster res "%1" /prop PersistentState=0"
//  to disable this resource, and then run "net stop clussvc" to stop the cluster service. Ensure that
//  any problem in the script code is fixed.  Then run "net start clussvc" to start the cluster service.
//  If necessary, ensure that the pending time out is increased before bringing the resource online
//  again.
//
#define RES_GENSCRIPT_TIMEOUT            1232L

//
// MessageId: RES_GENSCRIPT_HANGMODE
//
// MessageText:
//
//  Cluster generic script resource %1: Request to perform the %2 operation will not be processed.
//  This is because of a previous failed attempt to execute the %3 entry point in a timely fashion.
//  Please review the script code for this entry point to make sure there is no infinite loop or a hang
//  in it, and then consider increasing the resource pending timeout value if necessary. In a
//  command shell, run "cluster res "%1" /prop PersistentState=0" to disable this resource, and then
//  run "net stop clussvc" to stop the cluster service. Ensure that any problem in the script code is
//  fixed.  Then run "net start clussvc" to start the cluster service. If necessary, ensure that the
//  pending time out is increased before bringing the resource online again.
//
#define RES_GENSCRIPT_HANGMODE           1233L

#endif // _CLUSVMSG_INCLUDED
