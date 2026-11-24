//---------------------------------------------------------------------------
// Microsoft Visual Studio
//
// Microsoft Confidential
// Copyright 1994 - 2000 Microsoft Corporation. All Rights Reserved.
//
// File: hu_nest.cpp
// Area: Hierarchy Utilities
//
// Contents:
// Definition (implementation) of the NestedContainer
//  defined in hu_nest.h
//---------------------------------------------------------------------------

#include "hu_pch.h"
#include "hu_nest.h"

//---------------------------------------------------------------------------
//
//---------------------------------------------------------------------------
CHierNestedContainer::~CHierNestedContainer(void)
{
}

//---------------------------------------------------------------------------
// VSHPROPID_FirstChild
//---------------------------------------------------------------------------
VSITEMID CHierNestedContainer::GetFirstChild(BOOL fDisplayOnly /*= TRUE*/)
{
    // nested containers have no children of their own. the shell is
    //  smart enough to find the chilren of the nested hierarcy
    //  but only if we return VSITEMID_NIL...
    return (VSITEMID)VSITEMID_NIL;
}

//---------------------------------------------------------------------------
// is this node expandable? VSHPROPID_Expandable
//---------------------------------------------------------------------------
BOOL CHierNestedContainer::Expandable() const
{
    return TRUE;
}

//---------------------------------------------------------------------------
//should this node be autoexpanded in the shell? VSHPROPID_ExpandByDefault
//---------------------------------------------------------------------------
BOOL CHierNestedContainer::ExpandByDefault() const
{
    return FALSE;
}

//---------------------------------------------------------------------------
// VSHPROPID_Caption
//---------------------------------------------------------------------------
HRESULT CHierNestedContainer::GetDisplayCaption(CString& strCaption)
{
    HRESULT hr;
    if (GetName().GetLength())
    {   // if we have a caption use it
        hr = CHierNode::GetDisplayCaption(strCaption);
    }
    else
    {   // otherwise ask the nested hierarchy
        CComVariant vt;
        if (GetNested() == NULL)
        {
            hr = InitNestedHierarchy();
            if (FAILED(hr)) 
                goto ERROR_EXIT;
        }
        ASSERT(GetNested() != NULL);
        hr = GetNested()->GetProperty((VSITEMID)VSITEMID_ROOT, VSHPROPID_Caption, &vt);

        if (SUCCEEDED(hr))
        {               
            SetName(V_BSTR(&vt));
            ASSERT(VT_BSTR == V_VT(&vt));
            strCaption = V_BSTR(&vt);
        }
    }
ERROR_EXIT:
    return hr;
}

//---------------------------------------------------------------------------
// Converts this node into a nested Hierarchy
//---------------------------------------------------------------------------
HRESULT CHierNestedContainer::GetNestedHierarchy
(
    REFIID riid,
    void **ppVsHierarchy,
    VSITEMID *pitemidNested)
{
    ASSERT(NULL != ppVsHierarchy && NULL == *ppVsHierarchy);
    ASSERT(NULL != pitemidNested && VSITEMID_NIL == *pitemidNested);

    HRESULT hr;
    if (GetNested() == NULL)
    {
        hr = InitNestedHierarchy();
        if (FAILED(hr)) { goto ERROR_EXIT; }
    }
    ASSERT(GetNested() != NULL);
    *pitemidNested = (VSITEMID)VSITEMID_ROOT;
    hr = GetNested()->QueryInterface(riid, ppVsHierarchy);

ERROR_EXIT:
    return hr;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
HRESULT CHierNestedContainer::EnumerateChildren(void)
{
    HRESULT hr = S_OK;
    if (GetNested() == NULL)
    {
        hr = InitNestedHierarchy();
    }
    return hr;
}

//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
HRESULT CHierNestedContainer::InitNestedHierarchy(void)
{
    return E_FAIL;
}
