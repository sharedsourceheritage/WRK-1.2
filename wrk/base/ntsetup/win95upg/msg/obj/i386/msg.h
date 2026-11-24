//
// ####################################################################################
// #
// #  w95upg.dll messages
// #
// ####################################################################################
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
// MessageId: MSG_FIRST_WIN9X
//
// MessageText:
//
//  MSG_FIRST_WIN9X
//
#define MSG_FIRST_WIN9X                  0x00000064L

// ***
// *** Types of operating systems
// ***
//
// MessageId: MSG_CHICAGO
//
// MessageText:
//
//  Windows 95%0
//
#define MSG_CHICAGO                      0x00000065L

//
// MessageId: MSG_NASHVILLE
//
// MessageText:
//
//  Windows 95%0
//
#define MSG_NASHVILLE                    0x00000066L

//
// MessageId: MSG_MEMPHIS
//
// MessageText:
//
//  Windows 98%0
//
#define MSG_MEMPHIS                      0x00000067L

// ***
// *** NT Server block and Windows CE block
// ***
//
// MessageId: MSG_SERVER_UPGRADE_UNSUPPORTED_INIT
//
// MessageText:
//
//  Setup cannot upgrade %1 settings to Windows XP Server. The Upgrade option is not available.%0
//
#define MSG_SERVER_UPGRADE_UNSUPPORTED_INIT 0x00000068L

//
// MessageId: MSG_SERVER_UPGRADE_UNSUPPORTED
//
// MessageText:
//
//  Setup cannot upgrade %1 settings to Windows XP Server. Restart Setup, and select Install Windows XP.%0
//
#define MSG_SERVER_UPGRADE_UNSUPPORTED   0x00000069L

//
// MessageId: MSG_PLATFORM_UPGRADE_UNSUPPORTED
//
// MessageText:
//
//  Setup cannot upgrade this computer to Windows XP. The Upgrade option is not available.%0
//
#define MSG_PLATFORM_UPGRADE_UNSUPPORTED 0x0000006AL

// ***
// *** Initialization failure
// ***
//
// MessageId: MSG_DEFERRED_INIT_FAILED_POPUP
//
// MessageText:
//
//  Setup cannot run on this computer. A hardware device may have failed, or there may not be enough memory available.%0
//
#define MSG_DEFERRED_INIT_FAILED_POPUP   0x0000006BL

// ***
// *** Progress bar messages
// ***
//
// MessageId: MSG_HWCOMP_TEXT
//
// MessageText:
//
//  Hardware check%0
//
#define MSG_HWCOMP_TEXT                  0x0000006CL

//
// MessageId: MSG_UPGRADEREPORT_TEXT
//
// MessageText:
//
//  Analyzing your computer...%0
//
#define MSG_UPGRADEREPORT_TEXT           0x0000006DL

//
// MessageId: MSG_PREPARING_LIST
//
// MessageText:
//
//  Preparing a list of components...%0
//
#define MSG_PREPARING_LIST               0x0000006EL

//
// MessageId: MSG_HWCOMP
//
// MessageText:
//
//  Examining your hardware...%0
//
#define MSG_HWCOMP                       0x0000006FL

//
// MessageId: MSG_MIGAPP
//
// MessageText:
//
//  Examining programs...%0
//
#define MSG_MIGAPP                       0x00000070L

//
// MessageId: MSG_ENUMERATING_FILE_SYSTEM
//
// MessageText:
//
//  Scanning hard disks for incompatibilities...%0
//
#define MSG_ENUMERATING_FILE_SYSTEM      0x00000071L

//
// MessageId: MSG_PROCESSING_SYSTEM_FILES
//
// MessageText:
//
//  Processing system files...%0
//
#define MSG_PROCESSING_SYSTEM_FILES      0x00000072L

//
// MessageId: MSG_PROCESSING_MIGRATIONDLLS
//
// MessageText:
//
//  Processing upgrade packs...%0
//
#define MSG_PROCESSING_MIGRATIONDLLS     0x00000073L

//
// MessageId: MSG_PROCESSING_SHELL_LINKS
//
// MessageText:
//
//  Processing system files...%0
//
#define MSG_PROCESSING_SHELL_LINKS       0x00000074L

//
// MessageId: MSG_PROCESSING_DOSFILES
//
// MessageText:
//
//  Processing MS-DOS configuration files...%0
//
#define MSG_PROCESSING_DOSFILES          0x00000075L

//
// MessageId: MSG_INITIALIZING
//
// MessageText:
//
//  Preparing Setup database...%0
//
#define MSG_INITIALIZING                 0x00000076L

//
// MessageId: MSG_LOCATING_MIGRATION_DLLS
//
// MessageText:
//
//  Locating upgrade packs...%0
//
#define MSG_LOCATING_MIGRATION_DLLS      0x00000077L

//
// MessageId: MSG_BEGINNING_ENUMERATION
//
// MessageText:
//
//  Examining hard disks...%0
//
#define MSG_BEGINNING_ENUMERATION        0x00000078L

//
// WARNING: This text is sent to NT for uninstall via the registry. This is because
//          progress text is needed but it is too late to make UI changes. We must
//          recycle old text. <bleck!>
//
//
// MessageId: MSG_OLEREG
//
// MessageText:
//
//  Processing...%0
//
#define MSG_OLEREG                       0x00000079L

// When rebuilding the hwcomp.dat file:
//
// MessageId: MSG_DECOMPRESSING
//
// MessageText:
//
//  Decompressing installation files...%0
//
#define MSG_DECOMPRESSING                0x0000007AL

// ***
// *** Supply Hardware Files and Supply Upgrade Packs dialogs
// ***
// Browse title
//
// MessageId: MSG_DRIVER_DLG_TITLE
//
// MessageText:
//
//  Select the location of the hardware files supplied by the manufacturer.%0
//
#define MSG_DRIVER_DLG_TITLE             0x0000007BL

// Browse title
//
// MessageId: MSG_UPGRADE_MODULE_DLG_TITLE
//
// MessageText:
//
//  Select the location of any upgrade packs supplied by a software manufacturer.%0
//
#define MSG_UPGRADE_MODULE_DLG_TITLE     0x0000007CL

// User chose Browse, then something, then OK. This popup appears because selection is invalid.
// (User will have to Browse again.)
//
// MessageId: MSG_BAD_SEARCH_PATH
//
// MessageText:
//
//  Setup cannot search the folder you selected. Please select another folder.%0
//
#define MSG_BAD_SEARCH_PATH              0x0000007DL

// Either no suitable drivers found, or drivers already supplied.
//
// MessageId: MSG_NO_DRIVERS_FOUND
//
// MessageText:
//
//  Setup did not find the required hardware files in the selected folder.%0
//
#define MSG_NO_DRIVERS_FOUND             0x0000007EL

// When copying the driver to the local disk... we ran out of space.
//
// MessageId: MSG_DISK_FULL
//
// MessageText:
//
//  There is not enough disk space to copy the selected files. Quit Setup, free additional disk space, and then restart Setup.%0
//
#define MSG_DISK_FULL                    0x0000007FL

// No upgrade packs found.
//
// MessageId: MSG_NO_MODULES_FOUND
//
// MessageText:
//
//  Setup did not find any upgrade packs in the selected folder. Select another folder and try again.%0
//
#define MSG_NO_MODULES_FOUND             0x00000080L

// ***
// *** Name change UI
// ***
//
// MessageId: MSG_NAME_IN_USE_POPUP
//
// MessageText:
//
//  The name you specified conflicts with another setting. Click OK, and then type a different name.%0
//
#define MSG_NAME_IN_USE_POPUP            0x00000081L

//
// MessageId: MSG_RECOMMENDED_COMPUTER_NAME
//
// MessageText:
//
//  MyComputer%0
//
#define MSG_RECOMMENDED_COMPUTER_NAME    0x00000082L

//
// - Arbitrary name used in rare cases when incompatible user names are
//   found; must be 15 characters or less
// - Setup appends numbers when two or more user names are incompatible
//   (Windows User 2, Windows User 3, etc...)
// - UI allows changing Setup's recommendations
//
//
// MessageId: MSG_RECOMMENDED_USER_NAME
//
// MessageText:
//
//  Windows User%0
//
#define MSG_RECOMMENDED_USER_NAME        0x00000083L

//
// MessageId: MSG_RECOMMENDED_WORKGROUP_NAME
//
// MessageText:
//
//  Workgroup%0
//
#define MSG_RECOMMENDED_WORKGROUP_NAME   0x00000084L

//
// MessageId: MSG_COMPUTERNAME_CATEGORY
//
// MessageText:
//
//  Computer Name%0
//
#define MSG_COMPUTERNAME_CATEGORY        0x00000085L

//
// MessageId: MSG_COMPUTERDOMAIN_CATEGORY
//
// MessageText:
//
//  Computer Domain%0
//
#define MSG_COMPUTERDOMAIN_CATEGORY      0x00000086L

//
// MessageId: MSG_WORKGROUP_CATEGORY
//
// MessageText:
//
//  Workgroup%0
//
#define MSG_WORKGROUP_CATEGORY           0x00000087L

//
// MessageId: MSG_USERNAME_CATEGORY
//
// MessageText:
//
//  User Name%0
//
#define MSG_USERNAME_CATEGORY            0x00000088L

// Used for other names besides computer names (i.e., domain name, workgroup name)
//
// MessageId: MSG_INVALID_COMPUTERNAME_CHAR_POPUP
//
// MessageText:
//
//  The name must be composed only of the following characters:
//  
//   Alphabetic: A-Z, a-z
//   Numeric: 0-9
//   Punctuation and Symbols: ! @ # $ %% ^ & ' ( ) . - _ { } ~
//
#define MSG_INVALID_COMPUTERNAME_CHAR_POPUP 0x00000089L

//
// MessageId: MSG_INVALID_EMPTY_NAME_POPUP
//
// MessageText:
//
//  Please specify a new name, or click Cancel to return to the previous screen.%0
//
#define MSG_INVALID_EMPTY_NAME_POPUP     0x0000008AL

// Used for other names besides computer names (i.e., domain name, workgroup name)
//
// MessageId: MSG_INVALID_COMPUTERNAME_LENGTH_POPUP
//
// MessageText:
//
//  The name cannot be longer than 15 characters.%0
//
#define MSG_INVALID_COMPUTERNAME_LENGTH_POPUP 0x0000008BL

//
// MessageId: MSG_INVALID_USERNAME_CHAR_POPUP
//
// MessageText:
//
//  User names cannot use the following characters:
//  
//   " \ / [ ] : ; | = , + * ? < >
//
#define MSG_INVALID_USERNAME_CHAR_POPUP  0x0000008CL

//
// MessageId: MSG_INVALID_USERNAME_SPACEDOT_POPUP
//
// MessageText:
//
//  User names cannot consist only of spaces and periods.%0
//
#define MSG_INVALID_USERNAME_SPACEDOT_POPUP 0x0000008DL

//
// MessageId: MSG_INVALID_USERNAME_LENGTH_POPUP
//
// MessageText:
//
//  User names cannot be longer than 20 characters.%0
//
#define MSG_INVALID_USERNAME_LENGTH_POPUP 0x0000008EL

//
// MessageId: MSG_INVALID_USERNAME_DUPLICATE_POPUP
//
// MessageText:
//
//  The specified user name is already in use. You should type a different user name.%0
//
#define MSG_INVALID_USERNAME_DUPLICATE_POPUP 0x0000008FL

// Domain error popup when invalid domain name is entered
// ISSUE  - because of localization constraints, this message has
//          been moved to the end of the file
// Domain error popup when non-existent domain name is entered
//
// MessageId: MSG_DOMAIN_NOT_RESPONDING_POPUP
//
// MessageText:
//
//  Setup could not reach the specified domain. Verify the domain name.%0
//
#define MSG_DOMAIN_NOT_RESPONDING_POPUP  0x00000090L

// Domain error popup when no accounts are found on any domains
//
// MessageId: MSG_DOMAIN_ACCOUNT_NOT_FOUND_POPUP
//
// MessageText:
//
//  Setup cannot find a network account for this computer. Contact your network administrator.%0
//
#define MSG_DOMAIN_ACCOUNT_NOT_FOUND_POPUP 0x00000091L

// Names that collide with NT, not used for display; separate names with pipe symbol (|)
//
// MessageId: MSG_NAME_COLLISION_LIST
//
// MessageText:
//
//  Administrators|Account Operators|Anonymous Logon|Authenticated Users|Backup Operators|Batch|Creator Group|Creator Owner|DIALUP|Domain Admins|Domain Guests|Domain Users|Everyone|Guest|Guests|HelpAssistant|HelpServicesGroup|INTERACTIVE|LOCAL SERVICE|NETWORK|Network Configuration Operators|NETWORK SERVICE|None|Power Users|Print Operators|Remote Desktop Users|REMOTE INTERACTIVE LOGON|Replicator|Server Operators|SERVICE|SYSTEM|TERMINAL SERVER USER|TsInternetUser|Users|MTS Administrators|MTS Impersonators|MTS_ADMIN|IMDB Trusted Users|WBEM Users|IMDB Trusted Users|%0
//
#define MSG_NAME_COLLISION_LIST          0x00000092L

// ***
// *** Print and save as dialogs
// ***
// Error building SaveReportTo Config Option.
//
// MessageId: MSG_ERROR_CREATING_SAVETO_DIRECTORY
//
// MessageText:
//
//  Setup cannot create the SaveReportTo folder specified by the Answer File. Reports will be saved to the Windows folder instead.%0
//
#define MSG_ERROR_CREATING_SAVETO_DIRECTORY 0x00000093L

// Save As default file name
//
// MessageId: MSG_DEFAULT_REPORT_FILE
//
// MessageText:
//
//  upgrade.htm%0
//
#define MSG_DEFAULT_REPORT_FILE          0x00000094L

// prntsave.c -- to be removed soon
//
// MessageId: MSG_REPORT_SAVE_INDENT_LEN
//
// MessageText:
//
//  10%0
//
#define MSG_REPORT_SAVE_INDENT_LEN       0x00000095L

//
// MessageId: MSG_CANT_PRINT
//
// MessageText:
//
//  Setup cannot print the report. Make sure this computer is attached to a local or network printer.%0
//
#define MSG_CANT_PRINT                   0x00000096L

// Headers go at the top of every page on the incompatibility printout.
// Each message has arg 1 as a page number.
//
// MessageId: MSG_REPORT_HEADER_LEFT
//
// MessageText:
//
//  Upgrade Report%0
//
#define MSG_REPORT_HEADER_LEFT           0x00000097L

//
// MessageId: MSG_REPORT_HEADER_CENTER
//
// MessageText:
//
//  %0
//
#define MSG_REPORT_HEADER_CENTER         0x00000098L

//
// MessageId: MSG_REPORT_HEADER_RIGHT
//
// MessageText:
//
//  Page %1%0
//
#define MSG_REPORT_HEADER_RIGHT          0x00000099L

// Winds up in the print spooler UI:
//
// MessageId: MSG_REPORT_DOC_NAME
//
// MessageText:
//
//  Windows XP Setup Incompatibility Report%0
//
#define MSG_REPORT_DOC_NAME              0x0000009AL

// We tried saving the report, but ran into an error.
//
// MessageId: MSG_CANT_SAVE
//
// MessageText:
//
//  Setup cannot save the report to your disk. Please check the disk and make sure it has enough free space.%0
//
#define MSG_CANT_SAVE                    0x0000009BL

// ***
// *** Disk Space
// ***
//
// MessageId: MSG_ERROR_OUT_OF_DISK_SPACE
//
// MessageText:
//
//  Setup does not have enough disk space to continue. You will need to free %2 megabytes of space on your %1 drive before setup can continue.%0
//
#define MSG_ERROR_OUT_OF_DISK_SPACE      0x0000009CL

// ***
// *** Messages written to the setupact.log or setuperr.log file
// ***
//
// MessageId: MSG_MSGMGR_ADD
//
// MessageText:
//
//  Added incompatibility message for object %1: %2
//
#define MSG_MSGMGR_ADD                   0x0000009DL

// ***
// *** DOSMIG
// ***
//
// MessageId: MSG_DOS_LOG_WARNING
//
// MessageText:
//
//  The following lines describe incompatible or unknown MS-DOS configuration items. Resources controlled by these lines may not function after Setup is complete.
//  
//  %1%0
//
#define MSG_DOS_LOG_WARNING              0x0000009EL

//
// MessageId: MSG_DOS_INCOMPATIBLE_ITEM
//
// MessageText:
//
//  Line %1 of %2, (Unknown)
//  %3%0
//
#define MSG_DOS_INCOMPATIBLE_ITEM        0x0000009FL

//
// MessageId: MSG_DOS_UNKNOWN_ITEM
//
// MessageText:
//
//  Line %1 of %2, (Incompatible)
//  %3%0
//
#define MSG_DOS_UNKNOWN_ITEM             0x000000A0L

// ***
// *** Messages for user account processing
// ***
//
// MessageId: MSG_NO_VALID_ACCOUNTS_POPUP
//
// MessageText:
//
//  Setup could not process user accounts. Start Setup again.%0
//
#define MSG_NO_VALID_ACCOUNTS_POPUP      0x000000A1L

// ***
// *** Messages from the file scan on Win9x
// ***
//
// MessageId: MSG_MODULE_REQUIRES_EXPORT_LOG
//
// MessageText:
//
//  File %1 requires export(s) not available on Windows XP.
//
#define MSG_MODULE_REQUIRES_EXPORT_LOG   0x000000A2L

//
// MessageId: MSG_ENUMDRIVES_FAILED_LOG
//
// MessageText:
//
//  An error occurred while Setup was examining drives.
//
#define MSG_ENUMDRIVES_FAILED_LOG        0x000000A3L

// ***
// *** Messages for directory collisions
// ***
//
// MessageId: MSG_DIR_COLLISION_LOG
//
// MessageText:
//
//  The following files will be renamed because of a collision with Windows XP folders:
//  %1%0
//
#define MSG_DIR_COLLISION_LOG            0x000000A4L

// ***
// *** Win9x-side Migration DLL processing
// ***
//
// %1 - DLL path
// %2 - Product ID (a friendly name, empty until QueryVersion completes successfully)
// %3 - Error code
// %4 - Entry point that failed
//
// Additional parameters for MSG_MIGDLL_FAILED_POPUP and MSG_MIGDLL_FAILED_LOG:
//
// %5 - Company Name
// %6 - Support Phone Number
// %7 - Support URL
// %8 - Instructions to user from migration DLL
// %9 - Line break if either %6, %7 or %8 is non empty
//
//
// MessageId: MSG_MIGDLL_QV_FAILED_LOG
//
// MessageText:
//
//  The upgrade pack %1 failed in QueryVersion with error code %3. Setup cannot process this pack.
//
#define MSG_MIGDLL_QV_FAILED_LOG         0x000000A5L

//
// MessageId: MSG_MIGDLL_FAILED_POPUP
//
// MessageText:
//
//  The %2 upgrade pack from %5 failed. Setup cannot process this upgrade pack.%9%8%6%7
//
#define MSG_MIGDLL_FAILED_POPUP          0x000000A6L

//
// MessageId: MSG_MIGDLL_FAILED_LOG
//
// MessageText:
//
//  The upgrade pack %2 failed in %4 with error code %3. Setup cannot process this pack.%0
//
#define MSG_MIGDLL_FAILED_LOG            0x000000A7L

//
// MessageId: MSG_MIGDLL_QUERYVERSION_EXCEPTION_LOG
//
// MessageText:
//
//  Migration DLL at %1 threw an exception in QueryVersion; the DLL will not be processed.
//
#define MSG_MIGDLL_QUERYVERSION_EXCEPTION_LOG 0x000000A8L

//
// MessageId: MSG_MIGDLL_INITIALIZE9X_EXCEPTION_LOG
//
// MessageText:
//
//  Migration DLL %2 threw an exception in Initialize9x; the DLL will not be processed.
//
#define MSG_MIGDLL_INITIALIZE9X_EXCEPTION_LOG 0x000000A9L

//
// MessageId: MSG_MIGDLL_MIGRATEUSER9X_EXCEPTION_LOG
//
// MessageText:
//
//  Migration DLL %2 threw an exception in MigrateUser9x; the DLL will not be processed.
//
#define MSG_MIGDLL_MIGRATEUSER9X_EXCEPTION_LOG 0x000000AAL

