
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#pragma once

HRESULT VariantValueToProperty( in IDebugSymbolProvider* pprovider,
                                in IDebugAddress*        paddress,
                                in IDebugBinder*         pbinder,
                                in DWORD                 radix,
                                in LPCOLESTR             pszExpr,
                                in VARIANT&              value, 
                                out IDebugProperty2**    ppproperty );

HRESULT VariantValueNormalize ( in IDebugBinder* pbinder, in VARIANT& value, out VARIANT* pvarResult );

HRESULT VariantValueCoerce    ( in  IDebugBinder* pbinder, 
                                in  VARTYPE       type, 
                                in  VARIANT&      var, 
                                out VARIANT*      pvarResult );

HRESULT VariantTypeToString   ( in VARIANT& type, out BSTR* pbstrTypeName );
HRESULT VariantValueToString  ( in DWORD radix, in IDebugBinder* pbinder, in VARIANT& value, out BSTR* pbstrValueStr );
