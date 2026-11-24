
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#pragma once

/*---------------------------------------------------------
  Localised strings
-----------------------------------------------------------*/
LPCOLESTR GetString  ( in ULONG stringId   );
HRESULT   InitStrings( in HMODULE instance, in const CLSID& clsid );
HRESULT   DoneStrings();
