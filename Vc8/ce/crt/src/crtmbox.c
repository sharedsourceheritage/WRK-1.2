/***
*crtmbox.c - CRT MessageBoxA wrapper.
*
*       Copyright (c) Microsoft Corporation. All rights reserved.
*
*Purpose:
*       Wrap MessageBoxA.
*
*Revision History:
*       02-24-95  CFW   Module created.
*       02-27-95  CFW   Move GetActiveWindow/GetLastActivePopup to here.
*       05-17-99  PML   Remove all Macintosh support.
*       09-16-00  PML   Use MB_SERVICE_NOTIFICATION from services (vs7#123291)
*       08-28-03  SJ    Added _wassert, CrtSetReportHookW2,CrtDbgReportW, 
*                       & other helper functions. VSWhidbey#55308
*       03-13-04  MSL   Securely load system dll for prefast
*       10-09-04  MSL   Prefast initialisation fixes
*       05-13-05  MSL   WIN32_WINNT now defined centrally for CRT
*
*******************************************************************************/

#include <tchar.h>
#include <windows.h>
#include <stdlib.h>
#include <awint.h>
#include <internal.h>

/***
*__crtMessageBox - call MessageBoxA dynamically.
*
*Purpose:
*       Avoid static link with user32.dll. Only load it when actually needed.
*
*Entry:
*       see MessageBoxA docs.
*
*Exit:
*       see MessageBoxA docs.
*
*Exceptions:
*
*******************************************************************************/
#ifdef _UNICODE
int __cdecl __crtMessageBoxW(
#else
int __cdecl __crtMessageBoxA(
#endif
        LPCTSTR lpText,
        LPCTSTR lpCaption,
        UINT uType
        )
{
        typedef int (APIENTRY *PFNMessageBox)(HWND, LPCTSTR, LPCTSTR, UINT);
        typedef HWND (APIENTRY *PFNGetActiveWindow)(void);
        typedef HWND (APIENTRY *PFNGetLastActivePopup)(HWND);
        typedef HWINSTA (APIENTRY *PFNGetProcessWindowStation)(void);
        typedef BOOL (APIENTRY *PFNGetUserObjectInformation)(HANDLE, int, PVOID, DWORD, LPDWORD);

        void *pfn = NULL;
        void *enull = _encoded_null();
        static PFNMessageBox pfnMessageBox = NULL;
        static PFNGetActiveWindow pfnGetActiveWindow = NULL;
        static PFNGetLastActivePopup pfnGetLastActivePopup = NULL;
        static PFNGetProcessWindowStation pfnGetProcessWindowStation = NULL;
        static PFNGetUserObjectInformation pfnGetUserObjectInformation = NULL;

        HWND hWndParent = NULL;
        BOOL fNonInteractive = FALSE;
#ifndef _WIN32_WCE
        HWINSTA hwinsta;
        USEROBJECTFLAGS uof;
        DWORD nDummy;
        unsigned int osplatform = 0;
        unsigned int winmajor = 0;
#endif /* _WIN32_WCE */

        if (NULL == pfnMessageBox)
        {
#ifndef _WIN32_WCE
            HMODULE hlib=LoadLibrary(_T("USER32.DLL"));
#else /* _WIN32_WCE */                         
            HMODULE hlib=LoadLibrary(_T("COREDLL.DLL"));
#endif /* _WIN32_WCE */               
            if(hlib==NULL)
            {
                return 0;
            }

            if (NULL == (pfn =
#ifdef _UNICODE
#ifndef _WIN32_WCE
                            GetProcAddress(hlib, "MessageBoxW")))
#else /* _WIN32_WCE */                         
                            GetProcAddress(hlib, L"MessageBoxW")))
#endif /* _WIN32_WCE */               
#else                            
                            GetProcAddress(hlib, "MessageBoxA")))
#endif                            
                return 0;

            pfnMessageBox = (PFNMessageBox) _encode_pointer(pfn);

            pfnGetActiveWindow = (PFNGetActiveWindow)

#ifndef _WIN32_WCE
                _encode_pointer(GetProcAddress(hlib, "GetActiveWindow"));
#else /* _WIN32_WCE */                         
                _encode_pointer(GetProcAddress(hlib, L"GetActiveWindow"));
#endif /* _WIN32_WCE */               


            pfnGetLastActivePopup = (PFNGetLastActivePopup)

#ifndef _WIN32_WCE
                _encode_pointer(GetProcAddress(hlib, "GetLastActivePopup"));
#else /* _WIN32_WCE */                         
                _encode_pointer(GetProcAddress(hlib, L"GetLastActivePopup"));
#endif /* _WIN32_WCE */               


#ifndef _WIN32_WCE
            _ERRCHECK(_get_osplatform(&osplatform));
            if (osplatform == VER_PLATFORM_WIN32_NT)
            {
                pfn =
#ifdef _UNICODE                
                        GetProcAddress(hlib, "GetUserObjectInformationW");
#else                        
                        GetProcAddress(hlib, "GetUserObjectInformationA");
#endif                        

                pfnGetUserObjectInformation = (PFNGetUserObjectInformation) _encode_pointer(pfn);

                if (pfnGetUserObjectInformation != NULL)
                    pfnGetProcessWindowStation = (PFNGetProcessWindowStation)
                        _encode_pointer(GetProcAddress(hlib, "GetProcessWindowStation"));
            }
        }

        /*
         * If the current process isn't attached to a visible WindowStation,
         * (e.g. a non-interactive service), then we need to set the
         * MB_SERVICE_NOTIFICATION flag, else the message box will be
         * invisible, hanging the program.
         *
         * This check only applies to Windows NT-based systems (for which we
         * retrieved the address of GetProcessWindowStation above).
         */

        if (pfnGetProcessWindowStation != enull && pfnGetUserObjectInformation != enull)
        {
            if (NULL == (hwinsta = ((PFNGetProcessWindowStation) _decode_pointer(pfnGetProcessWindowStation))()) ||
                !((PFNGetUserObjectInformation) _decode_pointer(pfnGetUserObjectInformation))
                    (hwinsta, UOI_FLAGS, &uof, sizeof(uof), &nDummy) ||
                (uof.dwFlags & WSF_VISIBLE) == 0)
            {
                fNonInteractive = TRUE;
            }
        }

        if (fNonInteractive)
        {
            _ERRCHECK(_get_winmajor(&winmajor));
            if (winmajor >= 4)
                uType |= MB_SERVICE_NOTIFICATION;
            else
                uType |= MB_SERVICE_NOTIFICATION_NT3X;
        }
        else
#else
	}
#endif /* _WIN32_WCE */

        {
            if (pfnGetActiveWindow != enull)
                hWndParent = ((PFNGetActiveWindow) _decode_pointer(pfnGetActiveWindow))();

            if (hWndParent != NULL && pfnGetLastActivePopup != enull)
                hWndParent = ((PFNGetLastActivePopup) _decode_pointer(pfnGetLastActivePopup))(hWndParent);
        }

        return ((PFNMessageBox) _decode_pointer(pfnMessageBox))(hWndParent, lpText, lpCaption, uType);
}
