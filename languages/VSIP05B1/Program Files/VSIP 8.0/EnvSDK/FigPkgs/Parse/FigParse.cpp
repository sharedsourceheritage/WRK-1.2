
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// FigParse.cpp : Implementation of CFigParse
#include "stdafx.h"
#include "FigParse.h"
#include <comdef.h>

#include <iostream>
#include <string>
using namespace std;


BOOL CheckParameters(
    /* [in]      */ LPFIGMARK        pMks,
    /* [in]      */ int             cParams,
    /* [in]      */ wstring         sLine,
    /* [in, out] */ wstring&        sError,
    /* [out]     */ unsigned int *    pnStartPosition,
    /* [out]     */ unsigned int *    pnEndPosition)
{
    for (int i = 0; i < cParams; i++)
    {
        ULONG ulStart = pMks[i].nStart;
        ULONG ulEnd   = pMks[i].nEnd;
        wstring sParam(sLine, ulStart, ulEnd - ulStart + 1);
        long lParValue = _wtol(sParam.c_str());
        if ( (lParValue < FIG_PARAM_MIN) ||  (lParValue > FIG_PARAM_MAX))
        {
            // we have a problem here
            sError += L" : Incorrect Parameter (must be between ";
            WCHAR wszValue[20];
            _ultow(FIG_PARAM_MIN, wszValue, 10);
            sError += wszValue;
            sError += L" and ";
            _ultow(FIG_PARAM_MAX, wszValue, 10);
            sError += wszValue;
            sError += L")";
            *pnStartPosition = ulStart;
            *pnEndPosition   = ulEnd + 1;
            return FALSE;
        }
    }
    // everything is OK;
    return TRUE; 
}

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
//              EnvSdk_RegKey is expected to be of the form "7.x" or "7.xexp".
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

    const ULONG cchBuffer = _MAX_PATH;
    WCHAR wszRegistrationRoot[cchBuffer];
    DWORD cchFreeBuffer = cchBuffer - 1;
    if (pwszRegRoot)
    {
        if ( wcslen(pwszRegRoot) >= cchFreeBuffer )
            return E_INVALIDARG;
        wcsncpy(wszRegistrationRoot, pwszRegRoot, cchFreeBuffer);
    }
    else
    {
        DWORD cchDefRegRoot = lstrlenW(LREGKEY_VISUALSTUDIOROOT_NOVERSION) + 1;
        if (cchDefRegRoot >= cchFreeBuffer)
            return HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER);

        wcsncpy(wszRegistrationRoot, LREGKEY_VISUALSTUDIOROOT_NOVERSION, cchFreeBuffer);
        cchFreeBuffer -= lstrlenW(LREGKEY_VISUALSTUDIOROOT_NOVERSION);
        wcsncat(wszRegistrationRoot, L"\\", cchFreeBuffer);
        --cchFreeBuffer;
        
        // this is Environment SDK specific
        // we check for  EnvSdk_RegKey environment variable to
        // determine where to register
        DWORD cchEnvVarRead = GetEnvironmentVariableW(
            /* LPCTSTR */ L"EnvSdk_RegKey",               // environment variable name
            /* LPTSTR  */ &wszRegistrationRoot[cchDefRegRoot],// buffer for variable value
            /* DWORD   */ cchFreeBuffer);// size of buffer
        if (cchEnvVarRead >= cchFreeBuffer)
            return E_UNEXPECTED;
        // If the environment variable does not exist then we must use 
        // LREGKEY_VISUALSTUDIOROOT which has the version number.
        if (0 == cchEnvVarRead)
            wcsncpy(wszRegistrationRoot, LREGKEY_VISUALSTUDIOROOT, cchBuffer-1);
    }
       
    CComBSTR cbstrRootBegin;
    CComBSTR cbstrRootEnd;
    
    // Make sure the string ends in backslash to simplify loop 
    // for processing backslashes.
    int len = (int)wcslen(wszRegistrationRoot);
    if(wszRegistrationRoot[len - 1] != L'\\')
        wcscat(wszRegistrationRoot, L"\\");

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

/////////////////////////////////////////////////////////////////////////////
// CFigParse

