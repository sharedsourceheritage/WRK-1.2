/***
*strcat_s.c - contains strcat_s()
*
*   Copyright (c) Microsoft Corporation. All rights reserved.
*
*Purpose:
*   strcat_s() concatenates (appends) a copy of the source string to the
*   end of the destination string.
*
*Revision History:
*   10-10-03   AC   Module created.
*   03-10-04   AC   Return ERANGE when buffer is too small
*   08-03-04   AC   Moved the implementation in tcscat.inl and tcscpy.inl.
*                   Split strcat_s and strcpy_s.
*
*******************************************************************************/

#include <string.h>
#include <internal_securecrt.h>

#define _FUNC_PROLOGUE
#define _FUNC_NAME strcat_s
#define _CHAR char
#define _DEST _Dst
#define _SIZE _SizeInBytes
#define _SRC _Src

#include <tcscat_s.inl>
