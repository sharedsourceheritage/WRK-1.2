//-----------------------------------------------------------
// Microsoft Visual Basic
//
// Copyrigtht (c) 1994-2000 Microsoft Corp.
// All Rights Reserved
//
// op_util.h:  declaration of utilities for working with
// IVsOutputWindowPane
//
// NOTE: All functions here are mbcs/unicode compliant.
//       Do NOT add non mbcs/unicdoe compliant functions!
//-----------------------------------------------------------
#if (_MSC_VER > 1000) && !defined(NO_PRAGMA_ONCE)
#pragma once
#endif

#ifndef __OP_UTIL_H
#define __OP_UTIL_H

// Loads nID and wirtes it to the output pane.  Handles null pOutputWndPane
HRESULT OPUtilWriteTextToOutputWindow(IVsOutputWindowPane* pOutputWndPane, UINT nID);

// Formats pszParam into nID and writes it to the output window pane. Handles 
// null pOutputWndPane
HRESULT OPUtilWriteTextToOutputWindow(IVsOutputWindowPane* pOutputWndPane, UINT nID, LPCTSTR pszParam);

// Writes pszText to the output window pane. Handles null pOutputWndPane
HRESULT OPUtilWriteTextToOutputWindow(IVsOutputWindowPane* pOutputWndPane, LPCTSTR pszText);

// Writes the current error info to the output window pane. If nIDPrompt is 
// non-zero, it will format the error text into nIDPrompt. Handles null pOutputWndPane
HRESULT OPUtilWriteErrorInfoToOutputWindow(IVsOutputWindowPane* pOutputWndPane, UINT nIDPrompt);

#endif  // __OP_UTIL_H
