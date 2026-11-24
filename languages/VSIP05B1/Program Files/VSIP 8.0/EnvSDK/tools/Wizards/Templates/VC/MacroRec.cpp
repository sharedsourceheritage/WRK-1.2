
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// MacroRec.cpp : This file contains methods relating to macro recording

#include "stdafx.h"

#include "EdCommon.h"

#include "..\%ProjectName%UI\guids.h"
#include "..\%ProjectName%UI\resource.h"


// Maximum length of text allowed to be output in a single line to
// the macro recorder;
#define	MAXMACRORECORDTEXT	200



/////////////////////////////////////////////////////////////////////////////
// CBscEditorDocument IBscEditor Implementation
//

STDMETHODIMP CBscEditorDocument::get_DTE(_DTE** ppDTE)
{
	return m_srpSiteSP->QueryService(SID_SDTE, IID__DTE, (LPVOID*)ppDTE);
}

STDMETHODIMP CBscEditorDocument::get_Parent(_DTE** ppParent)
{
	return m_srpSiteSP->QueryService(SID_SDTE, IID__DTE, (LPVOID*)ppParent);
}

STDMETHODIMP CBscEditorDocument::get_DefaultTabStop(float* pdVal)
{
	return m_srpTextDocObj->GetDefaultTabStop(pdVal);
}

STDMETHODIMP CBscEditorDocument::put_DefaultTabStop(float dVal)
{
	return m_srpTextDocObj->SetDefaultTabStop(dVal);
}

STDMETHODIMP CBscEditorDocument::get_Range(ITextRange** ppRange)
{
	return m_srpTextDocObj->Range(0, tomForward, ppRange);
}

STDMETHODIMP CBscEditorDocument::get_Selection(ITextSelection** ppSelection)
{
	return m_srpTextDocObj->GetSelection(ppSelection);
}

STDMETHODIMP CBscEditorDocument::FindText(BSTR pStr)
{
	long cFound = 0;
	return m_srpTextRange->FindText(pStr, tomForward, 0, &cFound);
}

STDMETHODIMP CBscEditorDocument::SetText(BSTR pStr)
{
	HRESULT hr;
	CComPtr<ITextSelection>	srpTextSelection;

	m_srpTextDocObj->GetSelection(&srpTextSelection);
	hr = srpTextSelection->TypeText(pStr);
	::SetFocus(m_hwndRTF);
	return hr;
}

// This method merely calls the RTF window selection object method
// and then sets the cursor into the window by setting the focus.
STDMETHODIMP CBscEditorDocument::get_Flags(long* plFlags)
{
	HRESULT hr;
	CComPtr<ITextSelection>	srpTextSelection;

	m_srpTextDocObj->GetSelection(&srpTextSelection);
	hr = srpTextSelection->GetFlags(plFlags);
	::SetFocus(m_hwndRTF);
	return hr;
}

// This method merely calls the RTF window selection object method
// and then sets the cursor into the window by setting the focus.
STDMETHODIMP CBscEditorDocument::put_Flags(long lFlags)
{
	HRESULT hr;
	CComPtr<ITextSelection>	srpTextSelection;

	m_srpTextDocObj->GetSelection(&srpTextSelection);
	hr = srpTextSelection->SetFlags(lFlags);
	::SetFocus(m_hwndRTF);
	return hr;
}

// This method merely calls the RTF window selection object method
// and then sets the cursor into the window by setting the focus.
STDMETHODIMP CBscEditorDocument::TypeText(BSTR pStr)
{
	HRESULT hr;
	CComPtr<ITextSelection>	srpTextSelection;

	m_srpTextDocObj->GetSelection(&srpTextSelection);
	hr = srpTextSelection->TypeText(pStr);
	::SetFocus(m_hwndRTF);
	return hr;
}

// This method merely calls the RTF window selection object method
// and then sets the cursor into the window by setting the focus.
STDMETHODIMP CBscEditorDocument::Cut(void)
{
	HRESULT hr;
	CComPtr<ITextSelection>	srpTextSelection;

	m_srpTextDocObj->GetSelection(&srpTextSelection);
	hr = srpTextSelection->Cut(NULL);
	::SetFocus(m_hwndRTF);
	return hr;
}

// This method merely calls the RTF window selection object method
// and then sets the cursor into the window by setting the focus.
STDMETHODIMP CBscEditorDocument::Copy(void)
{
	HRESULT hr;
	CComPtr<ITextSelection>	srpTextSelection;

	m_srpTextDocObj->GetSelection(&srpTextSelection);
	hr = srpTextSelection->Copy(NULL);
	::SetFocus(m_hwndRTF);
	return hr;
}