CFigParse::CFigParse()
{
    ATLTRACE( TEXT( "Constructing CFigParse: 0x%X\n" ), this );
}

CFigParse::~CFigParse()
{
    ATLTRACE( TEXT( "Destructing CFigParse: 0x%X\n" ), this );
}


/* static */ 
HRESULT WINAPI CFigParse::UpdateRegistry(
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
    CComBSTR cbstrCLSID_FigParse(CLSID_FigParse);
    if (!cbstrCLSID_FigParse) 
        return E_OUTOFMEMORY;

    // now set the atl reg map
    _ATL_REGMAP_ENTRY rgMap[] =
    {
        // NOTE: these names cannot be longer than 30 characters. 
        {L"REGROOTBEGIN",                   cbstrRegRootBegin},
        {L"REGROOTEND",                     cbstrRegRootEnd},
        {L"CLSID_FigParse",                 cbstrCLSID_FigParse},
        {NULL, NULL}
    };

    return _AtlModule.UpdateRegistryFromResourceS(IDR_FIGPARSE, bRegister, rgMap);
}


STDMETHODIMP CFigParse::Line(
            /* [in] */        LPOLESTR    szLine,        // line to parse (wide char string)
            /* [in, out] */ long*        pcnMarks,    // [in] max number of mark structs, [out] number of marks found
            /* [in, out] */ LPFIGMARK*    prgMarks,    // array of mark structs
            /* [out] */        BSTR*        bstrError ) // possible error, SysFreeString if not null
{
    HRESULT hr = NOERROR;

    try {
        // check input pointers
        if (szLine == NULL || pcnMarks == NULL || prgMarks == NULL)
            return E_INVALIDARG;

        // locals for parsing
        unsigned int        cnCurMarks = 0;
        unsigned int        cnMaxMarks = *pcnMarks;
        LPFIGMARK    pMks = *prgMarks;

        // set [out] values
        *pcnMarks = 0;
        *bstrError = NULL;

        // these are STL basic_strings
        wstring sCommand        = L"draw";
        wstring sTypeArror        = L"arrow";
        wstring sTypeCircle        = L"circle";
        wstring sTypeRectangle    = L"rectangle";
        wstring sParameters        = L"0123456789";
        wstring sComment        = L"'";
        wstring sWhiteSpace        = L" '";    // start of comment also considered whitespace
        wstring sLine            = szLine;

        // valid string and array count ?
        if (sLine.length() == 0 || cnMaxMarks == 0 || pMks == NULL)
            return E_INVALIDARG;

        // set whitespace to ' '; remove invalid chars; make input string all lower case
        unsigned int    nWhiteStart = 0;
        for (unsigned int nCharPos = 0; nCharPos < sLine.length(); nCharPos++)
        {
            if (iswspace( sLine[nCharPos] ))        // change tabs etc. to spaces
            {
                sLine[nCharPos] = ' ';
                continue;    // don't increment nWhiteStart
            }
            else if (!iswprint( sLine[nCharPos] ))    // invalid chars are '?'
                sLine[nCharPos] = '?';
            else if (iswupper( sLine[nCharPos] ))    // all lower case
                sLine[nCharPos] = towlower( sLine[nCharPos] );
            nWhiteStart = nCharPos + 1;
        }

        // remove any trailing white space
        if (nWhiteStart < nCharPos)
                sLine.resize( nWhiteStart );

        unsigned int        nPosition = 0;
        unsigned int        nStartPosition = 0;
        unsigned int        nEndPosition = 0;
        // break the string into tokens
        while (nPosition != sLine.npos)
        {
            nPosition = (unsigned int)sLine.find_first_of( sWhiteSpace, nStartPosition );
            if (cnCurMarks < cnMaxMarks)
            {
                // ignore leading space
                if (nPosition == nStartPosition)
                {
                    // test for comment
                    if (sLine.compare( nStartPosition, sComment.length(), sComment ))
                    {
                        ++nStartPosition;
                        continue;  // check next char
                    }
                    // comment makes the whole rest of the line the last token
                    else
                    {  
                        pMks[cnCurMarks].eTokenType = eComment;  
                        pMks[cnCurMarks].nStart = nStartPosition;
                        pMks[cnCurMarks].nEnd = (ULONG)sLine.length() - 1;
                        ++cnCurMarks;
                        break;  // out of the while loop
                    }
                }
                // process unknown tokens
                pMks[cnCurMarks].eTokenType = eUnknown;  // invalid type for now
                pMks[cnCurMarks].nStart = nStartPosition;
                if (nPosition != sLine.npos)
                    pMks[cnCurMarks].nEnd = nPosition - 1;
                else
                    pMks[cnCurMarks].nEnd = (ULONG)sLine.length() - 1;
                ++cnCurMarks;
                nStartPosition = nPosition;  // start at whitespace char (in case of "'")
            }
            else 
                break;  // out of the while loop
        }
        *pcnMarks = cnCurMarks;  // [out] total mark count

        // search for known tokens
        cnCurMarks = 0;
        wstring    sTmpToken;
        FIGTYPE    eTmpType;
        while (cnCurMarks < (unsigned int)*pcnMarks)
        {
            // only check tokens marked as unknown
            if (pMks[cnCurMarks].eTokenType != eUnknown)
            {
                ++cnCurMarks;
                continue;  // while loop with next mark struct
            }
            // check for the easy tokens
            for (unsigned int cToken = 0; cToken < 4; cToken++)
            {
                switch (cToken)
                {
                case 0:  sTmpToken = sCommand;  eTmpType = eCommand;  break;
                case 1:  sTmpToken = sTypeArror;  eTmpType = eType;  break;
                case 2:  sTmpToken = sTypeCircle;  eTmpType = eType;  break;
                case 3:  sTmpToken = sTypeRectangle;  eTmpType = eType;  break;
                }
                // check length
                if (sTmpToken.length()
                 != pMks[cnCurMarks].nEnd - pMks[cnCurMarks].nStart + 1)
                {
                    continue;  // for loop to check next token type
                }
                // compare text
                if (!sLine.compare( pMks[cnCurMarks].nStart,
                 sTmpToken.length(), sTmpToken ))
                {  
                    pMks[cnCurMarks].eTokenType = eTmpType;  
                    break;  // out of for loop
                }
            }
            ++cnCurMarks;
        }

        // now find the last tokens: Parameters
        cnCurMarks = 0;
        while (cnCurMarks < (unsigned int)*pcnMarks)
        {
            // only check tokens marked as unknown
            if (pMks[cnCurMarks].eTokenType != eUnknown)
            {
                ++cnCurMarks;
                continue;  // while loop with next mark struct
            }

            // parameters are a group of numbers
            unsigned int        nLength = 0;
            nPosition = 0;
            nStartPosition = pMks[cnCurMarks].nStart;
            while (nPosition != sLine.npos)
            {
                nPosition = (ULONG)sLine.find_first_of( sParameters, nStartPosition );
                // step over the digits in the parameter
                if (nPosition == nStartPosition)
                {  
                    ++nStartPosition;
                    ++nLength;
                    continue;  // check next char
                }
                // check length
                if( nLength
                 == pMks[cnCurMarks].nEnd - pMks[cnCurMarks].nStart + 1)
                {
                    pMks[cnCurMarks].eTokenType = eParameter;  // found one
                }
                break;  // out of inner while loop
            }
            ++cnCurMarks;
        }

        // check the syntax, if bad, add an error token with the first error location
        if ((unsigned int)*pcnMarks < cnMaxMarks)    // enough room for one more ?
        {
            BOOL    fError = true;  // pessimistically assume it's wrong :(
            nStartPosition = 0;
            nEndPosition = (ULONG)sLine.length();
            wstring sError = L"Syntax Error";

            // it is a syntax error to have any unknown tokens
            //
            BOOL fUnknown = false;
            cnCurMarks = 0;
            while (cnCurMarks < (unsigned int)*pcnMarks)
            {
                if (pMks[cnCurMarks].eTokenType == eUnknown)
                {
                    fUnknown = true;
                    break;  // out of while loop
                }
                ++cnCurMarks;
            }
            if (fUnknown)
            {
                nStartPosition = pMks[cnCurMarks].nStart;
                nEndPosition = pMks[cnCurMarks].nEnd + 1;
                sError += L" : Invalid Token";
            }
            // correct syntax would be the following tokens and order
            //   0 : Comment
            //
            else if (*pcnMarks > 0 && pMks[0].eTokenType == eComment)
            {
                fError = false;
            }
            // correct syntax would be the following tokens and order
            //   0 : Command
            //   1 : Type        : 'Circle'
            //   2 : Parameter 1
            //   3 : Parameter 2
            //   4 : Parameter 3 : only 3 params for Circle Type
            //  [5]: Comment [optional]
            //
            // correct syntax would be the following tokens and order
            //   0 : Command
            //   1 : Type        : 'Rectangle' or 'Arrow'
            //   2 : Parameter 1
            //   3 : Parameter 2
            //   4 : Parameter 3 
            //   5 : Parameter 4 : 4 params for Rectangle and Arrow Types
            //  [6]: Comment [optional]
            //
            else if (*pcnMarks > 0 && pMks[0].eTokenType != eCommand)
            {
                nStartPosition = pMks[0].nStart;  // position of the error
                nEndPosition = pMks[0].nEnd + 1;
                sError += L" : Missing Command (e.g. draw)";
            }
            else if (*pcnMarks == 1 && pMks[0].eTokenType == eCommand)
            {
                nStartPosition = pMks[0].nEnd + 1;
                nEndPosition = pMks[0].nEnd + 1;
                sError += L" : Missing Type (e.g. arrow, circle or rectangle)";
            }
            else if (*pcnMarks > 1 && pMks[1].eTokenType != eType)
            {
                nStartPosition = pMks[1].nStart;
                nEndPosition = pMks[1].nEnd + 1;
                sError += L" : Missing Type (e.g. arrow, circle or rectangle)";
            }
            else if (*pcnMarks == 2 && pMks[1].eTokenType == eType)
            {
                nStartPosition = pMks[1].nEnd + 1;
                nEndPosition = pMks[1].nEnd + 1;
                sError += L" : Missing First Parameter (e.g. 10)";
            }
            else if (*pcnMarks > 2 && pMks[2].eTokenType != eParameter)
            {
                nStartPosition = pMks[2].nStart;
                nEndPosition = pMks[2].nEnd + 1;
                sError += L" : Missing First Parameter (e.g. 10)";
            }
            else if (*pcnMarks == 3 && pMks[2].eTokenType == eParameter)
            {
                nStartPosition = pMks[2].nEnd + 1;
                nEndPosition = pMks[2].nEnd + 1;
                sError += L" : Missing Second Parameter (e.g. 20)";
            }
            else if (*pcnMarks > 3 && pMks[3].eTokenType != eParameter)
            {
                nStartPosition = pMks[3].nStart;
                nEndPosition = pMks[3].nEnd + 1;
                sError += L" : Missing Second Parameter (e.g. 20)";
            }
            else if (*pcnMarks == 4 && pMks[3].eTokenType == eParameter)
            {
                nStartPosition = pMks[3].nEnd + 1;
                nEndPosition = pMks[3].nEnd + 1;
                sError += L" : Missing Third Parameter (e.g. 30)";
            }
            else if (*pcnMarks > 4 && pMks[4].eTokenType != eParameter)
            {
                nStartPosition = pMks[4].nStart;
                nEndPosition = pMks[4].nEnd + 1;
                sError += L" : Missing Third Parameter (e.g. 30)";
            }
            else
            {
                for (int cToken = 0; cToken < 3; cToken++)
                {
                    switch (cToken)
                    {
                    case 0:  sTmpToken = sTypeCircle;  break;
                    case 1:  sTmpToken = sTypeArror;  break;
                    case 2:  sTmpToken = sTypeRectangle;  break;
                    }
                    // compare text
                    if (!sLine.compare( pMks[1].nStart, 
                     sTmpToken.length(), sTmpToken ))
                    {  
                        if (cToken == 0)  // Circle Type, look for 3 params
                        {
                            if (pMks[2].eTokenType == eParameter
                             && pMks[3].eTokenType == eParameter
                             && pMks[4].eTokenType == eParameter)
                            {
                                if ( (*pcnMarks > 5) && (pMks[5].eTokenType != eComment) )
                                {
                                    nStartPosition = pMks[5].nStart;
                                    nEndPosition = pMks[5].nEnd + 1;
                                    sError += L" : Invalid Token";
                                }
                                else
                                {
                                    BOOL fGoodParams = CheckParameters(
                                        /* [in]      LPFIGMARK         pMks*/ &pMks[2],
                                        /* [in]      int             cParams*/ 3,
                                        /* [in]      wstring         sLine*/  sLine,
                                        /* [in, out] wstring&        sError*/ sError,
                                        /* [out]     unsigned int *    pnStartPosition*/ &nStartPosition,
                                        /* [out]     unsigned int *    pnEndPosition*/ &nEndPosition);
                                    if ( fGoodParams )
                                        fError = false;  // syntax is correct :)
                                }
                            }
                        }
                        else  // Rectangle or Arrow Type, look for 4 params
                        {
                            if (*pcnMarks == 5 && pMks[4].eTokenType == eParameter)
                            {
                                nStartPosition = pMks[4].nEnd + 1;
                                nEndPosition = pMks[4].nEnd + 1;
                                sError += L" : Missing Fourth Parameter (e.g. 40)";
                            }
                            else if (*pcnMarks > 5
                             && pMks[2].eTokenType == eParameter
                             && pMks[3].eTokenType == eParameter
                             && pMks[4].eTokenType == eParameter
                             && pMks[5].eTokenType == eParameter)
                            {
                                if ( (*pcnMarks > 6) && (pMks[6].eTokenType != eComment) )
                                {
                                    nStartPosition = pMks[6].nStart;
                                    nEndPosition = pMks[6].nEnd + 1;
                                    sError += L" : Invalid Token";
                                }
                                else
                                {
                                    BOOL fGoodParams = CheckParameters(
                                        /* [in]      LPFIGMARK         pMks*/ &pMks[2],
                                        /* [in]      int             cParams*/ 4,
                                        /* [in]      wstring         sLine*/  sLine,
                                        /* [in, out] wstring&        sError*/ sError,
                                        /* [out]     unsigned int *    pnStartPosition*/ &nStartPosition,
                                        /* [out]     unsigned int *    pnEndPosition*/ &nEndPosition);
                                    if ( fGoodParams )
                                        fError = false;  // syntax is correct :)
                                }
                            }
                            else
                            {
                                nStartPosition = pMks[5].nStart;
                                nEndPosition = pMks[5].nEnd + 1;
                                sError += L" : Missing Fourth Parameter (e.g. 40)";
                            }
                        }
                        break;  // out of for loop
                    }
                }
            }

            if (fError)
            {
                // yack !
                pMks[*pcnMarks].eTokenType = eError;  
                pMks[*pcnMarks].nStart = nStartPosition;  // where was the error
                pMks[*pcnMarks].nEnd = nEndPosition;

                ++(*pcnMarks);  // [out] total mark count

                // return the BSTR error string
                *bstrError = SysAllocString( sError.c_str() );
            }
        }
        else
            hr = E_OUTOFMEMORY;  // not enough room in token struct passed in
    }
    catch(...)
    {
        hr = E_FAIL;
    }

    return hr;
}


