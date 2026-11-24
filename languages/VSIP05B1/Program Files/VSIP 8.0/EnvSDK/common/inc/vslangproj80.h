

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for vslangproj80.idl:
    Oicf, W0, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __vslangproj80_h__
#define __vslangproj80_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __ProjectConfigurationProperties3_FWD_DEFINED__
#define __ProjectConfigurationProperties3_FWD_DEFINED__
typedef interface ProjectConfigurationProperties3 ProjectConfigurationProperties3;
#endif 	/* __ProjectConfigurationProperties3_FWD_DEFINED__ */


#ifndef ___WebReferencesEvents__FWD_DEFINED__
#define ___WebReferencesEvents__FWD_DEFINED__
typedef interface _WebReferencesEvents_ _WebReferencesEvents_;
#endif 	/* ___WebReferencesEvents__FWD_DEFINED__ */


#ifndef ___dispWebReferencesEvents__FWD_DEFINED__
#define ___dispWebReferencesEvents__FWD_DEFINED__
typedef interface _dispWebReferencesEvents_ _dispWebReferencesEvents_;
#endif 	/* ___dispWebReferencesEvents__FWD_DEFINED__ */


#ifndef __WebReferencesEvents__FWD_DEFINED__
#define __WebReferencesEvents__FWD_DEFINED__

#ifdef __cplusplus
typedef class WebReferencesEvents_ WebReferencesEvents_;
#else
typedef struct WebReferencesEvents_ WebReferencesEvents_;
#endif /* __cplusplus */

#endif 	/* __WebReferencesEvents__FWD_DEFINED__ */


#ifndef __VSProjectEvents2_FWD_DEFINED__
#define __VSProjectEvents2_FWD_DEFINED__
typedef interface VSProjectEvents2 VSProjectEvents2;
#endif 	/* __VSProjectEvents2_FWD_DEFINED__ */


#ifndef __VSProject2_FWD_DEFINED__
#define __VSProject2_FWD_DEFINED__
typedef interface VSProject2 VSProject2;
#endif 	/* __VSProject2_FWD_DEFINED__ */


#ifndef __ProjectProperties3_FWD_DEFINED__
#define __ProjectProperties3_FWD_DEFINED__
typedef interface ProjectProperties3 ProjectProperties3;
#endif 	/* __ProjectProperties3_FWD_DEFINED__ */


#ifndef __VBProjectProperties3_FWD_DEFINED__
#define __VBProjectProperties3_FWD_DEFINED__
typedef interface VBProjectProperties3 VBProjectProperties3;
#endif 	/* __VBProjectProperties3_FWD_DEFINED__ */


#ifndef __CSharpProjectConfigurationProperties3_FWD_DEFINED__
#define __CSharpProjectConfigurationProperties3_FWD_DEFINED__
typedef interface CSharpProjectConfigurationProperties3 CSharpProjectConfigurationProperties3;
#endif 	/* __CSharpProjectConfigurationProperties3_FWD_DEFINED__ */


#ifndef __Reference3_FWD_DEFINED__
#define __Reference3_FWD_DEFINED__
typedef interface Reference3 Reference3;
#endif 	/* __Reference3_FWD_DEFINED__ */


#ifndef __JSharpProjectConfigurationProperties3_FWD_DEFINED__
#define __JSharpProjectConfigurationProperties3_FWD_DEFINED__
typedef interface JSharpProjectConfigurationProperties3 JSharpProjectConfigurationProperties3;
#endif 	/* __JSharpProjectConfigurationProperties3_FWD_DEFINED__ */


#ifndef __FolderProperties2_FWD_DEFINED__
#define __FolderProperties2_FWD_DEFINED__
typedef interface FolderProperties2 FolderProperties2;
#endif 	/* __FolderProperties2_FWD_DEFINED__ */


#ifndef __FileProperties2_FWD_DEFINED__
#define __FileProperties2_FWD_DEFINED__
typedef interface FileProperties2 FileProperties2;
#endif 	/* __FileProperties2_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

/* interface __MIDL_itf_vslangproj80_0000 */
/* [local] */ 


enum __MIDL___MIDL_itf_vslangproj80_0000_0001
    {	VBPROJPROPID_DebugInfo	= 10106,
	VBPROJPROPID_PlatformTarget	= 10109
    } ;

enum __MIDL___MIDL_itf_vslangproj80_0000_0002
    {	VBPROJPROPID_InstanceType	= 12100,
	VBPROJPROPID_ShutdownMode	= 12101,
	VBPROJPROPID_AssemblyTitle	= 12102,
	VBPROJPROPID_AssemblyDescription	= 12103,
	VBPROJPROPID_AssemblyCompany	= 12104,
	VBPROJPROPID_AssemblyProduct	= 12105,
	VBPROJPROPID_AssemblyCopyright	= 12106,
	VBPROJPROPID_AssemblyTrademark	= 12107,
	VBPROJPROPID_AssemblyType	= 12108,
	VBPROJPROPID_TypeComplianceDiagnostics	= 12109,
	VBPROJPROPID_CompatibilityChecks	= 12110,
	VBPROJPROPID_CompatibleAssembly	= 12111,
	VBPROJPROPID_Win32ResourceFile	= 12112,
	VBPROJPROPID_PermissionSet	= 12113,
	VBPROJPROPID_AssemblyOriginatorKeyFileType	= 12114,
	VBPROJPROPID_AssemblyKeyProviderName	= 12115,
	VBPROJPROPID_AssemblyVersion	= 12116,
	VBPROJPROPID_AssemblyFileVersion	= 12117,
	VBPROJPROPID_SecureDebugURL	= 12118,
	VBPROJPROPID_GenerateManifests	= 12119,
	VBPROJPROPID_EnableSecurityDebugging	= 12120,
	VBPROJPROPID_TreatSpecificWarningsAsErrors	= 12121,
	VBPROJPROPID_Publish	= 12122,
	VBPROJPROPID_ComVisible	= 12123,
	VBPROJPROPID_AssemblyGuid	= 12124,
	VBPROJPROPID_NeutralResourcesLanguage	= 12125,
	VBPROJPROPID_SignAssembly	= 12126,
	VBPROJPROPID_TargetZone	= 12127,
	VBPROJPROPID_ExcludedPermissions	= 12128
    } ;

enum __MIDL___MIDL_itf_vslangproj80_0000_0003
    {	DISPID_Reference_SpecificVersion	= 120,
	DISPID_Reference_SubType	= 121,
	DISPID_Reference_Isolated	= 122,
	DISPID_Reference_Aliases	= 123,
	DISPID_Reference_RefType	= 124
    } ;

enum __PROJECTREFERENCETYPE
    {	PROJREFTYPE_ASSEMBLY	= 1,
	PROJREFTYPE_ACTIVEX	= 2,
	PROJREFTYPE_NATIVE	= 3
    } ;
typedef DWORD PROJECTREFERENCETYPE;


enum __MIDL___MIDL_itf_vslangproj80_0000_0004
    {	DISPID_VBFile_CopyToOutputDirectory	= DISPID_VALUE + 100,
	DISPID_VBFile_ItemType	= DISPID_VALUE + 101
    } ;
#define CSharpProjectProperties3 ProjectProperties3
#define IID_CSharpProjectProperties3 IID_ProjectProperties3
#define VJSharpProjectProperties3 ProjectProperties3
#define IID_VJSharpProjectProperties3 IID_ProjectProperties3

enum __MIDL___MIDL_itf_vslangproj80_0000_0005
    {	CSPROJPROPID_TreatSpecificWarningsAsErrors	= 13102,
	CSPROJPROPID_LanguageVersion	= 13104,
	CSPROJPROPID_ErrorReport	= 13105
    } ;

enum __MIDL___MIDL_itf_vslangproj80_0000_0006
    {	VBPROJPROPID_MyApplication	= 14101,
	VBPROJPROPID_MyType	= 14102
    } ;

enum __MIDL___MIDL_itf_vslangproj80_0000_0007
    {	JSPROJPROPID_ResponseFile	= 15101,
	JSPROJPROPID_CodePage	= 15102,
	JSPROJPROPID_JCPA	= 15103,
	JSPROJPROPID_RecursePath	= 15104,
	JSPROJPROPID_UTF8Output	= 15105,
	JSPROJPROPID_DisableLangXtns	= 15106,
	JSPROJPROPID_SecureScoping	= 15107
    } ;

enum _prjOriginatorKeyFileType
    {	prjOriginatorKeyFileTypeSNK	= 1,
	prjOriginatorKeyFileTypePFX	= 2
    } ;
typedef DWORD prjOriginatorKeyFileType;

#define VSLANGPROJ80_VER_MAJ    8
#define VSLANGPROJ80_VER_MIN    0


extern RPC_IF_HANDLE __MIDL_itf_vslangproj80_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_vslangproj80_0000_v0_0_s_ifspec;


#ifndef __VSLangProj80_LIBRARY_DEFINED__
#define __VSLangProj80_LIBRARY_DEFINED__

/* library VSLangProj80 */
/* [version][helpstring][uuid] */ 


enum __MIDL___MIDL_itf_vslangproj80_0125_0001
    {	DISPID_VBFolder_WebReferenceInterface	= 11
    } ;

EXTERN_C const IID LIBID_VSLangProj80;

#ifndef __ProjectConfigurationProperties3_INTERFACE_DEFINED__
#define __ProjectConfigurationProperties3_INTERFACE_DEFINED__

/* interface ProjectConfigurationProperties3 */
/* [object][dual][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_ProjectConfigurationProperties3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9918DAB5-FC67-4cd4-B352-2F3FA1E2BD08")
    ProjectConfigurationProperties3 : public ProjectConfigurationProperties2
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_DebugInfo( 
            /* [retval][out] */ BSTR *pbstrDebugInfo) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_DebugInfo( 
            /* [in] */ BSTR bstrDebugInfo) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_PlatformTarget( 
            /* [retval][out] */ BSTR *pbstrPlatformTarget) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_PlatformTarget( 
            /* [in] */ BSTR bstrPlatformTarget) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_TreatSpecificWarningsAsErrors( 
            /* [retval][out] */ BSTR *pbstrWarningsAsErrors) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_TreatSpecificWarningsAsErrors( 
            /* [in] */ BSTR bstrWarningsAsErrors) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ProjectConfigurationProperties3Vtbl
    {
        BEGIN_INTERFACE
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ struct GUID *riid,
            /* [out][idldescattr] */ void **ppvObj,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *AddRef )( 
            ProjectConfigurationProperties3 * This,
            /* [retval][out] */ unsigned long *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Release )( 
            ProjectConfigurationProperties3 * This,
            /* [retval][out] */ unsigned long *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ProjectConfigurationProperties3 * This,
            /* [out][idldescattr] */ unsigned UINT *pctinfo,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ unsigned UINT itinfo,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [out][idldescattr] */ void **pptinfo,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ struct GUID *riid,
            /* [in][idldescattr] */ signed char **rgszNames,
            /* [in][idldescattr] */ unsigned UINT cNames,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [out][idldescattr] */ signed long *rgdispid,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ signed long dispidMember,
            /* [in][idldescattr] */ struct GUID *riid,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [in][idldescattr] */ unsigned short wFlags,
            /* [in][idldescattr] */ struct DISPPARAMS *pdispparams,
            /* [out][idldescattr] */ VARIANT *pvarResult,
            /* [out][idldescattr] */ struct EXCEPINFO *pexcepinfo,
            /* [out][idldescattr] */ unsigned UINT *puArgErr,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][hidden][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get___id )( 
            ProjectConfigurationProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_DebugSymbols )( 
            ProjectConfigurationProperties3 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_DebugSymbols )( 
            ProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_DefineDebug )( 
            ProjectConfigurationProperties3 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_DefineDebug )( 
            ProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_DefineTrace )( 
            ProjectConfigurationProperties3 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_DefineTrace )( 
            ProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_OutputPath )( 
            ProjectConfigurationProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_OutputPath )( 
            ProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_IntermediatePath )( 
            ProjectConfigurationProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][hidden][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_IntermediatePath )( 
            ProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_DefineConstants )( 
            ProjectConfigurationProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_DefineConstants )( 
            ProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_RemoveIntegerChecks )( 
            ProjectConfigurationProperties3 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_RemoveIntegerChecks )( 
            ProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_BaseAddress )( 
            ProjectConfigurationProperties3 * This,
            /* [retval][out] */ unsigned long *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_BaseAddress )( 
            ProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ unsigned long noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_AllowUnsafeBlocks )( 
            ProjectConfigurationProperties3 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_AllowUnsafeBlocks )( 
            ProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_CheckForOverflowUnderflow )( 
            ProjectConfigurationProperties3 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_CheckForOverflowUnderflow )( 
            ProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_DocumentationFile )( 
            ProjectConfigurationProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_DocumentationFile )( 
            ProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Optimize )( 
            ProjectConfigurationProperties3 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_Optimize )( 
            ProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_IncrementalBuild )( 
            ProjectConfigurationProperties3 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_IncrementalBuild )( 
            ProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_StartProgram )( 
            ProjectConfigurationProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_StartProgram )( 
            ProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_StartWorkingDirectory )( 
            ProjectConfigurationProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_StartWorkingDirectory )( 
            ProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_StartURL )( 
            ProjectConfigurationProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_StartURL )( 
            ProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_StartPage )( 
            ProjectConfigurationProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_StartPage )( 
            ProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_StartArguments )( 
            ProjectConfigurationProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_StartArguments )( 
            ProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_StartWithIE )( 
            ProjectConfigurationProperties3 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_StartWithIE )( 
            ProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_EnableASPDebugging )( 
            ProjectConfigurationProperties3 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_EnableASPDebugging )( 
            ProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_EnableASPXDebugging )( 
            ProjectConfigurationProperties3 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_EnableASPXDebugging )( 
            ProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_EnableUnmanagedDebugging )( 
            ProjectConfigurationProperties3 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_EnableUnmanagedDebugging )( 
            ProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_StartAction )( 
            ProjectConfigurationProperties3 * This,
            /* [retval][out] */ enum prjStartAction *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_StartAction )( 
            ProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ enum prjStartAction noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Extender )( 
            ProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BSTR ExtenderName,
            /* [retval][out] */ IDispatch **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ExtenderNames )( 
            ProjectConfigurationProperties3 * This,
            /* [retval][out] */ VARIANT *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ExtenderCATID )( 
            ProjectConfigurationProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_WarningLevel )( 
            ProjectConfigurationProperties3 * This,
            /* [retval][out] */ enum prjWarningLevel *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_WarningLevel )( 
            ProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ enum prjWarningLevel noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_TreatWarningsAsErrors )( 
            ProjectConfigurationProperties3 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_TreatWarningsAsErrors )( 
            ProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_EnableSQLServerDebugging )( 
            ProjectConfigurationProperties3 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_EnableSQLServerDebugging )( 
            ProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_FileAlignment )( 
            ProjectConfigurationProperties3 * This,
            /* [retval][out] */ unsigned long *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_FileAlignment )( 
            ProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ unsigned long noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_RegisterForComInterop )( 
            ProjectConfigurationProperties3 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_RegisterForComInterop )( 
            ProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ConfigurationOverrideFile )( 
            ProjectConfigurationProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_ConfigurationOverrideFile )( 
            ProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_RemoteDebugEnabled )( 
            ProjectConfigurationProperties3 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_RemoteDebugEnabled )( 
            ProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_RemoteDebugMachine )( 
            ProjectConfigurationProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_RemoteDebugMachine )( 
            ProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_NoWarn )( 
            ProjectConfigurationProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_NoWarn )( 
            ProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_NoStdLib )( 
            ProjectConfigurationProperties3 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_NoStdLib )( 
            ProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DebugInfo )( 
            ProjectConfigurationProperties3 * This,
            /* [retval][out] */ BSTR *pbstrDebugInfo);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DebugInfo )( 
            ProjectConfigurationProperties3 * This,
            /* [in] */ BSTR bstrDebugInfo);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PlatformTarget )( 
            ProjectConfigurationProperties3 * This,
            /* [retval][out] */ BSTR *pbstrPlatformTarget);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PlatformTarget )( 
            ProjectConfigurationProperties3 * This,
            /* [in] */ BSTR bstrPlatformTarget);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TreatSpecificWarningsAsErrors )( 
            ProjectConfigurationProperties3 * This,
            /* [retval][out] */ BSTR *pbstrWarningsAsErrors);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TreatSpecificWarningsAsErrors )( 
            ProjectConfigurationProperties3 * This,
            /* [in] */ BSTR bstrWarningsAsErrors);
        
        END_INTERFACE
    } ProjectConfigurationProperties3Vtbl;

    interface ProjectConfigurationProperties3
    {
        CONST_VTBL struct ProjectConfigurationProperties3Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ProjectConfigurationProperties3_QueryInterface(This,riid,ppvObj,retval)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObj,retval)

#define ProjectConfigurationProperties3_AddRef(This,retval)	\
    (This)->lpVtbl -> AddRef(This,retval)

#define ProjectConfigurationProperties3_Release(This,retval)	\
    (This)->lpVtbl -> Release(This,retval)

#define ProjectConfigurationProperties3_GetTypeInfoCount(This,pctinfo,retval)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo,retval)

#define ProjectConfigurationProperties3_GetTypeInfo(This,itinfo,lcid,pptinfo,retval)	\
    (This)->lpVtbl -> GetTypeInfo(This,itinfo,lcid,pptinfo,retval)

#define ProjectConfigurationProperties3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgdispid,retval)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgdispid,retval)

#define ProjectConfigurationProperties3_Invoke(This,dispidMember,riid,lcid,wFlags,pdispparams,pvarResult,pexcepinfo,puArgErr,retval)	\
    (This)->lpVtbl -> Invoke(This,dispidMember,riid,lcid,wFlags,pdispparams,pvarResult,pexcepinfo,puArgErr,retval)

#define ProjectConfigurationProperties3_get___id(This,retval)	\
    (This)->lpVtbl -> get___id(This,retval)

#define ProjectConfigurationProperties3_get_DebugSymbols(This,retval)	\
    (This)->lpVtbl -> get_DebugSymbols(This,retval)

#define ProjectConfigurationProperties3_put_DebugSymbols(This,noname,retval)	\
    (This)->lpVtbl -> put_DebugSymbols(This,noname,retval)

#define ProjectConfigurationProperties3_get_DefineDebug(This,retval)	\
    (This)->lpVtbl -> get_DefineDebug(This,retval)

#define ProjectConfigurationProperties3_put_DefineDebug(This,noname,retval)	\
    (This)->lpVtbl -> put_DefineDebug(This,noname,retval)

#define ProjectConfigurationProperties3_get_DefineTrace(This,retval)	\
    (This)->lpVtbl -> get_DefineTrace(This,retval)

#define ProjectConfigurationProperties3_put_DefineTrace(This,noname,retval)	\
    (This)->lpVtbl -> put_DefineTrace(This,noname,retval)

#define ProjectConfigurationProperties3_get_OutputPath(This,retval)	\
    (This)->lpVtbl -> get_OutputPath(This,retval)

#define ProjectConfigurationProperties3_put_OutputPath(This,noname,retval)	\
    (This)->lpVtbl -> put_OutputPath(This,noname,retval)

#define ProjectConfigurationProperties3_get_IntermediatePath(This,retval)	\
    (This)->lpVtbl -> get_IntermediatePath(This,retval)

#define ProjectConfigurationProperties3_put_IntermediatePath(This,noname,retval)	\
    (This)->lpVtbl -> put_IntermediatePath(This,noname,retval)

#define ProjectConfigurationProperties3_get_DefineConstants(This,retval)	\
    (This)->lpVtbl -> get_DefineConstants(This,retval)

#define ProjectConfigurationProperties3_put_DefineConstants(This,noname,retval)	\
    (This)->lpVtbl -> put_DefineConstants(This,noname,retval)

#define ProjectConfigurationProperties3_get_RemoveIntegerChecks(This,retval)	\
    (This)->lpVtbl -> get_RemoveIntegerChecks(This,retval)

#define ProjectConfigurationProperties3_put_RemoveIntegerChecks(This,noname,retval)	\
    (This)->lpVtbl -> put_RemoveIntegerChecks(This,noname,retval)

#define ProjectConfigurationProperties3_get_BaseAddress(This,retval)	\
    (This)->lpVtbl -> get_BaseAddress(This,retval)

#define ProjectConfigurationProperties3_put_BaseAddress(This,noname,retval)	\
    (This)->lpVtbl -> put_BaseAddress(This,noname,retval)

#define ProjectConfigurationProperties3_get_AllowUnsafeBlocks(This,retval)	\
    (This)->lpVtbl -> get_AllowUnsafeBlocks(This,retval)

#define ProjectConfigurationProperties3_put_AllowUnsafeBlocks(This,noname,retval)	\
    (This)->lpVtbl -> put_AllowUnsafeBlocks(This,noname,retval)

#define ProjectConfigurationProperties3_get_CheckForOverflowUnderflow(This,retval)	\
    (This)->lpVtbl -> get_CheckForOverflowUnderflow(This,retval)

#define ProjectConfigurationProperties3_put_CheckForOverflowUnderflow(This,noname,retval)	\
    (This)->lpVtbl -> put_CheckForOverflowUnderflow(This,noname,retval)

#define ProjectConfigurationProperties3_get_DocumentationFile(This,retval)	\
    (This)->lpVtbl -> get_DocumentationFile(This,retval)

#define ProjectConfigurationProperties3_put_DocumentationFile(This,noname,retval)	\
    (This)->lpVtbl -> put_DocumentationFile(This,noname,retval)

#define ProjectConfigurationProperties3_get_Optimize(This,retval)	\
    (This)->lpVtbl -> get_Optimize(This,retval)

#define ProjectConfigurationProperties3_put_Optimize(This,noname,retval)	\
    (This)->lpVtbl -> put_Optimize(This,noname,retval)

#define ProjectConfigurationProperties3_get_IncrementalBuild(This,retval)	\
    (This)->lpVtbl -> get_IncrementalBuild(This,retval)

#define ProjectConfigurationProperties3_put_IncrementalBuild(This,noname,retval)	\
    (This)->lpVtbl -> put_IncrementalBuild(This,noname,retval)

#define ProjectConfigurationProperties3_get_StartProgram(This,retval)	\
    (This)->lpVtbl -> get_StartProgram(This,retval)

#define ProjectConfigurationProperties3_put_StartProgram(This,noname,retval)	\
    (This)->lpVtbl -> put_StartProgram(This,noname,retval)

#define ProjectConfigurationProperties3_get_StartWorkingDirectory(This,retval)	\
    (This)->lpVtbl -> get_StartWorkingDirectory(This,retval)

#define ProjectConfigurationProperties3_put_StartWorkingDirectory(This,noname,retval)	\
    (This)->lpVtbl -> put_StartWorkingDirectory(This,noname,retval)

#define ProjectConfigurationProperties3_get_StartURL(This,retval)	\
    (This)->lpVtbl -> get_StartURL(This,retval)

#define ProjectConfigurationProperties3_put_StartURL(This,noname,retval)	\
    (This)->lpVtbl -> put_StartURL(This,noname,retval)

#define ProjectConfigurationProperties3_get_StartPage(This,retval)	\
    (This)->lpVtbl -> get_StartPage(This,retval)

#define ProjectConfigurationProperties3_put_StartPage(This,noname,retval)	\
    (This)->lpVtbl -> put_StartPage(This,noname,retval)

#define ProjectConfigurationProperties3_get_StartArguments(This,retval)	\
    (This)->lpVtbl -> get_StartArguments(This,retval)

#define ProjectConfigurationProperties3_put_StartArguments(This,noname,retval)	\
    (This)->lpVtbl -> put_StartArguments(This,noname,retval)

#define ProjectConfigurationProperties3_get_StartWithIE(This,retval)	\
    (This)->lpVtbl -> get_StartWithIE(This,retval)

#define ProjectConfigurationProperties3_put_StartWithIE(This,noname,retval)	\
    (This)->lpVtbl -> put_StartWithIE(This,noname,retval)

#define ProjectConfigurationProperties3_get_EnableASPDebugging(This,retval)	\
    (This)->lpVtbl -> get_EnableASPDebugging(This,retval)

#define ProjectConfigurationProperties3_put_EnableASPDebugging(This,noname,retval)	\
    (This)->lpVtbl -> put_EnableASPDebugging(This,noname,retval)

#define ProjectConfigurationProperties3_get_EnableASPXDebugging(This,retval)	\
    (This)->lpVtbl -> get_EnableASPXDebugging(This,retval)

#define ProjectConfigurationProperties3_put_EnableASPXDebugging(This,noname,retval)	\
    (This)->lpVtbl -> put_EnableASPXDebugging(This,noname,retval)

#define ProjectConfigurationProperties3_get_EnableUnmanagedDebugging(This,retval)	\
    (This)->lpVtbl -> get_EnableUnmanagedDebugging(This,retval)

#define ProjectConfigurationProperties3_put_EnableUnmanagedDebugging(This,noname,retval)	\
    (This)->lpVtbl -> put_EnableUnmanagedDebugging(This,noname,retval)

#define ProjectConfigurationProperties3_get_StartAction(This,retval)	\
    (This)->lpVtbl -> get_StartAction(This,retval)

#define ProjectConfigurationProperties3_put_StartAction(This,noname,retval)	\
    (This)->lpVtbl -> put_StartAction(This,noname,retval)

#define ProjectConfigurationProperties3_get_Extender(This,ExtenderName,retval)	\
    (This)->lpVtbl -> get_Extender(This,ExtenderName,retval)

#define ProjectConfigurationProperties3_get_ExtenderNames(This,retval)	\
    (This)->lpVtbl -> get_ExtenderNames(This,retval)

#define ProjectConfigurationProperties3_get_ExtenderCATID(This,retval)	\
    (This)->lpVtbl -> get_ExtenderCATID(This,retval)

#define ProjectConfigurationProperties3_get_WarningLevel(This,retval)	\
    (This)->lpVtbl -> get_WarningLevel(This,retval)

#define ProjectConfigurationProperties3_put_WarningLevel(This,noname,retval)	\
    (This)->lpVtbl -> put_WarningLevel(This,noname,retval)

#define ProjectConfigurationProperties3_get_TreatWarningsAsErrors(This,retval)	\
    (This)->lpVtbl -> get_TreatWarningsAsErrors(This,retval)

