;//
;// ####################################################################################
;// #
;// #  w95upg.dll messages
;// #
;// ####################################################################################
;//
MessageId=100 SymbolicName=MSG_FIRST_WIN9X
Language=English
.


;// ***
;// *** Types of operating systems
;// ***

MessageId= SymbolicName=MSG_CHICAGO
Language=English
Windows 95%0
.

MessageId= SymbolicName=MSG_NASHVILLE
Language=English
Windows 95%0
.

MessageId= SymbolicName=MSG_MEMPHIS
Language=English
Windows 98%0
.

;// ***
;// *** NT Server block and Windows CE block
;// ***

MessageId= SymbolicName=MSG_SERVER_UPGRADE_UNSUPPORTED_INIT
Language=English
Setup cannot upgrade %1 settings to Windows XP Server. The Upgrade option is not available.%0
.

MessageId= SymbolicName=MSG_SERVER_UPGRADE_UNSUPPORTED
Language=English
Setup cannot upgrade %1 settings to Windows XP Server. Restart Setup, and select Install Windows XP.%0
.

MessageId= SymbolicName=MSG_PLATFORM_UPGRADE_UNSUPPORTED
Language=English
Setup cannot upgrade this computer to Windows XP. The Upgrade option is not available.%0
.

;// ***
;// *** Initialization failure
;// ***

MessageId= SymbolicName=MSG_DEFERRED_INIT_FAILED_POPUP
Language=English
Setup cannot run on this computer. A hardware device may have failed, or there may not be enough memory available.%0
.

;// ***
;// *** Progress bar messages
;// ***

MessageId= SymbolicName=MSG_HWCOMP_TEXT
Language=English
Hardware check%0
.

MessageId= SymbolicName=MSG_UPGRADEREPORT_TEXT
Language=English
Analyzing your computer...%0
.

MessageId= SymbolicName=MSG_PREPARING_LIST
Language=English
Preparing a list of components...%0
.

MessageId= SymbolicName=MSG_HWCOMP
Language=English
Examining your hardware...%0
.

MessageId= SymbolicName=MSG_MIGAPP
Language=English
Examining programs...%0
.

MessageId= SymbolicName=MSG_ENUMERATING_FILE_SYSTEM
Language=English
Scanning hard disks for incompatibilities...%0
.

MessageId= SymbolicName=MSG_PROCESSING_SYSTEM_FILES
Language=English
Processing system files...%0
.

MessageId= SymbolicName=MSG_PROCESSING_MIGRATIONDLLS
Language=English
Processing upgrade packs...%0
.

MessageId= SymbolicName=MSG_PROCESSING_SHELL_LINKS
Language=English
Processing system files...%0
.

MessageId= SymbolicName=MSG_PROCESSING_DOSFILES
Language=English
Processing MS-DOS configuration files...%0
.

MessageId= SymbolicName=MSG_INITIALIZING
Language=English
Preparing Setup database...%0
.

MessageId= SymbolicName=MSG_LOCATING_MIGRATION_DLLS
Language=English
Locating upgrade packs...%0
.

MessageId= SymbolicName=MSG_BEGINNING_ENUMERATION
Language=English
Examining hard disks...%0
.

;//
;// WARNING: This text is sent to NT for uninstall via the registry. This is because
;//          progress text is needed but it is too late to make UI changes. We must
;//          recycle old text. <bleck!>
;//
MessageId= SymbolicName=MSG_OLEREG
Language=English
Processing...%0
.



;// When rebuilding the hwcomp.dat file:
MessageId= SymbolicName=MSG_DECOMPRESSING
Language=English
Decompressing installation files...%0
.

;// ***
;// *** Supply Hardware Files and Supply Upgrade Packs dialogs
;// ***

;// Browse title
MessageId= SymbolicName=MSG_DRIVER_DLG_TITLE
Language=English
Select the location of the hardware files supplied by the manufacturer.%0
.

;// Browse title
MessageId= SymbolicName=MSG_UPGRADE_MODULE_DLG_TITLE
Language=English
Select the location of any upgrade packs supplied by a software manufacturer.%0
.

;// User chose Browse, then something, then OK. This popup appears because selection is invalid.
;// (User will have to Browse again.)
MessageID= SymbolicName=MSG_BAD_SEARCH_PATH
Language=English
Setup cannot search the folder you selected. Please select another folder.%0
.

;// Either no suitable drivers found, or drivers already supplied.
MessageID= SymbolicName=MSG_NO_DRIVERS_FOUND
Language=English
Setup did not find the required hardware files in the selected folder.%0
.

;// When copying the driver to the local disk... we ran out of space.
MessageID= SymbolicName=MSG_DISK_FULL
Language=English
There is not enough disk space to copy the selected files. Quit Setup, free additional disk space, and then restart Setup.%0
.

;// No upgrade packs found.
MessageID= SymbolicName=MSG_NO_MODULES_FOUND
Language=English
Setup did not find any upgrade packs in the selected folder. Select another folder and try again.%0
.

;// ***
;// *** Name change UI
;// ***

MessageId= SymbolicName=MSG_NAME_IN_USE_POPUP
Language=English
The name you specified conflicts with another setting. Click OK, and then type a different name.%0
.

MessageID= SymbolicName=MSG_RECOMMENDED_COMPUTER_NAME
Language=English
MyComputer%0
.

;//
;// - Arbitrary name used in rare cases when incompatible user names are
;//   found; must be 15 characters or less
;// - Setup appends numbers when two or more user names are incompatible
;//   (Windows User 2, Windows User 3, etc...)
;// - UI allows changing Setup's recommendations
;//

MessageID= SymbolicName=MSG_RECOMMENDED_USER_NAME
Language=English
Windows User%0
.

MessageID= SymbolicName=MSG_RECOMMENDED_WORKGROUP_NAME
Language=English
Workgroup%0
.

MessageID= SymbolicName=MSG_COMPUTERNAME_CATEGORY
Language=English
Computer Name%0
.

MessageID= SymbolicName=MSG_COMPUTERDOMAIN_CATEGORY
Language=English
Computer Domain%0
.

MessageID= SymbolicName=MSG_WORKGROUP_CATEGORY
Language=English
Workgroup%0
.

MessageID= SymbolicName=MSG_USERNAME_CATEGORY
Language=English
User Name%0
.

;// Used for other names besides computer names (i.e., domain name, workgroup name)
MessageID= SymbolicName=MSG_INVALID_COMPUTERNAME_CHAR_POPUP
Language=English
The name must be composed only of the following characters:

 Alphabetic: A-Z, a-z
 Numeric: 0-9
 Punctuation and Symbols: ! @ # $ %% ^ & ' ( ) . - _ { } ~
.

MessageID= SymbolicName=MSG_INVALID_EMPTY_NAME_POPUP
Language=English
Please specify a new name, or click Cancel to return to the previous screen.%0
.

;// Used for other names besides computer names (i.e., domain name, workgroup name)
MessageID= SymbolicName=MSG_INVALID_COMPUTERNAME_LENGTH_POPUP
Language=English
The name cannot be longer than 15 characters.%0
.

MessageID= SymbolicName=MSG_INVALID_USERNAME_CHAR_POPUP
Language=English
User names cannot use the following characters:

 " \ / [ ] : ; | = , + * ? < >
.

MessageID= SymbolicName=MSG_INVALID_USERNAME_SPACEDOT_POPUP
Language=English
User names cannot consist only of spaces and periods.%0
.

MessageID= SymbolicName=MSG_INVALID_USERNAME_LENGTH_POPUP
Language=English
User names cannot be longer than 20 characters.%0
.

MessageID= SymbolicName=MSG_INVALID_USERNAME_DUPLICATE_POPUP
Language=English
The specified user name is already in use. You should type a different user name.%0
.

;// Domain error popup when invalid domain name is entered
;// ISSUE  - because of localization constraints, this message has
;//          been moved to the end of the file

;// Domain error popup when non-existent domain name is entered
MessageID= SymbolicName=MSG_DOMAIN_NOT_RESPONDING_POPUP
Language=English
Setup could not reach the specified domain. Verify the domain name.%0
.

;// Domain error popup when no accounts are found on any domains
MessageID= SymbolicName=MSG_DOMAIN_ACCOUNT_NOT_FOUND_POPUP
Language=English
Setup cannot find a network account for this computer. Contact your network administrator.%0
.

;// Names that collide with NT, not used for display; separate names with pipe symbol (|)
MessageID= SymbolicName=MSG_NAME_COLLISION_LIST
Language=English
Administrators|Account Operators|Anonymous Logon|Authenticated Users|Backup Operators|Batch|Creator Group|Creator Owner|DIALUP|Domain Admins|Domain Guests|Domain Users|Everyone|Guest|Guests|HelpAssistant|HelpServicesGroup|INTERACTIVE|LOCAL SERVICE|NETWORK|Network Configuration Operators|NETWORK SERVICE|None|Power Users|Print Operators|Remote Desktop Users|REMOTE INTERACTIVE LOGON|Replicator|Server Operators|SERVICE|SYSTEM|TERMINAL SERVER USER|TsInternetUser|Users|MTS Administrators|MTS Impersonators|MTS_ADMIN|IMDB Trusted Users|WBEM Users|IMDB Trusted Users|%0
.

;// ***
;// *** Print and save as dialogs
;// ***

;// Error building SaveReportTo Config Option.
MessageId= SymbolicName=MSG_ERROR_CREATING_SAVETO_DIRECTORY
Language=English
Setup cannot create the SaveReportTo folder specified by the Answer File. Reports will be saved to the Windows folder instead.%0
.

;// Save As default file name
MessageId= SymbolicName=MSG_DEFAULT_REPORT_FILE
Language=English
upgrade.htm%0
.

;// prntsave.c -- to be removed soon
MessageId= SymbolicName=MSG_REPORT_SAVE_INDENT_LEN
Language=English
10%0
.

MessageID= SymbolicName=MSG_CANT_PRINT
Language=English
Setup cannot print the report. Make sure this computer is attached to a local or network printer.%0
.

;// Headers go at the top of every page on the incompatibility printout.
;// Each message has arg 1 as a page number.
MessageID= SymbolicName=MSG_REPORT_HEADER_LEFT
Language=English
Upgrade Report%0
.

MessageID= SymbolicName=MSG_REPORT_HEADER_CENTER
Language=English
%0
.

MessageID= SymbolicName=MSG_REPORT_HEADER_RIGHT
Language=English
Page %1%0
.

;// Winds up in the print spooler UI:
MessageID= SymbolicName=MSG_REPORT_DOC_NAME
Language=English
Windows XP Setup Incompatibility Report%0
.

;// We tried saving the report, but ran into an error.
MessageID= SymbolicName=MSG_CANT_SAVE
Language=English
Setup cannot save the report to your disk. Please check the disk and make sure it has enough free space.%0
.


;// ***
;// *** Disk Space
;// ***

MessageId= SymbolicName=MSG_ERROR_OUT_OF_DISK_SPACE
Language=English
Setup does not have enough disk space to continue. You will need to free %2 megabytes of space on your %1 drive before setup can continue.%0
.

;// ***
;// *** Messages written to the setupact.log or setuperr.log file
;// ***

MessageId= SymbolicName=MSG_MSGMGR_ADD
Language=English
Added incompatibility message for object %1: %2
.

;// ***
;// *** DOSMIG
;// ***

MessageId= SymbolicName=MSG_DOS_LOG_WARNING
Language=English
The following lines describe incompatible or unknown MS-DOS configuration items. Resources controlled by these lines may not function after Setup is complete.

%1%0
.

MessageId= SymbolicName=MSG_DOS_INCOMPATIBLE_ITEM
Language=English
Line %1 of %2, (Unknown)
%3%0
.

MessageId= SymbolicName=MSG_DOS_UNKNOWN_ITEM
Language=English
Line %1 of %2, (Incompatible)
%3%0
.

;// ***
;// *** Messages for user account processing
;// ***

MessageId= SymbolicName=MSG_NO_VALID_ACCOUNTS_POPUP
Language=English
Setup could not process user accounts. Start Setup again.%0
.

;// ***
;// *** Messages from the file scan on Win9x
;// ***

MessageId= SymbolicName=MSG_MODULE_REQUIRES_EXPORT_LOG
Language=English
File %1 requires export(s) not available on Windows XP.
.

MessageId= SymbolicName=MSG_ENUMDRIVES_FAILED_LOG
Language=English
An error occurred while Setup was examining drives.
.

;// ***
;// *** Messages for directory collisions
;// ***

MessageId= SymbolicName=MSG_DIR_COLLISION_LOG
Language=English
The following files will be renamed because of a collision with Windows XP folders:
%1%0
.

;// ***
;// *** Win9x-side Migration DLL processing
;// ***

;//
;// %1 - DLL path
;// %2 - Product ID (a friendly name, empty until QueryVersion completes successfully)
;// %3 - Error code
;// %4 - Entry point that failed
;//
;// Additional parameters for MSG_MIGDLL_FAILED_POPUP and MSG_MIGDLL_FAILED_LOG:
;//
;// %5 - Company Name
;// %6 - Support Phone Number
;// %7 - Support URL
;// %8 - Instructions to user from migration DLL
;// %9 - Line break if either %6, %7 or %8 is non empty
;//

MessageId= SymbolicName=MSG_MIGDLL_QV_FAILED_LOG
Language=English
The upgrade pack %1 failed in QueryVersion with error code %3. Setup cannot process this pack.
.

MessageId= SymbolicName=MSG_MIGDLL_FAILED_POPUP
Language=English
The %2 upgrade pack from %5 failed. Setup cannot process this upgrade pack.%9%8%6%7
.

MessageId= SymbolicName=MSG_MIGDLL_FAILED_LOG
Language=English
The upgrade pack %2 failed in %4 with error code %3. Setup cannot process this pack.%0
.

MessageId= SymbolicName=MSG_MIGDLL_QUERYVERSION_EXCEPTION_LOG
Language=English
Migration DLL at %1 threw an exception in QueryVersion; the DLL will not be processed.
.

MessageId= SymbolicName=MSG_MIGDLL_INITIALIZE9X_EXCEPTION_LOG
Language=English
Migration DLL %2 threw an exception in Initialize9x; the DLL will not be processed.
.

