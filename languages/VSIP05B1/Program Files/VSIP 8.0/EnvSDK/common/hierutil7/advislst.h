//---------------------------------------------------------------------------
// Microsoft Visual Studio
//
// Microsoft Confidential
// Copyright 1994 - 2000 Microsoft Corporation. All Rights Reserved.
//
// advislst.h: Definition of templated Event sink class.
//
//---------------------------------------------------------------------------
#if (_MSC_VER > 1000) && !defined(NO_PRAGMA_ONCE)
#pragma once
#endif

#ifndef __ADVISLST_H__
#define __ADVISLST_H__

template <class T>
class CVsAdviseListEnumerator;

template <class T>
struct EventSink
{	
	CComPtr<T> m_srpEventSink;
	VSCOOKIE   m_dwCookie;
};

template <class T>
class CVsAdviseList
{
public:
	CVsAdviseList() : m_dwNextCookie(1) {}
	~CVsAdviseList()
	{	// Should all be freed by now
		ASSERT(GetCount() == 0);
		for(int i = 0; i < m_rgEventSinks.GetSize(); ++i)
		{
			delete m_rgEventSinks[i];
		}
	}

	// Sets an advise and returns the cookie. Note that this function
	// WILL AddRef() pAdvise!!
	HRESULT	SetAdvise(T* pAdvise, VSCOOKIE* pdwCookie)
	{
		HRESULT hr = S_OK;
		ASSERT(pAdvise != NULL && m_dwNextCookie != 0);
		// Create event sink, Addref Advise, Set cookie
		EventSink<T> *pSink = new EventSink<T>;
		if(pSink)
		{
			pSink->m_srpEventSink = pAdvise;
			*pdwCookie = m_dwNextCookie;
			pSink->m_dwCookie = m_dwNextCookie;
			++m_dwNextCookie;
			m_rgEventSinks.Add(pSink);
		}
		else
		{
			hr = E_OUTOFMEMORY;
		}
		return hr;
	}

	// Removes an advise sink
	HRESULT	UnAdvise(VSCOOKIE dwCookie)
	{
		ASSERT(dwCookie != 0 && dwCookie < m_dwNextCookie);	// unadvising an unknown cookie
		int n = m_rgEventSinks.GetSize();
		for(int i = 0; i < n; ++i)
		{
			if(m_rgEventSinks[i]->m_dwCookie == dwCookie)
			{
				delete m_rgEventSinks[i];
				m_rgEventSinks.RemoveAt(i);
				return S_OK;
			}
		}
		// We didn't find the connection - probably removed before
		ASSERT(FALSE);
		return CONNECT_E_NOCONNECTION ;
	}

	int		GetCount() const {return m_rgEventSinks.GetSize();}

	// Returns advise interface at index. NOT dwCookie.
	T*		GetAdviseSink(int index) const
	{
		ASSERT(index < GetCount());
		return m_rgEventSinks[index]->m_srpEventSink;
	}

    EventSink<T>* GetEventSink(int index) 
    {
        ASSERT(index < GetCount());
        return m_rgEventSinks[index];
    }

protected:
	VSCOOKIE m_dwNextCookie;
	CVxTypedPtrArray<CVxPtrArray, EventSink<T>*> m_rgEventSinks;
};

// Thread-safe enumerator for the events, as long as two threads
// do not operate on the same CVsAdviseListEnumerator object.
template <class T>
class CVsAdviseListEnumerator
{
public:
    CVsAdviseListEnumerator(CVsAdviseList<T>* pList = NULL) { Init(pList); }
    void Init(CVsAdviseList<T>* pList)
    {
        m_pList = pList;
        m_rgEventSinksCopy.RemoveAll();

        if (m_pList != NULL)
        {
            for (int i = 0; i < pList->GetCount(); i++)
            {
                EventSink<T>* pevtSink = pList->GetEventSink(i);
                m_rgEventSinksCopy.Add(pevtSink);
            }
        }

        // When you call GetNext(), this will get incremented to zero and
        // the first item will be returned.  When you call GetFirst(), it
        // will call GetNext() under the covers.  
        m_iCurRetIdx = -1;
    }

    T* GetFirst()
    {
        if (m_rgEventSinksCopy.GetSize() == 0) 
            return NULL;

        return GetNext();
    }

    T* GetNext()
    {
        if (m_pList == NULL)
        {
            ASSERT(FALSE);
            return NULL;
        }

        while (++m_iCurRetIdx < m_rgEventSinksCopy.GetSize())
        {
            // See if the item is still advisable
            for (int i = 0; i < m_pList->GetCount(); i++)
            {
                if (m_rgEventSinksCopy[m_iCurRetIdx]->m_srpEventSink == m_pList->GetAdviseSink(i)) 
                {
                    // Yes, it is!
                    return m_rgEventSinksCopy[m_iCurRetIdx]->m_srpEventSink;
                }
            }

            // The element we're currently looking at in the copied list
            // has been removed from the master advise list for some reason,
            // eg. if the firing of this event on a previous advisee resulted
            // in the advise list being modified.  This may mean that the element 
            // no longer wishes to be notified.  Therefore, we just go to the next 
            // item in the list.
        }

        // No more elements in the copied list means there are no more sinks!
        return NULL;
    }

protected:
    CVsAdviseList<T>* m_pList;

