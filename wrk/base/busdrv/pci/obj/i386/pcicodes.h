/*++ BUILD Version: 0001    // Increment this if a change has global effects

Copyright (c) 1997  Microsoft Corporation

Module Name:

    pcicodes.mc

Abstract:

    Internationalizable descriptions of PCI devices based on Base Class
    and Sub Class.

Author:

    Peter Johnston (peterj) 28-Mar-1997

Revision History:

--*/

//
//  Status values are 32 bit values layed out as follows:
//
//   3 3 2 2 2 2 2 2 2 2 2 2 1 1 1 1 1 1 1 1 1 1
//   1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0 9 8 7 6 5 4 3 2 1 0
//  +---+-+-------------------------+-------------------------------+
//  |Sev|C|       Facility          |               Code            |
//  +---+-+-------------------------+-------------------------------+
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
//      Facility - is the facility code
//
//      Code - is the facility's status code
//
//
//  For PCI, the Message ID is made up of the 8 bit Base Class field and
//  the 8 bit Sub Class field from the PCI Mandatory header.
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
#define STATUS_SEVERITY_WARNING          0x2
#define STATUS_SEVERITY_SUCCESS          0x0
#define STATUS_SEVERITY_INFORMATIONAL    0x1
#define STATUS_SEVERITY_ERROR            0x3


//
// MessageId: PCI_PRE_20
//
// MessageText:
//
//  PCI Device
//
#define PCI_PRE_20                       ((ULONG)0x00000000L)

//
// MessageId: PCI_PRE_20_VGA
//
// MessageText:
//
//  VGA Device
//
#define PCI_PRE_20_VGA                   ((ULONG)0x00000001L)

//
// MessageId: PCI_SCSI_BUS
//
// MessageText:
//
//  SCSI Controller
//
#define PCI_SCSI_BUS                     ((ULONG)0x00000100L)

//
// MessageId: PCI_IDE_CTLR
//
// MessageText:
//
//  IDE Controller
//
#define PCI_IDE_CTLR                     ((ULONG)0x00000101L)

//
// MessageId: PCI_FLOPPY
//
// MessageText:
//
//  Floppy Controller
//
#define PCI_FLOPPY                       ((ULONG)0x00000102L)

//
// MessageId: PCI_IPI_CTLR
//
// MessageText:
//
//  IPI Controller
//
#define PCI_IPI_CTLR                     ((ULONG)0x00000103L)

//
// MessageId: PCI_RAID_CTLR
//
// MessageText:
//
//  RAID Controller
//
#define PCI_RAID_CTLR                    ((ULONG)0x00000104L)

//
// MessageId: PCI_MSC_OTHER
//
// MessageText:
//
//  Mass Storage Controller
//
#define PCI_MSC_OTHER                    ((ULONG)0x00000180L)

//
// MessageId: PCI_ENET
//
// MessageText:
//
//  Ethernet Controller
//
#define PCI_ENET                         ((ULONG)0x00000200L)

//
// MessageId: PCI_TOKEN_RING
//
// MessageText:
//
//  Token Ring Network Controller
//
#define PCI_TOKEN_RING                   ((ULONG)0x00000201L)

//
// MessageId: PCI_FDDI
//
// MessageText:
//
//  FDDI Network Controller
//
#define PCI_FDDI                         ((ULONG)0x00000202L)

//
// MessageId: PCI_ATM
//
// MessageText:
//
//  ATM Network Controller
//
#define PCI_ATM                          ((ULONG)0x00000203L)

//
// MessageId: PCI_ISDN
//
// MessageText:
//
//  ISDN Controller
//
#define PCI_ISDN                         ((ULONG)0x00000204L)

//
// MessageId: PCI_NET_CTLR
//
// MessageText:
//
//  Network Controller
//
#define PCI_NET_CTLR                     ((ULONG)0x00000280L)

//
// MessageId: PCI_VGA
//
// MessageText:
//
//  Video Controller (VGA Compatible)
//
#define PCI_VGA                          ((ULONG)0x00000300L)

//  XGA confuses people - this is VGA compatible as well
//
// MessageId: PCI_XGA
//
// MessageText:
//
//  Video Controller (VGA Compatible)
//
#define PCI_XGA                          ((ULONG)0x00000301L)