MessageId= SymbolicName=MSG_MIGDLL_MIGRATEUSER9X_EXCEPTION_LOG
Language=English
Migration DLL %2 threw an exception in MigrateUser9x; the DLL will not be processed.
.

MessageId= SymbolicName=MSG_MIGDLL_MIGRATESYSTEM9X_EXCEPTION_LOG
Language=English
Migration DLL %2 threw an exception in MigrateSystem9x; the DLL will not be processed.
.

;// ***
;// *** Account Names used for display
;// ***

MessageId= SymbolicName=MSG_DEFAULT_USER
Language=English
Logon User%0
.

MessageId= SymbolicName=MSG_ADMINISTRATOR
Language=English
Administrator%0
.

;// ***
;// *** Drive accessibility
;// ***

MessageId= SymbolicName=MSG_NO_ACCESSIBLE_DRIVES_POPUP
Language=English
Setup did not find any compatible drives on this computer. Setup cannot upgrade this computer to Windows XP.%0
.

;//
;// Other system warnings
;//

MessageId= SymbolicName=MSG_FULL_REPORT_TEXT
Language=English
Setup found hardware or software on your computer that might not work with Windows XP. You should read and understand this upgrade report before continuing. For more information, click Full Report.%0
.

MessageId= SymbolicName=MSG_FULL_REPORT_BUTTON
Language=English
&Full Report%0
.

;//
;// Checked-build Messages - shown only on checked build
;//

MessageId= SymbolicName=MSG_COMPONENT_OLE
Language=English
Installation Notes\Checked Build Warning\OLE\%2%0
.

MessageId= SymbolicName=MSG_OBJECT_POINTS_TO_DELETED_GUID
Language=English
Checked build warning: OLE object (%1) points to a deleted class ID.

.

MessageId= SymbolicName=MSG_OBJECT_POINTS_TO_DELETED_FILE
Language=English
Checked build warning: OLE object (%1) is part of a %3-specific binary that will be deleted.

.

MessageId= SymbolicName=MSG_GUID_LEAK
Language=English
Checked build warning: A %3-specific OLE object (%1) has an Interface reference to a supported object; the supported object may no longer be needed.

.

MessageId= SymbolicName=MSG_INTERFACE_BROKEN
Language=English
Checked build warning: A supported OLE object (%1) has an Interface dependency on a %3-specific object.

.

MessageId= SymbolicName=MSG_POTENTIAL_INTERFACE_LEAK
Language=English
Checked build warning: A %3-specific OLE object (%1) has a reference to a supported object; the supported object may no longer be needed.

.

MessageId= SymbolicName=MSG_PROGID_BROKEN
Language=English
Checked build warning: A supported OLE program ID (%1) has a reference to a %3-specific object.

.

MessageId= SymbolicName=MSG_POTENTIAL_PROGID_LEAK
Language=English
Checked build warning: A %3-specific OLE object (%1) has a reference to a supported program ID; the supported program ID may no longer be needed.

.

;//
;// Messages displayed during unattended operations
;//

MessageId= SymbolicName=MSG_BUILDING_REPORT_MESSAGE
Language=English
The Windows XP Upgrade Advisor is building a report for your computer's hardware and software. This report will be saved to the following location:
 %1%0
.

;// This is for an undocumented mode that we use for research at upgrade fairs, customers do not see it.
MessageId= SymbolicName=MSG_ERROR_READING_FROM_DEVICE
Language=English
Error reading from device. Click OK to try again, or click Cancel to abort.%0
.

;// This is for an undocumented mode that we use for research at upgrade fairs, customers do not see it.
MessageId= SymbolicName=MSG_INSERT_FLOPPY
Language=English
Setup requires more space to finish saving this file. Insert a new floppy disk, and click OK, or click Cancel to abort saving this file.%0
.

;//
;// Critical error messages explaining why Setup is about to puke. These conditions are extremely rare.
;//

MessageId= SymbolicName=MSG_ERROR_UNEXPECTED_ACCESSIBLE_DRIVES
Language=English
Setup encountered an error while examining your disk drives. Contact Microsoft Technical Support.%0
.

MessageId= SymbolicName=MSG_COULD_NOT_CREATE_DIRECTORY
Language=English
Setup cannot create a temporary folder. Setup cannot continue.
.

MessageId= SymbolicName=MSG_TXTSETUP_SIF_ERROR
Language=English
Setup cannot access Txtsetup.sif, a required file that comes with Windows XP. Setup cannot continue.
.

MessageId= SymbolicName=MSG_UNEXPECTED_ERROR_ENCOUNTERED
Language=English
Setup cannot continue. Contact Microsoft Technical Support. (Error: %1!X!h)
.

;//
;// Hardware compatibility
;//

MessageID= SymbolicName=MSG_OFFLINE_DEVICE
Language=English
%1</B> (not currently present)%0
.

;// UNUSED!!
MessageId= SymbolicName=MSG_HARDWARE_COMPONENT
Language=English
%0
.

MessageId= SymbolicName=MSG_HARDWARE_MESSAGE
Language=English
Windows XP does not supply a driver for the following device:

Device: %1
Manufacturer: %4
Device Type: %2
Device Class: %3
.

;//
;// Network incompatibility text
;//

;// %1 is name of protocol, i.e., Banyan Vines
MessageId= SymbolicName=MSG_UNSUPPORTED_PROTOCOL_UNUSED
Language=English
%0
.

;// %2 is the protocol vendor, i.e., Banyan
MessageId= SymbolicName=MSG_UNSUPPORTED_PROTOCOL_KNOWN_MFG_UNUSED
Language=English
%0
.

MessageId= SymbolicName=MSG_NETWORK_PROTOCOLS_UNUSED
Language=English
%0
.

;// Unusual condition where RAS settings can't be obtained.
MessageId= SymbolicName=MSG_RAS_COMPONENT_UNUSED
Language=English
%0
.

MessageId= SymbolicName=MSG_RAS_MESSAGE_UNUSED
Language=English
%0
.

;//
;// Messages added since localization began
;//
;// The localizers cannot handle changes in MessageID!
;//

MessageID= SymbolicName=MSG_ACCOUNT_NOT_FOUND_POPUP
Language=English
Setup did not find an account for your computer on the specified domain. Do you want to create an account?%0
.

MessageID= SymbolicName=MSG_FILE_COPY_ERROR
Language=English
Setup cannot copy all of its files to your computer.%0
.

;// %1 - source, %2 - dest
MessageID= SymbolicName=MSG_FILE_COPY_ERROR_LOG
Language=English
Setup cannot copy %1 to %2.
.

;// %1 - link name
MessageID= SymbolicName=MSG_NICE_PATH_START_MENU
Language=English
%1</B> (on the Start menu)%0
.

;// %1 - link name
MessageID= SymbolicName=MSG_NICE_PATH_DESKTOP
Language=English
%1</B> (on the Desktop)%0
.

;// %1 - link name
MessageID= SymbolicName=MSG_NICE_PATH_FAVORITES
Language=English
%1</B> (in Favorites)%0
.

;// %1 - link name
MessageID= SymbolicName=MSG_NICE_PATH_PROGRAMS
Language=English
%1</B> (on the Start menu)%0
.

;// %1 - link name
MessageID= SymbolicName=MSG_NICE_PATH_RECENT
Language=English
%1</B> (in Recent Documents)%0
.

;// %1 - link name
MessageID= SymbolicName=MSG_NICE_PATH_SEND_TO
Language=English
Send to %1%0
.

;// %1 - link name
MessageID= SymbolicName=MSG_NICE_PATH_START_UP
Language=English
%1</B> (on the Start menu)%0
.

;// %1 - link name
MessageID= SymbolicName=MSG_NICE_PATH_TEMPLATES
Language=English
%1</B> (in New Document Templates)%0
.

;// %1 - link name
MessageID= SymbolicName=MSG_NICE_PATH_WIN_DIR
Language=English
%1</B> (in the Windows folder)%0
.

;// %1 - link name
MessageID= SymbolicName=MSG_NICE_PATH_SYSTEM_DIR
Language=English
%1</B> (in the System folder)%0
.

;// %1 - link name
MessageID= SymbolicName=MSG_NICE_PATH_PROGRAM_FILES
Language=English
%1</B> (in Program Files)%0
.

;// %1 - link name
MessageID= SymbolicName=MSG_NICE_PATH_CONTROL_PANEL
Language=English
%1</B> (in Control Panel)%0
.

;// %1 - link name  %2 - last folder  %3 - drive
MessageID= SymbolicName=MSG_NICE_PATH_DRIVE_AND_FOLDER
Language=English
%1</B> (in %2 folder on drive %3)%0
.

;// %1 - link name  %2 - drive
MessageID= SymbolicName=MSG_NICE_PATH_DRIVE
Language=English
%1</B> (on drive %2)%0
.

;// %1 - link name  %2 - last folder
MessageID= SymbolicName=MSG_NICE_PATH_FOLDER
Language=English
%1</B> (in %2 folder)%0
.

;// %1 - link name
MessageID= SymbolicName=MSG_NICE_PATH_LINK
Language=English
%1%0
.

MessageID= SymbolicName=MSG_OFFLINE_DEVICE_PLAIN
Language=English
%1 (not currently present)%0
.


MessageID= SymbolicName=MSG_386ENH_DRIVER_LOG
Language=English
Setup found the following obsolete drivers:

%1
.

MessageID= SymbolicName=MSG_UNKNOWN_OS
Language=English
The version of Windows running is not supported. Setup can only upgrade official releases. Setup will now exit.%0
.

;// %1 - link name
MessageID= SymbolicName=MSG_NICE_PATH_SCREEN_SAVER
Language=English
%1</B> (current Screen Saver)%0
.

MessageID= SymbolicName=MSG_RESTYPE_MEMORY
Language=English
Memory Range%0
.

MessageID= SymbolicName=MSG_RESTYPE_IO
Language=English
Input/Output Range%0
.

MessageID= SymbolicName=MSG_RESTYPE_DMA
Language=English
Direct Memory Access%0
.

MessageID= SymbolicName=MSG_RESTYPE_IRQ
Language=English
Interrupt Request%0
.


MessageID= SymbolicName=MSG_FILE_NAME_FILTER
Language=English
HTML Files (*.htm)|*.htm|Text Files (*.txt)|*.txt|All Files (*.*)|*.*|%0
.


;// %1-device description %2-manufacturer %3-class %4-resource list
MessageID= SymbolicName=MSG_RESOURCE_HEADER_LOG
Language=English
The following settings may be needed to install the device on Windows XP.

  Device: %1
  Manufacturer: %2
  Device Class: %3
  Resources:
%4
.


;// %1-resource type (i.e., IRQ)  %2-resource value
;// IMPORTANT: The number between the exclaimation points (i.e., 22 on US) must be
;//            greater than length of the MSG_RESTYPE constants above.
MessageID= SymbolicName=MSG_RESOURCE_ITEM_LOG
Language=English
    %1!-22s!%2
.


MessageID= SymbolicName=MSG_AUTO_DMA
Language=English
Auto
.

;// %1 - virus application name
MessageID= SymbolicName=MSG_BAD_VIRUS_SCANNER
Language=English
Setup has determined that you are running the %1 program. This program can cause problems while installing Windows XP. You must disable this program before running Setup.

To stop the program and continue with Setup, click End Task.%0
.

;// %1 - system drive letter, %2 - space to be freed, %3 - ~ls size, %4 - non-system drive option requirment, in mb, %5 - backup image size
MessageID= SymbolicName=MSG_NOT_ENOUGH_DISK_SPACE_WITH_BACKUP
Language=English
Your computer does not have enough free disk space to install Windows XP. You need at least %2 MB free on drive %1. If you want to be able to undo the upgrade, a backup will require %5 MB more.%0
.

MessageID= SymbolicName=MSG_NOT_ENOUGH_DISKSPACE_SUBGROUP
Language=English
Disk Space%0
.

;// %1 - system drive letter, %2 - space to be freed, %3 - ~ls size, %4 - non-system drive option requirment, in mb, %5 - backup image size
MessageID= SymbolicName=MSG_NOT_ENOUGH_DISK_SPACE
Language=English
Your computer does not have enough free disk space to install Windows XP. You need at least %2 MB free on drive %1.%0
.

;// network domain account create
MessageID= SymbolicName=MSG_USER_IS_BOGUS
Language=English
The specified user name is not valid.

Contact your network administrator for information on creating a computer account.%0
.

;// network domain account create
MessageID= SymbolicName=MSG_USER_IS_CURRENT_USER
Language=English
Your user account must have permission to add computers to the domain.  Normally, only special accounts and network administrators have this permission.

Are you sure you have permission to add computer accounts to the domain?%0
.

MessageID= SymbolicName=MSG_CONTACT_NET_ADMIN
Language=English
Contact your network administrator for assistance with your computer account before continuing the upgrade to Windows XP.%0
.

MessageID= SymbolicName=MSG_KILL_APPLICATION
Language=English
&End Task%0
.

MessageID= SymbolicName=MSG_QUIT_SETUP
Language=English
&Quit Setup%0
.

;// Message when error 5, 32, 53, 54, 55, 65, 66, 67, 68, 88, 123, 148, 1203,
;// 1222, 1231 or 2250 causes setup to die
MessageID= SymbolicName=MSG_ACCESS_DENIED
Language=English
Setup could not access one or more files. Possible causes of this error are:

1. You do not have the correct network permissions
2. The network or CD-ROM is no longer accessible
3. A file might be locked by someone else on the network

Please check your network or CD-ROM, then restart Setup.%0
.

MessageID= SymbolicName=MSG_AUTODETECT_FRAMETYPE
Language=English
Setup could not directly map your IPX Frame Type. After the upgrade is complete, the frame type will be set to auto detect.%0
.

;// %1 - link name
MessageID= SymbolicName=MSG_NICE_PATH_RUN_KEY
Language=English
%1</B> (a startup program)%0
.

;// This message is used to recommend a new computer name
;// %1 - user name
MessageID= SymbolicName=MSG_COMPUTER_REPLACEMENT_NAME
Language=English
%1-COMP%0
.

;// %1 - drive letter of media to eject (A, C, D, etc...)
MessageID= SymbolicName=MSG_REMOVE_DRIVER_DISK
Language=English
Remove the driver disk from drive %1, then click OK to continue.%0
.

