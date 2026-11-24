//
// Text strings for sc.exe
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
// MessageId: SC_HELP_GENERIC
//
// MessageText:
//
//  DESCRIPTION:
//          SC is a command line program used for communicating with the
//          Service Control Manager and services.
//  USAGE:
//          sc <server> [command] [service name] <option1> <option2>...
//  
//  
//          The option <server> has the form "\\ServerName"
//          Further help on commands can be obtained by typing: "sc [command]"
//          Commands:
//            query-----------Queries the status for a service, or
//                            enumerates the status for types of services.
//            queryex---------Queries the extended status for a service, or
//                            enumerates the status for types of services.
//            start-----------Starts a service.
//            pause-----------Sends a PAUSE control request to a service.
//            interrogate-----Sends an INTERROGATE control request to a service.
//            continue--------Sends a CONTINUE control request to a service.
//            stop------------Sends a STOP request to a service.
//            config----------Changes the configuration of a service (persistent).
//            description-----Changes the description of a service.
//            failure---------Changes the actions taken by a service upon failure.
//            qc--------------Queries the configuration information for a service.
//            qdescription----Queries the description for a service.
//            qfailure--------Queries the actions taken by a service upon failure.
//            delete----------Deletes a service (from the registry).
//            create----------Creates a service. (adds it to the registry).
//            control---------Sends a control to a service.
//            sdshow----------Displays a service's security descriptor.
//            sdset-----------Sets a service's security descriptor.
//            GetDisplayName--Gets the DisplayName for a service.
//            GetKeyName------Gets the ServiceKeyName for a service.
//            EnumDepend------Enumerates Service Dependencies.
//  
//          The following commands don't require a service name:
//          sc <server> <command> <option>
//            boot------------(ok | bad) Indicates whether the last boot should
//                            be saved as the last-known-good boot configuration
//            Lock------------Locks the Service Database
//            QueryLock-------Queries the LockStatus for the SCManager Database
//  EXAMPLE:
//          sc start MyService
//  
//  Would you like to see help for the QUERY and QUERYEX commands? [ y | n ]: 
//
#define SC_HELP_GENERIC                  0x00000001L

// Note to localization team: if you translate the "[ y | n ]" in the above
// message, then please also translate the character in SC_PROMPT_YES_CHARACTER below.
//
// MessageId: SC_HELP_QUERY
//
// MessageText:
//
//  
//  
//  QUERY and QUERYEX OPTIONS:
//          If the query command is followed by a service name, the status
//          for that service is returned.  Further options do not apply in
//          this case.  If the query command is followed by nothing or one of
//          the options listed below, the services are enumerated.
//      type=    Type of services to enumerate (driver, service, all)
//               (default = service)
//      state=   State of services to enumerate (inactive, all)
//               (default = active)\n"
//      bufsize= The size (in bytes) of the enumeration buffer
//               (default = %1)
//      ri=      The resume index number at which to begin the enumeration\n"
//               (default = 0)
//      group=   Service group to enumerate
//               (default = all groups)
//  
//  SYNTAX EXAMPLES
//  sc query                - Enumerates status for active services & drivers
//  sc query messenger      - Displays status for the messenger service
//  sc queryex messenger    - Displays extended status for the messenger service
//  sc query type= driver   - Enumerates only active drivers
//  sc query type= service  - Enumerates only Win32 services
//  sc query state= all     - Enumerates all services & drivers
//  sc query bufsize= 50    - Enumerates with a 50 byte buffer
//  sc query ri= 14         - Enumerates with resume index = 14
//  sc queryex group= \"\"    - Enumerates active services not in a group
//  sc query type= service type= interact - Enumerates all interactive services
//  sc query type= driver group= NDIS     - Enumerates all NDIS drivers
//
#define SC_HELP_QUERY                    0x00000002L