//
// MessageId: PCI_3D_CTLR
//
// MessageText:
//
//  3D Video Controller
//
#define PCI_3D_CTLR                      ((ULONG)0x00000302L)

//
// MessageId: PCI_VID_OTHER
//
// MessageText:
//
//  Video Controller
//
#define PCI_VID_OTHER                    ((ULONG)0x00000380L)

//
// MessageId: PCI_MM_VIDEO
//
// MessageText:
//
//  Multimedia Video Controller
//
#define PCI_MM_VIDEO                     ((ULONG)0x00000400L)

//
// MessageId: PCI_MM_AUDIO
//
// MessageText:
//
//  Multimedia Audio Controller
//
#define PCI_MM_AUDIO                     ((ULONG)0x00000401L)

//
// MessageId: PCI_MM_TELEPHONY
//
// MessageText:
//
//  Computer Telephony Device
//
#define PCI_MM_TELEPHONY                 ((ULONG)0x00000402L)

//
// MessageId: PCI_MM_OTHER
//
// MessageText:
//
//  Multimedia Controller
//
#define PCI_MM_OTHER                     ((ULONG)0x00000480L)

//
// MessageId: PCI_MEM_RAM
//
// MessageText:
//
//  PCI Memory
//
#define PCI_MEM_RAM                      ((ULONG)0x00000500L)

//
// MessageId: PCI_MEM_FLASH
//
// MessageText:
//
//  PCI FLASH Memory
//
#define PCI_MEM_FLASH                    ((ULONG)0x00000501L)

//
// MessageId: PCI_MEM_OTHER
//
// MessageText:
//
//  PCI Memory Controller
//
#define PCI_MEM_OTHER                    ((ULONG)0x00000580L)

//
// MessageId: PCI_BR_HOST
//
// MessageText:
//
//  PCI HOST Bridge
//
#define PCI_BR_HOST                      ((ULONG)0x00000600L)

//
// MessageId: PCI_BR_ISA
//
// MessageText:
//
//  PCI to ISA Bridge
//
#define PCI_BR_ISA                       ((ULONG)0x00000601L)

//
// MessageId: PCI_BR_EISA
//
// MessageText:
//
//  PCI to EISA Bridge
//
#define PCI_BR_EISA                      ((ULONG)0x00000602L)

//
// MessageId: PCI_BR_MCA
//
// MessageText:
//
//  PCI to Micro Channel Bridge
//
#define PCI_BR_MCA                       ((ULONG)0x00000603L)

//
// MessageId: PCI_BR_PCI
//
// MessageText:
//
//  PCI to PCI Bridge
//
#define PCI_BR_PCI                       ((ULONG)0x00000604L)

//
// MessageId: PCI_BR_PCMCIA
//
// MessageText:
//
//  PCI to PCMCIA Bridge
//
#define PCI_BR_PCMCIA                    ((ULONG)0x00000605L)

//
// MessageId: PCI_BR_NUBUS
//
// MessageText:
//
//  PCI to NUBUS Bridge
//
#define PCI_BR_NUBUS                     ((ULONG)0x00000606L)

//
// MessageId: PCI_BR_CARDBUS
//
// MessageText:
//
//  PCI to CARDBUS Bridge
//
#define PCI_BR_CARDBUS                   ((ULONG)0x00000607L)

//
// MessageId: PCI_BR_RACEWAY
//
// MessageText:
//
//  PCI to RACEway Bridge
//
#define PCI_BR_RACEWAY                   ((ULONG)0x00000608L)

//
// MessageId: PCI_BR_OTHER
//
// MessageText:
//
//  Other PCI Bridge Device
//
#define PCI_BR_OTHER                     ((ULONG)0x00000680L)

//
// MessageId: PCI_COM_SERIAL
//
// MessageText:
//
//  PCI Serial Port
//
#define PCI_COM_SERIAL                   ((ULONG)0x00000700L)

//
// MessageId: PCI_COM_PARALLEL
//
// MessageText:
//
//  PCI Parallel Port
//
#define PCI_COM_PARALLEL                 ((ULONG)0x00000701L)

//
// MessageId: PCI_COM_MULTIPORT
//
// MessageText:
//
//  PCI Multiport Serial Controller
//
#define PCI_COM_MULTIPORT                ((ULONG)0x00000702L)

