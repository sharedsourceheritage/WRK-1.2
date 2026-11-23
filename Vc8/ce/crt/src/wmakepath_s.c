/***
*wmakepath_s.c - create path name from components
*
*   Copyright (c) Microsoft Corporation. All rights reserved.
*
*Purpose:
*   To provide support for creation of full path names from components
*
*Revision History:
*   08-05-04  AC    Created from makepath.c and tmakepath_s.inl
*
*******************************************************************************/

#include <stdlib.h>
#ifndef _WIN32_WCE
#include <mbstring.h>
#endif /* _WIN32_WCE */
#include <internal_securecrt.h>

#define _FUNC_PROLOGUE
#define _FUNC_NAME _wmakepath_s
#define _CHAR wchar_t
#define _DEST _Dst
#define _SIZE _SizeInWords
#ifndef _WIN32_WCE
#define _T(_Character) L##_Character
#endif /* _WIN32_WCE */
#define _MBS_SUPPORT 0

#include <tmakepath_s.inl>
