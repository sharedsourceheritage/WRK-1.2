
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// DataObj.cpp : Implementaion of the CDataObject class 

#include "stdafx.h"  // system includes
#include "PrjInc.h"  // project includes

CDataObject::CDataObject( UINT cfFormat, listLines_type &lSelected, IVsTextLines *pVsTextLines ) 
{
    ENVSDK_TRACE(envsdkTraceGeneral, 3, _T(" CDataObject::CDataObject : at 0x%X \n"), this );

    m_dwRef = 0;
    m_PasteAtLine = 0;
    m_srpVsTextLines = pVsTextLines;  // Note: assignment to a smart pointer does an AddRef()

    FigLineType Ftype;
    long P1, P2, P3, P4;
    CComBSTR bstrCmt;
    listLines_type::iterator pos;
    for( pos = lSelected.begin(); pos != lSelected.end(); pos++ ) {     // alloc line objs (originals could be deleted)

        (*pos)->get_Type( &Ftype );
        (*pos)->get_Parameter1( &P1 );
        (*pos)->get_Parameter2( &P2 );
        (*pos)->get_Parameter3( &P3 );
        (*pos)->get_Parameter4( &P4 );
        (*pos)->get_Comment( &bstrCmt );
    
        CFigEditLine *pTmp = new CFigEditLine( 0, m_srpVsTextLines, 
                                    Ftype, P1, P2, P3, P4, bstrCmt );
        if( pTmp )
        {
            pTmp->AddRef();
            m_SelLines.insert( m_SelLines.end(), pTmp );    // make a list of selected lines 
        }

        // Done with the string, free it.
        bstrCmt.Empty();
    }

    // Initilize the FORMATETCs arrays we use for EnumFormatEtc
    m_cfeGet = CFORMATETCGET;

    // our custom format
    m_cf = cfFormat;

    // Init the formats we support
    SETDefFormatEtc( m_rgfeGet[0], m_cf, TYMED_HGLOBAL );       // custom format must be first
    SETDefFormatEtc( m_rgfeGet[1], CF_TEXT, TYMED_HGLOBAL );
}

CDataObject::CDataObject(FigLineType Ftype)
{
    // this constructor is for creating toolbox items
    ENVSDK_TRACE(envsdkTraceGeneral, 3, _T(" CDataObject::CDataObject(FigLineType) : at 0x%X \n"), this );

    m_dwRef = 0;
    m_PasteAtLine = 0;
    m_srpVsTextLines = NULL;  // Note: this member is not used except in the constructor

    long P1 =0, P2 = 0, P3 = 0, P4 = 0;
    CComBSTR bstrCmt = L"";

    switch (Ftype)
    {
    case FigArrow:
        P1 = 0;
        P2 = 0;
        P3 = 10;
        P4 = 10;
        break;
    case FigCircle:
        P1 = 10;
        P2 = 10;
        P3 = 5;
        P4 = 0;
        break;
    case FigRectangle:
        P1 = 0;
        P2 = 0;
        P3 = 10;
        P4 = 10;
        break;
    case FigComment:
        bstrCmt = L"********************************************************";
        break;
    default:
        break;
    }

    CFigEditLine *pTmp = new CFigEditLine( 0, m_srpVsTextLines, 
                                Ftype, P1, P2, P3, P4, bstrCmt );
    if( pTmp )
    {
        pTmp->AddRef();
        m_SelLines.insert( m_SelLines.end(), pTmp );    // make a list of selected lines 
    }

    // Initilize the FORMATETCs arrays we use for EnumFormatEtc
    m_cfeGet = CFORMATETCGET;

    // our custom format
    m_cf = RegisterClipboardFormatW(WSTR_CF_FigureSampleLine);
    ASSERT(m_cf != 0);

    // Init the formats we support
    SETDefFormatEtc( m_rgfeGet[0], m_cf, TYMED_HGLOBAL );       // custom format must be first
    SETDefFormatEtc( m_rgfeGet[1], CF_TEXT, TYMED_HGLOBAL );
}

CDataObject::~CDataObject()
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, _T(" CDataObject::~CDataObject : at 0x%X \n"), this );

    _ASSERTE( 0 == m_dwRef );
    for( listLines_type::iterator pos = m_SelLines.begin(); pos != m_SelLines.end(); pos++ )
        (*pos)->Release();
}


/*****************************************************************************
** IUnknown Implementation
*****************************************************************************/

