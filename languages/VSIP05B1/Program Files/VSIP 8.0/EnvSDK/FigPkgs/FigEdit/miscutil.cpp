
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// miscutil.cpp : miscellaneous utility routines

#include "stdafx.h"  // system includes
#include "PrjInc.h"  // project includes

//==========================================================================
//                                                              User Context

// Create an empty IVsUserContext object
HRESULT CreateUserContext(
    /* [out] */ IVsUserContext** ppUserContext)
{
    ExpectedPtrRet(ppUserContext);
    *ppUserContext = NULL;

    HRESULT hr = E_FAIL;        
    IVsMonitorUserContext* pmuc = NULL;

    hr = _AtlModule.QueryService(
                SID_SVsMonitorUserContext, 
                IID_IVsMonitorUserContext, 
                (void**)&pmuc );
    IfFailRet(hr);
    ExpectedExprRet(pmuc!=NULL);

    hr = pmuc->CreateEmptyContext(ppUserContext);
    pmuc->Release(); 
            
    return hr;
}


HRESULT AddUserContextForFigLineType(
    /* [in] */ IVsUserContext* pIVsUserContext, 
    /* [in] */ FigLineType     flt)
{
    ExpectedPtrRet(pIVsUserContext);

    HRESULT hr = S_OK;

    switch (flt)
    {
        case FigArrow:
            hr = pIVsUserContext->AddAttribute(VSUC_Usage_LookupF1, L"keyword", L"vs.envsdk.figprj.arrow");
            break;
        case FigCircle:
            hr = pIVsUserContext->AddAttribute(VSUC_Usage_LookupF1, L"keyword", L"vs.envsdk.figprj.circle");
            break;
        case FigRectangle:
            hr = pIVsUserContext->AddAttribute(VSUC_Usage_LookupF1, L"keyword", L"vs.envsdk.figprj.rectangle");
            break;
        case FigComment:
            hr = pIVsUserContext->AddAttribute(VSUC_Usage_LookupF1, L"keyword", L"vs.envsdk.figprj.comment");
            break;
        default:
            hr = S_FALSE;
    }

    return hr;
}

//                                                              User Context
//==========================================================================
