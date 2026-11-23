// This is a part of the Active Template Library.
// Copyright (C) Microsoft Corporation
// All rights reserved.
//
// This source code is only intended as a supplement to the
// Active Template Library Reference and related
// electronic documentation provided with the library.
// See these sources for detailed information regarding the	
// Active Template Library product.

#include "StdAfx.H"

#pragma warning( disable: 4073 )  // initializers put in library initialization area

namespace ATL
{

#pragma init_seg( lib )

#ifndef _WIN32_WCE
CImage::CInitGDIPlus CImage::s_initGDIPlus;
#endif // _WIN32_WCE

};  // namespace ATL