#define ProjectConfigurationProperties3_put_TreatWarningsAsErrors(This,noname,retval)	\
    (This)->lpVtbl -> put_TreatWarningsAsErrors(This,noname,retval)

#define ProjectConfigurationProperties3_get_EnableSQLServerDebugging(This,retval)	\
    (This)->lpVtbl -> get_EnableSQLServerDebugging(This,retval)

#define ProjectConfigurationProperties3_put_EnableSQLServerDebugging(This,noname,retval)	\
    (This)->lpVtbl -> put_EnableSQLServerDebugging(This,noname,retval)

#define ProjectConfigurationProperties3_get_FileAlignment(This,retval)	\
    (This)->lpVtbl -> get_FileAlignment(This,retval)

#define ProjectConfigurationProperties3_put_FileAlignment(This,noname,retval)	\
    (This)->lpVtbl -> put_FileAlignment(This,noname,retval)

#define ProjectConfigurationProperties3_get_RegisterForComInterop(This,retval)	\
    (This)->lpVtbl -> get_RegisterForComInterop(This,retval)

#define ProjectConfigurationProperties3_put_RegisterForComInterop(This,noname,retval)	\
    (This)->lpVtbl -> put_RegisterForComInterop(This,noname,retval)

#define ProjectConfigurationProperties3_get_ConfigurationOverrideFile(This,retval)	\
    (This)->lpVtbl -> get_ConfigurationOverrideFile(This,retval)

#define ProjectConfigurationProperties3_put_ConfigurationOverrideFile(This,noname,retval)	\
    (This)->lpVtbl -> put_ConfigurationOverrideFile(This,noname,retval)

#define ProjectConfigurationProperties3_get_RemoteDebugEnabled(This,retval)	\
    (This)->lpVtbl -> get_RemoteDebugEnabled(This,retval)

#define ProjectConfigurationProperties3_put_RemoteDebugEnabled(This,noname,retval)	\
    (This)->lpVtbl -> put_RemoteDebugEnabled(This,noname,retval)

#define ProjectConfigurationProperties3_get_RemoteDebugMachine(This,retval)	\
    (This)->lpVtbl -> get_RemoteDebugMachine(This,retval)

#define ProjectConfigurationProperties3_put_RemoteDebugMachine(This,noname,retval)	\
    (This)->lpVtbl -> put_RemoteDebugMachine(This,noname,retval)

#define ProjectConfigurationProperties3_get_NoWarn(This,retval)	\
    (This)->lpVtbl -> get_NoWarn(This,retval)

#define ProjectConfigurationProperties3_put_NoWarn(This,noname,retval)	\
    (This)->lpVtbl -> put_NoWarn(This,noname,retval)

#define ProjectConfigurationProperties3_get_NoStdLib(This,retval)	\
    (This)->lpVtbl -> get_NoStdLib(This,retval)

#define ProjectConfigurationProperties3_put_NoStdLib(This,noname,retval)	\
    (This)->lpVtbl -> put_NoStdLib(This,noname,retval)


#define ProjectConfigurationProperties3_get_DebugInfo(This,pbstrDebugInfo)	\
    (This)->lpVtbl -> get_DebugInfo(This,pbstrDebugInfo)

#define ProjectConfigurationProperties3_put_DebugInfo(This,bstrDebugInfo)	\
    (This)->lpVtbl -> put_DebugInfo(This,bstrDebugInfo)

#define ProjectConfigurationProperties3_get_PlatformTarget(This,pbstrPlatformTarget)	\
    (This)->lpVtbl -> get_PlatformTarget(This,pbstrPlatformTarget)

#define ProjectConfigurationProperties3_put_PlatformTarget(This,bstrPlatformTarget)	\
    (This)->lpVtbl -> put_PlatformTarget(This,bstrPlatformTarget)

#define ProjectConfigurationProperties3_get_TreatSpecificWarningsAsErrors(This,pbstrWarningsAsErrors)	\
    (This)->lpVtbl -> get_TreatSpecificWarningsAsErrors(This,pbstrWarningsAsErrors)

#define ProjectConfigurationProperties3_put_TreatSpecificWarningsAsErrors(This,bstrWarningsAsErrors)	\
    (This)->lpVtbl -> put_TreatSpecificWarningsAsErrors(This,bstrWarningsAsErrors)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id][propget] */ HRESULT STDMETHODCALLTYPE ProjectConfigurationProperties3_get_DebugInfo_Proxy( 
    ProjectConfigurationProperties3 * This,
    /* [retval][out] */ BSTR *pbstrDebugInfo);


void __RPC_STUB ProjectConfigurationProperties3_get_DebugInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE ProjectConfigurationProperties3_put_DebugInfo_Proxy( 
    ProjectConfigurationProperties3 * This,
    /* [in] */ BSTR bstrDebugInfo);


void __RPC_STUB ProjectConfigurationProperties3_put_DebugInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE ProjectConfigurationProperties3_get_PlatformTarget_Proxy( 
    ProjectConfigurationProperties3 * This,
    /* [retval][out] */ BSTR *pbstrPlatformTarget);


void __RPC_STUB ProjectConfigurationProperties3_get_PlatformTarget_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE ProjectConfigurationProperties3_put_PlatformTarget_Proxy( 
    ProjectConfigurationProperties3 * This,
    /* [in] */ BSTR bstrPlatformTarget);


void __RPC_STUB ProjectConfigurationProperties3_put_PlatformTarget_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE ProjectConfigurationProperties3_get_TreatSpecificWarningsAsErrors_Proxy( 
    ProjectConfigurationProperties3 * This,
    /* [retval][out] */ BSTR *pbstrWarningsAsErrors);


void __RPC_STUB ProjectConfigurationProperties3_get_TreatSpecificWarningsAsErrors_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE ProjectConfigurationProperties3_put_TreatSpecificWarningsAsErrors_Proxy( 
    ProjectConfigurationProperties3 * This,
    /* [in] */ BSTR bstrWarningsAsErrors);


void __RPC_STUB ProjectConfigurationProperties3_put_TreatSpecificWarningsAsErrors_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ProjectConfigurationProperties3_INTERFACE_DEFINED__ */


#ifndef ___WebReferencesEvents__INTERFACE_DEFINED__
#define ___WebReferencesEvents__INTERFACE_DEFINED__

/* interface _WebReferencesEvents_ */
/* [object][dual][uuid] */ 


EXTERN_C const IID IID__WebReferencesEvents_;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("33BD7FEF-EEB4-412a-A4C1-9FBFF6F57067")
    _WebReferencesEvents_ : public IDispatch
    {
    public:
    };
    
#else 	/* C style interface */

    typedef struct _WebReferencesEvents_Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _WebReferencesEvents_ * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _WebReferencesEvents_ * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _WebReferencesEvents_ * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _WebReferencesEvents_ * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _WebReferencesEvents_ * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _WebReferencesEvents_ * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _WebReferencesEvents_ * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _WebReferencesEvents_Vtbl;

    interface _WebReferencesEvents_
    {
        CONST_VTBL struct _WebReferencesEvents_Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _WebReferencesEvents__QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _WebReferencesEvents__AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _WebReferencesEvents__Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _WebReferencesEvents__GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _WebReferencesEvents__GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _WebReferencesEvents__GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _WebReferencesEvents__Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#endif /* COBJMACROS */


#endif 	/* C style interface */




#endif 	/* ___WebReferencesEvents__INTERFACE_DEFINED__ */


#ifndef ___dispWebReferencesEvents__DISPINTERFACE_DEFINED__
#define ___dispWebReferencesEvents__DISPINTERFACE_DEFINED__

/* dispinterface _dispWebReferencesEvents_ */
/* [uuid] */ 


EXTERN_C const IID DIID__dispWebReferencesEvents_;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("9AAD53A9-32CB-4d84-97A7-B4AFA94F5878")
    _dispWebReferencesEvents_ : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _dispWebReferencesEvents_Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _dispWebReferencesEvents_ * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _dispWebReferencesEvents_ * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _dispWebReferencesEvents_ * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _dispWebReferencesEvents_ * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _dispWebReferencesEvents_ * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _dispWebReferencesEvents_ * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _dispWebReferencesEvents_ * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        END_INTERFACE
    } _dispWebReferencesEvents_Vtbl;

    interface _dispWebReferencesEvents_
    {
        CONST_VTBL struct _dispWebReferencesEvents_Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _dispWebReferencesEvents__QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _dispWebReferencesEvents__AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _dispWebReferencesEvents__Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _dispWebReferencesEvents__GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _dispWebReferencesEvents__GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _dispWebReferencesEvents__GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _dispWebReferencesEvents__Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___dispWebReferencesEvents__DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_WebReferencesEvents_;

#ifdef __cplusplus

class DECLSPEC_UUID("2DF4B0DE-579D-46b2-9D6E-88AF01E08FB0")
WebReferencesEvents_;
#endif

#ifndef __VSProjectEvents2_INTERFACE_DEFINED__
#define __VSProjectEvents2_INTERFACE_DEFINED__

/* interface VSProjectEvents2 */
/* [uuid][object][oleautomation][dual] */ 


EXTERN_C const IID IID_VSProjectEvents2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("6DCBC5A7-37BF-461c-958F-A81DA10D242E")
    VSProjectEvents2 : public VSProjectEvents
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_WebReferencesEvents_( 
            /* [retval][out] */ WebReferencesEvents_	**ppWebReferenceEvents_) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct VSProjectEvents2Vtbl
    {
        BEGIN_INTERFACE
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            VSProjectEvents2 * This,
            /* [in][idldescattr] */ struct GUID *riid,
            /* [out][idldescattr] */ void **ppvObj,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *AddRef )( 
            VSProjectEvents2 * This,
            /* [retval][out] */ unsigned long *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Release )( 
            VSProjectEvents2 * This,
            /* [retval][out] */ unsigned long *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            VSProjectEvents2 * This,
            /* [out][idldescattr] */ unsigned UINT *pctinfo,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            VSProjectEvents2 * This,
            /* [in][idldescattr] */ unsigned UINT itinfo,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [out][idldescattr] */ void **pptinfo,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            VSProjectEvents2 * This,
            /* [in][idldescattr] */ struct GUID *riid,
            /* [in][idldescattr] */ signed char **rgszNames,
            /* [in][idldescattr] */ unsigned UINT cNames,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [out][idldescattr] */ signed long *rgdispid,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            VSProjectEvents2 * This,
            /* [in][idldescattr] */ signed long dispidMember,
            /* [in][idldescattr] */ struct GUID *riid,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [in][idldescattr] */ unsigned short wFlags,
            /* [in][idldescattr] */ struct DISPPARAMS *pdispparams,
            /* [out][idldescattr] */ VARIANT *pvarResult,
            /* [out][idldescattr] */ struct EXCEPINFO *pexcepinfo,
            /* [out][idldescattr] */ unsigned UINT *puArgErr,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ReferencesEvents )( 
            VSProjectEvents2 * This,
            /* [retval][out] */ **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_BuildManagerEvents )( 
            VSProjectEvents2 * This,
            /* [retval][out] */ **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ImportsEvents )( 
            VSProjectEvents2 * This,
            /* [retval][out] */ **retval);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_WebReferencesEvents_ )( 
            VSProjectEvents2 * This,
            /* [retval][out] */ WebReferencesEvents_	**ppWebReferenceEvents_);
        
        END_INTERFACE
    } VSProjectEvents2Vtbl;

    interface VSProjectEvents2
    {
        CONST_VTBL struct VSProjectEvents2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define VSProjectEvents2_QueryInterface(This,riid,ppvObj,retval)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObj,retval)

#define VSProjectEvents2_AddRef(This,retval)	\
    (This)->lpVtbl -> AddRef(This,retval)

#define VSProjectEvents2_Release(This,retval)	\
    (This)->lpVtbl -> Release(This,retval)

#define VSProjectEvents2_GetTypeInfoCount(This,pctinfo,retval)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo,retval)

#define VSProjectEvents2_GetTypeInfo(This,itinfo,lcid,pptinfo,retval)	\
    (This)->lpVtbl -> GetTypeInfo(This,itinfo,lcid,pptinfo,retval)

#define VSProjectEvents2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgdispid,retval)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgdispid,retval)

#define VSProjectEvents2_Invoke(This,dispidMember,riid,lcid,wFlags,pdispparams,pvarResult,pexcepinfo,puArgErr,retval)	\
    (This)->lpVtbl -> Invoke(This,dispidMember,riid,lcid,wFlags,pdispparams,pvarResult,pexcepinfo,puArgErr,retval)

#define VSProjectEvents2_get_ReferencesEvents(This,retval)	\
    (This)->lpVtbl -> get_ReferencesEvents(This,retval)

#define VSProjectEvents2_get_BuildManagerEvents(This,retval)	\
    (This)->lpVtbl -> get_BuildManagerEvents(This,retval)

#define VSProjectEvents2_get_ImportsEvents(This,retval)	\
    (This)->lpVtbl -> get_ImportsEvents(This,retval)


#define VSProjectEvents2_get_WebReferencesEvents_(This,ppWebReferenceEvents_)	\
    (This)->lpVtbl -> get_WebReferencesEvents_(This,ppWebReferenceEvents_)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE VSProjectEvents2_get_WebReferencesEvents__Proxy( 
    VSProjectEvents2 * This,
    /* [retval][out] */ WebReferencesEvents_	**ppWebReferenceEvents_);


void __RPC_STUB VSProjectEvents2_get_WebReferencesEvents__Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __VSProjectEvents2_INTERFACE_DEFINED__ */


#ifndef __VSProject2_INTERFACE_DEFINED__
#define __VSProject2_INTERFACE_DEFINED__

/* interface VSProject2 */
/* [uuid][object][oleautomation][dual] */ 


EXTERN_C const IID IID_VSProject2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B1042570-25C6-424a-B58B-56FA83AA828A")
    VSProject2 : public VSProject
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_PublishManager( 
            /* [retval][out] */ IDispatch **ppPublishManager) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Events2( 
            /* [retval][out] */ VSProjectEvents2 **ppEvents) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct VSProject2Vtbl
    {
        BEGIN_INTERFACE
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            VSProject2 * This,
            /* [in][idldescattr] */ struct GUID *riid,
            /* [out][idldescattr] */ void **ppvObj,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *AddRef )( 
            VSProject2 * This,
            /* [retval][out] */ unsigned long *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Release )( 
            VSProject2 * This,
            /* [retval][out] */ unsigned long *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            VSProject2 * This,
            /* [out][idldescattr] */ unsigned UINT *pctinfo,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            VSProject2 * This,
            /* [in][idldescattr] */ unsigned UINT itinfo,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [out][idldescattr] */ void **pptinfo,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            VSProject2 * This,
            /* [in][idldescattr] */ struct GUID *riid,
            /* [in][idldescattr] */ signed char **rgszNames,
            /* [in][idldescattr] */ unsigned UINT cNames,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [out][idldescattr] */ signed long *rgdispid,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            VSProject2 * This,
            /* [in][idldescattr] */ signed long dispidMember,
            /* [in][idldescattr] */ struct GUID *riid,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [in][idldescattr] */ unsigned short wFlags,
            /* [in][idldescattr] */ struct DISPPARAMS *pdispparams,
            /* [out][idldescattr] */ VARIANT *pvarResult,
            /* [out][idldescattr] */ struct EXCEPINFO *pexcepinfo,
            /* [out][idldescattr] */ unsigned UINT *puArgErr,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_References )( 
            VSProject2 * This,
            /* [retval][out] */ References **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_BuildManager )( 
            VSProject2 * This,
            /* [retval][out] */ BuildManager **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_DTE )( 
            VSProject2 * This,
            /* [retval][out] */ **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Project )( 
            VSProject2 * This,
            /* [retval][out] */ Project **retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *CreateWebReferencesFolder )( 
            VSProject2 * This,
            /* [retval][out] */ ProjectItem **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_WebReferencesFolder )( 
            VSProject2 * This,
            /* [retval][out] */ ProjectItem **retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *AddWebReference )( 
            VSProject2 * This,
            /* [in][idldescattr] */ BSTR bstrUrl,
            /* [retval][out] */ ProjectItem **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_TemplatePath )( 
            VSProject2 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Refresh )( 
            VSProject2 * This,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_WorkOffline )( 
            VSProject2 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_WorkOffline )( 
            VSProject2 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Imports )( 
            VSProject2 * This,
            /* [retval][out] */ Imports **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Events )( 
            VSProject2 * This,
            /* [retval][out] */ VSProjectEvents **retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *CopyProject )( 
            VSProject2 * This,
            /* [in][idldescattr] */ BSTR bstrDestFolder,
            /* [in][idldescattr] */ BSTR bstrDestUNCPath,
            /* [in][idldescattr] */ enum prjCopyProjectOption copyProjectOption,
            /* [in][idldescattr] */ BSTR bstrUsername,
            /* [in][idldescattr] */ BSTR bstrPassword,
            /* [retval][out] */ void *retval);
        
        /* [id][hidden][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Exec )( 
            VSProject2 * This,
            /* [in][idldescattr] */ enum prjExecCommand command,
            /* [idldescattr] */ signed long bSuppressUI,
            /* [in][idldescattr] */ VARIANT varIn,
            /* [out][idldescattr] */ VARIANT *pVarOut,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GenerateKeyPairFiles )( 
            VSProject2 * This,
            /* [in][idldescattr] */ BSTR strPublicPrivateFile,
            /* [in][idldescattr] */ BSTR strPublicOnlyFile,
            /* [retval][out] */ void *retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetUniqueFilename )( 
            VSProject2 * This,
            /* [in][idldescattr] */ IDispatch *pDispatch,
            /* [in][idldescattr] */ BSTR bstrRoot,
            /* [in][idldescattr] */ BSTR bstrDesiredExt,
            /* [retval][out] */ BSTR *retval);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_PublishManager )( 
            VSProject2 * This,
            /* [retval][out] */ IDispatch **ppPublishManager);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Events2 )( 
            VSProject2 * This,
            /* [retval][out] */ VSProjectEvents2 **ppEvents);
        
        END_INTERFACE
    } VSProject2Vtbl;

    interface VSProject2
    {
        CONST_VTBL struct VSProject2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define VSProject2_QueryInterface(This,riid,ppvObj,retval)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObj,retval)

#define VSProject2_AddRef(This,retval)	\
    (This)->lpVtbl -> AddRef(This,retval)

#define VSProject2_Release(This,retval)	\
    (This)->lpVtbl -> Release(This,retval)

#define VSProject2_GetTypeInfoCount(This,pctinfo,retval)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo,retval)

#define VSProject2_GetTypeInfo(This,itinfo,lcid,pptinfo,retval)	\
    (This)->lpVtbl -> GetTypeInfo(This,itinfo,lcid,pptinfo,retval)

#define VSProject2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgdispid,retval)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgdispid,retval)

#define VSProject2_Invoke(This,dispidMember,riid,lcid,wFlags,pdispparams,pvarResult,pexcepinfo,puArgErr,retval)	\
    (This)->lpVtbl -> Invoke(This,dispidMember,riid,lcid,wFlags,pdispparams,pvarResult,pexcepinfo,puArgErr,retval)

#define VSProject2_get_References(This,retval)	\
    (This)->lpVtbl -> get_References(This,retval)

#define VSProject2_get_BuildManager(This,retval)	\
    (This)->lpVtbl -> get_BuildManager(This,retval)

#define VSProject2_get_DTE(This,retval)	\
    (This)->lpVtbl -> get_DTE(This,retval)

#define VSProject2_get_Project(This,retval)	\
    (This)->lpVtbl -> get_Project(This,retval)

#define VSProject2_CreateWebReferencesFolder(This,retval)	\
    (This)->lpVtbl -> CreateWebReferencesFolder(This,retval)

#define VSProject2_get_WebReferencesFolder(This,retval)	\
    (This)->lpVtbl -> get_WebReferencesFolder(This,retval)

#define VSProject2_AddWebReference(This,bstrUrl,retval)	\
    (This)->lpVtbl -> AddWebReference(This,bstrUrl,retval)

#define VSProject2_get_TemplatePath(This,retval)	\
    (This)->lpVtbl -> get_TemplatePath(This,retval)

#define VSProject2_Refresh(This,retval)	\
    (This)->lpVtbl -> Refresh(This,retval)

#define VSProject2_get_WorkOffline(This,retval)	\
    (This)->lpVtbl -> get_WorkOffline(This,retval)

#define VSProject2_put_WorkOffline(This,noname,retval)	\
    (This)->lpVtbl -> put_WorkOffline(This,noname,retval)

#define VSProject2_get_Imports(This,retval)	\
    (This)->lpVtbl -> get_Imports(This,retval)

#define VSProject2_get_Events(This,retval)	\
    (This)->lpVtbl -> get_Events(This,retval)

#define VSProject2_CopyProject(This,bstrDestFolder,bstrDestUNCPath,copyProjectOption,bstrUsername,bstrPassword,retval)	\
    (This)->lpVtbl -> CopyProject(This,bstrDestFolder,bstrDestUNCPath,copyProjectOption,bstrUsername,bstrPassword,retval)

#define VSProject2_Exec(This,command,bSuppressUI,varIn,pVarOut,retval)	\
    (This)->lpVtbl -> Exec(This,command,bSuppressUI,varIn,pVarOut,retval)

#define VSProject2_GenerateKeyPairFiles(This,strPublicPrivateFile,strPublicOnlyFile,retval)	\
    (This)->lpVtbl -> GenerateKeyPairFiles(This,strPublicPrivateFile,strPublicOnlyFile,retval)

#define VSProject2_GetUniqueFilename(This,pDispatch,bstrRoot,bstrDesiredExt,retval)	\
    (This)->lpVtbl -> GetUniqueFilename(This,pDispatch,bstrRoot,bstrDesiredExt,retval)


#define VSProject2_get_PublishManager(This,ppPublishManager)	\
    (This)->lpVtbl -> get_PublishManager(This,ppPublishManager)

#define VSProject2_get_Events2(This,ppEvents)	\
    (This)->lpVtbl -> get_Events2(This,ppEvents)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE VSProject2_get_PublishManager_Proxy( 
    VSProject2 * This,
    /* [retval][out] */ IDispatch **ppPublishManager);


void __RPC_STUB VSProject2_get_PublishManager_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE VSProject2_get_Events2_Proxy( 
    VSProject2 * This,
    /* [retval][out] */ VSProjectEvents2 **ppEvents);


void __RPC_STUB VSProject2_get_Events2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __VSProject2_INTERFACE_DEFINED__ */


#ifndef __ProjectProperties3_INTERFACE_DEFINED__
#define __ProjectProperties3_INTERFACE_DEFINED__

/* interface ProjectProperties3 */
/* [object][dual][unique][helpstring][uuid] */ 

typedef /* [uuid] */  DECLSPEC_UUID("355354DE-E2F0-45d5-9632-4823655C9C95") 
enum prjAssemblyType
    {	prjAssemblyType_Library	= 0,
	prjAssemblyType_Platform	= prjAssemblyType_Library + 1
    } 	prjAssemblyType;

#define prjAssemblyTypeMin  prjAssemblyType_Library
#define prjAssemblyTypeMax  prjAssemblyType_Platform