    CVxTypedPtrArray<CVxPtrArray, EventSink<T>*> m_rgEventSinksCopy;
    int m_iCurRetIdx;
};

#ifdef _WIN64

// Advise list with 32-bit cookies
template <class T>
class CVsAdviseListEnumeratorDW;

template <class T>
struct EventSinkDW
{	
	CComPtr<T> m_srpEventSink;
	DWORD	   m_dwCookie;
};

template <class T>
class CVsAdviseListDW
{
public:
	CVsAdviseListDW() : m_dwNextCookie(1) {}
	~CVsAdviseListDW()
	{	// Should all be freed by now
		ASSERT(GetCount() == 0);
		for(int i = 0; i < m_rgEventSinks.GetSize(); ++i)
		{
			delete m_rgEventSinks[i];
		}
	}

	// Sets an advise and returns the cookie. Note that this function
	// WILL AddRef() pAdvise!!
	HRESULT	SetAdvise(T* pAdvise, DWORD* pdwCookie)
	{
		HRESULT hr = S_OK;
		ASSERT(pAdvise != NULL && m_dwNextCookie != 0);
		// Create event sink, Addref Advise, Set cookie
		EventSinkDW<T> *pSink = new EventSinkDW<T>;
		if(pSink)
		{
			pSink->m_srpEventSink = pAdvise;
			*pdwCookie = m_dwNextCookie;
			pSink->m_dwCookie = m_dwNextCookie;
			++m_dwNextCookie;
			m_rgEventSinks.Add(pSink);
		}
		else
		{
			hr = E_OUTOFMEMORY;
		}
		return hr;
	}

	// Removes an advise sink
	HRESULT	UnAdvise(DWORD dwCookie)
	{
		ASSERT(dwCookie != 0 && dwCookie < m_dwNextCookie);	// unadvising an unknown cookie
		int n = m_rgEventSinks.GetSize();
		for(int i = 0; i < n; ++i)
		{
			if(m_rgEventSinks[i]->m_dwCookie == dwCookie)
			{
				delete m_rgEventSinks[i];
				m_rgEventSinks.RemoveAt(i);
				return S_OK;
			}
		}
		// We didn't find the connection - probably removed before
		ASSERT(FALSE);
		return CONNECT_E_NOCONNECTION ;
	}

	int		GetCount() const {return m_rgEventSinks.GetSize();}

	// Returns advise interface at index. NOT dwCookie.
	T*		GetAdviseSink(int index) const
	{
		ASSERT(index < GetCount());
		return m_rgEventSinks[index]->m_srpEventSink;
	}

    EventSinkDW<T>* GetEventSink(int index) 
    {
        ASSERT(index < GetCount());
        return m_rgEventSinks[index];
    }

protected:
	DWORD m_dwNextCookie;
	CVxTypedPtrArray<CVxPtrArray, EventSinkDW<T>*> m_rgEventSinks;
};

// Thread-safe enumerator for the events, as long as two threads
// do not operate on the same CVsAdviseListEnumeratorDW object.
template <class T>
class CVsAdviseListEnumeratorDW
{
public:
    CVsAdviseListEnumeratorDW(CVsAdviseListDW<T>* pList = NULL) { Init(pList); }
    void Init(CVsAdviseListDW<T>* pList)
    {
        m_pList = pList;
        m_rgEventSinksCopy.RemoveAll();

        if (m_pList != NULL)
        {
            for (int i = 0; i < pList->GetCount(); i++)
            {
                EventSinkDW<T>* pevtSink = pList->GetEventSink(i);
                m_rgEventSinksCopy.Add(pevtSink);
            }
        }

        // When you call GetNext(), this will get incremented to zero and
        // the first item will be returned.  When you call GetFirst(), it
        // will call GetNext() under the covers.  
        m_iCurRetIdx = -1;
    }

    T* GetFirst()
    {
        if (m_rgEventSinksCopy.GetSize() == 0) 
            return NULL;

        return GetNext();
    }

    T* GetNext()
    {
        if (m_pList == NULL)
        {
            ASSERT(FALSE);
            return NULL;
        }

        while (++m_iCurRetIdx < m_rgEventSinksCopy.GetSize())
        {
            // See if the item is still advisable
            for (int i = 0; i < m_pList->GetCount(); i++)
            {
                if (m_rgEventSinksCopy[m_iCurRetIdx]->m_srpEventSink == m_pList->GetAdviseSink(i)) 
                {
                    // Yes, it is!
                    return m_rgEventSinksCopy[m_iCurRetIdx]->m_srpEventSink;
                }
            }

            // The element we're currently looking at in the copied list
            // has been removed from the master advise list for some reason,
            // eg. if the firing of this event on a previous advisee resulted
            // in the advise list being modified.  This may mean that the element 
            // no longer wishes to be notified.  Therefore, we just go to the next 
            // item in the list.
        }

        // No more elements in the copied list means there are no more sinks!
        return NULL;
    }

protected:
    CVsAdviseListDW<T>* m_pList;

    CVxTypedPtrArray<CVxPtrArray, EventSinkDW<T>*> m_rgEventSinksCopy;
    int m_iCurRetIdx;
};
#else
#define CVsAdviseListDW CVsAdviseList
#define CVsAdviseListEnumeratorDW CVsAdviseListEnumerator
#endif // _WIN64

#endif

// End of advislst.h
