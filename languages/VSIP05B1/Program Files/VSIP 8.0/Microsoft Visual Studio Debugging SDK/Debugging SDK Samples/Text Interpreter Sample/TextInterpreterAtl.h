#ifndef __TEXTINTERPRETERATL_H__
#define __TEXTINTERPRETERATL_H__

// ----------------------------------------------------------------------------
// CComEnumWithCountImpl

template <class Base, const IID* piid, class T, class Copy>
class ATL_NO_VTABLE CComEnumWithCountImpl : public Base
{
public:
   CComEnumWithCountImpl() {m_begin = m_end = m_iter = NULL; m_dwFlags = 0; m_pUnk = NULL;}
   ~CComEnumWithCountImpl();
   STDMETHOD(Next)(ULONG celt, T* rgelt, ULONG* pceltFetched);
   STDMETHOD(Skip)(ULONG celt);
   STDMETHOD(Reset)(void){m_iter = m_begin;return S_OK;}
   STDMETHOD(Clone)(Base** ppEnum);
   STDMETHOD(GetCount)(ULONG* pcelt);
   HRESULT Init(T* begin, T* end, IUnknown* pUnk,
      CComEnumFlags flags = AtlFlagNoCopy);
   IUnknown* m_pUnk;
   T* m_begin;
   T* m_end;
   T* m_iter;
   DWORD m_dwFlags;
protected:
   enum FlagBits
   {
      BitCopy=1,
      BitOwn=2
   };
};

template <class Base, const IID* piid, class T, class Copy>
CComEnumWithCountImpl<Base, piid, T, Copy>::~CComEnumWithCountImpl()
{
   if (m_dwFlags & BitOwn)
   {
      for (T* p = m_begin; p != m_end; p++)
         Copy::destroy(p);
      delete [] m_begin;
   }
   if (m_pUnk)
      m_pUnk->Release();
}

template <class Base, const IID* piid, class T, class Copy>
STDMETHODIMP CComEnumWithCountImpl<Base, piid, T, Copy>::Next(ULONG celt, T* rgelt,
   ULONG* pceltFetched)
{
   if (rgelt == NULL || (celt != 1 && pceltFetched == NULL))
      return E_POINTER;
   if (m_begin == NULL || m_end == NULL || m_iter == NULL)
      return E_FAIL;
   ULONG nRem = (ULONG)(m_end - m_iter);
   HRESULT hRes = S_OK;
   if (nRem < celt)
      hRes = S_FALSE;
   ULONG nMin = min(celt, nRem);
   if (pceltFetched != NULL)
      *pceltFetched = nMin;
   while(nMin--)
      Copy::copy(rgelt++, m_iter++);
   return hRes;
}

template <class Base, const IID* piid, class T, class Copy>
STDMETHODIMP CComEnumWithCountImpl<Base, piid, T, Copy>::Skip(ULONG celt)
{
   m_iter += celt;
   if (m_iter < m_end)
      return S_OK;
   m_iter = m_end;
   return S_FALSE;
}

template <class Base, const IID* piid, class T, class Copy>
STDMETHODIMP CComEnumWithCountImpl<Base, piid, T, Copy>::Clone(Base** ppEnum)
{
   typedef CComObject<CComEnumWithCount<Base, piid, T, Copy> > _class;
   HRESULT hRes = E_POINTER;
   if (ppEnum != NULL)
   {
      _class* p = NULL;
      ATLTRY(p = new _class)
      if (p == NULL)
      {
         *ppEnum = NULL;
         hRes = E_OUTOFMEMORY;
      }
      else
      {
         // If the data is a copy then we need to keep "this" object around
         hRes = p->Init(m_begin, m_end, (m_dwFlags & BitCopy) ? this : m_pUnk);
         if (FAILED(hRes))
            delete p;
         else
         {
            p->m_iter = m_iter;
            hRes = p->_InternalQueryInterface(*piid, (void**)ppEnum);
            if (FAILED(hRes))
               delete p;
         }
      }
   }
   return hRes;
}

template <class Base, const IID* piid, class T, class Copy>
STDMETHODIMP CComEnumWithCountImpl<Base, piid, T, Copy>::GetCount(ULONG* pcelt)
{
   *pcelt = (ULONG)(m_end - m_begin);
   return S_OK;
}

template <class Base, const IID* piid, class T, class Copy>
HRESULT CComEnumWithCountImpl<Base, piid, T, Copy>::Init(T* begin, T* end, IUnknown* pUnk,
   CComEnumFlags flags)
{
   if (flags == AtlFlagCopy)
   {
      _ASSERTE(m_begin == NULL); //Init called twice?
      ATLTRY(m_begin = new T[end-begin])
      m_iter = m_begin;
      if (m_begin == NULL)
         return E_OUTOFMEMORY;
      for (T* i=begin; i != end; i++)
      {
         Copy::init(m_iter);
         Copy::copy(m_iter++, i);
      }
      m_end = m_begin + (end-begin);
   }
   else
   {
      m_begin = begin;
      m_end = end;
   }
   m_pUnk = pUnk;
   if (m_pUnk)
      m_pUnk->AddRef();
   m_iter = m_begin;
   m_dwFlags = flags;
   return S_OK;
}

template <class Base, const IID* piid, class T, class Copy, class ThreadModel = CComObjectThreadModel>
class ATL_NO_VTABLE CComEnumWithCount :
   public CComEnumWithCountImpl<Base, piid, T, Copy>,
   public CComObjectRootEx< ThreadModel >
{
public:
   typedef CComEnumWithCount<Base, piid, T, Copy > _CComEnum;
   typedef CComEnumWithCountImpl<Base, piid, T, Copy > _CComEnumBase;
   BEGIN_COM_MAP(_CComEnum)
      COM_INTERFACE_ENTRY_IID(*piid, _CComEnumBase)
   END_COM_MAP()
};

#endif // __TEXTINTERPRETERATL_H__
