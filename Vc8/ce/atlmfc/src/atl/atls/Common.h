// This is a part of the Active Template Library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the	
// Active Template Library product.

#ifndef _WIN32_WCE
extern const char *g_pszUpdateEventName;
extern const char *g_pszAllocFileMapName;
extern const char *g_pszKernelObjFmt;
#else // _WIN32_WCE
extern const wchar_t *g_pszUpdateEventName;
extern const wchar_t *g_pszAllocFileMapName;
extern const wchar_t *g_pszKernelObjFmt;
#endif // _WIN32_WCE
extern const char *g_pszLockMutexName;
extern const char *g_pszLockEventName;
extern const char *g_pszAllocMutexName;

extern const wchar_t *g_pszProcessObject;
extern const wchar_t *g_pszReadsInProgress;

extern class CAtlAllocator g_Allocator;
extern class CAtlTraceLock g_Lock;