;// %1 - file names that could not be renamed and will be deleted
MessageId= SymbolicName=MSG_DIR_COLLISION_DELETE_LOG
Language=English
The following files will be deleted because of a collision with Windows XP folders:
%1%0
.

;// %1 - file name that could not be renamed
MessageID= SymbolicName=MSG_CANNOT_RENAME_FILE
Language=English
Setup cannot rename file %1. Please close all running applications then press Retry.%0
.

;// caption of the first button on Retry File Rename dialog
MessageID= SymbolicName=MSG_RETRY_RENAME
Language=English
&Retry Rename%0
.

;// C:\Documents and Settings
MessageID= SymbolicName=MSG_USER_PROFILE_ROOT
Language=English
%%SystemDrive%%\Documents and Settings%0
.


MessageID= SymbolicName=MSG_NO_NECESSARY_MODULES_FOUND
Language=English
Setup found upgrade packs in the selected folder, but they are not needed for your computer.%0
.

MessageID= SymbolicName=MSG_DEFAULT_WORKGROUP
Language=English
WORKGROUP%0
.

MessageID= SymbolicName=MSG_DOMAIN_HELP
Language=English
You must obtain domain information from your network administrator in order to join this computer to a domain.%0
.

;// %1 - minimum time estimate, %2 - maximum time estimate, %3 - current OS name
MessageID= SymbolicName=MSG_LAST_PAGE
Language=English
Setup is now ready to install Windows XP. The upgrade takes approximately %1 to %2 minutes, and your computer will restart three times.
.

;// %1 - minimum time estimate, %2 - maximum time estimate, %3 - current OS name
MessageID= SymbolicName=MSG_LAST_PAGE_WITH_NTFS_CONVERSION
Language=English
Setup is now ready to install Windows XP. The upgrade takes approximately %1 to %2 minutes, plus additional time to convert to NTFS. Your computer will restart four times.
.


;// %1 - win95 name.
MessageID= SymbolicName=MSG_OTHER_OS_FOUND_EARLY_POPUP
Language=English
You cannot upgrade your %1 installation to Windows XP because you have more than one operating system installed on your computer. Upgrading one operating system can cause problems with files shared by the other operating system, and is therefore not permitted.%0
.


MessageID= SymbolicName=MSG_CANCEL_BUTTON
Language=English
&Cancel%0
.

MessageID= SymbolicName=MSG_REVIEW_BUTTON
Language=English
&Review%0
.

MessageID= SymbolicName=MSG_BLOCKING_FILE_BLOCK_UNATTENDED
Language=English
Setup has found programs installed on your computer that must be removed before an upgrade can be attempted. If you wish to review the upgrade report click Review. Otherwise, to quit setup click Quit.%0
.

MessageId= SymbolicName=MSG_BLOCKING_HARDWARE_BLOCK
Language=English
Because your computer has a hardware configuration that is not supported by Windows XP, you cannot continue. Setup will now exit.
.


MessageID= SymbolicName=MSG_BLOCKING_HARDWARE_BLOCK_UNATTENDED
Language=English
Because your computer has a hardware configuration that is not supported by Windows XP, you cannot continue. If you wish to review the upgrade report click Review. Otherwise, to quit setup click Quit.%0
.

MessageID= SymbolicName=MSG_QUIT_BUTTON
Language=English
&Quit%0
.

MessageId= SymbolicName=MSG_UNEXPECTED_ERROR_ENCOUNTERED_NORC
Language=English
Setup cannot continue. Contact Microsoft Technical Support.
.

MessageId= SymbolicName=MSG_PLEASE_SPECIFY_A_DOMAIN
Language=English
To join a domain, you must specify a domain name.
.

MessageId= SymbolicName=MSG_FINISH
Language=English
Finish%0
.

MessageId= SymbolicName=MSG_MILLENNIUM
Language=English
Windows Millennium Edition%0
.

MessageId= SymbolicName=MSG_WIN95UPG_RELOAD_FAILED
Language=English
Setup failed to load the information file %1 and cannot continue.

Contact Microsoft Technical Support.%0
.

MessageID= SymbolicName=MSG_NOT_ENOUGH_DISK_SPACE_FOR_BACKUP
Language=English
Your computer does not have enough disk space to save your current version of Windows for backup. You can cancel Setup now, free additional disk space, and then restart Setup.  You need at least %2 MB free space on drive %1.

If you continue, you will not have the ability to uninstall Windows XP.

Do you want to cancel Setup now to free additional disk space? (recommended)%0
.

MessageId= SymbolicName=MSG_DISK_SPACE
Language=English
%1 MB%0
.

MessageId= SymbolicName=MSG_DISK_AND_FREE_DISK_SPACE
Language=English
&%1 - %2 MB Free%0
.

MessageId= SymbolicName=MSG_LONG_BACKUP_PATH
Language=English
Length of PathForBackup is too long: %1%0
.

;// Names that collide with NT, not used for display; separate names with pipe symbol (|)
MessageID= SymbolicName=MSG_NAME_COLLISION_LIST_PER
Language=English
Administrators|Account Operators|Anonymous Logon|Authenticated Users|Backup Operators|Batch|Creator Group|Creator Owner|DIALUP|Domain Admins|Domain Guests|Domain Users|Everyone|Guest|Guests|Owner|HelpAssistant|HelpServicesGroup|INTERACTIVE|LOCAL SERVICE|NETWORK|Network Configuration Operators|NETWORK SERVICE|None|Power Users|Print Operators|Remote Desktop Users|REMOTE INTERACTIVE LOGON|Replicator|Server Operators|SERVICE|SYSTEM|TERMINAL SERVER USER|TsInternetUser|Users|MTS Administrators|MTS Impersonators|MTS_ADMIN|IMDB Trusted Users|WBEM Users|IMDB Trusted Users|%0
.

MessageId= SymbolicName=MSG_STOP_BECAUSE_CANT_BACK_UP
Language=English
There is not enough disk space on any disk to store a backup of the original operating system, and EnableBackup=Required was specified in the /unattend script. Setup cannot continue.%0
.

;// %1 - path specified in unattend script
MessageId= SymbolicName=MSG_STOP_BECAUSE_CANT_BACK_UP_2
Language=English
There is not enough disk space on %1 to store a backup of the original operating system, and EnableBackup=Required was also specified in the /unattend script. Setup cannot continue.%0
.


MessageID= SymbolicName=MSG_BAD_VIRUS_SCANNER_STOP
Language=English
Setup has determined that you are running the %1 program. This program can cause problems while installing Windows XP. You must disable or uninstall this program before continuing Setup.
Some programs can be uninstalled using Add or Remove Programs in Control Panel. To disable the program, refer to the program documentation.
.

MessageID= SymbolicName=MSG_RESTART_IF_CONTINUE_APPWIZCPL
Language=English
You now have the opportunity to remove incompatible applications. If you proceed, Setup will restart when you press Next.

Click Yes to run Add/Remove Programs
Click No to continue Setup
.

MessageID= SymbolicName=MSG_REPORT_HEADER_BLOCKING_ISSUES_SHORT
Language=English
Setup found some blocking issues. You must address these issues before you can continue upgrading your computer. For more information, click Full Report.
.

MessageID= SymbolicName=MSG_REPORT_HEADER_BLOCKING_ISSUES
Language=English
Setup found some blocking issues. You must address these issues before you can continue upgrading your computer. For more information, click Full Details.
.

MessageID= SymbolicName=MSG_INVALID_USERNAME_TRAILINGDOT_POPUP
Language=English
A name cannot end in a period.%0
.

MessageID= SymbolicName=MSG_ALL_USERS
Language=English
All Users%0
.
;//
;// ####################################################################################
;// #
;// #  w95upgnt.dll messages
;// #
;// ####################################################################################
;//

MessageId=5000 SymbolicName=MSG_PROFILE_ERROR
Language=English
Setup cannot create a user profile for %1. This user account cannot be upgraded. After Setup completes, re-create the account.%0
.

MessageId= SymbolicName=MSG_MIGRATING_SHELL
Language=English
Upgrading desktop and Start menu...%0
.

MessageId= SymbolicName=MSG_MIGRATING_PLATFORM_SETTINGS
Language=English
Upgrading %1 settings...%0
.

MessageId= SymbolicName=MSG_MIGRATING_DEFAULT_USER
Language=English
Upgrading logon settings...%0
.

MessageId= SymbolicName=MSG_MIGRATING_USER
Language=English
Upgrading user settings...%1%0
.

MessageId= SymbolicName=MSG_MIGRATED_ACCOUNT_DESCRIPTION
Language=English
Account upgraded from %1%0
.

MessageId= SymbolicName=MSG_UNABLE_TO_CREATE_SHARE
Language=English
Setup cannot share %2 as %1. After Setup completes, you should manually create this full-access share.%0
.

MessageId= SymbolicName=MSG_UNABLE_TO_CREATE_RO_SHARE
Language=English
Setup cannot share %2 as %1. After Setup completes, you should manually create this read-only share.%0
.

MessageId= SymbolicName=MSG_UNABLE_TO_CREATE_ACL_SHARE
Language=English
Setup cannot share %2 as %1. After Setup completes, you should manually create this share and restore the user access list.%0
.

;// %1 - user name, %2 - share name, %3 - share path
MessageId= SymbolicName=MSG_NO_USER_SID
Language=English
Because Setup could not locate an account for %1, the account was removed from the share %2 (%3). After Setup completes, you should manually add this account to the share.%0
.

;// %1 - share name, %2 - share path
MessageId= SymbolicName=MSG_ALL_SIDS_BAD
Language=English
Setup cannot locate any accounts for the %1 share (%2). The Setup log contains a list of accounts for %1. After Setup completes, you should manually add accounts to the share.%0
.

MessageId= SymbolicName=MSG_MANY_SIDS_BAD
Language=English

Setup cannot locate %1!u! of %2!u! accounts for the %3 share (%4). The Setup log contains a list of accounts that could not be added to %1. After Setup completes, you should manually add these accounts to the share.%0
.

;// %1 - product ID, %2 - ?, %3 - function
MessageId= SymbolicName=MSG_EXCEPTION_MIGRATE_INIT_NT
Language=English
The module for %1 failed unexpectedly during initialization.%0
.

MessageId= SymbolicName=MSG_EXCEPTION_MIGRATE_USER_NT
Language=English
The module for %1 failed unexpectedly while processing %3.%0
.

MessageId= SymbolicName=MSG_EXCEPTION_MIGRATE_SYSTEM_NT
Language=English
The module for %1 failed unexpectedly while processing the system settings.%0
.

MessageId= SymbolicName=MSG_PROCESSING_MIGRATION_DLLS
Language=English
Processing upgrade packs...%0
.

MessageId= SymbolicName=MSG_MIGRATING_ADMINISTRATOR
Language=English
Upgrading Administrator account...%0
.

;// %1 - Dospath
MessageId= SymbolicName=MSG_BOOT16_STARTUP_COMMENT
Language=English
ECHO You are using automatically generated configuration files.
ECHO Your original configuration files have been renamed
ECHO Config.upg and Autoexec.upg and are located in the %1 Directory.
ECHO.
.


;// %1 - Product Name
;// %2 - Company Name
;// %3 - Support Phone (with line break), see MSG_MIGDLL_SUPPORT_PHONE_FIXUP
;// %4 - Support URL (with line break), see MSG_MIGDLL_SUPPORT_URL_FIXUP
;// %5 - Instructions to user from DLL (with line break), see MSG_MIGDLL_INSTRUCTIONS_FIXUP
;// %6 - Line break if either %3, %4 or %5 is not empty
MessageId= SymbolicName=MSG_CREATE_PROCESS_ERROR
Language=English
Setup cannot process the %1 upgrade pack from %2.%6%5%3%4
.

;// %1 - Product Name
;// %2 - Company Name
;// %3 - Support Phone (with line break), see MSG_MIGDLL_SUPPORT_PHONE_FIXUP
;// %4 - Support URL (with line break), see MSG_MIGDLL_SUPPORT_URL_FIXUP
;// %5 - Instructions to user from DLL (with line break), see MSG_MIGDLL_INSTRUCTIONS_FIXUP
;// %6 - Line break if either %3, %4 or %5 is not empty
MessageId= SymbolicName=MSG_MIGDLL_ERROR
Language=English
Setup cannot process the %1 upgrade pack from %2.%6%5%3%4
.

MessageId= SymbolicName=MSG_DEFAULT_MIGDLL_DESC
Language=English
(unknown program)%0
.

;// %1 - Windows 95 or Windows 98
MessageId= SymbolicName=MSG_MIGRATION_IS_TOAST
Language=English
Setup cannot upgrade some settings. After Setup completes, you may need to reinstall one or more programs.%0
.

MessageId= SymbolicName=MSG_SYSTEM_DIR
Language=English
SYSTEM%0
.

MessageId= SymbolicName=MSG_PROGRAM_FILES_DIR
Language=English
c:\Program Files%0
.

MessageId= SymbolicName=MSG_DMNT_APPENDSTRING
Language=English

REM
REM *************************************************
REM ** Lines below this have been migrated from the
REM ** original %1 settings.
REM *************************************************
REM

%0
.

MessageId= SymbolicName=MSG_GETANYDC_RETRY
Language=English
Setup cannot locate a server for the %1 domain. To upgrade one or more users, Setup needs a server connection. Would you like Setup to search again?%0
.

MessageId= SymbolicName=MSG_ALL_USERS_ARE_LOCAL
Language=English
Because this computer is not joined to a domain, Setup cannot upgrade your domain accounts. Setup will create accounts that do not have domain access.%0
.

MessageId= SymbolicName=MSG_GETPRIMARYDC_RETRY
Language=English
Setup is trying to determine if any user accounts are on the %1 domain, but the domain is not responding.  Would you like Setup to try again?%0
.

MessageId= SymbolicName=MSG_NULSESSION_RETRY
Language=English
Setup cannot connect to server %1 of the %2 domain. This connection is necessary for the correct upgrade of users who log on to %2.

Would you like Setup to try again, connecting to another server if possible?%0
.

MessageId= SymbolicName=MSG_SID_RETRY
Language=English
Setup cannot obtain security settings for %1. Would you like Setup to try again?%0
.

MessageId= SymbolicName=MSG_CREATE_ACCOUNT_FAILED
Language=English
Setup encountered an error while creating an account for %1. This user's settings will be lost.%0
.

