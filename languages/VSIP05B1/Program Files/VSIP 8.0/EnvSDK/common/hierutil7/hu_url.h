//---------------------------------------------------------------------------
// Microsoft Visual Studio
//
// Microsoft Confidential
// Copyright (C) 1994 - 2000 Microsoft Corporation. 
// All Rights Reserved.
//
// hu_url.h : definition URL utilities
//---------------------------------------------------------------------------
#if (_MSC_VER > 1000) && !defined(NO_PRAGMA_ONCE)
#pragma once
#endif

#ifndef __HU_URL_H__
#define __HU_URL_H__

//-----------------------------------------------------------------------------
//  UtilConvertToRelative
//
//  Converts a URL to folder-relative URL.
//      The URL is returned identical if
//          the projects don't match
//          the protocols don't match
//                              
//-----------------------------------------------------------------------------
HRESULT UtilConvertToRelativeURL(
    LPOLESTR pstrDestURL,
    LPOLESTR pstrDestFolder,
    LPOLESTR pstrDestProject,
    BSTR * pbstrRelativeURL);

#endif // __HU_URL_H__

