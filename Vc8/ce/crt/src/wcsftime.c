/***
*wcsftime.c - String Format Time
*
*       Copyright (c) Microsoft Corporation. All rights reserved.
*
*Purpose:
*
*Revision History:
*       03-08-93  CFW   Module Created.
*       03-10-93  CFW   Fixed up properly.
*       04-06-93  SKS   Replace _CRTAPI* with __cdecl
*       02-07-94  CFW   POSIXify.
*       12-16-94  CFW   Format must be wchar_t!
*       01-10-95  CFW   Debug CRT allocs.
*       08-27-98  GJF   Revised multithread support based on threadlocinfo
*                       struct. Also, use _alloca rather than malloc/free, 
*                       when possible.
*       01-06-99  GJF   Changes for 64-bit size_t.
*       12-10-99  GB    Added support for recovery from stack overflow around 
*                       _alloca().
*       11-12-01  GB    Added support for new locale implementation.
*       12-11-01  BWT   Replace _getptd with _getptd_noexit - we can return 0/ENOMEM
*                       here instead of exiting.
*       03-23-03  SSM   VSWhidbey 173165. wcslen was being called before the 
*                       the buffer was validated for NULL in wcsftime.
*       09-25-04  JL    Replace usage of _alloca() with _alloca_s() / _freea_s()
*       03-14-05  PAL   Set errno=ERANGE if appropriate. (VSW 435529)
*       04-04-05  JL    Replace _alloca_s and _freea_s with _malloca and _freea
*       04-01-05  MSL   Integer overflow protection
*
*******************************************************************************/

#ifndef _POSIX_

#include <cruntime.h>
#include <internal.h>
#include <mtdll.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>
#include <time.h>
#include <dbgint.h>
#include <malloc.h>
#include <excpt.h>
#include <errno.h>
#include <locale.h>
#include <setlocal.h>

#ifndef _WIN32_WCE
extern "C" 
#endif /* _WIN32_WCE */
size_t __cdecl _Strftime_l (char *string, size_t maxsize, const char *format,
        const struct tm *timeptr, void *lc_time_arg
#ifndef _WIN32_WCE
	, _locale_t plocinfo
#endif /* _WIN32_WCE */
);


/***
*size_t wcsftime(wstring, maxsize, format, timeptr) - Format a time string
*
*Purpose:
*       The wcsftime functions is equivalent to to the strftime function, except
*       that the argument 'wstring' specifies an array of a wide string into
*       which the generated output is to be placed. The wcsftime acts as if
*       strftime were called and the result string converted by mbstowcs().
*       [ISO]
*
*Entry:
*       wchar_t *wstring = pointer to output string
*       size_t maxsize = max length of string
*       const wchar_t *format = format control string
*       const struct tm *timeptr = pointer to tb data structure
*
*Exit:
*       !0 = If the total number of resulting characters including the
*       terminating null is not more than 'maxsize', then return the
*       number of wide chars placed in the 'wstring' array (not including the
*       null terminator).
*
*       0 = Otherwise, return 0 and the contents of the string are
*       indeterminate.
*
*Exceptions:
*
*******************************************************************************/