// This method merely calls the RTF window selection object method
// and then sets the cursor into the window by setting the focus.
STDMETHODIMP CBscEditorDocument::Paste(void)
{
	HRESULT hr;
	CComPtr<ITextSelection>	srpTextSelection;

	m_srpTextDocObj->GetSelection(&srpTextSelection);
	hr = srpTextSelection->Paste(NULL, 0);
	::SetFocus(m_hwndRTF);
	return hr;
}

// This method merely calls the RTF window selection object method
// and then sets the cursor into the window by setting the focus.
STDMETHODIMP CBscEditorDocument::Delete(long lUnit, long cUnit)
{
	HRESULT hr;
	CComPtr<ITextSelection>	srpTextSelection;

	m_srpTextDocObj->GetSelection(&srpTextSelection);
	hr = srpTextSelection->Delete(lUnit, cUnit, NULL);
	::SetFocus(m_hwndRTF);
	return hr;
}


// This method merely calls the RTF window selection object method
// and then sets the cursor into the window by setting the focus.
STDMETHODIMP CBscEditorDocument::MoveUp(long lUnit, long cUnit, long lExtend)
{
	HRESULT hr;
	CComPtr<ITextSelection>	srpTextSelection;

	m_srpTextDocObj->GetSelection(&srpTextSelection);
	hr = srpTextSelection->MoveUp(lUnit, cUnit, lExtend, NULL);
	::SetFocus(m_hwndRTF);
	return hr;
}

// This method merely calls the RTF window selection object method
// and then sets the cursor into the window by setting the focus.
STDMETHODIMP CBscEditorDocument::MoveDown(long lUnit, long cUnit, long lExtend)
{
	HRESULT hr;
	CComPtr<ITextSelection>	srpTextSelection;

	m_srpTextDocObj->GetSelection(&srpTextSelection);
	hr = srpTextSelection->MoveDown(lUnit, cUnit, lExtend, NULL);
	::SetFocus(m_hwndRTF);
	return hr;
}

// This method merely calls the RTF window selection object method
// and then sets the cursor into the window by setting the focus.
STDMETHODIMP CBscEditorDocument::MoveLeft(long lUnit, long cUnit, long lExtend)
{
	HRESULT hr;
	CComPtr<ITextSelection>	srpTextSelection;

	m_srpTextDocObj->GetSelection(&srpTextSelection);
	hr = srpTextSelection->MoveLeft(lUnit, cUnit, lExtend, NULL);
	::SetFocus(m_hwndRTF);
	return hr;
}

// This method merely calls the RTF window selection object method
// and then sets the cursor into the window by setting the focus.
STDMETHODIMP CBscEditorDocument::MoveRight(long lUnit, long cUnit, long lExtend)
{
	HRESULT hr;
	CComPtr<ITextSelection>	srpTextSelection;

	m_srpTextDocObj->GetSelection(&srpTextSelection);
	hr = srpTextSelection->MoveRight(lUnit, cUnit, lExtend, NULL);
	::SetFocus(m_hwndRTF);
	return hr;
}

// This method merely calls the RTF window selection object method
// and then sets the cursor into the window by setting the focus.
STDMETHODIMP CBscEditorDocument::EndKey(long lUnit, long lExtend)
{
	HRESULT hr;
	CComPtr<ITextSelection>	srpTextSelection;

	m_srpTextDocObj->GetSelection(&srpTextSelection);
	hr = srpTextSelection->EndKey(lUnit, lExtend, NULL);
	::SetFocus(m_hwndRTF);
	return hr;
}

// This method merely calls the RTF window selection object method
// and then sets the cursor into the window by setting the focus.
STDMETHODIMP CBscEditorDocument::HomeKey(long lUnit, long lExtend)
{
	HRESULT hr;
	CComPtr<ITextSelection>	srpTextSelection;

	m_srpTextDocObj->GetSelection(&srpTextSelection);
	hr = srpTextSelection->HomeKey(lUnit, lExtend, NULL);
	::SetFocus(m_hwndRTF);
	return hr;
}



// IVsExtensibleObject

