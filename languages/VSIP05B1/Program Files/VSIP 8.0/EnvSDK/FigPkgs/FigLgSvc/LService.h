
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// LService.h : Declaration of CFigLanguageService

#pragma once

/////////////////////////////////////////////////////////////////////////////
// forward declarations
class CVsPackage;

/////////////////////////////////////////////////////////////////////////////
// CFigLanguageService

class CFigLanguageService :
	public IVsLanguageInfo,
	public IVsLanguageContextProvider, 
	public IVsProvideUserContextForObject
{
public:
	CFigLanguageService( CVsPackage *pCVsPkg );
	~CFigLanguageService();
	
	BEGIN_INTERFACE
	// *** IUnknown methods **********************************************************
	STDMETHODIMP QueryInterface(REFIID riid, LPVOID FAR* ppvObj);
	STDMETHODIMP_(ULONG) AddRef();
	STDMETHODIMP_(ULONG) Release();


	// *** IVsLanguageInfo methods ***************************************************
	//
	// Name of language (i.e. "Java", "Visual Basic", "C++", "HTML", etc..)
	STDMETHODIMP GetLanguageName( BSTR *bstrName );

	// File extensions belonging to this language.  If multiple, separate
	// with semicolons (i.e., ".java", ".c;.cpp;.cxx;.h;.hpp;.hxx", etc...)
	STDMETHODIMP GetFileExtensions( BSTR *bstrExtensions );
	
	// Colorizer provision.  This can return an interface on the language
	// info object itself, or farm out new objects (if, for instance, the
	// colorizers for this language need state information on a per-file
	// basis)
	STDMETHODIMP GetColorizer( 
							IVsTextLines *pBuffer,
							IVsColorizer **ppColorizer );
	
	// Provide language with opportunity to add "adornments" to a code window
	STDMETHODIMP GetCodeWindowManager( 
							IVsCodeWindow  *pCodeWin,
							IVsCodeWindowManager  **ppCodeWinMgr );

protected:
    STDMETHOD(InitFigParser)();

//==========================================================================
//                                               User Context Window support
//
//--------------------------------------------------------------------------
//                                            IVsProvideUserContextForObject
//
    //----------------------------------------------------------------------
    // Function:    GetObjectContext
    //              Provides the text editor with the location of the 
    //              language service’s context bag.
    //
    // Parameters: 
    //    /* [in]          */ IUnknown*        punk,
    //              Pointer to the text view (IVsTextView). This allows the 
    //              language service to query into the text view if it needs
    //              additional information about the current selection or 
    //              position in the text document to fill the context bag.
    //
    //    /* [out, retval] */ IVsUserContext** ppctx);
    //              Pointer to the context bag created by the language 
    //              service.  
    //
    // Returns:     HRESULT
    // Notes:
    //----------------------------------------------------------------------
	STDMETHOD(GetObjectContext)(
        /* [in]          */ IUnknown*        punk,
        /* [out, retval] */ IVsUserContext** ppctx);


//--------------------------------------------------------------------------
//                                                IVsLanguageContextProvider
public:
    //----------------------------------------------------------------------
    // Function:    UpdateLanguageContext
    //
    // Parameters: 
	//	    DWORD dwHint,        
    //              ORing of LanguageContextHint enum values
    //              Specifies whether the context is an F1 keyword.
    //
	//	    IVsTextLines *pBuffer,  
    //              Buffer in question
    //
	//	    TextSpan *ptsSelection, 
    //              Relevant range of text
    //
	//	    IVsUserContext *pUC);     
    //              Context to update
    //
    // Returns:     HRESULT
    //
    // Notes:
    //              Return values: 
    //              - S_OK: the implementor has added whatever context 
    //              should be added
    //              - any other success code: forbidden (caller will assert)
    //              - any failure code: means the implementor is "passing" 
    //              on this opportunity to provide context and the text 
    //              editor will fall back to other mechanisms
    //----------------------------------------------------------------------
	STDMETHOD(UpdateLanguageContext)(
		DWORD dwHint,           // ORing of LanguageContextHint enum values
		IVsTextLines *pBuffer,  // buffer in question
		TextSpan *ptsSelection, // relevant range of text
		IVsUserContext *pUC);     // context to update

//                                               User Context Window support
//==========================================================================

private:
	DWORD m_dwRef;
	CVsPackage* m_pCVsPkg;
	BOOL m_fZombie;
	CComPtr<IFigParse> m_srpParse;
	CComPtr<IVsUserContext> m_srpUserCtx;	// user context bag for Related Links window
};

