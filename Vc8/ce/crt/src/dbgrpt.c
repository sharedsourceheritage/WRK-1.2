/***
*dbgrpt.c - Debug CRT Reporting Functions
*
*       Copyright (c) Microsoft Corporation. All rights reserved.
*
*Purpose:
*
*Revision History:
*       08-16-94  CFW   Module created.
*       11-28-94  CFW   Change _SetCrtxxx to _CrtSetxxx.
*       12-08-94  CFW   Use non-win32 names.
*       01-05-94  CFW   Add report hook.
*       01-11-94  CFW   Report uses _snprintf, all unsigned chars.
*       01-20-94  CFW   Change unsigned chars to chars.
*       01-24-94  CFW   Name cleanup.
*       02-09-95  CFW   PMac work, _CrtDbgReport now returns 1 for debug,
*                       -1 for error.
*       02-15-95  CFW   Make all CRT message boxes look alike.
*       02-24-95  CFW   Use __crtMessageBoxA.
*       02-27-95  CFW   Move GetActiveWindow/GetLastrActivePopup into
*                       __crtMessageBoxA, add _CrtDbgBreak.
*       02-28-95  CFW   Fix PMac reporting.
*       03-21-95  CFW   Add _CRT_ASSERT report type, improve assert windows.
*       04-19-95  CFW   Avoid double asserts.
*       04-25-95  CFW   Add _CRTIMP to all exported functions.
*       04-30-95  CFW   "JIT" message removed.
*       05-10-95  CFW   Change Interlockedxxx to _CrtInterlockedxxx.
*       05-24-95  CFW   Change report hook scheme, make _crtAssertBusy available.
*       06-06-95  CFW   Remove _MB_SERVICE_NOTIFICATION.
*       06-08-95  CFW   Macos header changes cause warning.
*       06-08-95  CFW   Add return value parameter to report hook.
*       06-27-95  CFW   Add win32s support for debug libs.
*       07-07-95  CFW   Simplify default report mode scheme.
*       07-19-95  CFW   Use WLM debug string scheme for PMac.
*       08-01-95  JWM   PMac file output fixed.
*       01-08-96  JWM   File output now in text mode.
*       04-22-96  JWM   MAX_MSG increased from 512 to 4096.
*       04-29-96  JWM   _crtAssertBusy no longer being decremented prematurely.
*       01-05-99  GJF   Changes for 64-bit size_t.
*       05-17-99  PML   Remove all Macintosh support.
*       03-21-01  PML   Add _CrtSetReportHook2 (vs7#124998)
*       03-28-01  PML   Protect against GetModuleFileName overflow (vs7#231284)
*       05-08-02  GB    VS7#520926. Fixed small chance of BO on szLineMessage
*       08-12-03  AC    Validation of input parameters
*       08-28-03  SJ    Added _wassert, CrtSetReportHookW2,CrtDbgReportW, 
*                       & other helper functions. VSWhidbey#55308
*       04-05-04  AJS   Added _CrtDbgReportTV, allowed building as C++.
*       01-28-05  SJ    DEBUG_LOCK is now preallocated.
*
*******************************************************************************/

#ifdef  _DEBUG

#include <internal.h>
#include <mtdll.h>
#include <malloc.h>
#ifndef _WIN32_WCE
#include <mbstring.h>
#endif /* _WIN32_WCE */
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <tchar.h>
#include <dbgint.h>
#include <signal.h>
#include <string.h>
#include <awint.h>
#include <windows.h>
#include <errno.h>

