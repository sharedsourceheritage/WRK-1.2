

/* this ALWAYS GENERATED file contains the proxy stub code */


 /* File created by MIDL compiler version 6.00.0361 */
/* Compiler settings for wsbint.idl:
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


#include "wsbint.h"

#define TYPE_FORMAT_STRING_SIZE   871                               
#define PROC_FORMAT_STRING_SIZE   5293                              
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


extern const MIDL_SERVER_INFO IWsbCollectable_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWsbCollectable_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWsbCollection_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWsbCollection_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWsbEnum_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWsbEnum_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWsbEnumEx_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWsbEnumEx_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWsbGuid_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWsbGuid_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWsbIndexedCollection_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWsbIndexedCollection_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWsbPersistStream_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWsbPersistStream_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWsbPersistable_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWsbPersistable_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWsbString_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWsbString_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWsbTestable_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWsbTestable_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWsbDbSys_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWsbDbSys_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWsbDb_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWsbDb_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWsbDbSession_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWsbDbSession_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWsbDbKey_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWsbDbKey_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWsbDbEntity_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWsbDbEntity_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWsbCreateLocalObject_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWsbCreateLocalObject_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWsbTrace_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWsbTrace_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWsbServer_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWsbServer_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmSystemState_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmSystemState_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmEvent_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmEvent_ProxyInfo;


extern const EXPR_EVAL ExprEvalRoutines[];

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

	/* Procedure CompareTo */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x3 ),	/* 3 */
/*  8 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x22 ),	/* 34 */
/* 14 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 16 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	NdrFcShort( 0x0 ),	/* 0 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCollectable */

/* 24 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 26 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 28 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter pResult */

/* 30 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 32 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 34 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 36 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 38 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 40 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Contains */


	/* Procedure IsEqual */

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

	/* Parameter pCollectable */


	/* Parameter pCollectable */

/* 66 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 68 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 70 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Return value */


	/* Return value */

/* 72 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 74 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 76 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Add */

/* 78 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 80 */	NdrFcLong( 0x0 ),	/* 0 */
/* 84 */	NdrFcShort( 0x3 ),	/* 3 */
/* 86 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 88 */	NdrFcShort( 0x0 ),	/* 0 */
/* 90 */	NdrFcShort( 0x8 ),	/* 8 */
/* 92 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 94 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 96 */	NdrFcShort( 0x0 ),	/* 0 */
/* 98 */	NdrFcShort( 0x0 ),	/* 0 */
/* 100 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCollectable */

/* 102 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 104 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 106 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Return value */

/* 108 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 110 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 112 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetEntries */

/* 114 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 116 */	NdrFcLong( 0x0 ),	/* 0 */
/* 120 */	NdrFcShort( 0x5 ),	/* 5 */
/* 122 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 124 */	NdrFcShort( 0x0 ),	/* 0 */
/* 126 */	NdrFcShort( 0x24 ),	/* 36 */
/* 128 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 130 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 132 */	NdrFcShort( 0x0 ),	/* 0 */
/* 134 */	NdrFcShort( 0x0 ),	/* 0 */
/* 136 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pEntries */

/* 138 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 140 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 142 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 144 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 146 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 148 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Find */

/* 150 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 152 */	NdrFcLong( 0x0 ),	/* 0 */
/* 156 */	NdrFcShort( 0x6 ),	/* 6 */
/* 158 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 160 */	NdrFcShort( 0x44 ),	/* 68 */
/* 162 */	NdrFcShort( 0x8 ),	/* 8 */
/* 164 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 166 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 168 */	NdrFcShort( 0x1 ),	/* 1 */
/* 170 */	NdrFcShort( 0x0 ),	/* 0 */
/* 172 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCollectable */

/* 174 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 176 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 178 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter riid */

/* 180 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 182 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 184 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter ppElement */

/* 186 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 188 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 190 */	NdrFcShort( 0x32 ),	/* Type Offset=50 */

	/* Return value */

/* 192 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 194 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 196 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindGTE */


	/* Procedure IsEmpty */

/* 198 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 200 */	NdrFcLong( 0x0 ),	/* 0 */
/* 204 */	NdrFcShort( 0x7 ),	/* 7 */
/* 206 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 208 */	NdrFcShort( 0x0 ),	/* 0 */
/* 210 */	NdrFcShort( 0x8 ),	/* 8 */
/* 212 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 214 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 216 */	NdrFcShort( 0x0 ),	/* 0 */
/* 218 */	NdrFcShort( 0x0 ),	/* 0 */
/* 220 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */

/* 222 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 224 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 226 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindLT */


	/* Procedure IsLocked */

/* 228 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 230 */	NdrFcLong( 0x0 ),	/* 0 */
/* 234 */	NdrFcShort( 0x8 ),	/* 8 */
/* 236 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 238 */	NdrFcShort( 0x0 ),	/* 0 */
/* 240 */	NdrFcShort( 0x8 ),	/* 8 */
/* 242 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 244 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 246 */	NdrFcShort( 0x0 ),	/* 0 */
/* 248 */	NdrFcShort( 0x0 ),	/* 0 */
/* 250 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */

/* 252 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 254 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 256 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindLTE */


	/* Procedure IncrementChangeCount */


	/* Procedure IsCaseDependent */


	/* Procedure Lock */

/* 258 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 260 */	NdrFcLong( 0x0 ),	/* 0 */
/* 264 */	NdrFcShort( 0x9 ),	/* 9 */
/* 266 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 268 */	NdrFcShort( 0x0 ),	/* 0 */
/* 270 */	NdrFcShort( 0x8 ),	/* 8 */
/* 272 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 274 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 276 */	NdrFcShort( 0x0 ),	/* 0 */
/* 278 */	NdrFcShort( 0x0 ),	/* 0 */
/* 280 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 282 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 284 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 286 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure OccurencesOf */

/* 288 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 290 */	NdrFcLong( 0x0 ),	/* 0 */
/* 294 */	NdrFcShort( 0xa ),	/* 10 */
/* 296 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 298 */	NdrFcShort( 0x0 ),	/* 0 */
/* 300 */	NdrFcShort( 0x24 ),	/* 36 */
/* 302 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 304 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 306 */	NdrFcShort( 0x0 ),	/* 0 */
/* 308 */	NdrFcShort( 0x0 ),	/* 0 */
/* 310 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCollectable */

/* 312 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 314 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 316 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter occurences */

/* 318 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 320 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 322 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 324 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 326 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 328 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Remove */

/* 330 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 332 */	NdrFcLong( 0x0 ),	/* 0 */
/* 336 */	NdrFcShort( 0xb ),	/* 11 */
/* 338 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 340 */	NdrFcShort( 0x44 ),	/* 68 */
/* 342 */	NdrFcShort( 0x8 ),	/* 8 */
/* 344 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 346 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 348 */	NdrFcShort( 0x1 ),	/* 1 */
/* 350 */	NdrFcShort( 0x0 ),	/* 0 */
/* 352 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCollectable */

/* 354 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 356 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 358 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter riid */

/* 360 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 362 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 364 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter ppElement */

/* 366 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 368 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 370 */	NdrFcShort( 0x3e ),	/* Type Offset=62 */

	/* Return value */

/* 372 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 374 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 376 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoveAndRelease */

/* 378 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 380 */	NdrFcLong( 0x0 ),	/* 0 */
/* 384 */	NdrFcShort( 0xc ),	/* 12 */
/* 386 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 388 */	NdrFcShort( 0x0 ),	/* 0 */
/* 390 */	NdrFcShort( 0x8 ),	/* 8 */
/* 392 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 394 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 396 */	NdrFcShort( 0x0 ),	/* 0 */
/* 398 */	NdrFcShort( 0x0 ),	/* 0 */
/* 400 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCollectable */

/* 402 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 404 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 406 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Return value */

/* 408 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 410 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 412 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Unload */


	/* Procedure Next */


	/* Procedure RemoveAllAndRelease */

/* 414 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 416 */	NdrFcLong( 0x0 ),	/* 0 */
/* 420 */	NdrFcShort( 0xd ),	/* 13 */
/* 422 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 424 */	NdrFcShort( 0x0 ),	/* 0 */
/* 426 */	NdrFcShort( 0x8 ),	/* 8 */
/* 428 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 430 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 432 */	NdrFcShort( 0x0 ),	/* 0 */
/* 434 */	NdrFcShort( 0x0 ),	/* 0 */
/* 436 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 438 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 440 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 442 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Previous */


	/* Procedure Unlock */

/* 444 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 446 */	NdrFcLong( 0x0 ),	/* 0 */
/* 450 */	NdrFcShort( 0xe ),	/* 14 */
/* 452 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 454 */	NdrFcShort( 0x0 ),	/* 0 */
/* 456 */	NdrFcShort( 0x8 ),	/* 8 */
/* 458 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 460 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 462 */	NdrFcShort( 0x0 ),	/* 0 */
/* 464 */	NdrFcShort( 0x0 ),	/* 0 */
/* 466 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */

/* 468 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 470 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 472 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Enum */

/* 474 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 476 */	NdrFcLong( 0x0 ),	/* 0 */
/* 480 */	NdrFcShort( 0xf ),	/* 15 */
/* 482 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 484 */	NdrFcShort( 0x0 ),	/* 0 */
/* 486 */	NdrFcShort( 0x8 ),	/* 8 */
/* 488 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 490 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 492 */	NdrFcShort( 0x0 ),	/* 0 */
/* 494 */	NdrFcShort( 0x0 ),	/* 0 */
/* 496 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppEnum */

/* 498 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 500 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 502 */	NdrFcShort( 0x4a ),	/* Type Offset=74 */

	/* Return value */

/* 504 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 506 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 508 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure EnumUnknown */

/* 510 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 512 */	NdrFcLong( 0x0 ),	/* 0 */
/* 516 */	NdrFcShort( 0x10 ),	/* 16 */
/* 518 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 520 */	NdrFcShort( 0x0 ),	/* 0 */
/* 522 */	NdrFcShort( 0x8 ),	/* 8 */
/* 524 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 526 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 528 */	NdrFcShort( 0x0 ),	/* 0 */
/* 530 */	NdrFcShort( 0x0 ),	/* 0 */
/* 532 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppEnum */

/* 534 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 536 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 538 */	NdrFcShort( 0x60 ),	/* Type Offset=96 */

	/* Return value */

/* 540 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 542 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 544 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure First */

/* 546 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 548 */	NdrFcLong( 0x0 ),	/* 0 */
/* 552 */	NdrFcShort( 0x3 ),	/* 3 */
/* 554 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 556 */	NdrFcShort( 0x44 ),	/* 68 */
/* 558 */	NdrFcShort( 0x8 ),	/* 8 */
/* 560 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 562 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 564 */	NdrFcShort( 0x1 ),	/* 1 */
/* 566 */	NdrFcShort( 0x0 ),	/* 0 */
/* 568 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter riid */

/* 570 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 572 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 574 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter ppElement */

/* 576 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 578 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 580 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Return value */

/* 582 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 584 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 586 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Next */

/* 588 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 590 */	NdrFcLong( 0x0 ),	/* 0 */
/* 594 */	NdrFcShort( 0x4 ),	/* 4 */
/* 596 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 598 */	NdrFcShort( 0x44 ),	/* 68 */
/* 600 */	NdrFcShort( 0x8 ),	/* 8 */
/* 602 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 604 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 606 */	NdrFcShort( 0x1 ),	/* 1 */
/* 608 */	NdrFcShort( 0x0 ),	/* 0 */
/* 610 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter riid */

/* 612 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 614 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 616 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter ppElement */

/* 618 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 620 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 622 */	NdrFcShort( 0x82 ),	/* Type Offset=130 */

	/* Return value */

/* 624 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 626 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 628 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure This */

/* 630 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 632 */	NdrFcLong( 0x0 ),	/* 0 */
/* 636 */	NdrFcShort( 0x5 ),	/* 5 */
/* 638 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 640 */	NdrFcShort( 0x44 ),	/* 68 */
/* 642 */	NdrFcShort( 0x8 ),	/* 8 */
/* 644 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 646 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 648 */	NdrFcShort( 0x1 ),	/* 1 */
/* 650 */	NdrFcShort( 0x0 ),	/* 0 */
/* 652 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter riid */

/* 654 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 656 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 658 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter ppElement */

/* 660 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 662 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 664 */	NdrFcShort( 0x8e ),	/* Type Offset=142 */

	/* Return value */

/* 666 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 668 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 670 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Previous */

/* 672 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 674 */	NdrFcLong( 0x0 ),	/* 0 */
/* 678 */	NdrFcShort( 0x6 ),	/* 6 */
/* 680 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 682 */	NdrFcShort( 0x44 ),	/* 68 */
/* 684 */	NdrFcShort( 0x8 ),	/* 8 */
/* 686 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 688 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 690 */	NdrFcShort( 0x1 ),	/* 1 */
/* 692 */	NdrFcShort( 0x0 ),	/* 0 */
/* 694 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter riid */

/* 696 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 698 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 700 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter ppElement */

/* 702 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 704 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 706 */	NdrFcShort( 0x9a ),	/* Type Offset=154 */

	/* Return value */

/* 708 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 710 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 712 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Last */

/* 714 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 716 */	NdrFcLong( 0x0 ),	/* 0 */
/* 720 */	NdrFcShort( 0x7 ),	/* 7 */
/* 722 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 724 */	NdrFcShort( 0x44 ),	/* 68 */
/* 726 */	NdrFcShort( 0x8 ),	/* 8 */
/* 728 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 730 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 732 */	NdrFcShort( 0x1 ),	/* 1 */
/* 734 */	NdrFcShort( 0x0 ),	/* 0 */
/* 736 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter riid */

/* 738 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 740 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 742 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter ppElement */

/* 744 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 746 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 748 */	NdrFcShort( 0xa6 ),	/* Type Offset=166 */

	/* Return value */

/* 750 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 752 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 754 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindNext */

/* 756 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 758 */	NdrFcLong( 0x0 ),	/* 0 */
/* 762 */	NdrFcShort( 0x8 ),	/* 8 */
/* 764 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 766 */	NdrFcShort( 0x44 ),	/* 68 */
/* 768 */	NdrFcShort( 0x8 ),	/* 8 */
/* 770 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 772 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 774 */	NdrFcShort( 0x1 ),	/* 1 */
/* 776 */	NdrFcShort( 0x0 ),	/* 0 */
/* 778 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCollectable */

/* 780 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 782 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 784 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter riid */

/* 786 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 788 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 790 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter ppElement */

/* 792 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 794 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 796 */	NdrFcShort( 0xb2 ),	/* Type Offset=178 */

	/* Return value */

/* 798 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 800 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 802 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Find */

/* 804 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 806 */	NdrFcLong( 0x0 ),	/* 0 */
/* 810 */	NdrFcShort( 0x9 ),	/* 9 */
/* 812 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 814 */	NdrFcShort( 0x44 ),	/* 68 */
/* 816 */	NdrFcShort( 0x8 ),	/* 8 */
/* 818 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 820 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 822 */	NdrFcShort( 0x1 ),	/* 1 */
/* 824 */	NdrFcShort( 0x0 ),	/* 0 */
/* 826 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCollectable */

/* 828 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 830 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 832 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter riid */

/* 834 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 836 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 838 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter ppElement */

/* 840 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 842 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 844 */	NdrFcShort( 0xbe ),	/* Type Offset=190 */

	/* Return value */

/* 846 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 848 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 850 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindPrevious */

/* 852 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 854 */	NdrFcLong( 0x0 ),	/* 0 */
/* 858 */	NdrFcShort( 0xa ),	/* 10 */
/* 860 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 862 */	NdrFcShort( 0x44 ),	/* 68 */
/* 864 */	NdrFcShort( 0x8 ),	/* 8 */
/* 866 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 868 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 870 */	NdrFcShort( 0x1 ),	/* 1 */
/* 872 */	NdrFcShort( 0x0 ),	/* 0 */
/* 874 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCollectable */

/* 876 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 878 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 880 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter riid */

/* 882 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 884 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 886 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter ppElement */

/* 888 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 890 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 892 */	NdrFcShort( 0xca ),	/* Type Offset=202 */

	/* Return value */

/* 894 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 896 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 898 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Last */


	/* Procedure SkipToFirst */


	/* Procedure SkipToFirst */

/* 900 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 902 */	NdrFcLong( 0x0 ),	/* 0 */
/* 906 */	NdrFcShort( 0xb ),	/* 11 */
/* 908 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 910 */	NdrFcShort( 0x0 ),	/* 0 */
/* 912 */	NdrFcShort( 0x8 ),	/* 8 */
/* 914 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 916 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 918 */	NdrFcShort( 0x0 ),	/* 0 */
/* 920 */	NdrFcShort( 0x0 ),	/* 0 */
/* 922 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 924 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 926 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 928 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SkipNext */


	/* Procedure SkipNext */

/* 930 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 932 */	NdrFcLong( 0x0 ),	/* 0 */
/* 936 */	NdrFcShort( 0xc ),	/* 12 */
/* 938 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 940 */	NdrFcShort( 0x8 ),	/* 8 */
/* 942 */	NdrFcShort( 0x8 ),	/* 8 */
/* 944 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 946 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 948 */	NdrFcShort( 0x0 ),	/* 0 */
/* 950 */	NdrFcShort( 0x0 ),	/* 0 */
/* 952 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter element */


	/* Parameter element */

/* 954 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 956 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 958 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 960 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 962 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 964 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SkipTo */


	/* Procedure SkipTo */

/* 966 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 968 */	NdrFcLong( 0x0 ),	/* 0 */
/* 972 */	NdrFcShort( 0xd ),	/* 13 */
/* 974 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 976 */	NdrFcShort( 0x8 ),	/* 8 */
/* 978 */	NdrFcShort( 0x8 ),	/* 8 */
/* 980 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 982 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 984 */	NdrFcShort( 0x0 ),	/* 0 */
/* 986 */	NdrFcShort( 0x0 ),	/* 0 */
/* 988 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter index */


	/* Parameter index */

/* 990 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 992 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 994 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 996 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 998 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1000 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetTraceEntryExit */


	/* Procedure SkipPrevious */


	/* Procedure SkipPrevious */

/* 1002 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1004 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1008 */	NdrFcShort( 0xe ),	/* 14 */
/* 1010 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1012 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1014 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1016 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1018 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1020 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1022 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1024 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter traceEntryExit */


	/* Parameter element */


	/* Parameter element */

/* 1026 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1028 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1030 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 1032 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1034 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1036 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SkipToLast */


	/* Procedure SkipToLast */

/* 1038 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1040 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1044 */	NdrFcShort( 0xf ),	/* 15 */
/* 1046 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1048 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1050 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1052 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1054 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1056 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1058 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1060 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */

/* 1062 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1064 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1066 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Remove */


	/* Procedure Reset */


	/* Procedure Reset */

/* 1068 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1070 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1074 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1076 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1078 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1080 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1082 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1084 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1086 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1088 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1090 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 1092 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1094 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1096 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Init */


	/* Procedure Init */

/* 1098 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1100 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1104 */	NdrFcShort( 0x11 ),	/* 17 */
/* 1106 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1108 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1110 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1112 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1114 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1116 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1118 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1120 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCollection */


	/* Parameter pCollection */

/* 1122 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1124 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1126 */	NdrFcShort( 0xd6 ),	/* Type Offset=214 */

	/* Return value */


	/* Return value */

/* 1128 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1130 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1132 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Clone */


	/* Procedure Clone */

/* 1134 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1136 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1140 */	NdrFcShort( 0x12 ),	/* 18 */
/* 1142 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1144 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1146 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1148 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1150 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1152 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1154 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1156 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppEnum */


	/* Parameter ppEnum */

/* 1158 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1160 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1162 */	NdrFcShort( 0x4a ),	/* Type Offset=74 */

	/* Return value */


	/* Return value */

/* 1164 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1166 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1168 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure First */

/* 1170 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1172 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1176 */	NdrFcShort( 0x3 ),	/* 3 */
/* 1178 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1180 */	NdrFcShort( 0x4c ),	/* 76 */
/* 1182 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1184 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x5,		/* 5 */
/* 1186 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1188 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1190 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1192 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter element */

/* 1194 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1196 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1198 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter riid */

/* 1200 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1202 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1204 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter elements */

/* 1206 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 1208 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1210 */	NdrFcShort( 0xf4 ),	/* Type Offset=244 */

	/* Parameter pElementsFetched */

/* 1212 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1214 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1216 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1218 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1220 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1222 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Next */

/* 1224 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1226 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1230 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1232 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1234 */	NdrFcShort( 0x4c ),	/* 76 */
/* 1236 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1238 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x5,		/* 5 */
/* 1240 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1242 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1244 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1246 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter element */

/* 1248 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1250 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1252 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter riid */

/* 1254 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1256 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1258 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter elements */

/* 1260 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 1262 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1264 */	NdrFcShort( 0x116 ),	/* Type Offset=278 */

	/* Parameter pElementsFetched */

/* 1266 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1268 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1270 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1272 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1274 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1276 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure This */

/* 1278 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1280 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1284 */	NdrFcShort( 0x5 ),	/* 5 */
/* 1286 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1288 */	NdrFcShort( 0x4c ),	/* 76 */
/* 1290 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1292 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x5,		/* 5 */
/* 1294 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1296 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1298 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1300 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter element */

/* 1302 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1304 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1306 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter riid */

/* 1308 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1310 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1312 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter elements */

/* 1314 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 1316 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1318 */	NdrFcShort( 0x138 ),	/* Type Offset=312 */

	/* Parameter pElementsFetched */

/* 1320 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1322 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1324 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1326 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1328 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1330 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Previous */

/* 1332 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1334 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1338 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1340 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1342 */	NdrFcShort( 0x4c ),	/* 76 */
/* 1344 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1346 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x5,		/* 5 */
/* 1348 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1350 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1352 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1354 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter element */

/* 1356 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1358 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1360 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter riid */

/* 1362 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1364 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1366 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter elements */

/* 1368 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 1370 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1372 */	NdrFcShort( 0x15a ),	/* Type Offset=346 */

	/* Parameter pElementsFetched */

/* 1374 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1376 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1378 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1380 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1382 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1384 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Last */

/* 1386 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1388 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1392 */	NdrFcShort( 0x7 ),	/* 7 */
/* 1394 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1396 */	NdrFcShort( 0x4c ),	/* 76 */
/* 1398 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1400 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x5,		/* 5 */
/* 1402 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1404 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1406 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1408 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter element */

/* 1410 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1412 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1414 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter riid */

/* 1416 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1418 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1420 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter elements */

/* 1422 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 1424 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1426 */	NdrFcShort( 0x17c ),	/* Type Offset=380 */

	/* Parameter pElementsFetched */

/* 1428 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1430 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1432 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1434 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1436 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1438 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindNext */

/* 1440 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1442 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1446 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1448 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 1450 */	NdrFcShort( 0x4c ),	/* 76 */
/* 1452 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1454 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 1456 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1458 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1460 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1462 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCollectable */

/* 1464 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1466 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1468 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter element */

/* 1470 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1472 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1474 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter riid */

/* 1476 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1478 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1480 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter elements */

/* 1482 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 1484 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1486 */	NdrFcShort( 0x19e ),	/* Type Offset=414 */

	/* Parameter pElementsFetched */

/* 1488 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1490 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1492 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1494 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1496 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1498 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Find */

/* 1500 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1502 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1506 */	NdrFcShort( 0x9 ),	/* 9 */
/* 1508 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 1510 */	NdrFcShort( 0x4c ),	/* 76 */
/* 1512 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1514 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 1516 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1518 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1520 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1522 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCollectable */

/* 1524 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1526 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1528 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter element */

/* 1530 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1532 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1534 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter riid */

/* 1536 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1538 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1540 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter elements */

/* 1542 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 1544 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1546 */	NdrFcShort( 0x1c0 ),	/* Type Offset=448 */

	/* Parameter pElementsFetched */

/* 1548 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1550 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1552 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1554 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1556 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1558 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindPrevious */

/* 1560 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1562 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1566 */	NdrFcShort( 0xa ),	/* 10 */
/* 1568 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 1570 */	NdrFcShort( 0x4c ),	/* 76 */
/* 1572 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1574 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 1576 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1578 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1580 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1582 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCollectable */

/* 1584 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1586 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1588 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter element */

/* 1590 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1592 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1594 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter riid */

/* 1596 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1598 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1600 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter elements */

/* 1602 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 1604 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1606 */	NdrFcShort( 0x1e2 ),	/* Type Offset=482 */

	/* Parameter pElementsFetched */

/* 1608 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1610 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1612 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1614 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1616 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1618 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToGuid */

/* 1620 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1622 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1626 */	NdrFcShort( 0x5 ),	/* 5 */
/* 1628 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 1630 */	NdrFcShort( 0x30 ),	/* 48 */
/* 1632 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1634 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1636 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1638 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1640 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1642 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter value */

/* 1644 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 1646 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1648 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter pResult */

/* 1650 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1652 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1654 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1656 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1658 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1660 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToIGuid */

/* 1662 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1664 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1668 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1670 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1672 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1674 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1676 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1678 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1680 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1682 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1684 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pGuid */

/* 1686 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1688 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1690 */	NdrFcShort( 0x1f8 ),	/* Type Offset=504 */

	/* Parameter pResult */

/* 1692 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1694 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1696 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1698 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1700 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1702 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetGuid */

/* 1704 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1706 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1710 */	NdrFcShort( 0x7 ),	/* 7 */
/* 1712 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1714 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1716 */	NdrFcShort( 0x4c ),	/* 76 */
/* 1718 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1720 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1722 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1724 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1726 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pValue */

/* 1728 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 1730 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1732 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Return value */

/* 1734 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1736 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1738 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetGuid */

/* 1740 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1742 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1746 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1748 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 1750 */	NdrFcShort( 0x30 ),	/* 48 */
/* 1752 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1754 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1756 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1758 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1760 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1762 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter value */

/* 1764 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 1766 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1768 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Return value */

/* 1770 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1772 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1774 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AddAt */

/* 1776 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1778 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1782 */	NdrFcShort( 0x11 ),	/* 17 */
/* 1784 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1786 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1788 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1790 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1792 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1794 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1796 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1798 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCollectable */

/* 1800 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1802 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1804 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter index */

/* 1806 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1808 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1810 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1812 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1814 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1816 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Append */

/* 1818 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1820 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1824 */	NdrFcShort( 0x12 ),	/* 18 */
/* 1826 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1828 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1830 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1832 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1834 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1836 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1838 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1840 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCollectable */

/* 1842 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1844 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1846 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Return value */

/* 1848 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1850 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1852 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Prepend */

/* 1854 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1856 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1860 */	NdrFcShort( 0x13 ),	/* 19 */
/* 1862 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1864 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1866 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1868 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1870 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1872 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1874 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1876 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCollectable */

/* 1878 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1880 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1882 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Return value */

/* 1884 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1886 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1888 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoveAt */

/* 1890 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1892 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1896 */	NdrFcShort( 0x14 ),	/* 20 */
/* 1898 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1900 */	NdrFcShort( 0x4c ),	/* 76 */
/* 1902 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1904 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 1906 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1908 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1910 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1912 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter index */

/* 1914 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1916 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1918 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter riid */

/* 1920 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1922 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1924 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter ppElement */

/* 1926 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1928 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1930 */	NdrFcShort( 0x20e ),	/* Type Offset=526 */

	/* Return value */

/* 1932 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1934 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1936 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure First */

/* 1938 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1940 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1944 */	NdrFcShort( 0x15 ),	/* 21 */
/* 1946 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 1948 */	NdrFcShort( 0x44 ),	/* 68 */
/* 1950 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1952 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 1954 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1956 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1958 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1960 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter riid */

/* 1962 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1964 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 1966 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter ppElement */

/* 1968 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1970 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 1972 */	NdrFcShort( 0x21a ),	/* Type Offset=538 */

	/* Return value */

/* 1974 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1976 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 1978 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure At */

/* 1980 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1982 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1986 */	NdrFcShort( 0x16 ),	/* 22 */
/* 1988 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 1990 */	NdrFcShort( 0x4c ),	/* 76 */
/* 1992 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1994 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 1996 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1998 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2000 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2002 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter index */

/* 2004 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2006 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2008 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter riid */

/* 2010 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 2012 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2014 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter ppElement */

/* 2016 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2018 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2020 */	NdrFcShort( 0x226 ),	/* Type Offset=550 */

	/* Return value */

/* 2022 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2024 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2026 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Last */

/* 2028 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2030 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2034 */	NdrFcShort( 0x17 ),	/* 23 */
/* 2036 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2038 */	NdrFcShort( 0x44 ),	/* 68 */
/* 2040 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2042 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 2044 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 2046 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2048 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2050 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter riid */

/* 2052 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 2054 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2056 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter ppElement */

/* 2058 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2060 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2062 */	NdrFcShort( 0x232 ),	/* Type Offset=562 */

	/* Return value */

/* 2064 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2066 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2068 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Index */

/* 2070 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2072 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2076 */	NdrFcShort( 0x18 ),	/* 24 */
/* 2078 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2080 */	NdrFcShort( 0x1c ),	/* 28 */
/* 2082 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2084 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2086 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2088 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2090 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2092 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCollectable */

/* 2094 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2096 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2098 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter pIndex */

/* 2100 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 2102 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2104 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2106 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2108 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2110 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Copy */

/* 2112 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2114 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2118 */	NdrFcShort( 0x19 ),	/* 25 */
/* 2120 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 2122 */	NdrFcShort( 0x54 ),	/* 84 */
/* 2124 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2126 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x6,		/* 6 */
/* 2128 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 2130 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2132 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2134 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter start */

/* 2136 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2138 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2140 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter stop */

/* 2142 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2144 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2146 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter riid */