STDMETHODIMP CBscEditorDocument::GetAutomationObject(LPCOLESTR szPropName, IDispatch** ppObject)
{
	return this->QueryInterface(IID_IDispatch, (LPVOID*)ppObject);

	// Note that we could in this case provide the interface
	// from the text document object :-
	//	return m_srpTextDocObj->QueryInterface(IID_IDispatch, (LPVOID*)ppObject);
}


//
// CBscEditorDocument::EstablishRecordState
//
// This function reads the current macro recording state. If recording has
// been switched on it queries for the macro recording service etc. If it
// has been switched off it releases the service etc.
//
// Parameters: None
//
// Returns nothing. Note that if there are any failures detected by this
// function then macro recording is considered to be off and flags are
// set/cleared accordingly.
//
void CBscEditorDocument::EstablishRecordState()
{
  
	HRESULT			hr;

	// We retrieve the macro recording state here.
	GetRecordState();		// Just ignore return value.
	
	// If there is a change in the record state to OFF or ON we must either obtain
	// or release the macro recorder. 
	if (m_eRecordState == VSRECORDSTATE_ON && !m_fMacroRecording)
	{
		// If this QueryService fails we merely ignore the HRESULT and do
		// no macro recording
		if
		(
			SUCCEEDED(hr =	m_srpSiteSP->QueryService
							(
								SID_SVsMacroRecorder,
								IID_IVsMacroRecorder,
								(LPVOID*)&m_srpMacroRecorder
							))
		)
		{
			// Get a GUID for use with the macro recorder. If this fails then
			// we do not attempt to perform macro recording.
			if (SUCCEEDED(CoCreateGuid(&m_guidMacroRecorder)))
			{
				m_fMacroRecording = true;
			}
		}
	}

	// If the macro recording state has been switched off then we can release
	// the service. Note that if the state has become paused we take no action.
	if (m_eRecordState == VSRECORDSTATE_OFF && m_fMacroRecording)
	{
		m_fMacroRecording = false;
		ResetMacroState();
		m_srpMacroRecorder.Release();
	}
}


//
// CBscEditorDocument::RecordCommand
//
// This function provides the interface to the shell macro recording service
// for commands.
//
// Parameters:
//	pguidCmdGroup	Command group - the standard set or the one we've registered.
//	CmdID			Command ID within group
//
void CBscEditorDocument::RecordCommand(const GUID *pguidCmdGroup, DWORD nCmdID)
{
	// If a command does not appear here it will nevertheless be recorded
	// via the macro recording fallback mechanism. The mechanism attempts
	// to record an action when it detects that macro recording is ON but
	// that we did not record a line for a particular command.
	if (pguidCmdGroup == NULL)
	{
		return;
	}
	else if (CMDSETID_StandardCommandSet97 == *pguidCmdGroup)
	{
		switch (nCmdID)
		{

		case cmdidCut:
			// Just issue this as a single command and reset
			// the last macro recorded state
			m_srpMacroRecorder->RecordLine
			(
				L"ActiveDocument.Object.Cut",
				m_guidMacroRecorder
			);
			ResetMacroState();
			break;

		case cmdidCopy:
			// Just issue this as a single command and reset
			// the last macro recorded state
			m_srpMacroRecorder->RecordLine
			(
				L"ActiveDocument.Object.Copy",
				m_guidMacroRecorder
			);
			ResetMacroState();
			break;

		case cmdidPaste:
			// Just issue this as a single command and reset
			// the last macro recorded state
			m_srpMacroRecorder->RecordLine
			(
				L"ActiveDocument.Object.Paste",
				m_guidMacroRecorder
			);
			ResetMacroState();
			break;

		case cmdidDelete:
			// Just issue this as a single command and reset the last macro 
			// recorded state. Note that we also generate a "Delete" command
			// within the WM_KEYDOWN case in method RecordKeyStroke (below)
			// when the backspace or delete key is pressed. However in those
			// cases we coalesce multiple keystrokes and generate a "Delete" 
			// command with parameters.
			m_srpMacroRecorder->RecordLine
			(
				L"ActiveDocument.Object.Delete",
				m_guidMacroRecorder
			);
			ResetMacroState();
			break;
		}
	}
}


