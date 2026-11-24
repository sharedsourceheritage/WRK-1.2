
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#pragma once

class CVsThreadBase
{
protected:
	CVsThreadBase(
		DWORD dwStackSize,
		DWORD dwCreationFlags,
		DWORD dwTickPeriod);
	virtual ~CVsThreadBase();

	static unsigned __stdcall InternalThreadMain(void *);
	virtual HRESULT PrepareInStartingThread_base(void *pvArgument) = 0;
	virtual void ThreadMain_base(void *pvArgument) = 0;
	HRESULT Start_base(void *pvArgument, LPSECURITY_ATTRIBUTES p);

	virtual HRESULT MarshalParentIUnknown(IUnknown *);
	virtual HRESULT UnmarshalParentIUnknown();

	virtual void InternalTick(BOOL &rfContinue);

	void WaitAndTick(DWORD dwMS, BOOL fTickOnMessage, BOOL &rfCancelled);
	void Detach();

	virtual void ReleaseThreadHandle();

	// Call this function before starting another operation; if the previous thread
	// is still running, rfReady will be set to false.
	bool IsPreviousOperationFinished();

	operator HANDLE() const { return reinterpret_cast<HANDLE>(m_hThread); }

	DWORD m_dwTickPeriod;
	HANDLE m_hThread;
	HANDLE m_hEvent;
	DWORD m_dwStackSize;
	DWORD m_dwCreationFlags;
	void *m_pvArgument;
	volatile bool m_fKillChild;
	// There is a race condition where the child-done event may be signalled
	// twice before the second rendezvous point is reached; when the child
	// thread is done running its ThreadMain(), m_fChildDone() is set to
	// true and is checked prior to waiting on the event to be signalled.
	volatile bool m_fChildDone;

	// This is an inter-thread marshalled IStream; it should be safe to use in
	// both parent and child threads.
	IStream *m_pIStream_IUnknown_Parent;

	// This interface pointer is unmarshalled in the child thread and must only
	// be accessed in the child thread.
	IUnknown *m_pIUnknown_Parent;
};

template <class T> class CVsThread : protected CVsThreadBase
{
	typedef CVsThreadBase super;
 	friend T;

protected:
 	CVsThread(
 		DWORD dwStackSize = 0,
 		DWORD dwCreationFlags = 0,
 		DWORD dwTickPeriod = 0) : super(dwStackSize, dwCreationFlags, dwTickPeriod) { }

	virtual HRESULT PrepareInStartingThread_base(void *pvArgument) { return this->PrepareInStartingThread(reinterpret_cast<T *>(pvArgument)); }
	virtual void ThreadMain_base(void *pvArgument) { this->ThreadMain(reinterpret_cast<T *>(pvArgument)); }

	// Pure virtual invoked as the main processing of the thread
	virtual void ThreadMain(T *ptArgument) = 0;

	// The PrepareInStartingThread() function is invoked in the starting
	// thread when Start() is called.  It's an opportune time to marshall
	// any OLE interfaces for use in the started thread.
	virtual HRESULT PrepareInStartingThread(T *) { return S_OK;}

public:
	HRESULT Start(T *pt, LPSECURITY_ATTRIBUTES pSecurityAttributes = NULL) { return this->Start_base(pt, pSecurityAttributes); }

	using super::WaitAndTick;
	using super::Detach;
};
