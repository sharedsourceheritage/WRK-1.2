/***
*wcslen_s.c - contains wcsnlen() routine
*
*   Copyright (c) Microsoft Corporation. All rights reserved.
*
*Purpose:
*   wcslen returns the length of a null-terminated wide-character string,
*   not including the null wchar_t itself.
*
*Revision History:
*   10-08-03  AC    Module created.
*   03-08-04  AC    Change the name to wcsnlen.
*
*******************************************************************************/

#ifndef _POSIX_

#include <cruntime.h>
#include <string.h>

/***
*wcsnlen - return the length of a null-terminated wide-character string
*
*Purpose:
*   Finds the length in bytes of the given string, not including
*   the final null character. Only the first maxsize characters
*   are inspected: if the null character is not found, maxsize is
*   returned.
*
*Entry:
*   const wchar_t * wcs - string whose length is to be computed
*   size_t maxsize
*
*Exit:
*   Length of the string "wcs", exclusive of the final null byte, or
*   maxsize if the null character is not found.
*
*Exceptions:
*
*******************************************************************************/

size_t __cdecl wcsnlen(const wchar_t *wcs, size_t maxsize)
{
    size_t n;

    /* Note that we do not check if s == NULL, because we do not
     * return errno_t...
     */

    for (n = 0; n < maxsize && *wcs; n++, wcs++)
        ;

    return n;
}

#endif /* _POSIX_ */