STDMETHODIMP CDataObject::QueryInterface( REFIID riid, LPVOID FAR* ppvObj )
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, TEXT("FigEdit: CDataObject::QueryInterface\n") );

    if( ppvObj == NULL )
        return( E_INVALIDARG );

    *ppvObj = NULL;     // always intialize out parameters
    if( riid == IID_IUnknown ) 
    {
        AddRef();
        *ppvObj = (IDataObject *) this;
        return NOERROR;
    }
    else if( riid == IID_IDataObject )
    {
        AddRef();
        *ppvObj = (IDataObject *) this;
        return NOERROR;
    }
    else if( riid == IID_IDropSource )
    {
        AddRef();
        *ppvObj = (IDropSource *) this;
        return NOERROR;
    }
    
    return E_NOINTERFACE;
}

STDMETHODIMP_(ULONG) CDataObject::AddRef()
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, TEXT("FigEdit: CDataObject::AddRef : at 0x%X \n"), this );

    ++m_dwRef;
    return( m_dwRef );
}

STDMETHODIMP_(ULONG) CDataObject::Release()
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, TEXT("FigEdit: CDataObject::Release : at 0x%X \n"), this );

    --m_dwRef;
    if( m_dwRef == 0 ) {
        delete this;
        return 0;
    }
    return( m_dwRef ); 
}


/*****************************************************************************
** IDataObject Implementation
*****************************************************************************/


// ::GetData
//
// Purpose:
//  Retrieves data described by a specific FormatEtc into a StgMedium
//  allocated by this function.  Used like GetClipboardData.
//  USER must FREE the hglobal in the STM if successful.
//
// Parameters:
//  pFE             LPFORMATETC describing the desired data.
//  pSTM            LPSTGMEDIUM in which to return the data.
//
// Return Value:
//  HRESULT         S_OK or a general error value.
//
STDMETHODIMP CDataObject::GetData( FORMATETC *pformatetcIn, 
                                   STGMEDIUM *pmedium )
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, TEXT("FigEdit: CDataObject::GetData\n") );

    _ASSERTE( NULL != pformatetcIn );
    _ASSERTE( NULL != pmedium );
    UINT  cf = pformatetcIn->cfFormat;

    // Check the aspects we support.
    if( !( DVASPECT_CONTENT & pformatetcIn->dwAspect ))
        return DATA_E_FORMATETC;

    switch( cf )
    {
    case CF_TEXT:
        if( !( TYMED_HGLOBAL & pformatetcIn->tymed ))
            break;
        return RenderText( pmedium );

    default:
        if( cf == m_cf ) {
            if( !( TYMED_HGLOBAL & pformatetcIn->tymed ))
                break;
            return RenderLines( pmedium );
        }
        break;
    }

    return DATA_E_FORMATETC;
}


// ::SetData
//
// Purpose:
//  Places data described by a FormatEtc and living in a StgMedium
//  into the object.  The object may be responsible to clean up the
//  StgMedium before exiting.
//
// Parameters:
//  pFE             LPFORMATETC describing the data to set.
//  pSTM            LPSTGMEDIUM containing the data.
//  fRelease        BOOL indicating if this function is responsible
//                  for freeing the data.
//
// Return Value:
//  HRESULT         S_OK or a general error value.
//
STDMETHODIMP CDataObject::SetData( FORMATETC *pformatetc, 
                                   STGMEDIUM *pmedium, 
                                   BOOL fRelease )
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, TEXT("FigEdit: CDataObject::SetData\n") );

    // this is not used.  Data is set into this object when it is created.

    return DATA_E_FORMATETC;
}


// ::EnumFormatEtc
//
// Purpose:
//  Returns an IEnumFORMATETC object through which the caller can
//  iterate to learn about all the data formats this object can
//  provide through either GetData[Here] or SetData.
//
// Parameters:
//  dwDirection     DWORD describing a data direction, either
//                  DATADIR_SET or DATADIR_GET.
//  ppenumFormatEtc LPENUMFORMATETC * in which to return the
//                  pointer to the enumerator.
//
// Return Value:
//  HRESULT         S_OK or a general error value.
//
STDMETHODIMP CDataObject::EnumFormatEtc( DWORD dwDirection, 
                                         IEnumFORMATETC **ppenumFormatEtc )
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, TEXT("FigEdit: CDataObject::EnumFormatEtc\n") );

    if (NULL == ppenumFormatEtc)
        return E_INVALIDARG;

    switch (dwDirection)
    {
    // we support getting data in 2 formats CF_TEXT and our internal m_cf
    case DATADIR_GET:
        *ppenumFormatEtc = new CEnumFormatEtc( (IDataObject *)this, m_cfeGet, m_rgfeGet );
        break; 

    // we support setting data in only one format, our internal m_cf (first in array)
    case DATADIR_SET:
        *ppenumFormatEtc = new CEnumFormatEtc( (IDataObject *)this, 1, m_rgfeGet );
        break; 

    default:
        *ppenumFormatEtc = NULL;
        return E_NOTIMPL;
    }

    if (NULL == *ppenumFormatEtc)
        return E_OUTOFMEMORY;
    else
        (*ppenumFormatEtc)->AddRef();

    return S_OK;
}


