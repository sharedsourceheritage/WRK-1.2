
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// Implementation.cpp : Implementation of CImplementation

#include "stdafx.h"
#include <strsafe.h>
#include "FigCompiler.h"
#include "resource.h"       // main symbols
#include "PrimitiveToken.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Arrow.h"
#include "Implementation.h"
#include "ClassDriver.h"

//=========================================================================
//                                                       REGISTRATION UTILS
//
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
//               EnvSdk_RegKey is expected to be of the form "7.x" or "7.xexp".
//              If  EnvSdk_RegKey does not exist the default (LREGKEY_VISUALSTUDIOROOT)
//              string will be used i.e. L"Software\\Microsoft\\VisualStudio\\7.1"
// Returns:     HRESULT
// Notes:
//---------------------------------------------------------------------
HRESULT GetRegRootStrings(
    /* [out] */ BSTR *       pbstrRootBegin, 
    /* [out] */ BSTR *       pbstrRootEnd,
    /* [in]  */ const WCHAR* pwszRegRoot = NULL)
{
    _ASSERTE(pbstrRootBegin && pbstrRootEnd);
    if(!pbstrRootBegin || !pbstrRootEnd)
        return E_POINTER;

    HRESULT hr = S_OK;

    const ULONG cchBuffer = _MAX_PATH + 1;
    WCHAR wszRegistrationRoot[cchBuffer];
    if (pwszRegRoot)
    {
        hr = StringCchCopy(wszRegistrationRoot, cchBuffer, pwszRegRoot);
        if (FAILED(hr)) return hr;
    }
    else
    {
        hr = StringCchCopy(wszRegistrationRoot, cchBuffer, LREGKEY_VISUALSTUDIOROOT_NOVERSION);
        if (FAILED(hr)) return hr;
        hr = StringCchCat(wszRegistrationRoot, cchBuffer, L"\\");
        if (FAILED(hr)) return hr;
        
        // this is Environment SDK specific
        // we check for  EnvSdk_RegKey environment variable to
        // determine where to register
        DWORD cchDefRegRoot = lstrlenW(LREGKEY_VISUALSTUDIOROOT_NOVERSION) + 1;
        DWORD cchFreeBuffer = cchBuffer - cchDefRegRoot;
        DWORD cchEnvVarRead = GetEnvironmentVariableW(
            /* LPCTSTR */ L"EnvSdk_RegKey",               // environment variable name
            /* LPTSTR  */ &wszRegistrationRoot[cchDefRegRoot],// buffer for variable value
            /* DWORD   */ cchFreeBuffer);// size of buffer
        if (cchEnvVarRead >= cchFreeBuffer)
            return E_UNEXPECTED;
        // If the environment variable does not exist then we must use 
        // LREGKEY_VISUALSTUDIOROOT which has the version number.
        if (0 == cchEnvVarRead)
        {
            hr = StringCchCopy(wszRegistrationRoot, cchBuffer, LREGKEY_VISUALSTUDIOROOT);
            if (FAILED(hr)) return hr;
        }
    }
       
    CComBSTR cbstrRootBegin;
    CComBSTR cbstrRootEnd;
    
    // Make sure the string ends in backslash to simplify loop 
    // for processing backslashes.
    int len = (int)wcslen(wszRegistrationRoot);
    if(wszRegistrationRoot[len - 1] != L'\\')
    {
        hr = StringCchCat(wszRegistrationRoot, cchBuffer, L"\\");
        if (FAILED(hr)) return hr;
    }

    WCHAR * pStart = wszRegistrationRoot;
    WCHAR * pSlash = wcschr(wszRegistrationRoot, L'\\');

    while(pSlash)
    {
        *pSlash = 0;
        hr = cbstrRootBegin.Append(L" NoRemove ");
        if (FAILED(hr)) 
            return hr;

        hr = cbstrRootBegin.Append(pStart);
        if (FAILED(hr)) 
            return hr;

        hr = cbstrRootBegin.Append(L"\n{\n");
        if (FAILED(hr)) 
            return hr;

        hr = cbstrRootEnd.Append(L"\n}\n");
        if (FAILED(hr)) 
            return hr;

        pStart = pSlash + 1;
        pSlash = wcschr(pStart, L'\\');
    }

    *pbstrRootBegin = cbstrRootBegin.Detach();
    *pbstrRootEnd   = cbstrRootEnd.Detach();

    return S_OK;
}
//                                                       REGISTRATION UTILS
//=========================================================================

CImplementation::CImplementation()
{
};
CImplementation::~CImplementation(){};

/* static */ 
HRESULT WINAPI CImplementation::UpdateRegistry(
    /* [in] */ BOOL bRegister)
{
    HRESULT hr = S_OK;

    // get the REGROOTBEGIN and REGROOTEND strings 
    CComBSTR cbstrRegRootBegin;
    CComBSTR cbstrRegRootEnd;
    hr = GetRegRootStrings(&cbstrRegRootBegin, &cbstrRegRootEnd);
    if (FAILED(hr))
        return hr;

    // get the guid strings
    CComBSTR cbstrCLSID_FigCompiler(CLSID_FigCompiler);
    if (!cbstrCLSID_FigCompiler) 
        return E_OUTOFMEMORY;

    // now set the atl reg map
    _ATL_REGMAP_ENTRY rgMap[] =
    {
        // NOTE: these names cannot be longer than 30 characters. 
        {L"REGROOTBEGIN",                   cbstrRegRootBegin},
        {L"REGROOTEND",                     cbstrRegRootEnd},
        {L"CLSID_FigCompiler",              cbstrCLSID_FigCompiler},
        {NULL, NULL}
    };

    return _AtlModule.UpdateRegistryFromResourceS(IDR_FIGCOMPILER, bRegister, rgMap);
}