//
// MessageId: MSG_MIGDLL_MIGRATESYSTEM9X_EXCEPTION_LOG
//
// MessageText:
//
//  Migration DLL %2 threw an exception in MigrateSystem9x; the DLL will not be processed.
//
#define MSG_MIGDLL_MIGRATESYSTEM9X_EXCEPTION_LOG 0x000000ABL

// ***
// *** Account Names used for display
// ***
//
// MessageId: MSG_DEFAULT_USER
//
// MessageText:
//
//  Logon User%0
//
#define MSG_DEFAULT_USER                 0x000000ACL

//
// MessageId: MSG_ADMINISTRATOR
//
// MessageText:
//
//  Administrator%0
//
#define MSG_ADMINISTRATOR                0x000000ADL

// ***
// *** Drive accessibility
// ***
//
// MessageId: MSG_NO_ACCESSIBLE_DRIVES_POPUP
//
// MessageText:
//
//  Setup did not find any compatible drives on this computer. Setup cannot upgrade this computer to Windows XP.%0
//
#define MSG_NO_ACCESSIBLE_DRIVES_POPUP   0x000000AEL

//
// Other system warnings
//
//
// MessageId: MSG_FULL_REPORT_TEXT
//
// MessageText:
//
//  Setup found hardware or software on your computer that might not work with Windows XP. You should read and understand this upgrade report before continuing. For more information, click Full Report.%0
//
#define MSG_FULL_REPORT_TEXT             0x000000AFL

//
// MessageId: MSG_FULL_REPORT_BUTTON
//
// MessageText:
//
//  &Full Report%0
//
#define MSG_FULL_REPORT_BUTTON           0x000000B0L

//
// Checked-build Messages - shown only on checked build
//
//
// MessageId: MSG_COMPONENT_OLE
//
// MessageText:
//
//  Installation Notes\Checked Build Warning\OLE\%2%0
//
#define MSG_COMPONENT_OLE                0x000000B1L

//
// MessageId: MSG_OBJECT_POINTS_TO_DELETED_GUID
//
// MessageText:
//
//  Checked build warning: OLE object (%1) points to a deleted class ID.
//  
//
#define MSG_OBJECT_POINTS_TO_DELETED_GUID 0x000000B2L

//
// MessageId: MSG_OBJECT_POINTS_TO_DELETED_FILE
//
// MessageText:
//
//  Checked build warning: OLE object (%1) is part of a %3-specific binary that will be deleted.
//  
//
#define MSG_OBJECT_POINTS_TO_DELETED_FILE 0x000000B3L

//
// MessageId: MSG_GUID_LEAK
//
// MessageText:
//
//  Checked build warning: A %3-specific OLE object (%1) has an Interface reference to a supported object; the supported object may no longer be needed.
//  
//
#define MSG_GUID_LEAK                    0x000000B4L

//
// MessageId: MSG_INTERFACE_BROKEN
//
// MessageText:
//
//  Checked build warning: A supported OLE object (%1) has an Interface dependency on a %3-specific object.
//  
//
#define MSG_INTERFACE_BROKEN             0x000000B5L

//
// MessageId: MSG_POTENTIAL_INTERFACE_LEAK
//
// MessageText:
//
//  Checked build warning: A %3-specific OLE object (%1) has a reference to a supported object; the supported object may no longer be needed.
//  
//
#define MSG_POTENTIAL_INTERFACE_LEAK     0x000000B6L

//
// MessageId: MSG_PROGID_BROKEN
//
// MessageText:
//
//  Checked build warning: A supported OLE program ID (%1) has a reference to a %3-specific object.
//  
//
#define MSG_PROGID_BROKEN                0x000000B7L

//
// MessageId: MSG_POTENTIAL_PROGID_LEAK
//
// MessageText:
//
//  Checked build warning: A %3-specific OLE object (%1) has a reference to a supported program ID; the supported program ID may no longer be needed.
//  
//
#define MSG_POTENTIAL_PROGID_LEAK        0x000000B8L

//
// Messages displayed during unattended operations
//
//
// MessageId: MSG_BUILDING_REPORT_MESSAGE
//
// MessageText:
//
//  The Windows XP Upgrade Advisor is building a report for your computer's hardware and software. This report will be saved to the following location:
//   %1%0
//
#define MSG_BUILDING_REPORT_MESSAGE      0x000000B9L

// This is for an undocumented mode that we use for research at upgrade fairs, customers do not see it.
//
// MessageId: MSG_ERROR_READING_FROM_DEVICE
//
// MessageText:
//
//  Error reading from device. Click OK to try again, or click Cancel to abort.%0
//
#define MSG_ERROR_READING_FROM_DEVICE    0x000000BAL

// This is for an undocumented mode that we use for research at upgrade fairs, customers do not see it.
//
// MessageId: MSG_INSERT_FLOPPY
//
// MessageText:
//
//  Setup requires more space to finish saving this file. Insert a new floppy disk, and click OK, or click Cancel to abort saving this file.%0
//
#define MSG_INSERT_FLOPPY                0x000000BBL

//
// Critical error messages explaining why Setup is about to puke. These conditions are extremely rare.
//
//
// MessageId: MSG_ERROR_UNEXPECTED_ACCESSIBLE_DRIVES
//
// MessageText:
//
//  Setup encountered an error while examining your disk drives. Contact Microsoft Technical Support.%0
//
#define MSG_ERROR_UNEXPECTED_ACCESSIBLE_DRIVES 0x000000BCL

//
// MessageId: MSG_COULD_NOT_CREATE_DIRECTORY
//
// MessageText:
//
//  Setup cannot create a temporary folder. Setup cannot continue.
//
#define MSG_COULD_NOT_CREATE_DIRECTORY   0x000000BDL

//
// MessageId: MSG_TXTSETUP_SIF_ERROR
//
// MessageText:
//
//  Setup cannot access Txtsetup.sif, a required file that comes with Windows XP. Setup cannot continue.
//
#define MSG_TXTSETUP_SIF_ERROR           0x000000BEL

//
// MessageId: MSG_UNEXPECTED_ERROR_ENCOUNTERED
//
// MessageText:
//
//  Setup cannot continue. Contact Microsoft Technical Support. (Error: %1!X!h)
//
#define MSG_UNEXPECTED_ERROR_ENCOUNTERED 0x000000BFL

//
// Hardware compatibility
//
//
// MessageId: MSG_OFFLINE_DEVICE
//
// MessageText:
//
//  %1</B> (not currently present)%0
//
#define MSG_OFFLINE_DEVICE               0x000000C0L

// UNUSED!!
//
// MessageId: MSG_HARDWARE_COMPONENT
//
// MessageText:
//
//  %0
//
#define MSG_HARDWARE_COMPONENT           0x000000C1L

//
// MessageId: MSG_HARDWARE_MESSAGE
//
// MessageText:
//
//  Windows XP does not supply a driver for the following device:
//  
//  Device: %1
//  Manufacturer: %4
//  Device Type: %2
//  Device Class: %3
//
#define MSG_HARDWARE_MESSAGE             0x000000C2L

//
// Network incompatibility text
//
// %1 is name of protocol, i.e., Banyan Vines
//
// MessageId: MSG_UNSUPPORTED_PROTOCOL_UNUSED
//
// MessageText:
//
//  %0
//
#define MSG_UNSUPPORTED_PROTOCOL_UNUSED  0x000000C3L

// %2 is the protocol vendor, i.e., Banyan
//
// MessageId: MSG_UNSUPPORTED_PROTOCOL_KNOWN_MFG_UNUSED
//
// MessageText:
//
//  %0
//
#define MSG_UNSUPPORTED_PROTOCOL_KNOWN_MFG_UNUSED 0x000000C4L

//
// MessageId: MSG_NETWORK_PROTOCOLS_UNUSED
//
// MessageText:
//
//  %0
//
#define MSG_NETWORK_PROTOCOLS_UNUSED     0x000000C5L

// Unusual condition where RAS settings can't be obtained.
//
// MessageId: MSG_RAS_COMPONENT_UNUSED
//
// MessageText:
//
//  %0
//
#define MSG_RAS_COMPONENT_UNUSED         0x000000C6L

//
// MessageId: MSG_RAS_MESSAGE_UNUSED
//
// MessageText:
//
//  %0
//
#define MSG_RAS_MESSAGE_UNUSED           0x000000C7L

//
// Messages added since localization began
//
// The localizers cannot handle changes in MessageID!
//
//
// MessageId: MSG_ACCOUNT_NOT_FOUND_POPUP
//
// MessageText:
//
//  Setup did not find an account for your computer on the specified domain. Do you want to create an account?%0
//
#define MSG_ACCOUNT_NOT_FOUND_POPUP      0x000000C8L

//
// MessageId: MSG_FILE_COPY_ERROR
//
// MessageText:
//
//  Setup cannot copy all of its files to your computer.%0
//
#define MSG_FILE_COPY_ERROR              0x000000C9L

// %1 - source, %2 - dest
//
// MessageId: MSG_FILE_COPY_ERROR_LOG
//
// MessageText:
//
//  Setup cannot copy %1 to %2.
//
#define MSG_FILE_COPY_ERROR_LOG          0x000000CAL

// %1 - link name
//
// MessageId: MSG_NICE_PATH_START_MENU
//
// MessageText:
//
//  %1</B> (on the Start menu)%0
//
#define MSG_NICE_PATH_START_MENU         0x000000CBL

// %1 - link name
//
// MessageId: MSG_NICE_PATH_DESKTOP
//
// MessageText:
//
//  %1</B> (on the Desktop)%0
//
#define MSG_NICE_PATH_DESKTOP            0x000000CCL

// %1 - link name
//
// MessageId: MSG_NICE_PATH_FAVORITES
//
// MessageText:
//
//  %1</B> (in Favorites)%0
//
#define MSG_NICE_PATH_FAVORITES          0x000000CDL

// %1 - link name
//
// MessageId: MSG_NICE_PATH_PROGRAMS
//
// MessageText:
//
//  %1</B> (on the Start menu)%0
//
#define MSG_NICE_PATH_PROGRAMS           0x000000CEL

// %1 - link name
//
// MessageId: MSG_NICE_PATH_RECENT
//
// MessageText:
//
//  %1</B> (in Recent Documents)%0
//
#define MSG_NICE_PATH_RECENT             0x000000CFL

// %1 - link name
//
// MessageId: MSG_NICE_PATH_SEND_TO
//
// MessageText:
//
//  Send to %1%0
//
#define MSG_NICE_PATH_SEND_TO            0x000000D0L

// %1 - link name
//
// MessageId: MSG_NICE_PATH_START_UP
//
// MessageText:
//
//  %1</B> (on the Start menu)%0
//
#define MSG_NICE_PATH_START_UP           0x000000D1L

// %1 - link name
//
// MessageId: MSG_NICE_PATH_TEMPLATES
//
// MessageText:
//
//  %1</B> (in New Document Templates)%0
//
#define MSG_NICE_PATH_TEMPLATES          0x000000D2L

// %1 - link name
//
// MessageId: MSG_NICE_PATH_WIN_DIR
//
// MessageText:
//
//  %1</B> (in the Windows folder)%0
//
#define MSG_NICE_PATH_WIN_DIR            0x000000D3L

// %1 - link name
//
// MessageId: MSG_NICE_PATH_SYSTEM_DIR
//
// MessageText:
//
//  %1</B> (in the System folder)%0
//
#define MSG_NICE_PATH_SYSTEM_DIR         0x000000D4L

// %1 - link name
//
// MessageId: MSG_NICE_PATH_PROGRAM_FILES
//
// MessageText:
//
//  %1</B> (in Program Files)%0
//
#define MSG_NICE_PATH_PROGRAM_FILES      0x000000D5L

// %1 - link name
//
// MessageId: MSG_NICE_PATH_CONTROL_PANEL
//
// MessageText:
//
//  %1</B> (in Control Panel)%0
//
#define MSG_NICE_PATH_CONTROL_PANEL      0x000000D6L

// %1 - link name  %2 - last folder  %3 - drive
//
// MessageId: MSG_NICE_PATH_DRIVE_AND_FOLDER
//
// MessageText:
//
//  %1</B> (in %2 folder on drive %3)%0
//
#define MSG_NICE_PATH_DRIVE_AND_FOLDER   0x000000D7L

// %1 - link name  %2 - drive
//
// MessageId: MSG_NICE_PATH_DRIVE
//
// MessageText:
//
//  %1</B> (on drive %2)%0
//
#define MSG_NICE_PATH_DRIVE              0x000000D8L

// %1 - link name  %2 - last folder
//
// MessageId: MSG_NICE_PATH_FOLDER
//
// MessageText:
//
//  %1</B> (in %2 folder)%0
//
#define MSG_NICE_PATH_FOLDER             0x000000D9L

// %1 - link name
//
// MessageId: MSG_NICE_PATH_LINK
//
// MessageText:
//
//  %1%0
//
#define MSG_NICE_PATH_LINK               0x000000DAL

//
// MessageId: MSG_OFFLINE_DEVICE_PLAIN
//
// MessageText:
//
//  %1 (not currently present)%0
//
#define MSG_OFFLINE_DEVICE_PLAIN         0x000000DBL

//
// MessageId: MSG_386ENH_DRIVER_LOG
//
// MessageText:
//
//  Setup found the following obsolete drivers:
//  
//  %1
//
#define MSG_386ENH_DRIVER_LOG            0x000000DCL

//
// MessageId: MSG_UNKNOWN_OS
//
// MessageText:
//
//  The version of Windows running is not supported. Setup can only upgrade official releases. Setup will now exit.%0
//
#define MSG_UNKNOWN_OS                   0x000000DDL

// %1 - link name
//
// MessageId: MSG_NICE_PATH_SCREEN_SAVER
//
// MessageText:
//
//  %1</B> (current Screen Saver)%0
//
#define MSG_NICE_PATH_SCREEN_SAVER       0x000000DEL

//
// MessageId: MSG_RESTYPE_MEMORY
//
// MessageText:
//
//  Memory Range%0
//
#define MSG_RESTYPE_MEMORY               0x000000DFL

//
// MessageId: MSG_RESTYPE_IO
//
// MessageText:
//
//  Input/Output Range%0
//
#define MSG_RESTYPE_IO                   0x000000E0L

//
// MessageId: MSG_RESTYPE_DMA
//
// MessageText:
//
//  Direct Memory Access%0
//
#define MSG_RESTYPE_DMA                  0x000000E1L

//
// MessageId: MSG_RESTYPE_IRQ
//
// MessageText:
//
//  Interrupt Request%0
//
#define MSG_RESTYPE_IRQ                  0x000000E2L

//
// MessageId: MSG_FILE_NAME_FILTER
//
// MessageText:
//
//  HTML Files (*.htm)|*.htm|Text Files (*.txt)|*.txt|All Files (*.*)|*.*|%0
//
#define MSG_FILE_NAME_FILTER             0x000000E3L

// %1-device description %2-manufacturer %3-class %4-resource list
//
// MessageId: MSG_RESOURCE_HEADER_LOG
//
// MessageText:
//
//  The following settings may be needed to install the device on Windows XP.
//  
//    Device: %1
//    Manufacturer: %2
//    Device Class: %3
//    Resources:
//  %4
//
#define MSG_RESOURCE_HEADER_LOG          0x000000E4L

// %1-resource type (i.e., IRQ)  %2-resource value
// IMPORTANT: The number between the exclaimation points (i.e., 22 on US) must be
//            greater than length of the MSG_RESTYPE constants above.
//
// MessageId: MSG_RESOURCE_ITEM_LOG
//
// MessageText:
//
//      %1!-22s!%2
//
#define MSG_RESOURCE_ITEM_LOG            0x000000E5L

//
// MessageId: MSG_AUTO_DMA
//
// MessageText:
//
//  Auto
//
#define MSG_AUTO_DMA                     0x000000E6L

// %1 - virus application name
//
// MessageId: MSG_BAD_VIRUS_SCANNER
//
// MessageText:
//
//  Setup has determined that you are running the %1 program. This program can cause problems while installing Windows XP. You must disable this program before running Setup.
//  
//  To stop the program and continue with Setup, click End Task.%0
//
#define MSG_BAD_VIRUS_SCANNER            0x000000E7L

// %1 - system drive letter, %2 - space to be freed, %3 - ~ls size, %4 - non-system drive option requirment, in mb, %5 - backup image size
//
// MessageId: MSG_NOT_ENOUGH_DISK_SPACE_WITH_BACKUP
//
// MessageText:
//
//  Your computer does not have enough free disk space to install Windows XP. You need at least %2 MB free on drive %1. If you want to be able to undo the upgrade, a backup will require %5 MB more.%0
//
#define MSG_NOT_ENOUGH_DISK_SPACE_WITH_BACKUP 0x000000E8L

//
// MessageId: MSG_NOT_ENOUGH_DISKSPACE_SUBGROUP
//
// MessageText:
//
//  Disk Space%0
//
#define MSG_NOT_ENOUGH_DISKSPACE_SUBGROUP 0x000000E9L

// %1 - system drive letter, %2 - space to be freed, %3 - ~ls size, %4 - non-system drive option requirment, in mb, %5 - backup image size
//
// MessageId: MSG_NOT_ENOUGH_DISK_SPACE
//
// MessageText:
//
//  Your computer does not have enough free disk space to install Windows XP. You need at least %2 MB free on drive %1.%0
//
#define MSG_NOT_ENOUGH_DISK_SPACE        0x000000EAL

// network domain account create
//
// MessageId: MSG_USER_IS_BOGUS
//
// MessageText:
//
//  The specified user name is not valid.
//  
//  Contact your network administrator for information on creating a computer account.%0
//
#define MSG_USER_IS_BOGUS                0x000000EBL

// network domain account create
//
// MessageId: MSG_USER_IS_CURRENT_USER
//
// MessageText:
//
//  Your user account must have permission to add computers to the domain.  Normally, only special accounts and network administrators have this permission.
//  
//  Are you sure you have permission to add computer accounts to the domain?%0
//
#define MSG_USER_IS_CURRENT_USER         0x000000ECL

//
// MessageId: MSG_CONTACT_NET_ADMIN
//
// MessageText:
//
//  Contact your network administrator for assistance with your computer account before continuing the upgrade to Windows XP.%0
//
#define MSG_CONTACT_NET_ADMIN            0x000000EDL

//
// MessageId: MSG_KILL_APPLICATION
//
// MessageText:
//
//  &End Task%0
//
#define MSG_KILL_APPLICATION             0x000000EEL

//
// MessageId: MSG_QUIT_SETUP
//
// MessageText:
//
//  &Quit Setup%0
//
#define MSG_QUIT_SETUP                   0x000000EFL

// Message when error 5, 32, 53, 54, 55, 65, 66, 67, 68, 88, 123, 148, 1203,
// 1222, 1231 or 2250 causes setup to die
//
// MessageId: MSG_ACCESS_DENIED
//
// MessageText:
//
//  Setup could not access one or more files. Possible causes of this error are:
//  
//  1. You do not have the correct network permissions
//  2. The network or CD-ROM is no longer accessible
//  3. A file might be locked by someone else on the network
//  
//  Please check your network or CD-ROM, then restart Setup.%0
//
#define MSG_ACCESS_DENIED                0x000000F0L

//
// MessageId: MSG_AUTODETECT_FRAMETYPE
//
// MessageText:
//
//  Setup could not directly map your IPX Frame Type. After the upgrade is complete, the frame type will be set to auto detect.%0
//
#define MSG_AUTODETECT_FRAMETYPE         0x000000F1L

// %1 - link name
//
// MessageId: MSG_NICE_PATH_RUN_KEY
//
// MessageText:
//
//  %1</B> (a startup program)%0
//
#define MSG_NICE_PATH_RUN_KEY            0x000000F2L

// This message is used to recommend a new computer name
// %1 - user name
//
// MessageId: MSG_COMPUTER_REPLACEMENT_NAME
//
// MessageText:
//
//  %1-COMP%0
//
#define MSG_COMPUTER_REPLACEMENT_NAME    0x000000F3L

