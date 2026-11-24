/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#include "project.h"
#include <stdio.h>
#include <stdarg.h>

#include "vsmem.h"

/*---------------------------------------------------------
  Reference counting
-----------------------------------------------------------*/
ULONG IncRefCount( inout ULONG* refCount )
{
  return (ULONG)InterlockedIncrement( (LONG*)refCount );
}

ULONG DecRefCount( inout ULONG* refCount )
{
  return (ULONG)InterlockedDecrement( (LONG*)refCount );
}


/*---------------------------------------------------------
  Component identity
---------------------------------------------------------*/
bool SameObject( IUnknown* obj1, IUnknown* obj2 )
{
  HRESULT hr;
  IUnknown* unk1;
  IUnknown* unk2;

  if (obj1 == obj2) return true;
  if (!obj1) return false;
  if (!obj2) return false;

  hr = obj1->QueryInterface( IID_IUnknown, reinterpret_cast<void**>(&unk1) );
  if (FAILED(hr)) return false;
  
  hr = obj2->QueryInterface( IID_IUnknown, reinterpret_cast<void**>(&unk2) );
  if (FAILED(hr)) { RELEASE(unk1); return false; }

  bool areEqual = (unk1 == unk2);
  RELEASE(unk1);
  RELEASE(unk2);

  return areEqual;  
}

/*---------------------------------------------------------
  Connection points
-----------------------------------------------------------*/
STDMETHODIMP Connect( in IUnknown* eventSource, in IUnknown* eventSink, 
                      in const IID& eventIID, out DWORD* cookie )
{
  HRESULT hr;
  OUTARG(cookie);
  REFARG(eventSource);
  REFARG(eventSink);

  IConnectionPointContainer*  connectContainer = NULL;
  IConnectionPoint*           connectPoint     = NULL;

  hr = eventSource->QueryInterface (IID_IConnectionPointContainer, reinterpret_cast<void**>(&connectContainer) );
  if (FAILED(hr)) return hr;

  hr = connectContainer->FindConnectionPoint (eventIID, &connectPoint );
  RELEASE(connectContainer);
  if (FAILED(hr)) return hr;

  hr = connectPoint->Advise (eventSink, cookie);
  RELEASE(connectPoint);
  if (FAILED(hr)) return hr;
  
  return S_OK;
}

STDMETHODIMP DisConnect( in IUnknown* eventSource, in const IID& eventIID, inout DWORD* cookie )
{
  INOUTARG(cookie);
  REFARG(eventSource);
  HRESULT hr;

  if (*cookie == 0)  return S_OK;

  IConnectionPointContainer*  connectContainer;
  IConnectionPoint*           connectPoint;

  hr = eventSource->QueryInterface (IID_IConnectionPointContainer, reinterpret_cast<void**>(&connectContainer));
  if (FAILED(hr)) return hr;

  hr = connectContainer->FindConnectionPoint(eventIID, &connectPoint);
  RELEASE(connectContainer);
  if (FAILED(hr)) return hr;

  hr = connectPoint->Unadvise(*cookie);
  *cookie = 0;
  RELEASE(connectPoint);  
  if (FAILED(hr)) return hr;

  return S_OK;
}



/*---------------------------------------------------------
  Debugging
-----------------------------------------------------------*/
static const char*      g_traceModuleName = NULL;
static CRITICAL_SECTION g_traceGuard;
static DWORD            g_traceThreadID;
static FILE*            g_traceFile;

void TraceOutput( const char* s )
{
  OutputDebugStringA( s );
  if (g_traceFile)
  {
    fputs(s, g_traceFile);
    fflush(g_traceFile);
  }
}

void Trace( const char* format, ... )
{
  va_list args;
  va_start( args, format );

  EnterCriticalSection( &g_traceGuard );

  if (g_traceModuleName)
  {
    TraceOutput(g_traceModuleName);
    TraceOutput(": ");
  }

  char buffer[1024];
  
  DWORD threadID = GetCurrentThreadId();
  if (threadID != g_traceThreadID)
  {
    _snprintf( buffer, 1023, "tid 0x%x: ", threadID );
    buffer[1023] = 0;
    TraceOutput(buffer);
  }

  _vsnprintf( buffer, 1024, format, args );
  buffer[1023] = 0;

  TraceOutput(buffer);

  TraceOutput("\n");

  LeaveCriticalSection( &g_traceGuard );

  va_end( args );
  return;
}


