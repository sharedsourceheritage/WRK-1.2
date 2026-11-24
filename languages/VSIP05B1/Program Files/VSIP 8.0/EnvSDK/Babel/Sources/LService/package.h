/***************************************************************************
         Copyright (c) Microsoft Corporation, All rights reserved.             
    This code sample is provided "AS IS" without warranty of any kind, 
    it is not recommended for use in a production environment.
***************************************************************************/

#ifndef package_h
#define package_h

#include <olecm.h>  //for IOleComponent

const long DirectLoad = 0x12345678;

/*---------------------------------------------------------
  Package
-----------------------------------------------------------*/
class Package : public IVsPackage, 
                public IServiceProvider,
                public IOleComponent,
                public IBabelPackage
{
private:
  ULONG                 m_refCount;
  IServiceProvider*     m_provider;
  ObjectList*           m_languages;
  
  IOleComponentManager* m_componentManager;  
#ifdef VS7SDK
  DWORD_PTR             m_componentManagerConnect;
#else
  DWORD                 m_componentManagerConnect;
#endif

public:
  Package();
  ~Package();

  STDMETHODIMP Init();
  STDMETHODIMP Done();

  //IUnknown
  STDMETHODIMP QueryInterface( in REFIID iid, out void** obj );
  STDMETHODIMP_(ULONG) AddRef();
  STDMETHODIMP_(ULONG) Release();

 //implement IDispatch (for IBabelPackage only)
  STDMETHODIMP GetTypeInfoCount( out UINT* count );
  STDMETHODIMP GetTypeInfo     ( in UINT index, in LCID lcid, out ITypeInfo** typeInfo );
  STDMETHODIMP GetIDsOfNames   ( in REFIID iid, in OLECHAR** names, in UINT count, in LCID lcid, out DISPID* dispids );
  STDMETHODIMP Invoke          ( in DISPID dispid, in REFIID iid, in LCID lcid, in WORD flags, in DISPPARAMS* args, out VARIANT* result, out EXCEPINFO* error, out UINT* errorArg );


  //IVsPackage
  STDMETHODIMP SetSite( in IServiceProvider* provider );
  STDMETHODIMP QueryClose( out BOOL* canClose );
  STDMETHODIMP Close();
  STDMETHODIMP GetAutomationObject( in LPCOLESTR propertyName, out IDispatch** obj );
  STDMETHODIMP CreateTool( in REFGUID guidTool );
  STDMETHODIMP ResetDefaults( in PKGRESETFLAGS flags );
  STDMETHODIMP GetPropertyPage( in REFGUID guidPage, VSPROPSHEETPAGE* page );

  //IServiceProvider
  STDMETHODIMP QueryService( in REFGUID sid, in REFIID iid, void** obj );

  //IBabelPackage
  STDMETHODIMP LoadScope( in long reserved, in BSTR filePath, 
                          in IBabelProject* project, out IScope** scope );

  // IOleComponent, lots of stuff just for idle time processing
  STDMETHODIMP_(BOOL) FDoIdle( in DWORD grfidlef );
  STDMETHODIMP_(void) Terminate();  
  
  STDMETHOD_(BOOL, FPreTranslateMessage) (MSG *pMsg)                    { return FALSE; }
  STDMETHOD_(void, OnEnterState) (ULONG uStateID, BOOL fEnter)          {}
  STDMETHOD_(void, OnAppActivate) (BOOL fActive, DWORD dwOtherThreadID) {}
  STDMETHOD_(void, OnLoseActivation) ()                                 {}
  STDMETHOD_(void, OnActivationChange) (IOleComponent* pic, BOOL fSameComponent, const OLECRINFO *pcrinfo, BOOL fHostIsActivating, const OLECHOSTINFO *pchostinfo, DWORD dwReserved) {}
  STDMETHOD_(BOOL, FContinueMessageLoop) (ULONG uReason, void *pvLoopData, MSG *pMsgPeeked)   { return TRUE; }
  STDMETHOD_(BOOL, FQueryTerminate) (BOOL fPromptUser)                  { return TRUE; }
  STDMETHOD_(HWND, HwndGetWindow) (DWORD dwWhich, DWORD dwReserved)     { return NULL; }

#if (defined(VS6SDK) || defined(VS7SDK))
  STDMETHOD_(BOOL, FReserved1) (DWORD dwReserved, UINT message, WPARAM wParam, LPARAM lParam)  { return TRUE; }
#else 
  STDMETHOD_(BOOL, FDebugMessage) (HOLEINST hinst, UINT message, WPARAM wParam, LPARAM lParam) { return FALSE; }
#endif

};


#endif