// %1 - drive letter of media to eject (A, C, D, etc...)
//
// MessageId: MSG_REMOVE_DRIVER_DISK
//
// MessageText:
//
//  Remove the driver disk from drive %1, then click OK to continue.%0
//
#define MSG_REMOVE_DRIVER_DISK           0x000000F4L

// %1 - file names that could not be renamed and will be deleted
//
// MessageId: MSG_DIR_COLLISION_DELETE_LOG
//
// MessageText:
//
//  The following files will be deleted because of a collision with Windows XP folders:
//  %1%0
//
#define MSG_DIR_COLLISION_DELETE_LOG     0x000000F5L

// %1 - file name that could not be renamed
//
// MessageId: MSG_CANNOT_RENAME_FILE
//
// MessageText:
//
//  Setup cannot rename file %1. Please close all running applications then press Retry.%0
//
#define MSG_CANNOT_RENAME_FILE           0x000000F6L

// caption of the first button on Retry File Rename dialog
//
// MessageId: MSG_RETRY_RENAME
//
// MessageText:
//
//  &Retry Rename%0
//
#define MSG_RETRY_RENAME                 0x000000F7L

// C:\Documents and Settings
//
// MessageId: MSG_USER_PROFILE_ROOT
//
// MessageText:
//
//  %%SystemDrive%%\Documents and Settings%0
//
#define MSG_USER_PROFILE_ROOT            0x000000F8L

//
// MessageId: MSG_NO_NECESSARY_MODULES_FOUND
//
// MessageText:
//
//  Setup found upgrade packs in the selected folder, but they are not needed for your computer.%0
//
#define MSG_NO_NECESSARY_MODULES_FOUND   0x000000F9L

//
// MessageId: MSG_DEFAULT_WORKGROUP
//
// MessageText:
//
//  WORKGROUP%0
//
#define MSG_DEFAULT_WORKGROUP            0x000000FAL

//
// MessageId: MSG_DOMAIN_HELP
//
// MessageText:
//
//  You must obtain domain information from your network administrator in order to join this computer to a domain.%0
//
#define MSG_DOMAIN_HELP                  0x000000FBL

// %1 - minimum time estimate, %2 - maximum time estimate, %3 - current OS name
//
// MessageId: MSG_LAST_PAGE
//
// MessageText:
//
//  Setup is now ready to install Windows XP. The upgrade takes approximately %1 to %2 minutes, and your computer will restart three times.
//
#define MSG_LAST_PAGE                    0x000000FCL

// %1 - minimum time estimate, %2 - maximum time estimate, %3 - current OS name
//
// MessageId: MSG_LAST_PAGE_WITH_NTFS_CONVERSION
//
// MessageText:
//
//  Setup is now ready to install Windows XP. The upgrade takes approximately %1 to %2 minutes, plus additional time to convert to NTFS. Your computer will restart four times.
//
#define MSG_LAST_PAGE_WITH_NTFS_CONVERSION 0x000000FDL

// %1 - win95 name.
//
// MessageId: MSG_OTHER_OS_FOUND_EARLY_POPUP
//
// MessageText:
//
//  You cannot upgrade your %1 installation to Windows XP because you have more than one operating system installed on your computer. Upgrading one operating system can cause problems with files shared by the other operating system, and is therefore not permitted.%0
//
#define MSG_OTHER_OS_FOUND_EARLY_POPUP   0x000000FEL

//
// MessageId: MSG_CANCEL_BUTTON
//
// MessageText:
//
//  &Cancel%0
//
#define MSG_CANCEL_BUTTON                0x000000FFL

//
// MessageId: MSG_REVIEW_BUTTON
//
// MessageText:
//
//  &Review%0
//
#define MSG_REVIEW_BUTTON                0x00000100L

//
// MessageId: MSG_BLOCKING_FILE_BLOCK_UNATTENDED
//
// MessageText:
//
//  Setup has found programs installed on your computer that must be removed before an upgrade can be attempted. If you wish to review the upgrade report click Review. Otherwise, to quit setup click Quit.%0
//
#define MSG_BLOCKING_FILE_BLOCK_UNATTENDED 0x00000101L

//
// MessageId: MSG_BLOCKING_HARDWARE_BLOCK
//
// MessageText:
//
//  Because your computer has a hardware configuration that is not supported by Windows XP, you cannot continue. Setup will now exit.
//
#define MSG_BLOCKING_HARDWARE_BLOCK      0x00000102L

//
// MessageId: MSG_BLOCKING_HARDWARE_BLOCK_UNATTENDED
//
// MessageText:
//
//  Because your computer has a hardware configuration that is not supported by Windows XP, you cannot continue. If you wish to review the upgrade report click Review. Otherwise, to quit setup click Quit.%0
//
#define MSG_BLOCKING_HARDWARE_BLOCK_UNATTENDED 0x00000103L

//
// MessageId: MSG_QUIT_BUTTON
//
// MessageText:
//
//  &Quit%0
//
#define MSG_QUIT_BUTTON                  0x00000104L

//
// MessageId: MSG_UNEXPECTED_ERROR_ENCOUNTERED_NORC
//
// MessageText:
//
//  Setup cannot continue. Contact Microsoft Technical Support.
//
#define MSG_UNEXPECTED_ERROR_ENCOUNTERED_NORC 0x00000105L

//
// MessageId: MSG_PLEASE_SPECIFY_A_DOMAIN
//
// MessageText:
//
//  To join a domain, you must specify a domain name.
//
#define MSG_PLEASE_SPECIFY_A_DOMAIN      0x00000106L

//
// MessageId: MSG_FINISH
//
// MessageText:
//
//  Finish%0
//
#define MSG_FINISH                       0x00000107L

//
// MessageId: MSG_MILLENNIUM
//
// MessageText:
//
//  Windows Millennium Edition%0
//
#define MSG_MILLENNIUM                   0x00000108L

//
// MessageId: MSG_WIN95UPG_RELOAD_FAILED
//
// MessageText:
//
//  Setup failed to load the information file %1 and cannot continue.
//  
//  Contact Microsoft Technical Support.%0
//
#define MSG_WIN95UPG_RELOAD_FAILED       0x00000109L

//
// MessageId: MSG_NOT_ENOUGH_DISK_SPACE_FOR_BACKUP
//
// MessageText:
//
//  Your computer does not have enough disk space to save your current version of Windows for backup. You can cancel Setup now, free additional disk space, and then restart Setup.  You need at least %2 MB free space on drive %1.
//  
//  If you continue, you will not have the ability to uninstall Windows XP.
//  
//  Do you want to cancel Setup now to free additional disk space? (recommended)%0
//
#define MSG_NOT_ENOUGH_DISK_SPACE_FOR_BACKUP 0x0000010AL

//
// MessageId: MSG_DISK_SPACE
//
// MessageText:
//
//  %1 MB%0
//
#define MSG_DISK_SPACE                   0x0000010BL

//
// MessageId: MSG_DISK_AND_FREE_DISK_SPACE
//
// MessageText:
//
//  &%1 - %2 MB Free%0
//
#define MSG_DISK_AND_FREE_DISK_SPACE     0x0000010CL

//
// MessageId: MSG_LONG_BACKUP_PATH
//
// MessageText:
//
//  Length of PathForBackup is too long: %1%0
//
#define MSG_LONG_BACKUP_PATH             0x0000010DL

// Names that collide with NT, not used for display; separate names with pipe symbol (|)
//
// MessageId: MSG_NAME_COLLISION_LIST_PER
//
// MessageText:
//
//  Administrators|Account Operators|Anonymous Logon|Authenticated Users|Backup Operators|Batch|Creator Group|Creator Owner|DIALUP|Domain Admins|Domain Guests|Domain Users|Everyone|Guest|Guests|Owner|HelpAssistant|HelpServicesGroup|INTERACTIVE|LOCAL SERVICE|NETWORK|Network Configuration Operators|NETWORK SERVICE|None|Power Users|Print Operators|Remote Desktop Users|REMOTE INTERACTIVE LOGON|Replicator|Server Operators|SERVICE|SYSTEM|TERMINAL SERVER USER|TsInternetUser|Users|MTS Administrators|MTS Impersonators|MTS_ADMIN|IMDB Trusted Users|WBEM Users|IMDB Trusted Users|%0
//
#define MSG_NAME_COLLISION_LIST_PER      0x0000010EL

//
// MessageId: MSG_STOP_BECAUSE_CANT_BACK_UP
//
// MessageText:
//
//  There is not enough disk space on any disk to store a backup of the original operating system, and EnableBackup=Required was specified in the /unattend script. Setup cannot continue.%0
//
#define MSG_STOP_BECAUSE_CANT_BACK_UP    0x0000010FL

// %1 - path specified in unattend script
//
// MessageId: MSG_STOP_BECAUSE_CANT_BACK_UP_2
//
// MessageText:
//
//  There is not enough disk space on %1 to store a backup of the original operating system, and EnableBackup=Required was also specified in the /unattend script. Setup cannot continue.%0
//
#define MSG_STOP_BECAUSE_CANT_BACK_UP_2  0x00000110L

//
// MessageId: MSG_BAD_VIRUS_SCANNER_STOP
//
// MessageText:
//
//  Setup has determined that you are running the %1 program. This program can cause problems while installing Windows XP. You must disable or uninstall this program before continuing Setup.
//  Some programs can be uninstalled using Add or Remove Programs in Control Panel. To disable the program, refer to the program documentation.
//
#define MSG_BAD_VIRUS_SCANNER_STOP       0x00000111L

//
// MessageId: MSG_RESTART_IF_CONTINUE_APPWIZCPL
//
// MessageText:
//
//  You now have the opportunity to remove incompatible applications. If you proceed, Setup will restart when you press Next.
//  
//  Click Yes to run Add/Remove Programs
//  Click No to continue Setup
//
#define MSG_RESTART_IF_CONTINUE_APPWIZCPL 0x00000112L

//
// MessageId: MSG_REPORT_HEADER_BLOCKING_ISSUES_SHORT
//
// MessageText:
//
//  Setup found some blocking issues. You must address these issues before you can continue upgrading your computer. For more information, click Full Report.
//
#define MSG_REPORT_HEADER_BLOCKING_ISSUES_SHORT 0x00000113L

//
// MessageId: MSG_REPORT_HEADER_BLOCKING_ISSUES
//
// MessageText:
//
//  Setup found some blocking issues. You must address these issues before you can continue upgrading your computer. For more information, click Full Details.
//
#define MSG_REPORT_HEADER_BLOCKING_ISSUES 0x00000114L

//
// MessageId: MSG_INVALID_USERNAME_TRAILINGDOT_POPUP
//
// MessageText:
//
//  A name cannot end in a period.%0
//
#define MSG_INVALID_USERNAME_TRAILINGDOT_POPUP 0x00000115L

//
// MessageId: MSG_ALL_USERS
//
// MessageText:
//
//  All Users%0
//
#define MSG_ALL_USERS                    0x00000116L

//
// ####################################################################################
// #
// #  w95upgnt.dll messages
// #
// ####################################################################################
//
//
// MessageId: MSG_PROFILE_ERROR
//
// MessageText:
//
//  Setup cannot create a user profile for %1. This user account cannot be upgraded. After Setup completes, re-create the account.%0
//
#define MSG_PROFILE_ERROR                0x00001388L

//
// MessageId: MSG_MIGRATING_SHELL
//
// MessageText:
//
//  Upgrading desktop and Start menu...%0
//
#define MSG_MIGRATING_SHELL              0x00001389L

//
// MessageId: MSG_MIGRATING_PLATFORM_SETTINGS
//
// MessageText:
//
//  Upgrading %1 settings...%0
//
#define MSG_MIGRATING_PLATFORM_SETTINGS  0x0000138AL

//
// MessageId: MSG_MIGRATING_DEFAULT_USER
//
// MessageText:
//
//  Upgrading logon settings...%0
//
#define MSG_MIGRATING_DEFAULT_USER       0x0000138BL

//
// MessageId: MSG_MIGRATING_USER
//
// MessageText:
//
//  Upgrading user settings...%1%0
//
#define MSG_MIGRATING_USER               0x0000138CL

//
// MessageId: MSG_MIGRATED_ACCOUNT_DESCRIPTION
//
// MessageText:
//
//  Account upgraded from %1%0
//
#define MSG_MIGRATED_ACCOUNT_DESCRIPTION 0x0000138DL

//
// MessageId: MSG_UNABLE_TO_CREATE_SHARE
//
// MessageText:
//
//  Setup cannot share %2 as %1. After Setup completes, you should manually create this full-access share.%0
//
#define MSG_UNABLE_TO_CREATE_SHARE       0x0000138EL

//
// MessageId: MSG_UNABLE_TO_CREATE_RO_SHARE
//
// MessageText:
//
//  Setup cannot share %2 as %1. After Setup completes, you should manually create this read-only share.%0
//
#define MSG_UNABLE_TO_CREATE_RO_SHARE    0x0000138FL

//
// MessageId: MSG_UNABLE_TO_CREATE_ACL_SHARE
//
// MessageText:
//
//  Setup cannot share %2 as %1. After Setup completes, you should manually create this share and restore the user access list.%0
//
#define MSG_UNABLE_TO_CREATE_ACL_SHARE   0x00001390L

// %1 - user name, %2 - share name, %3 - share path
//
// MessageId: MSG_NO_USER_SID
//
// MessageText:
//
//  Because Setup could not locate an account for %1, the account was removed from the share %2 (%3). After Setup completes, you should manually add this account to the share.%0
//
#define MSG_NO_USER_SID                  0x00001391L

// %1 - share name, %2 - share path
//
// MessageId: MSG_ALL_SIDS_BAD
//
// MessageText:
//
//  Setup cannot locate any accounts for the %1 share (%2). The Setup log contains a list of accounts for %1. After Setup completes, you should manually add accounts to the share.%0
//
#define MSG_ALL_SIDS_BAD                 0x00001392L

//
// MessageId: MSG_MANY_SIDS_BAD
//
// MessageText:
//
//  
//  Setup cannot locate %1!u! of %2!u! accounts for the %3 share (%4). The Setup log contains a list of accounts that could not be added to %1. After Setup completes, you should manually add these accounts to the share.%0
//
#define MSG_MANY_SIDS_BAD                0x00001393L

// %1 - product ID, %2 - ?, %3 - function
//
// MessageId: MSG_EXCEPTION_MIGRATE_INIT_NT
//
// MessageText:
//
//  The module for %1 failed unexpectedly during initialization.%0
//
#define MSG_EXCEPTION_MIGRATE_INIT_NT    0x00001394L

//
// MessageId: MSG_EXCEPTION_MIGRATE_USER_NT
//
// MessageText:
//
//  The module for %1 failed unexpectedly while processing %3.%0
//
#define MSG_EXCEPTION_MIGRATE_USER_NT    0x00001395L

//
// MessageId: MSG_EXCEPTION_MIGRATE_SYSTEM_NT
//
// MessageText:
//
//  The module for %1 failed unexpectedly while processing the system settings.%0
//
#define MSG_EXCEPTION_MIGRATE_SYSTEM_NT  0x00001396L

//
// MessageId: MSG_PROCESSING_MIGRATION_DLLS
//
// MessageText:
//
//  Processing upgrade packs...%0
//
#define MSG_PROCESSING_MIGRATION_DLLS    0x00001397L

//
// MessageId: MSG_MIGRATING_ADMINISTRATOR
//
// MessageText:
//
//  Upgrading Administrator account...%0
//
#define MSG_MIGRATING_ADMINISTRATOR      0x00001398L

// %1 - Dospath
//
// MessageId: MSG_BOOT16_STARTUP_COMMENT
//
// MessageText:
//
//  ECHO You are using automatically generated configuration files.
//  ECHO Your original configuration files have been renamed
//  ECHO Config.upg and Autoexec.upg and are located in the %1 Directory.
//  ECHO.
//
#define MSG_BOOT16_STARTUP_COMMENT       0x00001399L

// %1 - Product Name
// %2 - Company Name
// %3 - Support Phone (with line break), see MSG_MIGDLL_SUPPORT_PHONE_FIXUP
// %4 - Support URL (with line break), see MSG_MIGDLL_SUPPORT_URL_FIXUP
// %5 - Instructions to user from DLL (with line break), see MSG_MIGDLL_INSTRUCTIONS_FIXUP
// %6 - Line break if either %3, %4 or %5 is not empty
//
// MessageId: MSG_CREATE_PROCESS_ERROR
//
// MessageText:
//
//  Setup cannot process the %1 upgrade pack from %2.%6%5%3%4
//
#define MSG_CREATE_PROCESS_ERROR         0x0000139AL

// %1 - Product Name
// %2 - Company Name
// %3 - Support Phone (with line break), see MSG_MIGDLL_SUPPORT_PHONE_FIXUP
// %4 - Support URL (with line break), see MSG_MIGDLL_SUPPORT_URL_FIXUP
// %5 - Instructions to user from DLL (with line break), see MSG_MIGDLL_INSTRUCTIONS_FIXUP
// %6 - Line break if either %3, %4 or %5 is not empty
//
// MessageId: MSG_MIGDLL_ERROR
//
// MessageText:
//
//  Setup cannot process the %1 upgrade pack from %2.%6%5%3%4
//
#define MSG_MIGDLL_ERROR                 0x0000139BL

//
// MessageId: MSG_DEFAULT_MIGDLL_DESC
//
// MessageText:
//
//  (unknown program)%0
//
#define MSG_DEFAULT_MIGDLL_DESC          0x0000139CL

// %1 - Windows 95 or Windows 98
//
// MessageId: MSG_MIGRATION_IS_TOAST
//
// MessageText:
//
//  Setup cannot upgrade some settings. After Setup completes, you may need to reinstall one or more programs.%0
//
#define MSG_MIGRATION_IS_TOAST           0x0000139DL

//
// MessageId: MSG_SYSTEM_DIR
//
// MessageText:
//
//  SYSTEM%0
//
#define MSG_SYSTEM_DIR                   0x0000139EL

//
// MessageId: MSG_PROGRAM_FILES_DIR
//
// MessageText:
//
//  c:\Program Files%0
//
#define MSG_PROGRAM_FILES_DIR            0x0000139FL

//
// MessageId: MSG_DMNT_APPENDSTRING
//
// MessageText:
//
//  
//  REM
//  REM *************************************************
//  REM ** Lines below this have been migrated from the
//  REM ** original %1 settings.
//  REM *************************************************
//  REM
//  
//  %0
//
#define MSG_DMNT_APPENDSTRING            0x000013A0L

//
// MessageId: MSG_GETANYDC_RETRY
//
// MessageText:
//
//  Setup cannot locate a server for the %1 domain. To upgrade one or more users, Setup needs a server connection. Would you like Setup to search again?%0
//
#define MSG_GETANYDC_RETRY               0x000013A1L

//
// MessageId: MSG_ALL_USERS_ARE_LOCAL
//
// MessageText:
//
//  Because this computer is not joined to a domain, Setup cannot upgrade your domain accounts. Setup will create accounts that do not have domain access.%0
//
#define MSG_ALL_USERS_ARE_LOCAL          0x000013A2L

//
// MessageId: MSG_GETPRIMARYDC_RETRY
//
// MessageText:
//
//  Setup is trying to determine if any user accounts are on the %1 domain, but the domain is not responding.  Would you like Setup to try again?%0
//
#define MSG_GETPRIMARYDC_RETRY           0x000013A3L

//
// MessageId: MSG_NULSESSION_RETRY
//
// MessageText:
//
//  Setup cannot connect to server %1 of the %2 domain. This connection is necessary for the correct upgrade of users who log on to %2.
//  
//  Would you like Setup to try again, connecting to another server if possible?%0
//
#define MSG_NULSESSION_RETRY             0x000013A4L

//
// MessageId: MSG_SID_RETRY
//
// MessageText:
//
//  Setup cannot obtain security settings for %1. Would you like Setup to try again?%0
//
#define MSG_SID_RETRY                    0x000013A5L

//
// MessageId: MSG_CREATE_ACCOUNT_FAILED
//
// MessageText:
//
//  Setup encountered an error while creating an account for %1. This user's settings will be lost.%0
//
#define MSG_CREATE_ACCOUNT_FAILED        0x000013A6L

//
// MessageId: MSG_SID_LOOKUP_FAILED
//
// MessageText:
//
//  Setup encountered an error while obtaining the security identifier for %1. This user's settings will be lost.%0
//
#define MSG_SID_LOOKUP_FAILED            0x000013A7L

