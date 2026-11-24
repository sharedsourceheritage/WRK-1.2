/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#include "project.h"

/*---------------------------------------------------------
  local globals
-----------------------------------------------------------*/
static HINSTANCE  g_instance     = NULL;
static ULONG      g_dllRefCount  = 0;
static ITypeInfo* g_typeInfo     = NULL;

static const CLSID clsidEcmaService = 
  { 0xc10becc0, 0xd8b1, 0x480f, { 0xb9, 0xfb, 0x8c, 0x45, 0xe3, 0xf, 0x8b, 0xd } };

static const CLSID clsidBabelPackage =
  { 0x221f0eb7, 0x30f7, 0x45ff, { 0xae, 0x73, 0x59, 0x68, 0xb1, 0x67, 0xcf, 0x9 } };




//paths
LPCOLESTR pathVS          = OLE("Software\\Microsoft\\VisualStudio\\7.0");
LPCOLESTR pathFileExt     = OLE("Languages\\File Extensions\\.ecma");
LPCOLESTR pathLangService = OLE("Languages\\Language Services\\EcmaScript");
LPCOLESTR ecmaName        = OLE("EcmaScript");


/*---------------------------------------------------------
  Prototypes
-----------------------------------------------------------*/
static HRESULT RegisterServer( bool registerIt, HKEY keyRoot );
static HRESULT VSRegisterServer( bool registerIt, LPOLESTR regRoot );
static HRESULT LoadTypeInfo();

/*---------------------------------------------------------
  Class Factory
-----------------------------------------------------------*/
class EcmaServiceFactory : IClassFactory
{
private:
  ULONG   m_refCount;

public:
  EcmaServiceFactory();
  ~EcmaServiceFactory();

  //IUnknown
  STDMETHODIMP QueryInterface( REFIID iid, LPVOID* obj );
  STDMETHODIMP_(ULONG) AddRef();
  STDMETHODIMP_(ULONG) Release();

  //IClassFactory
  STDMETHODIMP CreateInstance( IUnknown* outer, REFIID iid, LPVOID* obj );
  STDMETHODIMP LockServer( BOOL lockIt );
};



/*---------------------------------------------------------
  Dll entry points
-----------------------------------------------------------*/
BOOL APIENTRY DllMain( HINSTANCE instance, DWORD reason, LPVOID reserved )
{
  switch (reason)
  {
  case DLL_PROCESS_ATTACH:
    TRACE( "load dll" );
    g_instance    = instance;
    g_dllRefCount = 0;
    LoadTypeInfo();
    break;
  case DLL_PROCESS_DETACH:
    TRACE("unload dll");
    RELEASE(g_typeInfo);
    break;
  }

  return TRUE;
}

STDAPI DllCanUnloadNow()
{
  return (g_dllRefCount == 0);
}


STDAPI DllGetClassObject( REFCLSID clsid, REFIID iid, LPVOID* obj )
{
  OUTARG(obj);

  if (clsid == clsidEcmaService)
  {
    EcmaServiceFactory*  factory  = new EcmaServiceFactory();
    if (!factory) return E_OUTOFMEMORY;

    HRESULT hr = factory->QueryInterface(iid,obj);
    RELEASE(factory);
    return hr;
  }
  else 
    return CLASS_E_CLASSNOTAVAILABLE;
}


STDAPI DllRegisterServer()
{
  return RegisterServer(true,HKEY_CLASSES_ROOT);
}


STDAPI DllUnregisterServer()
{
  return RegisterServer(false,HKEY_CLASSES_ROOT);
}


STDAPI VSDllRegisterServer( LPOLESTR regRoot )
{
  return VSRegisterServer( true, regRoot );
}


STDAPI VSDllUnregisterServer( LPOLESTR regRoot )
{
  return VSRegisterServer( false, regRoot );
}


/*---------------------------------------------------------
  Class Factory
-----------------------------------------------------------*/
EcmaServiceFactory::EcmaServiceFactory()
{
  TRACE1("create EcmaServiceFactory: 0x%x", this );
  m_refCount = 1;
}

EcmaServiceFactory::~EcmaServiceFactory()
{
  TRACE1("destroy EcmaServiceFactory: 0x%x", this );
}