//
// MessageId: PCI_COM_MODEM
//
// MessageText:
//
//  PCI Modem
//
#define PCI_COM_MODEM                    ((ULONG)0x00000703L)

//
// MessageId: PCI_COM_OTHER
//
// MessageText:
//
//  PCI Simple Communications Controller
//
#define PCI_COM_OTHER                    ((ULONG)0x00000780L)

//
// MessageId: PCI_SYS_INT
//
// MessageText:
//
//  System Interrupt Controller
//
#define PCI_SYS_INT                      ((ULONG)0x00000800L)

//
// MessageId: PCI_SYS_DMA
//
// MessageText:
//
//  System DMA Controller
//
#define PCI_SYS_DMA                      ((ULONG)0x00000801L)

//
// MessageId: PCI_SYS_TIMER
//
// MessageText:
//
//  System Timer
//
#define PCI_SYS_TIMER                    ((ULONG)0x00000802L)

//
// MessageId: PCI_SYS_RTC
//
// MessageText:
//
//  Real Time Clock
//
#define PCI_SYS_RTC                      ((ULONG)0x00000803L)

//
// MessageId: PCI_SYS_HOTPLUG_CTLR
//
// MessageText:
//
//  Generic PCI Hot-Plug Controller
//
#define PCI_SYS_HOTPLUG_CTLR             ((ULONG)0x00000804L)

//
// MessageId: PCI_SYS_OTHER
//
// MessageText:
//
//  Base System Device
//
#define PCI_SYS_OTHER                    ((ULONG)0x00000880L)

//
// MessageId: PCI_INP_KBD
//
// MessageText:
//
//  PCI Keyboard Controller
//
#define PCI_INP_KBD                      ((ULONG)0x00000900L)

//
// MessageId: PCI_INP_DIGITIZER
//
// MessageText:
//
//  PCI Digitizer
//
#define PCI_INP_DIGITIZER                ((ULONG)0x00000901L)

//
// MessageId: PCI_INP_MOUSE
//
// MessageText:
//
//  PCI Mouse Controller
//
#define PCI_INP_MOUSE                    ((ULONG)0x00000902L)

//
// MessageId: PCI_INP_SCANNER
//
// MessageText:
//
//  PCI Scanner Controller
//
#define PCI_INP_SCANNER                  ((ULONG)0x00000903L)

//
// MessageId: PCI_INP_GAMEPORT
//
// MessageText:
//
//  PCI Gameport Controller
//
#define PCI_INP_GAMEPORT                 ((ULONG)0x00000904L)

//
// MessageId: PCI_INP_OTHER
//
// MessageText:
//
//  PCI Input Device
//
#define PCI_INP_OTHER                    ((ULONG)0x00000980L)

//
// MessageId: PCI_DOC_GENERIC
//
// MessageText:
//
//  Docking Station
//
#define PCI_DOC_GENERIC                  ((ULONG)0x00000A00L)

//
// MessageId: PCI_DOC_OTHER
//
// MessageText:
//
//  Docking Station (Unknown type)
//
#define PCI_DOC_OTHER                    ((ULONG)0x00000A80L)

//
// MessageId: PCI_PROC_386
//
// MessageText:
//
//  386 Processor
//
#define PCI_PROC_386                     ((ULONG)0x00000B00L)

//
// MessageId: PCI_PROC_486
//
// MessageText:
//
//  486 Processor
//
#define PCI_PROC_486                     ((ULONG)0x00000B01L)

//
// MessageId: PCI_PROC_PENTIUM
//
// MessageText:
//
//  Pentium Processor
//
#define PCI_PROC_PENTIUM                 ((ULONG)0x00000B02L)

//
// MessageId: PCI_PROC_ALPHA
//
// MessageText:
//
//  ALPHA Processor
//
#define PCI_PROC_ALPHA                   ((ULONG)0x00000B10L)

//
// MessageId: PCI_PROC_POWERPC
//
// MessageText:
//
//  PowerPC Processor
//
#define PCI_PROC_POWERPC                 ((ULONG)0x00000B20L)

//
// MessageId: PCI_PROC_OTHER
//
// MessageText:
//
//  Coprocessor
//
#define PCI_PROC_OTHER                   ((ULONG)0x00000B40L)

