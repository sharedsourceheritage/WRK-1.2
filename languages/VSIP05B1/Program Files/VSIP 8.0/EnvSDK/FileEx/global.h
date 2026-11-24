
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#pragma once

///////////////////////////////////////////////////////////////////////////////
// GetResourceURL - Builds up a res:// URL

HRESULT GetResourceURL(const WCHAR* wszName, 
					   BOOL fUIDLL, 
					   BSTR* pbstrURL);


void UpdateCommandUI(BOOL fImmediate);

// Brings up the Environment message box, and returns the user's selection
long ShowMessage(
    /* [in] */ LPCTSTR          lpszTitle, 
    /* [in] */ LPCTSTR          lpszMsg, 
    /* [in] */ UINT             nIDHelp     = -1,
    /* [in] */ OLEMSGBUTTON     nButtons    = OLEMSGBUTTON_OK, 
    /* [in] */ OLEMSGDEFBUTTON  nDefButton  = OLEMSGDEFBUTTON_FIRST,
    /* [in] */ OLEMSGICON       nIcon       = OLEMSGICON_CRITICAL, 
    /* [in] */ BOOL             fAlert      = FALSE);

void Append (CString& str, TCHAR* lpsz, int cch);
