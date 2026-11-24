

/* this ALWAYS GENERATED file contains the proxy stub code */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for jobint.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#if !defined(_M_IA64) && !defined(_M_AMD64)


#pragma warning( disable: 4049 )  /* more than 64k source lines */
#if _MSC_VER >= 1200
#pragma warning(push)
#endif
#pragma warning( disable: 4100 ) /* unreferenced arguments in x86 call */
#pragma warning( disable: 4211 )  /* redefine extent to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 475
#endif


#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif // __RPCPROXY_H_VERSION__


#include "jobint.h"

#define TYPE_FORMAT_STRING_SIZE   753                               
#define PROC_FORMAT_STRING_SIZE   5797                              
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   0            

typedef struct _MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } MIDL_TYPE_FORMAT_STRING;

typedef struct _MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } MIDL_PROC_FORMAT_STRING;


static RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString;
extern const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmAction_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmAction_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmActionOnResource_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmActionOnResource_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmActionOnResourcePost_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmActionOnResourcePost_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmActionOnResourcePre_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmActionOnResourcePre_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmActionOnResourcePreScan_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmActionOnResourcePreScan_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmCriteria_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmCriteria_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmRelativeCriteria_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmRelativeCriteria_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmDirectedAction_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmDirectedAction_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmJob_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmJob_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmJobContext_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmJobContext_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmJobDef_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmJobDef_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmJobSinkEverySession_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmJobSinkEverySession_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmJobWorkItem_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmJobWorkItem_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmPhase_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmPhase_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmPolicy_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmPolicy_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmRelocateAction_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmRelocateAction_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmRule_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmRule_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmRuleStack_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmRuleStack_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmScanner_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmScanner_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmSession_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmSession_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmSessionSinkEveryEvent_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmSessionSinkEveryEvent_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmSessionSinkEveryItem_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmSessionSinkEveryItem_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmSessionSinkEveryMediaState_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmSessionSinkEveryMediaState_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmSessionSinkEveryPriority_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmSessionSinkEveryPriority_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmSessionSinkEveryState_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmSessionSinkEveryState_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmSessionSinkSomeItems_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmSessionSinkSomeItems_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmSessionTotals_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmSessionTotals_ProxyInfo;



#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT50_OR_LATER)
#error You need a Windows 2000 or later to run this stub because it uses these features:
#error   /robust command line switch.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will die there with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure GetDestination */


	/* Procedure ComparatorAsString */


	/* Procedure GetName */


	/* Procedure GetName */


	/* Procedure GetName */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x3 ),	/* 3 */
/*  8 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 10 */	NdrFcShort( 0x8 ),	/* 8 */
/* 12 */	NdrFcShort( 0x8 ),	/* 8 */
/* 14 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 16 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	NdrFcShort( 0x0 ),	/* 0 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pDest */


	/* Parameter pCompString */


	/* Parameter pName */


	/* Parameter pName */


	/* Parameter pName */

/* 24 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 26 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 28 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter bufferSize */


	/* Parameter bufferSize */


	/* Parameter bufferSize */


	/* Parameter bufferSize */


	/* Parameter bufferSize */

/* 30 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 32 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 34 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 36 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 38 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 40 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Do */

/* 42 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 44 */	NdrFcLong( 0x0 ),	/* 0 */
/* 48 */	NdrFcShort( 0x4 ),	/* 4 */
/* 50 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 52 */	NdrFcShort( 0x0 ),	/* 0 */
/* 54 */	NdrFcShort( 0x8 ),	/* 8 */
/* 56 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 58 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 60 */	NdrFcShort( 0x0 ),	/* 0 */
/* 62 */	NdrFcShort( 0x0 ),	/* 0 */
/* 64 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pScanItem */

/* 66 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 68 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 70 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Return value */

/* 72 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 74 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 76 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Do */

/* 78 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 80 */	NdrFcLong( 0x0 ),	/* 0 */
/* 84 */	NdrFcShort( 0x3 ),	/* 3 */
/* 86 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 88 */	NdrFcShort( 0x8 ),	/* 8 */
/* 90 */	NdrFcShort( 0x8 ),	/* 8 */
/* 92 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 94 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 96 */	NdrFcShort( 0x0 ),	/* 0 */
/* 98 */	NdrFcShort( 0x0 ),	/* 0 */
/* 100 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pWorkItem */

/* 102 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 104 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 106 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter state */

/* 108 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 110 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 112 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 114 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 116 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 118 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Do */

/* 120 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 122 */	NdrFcLong( 0x0 ),	/* 0 */
/* 126 */	NdrFcShort( 0x3 ),	/* 3 */
/* 128 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 130 */	NdrFcShort( 0x0 ),	/* 0 */
/* 132 */	NdrFcShort( 0x8 ),	/* 8 */
/* 134 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 136 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 138 */	NdrFcShort( 0x0 ),	/* 0 */
/* 140 */	NdrFcShort( 0x0 ),	/* 0 */
/* 142 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pWorkItem */

/* 144 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 146 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 148 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter pJobDef */

/* 150 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 152 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 154 */	NdrFcShort( 0x2e ),	/* Type Offset=46 */

	/* Return value */

/* 156 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 158 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 160 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Do */

/* 162 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 164 */	NdrFcLong( 0x0 ),	/* 0 */
/* 168 */	NdrFcShort( 0x3 ),	/* 3 */
/* 170 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 172 */	NdrFcShort( 0x0 ),	/* 0 */
/* 174 */	NdrFcShort( 0x8 ),	/* 8 */
/* 176 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 178 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 180 */	NdrFcShort( 0x0 ),	/* 0 */
/* 182 */	NdrFcShort( 0x0 ),	/* 0 */
/* 184 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pResource */

/* 186 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 188 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 190 */	NdrFcShort( 0x40 ),	/* Type Offset=64 */

	/* Parameter pSession */

/* 192 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 194 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 196 */	NdrFcShort( 0x52 ),	/* Type Offset=82 */

	/* Return value */

/* 198 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 200 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 202 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ExpandPlaceholders */


	/* Procedure DidFinish */


	/* Procedure ComparatorIsBinary */


	/* Procedure IsIgnored */

/* 204 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 206 */	NdrFcLong( 0x0 ),	/* 0 */
/* 210 */	NdrFcShort( 0x4 ),	/* 4 */
/* 212 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 214 */	NdrFcShort( 0x0 ),	/* 0 */
/* 216 */	NdrFcShort( 0x8 ),	/* 8 */
/* 218 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 220 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 222 */	NdrFcShort( 0x0 ),	/* 0 */
/* 224 */	NdrFcShort( 0x0 ),	/* 0 */
/* 226 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 228 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 230 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 232 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RetainHierarchy */


	/* Procedure DoPostScan */


	/* Procedure DidFinishOk */


	/* Procedure IsNegated */

/* 234 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 236 */	NdrFcLong( 0x0 ),	/* 0 */
/* 240 */	NdrFcShort( 0x5 ),	/* 5 */
/* 242 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 244 */	NdrFcShort( 0x0 ),	/* 0 */
/* 246 */	NdrFcShort( 0x8 ),	/* 8 */
/* 248 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 250 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 252 */	NdrFcShort( 0x0 ),	/* 0 */
/* 254 */	NdrFcShort( 0x0 ),	/* 0 */
/* 256 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 258 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 260 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 262 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetIsIgnored */

/* 264 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 266 */	NdrFcLong( 0x0 ),	/* 0 */
/* 270 */	NdrFcShort( 0x6 ),	/* 6 */
/* 272 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 274 */	NdrFcShort( 0x8 ),	/* 8 */
/* 276 */	NdrFcShort( 0x8 ),	/* 8 */
/* 278 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 280 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 282 */	NdrFcShort( 0x0 ),	/* 0 */
/* 284 */	NdrFcShort( 0x0 ),	/* 0 */
/* 286 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter isIgnored */

/* 288 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 290 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 292 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 294 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 296 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 298 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetExpandPlaceholders */


	/* Procedure SetIsNegated */

/* 300 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 302 */	NdrFcLong( 0x0 ),	/* 0 */
/* 306 */	NdrFcShort( 0x7 ),	/* 7 */
/* 308 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 310 */	NdrFcShort( 0x8 ),	/* 8 */
/* 312 */	NdrFcShort( 0x8 ),	/* 8 */
/* 314 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 316 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 318 */	NdrFcShort( 0x0 ),	/* 0 */
/* 320 */	NdrFcShort( 0x0 ),	/* 0 */
/* 322 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter expandPlaceholders */


	/* Parameter isNegated */

/* 324 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 326 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 328 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 330 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 332 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 334 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ShouldDo */

/* 336 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 338 */	NdrFcLong( 0x0 ),	/* 0 */
/* 342 */	NdrFcShort( 0x8 ),	/* 8 */
/* 344 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 346 */	NdrFcShort( 0x6 ),	/* 6 */
/* 348 */	NdrFcShort( 0x8 ),	/* 8 */
/* 350 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 352 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 354 */	NdrFcShort( 0x0 ),	/* 0 */
/* 356 */	NdrFcShort( 0x0 ),	/* 0 */
/* 358 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pScanItem */

/* 360 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 362 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 364 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter scale */

/* 366 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 368 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 370 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 372 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 374 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 376 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Value */

/* 378 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 380 */	NdrFcLong( 0x0 ),	/* 0 */
/* 384 */	NdrFcShort( 0x9 ),	/* 9 */
/* 386 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 388 */	NdrFcShort( 0x8 ),	/* 8 */
/* 390 */	NdrFcShort( 0x8 ),	/* 8 */
/* 392 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 394 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 396 */	NdrFcShort( 0x0 ),	/* 0 */
/* 398 */	NdrFcShort( 0x0 ),	/* 0 */
/* 400 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pScanItem */

/* 402 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 404 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 406 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter value */

/* 408 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 410 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 412 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter bufferSize */

/* 414 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 416 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 418 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 420 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 422 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 424 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetName */


	/* Procedure GetArg1 */

/* 426 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 428 */	NdrFcLong( 0x0 ),	/* 0 */
/* 432 */	NdrFcShort( 0x5 ),	/* 5 */
/* 434 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 436 */	NdrFcShort( 0x8 ),	/* 8 */
/* 438 */	NdrFcShort( 0x8 ),	/* 8 */
/* 440 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 442 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 444 */	NdrFcShort( 0x0 ),	/* 0 */
/* 446 */	NdrFcShort( 0x0 ),	/* 0 */
/* 448 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */


	/* Parameter pArg */

/* 450 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 452 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 454 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter bufferSize */


	/* Parameter bufferSize */

/* 456 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 458 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 460 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 462 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 464 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 466 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetName */


	/* Procedure GetArg2 */

/* 468 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 470 */	NdrFcLong( 0x0 ),	/* 0 */
/* 474 */	NdrFcShort( 0x6 ),	/* 6 */
/* 476 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 478 */	NdrFcShort( 0x8 ),	/* 8 */
/* 480 */	NdrFcShort( 0x8 ),	/* 8 */
/* 482 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 484 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 486 */	NdrFcShort( 0x0 ),	/* 0 */
/* 488 */	NdrFcShort( 0x0 ),	/* 0 */
/* 490 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */


	/* Parameter pArg */

/* 492 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 494 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 496 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter bufferSize */


	/* Parameter bufferSize */

/* 498 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 500 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 502 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 504 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 506 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 508 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetAction */


	/* Procedure GetComparator */

/* 510 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 512 */	NdrFcLong( 0x0 ),	/* 0 */
/* 516 */	NdrFcShort( 0x7 ),	/* 7 */
/* 518 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 520 */	NdrFcShort( 0x0 ),	/* 0 */
/* 522 */	NdrFcShort( 0x24 ),	/* 36 */
/* 524 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 526 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 528 */	NdrFcShort( 0x0 ),	/* 0 */
/* 530 */	NdrFcShort( 0x0 ),	/* 0 */
/* 532 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pAction */


	/* Parameter pComparator */

/* 534 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 536 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 538 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 540 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 542 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 544 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetArg1 */

/* 546 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 548 */	NdrFcLong( 0x0 ),	/* 0 */
/* 552 */	NdrFcShort( 0x8 ),	/* 8 */
/* 554 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 556 */	NdrFcShort( 0x0 ),	/* 0 */
/* 558 */	NdrFcShort( 0x8 ),	/* 8 */
/* 560 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 562 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 564 */	NdrFcShort( 0x0 ),	/* 0 */
/* 566 */	NdrFcShort( 0x0 ),	/* 0 */
/* 568 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg */

/* 570 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 572 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 574 */	NdrFcShort( 0x6a ),	/* Type Offset=106 */

	/* Return value */

/* 576 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 578 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 580 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetArg2 */

/* 582 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 584 */	NdrFcLong( 0x0 ),	/* 0 */
/* 588 */	NdrFcShort( 0x9 ),	/* 9 */
/* 590 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 592 */	NdrFcShort( 0x0 ),	/* 0 */
/* 594 */	NdrFcShort( 0x8 ),	/* 8 */
/* 596 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 598 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 600 */	NdrFcShort( 0x0 ),	/* 0 */
/* 602 */	NdrFcShort( 0x0 ),	/* 0 */
/* 604 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg */

/* 606 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 608 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 610 */	NdrFcShort( 0x6a ),	/* Type Offset=106 */

	/* Return value */

/* 612 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 614 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 616 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetComparator */

/* 618 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 620 */	NdrFcLong( 0x0 ),	/* 0 */
/* 624 */	NdrFcShort( 0xa ),	/* 10 */
/* 626 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 628 */	NdrFcShort( 0x8 ),	/* 8 */
/* 630 */	NdrFcShort( 0x8 ),	/* 8 */
/* 632 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 634 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 636 */	NdrFcShort( 0x0 ),	/* 0 */
/* 638 */	NdrFcShort( 0x0 ),	/* 0 */
/* 640 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter comparator */

/* 642 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 644 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 646 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 648 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 650 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 652 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetStoragePoolId */

/* 654 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 656 */	NdrFcLong( 0x0 ),	/* 0 */
/* 660 */	NdrFcShort( 0x3 ),	/* 3 */
/* 662 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 664 */	NdrFcShort( 0x0 ),	/* 0 */
/* 666 */	NdrFcShort( 0x4c ),	/* 76 */
/* 668 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 670 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 672 */	NdrFcShort( 0x0 ),	/* 0 */
/* 674 */	NdrFcShort( 0x0 ),	/* 0 */
/* 676 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */

/* 678 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 680 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 682 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Return value */

/* 684 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 686 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 688 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetStoragePoolId */

/* 690 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 692 */	NdrFcLong( 0x0 ),	/* 0 */
/* 696 */	NdrFcShort( 0x4 ),	/* 4 */
/* 698 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 700 */	NdrFcShort( 0x30 ),	/* 48 */
/* 702 */	NdrFcShort( 0x8 ),	/* 8 */
/* 704 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 706 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 708 */	NdrFcShort( 0x0 ),	/* 0 */
/* 710 */	NdrFcShort( 0x0 ),	/* 0 */
/* 712 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter id */

/* 714 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 716 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 718 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Return value */

/* 720 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 722 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 724 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Cancel */


	/* Procedure Cancel */

/* 726 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 728 */	NdrFcLong( 0x0 ),	/* 0 */
/* 732 */	NdrFcShort( 0x3 ),	/* 3 */
/* 734 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 736 */	NdrFcShort( 0x8 ),	/* 8 */
/* 738 */	NdrFcShort( 0x8 ),	/* 8 */
/* 740 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 742 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 744 */	NdrFcShort( 0x0 ),	/* 0 */
/* 746 */	NdrFcShort( 0x0 ),	/* 0 */
/* 748 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter phase */


	/* Parameter phase */

/* 750 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 752 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 754 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 756 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 758 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 760 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure EnumWorkItems */

/* 762 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 764 */	NdrFcLong( 0x0 ),	/* 0 */
/* 768 */	NdrFcShort( 0x6 ),	/* 6 */
/* 770 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 772 */	NdrFcShort( 0x0 ),	/* 0 */
/* 774 */	NdrFcShort( 0x8 ),	/* 8 */
/* 776 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 778 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 780 */	NdrFcShort( 0x0 ),	/* 0 */
/* 782 */	NdrFcShort( 0x0 ),	/* 0 */
/* 784 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppEnum */

/* 786 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 788 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 790 */	NdrFcShort( 0x82 ),	/* Type Offset=130 */

	/* Return value */

/* 792 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 794 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 796 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindWorkItem */

/* 798 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 800 */	NdrFcLong( 0x0 ),	/* 0 */
/* 804 */	NdrFcShort( 0x7 ),	/* 7 */
/* 806 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 808 */	NdrFcShort( 0x0 ),	/* 0 */
/* 810 */	NdrFcShort( 0x8 ),	/* 8 */
/* 812 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 814 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 816 */	NdrFcShort( 0x0 ),	/* 0 */
/* 818 */	NdrFcShort( 0x0 ),	/* 0 */
/* 820 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSession */

/* 822 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 824 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 826 */	NdrFcShort( 0x98 ),	/* Type Offset=152 */

	/* Parameter ppWorkItem */

/* 828 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 830 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 832 */	NdrFcShort( 0xaa ),	/* Type Offset=170 */

	/* Return value */

/* 834 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 836 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 838 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetContext */

/* 840 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 842 */	NdrFcLong( 0x0 ),	/* 0 */
/* 846 */	NdrFcShort( 0x8 ),	/* 8 */
/* 848 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 850 */	NdrFcShort( 0x0 ),	/* 0 */
/* 852 */	NdrFcShort( 0x8 ),	/* 8 */
/* 854 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 856 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 858 */	NdrFcShort( 0x0 ),	/* 0 */
/* 860 */	NdrFcShort( 0x0 ),	/* 0 */
/* 862 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppContext */

/* 864 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 866 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 868 */	NdrFcShort( 0xae ),	/* Type Offset=174 */

	/* Return value */

/* 870 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 872 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 874 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDef */

/* 876 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 878 */	NdrFcLong( 0x0 ),	/* 0 */
/* 882 */	NdrFcShort( 0x9 ),	/* 9 */
/* 884 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 886 */	NdrFcShort( 0x0 ),	/* 0 */
/* 888 */	NdrFcShort( 0x8 ),	/* 8 */
/* 890 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 892 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 894 */	NdrFcShort( 0x0 ),	/* 0 */
/* 896 */	NdrFcShort( 0x0 ),	/* 0 */
/* 898 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppDef */

/* 900 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 902 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 904 */	NdrFcShort( 0xc4 ),	/* Type Offset=196 */

	/* Return value */

/* 906 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 908 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 910 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetHsmId */

/* 912 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 914 */	NdrFcLong( 0x0 ),	/* 0 */
/* 918 */	NdrFcShort( 0xa ),	/* 10 */
/* 920 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 922 */	NdrFcShort( 0x0 ),	/* 0 */
/* 924 */	NdrFcShort( 0x4c ),	/* 76 */
/* 926 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 928 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 930 */	NdrFcShort( 0x0 ),	/* 0 */
/* 932 */	NdrFcShort( 0x0 ),	/* 0 */
/* 934 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */

/* 936 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 938 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 940 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Return value */

/* 942 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 944 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 946 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetResourceId */


	/* Procedure GetIdentifier */

/* 948 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 950 */	NdrFcLong( 0x0 ),	/* 0 */
/* 954 */	NdrFcShort( 0xb ),	/* 11 */
/* 956 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 958 */	NdrFcShort( 0x0 ),	/* 0 */
/* 960 */	NdrFcShort( 0x4c ),	/* 76 */
/* 962 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 964 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 966 */	NdrFcShort( 0x0 ),	/* 0 */
/* 968 */	NdrFcShort( 0x0 ),	/* 0 */
/* 970 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */


	/* Parameter pId */

/* 972 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 974 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 976 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Return value */


	/* Return value */

/* 978 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 980 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 982 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetRunId */


	/* Procedure GetMaxActiveSessions */

/* 984 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 986 */	NdrFcLong( 0x0 ),	/* 0 */
/* 990 */	NdrFcShort( 0xc ),	/* 12 */
/* 992 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 994 */	NdrFcShort( 0x0 ),	/* 0 */
/* 996 */	NdrFcShort( 0x24 ),	/* 36 */
/* 998 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1000 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1002 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1004 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1006 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */


	/* Parameter pMaxActiveSessions */

/* 1008 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1010 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1012 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 1014 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1016 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1018 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetStateAsString */


	/* Procedure GetStartingPath */


	/* Procedure GetName */

/* 1020 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1022 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1026 */	NdrFcShort( 0xd ),	/* 13 */
/* 1028 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1030 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1032 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1034 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1036 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1038 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1040 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1042 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */


	/* Parameter pString */


	/* Parameter pName */

/* 1044 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 1046 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1048 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter bufferSize */


	/* Parameter bufferSize */


	/* Parameter bufferSize */

/* 1050 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1052 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1054 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 1056 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1058 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1060 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetRunId */

/* 1062 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1064 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1068 */	NdrFcShort( 0xe ),	/* 14 */
/* 1070 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1072 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1074 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1076 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1078 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1080 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1082 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1084 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */

/* 1086 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1088 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1090 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1092 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1094 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1096 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetState */


	/* Procedure GetState */

/* 1098 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1100 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1104 */	NdrFcShort( 0xf ),	/* 15 */
/* 1106 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1108 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1110 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1112 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1114 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1116 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1118 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1120 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pState */


	/* Parameter pState */

/* 1122 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1124 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1126 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 1128 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1130 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1132 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure InitAs */

/* 1134 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1136 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1140 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1142 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 1144 */	NdrFcShort( 0x40 ),	/* 64 */
/* 1146 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1148 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x8,		/* 8 */
/* 1150 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1152 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1154 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1156 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 1158 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1160 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1162 */	NdrFcShort( 0x6a ),	/* Type Offset=106 */

	/* Parameter pDef */

/* 1164 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1166 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1168 */	NdrFcShort( 0xc8 ),	/* Type Offset=200 */

	/* Parameter type */

/* 1170 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1172 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1174 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter storagePool */

/* 1176 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 1178 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1180 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Parameter pServer */

/* 1182 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1184 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 1186 */	NdrFcShort( 0xde ),	/* Type Offset=222 */

	/* Parameter isUserDefined */

/* 1188 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1190 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 1192 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pResource */

/* 1194 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1196 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 1198 */	NdrFcShort( 0xf0 ),	/* Type Offset=240 */

	/* Return value */

/* 1200 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1202 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 1204 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsActive */

/* 1206 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1208 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1212 */	NdrFcShort( 0x11 ),	/* 17 */
/* 1214 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1216 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1218 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1220 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1222 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1224 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1226 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1228 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1230 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1232 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1234 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsUserDefined */

/* 1236 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1238 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1242 */	NdrFcShort( 0x12 ),	/* 18 */
/* 1244 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1246 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1248 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1250 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1252 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1254 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1256 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1258 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1260 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1262 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1264 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Pause */

/* 1266 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1268 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1272 */	NdrFcShort( 0x13 ),	/* 19 */
/* 1274 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1276 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1278 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1280 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1282 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1284 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1286 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1288 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter phase */

/* 1290 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1292 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1294 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 1296 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1298 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1300 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SkipSystemItems */


	/* Procedure Restart */

/* 1302 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1304 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1308 */	NdrFcShort( 0x14 ),	/* 20 */
/* 1310 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1312 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1314 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1316 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1318 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1320 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1322 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1324 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */

/* 1326 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1328 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1330 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Resume */

/* 1332 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1334 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1338 */	NdrFcShort( 0x15 ),	/* 21 */
/* 1340 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1342 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1344 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1346 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1348 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1350 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1352 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1354 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter phase */

/* 1356 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1358 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1360 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 1362 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1364 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1366 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetContext */

/* 1368 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1370 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1374 */	NdrFcShort( 0x16 ),	/* 22 */
/* 1376 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1378 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1380 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1382 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1384 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1386 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1388 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1390 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pContext */

/* 1392 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1394 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1396 */	NdrFcShort( 0x102 ),	/* Type Offset=258 */

	/* Return value */

/* 1398 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1400 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1402 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetDef */

/* 1404 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1406 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1410 */	NdrFcShort( 0x17 ),	/* 23 */
/* 1412 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1414 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1416 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1418 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1420 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1422 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1424 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1426 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pDef */

/* 1428 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1430 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1432 */	NdrFcShort( 0x114 ),	/* Type Offset=276 */

	/* Return value */

/* 1434 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1436 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1438 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetHsmId */

/* 1440 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1442 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1446 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1448 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1450 */	NdrFcShort( 0x30 ),	/* 48 */
/* 1452 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1454 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1456 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1458 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1460 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1462 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter id */

/* 1464 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 1466 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1468 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Return value */

/* 1470 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1472 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1474 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetIsUserDefined */

/* 1476 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1478 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1482 */	NdrFcShort( 0x19 ),	/* 25 */
/* 1484 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1486 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1488 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1490 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1492 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1494 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1496 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1498 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter isUserDefined */

/* 1500 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1502 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1504 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1506 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1508 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1510 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetName */

/* 1512 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1514 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1518 */	NdrFcShort( 0x1a ),	/* 26 */
/* 1520 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1522 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1524 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1526 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1528 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1530 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1532 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1534 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 1536 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1538 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1540 */	NdrFcShort( 0x6a ),	/* Type Offset=106 */

	/* Return value */

/* 1542 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1544 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1546 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Start */

/* 1548 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1550 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1554 */	NdrFcShort( 0x1b ),	/* 27 */
/* 1556 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1558 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1560 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1562 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1564 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1566 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1568 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1570 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1572 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1574 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1576 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Suspend */

/* 1578 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1580 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1584 */	NdrFcShort( 0x1c ),	/* 28 */
/* 1586 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1588 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1590 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1592 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1594 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1596 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1598 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1600 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter phase */

/* 1602 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1604 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1606 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 1608 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1610 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1612 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure WaitUntilDone */

/* 1614 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1616 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1620 */	NdrFcShort( 0x1d ),	/* 29 */
/* 1622 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1624 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1626 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1628 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1630 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1632 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1634 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1636 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1638 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1640 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1642 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure EnumPolicies */


	/* Procedure EnumResources */

/* 1644 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1646 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1650 */	NdrFcShort( 0x3 ),	/* 3 */
/* 1652 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1654 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1656 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1658 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1660 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1662 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1664 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1666 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppEnum */


	/* Parameter ppEnum */

/* 1668 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1670 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1672 */	NdrFcShort( 0x126 ),	/* Type Offset=294 */

	/* Return value */


	/* Return value */

/* 1674 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1676 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1678 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Resources */

/* 1680 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1682 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1686 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1688 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1690 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1692 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1694 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1696 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1698 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1700 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1702 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppResources */

/* 1704 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1706 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1708 */	NdrFcShort( 0x13c ),	/* Type Offset=316 */

	/* Return value */

/* 1710 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1712 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1714 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetUsesAllManaged */

/* 1716 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1718 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1722 */	NdrFcShort( 0x5 ),	/* 5 */
/* 1724 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1726 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1728 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1730 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1732 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1734 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1736 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1738 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter usesAllManaged */

/* 1740 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1742 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1744 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1746 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1748 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1750 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DoPreScan */


	/* Procedure UsesAllManaged */

/* 1752 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1754 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1758 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1760 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1762 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1764 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1766 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1768 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1770 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1772 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1774 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */

/* 1776 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1778 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1780 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetIdentifier */

/* 1782 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1784 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1788 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1790 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1792 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1794 */	NdrFcShort( 0x4c ),	/* 76 */
/* 1796 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1798 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1800 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1802 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1804 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */

/* 1806 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 1808 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1810 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Return value */

/* 1812 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1814 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1816 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPostActionOnResource */

/* 1818 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1820 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1824 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1826 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1828 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1830 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1832 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1834 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1836 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1838 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1840 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppAction */

/* 1842 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1844 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1846 */	NdrFcShort( 0x152 ),	/* Type Offset=338 */

	/* Return value */

/* 1848 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1850 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1852 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPreActionOnResource */

/* 1854 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1856 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1860 */	NdrFcShort( 0x7 ),	/* 7 */
/* 1862 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1864 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1866 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1868 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1870 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1872 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1874 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1876 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppAction */

/* 1878 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1880 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1882 */	NdrFcShort( 0x168 ),	/* Type Offset=360 */

	/* Return value */

/* 1884 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1886 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1888 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPreScanActionOnResource */

/* 1890 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1892 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1896 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1898 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1900 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1902 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1904 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1906 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1908 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1910 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1912 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppAction */

/* 1914 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1916 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1918 */	NdrFcShort( 0x17e ),	/* Type Offset=382 */

	/* Return value */

/* 1920 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1922 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1924 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure InitAs */

/* 1926 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1928 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1932 */	NdrFcShort( 0x9 ),	/* 9 */
/* 1934 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 1936 */	NdrFcShort( 0x40 ),	/* 64 */
/* 1938 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1940 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 1942 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1944 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1946 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1948 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 1950 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1952 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1954 */	NdrFcShort( 0x6a ),	/* Type Offset=106 */

	/* Parameter type */

/* 1956 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1958 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1960 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter storagePool */

/* 1962 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 1964 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1966 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Parameter pServer */

/* 1968 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1970 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 1972 */	NdrFcShort( 0xde ),	/* Type Offset=222 */

	/* Parameter isUserDefined */

/* 1974 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1976 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 1978 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1980 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1982 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 1984 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Policies */

/* 1986 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1988 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1992 */	NdrFcShort( 0xa ),	/* 10 */
/* 1994 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1996 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1998 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2000 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2002 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2004 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2006 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2008 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppPolicies */

/* 2010 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2012 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2014 */	NdrFcShort( 0x13c ),	/* Type Offset=316 */

	/* Return value */

/* 2016 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2018 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2020 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetName */

/* 2022 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2024 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2028 */	NdrFcShort( 0xb ),	/* 11 */
/* 2030 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2032 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2034 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2036 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2038 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2040 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2042 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2044 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 2046 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2048 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2050 */	NdrFcShort( 0x6a ),	/* Type Offset=106 */

	/* Return value */

/* 2052 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2054 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2056 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetPostActionOnResource */

/* 2058 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2060 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2064 */	NdrFcShort( 0xc ),	/* 12 */
/* 2066 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2068 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2070 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2072 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2074 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2076 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2078 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2080 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pAction */

/* 2082 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2084 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2086 */	NdrFcShort( 0x156 ),	/* Type Offset=342 */

	/* Return value */

/* 2088 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2090 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2092 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetPreActionOnResource */

/* 2094 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2096 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2100 */	NdrFcShort( 0xd ),	/* 13 */
/* 2102 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2104 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2106 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2108 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2110 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2112 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2114 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2116 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pAction */

/* 2118 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2120 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2122 */	NdrFcShort( 0x16c ),	/* Type Offset=364 */

	/* Return value */

/* 2124 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2126 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2128 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetPreScanActionOnResource */

/* 2130 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2132 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2136 */	NdrFcShort( 0xe ),	/* 14 */
/* 2138 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2140 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2142 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2144 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2146 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2148 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2150 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2152 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pAction */

/* 2154 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2156 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2158 */	NdrFcShort( 0x182 ),	/* Type Offset=386 */

	/* Return value */

/* 2160 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2162 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2164 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetIsUserDefined */


	/* Procedure SetSkipHiddenItems */

/* 2166 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2168 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2172 */	NdrFcShort( 0xf ),	/* 15 */
/* 2174 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2176 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2178 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2180 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2182 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2184 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2186 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2188 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter isUserDefined */


	/* Parameter shouldSkip */

/* 2190 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2192 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2194 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 2196 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2198 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2200 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetIsUsedInSubDirs */


	/* Procedure SetSkipSystemItems */

/* 2202 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2204 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2208 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2210 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2212 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2214 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2216 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2218 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2220 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2222 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2224 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter isUsed */


	/* Parameter shouldSkip */

/* 2226 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2228 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2230 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 2232 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2234 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2236 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetUseRPIndex */

/* 2238 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2240 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2244 */	NdrFcShort( 0x11 ),	/* 17 */
/* 2246 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2248 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2250 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2252 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2254 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2256 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2258 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2260 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter useIndex */

/* 2262 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2264 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2266 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2268 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2270 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2272 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetUseDbIndex */

/* 2274 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2276 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2280 */	NdrFcShort( 0x12 ),	/* 18 */
/* 2282 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2284 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2286 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2288 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2290 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2292 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2294 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2296 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter useIndex */

/* 2298 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2300 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2302 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2304 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2306 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2308 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SkipHiddenItems */