//
// MessageId: MSG_SEARCHING_DOMAINS
//
// MessageText:
//
//  Looking up network user accounts...%0
//
#define MSG_SEARCHING_DOMAINS            0x000013A8L

//
// MessageId: MSG_SEARCHING_A_DOMAIN
//
// MessageText:
//
//  Looking up accounts in the %1 domain...%0
//
#define MSG_SEARCHING_A_DOMAIN           0x000013A9L

//
// MessageId: MSG_USER_SINGULAR
//
// MessageText:
//
//  user%0
//
#define MSG_USER_SINGULAR                0x000013AAL

//
// MessageId: MSG_USERS_PLURAL
//
// MessageText:
//
//  users%0
//
#define MSG_USERS_PLURAL                 0x000013ABL

//
// MessageId: MSG_ACCOUNT_RESOLVE_INSTRUCTIONS_SINGULAR
//
// MessageText:
//
//  A network account could not be determined for %1 user. Select an action to take for this user.%0
//
#define MSG_ACCOUNT_RESOLVE_INSTRUCTIONS_SINGULAR 0x000013ACL

//
// MessageId: MSG_ACCOUNT_RESOLVE_INSTRUCTIONS_PLURAL
//
// MessageText:
//
//  A network account could not be determined for %1 users. Select an action to take for each user.%0
//
#define MSG_ACCOUNT_RESOLVE_INSTRUCTIONS_PLURAL 0x000013ADL

//
// STF processing:
//    %1 is STF file path
//    %2 is INF file path associated with STF (for MSG_STF_MISSING_INF_LOG only)
//
//
// MessageId: MSG_COULD_NOT_PROCESS_STF_LOG
//
// MessageText:
//
//  Windows XP Setup cannot process the file %1. You may encounter problems uninstalling or reinstalling programs that need this file.%0
//
#define MSG_COULD_NOT_PROCESS_STF_LOG    0x000013AEL

//
// MessageId: MSG_STF_MISSING_INF_LOG
//
// MessageText:
//
//  Windows XP Setup could perform only limited processing on %1 because %2 is missing. You may encounter problems uninstalling or reinstalling programs that need this file.%0
//
#define MSG_STF_MISSING_INF_LOG          0x000013AFL

//
// Account names
//
//
// MessageId: MSG_EVERYONE_GROUP
//
// MessageText:
//
//  Everyone%0
//
#define MSG_EVERYONE_GROUP               0x000013B0L

//
// MessageId: MSG_ADMINISTRATORS_GROUP
//
// MessageText:
//
//  Administrators%0
//
#define MSG_ADMINISTRATORS_GROUP         0x000013B1L

//
// MessageId: MSG_DOMAIN_USERS_GROUP
//
// MessageText:
//
//  Domain Users%0
//
#define MSG_DOMAIN_USERS_GROUP           0x000013B2L

//
// MessageId: MSG_NONE_GROUP
//
// MessageText:
//
//  none%0
//
#define MSG_NONE_GROUP                   0x000013B3L

//
// INI file mapping
//
//
// MessageId: MSG_INI_FILE_MAPPING_LOG
//
// MessageText:
//
//  At least one error occurred while processing the INI file settings. Some 16-bit programs may function incorrectly after the upgrade.
//
#define MSG_INI_FILE_MAPPING_LOG         0x000013B4L

//
// MessageId: MSG_INI_FILE_CONVERSION_LOG
//
// MessageText:
//
//  At least one error occurred while converting INI files. Some 16-bit programs may function incorrectly after the upgrade.
//
#define MSG_INI_FILE_CONVERSION_LOG      0x000013B5L

//
// MessageId: MSG_UNABLE_TO_MIGRATE_TAPI_DIALING_LOCATIONS
//
// MessageText:
//
//  At least one error occurred while upgrading dialing locations. After the upgrade is complete, you may need to reset your area code and other dialing options.
//
#define MSG_UNABLE_TO_MIGRATE_TAPI_DIALING_LOCATIONS 0x000013B6L

//
// MessageId: MSG_ERROR_MIGRATING_PHONEBOOK_ENTRIES
//
// MessageText:
//
//  At least one error occurred while upgrading the phonebook entries for %1. You may need to recreate some phonebook entries for this user.
//
#define MSG_ERROR_MIGRATING_PHONEBOOK_ENTRIES 0x000013B7L

//
// MessageId: MSG_PROFILE_LOOKUP_FAILED
//
// MessageText:
//
//  Setup encountered an error while obtaining the profile folder for %1. This user's settings will be lost.%0
//
#define MSG_PROFILE_LOOKUP_FAILED        0x000013B8L

// %1 - file path %2 - error code (unsigned int)
//
// MessageId: MSG_COULD_NOT_MOVE_FILE_LOG
//
// MessageText:
//
//  Setup encountered an error while processing %1. Error code: %2!u!%0
//
#define MSG_COULD_NOT_MOVE_FILE_LOG      0x000013B9L

//
// Messages that are out of order (because of localization tool constraints)
//
// Title for NT Domain Resolution dialog
//
// %1 - user name
//
// MessageId: MSG_USER_DOMAIN_LOGON_DLG
//
// MessageText:
//
//  Domains: (for %1)%0
//
#define MSG_USER_DOMAIN_LOGON_DLG        0x000013BAL

// Text that appears in the NT Domain Resolution dialog, a user option in a combo box
//
// MessageId: MSG_DOMAIN_NOT_LISTED_DLG
//
// MessageText:
//
//  (Search again)%0
//
#define MSG_DOMAIN_NOT_LISTED_DLG        0x000013BBL

// Text that appears in the NT Domain Resolution dialog, a user option in a combo box
//
// MessageId: MSG_LOCAL_ACCOUNT_DLG
//
// MessageText:
//
//  (Local account)%0
//
#define MSG_LOCAL_ACCOUNT_DLG            0x000013BCL

// Status text, %1 - current domain name, %2 - current domain number (UINT), %3 - total domains (UINT)
//
// MessageId: MSG_DOMAIN_STATUS_POPUP
//
// MessageText:
//
//  Processing domain %1 (%2!u! of %3!u!)%0
//
#define MSG_DOMAIN_STATUS_POPUP          0x000013BDL

// Initial message for domain lookup status popup
//
// MessageId: MSG_INITIAL_STATUS_MSG
//
// MessageText:
//
//  Building a list of domains%0
//
#define MSG_INITIAL_STATUS_MSG           0x000013BEL

// Power Users local group
//
// MessageId: MSG_POWER_USERS_GROUP
//
// MessageText:
//
//  Power Users%0
//
#define MSG_POWER_USERS_GROUP            0x000013BFL

// Error migrating a briefcase, %1 - Briefcase Directory
//
// MessageId: MSG_ERROR_MIGRATING_BRIEFCASE
//
// MessageText:
//
//  An error occured while converting briefcase %1%0
//
#define MSG_ERROR_MIGRATING_BRIEFCASE    0x000013C0L

//
// MessageId: MSG_OWNERS_GROUP
//
// MessageText:
//
//  Owners%0
//
#define MSG_OWNERS_GROUP                 0x000013C1L

//
// MessageId: MSG_UNINSTALL_DISPLAY_STRING
//
// MessageText:
//
//  Windows XP Uninstall%0
//
#define MSG_UNINSTALL_DISPLAY_STRING     0x000013C2L

// %1 - Boot.ini path, %2 - Boot.~t path
//
// MessageId: MSG_BOOT_INI_MOVE_FAILED
//
// MessageText:
//
//  Unable to move %1 to %2%0
//
#define MSG_BOOT_INI_MOVE_FAILED         0x000013C3L

// %1 - Boot.ini path
//
// MessageId: MSG_BOOT_INI_SAVE_FAILED
//
// MessageText:
//
//  Unable to save %1%0
//
#define MSG_BOOT_INI_SAVE_FAILED         0x000013C4L

// %1 - temp dir path
//
// MessageId: MSG_LEFT_TEMP_SHELL_FOLDERS
//
// MessageText:
//
//  Because of errors during processing, documents and other files were left in %1.%0
//
#define MSG_LEFT_TEMP_SHELL_FOLDERS      0x000013C5L

//
// MessageId: MSG_OPTIONS_CLEANER
//
// MessageText:
//
//  These files are the installation files for Windows 98 or Windows ME. They came pre-installed on your computer. You can remove them if you do not plan to install Windows 98/ME again.%0
//
#define MSG_OPTIONS_CLEANER              0x000013C6L

//
// MessageId: MSG_OPTIONS_CLEANER_TITLE
//
// MessageText:
//
//  Windows 98/ME Installation Files%0
//
#define MSG_OPTIONS_CLEANER_TITLE        0x000013C7L

//
// MessageId: MSG_EMPTY_MYDOCS_TITLE
//
// MessageText:
//
//  Where did my files go.txt%0
//
#define MSG_EMPTY_MYDOCS_TITLE           0x000013C8L

//
// MessageId: MSG_EMPTY_MYDOCS_TEXT
//
// MessageText:
//
//  In Windows 98 and Windows Millennium Edition, two or more users
//  could save their files to the same location--My Documents. In
//  Windows XP, a new feature allows all users on the computer to
//  share documents by saving them to a folder called Shared
//  Documents. As part of the upgrade process, Setup moved your
//  documents to this new folder.
//  
//  To find your documents, go to My Computer and double-click the
//  Shared Documents folder. In the future, whenever you want to share
//  files with other users on this computer, just copy the files to
//  Shared Documents.
//  
//
#define MSG_EMPTY_MYDOCS_TEXT            0x000013C9L

//
// ####################################################################################
// #
// #  Common Messages
// #
// ####################################################################################
//
//
// MessageId: MSG_MESSAGEBOX_TITLE
//
// MessageText:
//
//  Windows XP Setup%0
//
#define MSG_MESSAGEBOX_TITLE             0x00002710L

//
// MessageId: MSG_OUT_OF_MEMORY_RETRY
//
// MessageText:
//
//  Setup needs more memory.  Close all open programs and click Retry.  If there are no other programs open, click Cancel to quit Setup.%0
//
#define MSG_OUT_OF_MEMORY_RETRY          0x00002711L

//
// MessageId: MSG_OUT_OF_MEMORY
//
// MessageText:
//
//  Your computer needs more memory for Setup to continue.%0
//
#define MSG_OUT_OF_MEMORY                0x00002712L

//
// MessageId: MSG_ERROR
//
// MessageText:
//
//  Error%0
//
#define MSG_ERROR                        0x00002713L

// ***
// *** Migration DLL support info fixups (used when DLL
// *** provides non-empty strings)
// ***
// %1 - Support Phone
//
// MessageId: MSG_MIGDLL_SUPPORT_PHONE_FIXUP
//
// MessageText:
//
//  
//  Support Phone: %1
//
#define MSG_MIGDLL_SUPPORT_PHONE_FIXUP   0x00002714L

// %1 - Support URL
//
// MessageId: MSG_MIGDLL_SUPPORT_URL_FIXUP
//
// MessageText:
//
//  
//  Support on the Internet: %1
//
#define MSG_MIGDLL_SUPPORT_URL_FIXUP     0x00002715L

// %1 - Instructions
//
// MessageId: MSG_MIGDLL_INSTRUCTIONS_FIXUP
//
// MessageText:
//
//  
//  %1
//
#define MSG_MIGDLL_INSTRUCTIONS_FIXUP    0x00002716L

// ***
// *** Windows platform names
// ***
//
// MessageId: MSG_SHORT_OS_NAME
//
// MessageText:
//
//  Windows%0
//
#define MSG_SHORT_OS_NAME                0x00002717L

//
// MessageId: MSG_NORMAL_OS_NAME
//
// MessageText:
//
//  Windows XP%0
//
#define MSG_NORMAL_OS_NAME               0x00002718L

//
// MessageId: MSG_FULL_OS_NAME
//
// MessageText:
//
//  Windows XP%0
//
#define MSG_FULL_OS_NAME                 0x00002719L

//
// MessageId: MSG_ADMINISTRATOR_ACCOUNT
//
// MessageText:
//
//  Administrator%0
//
#define MSG_ADMINISTRATOR_ACCOUNT        0x0000271AL

// ***
// *** Messages that are out of place
// ***
// *** This is because localization tools cannot deal with symbol renumbering
// ***
//
// ####################################################################################
// #
// #  migration report messages
// #
// ####################################################################################
//
//
// Text for migration report
//
// There are messages for the following message groups:
//
//     Hardware
//     General Information
//     Settings That Will Not Be Upgraded
//     Program Compatibility Not Known
//     Software Designed for MS-DOS
//     Software Incompatible with Windows XP
//     Software That Must Be Reinstalled
//     Software to Be Removed by Setup
//     Notes About Your Other Software
//     Other Upgrade Information
//
// All text has a plain version and an HTML version. The plain version
// is used for Save As and Print, while the HTML version is used for
// the UI.
//
//***************************************************************************
//
// General Instructions
//
//***************************************************************************
// Text at the top of the report
//
// MessageId: MSG_REPORT_GENERAL_INSTRUCTIONS
//
// MessageText:
//
//  Upgrade Report
//  --------------
//  Setup found hardware or software on your computer that might not or will not work with Windows XP. You should read and understand this upgrade report before continuing.
//  
//
#define MSG_REPORT_GENERAL_INSTRUCTIONS  0x00004E20L

//
// MessageId: MSG_REPORT_GENERAL_INSTRUCTIONS_HTML
//
// MessageText:
//
//  Setup found hardware or software on your computer that might not or will not work with Windows XP. You should read and understand this upgrade report before continuing.<P>
//
#define MSG_REPORT_GENERAL_INSTRUCTIONS_HTML 0x00004E21L

//
// MessageId: MSG_REPORT_GENERAL_INSTRUCTIONS_END
//
// MessageText:
//
//  Setup has detected that some hardware or programs on your computer might not function correctly after the upgrade is completed. This lack of functionality can have an effect on things you might want to do, such as connecting to the Internet, accessing e-mail, printing, scanning, and playing sounds or music. It is important that you read and understand this upgrade report before continuing. To resolve some of these issues, you can get more information at %1 on the Web.
//  
//
#define MSG_REPORT_GENERAL_INSTRUCTIONS_END 0x00004E22L

//
// MessageId: MSG_REPORT_GENERAL_INSTRUCTIONS_END_HTML
//
// MessageText:
//
//  Setup has detected that some hardware or programs on your computer might not function correctly after the upgrade is completed. This lack of functionality can have an effect on things you might want to do, such as connecting to the Internet, accessing e-mail, printing, scanning, and playing sounds or music. It is important that you read and understand this upgrade report before continuing. To resolve some of these issues, you can get more information at %1 on the Web.
//  <P>
//
#define MSG_REPORT_GENERAL_INSTRUCTIONS_END_HTML 0x00004E23L

//***************************************************************************
//
// Hardware
//
//***************************************************************************
//
// MessageId: MSG_INCOMPATIBLE_HARDWARE_ROOT
//
// MessageText:
//
//  Hardware%0
//
#define MSG_INCOMPATIBLE_HARDWARE_ROOT   0x00004E24L

//
// If incompatible hardware was found... text goes at top, then a list of devices, then text at bottom.
// MSG_HARDWARE_INSTRUCTIONS  -- text for the top
// MSG_HARDWARE_INSTRUCTIONS2 -- text for the bottom
//
//
// MessageId: MSG_HARDWARE_PNP_INSTRUCTIONS
//
// MessageText:
//
//  Hardware That Might Need Additional Files
//  
//  The following hardware might need additional files in order to work with Windows XP. Contact your hardware vendors to obtain Windows XP compatible updates. In many cases, if a Windows XP version is not yet available, a Windows 2000 compatible update should work. It is recommended that you obtain these drivers in advance.
//  
//  You can also view the Microsoft Windows XP Hardware Compatibility List at:
//  
//  http://www.microsoft.com/isapi/redir.dll?Prd=Whistler&Ar=Help&Sba=compatible
//  
//  Please note that some of the following entries might be software that is registered as hardware.
//  
//
#define MSG_HARDWARE_PNP_INSTRUCTIONS    0x00004E25L

//
// MessageId: MSG_HARDWARE_PNP_INSTRUCTIONS_HTML
//
// MessageText:
//
//  <UL><B>Hardware That Might Need Additional Files</B><BR>
//  The following hardware might need additional files in order to work with Windows XP. Contact your hardware vendors to obtain Windows XP compatible updates. In many cases, if a Windows XP version is not yet available, a Windows 2000 compatible update should work. It is recommended that you obtain these drivers in advance.<P>
//  You can also view the <A HREF="http://www.microsoft.com/isapi/redir.dll?Prd=Whistler&Ar=Help&Sba=compatible">Microsoft Windows XP Hardware Compatibility List</A> on the Web.<P>
//  Please note that some of the following entries might be software that is registered as hardware.
//  <P>
//
#define MSG_HARDWARE_PNP_INSTRUCTIONS_HTML 0x00004E26L

//
// MessageId: MSG_HARDWARE_PNP_INSTRUCTIONS2
//
// MessageText:
//
//  %0
//
#define MSG_HARDWARE_PNP_INSTRUCTIONS2   0x00004E27L

//
// MessageId: MSG_HARDWARE_PNP_INSTRUCTIONS2_HTML
//
// MessageText:
//
//  </UL>
//
#define MSG_HARDWARE_PNP_INSTRUCTIONS2_HTML 0x00004E28L

//***************************************************************************
//
// General Information
//
//***************************************************************************
//
// MessageId: MSG_INSTALL_NOTES_ROOT
//
// MessageText:
//
//  General Information%0
//
#define MSG_INSTALL_NOTES_ROOT           0x00004E29L

//
// MessageId: MSG_INSTALL_NOTES_INTRO
//
// MessageText:
//
//  General Information
//  -------------------
//  This section provides important information that you need to be aware of before you upgrade.
//  
//
#define MSG_INSTALL_NOTES_INTRO          0x00004E2AL

//
// MessageId: MSG_INSTALL_NOTES_INTRO_HTML
//
// MessageText:
//
//  <B>General Information</B><BR>
//  This section provides important information that you need to be aware of before you upgrade.
//  <P>
//
#define MSG_INSTALL_NOTES_INTRO_HTML     0x00004E2BL

// ***
// *** Name changes
// ***
//
// MessageId: MSG_REPORT_NAMECHANGE
//
// MessageText:
//
//  Name Changes
//  
//  The following names will change during the upgrade to Windows XP:
//  
//
#define MSG_REPORT_NAMECHANGE            0x00004E2CL

//
// MessageId: MSG_REPORT_NAMECHANGE_HTML
//
// MessageText:
//
//  <UL><B>Name Changes</B><BR>
//  The following names will change during the upgrade to Windows XP:
//  <P>
//  <UL>%0
//
#define MSG_REPORT_NAMECHANGE_HTML       0x00004E2DL

// Remind user they changed some names. %1-name group  %2-old name  %3-new name
//
// MessageId: MSG_NAMECHANGE_WARNING_GROUP
//
// MessageText:
//
//  Name Changes%0
//
#define MSG_NAMECHANGE_WARNING_GROUP     0x00004E2EL

// Remind user they changed some names. %1-name group  %2-old name  %3-new name
//
// MessageId: MSG_NAMECHANGE_WARNING_SUBCOMPONENT
//
// MessageText:
//
//  %2</B> will become <B>%3%0
//
#define MSG_NAMECHANGE_WARNING_SUBCOMPONENT 0x00004E2FL

// ***
// *** DOS Items
// ***
//
// MessageId: MSG_DOS_WARNING
//
// MessageText:
//
//  One or more entries in your MS-DOS configuration files (Autoexec.bat and Config.sys) are incompatible with Windows XP. These entries might be associated with older hardware or software that is incompatible with Windows XP. More technical information is provided in the Setupact.log file, located in your Windows folder.%0
//
#define MSG_DOS_WARNING                  0x00004E30L

//
// MessageId: MSG_DOS_WARNING_SUBGROUP
//
// MessageText:
//
//  DOS Configuration%0
//
#define MSG_DOS_WARNING_SUBGROUP         0x00004E31L