//
// MessageId: SC_HELP_CONFIG
//
// MessageText:
//
//  DESCRIPTION:
//          Modifies a service entry in the registry and Service Database.
//  USAGE:
//          sc <server> config [service name] <option1> <option2>...
//  
//  OPTIONS:
//  NOTE: The option name includes the equal sign.
//   type= <own|share|interact|kernel|filesys|rec|adapt>
//   start= <boot|system|auto|demand|disabled>
//   error= <normal|severe|critical|ignore>
//   binPath= <BinaryPathName>
//   group= <LoadOrderGroup>
//   tag= <yes|no>
//   depend= <Dependencies(separated by / (forward slash))>
//   obj= <AccountName|ObjectName>
//   DisplayName= <display name>
//   password= <password>
//
#define SC_HELP_CONFIG                   0x00000003L

//
// MessageId: SC_HELP_CREATE
//
// MessageText:
//
//  DESCRIPTION:
//          Creates a service entry in the registry and Service Database.
//  USAGE:
//          sc <server> create [service name] [binPath= ] <option1> <option2>...
//  
//  OPTIONS:
//  NOTE: The option name includes the equal sign.
//   type= <own|share|interact|kernel|filesys|rec>
//         (default = own)
//   start= <boot|system|auto|demand|disabled>
//         (default = demand)
//   error= <normal|severe|critical|ignore>
//         (default = normal)
//   binPath= <BinaryPathName>
//   group= <LoadOrderGroup>
//   tag= <yes|no>
//   depend= <Dependencies(separated by / (forward slash))>
//   obj= <AccountName|ObjectName>
//         (default = LocalSystem)
//   DisplayName= <display name>
//   password= <password>
//
#define SC_HELP_CREATE                   0x00000004L

//
// MessageId: SC_HELP_CHANGE_FAILURE
//
// MessageText:
//
//  DESCRIPTION:
//          Changes the actions upon failure
//  USAGE:
//          sc <server> failure [service name] <option1> <option2>...
//  
//  OPTIONS:
//          reset=   <Length of period of no failures (in seconds)
//                    after which to reset the failure count to 0 (may be INFINITE)>
//                    (Must be used in conjunction with actions= )
//          reboot=  <Message broadcast before rebooting on failure>
//          command= <Command line to be run on failure>
//          actions= <Failure actions and their delay time (in milliseconds),
//                    separated by / (forward slash) -- e.g., run/5000/reboot/800
//                    Valid actions are <run|restart|reboot> >
//                    (Must be used in conjunction with the reset= option)
//
#define SC_HELP_CHANGE_FAILURE           0x00000005L

//
// MessageId: SC_HELP_START
//
// MessageText:
//
//  DESCRIPTION:
//          Starts a service running.
//  USAGE:
//          sc <server> start [service name] <arg1> <arg2> ...
//
#define SC_HELP_START                    0x00000006L

//
// MessageId: SC_HELP_PAUSE
//
// MessageText:
//
//  DESCRIPTION:
//          Sends a PAUSE control request to a service.
//  USAGE:
//          sc <server> pause [service name]
//
#define SC_HELP_PAUSE                    0x00000007L

//
// MessageId: SC_HELP_INTERROGATE
//
// MessageText:
//
//  DESCRIPTION:
//          Sends an INTERROGATE control request to a service.
//  USAGE:
//          sc <server> interrogate [service name]
//
#define SC_HELP_INTERROGATE              0x00000008L

//
// MessageId: SC_HELP_CONTROL
//
// MessageText:
//
//  DESCRIPTION:
//          Sends a CONTROL code to a service.
//  USAGE:
//          sc <server> control [service name] <value>
//              <value> = user-defined control code
//              <value> = <paramchange|
//                         netbindadd|netbindremove|
//                         netbindenable|netbinddisable>
//  
//  See also sc stop, sc pause, etc.
//
#define SC_HELP_CONTROL                  0x00000009L

//
// MessageId: SC_HELP_CONTINUE
//
// MessageText:
//
//  DESCRIPTION:
//          Sends a CONTINUE control request to a service.
//  USAGE:
//          sc <server> continue [service name]
//
#define SC_HELP_CONTINUE                 0x0000000AL