//
// MessageId: PCI_SB_1394
//
// MessageText:
//
//  IEEE 1394 Controller
//
#define PCI_SB_1394                      ((ULONG)0x00000C00L)

//
// MessageId: PCI_SB_ACCESS
//
// MessageText:
//
//  ACCESS Bus Controller
//
#define PCI_SB_ACCESS                    ((ULONG)0x00000C01L)

//
// MessageId: PCI_SB_SSA
//
// MessageText:
//
//  SSA Controller
//
#define PCI_SB_SSA                       ((ULONG)0x00000C02L)

//
// MessageId: PCI_SB_USB
//
// MessageText:
//
//  Universal Serial Bus (USB) Controller
//
#define PCI_SB_USB                       ((ULONG)0x00000C03L)

//
// MessageId: PCI_SB_FIBRE
//
// MessageText:
//
//  Fibre Channel Controller
//
#define PCI_SB_FIBRE                     ((ULONG)0x00000C04L)

//
// MessageId: PCI_SB_SMBUS
//
// MessageText:
//
//  SM Bus Controller
//
#define PCI_SB_SMBUS                     ((ULONG)0x00000C05L)

//
// MessageId: PCI_WIRELESS_IRDA
//
// MessageText:
//
//  iRDA Compatible Controller
//
#define PCI_WIRELESS_IRDA                ((ULONG)0x00000D00L)

//
// MessageId: PCI_WIRELESS_CON_IR
//
// MessageText:
//
//  Consumer IR Controller
//
#define PCI_WIRELESS_CON_IR              ((ULONG)0x00000D01L)

//
// MessageId: PCI_WIRELESS_RF
//
// MessageText:
//
//  RF Controller
//
#define PCI_WIRELESS_RF                  ((ULONG)0x00000D10L)

//
// MessageId: PCI_WIRELESS_CONTROLLER
//
// MessageText:
//
//  PCI Wireless Controller
//
#define PCI_WIRELESS_CONTROLLER          ((ULONG)0x00000D80L)

//
// MessageId: PCI_INTIO_I20
//
// MessageText:
//
//  Intelligent I/O (I2O) Controller
//
#define PCI_INTIO_I20                    ((ULONG)0x00000E00L)

//
// MessageId: PCI_SAT_TV
//
// MessageText:
//
//  Satellite Communications Television Controller
//
#define PCI_SAT_TV                       ((ULONG)0x00000F01L)

//
// MessageId: PCI_SAT_AUDIO
//
// MessageText:
//
//  Satellite Communications Audio Controller
//
#define PCI_SAT_AUDIO                    ((ULONG)0x00000F02L)

//
// MessageId: PCI_SAT_VOICE
//
// MessageText:
//
//  Satellite Communications Voice Controller
//
#define PCI_SAT_VOICE                    ((ULONG)0x00000F03L)

//
// MessageId: PCI_SAT_Data
//
// MessageText:
//
//  Satellite Communications Data Controller
//
#define PCI_SAT_Data                     ((ULONG)0x00000F04L)

//
// MessageId: PCI_CRYPTO_NET_COMP
//
// MessageText:
//
//  Network and Computing Encryption/Decryption Controller
//
#define PCI_CRYPTO_NET_COMP              ((ULONG)0x00001000L)

//
// MessageId: PCI_CRYPTO_ENTERTAINMENT
//
// MessageText:
//
//  Entertainment Encryption/Decryption Controller
//
#define PCI_CRYPTO_ENTERTAINMENT         ((ULONG)0x00001010L)

//
// MessageId: PCI_CRYPTO_OTHER
//
// MessageText:
//
//  PCI Encryption/Decryption Controller
//
#define PCI_CRYPTO_OTHER                 ((ULONG)0x00001080L)

//
// MessageId: PCI_DASP_DPIO
//
// MessageText:
//
//  DPIO Module
//
#define PCI_DASP_DPIO                    ((ULONG)0x00001100L)

//
// MessageId: PCI_DASP_CONTROLLER
//
// MessageText:
//
//  PCI Data Acquisition and Signal Processing Controller
//
#define PCI_DASP_CONTROLLER              ((ULONG)0x00001180L)

//
// MessageId: PCI_LOCATION_TEXT
//
// MessageText:
//
//  PCI bus %u, device %u, function %u
//
#define PCI_LOCATION_TEXT                ((ULONG)0x00010000L)

