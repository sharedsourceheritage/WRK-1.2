/***
*wcscat_s.c - contains wcscat_s()
*
*   Copyright (c) Microsoft Corporation. All rights reserved.
*
*Purpose:
*   wcscat_s() appends one wchar_t string onto another.
*
*   wcscat() concatenates (appends) a copy of the source string to the
*   end of the destination string.
*   Strings are wide-character strings.
*
*Revision History:
*   10-10-03  AC    Module created.
*   03-10-04  AC    Return ERANGE when buffer is too small
*   08-03-04  AC    Moved the implementation in tcscat.inl and tcscpy.inl.
*                   Split wcscat_s and wcscpy_s.
*
*******************************************************************************/

#ifndef _POSIX_

#include <string.h>
#include <internal_securecrt.h>

#define _FUNC_PROLOGUE
#define _FUNC_NAME wcscat_s
#define _CHAR wchar_t
#define _DEST _Dst
#define _SIZE _SizeInWords
#define _SRC _Src

#include <tcscat_s.inl>

#endif /* _POSIX_ */