//IUnknown
STDMETHODIMP EcmaServiceFactory::QueryInterface( REFIID iid, LPVOID* obj )
{
  OUTARG(obj);

  if (iid == IID_IUnknown || iid == IID_IClassFactory)
  {
    *obj = static_cast<IClassFactory*>(this);
  }
  else
    return E_NOINTERFACE;

  AddRef();
  return S_OK;
}

STDMETHODIMP_(ULONG) EcmaServiceFactory::AddRef()
{
  return IncRefCount(&m_refCount);
}

STDMETHODIMP_(ULONG) EcmaServiceFactory::Release()
{
  if (DecRefCount(&m_refCount) == 0)
  {
    delete this;
    return 0;
  }
  else
    return m_refCount;
}

//IClassFactory
STDMETHODIMP EcmaServiceFactory::CreateInstance( IUnknown* outer, REFIID iid, LPVOID* obj )
{
  TRACE("EcmaServiceFactory::CreateInstance");
  OUTARG(obj);
  HRESULT hr;

  if (outer) return CLASS_E_NOAGGREGATION;

  EcmaService* service = new EcmaService(g_typeInfo);
  if (!service) return E_OUTOFMEMORY;

  hr = service->Init();
  if (FAILED(hr)) { RELEASE(service); return hr; }
  
  hr = service->QueryInterface( iid, obj );
  RELEASE(service);

  return hr;
}

STDMETHODIMP EcmaServiceFactory::LockServer( BOOL lockIt )
{
  if (lockIt)
  {
    IncRefCount( &g_dllRefCount );
  }
  else
  {
    DecRefCount( &g_dllRefCount );
  }

  return S_OK;
}

/*---------------------------------------------------------
  Load the BabelService type library
-----------------------------------------------------------*/
static HRESULT LoadTypeInfo()
{
  HRESULT hr;

  //load it only once
  if (g_typeInfo) return S_OK;

  //load the library
  ITypeLib* lib;
  hr = LoadRegTypeLib( LIBID_BabelServiceLib, 1, 0, LANG_NEUTRAL, &lib );
  if (FAILED(hr)) return hr;

  //get the typeinfo 
  hr = lib->GetTypeInfoOfGuid( IID_IBabelService, &g_typeInfo );
  RELEASE(lib);
  if (FAILED(hr)) return hr;

  return S_OK;
}

/*---------------------------------------------------------
  Registration
-----------------------------------------------------------*/
static HRESULT RegisterService( bool registerIt )
{
  HRESULT hr        = S_OK;
  HKEY    keyVS     = 0;
  HKEY    keySub    = 0;

 
  //get CLSIDs as strings
  OLECHAR oleCLSID[128];
  if (StringFromGUID2(clsidEcmaService, oleCLSID, 127) == 0) return E_FAIL;
  
  OLECHAR olePackageId[128];
  if (StringFromGUID2(clsidBabelPackage, olePackageId, 127) == 0) return E_FAIL;
  
  //open VS root
  hr = OleRegOpenKey( HKEY_LOCAL_MACHINE, pathVS, &keyVS );
  if (FAILED(hr)) return hr;

  //file extension
  if (!registerIt)
  {
    OleRegDeleteRecursive( keyVS, pathFileExt );
  }
  else
  {
    hr = OleRegCreateKey( keyVS, pathFileExt, &keySub );
    if (FAILED(hr)) goto fail;

    hr = OleRegSetValue( keySub, NULL, oleCLSID );
    if (FAILED(hr)) goto fail;

    hr = OleRegSetValue( keySub, OLE("Name"), ecmaName );
    if (FAILED(hr)) goto fail;

    RegCloseKey( keySub ); 
    keySub = 0;
  }

  //language service
  if (!registerIt)
  {
    OleRegDeleteRecursive( keyVS, pathLangService );
  }
  else
  {
    hr = OleRegCreateKey( keyVS, pathLangService, &keySub );
    if (FAILED(hr)) goto fail;

    hr = OleRegSetValue( keySub, NULL, oleCLSID );
    if (FAILED(hr)) goto fail;

    hr = OleRegSetValue( keySub, OLE("Package"), olePackageId );
    if (FAILED(hr)) goto fail;

    hr = OleRegSetValueDword( keySub, OLE("LangResId"), 0 );
    if (FAILED(hr)) goto fail;

    hr = OleRegSetValueDword( keySub, OLE("RequestStockColors"), 1 );
    if (FAILED(hr)) goto fail;
    
    hr = OleRegSetValueDword( keySub, OLE("QuickInfo"), 0 );
    if (FAILED(hr)) goto fail;
    
    hr = OleRegSetValueDword( keySub, OLE("CodeSenseDelay"), 1000 );
    if (FAILED(hr)) goto fail;
    
    RegCloseKey( keySub ); 
    keySub = 0;
  }

  //services
  OLECHAR pathServices[MAX_PATH+1];
  wcscpy( pathServices, OLE("Services\\" ) );
  wcscat( pathServices, oleCLSID );

  if (!registerIt)
  {
    OleRegDeleteRecursive( keyVS, pathServices );
  }
  else
  {
    hr = OleRegCreateKey( keyVS, pathServices, &keySub );
    if (FAILED(hr)) goto fail;

    hr = OleRegSetValue( keySub, NULL, olePackageId );
    if (FAILED(hr)) goto fail;

    hr = OleRegSetValue( keySub, OLE("Name"), ecmaName );
    if (FAILED(hr)) goto fail;

    RegCloseKey( keySub ); 
    keySub = 0;
  }

  //release resources
fail:
  if (keySub) RegCloseKey(keySub);
  if (keyVS)  RegCloseKey(keyVS);
  return hr;
}