//
// MessageId: SC_HELP_STOP
//
// MessageText:
//
//  DESCRIPTION:
//          Sends a STOP control request to a service.
//  USAGE:
//          sc <server> stop [service name]
//
#define SC_HELP_STOP                     0x0000000BL

//
// MessageId: SC_HELP_CHANGE_DESCRIPTION
//
// MessageText:
//
//  DESCRIPTION:
//          Sets the description string for a service.
//  USAGE:
//          sc <server> description [service name] [description]
//
#define SC_HELP_CHANGE_DESCRIPTION       0x0000000CL

//
// MessageId: SC_HELP_QUERY_CONFIG
//
// MessageText:
//
//  DESCRIPTION:
//          Queries the configuration information for a service.
//  USAGE:
//          sc <server> qc [service name] <bufferSize>
//
#define SC_HELP_QUERY_CONFIG             0x0000000DL

//
// MessageId: SC_HELP_QUERY_DESCRIPTION
//
// MessageText:
//
//  DESCRIPTION:
//          Retrieves the description string of a service.
//  USAGE:
//          sc <server> qdescription [service name] <bufferSize>
//
#define SC_HELP_QUERY_DESCRIPTION        0x0000000EL

//
// MessageId: SC_HELP_QUERY_FAILURE
//
// MessageText:
//
//  DESCRIPTION:
//          Retrieves the actions performed on service failure.
//  USAGE:
//          sc <server> qfailure [service name] <bufferSize>
//
#define SC_HELP_QUERY_FAILURE            0x0000000FL

//
// MessageId: SC_HELP_QUERY_LOCK
//
// MessageText:
//
//  DESCRIPTION:
//          Queries the Lock Status for a SC Manager Database.
//  USAGE:
//          sc <server> querylock <bufferSize>
//
#define SC_HELP_QUERY_LOCK               0x00000010L

//
// MessageId: SC_HELP_DELETE
//
// MessageText:
//
//  DESCRIPTION:
//          Deletes a service entry from the registry.
//          If the service is running, or another process has an
//          open handle to the service, the service is simply marked
//          for deletion.
//  USAGE:
//          sc <server> delete [service name]
//
#define SC_HELP_DELETE                   0x00000011L

//
// MessageId: SC_HELP_BOOT
//
// MessageText:
//
//  DESCRIPTION:
//          Indicates whether the last boot should be saved as the
//          last-known-good boot configuration on the local machine.
//          If specified, the server name is ignored.
//  USAGE:
//          sc <server> boot <bad | ok>
//
#define SC_HELP_BOOT                     0x00000012L

//
// MessageId: SC_HELP_GET_DISPLAY_NAME
//
// MessageText:
//
//  DESCRIPTION:
//          Gets the display name associated with a particular service
//  USAGE:
//          sc <server> GetDisplayName <service key name> <bufsize>
//
#define SC_HELP_GET_DISPLAY_NAME         0x00000013L

//
// MessageId: SC_HELP_GET_KEY_NAME
//
// MessageText:
//
//  DESCRIPTION:
//          Gets the key name associated with a particular service,
//          using the display name as input
//  USAGE:
//          sc <server> GetKeyName <service display name> <bufsize>
//
#define SC_HELP_GET_KEY_NAME             0x00000014L

//
// MessageId: SC_HELP_ENUM_DEPEND
//
// MessageText:
//
//  DESCRIPTION:
//          Enumerates the Services that are dependent on this one
//  USAGE:
//          sc <server> EnumDepend <service name> <bufsize>
//
#define SC_HELP_ENUM_DEPEND              0x00000015L

//
// MessageId: SC_HELP_SDSHOW
//
// MessageText:
//
//  DESCRIPTION:
//          Displays a service's security descriptor in SDDL format
//  USAGE:
//          sc <server> sdshow <service name>
//
#define SC_HELP_SDSHOW                   0x00000016L

