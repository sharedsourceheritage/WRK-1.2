
/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#include "project.h"
#include "vsshell.h"
#include "VSRegKeyNames.h"
#include <dbgmetric.h>  // SetEEMetric RemoveEEMetric

/*---------------------------------------------------------
  globals
-----------------------------------------------------------*/
HINSTANCE g_instance     = NULL;
ULONG     g_dllRefCount  = 0;

static const GUID CLSID_MycEE = 
  { 0x462d4a3d, 0xb257, 0x4aee, { 0x97, 0xcd, 0x59, 0x18, 0xc7, 0x53, 0x17, 0x57 } };

static const GUID guidMycLang = 
  { 0x462d4a3e, 0xb257, 0x4aee, { 0x97, 0xcd, 0x59, 0x18, 0xc7, 0x53, 0x17, 0x57 } };


/*---------------------------------------------------------
  Prototypes
-----------------------------------------------------------*/
static HRESULT RegisterServer( bool registerIt, HKEY keyRoot );

/*---------------------------------------------------------
  Class Factory
-----------------------------------------------------------*/
class CEEFactory : IClassFactory
{
private:
  ULONG   m_refCount;

public:
  CEEFactory();
  ~CEEFactory();

  //IUnknown
  STDMETHODIMP QueryInterface( REFIID iid, LPVOID* pobj );
  STDMETHODIMP_(ULONG) AddRef();
  STDMETHODIMP_(ULONG) Release();

  //IClassFactory
  STDMETHODIMP CreateInstance( IUnknown* pouter, REFIID iid, LPVOID* pobj );
  STDMETHODIMP LockServer( BOOL lockIt );
};



/*---------------------------------------------------------
  Dll entry points
-----------------------------------------------------------*/
BOOL APIENTRY DllMain( HINSTANCE instance, DWORD reason, LPVOID preserved )
{
  switch (reason)
  {
  case DLL_PROCESS_ATTACH:
    TRACE( "load dll" );
    g_instance    = instance;
    g_dllRefCount = 0;
    InitStrings( instance, CLSID_MycEE );
    break;
  case DLL_PROCESS_DETACH:
    TRACE("unload dll");
    DoneStrings();
    break;
  }

  return TRUE;
}

STDAPI DllCanUnloadNow()
{
  return (g_dllRefCount == 0) ? S_OK : S_FALSE;
}


