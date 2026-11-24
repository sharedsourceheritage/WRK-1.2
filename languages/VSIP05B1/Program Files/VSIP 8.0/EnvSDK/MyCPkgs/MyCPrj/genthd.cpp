
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#include "stdafx.h"
#include "PrjInc.h"

CVsThreadBase::CVsThreadBase
(
DWORD dwStackSize,
DWORD dwCreationFlags,
DWORD dwTickPeriod
) : m_hThread(0),
	m_dwStackSize(dwStackSize),
	m_dwCreationFlags(dwCreationFlags),
	m_dwTickPeriod(dwTickPeriod),
	m_pvArgument(NULL),
	m_hEvent(NULL),
	m_fKillChild(false),
	m_pIStream_IUnknown_Parent(NULL),
	m_pIUnknown_Parent(NULL)
{
	m_hEvent = ::CreateEvent(
					NULL,		// security attributes
					FALSE,		// FALSE => auto reset event
					FALSE,		// FALSE => initially unsignalled
					NULL);		// NULL => anonymous
}

CVsThreadBase::~CVsThreadBase()
{
	ASSERT(m_hThread == 0);
	ASSERT(m_pIStream_IUnknown_Parent == NULL);
	ASSERT(m_pIUnknown_Parent == NULL);

	if (m_hThread != 0)
	{
		::CloseHandle(m_hThread);
		m_hThread = 0;
	}

	if (m_hEvent != 0)
	{
		::CloseHandle(m_hEvent);
		m_hEvent = 0;
	}
}

HRESULT CVsThreadBase::MarshalParentIUnknown(IUnknown *pIUnknown)
{
	ASSERT(m_pIStream_IUnknown_Parent == NULL);
    ExpectedPtrRet(pIUnknown);
	return ::CoMarshalInterThreadInterfaceInStream(
				IID_IUnknown,
				pIUnknown,
				&m_pIStream_IUnknown_Parent);
}

HRESULT CVsThreadBase::UnmarshalParentIUnknown()
{
	if (m_pIStream_IUnknown_Parent == NULL)
		return E_UNEXPECTED;

	ASSERT(m_pIUnknown_Parent == NULL);
	HRESULT hr;

	hr = ::CoGetInterfaceAndReleaseStream(
				m_pIStream_IUnknown_Parent,
				IID_IUnknown,
				(void **) &m_pIUnknown_Parent);
	m_pIStream_IUnknown_Parent = NULL;
	return hr;
}

void CVsThreadBase::InternalTick(BOOL &rfContinue)
{
	if (m_fKillChild)
		rfContinue = FALSE;
}

void CVsThreadBase::Detach()
{
	if (m_hThread != 0)
		this->ReleaseThreadHandle();
}

void CVsThreadBase::ReleaseThreadHandle()
{
	ASSERT(m_hThread != 0);
	BOOL fSucceeded = ::CloseHandle(m_hThread);
	m_hThread = 0;
}

bool CVsThreadBase::IsPreviousOperationFinished()
{
	if (m_hThread != NULL)
	{
		if (m_fChildDone)
		{
			BOOL fSucceeded = ::CloseHandle(m_hThread);

			m_hThread = NULL;
			return true;
		}
		else
			return false;
	}

	// In case one of the branches in the previous if statement is changed to
	// allow fall-through by accident...
	ASSERT(m_hThread == NULL);
	return true;
}

