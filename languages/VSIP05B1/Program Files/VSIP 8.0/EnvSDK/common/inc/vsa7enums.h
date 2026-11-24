// Created by Microsoft (R) C/C++ Compiler Version 14.00.40310.19 (51525e57).
//
// f:\beta1\vsa\idl\vsa\obj2r\i386\microsoft.vsaenums.tlh
//
// C++ source equivalent of Win32 type library Microsoft.VsaEnums.tlb
// compiler-generated file created 06/24/04 at 22:42:49 - DO NOT EDIT!

#pragma once
#pragma pack(push, 8)

#include <comdef.h>

//
// Forward references and typedefs
//

struct __declspec(uuid("d3295d86-d604-11d4-a704-00c04fa137e4"))
/* LIBID */ __Microsoft_Vsa;
enum VsaIDEMode;
enum VsaItemType;
enum VsaItemFlag;
enum VsaError;
struct /* coclass */ VsaLoader;
struct /* coclass */ VsaModule;

//
// Type library items
//

enum __declspec(uuid("05a1147d-6c8d-3bb8-888f-8bfa319b2e6f"))
VsaIDEMode
{
    VsaIDEMode_Break = 0,
    VsaIDEMode_Design = 1,
    VsaIDEMode_Run = 2
};

enum __declspec(uuid("a9f6f86e-fcf5-3d8d-97e4-0fe6c7fe2274"))
VsaItemType
{
    VsaItemType_AppGlobal = 1,
    VsaItemType_Code = 2,
    VsaItemType_Reference = 0
};

enum __declspec(uuid("40d8ce77-8139-3483-8674-bb9e3acd9b89"))
VsaItemFlag
{
    VsaItemFlag_Class = 2,
    VsaItemFlag_Module = 1,
    VsaItemFlag_None = 0
};

enum __declspec(uuid("c216f805-8fab-3d33-bf81-7b1035e917b9"))
VsaError
{
    VsaError_AppDomainCannotBeSet = -2146226176,
    VsaError_AppDomainInvalid = -2146226175,
    VsaError_ApplicationBaseCannotBeSet = -2146226174,
    VsaError_ApplicationBaseInvalid = -2146226173,
    VsaError_AssemblyExpected = -2146226172,
    VsaError_AssemblyNameInvalid = -2146226171,
    VsaError_BadAssembly = -2146226170,
    VsaError_BrowserNotExist = -2146226115,
    VsaError_CachedAssemblyInvalid = -2146226169,
    VsaError_CallbackUnexpected = -2146226168,
    VsaError_CannotAttachToWebServer = -2146226100,
    VsaError_CodeDOMNotAvailable = -2146226167,
    VsaError_CompiledStateNotFound = -2146226166,
    VsaError_DebugInfoNotSupported = -2146226165,
    VsaError_DebuggeeNotStarted = -2146226114,
    VsaError_ElementNameInvalid = -2146226164,
    VsaError_ElementNotFound = -2146226163,
    VsaError_EngineBusy = -2146226162,
    VsaError_EngineCannotClose = -2146226161,
    VsaError_EngineCannotReset = -2146226160,
    VsaError_EngineClosed = -2146226159,
    VsaError_EngineEmpty = -2146226159,
    VsaError_EngineInitialized = -2146226157,
    VsaError_EngineNameInUse = -2146226156,
    VsaError_EngineNameInvalid = -2146226113,
    VsaError_EngineNameNotSet = -2146226099,
    VsaError_EngineNotCompiled = -2146226155,
    VsaError_EngineNotExist = -2146226112,
    VsaError_EngineNotInitialized = -2146226154,
    VsaError_EngineNotRunning = -2146226153,
    VsaError_EngineRunning = -2146226152,
    VsaError_EventSourceInvalid = -2146226151,
    VsaError_EventSourceNameInUse = -2146226150,
    VsaError_EventSourceNameInvalid = -2146226149,
    VsaError_EventSourceNotFound = -2146226148,
    VsaError_EventSourceTypeInvalid = -2146226147,
    VsaError_FileFormatUnsupported = -2146226111,
    VsaError_FileTypeUnknown = -2146226110,
    VsaError_GetCompiledStateFailed = -2146226146,
    VsaError_GlobalInstanceInvalid = -2146226145,
    VsaError_GlobalInstanceTypeInvalid = -2146226144,
    VsaError_InternalCompilerError = -2146226143,
    VsaError_ItemCannotBeRemoved = -2146226142,
    VsaError_ItemCannotBeRenamed = -2146226109,
    VsaError_ItemFlagNotSupported = -2146226141,
    VsaError_ItemNameInUse = -2146226140,
    VsaError_ItemNameInvalid = -2146226139,
    VsaError_ItemNotFound = -2146226138,
    VsaError_ItemTypeNotSupported = -2146226137,
    VsaError_LCIDNotSupported = -2146226136,
    VsaError_LoadElementFailed = -2146226135,
    VsaError_MissingPdb = -2146226102,
    VsaError_MissingSource = -2146226108,
    VsaError_NameTooLong = -2146226106,
    VsaError_NotClientSideAndNoUrl = -2146226101,
    VsaError_NotInitCompleted = -2146226107,
    VsaError_NotificationInvalid = -2146226134,
    VsaError_OptionInvalid = -2146226133,
    VsaError_OptionNotSupported = -2146226132,
    VsaError_ProcNameInUse = -2146226105,
    VsaError_ProcNameInvalid = -2146226104,
    VsaError_RevokeFailed = -2146226131,
    VsaError_RootMonikerAlreadySet = -2146226130,
    VsaError_RootMonikerInUse = -2146226129,
    VsaError_RootMonikerInvalid = -2146226128,
    VsaError_RootMonikerNotSet = -2146226127,
    VsaError_RootMonikerProtocolInvalid = -2146226126,
    VsaError_RootNamespaceInvalid = -2146226125,
    VsaError_RootNamespaceNotSet = -2146226124,
    VsaError_SaveCompiledStateFailed = -2146226123,
    VsaError_SaveElementFailed = -2146226122,
    VsaError_SiteAlreadySet = -2146226121,
    VsaError_SiteInvalid = -2146226120,
    VsaError_SiteNotSet = -2146226119,
    VsaError_SourceItemNotAvailable = -2146226118,
    VsaError_SourceMonikerNotAvailable = -2146226117,
    VsaError_URLInvalid = -2146226116,
    VsaError_UnknownError = -2146225921,
    VsaError_VsaServerDown = -2146226103
};

struct __declspec(uuid("37e0fbbb-865f-339d-acf9-fd66f9a2867e"))
VsaLoader;
    // [ default ] interface _VsaLoader
    // interface _Object
    // interface IVsaEngine

struct __declspec(uuid("7f64f934-c1cc-338e-b695-f64d71e820fe"))
VsaModule;
    // [ default ] interface _VsaModule
    // interface _Object

#pragma pack(pop)