//
// MessageId: SC_HELP_SDSET
//
// MessageText:
//
//  DESCRIPTION:
//          Sets a service's security descriptor
//  USAGE:
//          sc <server> sdset <service name> <SD in SDDL format>
//
#define SC_HELP_SDSET                    0x00000017L

//
// MessageId: SC_DISPLAY_DESCRIPTION
//
// MessageText:
//
//  
//  SERVICE_NAME: %1
//  DESCRIPTION:  %2
//
#define SC_DISPLAY_DESCRIPTION           0x00000023L

//
// MessageId: SC_DISPLAY_GET_NAME
//
// MessageText:
//
//  Name = %1
//
#define SC_DISPLAY_GET_NAME              0x00000024L

//
// MessageId: SC_DISPLAY_SD
//
// MessageText:
//
//  
//  %1
//
#define SC_DISPLAY_SD                    0x00000025L

//
// MessageId: SC_DISPLAY_LOCKED_TRUE
//
// MessageText:
//
//          IsLocked      : TRUE
//
#define SC_DISPLAY_LOCKED_TRUE           0x00000026L

//
// MessageId: SC_DISPLAY_LOCKED_FALSE
//
// MessageText:
//
//          IsLocked      : FALSE
//
#define SC_DISPLAY_LOCKED_FALSE          0x00000027L

//
// MessageId: SC_DISPLAY_LOCK_STATS
//
// MessageText:
//
//          LockOwner     : %1
//          LockDuration  : %2 (seconds since acquired)
//  
//
#define SC_DISPLAY_LOCK_STATS            0x00000028L

//
// MessageId: SC_DISPLAY_TAG
//
// MessageText:
//
//  [SC] Tag = %1
//
#define SC_DISPLAY_TAG                   0x00000029L

//
// MessageId: SC_DISPLAY_ENUM_NUMBER
//
// MessageText:
//
//  [SC] %1: entriesread = %2
//
#define SC_DISPLAY_ENUM_NUMBER           0x0000002AL

//
// MessageId: SC_DISPLAY_NEWLINE
//
// MessageText:
//
//  
//
#define SC_DISPLAY_NEWLINE               0x0000002BL

// Note to localization team: if you translate the letter "u" in the following
// message, then please also translate the character in SC_PROMPT_UNLOCK_CHARACTER
//
// MessageId: SC_DISPLAY_DATABASE_LOCKED
//
// MessageText:
//
//  
//  Active database is locked.
//  To unlock via API, press u:
//
#define SC_DISPLAY_DATABASE_LOCKED       0x0000002DL

//
// MessageId: SC_DISPLAY_DATABASE_UNLOCKING
//
// MessageText:
//
//  
//  [SC] Will be unlocking database by exiting
//
#define SC_DISPLAY_DATABASE_UNLOCKING    0x0000002EL

//
// MessageId: SC_DISPLAY_STATUS_WITHOUT_DISPLAY_NAME
//
// MessageText:
//
//  
//  SERVICE_NAME: %1 %2
//          TYPE               : %3  %4 %5
//          STATE              : %6  %7
//                                  (%8, %9, %10)
//          WIN32_EXIT_CODE    : %11  (0x%12)
//          SERVICE_EXIT_CODE  : %13  (0x%14)
//          CHECKPOINT         : 0x%15
//          WAIT_HINT          : 0x%16
//
#define SC_DISPLAY_STATUS_WITHOUT_DISPLAY_NAME 0x0000002FL

//
// MessageId: SC_DISPLAY_STATUS_WITH_DISPLAY_NAME
//
// MessageText:
//
//  
//  SERVICE_NAME: %1
//  DISPLAY_NAME: %2
//          TYPE               : %3  %4 %5
//          STATE              : %6  %7
//                                  (%8, %9, %10)
//          WIN32_EXIT_CODE    : %11  (0x%12)
//          SERVICE_EXIT_CODE  : %13  (0x%14)
//          CHECKPOINT         : 0x%15
//          WAIT_HINT          : 0x%16
//
#define SC_DISPLAY_STATUS_WITH_DISPLAY_NAME 0x00000030L