/* 2148 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 2150 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2152 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter elements */

/* 2154 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 2156 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2158 */	NdrFcShort( 0x24e ),	/* Type Offset=590 */

	/* Parameter pElementsFetched */

/* 2160 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2162 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2164 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2166 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2168 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2170 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CopyIfMatches */

/* 2172 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2174 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2178 */	NdrFcShort( 0x1a ),	/* 26 */
/* 2180 */	NdrFcShort( 0x28 ),	/* x86 Stack size/offset = 40 */
/* 2182 */	NdrFcShort( 0x5c ),	/* 92 */
/* 2184 */	NdrFcShort( 0x40 ),	/* 64 */
/* 2186 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x9,		/* 9 */
/* 2188 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 2190 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2192 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2194 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter start */

/* 2196 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2198 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2200 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter stop */

/* 2202 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2204 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2206 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pCollectable */

/* 2208 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2210 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2212 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter element */

/* 2214 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2216 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2218 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter riid */

/* 2220 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 2222 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2224 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter elements */

/* 2226 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 2228 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 2230 */	NdrFcShort( 0x270 ),	/* Type Offset=624 */

	/* Parameter pElementsFetched */

/* 2232 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2234 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 2236 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pStoppedAt */

/* 2238 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2240 */	NdrFcShort( 0x20 ),	/* x86 Stack size/offset = 32 */
/* 2242 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2244 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2246 */	NdrFcShort( 0x24 ),	/* x86 Stack size/offset = 36 */
/* 2248 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AppendBool */


	/* Procedure SetIsDirty */

/* 2250 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2252 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2256 */	NdrFcShort( 0x3 ),	/* 3 */
/* 2258 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2260 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2262 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2264 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2266 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2268 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2270 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2272 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter value */


	/* Parameter isDirty */

/* 2274 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2276 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2278 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 2280 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2282 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2284 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDefaultFileName */

/* 2286 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2288 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2292 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2294 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2296 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2298 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2300 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2302 */	0x8,		/* 8 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 2304 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2306 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2308 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFilename */

/* 2310 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 2312 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2314 */	NdrFcShort( 0x28a ),	/* Type Offset=650 */

	/* Parameter bufferSize */

/* 2316 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2318 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2320 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2322 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2324 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2326 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindEQ */


	/* Procedure TransactionEnd */


	/* Procedure Terminate */


	/* Procedure ReleaseFile */

/* 2328 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2330 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2334 */	NdrFcShort( 0x5 ),	/* 5 */
/* 2336 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2338 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2340 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2342 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 2344 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2346 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2348 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2350 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 2352 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2354 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2356 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetDefaultFileName */

/* 2358 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2360 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2364 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2366 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2368 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2370 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2372 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2374 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2376 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2378 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2380 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter fileName */

/* 2382 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2384 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2386 */	NdrFcShort( 0x2ac ),	/* Type Offset=684 */

	/* Return value */

/* 2388 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2390 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2392 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToString */

/* 2394 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2396 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2400 */	NdrFcShort( 0x5 ),	/* 5 */
/* 2402 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2404 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2406 */	NdrFcShort( 0x22 ),	/* 34 */
/* 2408 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2410 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2412 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2414 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2416 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter value */

/* 2418 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2420 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2422 */	NdrFcShort( 0x2ac ),	/* Type Offset=684 */

	/* Parameter pResult */

/* 2424 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2426 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2428 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2430 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2432 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2434 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToIString */

/* 2436 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2438 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2442 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2444 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2446 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2448 */	NdrFcShort( 0x22 ),	/* 34 */
/* 2450 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2452 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2454 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2456 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2458 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pString */

/* 2460 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2462 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2464 */	NdrFcShort( 0x2ae ),	/* Type Offset=686 */

	/* Parameter pResult */

/* 2466 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2468 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2470 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2472 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2474 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2476 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetString */

/* 2478 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2480 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2484 */	NdrFcShort( 0x7 ),	/* 7 */
/* 2486 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2488 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2490 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2492 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2494 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2496 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2498 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2500 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pValue */

/* 2502 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 2504 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2506 */	NdrFcShort( 0x2c0 ),	/* Type Offset=704 */

	/* Parameter bufferSize */

/* 2508 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2510 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2512 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2514 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2516 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2518 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetStringAndCase */

/* 2520 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2522 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2526 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2528 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 2530 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2532 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2534 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 2536 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2538 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2540 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2542 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pValue */

/* 2544 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 2546 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2548 */	NdrFcShort( 0x2c0 ),	/* Type Offset=704 */

	/* Parameter pIsCaseDependent */

/* 2550 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2552 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2554 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter bufferSize */

/* 2556 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2558 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2560 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2562 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2564 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2566 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetToBool */


	/* Procedure SetIsCaseDependent */

/* 2568 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2570 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2574 */	NdrFcShort( 0xa ),	/* 10 */
/* 2576 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2578 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2580 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2582 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2584 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2586 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2588 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2590 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter value */


	/* Parameter isCaseDependent */

/* 2592 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2594 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2596 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 2598 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2600 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2602 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Locate */


	/* Procedure SetString */

/* 2604 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2606 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2610 */	NdrFcShort( 0xb ),	/* 11 */
/* 2612 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2614 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2616 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2618 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2620 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2622 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2624 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2626 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter path */


	/* Parameter value */

/* 2628 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2630 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2632 */	NdrFcShort( 0x2ac ),	/* Type Offset=684 */

	/* Return value */


	/* Return value */

/* 2634 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2636 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2638 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetStringAndCase */

/* 2640 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2642 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2646 */	NdrFcShort( 0xc ),	/* 12 */
/* 2648 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2650 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2652 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2654 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2656 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2658 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2660 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2662 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter value */

/* 2664 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2666 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2668 */	NdrFcShort( 0x2ac ),	/* Type Offset=684 */

	/* Parameter isCaseDependent */

/* 2670 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2672 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2674 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2676 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2678 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2680 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Test */

/* 2682 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2684 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2688 */	NdrFcShort( 0x3 ),	/* 3 */
/* 2690 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2692 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2694 */	NdrFcShort( 0x3c ),	/* 60 */
/* 2696 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 2698 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2700 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2702 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2704 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter passed */

/* 2706 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2708 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2710 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter failed */

/* 2712 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2714 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2716 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2718 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2720 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2722 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Backup */

/* 2724 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2726 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2730 */	NdrFcShort( 0x3 ),	/* 3 */
/* 2732 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2734 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2736 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2738 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2740 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2742 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2744 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2746 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter path */

/* 2748 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2750 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2752 */	NdrFcShort( 0x2ac ),	/* Type Offset=684 */

	/* Parameter flags */

/* 2754 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2756 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2758 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2760 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2762 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2764 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Create */


	/* Procedure Init */

/* 2766 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2768 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2772 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2774 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2776 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2778 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2780 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2782 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2784 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2786 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2788 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter path */


	/* Parameter path */

/* 2790 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2792 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2794 */	NdrFcShort( 0x2ac ),	/* Type Offset=684 */

	/* Parameter flags */


	/* Parameter flags */

/* 2796 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2798 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2800 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 2802 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2804 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2806 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure NewSession */

/* 2808 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2810 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2814 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2816 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2818 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2820 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2822 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2824 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2826 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2828 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2830 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppSession */

/* 2832 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2834 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2836 */	NdrFcShort( 0x2c8 ),	/* Type Offset=712 */

	/* Return value */

/* 2838 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2840 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2842 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetGlobalSession */

/* 2844 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2846 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2850 */	NdrFcShort( 0x7 ),	/* 7 */
/* 2852 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2854 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2856 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2858 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2860 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2862 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2864 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2866 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppSession */

/* 2868 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2870 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2872 */	NdrFcShort( 0x2c8 ),	/* Type Offset=712 */

	/* Return value */

/* 2874 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2876 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2878 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Restore */

/* 2880 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2882 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2886 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2888 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2890 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2892 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2894 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2896 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2898 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2900 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2902 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter fromPath */

/* 2904 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2906 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2908 */	NdrFcShort( 0x2ac ),	/* Type Offset=684 */

	/* Parameter toPath */

/* 2910 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2912 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2914 */	NdrFcShort( 0x2ac ),	/* Type Offset=684 */

	/* Return value */

/* 2916 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2918 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2920 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Close */

/* 2922 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2924 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2928 */	NdrFcShort( 0x3 ),	/* 3 */
/* 2930 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2932 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2934 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2936 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2938 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2940 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2942 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2944 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSession */

/* 2946 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2948 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2950 */	NdrFcShort( 0x2cc ),	/* Type Offset=716 */

	/* Return value */

/* 2952 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2954 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2956 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Delete */

/* 2958 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2960 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2964 */	NdrFcShort( 0x5 ),	/* 5 */
/* 2966 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 2968 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2970 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2972 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2974 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2976 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2978 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2980 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter path */

/* 2982 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2984 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 2986 */	NdrFcShort( 0x2ac ),	/* Type Offset=684 */

	/* Parameter flags */

/* 2988 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2990 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 2992 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2994 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2996 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 2998 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Dump */

/* 3000 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3002 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3006 */	NdrFcShort( 0x6 ),	/* 6 */
/* 3008 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3010 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3012 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3014 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 3016 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3018 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3020 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3022 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Filename */

/* 3024 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3026 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3028 */	NdrFcShort( 0x2ac ),	/* Type Offset=684 */

	/* Parameter Flags */

/* 3030 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3032 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3034 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter Data */

/* 3036 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3038 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3040 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3042 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3044 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3046 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetEntity */

/* 3048 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3050 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3054 */	NdrFcShort( 0x7 ),	/* 7 */
/* 3056 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3058 */	NdrFcShort( 0x4c ),	/* 76 */
/* 3060 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3062 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 3064 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 3066 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3068 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3070 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSession */

/* 3072 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3074 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3076 */	NdrFcShort( 0x2cc ),	/* Type Offset=716 */

	/* Parameter RecId */

/* 3078 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3080 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3082 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter riid */

/* 3084 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 3086 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3088 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter ppEntity */

/* 3090 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3092 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3094 */	NdrFcShort( 0x2de ),	/* Type Offset=734 */

	/* Return value */

/* 3096 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3098 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3100 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetName */

/* 3102 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3104 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3108 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3110 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3112 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3114 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3116 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 3118 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3120 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3122 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3124 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */

/* 3126 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 3128 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3130 */	NdrFcShort( 0x2c0 ),	/* Type Offset=704 */

	/* Return value */

/* 3132 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3134 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3136 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPath */

/* 3138 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3140 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3144 */	NdrFcShort( 0x9 ),	/* 9 */
/* 3146 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3148 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3150 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3152 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 3154 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3156 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3158 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3160 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPath */

/* 3162 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 3164 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3166 */	NdrFcShort( 0x2c0 ),	/* Type Offset=704 */

	/* Return value */

/* 3168 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3170 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3172 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetVersion */

/* 3174 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3176 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3180 */	NdrFcShort( 0xa ),	/* 10 */
/* 3182 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3184 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3186 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3188 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3190 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3192 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3194 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3196 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVer */

/* 3198 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3200 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3202 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3204 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3206 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3208 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Open */

/* 3210 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3212 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3216 */	NdrFcShort( 0xc ),	/* 12 */
/* 3218 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3220 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3222 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3224 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3226 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3228 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3230 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3232 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppSession */

/* 3234 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 3236 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3238 */	NdrFcShort( 0x2ea ),	/* Type Offset=746 */

	/* Return value */

/* 3240 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3242 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3244 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure OnStateChange */


	/* Procedure StartTrace */


	/* Procedure TransactionBegin */

/* 3246 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3248 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3252 */	NdrFcShort( 0x3 ),	/* 3 */
/* 3254 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3256 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3258 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3260 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 3262 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3264 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3266 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3268 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 3270 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3272 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3274 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure StopTrace */


	/* Procedure Disconnect */


	/* Procedure TransactionCancel */

/* 3276 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3278 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3282 */	NdrFcShort( 0x4 ),	/* 4 */
/* 3284 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3286 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3288 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3290 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 3292 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3294 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3296 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3298 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 3300 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3302 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3304 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AppendBytes */

/* 3306 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3308 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3312 */	NdrFcShort( 0x4 ),	/* 4 */
/* 3314 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3316 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3318 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3320 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 3322 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3324 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3326 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3328 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bytes */

/* 3330 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3332 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3334 */	NdrFcShort( 0x2f2 ),	/* Type Offset=754 */

	/* Parameter size */

/* 3336 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3338 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3340 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3342 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3344 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3346 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AppendFiletime */

/* 3348 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3350 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3354 */	NdrFcShort( 0x5 ),	/* 5 */
/* 3356 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3358 */	NdrFcShort( 0x18 ),	/* 24 */
/* 3360 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3362 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3364 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3366 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3368 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3370 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter value */

/* 3372 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 3374 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3376 */	NdrFcShort( 0x2fe ),	/* Type Offset=766 */

	/* Return value */

/* 3378 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3380 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3382 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AppendGuid */

/* 3384 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3386 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3390 */	NdrFcShort( 0x6 ),	/* 6 */
/* 3392 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3394 */	NdrFcShort( 0x30 ),	/* 48 */
/* 3396 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3398 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3400 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3402 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3404 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3406 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter value */

/* 3408 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 3410 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3412 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Return value */

/* 3414 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3416 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3418 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AppendLonglong */

/* 3420 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3422 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3426 */	NdrFcShort( 0x7 ),	/* 7 */
/* 3428 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3430 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3432 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3434 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3436 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3438 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3440 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3442 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter value */

/* 3444 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3446 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3448 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 3450 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3452 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3454 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AppendString */

/* 3456 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3458 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3462 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3464 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3466 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3468 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3470 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3472 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3474 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3476 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3478 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter value */

/* 3480 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3482 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3484 */	NdrFcShort( 0x2ac ),	/* Type Offset=684 */

	/* Return value */

/* 3486 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3488 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3490 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDatabaseVersion */


	/* Procedure GetType */

/* 3492 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3494 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3498 */	NdrFcShort( 0x9 ),	/* 9 */
/* 3500 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3502 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3504 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3506 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3508 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3510 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3512 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3514 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pDatabaseVersion */


	/* Parameter pType */

/* 3516 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3518 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3520 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 3522 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3524 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3526 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetToBytes */

/* 3528 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3530 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3534 */	NdrFcShort( 0xb ),	/* 11 */
/* 3536 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3538 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3540 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3542 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 3544 */	0x8,		/* 8 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3546 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3548 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3550 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bytes */

/* 3552 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3554 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3556 */	NdrFcShort( 0x2f2 ),	/* Type Offset=754 */

	/* Parameter size */

/* 3558 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3560 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3562 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3564 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3566 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3568 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetToFiletime */

/* 3570 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3572 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3576 */	NdrFcShort( 0xc ),	/* 12 */
/* 3578 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3580 */	NdrFcShort( 0x18 ),	/* 24 */
/* 3582 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3584 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3586 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3588 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3590 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3592 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter value */

/* 3594 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 3596 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3598 */	NdrFcShort( 0x2fe ),	/* Type Offset=766 */

	/* Return value */

/* 3600 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3602 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3604 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetToGuid */

/* 3606 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3608 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3612 */	NdrFcShort( 0xd ),	/* 13 */
/* 3614 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 3616 */	NdrFcShort( 0x30 ),	/* 48 */
/* 3618 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3620 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3622 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3624 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3626 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3628 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter value */

/* 3630 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 3632 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3634 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Return value */

/* 3636 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3638 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 3640 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetToLonglong */

/* 3642 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3644 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3648 */	NdrFcShort( 0xe ),	/* 14 */
/* 3650 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3652 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3654 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3656 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3658 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3660 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3662 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3664 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter value */

/* 3666 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3668 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3670 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 3672 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3674 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3676 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetToUlong */

/* 3678 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3680 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3684 */	NdrFcShort( 0xf ),	/* 15 */
/* 3686 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3688 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3690 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3692 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3694 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3696 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3698 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3700 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter value */

/* 3702 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3704 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3706 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3708 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3710 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3712 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetToString */

/* 3714 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3716 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3720 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3722 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3724 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3726 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3728 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3730 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3732 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3734 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3736 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter value */

/* 3738 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3740 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3742 */	NdrFcShort( 0x2ac ),	/* Type Offset=684 */

	/* Return value */

/* 3744 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3746 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3748 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Clone */

/* 3750 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3752 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3756 */	NdrFcShort( 0x3 ),	/* 3 */
/* 3758 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 3760 */	NdrFcShort( 0x44 ),	/* 68 */
/* 3762 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3764 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 3766 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 3768 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3770 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3772 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter riid */

/* 3774 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 3776 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3778 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter ppEntity */

/* 3780 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3782 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3784 */	NdrFcShort( 0x306 ),	/* Type Offset=774 */

	/* Return value */

/* 3786 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3788 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3790 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindGT */

/* 3792 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3794 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3798 */	NdrFcShort( 0x6 ),	/* 6 */
/* 3800 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3802 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3804 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3806 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 3808 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3810 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3812 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3814 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 3816 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3818 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3820 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SaveAll */


	/* Procedure First */

/* 3822 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3824 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3828 */	NdrFcShort( 0xa ),	/* 10 */
/* 3830 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3832 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3834 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3836 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 3838 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3840 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3842 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3844 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */

/* 3846 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3848 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3850 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DestroyObject */


	/* Procedure MarkAsNew */

/* 3852 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3854 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3858 */	NdrFcShort( 0xc ),	/* 12 */
/* 3860 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3862 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3864 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3866 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 3868 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3870 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3872 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3874 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */

/* 3876 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3878 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3880 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Print */

/* 3882 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3884 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3888 */	NdrFcShort( 0xf ),	/* 15 */
/* 3890 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3892 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3894 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3896 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3898 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3900 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3902 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3904 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pStream */

/* 3906 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3908 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3910 */	NdrFcShort( 0x312 ),	/* Type Offset=786 */

	/* Return value */

/* 3912 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3914 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3916 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure UpdateKey */

/* 3918 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3920 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3924 */	NdrFcShort( 0x11 ),	/* 17 */
/* 3926 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3928 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3930 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3932 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3934 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3936 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3938 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3940 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pKey */

/* 3942 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3944 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3946 */	NdrFcShort( 0x324 ),	/* Type Offset=804 */

	/* Return value */

/* 3948 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3950 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3952 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure UseKey */

/* 3954 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3956 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3960 */	NdrFcShort( 0x12 ),	/* 18 */
/* 3962 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 3964 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3966 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3968 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3970 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3972 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3974 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3976 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter type */

/* 3978 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3980 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 3982 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3984 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3986 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 3988 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Write */

/* 3990 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3992 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3996 */	NdrFcShort( 0x13 ),	/* 19 */
/* 3998 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4000 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4002 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4004 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 4006 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4008 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4010 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4012 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 4014 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4016 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4018 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetSequentialScan */

/* 4020 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4022 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4026 */	NdrFcShort( 0x14 ),	/* 20 */
/* 4028 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4030 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4032 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4034 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 4036 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4038 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4040 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4042 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 4044 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4046 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4048 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure LoadFromRegistry */


	/* Procedure ResetSequentialScan */

/* 4050 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4052 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4056 */	NdrFcShort( 0x15 ),	/* 21 */
/* 4058 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4060 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4062 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4064 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 4066 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4068 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4070 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4072 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */

/* 4074 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4076 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4078 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateInstance */

/* 4080 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4082 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4086 */	NdrFcShort( 0x3 ),	/* 3 */
/* 4088 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 4090 */	NdrFcShort( 0x88 ),	/* 136 */
/* 4092 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4094 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 4096 */	0x8,		/* 8 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 4098 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4100 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4102 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter rclsid */

/* 4104 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 4106 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4108 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter riid */

/* 4110 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 4112 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4114 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter ppv */

/* 4116 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 4118 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4120 */	NdrFcShort( 0x336 ),	/* Type Offset=822 */

	/* Return value */

/* 4122 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4124 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4126 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetTraceOn */

/* 4128 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4130 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4134 */	NdrFcShort( 0x5 ),	/* 5 */
/* 4136 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4138 */	NdrFcShort( 0x10 ),	/* 16 */
/* 4140 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4142 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4144 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4146 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4148 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4150 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter traceElement */

/* 4152 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4154 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4156 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 4158 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4160 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4162 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetTraceOff */

/* 4164 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4166 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4170 */	NdrFcShort( 0x6 ),	/* 6 */
/* 4172 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4174 */	NdrFcShort( 0x10 ),	/* 16 */
/* 4176 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4178 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4180 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4182 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4184 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4186 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter traceElement */

/* 4188 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4190 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4192 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 4194 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4196 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4198 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetTraceSettings */

/* 4200 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4202 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4206 */	NdrFcShort( 0x7 ),	/* 7 */
/* 4208 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4210 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4212 */	NdrFcShort( 0x2c ),	/* 44 */
/* 4214 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4216 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4218 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4220 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4222 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pTraceElements */

/* 4224 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4226 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4228 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 4230 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4232 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4234 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetTraceSetting */

/* 4236 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4238 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4242 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4244 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 4246 */	NdrFcShort( 0x10 ),	/* 16 */
/* 4248 */	NdrFcShort( 0x24 ),	/* 36 */
/* 4250 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 4252 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4254 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4256 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4258 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter traceElement */

/* 4260 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4262 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4264 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pOn */

/* 4266 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4268 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4270 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4272 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4274 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4276 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DirectOutput */

/* 4278 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4280 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4284 */	NdrFcShort( 0x9 ),	/* 9 */
/* 4286 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4288 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4290 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4292 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4294 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4296 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4298 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4300 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter output */

/* 4302 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4304 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4306 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4308 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4310 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4312 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetOutputFormat */

/* 4314 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4316 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4320 */	NdrFcShort( 0xa ),	/* 10 */
/* 4322 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 4324 */	NdrFcShort( 0x18 ),	/* 24 */
/* 4326 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4328 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 4330 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4332 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4334 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4336 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter timeStamp */

/* 4338 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4340 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4342 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter traceCount */

/* 4344 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4346 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4348 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter traceThreadId */

/* 4350 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4352 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4354 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4356 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4358 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4360 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetOutputFormat */

/* 4362 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4364 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4368 */	NdrFcShort( 0xb ),	/* 11 */
/* 4370 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 4372 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4374 */	NdrFcShort( 0x5c ),	/* 92 */
/* 4376 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 4378 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4380 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4382 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4384 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pTimeStamp */

/* 4386 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4388 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4390 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pTraceCount */

/* 4392 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4394 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4396 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pTraceThreadId */

/* 4398 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4400 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4402 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4404 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4406 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4408 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetTraceFileControls */

/* 4410 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4412 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4416 */	NdrFcShort( 0xc ),	/* 12 */
/* 4418 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 4420 */	NdrFcShort( 0x18 ),	/* 24 */
/* 4422 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4424 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 4426 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4428 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4430 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4432 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter traceFileName */

/* 4434 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 4436 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4438 */	NdrFcShort( 0x2ac ),	/* Type Offset=684 */

	/* Parameter commitEachEntry */

/* 4440 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4442 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4444 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter maxTraceFileSize */

/* 4446 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4448 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4450 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter traceFileCopyName */

/* 4452 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 4454 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 4456 */	NdrFcShort( 0x2ac ),	/* Type Offset=684 */

	/* Return value */

/* 4458 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4460 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4462 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetTraceFileControls */

/* 4464 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4466 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4470 */	NdrFcShort( 0xd ),	/* 13 */
/* 4472 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4474 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4476 */	NdrFcShort( 0x48 ),	/* 72 */
/* 4478 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x5,		/* 5 */
/* 4480 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4482 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4484 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4486 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter traceFileName */

/* 4488 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 4490 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4492 */	NdrFcShort( 0x2c0 ),	/* Type Offset=704 */

	/* Parameter pCommitEachEntry */

/* 4494 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4496 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4498 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pMaxTraceFileSize */

/* 4500 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4502 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4504 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter traceFileCopyName */

/* 4506 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 4508 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4510 */	NdrFcShort( 0x2c0 ),	/* Type Offset=704 */

	/* Return value */

/* 4512 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4514 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 4516 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetTraceEntryExit */

/* 4518 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4520 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4524 */	NdrFcShort( 0xf ),	/* 15 */
/* 4526 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4528 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4530 */	NdrFcShort( 0x24 ),	/* 36 */
/* 4532 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4534 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4536 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4538 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4540 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pTraceEntryExit */

/* 4542 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4544 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4546 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4548 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4550 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4552 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetLogLevel */

/* 4554 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4556 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4560 */	NdrFcShort( 0x10 ),	/* 16 */
/* 4562 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4564 */	NdrFcShort( 0x6 ),	/* 6 */
/* 4566 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4568 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4570 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4572 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4574 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4576 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter traceError */

/* 4578 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4580 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4582 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 4584 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4586 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4588 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetLogLevel */

/* 4590 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4592 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4596 */	NdrFcShort( 0x11 ),	/* 17 */
/* 4598 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4600 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4602 */	NdrFcShort( 0x22 ),	/* 34 */
/* 4604 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4606 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4608 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4610 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4612 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pTraceError */

/* 4614 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4616 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4618 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 4620 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4622 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4624 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Print */

/* 4626 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4628 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4632 */	NdrFcShort( 0x12 ),	/* 18 */
/* 4634 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4636 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4638 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4640 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 4642 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4644 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4646 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4648 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter traceString */

/* 4650 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 4652 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4654 */	NdrFcShort( 0x2ac ),	/* Type Offset=684 */

	/* Return value */

/* 4656 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4658 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4660 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetRegistryEntry */

/* 4662 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4664 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4668 */	NdrFcShort( 0x13 ),	/* 19 */
/* 4670 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4672 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4674 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4676 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 4678 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4680 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4682 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4684 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pRegistryEntry */

/* 4686 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 4688 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4690 */	NdrFcShort( 0x2c0 ),	/* Type Offset=704 */

	/* Return value */

/* 4692 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4694 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4696 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetRegistryEntry */

/* 4698 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4700 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4704 */	NdrFcShort( 0x14 ),	/* 20 */
/* 4706 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4708 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4710 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4712 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 4714 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4716 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4718 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4720 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pRegistryEntry */

/* 4722 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 4724 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4726 */	NdrFcShort( 0x2ac ),	/* Type Offset=684 */

	/* Return value */

/* 4728 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4730 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4732 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetTraceSettings */

/* 4734 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4736 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4740 */	NdrFcShort( 0x16 ),	/* 22 */
/* 4742 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4744 */	NdrFcShort( 0x10 ),	/* 16 */
/* 4746 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4748 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4750 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4752 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4754 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4756 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter traceElements */

/* 4758 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4760 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4762 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 4764 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4766 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4768 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetLogSnapShot */

/* 4770 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4772 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4776 */	NdrFcShort( 0x17 ),	/* 23 */
/* 4778 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4780 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4782 */	NdrFcShort( 0x5a ),	/* 90 */
/* 4784 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x5,		/* 5 */
/* 4786 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4788 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4790 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4792 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pOn */

/* 4794 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4796 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4798 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pLevel */

/* 4800 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4802 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4804 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pSnapShotPath */

/* 4806 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 4808 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4810 */	NdrFcShort( 0x2c0 ),	/* Type Offset=704 */

	/* Parameter pResetTrace */

/* 4812 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4814 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4816 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4818 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4820 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 4822 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetLogSnapShot */

/* 4824 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4826 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4830 */	NdrFcShort( 0x18 ),	/* 24 */
/* 4832 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 4834 */	NdrFcShort( 0x16 ),	/* 22 */
/* 4836 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4838 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 4840 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4842 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4844 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4846 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter on */

/* 4848 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4850 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4852 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter level */

/* 4854 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4856 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4858 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter snapShotPath */

/* 4860 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 4862 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4864 */	NdrFcShort( 0x2ac ),	/* Type Offset=684 */

	/* Parameter resetTrace */

/* 4866 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4868 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4870 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4872 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4874 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 4876 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDbPathAndName */

/* 4878 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4880 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4884 */	NdrFcShort( 0x3 ),	/* 3 */
/* 4886 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4888 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4890 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4892 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 4894 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4896 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4898 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4900 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pDbPathAndName */

/* 4902 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 4904 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4906 */	NdrFcShort( 0x2c0 ),	/* Type Offset=704 */

	/* Parameter bufferSize */

/* 4908 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4910 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4912 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4914 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4916 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4918 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetId */

/* 4920 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4922 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4926 */	NdrFcShort( 0x4 ),	/* 4 */
/* 4928 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4930 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4932 */	NdrFcShort( 0x4c ),	/* 76 */
/* 4934 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4936 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4938 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4940 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4942 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */

/* 4944 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 4946 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4948 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Return value */

/* 4950 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4952 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4954 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetRegistryName */

/* 4956 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4958 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4962 */	NdrFcShort( 0x5 ),	/* 5 */
/* 4964 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 4966 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4968 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4970 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 4972 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4974 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4976 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4978 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pRegistryName */

/* 4980 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 4982 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 4984 */	NdrFcShort( 0x2c0 ),	/* Type Offset=704 */

	/* Parameter bufferSize */

/* 4986 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4988 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 4990 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4992 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4994 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 4996 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetBuildVersion */

/* 4998 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5000 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5004 */	NdrFcShort( 0x6 ),	/* 6 */
/* 5006 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5008 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5010 */	NdrFcShort( 0x24 ),	/* 36 */
/* 5012 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5014 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5016 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5018 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5020 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pBuildVersion */

/* 5022 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5024 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5026 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5028 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5030 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5032 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetNtProductVersion */

/* 5034 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5036 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5040 */	NdrFcShort( 0x7 ),	/* 7 */
/* 5042 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 5044 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5046 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5048 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 5050 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5052 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5054 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5056 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pNtProductVersion */