STDAPI DllGetClassObject( REFCLSID clsid, REFIID iid, LPVOID* pobj )
{
  OUTARG(pobj);

  if (clsid == CLSID_MycEE)
  {
    CEEFactory*  pfactory  = new CEEFactory();
    if (!pfactory) return E_OUTOFMEMORY;

    HRESULT hr = pfactory->QueryInterface(iid,pobj);
    RELEASE(pfactory);
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


/*---------------------------------------------------------
  Class Factory
-----------------------------------------------------------*/
CEEFactory::CEEFactory()
{
  TRACE1("create CEEFactory: 0x%x", this );
  m_refCount = 1;
}

CEEFactory::~CEEFactory()
{
  TRACE1("destroy CEEFactory: 0x%x", this );
}

//IUnknown
STDMETHODIMP CEEFactory::QueryInterface( REFIID iid, LPVOID* pobj )
{
  OUTARG(pobj);

  if (iid == IID_IUnknown || iid == IID_IClassFactory)
  {
    *pobj = static_cast<IClassFactory*>(this);
  }
  else
    return E_NOINTERFACE;

  AddRef();
  return S_OK;
}

STDMETHODIMP_(ULONG) CEEFactory::AddRef()
{
  return IncRefCount(&m_refCount);
}

STDMETHODIMP_(ULONG) CEEFactory::Release()
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
STDMETHODIMP CEEFactory::CreateInstance( IUnknown* pouter, REFIID iid, LPVOID* pobj )
{
  TRACE("CEEFactory::CreateInstance");
  OUTARG(pobj);

  if (pouter) return CLASS_E_NOAGGREGATION;

  CExpressionEvaluator* pevaluator = new CExpressionEvaluator();
  if (!pevaluator) return E_OUTOFMEMORY;

  HRESULT hr = pevaluator->QueryInterface( iid, pobj );
  RELEASE(pevaluator);

  return hr;
}

STDMETHODIMP CEEFactory::LockServer( BOOL lockIt )
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
  Registration
-----------------------------------------------------------*/
#ifndef LREGKEY_VISUALSTUDIOROOT
    #define LREGKEY_VISUALSTUDIOROOT L"Software\\Microsoft\\VisualStudio\\7.1"
#endif

static HRESULT RegisterMetric( bool registerIt )
{
  // check where we should register
  const ULONG cchBuffer = _MAX_PATH;
  WCHAR wszRegistrationRoot[cchBuffer];
  DWORD cchFreeBuffer = cchBuffer - 1;
  wcscpy(wszRegistrationRoot, LREGKEY_VISUALSTUDIOROOT_NOVERSION);
  wcscat(wszRegistrationRoot, L"\\");

  // this is Environment SDK specific
  // we check for  EnvSdk_RegKey environment variable to
  // determine where to register
  DWORD cchDefRegRoot = lstrlenW(LREGKEY_VISUALSTUDIOROOT_NOVERSION) + 1;
  cchFreeBuffer = cchFreeBuffer - cchDefRegRoot;
  DWORD cchEnvVarRead = GetEnvironmentVariableW(
      /* LPCTSTR */ L"EnvSdk_RegKey",               // environment variable name
      /* LPTSTR  */ &wszRegistrationRoot[cchDefRegRoot],// buffer for variable value
      /* DWORD   */ cchFreeBuffer);// size of buffer
  if (cchEnvVarRead >= cchFreeBuffer)
    return E_UNEXPECTED;
  // If the environment variable does not exist then we must use 
  // LREGKEY_VISUALSTUDIOROOT which has the version number.
  if (0 == cchEnvVarRead)
    wcscpy(wszRegistrationRoot, LREGKEY_VISUALSTUDIOROOT);

  if (registerIt)
  {
    SetEEMetric( guidMycLang, guidMicrosoftVendor, metricCLSID, CLSID_MycEE, wszRegistrationRoot );
    SetEEMetric( guidMycLang, guidMicrosoftVendor, metricName,  GetString(IDS_INFO_MYCDESCRIPTION), wszRegistrationRoot );
    SetEEMetric( guidMycLang, guidMicrosoftVendor, metricLanguage, L"MyC", wszRegistrationRoot);

    GUID engineGuids[2];
    engineGuids[0] = guidCOMPlusOnlyEng;
    engineGuids[1] = guidCOMPlusNativeEng;
    SetEEMetric( guidMycLang, guidMicrosoftVendor, metricEngine, engineGuids, 2, wszRegistrationRoot);
  }
  else
  {
    RemoveEEMetric( guidMycLang, guidMicrosoftVendor, metricCLSID, wszRegistrationRoot);
    RemoveEEMetric( guidMycLang, guidMicrosoftVendor, metricName, wszRegistrationRoot );
    RemoveEEMetric( guidMycLang, guidMicrosoftVendor, metricLanguage, wszRegistrationRoot );
    RemoveEEMetric( guidMycLang, guidMicrosoftVendor, metricEngine, wszRegistrationRoot );
  }

  return S_OK;    
}

static HRESULT RegisterServer( bool registerIt, HKEY keyRoot )
{
  HRESULT hr        = S_OK;
  HKEY    keyCLSID  = 0;
  HKEY    keyClass  = 0;
  HKEY    keyInProc = 0;

  //get clsid as string
  OLECHAR oleCLSID[128];
  if (StringFromGUID2(CLSID_MycEE, oleCLSID, 127) == 0)
  { hr = E_FAIL; goto fail; }

  //get dll path
  OLECHAR dllPath[MAX_PATH];
  DWORD dwLen = ::GetModuleFileNameW(g_instance, dllPath, MAX_PATH);
  if (dwLen == 0)
  {
      hr = HRESULT_FROM_WIN32(::GetLastError());
      goto fail;
  }
  if (dwLen == MAX_PATH)
  {
      hr = HRESULT_FROM_WIN32(ERROR_INSUFFICIENT_BUFFER);
      goto fail;
  }
  
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

    OleRegSetValue( keyClass, NULL, GetString(IDS_INFO_MYCDESCRIPTION));
    
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
  if (keyClass) RegCloseKey(keyClass);
  if (keyCLSID) RegCloseKey(keyCLSID);

  if (SUCCEEDED(hr) || (registerIt == false))
    hr = RegisterMetric( registerIt );
  
  return hr;
}
