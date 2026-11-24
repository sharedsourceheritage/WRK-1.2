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
// MessageId: ID_DSP_TXT_TRUECOLOR
//
// MessageText:
//
//  True Color
//
#define ID_DSP_TXT_TRUECOLOR             0x00000001L

//
// MessageId: ID_DSP_TXT_COLOR
//
// MessageText:
//
//  %1!d! Colors
//
#define ID_DSP_TXT_COLOR                 0x00000002L

//
// MessageId: ID_DSP_TXT_XBYY
//
// MessageText:
//
//  %1!d! by %2!d! pixels
//
#define ID_DSP_TXT_XBYY                  0x00000003L

//
// MessageId: ID_DSP_TXT_TEST_MODE
//
// MessageText:
//
//  Testing Mode
//
#define ID_DSP_TXT_TEST_MODE             0x00000004L

//
// MessageId: ID_DSP_TXT_DID_TEST_RESULT
//
// MessageText:
//
//  Did you see the test bitmap properly?
//
#define ID_DSP_TXT_DID_TEST_RESULT       0x00000005L

//
// MessageId: ID_DSP_TXT_DID_TEST_WARNING
//
// MessageText:
//
//  The new mode will be tested.
//  Your graphics adapter will be set to the new mode temporarily so you can
//  determine whether it works properly.
//  Please press OK and then wait 5 seconds.
//
#define ID_DSP_TXT_DID_TEST_WARNING      0x00000006L

//
// MessageId: ID_DSP_TXT_SETTINGS
//
// MessageText:
//
//  Display Settings
//
#define ID_DSP_TXT_SETTINGS              0x00000007L

//
// MessageId: ID_DSP_TXT_TEST_FAILED
//
// MessageText:
//
//  The screen was not visible due to a limitation of your video card or display
//  monitor.
//  Please try different settings for your display.
//
#define ID_DSP_TXT_TEST_FAILED           0x00000008L

//
// MessageId: ID_DSP_TXT_ADMIN_CHANGE
//
// MessageText:
//
//  You do not have the required Administrative privilege to change these
//  system settings. Please contact your Administrator.
//
#define ID_DSP_TXT_ADMIN_CHANGE          0x00000009L

//
// MessageId: ID_DSP_TXT_CHANGE_SETTINGS
//
// MessageText:
//
//  Change Settings.
//
#define ID_DSP_TXT_CHANGE_SETTINGS       0x0000000AL

//
// MessageId: ID_DSP_TXT_COMPATABLE_DEV
//
// MessageText:
//
//  %1 compatible display adapter
//
#define ID_DSP_TXT_COMPATABLE_DEV        0x0000000BL

//
// MessageId: MSG_SETTING_MB
//
// MessageText:
//
//  %1!d! MB
//
#define MSG_SETTING_MB                   0x0000000CL

//
// MessageId: MSG_SETTING_KB
//
// MessageText:
//
//  %1!d! KB
//
#define MSG_SETTING_KB                   0x0000000DL

//
// MessageId: ID_DSP_TXT_FREQ
//
// MessageText:
//
//  %1!d! Hertz
//
#define ID_DSP_TXT_FREQ                  0x0000000EL

//
// MessageId: ID_DSP_TXT_INTERLACED
//
// MessageText:
//
//  %1!d! Hertz, Interlaced
//
#define ID_DSP_TXT_INTERLACED            0x0000000FL

//
// MessageId: ID_DSP_TXT_DEFFREQ
//
// MessageText:
//
//  Use hardware default setting
//
#define ID_DSP_TXT_DEFFREQ               0x00000010L