//
// MessageId: MSG_UNKNOWNDOS_WARNING_GROUP
//
// MessageText:
//
//  Unknown DOS%0
//
#define MSG_UNKNOWNDOS_WARNING_GROUP     0x00004E32L

//
// MessageId: MSG_UNKNOWNDOS_WARNING_SUBCOMPONENT
//
// MessageText:
//
//  Line %1 of %2
//
#define MSG_UNKNOWNDOS_WARNING_SUBCOMPONENT 0x00004E33L

// ***
// *** Network Shares
// ***
//
// MessageId: MSG_NET_SHARES_SUBGROUP
//
// MessageText:
//
//  Network Shares%0
//
#define MSG_NET_SHARES_SUBGROUP          0x00004E34L

// Incompatible setting: NT does not allow passwords on shares.  %1 - specifies share name
//
// MessageId: MSG_LOST_SHARE_PASSWORDS
//
// MessageText:
//
//  Share %1 requires a password. Windows XP uses user-level access rights instead of passwords.
//  
//  Setup will create the %1 share and set the permissions to deny all user access. After Setup completes, you can modify the permissions by right-clicking the folder and then clicking Properties.
//
#define MSG_LOST_SHARE_PASSWORDS         0x00004E35L

// Incompatible setting: NT has a much simpler UI and does not allow such granular access settings.  %1 - specifies share name  %2 - specifies full path
//
// MessageId: MSG_LOST_ACCESS_FLAGS
//
// MessageText:
//
//  Windows XP does not support the custom access permissions on share %1 (path: %2). Setup will create the folder and set the highest security level for access to the folder. After Setup completes, you can modify the permissions by right-clicking the folder and then clicking Properties.%0
//
#define MSG_LOST_ACCESS_FLAGS            0x00004E36L

// On some Win95 machines, the ACL APIs fail. This is a bug in Win9x and there is no workaround.  %1 - specifies share name
//
// MessageId: MSG_INVALID_ACL_LIST
//
// MessageText:
//
//  Setup encountered a problem reading the access permissions on share %1 (path: %2). After Setup completes, you can set the folder properties by right-clicking the folder and then clicking Properties.%0
//
#define MSG_INVALID_ACL_LIST             0x00004E37L

// ***
// *** Directory Collision
// ***
// Folders that will be renamed because of a collision with Win2000 folders
//
// MessageId: MSG_DIRECTORY_COLLISION_SUBGROUP
//
// MessageText:
//
//  Folder Name Changes%0.
//
#define MSG_DIRECTORY_COLLISION_SUBGROUP 0x00004E38L

// Introduction
//
// MessageId: MSG_DIRECTORY_COLLISION_INTRO
//
// MessageText:
//
//  Because two folders have the same name, Setup will rename them as follows:
//  
//
#define MSG_DIRECTORY_COLLISION_INTRO    0x00004E39L

// ***
// *** Drive type check
// ***
// Compressed, unknown drive types
//
// MessageId: MSG_DRIVE_INACCESSIBLE_SUBGROUP
//
// MessageText:
//
//  Inaccessible Drives%0
//
#define MSG_DRIVE_INACCESSIBLE_SUBGROUP  0x00004E3AL

//
// MessageId: MSG_DRIVE_INACCESSIBLE_INTRO
//
// MessageText:
//
//  Inaccessible Drives
//  
//  Setup cannot upgrade programs on the following drives:
//  
//
#define MSG_DRIVE_INACCESSIBLE_INTRO     0x00004E3BL

// EXCLUDE.INF excluded drives
//
// MessageId: MSG_DRIVE_EXCLUDED_SUBGROUP
//
// MessageText:
//
//  Excluded Drives%0
//
#define MSG_DRIVE_EXCLUDED_SUBGROUP      0x00004E3CL

//
// MessageId: MSG_DRIVE_EXCLUDED_INTRO
//
// MessageText:
//
//  Excluded Drives
//  
//  Setup will not look for programs on the following drives, because they have been excluded:
//  
//
#define MSG_DRIVE_EXCLUDED_INTRO         0x00004E3DL

// Network drives
//
// MessageId: MSG_DRIVE_NETWORK_SUBGROUP
//
// MessageText:
//
//  Network Drives%0
//
#define MSG_DRIVE_NETWORK_SUBGROUP       0x00004E3EL

//
// MessageId: MSG_DRIVE_NETWORK_INTRO
//
// MessageText:
//
//  Network Drives
//  
//  Setup will not look for programs on the following network drives:
//  
//
#define MSG_DRIVE_NETWORK_INTRO          0x00004E3FL

// RAM disks
//
// MessageId: MSG_DRIVE_RAM_SUBGROUP
//
// MessageText:
//
//  RAM Disks%0
//
#define MSG_DRIVE_RAM_SUBGROUP           0x00004E40L

//
// MessageId: MSG_DRIVE_RAM_INTRO
//
// MessageText:
//
//  RAM Disks
//  
//  The following RAM disks are not compatible with Windows XP:
//  
//
#define MSG_DRIVE_RAM_INTRO              0x00004E41L

// Substituted drives
//
// MessageId: MSG_DRIVE_SUBST_SUBGROUP
//
// MessageText:
//
//  Substituted Drives%0
//
#define MSG_DRIVE_SUBST_SUBGROUP         0x00004E42L

//
// MessageId: MSG_DRIVE_SUBST_INTRO
//
// MessageText:
//
//  Substituted Drives
//  
//  The following substituted drives don't need to be processed:
//
#define MSG_DRIVE_SUBST_INTRO            0x00004E43L

// ***
// *** Keyboard Layout
// ***
//
// MessageId: MSG_KEYBOARD_SUBGROUP
//
// MessageText:
//
//  <unused>%0
//
#define MSG_KEYBOARD_SUBGROUP            0x00004E44L

//
// MessageId: MSG_KEYBOARD_LAYOUT_NOT_SUPPORTED
//
// MessageText:
//
//  <unused>%0
//
#define MSG_KEYBOARD_LAYOUT_NOT_SUPPORTED 0x00004E45L

//
// MessageId: MSG_KEYBOARD_DEVICE_UNSUPPORTED
//
// MessageText:
//
//  <unused>%0
//
#define MSG_KEYBOARD_DEVICE_UNSUPPORTED  0x00004E46L

// ***
// *** Incomplete user settings
// ***
//
// Subgroups for MSG_REG_SETTINGS_INCOMPLETE

//
// MessageId: MSG_REG_SETTINGS_SUBGROUP
//
// MessageText:
//
//  Invalid User Accounts%0
//
#define MSG_REG_SETTINGS_SUBGROUP        0x00004E47L

//
// MessageId: MSG_SHELL_SETTINGS_SUBGROUP
//
// MessageText:
//
//  Inaccessible or Incomplete User Accounts%0
//
#define MSG_SHELL_SETTINGS_SUBGROUP      0x00004E48L

// If we encounter a busted user... this text is displayed
//
// MessageId: MSG_REG_SETTINGS_INCOMPLETE
//
// MessageText:
//
//  User Accounts That Cannot Be Upgraded
//  
//  The following user accounts are inaccessible or incomplete and cannot be upgraded to Windows XP:
//  
//
#define MSG_REG_SETTINGS_INCOMPLETE      0x00004E49L

//
// MessageId: MSG_REG_SETTINGS_INCOMPLETE_HTML
//
// MessageText:
//
//  <UL><B>User Accounts That Cannot Be Upgraded</B><BR>
//  The following user accounts are inaccessible or incomplete and cannot be upgraded to Windows XP:
//  <P>
//  <UL>%0
//
#define MSG_REG_SETTINGS_INCOMPLETE_HTML 0x00004E4AL

// If we encounter a busted shell... this text is displayed

//
// MessageId: MSG_SHELL_SETTINGS_INCOMPLETE
//
// MessageText:
//
//  Users With a Damaged Start Menu or Desktop
//  
//  The Start menu or desktop for the following user accounts is inaccessible or incomplete and cannot be upgraded to Windows XP. After Setup completes, you can recreate these accounts.
//  
//
#define MSG_SHELL_SETTINGS_INCOMPLETE    0x00004E4BL

//
// MessageId: MSG_SHELL_SETTINGS_INCOMPLETE_HTML
//
// MessageText:
//
//  <UL><B>Users With a Damaged Start Menu or Desktop</B><BR>
//  The Start menu or desktop for the following user accounts is inaccessible or incomplete and cannot be upgraded to Windows XP. After Setup completes, you can recreate these accounts.
//  <P>
//  <UL>%0
//
#define MSG_SHELL_SETTINGS_INCOMPLETE_HTML 0x00004E4CL

// When user name is empty on Win9x, this text is used for display. (Rarely used.)

//
// MessageId: MSG_REG_SETTINGS_EMPTY_USER
//
// MessageText:
//
//  [default user account]%0
//
#define MSG_REG_SETTINGS_EMPTY_USER      0x00004E4DL

// ***
// *** Hardware Profiles
// ***
//
// Hardware profile incompatibility text

//
// MessageId: MSG_HWPROFILES_SUBGROUP
//
// MessageText:
//
//  Hardware Profiles%0
//
#define MSG_HWPROFILES_SUBGROUP          0x00004E4EL

//
// MessageId: MSG_HWPROFILES_INTRO
//
// MessageText:
//
//  Hardware Profiles
//  
//  Some settings in the following hardware profiles cannot be transferred to Windows XP. The first time you use each incomplete profile, the Hardware wizard will help you re-create these settings.
//  
//
#define MSG_HWPROFILES_INTRO             0x00004E4FL

//
// MessageId: MSG_HWPROFILES_INTRO_HTML
//
// MessageText:
//
//  <UL><B>Hardware Profiles</B><BR>
//  Some settings in the following hardware profiles cannot be transferred to Windows XP. The first time you use each incomplete profile, the Hardware wizard will help you re-create these settings.
//  <P>
//  <UL>
//
#define MSG_HWPROFILES_INTRO_HTML        0x00004E50L

// Incompatible Shell settings
//
//
// MessageId: MSG_REPORT_SHELL_INCOMPATIBLE
//
// MessageText:
//
//  Setup detected a program that replaces Windows Explorer. Setup will disable this program to avoid startup problems in Windows XP.%0
//
#define MSG_REPORT_SHELL_INCOMPATIBLE    0x00004E51L

// ***
// *** Other -- as time goes on, there will be as few of these as possible
// ***
//
// MessageId: MSG_INSTALL_NOTES_OTHER
//
// MessageText:
//
//  <unused>%0
//
#define MSG_INSTALL_NOTES_OTHER          0x00004E52L

//
// MessageId: MSG_INSTALL_NOTES_OTHER_HTML
//
// MessageText:
//
//  <unused>%0
//
#define MSG_INSTALL_NOTES_OTHER_HTML     0x00004E53L

//***************************************************************************
//
// Settings That Will Not Be Upgraded
//
//***************************************************************************
//
// MessageId: MSG_LOSTSETTINGS_ROOT
//
// MessageText:
//
//  Settings That Will Not Be Upgraded%0
//
#define MSG_LOSTSETTINGS_ROOT            0x00004E54L

//***************************************************************************
//
// Applications that will be automatically uninstalled
//
//***************************************************************************
//
// MessageId: MSG_AUTO_UNINSTALL_SUBGROUP
//
// MessageText:
//
//  Software to Be Removed by Setup%0
//
#define MSG_AUTO_UNINSTALL_SUBGROUP      0x00004E55L

//
// MessageId: MSG_AUTO_UNINSTALL_INTRO
//
// MessageText:
//
//  Software to Be Removed by Setup
//  
//  The following programs were not designed for Windows XP. If you continue, Setup will remove them from your computer.
//  
//
#define MSG_AUTO_UNINSTALL_INTRO         0x00004E56L

//
// MessageId: MSG_AUTO_UNINSTALL_INTRO_HTML
//
// MessageText:
//
//  <B>Software to Be Removed by Setup</B><BR>
//  The following programs were not designed for Windows XP. If you continue, Setup will remove them from your computer.
//  <P>
//
#define MSG_AUTO_UNINSTALL_INTRO_HTML    0x00004E57L

//***************************************************************************
//
// Software Incompatible with Windows XP
//
//***************************************************************************
//
// MessageId: MSG_INCOMPATIBLE_ROOT
//
// MessageText:
//
//  Software Incompatible with Windows XP%0
//
#define MSG_INCOMPATIBLE_ROOT            0x00004E58L

// Win95-specific software, will never run on NT

//
// MessageId: MSG_INCOMPATIBLE_INTRO
//
// MessageText:
//
//  Software Incompatible with Windows XP
//  -------------------------------------
//  
//
#define MSG_INCOMPATIBLE_INTRO           0x00004E59L

//
// MessageId: MSG_INCOMPATIBLE_INTRO_HTML
//
// MessageText:
//
//  <B>Software Compatibility Issues</B>
//  <P>
//
#define MSG_INCOMPATIBLE_INTRO_HTML      0x00004E5AL

//***************************************************************************
//
// Software That Must Be Reinstalled
//
//***************************************************************************
//
// MessageId: MSG_REINSTALL_ROOT
//
// MessageText:
//
//  Software That Must Be Reinstalled%0
//
#define MSG_REINSTALL_ROOT               0x00004E5BL

// Win95-specific installation software installed an app; needs to be reinstalled to get NT version.

//
// MessageId: MSG_REPORT_BEGIN_INDENT
//
// MessageText:
//
//  %0
//
#define MSG_REPORT_BEGIN_INDENT          0x00004E5CL

//
// MessageId: MSG_REPORT_BEGIN_INDENT_HTML
//
// MessageText:
//
//  <UL>%0
//
#define MSG_REPORT_BEGIN_INDENT_HTML     0x00004E5DL

//
// MessageId: MSG_REPORT_REINSTALL_INSTRUCTIONS2
//
// MessageText:
//
//  <unused>%0
//
#define MSG_REPORT_REINSTALL_INSTRUCTIONS2 0x00004E5EL

//
// MessageId: MSG_REPORT_REINSTALL_INSTRUCTIONS2_HTML
//
// MessageText:
//
//  <unused>%0
//
#define MSG_REPORT_REINSTALL_INSTRUCTIONS2_HTML 0x00004E5FL

//***************************************************************************
//
// Notes About Your Other Software
//
//***************************************************************************
//
// MessageId: MSG_MINOR_PROBLEM_ROOT
//
// MessageText:
//
//  Notes About Your Other Software%0
//
#define MSG_MINOR_PROBLEM_ROOT           0x00004E60L

//
// MessageId: MSG_MINOR_PROBLEM_INTRO
//
// MessageText:
//
//  Notes About Your Other Software
//  -------------------------------
//  This section describes issues that might affect other software you use. Be sure to read this section before you begin the upgrade to Windows XP.
//  
//
#define MSG_MINOR_PROBLEM_INTRO          0x00004E61L

//
// MessageId: MSG_MINOR_PROBLEM_INTRO_HTML
//
// MessageText:
//
//  <B>Notes About Your Other Software</B><BR>
//  This section describes issues that might affect other software you use. Be sure to read this section before you begin the upgrade to Windows XP.
//  <P>
//
#define MSG_MINOR_PROBLEM_INTRO_HTML     0x00004E62L

// ***
// *** Incompatible Help Files
// ***
//
// Incompatible Help Files text

//
// MessageId: MSG_HELPFILES_SUBGROUP
//
// MessageText:
//
//  Incompatible Help Files%0
//
#define MSG_HELPFILES_SUBGROUP           0x00004E63L

//
// MessageId: MSG_HELPFILES_INTRO
//
// MessageText:
//
//  Help Files
//  
//  Some or all of the online Help contained in the following files will not work with Windows XP:
//  
//
#define MSG_HELPFILES_INTRO              0x00004E64L

//
// MessageId: MSG_HELPFILES_INTRO_HTML
//
// MessageText:
//
//  <UL><B>Help Files</B><BR>
//  Some or all of the online Help contained in the following files will not work with Windows XP:
//  <P>
//  <UL>%0
//
#define MSG_HELPFILES_INTRO_HTML         0x00004E65L

//
// Help Files checking messages
//
// Technical log message, %2 - help file name, %1 - 16-bit DLL path
//
// MessageId: MSG_HELPFILES_NOTFOUND_LOG
//
// MessageText:
//
//  Help file %2 uses %1 as an extension pack. Setup could not find %1.%0
//
#define MSG_HELPFILES_NOTFOUND_LOG       0x00004E66L

// Technical log message, %2 - help file name, %1 - 16-bit DLL path
//
// MessageId: MSG_HELPFILES_BROKEN_LOG
//
// MessageText:
//
//  Help file %2 uses %1 as an extension pack. %1 is not working properly or is not a Windows extension pack.%0
//
#define MSG_HELPFILES_BROKEN_LOG         0x00004E67L

// Technical log message, %2 - help file name, %1 - 16-bit DLL path
//
// MessageId: MSG_HELPFILES_MISMATCHED_LOG
//
// MessageText:
//
//  Help file %2 uses %1 as an extension pack. Because %1 and %2 will be loaded into different subsystems, you won't be able to use this Help file under Windows XP.%0
//
#define MSG_HELPFILES_MISMATCHED_LOG     0x00004E68L

//***************************************************************************
//
// Other Upgrade Information
//
//***************************************************************************
//
// MessageId: MSG_MIGDLL_ROOT
//
// MessageText:
//
//  Other Upgrade Information%0
//
#define MSG_MIGDLL_ROOT                  0x00004E69L

//
// MessageId: MSG_MIGDLL_INTRO
//
// MessageText:
//
//  Other Upgrade Information
//  -------------------------
//  
//
#define MSG_MIGDLL_INTRO                 0x00004E6AL

//
// MessageId: MSG_MIGDLL_INTRO_HTML
//
// MessageText:
//
//  <B>Other Upgrade Information</B>
//  <P>
//
#define MSG_MIGDLL_INTRO_HTML            0x00004E6BL

//***************************************************************************
//
// Unorganized messages -- all new messages must be added to the end,
// because of localization constraints.
//
//***************************************************************************
//
// MessageId: MSG_MULTI_MONITOR_UNSUPPORTED_SUBGROUP
//
// MessageText:
//
//  Multiple Monitor Support%0
//
#define MSG_MULTI_MONITOR_UNSUPPORTED_SUBGROUP 0x00004E6CL

//
// MessageId: MSG_MULTI_MONITOR_UNSUPPORTED_PER
//
// MessageText:
//
//  The Home Edition of Windows XP does not include multi-monitor support. Upgrading to Windows XP Professional Edition will enable multi-monitor support.%0
//
#define MSG_MULTI_MONITOR_UNSUPPORTED_PER 0x00004E6DL

//
// MessageId: MSG_MULTI_MONITOR_UNSUPPORTED
//
// MessageText:
//
//  Although Windows XP supports multiple monitors, Setup might not be able to preserve your current monitor configuration. After Setup completes, you might need to adjust your monitor configuration.%0
//
#define MSG_MULTI_MONITOR_UNSUPPORTED    0x00004E6EL

//
// MessageId: MSG_OTHER_OS_WARNING_SUBGROUP
//
// MessageText:
//
//  Other Operating Systems Found%0
//
#define MSG_OTHER_OS_WARNING_SUBGROUP    0x00004E6FL

//
// MessageId: MSG_OTHER_OS_WARNING
//
// MessageText:
//
//  You cannot upgrade this Windows installation to Windows XP, because you have more than one operating system installed on your computer. Upgrading one operating system can cause problems with files shared by the other operating system, and is therefore not permitted.%0
//
#define MSG_OTHER_OS_WARNING             0x00004E70L

//
// MessageId: MSG_OTHER_OS_IN_PATH_SUBGROUP
//
// MessageText:
//
//  <unused>%0
//
#define MSG_OTHER_OS_IN_PATH_SUBGROUP    0x00004E71L

//
// MessageId: MSG_OTHER_OS_IN_PATH
//
// MessageText:
//
//  <unused>%0
//
#define MSG_OTHER_OS_IN_PATH             0x00004E72L

//
// MessageId: MSG_BACKUP_DETECTED_SUBGROUP
//
// MessageText:
//
//  Backup Files Found%0
//
#define MSG_BACKUP_DETECTED_SUBGROUP     0x00004E73L