void CVsThreadBase::WaitAndTick(DWORD dwMilliseconds, BOOL fTickOnMessage, BOOL &rfCancelled)
{
	rfCancelled = false;

	ASSERT(m_hThread != 0);
	if (m_hThread == 0)
		return;

	// This is actually where we issue the ticks, as the child thread may or may not
	// be able to correctly issue them across the thread boundaries.
	DWORD dwMSThisWait = m_dwTickPeriod;
	while ((!m_fChildDone) && (dwMilliseconds != 0))
	{
		if (dwMilliseconds < dwMSThisWait)
			dwMSThisWait = dwMilliseconds;

 		DWORD dwResult = ::MsgWaitForMultipleObjects(
 								1, &m_hEvent,	// one hEvent we're waiting for
 								FALSE,			// wait for just one
 								dwMSThisWait,
 								fTickOnMessage ? QS_ALLINPUT : 0);
 		if ((dwResult == WAIT_TIMEOUT) ||
 			(dwResult == WAIT_OBJECT_0 + 1))
		{
			BOOL fContinue = TRUE;
			this->InternalTick(fContinue);
			if (!fContinue)
			{
				rfCancelled = true;
				return;
			}

			if (dwMilliseconds != INFINITE)
				dwMilliseconds -= dwMSThisWait;

			// Check if any APCs need to be dispatched:
			::WaitForSingleObjectEx(m_hThread, 0, TRUE);
		}
		else if (dwResult == WAIT_FAILED)
	    {
	        ASSERT(FALSE);
	        break;
	    }
		else
		{
			ASSERT(dwResult == WAIT_OBJECT_0);
		}
	}
}

HRESULT CVsThreadBase::Start_base
(
void *pvArgument,
LPSECURITY_ATTRIBUTES psa
)
{
    if (m_hEvent == NULL)
        return E_FAIL;
	ASSERT(m_hThread == 0);
	ASSERT(m_pvArgument == NULL);
	m_pvArgument = pvArgument;
	m_fChildDone = false;

	if (FAILED(this->PrepareInStartingThread_base(pvArgument)))
	    return E_FAIL;

	unsigned uThreadID;
	m_hThread = reinterpret_cast<HANDLE>(_beginthreadex(psa, m_dwStackSize, &CVsThreadBase::InternalThreadMain, this, m_dwCreationFlags, (unsigned *) &uThreadID));
	m_pvArgument = NULL;
	ASSERT(m_hThread != NULL);
	if (m_hThread == NULL)
	{
	    ASSERT(FALSE);
	    return E_FAIL;
	}

	for (;;)
	{
		DWORD dwResult = ::WaitForSingleObjectEx(
									m_hEvent,
									100,
									TRUE);
		if (dwResult == WAIT_FAILED)
		{
		    ASSERT(FALSE);
		    break;
		}

		if (dwResult == WAIT_OBJECT_0)
			break;

		if (dwResult == WAIT_IO_COMPLETION)
			continue;

		// We should have timed out to get here.
		ASSERT(dwResult == WAIT_TIMEOUT);

		// Let's make sure that the child thread hasn't died on us.
		if (::WaitForSingleObjectEx(m_hThread, 0, FALSE) == WAIT_OBJECT_0)
		{
			// The child is dead; there's no hope.  Throw E_UNEXPECTED;
			ASSERT(FALSE);
            _VxModule.SetErrorInfo(E_UNEXPECTED, IDS_E_THREADTERMINATED, NULL);
            return E_UNEXPECTED;
		}
	}
	return S_OK;
}

unsigned CVsThreadBase::InternalThreadMain(void *pvArgument)
{
	
	HRESULT hr = CoInitializeEx(NULL, COINIT_MULTITHREADED);

	ASSERT(SUCCEEDED(hr));

	if (SUCCEEDED(hr))
	{
		CVsThreadBase *pThis = reinterpret_cast<CVsThreadBase *>(pvArgument);

		ASSERT(!pThis->m_fChildDone);

		hr = pThis->UnmarshalParentIUnknown();
        if (SUCCEEDED(hr))
        {
		    // Let the caller know we're all set.
		    BOOL fSucceeded = ::SetEvent(pThis->m_hEvent);
		    ASSERT(fSucceeded);

		    pThis->ThreadMain_base(pThis->m_pvArgument);

		    pThis->m_fChildDone = true;
		    fSucceeded = ::SetEvent(pThis->m_hEvent);
		    ASSERT(fSucceeded);

		    if (pThis->m_pIUnknown_Parent != NULL)
		    {
			    IUnknown *pIUnknown_Parent = pThis->m_pIUnknown_Parent;
			    pThis->m_pIUnknown_Parent = NULL;
			    pIUnknown_Parent->Release();
		    }
        }
		CoUninitialize();
	}


	return 0;
}

