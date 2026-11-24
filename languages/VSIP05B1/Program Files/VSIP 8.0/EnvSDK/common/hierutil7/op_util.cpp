//-----------------------------------------------------------
// Microsoft Visual Basic
//
// Copyrigtht (c) 1994-2000 Microsoft Corp.
// All Rights Reserved
//
// op_util.cpp:  implementation of utilities for working with
// IVsOutputWindowPane
//
// NOTE: All functions here are mbcs/unicode compliant.
//       Do NOT add non mbcs/unicdoe compliant functions!
//-----------------------------------------------------------

#include "hu_pch.h"
#include "hu_util.h"
#include "op_util.h"
#include "lutil.h"

//---------------------------------------------------------------------------
// Formats pszParam into nID and writes it to the output window pane. Handles 
// null pOutputWndPane
//---------------------------------------------------------------------------
HRESULT OPUtilWriteTextToOutputWindow(IVsOutputWindowPane* pOutputWndPane, UINT nID)
{
    CString strMsg;
    strMsg.LoadString(nID);

    return OPUtilWriteTextToOutputWindow(pOutputWndPane, strMsg);
}

//---------------------------------------------------------------------------
// Formats pszParam into nID and writes it to the output window pane. Handles 
// null pOutputWndPane
//---------------------------------------------------------------------------
HRESULT OPUtilWriteTextToOutputWindow(IVsOutputWindowPane* pOutputWndPane, UINT nID, 
                                      LPCTSTR pszParam)
{
    CString strText;
    VxFormatString1(strText, nID, pszParam);
    return OPUtilWriteTextToOutputWindow(pOutputWndPane, strText);
}

//---------------------------------------------------------------------------
// Writes pszText to the output window pane. Handles null pOutputWndPane
//---------------------------------------------------------------------------
HRESULT OPUtilWriteTextToOutputWindow(IVsOutputWindowPane* pOutputWndPane, LPCTSTR pszText)
{
    USES_CONVERSION;

    HRESULT hr = E_FAIL;
    if(pOutputWndPane)
        hr = pOutputWndPane->OutputString(T2COLE(pszText));
    return hr;
}

//---------------------------------------------------------------------------
// Writes the current error info to the output window pane. If nIDPrompt is 
// non-zero, it will format the error text into nIDPrompt. Handles null pOutputWndPane
//---------------------------------------------------------------------------
HRESULT OPUtilWriteErrorInfoToOutputWindow(IVsOutputWindowPane* pOutputWndPane, UINT nIDPrompt)
{
    CString strText;
    LUtilGetErrorDescription(strText);

    CString strError;
    if(nIDPrompt)
        VxFormatString1(strError, nIDPrompt, strText);
    else
        strError = strText;

    return OPUtilWriteTextToOutputWindow(pOutputWndPane, strError);
}