MessageId= SymbolicName=MSG_SID_LOOKUP_FAILED
Language=English
Setup encountered an error while obtaining the security identifier for %1. This user's settings will be lost.%0
.

MessageId= SymbolicName=MSG_SEARCHING_DOMAINS
Language=English
Looking up network user accounts...%0
.

MessageId= SymbolicName=MSG_SEARCHING_A_DOMAIN
Language=English
Looking up accounts in the %1 domain...%0
.

MessageId= SymbolicName=MSG_USER_SINGULAR
Language=English
user%0
.

MessageId= SymbolicName=MSG_USERS_PLURAL
Language=English
users%0
.

MessageId= SymbolicName=MSG_ACCOUNT_RESOLVE_INSTRUCTIONS_SINGULAR
Language=English
A network account could not be determined for %1 user. Select an action to take for this user.%0
.

MessageId= SymbolicName=MSG_ACCOUNT_RESOLVE_INSTRUCTIONS_PLURAL
Language=English
A network account could not be determined for %1 users. Select an action to take for each user.%0
.

;//
;// STF processing:
;//    %1 is STF file path
;//    %2 is INF file path associated with STF (for MSG_STF_MISSING_INF_LOG only)
;//

MessageId= SymbolicName=MSG_COULD_NOT_PROCESS_STF_LOG
Language=English
Windows XP Setup cannot process the file %1. You may encounter problems uninstalling or reinstalling programs that need this file.%0
.

MessageId= SymbolicName=MSG_STF_MISSING_INF_LOG
Language=English
Windows XP Setup could perform only limited processing on %1 because %2 is missing. You may encounter problems uninstalling or reinstalling programs that need this file.%0
.

;//
;// Account names
;//

MessageId= SymbolicName=MSG_EVERYONE_GROUP
Language=English
Everyone%0
.

MessageId= SymbolicName=MSG_ADMINISTRATORS_GROUP
Language=English
Administrators%0
.

MessageId= SymbolicName=MSG_DOMAIN_USERS_GROUP
Language=English
Domain Users%0
.

MessageId= SymbolicName=MSG_NONE_GROUP
Language=English
none%0
.

;//
;// INI file mapping
;//

MessageId= SymbolicName=MSG_INI_FILE_MAPPING_LOG
Language=English
At least one error occurred while processing the INI file settings. Some 16-bit programs may function incorrectly after the upgrade.
.

MessageId= SymbolicName=MSG_INI_FILE_CONVERSION_LOG
Language=English
At least one error occurred while converting INI files. Some 16-bit programs may function incorrectly after the upgrade.
.

MessageId= SymbolicName=MSG_UNABLE_TO_MIGRATE_TAPI_DIALING_LOCATIONS
Language=English
At least one error occurred while upgrading dialing locations. After the upgrade is complete, you may need to reset your area code and other dialing options.
.

MessageId= SymbolicName=MSG_ERROR_MIGRATING_PHONEBOOK_ENTRIES
Language=English
At least one error occurred while upgrading the phonebook entries for %1. You may need to recreate some phonebook entries for this user.
.

MessageId= SymbolicName=MSG_PROFILE_LOOKUP_FAILED
Language=English
Setup encountered an error while obtaining the profile folder for %1. This user's settings will be lost.%0
.

;// %1 - file path %2 - error code (unsigned int)
MessageId= SymbolicName=MSG_COULD_NOT_MOVE_FILE_LOG
Language=English
Setup encountered an error while processing %1. Error code: %2!u!%0
.

;//
;// Messages that are out of order (because of localization tool constraints)
;//

;// Title for NT Domain Resolution dialog
;//
;// %1 - user name
MessageId= SymbolicName=MSG_USER_DOMAIN_LOGON_DLG
Language=English
Domains: (for %1)%0
.

;// Text that appears in the NT Domain Resolution dialog, a user option in a combo box
MessageId= SymbolicName=MSG_DOMAIN_NOT_LISTED_DLG
Language=English
(Search again)%0
.

;// Text that appears in the NT Domain Resolution dialog, a user option in a combo box
MessageId= SymbolicName=MSG_LOCAL_ACCOUNT_DLG
Language=English
(Local account)%0
.

;// Status text, %1 - current domain name, %2 - current domain number (UINT), %3 - total domains (UINT)
MessageId= SymbolicName=MSG_DOMAIN_STATUS_POPUP
Language=English
Processing domain %1 (%2!u! of %3!u!)%0
.

;// Initial message for domain lookup status popup
MessageId= SymbolicName=MSG_INITIAL_STATUS_MSG
Language=English
Building a list of domains%0
.

;// Power Users local group
MessageId= SymbolicName=MSG_POWER_USERS_GROUP
Language=English
Power Users%0
.

;// Error migrating a briefcase, %1 - Briefcase Directory
MessageId= SymbolicName=MSG_ERROR_MIGRATING_BRIEFCASE
Language=English
An error occured while converting briefcase %1%0
.

MessageId= SymbolicName=MSG_OWNERS_GROUP
Language=English
Owners%0
.

MessageId= SymbolicName=MSG_UNINSTALL_DISPLAY_STRING
Language=English
Windows XP Uninstall%0
.

;// %1 - Boot.ini path, %2 - Boot.~t path
MessageId= SymbolicName=MSG_BOOT_INI_MOVE_FAILED
Language=English
Unable to move %1 to %2%0
.

;// %1 - Boot.ini path
MessageId= SymbolicName=MSG_BOOT_INI_SAVE_FAILED
Language=English
Unable to save %1%0
.

;// %1 - temp dir path
MessageId= SymbolicName=MSG_LEFT_TEMP_SHELL_FOLDERS
Language=English
Because of errors during processing, documents and other files were left in %1.%0
.

MessageId= SymbolicName=MSG_OPTIONS_CLEANER
Language=English
These files are the installation files for Windows 98 or Windows ME. They came pre-installed on your computer. You can remove them if you do not plan to install Windows 98/ME again.%0
.

MessageId= SymbolicName=MSG_OPTIONS_CLEANER_TITLE
Language=English
Windows 98/ME Installation Files%0
.

MessageId= SymbolicName=MSG_EMPTY_MYDOCS_TITLE
Language=English
Where did my files go.txt%0
.

MessageId= SymbolicName=MSG_EMPTY_MYDOCS_TEXT
Language=English
In Windows 98 and Windows Millennium Edition, two or more users
could save their files to the same location--My Documents. In
Windows XP, a new feature allows all users on the computer to
share documents by saving them to a folder called Shared
Documents. As part of the upgrade process, Setup moved your
documents to this new folder.

To find your documents, go to My Computer and double-click the
Shared Documents folder. In the future, whenever you want to share
files with other users on this computer, just copy the files to
Shared Documents.

.
;//
;// ####################################################################################
;// #
;// #  Common Messages
;// #
;// ####################################################################################
;//

MessageId=10000 SymbolicName=MSG_MESSAGEBOX_TITLE
Language=English
Windows XP Setup%0
.

MessageId=10001 SymbolicName=MSG_OUT_OF_MEMORY_RETRY
Language=English
Setup needs more memory.  Close all open programs and click Retry.  If there are no other programs open, click Cancel to quit Setup.%0
.

MessageId=10002 SymbolicName=MSG_OUT_OF_MEMORY
Language=English
Your computer needs more memory for Setup to continue.%0
.

MessageId=10003 SymbolicName=MSG_ERROR
Language=English
Error%0
.

;// ***
;// *** Migration DLL support info fixups (used when DLL
;// *** provides non-empty strings)
;// ***

;// %1 - Support Phone
MessageId= SymbolicName=MSG_MIGDLL_SUPPORT_PHONE_FIXUP
Language=English

Support Phone: %1
.

;// %1 - Support URL
MessageId= SymbolicName=MSG_MIGDLL_SUPPORT_URL_FIXUP
Language=English

Support on the Internet: %1
.

;// %1 - Instructions
MessageId= SymbolicName=MSG_MIGDLL_INSTRUCTIONS_FIXUP
Language=English

%1
.

;// ***
;// *** Windows platform names
;// ***

MessageId= SymbolicName=MSG_SHORT_OS_NAME
Language=English
Windows%0
.

MessageId= SymbolicName=MSG_NORMAL_OS_NAME
Language=English
Windows XP%0
.

MessageId= SymbolicName=MSG_FULL_OS_NAME
Language=English
Windows XP%0
.

MessageId= SymbolicName=MSG_ADMINISTRATOR_ACCOUNT
Language=English
Administrator%0
.

;// ***
;// *** Messages that are out of place
;// ***
;// *** This is because localization tools cannot deal with symbol renumbering
;// ***

;//
;// ####################################################################################
;// #
;// #  migration report messages
;// #
;// ####################################################################################
;//
;//
;// Text for migration report
;//
;// There are messages for the following message groups:
;//
;//     Hardware
;//     General Information
;//     Settings That Will Not Be Upgraded
;//     Program Compatibility Not Known
;//     Software Designed for MS-DOS
;//     Software Incompatible with Windows XP
;//     Software That Must Be Reinstalled
;//     Software to Be Removed by Setup
;//     Notes About Your Other Software
;//     Other Upgrade Information
;//
;// All text has a plain version and an HTML version. The plain version
;// is used for Save As and Print, while the HTML version is used for
;// the UI.
;//


;//***************************************************************************
;//
;// General Instructions
;//
;//***************************************************************************

;// Text at the top of the report
MessageId=20000 SymbolicName=MSG_REPORT_GENERAL_INSTRUCTIONS
Language=English
Upgrade Report
--------------
Setup found hardware or software on your computer that might not or will not work with Windows XP. You should read and understand this upgrade report before continuing.

.

MessageId= SymbolicName=MSG_REPORT_GENERAL_INSTRUCTIONS_HTML
Language=English
Setup found hardware or software on your computer that might not or will not work with Windows XP. You should read and understand this upgrade report before continuing.<P>
.

MessageId= SymbolicName=MSG_REPORT_GENERAL_INSTRUCTIONS_END
Language=English
Setup has detected that some hardware or programs on your computer might not function correctly after the upgrade is completed. This lack of functionality can have an effect on things you might want to do, such as connecting to the Internet, accessing e-mail, printing, scanning, and playing sounds or music. It is important that you read and understand this upgrade report before continuing. To resolve some of these issues, you can get more information at %1 on the Web.

.

MessageId= SymbolicName=MSG_REPORT_GENERAL_INSTRUCTIONS_END_HTML
Language=English
Setup has detected that some hardware or programs on your computer might not function correctly after the upgrade is completed. This lack of functionality can have an effect on things you might want to do, such as connecting to the Internet, accessing e-mail, printing, scanning, and playing sounds or music. It is important that you read and understand this upgrade report before continuing. To resolve some of these issues, you can get more information at %1 on the Web.
<P>
.


;//***************************************************************************
;//
;// Hardware
;//
;//***************************************************************************

MessageId= SymbolicName=MSG_INCOMPATIBLE_HARDWARE_ROOT
Language=English
Hardware%0
.

;//
;// If incompatible hardware was found... text goes at top, then a list of devices, then text at bottom.
;// MSG_HARDWARE_INSTRUCTIONS  -- text for the top
;// MSG_HARDWARE_INSTRUCTIONS2 -- text for the bottom
;//

MessageId= SymbolicName=MSG_HARDWARE_PNP_INSTRUCTIONS
Language=English
Hardware That Might Need Additional Files

The following hardware might need additional files in order to work with Windows XP. Contact your hardware vendors to obtain Windows XP compatible updates. In many cases, if a Windows XP version is not yet available, a Windows 2000 compatible update should work. It is recommended that you obtain these drivers in advance.

You can also view the Microsoft Windows XP Hardware Compatibility List at:

http://www.microsoft.com/isapi/redir.dll?Prd=Whistler&Ar=Help&Sba=compatible

Please note that some of the following entries might be software that is registered as hardware.

.

MessageId= SymbolicName=MSG_HARDWARE_PNP_INSTRUCTIONS_HTML
Language=English
<UL><B>Hardware That Might Need Additional Files</B><BR>
The following hardware might need additional files in order to work with Windows XP. Contact your hardware vendors to obtain Windows XP compatible updates. In many cases, if a Windows XP version is not yet available, a Windows 2000 compatible update should work. It is recommended that you obtain these drivers in advance.<P>
You can also view the <A HREF="http://www.microsoft.com/isapi/redir.dll?Prd=Whistler&Ar=Help&Sba=compatible">Microsoft Windows XP Hardware Compatibility List</A> on the Web.<P>
Please note that some of the following entries might be software that is registered as hardware.
<P>
.

MessageId= SymbolicName=MSG_HARDWARE_PNP_INSTRUCTIONS2
Language=English
%0
.

MessageId= SymbolicName=MSG_HARDWARE_PNP_INSTRUCTIONS2_HTML
Language=English
</UL>
.


;//***************************************************************************
;//
;// General Information
;//
;//***************************************************************************

MessageId= SymbolicName=MSG_INSTALL_NOTES_ROOT
Language=English
General Information%0
.

MessageId= SymbolicName=MSG_INSTALL_NOTES_INTRO
Language=English
General Information
-------------------
This section provides important information that you need to be aware of before you upgrade.

.

MessageId= SymbolicName=MSG_INSTALL_NOTES_INTRO_HTML
Language=English
<B>General Information</B><BR>
This section provides important information that you need to be aware of before you upgrade.
<P>
.

;// ***
;// *** Name changes
;// ***

MessageID= SymbolicName=MSG_REPORT_NAMECHANGE
Language=English
Name Changes

The following names will change during the upgrade to Windows XP:

.

MessageID= SymbolicName=MSG_REPORT_NAMECHANGE_HTML
Language=English
<UL><B>Name Changes</B><BR>
The following names will change during the upgrade to Windows XP:
<P>
<UL>%0
.

;// Remind user they changed some names. %1-name group  %2-old name  %3-new name
MessageID= SymbolicName=MSG_NAMECHANGE_WARNING_GROUP
Language=English
Name Changes%0
.

;// Remind user they changed some names. %1-name group  %2-old name  %3-new name
MessageID= SymbolicName=MSG_NAMECHANGE_WARNING_SUBCOMPONENT
Language=English
%2</B> will become <B>%3%0
.