/* 2310 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2312 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2316 */	NdrFcShort( 0x13 ),	/* 19 */
/* 2318 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2320 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2322 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2324 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 2326 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2328 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2330 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2332 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 2334 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2336 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2338 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure UseRPIndex */

/* 2340 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2342 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2346 */	NdrFcShort( 0x15 ),	/* 21 */
/* 2348 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2350 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2352 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2354 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 2356 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2358 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2360 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2362 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 2364 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2366 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2368 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure UseDbIndex */

/* 2370 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2372 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2376 */	NdrFcShort( 0x16 ),	/* 22 */
/* 2378 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2380 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2382 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2384 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 2386 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2388 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2390 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2392 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 2394 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2396 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2398 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ProcessJobSession */

/* 2400 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2402 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2406 */	NdrFcShort( 0x3 ),	/* 3 */
/* 2408 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2410 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2412 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2414 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 2416 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2418 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2420 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2422 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSession */

/* 2424 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2426 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2428 */	NdrFcShort( 0x194 ),	/* Type Offset=404 */

	/* Parameter pPhase */

/* 2430 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2432 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2434 */	NdrFcShort( 0x1a6 ),	/* Type Offset=422 */

	/* Parameter currentPath */

/* 2436 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2438 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2440 */	NdrFcShort( 0x6a ),	/* Type Offset=106 */

	/* Return value */

/* 2442 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2444 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2446 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToResourceId */

/* 2448 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2450 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2454 */	NdrFcShort( 0x3 ),	/* 3 */
/* 2456 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 2458 */	NdrFcShort( 0x30 ),	/* 48 */
/* 2460 */	NdrFcShort( 0x22 ),	/* 34 */
/* 2462 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 2464 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2466 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2468 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2470 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter id */

/* 2472 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 2474 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2476 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Parameter pResult */

/* 2478 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2480 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2482 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2484 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2486 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2488 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToIWorkItem */

/* 2490 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2492 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2496 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2498 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2500 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2502 */	NdrFcShort( 0x22 ),	/* 34 */
/* 2504 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2506 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2508 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2510 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2512 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pWorkItem */

/* 2514 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2516 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2518 */	NdrFcShort( 0x1bc ),	/* Type Offset=444 */

	/* Parameter pResult */

/* 2520 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2522 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2524 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2526 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2528 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2530 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure EnumPhases */

/* 2532 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2534 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2538 */	NdrFcShort( 0x7 ),	/* 7 */
/* 2540 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2542 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2544 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2546 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2548 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2550 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2552 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2554 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppEnum */

/* 2556 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2558 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2560 */	NdrFcShort( 0x1ce ),	/* Type Offset=462 */

	/* Return value */

/* 2562 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2564 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2566 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure EnumTotals */

/* 2568 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2570 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2574 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2576 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2578 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2580 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2582 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2584 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2586 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2588 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2590 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppEnum */

/* 2592 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2594 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2596 */	NdrFcShort( 0x1ce ),	/* Type Offset=462 */

	/* Return value */

/* 2598 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2600 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2602 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPath */


	/* Procedure GetCurrentPath */

/* 2604 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2606 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2610 */	NdrFcShort( 0x9 ),	/* 9 */
/* 2612 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2614 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2616 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2618 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2620 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2622 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2624 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2626 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPath */


	/* Parameter pString */

/* 2628 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 2630 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2632 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter bufferSize */


	/* Parameter bufferSize */

/* 2634 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2636 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2638 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 2640 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2642 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2644 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetFinishTime */

/* 2646 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2648 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2652 */	NdrFcShort( 0xa ),	/* 10 */
/* 2654 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2656 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2658 */	NdrFcShort( 0x34 ),	/* 52 */
/* 2660 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2662 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2664 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2666 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2668 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pTime */

/* 2670 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 2672 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2674 */	NdrFcShort( 0x1e8 ),	/* Type Offset=488 */

	/* Return value */

/* 2676 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2678 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2680 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSession */

/* 2682 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2684 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2688 */	NdrFcShort( 0xc ),	/* 12 */
/* 2690 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2692 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2694 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2696 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2698 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2700 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2702 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2704 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppSession */

/* 2706 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2708 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2710 */	NdrFcShort( 0x1f0 ),	/* Type Offset=496 */

	/* Return value */

/* 2712 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2714 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2716 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetStartTime */

/* 2718 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2720 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2724 */	NdrFcShort( 0xe ),	/* 14 */
/* 2726 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2728 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2730 */	NdrFcShort( 0x34 ),	/* 52 */
/* 2732 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2734 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2736 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2738 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2740 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pTime */

/* 2742 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 2744 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2746 */	NdrFcShort( 0x1e8 ),	/* Type Offset=488 */

	/* Return value */

/* 2748 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2750 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2752 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetStateAsString */

/* 2754 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2756 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2760 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2762 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2764 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2766 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2768 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2770 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2772 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2774 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2776 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */

/* 2778 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 2780 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2782 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter bufferSize */

/* 2784 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2786 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2788 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2790 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2792 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2794 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSubRunId */

/* 2796 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2798 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2802 */	NdrFcShort( 0x11 ),	/* 17 */
/* 2804 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2806 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2808 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2810 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2812 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2814 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2816 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2818 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */

/* 2820 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2822 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2824 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2826 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2828 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2830 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Clone */

/* 2832 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2834 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2838 */	NdrFcShort( 0x3 ),	/* 3 */
/* 2840 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2842 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2844 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2846 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2848 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2850 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2852 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2854 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppPhase */

/* 2856 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2858 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2860 */	NdrFcShort( 0x206 ),	/* Type Offset=518 */

	/* Return value */

/* 2862 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2864 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2866 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CopyTo */

/* 2868 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2870 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2874 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2876 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2878 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2880 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2882 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2884 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2886 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2888 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2890 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPhase */

/* 2892 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2894 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2896 */	NdrFcShort( 0x20a ),	/* Type Offset=522 */

	/* Return value */

/* 2898 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2900 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2902 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetElapsedTime */

/* 2904 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2906 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2910 */	NdrFcShort( 0x5 ),	/* 5 */
/* 2912 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2914 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2916 */	NdrFcShort( 0x72 ),	/* 114 */
/* 2918 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x5,		/* 5 */
/* 2920 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2922 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2924 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2926 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pDays */

/* 2928 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2930 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2932 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pHours */

/* 2934 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2936 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2938 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pMinutes */

/* 2940 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2942 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2944 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pSeconds */

/* 2946 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2948 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2950 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2952 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2954 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2956 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMediaState */

/* 2958 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2960 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2964 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2966 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2968 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2970 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2972 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2974 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2976 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2978 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2980 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pState */

/* 2982 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2984 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2986 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 2988 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2990 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2992 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetName */


	/* Procedure GetMediaStateAsString */

/* 2994 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2996 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3000 */	NdrFcShort( 0x7 ),	/* 7 */
/* 3002 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3004 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3006 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3008 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 3010 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3012 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3014 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3016 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */


	/* Parameter pName */

/* 3018 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 3020 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3022 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter bufferSize */


	/* Parameter bufferSize */

/* 3024 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3026 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3028 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 3030 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3032 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3034 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetName */


	/* Procedure GetSearchName */


	/* Procedure GetName */

/* 3036 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3038 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3042 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3044 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3046 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3048 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3050 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 3052 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3054 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3056 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3058 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */


	/* Parameter pName */


	/* Parameter pName */

/* 3060 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 3062 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3064 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter bufferSize */


	/* Parameter bufferSize */


	/* Parameter bufferSize */

/* 3066 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3068 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3070 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 3072 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3074 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3076 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPhase */

/* 3078 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3080 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3084 */	NdrFcShort( 0x9 ),	/* 9 */
/* 3086 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3088 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3090 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3092 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3094 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3096 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3098 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3100 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPhase */

/* 3102 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3104 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3106 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 3108 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3110 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3112 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPriority */

/* 3114 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3116 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3120 */	NdrFcShort( 0xa ),	/* 10 */
/* 3122 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3124 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3126 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3128 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3130 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3132 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3134 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3136 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPriority */

/* 3138 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3140 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3142 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 3144 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3146 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3148 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPriorityAsString */

/* 3150 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3152 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3156 */	NdrFcShort( 0xb ),	/* 11 */
/* 3158 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3160 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3162 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3164 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 3166 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3168 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3170 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3172 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */

/* 3174 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 3176 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3178 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter bufferSize */

/* 3180 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3182 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3184 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3186 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3188 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3190 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetState */

/* 3192 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3194 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3198 */	NdrFcShort( 0xc ),	/* 12 */
/* 3200 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3202 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3204 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3206 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3208 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3210 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3212 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3214 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pState */

/* 3216 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3218 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3220 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 3222 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3224 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3226 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetStats */

/* 3228 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3230 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3234 */	NdrFcShort( 0xe ),	/* 14 */
/* 3236 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 3238 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3240 */	NdrFcShort( 0xe0 ),	/* 224 */
/* 3242 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x7,		/* 7 */
/* 3244 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3246 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3248 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3250 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter items */

/* 3252 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3254 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3256 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 3258 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3260 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3262 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter skippedItems */

/* 3264 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3266 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3268 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter skippedSize */

/* 3270 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3272 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3274 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter errorItems */

/* 3276 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3278 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3280 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter errorSize */

/* 3282 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3284 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3286 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 3288 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3290 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 3292 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetStartTime */

/* 3294 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3296 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3300 */	NdrFcShort( 0xf ),	/* 15 */
/* 3302 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3304 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3306 */	NdrFcShort( 0x34 ),	/* 52 */
/* 3308 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3310 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3312 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3314 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3316 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pTime */

/* 3318 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 3320 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3322 */	NdrFcShort( 0x1e8 ),	/* Type Offset=488 */

	/* Return value */

/* 3324 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3326 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3328 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetStopTime */

/* 3330 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3332 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3336 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3338 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3340 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3342 */	NdrFcShort( 0x34 ),	/* 52 */
/* 3344 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3346 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3348 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3350 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3352 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pTime */

/* 3354 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 3356 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3358 */	NdrFcShort( 0x1e8 ),	/* Type Offset=488 */

	/* Return value */

/* 3360 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3362 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3364 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure EnumRules */

/* 3366 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3368 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3372 */	NdrFcShort( 0x3 ),	/* 3 */
/* 3374 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3376 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3378 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3380 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 3382 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3384 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3386 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3388 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppEnum */

/* 3390 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3392 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3394 */	NdrFcShort( 0x1ce ),	/* Type Offset=462 */

	/* Return value */

/* 3396 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3398 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3400 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetAction */

/* 3402 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3404 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3408 */	NdrFcShort( 0x4 ),	/* 4 */
/* 3410 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3412 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3414 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3416 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 3418 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3420 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3422 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3424 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppAction */

/* 3426 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3428 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3430 */	NdrFcShort( 0x220 ),	/* Type Offset=544 */

	/* Return value */

/* 3432 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3434 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3436 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetIdentifier */

/* 3438 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3440 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3444 */	NdrFcShort( 0x5 ),	/* 5 */
/* 3446 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3448 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3450 */	NdrFcShort( 0x4c ),	/* 76 */
/* 3452 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3454 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3456 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3458 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3460 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */

/* 3462 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 3464 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3466 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Return value */

/* 3468 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3470 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3472 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetScale */

/* 3474 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3476 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3480 */	NdrFcShort( 0x7 ),	/* 7 */
/* 3482 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3484 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3486 */	NdrFcShort( 0x22 ),	/* 34 */
/* 3488 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3490 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3492 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3494 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3496 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pScale */

/* 3498 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3500 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3502 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 3504 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3506 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3508 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Rules */

/* 3510 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3512 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3516 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3518 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3520 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3522 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3524 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 3526 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3528 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3530 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3532 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppWsbCollection */

/* 3534 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3536 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3538 */	NdrFcShort( 0x236 ),	/* Type Offset=566 */

	/* Return value */

/* 3540 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3542 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3544 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetAction */

/* 3546 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3548 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3552 */	NdrFcShort( 0x9 ),	/* 9 */
/* 3554 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3556 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3558 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3560 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3562 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3564 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3566 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3568 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pAction */

/* 3570 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3572 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3574 */	NdrFcShort( 0x224 ),	/* Type Offset=548 */

	/* Return value */

/* 3576 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3578 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3580 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetName */

/* 3582 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3584 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3588 */	NdrFcShort( 0xa ),	/* 10 */
/* 3590 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3592 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3594 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3596 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3598 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3600 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3602 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3604 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 3606 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3608 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3610 */	NdrFcShort( 0x6a ),	/* Type Offset=106 */

	/* Return value */

/* 3612 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3614 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3616 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetScale */

/* 3618 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3620 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3624 */	NdrFcShort( 0xb ),	/* 11 */
/* 3626 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3628 */	NdrFcShort( 0x6 ),	/* 6 */
/* 3630 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3632 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3634 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3636 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3638 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3640 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter scale */

/* 3642 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3644 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3646 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 3648 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3650 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3652 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetUsesDefaultRules */

/* 3654 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3656 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3660 */	NdrFcShort( 0xc ),	/* 12 */
/* 3662 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3664 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3666 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3668 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3670 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3672 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3674 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3676 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter usesDefaults */

/* 3678 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3680 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3682 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3684 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3686 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3688 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure UsesDefaultRules */

/* 3690 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3692 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3696 */	NdrFcShort( 0xd ),	/* 13 */
/* 3698 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3700 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3702 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3704 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 3706 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3708 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3710 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3712 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 3714 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3716 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3718 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Pop */


	/* Procedure SetDestination */

/* 3720 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3722 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3726 */	NdrFcShort( 0x6 ),	/* 6 */
/* 3728 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3730 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3732 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3734 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3736 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3738 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3740 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3742 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter path */


	/* Parameter dest */

/* 3744 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3746 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3748 */	NdrFcShort( 0x6a ),	/* Type Offset=106 */

	/* Return value */


	/* Return value */

/* 3750 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3752 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3754 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetRetainHierarchy */

/* 3756 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3758 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3762 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3764 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3766 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3768 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3770 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3772 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3774 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3776 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3778 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter retainHierarchy */

/* 3780 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3782 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3784 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3786 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3788 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3790 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToIRule */

/* 3792 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3794 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3798 */	NdrFcShort( 0x3 ),	/* 3 */
/* 3800 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3802 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3804 */	NdrFcShort( 0x22 ),	/* 34 */
/* 3806 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 3808 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3810 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3812 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3814 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pRule */

/* 3816 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3818 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3820 */	NdrFcShort( 0x24c ),	/* Type Offset=588 */

	/* Parameter pResult */

/* 3822 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3824 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3826 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 3828 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3830 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3832 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToPathAndName */

/* 3834 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3836 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3840 */	NdrFcShort( 0x4 ),	/* 4 */
/* 3842 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3844 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3846 */	NdrFcShort( 0x22 ),	/* 34 */
/* 3848 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 3850 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3852 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3854 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3856 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter path */

/* 3858 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3860 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3862 */	NdrFcShort( 0x6a ),	/* Type Offset=106 */

	/* Parameter name */

/* 3864 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3866 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3868 */	NdrFcShort( 0x6a ),	/* Type Offset=106 */

	/* Parameter pResult */

/* 3870 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3872 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3874 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 3876 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3878 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3880 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Criteria */

/* 3882 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3884 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3888 */	NdrFcShort( 0x5 ),	/* 5 */
/* 3890 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3892 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3894 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3896 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 3898 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3900 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3902 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3904 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppWsbCollection */

/* 3906 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3908 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3910 */	NdrFcShort( 0x236 ),	/* Type Offset=566 */

	/* Return value */

/* 3912 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3914 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3916 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure EnumCriteria */

/* 3918 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3920 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3924 */	NdrFcShort( 0x6 ),	/* 6 */
/* 3926 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3928 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3930 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3932 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 3934 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3936 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3938 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3940 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppEnum */

/* 3942 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3944 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3946 */	NdrFcShort( 0x1ce ),	/* Type Offset=462 */

	/* Return value */

/* 3948 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3950 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3952 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsInclude */

/* 3954 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3956 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3960 */	NdrFcShort( 0xa ),	/* 10 */
/* 3962 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3964 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3966 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3968 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 3970 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3972 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3974 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3976 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 3978 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3980 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3982 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsUserDefined */

/* 3984 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3986 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3990 */	NdrFcShort( 0xb ),	/* 11 */
/* 3992 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3994 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3996 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3998 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 4000 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4002 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4004 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4006 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 4008 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4010 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4012 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsUsedInSubDirs */

/* 4014 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4016 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4020 */	NdrFcShort( 0xc ),	/* 12 */
/* 4022 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4024 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4026 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4028 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 4030 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4032 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4034 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4036 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 4038 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4040 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4042 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MatchesName */

/* 4044 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4046 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4050 */	NdrFcShort( 0xd ),	/* 13 */
/* 4052 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4054 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4056 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4058 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 4060 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4062 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4064 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4066 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 4068 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 4070 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4072 */	NdrFcShort( 0x6a ),	/* Type Offset=106 */

	/* Return value */

/* 4074 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4076 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4078 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetIsInclude */

/* 4080 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4082 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4086 */	NdrFcShort( 0xe ),	/* 14 */
/* 4088 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4090 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4092 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4094 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4096 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4098 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4100 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4102 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter isInclude */

/* 4104 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4106 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4108 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4110 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4112 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4114 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetName */

/* 4116 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4118 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4122 */	NdrFcShort( 0x11 ),	/* 17 */
/* 4124 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4126 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4128 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4130 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 4132 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4134 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4136 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4138 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 4140 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 4142 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4144 */	NdrFcShort( 0x6a ),	/* Type Offset=106 */

	/* Return value */

/* 4146 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4148 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4150 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetPath */

/* 4152 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4154 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4158 */	NdrFcShort( 0x12 ),	/* 18 */
/* 4160 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4162 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4164 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4166 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 4168 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4170 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4172 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4174 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter path */

/* 4176 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 4178 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4180 */	NdrFcShort( 0x6a ),	/* Type Offset=106 */

	/* Return value */

/* 4182 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4184 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4186 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Do */

/* 4188 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4190 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4194 */	NdrFcShort( 0x3 ),	/* 3 */
/* 4196 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4198 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4200 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4202 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 4204 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4206 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4208 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4210 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pScanItem */

/* 4212 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 4214 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4216 */	NdrFcShort( 0x25e ),	/* Type Offset=606 */

	/* Return value */

/* 4218 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4220 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4222 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DoesMatch */

/* 4224 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4226 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4230 */	NdrFcShort( 0x4 ),	/* 4 */
/* 4232 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4234 */	NdrFcShort( 0x1c ),	/* 28 */
/* 4236 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4238 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 4240 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4242 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4244 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4246 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pScanItem */

/* 4248 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 4250 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4252 */	NdrFcShort( 0x25e ),	/* Type Offset=606 */

	/* Parameter pShouldDo */

/* 4254 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 4256 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4258 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4260 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4262 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4264 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Init */

/* 4266 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4268 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4272 */	NdrFcShort( 0x5 ),	/* 5 */
/* 4274 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4276 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4278 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4280 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 4282 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4284 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4286 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4288 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPolicy */

/* 4290 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 4292 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4294 */	NdrFcShort( 0x274 ),	/* Type Offset=628 */

	/* Parameter pResource */

/* 4296 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 4298 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4300 */	NdrFcShort( 0x286 ),	/* Type Offset=646 */

	/* Return value */

/* 4302 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4304 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4306 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Push */

/* 4308 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4310 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4314 */	NdrFcShort( 0x7 ),	/* 7 */
/* 4316 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4318 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4320 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4322 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 4324 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4326 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4328 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4330 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter path */

/* 4332 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 4334 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4336 */	NdrFcShort( 0x6a ),	/* Type Offset=106 */

	/* Return value */

/* 4338 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4340 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4342 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Start */

/* 4344 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4346 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4350 */	NdrFcShort( 0x3 ),	/* 3 */
/* 4352 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4354 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4356 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4358 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 4360 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4362 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4364 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4366 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSession */

/* 4368 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 4370 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4372 */	NdrFcShort( 0x194 ),	/* Type Offset=404 */

	/* Parameter path */

/* 4374 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 4376 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4378 */	NdrFcShort( 0x6a ),	/* Type Offset=106 */

	/* Return value */

/* 4380 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4382 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4384 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure EnumPhases */

/* 4386 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4388 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4392 */	NdrFcShort( 0x4 ),	/* 4 */
/* 4394 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4396 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4398 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4400 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 4402 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4404 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4406 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4408 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppEnum */

/* 4410 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 4412 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4414 */	NdrFcShort( 0x1ce ),	/* Type Offset=462 */

	/* Return value */

/* 4416 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4418 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4420 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure EnumTotals */

/* 4422 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4424 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4428 */	NdrFcShort( 0x5 ),	/* 5 */
/* 4430 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4432 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4434 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4436 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 4438 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4440 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4442 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4444 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppEnum */

/* 4446 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 4448 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4450 */	NdrFcShort( 0x1ce ),	/* Type Offset=462 */

	/* Return value */

/* 4452 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4454 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4456 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetAdviseInterval */

/* 4458 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4460 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4464 */	NdrFcShort( 0x6 ),	/* 6 */
/* 4466 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4468 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4470 */	NdrFcShort( 0x2c ),	/* 44 */
/* 4472 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4474 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4476 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4478 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4480 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFiletimeTicks */

/* 4482 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4484 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4486 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 4488 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4490 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4492 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetHsmId */

/* 4494 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4496 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4500 */	NdrFcShort( 0x7 ),	/* 7 */
/* 4502 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4504 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4506 */	NdrFcShort( 0x4c ),	/* 76 */
/* 4508 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4510 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4512 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4514 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4516 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */

/* 4518 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 4520 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4522 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Return value */

/* 4524 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4526 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4528 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetIdentifier */

/* 4530 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4532 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4536 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4538 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4540 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4542 */	NdrFcShort( 0x4c ),	/* 76 */
/* 4544 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4546 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4548 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4550 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4552 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */

/* 4554 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 4556 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4558 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Return value */

/* 4560 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4562 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4564 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetJob */

/* 4566 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4568 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4572 */	NdrFcShort( 0x9 ),	/* 9 */
/* 4574 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4576 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4578 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4580 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 4582 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4584 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4586 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4588 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppJob */

/* 4590 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 4592 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4594 */	NdrFcShort( 0x298 ),	/* Type Offset=664 */

	/* Return value */

/* 4596 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4598 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4600 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetName */

/* 4602 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4604 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4608 */	NdrFcShort( 0xa ),	/* 10 */
/* 4610 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4612 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4614 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4616 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 4618 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4620 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4622 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4624 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */

/* 4626 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 4628 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4630 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter bufferSize */

/* 4632 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4634 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4636 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4638 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4640 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4642 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetResource */

/* 4644 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4646 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4650 */	NdrFcShort( 0xb ),	/* 11 */
/* 4652 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4654 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4656 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4658 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 4660 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4662 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4664 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4666 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppResource */

/* 4668 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 4670 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4672 */	NdrFcShort( 0x2ae ),	/* Type Offset=686 */

	/* Return value */

/* 4674 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4676 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4678 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSubRunId */

/* 4680 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4682 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4686 */	NdrFcShort( 0xd ),	/* 13 */
/* 4688 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4690 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4692 */	NdrFcShort( 0x24 ),	/* 36 */
/* 4694 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4696 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4698 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4700 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4702 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */

/* 4704 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4706 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4708 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4710 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4712 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4714 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsCanceling */

/* 4716 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4718 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4722 */	NdrFcShort( 0xe ),	/* 14 */
/* 4724 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4726 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4728 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4730 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 4732 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4734 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4736 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4738 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 4740 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4742 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4744 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Pause */

/* 4746 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4748 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4752 */	NdrFcShort( 0xf ),	/* 15 */
/* 4754 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4756 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4758 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4760 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4762 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4764 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4766 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4768 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter phase */

/* 4770 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4772 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4774 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 4776 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4778 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4780 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ProcessEvent */

/* 4782 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4784 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4788 */	NdrFcShort( 0x10 ),	/* 16 */
/* 4790 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4792 */	NdrFcShort( 0x10 ),	/* 16 */
/* 4794 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4796 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 4798 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4800 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4802 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4804 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter phase */

/* 4806 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4808 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4810 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter event */

/* 4812 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4814 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4816 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 4818 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4820 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4822 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ProcessHr */

/* 4824 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4826 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4830 */	NdrFcShort( 0x11 ),	/* 17 */
/* 4832 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4834 */	NdrFcShort( 0x18 ),	/* 24 */
/* 4836 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4838 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 4840 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4842 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4844 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4846 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter phase */

/* 4848 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4850 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4852 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter file */

/* 4854 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 4856 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4858 */	NdrFcShort( 0x2c6 ),	/* Type Offset=710 */

	/* Parameter line */

/* 4860 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4862 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4864 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter hr */

/* 4866 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4868 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4870 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4872 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4874 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 4876 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ProcessItem */

/* 4878 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4880 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4884 */	NdrFcShort( 0x12 ),	/* 18 */
/* 4886 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4888 */	NdrFcShort( 0x18 ),	/* 24 */
/* 4890 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4892 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 4894 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4896 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4898 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4900 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter phase */

/* 4902 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4904 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4906 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter action */

/* 4908 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4910 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4912 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter pScanItem */

/* 4914 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 4916 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4918 */	NdrFcShort( 0x2c8 ),	/* Type Offset=712 */

	/* Parameter hrItem */

/* 4920 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4922 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4924 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4926 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4928 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 4930 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ProcessMediaState */

/* 4932 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4934 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4938 */	NdrFcShort( 0x13 ),	/* 19 */
/* 4940 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 4942 */	NdrFcShort( 0x20 ),	/* 32 */
/* 4944 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4946 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 4948 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4950 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4952 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4954 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter phase */

/* 4956 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4958 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4960 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter state */

/* 4962 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4964 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4966 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter mediaName */

/* 4968 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 4970 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4972 */	NdrFcShort( 0x6a ),	/* Type Offset=106 */

	/* Parameter mediaType */

/* 4974 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4976 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4978 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter time */

/* 4980 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4982 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 4984 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4986 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4988 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4990 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ProcessPriority */

/* 4992 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4994 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4998 */	NdrFcShort( 0x14 ),	/* 20 */
/* 5000 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5002 */	NdrFcShort( 0x10 ),	/* 16 */
/* 5004 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5006 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 5008 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5010 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5012 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5014 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter phase */

/* 5016 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5018 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5020 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter priority */

/* 5022 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5024 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5026 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 5028 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5030 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5032 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ProcessState */

/* 5034 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5036 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5040 */	NdrFcShort( 0x15 ),	/* 21 */
/* 5042 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5044 */	NdrFcShort( 0x18 ),	/* 24 */
/* 5046 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5048 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 5050 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5052 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5054 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5056 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter phase */

/* 5058 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5060 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5062 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter state */

/* 5064 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5066 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5068 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter currentPath */

/* 5070 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 5072 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5074 */	NdrFcShort( 0x6a ),	/* Type Offset=106 */

	/* Parameter bLog */

/* 5076 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5078 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5080 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5082 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5084 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 5086 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ProcessString */

/* 5088 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5090 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5094 */	NdrFcShort( 0x16 ),	/* 22 */
/* 5096 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5098 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5100 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5102 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 5104 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5106 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5108 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5110 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter phase */

/* 5112 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5114 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5116 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter string */

/* 5118 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 5120 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5122 */	NdrFcShort( 0x6a ),	/* Type Offset=106 */

	/* Return value */

/* 5124 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5126 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5128 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Resume */

/* 5130 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5132 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5136 */	NdrFcShort( 0x17 ),	/* 23 */
/* 5138 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5140 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5142 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5144 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5146 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5148 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5150 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5152 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter phase */

/* 5154 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5156 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5158 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 5160 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5162 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5164 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetAdviseInterval */

/* 5166 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5168 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5172 */	NdrFcShort( 0x18 ),	/* 24 */
/* 5174 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5176 */	NdrFcShort( 0x10 ),	/* 16 */
/* 5178 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5180 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5182 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5184 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5186 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5188 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter filetimeTicks */

/* 5190 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5192 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5194 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 5196 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5198 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5200 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Start */

/* 5202 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5204 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5208 */	NdrFcShort( 0x19 ),	/* 25 */
/* 5210 */	NdrFcShort( 0x30 ),	/* x86 Stack size/offset = 48 */
/* 5212 */	NdrFcShort( 0x48 ),	/* 72 */
/* 5214 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5216 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x8,		/* 8 */
/* 5218 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5220 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5222 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5224 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 5226 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 5228 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5230 */	NdrFcShort( 0x6a ),	/* Type Offset=106 */

	/* Parameter logControl */

/* 5232 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5234 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5236 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter hsmId */

/* 5238 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 5240 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5242 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Parameter pJob */

/* 5244 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5246 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 5248 */	NdrFcShort( 0x29c ),	/* Type Offset=668 */

	/* Parameter pResource */

/* 5250 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5252 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 5254 */	NdrFcShort( 0x2b2 ),	/* Type Offset=690 */

	/* Parameter runId */

/* 5256 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5258 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 5260 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter subRunId */

/* 5262 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5264 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 5266 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5268 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5270 */	NdrFcShort( 0x2c ),	/* x86 Stack size/offset = 44 */
/* 5272 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Suspend */

/* 5274 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5276 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5280 */	NdrFcShort( 0x1a ),	/* 26 */
/* 5282 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5284 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5286 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5288 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5290 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5292 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5294 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5296 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter phase */

/* 5298 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5300 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5302 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 5304 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5306 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5308 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ProcessSessionEvent */

/* 5310 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5312 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5316 */	NdrFcShort( 0x3 ),	/* 3 */
/* 5318 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 5320 */	NdrFcShort( 0x10 ),	/* 16 */
/* 5322 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5324 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 5326 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5328 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5330 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5332 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSession */

/* 5334 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5336 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5338 */	NdrFcShort( 0x1f4 ),	/* Type Offset=500 */

	/* Parameter phase */

/* 5340 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5342 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5344 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter event */

/* 5346 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5348 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5350 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 5352 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5354 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5356 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ProcessSessionItem */


	/* Procedure ProcessSessionItem */

/* 5358 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5360 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5364 */	NdrFcShort( 0x3 ),	/* 3 */
/* 5366 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 5368 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5370 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5372 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 5374 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5376 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5378 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5380 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSession */


	/* Parameter pSession */

/* 5382 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5384 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5386 */	NdrFcShort( 0x1f4 ),	/* Type Offset=500 */

	/* Parameter pPhase */


	/* Parameter pPhase */

/* 5388 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5390 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5392 */	NdrFcShort( 0x20a ),	/* Type Offset=522 */

	/* Parameter pScanItem */


	/* Parameter pScanItem */

/* 5394 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5396 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5398 */	NdrFcShort( 0x2c8 ),	/* Type Offset=712 */

	/* Parameter hrItem */


	/* Parameter hrItem */

/* 5400 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5402 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5404 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pSessionTotals */


	/* Parameter pSessionTotals */

/* 5406 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5408 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 5410 */	NdrFcShort( 0x2da ),	/* Type Offset=730 */

	/* Return value */


	/* Return value */

/* 5412 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5414 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5416 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ProcessSessionMediaState */

/* 5418 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5420 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5424 */	NdrFcShort( 0x3 ),	/* 3 */
/* 5426 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 5428 */	NdrFcShort( 0x18 ),	/* 24 */
/* 5430 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5432 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 5434 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5436 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5438 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5440 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSession */

/* 5442 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5444 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5446 */	NdrFcShort( 0x1f4 ),	/* Type Offset=500 */

	/* Parameter pPhase */

/* 5448 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5450 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5452 */	NdrFcShort( 0x20a ),	/* Type Offset=522 */

	/* Parameter state */

/* 5454 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5456 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5458 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter mediaName */

/* 5460 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 5462 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5464 */	NdrFcShort( 0x6a ),	/* Type Offset=106 */

	/* Parameter mediaType */

/* 5466 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5468 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 5470 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter time */

/* 5472 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5474 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5476 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5478 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5480 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 5482 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ProcessSessionPriority */

/* 5484 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5486 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5490 */	NdrFcShort( 0x3 ),	/* 3 */
/* 5492 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5494 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5496 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5498 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 5500 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5502 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5504 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5506 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSession */

/* 5508 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5510 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5512 */	NdrFcShort( 0x1f4 ),	/* Type Offset=500 */

	/* Parameter pPhase */

/* 5514 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5516 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5518 */	NdrFcShort( 0x20a ),	/* Type Offset=522 */

	/* Return value */

