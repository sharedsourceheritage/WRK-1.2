
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#pragma once

HRESULT FieldLookup            ( in  IDebugSymbolProvider* pprovider, 
                                 in  IDebugAddress*        paddress, 
                                 in  LPCOLESTR             pszName, 
                                 out IDebugField**         ppfield );

HRESULT FieldGetType          ( in IDebugField* pfield, out VARIANT* pvarType );
HRESULT FieldGetValue         ( in IDebugField* pfield, out VARIANT* pvarValue );
HRESULT FieldSetValue         ( in IDebugBinder* pbinder, in IDebugField* pfield, in VARIANT& value );

HRESULT FieldCoerceValueType  ( in IDebugBinder*  pbinder,
                                in IDebugField*   pfield, 
                                in VARIANT&       rawValue, 
                                out VARIANT*      pvarValue );

HRESULT FieldGetPrimitiveValue( in IDebugBinder* pbinder, in IDebugField* pfield, out VARIANT* pvarValue );
