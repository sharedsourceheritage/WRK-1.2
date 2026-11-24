/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#include "project.h"

#include "dllmain.h"  //for RegOpenKeyVS & clsidBabelPackage
#include "package.h"
#include "lservice.h"
#include "delayscope.h"

//#ifdef VS7SDK
const IID IID_IProfferService
  = { 0xCB728B20, 0xF786, 0x11ce, { 0x92, 0xAD, 0x00, 0xAA, 0x00, 0xA7, 0x4C, 0xD0 }};
//#endif

const GUID SID_IBabelPackage
  = { 0x58645F93, 0x4EC7, 0x4aa4, { 0x92, 0xFB, 0x09, 0x62, 0x5D, 0x04, 0xFC, 0x77 }};

#ifdef VS6SDK
#include <initguid.h>
#include <olecmid.h>
#endif

/*---------------------------------------------------------
  Package 
-----------------------------------------------------------*/
Package::Package()
{
  TRACE_CREATE( "Package", static_cast<IVsPackage*>(this) );
  m_refCount  = 1;
  m_provider  = NULL;
  m_languages = NULL;

  m_componentManager        = NULL;
  m_componentManagerConnect = 0;
}


Package::~Package()
{
  TRACE_DESTROY( static_cast<IVsPackage*>(this) );
  Done();
}


STDMETHODIMP Package::Init()
{
  m_languages = new ObjectList();
  if (!m_languages) return E_OUTOFMEMORY;

  //read all babel services from the registry
  HRESULT hr = S_OK;
  HKEY    keyLanguages  = 0;

  // find the registry root
  HKEY keyVS;
  BSTR bstrRoot = NULL;
  ILocalRegistry2* pILocalRegistry2;
  hr = m_provider->QueryService(SID_SLocalRegistry, IID_ILocalRegistry2, (void **)&pILocalRegistry2);
  if (SUCCEEDED(hr))
  {
    hr = pILocalRegistry2->GetLocalRegistryRoot(&bstrRoot);
  }
  if (SysStringLen(bstrRoot)>0)
    hr = hrRegOpenKeyEx(HKEY_LOCAL_MACHINE, bstrRoot, 0, KEY_READ, &keyVS );
  else
    hr = RegOpenKeyVS(KEY_READ, &keyVS);
  RELEASE(pILocalRegistry2);
  bstrFree(bstrRoot);
  if (FAILED(hr)) return hr;

  hr = hrRegOpenKeyEx(keyVS,L"languages\\language services", 0, KEY_READ, &keyLanguages );
  RegCloseKey(keyVS);
  if (FAILED(hr)) return hr;

  //go through all entries
  wchar_t keyName[MAXPATH+1];
  LONG    result;
  int     index;

  index = 0;
  while (result = RegEnumKey( keyLanguages, index, keyName, MAXPATH), result == ERROR_SUCCESS)
  {
    HKEY keySub;
    hr = hrRegOpenKeyEx( keyLanguages, keyName, 0, KEY_READ, &keySub );
    if (FAILED(hr)) break;

    wchar_t packageIdStr[MAXCLSID+1];
    DWORD   packageIdLen = MAXCLSID;
    if (SUCCEEDED(hrRegQueryValueEx( keySub, L"package", NULL, NULL, 
                                     (BYTE*)packageIdStr, &packageIdLen )))
    {
      CLSID packageId;
      hr = CLSIDFromString( packageIdStr, &packageId );
      if (FAILED(hr)) break;

      //if this service uses the babel language service
      if (packageId == clsidBabelPackage)
      {
        //then create a service for it
        LanguageService* lservice = new LanguageService( keyName );
        if (!lservice) { hr = E_OUTOFMEMORY; break; }

        hr = lservice->Init( keySub );
        if (FAILED(hr)) { lservice->Done(); RELEASE(lservice); break; }

        //and put it on our languages list
        IUnknown* lserviceUnk = NULL;
        hr = lservice->QueryInterface( IID_IUnknown, reinterpret_cast<void**>(&lserviceUnk) );
        RELEASE(lservice);
        if (FAILED(hr)) break;

        hr = m_languages->Insert( lserviceUnk );
        RELEASE(lserviceUnk);
        if (FAILED(hr)) break;
      }
    }

    index++;
  }
  RegCloseKey(keyLanguages);
  if (FAILED(hr)) return hr;
  if (result != ERROR_NO_MORE_ITEMS) return HRESULT_FROM_WIN32(result);

  return S_OK;
}

