//---------------------------------------------------------------------------
// Microsoft Visual Studio
//
// Copyright (c) 1998-2000 Microsoft Corporation Inc.
// All rights reserved
//
// HierTaskList.h  - Implements a generic task items and task enumerator
//
//---------------------------------------------------------------------------
#if (_MSC_VER > 1000) && !defined(NO_PRAGMA_ONCE)
#pragma once
#endif
#ifndef __HIERTASKLIST_H__
#define __HIERTASKLIST_H__
#include "hu_node.h"

class CHierTaskItemBase;
class CHierEnumTaskItems;

//-----------------------------------------------------------------------------
// CHierTaskItemBase: base implementation for IVsTaskItem 
//-----------------------------------------------------------------------------

class CHierTaskItemBase :
    public IVsTaskItem,
    public IVsProvideUserContext,
    public CComObjectRootEx<CComSingleThreadModel>
{
public:
    CHierTaskItemBase();

    BEGIN_COM_MAP(CHierTaskItemBase)
    COM_INTERFACE_ENTRY(IVsTaskItem)
    COM_INTERFACE_ENTRY(IVsProvideUserContext)
    END_COM_MAP()
    DECLARE_NOT_AGGREGATABLE(CHierTaskItemBase)

// IVsTaskItem methods
public:
    STDMETHOD(get_Priority)(VSTASKPRIORITY *ptpPriority);
    STDMETHOD(put_Priority)(VSTASKPRIORITY ptpPriority);

    STDMETHOD(get_Category)(VSTASKCATEGORY *pCat);
    STDMETHOD(get_SubcategoryIndex)(long *pIndex);
    STDMETHOD(get_ImageListIndex)(long *pIndex);

    STDMETHOD(get_Checked)(BOOL *pfChecked);
    STDMETHOD(put_Checked)(BOOL fChecked);

    STDMETHOD(get_Text)(BSTR *pbstrText);
    STDMETHOD(put_Text)(BSTR bstrName);

    STDMETHOD(get_Document)(BSTR *pbstrMkDocument);
    STDMETHOD(get_Line)(long *piLine);
    STDMETHOD(get_Column)(long *piCol);

    STDMETHOD(get_CanDelete)(BOOL *fCanDelete);
    STDMETHOD(get_IsReadOnly)(VSTASKFIELD field, BOOL *fReadOnly);
    STDMETHOD(get_HasHelp)(BOOL *pfHasHelp);

    STDMETHOD(NavigateTo)();
    STDMETHOD(NavigateToHelp)();

    STDMETHOD(OnFilterTask)(BOOL fVisible);
    STDMETHOD(OnDeleteTask)();
    
    void SetHelpKeyword(LPCWSTR pszHelpKeyword) {m_strHelpKeyword = pszHelpKeyword;}

// IVsProvideUserContext methods
public:
    STDMETHOD(GetUserContext)(IVsUserContext** ppUserContext);

protected:
    // Since all taskitems support this field we define it generically. Can use put_Text to set it.
    CString         m_strText;
    CString         m_strHelpKeyword;

    // Protected to force Release().
    virtual ~CHierTaskItemBase() {}

};

//-----------------------------------------------------------------------------
// CHierEnumTaskItems: implements IVsEnumTaskItems
//-----------------------------------------------------------------------------
class CHierEnumTaskItems :
    public IVsEnumTaskItems,
    public CComObjectRootEx<CComSingleThreadModel>
{
public:
        CHierEnumTaskItems();

    // Takes ownership of the array (ie. free's it)
    void Init(CIVsTaskItemArray* pTaskItemArray);

    BEGIN_COM_MAP(CHierEnumTaskItems)
    COM_INTERFACE_ENTRY(IVsEnumTaskItems)
    END_COM_MAP()

// IVsEnumTaskItems methods
public:
    STDMETHOD(Next)(ULONG celt, IVsTaskItem **rgelt, ULONG *pceltFetched);
    STDMETHOD(Skip)(ULONG celt);
    STDMETHOD(Reset)(void);
    STDMETHOD(Clone)(IVsEnumTaskItems **ppenum);

protected:
    virtual ~CHierEnumTaskItems();

    CIVsTaskItemArray* m_pTaskItemArray;
    int             m_index;
};

#endif
// End of hiertasklist.h