EXTERN_C const IID IID_ProjectProperties3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("7C9D1773-F1F3-447c-AF1A-218E5E2C2F7F")
    ProjectProperties3 : public ProjectProperties2
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Title( 
            /* [retval][out] */ BSTR *pbstrTitle) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Title( 
            /* [in] */ BSTR bstrTitle) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Description( 
            /* [retval][out] */ BSTR *pbstrDescription) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Description( 
            /* [in] */ BSTR bstrDescription) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Company( 
            /* [retval][out] */ BSTR *pbstrCompany) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Company( 
            /* [in] */ BSTR bstrCompany) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Product( 
            /* [retval][out] */ BSTR *pbstrProduct) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Product( 
            /* [in] */ BSTR bstrProduct) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Copyright( 
            /* [retval][out] */ BSTR *pbstrCopyright) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Copyright( 
            /* [in] */ BSTR bstrCopyright) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Trademark( 
            /* [retval][out] */ BSTR *pbstrTrademark) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Trademark( 
            /* [in] */ BSTR bstrTrademark) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_AssemblyType( 
            /* [retval][out] */ prjAssemblyType *pAssemblyType) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_AssemblyType( 
            /* [in] */ prjAssemblyType AssemblyType) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_TypeComplianceDiagnostics( 
            /* [retval][out] */ VARIANT_BOOL *pbTypeComplianceDiagnostics) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_TypeComplianceDiagnostics( 
            /* [in] */ VARIANT_BOOL bTypeComplianceDiagnostics) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_Win32ResourceFile( 
            /* [retval][out] */ BSTR *pbstrW32ResourceFile) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_Win32ResourceFile( 
            /* [in] */ BSTR bstrWin32ResourceFile) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_PermissionSet( 
            /* [retval][out] */ IUnknown **ppunk) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_PermissionSet( 
            /* [in] */ IUnknown *punk) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AssemblyKeyProviderName( 
            /* [retval][out] */ BSTR *pbstrKeyProviderName) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AssemblyKeyProviderName( 
            /* [in] */ BSTR bstrKeyProviderName) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AssemblyOriginatorKeyFileType( 
            /* [retval][out] */ DWORD *pdwOriginatorKeyFileType) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AssemblyOriginatorKeyFileType( 
            /* [in] */ DWORD dwOriginatorKeyFileType) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AssemblyVersion( 
            /* [retval][out] */ BSTR *pbstrAssemblyVersion) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AssemblyVersion( 
            /* [in] */ BSTR bstrAssemblyVersion) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AssemblyFileVersion( 
            /* [retval][out] */ BSTR *pbstrAssemblyVersion) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AssemblyFileVersion( 
            /* [in] */ BSTR bstrAssemblyVersion) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_GenerateManifests( 
            /* [retval][out] */ VARIANT_BOOL *pbGenerateManifests) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_GenerateManifests( 
            /* [in] */ VARIANT_BOOL bGenerateManifests) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_EnableSecurityDebugging( 
            /* [retval][out] */ VARIANT_BOOL *pbEnableSecurityDebugging) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_EnableSecurityDebugging( 
            /* [in] */ VARIANT_BOOL bEnableSecurityDebugging) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_DebugSecurityZoneURL( 
            /* [retval][out] */ BSTR *pbstrSecurityURL) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_DebugSecurityZoneURL( 
            /* [in] */ BSTR bstrSecurityURL) = 0;
        
        virtual /* [helpstring][id][nonbrowsable][propget] */ HRESULT STDMETHODCALLTYPE get_Publish( 
            /* [retval][out] */ IDispatch **ppdispPublish) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ComVisible( 
            /* [retval][out] */ VARIANT_BOOL *pbComVisible) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ComVisible( 
            /* [in] */ VARIANT_BOOL bComVisible) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_AssemblyGuid( 
            /* [retval][out] */ BSTR *pbstrAssemblyGuid) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_AssemblyGuid( 
            /* [in] */ BSTR bstrAssemblyGuid) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_NeutralResourcesLanguage( 
            /* [retval][out] */ BSTR *pbstrNeutralResourcesLanguage) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_NeutralResourcesLanguage( 
            /* [in] */ BSTR bstrNeutralResourcesLanguage) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SignAssembly( 
            /* [retval][out] */ VARIANT_BOOL *pbSignAssembly) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SignAssembly( 
            /* [in] */ VARIANT_BOOL bSignAssembly) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_TargetZone( 
            /* [retval][out] */ BSTR *pbstrTargetZone) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_TargetZone( 
            /* [in] */ BSTR bstrTargetZone) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ExcludedPermissions( 
            /* [retval][out] */ BSTR *pbstrExcludedPermissions) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ExcludedPermissions( 
            /* [in] */ BSTR bstrExcludedPermissions) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ProjectProperties3Vtbl
    {
        BEGIN_INTERFACE
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            ProjectProperties3 * This,
            /* [in][idldescattr] */ struct GUID *riid,
            /* [out][idldescattr] */ void **ppvObj,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *AddRef )( 
            ProjectProperties3 * This,
            /* [retval][out] */ unsigned long *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Release )( 
            ProjectProperties3 * This,
            /* [retval][out] */ unsigned long *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            ProjectProperties3 * This,
            /* [out][idldescattr] */ unsigned UINT *pctinfo,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            ProjectProperties3 * This,
            /* [in][idldescattr] */ unsigned UINT itinfo,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [out][idldescattr] */ void **pptinfo,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            ProjectProperties3 * This,
            /* [in][idldescattr] */ struct GUID *riid,
            /* [in][idldescattr] */ signed char **rgszNames,
            /* [in][idldescattr] */ unsigned UINT cNames,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [out][idldescattr] */ signed long *rgdispid,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            ProjectProperties3 * This,
            /* [in][idldescattr] */ signed long dispidMember,
            /* [in][idldescattr] */ struct GUID *riid,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [in][idldescattr] */ unsigned short wFlags,
            /* [in][idldescattr] */ struct DISPPARAMS *pdispparams,
            /* [out][idldescattr] */ VARIANT *pvarResult,
            /* [out][idldescattr] */ struct EXCEPINFO *pexcepinfo,
            /* [out][idldescattr] */ unsigned UINT *puArgErr,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][hidden][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get___id )( 
            ProjectProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][hidden][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get___project )( 
            ProjectProperties3 * This,
            /* [retval][out] */ IUnknown **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_StartupObject )( 
            ProjectProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_StartupObject )( 
            ProjectProperties3 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_OutputType )( 
            ProjectProperties3 * This,
            /* [retval][out] */ enum prjOutputType *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_OutputType )( 
            ProjectProperties3 * This,
            /* [in][idldescattr] */ enum prjOutputType noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_RootNamespace )( 
            ProjectProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_RootNamespace )( 
            ProjectProperties3 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_AssemblyName )( 
            ProjectProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_AssemblyName )( 
            ProjectProperties3 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_AssemblyOriginatorKeyFile )( 
            ProjectProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_AssemblyOriginatorKeyFile )( 
            ProjectProperties3 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_AssemblyKeyContainerName )( 
            ProjectProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_AssemblyKeyContainerName )( 
            ProjectProperties3 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_AssemblyOriginatorKeyMode )( 
            ProjectProperties3 * This,
            /* [retval][out] */ enum prjOriginatorKeyMode *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_AssemblyOriginatorKeyMode )( 
            ProjectProperties3 * This,
            /* [in][idldescattr] */ enum prjOriginatorKeyMode noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_DelaySign )( 
            ProjectProperties3 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_DelaySign )( 
            ProjectProperties3 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_WebServer )( 
            ProjectProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_WebServerVersion )( 
            ProjectProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ServerExtensionsVersion )( 
            ProjectProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_LinkRepair )( 
            ProjectProperties3 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_LinkRepair )( 
            ProjectProperties3 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_OfflineURL )( 
            ProjectProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_FileSharePath )( 
            ProjectProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_FileSharePath )( 
            ProjectProperties3 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveFileSharePath )( 
            ProjectProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_WebAccessMethod )( 
            ProjectProperties3 * This,
            /* [retval][out] */ enum prjWebAccessMethod *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_WebAccessMethod )( 
            ProjectProperties3 * This,
            /* [in][idldescattr] */ enum prjWebAccessMethod noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveWebAccessMethod )( 
            ProjectProperties3 * This,
            /* [retval][out] */ enum prjWebAccessMethod *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultClientScript )( 
            ProjectProperties3 * This,
            /* [retval][out] */ enum prjScriptLanguage *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultClientScript )( 
            ProjectProperties3 * This,
            /* [in][idldescattr] */ enum prjScriptLanguage noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultTargetSchema )( 
            ProjectProperties3 * This,
            /* [retval][out] */ enum prjTargetSchema *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultTargetSchema )( 
            ProjectProperties3 * This,
            /* [in][idldescattr] */ enum prjTargetSchema noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultHTMLPageLayout )( 
            ProjectProperties3 * This,
            /* [retval][out] */ enum prjHTMLPageLayout *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultHTMLPageLayout )( 
            ProjectProperties3 * This,
            /* [in][idldescattr] */ enum prjHTMLPageLayout noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_FileName )( 
            ProjectProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_FileName )( 
            ProjectProperties3 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_FullPath )( 
            ProjectProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_LocalPath )( 
            ProjectProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_URL )( 
            ProjectProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveConfigurationSettings )( 
            ProjectProperties3 * This,
            /* [retval][out] */ ProjectConfigurationProperties **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Extender )( 
            ProjectProperties3 * This,
            /* [in][idldescattr] */ BSTR ExtenderName,
            /* [retval][out] */ IDispatch **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ExtenderNames )( 
            ProjectProperties3 * This,
            /* [retval][out] */ VARIANT *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ExtenderCATID )( 
            ProjectProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ApplicationIcon )( 
            ProjectProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_ApplicationIcon )( 
            ProjectProperties3 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_OptionStrict )( 
            ProjectProperties3 * This,
            /* [retval][out] */ enum prjOptionStrict *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_OptionStrict )( 
            ProjectProperties3 * This,
            /* [in][idldescattr] */ enum prjOptionStrict noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ReferencePath )( 
            ProjectProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_ReferencePath )( 
            ProjectProperties3 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_OutputFileName )( 
            ProjectProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][hidden][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_AbsoluteProjectDirectory )( 
            ProjectProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_OptionExplicit )( 
            ProjectProperties3 * This,
            /* [retval][out] */ enum prjOptionExplicit *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_OptionExplicit )( 
            ProjectProperties3 * This,
            /* [in][idldescattr] */ enum prjOptionExplicit noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_OptionCompare )( 
            ProjectProperties3 * This,
            /* [retval][out] */ enum prjCompare *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_OptionCompare )( 
            ProjectProperties3 * This,
            /* [in][idldescattr] */ enum prjCompare noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ProjectType )( 
            ProjectProperties3 * This,
            /* [retval][out] */ enum prjProjectType *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultNamespace )( 
            ProjectProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultNamespace )( 
            ProjectProperties3 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_PreBuildEvent )( 
            ProjectProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_PreBuildEvent )( 
            ProjectProperties3 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_PostBuildEvent )( 
            ProjectProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_PostBuildEvent )( 
            ProjectProperties3 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_RunPostBuildEvent )( 
            ProjectProperties3 * This,
            /* [retval][out] */ enum prjRunPostBuildEvent *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_RunPostBuildEvent )( 
            ProjectProperties3 * This,
            /* [in][idldescattr] */ enum prjRunPostBuildEvent noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_AspnetVersion )( 
            ProjectProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Title )( 
            ProjectProperties3 * This,
            /* [retval][out] */ BSTR *pbstrTitle);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Title )( 
            ProjectProperties3 * This,
            /* [in] */ BSTR bstrTitle);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Description )( 
            ProjectProperties3 * This,
            /* [retval][out] */ BSTR *pbstrDescription);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Description )( 
            ProjectProperties3 * This,
            /* [in] */ BSTR bstrDescription);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Company )( 
            ProjectProperties3 * This,
            /* [retval][out] */ BSTR *pbstrCompany);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Company )( 
            ProjectProperties3 * This,
            /* [in] */ BSTR bstrCompany);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Product )( 
            ProjectProperties3 * This,
            /* [retval][out] */ BSTR *pbstrProduct);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Product )( 
            ProjectProperties3 * This,
            /* [in] */ BSTR bstrProduct);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Copyright )( 
            ProjectProperties3 * This,
            /* [retval][out] */ BSTR *pbstrCopyright);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Copyright )( 
            ProjectProperties3 * This,
            /* [in] */ BSTR bstrCopyright);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Trademark )( 
            ProjectProperties3 * This,
            /* [retval][out] */ BSTR *pbstrTrademark);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Trademark )( 
            ProjectProperties3 * This,
            /* [in] */ BSTR bstrTrademark);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AssemblyType )( 
            ProjectProperties3 * This,
            /* [retval][out] */ prjAssemblyType *pAssemblyType);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AssemblyType )( 
            ProjectProperties3 * This,
            /* [in] */ prjAssemblyType AssemblyType);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TypeComplianceDiagnostics )( 
            ProjectProperties3 * This,
            /* [retval][out] */ VARIANT_BOOL *pbTypeComplianceDiagnostics);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TypeComplianceDiagnostics )( 
            ProjectProperties3 * This,
            /* [in] */ VARIANT_BOOL bTypeComplianceDiagnostics);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Win32ResourceFile )( 
            ProjectProperties3 * This,
            /* [retval][out] */ BSTR *pbstrW32ResourceFile);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Win32ResourceFile )( 
            ProjectProperties3 * This,
            /* [in] */ BSTR bstrWin32ResourceFile);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PermissionSet )( 
            ProjectProperties3 * This,
            /* [retval][out] */ IUnknown **ppunk);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PermissionSet )( 
            ProjectProperties3 * This,
            /* [in] */ IUnknown *punk);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AssemblyKeyProviderName )( 
            ProjectProperties3 * This,
            /* [retval][out] */ BSTR *pbstrKeyProviderName);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AssemblyKeyProviderName )( 
            ProjectProperties3 * This,
            /* [in] */ BSTR bstrKeyProviderName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AssemblyOriginatorKeyFileType )( 
            ProjectProperties3 * This,
            /* [retval][out] */ DWORD *pdwOriginatorKeyFileType);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AssemblyOriginatorKeyFileType )( 
            ProjectProperties3 * This,
            /* [in] */ DWORD dwOriginatorKeyFileType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AssemblyVersion )( 
            ProjectProperties3 * This,
            /* [retval][out] */ BSTR *pbstrAssemblyVersion);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AssemblyVersion )( 
            ProjectProperties3 * This,
            /* [in] */ BSTR bstrAssemblyVersion);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AssemblyFileVersion )( 
            ProjectProperties3 * This,
            /* [retval][out] */ BSTR *pbstrAssemblyVersion);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AssemblyFileVersion )( 
            ProjectProperties3 * This,
            /* [in] */ BSTR bstrAssemblyVersion);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_GenerateManifests )( 
            ProjectProperties3 * This,
            /* [retval][out] */ VARIANT_BOOL *pbGenerateManifests);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_GenerateManifests )( 
            ProjectProperties3 * This,
            /* [in] */ VARIANT_BOOL bGenerateManifests);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableSecurityDebugging )( 
            ProjectProperties3 * This,
            /* [retval][out] */ VARIANT_BOOL *pbEnableSecurityDebugging);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableSecurityDebugging )( 
            ProjectProperties3 * This,
            /* [in] */ VARIANT_BOOL bEnableSecurityDebugging);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DebugSecurityZoneURL )( 
            ProjectProperties3 * This,
            /* [retval][out] */ BSTR *pbstrSecurityURL);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DebugSecurityZoneURL )( 
            ProjectProperties3 * This,
            /* [in] */ BSTR bstrSecurityURL);
        
        /* [helpstring][id][nonbrowsable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Publish )( 
            ProjectProperties3 * This,
            /* [retval][out] */ IDispatch **ppdispPublish);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ComVisible )( 
            ProjectProperties3 * This,
            /* [retval][out] */ VARIANT_BOOL *pbComVisible);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ComVisible )( 
            ProjectProperties3 * This,
            /* [in] */ VARIANT_BOOL bComVisible);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AssemblyGuid )( 
            ProjectProperties3 * This,
            /* [retval][out] */ BSTR *pbstrAssemblyGuid);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AssemblyGuid )( 
            ProjectProperties3 * This,
            /* [in] */ BSTR bstrAssemblyGuid);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NeutralResourcesLanguage )( 
            ProjectProperties3 * This,
            /* [retval][out] */ BSTR *pbstrNeutralResourcesLanguage);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_NeutralResourcesLanguage )( 
            ProjectProperties3 * This,
            /* [in] */ BSTR bstrNeutralResourcesLanguage);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SignAssembly )( 
            ProjectProperties3 * This,
            /* [retval][out] */ VARIANT_BOOL *pbSignAssembly);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SignAssembly )( 
            ProjectProperties3 * This,
            /* [in] */ VARIANT_BOOL bSignAssembly);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TargetZone )( 
            ProjectProperties3 * This,
            /* [retval][out] */ BSTR *pbstrTargetZone);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TargetZone )( 
            ProjectProperties3 * This,
            /* [in] */ BSTR bstrTargetZone);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ExcludedPermissions )( 
            ProjectProperties3 * This,
            /* [retval][out] */ BSTR *pbstrExcludedPermissions);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ExcludedPermissions )( 
            ProjectProperties3 * This,
            /* [in] */ BSTR bstrExcludedPermissions);
        
        END_INTERFACE
    } ProjectProperties3Vtbl;

    interface ProjectProperties3
    {
        CONST_VTBL struct ProjectProperties3Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ProjectProperties3_QueryInterface(This,riid,ppvObj,retval)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObj,retval)

#define ProjectProperties3_AddRef(This,retval)	\
    (This)->lpVtbl -> AddRef(This,retval)

#define ProjectProperties3_Release(This,retval)	\
    (This)->lpVtbl -> Release(This,retval)

#define ProjectProperties3_GetTypeInfoCount(This,pctinfo,retval)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo,retval)

#define ProjectProperties3_GetTypeInfo(This,itinfo,lcid,pptinfo,retval)	\
    (This)->lpVtbl -> GetTypeInfo(This,itinfo,lcid,pptinfo,retval)

#define ProjectProperties3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgdispid,retval)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgdispid,retval)

#define ProjectProperties3_Invoke(This,dispidMember,riid,lcid,wFlags,pdispparams,pvarResult,pexcepinfo,puArgErr,retval)	\
    (This)->lpVtbl -> Invoke(This,dispidMember,riid,lcid,wFlags,pdispparams,pvarResult,pexcepinfo,puArgErr,retval)

#define ProjectProperties3_get___id(This,retval)	\
    (This)->lpVtbl -> get___id(This,retval)

#define ProjectProperties3_get___project(This,retval)	\
    (This)->lpVtbl -> get___project(This,retval)

#define ProjectProperties3_get_StartupObject(This,retval)	\
    (This)->lpVtbl -> get_StartupObject(This,retval)

#define ProjectProperties3_put_StartupObject(This,noname,retval)	\
    (This)->lpVtbl -> put_StartupObject(This,noname,retval)

#define ProjectProperties3_get_OutputType(This,retval)	\
    (This)->lpVtbl -> get_OutputType(This,retval)

#define ProjectProperties3_put_OutputType(This,noname,retval)	\
    (This)->lpVtbl -> put_OutputType(This,noname,retval)

#define ProjectProperties3_get_RootNamespace(This,retval)	\
    (This)->lpVtbl -> get_RootNamespace(This,retval)

#define ProjectProperties3_put_RootNamespace(This,noname,retval)	\
    (This)->lpVtbl -> put_RootNamespace(This,noname,retval)

#define ProjectProperties3_get_AssemblyName(This,retval)	\
    (This)->lpVtbl -> get_AssemblyName(This,retval)

#define ProjectProperties3_put_AssemblyName(This,noname,retval)	\
    (This)->lpVtbl -> put_AssemblyName(This,noname,retval)

#define ProjectProperties3_get_AssemblyOriginatorKeyFile(This,retval)	\
    (This)->lpVtbl -> get_AssemblyOriginatorKeyFile(This,retval)

#define ProjectProperties3_put_AssemblyOriginatorKeyFile(This,noname,retval)	\
    (This)->lpVtbl -> put_AssemblyOriginatorKeyFile(This,noname,retval)

#define ProjectProperties3_get_AssemblyKeyContainerName(This,retval)	\
    (This)->lpVtbl -> get_AssemblyKeyContainerName(This,retval)

#define ProjectProperties3_put_AssemblyKeyContainerName(This,noname,retval)	\
    (This)->lpVtbl -> put_AssemblyKeyContainerName(This,noname,retval)

#define ProjectProperties3_get_AssemblyOriginatorKeyMode(This,retval)	\
    (This)->lpVtbl -> get_AssemblyOriginatorKeyMode(This,retval)

#define ProjectProperties3_put_AssemblyOriginatorKeyMode(This,noname,retval)	\
    (This)->lpVtbl -> put_AssemblyOriginatorKeyMode(This,noname,retval)

#define ProjectProperties3_get_DelaySign(This,retval)	\
    (This)->lpVtbl -> get_DelaySign(This,retval)

#define ProjectProperties3_put_DelaySign(This,noname,retval)	\
    (This)->lpVtbl -> put_DelaySign(This,noname,retval)

#define ProjectProperties3_get_WebServer(This,retval)	\
    (This)->lpVtbl -> get_WebServer(This,retval)

#define ProjectProperties3_get_WebServerVersion(This,retval)	\
    (This)->lpVtbl -> get_WebServerVersion(This,retval)

#define ProjectProperties3_get_ServerExtensionsVersion(This,retval)	\
    (This)->lpVtbl -> get_ServerExtensionsVersion(This,retval)

#define ProjectProperties3_get_LinkRepair(This,retval)	\
    (This)->lpVtbl -> get_LinkRepair(This,retval)

#define ProjectProperties3_put_LinkRepair(This,noname,retval)	\
    (This)->lpVtbl -> put_LinkRepair(This,noname,retval)

#define ProjectProperties3_get_OfflineURL(This,retval)	\
    (This)->lpVtbl -> get_OfflineURL(This,retval)

#define ProjectProperties3_get_FileSharePath(This,retval)	\
    (This)->lpVtbl -> get_FileSharePath(This,retval)

#define ProjectProperties3_put_FileSharePath(This,noname,retval)	\
    (This)->lpVtbl -> put_FileSharePath(This,noname,retval)

#define ProjectProperties3_get_ActiveFileSharePath(This,retval)	\
    (This)->lpVtbl -> get_ActiveFileSharePath(This,retval)

#define ProjectProperties3_get_WebAccessMethod(This,retval)	\
    (This)->lpVtbl -> get_WebAccessMethod(This,retval)

#define ProjectProperties3_put_WebAccessMethod(This,noname,retval)	\
    (This)->lpVtbl -> put_WebAccessMethod(This,noname,retval)

#define ProjectProperties3_get_ActiveWebAccessMethod(This,retval)	\
    (This)->lpVtbl -> get_ActiveWebAccessMethod(This,retval)

#define ProjectProperties3_get_DefaultClientScript(This,retval)	\
    (This)->lpVtbl -> get_DefaultClientScript(This,retval)

#define ProjectProperties3_put_DefaultClientScript(This,noname,retval)	\
    (This)->lpVtbl -> put_DefaultClientScript(This,noname,retval)

#define ProjectProperties3_get_DefaultTargetSchema(This,retval)	\
    (This)->lpVtbl -> get_DefaultTargetSchema(This,retval)

#define ProjectProperties3_put_DefaultTargetSchema(This,noname,retval)	\
    (This)->lpVtbl -> put_DefaultTargetSchema(This,noname,retval)

#define ProjectProperties3_get_DefaultHTMLPageLayout(This,retval)	\
    (This)->lpVtbl -> get_DefaultHTMLPageLayout(This,retval)

#define ProjectProperties3_put_DefaultHTMLPageLayout(This,noname,retval)	\
    (This)->lpVtbl -> put_DefaultHTMLPageLayout(This,noname,retval)

#define ProjectProperties3_get_FileName(This,retval)	\
    (This)->lpVtbl -> get_FileName(This,retval)

#define ProjectProperties3_put_FileName(This,noname,retval)	\
    (This)->lpVtbl -> put_FileName(This,noname,retval)

#define ProjectProperties3_get_FullPath(This,retval)	\
    (This)->lpVtbl -> get_FullPath(This,retval)

#define ProjectProperties3_get_LocalPath(This,retval)	\
    (This)->lpVtbl -> get_LocalPath(This,retval)

#define ProjectProperties3_get_URL(This,retval)	\
    (This)->lpVtbl -> get_URL(This,retval)

#define ProjectProperties3_get_ActiveConfigurationSettings(This,retval)	\
    (This)->lpVtbl -> get_ActiveConfigurationSettings(This,retval)

#define ProjectProperties3_get_Extender(This,ExtenderName,retval)	\
    (This)->lpVtbl -> get_Extender(This,ExtenderName,retval)

#define ProjectProperties3_get_ExtenderNames(This,retval)	\
    (This)->lpVtbl -> get_ExtenderNames(This,retval)

#define ProjectProperties3_get_ExtenderCATID(This,retval)	\
    (This)->lpVtbl -> get_ExtenderCATID(This,retval)

#define ProjectProperties3_get_ApplicationIcon(This,retval)	\
    (This)->lpVtbl -> get_ApplicationIcon(This,retval)

#define ProjectProperties3_put_ApplicationIcon(This,noname,retval)	\
    (This)->lpVtbl -> put_ApplicationIcon(This,noname,retval)

#define ProjectProperties3_get_OptionStrict(This,retval)	\
    (This)->lpVtbl -> get_OptionStrict(This,retval)

#define ProjectProperties3_put_OptionStrict(This,noname,retval)	\
    (This)->lpVtbl -> put_OptionStrict(This,noname,retval)

#define ProjectProperties3_get_ReferencePath(This,retval)	\
    (This)->lpVtbl -> get_ReferencePath(This,retval)

#define ProjectProperties3_put_ReferencePath(This,noname,retval)	\
    (This)->lpVtbl -> put_ReferencePath(This,noname,retval)

#define ProjectProperties3_get_OutputFileName(This,retval)	\
    (This)->lpVtbl -> get_OutputFileName(This,retval)

#define ProjectProperties3_get_AbsoluteProjectDirectory(This,retval)	\
    (This)->lpVtbl -> get_AbsoluteProjectDirectory(This,retval)

#define ProjectProperties3_get_OptionExplicit(This,retval)	\
    (This)->lpVtbl -> get_OptionExplicit(This,retval)

#define ProjectProperties3_put_OptionExplicit(This,noname,retval)	\
    (This)->lpVtbl -> put_OptionExplicit(This,noname,retval)

#define ProjectProperties3_get_OptionCompare(This,retval)	\
    (This)->lpVtbl -> get_OptionCompare(This,retval)

#define ProjectProperties3_put_OptionCompare(This,noname,retval)	\
    (This)->lpVtbl -> put_OptionCompare(This,noname,retval)

#define ProjectProperties3_get_ProjectType(This,retval)	\
    (This)->lpVtbl -> get_ProjectType(This,retval)

#define ProjectProperties3_get_DefaultNamespace(This,retval)	\
    (This)->lpVtbl -> get_DefaultNamespace(This,retval)

#define ProjectProperties3_put_DefaultNamespace(This,noname,retval)	\
    (This)->lpVtbl -> put_DefaultNamespace(This,noname,retval)

#define ProjectProperties3_get_PreBuildEvent(This,retval)	\
    (This)->lpVtbl -> get_PreBuildEvent(This,retval)

#define ProjectProperties3_put_PreBuildEvent(This,noname,retval)	\
    (This)->lpVtbl -> put_PreBuildEvent(This,noname,retval)

#define ProjectProperties3_get_PostBuildEvent(This,retval)	\
    (This)->lpVtbl -> get_PostBuildEvent(This,retval)

#define ProjectProperties3_put_PostBuildEvent(This,noname,retval)	\
    (This)->lpVtbl -> put_PostBuildEvent(This,noname,retval)

#define ProjectProperties3_get_RunPostBuildEvent(This,retval)	\
    (This)->lpVtbl -> get_RunPostBuildEvent(This,retval)

#define ProjectProperties3_put_RunPostBuildEvent(This,noname,retval)	\
    (This)->lpVtbl -> put_RunPostBuildEvent(This,noname,retval)

#define ProjectProperties3_get_AspnetVersion(This,retval)	\
    (This)->lpVtbl -> get_AspnetVersion(This,retval)


#define ProjectProperties3_get_Title(This,pbstrTitle)	\
    (This)->lpVtbl -> get_Title(This,pbstrTitle)

#define ProjectProperties3_put_Title(This,bstrTitle)	\
    (This)->lpVtbl -> put_Title(This,bstrTitle)

#define ProjectProperties3_get_Description(This,pbstrDescription)	\
    (This)->lpVtbl -> get_Description(This,pbstrDescription)

#define ProjectProperties3_put_Description(This,bstrDescription)	\
    (This)->lpVtbl -> put_Description(This,bstrDescription)

#define ProjectProperties3_get_Company(This,pbstrCompany)	\
    (This)->lpVtbl -> get_Company(This,pbstrCompany)

#define ProjectProperties3_put_Company(This,bstrCompany)	\
    (This)->lpVtbl -> put_Company(This,bstrCompany)

#define ProjectProperties3_get_Product(This,pbstrProduct)	\
    (This)->lpVtbl -> get_Product(This,pbstrProduct)