// %1 - Operating System (i.e., Windows 95); %2 - number of backup folders found
//
// MessageId: MSG_BACKUP_DETECTED
//
// MessageText:
//
//  Setup found files on your computer that appear to be a backup of part of %1. During the upgrade to Windows XP, Setup removes %1 from your computer, including any backups you might have on your hard disk. More information is available in the Setupact.log file, located in your Windows folder.  It lists %2 folders that might contain backup files.<P>
//  Protect your backup files by copying them to floppy disks, a network server, a compressed archive file, or other backup mechanism.%0
//
#define MSG_BACKUP_DETECTED              0x00004E74L

//
// MessageId: MSG_BETA2_ROOT
//
// MessageText:
//
//  <unused>%0
//
#define MSG_BETA2_ROOT                   0x00004E75L

//
// MessageId: MSG_OLD_DRIVER_FOUND_SUBGROUP
//
// MessageText:
//
//  Drivers Designed for Windows 3.1%0
//
#define MSG_OLD_DRIVER_FOUND_SUBGROUP    0x00004E76L

//
// MessageId: MSG_OLD_DRIVER_FOUND_MESSAGE
//
// MessageText:
//
//  Setup found hardware files designed for Windows 3.1. These files are not Plug-and-Play compatible. It is safe to upgrade now, but some of your hardware might not function after Setup completes.<P>
//  Although Setup identified the hardware files, it cannot identify the device. After upgrade, you might be able to determine which device could not be found by right-clicking My Computer, clicking Properties, clicking Device Manager, and then checking the device list for missing items.%0
//
#define MSG_OLD_DRIVER_FOUND_MESSAGE     0x00004E77L

//
// MessageId: MSG_NON_PNP_DRIVER_SUBGROUP
//
// MessageText:
//
//  <unused>%0
//
#define MSG_NON_PNP_DRIVER_SUBGROUP      0x00004E78L

//
// MessageId: MSG_NO_INCOMPATIBILITIES
//
// MessageText:
//
//  No incompatible hardware or software was found on your computer.%0
//
#define MSG_NO_INCOMPATIBILITIES         0x00004E79L

// %1 - Operating System (i.e., Windows 95)
//
// MessageId: MSG_NO_BOOT16_WARNING_SUBGROUP
//
// MessageText:
//
//  MS-DOS Startup Option%0
//
#define MSG_NO_BOOT16_WARNING_SUBGROUP   0x00004E7AL

// %1 - Operating System (i.e., Windows 95)
//
// MessageId: MSG_NO_BOOT16_WARNING
//
// MessageText:
//
//  Because you are upgrading your system disk to the Windows XP File System (NTFS), the MS-DOS startup option has been automatically disabled.%0
//
#define MSG_NO_BOOT16_WARNING            0x00004E7BL

//
// MessageId: MSG_TIMEZONE_COMPONENT
//
// MessageText:
//
//  General Information\Time Zone\%0
//
#define MSG_TIMEZONE_COMPONENT           0x00004E7CL

//
// MessageId: MSG_TIMEZONE_WARNING
//
// MessageText:
//
//  The current time zone for your computer (%1) matches more than one Windows XP time zone. After Setup completes, you should use the Regional Settings icon in Control Panel to check your time zone settings.%0
//
#define MSG_TIMEZONE_WARNING             0x00004E7DL

//***************************************************************************
//
// Software Designed for MS-DOS
//
//***************************************************************************
//
// MessageId: MSG_DOS_DESIGNED_ROOT
//
// MessageText:
//
//  Software Designed for MS-DOS%0
//
#define MSG_DOS_DESIGNED_ROOT            0x00004E7EL

// MS-DOS specific software, will never run on NT

//
// MessageId: MSG_DOS_DESIGNED_INTRO
//
// MessageText:
//
//  Software Designed for MS-DOS
//  ----------------------------
//  The following programs are designed only for MS-DOS. After upgrading, use the MS-DOS startup option to run these programs.
//  
//
#define MSG_DOS_DESIGNED_INTRO           0x00004E7FL

//
// MessageId: MSG_DOS_DESIGNED_INTRO_HTML
//
// MessageText:
//
//  <B>Software Designed for MS-DOS</B><BR>
//  The following programs are designed only for MS-DOS. After upgrading, use the MS-DOS startup option to run these programs.
//  <P>
//
#define MSG_DOS_DESIGNED_INTRO_HTML      0x00004E80L

// Win95-specific software, will never run on NT

//
// MessageId: MSG_REPORT_WIN95_ONLY_INSTRUCTIONS2
//
// MessageText:
//
//  <unused>%0
//
#define MSG_REPORT_WIN95_ONLY_INSTRUCTIONS2 0x00004E81L

//
// MessageId: MSG_REPORT_WIN95_ONLY_INSTRUCTIONS2_HTML
//
// MessageText:
//
//  <unused>%0
//
#define MSG_REPORT_WIN95_ONLY_INSTRUCTIONS2_HTML 0x00004E82L

// TWAIN
//
// MessageId: MSG_TWAIN_SUBGROUP
//
// MessageText:
//
//  TWAIN%0
//
#define MSG_TWAIN_SUBGROUP               0x00004E83L

//
// MessageId: MSG_TWAIN_DEVICES_UNKNOWN
//
// MessageText:
//
//  Scanners or Digital Cameras That Might Not Work
//  
//  Setup did not recognize the following scanners or digital cameras. Before upgrading, check the packaging that came with each device to see if it supports Windows XP, or contact the device manufacturer. Reinstall each device when Setup is complete, using the software that came with the device.
//  
//
#define MSG_TWAIN_DEVICES_UNKNOWN        0x00004E84L

//
// MessageId: MSG_TWAIN_DEVICES_UNKNOWN_HTML
//
// MessageText:
//
//  <UL><B>Scanners or Digital Cameras That Might Not Work</B><BR>
//  Setup did not recognize the following scanners or digital cameras. Before upgrading, check the packaging that came with each device to see if it supports Windows XP, or contact the device manufacturer. Reinstall each device when Setup is complete, using the software that came with the device.
//  <P>
//  <UL>%0
//
#define MSG_TWAIN_DEVICES_UNKNOWN_HTML   0x00004E85L

//
// MessageId: MSG_RAS_SUBGROUP
//
// MessageText:
//
//  <unused>%0
//
#define MSG_RAS_SUBGROUP                 0x00004E86L

//
// MessageId: MSG_BAD_RAS_PROTOCOL
//
// MessageText:
//
//  <unused>%0
//
#define MSG_BAD_RAS_PROTOCOL             0x00004E87L

//
// MessageId: MSG_TWAIN_DEVICES_UNKNOWN2
//
// MessageText:
//
//  <unused>%0
//
#define MSG_TWAIN_DEVICES_UNKNOWN2       0x00004E88L

//
// MessageId: MSG_TWAIN_DEVICES_UNKNOWN2_HTML
//
// MessageText:
//
//  <unused>%0
//
#define MSG_TWAIN_DEVICES_UNKNOWN2_HTML  0x00004E89L

//
// MessageId: MSG_INCOMPATIBLE_HARDWARE_PNP_SUBGROUP
//
// MessageText:
//
//  1-Incompatible Hardware%0
//
#define MSG_INCOMPATIBLE_HARDWARE_PNP_SUBGROUP 0x00004E8AL

//
// MessageId: MSG_INCOMPATIBLE_HARDWARE_INTRO
//
// MessageText:
//
//  Hardware Compatibility Issues
//  -----------------------------
//  Setup has found hardware on your computer that is incompatible with (that is, it does not work with) Windows XP.
//  
//
#define MSG_INCOMPATIBLE_HARDWARE_INTRO  0x00004E8BL

//
// MessageId: MSG_INCOMPATIBLE_HARDWARE_INTRO_HTML
//
// MessageText:
//
//  <B>Hardware Compatibility Issues</B><BR>
//  Setup has found hardware on your computer that is incompatible with (that is, it does not work with) Windows XP.
//  <P>
//  
//
#define MSG_INCOMPATIBLE_HARDWARE_INTRO_HTML 0x00004E8CL

//
// MessageId: MSG_INCOMPATIBLE_HARDWARE_OTHER
//
// MessageText:
//
//  %0
//
#define MSG_INCOMPATIBLE_HARDWARE_OTHER  0x00004E8DL

//
// MessageId: MSG_INCOMPATIBLE_HARDWARE_OTHER_HTML
//
// MessageText:
//
//  
//
#define MSG_INCOMPATIBLE_HARDWARE_OTHER_HTML 0x00004E8EL

//
// MessageId: MSG_JOYSTICK_SUBGROUP
//
// MessageText:
//
//  Incompatible Joysticks
//
#define MSG_JOYSTICK_SUBGROUP            0x00004E8FL

//
// MessageId: MSG_JOYSTICK_DEVICE_UNKNOWN
//
// MessageText:
//
//  Incompatible Joysticks
//  
//  The following joysticks need additional files from the hardware manufacturer to work with Windows XP.
//  
//
#define MSG_JOYSTICK_DEVICE_UNKNOWN      0x00004E90L

//
// MessageId: MSG_JOYSTICK_DEVICE_UNKNOWN_HTML
//
// MessageText:
//
//  <UL><B>Incompatible Joysticks</B><BR>
//  The following joysticks need additional files from the hardware manufacturer to work with Windows XP.
//  <P>
//  <UL>%0
//
#define MSG_JOYSTICK_DEVICE_UNKNOWN_HTML 0x00004E91L

//***************************************************************************
//
// Program Compatibility Not Known
//
//***************************************************************************
//
// MessageId: MSG_UNKNOWN_ROOT
//
// MessageText:
//
//  Program Compatibility Not Known%0
//
#define MSG_UNKNOWN_ROOT                 0x00004E92L

//
// MessageId: MSG_REPORT_UNKNOWN_INSTRUCTIONS
//
// MessageText:
//
//  Program Compatibility Not Known
//  -------------------------------
//  Setup cannot determine the compatibility of the software listed below.  Most programs support Windows XP.  Before upgrading, check the software compatibility list on  http://www.microsoft.com/isapi/redir.dll?prd=whistler&ar=help&sba=compatible, or contact the software manufacturer.
//  
//
#define MSG_REPORT_UNKNOWN_INSTRUCTIONS  0x00004E93L

//
// MessageId: MSG_REPORT_UNKNOWN_INSTRUCTIONS_HTML
//
// MessageText:
//
//  <B>Program Compatibility Not Known</B><BR>
//  Setup cannot determine the compatibility of the software listed below.  Most programs support Windows XP.  Before upgrading, check the software compatibility list on <A HREF="http://www.microsoft.com/isapi/redir.dll?prd=whistler&ar=help&sba=compatible">Microsoft's Web site</A>, or contact the software manufacturer.<P>
//
#define MSG_REPORT_UNKNOWN_INSTRUCTIONS_HTML 0x00004E94L

//
// MessageId: MSG_NOT_ENOUGH_RAM_SUBGROUP
//
// MessageText:
//
//  Memory%0
//
#define MSG_NOT_ENOUGH_RAM_SUBGROUP      0x00004E95L

// %1 - Needed RAM (number in MB), %2 - Current RAM, %3 - Difference
//
// MessageId: MSG_NOT_ENOUGH_RAM
//
// MessageText:
//
//  Your computer does not have enough memory to run Windows XP. Windows XP requires %1 MB of memory, but your computer only has %2 MB. You need to add at least %3 MB of additional memory to your computer before upgrading.%0
//
#define MSG_NOT_ENOUGH_RAM               0x00004E96L

//
// MessageId: MSG_RECYCLE_BIN_SUBGROUP
//
// MessageText:
//
//  Recycle Bin%0
//
#define MSG_RECYCLE_BIN_SUBGROUP         0x00004E97L

// %1 - number of files in the Recycle Bin
//
// MessageId: MSG_RECYCLED_FILES_WILL_BE_DELETED
//
// MessageText:
//
//  Setup found %1 files in your Recycle Bin. If you continue upgrading to Windows XP, these files will be deleted.%0
//
#define MSG_RECYCLED_FILES_WILL_BE_DELETED 0x00004E98L

// Used when a machine name doesn't exist
//
// MessageId: MSG_BLANK_NAME
//
// MessageText:
//
//  (blank name)%0
//
#define MSG_BLANK_NAME                   0x00004E99L

// %1 - system drive letter, %2 - space to be freed, %3 - ~ls size, %4 - non-system drive option requirment, in mb, %5 - backup image size
//
// MessageId: MSG_NOT_ENOUGH_DISK_SPACE_WITH_LOCALSOURCE
//
// MessageText:
//
//  Your computer does not have enough disk space to completely install Windows XP. You must free additional disk space before you can upgrade. You need at least %2 MB free space on drive %1, or at least %3 MB on any other drive.%0
//
#define MSG_NOT_ENOUGH_DISK_SPACE_WITH_LOCALSOURCE 0x00004E9AL

// %1 - system drive letter, %2 - space to be freed, %3 - ~ls size, %4 - non-system drive option requirment, in mb, %5 - backup image size
//
// MessageId: MSG_NOT_ENOUGH_DISK_SPACE_WITH_LOCALSOURCE_AND_WINDIR
//
// MessageText:
//
//  Your computer does not have enough disk space to completely install Windows XP. You must free additional disk space before you can upgrade. You need at least %2 MB free space on drive %1, or you need at least %4 MB on drive %1 and %3 MB on any other drive.%0
//
#define MSG_NOT_ENOUGH_DISK_SPACE_WITH_LOCALSOURCE_AND_WINDIR 0x00004E9BL

//
// MessageId: MSG_DUN_ENTRIES_WILL_BE_MOVED
//
// MessageText:
//
//  <unused>%0
//
#define MSG_DUN_ENTRIES_WILL_BE_MOVED    0x00004E9CL

//
// MessageId: MSG_MAPI_NOT_HANDLED_SUBGROUP
//
// MessageText:
//
//  Windows Messaging Services%0
//
#define MSG_MAPI_NOT_HANDLED_SUBGROUP    0x00004E9DL

//
// MessageId: MSG_MAPI_NOT_HANDLED
//
// MessageText:
//
//  Setup has detected a version of messaging (MAPI) that does not function on Windows XP.  Obtain an upgrade pack for your e-mail program, or reinstall it after upgrading to Windows XP.%0
//
#define MSG_MAPI_NOT_HANDLED             0x00004E9EL

//***************************************************************************
//
// Applications that must be uninstalled before an upgrade can occur.
//
//***************************************************************************
//
// MessageId: MSG_MUST_UNINSTALL_ROOT
//
// MessageText:
//
//  Software to be Removed Before Upgrading%0
//
#define MSG_MUST_UNINSTALL_ROOT          0x00004E9FL

//
// MessageId: MSG_MUST_UNINSTALL_INTRO
//
// MessageText:
//
//  Software That Must be Permanently Removed
//  -----------------------------------------
//  The following programs can cause problems during the upgrade process and Setup cannot automatically remove them for you. Therefore, before Setup can continue, you must uninstall these programs from your computer.
//  
//
#define MSG_MUST_UNINSTALL_INTRO         0x00004EA0L

//
// MessageId: MSG_MUST_UNINSTALL_INTRO_HTML
//
// MessageText:
//
//  <B>Software That Must be Permanently Removed</B><BR>
//  The following programs can cause problems during the upgrade process and Setup cannot automatically remove them for you. Therefore, before Setup can continue, you must uninstall these programs from your computer.
//  <P>
//  <UL>%0
//
#define MSG_MUST_UNINSTALL_INTRO_HTML    0x00004EA1L

//
// MessageId: MSG_BLOCKING_FILE_BLOCK
//
// MessageText:
//
//  Because there are applications that must be uninstalled before an upgrade can be attempted, Setup will now exit. After you uninstall the necessary applications, run Setup again.%0
//
#define MSG_BLOCKING_FILE_BLOCK          0x00004EA2L

//
// MessageId: MSG_OTHER_OS_FOUND
//
// MessageText:
//
//  Windows XP Setup does not support upgrading from Windows if you have multiple Operating Systems installed.%0
//
#define MSG_OTHER_OS_FOUND               0x00004EA3L

//
// MessageId: MSG_CONNECTION_MOVED_SUBGROUP
//
// MessageText:
//
//  Moved Dial-Up Connections%0
//
#define MSG_CONNECTION_MOVED_SUBGROUP    0x00004EA4L

//
// MessageId: MSG_CONNECTION_MOVED_INTRO
//
// MessageText:
//
//  Dial-Up Connections That Will Be Moved
//  
//  The following connections will be moved into your Network and Dial-Up Connections Folder after migration.
//  
//
#define MSG_CONNECTION_MOVED_INTRO       0x00004EA5L

//
// MessageId: MSG_CONNECTION_MOVED_INTRO_HTML
//
// MessageText:
//
//  <UL><B>Dial-Up Connections That Will Be Moved</B><BR>
//  The following connections will be moved into your Network and Dial-Up Connections Folder after migration.
//  <P>
//
#define MSG_CONNECTION_MOVED_INTRO_HTML  0x00004EA6L

//
// MessageId: MSG_CONNECTION_BADPROTOCOL_SUBGROUP
//
// MessageText:
//
//  Dial-Up Connections Might Not Work%0
//
#define MSG_CONNECTION_BADPROTOCOL_SUBGROUP 0x00004EA7L

//
// MessageId: MSG_CONNECTION_BADPROTOCOL_INTRO
//
// MessageText:
//
//  Dial-Up Connections That Might Not Work
//  
//  The following connections might not work after migration is complete. They will be migrated using Windows XP defaults instead of the incompatible settings.
//  
//
#define MSG_CONNECTION_BADPROTOCOL_INTRO 0x00004EA8L

//
// MessageId: MSG_CONNECTION_BADPROTOCOL_INTRO_HTML
//
// MessageText:
//
//  <UL><B>Dial-Up Connections That Might Not Work</B><BR>
//  The following connections might not work after migration is complete. They will be migrated using Windows XP defaults instead of the incompatible settings.
//  <P>
//  <UL>%0
//
#define MSG_CONNECTION_BADPROTOCOL_INTRO_HTML 0x00004EA9L

//
// MessageId: MSG_TIMEZONE_WARNING_UNKNOWN
//
// MessageText:
//
//  Setup was unable to determine your time zone. After Setup completes, you should use the Regional Settings icon in Control Panel to check your time zone settings.%0
//
#define MSG_TIMEZONE_WARNING_UNKNOWN     0x00004EAAL

//
// MessageId: MSG_TIMEZONE_UNKNOWN
//
// MessageText:
//
//  Unknown Time Zone
//
#define MSG_TIMEZONE_UNKNOWN             0x00004EABL

//
// MessageId: MSG_RUNNING_MIGRATION_DLLS_SUBGROUP
//
// MessageText:
//
//  Upgrade Packs%0
//
#define MSG_RUNNING_MIGRATION_DLLS_SUBGROUP 0x00004EACL

//
// MessageId: MSG_RUNNING_MIGRATION_DLLS_INTRO
//
// MessageText:
//
//  Upgrade Packs That Are Being Processed
//  
//  The following upgrade packs are being processed during the migration to Windows XP.
//  
//
#define MSG_RUNNING_MIGRATION_DLLS_INTRO 0x00004EADL

//
// MessageId: MSG_RUNNING_MIGRATION_DLLS_INTRO_HTML
//
// MessageText:
//
//  <UL><B>Upgrade Packs That Are Being Processed</B><BR>
//  The following upgrade packs are being processed during the migration to Windows XP.
//  <P>
//  <UL>%0
//
#define MSG_RUNNING_MIGRATION_DLLS_INTRO_HTML 0x00004EAEL

//
// MessageId: MSG_TOTALLY_INCOMPATIBLE_SUBGROUP
//
// MessageText:
//
//  !Incompatible%0
//
#define MSG_TOTALLY_INCOMPATIBLE_SUBGROUP 0x00004EAFL

//
// MessageId: MSG_TOTALLY_INCOMPATIBLE_INTRO
//
// MessageText:
//
//  Software That Does Not Support Windows XP
//  
//  Setup has found programs on your computer that are incompatible with (that is, they do not work with) Windows XP. Contact your software vendors to obtain updates or Windows XP-compatible versions. If you don't update these programs before you upgrade, the programs will not work after the upgrade is completed.
//  
//
#define MSG_TOTALLY_INCOMPATIBLE_INTRO   0x00004EB0L

