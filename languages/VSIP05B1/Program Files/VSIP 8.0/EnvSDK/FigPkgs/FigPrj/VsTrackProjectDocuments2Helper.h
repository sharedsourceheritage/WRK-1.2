
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/


// VsTrackProjectDocuments2Helper.h 

#pragma once

// Flags
typedef enum tagProjectEventFlags
{	
    ProjectEventFlags_None             = 0,
	ProjectEventFlags_IsNestedProject  = 0x1

} ProjectEventFlags;


// All events involving Adding, Removing, and Renaming of items in the project
// need to be announced to the IVsTrackProjectDocuments service. This service
// inturns manages broadcasting these events to interesting parties.
// For example, these events allow the Source Code Control (SCC) manager
// to coordinate SCC for the project items. These events allow the debugger to
// manage its list of breakpoints. There will be other interested parties.
//
// The class encapsulates the shell's IVsTrackProjectDocuments2 interface
// That makes it more consistent for project's rename/add/delete code.
// These methods are invoked when an project change originates internally. 
// The methods just pass off to the shell methods in 
// SID_SVsTrackProjectDocuments2, which notifies other hierarchies
// that we are about to change or have changed some files.
// 

class CVsTrackProjectDocuments2Helper
{
public:

    CVsTrackProjectDocuments2Helper(
        /* [in] */ IVsProject* pIVsProject);

    //----------------------------------------------------------------------
    // Function:    CanAddItem
    // Parameters: 
    //   /* [in] */ LPCOLESTR          pszFile,
    //   /* [in] */ ProjectEventFlags  flags /* = ProjectEventsFlags_None */)
    //
    // Returns:     HRESULT
    //              S_OK    - ok to add
    //              E_ABORT - action was aborted
    //              E_xxx   - failure
    // Notes:
    //----------------------------------------------------------------------
    virtual HRESULT CanAddItem(
        /* [in] */ LPCOLESTR          pszFile,
        /* [in] */ ProjectEventFlags  flags = ProjectEventFlags_None );

    virtual void OnItemAdded( 
        /* [in] */ CHierNode*         pCHierNode,
        /* [in] */ ProjectEventFlags  flags = ProjectEventFlags_None );

    virtual HRESULT CanRenameItem( 
        /* [in] */ CHierNode*         pCHierNode,
        /* [in] */ LPCOLESTR          pszNewName,
        /* [in] */ ProjectEventFlags  flags = ProjectEventFlags_None );

    virtual void OnItemRenamed(
        /* [in] */ CHierNode*         pCHierNode,
        /* [in] */ LPCOLESTR          pszOldName,
        /* [in] */ ProjectEventFlags  flags = ProjectEventFlags_None );

    virtual HRESULT CVsTrackProjectDocuments2Helper::CanDeleteItem(
        /* [in] */ CHierNode*         pCHierNode,
        /* [in] */ ProjectEventFlags  flags = ProjectEventFlags_None );

    virtual void CVsTrackProjectDocuments2Helper::OnItemDeleted(
        /* [in] */ LPCOLESTR          pszFile,
        /* [in] */ ProjectEventFlags  flags = ProjectEventFlags_None );

protected:
    CComPtr<IVsTrackProjectDocuments2> GetIVsTrackProjectDocuments2();

protected:
    // strong ref on the IVsProject because can't call any methods on 
    // this class unless IVsProject is alive
    CComPtr<IVsProject>     m_srpIVsProject;
};
