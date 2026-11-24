/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#include "project.h"

#include "dllmain.h"
#include "resource.h" //IDB_IMAGELIST
#include "package.h"  
#include "strsafe.h"

/*---------------------------------------------------------
  globals
-----------------------------------------------------------*/
HINSTANCE  g_instance             = NULL;

ITypeInfo* g_typeInfoColorSink    = NULL;
ITypeInfo* g_typeInfoParseSink    = NULL;
ITypeInfo* g_typeInfoScope        = NULL;
ITypeInfo* g_typeInfoDeclarations = NULL;
ITypeInfo* g_typeInfoNames        = NULL;
ITypeInfo* g_typeInfoMethods      = NULL;
ITypeInfo* g_typeInfoBabelPackage = NULL;

const CLSID clsidBabelPackage = 
  { 0x221f0eb7, 0x30f7, 0x45ff, { 0xae, 0x73, 0x59, 0x68, 0xb1, 0x67, 0xcf, 0x9 } };

HIMAGELIST g_imageList         = NULL;

const int  ImageWidth          = 16;		
const int  ImageGrowFactor     = 4;

/*---------------------------------------------------------
  local globals
-----------------------------------------------------------*/
static ULONG g_dllRefCount     = 0;

//registry paths
static const wchar_t* regPathVS        = L"Software\\Microsoft\\VisualStudio\\8.0";

static const wchar_t* pathMenus        = L"Menus";
static const wchar_t* pathPackages     = L"Packages";
static const wchar_t* babelDescription = L"Babel Language Package";
static const wchar_t* valueMenu        = L",203,1";


/*---------------------------------------------------------
  Prototypes
-----------------------------------------------------------*/
static HRESULT RegisterServer( bool registerIt, HKEY keyRoot );
static HRESULT VSRegisterServer( bool registerIt, const wchar_t* regRoot );

static HRESULT LoadTypeInfo();
static HRESULT DoneTypeInfo();

static HRESULT LoadResources();
static HRESULT DoneResources();

/*---------------------------------------------------------
  Open vstudio root
-----------------------------------------------------------*/
HRESULT RegOpenKeyVS( REGSAM samDesired, out HKEY* key )
{
  return hrRegOpenKeyEx( HKEY_LOCAL_MACHINE, regPathVS, 0, samDesired, key );
}


/*---------------------------------------------------------
  Class Factory
-----------------------------------------------------------*/
class PackageFactory : IClassFactory
{
private:
  ULONG   m_refCount;

public:
  PackageFactory();
  ~PackageFactory();

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
  HRESULT hr = S_OK;
  const size_t pathSize = MAXPATH + 1;

  switch (reason)
  {
  case DLL_PROCESS_ATTACH:     
    //get clsid as string
    wchar_t oleCLSID[MAXCLSID];
    StringFromGUID2( clsidBabelPackage, oleCLSID, MAXCLSID);
      
    //create reg path
    wchar_t regPath[pathSize];
    StringCchCopy( regPath, pathSize, regPathVS );
    StringCchCat ( regPath, pathSize, L"\\" );
    StringCchCat ( regPath, pathSize, pathPackages );
    StringCchCat ( regPath, pathSize, L"\\" );
    StringCchCat ( regPath, pathSize, oleCLSID );

    //call trace init
    TRACE_INIT( "babel package", regPath );
    TRACE( "load dll" );

    g_instance    = instance;
    g_dllRefCount = 0;
    hr = LoadTypeInfo();  ASSERT(SUCCEEDED(hr));
    hr = LoadResources(); ASSERT(SUCCEEDED(hr));
    break;

  case DLL_PROCESS_DETACH:
    TRACE("unload dll");
    DoneResources();
    DoneTypeInfo();
    TRACE_DONE();
    break;
  case DLL_THREAD_ATTACH:
    TRACE("dll attach thread");
    break;
  case DLL_THREAD_DETACH:
    TRACE("dll detach thread");
    break;
  }

  return TRUE;
}

STDAPI DllCanUnloadNow()
{
    return (g_dllRefCount == 0) ? S_OK : S_FALSE;
}


