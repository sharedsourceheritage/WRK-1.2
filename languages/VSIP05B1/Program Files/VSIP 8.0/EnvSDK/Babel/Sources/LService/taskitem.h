/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#ifndef taskitem_h
#define taskitem_h

/*---------------------------------------------------------
  CreateTask
-----------------------------------------------------------*/
HRESULT CreateTask( in IServiceProvider* provider,
                    in IVsTextLines*     textLines,
                    in MARKERTYPE        markerType,                  
                    in BSTR tipText, in const wchar_t* fileName, bool readOnly,
                    in TextSpan& span,
                    in VSTASKPRIORITY priority, in VSTASKBITMAP bitmap, in VSTASKCATEGORY category,
                    out IVsTaskItem** taskItem
                  );

#endif