#define ProjectProperties3_put_Product(This,bstrProduct)	\
    (This)->lpVtbl -> put_Product(This,bstrProduct)

#define ProjectProperties3_get_Copyright(This,pbstrCopyright)	\
    (This)->lpVtbl -> get_Copyright(This,pbstrCopyright)

#define ProjectProperties3_put_Copyright(This,bstrCopyright)	\
    (This)->lpVtbl -> put_Copyright(This,bstrCopyright)

#define ProjectProperties3_get_Trademark(This,pbstrTrademark)	\
    (This)->lpVtbl -> get_Trademark(This,pbstrTrademark)

#define ProjectProperties3_put_Trademark(This,bstrTrademark)	\
    (This)->lpVtbl -> put_Trademark(This,bstrTrademark)

#define ProjectProperties3_get_AssemblyType(This,pAssemblyType)	\
    (This)->lpVtbl -> get_AssemblyType(This,pAssemblyType)

#define ProjectProperties3_put_AssemblyType(This,AssemblyType)	\
    (This)->lpVtbl -> put_AssemblyType(This,AssemblyType)

#define ProjectProperties3_get_TypeComplianceDiagnostics(This,pbTypeComplianceDiagnostics)	\
    (This)->lpVtbl -> get_TypeComplianceDiagnostics(This,pbTypeComplianceDiagnostics)

#define ProjectProperties3_put_TypeComplianceDiagnostics(This,bTypeComplianceDiagnostics)	\
    (This)->lpVtbl -> put_TypeComplianceDiagnostics(This,bTypeComplianceDiagnostics)

#define ProjectProperties3_get_Win32ResourceFile(This,pbstrW32ResourceFile)	\
    (This)->lpVtbl -> get_Win32ResourceFile(This,pbstrW32ResourceFile)

#define ProjectProperties3_put_Win32ResourceFile(This,bstrWin32ResourceFile)	\
    (This)->lpVtbl -> put_Win32ResourceFile(This,bstrWin32ResourceFile)

#define ProjectProperties3_get_PermissionSet(This,ppunk)	\
    (This)->lpVtbl -> get_PermissionSet(This,ppunk)

#define ProjectProperties3_put_PermissionSet(This,punk)	\
    (This)->lpVtbl -> put_PermissionSet(This,punk)

#define ProjectProperties3_get_AssemblyKeyProviderName(This,pbstrKeyProviderName)	\
    (This)->lpVtbl -> get_AssemblyKeyProviderName(This,pbstrKeyProviderName)

#define ProjectProperties3_put_AssemblyKeyProviderName(This,bstrKeyProviderName)	\
    (This)->lpVtbl -> put_AssemblyKeyProviderName(This,bstrKeyProviderName)

#define ProjectProperties3_get_AssemblyOriginatorKeyFileType(This,pdwOriginatorKeyFileType)	\
    (This)->lpVtbl -> get_AssemblyOriginatorKeyFileType(This,pdwOriginatorKeyFileType)

#define ProjectProperties3_put_AssemblyOriginatorKeyFileType(This,dwOriginatorKeyFileType)	\
    (This)->lpVtbl -> put_AssemblyOriginatorKeyFileType(This,dwOriginatorKeyFileType)

#define ProjectProperties3_get_AssemblyVersion(This,pbstrAssemblyVersion)	\
    (This)->lpVtbl -> get_AssemblyVersion(This,pbstrAssemblyVersion)

#define ProjectProperties3_put_AssemblyVersion(This,bstrAssemblyVersion)	\
    (This)->lpVtbl -> put_AssemblyVersion(This,bstrAssemblyVersion)

#define ProjectProperties3_get_AssemblyFileVersion(This,pbstrAssemblyVersion)	\
    (This)->lpVtbl -> get_AssemblyFileVersion(This,pbstrAssemblyVersion)

#define ProjectProperties3_put_AssemblyFileVersion(This,bstrAssemblyVersion)	\
    (This)->lpVtbl -> put_AssemblyFileVersion(This,bstrAssemblyVersion)

#define ProjectProperties3_get_GenerateManifests(This,pbGenerateManifests)	\
    (This)->lpVtbl -> get_GenerateManifests(This,pbGenerateManifests)

#define ProjectProperties3_put_GenerateManifests(This,bGenerateManifests)	\
    (This)->lpVtbl -> put_GenerateManifests(This,bGenerateManifests)

#define ProjectProperties3_get_EnableSecurityDebugging(This,pbEnableSecurityDebugging)	\
    (This)->lpVtbl -> get_EnableSecurityDebugging(This,pbEnableSecurityDebugging)

#define ProjectProperties3_put_EnableSecurityDebugging(This,bEnableSecurityDebugging)	\
    (This)->lpVtbl -> put_EnableSecurityDebugging(This,bEnableSecurityDebugging)

#define ProjectProperties3_get_DebugSecurityZoneURL(This,pbstrSecurityURL)	\
    (This)->lpVtbl -> get_DebugSecurityZoneURL(This,pbstrSecurityURL)

#define ProjectProperties3_put_DebugSecurityZoneURL(This,bstrSecurityURL)	\
    (This)->lpVtbl -> put_DebugSecurityZoneURL(This,bstrSecurityURL)

#define ProjectProperties3_get_Publish(This,ppdispPublish)	\
    (This)->lpVtbl -> get_Publish(This,ppdispPublish)

#define ProjectProperties3_get_ComVisible(This,pbComVisible)	\
    (This)->lpVtbl -> get_ComVisible(This,pbComVisible)

#define ProjectProperties3_put_ComVisible(This,bComVisible)	\
    (This)->lpVtbl -> put_ComVisible(This,bComVisible)

#define ProjectProperties3_get_AssemblyGuid(This,pbstrAssemblyGuid)	\
    (This)->lpVtbl -> get_AssemblyGuid(This,pbstrAssemblyGuid)

#define ProjectProperties3_put_AssemblyGuid(This,bstrAssemblyGuid)	\
    (This)->lpVtbl -> put_AssemblyGuid(This,bstrAssemblyGuid)

#define ProjectProperties3_get_NeutralResourcesLanguage(This,pbstrNeutralResourcesLanguage)	\
    (This)->lpVtbl -> get_NeutralResourcesLanguage(This,pbstrNeutralResourcesLanguage)

#define ProjectProperties3_put_NeutralResourcesLanguage(This,bstrNeutralResourcesLanguage)	\
    (This)->lpVtbl -> put_NeutralResourcesLanguage(This,bstrNeutralResourcesLanguage)

#define ProjectProperties3_get_SignAssembly(This,pbSignAssembly)	\
    (This)->lpVtbl -> get_SignAssembly(This,pbSignAssembly)

#define ProjectProperties3_put_SignAssembly(This,bSignAssembly)	\
    (This)->lpVtbl -> put_SignAssembly(This,bSignAssembly)

#define ProjectProperties3_get_TargetZone(This,pbstrTargetZone)	\
    (This)->lpVtbl -> get_TargetZone(This,pbstrTargetZone)

#define ProjectProperties3_put_TargetZone(This,bstrTargetZone)	\
    (This)->lpVtbl -> put_TargetZone(This,bstrTargetZone)

#define ProjectProperties3_get_ExcludedPermissions(This,pbstrExcludedPermissions)	\
    (This)->lpVtbl -> get_ExcludedPermissions(This,pbstrExcludedPermissions)

#define ProjectProperties3_put_ExcludedPermissions(This,bstrExcludedPermissions)	\
    (This)->lpVtbl -> put_ExcludedPermissions(This,bstrExcludedPermissions)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id][propget] */ HRESULT STDMETHODCALLTYPE ProjectProperties3_get_Title_Proxy( 
    ProjectProperties3 * This,
    /* [retval][out] */ BSTR *pbstrTitle);


void __RPC_STUB ProjectProperties3_get_Title_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE ProjectProperties3_put_Title_Proxy( 
    ProjectProperties3 * This,
    /* [in] */ BSTR bstrTitle);


void __RPC_STUB ProjectProperties3_put_Title_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE ProjectProperties3_get_Description_Proxy( 
    ProjectProperties3 * This,
    /* [retval][out] */ BSTR *pbstrDescription);


void __RPC_STUB ProjectProperties3_get_Description_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE ProjectProperties3_put_Description_Proxy( 
    ProjectProperties3 * This,
    /* [in] */ BSTR bstrDescription);


void __RPC_STUB ProjectProperties3_put_Description_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE ProjectProperties3_get_Company_Proxy( 
    ProjectProperties3 * This,
    /* [retval][out] */ BSTR *pbstrCompany);


void __RPC_STUB ProjectProperties3_get_Company_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE ProjectProperties3_put_Company_Proxy( 
    ProjectProperties3 * This,
    /* [in] */ BSTR bstrCompany);


void __RPC_STUB ProjectProperties3_put_Company_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE ProjectProperties3_get_Product_Proxy( 
    ProjectProperties3 * This,
    /* [retval][out] */ BSTR *pbstrProduct);


void __RPC_STUB ProjectProperties3_get_Product_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE ProjectProperties3_put_Product_Proxy( 
    ProjectProperties3 * This,
    /* [in] */ BSTR bstrProduct);


void __RPC_STUB ProjectProperties3_put_Product_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE ProjectProperties3_get_Copyright_Proxy( 
    ProjectProperties3 * This,
    /* [retval][out] */ BSTR *pbstrCopyright);


void __RPC_STUB ProjectProperties3_get_Copyright_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE ProjectProperties3_put_Copyright_Proxy( 
    ProjectProperties3 * This,
    /* [in] */ BSTR bstrCopyright);


void __RPC_STUB ProjectProperties3_put_Copyright_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE ProjectProperties3_get_Trademark_Proxy( 
    ProjectProperties3 * This,
    /* [retval][out] */ BSTR *pbstrTrademark);


void __RPC_STUB ProjectProperties3_get_Trademark_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE ProjectProperties3_put_Trademark_Proxy( 
    ProjectProperties3 * This,
    /* [in] */ BSTR bstrTrademark);


void __RPC_STUB ProjectProperties3_put_Trademark_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE ProjectProperties3_get_AssemblyType_Proxy( 
    ProjectProperties3 * This,
    /* [retval][out] */ prjAssemblyType *pAssemblyType);


void __RPC_STUB ProjectProperties3_get_AssemblyType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE ProjectProperties3_put_AssemblyType_Proxy( 
    ProjectProperties3 * This,
    /* [in] */ prjAssemblyType AssemblyType);


void __RPC_STUB ProjectProperties3_put_AssemblyType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE ProjectProperties3_get_TypeComplianceDiagnostics_Proxy( 
    ProjectProperties3 * This,
    /* [retval][out] */ VARIANT_BOOL *pbTypeComplianceDiagnostics);


void __RPC_STUB ProjectProperties3_get_TypeComplianceDiagnostics_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE ProjectProperties3_put_TypeComplianceDiagnostics_Proxy( 
    ProjectProperties3 * This,
    /* [in] */ VARIANT_BOOL bTypeComplianceDiagnostics);


void __RPC_STUB ProjectProperties3_put_TypeComplianceDiagnostics_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE ProjectProperties3_get_Win32ResourceFile_Proxy( 
    ProjectProperties3 * This,
    /* [retval][out] */ BSTR *pbstrW32ResourceFile);


void __RPC_STUB ProjectProperties3_get_Win32ResourceFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE ProjectProperties3_put_Win32ResourceFile_Proxy( 
    ProjectProperties3 * This,
    /* [in] */ BSTR bstrWin32ResourceFile);


void __RPC_STUB ProjectProperties3_put_Win32ResourceFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE ProjectProperties3_get_PermissionSet_Proxy( 
    ProjectProperties3 * This,
    /* [retval][out] */ IUnknown **ppunk);


void __RPC_STUB ProjectProperties3_get_PermissionSet_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE ProjectProperties3_put_PermissionSet_Proxy( 
    ProjectProperties3 * This,
    /* [in] */ IUnknown *punk);


void __RPC_STUB ProjectProperties3_put_PermissionSet_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ProjectProperties3_get_AssemblyKeyProviderName_Proxy( 
    ProjectProperties3 * This,
    /* [retval][out] */ BSTR *pbstrKeyProviderName);


void __RPC_STUB ProjectProperties3_get_AssemblyKeyProviderName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ProjectProperties3_put_AssemblyKeyProviderName_Proxy( 
    ProjectProperties3 * This,
    /* [in] */ BSTR bstrKeyProviderName);


void __RPC_STUB ProjectProperties3_put_AssemblyKeyProviderName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ProjectProperties3_get_AssemblyOriginatorKeyFileType_Proxy( 
    ProjectProperties3 * This,
    /* [retval][out] */ DWORD *pdwOriginatorKeyFileType);


void __RPC_STUB ProjectProperties3_get_AssemblyOriginatorKeyFileType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ProjectProperties3_put_AssemblyOriginatorKeyFileType_Proxy( 
    ProjectProperties3 * This,
    /* [in] */ DWORD dwOriginatorKeyFileType);


void __RPC_STUB ProjectProperties3_put_AssemblyOriginatorKeyFileType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ProjectProperties3_get_AssemblyVersion_Proxy( 
    ProjectProperties3 * This,
    /* [retval][out] */ BSTR *pbstrAssemblyVersion);


void __RPC_STUB ProjectProperties3_get_AssemblyVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ProjectProperties3_put_AssemblyVersion_Proxy( 
    ProjectProperties3 * This,
    /* [in] */ BSTR bstrAssemblyVersion);


void __RPC_STUB ProjectProperties3_put_AssemblyVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ProjectProperties3_get_AssemblyFileVersion_Proxy( 
    ProjectProperties3 * This,
    /* [retval][out] */ BSTR *pbstrAssemblyVersion);


void __RPC_STUB ProjectProperties3_get_AssemblyFileVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ProjectProperties3_put_AssemblyFileVersion_Proxy( 
    ProjectProperties3 * This,
    /* [in] */ BSTR bstrAssemblyVersion);


void __RPC_STUB ProjectProperties3_put_AssemblyFileVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE ProjectProperties3_get_GenerateManifests_Proxy( 
    ProjectProperties3 * This,
    /* [retval][out] */ VARIANT_BOOL *pbGenerateManifests);


void __RPC_STUB ProjectProperties3_get_GenerateManifests_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE ProjectProperties3_put_GenerateManifests_Proxy( 
    ProjectProperties3 * This,
    /* [in] */ VARIANT_BOOL bGenerateManifests);


void __RPC_STUB ProjectProperties3_put_GenerateManifests_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE ProjectProperties3_get_EnableSecurityDebugging_Proxy( 
    ProjectProperties3 * This,
    /* [retval][out] */ VARIANT_BOOL *pbEnableSecurityDebugging);


void __RPC_STUB ProjectProperties3_get_EnableSecurityDebugging_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE ProjectProperties3_put_EnableSecurityDebugging_Proxy( 
    ProjectProperties3 * This,
    /* [in] */ VARIANT_BOOL bEnableSecurityDebugging);


void __RPC_STUB ProjectProperties3_put_EnableSecurityDebugging_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE ProjectProperties3_get_DebugSecurityZoneURL_Proxy( 
    ProjectProperties3 * This,
    /* [retval][out] */ BSTR *pbstrSecurityURL);


void __RPC_STUB ProjectProperties3_get_DebugSecurityZoneURL_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE ProjectProperties3_put_DebugSecurityZoneURL_Proxy( 
    ProjectProperties3 * This,
    /* [in] */ BSTR bstrSecurityURL);


void __RPC_STUB ProjectProperties3_put_DebugSecurityZoneURL_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][nonbrowsable][propget] */ HRESULT STDMETHODCALLTYPE ProjectProperties3_get_Publish_Proxy( 
    ProjectProperties3 * This,
    /* [retval][out] */ IDispatch **ppdispPublish);


void __RPC_STUB ProjectProperties3_get_Publish_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ProjectProperties3_get_ComVisible_Proxy( 
    ProjectProperties3 * This,
    /* [retval][out] */ VARIANT_BOOL *pbComVisible);


void __RPC_STUB ProjectProperties3_get_ComVisible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ProjectProperties3_put_ComVisible_Proxy( 
    ProjectProperties3 * This,
    /* [in] */ VARIANT_BOOL bComVisible);


void __RPC_STUB ProjectProperties3_put_ComVisible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ProjectProperties3_get_AssemblyGuid_Proxy( 
    ProjectProperties3 * This,
    /* [retval][out] */ BSTR *pbstrAssemblyGuid);


void __RPC_STUB ProjectProperties3_get_AssemblyGuid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ProjectProperties3_put_AssemblyGuid_Proxy( 
    ProjectProperties3 * This,
    /* [in] */ BSTR bstrAssemblyGuid);


void __RPC_STUB ProjectProperties3_put_AssemblyGuid_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ProjectProperties3_get_NeutralResourcesLanguage_Proxy( 
    ProjectProperties3 * This,
    /* [retval][out] */ BSTR *pbstrNeutralResourcesLanguage);


void __RPC_STUB ProjectProperties3_get_NeutralResourcesLanguage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ProjectProperties3_put_NeutralResourcesLanguage_Proxy( 
    ProjectProperties3 * This,
    /* [in] */ BSTR bstrNeutralResourcesLanguage);


void __RPC_STUB ProjectProperties3_put_NeutralResourcesLanguage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ProjectProperties3_get_SignAssembly_Proxy( 
    ProjectProperties3 * This,
    /* [retval][out] */ VARIANT_BOOL *pbSignAssembly);


void __RPC_STUB ProjectProperties3_get_SignAssembly_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ProjectProperties3_put_SignAssembly_Proxy( 
    ProjectProperties3 * This,
    /* [in] */ VARIANT_BOOL bSignAssembly);


void __RPC_STUB ProjectProperties3_put_SignAssembly_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ProjectProperties3_get_TargetZone_Proxy( 
    ProjectProperties3 * This,
    /* [retval][out] */ BSTR *pbstrTargetZone);


void __RPC_STUB ProjectProperties3_get_TargetZone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ProjectProperties3_put_TargetZone_Proxy( 
    ProjectProperties3 * This,
    /* [in] */ BSTR bstrTargetZone);


void __RPC_STUB ProjectProperties3_put_TargetZone_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ProjectProperties3_get_ExcludedPermissions_Proxy( 
    ProjectProperties3 * This,
    /* [retval][out] */ BSTR *pbstrExcludedPermissions);


void __RPC_STUB ProjectProperties3_get_ExcludedPermissions_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE ProjectProperties3_put_ExcludedPermissions_Proxy( 
    ProjectProperties3 * This,
    /* [in] */ BSTR bstrExcludedPermissions);


void __RPC_STUB ProjectProperties3_put_ExcludedPermissions_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ProjectProperties3_INTERFACE_DEFINED__ */


#ifndef __VBProjectProperties3_INTERFACE_DEFINED__
#define __VBProjectProperties3_INTERFACE_DEFINED__

/* interface VBProjectProperties3 */
/* [object][dual][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_VBProjectProperties3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A93BFE7B-CFDA-471D-93C6-1747D0B06E8E")
    VBProjectProperties3 : public ProjectProperties3
    {
    public:
        virtual /* [helpstring][id][nonbrowsable][propget] */ HRESULT STDMETHODCALLTYPE get_MyApplication( 
            /* [retval][out] */ IDispatch **ppdispMyApplication) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MyType( 
            /* [retval][out] */ BSTR *pbstrMyType) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MyType( 
            /* [in] */ BSTR bstrMyType) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct VBProjectProperties3Vtbl
    {
        BEGIN_INTERFACE
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            VBProjectProperties3 * This,
            /* [in][idldescattr] */ struct GUID *riid,
            /* [out][idldescattr] */ void **ppvObj,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *AddRef )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ unsigned long *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Release )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ unsigned long *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            VBProjectProperties3 * This,
            /* [out][idldescattr] */ unsigned UINT *pctinfo,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            VBProjectProperties3 * This,
            /* [in][idldescattr] */ unsigned UINT itinfo,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [out][idldescattr] */ void **pptinfo,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            VBProjectProperties3 * This,
            /* [in][idldescattr] */ struct GUID *riid,
            /* [in][idldescattr] */ signed char **rgszNames,
            /* [in][idldescattr] */ unsigned UINT cNames,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [out][idldescattr] */ signed long *rgdispid,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            VBProjectProperties3 * This,
            /* [in][idldescattr] */ signed long dispidMember,
            /* [in][idldescattr] */ struct GUID *riid,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [in][idldescattr] */ unsigned short wFlags,
            /* [in][idldescattr] */ struct DISPPARAMS *pdispparams,
            /* [out][idldescattr] */ VARIANT *pvarResult,
            /* [out][idldescattr] */ struct EXCEPINFO *pexcepinfo,
            /* [out][idldescattr] */ unsigned UINT *puArgErr,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][hidden][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get___id )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][hidden][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get___project )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ IUnknown **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_StartupObject )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_StartupObject )( 
            VBProjectProperties3 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_OutputType )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ enum prjOutputType *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_OutputType )( 
            VBProjectProperties3 * This,
            /* [in][idldescattr] */ enum prjOutputType noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_RootNamespace )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_RootNamespace )( 
            VBProjectProperties3 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_AssemblyName )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_AssemblyName )( 
            VBProjectProperties3 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_AssemblyOriginatorKeyFile )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_AssemblyOriginatorKeyFile )( 
            VBProjectProperties3 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_AssemblyKeyContainerName )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_AssemblyKeyContainerName )( 
            VBProjectProperties3 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_AssemblyOriginatorKeyMode )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ enum prjOriginatorKeyMode *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_AssemblyOriginatorKeyMode )( 
            VBProjectProperties3 * This,
            /* [in][idldescattr] */ enum prjOriginatorKeyMode noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_DelaySign )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_DelaySign )( 
            VBProjectProperties3 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_WebServer )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_WebServerVersion )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ServerExtensionsVersion )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_LinkRepair )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_LinkRepair )( 
            VBProjectProperties3 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_OfflineURL )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_FileSharePath )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_FileSharePath )( 
            VBProjectProperties3 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveFileSharePath )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_WebAccessMethod )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ enum prjWebAccessMethod *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_WebAccessMethod )( 
            VBProjectProperties3 * This,
            /* [in][idldescattr] */ enum prjWebAccessMethod noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveWebAccessMethod )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ enum prjWebAccessMethod *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultClientScript )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ enum prjScriptLanguage *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultClientScript )( 
            VBProjectProperties3 * This,
            /* [in][idldescattr] */ enum prjScriptLanguage noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultTargetSchema )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ enum prjTargetSchema *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultTargetSchema )( 
            VBProjectProperties3 * This,
            /* [in][idldescattr] */ enum prjTargetSchema noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultHTMLPageLayout )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ enum prjHTMLPageLayout *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultHTMLPageLayout )( 
            VBProjectProperties3 * This,
            /* [in][idldescattr] */ enum prjHTMLPageLayout noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_FileName )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_FileName )( 
            VBProjectProperties3 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_FullPath )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_LocalPath )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_URL )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ActiveConfigurationSettings )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ ProjectConfigurationProperties **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Extender )( 
            VBProjectProperties3 * This,
            /* [in][idldescattr] */ BSTR ExtenderName,
            /* [retval][out] */ IDispatch **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ExtenderNames )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ VARIANT *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ExtenderCATID )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ApplicationIcon )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_ApplicationIcon )( 
            VBProjectProperties3 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_OptionStrict )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ enum prjOptionStrict *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_OptionStrict )( 
            VBProjectProperties3 * This,
            /* [in][idldescattr] */ enum prjOptionStrict noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ReferencePath )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_ReferencePath )( 
            VBProjectProperties3 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_OutputFileName )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][hidden][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_AbsoluteProjectDirectory )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_OptionExplicit )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ enum prjOptionExplicit *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_OptionExplicit )( 
            VBProjectProperties3 * This,
            /* [in][idldescattr] */ enum prjOptionExplicit noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_OptionCompare )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ enum prjCompare *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_OptionCompare )( 
            VBProjectProperties3 * This,
            /* [in][idldescattr] */ enum prjCompare noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ProjectType )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ enum prjProjectType *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultNamespace )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_DefaultNamespace )( 
            VBProjectProperties3 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_PreBuildEvent )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_PreBuildEvent )( 
            VBProjectProperties3 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_PostBuildEvent )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_PostBuildEvent )( 
            VBProjectProperties3 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_RunPostBuildEvent )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ enum prjRunPostBuildEvent *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_RunPostBuildEvent )( 
            VBProjectProperties3 * This,
            /* [in][idldescattr] */ enum prjRunPostBuildEvent noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_AspnetVersion )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Title )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ BSTR *pbstrTitle);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Title )( 
            VBProjectProperties3 * This,
            /* [in] */ BSTR bstrTitle);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Description )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ BSTR *pbstrDescription);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Description )( 
            VBProjectProperties3 * This,
            /* [in] */ BSTR bstrDescription);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Company )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ BSTR *pbstrCompany);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Company )( 
            VBProjectProperties3 * This,
            /* [in] */ BSTR bstrCompany);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Product )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ BSTR *pbstrProduct);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Product )( 
            VBProjectProperties3 * This,
            /* [in] */ BSTR bstrProduct);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Copyright )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ BSTR *pbstrCopyright);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Copyright )( 
            VBProjectProperties3 * This,
            /* [in] */ BSTR bstrCopyright);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Trademark )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ BSTR *pbstrTrademark);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Trademark )( 
            VBProjectProperties3 * This,
            /* [in] */ BSTR bstrTrademark);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AssemblyType )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ prjAssemblyType *pAssemblyType);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AssemblyType )( 
            VBProjectProperties3 * This,
            /* [in] */ prjAssemblyType AssemblyType);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TypeComplianceDiagnostics )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ VARIANT_BOOL *pbTypeComplianceDiagnostics);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TypeComplianceDiagnostics )( 
            VBProjectProperties3 * This,
            /* [in] */ VARIANT_BOOL bTypeComplianceDiagnostics);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Win32ResourceFile )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ BSTR *pbstrW32ResourceFile);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_Win32ResourceFile )( 
            VBProjectProperties3 * This,
            /* [in] */ BSTR bstrWin32ResourceFile);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PermissionSet )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ IUnknown **ppunk);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PermissionSet )( 
            VBProjectProperties3 * This,
            /* [in] */ IUnknown *punk);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AssemblyKeyProviderName )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ BSTR *pbstrKeyProviderName);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AssemblyKeyProviderName )( 
            VBProjectProperties3 * This,
            /* [in] */ BSTR bstrKeyProviderName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AssemblyOriginatorKeyFileType )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ DWORD *pdwOriginatorKeyFileType);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AssemblyOriginatorKeyFileType )( 
            VBProjectProperties3 * This,
            /* [in] */ DWORD dwOriginatorKeyFileType);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AssemblyVersion )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ BSTR *pbstrAssemblyVersion);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AssemblyVersion )( 
            VBProjectProperties3 * This,
            /* [in] */ BSTR bstrAssemblyVersion);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AssemblyFileVersion )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ BSTR *pbstrAssemblyVersion);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AssemblyFileVersion )( 
            VBProjectProperties3 * This,
            /* [in] */ BSTR bstrAssemblyVersion);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_GenerateManifests )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ VARIANT_BOOL *pbGenerateManifests);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_GenerateManifests )( 
            VBProjectProperties3 * This,
            /* [in] */ VARIANT_BOOL bGenerateManifests);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_EnableSecurityDebugging )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ VARIANT_BOOL *pbEnableSecurityDebugging);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_EnableSecurityDebugging )( 
            VBProjectProperties3 * This,
            /* [in] */ VARIANT_BOOL bEnableSecurityDebugging);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DebugSecurityZoneURL )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ BSTR *pbstrSecurityURL);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DebugSecurityZoneURL )( 
            VBProjectProperties3 * This,
            /* [in] */ BSTR bstrSecurityURL);
        
        /* [helpstring][id][nonbrowsable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_Publish )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ IDispatch **ppdispPublish);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ComVisible )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ VARIANT_BOOL *pbComVisible);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ComVisible )( 
            VBProjectProperties3 * This,
            /* [in] */ VARIANT_BOOL bComVisible);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_AssemblyGuid )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ BSTR *pbstrAssemblyGuid);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_AssemblyGuid )( 
            VBProjectProperties3 * This,
            /* [in] */ BSTR bstrAssemblyGuid);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_NeutralResourcesLanguage )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ BSTR *pbstrNeutralResourcesLanguage);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_NeutralResourcesLanguage )( 
            VBProjectProperties3 * This,
            /* [in] */ BSTR bstrNeutralResourcesLanguage);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SignAssembly )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ VARIANT_BOOL *pbSignAssembly);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SignAssembly )( 
            VBProjectProperties3 * This,
            /* [in] */ VARIANT_BOOL bSignAssembly);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TargetZone )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ BSTR *pbstrTargetZone);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TargetZone )( 
            VBProjectProperties3 * This,
            /* [in] */ BSTR bstrTargetZone);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ExcludedPermissions )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ BSTR *pbstrExcludedPermissions);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ExcludedPermissions )( 
            VBProjectProperties3 * This,
            /* [in] */ BSTR bstrExcludedPermissions);
        
        /* [helpstring][id][nonbrowsable][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MyApplication )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ IDispatch **ppdispMyApplication);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_MyType )( 
            VBProjectProperties3 * This,
            /* [retval][out] */ BSTR *pbstrMyType);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_MyType )( 
            VBProjectProperties3 * This,
            /* [in] */ BSTR bstrMyType);
        
        END_INTERFACE
    } VBProjectProperties3Vtbl;

    interface VBProjectProperties3
    {
        CONST_VTBL struct VBProjectProperties3Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define VBProjectProperties3_QueryInterface(This,riid,ppvObj,retval)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObj,retval)