//
// CBscEditorDocument::RecordKeyStroke
//
// This function provides the interface to the shell macro recording service
// for window keystrokes.
//
// Parameters:
//	msg					Window message (e.g. WM_CHAR)
//	wParam				First message parameter
//	lParam				Second message parameter
// See CallWindowProc in MSDN for more details of the message parameters.
//
void CBscEditorDocument::RecordKeyStroke(UINT msg, WPARAM wParam, LPARAM lParam)
{
  USES_CONVERSION;

	CComBSTR			bstrMacro;		// Complete macro text line we build up.
	wchar_t				szChar[2] = {0, L'\0'};
	BOOL				fShift;			// Shift key state
	BOOL				fCtrl;			// Control key state


	switch(msg)
	{
	case WM_CHAR:
		szChar[0] = (wchar_t)wParam;

		// If the previous character received was a multibyte
		// character leading byte then we convert it and the
		// bytes we have just received to a wide character and
		// reset the stored flag. then we continue to process
		// the converted character. If the character received
		// is the leading byte of a multibyte character we
		// merely store it and set the flag.
		if (LeadByteFlagIsSet())
		{
			m_szMultiByteString[1] = (char)wParam;
			MultiByteToWideChar(CP_ACP, MB_PRECOMPOSED, m_szMultiByteString, 2, szChar, 1);
			ResetLeadByteFlag();
		}
		else
		{
			if (isleadbyte((int)wParam))
			{
				m_szMultiByteString[0] = (char)wParam;
				SetLeadByteFlag();
			}
		}

		// Deal with standard characters, newline and tab.
		// Note that we only deal with newline and tab here 
		// because in the text object model (tom) they are
		// merely characters. We could handle then in WM_KEYDOWN
		// and we would do so if they were not treated as text
		// by the text object model.
		// Note also that under some circumstances we receive a 0x7f
		// which we must avoid processing.
		// Note also we do no processing if the character received is
		// the lead byte of a multibyte character - we must wait for 
		// the trailing byte and then convert it.
		if
		(
			!LeadByteFlagIsSet()
			&&
			(
				(wParam >= 0x20 && wParam <= 0x7e) 
				||
				wParam > 0x7f
				||
				wParam == VK_RETURN
				||
				wParam == VK_TAB
			)
		)
		{
			bstrMacro.Append(L"ActiveDocument.Object.TypeText \"");

			// If the last command emitted was a text command, this object
			// was the last text emitter and the amount of text output is not
			// equal to the maximum then we append the character to the
			// previous character(s) and replace the last line sent. If both
			// these conditions are not fulfilled we initialise the buffer, set
			// the last macro state and record a new line.
			if
			(
				eLastMacroText == GetMacroState() 
				&& 
				ObjectIsLastMacroEmitter()
				&&
				m_bstrText.Length() < MAXMACRORECORDTEXT
			)
			{
				m_bstrText.Append(szChar);
				bstrMacro.AppendBSTR(m_bstrText);
				bstrMacro.Append(L"\"");
				m_srpMacroRecorder->ReplaceLine(bstrMacro.m_str, m_guidMacroRecorder);
			}
			else
			{
				m_bstrText.Empty();
				m_bstrText.Append(szChar);
				bstrMacro.AppendBSTR(m_bstrText);
				bstrMacro.Append(L"\"");
				m_srpMacroRecorder->RecordLine(bstrMacro.m_str, m_guidMacroRecorder);
				SetMacroState(eLastMacroText);
			}
		}
		break;

	case WM_KEYDOWN:
		// Obtain the control and shift keys as they modify a number of the
		// commands dealt with here. 
		fShift = GetKeyState(VK_SHIFT) & 0x8000 ? true : false;
		fCtrl = GetKeyState(VK_CONTROL) & 0x8000 ? true : false;

		// Switch on the virtual key. Note that in a number of cases we
		// batch the commands. Note also that a number of commands are
		// modified by the shift and/or the control key.
		switch(wParam)
		{
		case VK_BACK:	// BackSpace key
			// Note that the Shift Key does not affect this command
			if (fCtrl) 
				RecordDelete(eLastMacroBackSpaceWord, true, L"tomWord");
			else
				RecordDelete(eLastMacroBackSpaceChar, true, L"tomCharacter");
			break;

		case VK_DELETE:	// Delete key
			// Note that the Shift Key completely disables this command
			if (!fShift)
			{
				if (fCtrl) 
					RecordDelete(eLastMacroDeleteWord, false, L"tomWord");
				else
					RecordDelete(eLastMacroDeleteChar, false, L"tomCharacter");
			}
			break;

		case VK_LEFT:	// Left Arrow
			// Shift Key indicates selection, Control Key indicates words instead of characters
			if (fShift)
			{
				if (fCtrl) 
					RecordMove(eLastMacroLeftArrowWordSel, L"Left", L"tomWord", L"tomExtend");
				else
					RecordMove(eLastMacroLeftArrowCharSel, L"Left", L"tomCharacter", L"tomExtend");
			}
			else
			{
				if (fCtrl) 
					RecordMove(eLastMacroLeftArrowWord, L"Left", L"tomWord", L"tomMove");
				else
					RecordMove(eLastMacroLeftArrowChar, L"Left", L"tomCharacter", L"tomMove");
			}
			break;

		case VK_RIGHT:	// Right Arrow
			// Shift Key indicates selection, Control Key indicates words instead of characters
			if (fShift)
			{
				if (fCtrl) 
					RecordMove(eLastMacroRightArrowWordSel, L"Right", L"tomWord", L"tomExtend");
				else
					RecordMove(eLastMacroRightArrowCharSel, L"Right", L"tomCharacter", L"tomExtend");
			}
			else
			{
				if (fCtrl) 
					RecordMove(eLastMacroRightArrowWord, L"Right", L"tomWord", L"tomMove");
				else
					RecordMove(eLastMacroRightArrowChar, L"Right", L"tomCharacter", L"tomMove");
			}
			break;

		case VK_UP:		// Up Arrow
			// Shift Key indicates selection, Control Key indicates paragraphs instead of lines
			if (fShift)
			{
				if (fCtrl) 
					RecordMove(eLastMacroUpArrowParaSel, L"Up", L"tomParagraph", L"tomExtend");
				else
					RecordMove(eLastMacroUpArrowLineSel, L"Up", L"tomLine", L"tomExtend");
			}
			else
			{
				if (fCtrl) 
					RecordMove(eLastMacroUpArrowPara, L"Up", L"tomParagraph", L"tomMove");
				else
					RecordMove(eLastMacroUpArrowLine, L"Up", L"tomLine", L"tomMove");
			}
			break;

		case VK_DOWN:		// Down Arrow
			// Shift Key indicates selection, Control Key indicates paragraphs instead of lines
			if (fShift)
			{
				if (fCtrl) 
					RecordMove(eLastMacroDownArrowParaSel, L"Down", L"tomParagraph", L"tomExtend");
				else
					RecordMove(eLastMacroDownArrowLineSel, L"Down", L"tomLine", L"tomExtend");
			}
			else
			{
				if (fCtrl) 
					RecordMove(eLastMacroDownArrowPara, L"Down", L"tomParagraph", L"tomMove");
				else
					RecordMove(eLastMacroDownArrowLine, L"Down", L"tomLine", L"tomMove");
			}
			break;

		case VK_PRIOR:		// Page Up
		case VK_NEXT:		// Page Down
			// We can handle these keys together because we have decided not to
			// batch these commands but to issue them individually.
			bstrMacro.Append(L"ActiveDocument.Object.Move");
			if (wParam == VK_PRIOR)
				bstrMacro.Append(L"Up ");
			else
				bstrMacro.Append(L"Down ");
			if (fCtrl)
				bstrMacro.Append(L"tomWindow, 1, ");
			else
				bstrMacro.Append(L"tomScreen, 1, ");
			if (fShift)
				bstrMacro.Append(L"tomExtend");
			else
				bstrMacro.Append(L"tomMove");
			m_srpMacroRecorder->RecordLine(bstrMacro.m_str, m_guidMacroRecorder);
			ResetMacroState();
			break;

		case VK_END:		// End Key
		case VK_HOME:		// Home Key
			// We can handle these keys together because we have decided not to
			// batch these commands but to issue them individually.
			bstrMacro.Append(L"ActiveDocument.Object.");
			if (wParam == VK_END)
				bstrMacro.Append(L"EndKey ");
			else
				bstrMacro.Append(L"HomeKey ");
			if (fCtrl)
				bstrMacro.Append(L"tomStory, ");
			else
				bstrMacro.Append(L"tomLine, ");
			if (fShift)
				bstrMacro.Append(L"tomExtend");
			else
				bstrMacro.Append(L"tomMove");
			m_srpMacroRecorder->RecordLine(bstrMacro.m_str, m_guidMacroRecorder);
			ResetMacroState();
			break;

		case VK_INSERT:		// Insert Key
			// Note that the Control Key completely disables this command.
			// Note also that the Insert Key together with the Shift Key
			// actually generates a WM_PASTE message rather than a WM_KEYDOWN
			if (!fCtrl)
			{
				m_srpMacroRecorder->RecordLine
				(
					L"ActiveDocument.Object.Flags =  ActiveDocument.Object.Flags Xor tomSelOvertype",
					m_guidMacroRecorder
				);
				ResetMacroState();
			}

			break;

		default:
			// Note that VK_RETURN and VK_TAB are handled in the WM_CHAR message
			// case rather than in the WM_KEYDOWN case.
			break;
		}
		break;

	default:
		break;
	}
}