STDMETHODIMP Package::Done()
{
  Terminate();  //just to be safe

  ObjectElem*      elem     = NULL;
  LanguageService* lservice = NULL;
  for (m_languages->GetFirst( &elem,(IUnknown**)&lservice ); lservice; m_languages->GetNext( &elem, (IUnknown**)&lservice ))
  {
    lservice->Done();
  }

  RELEASE(m_languages);
  RELEASE(m_provider);  
  return S_OK;
}

/*---------------------------------------------------------
  IUnknown
-----------------------------------------------------------*/
STDMETHODIMP Package::QueryInterface( in REFIID iid, out void** obj )
{
  OUTARG(obj);

  if (iid == IID_IUnknown)
  {
    TRACE("Package::QueryInterface for IUnknown");
    *obj = static_cast<IVsPackage*>(this);
  }
  else if (iid == IID_IVsPackage)
  {
    TRACE("Package::QueryInterface for IVsPackage");
    *obj = static_cast<IVsPackage*>(this);
  }
  else if (iid == IID_IServiceProvider)
  {
    TRACE("Package::QueryInterface for IServiceProvider");
    *obj = static_cast<IServiceProvider*>(this);
  }
  else if (iid == IID_IOleComponent)
  {
    TRACE("Package::QueryInterface for IOleComponent");
    *obj = static_cast<IOleComponent*>(this);
  }
  else if (iid == IID_IDispatch || iid == IID_IBabelPackage)
  {
    TRACE("Package::QueryInterface for IDispatch / IBabelPackage");
    *obj = static_cast<IBabelPackage*>(this);
  }
  else
    return E_NOINTERFACE;

  AddRef();
  return S_OK;
}

STDMETHODIMP_(ULONG) Package::AddRef()
{
  return IncRefCount(&m_refCount);
}

STDMETHODIMP_(ULONG) Package::Release()
{
  if (DecRefCount(&m_refCount) == 0)
  {
    delete this;
    return 0;
  }
  else
    return m_refCount;
}


/*---------------------------------------------------------
  implement IDispatch (for IBabelPackage only)
-----------------------------------------------------------*/
STDMETHODIMP Package::GetTypeInfoCount( out UINT* count )
{
  OUTARG(count);

  if (g_typeInfoBabelPackage) *count = 1;
                         else *count = 0;
  return S_OK;
}

STDMETHODIMP Package::GetTypeInfo( in UINT index, in LCID lcid, out ITypeInfo** typeInfo )
{
  OUTARG(typeInfo);
  if (index != 0) return E_INVALIDARG;
  if (!g_typeInfoBabelPackage) return TYPE_E_CANTLOADLIBRARY;

  *typeInfo = g_typeInfoBabelPackage;
  return S_OK;
}

STDMETHODIMP Package::GetIDsOfNames( in REFIID iid, in OLECHAR** names, in UINT count, 
                                       in LCID lcid, out DISPID* dispids )
{
  if (!g_typeInfoBabelPackage) return TYPE_E_CANTLOADLIBRARY;
  return g_typeInfoBabelPackage->GetIDsOfNames( names, count, dispids );
}

STDMETHODIMP Package::Invoke( in DISPID dispid, in REFIID iid, in LCID lcid, 
                                in WORD flags, in DISPPARAMS* args, 
                                out VARIANT* result, out EXCEPINFO* error, out UINT* errorArg )
{
  if (!g_typeInfoBabelPackage) return TYPE_E_CANTLOADLIBRARY;  
  return g_typeInfoBabelPackage->Invoke( static_cast<IBabelPackage*>(this), 
                                      dispid, flags, args, result, error, errorArg );
}