;// ***
;// *** DOS Items
;// ***

MessageId= SymbolicName=MSG_DOS_WARNING
Language=English
One or more entries in your MS-DOS configuration files (Autoexec.bat and Config.sys) are incompatible with Windows XP. These entries might be associated with older hardware or software that is incompatible with Windows XP. More technical information is provided in the Setupact.log file, located in your Windows folder.%0
.

MessageId= SymbolicName=MSG_DOS_WARNING_SUBGROUP
Language=English
DOS Configuration%0
.

MessageID= SymbolicName=MSG_UNKNOWNDOS_WARNING_GROUP
Language=English
Unknown DOS%0
.

MessageID= SymbolicName=MSG_UNKNOWNDOS_WARNING_SUBCOMPONENT
Language=English
Line %1 of %2
.


;// ***
;// *** Network Shares
;// ***

MessageId= SymbolicName=MSG_NET_SHARES_SUBGROUP
Language=English
Network Shares%0
.

;// Incompatible setting: NT does not allow passwords on shares.  %1 - specifies share name
MessageId= SymbolicName=MSG_LOST_SHARE_PASSWORDS
Language=English
Share %1 requires a password. Windows XP uses user-level access rights instead of passwords.

Setup will create the %1 share and set the permissions to deny all user access. After Setup completes, you can modify the permissions by right-clicking the folder and then clicking Properties.
.

;// Incompatible setting: NT has a much simpler UI and does not allow such granular access settings.  %1 - specifies share name  %2 - specifies full path
MessageId= SymbolicName=MSG_LOST_ACCESS_FLAGS
Language=English
Windows XP does not support the custom access permissions on share %1 (path: %2). Setup will create the folder and set the highest security level for access to the folder. After Setup completes, you can modify the permissions by right-clicking the folder and then clicking Properties.%0
.

;// On some Win95 machines, the ACL APIs fail. This is a bug in Win9x and there is no workaround.  %1 - specifies share name
MessageId= SymbolicName=MSG_INVALID_ACL_LIST
Language=English
Setup encountered a problem reading the access permissions on share %1 (path: %2). After Setup completes, you can set the folder properties by right-clicking the folder and then clicking Properties.%0
.


;// ***
;// *** Directory Collision
;// ***

;// Folders that will be renamed because of a collision with Win2000 folders
MessageId= SymbolicName=MSG_DIRECTORY_COLLISION_SUBGROUP
Language=English
Folder Name Changes%0.
.

;// Introduction
MessageId= SymbolicName=MSG_DIRECTORY_COLLISION_INTRO
Language=English
Because two folders have the same name, Setup will rename them as follows:

.

;// ***
;// *** Drive type check
;// ***

;// Compressed, unknown drive types
MessageId= SymbolicName=MSG_DRIVE_INACCESSIBLE_SUBGROUP
Language=English
Inaccessible Drives%0
.

MessageId= SymbolicName=MSG_DRIVE_INACCESSIBLE_INTRO
Language=English
Inaccessible Drives

Setup cannot upgrade programs on the following drives:

.

;// EXCLUDE.INF excluded drives
MessageId= SymbolicName=MSG_DRIVE_EXCLUDED_SUBGROUP
Language=English
Excluded Drives%0
.

MessageId= SymbolicName=MSG_DRIVE_EXCLUDED_INTRO
Language=English
Excluded Drives

Setup will not look for programs on the following drives, because they have been excluded:

.

;// Network drives
MessageId= SymbolicName=MSG_DRIVE_NETWORK_SUBGROUP
Language=English
Network Drives%0
.

MessageId= SymbolicName=MSG_DRIVE_NETWORK_INTRO
Language=English
Network Drives

Setup will not look for programs on the following network drives:

.

;// RAM disks
MessageId= SymbolicName=MSG_DRIVE_RAM_SUBGROUP
Language=English
RAM Disks%0
.

MessageId= SymbolicName=MSG_DRIVE_RAM_INTRO
Language=English
RAM Disks

The following RAM disks are not compatible with Windows XP:

.

;// Substituted drives
MessageId= SymbolicName=MSG_DRIVE_SUBST_SUBGROUP
Language=English
Substituted Drives%0
.

MessageId= SymbolicName=MSG_DRIVE_SUBST_INTRO
Language=English
Substituted Drives

The following substituted drives don't need to be processed:
.

;// ***
;// *** Keyboard Layout
;// ***

MessageId= SymbolicName=MSG_KEYBOARD_SUBGROUP
Language=English
<unused>%0
.

MessageId= SymbolicName=MSG_KEYBOARD_LAYOUT_NOT_SUPPORTED
Language=English
<unused>%0
.

MessageId= SymbolicName=MSG_KEYBOARD_DEVICE_UNSUPPORTED
Language=English
<unused>%0
.


;// ***
;// *** Incomplete user settings
;// ***
;//
;// Subgroups for MSG_REG_SETTINGS_INCOMPLETE
;
MessageId= SymbolicName=MSG_REG_SETTINGS_SUBGROUP
Language=English
Invalid User Accounts%0
.

MessageId= SymbolicName=MSG_SHELL_SETTINGS_SUBGROUP
Language=English
Inaccessible or Incomplete User Accounts%0
.

;// If we encounter a busted user... this text is displayed
MessageId= SymbolicName=MSG_REG_SETTINGS_INCOMPLETE
Language=English
User Accounts That Cannot Be Upgraded

The following user accounts are inaccessible or incomplete and cannot be upgraded to Windows XP:

.

MessageId= SymbolicName=MSG_REG_SETTINGS_INCOMPLETE_HTML
Language=English
<UL><B>User Accounts That Cannot Be Upgraded</B><BR>
The following user accounts are inaccessible or incomplete and cannot be upgraded to Windows XP:
<P>
<UL>%0
.

;// If we encounter a busted shell... this text is displayed
;
MessageId= SymbolicName=MSG_SHELL_SETTINGS_INCOMPLETE
Language=English
Users With a Damaged Start Menu or Desktop

The Start menu or desktop for the following user accounts is inaccessible or incomplete and cannot be upgraded to Windows XP. After Setup completes, you can recreate these accounts.

.

MessageId= SymbolicName=MSG_SHELL_SETTINGS_INCOMPLETE_HTML
Language=English
<UL><B>Users With a Damaged Start Menu or Desktop</B><BR>
The Start menu or desktop for the following user accounts is inaccessible or incomplete and cannot be upgraded to Windows XP. After Setup completes, you can recreate these accounts.
<P>
<UL>%0
.

;// When user name is empty on Win9x, this text is used for display. (Rarely used.)
;
MessageId= SymbolicName=MSG_REG_SETTINGS_EMPTY_USER
Language=English
[default user account]%0
.

;// ***
;// *** Hardware Profiles
;// ***
;//
;// Hardware profile incompatibility text
;
MessageId= SymbolicName=MSG_HWPROFILES_SUBGROUP
Language=English
Hardware Profiles%0
.

MessageId= SymbolicName=MSG_HWPROFILES_INTRO
Language=English
Hardware Profiles

Some settings in the following hardware profiles cannot be transferred to Windows XP. The first time you use each incomplete profile, the Hardware wizard will help you re-create these settings.

.

MessageId= SymbolicName=MSG_HWPROFILES_INTRO_HTML
Language=English
<UL><B>Hardware Profiles</B><BR>
Some settings in the following hardware profiles cannot be transferred to Windows XP. The first time you use each incomplete profile, the Hardware wizard will help you re-create these settings.
<P>
<UL>
.

;// Incompatible Shell settings
;//
MessageID= SymbolicName=MSG_REPORT_SHELL_INCOMPATIBLE
Language=English
Setup detected a program that replaces Windows Explorer. Setup will disable this program to avoid startup problems in Windows XP.%0
.

;// ***
;// *** Other -- as time goes on, there will be as few of these as possible
;// ***

MessageId= SymbolicName=MSG_INSTALL_NOTES_OTHER
Language=English
<unused>%0
.

MessageId= SymbolicName=MSG_INSTALL_NOTES_OTHER_HTML
Language=English
<unused>%0
.

;//***************************************************************************
;//
;// Settings That Will Not Be Upgraded
;//
;//***************************************************************************

MessageId= SymbolicName=MSG_LOSTSETTINGS_ROOT
Language=English
Settings That Will Not Be Upgraded%0
.


;//***************************************************************************
;//
;// Applications that will be automatically uninstalled
;//
;//***************************************************************************

MessageId= SymbolicName=MSG_AUTO_UNINSTALL_SUBGROUP
Language=English
Software to Be Removed by Setup%0
.

MessageId= SymbolicName=MSG_AUTO_UNINSTALL_INTRO
Language=English
Software to Be Removed by Setup

The following programs were not designed for Windows XP. If you continue, Setup will remove them from your computer.

.

MessageId= SymbolicName=MSG_AUTO_UNINSTALL_INTRO_HTML
Language=English
<B>Software to Be Removed by Setup</B><BR>
The following programs were not designed for Windows XP. If you continue, Setup will remove them from your computer.
<P>
.


;//***************************************************************************
;//
;// Software Incompatible with Windows XP
;//
;//***************************************************************************

MessageId= SymbolicName=MSG_INCOMPATIBLE_ROOT
Language=English
Software Incompatible with Windows XP%0
.

;// Win95-specific software, will never run on NT
;
MessageId= SymbolicName=MSG_INCOMPATIBLE_INTRO
Language=English
Software Incompatible with Windows XP
-------------------------------------

.

MessageId= SymbolicName=MSG_INCOMPATIBLE_INTRO_HTML
Language=English
<B>Software Compatibility Issues</B>
<P>
.


;//***************************************************************************
;//
;// Software That Must Be Reinstalled
;//
;//***************************************************************************

MessageId= SymbolicName=MSG_REINSTALL_ROOT
Language=English
Software That Must Be Reinstalled%0
.

;// Win95-specific installation software installed an app; needs to be reinstalled to get NT version.
;
MessageId= SymbolicName=MSG_REPORT_BEGIN_INDENT
Language=English
%0
.

MessageId= SymbolicName=MSG_REPORT_BEGIN_INDENT_HTML
Language=English
<UL>%0
.

MessageId= SymbolicName=MSG_REPORT_REINSTALL_INSTRUCTIONS2
Language=English
<unused>%0
.

MessageId= SymbolicName=MSG_REPORT_REINSTALL_INSTRUCTIONS2_HTML
Language=English
<unused>%0
.


;//***************************************************************************
;//
;// Notes About Your Other Software
;//
;//***************************************************************************

MessageId= SymbolicName=MSG_MINOR_PROBLEM_ROOT
Language=English
Notes About Your Other Software%0
.

MessageId= SymbolicName=MSG_MINOR_PROBLEM_INTRO
Language=English
Notes About Your Other Software
-------------------------------
This section describes issues that might affect other software you use. Be sure to read this section before you begin the upgrade to Windows XP.

.

MessageId= SymbolicName=MSG_MINOR_PROBLEM_INTRO_HTML
Language=English
<B>Notes About Your Other Software</B><BR>
This section describes issues that might affect other software you use. Be sure to read this section before you begin the upgrade to Windows XP.
<P>
.

;// ***
;// *** Incompatible Help Files
;// ***
;//
;// Incompatible Help Files text
;
MessageId= SymbolicName=MSG_HELPFILES_SUBGROUP
Language=English
Incompatible Help Files%0
.

MessageId= SymbolicName=MSG_HELPFILES_INTRO
Language=English
Help Files

Some or all of the online Help contained in the following files will not work with Windows XP:

.

MessageId= SymbolicName=MSG_HELPFILES_INTRO_HTML
Language=English
<UL><B>Help Files</B><BR>
Some or all of the online Help contained in the following files will not work with Windows XP:
<P>
<UL>%0
.

;//
;// Help Files checking messages
;//

;// Technical log message, %2 - help file name, %1 - 16-bit DLL path
MessageId= SymbolicName=MSG_HELPFILES_NOTFOUND_LOG
Language=English
Help file %2 uses %1 as an extension pack. Setup could not find %1.%0
.

;// Technical log message, %2 - help file name, %1 - 16-bit DLL path
MessageId= SymbolicName=MSG_HELPFILES_BROKEN_LOG
Language=English
Help file %2 uses %1 as an extension pack. %1 is not working properly or is not a Windows extension pack.%0
.

;// Technical log message, %2 - help file name, %1 - 16-bit DLL path
MessageId= SymbolicName=MSG_HELPFILES_MISMATCHED_LOG
Language=English
Help file %2 uses %1 as an extension pack. Because %1 and %2 will be loaded into different subsystems, you won't be able to use this Help file under Windows XP.%0
.

;//***************************************************************************
;//
;// Other Upgrade Information
;//
;//***************************************************************************

MessageId= SymbolicName=MSG_MIGDLL_ROOT
Language=English
Other Upgrade Information%0
.

MessageId= SymbolicName=MSG_MIGDLL_INTRO
Language=English
Other Upgrade Information
-------------------------

.

MessageId= SymbolicName=MSG_MIGDLL_INTRO_HTML
Language=English
<B>Other Upgrade Information</B>
<P>
.

;//***************************************************************************
;//
;// Unorganized messages -- all new messages must be added to the end,
;// because of localization constraints.
;//
;//***************************************************************************


MessageId= SymbolicName=MSG_MULTI_MONITOR_UNSUPPORTED_SUBGROUP
Language=English
Multiple Monitor Support%0
.

MessageId= SymbolicName=MSG_MULTI_MONITOR_UNSUPPORTED_PER
Language=English
The Home Edition of Windows XP does not include multi-monitor support. Upgrading to Windows XP Professional Edition will enable multi-monitor support.%0
.

MessageId= SymbolicName=MSG_MULTI_MONITOR_UNSUPPORTED
Language=English
Although Windows XP supports multiple monitors, Setup might not be able to preserve your current monitor configuration. After Setup completes, you might need to adjust your monitor configuration.%0
.

MessageId= SymbolicName=MSG_OTHER_OS_WARNING_SUBGROUP
Language=English
Other Operating Systems Found%0
.

MessageId= SymbolicName=MSG_OTHER_OS_WARNING
Language=English
You cannot upgrade this Windows installation to Windows XP, because you have more than one operating system installed on your computer. Upgrading one operating system can cause problems with files shared by the other operating system, and is therefore not permitted.%0
.