//
// MessageId: SC_DISPLAY_STATUSEX_WITHOUT_DISPLAY_NAME
//
// MessageText:
//
//  
//  SERVICE_NAME: %1 %2
//          TYPE               : %3  %4 %5
//          STATE              : %6  %7
//                                  (%8, %9, %10)
//          WIN32_EXIT_CODE    : %11  (0x%12)
//          SERVICE_EXIT_CODE  : %13  (0x%14)
//          CHECKPOINT         : 0x%15
//          WAIT_HINT          : 0x%16
//          PID                : %17
//          FLAGS              : %18
//
#define SC_DISPLAY_STATUSEX_WITHOUT_DISPLAY_NAME 0x00000031L

//
// MessageId: SC_DISPLAY_STATUSEX_WITH_DISPLAY_NAME
//
// MessageText:
//
//  
//  SERVICE_NAME: %1
//  DISPLAY_NAME: %2
//          TYPE               : %3  %4 %5
//          STATE              : %6  %7
//                                  (%8, %9, %10)
//          WIN32_EXIT_CODE    : %11  (0x%12)
//          SERVICE_EXIT_CODE  : %13  (0x%14)
//          CHECKPOINT         : 0x%15
//          WAIT_HINT          : 0x%16
//          PID                : %17
//          FLAGS              : %18
//
#define SC_DISPLAY_STATUSEX_WITH_DISPLAY_NAME 0x00000032L

//
// MessageId: SC_DISPLAY_FAILURE
//
// MessageText:
//
//  
//  SERVICE_NAME: %1
//          RESET_PERIOD (in seconds)    : %2
//          REBOOT_MESSAGE               : %3
//          COMMAND_LINE                 : %4
//
#define SC_DISPLAY_FAILURE               0x00000033L

//
// MessageId: SC_DISPLAY_FAILURE_RESTART_FIRST
//
// MessageText:
//
//          FAILURE_ACTIONS              : RESTART -- Delay = %1 milliseconds.
//
#define SC_DISPLAY_FAILURE_RESTART_FIRST 0x00000034L

//
// MessageId: SC_DISPLAY_FAILURE_RESTART
//
// MessageText:
//
//                                         RESTART -- Delay = %1 milliseconds.
//
#define SC_DISPLAY_FAILURE_RESTART       0x00000035L

//
// MessageId: SC_DISPLAY_FAILURE_REBOOT_FIRST
//
// MessageText:
//
//          FAILURE_ACTIONS              : REBOOT -- Delay = %1 milliseconds.
//
#define SC_DISPLAY_FAILURE_REBOOT_FIRST  0x00000036L

//
// MessageId: SC_DISPLAY_FAILURE_REBOOT
//
// MessageText:
//
//                                         REBOOT -- Delay = %1 milliseconds.
//
#define SC_DISPLAY_FAILURE_REBOOT        0x00000037L

//
// MessageId: SC_DISPLAY_FAILURE_COMMAND_FIRST
//
// MessageText:
//
//          FAILURE_ACTIONS              : RUN PROCESS -- Delay = %1 milliseconds.
//
#define SC_DISPLAY_FAILURE_COMMAND_FIRST 0x00000038L

//
// MessageId: SC_DISPLAY_FAILURE_COMMAND
//
// MessageText:
//
//                                         RUN PROCESS -- Delay = %1 milliseconds.
//
#define SC_DISPLAY_FAILURE_COMMAND       0x00000039L

//
// MessageId: SC_DISPLAY_CONFIG
//
// MessageText:
//
//  
//  SERVICE_NAME: %1
//          TYPE               : %2  %3 %4
//          START_TYPE         : %5   %6
//          ERROR_CONTROL      : %7   %8
//          BINARY_PATH_NAME   : %9
//          LOAD_ORDER_GROUP   : %10
//          TAG                : %11
//          DISPLAY_NAME       : %12
//          DEPENDENCIES       : %13
//
#define SC_DISPLAY_CONFIG                0x0000003AL

