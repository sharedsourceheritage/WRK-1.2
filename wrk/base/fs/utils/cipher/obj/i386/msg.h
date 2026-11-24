/*++ BUILD Version: 0001    // Increment this if a change has global effects

Copyright (c) 1997-1999  Microsoft Corporation

Module Name:

    msg.h

Abstract:

    This file contains the message definitions for the Win32 Crypt
    utility.

Author:

    Robert Reichel        [RobertRe]        01-Apr-1997
    Robert Gu             [RobertG]         24-Mar-1998

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
// MessageId: CIPHER_OK
//
// MessageText:
//
//  [OK]
//
#define CIPHER_OK                        0x00000001L

//
// MessageId: CIPHER_ERR
//
// MessageText:
//
//  [ERR]
//
#define CIPHER_ERR                       0x00000002L

//
// MessageId: CIPHER_ENCRYPT_SUMMARY_NF
//
// MessageText:
//
//  
//  %1 directorie(s) within %2 directorie(s) were encrypted.
//  
//
#define CIPHER_ENCRYPT_SUMMARY_NF        0x00000003L

//
// MessageId: CIPHER_DECRYPT_SUMMARY_NF
//
// MessageText:
//
//  
//  %1 directorie(s) within %2 directorie(s) were decrypted.
//  
//
#define CIPHER_DECRYPT_SUMMARY_NF        0x00000004L

//
// MessageId: CIPHER_LIST_EDIR
//
// MessageText:
//
//  
//   Listing %1
//   New files added to this directory will be encrypted.
//  
//
#define CIPHER_LIST_EDIR                 0x00000006L

//
// MessageId: CIPHER_LIST_UDIR
//
// MessageText:
//
//  
//   Listing %1
//   New files added to this directory will not be encrypted.
//  
//
#define CIPHER_LIST_UDIR                 0x00000007L

//
// MessageId: CIPHER_LIST_SUMMARY
//
// MessageText:
//
//  
//  Of %1 file(s) within %2 directorie(s)
//  %3 are encrypted and %4 are not encrypted.
//  
//
#define CIPHER_LIST_SUMMARY              0x00000008L

//
// MessageId: CIPHER_ENCRYPT_DIR
//
// MessageText:
//
//  
//   Setting the directory %1 to encrypt new files %0
//  
//
#define CIPHER_ENCRYPT_DIR               0x00000009L

//
// MessageId: CIPHER_ENCRYPT_EDIR
//
// MessageText:
//
//  
//   Encrypting files in %1
//  
//
#define CIPHER_ENCRYPT_EDIR              0x0000000AL

//
// MessageId: CIPHER_ENCRYPT_UDIR
//
// MessageText:
//
//  
//   Encrypting files in %1
//  
//
#define CIPHER_ENCRYPT_UDIR              0x0000000BL

//
// MessageId: CIPHER_ENCRYPT_EDIR_NF
//
// MessageText:
//
//  
//   Encrypting directories in %1
//  
//
#define CIPHER_ENCRYPT_EDIR_NF           0x0000000CL

//
// MessageId: CIPHER_ENCRYPT_UDIR_NF
//
// MessageText:
//
//  
//   Encrypting directories in %1
//  
//
#define CIPHER_ENCRYPT_UDIR_NF           0x0000000DL

//
// MessageId: CIPHER_ENCRYPT_SUMMARY
//
// MessageText:
//
//  
//  %1 file(s) [or directorie(s)] within %2 directorie(s) were encrypted.
//  
//
#define CIPHER_ENCRYPT_SUMMARY           0x0000000EL

//
// MessageId: CIPHER_DECRYPT_DIR
//
// MessageText:
//
//  
//   Setting the directory %1 not to encrypt new files %0
//  
//
#define CIPHER_DECRYPT_DIR               0x0000000FL

//
// MessageId: CIPHER_DECRYPT_EDIR
//
// MessageText:
//
//  
//   Decrypting files in %1
//  
//
#define CIPHER_DECRYPT_EDIR              0x00000010L

//
// MessageId: CIPHER_DECRYPT_UDIR
//
// MessageText:
//
//  
//   Decrypting files in %1
//  
//
#define CIPHER_DECRYPT_UDIR              0x00000011L

//
// MessageId: CIPHER_DECRYPT_EDIR_NF
//
// MessageText:
//
//  
//   Decrypting directories in %1
//  
//
#define CIPHER_DECRYPT_EDIR_NF           0x00000012L

//
// MessageId: CIPHER_DECRYPT_UDIR_NF
//
// MessageText:
//
//  
//   Decrypting directories in %1
//  
//
#define CIPHER_DECRYPT_UDIR_NF           0x00000013L

//
// MessageId: CIPHER_DECRYPT_SUMMARY
//
// MessageText:
//
//  
//  %1 file(s) [or directorie(s)] within %2 directorie(s) were decrypted.
//  
//
#define CIPHER_DECRYPT_SUMMARY           0x00000014L

//
// MessageId: CIPHER_NO_MEMORY
//
// MessageText:
//
//  Out of memory.
//
#define CIPHER_NO_MEMORY                 0x00000015L

//
// MessageId: CIPHER_SKIPPING
//
// MessageText:
//
//  [Skipping %1]
//
#define CIPHER_SKIPPING                  0x00000016L

//
// MessageId: CIPHER_THROW
//
// MessageText:
//
//  %1%0
//
#define CIPHER_THROW                     0x00000017L

//
// MessageId: CIPHER_THROW_NL
//
// MessageText:
//
//  %1
//
#define CIPHER_THROW_NL                  0x00000018L

//
// MessageId: CIPHER_WRONG_FILE_SYSTEM
//
// MessageText:
//
//  %1: The file system does not support encryption.
//
#define CIPHER_WRONG_FILE_SYSTEM         0x00000019L

//
// MessageId: CIPHER_TO_ONE
//
// MessageText:
//
//  to 1 %0
//
#define CIPHER_TO_ONE                    0x0000001AL

//
// MessageId: CIPHER_INVALID_PATH
//
// MessageText:
//
//  Invalid drive specification: %1
//
#define CIPHER_INVALID_PATH              0x0000001BL

//
// MessageId: CIPHER_NETWORK_FILE
//
// MessageText:
//
//  Encryption of network files is not supported: %1
//
#define CIPHER_NETWORK_FILE              0x0000001CL

//
// MessageId: CIPHER_NETWORK_FILE_NF
//
// MessageText:
//
//  Encryption of network directories is not supported: %1
//
#define CIPHER_NETWORK_FILE_NF           0x0000001DL

//
// MessageId: CIPHER_INVALID_PARAMETER
//
// MessageText:
//
//  Invalid Parameter: %1
//
#define CIPHER_INVALID_PARAMETER         0x0000001EL

//
// MessageId: CIPHER_CURRENT_CERT
//
// MessageText:
//
//  
//  Your new file encryption certificate thumbprint information on the PC named %1 is:
//   
//    %2
//      
//
#define CIPHER_CURRENT_CERT              0x0000001FL

//
// MessageId: CIPHER_ENCRYPTED_FILES
//
// MessageText:
//
//  
//  Encrypted File(s) on your system:
//  
//
#define CIPHER_ENCRYPTED_FILES           0x00000020L

//
// MessageId: CIPHER_TOUCH_OK
//
// MessageText:
//
//  %1: Encryption updated.
//  
//
#define CIPHER_TOUCH_OK                  0x00000021L

//
// MessageId: CIPHER_USE_W
//
// MessageText:
//
//  Converting files from plaintext to ciphertext may leave sections of old
//  plaintext on the disk volume(s). It is recommended to use command
//  CIPHER /W:directory to clean up the disk after all converting is done.
//
#define CIPHER_USE_W                     0x00000022L

//
// MessageId: CIPHER_PROMPT_PASSWORD
//
// MessageText:
//
//  Please type in the password to protect your .PFX file:
//
#define CIPHER_PROMPT_PASSWORD           0x00000023L

//
// MessageId: CIPHER_CONFIRM_PASSWORD
//
// MessageText:
//
//  Please retype the password to confirm:
//
#define CIPHER_CONFIRM_PASSWORD          0x00000024L

//
// MessageId: CIPHER_PASSWORD_NOMATCH
//
// MessageText:
//
//  Passwords do not match. No certificate is generated.
//
#define CIPHER_PASSWORD_NOMATCH          0x00000025L

//
// MessageId: CIPHER_FILE_EXISTS
//
// MessageText:
//
//  Overwrite %1? (Yes/No):
//
#define CIPHER_FILE_EXISTS               0x00000026L

//
// MessageId: CIPHER_YESNOANSWER
//
// MessageText:
//
//  YN
//
#define CIPHER_YESNOANSWER               0x00000027L

//
// MessageId: CIPHER_CER_CREATED
//
// MessageText:
//
//  Your .CER file was created successfully.
//
#define CIPHER_CER_CREATED               0x00000028L

//
// MessageId: CIPHER_PFX_CREATED
//
// MessageText:
//
//  Your .PFX file was created successfully.
//
#define CIPHER_PFX_CREATED               0x00000029L

//
// MessageId: CIPHER_WIPE_PROGRESS
//
// MessageText:
//
//  Writing %1
//
#define CIPHER_WIPE_PROGRESS             0x0000002AL

//
// MessageId: CIPHER_WIPE_WARNING
//
// MessageText:
//
//  To remove as much data as possible, please close all other applications while
//  running CIPHER /W.
//
#define CIPHER_WIPE_WARNING              0x0000002BL

//
// MessageId: CIPHER_WRITE_ZERO
//
// MessageText:
//
//  0x00
//
#define CIPHER_WRITE_ZERO                0x0000002CL

//
// MessageId: CIPHER_WRITE_FF
//
// MessageText:
//
//  0xFF
//
#define CIPHER_WRITE_FF                  0x0000002DL

//
// MessageId: CIPHER_WRITE_RANDOM
//
// MessageText:
//
//  Random Numbers
//
#define CIPHER_WRITE_RANDOM              0x0000002EL

//
// MessageId: CIPHER_NO_LOCAL_CERT
//
// MessageText:
//
//  There is no local EFS certificate that is used to encrypt this file. No
//  local EFS certificate is backed up.  
//
#define CIPHER_NO_LOCAL_CERT             0x0000002FL

//
// MessageId: CIPHER_NO_CRT_LOCAL_CERT
//
// MessageText:
//
//  There is no local current EFS certificate to be backed up.  
//
#define CIPHER_NO_CRT_LOCAL_CERT         0x00000030L

//
// MessageId: CIPHER_BACKUP_OK
//
// MessageText:
//
//  Your certificates and the corresponding keys are being backed up. If you didn't start the process, press CANCEL. Press OK to confirm.
//
#define CIPHER_BACKUP_OK                 0x00000031L

//
// MessageId: CIPHER_CERTS_BACKED
//
// MessageText:
//
//  EFS certificate(s) is(are) backed up successfully.  
//
#define CIPHER_CERTS_BACKED              0x00000032L

//
// MessageId: CIPHER_CERTS_BACKUP_FAILED
//
// MessageText:
//
//  EFS certificate backup failed.
//
#define CIPHER_CERTS_BACKUP_FAILED       0x00000033L

//
// MessageId: CIPHER_BACKUP_WRN
//
// MessageText:
//
//  EFS certificate and key backup.
//
#define CIPHER_BACKUP_WRN                0x00000034L

//
// MessageId: CIPHER_PFX_FILENAME_NEEDED
//
// MessageText:
//
//  Please type the backup PFX file name.  
//
#define CIPHER_PFX_FILENAME_NEEDED       0x00000035L

//
// MessageId: CIPHER_PFX_FILENAME_TOO_LONG
//
// MessageText:
//
//  Output PFX file path too long. Make it shorter and try again.  
//
#define CIPHER_PFX_FILENAME_TOO_LONG     0x00000036L

//
// MessageId: CIPHER_USAGE
//
// MessageText:
//
//  Displays or alters the encryption of directories [files] on NTFS partitions.
//  
//    CIPHER [/E | /D] [/S:directory] [/A] [/I] [/F] [/Q] [/H] [pathname [...]]
//    
//    CIPHER /K
//    
//    CIPHER /R:filename
//    
//    CIPHER /U [/N]
//    
//    CIPHER /W:directory
//    
//    CIPHER /X[:efsfile] [filename]
//      
//      /A        Operates on files as well as directories. The encrypted file 
//                could become decrypted when it is modified if the parent 
//                directory is not encrypted. It is recommended that you encrypt
//                the file and the parent directory.
//      /D        Decrypts the specified directories. Directories will be marked
//                so that files added afterward will not be encrypted.
//      /E        Encrypts the specified directories. Directories will be marked
//                so that files added afterward will be encrypted.
//      /F        Forces the encryption operation on all specified objects, even
//                those which are already encrypted.  Already-encrypted objects
//                are skipped by default.
//      /H        Displays files with the hidden or system attributes.  These
//                files are omitted by default.
//      /I        Continues performing the specified operation even after errors
//                have occurred.  By default, CIPHER stops when an error is
//                encountered.
//      /K        Creates new file encryption key for the user running CIPHER. If
//                this option is chosen, all the other options will be ignored.
//      /N        This option only works with /U. This will prevent keys being
//                updated. This is used to find all the encrypted files on the 
//                local drives.
//      /Q        Reports only the most essential information.
//      /R        Generates an EFS recovery agent key and certificate, then writes
//                them to a .PFX file (containing certificate and private key) and 
//                a .CER file (containing only the certificate). An administrator
//                may add the contents of the .CER to the EFS recovery policy to 
//                create the recovery agent for users, and import the .PFX to 
//                recover individual files.
//      /S        Performs the specified operation on directories in the given
//                directory and all subdirectories.
//      /U        Tries to touch all the encrypted files on local drives. This will
//                update user's file encryption key or recovery agent's key to the
//                current ones if they are changed. This option does not work with
//                other options except /N.
//      /W        Removes data from available unused disk space on the entire 
//                volume. If this option is chosen, all other options are ignored.
//                The directory specified can be anywhere in a local volume. If it 
//                is a mount point or points to a directory in another volume, the
//                data on that volume will be removed.
//      /X        Backup EFS certificate and keys into file filename. If efsfile is
//                provided, the current user's certificate(s) used to encrypt the
//                file will be backed up. Otherwise, the user's current EFS 
//                certificate and keys will be backed up.
//      
//      
//      directory A directory path.
//      filename  A filename without extensions.
//      pathname  Specifies a pattern, file or directory.
//      efsfile   An encrypted file path.
//  
//      Used without parameters, CIPHER displays the encryption state of
//      the current directory and any files it contains. You may use multiple
//      directory names and wildcards.  You must put spaces between multiple
//      parameters.
//
#define CIPHER_USAGE                     0x0000005AL

