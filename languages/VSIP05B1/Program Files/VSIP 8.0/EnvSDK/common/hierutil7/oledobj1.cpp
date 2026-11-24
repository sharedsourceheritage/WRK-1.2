//-----------------------------------------------------------------------------
//  Microsoft Visual Studio
//
// Copyright (C) 1992-2000 Microsoft Corporation
// All rights reserved.
//
// This code was originally ported from the Microsoft Foundation Class Library.
//
//-----------------------------------------------------------------------------

#include "hu_pch.h"
#include "oledobj2.h"

/////////////////////////////////////////////////////////////////////////////
// CVxOleDataObject constructors

CVxOleDataObject::CVxOleDataObject()
{
    m_lpEnumerator = NULL;
    m_lpDataObject = NULL;
    m_bAutoRelease = TRUE;
    m_bClipboard = FALSE;
}

CVxOleDataObject::~CVxOleDataObject()
{
    Release();
}

void CVxOleDataObject::Attach(LPDATAOBJECT lpDataObject, BOOL bAutoRelease)
{
    ASSERT(lpDataObject != NULL);

    Release();  // detach previous
    m_lpDataObject = lpDataObject;
    m_bAutoRelease = bAutoRelease;
}

void CVxOleDataObject::Release()
{
    RELEASE(m_lpEnumerator);

    if (m_lpDataObject != NULL)
    {
        if (m_bAutoRelease)
            m_lpDataObject->Release();
        m_lpDataObject = NULL;
    }
    m_bClipboard = FALSE;
}

LPDATAOBJECT CVxOleDataObject::Detach()
{
    EnsureClipboardObject();

    LPDATAOBJECT lpDataObject = m_lpDataObject;
    m_lpDataObject = NULL;  // detach without Release
    m_bClipboard = FALSE;

    return lpDataObject;
}

LPDATAOBJECT CVxOleDataObject::GetIDataObject(BOOL bAddRef)
{
    EnsureClipboardObject();

    LPDATAOBJECT lpDataObject = m_lpDataObject;
    if (bAddRef && lpDataObject != NULL)
        lpDataObject->AddRef();

    return lpDataObject;
}

/////////////////////////////////////////////////////////////////////////////
// CVxOleDataObject attributes

void CVxOleDataObject::BeginEnumFormats()
{
    EnsureClipboardObject();
    ASSERT(m_bClipboard || m_lpDataObject != NULL);

    // release old enumerator
    RELEASE(m_lpEnumerator);
    if (m_lpDataObject == NULL)
        return;

    // get the new enumerator
    SCODE sc = m_lpDataObject->EnumFormatEtc(DATADIR_GET, &m_lpEnumerator);
    ASSERT(sc != S_OK || m_lpEnumerator != NULL);
}

BOOL CVxOleDataObject::GetNextFormat(LPFORMATETC lpFormatEtc)
{
    ASSERT(m_bClipboard || m_lpDataObject != NULL);
    ASSERT(VxIsValidAddress(lpFormatEtc, sizeof(FORMATETC), FALSE));

    // return FALSE if enumerator is already NULL
    if (m_lpEnumerator == NULL)
        return FALSE;

    // attempt to retrieve the next format with the enumerator
    SCODE sc = m_lpEnumerator->Next(1, lpFormatEtc, NULL);

    // if enumerator fails, stop the enumeration
    if (sc != S_OK)
    {
        RELEASE(m_lpEnumerator);
        return FALSE;   // enumeration has ended
    }
    // otherwise, continue
    return TRUE;
}

CVsFile* CVxOleDataObject::GetFileData(CLIPFORMAT cfFormat, LPFORMATETC lpFormatEtc)
{
    EnsureClipboardObject();
    ASSERT(m_bClipboard || m_lpDataObject != NULL);
    if (m_lpDataObject == NULL)
        return NULL;

    ASSERT(lpFormatEtc == NULL ||
        VxIsValidAddress(lpFormatEtc, sizeof(FORMATETC), FALSE));

    // fill in FORMATETC struct
    FORMATETC formatEtc;
    lpFormatEtc = _VxFillFormatEtc(lpFormatEtc, cfFormat, &formatEtc);
    formatEtc.tymed = TYMED_FILE|TYMED_MFPICT|TYMED_HGLOBAL|TYMED_ISTREAM;

    // attempt to get the data
    STGMEDIUM stgMedium;
    SCODE sc = m_lpDataObject->GetData(lpFormatEtc, &stgMedium);
    if (FAILED(sc))
        return FALSE;

    // STGMEDIUMs with pUnkForRelease need to be copied first
    if (stgMedium.pUnkForRelease != NULL)
    {
        ASSERT(lpFormatEtc);
        if(!lpFormatEtc)
            return FALSE;
        STGMEDIUM stgMediumDest;
        stgMediumDest.tymed = TYMED_NULL;
        stgMediumDest.pUnkForRelease = NULL;
        if (!_VxCopyStgMedium(lpFormatEtc->cfFormat, &stgMediumDest, &stgMedium))
        {
            ::ReleaseStgMedium(&stgMedium);
            return FALSE;
        }
        // release original and replace with new
        ::ReleaseStgMedium(&stgMedium);
        stgMedium = stgMediumDest;
    }

    // convert it to a file, depending on data
    CString strFileName;
    CVsFile* pFile = NULL;
    {
        switch (stgMedium.tymed)
        {
        case TYMED_FILE:
            strFileName = stgMedium.lpszFileName;
            pFile = new CVsFile;
            if (!pFile->Open(strFileName,
                CVsFile::modeReadWrite|CVsFile::shareExclusive))
            {
                delete pFile;
                pFile = NULL;
                break;
            }
            // caller is responsible for deleting the actual file,
            //  but we free the file name.
            CoTaskMemFree(stgMedium.lpszFileName);
            break;

        case TYMED_MFPICT:
        case TYMED_HGLOBAL:
            ASSERT(!_T("port CSharedFile"));
            pFile = new CVsSharedFile;
            ASSERT(pFile);
            if(!pFile)
                return NULL;
            ((CVsSharedFile*)pFile)->SetHandle(stgMedium.hGlobal);
            break;

        case TYMED_ISTREAM:
            ASSERT(!_T("port COleStreamFile"));
#if 0
            pFile = new COleStreamFile(stgMedium.pstm);
#endif
            break;

        default:
            // type not supported, so return error
            ::ReleaseStgMedium(&stgMedium);
            break;
        }
    }
    // store newly created CVsFile* and return
    return pFile;
}

