
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// DataObj.h : Declaration of the CDataObject container object for cut/copy/paste  
//             and D&D operations
//

#pragma once

#define CFORMATETCGET 2		// the number of formats we support
#define SETDefFormatEtc(fe, cf, med)   \
    {\
    (fe).cfFormat=cf;\
    (fe).dwAspect=DVASPECT_CONTENT;\
    (fe).ptd=NULL;\
    (fe).tymed=med;\
    (fe).lindex=-1;\
    };


/////////////////////////////////////////////////////////////////////////////
// forward declarations
class CFigEditLine;


/////////////////////////////////////////////////////////////////////////////
// CDataObject
class CDataObject : 
	public IDataObject,
	public IDropSource
{
public:
	CDataObject( UINT cfFormat, listLines_type &lSelected, IVsTextLines *pVsTextLines );
	CDataObject( FigLineType FType );
	~CDataObject();

	// *** IUnknown methods ***
	STDMETHODIMP QueryInterface( REFIID riid, LPVOID FAR* ppvObj );
	STDMETHODIMP_(ULONG) AddRef();
	STDMETHODIMP_(ULONG) Release();

	// *** IDataObject methods ***
	//
	STDMETHODIMP GetData( FORMATETC *pformatetcIn, 
						  STGMEDIUM *pmedium );
	STDMETHODIMP QueryGetData( FORMATETC *pformatetc );
	STDMETHODIMP GetCanonicalFormatEtc( FORMATETC *pformatectIn,
									    FORMATETC *pformatetcOut );
	STDMETHODIMP SetData( FORMATETC *pformatetc, 
						  STGMEDIUM *pmedium, 
						  BOOL fRelease );
	STDMETHODIMP EnumFormatEtc( DWORD dwDirection, 
								IEnumFORMATETC **ppenumFormatEtc );
	// these IDataObject methods are not used.
	STDMETHODIMP GetDataHere( FORMATETC *pformatetc, 
							  STGMEDIUM *pmedium ) {
		return E_NOTIMPL;	
	}
	STDMETHODIMP DAdvise( FORMATETC *, DWORD, IAdviseSink *, DWORD * ) {
		return OLE_E_ADVISENOTSUPPORTED;
	}
	STDMETHODIMP DUnadvise( DWORD ) {
		return OLE_E_ADVISENOTSUPPORTED;
	}
	STDMETHODIMP EnumDAdvise( IEnumSTATDATA ** ) {
		return OLE_E_ADVISENOTSUPPORTED;
	}

	// *** IDropSource methods ***
	//
	STDMETHODIMP QueryContinueDrag( BOOL fEscapePressed,
									DWORD grfKeyState );
	STDMETHODIMP GiveFeedback( DWORD dwEffect );

	// helper methods
	HRESULT RenderText( LPSTGMEDIUM pSTM );
	HRESULT RenderLines( LPSTGMEDIUM pSTM );


private:
	DWORD					m_dwRef;
	listLines_type			m_SelLines;		// an STL linked list of pointers to CFigEditLine objs
	ULONG					m_cfeGet;		// Arrays for IDataObject::EnumFormatEtc
	FORMATETC				m_rgfeGet[ CFORMATETCGET ];
	UINT					m_cf;
	long					m_PasteAtLine;
	CComPtr<IVsTextLines>	m_srpVsTextLines;
};


/////////////////////////////////////////////////////////////////////////////
// CEnumFormatEtc
//
// IEnumFORMATETC object that is created from
// ::EnumFormatEtc.  This object lives on its own.
class CEnumFormatEtc : 
	public IEnumFORMATETC
{
private:
	ULONG m_cRef;         //Object reference count
	LPUNKNOWN m_pUnkRef;  //For reference counting
	ULONG m_iCur;         // Current element.
	ULONG m_cfe;          // Number of FORMATETCs in use
	LPFORMATETC m_prgfe;  // Source of FORMATETCs

public:
	CEnumFormatEtc( LPUNKNOWN, ULONG, LPFORMATETC );
	~CEnumFormatEtc();

	// *** IUnknown methods ***
	STDMETHODIMP QueryInterface( REFIID, LPVOID FAR* );
	STDMETHODIMP_(ULONG) AddRef();
	STDMETHODIMP_(ULONG) Release();

	// *** IEnumFORMATETC methods ***
	STDMETHODIMP Next( ULONG, LPFORMATETC, ULONG * );
	STDMETHODIMP Skip( ULONG );
	STDMETHODIMP Reset( void );
	STDMETHODIMP Clone( IEnumFORMATETC ** );
};

typedef CEnumFormatEtc *PCEnumFormatEtc;