MessageId= SymbolicName=MSG_OTHER_OS_IN_PATH_SUBGROUP
Language=English
<unused>%0
.

MessageId= SymbolicName=MSG_OTHER_OS_IN_PATH
Language=English
<unused>%0
.

MessageId= SymbolicName=MSG_BACKUP_DETECTED_SUBGROUP
Language=English
Backup Files Found%0
.

;// %1 - Operating System (i.e., Windows 95); %2 - number of backup folders found
MessageId= SymbolicName=MSG_BACKUP_DETECTED
Language=English
Setup found files on your computer that appear to be a backup of part of %1. During the upgrade to Windows XP, Setup removes %1 from your computer, including any backups you might have on your hard disk. More information is available in the Setupact.log file, located in your Windows folder.  It lists %2 folders that might contain backup files.<P>
Protect your backup files by copying them to floppy disks, a network server, a compressed archive file, or other backup mechanism.%0
.

MessageId= SymbolicName=MSG_BETA2_ROOT
Language=English
<unused>%0
.

MessageID= SymbolicName=MSG_OLD_DRIVER_FOUND_SUBGROUP
Language=English
Drivers Designed for Windows 3.1%0
.

MessageID= SymbolicName=MSG_OLD_DRIVER_FOUND_MESSAGE
Language=English
Setup found hardware files designed for Windows 3.1. These files are not Plug-and-Play compatible. It is safe to upgrade now, but some of your hardware might not function after Setup completes.<P>
Although Setup identified the hardware files, it cannot identify the device. After upgrade, you might be able to determine which device could not be found by right-clicking My Computer, clicking Properties, clicking Device Manager, and then checking the device list for missing items.%0
.

MessageID= SymbolicName=MSG_NON_PNP_DRIVER_SUBGROUP
Language=English
<unused>%0
.

MessageID= SymbolicName=MSG_NO_INCOMPATIBILITIES
Language=English
No incompatible hardware or software was found on your computer.%0
.


;// %1 - Operating System (i.e., Windows 95)
MessageId= SymbolicName=MSG_NO_BOOT16_WARNING_SUBGROUP
Language=English
MS-DOS Startup Option%0
.

;// %1 - Operating System (i.e., Windows 95)
MessageId= SymbolicName=MSG_NO_BOOT16_WARNING
Language=English
Because you are upgrading your system disk to the Windows XP File System (NTFS), the MS-DOS startup option has been automatically disabled.%0
.

MessageId= SymbolicName=MSG_TIMEZONE_COMPONENT
Language=English
General Information\Time Zone\%0
.

MessageId= SymbolicName=MSG_TIMEZONE_WARNING
Language=English
The current time zone for your computer (%1) matches more than one Windows XP time zone. After Setup completes, you should use the Regional Settings icon in Control Panel to check your time zone settings.%0
.


;//***************************************************************************
;//
;// Software Designed for MS-DOS
;//
;//***************************************************************************

MessageId= SymbolicName=MSG_DOS_DESIGNED_ROOT
Language=English
Software Designed for MS-DOS%0
.

;// MS-DOS specific software, will never run on NT
;
MessageId= SymbolicName=MSG_DOS_DESIGNED_INTRO
Language=English
Software Designed for MS-DOS
----------------------------
The following programs are designed only for MS-DOS. After upgrading, use the MS-DOS startup option to run these programs.

.

MessageId= SymbolicName=MSG_DOS_DESIGNED_INTRO_HTML
Language=English
<B>Software Designed for MS-DOS</B><BR>
The following programs are designed only for MS-DOS. After upgrading, use the MS-DOS startup option to run these programs.
<P>
.


;// Win95-specific software, will never run on NT
;
MessageId= SymbolicName=MSG_REPORT_WIN95_ONLY_INSTRUCTIONS2
Language=English
<unused>%0
.

MessageId= SymbolicName=MSG_REPORT_WIN95_ONLY_INSTRUCTIONS2_HTML
Language=English
<unused>%0
.


;// TWAIN
MessageId= SymbolicName=MSG_TWAIN_SUBGROUP
Language=English
TWAIN%0
.

MessageId= SymbolicName=MSG_TWAIN_DEVICES_UNKNOWN
Language=English
Scanners or Digital Cameras That Might Not Work

Setup did not recognize the following scanners or digital cameras. Before upgrading, check the packaging that came with each device to see if it supports Windows XP, or contact the device manufacturer. Reinstall each device when Setup is complete, using the software that came with the device.

.

MessageId= SymbolicName=MSG_TWAIN_DEVICES_UNKNOWN_HTML
Language=English
<UL><B>Scanners or Digital Cameras That Might Not Work</B><BR>
Setup did not recognize the following scanners or digital cameras. Before upgrading, check the packaging that came with each device to see if it supports Windows XP, or contact the device manufacturer. Reinstall each device when Setup is complete, using the software that came with the device.
<P>
<UL>%0
.

MessageId= SymbolicName=MSG_RAS_SUBGROUP
Language=English
<unused>%0
.

MessageId= SymbolicName=MSG_BAD_RAS_PROTOCOL
Language=English
<unused>%0
.

MessageId= SymbolicName=MSG_TWAIN_DEVICES_UNKNOWN2
Language=English
<unused>%0
.

MessageId= SymbolicName=MSG_TWAIN_DEVICES_UNKNOWN2_HTML
Language=English
<unused>%0
.

MessageId= SymbolicName=MSG_INCOMPATIBLE_HARDWARE_PNP_SUBGROUP
Language=English
1-Incompatible Hardware%0
.

MessageId= SymbolicName=MSG_INCOMPATIBLE_HARDWARE_INTRO
Language=English
Hardware Compatibility Issues
-----------------------------
Setup has found hardware on your computer that is incompatible with (that is, it does not work with) Windows XP.

.

MessageId= SymbolicName=MSG_INCOMPATIBLE_HARDWARE_INTRO_HTML
Language=English
<B>Hardware Compatibility Issues</B><BR>
Setup has found hardware on your computer that is incompatible with (that is, it does not work with) Windows XP.
<P>

.

MessageId= SymbolicName=MSG_INCOMPATIBLE_HARDWARE_OTHER
Language=English
%0
.

MessageId= SymbolicName=MSG_INCOMPATIBLE_HARDWARE_OTHER_HTML
Language=English

.

MessageId= SymbolicName=MSG_JOYSTICK_SUBGROUP
Language=English
Incompatible Joysticks
.

MessageId= SymbolicName=MSG_JOYSTICK_DEVICE_UNKNOWN
Language=English
Incompatible Joysticks

The following joysticks need additional files from the hardware manufacturer to work with Windows XP.

.

MessageId= SymbolicName=MSG_JOYSTICK_DEVICE_UNKNOWN_HTML
Language=English
<UL><B>Incompatible Joysticks</B><BR>
The following joysticks need additional files from the hardware manufacturer to work with Windows XP.
<P>
<UL>%0
.


;//***************************************************************************
;//
;// Program Compatibility Not Known
;//
;//***************************************************************************

MessageId= SymbolicName=MSG_UNKNOWN_ROOT
Language=English
Program Compatibility Not Known%0
.

MessageId= SymbolicName=MSG_REPORT_UNKNOWN_INSTRUCTIONS
Language=English
Program Compatibility Not Known
-------------------------------
Setup cannot determine the compatibility of the software listed below.  Most programs support Windows XP.  Before upgrading, check the software compatibility list on  http://www.microsoft.com/isapi/redir.dll?prd=whistler&ar=help&sba=compatible, or contact the software manufacturer.

.

MessageId= SymbolicName=MSG_REPORT_UNKNOWN_INSTRUCTIONS_HTML
Language=English
<B>Program Compatibility Not Known</B><BR>
Setup cannot determine the compatibility of the software listed below.  Most programs support Windows XP.  Before upgrading, check the software compatibility list on <A HREF="http://www.microsoft.com/isapi/redir.dll?prd=whistler&ar=help&sba=compatible">Microsoft's Web site</A>, or contact the software manufacturer.<P>
.

MessageID= SymbolicName=MSG_NOT_ENOUGH_RAM_SUBGROUP
Language=English
Memory%0
.

;// %1 - Needed RAM (number in MB), %2 - Current RAM, %3 - Difference
MessageID= SymbolicName=MSG_NOT_ENOUGH_RAM
Language=English
Your computer does not have enough memory to run Windows XP. Windows XP requires %1 MB of memory, but your computer only has %2 MB. You need to add at least %3 MB of additional memory to your computer before upgrading.%0
.

MessageID= SymbolicName=MSG_RECYCLE_BIN_SUBGROUP
Language=English
Recycle Bin%0
.

;// %1 - number of files in the Recycle Bin
MessageID= SymbolicName=MSG_RECYCLED_FILES_WILL_BE_DELETED
Language=English
Setup found %1 files in your Recycle Bin. If you continue upgrading to Windows XP, these files will be deleted.%0
.

;// Used when a machine name doesn't exist
MessageID= SymbolicName=MSG_BLANK_NAME
Language=English
(blank name)%0
.

;// %1 - system drive letter, %2 - space to be freed, %3 - ~ls size, %4 - non-system drive option requirment, in mb, %5 - backup image size
MessageID= SymbolicName=MSG_NOT_ENOUGH_DISK_SPACE_WITH_LOCALSOURCE
Language=English
Your computer does not have enough disk space to completely install Windows XP. You must free additional disk space before you can upgrade. You need at least %2 MB free space on drive %1, or at least %3 MB on any other drive.%0
.

;// %1 - system drive letter, %2 - space to be freed, %3 - ~ls size, %4 - non-system drive option requirment, in mb, %5 - backup image size
MessageID= SymbolicName=MSG_NOT_ENOUGH_DISK_SPACE_WITH_LOCALSOURCE_AND_WINDIR
Language=English
Your computer does not have enough disk space to completely install Windows XP. You must free additional disk space before you can upgrade. You need at least %2 MB free space on drive %1, or you need at least %4 MB on drive %1 and %3 MB on any other drive.%0
.

MessageID= SymbolicName=MSG_DUN_ENTRIES_WILL_BE_MOVED
Language=English
<unused>%0
.


MessageId= SymbolicName=MSG_MAPI_NOT_HANDLED_SUBGROUP
Language=English
Windows Messaging Services%0
.

MessageId= SymbolicName=MSG_MAPI_NOT_HANDLED
Language=English
Setup has detected a version of messaging (MAPI) that does not function on Windows XP.  Obtain an upgrade pack for your e-mail program, or reinstall it after upgrading to Windows XP.%0
.

;//***************************************************************************
;//
;// Applications that must be uninstalled before an upgrade can occur.
;//
;//***************************************************************************

MessageId= SymbolicName=MSG_MUST_UNINSTALL_ROOT
Language=English
Software to be Removed Before Upgrading%0
.

MessageId= SymbolicName=MSG_MUST_UNINSTALL_INTRO
Language=English
Software That Must be Permanently Removed
-----------------------------------------
The following programs can cause problems during the upgrade process and Setup cannot automatically remove them for you. Therefore, before Setup can continue, you must uninstall these programs from your computer.

.

MessageId= SymbolicName=MSG_MUST_UNINSTALL_INTRO_HTML
Language=English
<B>Software That Must be Permanently Removed</B><BR>
The following programs can cause problems during the upgrade process and Setup cannot automatically remove them for you. Therefore, before Setup can continue, you must uninstall these programs from your computer.
<P>
<UL>%0
.

MessageId= SymbolicName=MSG_BLOCKING_FILE_BLOCK
Language=English
Because there are applications that must be uninstalled before an upgrade can be attempted, Setup will now exit. After you uninstall the necessary applications, run Setup again.%0
.

MessageId= SymbolicName=MSG_OTHER_OS_FOUND
Language=English
Windows XP Setup does not support upgrading from Windows if you have multiple Operating Systems installed.%0
.

MessageId= SymbolicName=MSG_CONNECTION_MOVED_SUBGROUP
Language=English
Moved Dial-Up Connections%0
.

MessageId= SymbolicName=MSG_CONNECTION_MOVED_INTRO
Language=English
Dial-Up Connections That Will Be Moved

The following connections will be moved into your Network and Dial-Up Connections Folder after migration.

.

MessageId= SymbolicName=MSG_CONNECTION_MOVED_INTRO_HTML
Language=English
<UL><B>Dial-Up Connections That Will Be Moved</B><BR>
The following connections will be moved into your Network and Dial-Up Connections Folder after migration.
<P>
.

MessageId= SymbolicName=MSG_CONNECTION_BADPROTOCOL_SUBGROUP
Language=English
Dial-Up Connections Might Not Work%0
.

MessageId= SymbolicName=MSG_CONNECTION_BADPROTOCOL_INTRO
Language=English
Dial-Up Connections That Might Not Work

The following connections might not work after migration is complete. They will be migrated using Windows XP defaults instead of the incompatible settings.

.

MessageId= SymbolicName=MSG_CONNECTION_BADPROTOCOL_INTRO_HTML
Language=English
<UL><B>Dial-Up Connections That Might Not Work</B><BR>
The following connections might not work after migration is complete. They will be migrated using Windows XP defaults instead of the incompatible settings.
<P>
<UL>%0
.

MessageId= SymbolicName=MSG_TIMEZONE_WARNING_UNKNOWN
Language=English
Setup was unable to determine your time zone. After Setup completes, you should use the Regional Settings icon in Control Panel to check your time zone settings.%0
.

MessageId= SymbolicName=MSG_TIMEZONE_UNKNOWN
Language=English
Unknown Time Zone
.

MessageId= SymbolicName=MSG_RUNNING_MIGRATION_DLLS_SUBGROUP
Language=English
Upgrade Packs%0
.

MessageId= SymbolicName=MSG_RUNNING_MIGRATION_DLLS_INTRO
Language=English
Upgrade Packs That Are Being Processed

The following upgrade packs are being processed during the migration to Windows XP.

.

MessageId= SymbolicName=MSG_RUNNING_MIGRATION_DLLS_INTRO_HTML
Language=English
<UL><B>Upgrade Packs That Are Being Processed</B><BR>
The following upgrade packs are being processed during the migration to Windows XP.
<P>
<UL>%0
.


MessageId= SymbolicName=MSG_TOTALLY_INCOMPATIBLE_SUBGROUP
Language=English
!Incompatible%0
.