// ::QueryGetData
//
// Purpose:
//  Tests if a call to GetData with this FormatEtc will provide
//  any rendering; used like IsClipboardFormatAvailable.
//
// Parameters:
//  pFE             LPFORMATETC describing the desired data.
//
// Return Value:
//  HRESULT         S_OK or a general error value.
//
STDMETHODIMP CDataObject::QueryGetData( FORMATETC *pformatetc )
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, TEXT("FigEdit: CDataObject::QueryGetData\n") );

    _ASSERTE( NULL != pformatetc );
    if (NULL == pformatetc)
        return E_INVALIDARG;

    // Check the aspects we support.
    if (!(DVASPECT_CONTENT & pformatetc->dwAspect))
        return DV_E_DVASPECT;
    // We only provide HGLOBALs
    if (!(pformatetc->tymed & TYMED_HGLOBAL))
        return DV_E_TYMED;
    // Check the formats we support
    if (pformatetc->cfFormat != m_cf
        && pformatetc->cfFormat != CF_TEXT)
        return DV_E_FORMATETC;

    return S_OK;
}


// ::GetCanonicalFormatEtc
//
// Purpose:
//  Provides the caller with an equivalent FormatEtc to the one
//  provided when different FormatEtcs will produce exactly the
//  same renderings.
//
// Parameters:
//  pFEIn            LPFORMATETC of the first description.
//  pFEOut           LPFORMATETC of the equal description.
//
// Return Value:
//  HRESULT         S_OK or a general error value.
//
STDMETHODIMP CDataObject::GetCanonicalFormatEtc( FORMATETC *pformatectIn,
                                                 FORMATETC *pformatetcOut )
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, TEXT("FigEdit: CDataObject::GetCanonicalFormatEtc\n") );

    if( NULL == pformatetcOut )
        return E_INVALIDARG;

    pformatetcOut->ptd = NULL;
    return DATA_S_SAMEFORMATETC;
}


// convert the line object(s) into a text on a hglobal
//
HRESULT CDataObject::RenderText( LPSTGMEDIUM pSTM )
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, TEXT("FigEdit: CDataObject::RenderText\n") );

    _ASSERTE( NULL != pSTM );
    if( NULL == pSTM )
        return E_INVALIDARG;
    // convert each line obj into a bstr
    CComBSTR bstrLines;
    listLines_type::iterator pos = m_SelLines.end();
    while (pos != m_SelLines.begin())
    {         
        --pos;  
        CComBSTR bstrTmp;
        (*pos)->MakeLine( &bstrTmp );
        bstrLines += bstrTmp;
        bstrLines += "\r\n";
    }

    // find out how much space the multi byte string will take
    size_t cmb = wcstombs( NULL, bstrLines, bstrLines.Length()) + sizeof( WCHAR );

    // alloc memory to hold the multi byte string (NOT UNICODE BSTR)
    HGLOBAL hMem;
    hMem = GlobalAlloc( GMEM_SHARE | GHND, cmb );
    if( NULL == hMem ) 
        return STG_E_MEDIUMFULL;

    // init memory
    CHAR *pchLines;
    pchLines = (CHAR *)GlobalLock( hMem );

    // convert unicode bstrs to multi byte
    wcstombs( pchLines, bstrLines, cmb );  
    GlobalUnlock( hMem );

    // set return values
    pSTM->hGlobal = hMem;
    pSTM->tymed = TYMED_HGLOBAL;
    pSTM->pUnkForRelease = NULL;    // means the caller is responsible for freeing global mem.
    return S_OK;
}


// convert the line object(s) into a custom byte stream on a hglobal
// the format is:
//  ULONG total number lines
//    ULONG total number of bytes in this line [ repeat the following lines for the number of objects ]
//    UINT  type
//    long  P1
//    long  P2
//    long  P3
//    long  P4
//    WCHAR comment (variable length)
//
///note: The "total number of bytes in this line" is actually the_fixed_#_bytes_per_line 
// (cPerLine) + #_of_comment's_characters