// called to parse a line of text from the buffer
STDMETHODIMP CFigParse::ParseLine( 
    /* [in]  */ IVsTextLines* pIVsTextLines, 
    /* [in]  */ long nLine, 
    /* [out] */ FigLineType *pType, 
    /* [out] */ long *pP1, 
    /* [out] */ long *pP2, 
    /* [out] */ long *pP3, 
    /* [out] */ long *pP4, 
    /* [out] */ BSTR *pbstrComment)
{
    // validate input params && initialize out params
    ExpectedPtrRet(pType); *pType = FigInvalid;
    ExpectedPtrRet(pP1); *pP1 = 0;
    ExpectedPtrRet(pP2); *pP2 = 0;
    ExpectedPtrRet(pP3); *pP3 = 0;
    ExpectedPtrRet(pP4); *pP4 = 0;
    ExpectedPtrRet(pbstrComment); *pbstrComment = NULL;    

    HRESULT     hr = S_OK;
    const int   ciMacFigMarks = 100;
    long        nLineLength;
    CComBSTR    cbstrLine;
    int         iCommentIndex = 0;
    FigLineType flt = FigInvalid;
    CComBSTR    cbstrCmt;
    CComBSTR    cbstrError;
    WCHAR *     wszLine = NULL;

    hr = pIVsTextLines->GetLengthOfLine(nLine, &nLineLength );
    IfFailRet(hr);
    if(nLineLength == 0) 
        return S_OK;

    // Puts the specified span of text into a BSTR; it is the caller's responsibility to free the BSTR.
    hr = pIVsTextLines->GetLineText(
        nLine,            // starting line
        0,                // starting character index within the line (must be <= length of line)
        nLine,            // ending line
        nLineLength,    // ending character index within the line (must be <= length of line)
        &cbstrLine );    // line text, if any
    IfFailRet(hr);
    if(cbstrLine.Length() == 0)
        return S_OK;

    // parse the line
    long ncMarks  = ciMacFigMarks;
    FIGMARK* pMks = new FIGMARK[ncMarks];
    if (pMks == NULL)
    {
        hr = E_OUTOFMEMORY;
        goto OnError;
    }
    memset(pMks, 0, ciMacFigMarks * sizeof(FIGMARK));

    // null terminate the input line for our parser
    wszLine = new WCHAR[nLineLength + 1];
    if (wszLine == NULL)
    {
        hr = E_OUTOFMEMORY;
        goto OnError;
    }
    memset(wszLine, 0, (nLineLength + 1) * sizeof(WCHAR));
    wcsncpy( wszLine, cbstrLine, nLineLength );

    // call the Line method on the parse object
    hr = Line(wszLine, &ncMarks, &pMks, &cbstrError );

    // what type of line ?   base on the parsed tokens
    if( FAILED(hr) || cbstrError != NULL ) 
    {
        // parse failed, so make comment the line text
        *pType = FigInvalid;
        cbstrCmt = wszLine;
        *pbstrComment = cbstrCmt.Copy();  // return comment

        hr = S_OK;
        goto OnError;
    }

    if( pMks[0].eTokenType == eComment ) 
        flt = FigComment;  
    else if ( pMks[1].eTokenType == eType ) 
    {
        WCHAR* pwszTemp = &wszLine[pMks[1].nStart];
        size_t stLength = pMks[1].nEnd - pMks[1].nStart + 1;

        if(!_wcsnicmp(pwszTemp, L"arrow", stLength )  )
            flt = FigArrow;  
        else if( !_wcsnicmp( pwszTemp, L"circle", stLength) )
            flt = FigCircle;  
        else if( !_wcsnicmp( pwszTemp, L"rectangle", stLength) )
            flt = FigRectangle;  
    }

    *pType = flt;

    // did we get a valid line type ?
    if( flt == FigInvalid ) 
    {
        // invalid line, so make comment the line text
        cbstrCmt = wszLine;
        *pbstrComment = cbstrCmt.Copy();  // return comment
        goto OnError;
    }

    if( flt == FigComment ) // it's a comment
    {            
        cbstrCmt = &wszLine[pMks[0].nStart + 1]; // dont save ' mark
        *pbstrComment = cbstrCmt.Copy();        // return comment
        goto OnError;
    } 

    if( pMks[2].eTokenType == eParameter )
        *pP1 = _wtoi( &wszLine[pMks[2].nStart] );        // return parameters
    if( pMks[3].eTokenType == eParameter )
        *pP2 = _wtoi( &wszLine[pMks[3].nStart] );
    if( pMks[4].eTokenType == eParameter )
        *pP3 = _wtoi( &wszLine[pMks[4].nStart] );

    iCommentIndex = 5; // if only 3 params (FigCircle)

    if ( flt != FigCircle ) 
    {
        if( pMks[5].eTokenType == eParameter )
            *pP4 = _wtoi( &wszLine[ pMks[5].nStart] );
        iCommentIndex = 6; // // 4 params
    }

    if( pMks[iCommentIndex].eTokenType == eComment ) 
    {
        cbstrCmt = &wszLine[pMks[iCommentIndex].nStart + 1];        // dont save ' mark
        *pbstrComment = cbstrCmt.Copy();  // return comment
    }

OnError:

    delete[] wszLine;
    delete[] pMks;

    return hr;
}