/*---------------------------------------------------------
  IVsPackage
-----------------------------------------------------------*/
STDMETHODIMP Package::SetSite( in IServiceProvider* provider )
{
  TRACE( "Package::SetSite" );
  REFARG(provider);
  ASSERT(m_provider == NULL);
  HRESULT hr;
  
  RELEASE(m_provider);
  m_provider = provider;
  ADDREF(m_provider);

  // now initialize
  hr = Init();
  if (FAILED(hr))
      return hr;

  //proffer services
  IProfferService* proffer = NULL;
  hr = m_provider->QueryService( SID_SProfferService, IID_IProfferService, reinterpret_cast<void**>(&proffer) );
  if (FAILED(hr)) return hr;

  DWORD  cookie;
  hr = proffer->ProfferService( SID_IBabelPackage, static_cast<IServiceProvider*>(this), &cookie );
  if (FAILED(hr)) return hr;

  ObjectElem*      elem     = NULL;
  LanguageService* lservice = NULL;
  for (m_languages->GetFirst( &elem,(IUnknown**)&lservice ); lservice; m_languages->GetNext( &elem, (IUnknown**)&lservice ))
  {
    hr = lservice->SetSite( m_provider );
    if (FAILED(hr)) { hr = S_OK; continue; }   //don't fail if one package can't be loaded

    CLSID id;
    hr = lservice->GetLanguageId( &id );
    if (FAILED(hr)) break;

    hr = proffer->ProfferService( id, static_cast<IServiceProvider*>(this), &cookie );
    if (FAILED(hr)) break;
  }
  RELEASE(proffer);
  if (FAILED(hr)) return hr;


  //register with ComponentManager for Idle processing
  if (!m_componentManager)
  {
    hr = m_provider->QueryService( SID_SOleComponentManager, IID_IOleComponentManager, 
                                   reinterpret_cast<void**>(&m_componentManager));
    if (FAILED(hr)) return hr;
  }

  if (!m_componentManagerConnect)
  {
      OLECRINFO   crinfo;

      crinfo.cbSize   = sizeof (crinfo);
      crinfo.grfcrf   = olecrfNeedIdleTime | olecrfNeedPeriodicIdleTime; 
      crinfo.grfcadvf = olecadvfModal| olecadvfRedrawOff | olecadvfWarningsOff;
      crinfo.uIdleTimeInterval = 1000;

      if (!m_componentManager->FRegisterComponent(this, &crinfo, &m_componentManagerConnect))
        return E_FAIL;
  }



  return S_OK;
}

STDMETHODIMP Package::QueryClose( out BOOL* canClose )
{
  OUTARG(canClose);

  *canClose = true;
  return S_OK;
}

STDMETHODIMP Package::Close()
{
  RELEASE(m_provider);
  //RELEASE(m_languages) ??
  return S_OK;
}

STDMETHODIMP Package::GetAutomationObject( in LPCOLESTR propertyName, out IDispatch** obj )
{
  OUTARG(obj);
  REFARG(propertyName);

  return E_NOTIMPL;
}

STDMETHODIMP Package::CreateTool( in REFGUID guidTool )
{
  return E_NOTIMPL;
}

STDMETHODIMP Package::ResetDefaults( in PKGRESETFLAGS flags )
{
  return S_OK;
}

STDMETHODIMP Package::GetPropertyPage( in REFGUID guidPage, VSPROPSHEETPAGE* page )
{
  return E_NOTIMPL;
}


/*---------------------------------------------------------
  IServiceProvider
-----------------------------------------------------------*/
STDMETHODIMP Package::QueryService( in REFGUID sid, in REFIID iid, void** obj )
{
  TRACE( "Package::QueryService" );
  OUTARG(obj);
  if (!m_provider) return E_UNEXPECTED;

  if (sid == SID_IBabelPackage)
    return QueryInterface( iid, obj );

  HRESULT     hr             = S_OK;
  ObjectElem* elem           = NULL;
  LanguageService* lservice  = NULL;

  for( m_languages->GetFirst( &elem, (IUnknown**)&lservice); lservice; m_languages->GetNext(&elem,(IUnknown**)&lservice) )
  {
    CLSID id;
    hr = lservice->GetLanguageId( &id );
    if (FAILED(hr)) { return hr; }

    if (id == sid)
    {
      hr = lservice->QueryInterface( iid, obj );
      return hr;
    }
  }

  return E_NOINTERFACE;
}