STDAPI DllGetClassObject( REFCLSID clsid, REFIID iid, LPVOID* obj )
{
  OUTARG(obj);

  if (clsid == clsidBabelPackage)
  {
    PackageFactory*  factory  = new PackageFactory();
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
  return VSRegisterServer(true,NULL);
}


STDAPI DllUnregisterServer()
{
  return VSRegisterServer(false,NULL);
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
PackageFactory::PackageFactory()
{
  TRACE_CREATE("PackageFactory", this );
  m_refCount = 1;
}

PackageFactory::~PackageFactory()
{
  TRACE_DESTROY(this);
}

//IUnknown
STDMETHODIMP PackageFactory::QueryInterface( REFIID iid, LPVOID* obj )
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

STDMETHODIMP_(ULONG) PackageFactory::AddRef()
{
  return IncRefCount(&m_refCount);
}

STDMETHODIMP_(ULONG) PackageFactory::Release()
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
STDMETHODIMP PackageFactory::CreateInstance( IUnknown* outer, REFIID iid, LPVOID* obj )
{
  TRACE("PackageFactory::CreateInstance");
  OUTARG(obj);
  HRESULT hr;

  if (outer) return CLASS_E_NOAGGREGATION;

  Package* package = new Package();
  if (!package) return E_OUTOFMEMORY;

  // Package init must be performed during the IVsPackage::SetSite call
  // because the package should open the registry root for the appid(devenv)
  // instance that loaded this package
  // hr = package->Init();
  // if (FAILED(hr)) { RELEASE(package); return hr; }

  hr = package->QueryInterface( iid, obj );
  RELEASE(package);

  return hr;
}

STDMETHODIMP PackageFactory::LockServer( BOOL lockIt )
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
  Load resources
-----------------------------------------------------------*/
static HRESULT LoadResources()
{
  g_imageList = ImageList_LoadBitmap( g_instance, MAKEINTRESOURCE( IDB_COMPLETION_SET ), 
			                          ImageWidth, ImageGrowFactor, RGB( 0, 255, 0 ));
  if (!g_imageList) return E_FAIL;

  return S_OK;
}

static HRESULT DoneResources()
{
  if (g_imageList) 
  {
    ImageList_Destroy( g_imageList );
    g_imageList = NULL;
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
  if (g_typeInfoColorSink) return S_OK;

  //load the library
  ITypeLib* lib;
  hr = LoadRegTypeLib( LIBID_BabelServiceLib, 1, 0, LANG_NEUTRAL, &lib );

  //if not registered, load from filepath
  if (FAILED(hr))  
  {
    const size_t pathSize = MAXPATH + 1;
	wchar_t path[pathSize];
    DWORD dwLen = ::GetModuleFileName(g_instance, path, pathSize-1);
    if (dwLen == 0)
      return HRESULT_FROM_WIN32(::GetLastError());
    if (dwLen == MAXPATH)
      return HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER);
    path[pathSize-1] = 0;
   
    //change the file name
    wchar_t* fileName = wcsrchr( path, L'\\' );
    if (!fileName) return E_FAIL;
    
    fileName[1] = 0;
    StringCchCat( path, pathSize, L"babelservice.tlb" );

    //and try to load from the pathname
    hr = LoadTypeLibEx( path, REGKIND_REGISTER, &lib );
    if (FAILED(hr)) return hr;
  }


  //get the typeinfo 
  if (!g_typeInfoColorSink)
  {
    hr = lib->GetTypeInfoOfGuid( IID_IColorSink, &g_typeInfoColorSink );
    if (FAILED(hr)) { RELEASE(lib); return hr; }
  }

  if (!g_typeInfoParseSink)
  {
    hr = lib->GetTypeInfoOfGuid( IID_IParseSink, &g_typeInfoParseSink );
    if (FAILED(hr)) { RELEASE(lib); return hr; }
  }

  if (!g_typeInfoScope)
  {
    hr = lib->GetTypeInfoOfGuid( IID_IScope, &g_typeInfoScope );
    if (FAILED(hr)) { RELEASE(lib); return hr; }
  }

  if (!g_typeInfoDeclarations)
  {
    hr = lib->GetTypeInfoOfGuid( IID_IDeclarations, &g_typeInfoDeclarations );
    if (FAILED(hr)) { RELEASE(lib); return hr; }
  }

  if (!g_typeInfoNames)
  {
    hr = lib->GetTypeInfoOfGuid( IID_INames, &g_typeInfoNames );
    if (FAILED(hr)) { RELEASE(lib); return hr; }
  }

  if (!g_typeInfoMethods)
  {
    hr = lib->GetTypeInfoOfGuid( IID_IMethods, &g_typeInfoMethods );
    if (FAILED(hr)) { RELEASE(lib); return hr; }
  }

  if (!g_typeInfoBabelPackage)
  {
    hr = lib->GetTypeInfoOfGuid( IID_IBabelPackage, &g_typeInfoBabelPackage );
    if (FAILED(hr)) { RELEASE(lib); return hr; }
  }

  RELEASE(lib);
  return S_OK;
}

static HRESULT DoneTypeInfo()
{
  RELEASE(g_typeInfoBabelPackage);
  RELEASE(g_typeInfoMethods);
  RELEASE(g_typeInfoNames);
  RELEASE(g_typeInfoDeclarations);
  RELEASE(g_typeInfoColorSink);
  RELEASE(g_typeInfoParseSink);
  RELEASE(g_typeInfoScope);
  return S_OK;
}

/*---------------------------------------------------------
  Registration
-----------------------------------------------------------*/
static HRESULT RegisterServer( in bool registerIt, in HKEY keyRoot )
{
  HRESULT hr     = S_OK;
  
  HKEY    keySub = 0;
  const size_t pathSubSize = MAXPATH + 1;
  wchar_t pathSub[pathSubSize];
  
  //get clsid as string
  wchar_t oleCLSID[MAXCLSID];
  if (StringFromGUID2( clsidBabelPackage, oleCLSID, MAXCLSID) == 0)
    return E_FAIL;

  //get module path
  wchar_t modulePath[MAXPATH+1];
  DWORD dwLen = ::GetModuleFileName(g_instance, modulePath, MAXPATH);
  if (dwLen == 0)
    return HRESULT_FROM_WIN32(::GetLastError());
  if (dwLen == MAXPATH)
    return HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER);
  modulePath[MAXPATH] = 0;

  //package path
  StringCchCopy( pathSub, pathSubSize, pathPackages );
  StringCchCat ( pathSub, pathSubSize, L"\\" );
  StringCchCat ( pathSub, pathSubSize, oleCLSID );

  if (!registerIt)
  {
    RegDeleteKey( keyRoot, pathSub );
  }
  else
  {
    hr = hrRegCreateKeyEx( keyRoot, pathSub, 0, NULL, REG_OPTION_NON_VOLATILE, 
                           KEY_ALL_ACCESS, NULL, &keySub, NULL );
    if (FAILED(hr)) goto fail;

    hr = hrRegSetValueEx( keySub, NULL, 0, REG_SZ, (BYTE*)(babelDescription), (lstrlenW(babelDescription)+1)*sizeof(wchar_t));
    if (FAILED(hr)) goto fail;

    hr = hrRegSetValueEx( keySub, L"InprocServer32", 0, REG_SZ, (BYTE*)(modulePath), (lstrlenW(modulePath)+1)*sizeof(wchar_t));
    if (FAILED(hr)) goto fail;

    RegCloseKey(keySub);
    keySub = 0;
  }

  //typelib
  if (!registerIt)
  {
    hr = UnRegisterTypeLib( LIBID_BabelServiceLib, 1, 0, LANG_NEUTRAL, SYS_WIN32 );
  }

fail:
  if (keySub) RegCloseKey(keySub); 
  if (FAILED(hr)) return hr;

  return S_OK;
}


/*---------------------------------------------------------
  VS Registration
-----------------------------------------------------------*/
static HRESULT VSRegisterServer( bool registerIt, const wchar_t* regRoot )
{
  HRESULT hr;
  HKEY    keyRoot;

  if (regRoot) 
    hr = hrRegOpenKeyEx( HKEY_LOCAL_MACHINE, regRoot, 0, KEY_WRITE, &keyRoot );
  else
    hr = RegOpenKeyVS( KEY_WRITE, &keyRoot );
  if (FAILED(hr)) return hr;

  hr = RegisterServer( registerIt, keyRoot );
  RegCloseKey( keyRoot );
  if (FAILED(hr)) return hr;

  return S_OK;
}


