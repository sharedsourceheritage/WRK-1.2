
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// Colorizr.h : Declaration of CFigColorizer

#pragma once

/////////////////////////////////////////////////////////////////////////////
// forward declarations
class CVsPackage;
class CFigBufferTaskProvider;
/////////////////////////////////////////////////////////////////////////////
// CFigColorizer

class CFigColorizer :
	public IVsColorizer
{
public:
	CFigColorizer( IFigParse *pIFigParse, CFigBufferTaskProvider* pCFigBufferTaskProvider);
	~CFigColorizer();
	
	BEGIN_INTERFACE
	// *** IUnknown methods **********************************************************
	STDMETHODIMP QueryInterface(REFIID riid, LPVOID FAR* ppvObj);
	STDMETHODIMP_(ULONG) AddRef();
	STDMETHODIMP_(ULONG) Release();

	// *** IVsColorizer methods ******************************************************
	//
	// If this colorizer requires per-line state maintenance, this method
	// should set pfFlag to TRUE, otherwise it should be set to FALSE.  If
	// state maintenance is not required, and editing performance will likely
	// be better.
	STDMETHODIMP GetStateMaintenanceFlag( 
						/* [out] */	BOOL *pfFlag );

	// Start state.  Called only if the colorizer needs state maintenance.
	// Indicates the state in which colorization of the first line of the
	// buffer should start
	STDMETHODIMP GetStartState( 
						/* [out] */	long *piStartState );

	// Colorize the given text.  For each character in the line of text
	// given, a matching index into the colorizer's syntax item array (+1) should
	// be placed in the color index array provided.  The colorizer should
	// start in the state provided, and return its current state (which will
	// be stored and provided as the start state when the following line is
	// colorized).  The index array given is gauranteed to be ONE ELEMENT
	// longer than the number of characters in the line.  This element is
	// used to determine the (background) color of the space to the right of
	// the last character on the line.
	// Color indexes are 1-BASED -- use 0 to specify default text color.
	// pText is NOT null-terminated.  iLength is the length of the line
	// MINUS the end-of-line marker (CR, LF, CRLF pair, or 0 (EOF)), which
	// will be present.
	STDMETHODIMP_(long) ColorizeLine( 
						/* [in] */ 	long iLine,
						/* [in] */ 	long iLength,
						/* [in] */ 	const WCHAR *pText,
						/* [in] */ 	long iState,
						/* [out] */	ULONG *pAttributes );

	// Determine the end-of-line state for the line given.  This method is
	// essentially the same as ColorizeLine, except that the line color data
	// is not required by the editor.  This method is an optimization for
	// cases when the start state for a line is needed but lines above are
	// not being displayed.  If state maintenance is not required by this
	// colorizer, this method will not be called.  Implementations should
	// be as fast as possible to keep peak editor performance.
	STDMETHODIMP_(long) GetStateAtEndOfLine( 
						/* [in] */	long iLine,
						/* [in] */	long iLength,
						/* [in] */	const WCHAR *pText,
						/* [in] */	long iState );

	// The buffer will call this before Release()ing the colorizer so that
	// it can Release() any references it holds on the buffer, thereby
	// breaking the circular reference chain.
	STDMETHODIMP_(void) CloseColorizer( void );


private:
	DWORD m_dwRef;
	BOOL m_fZombie;
	CComPtr<IFigParse> m_srpParse;
	long		m_ncMarks;
	LPFIGMARK	m_pMks;
    CFigBufferTaskProvider* m_pCFigBufferTaskProvider;
};