MessageId= SymbolicName=MSG_TOTALLY_INCOMPATIBLE_INTRO
Language=English
Software That Does Not Support Windows XP

Setup has found programs on your computer that are incompatible with (that is, they do not work with) Windows XP. Contact your software vendors to obtain updates or Windows XP-compatible versions. If you don't update these programs before you upgrade, the programs will not work after the upgrade is completed.

.

MessageId= SymbolicName=MSG_TOTALLY_INCOMPATIBLE_INTRO_HTML
Language=English
<B>Software That Does Not Support Windows XP</B><BR>
Setup has found programs on your computer that are incompatible with (that is, they do not work with) Windows XP. Contact your software vendors to obtain updates or Windows XP-compatible versions. If you don't update these programs before you upgrade, the programs will not work after the upgrade is completed.
<P>
<UL>%0
.

MessageId= SymbolicName=MSG_TOTALLY_INCOMPATIBLE_TRAIL
Language=English
Before you upgrade to Windows XP, you should remove any incompatible programs if you can. After the upgrade, uninstall for these programs might not work. Add/Remove Programs in Control Panel can help you uninstall most programs. Click Start, point to Settings, click Control Panel, and then click Add/Remove Programs.


.

MessageId= SymbolicName=MSG_TOTALLY_INCOMPATIBLE_TRAIL_HTML
Language=English
Before you upgrade to Windows XP, you should remove any incompatible programs if you can. After the upgrade, uninstall for these programs might not work. Add/Remove Programs in Control Panel can help you uninstall most programs. Click Start, point to Settings, click Control Panel, and then click Add/Remove Programs.
</UL>
.

MessageId= SymbolicName=MSG_REMOVED_FOR_SAFETY_SUBGROUP
Language=English
Removed For Safety%0
.

MessageId= SymbolicName=MSG_REMOVED_FOR_SAFETY_INTRO
Language=English
Software That Might Not Support Windows XP

Setup cannot determine if the following programs are compatible with Windows XP. Setup will disable them during the upgrade to eliminate the risk of problems. Contact the software vendor to obtain an upgrade pack.

.

MessageId= SymbolicName=MSG_REMOVED_FOR_SAFETY_INTRO_HTML
Language=English
<B>Software That Might Not Support Windows XP</B><BR>
Setup cannot determine if the following programs are compatible with Windows XP. Setup will disable them during the upgrade to eliminate the risk of problems. Contact the software vendor to obtain an upgrade pack.
<P>
<UL>%0
.

;// Display how folders will be renamed. %1-old name  %2-new name
MessageID= SymbolicName=MSG_DIRECTORY_COLLISION_SUBCOMPONENT
Language=English
%1 -> %2%0
.

MessageId= SymbolicName=MSG_INCOMPATIBLE_HARD_DISK_SUBGROUP
Language=English
Incompatible Hard Disk Controller%0
.

;// This case is extremely important.  The user's boot device probably won't work without an ISV driver!
MessageId= SymbolicName=MSG_INCOMPATIBLE_HARD_DISK_WARNING
Language=English
Setup does not have a driver for the main hard disk controller on this computer. To continue Setup, you must have the correct Windows XP-compatible disk driver. Do not use a disk driver designed only for Windows 98 or Windows ME.<P>

Caution: Do not continue the upgrade until you have the correct driver ready on a floppy disk. When Setup restarts, press the F6 key when prompted and follow the instructions.
.

;// This case is rarely a critical issue for the user, but it can be.
MessageId= SymbolicName=MSG_INCOMPATIBLE_HARD_DISK_NOTIFICATION
Language=English
Setup does not have a driver for a hard disk controller on this computer. To continue Setup, you should have the correct Windows XP-compatible disk driver. If you do not supply this driver, Setup might fail. Do not use a disk driver designed only for Windows 98 or Windows ME.<P>
It is recommended that you have the correct driver ready on a floppy disk before you continue. When Setup restarts, press the F6 key when prompted and follow the instructions. If Setup cannot proceed without the driver, you will need to cancel Setup.
.

MessageId= SymbolicName=MSG_UNKNOWN_OS_WARNING_SUBGROUP
Language=English
Unsupported Operating System Version%0
.

MessageId= SymbolicName=MSG_DRIVE_INACCESSIBLE_INTRO_HTML
Language=English
<UL><B>Inaccessible Drives</B><BR>
Setup cannot upgrade programs on the following drives:
<P>
<UL>%0
.

MessageId= SymbolicName=MSG_DRIVE_EXCLUDED_INTRO_HTML
Language=English
<UL><B>Excluded Drives</B><BR>
Setup will not look for programs on the following drives, because they have been excluded:
<P>
<UL>%0
.

MessageId= SymbolicName=MSG_DRIVE_NETWORK_INTRO_HTML
Language=English
<UL><B>Network Drives</B><BR>
Setup will not look for programs on the following network drives:
<P>
<UL>%0
.

MessageId= SymbolicName=MSG_DRIVE_RAM_INTRO_HTML
Language=English
<UL><B>RAM Disks</B><BR>
The following RAM disks are not compatible with Windows XP:
<P>
<UL>%0
.

MessageId= SymbolicName=MSG_DRIVE_SUBST_INTRO_HTML
Language=English
<UL><B>Substituted Drives</B><BR>
The following substituted drives don't need to be processed:
<P>
<UL>%0
.

MessageId= SymbolicName=MSG_LOSTSETTINGS_INTRO
Language=English
Settings That Will Not Be Upgraded
----------------------------------
Some of your settings will not be upgraded, because they aren't applicable in Windows XP.

.

MessageId= SymbolicName=MSG_LOSTSETTINGS_INTRO_HTML
Language=English
<B>Settings That Will Not Be Upgraded</B><BR>
Some of your settings will not be upgraded, because they aren't applicable in Windows XP.
<P>
.

MessageId= SymbolicName=MSG_REPORT_SHELL_SUBGROUP
Language=English
Windows Explorer Replacement%0
.

MessageId= SymbolicName=MSG_OTHER_OS_FOUND_POPUP
Language=English
Windows XP Setup does not support upgrading from Windows if you have multiple Operating Systems installed. Setup will now exit.%0
.

MessageId= SymbolicName=MSG_UNKNOWN_DEVICE_CLASS
Language=English
Other devices%0
.

MessageId= SymbolicName=MSG_DIRECTORY_COLLISION_INTRO_HTML
Language=English
<UL><B>Folder Name Changes</B><BR>
Because two folders have the same name, Setup will rename them as follows:
<P>
.

MessageId= SymbolicName=MSG_REUSABLE_1
Language=English
%0
.

MessageId= SymbolicName=MSG_REUSABLE_2
Language=English
%0
.

;// Old briefcase messages left as placeholders
;
MessageId= SymbolicName=MSG_NON_EMPTY_BRIEFCASES_SUBGROUP
Language=English
.

MessageId= SymbolicName=MSG_NON_EMPTY_BRIEFCASES_INTRO
Language=English
.

MessageId= SymbolicName=MSG_NON_EMPTY_BRIEFCASES_INTRO_HTML
Language=English
.

MessageId= SymbolicName=MSG_NON_EMPTY_BRIEFCASES_TRAIL
Language=English
.

MessageId= SymbolicName=MSG_NON_EMPTY_BRIEFCASES_TRAIL_HTML
Language=English
.


;//***************************************************************************
;//
;// Software That Must Be Temporarily Removed
;//
;//***************************************************************************

MessageId= SymbolicName=MSG_REINSTALL_BLOCK_ROOT
Language=English
Software That Must Be Temporarily Removed%0
.

;// Win95-specific installation software installed an app; needs to be reinstalled to get NT version.
;
MessageId= SymbolicName=MSG_REPORT_REINSTALL_BLOCK_INSTRUCTIONS
Language=English
Software That Must Be Temporarily Removed
-----------------------------------------
The following programs must be uninstalled before upgrading. You can then reinstall these programs after you have upgraded to Windows XP. To remove programs, use Add/Remove Programs in Control Panel or refer to the documentation that came with each program.

.

MessageId= SymbolicName=MSG_REPORT_REINSTALL_BLOCK_INSTRUCTIONS_HTML
Language=English
<B>Software That Must Be Temporarily Removed</B><BR>
The following programs must be uninstalled before upgrading. You can then reinstall these programs after you have upgraded to Windows XP. To remove programs, use Add/Remove Programs in Control Panel or refer to the documentation that came with each program.
<P>
<UL>%0
.

MessageId= SymbolicName=MSG_REPORT_REINSTALL_BLOCK_INSTRUCTIONS2
Language=English
<unused>%0
.

MessageId= SymbolicName=MSG_REPORT_REINSTALL_BLOCK_INSTRUCTIONS2_HTML
Language=English
<unused>%0
.

MessageId= SymbolicName=MSG_PRINTERS_DEVICE_CLASS
Language=English
Printers%0
.


MessageId= SymbolicName=MSG_BACKUP_DETECTED_LIST_SUBGROUP
Language=English
Backup_Files_Found%0
.

;// %1 - Operating System (i.e., Windows 95)
MessageId= SymbolicName=MSG_BACKUP_DETECTED_INTRO
Language=English
Backup Files Found

Setup found files on your computer that appear to be a backup of part of %1. During the upgrade to Windows XP, Setup removes %1 from your computer, including any backups you might have on your hard disk. Some files in the following folders will be removed:

.

;// %1 - Operating System (i.e., Windows 95)
MessageId= SymbolicName=MSG_BACKUP_DETECTED_INTRO_HTML
Language=English
<UL><B>Backup Files Found</B><BR>
Setup found files on your computer that appear to be a backup of part of %1. During the upgrade to Windows XP, Setup removes %1 from your computer, including any backups you might have on your hard disk. Some files in the following folders will be removed:
<P>
<UL>%0
.

MessageId= SymbolicName=MSG_BACKUP_DETECTED_TRAIL
Language=English
Protect your backup files by copying them to floppy disks, a network server, a compressed archive file, or other backup mechanism.

.

MessageId= SymbolicName=MSG_BACKUP_DETECTED_TRAIL_HTML
Language=English
<BR>Protect your backup files by copying them to floppy disks, a network server, a compressed archive file, or other backup mechanism.
</UL>
.

;// Log message, %1 - Backup Directory Name, %2 - Operating System Name (i.e., Windows 95)
MessageId= SymbolicName=MSG_BACKUP_DETECTED_LOG
Language=English
Directory %1 contains files that appear to be a backup of part of %2.%0
.

MessageId= SymbolicName=MSG_UNSUPPORTED_HARDWARE_PNP_SUBGROUP
Language=English
2-Unsupported Hardware%0
.

MessageId= SymbolicName=MSG_HARDWARE_UNSUPPORTED_INSTRUCTIONS
Language=English
Hardware That Will Not Work With Windows XP

The following devices are not supported by Windows XP. If you upgrade to Windows XP, these devices will not work. For a list of compatible hardware, see the Microsoft Windows XP Hardware Compatibility List at:

http://www.microsoft.com/isapi/redir.dll?Prd=Whistler&Ar=Help&Sba=compatible

.

MessageId= SymbolicName=MSG_HARDWARE_UNSUPPORTED_INSTRUCTIONS_HTML
Language=English
<UL><B>Hardware That Will Not Work With Windows XP</B><BR>
The following devices are not supported by Windows XP. If you upgrade to Windows XP, these devices will not work. For a list of compatible hardware, see the <A HREF="http://www.microsoft.com/isapi/redir.dll?Prd=Whistler&Ar=Help&Sba=compatible">Microsoft Windows XP Hardware Compatibility List</A>.
<P>
.


MessageId= SymbolicName=MSG_INCOMPATIBLE_PREINSTALLED_UTIL_SUBGROUP
Language=English
1-IncompatibleOemUtil%0
.

MessageId= SymbolicName=MSG_PREINSTALLED_UTIL_INSTRUCTIONS
Language=English
Incompatible Factory-Installed Programs

The following programs came with your computer, and they do not support Windows XP and will not work after the upgrade. Check with your computer manufacturer to find out if updated versions are available on its Web site.

.

MessageId= SymbolicName=MSG_PREINSTALLED_UTIL_INSTRUCTIONS_HTML
Language=English
<UL><B>Incompatible Factory-Installed Programs</B><BR>
The following programs came with your computer, and they do not support Windows XP and will not work after the upgrade. Check with your computer manufacturer to find out if updated versions are available on its Web site.
<P>
<UL>%0
.


MessageId= SymbolicName=MSG_INCOMPATIBLE_UTIL_SIMILAR_FEATURE_SUBGROUP
Language=English
!IncompatibleOemUtilSimilarFeature%0
.

MessageId= SymbolicName=MSG_PREINSTALLED_SIMILAR_FEATURE
Language=English
Incompatible Programs Similar to Windows XP Features

The following programs do not support Windows XP. Similar functionality is provided by Windows XP, so these programs aren't required after you upgrade.

.

MessageId= SymbolicName=MSG_PREINSTALLED_SIMILAR_FEATURE_HTML
Language=English
<UL><B>Incompatible Programs Similar to Windows XP Features</B><BR>
The following programs do not support Windows XP. Similar functionality is provided by Windows XP, so these programs aren't required after you upgrade.
<P>
<UL>%0
.

MessageId= SymbolicName=MSG_INCOMPATIBLE_HW_UTIL_SUBGROUP
Language=English
!IncompatibleIhvUtil%0
.

MessageId= SymbolicName=MSG_HW_UTIL_INTRO
Language=English
Incompatible Hardware Accessories

The following programs support your computer hardware; however, they are incompatible with Windows XP.  To see whether updated versions of these programs are available, visit your hardware manufacturer's Web site.

.

MessageId= SymbolicName=MSG_HW_UTIL_INTRO_HTML
Language=English
<UL><B>Incompatible Hardware Accessories</B><BR>
The following programs support your computer hardware; however, they are incompatible with Windows XP.  To see whether updated versions of these programs are available, visit your hardware manufacturer's Web site.
<P>
<UL>%0
.

MessageId= SymbolicName=MSG_BLOCKING_HARDWARE_SUBGROUP
Language=English
Unsupported Hardware Configuration%0
.


MessageId= SymbolicName=MSG_DARWIN_NOT_HANDLED_SUBGROUP
Language=English
Windows Installer%0
.

