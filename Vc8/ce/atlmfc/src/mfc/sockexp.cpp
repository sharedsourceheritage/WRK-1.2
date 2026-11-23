
// This is a part of the Microsoft Foundation Classes C++ library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Microsoft Foundation Classes Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the
// Microsoft Foundation Classes product.


#include "stdafx.h"


#define new DEBUG_NEW

#ifndef _WIN32_WCE
#pragma comment(lib, "wsock32.lib")
#else
#pragma comment(lib, "ws2.lib")
#endif // !_WIN32_WCE

BOOL AFXAPI _AfxSocketInit(WSADATA* lpwsaData);

BOOL AFXAPI AfxSocketInit(WSADATA* lpwsaData)
{
	// Reference the start up function to pull in wsock32.dll
	// This is to prevent problems with delay loading wsock32.dll from mfc*.dll
	// WSAStartup should never be NULL
	if (WSAStartup != NULL)
		return _AfxSocketInit(lpwsaData);
	return FALSE;
}