//
// MessageId: MSG_TOTALLY_INCOMPATIBLE_INTRO_HTML
//
// MessageText:
//
//  <B>Software That Does Not Support Windows XP</B><BR>
//  Setup has found programs on your computer that are incompatible with (that is, they do not work with) Windows XP. Contact your software vendors to obtain updates or Windows XP-compatible versions. If you don't update these programs before you upgrade, the programs will not work after the upgrade is completed.
//  <P>
//  <UL>%0
//
#define MSG_TOTALLY_INCOMPATIBLE_INTRO_HTML 0x00004EB1L

//
// MessageId: MSG_TOTALLY_INCOMPATIBLE_TRAIL
//
// MessageText:
//
//  Before you upgrade to Windows XP, you should remove any incompatible programs if you can. After the upgrade, uninstall for these programs might not work. Add/Remove Programs in Control Panel can help you uninstall most programs. Click Start, point to Settings, click Control Panel, and then click Add/Remove Programs.
//  
//  
//
#define MSG_TOTALLY_INCOMPATIBLE_TRAIL   0x00004EB2L

//
// MessageId: MSG_TOTALLY_INCOMPATIBLE_TRAIL_HTML
//
// MessageText:
//
//  Before you upgrade to Windows XP, you should remove any incompatible programs if you can. After the upgrade, uninstall for these programs might not work. Add/Remove Programs in Control Panel can help you uninstall most programs. Click Start, point to Settings, click Control Panel, and then click Add/Remove Programs.
//  </UL>
//
#define MSG_TOTALLY_INCOMPATIBLE_TRAIL_HTML 0x00004EB3L

//
// MessageId: MSG_REMOVED_FOR_SAFETY_SUBGROUP
//
// MessageText:
//
//  Removed For Safety%0
//
#define MSG_REMOVED_FOR_SAFETY_SUBGROUP  0x00004EB4L

//
// MessageId: MSG_REMOVED_FOR_SAFETY_INTRO
//
// MessageText:
//
//  Software That Might Not Support Windows XP
//  
//  Setup cannot determine if the following programs are compatible with Windows XP. Setup will disable them during the upgrade to eliminate the risk of problems. Contact the software vendor to obtain an upgrade pack.
//  
//
#define MSG_REMOVED_FOR_SAFETY_INTRO     0x00004EB5L

//
// MessageId: MSG_REMOVED_FOR_SAFETY_INTRO_HTML
//
// MessageText:
//
//  <B>Software That Might Not Support Windows XP</B><BR>
//  Setup cannot determine if the following programs are compatible with Windows XP. Setup will disable them during the upgrade to eliminate the risk of problems. Contact the software vendor to obtain an upgrade pack.
//  <P>
//  <UL>%0
//
#define MSG_REMOVED_FOR_SAFETY_INTRO_HTML 0x00004EB6L

// Display how folders will be renamed. %1-old name  %2-new name
//
// MessageId: MSG_DIRECTORY_COLLISION_SUBCOMPONENT
//
// MessageText:
//
//  %1 -> %2%0
//
#define MSG_DIRECTORY_COLLISION_SUBCOMPONENT 0x00004EB7L

//
// MessageId: MSG_INCOMPATIBLE_HARD_DISK_SUBGROUP
//
// MessageText:
//
//  Incompatible Hard Disk Controller%0
//
#define MSG_INCOMPATIBLE_HARD_DISK_SUBGROUP 0x00004EB8L

// This case is extremely important.  The user's boot device probably won't work without an ISV driver!
//
// MessageId: MSG_INCOMPATIBLE_HARD_DISK_WARNING
//
// MessageText:
//
//  Setup does not have a driver for the main hard disk controller on this computer. To continue Setup, you must have the correct Windows XP-compatible disk driver. Do not use a disk driver designed only for Windows 98 or Windows ME.<P>
//  
//  Caution: Do not continue the upgrade until you have the correct driver ready on a floppy disk. When Setup restarts, press the F6 key when prompted and follow the instructions.
//
#define MSG_INCOMPATIBLE_HARD_DISK_WARNING 0x00004EB9L

// This case is rarely a critical issue for the user, but it can be.
//
// MessageId: MSG_INCOMPATIBLE_HARD_DISK_NOTIFICATION
//
// MessageText:
//
//  Setup does not have a driver for a hard disk controller on this computer. To continue Setup, you should have the correct Windows XP-compatible disk driver. If you do not supply this driver, Setup might fail. Do not use a disk driver designed only for Windows 98 or Windows ME.<P>
//  It is recommended that you have the correct driver ready on a floppy disk before you continue. When Setup restarts, press the F6 key when prompted and follow the instructions. If Setup cannot proceed without the driver, you will need to cancel Setup.
//
#define MSG_INCOMPATIBLE_HARD_DISK_NOTIFICATION 0x00004EBAL

//
// MessageId: MSG_UNKNOWN_OS_WARNING_SUBGROUP
//
// MessageText:
//
//  Unsupported Operating System Version%0
//
#define MSG_UNKNOWN_OS_WARNING_SUBGROUP  0x00004EBBL

//
// MessageId: MSG_DRIVE_INACCESSIBLE_INTRO_HTML
//
// MessageText:
//
//  <UL><B>Inaccessible Drives</B><BR>
//  Setup cannot upgrade programs on the following drives:
//  <P>
//  <UL>%0
//
#define MSG_DRIVE_INACCESSIBLE_INTRO_HTML 0x00004EBCL

//
// MessageId: MSG_DRIVE_EXCLUDED_INTRO_HTML
//
// MessageText:
//
//  <UL><B>Excluded Drives</B><BR>
//  Setup will not look for programs on the following drives, because they have been excluded:
//  <P>
//  <UL>%0
//
#define MSG_DRIVE_EXCLUDED_INTRO_HTML    0x00004EBDL

//
// MessageId: MSG_DRIVE_NETWORK_INTRO_HTML
//
// MessageText:
//
//  <UL><B>Network Drives</B><BR>
//  Setup will not look for programs on the following network drives:
//  <P>
//  <UL>%0
//
#define MSG_DRIVE_NETWORK_INTRO_HTML     0x00004EBEL

//
// MessageId: MSG_DRIVE_RAM_INTRO_HTML
//
// MessageText:
//
//  <UL><B>RAM Disks</B><BR>
//  The following RAM disks are not compatible with Windows XP:
//  <P>
//  <UL>%0
//
#define MSG_DRIVE_RAM_INTRO_HTML         0x00004EBFL

//
// MessageId: MSG_DRIVE_SUBST_INTRO_HTML
//
// MessageText:
//
//  <UL><B>Substituted Drives</B><BR>
//  The following substituted drives don't need to be processed:
//  <P>
//  <UL>%0
//
#define MSG_DRIVE_SUBST_INTRO_HTML       0x00004EC0L

//
// MessageId: MSG_LOSTSETTINGS_INTRO
//
// MessageText:
//
//  Settings That Will Not Be Upgraded
//  ----------------------------------
//  Some of your settings will not be upgraded, because they aren't applicable in Windows XP.
//  
//
#define MSG_LOSTSETTINGS_INTRO           0x00004EC1L

//
// MessageId: MSG_LOSTSETTINGS_INTRO_HTML
//
// MessageText:
//
//  <B>Settings That Will Not Be Upgraded</B><BR>
//  Some of your settings will not be upgraded, because they aren't applicable in Windows XP.
//  <P>
//
#define MSG_LOSTSETTINGS_INTRO_HTML      0x00004EC2L

//
// MessageId: MSG_REPORT_SHELL_SUBGROUP
//
// MessageText:
//
//  Windows Explorer Replacement%0
//
#define MSG_REPORT_SHELL_SUBGROUP        0x00004EC3L

//
// MessageId: MSG_OTHER_OS_FOUND_POPUP
//
// MessageText:
//
//  Windows XP Setup does not support upgrading from Windows if you have multiple Operating Systems installed. Setup will now exit.%0
//
#define MSG_OTHER_OS_FOUND_POPUP         0x00004EC4L

//
// MessageId: MSG_UNKNOWN_DEVICE_CLASS
//
// MessageText:
//
//  Other devices%0
//
#define MSG_UNKNOWN_DEVICE_CLASS         0x00004EC5L

//
// MessageId: MSG_DIRECTORY_COLLISION_INTRO_HTML
//
// MessageText:
//
//  <UL><B>Folder Name Changes</B><BR>
//  Because two folders have the same name, Setup will rename them as follows:
//  <P>
//
#define MSG_DIRECTORY_COLLISION_INTRO_HTML 0x00004EC6L

//
// MessageId: MSG_REUSABLE_1
//
// MessageText:
//
//  %0
//
#define MSG_REUSABLE_1                   0x00004EC7L

//
// MessageId: MSG_REUSABLE_2
//
// MessageText:
//
//  %0
//
#define MSG_REUSABLE_2                   0x00004EC8L

// Old briefcase messages left as placeholders

//
// MessageId: MSG_NON_EMPTY_BRIEFCASES_SUBGROUP
//
// MessageText:
//
//  MSG_NON_EMPTY_BRIEFCASES_SUBGROUP
//
#define MSG_NON_EMPTY_BRIEFCASES_SUBGROUP 0x00004EC9L

//
// MessageId: MSG_NON_EMPTY_BRIEFCASES_INTRO
//
// MessageText:
//
//  MSG_NON_EMPTY_BRIEFCASES_INTRO
//
#define MSG_NON_EMPTY_BRIEFCASES_INTRO   0x00004ECAL

//
// MessageId: MSG_NON_EMPTY_BRIEFCASES_INTRO_HTML
//
// MessageText:
//
//  MSG_NON_EMPTY_BRIEFCASES_INTRO_HTML
//
#define MSG_NON_EMPTY_BRIEFCASES_INTRO_HTML 0x00004ECBL

//
// MessageId: MSG_NON_EMPTY_BRIEFCASES_TRAIL
//
// MessageText:
//
//  MSG_NON_EMPTY_BRIEFCASES_TRAIL
//
#define MSG_NON_EMPTY_BRIEFCASES_TRAIL   0x00004ECCL

//
// MessageId: MSG_NON_EMPTY_BRIEFCASES_TRAIL_HTML
//
// MessageText:
//
//  MSG_NON_EMPTY_BRIEFCASES_TRAIL_HTML
//
#define MSG_NON_EMPTY_BRIEFCASES_TRAIL_HTML 0x00004ECDL

//***************************************************************************
//
// Software That Must Be Temporarily Removed
//
//***************************************************************************
//
// MessageId: MSG_REINSTALL_BLOCK_ROOT
//
// MessageText:
//
//  Software That Must Be Temporarily Removed%0
//
#define MSG_REINSTALL_BLOCK_ROOT         0x00004ECEL

// Win95-specific installation software installed an app; needs to be reinstalled to get NT version.

//
// MessageId: MSG_REPORT_REINSTALL_BLOCK_INSTRUCTIONS
//
// MessageText:
//
//  Software That Must Be Temporarily Removed
//  -----------------------------------------
//  The following programs must be uninstalled before upgrading. You can then reinstall these programs after you have upgraded to Windows XP. To remove programs, use Add/Remove Programs in Control Panel or refer to the documentation that came with each program.
//  
//
#define MSG_REPORT_REINSTALL_BLOCK_INSTRUCTIONS 0x00004ECFL

//
// MessageId: MSG_REPORT_REINSTALL_BLOCK_INSTRUCTIONS_HTML
//
// MessageText:
//
//  <B>Software That Must Be Temporarily Removed</B><BR>
//  The following programs must be uninstalled before upgrading. You can then reinstall these programs after you have upgraded to Windows XP. To remove programs, use Add/Remove Programs in Control Panel or refer to the documentation that came with each program.
//  <P>
//  <UL>%0
//
#define MSG_REPORT_REINSTALL_BLOCK_INSTRUCTIONS_HTML 0x00004ED0L

//
// MessageId: MSG_REPORT_REINSTALL_BLOCK_INSTRUCTIONS2
//
// MessageText:
//
//  <unused>%0
//
#define MSG_REPORT_REINSTALL_BLOCK_INSTRUCTIONS2 0x00004ED1L

//
// MessageId: MSG_REPORT_REINSTALL_BLOCK_INSTRUCTIONS2_HTML
//
// MessageText:
//
//  <unused>%0
//
#define MSG_REPORT_REINSTALL_BLOCK_INSTRUCTIONS2_HTML 0x00004ED2L

//
// MessageId: MSG_PRINTERS_DEVICE_CLASS
//
// MessageText:
//
//  Printers%0
//
#define MSG_PRINTERS_DEVICE_CLASS        0x00004ED3L

//
// MessageId: MSG_BACKUP_DETECTED_LIST_SUBGROUP
//
// MessageText:
//
//  Backup_Files_Found%0
//
#define MSG_BACKUP_DETECTED_LIST_SUBGROUP 0x00004ED4L

// %1 - Operating System (i.e., Windows 95)
//
// MessageId: MSG_BACKUP_DETECTED_INTRO
//
// MessageText:
//
//  Backup Files Found
//  
//  Setup found files on your computer that appear to be a backup of part of %1. During the upgrade to Windows XP, Setup removes %1 from your computer, including any backups you might have on your hard disk. Some files in the following folders will be removed:
//  
//
#define MSG_BACKUP_DETECTED_INTRO        0x00004ED5L

// %1 - Operating System (i.e., Windows 95)
//
// MessageId: MSG_BACKUP_DETECTED_INTRO_HTML
//
// MessageText:
//
//  <UL><B>Backup Files Found</B><BR>
//  Setup found files on your computer that appear to be a backup of part of %1. During the upgrade to Windows XP, Setup removes %1 from your computer, including any backups you might have on your hard disk. Some files in the following folders will be removed:
//  <P>
//  <UL>%0
//
#define MSG_BACKUP_DETECTED_INTRO_HTML   0x00004ED6L

//
// MessageId: MSG_BACKUP_DETECTED_TRAIL
//
// MessageText:
//
//  Protect your backup files by copying them to floppy disks, a network server, a compressed archive file, or other backup mechanism.
//  
//
#define MSG_BACKUP_DETECTED_TRAIL        0x00004ED7L

//
// MessageId: MSG_BACKUP_DETECTED_TRAIL_HTML
//
// MessageText:
//
//  <BR>Protect your backup files by copying them to floppy disks, a network server, a compressed archive file, or other backup mechanism.
//  </UL>
//
#define MSG_BACKUP_DETECTED_TRAIL_HTML   0x00004ED8L

// Log message, %1 - Backup Directory Name, %2 - Operating System Name (i.e., Windows 95)
//
// MessageId: MSG_BACKUP_DETECTED_LOG
//
// MessageText:
//
//  Directory %1 contains files that appear to be a backup of part of %2.%0
//
#define MSG_BACKUP_DETECTED_LOG          0x00004ED9L

//
// MessageId: MSG_UNSUPPORTED_HARDWARE_PNP_SUBGROUP
//
// MessageText:
//
//  2-Unsupported Hardware%0
//
#define MSG_UNSUPPORTED_HARDWARE_PNP_SUBGROUP 0x00004EDAL

//
// MessageId: MSG_HARDWARE_UNSUPPORTED_INSTRUCTIONS
//
// MessageText:
//
//  Hardware That Will Not Work With Windows XP
//  
//  The following devices are not supported by Windows XP. If you upgrade to Windows XP, these devices will not work. For a list of compatible hardware, see the Microsoft Windows XP Hardware Compatibility List at:
//  
//  http://www.microsoft.com/isapi/redir.dll?Prd=Whistler&Ar=Help&Sba=compatible
//  
//
#define MSG_HARDWARE_UNSUPPORTED_INSTRUCTIONS 0x00004EDBL

//
// MessageId: MSG_HARDWARE_UNSUPPORTED_INSTRUCTIONS_HTML
//
// MessageText:
//
//  <UL><B>Hardware That Will Not Work With Windows XP</B><BR>
//  The following devices are not supported by Windows XP. If you upgrade to Windows XP, these devices will not work. For a list of compatible hardware, see the <A HREF="http://www.microsoft.com/isapi/redir.dll?Prd=Whistler&Ar=Help&Sba=compatible">Microsoft Windows XP Hardware Compatibility List</A>.
//  <P>
//
#define MSG_HARDWARE_UNSUPPORTED_INSTRUCTIONS_HTML 0x00004EDCL

//
// MessageId: MSG_INCOMPATIBLE_PREINSTALLED_UTIL_SUBGROUP
//
// MessageText:
//
//  1-IncompatibleOemUtil%0
//
#define MSG_INCOMPATIBLE_PREINSTALLED_UTIL_SUBGROUP 0x00004EDDL

//
// MessageId: MSG_PREINSTALLED_UTIL_INSTRUCTIONS
//
// MessageText:
//
//  Incompatible Factory-Installed Programs
//  
//  The following programs came with your computer, and they do not support Windows XP and will not work after the upgrade. Check with your computer manufacturer to find out if updated versions are available on its Web site.
//  
//
#define MSG_PREINSTALLED_UTIL_INSTRUCTIONS 0x00004EDEL

//
// MessageId: MSG_PREINSTALLED_UTIL_INSTRUCTIONS_HTML
//
// MessageText:
//
//  <UL><B>Incompatible Factory-Installed Programs</B><BR>
//  The following programs came with your computer, and they do not support Windows XP and will not work after the upgrade. Check with your computer manufacturer to find out if updated versions are available on its Web site.
//  <P>
//  <UL>%0
//
#define MSG_PREINSTALLED_UTIL_INSTRUCTIONS_HTML 0x00004EDFL

//
// MessageId: MSG_INCOMPATIBLE_UTIL_SIMILAR_FEATURE_SUBGROUP
//
// MessageText:
//
//  !IncompatibleOemUtilSimilarFeature%0
//
#define MSG_INCOMPATIBLE_UTIL_SIMILAR_FEATURE_SUBGROUP 0x00004EE0L

//
// MessageId: MSG_PREINSTALLED_SIMILAR_FEATURE
//
// MessageText:
//
//  Incompatible Programs Similar to Windows XP Features
//  
//  The following programs do not support Windows XP. Similar functionality is provided by Windows XP, so these programs aren't required after you upgrade.
//  
//
#define MSG_PREINSTALLED_SIMILAR_FEATURE 0x00004EE1L

//
// MessageId: MSG_PREINSTALLED_SIMILAR_FEATURE_HTML
//
// MessageText:
//
//  <UL><B>Incompatible Programs Similar to Windows XP Features</B><BR>
//  The following programs do not support Windows XP. Similar functionality is provided by Windows XP, so these programs aren't required after you upgrade.
//  <P>
//  <UL>%0
//
#define MSG_PREINSTALLED_SIMILAR_FEATURE_HTML 0x00004EE2L

//
// MessageId: MSG_INCOMPATIBLE_HW_UTIL_SUBGROUP
//
// MessageText:
//
//  !IncompatibleIhvUtil%0
//
#define MSG_INCOMPATIBLE_HW_UTIL_SUBGROUP 0x00004EE3L

//
// MessageId: MSG_HW_UTIL_INTRO
//
// MessageText:
//
//  Incompatible Hardware Accessories
//  
//  The following programs support your computer hardware; however, they are incompatible with Windows XP.  To see whether updated versions of these programs are available, visit your hardware manufacturer's Web site.
//  
//
#define MSG_HW_UTIL_INTRO                0x00004EE4L

//
// MessageId: MSG_HW_UTIL_INTRO_HTML
//
// MessageText:
//
//  <UL><B>Incompatible Hardware Accessories</B><BR>
//  The following programs support your computer hardware; however, they are incompatible with Windows XP.  To see whether updated versions of these programs are available, visit your hardware manufacturer's Web site.
//  <P>
//  <UL>%0
//
#define MSG_HW_UTIL_INTRO_HTML           0x00004EE5L

//
// MessageId: MSG_BLOCKING_HARDWARE_SUBGROUP
//
// MessageText:
//
//  Unsupported Hardware Configuration%0
//
#define MSG_BLOCKING_HARDWARE_SUBGROUP   0x00004EE6L

//
// MessageId: MSG_DARWIN_NOT_HANDLED_SUBGROUP
//
// MessageText:
//
//  Windows Installer%0
//
#define MSG_DARWIN_NOT_HANDLED_SUBGROUP  0x00004EE7L