HRESULT CDataObject::RenderLines( LPSTGMEDIUM pSTM )
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, TEXT("FigEdit: CDataObject::RenderLines\n") );

    _ASSERTE( NULL != pSTM );
    if( NULL == pSTM )
        return E_POINTER;

    CComBSTR bstrCmt;
    ULONG cCmtChars = 0;
    listLines_type::iterator pos = m_SelLines.end();
    while (pos != m_SelLines.begin())
    {         
        --pos;  
        (*pos)->get_Comment( &bstrCmt );
        cCmtChars += bstrCmt.Length();
        bstrCmt.Empty();
    }
    // figure out how much memory to allocate per line (without comment)
    ULONG cPerLine =    sizeof( ULONG ) +           // total number of bytes
                        sizeof( FigLineType ) +     // type
                        (4 * sizeof( long ));       // parameters
    
    // total memory, count of lines + size of line properties + all comments
    size_t nTotal =     sizeof( ULONG ) + 
                        ( cPerLine * m_SelLines.size() ) + 
                        ( cCmtChars * sizeof( WCHAR ));

    HGLOBAL hMem = GlobalAlloc( GMEM_SHARE | GHND, nTotal );
    if( NULL == hMem )
        return STG_E_MEDIUMFULL;
    BYTE *pMem = (BYTE *)GlobalLock( hMem );
    _ASSERTE( NULL != pMem );   // only returns NULL if memory discarded or allocate count = 0
    if( NULL == pMem )
    {
        GlobalFree(hMem);
        return E_FAIL;
    }

    // write the line data into the memory buffer
    *(ULONG *)pMem = (ULONG)m_SelLines.size();  // write num lines
    pMem += sizeof( ULONG );

    pos = m_SelLines.end();
    for (UINT i = 0; i < m_SelLines.size(); i++)
    {
        (*--pos)->get_Comment( &bstrCmt );
        *(ULONG *)pMem = cPerLine + bstrCmt.Length();   // write num byes in this line
        pMem += sizeof( ULONG );

        (*pos)->get_Type( (FigLineType *)pMem );    // write type
        pMem += sizeof( FigLineType );

        (*pos)->get_Parameter1( (long *)pMem ); // write param1
        pMem += sizeof( long );
        (*pos)->get_Parameter2( (long *)pMem ); // write param2
        pMem += sizeof( long );
        (*pos)->get_Parameter3( (long *)pMem ); // write param3
        pMem += sizeof( long );
        (*pos)->get_Parameter4( (long *)pMem ); // write param4
        pMem += sizeof( long );

        if ( bstrCmt.Length())
        {
            wcsncpy( (WCHAR *)pMem, bstrCmt, bstrCmt.Length() );    // write comment
            pMem += bstrCmt.Length() * sizeof( WCHAR );
        }
        bstrCmt.Empty();
    }
    GlobalUnlock( hMem );

    pSTM->hGlobal = hMem;
    pSTM->tymed = TYMED_HGLOBAL;
    pSTM->pUnkForRelease = NULL;    // means the caller is responsible for freeing global mem.
    return S_OK;
}

// May return E_UNEXPECTED and E_OUTOFMEMORY, as well as:
//  S_OK    The drag operation should continue. This result occurs if no errors are detected,
//          the mouse button starting the drag-and-drop operation has not been released, and
//          the Esc key has not been detected.
//  DRAGDROP_S_DROP
//          The drop operation should occur completing the drag operation. This result occurs
//          if grfKeyState indicates that the key that started the drag-and-drop operation has
//          been released. 
//  DRAGDROP_S_CANCEL 
//          The drag operation should be canceled with no drop operation occurring. This result
//          occurs if fEscapePressed is TRUE, indicating the Esc key has been pressed. 
STDMETHODIMP CDataObject::QueryContinueDrag( BOOL fEscapePressed, DWORD grfKeyState )
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, TEXT("FigEdit: CDataObject::QueryContinueDrag\n") );

    if (fEscapePressed)
        return DRAGDROP_S_CANCEL;
    if (!(grfKeyState & MK_LBUTTON))    // left button released?
        return DRAGDROP_S_DROP;
    return S_OK;
}

// give visual feedback to the end user during a drag-and-drop operation by providing the DoDragDrop
// function with an enumeration value specifying the visual effect
// May return E_INVALIDARG, E_UNEXPECTED, and E_OUTOFMEMORY, as well as:
//  S_OK    successfully set the cursor
//  DRAGDROP_S_USEDEFAULTCURSORS 
//          successful completion, and requests to use OLE-provided default cursors.
STDMETHODIMP CDataObject::GiveFeedback( DWORD dwEffect )
{
    ENVSDK_TRACE(envsdkTraceGeneral, 4, TEXT("FigEdit: CDataObject::GiveFeedback\n") );

    return DRAGDROP_S_USEDEFAULTCURSORS;
}

// end of file DataObj.cpp