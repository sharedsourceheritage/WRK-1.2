/***
*strncpy_s.c - copy at most n characters of string
*
*   Copyright (c) Microsoft Corporation. All rights reserved.
*
*Purpose:
*   defines strncpy_s() - copy at most n characters of string
*
*Revision History:
*   10-10-03    AC  Module created.
*   03-10-04    AC  Return ERANGE when buffer is too small.
*   03-29-04    AC  The case dest == NULL && sizeInTChars == 0 && count == 0 is allowed.
*                   VSW#239396
*   08-03-04    AC  Moved the implementation in tcsncpy.inl.
*
*******************************************************************************/

#if defined(_WIN32_WCE) && !defined(_NANSI)

// For CE the build is Unicode by default, so it has to be explicity turned off to build ANSI.
#ifdef _UNICODE
#undef _UNICODE
#endif
#ifdef UNICODE
#undef UNICODE
#endif

#endif

#include <string.h>
#include <internal_securecrt.h>

#define _FUNC_PROLOGUE
#define _FUNC_NAME strncpy_s
#define _CHAR char
#define _DEST _Dst
#define _SIZE _SizeInBytes
#define _SRC _Src
#define _COUNT _Count

#include <tcsncpy_s.inl>