/* 5058 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 5060 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5062 */	NdrFcShort( 0x2c0 ),	/* Type Offset=704 */

	/* Parameter bufferSize */

/* 5064 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5066 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5068 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5070 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5072 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5074 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetNtProductBuild */

/* 5076 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5078 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5082 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5084 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5086 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5088 */	NdrFcShort( 0x24 ),	/* 36 */
/* 5090 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5092 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5094 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5096 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5098 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pNtProductBuild */

/* 5100 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5102 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5104 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5106 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5108 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5110 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetId */

/* 5112 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5114 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5118 */	NdrFcShort( 0xb ),	/* 11 */
/* 5120 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
/* 5122 */	NdrFcShort( 0x30 ),	/* 48 */
/* 5124 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5126 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5128 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5130 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5132 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5134 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter id */

/* 5136 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 5138 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5140 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Return value */

/* 5142 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5144 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 5146 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CheckAccess */

/* 5148 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5150 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5154 */	NdrFcShort( 0xe ),	/* 14 */
/* 5156 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5158 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5160 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5162 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5164 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5166 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5168 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5170 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter AccessType */

/* 5172 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5174 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5176 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 5178 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5180 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5182 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetTrace */

/* 5184 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5186 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5190 */	NdrFcShort( 0xf ),	/* 15 */
/* 5192 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5194 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5196 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5198 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 5200 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5202 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5204 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5206 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppTrace */

/* 5208 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 5210 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5212 */	NdrFcShort( 0x346 ),	/* Type Offset=838 */

	/* Return value */

/* 5214 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5216 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5218 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetTrace */

/* 5220 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5222 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5226 */	NdrFcShort( 0x10 ),	/* 16 */
/* 5228 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5230 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5232 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5234 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 5236 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5238 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5240 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5242 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pTrace */

/* 5244 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5246 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5248 */	NdrFcShort( 0x34a ),	/* Type Offset=842 */

	/* Return value */

/* 5250 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5252 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5254 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ChangeSysState */

/* 5256 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5258 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5262 */	NdrFcShort( 0x3 ),	/* 3 */
/* 5264 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 5266 */	NdrFcShort( 0x28 ),	/* 40 */
/* 5268 */	NdrFcShort( 0x30 ),	/* 48 */
/* 5270 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5272 */	0x8,		/* 8 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5274 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5276 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5278 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSysState */

/* 5280 */	NdrFcShort( 0x11a ),	/* Flags:  must free, in, out, simple ref, */
/* 5282 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 5284 */	NdrFcShort( 0x360 ),	/* Type Offset=864 */

	/* Return value */

/* 5286 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5288 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 5290 */	0x8,		/* FC_LONG */
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
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/*  4 */	NdrFcLong( 0x0 ),	/* 0 */
/*  8 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 14 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 16 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 18 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 20 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 22 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 24 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 26 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 28 */	
			0x11, 0x0,	/* FC_RP */
/* 30 */	NdrFcShort( 0x8 ),	/* Offset= 8 (38) */
/* 32 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 34 */	NdrFcShort( 0x8 ),	/* 8 */
/* 36 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 38 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 40 */	NdrFcShort( 0x10 ),	/* 16 */
/* 42 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 44 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 46 */	0x0,		/* 0 */
			NdrFcShort( 0xfff1 ),	/* Offset= -15 (32) */
			0x5b,		/* FC_END */
/* 50 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 52 */	NdrFcShort( 0x2 ),	/* Offset= 2 (54) */
/* 54 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 56 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 58 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 60 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 62 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 64 */	NdrFcShort( 0x2 ),	/* Offset= 2 (66) */
/* 66 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 68 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 70 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 72 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 74 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 76 */	NdrFcShort( 0x2 ),	/* Offset= 2 (78) */
/* 78 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 80 */	NdrFcLong( 0x9c7d6f14 ),	/* -1669501164 */
/* 84 */	NdrFcShort( 0x1562 ),	/* 5474 */
/* 86 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 88 */	0x81,		/* 129 */
			0xac,		/* 172 */
/* 90 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 92 */	0xc9,		/* 201 */
			0x11,		/* 17 */
/* 94 */	0x80,		/* 128 */
			0xf2,		/* 242 */
/* 96 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 98 */	NdrFcShort( 0x2 ),	/* Offset= 2 (100) */
/* 100 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 102 */	NdrFcLong( 0x100 ),	/* 256 */
/* 106 */	NdrFcShort( 0x0 ),	/* 0 */
/* 108 */	NdrFcShort( 0x0 ),	/* 0 */
/* 110 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 112 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 114 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 116 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 118 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 120 */	NdrFcShort( 0x2 ),	/* Offset= 2 (122) */
/* 122 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 124 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 126 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 128 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 130 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 132 */	NdrFcShort( 0x2 ),	/* Offset= 2 (134) */
/* 134 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 136 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 138 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 140 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 142 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 144 */	NdrFcShort( 0x2 ),	/* Offset= 2 (146) */
/* 146 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 148 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 150 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 152 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 154 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 156 */	NdrFcShort( 0x2 ),	/* Offset= 2 (158) */
/* 158 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 160 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 162 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 164 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 166 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 168 */	NdrFcShort( 0x2 ),	/* Offset= 2 (170) */
/* 170 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 172 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 174 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 176 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 178 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 180 */	NdrFcShort( 0x2 ),	/* Offset= 2 (182) */
/* 182 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 184 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 186 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 188 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 190 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 192 */	NdrFcShort( 0x2 ),	/* Offset= 2 (194) */
/* 194 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 196 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 198 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 200 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 202 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 204 */	NdrFcShort( 0x2 ),	/* Offset= 2 (206) */
/* 206 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 208 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 210 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 212 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 214 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 216 */	NdrFcLong( 0x9c7d6f0f ),	/* -1669501169 */
/* 220 */	NdrFcShort( 0x1562 ),	/* 5474 */
/* 222 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 224 */	0x81,		/* 129 */
			0xac,		/* 172 */
/* 226 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 228 */	0xc9,		/* 201 */
			0x11,		/* 17 */
/* 230 */	0x80,		/* 128 */
			0xf2,		/* 242 */
/* 232 */	
			0x11, 0x0,	/* FC_RP */
/* 234 */	NdrFcShort( 0xa ),	/* Offset= 10 (244) */
/* 236 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 238 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 240 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 242 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 244 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 246 */	NdrFcShort( 0x0 ),	/* 0 */
/* 248 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 250 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 252 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 254 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 256 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 258 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 260 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 262 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (236) */
/* 264 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 266 */	
			0x11, 0x0,	/* FC_RP */
/* 268 */	NdrFcShort( 0xa ),	/* Offset= 10 (278) */
/* 270 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 272 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 274 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 276 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 278 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 280 */	NdrFcShort( 0x0 ),	/* 0 */
/* 282 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 284 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 286 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 288 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 290 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 292 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 294 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 296 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (270) */
/* 298 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 300 */	
			0x11, 0x0,	/* FC_RP */
/* 302 */	NdrFcShort( 0xa ),	/* Offset= 10 (312) */
/* 304 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 306 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 308 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 310 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 312 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 314 */	NdrFcShort( 0x0 ),	/* 0 */
/* 316 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 318 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 320 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 322 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 324 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 326 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 328 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 330 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (304) */
/* 332 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 334 */	
			0x11, 0x0,	/* FC_RP */
/* 336 */	NdrFcShort( 0xa ),	/* Offset= 10 (346) */
/* 338 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 340 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 342 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 344 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 346 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 348 */	NdrFcShort( 0x0 ),	/* 0 */
/* 350 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 352 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 354 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 356 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 358 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 360 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 362 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 364 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (338) */
/* 366 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 368 */	
			0x11, 0x0,	/* FC_RP */
/* 370 */	NdrFcShort( 0xa ),	/* Offset= 10 (380) */
/* 372 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 374 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 376 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 378 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 380 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 382 */	NdrFcShort( 0x0 ),	/* 0 */
/* 384 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 386 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 388 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 390 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 392 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 394 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 396 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 398 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (372) */
/* 400 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 402 */	
			0x11, 0x0,	/* FC_RP */
/* 404 */	NdrFcShort( 0xa ),	/* Offset= 10 (414) */
/* 406 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 408 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 410 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 412 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 414 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 416 */	NdrFcShort( 0x0 ),	/* 0 */
/* 418 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 420 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 422 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 424 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 426 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 428 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 430 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 432 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (406) */
/* 434 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 436 */	
			0x11, 0x0,	/* FC_RP */
/* 438 */	NdrFcShort( 0xa ),	/* Offset= 10 (448) */
/* 440 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 442 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 444 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 446 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 448 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 450 */	NdrFcShort( 0x0 ),	/* 0 */
/* 452 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 454 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 456 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 458 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 460 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 462 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 464 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 466 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (440) */
/* 468 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 470 */	
			0x11, 0x0,	/* FC_RP */
/* 472 */	NdrFcShort( 0xa ),	/* Offset= 10 (482) */
/* 474 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 476 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 478 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 480 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 482 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 484 */	NdrFcShort( 0x0 ),	/* 0 */
/* 486 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 488 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 490 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 492 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 494 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 496 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 498 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 500 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (474) */
/* 502 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 504 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 506 */	NdrFcLong( 0xa0ff1f41 ),	/* -1593893055 */
/* 510 */	NdrFcShort( 0x237a ),	/* 9082 */
/* 512 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 514 */	0x81,		/* 129 */
			0xba,		/* 186 */
/* 516 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 518 */	0xc9,		/* 201 */
			0x11,		/* 17 */
/* 520 */	0x80,		/* 128 */
			0xf2,		/* 242 */
/* 522 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 524 */	NdrFcShort( 0xfe1a ),	/* Offset= -486 (38) */
/* 526 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 528 */	NdrFcShort( 0x2 ),	/* Offset= 2 (530) */
/* 530 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 532 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 534 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 536 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 538 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 540 */	NdrFcShort( 0x2 ),	/* Offset= 2 (542) */
/* 542 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 544 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 546 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 548 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 550 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 552 */	NdrFcShort( 0x2 ),	/* Offset= 2 (554) */
/* 554 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 556 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 558 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 560 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 562 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 564 */	NdrFcShort( 0x2 ),	/* Offset= 2 (566) */
/* 566 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 568 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 570 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 572 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 574 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 576 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 578 */	
			0x11, 0x0,	/* FC_RP */
/* 580 */	NdrFcShort( 0xa ),	/* Offset= 10 (590) */
/* 582 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 584 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 586 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 588 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 590 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 592 */	NdrFcShort( 0x0 ),	/* 0 */
/* 594 */	0x20,		/* Corr desc:  parameter,  */
			0x59,		/* FC_CALLBACK */
/* 596 */	NdrFcShort( 0x0 ),	/* 0 */
/* 598 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 600 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 602 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 604 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 606 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 608 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (582) */
/* 610 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 612 */	
			0x11, 0x0,	/* FC_RP */
/* 614 */	NdrFcShort( 0xa ),	/* Offset= 10 (624) */
/* 616 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 618 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 620 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
/* 622 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 624 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 626 */	NdrFcShort( 0x0 ),	/* 0 */
/* 628 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 630 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
/* 632 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 634 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 636 */	NdrFcShort( 0x1c ),	/* x86 Stack size/offset = 28 */
/* 638 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 640 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 642 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (616) */
/* 644 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 646 */	
			0x11, 0x0,	/* FC_RP */
/* 648 */	NdrFcShort( 0x2 ),	/* Offset= 2 (650) */
/* 650 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 652 */	NdrFcShort( 0x4 ),	/* 4 */
/* 654 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 656 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 658 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 660 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 662 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 664 */	NdrFcShort( 0x4 ),	/* 4 */
/* 666 */	NdrFcShort( 0x0 ),	/* 0 */
/* 668 */	NdrFcShort( 0x1 ),	/* 1 */
/* 670 */	NdrFcShort( 0x0 ),	/* 0 */
/* 672 */	NdrFcShort( 0x0 ),	/* 0 */
/* 674 */	0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 676 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 678 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 680 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 682 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 684 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 686 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 688 */	NdrFcLong( 0xdb35d731 ),	/* -617228495 */
/* 692 */	NdrFcShort( 0x21e9 ),	/* 8681 */
/* 694 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 696 */	0x81,		/* 129 */
			0xb8,		/* 184 */
/* 698 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 700 */	0xc9,		/* 201 */
			0x11,		/* 17 */
/* 702 */	0x80,		/* 128 */
			0xf2,		/* 242 */
/* 704 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 706 */	NdrFcShort( 0x2 ),	/* Offset= 2 (708) */
/* 708 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 710 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 712 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 714 */	NdrFcShort( 0x2 ),	/* Offset= 2 (716) */
/* 716 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 718 */	NdrFcLong( 0x1973831 ),	/* 26687537 */
/* 722 */	NdrFcShort( 0xe996 ),	/* -5738 */
/* 724 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 726 */	0x99,		/* 153 */
			0x28,		/* 40 */
/* 728 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 730 */	0xc9,		/* 201 */
			0x5,		/* 5 */
/* 732 */	0x8b,		/* 139 */
			0xf6,		/* 246 */
/* 734 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 736 */	NdrFcShort( 0x2 ),	/* Offset= 2 (738) */
/* 738 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 740 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 742 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
/* 744 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 746 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 748 */	NdrFcShort( 0xffe0 ),	/* Offset= -32 (716) */
/* 750 */	
			0x11, 0x0,	/* FC_RP */
/* 752 */	NdrFcShort( 0x2 ),	/* Offset= 2 (754) */
/* 754 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 756 */	NdrFcShort( 0x1 ),	/* 1 */
/* 758 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 760 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 762 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 764 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 766 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 768 */	NdrFcShort( 0x8 ),	/* 8 */
/* 770 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 772 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 774 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 776 */	NdrFcShort( 0x2 ),	/* Offset= 2 (778) */
/* 778 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 780 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 782 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
/* 784 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 786 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 788 */	NdrFcLong( 0xc ),	/* 12 */
/* 792 */	NdrFcShort( 0x0 ),	/* 0 */
/* 794 */	NdrFcShort( 0x0 ),	/* 0 */
/* 796 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 798 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 800 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 802 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 804 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 806 */	NdrFcLong( 0x46ce9eda ),	/* 1187946202 */
/* 810 */	NdrFcShort( 0x447c ),	/* 17532 */
/* 812 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 814 */	0x98,		/* 152 */
			0xfc,		/* 252 */
/* 816 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 818 */	0xc9,		/* 201 */
			0x5,		/* 5 */
/* 820 */	0x8b,		/* 139 */
			0xf6,		/* 246 */
/* 822 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 824 */	NdrFcShort( 0x2 ),	/* Offset= 2 (826) */
/* 826 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 828 */	0x28,		/* Corr desc:  parameter, FC_LONG */
			0x0,		/*  */
/* 830 */	NdrFcShort( 0x8 ),	/* x86 Stack size/offset = 8 */
/* 832 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 834 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 836 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */
/* 838 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 840 */	NdrFcShort( 0x2 ),	/* Offset= 2 (842) */
/* 842 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 844 */	NdrFcLong( 0xaf2da10 ),	/* 183687696 */
/* 848 */	NdrFcShort( 0x7dd7 ),	/* 32215 */
/* 850 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 852 */	0x9e,		/* 158 */
			0x33,		/* 51 */
/* 854 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 856 */	0xc9,		/* 201 */
			0x16,		/* 22 */
/* 858 */	0xf1,		/* 241 */
			0x20,		/* 32 */
/* 860 */	
			0x11, 0x0,	/* FC_RP */
/* 862 */	NdrFcShort( 0x2 ),	/* Offset= 2 (864) */
/* 864 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 866 */	NdrFcShort( 0x4 ),	/* 4 */
/* 868 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */

			0x0
        }
    };