//
// CBscEditorDocument::RecordDelete
//
// This function generates a delete message and passes it to the macro recorder
// for the BackSpace and Delete keys.
//
// Parameters:
//	eState				Command type
//	fNegate				If set to TRUE then the command count is to be
//						negated before outputting the macro text.
//	pszWordOrChar		Contains either "tomWord" or "tomCharacter"
//
void CBscEditorDocument::RecordDelete(LastMacro eState, BOOL fNegate, LPCWSTR pszWordOrChar)
{
	CComBSTR		bstrMacro;			// Complete macro text line we build up.
	BOOL			fReplace = true;	// Call ReplaceLine if flag remains TRUE
	wchar_t			string[12];			// Area to hold result of _ltow

	// We first check if the the previous command was the same as the current
	// and if this object emitted the last macro line. If not then we reset
	// the macro state and utimately call RecordLine if both are true we wiil
	// call ReplaceLine.
	if 
	(
		eState != GetMacroState() 
		|| 
		!ObjectIsLastMacroEmitter()
	)
	{
		ResetMacroState();
		fReplace = false;
	}
	IncrMacroCommandCount();

	// Convert command count to string
	if (fNegate)
	{
		_ltow(-GetMacroCommandCount(), string, 10);
	}
	else
	{
		_ltow(GetMacroCommandCount(), string, 10);
	}

	// Set up the text message
	bstrMacro.Append(L"ActiveDocument.Object.Delete ");
	bstrMacro.Append(pszWordOrChar);
	bstrMacro.Append(L", ");
	bstrMacro.Append(string);
	if (fReplace)
	{
		m_srpMacroRecorder->ReplaceLine(bstrMacro.m_str, m_guidMacroRecorder);
	}
	else
	{
		m_srpMacroRecorder->RecordLine(bstrMacro.m_str, m_guidMacroRecorder);
		SetMacroState(eState);
	}
	bstrMacro.Empty();
}

