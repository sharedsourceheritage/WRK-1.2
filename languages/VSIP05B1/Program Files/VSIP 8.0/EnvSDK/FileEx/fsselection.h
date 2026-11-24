
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

//*****************************************************************************
// Information Contained Herein Is Proprietary and Confidential.
//*****************************************************************************
// FSSelection.h
//
// Declaration of CFileSystemSelection
//
//*****************************************************************************

#pragma once

//*****************************************************************************
// CFileSystemSelection
//*****************************************************************************

class ATL_NO_VTABLE CFileSystemSelection :
    public CComObjectRootEx<CComSingleThreadModel>,
    public IFileSystemSelectionContainer,
    public ISelectionContainer,
    public ICategorizeProperties,
    public IDispatchImpl<IFileSystemSelection, &IID_IFileSystemSelection, &LIBID_FileExLib>
{
// Constructor/Destructor
public:
    CFileSystemSelection();
    ~CFileSystemSelection();

// COM Interface Map
BEGIN_COM_MAP(CFileSystemSelection)
    COM_INTERFACE_ENTRY(ISelectionContainer)
    COM_INTERFACE_ENTRY(IDispatch)
    COM_INTERFACE_ENTRY_IID(IID_ICategorizeProperties, ICategorizeProperties)
    COM_INTERFACE_ENTRY(IFileSystemSelection)
    COM_INTERFACE_ENTRY(IFileSystemSelectionContainer)
END_COM_MAP()

public:
// IFileSystemSelection
    STDMETHOD(Initialize)(
                    /*[in]*/ IServiceProvider* pSP);
    STDMETHOD(Close)(void);
    STDMETHOD(UpdateFolderSelection)(
                    /*[in]*/ DWORD_PTR dwFolderPtr);
    STDMETHOD(UpdateFileSelection)(
                    /*[in]*/ DWORD_PTR dwFilePtr);

// ISelectionContainer
    STDMETHOD(CountObjects)(
                    /*[in] */ DWORD  dwFlags, 
                    /*[out]*/ ULONG* pc);

    STDMETHOD(GetObjects)(
                    /*[in] */ DWORD      dwFlags, 
                    /*[in] */ ULONG      cObjects,
                    /*[out]*/ IUnknown** apUnkObjects);

    STDMETHOD(SelectObjects)(
                    /*[in]*/ ULONG      cSelect,
                    /*[in]*/ IUnknown** apUnkSelect,
                    /*[in]*/ DWORD      dwFlags);

// ICategorizeProperties
    STDMETHOD(MapPropertyToCategory)(
                    /*[in] */ DISPID   dispid,
                    /*[out]*/ PROPCAT* ppropcat);
    STDMETHOD(GetCategoryName)(
                    /*[in] */ PROPCAT propcat, 
                    /*[in] */ LCID    lcid,
                    /*[out]*/ BSTR*   pbstrName);

// IFileSystemSelection
    STDMETHOD(get_Name)(
                    /*[out,ret]*/ BSTR* pbstrName);
    STDMETHOD(get_Path)(
                    /*[out,ret]*/ BSTR* pbstrPath);
    STDMETHOD(get_Type)(
                    /*[out,ret]*/ BSTR* pbstrType);
    STDMETHOD(get_Size)(
                    /*[out,ret]*/ BSTR* pbstrSize);
    STDMETHOD(get_ReadOnly)(
                    /*[out,ret]*/ VARIANT_BOOL* pfReadOnly);
    STDMETHOD(get_Hidden)(
                    /*[out,ret]*/ VARIANT_BOOL* pfHidden);
    STDMETHOD(get_Compressed)(
                    /*[out,ret]*/ VARIANT_BOOL* pfCompressed);

// Attributes
protected:
    CComPtr<ITrackSelection> m_srpSelTracker;
    CFileSystemFolderItem* m_pSelFolder;
    CFileSystemFileItem* m_pSelFile;
};
