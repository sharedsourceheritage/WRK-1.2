// Created by Microsoft (R) C/C++ Compiler Version 14.00.40310.19 (d8c88be9).
//
// f:\beta1\vsa\idl\vsa\obj2r\i386\microsoft.vsa.tlh
//
// C++ source equivalent of Win32 type library Microsoft.Vsa.tlb
// compiler-generated file created 06/24/04 at 22:42:46 - DO NOT EDIT!

//
// Cross-referenced type libraries:
//
//  #import "//  #import "f:\beta1\Tools\x86\vc\bin\mscorlib.tlb"
//

#pragma once
#pragma pack(push, 8)

#include <comdef.h>

//
// Forward references and typedefs
//

struct __declspec(uuid("d3295d86-d604-11d4-a704-00c04fa137e4"))
/* LIBID */ __Microsoft_Vsa;
struct __declspec(uuid("e0c0ffe7-7eea-4ee5-b7e4-0080c7eb0b74"))
/* interface */ IVsaCodeItem;
struct __declspec(uuid("e0c0ffe5-7eea-4ee5-b7e4-0080c7eb0b74"))
/* interface */ IVsaItem;
struct __declspec(uuid("e0c0ffed-7eea-4ee5-b7e4-0080c7eb0b74"))
/* interface */ IVsaDTCodeItem;
struct __declspec(uuid("e0c0ffee-7eea-4ee5-b7e4-0080c7eb0b74"))
/* interface */ IVsaDTEngine;
struct __declspec(uuid("78470a10-8153-407d-ab1b-05067c54c36b"))
/* interface */ IVsaIDE;
struct __declspec(uuid("e0c0ffe1-7eea-4ee2-b7e4-0080c7eb0b74"))
/* interface */ IVsaEngine;
struct __declspec(uuid("e0c0ffe2-7eea-4ee2-b7e4-0080c7eb0b74"))
/* interface */ IVsaSite;
struct __declspec(uuid("0ab1eb6a-12bd-44d0-b941-0580adfc73de"))
/* interface */ IVsaItems;
struct __declspec(uuid("e0c0ffe3-7eea-4ee2-b7e4-0080c7eb0b74"))
/* interface */ IVsaPersistSite;
struct __declspec(uuid("e0c0ffe4-7eea-4ee2-b7e4-0080c7eb0b74"))
/* interface */ IVsaError;
struct __declspec(uuid("4e76d92e-e29d-46f3-ae22-0333158109f1"))
/* interface */ IVsaGlobalItem;
struct __declspec(uuid("7bd84086-1fb5-4b5d-8e05-eaa2f17218e0"))
/* interface */ IVsaIDESite;
struct __declspec(uuid("e0c0ffe6-7eea-4ee5-b7e4-0080c7eb0b74"))
/* interface */ IVsaReferenceItem;
struct /* coclass */ VsaException;
struct /* coclass */ VsaLoader;
struct /* coclass */ VsaModule;
struct __declspec(uuid("90100f83-54b7-36ab-997d-384216e4aacc"))
/* dual interface */ _VsaException;
struct __declspec(uuid("25c39c8c-fa1f-33f0-8bd8-2b2dffdac524"))
/* dual interface */ _VsaLoader;
struct __declspec(uuid("bbfe0a2a-91dc-3f1b-9968-fdd2e20f2e9f"))
/* dual interface */ _VsaModule;

//
// Smart pointer typedef declarations
//

_COM_SMARTPTR_TYPEDEF(IVsaCodeItem, __uuidof(IVsaCodeItem));
_COM_SMARTPTR_TYPEDEF(IVsaDTCodeItem, __uuidof(IVsaDTCodeItem));
_COM_SMARTPTR_TYPEDEF(IVsaPersistSite, __uuidof(IVsaPersistSite));
_COM_SMARTPTR_TYPEDEF(IVsaGlobalItem, __uuidof(IVsaGlobalItem));
_COM_SMARTPTR_TYPEDEF(IVsaIDESite, __uuidof(IVsaIDESite));
_COM_SMARTPTR_TYPEDEF(IVsaIDE, __uuidof(IVsaIDE));
_COM_SMARTPTR_TYPEDEF(IVsaDTEngine, __uuidof(IVsaDTEngine));
_COM_SMARTPTR_TYPEDEF(IVsaItem, __uuidof(IVsaItem));
_COM_SMARTPTR_TYPEDEF(IVsaError, __uuidof(IVsaError));
_COM_SMARTPTR_TYPEDEF(IVsaSite, __uuidof(IVsaSite));
_COM_SMARTPTR_TYPEDEF(IVsaItems, __uuidof(IVsaItems));
_COM_SMARTPTR_TYPEDEF(IVsaEngine, __uuidof(IVsaEngine));
_COM_SMARTPTR_TYPEDEF(IVsaReferenceItem, __uuidof(IVsaReferenceItem));
_COM_SMARTPTR_TYPEDEF(_VsaException, __uuidof(_VsaException));
_COM_SMARTPTR_TYPEDEF(_VsaLoader, __uuidof(_VsaLoader));
_COM_SMARTPTR_TYPEDEF(_VsaModule, __uuidof(_VsaModule));