/*---------------------------------------------------------
  IBabelPackage
-----------------------------------------------------------*/
STDMETHODIMP Package::LoadScope( in long reserved,
                                 in BSTR fileName, 
                                 in IBabelProject* project,
                                 out IScope** scope )
{
  TRACE1( "Package::LoadScope: %S", fileName );
  OUTARG(scope);
  HRESULT hr = S_OK;

  //--------
  //Normally we delay the loading of the scope
  if (reserved != DirectLoad)
  {
    *scope = new DelayScope( m_provider, project, fileName );
    if (!scope) return E_OUTOFMEMORY;
    return S_OK;
  }

  //--------
  //Otherwise we do a direct load (called from a DelayScope)
  
  //get path
  char cfilePath[MAXPATH+1];
  _fullpath( cfilePath, CW2A(fileName), MAXPATH );
  BSTR filePath = SysAllocString( CA2W(cfilePath) );

  //get extension
  wchar_t* p = SysStringLen(filePath)==0 ? NULL : wcsrchr( filePath, L'.' );
  if (!p) { bstrFree(filePath); return E_FAIL; }
  BSTR fileExt = SysAllocString(p);

  //try to load it
  ObjectElem* elem           = NULL;
  LanguageService* lservice  = NULL;
  for( m_languages->GetFirst( &elem, (IUnknown**)&lservice); lservice; m_languages->GetNext(&elem,(IUnknown**)&lservice) )
  {
    BSTR extensions = NULL;
    lservice->GetFileExtensions( &extensions );

    //matches the extension?
    TRACE2( "Package::LoadScope::extensions '%S' vs. '%S'", fileExt, extensions );

    hr = E_FAIL;        
    const wchar_t* start = extensions;
    const wchar_t* end   = extensions;
    while (end && *end != 0)
    {
      do 
      {
        end++;
      } while (*end != 0 && *end != L';');

      if (strCompareLen( fileExt, start, (unsigned)(end-start) ) == 0)
      {
        hr = S_OK;
        break;
      }
      else
      {
        if (*end == L';')
        {
          end++;
          start = end;
        }
      }
    }  
    bstrFree(extensions);
    if (hr == S_OK) 
    {
      hr = lservice->LoadScope( filePath, project, scope );
      if (hr == S_OK) goto end;
    }
  }
  hr = E_FAIL;

end:
  bstrFree( filePath );
  bstrFree( fileExt );
  return hr;
}


/*---------------------------------------------------------
  IOleComponent
-----------------------------------------------------------*/
STDMETHODIMP_(void) Package::Terminate()
{
  TRACE("Package::Terminate");

  if (m_componentManagerConnect)
  {
    m_componentManager->FRevokeComponent (m_componentManagerConnect);
    m_componentManagerConnect = 0;
  }

  RELEASE(m_componentManager);
}
 

STDMETHODIMP_(BOOL) Package::FDoIdle( in DWORD grfidlef )
{
  bool  moreToDo = false;
  bool  periodic = ((grfidlef & oleidlefPeriodic) != 0);

//  TRACE1("Package::FDoIdle: periodic=%i", periodic );
  
  ObjectElem* elem           = NULL;
  LanguageService* lservice  = NULL;
  for( m_languages->GetFirst( &elem, (IUnknown**)&lservice); lservice; m_languages->GetNext(&elem,(IUnknown**)&lservice) )
  {
    moreToDo |= lservice->OnIdle( periodic );
//    if (!m_componentManager->FContinueIdle()) { TRACE("Package::FDoIdle: break"); return true; }
  }

  return FALSE; //moreToDo
}
