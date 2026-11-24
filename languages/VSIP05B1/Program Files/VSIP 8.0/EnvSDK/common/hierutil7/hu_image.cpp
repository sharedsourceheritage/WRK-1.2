//-----------------------------------------------------------------------------
// Microsoft Visual Studio
//
// Microsoft Confidential
// Copyright 1994 - 2000 Microsoft Corporation. All Rights Reserved.
//
// File: hu_image.cpp
// Area: IHierarchy Utilities implementation
//
// Contents:
//  CUIHierarchyImageList class
//-----------------------------------------------------------------------------

// Includes -------------------------------------------------------------------
#include "hu_pch.h"
#include "hu_image.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//-----------------------------------------------------------------------------
// Name: CUIHierarchyImageList::CUIHierarchyImageList()
//
// Description:
//  CUIHierarchyImageList class constructor -- does the actual work of creating
//  an image list, setting m_hrStatus to a failure code that callers can check
//  later to see if this succeeded or not.
//
//-----------------------------------------------------------------------------
CUIHierarchyImageList::CUIHierarchyImageList
(
    HINSTANCE       hInst,              // in: Resource module instance handle
    PImageListItem  prgImageListItems,  // in: ImageList item array
    ImageType       it,                 // in: Image type
    UINT            cxImage,            // in: Image width
    UINT            cyImage             // in: Image height
) :
    m_hImageList(NULL),
    m_rgImageListItems(NULL),
    m_hrStatus(S_OK)
{
    HBITMAP hBitmap = NULL; // Bitmap handle
    HICON   hIcon = NULL;   // Icon handle

    // Establish ImageList item array
    //
    for (UINT i = 0; prgImageListItems[i].pguidType; i++)
        NULL;

    m_rgImageListItems = new ImageListItem[i + 1];

    // Create ImageList
    //
    m_hImageList = ImageList_Create(
                        cxImage,    // X size of one image
                        cyImage,    // Y size of one image
                        TRUE,       // Masked images
                        i,          // Number of images in this list
                        0);         // No "growing" bitmaps in this list.

    if (!m_hImageList)
    {
        m_hrStatus = E_UNEXPECTED;
        return;
    }

    // Cycle through image list item array items
    //
    for (i = 0; FStatusOK() && prgImageListItems[i].pguidType; i++)
    {
        // Add item to ImageList
        //
        if (IT_BITMAP == it)
        {
            hBitmap = LoadBitmap(
                        hInst,
                        MAKEINTRESOURCE(prgImageListItems[i].uiIDB));

            if (NULL == hBitmap)
                m_hrStatus = E_UNEXPECTED;
            else
            {
                m_rgImageListItems[i].iImage = ImageList_AddMasked(
                                                    m_hImageList,
                                                    hBitmap,
                                                    RGB(255, 0, 255));
                DeleteObject(hBitmap);
                hBitmap = NULL;
            }
        }
        else if (IT_ICON == it)
        {
            hIcon = LoadIcon(
                        hInst,
                        MAKEINTRESOURCE(prgImageListItems[i].uiIDI));

            if (NULL == hIcon)
                m_hrStatus = E_UNEXPECTED;
            else
            {
                m_rgImageListItems[i].iImage = ImageList_AddIcon(
                                                    m_hImageList,
                                                    hIcon);
                DeleteObject(hIcon);
                hIcon = NULL;
            }
        }

        if (FStatusOK())
            m_rgImageListItems[i].pguidType = prgImageListItems[i].pguidType;
    }

    m_rgImageListItems[i].pguidType = NULL;

    // Ensure all items added to ImageList
    //
    if (((UINT) ImageList_GetImageCount(m_hImageList)) < i)
    {
        m_hrStatus = E_FAIL;
    }
}


//-----------------------------------------------------------------------------
// Name: CUIHierarchyImageList::~CUIHierarchyImageList()
//
// Description:
// CUIHierarchyImageList class destructor
//
// Thread-Safety: None
//
// Return Values: None
//-----------------------------------------------------------------------------
CUIHierarchyImageList::~CUIHierarchyImageList()
{
    delete [] m_rgImageListItems;
    if (m_hImageList)
        ImageList_Destroy(m_hImageList);
}


//-----------------------------------------------------------------------------
// Name: CUIHierarchyImageList::operator HIMAGELIST()
//
// Description:
// CUIHierarchyImageList class HIMAGELIST conversion operator
//
// Thread-Safety: None
//
// Return Values:
// HIMAGELIST to internal image list pointer
//-----------------------------------------------------------------------------
CUIHierarchyImageList::operator HIMAGELIST()
{
    return m_hImageList;
}


//-----------------------------------------------------------------------------
// Name: CUIHierarchyImageList::IImageFromPguidType()
//
// Description:
// Converts item type to image index
//
// Thread-Safety: None
//
// Return Values:
// Image index
//-----------------------------------------------------------------------------
INT CUIHierarchyImageList::IImageFromPguidType(const GUID *pguidType)
{
    // Cycle through image list item array items
    //
    for (INT i = 0; m_rgImageListItems[i].pguidType; i++)
    {
        // Check whether match
        if (*pguidType == *m_rgImageListItems[i].pguidType)
            return m_rgImageListItems[i].iImage;
    }

    // didn't find requested GUID, return negative number
    //
    return -1;
}


//-----------------------------------------------------------------------------
// Name: CUIHierarchyImageList::GuidTypeFromIImage()
//
// Description:
// Converts image index to item type
//
// Thread-Safety: None
// Return Values:
// Node type
//-----------------------------------------------------------------------------
const GUID *CUIHierarchyImageList::GuidTypeFromIImage(UINT  iImage)
{
    UINT    i;  // Index

    // Cycle through image list item array items
    for (i = 0; m_rgImageListItems[i].pguidType; i++)
    {
        // Check whether match
        if (iImage == m_rgImageListItems[i].iImage)
            return m_rgImageListItems[i].pguidType;
    }

    return NULL;
}