//
// Type library items
//

struct __declspec(uuid("e0c0ffe7-7eea-4ee5-b7e4-0080c7eb0b74"))
IVsaCodeItem : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_SourceText (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall put_SourceText (
        /*[in]*/ BSTR pRetVal ) = 0;
      virtual HRESULT __stdcall get_CodeDOM (
        /*[out,retval]*/ struct IDispatch * * pRetVal ) = 0;
      virtual HRESULT __stdcall AppendSourceText (
        /*[in]*/ BSTR text ) = 0;
      virtual HRESULT __stdcall AddEventSource (
        /*[in]*/ BSTR eventSourceName,
        /*[in]*/ BSTR eventSourceType ) = 0;
      virtual HRESULT __stdcall RemoveEventSource (
        /*[in]*/ BSTR eventSourceName ) = 0;
};

struct __declspec(uuid("e0c0ffed-7eea-4ee5-b7e4-0080c7eb0b74"))
IVsaDTCodeItem : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_CanDelete (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall put_CanDelete (
        /*[in]*/ VARIANT_BOOL pRetVal ) = 0;
      virtual HRESULT __stdcall get_CanMove (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall put_CanMove (
        /*[in]*/ VARIANT_BOOL pRetVal ) = 0;
      virtual HRESULT __stdcall get_CanRename (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall put_CanRename (
        /*[in]*/ VARIANT_BOOL pRetVal ) = 0;
      virtual HRESULT __stdcall get_Hidden (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall put_Hidden (
        /*[in]*/ VARIANT_BOOL pRetVal ) = 0;
      virtual HRESULT __stdcall get_ReadOnly (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall put_ReadOnly (
        /*[in]*/ VARIANT_BOOL pRetVal ) = 0;
};

struct __declspec(uuid("e0c0ffe3-7eea-4ee2-b7e4-0080c7eb0b74"))
IVsaPersistSite : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall SaveElement (
        /*[in]*/ BSTR Name,
        /*[in]*/ BSTR source ) = 0;
      virtual HRESULT __stdcall LoadElement (
        /*[in]*/ BSTR Name,
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
};

struct __declspec(uuid("4e76d92e-e29d-46f3-ae22-0333158109f1"))
IVsaGlobalItem : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall put_TypeString (
        /*[in]*/ BSTR _arg1 ) = 0;
      virtual HRESULT __stdcall get_ExposeMembers (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall put_ExposeMembers (
        /*[in]*/ VARIANT_BOOL pRetVal ) = 0;
};

struct __declspec(uuid("7bd84086-1fb5-4b5d-8e05-eaa2f17218e0"))
IVsaIDESite : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall Notify (
        /*[in]*/ BSTR Notify,
        /*[in]*/ VARIANT optional ) = 0;
};

struct __declspec(uuid("78470a10-8153-407d-ab1b-05067c54c36b"))
IVsaIDE : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Site (
        /*[out,retval]*/ struct IVsaIDESite * * pRetVal ) = 0;
      virtual HRESULT __stdcall putref_Site (
        /*[in]*/ struct IVsaIDESite * pRetVal ) = 0;
      virtual HRESULT __stdcall ShowIDE (
        /*[in]*/ VARIANT_BOOL showOrHide ) = 0;
      virtual HRESULT __stdcall get_DefaultSearchPath (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall put_DefaultSearchPath (
        /*[in]*/ BSTR pRetVal ) = 0;
      virtual HRESULT __stdcall get_ExtensibilityObject (
        /*[out,retval]*/ IUnknown * * pRetVal ) = 0;
      virtual HRESULT __stdcall EnableMainWindow (
        /*[in]*/ VARIANT_BOOL isEnable ) = 0;
      virtual HRESULT __stdcall get_IDEMode (
        /*[out,retval]*/ enum VsaIDEMode * pRetVal ) = 0;
};

struct __declspec(uuid("e0c0ffee-7eea-4ee5-b7e4-0080c7eb0b74"))
IVsaDTEngine : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_TargetURL (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall put_TargetURL (
        /*[in]*/ BSTR pRetVal ) = 0;
      virtual HRESULT __stdcall InitCompleted ( ) = 0;
      virtual HRESULT __stdcall GetIDE (
        /*[out,retval]*/ struct IVsaIDE * * pRetVal ) = 0;
      virtual HRESULT __stdcall AttachDebugger (
        /*[in]*/ VARIANT_BOOL isAttach ) = 0;
};

struct __declspec(uuid("e0c0ffe5-7eea-4ee5-b7e4-0080c7eb0b74"))
IVsaItem : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall put_Name (
        /*[in]*/ BSTR pRetVal ) = 0;
      virtual HRESULT __stdcall get_ItemType (
        /*[out,retval]*/ enum VsaItemType * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsDirty (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall GetOption (
        /*[in]*/ BSTR Name,
        /*[out,retval]*/ VARIANT * pRetVal ) = 0;
      virtual HRESULT __stdcall SetOption (
        /*[in]*/ BSTR Name,
        /*[in]*/ VARIANT value ) = 0;
};

struct __declspec(uuid("e0c0ffe4-7eea-4ee2-b7e4-0080c7eb0b74"))
IVsaError : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Line (
        /*[out,retval]*/ long * pRetVal ) = 0;
      virtual HRESULT __stdcall get_Severity (
        /*[out,retval]*/ long * pRetVal ) = 0;
      virtual HRESULT __stdcall get_Description (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall get_LineText (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall get_SourceItem (
        /*[out,retval]*/ struct IVsaItem * * pRetVal ) = 0;
      virtual HRESULT __stdcall get_EndColumn (
        /*[out,retval]*/ long * pRetVal ) = 0;
      virtual HRESULT __stdcall get_StartColumn (
        /*[out,retval]*/ long * pRetVal ) = 0;
      virtual HRESULT __stdcall get_Number (
        /*[out,retval]*/ long * pRetVal ) = 0;
      virtual HRESULT __stdcall get_SourceMoniker (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
};

struct __declspec(uuid("e0c0ffe2-7eea-4ee2-b7e4-0080c7eb0b74"))
IVsaSite : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall GetCompiledState (
        /*[out]*/ SAFEARRAY * * pe,
        /*[out]*/ SAFEARRAY * * debugInfo ) = 0;
      virtual HRESULT __stdcall OnCompilerError (
        /*[in]*/ struct IVsaError * error,
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall GetGlobalInstance (
        /*[in]*/ BSTR Name,
        /*[out,retval]*/ IUnknown * * pRetVal ) = 0;
      virtual HRESULT __stdcall GetEventSourceInstance (
        /*[in]*/ BSTR itemName,
        /*[in]*/ BSTR eventSourceName,
        /*[out,retval]*/ IUnknown * * pRetVal ) = 0;
      virtual HRESULT __stdcall Notify (
        /*[in]*/ BSTR Notify,
        /*[in]*/ VARIANT info ) = 0;
};

struct __declspec(uuid("0ab1eb6a-12bd-44d0-b941-0580adfc73de"))
IVsaItems : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Count (
        /*[out,retval]*/ long * pRetVal ) = 0;
      virtual HRESULT __stdcall get_Item (
        /*[in]*/ BSTR Name,
        /*[out,retval]*/ struct IVsaItem * * pRetVal ) = 0;
      virtual HRESULT __stdcall get_Item_2 (
        /*[in]*/ long index,
        /*[out,retval]*/ struct IVsaItem * * pRetVal ) = 0;
      virtual HRESULT __stdcall CreateItem (
        /*[in]*/ BSTR Name,
        /*[in]*/ enum VsaItemType ItemType,
        /*[in]*/ enum VsaItemFlag itemFlag,
        /*[out,retval]*/ struct IVsaItem * * pRetVal ) = 0;
      virtual HRESULT __stdcall Remove (
        /*[in]*/ BSTR Name ) = 0;
      virtual HRESULT __stdcall Remove_2 (
        /*[in]*/ long index ) = 0;
};

struct __declspec(uuid("e0c0ffe1-7eea-4ee2-b7e4-0080c7eb0b74"))
IVsaEngine : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_Site (
        /*[out,retval]*/ struct IVsaSite * * pRetVal ) = 0;
      virtual HRESULT __stdcall putref_Site (
        /*[in]*/ struct IVsaSite * pRetVal ) = 0;
      virtual HRESULT __stdcall get_Name (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall put_Name (
        /*[in]*/ BSTR pRetVal ) = 0;
      virtual HRESULT __stdcall get_RootMoniker (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall put_RootMoniker (
        /*[in]*/ BSTR pRetVal ) = 0;
      virtual HRESULT __stdcall get_RootNamespace (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall put_RootNamespace (
        /*[in]*/ BSTR pRetVal ) = 0;
      virtual HRESULT __stdcall get_LCID (
        /*[out,retval]*/ long * pRetVal ) = 0;
      virtual HRESULT __stdcall put_LCID (
        /*[in]*/ long pRetVal ) = 0;
      virtual HRESULT __stdcall get_GenerateDebugInfo (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall put_GenerateDebugInfo (
        /*[in]*/ VARIANT_BOOL pRetVal ) = 0;
      virtual HRESULT __stdcall get_Evidence (
        /*[out,retval]*/ struct _Evidence * * pRetVal ) = 0;
      virtual HRESULT __stdcall putref_Evidence (
        /*[in]*/ struct _Evidence * pRetVal ) = 0;
      virtual HRESULT __stdcall get_Items (
        /*[out,retval]*/ struct IVsaItems * * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsDirty (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_Language (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall get_Version (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall GetOption (
        /*[in]*/ BSTR Name,
        /*[out,retval]*/ VARIANT * pRetVal ) = 0;
      virtual HRESULT __stdcall SetOption (
        /*[in]*/ BSTR Name,
        /*[in]*/ VARIANT value ) = 0;
      virtual HRESULT __stdcall Compile (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall Run ( ) = 0;
      virtual HRESULT __stdcall Reset ( ) = 0;
      virtual HRESULT __stdcall Close ( ) = 0;
      virtual HRESULT __stdcall get_IsRunning (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_IsCompiled (
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall RevokeCache ( ) = 0;
      virtual HRESULT __stdcall SaveSourceState (
        /*[in]*/ struct IVsaPersistSite * Site ) = 0;
      virtual HRESULT __stdcall LoadSourceState (
        /*[in]*/ struct IVsaPersistSite * Site ) = 0;
      virtual HRESULT __stdcall SaveCompiledState (
        /*[out]*/ SAFEARRAY * * pe,
        /*[out]*/ SAFEARRAY * * pdb ) = 0;
      virtual HRESULT __stdcall InitNew ( ) = 0;
      virtual HRESULT __stdcall IsValidIdentifier (
        /*[in]*/ BSTR identifier,
        /*[out,retval]*/ VARIANT_BOOL * pRetVal ) = 0;
      virtual HRESULT __stdcall get_Assembly (
        /*[out,retval]*/ struct _Assembly * * pRetVal ) = 0;
};

struct __declspec(uuid("e0c0ffe6-7eea-4ee5-b7e4-0080c7eb0b74"))
IVsaReferenceItem : IUnknown
{
    //
    // Raw methods provided by interface
    //

      virtual HRESULT __stdcall get_AssemblyName (
        /*[out,retval]*/ BSTR * pRetVal ) = 0;
      virtual HRESULT __stdcall put_AssemblyName (
        /*[in]*/ BSTR pRetVal ) = 0;
};

struct __declspec(uuid("5f44bb1a-465a-37db-8e84-acc733bf7541"))
VsaException;
    // [ default ] interface _VsaException
    // interface _Object
    // interface ISerializable
    // interface _Exception

struct __declspec(uuid("37e0fbbb-865f-339d-acf9-fd66f9a2867e"))
VsaLoader;
    // [ default ] interface _VsaLoader
    // interface _Object
    // interface IVsaEngine

struct __declspec(uuid("7f64f934-c1cc-338e-b695-f64d71e820fe"))
VsaModule;
    // [ default ] interface _VsaModule
    // interface _Object

struct __declspec(uuid("90100f83-54b7-36ab-997d-384216e4aacc"))
_VsaException : IDispatch
{};

struct __declspec(uuid("25c39c8c-fa1f-33f0-8bd8-2b2dffdac524"))
_VsaLoader : IDispatch
{};

struct __declspec(uuid("bbfe0a2a-91dc-3f1b-9968-fdd2e20f2e9f"))
_VsaModule : IDispatch
{};

#pragma pack(pop)
