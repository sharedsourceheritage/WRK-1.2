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
// MessageId: MSG_FIRST
//
// MessageText:
//
//  MSG_FIRST
//
#define MSG_FIRST                        0x0000EA60L

//
// MessageId: MSG_ERROR_WITH_SYSTEM_ERROR
//
// MessageText:
//
//  %1
//  
//  %2%0
//
#define MSG_ERROR_WITH_SYSTEM_ERROR      0x0000EA61L

//
// MessageId: MSG_CANT_INIT
//
// MessageText:
//
//  The application could not be initialized.%0
//
#define MSG_CANT_INIT                    0x0000EA62L

//
// MessageId: MSG_ARGS
//
// MessageText:
//
//  Invalid program arguments were specified.
//  
//      /i:<master_oc_inf> - (required) Specifies the name of the master inf.
//                           The installation source path is taken from here.
//  
//      /u:<unattend_spec> - Specifies unattended operation parameters.
//      
//      /r                 - Suppress reboot (when reboot is necessary).
//  
//      /z                 - Indicates that args that follow are not OC args 
//                           and should be passed to components.
//  
//      /n                 - Forces the specified master inf to be treated as new.
//  
//      /f                 - Indicates that all component installation states
//                           should be initialized as if their installers had
//                           never been run.
//                           
//      /c                 - Disallow cancel during final installation phase.
//      
//      /x                 - Supresses the 'initializing' banner.
//  
//      /q                 - for use with /u.  Runs the unattended installation
//                           without UI.        
//  
//      /w                 - for use with /u.  If a reboot is required, prompt
//                           the user instead of automatically rebooting.
//                           
//      /l                 - Multi-Language aware installation
//                           
//
#define MSG_ARGS                         0x0000EA63L

//
// MessageId: MSG_ONLY_ONE_INST
//
// MessageText:
//
//  Another copy of this setup program is running. Please wait 
//  until the other setup is completed before attempting to run 
//  this program again.%0
//
#define MSG_ONLY_ONE_INST                0x0000EA64L

//
// MessageId: MSG_LOG_GUI_START
//
// MessageText:
//
//  Optional Component Manager Setup has started.
//
#define MSG_LOG_GUI_START                0x0000EA65L

//
// MessageId: MSG_NOT_ADMIN
//
// MessageText:
//
//  You do not have permissions to use the Add/Remove Windows Components.
//  
//  Ask a computer administrator to install the optional components for you.%0
//
#define MSG_NOT_ADMIN                    0x0000EA66L