//
// CBscEditorDocument::RecordMove
//
// This function generates a move (up, down, left or right) message and passes it
// to the macro recorder for the arrow keys.
//
// Parameters:
//	eState				Command type
//	pszDir				Direction text (UP, DOWN, LEFT, RIGHT)
//	pszScope			Contains "tomWord", "tomCharacter", "tomParagraph" or "tomLine"
//	pszExtOrMove		Contains either "tomExtend" or "tomMove"
//
void CBscEditorDocument::RecordMove
(
	LastMacro eState,
	LPCWSTR pszDir,
	LPCWSTR pszScope,
	LPCWSTR pszExtOrMove
)
{
	CComBSTR		bstrMacro;			// Complete macro text line we build up.
	BOOL			fReplace = true;	// Call ReplaceLine if flag remains TRUE
	wchar_t			string[12];			// Area to hold result of _ltow

	// We first check if the the previous command was the same as the current
	// and if this object emitted the last macro line. If not then we reset
	// the macro state and utimately call RecordLine if both are true we wiil
	// call ReplaceLine.
	if 
	(
		eState != GetMacroState() 
		|| 
		!ObjectIsLastMacroEmitter()
	)
	{
		ResetMacroState();
		fReplace = false;
	}
	IncrMacroCommandCount();

	// Convert command count to string
	_ltow(GetMacroCommandCount(), string, 10);

	// Set up the text message
	bstrMacro.Append(L"ActiveDocument.Object.Move");
	bstrMacro.Append(pszDir);
	bstrMacro.Append(L" ");
	bstrMacro.Append(pszScope);
	bstrMacro.Append(L", ");
	bstrMacro.Append(string);
	bstrMacro.Append(L", ");
	bstrMacro.Append(pszExtOrMove);
	if (fReplace)
	{
		m_srpMacroRecorder->ReplaceLine(bstrMacro.m_str, m_guidMacroRecorder);
	}
	else
	{
		m_srpMacroRecorder->RecordLine(bstrMacro.m_str, m_guidMacroRecorder);
		SetMacroState(eState);
	}
	bstrMacro.Empty();
}