static void __RPC_USER IWsbIndexedCollection_CopyExprEval_0000( PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(4)
    struct _PARAM_STRUCT
        {
        IHsmEvent *This;
        ULONG start;
        ULONG stop;
        REFIID riid;
        void **elements;
        ULONG *pElementsFetched;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT *pS	=	( struct _PARAM_STRUCT * )pStubMsg->StackTop;
    
    pStubMsg->Offset = 0;
    pStubMsg->MaxCount = ( unsigned long ) ( pS->stop > pS->start ? pS->stop - pS->start : pS->start - pS->stop );
}

static const EXPR_EVAL ExprEvalRoutines[] = 
    {
    IWsbIndexedCollection_CopyExprEval_0000
    };



/* Standard interface: __MIDL_itf_wsbint_0000, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IWsbCollectable, ver. 0.0,
   GUID={0x9C7D6F0A,0x1562,0x11D0,{0x81,0xAC,0x00,0xA0,0xC9,0x11,0x80,0xF2}} */

#pragma code_seg(".orpc")
static const unsigned short IWsbCollectable_FormatStringOffsetTable[] =
    {
    0,
    42
    };

static const MIDL_STUBLESS_PROXY_INFO IWsbCollectable_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IWsbCollectable_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWsbCollectable_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IWsbCollectable_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(5) _IWsbCollectableProxyVtbl = 
{
    &IWsbCollectable_ProxyInfo,
    &IID_IWsbCollectable,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWsbCollectable::CompareTo */ ,
    (void *) (INT_PTR) -1 /* IWsbCollectable::IsEqual */
};

const CInterfaceStubVtbl _IWsbCollectableStubVtbl =
{
    &IID_IWsbCollectable,
    &IWsbCollectable_ServerInfo,
    5,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWsbCollection, ver. 0.0,
   GUID={0x9C7D6F0F,0x1562,0x11D0,{0x81,0xAC,0x00,0xA0,0xC9,0x11,0x80,0xF2}} */

#pragma code_seg(".orpc")
static const unsigned short IWsbCollection_FormatStringOffsetTable[] =
    {
    78,
    42,
    114,
    150,
    198,
    228,
    258,
    288,
    330,
    378,
    414,
    444,
    474,
    510
    };

static const MIDL_STUBLESS_PROXY_INFO IWsbCollection_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IWsbCollection_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWsbCollection_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IWsbCollection_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(17) _IWsbCollectionProxyVtbl = 
{
    &IWsbCollection_ProxyInfo,
    &IID_IWsbCollection,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWsbCollection::Add */ ,
    (void *) (INT_PTR) -1 /* IWsbCollection::Contains */ ,
    (void *) (INT_PTR) -1 /* IWsbCollection::GetEntries */ ,
    (void *) (INT_PTR) -1 /* IWsbCollection::Find */ ,
    (void *) (INT_PTR) -1 /* IWsbCollection::IsEmpty */ ,
    (void *) (INT_PTR) -1 /* IWsbCollection::IsLocked */ ,
    (void *) (INT_PTR) -1 /* IWsbCollection::Lock */ ,
    (void *) (INT_PTR) -1 /* IWsbCollection::OccurencesOf */ ,
    (void *) (INT_PTR) -1 /* IWsbCollection::Remove */ ,
    (void *) (INT_PTR) -1 /* IWsbCollection::RemoveAndRelease */ ,
    (void *) (INT_PTR) -1 /* IWsbCollection::RemoveAllAndRelease */ ,
    (void *) (INT_PTR) -1 /* IWsbCollection::Unlock */ ,
    (void *) (INT_PTR) -1 /* IWsbCollection::Enum */ ,
    (void *) (INT_PTR) -1 /* IWsbCollection::EnumUnknown */
};

const CInterfaceStubVtbl _IWsbCollectionStubVtbl =
{
    &IID_IWsbCollection,
    &IWsbCollection_ServerInfo,
    17,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWsbEnum, ver. 0.0,
   GUID={0x9C7D6F14,0x1562,0x11D0,{0x81,0xAC,0x00,0xA0,0xC9,0x11,0x80,0xF2}} */

#pragma code_seg(".orpc")
static const unsigned short IWsbEnum_FormatStringOffsetTable[] =
    {
    546,
    588,
    630,
    672,
    714,
    756,
    804,
    852,
    900,
    930,
    966,
    1002,
    1038,
    1068,
    1098,
    1134
    };

static const MIDL_STUBLESS_PROXY_INFO IWsbEnum_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IWsbEnum_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWsbEnum_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IWsbEnum_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(19) _IWsbEnumProxyVtbl = 
{
    &IWsbEnum_ProxyInfo,
    &IID_IWsbEnum,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWsbEnum::First */ ,
    (void *) (INT_PTR) -1 /* IWsbEnum::Next */ ,
    (void *) (INT_PTR) -1 /* IWsbEnum::This */ ,
    (void *) (INT_PTR) -1 /* IWsbEnum::Previous */ ,
    (void *) (INT_PTR) -1 /* IWsbEnum::Last */ ,
    (void *) (INT_PTR) -1 /* IWsbEnum::FindNext */ ,
    (void *) (INT_PTR) -1 /* IWsbEnum::Find */ ,
    (void *) (INT_PTR) -1 /* IWsbEnum::FindPrevious */ ,
    (void *) (INT_PTR) -1 /* IWsbEnum::SkipToFirst */ ,
    (void *) (INT_PTR) -1 /* IWsbEnum::SkipNext */ ,
    (void *) (INT_PTR) -1 /* IWsbEnum::SkipTo */ ,
    (void *) (INT_PTR) -1 /* IWsbEnum::SkipPrevious */ ,
    (void *) (INT_PTR) -1 /* IWsbEnum::SkipToLast */ ,
    (void *) (INT_PTR) -1 /* IWsbEnum::Reset */ ,
    (void *) (INT_PTR) -1 /* IWsbEnum::Init */ ,
    (void *) (INT_PTR) -1 /* IWsbEnum::Clone */
};

const CInterfaceStubVtbl _IWsbEnumStubVtbl =
{
    &IID_IWsbEnum,
    &IWsbEnum_ServerInfo,
    19,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWsbEnumEx, ver. 0.0,
   GUID={0xF5A3AC60,0x9993,0x11d0,{0x81,0xE7,0x00,0xA0,0xC9,0x11,0x80,0xF2}} */

#pragma code_seg(".orpc")
static const unsigned short IWsbEnumEx_FormatStringOffsetTable[] =
    {
    1170,
    1224,
    1278,
    1332,
    1386,
    1440,
    1500,
    1560,
    900,
    930,
    966,
    1002,
    1038,
    1068,
    1098,
    1134
    };

static const MIDL_STUBLESS_PROXY_INFO IWsbEnumEx_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IWsbEnumEx_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWsbEnumEx_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IWsbEnumEx_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(19) _IWsbEnumExProxyVtbl = 
{
    &IWsbEnumEx_ProxyInfo,
    &IID_IWsbEnumEx,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWsbEnumEx::First */ ,
    (void *) (INT_PTR) -1 /* IWsbEnumEx::Next */ ,
    (void *) (INT_PTR) -1 /* IWsbEnumEx::This */ ,
    (void *) (INT_PTR) -1 /* IWsbEnumEx::Previous */ ,
    (void *) (INT_PTR) -1 /* IWsbEnumEx::Last */ ,
    (void *) (INT_PTR) -1 /* IWsbEnumEx::FindNext */ ,
    (void *) (INT_PTR) -1 /* IWsbEnumEx::Find */ ,
    (void *) (INT_PTR) -1 /* IWsbEnumEx::FindPrevious */ ,
    (void *) (INT_PTR) -1 /* IWsbEnumEx::SkipToFirst */ ,
    (void *) (INT_PTR) -1 /* IWsbEnumEx::SkipNext */ ,
    (void *) (INT_PTR) -1 /* IWsbEnumEx::SkipTo */ ,
    (void *) (INT_PTR) -1 /* IWsbEnumEx::SkipPrevious */ ,
    (void *) (INT_PTR) -1 /* IWsbEnumEx::SkipToLast */ ,
    (void *) (INT_PTR) -1 /* IWsbEnumEx::Reset */ ,
    (void *) (INT_PTR) -1 /* IWsbEnumEx::Init */ ,
    (void *) (INT_PTR) -1 /* IWsbEnumEx::Clone */
};

const CInterfaceStubVtbl _IWsbEnumExStubVtbl =
{
    &IID_IWsbEnumEx,
    &IWsbEnumEx_ServerInfo,
    19,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWsbGuid, ver. 0.0,
   GUID={0xA0FF1F41,0x237A,0x11D0,{0x81,0xBA,0x00,0xA0,0xC9,0x11,0x80,0xF2}} */

#pragma code_seg(".orpc")
static const unsigned short IWsbGuid_FormatStringOffsetTable[] =
    {
    0,
    42,
    1620,
    1662,
    1704,
    1740
    };

static const MIDL_STUBLESS_PROXY_INFO IWsbGuid_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IWsbGuid_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWsbGuid_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IWsbGuid_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(9) _IWsbGuidProxyVtbl = 
{
    &IWsbGuid_ProxyInfo,
    &IID_IWsbGuid,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWsbCollectable::CompareTo */ ,
    (void *) (INT_PTR) -1 /* IWsbCollectable::IsEqual */ ,
    (void *) (INT_PTR) -1 /* IWsbGuid::CompareToGuid */ ,
    (void *) (INT_PTR) -1 /* IWsbGuid::CompareToIGuid */ ,
    (void *) (INT_PTR) -1 /* IWsbGuid::GetGuid */ ,
    (void *) (INT_PTR) -1 /* IWsbGuid::SetGuid */
};

const CInterfaceStubVtbl _IWsbGuidStubVtbl =
{
    &IID_IWsbGuid,
    &IWsbGuid_ServerInfo,
    9,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWsbIndexedCollection, ver. 0.0,
   GUID={0xA5B69200,0x214B,0x11D0,{0x81,0xB7,0x00,0xA0,0xC9,0x11,0x80,0xF2}} */

#pragma code_seg(".orpc")
static const unsigned short IWsbIndexedCollection_FormatStringOffsetTable[] =
    {
    78,
    42,
    114,
    150,
    198,
    228,
    258,
    288,
    330,
    378,
    414,
    444,
    474,
    510,
    1776,
    1818,
    1854,
    1890,
    1938,
    1980,
    2028,
    2070,
    2112,
    2172
    };

static const MIDL_STUBLESS_PROXY_INFO IWsbIndexedCollection_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IWsbIndexedCollection_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWsbIndexedCollection_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IWsbIndexedCollection_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(27) _IWsbIndexedCollectionProxyVtbl = 
{
    &IWsbIndexedCollection_ProxyInfo,
    &IID_IWsbIndexedCollection,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWsbCollection::Add */ ,
    (void *) (INT_PTR) -1 /* IWsbCollection::Contains */ ,
    (void *) (INT_PTR) -1 /* IWsbCollection::GetEntries */ ,
    (void *) (INT_PTR) -1 /* IWsbCollection::Find */ ,
    (void *) (INT_PTR) -1 /* IWsbCollection::IsEmpty */ ,
    (void *) (INT_PTR) -1 /* IWsbCollection::IsLocked */ ,
    (void *) (INT_PTR) -1 /* IWsbCollection::Lock */ ,
    (void *) (INT_PTR) -1 /* IWsbCollection::OccurencesOf */ ,
    (void *) (INT_PTR) -1 /* IWsbCollection::Remove */ ,
    (void *) (INT_PTR) -1 /* IWsbCollection::RemoveAndRelease */ ,
    (void *) (INT_PTR) -1 /* IWsbCollection::RemoveAllAndRelease */ ,
    (void *) (INT_PTR) -1 /* IWsbCollection::Unlock */ ,
    (void *) (INT_PTR) -1 /* IWsbCollection::Enum */ ,
    (void *) (INT_PTR) -1 /* IWsbCollection::EnumUnknown */ ,
    (void *) (INT_PTR) -1 /* IWsbIndexedCollection::AddAt */ ,
    (void *) (INT_PTR) -1 /* IWsbIndexedCollection::Append */ ,
    (void *) (INT_PTR) -1 /* IWsbIndexedCollection::Prepend */ ,
    (void *) (INT_PTR) -1 /* IWsbIndexedCollection::RemoveAt */ ,
    (void *) (INT_PTR) -1 /* IWsbIndexedCollection::First */ ,
    (void *) (INT_PTR) -1 /* IWsbIndexedCollection::At */ ,
    (void *) (INT_PTR) -1 /* IWsbIndexedCollection::Last */ ,
    (void *) (INT_PTR) -1 /* IWsbIndexedCollection::Index */ ,
    (void *) (INT_PTR) -1 /* IWsbIndexedCollection::Copy */ ,
    (void *) (INT_PTR) -1 /* IWsbIndexedCollection::CopyIfMatches */
};

const CInterfaceStubVtbl _IWsbIndexedCollectionStubVtbl =
{
    &IID_IWsbIndexedCollection,
    &IWsbIndexedCollection_ServerInfo,
    27,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWsbPersistStream, ver. 0.0,
   GUID={0xC4D14AA2,0x79EE,0x11D0,{0x99,0x09,0x00,0xA0,0xC9,0x05,0x8B,0xF6}} */

#pragma code_seg(".orpc")
static const unsigned short IWsbPersistStream_FormatStringOffsetTable[] =
    {
    2250
    };

static const MIDL_STUBLESS_PROXY_INFO IWsbPersistStream_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IWsbPersistStream_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWsbPersistStream_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IWsbPersistStream_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IWsbPersistStreamProxyVtbl = 
{
    &IWsbPersistStream_ProxyInfo,
    &IID_IWsbPersistStream,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWsbPersistStream::SetIsDirty */
};

const CInterfaceStubVtbl _IWsbPersistStreamStubVtbl =
{
    &IID_IWsbPersistStream,
    &IWsbPersistStream_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWsbPersistable, ver. 0.0,
   GUID={0x5BF46531,0x282D,0x11D0,{0x81,0xBE,0x00,0xA0,0xC9,0x11,0x80,0xF2}} */

#pragma code_seg(".orpc")
static const unsigned short IWsbPersistable_FormatStringOffsetTable[] =
    {
    2250,
    2286,
    2328,
    2358
    };

static const MIDL_STUBLESS_PROXY_INFO IWsbPersistable_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IWsbPersistable_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWsbPersistable_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IWsbPersistable_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(7) _IWsbPersistableProxyVtbl = 
{
    &IWsbPersistable_ProxyInfo,
    &IID_IWsbPersistable,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWsbPersistStream::SetIsDirty */ ,
    (void *) (INT_PTR) -1 /* IWsbPersistable::GetDefaultFileName */ ,
    (void *) (INT_PTR) -1 /* IWsbPersistable::ReleaseFile */ ,
    (void *) (INT_PTR) -1 /* IWsbPersistable::SetDefaultFileName */
};

const CInterfaceStubVtbl _IWsbPersistableStubVtbl =
{
    &IID_IWsbPersistable,
    &IWsbPersistable_ServerInfo,
    7,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWsbString, ver. 0.0,
   GUID={0xDB35D731,0x21E9,0x11D0,{0x81,0xB8,0x00,0xA0,0xC9,0x11,0x80,0xF2}} */

#pragma code_seg(".orpc")
static const unsigned short IWsbString_FormatStringOffsetTable[] =
    {
    0,
    42,
    2394,
    2436,
    2478,
    2520,
    258,
    2568,
    2604,
    2640
    };

static const MIDL_STUBLESS_PROXY_INFO IWsbString_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IWsbString_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWsbString_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IWsbString_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(13) _IWsbStringProxyVtbl = 
{
    &IWsbString_ProxyInfo,
    &IID_IWsbString,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWsbCollectable::CompareTo */ ,
    (void *) (INT_PTR) -1 /* IWsbCollectable::IsEqual */ ,
    (void *) (INT_PTR) -1 /* IWsbString::CompareToString */ ,
    (void *) (INT_PTR) -1 /* IWsbString::CompareToIString */ ,
    (void *) (INT_PTR) -1 /* IWsbString::GetString */ ,
    (void *) (INT_PTR) -1 /* IWsbString::GetStringAndCase */ ,
    (void *) (INT_PTR) -1 /* IWsbString::IsCaseDependent */ ,
    (void *) (INT_PTR) -1 /* IWsbString::SetIsCaseDependent */ ,
    (void *) (INT_PTR) -1 /* IWsbString::SetString */ ,
    (void *) (INT_PTR) -1 /* IWsbString::SetStringAndCase */
};

const CInterfaceStubVtbl _IWsbStringStubVtbl =
{
    &IID_IWsbString,
    &IWsbString_ServerInfo,
    13,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWsbTestable, ver. 0.0,
   GUID={0x05342021,0x25D8,0x11D0,{0x81,0xBB,0x00,0xA0,0xC9,0x11,0x80,0xF2}} */

#pragma code_seg(".orpc")
static const unsigned short IWsbTestable_FormatStringOffsetTable[] =
    {
    2682
    };

static const MIDL_STUBLESS_PROXY_INFO IWsbTestable_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IWsbTestable_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWsbTestable_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IWsbTestable_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IWsbTestableProxyVtbl = 
{
    &IWsbTestable_ProxyInfo,
    &IID_IWsbTestable,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWsbTestable::Test */
};

const CInterfaceStubVtbl _IWsbTestableStubVtbl =
{
    &IID_IWsbTestable,
    &IWsbTestable_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWsbDbSys, ver. 0.0,
   GUID={0xF2608980,0x0A45,0x47B4,{0xB1,0x10,0x37,0xEA,0x59,0xF6,0x7C,0x47}} */

#pragma code_seg(".orpc")
static const unsigned short IWsbDbSys_FormatStringOffsetTable[] =
    {
    2724,
    2766,
    2328,
    2808,
    2844,
    2880,
    258
    };

static const MIDL_STUBLESS_PROXY_INFO IWsbDbSys_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IWsbDbSys_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWsbDbSys_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IWsbDbSys_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(10) _IWsbDbSysProxyVtbl = 
{
    &IWsbDbSys_ProxyInfo,
    &IID_IWsbDbSys,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWsbDbSys::Backup */ ,
    (void *) (INT_PTR) -1 /* IWsbDbSys::Init */ ,
    (void *) (INT_PTR) -1 /* IWsbDbSys::Terminate */ ,
    (void *) (INT_PTR) -1 /* IWsbDbSys::NewSession */ ,
    (void *) (INT_PTR) -1 /* IWsbDbSys::GetGlobalSession */ ,
    (void *) (INT_PTR) -1 /* IWsbDbSys::Restore */ ,
    (void *) (INT_PTR) -1 /* IWsbDbSys::IncrementChangeCount */
};

const CInterfaceStubVtbl _IWsbDbSysStubVtbl =
{
    &IID_IWsbDbSys,
    &IWsbDbSys_ServerInfo,
    10,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWsbDb, ver. 0.0,
   GUID={0xD7A42F4A,0x117C,0x47A3,{0x9C,0x30,0x92,0xD6,0x3A,0x49,0x19,0xE4}} */

#pragma code_seg(".orpc")
static const unsigned short IWsbDb_FormatStringOffsetTable[] =
    {
    2922,
    2766,
    2958,
    3000,
    3048,
    3102,
    3138,
    3174,
    2604,
    3210
    };

static const MIDL_STUBLESS_PROXY_INFO IWsbDb_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IWsbDb_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWsbDb_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IWsbDb_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(13) _IWsbDbProxyVtbl = 
{
    &IWsbDb_ProxyInfo,
    &IID_IWsbDb,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWsbDb::Close */ ,
    (void *) (INT_PTR) -1 /* IWsbDb::Create */ ,
    (void *) (INT_PTR) -1 /* IWsbDb::Delete */ ,
    (void *) (INT_PTR) -1 /* IWsbDb::Dump */ ,
    (void *) (INT_PTR) -1 /* IWsbDb::GetEntity */ ,
    (void *) (INT_PTR) -1 /* IWsbDb::GetName */ ,
    (void *) (INT_PTR) -1 /* IWsbDb::GetPath */ ,
    (void *) (INT_PTR) -1 /* IWsbDb::GetVersion */ ,
    (void *) (INT_PTR) -1 /* IWsbDb::Locate */ ,
    (void *) (INT_PTR) -1 /* IWsbDb::Open */
};

const CInterfaceStubVtbl _IWsbDbStubVtbl =
{
    &IID_IWsbDb,
    &IWsbDb_ServerInfo,
    13,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWsbDbSession, ver. 0.0,
   GUID={0x01973831,0xE996,0x11d0,{0x99,0x28,0x00,0xA0,0xC9,0x05,0x8B,0xF6}} */

#pragma code_seg(".orpc")
static const unsigned short IWsbDbSession_FormatStringOffsetTable[] =
    {
    3246,
    3276,
    2328
    };

static const MIDL_STUBLESS_PROXY_INFO IWsbDbSession_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IWsbDbSession_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWsbDbSession_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IWsbDbSession_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(6) _IWsbDbSessionProxyVtbl = 
{
    &IWsbDbSession_ProxyInfo,
    &IID_IWsbDbSession,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWsbDbSession::TransactionBegin */ ,
    (void *) (INT_PTR) -1 /* IWsbDbSession::TransactionCancel */ ,
    (void *) (INT_PTR) -1 /* IWsbDbSession::TransactionEnd */
};

const CInterfaceStubVtbl _IWsbDbSessionStubVtbl =
{
    &IID_IWsbDbSession,
    &IWsbDbSession_ServerInfo,
    6,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWsbDbKey, ver. 0.0,
   GUID={0x46CE9EDA,0x447C,0x11D0,{0x98,0xFC,0x00,0xA0,0xC9,0x05,0x8B,0xF6}} */

#pragma code_seg(".orpc")
static const unsigned short IWsbDbKey_FormatStringOffsetTable[] =
    {
    2250,
    3306,
    3348,
    3384,
    3420,
    3456,
    3492,
    2568,
    3528,
    3570,
    3606,
    3642,
    3678,
    3714
    };

static const MIDL_STUBLESS_PROXY_INFO IWsbDbKey_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IWsbDbKey_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWsbDbKey_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IWsbDbKey_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(17) _IWsbDbKeyProxyVtbl = 
{
    &IWsbDbKey_ProxyInfo,
    &IID_IWsbDbKey,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWsbDbKey::AppendBool */ ,
    (void *) (INT_PTR) -1 /* IWsbDbKey::AppendBytes */ ,
    (void *) (INT_PTR) -1 /* IWsbDbKey::AppendFiletime */ ,
    (void *) (INT_PTR) -1 /* IWsbDbKey::AppendGuid */ ,
    (void *) (INT_PTR) -1 /* IWsbDbKey::AppendLonglong */ ,
    (void *) (INT_PTR) -1 /* IWsbDbKey::AppendString */ ,
    (void *) (INT_PTR) -1 /* IWsbDbKey::GetType */ ,
    (void *) (INT_PTR) -1 /* IWsbDbKey::SetToBool */ ,
    (void *) (INT_PTR) -1 /* IWsbDbKey::SetToBytes */ ,
    (void *) (INT_PTR) -1 /* IWsbDbKey::SetToFiletime */ ,
    (void *) (INT_PTR) -1 /* IWsbDbKey::SetToGuid */ ,
    (void *) (INT_PTR) -1 /* IWsbDbKey::SetToLonglong */ ,
    (void *) (INT_PTR) -1 /* IWsbDbKey::SetToUlong */ ,
    (void *) (INT_PTR) -1 /* IWsbDbKey::SetToString */
};

const CInterfaceStubVtbl _IWsbDbKeyStubVtbl =
{
    &IID_IWsbDbKey,
    &IWsbDbKey_ServerInfo,
    17,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWsbDbEntity, ver. 0.0,
   GUID={0xFC7FB18F,0xF497,0x47A6,{0xA2,0x8F,0x7C,0xC4,0xBF,0xEC,0xAA,0x5E}} */

#pragma code_seg(".orpc")
static const unsigned short IWsbDbEntity_FormatStringOffsetTable[] =
    {
    3750,
    3276,
    2328,
    3792,
    198,
    228,
    258,
    3822,
    900,
    3852,
    414,
    444,
    3882,
    1068,
    3918,
    3954,
    3990,
    4020,
    4050
    };

static const MIDL_STUBLESS_PROXY_INFO IWsbDbEntity_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IWsbDbEntity_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWsbDbEntity_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IWsbDbEntity_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(22) _IWsbDbEntityProxyVtbl = 
{
    &IWsbDbEntity_ProxyInfo,
    &IID_IWsbDbEntity,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWsbDbEntity::Clone */ ,
    (void *) (INT_PTR) -1 /* IWsbDbEntity::Disconnect */ ,
    (void *) (INT_PTR) -1 /* IWsbDbEntity::FindEQ */ ,
    (void *) (INT_PTR) -1 /* IWsbDbEntity::FindGT */ ,
    (void *) (INT_PTR) -1 /* IWsbDbEntity::FindGTE */ ,
    (void *) (INT_PTR) -1 /* IWsbDbEntity::FindLT */ ,
    (void *) (INT_PTR) -1 /* IWsbDbEntity::FindLTE */ ,
    (void *) (INT_PTR) -1 /* IWsbDbEntity::First */ ,
    (void *) (INT_PTR) -1 /* IWsbDbEntity::Last */ ,
    (void *) (INT_PTR) -1 /* IWsbDbEntity::MarkAsNew */ ,
    (void *) (INT_PTR) -1 /* IWsbDbEntity::Next */ ,
    (void *) (INT_PTR) -1 /* IWsbDbEntity::Previous */ ,
    (void *) (INT_PTR) -1 /* IWsbDbEntity::Print */ ,
    (void *) (INT_PTR) -1 /* IWsbDbEntity::Remove */ ,
    (void *) (INT_PTR) -1 /* IWsbDbEntity::UpdateKey */ ,
    (void *) (INT_PTR) -1 /* IWsbDbEntity::UseKey */ ,
    (void *) (INT_PTR) -1 /* IWsbDbEntity::Write */ ,
    (void *) (INT_PTR) -1 /* IWsbDbEntity::SetSequentialScan */ ,
    (void *) (INT_PTR) -1 /* IWsbDbEntity::ResetSequentialScan */
};

const CInterfaceStubVtbl _IWsbDbEntityStubVtbl =
{
    &IID_IWsbDbEntity,
    &IWsbDbEntity_ServerInfo,
    22,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWsbCreateLocalObject, ver. 0.0,
   GUID={0xEF5207D0,0x8C0B,0x11d0,{0x9E,0x39,0x00,0xA0,0xC9,0x16,0xF1,0x20}} */

#pragma code_seg(".orpc")
static const unsigned short IWsbCreateLocalObject_FormatStringOffsetTable[] =
    {
    4080
    };

static const MIDL_STUBLESS_PROXY_INFO IWsbCreateLocalObject_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IWsbCreateLocalObject_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWsbCreateLocalObject_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IWsbCreateLocalObject_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IWsbCreateLocalObjectProxyVtbl = 
{
    &IWsbCreateLocalObject_ProxyInfo,
    &IID_IWsbCreateLocalObject,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWsbCreateLocalObject::CreateInstance */
};

const CInterfaceStubVtbl _IWsbCreateLocalObjectStubVtbl =
{
    &IID_IWsbCreateLocalObject,
    &IWsbCreateLocalObject_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWsbTrace, ver. 0.0,
   GUID={0x0AF2DA10,0x7DD7,0x11d0,{0x9E,0x33,0x00,0xA0,0xC9,0x16,0xF1,0x20}} */

#pragma code_seg(".orpc")
static const unsigned short IWsbTrace_FormatStringOffsetTable[] =
    {
    3246,
    3276,
    4128,
    4164,
    4200,
    4236,
    4278,
    4314,
    4362,
    4410,
    4464,
    1002,
    4518,
    4554,
    4590,
    4626,
    4662,
    4698,
    4050,
    4734,
    4770,
    4824
    };

static const MIDL_STUBLESS_PROXY_INFO IWsbTrace_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IWsbTrace_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWsbTrace_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IWsbTrace_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(25) _IWsbTraceProxyVtbl = 
{
    &IWsbTrace_ProxyInfo,
    &IID_IWsbTrace,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWsbTrace::StartTrace */ ,
    (void *) (INT_PTR) -1 /* IWsbTrace::StopTrace */ ,
    (void *) (INT_PTR) -1 /* IWsbTrace::SetTraceOn */ ,
    (void *) (INT_PTR) -1 /* IWsbTrace::SetTraceOff */ ,
    (void *) (INT_PTR) -1 /* IWsbTrace::GetTraceSettings */ ,
    (void *) (INT_PTR) -1 /* IWsbTrace::GetTraceSetting */ ,
    (void *) (INT_PTR) -1 /* IWsbTrace::DirectOutput */ ,
    (void *) (INT_PTR) -1 /* IWsbTrace::SetOutputFormat */ ,
    (void *) (INT_PTR) -1 /* IWsbTrace::GetOutputFormat */ ,
    (void *) (INT_PTR) -1 /* IWsbTrace::SetTraceFileControls */ ,
    (void *) (INT_PTR) -1 /* IWsbTrace::GetTraceFileControls */ ,
    (void *) (INT_PTR) -1 /* IWsbTrace::SetTraceEntryExit */ ,
    (void *) (INT_PTR) -1 /* IWsbTrace::GetTraceEntryExit */ ,
    (void *) (INT_PTR) -1 /* IWsbTrace::SetLogLevel */ ,
    (void *) (INT_PTR) -1 /* IWsbTrace::GetLogLevel */ ,
    (void *) (INT_PTR) -1 /* IWsbTrace::Print */ ,
    (void *) (INT_PTR) -1 /* IWsbTrace::GetRegistryEntry */ ,
    (void *) (INT_PTR) -1 /* IWsbTrace::SetRegistryEntry */ ,
    (void *) (INT_PTR) -1 /* IWsbTrace::LoadFromRegistry */ ,
    (void *) (INT_PTR) -1 /* IWsbTrace::SetTraceSettings */ ,
    (void *) (INT_PTR) -1 /* IWsbTrace::GetLogSnapShot */ ,
    (void *) (INT_PTR) -1 /* IWsbTrace::SetLogSnapShot */
};

const CInterfaceStubVtbl _IWsbTraceStubVtbl =
{
    &IID_IWsbTrace,
    &IWsbTrace_ServerInfo,
    25,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWsbDbSysPriv, ver. 0.0,
   GUID={0x8A2612A9,0x2466,0x470E,{0xAD,0x46,0x05,0x93,0x18,0xCE,0x8C,0x4E}} */


/* Object interface: IWsbDbPriv, ver. 0.0,
   GUID={0x5FD6B1D1,0x6A43,0x11D0,{0x99,0x05,0x00,0xA0,0xC9,0x05,0x8B,0xF6}} */


/* Object interface: IWsbDbSessionPriv, ver. 0.0,
   GUID={0xC8DA1798,0xA48C,0x458C,{0xB5,0x97,0xF4,0x97,0xAB,0x04,0x6A,0x38}} */


/* Object interface: IWsbDbKeyPriv, ver. 0.0,
   GUID={0x5FD6B1D4,0x6A43,0x11D0,{0x99,0x05,0x00,0xA0,0xC9,0x05,0x8B,0xF6}} */


/* Object interface: IWsbDbEntityPriv, ver. 0.0,
   GUID={0xF16476FD,0xBF20,0x442A,{0x84,0xEB,0x5C,0xEA,0x94,0x62,0xE8,0x1D}} */


/* Object interface: IWsbServer, ver. 0.0,
   GUID={0x58A4F966,0x55BE,0x4D62,{0x89,0x2E,0x43,0xA9,0x97,0x8B,0xF4,0xC2}} */

#pragma code_seg(".orpc")
static const unsigned short IWsbServer_FormatStringOffsetTable[] =
    {
    4878,
    4920,
    4956,
    4998,
    5034,
    5076,
    3492,
    3822,
    5112,
    3852,
    414,
    5148,
    5184,
    5220
    };

static const MIDL_STUBLESS_PROXY_INFO IWsbServer_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IWsbServer_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWsbServer_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IWsbServer_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(17) _IWsbServerProxyVtbl = 
{
    &IWsbServer_ProxyInfo,
    &IID_IWsbServer,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWsbServer::GetDbPathAndName */ ,
    (void *) (INT_PTR) -1 /* IWsbServer::GetId */ ,
    (void *) (INT_PTR) -1 /* IWsbServer::GetRegistryName */ ,
    (void *) (INT_PTR) -1 /* IWsbServer::GetBuildVersion */ ,
    (void *) (INT_PTR) -1 /* IWsbServer::GetNtProductVersion */ ,
    (void *) (INT_PTR) -1 /* IWsbServer::GetNtProductBuild */ ,
    (void *) (INT_PTR) -1 /* IWsbServer::GetDatabaseVersion */ ,
    (void *) (INT_PTR) -1 /* IWsbServer::SaveAll */ ,
    (void *) (INT_PTR) -1 /* IWsbServer::SetId */ ,
    (void *) (INT_PTR) -1 /* IWsbServer::DestroyObject */ ,
    (void *) (INT_PTR) -1 /* IWsbServer::Unload */ ,
    (void *) (INT_PTR) -1 /* IWsbServer::CheckAccess */ ,
    (void *) (INT_PTR) -1 /* IWsbServer::GetTrace */ ,
    (void *) (INT_PTR) -1 /* IWsbServer::SetTrace */
};

const CInterfaceStubVtbl _IWsbServerStubVtbl =
{
    &IID_IWsbServer,
    &IWsbServer_ServerInfo,
    17,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmSystemState, ver. 0.0,
   GUID={0x3F0DA041,0x69F1,0x11d2,{0xAF,0x82,0x00,0x10,0x4B,0x9A,0x37,0x58}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmSystemState_FormatStringOffsetTable[] =
    {
    5256
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmSystemState_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmSystemState_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmSystemState_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmSystemState_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IHsmSystemStateProxyVtbl = 
{
    &IHsmSystemState_ProxyInfo,
    &IID_IHsmSystemState,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmSystemState::ChangeSysState */
};

const CInterfaceStubVtbl _IHsmSystemStateStubVtbl =
{
    &IID_IHsmSystemState,
    &IHsmSystemState_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmEvent, ver. 0.0,
   GUID={0x621EFF31,0xB2E2,0x11d1,{0xB9,0xA6,0x00,0xA0,0xC9,0x19,0x04,0x47}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmEvent_FormatStringOffsetTable[] =
    {
    3246
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmEvent_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmEvent_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmEvent_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmEvent_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IHsmEventProxyVtbl = 
{
    &IHsmEvent_ProxyInfo,
    &IID_IHsmEvent,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmEvent::OnStateChange */
};

const CInterfaceStubVtbl _IHsmEventStubVtbl =
{
    &IID_IHsmEvent,
    &IHsmEvent_ServerInfo,
    4,
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
    ExprEvalRoutines,
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

const CInterfaceProxyVtbl * _wsbint_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IWsbIndexedCollectionProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWsbCollectableProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWsbCollectionProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWsbTraceProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWsbEnumProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWsbTestableProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWsbDbSessionProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWsbPersistableProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWsbStringProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmEventProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWsbGuidProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmSystemStateProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWsbDbProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWsbEnumExProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWsbServerProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWsbDbSysProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWsbDbEntityProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWsbPersistStreamProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWsbCreateLocalObjectProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWsbDbKeyProxyVtbl,
    0
};

const CInterfaceStubVtbl * _wsbint_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IWsbIndexedCollectionStubVtbl,
    ( CInterfaceStubVtbl *) &_IWsbCollectableStubVtbl,
    ( CInterfaceStubVtbl *) &_IWsbCollectionStubVtbl,
    ( CInterfaceStubVtbl *) &_IWsbTraceStubVtbl,
    ( CInterfaceStubVtbl *) &_IWsbEnumStubVtbl,
    ( CInterfaceStubVtbl *) &_IWsbTestableStubVtbl,
    ( CInterfaceStubVtbl *) &_IWsbDbSessionStubVtbl,
    ( CInterfaceStubVtbl *) &_IWsbPersistableStubVtbl,
    ( CInterfaceStubVtbl *) &_IWsbStringStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmEventStubVtbl,
    ( CInterfaceStubVtbl *) &_IWsbGuidStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmSystemStateStubVtbl,
    ( CInterfaceStubVtbl *) &_IWsbDbStubVtbl,
    ( CInterfaceStubVtbl *) &_IWsbEnumExStubVtbl,
    ( CInterfaceStubVtbl *) &_IWsbServerStubVtbl,
    ( CInterfaceStubVtbl *) &_IWsbDbSysStubVtbl,
    ( CInterfaceStubVtbl *) &_IWsbDbEntityStubVtbl,
    ( CInterfaceStubVtbl *) &_IWsbPersistStreamStubVtbl,
    ( CInterfaceStubVtbl *) &_IWsbCreateLocalObjectStubVtbl,
    ( CInterfaceStubVtbl *) &_IWsbDbKeyStubVtbl,
    0
};

PCInterfaceName const _wsbint_InterfaceNamesList[] = 
{
    "IWsbIndexedCollection",
    "IWsbCollectable",
    "IWsbCollection",
    "IWsbTrace",
    "IWsbEnum",
    "IWsbTestable",
    "IWsbDbSession",
    "IWsbPersistable",
    "IWsbString",
    "IHsmEvent",
    "IWsbGuid",
    "IHsmSystemState",
    "IWsbDb",
    "IWsbEnumEx",
    "IWsbServer",
    "IWsbDbSys",
    "IWsbDbEntity",
    "IWsbPersistStream",
    "IWsbCreateLocalObject",
    "IWsbDbKey",
    0
};


#define _wsbint_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _wsbint, pIID, n)

int __stdcall _wsbint_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _wsbint, 20, 16 )
    IID_BS_LOOKUP_NEXT_TEST( _wsbint, 8 )
    IID_BS_LOOKUP_NEXT_TEST( _wsbint, 4 )
    IID_BS_LOOKUP_NEXT_TEST( _wsbint, 2 )
    IID_BS_LOOKUP_NEXT_TEST( _wsbint, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _wsbint, 20, *pIndex )
    
}

const ExtendedProxyFileInfo wsbint_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _wsbint_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _wsbint_StubVtblList,
    (const PCInterfaceName * ) & _wsbint_InterfaceNamesList,
    0, // no delegation
    & _wsbint_IID_Lookup, 
    20,
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
/* Compiler settings for wsbint.idl:
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


#include "wsbint.h"

#define TYPE_FORMAT_STRING_SIZE   861                               
#define PROC_FORMAT_STRING_SIZE   5557                              
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


extern const MIDL_SERVER_INFO IWsbCollectable_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWsbCollectable_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWsbCollection_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWsbCollection_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWsbEnum_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWsbEnum_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWsbEnumEx_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWsbEnumEx_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWsbGuid_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWsbGuid_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWsbIndexedCollection_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWsbIndexedCollection_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWsbPersistStream_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWsbPersistStream_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWsbPersistable_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWsbPersistable_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWsbString_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWsbString_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWsbTestable_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWsbTestable_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWsbDbSys_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWsbDbSys_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWsbDb_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWsbDb_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWsbDbSession_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWsbDbSession_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWsbDbKey_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWsbDbKey_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWsbDbEntity_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWsbDbEntity_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWsbCreateLocalObject_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWsbCreateLocalObject_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWsbTrace_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWsbTrace_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IWsbServer_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IWsbServer_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmSystemState_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmSystemState_ProxyInfo;


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IHsmEvent_ServerInfo;
extern const MIDL_STUBLESS_PROXY_INFO IHsmEvent_ProxyInfo;


extern const EXPR_EVAL ExprEvalRoutines[];

#if !defined(__RPC_WIN64__)
#error  Invalid build platform for this stub.
#endif

static const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure CompareTo */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x3 ),	/* 3 */
/*  8 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x22 ),	/* 34 */
/* 14 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 16 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 18 */	NdrFcShort( 0x0 ),	/* 0 */
/* 20 */	NdrFcShort( 0x0 ),	/* 0 */
/* 22 */	NdrFcShort( 0x0 ),	/* 0 */
/* 24 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCollectable */

/* 26 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 28 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 30 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter pResult */

/* 32 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 34 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 36 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 38 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 40 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 42 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Contains */


	/* Procedure IsEqual */

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

	/* Parameter pCollectable */


	/* Parameter pCollectable */

/* 70 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 72 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 74 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Return value */


	/* Return value */

/* 76 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 78 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 80 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Add */

/* 82 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 84 */	NdrFcLong( 0x0 ),	/* 0 */
/* 88 */	NdrFcShort( 0x3 ),	/* 3 */
/* 90 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 92 */	NdrFcShort( 0x0 ),	/* 0 */
/* 94 */	NdrFcShort( 0x8 ),	/* 8 */
/* 96 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 98 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 100 */	NdrFcShort( 0x0 ),	/* 0 */
/* 102 */	NdrFcShort( 0x0 ),	/* 0 */
/* 104 */	NdrFcShort( 0x0 ),	/* 0 */
/* 106 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCollectable */

/* 108 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 110 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 112 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Return value */

/* 114 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 116 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 118 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetEntries */

/* 120 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 122 */	NdrFcLong( 0x0 ),	/* 0 */
/* 126 */	NdrFcShort( 0x5 ),	/* 5 */
/* 128 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 130 */	NdrFcShort( 0x0 ),	/* 0 */
/* 132 */	NdrFcShort( 0x24 ),	/* 36 */
/* 134 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 136 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 138 */	NdrFcShort( 0x0 ),	/* 0 */
/* 140 */	NdrFcShort( 0x0 ),	/* 0 */
/* 142 */	NdrFcShort( 0x0 ),	/* 0 */
/* 144 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pEntries */

/* 146 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 148 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 150 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 152 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 154 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 156 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Find */

/* 158 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 160 */	NdrFcLong( 0x0 ),	/* 0 */
/* 164 */	NdrFcShort( 0x6 ),	/* 6 */
/* 166 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 168 */	NdrFcShort( 0x44 ),	/* 68 */
/* 170 */	NdrFcShort( 0x8 ),	/* 8 */
/* 172 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 174 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 176 */	NdrFcShort( 0x1 ),	/* 1 */
/* 178 */	NdrFcShort( 0x0 ),	/* 0 */
/* 180 */	NdrFcShort( 0x0 ),	/* 0 */
/* 182 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCollectable */

/* 184 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 186 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 188 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter riid */

/* 190 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 192 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 194 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter ppElement */

/* 196 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 198 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 200 */	NdrFcShort( 0x32 ),	/* Type Offset=50 */

	/* Return value */

/* 202 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 204 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 206 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindGTE */


	/* Procedure IsEmpty */

/* 208 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 210 */	NdrFcLong( 0x0 ),	/* 0 */
/* 214 */	NdrFcShort( 0x7 ),	/* 7 */
/* 216 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 218 */	NdrFcShort( 0x0 ),	/* 0 */
/* 220 */	NdrFcShort( 0x8 ),	/* 8 */
/* 222 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 224 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 226 */	NdrFcShort( 0x0 ),	/* 0 */
/* 228 */	NdrFcShort( 0x0 ),	/* 0 */
/* 230 */	NdrFcShort( 0x0 ),	/* 0 */
/* 232 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */

/* 234 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 236 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 238 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindLT */


	/* Procedure IsLocked */

/* 240 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 242 */	NdrFcLong( 0x0 ),	/* 0 */
/* 246 */	NdrFcShort( 0x8 ),	/* 8 */
/* 248 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 250 */	NdrFcShort( 0x0 ),	/* 0 */
/* 252 */	NdrFcShort( 0x8 ),	/* 8 */
/* 254 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 256 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 258 */	NdrFcShort( 0x0 ),	/* 0 */
/* 260 */	NdrFcShort( 0x0 ),	/* 0 */
/* 262 */	NdrFcShort( 0x0 ),	/* 0 */
/* 264 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */

/* 266 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 268 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 270 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindLTE */


	/* Procedure IncrementChangeCount */


	/* Procedure IsCaseDependent */


	/* Procedure Lock */

/* 272 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 274 */	NdrFcLong( 0x0 ),	/* 0 */
/* 278 */	NdrFcShort( 0x9 ),	/* 9 */
/* 280 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 282 */	NdrFcShort( 0x0 ),	/* 0 */
/* 284 */	NdrFcShort( 0x8 ),	/* 8 */
/* 286 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 288 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 290 */	NdrFcShort( 0x0 ),	/* 0 */
/* 292 */	NdrFcShort( 0x0 ),	/* 0 */
/* 294 */	NdrFcShort( 0x0 ),	/* 0 */
/* 296 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 298 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 300 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 302 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure OccurencesOf */

/* 304 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 306 */	NdrFcLong( 0x0 ),	/* 0 */
/* 310 */	NdrFcShort( 0xa ),	/* 10 */
/* 312 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 314 */	NdrFcShort( 0x0 ),	/* 0 */
/* 316 */	NdrFcShort( 0x24 ),	/* 36 */
/* 318 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 320 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 322 */	NdrFcShort( 0x0 ),	/* 0 */
/* 324 */	NdrFcShort( 0x0 ),	/* 0 */
/* 326 */	NdrFcShort( 0x0 ),	/* 0 */
/* 328 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCollectable */

/* 330 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 332 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 334 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter occurences */

/* 336 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 338 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 340 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 342 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 344 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 346 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Remove */

/* 348 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 350 */	NdrFcLong( 0x0 ),	/* 0 */
/* 354 */	NdrFcShort( 0xb ),	/* 11 */
/* 356 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 358 */	NdrFcShort( 0x44 ),	/* 68 */
/* 360 */	NdrFcShort( 0x8 ),	/* 8 */
/* 362 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 364 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 366 */	NdrFcShort( 0x1 ),	/* 1 */
/* 368 */	NdrFcShort( 0x0 ),	/* 0 */
/* 370 */	NdrFcShort( 0x0 ),	/* 0 */
/* 372 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCollectable */

/* 374 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 376 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 378 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter riid */

/* 380 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 382 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 384 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter ppElement */

/* 386 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 388 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 390 */	NdrFcShort( 0x3e ),	/* Type Offset=62 */

	/* Return value */

/* 392 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 394 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 396 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoveAndRelease */

/* 398 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 400 */	NdrFcLong( 0x0 ),	/* 0 */
/* 404 */	NdrFcShort( 0xc ),	/* 12 */
/* 406 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 408 */	NdrFcShort( 0x0 ),	/* 0 */
/* 410 */	NdrFcShort( 0x8 ),	/* 8 */
/* 412 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 414 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 416 */	NdrFcShort( 0x0 ),	/* 0 */
/* 418 */	NdrFcShort( 0x0 ),	/* 0 */
/* 420 */	NdrFcShort( 0x0 ),	/* 0 */
/* 422 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCollectable */

/* 424 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 426 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 428 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Return value */

/* 430 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 432 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 434 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Unload */


	/* Procedure Next */


	/* Procedure RemoveAllAndRelease */

/* 436 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 438 */	NdrFcLong( 0x0 ),	/* 0 */
/* 442 */	NdrFcShort( 0xd ),	/* 13 */
/* 444 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 446 */	NdrFcShort( 0x0 ),	/* 0 */
/* 448 */	NdrFcShort( 0x8 ),	/* 8 */
/* 450 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 452 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 454 */	NdrFcShort( 0x0 ),	/* 0 */
/* 456 */	NdrFcShort( 0x0 ),	/* 0 */
/* 458 */	NdrFcShort( 0x0 ),	/* 0 */
/* 460 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 462 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 464 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 466 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Previous */


	/* Procedure Unlock */

/* 468 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 470 */	NdrFcLong( 0x0 ),	/* 0 */
/* 474 */	NdrFcShort( 0xe ),	/* 14 */
/* 476 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 478 */	NdrFcShort( 0x0 ),	/* 0 */
/* 480 */	NdrFcShort( 0x8 ),	/* 8 */
/* 482 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 484 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 486 */	NdrFcShort( 0x0 ),	/* 0 */
/* 488 */	NdrFcShort( 0x0 ),	/* 0 */
/* 490 */	NdrFcShort( 0x0 ),	/* 0 */
/* 492 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */

/* 494 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 496 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 498 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Enum */

/* 500 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 502 */	NdrFcLong( 0x0 ),	/* 0 */
/* 506 */	NdrFcShort( 0xf ),	/* 15 */
/* 508 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 510 */	NdrFcShort( 0x0 ),	/* 0 */
/* 512 */	NdrFcShort( 0x8 ),	/* 8 */
/* 514 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 516 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 518 */	NdrFcShort( 0x0 ),	/* 0 */
/* 520 */	NdrFcShort( 0x0 ),	/* 0 */
/* 522 */	NdrFcShort( 0x0 ),	/* 0 */
/* 524 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppEnum */

/* 526 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 528 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 530 */	NdrFcShort( 0x4a ),	/* Type Offset=74 */

	/* Return value */

/* 532 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 534 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 536 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure EnumUnknown */

/* 538 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 540 */	NdrFcLong( 0x0 ),	/* 0 */
/* 544 */	NdrFcShort( 0x10 ),	/* 16 */
/* 546 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 548 */	NdrFcShort( 0x0 ),	/* 0 */
/* 550 */	NdrFcShort( 0x8 ),	/* 8 */
/* 552 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 554 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 556 */	NdrFcShort( 0x0 ),	/* 0 */
/* 558 */	NdrFcShort( 0x0 ),	/* 0 */
/* 560 */	NdrFcShort( 0x0 ),	/* 0 */
/* 562 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppEnum */

/* 564 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 566 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 568 */	NdrFcShort( 0x60 ),	/* Type Offset=96 */

	/* Return value */

/* 570 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 572 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 574 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure First */

/* 576 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 578 */	NdrFcLong( 0x0 ),	/* 0 */
/* 582 */	NdrFcShort( 0x3 ),	/* 3 */
/* 584 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 586 */	NdrFcShort( 0x44 ),	/* 68 */
/* 588 */	NdrFcShort( 0x8 ),	/* 8 */
/* 590 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 592 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 594 */	NdrFcShort( 0x1 ),	/* 1 */
/* 596 */	NdrFcShort( 0x0 ),	/* 0 */
/* 598 */	NdrFcShort( 0x0 ),	/* 0 */
/* 600 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter riid */

/* 602 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 604 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 606 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter ppElement */

/* 608 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 610 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 612 */	NdrFcShort( 0x76 ),	/* Type Offset=118 */

	/* Return value */

/* 614 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 616 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 618 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Next */

/* 620 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 622 */	NdrFcLong( 0x0 ),	/* 0 */
/* 626 */	NdrFcShort( 0x4 ),	/* 4 */
/* 628 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 630 */	NdrFcShort( 0x44 ),	/* 68 */
/* 632 */	NdrFcShort( 0x8 ),	/* 8 */
/* 634 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 636 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 638 */	NdrFcShort( 0x1 ),	/* 1 */
/* 640 */	NdrFcShort( 0x0 ),	/* 0 */
/* 642 */	NdrFcShort( 0x0 ),	/* 0 */
/* 644 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter riid */

/* 646 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 648 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 650 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter ppElement */

/* 652 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 654 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 656 */	NdrFcShort( 0x82 ),	/* Type Offset=130 */

	/* Return value */

/* 658 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 660 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 662 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure This */

/* 664 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 666 */	NdrFcLong( 0x0 ),	/* 0 */
/* 670 */	NdrFcShort( 0x5 ),	/* 5 */
/* 672 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 674 */	NdrFcShort( 0x44 ),	/* 68 */
/* 676 */	NdrFcShort( 0x8 ),	/* 8 */
/* 678 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 680 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 682 */	NdrFcShort( 0x1 ),	/* 1 */
/* 684 */	NdrFcShort( 0x0 ),	/* 0 */
/* 686 */	NdrFcShort( 0x0 ),	/* 0 */
/* 688 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter riid */

/* 690 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 692 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 694 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter ppElement */

/* 696 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 698 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 700 */	NdrFcShort( 0x8e ),	/* Type Offset=142 */

	/* Return value */

/* 702 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 704 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 706 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Previous */

/* 708 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 710 */	NdrFcLong( 0x0 ),	/* 0 */
/* 714 */	NdrFcShort( 0x6 ),	/* 6 */
/* 716 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 718 */	NdrFcShort( 0x44 ),	/* 68 */
/* 720 */	NdrFcShort( 0x8 ),	/* 8 */
/* 722 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 724 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 726 */	NdrFcShort( 0x1 ),	/* 1 */
/* 728 */	NdrFcShort( 0x0 ),	/* 0 */
/* 730 */	NdrFcShort( 0x0 ),	/* 0 */
/* 732 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter riid */

/* 734 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 736 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 738 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter ppElement */

/* 740 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 742 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 744 */	NdrFcShort( 0x9a ),	/* Type Offset=154 */

	/* Return value */

/* 746 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 748 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 750 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Last */

/* 752 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 754 */	NdrFcLong( 0x0 ),	/* 0 */
/* 758 */	NdrFcShort( 0x7 ),	/* 7 */
/* 760 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 762 */	NdrFcShort( 0x44 ),	/* 68 */
/* 764 */	NdrFcShort( 0x8 ),	/* 8 */
/* 766 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 768 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 770 */	NdrFcShort( 0x1 ),	/* 1 */
/* 772 */	NdrFcShort( 0x0 ),	/* 0 */
/* 774 */	NdrFcShort( 0x0 ),	/* 0 */
/* 776 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter riid */

/* 778 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 780 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 782 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter ppElement */

/* 784 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 786 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 788 */	NdrFcShort( 0xa6 ),	/* Type Offset=166 */

	/* Return value */

/* 790 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 792 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 794 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindNext */

/* 796 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 798 */	NdrFcLong( 0x0 ),	/* 0 */
/* 802 */	NdrFcShort( 0x8 ),	/* 8 */
/* 804 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 806 */	NdrFcShort( 0x44 ),	/* 68 */
/* 808 */	NdrFcShort( 0x8 ),	/* 8 */
/* 810 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 812 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 814 */	NdrFcShort( 0x1 ),	/* 1 */
/* 816 */	NdrFcShort( 0x0 ),	/* 0 */
/* 818 */	NdrFcShort( 0x0 ),	/* 0 */
/* 820 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCollectable */

/* 822 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 824 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 826 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter riid */

/* 828 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 830 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 832 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter ppElement */

/* 834 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 836 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 838 */	NdrFcShort( 0xb2 ),	/* Type Offset=178 */

	/* Return value */

/* 840 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 842 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 844 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Find */

/* 846 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 848 */	NdrFcLong( 0x0 ),	/* 0 */
/* 852 */	NdrFcShort( 0x9 ),	/* 9 */
/* 854 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 856 */	NdrFcShort( 0x44 ),	/* 68 */
/* 858 */	NdrFcShort( 0x8 ),	/* 8 */
/* 860 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 862 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 864 */	NdrFcShort( 0x1 ),	/* 1 */
/* 866 */	NdrFcShort( 0x0 ),	/* 0 */
/* 868 */	NdrFcShort( 0x0 ),	/* 0 */
/* 870 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCollectable */

/* 872 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 874 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 876 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter riid */

/* 878 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 880 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 882 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter ppElement */

/* 884 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 886 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 888 */	NdrFcShort( 0xbe ),	/* Type Offset=190 */

	/* Return value */

/* 890 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 892 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 894 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindPrevious */

/* 896 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 898 */	NdrFcLong( 0x0 ),	/* 0 */
/* 902 */	NdrFcShort( 0xa ),	/* 10 */
/* 904 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 906 */	NdrFcShort( 0x44 ),	/* 68 */
/* 908 */	NdrFcShort( 0x8 ),	/* 8 */
/* 910 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 912 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 914 */	NdrFcShort( 0x1 ),	/* 1 */
/* 916 */	NdrFcShort( 0x0 ),	/* 0 */
/* 918 */	NdrFcShort( 0x0 ),	/* 0 */
/* 920 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCollectable */

/* 922 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 924 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 926 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter riid */

/* 928 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 930 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 932 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter ppElement */

/* 934 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 936 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 938 */	NdrFcShort( 0xca ),	/* Type Offset=202 */

	/* Return value */

/* 940 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 942 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 944 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Last */


	/* Procedure SkipToFirst */


	/* Procedure SkipToFirst */

/* 946 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 948 */	NdrFcLong( 0x0 ),	/* 0 */
/* 952 */	NdrFcShort( 0xb ),	/* 11 */
/* 954 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 956 */	NdrFcShort( 0x0 ),	/* 0 */
/* 958 */	NdrFcShort( 0x8 ),	/* 8 */
/* 960 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 962 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 964 */	NdrFcShort( 0x0 ),	/* 0 */
/* 966 */	NdrFcShort( 0x0 ),	/* 0 */
/* 968 */	NdrFcShort( 0x0 ),	/* 0 */
/* 970 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 972 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 974 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 976 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SkipNext */


	/* Procedure SkipNext */

/* 978 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 980 */	NdrFcLong( 0x0 ),	/* 0 */
/* 984 */	NdrFcShort( 0xc ),	/* 12 */
/* 986 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 988 */	NdrFcShort( 0x8 ),	/* 8 */
/* 990 */	NdrFcShort( 0x8 ),	/* 8 */
/* 992 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 994 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 996 */	NdrFcShort( 0x0 ),	/* 0 */
/* 998 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1000 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1002 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter element */


	/* Parameter element */

/* 1004 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1006 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1008 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 1010 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1012 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1014 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SkipTo */


	/* Procedure SkipTo */

/* 1016 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1018 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1022 */	NdrFcShort( 0xd ),	/* 13 */
/* 1024 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1026 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1028 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1030 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1032 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1034 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1036 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1038 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1040 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter index */


	/* Parameter index */

/* 1042 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1044 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1046 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 1048 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1050 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1052 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetTraceEntryExit */


	/* Procedure SkipPrevious */


	/* Procedure SkipPrevious */

/* 1054 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1056 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1060 */	NdrFcShort( 0xe ),	/* 14 */
/* 1062 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1064 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1066 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1068 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1070 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1072 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1074 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1076 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1078 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter traceEntryExit */


	/* Parameter element */


	/* Parameter element */

/* 1080 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1082 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1084 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 1086 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1088 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1090 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SkipToLast */


	/* Procedure SkipToLast */

/* 1092 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1094 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1098 */	NdrFcShort( 0xf ),	/* 15 */
/* 1100 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1102 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1104 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1106 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1108 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1110 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1112 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1114 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1116 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */

/* 1118 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1120 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1122 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Remove */


	/* Procedure Reset */


	/* Procedure Reset */

/* 1124 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1126 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1130 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1132 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1134 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1136 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1138 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 1140 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1142 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1144 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1146 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1148 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 1150 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1152 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1154 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Init */


	/* Procedure Init */

/* 1156 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1158 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1162 */	NdrFcShort( 0x11 ),	/* 17 */
/* 1164 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1166 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1168 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1170 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1172 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1174 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1176 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1178 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1180 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCollection */


	/* Parameter pCollection */

/* 1182 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1184 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1186 */	NdrFcShort( 0xd6 ),	/* Type Offset=214 */

	/* Return value */


	/* Return value */

/* 1188 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1190 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1192 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Clone */


	/* Procedure Clone */

/* 1194 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1196 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1200 */	NdrFcShort( 0x12 ),	/* 18 */
/* 1202 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1204 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1206 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1208 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 1210 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1212 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1214 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1216 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1218 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppEnum */


	/* Parameter ppEnum */

/* 1220 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 1222 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1224 */	NdrFcShort( 0x4a ),	/* Type Offset=74 */

	/* Return value */


	/* Return value */

/* 1226 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1228 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1230 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure First */

/* 1232 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1234 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1238 */	NdrFcShort( 0x3 ),	/* 3 */
/* 1240 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 1242 */	NdrFcShort( 0x4c ),	/* 76 */
/* 1244 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1246 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x5,		/* 5 */
/* 1248 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1250 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1252 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1254 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1256 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter element */

/* 1258 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1260 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1262 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter riid */

/* 1264 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1266 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1268 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter elements */

/* 1270 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 1272 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1274 */	NdrFcShort( 0xf4 ),	/* Type Offset=244 */

	/* Parameter pElementsFetched */

/* 1276 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1278 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1280 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1282 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1284 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 1286 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Next */

/* 1288 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1290 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1294 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1296 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 1298 */	NdrFcShort( 0x4c ),	/* 76 */
/* 1300 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1302 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x5,		/* 5 */
/* 1304 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1306 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1308 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1310 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1312 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter element */

/* 1314 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1316 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1318 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter riid */

/* 1320 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1322 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1324 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter elements */

/* 1326 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 1328 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1330 */	NdrFcShort( 0x116 ),	/* Type Offset=278 */

	/* Parameter pElementsFetched */

/* 1332 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1334 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1336 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1338 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1340 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 1342 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure This */

/* 1344 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1346 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1350 */	NdrFcShort( 0x5 ),	/* 5 */
/* 1352 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 1354 */	NdrFcShort( 0x4c ),	/* 76 */
/* 1356 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1358 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x5,		/* 5 */
/* 1360 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1362 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1364 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1366 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1368 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter element */

/* 1370 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1372 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1374 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter riid */

/* 1376 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1378 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1380 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter elements */

/* 1382 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 1384 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1386 */	NdrFcShort( 0x138 ),	/* Type Offset=312 */

	/* Parameter pElementsFetched */

/* 1388 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1390 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1392 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1394 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1396 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 1398 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Previous */

/* 1400 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1402 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1406 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1408 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 1410 */	NdrFcShort( 0x4c ),	/* 76 */
/* 1412 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1414 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x5,		/* 5 */
/* 1416 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1418 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1420 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1422 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1424 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter element */

/* 1426 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1428 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1430 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter riid */

/* 1432 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1434 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1436 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter elements */

/* 1438 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 1440 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1442 */	NdrFcShort( 0x15a ),	/* Type Offset=346 */

	/* Parameter pElementsFetched */

/* 1444 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1446 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1448 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1450 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1452 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 1454 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Last */

/* 1456 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1458 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1462 */	NdrFcShort( 0x7 ),	/* 7 */
/* 1464 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 1466 */	NdrFcShort( 0x4c ),	/* 76 */
/* 1468 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1470 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x5,		/* 5 */
/* 1472 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1474 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1476 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1478 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1480 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter element */

/* 1482 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1484 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1486 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter riid */

/* 1488 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1490 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1492 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter elements */

/* 1494 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 1496 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1498 */	NdrFcShort( 0x17c ),	/* Type Offset=380 */

	/* Parameter pElementsFetched */

/* 1500 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1502 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1504 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1506 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1508 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 1510 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindNext */

/* 1512 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1514 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1518 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1520 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 1522 */	NdrFcShort( 0x4c ),	/* 76 */
/* 1524 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1526 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 1528 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1530 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1532 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1534 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1536 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCollectable */

/* 1538 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1540 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1542 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter element */

/* 1544 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1546 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1548 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter riid */

/* 1550 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1552 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1554 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter elements */

/* 1556 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 1558 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1560 */	NdrFcShort( 0x19e ),	/* Type Offset=414 */

	/* Parameter pElementsFetched */

/* 1562 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1564 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 1566 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1568 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1570 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 1572 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Find */

/* 1574 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1576 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1580 */	NdrFcShort( 0x9 ),	/* 9 */
/* 1582 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 1584 */	NdrFcShort( 0x4c ),	/* 76 */
/* 1586 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1588 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 1590 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1592 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1594 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1596 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1598 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCollectable */

/* 1600 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1602 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1604 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter element */

/* 1606 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1608 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1610 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter riid */

/* 1612 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1614 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1616 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter elements */

/* 1618 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 1620 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1622 */	NdrFcShort( 0x1c0 ),	/* Type Offset=448 */

	/* Parameter pElementsFetched */

/* 1624 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1626 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 1628 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1630 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1632 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 1634 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindPrevious */

/* 1636 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1638 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1642 */	NdrFcShort( 0xa ),	/* 10 */
/* 1644 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 1646 */	NdrFcShort( 0x4c ),	/* 76 */
/* 1648 */	NdrFcShort( 0x24 ),	/* 36 */
/* 1650 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x6,		/* 6 */
/* 1652 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 1654 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1656 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1658 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1660 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCollectable */

/* 1662 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1664 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1666 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter element */

/* 1668 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1670 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1672 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter riid */

/* 1674 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 1676 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1678 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter elements */

/* 1680 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 1682 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1684 */	NdrFcShort( 0x1e2 ),	/* Type Offset=482 */

	/* Parameter pElementsFetched */

/* 1686 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1688 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 1690 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1692 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1694 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 1696 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToGuid */

/* 1698 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1700 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1704 */	NdrFcShort( 0x5 ),	/* 5 */
/* 1706 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 1708 */	NdrFcShort( 0x30 ),	/* 48 */
/* 1710 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1712 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 1714 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1716 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1718 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1720 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1722 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter value */

/* 1724 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 1726 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1728 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter pResult */

/* 1730 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1732 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1734 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1736 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1738 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1740 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToIGuid */

/* 1742 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1744 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1748 */	NdrFcShort( 0x6 ),	/* 6 */
/* 1750 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1752 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1754 */	NdrFcShort( 0x22 ),	/* 34 */
/* 1756 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1758 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1760 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1762 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1764 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1766 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pGuid */

/* 1768 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1770 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1772 */	NdrFcShort( 0x1f8 ),	/* Type Offset=504 */

	/* Parameter pResult */

/* 1774 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 1776 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1778 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 1780 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1782 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1784 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetGuid */

/* 1786 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1788 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1792 */	NdrFcShort( 0x7 ),	/* 7 */
/* 1794 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1796 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1798 */	NdrFcShort( 0x4c ),	/* 76 */
/* 1800 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1802 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1804 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1806 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1808 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1810 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pValue */

/* 1812 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 1814 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1816 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Return value */

/* 1818 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1820 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1822 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetGuid */

/* 1824 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1826 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1830 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1832 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1834 */	NdrFcShort( 0x30 ),	/* 48 */
/* 1836 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1838 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 1840 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1842 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1844 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1846 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1848 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter value */

/* 1850 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 1852 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1854 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Return value */

/* 1856 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1858 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1860 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AddAt */

/* 1862 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1864 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1868 */	NdrFcShort( 0x11 ),	/* 17 */
/* 1870 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 1872 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1874 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1876 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 1878 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1880 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1882 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1884 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1886 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCollectable */

/* 1888 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1890 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1892 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter index */

/* 1894 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 1896 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1898 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 1900 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1902 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1904 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Append */

/* 1906 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1908 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1912 */	NdrFcShort( 0x12 ),	/* 18 */
/* 1914 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1916 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1918 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1920 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1922 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1924 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1926 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1928 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1930 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCollectable */

/* 1932 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1934 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1936 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Return value */

/* 1938 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1940 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1942 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Prepend */

/* 1944 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1946 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1950 */	NdrFcShort( 0x13 ),	/* 19 */
/* 1952 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 1954 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1956 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1958 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 1960 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 1962 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1964 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1966 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1968 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCollectable */

/* 1970 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 1972 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 1974 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Return value */

/* 1976 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 1978 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 1980 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure RemoveAt */

/* 1982 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 1984 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1988 */	NdrFcShort( 0x14 ),	/* 20 */
/* 1990 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 1992 */	NdrFcShort( 0x4c ),	/* 76 */
/* 1994 */	NdrFcShort( 0x8 ),	/* 8 */
/* 1996 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 1998 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 2000 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2002 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2004 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2006 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter index */

/* 2008 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2010 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2012 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter riid */

/* 2014 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 2016 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2018 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter ppElement */

/* 2020 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2022 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2024 */	NdrFcShort( 0x20e ),	/* Type Offset=526 */

	/* Return value */

/* 2026 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2028 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2030 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure First */

/* 2032 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2034 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2038 */	NdrFcShort( 0x15 ),	/* 21 */
/* 2040 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2042 */	NdrFcShort( 0x44 ),	/* 68 */
/* 2044 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2046 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 2048 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 2050 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2052 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2054 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2056 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter riid */

/* 2058 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 2060 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2062 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter ppElement */

/* 2064 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2066 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2068 */	NdrFcShort( 0x21a ),	/* Type Offset=538 */

	/* Return value */

/* 2070 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2072 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2074 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure At */

/* 2076 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2078 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2082 */	NdrFcShort( 0x16 ),	/* 22 */
/* 2084 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 2086 */	NdrFcShort( 0x4c ),	/* 76 */
/* 2088 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2090 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 2092 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 2094 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2096 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2098 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2100 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter index */

/* 2102 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2104 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2106 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter riid */

/* 2108 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 2110 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2112 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter ppElement */

/* 2114 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2116 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2118 */	NdrFcShort( 0x226 ),	/* Type Offset=550 */

	/* Return value */

/* 2120 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2122 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2124 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Last */

/* 2126 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2128 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2132 */	NdrFcShort( 0x17 ),	/* 23 */
/* 2134 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2136 */	NdrFcShort( 0x44 ),	/* 68 */
/* 2138 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2140 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 2142 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 2144 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2146 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2148 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2150 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter riid */

/* 2152 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 2154 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2156 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter ppElement */

/* 2158 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2160 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2162 */	NdrFcShort( 0x232 ),	/* Type Offset=562 */

	/* Return value */

/* 2164 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2166 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2168 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Index */

/* 2170 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2172 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2176 */	NdrFcShort( 0x18 ),	/* 24 */
/* 2178 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2180 */	NdrFcShort( 0x1c ),	/* 28 */
/* 2182 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2184 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2186 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2188 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2190 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2192 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2194 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pCollectable */

/* 2196 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2198 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2200 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter pIndex */

/* 2202 */	NdrFcShort( 0x148 ),	/* Flags:  in, base type, simple ref, */
/* 2204 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2206 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2208 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2210 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2212 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Copy */

/* 2214 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2216 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2220 */	NdrFcShort( 0x19 ),	/* 25 */
/* 2222 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 2224 */	NdrFcShort( 0x54 ),	/* 84 */
/* 2226 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2228 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x6,		/* 6 */
/* 2230 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 2232 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2234 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2236 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2238 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter start */

/* 2240 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2242 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2244 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter stop */

/* 2246 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2248 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2250 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter riid */

/* 2252 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 2254 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2256 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter elements */

/* 2258 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 2260 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2262 */	NdrFcShort( 0x24e ),	/* Type Offset=590 */

	/* Parameter pElementsFetched */

/* 2264 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2266 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 2268 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2270 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2272 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 2274 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CopyIfMatches */

/* 2276 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2278 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2282 */	NdrFcShort( 0x1a ),	/* 26 */
/* 2284 */	NdrFcShort( 0x50 ),	/* ia64 Stack size/offset = 80 */
/* 2286 */	NdrFcShort( 0x5c ),	/* 92 */
/* 2288 */	NdrFcShort( 0x40 ),	/* 64 */
/* 2290 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x9,		/* 9 */
/* 2292 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 2294 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2296 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2298 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2300 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter start */

/* 2302 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2304 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2306 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter stop */

/* 2308 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2310 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2312 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pCollectable */

/* 2314 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2316 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2318 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Parameter element */

/* 2320 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2322 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2324 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter riid */

/* 2326 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 2328 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 2330 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter elements */

/* 2332 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
/* 2334 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 2336 */	NdrFcShort( 0x270 ),	/* Type Offset=624 */

	/* Parameter pElementsFetched */

/* 2338 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2340 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 2342 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pStoppedAt */

/* 2344 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2346 */	NdrFcShort( 0x40 ),	/* ia64 Stack size/offset = 64 */
/* 2348 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2350 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2352 */	NdrFcShort( 0x48 ),	/* ia64 Stack size/offset = 72 */
/* 2354 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AppendBool */


	/* Procedure SetIsDirty */

/* 2356 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2358 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2362 */	NdrFcShort( 0x3 ),	/* 3 */
/* 2364 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2366 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2368 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2370 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2372 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2374 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2376 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2378 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2380 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter value */


	/* Parameter isDirty */

/* 2382 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2384 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2386 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 2388 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2390 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2392 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDefaultFileName */

/* 2394 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2396 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2400 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2402 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2404 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2406 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2408 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2410 */	0xa,		/* 10 */
			0x7,		/* Ext Flags:  new corr desc, clt corr check, srv corr check, */
/* 2412 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2414 */	NdrFcShort( 0x1 ),	/* 1 */
/* 2416 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2418 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pFilename */

/* 2420 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
/* 2422 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2424 */	NdrFcShort( 0x28a ),	/* Type Offset=650 */

	/* Parameter bufferSize */

/* 2426 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2428 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2430 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2432 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2434 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2436 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindEQ */


	/* Procedure TransactionEnd */


	/* Procedure Terminate */


	/* Procedure ReleaseFile */

/* 2438 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2440 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2444 */	NdrFcShort( 0x5 ),	/* 5 */
/* 2446 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2448 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2450 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2452 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 2454 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2456 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2458 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2460 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2462 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 2464 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2466 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2468 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetDefaultFileName */

/* 2470 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2472 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2476 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2478 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2480 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2482 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2484 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2486 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2488 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2490 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2492 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2494 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter fileName */

/* 2496 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2498 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2500 */	NdrFcShort( 0x2a2 ),	/* Type Offset=674 */

	/* Return value */

/* 2502 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2504 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2506 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToString */

/* 2508 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2510 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2514 */	NdrFcShort( 0x5 ),	/* 5 */
/* 2516 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2518 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2520 */	NdrFcShort( 0x22 ),	/* 34 */
/* 2522 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2524 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2526 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2528 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2530 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2532 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter value */

/* 2534 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2536 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2538 */	NdrFcShort( 0x2a2 ),	/* Type Offset=674 */

	/* Parameter pResult */

/* 2540 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2542 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2544 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2546 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2548 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2550 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CompareToIString */

/* 2552 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2554 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2558 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2560 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2562 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2564 */	NdrFcShort( 0x22 ),	/* 34 */
/* 2566 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2568 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2570 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2572 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2574 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2576 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pString */

/* 2578 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 2580 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2582 */	NdrFcShort( 0x2a4 ),	/* Type Offset=676 */

	/* Parameter pResult */

/* 2584 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2586 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2588 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2590 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2592 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2594 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetString */

/* 2596 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2598 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2602 */	NdrFcShort( 0x7 ),	/* 7 */
/* 2604 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2606 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2608 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2610 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2612 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2614 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2616 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2618 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2620 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pValue */

/* 2622 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 2624 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2626 */	NdrFcShort( 0x2b6 ),	/* Type Offset=694 */

	/* Parameter bufferSize */

/* 2628 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2630 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2632 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2634 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2636 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2638 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetStringAndCase */

/* 2640 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2642 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2646 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2648 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 2650 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2652 */	NdrFcShort( 0x24 ),	/* 36 */
/* 2654 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 2656 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2658 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2660 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2662 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2664 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pValue */

/* 2666 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 2668 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2670 */	NdrFcShort( 0x2b6 ),	/* Type Offset=694 */

	/* Parameter pIsCaseDependent */

/* 2672 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2674 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2676 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter bufferSize */

/* 2678 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2680 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2682 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2684 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2686 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2688 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetToBool */


	/* Procedure SetIsCaseDependent */

/* 2690 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2692 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2696 */	NdrFcShort( 0xa ),	/* 10 */
/* 2698 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2700 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2702 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2704 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 2706 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2708 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2710 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2712 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2714 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter value */


	/* Parameter isCaseDependent */

/* 2716 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2718 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2720 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 2722 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2724 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2726 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Locate */


	/* Procedure SetString */

/* 2728 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2730 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2734 */	NdrFcShort( 0xb ),	/* 11 */
/* 2736 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2738 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2740 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2742 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 2744 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2746 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2748 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2750 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2752 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter path */


	/* Parameter value */

/* 2754 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2756 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2758 */	NdrFcShort( 0x2a2 ),	/* Type Offset=674 */

	/* Return value */


	/* Return value */

/* 2760 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2762 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2764 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetStringAndCase */

/* 2766 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2768 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2772 */	NdrFcShort( 0xc ),	/* 12 */
/* 2774 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2776 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2778 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2780 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2782 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2784 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2786 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2788 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2790 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter value */

/* 2792 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2794 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2796 */	NdrFcShort( 0x2a2 ),	/* Type Offset=674 */

	/* Parameter isCaseDependent */

/* 2798 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2800 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2802 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2804 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2806 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2808 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Test */

/* 2810 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2812 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2816 */	NdrFcShort( 0x3 ),	/* 3 */
/* 2818 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2820 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2822 */	NdrFcShort( 0x3c ),	/* 60 */
/* 2824 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 2826 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2828 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2830 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2832 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2834 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter passed */

/* 2836 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2838 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2840 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter failed */

/* 2842 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 2844 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2846 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 2848 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2850 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2852 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Backup */

/* 2854 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2856 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2860 */	NdrFcShort( 0x3 ),	/* 3 */
/* 2862 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2864 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2866 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2868 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2870 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2872 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2874 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2876 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2878 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter path */

/* 2880 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2882 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2884 */	NdrFcShort( 0x2a2 ),	/* Type Offset=674 */

	/* Parameter flags */

/* 2886 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2888 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2890 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 2892 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2894 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2896 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Create */


	/* Procedure Init */

/* 2898 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2900 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2904 */	NdrFcShort( 0x4 ),	/* 4 */
/* 2906 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 2908 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2910 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2912 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 2914 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2916 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2918 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2920 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2922 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter path */


	/* Parameter path */

/* 2924 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 2926 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2928 */	NdrFcShort( 0x2a2 ),	/* Type Offset=674 */

	/* Parameter flags */


	/* Parameter flags */

/* 2930 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 2932 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2934 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 2936 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2938 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2940 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure NewSession */

/* 2942 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2944 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2948 */	NdrFcShort( 0x6 ),	/* 6 */
/* 2950 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2952 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2954 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2956 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2958 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2960 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2962 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2964 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2966 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppSession */

/* 2968 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 2970 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 2972 */	NdrFcShort( 0x2be ),	/* Type Offset=702 */

	/* Return value */

/* 2974 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 2976 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 2978 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetGlobalSession */

/* 2980 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 2982 */	NdrFcLong( 0x0 ),	/* 0 */
/* 2986 */	NdrFcShort( 0x7 ),	/* 7 */
/* 2988 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 2990 */	NdrFcShort( 0x0 ),	/* 0 */
/* 2992 */	NdrFcShort( 0x8 ),	/* 8 */
/* 2994 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 2996 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 2998 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3000 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3002 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3004 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppSession */

/* 3006 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3008 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3010 */	NdrFcShort( 0x2be ),	/* Type Offset=702 */

	/* Return value */

/* 3012 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3014 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3016 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Restore */

/* 3018 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3020 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3024 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3026 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3028 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3030 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3032 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 3034 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3036 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3038 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3040 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3042 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter fromPath */

/* 3044 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3046 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3048 */	NdrFcShort( 0x2a2 ),	/* Type Offset=674 */

	/* Parameter toPath */

/* 3050 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3052 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3054 */	NdrFcShort( 0x2a2 ),	/* Type Offset=674 */

	/* Return value */

/* 3056 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3058 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3060 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Close */

/* 3062 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3064 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3068 */	NdrFcShort( 0x3 ),	/* 3 */
/* 3070 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3072 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3074 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3076 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3078 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3080 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3082 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3084 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3086 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSession */

/* 3088 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3090 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3092 */	NdrFcShort( 0x2c2 ),	/* Type Offset=706 */

	/* Return value */

/* 3094 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3096 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3098 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Delete */

/* 3100 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3102 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3106 */	NdrFcShort( 0x5 ),	/* 5 */
/* 3108 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3110 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3112 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3114 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 3116 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3118 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3120 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3122 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3124 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter path */

/* 3126 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3128 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3130 */	NdrFcShort( 0x2a2 ),	/* Type Offset=674 */

	/* Parameter flags */

/* 3132 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3134 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3136 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3138 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3140 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3142 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Dump */

/* 3144 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3146 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3150 */	NdrFcShort( 0x6 ),	/* 6 */
/* 3152 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 3154 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3156 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3158 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x4,		/* 4 */
/* 3160 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3162 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3164 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3166 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3168 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter Filename */

/* 3170 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3172 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3174 */	NdrFcShort( 0x2a2 ),	/* Type Offset=674 */

	/* Parameter Flags */

/* 3176 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3178 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3180 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter Data */

/* 3182 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3184 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3186 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3188 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3190 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3192 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetEntity */

/* 3194 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3196 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3200 */	NdrFcShort( 0x7 ),	/* 7 */
/* 3202 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 3204 */	NdrFcShort( 0x4c ),	/* 76 */
/* 3206 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3208 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 3210 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 3212 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3214 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3216 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3218 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSession */

/* 3220 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 3222 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3224 */	NdrFcShort( 0x2c2 ),	/* Type Offset=706 */

	/* Parameter RecId */

/* 3226 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3228 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3230 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter riid */

/* 3232 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 3234 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3236 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter ppEntity */

/* 3238 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3240 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3242 */	NdrFcShort( 0x2d4 ),	/* Type Offset=724 */

	/* Return value */

/* 3244 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3246 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 3248 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetName */

/* 3250 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3252 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3256 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3258 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3260 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3262 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3264 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 3266 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3268 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3270 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3272 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3274 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pName */

/* 3276 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 3278 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3280 */	NdrFcShort( 0x2b6 ),	/* Type Offset=694 */

	/* Return value */

/* 3282 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3284 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3286 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPath */

/* 3288 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3290 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3294 */	NdrFcShort( 0x9 ),	/* 9 */
/* 3296 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3298 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3300 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3302 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 3304 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3306 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3308 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3310 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3312 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pPath */

/* 3314 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 3316 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3318 */	NdrFcShort( 0x2b6 ),	/* Type Offset=694 */

	/* Return value */

/* 3320 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3322 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3324 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetVersion */

/* 3326 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3328 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3332 */	NdrFcShort( 0xa ),	/* 10 */
/* 3334 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3336 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3338 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3340 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3342 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3344 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3346 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3348 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3350 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pVer */

/* 3352 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3354 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3356 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3358 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3360 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3362 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Open */

/* 3364 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3366 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3370 */	NdrFcShort( 0xc ),	/* 12 */
/* 3372 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3374 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3376 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3378 */	0x47,		/* Oi2 Flags:  srv must size, clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3380 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3382 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3384 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3386 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3388 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppSession */

/* 3390 */	NdrFcShort( 0x201b ),	/* Flags:  must size, must free, in, out, srv alloc size=8 */
/* 3392 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3394 */	NdrFcShort( 0x2e0 ),	/* Type Offset=736 */

	/* Return value */

/* 3396 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3398 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3400 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure OnStateChange */


	/* Procedure StartTrace */


	/* Procedure TransactionBegin */

/* 3402 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3404 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3408 */	NdrFcShort( 0x3 ),	/* 3 */
/* 3410 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3412 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3414 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3416 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 3418 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3420 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3422 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3424 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3426 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 3428 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3430 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3432 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure StopTrace */


	/* Procedure Disconnect */


	/* Procedure TransactionCancel */

/* 3434 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3436 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3440 */	NdrFcShort( 0x4 ),	/* 4 */
/* 3442 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3444 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3446 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3448 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 3450 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3452 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3454 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3456 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3458 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */


	/* Return value */

/* 3460 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3462 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3464 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AppendBytes */

/* 3466 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3468 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3472 */	NdrFcShort( 0x4 ),	/* 4 */
/* 3474 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3476 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3478 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3480 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 3482 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3484 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3486 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3488 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3490 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bytes */

/* 3492 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3494 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3496 */	NdrFcShort( 0x2e8 ),	/* Type Offset=744 */

	/* Parameter size */

/* 3498 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3500 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3502 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3504 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3506 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3508 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AppendFiletime */

/* 3510 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3512 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3516 */	NdrFcShort( 0x5 ),	/* 5 */
/* 3518 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3520 */	NdrFcShort( 0x18 ),	/* 24 */
/* 3522 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3524 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3526 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3528 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3530 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3532 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3534 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter value */

/* 3536 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 3538 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3540 */	NdrFcShort( 0x2f4 ),	/* Type Offset=756 */

	/* Return value */

/* 3542 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3544 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3546 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AppendGuid */

/* 3548 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3550 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3554 */	NdrFcShort( 0x6 ),	/* 6 */
/* 3556 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3558 */	NdrFcShort( 0x30 ),	/* 48 */
/* 3560 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3562 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3564 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3566 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3568 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3570 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3572 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter value */

/* 3574 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 3576 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3578 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Return value */

/* 3580 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3582 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3584 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AppendLonglong */

/* 3586 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3588 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3592 */	NdrFcShort( 0x7 ),	/* 7 */
/* 3594 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3596 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3598 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3600 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3602 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3604 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3606 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3608 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3610 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter value */

/* 3612 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3614 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3616 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 3618 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3620 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3622 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AppendString */

/* 3624 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3626 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3630 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3632 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3634 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3636 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3638 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3640 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3642 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3644 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3646 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3648 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter value */

/* 3650 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3652 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3654 */	NdrFcShort( 0x2a2 ),	/* Type Offset=674 */

	/* Return value */

/* 3656 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3658 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3660 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDatabaseVersion */


	/* Procedure GetType */

/* 3662 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3664 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3668 */	NdrFcShort( 0x9 ),	/* 9 */
/* 3670 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3672 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3674 */	NdrFcShort( 0x24 ),	/* 36 */
/* 3676 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3678 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3680 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3682 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3684 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3686 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pDatabaseVersion */


	/* Parameter pType */

/* 3688 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 3690 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3692 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 3694 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3696 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3698 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetToBytes */

/* 3700 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3702 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3706 */	NdrFcShort( 0xb ),	/* 11 */
/* 3708 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3710 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3712 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3714 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x3,		/* 3 */
/* 3716 */	0xa,		/* 10 */
			0x5,		/* Ext Flags:  new corr desc, srv corr check, */
/* 3718 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3720 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3722 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3724 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter bytes */

/* 3726 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3728 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3730 */	NdrFcShort( 0x2e8 ),	/* Type Offset=744 */

	/* Parameter size */

/* 3732 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3734 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3736 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3738 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3740 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3742 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetToFiletime */

/* 3744 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3746 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3750 */	NdrFcShort( 0xc ),	/* 12 */
/* 3752 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3754 */	NdrFcShort( 0x18 ),	/* 24 */
/* 3756 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3758 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3760 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3762 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3764 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3766 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3768 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter value */

/* 3770 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 3772 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3774 */	NdrFcShort( 0x2f4 ),	/* Type Offset=756 */

	/* Return value */

/* 3776 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3778 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3780 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetToGuid */

/* 3782 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3784 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3788 */	NdrFcShort( 0xd ),	/* 13 */
/* 3790 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3792 */	NdrFcShort( 0x30 ),	/* 48 */
/* 3794 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3796 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3798 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3800 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3802 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3804 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3806 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter value */

/* 3808 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 3810 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3812 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Return value */

/* 3814 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3816 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3818 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetToLonglong */

/* 3820 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3822 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3826 */	NdrFcShort( 0xe ),	/* 14 */
/* 3828 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3830 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3832 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3834 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3836 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3838 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3840 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3842 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3844 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter value */

/* 3846 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3848 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3850 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 3852 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3854 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3856 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetToUlong */

/* 3858 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3860 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3864 */	NdrFcShort( 0xf ),	/* 15 */
/* 3866 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3868 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3870 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3872 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 3874 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3876 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3878 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3880 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3882 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter value */

/* 3884 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 3886 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3888 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 3890 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3892 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3894 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetToString */

/* 3896 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3898 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3902 */	NdrFcShort( 0x10 ),	/* 16 */
/* 3904 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3906 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3908 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3910 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 3912 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3914 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3916 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3918 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3920 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter value */

/* 3922 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 3924 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3926 */	NdrFcShort( 0x2a2 ),	/* Type Offset=674 */

	/* Return value */

/* 3928 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3930 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3932 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Clone */

/* 3934 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3936 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3940 */	NdrFcShort( 0x3 ),	/* 3 */
/* 3942 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 3944 */	NdrFcShort( 0x44 ),	/* 68 */
/* 3946 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3948 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 3950 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 3952 */	NdrFcShort( 0x1 ),	/* 1 */
/* 3954 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3956 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3958 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter riid */

/* 3960 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 3962 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 3964 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter ppEntity */

/* 3966 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 3968 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3970 */	NdrFcShort( 0x2fc ),	/* Type Offset=764 */

	/* Return value */

/* 3972 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 3974 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 3976 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure FindGT */

/* 3978 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 3980 */	NdrFcLong( 0x0 ),	/* 0 */
/* 3984 */	NdrFcShort( 0x6 ),	/* 6 */
/* 3986 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 3988 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3990 */	NdrFcShort( 0x8 ),	/* 8 */
/* 3992 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 3994 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 3996 */	NdrFcShort( 0x0 ),	/* 0 */
/* 3998 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4000 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4002 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 4004 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4006 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4008 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SaveAll */


	/* Procedure First */

/* 4010 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4012 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4016 */	NdrFcShort( 0xa ),	/* 10 */
/* 4018 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4020 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4022 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4024 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 4026 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4028 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4030 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4032 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4034 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */

/* 4036 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4038 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4040 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DestroyObject */


	/* Procedure MarkAsNew */

/* 4042 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4044 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4048 */	NdrFcShort( 0xc ),	/* 12 */
/* 4050 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4052 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4054 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4056 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 4058 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4060 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4062 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4064 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4066 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */

/* 4068 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4070 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4072 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Print */

/* 4074 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4076 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4080 */	NdrFcShort( 0xf ),	/* 15 */
/* 4082 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4084 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4086 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4088 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 4090 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4092 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4094 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4096 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4098 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pStream */

/* 4100 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 4102 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4104 */	NdrFcShort( 0x308 ),	/* Type Offset=776 */

	/* Return value */

/* 4106 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4108 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4110 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure UpdateKey */

/* 4112 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4114 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4118 */	NdrFcShort( 0x11 ),	/* 17 */
/* 4120 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4122 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4124 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4126 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 4128 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4130 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4132 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4134 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4136 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pKey */

/* 4138 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 4140 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4142 */	NdrFcShort( 0x31a ),	/* Type Offset=794 */

	/* Return value */

/* 4144 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4146 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4148 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure UseKey */

/* 4150 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4152 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4156 */	NdrFcShort( 0x12 ),	/* 18 */
/* 4158 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4160 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4162 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4164 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4166 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4168 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4170 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4172 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4174 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter type */

/* 4176 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4178 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4180 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4182 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4184 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4186 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Write */

/* 4188 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4190 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4194 */	NdrFcShort( 0x13 ),	/* 19 */
/* 4196 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4198 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4200 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4202 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 4204 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4206 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4208 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4210 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4212 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 4214 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4216 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4218 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetSequentialScan */

/* 4220 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4222 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4226 */	NdrFcShort( 0x14 ),	/* 20 */
/* 4228 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4230 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4232 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4234 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 4236 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4238 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4240 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4242 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4244 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */

/* 4246 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4248 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4250 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure LoadFromRegistry */


	/* Procedure ResetSequentialScan */

/* 4252 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4254 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4258 */	NdrFcShort( 0x15 ),	/* 21 */
/* 4260 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4262 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4264 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4266 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x1,		/* 1 */
/* 4268 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4270 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4272 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4274 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4276 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Return value */


	/* Return value */

/* 4278 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4280 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4282 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CreateInstance */

/* 4284 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4286 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4290 */	NdrFcShort( 0x3 ),	/* 3 */
/* 4292 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 4294 */	NdrFcShort( 0x88 ),	/* 136 */
/* 4296 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4298 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x4,		/* 4 */
/* 4300 */	0xa,		/* 10 */
			0x3,		/* Ext Flags:  new corr desc, clt corr check, */
/* 4302 */	NdrFcShort( 0x1 ),	/* 1 */
/* 4304 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4306 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4308 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter rclsid */

/* 4310 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 4312 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4314 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter riid */

/* 4316 */	NdrFcShort( 0x10a ),	/* Flags:  must free, in, simple ref, */
/* 4318 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4320 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Parameter ppv */

/* 4322 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 4324 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4326 */	NdrFcShort( 0x32c ),	/* Type Offset=812 */

	/* Return value */

/* 4328 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4330 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 4332 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetTraceOn */

/* 4334 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4336 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4340 */	NdrFcShort( 0x5 ),	/* 5 */
/* 4342 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4344 */	NdrFcShort( 0x10 ),	/* 16 */
/* 4346 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4348 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4350 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4352 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4354 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4356 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4358 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter traceElement */

/* 4360 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4362 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4364 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 4366 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4368 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4370 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetTraceOff */

/* 4372 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4374 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4378 */	NdrFcShort( 0x6 ),	/* 6 */
/* 4380 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4382 */	NdrFcShort( 0x10 ),	/* 16 */
/* 4384 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4386 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4388 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4390 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4392 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4394 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4396 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter traceElement */

/* 4398 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4400 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4402 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 4404 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4406 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4408 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetTraceSettings */

/* 4410 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4412 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4416 */	NdrFcShort( 0x7 ),	/* 7 */
/* 4418 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4420 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4422 */	NdrFcShort( 0x2c ),	/* 44 */
/* 4424 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4426 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4428 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4430 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4432 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4434 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pTraceElements */

/* 4436 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4438 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4440 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 4442 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4444 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4446 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetTraceSetting */

/* 4448 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4450 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4454 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4456 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 4458 */	NdrFcShort( 0x10 ),	/* 16 */
/* 4460 */	NdrFcShort( 0x24 ),	/* 36 */
/* 4462 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x3,		/* 3 */
/* 4464 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4466 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4468 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4470 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4472 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter traceElement */

/* 4474 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4476 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4478 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter pOn */

/* 4480 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4482 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4484 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4486 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4488 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4490 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure DirectOutput */

/* 4492 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4494 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4498 */	NdrFcShort( 0x9 ),	/* 9 */
/* 4500 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4502 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4504 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4506 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4508 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4510 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4512 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4514 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4516 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter output */

/* 4518 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4520 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4522 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4524 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4526 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4528 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetOutputFormat */

/* 4530 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4532 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4536 */	NdrFcShort( 0xa ),	/* 10 */
/* 4538 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 4540 */	NdrFcShort( 0x18 ),	/* 24 */
/* 4542 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4544 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 4546 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4548 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4550 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4552 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4554 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter timeStamp */

/* 4556 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4558 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4560 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter traceCount */

/* 4562 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4564 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4566 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter traceThreadId */

/* 4568 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4570 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4572 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4574 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4576 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 4578 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetOutputFormat */

/* 4580 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4582 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4586 */	NdrFcShort( 0xb ),	/* 11 */
/* 4588 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 4590 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4592 */	NdrFcShort( 0x5c ),	/* 92 */
/* 4594 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x4,		/* 4 */
/* 4596 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4598 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4600 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4602 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4604 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pTimeStamp */

/* 4606 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4608 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4610 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pTraceCount */

/* 4612 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4614 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4616 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pTraceThreadId */

/* 4618 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4620 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4622 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4624 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4626 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 4628 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetTraceFileControls */

/* 4630 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4632 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4636 */	NdrFcShort( 0xc ),	/* 12 */
/* 4638 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 4640 */	NdrFcShort( 0x18 ),	/* 24 */
/* 4642 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4644 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 4646 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4648 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4650 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4652 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4654 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter traceFileName */

/* 4656 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 4658 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4660 */	NdrFcShort( 0x2a2 ),	/* Type Offset=674 */

	/* Parameter commitEachEntry */

/* 4662 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4664 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4666 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter maxTraceFileSize */

/* 4668 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4670 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4672 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter traceFileCopyName */

/* 4674 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 4676 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 4678 */	NdrFcShort( 0x2a2 ),	/* Type Offset=674 */

	/* Return value */

/* 4680 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4682 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 4684 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetTraceFileControls */

/* 4686 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4688 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4692 */	NdrFcShort( 0xd ),	/* 13 */
/* 4694 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 4696 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4698 */	NdrFcShort( 0x48 ),	/* 72 */
/* 4700 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x5,		/* 5 */
/* 4702 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4704 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4706 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4708 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4710 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter traceFileName */

/* 4712 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 4714 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4716 */	NdrFcShort( 0x2b6 ),	/* Type Offset=694 */

	/* Parameter pCommitEachEntry */

/* 4718 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4720 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4722 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pMaxTraceFileSize */

/* 4724 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4726 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4728 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Parameter traceFileCopyName */

/* 4730 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 4732 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 4734 */	NdrFcShort( 0x2b6 ),	/* Type Offset=694 */

	/* Return value */

/* 4736 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4738 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 4740 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetTraceEntryExit */

/* 4742 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4744 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4748 */	NdrFcShort( 0xf ),	/* 15 */
/* 4750 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4752 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4754 */	NdrFcShort( 0x24 ),	/* 36 */
/* 4756 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4758 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4760 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4762 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4764 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4766 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pTraceEntryExit */

/* 4768 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4770 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4772 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 4774 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4776 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4778 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetLogLevel */

/* 4780 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4782 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4786 */	NdrFcShort( 0x10 ),	/* 16 */
/* 4788 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4790 */	NdrFcShort( 0x6 ),	/* 6 */
/* 4792 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4794 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4796 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4798 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4800 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4802 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4804 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter traceError */

/* 4806 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4808 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4810 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 4812 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4814 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4816 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetLogLevel */

/* 4818 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4820 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4824 */	NdrFcShort( 0x11 ),	/* 17 */
/* 4826 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4828 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4830 */	NdrFcShort( 0x22 ),	/* 34 */
/* 4832 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4834 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4836 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4838 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4840 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4842 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pTraceError */

/* 4844 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 4846 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4848 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Return value */

/* 4850 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4852 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4854 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Print */

/* 4856 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4858 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4862 */	NdrFcShort( 0x12 ),	/* 18 */
/* 4864 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4866 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4868 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4870 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 4872 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4874 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4876 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4878 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4880 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter traceString */

/* 4882 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 4884 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4886 */	NdrFcShort( 0x2a2 ),	/* Type Offset=674 */

	/* Return value */

/* 4888 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4890 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4892 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetRegistryEntry */

/* 4894 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4896 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4900 */	NdrFcShort( 0x13 ),	/* 19 */
/* 4902 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4904 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4906 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4908 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 4910 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4912 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4914 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4916 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4918 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pRegistryEntry */

/* 4920 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 4922 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4924 */	NdrFcShort( 0x2b6 ),	/* Type Offset=694 */

	/* Return value */

/* 4926 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4928 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4930 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetRegistryEntry */

/* 4932 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4934 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4938 */	NdrFcShort( 0x14 ),	/* 20 */
/* 4940 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4942 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4944 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4946 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 4948 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4950 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4952 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4954 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4956 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pRegistryEntry */

/* 4958 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 4960 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 4962 */	NdrFcShort( 0x2a2 ),	/* Type Offset=674 */

	/* Return value */

/* 4964 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 4966 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 4968 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetTraceSettings */

/* 4970 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 4972 */	NdrFcLong( 0x0 ),	/* 0 */
/* 4976 */	NdrFcShort( 0x16 ),	/* 22 */
/* 4978 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 4980 */	NdrFcShort( 0x10 ),	/* 16 */
/* 4982 */	NdrFcShort( 0x8 ),	/* 8 */
/* 4984 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 4986 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 4988 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4990 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4992 */	NdrFcShort( 0x0 ),	/* 0 */
/* 4994 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter traceElements */

/* 4996 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 4998 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5000 */	0xb,		/* FC_HYPER */
			0x0,		/* 0 */

	/* Return value */

/* 5002 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5004 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5006 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetLogSnapShot */

/* 5008 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5010 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5014 */	NdrFcShort( 0x17 ),	/* 23 */
/* 5016 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 5018 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5020 */	NdrFcShort( 0x5a ),	/* 90 */
/* 5022 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x5,		/* 5 */
/* 5024 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5026 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5028 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5030 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5032 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pOn */

/* 5034 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5036 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5038 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter pLevel */

/* 5040 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5042 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5044 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter pSnapShotPath */

/* 5046 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 5048 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5050 */	NdrFcShort( 0x2b6 ),	/* Type Offset=694 */

	/* Parameter pResetTrace */

/* 5052 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5054 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 5056 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5058 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5060 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 5062 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetLogSnapShot */

/* 5064 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5066 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5070 */	NdrFcShort( 0x18 ),	/* 24 */
/* 5072 */	NdrFcShort( 0x30 ),	/* ia64 Stack size/offset = 48 */
/* 5074 */	NdrFcShort( 0x16 ),	/* 22 */
/* 5076 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5078 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x5,		/* 5 */
/* 5080 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5082 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5084 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5086 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5088 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter on */

/* 5090 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5092 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5094 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter level */

/* 5096 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5098 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5100 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter snapShotPath */

/* 5102 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
/* 5104 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5106 */	NdrFcShort( 0x2a2 ),	/* Type Offset=674 */

	/* Parameter resetTrace */

/* 5108 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5110 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 5112 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5114 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5116 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 5118 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetDbPathAndName */

/* 5120 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5122 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5126 */	NdrFcShort( 0x3 ),	/* 3 */
/* 5128 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 5130 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5132 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5134 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 5136 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5138 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5140 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5142 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5144 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pDbPathAndName */

/* 5146 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 5148 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5150 */	NdrFcShort( 0x2b6 ),	/* Type Offset=694 */

	/* Parameter bufferSize */

/* 5152 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5154 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5156 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5158 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5160 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5162 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetId */

/* 5164 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5166 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5170 */	NdrFcShort( 0x4 ),	/* 4 */
/* 5172 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5174 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5176 */	NdrFcShort( 0x4c ),	/* 76 */
/* 5178 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5180 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5182 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5184 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5186 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5188 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pId */

/* 5190 */	NdrFcShort( 0x4112 ),	/* Flags:  must free, out, simple ref, srv alloc size=16 */
/* 5192 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5194 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Return value */

/* 5196 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5198 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5200 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetRegistryName */

/* 5202 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5204 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5208 */	NdrFcShort( 0x5 ),	/* 5 */
/* 5210 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 5212 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5214 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5216 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 5218 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5220 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5222 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5224 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5226 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pRegistryName */

/* 5228 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 5230 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5232 */	NdrFcShort( 0x2b6 ),	/* Type Offset=694 */

	/* Parameter bufferSize */

/* 5234 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5236 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5238 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5240 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5242 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5244 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetBuildVersion */

/* 5246 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5248 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5252 */	NdrFcShort( 0x6 ),	/* 6 */
/* 5254 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5256 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5258 */	NdrFcShort( 0x24 ),	/* 36 */
/* 5260 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5262 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5264 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5266 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5268 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5270 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pBuildVersion */

/* 5272 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5274 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5276 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5278 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5280 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5282 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetNtProductVersion */

/* 5284 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5286 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5290 */	NdrFcShort( 0x7 ),	/* 7 */
/* 5292 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 5294 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5296 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5298 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x3,		/* 3 */
/* 5300 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5302 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5304 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5306 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5308 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pNtProductVersion */

/* 5310 */	NdrFcShort( 0x2013 ),	/* Flags:  must size, must free, out, srv alloc size=8 */
/* 5312 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5314 */	NdrFcShort( 0x2b6 ),	/* Type Offset=694 */

	/* Parameter bufferSize */

/* 5316 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5318 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5320 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5322 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5324 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5326 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetNtProductBuild */

/* 5328 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5330 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5334 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5336 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5338 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5340 */	NdrFcShort( 0x24 ),	/* 36 */
/* 5342 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5344 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5346 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5348 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5350 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5352 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pNtProductBuild */

/* 5354 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
/* 5356 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5358 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 5360 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5362 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5364 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetId */

/* 5366 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5368 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5372 */	NdrFcShort( 0xb ),	/* 11 */
/* 5374 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 5376 */	NdrFcShort( 0x30 ),	/* 48 */
/* 5378 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5380 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5382 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5384 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5386 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5388 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5390 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter id */

/* 5392 */	NdrFcShort( 0x8a ),	/* Flags:  must free, in, by val, */
/* 5394 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5396 */	NdrFcShort( 0x26 ),	/* Type Offset=38 */

	/* Return value */

/* 5398 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5400 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5402 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure CheckAccess */

/* 5404 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5406 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5410 */	NdrFcShort( 0xe ),	/* 14 */
/* 5412 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5414 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5416 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5418 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5420 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5422 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5424 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5426 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5428 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter AccessType */

/* 5430 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
/* 5432 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5434 */	0xe,		/* FC_ENUM32 */
			0x0,		/* 0 */

	/* Return value */

/* 5436 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5438 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5440 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetTrace */

/* 5442 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5444 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5448 */	NdrFcShort( 0xf ),	/* 15 */
/* 5450 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5452 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5454 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5456 */	0x45,		/* Oi2 Flags:  srv must size, has return, has ext, */
			0x2,		/* 2 */
/* 5458 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5460 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5462 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5464 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5466 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter ppTrace */

/* 5468 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
/* 5470 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5472 */	NdrFcShort( 0x33c ),	/* Type Offset=828 */

	/* Return value */

/* 5474 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5476 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5478 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetTrace */

/* 5480 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5482 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5486 */	NdrFcShort( 0x10 ),	/* 16 */
/* 5488 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5490 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5492 */	NdrFcShort( 0x8 ),	/* 8 */
/* 5494 */	0x46,		/* Oi2 Flags:  clt must size, has return, has ext, */
			0x2,		/* 2 */
/* 5496 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5498 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5500 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5502 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5504 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pTrace */

/* 5506 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
/* 5508 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5510 */	NdrFcShort( 0x340 ),	/* Type Offset=832 */

	/* Return value */

/* 5512 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5514 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5516 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure ChangeSysState */

/* 5518 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 5520 */	NdrFcLong( 0x0 ),	/* 0 */
/* 5524 */	NdrFcShort( 0x3 ),	/* 3 */
/* 5526 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 5528 */	NdrFcShort( 0x28 ),	/* 40 */
/* 5530 */	NdrFcShort( 0x30 ),	/* 48 */
/* 5532 */	0x44,		/* Oi2 Flags:  has return, has ext, */
			0x2,		/* 2 */
/* 5534 */	0xa,		/* 10 */
			0x1,		/* Ext Flags:  new corr desc, */
/* 5536 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5538 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5540 */	NdrFcShort( 0x0 ),	/* 0 */
/* 5542 */	NdrFcShort( 0x0 ),	/* 0 */

	/* Parameter pSysState */

/* 5544 */	NdrFcShort( 0x11a ),	/* Flags:  must free, in, out, simple ref, */
/* 5546 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 5548 */	NdrFcShort( 0x356 ),	/* Type Offset=854 */

	/* Return value */

/* 5550 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
/* 5552 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 5554 */	0x8,		/* FC_LONG */
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
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/*  4 */	NdrFcLong( 0x0 ),	/* 0 */
/*  8 */	NdrFcShort( 0x0 ),	/* 0 */
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 14 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 16 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 18 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 20 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 22 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 24 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 26 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 28 */	
			0x11, 0x0,	/* FC_RP */
/* 30 */	NdrFcShort( 0x8 ),	/* Offset= 8 (38) */
/* 32 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 34 */	NdrFcShort( 0x8 ),	/* 8 */
/* 36 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 38 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 40 */	NdrFcShort( 0x10 ),	/* 16 */
/* 42 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 44 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 46 */	0x0,		/* 0 */
			NdrFcShort( 0xfff1 ),	/* Offset= -15 (32) */
			0x5b,		/* FC_END */
/* 50 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 52 */	NdrFcShort( 0x2 ),	/* Offset= 2 (54) */
/* 54 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 56 */	0x2b,		/* Corr desc:  parameter, FC_HYPER */
			0x0,		/*  */
/* 58 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 60 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 62 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 64 */	NdrFcShort( 0x2 ),	/* Offset= 2 (66) */
/* 66 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 68 */	0x2b,		/* Corr desc:  parameter, FC_HYPER */
			0x0,		/*  */
/* 70 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 72 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 74 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 76 */	NdrFcShort( 0x2 ),	/* Offset= 2 (78) */
/* 78 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 80 */	NdrFcLong( 0x9c7d6f14 ),	/* -1669501164 */
/* 84 */	NdrFcShort( 0x1562 ),	/* 5474 */
/* 86 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 88 */	0x81,		/* 129 */
			0xac,		/* 172 */
/* 90 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 92 */	0xc9,		/* 201 */
			0x11,		/* 17 */
/* 94 */	0x80,		/* 128 */
			0xf2,		/* 242 */
/* 96 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 98 */	NdrFcShort( 0x2 ),	/* Offset= 2 (100) */
/* 100 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 102 */	NdrFcLong( 0x100 ),	/* 256 */
/* 106 */	NdrFcShort( 0x0 ),	/* 0 */
/* 108 */	NdrFcShort( 0x0 ),	/* 0 */
/* 110 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 112 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 114 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 116 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 118 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 120 */	NdrFcShort( 0x2 ),	/* Offset= 2 (122) */
/* 122 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 124 */	0x2b,		/* Corr desc:  parameter, FC_HYPER */
			0x0,		/*  */
/* 126 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 128 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 130 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 132 */	NdrFcShort( 0x2 ),	/* Offset= 2 (134) */
/* 134 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 136 */	0x2b,		/* Corr desc:  parameter, FC_HYPER */
			0x0,		/*  */
/* 138 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 140 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 142 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 144 */	NdrFcShort( 0x2 ),	/* Offset= 2 (146) */
/* 146 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 148 */	0x2b,		/* Corr desc:  parameter, FC_HYPER */
			0x0,		/*  */
/* 150 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 152 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 154 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 156 */	NdrFcShort( 0x2 ),	/* Offset= 2 (158) */
/* 158 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 160 */	0x2b,		/* Corr desc:  parameter, FC_HYPER */
			0x0,		/*  */
/* 162 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 164 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 166 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 168 */	NdrFcShort( 0x2 ),	/* Offset= 2 (170) */
/* 170 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 172 */	0x2b,		/* Corr desc:  parameter, FC_HYPER */
			0x0,		/*  */
/* 174 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 176 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 178 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 180 */	NdrFcShort( 0x2 ),	/* Offset= 2 (182) */
/* 182 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 184 */	0x2b,		/* Corr desc:  parameter, FC_HYPER */
			0x0,		/*  */
/* 186 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 188 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 190 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 192 */	NdrFcShort( 0x2 ),	/* Offset= 2 (194) */
/* 194 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 196 */	0x2b,		/* Corr desc:  parameter, FC_HYPER */
			0x0,		/*  */
/* 198 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 200 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 202 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 204 */	NdrFcShort( 0x2 ),	/* Offset= 2 (206) */
/* 206 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 208 */	0x2b,		/* Corr desc:  parameter, FC_HYPER */
			0x0,		/*  */
/* 210 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 212 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 214 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 216 */	NdrFcLong( 0x9c7d6f0f ),	/* -1669501169 */
/* 220 */	NdrFcShort( 0x1562 ),	/* 5474 */
/* 222 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 224 */	0x81,		/* 129 */
			0xac,		/* 172 */
/* 226 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 228 */	0xc9,		/* 201 */
			0x11,		/* 17 */
/* 230 */	0x80,		/* 128 */
			0xf2,		/* 242 */
/* 232 */	
			0x11, 0x0,	/* FC_RP */
/* 234 */	NdrFcShort( 0xa ),	/* Offset= 10 (244) */
/* 236 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 238 */	0x2b,		/* Corr desc:  parameter, FC_HYPER */
			0x0,		/*  */
/* 240 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 242 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 244 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 246 */	NdrFcShort( 0x0 ),	/* 0 */
/* 248 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 250 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 252 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 254 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 256 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 258 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 260 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 262 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (236) */
/* 264 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 266 */	
			0x11, 0x0,	/* FC_RP */
/* 268 */	NdrFcShort( 0xa ),	/* Offset= 10 (278) */
/* 270 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 272 */	0x2b,		/* Corr desc:  parameter, FC_HYPER */
			0x0,		/*  */
/* 274 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 276 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 278 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 280 */	NdrFcShort( 0x0 ),	/* 0 */
/* 282 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 284 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 286 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 288 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 290 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 292 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 294 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 296 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (270) */
/* 298 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 300 */	
			0x11, 0x0,	/* FC_RP */
/* 302 */	NdrFcShort( 0xa ),	/* Offset= 10 (312) */
/* 304 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 306 */	0x2b,		/* Corr desc:  parameter, FC_HYPER */
			0x0,		/*  */
/* 308 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 310 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 312 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 314 */	NdrFcShort( 0x0 ),	/* 0 */
/* 316 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 318 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 320 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 322 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 324 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 326 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 328 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 330 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (304) */
/* 332 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 334 */	
			0x11, 0x0,	/* FC_RP */
/* 336 */	NdrFcShort( 0xa ),	/* Offset= 10 (346) */
/* 338 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 340 */	0x2b,		/* Corr desc:  parameter, FC_HYPER */
			0x0,		/*  */
/* 342 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 344 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 346 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 348 */	NdrFcShort( 0x0 ),	/* 0 */
/* 350 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 352 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 354 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 356 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 358 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 360 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 362 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 364 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (338) */
/* 366 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 368 */	
			0x11, 0x0,	/* FC_RP */
/* 370 */	NdrFcShort( 0xa ),	/* Offset= 10 (380) */
/* 372 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 374 */	0x2b,		/* Corr desc:  parameter, FC_HYPER */
			0x0,		/*  */
/* 376 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 378 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 380 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 382 */	NdrFcShort( 0x0 ),	/* 0 */
/* 384 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 386 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 388 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 390 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 392 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 394 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 396 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 398 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (372) */
/* 400 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 402 */	
			0x11, 0x0,	/* FC_RP */
/* 404 */	NdrFcShort( 0xa ),	/* Offset= 10 (414) */
/* 406 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 408 */	0x2b,		/* Corr desc:  parameter, FC_HYPER */
			0x0,		/*  */
/* 410 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 412 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 414 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 416 */	NdrFcShort( 0x0 ),	/* 0 */
/* 418 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 420 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 422 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 424 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 426 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 428 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 430 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 432 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (406) */
/* 434 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 436 */	
			0x11, 0x0,	/* FC_RP */
/* 438 */	NdrFcShort( 0xa ),	/* Offset= 10 (448) */
/* 440 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 442 */	0x2b,		/* Corr desc:  parameter, FC_HYPER */
			0x0,		/*  */
/* 444 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 446 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 448 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 450 */	NdrFcShort( 0x0 ),	/* 0 */
/* 452 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 454 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 456 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 458 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 460 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 462 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 464 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 466 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (440) */
/* 468 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 470 */	
			0x11, 0x0,	/* FC_RP */
/* 472 */	NdrFcShort( 0xa ),	/* Offset= 10 (482) */
/* 474 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 476 */	0x2b,		/* Corr desc:  parameter, FC_HYPER */
			0x0,		/*  */
/* 478 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 480 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 482 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 484 */	NdrFcShort( 0x0 ),	/* 0 */
/* 486 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 488 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 490 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 492 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 494 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 496 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 498 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 500 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (474) */
/* 502 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 504 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 506 */	NdrFcLong( 0xa0ff1f41 ),	/* -1593893055 */
/* 510 */	NdrFcShort( 0x237a ),	/* 9082 */
/* 512 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 514 */	0x81,		/* 129 */
			0xba,		/* 186 */
/* 516 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 518 */	0xc9,		/* 201 */
			0x11,		/* 17 */
/* 520 */	0x80,		/* 128 */
			0xf2,		/* 242 */
/* 522 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 524 */	NdrFcShort( 0xfe1a ),	/* Offset= -486 (38) */
/* 526 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 528 */	NdrFcShort( 0x2 ),	/* Offset= 2 (530) */
/* 530 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 532 */	0x2b,		/* Corr desc:  parameter, FC_HYPER */
			0x0,		/*  */
/* 534 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 536 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 538 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 540 */	NdrFcShort( 0x2 ),	/* Offset= 2 (542) */
/* 542 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 544 */	0x2b,		/* Corr desc:  parameter, FC_HYPER */
			0x0,		/*  */
/* 546 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 548 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 550 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 552 */	NdrFcShort( 0x2 ),	/* Offset= 2 (554) */
/* 554 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 556 */	0x2b,		/* Corr desc:  parameter, FC_HYPER */
			0x0,		/*  */
/* 558 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 560 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 562 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 564 */	NdrFcShort( 0x2 ),	/* Offset= 2 (566) */
/* 566 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 568 */	0x2b,		/* Corr desc:  parameter, FC_HYPER */
			0x0,		/*  */
/* 570 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 572 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 574 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 576 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 578 */	
			0x11, 0x0,	/* FC_RP */
/* 580 */	NdrFcShort( 0xa ),	/* Offset= 10 (590) */
/* 582 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 584 */	0x2b,		/* Corr desc:  parameter, FC_HYPER */
			0x0,		/*  */
/* 586 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 588 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 590 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 592 */	NdrFcShort( 0x0 ),	/* 0 */
/* 594 */	0x20,		/* Corr desc:  parameter,  */
			0x59,		/* FC_CALLBACK */
/* 596 */	NdrFcShort( 0x0 ),	/* 0 */
/* 598 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 600 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 602 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 604 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 606 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 608 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (582) */
/* 610 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 612 */	
			0x11, 0x0,	/* FC_RP */
/* 614 */	NdrFcShort( 0xa ),	/* Offset= 10 (624) */
/* 616 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 618 */	0x2b,		/* Corr desc:  parameter, FC_HYPER */
			0x0,		/*  */
/* 620 */	NdrFcShort( 0x28 ),	/* ia64 Stack size/offset = 40 */
/* 622 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 624 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 626 */	NdrFcShort( 0x0 ),	/* 0 */
/* 628 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 630 */	NdrFcShort( 0x20 ),	/* ia64 Stack size/offset = 32 */
/* 632 */	NdrFcShort( 0x1 ),	/* Corr flags:  early, */
/* 634 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x54,		/* FC_DEREFERENCE */
/* 636 */	NdrFcShort( 0x38 ),	/* ia64 Stack size/offset = 56 */
/* 638 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 640 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 642 */	NdrFcShort( 0xffe6 ),	/* Offset= -26 (616) */
/* 644 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 646 */	
			0x11, 0x0,	/* FC_RP */
/* 648 */	NdrFcShort( 0x2 ),	/* Offset= 2 (650) */
/* 650 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 652 */	NdrFcShort( 0x0 ),	/* 0 */
/* 654 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 656 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 658 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 660 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 664 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 666 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 668 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 670 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 672 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 674 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 676 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 678 */	NdrFcLong( 0xdb35d731 ),	/* -617228495 */
/* 682 */	NdrFcShort( 0x21e9 ),	/* 8681 */
/* 684 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 686 */	0x81,		/* 129 */
			0xb8,		/* 184 */
/* 688 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 690 */	0xc9,		/* 201 */
			0x11,		/* 17 */
/* 692 */	0x80,		/* 128 */
			0xf2,		/* 242 */
/* 694 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 696 */	NdrFcShort( 0x2 ),	/* Offset= 2 (698) */
/* 698 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 700 */	
			0x25,		/* FC_C_WSTRING */
			0x5c,		/* FC_PAD */
/* 702 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 704 */	NdrFcShort( 0x2 ),	/* Offset= 2 (706) */
/* 706 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 708 */	NdrFcLong( 0x1973831 ),	/* 26687537 */
/* 712 */	NdrFcShort( 0xe996 ),	/* -5738 */
/* 714 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 716 */	0x99,		/* 153 */
			0x28,		/* 40 */
/* 718 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 720 */	0xc9,		/* 201 */
			0x5,		/* 5 */
/* 722 */	0x8b,		/* 139 */
			0xf6,		/* 246 */
/* 724 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 726 */	NdrFcShort( 0x2 ),	/* Offset= 2 (728) */
/* 728 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 730 */	0x2b,		/* Corr desc:  parameter, FC_HYPER */
			0x0,		/*  */
/* 732 */	NdrFcShort( 0x18 ),	/* ia64 Stack size/offset = 24 */
/* 734 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 736 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] [pointer_deref] */
/* 738 */	NdrFcShort( 0xffe0 ),	/* Offset= -32 (706) */
/* 740 */	
			0x11, 0x0,	/* FC_RP */
/* 742 */	NdrFcShort( 0x2 ),	/* Offset= 2 (744) */
/* 744 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 746 */	NdrFcShort( 0x1 ),	/* 1 */
/* 748 */	0x29,		/* Corr desc:  parameter, FC_ULONG */
			0x0,		/*  */
/* 750 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 752 */	NdrFcShort( 0x0 ),	/* Corr flags:  */
/* 754 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 756 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 758 */	NdrFcShort( 0x8 ),	/* 8 */
/* 760 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 762 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 764 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 766 */	NdrFcShort( 0x2 ),	/* Offset= 2 (768) */
/* 768 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 770 */	0x2b,		/* Corr desc:  parameter, FC_HYPER */
			0x0,		/*  */
/* 772 */	NdrFcShort( 0x8 ),	/* ia64 Stack size/offset = 8 */
/* 774 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 776 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 778 */	NdrFcLong( 0xc ),	/* 12 */
/* 782 */	NdrFcShort( 0x0 ),	/* 0 */
/* 784 */	NdrFcShort( 0x0 ),	/* 0 */
/* 786 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 788 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 790 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 792 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 794 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 796 */	NdrFcLong( 0x46ce9eda ),	/* 1187946202 */
/* 800 */	NdrFcShort( 0x447c ),	/* 17532 */
/* 802 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 804 */	0x98,		/* 152 */
			0xfc,		/* 252 */
/* 806 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 808 */	0xc9,		/* 201 */
			0x5,		/* 5 */
/* 810 */	0x8b,		/* 139 */
			0xf6,		/* 246 */
/* 812 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 814 */	NdrFcShort( 0x2 ),	/* Offset= 2 (816) */
/* 816 */	
			0x2f,		/* FC_IP */
			0x5c,		/* FC_PAD */
/* 818 */	0x2b,		/* Corr desc:  parameter, FC_HYPER */
			0x0,		/*  */
/* 820 */	NdrFcShort( 0x10 ),	/* ia64 Stack size/offset = 16 */
/* 822 */	NdrFcShort( 0x5 ),	/* Corr flags:  early, iid_is, */
/* 824 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 826 */	0xb,		/* FC_HYPER */
			0x5c,		/* FC_PAD */
/* 828 */	
			0x11, 0x10,	/* FC_RP [pointer_deref] */
/* 830 */	NdrFcShort( 0x2 ),	/* Offset= 2 (832) */
/* 832 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 834 */	NdrFcLong( 0xaf2da10 ),	/* 183687696 */
/* 838 */	NdrFcShort( 0x7dd7 ),	/* 32215 */
/* 840 */	NdrFcShort( 0x11d0 ),	/* 4560 */
/* 842 */	0x9e,		/* 158 */
			0x33,		/* 51 */
/* 844 */	0x0,		/* 0 */
			0xa0,		/* 160 */
/* 846 */	0xc9,		/* 201 */
			0x16,		/* 22 */
/* 848 */	0xf1,		/* 241 */
			0x20,		/* 32 */
/* 850 */	
			0x11, 0x0,	/* FC_RP */
/* 852 */	NdrFcShort( 0x2 ),	/* Offset= 2 (854) */
/* 854 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 856 */	NdrFcShort( 0x4 ),	/* 4 */
/* 858 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */

			0x0
        }
    };

static void __RPC_USER IWsbIndexedCollection_CopyExprEval_0000( PMIDL_STUB_MESSAGE pStubMsg )
{
    #pragma pack(8)
    struct _PARAM_STRUCT
        {
        IHsmEvent *This;
        ULONG start;
        char Pad0[4];
        ULONG stop;
        char Pad1[4];
        REFIID riid;
        void **elements;
        ULONG *pElementsFetched;
        HRESULT _RetVal;
        };
    #pragma pack()
    struct _PARAM_STRUCT *pS	=	( struct _PARAM_STRUCT * )pStubMsg->StackTop;
    
    pStubMsg->Offset = 0;
    pStubMsg->MaxCount = (ULONG_PTR) ( pS->stop > pS->start ? pS->stop - pS->start : pS->start - pS->stop );
}

static const EXPR_EVAL ExprEvalRoutines[] = 
    {
    IWsbIndexedCollection_CopyExprEval_0000
    };



/* Standard interface: __MIDL_itf_wsbint_0000, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IWsbCollectable, ver. 0.0,
   GUID={0x9C7D6F0A,0x1562,0x11D0,{0x81,0xAC,0x00,0xA0,0xC9,0x11,0x80,0xF2}} */

#pragma code_seg(".orpc")
static const unsigned short IWsbCollectable_FormatStringOffsetTable[] =
    {
    0,
    44
    };

static const MIDL_STUBLESS_PROXY_INFO IWsbCollectable_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IWsbCollectable_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWsbCollectable_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IWsbCollectable_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(5) _IWsbCollectableProxyVtbl = 
{
    &IWsbCollectable_ProxyInfo,
    &IID_IWsbCollectable,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWsbCollectable::CompareTo */ ,
    (void *) (INT_PTR) -1 /* IWsbCollectable::IsEqual */
};

const CInterfaceStubVtbl _IWsbCollectableStubVtbl =
{
    &IID_IWsbCollectable,
    &IWsbCollectable_ServerInfo,
    5,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWsbCollection, ver. 0.0,
   GUID={0x9C7D6F0F,0x1562,0x11D0,{0x81,0xAC,0x00,0xA0,0xC9,0x11,0x80,0xF2}} */

#pragma code_seg(".orpc")
static const unsigned short IWsbCollection_FormatStringOffsetTable[] =
    {
    82,
    44,
    120,
    158,
    208,
    240,
    272,
    304,
    348,
    398,
    436,
    468,
    500,
    538
    };

static const MIDL_STUBLESS_PROXY_INFO IWsbCollection_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IWsbCollection_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWsbCollection_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IWsbCollection_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(17) _IWsbCollectionProxyVtbl = 
{
    &IWsbCollection_ProxyInfo,
    &IID_IWsbCollection,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWsbCollection::Add */ ,
    (void *) (INT_PTR) -1 /* IWsbCollection::Contains */ ,
    (void *) (INT_PTR) -1 /* IWsbCollection::GetEntries */ ,
    (void *) (INT_PTR) -1 /* IWsbCollection::Find */ ,
    (void *) (INT_PTR) -1 /* IWsbCollection::IsEmpty */ ,
    (void *) (INT_PTR) -1 /* IWsbCollection::IsLocked */ ,
    (void *) (INT_PTR) -1 /* IWsbCollection::Lock */ ,
    (void *) (INT_PTR) -1 /* IWsbCollection::OccurencesOf */ ,
    (void *) (INT_PTR) -1 /* IWsbCollection::Remove */ ,
    (void *) (INT_PTR) -1 /* IWsbCollection::RemoveAndRelease */ ,
    (void *) (INT_PTR) -1 /* IWsbCollection::RemoveAllAndRelease */ ,
    (void *) (INT_PTR) -1 /* IWsbCollection::Unlock */ ,
    (void *) (INT_PTR) -1 /* IWsbCollection::Enum */ ,
    (void *) (INT_PTR) -1 /* IWsbCollection::EnumUnknown */
};

const CInterfaceStubVtbl _IWsbCollectionStubVtbl =
{
    &IID_IWsbCollection,
    &IWsbCollection_ServerInfo,
    17,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWsbEnum, ver. 0.0,
   GUID={0x9C7D6F14,0x1562,0x11D0,{0x81,0xAC,0x00,0xA0,0xC9,0x11,0x80,0xF2}} */

#pragma code_seg(".orpc")
static const unsigned short IWsbEnum_FormatStringOffsetTable[] =
    {
    576,
    620,
    664,
    708,
    752,
    796,
    846,
    896,
    946,
    978,
    1016,
    1054,
    1092,
    1124,
    1156,
    1194
    };

static const MIDL_STUBLESS_PROXY_INFO IWsbEnum_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IWsbEnum_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWsbEnum_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IWsbEnum_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(19) _IWsbEnumProxyVtbl = 
{
    &IWsbEnum_ProxyInfo,
    &IID_IWsbEnum,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWsbEnum::First */ ,
    (void *) (INT_PTR) -1 /* IWsbEnum::Next */ ,
    (void *) (INT_PTR) -1 /* IWsbEnum::This */ ,
    (void *) (INT_PTR) -1 /* IWsbEnum::Previous */ ,
    (void *) (INT_PTR) -1 /* IWsbEnum::Last */ ,
    (void *) (INT_PTR) -1 /* IWsbEnum::FindNext */ ,
    (void *) (INT_PTR) -1 /* IWsbEnum::Find */ ,
    (void *) (INT_PTR) -1 /* IWsbEnum::FindPrevious */ ,
    (void *) (INT_PTR) -1 /* IWsbEnum::SkipToFirst */ ,
    (void *) (INT_PTR) -1 /* IWsbEnum::SkipNext */ ,
    (void *) (INT_PTR) -1 /* IWsbEnum::SkipTo */ ,
    (void *) (INT_PTR) -1 /* IWsbEnum::SkipPrevious */ ,
    (void *) (INT_PTR) -1 /* IWsbEnum::SkipToLast */ ,
    (void *) (INT_PTR) -1 /* IWsbEnum::Reset */ ,
    (void *) (INT_PTR) -1 /* IWsbEnum::Init */ ,
    (void *) (INT_PTR) -1 /* IWsbEnum::Clone */
};

const CInterfaceStubVtbl _IWsbEnumStubVtbl =
{
    &IID_IWsbEnum,
    &IWsbEnum_ServerInfo,
    19,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWsbEnumEx, ver. 0.0,
   GUID={0xF5A3AC60,0x9993,0x11d0,{0x81,0xE7,0x00,0xA0,0xC9,0x11,0x80,0xF2}} */

#pragma code_seg(".orpc")
static const unsigned short IWsbEnumEx_FormatStringOffsetTable[] =
    {
    1232,
    1288,
    1344,
    1400,
    1456,
    1512,
    1574,
    1636,
    946,
    978,
    1016,
    1054,
    1092,
    1124,
    1156,
    1194
    };

static const MIDL_STUBLESS_PROXY_INFO IWsbEnumEx_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IWsbEnumEx_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWsbEnumEx_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IWsbEnumEx_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(19) _IWsbEnumExProxyVtbl = 
{
    &IWsbEnumEx_ProxyInfo,
    &IID_IWsbEnumEx,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWsbEnumEx::First */ ,
    (void *) (INT_PTR) -1 /* IWsbEnumEx::Next */ ,
    (void *) (INT_PTR) -1 /* IWsbEnumEx::This */ ,
    (void *) (INT_PTR) -1 /* IWsbEnumEx::Previous */ ,
    (void *) (INT_PTR) -1 /* IWsbEnumEx::Last */ ,
    (void *) (INT_PTR) -1 /* IWsbEnumEx::FindNext */ ,
    (void *) (INT_PTR) -1 /* IWsbEnumEx::Find */ ,
    (void *) (INT_PTR) -1 /* IWsbEnumEx::FindPrevious */ ,
    (void *) (INT_PTR) -1 /* IWsbEnumEx::SkipToFirst */ ,
    (void *) (INT_PTR) -1 /* IWsbEnumEx::SkipNext */ ,
    (void *) (INT_PTR) -1 /* IWsbEnumEx::SkipTo */ ,
    (void *) (INT_PTR) -1 /* IWsbEnumEx::SkipPrevious */ ,
    (void *) (INT_PTR) -1 /* IWsbEnumEx::SkipToLast */ ,
    (void *) (INT_PTR) -1 /* IWsbEnumEx::Reset */ ,
    (void *) (INT_PTR) -1 /* IWsbEnumEx::Init */ ,
    (void *) (INT_PTR) -1 /* IWsbEnumEx::Clone */
};

const CInterfaceStubVtbl _IWsbEnumExStubVtbl =
{
    &IID_IWsbEnumEx,
    &IWsbEnumEx_ServerInfo,
    19,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWsbGuid, ver. 0.0,
   GUID={0xA0FF1F41,0x237A,0x11D0,{0x81,0xBA,0x00,0xA0,0xC9,0x11,0x80,0xF2}} */

#pragma code_seg(".orpc")
static const unsigned short IWsbGuid_FormatStringOffsetTable[] =
    {
    0,
    44,
    1698,
    1742,
    1786,
    1824
    };

static const MIDL_STUBLESS_PROXY_INFO IWsbGuid_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IWsbGuid_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWsbGuid_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IWsbGuid_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(9) _IWsbGuidProxyVtbl = 
{
    &IWsbGuid_ProxyInfo,
    &IID_IWsbGuid,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWsbCollectable::CompareTo */ ,
    (void *) (INT_PTR) -1 /* IWsbCollectable::IsEqual */ ,
    (void *) (INT_PTR) -1 /* IWsbGuid::CompareToGuid */ ,
    (void *) (INT_PTR) -1 /* IWsbGuid::CompareToIGuid */ ,
    (void *) (INT_PTR) -1 /* IWsbGuid::GetGuid */ ,
    (void *) (INT_PTR) -1 /* IWsbGuid::SetGuid */
};

const CInterfaceStubVtbl _IWsbGuidStubVtbl =
{
    &IID_IWsbGuid,
    &IWsbGuid_ServerInfo,
    9,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWsbIndexedCollection, ver. 0.0,
   GUID={0xA5B69200,0x214B,0x11D0,{0x81,0xB7,0x00,0xA0,0xC9,0x11,0x80,0xF2}} */

#pragma code_seg(".orpc")
static const unsigned short IWsbIndexedCollection_FormatStringOffsetTable[] =
    {
    82,
    44,
    120,
    158,
    208,
    240,
    272,
    304,
    348,
    398,
    436,
    468,
    500,
    538,
    1862,
    1906,
    1944,
    1982,
    2032,
    2076,
    2126,
    2170,
    2214,
    2276
    };

static const MIDL_STUBLESS_PROXY_INFO IWsbIndexedCollection_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IWsbIndexedCollection_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWsbIndexedCollection_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IWsbIndexedCollection_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(27) _IWsbIndexedCollectionProxyVtbl = 
{
    &IWsbIndexedCollection_ProxyInfo,
    &IID_IWsbIndexedCollection,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWsbCollection::Add */ ,
    (void *) (INT_PTR) -1 /* IWsbCollection::Contains */ ,
    (void *) (INT_PTR) -1 /* IWsbCollection::GetEntries */ ,
    (void *) (INT_PTR) -1 /* IWsbCollection::Find */ ,
    (void *) (INT_PTR) -1 /* IWsbCollection::IsEmpty */ ,
    (void *) (INT_PTR) -1 /* IWsbCollection::IsLocked */ ,
    (void *) (INT_PTR) -1 /* IWsbCollection::Lock */ ,
    (void *) (INT_PTR) -1 /* IWsbCollection::OccurencesOf */ ,
    (void *) (INT_PTR) -1 /* IWsbCollection::Remove */ ,
    (void *) (INT_PTR) -1 /* IWsbCollection::RemoveAndRelease */ ,
    (void *) (INT_PTR) -1 /* IWsbCollection::RemoveAllAndRelease */ ,
    (void *) (INT_PTR) -1 /* IWsbCollection::Unlock */ ,
    (void *) (INT_PTR) -1 /* IWsbCollection::Enum */ ,
    (void *) (INT_PTR) -1 /* IWsbCollection::EnumUnknown */ ,
    (void *) (INT_PTR) -1 /* IWsbIndexedCollection::AddAt */ ,
    (void *) (INT_PTR) -1 /* IWsbIndexedCollection::Append */ ,
    (void *) (INT_PTR) -1 /* IWsbIndexedCollection::Prepend */ ,
    (void *) (INT_PTR) -1 /* IWsbIndexedCollection::RemoveAt */ ,
    (void *) (INT_PTR) -1 /* IWsbIndexedCollection::First */ ,
    (void *) (INT_PTR) -1 /* IWsbIndexedCollection::At */ ,
    (void *) (INT_PTR) -1 /* IWsbIndexedCollection::Last */ ,
    (void *) (INT_PTR) -1 /* IWsbIndexedCollection::Index */ ,
    (void *) (INT_PTR) -1 /* IWsbIndexedCollection::Copy */ ,
    (void *) (INT_PTR) -1 /* IWsbIndexedCollection::CopyIfMatches */
};

const CInterfaceStubVtbl _IWsbIndexedCollectionStubVtbl =
{
    &IID_IWsbIndexedCollection,
    &IWsbIndexedCollection_ServerInfo,
    27,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWsbPersistStream, ver. 0.0,
   GUID={0xC4D14AA2,0x79EE,0x11D0,{0x99,0x09,0x00,0xA0,0xC9,0x05,0x8B,0xF6}} */

#pragma code_seg(".orpc")
static const unsigned short IWsbPersistStream_FormatStringOffsetTable[] =
    {
    2356
    };

static const MIDL_STUBLESS_PROXY_INFO IWsbPersistStream_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IWsbPersistStream_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWsbPersistStream_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IWsbPersistStream_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IWsbPersistStreamProxyVtbl = 
{
    &IWsbPersistStream_ProxyInfo,
    &IID_IWsbPersistStream,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWsbPersistStream::SetIsDirty */
};

const CInterfaceStubVtbl _IWsbPersistStreamStubVtbl =
{
    &IID_IWsbPersistStream,
    &IWsbPersistStream_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWsbPersistable, ver. 0.0,
   GUID={0x5BF46531,0x282D,0x11D0,{0x81,0xBE,0x00,0xA0,0xC9,0x11,0x80,0xF2}} */

#pragma code_seg(".orpc")
static const unsigned short IWsbPersistable_FormatStringOffsetTable[] =
    {
    2356,
    2394,
    2438,
    2470
    };

static const MIDL_STUBLESS_PROXY_INFO IWsbPersistable_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IWsbPersistable_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWsbPersistable_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IWsbPersistable_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(7) _IWsbPersistableProxyVtbl = 
{
    &IWsbPersistable_ProxyInfo,
    &IID_IWsbPersistable,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWsbPersistStream::SetIsDirty */ ,
    (void *) (INT_PTR) -1 /* IWsbPersistable::GetDefaultFileName */ ,
    (void *) (INT_PTR) -1 /* IWsbPersistable::ReleaseFile */ ,
    (void *) (INT_PTR) -1 /* IWsbPersistable::SetDefaultFileName */
};

const CInterfaceStubVtbl _IWsbPersistableStubVtbl =
{
    &IID_IWsbPersistable,
    &IWsbPersistable_ServerInfo,
    7,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWsbString, ver. 0.0,
   GUID={0xDB35D731,0x21E9,0x11D0,{0x81,0xB8,0x00,0xA0,0xC9,0x11,0x80,0xF2}} */

#pragma code_seg(".orpc")
static const unsigned short IWsbString_FormatStringOffsetTable[] =
    {
    0,
    44,
    2508,
    2552,
    2596,
    2640,
    272,
    2690,
    2728,
    2766
    };

static const MIDL_STUBLESS_PROXY_INFO IWsbString_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IWsbString_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWsbString_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IWsbString_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(13) _IWsbStringProxyVtbl = 
{
    &IWsbString_ProxyInfo,
    &IID_IWsbString,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWsbCollectable::CompareTo */ ,
    (void *) (INT_PTR) -1 /* IWsbCollectable::IsEqual */ ,
    (void *) (INT_PTR) -1 /* IWsbString::CompareToString */ ,
    (void *) (INT_PTR) -1 /* IWsbString::CompareToIString */ ,
    (void *) (INT_PTR) -1 /* IWsbString::GetString */ ,
    (void *) (INT_PTR) -1 /* IWsbString::GetStringAndCase */ ,
    (void *) (INT_PTR) -1 /* IWsbString::IsCaseDependent */ ,
    (void *) (INT_PTR) -1 /* IWsbString::SetIsCaseDependent */ ,
    (void *) (INT_PTR) -1 /* IWsbString::SetString */ ,
    (void *) (INT_PTR) -1 /* IWsbString::SetStringAndCase */
};

const CInterfaceStubVtbl _IWsbStringStubVtbl =
{
    &IID_IWsbString,
    &IWsbString_ServerInfo,
    13,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWsbTestable, ver. 0.0,
   GUID={0x05342021,0x25D8,0x11D0,{0x81,0xBB,0x00,0xA0,0xC9,0x11,0x80,0xF2}} */

#pragma code_seg(".orpc")
static const unsigned short IWsbTestable_FormatStringOffsetTable[] =
    {
    2810
    };

static const MIDL_STUBLESS_PROXY_INFO IWsbTestable_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IWsbTestable_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWsbTestable_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IWsbTestable_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IWsbTestableProxyVtbl = 
{
    &IWsbTestable_ProxyInfo,
    &IID_IWsbTestable,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWsbTestable::Test */
};

const CInterfaceStubVtbl _IWsbTestableStubVtbl =
{
    &IID_IWsbTestable,
    &IWsbTestable_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWsbDbSys, ver. 0.0,
   GUID={0xF2608980,0x0A45,0x47B4,{0xB1,0x10,0x37,0xEA,0x59,0xF6,0x7C,0x47}} */

#pragma code_seg(".orpc")
static const unsigned short IWsbDbSys_FormatStringOffsetTable[] =
    {
    2854,
    2898,
    2438,
    2942,
    2980,
    3018,
    272
    };

static const MIDL_STUBLESS_PROXY_INFO IWsbDbSys_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IWsbDbSys_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWsbDbSys_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IWsbDbSys_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(10) _IWsbDbSysProxyVtbl = 
{
    &IWsbDbSys_ProxyInfo,
    &IID_IWsbDbSys,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWsbDbSys::Backup */ ,
    (void *) (INT_PTR) -1 /* IWsbDbSys::Init */ ,
    (void *) (INT_PTR) -1 /* IWsbDbSys::Terminate */ ,
    (void *) (INT_PTR) -1 /* IWsbDbSys::NewSession */ ,
    (void *) (INT_PTR) -1 /* IWsbDbSys::GetGlobalSession */ ,
    (void *) (INT_PTR) -1 /* IWsbDbSys::Restore */ ,
    (void *) (INT_PTR) -1 /* IWsbDbSys::IncrementChangeCount */
};

const CInterfaceStubVtbl _IWsbDbSysStubVtbl =
{
    &IID_IWsbDbSys,
    &IWsbDbSys_ServerInfo,
    10,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWsbDb, ver. 0.0,
   GUID={0xD7A42F4A,0x117C,0x47A3,{0x9C,0x30,0x92,0xD6,0x3A,0x49,0x19,0xE4}} */

#pragma code_seg(".orpc")
static const unsigned short IWsbDb_FormatStringOffsetTable[] =
    {
    3062,
    2898,
    3100,
    3144,
    3194,
    3250,
    3288,
    3326,
    2728,
    3364
    };

static const MIDL_STUBLESS_PROXY_INFO IWsbDb_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IWsbDb_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWsbDb_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IWsbDb_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(13) _IWsbDbProxyVtbl = 
{
    &IWsbDb_ProxyInfo,
    &IID_IWsbDb,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWsbDb::Close */ ,
    (void *) (INT_PTR) -1 /* IWsbDb::Create */ ,
    (void *) (INT_PTR) -1 /* IWsbDb::Delete */ ,
    (void *) (INT_PTR) -1 /* IWsbDb::Dump */ ,
    (void *) (INT_PTR) -1 /* IWsbDb::GetEntity */ ,
    (void *) (INT_PTR) -1 /* IWsbDb::GetName */ ,
    (void *) (INT_PTR) -1 /* IWsbDb::GetPath */ ,
    (void *) (INT_PTR) -1 /* IWsbDb::GetVersion */ ,
    (void *) (INT_PTR) -1 /* IWsbDb::Locate */ ,
    (void *) (INT_PTR) -1 /* IWsbDb::Open */
};

const CInterfaceStubVtbl _IWsbDbStubVtbl =
{
    &IID_IWsbDb,
    &IWsbDb_ServerInfo,
    13,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWsbDbSession, ver. 0.0,
   GUID={0x01973831,0xE996,0x11d0,{0x99,0x28,0x00,0xA0,0xC9,0x05,0x8B,0xF6}} */

#pragma code_seg(".orpc")
static const unsigned short IWsbDbSession_FormatStringOffsetTable[] =
    {
    3402,
    3434,
    2438
    };

static const MIDL_STUBLESS_PROXY_INFO IWsbDbSession_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IWsbDbSession_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWsbDbSession_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IWsbDbSession_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(6) _IWsbDbSessionProxyVtbl = 
{
    &IWsbDbSession_ProxyInfo,
    &IID_IWsbDbSession,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWsbDbSession::TransactionBegin */ ,
    (void *) (INT_PTR) -1 /* IWsbDbSession::TransactionCancel */ ,
    (void *) (INT_PTR) -1 /* IWsbDbSession::TransactionEnd */
};

const CInterfaceStubVtbl _IWsbDbSessionStubVtbl =
{
    &IID_IWsbDbSession,
    &IWsbDbSession_ServerInfo,
    6,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWsbDbKey, ver. 0.0,
   GUID={0x46CE9EDA,0x447C,0x11D0,{0x98,0xFC,0x00,0xA0,0xC9,0x05,0x8B,0xF6}} */

#pragma code_seg(".orpc")
static const unsigned short IWsbDbKey_FormatStringOffsetTable[] =
    {
    2356,
    3466,
    3510,
    3548,
    3586,
    3624,
    3662,
    2690,
    3700,
    3744,
    3782,
    3820,
    3858,
    3896
    };

static const MIDL_STUBLESS_PROXY_INFO IWsbDbKey_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IWsbDbKey_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWsbDbKey_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IWsbDbKey_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(17) _IWsbDbKeyProxyVtbl = 
{
    &IWsbDbKey_ProxyInfo,
    &IID_IWsbDbKey,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWsbDbKey::AppendBool */ ,
    (void *) (INT_PTR) -1 /* IWsbDbKey::AppendBytes */ ,
    (void *) (INT_PTR) -1 /* IWsbDbKey::AppendFiletime */ ,
    (void *) (INT_PTR) -1 /* IWsbDbKey::AppendGuid */ ,
    (void *) (INT_PTR) -1 /* IWsbDbKey::AppendLonglong */ ,
    (void *) (INT_PTR) -1 /* IWsbDbKey::AppendString */ ,
    (void *) (INT_PTR) -1 /* IWsbDbKey::GetType */ ,
    (void *) (INT_PTR) -1 /* IWsbDbKey::SetToBool */ ,
    (void *) (INT_PTR) -1 /* IWsbDbKey::SetToBytes */ ,
    (void *) (INT_PTR) -1 /* IWsbDbKey::SetToFiletime */ ,
    (void *) (INT_PTR) -1 /* IWsbDbKey::SetToGuid */ ,
    (void *) (INT_PTR) -1 /* IWsbDbKey::SetToLonglong */ ,
    (void *) (INT_PTR) -1 /* IWsbDbKey::SetToUlong */ ,
    (void *) (INT_PTR) -1 /* IWsbDbKey::SetToString */
};

const CInterfaceStubVtbl _IWsbDbKeyStubVtbl =
{
    &IID_IWsbDbKey,
    &IWsbDbKey_ServerInfo,
    17,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWsbDbEntity, ver. 0.0,
   GUID={0xFC7FB18F,0xF497,0x47A6,{0xA2,0x8F,0x7C,0xC4,0xBF,0xEC,0xAA,0x5E}} */

#pragma code_seg(".orpc")
static const unsigned short IWsbDbEntity_FormatStringOffsetTable[] =
    {
    3934,
    3434,
    2438,
    3978,
    208,
    240,
    272,
    4010,
    946,
    4042,
    436,
    468,
    4074,
    1124,
    4112,
    4150,
    4188,
    4220,
    4252
    };

static const MIDL_STUBLESS_PROXY_INFO IWsbDbEntity_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IWsbDbEntity_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWsbDbEntity_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IWsbDbEntity_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(22) _IWsbDbEntityProxyVtbl = 
{
    &IWsbDbEntity_ProxyInfo,
    &IID_IWsbDbEntity,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWsbDbEntity::Clone */ ,
    (void *) (INT_PTR) -1 /* IWsbDbEntity::Disconnect */ ,
    (void *) (INT_PTR) -1 /* IWsbDbEntity::FindEQ */ ,
    (void *) (INT_PTR) -1 /* IWsbDbEntity::FindGT */ ,
    (void *) (INT_PTR) -1 /* IWsbDbEntity::FindGTE */ ,
    (void *) (INT_PTR) -1 /* IWsbDbEntity::FindLT */ ,
    (void *) (INT_PTR) -1 /* IWsbDbEntity::FindLTE */ ,
    (void *) (INT_PTR) -1 /* IWsbDbEntity::First */ ,
    (void *) (INT_PTR) -1 /* IWsbDbEntity::Last */ ,
    (void *) (INT_PTR) -1 /* IWsbDbEntity::MarkAsNew */ ,
    (void *) (INT_PTR) -1 /* IWsbDbEntity::Next */ ,
    (void *) (INT_PTR) -1 /* IWsbDbEntity::Previous */ ,
    (void *) (INT_PTR) -1 /* IWsbDbEntity::Print */ ,
    (void *) (INT_PTR) -1 /* IWsbDbEntity::Remove */ ,
    (void *) (INT_PTR) -1 /* IWsbDbEntity::UpdateKey */ ,
    (void *) (INT_PTR) -1 /* IWsbDbEntity::UseKey */ ,
    (void *) (INT_PTR) -1 /* IWsbDbEntity::Write */ ,
    (void *) (INT_PTR) -1 /* IWsbDbEntity::SetSequentialScan */ ,
    (void *) (INT_PTR) -1 /* IWsbDbEntity::ResetSequentialScan */
};

const CInterfaceStubVtbl _IWsbDbEntityStubVtbl =
{
    &IID_IWsbDbEntity,
    &IWsbDbEntity_ServerInfo,
    22,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWsbCreateLocalObject, ver. 0.0,
   GUID={0xEF5207D0,0x8C0B,0x11d0,{0x9E,0x39,0x00,0xA0,0xC9,0x16,0xF1,0x20}} */

#pragma code_seg(".orpc")
static const unsigned short IWsbCreateLocalObject_FormatStringOffsetTable[] =
    {
    4284
    };

static const MIDL_STUBLESS_PROXY_INFO IWsbCreateLocalObject_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IWsbCreateLocalObject_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWsbCreateLocalObject_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IWsbCreateLocalObject_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IWsbCreateLocalObjectProxyVtbl = 
{
    &IWsbCreateLocalObject_ProxyInfo,
    &IID_IWsbCreateLocalObject,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWsbCreateLocalObject::CreateInstance */
};

const CInterfaceStubVtbl _IWsbCreateLocalObjectStubVtbl =
{
    &IID_IWsbCreateLocalObject,
    &IWsbCreateLocalObject_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWsbTrace, ver. 0.0,
   GUID={0x0AF2DA10,0x7DD7,0x11d0,{0x9E,0x33,0x00,0xA0,0xC9,0x16,0xF1,0x20}} */

#pragma code_seg(".orpc")
static const unsigned short IWsbTrace_FormatStringOffsetTable[] =
    {
    3402,
    3434,
    4334,
    4372,
    4410,
    4448,
    4492,
    4530,
    4580,
    4630,
    4686,
    1054,
    4742,
    4780,
    4818,
    4856,
    4894,
    4932,
    4252,
    4970,
    5008,
    5064
    };

static const MIDL_STUBLESS_PROXY_INFO IWsbTrace_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IWsbTrace_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWsbTrace_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IWsbTrace_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(25) _IWsbTraceProxyVtbl = 
{
    &IWsbTrace_ProxyInfo,
    &IID_IWsbTrace,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWsbTrace::StartTrace */ ,
    (void *) (INT_PTR) -1 /* IWsbTrace::StopTrace */ ,
    (void *) (INT_PTR) -1 /* IWsbTrace::SetTraceOn */ ,
    (void *) (INT_PTR) -1 /* IWsbTrace::SetTraceOff */ ,
    (void *) (INT_PTR) -1 /* IWsbTrace::GetTraceSettings */ ,
    (void *) (INT_PTR) -1 /* IWsbTrace::GetTraceSetting */ ,
    (void *) (INT_PTR) -1 /* IWsbTrace::DirectOutput */ ,
    (void *) (INT_PTR) -1 /* IWsbTrace::SetOutputFormat */ ,
    (void *) (INT_PTR) -1 /* IWsbTrace::GetOutputFormat */ ,
    (void *) (INT_PTR) -1 /* IWsbTrace::SetTraceFileControls */ ,
    (void *) (INT_PTR) -1 /* IWsbTrace::GetTraceFileControls */ ,
    (void *) (INT_PTR) -1 /* IWsbTrace::SetTraceEntryExit */ ,
    (void *) (INT_PTR) -1 /* IWsbTrace::GetTraceEntryExit */ ,
    (void *) (INT_PTR) -1 /* IWsbTrace::SetLogLevel */ ,
    (void *) (INT_PTR) -1 /* IWsbTrace::GetLogLevel */ ,
    (void *) (INT_PTR) -1 /* IWsbTrace::Print */ ,
    (void *) (INT_PTR) -1 /* IWsbTrace::GetRegistryEntry */ ,
    (void *) (INT_PTR) -1 /* IWsbTrace::SetRegistryEntry */ ,
    (void *) (INT_PTR) -1 /* IWsbTrace::LoadFromRegistry */ ,
    (void *) (INT_PTR) -1 /* IWsbTrace::SetTraceSettings */ ,
    (void *) (INT_PTR) -1 /* IWsbTrace::GetLogSnapShot */ ,
    (void *) (INT_PTR) -1 /* IWsbTrace::SetLogSnapShot */
};

const CInterfaceStubVtbl _IWsbTraceStubVtbl =
{
    &IID_IWsbTrace,
    &IWsbTrace_ServerInfo,
    25,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IWsbDbSysPriv, ver. 0.0,
   GUID={0x8A2612A9,0x2466,0x470E,{0xAD,0x46,0x05,0x93,0x18,0xCE,0x8C,0x4E}} */


/* Object interface: IWsbDbPriv, ver. 0.0,
   GUID={0x5FD6B1D1,0x6A43,0x11D0,{0x99,0x05,0x00,0xA0,0xC9,0x05,0x8B,0xF6}} */


/* Object interface: IWsbDbSessionPriv, ver. 0.0,
   GUID={0xC8DA1798,0xA48C,0x458C,{0xB5,0x97,0xF4,0x97,0xAB,0x04,0x6A,0x38}} */


/* Object interface: IWsbDbKeyPriv, ver. 0.0,
   GUID={0x5FD6B1D4,0x6A43,0x11D0,{0x99,0x05,0x00,0xA0,0xC9,0x05,0x8B,0xF6}} */


/* Object interface: IWsbDbEntityPriv, ver. 0.0,
   GUID={0xF16476FD,0xBF20,0x442A,{0x84,0xEB,0x5C,0xEA,0x94,0x62,0xE8,0x1D}} */


/* Object interface: IWsbServer, ver. 0.0,
   GUID={0x58A4F966,0x55BE,0x4D62,{0x89,0x2E,0x43,0xA9,0x97,0x8B,0xF4,0xC2}} */

#pragma code_seg(".orpc")
static const unsigned short IWsbServer_FormatStringOffsetTable[] =
    {
    5120,
    5164,
    5202,
    5246,
    5284,
    5328,
    3662,
    4010,
    5366,
    4042,
    436,
    5404,
    5442,
    5480
    };

static const MIDL_STUBLESS_PROXY_INFO IWsbServer_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IWsbServer_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IWsbServer_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IWsbServer_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(17) _IWsbServerProxyVtbl = 
{
    &IWsbServer_ProxyInfo,
    &IID_IWsbServer,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IWsbServer::GetDbPathAndName */ ,
    (void *) (INT_PTR) -1 /* IWsbServer::GetId */ ,
    (void *) (INT_PTR) -1 /* IWsbServer::GetRegistryName */ ,
    (void *) (INT_PTR) -1 /* IWsbServer::GetBuildVersion */ ,
    (void *) (INT_PTR) -1 /* IWsbServer::GetNtProductVersion */ ,
    (void *) (INT_PTR) -1 /* IWsbServer::GetNtProductBuild */ ,
    (void *) (INT_PTR) -1 /* IWsbServer::GetDatabaseVersion */ ,
    (void *) (INT_PTR) -1 /* IWsbServer::SaveAll */ ,
    (void *) (INT_PTR) -1 /* IWsbServer::SetId */ ,
    (void *) (INT_PTR) -1 /* IWsbServer::DestroyObject */ ,
    (void *) (INT_PTR) -1 /* IWsbServer::Unload */ ,
    (void *) (INT_PTR) -1 /* IWsbServer::CheckAccess */ ,
    (void *) (INT_PTR) -1 /* IWsbServer::GetTrace */ ,
    (void *) (INT_PTR) -1 /* IWsbServer::SetTrace */
};

const CInterfaceStubVtbl _IWsbServerStubVtbl =
{
    &IID_IWsbServer,
    &IWsbServer_ServerInfo,
    17,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmSystemState, ver. 0.0,
   GUID={0x3F0DA041,0x69F1,0x11d2,{0xAF,0x82,0x00,0x10,0x4B,0x9A,0x37,0x58}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmSystemState_FormatStringOffsetTable[] =
    {
    5518
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmSystemState_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmSystemState_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmSystemState_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmSystemState_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IHsmSystemStateProxyVtbl = 
{
    &IHsmSystemState_ProxyInfo,
    &IID_IHsmSystemState,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmSystemState::ChangeSysState */
};

const CInterfaceStubVtbl _IHsmSystemStateStubVtbl =
{
    &IID_IHsmSystemState,
    &IHsmSystemState_ServerInfo,
    4,
    0, /* pure interpreted */
    CStdStubBuffer_METHODS
};


/* Object interface: IHsmEvent, ver. 0.0,
   GUID={0x621EFF31,0xB2E2,0x11d1,{0xB9,0xA6,0x00,0xA0,0xC9,0x19,0x04,0x47}} */

#pragma code_seg(".orpc")
static const unsigned short IHsmEvent_FormatStringOffsetTable[] =
    {
    3402
    };

static const MIDL_STUBLESS_PROXY_INFO IHsmEvent_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IHsmEvent_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };


static const MIDL_SERVER_INFO IHsmEvent_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IHsmEvent_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0};
CINTERFACE_PROXY_VTABLE(4) _IHsmEventProxyVtbl = 
{
    &IHsmEvent_ProxyInfo,
    &IID_IHsmEvent,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    (void *) (INT_PTR) -1 /* IHsmEvent::OnStateChange */
};

const CInterfaceStubVtbl _IHsmEventStubVtbl =
{
    &IID_IHsmEvent,
    &IHsmEvent_ServerInfo,
    4,
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
    ExprEvalRoutines,
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

const CInterfaceProxyVtbl * _wsbint_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IWsbIndexedCollectionProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWsbCollectableProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWsbCollectionProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWsbTraceProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWsbEnumProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWsbTestableProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWsbDbSessionProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWsbPersistableProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWsbStringProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmEventProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWsbGuidProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IHsmSystemStateProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWsbDbProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWsbEnumExProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWsbServerProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWsbDbSysProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWsbDbEntityProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWsbPersistStreamProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWsbCreateLocalObjectProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IWsbDbKeyProxyVtbl,
    0
};

const CInterfaceStubVtbl * _wsbint_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IWsbIndexedCollectionStubVtbl,
    ( CInterfaceStubVtbl *) &_IWsbCollectableStubVtbl,
    ( CInterfaceStubVtbl *) &_IWsbCollectionStubVtbl,
    ( CInterfaceStubVtbl *) &_IWsbTraceStubVtbl,
    ( CInterfaceStubVtbl *) &_IWsbEnumStubVtbl,
    ( CInterfaceStubVtbl *) &_IWsbTestableStubVtbl,
    ( CInterfaceStubVtbl *) &_IWsbDbSessionStubVtbl,
    ( CInterfaceStubVtbl *) &_IWsbPersistableStubVtbl,
    ( CInterfaceStubVtbl *) &_IWsbStringStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmEventStubVtbl,
    ( CInterfaceStubVtbl *) &_IWsbGuidStubVtbl,
    ( CInterfaceStubVtbl *) &_IHsmSystemStateStubVtbl,
    ( CInterfaceStubVtbl *) &_IWsbDbStubVtbl,
    ( CInterfaceStubVtbl *) &_IWsbEnumExStubVtbl,
    ( CInterfaceStubVtbl *) &_IWsbServerStubVtbl,
    ( CInterfaceStubVtbl *) &_IWsbDbSysStubVtbl,
    ( CInterfaceStubVtbl *) &_IWsbDbEntityStubVtbl,
    ( CInterfaceStubVtbl *) &_IWsbPersistStreamStubVtbl,
    ( CInterfaceStubVtbl *) &_IWsbCreateLocalObjectStubVtbl,
    ( CInterfaceStubVtbl *) &_IWsbDbKeyStubVtbl,
    0
};

PCInterfaceName const _wsbint_InterfaceNamesList[] = 
{
    "IWsbIndexedCollection",
    "IWsbCollectable",
    "IWsbCollection",
    "IWsbTrace",
    "IWsbEnum",
    "IWsbTestable",
    "IWsbDbSession",
    "IWsbPersistable",
    "IWsbString",
    "IHsmEvent",
    "IWsbGuid",
    "IHsmSystemState",
    "IWsbDb",
    "IWsbEnumEx",
    "IWsbServer",
    "IWsbDbSys",
    "IWsbDbEntity",
    "IWsbPersistStream",
    "IWsbCreateLocalObject",
    "IWsbDbKey",
    0
};


#define _wsbint_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _wsbint, pIID, n)

int __stdcall _wsbint_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _wsbint, 20, 16 )
    IID_BS_LOOKUP_NEXT_TEST( _wsbint, 8 )
    IID_BS_LOOKUP_NEXT_TEST( _wsbint, 4 )
    IID_BS_LOOKUP_NEXT_TEST( _wsbint, 2 )
    IID_BS_LOOKUP_NEXT_TEST( _wsbint, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _wsbint, 20, *pIndex )
    
}

const ExtendedProxyFileInfo wsbint_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _wsbint_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _wsbint_StubVtblList,
    (const PCInterfaceName * ) & _wsbint_InterfaceNamesList,
    0, // no delegation
    & _wsbint_IID_Lookup, 
    20,
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