#define VBProjectProperties3_AddRef(This,retval)	\
    (This)->lpVtbl -> AddRef(This,retval)

#define VBProjectProperties3_Release(This,retval)	\
    (This)->lpVtbl -> Release(This,retval)

#define VBProjectProperties3_GetTypeInfoCount(This,pctinfo,retval)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo,retval)

#define VBProjectProperties3_GetTypeInfo(This,itinfo,lcid,pptinfo,retval)	\
    (This)->lpVtbl -> GetTypeInfo(This,itinfo,lcid,pptinfo,retval)

#define VBProjectProperties3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgdispid,retval)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgdispid,retval)

#define VBProjectProperties3_Invoke(This,dispidMember,riid,lcid,wFlags,pdispparams,pvarResult,pexcepinfo,puArgErr,retval)	\
    (This)->lpVtbl -> Invoke(This,dispidMember,riid,lcid,wFlags,pdispparams,pvarResult,pexcepinfo,puArgErr,retval)

#define VBProjectProperties3_get___id(This,retval)	\
    (This)->lpVtbl -> get___id(This,retval)

#define VBProjectProperties3_get___project(This,retval)	\
    (This)->lpVtbl -> get___project(This,retval)

#define VBProjectProperties3_get_StartupObject(This,retval)	\
    (This)->lpVtbl -> get_StartupObject(This,retval)

#define VBProjectProperties3_put_StartupObject(This,noname,retval)	\
    (This)->lpVtbl -> put_StartupObject(This,noname,retval)

#define VBProjectProperties3_get_OutputType(This,retval)	\
    (This)->lpVtbl -> get_OutputType(This,retval)

#define VBProjectProperties3_put_OutputType(This,noname,retval)	\
    (This)->lpVtbl -> put_OutputType(This,noname,retval)

#define VBProjectProperties3_get_RootNamespace(This,retval)	\
    (This)->lpVtbl -> get_RootNamespace(This,retval)

#define VBProjectProperties3_put_RootNamespace(This,noname,retval)	\
    (This)->lpVtbl -> put_RootNamespace(This,noname,retval)

#define VBProjectProperties3_get_AssemblyName(This,retval)	\
    (This)->lpVtbl -> get_AssemblyName(This,retval)

#define VBProjectProperties3_put_AssemblyName(This,noname,retval)	\
    (This)->lpVtbl -> put_AssemblyName(This,noname,retval)

#define VBProjectProperties3_get_AssemblyOriginatorKeyFile(This,retval)	\
    (This)->lpVtbl -> get_AssemblyOriginatorKeyFile(This,retval)

#define VBProjectProperties3_put_AssemblyOriginatorKeyFile(This,noname,retval)	\
    (This)->lpVtbl -> put_AssemblyOriginatorKeyFile(This,noname,retval)

#define VBProjectProperties3_get_AssemblyKeyContainerName(This,retval)	\
    (This)->lpVtbl -> get_AssemblyKeyContainerName(This,retval)

#define VBProjectProperties3_put_AssemblyKeyContainerName(This,noname,retval)	\
    (This)->lpVtbl -> put_AssemblyKeyContainerName(This,noname,retval)

#define VBProjectProperties3_get_AssemblyOriginatorKeyMode(This,retval)	\
    (This)->lpVtbl -> get_AssemblyOriginatorKeyMode(This,retval)

#define VBProjectProperties3_put_AssemblyOriginatorKeyMode(This,noname,retval)	\
    (This)->lpVtbl -> put_AssemblyOriginatorKeyMode(This,noname,retval)

#define VBProjectProperties3_get_DelaySign(This,retval)	\
    (This)->lpVtbl -> get_DelaySign(This,retval)

#define VBProjectProperties3_put_DelaySign(This,noname,retval)	\
    (This)->lpVtbl -> put_DelaySign(This,noname,retval)

#define VBProjectProperties3_get_WebServer(This,retval)	\
    (This)->lpVtbl -> get_WebServer(This,retval)

#define VBProjectProperties3_get_WebServerVersion(This,retval)	\
    (This)->lpVtbl -> get_WebServerVersion(This,retval)

#define VBProjectProperties3_get_ServerExtensionsVersion(This,retval)	\
    (This)->lpVtbl -> get_ServerExtensionsVersion(This,retval)

#define VBProjectProperties3_get_LinkRepair(This,retval)	\
    (This)->lpVtbl -> get_LinkRepair(This,retval)

#define VBProjectProperties3_put_LinkRepair(This,noname,retval)	\
    (This)->lpVtbl -> put_LinkRepair(This,noname,retval)

#define VBProjectProperties3_get_OfflineURL(This,retval)	\
    (This)->lpVtbl -> get_OfflineURL(This,retval)

#define VBProjectProperties3_get_FileSharePath(This,retval)	\
    (This)->lpVtbl -> get_FileSharePath(This,retval)

#define VBProjectProperties3_put_FileSharePath(This,noname,retval)	\
    (This)->lpVtbl -> put_FileSharePath(This,noname,retval)

#define VBProjectProperties3_get_ActiveFileSharePath(This,retval)	\
    (This)->lpVtbl -> get_ActiveFileSharePath(This,retval)

#define VBProjectProperties3_get_WebAccessMethod(This,retval)	\
    (This)->lpVtbl -> get_WebAccessMethod(This,retval)

#define VBProjectProperties3_put_WebAccessMethod(This,noname,retval)	\
    (This)->lpVtbl -> put_WebAccessMethod(This,noname,retval)

#define VBProjectProperties3_get_ActiveWebAccessMethod(This,retval)	\
    (This)->lpVtbl -> get_ActiveWebAccessMethod(This,retval)

#define VBProjectProperties3_get_DefaultClientScript(This,retval)	\
    (This)->lpVtbl -> get_DefaultClientScript(This,retval)

#define VBProjectProperties3_put_DefaultClientScript(This,noname,retval)	\
    (This)->lpVtbl -> put_DefaultClientScript(This,noname,retval)

#define VBProjectProperties3_get_DefaultTargetSchema(This,retval)	\
    (This)->lpVtbl -> get_DefaultTargetSchema(This,retval)

#define VBProjectProperties3_put_DefaultTargetSchema(This,noname,retval)	\
    (This)->lpVtbl -> put_DefaultTargetSchema(This,noname,retval)

#define VBProjectProperties3_get_DefaultHTMLPageLayout(This,retval)	\
    (This)->lpVtbl -> get_DefaultHTMLPageLayout(This,retval)

#define VBProjectProperties3_put_DefaultHTMLPageLayout(This,noname,retval)	\
    (This)->lpVtbl -> put_DefaultHTMLPageLayout(This,noname,retval)

#define VBProjectProperties3_get_FileName(This,retval)	\
    (This)->lpVtbl -> get_FileName(This,retval)

#define VBProjectProperties3_put_FileName(This,noname,retval)	\
    (This)->lpVtbl -> put_FileName(This,noname,retval)

#define VBProjectProperties3_get_FullPath(This,retval)	\
    (This)->lpVtbl -> get_FullPath(This,retval)

#define VBProjectProperties3_get_LocalPath(This,retval)	\
    (This)->lpVtbl -> get_LocalPath(This,retval)

#define VBProjectProperties3_get_URL(This,retval)	\
    (This)->lpVtbl -> get_URL(This,retval)

#define VBProjectProperties3_get_ActiveConfigurationSettings(This,retval)	\
    (This)->lpVtbl -> get_ActiveConfigurationSettings(This,retval)

#define VBProjectProperties3_get_Extender(This,ExtenderName,retval)	\
    (This)->lpVtbl -> get_Extender(This,ExtenderName,retval)

#define VBProjectProperties3_get_ExtenderNames(This,retval)	\
    (This)->lpVtbl -> get_ExtenderNames(This,retval)

#define VBProjectProperties3_get_ExtenderCATID(This,retval)	\
    (This)->lpVtbl -> get_ExtenderCATID(This,retval)

#define VBProjectProperties3_get_ApplicationIcon(This,retval)	\
    (This)->lpVtbl -> get_ApplicationIcon(This,retval)

#define VBProjectProperties3_put_ApplicationIcon(This,noname,retval)	\
    (This)->lpVtbl -> put_ApplicationIcon(This,noname,retval)

#define VBProjectProperties3_get_OptionStrict(This,retval)	\
    (This)->lpVtbl -> get_OptionStrict(This,retval)

#define VBProjectProperties3_put_OptionStrict(This,noname,retval)	\
    (This)->lpVtbl -> put_OptionStrict(This,noname,retval)

#define VBProjectProperties3_get_ReferencePath(This,retval)	\
    (This)->lpVtbl -> get_ReferencePath(This,retval)

#define VBProjectProperties3_put_ReferencePath(This,noname,retval)	\
    (This)->lpVtbl -> put_ReferencePath(This,noname,retval)

#define VBProjectProperties3_get_OutputFileName(This,retval)	\
    (This)->lpVtbl -> get_OutputFileName(This,retval)

#define VBProjectProperties3_get_AbsoluteProjectDirectory(This,retval)	\
    (This)->lpVtbl -> get_AbsoluteProjectDirectory(This,retval)

#define VBProjectProperties3_get_OptionExplicit(This,retval)	\
    (This)->lpVtbl -> get_OptionExplicit(This,retval)

#define VBProjectProperties3_put_OptionExplicit(This,noname,retval)	\
    (This)->lpVtbl -> put_OptionExplicit(This,noname,retval)

#define VBProjectProperties3_get_OptionCompare(This,retval)	\
    (This)->lpVtbl -> get_OptionCompare(This,retval)

#define VBProjectProperties3_put_OptionCompare(This,noname,retval)	\
    (This)->lpVtbl -> put_OptionCompare(This,noname,retval)

#define VBProjectProperties3_get_ProjectType(This,retval)	\
    (This)->lpVtbl -> get_ProjectType(This,retval)

#define VBProjectProperties3_get_DefaultNamespace(This,retval)	\
    (This)->lpVtbl -> get_DefaultNamespace(This,retval)

#define VBProjectProperties3_put_DefaultNamespace(This,noname,retval)	\
    (This)->lpVtbl -> put_DefaultNamespace(This,noname,retval)

#define VBProjectProperties3_get_PreBuildEvent(This,retval)	\
    (This)->lpVtbl -> get_PreBuildEvent(This,retval)

#define VBProjectProperties3_put_PreBuildEvent(This,noname,retval)	\
    (This)->lpVtbl -> put_PreBuildEvent(This,noname,retval)

#define VBProjectProperties3_get_PostBuildEvent(This,retval)	\
    (This)->lpVtbl -> get_PostBuildEvent(This,retval)

#define VBProjectProperties3_put_PostBuildEvent(This,noname,retval)	\
    (This)->lpVtbl -> put_PostBuildEvent(This,noname,retval)

#define VBProjectProperties3_get_RunPostBuildEvent(This,retval)	\
    (This)->lpVtbl -> get_RunPostBuildEvent(This,retval)

#define VBProjectProperties3_put_RunPostBuildEvent(This,noname,retval)	\
    (This)->lpVtbl -> put_RunPostBuildEvent(This,noname,retval)

#define VBProjectProperties3_get_AspnetVersion(This,retval)	\
    (This)->lpVtbl -> get_AspnetVersion(This,retval)


#define VBProjectProperties3_get_Title(This,pbstrTitle)	\
    (This)->lpVtbl -> get_Title(This,pbstrTitle)

#define VBProjectProperties3_put_Title(This,bstrTitle)	\
    (This)->lpVtbl -> put_Title(This,bstrTitle)

#define VBProjectProperties3_get_Description(This,pbstrDescription)	\
    (This)->lpVtbl -> get_Description(This,pbstrDescription)

#define VBProjectProperties3_put_Description(This,bstrDescription)	\
    (This)->lpVtbl -> put_Description(This,bstrDescription)

#define VBProjectProperties3_get_Company(This,pbstrCompany)	\
    (This)->lpVtbl -> get_Company(This,pbstrCompany)

#define VBProjectProperties3_put_Company(This,bstrCompany)	\
    (This)->lpVtbl -> put_Company(This,bstrCompany)

#define VBProjectProperties3_get_Product(This,pbstrProduct)	\
    (This)->lpVtbl -> get_Product(This,pbstrProduct)

#define VBProjectProperties3_put_Product(This,bstrProduct)	\
    (This)->lpVtbl -> put_Product(This,bstrProduct)

#define VBProjectProperties3_get_Copyright(This,pbstrCopyright)	\
    (This)->lpVtbl -> get_Copyright(This,pbstrCopyright)

#define VBProjectProperties3_put_Copyright(This,bstrCopyright)	\
    (This)->lpVtbl -> put_Copyright(This,bstrCopyright)

#define VBProjectProperties3_get_Trademark(This,pbstrTrademark)	\
    (This)->lpVtbl -> get_Trademark(This,pbstrTrademark)

#define VBProjectProperties3_put_Trademark(This,bstrTrademark)	\
    (This)->lpVtbl -> put_Trademark(This,bstrTrademark)

#define VBProjectProperties3_get_AssemblyType(This,pAssemblyType)	\
    (This)->lpVtbl -> get_AssemblyType(This,pAssemblyType)

#define VBProjectProperties3_put_AssemblyType(This,AssemblyType)	\
    (This)->lpVtbl -> put_AssemblyType(This,AssemblyType)

#define VBProjectProperties3_get_TypeComplianceDiagnostics(This,pbTypeComplianceDiagnostics)	\
    (This)->lpVtbl -> get_TypeComplianceDiagnostics(This,pbTypeComplianceDiagnostics)

#define VBProjectProperties3_put_TypeComplianceDiagnostics(This,bTypeComplianceDiagnostics)	\
    (This)->lpVtbl -> put_TypeComplianceDiagnostics(This,bTypeComplianceDiagnostics)

#define VBProjectProperties3_get_Win32ResourceFile(This,pbstrW32ResourceFile)	\
    (This)->lpVtbl -> get_Win32ResourceFile(This,pbstrW32ResourceFile)

#define VBProjectProperties3_put_Win32ResourceFile(This,bstrWin32ResourceFile)	\
    (This)->lpVtbl -> put_Win32ResourceFile(This,bstrWin32ResourceFile)

#define VBProjectProperties3_get_PermissionSet(This,ppunk)	\
    (This)->lpVtbl -> get_PermissionSet(This,ppunk)

#define VBProjectProperties3_put_PermissionSet(This,punk)	\
    (This)->lpVtbl -> put_PermissionSet(This,punk)

#define VBProjectProperties3_get_AssemblyKeyProviderName(This,pbstrKeyProviderName)	\
    (This)->lpVtbl -> get_AssemblyKeyProviderName(This,pbstrKeyProviderName)

#define VBProjectProperties3_put_AssemblyKeyProviderName(This,bstrKeyProviderName)	\
    (This)->lpVtbl -> put_AssemblyKeyProviderName(This,bstrKeyProviderName)

#define VBProjectProperties3_get_AssemblyOriginatorKeyFileType(This,pdwOriginatorKeyFileType)	\
    (This)->lpVtbl -> get_AssemblyOriginatorKeyFileType(This,pdwOriginatorKeyFileType)

#define VBProjectProperties3_put_AssemblyOriginatorKeyFileType(This,dwOriginatorKeyFileType)	\
    (This)->lpVtbl -> put_AssemblyOriginatorKeyFileType(This,dwOriginatorKeyFileType)

#define VBProjectProperties3_get_AssemblyVersion(This,pbstrAssemblyVersion)	\
    (This)->lpVtbl -> get_AssemblyVersion(This,pbstrAssemblyVersion)

#define VBProjectProperties3_put_AssemblyVersion(This,bstrAssemblyVersion)	\
    (This)->lpVtbl -> put_AssemblyVersion(This,bstrAssemblyVersion)

#define VBProjectProperties3_get_AssemblyFileVersion(This,pbstrAssemblyVersion)	\
    (This)->lpVtbl -> get_AssemblyFileVersion(This,pbstrAssemblyVersion)

#define VBProjectProperties3_put_AssemblyFileVersion(This,bstrAssemblyVersion)	\
    (This)->lpVtbl -> put_AssemblyFileVersion(This,bstrAssemblyVersion)

#define VBProjectProperties3_get_GenerateManifests(This,pbGenerateManifests)	\
    (This)->lpVtbl -> get_GenerateManifests(This,pbGenerateManifests)

#define VBProjectProperties3_put_GenerateManifests(This,bGenerateManifests)	\
    (This)->lpVtbl -> put_GenerateManifests(This,bGenerateManifests)

#define VBProjectProperties3_get_EnableSecurityDebugging(This,pbEnableSecurityDebugging)	\
    (This)->lpVtbl -> get_EnableSecurityDebugging(This,pbEnableSecurityDebugging)

#define VBProjectProperties3_put_EnableSecurityDebugging(This,bEnableSecurityDebugging)	\
    (This)->lpVtbl -> put_EnableSecurityDebugging(This,bEnableSecurityDebugging)

#define VBProjectProperties3_get_DebugSecurityZoneURL(This,pbstrSecurityURL)	\
    (This)->lpVtbl -> get_DebugSecurityZoneURL(This,pbstrSecurityURL)

#define VBProjectProperties3_put_DebugSecurityZoneURL(This,bstrSecurityURL)	\
    (This)->lpVtbl -> put_DebugSecurityZoneURL(This,bstrSecurityURL)

#define VBProjectProperties3_get_Publish(This,ppdispPublish)	\
    (This)->lpVtbl -> get_Publish(This,ppdispPublish)

#define VBProjectProperties3_get_ComVisible(This,pbComVisible)	\
    (This)->lpVtbl -> get_ComVisible(This,pbComVisible)

#define VBProjectProperties3_put_ComVisible(This,bComVisible)	\
    (This)->lpVtbl -> put_ComVisible(This,bComVisible)

#define VBProjectProperties3_get_AssemblyGuid(This,pbstrAssemblyGuid)	\
    (This)->lpVtbl -> get_AssemblyGuid(This,pbstrAssemblyGuid)

#define VBProjectProperties3_put_AssemblyGuid(This,bstrAssemblyGuid)	\
    (This)->lpVtbl -> put_AssemblyGuid(This,bstrAssemblyGuid)

#define VBProjectProperties3_get_NeutralResourcesLanguage(This,pbstrNeutralResourcesLanguage)	\
    (This)->lpVtbl -> get_NeutralResourcesLanguage(This,pbstrNeutralResourcesLanguage)

#define VBProjectProperties3_put_NeutralResourcesLanguage(This,bstrNeutralResourcesLanguage)	\
    (This)->lpVtbl -> put_NeutralResourcesLanguage(This,bstrNeutralResourcesLanguage)

#define VBProjectProperties3_get_SignAssembly(This,pbSignAssembly)	\
    (This)->lpVtbl -> get_SignAssembly(This,pbSignAssembly)

#define VBProjectProperties3_put_SignAssembly(This,bSignAssembly)	\
    (This)->lpVtbl -> put_SignAssembly(This,bSignAssembly)

#define VBProjectProperties3_get_TargetZone(This,pbstrTargetZone)	\
    (This)->lpVtbl -> get_TargetZone(This,pbstrTargetZone)

#define VBProjectProperties3_put_TargetZone(This,bstrTargetZone)	\
    (This)->lpVtbl -> put_TargetZone(This,bstrTargetZone)

#define VBProjectProperties3_get_ExcludedPermissions(This,pbstrExcludedPermissions)	\
    (This)->lpVtbl -> get_ExcludedPermissions(This,pbstrExcludedPermissions)

#define VBProjectProperties3_put_ExcludedPermissions(This,bstrExcludedPermissions)	\
    (This)->lpVtbl -> put_ExcludedPermissions(This,bstrExcludedPermissions)


#define VBProjectProperties3_get_MyApplication(This,ppdispMyApplication)	\
    (This)->lpVtbl -> get_MyApplication(This,ppdispMyApplication)

#define VBProjectProperties3_get_MyType(This,pbstrMyType)	\
    (This)->lpVtbl -> get_MyType(This,pbstrMyType)

#define VBProjectProperties3_put_MyType(This,bstrMyType)	\
    (This)->lpVtbl -> put_MyType(This,bstrMyType)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][nonbrowsable][propget] */ HRESULT STDMETHODCALLTYPE VBProjectProperties3_get_MyApplication_Proxy( 
    VBProjectProperties3 * This,
    /* [retval][out] */ IDispatch **ppdispMyApplication);


void __RPC_STUB VBProjectProperties3_get_MyApplication_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE VBProjectProperties3_get_MyType_Proxy( 
    VBProjectProperties3 * This,
    /* [retval][out] */ BSTR *pbstrMyType);


void __RPC_STUB VBProjectProperties3_get_MyType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE VBProjectProperties3_put_MyType_Proxy( 
    VBProjectProperties3 * This,
    /* [in] */ BSTR bstrMyType);


void __RPC_STUB VBProjectProperties3_put_MyType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __VBProjectProperties3_INTERFACE_DEFINED__ */


#ifndef __CSharpProjectConfigurationProperties3_INTERFACE_DEFINED__
#define __CSharpProjectConfigurationProperties3_INTERFACE_DEFINED__

