//-----------------------------------------------------------------------------
// Microsoft Visual Studio
//
// Microsoft Confidential
// Copyright (C) 1994 - 2000 Microsoft Corporation. 
// All Rights Reserved.
//
// File: hu_image.h
// Area: IHierarchy Utilities implementation
//
// Contents:
//  CUIHierarchyImageList class
//-----------------------------------------------------------------------------
#if (_MSC_VER > 1000) && !defined(NO_PRAGMA_ONCE)
#pragma once
#endif

#ifndef _HU_IMAGE_H_
#define _HU_IMAGE_H_



typedef struct tagImageListItem
{
const GUID *pguidType;  // GUID pointer
union
    {
    UINT    uiIDI;      // Icon resource id
    UINT    uiIDB;      // Bitmap resource id
    UINT    iImage;     // Image index
    };
} ImageListItem, *PImageListItem;


typedef enum enumImageType
{
    IT_BITMAP,
    IT_ICON
} ImageType;

//-----------------------------------------------------------------------------
// Name: CUIHierarchyImageList
//
// Description:
// ImageList class to be used with win95 controls
//
// Hungarian: il
//
// Thread-Safety: None
//-----------------------------------------------------------------------------
class DllPort CUIHierarchyImageList
{
public:

    CUIHierarchyImageList(
        HINSTANCE hinst, 
        PImageListItem prgImageListItems,
        ImageType it,
        UINT cxImage,
        UINT cyImage);
    ~CUIHierarchyImageList(VOID);

    operator HIMAGELIST();

    INT IImageFromPguidType(const GUID *pguidType);
    const GUID *GuidTypeFromIImage(UINT iImage);

    // Check construction status
    //
    HRESULT GetStatus() {return m_hrStatus;}
    BOOL    FStatusOK() {return (SUCCEEDED(m_hrStatus));}

private:
    // Construction status.  After creating the namespace,
    // clients should call FStatusOK to make sure it was
    // constructed successfully.
    //
    HRESULT m_hrStatus;

    HIMAGELIST      m_hImageList;       // Handle to ImageList
    PImageListItem  m_rgImageListItems; // ImageList item array
};
typedef CUIHierarchyImageList   *PUIHierarchyImageList;


#endif // _HU_IMAGE_H_