static HRESULT RegisterServer( bool registerIt, HKEY keyRoot )
{
  HRESULT hr        = S_OK;
  HKEY    keyCLSID  = 0;
  HKEY    keyClass  = 0;
  HKEY    keyInProc = 0;

  //get clsid as string
  OLECHAR oleCLSID[128];
  if (StringFromGUID2(clsidEcmaService, oleCLSID, 127) == 0)
  { hr = E_FAIL; goto fail; }

  //get dll path
  OLECHAR dllPath[MAX_PATH];
  hr = OleGetModuleFileName( g_instance, dllPath, MAX_PATH-1 );
  if (FAILED(hr)) goto fail;
  
  //open CLSID key
  hr = OleRegOpenKey( keyRoot, OLE("CLSID"), &keyCLSID );
  if (FAILED(hr)) goto fail;


  if (!registerIt)
  {
    //nuke it
    hr = OleRegDeleteRecursive( keyCLSID, oleCLSID );
    if (FAILED(hr)) goto fail;
   }
  else
  {
    //create it
    hr = OleRegCreateKey( keyCLSID, oleCLSID, &keyClass );
    if (FAILED(hr)) goto fail;

    OleRegSetValue( keyClass, NULL, ecmaName);
    
    if (keyRoot == HKEY_CLASSES_ROOT)
    {
      hr = OleRegCreateKey( keyClass, OLE("InprocServer32"), &keyInProc );
      if (FAILED(hr)) goto fail;

      OleRegSetValue( keyInProc, NULL, dllPath );
      OleRegSetValue( keyInProc, OLE("ThreadingModel"), OLE("both") );
    }
    else
    {
      OleRegSetValue( keyClass, OLE("InprocServer32"), dllPath );
    }
  }

  
fail:
  if (keyInProc) RegCloseKey(keyInProc);
  if (keyClass)  RegCloseKey(keyClass);
  if (keyCLSID)  RegCloseKey(keyCLSID);

  if (SUCCEEDED(hr) || (registerIt == false))
    hr = RegisterService( registerIt );
  
  return hr;
}


/*---------------------------------------------------------
  VS Registration
-----------------------------------------------------------*/
static HRESULT VSRegisterServer( bool registerIt, LPOLESTR regRoot )
{
  HRESULT hr;
  HKEY    keyRoot;

  hr = DllRegisterServer();
  if (FAILED(hr)) return hr;

  if (regRoot) 
    hr = OleRegOpenKey( HKEY_LOCAL_MACHINE, regRoot, &keyRoot );
  else
    hr = OleRegOpenKey( HKEY_LOCAL_MACHINE, pathVS, &keyRoot );

  if (FAILED(hr)) return hr;

  hr = RegisterServer( registerIt, keyRoot );
  RegCloseKey( keyRoot );
  if (FAILED(hr)) return hr;

  return S_OK;
}

