//-----------------------------------------------------------------------------
//  Microsoft Visual Studio
//
// Copyright (C) 1992-2000 Microsoft Corporation
// All rights reserved.
//
// This code was originally ported from the Microsoft Foundation Class Library.
//
// Implementation of parameterized Array
//
//-----------------------------------------------------------------------------
#include "hu_pch.h"
#include "oledobj2.h"


/////////////////////////////////////////////////////////////////////////////
// CVxOleDataSource implementation

struct VX_DATACACHE_ENTRY
{
    FORMATETC m_formatEtc;
    STGMEDIUM m_stgMedium;
    DATADIR m_nDataDir;
};

//---------------------------------------------------------------------------
// Helper for creating default FORMATETC from cfFormat
//---------------------------------------------------------------------------
LPFORMATETC _VxFillFormatEtc(
    LPFORMATETC lpFormatEtc, CLIPFORMAT cfFormat, LPFORMATETC lpFormatEtcFill)
{
    ASSERT(lpFormatEtcFill != NULL);
    if (lpFormatEtc == NULL && cfFormat != 0)
    {
        lpFormatEtc = lpFormatEtcFill;
        lpFormatEtc->cfFormat = cfFormat;
        lpFormatEtc->ptd = NULL;
        lpFormatEtc->dwAspect = DVASPECT_CONTENT;
        lpFormatEtc->lindex = -1;
        lpFormatEtc->tymed = (DWORD) -1;
    }
    return lpFormatEtc;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
DVTARGETDEVICE* _VxOleCopyTargetDevice(DVTARGETDEVICE* ptdSrc)
{
    if (ptdSrc == NULL)
        return NULL;

    DVTARGETDEVICE* ptdDest =
        (DVTARGETDEVICE*)CoTaskMemAlloc(ptdSrc->tdSize);
    if (ptdDest == NULL)
        return NULL;

    memcpy(ptdDest, ptdSrc, (size_t)ptdSrc->tdSize);
    return ptdDest;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void _VxOleCopyFormatEtc(LPFORMATETC petcDest, LPFORMATETC petcSrc)
{
    ASSERT(petcDest != NULL);
    ASSERT(petcSrc != NULL);

    petcDest->cfFormat = petcSrc->cfFormat;
    petcDest->ptd = _VxOleCopyTargetDevice(petcSrc->ptd);
    petcDest->dwAspect = petcSrc->dwAspect;
    petcDest->lindex = petcSrc->lindex;
    petcDest->tymed = petcSrc->tymed;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
static HGLOBAL CopyGlobalMemory(HGLOBAL hDest, HGLOBAL hSource)
{
    ASSERT(hSource != NULL);

    // make sure we have suitable hDest
    ASSERT(::GlobalSize(hSource) < INT_MAX);
    DWORD nSize = (LONG32) (::GlobalSize(hSource));
    if (hDest == NULL)
    {
        hDest = ::GlobalAlloc(GMEM_SHARE|GMEM_MOVEABLE, nSize);
        if (hDest == NULL)
            return NULL;
    }
    else if (nSize > ::GlobalSize(hDest))
    {
        // hDest is not large enough
        return NULL;
    }

    // copy the bits
    LPVOID lpSource = ::GlobalLock(hSource);
    LPVOID lpDest = ::GlobalLock(hDest);
    ASSERT(lpDest != NULL);
    ASSERT(lpSource != NULL);
    memcpy(lpDest, lpSource, nSize);
    ::GlobalUnlock(hDest);
    ::GlobalUnlock(hSource);

    // success -- return hDest
    return hDest;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
BOOL _VxCopyStgMedium(
    CLIPFORMAT cfFormat, LPSTGMEDIUM lpDest, LPSTGMEDIUM lpSource)
{
    if (lpDest->tymed == TYMED_NULL)
    {
        ASSERT(lpSource->tymed != TYMED_NULL);
        switch (lpSource->tymed)
        {
        case TYMED_ENHMF:
        case TYMED_HGLOBAL:
            ASSERT(sizeof(HGLOBAL) == sizeof(HENHMETAFILE));
            lpDest->tymed = lpSource->tymed;
            lpDest->hGlobal = NULL;
            break;  // fall through to CopyGlobalMemory case

        case TYMED_ISTREAM:
            lpDest->pstm = lpSource->pstm;
            lpDest->pstm->AddRef();
            lpDest->tymed = TYMED_ISTREAM;
            return TRUE;

        case TYMED_ISTORAGE:
            lpDest->pstg = lpSource->pstg;
            lpDest->pstg->AddRef();
            lpDest->tymed = TYMED_ISTORAGE;
            return TRUE;

        case TYMED_MFPICT:
            {
                // copy LPMETAFILEPICT struct + embedded HMETAFILE
                HGLOBAL hDest = ::CopyGlobalMemory(NULL, lpSource->hGlobal);
                if (hDest == NULL)
                    return FALSE;
                LPMETAFILEPICT lpPict = (LPMETAFILEPICT)::GlobalLock(hDest);
                ASSERT(lpPict != NULL);
                lpPict->hMF = ::CopyMetaFile(lpPict->hMF, NULL);
                if (lpPict->hMF == NULL)
                {
                    ::GlobalUnlock(hDest);
                    ::GlobalFree(hDest);
                    return FALSE;
                }
                ::GlobalUnlock(hDest);

                // fill STGMEDIUM struct
                lpDest->hGlobal = hDest;
                lpDest->tymed = TYMED_MFPICT;
            }
            return TRUE;

        case TYMED_GDI:
            lpDest->tymed = TYMED_GDI;
            lpDest->hGlobal = NULL;
            break;

        case TYMED_FILE:
            {
                USES_CONVERSION;
                lpDest->tymed = TYMED_FILE;
                ASSERT(lpSource->lpszFileName != NULL);
                UINT cbSrc = (int)ocslen(lpSource->lpszFileName);
                LPOLESTR szFileName = (LPOLESTR)CoTaskMemAlloc((cbSrc+1)*sizeof(OLECHAR));
                lpDest->lpszFileName = szFileName;
                if (szFileName == NULL)
                    return FALSE;
                memcpy(szFileName, lpSource->lpszFileName,  (cbSrc+1)*sizeof(OLECHAR));
                return TRUE;
            }

        // unable to create + copy other TYMEDs
        default:
            return FALSE;
        }
    }
    ASSERT(lpDest->tymed == lpSource->tymed);

    switch (lpSource->tymed)
    {
    case TYMED_HGLOBAL:
        {
            HGLOBAL hDest = ::CopyGlobalMemory(lpDest->hGlobal,
                lpSource->hGlobal);
            if (hDest == NULL)
                return FALSE;

            lpDest->hGlobal = hDest;
        }
        return TRUE;

    case TYMED_ISTREAM:
        {
            ASSERT(lpDest->pstm != NULL);
            ASSERT(lpSource->pstm != NULL);

            // get the size of the source stream
            STATSTG stat;
            if (lpSource->pstm->Stat(&stat, STATFLAG_NONAME) != S_OK)
            {
                // unable to get size of source stream
                return FALSE;
            }
            ASSERT(stat.pwcsName == NULL);

            // always seek to zero before copy
            LARGE_INTEGER zero = { 0, 0 };
            lpDest->pstm->Seek(zero, STREAM_SEEK_SET, NULL);
            lpSource->pstm->Seek(zero, STREAM_SEEK_SET, NULL);

            // copy source to destination
            if (lpSource->pstm->CopyTo(lpDest->pstm, stat.cbSize,
                NULL, NULL) != NULL)
            {
                // copy from source to dest failed
                return FALSE;
            }

            // always seek to zero after copy
            lpDest->pstm->Seek(zero, STREAM_SEEK_SET, NULL);
            lpSource->pstm->Seek(zero, STREAM_SEEK_SET, NULL);
        }
        return TRUE;

    case TYMED_ISTORAGE:
        {
            ASSERT(lpDest->pstg != NULL);
            ASSERT(lpSource->pstg != NULL);

            // just copy source to destination
            if (lpSource->pstg->CopyTo(0, NULL, NULL, lpDest->pstg) != S_OK)
                return FALSE;
        }
        return TRUE;

    case TYMED_FILE:
        {
            USES_CONVERSION;
            ASSERT(lpSource->lpszFileName != NULL);
            ASSERT(lpDest->lpszFileName != NULL);
            return CopyFile(OLE2T(lpSource->lpszFileName), OLE2T(lpDest->lpszFileName), FALSE);
        }


    case TYMED_ENHMF:
    case TYMED_GDI:
        {
            ASSERT(sizeof(HGLOBAL) == sizeof(HENHMETAFILE));

            // with TYMED_GDI cannot copy into existing HANDLE
            if (lpDest->hGlobal != NULL)
                return FALSE;

            // otherwise, use OleDuplicateData for the copy
            lpDest->hGlobal = OleDuplicateData(lpSource->hGlobal, cfFormat, 0);
            if (lpDest->hGlobal == NULL)
                return FALSE;
        }
        return TRUE;

    // other TYMEDs cannot be copied
    default:
        return FALSE;
    }
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
class CopyFormatEtc
{
public:
    static void init(FORMATETC *p)
    {
        p->cfFormat = 0;
        p->ptd      = NULL;
        p->dwAspect = 0;
        p->lindex   = 0;
        p->tymed    = 0;
    }
    static HRESULT copy(FORMATETC *pTo, FORMATETC *pFrom)
    {
        pTo->cfFormat   = pFrom->cfFormat;
        pTo->ptd        = _VxOleCopyTargetDevice(pFrom->ptd);
        pTo->dwAspect   = pFrom->dwAspect;
        pTo->lindex     = pFrom->lindex;
        pTo->tymed      = pFrom->tymed;
        return S_OK;
    }
    static void destroy(FORMATETC *p)
    {
        ASSERT(NULL != p);
        CoTaskMemFree(p->ptd);
    }
};

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
class CEnumFormatEtc :
     public CComEnum<IEnumFORMATETC, &IID_IEnumFORMATETC, FORMATETC, CopyFormatEtc, CComSingleThreadModel>
{
protected:
    virtual ~CEnumFormatEtc(void) { };

public:
    CEnumFormatEtc(void);

    void AddFormat(const FORMATETC* lpFormatEtc);

protected:
    DWORD m_nSize, m_nMaxSize;
};

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
CEnumFormatEtc::CEnumFormatEtc(void) :
    m_nSize(0), m_nMaxSize(0)
{
    m_dwFlags |= BitOwn;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void CEnumFormatEtc::AddFormat(const FORMATETC* lpFormatEtc)
{
    ASSERT(m_nSize <= m_nMaxSize);

    if (m_nSize == m_nMaxSize)
    {
        // not enough space for new item -- allocate more
        FORMATETC* pListNew = new FORMATETC[m_nSize+10];
        ASSERT(pListNew);
        if(!pListNew)
            return;
        m_nMaxSize += 10;
        memcpy(pListNew, m_begin, m_nSize*sizeof(FORMATETC));
        m_iter = (m_iter - m_begin) + pListNew;
        delete m_begin;
        m_begin = pListNew;
        m_end = m_begin + m_nSize;
    }
    // add this item to the list
    ASSERT(m_nSize < m_nMaxSize);
    FORMATETC* pFormat = &m_begin[m_nSize];
    pFormat->cfFormat = lpFormatEtc->cfFormat;
    pFormat->ptd = lpFormatEtc->ptd;
        // Note: ownership of lpFormatEtc->ptd is transfered with this call.
    pFormat->dwAspect = lpFormatEtc->dwAspect;
    pFormat->lindex = lpFormatEtc->lindex;
    pFormat->tymed = lpFormatEtc->tymed;
    ++m_nSize;
    ++m_end;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
CVxOleDataSource::CVxOleDataSource(void)
{
    m_pDataCache = NULL;
    m_nMaxSize = 0;
    m_nSize = 0;
    m_nGrowBy = 10;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
CVxOleDataSource::~CVxOleDataSource(void)
{
    // clear clipboard source if this object was on the clipboard
#if 0
    _AFX_OLE_STATE* pOleState = _afxOleState;
    if (this == pOleState->m_pClipboardSource)
        pOleState->m_pClipboardSource = NULL;
#endif
    // free the clipboard data cache
    Empty();
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void CVxOleDataSource::Empty()
{
    if (m_pDataCache != NULL)
    {
        ASSERT(m_nMaxSize != 0);
        ASSERT(m_nSize != 0);

        // release all of the STGMEDIUMs and FORMATETCs
        for (UINT nIndex = 0; nIndex < m_nSize; nIndex++)
        {
            CoTaskMemFree(m_pDataCache[nIndex].m_formatEtc.ptd);
            ::ReleaseStgMedium(&m_pDataCache[nIndex].m_stgMedium);
        }

        // delete the cache
        delete[] m_pDataCache;
        m_pDataCache = NULL;
        m_nMaxSize = 0;
        m_nSize = 0;
    }
    ASSERT(m_pDataCache == NULL);
    ASSERT(m_nMaxSize == 0);
    ASSERT(m_nSize == 0);
}

/////////////////////////////////////////////////////////////////////////////
// CVxOleDataSource clipboard API wrappers

void CVxOleDataSource::SetClipboard(void)
{
    ASSERT_VALID(this);

    // attempt OLE set clipboard operation
    SCODE sc = ::OleSetClipboard(this);
    ASSERT(S_OK == sc);
    sc;

    // success - set as current clipboard source
//  _afxOleState->m_pClipboardSource = this;
    ASSERT(::OleIsCurrentClipboard(this) == S_OK);
}

void PASCAL CVxOleDataSource::FlushClipboard()
{
    if (GetClipboardOwner() != NULL)
    {
        // active clipboard source and it is on the clipboard - flush it
        ::OleFlushClipboard();

        // shouldn't be clipboard owner any more...
        ASSERT(GetClipboardOwner() == NULL);
    }
}

#if 0
CVxOleDataSource* PASCAL CVxOleDataSource::GetClipboardOwner()
{
    _AFX_OLE_STATE* pOleState = _afxOleState;
    if (pOleState->m_pClipboardSource == NULL)
        return NULL;    // can't own the clipboard if pClipboardSource isn't set

    ASSERT_VALID(pOleState->m_pClipboardSource);
    LPDATAOBJECT lpDataObject = (LPDATAOBJECT)
        pOleState->m_pClipboardSource->GetInterface(&IID_IDataObject);
    if (::OleIsCurrentClipboard(lpDataObject) != S_OK)
    {
        pOleState->m_pClipboardSource = NULL;
        return NULL;    // don't own the clipboard anymore
    }

    // return current clipboard sourcew
    return pOleState->m_pClipboardSource;
}
#endif

/////////////////////////////////////////////////////////////////////////////
// CVxOleDataSource cache allocation

VX_DATACACHE_ENTRY* CVxOleDataSource::GetCacheEntry(
    LPFORMATETC lpFormatEtc, DATADIR nDataDir)
{
    VX_DATACACHE_ENTRY* pEntry = Lookup(lpFormatEtc, nDataDir);
    if (pEntry != NULL)
    {
        // cleanup current entry and return it
        CoTaskMemFree(pEntry->m_formatEtc.ptd);
        ::ReleaseStgMedium(&pEntry->m_stgMedium);
    }
    else
    {
        // allocate space for item at m_nSize (at least room for 1 item)
        if (m_pDataCache == NULL || m_nSize == m_nMaxSize)
        {
            ASSERT(m_nGrowBy != 0);
            VX_DATACACHE_ENTRY* pCache = new VX_DATACACHE_ENTRY[m_nMaxSize+m_nGrowBy];
            ASSERT(pCache);
            if(!pCache)
                return NULL;
            m_nMaxSize += m_nGrowBy;
            if (m_pDataCache != NULL)
            {
                memcpy(pCache, m_pDataCache, m_nSize * sizeof(VX_DATACACHE_ENTRY));
                delete[] m_pDataCache;
            }
            m_pDataCache = pCache;
        }
        ASSERT(m_pDataCache != NULL);
        ASSERT(m_nMaxSize != 0);

        pEntry = &m_pDataCache[m_nSize++];
    }

    // fill the cache entry with the format and data direction and return it
    pEntry->m_nDataDir = nDataDir;
    pEntry->m_formatEtc = *lpFormatEtc;
    return pEntry;
}

/////////////////////////////////////////////////////////////////////////////
// CVxOleDataSource operations

// for HGLOBAL based cached render
void CVxOleDataSource::CacheGlobalData(CLIPFORMAT cfFormat, HGLOBAL hGlobal,
    LPFORMATETC lpFormatEtc)
{
    ASSERT(hGlobal != NULL);
    ASSERT(lpFormatEtc == NULL ||
        VxIsValidAddress(lpFormatEtc, sizeof(FORMATETC), FALSE));

    // fill in FORMATETC struct
    FORMATETC formatEtc;
    lpFormatEtc = _VxFillFormatEtc(lpFormatEtc, cfFormat, &formatEtc);
    ASSERT(lpFormatEtc);
    if(!lpFormatEtc)
        return;
    lpFormatEtc->tymed = TYMED_HGLOBAL;

    // add it to the cache
    VX_DATACACHE_ENTRY* pEntry = GetCacheEntry(lpFormatEtc, DATADIR_GET);
    ASSERT(pEntry);
    if(!pEntry)
        return;
    pEntry->m_stgMedium.tymed = TYMED_HGLOBAL;
    pEntry->m_stgMedium.hGlobal = hGlobal;
    pEntry->m_stgMedium.pUnkForRelease = NULL;
}

// for raw LPSTGMEDIUM cached render
void CVxOleDataSource::CacheData(CLIPFORMAT cfFormat, LPSTGMEDIUM lpStgMedium,
    LPFORMATETC lpFormatEtc)
{
    ASSERT(lpStgMedium == NULL || lpStgMedium->tymed != TYMED_NULL);
    ASSERT(VxIsValidAddress(lpStgMedium, sizeof(STGMEDIUM), FALSE));
    ASSERT(lpFormatEtc == NULL ||
        VxIsValidAddress(lpFormatEtc, sizeof(FORMATETC), FALSE));

    // fill in FORMATETC struct
    FORMATETC formatEtc;
    lpFormatEtc = _VxFillFormatEtc(lpFormatEtc, cfFormat, &formatEtc);
    ASSERT(lpFormatEtc);
    if(!lpFormatEtc)
        return;

    // Only these TYMED_GDI formats can be copied, so can't serve as
    //  cache content (you must use DelayRenderData instead)
    // When using COleServerItem::CopyToClipboard this means providing an
    //  override of COleServerItem::OnGetClipboardData to provide a custom
    //  delayed rendering clipboard object.
    ASSERT(lpStgMedium->tymed != TYMED_GDI ||
        lpFormatEtc->cfFormat == CF_METAFILEPICT ||
        lpFormatEtc->cfFormat == CF_PALETTE ||
        lpFormatEtc->cfFormat == CF_BITMAP);
    lpFormatEtc->tymed = lpStgMedium->tymed;

    // add it to the cache
    VX_DATACACHE_ENTRY* pEntry = GetCacheEntry(lpFormatEtc, DATADIR_GET);
    if (pEntry)
        pEntry->m_stgMedium = *lpStgMedium;
}

// for CVsFile* based delayed render
void CVxOleDataSource::DelayRenderFileData(CLIPFORMAT cfFormat,
    LPFORMATETC lpFormatEtc)
{
    ASSERT(lpFormatEtc == NULL ||
        VxIsValidAddress(lpFormatEtc, sizeof(FORMATETC), FALSE));

    // fill in FORMATETC struct
    FORMATETC formatEtc;
    lpFormatEtc = _VxFillFormatEtc(lpFormatEtc, cfFormat, &formatEtc);
    ASSERT(lpFormatEtc);
    if(!lpFormatEtc)
        return;
    lpFormatEtc->tymed |= TYMED_ISTREAM|TYMED_HGLOBAL;

    // add it to the cache
    VX_DATACACHE_ENTRY* pEntry = GetCacheEntry(lpFormatEtc, DATADIR_GET);
    if (pEntry)
    {
        pEntry->m_stgMedium.tymed = TYMED_NULL;
        pEntry->m_stgMedium.hGlobal = NULL;
        pEntry->m_stgMedium.pUnkForRelease = NULL;
    }
}

// for LPSTGMEDIUM or HGLOBAL based delayed render
void CVxOleDataSource::DelayRenderData(CLIPFORMAT cfFormat, LPFORMATETC lpFormatEtc)
{
    ASSERT(lpFormatEtc == NULL ||
        VxIsValidAddress(lpFormatEtc, sizeof(FORMATETC), FALSE));

    // fill in FORMATETC struct
    FORMATETC formatEtc;
    if (lpFormatEtc == NULL)
    {
        lpFormatEtc = _VxFillFormatEtc(lpFormatEtc, cfFormat, &formatEtc);
        ASSERT(lpFormatEtc);
        if(!lpFormatEtc)
            return;
        lpFormatEtc->tymed = TYMED_HGLOBAL;
    }
    // insure that cfFormat member is set
    if (cfFormat != 0)
        lpFormatEtc->cfFormat = cfFormat;

    // add it to the cache
    VX_DATACACHE_ENTRY* pEntry = GetCacheEntry(lpFormatEtc, DATADIR_GET);
    if (pEntry)
        memset(&pEntry->m_stgMedium, 0, sizeof pEntry->m_stgMedium);
}

//---------------------------------------------------------------------------
// DelaySetData -- used to allow SetData on given LPFORMATETC
//---------------------------------------------------------------------------
void CVxOleDataSource::DelaySetData(CLIPFORMAT cfFormat, LPFORMATETC lpFormatEtc)
{
    ASSERT(lpFormatEtc == NULL ||
        VxIsValidAddress(lpFormatEtc, sizeof(FORMATETC), FALSE));

    // fill in FORMATETC struct
    FORMATETC formatEtc;
    lpFormatEtc = _VxFillFormatEtc(lpFormatEtc, cfFormat, &formatEtc);
    ASSERT(lpFormatEtc);
    if(!lpFormatEtc)
        return;

    // add it to the cache
    VX_DATACACHE_ENTRY* pEntry = GetCacheEntry(lpFormatEtc, DATADIR_SET);
    if (pEntry)
    {
        pEntry->m_stgMedium.tymed = TYMED_NULL;
        pEntry->m_stgMedium.hGlobal = NULL;
        pEntry->m_stgMedium.pUnkForRelease = NULL;
    }
}

/////////////////////////////////////////////////////////////////////////////
// CVxOleDataSource cache implementation

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
VX_DATACACHE_ENTRY* CVxOleDataSource::Lookup(
    LPFORMATETC lpFormatEtc, DATADIR nDataDir) const
{
    VX_DATACACHE_ENTRY* pLast = NULL;
    // look for suitable match to lpFormatEtc in cache
    for (UINT nIndex = 0; nIndex < m_nSize; nIndex++)
    {
        // get entry from cache at nIndex
        VX_DATACACHE_ENTRY* pCache = &m_pDataCache[nIndex];
        FORMATETC *pCacheFormat = &pCache->m_formatEtc;

        // check for match
        if (pCacheFormat->cfFormat == lpFormatEtc->cfFormat &&
            (pCacheFormat->tymed & lpFormatEtc->tymed) != 0 &&
            pCacheFormat->lindex == lpFormatEtc->lindex &&
            pCacheFormat->dwAspect == lpFormatEtc->dwAspect &&
            pCache->m_nDataDir == nDataDir)
        {
            // for backward compatibility we match even if we never
            // find an exact match for the DVTARGETDEVICE
            DVTARGETDEVICE* ptd1 = pCacheFormat->ptd;
            DVTARGETDEVICE* ptd2 = lpFormatEtc->ptd;
            pLast = pCache;
            if ( ((ptd1 == NULL) && (ptd2 == NULL)) ||
                ((ptd1 != NULL) && (ptd2 != NULL) &&
                    (ptd1->tdSize == ptd2->tdSize) &&
                    (memcmp(ptd1, ptd2, ptd1->tdSize)==0)
                ))
            {
                // exact match, so break now and return it
                break;
            }
            // continue looking for better match
        }
    }

    return pLast;    // not found
}

/////////////////////////////////////////////////////////////////////////////
// CVxOleDataSource overidable default implementation

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
BOOL CVxOleDataSource::OnRenderGlobalData(
    LPFORMATETC /*lpFormatEtc*/, HGLOBAL* /*phGlobal*/)
{
    return FALSE;   // default does nothing
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
BOOL CVxOleDataSource::OnRenderFileData(
    LPFORMATETC /*lpFormatEtc*/, CVsFile* /*pFile*/)
{
    return FALSE;   // default does nothing
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
BOOL CVxOleDataSource::OnRenderData(
    LPFORMATETC lpFormatEtc, LPSTGMEDIUM lpStgMedium)
{
    // attempt TYMED_HGLOBAL as prefered format
    if (lpFormatEtc->tymed & TYMED_HGLOBAL)
    {
        // attempt HGLOBAL delay render hook
        HGLOBAL hGlobal = lpStgMedium->hGlobal;
        if (OnRenderGlobalData(lpFormatEtc, &hGlobal))
        {
            ASSERT(lpStgMedium->tymed != TYMED_HGLOBAL ||
                (lpStgMedium->hGlobal == hGlobal));
            ASSERT(hGlobal != NULL);
            lpStgMedium->tymed = TYMED_HGLOBAL;
            lpStgMedium->hGlobal = hGlobal;
            return TRUE;
        }

        // attempt CVsFile* based delay render hook
        CVsSharedFile file;
        if (lpStgMedium->tymed == TYMED_HGLOBAL)
        {
            ASSERT(lpStgMedium->hGlobal != NULL);
            file.SetHandle(lpStgMedium->hGlobal, FALSE);
        }
        if (OnRenderFileData(lpFormatEtc, &file))
        {
            lpStgMedium->tymed = TYMED_HGLOBAL;
            lpStgMedium->hGlobal = file.Detach();
            ASSERT(lpStgMedium->hGlobal != NULL);
            return TRUE;
        }
        if (lpStgMedium->tymed == TYMED_HGLOBAL)
            file.Detach();
    }

    // attempt TYMED_ISTREAM format
    if (lpFormatEtc->tymed & TYMED_ISTREAM)
    {
        ASSERT(!_T("port COleStreamFile"));
#if 0
        COleStreamFile file;
        if (lpStgMedium->tymed == TYMED_ISTREAM)
        {
            ASSERT(lpStgMedium->pstm != NULL);
            file.Attach(lpStgMedium->pstm);
        }
        else
        {
            if (!file.CreateMemoryStream())
                return FALSE;

        }
        // get data into the stream
        if (OnRenderFileData(lpFormatEtc, &file))
        {
            lpStgMedium->tymed = TYMED_ISTREAM;
            lpStgMedium->pstm = file.Detach();
            return TRUE;
        }
        if (lpStgMedium->tymed == TYMED_ISTREAM)
            file.Detach();
#endif //0
    }

    return FALSE;   // default does nothing
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
BOOL CVxOleDataSource::OnSetData(
    LPFORMATETC /*lpFormatEtc*/, LPSTGMEDIUM /*lpStgMedium*/, BOOL /*bRelease*/)
{
    return FALSE;   // default does nothing
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
STDMETHODIMP CVxOleDataSource::GetData( 
            /* [unique][in] */ FORMATETC *pformatetcIn,
            /* [out] */ STGMEDIUM *pmedium)
{
    ASSERT_VALID(this);

    // attempt to find match in the cache
    VX_DATACACHE_ENTRY* pCache = this->Lookup(pformatetcIn, DATADIR_GET);
    if (pCache == NULL)
        return DATA_E_FORMATETC;

    // use cache if entry is not delay render
    memset(pmedium, 0, sizeof(STGMEDIUM));
    if (pCache->m_stgMedium.tymed != TYMED_NULL)
    {
        // Copy the cached medium into the lpStgMedium provided by caller.
        if (!_VxCopyStgMedium(pformatetcIn->cfFormat, pmedium,
          &pCache->m_stgMedium))
            return DATA_E_FORMATETC;

        // format was supported for copying
        return S_OK;
    }

    SCODE sc = DATA_E_FORMATETC;

    // attempt LPSTGMEDIUM based delay render
    if (this->OnRenderData(pformatetcIn, pmedium))
            sc = S_OK;
    return sc;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
STDMETHODIMP CVxOleDataSource::GetDataHere( 
            /* [unique][in] */ FORMATETC *pformatetc,
            /* [out][in] */ STGMEDIUM *pmedium)
{
    ASSERT_VALID(this);

    // these two must be the same
    ASSERT(pformatetc->tymed == pmedium->tymed);
    pformatetc->tymed = pmedium->tymed;    // but just in case...

    // attempt to find match in the cache
    VX_DATACACHE_ENTRY* pCache = this->Lookup(pformatetc, DATADIR_GET);
    if (pCache == NULL)
        return DATA_E_FORMATETC;

    // handle cached medium and copy
    if (pCache->m_stgMedium.tymed != TYMED_NULL)
    {
        // found a cached format -- copy it to dest medium
        ASSERT(pCache->m_stgMedium.tymed == pmedium->tymed);
        if (!_VxCopyStgMedium(pformatetc->cfFormat, pmedium,
          &pCache->m_stgMedium))
            return DATA_E_FORMATETC;

        // format was supported for copying
        return S_OK;
    }

    SCODE sc = DATA_E_FORMATETC;
    // attempt pmedium based delay render
    if (this->OnRenderData(pformatetc, pmedium))
        sc = S_OK;
    return sc;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
STDMETHODIMP CVxOleDataSource::QueryGetData( 
            /* [unique][in] */ FORMATETC *pformatetc)
{
    // attempt to find match in the cache
    VX_DATACACHE_ENTRY* pCache = this->Lookup(pformatetc, DATADIR_GET);
    if (pCache == NULL)
        return DATA_E_FORMATETC;

    // it was found in the cache or can be rendered -- success
    return S_OK;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
STDMETHODIMP CVxOleDataSource::GetCanonicalFormatEtc( 
            /* [unique][in] */ FORMATETC *pformatectIn,
            /* [out] */ FORMATETC *pformatetcOut)
{
    // because we support the target-device (ptd) for server metafile format,
    //  all members of the FORMATETC are significant.

    return DATA_S_SAMEFORMATETC;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
STDMETHODIMP CVxOleDataSource::SetData( 
            /* [unique][in] */ FORMATETC *pformatetc,
            /* [unique][in] */ STGMEDIUM *pmedium,
            /* [in] */ BOOL fRelease)
{
    ASSERT(pformatetc->tymed == pmedium->tymed);

    // attempt to find match in the cache
    VX_DATACACHE_ENTRY* pCache = this->Lookup(pformatetc, DATADIR_SET);
    if (pCache == NULL)
        return DATA_E_FORMATETC;

    ASSERT(pCache->m_stgMedium.tymed == TYMED_NULL);

    SCODE sc = E_UNEXPECTED;

    // attempt pmedium based SetData
    if (this->OnSetData(pformatetc, pmedium, fRelease))
        sc = S_OK;
    return sc;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
STDMETHODIMP CVxOleDataSource::EnumFormatEtc( 
            /* [in] */ DWORD dwDirection,
            /* [out] */ IEnumFORMATETC **ppenumFormatEtc)
{
    *ppenumFormatEtc = NULL;

    // generate a format list from the cache
    CComObject<CEnumFormatEtc> *pFormatList = NULL;
    HRESULT hr = CComObject<CEnumFormatEtc>::CreateInstance(&pFormatList);
    if (SUCCEEDED(hr))
    {
        for (UINT nIndex = 0; nIndex < this->m_nSize; nIndex++)
        {
            VX_DATACACHE_ENTRY* pCache = &this->m_pDataCache[nIndex];
            if ((DWORD)pCache->m_nDataDir & dwDirection)
            {
                // entry should be enumerated -- add it to the list
                FORMATETC formatEtc;
                _VxOleCopyFormatEtc(&formatEtc, &pCache->m_formatEtc);
                pFormatList->AddFormat(&formatEtc);
            }
        }
    }
    (*ppenumFormatEtc) = pFormatList;
    (*ppenumFormatEtc)->AddRef();
    return hr;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
STDMETHODIMP CVxOleDataSource::DAdvise( 
            /* [in] */ FORMATETC *pformatetc,
            /* [in] */ DWORD advf,
            /* [unique][in] */ IAdviseSink *pAdvSink,
            /* [out] */ DWORD *pdwConnection)
{
    ATLTRACE(_T("IDataObjectImpl::DAdvise\n"));
    HRESULT hr = S_OK;
    if (this->m_spDataAdviseHolder == NULL)
        hr = CreateDataAdviseHolder(&this->m_spDataAdviseHolder);

    if (hr == S_OK)
        hr = this->m_spDataAdviseHolder->Advise((IDataObject*)this, pformatetc, advf, pAdvSink, pdwConnection);

    return hr;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
STDMETHODIMP CVxOleDataSource::DUnadvise( 
            /* [in] */ DWORD dwConnection)
{
    ATLTRACE(_T("IDataObjectImpl::DUnadvise\n"));
    HRESULT hr = S_OK;
    if (this->m_spDataAdviseHolder == NULL)
        hr = OLE_E_NOCONNECTION;
    else
        hr = this->m_spDataAdviseHolder->Unadvise(dwConnection);
    return hr;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
STDMETHODIMP CVxOleDataSource::EnumDAdvise( 
            /* [out] */ IEnumSTATDATA **ppenumAdvise)
{
    ATLTRACE(_T("IDataObjectImpl::EnumDAdvise\n"));
    HRESULT hr = E_FAIL;
    if (this->m_spDataAdviseHolder != NULL)
        hr = this->m_spDataAdviseHolder->EnumAdvise(ppenumAdvise);
    return hr;
}

/////////////////////////////////////////////////////////////////////////////
// CVxOleDataSource diagnostics

#ifdef _DEBUG
void CVxOleDataSource::AssertValid() const
{
//  CCmdTarget::AssertValid();
    ASSERT(m_nSize <= m_nMaxSize);
    ASSERT(m_nMaxSize != 0 || m_pDataCache == NULL);
}

#if 0
void CVxOleDataSource::Dump(CDumpContext& dc) const
{
    CCmdTarget::Dump(dc);

    dc << "m_nMaxSize = " << m_nMaxSize;
    dc << "\nm_nSize = " << m_nSize;
    dc << "\nm_pDataCache = " << m_pDataCache;

    for (UINT n = 0; n < m_nSize; n++)
    {
        dc << "\n\tentry [" << n << "] = {";
        VX_DATACACHE_ENTRY& rEntry = m_pDataCache[n];
        dc << "\n\t m_formatEtc.cfFormat = " << rEntry.m_formatEtc.cfFormat;
        dc << "\n\t m_formatEtc.pdt = " << rEntry.m_formatEtc.ptd;
        dc << "\n\t m_formatEtc.dwAspect = " << rEntry.m_formatEtc.dwAspect;
        dc << "\n\t m_formatEtc.lindex = " << rEntry.m_formatEtc.lindex;
        dc << "\n\t m_formatEtc.tymed = " << rEntry.m_formatEtc.tymed;
        dc << "\n\t m_stgMedium.tymed = " << rEntry.m_stgMedium.tymed;
        dc << "\n\t m_nDataDir = " << (UINT)rEntry.m_nDataDir;
        dc << "\n\t}";
    }

    dc << "\n";
}
#endif
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