HGLOBAL CVxOleDataObject::GetGlobalData(CLIPFORMAT cfFormat, LPFORMATETC lpFormatEtc)
{
    EnsureClipboardObject();
    ASSERT(m_bClipboard || m_lpDataObject != NULL);
    if (m_lpDataObject == NULL)
        return NULL;

    ASSERT(lpFormatEtc == NULL ||
        VxIsValidAddress(lpFormatEtc, sizeof(FORMATETC), FALSE));

    // fill in FORMATETC struct
    FORMATETC formatEtc;
    BOOL bFillFormatEtc = (lpFormatEtc == NULL);
    lpFormatEtc = _VxFillFormatEtc(lpFormatEtc, cfFormat, &formatEtc);
    ASSERT(lpFormatEtc);
    if(!lpFormatEtc)
        return FALSE;
    if (bFillFormatEtc)
        lpFormatEtc->tymed = TYMED_HGLOBAL|TYMED_MFPICT;
    ASSERT((lpFormatEtc->tymed & (TYMED_HGLOBAL|TYMED_MFPICT)) != 0);

    // attempt to get the data
    STGMEDIUM stgMedium;
    SCODE sc = m_lpDataObject->GetData(lpFormatEtc, &stgMedium);
    if (FAILED(sc))
        return FALSE;

    // handle just hGlobal types
    switch (stgMedium.tymed)
    {
    case TYMED_MFPICT:
    case TYMED_HGLOBAL:
        if (stgMedium.pUnkForRelease == NULL)
            return stgMedium.hGlobal;

        STGMEDIUM stgMediumDest;
        stgMediumDest.tymed = TYMED_NULL;
        stgMediumDest.pUnkForRelease = NULL;
        if (!_VxCopyStgMedium(lpFormatEtc->cfFormat, &stgMediumDest, &stgMedium))
        {
            ::ReleaseStgMedium(&stgMedium);
            return NULL;
        }
        ::ReleaseStgMedium(&stgMedium);
        return stgMediumDest.hGlobal;

    // default -- falls through to error condition...
    }

    ::ReleaseStgMedium(&stgMedium);
    return NULL;
}

BOOL CVxOleDataObject::GetData(CLIPFORMAT cfFormat, LPSTGMEDIUM lpStgMedium,
    LPFORMATETC lpFormatEtc)
{
    EnsureClipboardObject();
    ASSERT(m_bClipboard || m_lpDataObject != NULL);
    if (m_lpDataObject == NULL)
        return FALSE;

    ASSERT(VxIsValidAddress(lpStgMedium, sizeof(STGMEDIUM), FALSE));

    // fill in FORMATETC struct
    FORMATETC formatEtc;
    lpFormatEtc = _VxFillFormatEtc(lpFormatEtc, cfFormat, &formatEtc);

    // attempt to get the data
    SCODE sc = m_lpDataObject->GetData(lpFormatEtc, lpStgMedium);
    if (FAILED(sc))
        return FALSE;

    return TRUE;
}

BOOL CVxOleDataObject::IsDataAvailable(CLIPFORMAT cfFormat, LPFORMATETC lpFormatEtc)
{
    if (m_bClipboard)
    {
        // it is faster and more reliable to ask the real Win32 clipboard
        //  instead of the OLE clipboard.
        return ::IsClipboardFormatAvailable(cfFormat);
    }
    else
    {
        ASSERT(m_lpDataObject != NULL);
        ASSERT(lpFormatEtc == NULL ||
            VxIsValidAddress(lpFormatEtc, sizeof(FORMATETC), FALSE));

        // fill in FORMATETC struct
        FORMATETC formatEtc;
        lpFormatEtc = _VxFillFormatEtc(lpFormatEtc, cfFormat, &formatEtc);

        // attempt to get the data
        return m_lpDataObject->QueryGetData(lpFormatEtc) == S_OK;
    }
}

/////////////////////////////////////////////////////////////////////////////
// clipboard API wrappers

BOOL CVxOleDataObject::AttachClipboard()
{
    ASSERT(VxIsValidAddress(this, sizeof(CVxOleDataObject)));
    ASSERT(m_lpDataObject == NULL); // need to call release?
    ASSERT(!m_bClipboard); // already attached to clipboard?

    // set special "clipboard" flag for optimizations
    m_bClipboard = TRUE;
    return TRUE;
}

void CVxOleDataObject::EnsureClipboardObject()
{
    ASSERT(VxIsValidAddress(this, sizeof(CVxOleDataObject)));

    if (m_bClipboard && m_lpDataObject == NULL)
    {
        // get clipboard using OLE API
        LPDATAOBJECT lpDataObject;
        SCODE sc = ::OleGetClipboard(&lpDataObject);

        // attach CVxOleDataObject wrapper to IDataObject from clipboard
        if (sc == S_OK)
            Attach(lpDataObject, TRUE);
    }
}

/////////////////////////////////////////////////////////////////////////////
