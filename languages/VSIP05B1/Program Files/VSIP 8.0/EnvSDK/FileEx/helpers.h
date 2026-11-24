
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

//*****************************************************************************
// Information Contained Herein Is Proprietary and Confidential.
//*****************************************************************************
// Helpers.h
//
// Miscellaneous Utility Functions
//
//*****************************************************************************

#pragma once

//=========================================================================
//                                                       REGISTRATION UTILS

//---------------------------------------------------------------------
// Function:    GetRegRootStrings
//              Contruct strings to be used in _ATL_REGMAP_ENTRY for the 
//              registry root (REGROOTBEGIN and REGROOTEND)
// Parameters: 
//    /* [out] */ BSTR *       pbstrRootBegin, 
//              Replacement string for REGROOTBEGIN. It looks like
//              "NoRemove Software \n{\n NoRemove Microsoft \n{\n NoRemove 
//              VisualStudio \n{\n NoRemove 7.1 \n{\n"
//    /* [out] */ BSTR *       pbstrRootEnd,
//              Replacement string for REGROOTEND. It looks like
//              "\n}\n \n}\n \n}\n \n}\n"
//    /* [in]  */ const WCHAR* pwszRegRoot = NULL)
//              Registry string that will be parsed to generate
//              pbstrRootBegin and pbstrRootEnd.
//              If pwszRegRoot is NULL the default (LREGKEY_VISUALSTUDIOROOT_NOVERSION) 
//              string will be used along with the string specified by 
//              EnvSdk_RegKey environment variable. The Environment SDK 
//              sample code checks for  EnvSdk_RegKey environment variable. 
//              If the variable exists then it is added to the default 
//              L"Software\\Microsoft\\VisualStudio\\" registry string.
//              EnvSdk_RegKey is expected to be of the form "7.x" or "7.xexp".
//              If  EnvSdk_RegKey does not exist the default (LREGKEY_VISUALSTUDIOROOT)
//              string will be used i.e. L"Software\\Microsoft\\VisualStudio\\7.1"
// Returns:     HRESULT
// Notes:
//---------------------------------------------------------------------
HRESULT GetRegRootStrings(
    /* [out] */ BSTR *       pbstrRootBegin, 
    /* [out] */ BSTR *       pbstrRootEnd,
    /* [in]  */ const WCHAR* pwszRegRoot = NULL);


//-------------------------------------------------------------------------
// Function:    GetRegDefaultResourceStrings
//              Contruct strings to be used in _ATL_REGMAP_ENTRY for the 
//              resource dll (RESOURCE_PATH and RESOURCE_DLL)
// Parameters: 
//    /* [out] */ BSTR *      pbstrResDllPath, // optional, can be NULL
//              Replacement string for RESOURCE_PATH. 
//
//    /* [out] */ BSTR *      pbstrResDllName) // optional, can be NULL
//              Replacement string for RESOURCE_DLL. 
//              UI suffix is added to the name of the main dll.
//
// Returns:     HRESULT
// Notes:
//-------------------------------------------------------------------------
HRESULT GetRegDefaultResourceStrings(
    /* [out] */ BSTR * pbstrResDllPath, // optional, can be NULL
    /* [out] */ BSTR * pbstrResDllName);// optional, can be NULL


//                                                       REGISTRATION UTILS
//=========================================================================