HRESULT STDMETHODCALLTYPE CImplementation::Compile(
            /* [in] */  BSTR    bstrXOffset,
            /* [in] */  BSTR    bstrYOffset,
            /* [in] */  BSTR    bstrPenColor,
            /* [in] */    BSTR    bstrSourceFile,
            /* [in] */    BSTR    bstrSourcePath,
            /* [in] */    BSTR    bstrOutputDirectory,
            /* [in] */  BOOL    fPropertyChanged,
            /* [in,out] */ BSTR* pbstrErrorString)
{    
    if (!bstrXOffset) return E_POINTER;
    if (!bstrYOffset) return E_POINTER;
    if (!bstrPenColor) return E_POINTER;
    if (!bstrSourceFile) return E_POINTER;
    if (!bstrSourcePath) return E_POINTER;
    if (!bstrOutputDirectory) return E_POINTER;
    if (!pbstrErrorString) return E_POINTER;
    *pbstrErrorString = NULL;

    //If the file could not be compiled, note this 
    //in the returned string

    // This class allows the compiler to automatically deallocate string memory on error exits
    // It is custom to accommodate a standard usage
    class    quickstring
    {
        char *    m_psz;
    public:
        quickstring() : m_psz(NULL) {}
        HRESULT Init(const BSTR bstrIn)
        {
            if (!bstrIn) 
                return E_POINTER;
            size_t    cmb = wcstombs( NULL, bstrIn, NULL);
            if (-1 == cmb)
                return E_FAIL;
            m_psz = new CHAR[++cmb + 1];
            if (!m_psz)
                return E_OUTOFMEMORY;
            cmb = wcstombs(m_psz, bstrIn, cmb);
            if (-1 == cmb)
            {
                delete[] m_psz;
                m_psz = NULL;
                return E_FAIL;
            }
            return S_OK;
        }
        ~quickstring()
        {
            if (NULL != m_psz)
                delete [] m_psz;
        }
        char * str( void )
        {
            return m_psz;
        }
    };

    HRESULT hr = S_OK;

    quickstring    pSourceFile; 
    hr = pSourceFile.Init(bstrSourceFile);
    if (FAILED(hr)) return hr;

    quickstring    pSourcePath;
    hr = pSourcePath.Init(bstrSourcePath);
    if (FAILED(hr)) return hr;
    if (*bstrSourcePath == L'\0')
        return E_INVALIDARG;
    HANDLE hFile = ::CreateFileW(bstrSourcePath, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE)
        hr = HRESULT_FROM_WIN32(GetLastError());
    else
    {
        if (GetFileType(hFile) != FILE_TYPE_DISK)
            hr = HRESULT_FROM_WIN32(ERROR_INVALID_NAME);
        CloseHandle(hFile);
    }
    if (FAILED(hr)) return hr;

    quickstring    pOutputDirectory;
    hr = pOutputDirectory.Init(bstrOutputDirectory);
    if (FAILED(hr)) return hr;

    Driver    driver;
    if (!driver.LoadParser())
    {
        *pbstrErrorString = SysAllocString(L"Could not load the parser used by the compiler\n");
        return E_INVALIDARG;
    }; 

    // If a property has changed, change regardless
    if (!fPropertyChanged)
    {
        if (driver.IsTheFileUpToDate( pSourcePath.str(), pOutputDirectory.str(),
         pSourceFile.str(), pbstrErrorString ))
            return S_OK;
    };

    FILE* input = fopen( pSourcePath.str(), "r" );
    if (NULL == input)
    {
        *pbstrErrorString=SysAllocString(L"Could not open the file\n");
        return E_INVALIDARG;
    };   
    
    driver.SaveFileAndClass( pSourceFile.str() );

    driver.SaveCurrentDirectory( pSourcePath.str() );
    driver.SaveOutputDirectory( pOutputDirectory.str() );
    hr = driver.ParseThisFile( input, pbstrErrorString); 
    fclose( input );

    if (FAILED(hr))
        return hr;

    //driver.ShowTokens();
    driver.BuildClasses(); //Turn raw tokens in to classes
 
    quickstring    xOffset;
    hr = xOffset.Init(bstrXOffset);
    if (FAILED(hr)) return hr;

    quickstring    yOffset;
    hr = yOffset.Init(bstrYOffset);
    if (FAILED(hr)) return hr;

    quickstring    penColor;
    hr = penColor.Init(bstrPenColor);
    if (FAILED(hr)) return hr;

    //Write out all the info
    driver.EmitClasses( xOffset.str(), yOffset.str(), penColor.str(), pbstrErrorString );

    return S_OK;
}
