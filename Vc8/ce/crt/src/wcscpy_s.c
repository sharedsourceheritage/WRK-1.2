/***
*strcpy_s.c - contains wcscpy_s()
*
*   Copyright (c) Microsoft Corporation. All rights reserved.
*
*Purpose:
*   wcscpy_s() copies one string onto another.
*
*Revision History:
*   08-03-04   AC   Created from strcpy_s.
*
*******************************************************************************/

#ifndef _POSIX_

#include <string.h>
#include <internal_securecrt.h>

#define _FUNC_PROLOGUE
#define _FUNC_NAME wcscpy_s
#define _CHAR wchar_t
#define _DEST _Dst
#define _SIZE _SizeInWords
#define _SRC _Src

#include <tcscpy_s.inl>

#endif /* _POSIX_ */
