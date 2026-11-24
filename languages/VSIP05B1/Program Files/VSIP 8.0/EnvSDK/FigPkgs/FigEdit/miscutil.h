
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

// miscutil.h : miscellaneous utility routines

#pragma once

//==========================================================================
//                                                              User Context

// Create an empty IVsUserContext object
HRESULT CreateUserContext(
    /* [out] */ IVsUserContext** ppUserContext);

HRESULT AddUserContextForFigLineType(
    /* [in] */ IVsUserContext* pIVsUserContext, 
    /* [in] */ FigLineType     flt);

//                                                              User Context
//==========================================================================
//                                                              User Context
