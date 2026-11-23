/***
*wcsncpy_s.c - copy at most n characters of wide-character string
*
*   Copyright (c) Microsoft Corporation. All rights reserved.
*
*Purpose:
*   defines wcsncpy_s() - copy at most n characters of wchar_t string
*
*Revision History:
*   09-09-91  AC    Module created.
*   08-03-04  AC    Moved the implementation in tcsncpy.inl.
*
*******************************************************************************/

#ifndef _POSIX_

#include <string.h>
#include <internal_securecrt.h>

#define _FUNC_PROLOGUE
#define _FUNC_NAME wcsncpy_s
#define _CHAR wchar_t
#define _DEST _Dst
#define _SIZE _SizeInWords
#define _SRC _Src
#define _COUNT _Count

#include <tcsncpy_s.inl>

#ifdef _WIN32_WCE
#define _NANSI
#endif /* _WIN32_WCE */

#endif /* _POSIX_ */
