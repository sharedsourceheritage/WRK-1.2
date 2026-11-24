//---------------------------------------------------------------------------
// Microsoft Visual Studio
//
// Microsoft Confidential
// Copyright (C) 1994 - 2000 Microsoft Corporation. 
// All Rights Reserved.
//
// File: hu_nest.h
// Area: Hierarchy Utilities
//
// Contents:
//  Declaration of a Nested Hierarchy class
//---------------------------------------------------------------------------
#if (_MSC_VER > 1000) && !defined(NO_PRAGMA_ONCE)
#pragma once
#endif

#ifndef __HU_NEST_H__
#define __HU_NEST_H__

#include "hu_ctnr.h"

class ATL_NO_VTABLE CHierNestedContainer :
    public CHierNode
{
protected:
    virtual ~CHierNestedContainer(void);

public:
    // RTTI implementation
    IMPLEMENT_RTTI(CHierNestedContainer)

    // CHierNode overrides
    virtual VSITEMID GetFirstChild(BOOL fDisplayOnly = TRUE);
    // CHierNode overrides
    virtual BOOL Expandable() const;
    virtual BOOL ExpandByDefault() const;

    virtual HRESULT GetNestedHierarchy(REFIID, void **, VSITEMID *);

    virtual HRESULT GetDisplayCaption(CString& strCaption);

public: // CHierContainer overrides
    virtual HRESULT EnumerateChildren(void);

public: // CHierNestedContainer
    CComPtr<IVsHierarchy>& GetNested(void)
    {
        return m_srpNestedHierarchy;
    }
    const CComPtr<IVsHierarchy>& GetNested(void) const
    {
        return m_srpNestedHierarchy;
    }
    void SetNestedHierarchy(IVsHierarchy* pVsHierarchy)
    {
        ASSERT(NULL != pVsHierarchy);
        m_srpNestedHierarchy = pVsHierarchy;
    }

protected:  // CHierNestedContainer
    virtual HRESULT InitNestedHierarchy(void);

protected:  // data members
    CComPtr<IVsHierarchy> m_srpNestedHierarchy;
};

#endif // __HU_NEST_H__