//
// MessageId: SC_DISPLAY_CONFIG_DEPENDENCY
//
// MessageText:
//
//                             : %1
//
#define SC_DISPLAY_CONFIG_DEPENDENCY     0x0000003BL

//
// MessageId: SC_DISPLAY_CONFIG_START_NAME
//
// MessageText:
//
//          SERVICE_START_NAME : %1
//
#define SC_DISPLAY_CONFIG_START_NAME     0x0000003CL

//
// MessageId: SC_API_SUCCEEDED
//
// MessageText:
//
//  [SC] %1 SUCCESS
//
#define SC_API_SUCCEEDED                 0x00000064L

//
// MessageId: SC_API_FAILED
//
// MessageText:
//
//  [SC] %1 FAILED %2:
//  
//  %3
//
#define SC_API_FAILED                    0x00000065L

//
// MessageId: SC_API_INSUFFICIENT_BUFFER
//
// MessageText:
//
//  [SC] %1 needs %2 bytes
//
#define SC_API_INSUFFICIENT_BUFFER       0x00000066L

//
// MessageId: SC_API_INSUFFICIENT_BUFFER_ENUM
//
// MessageText:
//
//  
//  [SC] %1: more data, need %2 bytes start resume at index %3
//
#define SC_API_INSUFFICIENT_BUFFER_ENUM  0x00000067L

//
// MessageId: SC_API_INSUFFICIENT_BUFFER_ENUMDEPEND
//
// MessageText:
//
//  
//  [SC] %1: more data, need %2 bytes
//
#define SC_API_INSUFFICIENT_BUFFER_ENUMDEPEND 0x00000068L

//
// MessageId: SC_API_INVALID_FIELD
//
// MessageText:
//
//  
//  ERROR: Invalid %1 field
//  
//
#define SC_API_INVALID_FIELD             0x00000069L

//
// MessageId: SC_API_INVALID_OPTION
//
// MessageText:
//
//  
//  ERROR:  Invalid Option
//  
//
#define SC_API_INVALID_OPTION            0x0000006AL

//
// MessageId: SC_API_NO_NAME_WITH_GROUP
//
// MessageText:
//
//  
//  ERROR:  Cannot specify a service name when enumerating a group
//  
//
#define SC_API_NO_NAME_WITH_GROUP        0x0000006BL

//
// MessageId: SC_API_NAME_REQUIRED
//
// MessageText:
//
//  
//  ERROR:  A service name is required
//  
//
#define SC_API_NAME_REQUIRED             0x0000006CL

//
// MessageId: SC_API_UNRECOGNIZED_COMMAND
//
// MessageText:
//
//  
//  ERROR:  Unrecognized command
//  
//
#define SC_API_UNRECOGNIZED_COMMAND      0x0000006DL

//
// MessageId: SC_API_RESET_AND_ACTIONS
//
// MessageText:
//
//  
//  ERROR:  The reset and actions options must be set simultaneously
//  
//
#define SC_API_RESET_AND_ACTIONS         0x0000006EL

// This string represents the first character in the word "unlock".  It is used
// to test the key typed by the user in response to the SC_DISPLAY_DATABASE_LOCKED
// prompt, defined above.
//
// MessageId: SC_PROMPT_UNLOCK_CHARACTER
//
// MessageText:
//
//  u
//
#define SC_PROMPT_UNLOCK_CHARACTER       0x0000006FL

// This string represents the first character in the word "yes".  It is used
// to test the key typed by the user in response to the question at the end
// of SC_HELP_GENERIC, defined above.
//
// MessageId: SC_PROMPT_YES_CHARACTER
//
// MessageText:
//
//  y
//
#define SC_PROMPT_YES_CHARACTER          0x00000070L

