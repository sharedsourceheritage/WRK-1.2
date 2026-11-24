
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#pragma once

//----------------------------------------------------------------------------
// Use Win32 GetLastError() API to generate an HRESULT.  There are some API's
// that do not set the last error, so we assume out of memory in that case.
//----------------------------------------------------------------------------
inline HRESULT HrLastError()
{
  long lErr = GetLastError();
  return lErr ? HRESULT_FROM_WIN32(lErr) : E_OUTOFMEMORY;
}