/* interface CSharpProjectConfigurationProperties3 */
/* [object][dual][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_CSharpProjectConfigurationProperties3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F25C9AD7-E371-414d-82A0-24E8BBC25C99")
    CSharpProjectConfigurationProperties3 : public ProjectConfigurationProperties3
    {
    public:
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_LanguageVersion( 
            /* [retval][out] */ BSTR *pbstrW32LanguageVersion) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_LanguageVersion( 
            /* [in] */ BSTR bstrLanguageVersion) = 0;
        
        virtual /* [id][propget] */ HRESULT STDMETHODCALLTYPE get_ErrorReport( 
            /* [retval][out] */ BSTR *pbstrErrorReport) = 0;
        
        virtual /* [id][propput] */ HRESULT STDMETHODCALLTYPE put_ErrorReport( 
            /* [in] */ BSTR bstrErrorReport) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct CSharpProjectConfigurationProperties3Vtbl
    {
        BEGIN_INTERFACE
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ struct GUID *riid,
            /* [out][idldescattr] */ void **ppvObj,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *AddRef )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ unsigned long *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Release )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ unsigned long *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [out][idldescattr] */ unsigned UINT *pctinfo,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ unsigned UINT itinfo,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [out][idldescattr] */ void **pptinfo,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ struct GUID *riid,
            /* [in][idldescattr] */ signed char **rgszNames,
            /* [in][idldescattr] */ unsigned UINT cNames,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [out][idldescattr] */ signed long *rgdispid,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ signed long dispidMember,
            /* [in][idldescattr] */ struct GUID *riid,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [in][idldescattr] */ unsigned short wFlags,
            /* [in][idldescattr] */ struct DISPPARAMS *pdispparams,
            /* [out][idldescattr] */ VARIANT *pvarResult,
            /* [out][idldescattr] */ struct EXCEPINFO *pexcepinfo,
            /* [out][idldescattr] */ unsigned UINT *puArgErr,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][hidden][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get___id )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_DebugSymbols )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_DebugSymbols )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_DefineDebug )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_DefineDebug )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_DefineTrace )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_DefineTrace )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_OutputPath )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_OutputPath )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_IntermediatePath )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][hidden][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_IntermediatePath )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_DefineConstants )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_DefineConstants )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_RemoveIntegerChecks )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_RemoveIntegerChecks )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_BaseAddress )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ unsigned long *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_BaseAddress )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ unsigned long noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_AllowUnsafeBlocks )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_AllowUnsafeBlocks )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_CheckForOverflowUnderflow )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_CheckForOverflowUnderflow )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_DocumentationFile )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_DocumentationFile )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Optimize )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_Optimize )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_IncrementalBuild )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_IncrementalBuild )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_StartProgram )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_StartProgram )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_StartWorkingDirectory )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_StartWorkingDirectory )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_StartURL )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_StartURL )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_StartPage )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_StartPage )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_StartArguments )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_StartArguments )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_StartWithIE )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_StartWithIE )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_EnableASPDebugging )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_EnableASPDebugging )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_EnableASPXDebugging )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_EnableASPXDebugging )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_EnableUnmanagedDebugging )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_EnableUnmanagedDebugging )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_StartAction )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ enum prjStartAction *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_StartAction )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ enum prjStartAction noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Extender )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BSTR ExtenderName,
            /* [retval][out] */ IDispatch **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ExtenderNames )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ VARIANT *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ExtenderCATID )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_WarningLevel )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ enum prjWarningLevel *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_WarningLevel )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ enum prjWarningLevel noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_TreatWarningsAsErrors )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_TreatWarningsAsErrors )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_EnableSQLServerDebugging )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_EnableSQLServerDebugging )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_FileAlignment )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ unsigned long *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_FileAlignment )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ unsigned long noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_RegisterForComInterop )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_RegisterForComInterop )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ConfigurationOverrideFile )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_ConfigurationOverrideFile )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_RemoteDebugEnabled )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_RemoteDebugEnabled )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_RemoteDebugMachine )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_RemoteDebugMachine )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_NoWarn )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_NoWarn )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_NoStdLib )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_NoStdLib )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DebugInfo )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BSTR *pbstrDebugInfo);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DebugInfo )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [in] */ BSTR bstrDebugInfo);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PlatformTarget )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BSTR *pbstrPlatformTarget);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PlatformTarget )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [in] */ BSTR bstrPlatformTarget);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TreatSpecificWarningsAsErrors )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BSTR *pbstrWarningsAsErrors);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TreatSpecificWarningsAsErrors )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [in] */ BSTR bstrWarningsAsErrors);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_LanguageVersion )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BSTR *pbstrW32LanguageVersion);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_LanguageVersion )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [in] */ BSTR bstrLanguageVersion);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ErrorReport )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BSTR *pbstrErrorReport);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ErrorReport )( 
            CSharpProjectConfigurationProperties3 * This,
            /* [in] */ BSTR bstrErrorReport);
        
        END_INTERFACE
    } CSharpProjectConfigurationProperties3Vtbl;

    interface CSharpProjectConfigurationProperties3
    {
        CONST_VTBL struct CSharpProjectConfigurationProperties3Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define CSharpProjectConfigurationProperties3_QueryInterface(This,riid,ppvObj,retval)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObj,retval)

#define CSharpProjectConfigurationProperties3_AddRef(This,retval)	\
    (This)->lpVtbl -> AddRef(This,retval)

#define CSharpProjectConfigurationProperties3_Release(This,retval)	\
    (This)->lpVtbl -> Release(This,retval)

#define CSharpProjectConfigurationProperties3_GetTypeInfoCount(This,pctinfo,retval)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo,retval)

#define CSharpProjectConfigurationProperties3_GetTypeInfo(This,itinfo,lcid,pptinfo,retval)	\
    (This)->lpVtbl -> GetTypeInfo(This,itinfo,lcid,pptinfo,retval)

#define CSharpProjectConfigurationProperties3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgdispid,retval)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgdispid,retval)

#define CSharpProjectConfigurationProperties3_Invoke(This,dispidMember,riid,lcid,wFlags,pdispparams,pvarResult,pexcepinfo,puArgErr,retval)	\
    (This)->lpVtbl -> Invoke(This,dispidMember,riid,lcid,wFlags,pdispparams,pvarResult,pexcepinfo,puArgErr,retval)

#define CSharpProjectConfigurationProperties3_get___id(This,retval)	\
    (This)->lpVtbl -> get___id(This,retval)

#define CSharpProjectConfigurationProperties3_get_DebugSymbols(This,retval)	\
    (This)->lpVtbl -> get_DebugSymbols(This,retval)

#define CSharpProjectConfigurationProperties3_put_DebugSymbols(This,noname,retval)	\
    (This)->lpVtbl -> put_DebugSymbols(This,noname,retval)

#define CSharpProjectConfigurationProperties3_get_DefineDebug(This,retval)	\
    (This)->lpVtbl -> get_DefineDebug(This,retval)

#define CSharpProjectConfigurationProperties3_put_DefineDebug(This,noname,retval)	\
    (This)->lpVtbl -> put_DefineDebug(This,noname,retval)

#define CSharpProjectConfigurationProperties3_get_DefineTrace(This,retval)	\
    (This)->lpVtbl -> get_DefineTrace(This,retval)

#define CSharpProjectConfigurationProperties3_put_DefineTrace(This,noname,retval)	\
    (This)->lpVtbl -> put_DefineTrace(This,noname,retval)

#define CSharpProjectConfigurationProperties3_get_OutputPath(This,retval)	\
    (This)->lpVtbl -> get_OutputPath(This,retval)

#define CSharpProjectConfigurationProperties3_put_OutputPath(This,noname,retval)	\
    (This)->lpVtbl -> put_OutputPath(This,noname,retval)

#define CSharpProjectConfigurationProperties3_get_IntermediatePath(This,retval)	\
    (This)->lpVtbl -> get_IntermediatePath(This,retval)

#define CSharpProjectConfigurationProperties3_put_IntermediatePath(This,noname,retval)	\
    (This)->lpVtbl -> put_IntermediatePath(This,noname,retval)

#define CSharpProjectConfigurationProperties3_get_DefineConstants(This,retval)	\
    (This)->lpVtbl -> get_DefineConstants(This,retval)

#define CSharpProjectConfigurationProperties3_put_DefineConstants(This,noname,retval)	\
    (This)->lpVtbl -> put_DefineConstants(This,noname,retval)

#define CSharpProjectConfigurationProperties3_get_RemoveIntegerChecks(This,retval)	\
    (This)->lpVtbl -> get_RemoveIntegerChecks(This,retval)

#define CSharpProjectConfigurationProperties3_put_RemoveIntegerChecks(This,noname,retval)	\
    (This)->lpVtbl -> put_RemoveIntegerChecks(This,noname,retval)

#define CSharpProjectConfigurationProperties3_get_BaseAddress(This,retval)	\
    (This)->lpVtbl -> get_BaseAddress(This,retval)

#define CSharpProjectConfigurationProperties3_put_BaseAddress(This,noname,retval)	\
    (This)->lpVtbl -> put_BaseAddress(This,noname,retval)

#define CSharpProjectConfigurationProperties3_get_AllowUnsafeBlocks(This,retval)	\
    (This)->lpVtbl -> get_AllowUnsafeBlocks(This,retval)

#define CSharpProjectConfigurationProperties3_put_AllowUnsafeBlocks(This,noname,retval)	\
    (This)->lpVtbl -> put_AllowUnsafeBlocks(This,noname,retval)

#define CSharpProjectConfigurationProperties3_get_CheckForOverflowUnderflow(This,retval)	\
    (This)->lpVtbl -> get_CheckForOverflowUnderflow(This,retval)

#define CSharpProjectConfigurationProperties3_put_CheckForOverflowUnderflow(This,noname,retval)	\
    (This)->lpVtbl -> put_CheckForOverflowUnderflow(This,noname,retval)

#define CSharpProjectConfigurationProperties3_get_DocumentationFile(This,retval)	\
    (This)->lpVtbl -> get_DocumentationFile(This,retval)

#define CSharpProjectConfigurationProperties3_put_DocumentationFile(This,noname,retval)	\
    (This)->lpVtbl -> put_DocumentationFile(This,noname,retval)

#define CSharpProjectConfigurationProperties3_get_Optimize(This,retval)	\
    (This)->lpVtbl -> get_Optimize(This,retval)

#define CSharpProjectConfigurationProperties3_put_Optimize(This,noname,retval)	\
    (This)->lpVtbl -> put_Optimize(This,noname,retval)

#define CSharpProjectConfigurationProperties3_get_IncrementalBuild(This,retval)	\
    (This)->lpVtbl -> get_IncrementalBuild(This,retval)

#define CSharpProjectConfigurationProperties3_put_IncrementalBuild(This,noname,retval)	\
    (This)->lpVtbl -> put_IncrementalBuild(This,noname,retval)

#define CSharpProjectConfigurationProperties3_get_StartProgram(This,retval)	\
    (This)->lpVtbl -> get_StartProgram(This,retval)

#define CSharpProjectConfigurationProperties3_put_StartProgram(This,noname,retval)	\
    (This)->lpVtbl -> put_StartProgram(This,noname,retval)

#define CSharpProjectConfigurationProperties3_get_StartWorkingDirectory(This,retval)	\
    (This)->lpVtbl -> get_StartWorkingDirectory(This,retval)

#define CSharpProjectConfigurationProperties3_put_StartWorkingDirectory(This,noname,retval)	\
    (This)->lpVtbl -> put_StartWorkingDirectory(This,noname,retval)

#define CSharpProjectConfigurationProperties3_get_StartURL(This,retval)	\
    (This)->lpVtbl -> get_StartURL(This,retval)

#define CSharpProjectConfigurationProperties3_put_StartURL(This,noname,retval)	\
    (This)->lpVtbl -> put_StartURL(This,noname,retval)

#define CSharpProjectConfigurationProperties3_get_StartPage(This,retval)	\
    (This)->lpVtbl -> get_StartPage(This,retval)

#define CSharpProjectConfigurationProperties3_put_StartPage(This,noname,retval)	\
    (This)->lpVtbl -> put_StartPage(This,noname,retval)

#define CSharpProjectConfigurationProperties3_get_StartArguments(This,retval)	\
    (This)->lpVtbl -> get_StartArguments(This,retval)

#define CSharpProjectConfigurationProperties3_put_StartArguments(This,noname,retval)	\
    (This)->lpVtbl -> put_StartArguments(This,noname,retval)

#define CSharpProjectConfigurationProperties3_get_StartWithIE(This,retval)	\
    (This)->lpVtbl -> get_StartWithIE(This,retval)

#define CSharpProjectConfigurationProperties3_put_StartWithIE(This,noname,retval)	\
    (This)->lpVtbl -> put_StartWithIE(This,noname,retval)

#define CSharpProjectConfigurationProperties3_get_EnableASPDebugging(This,retval)	\
    (This)->lpVtbl -> get_EnableASPDebugging(This,retval)

#define CSharpProjectConfigurationProperties3_put_EnableASPDebugging(This,noname,retval)	\
    (This)->lpVtbl -> put_EnableASPDebugging(This,noname,retval)

#define CSharpProjectConfigurationProperties3_get_EnableASPXDebugging(This,retval)	\
    (This)->lpVtbl -> get_EnableASPXDebugging(This,retval)

#define CSharpProjectConfigurationProperties3_put_EnableASPXDebugging(This,noname,retval)	\
    (This)->lpVtbl -> put_EnableASPXDebugging(This,noname,retval)

#define CSharpProjectConfigurationProperties3_get_EnableUnmanagedDebugging(This,retval)	\
    (This)->lpVtbl -> get_EnableUnmanagedDebugging(This,retval)

#define CSharpProjectConfigurationProperties3_put_EnableUnmanagedDebugging(This,noname,retval)	\
    (This)->lpVtbl -> put_EnableUnmanagedDebugging(This,noname,retval)

#define CSharpProjectConfigurationProperties3_get_StartAction(This,retval)	\
    (This)->lpVtbl -> get_StartAction(This,retval)

#define CSharpProjectConfigurationProperties3_put_StartAction(This,noname,retval)	\
    (This)->lpVtbl -> put_StartAction(This,noname,retval)

#define CSharpProjectConfigurationProperties3_get_Extender(This,ExtenderName,retval)	\
    (This)->lpVtbl -> get_Extender(This,ExtenderName,retval)

#define CSharpProjectConfigurationProperties3_get_ExtenderNames(This,retval)	\
    (This)->lpVtbl -> get_ExtenderNames(This,retval)

#define CSharpProjectConfigurationProperties3_get_ExtenderCATID(This,retval)	\
    (This)->lpVtbl -> get_ExtenderCATID(This,retval)

#define CSharpProjectConfigurationProperties3_get_WarningLevel(This,retval)	\
    (This)->lpVtbl -> get_WarningLevel(This,retval)

#define CSharpProjectConfigurationProperties3_put_WarningLevel(This,noname,retval)	\
    (This)->lpVtbl -> put_WarningLevel(This,noname,retval)

#define CSharpProjectConfigurationProperties3_get_TreatWarningsAsErrors(This,retval)	\
    (This)->lpVtbl -> get_TreatWarningsAsErrors(This,retval)

#define CSharpProjectConfigurationProperties3_put_TreatWarningsAsErrors(This,noname,retval)	\
    (This)->lpVtbl -> put_TreatWarningsAsErrors(This,noname,retval)

#define CSharpProjectConfigurationProperties3_get_EnableSQLServerDebugging(This,retval)	\
    (This)->lpVtbl -> get_EnableSQLServerDebugging(This,retval)

#define CSharpProjectConfigurationProperties3_put_EnableSQLServerDebugging(This,noname,retval)	\
    (This)->lpVtbl -> put_EnableSQLServerDebugging(This,noname,retval)

#define CSharpProjectConfigurationProperties3_get_FileAlignment(This,retval)	\
    (This)->lpVtbl -> get_FileAlignment(This,retval)

#define CSharpProjectConfigurationProperties3_put_FileAlignment(This,noname,retval)	\
    (This)->lpVtbl -> put_FileAlignment(This,noname,retval)

#define CSharpProjectConfigurationProperties3_get_RegisterForComInterop(This,retval)	\
    (This)->lpVtbl -> get_RegisterForComInterop(This,retval)

#define CSharpProjectConfigurationProperties3_put_RegisterForComInterop(This,noname,retval)	\
    (This)->lpVtbl -> put_RegisterForComInterop(This,noname,retval)

#define CSharpProjectConfigurationProperties3_get_ConfigurationOverrideFile(This,retval)	\
    (This)->lpVtbl -> get_ConfigurationOverrideFile(This,retval)

#define CSharpProjectConfigurationProperties3_put_ConfigurationOverrideFile(This,noname,retval)	\
    (This)->lpVtbl -> put_ConfigurationOverrideFile(This,noname,retval)

#define CSharpProjectConfigurationProperties3_get_RemoteDebugEnabled(This,retval)	\
    (This)->lpVtbl -> get_RemoteDebugEnabled(This,retval)

#define CSharpProjectConfigurationProperties3_put_RemoteDebugEnabled(This,noname,retval)	\
    (This)->lpVtbl -> put_RemoteDebugEnabled(This,noname,retval)

#define CSharpProjectConfigurationProperties3_get_RemoteDebugMachine(This,retval)	\
    (This)->lpVtbl -> get_RemoteDebugMachine(This,retval)

#define CSharpProjectConfigurationProperties3_put_RemoteDebugMachine(This,noname,retval)	\
    (This)->lpVtbl -> put_RemoteDebugMachine(This,noname,retval)

#define CSharpProjectConfigurationProperties3_get_NoWarn(This,retval)	\
    (This)->lpVtbl -> get_NoWarn(This,retval)

#define CSharpProjectConfigurationProperties3_put_NoWarn(This,noname,retval)	\
    (This)->lpVtbl -> put_NoWarn(This,noname,retval)

#define CSharpProjectConfigurationProperties3_get_NoStdLib(This,retval)	\
    (This)->lpVtbl -> get_NoStdLib(This,retval)

#define CSharpProjectConfigurationProperties3_put_NoStdLib(This,noname,retval)	\
    (This)->lpVtbl -> put_NoStdLib(This,noname,retval)


#define CSharpProjectConfigurationProperties3_get_DebugInfo(This,pbstrDebugInfo)	\
    (This)->lpVtbl -> get_DebugInfo(This,pbstrDebugInfo)

#define CSharpProjectConfigurationProperties3_put_DebugInfo(This,bstrDebugInfo)	\
    (This)->lpVtbl -> put_DebugInfo(This,bstrDebugInfo)

#define CSharpProjectConfigurationProperties3_get_PlatformTarget(This,pbstrPlatformTarget)	\
    (This)->lpVtbl -> get_PlatformTarget(This,pbstrPlatformTarget)

#define CSharpProjectConfigurationProperties3_put_PlatformTarget(This,bstrPlatformTarget)	\
    (This)->lpVtbl -> put_PlatformTarget(This,bstrPlatformTarget)

#define CSharpProjectConfigurationProperties3_get_TreatSpecificWarningsAsErrors(This,pbstrWarningsAsErrors)	\
    (This)->lpVtbl -> get_TreatSpecificWarningsAsErrors(This,pbstrWarningsAsErrors)

#define CSharpProjectConfigurationProperties3_put_TreatSpecificWarningsAsErrors(This,bstrWarningsAsErrors)	\
    (This)->lpVtbl -> put_TreatSpecificWarningsAsErrors(This,bstrWarningsAsErrors)


#define CSharpProjectConfigurationProperties3_get_LanguageVersion(This,pbstrW32LanguageVersion)	\
    (This)->lpVtbl -> get_LanguageVersion(This,pbstrW32LanguageVersion)

#define CSharpProjectConfigurationProperties3_put_LanguageVersion(This,bstrLanguageVersion)	\
    (This)->lpVtbl -> put_LanguageVersion(This,bstrLanguageVersion)

#define CSharpProjectConfigurationProperties3_get_ErrorReport(This,pbstrErrorReport)	\
    (This)->lpVtbl -> get_ErrorReport(This,pbstrErrorReport)

#define CSharpProjectConfigurationProperties3_put_ErrorReport(This,bstrErrorReport)	\
    (This)->lpVtbl -> put_ErrorReport(This,bstrErrorReport)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id][propget] */ HRESULT STDMETHODCALLTYPE CSharpProjectConfigurationProperties3_get_LanguageVersion_Proxy( 
    CSharpProjectConfigurationProperties3 * This,
    /* [retval][out] */ BSTR *pbstrW32LanguageVersion);


void __RPC_STUB CSharpProjectConfigurationProperties3_get_LanguageVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE CSharpProjectConfigurationProperties3_put_LanguageVersion_Proxy( 
    CSharpProjectConfigurationProperties3 * This,
    /* [in] */ BSTR bstrLanguageVersion);


void __RPC_STUB CSharpProjectConfigurationProperties3_put_LanguageVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propget] */ HRESULT STDMETHODCALLTYPE CSharpProjectConfigurationProperties3_get_ErrorReport_Proxy( 
    CSharpProjectConfigurationProperties3 * This,
    /* [retval][out] */ BSTR *pbstrErrorReport);


void __RPC_STUB CSharpProjectConfigurationProperties3_get_ErrorReport_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id][propput] */ HRESULT STDMETHODCALLTYPE CSharpProjectConfigurationProperties3_put_ErrorReport_Proxy( 
    CSharpProjectConfigurationProperties3 * This,
    /* [in] */ BSTR bstrErrorReport);


void __RPC_STUB CSharpProjectConfigurationProperties3_put_ErrorReport_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __CSharpProjectConfigurationProperties3_INTERFACE_DEFINED__ */


#ifndef __Reference3_INTERFACE_DEFINED__
#define __Reference3_INTERFACE_DEFINED__

/* interface Reference3 */
/* [uuid][object][oleautomation][dual] */ 


EXTERN_C const IID IID_Reference3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5021602E-2025-4299-88D2-0A92E8B41ADF")
    Reference3 : public Reference2
    {
    public:
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_SpecificVersion( 
            /* [retval][out] */ VARIANT_BOOL *pbSpecificVersion) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_SpecificVersion( 
            /* [in] */ VARIANT_BOOL bSpecificVersion) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_SubType( 
            /* [retval][out] */ BSTR *pbstrSubType) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_SubType( 
            /* [in] */ BSTR bstrSubType) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Isolated( 
            /* [retval][out] */ VARIANT_BOOL *pbIsolated) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Isolated( 
            /* [in] */ VARIANT_BOOL bIsolated) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_Aliases( 
            /* [retval][out] */ BSTR *pbstrAliases) = 0;
        
        virtual /* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE put_Aliases( 
            /* [in] */ BSTR bstrAliases) = 0;
        
        virtual /* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE get_RefType( 
            /* [retval][out] */ PROJECTREFERENCETYPE *pdwProjRefType) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct Reference3Vtbl
    {
        BEGIN_INTERFACE
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            Reference3 * This,
            /* [in][idldescattr] */ struct GUID *riid,
            /* [out][idldescattr] */ void **ppvObj,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *AddRef )( 
            Reference3 * This,
            /* [retval][out] */ unsigned long *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Release )( 
            Reference3 * This,
            /* [retval][out] */ unsigned long *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            Reference3 * This,
            /* [out][idldescattr] */ unsigned UINT *pctinfo,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            Reference3 * This,
            /* [in][idldescattr] */ unsigned UINT itinfo,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [out][idldescattr] */ void **pptinfo,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            Reference3 * This,
            /* [in][idldescattr] */ struct GUID *riid,
            /* [in][idldescattr] */ signed char **rgszNames,
            /* [in][idldescattr] */ unsigned UINT cNames,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [out][idldescattr] */ signed long *rgdispid,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            Reference3 * This,
            /* [in][idldescattr] */ signed long dispidMember,
            /* [in][idldescattr] */ struct GUID *riid,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [in][idldescattr] */ unsigned short wFlags,
            /* [in][idldescattr] */ struct DISPPARAMS *pdispparams,
            /* [out][idldescattr] */ VARIANT *pvarResult,
            /* [out][idldescattr] */ struct EXCEPINFO *pexcepinfo,
            /* [out][idldescattr] */ unsigned UINT *puArgErr,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_DTE )( 
            Reference3 * This,
            /* [retval][out] */ **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Collection )( 
            Reference3 * This,
            /* [retval][out] */ References **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ContainingProject )( 
            Reference3 * This,
            /* [retval][out] */ Project **retval);
        
        /* [id][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Remove )( 
            Reference3 * This,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Name )( 
            Reference3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Type )( 
            Reference3 * This,
            /* [retval][out] */ enum prjReferenceType *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Identity )( 
            Reference3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Path )( 
            Reference3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Description )( 
            Reference3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Culture )( 
            Reference3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_MajorVersion )( 
            Reference3 * This,
            /* [retval][out] */ signed long *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_MinorVersion )( 
            Reference3 * This,
            /* [retval][out] */ signed long *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_RevisionNumber )( 
            Reference3 * This,
            /* [retval][out] */ signed long *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_BuildNumber )( 
            Reference3 * This,
            /* [retval][out] */ signed long *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_StrongName )( 
            Reference3 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_SourceProject )( 
            Reference3 * This,
            /* [retval][out] */ Project **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_CopyLocal )( 
            Reference3 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_CopyLocal )( 
            Reference3 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Extender )( 
            Reference3 * This,
            /* [in][idldescattr] */ BSTR ExtenderName,
            /* [retval][out] */ IDispatch **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ExtenderNames )( 
            Reference3 * This,
            /* [retval][out] */ VARIANT *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ExtenderCATID )( 
            Reference3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_PublicKeyToken )( 
            Reference3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Version )( 
            Reference3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_RuntimeVersion )( 
            Reference3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_SpecificVersion )( 
            Reference3 * This,
            /* [retval][out] */ VARIANT_BOOL *pbSpecificVersion);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_SpecificVersion )( 
            Reference3 * This,
            /* [in] */ VARIANT_BOOL bSpecificVersion);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_SubType )( 
            Reference3 * This,
            /* [retval][out] */ BSTR *pbstrSubType);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_SubType )( 
            Reference3 * This,
            /* [in] */ BSTR bstrSubType);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Isolated )( 
            Reference3 * This,
            /* [retval][out] */ VARIANT_BOOL *pbIsolated);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Isolated )( 
            Reference3 * This,
            /* [in] */ VARIANT_BOOL bIsolated);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_Aliases )( 
            Reference3 * This,
            /* [retval][out] */ BSTR *pbstrAliases);
        
        /* [helpstring][propput][id] */ HRESULT ( STDMETHODCALLTYPE *put_Aliases )( 
            Reference3 * This,
            /* [in] */ BSTR bstrAliases);
        
        /* [helpstring][propget][id] */ HRESULT ( STDMETHODCALLTYPE *get_RefType )( 
            Reference3 * This,
            /* [retval][out] */ PROJECTREFERENCETYPE *pdwProjRefType);
        
        END_INTERFACE
    } Reference3Vtbl;

    interface Reference3
    {
        CONST_VTBL struct Reference3Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define Reference3_QueryInterface(This,riid,ppvObj,retval)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObj,retval)

#define Reference3_AddRef(This,retval)	\
    (This)->lpVtbl -> AddRef(This,retval)

#define Reference3_Release(This,retval)	\
    (This)->lpVtbl -> Release(This,retval)

#define Reference3_GetTypeInfoCount(This,pctinfo,retval)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo,retval)

#define Reference3_GetTypeInfo(This,itinfo,lcid,pptinfo,retval)	\
    (This)->lpVtbl -> GetTypeInfo(This,itinfo,lcid,pptinfo,retval)

#define Reference3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgdispid,retval)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgdispid,retval)

#define Reference3_Invoke(This,dispidMember,riid,lcid,wFlags,pdispparams,pvarResult,pexcepinfo,puArgErr,retval)	\
    (This)->lpVtbl -> Invoke(This,dispidMember,riid,lcid,wFlags,pdispparams,pvarResult,pexcepinfo,puArgErr,retval)

#define Reference3_get_DTE(This,retval)	\
    (This)->lpVtbl -> get_DTE(This,retval)

#define Reference3_get_Collection(This,retval)	\
    (This)->lpVtbl -> get_Collection(This,retval)