static size_t __cdecl _wcsftime_l_stat (
        wchar_t *wstring,
        size_t maxsize,
        const wchar_t *wformat,
        const struct tm *timeptr
#ifndef _WIN32_WCE
        ,_locale_t plocinfo
#endif /* _WIN32_WCE */
        )
{
    size_t retval = 0;
    char *format = NULL;
    char *string = NULL;
    size_t flen = 0;
#ifdef _WIN32_WCE
    int malloc_flag1 = 0;
    int malloc_flag2 = 0;
#endif /* _WIN32_WCE */

    _VALIDATE_RETURN( ( wstring != NULL ), EINVAL, 0)
    _VALIDATE_RETURN( ( maxsize != 0 ), EINVAL, 0)
    if ( maxsize > 0 )
    {
        *wstring = '\0';
    }

    _VALIDATE_RETURN( ( wformat != NULL ), EINVAL, 0)

    flen = wcslen(wformat) + 1;

#ifndef _WIN32_WCE
    string = (char *)_calloca(sizeof(char)*2, maxsize);
#else
    // _resetstkoflw isn't supported for CE, so always malloc
    string = NULL;
#endif /* _WIN32_WCE */

    if ( string == NULL )
    {
#ifndef _WIN32_WCE
        return 0;
#else
        if ((string = (char *)_malloc_crt(sizeof(char) * maxsize * 2)) == NULL)
        {
            return 0;
        }
        else
        {
            malloc_flag1++;
        }
#endif /* _WIN32_WCE */
    }


#ifndef _WIN32_WCE
    format = (char *)_calloca(sizeof(char)*2, flen);
#else
    // _resetstkoflw isn't supported for CE, so always malloc
    format = NULL;
#endif /* _WIN32_WCE */
    if ( format == NULL )
    {
#ifndef _WIN32_WCE
        goto done;
#else
        if ((format = (char *)_malloc_crt(sizeof(char) * flen * 2)) == NULL)
        {
            goto done;
        }
        else
        {
            malloc_flag2++;
        }
#endif /* _WIN32_WCE */
    }

#ifndef _WIN32_WCE
    if (_ERRCHECK_EINVAL_ERANGE(_wcstombs_s_l(NULL, format, flen * 2, wformat, flen * 2 - 1, plocinfo)) != 0)
#else /* _WIN32_WCE */
    if (wcstombs(format, wformat, flen * 2) == -1)
#endif /* _WIN32_WCE */
    {
        goto done;
    }

#ifndef _WIN32_WCE
    if (_Strftime_l(string, maxsize * 2, format, timeptr, 0, plocinfo))
#else /* _WIN32_WCE */
    if (_Strftime_l(string, maxsize * 2, format, timeptr, 0))
#endif /* _WIN32_WCE */
    {
#ifndef _WIN32_WCE
        if (_ERRCHECK_EINVAL_ERANGE(_mbstowcs_s_l(&retval, wstring, maxsize, string, _TRUNCATE, plocinfo)) != 0)
	{
	    // VSW 435529: Set errno here if we overflowed the buffer.
            if (retval >= maxsize)
            {
                errno = ERANGE;
            }
#else
        if ((retval = mbstowcs(wstring, string, maxsize)) == -1 || 
		retval == maxsize)
	{
#endif /* _WIN32_WCE */
        
            retval = 0;
        }
#ifndef _WIN32_WCE
        /* mbstowcs_s  returns the number of characters including the null-terminator;
         * _wcsftime just returns the number of characters.
         */
        if (retval > 0)
        {
            --retval;
        }
#else
        /* mbstowcs returns the number of characters not including the null-terminator
         * just return retval */
#endif /* _WIN32_WCE */
    }
    else
    {
        retval = 0;
    }

done:
#ifndef _WIN32_WCE
    if ( format != NULL )
        _freea(format);

    _freea(string);

#else
    if ( malloc_flag1 )
    {
        _free_crt(string);
    }

    if ( malloc_flag2 )
    {
        _free_crt(format);
    }
#endif /* _WIN32_WCE */

    if (retval == 0)
    {
        *wstring = '\0';
    }

    return retval;
}

#ifndef _WIN32_WCE
extern "C"
#endif /* _WIN32_WCE */
size_t __cdecl _wcsftime_l (
        wchar_t *wstring,
        size_t maxsize,
        const wchar_t *wformat,
        const struct tm *timeptr
#ifndef _WIN32_WCE
        ,_locale_t plocinfo
#endif /* _WIN32_WCE */
        )
{
#ifndef _WIN32_WCE
    _LocaleUpdate _loc_update(plocinfo);
#endif /* _WIN32_WCE */

    return _wcsftime_l_stat(
            wstring,
            maxsize,
            wformat,
            timeptr
#ifndef _WIN32_WCE
            ,_loc_update.GetLocaleT()
#endif /* _WIN32_WCE */
            );
}

#ifndef _WIN32_WCE
extern "C"
#endif /* _WIN32_WCE */
size_t __cdecl wcsftime (
        wchar_t *wstring,
        size_t maxsize,
        const wchar_t *wformat,
        const struct tm *timeptr
        )
{
    return _wcsftime_l(wstring, maxsize, wformat, timeptr
#ifndef _WIN32_WCE
                          , NULL
#endif /* _WIN32_WCE */
                          );
}

#endif /* _POSIX_ */