/* 5520 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5522 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5524 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ProcessSessionState */

/* 5526 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5528 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5532 */	NdrFcShort( 0x3 ),	/* 3 */
/* 5534 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 5536 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5538 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5540 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 5542 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5544 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5546 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5548 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSession */

/* 5550 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5552 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5554 */	NdrFcShort( 0x1f4 ),	/* Type Offset=500 */

	/* Parameter pPhase */

/* 5556 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5558 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5560 */	NdrFcShort( 0x20a ),	/* Type Offset=522 */

	/* Parameter currentPath */

/* 5562 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 5564 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5566 */	NdrFcShort( 0x6a ),	/* Type Offset=106 */

	/* Return value */

/* 5568 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5570 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5572 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Clone */

/* 5574 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5576 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5580 */	NdrFcShort( 0x3 ),	/* 3 */
/* 5582 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5584 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5586 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5588 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 5590 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5592 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5594 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5596 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppSessionTotals */

/* 5598 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 5600 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5602 */	NdrFcShort( 0x2ec ),	/* Type Offset=748 */

	/* Return value */

/* 5604 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5606 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5608 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CopyTo */

/* 5610 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5612 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5616 */	NdrFcShort( 0x4 ),	/* 4 */
/* 5618 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5620 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5622 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5624 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 5626 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5628 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5630 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5632 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSessionTotals */

/* 5634 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5636 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5638 */	NdrFcShort( 0x2da ),	/* Type Offset=730 */

	/* Return value */

/* 5640 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5642 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5644 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToAction */

/* 5646 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5648 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5652 */	NdrFcShort( 0x5 ),	/* 5 */
/* 5654 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5656 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5658 */	NdrFcShort( 0x22 ),	/* 34 */
/* 5660 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 5662 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5664 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5666 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5668 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter action */

/* 5670 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5672 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5674 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter pResult */

/* 5676 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5678 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5680 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 5682 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5684 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5686 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToISessionTotals */

/* 5688 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5690 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5694 */	NdrFcShort( 0x6 ),	/* 6 */
/* 5696 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5698 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5700 */	NdrFcShort( 0x22 ),	/* 34 */
/* 5702 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 5704 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5706 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5708 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5710 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pTotals */

/* 5712 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5714 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5716 */	NdrFcShort( 0x2da ),	/* Type Offset=730 */

	/* Parameter pResult */

/* 5718 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5720 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5722 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 5724 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5726 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5728 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetStats */

/* 5730 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5732 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5736 */	NdrFcShort( 0x9 ),	/* 9 */
/* 5738 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 5740 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5742 */	NdrFcShort( 0xe0 ),	/* 224 */
/* 5744 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x7,		/* 7 */
/* 5746 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5748 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5750 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5752 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter items */

/* 5754 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5756 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5758 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 5760 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5762 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5764 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter skippedItems */

/* 5766 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5768 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5770 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter skippedSize */

/* 5772 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5774 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5776 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter errorItems */

/* 5778 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5780 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 5782 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter errorSize */

/* 5784 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5786 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5788 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 5790 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5792 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 5794 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/*  4 */	NdrFcShort( 0x2 ),	/* Offset= 2 (6) */
/*  6 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/*  8 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 10 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 12 */	NdrFcLong( 0x87e7ed0 ),	/* 142507728 */
/* 16 */	NdrFcShort( 0x727a ),	/* 29306 */
/* 18 */	NdrFcShort( 0x11d2 ),	/* 4562 */
/* 20 */	0x9c,		/* 156 */
			0xd3,		/* 211 */
/* 22 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 24 */	0xc9,		/* 201 */
			0x11,		/* 17 */
/* 26 */	0x81,		/* 129 */
			0x2,		/* 2 */
/* 28 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 30 */	NdrFcLong( 0xb8e1cd20 ),	/* -1193161440 */
/* 34 */	NdrFcShort( 0x81d3 ),	/* -32301 */
/* 36 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 38 */	0x81,		/* 129 */
			0xe4,		/* 228 */
/* 40 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 42 */	0xc9,		/* 201 */
			0x11,		/* 17 */
/* 44 */	0x80,		/* 128 */
			0xf2,		/* 242 */
/* 46 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 48 */	NdrFcLong( 0x2fa5166a ),	/* 799348330 */
/* 52 */	NdrFcShort( 0xd28b ),	/* -11637 */
/* 54 */	NdrFcShort( 0x49d4 ),	/* 18900 */
/* 56 */	0xb5,		/* 181 */
			0xf8,		/* 248 */
/* 58 */	0xb1,		/* 177 */
			0x2b,		/* 43 */
/* 60 */	0x32,		/* 50 */
			0x1,		/* 1 */
/* 62 */	0xc1,		/* 193 */
			0xc4,		/* 196 */
/* 64 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 66 */	NdrFcLong( 0x172f71cd ),	/* 388985293 */
/* 70 */	NdrFcShort( 0xa452 ),	/* -23470 */
/* 72 */	NdrFcShort( 0x4005 ),	/* 16389 */
/* 74 */	0x8e,		/* 142 */
			0x3e,		/* 62 */
/* 76 */	0x7b,		/* 123 */
			0xce,		/* 206 */
/* 78 */	0xae,		/* 174 */
			0x12,		/* 18 */
/* 80 */	0x4d,		/* 77 */
			0x53,		/* 83 */
/* 82 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 84 */	NdrFcLong( 0x6e7196dc ),	/* 1852937948 */
/* 88 */	NdrFcShort( 0x7f9c ),	/* 32668 */
/* 90 */	NdrFcShort( 0x460d ),	/* 17933 */
/* 92 */	0x9e,		/* 158 */
			0x97,		/* 151 */
/* 94 */	0x84,		/* 132 */
			0x54,		/* 84 */
/* 96 */	0x90,		/* 144 */
			0xb8,		/* 184 */
/* 98 */	0x1d,		/* 29 */
			0x60,		/* 96 */
/* 100 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 102 */	0xe,		/* FC_ENUM32 */
			0x5c,		/* FC_PAD */
/* 104 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 106 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 108 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 110 */	NdrFcShort( 0x8 ),	/* Offset= 8 (118) */
/* 112 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 114 */	NdrFcShort( 0x8 ),	/* 8 */
/* 116 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 118 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 120 */	NdrFcShort( 0x10 ),	/* 16 */
/* 122 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 124 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 126 */	0x0,		/* 0 */
			NdrFcShort( 0xfff1 ),	/* Offset= -15 (112) */
			0x5b,		/* FC_END */
/* 130 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 132 */	NdrFcShort( 0x2 ),	/* Offset= 2 (134) */
/* 134 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 136 */	NdrFcLong( 0x9c7d6f14 ),	/* -1669501164 */
/* 140 */	NdrFcShort( 0x1562 ),	/* 5474 */
/* 142 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 144 */	0x81,		/* 129 */
			0xac,		/* 172 */
/* 146 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 148 */	0xc9,		/* 201 */
			0x11,		/* 17 */
/* 150 */	0x80,		/* 128 */
			0xf2,		/* 242 */
/* 152 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 154 */	NdrFcLong( 0x6e7196dc ),	/* 1852937948 */
/* 158 */	NdrFcShort( 0x7f9c ),	/* 32668 */
/* 160 */	NdrFcShort( 0x460d ),	/* 17933 */
/* 162 */	0x9e,		/* 158 */
			0x97,		/* 151 */
/* 164 */	0x84,		/* 132 */
			0x54,		/* 84 */
/* 166 */	0x90,		/* 144 */
			0xb8,		/* 184 */
/* 168 */	0x1d,		/* 29 */
			0x60,		/* 96 */
/* 170 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 172 */	NdrFcShort( 0xff70 ),	/* Offset= -144 (28) */
/* 174 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 176 */	NdrFcShort( 0x2 ),	/* Offset= 2 (178) */
/* 178 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 180 */	NdrFcLong( 0xad402360 ),	/* -1388305568 */
/* 184 */	NdrFcShort( 0xfc ),	/* 252 */
/* 186 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 188 */	0x81,		/* 129 */
			0x9c,		/* 156 */
/* 190 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 192 */	0xc9,		/* 201 */
			0x11,		/* 17 */
/* 194 */	0x80,		/* 128 */
			0xf2,		/* 242 */
/* 196 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 198 */	NdrFcShort( 0x2 ),	/* Offset= 2 (200) */
/* 200 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 202 */	NdrFcLong( 0x2fa5166a ),	/* 799348330 */
/* 206 */	NdrFcShort( 0xd28b ),	/* -11637 */
/* 208 */	NdrFcShort( 0x49d4 ),	/* 18900 */
/* 210 */	0xb5,		/* 181 */
			0xf8,		/* 248 */
/* 212 */	0xb1,		/* 177 */
			0x2b,		/* 43 */
/* 214 */	0x32,		/* 50 */
			0x1,		/* 1 */
/* 216 */	0xc1,		/* 193 */
			0xc4,		/* 196 */
/* 218 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 220 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 222 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 224 */	NdrFcLong( 0xe372f85b ),	/* -479004581 */
/* 228 */	NdrFcShort( 0xd72b ),	/* -10453 */
/* 230 */	NdrFcShort( 0x4a7d ),	/* 19069 */
/* 232 */	0xb0,		/* 176 */
			0xf6,		/* 246 */
/* 234 */	0x2b,		/* 43 */
			0xcf,		/* 207 */
/* 236 */	0x8f,		/* 143 */
			0xed,		/* 237 */
/* 238 */	0x88,		/* 136 */
			0xb9,		/* 185 */
/* 240 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 242 */	NdrFcLong( 0x172f71cd ),	/* 388985293 */
/* 246 */	NdrFcShort( 0xa452 ),	/* -23470 */
/* 248 */	NdrFcShort( 0x4005 ),	/* 16389 */
/* 250 */	0x8e,		/* 142 */
			0x3e,		/* 62 */
/* 252 */	0x7b,		/* 123 */
			0xce,		/* 206 */
/* 254 */	0xae,		/* 174 */
			0x12,		/* 18 */
/* 256 */	0x4d,		/* 77 */
			0x53,		/* 83 */
/* 258 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 260 */	NdrFcLong( 0xad402360 ),	/* -1388305568 */
/* 264 */	NdrFcShort( 0xfc ),	/* 252 */
/* 266 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 268 */	0x81,		/* 129 */
			0x9c,		/* 156 */
/* 270 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 272 */	0xc9,		/* 201 */
			0x11,		/* 17 */
/* 274 */	0x80,		/* 128 */
			0xf2,		/* 242 */
/* 276 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 278 */	NdrFcLong( 0x2fa5166a ),	/* 799348330 */
/* 282 */	NdrFcShort( 0xd28b ),	/* -11637 */
/* 284 */	NdrFcShort( 0x49d4 ),	/* 18900 */
/* 286 */	0xb5,		/* 181 */
			0xf8,		/* 248 */
/* 288 */	0xb1,		/* 177 */
			0x2b,		/* 43 */
/* 290 */	0x32,		/* 50 */
			0x1,		/* 1 */
/* 292 */	0xc1,		/* 193 */
			0xc4,		/* 196 */
/* 294 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 296 */	NdrFcShort( 0x2 ),	/* Offset= 2 (298) */
/* 298 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 300 */	NdrFcLong( 0x9c7d6f14 ),	/* -1669501164 */
/* 304 */	NdrFcShort( 0x1562 ),	/* 5474 */
/* 306 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 308 */	0x81,		/* 129 */
			0xac,		/* 172 */
/* 310 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 312 */	0xc9,		/* 201 */
			0x11,		/* 17 */
/* 314 */	0x80,		/* 128 */
			0xf2,		/* 242 */
/* 316 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 318 */	NdrFcShort( 0x2 ),	/* Offset= 2 (320) */
/* 320 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 322 */	NdrFcLong( 0x9c7d6f0f ),	/* -1669501169 */
/* 326 */	NdrFcShort( 0x1562 ),	/* 5474 */
/* 328 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 330 */	0x81,		/* 129 */
			0xac,		/* 172 */
/* 332 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 334 */	0xc9,		/* 201 */
			0x11,		/* 17 */
/* 336 */	0x80,		/* 128 */
			0xf2,		/* 242 */
/* 338 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 340 */	NdrFcShort( 0x2 ),	/* Offset= 2 (342) */
/* 342 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 344 */	NdrFcLong( 0xad613d1 ),	/* 181801937 */
/* 348 */	NdrFcShort( 0x18be ),	/* 6334 */
/* 350 */	NdrFcShort( 0x11d1 ),	/* 4561 */
/* 352 */	0x99,		/* 153 */
			0x39,		/* 57 */
/* 354 */	0x0,		/* 0 */
			0x60,		/* 96 */
/* 356 */	0x97,		/* 151 */
			0x6a,		/* 106 */
/* 358 */	0x54,		/* 84 */
			0x6d,		/* 109 */
/* 360 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 362 */	NdrFcShort( 0x2 ),	/* Offset= 2 (364) */
/* 364 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 366 */	NdrFcLong( 0xfd8d709c ),	/* -41062244 */
/* 370 */	NdrFcShort( 0x47dd ),	/* 18397 */
/* 372 */	NdrFcShort( 0x4d68 ),	/* 19816 */
/* 374 */	0xbb,		/* 187 */
			0xd5,		/* 213 */
/* 376 */	0x81,		/* 129 */
			0x7e,		/* 126 */
/* 378 */	0xdd,		/* 221 */
			0x93,		/* 147 */
/* 380 */	0x4e,		/* 78 */
			0x4b,		/* 75 */
/* 382 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 384 */	NdrFcShort( 0x2 ),	/* Offset= 2 (386) */
/* 386 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 388 */	NdrFcLong( 0xd7619db3 ),	/* -681468493 */
/* 392 */	NdrFcShort( 0x265e ),	/* 9822 */
/* 394 */	NdrFcShort( 0x4796 ),	/* 18326 */
/* 396 */	0xa9,		/* 169 */
			0x8c,		/* 140 */
/* 398 */	0xf6,		/* 246 */
			0xf2,		/* 242 */
/* 400 */	0x8c,		/* 140 */
			0x2a,		/* 42 */
/* 402 */	0x61,		/* 97 */
			0x8c,		/* 140 */
/* 404 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 406 */	NdrFcLong( 0x6e7196dc ),	/* 1852937948 */
/* 410 */	NdrFcShort( 0x7f9c ),	/* 32668 */
/* 412 */	NdrFcShort( 0x460d ),	/* 17933 */
/* 414 */	0x9e,		/* 158 */
			0x97,		/* 151 */
/* 416 */	0x84,		/* 132 */
			0x54,		/* 84 */
/* 418 */	0x90,		/* 144 */
			0xb8,		/* 184 */
/* 420 */	0x1d,		/* 29 */
			0x60,		/* 96 */
/* 422 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 424 */	NdrFcLong( 0x35035914 ),	/* 889411860 */
/* 428 */	NdrFcShort( 0xd1c ),	/* 3356 */
/* 430 */	NdrFcShort( 0x11d2 ),	/* 4562 */
/* 432 */	0x9b,		/* 155 */
			0xc,		/* 12 */
/* 434 */	0x0,		/* 0 */
			0x10,		/* 16 */
/* 436 */	0x4b,		/* 75 */
			0x9a,		/* 154 */
/* 438 */	0x28,		/* 40 */
			0x69,		/* 105 */
/* 440 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 442 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 444 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 446 */	NdrFcLong( 0xb8e1cd20 ),	/* -1193161440 */
/* 450 */	NdrFcShort( 0x81d3 ),	/* -32301 */
/* 452 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 454 */	0x81,		/* 129 */
			0xe4,		/* 228 */
/* 456 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 458 */	0xc9,		/* 201 */
			0x11,		/* 17 */
/* 460 */	0x80,		/* 128 */
			0xf2,		/* 242 */
/* 462 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 464 */	NdrFcShort( 0x2 ),	/* Offset= 2 (466) */
/* 466 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 468 */	NdrFcLong( 0x9c7d6f14 ),	/* -1669501164 */
/* 472 */	NdrFcShort( 0x1562 ),	/* 5474 */
/* 474 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 476 */	0x81,		/* 129 */
			0xac,		/* 172 */
/* 478 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 480 */	0xc9,		/* 201 */
			0x11,		/* 17 */
/* 482 */	0x80,		/* 128 */
			0xf2,		/* 242 */
/* 484 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 486 */	NdrFcShort( 0x2 ),	/* Offset= 2 (488) */
/* 488 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 490 */	NdrFcShort( 0x8 ),	/* 8 */
/* 492 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 494 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 496 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 498 */	NdrFcShort( 0x2 ),	/* Offset= 2 (500) */
/* 500 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 502 */	NdrFcLong( 0x6e7196dc ),	/* 1852937948 */
/* 506 */	NdrFcShort( 0x7f9c ),	/* 32668 */
/* 508 */	NdrFcShort( 0x460d ),	/* 17933 */
/* 510 */	0x9e,		/* 158 */
			0x97,		/* 151 */
/* 512 */	0x84,		/* 132 */
			0x54,		/* 84 */
/* 514 */	0x90,		/* 144 */
			0xb8,		/* 184 */
/* 516 */	0x1d,		/* 29 */
			0x60,		/* 96 */
/* 518 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 520 */	NdrFcShort( 0x2 ),	/* Offset= 2 (522) */
/* 522 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 524 */	NdrFcLong( 0x35035914 ),	/* 889411860 */
/* 528 */	NdrFcShort( 0xd1c ),	/* 3356 */
/* 530 */	NdrFcShort( 0x11d2 ),	/* 4562 */
/* 532 */	0x9b,		/* 155 */
			0xc,		/* 12 */
/* 534 */	0x0,		/* 0 */
			0x10,		/* 16 */
/* 536 */	0x4b,		/* 75 */
			0x9a,		/* 154 */
/* 538 */	0x28,		/* 40 */
			0x69,		/* 105 */
/* 540 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 542 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */
/* 544 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 546 */	NdrFcShort( 0x2 ),	/* Offset= 2 (548) */
/* 548 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 550 */	NdrFcLong( 0xad402351 ),	/* -1388305583 */
/* 554 */	NdrFcShort( 0xfc ),	/* 252 */
/* 556 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 558 */	0x81,		/* 129 */
			0x9c,		/* 156 */
/* 560 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 562 */	0xc9,		/* 201 */
			0x11,		/* 17 */
/* 564 */	0x80,		/* 128 */
			0xf2,		/* 242 */
/* 566 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 568 */	NdrFcShort( 0x2 ),	/* Offset= 2 (570) */
/* 570 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 572 */	NdrFcLong( 0x9c7d6f0f ),	/* -1669501169 */
/* 576 */	NdrFcShort( 0x1562 ),	/* 5474 */
/* 578 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 580 */	0x81,		/* 129 */
			0xac,		/* 172 */
/* 582 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 584 */	0xc9,		/* 201 */
			0x11,		/* 17 */
/* 586 */	0x80,		/* 128 */
			0xf2,		/* 242 */
/* 588 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 590 */	NdrFcLong( 0xad402356 ),	/* -1388305578 */
/* 594 */	NdrFcShort( 0xfc ),	/* 252 */
/* 596 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 598 */	0x81,		/* 129 */
			0x9c,		/* 156 */
/* 600 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 602 */	0xc9,		/* 201 */
			0x11,		/* 17 */
/* 604 */	0x80,		/* 128 */
			0xf2,		/* 242 */
/* 606 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 608 */	NdrFcLong( 0x87e7ed0 ),	/* 142507728 */
/* 612 */	NdrFcShort( 0x727a ),	/* 29306 */
/* 614 */	NdrFcShort( 0x11d2 ),	/* 4562 */
/* 616 */	0x9c,		/* 156 */
			0xd3,		/* 211 */
/* 618 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 620 */	0xc9,		/* 201 */
			0x11,		/* 17 */
/* 622 */	0x81,		/* 129 */
			0x2,		/* 2 */
/* 624 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 626 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 628 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 630 */	NdrFcLong( 0xad40234c ),	/* -1388305588 */
/* 634 */	NdrFcShort( 0xfc ),	/* 252 */
/* 636 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 638 */	0x81,		/* 129 */
			0x9c,		/* 156 */
/* 640 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 642 */	0xc9,		/* 201 */
			0x11,		/* 17 */
/* 644 */	0x80,		/* 128 */
			0xf2,		/* 242 */
/* 646 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 648 */	NdrFcLong( 0x172f71cd ),	/* 388985293 */
/* 652 */	NdrFcShort( 0xa452 ),	/* -23470 */
/* 654 */	NdrFcShort( 0x4005 ),	/* 16389 */
/* 656 */	0x8e,		/* 142 */
			0x3e,		/* 62 */
/* 658 */	0x7b,		/* 123 */
			0xce,		/* 206 */
/* 660 */	0xae,		/* 174 */
			0x12,		/* 18 */
/* 662 */	0x4d,		/* 77 */
			0x53,		/* 83 */
/* 664 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 666 */	NdrFcShort( 0x2 ),	/* Offset= 2 (668) */
/* 668 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 670 */	NdrFcLong( 0x2a87c7e2 ),	/* 713541602 */
/* 674 */	NdrFcShort( 0xdb24 ),	/* -9436 */
/* 676 */	NdrFcShort( 0x11d2 ),	/* 4562 */
/* 678 */	0xaf,		/* 175 */
			0xa2,		/* 162 */
/* 680 */	0x0,		/* 0 */
			0x10,		/* 16 */
/* 682 */	0x4b,		/* 75 */
			0x9a,		/* 154 */
/* 684 */	0x37,		/* 55 */
			0x58,		/* 88 */
/* 686 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 688 */	NdrFcShort( 0x2 ),	/* Offset= 2 (690) */
/* 690 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 692 */	NdrFcLong( 0x172f71cd ),	/* 388985293 */
/* 696 */	NdrFcShort( 0xa452 ),	/* -23470 */
/* 698 */	NdrFcShort( 0x4005 ),	/* 16389 */
/* 700 */	0x8e,		/* 142 */
			0x3e,		/* 62 */
/* 702 */	0x7b,		/* 123 */
			0xce,		/* 206 */
/* 704 */	0xae,		/* 174 */
			0x12,		/* 18 */
/* 706 */	0x4d,		/* 77 */
			0x53,		/* 83 */
/* 708 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 710 */	
			0x22,		/* FC_C_CSTRING */
			0x5c,		/* FC_PAD */
/* 712 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 714 */	NdrFcLong( 0x87e7ed0 ),	/* 142507728 */
/* 718 */	NdrFcShort( 0x727a ),	/* 29306 */
/* 720 */	NdrFcShort( 0x11d2 ),	/* 4562 */
/* 722 */	0x9c,		/* 156 */
			0xd3,		/* 211 */
/* 724 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 726 */	0xc9,		/* 201 */
			0x11,		/* 17 */
/* 728 */	0x81,		/* 129 */
			0x2,		/* 2 */
/* 730 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 732 */	NdrFcLong( 0x35035913 ),	/* 889411859 */
/* 736 */	NdrFcShort( 0xd1c ),	/* 3356 */
/* 738 */	NdrFcShort( 0x11d2 ),	/* 4562 */
/* 740 */	0x9b,		/* 155 */
			0xc,		/* 12 */
/* 742 */	0x0,		/* 0 */
			0x10,		/* 16 */
/* 744 */	0x4b,		/* 75 */
			0x9a,		/* 154 */
/* 746 */	0x28,		/* 40 */
			0x69,		/* 105 */
/* 748 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 750 */	NdrFcShort( 0xffec ),	/* Offset= -20 (730) */

			0x0
        }
    };


/* Standard interface: __MIDL_itf_jobint_0000, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IHsmAction, ver. 0.0,
   GUID={0xAD402351,0x00FC,0x11D0,{0x81,0x9C,0x00,0xA0,0xC9,0x11,0x80,0xF2}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmAction_FormatStringOffsetTable[] =
    {
    0,
    42
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmAction_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmAction_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmAction_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmAction_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(5) _IHsmActionProxyVtbl = 
{
    &IHsmAction_ProxyInfo,
    &IID_IHsmAction,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmAction::GetName */ ,
    (void *) (INT_PTR) -1 /* IHsmAction::Do */
};