/*---------------------------------------------------------
  Track object life times
-----------------------------------------------------------*/
struct ObjectInfo
{
  ObjectInfo* next;
  const char* name;
  bool        hide;
  IUnknown*   obj;
};

static ObjectInfo*      objectList = NULL;

void TraceLiveObjects( in const char* msg)
{
  EnterCriticalSection( &g_traceGuard );
  
  TRACE1("%s; live objects:", msg );
  for (ObjectInfo* objectInfo = objectList; objectInfo; objectInfo = objectInfo->next )
  {
    ULONG refCount = objectInfo->obj->AddRef();
    if (refCount > 0)
    {
      objectInfo->obj->Release();
      refCount--;
    }
    TRACE3( "  0x%x, refcount %u, %s", objectInfo->obj, refCount, objectInfo->name); 
  }

  LeaveCriticalSection( &g_traceGuard );
}

void TraceInit( const char* moduleName, wchar_t* regPath )
{
  InitializeCriticalSection( &g_traceGuard );
  g_traceThreadID     = GetCurrentThreadId();
  
  g_traceModuleName = moduleName;  
  g_traceFile       = NULL;
  objectList        = NULL;
  

  //open trace file
  //get reg key
  HKEY regKey;
  HRESULT hr = hrRegOpenKeyEx( HKEY_LOCAL_MACHINE, regPath, 0, KEY_READ, &regKey );
  if (FAILED(hr)) return;

  //get log file name from registry
  char  logFile[MAX_PATH];
  DWORD logFileLen = MAX_PATH;
  hr = hrRegQueryValueExA( regKey, "TraceFile", 0, NULL, (BYTE*)logFile, &logFileLen );
  RegCloseKey( regKey );
  if (FAILED(hr)) return;

  g_traceFile = fopen( logFile, "w+" );
}

void TraceDone()
{
  EnterCriticalSection( &g_traceGuard );

  if (objectList)
  {
    TraceLiveObjects( "TraceDone: found unreleased objects" );
    ASSERT( "TraceDone: found unrelease objects" );
  }

  ObjectInfo* objectInfo;
  ObjectInfo* objectNext;

  objectInfo = objectList;
  while (objectInfo)
  {
    objectNext = objectInfo->next;
    FREE(objectInfo);
    objectInfo = objectNext;
  }

  objectList = NULL;

  LeaveCriticalSection( &g_traceGuard );
  DeleteCriticalSection( &g_traceGuard );

  if (g_traceFile) 
  {
    fclose( g_traceFile );
    g_traceFile = NULL;
  }
}



void TraceCreate( const char* name, IUnknown* obj, bool hide )
{
  if (!obj) return;

  ObjectInfo* objectInfo = ALLOC(ObjectInfo);
  if (!objectInfo)
  {
    TRACE1("TraceCreate: creation of %s failed", name );
    return;
  }

  if (!hide) { TRACE2( "create %s at 0x%x", name, obj ); }

  EnterCriticalSection( &g_traceGuard );

  objectInfo->name = name;
  objectInfo->obj  = obj;
  objectInfo->hide = hide;
  objectInfo->next = objectList;
  objectList       = objectInfo;

  LeaveCriticalSection( &g_traceGuard );
}

void TraceDestroy( IUnknown* obj )
{
  EnterCriticalSection( &g_traceGuard );

  ObjectInfo* objectInfo;
  ObjectInfo* objectPrev = NULL;

  for (objectInfo = objectList; objectInfo; objectInfo = objectInfo->next)
  {
    if (objectInfo->obj == obj) break;
    objectPrev = objectInfo;
  }

  if (!objectInfo)
  {
    TRACE1( "TraceDestroy: destroying unknown object at 0x%x", obj );
  }
  else
  {
    if (!objectInfo->hide) 
    { 
      TRACE2( "destroy %s at 0x%8x", objectInfo->name, objectInfo->obj ); 
    }

    if (objectPrev)
      objectPrev->next = objectInfo->next;
    else
      objectList = objectInfo->next;

    FREE(objectInfo);
  }

  LeaveCriticalSection( &g_traceGuard );
}