//
// MessageId: MSG_DARWIN_NOT_HANDLED
//
// MessageText:
//
//  Setup has detected applications installed with a version of Windows Installer that is not compatible with Windows XP. If you continue, you will need to reinstall these applications from their original source.%0
//
#define MSG_DARWIN_NOT_HANDLED           0x00004EE8L

// %1 - system drive letter, %2 - space to be freed, %3 - ~ls size, %4 - non-system drive option requirment, in mb, %5 - backup image size
//
// MessageId: MSG_REPORT_NOT_ENOUGH_DISK_SPACE_FOR_BACKUP
//
// MessageText:
//
//  Your computer does not have enough disk space to save your current version of Windows for backup. You can cancel Setup now, free additional disk space, and then restart Setup.  You need at least %2 MB free space on drive %1. If you continue, you will not have the ability to uninstall Windows XP.%0
//
#define MSG_REPORT_NOT_ENOUGH_DISK_SPACE_FOR_BACKUP 0x00004EE9L

//***************************************************************************
//
// Blocking Issues
//
//***************************************************************************
//
// MessageId: MSG_BLOCKING_ITEMS_ROOT
//
// MessageText:
//
//  Blocking Issues%0
//
#define MSG_BLOCKING_ITEMS_ROOT          0x00004EEAL

//
// MessageId: MSG_BLOCKING_ITEMS_OTHER
//
// MessageText:
//
//  Installation Requirements
//  -------------------------
//  
//
#define MSG_BLOCKING_ITEMS_OTHER         0x00004EEBL

//
// MessageId: MSG_BLOCKING_ITEMS_OTHER_HTML
//
// MessageText:
//
//  <B>Installation Requirements</B><BR>
//
#define MSG_BLOCKING_ITEMS_OTHER_HTML    0x00004EECL

//
// MessageId: MSG_BLOCKING_HARDWARE_INTRO
//
// MessageText:
//
//  Unsupported Hardware Configuration
//  ----------------------------------
//  Your computer has hardware devices that prohibit you from upgrading to Windows XP.
//  
//
#define MSG_BLOCKING_HARDWARE_INTRO      0x00004EEDL

//
// MessageId: MSG_BLOCKING_HARDWARE_INTRO_HTML
//
// MessageText:
//
//  <B>Unsupported Hardware Configuration</B><BR>
//  Your computer has hardware devices that prohibit you from upgrading to Windows XP.
//  <P>
//  <UL>%0
//
#define MSG_BLOCKING_HARDWARE_INTRO_HTML 0x00004EEEL

// %1 - system drive letter, %2 - space to be freed, %3 - ~ls size, %4 - non-system drive option requirment, in mb, %5 - backup image size
//
// MessageId: MSG_NOT_ENOUGH_DISK_SPACE_WITH_LOCALSOURCE_AND_BACKUP
//
// MessageText:
//
//  Your computer does not have enough disk space to completely install Windows XP. You must free additional disk space before you can upgrade. You need at least %2 MB free space on drive %1, or at least %3 MB on any other drive. If you want to be able to undo the upgrade, a backup will require %5 MB more on any drive.%0
//
#define MSG_NOT_ENOUGH_DISK_SPACE_WITH_LOCALSOURCE_AND_BACKUP 0x00004EEFL

// %1 - system drive letter, %2 - space to be freed, %3 - ~ls size, %4 - non-system drive option requirment, in mb, %5 - backup image size
//
// MessageId: MSG_NOT_ENOUGH_DISK_SPACE_WITH_LOCALSOURCE_AND_WINDIR_AND_BACKUP
//
// MessageText:
//
//  Your computer does not have enough disk space to completely install Windows XP. You must free additional disk space before you can upgrade. You need at least %2 MB free space on drive %1, or you need at least %4 MB on drive %1 and %3 MB on any other drive. If you want to be able to undo the upgrade, a backup will require %5 MB more on any drive.%0
//
#define MSG_NOT_ENOUGH_DISK_SPACE_WITH_LOCALSOURCE_AND_WINDIR_AND_BACKUP 0x00004EF0L

//***************************************************************************
//
// Software That Must Be Reinstalled (part 2)
//
//***************************************************************************
//
// MessageId: MSG_REINSTALL_INTRO
//
// MessageText:
//
//  Software That Must Be Reinstalled
//  ---------------------------------
//  The following programs need to be reinstalled after the upgrade, because they use different files and settings in Windows XP.
//  
//
#define MSG_REINSTALL_INTRO              0x00004EF1L

//
// MessageId: MSG_REINSTALL_INTRO_HTML
//
// MessageText:
//
//  <B>Software That Must Be Reinstalled</B><BR>
//  The following programs need to be reinstalled after the upgrade, because they use different files and settings in Windows XP.
//  <P>
//
#define MSG_REINSTALL_INTRO_HTML         0x00004EF2L

// NOTE: the next 2 messages (starting with !) don't need localization
//
// MessageId: MSG_REINSTALL_DETAIL_SUBGROUP
//
// MessageText:
//
//  !ReinstallDetail%0
//
#define MSG_REINSTALL_DETAIL_SUBGROUP    0x00004EF3L

//
// MessageId: MSG_REINSTALL_LIST_SUBGROUP
//
// MessageText:
//
//  !ReinstallList%0
//
#define MSG_REINSTALL_LIST_SUBGROUP      0x00004EF4L

//
// MessageId: MSG_REPORT_INCOMPATIBLE_INSTRUCTIONS
//
// MessageText:
//
//  This section lists information about programs that are incompatible with Windows XP. Before upgrading, evaluate how important these programs are to you.
//  
//
#define MSG_REPORT_INCOMPATIBLE_INSTRUCTIONS 0x00004EF5L

//
// MessageId: MSG_REPORT_INCOMPATIBLE_INSTRUCTIONS_HTML
//
// MessageText:
//
//  This section lists information about programs that are incompatible with Windows XP. Before upgrading, evaluate how important these programs are to you.<P>
//
#define MSG_REPORT_INCOMPATIBLE_INSTRUCTIONS_HTML 0x00004EF6L

// NOTE: the next 2 messages (starting with !) don't need localization
//
// MessageId: MSG_INCOMPATIBLE_DETAIL_SUBGROUP
//
// MessageText:
//
//  !IncompatibleDetail%0
//
#define MSG_INCOMPATIBLE_DETAIL_SUBGROUP 0x00004EF7L

//
// Network incompatibility text
//
// %1 is name of protocol, i.e., Banyan Vines
//
// MessageId: MSG_UNSUPPORTED_PROTOCOL
//
// MessageText:
//
//  %1 is incompatible with Windows XP. You must obtain Windows XP-compatible software from the manufacturer of this component.%0
//
#define MSG_UNSUPPORTED_PROTOCOL         0x00004EF8L

// %2 is the protocol vendor, i.e., Banyan
//
// MessageId: MSG_UNSUPPORTED_PROTOCOL_KNOWN_MFG
//
// MessageText:
//
//  %1 is incompatible with Windows XP. You must obtain Windows XP-compatible software from %2, the manufacturer of this component.%0
//
#define MSG_UNSUPPORTED_PROTOCOL_KNOWN_MFG 0x00004EF9L

//
// MessageId: MSG_NETWORK_PROTOCOLS
//
// MessageText:
//
//  Network Incompatibilities\%1%0
//
#define MSG_NETWORK_PROTOCOLS            0x00004EFAL

// Unusual condition where RAS settings can't be obtained.
//
// MessageId: MSG_RAS_COMPONENT
//
// MessageText:
//
//  <unused>%0
//
#define MSG_RAS_COMPONENT                0x00004EFBL

//
// MessageId: MSG_RAS_MESSAGE
//
// MessageText:
//
//  <unused>%0
//
#define MSG_RAS_MESSAGE                  0x00004EFCL

//
// MessageId: MSG_PRO_SUPPORT_LINK
//
// MessageText:
//
//  Microsoft Windows XP Professional Page (http://go.microsoft.com/fwlink/?LinkId=574)%0
//
#define MSG_PRO_SUPPORT_LINK             0x00004EFDL

//
// MessageId: MSG_PRO_SUPPORT_LINK_HTML
//
// MessageText:
//
//  <A HREF="http://go.microsoft.com/fwlink/?LinkId=574">Microsoft Windows XP Professional</A>%0
//
#define MSG_PRO_SUPPORT_LINK_HTML        0x00004EFEL

//
// MessageId: MSG_PER_SUPPORT_LINK
//
// MessageText:
//
//  Microsoft Windows XP Home Edition Page(http://go.microsoft.com/fwlink/?LinkId=573)%0
//
#define MSG_PER_SUPPORT_LINK             0x00004EFFL

//
// MessageId: MSG_PER_SUPPORT_LINK_HTML
//
// MessageText:
//
//  <A HREF="http://go.microsoft.com/fwlink/?LinkId=573">Microsoft Windows XP Home Edition</A>%0
//
#define MSG_PER_SUPPORT_LINK_HTML        0x00004F00L

// %1 - PER/PRO Web link
//
// MessageId: MSG_REPORT_BLOCKING_INSTRUCTIONS
//
// MessageText:
//
//  Setup found some blocking issues. You must address these issues before you can continue upgrading your computer.
//  
//
#define MSG_REPORT_BLOCKING_INSTRUCTIONS 0x00004F01L

// %1 - PER/PRO Web link
//
// MessageId: MSG_REPORT_BLOCKING_INSTRUCTIONS_HTML
//
// MessageText:
//
//  Setup found some blocking issues. You must address these issues before you can continue upgrading your computer.<P>
//  
//
#define MSG_REPORT_BLOCKING_INSTRUCTIONS_HTML 0x00004F02L

//
// MessageId: MSG_REPORT_BACKUP_INSTRUCTIONS
//
// MessageText:
//
//  Setup will automatically back up your existing version of Windows. You can restore your computer safely even if these upgrade problems remain. To uninstall Windows XP, go to Add/Remove Programs in Control Panel.
//  
//
#define MSG_REPORT_BACKUP_INSTRUCTIONS   0x00004F03L

//
// MessageId: MSG_REPORT_BACKUP_INSTRUCTIONS_HTML
//
// MessageText:
//
//  Setup will automatically back up your existing version of Windows. You can restore your computer safely even if these upgrade problems remain. To uninstall Windows XP, go to Add/Remove Programs in Control Panel.<P>
//  
//
#define MSG_REPORT_BACKUP_INSTRUCTIONS_HTML 0x00004F04L

//
// MessageId: MSG_HARDWARE_REINSTALL_PNP_INSTRUCTIONS
//
// MessageText:
//
//  Hardware That Requires Reinstallation of Drivers
//  
//  The following hardware will not work immediately after the upgrade to Windows XP. However, these devices will work if you reinstall Windows XP or Windows 2000 compatible drivers for these devices. Check the Microsoft Windows Update Web site or your hardware vendors' Web sites to obtain the latest versions.
//  
//
#define MSG_HARDWARE_REINSTALL_PNP_INSTRUCTIONS 0x00004F05L

//
// MessageId: MSG_HARDWARE_REINSTALL_PNP_INSTRUCTIONS_HTML
//
// MessageText:
//
//  <UL><B>Hardware That Requires Reinstallation of Drivers</B><BR>
//  The following hardware will not work immediately after the upgrade to Windows XP. However, these devices will work if you reinstall Windows XP or Windows 2000 compatible drivers for these devices. Check the Microsoft Windows Update Web site or your hardware vendors' Web sites to obtain the latest versions.
//  <P>
//
#define MSG_HARDWARE_REINSTALL_PNP_INSTRUCTIONS_HTML 0x00004F06L

//
// MessageId: MSG_REINSTALL_HARDWARE_PNP_SUBGROUP
//
// MessageText:
//
//  3-Reinstall Hardware%0
//
#define MSG_REINSTALL_HARDWARE_PNP_SUBGROUP 0x00004F07L

//
// MessageId: MSG_CONNECTION_PASSWORD_SUBGROUP
//
// MessageText:
//
//  Dial-Up Networking Passwords Will Not Be Remembered%0
//
#define MSG_CONNECTION_PASSWORD_SUBGROUP 0x00004F08L

//
// MessageId: MSG_CONNECTION_PASSWORD_INTRO
//
// MessageText:
//
//  Dial-Up Networking Passwords Will Not Be Remembered
//  
//  The dial-up networking passwords for the following connections will not be remembered after the upgrade. You might need to look them up or contact your Internet Service Provider if you do not remember the password.
//  
//
#define MSG_CONNECTION_PASSWORD_INTRO    0x00004F09L

//
// MessageId: MSG_CONNECTION_PASSWORD_INTRO_HTML
//
// MessageText:
//
//  <UL><B>Dial-Up Networking Passwords Will Not Be Remembered</B><BR>
//  The dial-up networking passwords for the following connections will not be remembered after the upgrade. You might need to look them up or contact your Internet Service Provider if you do not remember the password.
//  <P>
//  <UL>
//
#define MSG_CONNECTION_PASSWORD_INTRO_HTML 0x00004F0AL

//
// MessageId: MSG_BLOCKING_TOC
//
// MessageText:
//
//  Blocking Issues%0
//  
//
#define MSG_BLOCKING_TOC                 0x00004F0BL

//
// MessageId: MSG_WARNING_TOC
//
// MessageText:
//
//  Warnings%0
//  
//
#define MSG_WARNING_TOC                  0x00004F0CL

//
// MessageId: MSG_INFO_TOC
//
// MessageText:
//
//  Helpful Information%0
//  
//
#define MSG_INFO_TOC                     0x00004F0DL

//
// MessageId: MSG_BLOCKING_INTRO
//
// MessageText:
//
//  BLOCKING ISSUES
//  ===============
//  Setup found some issues that will prevent you from upgrading your Windows installation. You must fix all of these issues before you can upgrade to Windows XP.
//  
//
#define MSG_BLOCKING_INTRO               0x00004F0EL

//
// MessageId: MSG_BLOCKING_INTRO_HTML
//
// MessageText:
//
//  <HR>
//  <B>Blocking Issues</B> (<A HREF="#top">return to top</A>)<BR>
//  Setup found some issues that will prevent you from upgrading your Windows installation. You must fix all of these issues before you can upgrade to Windows XP.
//  <P>
//
#define MSG_BLOCKING_INTRO_HTML          0x00004F0FL

//
// MessageId: MSG_WARNING_INTRO
//
// MessageText:
//
//  WARNINGS
//  ========
//  The following issues might require you to obtain files from Microsoft Windows Update Web site or a manufacturer's Web site. You can still continue to upgrade to Windows XP without resolving these issues, but some hardware or software might not work. Follow the recommendations in each section.
//  
//
#define MSG_WARNING_INTRO                0x00004F10L

//
// MessageId: MSG_WARNING_INTRO_HTML
//
// MessageText:
//
//  <HR>
//  <B>Warnings</B> (<A HREF="#top">return to top</A>)<BR>
//  The following issues might require you to obtain files from Microsoft Windows Update Web site or a manufacturer's Web site. You can still continue to upgrade to Windows XP without resolving these issues, but some hardware or software might not work. Follow the recommendations in each section.
//  <P>
//
#define MSG_WARNING_INTRO_HTML           0x00004F11L

//
// MessageId: MSG_INFO_INTRO
//
// MessageText:
//
//  HELPFUL INFORMATION
//  ===================
//  The following issues are listed for your information only. You can continue the upgrade to Windows XP.
//  
//
#define MSG_INFO_INTRO                   0x00004F12L

//
// MessageId: MSG_INFO_INTRO_HTML
//
// MessageText:
//
//  <HR>
//  <B>Helpful Information</B> (<A HREF="#top">return to top</A>)<BR>
//  The following issues are listed for your information only. You can continue the upgrade to Windows XP.
//  <P>
//
#define MSG_INFO_INTRO_HTML              0x00004F13L

//
// MessageId: MSG_HARDWARE_UNSUPPORTED_INSTRUCTIONS2
//
// MessageText:
//
//  %0
//
#define MSG_HARDWARE_UNSUPPORTED_INSTRUCTIONS2 0x00004F14L

//
// MessageId: MSG_HARDWARE_UNSUPPORTED_INSTRUCTIONS_HTML2
//
// MessageText:
//
//  </UL>%0
//
#define MSG_HARDWARE_UNSUPPORTED_INSTRUCTIONS_HTML2 0x00004F15L

//
// MessageId: MSG_HARDWARE_REINSTALL_PNP_INSTRUCTIONS2
//
// MessageText:
//
//  %0
//
#define MSG_HARDWARE_REINSTALL_PNP_INSTRUCTIONS2 0x00004F16L

//
// MessageId: MSG_HARDWARE_REINSTALL_PNP_INSTRUCTIONS_HTML2
//
// MessageText:
//
//  </UL>%0
//
#define MSG_HARDWARE_REINSTALL_PNP_INSTRUCTIONS_HTML2 0x00004F17L

//
// MessageId: MSG_UNINDENT
//
// MessageText:
//
//  %0
//
#define MSG_UNINDENT                     0x00004F18L

//
// MessageId: MSG_UNINDENT_HTML
//
// MessageText:
//
//  </UL>%0
//
#define MSG_UNINDENT_HTML                0x00004F19L

//
// MessageId: MSG_UNINDENT2
//
// MessageText:
//
//  %0
//
#define MSG_UNINDENT2                    0x00004F1AL

//
// MessageId: MSG_UNINDENT2_HTML
//
// MessageText:
//
//  </UL></UL>%0
//
#define MSG_UNINDENT2_HTML               0x00004F1BL

//
// MessageId: MSG_MISC_WARNINGS_ROOT
//
// MessageText:
//
//  Miscellaneous%0
//
#define MSG_MISC_WARNINGS_ROOT           0x00004F1CL

//
// MessageId: MSG_MISC_WARNINGS_INTRO
//
// MessageText:
//
//  Miscellaneous
//  -------------
//  You should review the following issues before upgrading.
//  
//
#define MSG_MISC_WARNINGS_INTRO          0x00004F1DL

//
// MessageId: MSG_MISC_WARNINGS_INTRO_HTML
//
// MessageText:
//
//  <B>Miscellaneous</B><BR>
//  You should review the following issues before upgrading.
//  <P>
//
#define MSG_MISC_WARNINGS_INTRO_HTML     0x00004F1EL

//
// MessageId: MSG_CONTENTS_TITLE
//
// MessageText:
//
//  Contents:
//
#define MSG_CONTENTS_TITLE               0x00004F1FL

//
// MessageId: MSG_CONTENTS_TITLE_HTML
//
// MessageText:
//
//  For more information, click a topic:<P>
//
#define MSG_CONTENTS_TITLE_HTML          0x00004F20L

//
// MessageId: MSG_SHARED_USER_ACCOUNTS
//
// MessageText:
//
//  Shared User Accounts%0
//
#define MSG_SHARED_USER_ACCOUNTS         0x00004F21L

// %1-Win9x OS name ; %2 - XP profiles folder name
//
// MessageId: MSG_SHARED_USER_ACCOUNTS_MESSAGE
//
// MessageText:
//
//  Setup detected that two or more users share the same settings. Because Windows XP allows multiple users to log on simultaneously, settings cannot be shared. Setup will only transfer settings for the user account that is currently logged on. You can create new user accounts after Setup completes. To find files from %1 user accounts, search in the %2 folder.
//
#define MSG_SHARED_USER_ACCOUNTS_MESSAGE 0x00004F22L

// %1 is name of protocol, i.e., Banyan Vines
//
// MessageId: MSG_UNSUPPORTED_PROTOCOL_FROM_MICROSOFT
//
// MessageText:
//
//  This version of %1 will not work with Windows XP. To update a more recent version of this software, go to the Microsoft Web site (http://www.microsoft.com).%0
//
#define MSG_UNSUPPORTED_PROTOCOL_FROM_MICROSOFT 0x00004F23L

//
// ####################################################################################
// #
// #  last messages (a localization tool requirement)
// #
// ####################################################################################
//
//
// MessageId: MSG_LAST
//
// MessageText:
//
//  %0
//
#define MSG_LAST                         0x00007530L

//
// MessageId: MSG_UNKOWN_WINDOWS
//
// MessageText:
//
//  Windows
//
#define MSG_UNKOWN_WINDOWS               0x00007531L

