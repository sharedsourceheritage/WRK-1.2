
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// VsObjectListStub.cpp: implementation of the CVsObjectListStub class.
//
//////////////////////////////////////////////////////////////////////

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// This is only a temporary stub class (CVsObjectListStub) to enable 
// the testing of the "class view/object browser" support provided by 
// the implemented IVsLibraryMgr, IVsLibrary, and IVsObjectList interfaces.
// The IVsObjectList implemented in CVsObjectListStub provides 
// information for the members of a class (file in MyC) and will be 
// replaced with the parser support.
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


#include "stdafx.h"
#include "PrjInc.h" 
#include "VsObjectListStub.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

HRESULT CVsObjectListStub::CreateInstance(
    /* [in]  */ CBrowseNode *        pBrowseNode, 
    /* [in]  */ IVsLibrary*          pIVsLibrary, 
    /* [in]  */ LIB_LISTTYPE         eListType, 
    /* [in]  */ LIB_LISTFLAGS        flags, 
    /* [in]  */ VSOBSEARCHCRITERIA * pobSrch, 
    /* [out] */ IVsObjectList **     ppList)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsObjectListStub::CreateInstance ") );

    ExpectedPtrRet(ppList);
    InitParam(ppList);

    CComObject<CVsObjectListStub>* pco = NULL;
    HRESULT hr = CComObject<CVsObjectListStub>::CreateInstance(&pco);
    IfFailRet(hr);

    ASSERT(pco != NULL);
    pco->AddRef();
    hr = pco->Init(pBrowseNode, pIVsLibrary, eListType, flags, pobSrch);
    IfFailGo(hr);

    hr = pco->QueryInterface(
                IID_IVsObjectList, 
                (void**)ppList);

Error:
    if (pco)
        pco->Release();

    return hr;
    
    
}

class BrowseNodeInfo
{
public:
    BrowseNodeInfo(LPCWSTR wszName, BROWSE_NODE_TYPE bnt) : 
        m_cbstrName(wszName),
        m_bnt(bnt)
    {}

    CComBSTR& Name() {return m_cbstrName;}
    BROWSE_NODE_TYPE& Type(){return m_bnt;}
protected:
    BrowseNodeInfo(){}

    CComBSTR          m_cbstrName;
    BROWSE_NODE_TYPE  m_bnt;
};


 
STDMETHODIMP CVsObjectListStub::Init(
    /* [in]  */ CBrowseNode *        pBrowseNodeParent, 
    /* [in]  */ IVsLibrary*          pIVsLibrary, 
    /* [in]  */ LIB_LISTTYPE         eListType, 
    /* [in]  */ LIB_LISTFLAGS        flags, 
    /* [in]  */ VSOBSEARCHCRITERIA * pobSrch)
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLF, 
        _T(": CVsObjectListStub::Init ")
        _T(", this = 0x%x \n"), this );

    ExpectedPtrRet(pBrowseNodeParent);
    ExpectedPtrRet(pIVsLibrary);
    m_eListType = eListType;

    // create some data 
    HRESULT hr = E_FAIL;
    CBrowseNode* pBrowseNode = NULL;
    BrowseNodeInfo rgbni[] = {
        BrowseNodeInfo(L"method1", BNT_FUNCTION),
        BrowseNodeInfo(L"method2", BNT_FUNCTION),
        BrowseNodeInfo(L"member1", BNT_VARIABLE),
        BrowseNodeInfo(L"member2", BNT_VARIABLE)
     };
           
    CComPtr<ILibraryItem> srpILibraryItem;
    hr = pBrowseNodeParent->GetLibraryItem(&srpILibraryItem);
    IfFailRet(hr);
    VSITEMID itemId;
    hr = pBrowseNodeParent->GetItemId(&itemId);
    IfFailRet(hr);

    if (m_eListType == LLT_MEMBERS)
    {
        for (int i = 0; i < NUMBER_OF(rgbni); i++)
        {        
            // create a new browse node
            hr = CBrowseNode::CreateInstance(
                srpILibraryItem,
                rgbni[i].Name(),
                rgbni[i].Type(),
                itemId,
                0,
                &pBrowseNode);
            IfFailRet(hr);
            m_rgpBrowseNode.Add(pBrowseNode);
        }
    }

    m_srpIVsLibrary = pIVsLibrary;

    return S_OK;
}



CVsObjectListStub::CVsObjectListStub()
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLC, 
        _T(": CVsObjectListStub::CVsObjectListStub , this = 0x%x \n"), this );

}

CVsObjectListStub::~CVsObjectListStub()
{
    ENVSDK_TRACE(envsdkTraceGeneral, TLD, 
        _T(": CVsObjectListStub::~CVsObjectListStub , this = 0x%x \n"), this );

    // release the array
    ULONG cBrowseNodes = 0;
    GetItemCount(&cBrowseNodes);
    for (ULONG uIndex = 0 ; uIndex < cBrowseNodes; uIndex++)
    {
        delete m_rgpBrowseNode[uIndex];
    }
    m_rgpBrowseNode.RemoveAll();
}