MessageId= SymbolicName=MSG_DARWIN_NOT_HANDLED
Language=English
Setup has detected applications installed with a version of Windows Installer that is not compatible with Windows XP. If you continue, you will need to reinstall these applications from their original source.%0
.

;// %1 - system drive letter, %2 - space to be freed, %3 - ~ls size, %4 - non-system drive option requirment, in mb, %5 - backup image size
MessageID= SymbolicName=MSG_REPORT_NOT_ENOUGH_DISK_SPACE_FOR_BACKUP
Language=English
Your computer does not have enough disk space to save your current version of Windows for backup. You can cancel Setup now, free additional disk space, and then restart Setup.  You need at least %2 MB free space on drive %1. If you continue, you will not have the ability to uninstall Windows XP.%0
.

;//***************************************************************************
;//
;// Blocking Issues
;//
;//***************************************************************************

MessageId= SymbolicName=MSG_BLOCKING_ITEMS_ROOT
Language=English
Blocking Issues%0
.

MessageId= SymbolicName=MSG_BLOCKING_ITEMS_OTHER
Language=English
Installation Requirements
-------------------------

.

MessageId= SymbolicName=MSG_BLOCKING_ITEMS_OTHER_HTML
Language=English
<B>Installation Requirements</B><BR>
.

MessageId= SymbolicName=MSG_BLOCKING_HARDWARE_INTRO
Language=English
Unsupported Hardware Configuration
----------------------------------
Your computer has hardware devices that prohibit you from upgrading to Windows XP.

.

MessageId= SymbolicName=MSG_BLOCKING_HARDWARE_INTRO_HTML
Language=English
<B>Unsupported Hardware Configuration</B><BR>
Your computer has hardware devices that prohibit you from upgrading to Windows XP.
<P>
<UL>%0
.

;// %1 - system drive letter, %2 - space to be freed, %3 - ~ls size, %4 - non-system drive option requirment, in mb, %5 - backup image size
MessageID= SymbolicName=MSG_NOT_ENOUGH_DISK_SPACE_WITH_LOCALSOURCE_AND_BACKUP
Language=English
Your computer does not have enough disk space to completely install Windows XP. You must free additional disk space before you can upgrade. You need at least %2 MB free space on drive %1, or at least %3 MB on any other drive. If you want to be able to undo the upgrade, a backup will require %5 MB more on any drive.%0
.

;// %1 - system drive letter, %2 - space to be freed, %3 - ~ls size, %4 - non-system drive option requirment, in mb, %5 - backup image size
MessageID= SymbolicName=MSG_NOT_ENOUGH_DISK_SPACE_WITH_LOCALSOURCE_AND_WINDIR_AND_BACKUP
Language=English
Your computer does not have enough disk space to completely install Windows XP. You must free additional disk space before you can upgrade. You need at least %2 MB free space on drive %1, or you need at least %4 MB on drive %1 and %3 MB on any other drive. If you want to be able to undo the upgrade, a backup will require %5 MB more on any drive.%0
.

;//***************************************************************************
;//
;// Software That Must Be Reinstalled (part 2)
;//
;//***************************************************************************

MessageId= SymbolicName=MSG_REINSTALL_INTRO
Language=English
Software That Must Be Reinstalled
---------------------------------
The following programs need to be reinstalled after the upgrade, because they use different files and settings in Windows XP.

.

MessageId= SymbolicName=MSG_REINSTALL_INTRO_HTML
Language=English
<B>Software That Must Be Reinstalled</B><BR>
The following programs need to be reinstalled after the upgrade, because they use different files and settings in Windows XP.
<P>
.

;// NOTE: the next 2 messages (starting with !) don't need localization
MessageId= SymbolicName=MSG_REINSTALL_DETAIL_SUBGROUP
Language=English
!ReinstallDetail%0
.

MessageId= SymbolicName=MSG_REINSTALL_LIST_SUBGROUP
Language=English
!ReinstallList%0
.

MessageId= SymbolicName=MSG_REPORT_INCOMPATIBLE_INSTRUCTIONS
Language=English
This section lists information about programs that are incompatible with Windows XP. Before upgrading, evaluate how important these programs are to you.

.

MessageId= SymbolicName=MSG_REPORT_INCOMPATIBLE_INSTRUCTIONS_HTML
Language=English
This section lists information about programs that are incompatible with Windows XP. Before upgrading, evaluate how important these programs are to you.<P>
.

;// NOTE: the next 2 messages (starting with !) don't need localization
MessageId= SymbolicName=MSG_INCOMPATIBLE_DETAIL_SUBGROUP
Language=English
!IncompatibleDetail%0
.

;//
;// Network incompatibility text
;//

;// %1 is name of protocol, i.e., Banyan Vines
MessageId= SymbolicName=MSG_UNSUPPORTED_PROTOCOL
Language=English
%1 is incompatible with Windows XP. You must obtain Windows XP-compatible software from the manufacturer of this component.%0
.

;// %2 is the protocol vendor, i.e., Banyan
MessageId= SymbolicName=MSG_UNSUPPORTED_PROTOCOL_KNOWN_MFG
Language=English
%1 is incompatible with Windows XP. You must obtain Windows XP-compatible software from %2, the manufacturer of this component.%0
.

MessageId= SymbolicName=MSG_NETWORK_PROTOCOLS
Language=English
Network Incompatibilities\%1%0
.

;// Unusual condition where RAS settings can't be obtained.
MessageId= SymbolicName=MSG_RAS_COMPONENT
Language=English
<unused>%0
.

MessageId= SymbolicName=MSG_RAS_MESSAGE
Language=English
<unused>%0
.

MessageId= SymbolicName=MSG_PRO_SUPPORT_LINK
Language=English
Microsoft Windows XP Professional Page (http://go.microsoft.com/fwlink/?LinkId=574)%0
.

MessageId= SymbolicName=MSG_PRO_SUPPORT_LINK_HTML
Language=English
<A HREF="http://go.microsoft.com/fwlink/?LinkId=574">Microsoft Windows XP Professional</A>%0
.

MessageId= SymbolicName=MSG_PER_SUPPORT_LINK
Language=English
Microsoft Windows XP Home Edition Page(http://go.microsoft.com/fwlink/?LinkId=573)%0
.

MessageId= SymbolicName=MSG_PER_SUPPORT_LINK_HTML
Language=English
<A HREF="http://go.microsoft.com/fwlink/?LinkId=573">Microsoft Windows XP Home Edition</A>%0
.

;// %1 - PER/PRO Web link
MessageId= SymbolicName=MSG_REPORT_BLOCKING_INSTRUCTIONS
Language=English
Setup found some blocking issues. You must address these issues before you can continue upgrading your computer.

.

;// %1 - PER/PRO Web link
MessageId= SymbolicName=MSG_REPORT_BLOCKING_INSTRUCTIONS_HTML
Language=English
Setup found some blocking issues. You must address these issues before you can continue upgrading your computer.<P>

.

MessageId= SymbolicName=MSG_REPORT_BACKUP_INSTRUCTIONS
Language=English
Setup will automatically back up your existing version of Windows. You can restore your computer safely even if these upgrade problems remain. To uninstall Windows XP, go to Add/Remove Programs in Control Panel.

.

MessageId= SymbolicName=MSG_REPORT_BACKUP_INSTRUCTIONS_HTML
Language=English
Setup will automatically back up your existing version of Windows. You can restore your computer safely even if these upgrade problems remain. To uninstall Windows XP, go to Add/Remove Programs in Control Panel.<P>

.

MessageId= SymbolicName=MSG_HARDWARE_REINSTALL_PNP_INSTRUCTIONS
Language=English
Hardware That Requires Reinstallation of Drivers

The following hardware will not work immediately after the upgrade to Windows XP. However, these devices will work if you reinstall Windows XP or Windows 2000 compatible drivers for these devices. Check the Microsoft Windows Update Web site or your hardware vendors' Web sites to obtain the latest versions.

.

MessageId= SymbolicName=MSG_HARDWARE_REINSTALL_PNP_INSTRUCTIONS_HTML
Language=English
<UL><B>Hardware That Requires Reinstallation of Drivers</B><BR>
The following hardware will not work immediately after the upgrade to Windows XP. However, these devices will work if you reinstall Windows XP or Windows 2000 compatible drivers for these devices. Check the Microsoft Windows Update Web site or your hardware vendors' Web sites to obtain the latest versions.
<P>
.

MessageId= SymbolicName=MSG_REINSTALL_HARDWARE_PNP_SUBGROUP
Language=English
3-Reinstall Hardware%0
.

MessageId= SymbolicName=MSG_CONNECTION_PASSWORD_SUBGROUP
Language=English
Dial-Up Networking Passwords Will Not Be Remembered%0
.

MessageId= SymbolicName=MSG_CONNECTION_PASSWORD_INTRO
Language=English
Dial-Up Networking Passwords Will Not Be Remembered

The dial-up networking passwords for the following connections will not be remembered after the upgrade. You might need to look them up or contact your Internet Service Provider if you do not remember the password.

.

MessageId= SymbolicName=MSG_CONNECTION_PASSWORD_INTRO_HTML
Language=English
<UL><B>Dial-Up Networking Passwords Will Not Be Remembered</B><BR>
The dial-up networking passwords for the following connections will not be remembered after the upgrade. You might need to look them up or contact your Internet Service Provider if you do not remember the password.
<P>
<UL>
.

MessageId= SymbolicName=MSG_BLOCKING_TOC
Language=English
Blocking Issues%0

.
MessageId= SymbolicName=MSG_WARNING_TOC
Language=English
Warnings%0

.
MessageId= SymbolicName=MSG_INFO_TOC
Language=English
Helpful Information%0

.

MessageId= SymbolicName=MSG_BLOCKING_INTRO
Language=English
BLOCKING ISSUES
===============
Setup found some issues that will prevent you from upgrading your Windows installation. You must fix all of these issues before you can upgrade to Windows XP.

.

MessageId= SymbolicName=MSG_BLOCKING_INTRO_HTML
Language=English
<HR>
<B>Blocking Issues</B> (<A HREF="#top">return to top</A>)<BR>
Setup found some issues that will prevent you from upgrading your Windows installation. You must fix all of these issues before you can upgrade to Windows XP.
<P>
.

MessageId= SymbolicName=MSG_WARNING_INTRO
Language=English
WARNINGS
========
The following issues might require you to obtain files from Microsoft Windows Update Web site or a manufacturer's Web site. You can still continue to upgrade to Windows XP without resolving these issues, but some hardware or software might not work. Follow the recommendations in each section.

.

MessageId= SymbolicName=MSG_WARNING_INTRO_HTML
Language=English
<HR>
<B>Warnings</B> (<A HREF="#top">return to top</A>)<BR>
The following issues might require you to obtain files from Microsoft Windows Update Web site or a manufacturer's Web site. You can still continue to upgrade to Windows XP without resolving these issues, but some hardware or software might not work. Follow the recommendations in each section.
<P>
.

MessageId= SymbolicName=MSG_INFO_INTRO
Language=English
HELPFUL INFORMATION
===================
The following issues are listed for your information only. You can continue the upgrade to Windows XP.

.

MessageId= SymbolicName=MSG_INFO_INTRO_HTML
Language=English
<HR>
<B>Helpful Information</B> (<A HREF="#top">return to top</A>)<BR>
The following issues are listed for your information only. You can continue the upgrade to Windows XP.
<P>
.


MessageId= SymbolicName=MSG_HARDWARE_UNSUPPORTED_INSTRUCTIONS2
Language=English
%0
.

MessageId= SymbolicName=MSG_HARDWARE_UNSUPPORTED_INSTRUCTIONS_HTML2
Language=English
</UL>%0
.


MessageId= SymbolicName=MSG_HARDWARE_REINSTALL_PNP_INSTRUCTIONS2
Language=English
%0
.

MessageId= SymbolicName=MSG_HARDWARE_REINSTALL_PNP_INSTRUCTIONS_HTML2
Language=English
</UL>%0
.


MessageId= SymbolicName=MSG_UNINDENT
Language=English
%0
.

MessageId= SymbolicName=MSG_UNINDENT_HTML
Language=English
</UL>%0
.


MessageId= SymbolicName=MSG_UNINDENT2
Language=English
%0
.

MessageId= SymbolicName=MSG_UNINDENT2_HTML
Language=English
</UL></UL>%0
.

MessageId= SymbolicName=MSG_MISC_WARNINGS_ROOT
Language=English
Miscellaneous%0
.

MessageId= SymbolicName=MSG_MISC_WARNINGS_INTRO
Language=English
Miscellaneous
-------------
You should review the following issues before upgrading.

.

MessageId= SymbolicName=MSG_MISC_WARNINGS_INTRO_HTML
Language=English
<B>Miscellaneous</B><BR>
You should review the following issues before upgrading.
<P>
.

MessageId= SymbolicName=MSG_CONTENTS_TITLE
Language=English
Contents:
.

MessageId= SymbolicName=MSG_CONTENTS_TITLE_HTML
Language=English
For more information, click a topic:<P>
.

MessageId= SymbolicName=MSG_SHARED_USER_ACCOUNTS
Language=English
Shared User Accounts%0
.

;// %1-Win9x OS name ; %2 - XP profiles folder name
MessageId= SymbolicName=MSG_SHARED_USER_ACCOUNTS_MESSAGE
Language=English
Setup detected that two or more users share the same settings. Because Windows XP allows multiple users to log on simultaneously, settings cannot be shared. Setup will only transfer settings for the user account that is currently logged on. You can create new user accounts after Setup completes. To find files from %1 user accounts, search in the %2 folder.
.

;// %1 is name of protocol, i.e., Banyan Vines
MessageId= SymbolicName=MSG_UNSUPPORTED_PROTOCOL_FROM_MICROSOFT
Language=English
This version of %1 will not work with Windows XP. To update a more recent version of this software, go to the Microsoft Web site (http://www.microsoft.com).%0
.
;//
;// ####################################################################################
;// #
;// #  last messages (a localization tool requirement)
;// #
;// ####################################################################################
;//

MessageId=30000 SymbolicName=MSG_LAST
Language=English
%0
.

MessageId= SymbolicName=MSG_UNKOWN_WINDOWS
Language=English
Windows
.
