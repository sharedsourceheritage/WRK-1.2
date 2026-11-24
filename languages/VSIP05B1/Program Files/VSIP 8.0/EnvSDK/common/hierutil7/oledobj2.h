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
#if (_MSC_VER > 1000) && !defined(NO_PRAGMA_ONCE)
#pragma once
#endif

#ifndef __OLEDOBJ2_H__
#define __OLEDOBJ2_H__

#include "mfcincl.h"

struct VX_DATACACHE_ENTRY;

extern LPFORMATETC _VxFillFormatEtc(
    LPFORMATETC lpFormatEtc, CLIPFORMAT cfFormat, LPFORMATETC lpFormatEtcFill);

extern DVTARGETDEVICE* _VxOleCopyTargetDevice(DVTARGETDEVICE* ptdSrc);

extern void _VxOleCopyFormatEtc(LPFORMATETC petcDest, LPFORMATETC petcSrc);

extern BOOL _VxCopyStgMedium(
    CLIPFORMAT cfFormat, LPSTGMEDIUM lpDest, LPSTGMEDIUM lpSource);

//---------------------------------------------------------------------------
// CVxOleDataObject -- simple wrapper for IDataObject
//---------------------------------------------------------------------------
class CVxOleDataObject
{
// Constructors
public:
             CVxOleDataObject();
    virtual  ~CVxOleDataObject();

// Operations
    void Attach(LPDATAOBJECT lpDataObject, BOOL bAutoRelease = TRUE);
    LPDATAOBJECT Detach();  // detach and get ownership of m_lpDataObject
    void Release(); // detach and Release ownership of m_lpDataObject
    BOOL AttachClipboard(); // attach to current clipboard object

// Attributes
    void BeginEnumFormats();
    BOOL GetNextFormat(LPFORMATETC lpFormatEtc);
    CVsFile* GetFileData(CLIPFORMAT cfFormat, LPFORMATETC lpFormatEtc = NULL);
    HGLOBAL GetGlobalData(CLIPFORMAT cfFormat, LPFORMATETC lpFormatEtc = NULL);
    BOOL GetData(CLIPFORMAT cfFormat, LPSTGMEDIUM lpStgMedium,
        LPFORMATETC lpFormatEtc = NULL);
    BOOL IsDataAvailable(CLIPFORMAT cfFormat, LPFORMATETC lpFormatEtc = NULL);

// Implementation
public:
    LPDATAOBJECT m_lpDataObject;
    LPENUMFORMATETC m_lpEnumerator;

    // advanced use and implementation
    LPDATAOBJECT GetIDataObject(BOOL bAddRef);
    void EnsureClipboardObject();
    BOOL m_bClipboard;      // TRUE if represents the Win32 clipboard

protected:
    BOOL m_bAutoRelease;    // TRUE if destructor should call Release

private:
    // Disable the copy constructor and assignment by default so you will get
    //   compiler errors instead of unexpected behaviour if you pass objects
    //   by value or assign objects.
    CVxOleDataObject(const CVxOleDataObject&);  // no implementation
    void operator=(const CVxOleDataObject&);  // no implementation
};

