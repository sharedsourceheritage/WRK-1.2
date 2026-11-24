/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#ifndef TextTipData_h
#define TextTipData_h

// CTextTipData handles quick info
class CTextTipData : 
    public IVsTextTipData
{
public:
    CTextTipData();
    HRESULT Init(IServiceProvider*, IVsTextView* );
    void    Close();
    ~CTextTipData();

    HRESULT Update (PCWSTR pszText, long iPos, long iLen);
    void    Dismiss ();
    void    CheckCaretPosition ();
    BOOL    IsActive () { return m_fWindowUp; }

    // IVsTextTipData
    STDMETHOD(GetTipText)(BSTR *pbstrText, BOOL *pbGetFontInfo);
    STDMETHOD(GetTipFontInfo)(long iChars, ULONG *pdwFontInfo);
    STDMETHOD(GetContextStream)(long *piPos, long *piLength);
    STDMETHOD_(void, OnDismiss)();
    STDMETHOD_(void, UpdateView)();

    // IUnknown
    STDMETHOD_(ULONG, AddRef());
    STDMETHOD_(ULONG, Release());
    STDMETHOD   (QueryInterface)(REFIID riid, void **ppvObj);

protected:

    IVsTextView* GetIVsTextView() {return m_pIVsTextView;}

protected:

    IVsTextTipWindow*   m_pIVsTextTipWindow;
    IVsTextView*        m_pIVsTextView;     // NOTE:  Not ref'd

    long                m_iPos;
    long                m_iLen;
    BSTR                m_bstrText;
    BOOL                m_fWindowUp;

    ULONG               m_refCount;
};


#endif
