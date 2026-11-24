
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// VsObjectListStub.h: interface for the CVsObjectListStub class.
//
//////////////////////////////////////////////////////////////////////

#pragma once
 
class CVsObjectListStub : 
    public  CVsObjectList
{
public:
    BEGIN_COM_MAP(CVsObjectList)
        COM_INTERFACE_ENTRY(IVsObjectList)
    END_COM_MAP()

public:
    static HRESULT CreateInstance(
        /* [in]  */ CBrowseNode *        pBrowseNode, 
        /* [in]  */ IVsLibrary*          pIVsLibrary, 
        /* [in]  */ LIB_LISTTYPE         eListType, 
        /* [in]  */ LIB_LISTFLAGS        flags, 
        /* [in]  */ VSOBSEARCHCRITERIA * pobSrch, 
        /* [out] */ IVsObjectList **     ppList);

protected:
    STDMETHOD(Init)(
        /* [in]  */ CBrowseNode *        pBrowseNode, 
        /* [in]  */ IVsLibrary*          pIVsLibrary, 
        /* [in]  */ LIB_LISTTYPE         eListType, 
        /* [in]  */ LIB_LISTFLAGS        flags, 
        /* [in]  */ VSOBSEARCHCRITERIA * pobSrch); 

    CVsObjectListStub();
    virtual ~CVsObjectListStub();

};

