/***
*wsplitpath_s.c - break down path name into components
*
*   Copyright (c) Microsoft Corporation. All rights reserved.
*
*Purpose:
*   To provide support for accessing the individual components of an
*   arbitrary path name
*
*Revision History:
*   08-05-04  AC    Created from splitpath.c and tsplitpath_s.inl
*   08-12-04  AC    Clean up
*
*******************************************************************************/

#include <stdlib.h>
#ifndef _WIN32_WCE
#include <mbstring.h>
#endif /* _WIN32_WCE */
#include <internal_securecrt.h>

#define _FUNC_PROLOGUE
#define _FUNC_NAME _wsplitpath_s
#define _CHAR wchar_t
#define _TCSNCPY_S wcsncpy_s
#ifndef _WIN32_WCE
#define _T(_Character) L##_Character
#endif /* _WIN32_WCE */
#define _MBS_SUPPORT 0

#include <tsplitpath_s.inl>
