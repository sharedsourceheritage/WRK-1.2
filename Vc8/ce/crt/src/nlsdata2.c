/***
*nlsdata2.c - globals for international library - locale handles and code page
*
*       Copyright (c) Microsoft Corporation. All rights reserved.
*
*Purpose:
*       This module defines the locale handles and code page.  The handles are
*       required by almost all locale dependent functions.  This module is
*       separated from nlsdatax.c for granularity.
*
*Revision History:
*       12-01-91  ETC   Created.
*       09-15-93  CFW   Use ANSI conformant "__" names.
*       04-12-94  GJF   Made definitions of __lc_handle and __lc_codepage
*                       conditional on ndef DLL_FOR_WIN32S
*       01-12-98  GJF   Added __lc_collate_cp.
*       26-01-00  GB    Added __lc_clike.
*       11-12-01  GB    Implemented new locale with true per thread locale
*                       capablity.
*       01-30-02  GB    added global data variable for single threaded
*                       library __setloc_struct
*       04-01-04  SJ    Design Changes in perthread locale - VSW#141214. Moved
*                       __globallocalestatus to it's own file.
*
*******************************************************************************/

#include <locale.h>
#include <setlocal.h>
#ifndef _WIN32_WCE
#include <mbctype.h>
#endif

char __clocalestr[] = "C";
extern struct __lc_time_data __lc_time_c;       /* defined in strftime.c */

#ifndef _MT
_setloc_struct __setloc_data = {
    NULL,           // *pchLanguage
    NULL,           // *pchCountry
    0,              // iLcidState
    0,              // iPrimaryLen
    0,              // bAbbrevLanguage
    0,              // bAbbrevCountry
    0,              // lcidLanguage
    0,              // lcidCountry
    {0, 0, 0},      // _cacheid
    0,              // _cachecp
    "C",            // _cachein[MAX_LC_LEN]
    "C",            // _chacheout[MAX_LC_LEN]
    {   {0,0},      // _Lcid_c[5]
        {0,0},
        {0,0},
        {0,0},
        {0,0}
    }
};
#endif
/*
 * initial locale information struct, set to the C locale. Used only until the
 * first call to setlocale()
 */
threadlocinfo __initiallocinfo = {
    1,                                        /* refcount                 */
    _CLOCALECP,                               /* lc_codepage              */
    _CLOCALECP,                               /* lc_collate_cp            */
    {   _CLOCALEHANDLE,                       /* lc_handle[_ALL]          */
        _CLOCALEHANDLE,                       /* lc_handle[_COLLATE]      */
        _CLOCALEHANDLE,                       /* lc_handle[_CTYPE]        */
        _CLOCALEHANDLE,                       /* lc_handle[_MONETARY]     */
        _CLOCALEHANDLE,                       /* lc_handle[_NUMERIC]      */
        _CLOCALEHANDLE                        /* lc_handle[_TIME]         */
    },
    {   {0, 0, 0},                            /* lc_id[LC_ALL]            */
        {0, 0, 0},                            /* lc_id[LC_COLLATE]        */
        {0, 0, 0},                            /* lc_id[LC_CTYPE]          */
        {0, 0, 0},                            /* lc_id[LC_MONETARY]       */
        {0, 0, 0},                            /* lc_id[LC_NUMERIC]        */
        {0, 0, 0}                             /* lc_id[LC_TIME]           */
    },
    {   {NULL, NULL, NULL, NULL},             /* lc_category[LC_ALL]      */
        {__clocalestr, NULL, NULL, NULL},     /* lc_category[LC_COLLATE]  */
        {__clocalestr, NULL, NULL, NULL},     /* lc_category[LC_CTYPE]    */
        {__clocalestr, NULL, NULL, NULL},     /* lc_category[LC_MONETARY] */
        {__clocalestr, NULL, NULL, NULL},     /* lc_category[LC_NUMERIC]  */
        {__clocalestr, NULL, NULL, NULL}      /* lc_category[LC_TIME]     */
    },
    1,                                        /* lc_clike                 */
    1,                                        /* mb_cur_max               */
    NULL,                                     /* lconv_intl_refcount      */
    NULL,                                     /* lconv_num_refcount       */
    NULL,                                     /* lconv_mon_refcount       */
    &__lconv_c,                               /* lconv                    */
    NULL,                                     /* ctype1_refcount          */
    NULL,                                     /* ctype1                   */
    __newctype + 128,                         /* pctype                   */
#ifndef _WIN32_WCE
    __newclmap + 128,                         /* pclmap                   */
    __newcumap + 128,                         /* pcumap                   */
#endif /* _WIN32_WCE */
    &__lc_time_c,                             /* lc_time_curr             */
};

/* 
 * global pointer to the current per-thread locale information structure.
 */
pthreadlocinfo __ptlocinfo = &__initiallocinfo;

/*
 *  Locale handles.
 */
LCID __lc_handle[] = 
    {   _CLOCALEHANDLE,                       /* lc_handle[_ALL]          */
        _CLOCALEHANDLE,                       /* lc_handle[_COLLATE]      */
        _CLOCALEHANDLE,                       /* lc_handle[_CTYPE]        */
        _CLOCALEHANDLE,                       /* lc_handle[_MONETARY]     */
        _CLOCALEHANDLE,                       /* lc_handle[_NUMERIC]      */
        _CLOCALEHANDLE                        /* lc_handle[_TIME]         */
    };

/*
 *  Code page.
 */
UINT __lc_codepage = _CLOCALECP;                /* CP_ACP */

/*
 * Code page for LC_COLLATE
 */
UINT __lc_collate_cp = _CLOCALECP;

/* if this locale has first 127 character set same as CLOCALE.
 */
int __lc_clike = 1;

#ifndef _WIN32_WCE
_locale_tstruct __initiallocalestructinfo = 
{
    &__initiallocinfo,
    &__initialmbcinfo
};
#endif /* _WIN32_WCE */