const CInterfaceStubVtbl _IHsmActionStubVtbl =
{
    &IID_IHsmAction,
    &IHsmAction_ServerInfo,
    5,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmActionOnResource, ver. 0.0,
   GUID={0xD9E04213,0x14D7,0x11d1,{0x99,0x38,0x00,0x60,0x97,0x6A,0x54,0x6D}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmActionOnResource_FormatStringOffsetTable[] =
    {
    0
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmActionOnResource_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmActionOnResource_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmActionOnResource_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmActionOnResource_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IHsmActionOnResourceProxyVtbl = 
{
    &IHsmActionOnResource_ProxyInfo,
    &IID_IHsmActionOnResource,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmActionOnResource::GetName */
};

const CInterfaceStubVtbl _IHsmActionOnResourceStubVtbl =
{
    &IID_IHsmActionOnResource,
    &IHsmActionOnResource_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmActionOnResourcePost, ver. 0.0,
   GUID={0x0AD613D1,0x18BE,0x11d1,{0x99,0x39,0x00,0x60,0x97,0x6A,0x54,0x6D}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmActionOnResourcePost_FormatStringOffsetTable[] =
    {
    78
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmActionOnResourcePost_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmActionOnResourcePost_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmActionOnResourcePost_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmActionOnResourcePost_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IHsmActionOnResourcePostProxyVtbl = 
{
    &IHsmActionOnResourcePost_ProxyInfo,
    &IID_IHsmActionOnResourcePost,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmActionOnResourcePost::Do */
};

const CInterfaceStubVtbl _IHsmActionOnResourcePostStubVtbl =
{
    &IID_IHsmActionOnResourcePost,
    &IHsmActionOnResourcePost_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmActionOnResourcePre, ver. 0.0,
   GUID={0xFD8D709C,0x47DD,0x4D68,{0xBB,0xD5,0x81,0x7E,0xDD,0x93,0x4E,0x4B}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmActionOnResourcePre_FormatStringOffsetTable[] =
    {
    120
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmActionOnResourcePre_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmActionOnResourcePre_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmActionOnResourcePre_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmActionOnResourcePre_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IHsmActionOnResourcePreProxyVtbl = 
{
    &IHsmActionOnResourcePre_ProxyInfo,
    &IID_IHsmActionOnResourcePre,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmActionOnResourcePre::Do */
};

const CInterfaceStubVtbl _IHsmActionOnResourcePreStubVtbl =
{
    &IID_IHsmActionOnResourcePre,
    &IHsmActionOnResourcePre_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmActionOnResourcePreScan, ver. 0.0,
   GUID={0xD7619DB3,0x265E,0x4796,{0xA9,0x8C,0xF6,0xF2,0x8C,0x2A,0x61,0x8C}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmActionOnResourcePreScan_FormatStringOffsetTable[] =
    {
    162
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmActionOnResourcePreScan_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmActionOnResourcePreScan_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmActionOnResourcePreScan_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmActionOnResourcePreScan_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IHsmActionOnResourcePreScanProxyVtbl = 
{
    &IHsmActionOnResourcePreScan_ProxyInfo,
    &IID_IHsmActionOnResourcePreScan,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmActionOnResourcePreScan::Do */
};

const CInterfaceStubVtbl _IHsmActionOnResourcePreScanStubVtbl =
{
    &IID_IHsmActionOnResourcePreScan,
    &IHsmActionOnResourcePreScan_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmCriteria, ver. 0.0,
   GUID={0xAD40235B,0x00FC,0x11D0,{0x81,0x9C,0x00,0xA0,0xC9,0x11,0x80,0xF2}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmCriteria_FormatStringOffsetTable[] =
    {
    0,
    204,
    234,
    264,
    300,
    336,
    378
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmCriteria_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmCriteria_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmCriteria_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmCriteria_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(10) _IHsmCriteriaProxyVtbl = 
{
    &IHsmCriteria_ProxyInfo,
    &IID_IHsmCriteria,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmCriteria::GetName */ ,
    (void *) (INT_PTR) -1 /* IHsmCriteria::IsIgnored */ ,
    (void *) (INT_PTR) -1 /* IHsmCriteria::IsNegated */ ,
    (void *) (INT_PTR) -1 /* IHsmCriteria::SetIsIgnored */ ,
    (void *) (INT_PTR) -1 /* IHsmCriteria::SetIsNegated */ ,
    (void *) (INT_PTR) -1 /* IHsmCriteria::ShouldDo */ ,
    (void *) (INT_PTR) -1 /* IHsmCriteria::Value */
};

const CInterfaceStubVtbl _IHsmCriteriaStubVtbl =
{
    &IID_IHsmCriteria,
    &IHsmCriteria_ServerInfo,
    10,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmRelativeCriteria, ver. 0.0,
   GUID={0x2B382EA1,0x16EA,0x11D0,{0x81,0xAE,0x00,0xA0,0xC9,0x11,0x80,0xF2}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmRelativeCriteria_FormatStringOffsetTable[] =
    {
    0,
    204,
    426,
    468,
    510,
    546,
    582,
    618
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmRelativeCriteria_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmRelativeCriteria_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmRelativeCriteria_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmRelativeCriteria_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(11) _IHsmRelativeCriteriaProxyVtbl = 
{
    &IHsmRelativeCriteria_ProxyInfo,
    &IID_IHsmRelativeCriteria,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmRelativeCriteria::ComparatorAsString */ ,
    (void *) (INT_PTR) -1 /* IHsmRelativeCriteria::ComparatorIsBinary */ ,
    (void *) (INT_PTR) -1 /* IHsmRelativeCriteria::GetArg1 */ ,
    (void *) (INT_PTR) -1 /* IHsmRelativeCriteria::GetArg2 */ ,
    (void *) (INT_PTR) -1 /* IHsmRelativeCriteria::GetComparator */ ,
    (void *) (INT_PTR) -1 /* IHsmRelativeCriteria::SetArg1 */ ,
    (void *) (INT_PTR) -1 /* IHsmRelativeCriteria::SetArg2 */ ,
    (void *) (INT_PTR) -1 /* IHsmRelativeCriteria::SetComparator */
};

const CInterfaceStubVtbl _IHsmRelativeCriteriaStubVtbl =
{
    &IID_IHsmRelativeCriteria,
    &IHsmRelativeCriteria_ServerInfo,
    11,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmDirectedAction, ver. 0.0,
   GUID={0xC7A01572,0x187A,0x11D0,{0x81,0xB0,0x00,0xA0,0xC9,0x11,0x80,0xF2}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmDirectedAction_FormatStringOffsetTable[] =
    {
    654,
    690
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmDirectedAction_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmDirectedAction_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmDirectedAction_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmDirectedAction_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(5) _IHsmDirectedActionProxyVtbl = 
{
    &IHsmDirectedAction_ProxyInfo,
    &IID_IHsmDirectedAction,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmDirectedAction::GetStoragePoolId */ ,
    (void *) (INT_PTR) -1 /* IHsmDirectedAction::SetStoragePoolId */
};

const CInterfaceStubVtbl _IHsmDirectedActionStubVtbl =
{
    &IID_IHsmDirectedAction,
    &IHsmDirectedAction_ServerInfo,
    5,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmJob, ver. 0.0,
   GUID={0x2A87C7E2,0xDB24,0x11d2,{0xAF,0xA2,0x00,0x10,0x4B,0x9A,0x37,0x58}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmJob_FormatStringOffsetTable[] =
    {
    726,
    204,
    234,
    762,
    798,
    840,
    876,
    912,
    948,
    984,
    1020,
    1062,
    1098,
    1134,
    1206,
    1236,
    1266,
    1302,
    1332,
    1368,
    1404,
    1440,
    1476,
    1512,
    1548,
    1578,
    1614
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmJob_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmJob_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmJob_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmJob_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(30) _IHsmJobProxyVtbl = 
{
    &IHsmJob_ProxyInfo,
    &IID_IHsmJob,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmJob::Cancel */ ,
    (void *) (INT_PTR) -1 /* IHsmJob::DidFinish */ ,
    (void *) (INT_PTR) -1 /* IHsmJob::DidFinishOk */ ,
    (void *) (INT_PTR) -1 /* IHsmJob::EnumWorkItems */ ,
    (void *) (INT_PTR) -1 /* IHsmJob::FindWorkItem */ ,
    (void *) (INT_PTR) -1 /* IHsmJob::GetContext */ ,
    (void *) (INT_PTR) -1 /* IHsmJob::GetDef */ ,
    (void *) (INT_PTR) -1 /* IHsmJob::GetHsmId */ ,
    (void *) (INT_PTR) -1 /* IHsmJob::GetIdentifier */ ,
    (void *) (INT_PTR) -1 /* IHsmJob::GetMaxActiveSessions */ ,
    (void *) (INT_PTR) -1 /* IHsmJob::GetName */ ,
    (void *) (INT_PTR) -1 /* IHsmJob::GetRunId */ ,
    (void *) (INT_PTR) -1 /* IHsmJob::GetState */ ,
    (void *) (INT_PTR) -1 /* IHsmJob::InitAs */ ,
    (void *) (INT_PTR) -1 /* IHsmJob::IsActive */ ,
    (void *) (INT_PTR) -1 /* IHsmJob::IsUserDefined */ ,
    (void *) (INT_PTR) -1 /* IHsmJob::Pause */ ,
    (void *) (INT_PTR) -1 /* IHsmJob::Restart */ ,
    (void *) (INT_PTR) -1 /* IHsmJob::Resume */ ,
    (void *) (INT_PTR) -1 /* IHsmJob::SetContext */ ,
    (void *) (INT_PTR) -1 /* IHsmJob::SetDef */ ,
    (void *) (INT_PTR) -1 /* IHsmJob::SetHsmId */ ,
    (void *) (INT_PTR) -1 /* IHsmJob::SetIsUserDefined */ ,
    (void *) (INT_PTR) -1 /* IHsmJob::SetName */ ,
    (void *) (INT_PTR) -1 /* IHsmJob::Start */ ,
    (void *) (INT_PTR) -1 /* IHsmJob::Suspend */ ,
    (void *) (INT_PTR) -1 /* IHsmJob::WaitUntilDone */
};

const CInterfaceStubVtbl _IHsmJobStubVtbl =
{
    &IID_IHsmJob,
    &IHsmJob_ServerInfo,
    30,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmJobContext, ver. 0.0,
   GUID={0xAD402360,0x00FC,0x11D0,{0x81,0x9C,0x00,0xA0,0xC9,0x11,0x80,0xF2}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmJobContext_FormatStringOffsetTable[] =
    {
    1644,
    1680,
    1716,
    1752
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmJobContext_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmJobContext_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmJobContext_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmJobContext_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(7) _IHsmJobContextProxyVtbl = 
{
    &IHsmJobContext_ProxyInfo,
    &IID_IHsmJobContext,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmJobContext::EnumResources */ ,
    (void *) (INT_PTR) -1 /* IHsmJobContext::Resources */ ,
    (void *) (INT_PTR) -1 /* IHsmJobContext::SetUsesAllManaged */ ,
    (void *) (INT_PTR) -1 /* IHsmJobContext::UsesAllManaged */
};

const CInterfaceStubVtbl _IHsmJobContextStubVtbl =
{
    &IID_IHsmJobContext,
    &IHsmJobContext_ServerInfo,
    7,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmJobDef, ver. 0.0,
   GUID={0x2FA5166A,0xD28B,0x49D4,{0xB5,0xF8,0xB1,0x2B,0x32,0x01,0xC1,0xC4}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmJobDef_FormatStringOffsetTable[] =
    {
    1644,
    1782,
    426,
    1818,
    1854,
    1890,
    1926,
    1986,
    2022,
    2058,
    2094,
    2130,
    2166,
    2202,
    2238,
    2274,
    2310,
    1302,
    2340,
    2370
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmJobDef_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmJobDef_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmJobDef_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmJobDef_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(23) _IHsmJobDefProxyVtbl = 
{
    &IHsmJobDef_ProxyInfo,
    &IID_IHsmJobDef,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmJobDef::EnumPolicies */ ,
    (void *) (INT_PTR) -1 /* IHsmJobDef::GetIdentifier */ ,
    (void *) (INT_PTR) -1 /* IHsmJobDef::GetName */ ,
    (void *) (INT_PTR) -1 /* IHsmJobDef::GetPostActionOnResource */ ,
    (void *) (INT_PTR) -1 /* IHsmJobDef::GetPreActionOnResource */ ,
    (void *) (INT_PTR) -1 /* IHsmJobDef::GetPreScanActionOnResource */ ,
    (void *) (INT_PTR) -1 /* IHsmJobDef::InitAs */ ,
    (void *) (INT_PTR) -1 /* IHsmJobDef::Policies */ ,
    (void *) (INT_PTR) -1 /* IHsmJobDef::SetName */ ,
    (void *) (INT_PTR) -1 /* IHsmJobDef::SetPostActionOnResource */ ,
    (void *) (INT_PTR) -1 /* IHsmJobDef::SetPreActionOnResource */ ,
    (void *) (INT_PTR) -1 /* IHsmJobDef::SetPreScanActionOnResource */ ,
    (void *) (INT_PTR) -1 /* IHsmJobDef::SetSkipHiddenItems */ ,
    (void *) (INT_PTR) -1 /* IHsmJobDef::SetSkipSystemItems */ ,
    (void *) (INT_PTR) -1 /* IHsmJobDef::SetUseRPIndex */ ,
    (void *) (INT_PTR) -1 /* IHsmJobDef::SetUseDbIndex */ ,
    (void *) (INT_PTR) -1 /* IHsmJobDef::SkipHiddenItems */ ,
    (void *) (INT_PTR) -1 /* IHsmJobDef::SkipSystemItems */ ,
    (void *) (INT_PTR) -1 /* IHsmJobDef::UseRPIndex */ ,
    (void *) (INT_PTR) -1 /* IHsmJobDef::UseDbIndex */
};

const CInterfaceStubVtbl _IHsmJobDefStubVtbl =
{
    &IID_IHsmJobDef,
    &IHsmJobDef_ServerInfo,
    23,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmJobSinkEverySession, ver. 0.0,
   GUID={0x4250BAA0,0x811D,0x11d0,{0x81,0xE4,0x00,0xA0,0xC9,0x11,0x80,0xF2}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmJobSinkEverySession_FormatStringOffsetTable[] =
    {
    2400
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmJobSinkEverySession_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmJobSinkEverySession_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmJobSinkEverySession_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmJobSinkEverySession_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IHsmJobSinkEverySessionProxyVtbl = 
{
    &IHsmJobSinkEverySession_ProxyInfo,
    &IID_IHsmJobSinkEverySession,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmJobSinkEverySession::ProcessJobSession */
};

const CInterfaceStubVtbl _IHsmJobSinkEverySessionStubVtbl =
{
    &IID_IHsmJobSinkEverySession,
    &IHsmJobSinkEverySession_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmJobWorkItem, ver. 0.0,
   GUID={0xB8E1CD20,0x81D3,0x11d0,{0x81,0xE4,0x00,0xA0,0xC9,0x11,0x80,0xF2}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmJobWorkItem_FormatStringOffsetTable[] =
    {
    2448,
    2490,
    234,
    1752,
    2532,
    2568,
    2604,
    2646,
    948,
    2682,
    1020,
    2718,
    1098,
    2754,
    2796
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmJobWorkItem_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmJobWorkItem_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmJobWorkItem_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmJobWorkItem_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(18) _IHsmJobWorkItemProxyVtbl = 
{
    &IHsmJobWorkItem_ProxyInfo,
    &IID_IHsmJobWorkItem,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmJobWorkItem::CompareToResourceId */ ,
    (void *) (INT_PTR) -1 /* IHsmJobWorkItem::CompareToIWorkItem */ ,
    (void *) (INT_PTR) -1 /* IHsmJobWorkItem::DoPostScan */ ,
    (void *) (INT_PTR) -1 /* IHsmJobWorkItem::DoPreScan */ ,
    (void *) (INT_PTR) -1 /* IHsmJobWorkItem::EnumPhases */ ,
    (void *) (INT_PTR) -1 /* IHsmJobWorkItem::EnumTotals */ ,
    (void *) (INT_PTR) -1 /* IHsmJobWorkItem::GetCurrentPath */ ,
    (void *) (INT_PTR) -1 /* IHsmJobWorkItem::GetFinishTime */ ,
    (void *) (INT_PTR) -1 /* IHsmJobWorkItem::GetResourceId */ ,
    (void *) (INT_PTR) -1 /* IHsmJobWorkItem::GetSession */ ,
    (void *) (INT_PTR) -1 /* IHsmJobWorkItem::GetStartingPath */ ,
    (void *) (INT_PTR) -1 /* IHsmJobWorkItem::GetStartTime */ ,
    (void *) (INT_PTR) -1 /* IHsmJobWorkItem::GetState */ ,
    (void *) (INT_PTR) -1 /* IHsmJobWorkItem::GetStateAsString */ ,
    (void *) (INT_PTR) -1 /* IHsmJobWorkItem::GetSubRunId */
};

const CInterfaceStubVtbl _IHsmJobWorkItemStubVtbl =
{
    &IID_IHsmJobWorkItem,
    &IHsmJobWorkItem_ServerInfo,
    18,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmPhase, ver. 0.0,
   GUID={0x35035914,0x0D1C,0x11d2,{0x9B,0x0C,0x00,0x10,0x4B,0x9A,0x28,0x69}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmPhase_FormatStringOffsetTable[] =
    {
    2832,
    2868,
    2904,
    2958,
    2994,
    3036,
    3078,
    3114,
    3150,
    3192,
    1020,
    3228,
    3294,
    3330
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmPhase_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmPhase_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmPhase_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmPhase_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(17) _IHsmPhaseProxyVtbl = 
{
    &IHsmPhase_ProxyInfo,
    &IID_IHsmPhase,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmPhase::Clone */ ,
    (void *) (INT_PTR) -1 /* IHsmPhase::CopyTo */ ,
    (void *) (INT_PTR) -1 /* IHsmPhase::GetElapsedTime */ ,
    (void *) (INT_PTR) -1 /* IHsmPhase::GetMediaState */ ,
    (void *) (INT_PTR) -1 /* IHsmPhase::GetMediaStateAsString */ ,
    (void *) (INT_PTR) -1 /* IHsmPhase::GetName */ ,
    (void *) (INT_PTR) -1 /* IHsmPhase::GetPhase */ ,
    (void *) (INT_PTR) -1 /* IHsmPhase::GetPriority */ ,
    (void *) (INT_PTR) -1 /* IHsmPhase::GetPriorityAsString */ ,
    (void *) (INT_PTR) -1 /* IHsmPhase::GetState */ ,
    (void *) (INT_PTR) -1 /* IHsmPhase::GetStateAsString */ ,
    (void *) (INT_PTR) -1 /* IHsmPhase::GetStats */ ,
    (void *) (INT_PTR) -1 /* IHsmPhase::GetStartTime */ ,
    (void *) (INT_PTR) -1 /* IHsmPhase::GetStopTime */
};

const CInterfaceStubVtbl _IHsmPhaseStubVtbl =
{
    &IID_IHsmPhase,
    &IHsmPhase_ServerInfo,
    17,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmPolicy, ver. 0.0,
   GUID={0xAD40234C,0x00FC,0x11D0,{0x81,0x9C,0x00,0xA0,0xC9,0x11,0x80,0xF2}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmPolicy_FormatStringOffsetTable[] =
    {
    3366,
    3402,
    3438,
    468,
    3474,
    3510,
    3546,
    3582,
    3618,
    3654,
    3690
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmPolicy_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmPolicy_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmPolicy_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmPolicy_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(14) _IHsmPolicyProxyVtbl = 
{
    &IHsmPolicy_ProxyInfo,
    &IID_IHsmPolicy,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmPolicy::EnumRules */ ,
    (void *) (INT_PTR) -1 /* IHsmPolicy::GetAction */ ,
    (void *) (INT_PTR) -1 /* IHsmPolicy::GetIdentifier */ ,
    (void *) (INT_PTR) -1 /* IHsmPolicy::GetName */ ,
    (void *) (INT_PTR) -1 /* IHsmPolicy::GetScale */ ,
    (void *) (INT_PTR) -1 /* IHsmPolicy::Rules */ ,
    (void *) (INT_PTR) -1 /* IHsmPolicy::SetAction */ ,
    (void *) (INT_PTR) -1 /* IHsmPolicy::SetName */ ,
    (void *) (INT_PTR) -1 /* IHsmPolicy::SetScale */ ,
    (void *) (INT_PTR) -1 /* IHsmPolicy::SetUsesDefaultRules */ ,
    (void *) (INT_PTR) -1 /* IHsmPolicy::UsesDefaultRules */
};

const CInterfaceStubVtbl _IHsmPolicyStubVtbl =
{
    &IID_IHsmPolicy,
    &IHsmPolicy_ServerInfo,
    14,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmRelocateAction, ver. 0.0,
   GUID={0xC7A01571,0x187A,0x11D0,{0x81,0xB0,0x00,0xA0,0xC9,0x11,0x80,0xF2}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmRelocateAction_FormatStringOffsetTable[] =
    {
    0,
    204,
    234,
    3720,
    300,
    3756
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmRelocateAction_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmRelocateAction_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmRelocateAction_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmRelocateAction_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(9) _IHsmRelocateActionProxyVtbl = 
{
    &IHsmRelocateAction_ProxyInfo,
    &IID_IHsmRelocateAction,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmRelocateAction::GetDestination */ ,
    (void *) (INT_PTR) -1 /* IHsmRelocateAction::ExpandPlaceholders */ ,
    (void *) (INT_PTR) -1 /* IHsmRelocateAction::RetainHierarchy */ ,
    (void *) (INT_PTR) -1 /* IHsmRelocateAction::SetDestination */ ,
    (void *) (INT_PTR) -1 /* IHsmRelocateAction::SetExpandPlaceholders */ ,
    (void *) (INT_PTR) -1 /* IHsmRelocateAction::SetRetainHierarchy */
};

const CInterfaceStubVtbl _IHsmRelocateActionStubVtbl =
{
    &IID_IHsmRelocateAction,
    &IHsmRelocateAction_ServerInfo,
    9,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmRule, ver. 0.0,
   GUID={0xAD402356,0x00FC,0x11D0,{0x81,0x9C,0x00,0xA0,0xC9,0x11,0x80,0xF2}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmRule_FormatStringOffsetTable[] =
    {
    3792,
    3834,
    3882,
    3918,
    2994,
    3036,
    2604,
    3954,
    3984,
    4014,
    4044,
    4080,
    2166,
    2202,
    4116,
    4152
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmRule_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmRule_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmRule_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmRule_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(19) _IHsmRuleProxyVtbl = 
{
    &IHsmRule_ProxyInfo,
    &IID_IHsmRule,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmRule::CompareToIRule */ ,
    (void *) (INT_PTR) -1 /* IHsmRule::CompareToPathAndName */ ,
    (void *) (INT_PTR) -1 /* IHsmRule::Criteria */ ,
    (void *) (INT_PTR) -1 /* IHsmRule::EnumCriteria */ ,
    (void *) (INT_PTR) -1 /* IHsmRule::GetName */ ,
    (void *) (INT_PTR) -1 /* IHsmRule::GetSearchName */ ,
    (void *) (INT_PTR) -1 /* IHsmRule::GetPath */ ,
    (void *) (INT_PTR) -1 /* IHsmRule::IsInclude */ ,
    (void *) (INT_PTR) -1 /* IHsmRule::IsUserDefined */ ,
    (void *) (INT_PTR) -1 /* IHsmRule::IsUsedInSubDirs */ ,
    (void *) (INT_PTR) -1 /* IHsmRule::MatchesName */ ,
    (void *) (INT_PTR) -1 /* IHsmRule::SetIsInclude */ ,
    (void *) (INT_PTR) -1 /* IHsmRule::SetIsUserDefined */ ,
    (void *) (INT_PTR) -1 /* IHsmRule::SetIsUsedInSubDirs */ ,
    (void *) (INT_PTR) -1 /* IHsmRule::SetName */ ,
    (void *) (INT_PTR) -1 /* IHsmRule::SetPath */
};

const CInterfaceStubVtbl _IHsmRuleStubVtbl =
{
    &IID_IHsmRule,
    &IHsmRule_ServerInfo,
    19,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmRuleStack, ver. 0.0,
   GUID={0x7B22FF21,0x1AD6,0x11D0,{0x81,0xB1,0x00,0xA0,0xC9,0x11,0x80,0xF2}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmRuleStack_FormatStringOffsetTable[] =
    {
    4188,
    4224,
    4266,
    3720,
    4308
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmRuleStack_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmRuleStack_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmRuleStack_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmRuleStack_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(8) _IHsmRuleStackProxyVtbl = 
{
    &IHsmRuleStack_ProxyInfo,
    &IID_IHsmRuleStack,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmRuleStack::Do */ ,
    (void *) (INT_PTR) -1 /* IHsmRuleStack::DoesMatch */ ,
    (void *) (INT_PTR) -1 /* IHsmRuleStack::Init */ ,
    (void *) (INT_PTR) -1 /* IHsmRuleStack::Pop */ ,
    (void *) (INT_PTR) -1 /* IHsmRuleStack::Push */
};

const CInterfaceStubVtbl _IHsmRuleStackStubVtbl =
{
    &IID_IHsmRuleStack,
    &IHsmRuleStack_ServerInfo,
    8,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmScanner, ver. 0.0,
   GUID={0xBEA60F83,0x7EBA,0x11d0,{0x81,0xE4,0x00,0xA0,0xC9,0x11,0x80,0xF2}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmScanner_FormatStringOffsetTable[] =
    {
    4344
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmScanner_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmScanner_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmScanner_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmScanner_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IHsmScannerProxyVtbl = 
{
    &IHsmScanner_ProxyInfo,
    &IID_IHsmScanner,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmScanner::Start */
};

const CInterfaceStubVtbl _IHsmScannerStubVtbl =
{
    &IID_IHsmScanner,
    &IHsmScanner_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmSession, ver. 0.0,
   GUID={0x6E7196DC,0x7F9C,0x460D,{0x9E,0x97,0x84,0x54,0x90,0xB8,0x1D,0x60}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmSession_FormatStringOffsetTable[] =
    {
    726,
    4386,
    4422,
    4458,
    4494,
    4530,
    4566,
    4602,
    4644,
    984,
    4680,
    4716,
    4746,
    4782,
    4824,
    4878,
    4932,
    4992,
    5034,
    5088,
    5130,
    5166,
    5202,
    5274
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmSession_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmSession_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmSession_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmSession_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(27) _IHsmSessionProxyVtbl = 
{
    &IHsmSession_ProxyInfo,
    &IID_IHsmSession,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmSession::Cancel */ ,
    (void *) (INT_PTR) -1 /* IHsmSession::EnumPhases */ ,
    (void *) (INT_PTR) -1 /* IHsmSession::EnumTotals */ ,
    (void *) (INT_PTR) -1 /* IHsmSession::GetAdviseInterval */ ,
    (void *) (INT_PTR) -1 /* IHsmSession::GetHsmId */ ,
    (void *) (INT_PTR) -1 /* IHsmSession::GetIdentifier */ ,
    (void *) (INT_PTR) -1 /* IHsmSession::GetJob */ ,
    (void *) (INT_PTR) -1 /* IHsmSession::GetName */ ,
    (void *) (INT_PTR) -1 /* IHsmSession::GetResource */ ,
    (void *) (INT_PTR) -1 /* IHsmSession::GetRunId */ ,
    (void *) (INT_PTR) -1 /* IHsmSession::GetSubRunId */ ,
    (void *) (INT_PTR) -1 /* IHsmSession::IsCanceling */ ,
    (void *) (INT_PTR) -1 /* IHsmSession::Pause */ ,
    (void *) (INT_PTR) -1 /* IHsmSession::ProcessEvent */ ,
    (void *) (INT_PTR) -1 /* IHsmSession::ProcessHr */ ,
    (void *) (INT_PTR) -1 /* IHsmSession::ProcessItem */ ,
    (void *) (INT_PTR) -1 /* IHsmSession::ProcessMediaState */ ,
    (void *) (INT_PTR) -1 /* IHsmSession::ProcessPriority */ ,
    (void *) (INT_PTR) -1 /* IHsmSession::ProcessState */ ,
    (void *) (INT_PTR) -1 /* IHsmSession::ProcessString */ ,
    (void *) (INT_PTR) -1 /* IHsmSession::Resume */ ,
    (void *) (INT_PTR) -1 /* IHsmSession::SetAdviseInterval */ ,
    (void *) (INT_PTR) -1 /* IHsmSession::Start */ ,
    (void *) (INT_PTR) -1 /* IHsmSession::Suspend */
};

const CInterfaceStubVtbl _IHsmSessionStubVtbl =
{
    &IID_IHsmSession,
    &IHsmSession_ServerInfo,
    27,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmSessionSinkEveryEvent, ver. 0.0,
   GUID={0xF1AAA4E0,0x8385,0x11d0,{0x81,0xE4,0x00,0xA0,0xC9,0x11,0x80,0xF2}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmSessionSinkEveryEvent_FormatStringOffsetTable[] =
    {
    5310
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmSessionSinkEveryEvent_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmSessionSinkEveryEvent_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmSessionSinkEveryEvent_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmSessionSinkEveryEvent_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IHsmSessionSinkEveryEventProxyVtbl = 
{
    &IHsmSessionSinkEveryEvent_ProxyInfo,
    &IID_IHsmSessionSinkEveryEvent,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmSessionSinkEveryEvent::ProcessSessionEvent */
};

const CInterfaceStubVtbl _IHsmSessionSinkEveryEventStubVtbl =
{
    &IID_IHsmSessionSinkEveryEvent,
    &IHsmSessionSinkEveryEvent_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmSessionSinkEveryItem, ver. 0.0,
   GUID={0xBEA60F85,0x7EBA,0x11d0,{0x81,0xE4,0x00,0xA0,0xC9,0x11,0x80,0xF2}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmSessionSinkEveryItem_FormatStringOffsetTable[] =
    {
    5358
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmSessionSinkEveryItem_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmSessionSinkEveryItem_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmSessionSinkEveryItem_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmSessionSinkEveryItem_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IHsmSessionSinkEveryItemProxyVtbl = 
{
    &IHsmSessionSinkEveryItem_ProxyInfo,
    &IID_IHsmSessionSinkEveryItem,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmSessionSinkEveryItem::ProcessSessionItem */
};

const CInterfaceStubVtbl _IHsmSessionSinkEveryItemStubVtbl =
{
    &IID_IHsmSessionSinkEveryItem,
    &IHsmSessionSinkEveryItem_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmSessionSinkEveryMediaState, ver. 0.0,
   GUID={0xD5450542,0xA6C2,0x11d0,{0x81,0xE7,0x00,0xA0,0xC9,0x11,0x80,0xF2}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmSessionSinkEveryMediaState_FormatStringOffsetTable[] =
    {
    5418
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmSessionSinkEveryMediaState_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmSessionSinkEveryMediaState_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmSessionSinkEveryMediaState_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmSessionSinkEveryMediaState_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IHsmSessionSinkEveryMediaStateProxyVtbl = 
{
    &IHsmSessionSinkEveryMediaState_ProxyInfo,
    &IID_IHsmSessionSinkEveryMediaState,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmSessionSinkEveryMediaState::ProcessSessionMediaState */
};

const CInterfaceStubVtbl _IHsmSessionSinkEveryMediaStateStubVtbl =
{
    &IID_IHsmSessionSinkEveryMediaState,
    &IHsmSessionSinkEveryMediaState_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmSessionSinkEveryPriority, ver. 0.0,
   GUID={0xD5450543,0xA6C2,0x11d0,{0x81,0xE7,0x00,0xA0,0xC9,0x11,0x80,0xF2}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmSessionSinkEveryPriority_FormatStringOffsetTable[] =
    {
    5484
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmSessionSinkEveryPriority_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmSessionSinkEveryPriority_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmSessionSinkEveryPriority_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmSessionSinkEveryPriority_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IHsmSessionSinkEveryPriorityProxyVtbl = 
{
    &IHsmSessionSinkEveryPriority_ProxyInfo,
    &IID_IHsmSessionSinkEveryPriority,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmSessionSinkEveryPriority::ProcessSessionPriority */
};

const CInterfaceStubVtbl _IHsmSessionSinkEveryPriorityStubVtbl =
{
    &IID_IHsmSessionSinkEveryPriority,
    &IHsmSessionSinkEveryPriority_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmSessionSinkEveryState, ver. 0.0,
   GUID={0xBEA60F87,0x7EBA,0x11d0,{0x81,0xE4,0x00,0xA0,0xC9,0x11,0x80,0xF2}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmSessionSinkEveryState_FormatStringOffsetTable[] =
    {
    5526
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmSessionSinkEveryState_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmSessionSinkEveryState_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmSessionSinkEveryState_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmSessionSinkEveryState_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IHsmSessionSinkEveryStateProxyVtbl = 
{
    &IHsmSessionSinkEveryState_ProxyInfo,
    &IID_IHsmSessionSinkEveryState,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmSessionSinkEveryState::ProcessSessionState */
};

const CInterfaceStubVtbl _IHsmSessionSinkEveryStateStubVtbl =
{
    &IID_IHsmSessionSinkEveryState,
    &IHsmSessionSinkEveryState_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmSessionSinkSomeItems, ver. 0.0,
   GUID={0xBEA60F88,0x7EBA,0x11d0,{0x81,0xE4,0x00,0xA0,0xC9,0x11,0x80,0xF2}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmSessionSinkSomeItems_FormatStringOffsetTable[] =
    {
    5358
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmSessionSinkSomeItems_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmSessionSinkSomeItems_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmSessionSinkSomeItems_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmSessionSinkSomeItems_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IHsmSessionSinkSomeItemsProxyVtbl = 
{
    &IHsmSessionSinkSomeItems_ProxyInfo,
    &IID_IHsmSessionSinkSomeItems,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmSessionSinkSomeItems::ProcessSessionItem */
};

const CInterfaceStubVtbl _IHsmSessionSinkSomeItemsStubVtbl =
{
    &IID_IHsmSessionSinkSomeItems,
    &IHsmSessionSinkSomeItems_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmSessionTotals, ver. 0.0,
   GUID={0x35035913,0x0D1C,0x11d2,{0x9B,0x0C,0x00,0x10,0x4B,0x9A,0x28,0x69}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmSessionTotals_FormatStringOffsetTable[] =
    {
    5574,
    5610,
    5646,
    5688,
    510,
    3036,
    5730
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmSessionTotals_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmSessionTotals_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmSessionTotals_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmSessionTotals_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(10) _IHsmSessionTotalsProxyVtbl = 
{
    &IHsmSessionTotals_ProxyInfo,
    &IID_IHsmSessionTotals,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmSessionTotals::Clone */ ,
    (void *) (INT_PTR) -1 /* IHsmSessionTotals::CopyTo */ ,
    (void *) (INT_PTR) -1 /* IHsmSessionTotals::CompareToAction */ ,
    (void *) (INT_PTR) -1 /* IHsmSessionTotals::CompareToISessionTotals */ ,
    (void *) (INT_PTR) -1 /* IHsmSessionTotals::GetAction */ ,
    (void *) (INT_PTR) -1 /* IHsmSessionTotals::GetName */ ,
    (void *) (INT_PTR) -1 /* IHsmSessionTotals::GetStats */
};

const CInterfaceStubVtbl _IHsmSessionTotalsStubVtbl =
{
    &IID_IHsmSessionTotals,
    &IHsmSessionTotals_ServerInfo,
    10,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    __MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x50002, /* Ndr library version */
    0,
    0x6000169, /* MIDL Version 6.0.361 */
    0,
    0,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0   /* Reserved5 */
    };

const CInterfaceProxyVtbl * _jobint_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IHsmActionOnResourceProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmSessionTotalsProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmPhaseProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmJobWorkItemProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmRuleStackProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmSessionSinkEveryMediaStateProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmSessionSinkEveryPriorityProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmPolicyProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmActionProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmRuleProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmCriteriaProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmJobContextProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmJobDefProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmRelocateActionProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmDirectedActionProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmScannerProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmSessionSinkEveryItemProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmSessionSinkEveryStateProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmSessionSinkSomeItemsProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmActionOnResourcePreProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmJobSinkEverySessionProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmRelativeCriteriaProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmActionOnResourcePreScanProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmActionOnResourcePostProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmSessionProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmSessionSinkEveryEventProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmJobProxyVtbl,
    0
};

const CInterfaceStubVtbl * _jobint_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IHsmActionOnResourceStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmSessionTotalsStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmPhaseStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmJobWorkItemStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmRuleStackStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmSessionSinkEveryMediaStateStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmSessionSinkEveryPriorityStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmPolicyStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmActionStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmRuleStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmCriteriaStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmJobContextStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmJobDefStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmRelocateActionStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmDirectedActionStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmScannerStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmSessionSinkEveryItemStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmSessionSinkEveryStateStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmSessionSinkSomeItemsStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmActionOnResourcePreStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmJobSinkEverySessionStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmRelativeCriteriaStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmActionOnResourcePreScanStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmActionOnResourcePostStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmSessionStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmSessionSinkEveryEventStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmJobStubVtbl,
    0
};

PCInterfaceName const _jobint_InterfaceNamesList[] = 
{
    "IHsmActionOnResource",
    "IHsmSessionTotals",
    "IHsmPhase",
    "IHsmJobWorkItem",
    "IHsmRuleStack",
    "IHsmSessionSinkEveryMediaState",
    "IHsmSessionSinkEveryPriority",
    "IHsmPolicy",
    "IHsmAction",
    "IHsmRule",
    "IHsmCriteria",
    "IHsmJobContext",
    "IHsmJobDef",
    "IHsmRelocateAction",
    "IHsmDirectedAction",
    "IHsmScanner",
    "IHsmSessionSinkEveryItem",
    "IHsmSessionSinkEveryState",
    "IHsmSessionSinkSomeItems",
    "IHsmActionOnResourcePre",
    "IHsmJobSinkEverySession",
    "IHsmRelativeCriteria",
    "IHsmActionOnResourcePreScan",
    "IHsmActionOnResourcePost",
    "IHsmSession",
    "IHsmSessionSinkEveryEvent",
    "IHsmJob",
    0
};


#define _jobint_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _jobint, pIID, n)

int __stdcall _jobint_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _jobint, 27, 16 )
    IID_BS_LOOKUP_NEXT_TEST( _jobint, 8 )
    IID_BS_LOOKUP_NEXT_TEST( _jobint, 4 )
    IID_BS_LOOKUP_NEXT_TEST( _jobint, 2 )
    IID_BS_LOOKUP_NEXT_TEST( _jobint, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _jobint, 27, *pIndex )
    
}

const ExtendedProxyFileInfo jobint_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _jobint_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _jobint_StubVtblList,
    (const PCInterfaceName * ) & _jobint_InterfaceNamesList,
    0, // no delegation
    & _jobint_IID_Lookup, 
    27,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* !defined(_M_IA64) && !defined(_M_AMD64)*/



/* this ALWAYS GENERATED file contains the proxy stub code */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for jobint.idl:
    Oicf, W1, Zp8, env=Win64 (32b run,appending)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#if defined(_M_IA64) || defined(_M_AMD64)


#pragma warning( disable: 4049 )  /* more than 64k source lines */
#if _MSC_VER >= 1200
#pragma warning(push)
#endif

#pragma warning( disable: 4211 )  /* redefine extent to static */
#pragma warning( disable: 4232 )  /* dllimport identity*/
#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 475
#endif


#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif // __RPCPROXY_H_VERSION__


#include "jobint.h"

#define TYPE_FORMAT_STRING_SIZE   753                               
#define PROC_FORMAT_STRING_SIZE   6095                              
#define TRANSMIT_AS_TABLE_SIZE    0            
#define WIRE_MARSHAL_TABLE_SIZE   0            

typedef struct _MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } MIDL_TYPE_FORMAT_STRING;

typedef struct _MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } MIDL_PROC_FORMAT_STRING;


static RPC_SYNTAX_IDENTIFIER  _RpcTransferSyntax = 
{{0x8A885D04,0x1CEB,0x11C9,{0x9F,0xE8,0x08,0x00,0x2B,0x10,0x48,0x60}},{2,0}};


extern const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString;
extern const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmAction_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmAction_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmActionOnResource_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmActionOnResource_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmActionOnResourcePost_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmActionOnResourcePost_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmActionOnResourcePre_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmActionOnResourcePre_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmActionOnResourcePreScan_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmActionOnResourcePreScan_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmCriteria_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmCriteria_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmRelativeCriteria_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmRelativeCriteria_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmDirectedAction_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmDirectedAction_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmJob_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmJob_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmJobContext_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmJobContext_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmJobDef_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmJobDef_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmJobSinkEverySession_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmJobSinkEverySession_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmJobWorkItem_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmJobWorkItem_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmPhase_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmPhase_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmPolicy_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmPolicy_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmRelocateAction_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmRelocateAction_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmRule_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmRule_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmRuleStack_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmRuleStack_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmScanner_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmScanner_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmSession_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmSession_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmSessionSinkEveryEvent_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmSessionSinkEveryEvent_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmSessionSinkEveryItem_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmSessionSinkEveryItem_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmSessionSinkEveryMediaState_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmSessionSinkEveryMediaState_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmSessionSinkEveryPriority_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmSessionSinkEveryPriority_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmSessionSinkEveryState_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmSessionSinkEveryState_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmSessionSinkSomeItems_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmSessionSinkSomeItems_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmSessionTotals_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmSessionTotals_ProxyInfo;



#if !defined(__RPC_WIN64__)
#error  Invalid build platform for this stub.
#endif

static const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure GetDestination */


	/* Procedure ComparatorAsString */


	/* Procedure GetName */


	/* Procedure GetName */


	/* Procedure GetName */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x3 ),	/* 3 */
/*  8 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 10 */	NdrFcShort( 0x8 ),	/* 8 */
/* 12 */	NdrFcShort( 0x8 ),	/* 8 */
/* 14 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 16 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	NdrFcShort( 0x0 ),	/* 0 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */
/* 24 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pDest */


	/* Parameter pCompString */


	/* Parameter pName */


	/* Parameter pName */


	/* Parameter pName */

/* 26 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 28 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 30 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter bufferSize */


	/* Parameter bufferSize */


	/* Parameter bufferSize */


	/* Parameter bufferSize */


	/* Parameter bufferSize */

/* 32 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 34 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 36 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 38 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 40 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 42 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Do */

/* 44 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 46 */	NdrFcLong( 0x0 ),	/* 0 */
/* 50 */	NdrFcShort( 0x4 ),	/* 4 */
/* 52 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 54 */	NdrFcShort( 0x0 ),	/* 0 */
/* 56 */	NdrFcShort( 0x8 ),	/* 8 */
/* 58 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 60 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 62 */	NdrFcShort( 0x0 ),	/* 0 */
/* 64 */	NdrFcShort( 0x0 ),	/* 0 */
/* 66 */	NdrFcShort( 0x0 ),	/* 0 */
/* 68 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pScanItem */

/* 70 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 72 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 74 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Return value */

/* 76 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 78 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 80 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Do */

/* 82 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 84 */	NdrFcLong( 0x0 ),	/* 0 */
/* 88 */	NdrFcShort( 0x3 ),	/* 3 */
/* 90 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 92 */	NdrFcShort( 0x8 ),	/* 8 */
/* 94 */	NdrFcShort( 0x8 ),	/* 8 */
/* 96 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 98 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 100 */	NdrFcShort( 0x0 ),	/* 0 */
/* 102 */	NdrFcShort( 0x0 ),	/* 0 */
/* 104 */	NdrFcShort( 0x0 ),	/* 0 */
/* 106 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pWorkItem */

/* 108 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 110 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 112 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter state */

/* 114 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 116 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 118 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 120 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 122 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 124 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Do */

/* 126 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 128 */	NdrFcLong( 0x0 ),	/* 0 */
/* 132 */	NdrFcShort( 0x3 ),	/* 3 */
/* 134 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 136 */	NdrFcShort( 0x0 ),	/* 0 */
/* 138 */	NdrFcShort( 0x8 ),	/* 8 */
/* 140 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 142 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 144 */	NdrFcShort( 0x0 ),	/* 0 */
/* 146 */	NdrFcShort( 0x0 ),	/* 0 */
/* 148 */	NdrFcShort( 0x0 ),	/* 0 */
/* 150 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pWorkItem */

/* 152 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 154 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 156 */	NdrFcShort( 0x1c ),	/* Type Offset=28 */

	/* Parameter pJobDef */

/* 158 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 160 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 162 */	NdrFcShort( 0x2e ),	/* Type Offset=46 */

	/* Return value */

/* 164 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 166 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 168 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Do */

/* 170 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 172 */	NdrFcLong( 0x0 ),	/* 0 */
/* 176 */	NdrFcShort( 0x3 ),	/* 3 */
/* 178 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 180 */	NdrFcShort( 0x0 ),	/* 0 */
/* 182 */	NdrFcShort( 0x8 ),	/* 8 */
/* 184 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 186 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 188 */	NdrFcShort( 0x0 ),	/* 0 */
/* 190 */	NdrFcShort( 0x0 ),	/* 0 */
/* 192 */	NdrFcShort( 0x0 ),	/* 0 */
/* 194 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pResource */

/* 196 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 198 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 200 */	NdrFcShort( 0x40 ),	/* Type Offset=64 */

	/* Parameter pSession */

/* 202 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 204 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 206 */	NdrFcShort( 0x52 ),	/* Type Offset=82 */

	/* Return value */

/* 208 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 210 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 212 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ExpandPlaceholders */


	/* Procedure DidFinish */


	/* Procedure ComparatorIsBinary */


	/* Procedure IsIgnored */

/* 214 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 216 */	NdrFcLong( 0x0 ),	/* 0 */
/* 220 */	NdrFcShort( 0x4 ),	/* 4 */
/* 222 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 224 */	NdrFcShort( 0x0 ),	/* 0 */
/* 226 */	NdrFcShort( 0x8 ),	/* 8 */
/* 228 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 230 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 232 */	NdrFcShort( 0x0 ),	/* 0 */
/* 234 */	NdrFcShort( 0x0 ),	/* 0 */
/* 236 */	NdrFcShort( 0x0 ),	/* 0 */
/* 238 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 240 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 242 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 244 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RetainHierarchy */


	/* Procedure DoPostScan */


	/* Procedure DidFinishOk */


	/* Procedure IsNegated */

/* 246 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 248 */	NdrFcLong( 0x0 ),	/* 0 */
/* 252 */	NdrFcShort( 0x5 ),	/* 5 */
/* 254 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 256 */	NdrFcShort( 0x0 ),	/* 0 */
/* 258 */	NdrFcShort( 0x8 ),	/* 8 */
/* 260 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 262 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 264 */	NdrFcShort( 0x0 ),	/* 0 */
/* 266 */	NdrFcShort( 0x0 ),	/* 0 */
/* 268 */	NdrFcShort( 0x0 ),	/* 0 */
/* 270 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 272 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 274 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 276 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetIsIgnored */

/* 278 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 280 */	NdrFcLong( 0x0 ),	/* 0 */
/* 284 */	NdrFcShort( 0x6 ),	/* 6 */
/* 286 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 288 */	NdrFcShort( 0x8 ),	/* 8 */
/* 290 */	NdrFcShort( 0x8 ),	/* 8 */
/* 292 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 294 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 296 */	NdrFcShort( 0x0 ),	/* 0 */
/* 298 */	NdrFcShort( 0x0 ),	/* 0 */
/* 300 */	NdrFcShort( 0x0 ),	/* 0 */
/* 302 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter isIgnored */

/* 304 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 306 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 308 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 310 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 312 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 314 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetExpandPlaceholders */


	/* Procedure SetIsNegated */

/* 316 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 318 */	NdrFcLong( 0x0 ),	/* 0 */
/* 322 */	NdrFcShort( 0x7 ),	/* 7 */
/* 324 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 326 */	NdrFcShort( 0x8 ),	/* 8 */
/* 328 */	NdrFcShort( 0x8 ),	/* 8 */
/* 330 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 332 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 334 */	NdrFcShort( 0x0 ),	/* 0 */
/* 336 */	NdrFcShort( 0x0 ),	/* 0 */
/* 338 */	NdrFcShort( 0x0 ),	/* 0 */
/* 340 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter expandPlaceholders */


	/* Parameter isNegated */

/* 342 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 344 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 346 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 348 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 350 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 352 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ShouldDo */

/* 354 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 356 */	NdrFcLong( 0x0 ),	/* 0 */
/* 360 */	NdrFcShort( 0x8 ),	/* 8 */
/* 362 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 364 */	NdrFcShort( 0x6 ),	/* 6 */
/* 366 */	NdrFcShort( 0x8 ),	/* 8 */
/* 368 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 370 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 372 */	NdrFcShort( 0x0 ),	/* 0 */
/* 374 */	NdrFcShort( 0x0 ),	/* 0 */
/* 376 */	NdrFcShort( 0x0 ),	/* 0 */
/* 378 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pScanItem */

/* 380 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 382 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 384 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter scale */

/* 386 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 388 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 390 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 392 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 394 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 396 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Value */

/* 398 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 400 */	NdrFcLong( 0x0 ),	/* 0 */
/* 404 */	NdrFcShort( 0x9 ),	/* 9 */
/* 406 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 408 */	NdrFcShort( 0x8 ),	/* 8 */
/* 410 */	NdrFcShort( 0x8 ),	/* 8 */
/* 412 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 414 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 416 */	NdrFcShort( 0x0 ),	/* 0 */
/* 418 */	NdrFcShort( 0x0 ),	/* 0 */
/* 420 */	NdrFcShort( 0x0 ),	/* 0 */
/* 422 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pScanItem */

/* 424 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 426 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 428 */	NdrFcShort( 0xa ),	/* Type Offset=10 */

	/* Parameter value */

/* 430 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 432 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 434 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter bufferSize */

/* 436 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 438 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 440 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 442 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 444 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 446 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetName */


	/* Procedure GetArg1 */

/* 448 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 450 */	NdrFcLong( 0x0 ),	/* 0 */
/* 454 */	NdrFcShort( 0x5 ),	/* 5 */
/* 456 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 458 */	NdrFcShort( 0x8 ),	/* 8 */
/* 460 */	NdrFcShort( 0x8 ),	/* 8 */
/* 462 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 464 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 466 */	NdrFcShort( 0x0 ),	/* 0 */
/* 468 */	NdrFcShort( 0x0 ),	/* 0 */
/* 470 */	NdrFcShort( 0x0 ),	/* 0 */
/* 472 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */


	/* Parameter pArg */

/* 474 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 476 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 478 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter bufferSize */


	/* Parameter bufferSize */

/* 480 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 482 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 484 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 486 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 488 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 490 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetName */


	/* Procedure GetArg2 */

/* 492 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 494 */	NdrFcLong( 0x0 ),	/* 0 */
/* 498 */	NdrFcShort( 0x6 ),	/* 6 */
/* 500 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 502 */	NdrFcShort( 0x8 ),	/* 8 */
/* 504 */	NdrFcShort( 0x8 ),	/* 8 */
/* 506 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 508 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 510 */	NdrFcShort( 0x0 ),	/* 0 */
/* 512 */	NdrFcShort( 0x0 ),	/* 0 */
/* 514 */	NdrFcShort( 0x0 ),	/* 0 */
/* 516 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */


	/* Parameter pArg */

/* 518 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 520 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 522 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter bufferSize */


	/* Parameter bufferSize */

/* 524 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 526 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 528 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 530 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 532 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 534 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetAction */


	/* Procedure GetComparator */

/* 536 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 538 */	NdrFcLong( 0x0 ),	/* 0 */
/* 542 */	NdrFcShort( 0x7 ),	/* 7 */
/* 544 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 546 */	NdrFcShort( 0x0 ),	/* 0 */
/* 548 */	NdrFcShort( 0x24 ),	/* 36 */
/* 550 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 552 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 554 */	NdrFcShort( 0x0 ),	/* 0 */
/* 556 */	NdrFcShort( 0x0 ),	/* 0 */
/* 558 */	NdrFcShort( 0x0 ),	/* 0 */
/* 560 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pAction */


	/* Parameter pComparator */

/* 562 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 564 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 566 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 568 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 570 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 572 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetArg1 */

/* 574 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 576 */	NdrFcLong( 0x0 ),	/* 0 */
/* 580 */	NdrFcShort( 0x8 ),	/* 8 */
/* 582 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 584 */	NdrFcShort( 0x0 ),	/* 0 */
/* 586 */	NdrFcShort( 0x8 ),	/* 8 */
/* 588 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 590 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 592 */	NdrFcShort( 0x0 ),	/* 0 */
/* 594 */	NdrFcShort( 0x0 ),	/* 0 */
/* 596 */	NdrFcShort( 0x0 ),	/* 0 */
/* 598 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg */

/* 600 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 602 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 604 */	NdrFcShort( 0x6a ),	/* Type Offset=106 */

	/* Return value */

/* 606 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 608 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 610 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetArg2 */

/* 612 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 614 */	NdrFcLong( 0x0 ),	/* 0 */
/* 618 */	NdrFcShort( 0x9 ),	/* 9 */
/* 620 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 622 */	NdrFcShort( 0x0 ),	/* 0 */
/* 624 */	NdrFcShort( 0x8 ),	/* 8 */
/* 626 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 628 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 630 */	NdrFcShort( 0x0 ),	/* 0 */
/* 632 */	NdrFcShort( 0x0 ),	/* 0 */
/* 634 */	NdrFcShort( 0x0 ),	/* 0 */
/* 636 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter arg */

/* 638 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 640 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 642 */	NdrFcShort( 0x6a ),	/* Type Offset=106 */

	/* Return value */

/* 644 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 646 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 648 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetComparator */

/* 650 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 652 */	NdrFcLong( 0x0 ),	/* 0 */
/* 656 */	NdrFcShort( 0xa ),	/* 10 */
/* 658 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 660 */	NdrFcShort( 0x8 ),	/* 8 */
/* 662 */	NdrFcShort( 0x8 ),	/* 8 */
/* 664 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 666 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 668 */	NdrFcShort( 0x0 ),	/* 0 */
/* 670 */	NdrFcShort( 0x0 ),	/* 0 */
/* 672 */	NdrFcShort( 0x0 ),	/* 0 */
/* 674 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter comparator */

/* 676 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 678 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 680 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 682 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 684 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 686 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetStoragePoolId */

/* 688 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 690 */	NdrFcLong( 0x0 ),	/* 0 */
/* 694 */	NdrFcShort( 0x3 ),	/* 3 */
/* 696 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 698 */	NdrFcShort( 0x0 ),	/* 0 */
/* 700 */	NdrFcShort( 0x4c ),	/* 76 */
/* 702 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 704 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 706 */	NdrFcShort( 0x0 ),	/* 0 */
/* 708 */	NdrFcShort( 0x0 ),	/* 0 */
/* 710 */	NdrFcShort( 0x0 ),	/* 0 */
/* 712 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */

/* 714 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 716 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 718 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Return value */

/* 720 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 722 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 724 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetStoragePoolId */

/* 726 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 728 */	NdrFcLong( 0x0 ),	/* 0 */
/* 732 */	NdrFcShort( 0x4 ),	/* 4 */
/* 734 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 736 */	NdrFcShort( 0x30 ),	/* 48 */
/* 738 */	NdrFcShort( 0x8 ),	/* 8 */
/* 740 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 742 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 744 */	NdrFcShort( 0x0 ),	/* 0 */
/* 746 */	NdrFcShort( 0x0 ),	/* 0 */
/* 748 */	NdrFcShort( 0x0 ),	/* 0 */
/* 750 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter id */

/* 752 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 754 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 756 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Return value */

/* 758 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 760 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 762 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Cancel */


	/* Procedure Cancel */

/* 764 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 766 */	NdrFcLong( 0x0 ),	/* 0 */
/* 770 */	NdrFcShort( 0x3 ),	/* 3 */
/* 772 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 774 */	NdrFcShort( 0x8 ),	/* 8 */
/* 776 */	NdrFcShort( 0x8 ),	/* 8 */
/* 778 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 780 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 782 */	NdrFcShort( 0x0 ),	/* 0 */
/* 784 */	NdrFcShort( 0x0 ),	/* 0 */
/* 786 */	NdrFcShort( 0x0 ),	/* 0 */
/* 788 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter phase */


	/* Parameter phase */

/* 790 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 792 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 794 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 796 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 798 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 800 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure EnumWorkItems */

/* 802 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 804 */	NdrFcLong( 0x0 ),	/* 0 */
/* 808 */	NdrFcShort( 0x6 ),	/* 6 */
/* 810 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 812 */	NdrFcShort( 0x0 ),	/* 0 */
/* 814 */	NdrFcShort( 0x8 ),	/* 8 */
/* 816 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 818 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 820 */	NdrFcShort( 0x0 ),	/* 0 */
/* 822 */	NdrFcShort( 0x0 ),	/* 0 */
/* 824 */	NdrFcShort( 0x0 ),	/* 0 */
/* 826 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppEnum */

/* 828 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 830 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 832 */	NdrFcShort( 0x82 ),	/* Type Offset=130 */

	/* Return value */

/* 834 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 836 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 838 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindWorkItem */

/* 840 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 842 */	NdrFcLong( 0x0 ),	/* 0 */
/* 846 */	NdrFcShort( 0x7 ),	/* 7 */
/* 848 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 850 */	NdrFcShort( 0x0 ),	/* 0 */
/* 852 */	NdrFcShort( 0x8 ),	/* 8 */
/* 854 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 856 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 858 */	NdrFcShort( 0x0 ),	/* 0 */
/* 860 */	NdrFcShort( 0x0 ),	/* 0 */
/* 862 */	NdrFcShort( 0x0 ),	/* 0 */
/* 864 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSession */

/* 866 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 868 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 870 */	NdrFcShort( 0x98 ),	/* Type Offset=152 */

	/* Parameter ppWorkItem */

/* 872 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 874 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 876 */	NdrFcShort( 0xaa ),	/* Type Offset=170 */

	/* Return value */

/* 878 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 880 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 882 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetContext */

/* 884 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 886 */	NdrFcLong( 0x0 ),	/* 0 */
/* 890 */	NdrFcShort( 0x8 ),	/* 8 */
/* 892 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 894 */	NdrFcShort( 0x0 ),	/* 0 */
/* 896 */	NdrFcShort( 0x8 ),	/* 8 */
/* 898 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 900 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 902 */	NdrFcShort( 0x0 ),	/* 0 */
/* 904 */	NdrFcShort( 0x0 ),	/* 0 */
/* 906 */	NdrFcShort( 0x0 ),	/* 0 */
/* 908 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppContext */

/* 910 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 912 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 914 */	NdrFcShort( 0xae ),	/* Type Offset=174 */

	/* Return value */

/* 916 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 918 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 920 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDef */

/* 922 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 924 */	NdrFcLong( 0x0 ),	/* 0 */
/* 928 */	NdrFcShort( 0x9 ),	/* 9 */
/* 930 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 932 */	NdrFcShort( 0x0 ),	/* 0 */
/* 934 */	NdrFcShort( 0x8 ),	/* 8 */
/* 936 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 938 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 940 */	NdrFcShort( 0x0 ),	/* 0 */
/* 942 */	NdrFcShort( 0x0 ),	/* 0 */
/* 944 */	NdrFcShort( 0x0 ),	/* 0 */
/* 946 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppDef */

/* 948 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 950 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 952 */	NdrFcShort( 0xc4 ),	/* Type Offset=196 */

	/* Return value */

/* 954 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 956 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 958 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetHsmId */

/* 960 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 962 */	NdrFcLong( 0x0 ),	/* 0 */
/* 966 */	NdrFcShort( 0xa ),	/* 10 */
/* 968 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 970 */	NdrFcShort( 0x0 ),	/* 0 */
/* 972 */	NdrFcShort( 0x4c ),	/* 76 */
/* 974 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 976 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 978 */	NdrFcShort( 0x0 ),	/* 0 */
/* 980 */	NdrFcShort( 0x0 ),	/* 0 */
/* 982 */	NdrFcShort( 0x0 ),	/* 0 */
/* 984 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */

/* 986 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 988 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 990 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Return value */

/* 992 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 994 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 996 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetResourceId */


	/* Procedure GetIdentifier */

/* 998 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1000 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1004 */	NdrFcShort( 0xb ),	/* 11 */
/* 1006 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1008 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1010 */	NdrFcShort( 0x4c ),	/* 76 */
/* 1012 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1014 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1016 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1018 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1020 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1022 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */


	/* Parameter pId */

/* 1024 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 1026 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1028 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Return value */


	/* Return value */

/* 1030 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1032 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1034 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetRunId */


	/* Procedure GetMaxActiveSessions */

/* 1036 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1038 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1042 */	NdrFcShort( 0xc ),	/* 12 */
/* 1044 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1046 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1048 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1050 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1052 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1054 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1056 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1058 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1060 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */


	/* Parameter pMaxActiveSessions */

/* 1062 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1064 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1066 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 1068 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1070 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1072 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetStateAsString */


	/* Procedure GetStartingPath */


	/* Procedure GetName */

/* 1074 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1076 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1080 */	NdrFcShort( 0xd ),	/* 13 */
/* 1082 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1084 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1086 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1088 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1090 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1092 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1094 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1096 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1098 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */


	/* Parameter pString */


	/* Parameter pName */

/* 1100 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 1102 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1104 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter bufferSize */


	/* Parameter bufferSize */


	/* Parameter bufferSize */

/* 1106 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1108 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1110 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 1112 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1114 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1116 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetRunId */

/* 1118 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1120 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1124 */	NdrFcShort( 0xe ),	/* 14 */
/* 1126 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1128 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1130 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1132 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1134 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1136 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1138 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1140 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1142 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */

/* 1144 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1146 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1148 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1150 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1152 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1154 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetState */


	/* Procedure GetState */

/* 1156 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1158 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1162 */	NdrFcShort( 0xf ),	/* 15 */
/* 1164 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1166 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1168 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1170 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1172 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1174 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1176 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1178 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1180 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pState */


	/* Parameter pState */

/* 1182 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1184 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1186 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 1188 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1190 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1192 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure InitAs */

/* 1194 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1196 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1200 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1202 */	NdrFcShort( 0x50 ),	/* ia64 Stack size/offset = 80 */
/* 1204 */	NdrFcShort( 0x40 ),	/* 64 */
/* 1206 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1208 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x8,		/* 8 */
/* 1210 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1212 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1214 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1216 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1218 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 1220 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1222 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1224 */	NdrFcShort( 0x6a ),	/* Type Offset=106 */

	/* Parameter pDef */

/* 1226 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1228 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1230 */	NdrFcShort( 0xc8 ),	/* Type Offset=200 */

	/* Parameter type */

/* 1232 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1234 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1236 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter storagePool */

/* 1238 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 1240 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1242 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Parameter pServer */

/* 1244 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1246 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 1248 */	NdrFcShort( 0xde ),	/* Type Offset=222 */

	/* Parameter isUserDefined */

/* 1250 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1252 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 1254 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pResource */

/* 1256 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1258 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 1260 */	NdrFcShort( 0xf0 ),	/* Type Offset=240 */

	/* Return value */

/* 1262 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1264 */	NdrFcShort( 0x48 ),	/* ia64 Stack size/offset = 72 */
/* 1266 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsActive */

/* 1268 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1270 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1274 */	NdrFcShort( 0x11 ),	/* 17 */
/* 1276 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1278 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1280 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1282 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1284 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1286 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1288 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1290 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1292 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1294 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1296 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1298 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsUserDefined */

/* 1300 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1302 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1306 */	NdrFcShort( 0x12 ),	/* 18 */
/* 1308 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1310 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1312 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1314 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1316 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1318 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1320 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1322 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1324 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1326 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1328 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1330 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Pause */

/* 1332 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1334 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1338 */	NdrFcShort( 0x13 ),	/* 19 */
/* 1340 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1342 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1344 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1346 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1348 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1350 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1352 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1354 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1356 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter phase */

/* 1358 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1360 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1362 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 1364 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1366 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1368 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SkipSystemItems */


	/* Procedure Restart */

/* 1370 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1372 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1376 */	NdrFcShort( 0x14 ),	/* 20 */
/* 1378 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1380 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1382 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1384 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1386 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1388 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1390 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1392 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1394 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */

/* 1396 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1398 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1400 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Resume */

/* 1402 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1404 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1408 */	NdrFcShort( 0x15 ),	/* 21 */
/* 1410 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1412 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1414 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1416 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1418 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1420 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1422 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1424 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1426 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter phase */

/* 1428 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1430 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1432 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 1434 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1436 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1438 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetContext */

/* 1440 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1442 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1446 */	NdrFcShort( 0x16 ),	/* 22 */
/* 1448 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1450 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1452 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1454 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1456 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1458 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1460 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1462 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1464 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pContext */

/* 1466 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1468 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1470 */	NdrFcShort( 0x102 ),	/* Type Offset=258 */

	/* Return value */

/* 1472 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1474 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1476 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetDef */

/* 1478 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1480 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1484 */	NdrFcShort( 0x17 ),	/* 23 */
/* 1486 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1488 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1490 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1492 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1494 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1496 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1498 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1500 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1502 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pDef */

/* 1504 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1506 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1508 */	NdrFcShort( 0x114 ),	/* Type Offset=276 */

	/* Return value */

/* 1510 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1512 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1514 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetHsmId */

/* 1516 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1518 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1522 */	NdrFcShort( 0x18 ),	/* 24 */
/* 1524 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1526 */	NdrFcShort( 0x30 ),	/* 48 */
/* 1528 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1530 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1532 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1534 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1536 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1538 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1540 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter id */

/* 1542 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 1544 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1546 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Return value */

/* 1548 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1550 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1552 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetIsUserDefined */

/* 1554 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1556 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1560 */	NdrFcShort( 0x19 ),	/* 25 */
/* 1562 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1564 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1566 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1568 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1570 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1572 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1574 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1576 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1578 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter isUserDefined */

/* 1580 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1582 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1584 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1586 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1588 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1590 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetName */

/* 1592 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1594 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1598 */	NdrFcShort( 0x1a ),	/* 26 */
/* 1600 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1602 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1604 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1606 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1608 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1610 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1612 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1614 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1616 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 1618 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 1620 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1622 */	NdrFcShort( 0x6a ),	/* Type Offset=106 */

	/* Return value */

/* 1624 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1626 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1628 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Start */

/* 1630 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1632 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1636 */	NdrFcShort( 0x1b ),	/* 27 */
/* 1638 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1640 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1642 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1644 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1646 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1648 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1650 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1652 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1654 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1656 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1658 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1660 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Suspend */

/* 1662 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1664 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1668 */	NdrFcShort( 0x1c ),	/* 28 */
/* 1670 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1672 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1674 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1676 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1678 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1680 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1682 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1684 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1686 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter phase */

/* 1688 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1690 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1692 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 1694 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1696 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1698 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure WaitUntilDone */

/* 1700 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1702 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1706 */	NdrFcShort( 0x1d ),	/* 29 */
/* 1708 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1710 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1712 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1714 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1716 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1718 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1720 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1722 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1724 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 1726 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1728 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1730 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure EnumPolicies */


	/* Procedure EnumResources */

/* 1732 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1734 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1738 */	NdrFcShort( 0x3 ),	/* 3 */
/* 1740 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1742 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1744 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1746 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1748 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1750 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1752 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1754 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1756 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppEnum */


	/* Parameter ppEnum */

/* 1758 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1760 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1762 */	NdrFcShort( 0x126 ),	/* Type Offset=294 */

	/* Return value */


	/* Return value */

/* 1764 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1766 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1768 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Resources */

/* 1770 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1772 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1776 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1778 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1780 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1782 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1784 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1786 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1788 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1790 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1792 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1794 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppResources */

/* 1796 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1798 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1800 */	NdrFcShort( 0x13c ),	/* Type Offset=316 */

	/* Return value */

/* 1802 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1804 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1806 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetUsesAllManaged */

/* 1808 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1810 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1814 */	NdrFcShort( 0x5 ),	/* 5 */
/* 1816 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1818 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1820 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1822 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1824 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1826 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1828 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1830 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1832 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter usesAllManaged */

/* 1834 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1836 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1838 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1840 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1842 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1844 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DoPreScan */


	/* Procedure UsesAllManaged */

/* 1846 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1848 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1852 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1854 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1856 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1858 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1860 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1862 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1864 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1866 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1868 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1870 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */

/* 1872 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1874 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1876 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetIdentifier */

/* 1878 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1880 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1884 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1886 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1888 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1890 */	NdrFcShort( 0x4c ),	/* 76 */
/* 1892 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1894 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1896 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1898 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1900 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1902 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */

/* 1904 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 1906 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1908 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Return value */

/* 1910 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1912 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1914 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPostActionOnResource */

/* 1916 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1918 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1922 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1924 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1926 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1928 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1930 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1932 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1934 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1936 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1938 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1940 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppAction */

/* 1942 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1944 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1946 */	NdrFcShort( 0x152 ),	/* Type Offset=338 */

	/* Return value */

/* 1948 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1950 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1952 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPreActionOnResource */

/* 1954 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1956 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1960 */	NdrFcShort( 0x7 ),	/* 7 */
/* 1962 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1964 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1966 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1968 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1970 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1972 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1974 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1976 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1978 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppAction */

/* 1980 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1982 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1984 */	NdrFcShort( 0x168 ),	/* Type Offset=360 */

	/* Return value */

/* 1986 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1988 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1990 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPreScanActionOnResource */

/* 1992 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1994 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1998 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2000 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2002 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2004 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2006 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2008 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2010 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2012 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2014 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2016 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppAction */

/* 2018 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2020 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2022 */	NdrFcShort( 0x17e ),	/* Type Offset=382 */

	/* Return value */

/* 2024 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2026 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2028 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure InitAs */

/* 2030 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2032 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2036 */	NdrFcShort( 0x9 ),	/* 9 */
/* 2038 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 2040 */	NdrFcShort( 0x40 ),	/* 64 */
/* 2042 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2044 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 2046 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2048 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2050 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2052 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2054 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 2056 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2058 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2060 */	NdrFcShort( 0x6a ),	/* Type Offset=106 */

	/* Parameter type */

/* 2062 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2064 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2066 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter storagePool */

/* 2068 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 2070 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2072 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Parameter pServer */

/* 2074 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2076 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 2078 */	NdrFcShort( 0xde ),	/* Type Offset=222 */

	/* Parameter isUserDefined */

/* 2080 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2082 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 2084 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2086 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2088 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 2090 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Policies */

/* 2092 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2094 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2098 */	NdrFcShort( 0xa ),	/* 10 */
/* 2100 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2102 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2104 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2106 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2108 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2110 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2112 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2114 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2116 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppPolicies */

/* 2118 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2120 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2122 */	NdrFcShort( 0x13c ),	/* Type Offset=316 */

	/* Return value */

/* 2124 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2126 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2128 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetName */

/* 2130 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2132 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2136 */	NdrFcShort( 0xb ),	/* 11 */
/* 2138 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2140 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2142 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2144 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2146 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2148 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2150 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2152 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2154 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 2156 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2158 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2160 */	NdrFcShort( 0x6a ),	/* Type Offset=106 */

	/* Return value */

/* 2162 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2164 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2166 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetPostActionOnResource */

/* 2168 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2170 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2174 */	NdrFcShort( 0xc ),	/* 12 */
/* 2176 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2178 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2180 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2182 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2184 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2186 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2188 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2190 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2192 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pAction */

/* 2194 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2196 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2198 */	NdrFcShort( 0x156 ),	/* Type Offset=342 */

	/* Return value */

/* 2200 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2202 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2204 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetPreActionOnResource */

/* 2206 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2208 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2212 */	NdrFcShort( 0xd ),	/* 13 */
/* 2214 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2216 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2218 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2220 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2222 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2224 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2226 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2228 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2230 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pAction */

/* 2232 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2234 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2236 */	NdrFcShort( 0x16c ),	/* Type Offset=364 */

	/* Return value */

/* 2238 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2240 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2242 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetPreScanActionOnResource */

/* 2244 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2246 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2250 */	NdrFcShort( 0xe ),	/* 14 */
/* 2252 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2254 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2256 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2258 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2260 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2262 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2264 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2266 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2268 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pAction */

/* 2270 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2272 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2274 */	NdrFcShort( 0x182 ),	/* Type Offset=386 */

	/* Return value */

/* 2276 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2278 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2280 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetIsUserDefined */


	/* Procedure SetSkipHiddenItems */

/* 2282 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2284 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2288 */	NdrFcShort( 0xf ),	/* 15 */
/* 2290 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2292 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2294 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2296 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2298 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2300 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2302 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2304 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2306 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter isUserDefined */


	/* Parameter shouldSkip */

/* 2308 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2310 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2312 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 2314 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2316 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2318 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetIsUsedInSubDirs */


	/* Procedure SetSkipSystemItems */

/* 2320 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2322 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2326 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2328 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2330 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2332 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2334 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2336 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2338 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2340 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2342 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2344 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter isUsed */


	/* Parameter shouldSkip */

/* 2346 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2348 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2350 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 2352 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2354 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2356 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetUseRPIndex */

/* 2358 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2360 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2364 */	NdrFcShort( 0x11 ),	/* 17 */
/* 2366 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2368 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2370 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2372 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2374 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2376 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2378 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2380 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2382 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter useIndex */

/* 2384 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2386 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2388 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2390 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2392 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2394 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetUseDbIndex */

/* 2396 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2398 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2402 */	NdrFcShort( 0x12 ),	/* 18 */
/* 2404 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2406 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2408 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2410 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2412 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2414 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2416 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2418 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2420 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter useIndex */

/* 2422 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2424 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2426 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2428 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2430 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2432 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SkipHiddenItems */

/* 2434 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2436 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2440 */	NdrFcShort( 0x13 ),	/* 19 */
/* 2442 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2444 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2446 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2448 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 2450 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2452 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2454 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2456 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2458 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 2460 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2462 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2464 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure UseRPIndex */

/* 2466 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2468 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2472 */	NdrFcShort( 0x15 ),	/* 21 */
/* 2474 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2476 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2478 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2480 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 2482 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2484 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2486 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2488 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2490 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 2492 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2494 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2496 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure UseDbIndex */

/* 2498 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2500 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2504 */	NdrFcShort( 0x16 ),	/* 22 */
/* 2506 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2508 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2510 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2512 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 2514 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2516 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2518 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2520 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2522 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 2524 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2526 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2528 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ProcessJobSession */

/* 2530 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2532 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2536 */	NdrFcShort( 0x3 ),	/* 3 */
/* 2538 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 2540 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2542 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2544 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 2546 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2548 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2550 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2552 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2554 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSession */

/* 2556 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2558 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2560 */	NdrFcShort( 0x194 ),	/* Type Offset=404 */

	/* Parameter pPhase */

/* 2562 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2564 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2566 */	NdrFcShort( 0x1a6 ),	/* Type Offset=422 */

	/* Parameter currentPath */

/* 2568 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2570 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2572 */	NdrFcShort( 0x6a ),	/* Type Offset=106 */

	/* Return value */

/* 2574 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2576 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2578 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToResourceId */

/* 2580 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2582 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2586 */	NdrFcShort( 0x3 ),	/* 3 */
/* 2588 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 2590 */	NdrFcShort( 0x30 ),	/* 48 */
/* 2592 */	NdrFcShort( 0x22 ),	/* 34 */
/* 2594 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 2596 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2598 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2600 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2602 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2604 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter id */

/* 2606 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 2608 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2610 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Parameter pResult */

/* 2612 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2614 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2616 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2618 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2620 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2622 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToIWorkItem */

/* 2624 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2626 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2630 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2632 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2634 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2636 */	NdrFcShort( 0x22 ),	/* 34 */
/* 2638 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2640 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2642 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2644 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2646 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2648 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pWorkItem */

/* 2650 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2652 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2654 */	NdrFcShort( 0x1bc ),	/* Type Offset=444 */

	/* Parameter pResult */

/* 2656 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2658 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2660 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2662 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2664 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2666 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure EnumPhases */

/* 2668 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2670 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2674 */	NdrFcShort( 0x7 ),	/* 7 */
/* 2676 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2678 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2680 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2682 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2684 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2686 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2688 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2690 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2692 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppEnum */

/* 2694 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2696 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2698 */	NdrFcShort( 0x1ce ),	/* Type Offset=462 */

	/* Return value */

/* 2700 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2702 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2704 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure EnumTotals */

/* 2706 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2708 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2712 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2714 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2716 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2718 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2720 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2722 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2724 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2726 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2728 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2730 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppEnum */

/* 2732 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2734 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2736 */	NdrFcShort( 0x1ce ),	/* Type Offset=462 */

	/* Return value */

/* 2738 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2740 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2742 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPath */


	/* Procedure GetCurrentPath */

/* 2744 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2746 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2750 */	NdrFcShort( 0x9 ),	/* 9 */
/* 2752 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2754 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2756 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2758 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2760 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2762 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2764 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2766 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2768 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPath */


	/* Parameter pString */

/* 2770 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 2772 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2774 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter bufferSize */


	/* Parameter bufferSize */

/* 2776 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2778 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2780 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 2782 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2784 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2786 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetFinishTime */

/* 2788 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2790 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2794 */	NdrFcShort( 0xa ),	/* 10 */
/* 2796 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2798 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2800 */	NdrFcShort( 0x34 ),	/* 52 */
/* 2802 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2804 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2806 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2808 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2810 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2812 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pTime */

/* 2814 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 2816 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2818 */	NdrFcShort( 0x1e8 ),	/* Type Offset=488 */

	/* Return value */

/* 2820 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2822 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2824 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSession */

/* 2826 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2828 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2832 */	NdrFcShort( 0xc ),	/* 12 */
/* 2834 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2836 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2838 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2840 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2842 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2844 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2846 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2848 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2850 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppSession */

/* 2852 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2854 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2856 */	NdrFcShort( 0x1f0 ),	/* Type Offset=496 */

	/* Return value */

/* 2858 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2860 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2862 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetStartTime */

/* 2864 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2866 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2870 */	NdrFcShort( 0xe ),	/* 14 */
/* 2872 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2874 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2876 */	NdrFcShort( 0x34 ),	/* 52 */
/* 2878 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2880 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2882 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2884 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2886 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2888 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pTime */

/* 2890 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 2892 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2894 */	NdrFcShort( 0x1e8 ),	/* Type Offset=488 */

	/* Return value */

/* 2896 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2898 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2900 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetStateAsString */

/* 2902 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2904 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2908 */	NdrFcShort( 0x10 ),	/* 16 */
/* 2910 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2912 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2914 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2916 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2918 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2920 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2922 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2924 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2926 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */

/* 2928 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 2930 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2932 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter bufferSize */

/* 2934 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2936 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2938 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2940 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2942 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2944 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSubRunId */

/* 2946 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2948 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2952 */	NdrFcShort( 0x11 ),	/* 17 */
/* 2954 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2956 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2958 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2960 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2962 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2964 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2966 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2968 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2970 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */

/* 2972 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2974 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2976 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2978 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2980 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2982 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Clone */

/* 2984 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2986 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2990 */	NdrFcShort( 0x3 ),	/* 3 */
/* 2992 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2994 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2996 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2998 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 3000 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3002 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3004 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3006 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3008 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppPhase */

/* 3010 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3012 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3014 */	NdrFcShort( 0x206 ),	/* Type Offset=518 */

	/* Return value */

/* 3016 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3018 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3020 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CopyTo */

/* 3022 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3024 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3028 */	NdrFcShort( 0x4 ),	/* 4 */
/* 3030 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3032 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3034 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3036 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3038 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3040 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3042 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3044 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3046 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPhase */

/* 3048 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3050 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3052 */	NdrFcShort( 0x20a ),	/* Type Offset=522 */

	/* Return value */

/* 3054 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3056 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3058 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetElapsedTime */

/* 3060 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3062 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3066 */	NdrFcShort( 0x5 ),	/* 5 */
/* 3068 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 3070 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3072 */	NdrFcShort( 0x72 ),	/* 114 */
/* 3074 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x5,		/* 5 */
/* 3076 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3078 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3080 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3082 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3084 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pDays */

/* 3086 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3088 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3090 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pHours */

/* 3092 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3094 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3096 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pMinutes */

/* 3098 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3100 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3102 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pSeconds */

/* 3104 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3106 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3108 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 3110 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3112 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 3114 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetMediaState */

/* 3116 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3118 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3122 */	NdrFcShort( 0x6 ),	/* 6 */
/* 3124 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3126 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3128 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3130 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3132 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3134 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3136 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3138 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3140 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pState */

/* 3142 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3144 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3146 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 3148 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3150 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3152 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetName */


	/* Procedure GetMediaStateAsString */

/* 3154 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3156 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3160 */	NdrFcShort( 0x7 ),	/* 7 */
/* 3162 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3164 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3166 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3168 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 3170 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3172 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3174 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3176 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3178 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */


	/* Parameter pName */

/* 3180 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 3182 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3184 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter bufferSize */


	/* Parameter bufferSize */

/* 3186 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3188 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3190 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 3192 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3194 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3196 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetName */


	/* Procedure GetSearchName */


	/* Procedure GetName */

/* 3198 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3200 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3204 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3206 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3208 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3210 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3212 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 3214 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3216 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3218 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3220 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3222 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */


	/* Parameter pName */


	/* Parameter pName */

/* 3224 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 3226 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3228 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter bufferSize */


	/* Parameter bufferSize */


	/* Parameter bufferSize */

/* 3230 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3232 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3234 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 3236 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3238 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3240 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPhase */

/* 3242 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3244 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3248 */	NdrFcShort( 0x9 ),	/* 9 */
/* 3250 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3252 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3254 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3256 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3258 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3260 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3262 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3264 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3266 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPhase */

/* 3268 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3270 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3272 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 3274 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3276 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3278 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPriority */

/* 3280 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3282 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3286 */	NdrFcShort( 0xa ),	/* 10 */
/* 3288 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3290 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3292 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3294 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3296 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3298 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3300 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3302 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3304 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPriority */

/* 3306 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3308 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3310 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 3312 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3314 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3316 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPriorityAsString */

/* 3318 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3320 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3324 */	NdrFcShort( 0xb ),	/* 11 */
/* 3326 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3328 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3330 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3332 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 3334 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3336 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3338 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3340 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3342 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */

/* 3344 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 3346 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3348 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter bufferSize */

/* 3350 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3352 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3354 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3356 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3358 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3360 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetState */

/* 3362 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3364 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3368 */	NdrFcShort( 0xc ),	/* 12 */
/* 3370 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3372 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3374 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3376 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3378 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3380 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3382 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3384 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3386 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pState */

/* 3388 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3390 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3392 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 3394 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3396 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3398 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetStats */

/* 3400 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3402 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3406 */	NdrFcShort( 0xe ),	/* 14 */
/* 3408 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 3410 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3412 */	NdrFcShort( 0xe0 ),	/* 224 */
/* 3414 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x7,		/* 7 */
/* 3416 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3418 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3420 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3422 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3424 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter items */

/* 3426 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3428 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3430 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 3432 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3434 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3436 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter skippedItems */

/* 3438 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3440 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3442 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter skippedSize */

/* 3444 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3446 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3448 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter errorItems */

/* 3450 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3452 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 3454 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter errorSize */

/* 3456 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3458 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 3460 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 3462 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3464 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 3466 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetStartTime */

/* 3468 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3470 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3474 */	NdrFcShort( 0xf ),	/* 15 */
/* 3476 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3478 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3480 */	NdrFcShort( 0x34 ),	/* 52 */
/* 3482 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3484 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3486 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3488 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3490 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3492 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pTime */

/* 3494 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 3496 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3498 */	NdrFcShort( 0x1e8 ),	/* Type Offset=488 */

	/* Return value */

/* 3500 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3502 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3504 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetStopTime */

/* 3506 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3508 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3512 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3514 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3516 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3518 */	NdrFcShort( 0x34 ),	/* 52 */
/* 3520 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3522 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3524 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3526 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3528 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3530 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pTime */

/* 3532 */	NdrFcShort( 0x2112 ),	/* Flags:  must free, out, simple ref, srv alloc size=8 */
/* 3534 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3536 */	NdrFcShort( 0x1e8 ),	/* Type Offset=488 */

	/* Return value */

/* 3538 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3540 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3542 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure EnumRules */

/* 3544 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3546 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3550 */	NdrFcShort( 0x3 ),	/* 3 */
/* 3552 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3554 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3556 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3558 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 3560 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3562 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3564 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3566 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3568 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppEnum */

/* 3570 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3572 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3574 */	NdrFcShort( 0x1ce ),	/* Type Offset=462 */

	/* Return value */

/* 3576 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3578 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3580 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetAction */

/* 3582 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3584 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3588 */	NdrFcShort( 0x4 ),	/* 4 */
/* 3590 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3592 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3594 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3596 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 3598 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3600 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3602 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3604 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3606 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppAction */

/* 3608 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3610 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3612 */	NdrFcShort( 0x220 ),	/* Type Offset=544 */

	/* Return value */

/* 3614 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3616 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3618 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetIdentifier */

/* 3620 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3622 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3626 */	NdrFcShort( 0x5 ),	/* 5 */
/* 3628 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3630 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3632 */	NdrFcShort( 0x4c ),	/* 76 */
/* 3634 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3636 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3638 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3640 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3642 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3644 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */

/* 3646 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 3648 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3650 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Return value */

/* 3652 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3654 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3656 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetScale */

/* 3658 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3660 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3664 */	NdrFcShort( 0x7 ),	/* 7 */
/* 3666 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3668 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3670 */	NdrFcShort( 0x22 ),	/* 34 */
/* 3672 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3674 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3676 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3678 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3680 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3682 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pScale */

/* 3684 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3686 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3688 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 3690 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3692 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3694 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Rules */

/* 3696 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3698 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3702 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3704 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3706 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3708 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3710 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 3712 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3714 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3716 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3718 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3720 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppWsbCollection */

/* 3722 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3724 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3726 */	NdrFcShort( 0x236 ),	/* Type Offset=566 */

	/* Return value */

/* 3728 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3730 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3732 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetAction */

/* 3734 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3736 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3740 */	NdrFcShort( 0x9 ),	/* 9 */
/* 3742 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3744 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3746 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3748 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3750 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3752 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3754 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3756 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3758 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pAction */

/* 3760 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3762 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3764 */	NdrFcShort( 0x224 ),	/* Type Offset=548 */

	/* Return value */

/* 3766 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3768 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3770 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetName */

/* 3772 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3774 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3778 */	NdrFcShort( 0xa ),	/* 10 */
/* 3780 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3782 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3784 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3786 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3788 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3790 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3792 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3794 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3796 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 3798 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3800 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3802 */	NdrFcShort( 0x6a ),	/* Type Offset=106 */

	/* Return value */

/* 3804 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3806 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3808 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetScale */

/* 3810 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3812 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3816 */	NdrFcShort( 0xb ),	/* 11 */
/* 3818 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3820 */	NdrFcShort( 0x6 ),	/* 6 */
/* 3822 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3824 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3826 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3828 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3830 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3832 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3834 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter scale */

/* 3836 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3838 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3840 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 3842 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3844 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3846 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetUsesDefaultRules */

/* 3848 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3850 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3854 */	NdrFcShort( 0xc ),	/* 12 */
/* 3856 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3858 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3860 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3862 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3864 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3866 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3868 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3870 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3872 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter usesDefaults */

/* 3874 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3876 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3878 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3880 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3882 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3884 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure UsesDefaultRules */

/* 3886 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3888 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3892 */	NdrFcShort( 0xd ),	/* 13 */
/* 3894 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3896 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3898 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3900 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 3902 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3904 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3906 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3908 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3910 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 3912 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3914 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3916 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Pop */


	/* Procedure SetDestination */

/* 3918 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3920 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3924 */	NdrFcShort( 0x6 ),	/* 6 */
/* 3926 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3928 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3930 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3932 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3934 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3936 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3938 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3940 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3942 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter path */


	/* Parameter dest */

/* 3944 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3946 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3948 */	NdrFcShort( 0x6a ),	/* Type Offset=106 */

	/* Return value */


	/* Return value */

/* 3950 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3952 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3954 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetRetainHierarchy */

/* 3956 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3958 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3962 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3964 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3966 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3968 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3970 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3972 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3974 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3976 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3978 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3980 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter retainHierarchy */

/* 3982 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3984 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3986 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3988 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3990 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3992 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToIRule */

/* 3994 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3996 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4000 */	NdrFcShort( 0x3 ),	/* 3 */
/* 4002 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 4004 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4006 */	NdrFcShort( 0x22 ),	/* 34 */
/* 4008 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 4010 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4012 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4014 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4016 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4018 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pRule */

/* 4020 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 4022 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4024 */	NdrFcShort( 0x24c ),	/* Type Offset=588 */

	/* Parameter pResult */

/* 4026 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4028 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4030 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 4032 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4034 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4036 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToPathAndName */

/* 4038 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4040 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4044 */	NdrFcShort( 0x4 ),	/* 4 */
/* 4046 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 4048 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4050 */	NdrFcShort( 0x22 ),	/* 34 */
/* 4052 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 4054 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4056 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4058 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4060 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4062 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter path */

/* 4064 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 4066 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4068 */	NdrFcShort( 0x6a ),	/* Type Offset=106 */

	/* Parameter name */

/* 4070 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 4072 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4074 */	NdrFcShort( 0x6a ),	/* Type Offset=106 */

	/* Parameter pResult */

/* 4076 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4078 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4080 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 4082 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4084 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 4086 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Criteria */

/* 4088 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4090 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4094 */	NdrFcShort( 0x5 ),	/* 5 */
/* 4096 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4098 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4100 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4102 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 4104 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4106 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4108 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4110 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4112 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppWsbCollection */

/* 4114 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 4116 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4118 */	NdrFcShort( 0x236 ),	/* Type Offset=566 */

	/* Return value */

/* 4120 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4122 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4124 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure EnumCriteria */

/* 4126 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4128 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4132 */	NdrFcShort( 0x6 ),	/* 6 */
/* 4134 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4136 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4138 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4140 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 4142 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4144 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4146 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4148 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4150 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppEnum */

/* 4152 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 4154 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4156 */	NdrFcShort( 0x1ce ),	/* Type Offset=462 */

	/* Return value */

/* 4158 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4160 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4162 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsInclude */

/* 4164 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4166 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4170 */	NdrFcShort( 0xa ),	/* 10 */
/* 4172 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4174 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4176 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4178 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 4180 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4182 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4184 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4186 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4188 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 4190 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4192 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4194 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsUserDefined */

/* 4196 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4198 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4202 */	NdrFcShort( 0xb ),	/* 11 */
/* 4204 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4206 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4208 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4210 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 4212 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4214 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4216 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4218 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4220 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 4222 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4224 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4226 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsUsedInSubDirs */

/* 4228 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4230 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4234 */	NdrFcShort( 0xc ),	/* 12 */
/* 4236 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4238 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4240 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4242 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 4244 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4246 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4248 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4250 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4252 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 4254 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4256 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4258 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure MatchesName */

/* 4260 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4262 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4266 */	NdrFcShort( 0xd ),	/* 13 */
/* 4268 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4270 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4272 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4274 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 4276 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4278 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4280 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4282 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4284 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 4286 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 4288 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4290 */	NdrFcShort( 0x6a ),	/* Type Offset=106 */

	/* Return value */

/* 4292 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4294 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4296 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetIsInclude */

/* 4298 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4300 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4304 */	NdrFcShort( 0xe ),	/* 14 */
/* 4306 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4308 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4310 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4312 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4314 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4316 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4318 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4320 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4322 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter isInclude */

/* 4324 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4326 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4328 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4330 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4332 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4334 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetName */

/* 4336 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4338 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4342 */	NdrFcShort( 0x11 ),	/* 17 */
/* 4344 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4346 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4348 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4350 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 4352 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4354 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4356 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4358 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4360 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 4362 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 4364 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4366 */	NdrFcShort( 0x6a ),	/* Type Offset=106 */

	/* Return value */

/* 4368 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4370 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4372 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetPath */

/* 4374 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4376 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4380 */	NdrFcShort( 0x12 ),	/* 18 */
/* 4382 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4384 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4386 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4388 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 4390 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4392 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4394 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4396 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4398 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter path */

/* 4400 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 4402 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4404 */	NdrFcShort( 0x6a ),	/* Type Offset=106 */

	/* Return value */

/* 4406 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4408 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4410 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Do */

/* 4412 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4414 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4418 */	NdrFcShort( 0x3 ),	/* 3 */
/* 4420 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4422 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4424 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4426 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 4428 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4430 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4432 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4434 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4436 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pScanItem */

/* 4438 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 4440 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4442 */	NdrFcShort( 0x25e ),	/* Type Offset=606 */

	/* Return value */

/* 4444 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4446 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4448 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DoesMatch */

/* 4450 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4452 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4456 */	NdrFcShort( 0x4 ),	/* 4 */
/* 4458 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 4460 */	NdrFcShort( 0x1c ),	/* 28 */
/* 4462 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4464 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 4466 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4468 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4470 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4472 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4474 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pScanItem */

/* 4476 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 4478 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4480 */	NdrFcShort( 0x25e ),	/* Type Offset=606 */

	/* Parameter pShouldDo */

/* 4482 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 4484 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4486 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4488 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4490 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4492 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Init */

/* 4494 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4496 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4500 */	NdrFcShort( 0x5 ),	/* 5 */
/* 4502 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 4504 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4506 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4508 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 4510 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4512 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4514 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4516 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4518 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPolicy */

/* 4520 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 4522 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4524 */	NdrFcShort( 0x274 ),	/* Type Offset=628 */

	/* Parameter pResource */

/* 4526 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 4528 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4530 */	NdrFcShort( 0x286 ),	/* Type Offset=646 */

	/* Return value */

/* 4532 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4534 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4536 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Push */

/* 4538 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4540 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4544 */	NdrFcShort( 0x7 ),	/* 7 */
/* 4546 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4548 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4550 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4552 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 4554 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4556 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4558 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4560 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4562 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter path */

/* 4564 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 4566 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4568 */	NdrFcShort( 0x6a ),	/* Type Offset=106 */

	/* Return value */

/* 4570 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4572 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4574 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Start */

/* 4576 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4578 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4582 */	NdrFcShort( 0x3 ),	/* 3 */
/* 4584 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 4586 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4588 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4590 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 4592 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4594 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4596 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4598 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4600 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSession */

/* 4602 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 4604 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4606 */	NdrFcShort( 0x194 ),	/* Type Offset=404 */

	/* Parameter path */

/* 4608 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 4610 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4612 */	NdrFcShort( 0x6a ),	/* Type Offset=106 */

	/* Return value */

/* 4614 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4616 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4618 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure EnumPhases */

/* 4620 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4622 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4626 */	NdrFcShort( 0x4 ),	/* 4 */
/* 4628 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4630 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4632 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4634 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 4636 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4638 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4640 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4642 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4644 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppEnum */

/* 4646 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 4648 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4650 */	NdrFcShort( 0x1ce ),	/* Type Offset=462 */

	/* Return value */

/* 4652 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4654 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4656 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure EnumTotals */

/* 4658 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4660 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4664 */	NdrFcShort( 0x5 ),	/* 5 */
/* 4666 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4668 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4670 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4672 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 4674 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4676 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4678 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4680 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4682 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppEnum */

/* 4684 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 4686 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4688 */	NdrFcShort( 0x1ce ),	/* Type Offset=462 */

	/* Return value */

/* 4690 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4692 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4694 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetAdviseInterval */

/* 4696 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4698 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4702 */	NdrFcShort( 0x6 ),	/* 6 */
/* 4704 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4706 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4708 */	NdrFcShort( 0x2c ),	/* 44 */
/* 4710 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4712 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4714 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4716 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4718 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4720 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFiletimeTicks */

/* 4722 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4724 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4726 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 4728 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4730 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4732 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetHsmId */

/* 4734 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4736 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4740 */	NdrFcShort( 0x7 ),	/* 7 */
/* 4742 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4744 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4746 */	NdrFcShort( 0x4c ),	/* 76 */
/* 4748 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4750 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4752 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4754 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4756 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4758 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */

/* 4760 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 4762 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4764 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Return value */

/* 4766 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4768 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4770 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetIdentifier */

/* 4772 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4774 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4778 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4780 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4782 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4784 */	NdrFcShort( 0x4c ),	/* 76 */
/* 4786 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4788 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4790 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4792 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4794 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4796 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */

/* 4798 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 4800 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4802 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Return value */

/* 4804 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4806 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4808 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetJob */

/* 4810 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4812 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4816 */	NdrFcShort( 0x9 ),	/* 9 */
/* 4818 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4820 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4822 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4824 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 4826 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4828 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4830 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4832 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4834 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppJob */

/* 4836 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 4838 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4840 */	NdrFcShort( 0x298 ),	/* Type Offset=664 */

	/* Return value */

/* 4842 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4844 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4846 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetName */

/* 4848 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4850 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4854 */	NdrFcShort( 0xa ),	/* 10 */
/* 4856 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 4858 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4860 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4862 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 4864 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4866 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4868 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4870 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4872 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */

/* 4874 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 4876 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4878 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter bufferSize */

/* 4880 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4882 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4884 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4886 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4888 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4890 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetResource */

/* 4892 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4894 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4898 */	NdrFcShort( 0xb ),	/* 11 */
/* 4900 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4902 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4904 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4906 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 4908 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4910 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4912 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4914 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4916 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppResource */

/* 4918 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 4920 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4922 */	NdrFcShort( 0x2ae ),	/* Type Offset=686 */

	/* Return value */

/* 4924 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4926 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4928 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetSubRunId */

/* 4930 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4932 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4936 */	NdrFcShort( 0xd ),	/* 13 */
/* 4938 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4940 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4942 */	NdrFcShort( 0x24 ),	/* 36 */
/* 4944 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4946 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4948 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4950 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4952 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4954 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */

/* 4956 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4958 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4960 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4962 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4964 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4966 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure IsCanceling */

/* 4968 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4970 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4974 */	NdrFcShort( 0xe ),	/* 14 */
/* 4976 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4978 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4980 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4982 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 4984 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4986 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4988 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4990 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4992 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 4994 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4996 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4998 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Pause */

/* 5000 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5002 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5006 */	NdrFcShort( 0xf ),	/* 15 */
/* 5008 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5010 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5012 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5014 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5016 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5018 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5020 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5022 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5024 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter phase */

/* 5026 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5028 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5030 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 5032 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5034 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5036 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ProcessEvent */

/* 5038 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5040 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5044 */	NdrFcShort( 0x10 ),	/* 16 */
/* 5046 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 5048 */	NdrFcShort( 0x10 ),	/* 16 */
/* 5050 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5052 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 5054 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5056 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5058 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5060 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5062 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter phase */

/* 5064 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5066 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5068 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter event */

/* 5070 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5072 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5074 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 5076 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5078 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5080 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ProcessHr */

/* 5082 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5084 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5088 */	NdrFcShort( 0x11 ),	/* 17 */
/* 5090 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 5092 */	NdrFcShort( 0x18 ),	/* 24 */
/* 5094 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5096 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 5098 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5100 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5102 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5104 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5106 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter phase */

/* 5108 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5110 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5112 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter file */

/* 5114 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 5116 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5118 */	NdrFcShort( 0x2c6 ),	/* Type Offset=710 */

	/* Parameter line */

/* 5120 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5122 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5124 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter hr */

/* 5126 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5128 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 5130 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5132 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5134 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 5136 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ProcessItem */

/* 5138 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5140 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5144 */	NdrFcShort( 0x12 ),	/* 18 */
/* 5146 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 5148 */	NdrFcShort( 0x18 ),	/* 24 */
/* 5150 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5152 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 5154 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5156 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5158 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5160 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5162 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter phase */

/* 5164 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5166 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5168 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter action */

/* 5170 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5172 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5174 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter pScanItem */

/* 5176 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5178 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5180 */	NdrFcShort( 0x2c8 ),	/* Type Offset=712 */

	/* Parameter hrItem */

/* 5182 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5184 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 5186 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5188 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5190 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 5192 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ProcessMediaState */

/* 5194 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5196 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5200 */	NdrFcShort( 0x13 ),	/* 19 */
/* 5202 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 5204 */	NdrFcShort( 0x20 ),	/* 32 */
/* 5206 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5208 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 5210 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5212 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5214 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5216 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5218 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter phase */

/* 5220 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5222 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5224 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter state */

/* 5226 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5228 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5230 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter mediaName */

/* 5232 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 5234 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5236 */	NdrFcShort( 0x6a ),	/* Type Offset=106 */

	/* Parameter mediaType */

/* 5238 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5240 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 5242 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter time */

/* 5244 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5246 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 5248 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5250 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5252 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 5254 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ProcessPriority */

/* 5256 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5258 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5262 */	NdrFcShort( 0x14 ),	/* 20 */
/* 5264 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 5266 */	NdrFcShort( 0x10 ),	/* 16 */
/* 5268 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5270 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 5272 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5274 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5276 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5278 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5280 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter phase */

/* 5282 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5284 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5286 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter priority */

/* 5288 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5290 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5292 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 5294 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5296 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5298 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ProcessState */

/* 5300 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5302 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5306 */	NdrFcShort( 0x15 ),	/* 21 */
/* 5308 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 5310 */	NdrFcShort( 0x18 ),	/* 24 */
/* 5312 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5314 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 5316 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5318 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5320 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5322 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5324 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter phase */

/* 5326 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5328 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5330 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter state */

/* 5332 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5334 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5336 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter currentPath */

/* 5338 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 5340 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5342 */	NdrFcShort( 0x6a ),	/* Type Offset=106 */

	/* Parameter bLog */

/* 5344 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5346 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 5348 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5350 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5352 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 5354 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ProcessString */

/* 5356 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5358 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5362 */	NdrFcShort( 0x16 ),	/* 22 */
/* 5364 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 5366 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5368 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5370 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 5372 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5374 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5376 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5378 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5380 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter phase */

/* 5382 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5384 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5386 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter string */

/* 5388 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 5390 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5392 */	NdrFcShort( 0x6a ),	/* Type Offset=106 */

	/* Return value */

/* 5394 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5396 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5398 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Resume */

/* 5400 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5402 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5406 */	NdrFcShort( 0x17 ),	/* 23 */
/* 5408 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5410 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5412 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5414 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5416 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5418 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5420 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5422 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5424 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter phase */

/* 5426 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5428 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5430 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 5432 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5434 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5436 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetAdviseInterval */

/* 5438 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5440 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5444 */	NdrFcShort( 0x18 ),	/* 24 */
/* 5446 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5448 */	NdrFcShort( 0x10 ),	/* 16 */
/* 5450 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5452 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5454 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5456 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5458 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5460 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5462 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter filetimeTicks */

/* 5464 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5466 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5468 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 5470 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5472 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5474 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Start */

/* 5476 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5478 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5482 */	NdrFcShort( 0x19 ),	/* 25 */
/* 5484 */	NdrFcShort( 0x50 ),	/* ia64 Stack size/offset = 80 */
/* 5486 */	NdrFcShort( 0x48 ),	/* 72 */
/* 5488 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5490 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x8,		/* 8 */
/* 5492 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5494 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5496 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5498 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5500 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter name */

/* 5502 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 5504 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5506 */	NdrFcShort( 0x6a ),	/* Type Offset=106 */

	/* Parameter logControl */

/* 5508 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5510 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5512 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter hsmId */

/* 5514 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 5516 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5518 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Parameter pJob */

/* 5520 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5522 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 5524 */	NdrFcShort( 0x29c ),	/* Type Offset=668 */

	/* Parameter pResource */

/* 5526 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5528 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 5530 */	NdrFcShort( 0x2b2 ),	/* Type Offset=690 */

	/* Parameter runId */

/* 5532 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5534 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 5536 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter subRunId */

/* 5538 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5540 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 5542 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5544 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5546 */	NdrFcShort( 0x48 ),	/* ia64 Stack size/offset = 72 */
/* 5548 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Suspend */

/* 5550 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5552 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5556 */	NdrFcShort( 0x1a ),	/* 26 */
/* 5558 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5560 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5562 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5564 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5566 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5568 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5570 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5572 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5574 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter phase */

/* 5576 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5578 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5580 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 5582 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5584 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5586 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ProcessSessionEvent */

/* 5588 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5590 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5594 */	NdrFcShort( 0x3 ),	/* 3 */
/* 5596 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 5598 */	NdrFcShort( 0x10 ),	/* 16 */
/* 5600 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5602 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 5604 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5606 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5608 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5610 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5612 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSession */

/* 5614 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5616 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5618 */	NdrFcShort( 0x1f4 ),	/* Type Offset=500 */

	/* Parameter phase */

/* 5620 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5622 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5624 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter event */

/* 5626 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5628 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5630 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 5632 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5634 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 5636 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ProcessSessionItem */


	/* Procedure ProcessSessionItem */

/* 5638 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5640 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5644 */	NdrFcShort( 0x3 ),	/* 3 */
/* 5646 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 5648 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5650 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5652 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 5654 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5656 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5658 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5660 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5662 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSession */


	/* Parameter pSession */

/* 5664 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5666 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5668 */	NdrFcShort( 0x1f4 ),	/* Type Offset=500 */

	/* Parameter pPhase */


	/* Parameter pPhase */

/* 5670 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5672 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5674 */	NdrFcShort( 0x20a ),	/* Type Offset=522 */

	/* Parameter pScanItem */


	/* Parameter pScanItem */

/* 5676 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5678 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5680 */	NdrFcShort( 0x2c8 ),	/* Type Offset=712 */

	/* Parameter hrItem */


	/* Parameter hrItem */

/* 5682 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5684 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 5686 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pSessionTotals */


	/* Parameter pSessionTotals */

/* 5688 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5690 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 5692 */	NdrFcShort( 0x2da ),	/* Type Offset=730 */

	/* Return value */


	/* Return value */

/* 5694 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5696 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 5698 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ProcessSessionMediaState */

/* 5700 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5702 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5706 */	NdrFcShort( 0x3 ),	/* 3 */
/* 5708 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 5710 */	NdrFcShort( 0x18 ),	/* 24 */
/* 5712 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5714 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x7,		/* 7 */
/* 5716 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5718 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5720 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5722 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5724 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSession */

/* 5726 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5728 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5730 */	NdrFcShort( 0x1f4 ),	/* Type Offset=500 */

	/* Parameter pPhase */

/* 5732 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5734 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5736 */	NdrFcShort( 0x20a ),	/* Type Offset=522 */

	/* Parameter state */

/* 5738 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5740 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5742 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter mediaName */

/* 5744 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 5746 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 5748 */	NdrFcShort( 0x6a ),	/* Type Offset=106 */

	/* Parameter mediaType */

/* 5750 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5752 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 5754 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter time */

/* 5756 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5758 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 5760 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5762 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5764 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 5766 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ProcessSessionPriority */

/* 5768 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5770 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5774 */	NdrFcShort( 0x3 ),	/* 3 */
/* 5776 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 5778 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5780 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5782 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 5784 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5786 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5788 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5790 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5792 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSession */

/* 5794 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5796 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5798 */	NdrFcShort( 0x1f4 ),	/* Type Offset=500 */

	/* Parameter pPhase */

/* 5800 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5802 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5804 */	NdrFcShort( 0x20a ),	/* Type Offset=522 */

	/* Return value */

/* 5806 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5808 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5810 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ProcessSessionState */

/* 5812 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5814 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5818 */	NdrFcShort( 0x3 ),	/* 3 */
/* 5820 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 5822 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5824 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5826 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 5828 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5830 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5832 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5834 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5836 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSession */

/* 5838 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5840 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5842 */	NdrFcShort( 0x1f4 ),	/* Type Offset=500 */

	/* Parameter pPhase */

/* 5844 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5846 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5848 */	NdrFcShort( 0x20a ),	/* Type Offset=522 */

	/* Parameter currentPath */

/* 5850 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 5852 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5854 */	NdrFcShort( 0x6a ),	/* Type Offset=106 */

	/* Return value */

/* 5856 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5858 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 5860 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Clone */

/* 5862 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5864 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5868 */	NdrFcShort( 0x3 ),	/* 3 */
/* 5870 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5872 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5874 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5876 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 5878 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5880 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5882 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5884 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5886 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppSessionTotals */

/* 5888 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 5890 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5892 */	NdrFcShort( 0x2ec ),	/* Type Offset=748 */

	/* Return value */

/* 5894 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5896 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5898 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CopyTo */

/* 5900 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5902 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5906 */	NdrFcShort( 0x4 ),	/* 4 */
/* 5908 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5910 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5912 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5914 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 5916 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5918 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5920 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5922 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5924 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSessionTotals */

/* 5926 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5928 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5930 */	NdrFcShort( 0x2da ),	/* Type Offset=730 */

	/* Return value */

/* 5932 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5934 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5936 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToAction */

/* 5938 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5940 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5944 */	NdrFcShort( 0x5 ),	/* 5 */
/* 5946 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 5948 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5950 */	NdrFcShort( 0x22 ),	/* 34 */
/* 5952 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 5954 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5956 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5958 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5960 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5962 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter action */

/* 5964 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5966 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5968 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Parameter pResult */

/* 5970 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5972 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5974 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 5976 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5978 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5980 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToISessionTotals */

/* 5982 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5984 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5988 */	NdrFcShort( 0x6 ),	/* 6 */
/* 5990 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 5992 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5994 */	NdrFcShort( 0x22 ),	/* 34 */
/* 5996 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 5998 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6000 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6002 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6004 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6006 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pTotals */

/* 6008 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 6010 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 6012 */	NdrFcShort( 0x2da ),	/* Type Offset=730 */

	/* Parameter pResult */

/* 6014 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 6016 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 6018 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 6020 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6022 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 6024 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetStats */

/* 6026 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 6028 */	NdrFcLong( 0x0 ),	/* 0 */
/* 6032 */	NdrFcShort( 0x9 ),	/* 9 */
/* 6034 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 6036 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6038 */	NdrFcShort( 0xe0 ),	/* 224 */
/* 6040 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x7,		/* 7 */
/* 6042 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 6044 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6046 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6048 */	NdrFcShort( 0x0 ),	/* 0 */
/* 6050 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter items */

/* 6052 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 6054 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 6056 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter size */

/* 6058 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 6060 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 6062 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter skippedItems */

/* 6064 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 6066 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 6068 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter skippedSize */

/* 6070 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 6072 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 6074 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter errorItems */

/* 6076 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 6078 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 6080 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter errorSize */

/* 6082 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 6084 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 6086 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 6088 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 6090 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 6092 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/*  4 */	NdrFcShort( 0x2 ),	/* Offset= 2 (6) */
/*  6 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/*  8 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 10 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 12 */	NdrFcLong( 0x87e7ed0 ),	/* 142507728 */
/* 16 */	NdrFcShort( 0x727a ),	/* 29306 */
/* 18 */	NdrFcShort( 0x11d2 ),	/* 4562 */
/* 20 */	0x9c,		/* 156 */
			0xd3,		/* 211 */
/* 22 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 24 */	0xc9,		/* 201 */
			0x11,		/* 17 */
/* 26 */	0x81,		/* 129 */
			0x2,		/* 2 */
/* 28 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 30 */	NdrFcLong( 0xb8e1cd20 ),	/* -1193161440 */
/* 34 */	NdrFcShort( 0x81d3 ),	/* -32301 */
/* 36 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 38 */	0x81,		/* 129 */
			0xe4,		/* 228 */
/* 40 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 42 */	0xc9,		/* 201 */
			0x11,		/* 17 */
/* 44 */	0x80,		/* 128 */
			0xf2,		/* 242 */
/* 46 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 48 */	NdrFcLong( 0x2fa5166a ),	/* 799348330 */
/* 52 */	NdrFcShort( 0xd28b ),	/* -11637 */
/* 54 */	NdrFcShort( 0x49d4 ),	/* 18900 */
/* 56 */	0xb5,		/* 181 */
			0xf8,		/* 248 */
/* 58 */	0xb1,		/* 177 */
			0x2b,		/* 43 */
/* 60 */	0x32,		/* 50 */
			0x1,		/* 1 */
/* 62 */	0xc1,		/* 193 */
			0xc4,		/* 196 */
/* 64 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 66 */	NdrFcLong( 0x172f71cd ),	/* 388985293 */
/* 70 */	NdrFcShort( 0xa452 ),	/* -23470 */
/* 72 */	NdrFcShort( 0x4005 ),	/* 16389 */
/* 74 */	0x8e,		/* 142 */
			0x3e,		/* 62 */
/* 76 */	0x7b,		/* 123 */
			0xce,		/* 206 */
/* 78 */	0xae,		/* 174 */
			0x12,		/* 18 */
/* 80 */	0x4d,		/* 77 */
			0x53,		/* 83 */
/* 82 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 84 */	NdrFcLong( 0x6e7196dc ),	/* 1852937948 */
/* 88 */	NdrFcShort( 0x7f9c ),	/* 32668 */
/* 90 */	NdrFcShort( 0x460d ),	/* 17933 */
/* 92 */	0x9e,		/* 158 */
			0x97,		/* 151 */
/* 94 */	0x84,		/* 132 */
			0x54,		/* 84 */
/* 96 */	0x90,		/* 144 */
			0xb8,		/* 184 */
/* 98 */	0x1d,		/* 29 */
			0x60,		/* 96 */
/* 100 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 102 */	0xe,		/* FC_ENUM32 */
			0x5c,		/* FC_PAD */
/* 104 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 106 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 108 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 110 */	NdrFcShort( 0x8 ),	/* Offset= 8 (118) */
/* 112 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 114 */	NdrFcShort( 0x8 ),	/* 8 */
/* 116 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 118 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 120 */	NdrFcShort( 0x10 ),	/* 16 */
/* 122 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 124 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 126 */	0x0,		/* 0 */
			NdrFcShort( 0xfff1 ),	/* Offset= -15 (112) */
			0x5b,		/* FC_END */
/* 130 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 132 */	NdrFcShort( 0x2 ),	/* Offset= 2 (134) */
/* 134 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 136 */	NdrFcLong( 0x9c7d6f14 ),	/* -1669501164 */
/* 140 */	NdrFcShort( 0x1562 ),	/* 5474 */
/* 142 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 144 */	0x81,		/* 129 */
			0xac,		/* 172 */
/* 146 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 148 */	0xc9,		/* 201 */
			0x11,		/* 17 */
/* 150 */	0x80,		/* 128 */
			0xf2,		/* 242 */
/* 152 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 154 */	NdrFcLong( 0x6e7196dc ),	/* 1852937948 */
/* 158 */	NdrFcShort( 0x7f9c ),	/* 32668 */
/* 160 */	NdrFcShort( 0x460d ),	/* 17933 */
/* 162 */	0x9e,		/* 158 */
			0x97,		/* 151 */
/* 164 */	0x84,		/* 132 */
			0x54,		/* 84 */
/* 166 */	0x90,		/* 144 */
			0xb8,		/* 184 */
/* 168 */	0x1d,		/* 29 */
			0x60,		/* 96 */
/* 170 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 172 */	NdrFcShort( 0xff70 ),	/* Offset= -144 (28) */
/* 174 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 176 */	NdrFcShort( 0x2 ),	/* Offset= 2 (178) */
/* 178 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 180 */	NdrFcLong( 0xad402360 ),	/* -1388305568 */
/* 184 */	NdrFcShort( 0xfc ),	/* 252 */
/* 186 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 188 */	0x81,		/* 129 */
			0x9c,		/* 156 */
/* 190 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 192 */	0xc9,		/* 201 */
			0x11,		/* 17 */
/* 194 */	0x80,		/* 128 */
			0xf2,		/* 242 */
/* 196 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 198 */	NdrFcShort( 0x2 ),	/* Offset= 2 (200) */
/* 200 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 202 */	NdrFcLong( 0x2fa5166a ),	/* 799348330 */
/* 206 */	NdrFcShort( 0xd28b ),	/* -11637 */
/* 208 */	NdrFcShort( 0x49d4 ),	/* 18900 */
/* 210 */	0xb5,		/* 181 */
			0xf8,		/* 248 */
/* 212 */	0xb1,		/* 177 */
			0x2b,		/* 43 */
/* 214 */	0x32,		/* 50 */
			0x1,		/* 1 */
/* 216 */	0xc1,		/* 193 */
			0xc4,		/* 196 */
/* 218 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 220 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 222 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 224 */	NdrFcLong( 0xe372f85b ),	/* -479004581 */
/* 228 */	NdrFcShort( 0xd72b ),	/* -10453 */
/* 230 */	NdrFcShort( 0x4a7d ),	/* 19069 */
/* 232 */	0xb0,		/* 176 */
			0xf6,		/* 246 */
/* 234 */	0x2b,		/* 43 */
			0xcf,		/* 207 */
/* 236 */	0x8f,		/* 143 */
			0xed,		/* 237 */
/* 238 */	0x88,		/* 136 */
			0xb9,		/* 185 */
/* 240 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 242 */	NdrFcLong( 0x172f71cd ),	/* 388985293 */
/* 246 */	NdrFcShort( 0xa452 ),	/* -23470 */
/* 248 */	NdrFcShort( 0x4005 ),	/* 16389 */
/* 250 */	0x8e,		/* 142 */
			0x3e,		/* 62 */
/* 252 */	0x7b,		/* 123 */
			0xce,		/* 206 */
/* 254 */	0xae,		/* 174 */
			0x12,		/* 18 */
/* 256 */	0x4d,		/* 77 */
			0x53,		/* 83 */
/* 258 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 260 */	NdrFcLong( 0xad402360 ),	/* -1388305568 */
/* 264 */	NdrFcShort( 0xfc ),	/* 252 */
/* 266 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 268 */	0x81,		/* 129 */
			0x9c,		/* 156 */
/* 270 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 272 */	0xc9,		/* 201 */
			0x11,		/* 17 */
/* 274 */	0x80,		/* 128 */
			0xf2,		/* 242 */
/* 276 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 278 */	NdrFcLong( 0x2fa5166a ),	/* 799348330 */
/* 282 */	NdrFcShort( 0xd28b ),	/* -11637 */
/* 284 */	NdrFcShort( 0x49d4 ),	/* 18900 */
/* 286 */	0xb5,		/* 181 */
			0xf8,		/* 248 */
/* 288 */	0xb1,		/* 177 */
			0x2b,		/* 43 */
/* 290 */	0x32,		/* 50 */
			0x1,		/* 1 */
/* 292 */	0xc1,		/* 193 */
			0xc4,		/* 196 */
/* 294 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 296 */	NdrFcShort( 0x2 ),	/* Offset= 2 (298) */
/* 298 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 300 */	NdrFcLong( 0x9c7d6f14 ),	/* -1669501164 */
/* 304 */	NdrFcShort( 0x1562 ),	/* 5474 */
/* 306 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 308 */	0x81,		/* 129 */
			0xac,		/* 172 */
/* 310 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 312 */	0xc9,		/* 201 */
			0x11,		/* 17 */
/* 314 */	0x80,		/* 128 */
			0xf2,		/* 242 */
/* 316 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 318 */	NdrFcShort( 0x2 ),	/* Offset= 2 (320) */
/* 320 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 322 */	NdrFcLong( 0x9c7d6f0f ),	/* -1669501169 */
/* 326 */	NdrFcShort( 0x1562 ),	/* 5474 */
/* 328 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 330 */	0x81,		/* 129 */
			0xac,		/* 172 */
/* 332 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 334 */	0xc9,		/* 201 */
			0x11,		/* 17 */
/* 336 */	0x80,		/* 128 */
			0xf2,		/* 242 */
/* 338 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 340 */	NdrFcShort( 0x2 ),	/* Offset= 2 (342) */
/* 342 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 344 */	NdrFcLong( 0xad613d1 ),	/* 181801937 */
/* 348 */	NdrFcShort( 0x18be ),	/* 6334 */
/* 350 */	NdrFcShort( 0x11d1 ),	/* 4561 */
/* 352 */	0x99,		/* 153 */
			0x39,		/* 57 */
/* 354 */	0x0,		/* 0 */
			0x60,		/* 96 */
/* 356 */	0x97,		/* 151 */
			0x6a,		/* 106 */
/* 358 */	0x54,		/* 84 */
			0x6d,		/* 109 */
/* 360 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 362 */	NdrFcShort( 0x2 ),	/* Offset= 2 (364) */
/* 364 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 366 */	NdrFcLong( 0xfd8d709c ),	/* -41062244 */
/* 370 */	NdrFcShort( 0x47dd ),	/* 18397 */
/* 372 */	NdrFcShort( 0x4d68 ),	/* 19816 */
/* 374 */	0xbb,		/* 187 */
			0xd5,		/* 213 */
/* 376 */	0x81,		/* 129 */
			0x7e,		/* 126 */
/* 378 */	0xdd,		/* 221 */
			0x93,		/* 147 */
/* 380 */	0x4e,		/* 78 */
			0x4b,		/* 75 */
/* 382 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 384 */	NdrFcShort( 0x2 ),	/* Offset= 2 (386) */
/* 386 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 388 */	NdrFcLong( 0xd7619db3 ),	/* -681468493 */
/* 392 */	NdrFcShort( 0x265e ),	/* 9822 */
/* 394 */	NdrFcShort( 0x4796 ),	/* 18326 */
/* 396 */	0xa9,		/* 169 */
			0x8c,		/* 140 */
/* 398 */	0xf6,		/* 246 */
			0xf2,		/* 242 */
/* 400 */	0x8c,		/* 140 */
			0x2a,		/* 42 */
/* 402 */	0x61,		/* 97 */
			0x8c,		/* 140 */
/* 404 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 406 */	NdrFcLong( 0x6e7196dc ),	/* 1852937948 */
/* 410 */	NdrFcShort( 0x7f9c ),	/* 32668 */
/* 412 */	NdrFcShort( 0x460d ),	/* 17933 */
/* 414 */	0x9e,		/* 158 */
			0x97,		/* 151 */
/* 416 */	0x84,		/* 132 */
			0x54,		/* 84 */
/* 418 */	0x90,		/* 144 */
			0xb8,		/* 184 */
/* 420 */	0x1d,		/* 29 */
			0x60,		/* 96 */
/* 422 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 424 */	NdrFcLong( 0x35035914 ),	/* 889411860 */
/* 428 */	NdrFcShort( 0xd1c ),	/* 3356 */
/* 430 */	NdrFcShort( 0x11d2 ),	/* 4562 */
/* 432 */	0x9b,		/* 155 */
			0xc,		/* 12 */
/* 434 */	0x0,		/* 0 */
			0x10,		/* 16 */
/* 436 */	0x4b,		/* 75 */
			0x9a,		/* 154 */
/* 438 */	0x28,		/* 40 */
			0x69,		/* 105 */
/* 440 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 442 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 444 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 446 */	NdrFcLong( 0xb8e1cd20 ),	/* -1193161440 */
/* 450 */	NdrFcShort( 0x81d3 ),	/* -32301 */
/* 452 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 454 */	0x81,		/* 129 */
			0xe4,		/* 228 */
/* 456 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 458 */	0xc9,		/* 201 */
			0x11,		/* 17 */
/* 460 */	0x80,		/* 128 */
			0xf2,		/* 242 */
/* 462 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 464 */	NdrFcShort( 0x2 ),	/* Offset= 2 (466) */
/* 466 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 468 */	NdrFcLong( 0x9c7d6f14 ),	/* -1669501164 */
/* 472 */	NdrFcShort( 0x1562 ),	/* 5474 */
/* 474 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 476 */	0x81,		/* 129 */
			0xac,		/* 172 */
/* 478 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 480 */	0xc9,		/* 201 */
			0x11,		/* 17 */
/* 482 */	0x80,		/* 128 */
			0xf2,		/* 242 */
/* 484 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 486 */	NdrFcShort( 0x2 ),	/* Offset= 2 (488) */
/* 488 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 490 */	NdrFcShort( 0x8 ),	/* 8 */
/* 492 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 494 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 496 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 498 */	NdrFcShort( 0x2 ),	/* Offset= 2 (500) */
/* 500 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 502 */	NdrFcLong( 0x6e7196dc ),	/* 1852937948 */
/* 506 */	NdrFcShort( 0x7f9c ),	/* 32668 */
/* 508 */	NdrFcShort( 0x460d ),	/* 17933 */
/* 510 */	0x9e,		/* 158 */
			0x97,		/* 151 */
/* 512 */	0x84,		/* 132 */
			0x54,		/* 84 */
/* 514 */	0x90,		/* 144 */
			0xb8,		/* 184 */
/* 516 */	0x1d,		/* 29 */
			0x60,		/* 96 */
/* 518 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 520 */	NdrFcShort( 0x2 ),	/* Offset= 2 (522) */
/* 522 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 524 */	NdrFcLong( 0x35035914 ),	/* 889411860 */
/* 528 */	NdrFcShort( 0xd1c ),	/* 3356 */
/* 530 */	NdrFcShort( 0x11d2 ),	/* 4562 */
/* 532 */	0x9b,		/* 155 */
			0xc,		/* 12 */
/* 534 */	0x0,		/* 0 */
			0x10,		/* 16 */
/* 536 */	0x4b,		/* 75 */
			0x9a,		/* 154 */
/* 538 */	0x28,		/* 40 */
			0x69,		/* 105 */
/* 540 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 542 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */
/* 544 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 546 */	NdrFcShort( 0x2 ),	/* Offset= 2 (548) */
/* 548 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 550 */	NdrFcLong( 0xad402351 ),	/* -1388305583 */
/* 554 */	NdrFcShort( 0xfc ),	/* 252 */
/* 556 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 558 */	0x81,		/* 129 */
			0x9c,		/* 156 */
/* 560 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 562 */	0xc9,		/* 201 */
			0x11,		/* 17 */
/* 564 */	0x80,		/* 128 */
			0xf2,		/* 242 */
/* 566 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 568 */	NdrFcShort( 0x2 ),	/* Offset= 2 (570) */
/* 570 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 572 */	NdrFcLong( 0x9c7d6f0f ),	/* -1669501169 */
/* 576 */	NdrFcShort( 0x1562 ),	/* 5474 */
/* 578 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 580 */	0x81,		/* 129 */
			0xac,		/* 172 */
/* 582 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 584 */	0xc9,		/* 201 */
			0x11,		/* 17 */
/* 586 */	0x80,		/* 128 */
			0xf2,		/* 242 */
/* 588 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 590 */	NdrFcLong( 0xad402356 ),	/* -1388305578 */
/* 594 */	NdrFcShort( 0xfc ),	/* 252 */
/* 596 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 598 */	0x81,		/* 129 */
			0x9c,		/* 156 */
/* 600 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 602 */	0xc9,		/* 201 */
			0x11,		/* 17 */
/* 604 */	0x80,		/* 128 */
			0xf2,		/* 242 */
/* 606 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 608 */	NdrFcLong( 0x87e7ed0 ),	/* 142507728 */
/* 612 */	NdrFcShort( 0x727a ),	/* 29306 */
/* 614 */	NdrFcShort( 0x11d2 ),	/* 4562 */
/* 616 */	0x9c,		/* 156 */
			0xd3,		/* 211 */
/* 618 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 620 */	0xc9,		/* 201 */
			0x11,		/* 17 */
/* 622 */	0x81,		/* 129 */
			0x2,		/* 2 */
/* 624 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 626 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 628 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 630 */	NdrFcLong( 0xad40234c ),	/* -1388305588 */
/* 634 */	NdrFcShort( 0xfc ),	/* 252 */
/* 636 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 638 */	0x81,		/* 129 */
			0x9c,		/* 156 */
/* 640 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 642 */	0xc9,		/* 201 */
			0x11,		/* 17 */
/* 644 */	0x80,		/* 128 */
			0xf2,		/* 242 */
/* 646 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 648 */	NdrFcLong( 0x172f71cd ),	/* 388985293 */
/* 652 */	NdrFcShort( 0xa452 ),	/* -23470 */
/* 654 */	NdrFcShort( 0x4005 ),	/* 16389 */
/* 656 */	0x8e,		/* 142 */
			0x3e,		/* 62 */
/* 658 */	0x7b,		/* 123 */
			0xce,		/* 206 */
/* 660 */	0xae,		/* 174 */
			0x12,		/* 18 */
/* 662 */	0x4d,		/* 77 */
			0x53,		/* 83 */
/* 664 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 666 */	NdrFcShort( 0x2 ),	/* Offset= 2 (668) */
/* 668 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 670 */	NdrFcLong( 0x2a87c7e2 ),	/* 713541602 */
/* 674 */	NdrFcShort( 0xdb24 ),	/* -9436 */
/* 676 */	NdrFcShort( 0x11d2 ),	/* 4562 */
/* 678 */	0xaf,		/* 175 */
			0xa2,		/* 162 */
/* 680 */	0x0,		/* 0 */
			0x10,		/* 16 */
/* 682 */	0x4b,		/* 75 */
			0x9a,		/* 154 */
/* 684 */	0x37,		/* 55 */
			0x58,		/* 88 */
/* 686 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 688 */	NdrFcShort( 0x2 ),	/* Offset= 2 (690) */
/* 690 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 692 */	NdrFcLong( 0x172f71cd ),	/* 388985293 */
/* 696 */	NdrFcShort( 0xa452 ),	/* -23470 */
/* 698 */	NdrFcShort( 0x4005 ),	/* 16389 */
/* 700 */	0x8e,		/* 142 */
			0x3e,		/* 62 */
/* 702 */	0x7b,		/* 123 */
			0xce,		/* 206 */
/* 704 */	0xae,		/* 174 */
			0x12,		/* 18 */
/* 706 */	0x4d,		/* 77 */
			0x53,		/* 83 */
/* 708 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 710 */	
			0x22,		/* FC_C_CSTRING */
			0x5c,		/* FC_PAD */
/* 712 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 714 */	NdrFcLong( 0x87e7ed0 ),	/* 142507728 */
/* 718 */	NdrFcShort( 0x727a ),	/* 29306 */
/* 720 */	NdrFcShort( 0x11d2 ),	/* 4562 */
/* 722 */	0x9c,		/* 156 */
			0xd3,		/* 211 */
/* 724 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 726 */	0xc9,		/* 201 */
			0x11,		/* 17 */
/* 728 */	0x81,		/* 129 */
			0x2,		/* 2 */
/* 730 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 732 */	NdrFcLong( 0x35035913 ),	/* 889411859 */
/* 736 */	NdrFcShort( 0xd1c ),	/* 3356 */
/* 738 */	NdrFcShort( 0x11d2 ),	/* 4562 */
/* 740 */	0x9b,		/* 155 */
			0xc,		/* 12 */
/* 742 */	0x0,		/* 0 */
			0x10,		/* 16 */
/* 744 */	0x4b,		/* 75 */
			0x9a,		/* 154 */
/* 746 */	0x28,		/* 40 */
			0x69,		/* 105 */
/* 748 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 750 */	NdrFcShort( 0xffec ),	/* Offset= -20 (730) */

			0x0
        }
    };


/* Standard interface: __MIDL_itf_jobint_0000, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IHsmAction, ver. 0.0,
   GUID={0xAD402351,0x00FC,0x11D0,{0x81,0x9C,0x00,0xA0,0xC9,0x11,0x80,0xF2}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmAction_FormatStringOffsetTable[] =
    {
    0,
    44
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmAction_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmAction_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmAction_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmAction_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(5) _IHsmActionProxyVtbl = 
{
    &IHsmAction_ProxyInfo,
    &IID_IHsmAction,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmAction::GetName */ ,
    (void *) (INT_PTR) -1 /* IHsmAction::Do */
};

const CInterfaceStubVtbl _IHsmActionStubVtbl =
{
    &IID_IHsmAction,
    &IHsmAction_ServerInfo,
    5,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmActionOnResource, ver. 0.0,
   GUID={0xD9E04213,0x14D7,0x11d1,{0x99,0x38,0x00,0x60,0x97,0x6A,0x54,0x6D}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmActionOnResource_FormatStringOffsetTable[] =
    {
    0
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmActionOnResource_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmActionOnResource_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmActionOnResource_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmActionOnResource_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IHsmActionOnResourceProxyVtbl = 
{
    &IHsmActionOnResource_ProxyInfo,
    &IID_IHsmActionOnResource,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmActionOnResource::GetName */
};

const CInterfaceStubVtbl _IHsmActionOnResourceStubVtbl =
{
    &IID_IHsmActionOnResource,
    &IHsmActionOnResource_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmActionOnResourcePost, ver. 0.0,
   GUID={0x0AD613D1,0x18BE,0x11d1,{0x99,0x39,0x00,0x60,0x97,0x6A,0x54,0x6D}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmActionOnResourcePost_FormatStringOffsetTable[] =
    {
    82
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmActionOnResourcePost_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmActionOnResourcePost_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmActionOnResourcePost_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmActionOnResourcePost_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IHsmActionOnResourcePostProxyVtbl = 
{
    &IHsmActionOnResourcePost_ProxyInfo,
    &IID_IHsmActionOnResourcePost,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmActionOnResourcePost::Do */
};

const CInterfaceStubVtbl _IHsmActionOnResourcePostStubVtbl =
{
    &IID_IHsmActionOnResourcePost,
    &IHsmActionOnResourcePost_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmActionOnResourcePre, ver. 0.0,
   GUID={0xFD8D709C,0x47DD,0x4D68,{0xBB,0xD5,0x81,0x7E,0xDD,0x93,0x4E,0x4B}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmActionOnResourcePre_FormatStringOffsetTable[] =
    {
    126
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmActionOnResourcePre_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmActionOnResourcePre_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmActionOnResourcePre_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmActionOnResourcePre_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IHsmActionOnResourcePreProxyVtbl = 
{
    &IHsmActionOnResourcePre_ProxyInfo,
    &IID_IHsmActionOnResourcePre,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmActionOnResourcePre::Do */
};

const CInterfaceStubVtbl _IHsmActionOnResourcePreStubVtbl =
{
    &IID_IHsmActionOnResourcePre,
    &IHsmActionOnResourcePre_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmActionOnResourcePreScan, ver. 0.0,
   GUID={0xD7619DB3,0x265E,0x4796,{0xA9,0x8C,0xF6,0xF2,0x8C,0x2A,0x61,0x8C}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmActionOnResourcePreScan_FormatStringOffsetTable[] =
    {
    170
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmActionOnResourcePreScan_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmActionOnResourcePreScan_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmActionOnResourcePreScan_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmActionOnResourcePreScan_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IHsmActionOnResourcePreScanProxyVtbl = 
{
    &IHsmActionOnResourcePreScan_ProxyInfo,
    &IID_IHsmActionOnResourcePreScan,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmActionOnResourcePreScan::Do */
};

const CInterfaceStubVtbl _IHsmActionOnResourcePreScanStubVtbl =
{
    &IID_IHsmActionOnResourcePreScan,
    &IHsmActionOnResourcePreScan_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmCriteria, ver. 0.0,
   GUID={0xAD40235B,0x00FC,0x11D0,{0x81,0x9C,0x00,0xA0,0xC9,0x11,0x80,0xF2}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmCriteria_FormatStringOffsetTable[] =
    {
    0,
    214,
    246,
    278,
    316,
    354,
    398
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmCriteria_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmCriteria_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmCriteria_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmCriteria_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(10) _IHsmCriteriaProxyVtbl = 
{
    &IHsmCriteria_ProxyInfo,
    &IID_IHsmCriteria,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmCriteria::GetName */ ,
    (void *) (INT_PTR) -1 /* IHsmCriteria::IsIgnored */ ,
    (void *) (INT_PTR) -1 /* IHsmCriteria::IsNegated */ ,
    (void *) (INT_PTR) -1 /* IHsmCriteria::SetIsIgnored */ ,
    (void *) (INT_PTR) -1 /* IHsmCriteria::SetIsNegated */ ,
    (void *) (INT_PTR) -1 /* IHsmCriteria::ShouldDo */ ,
    (void *) (INT_PTR) -1 /* IHsmCriteria::Value */
};

const CInterfaceStubVtbl _IHsmCriteriaStubVtbl =
{
    &IID_IHsmCriteria,
    &IHsmCriteria_ServerInfo,
    10,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmRelativeCriteria, ver. 0.0,
   GUID={0x2B382EA1,0x16EA,0x11D0,{0x81,0xAE,0x00,0xA0,0xC9,0x11,0x80,0xF2}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmRelativeCriteria_FormatStringOffsetTable[] =
    {
    0,
    214,
    448,
    492,
    536,
    574,
    612,
    650
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmRelativeCriteria_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmRelativeCriteria_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmRelativeCriteria_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmRelativeCriteria_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(11) _IHsmRelativeCriteriaProxyVtbl = 
{
    &IHsmRelativeCriteria_ProxyInfo,
    &IID_IHsmRelativeCriteria,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmRelativeCriteria::ComparatorAsString */ ,
    (void *) (INT_PTR) -1 /* IHsmRelativeCriteria::ComparatorIsBinary */ ,
    (void *) (INT_PTR) -1 /* IHsmRelativeCriteria::GetArg1 */ ,
    (void *) (INT_PTR) -1 /* IHsmRelativeCriteria::GetArg2 */ ,
    (void *) (INT_PTR) -1 /* IHsmRelativeCriteria::GetComparator */ ,
    (void *) (INT_PTR) -1 /* IHsmRelativeCriteria::SetArg1 */ ,
    (void *) (INT_PTR) -1 /* IHsmRelativeCriteria::SetArg2 */ ,
    (void *) (INT_PTR) -1 /* IHsmRelativeCriteria::SetComparator */
};

const CInterfaceStubVtbl _IHsmRelativeCriteriaStubVtbl =
{
    &IID_IHsmRelativeCriteria,
    &IHsmRelativeCriteria_ServerInfo,
    11,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmDirectedAction, ver. 0.0,
   GUID={0xC7A01572,0x187A,0x11D0,{0x81,0xB0,0x00,0xA0,0xC9,0x11,0x80,0xF2}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmDirectedAction_FormatStringOffsetTable[] =
    {
    688,
    726
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmDirectedAction_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmDirectedAction_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmDirectedAction_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmDirectedAction_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(5) _IHsmDirectedActionProxyVtbl = 
{
    &IHsmDirectedAction_ProxyInfo,
    &IID_IHsmDirectedAction,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmDirectedAction::GetStoragePoolId */ ,
    (void *) (INT_PTR) -1 /* IHsmDirectedAction::SetStoragePoolId */
};

const CInterfaceStubVtbl _IHsmDirectedActionStubVtbl =
{
    &IID_IHsmDirectedAction,
    &IHsmDirectedAction_ServerInfo,
    5,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmJob, ver. 0.0,
   GUID={0x2A87C7E2,0xDB24,0x11d2,{0xAF,0xA2,0x00,0x10,0x4B,0x9A,0x37,0x58}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmJob_FormatStringOffsetTable[] =
    {
    764,
    214,
    246,
    802,
    840,
    884,
    922,
    960,
    998,
    1036,
    1074,
    1118,
    1156,
    1194,
    1268,
    1300,
    1332,
    1370,
    1402,
    1440,
    1478,
    1516,
    1554,
    1592,
    1630,
    1662,
    1700
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmJob_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmJob_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmJob_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmJob_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(30) _IHsmJobProxyVtbl = 
{
    &IHsmJob_ProxyInfo,
    &IID_IHsmJob,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmJob::Cancel */ ,
    (void *) (INT_PTR) -1 /* IHsmJob::DidFinish */ ,
    (void *) (INT_PTR) -1 /* IHsmJob::DidFinishOk */ ,
    (void *) (INT_PTR) -1 /* IHsmJob::EnumWorkItems */ ,
    (void *) (INT_PTR) -1 /* IHsmJob::FindWorkItem */ ,
    (void *) (INT_PTR) -1 /* IHsmJob::GetContext */ ,
    (void *) (INT_PTR) -1 /* IHsmJob::GetDef */ ,
    (void *) (INT_PTR) -1 /* IHsmJob::GetHsmId */ ,
    (void *) (INT_PTR) -1 /* IHsmJob::GetIdentifier */ ,
    (void *) (INT_PTR) -1 /* IHsmJob::GetMaxActiveSessions */ ,
    (void *) (INT_PTR) -1 /* IHsmJob::GetName */ ,
    (void *) (INT_PTR) -1 /* IHsmJob::GetRunId */ ,
    (void *) (INT_PTR) -1 /* IHsmJob::GetState */ ,
    (void *) (INT_PTR) -1 /* IHsmJob::InitAs */ ,
    (void *) (INT_PTR) -1 /* IHsmJob::IsActive */ ,
    (void *) (INT_PTR) -1 /* IHsmJob::IsUserDefined */ ,
    (void *) (INT_PTR) -1 /* IHsmJob::Pause */ ,
    (void *) (INT_PTR) -1 /* IHsmJob::Restart */ ,
    (void *) (INT_PTR) -1 /* IHsmJob::Resume */ ,
    (void *) (INT_PTR) -1 /* IHsmJob::SetContext */ ,
    (void *) (INT_PTR) -1 /* IHsmJob::SetDef */ ,
    (void *) (INT_PTR) -1 /* IHsmJob::SetHsmId */ ,
    (void *) (INT_PTR) -1 /* IHsmJob::SetIsUserDefined */ ,
    (void *) (INT_PTR) -1 /* IHsmJob::SetName */ ,
    (void *) (INT_PTR) -1 /* IHsmJob::Start */ ,
    (void *) (INT_PTR) -1 /* IHsmJob::Suspend */ ,
    (void *) (INT_PTR) -1 /* IHsmJob::WaitUntilDone */
};

const CInterfaceStubVtbl _IHsmJobStubVtbl =
{
    &IID_IHsmJob,
    &IHsmJob_ServerInfo,
    30,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmJobContext, ver. 0.0,
   GUID={0xAD402360,0x00FC,0x11D0,{0x81,0x9C,0x00,0xA0,0xC9,0x11,0x80,0xF2}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmJobContext_FormatStringOffsetTable[] =
    {
    1732,
    1770,
    1808,
    1846
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmJobContext_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmJobContext_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmJobContext_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmJobContext_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(7) _IHsmJobContextProxyVtbl = 
{
    &IHsmJobContext_ProxyInfo,
    &IID_IHsmJobContext,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmJobContext::EnumResources */ ,
    (void *) (INT_PTR) -1 /* IHsmJobContext::Resources */ ,
    (void *) (INT_PTR) -1 /* IHsmJobContext::SetUsesAllManaged */ ,
    (void *) (INT_PTR) -1 /* IHsmJobContext::UsesAllManaged */
};

const CInterfaceStubVtbl _IHsmJobContextStubVtbl =
{
    &IID_IHsmJobContext,
    &IHsmJobContext_ServerInfo,
    7,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmJobDef, ver. 0.0,
   GUID={0x2FA5166A,0xD28B,0x49D4,{0xB5,0xF8,0xB1,0x2B,0x32,0x01,0xC1,0xC4}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmJobDef_FormatStringOffsetTable[] =
    {
    1732,
    1878,
    448,
    1916,
    1954,
    1992,
    2030,
    2092,
    2130,
    2168,
    2206,
    2244,
    2282,
    2320,
    2358,
    2396,
    2434,
    1370,
    2466,
    2498
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmJobDef_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmJobDef_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmJobDef_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmJobDef_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(23) _IHsmJobDefProxyVtbl = 
{
    &IHsmJobDef_ProxyInfo,
    &IID_IHsmJobDef,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmJobDef::EnumPolicies */ ,
    (void *) (INT_PTR) -1 /* IHsmJobDef::GetIdentifier */ ,
    (void *) (INT_PTR) -1 /* IHsmJobDef::GetName */ ,
    (void *) (INT_PTR) -1 /* IHsmJobDef::GetPostActionOnResource */ ,
    (void *) (INT_PTR) -1 /* IHsmJobDef::GetPreActionOnResource */ ,
    (void *) (INT_PTR) -1 /* IHsmJobDef::GetPreScanActionOnResource */ ,
    (void *) (INT_PTR) -1 /* IHsmJobDef::InitAs */ ,
    (void *) (INT_PTR) -1 /* IHsmJobDef::Policies */ ,
    (void *) (INT_PTR) -1 /* IHsmJobDef::SetName */ ,
    (void *) (INT_PTR) -1 /* IHsmJobDef::SetPostActionOnResource */ ,
    (void *) (INT_PTR) -1 /* IHsmJobDef::SetPreActionOnResource */ ,
    (void *) (INT_PTR) -1 /* IHsmJobDef::SetPreScanActionOnResource */ ,
    (void *) (INT_PTR) -1 /* IHsmJobDef::SetSkipHiddenItems */ ,
    (void *) (INT_PTR) -1 /* IHsmJobDef::SetSkipSystemItems */ ,
    (void *) (INT_PTR) -1 /* IHsmJobDef::SetUseRPIndex */ ,
    (void *) (INT_PTR) -1 /* IHsmJobDef::SetUseDbIndex */ ,
    (void *) (INT_PTR) -1 /* IHsmJobDef::SkipHiddenItems */ ,
    (void *) (INT_PTR) -1 /* IHsmJobDef::SkipSystemItems */ ,
    (void *) (INT_PTR) -1 /* IHsmJobDef::UseRPIndex */ ,
    (void *) (INT_PTR) -1 /* IHsmJobDef::UseDbIndex */
};

const CInterfaceStubVtbl _IHsmJobDefStubVtbl =
{
    &IID_IHsmJobDef,
    &IHsmJobDef_ServerInfo,
    23,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmJobSinkEverySession, ver. 0.0,
   GUID={0x4250BAA0,0x811D,0x11d0,{0x81,0xE4,0x00,0xA0,0xC9,0x11,0x80,0xF2}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmJobSinkEverySession_FormatStringOffsetTable[] =
    {
    2530
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmJobSinkEverySession_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmJobSinkEverySession_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmJobSinkEverySession_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmJobSinkEverySession_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IHsmJobSinkEverySessionProxyVtbl = 
{
    &IHsmJobSinkEverySession_ProxyInfo,
    &IID_IHsmJobSinkEverySession,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmJobSinkEverySession::ProcessJobSession */
};

const CInterfaceStubVtbl _IHsmJobSinkEverySessionStubVtbl =
{
    &IID_IHsmJobSinkEverySession,
    &IHsmJobSinkEverySession_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmJobWorkItem, ver. 0.0,
   GUID={0xB8E1CD20,0x81D3,0x11d0,{0x81,0xE4,0x00,0xA0,0xC9,0x11,0x80,0xF2}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmJobWorkItem_FormatStringOffsetTable[] =
    {
    2580,
    2624,
    246,
    1846,
    2668,
    2706,
    2744,
    2788,
    998,
    2826,
    1074,
    2864,
    1156,
    2902,
    2946
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmJobWorkItem_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmJobWorkItem_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmJobWorkItem_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmJobWorkItem_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(18) _IHsmJobWorkItemProxyVtbl = 
{
    &IHsmJobWorkItem_ProxyInfo,
    &IID_IHsmJobWorkItem,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmJobWorkItem::CompareToResourceId */ ,
    (void *) (INT_PTR) -1 /* IHsmJobWorkItem::CompareToIWorkItem */ ,
    (void *) (INT_PTR) -1 /* IHsmJobWorkItem::DoPostScan */ ,
    (void *) (INT_PTR) -1 /* IHsmJobWorkItem::DoPreScan */ ,
    (void *) (INT_PTR) -1 /* IHsmJobWorkItem::EnumPhases */ ,
    (void *) (INT_PTR) -1 /* IHsmJobWorkItem::EnumTotals */ ,
    (void *) (INT_PTR) -1 /* IHsmJobWorkItem::GetCurrentPath */ ,
    (void *) (INT_PTR) -1 /* IHsmJobWorkItem::GetFinishTime */ ,
    (void *) (INT_PTR) -1 /* IHsmJobWorkItem::GetResourceId */ ,
    (void *) (INT_PTR) -1 /* IHsmJobWorkItem::GetSession */ ,
    (void *) (INT_PTR) -1 /* IHsmJobWorkItem::GetStartingPath */ ,
    (void *) (INT_PTR) -1 /* IHsmJobWorkItem::GetStartTime */ ,
    (void *) (INT_PTR) -1 /* IHsmJobWorkItem::GetState */ ,
    (void *) (INT_PTR) -1 /* IHsmJobWorkItem::GetStateAsString */ ,
    (void *) (INT_PTR) -1 /* IHsmJobWorkItem::GetSubRunId */
};

const CInterfaceStubVtbl _IHsmJobWorkItemStubVtbl =
{
    &IID_IHsmJobWorkItem,
    &IHsmJobWorkItem_ServerInfo,
    18,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmPhase, ver. 0.0,
   GUID={0x35035914,0x0D1C,0x11d2,{0x9B,0x0C,0x00,0x10,0x4B,0x9A,0x28,0x69}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmPhase_FormatStringOffsetTable[] =
    {
    2984,
    3022,
    3060,
    3116,
    3154,
    3198,
    3242,
    3280,
    3318,
    3362,
    1074,
    3400,
    3468,
    3506
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmPhase_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmPhase_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmPhase_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmPhase_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(17) _IHsmPhaseProxyVtbl = 
{
    &IHsmPhase_ProxyInfo,
    &IID_IHsmPhase,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmPhase::Clone */ ,
    (void *) (INT_PTR) -1 /* IHsmPhase::CopyTo */ ,
    (void *) (INT_PTR) -1 /* IHsmPhase::GetElapsedTime */ ,
    (void *) (INT_PTR) -1 /* IHsmPhase::GetMediaState */ ,
    (void *) (INT_PTR) -1 /* IHsmPhase::GetMediaStateAsString */ ,
    (void *) (INT_PTR) -1 /* IHsmPhase::GetName */ ,
    (void *) (INT_PTR) -1 /* IHsmPhase::GetPhase */ ,
    (void *) (INT_PTR) -1 /* IHsmPhase::GetPriority */ ,
    (void *) (INT_PTR) -1 /* IHsmPhase::GetPriorityAsString */ ,
    (void *) (INT_PTR) -1 /* IHsmPhase::GetState */ ,
    (void *) (INT_PTR) -1 /* IHsmPhase::GetStateAsString */ ,
    (void *) (INT_PTR) -1 /* IHsmPhase::GetStats */ ,
    (void *) (INT_PTR) -1 /* IHsmPhase::GetStartTime */ ,
    (void *) (INT_PTR) -1 /* IHsmPhase::GetStopTime */
};

const CInterfaceStubVtbl _IHsmPhaseStubVtbl =
{
    &IID_IHsmPhase,
    &IHsmPhase_ServerInfo,
    17,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmPolicy, ver. 0.0,
   GUID={0xAD40234C,0x00FC,0x11D0,{0x81,0x9C,0x00,0xA0,0xC9,0x11,0x80,0xF2}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmPolicy_FormatStringOffsetTable[] =
    {
    3544,
    3582,
    3620,
    492,
    3658,
    3696,
    3734,
    3772,
    3810,
    3848,
    3886
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmPolicy_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmPolicy_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmPolicy_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmPolicy_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(14) _IHsmPolicyProxyVtbl = 
{
    &IHsmPolicy_ProxyInfo,
    &IID_IHsmPolicy,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmPolicy::EnumRules */ ,
    (void *) (INT_PTR) -1 /* IHsmPolicy::GetAction */ ,
    (void *) (INT_PTR) -1 /* IHsmPolicy::GetIdentifier */ ,
    (void *) (INT_PTR) -1 /* IHsmPolicy::GetName */ ,
    (void *) (INT_PTR) -1 /* IHsmPolicy::GetScale */ ,
    (void *) (INT_PTR) -1 /* IHsmPolicy::Rules */ ,
    (void *) (INT_PTR) -1 /* IHsmPolicy::SetAction */ ,
    (void *) (INT_PTR) -1 /* IHsmPolicy::SetName */ ,
    (void *) (INT_PTR) -1 /* IHsmPolicy::SetScale */ ,
    (void *) (INT_PTR) -1 /* IHsmPolicy::SetUsesDefaultRules */ ,
    (void *) (INT_PTR) -1 /* IHsmPolicy::UsesDefaultRules */
};

const CInterfaceStubVtbl _IHsmPolicyStubVtbl =
{
    &IID_IHsmPolicy,
    &IHsmPolicy_ServerInfo,
    14,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmRelocateAction, ver. 0.0,
   GUID={0xC7A01571,0x187A,0x11D0,{0x81,0xB0,0x00,0xA0,0xC9,0x11,0x80,0xF2}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmRelocateAction_FormatStringOffsetTable[] =
    {
    0,
    214,
    246,
    3918,
    316,
    3956
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmRelocateAction_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmRelocateAction_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmRelocateAction_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmRelocateAction_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(9) _IHsmRelocateActionProxyVtbl = 
{
    &IHsmRelocateAction_ProxyInfo,
    &IID_IHsmRelocateAction,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmRelocateAction::GetDestination */ ,
    (void *) (INT_PTR) -1 /* IHsmRelocateAction::ExpandPlaceholders */ ,
    (void *) (INT_PTR) -1 /* IHsmRelocateAction::RetainHierarchy */ ,
    (void *) (INT_PTR) -1 /* IHsmRelocateAction::SetDestination */ ,
    (void *) (INT_PTR) -1 /* IHsmRelocateAction::SetExpandPlaceholders */ ,
    (void *) (INT_PTR) -1 /* IHsmRelocateAction::SetRetainHierarchy */
};

const CInterfaceStubVtbl _IHsmRelocateActionStubVtbl =
{
    &IID_IHsmRelocateAction,
    &IHsmRelocateAction_ServerInfo,
    9,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmRule, ver. 0.0,
   GUID={0xAD402356,0x00FC,0x11D0,{0x81,0x9C,0x00,0xA0,0xC9,0x11,0x80,0xF2}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmRule_FormatStringOffsetTable[] =
    {
    3994,
    4038,
    4088,
    4126,
    3154,
    3198,
    2744,
    4164,
    4196,
    4228,
    4260,
    4298,
    2282,
    2320,
    4336,
    4374
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmRule_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmRule_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmRule_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmRule_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(19) _IHsmRuleProxyVtbl = 
{
    &IHsmRule_ProxyInfo,
    &IID_IHsmRule,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmRule::CompareToIRule */ ,
    (void *) (INT_PTR) -1 /* IHsmRule::CompareToPathAndName */ ,
    (void *) (INT_PTR) -1 /* IHsmRule::Criteria */ ,
    (void *) (INT_PTR) -1 /* IHsmRule::EnumCriteria */ ,
    (void *) (INT_PTR) -1 /* IHsmRule::GetName */ ,
    (void *) (INT_PTR) -1 /* IHsmRule::GetSearchName */ ,
    (void *) (INT_PTR) -1 /* IHsmRule::GetPath */ ,
    (void *) (INT_PTR) -1 /* IHsmRule::IsInclude */ ,
    (void *) (INT_PTR) -1 /* IHsmRule::IsUserDefined */ ,
    (void *) (INT_PTR) -1 /* IHsmRule::IsUsedInSubDirs */ ,
    (void *) (INT_PTR) -1 /* IHsmRule::MatchesName */ ,
    (void *) (INT_PTR) -1 /* IHsmRule::SetIsInclude */ ,
    (void *) (INT_PTR) -1 /* IHsmRule::SetIsUserDefined */ ,
    (void *) (INT_PTR) -1 /* IHsmRule::SetIsUsedInSubDirs */ ,
    (void *) (INT_PTR) -1 /* IHsmRule::SetName */ ,
    (void *) (INT_PTR) -1 /* IHsmRule::SetPath */
};

const CInterfaceStubVtbl _IHsmRuleStubVtbl =
{
    &IID_IHsmRule,
    &IHsmRule_ServerInfo,
    19,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmRuleStack, ver. 0.0,
   GUID={0x7B22FF21,0x1AD6,0x11D0,{0x81,0xB1,0x00,0xA0,0xC9,0x11,0x80,0xF2}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmRuleStack_FormatStringOffsetTable[] =
    {
    4412,
    4450,
    4494,
    3918,
    4538
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmRuleStack_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmRuleStack_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmRuleStack_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmRuleStack_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(8) _IHsmRuleStackProxyVtbl = 
{
    &IHsmRuleStack_ProxyInfo,
    &IID_IHsmRuleStack,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmRuleStack::Do */ ,
    (void *) (INT_PTR) -1 /* IHsmRuleStack::DoesMatch */ ,
    (void *) (INT_PTR) -1 /* IHsmRuleStack::Init */ ,
    (void *) (INT_PTR) -1 /* IHsmRuleStack::Pop */ ,
    (void *) (INT_PTR) -1 /* IHsmRuleStack::Push */
};

const CInterfaceStubVtbl _IHsmRuleStackStubVtbl =
{
    &IID_IHsmRuleStack,
    &IHsmRuleStack_ServerInfo,
    8,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmScanner, ver. 0.0,
   GUID={0xBEA60F83,0x7EBA,0x11d0,{0x81,0xE4,0x00,0xA0,0xC9,0x11,0x80,0xF2}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmScanner_FormatStringOffsetTable[] =
    {
    4576
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmScanner_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmScanner_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmScanner_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmScanner_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IHsmScannerProxyVtbl = 
{
    &IHsmScanner_ProxyInfo,
    &IID_IHsmScanner,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmScanner::Start */
};

const CInterfaceStubVtbl _IHsmScannerStubVtbl =
{
    &IID_IHsmScanner,
    &IHsmScanner_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmSession, ver. 0.0,
   GUID={0x6E7196DC,0x7F9C,0x460D,{0x9E,0x97,0x84,0x54,0x90,0xB8,0x1D,0x60}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmSession_FormatStringOffsetTable[] =
    {
    764,
    4620,
    4658,
    4696,
    4734,
    4772,
    4810,
    4848,
    4892,
    1036,
    4930,
    4968,
    5000,
    5038,
    5082,
    5138,
    5194,
    5256,
    5300,
    5356,
    5400,
    5438,
    5476,
    5550
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmSession_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmSession_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmSession_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmSession_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(27) _IHsmSessionProxyVtbl = 
{
    &IHsmSession_ProxyInfo,
    &IID_IHsmSession,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmSession::Cancel */ ,
    (void *) (INT_PTR) -1 /* IHsmSession::EnumPhases */ ,
    (void *) (INT_PTR) -1 /* IHsmSession::EnumTotals */ ,
    (void *) (INT_PTR) -1 /* IHsmSession::GetAdviseInterval */ ,
    (void *) (INT_PTR) -1 /* IHsmSession::GetHsmId */ ,
    (void *) (INT_PTR) -1 /* IHsmSession::GetIdentifier */ ,
    (void *) (INT_PTR) -1 /* IHsmSession::GetJob */ ,
    (void *) (INT_PTR) -1 /* IHsmSession::GetName */ ,
    (void *) (INT_PTR) -1 /* IHsmSession::GetResource */ ,
    (void *) (INT_PTR) -1 /* IHsmSession::GetRunId */ ,
    (void *) (INT_PTR) -1 /* IHsmSession::GetSubRunId */ ,
    (void *) (INT_PTR) -1 /* IHsmSession::IsCanceling */ ,
    (void *) (INT_PTR) -1 /* IHsmSession::Pause */ ,
    (void *) (INT_PTR) -1 /* IHsmSession::ProcessEvent */ ,
    (void *) (INT_PTR) -1 /* IHsmSession::ProcessHr */ ,
    (void *) (INT_PTR) -1 /* IHsmSession::ProcessItem */ ,
    (void *) (INT_PTR) -1 /* IHsmSession::ProcessMediaState */ ,
    (void *) (INT_PTR) -1 /* IHsmSession::ProcessPriority */ ,
    (void *) (INT_PTR) -1 /* IHsmSession::ProcessState */ ,
    (void *) (INT_PTR) -1 /* IHsmSession::ProcessString */ ,
    (void *) (INT_PTR) -1 /* IHsmSession::Resume */ ,
    (void *) (INT_PTR) -1 /* IHsmSession::SetAdviseInterval */ ,
    (void *) (INT_PTR) -1 /* IHsmSession::Start */ ,
    (void *) (INT_PTR) -1 /* IHsmSession::Suspend */
};

const CInterfaceStubVtbl _IHsmSessionStubVtbl =
{
    &IID_IHsmSession,
    &IHsmSession_ServerInfo,
    27,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmSessionSinkEveryEvent, ver. 0.0,
   GUID={0xF1AAA4E0,0x8385,0x11d0,{0x81,0xE4,0x00,0xA0,0xC9,0x11,0x80,0xF2}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmSessionSinkEveryEvent_FormatStringOffsetTable[] =
    {
    5588
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmSessionSinkEveryEvent_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmSessionSinkEveryEvent_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmSessionSinkEveryEvent_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmSessionSinkEveryEvent_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IHsmSessionSinkEveryEventProxyVtbl = 
{
    &IHsmSessionSinkEveryEvent_ProxyInfo,
    &IID_IHsmSessionSinkEveryEvent,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmSessionSinkEveryEvent::ProcessSessionEvent */
};

const CInterfaceStubVtbl _IHsmSessionSinkEveryEventStubVtbl =
{
    &IID_IHsmSessionSinkEveryEvent,
    &IHsmSessionSinkEveryEvent_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmSessionSinkEveryItem, ver. 0.0,
   GUID={0xBEA60F85,0x7EBA,0x11d0,{0x81,0xE4,0x00,0xA0,0xC9,0x11,0x80,0xF2}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmSessionSinkEveryItem_FormatStringOffsetTable[] =
    {
    5638
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmSessionSinkEveryItem_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmSessionSinkEveryItem_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmSessionSinkEveryItem_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmSessionSinkEveryItem_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IHsmSessionSinkEveryItemProxyVtbl = 
{
    &IHsmSessionSinkEveryItem_ProxyInfo,
    &IID_IHsmSessionSinkEveryItem,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmSessionSinkEveryItem::ProcessSessionItem */
};

const CInterfaceStubVtbl _IHsmSessionSinkEveryItemStubVtbl =
{
    &IID_IHsmSessionSinkEveryItem,
    &IHsmSessionSinkEveryItem_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmSessionSinkEveryMediaState, ver. 0.0,
   GUID={0xD5450542,0xA6C2,0x11d0,{0x81,0xE7,0x00,0xA0,0xC9,0x11,0x80,0xF2}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmSessionSinkEveryMediaState_FormatStringOffsetTable[] =
    {
    5700
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmSessionSinkEveryMediaState_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmSessionSinkEveryMediaState_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmSessionSinkEveryMediaState_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmSessionSinkEveryMediaState_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IHsmSessionSinkEveryMediaStateProxyVtbl = 
{
    &IHsmSessionSinkEveryMediaState_ProxyInfo,
    &IID_IHsmSessionSinkEveryMediaState,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmSessionSinkEveryMediaState::ProcessSessionMediaState */
};

const CInterfaceStubVtbl _IHsmSessionSinkEveryMediaStateStubVtbl =
{
    &IID_IHsmSessionSinkEveryMediaState,
    &IHsmSessionSinkEveryMediaState_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmSessionSinkEveryPriority, ver. 0.0,
   GUID={0xD5450543,0xA6C2,0x11d0,{0x81,0xE7,0x00,0xA0,0xC9,0x11,0x80,0xF2}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmSessionSinkEveryPriority_FormatStringOffsetTable[] =
    {
    5768
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmSessionSinkEveryPriority_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmSessionSinkEveryPriority_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmSessionSinkEveryPriority_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmSessionSinkEveryPriority_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IHsmSessionSinkEveryPriorityProxyVtbl = 
{
    &IHsmSessionSinkEveryPriority_ProxyInfo,
    &IID_IHsmSessionSinkEveryPriority,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmSessionSinkEveryPriority::ProcessSessionPriority */
};

const CInterfaceStubVtbl _IHsmSessionSinkEveryPriorityStubVtbl =
{
    &IID_IHsmSessionSinkEveryPriority,
    &IHsmSessionSinkEveryPriority_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmSessionSinkEveryState, ver. 0.0,
   GUID={0xBEA60F87,0x7EBA,0x11d0,{0x81,0xE4,0x00,0xA0,0xC9,0x11,0x80,0xF2}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmSessionSinkEveryState_FormatStringOffsetTable[] =
    {
    5812
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmSessionSinkEveryState_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmSessionSinkEveryState_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmSessionSinkEveryState_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmSessionSinkEveryState_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IHsmSessionSinkEveryStateProxyVtbl = 
{
    &IHsmSessionSinkEveryState_ProxyInfo,
    &IID_IHsmSessionSinkEveryState,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmSessionSinkEveryState::ProcessSessionState */
};

const CInterfaceStubVtbl _IHsmSessionSinkEveryStateStubVtbl =
{
    &IID_IHsmSessionSinkEveryState,
    &IHsmSessionSinkEveryState_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmSessionSinkSomeItems, ver. 0.0,
   GUID={0xBEA60F88,0x7EBA,0x11d0,{0x81,0xE4,0x00,0xA0,0xC9,0x11,0x80,0xF2}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmSessionSinkSomeItems_FormatStringOffsetTable[] =
    {
    5638
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmSessionSinkSomeItems_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmSessionSinkSomeItems_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmSessionSinkSomeItems_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmSessionSinkSomeItems_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IHsmSessionSinkSomeItemsProxyVtbl = 
{
    &IHsmSessionSinkSomeItems_ProxyInfo,
    &IID_IHsmSessionSinkSomeItems,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmSessionSinkSomeItems::ProcessSessionItem */
};

const CInterfaceStubVtbl _IHsmSessionSinkSomeItemsStubVtbl =
{
    &IID_IHsmSessionSinkSomeItems,
    &IHsmSessionSinkSomeItems_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmSessionTotals, ver. 0.0,
   GUID={0x35035913,0x0D1C,0x11d2,{0x9B,0x0C,0x00,0x10,0x4B,0x9A,0x28,0x69}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmSessionTotals_FormatStringOffsetTable[] =
    {
    5862,
    5900,
    5938,
    5982,
    536,
    3198,
    6026
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmSessionTotals_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmSessionTotals_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmSessionTotals_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmSessionTotals_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(10) _IHsmSessionTotalsProxyVtbl = 
{
    &IHsmSessionTotals_ProxyInfo,
    &IID_IHsmSessionTotals,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmSessionTotals::Clone */ ,
    (void *) (INT_PTR) -1 /* IHsmSessionTotals::CopyTo */ ,
    (void *) (INT_PTR) -1 /* IHsmSessionTotals::CompareToAction */ ,
    (void *) (INT_PTR) -1 /* IHsmSessionTotals::CompareToISessionTotals */ ,
    (void *) (INT_PTR) -1 /* IHsmSessionTotals::GetAction */ ,
    (void *) (INT_PTR) -1 /* IHsmSessionTotals::GetName */ ,
    (void *) (INT_PTR) -1 /* IHsmSessionTotals::GetStats */
};

const CInterfaceStubVtbl _IHsmSessionTotalsStubVtbl =
{
    &IID_IHsmSessionTotals,
    &IHsmSessionTotals_ServerInfo,
    10,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    __MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x50002, /* Ndr library version */
    0,
    0x6000169, /* MIDL Version 6.0.361 */
    0,
    0,
    0,  /* notify & notify_flag routine table */
    0x1, /* MIDL flag */
    0, /* cs routines */
    0,   /* proxy/server info */
    0   /* Reserved5 */
    };

const CInterfaceProxyVtbl * _jobint_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IHsmActionOnResourceProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmSessionTotalsProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmPhaseProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmJobWorkItemProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmRuleStackProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmSessionSinkEveryMediaStateProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmSessionSinkEveryPriorityProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmPolicyProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmActionProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmRuleProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmCriteriaProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmJobContextProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmJobDefProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmRelocateActionProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmDirectedActionProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmScannerProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmSessionSinkEveryItemProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmSessionSinkEveryStateProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmSessionSinkSomeItemsProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmActionOnResourcePreProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmJobSinkEverySessionProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmRelativeCriteriaProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmActionOnResourcePreScanProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmActionOnResourcePostProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmSessionProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmSessionSinkEveryEventProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmJobProxyVtbl,
    0
};

const CInterfaceStubVtbl * _jobint_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IHsmActionOnResourceStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmSessionTotalsStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmPhaseStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmJobWorkItemStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmRuleStackStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmSessionSinkEveryMediaStateStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmSessionSinkEveryPriorityStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmPolicyStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmActionStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmRuleStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmCriteriaStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmJobContextStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmJobDefStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmRelocateActionStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmDirectedActionStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmScannerStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmSessionSinkEveryItemStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmSessionSinkEveryStateStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmSessionSinkSomeItemsStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmActionOnResourcePreStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmJobSinkEverySessionStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmRelativeCriteriaStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmActionOnResourcePreScanStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmActionOnResourcePostStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmSessionStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmSessionSinkEveryEventStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmJobStubVtbl,
    0
};

PCInterfaceName const _jobint_InterfaceNamesList[] = 
{
    "IHsmActionOnResource",
    "IHsmSessionTotals",
    "IHsmPhase",
    "IHsmJobWorkItem",
    "IHsmRuleStack",
    "IHsmSessionSinkEveryMediaState",
    "IHsmSessionSinkEveryPriority",
    "IHsmPolicy",
    "IHsmAction",
    "IHsmRule",
    "IHsmCriteria",
    "IHsmJobContext",
    "IHsmJobDef",
    "IHsmRelocateAction",
    "IHsmDirectedAction",
    "IHsmScanner",
    "IHsmSessionSinkEveryItem",
    "IHsmSessionSinkEveryState",
    "IHsmSessionSinkSomeItems",
    "IHsmActionOnResourcePre",
    "IHsmJobSinkEverySession",
    "IHsmRelativeCriteria",
    "IHsmActionOnResourcePreScan",
    "IHsmActionOnResourcePost",
    "IHsmSession",
    "IHsmSessionSinkEveryEvent",
    "IHsmJob",
    0
};


#define _jobint_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _jobint, pIID, n)

int __stdcall _jobint_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _jobint, 27, 16 )
    IID_BS_LOOKUP_NEXT_TEST( _jobint, 8 )
    IID_BS_LOOKUP_NEXT_TEST( _jobint, 4 )
    IID_BS_LOOKUP_NEXT_TEST( _jobint, 2 )
    IID_BS_LOOKUP_NEXT_TEST( _jobint, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _jobint, 27, *pIndex )
    
}

const ExtendedProxyFileInfo jobint_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _jobint_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _jobint_StubVtblList,
    (const PCInterfaceName * ) & _jobint_InterfaceNamesList,
    0, // no delegation
    & _jobint_IID_Lookup, 
    27,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
#if _MSC_VER >= 1200
#pragma warning(pop)
#endif


#endif /* defined(_M_IA64) || defined(_M_AMD64)*/