#define Reference3_get_ContainingProject(This,retval)	\
    (This)->lpVtbl -> get_ContainingProject(This,retval)

#define Reference3_Remove(This,retval)	\
    (This)->lpVtbl -> Remove(This,retval)

#define Reference3_get_Name(This,retval)	\
    (This)->lpVtbl -> get_Name(This,retval)

#define Reference3_get_Type(This,retval)	\
    (This)->lpVtbl -> get_Type(This,retval)

#define Reference3_get_Identity(This,retval)	\
    (This)->lpVtbl -> get_Identity(This,retval)

#define Reference3_get_Path(This,retval)	\
    (This)->lpVtbl -> get_Path(This,retval)

#define Reference3_get_Description(This,retval)	\
    (This)->lpVtbl -> get_Description(This,retval)

#define Reference3_get_Culture(This,retval)	\
    (This)->lpVtbl -> get_Culture(This,retval)

#define Reference3_get_MajorVersion(This,retval)	\
    (This)->lpVtbl -> get_MajorVersion(This,retval)

#define Reference3_get_MinorVersion(This,retval)	\
    (This)->lpVtbl -> get_MinorVersion(This,retval)

#define Reference3_get_RevisionNumber(This,retval)	\
    (This)->lpVtbl -> get_RevisionNumber(This,retval)

#define Reference3_get_BuildNumber(This,retval)	\
    (This)->lpVtbl -> get_BuildNumber(This,retval)

#define Reference3_get_StrongName(This,retval)	\
    (This)->lpVtbl -> get_StrongName(This,retval)

#define Reference3_get_SourceProject(This,retval)	\
    (This)->lpVtbl -> get_SourceProject(This,retval)

#define Reference3_get_CopyLocal(This,retval)	\
    (This)->lpVtbl -> get_CopyLocal(This,retval)

#define Reference3_put_CopyLocal(This,noname,retval)	\
    (This)->lpVtbl -> put_CopyLocal(This,noname,retval)

#define Reference3_get_Extender(This,ExtenderName,retval)	\
    (This)->lpVtbl -> get_Extender(This,ExtenderName,retval)

#define Reference3_get_ExtenderNames(This,retval)	\
    (This)->lpVtbl -> get_ExtenderNames(This,retval)

#define Reference3_get_ExtenderCATID(This,retval)	\
    (This)->lpVtbl -> get_ExtenderCATID(This,retval)

#define Reference3_get_PublicKeyToken(This,retval)	\
    (This)->lpVtbl -> get_PublicKeyToken(This,retval)

#define Reference3_get_Version(This,retval)	\
    (This)->lpVtbl -> get_Version(This,retval)

#define Reference3_get_RuntimeVersion(This,retval)	\
    (This)->lpVtbl -> get_RuntimeVersion(This,retval)


#define Reference3_get_SpecificVersion(This,pbSpecificVersion)	\
    (This)->lpVtbl -> get_SpecificVersion(This,pbSpecificVersion)

#define Reference3_put_SpecificVersion(This,bSpecificVersion)	\
    (This)->lpVtbl -> put_SpecificVersion(This,bSpecificVersion)

#define Reference3_get_SubType(This,pbstrSubType)	\
    (This)->lpVtbl -> get_SubType(This,pbstrSubType)

#define Reference3_put_SubType(This,bstrSubType)	\
    (This)->lpVtbl -> put_SubType(This,bstrSubType)

#define Reference3_get_Isolated(This,pbIsolated)	\
    (This)->lpVtbl -> get_Isolated(This,pbIsolated)

#define Reference3_put_Isolated(This,bIsolated)	\
    (This)->lpVtbl -> put_Isolated(This,bIsolated)

#define Reference3_get_Aliases(This,pbstrAliases)	\
    (This)->lpVtbl -> get_Aliases(This,pbstrAliases)

#define Reference3_put_Aliases(This,bstrAliases)	\
    (This)->lpVtbl -> put_Aliases(This,bstrAliases)

#define Reference3_get_RefType(This,pdwProjRefType)	\
    (This)->lpVtbl -> get_RefType(This,pdwProjRefType)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE Reference3_get_SpecificVersion_Proxy( 
    Reference3 * This,
    /* [retval][out] */ VARIANT_BOOL *pbSpecificVersion);


void __RPC_STUB Reference3_get_SpecificVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE Reference3_put_SpecificVersion_Proxy( 
    Reference3 * This,
    /* [in] */ VARIANT_BOOL bSpecificVersion);


void __RPC_STUB Reference3_put_SpecificVersion_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE Reference3_get_SubType_Proxy( 
    Reference3 * This,
    /* [retval][out] */ BSTR *pbstrSubType);


void __RPC_STUB Reference3_get_SubType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE Reference3_put_SubType_Proxy( 
    Reference3 * This,
    /* [in] */ BSTR bstrSubType);


void __RPC_STUB Reference3_put_SubType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE Reference3_get_Isolated_Proxy( 
    Reference3 * This,
    /* [retval][out] */ VARIANT_BOOL *pbIsolated);


void __RPC_STUB Reference3_get_Isolated_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE Reference3_put_Isolated_Proxy( 
    Reference3 * This,
    /* [in] */ VARIANT_BOOL bIsolated);


void __RPC_STUB Reference3_put_Isolated_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE Reference3_get_Aliases_Proxy( 
    Reference3 * This,
    /* [retval][out] */ BSTR *pbstrAliases);


void __RPC_STUB Reference3_get_Aliases_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propput][id] */ HRESULT STDMETHODCALLTYPE Reference3_put_Aliases_Proxy( 
    Reference3 * This,
    /* [in] */ BSTR bstrAliases);


void __RPC_STUB Reference3_put_Aliases_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][propget][id] */ HRESULT STDMETHODCALLTYPE Reference3_get_RefType_Proxy( 
    Reference3 * This,
    /* [retval][out] */ PROJECTREFERENCETYPE *pdwProjRefType);


void __RPC_STUB Reference3_get_RefType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __Reference3_INTERFACE_DEFINED__ */


#ifndef __JSharpProjectConfigurationProperties3_INTERFACE_DEFINED__
#define __JSharpProjectConfigurationProperties3_INTERFACE_DEFINED__

/* interface JSharpProjectConfigurationProperties3 */
/* [object][dual][unique][helpstring][uuid] */ 

typedef /* [uuid] */  DECLSPEC_UUID("3600DDB5-34C2-4CED-9337-5B266CC0A169") 
enum prjUTF8Output
    {	prjUTF8OutputOff	= 0,
	prjUTF8OutputOn	= 1
    } 	prjUTF8Output;

#define prjUTF8OutputMin     prjUTF8OutputOff
#define prjUTF8OutputMax     prjUTF8OutputOn
typedef /* [uuid] */  DECLSPEC_UUID("3600DDB6-34C2-4CED-9337-5B266CC0A169") 
enum prjDisableLangXtns
    {	prjDisableLangXtnsNone	= 0,
	prjDisableLangXtnsNET	= prjDisableLangXtnsNone + 1,
	prjDisableLangXtnsAll	= prjDisableLangXtnsNET + 1
    } 	prjDisableLangXtns;

#define prjDisableLangXtnsMin        prjDisableLangXtnsNone
#define prjDisableLangXtnsMax        prjDisableLangXtnsAll
typedef /* [uuid] */  DECLSPEC_UUID("3600DDB8-34C2-4CED-9337-5B266CC0A169") 
enum prjSecureScoping
    {	prjSecureScopingOff	= 0,
	prjSecureScopingOn	= 1
    } 	prjSecureScoping;

#define prjSecureScopingMin      prjSecureScopingOff
#define prjSecureScopingMax      prjSecureScopingOn

EXTERN_C const IID IID_JSharpProjectConfigurationProperties3;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3600DDB7-34C2-4CED-9337-5B266CC0A169")
    JSharpProjectConfigurationProperties3 : public ProjectConfigurationProperties3
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ResponseFile( 
            /* [retval][out] */ BSTR *pbstrResponseFile) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ResponseFile( 
            /* [in] */ BSTR bstrResponseFile) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CodePage( 
            /* [retval][out] */ BSTR *pbstrCodePage) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CodePage( 
            /* [in] */ BSTR bstrCodePage) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_JCPA( 
            /* [retval][out] */ BSTR *pbstrJCPA) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_JCPA( 
            /* [in] */ BSTR bstrJCPA) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RecursePath( 
            /* [retval][out] */ BSTR *pbstrRecursePath) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RecursePath( 
            /* [in] */ BSTR bstrRecursePath) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_UTF8Output( 
            /* [retval][out] */ prjUTF8Output *pUTF8Output) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_UTF8Output( 
            /* [in] */ prjUTF8Output utf8Output) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DisableLangXtns( 
            /* [retval][out] */ prjDisableLangXtns *pDisableLangXtns) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DisableLangXtns( 
            /* [in] */ prjDisableLangXtns DisableLangXtns) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_SecureScoping( 
            /* [retval][out] */ prjSecureScoping *pSecureScoping) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_SecureScoping( 
            /* [in] */ prjSecureScoping SecureScoping) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct JSharpProjectConfigurationProperties3Vtbl
    {
        BEGIN_INTERFACE
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ struct GUID *riid,
            /* [out][idldescattr] */ void **ppvObj,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *AddRef )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ unsigned long *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Release )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ unsigned long *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [out][idldescattr] */ unsigned UINT *pctinfo,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ unsigned UINT itinfo,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [out][idldescattr] */ void **pptinfo,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ struct GUID *riid,
            /* [in][idldescattr] */ signed char **rgszNames,
            /* [in][idldescattr] */ unsigned UINT cNames,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [out][idldescattr] */ signed long *rgdispid,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ signed long dispidMember,
            /* [in][idldescattr] */ struct GUID *riid,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [in][idldescattr] */ unsigned short wFlags,
            /* [in][idldescattr] */ struct DISPPARAMS *pdispparams,
            /* [out][idldescattr] */ VARIANT *pvarResult,
            /* [out][idldescattr] */ struct EXCEPINFO *pexcepinfo,
            /* [out][idldescattr] */ unsigned UINT *puArgErr,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][hidden][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get___id )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_DebugSymbols )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_DebugSymbols )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_DefineDebug )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_DefineDebug )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_DefineTrace )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_DefineTrace )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_OutputPath )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_OutputPath )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_IntermediatePath )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][hidden][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_IntermediatePath )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_DefineConstants )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_DefineConstants )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_RemoveIntegerChecks )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_RemoveIntegerChecks )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_BaseAddress )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ unsigned long *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_BaseAddress )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ unsigned long noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_AllowUnsafeBlocks )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_AllowUnsafeBlocks )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_CheckForOverflowUnderflow )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_CheckForOverflowUnderflow )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_DocumentationFile )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_DocumentationFile )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Optimize )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_Optimize )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_IncrementalBuild )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_IncrementalBuild )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_StartProgram )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_StartProgram )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_StartWorkingDirectory )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_StartWorkingDirectory )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_StartURL )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_StartURL )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_StartPage )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_StartPage )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_StartArguments )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_StartArguments )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_StartWithIE )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_StartWithIE )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_EnableASPDebugging )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_EnableASPDebugging )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_EnableASPXDebugging )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_EnableASPXDebugging )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_EnableUnmanagedDebugging )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_EnableUnmanagedDebugging )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_StartAction )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ enum prjStartAction *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_StartAction )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ enum prjStartAction noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Extender )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BSTR ExtenderName,
            /* [retval][out] */ IDispatch **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ExtenderNames )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ VARIANT *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ExtenderCATID )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_WarningLevel )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ enum prjWarningLevel *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_WarningLevel )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ enum prjWarningLevel noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_TreatWarningsAsErrors )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_TreatWarningsAsErrors )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_EnableSQLServerDebugging )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_EnableSQLServerDebugging )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_FileAlignment )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ unsigned long *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_FileAlignment )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ unsigned long noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_RegisterForComInterop )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_RegisterForComInterop )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ConfigurationOverrideFile )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_ConfigurationOverrideFile )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_RemoteDebugEnabled )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_RemoteDebugEnabled )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_RemoteDebugMachine )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_RemoteDebugMachine )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_NoWarn )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_NoWarn )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_NoStdLib )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_NoStdLib )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [in][idldescattr] */ BOOLEAN noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DebugInfo )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BSTR *pbstrDebugInfo);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DebugInfo )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [in] */ BSTR bstrDebugInfo);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_PlatformTarget )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BSTR *pbstrPlatformTarget);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_PlatformTarget )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [in] */ BSTR bstrPlatformTarget);
        
        /* [id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_TreatSpecificWarningsAsErrors )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BSTR *pbstrWarningsAsErrors);
        
        /* [id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_TreatSpecificWarningsAsErrors )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [in] */ BSTR bstrWarningsAsErrors);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ResponseFile )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BSTR *pbstrResponseFile);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ResponseFile )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [in] */ BSTR bstrResponseFile);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CodePage )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BSTR *pbstrCodePage);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CodePage )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [in] */ BSTR bstrCodePage);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_JCPA )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BSTR *pbstrJCPA);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_JCPA )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [in] */ BSTR bstrJCPA);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_RecursePath )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ BSTR *pbstrRecursePath);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_RecursePath )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [in] */ BSTR bstrRecursePath);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_UTF8Output )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ prjUTF8Output *pUTF8Output);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_UTF8Output )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [in] */ prjUTF8Output utf8Output);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_DisableLangXtns )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ prjDisableLangXtns *pDisableLangXtns);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_DisableLangXtns )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [in] */ prjDisableLangXtns DisableLangXtns);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_SecureScoping )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [retval][out] */ prjSecureScoping *pSecureScoping);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_SecureScoping )( 
            JSharpProjectConfigurationProperties3 * This,
            /* [in] */ prjSecureScoping SecureScoping);
        
        END_INTERFACE
    } JSharpProjectConfigurationProperties3Vtbl;

    interface JSharpProjectConfigurationProperties3
    {
        CONST_VTBL struct JSharpProjectConfigurationProperties3Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define JSharpProjectConfigurationProperties3_QueryInterface(This,riid,ppvObj,retval)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObj,retval)

#define JSharpProjectConfigurationProperties3_AddRef(This,retval)	\
    (This)->lpVtbl -> AddRef(This,retval)

#define JSharpProjectConfigurationProperties3_Release(This,retval)	\
    (This)->lpVtbl -> Release(This,retval)

#define JSharpProjectConfigurationProperties3_GetTypeInfoCount(This,pctinfo,retval)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo,retval)

#define JSharpProjectConfigurationProperties3_GetTypeInfo(This,itinfo,lcid,pptinfo,retval)	\
    (This)->lpVtbl -> GetTypeInfo(This,itinfo,lcid,pptinfo,retval)

#define JSharpProjectConfigurationProperties3_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgdispid,retval)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgdispid,retval)

#define JSharpProjectConfigurationProperties3_Invoke(This,dispidMember,riid,lcid,wFlags,pdispparams,pvarResult,pexcepinfo,puArgErr,retval)	\
    (This)->lpVtbl -> Invoke(This,dispidMember,riid,lcid,wFlags,pdispparams,pvarResult,pexcepinfo,puArgErr,retval)

#define JSharpProjectConfigurationProperties3_get___id(This,retval)	\
    (This)->lpVtbl -> get___id(This,retval)

#define JSharpProjectConfigurationProperties3_get_DebugSymbols(This,retval)	\
    (This)->lpVtbl -> get_DebugSymbols(This,retval)

#define JSharpProjectConfigurationProperties3_put_DebugSymbols(This,noname,retval)	\
    (This)->lpVtbl -> put_DebugSymbols(This,noname,retval)

#define JSharpProjectConfigurationProperties3_get_DefineDebug(This,retval)	\
    (This)->lpVtbl -> get_DefineDebug(This,retval)

#define JSharpProjectConfigurationProperties3_put_DefineDebug(This,noname,retval)	\
    (This)->lpVtbl -> put_DefineDebug(This,noname,retval)

#define JSharpProjectConfigurationProperties3_get_DefineTrace(This,retval)	\
    (This)->lpVtbl -> get_DefineTrace(This,retval)

#define JSharpProjectConfigurationProperties3_put_DefineTrace(This,noname,retval)	\
    (This)->lpVtbl -> put_DefineTrace(This,noname,retval)

#define JSharpProjectConfigurationProperties3_get_OutputPath(This,retval)	\
    (This)->lpVtbl -> get_OutputPath(This,retval)

#define JSharpProjectConfigurationProperties3_put_OutputPath(This,noname,retval)	\
    (This)->lpVtbl -> put_OutputPath(This,noname,retval)

#define JSharpProjectConfigurationProperties3_get_IntermediatePath(This,retval)	\
    (This)->lpVtbl -> get_IntermediatePath(This,retval)

#define JSharpProjectConfigurationProperties3_put_IntermediatePath(This,noname,retval)	\
    (This)->lpVtbl -> put_IntermediatePath(This,noname,retval)

#define JSharpProjectConfigurationProperties3_get_DefineConstants(This,retval)	\
    (This)->lpVtbl -> get_DefineConstants(This,retval)

#define JSharpProjectConfigurationProperties3_put_DefineConstants(This,noname,retval)	\
    (This)->lpVtbl -> put_DefineConstants(This,noname,retval)

#define JSharpProjectConfigurationProperties3_get_RemoveIntegerChecks(This,retval)	\
    (This)->lpVtbl -> get_RemoveIntegerChecks(This,retval)

#define JSharpProjectConfigurationProperties3_put_RemoveIntegerChecks(This,noname,retval)	\
    (This)->lpVtbl -> put_RemoveIntegerChecks(This,noname,retval)

#define JSharpProjectConfigurationProperties3_get_BaseAddress(This,retval)	\
    (This)->lpVtbl -> get_BaseAddress(This,retval)

#define JSharpProjectConfigurationProperties3_put_BaseAddress(This,noname,retval)	\
    (This)->lpVtbl -> put_BaseAddress(This,noname,retval)

#define JSharpProjectConfigurationProperties3_get_AllowUnsafeBlocks(This,retval)	\
    (This)->lpVtbl -> get_AllowUnsafeBlocks(This,retval)

#define JSharpProjectConfigurationProperties3_put_AllowUnsafeBlocks(This,noname,retval)	\
    (This)->lpVtbl -> put_AllowUnsafeBlocks(This,noname,retval)

#define JSharpProjectConfigurationProperties3_get_CheckForOverflowUnderflow(This,retval)	\
    (This)->lpVtbl -> get_CheckForOverflowUnderflow(This,retval)

#define JSharpProjectConfigurationProperties3_put_CheckForOverflowUnderflow(This,noname,retval)	\
    (This)->lpVtbl -> put_CheckForOverflowUnderflow(This,noname,retval)

#define JSharpProjectConfigurationProperties3_get_DocumentationFile(This,retval)	\
    (This)->lpVtbl -> get_DocumentationFile(This,retval)

#define JSharpProjectConfigurationProperties3_put_DocumentationFile(This,noname,retval)	\
    (This)->lpVtbl -> put_DocumentationFile(This,noname,retval)

#define JSharpProjectConfigurationProperties3_get_Optimize(This,retval)	\
    (This)->lpVtbl -> get_Optimize(This,retval)

#define JSharpProjectConfigurationProperties3_put_Optimize(This,noname,retval)	\
    (This)->lpVtbl -> put_Optimize(This,noname,retval)

#define JSharpProjectConfigurationProperties3_get_IncrementalBuild(This,retval)	\
    (This)->lpVtbl -> get_IncrementalBuild(This,retval)

#define JSharpProjectConfigurationProperties3_put_IncrementalBuild(This,noname,retval)	\
    (This)->lpVtbl -> put_IncrementalBuild(This,noname,retval)

#define JSharpProjectConfigurationProperties3_get_StartProgram(This,retval)	\
    (This)->lpVtbl -> get_StartProgram(This,retval)

#define JSharpProjectConfigurationProperties3_put_StartProgram(This,noname,retval)	\
    (This)->lpVtbl -> put_StartProgram(This,noname,retval)

#define JSharpProjectConfigurationProperties3_get_StartWorkingDirectory(This,retval)	\
    (This)->lpVtbl -> get_StartWorkingDirectory(This,retval)

#define JSharpProjectConfigurationProperties3_put_StartWorkingDirectory(This,noname,retval)	\
    (This)->lpVtbl -> put_StartWorkingDirectory(This,noname,retval)

#define JSharpProjectConfigurationProperties3_get_StartURL(This,retval)	\
    (This)->lpVtbl -> get_StartURL(This,retval)

#define JSharpProjectConfigurationProperties3_put_StartURL(This,noname,retval)	\
    (This)->lpVtbl -> put_StartURL(This,noname,retval)

#define JSharpProjectConfigurationProperties3_get_StartPage(This,retval)	\
    (This)->lpVtbl -> get_StartPage(This,retval)

#define JSharpProjectConfigurationProperties3_put_StartPage(This,noname,retval)	\
    (This)->lpVtbl -> put_StartPage(This,noname,retval)

#define JSharpProjectConfigurationProperties3_get_StartArguments(This,retval)	\
    (This)->lpVtbl -> get_StartArguments(This,retval)

#define JSharpProjectConfigurationProperties3_put_StartArguments(This,noname,retval)	\
    (This)->lpVtbl -> put_StartArguments(This,noname,retval)

#define JSharpProjectConfigurationProperties3_get_StartWithIE(This,retval)	\
    (This)->lpVtbl -> get_StartWithIE(This,retval)

#define JSharpProjectConfigurationProperties3_put_StartWithIE(This,noname,retval)	\
    (This)->lpVtbl -> put_StartWithIE(This,noname,retval)

#define JSharpProjectConfigurationProperties3_get_EnableASPDebugging(This,retval)	\
    (This)->lpVtbl -> get_EnableASPDebugging(This,retval)

#define JSharpProjectConfigurationProperties3_put_EnableASPDebugging(This,noname,retval)	\
    (This)->lpVtbl -> put_EnableASPDebugging(This,noname,retval)

#define JSharpProjectConfigurationProperties3_get_EnableASPXDebugging(This,retval)	\
    (This)->lpVtbl -> get_EnableASPXDebugging(This,retval)

#define JSharpProjectConfigurationProperties3_put_EnableASPXDebugging(This,noname,retval)	\
    (This)->lpVtbl -> put_EnableASPXDebugging(This,noname,retval)

#define JSharpProjectConfigurationProperties3_get_EnableUnmanagedDebugging(This,retval)	\
    (This)->lpVtbl -> get_EnableUnmanagedDebugging(This,retval)

#define JSharpProjectConfigurationProperties3_put_EnableUnmanagedDebugging(This,noname,retval)	\
    (This)->lpVtbl -> put_EnableUnmanagedDebugging(This,noname,retval)

#define JSharpProjectConfigurationProperties3_get_StartAction(This,retval)	\
    (This)->lpVtbl -> get_StartAction(This,retval)

#define JSharpProjectConfigurationProperties3_put_StartAction(This,noname,retval)	\
    (This)->lpVtbl -> put_StartAction(This,noname,retval)

#define JSharpProjectConfigurationProperties3_get_Extender(This,ExtenderName,retval)	\
    (This)->lpVtbl -> get_Extender(This,ExtenderName,retval)

#define JSharpProjectConfigurationProperties3_get_ExtenderNames(This,retval)	\
    (This)->lpVtbl -> get_ExtenderNames(This,retval)

#define JSharpProjectConfigurationProperties3_get_ExtenderCATID(This,retval)	\
    (This)->lpVtbl -> get_ExtenderCATID(This,retval)

#define JSharpProjectConfigurationProperties3_get_WarningLevel(This,retval)	\
    (This)->lpVtbl -> get_WarningLevel(This,retval)

#define JSharpProjectConfigurationProperties3_put_WarningLevel(This,noname,retval)	\
    (This)->lpVtbl -> put_WarningLevel(This,noname,retval)

#define JSharpProjectConfigurationProperties3_get_TreatWarningsAsErrors(This,retval)	\
    (This)->lpVtbl -> get_TreatWarningsAsErrors(This,retval)

#define JSharpProjectConfigurationProperties3_put_TreatWarningsAsErrors(This,noname,retval)	\
    (This)->lpVtbl -> put_TreatWarningsAsErrors(This,noname,retval)

#define JSharpProjectConfigurationProperties3_get_EnableSQLServerDebugging(This,retval)	\
    (This)->lpVtbl -> get_EnableSQLServerDebugging(This,retval)

#define JSharpProjectConfigurationProperties3_put_EnableSQLServerDebugging(This,noname,retval)	\
    (This)->lpVtbl -> put_EnableSQLServerDebugging(This,noname,retval)

#define JSharpProjectConfigurationProperties3_get_FileAlignment(This,retval)	\
    (This)->lpVtbl -> get_FileAlignment(This,retval)

#define JSharpProjectConfigurationProperties3_put_FileAlignment(This,noname,retval)	\
    (This)->lpVtbl -> put_FileAlignment(This,noname,retval)

#define JSharpProjectConfigurationProperties3_get_RegisterForComInterop(This,retval)	\
    (This)->lpVtbl -> get_RegisterForComInterop(This,retval)

#define JSharpProjectConfigurationProperties3_put_RegisterForComInterop(This,noname,retval)	\
    (This)->lpVtbl -> put_RegisterForComInterop(This,noname,retval)

#define JSharpProjectConfigurationProperties3_get_ConfigurationOverrideFile(This,retval)	\
    (This)->lpVtbl -> get_ConfigurationOverrideFile(This,retval)

#define JSharpProjectConfigurationProperties3_put_ConfigurationOverrideFile(This,noname,retval)	\
    (This)->lpVtbl -> put_ConfigurationOverrideFile(This,noname,retval)

#define JSharpProjectConfigurationProperties3_get_RemoteDebugEnabled(This,retval)	\
    (This)->lpVtbl -> get_RemoteDebugEnabled(This,retval)

#define JSharpProjectConfigurationProperties3_put_RemoteDebugEnabled(This,noname,retval)	\
    (This)->lpVtbl -> put_RemoteDebugEnabled(This,noname,retval)

#define JSharpProjectConfigurationProperties3_get_RemoteDebugMachine(This,retval)	\
    (This)->lpVtbl -> get_RemoteDebugMachine(This,retval)

#define JSharpProjectConfigurationProperties3_put_RemoteDebugMachine(This,noname,retval)	\
    (This)->lpVtbl -> put_RemoteDebugMachine(This,noname,retval)