//---------------------------------------------------------------------------
// CVxOleDataSource -- wrapper for implementing IDataObject
//  (works similar to how data is provided on the clipboard)
//---------------------------------------------------------------------------
class CVxOleDataSource :
     public CComObjectRootEx<CComSingleThreadModel>
    ,public IDataObject
{
protected:  // Destructors (protected to prevent accidental deletion
    virtual ~CVxOleDataSource();

public: // Constructors
    CVxOleDataSource();

BEGIN_COM_MAP(CVxOleDataSource)
    COM_INTERFACE_ENTRY(IDataObject)
END_COM_MAP()
DECLARE_NOT_AGGREGATABLE(CVxOleDataSource)

// IDataObject
public:
    STDMETHOD(GetData)( 
            /* [unique][in] */ FORMATETC *pformatetcIn,
            /* [out] */ STGMEDIUM *pmedium);
        
    STDMETHOD(GetDataHere)( 
            /* [unique][in] */ FORMATETC *pformatetc,
            /* [out][in] */ STGMEDIUM *pmedium);
        
    STDMETHOD(QueryGetData)( 
            /* [unique][in] */ FORMATETC *pformatetc);
        
    STDMETHOD(GetCanonicalFormatEtc)( 
            /* [unique][in] */ FORMATETC *pformatectIn,
            /* [out] */ FORMATETC *pformatetcOut);
        
    STDMETHOD(SetData)( 
            /* [unique][in] */ FORMATETC *pformatetc,
            /* [unique][in] */ STGMEDIUM *pmedium,
            /* [in] */ BOOL fRelease);
        
    STDMETHOD(EnumFormatEtc)( 
            /* [in] */ DWORD dwDirection,
            /* [out] */ IEnumFORMATETC **ppenumFormatEtc);
        
    STDMETHOD(DAdvise)( 
            /* [in] */ FORMATETC *pformatetc,
            /* [in] */ DWORD advf,
            /* [unique][in] */ IAdviseSink *pAdvSink,
            /* [out] */ DWORD *pdwConnection);
        
    STDMETHOD(DUnadvise)( 
            /* [in] */ DWORD dwConnection);
        
    STDMETHOD(EnumDAdvise)( 
            /* [out] */ IEnumSTATDATA **ppenumAdvise);

public: // IDataObjectImpl support
    CComPtr<IDataAdviseHolder> m_spDataAdviseHolder;

public:
// Operations
    void Empty();   // empty cache (similar to ::EmptyClipboard)

    // CacheData & DelayRenderData operations similar to ::SetClipboardData
    void CacheGlobalData(CLIPFORMAT cfFormat, HGLOBAL hGlobal,
        LPFORMATETC lpFormatEtc = NULL);    // for HGLOBAL based data
    void DelayRenderFileData(CLIPFORMAT cfFormat,
        LPFORMATETC lpFormatEtc = NULL);    // for CVsFile* based delayed render

    // Clipboard and Drag/Drop access
#if 0
    DROPEFFECT DoDragDrop(
        DWORD dwEffects = DROPEFFECT_COPY|DROPEFFECT_MOVE|DROPEFFECT_LINK,
        LPCRECT lpRectStartDrag = NULL,
        COleDropSource* pDropSource = NULL);
#endif
    void SetClipboard();
    static void PASCAL FlushClipboard();
//  static CVxOleDataSource* PASCAL GetClipboardOwner();

    // Advanced: STGMEDIUM based cached data
    void CacheData(CLIPFORMAT cfFormat, LPSTGMEDIUM lpStgMedium,
        LPFORMATETC lpFormatEtc = NULL);    // for LPSTGMEDIUM based data
    // Advanced: STGMEDIUM or HGLOBAL based delayed render
    void DelayRenderData(CLIPFORMAT cfFormat, LPFORMATETC lpFormatEtc = NULL);

    // Advanced: support for SetData in COleServerItem
    //  (not generally useful for clipboard or drag/drop operations)
    void DelaySetData(CLIPFORMAT cfFormat, LPFORMATETC lpFormatEtc = NULL);

// Overidables
    virtual BOOL OnRenderGlobalData(LPFORMATETC lpFormatEtc, HGLOBAL* phGlobal);
    virtual BOOL OnRenderFileData(LPFORMATETC lpFormatEtc, CVsFile* pFile);
    virtual BOOL OnRenderData(LPFORMATETC lpFormatEtc, LPSTGMEDIUM lpStgMedium);
        // OnRenderFileData and OnRenderGlobalData are called by
        //  the default implementation of OnRenderData.

    virtual BOOL OnSetData(LPFORMATETC lpFormatEtc, LPSTGMEDIUM lpStgMedium,
        BOOL bRelease);
        // used only in COleServerItem implementation

// Implementation
public:

#ifdef _DEBUG
    virtual void AssertValid() const;
//  virtual void Dump(CDumpContext& dc) const;
#endif

protected:
    VX_DATACACHE_ENTRY* m_pDataCache;  // data cache itself
    UINT m_nMaxSize;    // current allocated size
    UINT m_nSize;       // current size of the cache
    UINT m_nGrowBy;     // number of cache elements to grow by for new allocs

    VX_DATACACHE_ENTRY* Lookup(
        LPFORMATETC lpFormatEtc, DATADIR nDataDir) const;
    VX_DATACACHE_ENTRY* GetCacheEntry(
        LPFORMATETC lpFormatEtc, DATADIR nDataDir);

};

#endif //__OLEDOBJ2_H__
