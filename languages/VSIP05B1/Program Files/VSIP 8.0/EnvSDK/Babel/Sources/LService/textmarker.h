/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#ifndef textmarker_h
#define textmarker_h

/*---------------------------------------------------------
  TextMarker
-----------------------------------------------------------*/
HRESULT CreateMarker( in  IVsTextLines* textLines,
                      in  TextSpan&     span,
                      in  BSTR          tipText,
                      in  MARKERTYPE    markerType,
                      out IVsTextLineMarker** textLineMarker );

#endif