#define JSharpProjectConfigurationProperties3_get_NoWarn(This,retval)	\
    (This)->lpVtbl -> get_NoWarn(This,retval)

#define JSharpProjectConfigurationProperties3_put_NoWarn(This,noname,retval)	\
    (This)->lpVtbl -> put_NoWarn(This,noname,retval)

#define JSharpProjectConfigurationProperties3_get_NoStdLib(This,retval)	\
    (This)->lpVtbl -> get_NoStdLib(This,retval)

#define JSharpProjectConfigurationProperties3_put_NoStdLib(This,noname,retval)	\
    (This)->lpVtbl -> put_NoStdLib(This,noname,retval)


#define JSharpProjectConfigurationProperties3_get_DebugInfo(This,pbstrDebugInfo)	\
    (This)->lpVtbl -> get_DebugInfo(This,pbstrDebugInfo)

#define JSharpProjectConfigurationProperties3_put_DebugInfo(This,bstrDebugInfo)	\
    (This)->lpVtbl -> put_DebugInfo(This,bstrDebugInfo)

#define JSharpProjectConfigurationProperties3_get_PlatformTarget(This,pbstrPlatformTarget)	\
    (This)->lpVtbl -> get_PlatformTarget(This,pbstrPlatformTarget)

#define JSharpProjectConfigurationProperties3_put_PlatformTarget(This,bstrPlatformTarget)	\
    (This)->lpVtbl -> put_PlatformTarget(This,bstrPlatformTarget)

#define JSharpProjectConfigurationProperties3_get_TreatSpecificWarningsAsErrors(This,pbstrWarningsAsErrors)	\
    (This)->lpVtbl -> get_TreatSpecificWarningsAsErrors(This,pbstrWarningsAsErrors)

#define JSharpProjectConfigurationProperties3_put_TreatSpecificWarningsAsErrors(This,bstrWarningsAsErrors)	\
    (This)->lpVtbl -> put_TreatSpecificWarningsAsErrors(This,bstrWarningsAsErrors)


#define JSharpProjectConfigurationProperties3_get_ResponseFile(This,pbstrResponseFile)	\
    (This)->lpVtbl -> get_ResponseFile(This,pbstrResponseFile)

#define JSharpProjectConfigurationProperties3_put_ResponseFile(This,bstrResponseFile)	\
    (This)->lpVtbl -> put_ResponseFile(This,bstrResponseFile)

#define JSharpProjectConfigurationProperties3_get_CodePage(This,pbstrCodePage)	\
    (This)->lpVtbl -> get_CodePage(This,pbstrCodePage)

#define JSharpProjectConfigurationProperties3_put_CodePage(This,bstrCodePage)	\
    (This)->lpVtbl -> put_CodePage(This,bstrCodePage)

#define JSharpProjectConfigurationProperties3_get_JCPA(This,pbstrJCPA)	\
    (This)->lpVtbl -> get_JCPA(This,pbstrJCPA)

#define JSharpProjectConfigurationProperties3_put_JCPA(This,bstrJCPA)	\
    (This)->lpVtbl -> put_JCPA(This,bstrJCPA)

#define JSharpProjectConfigurationProperties3_get_RecursePath(This,pbstrRecursePath)	\
    (This)->lpVtbl -> get_RecursePath(This,pbstrRecursePath)

#define JSharpProjectConfigurationProperties3_put_RecursePath(This,bstrRecursePath)	\
    (This)->lpVtbl -> put_RecursePath(This,bstrRecursePath)

#define JSharpProjectConfigurationProperties3_get_UTF8Output(This,pUTF8Output)	\
    (This)->lpVtbl -> get_UTF8Output(This,pUTF8Output)

#define JSharpProjectConfigurationProperties3_put_UTF8Output(This,utf8Output)	\
    (This)->lpVtbl -> put_UTF8Output(This,utf8Output)

#define JSharpProjectConfigurationProperties3_get_DisableLangXtns(This,pDisableLangXtns)	\
    (This)->lpVtbl -> get_DisableLangXtns(This,pDisableLangXtns)

#define JSharpProjectConfigurationProperties3_put_DisableLangXtns(This,DisableLangXtns)	\
    (This)->lpVtbl -> put_DisableLangXtns(This,DisableLangXtns)

#define JSharpProjectConfigurationProperties3_get_SecureScoping(This,pSecureScoping)	\
    (This)->lpVtbl -> get_SecureScoping(This,pSecureScoping)

#define JSharpProjectConfigurationProperties3_put_SecureScoping(This,SecureScoping)	\
    (This)->lpVtbl -> put_SecureScoping(This,SecureScoping)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE JSharpProjectConfigurationProperties3_get_ResponseFile_Proxy( 
    JSharpProjectConfigurationProperties3 * This,
    /* [retval][out] */ BSTR *pbstrResponseFile);


void __RPC_STUB JSharpProjectConfigurationProperties3_get_ResponseFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE JSharpProjectConfigurationProperties3_put_ResponseFile_Proxy( 
    JSharpProjectConfigurationProperties3 * This,
    /* [in] */ BSTR bstrResponseFile);


void __RPC_STUB JSharpProjectConfigurationProperties3_put_ResponseFile_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE JSharpProjectConfigurationProperties3_get_CodePage_Proxy( 
    JSharpProjectConfigurationProperties3 * This,
    /* [retval][out] */ BSTR *pbstrCodePage);


void __RPC_STUB JSharpProjectConfigurationProperties3_get_CodePage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE JSharpProjectConfigurationProperties3_put_CodePage_Proxy( 
    JSharpProjectConfigurationProperties3 * This,
    /* [in] */ BSTR bstrCodePage);


void __RPC_STUB JSharpProjectConfigurationProperties3_put_CodePage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE JSharpProjectConfigurationProperties3_get_JCPA_Proxy( 
    JSharpProjectConfigurationProperties3 * This,
    /* [retval][out] */ BSTR *pbstrJCPA);


void __RPC_STUB JSharpProjectConfigurationProperties3_get_JCPA_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE JSharpProjectConfigurationProperties3_put_JCPA_Proxy( 
    JSharpProjectConfigurationProperties3 * This,
    /* [in] */ BSTR bstrJCPA);


void __RPC_STUB JSharpProjectConfigurationProperties3_put_JCPA_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE JSharpProjectConfigurationProperties3_get_RecursePath_Proxy( 
    JSharpProjectConfigurationProperties3 * This,
    /* [retval][out] */ BSTR *pbstrRecursePath);


void __RPC_STUB JSharpProjectConfigurationProperties3_get_RecursePath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE JSharpProjectConfigurationProperties3_put_RecursePath_Proxy( 
    JSharpProjectConfigurationProperties3 * This,
    /* [in] */ BSTR bstrRecursePath);


void __RPC_STUB JSharpProjectConfigurationProperties3_put_RecursePath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE JSharpProjectConfigurationProperties3_get_UTF8Output_Proxy( 
    JSharpProjectConfigurationProperties3 * This,
    /* [retval][out] */ prjUTF8Output *pUTF8Output);


void __RPC_STUB JSharpProjectConfigurationProperties3_get_UTF8Output_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE JSharpProjectConfigurationProperties3_put_UTF8Output_Proxy( 
    JSharpProjectConfigurationProperties3 * This,
    /* [in] */ prjUTF8Output utf8Output);


void __RPC_STUB JSharpProjectConfigurationProperties3_put_UTF8Output_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE JSharpProjectConfigurationProperties3_get_DisableLangXtns_Proxy( 
    JSharpProjectConfigurationProperties3 * This,
    /* [retval][out] */ prjDisableLangXtns *pDisableLangXtns);


void __RPC_STUB JSharpProjectConfigurationProperties3_get_DisableLangXtns_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE JSharpProjectConfigurationProperties3_put_DisableLangXtns_Proxy( 
    JSharpProjectConfigurationProperties3 * This,
    /* [in] */ prjDisableLangXtns DisableLangXtns);


void __RPC_STUB JSharpProjectConfigurationProperties3_put_DisableLangXtns_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE JSharpProjectConfigurationProperties3_get_SecureScoping_Proxy( 
    JSharpProjectConfigurationProperties3 * This,
    /* [retval][out] */ prjSecureScoping *pSecureScoping);


void __RPC_STUB JSharpProjectConfigurationProperties3_get_SecureScoping_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE JSharpProjectConfigurationProperties3_put_SecureScoping_Proxy( 
    JSharpProjectConfigurationProperties3 * This,
    /* [in] */ prjSecureScoping SecureScoping);


void __RPC_STUB JSharpProjectConfigurationProperties3_put_SecureScoping_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __JSharpProjectConfigurationProperties3_INTERFACE_DEFINED__ */


#ifndef __FolderProperties2_INTERFACE_DEFINED__
#define __FolderProperties2_INTERFACE_DEFINED__

/* interface FolderProperties2 */
/* [local][hidden][unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_FolderProperties2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("2ACA2576-0738-466f-845F-16062ED8D1BC")
    FolderProperties2 : public FolderProperties
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_WebReferenceInterface( 
            /* [retval][out] */ IUnknown **ppWebReference) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct FolderProperties2Vtbl
    {
        BEGIN_INTERFACE
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            FolderProperties2 * This,
            /* [in][idldescattr] */ struct GUID *riid,
            /* [out][idldescattr] */ void **ppvObj,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *AddRef )( 
            FolderProperties2 * This,
            /* [retval][out] */ unsigned long *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Release )( 
            FolderProperties2 * This,
            /* [retval][out] */ unsigned long *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            FolderProperties2 * This,
            /* [out][idldescattr] */ unsigned UINT *pctinfo,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            FolderProperties2 * This,
            /* [in][idldescattr] */ unsigned UINT itinfo,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [out][idldescattr] */ void **pptinfo,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            FolderProperties2 * This,
            /* [in][idldescattr] */ struct GUID *riid,
            /* [in][idldescattr] */ signed char **rgszNames,
            /* [in][idldescattr] */ unsigned UINT cNames,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [out][idldescattr] */ signed long *rgdispid,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            FolderProperties2 * This,
            /* [in][idldescattr] */ signed long dispidMember,
            /* [in][idldescattr] */ struct GUID *riid,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [in][idldescattr] */ unsigned short wFlags,
            /* [in][idldescattr] */ struct DISPPARAMS *pdispparams,
            /* [out][idldescattr] */ VARIANT *pvarResult,
            /* [out][idldescattr] */ struct EXCEPINFO *pexcepinfo,
            /* [out][idldescattr] */ unsigned UINT *puArgErr,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][hidden][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get___id )( 
            FolderProperties2 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_FileName )( 
            FolderProperties2 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_FileName )( 
            FolderProperties2 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_LocalPath )( 
            FolderProperties2 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_FullPath )( 
            FolderProperties2 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_URL )( 
            FolderProperties2 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Extender )( 
            FolderProperties2 * This,
            /* [in][idldescattr] */ BSTR ExtenderName,
            /* [retval][out] */ IDispatch **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ExtenderNames )( 
            FolderProperties2 * This,
            /* [retval][out] */ VARIANT *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ExtenderCATID )( 
            FolderProperties2 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_WebReference )( 
            FolderProperties2 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_WebReference )( 
            FolderProperties2 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_DefaultNamespace )( 
            FolderProperties2 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_UrlBehavior )( 
            FolderProperties2 * This,
            /* [retval][out] */ enum webrefUrlBehavior *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_UrlBehavior )( 
            FolderProperties2 * This,
            /* [in][idldescattr] */ enum webrefUrlBehavior noname,
            /* [retval][out] */ void *retval);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_WebReferenceInterface )( 
            FolderProperties2 * This,
            /* [retval][out] */ IUnknown **ppWebReference);
        
        END_INTERFACE
    } FolderProperties2Vtbl;

    interface FolderProperties2
    {
        CONST_VTBL struct FolderProperties2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define FolderProperties2_QueryInterface(This,riid,ppvObj,retval)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObj,retval)

#define FolderProperties2_AddRef(This,retval)	\
    (This)->lpVtbl -> AddRef(This,retval)

#define FolderProperties2_Release(This,retval)	\
    (This)->lpVtbl -> Release(This,retval)

#define FolderProperties2_GetTypeInfoCount(This,pctinfo,retval)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo,retval)

#define FolderProperties2_GetTypeInfo(This,itinfo,lcid,pptinfo,retval)	\
    (This)->lpVtbl -> GetTypeInfo(This,itinfo,lcid,pptinfo,retval)

#define FolderProperties2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgdispid,retval)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgdispid,retval)

#define FolderProperties2_Invoke(This,dispidMember,riid,lcid,wFlags,pdispparams,pvarResult,pexcepinfo,puArgErr,retval)	\
    (This)->lpVtbl -> Invoke(This,dispidMember,riid,lcid,wFlags,pdispparams,pvarResult,pexcepinfo,puArgErr,retval)

#define FolderProperties2_get___id(This,retval)	\
    (This)->lpVtbl -> get___id(This,retval)

#define FolderProperties2_get_FileName(This,retval)	\
    (This)->lpVtbl -> get_FileName(This,retval)

#define FolderProperties2_put_FileName(This,noname,retval)	\
    (This)->lpVtbl -> put_FileName(This,noname,retval)

#define FolderProperties2_get_LocalPath(This,retval)	\
    (This)->lpVtbl -> get_LocalPath(This,retval)

#define FolderProperties2_get_FullPath(This,retval)	\
    (This)->lpVtbl -> get_FullPath(This,retval)

#define FolderProperties2_get_URL(This,retval)	\
    (This)->lpVtbl -> get_URL(This,retval)

#define FolderProperties2_get_Extender(This,ExtenderName,retval)	\
    (This)->lpVtbl -> get_Extender(This,ExtenderName,retval)

#define FolderProperties2_get_ExtenderNames(This,retval)	\
    (This)->lpVtbl -> get_ExtenderNames(This,retval)

#define FolderProperties2_get_ExtenderCATID(This,retval)	\
    (This)->lpVtbl -> get_ExtenderCATID(This,retval)

#define FolderProperties2_get_WebReference(This,retval)	\
    (This)->lpVtbl -> get_WebReference(This,retval)

#define FolderProperties2_put_WebReference(This,noname,retval)	\
    (This)->lpVtbl -> put_WebReference(This,noname,retval)

#define FolderProperties2_get_DefaultNamespace(This,retval)	\
    (This)->lpVtbl -> get_DefaultNamespace(This,retval)

#define FolderProperties2_get_UrlBehavior(This,retval)	\
    (This)->lpVtbl -> get_UrlBehavior(This,retval)

#define FolderProperties2_put_UrlBehavior(This,noname,retval)	\
    (This)->lpVtbl -> put_UrlBehavior(This,noname,retval)


#define FolderProperties2_get_WebReferenceInterface(This,ppWebReference)	\
    (This)->lpVtbl -> get_WebReferenceInterface(This,ppWebReference)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE FolderProperties2_get_WebReferenceInterface_Proxy( 
    FolderProperties2 * This,
    /* [retval][out] */ IUnknown **ppWebReference);


void __RPC_STUB FolderProperties2_get_WebReferenceInterface_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __FolderProperties2_INTERFACE_DEFINED__ */


#ifndef __FileProperties2_INTERFACE_DEFINED__
#define __FileProperties2_INTERFACE_DEFINED__

/* interface FileProperties2 */
/* [object][dual][unique][helpstring][uuid] */ 


EXTERN_C const IID IID_FileProperties2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("41BE8D4D-F235-46d4-B9F8-C6D6459D503C")
    FileProperties2 : public FileProperties
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_CopyToOutputDirectory( 
            /* [retval][out] */ VARIANT_BOOL *pfCopy) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_CopyToOutputDirectory( 
            /* [in] */ VARIANT_BOOL fCopy) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ItemType( 
            /* [retval][out] */ BSTR *pbstrItemType) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ItemType( 
            /* [in] */ BSTR bstrItemType) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct FileProperties2Vtbl
    {
        BEGIN_INTERFACE
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            FileProperties2 * This,
            /* [in][idldescattr] */ struct GUID *riid,
            /* [out][idldescattr] */ void **ppvObj,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *AddRef )( 
            FileProperties2 * This,
            /* [retval][out] */ unsigned long *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Release )( 
            FileProperties2 * This,
            /* [retval][out] */ unsigned long *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            FileProperties2 * This,
            /* [out][idldescattr] */ unsigned UINT *pctinfo,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            FileProperties2 * This,
            /* [in][idldescattr] */ unsigned UINT itinfo,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [out][idldescattr] */ void **pptinfo,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            FileProperties2 * This,
            /* [in][idldescattr] */ struct GUID *riid,
            /* [in][idldescattr] */ signed char **rgszNames,
            /* [in][idldescattr] */ unsigned UINT cNames,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [out][idldescattr] */ signed long *rgdispid,
            /* [retval][out] */ void *retval);
        
        /* [id][restricted][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            FileProperties2 * This,
            /* [in][idldescattr] */ signed long dispidMember,
            /* [in][idldescattr] */ struct GUID *riid,
            /* [in][idldescattr] */ unsigned long lcid,
            /* [in][idldescattr] */ unsigned short wFlags,
            /* [in][idldescattr] */ struct DISPPARAMS *pdispparams,
            /* [out][idldescattr] */ VARIANT *pvarResult,
            /* [out][idldescattr] */ struct EXCEPINFO *pexcepinfo,
            /* [out][idldescattr] */ unsigned UINT *puArgErr,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][hidden][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get___id )( 
            FileProperties2 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_FileName )( 
            FileProperties2 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_FileName )( 
            FileProperties2 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Extension )( 
            FileProperties2 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Filesize )( 
            FileProperties2 * This,
            /* [retval][out] */ unsigned long *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_LocalPath )( 
            FileProperties2 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_FullPath )( 
            FileProperties2 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_URL )( 
            FileProperties2 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_HTMLTitle )( 
            FileProperties2 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Author )( 
            FileProperties2 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_DateCreated )( 
            FileProperties2 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_DateModified )( 
            FileProperties2 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ModifiedBy )( 
            FileProperties2 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_SubType )( 
            FileProperties2 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_SubType )( 
            FileProperties2 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_Extender )( 
            FileProperties2 * This,
            /* [in][idldescattr] */ BSTR ExtenderName,
            /* [retval][out] */ IDispatch **retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ExtenderNames )( 
            FileProperties2 * This,
            /* [retval][out] */ VARIANT *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_ExtenderCATID )( 
            FileProperties2 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_BuildAction )( 
            FileProperties2 * This,
            /* [retval][out] */ enum prjBuildAction *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_BuildAction )( 
            FileProperties2 * This,
            /* [in][idldescattr] */ enum prjBuildAction noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_CustomTool )( 
            FileProperties2 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_CustomTool )( 
            FileProperties2 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_CustomToolNamespace )( 
            FileProperties2 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propput][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *put_CustomToolNamespace )( 
            FileProperties2 * This,
            /* [in][idldescattr] */ BSTR noname,
            /* [retval][out] */ void *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_CustomToolOutput )( 
            FileProperties2 * This,
            /* [retval][out] */ BSTR *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_IsCustomToolOutput )( 
            FileProperties2 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_IsDependentFile )( 
            FileProperties2 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_IsLink )( 
            FileProperties2 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [id][propget][funcdescattr] */ HRESULT ( STDMETHODCALLTYPE *get_IsDesignTimeBuildInput )( 
            FileProperties2 * This,
            /* [retval][out] */ BOOLEAN *retval);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_CopyToOutputDirectory )( 
            FileProperties2 * This,
            /* [retval][out] */ VARIANT_BOOL *pfCopy);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_CopyToOutputDirectory )( 
            FileProperties2 * This,
            /* [in] */ VARIANT_BOOL fCopy);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_ItemType )( 
            FileProperties2 * This,
            /* [retval][out] */ BSTR *pbstrItemType);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE *put_ItemType )( 
            FileProperties2 * This,
            /* [in] */ BSTR bstrItemType);
        
        END_INTERFACE
    } FileProperties2Vtbl;

    interface FileProperties2
    {
        CONST_VTBL struct FileProperties2Vtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define FileProperties2_QueryInterface(This,riid,ppvObj,retval)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObj,retval)

#define FileProperties2_AddRef(This,retval)	\
    (This)->lpVtbl -> AddRef(This,retval)

#define FileProperties2_Release(This,retval)	\
    (This)->lpVtbl -> Release(This,retval)

#define FileProperties2_GetTypeInfoCount(This,pctinfo,retval)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo,retval)

#define FileProperties2_GetTypeInfo(This,itinfo,lcid,pptinfo,retval)	\
    (This)->lpVtbl -> GetTypeInfo(This,itinfo,lcid,pptinfo,retval)

#define FileProperties2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgdispid,retval)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgdispid,retval)

#define FileProperties2_Invoke(This,dispidMember,riid,lcid,wFlags,pdispparams,pvarResult,pexcepinfo,puArgErr,retval)	\
    (This)->lpVtbl -> Invoke(This,dispidMember,riid,lcid,wFlags,pdispparams,pvarResult,pexcepinfo,puArgErr,retval)

#define FileProperties2_get___id(This,retval)	\
    (This)->lpVtbl -> get___id(This,retval)

#define FileProperties2_get_FileName(This,retval)	\
    (This)->lpVtbl -> get_FileName(This,retval)

#define FileProperties2_put_FileName(This,noname,retval)	\
    (This)->lpVtbl -> put_FileName(This,noname,retval)

#define FileProperties2_get_Extension(This,retval)	\
    (This)->lpVtbl -> get_Extension(This,retval)

#define FileProperties2_get_Filesize(This,retval)	\
    (This)->lpVtbl -> get_Filesize(This,retval)

#define FileProperties2_get_LocalPath(This,retval)	\
    (This)->lpVtbl -> get_LocalPath(This,retval)

#define FileProperties2_get_FullPath(This,retval)	\
    (This)->lpVtbl -> get_FullPath(This,retval)

#define FileProperties2_get_URL(This,retval)	\
    (This)->lpVtbl -> get_URL(This,retval)

#define FileProperties2_get_HTMLTitle(This,retval)	\
    (This)->lpVtbl -> get_HTMLTitle(This,retval)

#define FileProperties2_get_Author(This,retval)	\
    (This)->lpVtbl -> get_Author(This,retval)

#define FileProperties2_get_DateCreated(This,retval)	\
    (This)->lpVtbl -> get_DateCreated(This,retval)

#define FileProperties2_get_DateModified(This,retval)	\
    (This)->lpVtbl -> get_DateModified(This,retval)

#define FileProperties2_get_ModifiedBy(This,retval)	\
    (This)->lpVtbl -> get_ModifiedBy(This,retval)

#define FileProperties2_get_SubType(This,retval)	\
    (This)->lpVtbl -> get_SubType(This,retval)

#define FileProperties2_put_SubType(This,noname,retval)	\
    (This)->lpVtbl -> put_SubType(This,noname,retval)

#define FileProperties2_get_Extender(This,ExtenderName,retval)	\
    (This)->lpVtbl -> get_Extender(This,ExtenderName,retval)

#define FileProperties2_get_ExtenderNames(This,retval)	\
    (This)->lpVtbl -> get_ExtenderNames(This,retval)

#define FileProperties2_get_ExtenderCATID(This,retval)	\
    (This)->lpVtbl -> get_ExtenderCATID(This,retval)

#define FileProperties2_get_BuildAction(This,retval)	\
    (This)->lpVtbl -> get_BuildAction(This,retval)

#define FileProperties2_put_BuildAction(This,noname,retval)	\
    (This)->lpVtbl -> put_BuildAction(This,noname,retval)

#define FileProperties2_get_CustomTool(This,retval)	\
    (This)->lpVtbl -> get_CustomTool(This,retval)

#define FileProperties2_put_CustomTool(This,noname,retval)	\
    (This)->lpVtbl -> put_CustomTool(This,noname,retval)

#define FileProperties2_get_CustomToolNamespace(This,retval)	\
    (This)->lpVtbl -> get_CustomToolNamespace(This,retval)

#define FileProperties2_put_CustomToolNamespace(This,noname,retval)	\
    (This)->lpVtbl -> put_CustomToolNamespace(This,noname,retval)

#define FileProperties2_get_CustomToolOutput(This,retval)	\
    (This)->lpVtbl -> get_CustomToolOutput(This,retval)

#define FileProperties2_get_IsCustomToolOutput(This,retval)	\
    (This)->lpVtbl -> get_IsCustomToolOutput(This,retval)

#define FileProperties2_get_IsDependentFile(This,retval)	\
    (This)->lpVtbl -> get_IsDependentFile(This,retval)

#define FileProperties2_get_IsLink(This,retval)	\
    (This)->lpVtbl -> get_IsLink(This,retval)

#define FileProperties2_get_IsDesignTimeBuildInput(This,retval)	\
    (This)->lpVtbl -> get_IsDesignTimeBuildInput(This,retval)


#define FileProperties2_get_CopyToOutputDirectory(This,pfCopy)	\
    (This)->lpVtbl -> get_CopyToOutputDirectory(This,pfCopy)

#define FileProperties2_put_CopyToOutputDirectory(This,fCopy)	\
    (This)->lpVtbl -> put_CopyToOutputDirectory(This,fCopy)

#define FileProperties2_get_ItemType(This,pbstrItemType)	\
    (This)->lpVtbl -> get_ItemType(This,pbstrItemType)

#define FileProperties2_put_ItemType(This,bstrItemType)	\
    (This)->lpVtbl -> put_ItemType(This,bstrItemType)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE FileProperties2_get_CopyToOutputDirectory_Proxy( 
    FileProperties2 * This,
    /* [retval][out] */ VARIANT_BOOL *pfCopy);


void __RPC_STUB FileProperties2_get_CopyToOutputDirectory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE FileProperties2_put_CopyToOutputDirectory_Proxy( 
    FileProperties2 * This,
    /* [in] */ VARIANT_BOOL fCopy);


void __RPC_STUB FileProperties2_put_CopyToOutputDirectory_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE FileProperties2_get_ItemType_Proxy( 
    FileProperties2 * This,
    /* [retval][out] */ BSTR *pbstrItemType);


void __RPC_STUB FileProperties2_get_ItemType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE FileProperties2_put_ItemType_Proxy( 
    FileProperties2 * This,
    /* [in] */ BSTR bstrItemType);


void __RPC_STUB FileProperties2_put_ItemType_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __FileProperties2_INTERFACE_DEFINED__ */

#endif /* __VSLangProj80_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