#ifdef  __cplusplus
extern "C" {
#endif

/*---------------------------------------------------------------------------
 *
 * Debug Reporting
 *
 --------------------------------------------------------------------------*/

extern _CRT_REPORT_HOOK _pfnReportHook;
extern ReportHookNode *_pReportHookList;
extern ReportHookNodeW *_pReportHookListW;

_CRTIMP int __cdecl _VCrtDbgReportA(
        int nRptType, 
        const char * szFile, 
        int nLine,
        const char * szModule,
        const char * szFormat, 
        va_list arglist
        );

_CRTIMP int __cdecl _VCrtDbgReportW(
        int nRptType, 
        const wchar_t * szFile, 
        int nLine,
        const wchar_t * szModule,
        const wchar_t * szFormat, 
        va_list arglist
        );

static const TCHAR * _CrtDbgModeMsg[_CRT_ERRCNT] = { _T("Warning"),
                                                    _T("Error"),
                                                    _T("Assertion Failed")
                                                  };

/***
*_CRT_REPORT_HOOK _CrtSetReportHook2() - configure client report hook in list
*
*Purpose:
*       Install or remove a client report hook from the report list.  Exists
*       separately from _CrtSetReportHook because the older function doesn't
*       work well in an environment where DLLs that are loaded and unloaded
*       dynamically out of LIFO order want to install report hooks.
*       This function exists in 2 forms - ANSI & UNICODE
*
*Entry:
*       int mode - _CRT_RPTHOOK_INSTALL or _CRT_RPTHOOK_REMOVE
*       _CRT_REPORT_HOOK pfnNewHook - report hook to install/remove/query
*
*Exit:
*       Returns -1 if an error was encountered, with EINVAL or ENOMEM set,
*       else returns the reference count of pfnNewHook after the call.
*
*Exceptions:
*       Input parameters are validated. Refer to the validation section of the function. 
*
*******************************************************************************/
_CRTIMP int __cdecl _CrtSetReportHookT2(
        int mode,
        _CRT_REPORT_HOOKT pfnNewHook
        )
{
        ReportHookNodeT *p;
        int ret;

        /* validation section */
        _VALIDATE_RETURN(mode == _CRT_RPTHOOK_INSTALL || mode == _CRT_RPTHOOK_REMOVE, EINVAL, -1);
        _VALIDATE_RETURN(pfnNewHook != NULL, EINVAL, -1);

#ifdef  _MT
        _mlock(_DEBUG_LOCK);
        __try
        {
#endif

        /* Search for new hook function to see if it's already installed */
        for (p = _pReportHookListT; p != NULL; p = p->next)
            if (p->pfnHookFunc == pfnNewHook)
                break;

        if (mode == _CRT_RPTHOOK_REMOVE)
        {
            /* Remove request - free list node if refcount goes to zero */
            if (p != NULL)
            {
                if ((ret = --p->refcount) == 0)
                {
                    if (p->next)
                        p->next->prev = p->prev;
                    if (p->prev)
                        p->prev->next = p->next;
                    else
                        _pReportHookListT = p->next;
                    _free_crt(p);
                }
            }
            else
            {
                _ASSERTE(("The hook function is not in the list!",0));
                ret = -1;
#ifndef _WIN32_WCE
                errno = EINVAL;
#endif /* _WIN32_WCE */
            }
        }
        else
        {
            /* Insert request */
            if (p != NULL)
            {
                /* Hook function already registered, move to head of list */
                ret = ++p->refcount;
                if (p != _pReportHookListT)
                {
                    if (p->next)
                        p->next->prev = p->prev;
                    p->prev->next = p->next;
                    p->prev = NULL;
                    p->next = _pReportHookListT;
                    _pReportHookListT->prev = p;
                    _pReportHookListT = p;
                }
            }
            else
            {
                /* Hook function not already registered, insert new node */
                p = (ReportHookNodeT *)_malloc_crt(sizeof(ReportHookNodeT));
                if (p == NULL)
                {
                    /* malloc fails: we do not assert here */
                    ret = -1;
#ifndef _WIN32_WCE
                    errno = ENOMEM;
#endif /* _WIN32_WCE */
                }
                else
                {
                    p->prev = NULL;
                    p->next = _pReportHookListT;
                    if (_pReportHookListT)
                        _pReportHookListT->prev = p;
                    ret = p->refcount = 1;
                    p->pfnHookFunc = pfnNewHook;
                    _pReportHookListT = p;
                }
            }
        }

#ifdef  _MT
        }
        __finally {
            _munlock(_DEBUG_LOCK);
        }
#endif

        return ret;
}


static TCHAR * dotdotdot = _T("...");
#define MAXLINELEN 64
#define DOTDOTDOTSZ 3

/***
*int _CrtDbgReport() - primary reporting function
*
*Purpose:
*       Display a message window with the following format.
*
*       ================= Microsft Visual C++ Debug Library ================
*
*       {Warning! | Error! | Assertion Failed!}
*
*       Program: c:\test\mytest\foo.exe
*       [Module: c:\test\mytest\bar.dll]
*       [File: c:\test\mytest\bar.c]
*       [Line: 69]
*
*       {<warning or error message> | Expression: <expression>}
*
*       [For information on how your program can cause an assertion
*        failure, see the Visual C++ documentation on asserts]
*
*       (Press Retry to debug the application)
*       
*       ===================================================================
*
*Entry:
*       int             nRptType    - report type
*       const TCHAR *    szFile      - file name
*       int             nLine       - line number
*       const TCHAR *    szModule    - module name
*       const TCHAR *    szFormat    - format string
*       ...                         - var args
*
*Exit:
*       if (MessageBox)
*       {
*           Abort -> aborts
*           Retry -> return TRUE
*           Ignore-> return FALSE
*       }
*       else
*           return FALSE
*
*Exceptions:
*       If something goes wrong, we do not assert, but we return -1.
*
*******************************************************************************/
__inline int __cdecl _CrtDbgReportTV(
        int nRptType, 
        const TCHAR * szFile, 
        int nLine,
        const TCHAR * szModule,
        const TCHAR * szFormat, 
        va_list arglist
        )
{
    #if defined(_UNICODE) && !defined (_WIN32_WCE)
    unsigned int osplatform = 0;
    _ERRCHECK(_get_osplatform(&osplatform));

    /* On Win9x we call the ANSI versions */
    if(osplatform == VER_PLATFORM_WIN32_WINDOWS)
    {
        char szaFile[DBGRPT_MAX_MSG], szaModule[DBGRPT_MAX_MSG], szaFormat[DBGRPT_MAX_MSG];
        errno_t e = 0;
        
        if(szFile && *szFile)
        {
            e = _ERRCHECK_EINVAL_ERANGE(wcstombs_s(NULL, szaFile, DBGRPT_MAX_MSG, szFile, _TRUNCATE));
            if(e == STRUNCATE)
            {
                /* We truncate the string & append a "..." to it. */
                szaFile[DBGRPT_MAX_MSG - DOTDOTDOTSZ - 1] = '\0';
                _ERRCHECK(strcat_s(szaFile, DBGRPT_MAX_MSG, "..."));
            }
            else if(e != 0)
            {
                /* If wcstombs_s encounters a wide character that cannot be 
                converted to a multibyte character, it returns EILSEQ */
                _ERRCHECK(strcpy_s(szaFile, DBGRPT_MAX_MSG, "Expression cannot be displayed on Win9x"));
            } 
        }
        else
            szaFile[0] = '\0';
        
        if(szModule && *szModule)
        {
            e = _ERRCHECK_EINVAL_ERANGE(wcstombs_s(NULL, szaModule, DBGRPT_MAX_MSG, szModule, _TRUNCATE));
            if(e == STRUNCATE)
            {
                szaFile[DBGRPT_MAX_MSG - DOTDOTDOTSZ - 1] = '\0';
                _ERRCHECK(strcat_s(szaFile, DBGRPT_MAX_MSG, "..."));
            }
            else if(e != 0)
            {
                _ERRCHECK(strcpy_s(szaModule, DBGRPT_MAX_MSG, "Expression cannot be displayed on Win9x"));
            }
        }
        else
            szaModule[0] = '\0';
        
        if(szFormat && *szFormat)
        {
            e = _ERRCHECK_EINVAL_ERANGE(wcstombs_s(NULL, szaFormat, DBGRPT_MAX_MSG, szFormat, _TRUNCATE));
            if( e != 0)
            {
                _ERRCHECK(strcpy_s(szaFormat, DBGRPT_MAX_MSG, DBGRPT_INVALIDMSG));
            }
        }
        else
            szaFormat[0] = '\0';
        
        return _VCrtDbgReportA(nRptType,szaFile,nLine,szaModule,szaFormat,arglist);
    }

#endif

    return _VCrtDbgReportT(nRptType,szFile,nLine,szModule,szFormat,arglist);
}

_CRTIMP int __cdecl _CrtDbgReportT(
        int nRptType, 
        const TCHAR * szFile, 
        int nLine,
        const TCHAR * szModule,
        const TCHAR * szFormat, 
        ...
        )
{
    int retval;
    va_list arglist;

    va_start(arglist,szFormat);
    
    retval = _CrtDbgReportTV(nRptType, szFile, nLine, szModule, szFormat, arglist);

    va_end(arglist);

    return retval;
}       

/***
*int __crtMessageWindow() - report to a message window
*
*Purpose:
*       put report into message window, allow user to choose action to take
*
*Entry:
*       int             nRptType      - report type
*       const TCHAR *    szFile        - file name
*       const TCHAR *    szLine        - line number
*       const TCHAR *    szModule      - module name
*       const TCHAR *    szUserMessage - user message
*
*Exit:
*       if (MessageBox)
*       {
*           Abort -> aborts
*           Retry -> return TRUE
*           Ignore-> return FALSE
*       }
*       else
*           return FALSE
*
*Exceptions:
*       If something goes wrong, we do not assert, but we simply return -1,
*       which will trigger the debugger automatically (the same as the user
*       pressing the Retry button).
*
*******************************************************************************/

int __cdecl __crtMessageWindow(
        int nRptType,
        const TCHAR * szFile,
        const TCHAR * szLine,        
        const TCHAR * szModule,
        const TCHAR * szUserMessage
        )
{
        int nCode;
        TCHAR *szShortProgName;
        const TCHAR *szShortModuleName = NULL ;
        TCHAR szExeName[MAX_PATH + 1];
        TCHAR szOutMessage[DBGRPT_MAX_MSG];
        int szlen = 0;

        if (szUserMessage == NULL)
            return 1;

        /* Shorten program name */
        szExeName[MAX_PATH] = _T('\0');
        if (!GetModuleFileName(NULL, szExeName, MAX_PATH))
            _ERRCHECK(_tcscpy_s(szExeName, MAX_PATH, _T("<program name unknown>")));

        szShortProgName = szExeName;

        if (_tcslen(szShortProgName) > MAXLINELEN)
        {
            szShortProgName += _tcslen(szShortProgName) - MAXLINELEN;
            _ERRCHECK(_tcsncpy_s(szShortProgName, MAX_PATH - (szShortProgName - szExeName), dotdotdot, DOTDOTDOTSZ));
        }

        /* Shorten module name */
        if (szModule && _tcslen(szModule) > MAXLINELEN)
        {
            szShortModuleName = szModule + _tcslen(szModule) - MAXLINELEN + 3;
        }

#ifndef _WIN32_WCE
        _ERRCHECK_SPRINTF(szlen = _sntprintf_s(szOutMessage, DBGRPT_MAX_MSG, DBGRPT_MAX_MSG - 1,
            _T("Debug %s!\n\nProgram: %s%s%s%s%s%s%s%s%s%s%s%s")
            _T("\n\n(Press Retry to debug the application)"),
            _CrtDbgModeMsg[nRptType],
            szShortProgName,
            szModule ? _T("\nModule: ") : _T(""),
            szShortModuleName ? _T("...") : _T(""),
            szShortModuleName ? szShortModuleName : (szModule ? szModule : _T("")),
            szFile ? _T("\nFile: ") : _T(""),
            szFile ? szFile : _T(""),
            szLine ? _T("\nLine: ") : _T(""),
            szLine ? szLine : _T(""),
            szUserMessage[0] ? _T("\n\n") : _T(""),
            szUserMessage[0] && _CRT_ASSERT == nRptType ? _T("Expression: ") : _T(""),
            szUserMessage[0] ? szUserMessage : _T(""),
            _CRT_ASSERT == nRptType ? 
            _T("\n\nFor information on how your program can cause an assertion")
            _T("\nfailure, see the Visual C++ documentation on asserts.")
            : _T("")));
#else /* _WIN32_WCE */
        _ERRCHECK_SPRINTF(szlen = _sntprintf(szOutMessage, DBGRPT_MAX_MSG,
            _T("Debug %s!\n\nProgram: %s%s%s%s%s%s%s%s%s%s%s")
            _T("\n\n(Press Retry to debug the application)"),
            _CrtDbgModeMsg[nRptType],
            szShortProgName,
            szModule ? _T("\nModule: ") : _T(""),
            szShortModuleName ? _T("...") : _T(""),
            szShortModuleName ? szShortModuleName : (szModule ? szModule : _T("")),
            szFile ? _T("\nFile: ") : _T(""),
            szFile ? szFile : _T(""),
            szLine ? _T("\nLine: ") : _T(""),
            szLine ? szLine : _T(""),
            szUserMessage[0] ? _T("\n") : _T(""),
            szUserMessage[0] && _CRT_ASSERT == nRptType ? _T("Expression: ") : _T(""),
            szUserMessage[0] ? szUserMessage : _T("")));
#endif /* _WIN32_WCE */
        if (szlen < 0)
#ifdef _UNICODE
            _ERRCHECK(wcscpy_s(szOutMessage, DBGRPT_MAX_MSG, _CRT_WIDE(DBGRPT_TOOLONGMSG)));
#else
            _ERRCHECK(strcpy_s(szOutMessage, DBGRPT_MAX_MSG, DBGRPT_TOOLONGMSG));
#endif

        /* Report the warning/error */
        nCode = __crtMessageBox(szOutMessage,
                             _T("Microsoft Visual C++ Debug Library"),
                             MB_ICONHAND|MB_ABORTRETRYIGNORE|MB_SETFOREGROUND
#ifndef _WIN32_WCE
                             |MB_TASKMODAL
#endif /* _WIN32_WCE */
                             );

        /* Abort: abort the program */
        if (IDABORT == nCode)
        {
#ifndef _WIN32_WCE
            /* note that it is better NOT to call abort() here, because the 
             * default implementation of abort() will call Watson
             */

            /* raise abort signal */
            raise(SIGABRT);
#endif /* _WIN32_WCE */

            /* We usually won't get here, but it's possible that
               SIGABRT was ignored.  So exit the program anyway. */
            _exit(3);
        }

        /* Retry: return 1 to call the debugger */
        if (IDRETRY == nCode)
            return 1;

        /* Ignore: continue execution */
        return 0;
}

#ifdef  __cplusplus
}
#endif

#endif  /* _DEBUG */

